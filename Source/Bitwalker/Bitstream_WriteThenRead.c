
#include "Bitstream_Read.h"
#include "Bitstream_Write.h"

/*@
   lemma LeftRight64:
     \forall uint64_t x, y, integer first, last;
     LeftEqualBits64(x, y, first, last) ==> EqualBits64(x, y, 64-last, 64-first);

*/

/*@
    requires valid:      Writeable(stream);
    requires invariant:  Invariant(stream, length);
    requires normal:     Normal(stream, length);
    requires upper:      UpperBitsNotSet(value, length);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;

    ensures result_value:  EqualBits64(\result, value);
*/
uint64_t Bitstream_WriteThenRead(Bitstream* stream, uint32_t length, uint64_t value)
{
    //@ ghost uint32_t pos = stream->bitpos;
    Bitstream_Write(stream, length, value);
    //@ assert equal:  EqualBits(stream, pos, pos+length, value);

    stream->bitpos -= length;
    //@ assert stream->bitpos == \at(stream->bitpos,Pre);

    uint64_t result = Bitstream_Read(stream, length);
    //@ assert equal:  EqualBits(stream, pos, pos+length, result);

    //@ assert left:         LeftEqualBits64(result, value, 64-length, 64);
    //@ assert partial_copy: EqualBits64(result, value, 0, length);
    //@ assert full_copy:    EqualBits64(result, value);

    return result;
}

