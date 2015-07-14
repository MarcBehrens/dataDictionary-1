
#include "Axle_Load_Speed_Profile_Core_2.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Axle_Load_Speed_Profile_Core_2_UpperBitsNotSet(const Axle_Load_Speed_Profile_Core_2* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->D_AXLELOAD_k,      15);
    status = status && UpperBitsNotSet64(p->L_AXLELOAD_k,      15);
    status = status && UpperBitsNotSet64(p->Q_FRONT_k,         1) ;
    status = status && UpperBitsNotSet64(p->N_ITER_2_1,        5) ;
    for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
    {
        status = status && Axle_Load_Speed_Profile_Core_2_1_UpperBitsNotSet(&(p->sub_2_1[i]));
    }

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Axle_Load_Speed_Profile_Core_2_Encoder(Bitstream* stream, const Axle_Load_Speed_Profile_Core_2* p)
{
    if (NormalBitstream(stream, AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_BITSIZE))
    {
        if (Axle_Load_Speed_Profile_Core_2_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->D_AXLELOAD_k);
            Bitstream_Write(stream, 15, p->L_AXLELOAD_k);
            Bitstream_Write(stream, 1,  p->Q_FRONT_k);
            Bitstream_Write(stream, 5,  p->N_ITER_2_1);
            for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
            {
                Axle_Load_Speed_Profile_Core_2_1_Encoder(stream, &(p->sub_2_1[i]));
            }


            //@ assert D_AXLELOAD_k:      EqualBits(stream, pos,       pos + 15,  p->D_AXLELOAD_k);
            //@ assert L_AXLELOAD_k:      EqualBits(stream, pos + 15,  pos + 30,  p->L_AXLELOAD_k);
            //@ assert Q_FRONT_k:         EqualBits(stream, pos + 30,  pos + 31,  p->Q_FRONT_k);

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

int Axle_Load_Speed_Profile_Core_2_Decoder(Bitstream* stream, Axle_Load_Speed_Profile_Core_2* p)
{
    if (NormalBitstream(stream, AXLE_LOAD_SPEED_PROFILE_CORE_2_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires D_AXLELOAD_k:   stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_AXLELOAD_k;
	  ensures  D_AXLELOAD_k:   stream->bitpos == pos + 15;
	  ensures  D_AXLELOAD_k:   EqualBits(stream, pos + 0, pos + 15, p->D_AXLELOAD_k);
	  ensures  D_AXLELOAD_k:   UpperBitsNotSet(p->D_AXLELOAD_k, 15);
	*/
	{ p->D_AXLELOAD_k		= Bitstream_Read(stream, 15); }

	/*@
	  requires L_AXLELOAD_k:   stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_AXLELOAD_k;
	  ensures  L_AXLELOAD_k:   stream->bitpos == pos + 30;
	  ensures  L_AXLELOAD_k:   EqualBits(stream, pos + 15, pos + 30, p->L_AXLELOAD_k);
	  ensures  L_AXLELOAD_k:   UpperBitsNotSet(p->L_AXLELOAD_k, 15);
	*/
	{ p->L_AXLELOAD_k		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_FRONT_k:      stream->bitpos == pos + 30;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_FRONT_k;
	  ensures  Q_FRONT_k:      stream->bitpos == pos + 31;
	  ensures  Q_FRONT_k:      EqualBits(stream, pos + 30, pos + 31, p->Q_FRONT_k);
	  ensures  Q_FRONT_k:      UpperBitsNotSet(p->Q_FRONT_k, 1);
	*/
	{ p->Q_FRONT_k		= Bitstream_Read(stream, 1); }

	{ p->N_ITER_2_1		= Bitstream_Read(stream, 5); }

        for (uint32_t i = 0; i < p->N_ITER_2_1; ++i)
        {
            Axle_Load_Speed_Profile_Core_2_1_Decoder(stream, &(p->sub_2_1[i]));
        }
        //@ assert D_AXLELOAD_k:      EqualBits(stream, pos,       pos + 15,  p->D_AXLELOAD_k);
        //@ assert L_AXLELOAD_k:      EqualBits(stream, pos + 15,  pos + 30,  p->L_AXLELOAD_k);
        //@ assert Q_FRONT_k:         EqualBits(stream, pos + 30,  pos + 31,  p->Q_FRONT_k);

        //@ assert D_AXLELOAD_k:      UpperBitsNotSet(p->D_AXLELOAD_k,      15);
        //@ assert L_AXLELOAD_k:      UpperBitsNotSet(p->L_AXLELOAD_k,      15);
        //@ assert Q_FRONT_k:         UpperBitsNotSet(p->Q_FRONT_k,         1);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

