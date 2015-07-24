// Simple test of the alignof operator
#include <iostream>
#include <cstddef>

class A
{
    long double b;
    long double c;
    long double d;
    double e;
    double f;
};

int main()
{
    std::cout << alignof(std::max_align_t)<<std::endl;
    std::cout << alignof(int)<<std::endl;
    std::cout << alignof(std::iostream)<<std::endl;
    std::cout << alignof(A)<<std::endl;
}

