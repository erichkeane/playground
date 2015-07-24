// Another simple teset to show the effects of references
// and const on the auto type
#include <iostream>

double b = 0;
 double& bar()
{
    return b;
}

int main()
{
    auto bcopy = bar();
    bcopy ++;
    std::cout<<"BCopy: "<< bcopy<<" " <<  b<<std::endl;

    auto& bref = bar();
    bref++;
    std::cout<<"BRef: " << bref <<" " <<  b <<std::endl;

    const auto& bref2 = bar();
    bref2++;
    std::cout<<"BRef2: " << bref2 <<" " <<  b <<std::endl;

}

