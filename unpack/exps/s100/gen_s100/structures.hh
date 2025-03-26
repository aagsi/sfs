/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for BAD_EVENT.
 *
 * Do not edit - automatically generated.
 */

// BAD_EVENT()
#if !PACKER_CODE
# define DECLARED_UNPACK_BAD_EVENT
class BAD_EVENT
#else//PACKER_CODE
# define DECLARED_PACKER_BAD_EVENT
class PACKER_BAD_EVENT
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA8 bad);
  DATA8 bad;
  // UINT32 be NOENCODE
  // {
    //  0_31: b = MATCH(0xbad00bad);
  // }
  // ENCODE(bad,(value=1));


public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(BAD_EVENT);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for BARRIER.
 *
 * Do not edit - automatically generated.
 */

// BARRIER()
#if !PACKER_CODE
# define DECLARED_UNPACK_BARRIER
class BARRIER
#else//PACKER_CODE
# define DECLARED_PACKER_BARRIER
class PACKER_BARRIER
#endif//PACKER_CODE

{
public:
  // UINT32 barrier NOENCODE
  // {
    //  0_19: no;
    // 20_31: ba = RANGE(0xf52,0xf58);
  // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(BARRIER);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for DUMMY.
 *
 * Do not edit - automatically generated.
 */

// DUMMY()
#if !PACKER_CODE
# define DECLARED_UNPACK_DUMMY
class DUMMY
#else//PACKER_CODE
# define DECLARED_PACKER_DUMMY
class PACKER_DUMMY
#endif//PACKER_CODE

{
public:
  // UINT32 no NOENCODE;

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(DUMMY);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for ERR_WORD_SIX.
 *
 * Do not edit - automatically generated.
 */

// ERR_WORD_SIX()
#if !PACKER_CODE
# define DECLARED_UNPACK_ERR_WORD_SIX
class ERR_WORD_SIX
#else//PACKER_CODE
# define DECLARED_PACKER_ERR_WORD_SIX
class PACKER_ERR_WORD_SIX
#endif//PACKER_CODE

{
public:
  // UINT32 err NOENCODE
  // {
    //  0_31: err = MATCH(0x06000000);
  // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(ERR_WORD_SIX);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for EXT_AIDA.
 *
 * Do not edit - automatically generated.
 */


/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for FATIMA_VME_SCALERS.
 *
 * Do not edit - automatically generated.
 */

// FATIMA_VME_SCALERS()
#if !PACKER_CODE
# define DECLARED_UNPACK_FATIMA_VME_SCALERS
class FATIMA_VME_SCALERS
#else//PACKER_CODE
# define DECLARED_PACKER_FATIMA_VME_SCALERS
class PACKER_FATIMA_VME_SCALERS
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA32 data[32] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA32,DATA32,32> data;
  // UINT32 sc_header NOENCODE
  // {
    //  0_07: empty1;
    //  8_12: nwords;
    // 13_26: empty2;
    // 27_31: geo = MATCH(15);
  // }
  // list(0<=index<sc_header.nwords)

    // UINT32 sc_data NOENCODE
    // {
      //  0_31: value;
    // }
    // ENCODE(data[index],(value=sc_data.value));

  // UINT32 scaler_trailer NOENCODE;

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(FATIMA_VME_SCALERS);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for FEBEX_EVENT.
 *
 * Do not edit - automatically generated.
 */

// FEBEX_EVENT(card)
#if !PACKER_CODE
# define DECLARED_UNPACK_FEBEX_EVENT
class FEBEX_EVENT
#else//PACKER_CODE
# define DECLARED_PACKER_FEBEX_EVENT
class PACKER_FEBEX_EVENT
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA8 trig);
  DATA8 trig;
  // MEMBER(DATA32 event_trigger_time_hi);
  DATA32 event_trigger_time_hi;
  // MEMBER(DATA32 event_trigger_time_lo);
  DATA32 event_trigger_time_lo;
  // MEMBER(DATA16 hit_pattern);
  DATA16 hit_pattern;
  // MEMBER(DATA16 channel_trigger_time_hi[16] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA16,DATA16,16> channel_trigger_time_hi;
  // MEMBER(DATA32 channel_trigger_time_lo[16] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA32,DATA32,16> channel_trigger_time_lo;
  // MEMBER(DATA8 pileup[16] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA8,DATA8,16> pileup;
  // MEMBER(DATA8 overflow[16] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA8,DATA8,16> overflow;
  // MEMBER(DATA8 channel_cfd[16] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA8,DATA8,16> channel_cfd;
  // MEMBER(DATA32 channel_energy[16] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA32,DATA32,16> channel_energy;
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

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 card);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 card);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer,uint32 card);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(FEBEX_EVENT);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for TRACE.
 *
 * Do not edit - automatically generated.
 */

// TRACE(board)
#if !PACKER_CODE
# define DECLARED_UNPACK_TRACE
class TRACE
#else//PACKER_CODE
# define DECLARED_PACKER_TRACE
class PACKER_TRACE
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA16 traces[16][4000] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA16,DATA16,4000> traces[16];
  // MEMBER(DATA8 channel_id_traces[16] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA8,DATA8,16> channel_id_traces;
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

    // UINT32 channel_trace NOENCODE
    // {
      //  0_13: data1;
      // 14_15: stuff1;
      // 16_29: data2;
      // 30_31: stuff2;
      // ENCODE(traces[header.ch_id][((2 * j) + 0)],(value=data1));
      // ENCODE(traces[header.ch_id][((2 * j) + 1)],(value=data2));
    // }
  // UINT32 trace_trailer NOENCODE
  // {
    //  0_23: notused;
    // 24_31: id = RANGE(176,191);
  // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 board);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 board);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer,uint32 board);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(TRACE);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for FEBEX_EVENT_TRACES.
 *
 * Do not edit - automatically generated.
 */

