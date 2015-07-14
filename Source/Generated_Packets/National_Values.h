
#ifndef NATIONAL_VALUES_H_INCLUDED
#define NATIONAL_VALUES_H_INCLUDED

#include "Bitstream.h"
#include "National_Values_Core.h"
#include "BasePacket.h"

struct National_Values : public BasePacket
{
    National_Values_Core core;

    National_Values() : BasePacket(3) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const National_Values*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<National_Values> National_ValuesPtr;

#endif // NATIONAL_VALUES_H_INCLUDED

