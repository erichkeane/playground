// Double-checks the layout of multi-D arrays in C/C++
#include <iostream>

void printit(int* arr)
{
    for (int i = 0; i < 27; ++i)
    {
        std::cout << arr[i]<<std::endl;
    }
}
int main()
{
    int arr[3][3][3]=
    {
        {
            {0,1,2},
            {3,4,5},
            {6,7,8}
        },
        {
            {9,10,11},
            {12,13,14},
            {15,16,17}
        },
        {
            {18,19,20},
            {21,22,23},
            {24,25,26}
        }
    };
    printit((int*)arr);
}

