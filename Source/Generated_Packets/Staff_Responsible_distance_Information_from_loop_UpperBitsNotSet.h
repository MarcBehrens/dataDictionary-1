
#ifndef STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_UPPERBITSNOTSET_H_INCLUDED
#define STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_UPPERBITSNOTSET_H_INCLUDED

#include "Staff_Responsible_distance_Information_from_loop_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Staff_Responsible_distance_Information_from_loop_UpperBitsNotSet(const Staff_Responsible_distance_Information_from_loop_Core* p);

#endif // STAFF_RESPONSIBLE_DISTANCE_INFORMATION_FROM_LOOP_UPPERBITSNOTSET_H_INCLUDED

