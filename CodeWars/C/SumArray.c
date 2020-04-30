/*

Write a method sum (sum_array in python, sumarray in julia, SumArray in C#) that takes an array of numbers and returns the sum of the numbers.
These may be integers or decimals for Ruby and any instance of Num for Haskell. The numbers can also be negative. If the array does not contain any numbers then you should return 0.

numbers = [1, 5, 4, 0, -1]
puts sum(numbers)
9

*/

#include <stdio.h>

int sum_array(const int *values, size_t count)
{
    int sum = 0;

    while (count--)
    {
        sum += values[count];
    }

    return sum;
}

int main ( void )
{
    int numbers[] = {1, 5, 4, 0, -1};

    printf("Sum: %d\n", sum_array(numbers, sizeof(numbers)/sizeof(int)));

    return 0;
}
