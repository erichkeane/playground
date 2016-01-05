// Showing error message of unsupported itr type in std::sort
#include <iostream>
#include <algorithm>

struct Foo{};
int main()
{
    Foo b, e;
    std::sort(b,e);
}
