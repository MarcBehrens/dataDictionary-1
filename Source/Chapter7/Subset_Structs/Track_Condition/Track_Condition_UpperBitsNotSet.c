
#include "Track_Condition_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Track_Condition_UpperBitsNotSet(const Track_Condition* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->Q_TRACKINIT,       1)   &&
        UpperBitsNotSet64(p->D_TRACKINIT,       15)  &&
        UpperBitsNotSet64(p->D_TRACKCOND,       15)  &&
        UpperBitsNotSet64(p->L_TRACKCOND,       15)  &&
        UpperBitsNotSet64(p->M_TRACKCOND,       4)   &&
        UpperBitsNotSet64(p->N_ITER,            5)   &&
        UpperBitsNotSet64(p->D_TRACKCOND(k),    15)  &&
        UpperBitsNotSet64(p->L_TRACKCOND(k),    15)  &&
        UpperBitsNotSet64(p->M_TRACKCOND(k),    4))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

