// Simple implementation of atoi in C++ using std::string
#include <iostream>
#include <string>
#include <climits>

using namespace std;
class Solution {

    public:
    int myAtoi(string str) {
        auto itr = str.begin();
        bool neg = false;

        while(*itr == ' ')++itr;
        if (*itr == '-')
        {
        neg = true;
        ++itr;
        }

        else if (*itr== '+') ++itr;
        long long total = 0;
        while (*itr >= '0' && *itr <='9' && (total == ((int)total)))
        {
        total *=10;
        total += (int)(*itr - '0');
        ++itr;
        }

        int newTotal = (int)total;

        if (newTotal != total)
        {
        if (neg)
        return INT_MIN;
        else
        return INT_MAX;
        }

        if (neg) newTotal = -newTotal;
        return newTotal;
    }

};


int main()
{
    Solution s;
    std::cout<< s.myAtoi("18446744073709551617");
}
