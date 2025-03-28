#include <sstream>
#include <iomanip>
// FairRoot
#include "FairLogger.h"
#include "FairRootManager.h"
#include "FairRunAna.h"
#include "FairRunOnline.h"
#include "FairRuntimeDb.h"

// sfs
#include "EventHeader.h"
#include "LisaNearlineSpectra.h"
#include "sfsLogger.h"
#include "AnalysisTools.h"

#include "TCanvas.h"
#include "TFile.h"
#include "TClonesArray.h"
#include "TFolder.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"
#include "THttpServer.h"
#include "TMath.h"
#include "TRandom.h"
#include <string>
#include "TColor.h"
#include "TStyle.h"

LisaNearlineSpectra::LisaNearlineSpectra()  :   LisaNearlineSpectra("LisaNearlineSpectra")
{
    lisa_config = TLisaConfiguration::GetInstance();
}

LisaNearlineSpectra::LisaNearlineSpectra(const TString& name, Int_t verbose)
    : FairTask(name, verbose)
    // , fHitLisa(NULL)
    , fNEvents(0)
    , header(nullptr)
    // ranges
{
    lisa_config = TLisaConfiguration::GetInstance();
    exp_config = TExperimentConfiguration::GetInstance();

}

LisaNearlineSpectra::~LisaNearlineSpectra()
{
    sfsLOG(info, "");
}

void LisaNearlineSpectra::SetParContainers()
{
    FairRuntimeDb *rtdb = FairRuntimeDb::instance();
    sfsLOG_IF(fatal, NULL == rtdb, "FairRuntimeDb not found.");
}

