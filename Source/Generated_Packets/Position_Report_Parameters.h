
#ifndef POSITION_REPORT_PARAMETERS_H_INCLUDED
#define POSITION_REPORT_PARAMETERS_H_INCLUDED

#include "Bitstream.h"
#include "Position_Report_Parameters_Core.h"
#include "BasePacket.h"

struct Position_Report_Parameters : public BasePacket
{
    Position_Report_Parameters_Core core;

    Position_Report_Parameters() : BasePacket(58) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Position_Report_Parameters*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Position_Report_Parameters> Position_Report_ParametersPtr;

#endif // POSITION_REPORT_PARAMETERS_H_INCLUDED

