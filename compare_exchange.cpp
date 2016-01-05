// example of a use-count implementation using std::atomic/compare_exchange_weak
#include <iostream>
#include <thread>
#include <atomic>

struct UseCount
{
    std::atomic<unsigned int> m_atomic;

    UseCount() : m_atomic(0){}
    void markInUse()
    {
        ++m_atomic;
    }

    void unmarkInUse()
    {
        auto start = m_atomic.load();

        while(start > 0 && m_atomic.compare_exchange_weak(start, start - 1))
        {}

        std::cout << start << '\n';
    }
};

UseCount c;

void DoStuff()
{
    c.markInUse();
    c.markInUse();
    c.unmarkInUse();
    c.markInUse();
    c.markInUse();
    c.unmarkInUse();
    c.unmarkInUse();
    c.unmarkInUse();
    c.unmarkInUse();
    c.unmarkInUse();
    c.unmarkInUse();
    c.markInUse();
    c.unmarkInUse();
    c.markInUse();
    c.unmarkInUse();
}


int main()
{
    std::thread t (DoStuff);
    std::thread t2 (DoStuff);
    std::thread t3 (DoStuff);
    std::thread t4 (DoStuff);
    std::thread t5 (DoStuff);
    std::thread t6 (DoStuff);

    t.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
}
