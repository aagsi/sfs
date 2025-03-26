class BAD_EVENT
{
  DATA8 bad;
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(BAD_EVENT);
};
class BARRIER
{
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(BARRIER);
};
class DUMMY
{
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(DUMMY);
};
class FEBEX_EVENT
{
  DATA8 trig;
  DATA32 event_trigger_time_hi;
  DATA32 event_trigger_time_lo;
  DATA16 hit_pattern;
  raw_array_zero_suppress<DATA16,DATA16,16> channel_trigger_time_hi;
  raw_array_zero_suppress<DATA32,DATA32,16> channel_trigger_time_lo;
  raw_array_zero_suppress<DATA8,DATA8,16> pileup;
  raw_array_zero_suppress<DATA8,DATA8,16> overflow;
  raw_array_zero_suppress<DATA8,DATA8,16> channel_cfd;
  raw_array_zero_suppress<DATA32,DATA32,16> channel_energy;
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 card);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 card);
  STRUCT_FCNS_DECL(FEBEX_EVENT);
};
class TRACE
{
  raw_array_zero_suppress<DATA16,DATA16,4000> traces[16];
  raw_array_zero_suppress<DATA8,DATA8,16> channel_id_traces;
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 board);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 board);
  STRUCT_FCNS_DECL(TRACE);
};
class FEBEX_EVENT_TRACES
{
  DATA8 trig;
  DATA32 event_trigger_time_hi;
  DATA32 event_trigger_time_lo;
  DATA16 hit_pattern;
  DATA32 num_channels_fired;
  DATA8 board_num;
  raw_array_zero_suppress<DATA8,DATA8,16> channel_id;
  raw_array_zero_suppress<DATA16,DATA16,16> channel_trigger_time_hi;
  raw_array_zero_suppress<DATA32,DATA32,16> channel_trigger_time_lo;
  raw_array_zero_suppress<DATA8,DATA8,16> pileup;
  raw_array_zero_suppress<DATA8,DATA8,16> overflow;
  raw_array_zero_suppress<DATA8,DATA8,16> channel_cfd;
  raw_array_zero_suppress<DATA32,DATA32,16> channel_energy;
      SINGLE(TRACE,trace);
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 card);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 card);
  STRUCT_FCNS_DECL(FEBEX_EVENT_TRACES);
};
class FEBEX_PADDING
{
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(FEBEX_PADDING);
};
class MVLC_SCALER
{
  raw_array_zero_suppress<DATA32,DATA32,32> scalers;
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 geo);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 geo);
  STRUCT_FCNS_DECL(MVLC_SCALER);
};
class VME_CAEN_V7X5
{
  raw_array_zero_suppress<DATA24,DATA24,32> data;
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 geom);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 geom);
  STRUCT_FCNS_DECL(VME_CAEN_V7X5);
};
class TDC_HEADER
{
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(TDC_HEADER);
};
class TDC_DATA_V1290
{
  raw_array_multi_zero_suppress<DATA24,DATA24,128,128> data;
  raw_array_multi_zero_suppress<DATA8,DATA8,128,128> leadOrTrail;
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(TDC_DATA_V1290);
};
class TDC_ERROR
{
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(TDC_ERROR);
};
class TDC_TRAILER
{
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(TDC_TRAILER);
};
class VME_CAEN_V1290_N
{
  DATA8 geo;
  SINGLE(TDC_HEADER,tdc_header);
  SINGLE(TDC_DATA_V1290,measurement);
  SINGLE(TDC_ERROR,tdc_err);
  SINGLE(TDC_TRAILER,tdc_trailer);
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(VME_CAEN_V1290_N);
};
class MAIN_CRATE_DATA
{
  SINGLE(BARRIER,barrier0);
  SINGLE(MVLC_SCALER,v830);
  SINGLE(BARRIER,barrier1);
  SINGLE(VME_CAEN_V7X5,v792);
  SINGLE(BARRIER,barrier2);
  SINGLE(VME_CAEN_V1290_N,v1290);
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(MAIN_CRATE_DATA);
};
class SPILL_OFF
{
  DATA8 spilloff;
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(SPILL_OFF);
};
class SPILL_ON
{
  DATA8 spillon;
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(SPILL_ON);
};
class TAMEX4_EPOCH_DATA
{
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 sfp,uint32 card,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_coarse
                                      ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_fine
                                      ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_edge
                                      ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_channel
                                      ,raw_list_ii_zero_suppress<DATA32,DATA32,1024> &time_epoch);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 sfp,uint32 card);
  STRUCT_FCNS_DECL(TAMEX4_EPOCH_DATA);
};
class TAMEX4_HEADER
{
  DATA16 post_trig_ns;
  DATA16 pre_trig_ns;
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(TAMEX4_HEADER);
};
class TAMEX4_PADDING
{
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(TAMEX4_PADDING);
};
class TAMEX4_TIME_DATA
{
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 sfp,uint32 card,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_coarse
                                      ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_fine
                                      ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_edge
                                      ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_channel
                                      ,raw_list_ii_zero_suppress<DATA32,DATA32,1024> &time_epoch);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 sfp,uint32 card);
  STRUCT_FCNS_DECL(TAMEX4_TIME_DATA);
};
class TAMEX4_SFP
{
  DATA16 trig;
  DATA32 event_size;
  raw_list_ii_zero_suppress<DATA12,DATA12,1024> time_coarse;
  raw_list_ii_zero_suppress<DATA12,DATA12,1024> time_fine;
  raw_list_ii_zero_suppress<DATA12,DATA12,1024> time_edge;
  raw_list_ii_zero_suppress<DATA12,DATA12,1024> time_channel;
  raw_list_ii_zero_suppress<DATA32,DATA32,1024> time_epoch;
    SINGLE(TAMEX4_EPOCH_DATA,epoch);
    SINGLE(TAMEX4_TIME_DATA,time);
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 sfp,uint32 card);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 sfp,uint32 card);
  STRUCT_FCNS_DECL(TAMEX4_SFP);
};
class TDC_DATA_V1190
{
  raw_array_multi_zero_suppress<DATA24,DATA24,128,128> data;
  raw_array_multi_zero_suppress<DATA8,DATA8,128,128> leadOrTrail;
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(TDC_DATA_V1190);
};
class TIMESTAMP_WHITERABBIT
{
  DATA12 subsystem_id;
  DATA16 t1;
  DATA16 t2;
  DATA16 t3;
  DATA16 t4;
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 id);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 id);
  STRUCT_FCNS_DECL(TIMESTAMP_WHITERABBIT);
};
class TIMESTAMP_WHITERABBIT_EXTENDED
{
  DATA16 subsystem_id;
  DATA16 t1;
  DATA16 t2;
  DATA16 t3;
  DATA16 t4;
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 id);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 id);
  STRUCT_FCNS_DECL(TIMESTAMP_WHITERABBIT_EXTENDED);
};
class TPAT_CRATE_DATA
{
  DATA16 tpat;
  uint32 w1;
  uint32 w2;
  uint32 w3;
  union
  {
    struct
    {
      uint32 pattern : 16;
      uint32 nothing : 16;
    };
    uint32 u32;
  } trigger_pattern;
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(TPAT_CRATE_DATA);
};
class VME_CAEN_V1190_N
{
  DATA8 geo;
  SINGLE(TDC_HEADER,tdc_header);
  SINGLE(TDC_DATA_V1190,measurement);
  SINGLE(TDC_ERROR,tdc_error);
  SINGLE(TDC_TRAILER,tdc_trailer);
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(VME_CAEN_V1190_N);
};
class TPC_CRATE_DATA
{
  SINGLE(BARRIER,barrier0);
  SINGLE(VME_CAEN_V7X5,v785);
  SINGLE(VME_CAEN_V7X5,v775);
  SINGLE(DUMMY,dummy);
  SINGLE(BARRIER,barrier1);
  SINGLE(VME_CAEN_V1190_N,v1190);
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(TPC_CRATE_DATA);
};
class VME_MESYTEC_MDPP16
{
  raw_array<DATA24,DATA24,16> adc;
  raw_array<DATA24,DATA24,16> tdc;
  raw_array<DATA24,DATA24,16> trig_tdc;
  raw_array<DATA24,DATA24,16> adc_short;
  union
  {
    struct
    {
      uint32 counter : 30;
      uint32 unnamed_30_31 : 2;
    };
    uint32 u32;
  } end_of_event;
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 geom);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 geom);
  STRUCT_FCNS_DECL(VME_MESYTEC_MDPP16);
};
class TRAVMUS_CRATE_DATA
{
    SINGLE(VME_MESYTEC_MDPP16,mdpp);
    SINGLE(DUMMY,dummy);
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(TRAVMUS_CRATE_DATA);
};
class TRIG3EVENT
{
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(TRIG3EVENT);
};
class USER_CRATE_DATA
{
  SINGLE(BARRIER,barrier1);
  SINGLE(VME_CAEN_V7X5,v775[2]);
  SINGLE(VME_CAEN_V7X5,v785[2]);
  SINGLE(BARRIER,barrier0);
  SINGLE(MVLC_SCALER,v830);
  SINGLE(BARRIER,barrier2);
  SINGLE(VME_CAEN_V1290_N,v1290);
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(USER_CRATE_DATA);
};
class VME_CAEN_V830
{
  raw_array_zero_suppress<DATA32,DATA32,32> data;
  union
  {
    struct
    {
      uint32 event_number : 16;
      uint32 ts : 2;
      uint32 count : 6;
      uint32 undefined : 2;
      uint32 unnamed_26_26 : 1;
      uint32 geom : 5;
    };
    uint32 u32;
  } header;
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 geom);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 geom);
  STRUCT_FCNS_DECL(VME_CAEN_V830);
};
class VULOM_TPAT
{
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(VULOM_TPAT);
};
class WR_MULTI
{
  DATA32 time_hi;
  DATA32 time_lo;
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(WR_MULTI);
};
class ZERO_FILLER
{
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(ZERO_FILLER);
};
class aida_subev
 : public unpack_subevent_base
{
  SINGLE(TIMESTAMP_WHITERABBIT,ts);
  SINGLE(EXT_AIDA,data);
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(aida_subev);
};
class bplast_subev
 : public unpack_subevent_base
{
  SINGLE(TIMESTAMP_WHITERABBIT,ts);
  SINGLE(TAMEX4_HEADER,trigger_window);
  SINGLE(TAMEX4_PADDING,padding);
  SINGLE(TAMEX4_SFP,tamex[9]);
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(bplast_subev);
};
class febex_subev
 : public unpack_subevent_base
{
  SINGLE(TIMESTAMP_WHITERABBIT,ts);
  SINGLE(FEBEX_PADDING,padding);
  SINGLE(FEBEX_EVENT,data[6]);
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(febex_subev);
};
class frs_main_subev
 : public unpack_subevent_base
{
  SINGLE(TRIG3EVENT,trig3);
  SINGLE(SPILL_ON,spill_on);
  SINGLE(SPILL_OFF,spill_off);
  SINGLE(MAIN_CRATE_DATA,data);
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(frs_main_subev);
};
class frs_tpat_subev
 : public unpack_subevent_base
{
  SINGLE(TIMESTAMP_WHITERABBIT,wr);
  SINGLE(TRIG3EVENT,trig3);
  SINGLE(TPAT_CRATE_DATA,data);
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(frs_tpat_subev);
};
class frs_tpc_subev
 : public unpack_subevent_base
{
  union
  {
    struct
    {
      uint32 b : 32;
    };
    uint32 u32;
  } be;
  SINGLE(TRIG3EVENT,trig3);
  SINGLE(SPILL_ON,spill_on);
  SINGLE(SPILL_OFF,spill_off);
  SINGLE(TPC_CRATE_DATA,data);
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(frs_tpc_subev);
};
class frs_travmus_subev
 : public unpack_subevent_base
{
  SINGLE(TIMESTAMP_WHITERABBIT,wr);
  SINGLE(VULOM_TPAT,stuff);
  SINGLE(TRAVMUS_CRATE_DATA,data);
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(frs_travmus_subev);
};
class frs_user_subev
 : public unpack_subevent_base
{
  SINGLE(TRIG3EVENT,trig3);
  SINGLE(SPILL_ON,spill_on);
  SINGLE(SPILL_OFF,spill_off);
  SINGLE(USER_CRATE_DATA,data);
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  STRUCT_FCNS_DECL(frs_user_subev);
};
class unpack_event : public unpack_event_base
{
SINGLE(aida_subev,aida);
SINGLE(febex_subev,germanium);
SINGLE(bplast_subev,bplast);
SINGLE(frs_main_subev,frsmain);
SINGLE(frs_tpc_subev,frstpc);
SINGLE(frs_user_subev,frsuser);
SINGLE(frs_tpat_subev,frstpat);
SINGLE(frs_travmus_subev,frstravmus);
  bitsone<9> __visited;
  void __clear_visited() { __visited.clear(); }
  bool ignore_unknown_subevent() { return true; }
template<typename __data_src_t>
  int __unpack_subevent(subevent_header *__header,__data_src_t &__buffer);
  int __revoke_subevent(subevent_header *__header);
  STRUCT_FCNS_DECL(unpack_event);
};
class unpack_sticky_event : public unpack_sticky_event_base
{
  void __clear_visited() { }
  bool ignore_unknown_subevent() { return false; }
template<typename __data_src_t>
  int __unpack_subevent(subevent_header *__header,__data_src_t &__buffer);
  int __revoke_subevent(subevent_header *__header);
  STRUCT_FCNS_DECL(unpack_sticky_event);
};
