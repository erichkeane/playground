// Example of creating a distribution based on the machine-ptr size
#include <iostream>
#include <random>

static uintptr_t distribution()
{
    static std::conditional<
        (sizeof(intptr_t) > 4) ,
            std::mt19937_64,
            std::mt19937
                >::type rng{std::random_device{}()};
    static std::uniform_int_distribution<uintptr_t> dist;
    return dist(rng);
}

int main()
{
    for(int i = 0; i < 10; ++i)
    std::cout << distribution() << std::endl;
}