InitStatus LisaNearlineSpectra::Init()
{
    FairRootManager* mgr = FairRootManager::Instance();
    sfsLOG_IF(fatal, NULL == mgr, "FairRootManager not found");

    header = (EventHeader*)mgr->GetObject("EventHeader.");
    sfsLOG_IF(error, !header, "Branch EventHeader. not found");

    lisaCalArray = mgr->InitObjectAs<decltype(lisaCalArray)>("LisaCalData");
    sfsLOG_IF(fatal, !lisaCalArray, "Branch LisaCalData not found!");

    FairRootManager::Instance()->GetOutFile()->cd();
    dir_lisa = gDirectory->mkdir("LISA");
    mgr->Register("LISA", "LISA Directory", dir_lisa, false); // allow other tasks to find this
   
    layer_number = lisa_config->NLayers();
    det_number = lisa_config->NDetectors();
    auto const & detector_mapping = lisa_config->Mapping();
    xmax = lisa_config->XMax();
    ymax = lisa_config->YMax();
    num_layers = lisa_config->NLayers();

    dir_lisa->cd();
    dir_stats = dir_lisa->mkdir("Stats");
    dir_energy = dir_lisa->mkdir("Energy");
    dir_traces = dir_lisa->mkdir("Traces");
    dir_drift = dir_lisa->mkdir("Drifts");
    
    // layer names: Tokyo, Eris, Sparrow
  
    //:::::::::::White Rabbit:::::::::::::::
    dir_stats->cd();
    h1_wr_diff = new TH1I("h1_wr_diff", "WR Difference", lisa_config->bin_wr_diff, lisa_config->min_wr_diff, lisa_config->max_wr_diff);
    h1_wr_diff->GetXaxis()->SetTitle("LISA WR Difference [ns]");
    h1_wr_diff->SetLineColor(kBlack);
    h1_wr_diff->SetFillColor(kRed-3);

    //:::::::::::H I T  P A T T E R N S:::::::::::::::
    //:::::::::::Total
    dir_stats->cd();
    h1_hitpattern_total = new TH1I("h1_hitpattern_total", "Hit Pattern", det_number, 0, det_number);
    for (auto & detector : detector_mapping)
    {
        int l = detector.second.first.first;
        city = detector.second.first.second;
        int x = detector.second.second.first; 
        int y = detector.second.second.second;
        
        // special case for weird layer
        if (l != 0) h1_hitpattern_total->GetXaxis()->SetBinLabel(l * xmax * ymax + (ymax-(y+1))*xmax + x + 1 - 3, city.Data());
        else h1_hitpattern_total->GetXaxis()->SetBinLabel(1, city.Data());
    }

    //:::::::::Layer
    c_hitpattern_layer = new TCanvas("c_hitpattern_layer", "Hit Pattern by Layer", 650, 350);
    c_hitpattern_layer->Divide(2, (layer_number+1)/2);
    h1_hitpattern_layer.resize(layer_number);
    for (int i = 0; i < layer_number; i++)
    {   
        c_hitpattern_layer->cd(i+1);
        h1_hitpattern_layer[i] = new TH1I(Form("h1_hitpattern_layer_%i", i), Form("Hit Pattern - Layer: %i", i), xmax * ymax, 0, xmax * ymax);
        h1_hitpattern_layer[i]->SetStats(0);
        h1_hitpattern_layer[i]->Draw();

        for (int j = 0; j < xmax * ymax; j++)
        {
            city = "";
            for (auto & detector : detector_mapping)
            {
                int x = detector.second.second.first; 
                int y = detector.second.second.second;
                if (detector.second.first.first == i && ((ymax-(y+1))*xmax + x) == j)
                {
                    city = detector.second.first.second;
                    break;
                }
            }
            h1_hitpattern_layer[i]->GetXaxis()->SetBinLabel(j+1, city.Data());
        }
       
    }
    c_hitpattern_layer->cd();
    dir_stats->Append(c_hitpattern_layer);

    //:::::::::::H I T  P A T T E R N - by grid ::::::::::::::::::
    dir_stats->cd();
    c_hitpattern_grid = new TCanvas("c_hitpattern_grid", "Hit Pattern Grid", 650, 350);
    c_hitpattern_grid->Divide(layer_number-1);
    h2_hitpattern_grid.resize(layer_number-1);
    c_hitpattern_grid->SetLogz();

    for (int i = 0; i < layer_number-1; i++)
    {   

        c_hitpattern_grid->cd(i+1);
        h2_hitpattern_grid[i] = new TH2F(Form("h2_hitpattern_grid_layer_%i", i), Form("Hit Pattern Grid - Layer %i", i+1), xmax, 0, xmax, ymax, 0, ymax);
        h2_hitpattern_grid[i]->SetStats(0);
        h2_hitpattern_grid[i]->Draw("colz");
        h2_hitpattern_grid[i]->GetXaxis()->SetTitle(Form("Hit Pattern Layer %i",i+1));
        h2_hitpattern_grid[i]->GetXaxis()->SetLabelSize(0);
        h2_hitpattern_grid[i]->GetXaxis()->SetTickLength(0);
        h2_hitpattern_grid[i]->GetYaxis()->SetLabelSize(0);
        h2_hitpattern_grid[i]->GetYaxis()->SetTickLength(0);
        h2_hitpattern_grid[i]->SetMinimum(1);
        h2_hitpattern_grid[i]->SetContour(100);
        
    }
    
    c_hitpattern_grid->cd();
    dir_stats->Append(c_hitpattern_grid);

    //:::::::::::P I L E   U P::::::::::::
    dir_stats->cd();
    c_pileup_grid = new TCanvas("c_pileup_grid", "Pileup Grid", 650, 350);
    c_pileup_grid->Divide(layer_number-1);
    h2_pileup_grid.resize(layer_number-1);
    c_hitpattern_grid->SetLogz();

    for (int i = 0; i < layer_number-1; i++)
    {   

        c_pileup_grid->cd(i+1);
        h2_pileup_grid[i] = new TH2F(Form("h2_pileup_grid_layer_%i", i), Form("Pile Up Grid - Layer %i", i+1), xmax, 0, xmax, ymax, 0, ymax);
        h2_pileup_grid[i]->SetStats(0);
        h2_pileup_grid[i]->Draw("COLZ");
        h2_pileup_grid[i]->GetXaxis()->SetTitle(Form("Pile Up Layer %i",i+1));
        h2_pileup_grid[i]->GetXaxis()->SetLabelSize(0);
        h2_pileup_grid[i]->GetXaxis()->SetTickLength(0);
        h2_pileup_grid[i]->GetYaxis()->SetLabelSize(0);
        h2_pileup_grid[i]->GetYaxis()->SetTickLength(0);
        h2_pileup_grid[i]->SetMinimum(1);
        
    }
    
    c_pileup_grid->cd();
    dir_stats->Append(c_pileup_grid);

    //:::::::::::O V E R   F L O W:::::::::::
    dir_stats->cd();
    c_overflow_grid = new TCanvas("c_overflow_grid", "Over Flow Grid", 650, 350);
    c_overflow_grid->Divide(layer_number-1);
    h2_overflow_grid.resize(layer_number-1);

    for (int i = 0; i < layer_number-1; i++)
    {   

        c_overflow_grid->cd(i+1);
        h2_overflow_grid[i] = new TH2F(Form("h2_overflow_grid_layer_%i", i), Form("Over Flow Grid - Layer %i", i+1), xmax, 0, xmax, ymax, 0, ymax);
        h2_overflow_grid[i]->SetStats(0);
        h2_overflow_grid[i]->Draw("COLZ");
        h2_overflow_grid[i]->GetXaxis()->SetTitle(Form("Over Flow Layer %i",i+1));
        h2_overflow_grid[i]->GetXaxis()->SetLabelSize(0);
        h2_overflow_grid[i]->GetXaxis()->SetTickLength(0);
        h2_overflow_grid[i]->GetYaxis()->SetLabelSize(0);
        h2_overflow_grid[i]->GetYaxis()->SetTickLength(0);
        h2_overflow_grid[i]->SetMinimum(1);
        
    }
    
    c_overflow_grid->cd();
    dir_stats->Append(c_overflow_grid);

    //:::::::::::M U L T I P L I C I T Y:::::::::::::::

    //:::::::::::Total Multiplicity
    h1_multiplicity = new TH1I("h1_multiplicity", "Total Multiplicity", det_number, 0, det_number+1);
    h1_multiplicity->SetStats(0);
    
    //:::::::::::Multiplicity per layer
    c_multiplicity_layer = new TCanvas("c_multiplicity_layer", "Multiplicty by Layer", 650, 350);
    c_multiplicity_layer->Divide(2, (layer_number + 1)/2);
    h1_multiplicity_layer.resize(layer_number);
    for (int i = 0; i < layer_number; i++)
    {
        c_multiplicity_layer->cd(i+1);
        h1_multiplicity_layer[i] = new TH1I(Form("Multiplicity_Layer_%i",i), Form("Multiplicity Layer %i",i), xmax * ymax+1, 0, xmax * ymax+1);
        h1_multiplicity_layer[i]->SetStats(0);
        h1_multiplicity_layer[i]->Draw();
    }
    c_multiplicity_layer->cd(0);
    dir_stats->Append(c_multiplicity_layer);

    //:::::::::::Layer Multiplicity
    h1_layer_multiplicity = new TH1I("h1_layer_multiplicity", "Layer Multiplicity", layer_number, 0, layer_number);
    h1_layer_multiplicity->SetStats(0);

    //:::::::::::::E N E R G Y:::::::::::::::::
    dir_energy->cd();

    // //:::::::: Gain Matched + Calibrated Energies 
    // h1_energy_layer_ch_GM.resize(layer_number);
    // //::::::::::Energy for now special case layer 0
    // h1_energy_layer_ch_GM[0].resize(1);
    // h1_energy_layer_ch_GM[0][0].resize(1);
    // h1_energy_layer_ch_GM[0][0][0] = new TH1F("tokyo_GM_fake", "Tokyo_GM_fake_ch", lisa_config->bin_energy, lisa_config->min_energy, lisa_config->max_energy);
    // h1_energy_layer_ch_GM[0][0][0]->Draw();
    // //:::::::::::Energy canvas GM for layer 1 and 2
    // for (int i = 1; i < layer_number; i++) //create a canvas for each layer
    // {

    //     h1_energy_layer_ch_GM[i].resize(xmax);
        
    //     for (int j = 0; j < xmax; j++)
    //     {
    //         h1_energy_layer_ch_GM[i][j].resize(ymax);
    //         for (int k = 0; k < ymax; k++)
    //         {   
    //             //general formula to place correctly on canvas for x,y coordinates
    //             c_energy_layer_ch[i]->cd((ymax-(k+1))*xmax + j + 1);
                
    //            city = "";
    //            for (auto & detector : detector_mapping)
    //            {
    //                if (detector.second.first.first == i && detector.second.second.first == j && detector.second.second.second == k)
    //                {
    //                    city = detector.second.first.second;
    //                    break;
    //                }
    //            }

    //             h1_energy_layer_ch_GM[i][j][k] = new TH1F(Form("energy_%s_%i_%i_%i_GM", city.Data(), i, j, k), city.Data(), lisa_config->bin_energy_GM, lisa_config->min_energy_GM, lisa_config->max_energy_GM);
    //             h1_energy_layer_ch_GM[i][j][k]->GetXaxis()->SetTitle("E(LISA) [MeV]");
    //             h1_energy_layer_ch_GM[i][j][k]->SetLineColor(kBlue+1);
    //             h1_energy_layer_ch_GM[i][j][k]->Draw();
    //         }
    //     }

    // }
    
    //Gain Matched + Calibrated with summed stats for layer
    h1_energy_layer_GM.resize(layer_number);
    //::::::::::Energy for now special case layer 0
    h1_energy_layer_GM[0] = new TH1F("tokyo_layer_GM_fake", "Tokyo_GM_fake_layer", lisa_config->bin_energy, lisa_config->min_energy, lisa_config->max_energy);
    h1_energy_layer_GM[0]->Draw();

     //:::::::::::Energy GM for layer 1 and layer 2 (summed stats between detectors in layer)
    for (int i = 1; i < layer_number; i++) //create a canvas for each layer
    {          
        h1_energy_layer_GM[i] = new TH1F(Form("energy_layer_%i_GM_all_detectors", i), Form("energy_layer_%i_GM_all_detectors", i), lisa_config->bin_energy_GM, lisa_config->min_energy_GM, lisa_config->max_energy_GM);
        h1_energy_layer_GM[i]->GetXaxis()->SetTitle(Form("E(LISA) Layer %i [MeV]",i));
        h1_energy_layer_GM[i]->SetLineColor(i);
        h1_energy_layer_GM[i]->Draw();   
    }
  
    //::::::::::: Energy Layer 1 vs Energy Layer 2 - stats of all dets together
    h2_energy_layer1_vs_layer2_GM = new TH2F("h2_energy_layer1_vs_layer2_GM", "E(Layer 1) vs E(Layer 2) GM", lisa_config->bin_energy_GM, lisa_config->min_energy_GM, lisa_config->max_energy_GM,lisa_config->bin_energy_GM, lisa_config->min_energy_GM, lisa_config->max_energy_GM); 
    h2_energy_layer1_vs_layer2_GM->SetOption("colz");
    h2_energy_layer1_vs_layer2_GM->GetXaxis()->SetTitle(Form("Energy - Layer 2 [MeV]"));
    h2_energy_layer1_vs_layer2_GM->GetYaxis()->SetTitle(Form("Energy - Layer 1 [MeV]"));
    
    //::::::::::::Sum Energy Layer 1 vs Layer 2 GAIN MATCHED
    h2_sum_energy_layer1_vs_layer2_GM = new TH2F("h2_sum_energy_layer1_vs_layer2_GM", "Sum E(Layer 1) vs Sum E(Layer 2) GM", lisa_config->bin_energy_GM*4, lisa_config->min_energy_GM*4, lisa_config->max_energy_GM*4,lisa_config->bin_energy_GM*4, lisa_config->min_energy_GM*4, lisa_config->max_energy_GM*4); 
    h2_sum_energy_layer1_vs_layer2_GM->SetOption("colz");
    h2_sum_energy_layer1_vs_layer2_GM->GetXaxis()->SetTitle(Form("Layer 2 E[MeV]"));
    h2_sum_energy_layer1_vs_layer2_GM->GetYaxis()->SetTitle(Form("Layer 1 E[MeV]"));

    //::::::::::: E N E R G Y  VS  T I M E::::::::::::
    dir_drift->cd();
    //::: Layer vs Time (WR)
    h2_energy_layer_vs_time.resize(layer_number);

    c_energy_layer_vs_time = new TCanvas("c_energy_layer_vs_wr","c_energy_layer_vs_wr", 650,350);
    c_energy_layer_vs_time->Divide(1,3);
    
    for (int i = 0; i < layer_number; i++)
    {
        c_energy_layer_vs_time->cd(i+1);
        h2_energy_layer_vs_time[i] = MakeTH2(dir_drift, "F", Form("h2_energyGM_layer%i_vs_time",i), Form("E_GM(Layer %i) vs WR [min]",i), 500, 0, 10000, lisa_config->bin_energy_GM, lisa_config->min_energy_GM, lisa_config->max_energy_GM);
        h2_energy_layer_vs_time[i]->SetTitle(Form("E_GM(Layer %i) vs WR",i));
        h2_energy_layer_vs_time[i]->GetYaxis()->SetTitle(Form("Energy GM Layer %i",i));
        h2_energy_layer_vs_time[i]->GetXaxis()->SetTitle("WR Time [min]");
        h2_energy_layer_vs_time[i]->Draw();
    }
    
    c_energy_layer_vs_time->cd(0);
    dir_drift->Append(c_energy_layer_vs_time);
    
    //::: Channel vs WR Time
    c_energy_ch_vs_time.resize(layer_number);
    h2_energy_ch_vs_time.resize(layer_number);

    //::::::::::Energy vs WR Time - for now special case layer 0
    c_energy_ch_vs_time[0] = new TCanvas("c_energy_layer0_ch_vs_wrtime", "Tokyo layer", 650, 350);
    h2_energy_ch_vs_time[0].resize(1);
    h2_energy_ch_vs_time[0][0].resize(1);

    h2_energy_ch_vs_time[0][0][0] = MakeTH2(dir_drift, "F", "h2_energyGM__ch_layer_0_vs_time", "E_GM(Layer 0) vs WR [min]", 500, 0, 10000, lisa_config->bin_energy_GM, lisa_config->min_energy_GM, lisa_config->max_energy_GM);

    h2_energy_ch_vs_time[0][0][0]->SetTitle("E_GM(Layer 0) vs WR [min]");
    h2_energy_ch_vs_time[0][0][0]->GetYaxis()->SetTitle("Energy 000");
    h2_energy_ch_vs_time[0][0][0]->GetXaxis()->SetTitle("WR Time");
    h2_energy_ch_vs_time[0][0][0]->Draw();
    dir_drift->Append(c_energy_ch_vs_time[0]);

    //::::::::::::Energy vs WR Time - Eris and Sparrow
    for (int i = 1; i < layer_number; i++) //create a canvas for each layer (not Tokyo)
    {
        c_energy_ch_vs_time[i] = new TCanvas(Form("c_ch_energy_layer_%d_vs_wrtime",i),Form("c_ch_energy_layer_%d_ch_vs_wrtime",i), 650,350);
        c_energy_ch_vs_time[i]->SetTitle(Form("Layer %d - Channel Energies vs WR Time",i));
        c_energy_ch_vs_time[i]->Divide(xmax,ymax); 
        h2_energy_ch_vs_time[i].resize(xmax);
        
        for (int j = 0; j < xmax; j++)
        {
            h2_energy_ch_vs_time[i][j].resize(ymax);
            for (int k = 0; k < ymax; k++)
            {   
                // general formula to place correctly on canvas for x,y coordinates
                c_energy_ch_vs_time[i]->cd((ymax-(k+1))*xmax + j + 1);
                
                city = "";
                for (auto & detector : detector_mapping)
                {
                    if (detector.second.first.first == i && detector.second.second.first == j && detector.second.second.second == k)
                    {
                        city = detector.second.first.second;
                        break;
                    }
                }
                
                h2_energy_ch_vs_time[i][j][k] = MakeTH2(dir_drift, "F", Form("h2_energyGM_ch_%d%d%d_vs_time",i,j,k), Form("E_GM ch %d%d%d vs WR [min]",i,j,k), 500, 0, 10000, lisa_config->bin_energy_GM, lisa_config->min_energy_GM, lisa_config->max_energy_GM);
                h2_energy_ch_vs_time[i][j][k]->SetTitle(Form("E_GM(%d%d%d) vs WR",i,j,k));
                h2_energy_ch_vs_time[i][j][k]->GetYaxis()->SetTitle(Form("Energy %d%d%d",i,j,k));
                h2_energy_ch_vs_time[i][j][k]->GetXaxis()->SetTitle("WR Time [min]");
                h2_energy_ch_vs_time[i][j][k]->Draw();
            }
        }
        c_energy_ch_vs_time[i]->cd(0);
        dir_drift->Append(c_energy_ch_vs_time[i]);
    }    


    //:::::::::::::T R A C E S:::::::::::::::::
    
    //Useless if not online
    // dir_traces->cd();
    // c_traces_layer_ch.resize(layer_number);
    // h1_traces_layer_ch.resize(layer_number);

    // //::::::::::::Traces for layer 0
    // c_traces_layer_ch[0] = new TCanvas("c_traces_layer_ch0", "Tokyo layer", 650, 350);
    // h1_traces_layer_ch[0].resize(1);
    // h1_traces_layer_ch[0][0].resize(1);
    // h1_traces_layer_ch[0][0][0] = new TH1F("tokyo_traces_layer", "Tokyo", 2000, 0, 20); // microseconds
    // h1_traces_layer_ch[0][0][0]->GetXaxis()->SetTitle("Time [us]");
    // h1_traces_layer_ch[0][0][0]->SetMinimum(lisa_config->AmplitudeMin); // set in macro
    // h1_traces_layer_ch[0][0][0]->SetMaximum(lisa_config->AmplitudeMax);
    // h1_traces_layer_ch[0][0][0]->SetStats(0);
    // h1_traces_layer_ch[0][0][0]->SetLineColor(kBlue+1);
    // h1_traces_layer_ch[0][0][0]->SetFillColor(kOrange-3);
    // h1_traces_layer_ch[0][0][0]->Draw();
    // dir_traces->Append(c_traces_layer_ch[0]);

    // //:::::::::::Traces canvas for layer 1 and 2   
    // for (int i = 1; i < layer_number; i++) //create a canvas for each layer
    // {
    //     c_traces_layer_ch[i] = new TCanvas(Form("c_traces_layer_%d",i),Form("c_traces_layer_%d",i), 650,350);
    //     c_traces_layer_ch[i]->SetTitle(Form("Layer %d - Traces",i));
    //     c_traces_layer_ch[i]->Divide(xmax,ymax); 
    //     h1_traces_layer_ch[i].resize(xmax);
    //     for (int j = 0; j < xmax; j++)
    //     {
    //         h1_traces_layer_ch[i][j].resize(ymax);
    //         for (int k = 0; k < ymax; k++)
    //         {   
    //             // general formula to place correctly on canvas for x,y coordinates
    //             c_traces_layer_ch[i]->cd((ymax-(k+1))*xmax + j + 1);
                
    //             city = "";
    //             for (auto & detector : detector_mapping)
    //             {
    //                 if (detector.second.first.first == i && detector.second.second.first == j && detector.second.second.second == k)
    //                 {
    //                     city = detector.second.first.second;
    //                     break;
    //                 }
    //             }

    //             h1_traces_layer_ch[i][j][k] = new TH1F(Form("traces_%s_%i_%i_%i", city.Data(), i, j, k), city.Data(), 2000, 0, 20);
    //             h1_traces_layer_ch[i][j][k]->GetXaxis()->SetTitle("Time [us]");
    //             h1_traces_layer_ch[i][j][k]->SetMinimum(lisa_config->AmplitudeMin); // set in macro
    //             h1_traces_layer_ch[i][j][k]->SetMaximum(lisa_config->AmplitudeMax);
    //             h1_traces_layer_ch[i][j][k]->SetStats(0);
    //             h1_traces_layer_ch[i][j][k]->SetLineColor(kBlue+1);
    //             h1_traces_layer_ch[i][j][k]->SetFillColor(kOrange-3);
    //             h1_traces_layer_ch[i][j][k]->Draw();
    //         }
    //     }
    //     c_traces_layer_ch[i]->cd(0);
    //     dir_traces->Append(c_traces_layer_ch[i]);

    // }


    //::: Traces stats Layer 1 and 2
    dir_traces->cd();
    c_traces_layer_ch_stat.resize(layer_number);
    h2_traces_layer_ch_stat.resize(layer_number);

    //::::::::::::Traces for layer 0
    c_traces_layer_ch_stat[0] = new TCanvas("c_traces_layer_ch0", "Tokyo layer", 650, 350);
    h2_traces_layer_ch_stat[0].resize(1);
    h2_traces_layer_ch_stat[0][0].resize(1);
    h2_traces_layer_ch_stat[0][0][0] = new TH2F("tokyo_traces_layer", "Tokyo", 2000, 0, 20,5000,3000,20000); // microseconds
    h2_traces_layer_ch_stat[0][0][0]->GetXaxis()->SetTitle("Time [us]");
    h2_traces_layer_ch_stat[0][0][0]->SetMinimum(lisa_config->AmplitudeMin); // set in macro
    h2_traces_layer_ch_stat[0][0][0]->SetMaximum(lisa_config->AmplitudeMax);
    h2_traces_layer_ch_stat[0][0][0]->SetStats(0);
    h2_traces_layer_ch_stat[0][0][0]->SetLineColor(kBlue+1);
    h2_traces_layer_ch_stat[0][0][0]->SetFillColor(kOrange-3);
    h2_traces_layer_ch_stat[0][0][0]->Draw();
    dir_traces->Append(c_traces_layer_ch_stat[0]);
    
    //Traces stat for layer 1 and 2
    for (int i = 1; i < layer_number; i++) 
    {
        c_traces_layer_ch_stat[i] = new TCanvas(Form("c_traces_layer_%d_stat",i),Form("c_traces_layer_%d_stat",i), 650,350);
        c_traces_layer_ch_stat[i]->SetTitle(Form("Layer %d - Traces",i));
        c_traces_layer_ch_stat[i]->Divide(xmax,ymax); 
        h2_traces_layer_ch_stat[i].resize(xmax);
        for (int j = 0; j < xmax; j++)
        {
            h2_traces_layer_ch_stat[i][j].resize(ymax);
            for (int k = 0; k < ymax; k++)
            {   
                // general formula to place correctly on canvas for x,y coordinates
                c_traces_layer_ch_stat[i]->cd((ymax-(k+1))*xmax + j + 1);
                
                city = "";
                for (auto & detector : detector_mapping)
                {
                    if (detector.second.first.first == i && detector.second.second.first == j && detector.second.second.second == k)
                    {
                        city = detector.second.first.second;
                        break;
                    }
                }

                h2_traces_layer_ch_stat[i][j][k] = new TH2F(Form("traces_%i_%i_%i_stat", i, j, k), Form("%i%i%i",i,j,k), 250, 0, 20,500,3000,15000);
                h2_traces_layer_ch_stat[i][j][k]->GetXaxis()->SetTitle("Time [us]");
                h2_traces_layer_ch_stat[i][j][k]->SetMinimum(lisa_config->AmplitudeMin);
                h2_traces_layer_ch_stat[i][j][k]->SetMaximum(lisa_config->AmplitudeMax);
                h2_traces_layer_ch_stat[i][j][k]->SetLineColor(kBlue+1);
                h2_traces_layer_ch_stat[i][j][k]->SetFillColor(kOrange-3);
                h2_traces_layer_ch_stat[i][j][k]->Draw("colz");
                h2_traces_layer_ch_stat[i][j][k]->SetOption("colz");

                gPad->SetLogz();
            }
        }
        c_traces_layer_ch_stat[i]->cd(0);
        dir_traces->Append(c_traces_layer_ch_stat[i]);

    }

    return kSUCCESS;
}


