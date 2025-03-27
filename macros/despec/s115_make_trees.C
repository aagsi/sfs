/**
 * @file s115_make_trees.C
 * @brief Macro to set up and run the tree-making process for the s115 experiment.
 *
 * This macro configures the data source, initializes detector readers, FRS parameters,
 * calibration tasks, and then executes the run.
 *
 * @date 2025-03-17
 */

#include <TROOT.h>
#include <TInterpreter.h>
#include <TSystem.h>
#include <TFolder.h>
#include <TStopwatch.h>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

// -----------------------------------------------------------------------------
// Include Experiment-Specific Headers
// (Ensure that your include paths (-I flags) are set so that these files are found)
// -----------------------------------------------------------------------------
#include "TFRSParameter.h"
//#include "TMWParameter.h"       // Make sure this header is available in your include path
//#include "TTPCParameter.h"
//#include "TMUSICParameter.h"
//#include "TLABRParameter.h"
//#include "TSCIParameter.h"
//#include "TIDParameter.h"
//#include "TSIParameter.h"
//#include "TMRTOFMSParameter.h"
//#include "TRangeParameter.h"
#include "bPlastReader.h"
#include "GermaniumReader.h"
#include "FrsReader.h"
#include "AidaReader.h"
#include "bPlastRaw2Cal.h"
#include "GermaniumRaw2Cal.h"
#include "FrsRaw2Cal.h"
#include "AidaUnpack2Cal.h"
#include "AidaCal2Hit.h"        // Added header for AidaCal2Hit
#include "FrsCal2Hit.h"
#include "UcesbSource.h"
#include "UnpackReader.h"
#include "ext_h101_unpack.h"
#include "ext_h101_aida.h"
#include "ext_h101_bplast.h"
#include "ext_h101_germanium.h"
#include "ext_h101_frs.h"
#include "FairRootFileSink.h"
#include "FairRunOnline.h"
#include <fairlogger/Logger.h>
#include "TFrsConfiguration.h"
#include "TCorrelationsConfiguration.h"
#include "TAidaConfiguration.h"
#include "TbPlastConfiguration.h"
#include "TGermaniumConfiguration.h"
#include "EventHeader.h"

// -----------------------------------------------------------------------------
// Subsystem Configuration Flags (using const bool for type safety)
// -----------------------------------------------------------------------------
const bool kAidaEnabled        = true;
const bool kBPlastEnabled      = true;
const bool kGermaniumEnabled   = true;
const bool kFrsEnabled         = true;
const bool kTimeMachineEnabled = false;
const bool kWhiteRabbitEnabled = false;

// -----------------------------------------------------------------------------
// Include FRS Setup File (without extern "C" so that proper C++ linkage is used)
// -----------------------------------------------------------------------------
#include "../../config/s115/frs/setup_115_022_2025_s1calib_conv.C"

// -----------------------------------------------------------------------------
// Data Structure for h101 Event Data
// Protect duplicate definition using an include guard
// -----------------------------------------------------------------------------
#ifndef EXT_STR_H101_DEFINED
typedef struct EXT_STR_h101_t {
    EXT_STR_h101_unpack_t         eventheaders;
    EXT_STR_h101_aida_onion_t     aida;
    EXT_STR_h101_bplast_onion_t   bplast;
    EXT_STR_h101_germanium_onion_t germanium;
    EXT_STR_h101_frs_onion_t      frs;
} EXT_STR_h101;
#define EXT_STR_H101_DEFINED
#endif

// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------
/**
 * @brief Configures the FairRunOnline run and UcesbSource for data acquisition.
 */
void SetupDataSource(FairRunOnline*& run, UcesbSource*& source, EXT_STR_h101& ucesb_struct,
                     const TString& filename, const TString& ucesb_path, Int_t nev,
                     const TString& outputFileName);

/**
 * @brief Initializes FRS parameter objects using the external setup function.
 */
void InitializeFRSParameters();

/**
 * @brief Loads detector configuration files.
 */
void SetupDetectorConfigurations(const std::string& config_path);

/**
 * @brief Registers detector readers with the UcesbSource.
 */
void SetupDetectorReaders(UcesbSource* source, EXT_STR_h101& ucesb_struct,
                          const std::string& config_path);

/**
 * @brief Adds calibration tasks to the run based on enabled subsystems.
 */
void SetupCalibrationTasks(FairRunOnline* run);

/**
 * @brief Adds analysis tasks to the run based on enabled subsystems.
 */
