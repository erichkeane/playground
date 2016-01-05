// Examining Destructor ordering
#include <iostream>

struct FooA
{
    std::string local;
    FooA(const std::string& l):local(l)
    {
    }
    ~FooA()
    {
        std::cout << "Foo A!"<<local<<std::endl;
    }
};

struct FooB : public FooA
{
    FooB(const std::string& l):FooA(l)
    {
    }
    ~FooB()
    {
        std::cout<<"Foo B!"<<local<<std::endl;
    }
};


int main()
{
    FooA a{"As A"};
    FooB b{"As B"};
}
