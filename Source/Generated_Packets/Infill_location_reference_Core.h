
#ifndef INFILL_LOCATION_REFERENCE_CORE_H_INCLUDED
#define INFILL_LOCATION_REFERENCE_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct Infill_location_reference_Core
{
    // TransmissionMedia=Balise, Loop, RIU
    // Defines location reference for all data contained in the same radio
    // message or balise/loop telegram respectively, following this packet.   
    // Packet Number = 136

    uint32_t  Q_DIR;            // # 2
    uint16_t  L_PACKET;         // # 13
    uint32_t  Q_NEWCOUNTRY;     // # 1
    uint16_t  NID_C;            // # 10
    uint16_t  NID_BG;           // # 14
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const Infill_location_reference_Core& p)
{
    stream 
       << +p.Q_DIR << ','
       << +p.L_PACKET << ','
       << +p.Q_NEWCOUNTRY << ','
       << +p.NID_C << ','
       << +p.NID_BG;

    return stream;
}

inline bool operator==(const Infill_location_reference_Core& a, const Infill_location_reference_Core& b)
{
    bool status = true;
    
    status = status && (a.Q_DIR == b.Q_DIR);
    status = status && (a.L_PACKET == b.L_PACKET);
    status = status && (a.Q_NEWCOUNTRY == b.Q_NEWCOUNTRY);
    if (a.Q_NEWCOUNTRY == 1)
    {
    status = status && (a.NID_C == b.NID_C);
    }
    status = status && (a.NID_BG == b.NID_BG);

    return status;
}

inline bool operator!=(const Infill_location_reference_Core& a, const Infill_location_reference_Core& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct Infill_location_reference_Core Infill_location_reference_Core;

#define INFILL_LOCATION_REFERENCE_CORE_BITSIZE 3866

/*@
    logic integer BitSize{L}(Infill_location_reference_Core* p) = INFILL_LOCATION_REFERENCE_CORE_BITSIZE;

    logic integer MaxBitSize{L}(Infill_location_reference_Core* p) = BitSize(p);

    predicate Separated(Bitstream* stream, Infill_location_reference_Core* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(Infill_location_reference_Core* p) = \true;

    predicate ZeroInitialized(Infill_location_reference_Core* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, Infill_location_reference_Core* p) = \true;

    predicate UpperBitsNotSet(Infill_location_reference_Core* p) = \true;

*/

#endif // INFILL_LOCATION_REFERENCE_CORE_H_INCLUDED

