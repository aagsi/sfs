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
  READ_FROM_BUFFER_FULL(1163,uint32 ,be,be.u32,0);
  CHECK_BITS_EQUAL(1162,be.b,0xbad00bad);
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
  READ_FROM_BUFFER_FULL(1031,uint32 ,barrier,barrier.u32,2);
  CHECK_BITS_RANGE(1030,barrier.ba,0xf52,0xf58);
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
  uint32  no;READ_FROM_BUFFER(1170,uint32 ,no,4);
}
FORCE_IMPL_DATA_SRC_FCN(void,DUMMY::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for ERR_WORD_SIX.
 *
 * Do not edit - automatically generated.
 */

// ERR_WORD_SIX()
template<typename __data_src_t>
void ERR_WORD_SIX::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "ERR_WORD_SIX",CT_OUT(NORM));
  }
  // UINT32 err NOENCODE
  // {
    //  0_31: err = MATCH(0x06000000);
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 err : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 err : 32; // 0..31
#endif
    };
    uint32  u32;
  } err;
  READ_FROM_BUFFER_FULL(1123,uint32 ,err,err.u32,6);
  CHECK_BITS_EQUAL(1122,err.err,0x06000000);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: err ", CT_OUT(BOLD), err.u32, CT_OUT(NORM));
    printf(".err=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  err.err, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,ERR_WORD_SIX::__unpack);

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
 * Event unpacker for FATIMA_VME_SCALERS.
 *
 * Do not edit - automatically generated.
 */

// FATIMA_VME_SCALERS()
template<typename __data_src_t>
void FATIMA_VME_SCALERS::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "FATIMA_VME_SCALERS",CT_OUT(NORM));
  }
  // MEMBER(DATA32 data[32] ZERO_SUPPRESS);
  // UINT32 sc_header NOENCODE
  // {
    //  0_07: empty1;
    //  8_12: nwords;
    // 13_26: empty2;
    // 27_31: geo = MATCH(15);
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 empty1 : 8; // 0..7
      uint32 nwords : 5; // 8..12
      uint32 empty2 : 14; // 13..26
      uint32 geo : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 geo : 5; // 27..31
      uint32 empty2 : 14; // 13..26
      uint32 nwords : 5; // 8..12
      uint32 empty1 : 8; // 0..7
