/*
A format for expressing an ordered list of integers is to use a comma separated list of either

individual integers
or a range of integers denoted by the starting integer separated from the end integer in the range by a dash, '-'. The range includes all integers in the interval including both endpoints. It is not considered a range unless it spans at least 3 numbers. For example ("12, 13, 15-17")
Complete the solution so that it takes a list of integers in increasing order and returns a correctly formatted string in the range format.

Example:

range_extraction((const []){-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20}, 20);
returns "-6,-3-1,3-5,7-11,14,15,17-20"
*/

#include <stdio.h>

#define NUM_OF(x)   (sizeof(x)/sizeof(*x))

#include <stdlib.h>
#include <string.h>

char *range_extraction(const int *args, size_t n)
{
    int current, next, span = 0;
    const int resultSize = (10+1) * n;
    char *p_result = (char *)calloc(resultSize + 1, sizeof(char));
    if (NULL == p_result)
    {
        return NULL;
    }

    for (int i = 0; i < n; ++i)
    {
        next = (i < (n-1)) ? args[i+1] : 0;
        current = (i < (n-1)) ? args[i] : 0;

        if (current + 1 == next)
        {
            span++;
        }
        else if (1 == span)
        {
            sprintf(p_result, "%s%d,%d,", p_result, args[i-1], args[i]);
            span = 0;
        }
        else if (span > 1)
        {
            sprintf(p_result, "%s%d-%d,", p_result, args[i-span], args[i]);
            span = 0;
        }
        else
        {
            sprintf(p_result, "%s%d,", p_result, args[i]);
        }
    }

    p_result[strlen(p_result)-1] = '\0';

    return p_result;
}

int main (void)
{
    const int data[] = {-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20};

    for (int i = 0; i < NUM_OF(data); ++i)
    {
        printf("%d, ", data[i]);
    }
    puts("");
    printf("%s", range_extraction(data, NUM_OF(data)));

    return 0;
}
