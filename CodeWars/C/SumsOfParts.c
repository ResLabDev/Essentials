/*
Let us consider this example (array written in general format):

ls = [0, 1, 3, 6, 10]

Its following parts:

ls = [0, 1, 3, 6, 10]
ls = [1, 3, 6, 10]
ls = [3, 6, 10]
ls = [6, 10]
ls = [10]
ls = []

The corresponding sums are (put together in a list): [20, 20, 19, 16, 10, 0]

The function parts_sums (or its variants in other languages) will take as parameter a list ls and return a list of the sums of its parts as defined above.

Other Examples:
ls = [1, 2, 3, 4, 5, 6]
parts_sums(ls) -> [21, 20, 18, 15, 11, 6, 0]

ls = [744125, 935, 407, 454, 430, 90, 144, 6710213, 889, 810, 2579358]
parts_sums(ls) -> [10037855, 9293730, 9292795, 9292388, 9291934, 9291504, 9291414, 9291270, 2581057, 2580168, 2579358, 0]
Notes
Some lists can be long.
Please ask before translating: some translations are already written and published when/if the kata is approved.
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

unsigned long long *parts_sums(size_t *len, const unsigned long long *ls, size_t n)
{
    unsigned long long sum = 0;
    int i;
    unsigned long long *sop;
    sop = (unsigned long long *)calloc(n + 1, sizeof(unsigned long long) );
    if (sop == NULL)
    {
        *len = 0;
        return NULL;
    }
    *len = 0;
    if (!n)
    {
        *len = 1;
        return sop;
    }
    for (i=n-1; i>=0; i--)
    {
        sum += ls[i];
        sop[i] = sum;
        (*len)++;
    }
    (*len)++;
    sop[n] = 0;
    return sop;
}

int main (int argc, char **argv)
{
    const unsigned long long a0[] = {1, 2, 3, 4, 5, 6};
    unsigned long long *sop;
    size_t sopLength;
    sop = parts_sums( &sopLength, a0, sizeof(a0) / sizeof(a0[0]) );
    int i;
    for (i=0; i<sopLength; i++)
    {
        printf("%d, ", sop[i]);
    }
    free(sop);

    return 0;
}
