
#include "Radio_Network_registration_Decoder.h"
#include "Bitstream_Read.h"

int Radio_Network_registration_Decoder(Bitstream* stream, Radio_Network_registration* p)
{
    if (NormalBitstream(stream, RADIO_NETWORK_REGISTRATION_BITSIZE))
    {
        uint8_t* addr = stream->addr;
        const uint32_t size = stream->size;
        const uint32_t pos = stream->bitpos;

	/*@
	  requires Q_DIR:          stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_DIR;
	  ensures  Q_DIR:          stream->bitpos == pos + 2;
	  ensures  Q_DIR:          EqualBits(stream, pos + 0, pos + 2, p->Q_DIR);
	  ensures  Q_DIR:          UpperBitsNotSet(p->Q_DIR, 2);
	*/
	{ p->Q_DIR		= Bitstream_Read(stream, 2); }

	/*@
	  requires L_PACKET:       stream->bitpos == pos + 2;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_PACKET;
	  ensures  L_PACKET:       stream->bitpos == pos + 15;
	  ensures  L_PACKET:       EqualBits(stream, pos + 2, pos + 15, p->L_PACKET);
	  ensures  L_PACKET:       UpperBitsNotSet(p->L_PACKET, 13);
	*/
	{ p->L_PACKET		= Bitstream_Read(stream, 13); }

	/*@
	  requires NID_MN:         stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->NID_MN;
	  ensures  NID_MN:         stream->bitpos == pos + 39;
	  ensures  NID_MN:         EqualBits(stream, pos + 15, pos + 39, p->NID_MN);
	  ensures  NID_MN:         UpperBitsNotSet(p->NID_MN, 24);
	*/
	{ p->NID_MN		= Bitstream_Read(stream, 24); }



        //@ assert Q_DIR:             EqualBits(stream, pos,       pos + 2,   p->Q_DIR);
        //@ assert L_PACKET:          EqualBits(stream, pos + 2,   pos + 15,  p->L_PACKET);
        //@ assert NID_MN:            EqualBits(stream, pos + 15,  pos + 39,  p->NID_MN);

        //@ assert Q_DIR:             UpperBitsNotSet(p->Q_DIR,             2);
        //@ assert L_PACKET:          UpperBitsNotSet(p->L_PACKET,          13);
        //@ assert NID_MN:            UpperBitsNotSet(p->NID_MN,            24);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

