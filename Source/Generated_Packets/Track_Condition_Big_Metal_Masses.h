
#ifndef TRACK_CONDITION_BIG_METAL_MASSES_H_INCLUDED
#define TRACK_CONDITION_BIG_METAL_MASSES_H_INCLUDED

#include "Bitstream.h"
#include "Track_Condition_Big_Metal_Masses_Core.h"
#include "BasePacket.h"

struct Track_Condition_Big_Metal_Masses : public BasePacket
{
    Track_Condition_Big_Metal_Masses_Core core;

    Track_Condition_Big_Metal_Masses() : BasePacket(67) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Track_Condition_Big_Metal_Masses*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Track_Condition_Big_Metal_Masses> Track_Condition_Big_Metal_MassesPtr;

#endif // TRACK_CONDITION_BIG_METAL_MASSES_H_INCLUDED

