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
 *                             J.E.L. Larsson                                 *
 *                               25.11.24                                     *
 ******************************************************************************/

// FairRoot
#include "FairLogger.h"
#include "FairRootManager.h"
#include "FairRunAna.h"
#include "FairRunOnline.h"
#include "FairRuntimeDb.h"

// sfs
#include "FrsFatimaCorrelationsNearline.h"
#include "EventHeader.h"
#include "FatimaTwinpeaksData.h"
#include "FatimaTwinpeaksCalData.h"
#include "FrsGate.h"
#include "FrsHitData.h"
#include "TFatimaTwinpeaksConfiguration.h"

#include "sfsLogger.h"


#include "TCanvas.h"
#include "TClonesArray.h"
#include "TFolder.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TGraph.h"
#include "THttpServer.h"
#include "TMath.h"
#include "TRandom.h"
#include "TFile.h"
#include "TDirectory.h"

FrsFatimaCorrelationsNearline::FrsFatimaCorrelationsNearline() : FrsFatimaCorrelationsNearline("FrsFatimaCorrelationsNearline")
{
    fatima_configuration = TFatimaTwinpeaksConfiguration::GetInstance();
    frs_configuration = TFrsConfiguration::GetInstance();

}

FrsFatimaCorrelationsNearline::FrsFatimaCorrelationsNearline(FrsGate * fg) : FrsFatimaCorrelationsNearline("FrsFatimaCorrelationsNearline")
{
    fatima_configuration = TFatimaTwinpeaksConfiguration::GetInstance();
    frsgate = fg;
    frs_configuration = TFrsConfiguration::GetInstance();
}

FrsFatimaCorrelationsNearline::FrsFatimaCorrelationsNearline(const TString& name, Int_t verbose)
    : FairTask(name, verbose)
    , fHitFatima(NULL)
    , hitArrayFrs(nullptr)
    , fNEvents(0)
    , header(nullptr)
{    
    fatima_configuration = TFatimaTwinpeaksConfiguration::GetInstance();
}

FrsFatimaCorrelationsNearline::~FrsFatimaCorrelationsNearline()
{
    sfsLOG(info, "");
    if (fHitFatima)
        delete fHitFatima;
}


