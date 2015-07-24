// Simple class to show the copy symantics caused by
// using auto on a pointer.
#include<iostream>
struct A{int a;};

A* barTest(){return new A;}

int main()
{
    auto cpy = barTest();
    auto* ptr = barTest();

    std::cout<< cpy->a <<std::endl;
    std::cout<< ptr.a <<std::endl;
}
