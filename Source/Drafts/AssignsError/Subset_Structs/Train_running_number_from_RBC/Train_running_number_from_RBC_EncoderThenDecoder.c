
#include "Train_running_number_from_RBC_Decoder.h"
#include "Train_running_number_from_RBC_Encoder.h"

/*@
    requires valid_stream:      Writeable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires normal:            Normal(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires invariant:         Invariant(p);
    requires upper:             UpperBitsNotSet(p);
    requires separation:        Separated(stream, p);

    assigns stream->addr[0..stream->size-1];
    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:   *p == \old(*p);
*/
void Train_running_number_from_RBC_EncoderThenDecoder(Bitstream* stream, Train_running_number_from_RBC* p)
{
    const uint32_t length = TRAIN_RUNNING_NUMBER_FROM_RBC_BITSIZE;
    //@ ghost uint32_t pos = stream->bitpos;

    //@ assert Normal(stream, length);
    Train_running_number_from_RBC_Encoder(stream, p);

    //@ assert left:    Unchanged{Here,Pre}(stream, 0, pos);
    //@ assert middle:  EqualBits(stream, pos, p);
    //@ assert right:   Unchanged{Here,Pre}(stream, pos + length, 8 * stream->size);

    stream->bitpos -= length;
    //@ assert stream->bitpos == pos;
    //@ assert Normal(stream, length);

    /*@
        assigns *p;

	ensures equal: EqualBits(stream, pos, p);
	ensures upper: UpperBitsNotSet(p);
    */
    Train_running_number_from_RBC_Decoder(stream, p);

}

