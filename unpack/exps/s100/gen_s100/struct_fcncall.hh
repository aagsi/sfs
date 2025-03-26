/** BEGIN_FUNCTION_CALL_PER_MEMBER *************************************
 *
 * Recursive function calls per member.
 *
 * Do not edit - automatically generated.
 */

#include "gen/default_fcncall_define.hh"

#ifndef USER_DEF_BAD_EVENT
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(BAD_EVENT)::FCNCALL_NAME(BAD_EVENT)
{
  FCNCALL_INIT;
  // DATA8 bad;
  {
  FCNCALL_SUBNAME("bad");
  { FCNCALL_CALL_CTRL_WRAP(bad,bad.FCNCALL_CALL(bad)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_BAD_EVENT

#ifndef USER_DEF_BARRIER
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(BARRIER)::FCNCALL_NAME(BARRIER)
{
  FCNCALL_INIT;
  FCNCALL_RET;
}
#endif//USER_DEF_BARRIER

#ifndef USER_DEF_DUMMY
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(DUMMY)::FCNCALL_NAME(DUMMY)
{
  FCNCALL_INIT;
  FCNCALL_RET;
}
#endif//USER_DEF_DUMMY

#ifndef USER_DEF_ERR_WORD_SIX
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(ERR_WORD_SIX)::FCNCALL_NAME(ERR_WORD_SIX)
{
  FCNCALL_INIT;
  FCNCALL_RET;
}
#endif//USER_DEF_ERR_WORD_SIX

#ifndef USER_DEF_FATIMA_VME_SCALERS
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(FATIMA_VME_SCALERS)::FCNCALL_NAME(FATIMA_VME_SCALERS)
{
  FCNCALL_INIT;
  // raw_array_zero_suppress<DATA32,DATA32,32> data;
  {
  FCNCALL_SUBNAME("data");
  { FCNCALL_CALL_CTRL_WRAP(data,data.FCNCALL_CALL(data)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_FATIMA_VME_SCALERS

#ifndef USER_DEF_FEBEX_EVENT
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(FEBEX_EVENT)::FCNCALL_NAME(FEBEX_EVENT)
{
  FCNCALL_INIT;
  // DATA8 trig;
  {
  FCNCALL_SUBNAME("trig");
  { FCNCALL_CALL_CTRL_WRAP(trig,trig.FCNCALL_CALL(trig)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA32 event_trigger_time_hi;
  {
  FCNCALL_SUBNAME("event_trigger_time_hi");
  { FCNCALL_CALL_CTRL_WRAP(event_trigger_time_hi,event_trigger_time_hi.FCNCALL_CALL(event_trigger_time_hi)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA32 event_trigger_time_lo;
  {
  FCNCALL_SUBNAME("event_trigger_time_lo");
  { FCNCALL_CALL_CTRL_WRAP(event_trigger_time_lo,event_trigger_time_lo.FCNCALL_CALL(event_trigger_time_lo)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA16 hit_pattern;
  {
  FCNCALL_SUBNAME("hit_pattern");
  { FCNCALL_CALL_CTRL_WRAP(hit_pattern,hit_pattern.FCNCALL_CALL(hit_pattern)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_array_zero_suppress<DATA16,DATA16,16> channel_trigger_time_hi;
  {
  FCNCALL_SUBNAME("channel_trigger_time_hi");
  { FCNCALL_CALL_CTRL_WRAP(channel_trigger_time_hi,channel_trigger_time_hi.FCNCALL_CALL(channel_trigger_time_hi)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_array_zero_suppress<DATA32,DATA32,16> channel_trigger_time_lo;
  {
  FCNCALL_SUBNAME("channel_trigger_time_lo");
  { FCNCALL_CALL_CTRL_WRAP(channel_trigger_time_lo,channel_trigger_time_lo.FCNCALL_CALL(channel_trigger_time_lo)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_array_zero_suppress<DATA8,DATA8,16> pileup;
  {
  FCNCALL_SUBNAME("pileup");
  { FCNCALL_CALL_CTRL_WRAP(pileup,pileup.FCNCALL_CALL(pileup)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_array_zero_suppress<DATA8,DATA8,16> overflow;
  {
  FCNCALL_SUBNAME("overflow");
  { FCNCALL_CALL_CTRL_WRAP(overflow,overflow.FCNCALL_CALL(overflow)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_array_zero_suppress<DATA8,DATA8,16> channel_cfd;
  {
  FCNCALL_SUBNAME("channel_cfd");
  { FCNCALL_CALL_CTRL_WRAP(channel_cfd,channel_cfd.FCNCALL_CALL(channel_cfd)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_array_zero_suppress<DATA32,DATA32,16> channel_energy;
  {
  FCNCALL_SUBNAME("channel_energy");
  { FCNCALL_CALL_CTRL_WRAP(channel_energy,channel_energy.FCNCALL_CALL(channel_energy)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_FEBEX_EVENT

#ifndef USER_DEF_TRACE
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(TRACE)::FCNCALL_NAME(TRACE)
{
  FCNCALL_INIT;
  // raw_array_zero_suppress<DATA16,DATA16,4000> traces[16];
  {
  FCNCALL_SUBNAME("traces");
  FCNCALL_FOR(__i0,16)
  {
    FCNCALL_SUBINDEX(__i0);
    { FCNCALL_CALL_CTRL_WRAP_ARRAY(traces__i0,,__i0,traces[__i0].FCNCALL_CALL(traces[__i0])); }
    FCNCALL_SUBINDEX_END(__i0);
  }
  FCNCALL_SUBNAME_END;
  }
  // raw_array_zero_suppress<DATA8,DATA8,16> channel_id_traces;
  {
  FCNCALL_SUBNAME("channel_id_traces");
  { FCNCALL_CALL_CTRL_WRAP(channel_id_traces,channel_id_traces.FCNCALL_CALL(channel_id_traces)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_TRACE

#ifndef USER_DEF_FEBEX_EVENT_TRACES
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(FEBEX_EVENT_TRACES)::FCNCALL_NAME(FEBEX_EVENT_TRACES)
{
  FCNCALL_INIT;
  // DATA8 trig;
  {
  FCNCALL_SUBNAME("trig");
  { FCNCALL_CALL_CTRL_WRAP(trig,trig.FCNCALL_CALL(trig)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA32 event_trigger_time_hi;
  {
  FCNCALL_SUBNAME("event_trigger_time_hi");
  { FCNCALL_CALL_CTRL_WRAP(event_trigger_time_hi,event_trigger_time_hi.FCNCALL_CALL(event_trigger_time_hi)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA32 event_trigger_time_lo;
  {
  FCNCALL_SUBNAME("event_trigger_time_lo");
  { FCNCALL_CALL_CTRL_WRAP(event_trigger_time_lo,event_trigger_time_lo.FCNCALL_CALL(event_trigger_time_lo)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA16 hit_pattern;
  {
  FCNCALL_SUBNAME("hit_pattern");
  { FCNCALL_CALL_CTRL_WRAP(hit_pattern,hit_pattern.FCNCALL_CALL(hit_pattern)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA32 num_channels_fired;
  {
  FCNCALL_SUBNAME("num_channels_fired");
  { FCNCALL_CALL_CTRL_WRAP(num_channels_fired,num_channels_fired.FCNCALL_CALL(num_channels_fired)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA8 board_num;
  {
  FCNCALL_SUBNAME("board_num");
  { FCNCALL_CALL_CTRL_WRAP(board_num,board_num.FCNCALL_CALL(board_num)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_array_zero_suppress<DATA8,DATA8,16> channel_id;
  {
  FCNCALL_SUBNAME("channel_id");
  { FCNCALL_CALL_CTRL_WRAP(channel_id,channel_id.FCNCALL_CALL(channel_id)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_array_zero_suppress<DATA16,DATA16,16> channel_trigger_time_hi;
  {
  FCNCALL_SUBNAME("channel_trigger_time_hi");
  { FCNCALL_CALL_CTRL_WRAP(channel_trigger_time_hi,channel_trigger_time_hi.FCNCALL_CALL(channel_trigger_time_hi)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_array_zero_suppress<DATA32,DATA32,16> channel_trigger_time_lo;
  {
  FCNCALL_SUBNAME("channel_trigger_time_lo");
  { FCNCALL_CALL_CTRL_WRAP(channel_trigger_time_lo,channel_trigger_time_lo.FCNCALL_CALL(channel_trigger_time_lo)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_array_zero_suppress<DATA8,DATA8,16> pileup;
  {
  FCNCALL_SUBNAME("pileup");
  { FCNCALL_CALL_CTRL_WRAP(pileup,pileup.FCNCALL_CALL(pileup)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_array_zero_suppress<DATA8,DATA8,16> overflow;
  {
  FCNCALL_SUBNAME("overflow");
  { FCNCALL_CALL_CTRL_WRAP(overflow,overflow.FCNCALL_CALL(overflow)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_array_zero_suppress<DATA8,DATA8,16> channel_cfd;
  {
  FCNCALL_SUBNAME("channel_cfd");
  { FCNCALL_CALL_CTRL_WRAP(channel_cfd,channel_cfd.FCNCALL_CALL(channel_cfd)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_array_zero_suppress<DATA32,DATA32,16> channel_energy;
  {
  FCNCALL_SUBNAME("channel_energy");
  { FCNCALL_CALL_CTRL_WRAP(channel_energy,channel_energy.FCNCALL_CALL(channel_energy)); }
  FCNCALL_SUBNAME_END;
  }
  // TRACE trace;
  {
  FCNCALL_SUBNAME("trace");
  { FCNCALL_CALL_CTRL_WRAP(trace,trace.FCNCALL_CALL(trace)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_FEBEX_EVENT_TRACES

#ifndef USER_DEF_FEBEX_PADDING
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(FEBEX_PADDING)::FCNCALL_NAME(FEBEX_PADDING)
{
  FCNCALL_INIT;
  FCNCALL_RET;
}
#endif//USER_DEF_FEBEX_PADDING

#ifndef USER_DEF_VME_CAEN_V830
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(VME_CAEN_V830)::FCNCALL_NAME(VME_CAEN_V830)
{
  FCNCALL_INIT;
  // raw_array_zero_suppress<DATA32,DATA32,32> data;
  {
  FCNCALL_SUBNAME("data");
  { FCNCALL_CALL_CTRL_WRAP(data,data.FCNCALL_CALL(data)); }
  FCNCALL_SUBNAME_END;
  }
  // union 
  // {
    // struct 
    // {
      // uint32 event_number : 16;
      // uint32 ts : 2;
      // uint32 count : 6;
      // uint32 undefined : 2;
      // uint32 unnamed_26_26 : 1;
      // uint32 geom : 5;
    // } ;
    // uint32 u32;
  // } header;
  {
  FCNCALL_SUBNAME("header");
#if !STRUCT_ONLY_LAST_UNION_MEMBER
  // struct 
  // {
    // uint32 event_number : 16;
    // uint32 ts : 2;
    // uint32 count : 6;
    // uint32 undefined : 2;
    // uint32 unnamed_26_26 : 1;
    // uint32 geom : 5;
  // } ;
  // uint32 event_number : 16;
  {
  FCNCALL_SUBNAME("event_number");
  { FCNCALL_CALL_CTRL_WRAP(header.event_number,FCNCALL_CALL_TYPE/*_BITFIELD*/(uint32,header.event_number)); }
  FCNCALL_SUBNAME_END;
  }
  // uint32 ts : 2;
  {
  FCNCALL_SUBNAME("ts");
  { FCNCALL_CALL_CTRL_WRAP(header.ts,FCNCALL_CALL_TYPE/*_BITFIELD*/(uint32,header.ts)); }
  FCNCALL_SUBNAME_END;
  }
  // uint32 count : 6;
  {
  FCNCALL_SUBNAME("count");
  { FCNCALL_CALL_CTRL_WRAP(header.count,FCNCALL_CALL_TYPE/*_BITFIELD*/(uint32,header.count)); }
  FCNCALL_SUBNAME_END;
  }
  // uint32 undefined : 2;
  {
  FCNCALL_SUBNAME("undefined");
  { FCNCALL_CALL_CTRL_WRAP(header.undefined,FCNCALL_CALL_TYPE/*_BITFIELD*/(uint32,header.undefined)); }
  FCNCALL_SUBNAME_END;
  }
  // uint32 unnamed_26_26 : 1;
  {
  FCNCALL_SUBNAME("unnamed_26_26");
  { FCNCALL_CALL_CTRL_WRAP(header.unnamed_26_26,FCNCALL_CALL_TYPE/*_BITFIELD*/(uint32,header.unnamed_26_26)); }
  FCNCALL_SUBNAME_END;
  }
  // uint32 geom : 5;
  {
  FCNCALL_SUBNAME("geom");
  { FCNCALL_CALL_CTRL_WRAP(header.geom,FCNCALL_CALL_TYPE/*_BITFIELD*/(uint32,header.geom)); }
  FCNCALL_SUBNAME_END;
  }
#endif// !STRUCT_ONLY_LAST_UNION_MEMBER
  // uint32 u32;
  {
  FCNCALL_SUBNAME("u32");
  { FCNCALL_CALL_CTRL_WRAP(header.u32,FCNCALL_CALL_TYPE(uint32,header.u32)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_VME_CAEN_V830

#ifndef USER_DEF_ZERO_FILLER
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(ZERO_FILLER)::FCNCALL_NAME(ZERO_FILLER)
{
  FCNCALL_INIT;
  FCNCALL_RET;
}
#endif//USER_DEF_ZERO_FILLER

#ifndef USER_DEF_VME_CAEN_V7X5
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(VME_CAEN_V7X5)::FCNCALL_NAME(VME_CAEN_V7X5)
{
  FCNCALL_INIT;
  // raw_array_zero_suppress<DATA24,DATA24,32> data;
  {
  FCNCALL_SUBNAME("data");
  { FCNCALL_CALL_CTRL_WRAP(data,data.FCNCALL_CALL(data)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_VME_CAEN_V7X5

#ifndef USER_DEF_TDC_HEADER
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(TDC_HEADER)::FCNCALL_NAME(TDC_HEADER)
{
  FCNCALL_INIT;
  FCNCALL_RET;
}
#endif//USER_DEF_TDC_HEADER

#ifndef USER_DEF_TDC_DATA_V1290
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(TDC_DATA_V1290)::FCNCALL_NAME(TDC_DATA_V1290)
{
  FCNCALL_INIT;
  // raw_array_multi_zero_suppress<DATA24,DATA24,128,128> data;
  {
  FCNCALL_SUBNAME("data");
  { FCNCALL_CALL_CTRL_WRAP(data,data.FCNCALL_CALL(data)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_array_multi_zero_suppress<DATA8,DATA8,128,128> leadOrTrail;
  {
  FCNCALL_SUBNAME("leadOrTrail");
  { FCNCALL_CALL_CTRL_WRAP(leadOrTrail,leadOrTrail.FCNCALL_CALL(leadOrTrail)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_TDC_DATA_V1290

#ifndef USER_DEF_TDC_ERROR
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(TDC_ERROR)::FCNCALL_NAME(TDC_ERROR)
{
  FCNCALL_INIT;
  FCNCALL_RET;
}
#endif//USER_DEF_TDC_ERROR

#ifndef USER_DEF_TDC_TRAILER
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(TDC_TRAILER)::FCNCALL_NAME(TDC_TRAILER)
{
  FCNCALL_INIT;
  FCNCALL_RET;
}
#endif//USER_DEF_TDC_TRAILER

#ifndef USER_DEF_VME_CAEN_V1290_N
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(VME_CAEN_V1290_N)::FCNCALL_NAME(VME_CAEN_V1290_N)
{
  FCNCALL_INIT;
  // DATA8 geo;
  {
  FCNCALL_SUBNAME("geo");
  { FCNCALL_CALL_CTRL_WRAP(geo,geo.FCNCALL_CALL(geo)); }
  FCNCALL_SUBNAME_END;
  }
  // TDC_HEADER tdc_header;
  {
  FCNCALL_SUBNAME("tdc_header");
  { FCNCALL_CALL_CTRL_WRAP(tdc_header,tdc_header.FCNCALL_CALL(tdc_header)); }
  FCNCALL_SUBNAME_END;
  }
  // TDC_DATA_V1290 measurement;
  {
  FCNCALL_SUBNAME("measurement");
  { FCNCALL_CALL_CTRL_WRAP(measurement,measurement.FCNCALL_CALL(measurement)); }
  FCNCALL_SUBNAME_END;
  }
  // TDC_ERROR tdc_err;
  {
  FCNCALL_SUBNAME("tdc_err");
  { FCNCALL_CALL_CTRL_WRAP(tdc_err,tdc_err.FCNCALL_CALL(tdc_err)); }
  FCNCALL_SUBNAME_END;
  }
  // TDC_TRAILER tdc_trailer;
  {
  FCNCALL_SUBNAME("tdc_trailer");
  { FCNCALL_CALL_CTRL_WRAP(tdc_trailer,tdc_trailer.FCNCALL_CALL(tdc_trailer)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_VME_CAEN_V1290_N

#ifndef USER_DEF_MAIN_CRATE_DATA
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(MAIN_CRATE_DATA)::FCNCALL_NAME(MAIN_CRATE_DATA)
{
  FCNCALL_INIT;
  // BARRIER barrier0;
  {
  FCNCALL_SUBNAME("barrier0");
  { FCNCALL_CALL_CTRL_WRAP(barrier0,barrier0.FCNCALL_CALL(barrier0)); }
  FCNCALL_SUBNAME_END;
  }
  // VME_CAEN_V830 v830;
  {
  FCNCALL_SUBNAME("v830");
  { FCNCALL_CALL_CTRL_WRAP(v830,v830.FCNCALL_CALL(v830)); }
  FCNCALL_SUBNAME_END;
  }
  // ZERO_FILLER filler0;
  {
  FCNCALL_SUBNAME("filler0");
  { FCNCALL_CALL_CTRL_WRAP(filler0,filler0.FCNCALL_CALL(filler0)); }
  FCNCALL_SUBNAME_END;
  }
  // BARRIER barrier1;
  {
  FCNCALL_SUBNAME("barrier1");
  { FCNCALL_CALL_CTRL_WRAP(barrier1,barrier1.FCNCALL_CALL(barrier1)); }
  FCNCALL_SUBNAME_END;
  }
  // VME_CAEN_V7X5 v792;
  {
  FCNCALL_SUBNAME("v792");
  { FCNCALL_CALL_CTRL_WRAP(v792,v792.FCNCALL_CALL(v792)); }
  FCNCALL_SUBNAME_END;
  }
  // BARRIER barrier2;
  {
  FCNCALL_SUBNAME("barrier2");
  { FCNCALL_CALL_CTRL_WRAP(barrier2,barrier2.FCNCALL_CALL(barrier2)); }
  FCNCALL_SUBNAME_END;
  }
  // VME_CAEN_V1290_N v1290;
  {
  FCNCALL_SUBNAME("v1290");
  { FCNCALL_CALL_CTRL_WRAP(v1290,v1290.FCNCALL_CALL(v1290)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_MAIN_CRATE_DATA

#ifndef USER_DEF_SPILL_OFF
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(SPILL_OFF)::FCNCALL_NAME(SPILL_OFF)
{
  FCNCALL_INIT;
  // DATA8 spilloff;
  {
  FCNCALL_SUBNAME("spilloff");
  { FCNCALL_CALL_CTRL_WRAP(spilloff,spilloff.FCNCALL_CALL(spilloff)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_SPILL_OFF

#ifndef USER_DEF_SPILL_ON
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(SPILL_ON)::FCNCALL_NAME(SPILL_ON)
{
  FCNCALL_INIT;
  // DATA8 spillon;
  {
  FCNCALL_SUBNAME("spillon");
  { FCNCALL_CALL_CTRL_WRAP(spillon,spillon.FCNCALL_CALL(spillon)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_SPILL_ON

#ifndef USER_DEF_TAMEX4_EPOCH_DATA
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(TAMEX4_EPOCH_DATA)::FCNCALL_NAME(TAMEX4_EPOCH_DATA)
{
  FCNCALL_INIT;
  FCNCALL_RET;
}
#endif//USER_DEF_TAMEX4_EPOCH_DATA

#ifndef USER_DEF_TAMEX4_HEADER
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(TAMEX4_HEADER)::FCNCALL_NAME(TAMEX4_HEADER)
{
  FCNCALL_INIT;
  // DATA16 post_trig_ns;
  {
  FCNCALL_SUBNAME("post_trig_ns");
  { FCNCALL_CALL_CTRL_WRAP(post_trig_ns,post_trig_ns.FCNCALL_CALL(post_trig_ns)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA16 pre_trig_ns;
  {
  FCNCALL_SUBNAME("pre_trig_ns");
  { FCNCALL_CALL_CTRL_WRAP(pre_trig_ns,pre_trig_ns.FCNCALL_CALL(pre_trig_ns)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_TAMEX4_HEADER

#ifndef USER_DEF_TAMEX4_PADDING
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(TAMEX4_PADDING)::FCNCALL_NAME(TAMEX4_PADDING)
{
  FCNCALL_INIT;
  FCNCALL_RET;
}
#endif//USER_DEF_TAMEX4_PADDING

#ifndef USER_DEF_TAMEX4_TIME_DATA
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(TAMEX4_TIME_DATA)::FCNCALL_NAME(TAMEX4_TIME_DATA)
{
  FCNCALL_INIT;
  FCNCALL_RET;
}
#endif//USER_DEF_TAMEX4_TIME_DATA

#ifndef USER_DEF_TAMEX4_SFP
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(TAMEX4_SFP)::FCNCALL_NAME(TAMEX4_SFP)
{
  FCNCALL_INIT;
  // DATA16 trig;
  {
  FCNCALL_SUBNAME("trig");
  { FCNCALL_CALL_CTRL_WRAP(trig,trig.FCNCALL_CALL(trig)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA32 event_size;
  {
  FCNCALL_SUBNAME("event_size");
  { FCNCALL_CALL_CTRL_WRAP(event_size,event_size.FCNCALL_CALL(event_size)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_list_ii_zero_suppress<DATA12,DATA12,1024> time_coarse;
  {
  FCNCALL_SUBNAME("time_coarse");
  { FCNCALL_CALL_CTRL_WRAP(time_coarse,time_coarse.FCNCALL_CALL(time_coarse)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_list_ii_zero_suppress<DATA12,DATA12,1024> time_fine;
  {
  FCNCALL_SUBNAME("time_fine");
  { FCNCALL_CALL_CTRL_WRAP(time_fine,time_fine.FCNCALL_CALL(time_fine)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_list_ii_zero_suppress<DATA12,DATA12,1024> time_edge;
  {
  FCNCALL_SUBNAME("time_edge");
  { FCNCALL_CALL_CTRL_WRAP(time_edge,time_edge.FCNCALL_CALL(time_edge)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_list_ii_zero_suppress<DATA12,DATA12,1024> time_channel;
  {
  FCNCALL_SUBNAME("time_channel");
  { FCNCALL_CALL_CTRL_WRAP(time_channel,time_channel.FCNCALL_CALL(time_channel)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_list_ii_zero_suppress<DATA32,DATA32,1024> time_epoch;
  {
  FCNCALL_SUBNAME("time_epoch");
  { FCNCALL_CALL_CTRL_WRAP(time_epoch,time_epoch.FCNCALL_CALL(time_epoch)); }
  FCNCALL_SUBNAME_END;
  }
  // TAMEX4_EPOCH_DATA epoch;
  {
  FCNCALL_SUBNAME("epoch");
  { FCNCALL_CALL_CTRL_WRAP(epoch,epoch.FCNCALL_CALL(epoch)); }
  FCNCALL_SUBNAME_END;
  }
  // TAMEX4_TIME_DATA time;
  {
  FCNCALL_SUBNAME("time");
  { FCNCALL_CALL_CTRL_WRAP(time,time.FCNCALL_CALL(time)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_TAMEX4_SFP

#ifndef USER_DEF_TDC_DATA_V1190
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(TDC_DATA_V1190)::FCNCALL_NAME(TDC_DATA_V1190)
{
  FCNCALL_INIT;
  // raw_array_multi_zero_suppress<DATA24,DATA24,128,128> data;
  {
  FCNCALL_SUBNAME("data");
  { FCNCALL_CALL_CTRL_WRAP(data,data.FCNCALL_CALL(data)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_array_multi_zero_suppress<DATA8,DATA8,128,128> leadOrTrail;
  {
  FCNCALL_SUBNAME("leadOrTrail");
  { FCNCALL_CALL_CTRL_WRAP(leadOrTrail,leadOrTrail.FCNCALL_CALL(leadOrTrail)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_TDC_DATA_V1190

#ifndef USER_DEF_TIMESTAMP_WHITERABBIT
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(TIMESTAMP_WHITERABBIT)::FCNCALL_NAME(TIMESTAMP_WHITERABBIT)
{
  FCNCALL_INIT;
  // DATA12 subsystem_id;
  {
  FCNCALL_SUBNAME("subsystem_id");
  { FCNCALL_CALL_CTRL_WRAP(subsystem_id,subsystem_id.FCNCALL_CALL(subsystem_id)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA16 t1;
  {
  FCNCALL_SUBNAME("t1");
  { FCNCALL_CALL_CTRL_WRAP(t1,t1.FCNCALL_CALL(t1)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA16 t2;
  {
  FCNCALL_SUBNAME("t2");
  { FCNCALL_CALL_CTRL_WRAP(t2,t2.FCNCALL_CALL(t2)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA16 t3;
  {
  FCNCALL_SUBNAME("t3");
  { FCNCALL_CALL_CTRL_WRAP(t3,t3.FCNCALL_CALL(t3)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA16 t4;
  {
  FCNCALL_SUBNAME("t4");
  { FCNCALL_CALL_CTRL_WRAP(t4,t4.FCNCALL_CALL(t4)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_TIMESTAMP_WHITERABBIT

#ifndef USER_DEF_TIMESTAMP_WHITERABBIT_EXTENDED
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(TIMESTAMP_WHITERABBIT_EXTENDED)::FCNCALL_NAME(TIMESTAMP_WHITERABBIT_EXTENDED)
{
  FCNCALL_INIT;
  // DATA16 subsystem_id;
  {
  FCNCALL_SUBNAME("subsystem_id");
  { FCNCALL_CALL_CTRL_WRAP(subsystem_id,subsystem_id.FCNCALL_CALL(subsystem_id)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA16 t1;
  {
  FCNCALL_SUBNAME("t1");
  { FCNCALL_CALL_CTRL_WRAP(t1,t1.FCNCALL_CALL(t1)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA16 t2;
  {
  FCNCALL_SUBNAME("t2");
  { FCNCALL_CALL_CTRL_WRAP(t2,t2.FCNCALL_CALL(t2)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA16 t3;
  {
  FCNCALL_SUBNAME("t3");
  { FCNCALL_CALL_CTRL_WRAP(t3,t3.FCNCALL_CALL(t3)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA16 t4;
  {
  FCNCALL_SUBNAME("t4");
  { FCNCALL_CALL_CTRL_WRAP(t4,t4.FCNCALL_CALL(t4)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_TIMESTAMP_WHITERABBIT_EXTENDED

#ifndef USER_DEF_TPAT_CRATE_DATA
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(TPAT_CRATE_DATA)::FCNCALL_NAME(TPAT_CRATE_DATA)
{
  FCNCALL_INIT;
  // DATA16 tpat;
  {
  FCNCALL_SUBNAME("tpat");
  { FCNCALL_CALL_CTRL_WRAP(tpat,tpat.FCNCALL_CALL(tpat)); }
  FCNCALL_SUBNAME_END;
  }
  // uint32 w1;
  {
  FCNCALL_SUBNAME("w1");
  { FCNCALL_CALL_CTRL_WRAP(w1,FCNCALL_CALL_TYPE(uint32,w1)); }
  FCNCALL_SUBNAME_END;
  }
  // uint32 w2;
  {
  FCNCALL_SUBNAME("w2");
  { FCNCALL_CALL_CTRL_WRAP(w2,FCNCALL_CALL_TYPE(uint32,w2)); }
  FCNCALL_SUBNAME_END;
  }
  // uint32 w3;
  {
  FCNCALL_SUBNAME("w3");
  { FCNCALL_CALL_CTRL_WRAP(w3,FCNCALL_CALL_TYPE(uint32,w3)); }
  FCNCALL_SUBNAME_END;
  }
  // union 
  // {
    // struct 
    // {
      // uint32 pattern : 16;
      // uint32 nothing : 16;
    // } ;
    // uint32 u32;
  // } trigger_pattern;
  {
  FCNCALL_SUBNAME("trigger_pattern");
#if !STRUCT_ONLY_LAST_UNION_MEMBER
  // struct 
  // {
    // uint32 pattern : 16;
    // uint32 nothing : 16;
  // } ;
  // uint32 pattern : 16;
  {
  FCNCALL_SUBNAME("pattern");
  { FCNCALL_CALL_CTRL_WRAP(trigger_pattern.pattern,FCNCALL_CALL_TYPE/*_BITFIELD*/(uint32,trigger_pattern.pattern)); }
  FCNCALL_SUBNAME_END;
  }
  // uint32 nothing : 16;
  {
  FCNCALL_SUBNAME("nothing");
  { FCNCALL_CALL_CTRL_WRAP(trigger_pattern.nothing,FCNCALL_CALL_TYPE/*_BITFIELD*/(uint32,trigger_pattern.nothing)); }
  FCNCALL_SUBNAME_END;
  }
#endif// !STRUCT_ONLY_LAST_UNION_MEMBER
  // uint32 u32;
  {
  FCNCALL_SUBNAME("u32");
  { FCNCALL_CALL_CTRL_WRAP(trigger_pattern.u32,FCNCALL_CALL_TYPE(uint32,trigger_pattern.u32)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_TPAT_CRATE_DATA

#ifndef USER_DEF_VME_CAEN_V1190_N
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(VME_CAEN_V1190_N)::FCNCALL_NAME(VME_CAEN_V1190_N)
{
  FCNCALL_INIT;
  // DATA8 geo;
  {
  FCNCALL_SUBNAME("geo");
  { FCNCALL_CALL_CTRL_WRAP(geo,geo.FCNCALL_CALL(geo)); }
  FCNCALL_SUBNAME_END;
  }
  // TDC_HEADER tdc_header;
  {
  FCNCALL_SUBNAME("tdc_header");
  { FCNCALL_CALL_CTRL_WRAP(tdc_header,tdc_header.FCNCALL_CALL(tdc_header)); }
  FCNCALL_SUBNAME_END;
  }
  // TDC_DATA_V1190 measurement;
  {
  FCNCALL_SUBNAME("measurement");
  { FCNCALL_CALL_CTRL_WRAP(measurement,measurement.FCNCALL_CALL(measurement)); }
  FCNCALL_SUBNAME_END;
  }
  // TDC_ERROR tdc_error;
  {
  FCNCALL_SUBNAME("tdc_error");
  { FCNCALL_CALL_CTRL_WRAP(tdc_error,tdc_error.FCNCALL_CALL(tdc_error)); }
  FCNCALL_SUBNAME_END;
  }
  // TDC_TRAILER tdc_trailer;
  {
  FCNCALL_SUBNAME("tdc_trailer");
  { FCNCALL_CALL_CTRL_WRAP(tdc_trailer,tdc_trailer.FCNCALL_CALL(tdc_trailer)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_VME_CAEN_V1190_N

#ifndef USER_DEF_TPC_CRATE_DATA
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(TPC_CRATE_DATA)::FCNCALL_NAME(TPC_CRATE_DATA)
{
  FCNCALL_INIT;
  // BARRIER barrier0;
  {
  FCNCALL_SUBNAME("barrier0");
  { FCNCALL_CALL_CTRL_WRAP(barrier0,barrier0.FCNCALL_CALL(barrier0)); }
  FCNCALL_SUBNAME_END;
  }
  // VME_CAEN_V7X5 v785;
  {
  FCNCALL_SUBNAME("v785");
  { FCNCALL_CALL_CTRL_WRAP(v785,v785.FCNCALL_CALL(v785)); }
  FCNCALL_SUBNAME_END;
  }
  // VME_CAEN_V7X5 v775;
  {
  FCNCALL_SUBNAME("v775");
  { FCNCALL_CALL_CTRL_WRAP(v775,v775.FCNCALL_CALL(v775)); }
  FCNCALL_SUBNAME_END;
  }
  // BARRIER barrier[3];
  {
  FCNCALL_SUBNAME("barrier");
  FCNCALL_FOR(__i0,3)
  {
    FCNCALL_SUBINDEX(__i0);
    { FCNCALL_CALL_CTRL_WRAP_ARRAY(barrier__i0,,__i0,barrier[__i0].FCNCALL_CALL(barrier[__i0])); }
    FCNCALL_SUBINDEX_END(__i0);
  }
  FCNCALL_SUBNAME_END;
  }
  // VME_CAEN_V1190_N v1190;
  {
  FCNCALL_SUBNAME("v1190");
  { FCNCALL_CALL_CTRL_WRAP(v1190,v1190.FCNCALL_CALL(v1190)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_TPC_CRATE_DATA

#ifndef USER_DEF_TRIG3EVENT
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(TRIG3EVENT)::FCNCALL_NAME(TRIG3EVENT)
{
  FCNCALL_INIT;
  FCNCALL_RET;
}
#endif//USER_DEF_TRIG3EVENT

#ifndef USER_DEF_USER_CRATE_DATA
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(USER_CRATE_DATA)::FCNCALL_NAME(USER_CRATE_DATA)
{
  FCNCALL_INIT;
  // BARRIER barrier1;
  {
  FCNCALL_SUBNAME("barrier1");
  { FCNCALL_CALL_CTRL_WRAP(barrier1,barrier1.FCNCALL_CALL(barrier1)); }
  FCNCALL_SUBNAME_END;
  }
  // VME_CAEN_V7X5 v775[2];
  {
  FCNCALL_SUBNAME("v775");
  FCNCALL_FOR(__i0,2)
  {
    FCNCALL_SUBINDEX(__i0);
    { FCNCALL_CALL_CTRL_WRAP_ARRAY(v775__i0,,__i0,v775[__i0].FCNCALL_CALL(v775[__i0])); }
    FCNCALL_SUBINDEX_END(__i0);
  }
  FCNCALL_SUBNAME_END;
  }
  // VME_CAEN_V7X5 v785[2];
  {
  FCNCALL_SUBNAME("v785");
  FCNCALL_FOR(__i0,2)
  {
    FCNCALL_SUBINDEX(__i0);
    { FCNCALL_CALL_CTRL_WRAP_ARRAY(v785__i0,,__i0,v785[__i0].FCNCALL_CALL(v785[__i0])); }
    FCNCALL_SUBINDEX_END(__i0);
  }
  FCNCALL_SUBNAME_END;
  }
  // BARRIER barrier0;
  {
  FCNCALL_SUBNAME("barrier0");
  { FCNCALL_CALL_CTRL_WRAP(barrier0,barrier0.FCNCALL_CALL(barrier0)); }
  FCNCALL_SUBNAME_END;
  }
  // VME_CAEN_V830 v830;
  {
  FCNCALL_SUBNAME("v830");
  { FCNCALL_CALL_CTRL_WRAP(v830,v830.FCNCALL_CALL(v830)); }
  FCNCALL_SUBNAME_END;
  }
  // ZERO_FILLER filler0;
  {
  FCNCALL_SUBNAME("filler0");
  { FCNCALL_CALL_CTRL_WRAP(filler0,filler0.FCNCALL_CALL(filler0)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_USER_CRATE_DATA

#ifndef USER_DEF_VME_CAEN_V1751
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(VME_CAEN_V1751)::FCNCALL_NAME(VME_CAEN_V1751)
{
  FCNCALL_INIT;
  // DATA8 board_id;
  {
  FCNCALL_SUBNAME("board_id");
  { FCNCALL_CALL_CTRL_WRAP(board_id,board_id.FCNCALL_CALL(board_id)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA8 channels;
  {
  FCNCALL_SUBNAME("channels");
  { FCNCALL_CALL_CTRL_WRAP(channels,channels.FCNCALL_CALL(channels)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA32 board_time;
  {
  FCNCALL_SUBNAME("board_time");
  { FCNCALL_CALL_CTRL_WRAP(board_time,board_time.FCNCALL_CALL(board_time)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_list_ii_zero_suppress<DATA32,DATA32,64> channel_time;
  {
  FCNCALL_SUBNAME("channel_time");
  { FCNCALL_CALL_CTRL_WRAP(channel_time,channel_time.FCNCALL_CALL(channel_time)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_list_ii_zero_suppress<DATA16,DATA16,64> chan_ext_time;
  {
  FCNCALL_SUBNAME("chan_ext_time");
  { FCNCALL_CALL_CTRL_WRAP(chan_ext_time,chan_ext_time.FCNCALL_CALL(chan_ext_time)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_list_ii_zero_suppress<DATA12,DATA12,64> chan_fine_time;
  {
  FCNCALL_SUBNAME("chan_fine_time");
  { FCNCALL_CALL_CTRL_WRAP(chan_fine_time,chan_fine_time.FCNCALL_CALL(chan_fine_time)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_list_ii_zero_suppress<DATA16,DATA16,64> qshort;
  {
  FCNCALL_SUBNAME("qshort");
  { FCNCALL_CALL_CTRL_WRAP(qshort,qshort.FCNCALL_CALL(qshort)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_list_ii_zero_suppress<DATA16,DATA16,64> qlong;
  {
  FCNCALL_SUBNAME("qlong");
  { FCNCALL_CALL_CTRL_WRAP(qlong,qlong.FCNCALL_CALL(qlong)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_VME_CAEN_V1751

#ifndef USER_DEF_WR_MULTI
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(WR_MULTI)::FCNCALL_NAME(WR_MULTI)
{
  FCNCALL_INIT;
  // DATA32 time_hi;
  {
  FCNCALL_SUBNAME("time_hi");
  { FCNCALL_CALL_CTRL_WRAP(time_hi,time_hi.FCNCALL_CALL(time_hi)); }
  FCNCALL_SUBNAME_END;
  }
  // DATA32 time_lo;
  {
  FCNCALL_SUBNAME("time_lo");
  { FCNCALL_CALL_CTRL_WRAP(time_lo,time_lo.FCNCALL_CALL(time_lo)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_WR_MULTI

#ifndef USER_DEF_aida_subev
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(aida_subev)::FCNCALL_NAME(aida_subev)
{
  FCNCALL_INIT;
  FCNCALL_CALL_CTRL_WRAP(unpack_subevent_base,FCNCALL_CLASS_NAME(unpack_subevent_base)::FCNCALL_CALL_BASE());
  // TIMESTAMP_WHITERABBIT ts;
  {
  FCNCALL_SUBNAME("ts");
  { FCNCALL_CALL_CTRL_WRAP(ts,ts.FCNCALL_CALL(ts)); }
  FCNCALL_SUBNAME_END;
  }
  // EXT_AIDA data;
  {
  FCNCALL_SUBNAME("data");
  { FCNCALL_CALL_CTRL_WRAP(data,data.FCNCALL_CALL(data)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_aida_subev

#ifndef USER_DEF_bgo_tamex_subevent
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(bgo_tamex_subevent)::FCNCALL_NAME(bgo_tamex_subevent)
{
  FCNCALL_INIT;
  FCNCALL_CALL_CTRL_WRAP(unpack_subevent_base,FCNCALL_CLASS_NAME(unpack_subevent_base)::FCNCALL_CALL_BASE());
  // TIMESTAMP_WHITERABBIT_EXTENDED ts;
  {
  FCNCALL_SUBNAME("ts");
  { FCNCALL_CALL_CTRL_WRAP(ts,ts.FCNCALL_CALL(ts)); }
  FCNCALL_SUBNAME_END;
  }
  // union 
  // {
    // struct 
    // {
      // uint32 b : 32;
    // } ;
    // uint32 u32;
  // } be;
  {
  FCNCALL_SUBNAME("be");
#if !STRUCT_ONLY_LAST_UNION_MEMBER
  // struct 
  // {
    // uint32 b : 32;
  // } ;
  // uint32 b : 32;
  {
  FCNCALL_SUBNAME("b");
  { FCNCALL_CALL_CTRL_WRAP(be.b,FCNCALL_CALL_TYPE/*_BITFIELD*/(uint32,be.b)); }
  FCNCALL_SUBNAME_END;
  }
#endif// !STRUCT_ONLY_LAST_UNION_MEMBER
  // uint32 u32;
  {
  FCNCALL_SUBNAME("u32");
  { FCNCALL_CALL_CTRL_WRAP(be.u32,FCNCALL_CALL_TYPE(uint32,be.u32)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_SUBNAME_END;
  }
  // TAMEX4_HEADER trigger_window;
  {
  FCNCALL_SUBNAME("trigger_window");
  { FCNCALL_CALL_CTRL_WRAP(trigger_window,trigger_window.FCNCALL_CALL(trigger_window)); }
  FCNCALL_SUBNAME_END;
  }
  // TAMEX4_PADDING padding;
  {
  FCNCALL_SUBNAME("padding");
  { FCNCALL_CALL_CTRL_WRAP(padding,padding.FCNCALL_CALL(padding)); }
  FCNCALL_SUBNAME_END;
  }
  // TAMEX4_SFP tamex[3];
  {
  FCNCALL_SUBNAME("tamex");
  FCNCALL_FOR(__i0,3)
  {
    FCNCALL_SUBINDEX(__i0);
    { FCNCALL_CALL_CTRL_WRAP_ARRAY(tamex__i0,,__i0,tamex[__i0].FCNCALL_CALL(tamex[__i0])); }
    FCNCALL_SUBINDEX_END(__i0);
  }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_bgo_tamex_subevent

#ifndef USER_DEF_bm_subev
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(bm_subev)::FCNCALL_NAME(bm_subev)
{
  FCNCALL_INIT;
  FCNCALL_CALL_CTRL_WRAP(unpack_subevent_base,FCNCALL_CLASS_NAME(unpack_subevent_base)::FCNCALL_CALL_BASE());
  // raw_list_ii_zero_suppress<DATA32,DATA32,100000> dataS2;
  {
  FCNCALL_SUBNAME("dataS2");
  { FCNCALL_CALL_CTRL_WRAP(dataS2,dataS2.FCNCALL_CALL(dataS2)); }
  FCNCALL_SUBNAME_END;
  }
  // raw_list_ii_zero_suppress<DATA32,DATA32,100000> dataS4;
  {
  FCNCALL_SUBNAME("dataS4");
  { FCNCALL_CALL_CTRL_WRAP(dataS4,dataS4.FCNCALL_CALL(dataS4)); }
  FCNCALL_SUBNAME_END;
  }
  // TIMESTAMP_WHITERABBIT_EXTENDED ts;
  {
  FCNCALL_SUBNAME("ts");
  { FCNCALL_CALL_CTRL_WRAP(ts,ts.FCNCALL_CALL(ts)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_bm_subev

#ifndef USER_DEF_bplast_subev
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(bplast_subev)::FCNCALL_NAME(bplast_subev)
{
  FCNCALL_INIT;
  FCNCALL_CALL_CTRL_WRAP(unpack_subevent_base,FCNCALL_CLASS_NAME(unpack_subevent_base)::FCNCALL_CALL_BASE());
  // TIMESTAMP_WHITERABBIT ts;
  {
  FCNCALL_SUBNAME("ts");
  { FCNCALL_CALL_CTRL_WRAP(ts,ts.FCNCALL_CALL(ts)); }
  FCNCALL_SUBNAME_END;
  }
  // TAMEX4_HEADER trigger_window;
  {
  FCNCALL_SUBNAME("trigger_window");
  { FCNCALL_CALL_CTRL_WRAP(trigger_window,trigger_window.FCNCALL_CALL(trigger_window)); }
  FCNCALL_SUBNAME_END;
  }
  // TAMEX4_PADDING padding;
  {
  FCNCALL_SUBNAME("padding");
  { FCNCALL_CALL_CTRL_WRAP(padding,padding.FCNCALL_CALL(padding)); }
  FCNCALL_SUBNAME_END;
  }
  // TAMEX4_SFP tamex[9];
  {
  FCNCALL_SUBNAME("tamex");
  FCNCALL_FOR(__i0,9)
  {
    FCNCALL_SUBINDEX(__i0);
    { FCNCALL_CALL_CTRL_WRAP_ARRAY(tamex__i0,,__i0,tamex[__i0].FCNCALL_CALL(tamex[__i0])); }
    FCNCALL_SUBINDEX_END(__i0);
  }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_bplast_subev

#ifndef USER_DEF_fatima_tamex_subev
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(fatima_tamex_subev)::FCNCALL_NAME(fatima_tamex_subev)
{
  FCNCALL_INIT;
  FCNCALL_CALL_CTRL_WRAP(unpack_subevent_base,FCNCALL_CLASS_NAME(unpack_subevent_base)::FCNCALL_CALL_BASE());
  // TIMESTAMP_WHITERABBIT_EXTENDED ts;
  {
  FCNCALL_SUBNAME("ts");
  { FCNCALL_CALL_CTRL_WRAP(ts,ts.FCNCALL_CALL(ts)); }
  FCNCALL_SUBNAME_END;
  }
  // TAMEX4_HEADER trigger_window;
  {
  FCNCALL_SUBNAME("trigger_window");
  { FCNCALL_CALL_CTRL_WRAP(trigger_window,trigger_window.FCNCALL_CALL(trigger_window)); }
  FCNCALL_SUBNAME_END;
  }
  // TAMEX4_PADDING padding;
  {
  FCNCALL_SUBNAME("padding");
  { FCNCALL_CALL_CTRL_WRAP(padding,padding.FCNCALL_CALL(padding)); }
  FCNCALL_SUBNAME_END;
  }
  // TAMEX4_SFP tamex[4];
  {
  FCNCALL_SUBNAME("tamex");
  FCNCALL_FOR(__i0,4)
  {
    FCNCALL_SUBINDEX(__i0);
    { FCNCALL_CALL_CTRL_WRAP_ARRAY(tamex__i0,,__i0,tamex[__i0].FCNCALL_CALL(tamex[__i0])); }
    FCNCALL_SUBINDEX_END(__i0);
  }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_fatima_tamex_subev

#ifndef USER_DEF_fatima_vme_subev
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(fatima_vme_subev)::FCNCALL_NAME(fatima_vme_subev)
{
  FCNCALL_INIT;
  FCNCALL_CALL_CTRL_WRAP(unpack_subevent_base,FCNCALL_CLASS_NAME(unpack_subevent_base)::FCNCALL_CALL_BASE());
  // TIMESTAMP_WHITERABBIT_EXTENDED ts;
  {
  FCNCALL_SUBNAME("ts");
  { FCNCALL_CALL_CTRL_WRAP(ts,ts.FCNCALL_CALL(ts)); }
  FCNCALL_SUBNAME_END;
  }
  // ERR_WORD_SIX error1;
  {
  FCNCALL_SUBNAME("error1");
  { FCNCALL_CALL_CTRL_WRAP(error1,error1.FCNCALL_CALL(error1)); }
  FCNCALL_SUBNAME_END;
  }
  // FATIMA_VME_SCALERS scalers;
  {
  FCNCALL_SUBNAME("scalers");
  { FCNCALL_CALL_CTRL_WRAP(scalers,scalers.FCNCALL_CALL(scalers)); }
  FCNCALL_SUBNAME_END;
  }
  // VME_CAEN_V1751 qdc1;
  {
  FCNCALL_SUBNAME("qdc1");
  { FCNCALL_CALL_CTRL_WRAP(qdc1,qdc1.FCNCALL_CALL(qdc1)); }
  FCNCALL_SUBNAME_END;
  }
  // VME_CAEN_V1751 qdc2;
  {
  FCNCALL_SUBNAME("qdc2");
  { FCNCALL_CALL_CTRL_WRAP(qdc2,qdc2.FCNCALL_CALL(qdc2)); }
  FCNCALL_SUBNAME_END;
  }
  // VME_CAEN_V1751 qdc3;
  {
  FCNCALL_SUBNAME("qdc3");
  { FCNCALL_CALL_CTRL_WRAP(qdc3,qdc3.FCNCALL_CALL(qdc3)); }
  FCNCALL_SUBNAME_END;
  }
  // VME_CAEN_V1751 qdc4;
  {
  FCNCALL_SUBNAME("qdc4");
  { FCNCALL_CALL_CTRL_WRAP(qdc4,qdc4.FCNCALL_CALL(qdc4)); }
  FCNCALL_SUBNAME_END;
  }
  // VME_CAEN_V1751 qdc5;
  {
  FCNCALL_SUBNAME("qdc5");
  { FCNCALL_CALL_CTRL_WRAP(qdc5,qdc5.FCNCALL_CALL(qdc5)); }
  FCNCALL_SUBNAME_END;
  }
  // ERR_WORD_SIX error2;
  {
  FCNCALL_SUBNAME("error2");
  { FCNCALL_CALL_CTRL_WRAP(error2,error2.FCNCALL_CALL(error2)); }
  FCNCALL_SUBNAME_END;
  }
  // VME_CAEN_V1290_N tdc1;
  {
  FCNCALL_SUBNAME("tdc1");
  { FCNCALL_CALL_CTRL_WRAP(tdc1,tdc1.FCNCALL_CALL(tdc1)); }
  FCNCALL_SUBNAME_END;
  }
  // ERR_WORD_SIX error3;
  {
  FCNCALL_SUBNAME("error3");
  { FCNCALL_CALL_CTRL_WRAP(error3,error3.FCNCALL_CALL(error3)); }
  FCNCALL_SUBNAME_END;
  }
  // VME_CAEN_V1290_N tdc2;
  {
  FCNCALL_SUBNAME("tdc2");
  { FCNCALL_CALL_CTRL_WRAP(tdc2,tdc2.FCNCALL_CALL(tdc2)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_fatima_vme_subev

#ifndef USER_DEF_febex_subev
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(febex_subev)::FCNCALL_NAME(febex_subev)
{
  FCNCALL_INIT;
  FCNCALL_CALL_CTRL_WRAP(unpack_subevent_base,FCNCALL_CLASS_NAME(unpack_subevent_base)::FCNCALL_CALL_BASE());
  // TIMESTAMP_WHITERABBIT ts;
  {
  FCNCALL_SUBNAME("ts");
  { FCNCALL_CALL_CTRL_WRAP(ts,ts.FCNCALL_CALL(ts)); }
  FCNCALL_SUBNAME_END;
  }
  // FEBEX_PADDING padding;
  {
  FCNCALL_SUBNAME("padding");
  { FCNCALL_CALL_CTRL_WRAP(padding,padding.FCNCALL_CALL(padding)); }
  FCNCALL_SUBNAME_END;
  }
  // FEBEX_EVENT data[4];
  {
  FCNCALL_SUBNAME("data");
  FCNCALL_FOR(__i0,4)
  {
    FCNCALL_SUBINDEX(__i0);
    { FCNCALL_CALL_CTRL_WRAP_ARRAY(data__i0,,__i0,data[__i0].FCNCALL_CALL(data[__i0])); }
    FCNCALL_SUBINDEX_END(__i0);
  }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_febex_subev

#ifndef USER_DEF_frs_main_subev
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(frs_main_subev)::FCNCALL_NAME(frs_main_subev)
{
  FCNCALL_INIT;
  FCNCALL_CALL_CTRL_WRAP(unpack_subevent_base,FCNCALL_CLASS_NAME(unpack_subevent_base)::FCNCALL_CALL_BASE());
  // TRIG3EVENT trig3;
  {
  FCNCALL_SUBNAME("trig3");
  { FCNCALL_CALL_CTRL_WRAP(trig3,trig3.FCNCALL_CALL(trig3)); }
  FCNCALL_SUBNAME_END;
  }
  // SPILL_ON spill_on;
  {
  FCNCALL_SUBNAME("spill_on");
  { FCNCALL_CALL_CTRL_WRAP(spill_on,spill_on.FCNCALL_CALL(spill_on)); }
  FCNCALL_SUBNAME_END;
  }
  // SPILL_OFF spill_off;
  {
  FCNCALL_SUBNAME("spill_off");
  { FCNCALL_CALL_CTRL_WRAP(spill_off,spill_off.FCNCALL_CALL(spill_off)); }
  FCNCALL_SUBNAME_END;
  }
  // MAIN_CRATE_DATA data;
  {
  FCNCALL_SUBNAME("data");
  { FCNCALL_CALL_CTRL_WRAP(data,data.FCNCALL_CALL(data)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_frs_main_subev

#ifndef USER_DEF_frs_tpat_subev
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(frs_tpat_subev)::FCNCALL_NAME(frs_tpat_subev)
{
  FCNCALL_INIT;
  FCNCALL_CALL_CTRL_WRAP(unpack_subevent_base,FCNCALL_CLASS_NAME(unpack_subevent_base)::FCNCALL_CALL_BASE());
  // TIMESTAMP_WHITERABBIT wr;
  {
  FCNCALL_SUBNAME("wr");
  { FCNCALL_CALL_CTRL_WRAP(wr,wr.FCNCALL_CALL(wr)); }
  FCNCALL_SUBNAME_END;
  }
  // TRIG3EVENT trig3;
  {
  FCNCALL_SUBNAME("trig3");
  { FCNCALL_CALL_CTRL_WRAP(trig3,trig3.FCNCALL_CALL(trig3)); }
  FCNCALL_SUBNAME_END;
  }
  // TPAT_CRATE_DATA data;
  {
  FCNCALL_SUBNAME("data");
  { FCNCALL_CALL_CTRL_WRAP(data,data.FCNCALL_CALL(data)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_frs_tpat_subev

#ifndef USER_DEF_frs_tpc_subev
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(frs_tpc_subev)::FCNCALL_NAME(frs_tpc_subev)
{
  FCNCALL_INIT;
  FCNCALL_CALL_CTRL_WRAP(unpack_subevent_base,FCNCALL_CLASS_NAME(unpack_subevent_base)::FCNCALL_CALL_BASE());
  // union 
  // {
    // struct 
    // {
      // uint32 b : 32;
    // } ;
    // uint32 u32;
  // } be;
  {
  FCNCALL_SUBNAME("be");
#if !STRUCT_ONLY_LAST_UNION_MEMBER
  // struct 
  // {
    // uint32 b : 32;
  // } ;
  // uint32 b : 32;
  {
  FCNCALL_SUBNAME("b");
  { FCNCALL_CALL_CTRL_WRAP(be.b,FCNCALL_CALL_TYPE/*_BITFIELD*/(uint32,be.b)); }
  FCNCALL_SUBNAME_END;
  }
#endif// !STRUCT_ONLY_LAST_UNION_MEMBER
  // uint32 u32;
  {
  FCNCALL_SUBNAME("u32");
  { FCNCALL_CALL_CTRL_WRAP(be.u32,FCNCALL_CALL_TYPE(uint32,be.u32)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_SUBNAME_END;
  }
  // TRIG3EVENT trig3;
  {
  FCNCALL_SUBNAME("trig3");
  { FCNCALL_CALL_CTRL_WRAP(trig3,trig3.FCNCALL_CALL(trig3)); }
  FCNCALL_SUBNAME_END;
  }
  // SPILL_ON spill_on;
  {
  FCNCALL_SUBNAME("spill_on");
  { FCNCALL_CALL_CTRL_WRAP(spill_on,spill_on.FCNCALL_CALL(spill_on)); }
  FCNCALL_SUBNAME_END;
  }
  // SPILL_OFF spill_off;
  {
  FCNCALL_SUBNAME("spill_off");
  { FCNCALL_CALL_CTRL_WRAP(spill_off,spill_off.FCNCALL_CALL(spill_off)); }
  FCNCALL_SUBNAME_END;
  }
  // TPC_CRATE_DATA data;
  {
  FCNCALL_SUBNAME("data");
  { FCNCALL_CALL_CTRL_WRAP(data,data.FCNCALL_CALL(data)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_frs_tpc_subev

#ifndef USER_DEF_frs_user_subev
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(frs_user_subev)::FCNCALL_NAME(frs_user_subev)
{
  FCNCALL_INIT;
  FCNCALL_CALL_CTRL_WRAP(unpack_subevent_base,FCNCALL_CLASS_NAME(unpack_subevent_base)::FCNCALL_CALL_BASE());
  // TRIG3EVENT trig3;
  {
  FCNCALL_SUBNAME("trig3");
  { FCNCALL_CALL_CTRL_WRAP(trig3,trig3.FCNCALL_CALL(trig3)); }
  FCNCALL_SUBNAME_END;
  }
  // SPILL_ON spill_on;
  {
  FCNCALL_SUBNAME("spill_on");
  { FCNCALL_CALL_CTRL_WRAP(spill_on,spill_on.FCNCALL_CALL(spill_on)); }
  FCNCALL_SUBNAME_END;
  }
  // SPILL_OFF spill_off;
  {
  FCNCALL_SUBNAME("spill_off");
  { FCNCALL_CALL_CTRL_WRAP(spill_off,spill_off.FCNCALL_CALL(spill_off)); }
  FCNCALL_SUBNAME_END;
  }
  // USER_CRATE_DATA data;
  {
  FCNCALL_SUBNAME("data");
  { FCNCALL_CALL_CTRL_WRAP(data,data.FCNCALL_CALL(data)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_frs_user_subev

#ifndef USER_DEF_unpack_event
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(unpack_event)::FCNCALL_NAME(unpack_event)
{
  FCNCALL_INIT;
  FCNCALL_CALL_CTRL_WRAP(unpack_event_base,FCNCALL_CLASS_NAME(unpack_event_base)::FCNCALL_CALL_BASE());
  // aida_subev aida;
  {
  FCNCALL_SUBNAME("aida");
  { FCNCALL_CALL_CTRL_WRAP(aida,aida.FCNCALL_CALL(aida)); }
  FCNCALL_SUBNAME_END;
  }
  // febex_subev germanium;
  {
  FCNCALL_SUBNAME("germanium");
  { FCNCALL_CALL_CTRL_WRAP(germanium,germanium.FCNCALL_CALL(germanium)); }
  FCNCALL_SUBNAME_END;
  }
  // fatima_tamex_subev fatima;
  {
  FCNCALL_SUBNAME("fatima");
  { FCNCALL_CALL_CTRL_WRAP(fatima,fatima.FCNCALL_CALL(fatima)); }
  FCNCALL_SUBNAME_END;
  }
  // fatima_vme_subev fatimavme;
  {
  FCNCALL_SUBNAME("fatimavme");
  { FCNCALL_CALL_CTRL_WRAP(fatimavme,fatimavme.FCNCALL_CALL(fatimavme)); }
  FCNCALL_SUBNAME_END;
  }
  // bplast_subev bplast;
  {
  FCNCALL_SUBNAME("bplast");
  { FCNCALL_CALL_CTRL_WRAP(bplast,bplast.FCNCALL_CALL(bplast)); }
  FCNCALL_SUBNAME_END;
  }
  // bgo_tamex_subevent bgo;
  {
  FCNCALL_SUBNAME("bgo");
  { FCNCALL_CALL_CTRL_WRAP(bgo,bgo.FCNCALL_CALL(bgo)); }
  FCNCALL_SUBNAME_END;
  }
  // frs_main_subev frsmain;
  {
  FCNCALL_SUBNAME("frsmain");
  { FCNCALL_CALL_CTRL_WRAP(frsmain,frsmain.FCNCALL_CALL(frsmain)); }
  FCNCALL_SUBNAME_END;
  }
  // frs_tpc_subev frstpc;
  {
  FCNCALL_SUBNAME("frstpc");
  { FCNCALL_CALL_CTRL_WRAP(frstpc,frstpc.FCNCALL_CALL(frstpc)); }
  FCNCALL_SUBNAME_END;
  }
  // frs_user_subev frsuser;
  {
  FCNCALL_SUBNAME("frsuser");
  { FCNCALL_CALL_CTRL_WRAP(frsuser,frsuser.FCNCALL_CALL(frsuser)); }
  FCNCALL_SUBNAME_END;
  }
  // frs_tpat_subev frstpat;
  {
  FCNCALL_SUBNAME("frstpat");
  { FCNCALL_CALL_CTRL_WRAP(frstpat,frstpat.FCNCALL_CALL(frstpat)); }
  FCNCALL_SUBNAME_END;
  }
  // bm_subev beammonitor;
  {
  FCNCALL_SUBNAME("beammonitor");
  { FCNCALL_CALL_CTRL_WRAP(beammonitor,beammonitor.FCNCALL_CALL(beammonitor)); }
  FCNCALL_SUBNAME_END;
  }
  FCNCALL_RET;
}
#endif//USER_DEF_unpack_event

#ifndef USER_DEF_unpack_sticky_event
FCNCALL_TEMPLATE
FCNCALL_RET_TYPE FCNCALL_CLASS_NAME(unpack_sticky_event)::FCNCALL_NAME(unpack_sticky_event)
{
  FCNCALL_INIT;
  FCNCALL_CALL_CTRL_WRAP(unpack_sticky_event_base,FCNCALL_CLASS_NAME(unpack_sticky_event_base)::FCNCALL_CALL_BASE());
  FCNCALL_RET;
}
#endif//USER_DEF_unpack_sticky_event

#include "gen/default_fcncall_undef.hh"


/** END_FUNCTION_CALL_PER_MEMBER **************************************/
