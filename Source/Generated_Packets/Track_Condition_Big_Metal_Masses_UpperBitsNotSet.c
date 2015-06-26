
#include "Track_Condition_Big_Metal_Masses_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Track_Condition_Big_Metal_Masses_UpperBitsNotSet(const Track_Condition_Big_Metal_Masses_Core* p)
{
    if (UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->D_TRACKCOND,       15)  &&
        UpperBitsNotSet64(p->L_TRACKCOND,       15)  &&
        UpperBitsNotSet64(p->N_ITER_1,          5))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

