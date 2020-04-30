/*
Given a triangle of consecutive odd numbers:

             1
          3     5
       7     9    11
   13    15    17    19
21    23    25    27    29
...
find the triangle's row knowing its index (the rows are 1-indexed), e.g.:

odd_row(1)  ==  [1]
odd_row(2)  ==  [3, 5]
odd_row(3)  ==  [7, 9, 11]
Note: your code should be optimized to handle big inputs.
*/

#include <stdio.h>
#include <stdlib.h>

unsigned long long *oddrow(size_t inx)
{

    unsigned long long *p_result = (unsigned long long *) calloc(sizeof(unsigned long long), inx);
    unsigned long long *p_resultCurrent = p_result;
    unsigned long long current;
    *p_result = (unsigned long long) ( ((inx - 1) * inx) + 1);

    if (1 == inx)
    {
        return p_result;
    }

    while (inx --> 1)
    {
        current = *p_resultCurrent;
        *(++p_resultCurrent) = current + 2;
    }

    return p_result;
}

int main (void)
{
    size_t row = 5;
    unsigned long long *p_res = oddrow(row);
    for (int i = 0; i < row; ++i)
    {
        printf("%lu, ", p_res[i]);
    }

    free(p_res);

    return 0;
}
