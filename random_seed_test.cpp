// Provides a SeedSequence replacement (not standards compliance)
#include <random>
#include <array>
#include <algorithm>
#include <iostream>
#include <functional>

template <class RandType>
class GenSeq
{
    public:
    GenSeq(RandType& rt):_rt(rt){}
    size_t size() const{ return std::numeric_limits<size_t>::max();}

    template< class RandomIt>
    void generate( RandomIt begin, RandomIt end)
    {
        std::generate(begin, end, std::ref(_rt));
    }
    private:
    RandType& _rt;
};

int main()
{
    std::random_device rd;
    GenSeq<std::random_device> seq { rd };

    std::mt19937 engine { seq };

    std::cout << engine() << '\n';
}
