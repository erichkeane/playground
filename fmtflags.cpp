// Checking out fmtflag default vaules for std::cout
#include <iostream>
#include <iomanip>

int main()
{
    //std::ios_base::fmtflags none;
    std::ios_base::fmtflags zero{};
    std::ios_base::fmtflags ct = std::cout.flags();

    //std::cout << "NONE: " << none << '\n';
    std::cout << "ZERO: " << zero << '\n';
    std::cout << "COUT: " << ct << '\n';

}
