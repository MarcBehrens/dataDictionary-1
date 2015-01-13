
#include "Geographical_Position_Information_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Geographical_Position_Information_UpperBitsNotSet(const Geographical_Position_Information* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->Q_NEWCOUNTRY,      1)   &&
        UpperBitsNotSet64(p->NID_C,             10)  &&
        UpperBitsNotSet64(p->NID_BG,            14)  &&
        UpperBitsNotSet64(p->D_POSOFF,          15)  &&
        UpperBitsNotSet64(p->Q_MPOSITION,       1)   &&
        UpperBitsNotSet64(p->M_POSITION,        24)  &&
        UpperBitsNotSet64(p->N_ITER,            5)   &&
        UpperBitsNotSet64(p->Q_NEWCOUNTRY(k),   1)   &&
        UpperBitsNotSet64(p->NID_C(k),          10)  &&
        UpperBitsNotSet64(p->NID_BG(k),         14)  &&
        UpperBitsNotSet64(p->D_POSOFF(k),       15)  &&
        UpperBitsNotSet64(p->Q_MPOSITION(k),    1)   &&
        UpperBitsNotSet64(p->M_POSITION(k),     24))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

