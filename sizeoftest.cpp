// testing unsigned max limit
#include <iostream>
#include <limits>

int main()
{
    std::cout << "unsigned: " << sizeof(unsigned) << '\n';
    std::cout << std::numeric_limits<unsigned>::max() <<'\n';
}
