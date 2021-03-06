
#include "Bitwalker_Peek_Normal.h"
#include "Bitwalker_Poke_Normal.h"

/*@
    requires valid:      Writeable(addr, size);
    requires invariant:  BitwalkerInvariant(size, bitpos, length);
    requires normal:     NormalBitwalker(size, bitpos, length);
    requires upper:      UpperBitsNotSet(value, length);

    assigns addr[0..size-1];

    ensures result_value:  EqualBits64(\result, value);
*/
uint64_t Bitwalker_PokeThenPeek(uint8_t* addr, uint32_t size,
                                uint32_t bitpos, uint32_t length, uint64_t value)
{
    Bitwalker_Poke_Normal(addr, size, bitpos, length, value);

    uint64_t result = Bitwalker_Peek_Normal(addr, size, bitpos, length);

    //@ assert partial_copy: EqualBits64(result, value, 0, length);
    //@ assert full_copy:    EqualBits64(result, value);

    return result;
}

