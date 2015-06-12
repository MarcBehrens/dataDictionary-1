
#ifndef STOP_IF_IN_STAFF_RESPONSIBLE_UPPERBITSNOTSET_H_INCLUDED
#define STOP_IF_IN_STAFF_RESPONSIBLE_UPPERBITSNOTSET_H_INCLUDED

#include "Stop_if_in_Staff_Responsible_Core.h"

/*@
    requires valid:      \valid_read(p);
    requires invariant:  Invariant(p);

    assigns \nothing;

    ensures result:  \result <==> UpperBitsNotSet(p);
*/
int Stop_if_in_Staff_Responsible_UpperBitsNotSet(const Stop_if_in_Staff_Responsible_Core* p);

#endif // STOP_IF_IN_STAFF_RESPONSIBLE_UPPERBITSNOTSET_H_INCLUDED
