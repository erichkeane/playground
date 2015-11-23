#include <iostream>
#include <initializer_list>
#include <utility>

// Simple type to convert an integer sequence of type char to a constexpr string
template <typename A>
struct int_seq_to_char_array;

// Specialization to accomplish integer_sequence to char constexpr string
template <template <class, char...> class A, char ...As>
struct int_seq_to_char_array<A<char, As...>>
{
    static constexpr const char value[] =  { As...};
};

// Definition of value type (required to avoid linking error)
template <template <class, char...> class A, char ...As>
constexpr const char int_seq_to_char_array<A<char, As...>>::value[];

// Simple type to take a pair of integer_sequence<char>, and combine them into a single one
template <typename A, typename B>
struct int_seq_combine{};
// Specialization to do the work!
template<template <class, char...> class A, template <class, char...> class B, char ...As, char ...Bs>
struct int_seq_combine<A<char, As...>, B<char, Bs...>>
{
    using type = std::integer_sequence<char, As..., Bs...>;
};

// Type to take a number parameter to a integer-sequence of the 'char' version of its digits
template<size_t Num>
struct num_to_int_seq;
// Specialization for base case
template<>
struct num_to_int_seq<0>
{
    using type = std::integer_sequence<char>;
};
// Specialization to do the work!
template<size_t Num>
struct num_to_int_seq
{
    using type = typename int_seq_combine<
        typename num_to_int_seq<Num/10>::type,
                 std::integer_sequence<char, '0' + Num % 10>>::type;
};

// speciality types necessary to get the fizz-buzz stuff working
using newline = std::integer_sequence<char, '\n'>;
using space = std::integer_sequence<char, ' '>;
using empty = std::integer_sequence<char>;
using fizz = std::integer_sequence<char, 'f','i','z','z'>;
using buzz = std::integer_sequence<char, 'b','u','z','z'>;


// type to create 'fizz' recursively if div 3
template <size_t Num>
struct fizz_buzz_div_3;

// 1 and 2 specialization for false situations
template <>
struct fizz_buzz_div_3<1>
{
    using type = empty;
};

template <>
struct fizz_buzz_div_3<2>
{
    using type = empty;
};

// 3 specialization for true situation base-case
template <>
struct fizz_buzz_div_3<3>
{
    using type = fizz;
};

// recursive case!
template<size_t Num>
struct fizz_buzz_div_3
{
    using type = typename fizz_buzz_div_3<Num - 3>::type;
};

// type to create 'buzz' recursively if div 5
template <size_t Num>
struct fizz_buzz_div_5;

// 1,2,3,4 specialization for false situation base-case
template <>
struct fizz_buzz_div_5<1>
{
    using type = empty;
};
template <>
struct fizz_buzz_div_5<2>
{
    using type = empty;
};
template <>
struct fizz_buzz_div_5<3>
{
    using type = empty;
};
template <>
struct fizz_buzz_div_5<4>
{
    using type = empty;
};
// 5 specialization for true situation base-case
template <>
struct fizz_buzz_div_5<5>
{
    using type = buzz;
};
// recursive case!
template <size_t Num>
struct fizz_buzz_div_5
{
    using type = typename fizz_buzz_div_5<Num - 5>::type;
};
// struct to create the words "fizz", "buzz", or "fizzbuzz" (composes others)
template <size_t Num>
struct fizz_buzz_words
{
    using type = typename int_seq_combine<
            typename fizz_buzz_div_3<Num>::type,
            typename fizz_buzz_div_5<Num>::type
                                        >::type;
};

// type to convert fizz-buzz start and end to string rep
template <size_t Start, size_t End>
struct fizz_buzz;
// Non-recursive base-case/single case
template <size_t V>
struct fizz_buzz<V, V>
{
    //using type = typename int_seq_combine<typename num_to_int_seq<V>::type, newline>::type;
    using type =
        typename int_seq_combine<typename num_to_int_seq<V>::type,
            typename int_seq_combine<space,
                typename int_seq_combine<typename fizz_buzz_words<V>::type, newline>::type
                                    >::type
                                >::type;
};

// Recursive case, applies each individuall to previous specialization
template <size_t Start, size_t End>
struct fizz_buzz
{
    using type = typename int_seq_combine<
        typename fizz_buzz<Start, Start>::type,
        typename fizz_buzz<Start + 1, End>::type>::type;
};

int main()
{
    using fizz_buzz_type = typename fizz_buzz<1,100>::type;
    std::cout << int_seq_to_char_array<fizz_buzz_type>::value;
}
