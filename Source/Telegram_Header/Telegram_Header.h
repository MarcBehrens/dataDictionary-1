
#ifndef TELEGRAM_HEADER_H_INCLUDED
#define TELEGRAM_HEADER_H_INCLUDED

#include "Bitstream.h"

struct Telegram_Header
{

    uint32_t  Q_UPDOWN;         // # 1
    uint8_t   M_VERSION;        // # 7
    uint32_t  Q_MEDIA;          // # 1
    uint8_t   N_PIG;            // # 3
    uint8_t   N_TOTAL;          // # 3
    uint8_t   M_DUP;            // # 2
    uint8_t   M_MCOUNT;         // # 8
    uint16_t  NID_C;            // # 10
    uint16_t  NID_BG;           // # 14
    uint32_t  Q_LINK;           // # 1
};

#ifdef __cplusplus

#include <iostream>

inline std::ostream& operator<< (std::ostream& stream, const Telegram_Header& p)
{
   stream << '('
          << uint64_t(p.Q_UPDOWN) << ','
          << uint64_t(p.M_VERSION) << ','
          << uint64_t(p.Q_MEDIA) << ','
          << uint64_t(p.N_PIG) << ','
          << uint64_t(p.N_TOTAL) << ','
          << uint64_t(p.M_DUP) << ','
          << uint64_t(p.M_MCOUNT) << ','
          << uint64_t(p.NID_C) << ','
          << uint64_t(p.NID_BG) << ','
          << uint64_t(p.Q_LINK) << ')';
   
    return stream;
}

inline bool operator==(const Telegram_Header& a, const Telegram_Header& b)
{
   return (a.Q_UPDOWN == b.Q_UPDOWN) &&
          (a.M_VERSION == b.M_VERSION) &&
          (a.Q_MEDIA == b.Q_MEDIA) &&
          (a.N_PIG == b.N_PIG) &&
          (a.N_TOTAL == b.N_TOTAL) &&
          (a.M_DUP == b.M_DUP) &&
          (a.M_MCOUNT == b.M_MCOUNT) &&
          (a.NID_C == b.NID_C) &&
          (a.NID_BG == b.NID_BG) &&
          (a.Q_LINK == b.Q_LINK);
}

inline bool operator!=(const Telegram_Header& a, const Telegram_Header& b)
{
    return !(a == b);
}

#endif // __cplusplus


typedef struct Telegram_Header Telegram_Header;

#define TELEGRAM_HEADER_BITSIZE 50

/*@
    logic integer BitSize{L}(Telegram_Header* p) = TELEGRAM_HEADER_BITSIZE;

    logic integer MaxBitSize{L}(Telegram_Header* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Telegram_Header* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Telegram_Header* p) =
      Invariant(p->Q_UPDOWN)       &&
      Invariant(p->M_VERSION)      &&
      Invariant(p->Q_MEDIA)        &&
      Invariant(p->N_PIG)          &&
      Invariant(p->N_TOTAL)        &&
      Invariant(p->M_DUP)          &&
      Invariant(p->M_MCOUNT)       &&
      Invariant(p->NID_C)          &&
      Invariant(p->NID_BG)         &&
      Invariant(p->Q_LINK);

    predicate ZeroInitialized(Telegram_Header* p) =
      ZeroInitialized(p->Q_UPDOWN)       &&
      ZeroInitialized(p->M_VERSION)      &&
      ZeroInitialized(p->Q_MEDIA)        &&
      ZeroInitialized(p->N_PIG)          &&
      ZeroInitialized(p->N_TOTAL)        &&
      ZeroInitialized(p->M_DUP)          &&
      ZeroInitialized(p->M_MCOUNT)       &&
      ZeroInitialized(p->NID_C)          &&
      ZeroInitialized(p->NID_BG)         &&
      ZeroInitialized(p->Q_LINK);

    predicate EqualBits(Bitstream* stream, integer pos, Telegram_Header* p) =
      EqualBits(stream, pos,      pos + 1,  p->Q_UPDOWN)  &&
      EqualBits(stream, pos + 1,  pos + 8,  p->M_VERSION) &&
      EqualBits(stream, pos + 8,  pos + 9,  p->Q_MEDIA)   &&
      EqualBits(stream, pos + 9,  pos + 12, p->N_PIG)     &&
      EqualBits(stream, pos + 12, pos + 15, p->N_TOTAL)   &&
      EqualBits(stream, pos + 15, pos + 17, p->M_DUP)     &&
      EqualBits(stream, pos + 17, pos + 25, p->M_MCOUNT)  &&
      EqualBits(stream, pos + 25, pos + 35, p->NID_C)     &&
      EqualBits(stream, pos + 35, pos + 49, p->NID_BG)    &&
      EqualBits(stream, pos + 49, pos + 50, p->Q_LINK);

    predicate UpperBitsNotSet(Telegram_Header* p) =
      UpperBitsNotSet(p->Q_UPDOWN,  1)      &&
      UpperBitsNotSet(p->M_VERSION, 7)      &&
      UpperBitsNotSet(p->Q_MEDIA,   1)      &&
      UpperBitsNotSet(p->N_PIG,     3)      &&
      UpperBitsNotSet(p->N_TOTAL,   3)      &&
      UpperBitsNotSet(p->M_DUP,     2)      &&
      UpperBitsNotSet(p->M_MCOUNT,  8)      &&
      UpperBitsNotSet(p->NID_C,     10)     &&
      UpperBitsNotSet(p->NID_BG,    14)     &&
      UpperBitsNotSet(p->Q_LINK,    1);

*/

#endif // TELEGRAM_HEADER_H_INCLUDED
