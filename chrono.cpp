// Playing with std::chrono overloads to functions
#include <chrono>
#include <iostream>

void func (std::chrono::milliseconds m){std::cout<< m << std::endl;}
void func (long long m){func(std::chrono::milliseconds{m});}

int main()
{
    std::chrono::minutes m {5};
    func(m);
    func(6);
}
