
#include "End_of_Information_Decoder.h"
#include "Bitstream_Read.h"

int End_of_Information_Decoder(Bitstream* stream, End_of_Information_Core* p)
{
    if (NormalBitstream(stream, END_OF_INFORMATION_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;



	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}
