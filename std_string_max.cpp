// examining std::string's max_size
#include <iostream>
#include <string>
#include <cmath>

int main()
{
    std::string str;
    std::cout << str.max_size() << std::endl;
    std::cout << 0x3fffffffffffffff << std::endl;
    std::cout << 0xffffffffffffffff << std::endl;
}
