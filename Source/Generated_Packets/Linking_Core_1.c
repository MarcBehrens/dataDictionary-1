
#include "Linking_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Linking_Core_1_UpperBitsNotSet(const Linking_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_LINK_k,          15);
    status = status && UpperBitsNotSet64(p->Q_NEWCOUNTRY_k,    1) ;
    if (p->Q_NEWCOUNTRY_k == 1)
    {
    status = status && UpperBitsNotSet64(p->NID_C_k,           10);
    }
    status = status && UpperBitsNotSet64(p->NID_BG_k,          14);
    status = status && UpperBitsNotSet64(p->Q_LINKORIENTATION_k, 1) ;
    status = status && UpperBitsNotSet64(p->Q_LINKREACTION_k,  2) ;
    status = status && UpperBitsNotSet64(p->Q_LOCACC_k,        6) ;

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Linking_Core_1_Encoder(Bitstream* stream, const Linking_Core_1* p)
{
    if (NormalBitstream(stream, LINKING_CORE_1_CORE_BITSIZE))
    {
        if (Linking_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_LINK_k);
            Bitstream_Write(stream, 1,  p->Q_NEWCOUNTRY_k);
            if (p->Q_NEWCOUNTRY_k == 1)
            {
            Bitstream_Write(stream, 10, p->NID_C_k);
            }

            Bitstream_Write(stream, 14, p->NID_BG_k);
            Bitstream_Write(stream, 1,  p->Q_LINKORIENTATION_k);
            Bitstream_Write(stream, 2,  p->Q_LINKREACTION_k);
            Bitstream_Write(stream, 6,  p->Q_LOCACC_k);


            //@ assert D_LINK_k:          EqualBits(stream, pos,       pos + 15,  p->D_LINK_k);
            //@ assert Q_NEWCOUNTRY_k:    EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY_k);

            return 1;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return -1;
    }
}

int Linking_Core_1_Decoder(Bitstream* stream, Linking_Core_1* p)
{
    if (NormalBitstream(stream, LINKING_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires D_LINK_k:       stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_LINK_k;
	  ensures  D_LINK_k:       stream->bitpos == pos + 15;
	  ensures  D_LINK_k:       EqualBits(stream, pos + 0, pos + 15, p->D_LINK_k);
	  ensures  D_LINK_k:       UpperBitsNotSet(p->D_LINK_k, 15);
	*/
	{ p->D_LINK_k		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_NEWCOUNTRY_k: stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_NEWCOUNTRY_k;
	  ensures  Q_NEWCOUNTRY_k: stream->bitpos == pos + 16;
	  ensures  Q_NEWCOUNTRY_k: EqualBits(stream, pos + 15, pos + 16, p->Q_NEWCOUNTRY_k);
	  ensures  Q_NEWCOUNTRY_k: UpperBitsNotSet(p->Q_NEWCOUNTRY_k, 1);
	*/
	{ p->Q_NEWCOUNTRY_k		= Bitstream_Read(stream, 1); }

        if (p->Q_NEWCOUNTRY_k == 1)
        {
	{ p->NID_C_k		= Bitstream_Read(stream, 10); }
        }

	{ p->NID_BG_k		= Bitstream_Read(stream, 14); }

	{ p->Q_LINKORIENTATION_k		= Bitstream_Read(stream, 1); }

	{ p->Q_LINKREACTION_k		= Bitstream_Read(stream, 2); }

	{ p->Q_LOCACC_k		= Bitstream_Read(stream, 6); }

        //@ assert D_LINK_k:          EqualBits(stream, pos,       pos + 15,  p->D_LINK_k);
        //@ assert Q_NEWCOUNTRY_k:    EqualBits(stream, pos + 15,  pos + 16,  p->Q_NEWCOUNTRY_k);

        //@ assert D_LINK_k:          UpperBitsNotSet(p->D_LINK_k,          15);
        //@ assert Q_NEWCOUNTRY_k:    UpperBitsNotSet(p->Q_NEWCOUNTRY_k,    1);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

