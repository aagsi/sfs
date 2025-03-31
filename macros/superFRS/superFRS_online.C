/**
 * @file superFRS_online.C
 * @brief Macro to set up and run the online analysis for the superFRS experiment.
 *
 * This macro configures the data source, initializes detector readers, calibration tasks,
 * online spectra, correlations, and finally executes the run.
 *
 * @author 
 * @date 2025-03-17
 */



#include "TInterpreter.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TFolder.h"
#include "TStopwatch.h"

#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

// Include subsystem readers and tasks
#include "TFRSParameter.h"
//#include "bPlastReader.h"
//#include "GermaniumReader.h"
#include "FrsReader.h"
//#include "bPlastRaw2Cal.h"
//#include "GermaniumRaw2Cal.h"
#include "FrsRaw2Cal.h"
#include "FrsCal2Hit.h"
//#include "bPlastOnlineSpectra.h"
//#include "GermaniumOnlineSpectra.h"
#include "FrsOnlineSpectra.h"
#include "FrsRawSpectra.h"
#include "FrsCalSpectra.h"
//#include "/u/profi/aali/sfsRoot/sfsRoot/analysis/online/wr/WhiterabbitCorrelationOnline.h"
//#include "/u/profi/aali/sfsRoot/sfsRoot/analysis/correlations/FrsGermaniumCorrelations.h"
#include "FrsGate.h"
#include "UcesbSource.h"
#include "UnpackReader.h"
#include "ext_h101_unpack.h"
#include "ext_h101_frs.h"
//#include "ext_h101_bplast.h"
//#include "ext_h101_germanium.h"
#include "FairRootFileSink.h"
#include "FairRunOnline.h"
#include <fairlogger/Logger.h>
#include <TMCtls.h>
#include "EventHeader.h"
#include "TFrsConfiguration.h"
#include "TCorrelationsConfiguration.h"
//#include "TbPlastConfiguration.h"
//#include "TGermaniumConfiguration.h"

// Enable or disable subsystems (set to true to enable the subsystem)
const bool kAidaEnabled         = false;
const bool kBPlastEnabled       = false;
const bool kGermaniumEnabled    = false;
const bool kFrsEnabled          = true;
const bool kTimeMachineEnabled  = false;
const bool kWhiteRabbitEnabled  = false;

// Include FRS setup (ideally, this should be wrapped in a function call)
#include "../../config/s115/frs/setup_115_023_2025_s1calib_conv.C"

/**
 * @struct EXT_STR_h101_t
 * @brief Structure to hold the h101 event data for various subsystems.
 */
typedef struct EXT_STR_h101_t {
    EXT_STR_h101_unpack_t         eventheaders;   ///< Event header unpacked data.
    // EXT_STR_h101_aida_onion_t   aida;           ///< Aida data (disabled for this configuration).
    //EXT_STR_h101_bplast_onion_t   bplast;         ///< bPlast subsystem data.
    //EXT_STR_h101_germanium_onion_t germanium;     ///< Germanium subsystem data.
    EXT_STR_h101_frs_onion_t      frs;            ///< FRS subsystem data.
} EXT_STR_h101;

