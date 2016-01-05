// printing entropy of random_device
#include <iostream>
#include <random>

int main()
{
    std::random_device d;
    std::cout << d.entropy() << '\n';

}