// FEBEX_EVENT_TRACES(card)
#if !PACKER_CODE
# define DECLARED_UNPACK_FEBEX_EVENT_TRACES
class FEBEX_EVENT_TRACES
#else//PACKER_CODE
# define DECLARED_PACKER_FEBEX_EVENT_TRACES
class PACKER_FEBEX_EVENT_TRACES
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA8 trig);
  DATA8 trig;
  // MEMBER(DATA32 event_trigger_time_hi);
  DATA32 event_trigger_time_hi;
  // MEMBER(DATA32 event_trigger_time_lo);
  DATA32 event_trigger_time_lo;
  // MEMBER(DATA16 hit_pattern);
  DATA16 hit_pattern;
  // MEMBER(DATA32 num_channels_fired);
  DATA32 num_channels_fired;
  // MEMBER(DATA8 board_num);
  DATA8 board_num;
  // MEMBER(DATA8 channel_id[16] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA8,DATA8,16> channel_id;
  // MEMBER(DATA16 channel_trigger_time_hi[16] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA16,DATA16,16> channel_trigger_time_hi;
  // MEMBER(DATA32 channel_trigger_time_lo[16] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA32,DATA32,16> channel_trigger_time_lo;
  // MEMBER(DATA8 pileup[16] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA8,DATA8,16> pileup;
  // MEMBER(DATA8 overflow[16] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA8,DATA8,16> overflow;
  // MEMBER(DATA8 channel_cfd[16] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA8,DATA8,16> channel_cfd;
  // MEMBER(DATA32 channel_energy[16] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA32,DATA32,16> channel_energy;
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

    // list(0<=index<((channel_size.size / 4) - 1))

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
    // list(0<=index<16)

      // select optional

        // trace = TRACE(board=card);
      SINGLE(TRACE,trace);
    // if((sumchannel.trigger_type == 3))

      // several UINT32 dummy NOENCODE;

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 card);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 card);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer,uint32 card);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(FEBEX_EVENT_TRACES);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for FEBEX_PADDING.
 *
 * Do not edit - automatically generated.
 */

// FEBEX_PADDING()
#if !PACKER_CODE
# define DECLARED_UNPACK_FEBEX_PADDING
class FEBEX_PADDING
#else//PACKER_CODE
# define DECLARED_PACKER_FEBEX_PADDING
class PACKER_FEBEX_PADDING
#endif//PACKER_CODE

{
public:
  // UINT32 pads_data NOENCODE
  // {
    //  0_11: counter;
    // 12_19: index;
    // 20_31: 0xadd;
  // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(FEBEX_PADDING);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for VME_CAEN_V830.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V830(geom)
#if !PACKER_CODE
# define DECLARED_UNPACK_VME_CAEN_V830
class VME_CAEN_V830
#else//PACKER_CODE
# define DECLARED_PACKER_VME_CAEN_V830
class PACKER_VME_CAEN_V830
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA32 data[32] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA32,DATA32,32> data;
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
  } header;
  // list(0<=index<header.count)

    // UINT32 ch_data NOENCODE
    // {
      //  0_25: value;
      //    26: 0;
      // 27_31: channel;
      // ENCODE(data[channel],(value=value));
    // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 geom);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 geom);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer,uint32 geom);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(VME_CAEN_V830);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for ZERO_FILLER.
 *
 * Do not edit - automatically generated.
 */

// ZERO_FILLER()
#if !PACKER_CODE
# define DECLARED_UNPACK_ZERO_FILLER
class ZERO_FILLER
#else//PACKER_CODE
# define DECLARED_PACKER_ZERO_FILLER
class PACKER_ZERO_FILLER
#endif//PACKER_CODE

{
public:
  // UINT32 filler NOENCODE
  // {
    //  0_31: zero = MATCH(0);
  // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(ZERO_FILLER);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for VME_CAEN_V7X5.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V7X5(geom)
#if !PACKER_CODE
# define DECLARED_UNPACK_VME_CAEN_V7X5
class VME_CAEN_V7X5
#else//PACKER_CODE
# define DECLARED_PACKER_VME_CAEN_V7X5
class PACKER_VME_CAEN_V7X5
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA24 data[32] ZERO_SUPPRESS);
  raw_array_zero_suppress<DATA24,DATA24,32> data;
  // UINT32 header NOENCODE
  // {
    //  0_07: undefined;
    //  8_13: count;
    // 16_23: crate;
    // 24_26: 2;
    // 27_31: geom = MATCH(geom);
  // }
  // list(0<=index<header.count)

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
  // UINT32 eob NOENCODE
  // {
    //  0_23: nothing;
    // 24_26: 4;
    // 27_31: id = MATCH(geom);
  // }
  // list(0<=i<2)

    // optional UINT32 eob2 NOENCODE
    // {
      //  0_23: nothing;
      // 24_26: id = MATCH(6);
      // 27_31: geom;
    // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 geom);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 geom);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer,uint32 geom);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(VME_CAEN_V7X5);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for TDC_HEADER.
 *
 * Do not edit - automatically generated.
 */

// TDC_HEADER()
#if !PACKER_CODE
# define DECLARED_UNPACK_TDC_HEADER
class TDC_HEADER
#else//PACKER_CODE
# define DECLARED_PACKER_TDC_HEADER
class PACKER_TDC_HEADER
#endif//PACKER_CODE

{
public:
  // UINT32 tdc_header NOENCODE
  // {
    //  0_11: bunch_id;
    // 12_23: event_id;
    // 24_25: tdc;
    //    26: unused;
    // 27_31: 1;
  // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(TDC_HEADER);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for TDC_DATA_V1290.
 *
 * Do not edit - automatically generated.
 */

// TDC_DATA_V1290()
#if !PACKER_CODE
# define DECLARED_UNPACK_TDC_DATA_V1290
class TDC_DATA_V1290
#else//PACKER_CODE
# define DECLARED_PACKER_TDC_DATA_V1290
class PACKER_TDC_DATA_V1290
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA24 data[128] ZERO_SUPPRESS_MULTI(128));
  raw_array_multi_zero_suppress<DATA24,DATA24,128,128> data;
  // MEMBER(DATA8 leadOrTrail[128] ZERO_SUPPRESS_MULTI(128));
  raw_array_multi_zero_suppress<DATA8,DATA8,128,128> leadOrTrail;
  // UINT32 tdc_data NOENCODE
  // {
    //  0_20: tdc;
    // 21_25: chn;
    //    26: lot;
    // 27_31: 0;
    // ENCODE(data[chn],(value=tdc));
    // ENCODE(leadOrTrail[chn],(value=lot));
  // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(TDC_DATA_V1290);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for TDC_ERROR.
 *
 * Do not edit - automatically generated.
 */

