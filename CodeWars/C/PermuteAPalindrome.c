/*
Write a function that will check whether the permutation of an input string is a palindrome. Bonus points for a solution that is efficient and/or that uses only built-in language functions. Deem yourself brilliant if you can come up with a version that does not use any function whatsoever.

Example
madam -> True
adamm -> True
junk -> False

Hint
The brute force approach would be to generate all the permutations of the string and check each one of them whether it is a palindrome. However, an optimized approach will not require this at all.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define ALPHA_SIZE ('z' - 'a')

bool permute_a_palindrome(const char *str_in)
{
    if (strlen(str_in) < 2)
    {
        return true;
    }

    int countChar[ALPHA_SIZE + 1] = {0};

    int length = 0;
    while (*str_in)
    {
        if (isalpha(*str_in))
        {
            countChar[tolower(*str_in) - 'a']++;
            length++;
        }
        str_in++;
    }

    bool b_disableOdd = (length & 0x1) ? false : true;

    for (int i = 0; i <= ALPHA_SIZE; i++)
    {
        if (countChar[i] & 0x1)
        {
            if (b_disableOdd)
            {
                return false;
            }
            else
            {
                b_disableOdd = true;
            }
        }
    }

    return true;
}

int main (void)
{
    printf(permute_a_palindrome("hello") ? "TRUE" : "FALSE");
}
