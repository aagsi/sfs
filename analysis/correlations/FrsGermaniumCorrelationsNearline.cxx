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
 *                        J.E.L. Larsson, C.E. Jones                          *
 *                               17.12.24                                     *
 ******************************************************************************/

// FairRoot
#include "FairLogger.h"
#include "FairRootManager.h"
#include "FairRunAna.h"
#include "FairRunOnline.h"
#include "FairRuntimeDb.h"

// sfs
#include "FrsGermaniumCorrelationsNearline.h"
#include "EventHeader.h"
#include "GermaniumFebexData.h"
#include "GermaniumCalData.h"
#include "FrsGate.h"
#include "FrsHitData.h"
#include "TGermaniumConfiguration.h"

#include "AnalysisTools.h"
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

FrsGermaniumCorrelationsNearline::FrsGermaniumCorrelationsNearline() : FrsGermaniumCorrelationsNearline("FrsGermaniumCorrelationsNearline")
{
    germanium_configuration = TGermaniumConfiguration::GetInstance();
    frs_configuration = TFrsConfiguration::GetInstance();

}

FrsGermaniumCorrelationsNearline::FrsGermaniumCorrelationsNearline(FrsGate * fg) : FrsGermaniumCorrelationsNearline("FrsGermaniumCorrelationsNearline")
{
    germanium_configuration = TGermaniumConfiguration::GetInstance();
    frsgate = fg;
    frs_configuration = TFrsConfiguration::GetInstance();
}

FrsGermaniumCorrelationsNearline::FrsGermaniumCorrelationsNearline(const TString& name, Int_t verbose)
    : FairTask(name, verbose)
    , fHitGe(NULL)
    , hitArrayFrs(nullptr)
    , fNEvents(0)
    , header(nullptr)
{    
    germanium_configuration = TGermaniumConfiguration::GetInstance();
}

FrsGermaniumCorrelationsNearline::~FrsGermaniumCorrelationsNearline()
{
    sfsLOG(info, "");
    if (fHitGe)
        delete fHitGe;
}


