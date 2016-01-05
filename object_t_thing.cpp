// switching a type based on map vs unordered_map, used during json bug fix
#include <iostream>
#include <map>
#include <unordered_map>
#include <typeinfo>

template<typename T>
struct voider
{
    using type = void;
};

template<template<typename...> class ObjectType, class Key, class Value, template<typename> class AllocatorType, typename Enable = void>
struct object_t_helper
{
    using type = ObjectType<
        Key,
        Value,
        std::less<Key>,
        AllocatorType<std::pair<Key, Value>>
              >;
};
/*
template<template<typename...> class ObjectType, class Key, class Value, template<typename> class AllocatorType>
struct object_t_helper<ObjectType, Key, Value, AllocatorType, typename voider<typename ObjectType<char,char>::key_compare>::type>
{
    using type = ObjectType<
        Key,
        Value,
        std::less<Key>,
        AllocatorType<std::pair<Key, Value>>
              >;
};*/
template<template<typename...> class ObjectType, class Key, class Value, template<typename> class AllocatorType>
struct object_t_helper<ObjectType, Key, Value, AllocatorType, typename voider<typename ObjectType<char,char>::hasher>::type>
{
    using type = ObjectType<
        Key,
        Value,
        std::hash<Key>,
        std::equal_to<Key>,
        AllocatorType<std::pair<Key, Value>>
              >;
};

/*
template<template<typename...> class ObjectType, class Key, class Value, template<typename> class AllocatorType>
struct object_t_helper<ObjectType, Key, Value, AllocatorType, typename voider<
        typename ObjectType<char,char, std::hash<char>, std::equal_to<char>, AllocatorType<std::pair<char,char>>>
>::type>
{
    using type = ObjectType<
        Key,
        Value,
        std::hash<Key>,
        std::equal_to<Key>,
        AllocatorType<std::pair<Key, Value>>
              >;
};
template<template<typename...> class ObjectType, class Key, class Value, template<typename> class AllocatorType>
struct object_t_helper<ObjectType, Key, Value, AllocatorType, typename voider<
        typename ObjectType<char,char, std::less<char>, AllocatorType<std::pair<char,char>>>
>::type>
{
    using type = ObjectType<
        Key,
        Value,
        std::less<Key>,
        AllocatorType<std::pair<Key, Value>>
              >;
};
*/


template<template<typename T, typename U, typename...Args> class ObjectType,
    class StringType, template<typename U> class AllocatorType>
struct basic_json
{

    using object_t = typename object_t_helper<ObjectType, StringType, basic_json, AllocatorType>::type;
    void print()
    {
        std::cout << "::" << typeid(object_t).name() << "\n";
    }
};


int main()
{
    basic_json<std::map, std::string, std::allocator> a;
    basic_json<std::unordered_map, std::string, std::allocator> b;

    a.print();
    b.print();

    std::cout << "::" << typeid(std::unordered_map<int, double>::key_type).name() << "\n";
    std::cout << "::" << typeid(std::unordered_map<int, double>::mapped_type).name() << "\n";

}
