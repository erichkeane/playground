#include <iostream>
#include <iomanip>

typedef struct UUID_t
{
    uint32_t data1;
    uint16_t data2;
    uint16_t data3;
    uint8_t  data4[8];
} GUID;

std::ostream& operator<<(std::ostream& os, const UUID_t& g)
{
    std::ios::fmtflags f (os.flags());

    os << std::hex
        << std::setw(8) << g.data1 << '-'
        << std::setw(4) << g.data2 << '-'
        << std::setw(4) << g.data3 << '-'
        << std::setw(2) << g.data3 << '-'
        << std::setw(2) << g.data4[0]
        << std::setw(2) << g.data4[1]
        << std::setw(2) << g.data4[2]
        << std::setw(2) << g.data4[3]
        << std::setw(2) << g.data4[4]
        << std::setw(2) << g.data4[5]
        << std::setw(2) << g.data4[6]
        << std::setw(2) << g.data4[7]
        << std::setw(2) << g.data4[8];


    os.flags(f);
    return os;
}

int main()
{
    GUID g;
    g.data1 = 213;
    g.data2=12;
    g.data3=33;
    g.data4[0] =234;
    g.data4[1]=59;
    g.data4[2]=23;
    g.data4[3]=38;
    g.data4[4]=35;
    g.data4[5]=32;
    g.data4[6]=89;
    g.data4[7]=32;

    std::cout <<g;
}
