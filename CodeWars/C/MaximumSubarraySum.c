/*
The maximum sum subarray problem consists in finding the maximum sum of a contiguous subsequence in an array or list of integers:

maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 9)
// should return 6, from sub-array: {4, -1, 2, 1}
Easy case is when the list is made up of only positive numbers and the maximum sum is the sum of the whole array. If the list is made up of only negative numbers, return 0 instead.

Empty list is considered to have zero greatest sum. Note that the empty list or array is also a valid sublist/subarray.

*/

#include <stdio.h>
#include <stddef.h>

#define MAX(a, b)   ( (a > b) ? a : b )

int maxSequence(const int* array, size_t n)
{
    if (!n) return 0;
    if ( n== 1) return array[0];
    int localMax = array[0];
    int globalMax = array[0];
    int i;
    for (i=0; i<n; i++)
    {
        localMax = MAX(array[i], array[i] + localMax);
        if ( localMax > globalMax )
        {
            globalMax = localMax;
        }
    }
    if (globalMax < 0) return 0;
    return globalMax;
}

int main ( void )
{
    const int a1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("%d\n", maxSequence( a1, sizeof(a1)/sizeof(a1[0]) ) );
    const int a2[] = {};
    printf("%d\n", maxSequence( a2, sizeof(a2)/sizeof(a2[0]) ) );
    const int a3[] =  {-2, -5, 6, -2, -3, 1, 5, -6};
    printf("%d\n", maxSequence( a3, sizeof(a3)/sizeof(a3[0]) ) );
    const int a4[] = {-2, -1, -3, -4, -1, -2, -1, -5, -4};
    printf("%d\n", maxSequence( a4, sizeof(a4)/sizeof(a4[0]) ) );

    return 0;
}
