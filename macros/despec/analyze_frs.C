#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TH2F.h>
#include <iostream>
#include <vector>

#include "FrsHitData.h" // Ensure this header is correctly included

void analyze_frs()
{
    // Open the input ROOT file
    TFile* inFile = TFile::Open("test_tree.root");
    if (!inFile || inFile->IsZombie()) {
        std::cerr << "Error: Cannot open file test_tree.root" << std::endl;
        return;
    }

    // Retrieve the tree named "cbmsim"
    TTree* tree = dynamic_cast<TTree*>(inFile->Get("cbmsim"));
    if (!tree) {
        std::cerr << "Error: TTree 'cbmsim' not found in file" << std::endl;
        inFile->Close();
        return;
    }

    // The branch "FrsHitData" is a std::vector<FrsHitItem>
    std::vector<FrsHitItem>* hits = nullptr;
    tree->SetBranchAddress("FrsHitData", &hits);

    // Create histograms for isotope identification
    TH1F* hAoQ = new TH1F("hAoQ", "AoQ from S2S4; AoQ_{s2s4}; Counts", 200, 1.5, 3.0);
    TH1F* hZ = new TH1F("hZ", "Z from MUSIC; Z; Counts", 100, 0, 50);
    TH2F* hZvsAoQ = new TH2F("hZvsAoQ", "Z vs AoQ; AoQ_{s2s4}; Z", 200, 2.45, 2.75, 100, 16, 38);

    // Loop over entries in the tree
    Long64_t nentries = tree->GetEntries();
    std::cout << "Total entries in tree: " << nentries << std::endl;

    for (Long64_t i = 0; i < nentries; i++) {
    	// Print progress every 100k events
    	if (i % 100000 == 0) {
            std::cout << "Processing event " << i << " / " << nentries << std::endl;
    	}

        tree->GetEntry(i);

        // Check if hits vector is valid
        if (!hits) continue;

        // Loop over all FrsHitItem objects in this event
        for (auto &hit : *hits) {
            Float_t aoq = hit.Get_ID_AoQ_s2s4();  // Mass-to-charge ratio
            Float_t z = hit.Get_ID_z41();         // Atomic number from MUSIC detector
            Float_t tof = hit.Get_sci_tof_21_41(); // Time-of-flight between S2 and S4

            // Ensure values are within reasonable ranges
            if (aoq > 0) hAoQ->Fill(aoq);
            if (z > 0) hZ->Fill(z);
            if (aoq > 0 && z > 0) hZvsAoQ->Fill(aoq, z);
        }
    }

    // Save the histograms to an output ROOT file
    TFile* outFile = TFile::Open("frs_analysis.root", "RECREATE");
    hAoQ->Write();
    hZ->Write();
    hZvsAoQ->Write();
    outFile->Close();

    std::cout << "Analysis complete! Results saved to frs_analysis.root" << std::endl;

    inFile->Close();
}
