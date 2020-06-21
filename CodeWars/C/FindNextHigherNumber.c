// https://www.codewars.com/kata/56bdd0aec5dc03d7780010a5/train/c

#include <stdio.h>
#include <stdbool.h>

int next_higher(int n)
{
    int res = 0;
    int exp = 0;
    bool swapped = 0;
    int numOfOnes = 0;
    int bits = n;
    while (bits)
    {
        if (((bits >> 1) & 1) || swapped)
        {
            res += ((bits & 1) << exp++);
        }
        else
        {
            res += (2 << exp++);
            bits >>= 1;
            exp++;
            swapped = 1;
        }

        if (bits & 1)
        {
            numOfOnes++;
        }

        bits >>= 1;
    }

    return (1 == numOfOnes) ? (n << 1) : res;
}


int main (void)
{
    printf("%d\n", next_higher(128));
    printf("%d\n", next_higher(7));
    printf("%d\n", next_higher(55));
    printf("%d\n", next_higher(129));
    printf("%d\n", next_higher(127));
    printf("%d\n", next_higher(1022));

    return 0;
}
