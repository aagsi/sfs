// FairRoot
#include "FairTask.h"
#include "FairLogger.h"
#include "FairRootManager.h"
#include "FairRunAna.h"
#include "FairRunOnline.h"
#include "FairRuntimeDb.h"

// sfs
#include "LisaRaw2Ana.h"
#include "sfsLogger.h"

// ROOT

#include <vector>
#include <numeric>

LisaRaw2Ana::LisaRaw2Ana()
    :   FairTask()
    ,   header(nullptr)
    ,   fNEvents(0)
    ,   fOnline(kFALSE)
    ,   lisaArray(nullptr)
    ,   lisaAnaArray(new std::vector<LisaAnaItem>)

{
    lisa_config = TLisaConfiguration::GetInstance();
}



LisaRaw2Ana::~LisaRaw2Ana()
{
    delete lisaArray;
    delete lisaAnaArray;
}

InitStatus LisaRaw2Ana::Init()
{
    FairRootManager* mgr = FairRootManager::Instance();
    sfsLOG_IF(fatal, NULL == mgr, "FairRootManager not found");

    header = (EventHeader*)mgr->GetObject("EventHeader.");
    sfsLOG_IF(error, !header, "Branch EventHeader. not found");

    lisaArray = mgr->InitObjectAs<decltype(lisaArray)>("LisaData");
    sfsLOG_IF(fatal, !lisaArray, "Branch LisaData not found!");
    
    mgr->RegisterAny("LisaAnaData", lisaAnaArray, !fOnline);

    return kSUCCESS;
}


//:::
// void LisaRaw2Cal::PrintMWDParameter()
// {
//     if (lisa_config->MWDParameterLoaded())
//     {
//         for (const auto& entry : lisa_config->MWDParameters())
//         {
//             //print parameters values
//         }
//     }
//     else
//     {
//         sfsLOG(info, "MWD parameters are not loaded");
//     }
// }   
//:::



void LisaRaw2Ana::Exec(Option_t* option)
{
    // lisaAnaArray->clear();

    // for (auto const & lisaItem : *lisaArray)
    // {
        
                
    //     if (lisa_config->MWDParametersLoaded())
    //     {

    //         sfsLOG(warn, "MWD Parameters loaded? ");

    //     }


    // }
}

void LisaRaw2Ana::FinishEvent()
{

}

void LisaRaw2Ana::FinishTask()
{
}