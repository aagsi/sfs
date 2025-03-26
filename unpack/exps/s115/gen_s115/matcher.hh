/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for BAD_EVENT.
 *
 * Do not edit - automatically generated.
 */

// BAD_EVENT()
template<typename __data_src_t>
bool BAD_EVENT::__match(__data_src_t &__buffer)
{
  // MEMBER(DATA8 bad);
  // UINT32 be NOENCODE
  // {
    //  0_31: b = MATCH(0xbad00bad);
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 b : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 b : 32; // 0..31
#endif
    };
    uint32  u32;
  } be;
  MATCH_READ_FROM_BUFFER_FULL(1134,uint32 ,be,be.u32,1);
  MATCH_BITS_EQUAL(1133,be.b,0xbad00bad);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,BAD_EVENT::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for BARRIER.
 *
 * Do not edit - automatically generated.
 */

// BARRIER()
template<typename __data_src_t>
bool BARRIER::__match(__data_src_t &__buffer)
{
  // UINT32 barrier NOENCODE
  // {
    //  0_19: no;
    // 20_31: ba = RANGE(0xf52,0xf58);
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 no : 20; // 0..19
      uint32 ba : 12; // 20..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 ba : 12; // 20..31
      uint32 no : 20; // 0..19
#endif
    };
    uint32  u32;
  } barrier;
  MATCH_READ_FROM_BUFFER_FULL(909,uint32 ,barrier,barrier.u32,3);
  MATCH_BITS_RANGE(908,barrier.ba,0xf52,0xf58);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,BARRIER::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for DUMMY.
 *
 * Do not edit - automatically generated.
 */

// DUMMY()
template<typename __data_src_t>
bool DUMMY::__match(__data_src_t &__buffer)
{
  // UINT32 no NOENCODE;
  uint32  no;
  MATCH_READ_FROM_BUFFER(1141,uint32 ,no,5);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,DUMMY::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for EXT_AIDA.
 *
 * Do not edit - automatically generated.
 */


/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for FEBEX_EVENT.
 *
 * Do not edit - automatically generated.
 */

// FEBEX_EVENT(card)
template<typename __data_src_t>
bool FEBEX_EVENT::__match(__data_src_t &__buffer,uint32 card)
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
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 unnamed_0_7 : 8; // 0..7
      uint32 trigger_type : 4; // 8..11
      uint32 sfpnr : 4; // 12..15
      uint32 card : 8; // 16..23
      uint32 unnamed_24_31 : 8; // 24..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_24_31 : 8; // 24..31
      uint32 card : 8; // 16..23
      uint32 sfpnr : 4; // 12..15
      uint32 trigger_type : 4; // 8..11
      uint32 unnamed_0_7 : 8; // 0..7
#endif
    };
    uint32  u32;
  } sumchannel;
  MATCH_READ_FROM_BUFFER_FULL(137,uint32 ,sumchannel,sumchannel.u32,16);
  MATCH_BITS_EQUAL(131,sumchannel.unnamed_0_7,52);
  MATCH_BITS_EQUAL(134,sumchannel.card,card);
  MATCH_BITS_EQUAL(135,sumchannel.unnamed_24_31,255);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN_ARG(bool,FEBEX_EVENT::__match,uint32 card);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TRACE.
 *
 * Do not edit - automatically generated.
 */

// TRACE(board)
template<typename __data_src_t>
bool TRACE::__match(__data_src_t &__buffer,uint32 board)
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
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 unnamed_0_7 : 8; // 0..7
      uint32 other : 8; // 8..15
      uint32 board : 4; // 16..19
      uint32 dummy_20_23 : 4;
      uint32 ch_id : 8; // 24..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 ch_id : 8; // 24..31
      uint32 dummy_20_23 : 4;
      uint32 board : 4; // 16..19
      uint32 other : 8; // 8..15
      uint32 unnamed_0_7 : 8; // 0..7
#endif
    };
    uint32  u32;
  } header;
  MATCH_READ_FROM_BUFFER_FULL(222,uint32 ,header,header.u32,22);
  MATCH_BITS_EQUAL(216,header.unnamed_0_7,52);
  MATCH_BITS_EQUAL(218,header.board,board);
  MATCH_UNNAMED_BITS_ZERO(222,header.u32,0x00f00000);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN_ARG(bool,TRACE::__match,uint32 board);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for FEBEX_EVENT_TRACES.
 *
 * Do not edit - automatically generated.
 */

