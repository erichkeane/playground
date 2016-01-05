// exmaples of std::hash in action
#include <functional>
#include <iostream>

int main()
{

    int i = -42;
    bool b = true;
    std::string str = "erich";
    std::hash<std::string> strhash;
    std::hash<bool> boolhash;
    std::hash<int> inthash;

    std::cout << (size_t)i << ":" << inthash(i)<<std::endl;
    std::cout << str << ":" << strhash(str)<<std::endl;
    std::cout << b << ":" << boolhash(b)<<std::endl;
}
