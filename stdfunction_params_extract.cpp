// extracting parameter types from a std::function object
#include <functional>
#include <type_traits>
#include <tuple>

template<typename Func>
struct func_get;

template<template <typename...> class Func, typename... Args, typename Ret>
struct func_get<Func<Ret(Args...)>>
{
    template<size_t Index>
    using argument_type = typename std::tuple_element<Index, std::tuple<Args...> >::type;
};

int main()
{
    std::function<int(double, float, char, int)> f;

    static_assert(std::is_same<double, func_get<decltype(f)>::argument_type<0>>::value, "Failed!");
    static_assert(std::is_same<float, func_get<decltype(f)>::argument_type<1>>::value, "Failed!");
    static_assert(std::is_same<char, func_get<decltype(f)>::argument_type<2>>::value, "Failed!");
    static_assert(std::is_same<int, func_get<decltype(f)>::argument_type<3>>::value, "Failed!");
}
