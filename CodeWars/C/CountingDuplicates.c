/*
Count the number of Duplicates
Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits that occur more than once in the input string. The input string can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digits.

Example
"abcde" -> 0 # no characters repeats more than once
"aabbcde" -> 2 # 'a' and 'b'
"aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
"indivisibility" -> 1 # 'i' occurs six times
"Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
"aA11" -> 2 # 'a' and '1'
"ABBA" -> 2 # 'A' and 'B' each occur twice

*/

#include <stdio.h>
#include <stddef.h>
#include <ctype.h>

size_t duplicate_count(const char * text)
{
    size_t duplicateAlpha = 0;
    int countAlpha['Z' + 1] = {0};
    int alphaIndex;

    while (*text)
    {
        alphaIndex = (*text > 'Z') ? toupper(*text) : *text;
        if (countAlpha[alphaIndex]++ == 1)
        {
            duplicateAlpha++;
        }
        text++;
    }

    return duplicateAlpha;
}

int main (int argv, char **argc)
{
    printf("%d, exp. : 0\n", duplicate_count("abcde"));
    printf("%d, exp. : 1\n", duplicate_count("abcdea"));
    printf("%d, exp. : 1\n", duplicate_count("indivisibility"));

    return 0;
}