// TDC_ERROR()
#if !PACKER_CODE
# define DECLARED_UNPACK_TDC_ERROR
class TDC_ERROR
#else//PACKER_CODE
# define DECLARED_PACKER_TDC_ERROR
class PACKER_TDC_ERROR
#endif//PACKER_CODE

{
public:
  // UINT32 tdc_err NOENCODE
  // {
    //  0_14: error_flags;
    // 15_23: unused1;
    // 24_25: tdc;
    //    26: unused2;
    // 27_31: 4;
  // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(TDC_ERROR);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for TDC_TRAILER.
 *
 * Do not edit - automatically generated.
 */

// TDC_TRAILER()
#if !PACKER_CODE
# define DECLARED_UNPACK_TDC_TRAILER
class TDC_TRAILER
#else//PACKER_CODE
# define DECLARED_PACKER_TDC_TRAILER
class PACKER_TDC_TRAILER
#endif//PACKER_CODE

{
public:
  // UINT32 tdc_trailer NOENCODE
  // {
    //  0_11: word_count;
    // 12_23: event_id;
    // 24_25: tdc;
    //    26: unused;
    // 27_31: 3;
  // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(TDC_TRAILER);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for VME_CAEN_V1290_N.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V1290_N()
#if !PACKER_CODE
# define DECLARED_UNPACK_VME_CAEN_V1290_N
class VME_CAEN_V1290_N
#else//PACKER_CODE
# define DECLARED_PACKER_VME_CAEN_V1290_N
class PACKER_VME_CAEN_V1290_N
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA8 geo);
  DATA8 geo;
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
  SINGLE(TDC_HEADER,tdc_header);
  SINGLE(TDC_DATA_V1290,measurement);
  SINGLE(TDC_ERROR,tdc_err);
  SINGLE(TDC_TRAILER,tdc_trailer);
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

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(VME_CAEN_V1290_N);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for MAIN_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// MAIN_CRATE_DATA()
#if !PACKER_CODE
# define DECLARED_UNPACK_MAIN_CRATE_DATA
class MAIN_CRATE_DATA
#else//PACKER_CODE
# define DECLARED_PACKER_MAIN_CRATE_DATA
class PACKER_MAIN_CRATE_DATA
#endif//PACKER_CODE

{
public:
  // barrier0 = BARRIER();
  // v830 = VME_CAEN_V830(geom=8);
  // filler0 = ZERO_FILLER();
  // barrier1 = BARRIER();
  // v792 = VME_CAEN_V7X5(geom=14);
  // UINT32 aaahhh NOENCODE
  // {
    //  0_31: 0xaaaa1290;
  // }
  // UINT32 exxxxx NOENCODE;
  // barrier2 = BARRIER();
  // v1290 = VME_CAEN_V1290_N();
  // optional UINT32 eodb NOENCODE;
  SINGLE(BARRIER,barrier0);
  SINGLE(VME_CAEN_V830,v830);
  SINGLE(ZERO_FILLER,filler0);
  SINGLE(BARRIER,barrier1);
  SINGLE(VME_CAEN_V7X5,v792);
  SINGLE(BARRIER,barrier2);
  SINGLE(VME_CAEN_V1290_N,v1290);

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(MAIN_CRATE_DATA);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for SPILL_OFF.
 *
 * Do not edit - automatically generated.
 */

// SPILL_OFF()
#if !PACKER_CODE
# define DECLARED_UNPACK_SPILL_OFF
class SPILL_OFF
#else//PACKER_CODE
# define DECLARED_PACKER_SPILL_OFF
class PACKER_SPILL_OFF
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA8 spilloff);
  DATA8 spilloff;
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


public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(SPILL_OFF);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for SPILL_ON.
 *
 * Do not edit - automatically generated.
 */

// SPILL_ON()
#if !PACKER_CODE
# define DECLARED_UNPACK_SPILL_ON
class SPILL_ON
#else//PACKER_CODE
# define DECLARED_PACKER_SPILL_ON
class PACKER_SPILL_ON
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA8 spillon);
  DATA8 spillon;
  // UINT32 on NOENCODE
  // {
    //  0_31: 0x30303030;
  // }
  // ENCODE(spillon,(value=1));


public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(SPILL_ON);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for TAMEX4_EPOCH_DATA.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_EPOCH_DATA(sfp,card,time_coarse,time_fine,time_edge,time_channel,
                  // time_epoch)
#if !PACKER_CODE
# define DECLARED_UNPACK_TAMEX4_EPOCH_DATA
class TAMEX4_EPOCH_DATA
#else//PACKER_CODE
# define DECLARED_PACKER_TAMEX4_EPOCH_DATA
class PACKER_TAMEX4_EPOCH_DATA
#endif//PACKER_CODE

{
public:
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

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 sfp,uint32 card,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_coarse
                                      ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_fine
                                      ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_edge
                                      ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_channel
                                      ,raw_list_ii_zero_suppress<DATA32,DATA32,1024> &time_epoch);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 sfp,uint32 card);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer,uint32 sfp,uint32 card,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_coarse
                                       ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_fine
                                       ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_edge
                                       ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_channel
                                       ,raw_list_ii_zero_suppress<DATA32,DATA32,1024> &time_epoch);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(TAMEX4_EPOCH_DATA);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for TAMEX4_HEADER.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_HEADER()
#if !PACKER_CODE
# define DECLARED_UNPACK_TAMEX4_HEADER
class TAMEX4_HEADER
#else//PACKER_CODE
# define DECLARED_PACKER_TAMEX4_HEADER
class PACKER_TAMEX4_HEADER
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA16 post_trig_ns);
  DATA16 post_trig_ns;
  // MEMBER(DATA16 pre_trig_ns);
  DATA16 pre_trig_ns;
  // UINT32 trigger_window NOENCODE
  // {
    //  0_15: post_trig_ns;
    // 16_31: pre_trig_ns;
    // ENCODE(post_trig_ns,(value=post_trig_ns));
    // ENCODE(pre_trig_ns,(value=pre_trig_ns));
  // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(TAMEX4_HEADER);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for TAMEX4_PADDING.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_PADDING()
#if !PACKER_CODE
# define DECLARED_UNPACK_TAMEX4_PADDING
class TAMEX4_PADDING
#else//PACKER_CODE
# define DECLARED_PACKER_TAMEX4_PADDING
class PACKER_TAMEX4_PADDING
#endif//PACKER_CODE

