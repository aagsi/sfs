/******************************************************************************
 *   Copyright (C) 2024 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2024 Members of HISPEC/DESPEC Collaboration                *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************
 *                       E.M. Gandolfo, C.E. Jones                            *
 *                               25..11.24                                    *
 ******************************************************************************/

// FairRoot
#include "FairLogger.h"
#include "FairRootManager.h"
#include "FairRunAna.h"
#include "FairRunOnline.h"

// sfs
//#include "TravMusSpectra.h"
#include "TravMusNearlineSpectra.h"
#include "EventHeader.h"
#include "sfsLogger.h"
#include "AnalysisTools.h"

// ROOT
#include "TCanvas.h"
#include "TClonesArray.h"
#include "TFolder.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TH2F.h"
#include "THttpServer.h"
#include "TMath.h"
#include "TRandom.h"
#include "TFile.h"


TravMusNearlineSpectra::TravMusNearlineSpectra() : TravMusNearlineSpectra("TravMusNearlineSpectra")
{
    frs_config = TFrsConfiguration::GetInstance();
}

TravMusNearlineSpectra::TravMusNearlineSpectra(const TString& name, Int_t iVerbose)
    :   FairTask(name, iVerbose)
    ,   travMusCalArray(nullptr)
    ,   travMusAnaArray(nullptr)
    ,   fNEvents(0)
    ,   header(nullptr)
{
    frs_config = TFrsConfiguration::GetInstance();
}

TravMusNearlineSpectra::~TravMusNearlineSpectra()
{
    sfsLOG(info, "");
}

InitStatus TravMusNearlineSpectra::Init()
{
    FairRootManager* mgr = FairRootManager::Instance();
    sfsLOG_IF(fatal, NULL == mgr, "FairRootManager not found");

    header = (EventHeader*)mgr->GetObject("EventHeader.");
    sfsLOG_IF(error, !header, "Branch EventHeader. not found");

    travMusCalArray = mgr->InitObjectAs<decltype(travMusCalArray)>("TravMusCalData");
    sfsLOG_IF(fatal, !travMusCalArray, "Branch TravMusCalData not found!");
    travMusAnaArray = mgr->InitObjectAs<decltype(travMusAnaArray)>("TravMusAnaData");
    sfsLOG_IF(fatal, !travMusAnaArray, "Branch TravMusAnaData not found!");
    
    mgr->GetOutFile()->cd();
    // try to find FRS first, then MUSIC, if not..
    dir_travmus = gDirectory->mkdir("Travel MUSIC");
    //mgr->Register("Travel MUSIC", "Travel MUSIC", dir_travmus, false); // allow other tasks to find this
    
    dir_raw_adc = dir_travmus->mkdir("Raw ADC");
    dir_drifts = dir_travmus->mkdir("Drifts");
    dir_raw_adc->cd();

    //:::::::::: Raw ADC ::::::::::::::::
    c_raw_adc = new TCanvas("c_raw_adc", "Travel MUSIC Raw ADC", 650, 350);
    c_raw_adc->Divide(4, 2);
    for (int i = 0; i < 8; i++)
    {
        c_raw_adc->cd(i+1);
        h1_travmus_raw_adc[i] = MakeTH1(dir_raw_adc, "I", Form("h1_travmus_raw_adc_anode_%i", i), Form("Raw ADC - Travel MUSIC Anode %i", i), 10500, 100, 12500, "ADC Channel", kPink-3, kBlue+2);
        h1_travmus_raw_adc[i]->Draw();
    }
    c_raw_adc->cd(0);
    dir_raw_adc->Append(c_raw_adc);


    dir_travmus->cd();

    // need Z from SC1
    // h1_Z_travmus = MakeTH1(dir_tac_1d, "D", "h1_Z_travmus", "Z (Travel MUSIC)", 750, 10, 100, "Z (Travel MUSIC)", kPink-3, kBlue+2);
    // h1_z_travmus_mhtdc = MakeTH1(dir_mhtdc_1d, "D", "h1_z_travmus_mhtdc", "Z (Travel MUSIC) (MHTDC)", 1000, 0, 100, "Z (Travel MUSIC)", kPink-3, kBlue+2);
    // h2_Ztrav_vs_T = MakeTH2(dir_drifts, "D", "h2_Ztrav_vs_T", "Z (Trav Mus) vs Time [mins]", 500, 0, 10000, 1500, frs_config->fMin_Z, frs_config->fMax_Z);
    // one of these is a duplicate..

    // from LISA branch, histos in FrsNearline
    h1_travmus_dE = MakeTH1(dir_travmus, "D", "h1_travmus_dE", "dE (Travel MUSIC)", 1000, 0, 4000., "dE (Travel MUSIC)", kPink-3, kBlue+2);
    h1_travmus_dE_driftcorr = MakeTH1(dir_travmus, "D", "h1_travmus_dE_driftcorr", "dE DriftCorr(Travel MUSIC)", 1000, 0, 4000., "dE DriftCorr (Travel MUSIC)", kPink-3, kBlue+2);

    //::: TravMus Drift with ref to the run number
    //c_TravMus_drift = new TCanvas("c_TravMus_drift", "c_TravMus_drift", 650, 350);
    //c_TravMus_drift->SetLogz();
    //c_TravMus_drift->cd();
    h2_TravMus_vs_T = MakeTH2(dir_drifts, "D", "h2_TravMus_vs_T", "dE (TravM) vs Time [min]", 1000, 0, 10000, 1000, 0, 4200, "WR [min]", "dE (Travel MUSIC)");
    // info on run number-not working now damn (EG)
    frs_time_min = std::numeric_limits<double>::max();
    frs_time_max = std::numeric_limits<double>::lowest(); 
    double initial_x_min = 0;      
    double initial_x_max = 10000; 
    double y_position = 4100;     
    double text_offset = 50; 
 
    hline = new TLine(initial_x_min, y_position, initial_x_max, y_position);
    hline->SetLineColor(kRed);
    hline->SetLineWidth(2);

    left_bar = new TLine(initial_x_min, y_position - 50, initial_x_min, y_position + 50);
    left_bar->SetLineColor(kRed);
    left_bar->SetLineWidth(2);

    right_bar = new TLine(initial_x_max, y_position - 50, initial_x_max, y_position + 50);
    right_bar->SetLineColor(kRed);
    right_bar->SetLineWidth(2);

    run_number_text = new TText((initial_x_min + initial_x_max) / 2, y_position + text_offset,
                                Form("run: %d", frs_config->frun_num));
    run_number_text->SetTextSize(0.03);
    run_number_text->SetTextAlign(22); // Center alignment

    // hline->Write();
    // left_bar->Write();
    // right_bar->Write();
    // run_number_text->Write();
    // h2_TravMus_vs_T->Draw();

    //c_TravMus_drift->cd();
    //dir_drifts->Append(c_TravMus_drift);

    // Drift corrected
    h2_TravMus_driftcorr_vs_T = MakeTH2(dir_drifts, "D", "h2_TravMus_driftcorr_vs_T", "dE (TravM) DriftCorr vs Time [min]", 1000, 0, 10000, 1000, 0, 4200, "WR [min]", "dE DriftCorr (Travel MUSIC)");


    return kSUCCESS;

}


