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
    template<typename T, typename = typename
        std::enable_if<
            std::is_same<T, std::nullptr_t>::value
        >::type>
    operator T() const{return nullptr;}
    operator Bar() const{Bar b(""); return b;}
};

int main()
{
    Foo a;
    Bar b = a;
    static_cast<Bar>(a);
    std::nullptr_t t = a;
    std::cout << "t is "<< t<<std::endl;
}
