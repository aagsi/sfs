



#include <TROOT.h>

// Struct should containt all subsystem h101 structures
typedef struct EXT_STR_h101_t
{   
    EXT_STR_h101_unpack_t eventheaders;
    EXT_STR_h101_bplast_onion_t bplast;
} EXT_STR_h101;


void bplast_nearline()
{   
    const Int_t nev = -1; const Int_t fRunId = 1; const Int_t fExpId = 1;

    // Name your experiment. Make sure all relevant directories are named identically.
    TString fExpName = "s100";

    // Define important paths.
    TString screenshot_path = "~/lustre/gamma/dryrunmarch24/screenshots/";
    TString sfsRoot_path = "/u/cjones/sfsRoot";
    TString ucesb_path = sfsRoot_path + "/unpack/exps/" + fExpName + "/" + fExpName + " --debug --input-buffer=200Mi --event-sizes --allow-errors --max-events=300000";
    ucesb_path.ReplaceAll("//","/");

    std::string config_path = std::string(sfsRoot_path.Data()) + "/config/" + std::string(fExpName.Data());

    // Macro timing
    TString cRunId = Form("%04d", fRunId);
    TString cExpId = Form("%03d", fExpId);
    TStopwatch timer;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d_%H%M%S");
    timer.Start();
    
    // Set level of debug information
    FairLogger::GetLogger()->SetLogScreenLevel("INFO");
    FairLogger::GetLogger()->SetColoredLog(true);

    // Define where to read data from. Online = stream/trans server, Nearline = .lmd file.
    TString filename = "bplast_trees.root";
    TString outputpath = "bplast_histograms";
    TString outputFileName = outputpath + ".root";

    FairRunAna* run = new FairRunAna();
    EventHeader* EvtHead = new EventHeader();
    run->SetEventHeader(EvtHead);
    run->SetRunId(1);
    run->SetSink(new FairRootFileSink(outputFileName));
    FairSource* fs = new FairFileSource(filename);
    ///fs->SetMaxEvents(nev);
    run->SetSource(fs);

    //run->ActivateHttpServer(refresh, port);
    //TDirectory* bplast_directory = new TDirectory("bPlastTest", "bPlastTest", "", 0);
    //FairRootManager::Instance()->Register("bPlastTest", "bPlast Directory", bplast_directory, false);

    // Create source using ucesb for input
    // this shit here is wrong or needs to be removed or whayever
    /*EXT_STR_h101 ucesb_struct;
    TString ntuple_options = "UNPACK"; // Define which level of data to unpack - we don't use "RAW" or "CAL"
    UcesbSource* source = new UcesbSource(filename, ntuple_options, ucesb_path, &ucesb_struct, sizeof(ucesb_struct));
    source->SetMaxEvents(nev);
    run->SetSource(source);*/

    TbPlastConfiguration::SetDetectorMapFile(config_path + "/bplast/bplast_alloc_mar20.txt");


     // ======================================================================================== //
    // =========== **** SPECTRA ***** ========================================================= //
    // ======================================================================================== //
    
    // ---------------------------------------------------------------------------------------- //
    // *** Nearline Spectra ********************************************************************* //

    bPlastNearlineSpectra* nearlinebplast = new bPlastNearlineSpectra();
    
    run->AddTask(nearlinebplast);


    // Initialise
    run->Init();
    
    FairLogger::GetLogger()->SetLogScreenLevel("info");

    // Information about portnumber and main data stream
    cout << "\n\n" << endl;
    cout << "Data stream is: " << filename << endl;
    cout << "\n\n" << endl;

    // Run
    //run->Run((nev < 0) ? nev : 0, (nev < 0) ? 0 : nev); 
    run->Run(0,10000000);

    // ---------------------------------------------------------------------------------------- //
    // *** Finish Macro *********************************************************************** //

    timer.Stop();
    Double_t rtime = timer.RealTime();
    Double_t ctime = timer.CpuTime();
    Float_t cpuUsage = ctime / rtime;
    cout << "CPU used: " << cpuUsage << endl;
    std::cout << std::endl << std::endl;
    std::cout << "Macro finished successfully." << std::endl;
    std::cout << "Output file is " << outputFileName << std::endl;
    std::cout << "Real time " << rtime << " s, CPU time " << ctime << " s" << std::endl << std::endl;
   // gApplication->Terminate(0);
   
   // ----------------------------------------------------------------------------------------- //
}