void SetupAnalysisTasks(FairRunOnline* run);

/**
 * @brief Prints timing and performance information after the run.
 */
void PrintRunInformation(const TString& filename, TStopwatch& timer);

/**
 * @brief Main function to set up and run the s115 tree-making process.
 */
void s115_make_trees();

// -----------------------------------------------------------------------------
// Main Function Implementation
// -----------------------------------------------------------------------------
void s115_make_trees() {
    // Experiment and Run Configuration
    const Int_t nev    = -1;  // Process all events if negative.
    const Int_t fRunId = 1;
    const Int_t fExpId = 1;
    TString fExpName   = "s115";
    
    // Define Important Paths
    TString sfsRoot_path = "/u/despec/s115_online/sfsRoot";
    TString ucesb_path = sfsRoot_path + "/unpack/exps/" + fExpName + "/" + fExpName +
                         " --debug --input-buffer=200Mi --event-sizes --allow-errors";
    ucesb_path.ReplaceAll("//", "/");
    
    std::string config_path = std::string(sfsRoot_path.Data()) + "/config/" + std::string(fExpName.Data());
    
    // Timer and Logger Setup
    TStopwatch timer;
    timer.Start();
    FairLogger::GetLogger()->SetLogScreenLevel("INFO");
    FairLogger::GetLogger()->SetColoredLog(true);
    
    // Data File and Output Configuration
    TString filename = "68Br_setting23_6gBe_0085_0073_stitched.lmd";
    TString outputpath = "test_tree";
    TString outputFileName = outputpath + ".root";
    
    // Setup Run and Data Source
    FairRunOnline* run = nullptr;
    UcesbSource* source = nullptr;
    EXT_STR_h101 ucesb_struct;
    SetupDataSource(run, source, ucesb_struct, filename, ucesb_path, nev, outputFileName);
    
    // Initialize FRS Parameters and Detector Configurations
    InitializeFRSParameters();
    TCorrelationsConfiguration::SetCorrelationsFile(config_path + "/correlations.dat");
    SetupDetectorConfigurations(config_path);
    
    // Setup Detector Readers
    SetupDetectorReaders(source, ucesb_struct, config_path);
    
    // Setup Calibration and Analysis Tasks
    SetupCalibrationTasks(run);
    SetupAnalysisTasks(run);
    
    // Initialize and Run the Analysis
    run->Init();
    FairLogger::GetLogger()->SetLogScreenLevel("info");
    std::cout << "\nData stream is: " << filename << "\n" << std::endl;
    run->Run((nev < 0) ? nev : 0, (nev < 0) ? 0 : nev);
    
    // Finish: Print Timing and Performance Information
    timer.Stop();
    PrintRunInformation(filename, timer);
}

// -----------------------------------------------------------------------------
// Function Definitions
// -----------------------------------------------------------------------------
void SetupDataSource(FairRunOnline*& run, UcesbSource*& source, EXT_STR_h101& ucesb_struct,
                     const TString& filename, const TString& ucesb_path, Int_t nev,
                     const TString& outputFileName) {
    run = new FairRunOnline();
    EventHeader* evtHeader = new EventHeader();
    run->SetEventHeader(evtHeader);
    run->SetRunId(1);
    run->SetSink(new FairRootFileSink(outputFileName));
    
    TString ntuple_options = "UNPACK,RAW"; // Options for unpacking data.
    source = new UcesbSource(filename, ntuple_options, ucesb_path, &ucesb_struct, sizeof(ucesb_struct));
    source->SetMaxEvents(nev);
    run->SetSource(source);
}

void InitializeFRSParameters() {
    // Create FRS parameter objects.
    TFRSParameter* frs = new TFRSParameter();
    // The following parameters should be declared/defined in your project.
    TMWParameter* mw = new TMWParameter();
    TTPCParameter* tpc = new TTPCParameter();
    TMUSICParameter* music = new TMUSICParameter();
    TLABRParameter* labr = new TLABRParameter();
    TSCIParameter* sci = new TSCIParameter();
    TIDParameter* id = new TIDParameter();
    TSIParameter* si = new TSIParameter();
    TMRTOFMSParameter* mrtof = new TMRTOFMSParameter();
    TRangeParameter* range = new TRangeParameter();
    
    setup(frs, mw, tpc, music, labr, sci, id, si, mrtof, range);
    TFrsConfiguration::SetParameters(frs, mw, tpc, music, labr, sci, id, si, mrtof, range);
}

