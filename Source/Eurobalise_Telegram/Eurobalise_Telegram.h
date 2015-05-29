
#ifndef EUROBALISE_TELEGRAM_H_INCLUDED
#define EUROBALISE_TELEGRAM_H_INCLUDED

#include "Telegram_Header.h"
#include "BasePacket.h"
#include <iostream>

typedef std::vector<BasePacketPtr> PacketSequence;

struct Eurobalise_Telegram
{
    Telegram_Header header;
    PacketSequence packets;

    void add(BasePacketPtr p)
    {
        packets.push_back(p);
    }

    BasePacketPtr packet(size_t i) const
    {
        return packets[i];
    }

    template<typename T>
    T get(size_t i) const
    {
         return std::static_pointer_cast<T>(packet(i));
    }

    bool decode(Bitstream& stream);

    bool encode(Bitstream& stream) const;
};

std::ostream& operator<<(std::ostream& stream, const Eurobalise_Telegram& p);

bool operator==(const Eurobalise_Telegram& a, const Eurobalise_Telegram& b);

bool operator!=(const Eurobalise_Telegram& a, const Eurobalise_Telegram& b);

#endif // EUROBALISE_TELEGRAM_H_INCLUDED

