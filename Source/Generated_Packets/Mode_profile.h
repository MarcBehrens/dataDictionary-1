
#ifndef MODE_PROFILE_H_INCLUDED
#define MODE_PROFILE_H_INCLUDED

#include "Bitstream.h"
#include "Mode_profile_Core.h"
#include "BasePacket.h"

struct Mode_profile : public BasePacket
{
    Mode_profile_Core core;

    Mode_profile() : BasePacket(80) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Mode_profile*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Mode_profile> Mode_profilePtr;

#endif // MODE_PROFILE_H_INCLUDED

