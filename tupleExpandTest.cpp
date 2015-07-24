// Quick example of using templates to implement an IOC container
// where the IOC container has multiple children without inheritence.
// Notice that the DoAllThings method is likely optimized to a very trivial
// implementation
#include <iostream>
#include <tuple>
#include <utility>

struct A
{
    void DoThing(int i)
    {
        std::cout<<"A:"<<i<<std::endl;
    }
    int inside = 5;
};
struct C
{
    void DoThing(int i)
    {
        std::cout<<"C:"<<i<<std::endl;
    }
    int inside = 4;
};
struct D
{
    void DoThing(int i)
    {
        std::cout<<"D:"<<i<<std::endl;
    }
    int inside = 4;
};
struct B
{
    void DoThing(int i)
    {
        std::cout<<"B:"<<i<<std::endl;
    }
    int inside = 4;
};



template<typename ...Ts>
class Magic
{
    public:
        Magic(Ts... args) : myStuff{std::forward_as_tuple(args...)}{}
        void DoAllThings(int i)
        {
            ThingHelper(i, tuple_seq);
        }
    private:
        std::tuple<Ts...> myStuff;
        static constexpr auto tuple_seq = std::make_index_sequence<sizeof...(Ts)>{};

        template<std::size_t... index>
        void ThingHelper(int i, std::index_sequence<index...>)
        {
            (void)std::initializer_list<int>
                {
                    (std::get<index>(myStuff).inside == i ?
                     std::get<index>(myStuff).DoThing(i) : (void)0, 0)...
                };
        }

};
int main()
{
    A a;
    B b;
    C c;
    D d;

    Magic<A,B,C,D> m {a,b,c,d};
    m.DoAllThings(5);
}
