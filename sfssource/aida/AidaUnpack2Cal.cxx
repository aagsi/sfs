#include "FairLogger.h"
#include "FairRootManager.h"
#include "FairRunAna.h"
#include "FairRunOnline.h"
#include "FairRuntimeDb.h"

// sfs
#include "AidaUnpack2Cal.h"
#include "TAidaConfiguration.h"
#include "sfsLogger.h"
#include "AidaData.h"
#include "AidaCalData.h"
#include "TimeMachineData.h"
#include <FairTask.h>
#include <TClonesArray.h>
#include <chrono>

// Static mapping of a FEE channel to DSSD Strip 
// Defined by AIDA hardware, not configurable
// 0 refers to the "edge" and 63 the middle
// For the "high" side thus 0 is strip 127
static const int FeeToStrip[64] = {
    62, 63, 59, 60, 61, 56, 57, 58, 52, 53, 54, 55, 49, 50, 51, 45,
    46, 47, 48, 42, 43, 44, 38, 39, 40, 41, 35, 36, 37, 31, 32, 33,
    34, 28, 29, 30, 24, 25, 26, 27, 21, 22, 23, 17, 18, 19, 20, 14,
    15, 16, 10, 11, 12,  7,  3,  0,  8,  4,  1,  9,  5,  2, 13,  6
};

AidaUnpack2Cal::AidaUnpack2Cal() :
  unpackArray(nullptr),
  scalerArray(nullptr),
  implantCalArray(new std::vector<AidaCalAdcItem>),
  decayCalArray(new std::vector<AidaCalAdcItem>),
  aidaTimeMachineArray(new TClonesArray("TimeMachineData")),
  fImplantOnline(false),
  fDecayOnline(false),
  fScalersOnline(false),
  conf(nullptr)
{
}

AidaUnpack2Cal::~AidaUnpack2Cal()
{
  delete implantCalArray;
  delete decayCalArray;
  delete aidaTimeMachineArray;
}

void AidaUnpack2Cal::SetParContainers()
{
}

InitStatus AidaUnpack2Cal::Init()
{
    FairRootManager* mgr = FairRootManager::Instance();
    sfsLOG_IF(fatal, NULL == mgr, "FairRootManager not found");

    unpackArray = mgr->InitObjectAs<decltype(unpackArray)>("AidaAdcData");
    sfsLOG_IF(fatal, !unpackArray, "Branch AidaAdcData not found!");

    scalerArray = mgr->InitObjectAs<decltype(scalerArray)>("AidaScalerData");
    sfsLOG_IF(fatal, !scalerArray, "Branch AidaScalerData not found!");

    mgr->RegisterAny("AidaImplantCalAdcData", implantCalArray, !fImplantOnline);
    mgr->RegisterAny("AidaDecayCalAdcData", decayCalArray, !fDecayOnline);
    mgr->Register("AidaTimeMachineData", "AidaTimeMachineDataFolder", aidaTimeMachineArray, !fScalersOnline);

    conf = TAidaConfiguration::GetInstance();
    ignoredEvents = 0;

    return kSUCCESS;
}


