#ifndef BeamMonitorReader_H
#define BeamMonitorReader_H

#include "sfsReader.h"
#include "BeamMonitorData.h"

#include <Rtypes.h>
#include <vector>

extern "C"
{
    #include "ext_h101_beammonitor.h"
}

class TClonesArray;

struct EXT_STR_h101_beammonitor_t;
typedef struct EXT_STR_h101_beammonitor_t EXT_STR_h101_beammonitor;
typedef struct EXT_STR_h101_beammonitor_onion_t EXT_STR_h101_beammonitor_onion;
class ext_data_struct_info;

class BeamMonitorReader : public sfsReader
{
    public:
        BeamMonitorReader(EXT_STR_h101_beammonitor_onion*, size_t);

        virtual ~BeamMonitorReader();

        virtual Bool_t Init(ext_data_struct_info*) override;

        virtual Bool_t Read() override;

        virtual void Reset() override;

        void SetOnline(Bool_t option) { fOnline = option; }
    
    private:
        unsigned int fNEvent;

        EXT_STR_h101_beammonitor_onion* fData;

        size_t fOffset;

        Bool_t fOnline;

        std::vector<BeamMonitorItem>* s2array;
        std::vector<BeamMonitorItem>* s4array;

        std::vector<uint32_t> s4data;
    
    public:
        ClassDefOverride(BeamMonitorReader, 1);
};

#endif