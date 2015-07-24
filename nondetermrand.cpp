// Simple example of how a non-deterministic random
// number generation works in C++11
#include <iostream>
#include <random>

using namespace std;

int main()
{
    random_device rnd;

    for(int i=0;i<10;++i)
    {
        std::cout<<rnd() <<std::endl;
    }
}