void AidaUnpack2Cal::Exec(Option_t* option)
{
  auto start = std::chrono::high_resolution_clock::now();
  implantCalArray->clear();
  decayCalArray->clear();
  aidaTimeMachineArray->Clear();

  for (auto const& unpack : *unpackArray)
  {
    if (ignoredEvents >= 10)
    {
      sfsLOG(fatal, "Lots of invalid AIDA events, check the AIDA configuration");
      return;
    }

    // TODO?: Clock correction
    if (unpack.Fee() > conf->FEEs())
    {
      sfsLOG(error, "AIDA FEE#" << unpack.Fee() << " greater than configured amount: " << conf->FEEs() << ", ignoring event");
      ignoredEvents++;
      return;
    }


    // if (conf->BB7()) if (unpack.Fee() == conf->BB7_FEE())
    // {
    //   // process BB7 events separately.
    //   // this is pretty hacky and dumb now, needs to be sorted out

    //   int dssd = conf->DSSDs(); // set to final DSSD..
    //   int side = (unpack.Channel() >= 0 && unpack.Channel() < 32) ? 0 : ((unpack.Channel() >= 32 && unpack.Channel() < 64) ? 1 : -1);
    //   int strip = unpack.Channel() - 32 * side;

    //   double intensity = (unpack.Value() - 32768); // * side ?
    //   bool range = unpack.Range();
    //   double energy = intensity * 0.7; // energy in MeV for AIDA at least.. 

    //   std::cout << "bb7 event -- " << std::endl;
    //   std::cout << "strip:: " << strip << std::endl;
    //   std::cout << "side:: " << side << std::endl;


    //   if (range) 
    //   {
    //       auto& cal = implantCalArray->emplace_back();
    //       cal.SetAll(unpack.SlowTime(), unpack.FastTime(), unpack.Fee(),
    //                 unpack.Channel(), dssd, side, strip,
    //                 range, intensity, energy);
    //   }
    //   else 
    //   {
    //       auto& cal = decayCalArray->emplace_back();
    //       cal.SetAll(unpack.SlowTime(), unpack.FastTime(), unpack.Fee(),
    //                 unpack.Channel(), dssd, side, strip,
    //                 range, intensity, energy);
    //   }

    //   continue;
  
    // }




    auto feeConf = conf->FEE(unpack.Fee() - 1);
    //std::cout << "fee:: " << unpack.Fee() << std::endl;
    if (feeConf.DSSD <= 0)
    {
      sfsLOG(error, "Invalid DSSD Mapping for AIDA fee " << unpack.Fee() << ", ignoring event");
      ignoredEvents++;
      return;
    }

    int dssd = feeConf.DSSD;

    int side = 0;
    int strip = 0;

    if (feeConf.Type == 2)
    {
      // std::cout << "dssd3 ::::  " << unpack.Channel() << std::endl;
      side = (unpack.Channel() >= 0 && unpack.Channel() < 32) ? -1 : ((unpack.Channel() >= 32 && unpack.Channel() < 64) ? 1 : 0);
      if (side == -1) 
      {
        // strip = unpack.Channel();
        //if (unpack.Channel() >= 0 && unpack.Channel() < 16) strip = unpack.Channel() + 16;
        //else if (unpack.Channel() >= 16 && unpack.Channel() < 32) strip = unpack.Channel() - 16;
        if (unpack.Channel() >= 0 && unpack.Channel() < 16) strip = unpack.Channel();
        else if (unpack.Channel() >= 16 && unpack.Channel() < 32) strip = 47 - unpack.Channel();
        
      }
      else if (side == 1) 
      {
       // if (unpack.Channel() >= 32 && unpack.Channel() < 48) strip = unpack.Channel() + 16 - 32;
       // else if (unpack.Channel() >= 48 && unpack.Channel() < 64) strip = unpack.Channel() - 16 - 32;
        if (unpack.Channel() >= 32 && unpack.Channel() < 48) strip = unpack.Channel() - 32;
        else if (unpack.Channel() >= 48 && unpack.Channel() < 64) strip = 47 - (unpack.Channel() - 32);
        // std::cout << unpack.Channel() << std::endl;
      }

    }
    else
    {
      side = feeConf.Side;
      if (feeConf.High)
      {
        strip = 127 - FeeToStrip[unpack.Channel()];
      }
      else
      {
        strip = FeeToStrip[unpack.Channel()];
      }
    }

 
    if (conf->Wide() && feeConf.Side == conf->DSSD(dssd - 1).XSide)
    {
      int shift = 0;
      if (feeConf.Segment == WideAIDASegment::Centre) shift = 128;
      if (feeConf.Segment == WideAIDASegment::Right) shift = 256;
      strip += shift;
    }
    double intensity = (unpack.Value() - 32768) * side;
    bool range = unpack.Range();
    double energy = 0;
    if (range)
    {
      energy = intensity * 0.7; // Energy in MeV
    }
    else
    {

      intensity = (intensity - conf->GetAdcOffset(unpack.Fee() - 1, unpack.Channel()));
      energy = intensity * conf->GetDssdGain(dssd - 1,
          side == conf->DSSD(dssd - 1).XSide ? 0 : 1, strip);

    }

    // Split into implant and decay arrays, check threshold for decays
    if (range) {
      auto& cal = implantCalArray->emplace_back();
      cal.SetAll(unpack.SlowTime(), unpack.FastTime(), unpack.Fee(),
          unpack.Channel(), dssd, side, strip,
          range, intensity, energy);

    }
    else {
      double thrs = conf->GetDssdStripThreshold(dssd - 1, side == - 1 ? 0 : 1, strip);
      if (thrs >= 0 && energy > thrs) {
        auto& cal = decayCalArray->emplace_back();
        cal.SetAll(unpack.SlowTime(), unpack.FastTime(), unpack.Fee(),
            unpack.Channel(), dssd, side, strip,
            range, intensity, energy);
      }
    }
  }

  // Clear decay array if implants present
  if (implantCalArray->size() > 0) {
    decayCalArray->clear();
  }


  uint64_t wr_undelayed = 0;
  uint64_t wr_delayed = 0;
  // Check scalers - for now just for Time Machine (raw is otherwise fine)
  for (auto const& scaler : *scalerArray)
  {
    if (scaler.Fee() == conf->TM_Undelayed())
    {
      wr_undelayed = scaler.Time();
    }
    if (scaler.Fee() == conf->TM_Delayed())
    {
      wr_delayed = scaler.Time();
    }
  }
  if (wr_undelayed != 0 && wr_delayed != 0)
  {
    int64_t time_diff = wr_delayed - wr_undelayed;
    new ((*aidaTimeMachineArray)[aidaTimeMachineArray->GetEntriesFast()]) TimeMachineData((double)(wr_undelayed & 0xFFFFFFFF), 0, 0x700, wr_undelayed);
    new ((*aidaTimeMachineArray)[aidaTimeMachineArray->GetEntriesFast()]) TimeMachineData(0, (double)(wr_delayed & 0xFFFFFFFF), 0x700, wr_delayed);
  }
    fExecs++;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    total_time_microsecs += duration.count();
}

void AidaUnpack2Cal::FinishTask()
{
    sfsLOG(info, "Average execution time: " << (double)total_time_microsecs/fExecs << " microseconds.");
}

ClassImp(AidaUnpack2Cal)

