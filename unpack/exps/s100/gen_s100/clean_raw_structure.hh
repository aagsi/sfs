class raw_event_SPILL
{
  DATA8 ON;
  DATA8 OFF;
  STRUCT_FCNS_DECL(raw_event_SPILL);
} ;
class raw_event_SCI_TAC
{
  raw_array_zero_suppress<DATA24,DATA24,16> DE;
  raw_array_zero_suppress<DATA24,DATA24,16> DT;
  STRUCT_FCNS_DECL(raw_event_SCI_TAC);
} ;
class raw_event_SCI_MHTDC
{
  raw_array_multi_zero_suppress<DATA24,DATA24,16,128> T;
  raw_array_multi_zero_suppress<DATA8,DATA8,16,128> LOT;
  STRUCT_FCNS_DECL(raw_event_SCI_MHTDC);
} ;
class raw_event_SCI
{
  raw_event_SCI_TAC
       TAC;
  raw_event_SCI_MHTDC
       MHTDC;
  STRUCT_FCNS_DECL(raw_event_SCI);
} ;
class raw_event_TPC_TDC
{
  raw_array_multi_zero_suppress<DATA24,DATA24,128,128> T;
  raw_array_multi_zero_suppress<DATA8,DATA8,128,128> LOT;
  STRUCT_FCNS_DECL(raw_event_TPC_TDC);
} ;
class raw_event_TPC
{
  raw_array_zero_suppress<DATA24,DATA24,32> ADC[7];
  raw_event_TPC_TDC
       TDC;
  STRUCT_FCNS_DECL(raw_event_TPC);
} ;
class raw_event_MUSIC
{
  raw_array_multi_zero_suppress<DATA24,DATA24,8,128> T;
  raw_array_multi_zero_suppress<DATA8,DATA8,8,128> LOT;
  raw_array_zero_suppress<DATA24,DATA24,8> E;
  STRUCT_FCNS_DECL(raw_event_MUSIC);
} ;
class raw_event_WR
{
  DATA12 ID;
  DATA16 T[4];
  STRUCT_FCNS_DECL(raw_event_WR);
} ;
class raw_event : public raw_event_base
{
  raw_event_SPILL
       SPILL;
  raw_array_zero_suppress<DATA32,DATA32,32> SCALERS[2];
  raw_event_SCI
       SCI;
  raw_event_TPC
       TPC;
  raw_event_MUSIC
       MUSIC[2];
  raw_event_WR
       WR;
  DATA16 TPAT;
  STRUCT_FCNS_DECL(raw_event);
} ;
class raw_sticky : public raw_sticky_base
{
  STRUCT_FCNS_DECL(raw_sticky);
} ;
