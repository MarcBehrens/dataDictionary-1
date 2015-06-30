
#ifndef TEMPORARY_SPEED_RESTRICTION_H_INCLUDED
#define TEMPORARY_SPEED_RESTRICTION_H_INCLUDED

#include "Bitstream.h"
#include "Temporary_Speed_Restriction_Core.h"
#include "BasePacket.h"

struct Temporary_Speed_Restriction : public BasePacket
{
    Temporary_Speed_Restriction_Core core;

    Temporary_Speed_Restriction() : BasePacket(65) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Temporary_Speed_Restriction*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Temporary_Speed_Restriction> Temporary_Speed_RestrictionPtr;

#endif // TEMPORARY_SPEED_RESTRICTION_H_INCLUDED

