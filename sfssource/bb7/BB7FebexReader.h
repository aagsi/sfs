#ifndef BB7FebexReader_H
#define BB7FebexReader_H

#include "BB7FebexData.h"
#include "sfsReader.h"

#include <Rtypes.h>
#include <vector>

extern "C"
{
    #include "ext_h101_bbfebex.h"
}

class TClonesArray;

struct EXT_STR_h101_bbfebex_t;
typedef struct EXT_STR_h101_bbfebex_t EXT_STR_h101_bbfebex;
typedef struct EXT_STR_h101_bbfebex_onion_t EXT_STR_h101_bbfebex_onion;
class ext_data_struct_info;

class BB7FebexReader : public sfsReader
{
    public:
        BB7FebexReader(EXT_STR_h101_bbfebex_onion*, size_t);

        virtual ~BB7FebexReader();

        virtual Bool_t Init(ext_data_struct_info*) override;

        virtual Bool_t Read() override;

        virtual void Reset() override;

        void SetOnline(Bool_t option) { fOnline = option; }

    private:
        Int_t fNEvent;

        EXT_STR_h101_bbfebex_onion* fData;

        size_t fOffset;

        Bool_t fOnline;
        
        TClonesArray* fArray;

        const int NBoards = 5; // maximum (2 x BB7 boards which don't exist right now?)

        int32_t energy;
        int64_t wr_t_first = 0;
        int64_t wr_t_second = 0;

        std::vector<BB7FebexItem>* bb7array;
        std::vector<BB7EmptyItem>* bb7empty;

        Int_t nReads = 0;
        Int_t n_zero_f0_0 = 0;
        Int_t n_zero_f0_1 = 0;

    
    public:
        ClassDefOverride(BB7FebexReader, 1);


};

#endif