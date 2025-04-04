#ifndef UnpackReader_H
#define UnpackReader_H 1

#include "sfsReader.h"
#include <Rtypes.h>
#include "EventHeader.h"
#include "TExperimentConfiguration.h"

struct EXT_STR_h101_unpack_t;
typedef struct EXT_STR_h101_unpack_t EXT_STR_h101_unpack;

class ext_data_struct_info;

class TExperimentConfiguration;

class UnpackReader : public sfsReader
{
  public:
    UnpackReader(EXT_STR_h101_unpack*, size_t);

    // Destructor
    virtual ~UnpackReader();

    // Setup structure information
    virtual Bool_t Init(ext_data_struct_info*) override;

    // Read data from full event structure
    virtual Bool_t Read() override;

    // Reset
    virtual void Reset() override;

    void SetOnline(Bool_t option) { fOnline = option; }

  private:
    // An event counter
    uint64_t fNEvent;
    // Reader specific data structure from ucesb
    EXT_STR_h101_unpack* fData;
    // Offset of detector specific data in full data structure
    size_t fOffset;
    // A pointer to the EventHeader structure
    EventHeader* fHeader;
    //
    Bool_t spill_flag = false;

    Bool_t fOnline;

    TExperimentConfiguration const* exp_config;

  public:
    ClassDefOverride(UnpackReader, 0);
};

#endif /* UnpackReader_H */