void TravMusNearlineSpectra::Exec(Option_t* option)
{

    if (travMusAnaArray->size() <= 0) return;

    uint64_t wr_t = 0;

    // Cal data
    for (auto const & travMusCalItem : *travMusCalArray)
    {
        if(travMusCalItem.Get_wr_t() == 0) return;
        for (int i = 0; i < 8; i++)
        {
            h1_travmus_raw_adc[i]->Fill(travMusCalItem.Get_music_energy(i));
        }
    }

    // Ana data
    const auto & travMusicHitItem = travMusAnaArray->at(0); 

    if (travMusicHitItem.Get_wr_t() > 0 && travMusicHitItem.Get_travmusic_dE() > 0) h1_travmus_dE->Fill(travMusicHitItem.Get_travmusic_dE());

    int TM_time_mins = 0;
    if (travMusicHitItem.Get_wr_t() > 0) TM_time_mins = (travMusicHitItem.Get_wr_t() - exp_config->exp_start_time)/ 60E9;

    // from LISA branch
    // ::: Drift TM        
    if (travMusicHitItem.Get_travmusic_dE() > 0 && TM_time_mins > 0) 
    {
        double y_position = 4010;  
        hline->SetX1(frs_time_min);
        hline->SetX2(frs_time_max);
        hline->SetY1(y_position);
        hline->SetY2(y_position);

        left_bar->SetX1(frs_time_min);
        left_bar->SetX2(frs_time_min);
        left_bar->SetY1(y_position - 50);
        left_bar->SetY2(y_position + 50);

        right_bar->SetX1(frs_time_max);
        right_bar->SetX2(frs_time_max);
        right_bar->SetY1(y_position - 50);
        right_bar->SetY2(y_position + 50);

        run_number_text->SetText((frs_time_min + frs_time_max) / 2, y_position + 50,
                                Form("run: %d", frs_config->frun_num));
        
        h2_TravMus_vs_T->Fill(TM_time_mins, travMusicHitItem.Get_travmusic_dE());

    }
    if (travMusicHitItem.Get_travmusic_dE_driftcorr() > 0 && TM_time_mins > 0) h2_TravMus_driftcorr_vs_T->Fill(TM_time_mins, travMusicHitItem.Get_travmusic_dE_driftcorr());

   
    fNEvents++;
}

void TravMusNearlineSpectra::FinishEvent()
{

}

void TravMusNearlineSpectra::FinishTask()
{   

    TDirectory* tmp = gDirectory;
    FairRootManager::Instance()->GetOutFile()->cd();
    dir_travmus->Write();
    sfsLOG(info, "Written travMUSIC analysis histograms to file.");

}

ClassImp(TravMusNearlineSpectra)
