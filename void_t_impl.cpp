// Examines the void_t implementation problem shown in N3911 Section 2.2
#include <iostream>

// Doesn't work with Clang++
//template <typename...>
//using void_t = void;

// Works with both clang++ and g++!
template <typename...>
struct void_t_impl
{
    using type = void;
};

template <typename...Args>
using void_t = typename void_t_impl<Args...>::type;

template<typename T, typename Enable = void>
struct printer{
    static void print()
    {
        std::cout << "Neither?!?!\n";
    }
};

template<typename T>
struct printer<T, void_t<typename T::TypeA>>
{
    static void print()
    {
        std::cout << "Has TypeA!\n";
    }
};

template<typename T>
struct printer<T, void_t<typename T::TypeB>>
{
    static void print()
    {
        std::cout << "Has TypeB!\n";
    }
};

struct FooA{
    using TypeA = int;
};

struct FooB{
    using TypeB = double;
};


int main()
{
    std::cout << "A: ";
    printer<FooA>::print();
    std::cout << "B: ";
    printer<FooB>::print();

    return 0;
}