InitStatus FrsFatimaCorrelationsNearline::Init()
{

    FairRootManager* mgr = FairRootManager::Instance();
    sfsLOG_IF(fatal, NULL == mgr, "FairRootManager not found");

    FairRunAna* run = FairRunAna::Instance();

    header = mgr->InitObjectAs<decltype(header)>("EventHeader.");
    sfsLOG_IF(error, !header, "Branch EventHeader. not found!");

    fHitFatima = (TClonesArray*)mgr->GetObject("FatimaTwinpeaksCalData");
    sfsLOG_IF(fatal, !fHitFatima, "Branch FatimaTwinpeaksCalData not found!");
    hitArrayFrs = mgr->InitObjectAs<decltype(hitArrayFrs)>("FrsHitData");
    sfsLOG_IF(fatal, !hitArrayFrs, "Branch FrsHitData not found!");

    dir_corr = (TDirectory*)mgr->GetObject("Correlations");
    if (dir_corr == nullptr) 
    {
        LOG(info) << "Creating Correlations Directory";
        FairRootManager::Instance()->GetOutFile()->cd();
        dir_corr = gDirectory->mkdir("Correlations");
        mgr->Register("Correlations", "Correlations Directory", dir_corr, false); // allow other tasks to find this
        found_dir_corr = false;
    }

    TString dirname = "FATIMA-FRS_gated-" + frsgate->GetName();
    dir_fatima = dir_corr->mkdir(dirname);

    dir_fatima->cd();

    //Implant rate
    g_frs_rate = new TGraph();
    g_frs_rate->SetName(TString("g_frs_fatima_rate_monitor_gated_")+frsgate->GetName());
    g_frs_rate->SetTitle(TString("FRS identified ions per second, avg 60 secs"));
    g_frs_rate->GetXaxis()->SetTitle("seconds");

    g_frs_total = new TGraph();
    g_frs_total->SetName(TString("g_frs_fatima_total_monitor_gated_")+frsgate->GetName());
    g_frs_total->SetTitle(TString("FRS identified ions in total"));
    g_frs_total->GetXaxis()->SetTitle("seconds");



    h2_frs_Z_vs_AoQ_gated = new TH2F(TString("h2_frs_fatima_Z_vs_AoQ_gated_")+frsgate->GetName(),TString("Z vs AoQ plot gated on FRS ")+frsgate->GetName(),1000,frs_configuration->fMin_AoQ,frs_configuration->fMax_AoQ,1000,frs_configuration->fMin_Z,frs_configuration->fMax_Z);
    h2_frs_Z_vs_AoQ_gated->GetXaxis()->SetTitle("A/Q");
    h2_frs_Z_vs_AoQ_gated->GetYaxis()->SetTitle("Z");


    h2_frs_Z_vs_Z2_gated = new TH2F(TString("h2_frs_fatima_Z_vs_Z2_gated_")+frsgate->GetName(),TString("Z1 vs Z2 plot gated on FRS ")+frsgate->GetName(),1000,frs_configuration->fMin_Z,frs_configuration->fMax_Z,1000,frs_configuration->fMin_Z,frs_configuration->fMax_Z);
    h2_frs_Z_vs_Z2_gated->GetXaxis()->SetTitle("Z1");
    h2_frs_Z_vs_Z2_gated->GetYaxis()->SetTitle("Z2");




    h2_frs_x2_vs_AoQ_gated = new TH2F(TString("h2_frs_fatima_x2_vs_AoQ_gated_")+frsgate->GetName(),TString("x2 vs AoQ plot gated on FRS ")+frsgate->GetName(),1000,frs_configuration->fMin_AoQ,frs_configuration->fMax_AoQ,1000,frs_configuration->fMin_x2,frs_configuration->fMax_x2);
    h2_frs_x2_vs_AoQ_gated->GetYaxis()->SetTitle("x2");
    h2_frs_x2_vs_AoQ_gated->GetXaxis()->SetTitle("A/Q");



    h2_frs_x4_vs_AoQ_gated = new TH2F(TString("h2_frs_fatima_x4_vs_AoQ_gated_")+frsgate->GetName(),TString("x4 vs AoQ plot gated on FRS ")+frsgate->GetName(),1000,frs_configuration->fMin_AoQ,frs_configuration->fMax_AoQ,1000,frs_configuration->fMin_x4,frs_configuration->fMax_x4);
    h2_frs_x4_vs_AoQ_gated->GetXaxis()->SetTitle("A/Q");
    h2_frs_x4_vs_AoQ_gated->GetYaxis()->SetTitle("x4");
    h2_frs_x2_vs_AoQ_gated->Draw("COLZ");

    h2_fatima_energy_vs_tsci41 = new TH2F(TString("h2_fatima_energy_vs_tsci41_frs_gate_"+frsgate->GetName()),TString("Fatima energies vs t(det) - t(sci41), short lifetime,  gated FRS on "+frsgate->GetName()),10000,-2000,stop_short_lifetime_collection,fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
    h2_fatima_energy_vs_tsci41->GetXaxis()->SetTitle("time difference (ns)");
    h2_fatima_energy_vs_tsci41->GetYaxis()->SetTitle("energy (keV)");

    

    h1_fatima_energy_promptflash_cut = new TH1F(TString("h1_fatima_energy_promptflash_cut_frs_gate_"+frsgate->GetName()),TString("Fatima energy, prompt flash cut out, short lifetime, gated FRS on "+frsgate->GetName()),fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
    h1_fatima_energy_promptflash_cut->GetXaxis()->SetTitle("energy (keV)");


    h2_fatima_energy_vs_tsci41_mult2 = new TH2F(TString("h2_fatima_energy_vs_tsci41_mult2_frs_gate_"+frsgate->GetName()),TString("Fatima mult = 2 energies vs t(det) - t(sci41), short lifetime,  gated FRS on "+frsgate->GetName()),10000,-2000,stop_short_lifetime_collection,fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
    h2_fatima_energy_vs_tsci41_mult2->GetXaxis()->SetTitle("time difference (ns)");
    h2_fatima_energy_vs_tsci41_mult2->GetYaxis()->SetTitle("energy (keV)");

    

    h1_fatima_energy_promptflash_cut_mult2 = new TH1F(TString("h1_fatima_energy_promptflash_cut_mult2_frs_gate_"+frsgate->GetName()),TString("Fatima mult = 2 energy, prompt flash cut out, short lifetime, gated FRS on "+frsgate->GetName()),fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
    h1_fatima_energy_promptflash_cut_mult2->GetXaxis()->SetTitle("energy (keV)");



    

    h2_fatima_energy_energy_promptflash_cut = new TH2F(TString("h2_fatima_energy_energy_promptflash_cut_frs_gate_"+frsgate->GetName()),TString(Form("Fatima energy vs energy, |t(det1)-t(det2)|<%i ns, prompt flash cut out, short lifetime, gated FRS on ",fatima_coincidence_gate)+frsgate->GetName()),fenergy_nbins,fenergy_bin_low,fenergy_bin_high,fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
    h2_fatima_energy_energy_promptflash_cut->GetXaxis()->SetTitle("energy (keV)");
    h2_fatima_energy_energy_promptflash_cut->GetYaxis()->SetTitle("energy (keV)");




    h2_fatima_energy_vs_sci41_wr_long = new TH2F(TString("h2_fatima_energy_vs_sci41_wr_long_frs_gate_"+frsgate->GetName()),TString("Fatima energies vs t(det,wr) - t(sci41,wr) long lifetime, gated FRS on "+frsgate->GetName()),10000,long_lifetime_binlow,long_lifetime_binhigh,fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
    h2_fatima_energy_vs_sci41_wr_long->GetXaxis()->SetTitle("time difference (ns)");
    h2_fatima_energy_vs_sci41_wr_long->GetYaxis()->SetTitle("energy (keV)");



    

    h1_fatima_energy_promptflash_cut_long = new TH1F(TString("h1_fatima_energy_promptflash_cut_long_frs_gate_"+frsgate->GetName()),TString("Fatima energy, prompt flash cut out, long lifetime, gated FRS on "+frsgate->GetName()),fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
    h1_fatima_energy_promptflash_cut_long->GetXaxis()->SetTitle("energy (keV)");


    h2_fatima_energy_energy_promptflash_cut_long = new TH2F(TString("h2_fatima_energy_energy_promptflash_cut_long_frs_gate_"+frsgate->GetName()),TString(Form("Fatima energy vs energy, |t(det1)-t(det2)|<%i ns, prompt flash cut out, long lifetime, gated FRS on ",fatima_coincidence_gate)+frsgate->GetName()),fenergy_nbins,fenergy_bin_low,fenergy_bin_high,fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
    h2_fatima_energy_energy_promptflash_cut_long->GetXaxis()->SetTitle("energy (keV)");
    h2_fatima_energy_energy_promptflash_cut_long->GetYaxis()->SetTitle("energy (keV)");

    

    //energy-gated spectra:
    folder_energy_gated = new TDirectory*[gamma_energies_of_interest.size()];

    h1_fatima_tsci41_energy_gated = new TH1F*[gamma_energies_of_interest.size()];
        
    h1_fatima_energy_promptflash_cut_energy_gated = new TH1F*[gamma_energies_of_interest.size()];
        
    //long:
    h1_fatima_energy_promptflash_cut_long_energy_gated = new TH1F*[gamma_energies_of_interest.size()];

    h1_fatima_twr_sci41_energy_gated = new TH1F*[gamma_energies_of_interest.size()];

    h2_fatima_energy_gated_energy_vs_dt_prompt_flash_cut = new TH2F*[gamma_energies_of_interest.size()];
    
    h2_fatima_energy_gated_energy_vs_dt_prompt_flash_cut_long = new TH2F*[gamma_energies_of_interest.size()];
        
    
    for (int idx_gamma_gate = 0; idx_gamma_gate < gamma_energies_of_interest.size(); idx_gamma_gate++){
        folder_energy_gated[idx_gamma_gate] = dir_fatima->mkdir(Form("Energy gated coincidence spectra, Eg = %i",(int)gamma_energies_of_interest.at(idx_gamma_gate)));
        folder_energy_gated[idx_gamma_gate]->cd();

        h1_fatima_tsci41_energy_gated[idx_gamma_gate] = new TH1F(TString(Form("h1_fatima_tsci41_energy_gated_%i_frs_gate_",(int)gamma_energies_of_interest.at(idx_gamma_gate)))+frsgate->GetName(),TString(Form("t(det) - t(sci41) gated on E = %i keV, gated FRS on ",(int)gamma_energies_of_interest.at(idx_gamma_gate))+frsgate->GetName()),10000,-2e3,stop_short_lifetime_collection);
        h1_fatima_tsci41_energy_gated[idx_gamma_gate]->GetXaxis()->SetTitle("time (ns)");

        
        h1_fatima_energy_promptflash_cut_energy_gated[idx_gamma_gate] = new TH1F(TString(Form("h1_fatima_energy_promptflash_cut_energy_gated_%i_frs_gate_",(int)gamma_energies_of_interest.at(idx_gamma_gate)))+frsgate->GetName(),TString(Form("Coincident gammas gated on E = %i keV, gated FRS on ",(int)gamma_energies_of_interest.at(idx_gamma_gate))+frsgate->GetName()),fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
        h1_fatima_energy_promptflash_cut_energy_gated[idx_gamma_gate]->GetXaxis()->SetTitle("Energy (keV)");



        h1_fatima_twr_sci41_energy_gated[idx_gamma_gate] = new TH1F(TString(Form("h1_fatima_twr_sci41_energy_gated_%i_frs_gate_",(int)gamma_energies_of_interest.at(idx_gamma_gate)))+frsgate->GetName(),TString(Form("WR t(det) - t(sci41) gated on E = %i keV, gated FRS on ",(int)gamma_energies_of_interest.at(idx_gamma_gate))+frsgate->GetName()),10000,long_lifetime_binlow,long_lifetime_binhigh);
        h1_fatima_twr_sci41_energy_gated[idx_gamma_gate]->GetXaxis()->SetTitle("time (ns)");



        h1_fatima_energy_promptflash_cut_long_energy_gated[idx_gamma_gate] = new TH1F(TString(Form("h1_fatima_energy_promptflash_cut_long_energy_gated_%i_frs_gate_",(int)gamma_energies_of_interest.at(idx_gamma_gate)))+frsgate->GetName(),TString(Form("Coincident gammas gated on E = %i keV, gated FRS on ",(int)gamma_energies_of_interest.at(idx_gamma_gate))+frsgate->GetName()),fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
        h1_fatima_energy_promptflash_cut_long_energy_gated[idx_gamma_gate]->GetXaxis()->SetTitle("Energy (keV)");



        h2_fatima_energy_gated_energy_vs_dt_prompt_flash_cut[idx_gamma_gate] = new TH2F(TString(Form("h2_fatima_energy_gated_%i_energy_vs_dt_prompt_flash_cut_frs_gate_",(int)gamma_energies_of_interest.at(idx_gamma_gate)))+frsgate->GetName(),TString(Form("Coincident gamma with start Ey1 = %i keV, Ey2 vs t(Ey1)-t(Ey2), short isomer,  gated FRS on ",(int)gamma_energies_of_interest.at(idx_gamma_gate)))+frsgate->GetName(),ftime_coincidence_nbins,ftime_coincidence_low,ftime_coincidence_high,fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
        h2_fatima_energy_gated_energy_vs_dt_prompt_flash_cut[idx_gamma_gate]->GetXaxis()->SetTitle("time between gammas (ns)");
        h2_fatima_energy_gated_energy_vs_dt_prompt_flash_cut[idx_gamma_gate]->GetYaxis()->SetTitle("energy of start gamma (keV)");


        

        h2_fatima_energy_gated_energy_vs_dt_prompt_flash_cut_long[idx_gamma_gate] = new TH2F(TString(Form("h2_fatima_energy_gated_%i_energy_vs_dt_prompt_flash_cut_long_frs_gate_",(int)gamma_energies_of_interest.at(idx_gamma_gate)))+frsgate->GetName(),TString(Form("Coincident gamma with start Ey1 = %i keV, Ey2 vs t(Ey1)-t(Ey2), long isomer , gated FRS on ",(int)gamma_energies_of_interest.at(idx_gamma_gate)))+frsgate->GetName(),ftime_coincidence_nbins,ftime_coincidence_low,ftime_coincidence_high,fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
        h2_fatima_energy_gated_energy_vs_dt_prompt_flash_cut_long[idx_gamma_gate]->GetXaxis()->SetTitle("time between gammas (ns)");
        h2_fatima_energy_gated_energy_vs_dt_prompt_flash_cut_long[idx_gamma_gate]->GetYaxis()->SetTitle("energy of start gamma (keV)");

        

    }

    return kSUCCESS;
}


void FrsFatimaCorrelationsNearline::Exec(Option_t* option)
{
    if (hitArrayFrs->size() == 0) return;
    positive_PID = false;
    auto const & frshit = hitArrayFrs->at(0);
    
    int64_t wr_t = frshit.Get_wr_t();
    if(wr_t_first_frs_hit == 0) wr_t_first_frs_hit = wr_t;
    double ID_x2 = frshit.Get_ID_x2();
    double ID_y2 = frshit.Get_ID_y2();
    double ID_x4 = frshit.Get_ID_x4();
    double ID_AoQ = frshit.Get_ID_AoQ_s2s4();
    double ID_z = frshit.Get_ID_z41();
    double ID_z2 = frshit.Get_ID_z42();
    double ID_dEdeg = frshit.Get_ID_dEdeg_z41();

    // this must pass all gates given to FrsGate:
    positive_PID = frsgate->PassedGate(ID_z, ID_z2, ID_x2, ID_x4, ID_AoQ, ID_dEdeg);
    if (positive_PID)
    {
        wr_t_last_frs_hit = wr_t;
        frs_rate_implanted ++;
        frs_total_implanted ++;

        h2_frs_Z_vs_AoQ_gated->Fill(ID_AoQ,ID_z);
        h2_frs_Z_vs_Z2_gated->Fill(ID_z,ID_z2);
        h2_frs_x2_vs_AoQ_gated->Fill(ID_AoQ,ID_x2);
        h2_frs_x4_vs_AoQ_gated->Fill(ID_AoQ,ID_x4);

        if (wr_t_last_frs_hit - frs_rate_time > 60e9)
        {
            g_frs_rate->AddPoint((wr_t_last_frs_hit - wr_t_first_frs_hit)/1000000000, frs_rate_implanted/60.0);
            g_frs_total->AddPoint((wr_t_last_frs_hit - wr_t_first_frs_hit)/1000000000, frs_total_implanted);
            frs_rate_time = wr_t_last_frs_hit;
            frs_rate_implanted = 0;
        }
    }else{
        wr_t_last_frs_hit = 0;
    }

    if (fHitFatima && fHitFatima->GetEntriesFast() > 0)
    {
    
        Int_t nHits = fHitFatima->GetEntriesFast();
        
        
        bool sci41_seen = false; // off-spill raw spectra
        int sci41_hit_idx = -1; // sci41's hit index, for getting the time
        int detector_id_sci41 = 0;
        double energy_sci41 = 0;
        double time_sci41 = 0;
        

        //find sci41:
        for (Int_t ihit = 0; ihit < nHits; ihit++){ // find the sci41 hit if it is there.
    
            FatimaTwinpeaksCalData* hit1 = (FatimaTwinpeaksCalData*)fHitFatima->At(ihit);
            if (!hit1) continue;
            int detector_id1 = hit1->Get_detector_id();
            double energy1 = hit1->Get_energy();
            double time1 = hit1->Get_fast_lead_time();
            if (detector_id1 == fatima_configuration->SC41L() /*|| detector_id1 == fatima_configuration->SC41R()*/) {
                
                if (sci41_seen == true) return;

                detector_id_sci41 = hit1->Get_detector_id();
                energy_sci41 = hit1->Get_energy();
                time_sci41 = hit1->Get_fast_lead_time();
                
                sci41_seen = true;
                sci41_hit_idx = ihit;
                break;
            }
        }

        // Spectra with respect to SCI41 - 'short' isomers
        if (nHits >= 2 && sci41_seen && positive_PID){
            for (int ihit2 = 0; ihit2 < nHits; ihit2 ++){
                if (ihit2 == sci41_hit_idx) continue;
                FatimaTwinpeaksCalData* hit2 = (FatimaTwinpeaksCalData*)fHitFatima->At(ihit2);
                if (!hit2) continue;
                int detector_id1 = hit2->Get_detector_id();
                double energy1 = hit2->Get_energy();
                double time1 = hit2->Get_fast_lead_time();

                if (fatima_configuration->IsDetectorAuxilliary(detector_id1)) continue;

                double timediff1 = time1 - time_sci41 - fatima_configuration->GetTimeshiftCoefficient(detector_id1);
                h2_fatima_energy_vs_tsci41->Fill(timediff1 ,energy1);

                for (int ihit3 = 0; ihit3<nHits; ihit3 ++){
                    if (ihit3 == sci41_hit_idx) continue;
                    if (ihit3 == ihit2) continue;
                    FatimaTwinpeaksCalData* hit3 = (FatimaTwinpeaksCalData*)fHitFatima->At(ihit3);
                    if (!hit3) continue;                    
                    int detector_id2 = hit3->Get_detector_id();
                    if (fatima_configuration->IsDetectorAuxilliary(detector_id2)) continue;
                    double energy2 = hit3->Get_energy();
                    double time2 = hit3->Get_fast_lead_time();

                    if (TMath::Abs(time2-fatima_configuration->GetTimeshiftCoefficient(detector_id2)-time1+fatima_configuration->GetTimeshiftCoefficient(detector_id1)) < fatima_coincidence_gate){
                        double timediff2 = time2 - time_sci41 - fatima_configuration->GetTimeshiftCoefficient(detector_id2);

                        h2_fatima_energy_vs_tsci41_mult2->Fill(timediff2,energy2);

                        if ((fatima_configuration->IsInsidePromptFlashCut(timediff2 ,energy2)==true) ) continue;
                        if (!(timediff2 < stop_short_lifetime_collection && timediff2 > - 500)) continue;
                        h1_fatima_energy_promptflash_cut_mult2->Fill(energy2);                        

                    }
                
                }
                

                //after this test, the prompt flash is cut out.
                if ((fatima_configuration->IsInsidePromptFlashCut(timediff1 ,energy1)==true) ) continue;

                
                if (!(timediff1 < stop_short_lifetime_collection && timediff1 > - 2000)) continue;
                
                h1_fatima_energy_promptflash_cut->Fill(energy1);

                for (int idx_gamma_gate = 0; idx_gamma_gate < gamma_energies_of_interest.size(); idx_gamma_gate++){
                    if (!(TMath::Abs(energy1 - gamma_energies_of_interest.at(idx_gamma_gate))<gate_width_gamma_energies_of_interest.at(idx_gamma_gate))) continue;
                    
                    //now energy1 fulfills the energy requirement and is outside prompt flash
                    h1_fatima_tsci41_energy_gated[idx_gamma_gate]->Fill(timediff1);
                }
        
                
                if (nHits >= 3){
                
                for (int ihit3 = 0; ihit3<nHits; ihit3 ++){
                    if (ihit3 == sci41_hit_idx) continue;
                    if (ihit3 == ihit2) continue;

                    FatimaTwinpeaksCalData* hit3 = (FatimaTwinpeaksCalData*)fHitFatima->At(ihit3);
                    if (!hit3) continue;
                    
                    int detector_id2 = hit3->Get_detector_id();
                    if (detector_id1 == detector_id2) continue; //this is likely a good veto before the add-back is done ... 
                    
                    double energy2 = hit3->Get_energy();
                    double time2 = hit3->Get_fast_lead_time();

                    if (fatima_configuration->IsDetectorAuxilliary(detector_id2)) continue;

                    double timediff2 = time2 - time_sci41 - fatima_configuration->GetTimeshiftCoefficient(detector_id2);
                    
                    if ((fatima_configuration->IsInsidePromptFlashCut(timediff2, energy2)==true)) continue;
                    if (!(timediff2 < stop_short_lifetime_collection && timediff2 > - 500)) continue;

                    if (ihit3 > ihit2 && (TMath::Abs(time2-fatima_configuration->GetTimeshiftCoefficient(detector_id2)-time1+fatima_configuration->GetTimeshiftCoefficient(detector_id1)) < fatima_coincidence_gate)) h2_fatima_energy_energy_promptflash_cut->Fill(energy1,energy2); // avoid double filling ... 


                    for (int idx_gamma_gate = 0; idx_gamma_gate < gamma_energies_of_interest.size(); idx_gamma_gate++){
                        if (!(TMath::Abs(energy1 - gamma_energies_of_interest.at(idx_gamma_gate))<gate_width_gamma_energies_of_interest.at(idx_gamma_gate))) continue;
                            // energy1 and energy2 are both in coincidence and outside the promptflash here:
                            if (TMath::Abs(time2-fatima_configuration->GetTimeshiftCoefficient(detector_id2)-time1+fatima_configuration->GetTimeshiftCoefficient(detector_id1)) < fatima_coincidence_gate) h1_fatima_energy_promptflash_cut_energy_gated[idx_gamma_gate]->Fill(energy2);
                            
                            h2_fatima_energy_gated_energy_vs_dt_prompt_flash_cut[idx_gamma_gate]->Fill(time1 - fatima_configuration->GetTimeshiftCoefficient(detector_id1) - time2 + fatima_configuration->GetTimeshiftCoefficient(detector_id2), energy2);
                        }
                    }
                }
            }
        }

        

        if (nHits >= 1 && wr_t_last_frs_hit != 0){
            //long isomer
        for (int ihit1 = 0; ihit1 < nHits; ihit1 ++){

            FatimaTwinpeaksCalData* hit_long1 = (FatimaTwinpeaksCalData*)fHitFatima->At(ihit1);
            if (!hit_long1) continue;
            int detector_id_long = hit_long1->Get_detector_id();
            double energy_long = hit_long1->Get_energy();
            double time_long = hit_long1->Get_fast_lead_time();
            int64_t fat_wr_long = hit_long1->Get_absolute_event_time();

            if (fatima_configuration->IsDetectorAuxilliary(detector_id_long)==true) continue;


            h2_fatima_energy_vs_sci41_wr_long->Fill(fat_wr_long-wr_t_last_frs_hit, energy_long);
            

            // cut the prompt flash on the whiterabbit, roughly, but you are after long isomers ... :)
            if (fat_wr_long - wr_t_last_frs_hit < start_long_lifetime_collection) continue;


            
            if (fat_wr_long - wr_t_last_frs_hit < stop_long_lifetime_collection) h1_fatima_energy_promptflash_cut_long->Fill(energy_long);

                for (int idx_gamma_gate = 0; idx_gamma_gate < gamma_energies_of_interest.size(); idx_gamma_gate++)
                {
                    if (!(TMath::Abs(energy_long - gamma_energies_of_interest.at(idx_gamma_gate))<gate_width_gamma_energies_of_interest.at(idx_gamma_gate))) continue;
                    //now energy1 fulfills the energy requirement and is outside prompt flash
                        
                        h1_fatima_twr_sci41_energy_gated[idx_gamma_gate]->Fill(fat_wr_long-wr_t_last_frs_hit);
                }

                        
                if (nHits >= 2)
                {
                
                for (int ihit2 = 0; ihit2<nHits; ihit2 ++){
                    FatimaTwinpeaksCalData* hit_long2 = (FatimaTwinpeaksCalData*)fHitFatima->At(ihit2);
                    if (!hit_long2) continue;
                    if (ihit1 == ihit2) continue;
                    int detector_id_long2 = hit_long2->Get_detector_id();
                    double energy_long2 = hit_long2->Get_energy();
                    double time_long2 = hit_long2->Get_fast_lead_time();
                    int64_t fat_wr_long2 = hit_long2->Get_absolute_event_time();


                    if (fatima_configuration->IsDetectorAuxilliary(detector_id_long2)) continue;
                    
                    if (fat_wr_long2 - wr_t_last_frs_hit < start_long_lifetime_collection) continue;
                    if (detector_id_long == detector_id_long2) continue; //this is likely a good veto before the add-back is done
                    
                    // check coincidence, this should also make it so that the second hit is outside the prompt flash as well...:

                    //avoid double filling:
                    if (ihit2>ihit1 && (TMath::Abs(time_long2-time_long- fatima_configuration->GetTimeshiftCoefficient(detector_id_long2)- fatima_configuration->GetTimeshiftCoefficient(detector_id_long)) < fatima_coincidence_gate)) h2_fatima_energy_energy_promptflash_cut_long->Fill(energy_long,energy_long2);
                    
                    for (int idx_gamma_gate = 0; idx_gamma_gate < gamma_energies_of_interest.size(); idx_gamma_gate++)
                    {
                        if (!(TMath::Abs(energy_long - gamma_energies_of_interest.at(idx_gamma_gate))<gate_width_gamma_energies_of_interest.at(idx_gamma_gate))) continue;
                        //now energy1 fulfills the energy requirement and is outside prompt flash
                        // energy1 and energy2 are both in coincidence and outside the promptflash here:
                        if (fat_wr_long2 - wr_t_last_frs_hit < stop_long_lifetime_collection && (TMath::Abs(time_long2-time_long- fatima_configuration->GetTimeshiftCoefficient(detector_id_long2)- fatima_configuration->GetTimeshiftCoefficient(detector_id_long)) < fatima_coincidence_gate)) h1_fatima_energy_promptflash_cut_long_energy_gated[idx_gamma_gate]->Fill(energy_long2);

                        h2_fatima_energy_gated_energy_vs_dt_prompt_flash_cut_long[idx_gamma_gate]->Fill(time_long - fatima_configuration->GetTimeshiftCoefficient(detector_id_long) - time_long2 + fatima_configuration->GetTimeshiftCoefficient(detector_id_long2), energy_long2);
                    }
                }
            }   
        }
        }
    }

    fNEvents += 1;
}

void FrsFatimaCorrelationsNearline::FinishEvent()
{
    if (fHitFatima)
    {
        fHitFatima->Clear();
    }
}

void FrsFatimaCorrelationsNearline::FinishTask()
{
    if (fNEvents == 0)
    {
        sfsLOG(warning, "No events processed, no histograms written.");
        return;
    }
    
    if (found_dir_corr == false)
    {
        TDirectory* tmp = gDirectory;
        FairRootManager::Instance()->GetOutFile()->cd();
        dir_corr->Write();
        gDirectory = tmp;
        sfsLOG(info, "FRS-FATIMA histograms written to file.");

    }
}

ClassImp(FrsFatimaCorrelationsNearline)
