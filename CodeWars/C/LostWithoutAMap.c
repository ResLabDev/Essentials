/*
Given an array of integers, return a new array with each value doubled.

For example:

[1, 2, 3] --> [2, 4, 6]

For the beginner, try to use the map method - it comes in very handy quite a lot so is a good one to know.
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

// Return a *new, dynamically allocated* array with each element doubled.
int *maps(const int *arr, size_t size)
{
    int *p_result = (int *) malloc(size * sizeof(int));
    if (NULL == p_result)
    {
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
        p_result[i] = 2 * arr[i];
    }

    return p_result;
}

int main (void)
{
    const int testArray[] = {1, 2, 3};
    int *p_map = maps(testArray, sizeof(testArray) / sizeof(testArray[0]));

    for (int i = 0; i < sizeof(testArray) / sizeof(testArray[0]); i++)
    {
        printf("%d, ", p_map[i]);
    }

    free(p_map);

    return 0;
}
