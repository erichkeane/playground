// printing a function pointer
#include <iostream>

void plainFunc(int, double){}
struct A
{
    bool AFunc(int, int*){return true;}
};

int main()
{
    //A a;
    std::cout
        << "Plain:    "<<(void*)&plainFunc << "\n"
        << "MemFirst: "<<(void*)&A::AFunc <<"\n"
        //<< "MemSec:   "<<&a.AFunc
        << std::endl;
}
