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
    int i, j, count;
    int mark[szin];
    int delCount = 0;

    if ( szin <= 1)
    {
        *szout = szin;
        return order;
    }

    mark[0] = 0;
    for (i=1; i<szin; i++)
    {
        if ( mark[i-1] )
        {
            continue;
        }
        count = 1;
        for (j=i; j<szin; j++)
        {
            if ( i == 1)
            {
                mark[j] = 0;
            }
            if ( order[i-1] != order[j] )
            {
                continue;
            }
            else
            {
                count++;
                if ( count >  max_e)
                {
                    mark[j] = -1;
                    delCount++;
                }
                else
                {
                    mark[j] = 1;
                }
            }
        }
    }
    count = 0;
    res = (int *)calloc( (szin-delCount), sizeof(int) );
    for (i=0; i<szin; i++)
    {
        if (mark[i] != -1)
        {
            res[count++] = order[i];
        }
    }
    *szout = count;

    return res;
}

int main( void )
{
    int samples[] = {1, 1, 3, 3, 3, 7, 2, 2, 2, 2};
    int *result;
    int resultSize, i;

    result = delete_nth(sizeof(samples)/sizeof(int), samples , 2, &resultSize);
    printf("{");
    for (i=0; i<resultSize; i++)
    {
        printf(" %d ", result[i]);
    }
    printf("} %d\n", resultSize);

    return 0;
}

