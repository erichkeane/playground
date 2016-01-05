// Playing around with std::allocator's max_size parameter
#include <iostream>
#include <vector>
#include <limits>

int main()
{

    std::allocator<long long> a;

    std::cout << std::hex <<"max_size: " << a.max_size() <<'\n';
    std::cout << std::hex <<"int max : " << std::numeric_limits<long long>::max() <<'\n';
}
