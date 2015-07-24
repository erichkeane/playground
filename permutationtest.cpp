// Quick sample of the std::next_permutations function
#include <iostream>
#include <algorithm>

int main()
{
    std::string a{"Erich Keane"};

    std::sort(std::begin(a), std::end(a));

    std::cout << "Sorted: " << a<<std::endl;

    int i = 0;
    while(std::next_permutation(std::begin(a), std::end(a)))
        ++i;

    std::cout << i << " perms "<<std::endl;

}