#endif
    };
    uint32  u32;
  } sc_header;
  READ_FROM_BUFFER_FULL(1137,uint32 ,sc_header,sc_header.u32,8);
  CHECK_BITS_EQUAL(1136,sc_header.geo,15);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: sc_header ", CT_OUT(BOLD), sc_header.u32, CT_OUT(NORM));
    printf(".empty1=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  sc_header.empty1, CT_OUT(NORM));
    printf(".nwords=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  sc_header.nwords, CT_OUT(NORM));
    printf(".empty2=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  sc_header.empty2, CT_OUT(NORM));
    printf(".geo=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  sc_header.geo, CT_OUT(NORM));
    printf("\n");
  }
  // list(0<=index<sc_header.nwords)

  for (uint32 index = 0; index < (uint32) (sc_header.nwords); ++index)
  {
    // UINT32 sc_data NOENCODE
    // {
      //  0_31: value;
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
    } sc_data;
    READ_FROM_BUFFER_FULL(1144,uint32 ,sc_data,sc_data.u32,9);
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: sc_data ", CT_OUT(BOLD), sc_data.u32, CT_OUT(NORM));
      printf(".value=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  sc_data.value, CT_OUT(NORM));
      printf("\n");
    }
    // ENCODE(data[index],(value=sc_data.value));

    {
      typedef __typeof__(*(&(data))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = data.insert_index(1145,index);
      __item.value = sc_data.value;
    }
  }
  // UINT32 scaler_trailer NOENCODE;
  uint32  scaler_trailer;READ_FROM_BUFFER(1148,uint32 ,scaler_trailer,10);
}
FORCE_IMPL_DATA_SRC_FCN(void,FATIMA_VME_SCALERS::__unpack);

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
  READ_FROM_BUFFER_FULL(138,uint32 ,sumchannel,sumchannel.u32,12);
  CHECK_BITS_EQUAL(132,sumchannel.unnamed_0_7,52);
  CHECK_BITS_EQUAL(135,sumchannel.card,card);
  CHECK_BITS_EQUAL(136,sumchannel.unnamed_24_31,255);
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
  READ_FROM_BUFFER_FULL(146,uint32 ,channel_size,channel_size.u32,13);
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
  READ_FROM_BUFFER_FULL(155,uint32 ,event_timestamp_hi,event_timestamp_hi.u32,14);
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
  READ_FROM_BUFFER_FULL(161,uint32 ,event_timestamp_lo,event_timestamp_lo.u32,15);
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
  READ_FROM_BUFFER_FULL(169,uint32 ,hp,hp.u32,16);
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
  READ_FROM_BUFFER_FULL(174,uint32 ,deadbeef,deadbeef.u32,17);
  CHECK_BITS_EQUAL(173,deadbeef.unnamed_0_31,0xdeadbeef);
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
    READ_FROM_BUFFER_FULL(185,uint32 ,channelids,channelids.u32,18);
    CHECK_BITS_EQUAL(181,channelids.unnamed_24_31,240);
    {
      typedef __typeof__(*(&(channel_trigger_time_hi))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = channel_trigger_time_hi.insert_index(184,channelids.channel_id_bits);
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
    READ_FROM_BUFFER_FULL(190,uint32 ,channel_ts,channel_ts.u32,19);
    {
      typedef __typeof__(*(&(channel_trigger_time_lo))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = channel_trigger_time_lo.insert_index(189,channelids.channel_id_bits);
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
    READ_FROM_BUFFER_FULL(202,uint32 ,chan_enrgy,chan_enrgy.u32,20);
    {
      {
        typedef __typeof__(*(&(channel_cfd))) __array_t;
        typedef typename __array_t::item_t __item_t;
        __item_t &__item = channel_cfd.insert_index(198,channelids.channel_id_bits);
        __item.value = chan_enrgy.TSF;
      }
      {
        typedef __typeof__(*(&(channel_energy))) __array_t;
        typedef typename __array_t::item_t __item_t;
        __item_t &__item = channel_energy.insert_index(199,channelids.channel_id_bits);
        __item.value = chan_enrgy.chan_energy;
      }
      {
        typedef __typeof__(*(&(pileup))) __array_t;
        typedef typename __array_t::item_t __item_t;
        __item_t &__item = pileup.insert_index(200,channelids.channel_id_bits);
        __item.value = chan_enrgy.pileup_flag;
      }
      {
        typedef __typeof__(*(&(overflow))) __array_t;
        typedef typename __array_t::item_t __item_t;
        __item_t &__item = overflow.insert_index(201,channelids.channel_id_bits);
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
    READ_FROM_BUFFER_FULL(206,uint32 ,future_use,future_use.u32,21);
    CHECK_BITS_EQUAL(205,future_use.unnamed_0_31,0);
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
  READ_FROM_BUFFER_FULL(223,uint32 ,header,header.u32,23);
  CHECK_BITS_EQUAL(217,header.unnamed_0_7,52);
  CHECK_BITS_EQUAL(219,header.board,board);
  CHECK_UNNAMED_BITS_ZERO(223,header.u32,0x00f00000);
  {
    typedef __typeof__(*(&(channel_id_traces))) __array_t;
    typedef typename __array_t::item_t __item_t;
    __item_t &__item = channel_id_traces.insert_index(221,header.ch_id);
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
  READ_FROM_BUFFER_FULL(228,uint32 ,tracesize,tracesize.u32,24);
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
  READ_FROM_BUFFER_FULL(234,uint32 ,tracehead,tracehead.u32,25);
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
    READ_FROM_BUFFER_FULL(254,uint32 ,channel_trace,channel_trace.u32,26);
    {
      {
        typedef __typeof__(*(&(traces[header.ch_id]))) __array_t;
        typedef typename __array_t::item_t __item_t;
        __item_t &__item = traces[header.ch_id].insert_index(252,((2 * j) + 0));
        __item.value = channel_trace.data1;
      }
      {
        typedef __typeof__(*(&(traces[header.ch_id]))) __array_t;
        typedef typename __array_t::item_t __item_t;
        __item_t &__item = traces[header.ch_id].insert_index(253,((2 * j) + 1));
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
  READ_FROM_BUFFER_FULL(263,uint32 ,trace_trailer,trace_trailer.u32,27);
  CHECK_BITS_RANGE(262,trace_trailer.id,176,191);
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
  READ_FROM_BUFFER_FULL(300,uint32 ,sumchannel,sumchannel.u32,29);
  CHECK_BITS_EQUAL(293,sumchannel.unnamed_0_7,52);
  CHECK_BITS_EQUAL(296,sumchannel.board_id,card);
  CHECK_BITS_EQUAL(297,sumchannel.unnamed_24_31,255);
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
  READ_FROM_BUFFER_FULL(310,uint32 ,channel_size,channel_size.u32,30);
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
  READ_FROM_BUFFER_FULL(319,uint32 ,event_timestamp_hi,event_timestamp_hi.u32,31);
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
  READ_FROM_BUFFER_FULL(325,uint32 ,event_timestamp_lo,event_timestamp_lo.u32,32);
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
  READ_FROM_BUFFER_FULL(333,uint32 ,hp,hp.u32,33);
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
  READ_FROM_BUFFER_FULL(338,uint32 ,deadbeef,deadbeef.u32,34);
  CHECK_BITS_EQUAL(337,deadbeef.unnamed_0_31,0xdeadbeef);
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
      READ_FROM_BUFFER_FULL(352,uint32 ,channelids,channelids.u32,35);
      CHECK_BITS_EQUAL(348,channelids.unnamed_24_31,240);
      {
        {
          typedef __typeof__(*(&(channel_id))) __array_t;
          typedef typename __array_t::item_t __item_t;
          __item_t &__item = channel_id.insert_index(350,index);
          __item.value = channelids.channel_id_bits;
        }
        {
          typedef __typeof__(*(&(channel_trigger_time_hi))) __array_t;
          typedef typename __array_t::item_t __item_t;
          __item_t &__item = channel_trigger_time_hi.insert_index(351,index);
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
      READ_FROM_BUFFER_FULL(357,uint32 ,channel_ts,channel_ts.u32,36);
      {
        typedef __typeof__(*(&(channel_trigger_time_lo))) __array_t;
        typedef typename __array_t::item_t __item_t;
        __item_t &__item = channel_trigger_time_lo.insert_index(356,index);
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
      READ_FROM_BUFFER_FULL(369,uint32 ,chan_enrgy,chan_enrgy.u32,37);
      {
        {
          typedef __typeof__(*(&(channel_cfd))) __array_t;
          typedef typename __array_t::item_t __item_t;
          __item_t &__item = channel_cfd.insert_index(365,index);
          __item.value = chan_enrgy.TSF;
        }
        {
          typedef __typeof__(*(&(channel_energy))) __array_t;
          typedef typename __array_t::item_t __item_t;
          __item_t &__item = channel_energy.insert_index(366,index);
          __item.value = chan_enrgy.chan_energy;
        }
        {
          typedef __typeof__(*(&(pileup))) __array_t;
          typedef typename __array_t::item_t __item_t;
          __item_t &__item = pileup.insert_index(367,index);
          __item.value = chan_enrgy.pileup_flag;
        }
        {
          typedef __typeof__(*(&(overflow))) __array_t;
          typedef typename __array_t::item_t __item_t;
          __item_t &__item = overflow.insert_index(368,index);
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
      READ_FROM_BUFFER_FULL(373,uint32 ,future_use,future_use.u32,38);
      CHECK_BITS_EQUAL(372,future_use.unnamed_0_31,0);
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
        PEEK_FROM_BUFFER(386,uint32,__match_peek);
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
            CHECK_SPURIOUS_MATCH_DECL(385,spurious_match_abort_loop_0,TRACE,/*board*/card);
            UNPACK_DECL(385,TRACE,trace,/*board*/card);
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
      READ_FROM_BUFFER(397,uint32 ,dummy,39);
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
  READ_FROM_BUFFER_FULL(112,uint32 ,pads_data,pads_data.u32,41);
  CHECK_BITS_EQUAL(111,pads_data.unnamed_20_31,0xadd);
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
  READ_FROM_BUFFER_FULL(916,uint32 ,header,header.u32,43);
  CHECK_BITS_EQUAL(914,header.unnamed_26_26,1);
  CHECK_BITS_EQUAL(915,header.geom,geom);
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
    READ_FROM_BUFFER_FULL(927,uint32 ,ch_data,ch_data.u32,44);
    CHECK_BITS_EQUAL(923,ch_data.unnamed_26_26,0);
    {
      typedef __typeof__(*(&(data))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = data.insert_index(926,ch_data.channel);
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
  READ_FROM_BUFFER_FULL(1039,uint32 ,filler,filler.u32,46);
  CHECK_BITS_EQUAL(1038,filler.zero,0);
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
  READ_FROM_BUFFER_FULL(947,uint32 ,header,header.u32,48);
  CHECK_BITS_EQUAL(945,header.unnamed_24_26,2);
  CHECK_BITS_EQUAL(946,header.geom,geom);
  CHECK_UNNAMED_BITS_ZERO(947,header.u32,0x0000c000);
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
    READ_FROM_BUFFER_FULL(965,uint32 ,ch_data,ch_data.u32,49);
    CHECK_BITS_EQUAL(960,ch_data.unnamed_24_26,0);
    {
      typedef __typeof__(*(&(data))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = data.insert_index(964,ch_data.channel);
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
  READ_FROM_BUFFER_FULL(973,uint32 ,eob,eob.u32,50);
  CHECK_BITS_EQUAL(971,eob.unnamed_24_26,4);
  CHECK_BITS_EQUAL(972,eob.id,geom);
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
    PEEK_FROM_BUFFER_FULL(982,uint32 ,eob2,eob2.u32,51);
    CHECK_JUMP_BITS_EQUAL(980,eob2.id,6,data_done_1);
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
  READ_FROM_BUFFER_FULL(741,uint32 ,tdc_header,tdc_header.u32,53);
  CHECK_BITS_EQUAL(740,tdc_header.unnamed_27_31,1);
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
  READ_FROM_BUFFER_FULL(758,uint32 ,tdc_data,tdc_data.u32,55);
  CHECK_BITS_EQUAL(754,tdc_data.unnamed_27_31,0);
  {
    {
      typedef __typeof__(*(&(data))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = data.insert_index(756,tdc_data.chn);
      __item.value = tdc_data.tdc;
    }
    {
      typedef __typeof__(*(&(leadOrTrail))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = leadOrTrail.insert_index(757,tdc_data.chn);
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
  READ_FROM_BUFFER_FULL(787,uint32 ,tdc_err,tdc_err.u32,57);
  CHECK_BITS_EQUAL(786,tdc_err.unnamed_27_31,4);
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
  READ_FROM_BUFFER_FULL(799,uint32 ,tdc_trailer,tdc_trailer.u32,59);
  CHECK_BITS_EQUAL(798,tdc_trailer.unnamed_27_31,3);
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
  READ_FROM_BUFFER_FULL(813,uint32 ,header,header.u32,61);
  CHECK_BITS_EQUAL(810,header.type,8);
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
    PEEK_FROM_BUFFER(821,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(817,spurious_match_abort_loop_1,TDC_HEADER);
        UNPACK_DECL(817,TDC_HEADER,tdc_header);
        break;
      case 2:
        CHECK_SPURIOUS_MATCH_DECL(818,spurious_match_abort_loop_1,TDC_DATA_V1290);
        UNPACK_DECL(818,TDC_DATA_V1290,measurement);
        break;
      case 3:
        CHECK_SPURIOUS_MATCH_DECL(819,spurious_match_abort_loop_1,TDC_ERROR);
        UNPACK_DECL(819,TDC_ERROR,tdc_err);
        break;
      case 4:
        CHECK_SPURIOUS_MATCH_DECL(820,spurious_match_abort_loop_1,TDC_TRAILER);
        UNPACK_DECL(820,TDC_TRAILER,tdc_trailer);
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
  PEEK_FROM_BUFFER_FULL(828,uint32 ,ext_time_tag,ext_time_tag.u32,62);
  CHECK_JUMP_BITS_EQUAL(827,ext_time_tag.unnamed_27_31,17,data_done_2);
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
  READ_FROM_BUFFER_FULL(839,uint32 ,trailer,trailer.u32,63);
  CHECK_BITS_EQUAL(838,trailer.unnamed_27_31,16);
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
  UNPACK_DECL(1065,BARRIER,barrier0);
  // v830 = VME_CAEN_V830(geom=8);
  UNPACK_DECL(1066,VME_CAEN_V830,v830,/*geom*/8);
  // filler0 = ZERO_FILLER();
  UNPACK_DECL(1068,ZERO_FILLER,filler0);
  // barrier1 = BARRIER();
  UNPACK_DECL(1070,BARRIER,barrier1);
  // v792 = VME_CAEN_V7X5(geom=14);
  UNPACK_DECL(1071,VME_CAEN_V7X5,v792,/*geom*/14);
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
  READ_FROM_BUFFER_FULL(1073,uint32 ,aaahhh,aaahhh.u32,65);
  CHECK_BITS_EQUAL(1073,aaahhh.unnamed_0_31,0xaaaa1290);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: aaahhh ", CT_OUT(BOLD), aaahhh.u32, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 exxxxx NOENCODE;
  uint32  exxxxx;READ_FROM_BUFFER(1074,uint32 ,exxxxx,66);
  // barrier2 = BARRIER();
  UNPACK_DECL(1076,BARRIER,barrier2);
  // v1290 = VME_CAEN_V1290_N();
  UNPACK_DECL(1077,VME_CAEN_V1290_N,v1290);
  // optional UINT32 eodb NOENCODE;
  uint32  eodb;if (__buffer.empty()) goto data_done_3;
  READ_FROM_BUFFER(1078,uint32 ,eodb,67);
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
  READ_FROM_BUFFER_FULL(1012,uint32 ,off1,off1.u32,68);
  CHECK_BITS_EQUAL(1011,off1.unnamed_0_31,0x4040400a);
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
  READ_FROM_BUFFER_FULL(1016,uint32 ,off2,off2.u32,69);
  CHECK_BITS_EQUAL(1015,off2.unnamed_0_31,0x4040400b);
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
  READ_FROM_BUFFER_FULL(1020,uint32 ,off3,off3.u32,70);
  CHECK_BITS_EQUAL(1019,off3.unnamed_0_31,0x4040400c);
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
  READ_FROM_BUFFER_FULL(1001,uint32 ,on,on.u32,72);
  CHECK_BITS_EQUAL(1000,on.unnamed_0_31,0x30303030);
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
  READ_FROM_BUFFER_FULL(474,uint32 ,data,data.u32,74);
  CHECK_BITS_EQUAL(467,data.unnamed_28_31,6);
  {
    {
      typedef __typeof__(*(&(time_coarse))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_coarse.append_item(469);
      __item.value = 0;
    }
    {
      typedef __typeof__(*(&(time_fine))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_fine.append_item(470);
      __item.value = 0;
    }
    {
      typedef __typeof__(*(&(time_edge))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_edge.append_item(471);
      __item.value = 0;
    }
    {
      typedef __typeof__(*(&(time_channel))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_channel.append_item(472);
      __item.value = 0;
    }
    {
      typedef __typeof__(*(&(time_epoch))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_epoch.append_item(473);
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
  READ_FROM_BUFFER_FULL(416,uint32 ,trigger_window,trigger_window.u32,76);
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
  READ_FROM_BUFFER_FULL(427,uint32 ,padding,padding.u32,78);
  CHECK_BITS_EQUAL(426,padding.unnamed_20_31,0xadd);
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
  READ_FROM_BUFFER_FULL(452,uint32 ,data,data.u32,80);
  CHECK_BITS_EQUAL(445,data.type,8);
  {
    {
      typedef __typeof__(*(&(time_coarse))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_coarse.append_item(447);
      __item.value = data.coarse;
    }
    {
      typedef __typeof__(*(&(time_fine))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_fine.append_item(448);
      __item.value = data.fine;
    }
    {
      typedef __typeof__(*(&(time_edge))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_edge.append_item(449);
      __item.value = data.is_leading;
    }
    {
      typedef __typeof__(*(&(time_channel))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_channel.append_item(450);
      __item.value = data.channel;
    }
    {
      typedef __typeof__(*(&(time_epoch))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = time_epoch.append_item(451);
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
  READ_FROM_BUFFER_FULL(496,uint32 ,indicator,indicator.u32,82);
  CHECK_BITS_EQUAL(490,indicator.unnamed_0_7,52);
  CHECK_BITS_EQUAL(492,indicator.sfp,sfp);
  CHECK_BITS_EQUAL(493,indicator.card,card);
  CHECK_BITS_EQUAL(494,indicator.unnamed_24_31,0);
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
  READ_FROM_BUFFER_FULL(506,uint32 ,data_size,data_size.u32,83);
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
  READ_FROM_BUFFER_FULL(515,uint32 ,tdc_header,tdc_header.u32,84);
  CHECK_BITS_EQUAL(513,tdc_header.unnamed_24_31,170);
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
      PEEK_FROM_BUFFER(523,uint32,__match_peek);
      // differ = e0000000 : 29 30 31
      uint32 __match_index = 0 | /* 29,31 */ ((__match_peek >> 29) & 0x00000007);
      static const sint8 __match_index_array[8] = { 0, 0, 0, 1, 2, 0, 0, 0, };
      __match_no = __match_index_array[__match_index];
      // last_subevent_item = 0
      }
      if (!__match_no) ERROR_U_LOC(523,"No match for select statement.");
      switch (__match_no)
      {
        case 1:
          CHECK_SPURIOUS_MATCH_DECL(521,spurious_match_abort_loop_2,TAMEX4_EPOCH_DATA,/*sfp*/sfp,/*card*/card/*,time_coarse:member*//*,time_fine:member*//*,time_edge:member*//*,time_channel:member*//*,time_epoch:member*/);
          UNPACK_DECL(521,TAMEX4_EPOCH_DATA,epoch,/*sfp*/sfp,/*card*/card,/*time_coarse*/time_coarse,/*time_fine*/time_fine,/*time_edge*/time_edge,/*time_channel*/time_channel,/*time_epoch*/time_epoch);
          break;
        case 2:
          CHECK_SPURIOUS_MATCH_DECL(522,spurious_match_abort_loop_2,TAMEX4_TIME_DATA,/*sfp*/sfp,/*card*/card/*,time_coarse:member*//*,time_fine:member*//*,time_edge:member*//*,time_channel:member*//*,time_epoch:member*/);
          UNPACK_DECL(522,TAMEX4_TIME_DATA,time,/*sfp*/sfp,/*card*/card,/*time_coarse*/time_coarse,/*time_fine*/time_fine,/*time_edge*/time_edge,/*time_channel*/time_channel,/*time_epoch*/time_epoch);
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
  READ_FROM_BUFFER_FULL(530,uint32 ,error_bits,error_bits.u32,85);
  CHECK_BITS_EQUAL(529,error_bits.unnamed_24_31,238);
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
  READ_FROM_BUFFER_FULL(539,uint32 ,trailer,trailer.u32,86);
  CHECK_BITS_EQUAL(538,trailer.unnamed_24_31,187);
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
  READ_FROM_BUFFER_FULL(775,uint32 ,tdc_data,tdc_data.u32,88);
  CHECK_BITS_EQUAL(771,tdc_data.unnamed_27_31,0);
  {
    {
      typedef __typeof__(*(&(data))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = data.insert_index(773,tdc_data.chn);
      __item.value = tdc_data.tdc;
    }
    {
      typedef __typeof__(*(&(leadOrTrail))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = leadOrTrail.insert_index(774,tdc_data.chn);
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
  READ_FROM_BUFFER_FULL(25,uint32 ,header,header.u32,90);
  CHECK_BITS_EQUAL(20,header.id,id);
  CHECK_BITS_EQUAL(21,header.unnamed_12_15,0);
  CHECK_BITS_EQUAL(23,header.unnamed_17_31,0);
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
  READ_FROM_BUFFER_FULL(30,uint32 ,d1,d1.u32,91);
  CHECK_BITS_EQUAL(28,d1.unnamed_16_31,0x3e1);
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
  READ_FROM_BUFFER_FULL(35,uint32 ,d2,d2.u32,92);
  CHECK_BITS_EQUAL(33,d2.unnamed_16_31,0x4e1);
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
  READ_FROM_BUFFER_FULL(40,uint32 ,d3,d3.u32,93);
  CHECK_BITS_EQUAL(38,d3.unnamed_16_31,0x5e1);
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
  READ_FROM_BUFFER_FULL(45,uint32 ,d4,d4.u32,94);
  CHECK_BITS_EQUAL(43,d4.unnamed_16_31,0x6e1);
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
  READ_FROM_BUFFER_FULL(62,uint32 ,header,header.u32,96);
  CHECK_BITS_EQUAL(57,header.id,id);
  CHECK_BITS_EQUAL(58,header.unnamed_13_15,0);
  CHECK_BITS_EQUAL(60,header.unnamed_17_31,0);
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
  READ_FROM_BUFFER_FULL(67,uint32 ,d1,d1.u32,97);
  CHECK_BITS_EQUAL(65,d1.unnamed_16_31,0x3e1);
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
  READ_FROM_BUFFER_FULL(72,uint32 ,d2,d2.u32,98);
  CHECK_BITS_EQUAL(70,d2.unnamed_16_31,0x4e1);
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
  READ_FROM_BUFFER_FULL(77,uint32 ,d3,d3.u32,99);
  CHECK_BITS_EQUAL(75,d3.unnamed_16_31,0x5e1);
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
  READ_FROM_BUFFER_FULL(82,uint32 ,d4,d4.u32,100);
  CHECK_BITS_EQUAL(80,d4.unnamed_16_31,0x6e1);
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
  READ_FROM_BUFFER(1048,uint32 ,w1,102);
  // UINT32 w2;
  READ_FROM_BUFFER(1049,uint32 ,w2,103);
  // UINT32 w3;
  READ_FROM_BUFFER(1050,uint32 ,w3,104);
  // UINT32 trigger_pattern
  // {
    //  0_15: pattern;
    // 16_31: nothing;
    // ENCODE(tpat,(value=pattern));
  // }
  READ_FROM_BUFFER_FULL(1057,uint32 ,trigger_pattern,trigger_pattern.u32,105);
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
  READ_FROM_BUFFER_FULL(854,uint32 ,header,header.u32,107);
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
    READ_FROM_BUFFER_FULL(862,uint32 ,second1,second1.u32,108);
    CHECK_BITS_EQUAL(861,second1.unnamed_0_31,0xffffffff);
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
    READ_FROM_BUFFER_FULL(869,uint32 ,real_header,real_header.u32,109);
    CHECK_BITS_EQUAL(868,real_header.unnamed_27_31,8);
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
    PEEK_FROM_BUFFER(878,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(874,spurious_match_abort_loop_3,TDC_HEADER);
        UNPACK_DECL(874,TDC_HEADER,tdc_header);
        break;
      case 2:
        CHECK_SPURIOUS_MATCH_DECL(875,spurious_match_abort_loop_3,TDC_DATA_V1190);
        UNPACK_DECL(875,TDC_DATA_V1190,measurement);
        break;
      case 3:
        CHECK_SPURIOUS_MATCH_DECL(876,spurious_match_abort_loop_3,TDC_ERROR);
        UNPACK_DECL(876,TDC_ERROR,tdc_error);
        break;
      case 4:
        CHECK_SPURIOUS_MATCH_DECL(877,spurious_match_abort_loop_3,TDC_TRAILER);
        UNPACK_DECL(877,TDC_TRAILER,tdc_trailer);
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
  if (__buffer.empty()) goto data_done_4;
  PEEK_FROM_BUFFER_FULL(885,uint32 ,ext_time_tag,ext_time_tag.u32,110);
  CHECK_JUMP_BITS_EQUAL(884,ext_time_tag.unnamed_27_31,17,data_done_4);
  __buffer.advance(sizeof(ext_time_tag.u32));
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: ext_time_tag ", CT_OUT(BOLD), ext_time_tag.u32, CT_OUT(NORM));
    printf(".time_tag=%s%7" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  ext_time_tag.time_tag, CT_OUT(NORM));
    printf("\n");
  }
  data_done_4:;
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
  READ_FROM_BUFFER_FULL(897,uint32 ,trailer,trailer.u32,111);
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
  uint32  eob;if (__buffer.empty()) goto data_done_5;
  READ_FROM_BUFFER(899,uint32 ,eob,112);
  data_done_5:;
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
    PEEK_FROM_BUFFER(1090,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1087,spurious_match_abort_loop_4,BARRIER);
        UNPACK_DECL(1087,BARRIER,barrier0);
        break;
      case 2:
        CHECK_SPURIOUS_MATCH_DECL(1088,spurious_match_abort_loop_4,VME_CAEN_V7X5,/*geom*/8);
        UNPACK_DECL(1088,VME_CAEN_V7X5,v785,/*geom*/8);
        break;
      case 3:
        CHECK_SPURIOUS_MATCH_DECL(1089,spurious_match_abort_loop_4,VME_CAEN_V7X5,/*geom*/12);
        UNPACK_DECL(1089,VME_CAEN_V7X5,v775,/*geom*/12);
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
  READ_FROM_BUFFER_FULL(1092,uint32 ,aaahhh,aaahhh.u32,114);
  CHECK_BITS_EQUAL(1092,aaahhh.unnamed_0_31,0xaaaa1190);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: aaahhh ", CT_OUT(BOLD), aaahhh.u32, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 exxxxx NOENCODE;
  uint32  exxxxx;READ_FROM_BUFFER(1093,uint32 ,exxxxx,115);
  // barrier[2] = BARRIER();
  UNPACK_DECL(1095,BARRIER,barrier[2]);
  // v1190 = VME_CAEN_V1190_N();
  UNPACK_DECL(1096,VME_CAEN_V1190_N,v1190);
}
FORCE_IMPL_DATA_SRC_FCN(void,TPC_CRATE_DATA::__unpack);

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
  READ_FROM_BUFFER_FULL(992,uint32 ,trig3,trig3.u32,116);
  CHECK_BITS_EQUAL(991,trig3.unnamed_0_31,0x20202020);
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
  UNPACK_DECL(1102,BARRIER,barrier0);
  // v830 = VME_CAEN_V830(geom=6);
  UNPACK_DECL(1103,VME_CAEN_V830,v830,/*geom*/6);
  // filler0 = ZERO_FILLER();
  UNPACK_DECL(1105,ZERO_FILLER,filler0);
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
    PEEK_FROM_BUFFER(1114,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1109,spurious_match_abort_loop_5,BARRIER);
        UNPACK_DECL(1109,BARRIER,barrier1);
        break;
      case 2:
        CHECK_SPURIOUS_MATCH_DECL(1110,spurious_match_abort_loop_5,VME_CAEN_V7X5,/*geom*/8);
        UNPACK_DECL(1110,VME_CAEN_V7X5,v775[0],/*geom*/8);
        break;
      case 3:
        CHECK_SPURIOUS_MATCH_DECL(1111,spurious_match_abort_loop_5,VME_CAEN_V7X5,/*geom*/9);
        UNPACK_DECL(1111,VME_CAEN_V7X5,v775[1],/*geom*/9);
        break;
      case 4:
        CHECK_SPURIOUS_MATCH_DECL(1112,spurious_match_abort_loop_5,VME_CAEN_V7X5,/*geom*/10);
        UNPACK_DECL(1112,VME_CAEN_V7X5,v785[0],/*geom*/10);
        break;
      case 5:
        CHECK_SPURIOUS_MATCH_DECL(1113,spurious_match_abort_loop_5,VME_CAEN_V7X5,/*geom*/12);
        UNPACK_DECL(1113,VME_CAEN_V7X5,v785[1],/*geom*/12);
        break;
    }
  }
  spurious_match_abort_loop_5:;
}
FORCE_IMPL_DATA_SRC_FCN(void,USER_CRATE_DATA::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for VME_CAEN_V1751.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V1751(board)
template<typename __data_src_t>
void VME_CAEN_V1751::__unpack(__data_src_t &__buffer,uint32 board)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_BLUE),  "VME_CAEN_V1751",CT_OUT(NORM));
  }
  // MEMBER(DATA8 board_id);
  // MEMBER(DATA8 channels);
  // MEMBER(DATA32 board_time);
  // MEMBER(DATA32 channel_time[64] NO_INDEX_LIST);
  // MEMBER(DATA16 chan_ext_time[64] NO_INDEX_LIST);
  // MEMBER(DATA12 chan_fine_time[64] NO_INDEX_LIST);
  // MEMBER(DATA16 qshort[64] NO_INDEX_LIST);
  // MEMBER(DATA16 qlong[64] NO_INDEX_LIST);
  // UINT32 board_agg_size NOENCODE
  // {
    //  0_27: event_size;
    // 28_31: 10;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 event_size : 28; // 0..27
      uint32 unnamed_28_31 : 4; // 28..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 unnamed_28_31 : 4; // 28..31
      uint32 event_size : 28; // 0..27
#endif
    };
    uint32  u32;
  } board_agg_size;
  READ_FROM_BUFFER_FULL(559,uint32 ,board_agg_size,board_agg_size.u32,118);
  CHECK_BITS_EQUAL(558,board_agg_size.unnamed_28_31,10);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: board_agg_size ", CT_OUT(BOLD), board_agg_size.u32, CT_OUT(NORM));
    printf(".event_size=%s%7" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  board_agg_size.event_size, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 board_details NOENCODE
  // {
    //  0_07: channels;
    //  8_23: pattern;
    // 24_25: empty;
    //    26: board_fail;
    // 27_31: id = MATCH(board);
    // ENCODE(channels,(value=channels));
    // ENCODE(board_id,(value=id));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 channels : 8; // 0..7
      uint32 pattern : 16; // 8..23
      uint32 empty : 2; // 24..25
      uint32 board_fail : 1; // 26
      uint32 id : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 id : 5; // 27..31
      uint32 board_fail : 1; // 26
      uint32 empty : 2; // 24..25
      uint32 pattern : 16; // 8..23
      uint32 channels : 8; // 0..7
#endif
    };
    uint32  u32;
  } board_details;
  READ_FROM_BUFFER_FULL(570,uint32 ,board_details,board_details.u32,119);
  CHECK_BITS_EQUAL(567,board_details.id,board);
  {
    {
      channels.value = board_details.channels;
    }
    {
      board_id.value = board_details.id;
    }
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: board_details ", CT_OUT(BOLD), board_details.u32, CT_OUT(NORM));
    printf(".channels=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  board_details.channels, CT_OUT(NORM));
    printf(".pattern=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  board_details.pattern, CT_OUT(NORM));
    printf(".empty=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  board_details.empty, CT_OUT(NORM));
    printf(".board_fail=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  board_details.board_fail, CT_OUT(NORM));
    printf(".id=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  board_details.id, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 board_agg_counter NOENCODE
  // {
    //  0_22: counter;
    // 23_31: empty;
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 counter : 23; // 0..22
      uint32 empty : 9; // 23..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 empty : 9; // 23..31
      uint32 counter : 23; // 0..22
#endif
    };
    uint32  u32;
  } board_agg_counter;
  READ_FROM_BUFFER_FULL(576,uint32 ,board_agg_counter,board_agg_counter.u32,120);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: board_agg_counter ", CT_OUT(BOLD), board_agg_counter.u32, CT_OUT(NORM));
    printf(".counter=%s%6" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  board_agg_counter.counter, CT_OUT(NORM));
    printf(".empty=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  board_agg_counter.empty, CT_OUT(NORM));
    printf("\n");
  }
  // UINT32 board_agg_timetag NOENCODE
  // {
    //  0_31: time_tag;
    // ENCODE(board_time,(value=time_tag));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 time_tag : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 time_tag : 32; // 0..31
#endif
    };
    uint32  u32;
  } board_agg_timetag;
  READ_FROM_BUFFER_FULL(582,uint32 ,board_agg_timetag,board_agg_timetag.u32,121);
  {
    board_time.value = board_agg_timetag.time_tag;
  }
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: board_agg_timetag ", CT_OUT(BOLD), board_agg_timetag.u32, CT_OUT(NORM));
    printf(".time_tag=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  board_agg_timetag.time_tag, CT_OUT(NORM));
    printf("\n");
  }
  // if((board_agg_size.event_size > 4))

  if ((board_agg_size.event_size > 4))
  {
    // list(0<=index<((board_agg_size.event_size - 4) / 6))

    for (uint32 index = 0; index < (uint32) (((board_agg_size.event_size - 4) / 6)); ++index)
    {
      // UINT32 channel_agg_size NOENCODE
      // {
        //  0_21: size;
        // 22_27: empty;
        // 28_31: format;
      // }
      union
      {
        struct
        {
#if __BYTE_ORDER == __LITTLE_ENDIAN
          uint32 size : 22; // 0..21
          uint32 empty : 6; // 22..27
          uint32 format : 4; // 28..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
          uint32 format : 4; // 28..31
          uint32 empty : 6; // 22..27
          uint32 size : 22; // 0..21
#endif
        };
        uint32  u32;
      } channel_agg_size;
      READ_FROM_BUFFER_FULL(600,uint32 ,channel_agg_size,channel_agg_size.u32,122);
      if (__buffer.is_memberdump())
      {
        printf("%s%08" PRIx32 "%s: channel_agg_size ", CT_OUT(BOLD), channel_agg_size.u32, CT_OUT(NORM));
        printf(".size=%s%6" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channel_agg_size.size, CT_OUT(NORM));
        printf(".empty=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channel_agg_size.empty, CT_OUT(NORM));
        printf(".format=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channel_agg_size.format, CT_OUT(NORM));
        printf("\n");
      }
      // UINT32 format_one NOENCODE
      // {
        //  0_15: no_wave_samples;
        // 16_17: empty;
        //    18: ed;
        // 19_21: dp1;
        // 22_24: dp2;
        // 25_26: ap;
        //    27: es;
        //    28: ee;
        //    29: et;
        //    30: eq;
        //    31: dt;
      // }
      union
      {
        struct
        {
#if __BYTE_ORDER == __LITTLE_ENDIAN
          uint32 no_wave_samples : 16; // 0..15
          uint32 empty : 2; // 16..17
          uint32 ed : 1; // 18
          uint32 dp1 : 3; // 19..21
          uint32 dp2 : 3; // 22..24
          uint32 ap : 2; // 25..26
          uint32 es : 1; // 27
          uint32 ee : 1; // 28
          uint32 et : 1; // 29
          uint32 eq : 1; // 30
          uint32 dt : 1; // 31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
          uint32 dt : 1; // 31
          uint32 eq : 1; // 30
          uint32 et : 1; // 29
          uint32 ee : 1; // 28
          uint32 es : 1; // 27
          uint32 ap : 2; // 25..26
          uint32 dp2 : 3; // 22..24
          uint32 dp1 : 3; // 19..21
          uint32 ed : 1; // 18
          uint32 empty : 2; // 16..17
          uint32 no_wave_samples : 16; // 0..15
#endif
        };
        uint32  u32;
      } format_one;
      READ_FROM_BUFFER_FULL(615,uint32 ,format_one,format_one.u32,123);
      if (__buffer.is_memberdump())
      {
        printf("%s%08" PRIx32 "%s: format_one ", CT_OUT(BOLD), format_one.u32, CT_OUT(NORM));
        printf(".no_wave_samples=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  format_one.no_wave_samples, CT_OUT(NORM));
        printf(".empty=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  format_one.empty, CT_OUT(NORM));
        printf(".ed=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  format_one.ed, CT_OUT(NORM));
        printf(".dp1=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  format_one.dp1, CT_OUT(NORM));
        printf(".dp2=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  format_one.dp2, CT_OUT(NORM));
        printf(".ap=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  format_one.ap, CT_OUT(NORM));
        printf(".es=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  format_one.es, CT_OUT(NORM));
        printf(".ee=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  format_one.ee, CT_OUT(NORM));
        printf(".et=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  format_one.et, CT_OUT(NORM));
        printf(".eq=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  format_one.eq, CT_OUT(NORM));
        printf(".dt=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  format_one.dt, CT_OUT(NORM));
        printf("\n");
      }
      // if((channel_agg_size.format == 4))

      // else

      if ((channel_agg_size.format == 4))
      {
        // UINT32 format_two NOENCODE
        // {
          //  0_02: ex;
          //     3: pp;
          //     4: dm;
          //  5_07: interp;
          //  8_31: empty;
        // }
        union
        {
          struct
          {
#if __BYTE_ORDER == __LITTLE_ENDIAN
            uint32 ex : 3; // 0..2
            uint32 pp : 1; // 3
            uint32 dm : 1; // 4
            uint32 interp : 3; // 5..7
            uint32 empty : 24; // 8..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
            uint32 empty : 24; // 8..31
            uint32 interp : 3; // 5..7
            uint32 dm : 1; // 4
            uint32 pp : 1; // 3
            uint32 ex : 3; // 0..2
#endif
          };
          uint32  u32;
        } format_two;
        READ_FROM_BUFFER_FULL(626,uint32 ,format_two,format_two.u32,124);
        if (__buffer.is_memberdump())
        {
          printf("%s%08" PRIx32 "%s: format_two ", CT_OUT(BOLD), format_two.u32, CT_OUT(NORM));
          printf(".ex=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  format_two.ex, CT_OUT(NORM));
          printf(".pp=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  format_two.pp, CT_OUT(NORM));
          printf(".dm=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  format_two.dm, CT_OUT(NORM));
          printf(".interp=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  format_two.interp, CT_OUT(NORM));
          printf(".empty=%s%6" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  format_two.empty, CT_OUT(NORM));
          printf("\n");
        }
        // if((format_one.et == 1))

        if ((format_one.et == 1))
        {
          // UINT32 channel_time_tag NOENCODE
          // {
            //  0_31: time_tag;
            // ENCODE(channel_time APPEND_LIST,(value=time_tag));
          // }
          union
          {
            struct
            {
#if __BYTE_ORDER == __LITTLE_ENDIAN
              uint32 time_tag : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
              uint32 time_tag : 32; // 0..31
#endif
            };
            uint32  u32;
          } channel_time_tag;
          READ_FROM_BUFFER_FULL(634,uint32 ,channel_time_tag,channel_time_tag.u32,125);
          {
            typedef __typeof__(*(&(channel_time))) __array_t;
            typedef typename __array_t::item_t __item_t;
            __item_t &__item = channel_time.append_item(633);
            __item.value = channel_time_tag.time_tag;
          }
          if (__buffer.is_memberdump())
          {
            printf("%s%08" PRIx32 "%s: channel_time_tag ", CT_OUT(BOLD), channel_time_tag.u32, CT_OUT(NORM));
            printf(".time_tag=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channel_time_tag.time_tag, CT_OUT(NORM));
            printf("\n");
          }
        }
        // if(((format_one.ee == 1) && (channel_agg_size.format == 4)))

        if (((format_one.ee == 1) && (channel_agg_size.format == 4)))
        {
          // if((format_two.ex == 0))

          // else

          if ((format_two.ex == 0))
          {
            // UINT32 extras NOENCODE
            // {
              //  0_15: baseline;
              // 16_31: ext_time;
              // ENCODE(chan_ext_time APPEND_LIST,(value=ext_time));
            // }
            union
            {
              struct
              {
#if __BYTE_ORDER == __LITTLE_ENDIAN
                uint32 baseline : 16; // 0..15
                uint32 ext_time : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
                uint32 ext_time : 16; // 16..31
                uint32 baseline : 16; // 0..15
#endif
              };
              uint32  u32;
            } extras;
            READ_FROM_BUFFER_FULL(648,uint32 ,extras,extras.u32,126);
            {
              typedef __typeof__(*(&(chan_ext_time))) __array_t;
              typedef typename __array_t::item_t __item_t;
              __item_t &__item = chan_ext_time.append_item(647);
              __item.value = extras.ext_time;
            }
            if (__buffer.is_memberdump())
            {
              printf("%s%08" PRIx32 "%s: extras ", CT_OUT(BOLD), extras.u32, CT_OUT(NORM));
              printf(".baseline=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  extras.baseline, CT_OUT(NORM));
              printf(".ext_time=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  extras.ext_time, CT_OUT(NORM));
              printf("\n");
            }
          }

          else
          {
            // if((format_two.ex == 1))

            // else

            if ((format_two.ex == 1))
            {
              // UINT32 extras NOENCODE
              // {
                //  0_15: flags;
                // 16_31: ext_time;
                // ENCODE(chan_ext_time APPEND_LIST,(value=ext_time));
              // }
              union
              {
                struct
                {
#if __BYTE_ORDER == __LITTLE_ENDIAN
                  uint32 flags : 16; // 0..15
                  uint32 ext_time : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
                  uint32 ext_time : 16; // 16..31
                  uint32 flags : 16; // 0..15
#endif
                };
                uint32  u32;
              } extras;
              READ_FROM_BUFFER_FULL(657,uint32 ,extras,extras.u32,127);
              {
                typedef __typeof__(*(&(chan_ext_time))) __array_t;
                typedef typename __array_t::item_t __item_t;
                __item_t &__item = chan_ext_time.append_item(656);
                __item.value = extras.ext_time;
              }
              if (__buffer.is_memberdump())
              {
                printf("%s%08" PRIx32 "%s: extras ", CT_OUT(BOLD), extras.u32, CT_OUT(NORM));
                printf(".flags=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  extras.flags, CT_OUT(NORM));
                printf(".ext_time=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  extras.ext_time, CT_OUT(NORM));
                printf("\n");
              }
            }

            else
            {
              // if((format_two.ex == 2))

              // else

              if ((format_two.ex == 2))
              {
                // UINT32 extras NOENCODE
                // {
                  //  0_09: fine_time;
                  // 10_15: flags;
                  // 16_31: ext_time;
                  // ENCODE(chan_fine_time APPEND_LIST,(value=fine_time));
                  // ENCODE(chan_ext_time APPEND_LIST,(value=ext_time));
                // }
                union
                {
                  struct
                  {
#if __BYTE_ORDER == __LITTLE_ENDIAN
                    uint32 fine_time : 10; // 0..9
                    uint32 flags : 6; // 10..15
                    uint32 ext_time : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
                    uint32 ext_time : 16; // 16..31
                    uint32 flags : 6; // 10..15
                    uint32 fine_time : 10; // 0..9
#endif
                  };
                  uint32  u32;
                } extras;
                READ_FROM_BUFFER_FULL(668,uint32 ,extras,extras.u32,128);
                {
                  {
                    typedef __typeof__(*(&(chan_fine_time))) __array_t;
                    typedef typename __array_t::item_t __item_t;
                    __item_t &__item = chan_fine_time.append_item(666);
                    __item.value = extras.fine_time;
                  }
                  {
                    typedef __typeof__(*(&(chan_ext_time))) __array_t;
                    typedef typename __array_t::item_t __item_t;
                    __item_t &__item = chan_ext_time.append_item(667);
                    __item.value = extras.ext_time;
                  }
                }
                if (__buffer.is_memberdump())
                {
                  printf("%s%08" PRIx32 "%s: extras ", CT_OUT(BOLD), extras.u32, CT_OUT(NORM));
                  printf(".fine_time=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  extras.fine_time, CT_OUT(NORM));
                  printf(".flags=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  extras.flags, CT_OUT(NORM));
                  printf(".ext_time=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  extras.ext_time, CT_OUT(NORM));
                  printf("\n");
                }
              }

              else
              {
                // if((format_two.ex == 4))

                // else

                if ((format_two.ex == 4))
                {
                  // UINT32 extras NOENCODE
                  // {
                    //  0_15: baseline;
                    // 16_26: fine_time;
                    // 27_31: flags;
                    // ENCODE(chan_fine_time APPEND_LIST,(value=fine_time));
                  // }
                  union
                  {
                    struct
                    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
                      uint32 baseline : 16; // 0..15
                      uint32 fine_time : 11; // 16..26
                      uint32 flags : 5; // 27..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
                      uint32 flags : 5; // 27..31
                      uint32 fine_time : 11; // 16..26
                      uint32 baseline : 16; // 0..15
#endif
                    };
                    uint32  u32;
                  } extras;
                  READ_FROM_BUFFER_FULL(678,uint32 ,extras,extras.u32,129);
                  {
                    typedef __typeof__(*(&(chan_fine_time))) __array_t;
                    typedef typename __array_t::item_t __item_t;
                    __item_t &__item = chan_fine_time.append_item(677);
                    __item.value = extras.fine_time;
                  }
                  if (__buffer.is_memberdump())
                  {
                    printf("%s%08" PRIx32 "%s: extras ", CT_OUT(BOLD), extras.u32, CT_OUT(NORM));
                    printf(".baseline=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  extras.baseline, CT_OUT(NORM));
                    printf(".fine_time=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  extras.fine_time, CT_OUT(NORM));
                    printf(".flags=%s%2" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  extras.flags, CT_OUT(NORM));
                    printf("\n");
                  }
                }

                else
                {
                  // if((format_two.ex == 5))

                  if ((format_two.ex == 5))
                  {
                    // UINT32 extras NOENCODE
                    // {
                      //  0_09: midscale;
                      // 10_19: sazc;
                      // 20_29: sbzc;
                      //    30: pp;
                      //    31: dm;
                    // }
                    union
                    {
                      struct
                      {
#if __BYTE_ORDER == __LITTLE_ENDIAN
                        uint32 midscale : 10; // 0..9
                        uint32 sazc : 10; // 10..19
                        uint32 sbzc : 10; // 20..29
                        uint32 pp : 1; // 30
                        uint32 dm : 1; // 31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
                        uint32 dm : 1; // 31
                        uint32 pp : 1; // 30
                        uint32 sbzc : 10; // 20..29
                        uint32 sazc : 10; // 10..19
                        uint32 midscale : 10; // 0..9
#endif
                      };
                      uint32  u32;
                    } extras;
                    READ_FROM_BUFFER_FULL(689,uint32 ,extras,extras.u32,130);
                    if (__buffer.is_memberdump())
                    {
                      printf("%s%08" PRIx32 "%s: extras ", CT_OUT(BOLD), extras.u32, CT_OUT(NORM));
                      printf(".midscale=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  extras.midscale, CT_OUT(NORM));
                      printf(".sazc=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  extras.sazc, CT_OUT(NORM));
                      printf(".sbzc=%s%3" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  extras.sbzc, CT_OUT(NORM));
                      printf(".pp=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  extras.pp, CT_OUT(NORM));
                      printf(".dm=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  extras.dm, CT_OUT(NORM));
                      printf("\n");
                    }
                  }
                }
              }
            }
          }
        }
      }

      else
      {
        // if((format_one.et == 1))

        if ((format_one.et == 1))
        {
          // UINT32 channel_time_tag NOENCODE
          // {
            //  0_31: time_tag;
            // ENCODE(channel_time APPEND_LIST,(value=time_tag));
          // }
          union
          {
            struct
            {
#if __BYTE_ORDER == __LITTLE_ENDIAN
              uint32 time_tag : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
              uint32 time_tag : 32; // 0..31
#endif
            };
            uint32  u32;
          } channel_time_tag;
          READ_FROM_BUFFER_FULL(703,uint32 ,channel_time_tag,channel_time_tag.u32,131);
          {
            typedef __typeof__(*(&(channel_time))) __array_t;
            typedef typename __array_t::item_t __item_t;
            __item_t &__item = channel_time.append_item(702);
            __item.value = channel_time_tag.time_tag;
          }
          if (__buffer.is_memberdump())
          {
            printf("%s%08" PRIx32 "%s: channel_time_tag ", CT_OUT(BOLD), channel_time_tag.u32, CT_OUT(NORM));
            printf(".time_tag=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  channel_time_tag.time_tag, CT_OUT(NORM));
            printf("\n");
          }
        }
      }
      // if((format_one.eq == 1))

      if ((format_one.eq == 1))
      {
        // UINT32 qdata NOENCODE
        // {
          //  0_14: qshort;
          //    15: empty;
          // 16_31: qlong;
          // ENCODE(qshort APPEND_LIST,(value=qshort));
          // ENCODE(qlong APPEND_LIST,(value=qlong));
        // }
        union
        {
          struct
          {
#if __BYTE_ORDER == __LITTLE_ENDIAN
            uint32 qshort : 15; // 0..14
            uint32 empty : 1; // 15
            uint32 qlong : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
            uint32 qlong : 16; // 16..31
            uint32 empty : 1; // 15
            uint32 qshort : 15; // 0..14
#endif
          };
          uint32  u32;
        } qdata;
        READ_FROM_BUFFER_FULL(718,uint32 ,qdata,qdata.u32,132);
        {
          {
            typedef __typeof__(*(&(qshort))) __array_t;
            typedef typename __array_t::item_t __item_t;
            __item_t &__item = qshort.append_item(716);
            __item.value = qdata.qshort;
          }
          {
            typedef __typeof__(*(&(qlong))) __array_t;
            typedef typename __array_t::item_t __item_t;
            __item_t &__item = qlong.append_item(717);
            __item.value = qdata.qlong;
          }
        }
        if (__buffer.is_memberdump())
        {
          printf("%s%08" PRIx32 "%s: qdata ", CT_OUT(BOLD), qdata.u32, CT_OUT(NORM));
          printf(".qshort=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  qdata.qshort, CT_OUT(NORM));
          printf(".empty=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  qdata.empty, CT_OUT(NORM));
          printf(".qlong=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  qdata.qlong, CT_OUT(NORM));
          printf("\n");
        }
      }
    }
  }
}
FORCE_IMPL_DATA_SRC_FCN_ARG(void,VME_CAEN_V1751::__unpack,uint32 board);

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
  READ_FROM_BUFFER_FULL(93,uint32 ,hi,hi.u32,134);
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
  READ_FROM_BUFFER_FULL(97,uint32 ,lo,lo.u32,135);
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
  UNPACK_DECL(1210,TIMESTAMP_WHITERABBIT,ts,/*id*/0x700);
  // external data = EXT_AIDA();
  UNPACK_DECL(1211,EXT_AIDA,data);
}
FORCE_IMPL_DATA_SRC_FCN(void,aida_subev::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for bgo_tamex_subevent.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(bgo_tamex_subevent)
template<typename __data_src_t>
void bgo_tamex_subevent::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_MAGENTA),  "bgo_tamex_subevent",CT_OUT(NORM));
  }
  // select optional

    // ts = TIMESTAMP_WHITERABBIT_EXTENDED(id=0x1900);
  do
  {
    if (__buffer.empty()) goto no_match_2;
    int __match_no = 0;
    // optimized match 1: TIMESTAMP_WHITERABBIT_EXTENDED ts: (s32) => (0xfffeffff,0x00001900)
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
        CHECK_SPURIOUS_MATCH_DECL(1185,spurious_match_abort_loop_6,TIMESTAMP_WHITERABBIT_EXTENDED,/*id*/0x1900);
        UNPACK_DECL(1185,TIMESTAMP_WHITERABBIT_EXTENDED,ts,/*id*/0x1900);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_6:;
    no_match_2:;
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
  if (__buffer.empty()) goto data_done_6;
  PEEK_FROM_BUFFER_FULL(1188,uint32 ,be,__be.u32,137);
  CHECK_JUMP_BITS_EQUAL(1188,__be.b,0xbad00bad,data_done_6);
  be.u32 = __be.u32;
  __buffer.advance(sizeof(__be.u32));
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: be ", CT_OUT(BOLD), __be.u32, CT_OUT(NORM));
    printf(".b=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  __be.b, CT_OUT(NORM));
    printf("\n");
  }
  data_done_6:;
  // select optional

    // trigger_window = TAMEX4_HEADER();
  do
  {
    if (__buffer.empty()) goto no_match_3;
    int __match_no = 0;
    // optimized match 1: TAMEX4_HEADER trigger_window: (s32) => (0x00000000,0x00000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1193,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1192,spurious_match_abort_loop_7,TAMEX4_HEADER);
        UNPACK_DECL(1192,TAMEX4_HEADER,trigger_window);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_7:;
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
    PEEK_FROM_BUFFER(1198,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1197,spurious_match_abort_loop_8,TAMEX4_PADDING);
        UNPACK_DECL(1197,TAMEX4_PADDING,padding);
        break;
    }
  }
  spurious_match_abort_loop_8:;
  // select several

    // tamex[0] = TAMEX4_SFP(sfp=1,card=0);
    // tamex[1] = TAMEX4_SFP(sfp=1,card=1);
    // tamex[2] = TAMEX4_SFP(sfp=1,card=2);
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: TAMEX4_SFP tamex[0]: (s32) => (0xfffff0ff,0x00001034)
    // optimized match 2: TAMEX4_SFP tamex[1]: (s32) => (0xfffff0ff,0x00011034)
    // optimized match 3: TAMEX4_SFP tamex[2]: (s32) => (0xfffff0ff,0x00021034)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1205,uint32,__match_peek);
    // differ = 00030000 : 16 17
    uint32 __match_index = 0 | /* 16,17 */ ((__match_peek >> 16) & 0x00000003);
    static const sint8 __match_index_array[4] = { 1, 2, 3, 0, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 1
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        UNPACK_DECL(1202,TAMEX4_SFP,tamex[0],/*sfp*/1,/*card*/0);
        break;
      case 2:
        UNPACK_DECL(1203,TAMEX4_SFP,tamex[1],/*sfp*/1,/*card*/1);
        break;
      case 3:
        UNPACK_DECL(1204,TAMEX4_SFP,tamex[2],/*sfp*/1,/*card*/2);
        break;
    }
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,bgo_tamex_subevent::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for bm_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(bm_subev)
template<typename __data_src_t>
void bm_subev::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_MAGENTA),  "bm_subev",CT_OUT(NORM));
  }
  // MEMBER(DATA32 dataS2[100000] NO_INDEX_LIST);
  // MEMBER(DATA32 dataS4[100000] NO_INDEX_LIST);
  // select optional

    // ts = TIMESTAMP_WHITERABBIT_EXTENDED(id=0x1700);
  do
  {
    if (__buffer.empty()) goto no_match_4;
    int __match_no = 0;
    // optimized match 1: TIMESTAMP_WHITERABBIT_EXTENDED ts: (s32) => (0xfffeffff,0x00001700)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1439,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1438,spurious_match_abort_loop_9,TIMESTAMP_WHITERABBIT_EXTENDED,/*id*/0x1700);
        UNPACK_DECL(1438,TIMESTAMP_WHITERABBIT_EXTENDED,ts,/*id*/0x1700);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_9:;
    no_match_4:;
  // UINT32 headS2 NOENCODE
  // {
    //  0_12: l_hit_ct;
    // 13_15: reserved;
    // 16_31: l_id = MATCH(0xaaaa);
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 l_hit_ct : 13; // 0..12
      uint32 reserved : 3; // 13..15
      uint32 l_id : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 l_id : 16; // 16..31
      uint32 reserved : 3; // 13..15
      uint32 l_hit_ct : 13; // 0..12
#endif
    };
    uint32  u32;
  } headS2;
  READ_FROM_BUFFER_FULL(1447,uint32 ,headS2,headS2.u32,138);
  CHECK_BITS_EQUAL(1446,headS2.l_id,0xaaaa);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: headS2 ", CT_OUT(BOLD), headS2.u32, CT_OUT(NORM));
    printf(".l_hit_ct=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  headS2.l_hit_ct, CT_OUT(NORM));
    printf(".reserved=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  headS2.reserved, CT_OUT(NORM));
    printf(".l_id=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  headS2.l_id, CT_OUT(NORM));
    printf("\n");
  }
  // list(0<=l_i<headS2.l_hit_ct)

  for (uint32 l_i = 0; l_i < (uint32) (headS2.l_hit_ct); ++l_i)
  {
    // UINT32 hit NOENCODE
    // {
      //  0_31: data;
      // ENCODE(dataS2 APPEND_LIST,(value=data));
    // }
    union
    {
      struct
      {
#if __BYTE_ORDER == __LITTLE_ENDIAN
        uint32 data : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
        uint32 data : 32; // 0..31
#endif
      };
      uint32  u32;
    } hit;
    READ_FROM_BUFFER_FULL(1455,uint32 ,hit,hit.u32,139);
    {
      typedef __typeof__(*(&(dataS2))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = dataS2.append_item(1454);
      __item.value = hit.data;
    }
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: hit ", CT_OUT(BOLD), hit.u32, CT_OUT(NORM));
      printf(".data=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  hit.data, CT_OUT(NORM));
      printf("\n");
    }
  }
  // UINT32 headS4 NOENCODE
  // {
    //  0_12: l_hit_ct;
    // 13_15: reserved;
    // 16_31: l_id = MATCH(0xbbbb);
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 l_hit_ct : 13; // 0..12
      uint32 reserved : 3; // 13..15
      uint32 l_id : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 l_id : 16; // 16..31
      uint32 reserved : 3; // 13..15
      uint32 l_hit_ct : 13; // 0..12
#endif
    };
    uint32  u32;
  } headS4;
  READ_FROM_BUFFER_FULL(1464,uint32 ,headS4,headS4.u32,140);
  CHECK_BITS_EQUAL(1463,headS4.l_id,0xbbbb);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: headS4 ", CT_OUT(BOLD), headS4.u32, CT_OUT(NORM));
    printf(".l_hit_ct=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  headS4.l_hit_ct, CT_OUT(NORM));
    printf(".reserved=%s%1" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  headS4.reserved, CT_OUT(NORM));
    printf(".l_id=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  headS4.l_id, CT_OUT(NORM));
    printf("\n");
  }
  // list(0<=l_i<headS4.l_hit_ct)

  for (uint32 l_i = 0; l_i < (uint32) (headS4.l_hit_ct); ++l_i)
  {
    // UINT32 hit NOENCODE
    // {
      //  0_31: data;
      // ENCODE(dataS4 APPEND_LIST,(value=data));
    // }
    union
    {
      struct
      {
#if __BYTE_ORDER == __LITTLE_ENDIAN
        uint32 data : 32; // 0..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
        uint32 data : 32; // 0..31
#endif
      };
      uint32  u32;
    } hit;
    READ_FROM_BUFFER_FULL(1472,uint32 ,hit,hit.u32,141);
    {
      typedef __typeof__(*(&(dataS4))) __array_t;
      typedef typename __array_t::item_t __item_t;
      __item_t &__item = dataS4.append_item(1471);
      __item.value = hit.data;
    }
    if (__buffer.is_memberdump())
    {
      printf("%s%08" PRIx32 "%s: hit ", CT_OUT(BOLD), hit.u32, CT_OUT(NORM));
      printf(".data=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  hit.data, CT_OUT(NORM));
      printf("\n");
    }
  }
  // UINT32 trailer NOENCODE
  // {
    //  0_15: reserved;
    // 16_31: l_id = MATCH(0xcccc);
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 reserved : 16; // 0..15
      uint32 l_id : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 l_id : 16; // 16..31
      uint32 reserved : 16; // 0..15
#endif
    };
    uint32  u32;
  } trailer;
  READ_FROM_BUFFER_FULL(1479,uint32 ,trailer,trailer.u32,142);
  CHECK_BITS_EQUAL(1478,trailer.l_id,0xcccc);
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: trailer ", CT_OUT(BOLD), trailer.u32, CT_OUT(NORM));
    printf(".reserved=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.reserved, CT_OUT(NORM));
    printf(".l_id=%s%4" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  trailer.l_id, CT_OUT(NORM));
    printf("\n");
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,bm_subev::__unpack);

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
    if (__buffer.empty()) goto no_match_5;
    int __match_no = 0;
    // optimized match 1: TIMESTAMP_WHITERABBIT ts: (s32) => (0xfffeffff,0x00000500)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1314,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_5;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1313,spurious_match_abort_loop_10,TIMESTAMP_WHITERABBIT,/*id*/0x500);
        UNPACK_DECL(1313,TIMESTAMP_WHITERABBIT,ts,/*id*/0x500);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_10:;
    no_match_5:;
  // select optional

    // trigger_window = TAMEX4_HEADER();
  do
  {
    if (__buffer.empty()) goto no_match_6;
    int __match_no = 0;
    // optimized match 1: TAMEX4_HEADER trigger_window: (s32) => (0x00000000,0x00000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1319,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1318,spurious_match_abort_loop_11,TAMEX4_HEADER);
        UNPACK_DECL(1318,TAMEX4_HEADER,trigger_window);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_11:;
    no_match_6:;
  // select several

    // padding = TAMEX4_PADDING();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: TAMEX4_PADDING padding: (s32) => (0xfff00000,0xadd00000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1324,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1323,spurious_match_abort_loop_12,TAMEX4_PADDING);
        UNPACK_DECL(1323,TAMEX4_PADDING,padding);
        break;
    }
  }
  spurious_match_abort_loop_12:;
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
    PEEK_FROM_BUFFER(1337,uint32,__match_peek);
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
        UNPACK_DECL(1328,TAMEX4_SFP,tamex[0],/*sfp*/0,/*card*/0);
        break;
      case 2:
        UNPACK_DECL(1329,TAMEX4_SFP,tamex[1],/*sfp*/0,/*card*/1);
        break;
      case 3:
        UNPACK_DECL(1330,TAMEX4_SFP,tamex[2],/*sfp*/0,/*card*/2);
        break;
      case 4:
        UNPACK_DECL(1331,TAMEX4_SFP,tamex[3],/*sfp*/0,/*card*/3);
        break;
      case 5:
        UNPACK_DECL(1332,TAMEX4_SFP,tamex[4],/*sfp*/0,/*card*/4);
        break;
      case 6:
        UNPACK_DECL(1333,TAMEX4_SFP,tamex[5],/*sfp*/0,/*card*/5);
        break;
      case 7:
        UNPACK_DECL(1334,TAMEX4_SFP,tamex[6],/*sfp*/0,/*card*/6);
        break;
      case 8:
        UNPACK_DECL(1335,TAMEX4_SFP,tamex[7],/*sfp*/0,/*card*/7);
        break;
      case 9:
        UNPACK_DECL(1336,TAMEX4_SFP,tamex[8],/*sfp*/0,/*card*/8);
        break;
    }
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,bplast_subev::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for fatima_tamex_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(fatima_tamex_subev)
template<typename __data_src_t>
void fatima_tamex_subev::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_MAGENTA),  "fatima_tamex_subev",CT_OUT(NORM));
  }
  // select optional

    // ts = TIMESTAMP_WHITERABBIT_EXTENDED(id=0x1600);
  do
  {
    if (__buffer.empty()) goto no_match_7;
    int __match_no = 0;
    // optimized match 1: TIMESTAMP_WHITERABBIT_EXTENDED ts: (s32) => (0xfffeffff,0x00001600)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1242,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_7;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1241,spurious_match_abort_loop_13,TIMESTAMP_WHITERABBIT_EXTENDED,/*id*/0x1600);
        UNPACK_DECL(1241,TIMESTAMP_WHITERABBIT_EXTENDED,ts,/*id*/0x1600);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_13:;
    no_match_7:;
  // select optional

    // trigger_window = TAMEX4_HEADER();
  do
  {
    if (__buffer.empty()) goto no_match_8;
    int __match_no = 0;
    // optimized match 1: TAMEX4_HEADER trigger_window: (s32) => (0x00000000,0x00000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1247,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_8;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1246,spurious_match_abort_loop_14,TAMEX4_HEADER);
        UNPACK_DECL(1246,TAMEX4_HEADER,trigger_window);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_14:;
    no_match_8:;
  // select several

    // padding = TAMEX4_PADDING();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: TAMEX4_PADDING padding: (s32) => (0xfff00000,0xadd00000)
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
        CHECK_SPURIOUS_MATCH_DECL(1251,spurious_match_abort_loop_15,TAMEX4_PADDING);
        UNPACK_DECL(1251,TAMEX4_PADDING,padding);
        break;
    }
  }
  spurious_match_abort_loop_15:;
  // select several

    // tamex[0] = TAMEX4_SFP(sfp=0,card=0);
    // tamex[1] = TAMEX4_SFP(sfp=0,card=1);
    // tamex[2] = TAMEX4_SFP(sfp=0,card=2);
    // tamex[3] = TAMEX4_SFP(sfp=0,card=3);
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: TAMEX4_SFP tamex[0]: (s32) => (0xfffff0ff,0x00000034)
    // optimized match 2: TAMEX4_SFP tamex[1]: (s32) => (0xfffff0ff,0x00010034)
    // optimized match 3: TAMEX4_SFP tamex[2]: (s32) => (0xfffff0ff,0x00020034)
    // optimized match 4: TAMEX4_SFP tamex[3]: (s32) => (0xfffff0ff,0x00030034)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1260,uint32,__match_peek);
    // differ = 00030000 : 16 17
    uint32 __match_index = 0 | /* 16,17 */ ((__match_peek >> 16) & 0x00000003);
    static const sint8 __match_index_array[4] = { 1, 2, 3, 4, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 1
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        UNPACK_DECL(1256,TAMEX4_SFP,tamex[0],/*sfp*/0,/*card*/0);
        break;
      case 2:
        UNPACK_DECL(1257,TAMEX4_SFP,tamex[1],/*sfp*/0,/*card*/1);
        break;
      case 3:
        UNPACK_DECL(1258,TAMEX4_SFP,tamex[2],/*sfp*/0,/*card*/2);
        break;
      case 4:
        UNPACK_DECL(1259,TAMEX4_SFP,tamex[3],/*sfp*/0,/*card*/3);
        break;
    }
  }
}
FORCE_IMPL_DATA_SRC_FCN(void,fatima_tamex_subev::__unpack);

/** END_UNPACKER ******************************************************/
/** BEGIN_UNPACKER *****************************************************
 *
 * Event unpacker for fatima_vme_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(fatima_vme_subev)
template<typename __data_src_t>
void fatima_vme_subev::__unpack(__data_src_t &__buffer)
{
  if (__buffer.is_memberdump())
  {
    printf("          %s%s%s: \n", CT_OUT(BOLD_MAGENTA),  "fatima_vme_subev",CT_OUT(NORM));
  }
  // select optional

    // ts = TIMESTAMP_WHITERABBIT_EXTENDED(id=0x1500);
  do
  {
    if (__buffer.empty()) goto no_match_9;
    int __match_no = 0;
    // optimized match 1: TIMESTAMP_WHITERABBIT_EXTENDED ts: (s32) => (0xfffeffff,0x00001500)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1268,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1267,spurious_match_abort_loop_16,TIMESTAMP_WHITERABBIT_EXTENDED,/*id*/0x1500);
        UNPACK_DECL(1267,TIMESTAMP_WHITERABBIT_EXTENDED,ts,/*id*/0x1500);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_16:;
    no_match_9:;
  // select several

    // error1 = ERR_WORD_SIX();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: ERR_WORD_SIX error1: (s32) => (0xffffffff,0x06000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1273,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1272,spurious_match_abort_loop_17,ERR_WORD_SIX);
        UNPACK_DECL(1272,ERR_WORD_SIX,error1);
        break;
    }
  }
  spurious_match_abort_loop_17:;
  // select optional

    // scalers = FATIMA_VME_SCALERS();
  do
  {
    if (__buffer.empty()) goto no_match_10;
    int __match_no = 0;
    // optimized match 1: FATIMA_VME_SCALERS scalers: (s32) => (0xf8000000,0x78000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1278,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1277,spurious_match_abort_loop_18,FATIMA_VME_SCALERS);
        UNPACK_DECL(1277,FATIMA_VME_SCALERS,scalers);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_18:;
    no_match_10:;
  // select optional

    // qdc1 = VME_CAEN_V1751(board=6);
  do
  {
    if (__buffer.empty()) goto no_match_11;
    int __match_no = 0;
    // optimized match 1: VME_CAEN_V1751 qdc1: (s32) => (0xf0000000,0xa0000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1280,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_11;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1280,spurious_match_abort_loop_19,VME_CAEN_V1751,/*board*/6);
        UNPACK_DECL(1280,VME_CAEN_V1751,qdc1,/*board*/6);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_19:;
    no_match_11:;
  // select optional

    // qdc2 = VME_CAEN_V1751(board=7);
  do
  {
    if (__buffer.empty()) goto no_match_12;
    int __match_no = 0;
    // optimized match 1: VME_CAEN_V1751 qdc2: (s32) => (0xf0000000,0xa0000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1281,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_12;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1281,spurious_match_abort_loop_20,VME_CAEN_V1751,/*board*/7);
        UNPACK_DECL(1281,VME_CAEN_V1751,qdc2,/*board*/7);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_20:;
    no_match_12:;
  // select optional

    // qdc3 = VME_CAEN_V1751(board=8);
  do
  {
    if (__buffer.empty()) goto no_match_13;
    int __match_no = 0;
    // optimized match 1: VME_CAEN_V1751 qdc3: (s32) => (0xf0000000,0xa0000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1282,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_13;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1282,spurious_match_abort_loop_21,VME_CAEN_V1751,/*board*/8);
        UNPACK_DECL(1282,VME_CAEN_V1751,qdc3,/*board*/8);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_21:;
    no_match_13:;
  // select optional

    // qdc4 = VME_CAEN_V1751(board=9);
  do
  {
    if (__buffer.empty()) goto no_match_14;
    int __match_no = 0;
    // optimized match 1: VME_CAEN_V1751 qdc4: (s32) => (0xf0000000,0xa0000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1283,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_14;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1283,spurious_match_abort_loop_22,VME_CAEN_V1751,/*board*/9);
        UNPACK_DECL(1283,VME_CAEN_V1751,qdc4,/*board*/9);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_22:;
    no_match_14:;
  // select optional

    // qdc5 = VME_CAEN_V1751(board=10);
  do
  {
    if (__buffer.empty()) goto no_match_15;
    int __match_no = 0;
    // optimized match 1: VME_CAEN_V1751 qdc5: (s32) => (0xf0000000,0xa0000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1284,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_15;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1284,spurious_match_abort_loop_23,VME_CAEN_V1751,/*board*/10);
        UNPACK_DECL(1284,VME_CAEN_V1751,qdc5,/*board*/10);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_23:;
    no_match_15:;
  // select several

    // error2 = ERR_WORD_SIX();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: ERR_WORD_SIX error2: (s32) => (0xffffffff,0x06000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1290,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1289,spurious_match_abort_loop_24,ERR_WORD_SIX);
        UNPACK_DECL(1289,ERR_WORD_SIX,error2);
        break;
    }
  }
  spurious_match_abort_loop_24:;
  // select optional

    // tdc1 = VME_CAEN_V1290_N();
  do
  {
    if (__buffer.empty()) goto no_match_16;
    int __match_no = 0;
    // optimized match 1: VME_CAEN_V1290_N tdc1: (s32) => (0xf8000000,0x40000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1296,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_16;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1295,spurious_match_abort_loop_25,VME_CAEN_V1290_N);
        UNPACK_DECL(1295,VME_CAEN_V1290_N,tdc1);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_25:;
    no_match_16:;
  // select several

    // error3 = ERR_WORD_SIX();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: ERR_WORD_SIX error3: (s32) => (0xffffffff,0x06000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1301,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1300,spurious_match_abort_loop_26,ERR_WORD_SIX);
        UNPACK_DECL(1300,ERR_WORD_SIX,error3);
        break;
    }
  }
  spurious_match_abort_loop_26:;
  // select optional

    // tdc2 = VME_CAEN_V1290_N();
  do
  {
    if (__buffer.empty()) goto no_match_17;
    int __match_no = 0;
    // optimized match 1: VME_CAEN_V1290_N tdc2: (s32) => (0xf8000000,0x40000000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1306,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 1
    }
    if (!__match_no) goto no_match_17;
    switch (__match_no)
    {
      case 1:
        UNPACK_DECL(1305,VME_CAEN_V1290_N,tdc2);
        break;
    }
  }
  while (0);
    no_match_17:;
}
FORCE_IMPL_DATA_SRC_FCN(void,fatima_vme_subev::__unpack);

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
    if (__buffer.empty()) goto no_match_18;
    int __match_no = 0;
    // optimized match 1: TIMESTAMP_WHITERABBIT ts: (s32) => (0xfffeffff,0x00000400)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1220,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_18;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1219,spurious_match_abort_loop_27,TIMESTAMP_WHITERABBIT,/*id*/0x400);
        UNPACK_DECL(1219,TIMESTAMP_WHITERABBIT,ts,/*id*/0x400);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_27:;
    no_match_18:;
  // select several

    // padding = FEBEX_PADDING();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: FEBEX_PADDING padding: (s32) => (0xfff00000,0xadd00000)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1225,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1224,spurious_match_abort_loop_28,FEBEX_PADDING);
        UNPACK_DECL(1224,FEBEX_PADDING,padding);
        break;
    }
  }
  spurious_match_abort_loop_28:;
  // select several

    // data[0] = FEBEX_EVENT(card=0);
    // data[1] = FEBEX_EVENT(card=1);
    // data[2] = FEBEX_EVENT(card=2);
    // data[3] = FEBEX_EVENT(card=3);
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: FEBEX_EVENT data[0]: (s32) => (0xffff00ff,0xff000034)
    // optimized match 2: FEBEX_EVENT data[1]: (s32) => (0xffff00ff,0xff010034)
    // optimized match 3: FEBEX_EVENT data[2]: (s32) => (0xffff00ff,0xff020034)
    // optimized match 4: FEBEX_EVENT data[3]: (s32) => (0xffff00ff,0xff030034)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1233,uint32,__match_peek);
    // differ = 00030000 : 16 17
    uint32 __match_index = 0 | /* 16,17 */ ((__match_peek >> 16) & 0x00000003);
    static const sint8 __match_index_array[4] = { 1, 2, 3, 4, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 1
    }
    if (!__match_no) break;
    switch (__match_no)
    {
      case 1:
        UNPACK_DECL(1229,FEBEX_EVENT,data[0],/*card*/0);
        break;
      case 2:
        UNPACK_DECL(1230,FEBEX_EVENT,data[1],/*card*/1);
        break;
      case 3:
        UNPACK_DECL(1231,FEBEX_EVENT,data[2],/*card*/2);
        break;
      case 4:
        UNPACK_DECL(1232,FEBEX_EVENT,data[3],/*card*/3);
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
    PEEK_FROM_BUFFER(1345,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1344,spurious_match_abort_loop_29,TRIG3EVENT);
        UNPACK_DECL(1344,TRIG3EVENT,trig3);
        break;
    }
  }
  spurious_match_abort_loop_29:;
  // select several

    // spill_on = SPILL_ON();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: SPILL_ON spill_on: (s32) => (0xffffffff,0x30303030)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1350,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1349,spurious_match_abort_loop_30,SPILL_ON);
        UNPACK_DECL(1349,SPILL_ON,spill_on);
        break;
    }
  }
  spurious_match_abort_loop_30:;
  // select several

    // spill_off = SPILL_OFF();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: SPILL_OFF spill_off: (s32) => (0xffffffff,0x4040400a)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1355,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1354,spurious_match_abort_loop_31,SPILL_OFF);
        UNPACK_DECL(1354,SPILL_OFF,spill_off);
        break;
    }
  }
  spurious_match_abort_loop_31:;
  // select optional

    // data = MAIN_CRATE_DATA();
  do
  {
    if (__buffer.empty()) goto no_match_19;
    int __match_no = 0;
    // optimized match 1: MAIN_CRATE_DATA data: could not get bits
    __buffer.peeking();
    MATCH_DECL(1359,__match_no,1,MAIN_CRATE_DATA,data);
    if (!__match_no) goto no_match_19;
    switch (__match_no)
    {
      case 1:
        UNPACK_DECL(1359,MAIN_CRATE_DATA,data);
        break;
    }
  }
  while (0);
    no_match_19:;
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
    if (__buffer.empty()) goto no_match_20;
    int __match_no = 0;
    // optimized match 1: TIMESTAMP_WHITERABBIT wr: (s32) => (0xfffeffff,0x00000100)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1417,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 0
    }
    if (!__match_no) goto no_match_20;
    switch (__match_no)
    {
      case 1:
        CHECK_SPURIOUS_MATCH_DECL(1416,spurious_match_abort_loop_32,TIMESTAMP_WHITERABBIT,/*id*/0x100);
        UNPACK_DECL(1416,TIMESTAMP_WHITERABBIT,wr,/*id*/0x100);
        break;
    }
  }
  while (0);
  spurious_match_abort_loop_32:;
    no_match_20:;
  // select several

    // trig3 = TRIG3EVENT();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: TRIG3EVENT trig3: (s32) => (0xffffffff,0x20202020)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1422,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1421,spurious_match_abort_loop_33,TRIG3EVENT);
        UNPACK_DECL(1421,TRIG3EVENT,trig3);
        break;
    }
  }
  spurious_match_abort_loop_33:;
  // select optional

    // data = TPAT_CRATE_DATA();
  do
  {
    if (__buffer.empty()) goto no_match_21;
    int __match_no = 0;
    // optimized match 1: TPAT_CRATE_DATA data: (s32)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1427,uint32,__match_peek);
    // differ = 00000000 :
    uint32 __match_index = 0;
    static const sint8 __match_index_array[1] = { 1, };
    __match_no = __match_index_array[__match_index];
    // last_subevent_item = 1
    }
    if (!__match_no) goto no_match_21;
    switch (__match_no)
    {
      case 1:
        UNPACK_DECL(1426,TPAT_CRATE_DATA,data);
        break;
    }
  }
  while (0);
    no_match_21:;
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
  if (__buffer.empty()) goto data_done_7;
  PEEK_FROM_BUFFER_FULL(1365,uint32 ,be,__be.u32,143);
  CHECK_JUMP_BITS_EQUAL(1365,__be.b,0xbad00bad,data_done_7);
  be.u32 = __be.u32;
  __buffer.advance(sizeof(__be.u32));
  if (__buffer.is_memberdump())
  {
    printf("%s%08" PRIx32 "%s: be ", CT_OUT(BOLD), __be.u32, CT_OUT(NORM));
    printf(".b=%s%8" PRIx64 "%s ", CT_OUT(BOLD), (uint64_t)  __be.b, CT_OUT(NORM));
    printf("\n");
  }
  data_done_7:;
  // select several

    // trig3 = TRIG3EVENT();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: TRIG3EVENT trig3: (s32) => (0xffffffff,0x20202020)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1370,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1369,spurious_match_abort_loop_34,TRIG3EVENT);
        UNPACK_DECL(1369,TRIG3EVENT,trig3);
        break;
    }
  }
  spurious_match_abort_loop_34:;
  // select several

    // spill_on = SPILL_ON();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: SPILL_ON spill_on: (s32) => (0xffffffff,0x30303030)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1375,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1374,spurious_match_abort_loop_35,SPILL_ON);
        UNPACK_DECL(1374,SPILL_ON,spill_on);
        break;
    }
  }
  spurious_match_abort_loop_35:;
  // select several

    // spill_off = SPILL_OFF();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: SPILL_OFF spill_off: (s32) => (0xffffffff,0x4040400a)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1380,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1379,spurious_match_abort_loop_36,SPILL_OFF);
        UNPACK_DECL(1379,SPILL_OFF,spill_off);
        break;
    }
  }
  spurious_match_abort_loop_36:;
  // select optional

    // data = TPC_CRATE_DATA();
  do
  {
    if (__buffer.empty()) goto no_match_22;
    int __match_no = 0;
    // optimized match 1: TPC_CRATE_DATA data: could not get bits
    __buffer.peeking();
    MATCH_DECL(1384,__match_no,1,TPC_CRATE_DATA,data);
    if (!__match_no) goto no_match_22;
    switch (__match_no)
    {
      case 1:
        UNPACK_DECL(1384,TPC_CRATE_DATA,data);
        break;
    }
  }
  while (0);
    no_match_22:;
}
FORCE_IMPL_DATA_SRC_FCN(void,frs_tpc_subev::__unpack);

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
    PEEK_FROM_BUFFER(1393,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1392,spurious_match_abort_loop_37,TRIG3EVENT);
        UNPACK_DECL(1392,TRIG3EVENT,trig3);
        break;
    }
  }
  spurious_match_abort_loop_37:;
  // select several

    // spill_on = SPILL_ON();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: SPILL_ON spill_on: (s32) => (0xffffffff,0x30303030)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1398,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1397,spurious_match_abort_loop_38,SPILL_ON);
        UNPACK_DECL(1397,SPILL_ON,spill_on);
        break;
    }
  }
  spurious_match_abort_loop_38:;
  // select several

    // spill_off = SPILL_OFF();
  for ( ; ; )
  {
    if (__buffer.empty()) break;
    int __match_no = 0;
    // optimized match 1: SPILL_OFF spill_off: (s32) => (0xffffffff,0x4040400a)
    {
    uint32 __match_peek;
    PEEK_FROM_BUFFER(1403,uint32,__match_peek);
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
        CHECK_SPURIOUS_MATCH_DECL(1402,spurious_match_abort_loop_39,SPILL_OFF);
        UNPACK_DECL(1402,SPILL_OFF,spill_off);
        break;
    }
  }
  spurious_match_abort_loop_39:;
  // select optional

    // data = USER_CRATE_DATA();
  do
  {
    if (__buffer.empty()) goto no_match_23;
    int __match_no = 0;
    // optimized match 1: USER_CRATE_DATA data: could not get bits
    __buffer.peeking();
    MATCH_DECL(1408,__match_no,1,USER_CRATE_DATA,data);
    if (!__match_no) goto no_match_23;
    switch (__match_no)
    {
      case 1:
        UNPACK_DECL(1408,USER_CRATE_DATA,data);
        break;
    }
  }
  while (0);
    no_match_23:;
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
  // fatima = fatima_tamex_subev(type=10,subtype=1,procid=75,control=20);
  // fatimavme = fatima_vme_subev(type=10,subtype=1,procid=70,control=20);
  // bplast = bplast_subev(type=10,subtype=1,procid=80,control=20);
  // bgo = bgo_tamex_subevent(procid=100);
  // frsmain = frs_main_subev(procid=10);
  // frstpc = frs_tpc_subev(procid=20);
  // frsuser = frs_user_subev(procid=30);
  // frstpat = frs_tpat_subev(procid=15);
  // beammonitor = bm_subev(procid=1);
  // ignore_unknown_subevent;
{
  int __match_no = 0;
  MATCH_SUBEVENT_DECL(1484,__match_no,1,((VES10_1_type==10)&&(VES10_1_subtype==1)&&(VES10_1_control==37)&&(VES10_1_procid==90)),aida);
  MATCH_SUBEVENT_DECL(1485,__match_no,2,((VES10_1_type==10)&&(VES10_1_subtype==1)&&(VES10_1_control==20)&&(VES10_1_procid==60)),germanium);
  MATCH_SUBEVENT_DECL(1486,__match_no,3,((VES10_1_type==10)&&(VES10_1_subtype==1)&&(VES10_1_control==20)&&(VES10_1_procid==75)),fatima);
  MATCH_SUBEVENT_DECL(1487,__match_no,4,((VES10_1_type==10)&&(VES10_1_subtype==1)&&(VES10_1_control==20)&&(VES10_1_procid==70)),fatimavme);
  MATCH_SUBEVENT_DECL(1488,__match_no,5,((VES10_1_type==10)&&(VES10_1_subtype==1)&&(VES10_1_control==20)&&(VES10_1_procid==80)),bplast);
  MATCH_SUBEVENT_DECL(1489,__match_no,6,((VES10_1_procid==100)),bgo);
  MATCH_SUBEVENT_DECL(1491,__match_no,7,((VES10_1_procid==10)),frsmain);
  MATCH_SUBEVENT_DECL(1492,__match_no,8,((VES10_1_procid==20)),frstpc);
  MATCH_SUBEVENT_DECL(1493,__match_no,9,((VES10_1_procid==30)),frsuser);
  MATCH_SUBEVENT_DECL(1494,__match_no,10,((VES10_1_procid==15)),frstpat);
  MATCH_SUBEVENT_DECL(1496,__match_no,11,((VES10_1_procid==1)),beammonitor);
  if (!__match_no) return 0;
  switch (__match_no)
  {
    case 1:
      UNPACK_SUBEVENT_DECL(1484,0,aida_subev,aida);
      break;
    case 2:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1485,febex_subev,germanium,0);
      UNPACK_SUBEVENT_DECL(1485,0,febex_subev,germanium);
      break;
    case 3:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1486,fatima_tamex_subev,fatima,1);
      UNPACK_SUBEVENT_DECL(1486,0,fatima_tamex_subev,fatima);
      break;
    case 4:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1487,fatima_vme_subev,fatimavme,2);
      UNPACK_SUBEVENT_DECL(1487,0,fatima_vme_subev,fatimavme);
      break;
    case 5:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1488,bplast_subev,bplast,3);
      UNPACK_SUBEVENT_DECL(1488,0,bplast_subev,bplast);
      break;
    case 6:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1489,bgo_tamex_subevent,bgo,4);
      UNPACK_SUBEVENT_DECL(1489,0,bgo_tamex_subevent,bgo);
      break;
    case 7:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1491,frs_main_subev,frsmain,5);
      UNPACK_SUBEVENT_DECL(1491,0,frs_main_subev,frsmain);
      break;
    case 8:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1492,frs_tpc_subev,frstpc,6);
      UNPACK_SUBEVENT_DECL(1492,0,frs_tpc_subev,frstpc);
      break;
    case 9:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1493,frs_user_subev,frsuser,7);
      UNPACK_SUBEVENT_DECL(1493,0,frs_user_subev,frsuser);
      break;
    case 10:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1494,frs_tpat_subev,frstpat,8);
      UNPACK_SUBEVENT_DECL(1494,0,frs_tpat_subev,frstpat);
      break;
    case 11:
      UNPACK_SUBEVENT_CHECK_NO_REVISIT(1496,bm_subev,beammonitor,9);
      UNPACK_SUBEVENT_DECL(1496,0,bm_subev,beammonitor);
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
