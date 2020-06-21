// https://www.codewars.com/kata/54599705cbae2aa60b0011a4/train/c

#include <stdio.h>

#include <stdbool.h>
#include <stddef.h>

typedef bool (*Predicate)(int);

bool bigger_than_ten(int x) {return x > 10; }
bool greater_than_9(int x) { return x > 9; }
bool equals_9(int x) { return x == 9; }
bool less_than_9(int x) { return x < 9; }

bool one(const int* arr, size_t size, Predicate fun)
{
    int trueCount = 0;
    while (size --> 0)
    {
        trueCount += (int)fun(*arr++);

        if (trueCount > 2) return false;
    }

    return (1 == trueCount);
}

int main (void)
{
    const int arr[] = {1, 3, 5, 6, 99, 1, 3};
    printf( one(arr, sizeof(arr)/sizeof(arr[0]), bigger_than_ten) ? "TRUE\n" : "FALSE\n");

    const int arr2[] = {1, 3, 5, 6, 99, 88, 3};
    printf( one(arr2, sizeof(arr2)/sizeof(arr2[0]), bigger_than_ten) ? "TRUE\n" : "FALSE\n");

    const int arr3[] = {1, 3, 5, 6, 5, 1, 3};
    printf( one(arr3, sizeof(arr3)/sizeof(arr3[0]), bigger_than_ten) ? "TRUE\n" : "FALSE\n");

    const int arr4[] = { 6, 7, 8, 9, 10, 11 };
    printf( one(arr4, sizeof(arr4)/sizeof(arr4[0]), greater_than_9) ? "TRUE\n" : "FALSE\n");
    printf( one(arr4, sizeof(arr4)/sizeof(arr4[0]), equals_9) ? "TRUE\n" : "FALSE\n");
    printf( one(arr4, sizeof(arr4)/sizeof(arr4[0]), less_than_9) ? "TRUE\n" : "FALSE\n");

    return 0;
}
