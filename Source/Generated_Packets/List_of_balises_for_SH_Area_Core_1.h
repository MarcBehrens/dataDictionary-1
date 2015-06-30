
#ifndef LIST_OF_BALISES_FOR_SH_AREA_CORE_1_CORE_H_INCLUDED
#define LIST_OF_BALISES_FOR_SH_AREA_CORE_1_CORE_H_INCLUDED

#include "Bitstream.h"
#include <iostream>

struct List_of_balises_for_SH_Area_Core_1
{

    uint8_t   Q_NEWCOUNTRY_k;   // # 1
    uint16_t  NID_C_k;          // # 10
    uint16_t  NID_BG_k;         // # 14
};

#ifdef __cplusplus

inline std::ostream& operator<<(std::ostream& stream, const List_of_balises_for_SH_Area_Core_1& p)
{
    stream 
       << +p.Q_NEWCOUNTRY_k << ','
       << +p.NID_C_k << ','
       << +p.NID_BG_k;

    return stream;
}

inline bool operator==(const List_of_balises_for_SH_Area_Core_1& a, const List_of_balises_for_SH_Area_Core_1& b)
{
    bool status = true;
    
    status = status && (a.Q_NEWCOUNTRY_k == b.Q_NEWCOUNTRY_k);
    if (a.Q_NEWCOUNTRY_k == 1)
    {
    status = status && (a.NID_C_k == b.NID_C_k);
    }
    status = status && (a.NID_BG_k == b.NID_BG_k);

    return status;
}

inline bool operator!=(const List_of_balises_for_SH_Area_Core_1& a, const List_of_balises_for_SH_Area_Core_1& b)
{
    return !(a == b);
}

#endif // __cplusplus

typedef struct List_of_balises_for_SH_Area_Core_1 List_of_balises_for_SH_Area_Core_1;

#define LIST_OF_BALISES_FOR_SH_AREA_CORE_1_CORE_BITSIZE 1781

/*@
    logic integer BitSize{L}(List_of_balises_for_SH_Area_Core_1* p) = LIST_OF_BALISES_FOR_SH_AREA_CORE_1_CORE_BITSIZE;

    logic integer MaxBitSize{L}(List_of_balises_for_SH_Area_Core_1* p) = BitSize(p);

    predicate Separated(Bitstream* stream, List_of_balises_for_SH_Area_Core_1* p) =
      \separated(stream, p) &&
      \separated(stream->addr + (0..stream->size-1), p);

    predicate Invariant(List_of_balises_for_SH_Area_Core_1* p) = \true;

    predicate ZeroInitialized(List_of_balises_for_SH_Area_Core_1* p) = \true;

    predicate EqualBits(Bitstream* stream, integer pos, List_of_balises_for_SH_Area_Core_1* p) = \true;

    predicate UpperBitsNotSet(List_of_balises_for_SH_Area_Core_1* p) = \true;

*/

#endif // LIST_OF_BALISES_FOR_SH_AREA_CORE_1_CORE_H_INCLUDED