{
public:
  // UINT32 padding NOENCODE
  // {
    //  0_11: counter;
    // 12_19: index;
    // 20_31: 0xadd;
  // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(TAMEX4_PADDING);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for TAMEX4_TIME_DATA.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_TIME_DATA(sfp,card,time_coarse,time_fine,time_edge,time_channel,
                 // time_epoch)
#if !PACKER_CODE
# define DECLARED_UNPACK_TAMEX4_TIME_DATA
class TAMEX4_TIME_DATA
#else//PACKER_CODE
# define DECLARED_PACKER_TAMEX4_TIME_DATA
class PACKER_TAMEX4_TIME_DATA
#endif//PACKER_CODE

{
public:
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

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 sfp,uint32 card,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_coarse
                                      ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_fine
                                      ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_edge
                                      ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_channel
                                      ,raw_list_ii_zero_suppress<DATA32,DATA32,1024> &time_epoch);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 sfp,uint32 card);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer,uint32 sfp,uint32 card,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_coarse
                                       ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_fine
                                       ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_edge
                                       ,raw_list_ii_zero_suppress<DATA12,DATA12,1024> &time_channel
                                       ,raw_list_ii_zero_suppress<DATA32,DATA32,1024> &time_epoch);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(TAMEX4_TIME_DATA);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for TAMEX4_SFP.
 *
 * Do not edit - automatically generated.
 */

// TAMEX4_SFP(sfp,card)
#if !PACKER_CODE
# define DECLARED_UNPACK_TAMEX4_SFP
class TAMEX4_SFP
#else//PACKER_CODE
# define DECLARED_PACKER_TAMEX4_SFP
class PACKER_TAMEX4_SFP
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA16 trig);
  DATA16 trig;
  // MEMBER(DATA32 event_size);
  DATA32 event_size;
  // MEMBER(DATA12 time_coarse[1024] NO_INDEX_LIST);
  raw_list_ii_zero_suppress<DATA12,DATA12,1024> time_coarse;
  // MEMBER(DATA12 time_fine[1024] NO_INDEX_LIST);
  raw_list_ii_zero_suppress<DATA12,DATA12,1024> time_fine;
  // MEMBER(DATA12 time_edge[1024] NO_INDEX_LIST);
  raw_list_ii_zero_suppress<DATA12,DATA12,1024> time_edge;
  // MEMBER(DATA12 time_channel[1024] NO_INDEX_LIST);
  raw_list_ii_zero_suppress<DATA12,DATA12,1024> time_channel;
  // MEMBER(DATA32 time_epoch[1024] NO_INDEX_LIST);
  raw_list_ii_zero_suppress<DATA32,DATA32,1024> time_epoch;
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

    // select

      // epoch = TAMEX4_EPOCH_DATA(sfp=sfp,card=card,time_coarse=time_coarse,
                                // time_fine=time_fine,time_edge=time_edge,
                                // time_channel=time_channel,time_epoch=time_epoch);
      // time = TAMEX4_TIME_DATA(sfp=sfp,card=card,time_coarse=time_coarse,
                              // time_fine=time_fine,time_edge=time_edge,
                              // time_channel=time_channel,time_epoch=time_epoch);
    SINGLE(TAMEX4_EPOCH_DATA,epoch);
    SINGLE(TAMEX4_TIME_DATA,time);
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

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 sfp,uint32 card);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 sfp,uint32 card);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer,uint32 sfp,uint32 card);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(TAMEX4_SFP);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for TDC_DATA_V1190.
 *
 * Do not edit - automatically generated.
 */

// TDC_DATA_V1190()
#if !PACKER_CODE
# define DECLARED_UNPACK_TDC_DATA_V1190
class TDC_DATA_V1190
#else//PACKER_CODE
# define DECLARED_PACKER_TDC_DATA_V1190
class PACKER_TDC_DATA_V1190
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA24 data[128] ZERO_SUPPRESS_MULTI(128));
  raw_array_multi_zero_suppress<DATA24,DATA24,128,128> data;
  // MEMBER(DATA8 leadOrTrail[128] ZERO_SUPPRESS_MULTI(128));
  raw_array_multi_zero_suppress<DATA8,DATA8,128,128> leadOrTrail;
  // UINT32 tdc_data NOENCODE
  // {
    //  0_18: tdc;
    // 19_25: chn;
    //    26: lot;
    // 27_31: 0;
    // ENCODE(data[chn],(value=tdc));
    // ENCODE(leadOrTrail[chn],(value=lot));
  // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(TDC_DATA_V1190);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for TIMESTAMP_WHITERABBIT.
 *
 * Do not edit - automatically generated.
 */

// TIMESTAMP_WHITERABBIT(id)
#if !PACKER_CODE
# define DECLARED_UNPACK_TIMESTAMP_WHITERABBIT
class TIMESTAMP_WHITERABBIT
#else//PACKER_CODE
# define DECLARED_PACKER_TIMESTAMP_WHITERABBIT
class PACKER_TIMESTAMP_WHITERABBIT
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA12 subsystem_id);
  DATA12 subsystem_id;
  // MEMBER(DATA16 t1);
  DATA16 t1;
  // MEMBER(DATA16 t2);
  DATA16 t2;
  // MEMBER(DATA16 t3);
  DATA16 t3;
  // MEMBER(DATA16 t4);
  DATA16 t4;
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

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 id);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 id);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer,uint32 id);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(TIMESTAMP_WHITERABBIT);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for TIMESTAMP_WHITERABBIT_EXTENDED.
 *
 * Do not edit - automatically generated.
 */

