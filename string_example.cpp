// example of string-view
#include <iostream>
#include <experimental/string_view>
using std::string;
using std::cout;
using std::endl;
using std::experimental::string_view;

string extractB(string_view o)
{
    // remove braces
    auto wobraces = o.substr(1, o.size() -2);
    auto justB = wobraces.substr(wobraces.find('b') - 1);
    auto justVal = justB.substr(justB.find(':') + 1);
    auto noQuotes = justVal.substr(1, justVal.size() - 2);
    return noQuotes;
}

int main()
{
    string orig = "{'a':'aval','b':'bval'}";
    string after = extractB(orig);

    cout << after <<endl;
}
