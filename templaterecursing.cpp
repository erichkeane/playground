// Simple example of getting a recursive template to work with an integer
// base type
#include <iostream>

template<int v>
struct Recurse
{
    constexpr static int Value = (int)(Recurse<v-1>::Value * .75 +4);
};

template<>
struct Recurse<1>
{
        constexpr static int Value = 6;
};



int main()
{
    std::cout<<"Value: "<< Recurse<1>::Value << std::endl;
    std::cout<<"Value: "<< Recurse<2>::Value << std::endl;
    std::cout<<"Value: "<< Recurse<3>::Value << std::endl;
    std::cout<<"Value: "<< Recurse<4>::Value << std::endl;
    std::cout<<"Value: "<< Recurse<5>::Value << std::endl;
}
