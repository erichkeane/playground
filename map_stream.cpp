// printing a std::map, which should fail
#include <iostream>
#include <map>

template<typename T>
void doPrint(T& thing)
{
    std::cout << thing;
}
int main()
{
    std::map<int, double> a;
    doPrint(a);
}