// FEBEX_EVENT_TRACES(card)
template<typename __data_src_t>
bool FEBEX_EVENT_TRACES::__match(__data_src_t &__buffer,uint32 card)
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
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 unnamed_0_7 : 8; // 0..7
      uint32 trigger_type : 4; // 8..11
      uint32 sfpnr : 4; // 12..15
      uint32 board_id : 8; // 16..23
      uint32 unnamed_24_31 : 8; // 24..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_24_31 : 8; // 24..31
      uint32 board_id : 8; // 16..23
      uint32 sfpnr : 4; // 12..15
      uint32 trigger_type : 4; // 8..11
      uint32 unnamed_0_7 : 8; // 0..7
#endif
    };
    uint32  u32;
  } sumchannel;
  MATCH_READ_FROM_BUFFER_FULL(299,uint32 ,sumchannel,sumchannel.u32,34);
  MATCH_BITS_EQUAL(292,sumchannel.unnamed_0_7,52);
  MATCH_BITS_EQUAL(295,sumchannel.board_id,card);
  MATCH_BITS_EQUAL(296,sumchannel.unnamed_24_31,255);
  {
  }
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN_ARG(bool,FEBEX_EVENT_TRACES::__match,uint32 card);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for FEBEX_PADDING.
 *
 * Do not edit - automatically generated.
 */

// FEBEX_PADDING()
template<typename __data_src_t>
bool FEBEX_PADDING::__match(__data_src_t &__buffer)
{
  // UINT32 pads_data NOENCODE
  // {
    //  0_11: counter;
    // 12_19: index;
    // 20_31: 0xadd;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 counter : 12; // 0..11
      uint32 index : 8; // 12..19
      uint32 unnamed_20_31 : 12; // 20..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_20_31 : 12; // 20..31
      uint32 index : 8; // 12..19
      uint32 counter : 12; // 0..11
#endif
    };
    uint32  u32;
  } pads_data;
  MATCH_READ_FROM_BUFFER_FULL(111,uint32 ,pads_data,pads_data.u32,36);
  MATCH_BITS_EQUAL(110,pads_data.unnamed_20_31,0xadd);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,FEBEX_PADDING::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for MVLC_SCALER.
 *
 * Do not edit - automatically generated.
 */

// MVLC_SCALER(geo)
template<typename __data_src_t>
bool MVLC_SCALER::__match(__data_src_t &__buffer,uint32 geo)
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
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 whatever : 16; // 0..15
      uint32 unnamed_16_16 : 1; // 16
      uint32 dummy_17 : 1;
      uint32 nlw : 6; // 18..23
      uint32 type : 3; // 24..26
      uint32 geom : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 geom : 5; // 27..31
      uint32 type : 3; // 24..26
      uint32 nlw : 6; // 18..23
      uint32 dummy_17 : 1;
      uint32 unnamed_16_16 : 1; // 16
      uint32 whatever : 16; // 0..15
#endif
    };
    uint32  u32;
  } header;
  MATCH_READ_FROM_BUFFER_FULL(981,uint32 ,header,header.u32,40);
  MATCH_BITS_EQUAL(977,header.unnamed_16_16,0);
  MATCH_BITS_EQUAL(980,header.geom,geo);
  MATCH_UNNAMED_BITS_ZERO(981,header.u32,0x00020000);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN_ARG(bool,MVLC_SCALER::__match,uint32 geo);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for VME_CAEN_V7X5.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V7X5(geom)
template<typename __data_src_t>
bool VME_CAEN_V7X5::__match(__data_src_t &__buffer,uint32 geom)
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
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 undefined : 8; // 0..7
      uint32 count : 6; // 8..13
      uint32 dummy_14_15 : 2;
      uint32 crate : 8; // 16..23
      uint32 unnamed_24_26 : 3; // 24..26
      uint32 geom : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 geom : 5; // 27..31
      uint32 unnamed_24_26 : 3; // 24..26
      uint32 crate : 8; // 16..23
      uint32 dummy_14_15 : 2;
      uint32 count : 6; // 8..13
      uint32 undefined : 8; // 0..7
