// detecting the 'is_one_of' property for std::tuple internals
#include <iostream>
#include <type_traits>
#include <tuple>


template<typename T>
struct remove_first;

template<template <typename...> class Base, typename T, typename...Rest>
struct remove_first<Base<T, Rest...>>
{
    typedef Base<Rest...> type;
};

template<typename ToTest, typename T2>
struct is_component;

template<typename ToTest, template <typename...> class Base, typename T>
struct is_component<ToTest, Base<T>>
{
    static constexpr bool value = std::is_same<ToTest, T>::value;
};

template<typename ToTest, template <typename...> class Base, typename T, typename...Rest>
struct is_component<ToTest, Base<T, Rest...>>
{
    static constexpr bool value = std::is_same<ToTest, T>::value
        || is_component<ToTest, Base<Rest...>>::value;
};


int main()
{
    typedef std::tuple<int, float, char> big_tup;
    typedef remove_first<big_tup>::type small_tuple;

    static_assert(std::is_same<small_tuple, std::tuple<float, char>>::value, "ERROR");
    // Calls the specialization
    static_assert(is_component<float, std::tuple<float>>::value, "ERROR1");
    static_assert(is_component<float, small_tuple>::value, "ERROR2");
    static_assert(is_component<char, small_tuple>::value, "ERROR3");

    // Fails as expected, since int isn't in small_tuple
    //static_assert(enable_if_component<int, small_tuple>::value, "ERROR4");

    // Illegal
    // static_assert(enable_if_component<float, std::tuple<>>::value,"ERROR5");
}