// TIMESTAMP_WHITERABBIT_EXTENDED(id)
#if !PACKER_CODE
# define DECLARED_UNPACK_TIMESTAMP_WHITERABBIT_EXTENDED
class TIMESTAMP_WHITERABBIT_EXTENDED
#else//PACKER_CODE
# define DECLARED_PACKER_TIMESTAMP_WHITERABBIT_EXTENDED
class PACKER_TIMESTAMP_WHITERABBIT_EXTENDED
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA16 subsystem_id);
  DATA16 subsystem_id;
  // MEMBER(DATA16 t1);
  DATA16 t1;
  // MEMBER(DATA16 t2);
  DATA16 t2;
  // MEMBER(DATA16 t3);
  DATA16 t3;
  // MEMBER(DATA16 t4);
  DATA16 t4;
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

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 id);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 id);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer,uint32 id);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(TIMESTAMP_WHITERABBIT_EXTENDED);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for TPAT_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// TPAT_CRATE_DATA()
#if !PACKER_CODE
# define DECLARED_UNPACK_TPAT_CRATE_DATA
class TPAT_CRATE_DATA
#else//PACKER_CODE
# define DECLARED_PACKER_TPAT_CRATE_DATA
class PACKER_TPAT_CRATE_DATA
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA16 tpat);
  DATA16 tpat;
  // UINT32 w1;
  uint32  w1;
  // UINT32 w2;
  uint32  w2;
  // UINT32 w3;
  uint32  w3;
  // UINT32 trigger_pattern
  // {
    //  0_15: pattern;
    // 16_31: nothing;
    // ENCODE(tpat,(value=pattern));
  // }
  union
  {
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
      uint32 pattern : 16; // 0..15
      uint32 nothing : 16; // 16..31
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
      uint32 nothing : 16; // 16..31
      uint32 pattern : 16; // 0..15
#endif
    };
    uint32  u32;
  } trigger_pattern;

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(TPAT_CRATE_DATA);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for VME_CAEN_V1190_N.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V1190_N()
#if !PACKER_CODE
# define DECLARED_UNPACK_VME_CAEN_V1190_N
class VME_CAEN_V1190_N
#else//PACKER_CODE
# define DECLARED_PACKER_VME_CAEN_V1190_N
class PACKER_VME_CAEN_V1190_N
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA8 geo);
  DATA8 geo;
  // UINT32 header NOENCODE
  // {
    //  0_04: geom;
    //  5_26: event_count;
    // 27_31: seven_f;
    // ENCODE(geo,(value=geom));
  // }
  // if((header.seven_f != 8))

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
  // select several

    // tdc_header = TDC_HEADER();
    // measurement = TDC_DATA_V1190();
    // tdc_error = TDC_ERROR();
    // tdc_trailer = TDC_TRAILER();
  SINGLE(TDC_HEADER,tdc_header);
  SINGLE(TDC_DATA_V1190,measurement);
  SINGLE(TDC_ERROR,tdc_error);
  SINGLE(TDC_TRAILER,tdc_trailer);
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

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(VME_CAEN_V1190_N);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for TPC_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// TPC_CRATE_DATA()
#if !PACKER_CODE
# define DECLARED_UNPACK_TPC_CRATE_DATA
class TPC_CRATE_DATA
#else//PACKER_CODE
# define DECLARED_PACKER_TPC_CRATE_DATA
class PACKER_TPC_CRATE_DATA
#endif//PACKER_CODE