#endif
    };
    uint32  u32;
  } header;
  MATCH_READ_FROM_BUFFER_FULL(823,uint32 ,header,header.u32,45);
  MATCH_BITS_EQUAL(821,header.unnamed_24_26,2);
  MATCH_BITS_EQUAL(822,header.geom,geom);
  MATCH_UNNAMED_BITS_ZERO(823,header.u32,0x0000c000);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN_ARG(bool,VME_CAEN_V7X5::__match,uint32 geom);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TDC_HEADER.
 *
 * Do not edit - automatically generated.
 */

// TDC_HEADER()
template<typename __data_src_t>
bool TDC_HEADER::__match(__data_src_t &__buffer)
{
  // UINT32 tdc_header NOENCODE
  // {
    //  0_11: bunch_id;
    // 12_23: event_id;
    // 24_25: tdc;
    //    26: unused;
    // 27_31: 1;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 bunch_id : 12; // 0..11
      uint32 event_id : 12; // 12..23
      uint32 tdc : 2; // 24..25
      uint32 unused : 1; // 26
      uint32 unnamed_27_31 : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_27_31 : 5; // 27..31
      uint32 unused : 1; // 26
      uint32 tdc : 2; // 24..25
      uint32 event_id : 12; // 12..23
      uint32 bunch_id : 12; // 0..11
#endif
    };
    uint32  u32;
  } tdc_header;
  MATCH_READ_FROM_BUFFER_FULL(617,uint32 ,tdc_header,tdc_header.u32,47);
  MATCH_BITS_EQUAL(616,tdc_header.unnamed_27_31,1);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,TDC_HEADER::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TDC_DATA_V1290.
 *
 * Do not edit - automatically generated.
 */

// TDC_DATA_V1290()
template<typename __data_src_t>
bool TDC_DATA_V1290::__match(__data_src_t &__buffer)
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
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 tdc : 21; // 0..20
      uint32 chn : 5; // 21..25
      uint32 lot : 1; // 26
      uint32 unnamed_27_31 : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_27_31 : 5; // 27..31
      uint32 lot : 1; // 26
      uint32 chn : 5; // 21..25
      uint32 tdc : 21; // 0..20
#endif
    };
    uint32  u32;
  } tdc_data;
  MATCH_READ_FROM_BUFFER_FULL(634,uint32 ,tdc_data,tdc_data.u32,49);
  MATCH_BITS_EQUAL(630,tdc_data.unnamed_27_31,0);
  {
  }
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,TDC_DATA_V1290::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TDC_ERROR.
 *
 * Do not edit - automatically generated.
 */

// TDC_ERROR()
template<typename __data_src_t>
bool TDC_ERROR::__match(__data_src_t &__buffer)
{
  // UINT32 tdc_err NOENCODE
  // {
    //  0_14: error_flags;
    // 15_23: unused1;
    // 24_25: tdc;
    //    26: unused2;
    // 27_31: 4;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 error_flags : 15; // 0..14
      uint32 unused1 : 9; // 15..23
      uint32 tdc : 2; // 24..25
      uint32 unused2 : 1; // 26
      uint32 unnamed_27_31 : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_27_31 : 5; // 27..31
      uint32 unused2 : 1; // 26
      uint32 tdc : 2; // 24..25
      uint32 unused1 : 9; // 15..23
      uint32 error_flags : 15; // 0..14
#endif
    };
    uint32  u32;
  } tdc_err;
  MATCH_READ_FROM_BUFFER_FULL(663,uint32 ,tdc_err,tdc_err.u32,51);
  MATCH_BITS_EQUAL(662,tdc_err.unnamed_27_31,4);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,TDC_ERROR::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TDC_TRAILER.
 *
 * Do not edit - automatically generated.
 */