void SetupDetectorConfigurations(const std::string& config_path) {
    TAidaConfiguration::SetBasePath(config_path + "/AIDA");
    TbPlastConfiguration::SetDetectorMapFile(config_path + "/bplast/bplast_mapping_220125.txt");
    TFrsConfiguration::SetConfigPath(config_path + "/frs/");
    TFrsConfiguration::SetCrateMapFile(config_path + "/frs/crate_map.txt");
    
    TGermaniumConfiguration::SetDetectorConfigurationFile(config_path + "/germanium/ge_alloc_jan22.txt");
    TGermaniumConfiguration::SetDetectorCoefficientFile(config_path + "/germanium/ge_cal_feb21_2025_new_cards.txt");
    TGermaniumConfiguration::SetDetectorTimeshiftsFile(config_path + "/germanium/ge_timeshifts_2202.txt");
    TGermaniumConfiguration::SetPromptFlashCut(config_path + "/germanium/promptflash_new.root");
}

void SetupDetectorReaders(UcesbSource* source, EXT_STR_h101& ucesb_struct,
                          const std::string& config_path) {
    UnpackReader* unpackHeader = new UnpackReader((EXT_STR_h101_unpack*)&ucesb_struct.eventheaders,
                                                  offsetof(EXT_STR_h101, eventheaders));
    source->AddReader(unpackHeader);
    
    if (kAidaEnabled) {
        AidaReader* aidaReader = new AidaReader((EXT_STR_h101_aida_onion*)&ucesb_struct.aida,
                                                offsetof(EXT_STR_h101, aida));
        aidaReader->SetOnline(false);
        source->AddReader(aidaReader);
    }
    
    if (kBPlastEnabled) {
        bPlastReader* bplastReader = new bPlastReader((EXT_STR_h101_bplast_onion*)&ucesb_struct.bplast,
                                                      offsetof(EXT_STR_h101, bplast));
        bplastReader->SetInputFileFineTimeHistos(config_path + "/bplast/fine_time_G302_21FEB.root");
        bplastReader->SetOnline(true);
        source->AddReader(bplastReader);
    }
    
    if (kGermaniumEnabled) {
        GermaniumReader* germaniumReader = new GermaniumReader((EXT_STR_h101_germanium_onion*)&ucesb_struct.germanium,
                                                               offsetof(EXT_STR_h101, germanium));
        germaniumReader->SetOnline(true);
        source->AddReader(germaniumReader);
    }
    
    if (kFrsEnabled) {
        FrsReader* frsReader = new FrsReader((EXT_STR_h101_frs_onion*)&ucesb_struct.frs,
                                             offsetof(EXT_STR_h101, frs));
        frsReader->SetOnline(true);
        source->AddReader(frsReader);
    }
}

void SetupCalibrationTasks(FairRunOnline* run) {
    if (kAidaEnabled) {
        AidaUnpack2Cal* aidaCal = new AidaUnpack2Cal();
        aidaCal->SetOnline(false);
        run->AddTask(aidaCal);
    }
    
    if (kBPlastEnabled) {
        bPlastRaw2Cal* bplastCal = new bPlastRaw2Cal();
        bplastCal->SetOnline(false);
        run->AddTask(bplastCal);
    }
    
    if (kGermaniumEnabled) {
        GermaniumRaw2Cal* germaniumCal = new GermaniumRaw2Cal();
        germaniumCal->SetOnline(false);
        run->AddTask(germaniumCal);
    }
    
    if (kFrsEnabled) {
        FrsRaw2Cal* frsCal = new FrsRaw2Cal();
        frsCal->SetOnline(true);
        run->AddTask(frsCal);
    }
}

void SetupAnalysisTasks(FairRunOnline* run) {
    if (kAidaEnabled) {
        AidaCal2Hit* aidaHit = new AidaCal2Hit();
        aidaHit->SetOnline(false);
        run->AddTask(aidaHit);
    }
    
    if (kFrsEnabled) {
        FrsCal2Hit* frsHit = new FrsCal2Hit();
        frsHit->SetOnline(false);
        run->AddTask(frsHit);
    }
}

void PrintRunInformation(const TString& filename, TStopwatch& timer) {
    Double_t rtime = timer.RealTime();
    Double_t ctime = timer.CpuTime();
    Float_t cpuUsage = ctime / rtime;
    
    std::cout << "CPU used: " << cpuUsage << std::endl;
    std::cout << "Macro finished successfully." << std::endl;
    std::cout << "Real time: " << rtime << " s, CPU time: " << ctime << " s" << std::endl;
}