namespace superFRSOnline {

/**
 * @brief Experiment configuration parameters.
 */
struct Config {
    Int_t nev;                   ///< Maximum number of events to process (-1 for all).
    Int_t runId;                 ///< Run ID for the analysis.
    TString expName;             ///< Experiment name.
    TString sfsRootPath;          ///< Base path for the sfsRoot framework.
    TString filename;            ///< Input file name.
    TString outputFileName;      ///< Output file name.
    std::string configPath;      ///< Path to configuration files.
    TString ucesbPath;           ///< Path for the UcesbSource options.
};

/**
 * @brief Initializes the experiment configuration.
 *
 * @param[out] config Reference to the Config structure to initialize.
 */
void InitializeConfig(Config &config) {
    config.nev = 10000;//-1;
    config.runId = 1;
    config.expName = "s115";
    //config.sfsRootPath = "/u/despec/s115_online/c4Root";
    config.sfsRootPath = "/u/profi/aali/sfsRoot/sfsRoot";
    config.filename = "../../../tmp/ioFiles/68Br_setting23_6gBe_0085_0073_stitched.lmd";
    config.outputFileName = "output.root";
    config.configPath = std::string(config.sfsRootPath.Data()) + "/config/" + std::string(config.expName.Data());
    config.ucesbPath = config.sfsRootPath + "/unpack/exps/" + config.expName + "/" +
                       config.expName + " --debug --input-buffer=200Mi --event-sizes --allow-errors";
    config.ucesbPath.ReplaceAll("//", "/");
}

/**
 * @brief Sets up correlations between FRS and Germanium detectors.
 *
 * @param[in,out] run Pointer to the FairRunOnline object.
 * @param[in] configPath Configuration file path.
 */
void SetupCorrelations(FairRunOnline* run, const std::string &configPath) {
    if (kFrsEnabled && kGermaniumEnabled) {
        FrsGate* Br71 = new FrsGate("71Br", configPath + "/frs/71Br_Mar3.root");
        FrsGate* Se69 = new FrsGate("69Se", configPath + "/frs/69Se_Mar2.root");
        FrsGate* Se70 = new FrsGate("70Se", configPath + "/frs/70Se_Mar3.root");
/*
        FrsGermaniumCorrelations* ge71Br = new FrsGermaniumCorrelations(Br71);
        ge71Br->SetShortLifetimeCollectionWindow(3000);
        run->AddTask(ge71Br);

        FrsGermaniumCorrelations* ge70Se = new FrsGermaniumCorrelations(Se70);
        ge70Se->SetShortLifetimeCollectionWindow(3000);
        run->AddTask(ge70Se);

        FrsGermaniumCorrelations* ge69Se = new FrsGermaniumCorrelations(Se69);
        ge69Se->SetShortLifetimeCollectionWindow(3000);
        run->AddTask(ge69Se);
*/
    }
}

/**
 * @brief Configures detector-specific settings.
 *
 * @param[in] configPath Configuration file path.
 */
void SetupDetectorConfiguration(const std::string &configPath) {
    //TbPlastConfiguration::SetDetectorMapFile(configPath + "/bplast/bplast_mapping_220125.txt");
    TFrsConfiguration::SetConfigPath(configPath + "/frs/");
    TFrsConfiguration::SetCrateMapFile(configPath + "/frs/crate_map.txt");
    //TGermaniumConfiguration::SetDetectorConfigurationFile(configPath + "/germanium/ge_alloc_jan22.txt");
    //TGermaniumConfiguration::SetDetectorCoefficientFile(configPath + "/germanium/ge_cal_feb21_2025_new_cards.txt");
    //TGermaniumConfiguration::SetDetectorTimeshiftsFile(configPath + "/germanium/ge_timeshifts_2202.txt");
    //TGermaniumConfiguration::SetPromptFlashCut(configPath + "/germanium/promptflash_new.root");
}

/**
 * @brief Sets up calibration and online tasks.
 *
 * @param[in,out] run Pointer to the FairRunOnline object.
 */
void SetupCalibrationTasks(FairRunOnline* run) {
    // bPlast calibration task.
    /*if (kBPlastEnabled) {
        bPlastRaw2Cal* calBplast = new bPlastRaw2Cal();
        calBplast->SetOnline(true);
        run->AddTask(calBplast);
    }*/
    // Germanium calibration task.
    /*if (kGermaniumEnabled) {
        GermaniumRaw2Cal* calGermanium = new GermaniumRaw2Cal();
        calGermanium->SetOnline(true);
        run->AddTask(calGermanium);
    }*/
    // FRS calibration and hit reconstruction tasks.
    if (kFrsEnabled) {
        FrsRaw2Cal* calFrs = new FrsRaw2Cal();
        calFrs->SetOnline(true);
        run->AddTask(calFrs);

        FrsCal2Hit* hitFrs = new FrsCal2Hit();
        hitFrs->SetOnline(true);
        run->AddTask(hitFrs);

        // Online spectra tasks for FRS.
        std::vector<FrsGate*> nogates;  // Empty vector; populate if necessary.
        FrsOnlineSpectra* onlineFrs = new FrsOnlineSpectra(nogates);
        run->AddTask(onlineFrs); // ok
        run->AddTask(new FrsRawSpectra()); // ok
        run->AddTask(new FrsCalSpectra()); // ok
    }
}

} // namespace superFRSOnline

/**
 * @brief Initializes the data source for the online analysis.
 *
 * This function creates and configures a UcesbSource object using the provided file name,
 * data source path, and event structure.
 *
 * @param[in,out] source Reference to the pointer that will hold the UcesbSource object.
 * @param[in] ucesb_struct Reference to the h101 event data structure.
 * @param[in] filename Name of the input file.
 * @param[in] ucesb_path Data source path with additional options.
 * @param[in] nev Maximum number of events to process (-1 means process all events).
 */
void SetupSource(UcesbSource*& source, EXT_STR_h101 &ucesb_struct, 
                 const TString &filename, const TString &ucesb_path, Int_t nev) {
    TString ntuple_options = "UNPACK,RAW"; ///< Options for unpacking and raw data.
    source = new UcesbSource(filename, ntuple_options, ucesb_path, 
                             &ucesb_struct, sizeof(ucesb_struct));
    source->SetMaxEvents(nev);
}

/**
 * @brief Adds detector readers to the data source based on enabled subsystems.
 *
 * This function registers the appropriate detector readers (e.g., bPlast, Germanium, FRS)
 * with the provided data source.
 *
 * @param[in] source Pointer to the UcesbSource object.
 * @param[in] ucesb_struct Reference to the h101 event data structure.
 * @param[in] config_path Path to the configuration files.
 */
