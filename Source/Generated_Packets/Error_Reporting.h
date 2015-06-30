
#ifndef ERROR_REPORTING_H_INCLUDED
#define ERROR_REPORTING_H_INCLUDED

#include "Bitstream.h"
#include "Error_Reporting_Core.h"
#include "BasePacket.h"

struct Error_Reporting : public BasePacket
{
    Error_Reporting_Core core;

    Error_Reporting() : BasePacket(4) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Error_Reporting*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Error_Reporting> Error_ReportingPtr;

#endif // ERROR_REPORTING_H_INCLUDED

