
#ifndef PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_DECODER_H_INCLUDED
#define PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_DECODER_H_INCLUDED

#include "Packet_for_sending_fixed_text_messages_Core.h"

/*@
    requires valid_stream:      Readable(stream);
    requires stream_invariant:  Invariant(stream, MaxBitSize(p));
    requires valid_package:     \valid(p);
    requires separation:        Separated(stream, p);

    assigns stream->bitpos;
    assigns *p;

    ensures unchanged:          Unchanged{Here,Old}(stream, 0, 8*stream->size);

    behavior normal_case:
      assumes Normal{Pre}(stream, MaxBitSize(p));

      assigns stream->bitpos;
      assigns *p;

      ensures invariant:  Invariant(p);
      ensures result:     \result == 1; 
      ensures increment:  stream->bitpos == \old(stream->bitpos) + BitSize(p);
      ensures equal:      EqualBits(stream, \old(stream->bitpos), p);
      ensures upper:      UpperBitsNotSet(p);

    behavior error_case:
      assumes !Normal{Pre}(stream, MaxBitSize(p));

      assigns \nothing;

      ensures result: \result == 0;

    complete behaviors;
    disjoint behaviors;
*/
int Packet_for_sending_fixed_text_messages_Decoder(Bitstream* stream, Packet_for_sending_fixed_text_messages_Core* p);


#endif // PACKET_FOR_SENDING_FIXED_TEXT_MESSAGES_DECODER_H_INCLUDED

