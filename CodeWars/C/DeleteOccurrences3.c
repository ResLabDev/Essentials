/*

Task
Given a list lst and a number N, create a new list that contains each number of lst at most N times without reordering. For example if N = 2, and the input is [1,2,3,1,2,1,2,3], you take [1,2,3,1,2], drop the next [1,2] since this would lead to 1 and 2 being in the result 3 times, and then take 3, which leads to [1,2,3,1,2,3].

For C:

Assign the return array length to the pointer parameter *szout.
Do not mutate the input array.
Example
delete_nth(4, {1, 1, 1, 1}, 2, *p)     // returns {1, 1}, 2
delete_nth(4, {20, 37, 20, 21}, 1, *p) // returns {20, 37, 21}, 3

*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int* delete_nth(size_t szin, int order[szin], int max_e, size_t *szout)
{
    int *res;
    int i, max=0;
    int temp[szin];

    if ( szin <= 1)
    {
        *szout = szin;
        return order;
    }
    for (i=0; i<szin; i++)
    {
        if (order[i] > max)
        {
            max = order[i];
        }
    }

    int count[max+1];
    for (i=0; i<szin; i++)
    {
        count[order[i]] = 0;
    }
    max = 0;
    for (i=0; i<szin; i++)
    {
        count[order[i]]++;
        if (count[order[i]] <= max_e)
        {
            temp[max] = order[i];
            max++;
        }
    }

    res = (int *)calloc(max, sizeof(int));
    for(i=0; i<max; i++)
    {
        res[i] = temp[i];
    }

    *szout = max;

    return res;
}

int main( void )
{
    int samples[] = {1, 1, 3, 3, 3, 7, 2, 2, 2, 2};
    int *result;
    int resultSize, i;

    result = delete_nth(sizeof(samples)/sizeof(int), samples , 3, &resultSize);
    printf("{");
    for (i=0; i<resultSize; i++)
    {
        printf(" %d ", result[i]);
    }
    printf("} %d\n", resultSize);

    return 0;
}