void SetupDetectors(UcesbSource* source, EXT_STR_h101 &ucesb_struct, 
                    const TString &config_path) {
    // Always add the unpack reader for the event header.
    UnpackReader* unpackHeader = new UnpackReader(
        (EXT_STR_h101_unpack*)&ucesb_struct.eventheaders, 
        offsetof(EXT_STR_h101, eventheaders));
    source->AddReader(unpackHeader);

    // bPlast detector reader.
    /*if (kBPlastEnabled) {
        bPlastReader* reader = new bPlastReader(
            (EXT_STR_h101_bplast_onion*)&ucesb_struct.bplast, 
            offsetof(EXT_STR_h101, bplast));
        reader->SetInputFileFineTimeHistos(config_path + "/bplast/fine_time_G302_21FEB.root");
        reader->SetOnline(true);
        source->AddReader(reader);
    }*/
    
    // Germanium detector reader.
    /*if (kGermaniumEnabled) {
        GermaniumReader* reader = new GermaniumReader(
            (EXT_STR_h101_germanium_onion*)&ucesb_struct.germanium, 
            offsetof(EXT_STR_h101, germanium));
        reader->SetOnline(true);
        source->AddReader(reader);
    }*/
    
    // FRS detector reader.
    if (kFrsEnabled) {
        FrsReader* reader = new FrsReader(
            (EXT_STR_h101_frs_onion*)&ucesb_struct.frs, 
            offsetof(EXT_STR_h101, frs));
        reader->SetOnline(true);
        source->AddReader(reader);
    }
}

/**
 * @brief Main function that configures and runs the online analysis.
 *
 * This function sets up the experiment configuration, initializes the data source,
 * detector readers, calibration tasks, online spectra, and correlation tasks. Finally,
 * it starts the run and reports performance statistics.
 */
void superFRS_online() {
    std::cout << "Running superFRS_online macro..." << std::endl;
    
    // Initialize experiment configuration.
    superFRSOnline::Config config;
    superFRSOnline::InitializeConfig(config);

    // ----- Timing and Logger Configuration -----
    TStopwatch timer;
    timer.Start();
    
    FairLogger::GetLogger()->SetLogScreenLevel("INFO");
    FairLogger::GetLogger()->SetColoredLog(true);
    
    // ----- Setup the Online Run -----
    FairRunOnline* run = new FairRunOnline();
    EventHeader* evtHeader = new EventHeader();
    run->SetEventHeader(evtHeader);
    run->SetRunId(config.runId);
    run->SetSink(new FairRootFileSink(config.outputFileName));
    run->ActivateHttpServer(1, 5000);
    

    // Create and register a folder for histograms.
    TFolder* histograms = new TFolder("Histograms", "Histograms");
    FairRootManager::Instance()->Register("Histograms", "Histogram Folder", histograms, false);
    run->AddObject(histograms);
    
    // ----- Data Source Setup -----
    EXT_STR_h101 ucesb_struct;  ///< Structure to hold incoming event data.
    UcesbSource* source = nullptr;
    SetupSource(source, ucesb_struct, config.filename, config.ucesbPath, config.nev);
    run->SetSource(source);
    
    // ----- FRS Parameter Initialization -----
    TFRSParameter* frs = new TFRSParameter();
    TMWParameter* mw = new TMWParameter();
    TTPCParameter* tpc = new TTPCParameter();
    TMUSICParameter* music = new TMUSICParameter();
    TLABRParameter* labr = new TLABRParameter();
    TSCIParameter* sci = new TSCIParameter();
    TIDParameter* id = new TIDParameter();
    TSIParameter* si = new TSIParameter();
    TMRTOFMSParameter* mrtof = new TMRTOFMSParameter();
    TRangeParameter* range = new TRangeParameter();
    
    // Call external FRS setup function.
    setup(frs, mw, tpc, music, labr, sci, id, si, mrtof, range);
    TFrsConfiguration::SetParameters(frs, mw, tpc, music, labr, sci, id, si, mrtof, range);
    
    TCorrelationsConfiguration::SetCorrelationsFile(config.configPath + "/correlations.dat");
    
    // ----- Detector Configuration -----
    superFRSOnline::SetupDetectorConfiguration(config.configPath);
    
    // ----- Setup Detector Readers -----
    SetupDetectors(source, ucesb_struct, config.configPath.c_str());
    
    // ----- Setup Calibration and Online Tasks -----
    superFRSOnline::SetupCalibrationTasks(run);
    
    // ----- Setup Correlations (FRS & Germanium) -----
    superFRSOnline::SetupCorrelations(run, config.configPath);
    
    // ----- Initialize and Run the Analysis -----
    run->Init();
    FairLogger::GetLogger()->SetLogScreenLevel("info");
    
    std::cout << "\nData stream: " << config.filename << std::endl;
    std::cout << "Online port server: 5000" << std::endl;
    
    run->Run((config.nev < 0) ? config.nev : 0, (config.nev < 0) ? 0 : config.nev);
    
    // ----- Performance Reporting -----
    timer.Stop();
    Double_t rtime = timer.RealTime();
    Double_t ctime = timer.CpuTime();
    Float_t cpuUsage = ctime / rtime;
    
    std::cout << "CPU usage: " << cpuUsage << std::endl;
    std::cout << "Macro finished successfully." << std::endl;
    std::cout << "Real time: " << rtime << " s, CPU time: " << ctime << " s" << std::endl;
}
