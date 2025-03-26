/** BEGIN_PACKER *******************************************************
 *
 * Event packer for BAD_EVENT.
 *
 * Do not edit - automatically generated.
 */

// BAD_EVENT()
template<typename __data_dest_t>
void PACKER_BAD_EVENT::__packer(__data_dest_t &__buffer)
{
  // MEMBER(DATA8 bad);
  // UINT32 be NOENCODE
  // {
    //  0_31: b = MATCH(0xbad00bad);
  // }
  // ENCODE(bad,(value=1));

}
FORCE_IMPL_DATA_SRC_FCN(void,BAD_EVENT::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for BARRIER.
 *
 * Do not edit - automatically generated.
 */

// BARRIER()
template<typename __data_dest_t>
void PACKER_BARRIER::__packer(__data_dest_t &__buffer)
{
  // UINT32 barrier NOENCODE
  // {
    //  0_19: no;
    // 20_31: ba = RANGE(0xf52,0xf58);
  // }
}
FORCE_IMPL_DATA_SRC_FCN(void,BARRIER::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for DUMMY.
 *
 * Do not edit - automatically generated.
 */

// DUMMY()
template<typename __data_dest_t>
void PACKER_DUMMY::__packer(__data_dest_t &__buffer)
{
  // UINT32 no NOENCODE;
}
FORCE_IMPL_DATA_SRC_FCN(void,DUMMY::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for EXT_AIDA.
 *
 * Do not edit - automatically generated.
 */


/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for FEBEX_EVENT.
 *
 * Do not edit - automatically generated.
 */

// FEBEX_EVENT(card)
template<typename __data_dest_t>
void PACKER_FEBEX_EVENT::__packer(__data_dest_t &__buffer,uint32 card)
{
  // MEMBER(DATA8 trig);
  // MEMBER(DATA32 event_trigger_time_hi);
  // MEMBER(DATA32 event_trigger_time_lo);
  // MEMBER(DATA16 hit_pattern);
  // MEMBER(DATA16 channel_trigger_time_hi[16] ZERO_SUPPRESS);
  // MEMBER(DATA32 channel_trigger_time_lo[16] ZERO_SUPPRESS);
  // MEMBER(DATA8 pileup[16] ZERO_SUPPRESS);
  // MEMBER(DATA8 overflow[16] ZERO_SUPPRESS);
  // MEMBER(DATA8 channel_cfd[16] ZERO_SUPPRESS);
  // MEMBER(DATA32 channel_energy[16] ZERO_SUPPRESS);
  // UINT32 sumchannel NOENCODE
  // {
    //  0_07: 52;
    //  8_11: trigger_type;
    // 12_15: sfpnr;
    // 16_23: card = MATCH(card);
    // 24_31: 255;
    // ENCODE(trig,(value=trigger_type));
  // }
  // UINT32 channel_size NOENCODE
  // {
    //  0_01: ignore;
    //  2_31: size;
  // }
  // UINT32 event_timestamp_hi NOENCODE
  // {
    //  0_15: timestamp_hi;
    // 16_31: ignore;
    // ENCODE(event_trigger_time_hi,(value=timestamp_hi));
  // }
  // UINT32 event_timestamp_lo NOENCODE
  // {
    //  0_31: timestamp_lo;
    // ENCODE(event_trigger_time_lo,(value=timestamp_lo));
  // }
  // UINT32 hp NOENCODE
  // {
    //  0_15: hp;
    // 16_31: ignore;
    // ENCODE(hit_pattern,(value=hp));
  // }
  // UINT32 deadbeef NOENCODE
  // {
    //  0_31: 0xdeadbeef;
  // }
  // list(0<=index<((channel_size.size / 4) - 1))

  {
    // UINT32 channelids NOENCODE
    // {
      //  0_15: chan_ts_hi;
      // 16_23: channel_id_bits;
      // 24_31: 240;
      // ENCODE(channel_trigger_time_hi[channelids.channel_id_bits],(value=chan_ts_hi));
    // }
    // UINT32 channel_ts NOENCODE
    // {
      //  0_31: chan_ts_lo;
      // ENCODE(channel_trigger_time_lo[channelids.channel_id_bits],(value=chan_ts_lo));
    // }
    // UINT32 chan_enrgy NOENCODE
    // {
      //  0_23: chan_energy;
      // 24_29: TSF;
      //    30: pileup_flag;
      //    31: overflow_flag;
      // ENCODE(channel_cfd[channelids.channel_id_bits],(value=TSF));
      // ENCODE(channel_energy[channelids.channel_id_bits],(value=chan_energy));
      // ENCODE(pileup[channelids.channel_id_bits],(value=pileup_flag));
      // ENCODE(overflow[channelids.channel_id_bits],(value=overflow_flag));
    // }
    // UINT32 future_use NOENCODE
    // {
      //  0_31: 0;
    // }
  }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,FEBEX_EVENT::__packer,uint32 card);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TRACE.
 *
 * Do not edit - automatically generated.
 */

// TRACE(board)
template<typename __data_dest_t>
void PACKER_TRACE::__packer(__data_dest_t &__buffer,uint32 board)
{
  // MEMBER(DATA16 traces[16][4000] ZERO_SUPPRESS);
  // MEMBER(DATA8 channel_id_traces[16] ZERO_SUPPRESS);
  // UINT32 header NOENCODE
  // {
    //  0_07: 52;
    //  8_15: other;
    // 16_19: board = MATCH(board);
    // 24_31: ch_id;
    // ENCODE(channel_id_traces[ch_id],(value=ch_id));
  // }
  // UINT32 tracesize NOENCODE
  // {
    //  0_31: size;
  // }
  // UINT32 tracehead NOENCODE
  // {
    //  0_23: other;
    // 24_31: head;
  // }
  // list(0<=j<((tracesize.size / 4) - 2))

  {
    // UINT32 channel_trace NOENCODE
    // {
      //  0_13: data1;
      // 14_15: stuff1;
      // 16_29: data2;
      // 30_31: stuff2;
      // ENCODE(traces[header.ch_id][((2 * j) + 0)],(value=data1));
      // ENCODE(traces[header.ch_id][((2 * j) + 1)],(value=data2));
    // }
  }
  // UINT32 trace_trailer NOENCODE
  // {
    //  0_23: notused;
    // 24_31: id = RANGE(176,191);
  // }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,TRACE::__packer,uint32 board);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for FEBEX_EVENT_TRACES.
 *
 * Do not edit - automatically generated.
 */

// FEBEX_EVENT_TRACES(card)
template<typename __data_dest_t>
void PACKER_FEBEX_EVENT_TRACES::__packer(__data_dest_t &__buffer,uint32 card)
{
  // MEMBER(DATA8 trig);
  // MEMBER(DATA32 event_trigger_time_hi);
  // MEMBER(DATA32 event_trigger_time_lo);
  // MEMBER(DATA16 hit_pattern);
  // MEMBER(DATA32 num_channels_fired);
  // MEMBER(DATA8 board_num);
  // MEMBER(DATA8 channel_id[16] ZERO_SUPPRESS);
  // MEMBER(DATA16 channel_trigger_time_hi[16] ZERO_SUPPRESS);
  // MEMBER(DATA32 channel_trigger_time_lo[16] ZERO_SUPPRESS);
  // MEMBER(DATA8 pileup[16] ZERO_SUPPRESS);
  // MEMBER(DATA8 overflow[16] ZERO_SUPPRESS);
  // MEMBER(DATA8 channel_cfd[16] ZERO_SUPPRESS);
  // MEMBER(DATA32 channel_energy[16] ZERO_SUPPRESS);
  // UINT32 sumchannel NOENCODE
  // {
    //  0_07: 52;
    //  8_11: trigger_type;
    // 12_15: sfpnr;
    // 16_23: board_id = MATCH(card);
    // 24_31: 255;
    // ENCODE(board_num,(value=board_id));
    // ENCODE(trig,(value=trigger_type));
  // }
  // UINT32 channel_size NOENCODE
  // {
    //  0_01: ignore;
    //  2_31: size;
    // ENCODE(num_channels_fired,(value=((size / 4) - 1)));
  // }
  // UINT32 event_timestamp_hi NOENCODE
  // {
    //  0_15: timestamp_hi;
    // 16_31: ignore;
    // ENCODE(event_trigger_time_hi,(value=timestamp_hi));
  // }
  // UINT32 event_timestamp_lo NOENCODE
  // {
    //  0_31: timestamp_lo;
    // ENCODE(event_trigger_time_lo,(value=timestamp_lo));
  // }
  // UINT32 hp NOENCODE
  // {
    //  0_15: hp;
    // 16_31: ignore;
    // ENCODE(hit_pattern,(value=hp));
  // }
  // UINT32 deadbeef NOENCODE
  // {
    //  0_31: 0xdeadbeef;
  // }
  // if((sumchannel.trigger_type == 1))

  // else

  if ((sumchannel.trigger_type == 1))
  {
    // list(0<=index<((channel_size.size / 4) - 1))

    {
      // UINT32 channelids NOENCODE
      // {
        //  0_15: chan_ts_hi;
        // 16_23: channel_id_bits;
        // 24_31: 240;
        // ENCODE(channel_id[index],(value=channel_id_bits));
        // ENCODE(channel_trigger_time_hi[index],(value=chan_ts_hi));
      // }
      // UINT32 channel_ts NOENCODE
      // {
        //  0_31: chan_ts_lo;
        // ENCODE(channel_trigger_time_lo[index],(value=chan_ts_lo));
      // }
      // UINT32 chan_enrgy NOENCODE
      // {
        //  0_23: chan_energy;
        // 24_29: TSF;
        //    30: pileup_flag;
        //    31: overflow_flag;
        // ENCODE(channel_cfd[index],(value=TSF));
        // ENCODE(channel_energy[index],(value=chan_energy));
        // ENCODE(pileup[index],(value=pileup_flag));
        // ENCODE(overflow[index],(value=overflow_flag));
      // }
      // UINT32 future_use NOENCODE
      // {
        //  0_31: 0;
      // }
    }
    // list(0<=index<16)

    {
      // select optional

        // trace = TRACE(board=card);
      {
        PACK_DECL(384,TRACE,trace,/*board*/card);
      }
    }
  }

  else
  {
    // if((sumchannel.trigger_type == 3))

    if ((sumchannel.trigger_type == 3))
    {
      // several UINT32 dummy NOENCODE;
    }
  }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,FEBEX_EVENT_TRACES::__packer,uint32 card);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for FEBEX_PADDING.
 *
 * Do not edit - automatically generated.
 */

// FEBEX_PADDING()
template<typename __data_dest_t>
void PACKER_FEBEX_PADDING::__packer(__data_dest_t &__buffer)
{
  // UINT32 pads_data NOENCODE
  // {
    //  0_11: counter;
    // 12_19: index;
    // 20_31: 0xadd;
  // }
}
FORCE_IMPL_DATA_SRC_FCN(void,FEBEX_PADDING::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for MVLC_SCALER.
 *
 * Do not edit - automatically generated.
 */

// MVLC_SCALER(geo)
template<typename __data_dest_t>
void PACKER_MVLC_SCALER::__packer(__data_dest_t &__buffer,uint32 geo)
{
  // MEMBER(DATA32 scalers[32] ZERO_SUPPRESS);
  // UINT32 header NOENCODE
  // {
    //  0_15: whatever;
    //    16: 0;
    // 18_23: nlw;
    // 24_26: type;
    // 27_31: geom = MATCH(geo);
  // }
  // list(0<=i<header.nlw)

  {
    // UINT32 scaler NOENCODE
    // {
      //  0_31: value;
      // ENCODE(scalers[i],(value=value));
    // }
  }
  // UINT32 trailer NOENCODE;
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,MVLC_SCALER::__packer,uint32 geo);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for VME_CAEN_V7X5.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V7X5(geom)
template<typename __data_dest_t>
void PACKER_VME_CAEN_V7X5::__packer(__data_dest_t &__buffer,uint32 geom)
{
  // MEMBER(DATA24 data[32] ZERO_SUPPRESS);
  // UINT32 header NOENCODE
  // {
    //  0_07: undefined;
    //  8_13: count;
    // 16_23: crate;
    // 24_26: 2;
    // 27_31: geom = MATCH(geom);
  // }
  // list(0<=index<header.count)

  {
    // UINT32 ch_data NOENCODE
    // {
      //  0_11: value;
      //    12: overflow;
      //    13: underflow;
      //    14: valid;
      //    15: undefined;
      // 16_20: channel;
      // 21_23: undefined2;
      // 24_26: 0;
      // 27_31: geom;
      // ENCODE(data[channel],(value=value));
    // }
  }
  // UINT32 eob NOENCODE
  // {
    //  0_23: nothing;
    // 24_26: 4;
    // 27_31: id = MATCH(geom);
  // }
  // list(0<=i<2)

  {
    // optional UINT32 eob2 NOENCODE
    // {
      //  0_23: nothing;
      // 24_26: id = MATCH(6);
      // 27_31: geom;
    // }
  }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,VME_CAEN_V7X5::__packer,uint32 geom);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TDC_HEADER.
 *
 * Do not edit - automatically generated.
 */

// TDC_HEADER()
template<typename __data_dest_t>
void PACKER_TDC_HEADER::__packer(__data_dest_t &__buffer)
{
  // UINT32 tdc_header NOENCODE
  // {
    //  0_11: bunch_id;
    // 12_23: event_id;
    // 24_25: tdc;
    //    26: unused;
    // 27_31: 1;
  // }
}
FORCE_IMPL_DATA_SRC_FCN(void,TDC_HEADER::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TDC_DATA_V1290.
 *
 * Do not edit - automatically generated.
 */

// TDC_DATA_V1290()
template<typename __data_dest_t>
void PACKER_TDC_DATA_V1290::__packer(__data_dest_t &__buffer)
{
  // MEMBER(DATA24 data[128] ZERO_SUPPRESS_MULTI(128));
  // MEMBER(DATA8 leadOrTrail[128] ZERO_SUPPRESS_MULTI(128));
  // UINT32 tdc_data NOENCODE
  // {
    //  0_20: tdc;
    // 21_25: chn;
    //    26: lot;
    // 27_31: 0;
    // ENCODE(data[chn],(value=tdc));
    // ENCODE(leadOrTrail[chn],(value=lot));
  // }
}
FORCE_IMPL_DATA_SRC_FCN(void,TDC_DATA_V1290::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TDC_ERROR.
 *
 * Do not edit - automatically generated.
 */

// TDC_ERROR()
template<typename __data_dest_t>
void PACKER_TDC_ERROR::__packer(__data_dest_t &__buffer)
{
  // UINT32 tdc_err NOENCODE
  // {
    //  0_14: error_flags;
    // 15_23: unused1;
    // 24_25: tdc;
    //    26: unused2;
    // 27_31: 4;
  // }
}
FORCE_IMPL_DATA_SRC_FCN(void,TDC_ERROR::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TDC_TRAILER.
 *
 * Do not edit - automatically generated.
 */

// TDC_TRAILER()
template<typename __data_dest_t>
void PACKER_TDC_TRAILER::__packer(__data_dest_t &__buffer)
{
  // UINT32 tdc_trailer NOENCODE
  // {
    //  0_11: word_count;
    // 12_23: event_id;
    // 24_25: tdc;
    //    26: unused;
    // 27_31: 3;
  // }
}
FORCE_IMPL_DATA_SRC_FCN(void,TDC_TRAILER::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for VME_CAEN_V1290_N.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V1290_N()
template<typename __data_dest_t>
void PACKER_VME_CAEN_V1290_N::__packer(__data_dest_t &__buffer)
{
  // MEMBER(DATA8 geo);
  // UINT32 header NOENCODE
  // {
    //  0_04: geom;
    //  5_26: event_count;
    // 27_31: type = MATCH(8);
    // ENCODE(geo,(value=geom));
  // }
  // select several

    // tdc_header = TDC_HEADER();
    // measurement = TDC_DATA_V1290();
    // tdc_err = TDC_ERROR();
    // tdc_trailer = TDC_TRAILER();
  {
    PACK_DECL(693,TDC_HEADER,tdc_header);
    PACK_DECL(694,TDC_DATA_V1290,measurement);
    PACK_DECL(695,TDC_ERROR,tdc_err);
    PACK_DECL(696,TDC_TRAILER,tdc_trailer);
  }
  // optional UINT32 ext_time_tag NOENCODE
  // {
    //  0_26: time_tag;
    // 27_31: 17;
  // }
  // UINT32 trailer NOENCODE
  // {
    //  0_04: geom;
    //  5_20: word_count;
    // 21_23: unused;
    //    24: tdc_error;
    //    25: overflow;
    //    26: trigger_lost;
    // 27_31: 16;
  // }
}
FORCE_IMPL_DATA_SRC_FCN(void,VME_CAEN_V1290_N::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for MAIN_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// MAIN_CRATE_DATA()
template<typename __data_dest_t>
void PACKER_MAIN_CRATE_DATA::__packer(__data_dest_t &__buffer)
{
  // barrier0 = BARRIER();
  PACK_DECL(1000,BARRIER,barrier0);
  // v830 = MVLC_SCALER(geo=8);
  PACK_DECL(1002,MVLC_SCALER,v830,/*geo*/8);
  // barrier1 = BARRIER();
  PACK_DECL(1006,BARRIER,barrier1);
  // v792 = VME_CAEN_V7X5(geom=14);
  PACK_DECL(1007,VME_CAEN_V7X5,v792,/*geom*/14);
  // UINT32 aaahhh NOENCODE
  // {
    //  0_31: 0xaaaa1290;
  // }
  // UINT32 exxxxx NOENCODE;
  // barrier2 = BARRIER();
  PACK_DECL(1012,BARRIER,barrier2);
  // v1290 = VME_CAEN_V1290_N();
  PACK_DECL(1013,VME_CAEN_V1290_N,v1290);
  // optional UINT32 eodb NOENCODE;
}
FORCE_IMPL_DATA_SRC_FCN(void,MAIN_CRATE_DATA::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for SPILL_OFF.
 *
 * Do not edit - automatically generated.
 */

// SPILL_OFF()
template<typename __data_dest_t>
void PACKER_SPILL_OFF::__packer(__data_dest_t &__buffer)
{
  // MEMBER(DATA8 spilloff);
  // UINT32 off1 NOENCODE
  // {
    //  0_31: 0x4040400a;
  // }
  // UINT32 off2 NOENCODE
  // {
    //  0_31: 0x4040400b;
  // }
  // UINT32 off3 NOENCODE
  // {
    //  0_31: 0x4040400c;
  // }
  // ENCODE(spilloff,(value=1));

}
FORCE_IMPL_DATA_SRC_FCN(void,SPILL_OFF::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for SPILL_ON.
 *
 * Do not edit - automatically generated.
 */

// SPILL_ON()
template<typename __data_dest_t>
void PACKER_SPILL_ON::__packer(__data_dest_t &__buffer)
{
  // MEMBER(DATA8 spillon);
  // UINT32 on NOENCODE
  // {
    //  0_31: 0x30303030;
  // }
  // ENCODE(spillon,(value=1));

}
FORCE_IMPL_DATA_SRC_FCN(void,SPILL_ON::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TAMEX4_EPOCH_DATA.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_EPOCH_DATA(sfp,card,time_coarse,time_fine,time_edge,time_channel,
                  // time_epoch)
template<typename __data_dest_t>
void PACKER_TAMEX4_EPOCH_DATA::__packer(__data_dest_t &__buffer,uint32 sfp
                                                               ,uint32 card
                                                               ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_coarse
                                                               ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_fine
                                                               ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_edge
                                                               ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_channel
                                                               ,raw_list_ii_zero_suppress<DATA32,DATA32,1024> &time_epoch)
{
  // MEMBER(DATA12 time_coarse[1024] NO_INDEX_LIST);
  // MEMBER(DATA12 time_fine[1024] NO_INDEX_LIST);
  // MEMBER(DATA12 time_edge[1024] NO_INDEX_LIST);
  // MEMBER(DATA12 time_channel[1024] NO_INDEX_LIST);
  // MEMBER(DATA32 time_epoch[1024] NO_INDEX_LIST);
  // UINT32 data NOENCODE
  // {
    //  0_27: epoch;
    // 28_31: 6;
    // ENCODE(time_coarse APPEND_LIST,(value=0));
    // ENCODE(time_fine APPEND_LIST,(value=0));
    // ENCODE(time_edge APPEND_LIST,(value=0));
    // ENCODE(time_channel APPEND_LIST,(value=0));
    // ENCODE(time_epoch APPEND_LIST,(value=epoch));
  // }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,TAMEX4_EPOCH_DATA::__packer,uint32 sfp,uint32 card);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TAMEX4_HEADER.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_HEADER()
template<typename __data_dest_t>
void PACKER_TAMEX4_HEADER::__packer(__data_dest_t &__buffer)
{
  // MEMBER(DATA16 post_trig_ns);
  // MEMBER(DATA16 pre_trig_ns);
  // UINT32 trigger_window NOENCODE
  // {
    //  0_15: post_trig_ns;
    // 16_31: pre_trig_ns;
    // ENCODE(post_trig_ns,(value=post_trig_ns));
    // ENCODE(pre_trig_ns,(value=pre_trig_ns));
  // }
}
FORCE_IMPL_DATA_SRC_FCN(void,TAMEX4_HEADER::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TAMEX4_PADDING.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_PADDING()
template<typename __data_dest_t>
void PACKER_TAMEX4_PADDING::__packer(__data_dest_t &__buffer)
{
  // UINT32 padding NOENCODE
  // {
    //  0_11: counter;
    // 12_19: index;
    // 20_31: 0xadd;
  // }
}
FORCE_IMPL_DATA_SRC_FCN(void,TAMEX4_PADDING::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TAMEX4_TIME_DATA.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_TIME_DATA(sfp,card,time_coarse,time_fine,time_edge,time_channel,
                 // time_epoch)
template<typename __data_dest_t>
void PACKER_TAMEX4_TIME_DATA::__packer(__data_dest_t &__buffer,uint32 sfp
                                                              ,uint32 card
                                                              ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_coarse
                                                              ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_fine
                                                              ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_edge
                                                              ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_channel
                                                              ,raw_list_ii_zero_suppress<DATA32,DATA32,1024> &time_epoch)
{
  // MEMBER(DATA12 time_coarse[1024] NO_INDEX_LIST);
  // MEMBER(DATA12 time_fine[1024] NO_INDEX_LIST);
  // MEMBER(DATA12 time_edge[1024] NO_INDEX_LIST);
  // MEMBER(DATA12 time_channel[1024] NO_INDEX_LIST);
  // MEMBER(DATA32 time_epoch[1024] NO_INDEX_LIST);
  // UINT32 data NOENCODE
  // {
    //  0_10: coarse;
    //    11: is_leading;
    // 12_21: fine;
    // 22_27: channel;
    // 28_31: type = CHECK(8);
    // ENCODE(time_coarse APPEND_LIST,(value=coarse));
    // ENCODE(time_fine APPEND_LIST,(value=fine));
    // ENCODE(time_edge APPEND_LIST,(value=is_leading));
    // ENCODE(time_channel APPEND_LIST,(value=channel));
    // ENCODE(time_epoch APPEND_LIST,(value=0));
  // }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,TAMEX4_TIME_DATA::__packer,uint32 sfp,uint32 card);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TAMEX4_SFP.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_SFP(sfp,card)
template<typename __data_dest_t>
void PACKER_TAMEX4_SFP::__packer(__data_dest_t &__buffer,uint32 sfp,uint32 card)
{
  // MEMBER(DATA16 trig);
  // MEMBER(DATA32 event_size);
  // MEMBER(DATA12 time_coarse[1024] NO_INDEX_LIST);
  // MEMBER(DATA12 time_fine[1024] NO_INDEX_LIST);
  // MEMBER(DATA12 time_edge[1024] NO_INDEX_LIST);
  // MEMBER(DATA12 time_channel[1024] NO_INDEX_LIST);
  // MEMBER(DATA32 time_epoch[1024] NO_INDEX_LIST);
  // UINT32 indicator NOENCODE
  // {
    //  0_07: 52;
    //  8_11: trigger_type;
    // 12_15: sfp = MATCH(sfp);
    // 16_23: card = MATCH(card);
    // 24_31: 0;
  // }
  // MATCH_END;
  // UINT32 data_size NOENCODE
  // {
    //  0_31: bytes;
    // ENCODE(event_size,(value=bytes));
  // }
  // UINT32 tdc_header NOENCODE
  // {
    //  0_15: lec;
    //    16: buf_no;
    // 17_19: reserved;
    // 20_23: trigger_type;
    // 24_31: 170;
    // ENCODE(trig,(value=trigger_type));
  // }
  // list(0<=i<((data_size.bytes / 4) - 3))

  {
    // select

      // epoch = TAMEX4_EPOCH_DATA(sfp=sfp,card=card,time_coarse=time_coarse,
                                // time_fine=time_fine,time_edge=time_edge,
                                // time_channel=time_channel,time_epoch=time_epoch);
      // time = TAMEX4_TIME_DATA(sfp=sfp,card=card,time_coarse=time_coarse,
                              // time_fine=time_fine,time_edge=time_edge,
                              // time_channel=time_channel,time_epoch=time_epoch);
    {
      PACK_DECL(520,TAMEX4_EPOCH_DATA,epoch,/*sfp*/sfp,/*card*/card,/*time_coarse*/time_coarse,/*time_fine*/time_fine,/*time_edge*/time_edge,/*time_channel*/time_channel,/*time_epoch*/time_epoch);
      PACK_DECL(521,TAMEX4_TIME_DATA,time,/*sfp*/sfp,/*card*/card,/*time_coarse*/time_coarse,/*time_fine*/time_fine,/*time_edge*/time_edge,/*time_channel*/time_channel,/*time_epoch*/time_epoch);
    }
  }
  // UINT32 error_bits NOENCODE
  // {
    //  0_23: bits;
    // 24_31: 238;
  // }
  // UINT32 trailer NOENCODE
  // {
    //  0_15: lec;
    //    16: buf_no;
    // 17_19: reserved;
    // 20_23: trigger_type;
    // 24_31: 187;
  // }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,TAMEX4_SFP::__packer,uint32 sfp,uint32 card);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TDC_DATA_V1190.
 *
 * Do not edit - automatically generated.
 */

// TDC_DATA_V1190()
template<typename __data_dest_t>
void PACKER_TDC_DATA_V1190::__packer(__data_dest_t &__buffer)
{
  // MEMBER(DATA24 data[128] ZERO_SUPPRESS_MULTI(128));
  // MEMBER(DATA8 leadOrTrail[128] ZERO_SUPPRESS_MULTI(128));
  // UINT32 tdc_data NOENCODE
  // {
    //  0_18: tdc;
    // 19_25: chn;
    //    26: lot;
    // 27_31: 0;
    // ENCODE(data[chn],(value=tdc));
    // ENCODE(leadOrTrail[chn],(value=lot));
  // }
}
FORCE_IMPL_DATA_SRC_FCN(void,TDC_DATA_V1190::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TIMESTAMP_WHITERABBIT.
 *
 * Do not edit - automatically generated.
 */

// TIMESTAMP_WHITERABBIT(id)
template<typename __data_dest_t>
void PACKER_TIMESTAMP_WHITERABBIT::__packer(__data_dest_t &__buffer,uint32 id)
{
  // MEMBER(DATA12 subsystem_id);
  // MEMBER(DATA16 t1);
  // MEMBER(DATA16 t2);
  // MEMBER(DATA16 t3);
  // MEMBER(DATA16 t4);
  // UINT32 header NOENCODE
  // {
    //  0_11: id = MATCH(id);
    // 12_15: 0;
    //    16: error_bit;
    // 17_31: 0;
    // ENCODE(subsystem_id,(value=id));
  // }
  // UINT32 d1 NOENCODE
  // {
    //  0_15: t1;
    // 16_31: 0x3e1;
    // ENCODE(t1,(value=t1));
  // }
  // UINT32 d2 NOENCODE
  // {
    //  0_15: t2;
    // 16_31: 0x4e1;
    // ENCODE(t2,(value=t2));
  // }
  // UINT32 d3 NOENCODE
  // {
    //  0_15: t3;
    // 16_31: 0x5e1;
    // ENCODE(t3,(value=t3));
  // }
  // UINT32 d4 NOENCODE
  // {
    //  0_15: t4;
    // 16_31: 0x6e1;
    // ENCODE(t4,(value=t4));
  // }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,TIMESTAMP_WHITERABBIT::__packer,uint32 id);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TIMESTAMP_WHITERABBIT_EXTENDED.
 *
 * Do not edit - automatically generated.
 */

// TIMESTAMP_WHITERABBIT_EXTENDED(id)
template<typename __data_dest_t>
void PACKER_TIMESTAMP_WHITERABBIT_EXTENDED::__packer(__data_dest_t &__buffer,uint32 id)
{
  // MEMBER(DATA16 subsystem_id);
  // MEMBER(DATA16 t1);
  // MEMBER(DATA16 t2);
  // MEMBER(DATA16 t3);
  // MEMBER(DATA16 t4);
  // UINT32 header NOENCODE
  // {
    //  0_12: id = MATCH(id);
    // 13_15: 0;
    //    16: error_bit;
    // 17_31: 0;
    // ENCODE(subsystem_id,(value=id));
  // }
  // UINT32 d1 NOENCODE
  // {
    //  0_15: t1;
    // 16_31: 0x3e1;
    // ENCODE(t1,(value=t1));
  // }
  // UINT32 d2 NOENCODE
  // {
    //  0_15: t2;
    // 16_31: 0x4e1;
    // ENCODE(t2,(value=t2));
  // }
  // UINT32 d3 NOENCODE
  // {
    //  0_15: t3;
    // 16_31: 0x5e1;
    // ENCODE(t3,(value=t3));
  // }
  // UINT32 d4 NOENCODE
  // {
    //  0_15: t4;
    // 16_31: 0x6e1;
    // ENCODE(t4,(value=t4));
  // }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,TIMESTAMP_WHITERABBIT_EXTENDED::__packer,uint32 id);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TPAT_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// TPAT_CRATE_DATA()
template<typename __data_dest_t>
void PACKER_TPAT_CRATE_DATA::__packer(__data_dest_t &__buffer)
{
  // MEMBER(DATA16 tpat);
  // UINT32 w1;
  // UINT32 w2;
  // UINT32 w3;
  // UINT32 trigger_pattern
  // {
    //  0_15: pattern;
    // 16_31: nothing;
    // ENCODE(tpat,(value=pattern));
  // }
  // UINT32 coffee NOENCODE
  // {
    //  0_07: scaler_words;
    //  8_31: coffee;
  // }
  // if((coffee.coffee == 0x00c0ffee))

  // else

  if ((coffee.coffee == 0x00c0ffee))
  {
    // list(0<=i<(coffee.scaler_words * 3))

    {
      // UINT32 scaler NOENCODE
      // {
        //  0_31: something;
      // }
    }
    // UINT32 dead NOENCODE
    // {
      //  0_31: 0xdeaddead;
    // }
    // several UINT32 eob NOENCODE;
  }

  else
  {
    // several UINT32 filler NOENCODE;
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,TPAT_CRATE_DATA::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for VME_CAEN_V1190_N.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V1190_N()
template<typename __data_dest_t>
void PACKER_VME_CAEN_V1190_N::__packer(__data_dest_t &__buffer)
{
  // MEMBER(DATA8 geo);
  // UINT32 header NOENCODE
  // {
    //  0_04: geom;
    //  5_26: event_count;
    // 27_31: seven_f;
    // ENCODE(geo,(value=geom));
  // }
  // if((header.seven_f != 8))

  if ((header.seven_f != 8))
  {
    // UINT32 second1 NOENCODE
    // {
      //  0_31: 0xffffffff;
    // }
    // UINT32 real_header NOENCODE
    // {
      //  0_04: geom;
      //  5_26: event_count;
      // 27_31: 8;
    // }
  }
  // select several

    // tdc_header = TDC_HEADER();
    // measurement = TDC_DATA_V1190();
    // tdc_error = TDC_ERROR();
    // tdc_trailer = TDC_TRAILER();
  {
    PACK_DECL(750,TDC_HEADER,tdc_header);
    PACK_DECL(751,TDC_DATA_V1190,measurement);
    PACK_DECL(752,TDC_ERROR,tdc_error);
    PACK_DECL(753,TDC_TRAILER,tdc_trailer);
  }
  // optional UINT32 ext_time_tag NOENCODE
  // {
    //  0_26: time_tag;
    // 27_31: 17;
  // }
  // UINT32 trailer NOENCODE
  // {
    //  0_04: geom;
    //  5_20: word_count;
    // 21_23: unused;
    //    24: tdc_error;
    //    25: overflow;
    //    26: trigger_lost;
    // 27_31: whatever;
  // }
  // optional UINT32 eob NOENCODE;
}
FORCE_IMPL_DATA_SRC_FCN(void,VME_CAEN_V1190_N::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TPC_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// TPC_CRATE_DATA()
template<typename __data_dest_t>
void PACKER_TPC_CRATE_DATA::__packer(__data_dest_t &__buffer)
{
  // select several

    // barrier0 = BARRIER();
    // v785 = VME_CAEN_V7X5(geom=8);
    // v775 = VME_CAEN_V7X5(geom=12);
  {
    PACK_DECL(1023,BARRIER,barrier0);
    PACK_DECL(1024,VME_CAEN_V7X5,v785,/*geom*/8);
    PACK_DECL(1025,VME_CAEN_V7X5,v775,/*geom*/12);
  }
  // UINT32 aaahhh NOENCODE
  // {
    //  0_31: 0xaaaa1190;
  // }
  // UINT32 exxxxx NOENCODE;
  // barrier1 = BARRIER();
  PACK_DECL(1031,BARRIER,barrier1);
  // v1190 = VME_CAEN_V1190_N();
  PACK_DECL(1032,VME_CAEN_V1190_N,v1190);
  // select several

    // dummy = DUMMY();
  {
    PACK_DECL(1037,DUMMY,dummy);
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,TPC_CRATE_DATA::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for VME_MESYTEC_MDPP16.
 *
 * Do not edit - automatically generated.
 */

// VME_MESYTEC_MDPP16(geom)
template<typename __data_dest_t>
void PACKER_VME_MESYTEC_MDPP16::__packer(__data_dest_t &__buffer,uint32 geom)
{
  // MEMBER(DATA24 adc[16]);
  // MEMBER(DATA24 tdc[16]);
  // MEMBER(DATA24 trig_tdc[16]);
  // MEMBER(DATA24 adc_short[16]);
  // MARK_COUNT(start);
  void *__mark_start = __buffer._offset;
  // UINT32 header NOENCODE
  // {
    //  0_09: word_number;
    // 10_12: adc_res;
    // 13_15: tdc_res;
    // 16_23: geom = MATCH(geom);
    // 24_29: 0;
    // 30_31: 1;
  // }
  // several UINT32 ch_data NOENCODE
  // {
    //  0_15: value;
    // 16_19: channel;
    // 20_21: ch_kind;
    //    22: overflow;
    //    23: pileup;
    // 24_27: 0;
    // 28_31: 1;
    // if((ch_kind == 0))
    // {
      // ENCODE(adc[channel],(value=value));
    // }
    // if((ch_kind == 1))
    // {
      // ENCODE(tdc[channel],(value=value));
    // }
    // if((ch_kind == 2))
    // {
      // ENCODE(trig_tdc[channel],(value=value));
    // }
    // if((ch_kind == 3))
    // {
      // ENCODE(adc_short[channel],(value=value));
    // }
  // }
  // several UINT32 fill_word NOENCODE
  // {
    //  0_31: 0;
  // }
  // UINT32 end_of_event
  // {
    //  0_29: counter;
    // 30_31: 3;
  // }
  // MARK_COUNT(end);
  void *__mark_end = __buffer._offset;
  // CHECK_COUNT(header.word_number,start,end,( - 4),4)
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,VME_MESYTEC_MDPP16::__packer,uint32 geom);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TRAVMUS_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// TRAVMUS_CRATE_DATA()
template<typename __data_dest_t>
void PACKER_TRAVMUS_CRATE_DATA::__packer(__data_dest_t &__buffer)
{
  // UINT32 coffee NOENCODE
  // {
    //  0_07: counter;
    //  8_31: 0x00c0ffee;
  // }
  // if((coffee.counter == 0))

  // else

  if ((coffee.counter == 0))
  {
    // UINT32 dead NOENCODE
    // {
      //  0_31: 0xdeaddead;
    // }
    // UINT32 vtime NOENCODE;
    // UINT32 dtime NOENCODE;
    // UINT32 barrier NOENCODE
    // {
      //  0_15: counter;
      // 16_31: bar = MATCH(0xf520);
    // }
    // select several

      // mdpp = VME_MESYTEC_MDPP16(geom=8);
    {
      PACK_DECL(1110,VME_MESYTEC_MDPP16,mdpp,/*geom*/8);
    }
  }

  else
  {
    // select several

      // dummy = DUMMY();
    {
      PACK_DECL(1118,DUMMY,dummy);
    }
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,TRAVMUS_CRATE_DATA::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for TRIG3EVENT.
 *
 * Do not edit - automatically generated.
 */

// TRIG3EVENT()
template<typename __data_dest_t>
void PACKER_TRIG3EVENT::__packer(__data_dest_t &__buffer)
{
  // UINT32 trig3 NOENCODE
  // {
    //  0_31: 0x20202020;
  // }
}
FORCE_IMPL_DATA_SRC_FCN(void,TRIG3EVENT::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for USER_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// USER_CRATE_DATA()
template<typename __data_dest_t>
void PACKER_USER_CRATE_DATA::__packer(__data_dest_t &__buffer)
{
  // barrier0 = BARRIER();
  PACK_DECL(1044,BARRIER,barrier0);
  // v830 = MVLC_SCALER(geo=8);
  PACK_DECL(1047,MVLC_SCALER,v830,/*geo*/8);
  // select several

    // barrier1 = BARRIER();
    // v775[0] = VME_CAEN_V7X5(geom=8);
    // v775[1] = VME_CAEN_V7X5(geom=9);
    // v785[0] = VME_CAEN_V7X5(geom=10);
    // v785[1] = VME_CAEN_V7X5(geom=12);
  {
    PACK_DECL(1053,BARRIER,barrier1);
    PACK_DECL(1054,VME_CAEN_V7X5,v775[0],/*geom*/8);
    PACK_DECL(1055,VME_CAEN_V7X5,v775[1],/*geom*/9);
    PACK_DECL(1056,VME_CAEN_V7X5,v785[0],/*geom*/10);
    PACK_DECL(1057,VME_CAEN_V7X5,v785[1],/*geom*/12);
  }
  // UINT32 aaahhh NOENCODE
  // {
    //  0_31: 0xaaaa1290;
  // }
  // UINT32 filler1 NOENCODE;
  // barrier2 = BARRIER();
  PACK_DECL(1062,BARRIER,barrier2);
  // v1290 = VME_CAEN_V1290_N();
  PACK_DECL(1063,VME_CAEN_V1290_N,v1290);
  // optional UINT32 eodb NOENCODE;
}
FORCE_IMPL_DATA_SRC_FCN(void,USER_CRATE_DATA::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for VME_CAEN_V830.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V830(geom)
template<typename __data_dest_t>
void PACKER_VME_CAEN_V830::__packer(__data_dest_t &__buffer,uint32 geom)
{
  // MEMBER(DATA32 data[32] ZERO_SUPPRESS);
  // UINT32 header
  // {
    //  0_15: event_number;
    // 16_17: ts;
    // 18_23: count;
    // 24_25: undefined;
    //    26: 1;
    // 27_31: geom = MATCH(geom);
  // }
  // list(0<=index<header.count)

  {
    // UINT32 ch_data NOENCODE
    // {
      //  0_25: value;
      //    26: 0;
      // 27_31: channel;
      // ENCODE(data[channel],(value=value));
    // }
  }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,VME_CAEN_V830::__packer,uint32 geom);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for VULOM_TPAT.
 *
 * Do not edit - automatically generated.
 */

// VULOM_TPAT()
template<typename __data_dest_t>
void PACKER_VULOM_TPAT::__packer(__data_dest_t &__buffer)
{
  // UINT32 vulom_head NOENCODE
  // {
    //  0_15: counter;
    // 16_31: head = MATCH(0xf500);
  // }
  // list(0<=i<vulom_head.counter)

  {
    // UINT32 tp NOENCODE;
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,VULOM_TPAT::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for WR_MULTI.
 *
 * Do not edit - automatically generated.
 */

// WR_MULTI()
template<typename __data_dest_t>
void PACKER_WR_MULTI::__packer(__data_dest_t &__buffer)
{
  // MEMBER(DATA32 time_hi);
  // MEMBER(DATA32 time_lo);
  // UINT32 hi NOENCODE
  // {
    //  0_31: time;
    // ENCODE(time_hi,(value=time));
  // }
  // UINT32 lo NOENCODE
  // {
    //  0_31: time;
    // ENCODE(time_lo,(value=time));
  // }
}
FORCE_IMPL_DATA_SRC_FCN(void,WR_MULTI::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for ZERO_FILLER.
 *
 * Do not edit - automatically generated.
 */

// ZERO_FILLER()
template<typename __data_dest_t>
void PACKER_ZERO_FILLER::__packer(__data_dest_t &__buffer)
{
  // UINT32 filler NOENCODE
  // {
    //  0_31: zero = MATCH(0);
  // }
}
FORCE_IMPL_DATA_SRC_FCN(void,ZERO_FILLER::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for aida_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(aida_subev)
template<typename __data_dest_t>
void PACKER_aida_subev::__packer(__data_dest_t &__buffer)
{
  // ts = TIMESTAMP_WHITERABBIT(id=0x700);
  PACK_DECL(1152,TIMESTAMP_WHITERABBIT,ts,/*id*/0x700);
  // external data = EXT_AIDA();
  PACK_DECL(1153,EXT_AIDA,data);
}
FORCE_IMPL_DATA_SRC_FCN(void,aida_subev::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for bplast_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(bplast_subev)
template<typename __data_dest_t>
void PACKER_bplast_subev::__packer(__data_dest_t &__buffer)
{
  // select optional

    // ts = TIMESTAMP_WHITERABBIT(id=0x500);
  {
    PACK_DECL(1185,TIMESTAMP_WHITERABBIT,ts,/*id*/0x500);
  }
  // select optional

    // trigger_window = TAMEX4_HEADER();
  {
    PACK_DECL(1190,TAMEX4_HEADER,trigger_window);
  }
  // select several

    // padding = TAMEX4_PADDING();
  {
    PACK_DECL(1195,TAMEX4_PADDING,padding);
  }
  // select several

    // tamex[0] = TAMEX4_SFP(sfp=0,card=0);
    // tamex[1] = TAMEX4_SFP(sfp=0,card=1);
    // tamex[2] = TAMEX4_SFP(sfp=0,card=2);
    // tamex[3] = TAMEX4_SFP(sfp=0,card=3);
    // tamex[4] = TAMEX4_SFP(sfp=0,card=4);
    // tamex[5] = TAMEX4_SFP(sfp=0,card=5);
    // tamex[6] = TAMEX4_SFP(sfp=0,card=6);
    // tamex[7] = TAMEX4_SFP(sfp=0,card=7);
    // tamex[8] = TAMEX4_SFP(sfp=0,card=8);
  {
    PACK_DECL(1200,TAMEX4_SFP,tamex[0],/*sfp*/0,/*card*/0);
    PACK_DECL(1201,TAMEX4_SFP,tamex[1],/*sfp*/0,/*card*/1);
    PACK_DECL(1202,TAMEX4_SFP,tamex[2],/*sfp*/0,/*card*/2);
    PACK_DECL(1203,TAMEX4_SFP,tamex[3],/*sfp*/0,/*card*/3);
    PACK_DECL(1204,TAMEX4_SFP,tamex[4],/*sfp*/0,/*card*/4);
    PACK_DECL(1205,TAMEX4_SFP,tamex[5],/*sfp*/0,/*card*/5);
    PACK_DECL(1206,TAMEX4_SFP,tamex[6],/*sfp*/0,/*card*/6);
    PACK_DECL(1207,TAMEX4_SFP,tamex[7],/*sfp*/0,/*card*/7);
    PACK_DECL(1208,TAMEX4_SFP,tamex[8],/*sfp*/0,/*card*/8);
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,bplast_subev::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for febex_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(febex_subev)
template<typename __data_dest_t>
void PACKER_febex_subev::__packer(__data_dest_t &__buffer)
{
  // select optional

    // ts = TIMESTAMP_WHITERABBIT(id=0x400);
  {
    PACK_DECL(1161,TIMESTAMP_WHITERABBIT,ts,/*id*/0x400);
  }
  // select several

    // padding = FEBEX_PADDING();
  {
    PACK_DECL(1166,FEBEX_PADDING,padding);
  }
  // select several

    // data[0] = FEBEX_EVENT(card=0);
    // data[1] = FEBEX_EVENT(card=1);
    // data[2] = FEBEX_EVENT(card=2);
    // data[3] = FEBEX_EVENT(card=3);
    // data[4] = FEBEX_EVENT(card=4);
    // data[5] = FEBEX_EVENT(card=5);
  {
    PACK_DECL(1171,FEBEX_EVENT,data[0],/*card*/0);
    PACK_DECL(1172,FEBEX_EVENT,data[1],/*card*/1);
    PACK_DECL(1173,FEBEX_EVENT,data[2],/*card*/2);
    PACK_DECL(1174,FEBEX_EVENT,data[3],/*card*/3);
    PACK_DECL(1175,FEBEX_EVENT,data[4],/*card*/4);
    PACK_DECL(1176,FEBEX_EVENT,data[5],/*card*/5);
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,febex_subev::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for frs_main_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_main_subev)
template<typename __data_dest_t>
void PACKER_frs_main_subev::__packer(__data_dest_t &__buffer)
{
  // select several

    // trig3 = TRIG3EVENT();
  {
    PACK_DECL(1216,TRIG3EVENT,trig3);
  }
  // select several

    // spill_on = SPILL_ON();
  {
    PACK_DECL(1221,SPILL_ON,spill_on);
  }
  // select several

    // spill_off = SPILL_OFF();
  {
    PACK_DECL(1226,SPILL_OFF,spill_off);
  }
  // UINT32 sevens NOENCODE
  // {
    //  0_31: 0x77777777;
  // }
  // select optional

    // data = MAIN_CRATE_DATA();
  {
    PACK_DECL(1236,MAIN_CRATE_DATA,data);
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,frs_main_subev::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for frs_tpat_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_tpat_subev)
template<typename __data_dest_t>
void PACKER_frs_tpat_subev::__packer(__data_dest_t &__buffer)
{
  // select optional

    // wr = TIMESTAMP_WHITERABBIT(id=0x100);
  {
    PACK_DECL(1298,TIMESTAMP_WHITERABBIT,wr,/*id*/0x100);
  }
  // select several

    // trig3 = TRIG3EVENT();
  {
    PACK_DECL(1303,TRIG3EVENT,trig3);
  }
  // select optional

    // data = TPAT_CRATE_DATA();
  {
    PACK_DECL(1308,TPAT_CRATE_DATA,data);
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,frs_tpat_subev::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for frs_tpc_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_tpc_subev)
template<typename __data_dest_t>
void PACKER_frs_tpc_subev::__packer(__data_dest_t &__buffer)
{
  // optional UINT32 be
  // {
    //  0_31: b = MATCH(0xbad00bad);
  // }
  // select several

    // trig3 = TRIG3EVENT();
  {
    PACK_DECL(1246,TRIG3EVENT,trig3);
  }
  // select several

    // spill_on = SPILL_ON();
  {
    PACK_DECL(1251,SPILL_ON,spill_on);
  }
  // select several

    // spill_off = SPILL_OFF();
  {
    PACK_DECL(1256,SPILL_OFF,spill_off);
  }
  // select optional

    // data = TPC_CRATE_DATA();
  {
    PACK_DECL(1261,TPC_CRATE_DATA,data);
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,frs_tpc_subev::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for frs_travmus_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_travmus_subev)
template<typename __data_dest_t>
void PACKER_frs_travmus_subev::__packer(__data_dest_t &__buffer)
{
  // select optional

    // wr = TIMESTAMP_WHITERABBIT(id=0x200);
  {
    PACK_DECL(1316,TIMESTAMP_WHITERABBIT,wr,/*id*/0x200);
  }
  // select optional

    // stuff = VULOM_TPAT();
  {
    PACK_DECL(1321,VULOM_TPAT,stuff);
  }
  // select optional

    // data = TRAVMUS_CRATE_DATA();
  {
    PACK_DECL(1326,TRAVMUS_CRATE_DATA,data);
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,frs_travmus_subev::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for frs_user_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_user_subev)
template<typename __data_dest_t>
void PACKER_frs_user_subev::__packer(__data_dest_t &__buffer)
{
  // select several

    // trig3 = TRIG3EVENT();
  {
    PACK_DECL(1269,TRIG3EVENT,trig3);
  }
  // select several

    // spill_on = SPILL_ON();
  {
    PACK_DECL(1274,SPILL_ON,spill_on);
  }
  // select several

    // spill_off = SPILL_OFF();
  {
    PACK_DECL(1279,SPILL_OFF,spill_off);
  }
  // UINT32 sevens NOENCODE
  // {
    //  0_31: 0x77777777;
  // }
  // select optional

    // data = USER_CRATE_DATA();
  {
    PACK_DECL(1290,USER_CRATE_DATA,data);
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,frs_user_subev::__packer);

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for EVENT.
 *
 * Do not edit - automatically generated.
 */

// EVENT
  // revisit aida = aida_subev(type=10,subtype=1,procid=90,control=37);
  // germanium = febex_subev(type=10,subtype=1,procid=60,control=20);
  // bplast = bplast_subev(type=10,subtype=1,procid=80,control=20);
  // frsmain = frs_main_subev(procid=10);
  // frstpc = frs_tpc_subev(procid=20);
  // frsuser = frs_user_subev(procid=30);
  // frstpat = frs_tpat_subev(procid=15);
  // frstravmus = frs_travmus_subev(procid=35,control=30);
  // ignore_unknown_subevent;
{
}

/** END_PACKER ********************************************************/
/** BEGIN_PACKER *******************************************************
 *
 * Event packer for EVENT.
 *
 * Do not edit - automatically generated.
 */

// STICKY_EVENT
{
}

/** END_PACKER ********************************************************/
