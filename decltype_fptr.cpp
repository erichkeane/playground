// Playing with decltype on a std::function object
#include <functional>
#include <type_traits>

int f (const int x)
{
    //++x; // fails, since X is const!
    return x;
}

int main()
{
    std::function<int(const int)> ff(f);

    static_assert(std::is_same<int, decltype(ff)::result_type>::value, "result");
    static_assert(std::is_same<int, decltype(ff)::argument_type>::value, "arg");
    //static_assert(std::is_same<const int, decltype(ff)::argument_type>::value, "arg2"); // fails, since the param is NOT const!

};
