// Test to see how to use SFINAE to have 2 otherwise identical functions
#include <iostream>
#include <type_traits>

template <typename T, typename std::enable_if<
!std::is_same<std::string, T>::value, int>::type = 0>
void decrement(T& value)
{
    -- value;
}

template <typename T, typename std::enable_if<
std::is_same<std::string, T>::value, int>::type = 0>
void decrement(T& value)
{
    value.pop_back();
}

int main()
{
    int i = 0;
    std::string str = "asdf";

    decrement(i);
    decrement(str);

    std::cout << i << " "<<str<<std::endl;
}
