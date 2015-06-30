
#ifndef VIRTUAL_BALISE_COVER_MARKER_H_INCLUDED
#define VIRTUAL_BALISE_COVER_MARKER_H_INCLUDED

#include "Bitstream.h"
#include "Virtual_Balise_Cover_marker_Core.h"
#include "BasePacket.h"

struct Virtual_Balise_Cover_marker : public BasePacket
{
    Virtual_Balise_Cover_marker_Core core;

    Virtual_Balise_Cover_marker() : BasePacket(0) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Virtual_Balise_Cover_marker*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Virtual_Balise_Cover_marker> Virtual_Balise_Cover_markerPtr;

#endif // VIRTUAL_BALISE_COVER_MARKER_H_INCLUDED

