// Playing with functionality of boost::replace_all_copy
#include <boost/algorithm/string/replace.hpp>
#include <iostream>



int main()
{
    std::string a = "asdkfjqpweofijaskldfjasdkl%^alksdfjaklsdfj;%kjl;askldfjas";

    std::cout << a << std::endl;
    std::string b = boost::replace_all_copy(a, "%", "%%");
    std::cout << b << std::endl;

}

