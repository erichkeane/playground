// Playing around with template template matching.
#include <iostream>
#include <vector>
#include <typeinfo>
#include <tuple>

#include <functional>
#include <type_traits>
#include <tuple>

// type to enable getting the nth argument of a function object
template<typename Func>
struct func_get;

template<template <typename...> class Func, typename... Args, typename Ret>
struct func_get<Func<Ret(Args...)>>
{
    template<size_t Index>
    using argument_type = typename std::tuple_element<Index, std::tuple<Args...> >::type;
};

// Simple pulling apart of a tuple/the like to pull out the 2nd type
template<template<typename...> class T, typename FST, typename SCD, typename...Rest>
void PrintSecondType(T<FST,SCD,Rest...>)
{
    std::cout << typeid(SCD).name() << std::endl;
}

// Simple example of changing std::vector handling based on the interior type (template matching)
template<template<typename, typename> class T, typename IT, typename Alloc>
void DoThingToVector(T<IT, Alloc> vect)
{
    std::cout << typeid(IT).name() <<std::endl;
}

template<template<typename, typename> class T, typename Alloc>
void DoThingToVector(T<std::string, Alloc> vect)
{
    std::cout << "std::string!" <<std::endl;
}

int main()
{
    std::function<int(double, float, char, int)> f;

    static_assert(std::is_same<double, func_get<decltype(f)>::argument_type<0>>::value, "Failed!");
    static_assert(std::is_same<float, func_get<decltype(f)>::argument_type<1>>::value, "Failed!");
    static_assert(std::is_same<char, func_get<decltype(f)>::argument_type<2>>::value, "Failed!");
    static_assert(std::is_same<int, func_get<decltype(f)>::argument_type<3>>::value, "Failed!");

    std::tuple<int, double, std::string> tp1;
    std::tuple<int, float, std::string> tp2;
    std::tuple<int, char, std::string> tp3;

    PrintSecondType(tp1);
    PrintSecondType(tp2);
    PrintSecondType(tp3);
    std::vector<int> iv;
    std::vector<double> dv;
    std::vector<std::string> sv;
    DoThingToVector(iv);
    DoThingToVector(dv);
    DoThingToVector(sv);
}
