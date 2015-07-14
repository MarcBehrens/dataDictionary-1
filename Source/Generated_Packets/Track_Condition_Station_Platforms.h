
#ifndef TRACK_CONDITION_STATION_PLATFORMS_H_INCLUDED
#define TRACK_CONDITION_STATION_PLATFORMS_H_INCLUDED

#include "Bitstream.h"
#include "Track_Condition_Station_Platforms_Core.h"
#include "BasePacket.h"

struct Track_Condition_Station_Platforms : public BasePacket
{
    Track_Condition_Station_Platforms_Core core;

    Track_Condition_Station_Platforms() : BasePacket(69) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Track_Condition_Station_Platforms*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Track_Condition_Station_Platforms> Track_Condition_Station_PlatformsPtr;

#endif // TRACK_CONDITION_STATION_PLATFORMS_H_INCLUDED

