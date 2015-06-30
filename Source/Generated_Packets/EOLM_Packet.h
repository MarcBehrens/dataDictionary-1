
#ifndef EOLM_PACKET_H_INCLUDED
#define EOLM_PACKET_H_INCLUDED

#include "Bitstream.h"
#include "EOLM_Packet_Core.h"
#include "BasePacket.h"

struct EOLM_Packet : public BasePacket
{
    EOLM_Packet_Core core;

    EOLM_Packet() : BasePacket(134) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const EOLM_Packet*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<EOLM_Packet> EOLM_PacketPtr;

#endif // EOLM_PACKET_H_INCLUDED

