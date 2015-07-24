// Small example of lexical_cast being used from string to int

#include <boost/lexical_cast.hpp>

int main()
{
//    std::string str = "2324811729";
    std::string str = "2324811729";

    unsigned int i = boost::lexical_cast<unsigned int>(str);

    std::cout<<"str: "<<str<<":  i"<<i<<std::endl;
    return 0;
}
