/*
Given two integers a and b, which can be positive or negative, find the sum of all the numbers between including them too and return it. If the two numbers are equal return a or b.

Note: a and b are not ordered!

Examples
GetSum(1, 0) == 1   // 1 + 0 = 1
GetSum(1, 2) == 3   // 1 + 2 = 3
GetSum(0, 1) == 1   // 0 + 1 = 1
GetSum(1, 1) == 1   // 1 Since both are same
GetSum(-1, 0) == -1 // -1 + 0 = -1
GetSum(-1, 2) == 2  // -1 + 0 + 1 + 2 = 2
*/

#include <stdio.h>

#define SWAP(a, b) { a ^= b; b ^= a; a ^= b; }

int get_sum(int a , int b) {
    if (a > b) SWAP(a, b);

    return ( ((a + b) * (b-a+1)) >> 1);
}


int main (void)
{
    printf("%d\n", get_sum(-1, 2));

    return 0;
}
