/*
You know what divisors of a number are. The divisors of a positive integer n are said to be proper when you consider only the divisors other than n itself. In the following description, divisors will
mean proper divisors. For example for 100 they are 1, 2, 4, 5, 10, 20, 25, and 50.

Let s(n) be the sum of these proper divisors of n. Call buddy two positive integers such that the sum of the proper divisors of each number is one more than the other number:

(n, m) are a pair of buddy if s(m) = n + 1 and s(n) = m + 1

For example 48 & 75 is such a pair:

Divisors of 48 are: 1, 2, 3, 4, 6, 8, 12, 16, 24 --> sum: 76 = 75 + 1
Divisors of 75 are: 1, 3, 5, 15, 25 --> sum: 49 = 48 + 1
Task
Given two positive integers start and limit, the function buddy(start, limit) should return the first pair (n m) of buddy pairs such that n (positive integer) is between start (inclusive)
and limit (inclusive); m can be greater than limit and has to be greater than n

If there is no buddy pair satisfying the conditions, then return "Nothing" or (for Go lang) nil

Examples

buddy(10, 50) returns "(48 75)"
buddy(48, 50) returns "(48 75)"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define STRING_LENGTH 50

long long sum_of_div(long long number)
{
    int sqrt_n = sqrt(number), sum = 1;
    int i, limit;

    if (sqrt_n * sqrt_n == number)
    {
        limit = sqrt_n - 1;
    }
    else
    {
        limit = sqrt_n;
    }
    for (i=2; i<=limit; i++)
    {
        if ( !(number % i) )
        {
            sum += i;
            sum += number / i;
        }
    }

    return sum;
}

char *buddy(long long start, long long limit)
{
    char *res;
    long long i, j;
    long long sum;

    res = (char *)calloc(STRING_LENGTH, sizeof(char));
    for (i = start; i <= limit; i++)
    {
        sum = sum_of_div(i);

        // Validation
        if ( i == (sum_of_div(sum-1)-1) )
        {
            sprintf(res, "(%llu %llu)", i, sum-1);
            return res;
        }
    }
    strcpy(res, "Nothing");

    return res;
}

int main(void)
{

    printf("%s\n", buddy(10, 50));
    printf("%s\n", buddy(2382, 3679));
    printf("%s\n", buddy(8983, 13355));
    printf("%s\n", buddy(1071625, 1103735));
    printf("%s\n", buddy(14656, 20372));
}
