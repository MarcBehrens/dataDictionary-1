
#ifndef ONBOARD_TELEPHONE_NUMBERS_H_INCLUDED
#define ONBOARD_TELEPHONE_NUMBERS_H_INCLUDED

#include "Bitstream.h"
#include "Onboard_telephone_numbers_Core.h"
#include "BasePacket.h"

struct Onboard_telephone_numbers : public BasePacket
{
    Onboard_telephone_numbers_Core core;

    Onboard_telephone_numbers() : BasePacket(3) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Onboard_telephone_numbers*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Onboard_telephone_numbers> Onboard_telephone_numbersPtr;

#endif // ONBOARD_TELEPHONE_NUMBERS_H_INCLUDED

