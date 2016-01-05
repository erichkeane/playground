// testing some char test code I saw in some code
#include <iostream>

void test(char c)
{
   if (c != '.' &&
       c != '-' &&
       (c < 'a' || c > 'z') &&
       (c < '0' || c > '9'))
    {
        std::cout << c << " is illegal\n";
    }
   else
        std::cout << c << " is legal\n";
}

int main()
{
    std::cout << sizeof(unsigned int)<<std::endl;
    char testchars[] = "1234567890abcdefghijklmnopqrstuvwxyz.-!@#%$^#&^*&^ ";

    for(size_t i = 0; i < sizeof(testchars) - 1; ++i)
        test(testchars[i]);
}
