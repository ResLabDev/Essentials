/*
Bob is a lazy man.

He needs you to create a method that can determine how many letters and digits are in a given string.

Example:

"hel2!lo" --> 6

"wicked .. !" --> 6

"!?..A" --> 1
*/

#include <stdio.h>

#include <stddef.h>
#include <ctype.h>

size_t count_letters_and_digits(const char *input)
{
    size_t count = 0;
    while (*input)
    {
        if (isalnum(*input))
        {
            count++;
        }
        input++;
    }

    return count;
}

int main (void)
{
    printf("%d\n", count_letters_and_digits("hel2!lo"));
    printf("%d\n", count_letters_and_digits("wicked .. !"));
    printf("%d\n", count_letters_and_digits("!?..A"));

    return 0;
}
