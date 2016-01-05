// Validating the mathcing of internal types in a template-template situation
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <typeinfo>

template<
    template<typename U, typename V, typename... Args> class OT,
    template<typename U, typename... Args> class AT>
class A
{
    public:
    void print()
    {
        std::cout <<"Print: " << typeid(OT).name() <<" " << typeid(AT).name() << "\n";
    }
};

int main()
{
    A<std::map, std::vector> a;
    a.print();

    A<std::unordered_map, std::vector> b;
    b.print();
}