InitStatus FrsGermaniumCorrelationsNearline::Init()
{

    // number of crystals, number of dets 

    sfsLOG(info, "");
    FairRootManager* mgr = FairRootManager::Instance();
    sfsLOG_IF(fatal, NULL == mgr, "FairRootManager not found");

    FairRunAna* run = FairRunAna::Instance();

    header = mgr->InitObjectAs<decltype(header)>("EventHeader.");
    sfsLOG_IF(error, !header, "Branch EventHeader. not found!");

    fHitGe = (TClonesArray*)mgr->GetObject("GermaniumCalData");
    sfsLOG_IF(fatal, !fHitGe, "Branch GermaniumCalData not found!");
    hitArrayFrs = mgr->InitObjectAs<decltype(hitArrayFrs)>("FrsHitData");
    sfsLOG_IF(fatal, !hitArrayFrs, "Branch FrsHitData not found!");
    multihitArray = mgr->InitObjectAs<decltype(multihitArray)>("FrsMultiHitData");
    sfsLOG_IF(fatal, !multihitArray, "Branch FrsMultiHitData not found!");


    dir_corr = (TDirectory*)mgr->GetObject("Correlations");
    if (dir_corr == nullptr) 
    {
        LOG(info) << "Creating Correlations Directory";
        FairRootManager::Instance()->GetOutFile()->cd();
        dir_corr = gDirectory->mkdir("Correlations");
        mgr->Register("Correlations", "Correlations Directory", dir_corr, false); // allow other tasks to find this
        found_dir_corr = false;
    }

    sfsLOG(info, "Germanium gamma-gamma coincidence window: " + TString(std::to_string(germanium_coincidence_gate*2) + " ns"));

    TString dirname = "DEGAS-FRS_gated" + frsgate->GetName();
    dir_germanium = dir_corr->mkdir(dirname);

    dir_germanium->cd();

    //Implant rate
    g_frs_rate = new TGraph();
    g_frs_rate->SetName(TString("g_frs_germanium_rate_monitor_gated_")+frsgate->GetName());
    g_frs_rate->SetTitle(TString("FRS identified ions per second, avg 60 secs"));
    g_frs_rate->GetXaxis()->SetTitle("seconds");

    g_frs_total = new TGraph();
    g_frs_total->SetName(TString("g_frs_germanium_total_monitor_gated_")+frsgate->GetName());
    g_frs_total->SetTitle(TString("FRS identified ions in total"));
    g_frs_total->GetXaxis()->SetTitle("seconds");

    h2_frs_Z_vs_AoQ_gated = new TH2F(TString("h2_frs_germanium_Z_vs_AoQ_gated_")+frsgate->GetName(),TString("Z vs AoQ plot gated on FRS ")+frsgate->GetName(),1000,frs_configuration->fMin_AoQ,frs_configuration->fMax_AoQ,1000,frs_configuration->fMin_Z,frs_configuration->fMax_Z);
    h2_frs_Z_vs_AoQ_gated->GetXaxis()->SetTitle("A/Q");
    h2_frs_Z_vs_AoQ_gated->GetYaxis()->SetTitle("Z");

    h2_frs_Z_vs_Z2_gated = new TH2F(TString("h2_frs_germanium_Z_vs_Z2_gated_")+frsgate->GetName(),TString("Z1 vs Z2 plot gated on FRS ")+frsgate->GetName(),1000,frs_configuration->fMin_Z,frs_configuration->fMax_Z,1000,frs_configuration->fMin_Z,frs_configuration->fMax_Z);
    h2_frs_Z_vs_Z2_gated->GetXaxis()->SetTitle("Z1");
    h2_frs_Z_vs_Z2_gated->GetYaxis()->SetTitle("Z2");



    h2_frs_x2_vs_AoQ_gated = new TH2F(TString("h2_frs_germanium_x2_vs_AoQ_gated_")+frsgate->GetName(),TString("x2 vs AoQ plot gated on FRS ")+frsgate->GetName(),1000,frs_configuration->fMin_AoQ,frs_configuration->fMax_AoQ,1000,frs_configuration->fMin_x2,frs_configuration->fMax_x2);
    h2_frs_x2_vs_AoQ_gated->GetYaxis()->SetTitle("x2");
    h2_frs_x2_vs_AoQ_gated->GetXaxis()->SetTitle("A/Q");


    h2_frs_x4_vs_AoQ_gated = new TH2F(TString("h2_frs_germanium_x4_vs_AoQ_gated_")+frsgate->GetName(),TString("x4 vs AoQ plot gated on FRS ")+frsgate->GetName(),1000,frs_configuration->fMin_AoQ,frs_configuration->fMax_AoQ,1000,frs_configuration->fMin_x4,frs_configuration->fMax_x4);
    h2_frs_x4_vs_AoQ_gated->GetXaxis()->SetTitle("A/Q");
    h2_frs_x4_vs_AoQ_gated->GetYaxis()->SetTitle("x4");

    // this is the "bad" one
    h2_germanium_energy_vs_tsci41 = new TH2F(TString("h2_germanium_energy_vs_tsci41_frs_gate_"+frsgate->GetName()),TString("Germanium energies vs t(det) - t(sci41), short lifetime,  gated FRS on "+frsgate->GetName()),10000,-2000,stop_short_lifetime_collection,fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
    h2_germanium_energy_vs_tsci41->GetXaxis()->SetTitle("time difference (ns)");
    h2_germanium_energy_vs_tsci41->GetYaxis()->SetTitle("energy (keV)");

    
    h1_germanium_energy_promptflash_cut = new TH1F(TString("h1_germanium_energy_promptflash_cut_frs_gate_"+frsgate->GetName()),TString("Germanium energy, prompt flash cut out, short lifetime, gated FRS on "+frsgate->GetName()),fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
    h1_germanium_energy_promptflash_cut->GetXaxis()->SetTitle("energy (keV)");


    
    h2_germanium_energy_energy_promptflash_cut = new TH2F(TString("h2_germanium_energy_energy_promptflash_cut_frs_gate_"+frsgate->GetName()),TString(Form("Germanium energy vs energy, |t(det1)-t(det2)|<%i ns, prompt flash cut out, short lifetime, gated FRS on ",germanium_coincidence_gate)+frsgate->GetName()),fenergy_nbins,fenergy_bin_low,fenergy_bin_high,fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
    h2_germanium_energy_energy_promptflash_cut->GetXaxis()->SetTitle("energy (keV)");
    h2_germanium_energy_energy_promptflash_cut->GetYaxis()->SetTitle("energy (keV)");



    // this is the "good" one
    h2_germanium_energy_vs_sci41_wr_long = new TH2F(TString("h2_germanium_energy_vs_sci41_wr_long_frs_gate_"+frsgate->GetName()),TString("Germanium energies vs t(det,wr) - t(sci41,wr) long lifetime, gated FRS on "+frsgate->GetName()),10000,long_lifetime_binlow,long_lifetime_binhigh,fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
    h2_germanium_energy_vs_sci41_wr_long->GetXaxis()->SetTitle("time difference (ns)");
    h2_germanium_energy_vs_sci41_wr_long->GetYaxis()->SetTitle("energy (keV)");

    
    h1_germanium_energy_promptflash_cut_long = new TH1F(TString("h1_germanium_energy_promptflash_cut_long_frs_gate_"+frsgate->GetName()),TString("Germanium energy, prompt flash cut out, long lifetime, gated FRS on "+frsgate->GetName()),fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
    h1_germanium_energy_promptflash_cut_long->GetXaxis()->SetTitle("energy (keV)");

    h2_germanium_energy_energy_promptflash_cut_long = new TH2F(TString("h2_germanium_energy_energy_promptflash_cut_long_frs_gate_"+frsgate->GetName()),TString(Form("Germanium energy vs energy, |t(det1)-t(det2)|<%i ns, prompt flash cut out, long lifetime, gated FRS on ",germanium_coincidence_gate)+frsgate->GetName()),fenergy_nbins,fenergy_bin_low,fenergy_bin_high,fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
    h2_germanium_energy_energy_promptflash_cut_long->GetXaxis()->SetTitle("energy (keV)");
    h2_germanium_energy_energy_promptflash_cut_long->GetYaxis()->SetTitle("energy (keV)");
    

    //energy-gated spectra:
    folder_energy_gated = new TDirectory*[gamma_energies_of_interest.size()];

    h1_germanium_tsci41_energy_gated = new TH1F*[gamma_energies_of_interest.size()];
        
    h1_germanium_energy_promptflash_cut_energy_gated = new TH1F*[gamma_energies_of_interest.size()];
        
    //long:
    h1_germanium_energy_promptflash_cut_long_energy_gated = new TH1F*[gamma_energies_of_interest.size()];

    h1_germanium_twr_sci41_energy_gated = new TH1F*[gamma_energies_of_interest.size()];
        
    
    for (int idx_gamma_gate = 0; idx_gamma_gate < gamma_energies_of_interest.size(); idx_gamma_gate++){
        folder_energy_gated[idx_gamma_gate] = dir_germanium->mkdir(Form("Energy gated coincidence spectra, Eg = %i",(int)gamma_energies_of_interest.at(idx_gamma_gate)));
        folder_energy_gated[idx_gamma_gate]->cd();

        h1_germanium_tsci41_energy_gated[idx_gamma_gate] = new TH1F(TString(Form("h1_germanium_tsci41_energy_gated_%i_frs_gate_",(int)gamma_energies_of_interest.at(idx_gamma_gate)))+frsgate->GetName(),TString(Form("t(det) - t(sci41) gated on E = %i keV, gated FRS on ",(int)gamma_energies_of_interest.at(idx_gamma_gate))+frsgate->GetName()),10000,-2e3,stop_short_lifetime_collection);
        h1_germanium_tsci41_energy_gated[idx_gamma_gate]->GetXaxis()->SetTitle("time (ns)");

        
        h1_germanium_energy_promptflash_cut_energy_gated[idx_gamma_gate] = new TH1F(TString(Form("h1_germanium_energy_promptflash_cut_energy_gated_%i_frs_gate_",(int)gamma_energies_of_interest.at(idx_gamma_gate)))+frsgate->GetName(),TString(Form("Coincident gammas gated on E = %i keV, gated FRS on ",(int)gamma_energies_of_interest.at(idx_gamma_gate))+frsgate->GetName()),fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
        h1_germanium_energy_promptflash_cut_energy_gated[idx_gamma_gate]->GetXaxis()->SetTitle("Energy (keV)");

        h1_germanium_twr_sci41_energy_gated[idx_gamma_gate] = new TH1F(TString(Form("h1_germanium_twr_sci41_energy_gated_%i_frs_gate_",(int)gamma_energies_of_interest.at(idx_gamma_gate)))+frsgate->GetName(),TString(Form("WR t(det) - t(sci41) gated on E = %i keV, gated FRS on ",(int)gamma_energies_of_interest.at(idx_gamma_gate))+frsgate->GetName()),10000,long_lifetime_binlow,long_lifetime_binhigh);
        h1_germanium_twr_sci41_energy_gated[idx_gamma_gate]->GetXaxis()->SetTitle("time (ns)");

        h1_germanium_energy_promptflash_cut_long_energy_gated[idx_gamma_gate] = new TH1F(TString(Form("h1_germanium_energy_promptflash_cut_long_energy_gated_%i_frs_gate_",(int)gamma_energies_of_interest.at(idx_gamma_gate)))+frsgate->GetName(),TString(Form("Coincident gammas gated on E = %i keV, gated FRS on ",(int)gamma_energies_of_interest.at(idx_gamma_gate))+frsgate->GetName()),fenergy_nbins,fenergy_bin_low,fenergy_bin_high);
        h1_germanium_energy_promptflash_cut_long_energy_gated[idx_gamma_gate]->GetXaxis()->SetTitle("Energy (keV)");

    }

    crystals_to_plot.clear();
    std::map<std::pair<int,int>,std::pair<int,int>> gmap = germanium_configuration->Mapping();

    for (auto it_mapping = gmap.begin(); it_mapping != gmap.end(); ++it_mapping){
        if (it_mapping->second.first >= 0) crystals_to_plot.emplace_back(std::pair<int,int>(it_mapping->second.first,it_mapping->second.second));
    }

    number_of_detectors_to_plot = crystals_to_plot.size();

    detector_labels = new char*[number_of_detectors_to_plot];
    h1_germanium_hitpattern_post6us = MakeTH1(dir_germanium, "I", "h1_germanium_hitpattern_post6us","Hit pattern of DEGAS",number_of_detectors_to_plot,0,number_of_detectors_to_plot, "Crystal", kRed-3, kBlack);
    h1_germanium_hitpattern_post6us->GetXaxis()->SetAlphanumeric();
    for (int ihist = 0; ihist < number_of_detectors_to_plot; ihist++)
    {
        detector_labels[ihist] = Form("%d%c",crystals_to_plot.at(ihist).first,(char)(crystals_to_plot.at(ihist).second+65));
        h1_germanium_hitpattern_post6us->GetXaxis()->SetBinLabel(ihist+1,detector_labels[ihist]);
    }    
    h1_germanium_hitpattern_post6us->GetXaxis()->LabelsOption("a");
    h1_germanium_hitpattern_post6us->SetStats(0);
    

    return kSUCCESS;
}


void FrsGermaniumCorrelationsNearline::Exec(Option_t* option)
{
    // 2025:
    // For 2025, we will use MHTDC, since TAC has fallen completely out of favour
    // We will update for retroactive to use a switch to decide either TAC, MHTDC or both
    // But this will come later...
    if (hitArrayFrs->size() == 0) return; // Avoid processing for nothing
    auto const & frshit = hitArrayFrs->at(0);
    
    positive_PID = false;

    int64_t wr_t = frshit.Get_wr_t(); // Until next update, wr_t not set in MHTDC vector
    if(wr_t_first_frs_hit == 0) wr_t_first_frs_hit = wr_t;
    
    ID_x2 = frshit.Get_ID_x2(); // positions are not MH (well, only since we "always use TPC", but actually we could use SC)
    ID_y2 = frshit.Get_ID_y2();
    ID_x4 = frshit.Get_ID_x4();

    if (use_tac)
    {
        ID_AoQ_s2s4 = frshit.Get_ID_AoQ_s2s4();
        ID_z41 = frshit.Get_ID_z41();
        ID_z42 = frshit.Get_ID_z42();
        ID_dEdegZ41 = frshit.Get_ID_dEdeg_z41();

    }
    else if (!use_tac || use_mhtdc) // change later
    {   
        if (multihitArray->size() == 0) return; // both are empty, nothing to process
        auto const & multihitItem = multihitArray->at(0);
        std::vector<Float_t> AoQ_s2s4_mhtdc = multihitItem.Get_ID_AoQ_s2s4_mhtdc();
        std::vector<Float_t> z41_mhtdc = multihitItem.Get_ID_z41_mhtdc();
        std::vector<Float_t> z42_mhtdc = multihitItem.Get_ID_z42_mhtdc();
        std::vector<Float_t> dEdeg_z41_mhtdc = multihitItem.Get_ID_dEdeg_z41_mhtdc();

        // For now we just take first hit, not really sure how to check PID with multihits honestly
        if (AoQ_s2s4_mhtdc.size() > 0)
        {
            ID_AoQ_s2s4 = AoQ_s2s4_mhtdc.at(0);
            ID_z41 = z41_mhtdc.at(0);
            ID_z42 = z42_mhtdc.at(0);
            ID_dEdegZ41 = dEdeg_z41_mhtdc.at(0);
        }
    }

    // Well we can do something more strict but for now ZvsAoQ is fine
    positive_PID = frsgate->Passed_ZvsAoQ(ID_z41,ID_AoQ_s2s4);
    // positive_PID = frsgate->PassedGate(ID_z, ID_z2, ID_x2, ID_x4, ID_AoQ, ID_dEdeg);

    if (positive_PID)
    {
        wr_t_last_frs_hit = wr_t;
        frs_rate_implanted++;
        frs_total_implanted++;

        h2_frs_Z_vs_AoQ_gated->Fill(ID_AoQ_s2s4,ID_z41);
        h2_frs_Z_vs_Z2_gated->Fill(ID_z41,ID_z42);
        h2_frs_x2_vs_AoQ_gated->Fill(ID_AoQ_s2s4,ID_x2);
        h2_frs_x4_vs_AoQ_gated->Fill(ID_AoQ_s2s4,ID_x4);

        if (wr_t_last_frs_hit - frs_rate_time > 60e9)
        {
            g_frs_rate->AddPoint((wr_t_last_frs_hit - wr_t_first_frs_hit)/1000000000, frs_rate_implanted  /60.0);
            g_frs_total->AddPoint((wr_t_last_frs_hit - wr_t_first_frs_hit)/1000000000, frs_total_implanted);
            frs_rate_time = wr_t_last_frs_hit;
            frs_rate_implanted = 0;
        }
    }
    else wr_t_last_frs_hit = 0;

    if (fHitGe && fHitGe->GetEntriesFast() > 0)
    {
    
        Int_t nHits = fHitGe->GetEntriesFast();
        
        
        bool sci41_seen = false; // off-spill raw spectra
        int sci41_hit_idx = -1; // sci41's hit index, for getting the time
        int detector_id_sci41 = 0;
        int crystal_id_sci41 = 0;
        double energy_sci41 = 0;
        double time_sci41 = 0;
        

        //find sci41:
        for (Int_t ihit = 0; ihit < nHits; ihit++){ // find the sci41 hit if it is there.
    
            GermaniumCalData* hit1 = (GermaniumCalData*)fHitGe->At(ihit);
            if (!hit1) continue;
            int detector_id1 = hit1->Get_detector_id();
            int crystal_id1 = hit1->Get_crystal_id();
            double energy1 = hit1->Get_channel_energy();
            double time1 = hit1->Get_channel_trigger_time();

            if (detector_id1 == germanium_configuration->SC41L() /*|| detector_id1 == germanium_configuration->SC41R()*/) {
                
                if (sci41_seen == true) return;
                
                detector_id_sci41 = hit1->Get_detector_id();
                crystal_id_sci41 = hit1->Get_crystal_id();
                energy_sci41 = hit1->Get_channel_energy();
                time_sci41 = hit1->Get_channel_trigger_time();
                
                sci41_seen = true;
                sci41_hit_idx = ihit;
                break;
            }
        }

        // Spectra with respect to SCI41 - 'short' isomers
        if (nHits >= 2 && sci41_seen && positive_PID){
            for (int ihit2 = 0; ihit2 < nHits; ihit2 ++){
                if (ihit2 == sci41_hit_idx) continue;
                GermaniumCalData* hit2 = (GermaniumCalData*)fHitGe->At(ihit2);
                if (!hit2) continue;
                int detector_id1 = hit2->Get_detector_id();
                int crystal_id1 = hit2->Get_crystal_id();
                double energy1 = hit2->Get_channel_energy();
                double time1 = hit2->Get_channel_trigger_time();

                if (germanium_configuration->IsDetectorAuxilliary(detector_id1)) continue;

                double timediff1 = time1 - time_sci41 - germanium_configuration->GetTimeshiftCoefficient(detector_id1,crystal_id1);
                
                h2_germanium_energy_vs_tsci41->Fill(timediff1 ,energy1);

                int crystal_index1 = std::distance(crystals_to_plot.begin(), std::find(crystals_to_plot.begin(),crystals_to_plot.end(),std::pair<int,int>(detector_id1,crystal_id1)));
                if (timediff1 > 6000) h1_germanium_hitpattern_post6us->Fill(detector_labels[crystal_index1],1);

                //after this test, the prompt flash is cut out.
                if ((germanium_configuration->IsInsidePromptFlashCut(timediff1 ,energy1)==true) ) continue;
                if ((timediff1 < -400 || timediff1 > stop_short_lifetime_collection)) continue;
                
                h1_germanium_energy_promptflash_cut->Fill(energy1);

                for (int idx_gamma_gate = 0; idx_gamma_gate < gamma_energies_of_interest.size(); idx_gamma_gate++){
                    if (!(TMath::Abs(energy1 - gamma_energies_of_interest.at(idx_gamma_gate))<gate_width_gamma_energies_of_interest.at(idx_gamma_gate))) continue;
                    
                    //now energy1 fulfills the energy requirement and is outside prompt flash
                    h1_germanium_tsci41_energy_gated[idx_gamma_gate]->Fill(timediff1);
                }
        
                
                if (nHits >= 3){
                
                for (int ihit3 = 0; ihit3<nHits; ihit3 ++){
                    if (ihit3 == sci41_hit_idx) continue;
                    if (ihit3 == ihit2) continue;

                    GermaniumCalData* hit3 = (GermaniumCalData*)fHitGe->At(ihit3);
                    if (!hit3) continue;
                    
                    int detector_id2 = hit3->Get_detector_id();
                    if (detector_id1 == detector_id2) continue; //this is likely a good veto before the add-back is done ... 
                    
                    int crystal_id2 = hit3->Get_crystal_id();
                    double energy2 = hit3->Get_channel_energy();
                    double time2 = hit3->Get_channel_trigger_time();

                    if (germanium_configuration->IsDetectorAuxilliary(detector_id2)) continue;
                    if (TMath::Abs(time2-time1) > germanium_coincidence_gate) continue;

                    double timediff2 = time2 - time_sci41 - germanium_configuration->GetTimeshiftCoefficient(detector_id2,crystal_id2);
                    
                    if ((germanium_configuration->IsInsidePromptFlashCut(timediff2, energy2)==true)) continue;
                    if ((timediff2 < -400 || timediff2 > stop_short_lifetime_collection)) continue;

                    if (ihit3 > ihit2) h2_germanium_energy_energy_promptflash_cut->Fill(energy1,energy2); // avoid double filling ... 


                    for (int idx_gamma_gate = 0; idx_gamma_gate < gamma_energies_of_interest.size(); idx_gamma_gate++){
                        if (!(TMath::Abs(energy1 - gamma_energies_of_interest.at(idx_gamma_gate))<gate_width_gamma_energies_of_interest.at(idx_gamma_gate))) continue;
                            // energy1 and energy2 are both in coincidence and outside the promptflash here:
                            h1_germanium_energy_promptflash_cut_energy_gated[idx_gamma_gate]->Fill(energy2);
                        }
                    }
                }
            }
        }

        
        // ok "wr_t_last_frs_hit == 0" means !positivePID
        // this is not very clear.
        if (nHits >= 1 && wr_t_last_frs_hit != 0){
            //long isomer
        for (int ihit1 = 0; ihit1 < nHits; ihit1 ++){

            GermaniumCalData* hit_long1 = (GermaniumCalData*)fHitGe->At(ihit1);
            if (!hit_long1) continue;
            int detector_id_long = hit_long1->Get_detector_id();
            int crystal_id_long = hit_long1->Get_crystal_id();
            double energy_long = hit_long1->Get_channel_energy();
            double time_long = hit_long1->Get_channel_trigger_time();
            int64_t ge_wr_long = hit_long1->Get_absolute_event_time();

            if (germanium_configuration->IsDetectorAuxilliary(detector_id_long)==true) continue;

            // this is the "good" one
            h2_germanium_energy_vs_sci41_wr_long->Fill(ge_wr_long-wr_t_last_frs_hit, energy_long);
            

            // cut the prompt flash on the whiterabbit, roughly, but you are after long isomers ... :)
            if (ge_wr_long - wr_t_last_frs_hit < start_long_lifetime_collection) continue;


            
            if (ge_wr_long - wr_t_last_frs_hit < stop_long_lifetime_collection) h1_germanium_energy_promptflash_cut_long->Fill(energy_long);

                for (int idx_gamma_gate = 0; idx_gamma_gate < gamma_energies_of_interest.size(); idx_gamma_gate++)
                {
                    if (!(TMath::Abs(energy_long - gamma_energies_of_interest.at(idx_gamma_gate))<gate_width_gamma_energies_of_interest.at(idx_gamma_gate))) continue;
                    //now energy1 fulfills the energy requirement and is outside prompt flash
                        
                        h1_germanium_twr_sci41_energy_gated[idx_gamma_gate]->Fill(ge_wr_long-wr_t_last_frs_hit);
                }

                        
                if (nHits >= 2)
                {
                
                for (int ihit2 = 0; ihit2<nHits; ihit2 ++){
                    GermaniumCalData* hit_long2 = (GermaniumCalData*)fHitGe->At(ihit2);
                    if (!hit_long2) continue;
                    if (ihit1 == ihit2) continue;
                    int detector_id_long2 = hit_long2->Get_detector_id();
                    int crystal_id_long2 = hit_long2->Get_crystal_id();
                    double energy_long2 = hit_long2->Get_channel_energy();
                    double time_long2 = hit_long2->Get_channel_trigger_time();
                    int64_t ge_wr_long2 = hit_long2->Get_absolute_event_time();


                    if (germanium_configuration->IsDetectorAuxilliary(detector_id_long2)) continue;
                    
                    if (ge_wr_long2 - wr_t_last_frs_hit < start_long_lifetime_collection) continue;
                    if (detector_id_long == detector_id_long2) continue; //this is likely a good veto before the add-back is done
                    
                    // check coincidence, this should also make it so that the second hit is outside the prompt flash as well...:
                    if (TMath::Abs(time_long2-time_long- germanium_configuration->GetTimeshiftCoefficient(detector_id_long2,crystal_id_long2)- germanium_configuration->GetTimeshiftCoefficient(detector_id_long,crystal_id_long)) > germanium_coincidence_gate) continue; 

                    //avoid double filling:
                    if (ihit2>ihit1) h2_germanium_energy_energy_promptflash_cut_long->Fill(energy_long,energy_long2);
                    
                    for (int idx_gamma_gate = 0; idx_gamma_gate < gamma_energies_of_interest.size(); idx_gamma_gate++)
                    {
                        if (!(TMath::Abs(energy_long - gamma_energies_of_interest.at(idx_gamma_gate))<gate_width_gamma_energies_of_interest.at(idx_gamma_gate))) continue;
                        //now energy1 fulfills the energy requirement and is outside prompt flash
                        // energy1 and energy2 are both in coincidence and outside the promptflash here:
                        if (ge_wr_long2 - wr_t_last_frs_hit < stop_long_lifetime_collection) h1_germanium_energy_promptflash_cut_long_energy_gated[idx_gamma_gate]->Fill(energy_long2);
                    }
                }
            }   
        }
        }
    }

    fNEvents += 1;
}

void FrsGermaniumCorrelationsNearline::FinishEvent()
{
    if (fHitGe)
    {
        fHitGe->Clear();
    }
}

void FrsGermaniumCorrelationsNearline::FinishTask()
{
    if (fNEvents == 0)
    {
        sfsLOG(warning, "No events processed, no histograms written.");
        return;
    }
    
    TDirectory* tmp = gDirectory;
    FairRootManager::Instance()->GetOutFile()->cd();
    dir_germanium->Write();
    gDirectory = tmp;
    sfsLOG(info, "FRS-DEGAS histograms written to file.");
}

ClassImp(FrsGermaniumCorrelationsNearline)
