
#ifndef TRAIN_RUNNING_NUMBER_H_INCLUDED
#define TRAIN_RUNNING_NUMBER_H_INCLUDED

#include "Bitstream.h"
#include "Train_running_number_Core.h"
#include "BasePacket.h"

struct Train_running_number : public BasePacket
{
    Train_running_number_Core core;

    Train_running_number() : BasePacket(5) {}

    void print(std::ostream& stream) const override
    {
        stream << '(' << +id << ',' << core << ')';
    }

    bool equals(const BasePacket& p) const override
    {
	if(auto q = dynamic_cast<const Train_running_number*>(&p))
	{
	    bool status = true;

	    status = status && (id == q->id);
	    status = status && (core == q->core);

	    return status;
	}
	return false;
    }
};

typedef std::shared_ptr<Train_running_number> Train_running_numberPtr;

#endif // TRAIN_RUNNING_NUMBER_H_INCLUDED

