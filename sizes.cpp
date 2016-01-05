// printing sizes of standard container
//
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>

int main()
{
    std::vector<char> v{};
    std::list<char> l{};
    std::set<char> s{};
    std::unordered_set<char> us{};

    std::cout << "Vector:  " << sizeof(v) << '\n';
    std::cout << "list:    " << sizeof(l) << '\n';
    std::cout << "set:     " << sizeof(s) << '\n';
    std::cout << "unordset:" << sizeof(us) << '\n';
}
