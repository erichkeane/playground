// a set of templates that differentiates between a std::vector and a non
// template type, setting base_type to either the 'type' or internal type
// of a vector, and recording the depth of the vector.  Thus, a
// vector<vector<vector<int>>> would be a depth of 3, and a base_type of int
#include <iostream>
#include <vector>
#include <typeinfo>

template <typename T, typename = void>
struct is_vector{ constexpr static const bool value = false; };

template <typename T>
struct is_vector<T,
    std::enable_if_t<
            std::is_same<T,
                std::vector<typename T::value_type, typename T::allocator_type>>::value
        >
    >
{ constexpr static const bool value = true; };

template<typename T, typename = void>
struct vector_info {
    constexpr static const size_t depth = 0;
    using base_type = T;
};


template<typename T>
struct vector_info <T,
            std::enable_if_t<
                is_vector<T>::value
            >
        >
{
     constexpr static const size_t depth = vector_info<typename T::value_type>::depth + 1;
     using base_type = typename vector_info<typename T::value_type>::base_type;
};

template <typename T>
void print()
{
    std::cout << typeid(typename vector_info<T>::base_type).name() << "  "<<
        vector_info<T>::depth<<std::endl;
}
int main()
{
    std::cout << is_vector<std::vector<int>>::value <<std::endl;
    std::cout << is_vector<int>::value <<std::endl;
    std::cout << is_vector<std::string>::value<<std::endl;
    std::cout << is_vector<std::vector<std::vector<int>>>::value <<std::endl;

    std::cout << "Vector Info\n";
    int i;
    std::vector<int> vi;
    std::vector<std::vector<int>> vvi;
    std::vector<std::vector<std::vector<int>>> vvvi;
    print<decltype(i)>();
    print<decltype(vi)>();
    print<decltype(vvi)>();
    print<decltype(vvvi)>();
}