{
public:
  // select several

    // barrier0 = BARRIER();
    // v785 = VME_CAEN_V7X5(geom=8);
    // v775 = VME_CAEN_V7X5(geom=12);
  SINGLE(BARRIER,barrier0);
  SINGLE(VME_CAEN_V7X5,v785);
  SINGLE(VME_CAEN_V7X5,v775);
  // UINT32 aaahhh NOENCODE
  // {
    //  0_31: 0xaaaa1190;
  // }
  // UINT32 exxxxx NOENCODE;
  // barrier[2] = BARRIER();
  // v1190 = VME_CAEN_V1190_N();
  SINGLE(BARRIER,barrier[3]);
  SINGLE(VME_CAEN_V1190_N,v1190);

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(TPC_CRATE_DATA);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for TRIG3EVENT.
 *
 * Do not edit - automatically generated.
 */

// TRIG3EVENT()
#if !PACKER_CODE
# define DECLARED_UNPACK_TRIG3EVENT
class TRIG3EVENT
#else//PACKER_CODE
# define DECLARED_PACKER_TRIG3EVENT
class PACKER_TRIG3EVENT
#endif//PACKER_CODE

{
public:
  // UINT32 trig3 NOENCODE
  // {
    //  0_31: 0x20202020;
  // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(TRIG3EVENT);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for USER_CRATE_DATA.
 *
 * Do not edit - automatically generated.
 */

// USER_CRATE_DATA()
#if !PACKER_CODE
# define DECLARED_UNPACK_USER_CRATE_DATA
class USER_CRATE_DATA
#else//PACKER_CODE
# define DECLARED_PACKER_USER_CRATE_DATA
class PACKER_USER_CRATE_DATA
#endif//PACKER_CODE

{
public:
  // barrier0 = BARRIER();
  // v830 = VME_CAEN_V830(geom=6);
  // filler0 = ZERO_FILLER();
  // select several

    // barrier1 = BARRIER();
    // v775[0] = VME_CAEN_V7X5(geom=8);
    // v775[1] = VME_CAEN_V7X5(geom=9);
    // v785[0] = VME_CAEN_V7X5(geom=10);
    // v785[1] = VME_CAEN_V7X5(geom=12);
  SINGLE(BARRIER,barrier1);
  SINGLE(VME_CAEN_V7X5,v775[2]);
  SINGLE(VME_CAEN_V7X5,v785[2]);
  SINGLE(BARRIER,barrier0);
  SINGLE(VME_CAEN_V830,v830);
  SINGLE(ZERO_FILLER,filler0);

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(USER_CRATE_DATA);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for VME_CAEN_V1751.
 *
 * Do not edit - automatically generated.
 */

// VME_CAEN_V1751(board)
#if !PACKER_CODE
# define DECLARED_UNPACK_VME_CAEN_V1751
class VME_CAEN_V1751
#else//PACKER_CODE
# define DECLARED_PACKER_VME_CAEN_V1751
class PACKER_VME_CAEN_V1751
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA8 board_id);
  DATA8 board_id;
  // MEMBER(DATA8 channels);
  DATA8 channels;
  // MEMBER(DATA32 board_time);
  DATA32 board_time;
  // MEMBER(DATA32 channel_time[64] NO_INDEX_LIST);
  raw_list_ii_zero_suppress<DATA32,DATA32,64> channel_time;
  // MEMBER(DATA16 chan_ext_time[64] NO_INDEX_LIST);
  raw_list_ii_zero_suppress<DATA16,DATA16,64> chan_ext_time;
  // MEMBER(DATA12 chan_fine_time[64] NO_INDEX_LIST);
  raw_list_ii_zero_suppress<DATA12,DATA12,64> chan_fine_time;
  // MEMBER(DATA16 qshort[64] NO_INDEX_LIST);
  raw_list_ii_zero_suppress<DATA16,DATA16,64> qshort;
  // MEMBER(DATA16 qlong[64] NO_INDEX_LIST);
  raw_list_ii_zero_suppress<DATA16,DATA16,64> qlong;
  // UINT32 board_agg_size NOENCODE
  // {
    //  0_27: event_size;
    // 28_31: 10;
  // }
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
  // UINT32 board_agg_counter NOENCODE
  // {
    //  0_22: counter;
    // 23_31: empty;
  // }
  // UINT32 board_agg_timetag NOENCODE
  // {
    //  0_31: time_tag;
    // ENCODE(board_time,(value=time_tag));
  // }
  // if((board_agg_size.event_size > 4))

    // list(0<=index<((board_agg_size.event_size - 4) / 6))

      // UINT32 channel_agg_size NOENCODE
      // {
        //  0_21: size;
        // 22_27: empty;
        // 28_31: format;
      // }
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
      // if((channel_agg_size.format == 4))

      // else

        // UINT32 format_two NOENCODE
        // {
          //  0_02: ex;
          //     3: pp;
          //     4: dm;
          //  5_07: interp;
          //  8_31: empty;
        // }
        // if((format_one.et == 1))

          // UINT32 channel_time_tag NOENCODE
          // {
            //  0_31: time_tag;
            // ENCODE(channel_time APPEND_LIST,(value=time_tag));
          // }
        // if(((format_one.ee == 1) && (channel_agg_size.format == 4)))

          // if((format_two.ex == 0))

          // else

            // UINT32 extras NOENCODE
            // {
              //  0_15: baseline;
              // 16_31: ext_time;
              // ENCODE(chan_ext_time APPEND_LIST,(value=ext_time));
            // }
            // if((format_two.ex == 1))

            // else

              // UINT32 extras NOENCODE
              // {
                //  0_15: flags;
                // 16_31: ext_time;
                // ENCODE(chan_ext_time APPEND_LIST,(value=ext_time));
              // }
              // if((format_two.ex == 2))

              // else

                // UINT32 extras NOENCODE
                // {
                  //  0_09: fine_time;
                  // 10_15: flags;
                  // 16_31: ext_time;
                  // ENCODE(chan_fine_time APPEND_LIST,(value=fine_time));
                  // ENCODE(chan_ext_time APPEND_LIST,(value=ext_time));
                // }
                // if((format_two.ex == 4))

                // else

                  // UINT32 extras NOENCODE
                  // {
                    //  0_15: baseline;
                    // 16_26: fine_time;
                    // 27_31: flags;
                    // ENCODE(chan_fine_time APPEND_LIST,(value=fine_time));
                  // }
                  // if((format_two.ex == 5))

                    // UINT32 extras NOENCODE
                    // {
                      //  0_09: midscale;
                      // 10_19: sazc;
                      // 20_29: sbzc;
                      //    30: pp;
                      //    31: dm;
                    // }
        // if((format_one.et == 1))

          // UINT32 channel_time_tag NOENCODE
          // {
            //  0_31: time_tag;
            // ENCODE(channel_time APPEND_LIST,(value=time_tag));
          // }
      // if((format_one.eq == 1))

        // UINT32 qdata NOENCODE
        // {
          //  0_14: qshort;
          //    15: empty;
          // 16_31: qlong;
          // ENCODE(qshort APPEND_LIST,(value=qshort));
          // ENCODE(qlong APPEND_LIST,(value=qlong));
        // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer,uint32 board);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer,uint32 board);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer,uint32 board);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(VME_CAEN_V1751);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for WR_MULTI.
 *
 * Do not edit - automatically generated.
 */

// WR_MULTI()
#if !PACKER_CODE
# define DECLARED_UNPACK_WR_MULTI
class WR_MULTI
#else//PACKER_CODE
# define DECLARED_PACKER_WR_MULTI
class PACKER_WR_MULTI
#endif//PACKER_CODE

{
public:
  // MEMBER(DATA32 time_hi);
  DATA32 time_hi;
  // MEMBER(DATA32 time_lo);
  DATA32 time_lo;
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

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(WR_MULTI);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for aida_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(aida_subev)
#if !PACKER_CODE
# define DECLARED_UNPACK_aida_subev
class aida_subev
#else//PACKER_CODE
# define DECLARED_PACKER_aida_subev
class PACKER_aida_subev
#endif//PACKER_CODE
 : public unpack_subevent_base
{
public:
  // ts = TIMESTAMP_WHITERABBIT(id=0x700);
  // external data = EXT_AIDA();
  SINGLE(TIMESTAMP_WHITERABBIT,ts);
  SINGLE(EXT_AIDA,data);

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(aida_subev);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for bgo_tamex_subevent.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(bgo_tamex_subevent)
#if !PACKER_CODE
# define DECLARED_UNPACK_bgo_tamex_subevent
class bgo_tamex_subevent
#else//PACKER_CODE
# define DECLARED_PACKER_bgo_tamex_subevent
class PACKER_bgo_tamex_subevent
#endif//PACKER_CODE
 : public unpack_subevent_base
{
public:
  // select optional

    // ts = TIMESTAMP_WHITERABBIT_EXTENDED(id=0x1900);
  SINGLE(TIMESTAMP_WHITERABBIT_EXTENDED,ts);
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
  } be;
  // select optional

    // trigger_window = TAMEX4_HEADER();
  SINGLE(TAMEX4_HEADER,trigger_window);
  // select several

    // padding = TAMEX4_PADDING();
  SINGLE(TAMEX4_PADDING,padding);
  // select several

    // tamex[0] = TAMEX4_SFP(sfp=1,card=0);
    // tamex[1] = TAMEX4_SFP(sfp=1,card=1);
    // tamex[2] = TAMEX4_SFP(sfp=1,card=2);
  SINGLE(TAMEX4_SFP,tamex[3]);

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(bgo_tamex_subevent);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for bm_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(bm_subev)
#if !PACKER_CODE
# define DECLARED_UNPACK_bm_subev
class bm_subev
#else//PACKER_CODE
# define DECLARED_PACKER_bm_subev
class PACKER_bm_subev
#endif//PACKER_CODE
 : public unpack_subevent_base
{
public:
  // MEMBER(DATA32 dataS2[100000] NO_INDEX_LIST);
  raw_list_ii_zero_suppress<DATA32,DATA32,100000> dataS2;
  // MEMBER(DATA32 dataS4[100000] NO_INDEX_LIST);
  raw_list_ii_zero_suppress<DATA32,DATA32,100000> dataS4;
  // select optional

    // ts = TIMESTAMP_WHITERABBIT_EXTENDED(id=0x1700);
  SINGLE(TIMESTAMP_WHITERABBIT_EXTENDED,ts);
  // UINT32 headS2 NOENCODE
  // {
    //  0_12: l_hit_ct;
    // 13_15: reserved;
    // 16_31: l_id = MATCH(0xaaaa);
  // }
  // list(0<=l_i<headS2.l_hit_ct)

    // UINT32 hit NOENCODE
    // {
      //  0_31: data;
      // ENCODE(dataS2 APPEND_LIST,(value=data));
    // }
  // UINT32 headS4 NOENCODE
  // {
    //  0_12: l_hit_ct;
    // 13_15: reserved;
    // 16_31: l_id = MATCH(0xbbbb);
  // }
  // list(0<=l_i<headS4.l_hit_ct)

    // UINT32 hit NOENCODE
    // {
      //  0_31: data;
      // ENCODE(dataS4 APPEND_LIST,(value=data));
    // }
  // UINT32 trailer NOENCODE
  // {
    //  0_15: reserved;
    // 16_31: l_id = MATCH(0xcccc);
  // }

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(bm_subev);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for bplast_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(bplast_subev)
#if !PACKER_CODE
# define DECLARED_UNPACK_bplast_subev
class bplast_subev
#else//PACKER_CODE
# define DECLARED_PACKER_bplast_subev
class PACKER_bplast_subev
#endif//PACKER_CODE
 : public unpack_subevent_base
{
public:
  // select optional

    // ts = TIMESTAMP_WHITERABBIT(id=0x500);
  SINGLE(TIMESTAMP_WHITERABBIT,ts);
  // select optional

    // trigger_window = TAMEX4_HEADER();
  SINGLE(TAMEX4_HEADER,trigger_window);
  // select several

    // padding = TAMEX4_PADDING();
  SINGLE(TAMEX4_PADDING,padding);
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
  SINGLE(TAMEX4_SFP,tamex[9]);

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(bplast_subev);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for fatima_tamex_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(fatima_tamex_subev)
#if !PACKER_CODE
# define DECLARED_UNPACK_fatima_tamex_subev
class fatima_tamex_subev
#else//PACKER_CODE
# define DECLARED_PACKER_fatima_tamex_subev
class PACKER_fatima_tamex_subev
#endif//PACKER_CODE
 : public unpack_subevent_base
{
public:
  // select optional

    // ts = TIMESTAMP_WHITERABBIT_EXTENDED(id=0x1600);
  SINGLE(TIMESTAMP_WHITERABBIT_EXTENDED,ts);
  // select optional

    // trigger_window = TAMEX4_HEADER();
  SINGLE(TAMEX4_HEADER,trigger_window);
  // select several

    // padding = TAMEX4_PADDING();
  SINGLE(TAMEX4_PADDING,padding);
  // select several

    // tamex[0] = TAMEX4_SFP(sfp=0,card=0);
    // tamex[1] = TAMEX4_SFP(sfp=0,card=1);
    // tamex[2] = TAMEX4_SFP(sfp=0,card=2);
    // tamex[3] = TAMEX4_SFP(sfp=0,card=3);
  SINGLE(TAMEX4_SFP,tamex[4]);

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(fatima_tamex_subev);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for fatima_vme_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(fatima_vme_subev)
#if !PACKER_CODE
# define DECLARED_UNPACK_fatima_vme_subev
class fatima_vme_subev
#else//PACKER_CODE
# define DECLARED_PACKER_fatima_vme_subev
class PACKER_fatima_vme_subev
#endif//PACKER_CODE
 : public unpack_subevent_base
{
public:
  // select optional

    // ts = TIMESTAMP_WHITERABBIT_EXTENDED(id=0x1500);
  SINGLE(TIMESTAMP_WHITERABBIT_EXTENDED,ts);
  // select several

    // error1 = ERR_WORD_SIX();
  SINGLE(ERR_WORD_SIX,error1);
  // select optional

    // scalers = FATIMA_VME_SCALERS();
  SINGLE(FATIMA_VME_SCALERS,scalers);
  // select optional

    // qdc1 = VME_CAEN_V1751(board=6);
  SINGLE(VME_CAEN_V1751,qdc1);
  // select optional

    // qdc2 = VME_CAEN_V1751(board=7);
  SINGLE(VME_CAEN_V1751,qdc2);
  // select optional

    // qdc3 = VME_CAEN_V1751(board=8);
  SINGLE(VME_CAEN_V1751,qdc3);
  // select optional

    // qdc4 = VME_CAEN_V1751(board=9);
  SINGLE(VME_CAEN_V1751,qdc4);
  // select optional

    // qdc5 = VME_CAEN_V1751(board=10);
  SINGLE(VME_CAEN_V1751,qdc5);
  // select several

    // error2 = ERR_WORD_SIX();
  SINGLE(ERR_WORD_SIX,error2);
  // select optional

    // tdc1 = VME_CAEN_V1290_N();
  SINGLE(VME_CAEN_V1290_N,tdc1);
  // select several

    // error3 = ERR_WORD_SIX();
  SINGLE(ERR_WORD_SIX,error3);
  // select optional

    // tdc2 = VME_CAEN_V1290_N();
  SINGLE(VME_CAEN_V1290_N,tdc2);

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(fatima_vme_subev);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for febex_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(febex_subev)
#if !PACKER_CODE
# define DECLARED_UNPACK_febex_subev
class febex_subev
#else//PACKER_CODE
# define DECLARED_PACKER_febex_subev
class PACKER_febex_subev
#endif//PACKER_CODE
 : public unpack_subevent_base
{
public:
  // select optional

    // ts = TIMESTAMP_WHITERABBIT(id=0x400);
  SINGLE(TIMESTAMP_WHITERABBIT,ts);
  // select several

    // padding = FEBEX_PADDING();
  SINGLE(FEBEX_PADDING,padding);
  // select several

    // data[0] = FEBEX_EVENT(card=0);
    // data[1] = FEBEX_EVENT(card=1);
    // data[2] = FEBEX_EVENT(card=2);
    // data[3] = FEBEX_EVENT(card=3);
  SINGLE(FEBEX_EVENT,data[4]);

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(febex_subev);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for frs_main_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_main_subev)
#if !PACKER_CODE
# define DECLARED_UNPACK_frs_main_subev
class frs_main_subev
#else//PACKER_CODE
# define DECLARED_PACKER_frs_main_subev
class PACKER_frs_main_subev
#endif//PACKER_CODE
 : public unpack_subevent_base
{
public:
  // select several

    // trig3 = TRIG3EVENT();
  SINGLE(TRIG3EVENT,trig3);
  // select several

    // spill_on = SPILL_ON();
  SINGLE(SPILL_ON,spill_on);
  // select several

    // spill_off = SPILL_OFF();
  SINGLE(SPILL_OFF,spill_off);
  // select optional

    // data = MAIN_CRATE_DATA();
  SINGLE(MAIN_CRATE_DATA,data);

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(frs_main_subev);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for frs_tpat_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_tpat_subev)
#if !PACKER_CODE
# define DECLARED_UNPACK_frs_tpat_subev
class frs_tpat_subev
#else//PACKER_CODE
# define DECLARED_PACKER_frs_tpat_subev
class PACKER_frs_tpat_subev
#endif//PACKER_CODE
 : public unpack_subevent_base
{
public:
  // select optional

    // wr = TIMESTAMP_WHITERABBIT(id=0x100);
  SINGLE(TIMESTAMP_WHITERABBIT,wr);
  // select several

    // trig3 = TRIG3EVENT();
  SINGLE(TRIG3EVENT,trig3);
  // select optional

    // data = TPAT_CRATE_DATA();
  SINGLE(TPAT_CRATE_DATA,data);

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(frs_tpat_subev);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for frs_tpc_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_tpc_subev)
#if !PACKER_CODE
# define DECLARED_UNPACK_frs_tpc_subev
class frs_tpc_subev
#else//PACKER_CODE
# define DECLARED_PACKER_frs_tpc_subev
class PACKER_frs_tpc_subev
#endif//PACKER_CODE
 : public unpack_subevent_base
{
public:
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
  } be;
  // select several

    // trig3 = TRIG3EVENT();
  SINGLE(TRIG3EVENT,trig3);
  // select several

    // spill_on = SPILL_ON();
  SINGLE(SPILL_ON,spill_on);
  // select several

    // spill_off = SPILL_OFF();
  SINGLE(SPILL_OFF,spill_off);
  // select optional

    // data = TPC_CRATE_DATA();
  SINGLE(TPC_CRATE_DATA,data);

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(frs_tpc_subev);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for frs_user_subev.
 *
 * Do not edit - automatically generated.
 */

// SUBEVENT(frs_user_subev)
#if !PACKER_CODE
# define DECLARED_UNPACK_frs_user_subev
class frs_user_subev
#else//PACKER_CODE
# define DECLARED_PACKER_frs_user_subev
class PACKER_frs_user_subev
#endif//PACKER_CODE
 : public unpack_subevent_base
{
public:
  // select several

    // trig3 = TRIG3EVENT();
  SINGLE(TRIG3EVENT,trig3);
  // select several

    // spill_on = SPILL_ON();
  SINGLE(SPILL_ON,spill_on);
  // select several

    // spill_off = SPILL_OFF();
  SINGLE(SPILL_OFF,spill_off);
  // select optional

    // data = USER_CRATE_DATA();
  SINGLE(USER_CRATE_DATA,data);

public:
#ifndef __PSDC__
# if !PACKER_CODE
template<typename __data_src_t>
  void __unpack(__data_src_t &__buffer);
template<typename __data_src_t>
  static bool __match(__data_src_t &__buffer);
  // void __clean();
# else//PACKER_CODE
template<typename __data_dest_t>
  void __packer(__data_dest_t &__buffer);
# endif//PACKER_CODE

  STRUCT_FCNS_DECL(frs_user_subev);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for EVENT.
 *
 * Do not edit - automatically generated.
 */

// EVENT
class unpack_event : public unpack_event_base
{
public:
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
SINGLE(aida_subev,aida);
SINGLE(febex_subev,germanium);
SINGLE(fatima_tamex_subev,fatima);
SINGLE(fatima_vme_subev,fatimavme);
SINGLE(bplast_subev,bplast);
SINGLE(bgo_tamex_subevent,bgo);
SINGLE(frs_main_subev,frsmain);
SINGLE(frs_tpc_subev,frstpc);
SINGLE(frs_user_subev,frsuser);
SINGLE(frs_tpat_subev,frstpat);
SINGLE(bm_subev,beammonitor);
public:
#ifndef __PSDC__
  bitsone<12> __visited;
  void __clear_visited() { __visited.clear(); }
  bool ignore_unknown_subevent() { return true; }
#endif//!__PSDC__

public:
#ifndef __PSDC__
template<typename __data_src_t>
  int __unpack_subevent(subevent_header *__header,__data_src_t &__buffer);
  int __revoke_subevent(subevent_header *__header);
  // void __clean_event();

  STRUCT_FCNS_DECL(unpack_event);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
/** BEGIN_STRUCTURES ***************************************************
 *
 * Event unpacker associated structures for EVENT.
 *
 * Do not edit - automatically generated.
 */

// STICKY_EVENT
class unpack_sticky_event : public unpack_sticky_event_base
{
public:
public:
#ifndef __PSDC__
  void __clear_visited() { }
  bool ignore_unknown_subevent() { return false; }
#endif//!__PSDC__

public:
#ifndef __PSDC__
template<typename __data_src_t>
  int __unpack_subevent(subevent_header *__header,__data_src_t &__buffer);
  int __revoke_subevent(subevent_header *__header);
  // void __clean_event();

  STRUCT_FCNS_DECL(unpack_sticky_event);
#endif//!__PSDC__
};

/** END_STRUCTURES ****************************************************/
