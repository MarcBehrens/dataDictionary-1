
#include "Route_Suitability_Data_UpperBitsNotSet.h"
#include "UpperBitsNotSet.h"

int Route_Suitability_Data_UpperBitsNotSet(const Route_Suitability_Data* p)
{
    if (UpperBitsNotSet64(p->NID_PACKET,        8)   &&
        UpperBitsNotSet64(p->Q_DIR,             2)   &&
        UpperBitsNotSet64(p->L_PACKET,          13)  &&
        UpperBitsNotSet64(p->Q_SCALE,           2)   &&
        UpperBitsNotSet64(p->Q_TRACKINIT,       1)   &&
        UpperBitsNotSet64(p->D_TRACKINIT,       15)  &&
        UpperBitsNotSet64(p->D_SUITABILITY,     15)  &&
        UpperBitsNotSet64(p->Q_SUITABILITY,     2)   &&
        UpperBitsNotSet64(p->M_LINEGAUGE,       8)   &&
        UpperBitsNotSet64(p->M_AXLELOADCAT,     7)   &&
        UpperBitsNotSet64(p->M_VOLTAGE,         4)   &&
        UpperBitsNotSet64(p->NID_CTRACTION,     10)  &&
        UpperBitsNotSet64(p->N_ITER,            5)   &&
        UpperBitsNotSet64(p->D_SUITABILITY(k),  15)  &&
        UpperBitsNotSet64(p->Q_SUITABILITY(k),  2)   &&
        UpperBitsNotSet64(p->M_LINEGAUGE(k),    8)   &&
        UpperBitsNotSet64(p->M_AXLELOADCAT(k),  7)   &&
        UpperBitsNotSet64(p->M_VOLTAGE(k),      4)   &&
        UpperBitsNotSet64(p->NID_CTRACTION(k),  10))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

