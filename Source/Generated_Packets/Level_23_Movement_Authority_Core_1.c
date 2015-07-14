
#include "Level_23_Movement_Authority_Core_1.h"
#include "UpperBitsNotSet.h"
#include "Bitstream_Write.h"
#include "Bitstream_Read.h"

int Level_23_Movement_Authority_Core_1_UpperBitsNotSet(const Level_23_Movement_Authority_Core_1* p)
{
    bool status = true;

    status = status && UpperBitsNotSet64(p->L_SECTION_k,       15);
    status = status && UpperBitsNotSet64(p->Q_SECTIONTIMER_k,  1) ;
    status = status && UpperBitsNotSet64(p->T_SECTIONTIMER_k,  10);
    status = status && UpperBitsNotSet64(p->D_SECTIONTIMERSTOPLOC_k, 15);

    if (status)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Level_23_Movement_Authority_Core_1_Encoder(Bitstream* stream, const Level_23_Movement_Authority_Core_1* p)
{
    if (NormalBitstream(stream, LEVEL_23_MOVEMENT_AUTHORITY_CORE_1_CORE_BITSIZE))
    {
        if (Level_23_Movement_Authority_Core_1_UpperBitsNotSet(p))
        {
            //@ ghost const uint32_t pos = stream->bitpos;

            Bitstream_Write(stream, 15, p->L_SECTION_k);
            Bitstream_Write(stream, 1,  p->Q_SECTIONTIMER_k);
            Bitstream_Write(stream, 10, p->T_SECTIONTIMER_k);
            Bitstream_Write(stream, 15, p->D_SECTIONTIMERSTOPLOC_k);


            //@ assert L_SECTION_k:       EqualBits(stream, pos,       pos + 15,  p->L_SECTION_k);
            //@ assert Q_SECTIONTIMER_k:  EqualBits(stream, pos + 15,  pos + 16,  p->Q_SECTIONTIMER_k);
            //@ assert T_SECTIONTIMER_k:  EqualBits(stream, pos + 16,  pos + 26,  p->T_SECTIONTIMER_k);
            //@ assert D_SECTIONTIMERSTOPLOC_k: EqualBits(stream, pos + 26,  pos + 41,  p->D_SECTIONTIMERSTOPLOC_k);

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

int Level_23_Movement_Authority_Core_1_Decoder(Bitstream* stream, Level_23_Movement_Authority_Core_1* p)
{
    if (NormalBitstream(stream, LEVEL_23_MOVEMENT_AUTHORITY_CORE_1_CORE_BITSIZE))
    {
        //@ ghost const uint32_t pos = stream->bitpos;

	/*@
	  requires L_SECTION_k:    stream->bitpos == pos + 0;
	  assigns        	   stream->bitpos;
	  assigns		   p->L_SECTION_k;
	  ensures  L_SECTION_k:    stream->bitpos == pos + 15;
	  ensures  L_SECTION_k:    EqualBits(stream, pos + 0, pos + 15, p->L_SECTION_k);
	  ensures  L_SECTION_k:    UpperBitsNotSet(p->L_SECTION_k, 15);
	*/
	{ p->L_SECTION_k		= Bitstream_Read(stream, 15); }

	/*@
	  requires Q_SECTIONTIMER_k: stream->bitpos == pos + 15;
	  assigns        	   stream->bitpos;
	  assigns		   p->Q_SECTIONTIMER_k;
	  ensures  Q_SECTIONTIMER_k: stream->bitpos == pos + 16;
	  ensures  Q_SECTIONTIMER_k: EqualBits(stream, pos + 15, pos + 16, p->Q_SECTIONTIMER_k);
	  ensures  Q_SECTIONTIMER_k: UpperBitsNotSet(p->Q_SECTIONTIMER_k, 1);
	*/
	{ p->Q_SECTIONTIMER_k		= Bitstream_Read(stream, 1); }

	/*@
	  requires T_SECTIONTIMER_k: stream->bitpos == pos + 16;
	  assigns        	   stream->bitpos;
	  assigns		   p->T_SECTIONTIMER_k;
	  ensures  T_SECTIONTIMER_k: stream->bitpos == pos + 26;
	  ensures  T_SECTIONTIMER_k: EqualBits(stream, pos + 16, pos + 26, p->T_SECTIONTIMER_k);
	  ensures  T_SECTIONTIMER_k: UpperBitsNotSet(p->T_SECTIONTIMER_k, 10);
	*/
	{ p->T_SECTIONTIMER_k		= Bitstream_Read(stream, 10); }

	/*@
	  requires D_SECTIONTIMERSTOPLOC_k: stream->bitpos == pos + 26;
	  assigns        	   stream->bitpos;
	  assigns		   p->D_SECTIONTIMERSTOPLOC_k;
	  ensures  D_SECTIONTIMERSTOPLOC_k: stream->bitpos == pos + 41;
	  ensures  D_SECTIONTIMERSTOPLOC_k: EqualBits(stream, pos + 26, pos + 41, p->D_SECTIONTIMERSTOPLOC_k);
	  ensures  D_SECTIONTIMERSTOPLOC_k: UpperBitsNotSet(p->D_SECTIONTIMERSTOPLOC_k, 15);
	*/
	{ p->D_SECTIONTIMERSTOPLOC_k		= Bitstream_Read(stream, 15); }

        //@ assert L_SECTION_k:       EqualBits(stream, pos,       pos + 15,  p->L_SECTION_k);
        //@ assert Q_SECTIONTIMER_k:  EqualBits(stream, pos + 15,  pos + 16,  p->Q_SECTIONTIMER_k);
        //@ assert T_SECTIONTIMER_k:  EqualBits(stream, pos + 16,  pos + 26,  p->T_SECTIONTIMER_k);
        //@ assert D_SECTIONTIMERSTOPLOC_k: EqualBits(stream, pos + 26,  pos + 41,  p->D_SECTIONTIMERSTOPLOC_k);

        //@ assert L_SECTION_k:       UpperBitsNotSet(p->L_SECTION_k,       15);
        //@ assert Q_SECTIONTIMER_k:  UpperBitsNotSet(p->Q_SECTIONTIMER_k,  1);
        //@ assert T_SECTIONTIMER_k:  UpperBitsNotSet(p->T_SECTIONTIMER_k,  10);
        //@ assert D_SECTIONTIMERSTOPLOC_k: UpperBitsNotSet(p->D_SECTIONTIMERSTOPLOC_k, 15);

	//@ assert final: EqualBits(stream, pos, p);

        return 1;
    }
    else
    {
        return 0;
    }
}