// TDC_TRAILER()
template<typename __data_src_t>
bool TDC_TRAILER::__match(__data_src_t &__buffer)
{
  // UINT32 tdc_trailer NOENCODE
  // {
    //  0_11: word_count;
    // 12_23: event_id;
    // 24_25: tdc;
    //    26: unused;
    // 27_31: 3;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 word_count : 12; // 0..11
      uint32 event_id : 12; // 12..23
      uint32 tdc : 2; // 24..25
      uint32 unused : 1; // 26
      uint32 unnamed_27_31 : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_27_31 : 5; // 27..31
      uint32 unused : 1; // 26
      uint32 tdc : 2; // 24..25
      uint32 event_id : 12; // 12..23
      uint32 word_count : 12; // 0..11
#endif
    };
    uint32  u32;
  } tdc_trailer;
  MATCH_READ_FROM_BUFFER_FULL(675,uint32 ,tdc_trailer,tdc_trailer.u32,53);
  MATCH_BITS_EQUAL(674,tdc_trailer.unnamed_27_31,3);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,TDC_TRAILER::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for VME_CAEN_V1290_N.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V1290_N()
template<typename __data_src_t>
bool VME_CAEN_V1290_N::__match(__data_src_t &__buffer)
{
  // MEMBER(DATA8 geo);
  // UINT32 header NOENCODE
  // {
    //  0_04: geom;
    //  5_26: event_count;
    // 27_31: type = MATCH(8);
    // ENCODE(geo,(value=geom));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 geom : 5; // 0..4
      uint32 event_count : 22; // 5..26
      uint32 type : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 type : 5; // 27..31
      uint32 event_count : 22; // 5..26
      uint32 geom : 5; // 0..4
#endif
    };
    uint32  u32;
  } header;
  MATCH_READ_FROM_BUFFER_FULL(689,uint32 ,header,header.u32,57);
  MATCH_BITS_EQUAL(686,header.type,8);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,VME_CAEN_V1290_N::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for MAIN_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// MAIN_CRATE_DATA()
template<typename __data_src_t>
bool MAIN_CRATE_DATA::__match(__data_src_t &__buffer)
{
  // barrier0 = BARRIER();
  MATCH_SUB_DECL(1000,BARRIER,barrier0);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,MAIN_CRATE_DATA::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for SPILL_OFF.
 *
 * Do not edit - automatically generated.
 */

// SPILL_OFF()
template<typename __data_src_t>
bool SPILL_OFF::__match(__data_src_t &__buffer)
{
  // MEMBER(DATA8 spilloff);
  // UINT32 off1 NOENCODE
  // {
    //  0_31: 0x4040400a;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 unnamed_0_31 : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_0_31 : 32; // 0..31
#endif
    };
    uint32  u32;
  } off1;
  MATCH_READ_FROM_BUFFER_FULL(888,uint32 ,off1,off1.u32,64);
  MATCH_BITS_EQUAL(887,off1.unnamed_0_31,0x4040400a);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,SPILL_OFF::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for SPILL_ON.
 *
 * Do not edit - automatically generated.
 */

// SPILL_ON()
template<typename __data_src_t>
bool SPILL_ON::__match(__data_src_t &__buffer)
{
  // MEMBER(DATA8 spillon);
  // UINT32 on NOENCODE
  // {
    //  0_31: 0x30303030;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 unnamed_0_31 : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_0_31 : 32; // 0..31
#endif
    };
    uint32  u32;
  } on;
  MATCH_READ_FROM_BUFFER_FULL(877,uint32 ,on,on.u32,66);
  MATCH_BITS_EQUAL(876,on.unnamed_0_31,0x30303030);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,SPILL_ON::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TAMEX4_EPOCH_DATA.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_EPOCH_DATA(sfp,card,time_coarse,time_fine,time_edge,time_channel,
                  // time_epoch)
template<typename __data_src_t>
bool TAMEX4_EPOCH_DATA::__match(__data_src_t &__buffer,uint32 sfp,uint32 card)
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
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 epoch : 28; // 0..27
      uint32 unnamed_28_31 : 4; // 28..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_28_31 : 4; // 28..31
      uint32 epoch : 28; // 0..27
#endif
    };
    uint32  u32;
  } data;
  MATCH_READ_FROM_BUFFER_FULL(473,uint32 ,data,data.u32,68);
  MATCH_BITS_EQUAL(466,data.unnamed_28_31,6);
  {
  }
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN_ARG(bool,TAMEX4_EPOCH_DATA::__match,uint32 sfp,uint32 card);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TAMEX4_HEADER.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_HEADER()
template<typename __data_src_t>
bool TAMEX4_HEADER::__match(__data_src_t &__buffer)
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
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 post_trig_ns : 16; // 0..15
      uint32 pre_trig_ns : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 pre_trig_ns : 16; // 16..31
      uint32 post_trig_ns : 16; // 0..15
