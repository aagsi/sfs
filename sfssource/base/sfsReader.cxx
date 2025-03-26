#include "sfsReader.h"

sfsReader::sfsReader(TString const& a_name)
    : TObject()
    , fName(a_name)
{
}

sfsReader::~sfsReader() {}

ClassImp(sfsReader);
