// template to make an initializer list of any integral type (int types only!)
// from any range!  Entire calculation is at compile time!

#include<iostream>
#include<algorithm>

template<typename T, T ...nums>
constexpr std::initializer_list<T> make_list_from_template_args()
{
    return {nums...};
}

template<typename T,T min, T max, T ...nums>
struct expander
{
    constexpr static std::initializer_list<T> value=
        expander<T, min + 1,max,nums..., min>::value;
};

template<typename T, T max, T ...nums>
struct expander<T, max, max, nums...>
{
    constexpr static std::initializer_list<T> value =
        make_list_from_template_args<T, nums..., max>();
};


template<typename T, T min, T max>
constexpr std::initializer_list<T> make_list()
{
    static_assert(min <= max, "Min must be <= max");

    return expander<T, min,max>::value;
}

int main()
{
    std::initializer_list<char> x = make_list<char, 'a', 'e'>();
    std::for_each(std::begin(x), std::end(x), [](auto c){std::cout<<c<<std::endl;});
    std::cout<<"\n\n\n";

    std::initializer_list<int> x1 = make_list<int, 1,10>();
    std::for_each(std::begin(x1), std::end(x1), [](auto c){std::cout<<c<<std::endl;});

}