#endif
    };
    uint32  u32;
  } trigger_window;
  MATCH_READ_FROM_BUFFER_FULL(415,uint32 ,trigger_window,trigger_window.u32,70);
  {
  }
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,TAMEX4_HEADER::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TAMEX4_PADDING.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_PADDING()
template<typename __data_src_t>
bool TAMEX4_PADDING::__match(__data_src_t &__buffer)
{
  // UINT32 padding NOENCODE
  // {
    //  0_11: counter;
    // 12_19: index;
    // 20_31: 0xadd;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 counter : 12; // 0..11
      uint32 index : 8; // 12..19
      uint32 unnamed_20_31 : 12; // 20..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_20_31 : 12; // 20..31
      uint32 index : 8; // 12..19
      uint32 counter : 12; // 0..11
#endif
    };
    uint32  u32;
  } padding;
  MATCH_READ_FROM_BUFFER_FULL(426,uint32 ,padding,padding.u32,72);
  MATCH_BITS_EQUAL(425,padding.unnamed_20_31,0xadd);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,TAMEX4_PADDING::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TAMEX4_TIME_DATA.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_TIME_DATA(sfp,card,time_coarse,time_fine,time_edge,time_channel,
                 // time_epoch)
template<typename __data_src_t>
bool TAMEX4_TIME_DATA::__match(__data_src_t &__buffer,uint32 sfp,uint32 card)
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
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 coarse : 11; // 0..10
      uint32 is_leading : 1; // 11
      uint32 fine : 10; // 12..21
      uint32 channel : 6; // 22..27
      uint32 type : 4; // 28..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 type : 4; // 28..31
      uint32 channel : 6; // 22..27
      uint32 fine : 10; // 12..21
      uint32 is_leading : 1; // 11
      uint32 coarse : 11; // 0..10
#endif
    };
    uint32  u32;
  } data;
  MATCH_READ_FROM_BUFFER_FULL(451,uint32 ,data,data.u32,74);
  MATCH_BITS_EQUAL(444,data.type,8);
  {
  }
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN_ARG(bool,TAMEX4_TIME_DATA::__match,uint32 sfp,uint32 card);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TAMEX4_SFP.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_SFP(sfp,card)
template<typename __data_src_t>
bool TAMEX4_SFP::__match(__data_src_t &__buffer,uint32 sfp,uint32 card)
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
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 unnamed_0_7 : 8; // 0..7
      uint32 trigger_type : 4; // 8..11
      uint32 sfp : 4; // 12..15
      uint32 card : 8; // 16..23
      uint32 unnamed_24_31 : 8; // 24..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_24_31 : 8; // 24..31
      uint32 card : 8; // 16..23
      uint32 sfp : 4; // 12..15
      uint32 trigger_type : 4; // 8..11
      uint32 unnamed_0_7 : 8; // 0..7
#endif
    };
    uint32  u32;
  } indicator;
  MATCH_READ_FROM_BUFFER_FULL(495,uint32 ,indicator,indicator.u32,80);
  MATCH_BITS_EQUAL(489,indicator.unnamed_0_7,52);
  MATCH_BITS_EQUAL(491,indicator.sfp,sfp);
  MATCH_BITS_EQUAL(492,indicator.card,card);
  MATCH_BITS_EQUAL(493,indicator.unnamed_24_31,0);
  // MATCH_END;
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN_ARG(bool,TAMEX4_SFP::__match,uint32 sfp,uint32 card);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TDC_DATA_V1190.
 *
 * Do not edit - automatically generated.
 */

