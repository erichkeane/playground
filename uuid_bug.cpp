// trying out a bug in UUID (since fixed in https://github.com/boostorg/uuid/pull/12)
#include <boost/uuid/uuid_io.hpp>
#include <iostream>

int main()
{
    boost::uuids::uuid uuid = {{ 0x0a, 0xe0, 0x47, 0x50, 0x0a, 0x0a, 0xeb, 0xec, 0xed, 0xee, 0xfc, 0x08, 0x4d, 0xcf, 0xe7, 0xf5 }};

    std::cout << uuid << std::endl;
    std::cout << std::left;
    std::cout << uuid << std::endl;
}
