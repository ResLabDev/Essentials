/*
Given an array of ones and zeroes, convert the equivalent binary value to an integer.
Eg: [0, 0, 0, 1] is treated as 0001 which is the binary representation of 1.
However, the arrays can have varying lengths, not just limited to 4.
*/

#include <stdio.h>
#include <stddef.h>

unsigned binary_array_to_numbers(const unsigned *bits, size_t count)
{
    unsigned i;
    unsigned result = 0;

    for (i=0; i<count; i++)
    {
        result = result << 1 | bits[i];
    }

    return result;
}

int main(void)
{
    unsigned bit_stream[] = {1, 0, 1, 0, 0};

    printf("%u", binary_array_to_numbers(bit_stream, (sizeof(bit_stream)/sizeof(unsigned))));

    return 0;
}