// TDC_DATA_V1190()
template<typename __data_src_t>
bool TDC_DATA_V1190::__match(__data_src_t &__buffer)
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
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 tdc : 19; // 0..18
      uint32 chn : 7; // 19..25
      uint32 lot : 1; // 26
      uint32 unnamed_27_31 : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_27_31 : 5; // 27..31
      uint32 lot : 1; // 26
      uint32 chn : 7; // 19..25
      uint32 tdc : 19; // 0..18
#endif
    };
    uint32  u32;
  } tdc_data;
  MATCH_READ_FROM_BUFFER_FULL(651,uint32 ,tdc_data,tdc_data.u32,82);
  MATCH_BITS_EQUAL(647,tdc_data.unnamed_27_31,0);
  {
  }
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,TDC_DATA_V1190::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TIMESTAMP_WHITERABBIT.
 *
 * Do not edit - automatically generated.
 */

// TIMESTAMP_WHITERABBIT(id)
template<typename __data_src_t>
bool TIMESTAMP_WHITERABBIT::__match(__data_src_t &__buffer,uint32 id)
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
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 id : 12; // 0..11
      uint32 unnamed_12_15 : 4; // 12..15
      uint32 error_bit : 1; // 16
      uint32 unnamed_17_31 : 15; // 17..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_17_31 : 15; // 17..31
      uint32 error_bit : 1; // 16
      uint32 unnamed_12_15 : 4; // 12..15
      uint32 id : 12; // 0..11
#endif
    };
    uint32  u32;
  } header;
  MATCH_READ_FROM_BUFFER_FULL(24,uint32 ,header,header.u32,88);
  MATCH_BITS_EQUAL(19,header.id,id);
  MATCH_BITS_EQUAL(20,header.unnamed_12_15,0);
  MATCH_BITS_EQUAL(22,header.unnamed_17_31,0);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN_ARG(bool,TIMESTAMP_WHITERABBIT::__match,uint32 id);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TIMESTAMP_WHITERABBIT_EXTENDED.
 *
 * Do not edit - automatically generated.
 */

// TIMESTAMP_WHITERABBIT_EXTENDED(id)
template<typename __data_src_t>
bool TIMESTAMP_WHITERABBIT_EXTENDED::__match(__data_src_t &__buffer,uint32 id)
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
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 id : 13; // 0..12
      uint32 unnamed_13_15 : 3; // 13..15
      uint32 error_bit : 1; // 16
      uint32 unnamed_17_31 : 15; // 17..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_17_31 : 15; // 17..31
      uint32 error_bit : 1; // 16
      uint32 unnamed_13_15 : 3; // 13..15
      uint32 id : 13; // 0..12
#endif
    };
    uint32  u32;
  } header;
  MATCH_READ_FROM_BUFFER_FULL(61,uint32 ,header,header.u32,94);
  MATCH_BITS_EQUAL(56,header.id,id);
  MATCH_BITS_EQUAL(57,header.unnamed_13_15,0);
  MATCH_BITS_EQUAL(59,header.unnamed_17_31,0);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN_ARG(bool,TIMESTAMP_WHITERABBIT_EXTENDED::__match,uint32 id);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TPAT_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// TPAT_CRATE_DATA()
template<typename __data_src_t>
bool TPAT_CRATE_DATA::__match(__data_src_t &__buffer)
{
  // MEMBER(DATA16 tpat);
  // UINT32 w1;
  uint32  __w1;
  MATCH_READ_FROM_BUFFER(926,uint32 ,__w1,104);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,TPAT_CRATE_DATA::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for VME_CAEN_V1190_N.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V1190_N()
template<typename __data_src_t>
bool VME_CAEN_V1190_N::__match(__data_src_t &__buffer)
{
  // MEMBER(DATA8 geo);
  // UINT32 header NOENCODE
  // {
    //  0_04: geom;
    //  5_26: event_count;
    // 27_31: seven_f;
    // ENCODE(geo,(value=geom));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 geom : 5; // 0..4
      uint32 event_count : 22; // 5..26
      uint32 seven_f : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 seven_f : 5; // 27..31
      uint32 event_count : 22; // 5..26
      uint32 geom : 5; // 0..4
#endif
    };
    uint32  u32;
  } header;
  MATCH_READ_FROM_BUFFER_FULL(730,uint32 ,header,header.u32,111);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,VME_CAEN_V1190_N::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TPC_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// TPC_CRATE_DATA()