void LisaNearlineSpectra::Exec(Option_t* option)
{   
    wr_time = 0;
    int multiplicity[layer_number] = {0};
    int total_multiplicity = 0;

    std::vector<uint32_t> sum_energy_layer;
    sum_energy_layer.resize(layer_number);

    int energy_ch[layer_number][xmax][ymax] = {0,0,0};
    int energy_ch_GM[layer_number][xmax][ymax] = {0,0,0};

    std::vector<uint32_t> sum_energy_layer_GM;
    sum_energy_layer_GM.resize(layer_number);

    std::vector<uint32_t> energy_layer_GM;
    energy_layer_GM.resize(layer_number);

    Long64_t LISA_time_mins = 0;

    //sfsLOG(info, "Comment to slow down program for testing");
    for (auto const & lisaCalItem : *lisaCalArray)
    {

        wr_time = lisaCalItem.Get_wr_t();
        if (wr_time == 0)return;
        if(wr_time > 0) LISA_time_mins = (wr_time - exp_config->exp_start_time)/ 60E9;

        //sfsLOG(info, "LISA_time_mins: " << LISA_time_mins << " wr time: "<< std::fixed << std::setprecision(10)<< wr_time);


        //::::::: Retrieve Data ::::::::::::::
        layer = lisaCalItem.Get_layer_id();
        city = lisaCalItem.Get_city();
        int xpos = lisaCalItem.Get_xposition();
        int ypos = lisaCalItem.Get_yposition();
        uint32_t energy = lisaCalItem.Get_energy();
        std::vector<uint16_t> trace = lisaCalItem.Get_trace();
        double energy_GM = lisaCalItem.Get_energy_GM();
        int pileup = lisaCalItem.Get_pileup();
        int overflow = lisaCalItem.Get_overflow();
        uint64_t evtno = header->GetEventno();
        
        //::::::::F I L L   H I S T O S:::::::
        //:::::::: H I T  P A T T E R N ::::::::::
        //:::::::::Layer
        int hp_bin = (ymax-(ypos+1))*xmax + xpos; // -1 compared to canvas position
        h1_hitpattern_layer[layer]->Fill(hp_bin);
        //:::::::::Total
        int hp_total_bin;
        if (layer != 0) hp_total_bin = layer * xmax * ymax + hp_bin - 3; // -3 is a fudge for uneven layers, temporary
        else hp_total_bin = 0;
        h1_hitpattern_total->Fill(hp_total_bin);
        //::::::::::By grid
        if (layer != 0) h2_hitpattern_grid[layer-1]->Fill(xpos,ypos);


        //:::::::::P I L E   UP:::::::::::::
        //::::::::::By grid
        if (pileup != 0) if (layer != 0) h2_pileup_grid[layer-1]->Fill(xpos,ypos);

        //:::::::::O V E R  F L O W:::::::::::::
        //::::::::::By grid
        if (overflow != 0) if (layer != 0) h2_overflow_grid[layer-1]->Fill(xpos,ypos);
        
        //:::::::: Count Multiplicity ::::::::
        multiplicity[layer]++;
        total_multiplicity++;

        //::::::::: E N E R G Y :::::::::::::::
        
        //::::::::Define Sum Energy
        sum_energy_layer[layer] += energy;
        energy_ch[layer][xpos][ypos] = energy;

        //::::Fill Energy Raw
        //h1_energy_layer_ch[layer][xpos][ypos]->Fill(energy);

        //::::::::Define Sum Energy GM
        sum_energy_layer_GM[layer] += energy_GM;
        energy_ch_GM[layer][xpos][ypos] = energy_GM;
        energy_layer_GM[layer] = energy_GM;
        
        //:::Fill Energy Gain Matched
        //h1_energy_layer_ch_GM[layer][xpos][ypos]->Fill(energy_GM);	//energy per layer and channel
        h1_energy_layer_GM[layer]->Fill(energy_GM);			        //energy per layer
                
        //:::::::Energy vs Time
        if (energy_GM > 0 && LISA_time_mins > 0)
        {
            //sfsLOG(info, "conditions on LISA time: " << LISA_time_mins << "and energy: " << energy_GM );
            h2_energy_layer_vs_time[layer]->Fill(LISA_time_mins, energy_GM);
            h2_energy_ch_vs_time[layer][xpos][ypos]->Fill(LISA_time_mins, energy_GM); 
        }
        
        //::::::::: Fill Traces ::::::::::::::
        // h1_traces_layer_ch[layer][xpos][ypos]->Reset();
        // for (int i = 0; i < trace.size(); i++)
        // {
        //     h1_traces_layer_ch[layer][xpos][ypos]->SetBinContent(i, trace[i]);
        //     //sfsLOG(info, "layer: " << layer << " x max: " << xmax << " ymax: " << ymax);

        // }    
    
        // :::: Fill traces stats :::
        for (int i = 0; i < trace.size(); i++)
        {
            if(layer==1)
            {
                //sfsLOG(info, "EXEC Layer number" << layer_number << " layer id :" << layer);
            }
            
	        h2_traces_layer_ch_stat[layer][xpos][ypos]->Fill(i*0.01,trace[i]);

        }
    
    }
    //sfsLOG(info, "::::::::::END LOOP::::::::::::" << " Layer number :" << layer_number);

    //sfsLOG(info, "LISA_time_mins: " << LISA_time_mins << " wr time: "<< std::fixed << std::setprecision(10)<< wr_time);

    if ( wr_time == 0 ) return;

    //:::::: WR Time Difference
    if( prev_wr > 0 )
    {
        wr_diff = wr_time - prev_wr; //to express wr difference in us
        h1_wr_diff->Fill(wr_diff);
    }
    prev_wr = wr_time;
    //sfsLOG(info,"wr time: " << wr_time << "   prev wr: " << prev_wr << " wr diff: " << wr_diff);


    //::::::: Fill Multiplicity ::::::::::
    for (int i = 0; i < layer_number; i++) h1_multiplicity_layer[i]->Fill(multiplicity[i]);
    h1_multiplicity->Fill(total_multiplicity);

    for (int i = 0; i < layer_number; i++)
    {
        if(multiplicity[i] != 0) h1_layer_multiplicity->Fill(i);
        //sfsLOG(info," layer number : " << layer_number << " layer : " << layer << " multiplicity [layer] : " << multiplicity[layer] << " multiplicity [i] : " << multiplicity[i]);
    }

    //:::::::Fill Sum Energy::::::::::
    //h2_sum_energy_layer1_vs_layer2->Fill(sum_energy_layer[2],sum_energy_layer[1]);
        
    //:::::::Fill Sum Energy GM::::::::::
    h2_sum_energy_layer1_vs_layer2_GM->Fill(sum_energy_layer_GM[2],sum_energy_layer_GM[1]);

    //:::::: Fill Energy GM for layers 1 and 2 ::::::::::
    h2_energy_layer1_vs_layer2_GM->Fill(energy_layer_GM[2],energy_layer_GM[1]);
        

    // ::: old en vs time ---- To be deleted soon
    //int wr_r = round(wr_time/1000000000);
    //time_t rawtime;
    //time(&rawtime);
    // if (fNEvents % 1000 == 0 && sum_energy_layer[1] > 0) 
    // {
    //     for (int i = 0; i < layer_number; i++)hG_energy_layer_vs_time[i]->SetPoint(en_count1, wr_r, sum_energy_layer[i]);
    //     en_count1++;
    // } 

    // if (fNEvents % 1000 == 0 && energy_ch[1][0][0]>0) 
    // {
    //     hG_energy_layer_ch_vs_time[0][0][0]->SetPoint(en_count2, wr_r, energy_ch[0][0][0]);
    //     //sfsLOG(info, " ENERGY " << energy_ch[0][0][0] );

    //     for (int i = 1; i < layer_number; i++) 
    //     {
    //         for(int j = 0; j < xmax; j++)
    //         {
    //             for (int z = 0; z < ymax; z++)
    //             {
    //                 hG_energy_layer_ch_vs_time[i][j][z]->SetPoint(en_count2, wr_r, energy_ch[i][j][z]);
    //                 //sfsLOG(info, " ENERGY " << energy_ch[i][j][z] << " i : " << i << " j : " << j << " z : " << z );
    //             }
                
    //         }
            
    //     //sfsLOG(info, "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
    //     //sfsLOG(info, " wr: " << wr_r << " wr tot "<< wr_time);

    //     }


    //     en_count2++;
    // } 
    //::::

    fNEvents += 1;
}

void LisaNearlineSpectra::FinishEvent()
{

}

void LisaNearlineSpectra::FinishTask()
{

    TDirectory* tmp = gDirectory;
    FairRootManager::Instance()->GetOutFile()->cd();
    dir_lisa->Write();
    sfsLOG(info, "Written LISA analysis histograms to file.");
    sfsLOG(info, "LISA events : " << fNEvents);


}

ClassImp(LisaNearlineSpectra)
