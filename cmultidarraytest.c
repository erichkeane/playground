// Shows the contiguous nature and ordering of a C
// multi-dimensional array
#include <stdio.h>

void printarray(int* array, size_t size)
{
    printf("Size is: %u\n", size);
    for(size_t i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int a[5] = {};
    int b[5][10] = {{2}};
    int c[3][10][3] = {};
    printarray((int*)a, sizeof(a)/sizeof(int));
    printarray((int*)b, sizeof(b)/sizeof(int));
    printarray((int*)c, sizeof(c)/sizeof(int));
}
