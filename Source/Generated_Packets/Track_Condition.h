
#ifndef TRACK_CONDITION_H_INCLUDED
#define TRACK_CONDITION_H_INCLUDED

#include "Bitstream.h"
#include "Track_Condition_Core.h"
#include "BasePacket.h"

struct Track_Condition : public BasePacket
{
    Track_Condition_Core core;

    Track_Condition() : BasePacket(68) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Track_Condition*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Track_Condition> Track_ConditionPtr;

#endif // TRACK_CONDITION_H_INCLUDED

