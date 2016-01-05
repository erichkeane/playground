// Demo of the dispatch-pattern using variadic template parameters
#include <iostream>
#include <tuple>

struct A
{
    A(int mi):my_int(mi){}
    A(A&& a):my_int(a.my_int){std::cout<<"Move CTOR\n";}
    A(const A& a):my_int(a.my_int){std::cout<<"Copy CTOR\n";}

    void print(int i)
    {
        std::cout << "A("<<my_int<<")::print("<< i << ")\n";
    }

    int my_int;
};
struct B
{
    B(int mi):my_int(mi){}
    void print(int i)
    {
        std::cout << "B("<<my_int<<")::print("<< i << ")\n";
    }

    int my_int;
};
struct C
{
    C(int mi):my_int(mi){}
    void print(int i)
    {
        std::cout << "C("<<my_int<<")::print("<< i << ")\n";
    }

    int my_int;
};

template<typename... Ts>
struct Dispatcher
{
    std::tuple<Ts...> vals;

    Dispatcher(Ts&&... ts): vals(std::forward_as_tuple<Ts>(ts)...){}

    static constexpr auto tuple_indexes = std::make_index_sequence<sizeof...(Ts)>{};

    template<std::size_t... index>
    void print_helper(int i, std::index_sequence<index...>)
    {
        (void)std::initializer_list<int>{(std::get<index>(vals).print(i), 0)...};
    }

    template<std::size_t... index>
    void print(int i, const std::index_sequence<index...> = tuple_indexes)
    {
        (void)std::initializer_list<int>{(std::get<index>(vals).print(i), 0)...};
        //print_helper(i, std::make_index_sequence<sizeof...(Ts)>{});
    }
};


int main()
{
    Dispatcher<A,B,C> dispatcher(A(3), B(5),C(12));

    dispatcher.print(5);
}
