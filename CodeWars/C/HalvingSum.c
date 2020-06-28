#include <stdio.h>

unsigned halving_sum(unsigned n)
{
    unsigned sum = n;

    while (n >>= 1)
    {
        sum += n;
    }

    return sum;
}

unsigned halving_sum_rec(unsigned n)
{
    return n ? n + halving_sum(n >> 1) : 0;
}

int main (void)
{
    printf("%d", halving_sum(25));

    return 0;
}
