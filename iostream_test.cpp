// playing with setw/setfill
#include <iostream>
#include <iomanip>

int main()
{
    std::string temp ("asdfasdfasdfa");
    std::cout << std::hex << std::setfill('0') << std::setw(2) << 14 << " " << temp << std::endl;

    double d = 2123.342345;
    std::cout << std::fixed << std::setw(8) << std::setprecision(2) << std::setfill('0') << d << std::endl;
}
