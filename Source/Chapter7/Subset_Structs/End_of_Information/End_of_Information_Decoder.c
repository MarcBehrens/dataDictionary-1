
#include "End_of_Information_Decoder.h"
#include "Bitwalker_Peek_Normal.h"

int End_of_Information_Decoder(Bitstream* stream, End_of_Information* p)
{
    if (NormalBitstream(stream, END_OF_INFORMATION_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;


        stream->bitpos += END_OF_INFORMATION_BITSIZE;



        return 1;
    }
    else
    {
        return 0;
    }
}

