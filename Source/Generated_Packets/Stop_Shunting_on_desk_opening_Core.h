
#ifndef STOP_SHUNTING_ON_DESK_OPENING_CORE_H_INCLUDED
#define STOP_SHUNTING_ON_DESK_OPENING_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Stop_Shunting_on_desk_opening_Core
{
    // TransmissionMedia=Balise
    // Packet to stop Shunting on desk opening.    
    // Packet Number = 135

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Stop_Shunting_on_desk_opening_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET;

    return stream;
}

inline bool operator==(const Stop_Shunting_on_desk_opening_Core& a, const Stop_Shunting_on_desk_opening_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);

    return status;
}

inline bool operator!=(const Stop_Shunting_on_desk_opening_Core& a, const Stop_Shunting_on_desk_opening_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Stop_Shunting_on_desk_opening_Core Stop_Shunting_on_desk_opening_Core;

#define STOP_SHUNTING_ON_DESK_OPENING_CORE_BITSIZE 3826

/*@
    logic integer BitSize{L}(Stop_Shunting_on_desk_opening_Core* p) = STOP_SHUNTING_ON_DESK_OPENING_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Stop_Shunting_on_desk_opening_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Stop_Shunting_on_desk_opening_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Stop_Shunting_on_desk_opening_Core* p) = \true;

    predicate ZeroInitialized(Stop_Shunting_on_desk_opening_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Stop_Shunting_on_desk_opening_Core* p) = \true;

    predicate UpperBitsNotSet(Stop_Shunting_on_desk_opening_Core* p) = \true;

*/

#endif // STOP_SHUNTING_ON_DESK_OPENING_CORE_H_INCLUDED

