// Another simple lexical-cast variation, this time trying to validate the
// to-string nature of the locale.
#include <iostream>
#include <boost/lexical_cast.hpp>

int main()
{
    setlocale(LC_ALL, "ja_JP");
    setlocale(LC_NUMERIC, "ja_JP");

    std::cout<<boost::lexical_cast<std::string>(555555555)<<std::endl;
}
