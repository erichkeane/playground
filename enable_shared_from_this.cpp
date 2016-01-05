// playing wiht the std::shared_from_this
#include <iostream>
#include <memory>

struct Foo : std::enable_shared_from_this<Foo>
{
    std::shared_ptr<Foo> getptr() { return shared_from_this();}
};

int main()
{

    Foo a;
    std::weak_ptr<Foo> ptr;
    std::shared_ptr<Foo> ptr2;

    std::cout << "Size: " << sizeof(a) <<'\n';
    std::cout << "Size: " << sizeof(ptr) <<'\n';
    std::cout << "Size: " << sizeof(ptr2) <<'\n';
}
