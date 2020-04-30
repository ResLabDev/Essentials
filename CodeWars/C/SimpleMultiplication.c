/*
Multiplying a given number by eight if it is an even number and by nine otherwise.
*/

#include <stdio.h>

int simple_multiplication(int number)
{
    if      // Odd
    {
        return (number * 9);
    }
    else                // Even
    {
        return (number << 3);
    }
}


int main(void)
{
    printf("%d %d", simple_multiplication(4), simple_multiplication(7));

    return 0;
}
