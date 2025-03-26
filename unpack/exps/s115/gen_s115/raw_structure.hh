/** BEGIN_EVENT_RAW_STRUCTURE ******************************************
 *
 * Event data structure.
 *
 * Do not edit - automatically generated.
 */

class raw_event_SPILL
{
public:
  DATA8 ON;
  DATA8 OFF;

public:
#ifndef __PSDC__
  STRUCT_FCNS_DECL(raw_event_SPILL);
#endif//!__PSDC__
} ;

class raw_event_SCI_TAC
{
public:
//DUMPY: 32 1
  raw_array_zero_suppress<DATA24,DATA24,32> DE;
//DUMPY: 32 1
  raw_array_zero_suppress<DATA24,DATA24,32> DT;

public:
#ifndef __PSDC__
  STRUCT_FCNS_DECL(raw_event_SCI_TAC);
#endif//!__PSDC__
} ;

class raw_event_SCI_MHTDC
{
public:
//DUMPY: 32 4
  raw_array_multi_zero_suppress<DATA24,DATA24,32,128> T;
//DUMPY: 32 4
  raw_array_multi_zero_suppress<DATA8,DATA8,32,128> LOT;

public:
#ifndef __PSDC__
  STRUCT_FCNS_DECL(raw_event_SCI_MHTDC);
#endif//!__PSDC__
} ;

class raw_event_SCI
{
public:
  raw_event_SCI_TAC
  /* {
  public:
//DUMPY: 32 1
    raw_array_zero_suppress<DATA24,DATA24,32> DE;
//DUMPY: 32 1
    raw_array_zero_suppress<DATA24,DATA24,32> DT;
  } */ TAC;
  raw_event_SCI_MHTDC
  /* {
  public:
//DUMPY: 32 4
    raw_array_multi_zero_suppress<DATA24,DATA24,32,128> T;
//DUMPY: 32 4
    raw_array_multi_zero_suppress<DATA8,DATA8,32,128> LOT;
  } */ MHTDC;

public:
#ifndef __PSDC__
  STRUCT_FCNS_DECL(raw_event_SCI);
#endif//!__PSDC__
} ;

class raw_event_TPC_TDC
{
public:
//DUMPY: 128 4
  raw_array_multi_zero_suppress<DATA24,DATA24,128,128> T;
//DUMPY: 128 4
  raw_array_multi_zero_suppress<DATA8,DATA8,128,128> LOT;

public:
#ifndef __PSDC__
  STRUCT_FCNS_DECL(raw_event_TPC_TDC);
#endif//!__PSDC__
} ;

class raw_event_TPC
{
public:
//DUMPY: 7 0
//DUMPY: 32 1
  raw_array_zero_suppress<DATA24,DATA24,32> ADC[7];
  raw_event_TPC_TDC
  /* {
  public:
//DUMPY: 128 4
    raw_array_multi_zero_suppress<DATA24,DATA24,128,128> T;
//DUMPY: 128 4
    raw_array_multi_zero_suppress<DATA8,DATA8,128,128> LOT;
  } */ TDC;

public:
#ifndef __PSDC__
  STRUCT_FCNS_DECL(raw_event_TPC);
#endif//!__PSDC__
} ;

//DUMPY: 5 0
class raw_event_MUSIC
{
public:
//DUMPY: 8 1
  raw_array_zero_suppress<DATA24,DATA24,8> E;
//DUMPY: 8 4
  raw_array_multi_zero_suppress<DATA24,DATA24,8,128> T;
//DUMPY: 8 4
  raw_array_multi_zero_suppress<DATA8,DATA8,8,128> LOT;

public:
#ifndef __PSDC__
  STRUCT_FCNS_DECL(raw_event_MUSIC);
#endif//!__PSDC__
} ;

class raw_event_WR
{
public:
  DATA12 ID;
//DUMPY: 4 0
  DATA16 T[4];

public:
#ifndef __PSDC__
  STRUCT_FCNS_DECL(raw_event_WR);
#endif//!__PSDC__
} ;

class raw_event : public raw_event_base
{
public:
  raw_event_SPILL
  /* {
  public:
    DATA8 ON;
    DATA8 OFF;
  } */ SPILL;
//DUMPY: 2 0
//DUMPY: 32 1
  raw_array_zero_suppress<DATA32,DATA32,32> SCALERS[2];
  raw_event_SCI
  /* {
  public:
    raw_event_SCI_TAC
    {
    public:
//DUMPY: 32 1
      raw_array_zero_suppress<DATA24,DATA24,32> DE;
//DUMPY: 32 1
      raw_array_zero_suppress<DATA24,DATA24,32> DT;
    } TAC;
    raw_event_SCI_MHTDC
    {
    public:
//DUMPY: 32 4
      raw_array_multi_zero_suppress<DATA24,DATA24,32,128> T;
//DUMPY: 32 4
      raw_array_multi_zero_suppress<DATA8,DATA8,32,128> LOT;
    } MHTDC;
  } */ SCI;
  raw_event_TPC
  /* {
  public:
//DUMPY: 7 0
//DUMPY: 32 1
    raw_array_zero_suppress<DATA24,DATA24,32> ADC[7];
    raw_event_TPC_TDC
    {
    public:
//DUMPY: 128 4
      raw_array_multi_zero_suppress<DATA24,DATA24,128,128> T;
//DUMPY: 128 4
      raw_array_multi_zero_suppress<DATA8,DATA8,128,128> LOT;
    } TDC;
  } */ TPC;
//DUMPY: 5 0
  raw_event_MUSIC
  /* {
  public:
//DUMPY: 8 1
    raw_array_zero_suppress<DATA24,DATA24,8> E;
//DUMPY: 8 4
    raw_array_multi_zero_suppress<DATA24,DATA24,8,128> T;
//DUMPY: 8 4
    raw_array_multi_zero_suppress<DATA8,DATA8,8,128> LOT;
  } */ MUSIC[5];
  raw_event_WR
  /* {
  public:
    DATA12 ID;
//DUMPY: 4 0
    DATA16 T[4];
  } */ WR;
  DATA16 TPAT;

public:
#ifndef __PSDC__
  STRUCT_FCNS_DECL(raw_event);
#endif//!__PSDC__
} ;

/** END_EVENT_RAW_STRUCTURE *******************************************/
/** BEGIN_EVENT_RAW_STRUCTURE ******************************************
 *
 * Event data structure.
 *
 * Do not edit - automatically generated.
 */

class raw_sticky : public raw_sticky_base
{
public:

public:
#ifndef __PSDC__
  STRUCT_FCNS_DECL(raw_sticky);
#endif//!__PSDC__
} ;

/** END_EVENT_RAW_STRUCTURE *******************************************/
