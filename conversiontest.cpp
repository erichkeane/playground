// Example of the ambiguous nature of a cast involving a
// conversion operator of nullptr_t, and a data type that
// is constructed with a pointer.
#include <iostream>

struct Bar
{
    Bar(const Bar&){std::cout<<"Bar ctor copy!"<<std::endl;}
    Bar(const char*){std::cout<<"Bar char ctor!"<<std::endl;}
};
struct Foo
{
    operator std::nullptr_t() const{return nullptr;}
    operator Bar() const{Bar b(""); return b;}
};

int main()
{
    Foo a;
    static_cast<Bar>(a);
}