template<typename __data_src_t>
bool TPC_CRATE_DATA::__match(__data_src_t &__buffer)
{
  // select several

    // barrier0 = BARRIER();
    // v785 = VME_CAEN_V7X5(geom=8);
    // v775 = VME_CAEN_V7X5(geom=12);
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    MATCH_DECL(1023,__match_no,1,BARRIER,barrier0);
    MATCH_DECL(1024,__match_no,2,VME_CAEN_V7X5,v785,/*geom*/8);
    MATCH_DECL(1025,__match_no,3,VME_CAEN_V7X5,v775,/*geom*/12);
    if (!__match_no) break;
    return true;
  }
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,TPC_CRATE_DATA::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for VME_MESYTEC_MDPP16.
 *
 * Do not edit - automatically generated.
 */

// VME_MESYTEC_MDPP16(geom)
template<typename __data_src_t>
bool VME_MESYTEC_MDPP16::__match(__data_src_t &__buffer,uint32 geom)
{
  // MEMBER(DATA24 adc[16]);
  // MEMBER(DATA24 tdc[16]);
  // MEMBER(DATA24 trig_tdc[16]);
  // MEMBER(DATA24 adc_short[16]);
  // MARK_COUNT(start);
  // UINT32 header NOENCODE
  // {
    //  0_09: word_number;
    // 10_12: adc_res;
    // 13_15: tdc_res;
    // 16_23: geom = MATCH(geom);
    // 24_29: 0;
    // 30_31: 1;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 word_number : 10; // 0..9
      uint32 adc_res : 3; // 10..12
      uint32 tdc_res : 3; // 13..15
      uint32 geom : 8; // 16..23
      uint32 unnamed_24_29 : 6; // 24..29
      uint32 unnamed_30_31 : 2; // 30..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_30_31 : 2; // 30..31
      uint32 unnamed_24_29 : 6; // 24..29
      uint32 geom : 8; // 16..23
      uint32 tdc_res : 3; // 13..15
      uint32 adc_res : 3; // 10..12
      uint32 word_number : 10; // 0..9
#endif
    };
    uint32  u32;
  } header;
  MATCH_READ_FROM_BUFFER_FULL(559,uint32 ,header,header.u32,118);
  MATCH_BITS_EQUAL(556,header.geom,geom);
  MATCH_BITS_EQUAL(557,header.unnamed_24_29,0);
  MATCH_BITS_EQUAL(558,header.unnamed_30_31,1);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN_ARG(bool,VME_MESYTEC_MDPP16::__match,uint32 geom);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TRAVMUS_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// TRAVMUS_CRATE_DATA()
template<typename __data_src_t>
bool TRAVMUS_CRATE_DATA::__match(__data_src_t &__buffer)
{
  // UINT32 coffee NOENCODE
  // {
    //  0_07: counter;
    //  8_31: 0x00c0ffee;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 counter : 8; // 0..7
      uint32 unnamed_8_31 : 24; // 8..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_8_31 : 24; // 8..31
      uint32 counter : 8; // 0..7
#endif
    };
    uint32  u32;
  } coffee;
  MATCH_READ_FROM_BUFFER_FULL(1089,uint32 ,coffee,coffee.u32,124);
  MATCH_BITS_EQUAL(1088,coffee.unnamed_8_31,0x00c0ffee);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,TRAVMUS_CRATE_DATA::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for TRIG3EVENT.
 *
 * Do not edit - automatically generated.
 */

// TRIG3EVENT()
template<typename __data_src_t>
bool TRIG3EVENT::__match(__data_src_t &__buffer)
{
  // UINT32 trig3 NOENCODE
  // {
    //  0_31: 0x20202020;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 unnamed_0_31 : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_0_31 : 32; // 0..31
#endif
    };
    uint32  u32;
  } trig3;
  MATCH_READ_FROM_BUFFER_FULL(868,uint32 ,trig3,trig3.u32,126);
  MATCH_BITS_EQUAL(867,trig3.unnamed_0_31,0x20202020);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,TRIG3EVENT::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for USER_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// USER_CRATE_DATA()
