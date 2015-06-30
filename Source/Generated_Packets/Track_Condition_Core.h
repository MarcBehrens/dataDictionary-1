
#ifndef TRACK_CONDITION_CORE_H_INCLUDED
#define TRACK_CONDITION_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>
#include "Track_Condition_Core_1.h"

struct Track_Condition_Core
{
    // TransmissionMedia=Any
    // The packet gives details concerning the track ahead to support the
    // driver when e.g. lower pantograph      
    // Packet Number = 68

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_SCALE;          // # 2
    uint32_t  Q_TRACKINIT;      // # 1
    uint16_t  D_TRACKINIT;      // # 15
    uint16_t  D_TRACKCOND;      // # 15
    uint16_t  L_TRACKCOND;      // # 15
    uint32_t  M_TRACKCOND;      // # 4
    uint8_t   N_ITER_1;         // # 5
    Track_Condition_Core_1   sub_1[31];
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Track_Condition_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_SCALE << ','
       << +p.Q_TRACKINIT << ','
       << +p.D_TRACKINIT << ','
       << +p.D_TRACKCOND << ','
       << +p.L_TRACKCOND << ','
       << +p.M_TRACKCOND << ','
       << +p.N_ITER_1;
       for (uint32_t i = 0; i < p.N_ITER_1; ++i)
       {
           stream << ',' << p.sub_1[i];
       }
   

    return stream;
}

inline bool operator==(const Track_Condition_Core& a, const Track_Condition_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_SCALE == b.Q_SCALE);
    status = status && (a.Q_TRACKINIT == b.Q_TRACKINIT);
    if (a.Q_TRACKINIT == 1)
    {
    status = status && (a.D_TRACKINIT == b.D_TRACKINIT);
    }
    if (a.Q_TRACKINIT == 0)
    {
    status = status && (a.D_TRACKCOND == b.D_TRACKCOND);
    status = status && (a.L_TRACKCOND == b.L_TRACKCOND);
    status = status && (a.M_TRACKCOND == b.M_TRACKCOND);
    if (a.N_ITER_1 == b.N_ITER_1)
    {
        for (uint32_t i = 0; i < a.N_ITER_1; ++i)
        {
            status = status && (a.sub_1[i] == b.sub_1[i]);
        }
    }
    else
    {
        status = false;
    }
    }

    return status;
}

inline bool operator!=(const Track_Condition_Core& a, const Track_Condition_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Track_Condition_Core Track_Condition_Core;

#define TRACK_CONDITION_CORE_BITSIZE 2506

/*@
    logic integer BitSize{L}(Track_Condition_Core* p) = TRACK_CONDITION_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Track_Condition_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Track_Condition_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Track_Condition_Core* p) = \true;

    predicate ZeroInitialized(Track_Condition_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Track_Condition_Core* p) = \true;

    predicate UpperBitsNotSet(Track_Condition_Core* p) = \true;

*/

#endif // TRACK_CONDITION_CORE_H_INCLUDED

