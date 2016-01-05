// Simple floating-point comparision test
#include <iostream>

template<typename T>
static bool approx(const T a, const T b)
{
    return not (a > b or a < b);
}


int main()
{
    double a = 0, b = 1;
    double c = 2, d = 3;

    std::cout << approx(a, b) <<std::endl;
    std::cout << approx(c, d) <<std::endl;
    std::cout << approx(d, d) <<std::endl;
}
