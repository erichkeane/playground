// Simple template version of palindrome test to see how well any  iteratable
// type in C++ could be tested.  Has cout statements to print each letter
// in advance
#include <iostream>
#include <iterator>
#include <algorithm>

template<class T>
bool is_palindrome(const T& item)
{
    auto end = std::end(item);
    for(auto start = std::begin(item);start < end; ++start)
    {
        std::cout<<"Char: "<< start<<std::endl;
    }

    std::cout<<"END"<<std::endl;

    return std::equal(std::begin(item), std::end(item),
            std::reverse_iterator<decltype(std::begin(item))>(std::end(item)));
}

int main()
{
    char test[] = "racecar";
    char test2[] = "raccar";
    char test3[] = "erich";

    std::cout << test << " "<<is_palindrome(test)<<std::endl;
    std::cout << test2 << " "<<is_palindrome(test2)<<std::endl;
    std::cout << test3 << " "<<is_palindrome(test3)<<std::endl;
}
