// Example of adding a constructor to a struct, yet have it still remain
// compatible with a C pod/trivial type
#include <stdint.h>
#include <iostream>
#include <type_traits>

typedef struct A
{
    int i;
    char str[20];
    float b;

    constexpr A() = default;
    A(int _i, float _b, std::string _s)
        : i (_i), b(_b)
    {
        str[_s.copy(str,sizeof(str)-1,0)]='\0';
    }
} A;

template<typename T>
void typetest(T t)
{
    std::cout << "Is pod? : "<< std::is_pod<T>::value<<std::endl;
    std::cout << "Is trivial? : "<< std::is_trivial<T>::value<<std::endl;
}

int main()
{
    A a(8, 3.5,"asdfaxcbasdfasdfasdfasdfasdfasdfasdfasdfasdfasdf");

    A b = a;

    std::cout << "A: "<< a.i<< " " << a.b << " :"<<a.str<< ":"<<std::endl;
    std::cout << "B: "<< b.i<< " " << b.b << " :"<<b.str<< ":"<<std::endl;

    typetest(a);

}
