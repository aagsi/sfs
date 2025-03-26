#ifndef sfsReader_H
#define sfsReader_H 1

#include "TObject.h"
#include "TString.h"
#include "EventHeader.h"

extern "C"
{
#include "ext_data_struct_info.hh"
}

class TClonesArray;

class sfsReader : public TObject
{
  public:
    sfsReader(TString const&);
    virtual ~sfsReader();

    /* Setup structure information */
    virtual Bool_t Init(ext_data_struct_info*) = 0;
    virtual void SetParContainers() {}
    virtual Bool_t ReInit() { return kTRUE; }
    /* Read data from full event structure */
    virtual Bool_t Read() = 0;
    /* Reset */
    virtual void Reset() = 0;
    /* Return actual name of the reader */
    const char* GetName() { return fName.Data(); }

  protected:
    TString fName;

  public:
    ClassDef(sfsReader, 0);
};

#endif /* sfsReader_H */
