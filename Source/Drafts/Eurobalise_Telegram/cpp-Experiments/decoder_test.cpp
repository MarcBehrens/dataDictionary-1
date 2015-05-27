
#include "Eurobalise_Telegram.h"
#include "Eurobalise_Header_Encoder.h"
#include "Packet_Header_Encoder.h"
#include "Bitstream_Init.h"
#include "subsets.h"
#include <cassert>
#include <iostream>

int main ()
{
    Eurobalise_Header head;
    {
    head.Q_UPDOWN = 0;
    head.M_VERSION = 3;
    head.Q_MEDIA = 0;
    head.N_PIG = 4;
    head.N_TOTAL = 3;
    head.M_DUP = 3;
    head.M_MCOUNT = 34;
    head.NID_C  = 120;
    head.NID_BG = 49;
    head.Q_LINK = 1;
    }

    Train_running_number_Core a;
    {
    a.L_PACKET = 53;
    a.NID_OPERATIONAL = 9;
    }

    Packet_Header a1;
    a1.NID_PACKET = 5;

    Adhesion_Factor_Core b;
    {
    b.Q_DIR = 1;
    b.L_PACKET = 56;
    b.Q_SCALE = 1;
    b.D_ADHESION = 9;
    b.L_ADHESION = 24;
    b.M_ADHESION = 0;
    }

    Packet_Header b1;
    b1.NID_PACKET = 71;

    End_of_Information_Core c;
    Packet_Header c1;
    c1.NID_PACKET = 255;

    // auto c_save = c;

    std::vector<uint8_t> raw_stream(1000);
    Bitstream stream;
    Bitstream_Init(&stream, &(raw_stream[0]), raw_stream.size(), 73);

    uint32_t init_pos = stream.bitpos;

    Eurobalise_Header_Encoder(&stream, &head);
    Packet_Header_Encoder(&stream, &a1);
    Train_running_number_Encoder(&stream, &a);
    Packet_Header_Encoder(&stream, &b1);
    Adhesion_Factor_Encoder(&stream, &b);
    Packet_Header_Encoder(&stream, &c1);
    End_of_Information_Encoder(&stream, &c);

    stream.bitpos = init_pos;

    Eurobalise_Telegram telegram;

    telegram.Decoder(&stream);

    Eurobalise_Header head_ret = telegram.header;
    auto a_ret = std::static_pointer_cast<Train_running_number>(telegram.packets[0]);
    auto b_ret = std::static_pointer_cast<Adhesion_Factor>(telegram.packets[1]);
    auto c_ret = std::static_pointer_cast<End_of_Information>(telegram.packets[2]);

    assert(head_ret == head);
    assert(a_ret->core == a);
    assert(b_ret->core == b);
    assert(c_ret->core == c);

    std::cout << "successful test of Eurobalise_Telegram_Decoder" << std::endl;

    return EXIT_SUCCESS;
}