template<typename __data_src_t>
bool USER_CRATE_DATA::__match(__data_src_t &__buffer)
{
  // barrier0 = BARRIER();
  MATCH_SUB_DECL(1044,BARRIER,barrier0);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,USER_CRATE_DATA::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for VME_CAEN_V830.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V830(geom)
template<typename __data_src_t>
bool VME_CAEN_V830::__match(__data_src_t &__buffer,uint32 geom)
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
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 event_number : 16; // 0..15
      uint32 ts : 2; // 16..17
      uint32 count : 6; // 18..23
      uint32 undefined : 2; // 24..25
      uint32 unnamed_26_26 : 1; // 26
      uint32 geom : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 geom : 5; // 27..31
      uint32 unnamed_26_26 : 1; // 26
      uint32 undefined : 2; // 24..25
      uint32 count : 6; // 18..23
      uint32 ts : 2; // 16..17
      uint32 event_number : 16; // 0..15
#endif
    };
    uint32  u32;
  } __header;
  MATCH_READ_FROM_BUFFER_FULL(792,uint32 ,header,__header.u32,132);
  MATCH_BITS_EQUAL(790,__header.unnamed_26_26,1);
  MATCH_BITS_EQUAL(791,__header.geom,geom);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN_ARG(bool,VME_CAEN_V830::__match,uint32 geom);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for VULOM_TPAT.
 *
 * Do not edit - automatically generated.
 */

// VULOM_TPAT()
template<typename __data_src_t>
bool VULOM_TPAT::__match(__data_src_t &__buffer)
{
  // UINT32 vulom_head NOENCODE
  // {
    //  0_15: counter;
    // 16_31: head = MATCH(0xf500);
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 counter : 16; // 0..15
      uint32 head : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 head : 16; // 16..31
      uint32 counter : 16; // 0..15
#endif
    };
    uint32  u32;
  } vulom_head;
  MATCH_READ_FROM_BUFFER_FULL(1073,uint32 ,vulom_head,vulom_head.u32,135);
  MATCH_BITS_EQUAL(1072,vulom_head.head,0xf500);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,VULOM_TPAT::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for WR_MULTI.
 *
 * Do not edit - automatically generated.
 */

// WR_MULTI()
template<typename __data_src_t>
bool WR_MULTI::__match(__data_src_t &__buffer)
{
  // MEMBER(DATA32 time_hi);
  // MEMBER(DATA32 time_lo);
  // UINT32 hi NOENCODE
  // {
    //  0_31: time;
    // ENCODE(time_hi,(value=time));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 time : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 time : 32; // 0..31
#endif
    };
    uint32  u32;
  } hi;
  MATCH_READ_FROM_BUFFER_FULL(92,uint32 ,hi,hi.u32,138);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,WR_MULTI::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for ZERO_FILLER.
 *
 * Do not edit - automatically generated.
 */

// ZERO_FILLER()
template<typename __data_src_t>
bool ZERO_FILLER::__match(__data_src_t &__buffer)
{
  // UINT32 filler NOENCODE
  // {
    //  0_31: zero = MATCH(0);
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 zero : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 zero : 32; // 0..31
#endif
    };
    uint32  u32;
  } filler;
  MATCH_READ_FROM_BUFFER_FULL(917,uint32 ,filler,filler.u32,140);
  MATCH_BITS_EQUAL(916,filler.zero,0);
  return true;
  return false;
}
FORCE_IMPL_DATA_SRC_FCN(bool,ZERO_FILLER::__match);

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for aida_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(aida_subev)
// No __match function for subevents.

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for bplast_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(bplast_subev)
// No __match function for subevents.

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for febex_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(febex_subev)
// No __match function for subevents.

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for frs_main_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_main_subev)
// No __match function for subevents.

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for frs_tpat_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_tpat_subev)
// No __match function for subevents.

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for frs_tpc_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_tpc_subev)
// No __match function for subevents.

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for frs_travmus_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_travmus_subev)
// No __match function for subevents.

/** END_MATCHER *******************************************************/
/** BEGIN_MATCHER ******************************************************
 *
 * Event matcher for frs_user_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_user_subev)
// No __match function for subevents.

/** END_MATCHER *******************************************************/
