/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for BAD_EVENT.
 *
 * Do not edit - automatically generated.
 */

// BAD_EVENT()
template<typename __data_src_t>
void BAD_EVENT::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "BAD_EVENT",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(1134,uint32 ,be,be.u32,0);
  CHECK_BITS_EQUAL(1133,be.b,0xbad00bad);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: be ", CT_OUT(BOLD), be.u32, CT_OUT(NORM));
    printf(".b=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  be.b, CT_OUT(NORM));
    printf("\n");
  }
  // ENCODE(bad,(value=1));

  {
    bad.value = 1;
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,BAD_EVENT::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for BARRIER.
 *
 * Do not edit - automatically generated.
 */

// BARRIER()
template<typename __data_src_t>
void BARRIER::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "BARRIER",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(909,uint32 ,barrier,barrier.u32,2);
  CHECK_BITS_RANGE(908,barrier.ba,0xf52,0xf58);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: barrier ", CT_OUT(BOLD), barrier.u32, CT_OUT(NORM));
    printf(".no=%s%5" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  barrier.no, CT_OUT(NORM));
    printf(".ba=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  barrier.ba, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,BARRIER::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for DUMMY.
 *
 * Do not edit - automatically generated.
 */

// DUMMY()
template<typename __data_src_t>
void DUMMY::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "DUMMY",CT_OUT(NORM));
  }
  // UINT32 no NOENCODE;
  uint32  no;READ_FROM_BUFFER(1141,uint32 ,no,4);
}
FORCE_IMPL_DATA_SRC_FCN(void,DUMMY::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for EXT_AIDA.
 *
 * Do not edit - automatically generated.
 */


/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for FEBEX_EVENT.
 *
 * Do not edit - automatically generated.
 */

// FEBEX_EVENT(card)
template<typename __data_src_t>
void FEBEX_EVENT::__unpack(__data_src_t &__buffer,uint32 card)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "FEBEX_EVENT",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(137,uint32 ,sumchannel,sumchannel.u32,6);
  CHECK_BITS_EQUAL(131,sumchannel.unnamed_0_7,52);
  CHECK_BITS_EQUAL(134,sumchannel.card,card);
  CHECK_BITS_EQUAL(135,sumchannel.unnamed_24_31,255);
  {
    trig.value = sumchannel.trigger_type;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: sumchannel ", CT_OUT(BOLD), sumchannel.u32, CT_OUT(NORM));
    printf(".trigger_type=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  sumchannel.trigger_type, CT_OUT(NORM));
    printf(".sfpnr=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  sumchannel.sfpnr, CT_OUT(NORM));
    printf(".card=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  sumchannel.card, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 channel_size NOENCODE
  // {
    //  0_01: ignore;
    //  2_31: size;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 ignore : 2; // 0..1
      uint32 size : 30; // 2..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 size : 30; // 2..31
      uint32 ignore : 2; // 0..1
#endif
    };
    uint32  u32;
  } channel_size;
  READ_FROM_BUFFER_FULL(145,uint32 ,channel_size,channel_size.u32,7);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: channel_size ", CT_OUT(BOLD), channel_size.u32, CT_OUT(NORM));
    printf(".ignore=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channel_size.ignore, CT_OUT(NORM));
    printf(".size=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channel_size.size, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 event_timestamp_hi NOENCODE
  // {
    //  0_15: timestamp_hi;
    // 16_31: ignore;
    // ENCODE(event_trigger_time_hi,(value=timestamp_hi));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 timestamp_hi : 16; // 0..15
      uint32 ignore : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 ignore : 16; // 16..31
      uint32 timestamp_hi : 16; // 0..15
#endif
    };
    uint32  u32;
  } event_timestamp_hi;
  READ_FROM_BUFFER_FULL(154,uint32 ,event_timestamp_hi,event_timestamp_hi.u32,8);
  {
    event_trigger_time_hi.value = event_timestamp_hi.timestamp_hi;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: event_timestamp_hi ", CT_OUT(BOLD), event_timestamp_hi.u32, CT_OUT(NORM));
    printf(".timestamp_hi=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  event_timestamp_hi.timestamp_hi, CT_OUT(NORM));
    printf(".ignore=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  event_timestamp_hi.ignore, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 event_timestamp_lo NOENCODE
  // {
    //  0_31: timestamp_lo;
    // ENCODE(event_trigger_time_lo,(value=timestamp_lo));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 timestamp_lo : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 timestamp_lo : 32; // 0..31
#endif
    };
    uint32  u32;
  } event_timestamp_lo;
  READ_FROM_BUFFER_FULL(160,uint32 ,event_timestamp_lo,event_timestamp_lo.u32,9);
  {
    event_trigger_time_lo.value = event_timestamp_lo.timestamp_lo;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: event_timestamp_lo ", CT_OUT(BOLD), event_timestamp_lo.u32, CT_OUT(NORM));
    printf(".timestamp_lo=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  event_timestamp_lo.timestamp_lo, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 hp NOENCODE
  // {
    //  0_15: hp;
    // 16_31: ignore;
    // ENCODE(hit_pattern,(value=hp));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 hp : 16; // 0..15
      uint32 ignore : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 ignore : 16; // 16..31
      uint32 hp : 16; // 0..15
#endif
    };
    uint32  u32;
  } hp;
  READ_FROM_BUFFER_FULL(168,uint32 ,hp,hp.u32,10);
  {
    hit_pattern.value = hp.hp;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: hp ", CT_OUT(BOLD), hp.u32, CT_OUT(NORM));
    printf(".hp=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  hp.hp, CT_OUT(NORM));
    printf(".ignore=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  hp.ignore, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 deadbeef NOENCODE
  // {
    //  0_31: 0xdeadbeef;
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
  } deadbeef;
  READ_FROM_BUFFER_FULL(173,uint32 ,deadbeef,deadbeef.u32,11);
  CHECK_BITS_EQUAL(172,deadbeef.unnamed_0_31,0xdeadbeef);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: deadbeef ", CT_OUT(BOLD), deadbeef.u32, CT_OUT(NORM));
    printf("\n");
  }
  // list(0<=index<((channel_size.size / 4) - 1))

  for (uint32 index = 0; index < (uint32) (((channel_size.size / 4) - 1)); ++index)
  {
    // UINT32 channelids NOENCODE
    // {
      //  0_15: chan_ts_hi;
      // 16_23: channel_id_bits;
      // 24_31: 240;
      // ENCODE(channel_trigger_time_hi[channelids.channel_id_bits],(value=chan_ts_hi));
    // }
    union
    {
      struct
      {
#if __BYTE_ORDER == __LITTLE_ENDIAN
        uint32 chan_ts_hi : 16; // 0..15
        uint32 channel_id_bits : 8; // 16..23
        uint32 unnamed_24_31 : 8; // 24..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
        uint32 unnamed_24_31 : 8; // 24..31
        uint32 channel_id_bits : 8; // 16..23
        uint32 chan_ts_hi : 16; // 0..15
#endif
      };
      uint32  u32;
    } channelids;
    READ_FROM_BUFFER_FULL(184,uint32 ,channelids,channelids.u32,12);
    CHECK_BITS_EQUAL(180,channelids.unnamed_24_31,240);
    {
      typedef __typeof__(*(&(channel_trigger_time_hi))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = channel_trigger_time_hi.insert_index(183,channelids.channel_id_bits);
      __item.value = channelids.chan_ts_hi;
    }
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: channelids ", CT_OUT(BOLD), channelids.u32, CT_OUT(NORM));
      printf(".chan_ts_hi=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channelids.chan_ts_hi, CT_OUT(NORM));
      printf(".channel_id_bits=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channelids.channel_id_bits, CT_OUT(NORM));
      printf("\n");
    }
    // UINT32 channel_ts NOENCODE
    // {
      //  0_31: chan_ts_lo;
      // ENCODE(channel_trigger_time_lo[channelids.channel_id_bits],(value=chan_ts_lo));
    // }
    union
    {
      struct
      {
#if __BYTE_ORDER == __LITTLE_ENDIAN
        uint32 chan_ts_lo : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
        uint32 chan_ts_lo : 32; // 0..31
#endif
      };
      uint32  u32;
    } channel_ts;
    READ_FROM_BUFFER_FULL(189,uint32 ,channel_ts,channel_ts.u32,13);
    {
      typedef __typeof__(*(&(channel_trigger_time_lo))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = channel_trigger_time_lo.insert_index(188,channelids.channel_id_bits);
      __item.value = channel_ts.chan_ts_lo;
    }
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: channel_ts ", CT_OUT(BOLD), channel_ts.u32, CT_OUT(NORM));
      printf(".chan_ts_lo=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channel_ts.chan_ts_lo, CT_OUT(NORM));
      printf("\n");
    }
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
    union
    {
      struct
      {
#if __BYTE_ORDER == __LITTLE_ENDIAN
        uint32 chan_energy : 24; // 0..23
        uint32 TSF : 6; // 24..29
        uint32 pileup_flag : 1; // 30
        uint32 overflow_flag : 1; // 31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
        uint32 overflow_flag : 1; // 31
        uint32 pileup_flag : 1; // 30
        uint32 TSF : 6; // 24..29
        uint32 chan_energy : 24; // 0..23
#endif
      };
      uint32  u32;
    } chan_enrgy;
    READ_FROM_BUFFER_FULL(201,uint32 ,chan_enrgy,chan_enrgy.u32,14);
    {
      {
        typedef __typeof__(*(&(channel_cfd))) __array_t;
        typedef typename __array_t::item_t __item_t;
        __item_t &__item = channel_cfd.insert_index(197,channelids.channel_id_bits);
        __item.value = chan_enrgy.TSF;
      }
      {
        typedef __typeof__(*(&(channel_energy))) __array_t;
        typedef typename __array_t::item_t __item_t;
        __item_t &__item = channel_energy.insert_index(198,channelids.channel_id_bits);
        __item.value = chan_enrgy.chan_energy;
      }
      {
        typedef __typeof__(*(&(pileup))) __array_t;
        typedef typename __array_t::item_t __item_t;
        __item_t &__item = pileup.insert_index(199,channelids.channel_id_bits);
        __item.value = chan_enrgy.pileup_flag;
      }
      {
        typedef __typeof__(*(&(overflow))) __array_t;
        typedef typename __array_t::item_t __item_t;
        __item_t &__item = overflow.insert_index(200,channelids.channel_id_bits);
        __item.value = chan_enrgy.overflow_flag;
      }
    }
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: chan_enrgy ", CT_OUT(BOLD), chan_enrgy.u32, CT_OUT(NORM));
      printf(".chan_energy=%s%6" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  chan_enrgy.chan_energy, CT_OUT(NORM));
      printf(".TSF=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  chan_enrgy.TSF, CT_OUT(NORM));
      printf(".pileup_flag=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  chan_enrgy.pileup_flag, CT_OUT(NORM));
      printf(".overflow_flag=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  chan_enrgy.overflow_flag, CT_OUT(NORM));
      printf("\n");
    }
    // UINT32 future_use NOENCODE
    // {
      //  0_31: 0;
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
    } future_use;
    READ_FROM_BUFFER_FULL(205,uint32 ,future_use,future_use.u32,15);
    CHECK_BITS_EQUAL(204,future_use.unnamed_0_31,0);
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: future_use ", CT_OUT(BOLD), future_use.u32, CT_OUT(NORM));
      printf("\n");
    }
  }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,FEBEX_EVENT::__unpack,uint32 card);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TRACE.
 *
 * Do not edit - automatically generated.
 */

// TRACE(board)
template<typename __data_src_t>
void TRACE::__unpack(__data_src_t &__buffer,uint32 board)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TRACE",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(222,uint32 ,header,header.u32,17);
  CHECK_BITS_EQUAL(216,header.unnamed_0_7,52);
  CHECK_BITS_EQUAL(218,header.board,board);
  CHECK_UNNAMED_BITS_ZERO(222,header.u32,0x00f00000);
  {
    typedef __typeof__(*(&(channel_id_traces))) __array_t;
    typedef typename __array_t::item_t __item_t;
    __item_t &__item = channel_id_traces.insert_index(220,header.ch_id);
    __item.value = header.ch_id;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: header ", CT_OUT(BOLD), header.u32, CT_OUT(NORM));
    printf(".other=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.other, CT_OUT(NORM));
    printf(".board=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.board, CT_OUT(NORM));
    printf(".ch_id=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.ch_id, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 tracesize NOENCODE
  // {
    //  0_31: size;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 size : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 size : 32; // 0..31
#endif
    };
    uint32  u32;
  } tracesize;
  READ_FROM_BUFFER_FULL(227,uint32 ,tracesize,tracesize.u32,18);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: tracesize ", CT_OUT(BOLD), tracesize.u32, CT_OUT(NORM));
    printf(".size=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tracesize.size, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 tracehead NOENCODE
  // {
    //  0_23: other;
    // 24_31: head;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 other : 24; // 0..23
      uint32 head : 8; // 24..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 head : 8; // 24..31
      uint32 other : 24; // 0..23
#endif
    };
    uint32  u32;
  } tracehead;
  READ_FROM_BUFFER_FULL(233,uint32 ,tracehead,tracehead.u32,19);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: tracehead ", CT_OUT(BOLD), tracehead.u32, CT_OUT(NORM));
    printf(".other=%s%6" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tracehead.other, CT_OUT(NORM));
    printf(".head=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tracehead.head, CT_OUT(NORM));
    printf("\n");
  }
  // list(0<=j<((tracesize.size / 4) - 2))

  for (uint32 j = 0; j < (uint32) (((tracesize.size / 4) - 2)); ++j)
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
    union
    {
      struct
      {
#if __BYTE_ORDER == __LITTLE_ENDIAN
        uint32 data1 : 14; // 0..13
        uint32 stuff1 : 2; // 14..15
        uint32 data2 : 14; // 16..29
        uint32 stuff2 : 2; // 30..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
        uint32 stuff2 : 2; // 30..31
        uint32 data2 : 14; // 16..29
        uint32 stuff1 : 2; // 14..15
        uint32 data1 : 14; // 0..13
#endif
      };
      uint32  u32;
    } channel_trace;
    READ_FROM_BUFFER_FULL(253,uint32 ,channel_trace,channel_trace.u32,20);
    {
      {
        typedef __typeof__(*(&(traces[header.ch_id]))) __array_t;
        typedef typename __array_t::item_t __item_t;
        __item_t &__item = traces[header.ch_id].insert_index(251,((2 * j) + 0));
        __item.value = channel_trace.data1;
      }
      {
        typedef __typeof__(*(&(traces[header.ch_id]))) __array_t;
        typedef typename __array_t::item_t __item_t;
        __item_t &__item = traces[header.ch_id].insert_index(252,((2 * j) + 1));
        __item.value = channel_trace.data2;
      }
    }
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: channel_trace ", CT_OUT(BOLD), channel_trace.u32, CT_OUT(NORM));
      printf(".data1=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channel_trace.data1, CT_OUT(NORM));
      printf(".stuff1=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channel_trace.stuff1, CT_OUT(NORM));
      printf(".data2=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channel_trace.data2, CT_OUT(NORM));
      printf(".stuff2=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channel_trace.stuff2, CT_OUT(NORM));
      printf("\n");
    }
  }
  // UINT32 trace_trailer NOENCODE
  // {
    //  0_23: notused;
    // 24_31: id = RANGE(176,191);
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 notused : 24; // 0..23
      uint32 id : 8; // 24..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 id : 8; // 24..31
      uint32 notused : 24; // 0..23
#endif
    };
    uint32  u32;
  } trace_trailer;
  READ_FROM_BUFFER_FULL(262,uint32 ,trace_trailer,trace_trailer.u32,21);
  CHECK_BITS_RANGE(261,trace_trailer.id,176,191);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: trace_trailer ", CT_OUT(BOLD), trace_trailer.u32, CT_OUT(NORM));
    printf(".notused=%s%6" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trace_trailer.notused, CT_OUT(NORM));
    printf(".id=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trace_trailer.id, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,TRACE::__unpack,uint32 board);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for FEBEX_EVENT_TRACES.
 *
 * Do not edit - automatically generated.
 */

// FEBEX_EVENT_TRACES(card)
template<typename __data_src_t>
void FEBEX_EVENT_TRACES::__unpack(__data_src_t &__buffer,uint32 card)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "FEBEX_EVENT_TRACES",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(299,uint32 ,sumchannel,sumchannel.u32,23);
  CHECK_BITS_EQUAL(292,sumchannel.unnamed_0_7,52);
  CHECK_BITS_EQUAL(295,sumchannel.board_id,card);
  CHECK_BITS_EQUAL(296,sumchannel.unnamed_24_31,255);
  {
    {
      board_num.value = sumchannel.board_id;
    }
    {
      trig.value = sumchannel.trigger_type;
    }
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: sumchannel ", CT_OUT(BOLD), sumchannel.u32, CT_OUT(NORM));
    printf(".trigger_type=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  sumchannel.trigger_type, CT_OUT(NORM));
    printf(".sfpnr=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  sumchannel.sfpnr, CT_OUT(NORM));
    printf(".board_id=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  sumchannel.board_id, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 channel_size NOENCODE
  // {
    //  0_01: ignore;
    //  2_31: size;
    // ENCODE(num_channels_fired,(value=((size / 4) - 1)));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 ignore : 2; // 0..1
      uint32 size : 30; // 2..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 size : 30; // 2..31
      uint32 ignore : 2; // 0..1
#endif
    };
    uint32  u32;
  } channel_size;
  READ_FROM_BUFFER_FULL(309,uint32 ,channel_size,channel_size.u32,24);
  {
    num_channels_fired.value = ((channel_size.size / 4) - 1);
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: channel_size ", CT_OUT(BOLD), channel_size.u32, CT_OUT(NORM));
    printf(".ignore=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channel_size.ignore, CT_OUT(NORM));
    printf(".size=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channel_size.size, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 event_timestamp_hi NOENCODE
  // {
    //  0_15: timestamp_hi;
    // 16_31: ignore;
    // ENCODE(event_trigger_time_hi,(value=timestamp_hi));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 timestamp_hi : 16; // 0..15
      uint32 ignore : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 ignore : 16; // 16..31
      uint32 timestamp_hi : 16; // 0..15
#endif
    };
    uint32  u32;
  } event_timestamp_hi;
  READ_FROM_BUFFER_FULL(318,uint32 ,event_timestamp_hi,event_timestamp_hi.u32,25);
  {
    event_trigger_time_hi.value = event_timestamp_hi.timestamp_hi;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: event_timestamp_hi ", CT_OUT(BOLD), event_timestamp_hi.u32, CT_OUT(NORM));
    printf(".timestamp_hi=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  event_timestamp_hi.timestamp_hi, CT_OUT(NORM));
    printf(".ignore=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  event_timestamp_hi.ignore, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 event_timestamp_lo NOENCODE
  // {
    //  0_31: timestamp_lo;
    // ENCODE(event_trigger_time_lo,(value=timestamp_lo));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 timestamp_lo : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 timestamp_lo : 32; // 0..31
#endif
    };
    uint32  u32;
  } event_timestamp_lo;
  READ_FROM_BUFFER_FULL(324,uint32 ,event_timestamp_lo,event_timestamp_lo.u32,26);
  {
    event_trigger_time_lo.value = event_timestamp_lo.timestamp_lo;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: event_timestamp_lo ", CT_OUT(BOLD), event_timestamp_lo.u32, CT_OUT(NORM));
    printf(".timestamp_lo=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  event_timestamp_lo.timestamp_lo, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 hp NOENCODE
  // {
    //  0_15: hp;
    // 16_31: ignore;
    // ENCODE(hit_pattern,(value=hp));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 hp : 16; // 0..15
      uint32 ignore : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 ignore : 16; // 16..31
      uint32 hp : 16; // 0..15
#endif
    };
    uint32  u32;
  } hp;
  READ_FROM_BUFFER_FULL(332,uint32 ,hp,hp.u32,27);
  {
    hit_pattern.value = hp.hp;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: hp ", CT_OUT(BOLD), hp.u32, CT_OUT(NORM));
    printf(".hp=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  hp.hp, CT_OUT(NORM));
    printf(".ignore=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  hp.ignore, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 deadbeef NOENCODE
  // {
    //  0_31: 0xdeadbeef;
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
  } deadbeef;
  READ_FROM_BUFFER_FULL(337,uint32 ,deadbeef,deadbeef.u32,28);
  CHECK_BITS_EQUAL(336,deadbeef.unnamed_0_31,0xdeadbeef);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: deadbeef ", CT_OUT(BOLD), deadbeef.u32, CT_OUT(NORM));
    printf("\n");
  }
  // if((sumchannel.trigger_type == 1))

  // else

  if ((sumchannel.trigger_type == 1))
  {
    // list(0<=index<((channel_size.size / 4) - 1))

    for (uint32 index = 0; index < (uint32) (((channel_size.size / 4) - 1)); ++index)
    {
      // UINT32 channelids NOENCODE
      // {
        //  0_15: chan_ts_hi;
        // 16_23: channel_id_bits;
        // 24_31: 240;
        // ENCODE(channel_id[index],(value=channel_id_bits));
        // ENCODE(channel_trigger_time_hi[index],(value=chan_ts_hi));
      // }
      union
      {
        struct
        {
#if __BYTE_ORDER == __LITTLE_ENDIAN
          uint32 chan_ts_hi : 16; // 0..15
          uint32 channel_id_bits : 8; // 16..23
          uint32 unnamed_24_31 : 8; // 24..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
          uint32 unnamed_24_31 : 8; // 24..31
          uint32 channel_id_bits : 8; // 16..23
          uint32 chan_ts_hi : 16; // 0..15
#endif
        };
        uint32  u32;
      } channelids;
      READ_FROM_BUFFER_FULL(351,uint32 ,channelids,channelids.u32,29);
      CHECK_BITS_EQUAL(347,channelids.unnamed_24_31,240);
      {
        {
          typedef __typeof__(*(&(channel_id))) __array_t;
          typedef typename __array_t::item_t __item_t;
          __item_t &__item = channel_id.insert_index(349,index);
          __item.value = channelids.channel_id_bits;
        }
        {
          typedef __typeof__(*(&(channel_trigger_time_hi))) __array_t;
          typedef typename __array_t::item_t __item_t;
          __item_t &__item = channel_trigger_time_hi.insert_index(350,index);
          __item.value = channelids.chan_ts_hi;
        }
      }
      if (__buffer.is_memberdump())
      {
        printf("%s%08" PRIx32 "%s: channelids ", CT_OUT(BOLD), channelids.u32, CT_OUT(NORM));
        printf(".chan_ts_hi=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channelids.chan_ts_hi, CT_OUT(NORM));
        printf(".channel_id_bits=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channelids.channel_id_bits, CT_OUT(NORM));
        printf("\n");
      }
      // UINT32 channel_ts NOENCODE
      // {
        //  0_31: chan_ts_lo;
        // ENCODE(channel_trigger_time_lo[index],(value=chan_ts_lo));
      // }
      union
      {
        struct
        {
#if __BYTE_ORDER == __LITTLE_ENDIAN
          uint32 chan_ts_lo : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
          uint32 chan_ts_lo : 32; // 0..31
#endif
        };
        uint32  u32;
      } channel_ts;
      READ_FROM_BUFFER_FULL(356,uint32 ,channel_ts,channel_ts.u32,30);
      {
        typedef __typeof__(*(&(channel_trigger_time_lo))) __array_t;
        typedef typename __array_t::item_t __item_t;
        __item_t &__item = channel_trigger_time_lo.insert_index(355,index);
        __item.value = channel_ts.chan_ts_lo;
      }
      if (__buffer.is_memberdump())
      {
        printf("%s%08" PRIx32 "%s: channel_ts ", CT_OUT(BOLD), channel_ts.u32, CT_OUT(NORM));
        printf(".chan_ts_lo=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channel_ts.chan_ts_lo, CT_OUT(NORM));
        printf("\n");
      }
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
      union
      {
        struct
        {
#if __BYTE_ORDER == __LITTLE_ENDIAN
          uint32 chan_energy : 24; // 0..23
          uint32 TSF : 6; // 24..29
          uint32 pileup_flag : 1; // 30
          uint32 overflow_flag : 1; // 31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
          uint32 overflow_flag : 1; // 31
          uint32 pileup_flag : 1; // 30
          uint32 TSF : 6; // 24..29
          uint32 chan_energy : 24; // 0..23
#endif
        };
        uint32  u32;
      } chan_enrgy;
      READ_FROM_BUFFER_FULL(368,uint32 ,chan_enrgy,chan_enrgy.u32,31);
      {
        {
          typedef __typeof__(*(&(channel_cfd))) __array_t;
          typedef typename __array_t::item_t __item_t;
          __item_t &__item = channel_cfd.insert_index(364,index);
          __item.value = chan_enrgy.TSF;
        }
        {
          typedef __typeof__(*(&(channel_energy))) __array_t;
          typedef typename __array_t::item_t __item_t;
          __item_t &__item = channel_energy.insert_index(365,index);
          __item.value = chan_enrgy.chan_energy;
        }
        {
          typedef __typeof__(*(&(pileup))) __array_t;
          typedef typename __array_t::item_t __item_t;
          __item_t &__item = pileup.insert_index(366,index);
          __item.value = chan_enrgy.pileup_flag;
        }
        {
          typedef __typeof__(*(&(overflow))) __array_t;
          typedef typename __array_t::item_t __item_t;
          __item_t &__item = overflow.insert_index(367,index);
          __item.value = chan_enrgy.overflow_flag;
        }
      }
      if (__buffer.is_memberdump())
      {
        printf("%s%08" PRIx32 "%s: chan_enrgy ", CT_OUT(BOLD), chan_enrgy.u32, CT_OUT(NORM));
        printf(".chan_energy=%s%6" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  chan_enrgy.chan_energy, CT_OUT(NORM));
        printf(".TSF=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  chan_enrgy.TSF, CT_OUT(NORM));
        printf(".pileup_flag=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  chan_enrgy.pileup_flag, CT_OUT(NORM));
        printf(".overflow_flag=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  chan_enrgy.overflow_flag, CT_OUT(NORM));
        printf("\n");
      }
      // UINT32 future_use NOENCODE
      // {
        //  0_31: 0;
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
      } future_use;
      READ_FROM_BUFFER_FULL(372,uint32 ,future_use,future_use.u32,32);
      CHECK_BITS_EQUAL(371,future_use.unnamed_0_31,0);
      if (__buffer.is_memberdump())
      {
        printf("%s%08" PRIx32 "%s: future_use ", CT_OUT(BOLD), future_use.u32, CT_OUT(NORM));
        printf("\n");
      }
    }
    // list(0<=index<16)

    for (uint32 index = 0; index < (uint32) (16); ++index)
    {
      // select optional

        // trace = TRACE(board=card);
      do
      {
        if (__buffer.empty()) goto no_match_1;
        int __match_no = 0;
        // optimized match 1: TRACE trace: (s32) => (0x00f000ff,0x00000034)
        {
        uint32 __match_peek;
        PEEK_FROM_BUFFER(385,uint32,__match_peek);
        // differ = 00000000 :
        uint32 __match_index = 0;
        static const sint8 __match_index_array[1] = { 1, };
        __match_no = __match_index_array[__match_index];
        // last_subevent_item = 0
        }
        if (!__match_no) goto no_match_1;
        switch (__match_no)
        {
          case 1:
            CHECK_SPURIOUS_MATCH_DECL(384,spurious_match_abort_loop_0,TRACE,/*board*/card);
            UNPACK_DECL(384,TRACE,trace,/*board*/card);
            break;
        }
      }
      while (0);
      spurious_match_abort_loop_0:;
        no_match_1:;
    }
  }

  else
  {
    // if((sumchannel.trigger_type == 3))

    if ((sumchannel.trigger_type == 3))
    {
      // several UINT32 dummy NOENCODE;
      for ( ; ; ) {
      uint32  dummy;if (__buffer.empty()) goto data_done_0;
      READ_FROM_BUFFER(396,uint32 ,dummy,33);
      }
      data_done_0:;
    }
  }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,FEBEX_EVENT_TRACES::__unpack,uint32 card);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for FEBEX_PADDING.
 *
 * Do not edit - automatically generated.
 */

// FEBEX_PADDING()
template<typename __data_src_t>
void FEBEX_PADDING::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "FEBEX_PADDING",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(111,uint32 ,pads_data,pads_data.u32,35);
  CHECK_BITS_EQUAL(110,pads_data.unnamed_20_31,0xadd);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: pads_data ", CT_OUT(BOLD), pads_data.u32, CT_OUT(NORM));
    printf(".counter=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  pads_data.counter, CT_OUT(NORM));
    printf(".index=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  pads_data.index, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,FEBEX_PADDING::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for MVLC_SCALER.
 *
 * Do not edit - automatically generated.
 */

// MVLC_SCALER(geo)
template<typename __data_src_t>
void MVLC_SCALER::__unpack(__data_src_t &__buffer,uint32 geo)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "MVLC_SCALER",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(981,uint32 ,header,header.u32,37);
  CHECK_BITS_EQUAL(977,header.unnamed_16_16,0);
  CHECK_BITS_EQUAL(980,header.geom,geo);
  CHECK_UNNAMED_BITS_ZERO(981,header.u32,0x00020000);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: header ", CT_OUT(BOLD), header.u32, CT_OUT(NORM));
    printf(".whatever=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.whatever, CT_OUT(NORM));
    printf(".nlw=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.nlw, CT_OUT(NORM));
    printf(".type=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.type, CT_OUT(NORM));
    printf(".geom=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.geom, CT_OUT(NORM));
    printf("\n");
  }
  // list(0<=i<header.nlw)

  for (uint32 i = 0; i < (uint32) (header.nlw); ++i)
  {
    // UINT32 scaler NOENCODE
    // {
      //  0_31: value;
      // ENCODE(scalers[i],(value=value));
    // }
    union
    {
      struct
      {
#if __BYTE_ORDER == __LITTLE_ENDIAN
        uint32 value : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
        uint32 value : 32; // 0..31
#endif
      };
      uint32  u32;
    } scaler;
    READ_FROM_BUFFER_FULL(989,uint32 ,scaler,scaler.u32,38);
    {
      typedef __typeof__(*(&(scalers))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = scalers.insert_index(988,i);
      __item.value = scaler.value;
    }
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: scaler ", CT_OUT(BOLD), scaler.u32, CT_OUT(NORM));
      printf(".value=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  scaler.value, CT_OUT(NORM));
      printf("\n");
    }
  }
  // UINT32 trailer NOENCODE;
  uint32  trailer;READ_FROM_BUFFER(992,uint32 ,trailer,39);
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,MVLC_SCALER::__unpack,uint32 geo);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for VME_CAEN_V7X5.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V7X5(geom)
template<typename __data_src_t>
void VME_CAEN_V7X5::__unpack(__data_src_t &__buffer,uint32 geom)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "VME_CAEN_V7X5",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(823,uint32 ,header,header.u32,41);
  CHECK_BITS_EQUAL(821,header.unnamed_24_26,2);
  CHECK_BITS_EQUAL(822,header.geom,geom);
  CHECK_UNNAMED_BITS_ZERO(823,header.u32,0x0000c000);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: header ", CT_OUT(BOLD), header.u32, CT_OUT(NORM));
    printf(".undefined=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.undefined, CT_OUT(NORM));
    printf(".count=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.count, CT_OUT(NORM));
    printf(".crate=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.crate, CT_OUT(NORM));
    printf(".geom=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.geom, CT_OUT(NORM));
    printf("\n");
  }
  // list(0<=index<header.count)

  for (uint32 index = 0; index < (uint32) (header.count); ++index)
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
    union
    {
      struct
      {
#if __BYTE_ORDER == __LITTLE_ENDIAN
        uint32 value : 12; // 0..11
        uint32 overflow : 1; // 12
        uint32 underflow : 1; // 13
        uint32 valid : 1; // 14
        uint32 undefined : 1; // 15
        uint32 channel : 5; // 16..20
        uint32 undefined2 : 3; // 21..23
        uint32 unnamed_24_26 : 3; // 24..26
        uint32 geom : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
        uint32 geom : 5; // 27..31
        uint32 unnamed_24_26 : 3; // 24..26
        uint32 undefined2 : 3; // 21..23
        uint32 channel : 5; // 16..20
        uint32 undefined : 1; // 15
        uint32 valid : 1; // 14
        uint32 underflow : 1; // 13
        uint32 overflow : 1; // 12
        uint32 value : 12; // 0..11
#endif
      };
      uint32  u32;
    } ch_data;
    READ_FROM_BUFFER_FULL(841,uint32 ,ch_data,ch_data.u32,42);
    CHECK_BITS_EQUAL(836,ch_data.unnamed_24_26,0);
    {
      typedef __typeof__(*(&(data))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = data.insert_index(840,ch_data.channel);
      __item.value = ch_data.value;
    }
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: ch_data ", CT_OUT(BOLD), ch_data.u32, CT_OUT(NORM));
      printf(".value=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ch_data.value, CT_OUT(NORM));
      printf(".overflow=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ch_data.overflow, CT_OUT(NORM));
      printf(".underflow=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ch_data.underflow, CT_OUT(NORM));
      printf(".valid=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ch_data.valid, CT_OUT(NORM));
      printf(".undefined=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ch_data.undefined, CT_OUT(NORM));
      printf(".channel=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ch_data.channel, CT_OUT(NORM));
      printf(".undefined2=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ch_data.undefined2, CT_OUT(NORM));
      printf(".geom=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ch_data.geom, CT_OUT(NORM));
      printf("\n");
    }
  }
  // UINT32 eob NOENCODE
  // {
    //  0_23: nothing;
    // 24_26: 4;
    // 27_31: id = MATCH(geom);
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 nothing : 24; // 0..23
      uint32 unnamed_24_26 : 3; // 24..26
      uint32 id : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 id : 5; // 27..31
      uint32 unnamed_24_26 : 3; // 24..26
      uint32 nothing : 24; // 0..23
#endif
    };
    uint32  u32;
  } eob;
  READ_FROM_BUFFER_FULL(849,uint32 ,eob,eob.u32,43);
  CHECK_BITS_EQUAL(847,eob.unnamed_24_26,4);
  CHECK_BITS_EQUAL(848,eob.id,geom);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: eob ", CT_OUT(BOLD), eob.u32, CT_OUT(NORM));
    printf(".nothing=%s%6" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  eob.nothing, CT_OUT(NORM));
    printf(".id=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  eob.id, CT_OUT(NORM));
    printf("\n");
  }
  // list(0<=i<2)

  for (uint32 i = 0; i < (uint32) (2); ++i)
  {
    // optional UINT32 eob2 NOENCODE
    // {
      //  0_23: nothing;
      // 24_26: id = MATCH(6);
      // 27_31: geom;
    // }
    union
    {
      struct
      {
#if __BYTE_ORDER == __LITTLE_ENDIAN
        uint32 nothing : 24; // 0..23
        uint32 id : 3; // 24..26
        uint32 geom : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
        uint32 geom : 5; // 27..31
        uint32 id : 3; // 24..26
        uint32 nothing : 24; // 0..23
#endif
      };
      uint32  u32;
    } eob2;
    if (__buffer.empty()) goto data_done_1;
    PEEK_FROM_BUFFER_FULL(858,uint32 ,eob2,eob2.u32,44);
    CHECK_JUMP_BITS_EQUAL(856,eob2.id,6,data_done_1);
    __buffer.advance(sizeof(eob2.u32));
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: eob2 ", CT_OUT(BOLD), eob2.u32, CT_OUT(NORM));
      printf(".nothing=%s%6" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  eob2.nothing, CT_OUT(NORM));
      printf(".id=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  eob2.id, CT_OUT(NORM));
      printf(".geom=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  eob2.geom, CT_OUT(NORM));
      printf("\n");
    }
    data_done_1:;
  }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,VME_CAEN_V7X5::__unpack,uint32 geom);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TDC_HEADER.
 *
 * Do not edit - automatically generated.
 */

// TDC_HEADER()
template<typename __data_src_t>
void TDC_HEADER::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TDC_HEADER",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(617,uint32 ,tdc_header,tdc_header.u32,46);
  CHECK_BITS_EQUAL(616,tdc_header.unnamed_27_31,1);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: tdc_header ", CT_OUT(BOLD), tdc_header.u32, CT_OUT(NORM));
    printf(".bunch_id=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_header.bunch_id, CT_OUT(NORM));
    printf(".event_id=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_header.event_id, CT_OUT(NORM));
    printf(".tdc=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_header.tdc, CT_OUT(NORM));
    printf(".unused=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_header.unused, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,TDC_HEADER::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TDC_DATA_V1290.
 *
 * Do not edit - automatically generated.
 */

// TDC_DATA_V1290()
template<typename __data_src_t>
void TDC_DATA_V1290::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TDC_DATA_V1290",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(634,uint32 ,tdc_data,tdc_data.u32,48);
  CHECK_BITS_EQUAL(630,tdc_data.unnamed_27_31,0);
  {
    {
      typedef __typeof__(*(&(data))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = data.insert_index(632,tdc_data.chn);
      __item.value = tdc_data.tdc;
    }
    {
      typedef __typeof__(*(&(leadOrTrail))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = leadOrTrail.insert_index(633,tdc_data.chn);
      __item.value = tdc_data.lot;
    }
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: tdc_data ", CT_OUT(BOLD), tdc_data.u32, CT_OUT(NORM));
    printf(".tdc=%s%6" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_data.tdc, CT_OUT(NORM));
    printf(".chn=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_data.chn, CT_OUT(NORM));
    printf(".lot=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_data.lot, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,TDC_DATA_V1290::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TDC_ERROR.
 *
 * Do not edit - automatically generated.
 */

// TDC_ERROR()
template<typename __data_src_t>
void TDC_ERROR::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TDC_ERROR",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(663,uint32 ,tdc_err,tdc_err.u32,50);
  CHECK_BITS_EQUAL(662,tdc_err.unnamed_27_31,4);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: tdc_err ", CT_OUT(BOLD), tdc_err.u32, CT_OUT(NORM));
    printf(".error_flags=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_err.error_flags, CT_OUT(NORM));
    printf(".unused1=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_err.unused1, CT_OUT(NORM));
    printf(".tdc=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_err.tdc, CT_OUT(NORM));
    printf(".unused2=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_err.unused2, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,TDC_ERROR::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TDC_TRAILER.
 *
 * Do not edit - automatically generated.
 */

// TDC_TRAILER()
template<typename __data_src_t>
void TDC_TRAILER::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TDC_TRAILER",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(675,uint32 ,tdc_trailer,tdc_trailer.u32,52);
  CHECK_BITS_EQUAL(674,tdc_trailer.unnamed_27_31,3);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: tdc_trailer ", CT_OUT(BOLD), tdc_trailer.u32, CT_OUT(NORM));
    printf(".word_count=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_trailer.word_count, CT_OUT(NORM));
    printf(".event_id=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_trailer.event_id, CT_OUT(NORM));
    printf(".tdc=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_trailer.tdc, CT_OUT(NORM));
    printf(".unused=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_trailer.unused, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,TDC_TRAILER::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for VME_CAEN_V1290_N.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V1290_N()
template<typename __data_src_t>
void VME_CAEN_V1290_N::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "VME_CAEN_V1290_N",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(689,uint32 ,header,header.u32,54);
  CHECK_BITS_EQUAL(686,header.type,8);
  {
    geo.value = header.geom;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: header ", CT_OUT(BOLD), header.u32, CT_OUT(NORM));
    printf(".geom=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.geom, CT_OUT(NORM));
    printf(".event_count=%s%6" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.event_count, CT_OUT(NORM));
    printf(".type=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.type, CT_OUT(NORM));
    printf("\n");
  }
  // select several

    // tdc_header = TDC_HEADER();
    // measurement = TDC_DATA_V1290();
    // tdc_err = TDC_ERROR();
    // tdc_trailer = TDC_TRAILER();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: TDC_HEADER tdc_header: (s32) => (0xf8000000,0x08000000)
    // optimized match 2: TDC_DATA_V1290 measurement: (s32) => (0xf8000000,0x00000000)
    // optimized match 3: TDC_ERROR tdc_err: (s32) => (0xf8000000,0x20000000)
    // optimized match 4: TDC_TRAILER tdc_trailer: (s32) => (0xf8000000,0x18000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(697,uint32,__match_peek);
    // differ = 38000000 : 27 28 29
    uint32 __match_index = 0 | /* 27,29 */ ((__match_peek >> 27) & 0x00000007);
    static const sint8 __match_index_array[8] = { 2, 1, 0, 4, 3, 0, 0, 0, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(693,spurious_match_abort_loop_1,TDC_HEADER);
        UNPACK_DECL(693,TDC_HEADER,tdc_header);
        break;
      case 2:
        CHECK_SPURIOUS_MATCH_DECL(694,spurious_match_abort_loop_1,TDC_DATA_V1290);
        UNPACK_DECL(694,TDC_DATA_V1290,measurement);
        break;
      case 3:
        CHECK_SPURIOUS_MATCH_DECL(695,spurious_match_abort_loop_1,TDC_ERROR);
        UNPACK_DECL(695,TDC_ERROR,tdc_err);
        break;
      case 4:
        CHECK_SPURIOUS_MATCH_DECL(696,spurious_match_abort_loop_1,TDC_TRAILER);
        UNPACK_DECL(696,TDC_TRAILER,tdc_trailer);
        break;
    }
  }
  spurious_match_abort_loop_1:;
  // optional UINT32 ext_time_tag NOENCODE
  // {
    //  0_26: time_tag;
    // 27_31: 17;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 time_tag : 27; // 0..26
      uint32 unnamed_27_31 : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_27_31 : 5; // 27..31
      uint32 time_tag : 27; // 0..26
#endif
    };
    uint32  u32;
  } ext_time_tag;
  if (__buffer.empty()) goto data_done_2;
  PEEK_FROM_BUFFER_FULL(704,uint32 ,ext_time_tag,ext_time_tag.u32,55);
  CHECK_JUMP_BITS_EQUAL(703,ext_time_tag.unnamed_27_31,17,data_done_2);
  __buffer.advance(sizeof(ext_time_tag.u32));
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: ext_time_tag ", CT_OUT(BOLD), ext_time_tag.u32, CT_OUT(NORM));
    printf(".time_tag=%s%7" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ext_time_tag.time_tag, CT_OUT(NORM));
    printf("\n");
  }
  data_done_2:;
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
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 geom : 5; // 0..4
      uint32 word_count : 16; // 5..20
      uint32 unused : 3; // 21..23
      uint32 tdc_error : 1; // 24
      uint32 overflow : 1; // 25
      uint32 trigger_lost : 1; // 26
      uint32 unnamed_27_31 : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_27_31 : 5; // 27..31
      uint32 trigger_lost : 1; // 26
      uint32 overflow : 1; // 25
      uint32 tdc_error : 1; // 24
      uint32 unused : 3; // 21..23
      uint32 word_count : 16; // 5..20
      uint32 geom : 5; // 0..4
#endif
    };
    uint32  u32;
  } trailer;
  READ_FROM_BUFFER_FULL(715,uint32 ,trailer,trailer.u32,56);
  CHECK_BITS_EQUAL(714,trailer.unnamed_27_31,16);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: trailer ", CT_OUT(BOLD), trailer.u32, CT_OUT(NORM));
    printf(".geom=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.geom, CT_OUT(NORM));
    printf(".word_count=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.word_count, CT_OUT(NORM));
    printf(".unused=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.unused, CT_OUT(NORM));
    printf(".tdc_error=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.tdc_error, CT_OUT(NORM));
    printf(".overflow=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.overflow, CT_OUT(NORM));
    printf(".trigger_lost=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.trigger_lost, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,VME_CAEN_V1290_N::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for MAIN_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// MAIN_CRATE_DATA()
template<typename __data_src_t>
void MAIN_CRATE_DATA::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "MAIN_CRATE_DATA",CT_OUT(NORM));
  }
  // barrier0 = BARRIER();
  UNPACK_DECL(1000,BARRIER,barrier0);
  // v830 = MVLC_SCALER(geo=8);
  UNPACK_DECL(1002,MVLC_SCALER,v830,/*geo*/8);
  // barrier1 = BARRIER();
  UNPACK_DECL(1006,BARRIER,barrier1);
  // v792 = VME_CAEN_V7X5(geom=14);
  UNPACK_DECL(1007,VME_CAEN_V7X5,v792,/*geom*/14);
  // UINT32 aaahhh NOENCODE
  // {
    //  0_31: 0xaaaa1290;
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
  } aaahhh;
  READ_FROM_BUFFER_FULL(1009,uint32 ,aaahhh,aaahhh.u32,58);
  CHECK_BITS_EQUAL(1009,aaahhh.unnamed_0_31,0xaaaa1290);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: aaahhh ", CT_OUT(BOLD), aaahhh.u32, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 exxxxx NOENCODE;
  uint32  exxxxx;READ_FROM_BUFFER(1010,uint32 ,exxxxx,59);
  // barrier2 = BARRIER();
  UNPACK_DECL(1012,BARRIER,barrier2);
  // v1290 = VME_CAEN_V1290_N();
  UNPACK_DECL(1013,VME_CAEN_V1290_N,v1290);
  // optional UINT32 eodb NOENCODE;
  uint32  eodb;if (__buffer.empty()) goto data_done_3;
  READ_FROM_BUFFER(1014,uint32 ,eodb,60);
  data_done_3:;
}
FORCE_IMPL_DATA_SRC_FCN(void,MAIN_CRATE_DATA::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for SPILL_OFF.
 *
 * Do not edit - automatically generated.
 */

// SPILL_OFF()
template<typename __data_src_t>
void SPILL_OFF::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "SPILL_OFF",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(888,uint32 ,off1,off1.u32,61);
  CHECK_BITS_EQUAL(887,off1.unnamed_0_31,0x4040400a);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: off1 ", CT_OUT(BOLD), off1.u32, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 off2 NOENCODE
  // {
    //  0_31: 0x4040400b;
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
  } off2;
  READ_FROM_BUFFER_FULL(892,uint32 ,off2,off2.u32,62);
  CHECK_BITS_EQUAL(891,off2.unnamed_0_31,0x4040400b);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: off2 ", CT_OUT(BOLD), off2.u32, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 off3 NOENCODE
  // {
    //  0_31: 0x4040400c;
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
  } off3;
  READ_FROM_BUFFER_FULL(896,uint32 ,off3,off3.u32,63);
  CHECK_BITS_EQUAL(895,off3.unnamed_0_31,0x4040400c);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: off3 ", CT_OUT(BOLD), off3.u32, CT_OUT(NORM));
    printf("\n");
  }
  // ENCODE(spilloff,(value=1));

  {
    spilloff.value = 1;
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,SPILL_OFF::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for SPILL_ON.
 *
 * Do not edit - automatically generated.
 */

// SPILL_ON()
template<typename __data_src_t>
void SPILL_ON::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "SPILL_ON",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(877,uint32 ,on,on.u32,65);
  CHECK_BITS_EQUAL(876,on.unnamed_0_31,0x30303030);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: on ", CT_OUT(BOLD), on.u32, CT_OUT(NORM));
    printf("\n");
  }
  // ENCODE(spillon,(value=1));

  {
    spillon.value = 1;
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,SPILL_ON::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TAMEX4_EPOCH_DATA.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_EPOCH_DATA(sfp,card,time_coarse,time_fine,time_edge,time_channel,
                  // time_epoch)
template<typename __data_src_t>
void TAMEX4_EPOCH_DATA::__unpack(__data_src_t &__buffer,uint32 sfp,uint32 card
                                                       ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_coarse
                                                       ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_fine
                                                       ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_edge
                                                       ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_channel
                                                       ,raw_list_ii_zero_suppress<DATA32,DATA32,1024> &time_epoch)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TAMEX4_EPOCH_DATA",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(473,uint32 ,data,data.u32,67);
  CHECK_BITS_EQUAL(466,data.unnamed_28_31,6);
  {
    {
      typedef __typeof__(*(&(time_coarse))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_coarse.append_item(468);
      __item.value = 0;
    }
    {
      typedef __typeof__(*(&(time_fine))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_fine.append_item(469);
      __item.value = 0;
    }
    {
      typedef __typeof__(*(&(time_edge))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_edge.append_item(470);
      __item.value = 0;
    }
    {
      typedef __typeof__(*(&(time_channel))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_channel.append_item(471);
      __item.value = 0;
    }
    {
      typedef __typeof__(*(&(time_epoch))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_epoch.append_item(472);
      __item.value = data.epoch;
    }
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: data ", CT_OUT(BOLD), data.u32, CT_OUT(NORM));
    printf(".epoch=%s%7" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  data.epoch, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,TAMEX4_EPOCH_DATA::__unpack,uint32 sfp,uint32 card
                                                            ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_coarse
                                                            ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_fine
                                                            ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_edge
                                                            ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_channel
                                                            ,raw_list_ii_zero_suppress<DATA32,DATA32,1024> &time_epoch);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TAMEX4_HEADER.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_HEADER()
template<typename __data_src_t>
void TAMEX4_HEADER::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TAMEX4_HEADER",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(415,uint32 ,trigger_window,trigger_window.u32,69);
  {
    {
      post_trig_ns.value = trigger_window.post_trig_ns;
    }
    {
      pre_trig_ns.value = trigger_window.pre_trig_ns;
    }
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: trigger_window ", CT_OUT(BOLD), trigger_window.u32, CT_OUT(NORM));
    printf(".post_trig_ns=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trigger_window.post_trig_ns, CT_OUT(NORM));
    printf(".pre_trig_ns=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trigger_window.pre_trig_ns, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,TAMEX4_HEADER::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TAMEX4_PADDING.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_PADDING()
template<typename __data_src_t>
void TAMEX4_PADDING::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TAMEX4_PADDING",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(426,uint32 ,padding,padding.u32,71);
  CHECK_BITS_EQUAL(425,padding.unnamed_20_31,0xadd);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: padding ", CT_OUT(BOLD), padding.u32, CT_OUT(NORM));
    printf(".counter=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  padding.counter, CT_OUT(NORM));
    printf(".index=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  padding.index, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,TAMEX4_PADDING::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TAMEX4_TIME_DATA.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_TIME_DATA(sfp,card,time_coarse,time_fine,time_edge,time_channel,
                 // time_epoch)
template<typename __data_src_t>
void TAMEX4_TIME_DATA::__unpack(__data_src_t &__buffer,uint32 sfp,uint32 card
                                                      ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_coarse
                                                      ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_fine
                                                      ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_edge
                                                      ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_channel
                                                      ,raw_list_ii_zero_suppress<DATA32,DATA32,1024> &time_epoch)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TAMEX4_TIME_DATA",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(451,uint32 ,data,data.u32,73);
  CHECK_BITS_EQUAL(444,data.type,8);
  {
    {
      typedef __typeof__(*(&(time_coarse))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_coarse.append_item(446);
      __item.value = data.coarse;
    }
    {
      typedef __typeof__(*(&(time_fine))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_fine.append_item(447);
      __item.value = data.fine;
    }
    {
      typedef __typeof__(*(&(time_edge))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_edge.append_item(448);
      __item.value = data.is_leading;
    }
    {
      typedef __typeof__(*(&(time_channel))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_channel.append_item(449);
      __item.value = data.channel;
    }
    {
      typedef __typeof__(*(&(time_epoch))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_epoch.append_item(450);
      __item.value = 0;
    }
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: data ", CT_OUT(BOLD), data.u32, CT_OUT(NORM));
    printf(".coarse=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  data.coarse, CT_OUT(NORM));
    printf(".is_leading=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  data.is_leading, CT_OUT(NORM));
    printf(".fine=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  data.fine, CT_OUT(NORM));
    printf(".channel=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  data.channel, CT_OUT(NORM));
    printf(".type=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  data.type, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,TAMEX4_TIME_DATA::__unpack,uint32 sfp,uint32 card
                                                           ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_coarse
                                                           ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_fine
                                                           ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_edge
                                                           ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_channel
                                                           ,raw_list_ii_zero_suppress<DATA32,DATA32,1024> &time_epoch);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TAMEX4_SFP.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_SFP(sfp,card)
template<typename __data_src_t>
void TAMEX4_SFP::__unpack(__data_src_t &__buffer,uint32 sfp,uint32 card)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TAMEX4_SFP",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(495,uint32 ,indicator,indicator.u32,75);
  CHECK_BITS_EQUAL(489,indicator.unnamed_0_7,52);
  CHECK_BITS_EQUAL(491,indicator.sfp,sfp);
  CHECK_BITS_EQUAL(492,indicator.card,card);
  CHECK_BITS_EQUAL(493,indicator.unnamed_24_31,0);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: indicator ", CT_OUT(BOLD), indicator.u32, CT_OUT(NORM));
    printf(".trigger_type=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  indicator.trigger_type, CT_OUT(NORM));
    printf(".sfp=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  indicator.sfp, CT_OUT(NORM));
    printf(".card=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  indicator.card, CT_OUT(NORM));
    printf("\n");
  }
  // MATCH_END;
  // UINT32 data_size NOENCODE
  // {
    //  0_31: bytes;
    // ENCODE(event_size,(value=bytes));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 bytes : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 bytes : 32; // 0..31
#endif
    };
    uint32  u32;
  } data_size;
  READ_FROM_BUFFER_FULL(505,uint32 ,data_size,data_size.u32,76);
  {
    event_size.value = data_size.bytes;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: data_size ", CT_OUT(BOLD), data_size.u32, CT_OUT(NORM));
    printf(".bytes=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  data_size.bytes, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 tdc_header NOENCODE
  // {
    //  0_15: lec;
    //    16: buf_no;
    // 17_19: reserved;
    // 20_23: trigger_type;
    // 24_31: 170;
    // ENCODE(trig,(value=trigger_type));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 lec : 16; // 0..15
      uint32 buf_no : 1; // 16
      uint32 reserved : 3; // 17..19
      uint32 trigger_type : 4; // 20..23
      uint32 unnamed_24_31 : 8; // 24..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_24_31 : 8; // 24..31
      uint32 trigger_type : 4; // 20..23
      uint32 reserved : 3; // 17..19
      uint32 buf_no : 1; // 16
      uint32 lec : 16; // 0..15
#endif
    };
    uint32  u32;
  } tdc_header;
  READ_FROM_BUFFER_FULL(514,uint32 ,tdc_header,tdc_header.u32,77);
  CHECK_BITS_EQUAL(512,tdc_header.unnamed_24_31,170);
  {
    trig.value = tdc_header.trigger_type;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: tdc_header ", CT_OUT(BOLD), tdc_header.u32, CT_OUT(NORM));
    printf(".lec=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_header.lec, CT_OUT(NORM));
    printf(".buf_no=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_header.buf_no, CT_OUT(NORM));
    printf(".reserved=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_header.reserved, CT_OUT(NORM));
    printf(".trigger_type=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_header.trigger_type, CT_OUT(NORM));
    printf("\n");
  }
  // list(0<=i<((data_size.bytes / 4) - 3))

  for (uint32 i = 0; i < (uint32) (((data_size.bytes / 4) - 3)); ++i)
  {
    // select

      // epoch = TAMEX4_EPOCH_DATA(sfp=sfp,card=card,time_coarse=time_coarse,
                                // time_fine=time_fine,time_edge=time_edge,
                                // time_channel=time_channel,time_epoch=time_epoch);
      // time = TAMEX4_TIME_DATA(sfp=sfp,card=card,time_coarse=time_coarse,
                              // time_fine=time_fine,time_edge=time_edge,
                              // time_channel=time_channel,time_epoch=time_epoch);
    do
    {
      int __match_no = 0;
      // optimized match 1: TAMEX4_EPOCH_DATA epoch: (s32) => (0xf0000000,0x60000000)
      // optimized match 2: TAMEX4_TIME_DATA time: (s32) => (0xf0000000,0x80000000)
      {
      uint32 __match_peek;
      PEEK_FROM_BUFFER(522,uint32,__match_peek);
      // differ = e0000000 : 29 30 31
      uint32 __match_index = 0 | /* 29,31 */ ((__match_peek >> 29) & 0x00000007);
      static const sint8 __match_index_array[8] = { 0, 0, 0, 1, 2, 0, 0, 0, };
      __match_no = __match_index_array[__match_index];
      // last_subevent_item = 0
      }
      if (!__match_no) ERROR_U_LOC(522,"No match for select statement.");
      switch (__match_no)
      {
        case 1:
          CHECK_SPURIOUS_MATCH_DECL(520,spurious_match_abort_loop_2,TAMEX4_EPOCH_DATA,/*sfp*/sfp,/*card*/card/*,time_coarse:member*//*,time_fine:member*//*,time_edge:member*//*,time_channel:member*//*,time_epoch:member*/);
          UNPACK_DECL(520,TAMEX4_EPOCH_DATA,epoch,/*sfp*/sfp,/*card*/card,/*time_coarse*/time_coarse,/*time_fine*/time_fine,/*time_edge*/time_edge,/*time_channel*/time_channel,/*time_epoch*/time_epoch);
          break;
        case 2:
          CHECK_SPURIOUS_MATCH_DECL(521,spurious_match_abort_loop_2,TAMEX4_TIME_DATA,/*sfp*/sfp,/*card*/card/*,time_coarse:member*//*,time_fine:member*//*,time_edge:member*//*,time_channel:member*//*,time_epoch:member*/);
          UNPACK_DECL(521,TAMEX4_TIME_DATA,time,/*sfp*/sfp,/*card*/card,/*time_coarse*/time_coarse,/*time_fine*/time_fine,/*time_edge*/time_edge,/*time_channel*/time_channel,/*time_epoch*/time_epoch);
          break;
      }
    }
    while (0);
    spurious_match_abort_loop_2:;
  }
  // UINT32 error_bits NOENCODE
  // {
    //  0_23: bits;
    // 24_31: 238;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 bits : 24; // 0..23
      uint32 unnamed_24_31 : 8; // 24..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_24_31 : 8; // 24..31
      uint32 bits : 24; // 0..23
#endif
    };
    uint32  u32;
  } error_bits;
  READ_FROM_BUFFER_FULL(529,uint32 ,error_bits,error_bits.u32,78);
  CHECK_BITS_EQUAL(528,error_bits.unnamed_24_31,238);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: error_bits ", CT_OUT(BOLD), error_bits.u32, CT_OUT(NORM));
    printf(".bits=%s%6" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  error_bits.bits, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 trailer NOENCODE
  // {
    //  0_15: lec;
    //    16: buf_no;
    // 17_19: reserved;
    // 20_23: trigger_type;
    // 24_31: 187;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 lec : 16; // 0..15
      uint32 buf_no : 1; // 16
      uint32 reserved : 3; // 17..19
      uint32 trigger_type : 4; // 20..23
      uint32 unnamed_24_31 : 8; // 24..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_24_31 : 8; // 24..31
      uint32 trigger_type : 4; // 20..23
      uint32 reserved : 3; // 17..19
      uint32 buf_no : 1; // 16
      uint32 lec : 16; // 0..15
#endif
    };
    uint32  u32;
  } trailer;
  READ_FROM_BUFFER_FULL(538,uint32 ,trailer,trailer.u32,79);
  CHECK_BITS_EQUAL(537,trailer.unnamed_24_31,187);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: trailer ", CT_OUT(BOLD), trailer.u32, CT_OUT(NORM));
    printf(".lec=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.lec, CT_OUT(NORM));
    printf(".buf_no=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.buf_no, CT_OUT(NORM));
    printf(".reserved=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.reserved, CT_OUT(NORM));
    printf(".trigger_type=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.trigger_type, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,TAMEX4_SFP::__unpack,uint32 sfp,uint32 card);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TDC_DATA_V1190.
 *
 * Do not edit - automatically generated.
 */

// TDC_DATA_V1190()
template<typename __data_src_t>
void TDC_DATA_V1190::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TDC_DATA_V1190",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(651,uint32 ,tdc_data,tdc_data.u32,81);
  CHECK_BITS_EQUAL(647,tdc_data.unnamed_27_31,0);
  {
    {
      typedef __typeof__(*(&(data))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = data.insert_index(649,tdc_data.chn);
      __item.value = tdc_data.tdc;
    }
    {
      typedef __typeof__(*(&(leadOrTrail))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = leadOrTrail.insert_index(650,tdc_data.chn);
      __item.value = tdc_data.lot;
    }
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: tdc_data ", CT_OUT(BOLD), tdc_data.u32, CT_OUT(NORM));
    printf(".tdc=%s%5" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_data.tdc, CT_OUT(NORM));
    printf(".chn=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_data.chn, CT_OUT(NORM));
    printf(".lot=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  tdc_data.lot, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,TDC_DATA_V1190::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TIMESTAMP_WHITERABBIT.
 *
 * Do not edit - automatically generated.
 */

// TIMESTAMP_WHITERABBIT(id)
template<typename __data_src_t>
void TIMESTAMP_WHITERABBIT::__unpack(__data_src_t &__buffer,uint32 id)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TIMESTAMP_WHITERABBIT",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(24,uint32 ,header,header.u32,83);
  CHECK_BITS_EQUAL(19,header.id,id);
  CHECK_BITS_EQUAL(20,header.unnamed_12_15,0);
  CHECK_BITS_EQUAL(22,header.unnamed_17_31,0);
  {
    subsystem_id.value = header.id;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: header ", CT_OUT(BOLD), header.u32, CT_OUT(NORM));
    printf(".id=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.id, CT_OUT(NORM));
    printf(".error_bit=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.error_bit, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 d1 NOENCODE
  // {
    //  0_15: t1;
    // 16_31: 0x3e1;
    // ENCODE(t1,(value=t1));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 t1 : 16; // 0..15
      uint32 unnamed_16_31 : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_16_31 : 16; // 16..31
      uint32 t1 : 16; // 0..15
#endif
    };
    uint32  u32;
  } d1;
  READ_FROM_BUFFER_FULL(29,uint32 ,d1,d1.u32,84);
  CHECK_BITS_EQUAL(27,d1.unnamed_16_31,0x3e1);
  {
    t1.value = d1.t1;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: d1 ", CT_OUT(BOLD), d1.u32, CT_OUT(NORM));
    printf(".t1=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  d1.t1, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 d2 NOENCODE
  // {
    //  0_15: t2;
    // 16_31: 0x4e1;
    // ENCODE(t2,(value=t2));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 t2 : 16; // 0..15
      uint32 unnamed_16_31 : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_16_31 : 16; // 16..31
      uint32 t2 : 16; // 0..15
#endif
    };
    uint32  u32;
  } d2;
  READ_FROM_BUFFER_FULL(34,uint32 ,d2,d2.u32,85);
  CHECK_BITS_EQUAL(32,d2.unnamed_16_31,0x4e1);
  {
    t2.value = d2.t2;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: d2 ", CT_OUT(BOLD), d2.u32, CT_OUT(NORM));
    printf(".t2=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  d2.t2, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 d3 NOENCODE
  // {
    //  0_15: t3;
    // 16_31: 0x5e1;
    // ENCODE(t3,(value=t3));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 t3 : 16; // 0..15
      uint32 unnamed_16_31 : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_16_31 : 16; // 16..31
      uint32 t3 : 16; // 0..15
#endif
    };
    uint32  u32;
  } d3;
  READ_FROM_BUFFER_FULL(39,uint32 ,d3,d3.u32,86);
  CHECK_BITS_EQUAL(37,d3.unnamed_16_31,0x5e1);
  {
    t3.value = d3.t3;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: d3 ", CT_OUT(BOLD), d3.u32, CT_OUT(NORM));
    printf(".t3=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  d3.t3, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 d4 NOENCODE
  // {
    //  0_15: t4;
    // 16_31: 0x6e1;
    // ENCODE(t4,(value=t4));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 t4 : 16; // 0..15
      uint32 unnamed_16_31 : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_16_31 : 16; // 16..31
      uint32 t4 : 16; // 0..15
#endif
    };
    uint32  u32;
  } d4;
  READ_FROM_BUFFER_FULL(44,uint32 ,d4,d4.u32,87);
  CHECK_BITS_EQUAL(42,d4.unnamed_16_31,0x6e1);
  {
    t4.value = d4.t4;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: d4 ", CT_OUT(BOLD), d4.u32, CT_OUT(NORM));
    printf(".t4=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  d4.t4, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,TIMESTAMP_WHITERABBIT::__unpack,uint32 id);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TIMESTAMP_WHITERABBIT_EXTENDED.
 *
 * Do not edit - automatically generated.
 */

// TIMESTAMP_WHITERABBIT_EXTENDED(id)
template<typename __data_src_t>
void TIMESTAMP_WHITERABBIT_EXTENDED::__unpack(__data_src_t &__buffer,uint32 id)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TIMESTAMP_WHITERABBIT_EXTENDED",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(61,uint32 ,header,header.u32,89);
  CHECK_BITS_EQUAL(56,header.id,id);
  CHECK_BITS_EQUAL(57,header.unnamed_13_15,0);
  CHECK_BITS_EQUAL(59,header.unnamed_17_31,0);
  {
    subsystem_id.value = header.id;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: header ", CT_OUT(BOLD), header.u32, CT_OUT(NORM));
    printf(".id=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.id, CT_OUT(NORM));
    printf(".error_bit=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.error_bit, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 d1 NOENCODE
  // {
    //  0_15: t1;
    // 16_31: 0x3e1;
    // ENCODE(t1,(value=t1));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 t1 : 16; // 0..15
      uint32 unnamed_16_31 : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_16_31 : 16; // 16..31
      uint32 t1 : 16; // 0..15
#endif
    };
    uint32  u32;
  } d1;
  READ_FROM_BUFFER_FULL(66,uint32 ,d1,d1.u32,90);
  CHECK_BITS_EQUAL(64,d1.unnamed_16_31,0x3e1);
  {
    t1.value = d1.t1;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: d1 ", CT_OUT(BOLD), d1.u32, CT_OUT(NORM));
    printf(".t1=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  d1.t1, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 d2 NOENCODE
  // {
    //  0_15: t2;
    // 16_31: 0x4e1;
    // ENCODE(t2,(value=t2));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 t2 : 16; // 0..15
      uint32 unnamed_16_31 : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_16_31 : 16; // 16..31
      uint32 t2 : 16; // 0..15
#endif
    };
    uint32  u32;
  } d2;
  READ_FROM_BUFFER_FULL(71,uint32 ,d2,d2.u32,91);
  CHECK_BITS_EQUAL(69,d2.unnamed_16_31,0x4e1);
  {
    t2.value = d2.t2;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: d2 ", CT_OUT(BOLD), d2.u32, CT_OUT(NORM));
    printf(".t2=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  d2.t2, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 d3 NOENCODE
  // {
    //  0_15: t3;
    // 16_31: 0x5e1;
    // ENCODE(t3,(value=t3));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 t3 : 16; // 0..15
      uint32 unnamed_16_31 : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_16_31 : 16; // 16..31
      uint32 t3 : 16; // 0..15
#endif
    };
    uint32  u32;
  } d3;
  READ_FROM_BUFFER_FULL(76,uint32 ,d3,d3.u32,92);
  CHECK_BITS_EQUAL(74,d3.unnamed_16_31,0x5e1);
  {
    t3.value = d3.t3;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: d3 ", CT_OUT(BOLD), d3.u32, CT_OUT(NORM));
    printf(".t3=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  d3.t3, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 d4 NOENCODE
  // {
    //  0_15: t4;
    // 16_31: 0x6e1;
    // ENCODE(t4,(value=t4));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 t4 : 16; // 0..15
      uint32 unnamed_16_31 : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_16_31 : 16; // 16..31
      uint32 t4 : 16; // 0..15
#endif
    };
    uint32  u32;
  } d4;
  READ_FROM_BUFFER_FULL(81,uint32 ,d4,d4.u32,93);
  CHECK_BITS_EQUAL(79,d4.unnamed_16_31,0x6e1);
  {
    t4.value = d4.t4;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: d4 ", CT_OUT(BOLD), d4.u32, CT_OUT(NORM));
    printf(".t4=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  d4.t4, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,TIMESTAMP_WHITERABBIT_EXTENDED::__unpack,uint32 id);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TPAT_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// TPAT_CRATE_DATA()
template<typename __data_src_t>
void TPAT_CRATE_DATA::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TPAT_CRATE_DATA",CT_OUT(NORM));
  }
  // MEMBER(DATA16 tpat);
  // UINT32 w1;
  READ_FROM_BUFFER(926,uint32 ,w1,95);
  // UINT32 w2;
  READ_FROM_BUFFER(927,uint32 ,w2,96);
  // UINT32 w3;
  READ_FROM_BUFFER(928,uint32 ,w3,97);
  // UINT32 trigger_pattern
  // {
    //  0_15: pattern;
    // 16_31: nothing;
    // ENCODE(tpat,(value=pattern));
  // }
  READ_FROM_BUFFER_FULL(935,uint32 ,trigger_pattern,trigger_pattern.u32,98);
  {
    tpat.value = trigger_pattern.pattern;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: trigger_pattern ", CT_OUT(BOLD), trigger_pattern.u32, CT_OUT(NORM));
    printf(".pattern=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trigger_pattern.pattern, CT_OUT(NORM));
    printf(".nothing=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trigger_pattern.nothing, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 coffee NOENCODE
  // {
    //  0_07: scaler_words;
    //  8_31: coffee;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 scaler_words : 8; // 0..7
      uint32 coffee : 24; // 8..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 coffee : 24; // 8..31
      uint32 scaler_words : 8; // 0..7
#endif
    };
    uint32  u32;
  } coffee;
  READ_FROM_BUFFER_FULL(942,uint32 ,coffee,coffee.u32,99);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: coffee ", CT_OUT(BOLD), coffee.u32, CT_OUT(NORM));
    printf(".scaler_words=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  coffee.scaler_words, CT_OUT(NORM));
    printf(".coffee=%s%6" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  coffee.coffee, CT_OUT(NORM));
    printf("\n");
  }
  // if((coffee.coffee == 0x00c0ffee))

  // else

  if ((coffee.coffee == 0x00c0ffee))
  {
    // list(0<=i<(coffee.scaler_words * 3))

    for (uint32 i = 0; i < (uint32) ((coffee.scaler_words * 3)); ++i)
    {
      // UINT32 scaler NOENCODE
      // {
        //  0_31: something;
      // }
      union
      {
        struct
        {
#if __BYTE_ORDER == __LITTLE_ENDIAN
          uint32 something : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
          uint32 something : 32; // 0..31
#endif
        };
        uint32  u32;
      } scaler;
      READ_FROM_BUFFER_FULL(951,uint32 ,scaler,scaler.u32,100);
      if (__buffer.is_memberdump())
      {
        printf("%s%08" PRIx32 "%s: scaler ", CT_OUT(BOLD), scaler.u32, CT_OUT(NORM));
        printf(".something=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  scaler.something, CT_OUT(NORM));
        printf("\n");
      }
    }
    // UINT32 dead NOENCODE
    // {
      //  0_31: 0xdeaddead;
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
    } dead;
    READ_FROM_BUFFER_FULL(957,uint32 ,dead,dead.u32,101);
    CHECK_BITS_EQUAL(956,dead.unnamed_0_31,0xdeaddead);
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: dead ", CT_OUT(BOLD), dead.u32, CT_OUT(NORM));
      printf("\n");
    }
    // several UINT32 eob NOENCODE;
    for ( ; ; ) {
    uint32  eob;if (__buffer.empty()) goto data_done_4;
    READ_FROM_BUFFER(959,uint32 ,eob,102);
    }
    data_done_4:;
  }

  else
  {
    // several UINT32 filler NOENCODE;
    for ( ; ; ) {
    uint32  filler;if (__buffer.empty()) goto data_done_5;
    READ_FROM_BUFFER(964,uint32 ,filler,103);
    }
    data_done_5:;
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,TPAT_CRATE_DATA::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for VME_CAEN_V1190_N.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V1190_N()
template<typename __data_src_t>
void VME_CAEN_V1190_N::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "VME_CAEN_V1190_N",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(730,uint32 ,header,header.u32,105);
  {
    geo.value = header.geom;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: header ", CT_OUT(BOLD), header.u32, CT_OUT(NORM));
    printf(".geom=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.geom, CT_OUT(NORM));
    printf(".event_count=%s%6" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.event_count, CT_OUT(NORM));
    printf(".seven_f=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.seven_f, CT_OUT(NORM));
    printf("\n");
  }
  // if((header.seven_f != 8))

  if ((header.seven_f != 8))
  {
    // UINT32 second1 NOENCODE
    // {
      //  0_31: 0xffffffff;
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
    } second1;
    READ_FROM_BUFFER_FULL(738,uint32 ,second1,second1.u32,106);
    CHECK_BITS_EQUAL(737,second1.unnamed_0_31,0xffffffff);
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: second1 ", CT_OUT(BOLD), second1.u32, CT_OUT(NORM));
      printf("\n");
    }
    // UINT32 real_header NOENCODE
    // {
      //  0_04: geom;
      //  5_26: event_count;
      // 27_31: 8;
    // }
    union
    {
      struct
      {
#if __BYTE_ORDER == __LITTLE_ENDIAN
        uint32 geom : 5; // 0..4
        uint32 event_count : 22; // 5..26
        uint32 unnamed_27_31 : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
        uint32 unnamed_27_31 : 5; // 27..31
        uint32 event_count : 22; // 5..26
        uint32 geom : 5; // 0..4
#endif
      };
      uint32  u32;
    } real_header;
    READ_FROM_BUFFER_FULL(745,uint32 ,real_header,real_header.u32,107);
    CHECK_BITS_EQUAL(744,real_header.unnamed_27_31,8);
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: real_header ", CT_OUT(BOLD), real_header.u32, CT_OUT(NORM));
      printf(".geom=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  real_header.geom, CT_OUT(NORM));
      printf(".event_count=%s%6" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  real_header.event_count, CT_OUT(NORM));
      printf("\n");
    }
  }
  // select several

    // tdc_header = TDC_HEADER();
    // measurement = TDC_DATA_V1190();
    // tdc_error = TDC_ERROR();
    // tdc_trailer = TDC_TRAILER();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: TDC_HEADER tdc_header: (s32) => (0xf8000000,0x08000000)
    // optimized match 2: TDC_DATA_V1190 measurement: (s32) => (0xf8000000,0x00000000)
    // optimized match 3: TDC_ERROR tdc_error: (s32) => (0xf8000000,0x20000000)
    // optimized match 4: TDC_TRAILER tdc_trailer: (s32) => (0xf8000000,0x18000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(754,uint32,__match_peek);
    // differ = 38000000 : 27 28 29
    uint32 __match_index = 0 | /* 27,29 */ ((__match_peek >> 27) & 0x00000007);
    static const sint8 __match_index_array[8] = { 2, 1, 0, 4, 3, 0, 0, 0, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(750,spurious_match_abort_loop_3,TDC_HEADER);
        UNPACK_DECL(750,TDC_HEADER,tdc_header);
        break;
      case 2:
        CHECK_SPURIOUS_MATCH_DECL(751,spurious_match_abort_loop_3,TDC_DATA_V1190);
        UNPACK_DECL(751,TDC_DATA_V1190,measurement);
        break;
      case 3:
        CHECK_SPURIOUS_MATCH_DECL(752,spurious_match_abort_loop_3,TDC_ERROR);
        UNPACK_DECL(752,TDC_ERROR,tdc_error);
        break;
      case 4:
        CHECK_SPURIOUS_MATCH_DECL(753,spurious_match_abort_loop_3,TDC_TRAILER);
        UNPACK_DECL(753,TDC_TRAILER,tdc_trailer);
        break;
    }
  }
  spurious_match_abort_loop_3:;
  // optional UINT32 ext_time_tag NOENCODE
  // {
    //  0_26: time_tag;
    // 27_31: 17;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 time_tag : 27; // 0..26
      uint32 unnamed_27_31 : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_27_31 : 5; // 27..31
      uint32 time_tag : 27; // 0..26
#endif
    };
    uint32  u32;
  } ext_time_tag;
  if (__buffer.empty()) goto data_done_6;
  PEEK_FROM_BUFFER_FULL(761,uint32 ,ext_time_tag,ext_time_tag.u32,108);
  CHECK_JUMP_BITS_EQUAL(760,ext_time_tag.unnamed_27_31,17,data_done_6);
  __buffer.advance(sizeof(ext_time_tag.u32));
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: ext_time_tag ", CT_OUT(BOLD), ext_time_tag.u32, CT_OUT(NORM));
    printf(".time_tag=%s%7" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ext_time_tag.time_tag, CT_OUT(NORM));
    printf("\n");
  }
  data_done_6:;
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
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 geom : 5; // 0..4
      uint32 word_count : 16; // 5..20
      uint32 unused : 3; // 21..23
      uint32 tdc_error : 1; // 24
      uint32 overflow : 1; // 25
      uint32 trigger_lost : 1; // 26
      uint32 whatever : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 whatever : 5; // 27..31
      uint32 trigger_lost : 1; // 26
      uint32 overflow : 1; // 25
      uint32 tdc_error : 1; // 24
      uint32 unused : 3; // 21..23
      uint32 word_count : 16; // 5..20
      uint32 geom : 5; // 0..4
#endif
    };
    uint32  u32;
  } trailer;
  READ_FROM_BUFFER_FULL(773,uint32 ,trailer,trailer.u32,109);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: trailer ", CT_OUT(BOLD), trailer.u32, CT_OUT(NORM));
    printf(".geom=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.geom, CT_OUT(NORM));
    printf(".word_count=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.word_count, CT_OUT(NORM));
    printf(".unused=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.unused, CT_OUT(NORM));
    printf(".tdc_error=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.tdc_error, CT_OUT(NORM));
    printf(".overflow=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.overflow, CT_OUT(NORM));
    printf(".trigger_lost=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.trigger_lost, CT_OUT(NORM));
    printf(".whatever=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.whatever, CT_OUT(NORM));
    printf("\n");
  }
  // optional UINT32 eob NOENCODE;
  uint32  eob;if (__buffer.empty()) goto data_done_7;
  READ_FROM_BUFFER(775,uint32 ,eob,110);
  data_done_7:;
}
FORCE_IMPL_DATA_SRC_FCN(void,VME_CAEN_V1190_N::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TPC_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// TPC_CRATE_DATA()
template<typename __data_src_t>
void TPC_CRATE_DATA::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TPC_CRATE_DATA",CT_OUT(NORM));
  }
  // select several

    // barrier0 = BARRIER();
    // v785 = VME_CAEN_V7X5(geom=8);
    // v775 = VME_CAEN_V7X5(geom=12);
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: BARRIER barrier0: (s32) => (0xff000000,0xf5000000)
    // optimized match 2: VME_CAEN_V7X5 v785: (s32) => (0xff00c000,0x42000000)
    // optimized match 3: VME_CAEN_V7X5 v775: (s32) => (0xff00c000,0x62000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1026,uint32,__match_peek);
    // differ = b7000000 : 24 25 26 28 29 31
    uint32 __match_index = 0 | /* 24,26 */ ((__match_peek >> 24) & 0x00000007) | /* 28,29 */ ((__match_peek >> 25) & 0x00000018) | /* 31,31 */ ((__match_peek >> 26) & 0x00000020);
    static const sint8 __match_index_array[64] = { 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1023,spurious_match_abort_loop_4,BARRIER);
        UNPACK_DECL(1023,BARRIER,barrier0);
        break;
      case 2:
        CHECK_SPURIOUS_MATCH_DECL(1024,spurious_match_abort_loop_4,VME_CAEN_V7X5,/*geom*/8);
        UNPACK_DECL(1024,VME_CAEN_V7X5,v785,/*geom*/8);
        break;
      case 3:
        CHECK_SPURIOUS_MATCH_DECL(1025,spurious_match_abort_loop_4,VME_CAEN_V7X5,/*geom*/12);
        UNPACK_DECL(1025,VME_CAEN_V7X5,v775,/*geom*/12);
        break;
    }
  }
  spurious_match_abort_loop_4:;
  // UINT32 aaahhh NOENCODE
  // {
    //  0_31: 0xaaaa1190;
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
  } aaahhh;
  READ_FROM_BUFFER_FULL(1028,uint32 ,aaahhh,aaahhh.u32,112);
  CHECK_BITS_EQUAL(1028,aaahhh.unnamed_0_31,0xaaaa1190);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: aaahhh ", CT_OUT(BOLD), aaahhh.u32, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 exxxxx NOENCODE;
  uint32  exxxxx;READ_FROM_BUFFER(1029,uint32 ,exxxxx,113);
  // barrier1 = BARRIER();
  UNPACK_DECL(1031,BARRIER,barrier1);
  // v1190 = VME_CAEN_V1190_N();
  UNPACK_DECL(1032,VME_CAEN_V1190_N,v1190);
  // select several

    // dummy = DUMMY();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: DUMMY dummy: (s32)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1038,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1037,spurious_match_abort_loop_5,DUMMY);
        UNPACK_DECL(1037,DUMMY,dummy);
        break;
    }
  }
  spurious_match_abort_loop_5:;
}
FORCE_IMPL_DATA_SRC_FCN(void,TPC_CRATE_DATA::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for VME_MESYTEC_MDPP16.
 *
 * Do not edit - automatically generated.
 */

// VME_MESYTEC_MDPP16(geom)
template<typename __data_src_t>
void VME_MESYTEC_MDPP16::__unpack(__data_src_t &__buffer,uint32 geom)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "VME_MESYTEC_MDPP16",CT_OUT(NORM));
  }
  // MEMBER(DATA24 adc[16]);
  // MEMBER(DATA24 tdc[16]);
  // MEMBER(DATA24 trig_tdc[16]);
  // MEMBER(DATA24 adc_short[16]);
  // MARK_COUNT(start);
  void *__mark_start = __buffer._data;
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
  READ_FROM_BUFFER_FULL(559,uint32 ,header,header.u32,114);
  CHECK_BITS_EQUAL(556,header.geom,geom);
  CHECK_BITS_EQUAL(557,header.unnamed_24_29,0);
  CHECK_BITS_EQUAL(558,header.unnamed_30_31,1);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: header ", CT_OUT(BOLD), header.u32, CT_OUT(NORM));
    printf(".word_number=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.word_number, CT_OUT(NORM));
    printf(".adc_res=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.adc_res, CT_OUT(NORM));
    printf(".tdc_res=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.tdc_res, CT_OUT(NORM));
    printf(".geom=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.geom, CT_OUT(NORM));
    printf("\n");
  }
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
  for ( ; ; ) {
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 value : 16; // 0..15
      uint32 channel : 4; // 16..19
      uint32 ch_kind : 2; // 20..21
      uint32 overflow : 1; // 22
      uint32 pileup : 1; // 23
      uint32 unnamed_24_27 : 4; // 24..27
      uint32 unnamed_28_31 : 4; // 28..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_28_31 : 4; // 28..31
      uint32 unnamed_24_27 : 4; // 24..27
      uint32 pileup : 1; // 23
      uint32 overflow : 1; // 22
      uint32 ch_kind : 2; // 20..21
      uint32 channel : 4; // 16..19
      uint32 value : 16; // 0..15
#endif
    };
    uint32  u32;
  } ch_data;
  if (__buffer.empty()) goto data_done_8;
  PEEK_FROM_BUFFER_FULL(587,uint32 ,ch_data,ch_data.u32,115);
  CHECK_JUMP_BITS_EQUAL(568,ch_data.unnamed_24_27,0,data_done_8);
  CHECK_JUMP_BITS_EQUAL(569,ch_data.unnamed_28_31,1,data_done_8);
  __buffer.advance(sizeof(ch_data.u32));
  {
    if ((ch_data.ch_kind == 0))
    {
      typedef __typeof__(*(&(adc))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = adc.insert_index(573,ch_data.channel);
      __item.value = ch_data.value;
    }
    if ((ch_data.ch_kind == 1))
    {
      typedef __typeof__(*(&(tdc))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = tdc.insert_index(577,ch_data.channel);
      __item.value = ch_data.value;
    }
    if ((ch_data.ch_kind == 2))
    {
      typedef __typeof__(*(&(trig_tdc))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = trig_tdc.insert_index(581,ch_data.channel);
      __item.value = ch_data.value;
    }
    if ((ch_data.ch_kind == 3))
    {
      typedef __typeof__(*(&(adc_short))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = adc_short.insert_index(585,ch_data.channel);
      __item.value = ch_data.value;
    }
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: ch_data ", CT_OUT(BOLD), ch_data.u32, CT_OUT(NORM));
    printf(".value=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ch_data.value, CT_OUT(NORM));
    printf(".channel=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ch_data.channel, CT_OUT(NORM));
    printf(".ch_kind=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ch_data.ch_kind, CT_OUT(NORM));
    printf(".overflow=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ch_data.overflow, CT_OUT(NORM));
    printf(".pileup=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ch_data.pileup, CT_OUT(NORM));
    printf("\n");
  }
  }
  data_done_8:;
  // several UINT32 fill_word NOENCODE
  // {
    //  0_31: 0;
  // }
  for ( ; ; ) {
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
  } fill_word;
  if (__buffer.empty()) goto data_done_9;
  PEEK_FROM_BUFFER_FULL(592,uint32 ,fill_word,fill_word.u32,116);
  CHECK_JUMP_BITS_EQUAL(591,fill_word.unnamed_0_31,0,data_done_9);
  __buffer.advance(sizeof(fill_word.u32));
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: fill_word ", CT_OUT(BOLD), fill_word.u32, CT_OUT(NORM));
    printf("\n");
  }
  }
  data_done_9:;
  // UINT32 end_of_event
  // {
    //  0_29: counter;
    // 30_31: 3;
  // }
  READ_FROM_BUFFER_FULL(598,uint32 ,end_of_event,end_of_event.u32,117);
  CHECK_BITS_EQUAL(597,end_of_event.unnamed_30_31,3);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: end_of_event ", CT_OUT(BOLD), end_of_event.u32, CT_OUT(NORM));
    printf(".counter=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  end_of_event.counter, CT_OUT(NORM));
    printf("\n");
  }
  // MARK_COUNT(end);
  void *__mark_end = __buffer._data;
  // CHECK_COUNT(header.word_number,start,end,( - 4),4)
  CHECK_WORD_COUNT(601,header.word_number,start,end,( - 4),4);
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,VME_MESYTEC_MDPP16::__unpack,uint32 geom);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TRAVMUS_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// TRAVMUS_CRATE_DATA()
template<typename __data_src_t>
void TRAVMUS_CRATE_DATA::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TRAVMUS_CRATE_DATA",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(1089,uint32 ,coffee,coffee.u32,119);
  CHECK_BITS_EQUAL(1088,coffee.unnamed_8_31,0x00c0ffee);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: coffee ", CT_OUT(BOLD), coffee.u32, CT_OUT(NORM));
    printf(".counter=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  coffee.counter, CT_OUT(NORM));
    printf("\n");
  }
  // if((coffee.counter == 0))

  // else

  if ((coffee.counter == 0))
  {
    // UINT32 dead NOENCODE
    // {
      //  0_31: 0xdeaddead;
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
    } dead;
    READ_FROM_BUFFER_FULL(1096,uint32 ,dead,dead.u32,120);
    CHECK_BITS_EQUAL(1095,dead.unnamed_0_31,0xdeaddead);
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: dead ", CT_OUT(BOLD), dead.u32, CT_OUT(NORM));
      printf("\n");
    }
    // UINT32 vtime NOENCODE;
    uint32  vtime;READ_FROM_BUFFER(1098,uint32 ,vtime,121);
    // UINT32 dtime NOENCODE;
    uint32  dtime;READ_FROM_BUFFER(1099,uint32 ,dtime,122);
    // UINT32 barrier NOENCODE
    // {
      //  0_15: counter;
      // 16_31: bar = MATCH(0xf520);
    // }
    union
    {
      struct
      {
#if __BYTE_ORDER == __LITTLE_ENDIAN
        uint32 counter : 16; // 0..15
        uint32 bar : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
        uint32 bar : 16; // 16..31
        uint32 counter : 16; // 0..15
#endif
      };
      uint32  u32;
    } barrier;
    READ_FROM_BUFFER_FULL(1106,uint32 ,barrier,barrier.u32,123);
    CHECK_BITS_EQUAL(1104,barrier.bar,0xf520);
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: barrier ", CT_OUT(BOLD), barrier.u32, CT_OUT(NORM));
      printf(".counter=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  barrier.counter, CT_OUT(NORM));
      printf(".bar=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  barrier.bar, CT_OUT(NORM));
      printf("\n");
    }
    // select several

      // mdpp = VME_MESYTEC_MDPP16(geom=8);
    for ( ; ; )
    {
      if (__buffer.empty()) break;
      int __match_no = 0;
      // optimized match 1: VME_MESYTEC_MDPP16 mdpp: (s32) => (0xffff0000,0x40080000)
      {
      uint32 __match_peek;
      PEEK_FROM_BUFFER(1111,uint32,__match_peek);
      // differ = 00000000 :
      uint32 __match_index = 0;
      static const sint8 __match_index_array[1] = { 1, };
      __match_no = __match_index_array[__match_index];
      // last_subevent_item = 0
      }
      if (!__match_no) break;
      switch (__match_no)
      {
        case 1:
          CHECK_SPURIOUS_MATCH_DECL(1110,spurious_match_abort_loop_6,VME_MESYTEC_MDPP16,/*geom*/8);
          UNPACK_DECL(1110,VME_MESYTEC_MDPP16,mdpp,/*geom*/8);
          break;
      }
    }
    spurious_match_abort_loop_6:;
  }

  else
  {
    // select several

      // dummy = DUMMY();
    for ( ; ; )
    {
      if (__buffer.empty()) break;
      int __match_no = 0;
      // optimized match 1: DUMMY dummy: (s32)
      {
      uint32 __match_peek;
      PEEK_FROM_BUFFER(1119,uint32,__match_peek);
      // differ = 00000000 :
      uint32 __match_index = 0;
      static const sint8 __match_index_array[1] = { 1, };
      __match_no = __match_index_array[__match_index];
      // last_subevent_item = 0
      }
      if (!__match_no) break;
      switch (__match_no)
      {
        case 1:
          CHECK_SPURIOUS_MATCH_DECL(1118,spurious_match_abort_loop_7,DUMMY);
          UNPACK_DECL(1118,DUMMY,dummy);
          break;
      }
    }
    spurious_match_abort_loop_7:;
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,TRAVMUS_CRATE_DATA::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for TRIG3EVENT.
 *
 * Do not edit - automatically generated.
 */

// TRIG3EVENT()
template<typename __data_src_t>
void TRIG3EVENT::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "TRIG3EVENT",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(868,uint32 ,trig3,trig3.u32,125);
  CHECK_BITS_EQUAL(867,trig3.unnamed_0_31,0x20202020);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: trig3 ", CT_OUT(BOLD), trig3.u32, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,TRIG3EVENT::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for USER_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// USER_CRATE_DATA()
template<typename __data_src_t>
void USER_CRATE_DATA::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "USER_CRATE_DATA",CT_OUT(NORM));
  }
  // barrier0 = BARRIER();
  UNPACK_DECL(1044,BARRIER,barrier0);
  // v830 = MVLC_SCALER(geo=8);
  UNPACK_DECL(1047,MVLC_SCALER,v830,/*geo*/8);
  // select several

    // barrier1 = BARRIER();
    // v775[0] = VME_CAEN_V7X5(geom=8);
    // v775[1] = VME_CAEN_V7X5(geom=9);
    // v785[0] = VME_CAEN_V7X5(geom=10);
    // v785[1] = VME_CAEN_V7X5(geom=12);
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: BARRIER barrier1: (s32) => (0xff000000,0xf5000000)
    // optimized match 2: VME_CAEN_V7X5 v775[0]: (s32) => (0xff00c000,0x42000000)
    // optimized match 3: VME_CAEN_V7X5 v775[1]: (s32) => (0xff00c000,0x4a000000)
    // optimized match 4: VME_CAEN_V7X5 v785[0]: (s32) => (0xff00c000,0x52000000)
    // optimized match 5: VME_CAEN_V7X5 v785[1]: (s32) => (0xff00c000,0x62000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1058,uint32,__match_peek);
    // differ = bf000000 : 24 25 26 27 28 29 31
    uint32 __match_index = 0 | /* 24,29 */ ((__match_peek >> 24) & 0x0000003f) | /* 31,31 */ ((__match_peek >> 25) & 0x00000040);
    static const sint8 __match_index_array[128] = { 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1053,spurious_match_abort_loop_8,BARRIER);
        UNPACK_DECL(1053,BARRIER,barrier1);
        break;
      case 2:
        CHECK_SPURIOUS_MATCH_DECL(1054,spurious_match_abort_loop_8,VME_CAEN_V7X5,/*geom*/8);
        UNPACK_DECL(1054,VME_CAEN_V7X5,v775[0],/*geom*/8);
        break;
      case 3:
        CHECK_SPURIOUS_MATCH_DECL(1055,spurious_match_abort_loop_8,VME_CAEN_V7X5,/*geom*/9);
        UNPACK_DECL(1055,VME_CAEN_V7X5,v775[1],/*geom*/9);
        break;
      case 4:
        CHECK_SPURIOUS_MATCH_DECL(1056,spurious_match_abort_loop_8,VME_CAEN_V7X5,/*geom*/10);
        UNPACK_DECL(1056,VME_CAEN_V7X5,v785[0],/*geom*/10);
        break;
      case 5:
        CHECK_SPURIOUS_MATCH_DECL(1057,spurious_match_abort_loop_8,VME_CAEN_V7X5,/*geom*/12);
        UNPACK_DECL(1057,VME_CAEN_V7X5,v785[1],/*geom*/12);
        break;
    }
  }
  spurious_match_abort_loop_8:;
  // UINT32 aaahhh NOENCODE
  // {
    //  0_31: 0xaaaa1290;
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
  } aaahhh;
  READ_FROM_BUFFER_FULL(1060,uint32 ,aaahhh,aaahhh.u32,127);
  CHECK_BITS_EQUAL(1060,aaahhh.unnamed_0_31,0xaaaa1290);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: aaahhh ", CT_OUT(BOLD), aaahhh.u32, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 filler1 NOENCODE;
  uint32  filler1;READ_FROM_BUFFER(1061,uint32 ,filler1,128);
  // barrier2 = BARRIER();
  UNPACK_DECL(1062,BARRIER,barrier2);
  // v1290 = VME_CAEN_V1290_N();
  UNPACK_DECL(1063,VME_CAEN_V1290_N,v1290);
  // optional UINT32 eodb NOENCODE;
  uint32  eodb;if (__buffer.empty()) goto data_done_10;
  READ_FROM_BUFFER(1064,uint32 ,eodb,129);
  data_done_10:;
}
FORCE_IMPL_DATA_SRC_FCN(void,USER_CRATE_DATA::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for VME_CAEN_V830.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V830(geom)
template<typename __data_src_t>
void VME_CAEN_V830::__unpack(__data_src_t &__buffer,uint32 geom)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "VME_CAEN_V830",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(792,uint32 ,header,header.u32,130);
  CHECK_BITS_EQUAL(790,header.unnamed_26_26,1);
  CHECK_BITS_EQUAL(791,header.geom,geom);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: header ", CT_OUT(BOLD), header.u32, CT_OUT(NORM));
    printf(".event_number=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.event_number, CT_OUT(NORM));
    printf(".ts=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.ts, CT_OUT(NORM));
    printf(".count=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.count, CT_OUT(NORM));
    printf(".undefined=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.undefined, CT_OUT(NORM));
    printf(".geom=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  header.geom, CT_OUT(NORM));
    printf("\n");
  }
  // list(0<=index<header.count)

  for (uint32 index = 0; index < (uint32) (header.count); ++index)
  {
    // UINT32 ch_data NOENCODE
    // {
      //  0_25: value;
      //    26: 0;
      // 27_31: channel;
      // ENCODE(data[channel],(value=value));
    // }
    union
    {
      struct
      {
#if __BYTE_ORDER == __LITTLE_ENDIAN
        uint32 value : 26; // 0..25
        uint32 unnamed_26_26 : 1; // 26
        uint32 channel : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
        uint32 channel : 5; // 27..31
        uint32 unnamed_26_26 : 1; // 26
        uint32 value : 26; // 0..25
#endif
      };
      uint32  u32;
    } ch_data;
    READ_FROM_BUFFER_FULL(803,uint32 ,ch_data,ch_data.u32,131);
    CHECK_BITS_EQUAL(799,ch_data.unnamed_26_26,0);
    {
      typedef __typeof__(*(&(data))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = data.insert_index(802,ch_data.channel);
      __item.value = ch_data.value;
    }
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: ch_data ", CT_OUT(BOLD), ch_data.u32, CT_OUT(NORM));
      printf(".value=%s%7" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ch_data.value, CT_OUT(NORM));
      printf(".channel=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ch_data.channel, CT_OUT(NORM));
      printf("\n");
    }
  }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,VME_CAEN_V830::__unpack,uint32 geom);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for VULOM_TPAT.
 *
 * Do not edit - automatically generated.
 */

// VULOM_TPAT()
template<typename __data_src_t>
void VULOM_TPAT::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "VULOM_TPAT",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(1073,uint32 ,vulom_head,vulom_head.u32,133);
  CHECK_BITS_EQUAL(1072,vulom_head.head,0xf500);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: vulom_head ", CT_OUT(BOLD), vulom_head.u32, CT_OUT(NORM));
    printf(".counter=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  vulom_head.counter, CT_OUT(NORM));
    printf(".head=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  vulom_head.head, CT_OUT(NORM));
    printf("\n");
  }
  // list(0<=i<vulom_head.counter)

  for (uint32 i = 0; i < (uint32) (vulom_head.counter); ++i)
  {
    // UINT32 tp NOENCODE;
    uint32  tp;READ_FROM_BUFFER(1078,uint32 ,tp,134);
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,VULOM_TPAT::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for WR_MULTI.
 *
 * Do not edit - automatically generated.
 */

// WR_MULTI()
template<typename __data_src_t>
void WR_MULTI::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "WR_MULTI",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(92,uint32 ,hi,hi.u32,136);
  {
    time_hi.value = hi.time;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: hi ", CT_OUT(BOLD), hi.u32, CT_OUT(NORM));
    printf(".time=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  hi.time, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 lo NOENCODE
  // {
    //  0_31: time;
    // ENCODE(time_lo,(value=time));
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
  } lo;
  READ_FROM_BUFFER_FULL(96,uint32 ,lo,lo.u32,137);
  {
    time_lo.value = lo.time;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: lo ", CT_OUT(BOLD), lo.u32, CT_OUT(NORM));
    printf(".time=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  lo.time, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,WR_MULTI::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for ZERO_FILLER.
 *
 * Do not edit - automatically generated.
 */

// ZERO_FILLER()
template<typename __data_src_t>
void ZERO_FILLER::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "ZERO_FILLER",CT_OUT(NORM));
  }
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
  READ_FROM_BUFFER_FULL(917,uint32 ,filler,filler.u32,139);
  CHECK_BITS_EQUAL(916,filler.zero,0);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: filler ", CT_OUT(BOLD), filler.u32, CT_OUT(NORM));
    printf(".zero=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  filler.zero, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,ZERO_FILLER::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for aida_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(aida_subev)
template<typename __data_src_t>
void aida_subev::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_MAGENTA),  "aida_subev",CT_OUT(NORM));
  }
  // ts = TIMESTAMP_WHITERABBIT(id=0x700);
  UNPACK_DECL(1152,TIMESTAMP_WHITERABBIT,ts,/*id*/0x700);
  // external data = EXT_AIDA();
  UNPACK_DECL(1153,EXT_AIDA,data);
}
FORCE_IMPL_DATA_SRC_FCN(void,aida_subev::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for bplast_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(bplast_subev)
template<typename __data_src_t>
void bplast_subev::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_MAGENTA),  "bplast_subev",CT_OUT(NORM));
  }
  // select optional

    // ts = TIMESTAMP_WHITERABBIT(id=0x500);
  do
  {
    if (__buffer.empty()) goto no_match_2;
    int __match_no = 0;
    // optimized match 1: TIMESTAMP_WHITERABBIT ts: (s32) => (0xfffeffff,0x00000500)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1186,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_2;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1185,spurious_match_abort_loop_9,TIMESTAMP_WHITERABBIT,/*id*/0x500);
        UNPACK_DECL(1185,TIMESTAMP_WHITERABBIT,ts,/*id*/0x500);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_9:;
    no_match_2:;
  // select optional

    // trigger_window = TAMEX4_HEADER();
  do
  {
    if (__buffer.empty()) goto no_match_3;
    int __match_no = 0;
    // optimized match 1: TAMEX4_HEADER trigger_window: (s32) => (0x00000000,0x00000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1191,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_3;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1190,spurious_match_abort_loop_10,TAMEX4_HEADER);
        UNPACK_DECL(1190,TAMEX4_HEADER,trigger_window);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_10:;
    no_match_3:;
  // select several

    // padding = TAMEX4_PADDING();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: TAMEX4_PADDING padding: (s32) => (0xfff00000,0xadd00000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1196,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1195,spurious_match_abort_loop_11,TAMEX4_PADDING);
        UNPACK_DECL(1195,TAMEX4_PADDING,padding);
        break;
    }
  }
  spurious_match_abort_loop_11:;
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
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: TAMEX4_SFP tamex[0]: (s32) => (0xfffff0ff,0x00000034)
    // optimized match 2: TAMEX4_SFP tamex[1]: (s32) => (0xfffff0ff,0x00010034)
    // optimized match 3: TAMEX4_SFP tamex[2]: (s32) => (0xfffff0ff,0x00020034)
    // optimized match 4: TAMEX4_SFP tamex[3]: (s32) => (0xfffff0ff,0x00030034)
    // optimized match 5: TAMEX4_SFP tamex[4]: (s32) => (0xfffff0ff,0x00040034)
    // optimized match 6: TAMEX4_SFP tamex[5]: (s32) => (0xfffff0ff,0x00050034)
    // optimized match 7: TAMEX4_SFP tamex[6]: (s32) => (0xfffff0ff,0x00060034)
    // optimized match 8: TAMEX4_SFP tamex[7]: (s32) => (0xfffff0ff,0x00070034)
    // optimized match 9: TAMEX4_SFP tamex[8]: (s32) => (0xfffff0ff,0x00080034)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1209,uint32,__match_peek);
    // differ = 000f0000 : 16 17 18 19
    uint32 __match_index = 0 | /* 16,19 */ ((__match_peek >> 16) & 0x0000000f);
    static const sint8 __match_index_array[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 1
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        UNPACK_DECL(1200,TAMEX4_SFP,tamex[0],/*sfp*/0,/*card*/0);
        break;
      case 2:
        UNPACK_DECL(1201,TAMEX4_SFP,tamex[1],/*sfp*/0,/*card*/1);
        break;
      case 3:
        UNPACK_DECL(1202,TAMEX4_SFP,tamex[2],/*sfp*/0,/*card*/2);
        break;
      case 4:
        UNPACK_DECL(1203,TAMEX4_SFP,tamex[3],/*sfp*/0,/*card*/3);
        break;
      case 5:
        UNPACK_DECL(1204,TAMEX4_SFP,tamex[4],/*sfp*/0,/*card*/4);
        break;
      case 6:
        UNPACK_DECL(1205,TAMEX4_SFP,tamex[5],/*sfp*/0,/*card*/5);
        break;
      case 7:
        UNPACK_DECL(1206,TAMEX4_SFP,tamex[6],/*sfp*/0,/*card*/6);
        break;
      case 8:
        UNPACK_DECL(1207,TAMEX4_SFP,tamex[7],/*sfp*/0,/*card*/7);
        break;
      case 9:
        UNPACK_DECL(1208,TAMEX4_SFP,tamex[8],/*sfp*/0,/*card*/8);
        break;
    }
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,bplast_subev::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for febex_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(febex_subev)
template<typename __data_src_t>
void febex_subev::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_MAGENTA),  "febex_subev",CT_OUT(NORM));
  }
  // select optional

    // ts = TIMESTAMP_WHITERABBIT(id=0x400);
  do
  {
    if (__buffer.empty()) goto no_match_4;
    int __match_no = 0;
    // optimized match 1: TIMESTAMP_WHITERABBIT ts: (s32) => (0xfffeffff,0x00000400)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1162,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_4;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1161,spurious_match_abort_loop_12,TIMESTAMP_WHITERABBIT,/*id*/0x400);
        UNPACK_DECL(1161,TIMESTAMP_WHITERABBIT,ts,/*id*/0x400);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_12:;
    no_match_4:;
  // select several

    // padding = FEBEX_PADDING();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: FEBEX_PADDING padding: (s32) => (0xfff00000,0xadd00000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1167,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1166,spurious_match_abort_loop_13,FEBEX_PADDING);
        UNPACK_DECL(1166,FEBEX_PADDING,padding);
        break;
    }
  }
  spurious_match_abort_loop_13:;
  // select several

    // data[0] = FEBEX_EVENT(card=0);
    // data[1] = FEBEX_EVENT(card=1);
    // data[2] = FEBEX_EVENT(card=2);
    // data[3] = FEBEX_EVENT(card=3);
    // data[4] = FEBEX_EVENT(card=4);
    // data[5] = FEBEX_EVENT(card=5);
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: FEBEX_EVENT data[0]: (s32) => (0xffff00ff,0xff000034)
    // optimized match 2: FEBEX_EVENT data[1]: (s32) => (0xffff00ff,0xff010034)
    // optimized match 3: FEBEX_EVENT data[2]: (s32) => (0xffff00ff,0xff020034)
    // optimized match 4: FEBEX_EVENT data[3]: (s32) => (0xffff00ff,0xff030034)
    // optimized match 5: FEBEX_EVENT data[4]: (s32) => (0xffff00ff,0xff040034)
    // optimized match 6: FEBEX_EVENT data[5]: (s32) => (0xffff00ff,0xff050034)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1177,uint32,__match_peek);
    // differ = 00070000 : 16 17 18
    uint32 __match_index = 0 | /* 16,18 */ ((__match_peek >> 16) & 0x00000007);
    static const sint8 __match_index_array[8] = { 1, 2, 3, 4, 5, 6, 0, 0, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 1
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        UNPACK_DECL(1171,FEBEX_EVENT,data[0],/*card*/0);
        break;
      case 2:
        UNPACK_DECL(1172,FEBEX_EVENT,data[1],/*card*/1);
        break;
      case 3:
        UNPACK_DECL(1173,FEBEX_EVENT,data[2],/*card*/2);
        break;
      case 4:
        UNPACK_DECL(1174,FEBEX_EVENT,data[3],/*card*/3);
        break;
      case 5:
        UNPACK_DECL(1175,FEBEX_EVENT,data[4],/*card*/4);
        break;
      case 6:
        UNPACK_DECL(1176,FEBEX_EVENT,data[5],/*card*/5);
        break;
    }
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,febex_subev::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for frs_main_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_main_subev)
template<typename __data_src_t>
void frs_main_subev::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_MAGENTA),  "frs_main_subev",CT_OUT(NORM));
  }
  // select several

    // trig3 = TRIG3EVENT();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: TRIG3EVENT trig3: (s32) => (0xffffffff,0x20202020)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1217,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1216,spurious_match_abort_loop_14,TRIG3EVENT);
        UNPACK_DECL(1216,TRIG3EVENT,trig3);
        break;
    }
  }
  spurious_match_abort_loop_14:;
  // select several

    // spill_on = SPILL_ON();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: SPILL_ON spill_on: (s32) => (0xffffffff,0x30303030)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1222,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1221,spurious_match_abort_loop_15,SPILL_ON);
        UNPACK_DECL(1221,SPILL_ON,spill_on);
        break;
    }
  }
  spurious_match_abort_loop_15:;
  // select several

    // spill_off = SPILL_OFF();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: SPILL_OFF spill_off: (s32) => (0xffffffff,0x4040400a)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1227,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1226,spurious_match_abort_loop_16,SPILL_OFF);
        UNPACK_DECL(1226,SPILL_OFF,spill_off);
        break;
    }
  }
  spurious_match_abort_loop_16:;
  // UINT32 sevens NOENCODE
  // {
    //  0_31: 0x77777777;
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
  } sevens;
  READ_FROM_BUFFER_FULL(1232,uint32 ,sevens,sevens.u32,141);
  CHECK_BITS_EQUAL(1231,sevens.unnamed_0_31,0x77777777);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: sevens ", CT_OUT(BOLD), sevens.u32, CT_OUT(NORM));
    printf("\n");
  }
  // select optional

    // data = MAIN_CRATE_DATA();
  do
  {
    if (__buffer.empty()) goto no_match_5;
    int __match_no = 0;
    // optimized match 1: MAIN_CRATE_DATA data: could not get bits
    __buffer.peeking();
    MATCH_DECL(1236,__match_no,1,MAIN_CRATE_DATA,data);
    if (!__match_no) goto no_match_5;
    switch (__match_no)
    {
      case 1:
        UNPACK_DECL(1236,MAIN_CRATE_DATA,data);
        break;
    }
  }
  while (0);
    no_match_5:;
}
FORCE_IMPL_DATA_SRC_FCN(void,frs_main_subev::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for frs_tpat_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_tpat_subev)
template<typename __data_src_t>
void frs_tpat_subev::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_MAGENTA),  "frs_tpat_subev",CT_OUT(NORM));
  }
  // select optional

    // wr = TIMESTAMP_WHITERABBIT(id=0x100);
  do
  {
    if (__buffer.empty()) goto no_match_6;
    int __match_no = 0;
    // optimized match 1: TIMESTAMP_WHITERABBIT wr: (s32) => (0xfffeffff,0x00000100)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1299,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_6;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1298,spurious_match_abort_loop_17,TIMESTAMP_WHITERABBIT,/*id*/0x100);
        UNPACK_DECL(1298,TIMESTAMP_WHITERABBIT,wr,/*id*/0x100);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_17:;
    no_match_6:;
  // select several

    // trig3 = TRIG3EVENT();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: TRIG3EVENT trig3: (s32) => (0xffffffff,0x20202020)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1304,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1303,spurious_match_abort_loop_18,TRIG3EVENT);
        UNPACK_DECL(1303,TRIG3EVENT,trig3);
        break;
    }
  }
  spurious_match_abort_loop_18:;
  // select optional

    // data = TPAT_CRATE_DATA();
  do
  {
    if (__buffer.empty()) goto no_match_7;
    int __match_no = 0;
    // optimized match 1: TPAT_CRATE_DATA data: (s32)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1309,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 1
    }
    if (!__match_no) goto no_match_7;
    switch (__match_no)
    {
      case 1:
        UNPACK_DECL(1308,TPAT_CRATE_DATA,data);
        break;
    }
  }
  while (0);
    no_match_7:;
}
FORCE_IMPL_DATA_SRC_FCN(void,frs_tpat_subev::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for frs_tpc_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_tpc_subev)
template<typename __data_src_t>
void frs_tpc_subev::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_MAGENTA),  "frs_tpc_subev",CT_OUT(NORM));
  }
  // optional UINT32 be
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
  } __be;
  if (__buffer.empty()) goto data_done_11;
  PEEK_FROM_BUFFER_FULL(1242,uint32 ,be,__be.u32,142);
  CHECK_JUMP_BITS_EQUAL(1242,__be.b,0xbad00bad,data_done_11);
  be.u32 = __be.u32;
  __buffer.advance(sizeof(__be.u32));
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: be ", CT_OUT(BOLD), __be.u32, CT_OUT(NORM));
    printf(".b=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  __be.b, CT_OUT(NORM));
    printf("\n");
  }
  data_done_11:;
  // select several

    // trig3 = TRIG3EVENT();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: TRIG3EVENT trig3: (s32) => (0xffffffff,0x20202020)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1247,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1246,spurious_match_abort_loop_19,TRIG3EVENT);
        UNPACK_DECL(1246,TRIG3EVENT,trig3);
        break;
    }
  }
  spurious_match_abort_loop_19:;
  // select several

    // spill_on = SPILL_ON();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: SPILL_ON spill_on: (s32) => (0xffffffff,0x30303030)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1252,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1251,spurious_match_abort_loop_20,SPILL_ON);
        UNPACK_DECL(1251,SPILL_ON,spill_on);
        break;
    }
  }
  spurious_match_abort_loop_20:;
  // select several

    // spill_off = SPILL_OFF();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: SPILL_OFF spill_off: (s32) => (0xffffffff,0x4040400a)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1257,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1256,spurious_match_abort_loop_21,SPILL_OFF);
        UNPACK_DECL(1256,SPILL_OFF,spill_off);
        break;
    }
  }
  spurious_match_abort_loop_21:;
  // select optional

    // data = TPC_CRATE_DATA();
  do
  {
    if (__buffer.empty()) goto no_match_8;
    int __match_no = 0;
    // optimized match 1: TPC_CRATE_DATA data: could not get bits
    __buffer.peeking();
    MATCH_DECL(1261,__match_no,1,TPC_CRATE_DATA,data);
    if (!__match_no) goto no_match_8;
    switch (__match_no)
    {
      case 1:
        UNPACK_DECL(1261,TPC_CRATE_DATA,data);
        break;
    }
  }
  while (0);
    no_match_8:;
}
FORCE_IMPL_DATA_SRC_FCN(void,frs_tpc_subev::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for frs_travmus_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_travmus_subev)
template<typename __data_src_t>
void frs_travmus_subev::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_MAGENTA),  "frs_travmus_subev",CT_OUT(NORM));
  }
  // select optional

    // wr = TIMESTAMP_WHITERABBIT(id=0x200);
  do
  {
    if (__buffer.empty()) goto no_match_9;
    int __match_no = 0;
    // optimized match 1: TIMESTAMP_WHITERABBIT wr: (s32) => (0xfffeffff,0x00000200)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1317,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_9;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1316,spurious_match_abort_loop_22,TIMESTAMP_WHITERABBIT,/*id*/0x200);
        UNPACK_DECL(1316,TIMESTAMP_WHITERABBIT,wr,/*id*/0x200);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_22:;
    no_match_9:;
  // select optional

    // stuff = VULOM_TPAT();
  do
  {
    if (__buffer.empty()) goto no_match_10;
    int __match_no = 0;
    // optimized match 1: VULOM_TPAT stuff: (s32) => (0xffff0000,0xf5000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1322,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_10;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1321,spurious_match_abort_loop_23,VULOM_TPAT);
        UNPACK_DECL(1321,VULOM_TPAT,stuff);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_23:;
    no_match_10:;
  // select optional

    // data = TRAVMUS_CRATE_DATA();
  do
  {
    if (__buffer.empty()) goto no_match_11;
    int __match_no = 0;
    // optimized match 1: TRAVMUS_CRATE_DATA data: (s32) => (0xffffff00,0xc0ffee00)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1327,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 1
    }
    if (!__match_no) goto no_match_11;
    switch (__match_no)
    {
      case 1:
        UNPACK_DECL(1326,TRAVMUS_CRATE_DATA,data);
        break;
    }
  }
  while (0);
    no_match_11:;
}
FORCE_IMPL_DATA_SRC_FCN(void,frs_travmus_subev::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for frs_user_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_user_subev)
template<typename __data_src_t>
void frs_user_subev::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_MAGENTA),  "frs_user_subev",CT_OUT(NORM));
  }
  // select several

    // trig3 = TRIG3EVENT();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: TRIG3EVENT trig3: (s32) => (0xffffffff,0x20202020)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1270,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1269,spurious_match_abort_loop_24,TRIG3EVENT);
        UNPACK_DECL(1269,TRIG3EVENT,trig3);
        break;
    }
  }
  spurious_match_abort_loop_24:;
  // select several

    // spill_on = SPILL_ON();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: SPILL_ON spill_on: (s32) => (0xffffffff,0x30303030)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1275,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1274,spurious_match_abort_loop_25,SPILL_ON);
        UNPACK_DECL(1274,SPILL_ON,spill_on);
        break;
    }
  }
  spurious_match_abort_loop_25:;
  // select several

    // spill_off = SPILL_OFF();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: SPILL_OFF spill_off: (s32) => (0xffffffff,0x4040400a)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1280,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1279,spurious_match_abort_loop_26,SPILL_OFF);
        UNPACK_DECL(1279,SPILL_OFF,spill_off);
        break;
    }
  }
  spurious_match_abort_loop_26:;
  // UINT32 sevens NOENCODE
  // {
    //  0_31: 0x77777777;
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
  } sevens;
  READ_FROM_BUFFER_FULL(1285,uint32 ,sevens,sevens.u32,143);
  CHECK_BITS_EQUAL(1284,sevens.unnamed_0_31,0x77777777);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: sevens ", CT_OUT(BOLD), sevens.u32, CT_OUT(NORM));
    printf("\n");
  }
  // select optional

    // data = USER_CRATE_DATA();
  do
  {
    if (__buffer.empty()) goto no_match_12;
    int __match_no = 0;
    // optimized match 1: USER_CRATE_DATA data: could not get bits
    __buffer.peeking();
    MATCH_DECL(1290,__match_no,1,USER_CRATE_DATA,data);
    if (!__match_no) goto no_match_12;
    switch (__match_no)
    {
      case 1:
        UNPACK_DECL(1290,USER_CRATE_DATA,data);
        break;
    }
  }
  while (0);
    no_match_12:;
}
FORCE_IMPL_DATA_SRC_FCN(void,frs_user_subev::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for EVENT.
 *
 * Do not edit - automatically generated.
 */

// EVENT
template<typename __data_src_t>
int unpack_event::__unpack_subevent(subevent_header *__header,__data_src_t &__buffer)
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
  int __match_no = 0;
  MATCH_SUBEVENT_DECL(1333,__match_no,1,((VES10_1_type==10)&&(VES10_1_subtype==1)&&(VES10_1_control==37)&&(VES10_1_procid==90)),aida);
  MATCH_SUBEVENT_DECL(1334,__match_no,2,((VES10_1_type==10)&&(VES10_1_subtype==1)&&(VES10_1_control==20)&&(VES10_1_procid==60)),germanium);
  MATCH_SUBEVENT_DECL(1335,__match_no,3,((VES10_1_type==10)&&(VES10_1_subtype==1)&&(VES10_1_control==20)&&(VES10_1_procid==80)),bplast);
  MATCH_SUBEVENT_DECL(1337,__match_no,4,((VES10_1_procid==10)),frsmain);
  MATCH_SUBEVENT_DECL(1338,__match_no,5,((VES10_1_procid==20)),frstpc);
  MATCH_SUBEVENT_DECL(1339,__match_no,6,((VES10_1_procid==30)),frsuser);
  MATCH_SUBEVENT_DECL(1340,__match_no,7,((VES10_1_procid==15)),frstpat);
  MATCH_SUBEVENT_DECL(1342,__match_no,8,((VES10_1_control==30)&&(VES10_1_procid==35)),frstravmus);
  if (!__match_no) return 0;
  switch (__match_no)
  {
    case 1:
      UNPACK_SUBEVENT_DECL(1333,0,aida_subev,aida);
      break;
    case 2:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1334,febex_subev,germanium,0);
      UNPACK_SUBEVENT_DECL(1334,0,febex_subev,germanium);
      break;
    case 3:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1335,bplast_subev,bplast,1);
      UNPACK_SUBEVENT_DECL(1335,0,bplast_subev,bplast);
      break;
    case 4:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1337,frs_main_subev,frsmain,2);
      UNPACK_SUBEVENT_DECL(1337,0,frs_main_subev,frsmain);
      break;
    case 5:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1338,frs_tpc_subev,frstpc,3);
      UNPACK_SUBEVENT_DECL(1338,0,frs_tpc_subev,frstpc);
      break;
    case 6:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1339,frs_user_subev,frsuser,4);
      UNPACK_SUBEVENT_DECL(1339,0,frs_user_subev,frsuser);
      break;
    case 7:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1340,frs_tpat_subev,frstpat,5);
      UNPACK_SUBEVENT_DECL(1340,0,frs_tpat_subev,frstpat);
      break;
    case 8:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1342,frs_travmus_subev,frstravmus,6);
      UNPACK_SUBEVENT_DECL(1342,0,frs_travmus_subev,frstravmus);
      break;
  }
  return 0;
}
FORCE_IMPL_DATA_SRC_FCN_HDR(int,unpack_event::__unpack_subevent);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for EVENT.
 *
 * Do not edit - automatically generated.
 */

// STICKY_EVENT
template<typename __data_src_t>
int unpack_sticky_event::__unpack_subevent(subevent_header *__header,__data_src_t &__buffer)
{
  int __match_no = 0;
  if (!__match_no) return 0;
  switch (__match_no)
  {
  }
  return 0;
}
FORCE_IMPL_DATA_SRC_FCN_HDR(int,unpack_sticky_event::__unpack_subevent);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER_DEFINES *********************************************
 *
 * Control
 *
 * Do not edit - automatically generated.
 */

#define STICKY_EVENT_IS_NONTRIVIAL  0


/** END_UNPACKER_DEFINES **********************************************/
