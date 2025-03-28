#ifndef FatimaVmeReader_H
#define FatimaVmeReader_H

#include "sfsReader.h"
#include "FatimaVmeData.h"
#include <unordered_map>
#include <map>
#include <set>

#include <Rtypes.h>
#include <vector>
#include <iostream>
#include <vector>

extern "C"
{
    #include "ext_h101_fatimavme.h"
}

class TClonesArray;
class FatimaVmeData;
// class vector;

struct EXT_STR_h101_fatimavme_t;
typedef struct EXT_STR_h101_fatimavme_t EXT_STR_h101_fatimavme;
typedef struct EXT_STR_h101_fatimavme_onion_t EXT_STR_h101_fatimavme_onion;
class ext_data_struct_info;

// struct
// jesus fatima reader got weird

class FatimaVmeReader : public sfsReader
{
    public:
        FatimaVmeReader(EXT_STR_h101_fatimavme_onion*, size_t);

        virtual ~FatimaVmeReader();

        virtual Bool_t Init(ext_data_struct_info*) override;

        virtual Bool_t Read() override;

        virtual void Reset() override;

        void SetOnline(Bool_t option) { fOnline = option; }
        //void Set_Allocation(TString& filepath);

        std::vector<int> Get_Channels(Int_t channel_mask);

        // FT Calib?

        // GetFT?

        // misc...........


    private:

        Int_t fNEvent = 0;
        Bool_t fOnline;

        EXT_STR_h101_fatimavme_onion* fData;
        size_t fOffset;

        TClonesArray* fArray;
        std::vector<FatimaVmeQDCItem>* qdcArray;
        std::vector<FatimaVmeTDCItem>* tdcArray;

        std::map<std::pair<int, int>, int> dets_qdc;
        std::map<std::pair<int, int>, int> dets_tdc;
        //std::set<int> extra_signals = {TM_U, TM_D, SC41L_A, SC41R_A, SC41L_D, SC41R_D};
        int num_qdc_boards;
        int num_tdc_boards;

        std::vector<uint32_t> qdc_detectors = {};
        std::vector<uint32_t> QDC_time_coarse = {};
        std::vector<uint64_t> QDC_time_fine = {};
        std::vector<uint32_t> QLong_raw = {};
        std::vector<uint32_t> QShort_raw = {};

        std::vector<uint32_t> tdc_detectors = {};
        std::vector<uint32_t> v1290_data = {};
        std::vector<uint32_t> v1290_lot = {};   

        uint64_t wr_t;


    public:
        ClassDefOverride(FatimaVmeReader, 1);

};


#endif