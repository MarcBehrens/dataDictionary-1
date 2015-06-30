
#ifndef TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_H_INCLUDED
#define TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_H_INCLUDED

#include "Bitstream.h"
#include "Track_Condition_Change_of_allowed_current_consumption_Core.h"
#include "BasePacket.h"

struct Track_Condition_Change_of_allowed_current_consumption : public BasePacket
{
    Track_Condition_Change_of_allowed_current_consumption_Core core;

    Track_Condition_Change_of_allowed_current_consumption() : BasePacket(40) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Track_Condition_Change_of_allowed_current_consumption*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Track_Condition_Change_of_allowed_current_consumption> Track_Condition_Change_of_allowed_current_consumptionPtr;

#endif // TRACK_CONDITION_CHANGE_OF_ALLOWED_CURRENT_CONSUMPTION_H_INCLUDED

