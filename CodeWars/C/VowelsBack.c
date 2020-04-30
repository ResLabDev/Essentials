/*
You need to play around with the provided string (s).
Move consonants forward 9 places through the alphabet. If they pass 'z', start again at 'a'.
Move vowels back 5 places through the alphabet. If they pass 'a', start again at 'z'. For our Polish friends this kata does not count 'y' as a vowel.

Exceptions:
If the character is 'c' or 'o', move it back 1 place. For 'd' move it back 3, and for 'e', move it back 4.
If a moved letter becomes 'c', 'o', 'd' or 'e', revert it back to it's original value.
Provided string will always be lower case, won't be empty and will have no special characters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum
{
    consonant,
    vowel,
    special
} alphaType_t;

static const char specials[] = {'c', 'o', 'd', 'e'};

static bool IsSpecial (const char ch)
{
    bool b_ret = false;

    for (int i = 0; i < (sizeof(specials) / sizeof(specials[0])); i++)
    {
        if (ch == specials[i])
        {
            b_ret = true;
            break;
        }
    }

    return b_ret;
}

static int MoveCalc (const char ch)   // Special characters: c, o, d, e
{
    int move = 0;

    const char vowels[] = {'a', 'i', 'u'};

    alphaType_t charType = consonant;

    for (int i = 0; i < (sizeof(vowels) / sizeof(vowels[0])); i++)
    {
        if (ch == vowels[i])
        {
            charType = vowel;
            break;
        }
    }

    if (charType != vowel)
    {
        if (IsSpecial(ch))
        {
            charType = special;
        }
    }

    switch (charType)
    {
        case consonant:
            move = 9;
            break;
        case vowel:
            move = - 5;
            break;
        case special:
            move = (ch == specials[2]) ? -3 :
                   (ch == specials[3]) ? -4 : -1;
            break;
        default:
            break;

    }

    return move;
}

char *vowel_back (const char *str_in)
{
    char *p_result = (char *) malloc((strlen(str_in) + 1) * sizeof(char));

    if (NULL == p_result)
    {
        return NULL;
    }

    int calc;
    int i = 0;
    while(str_in[i])
    {
        calc = (int)(str_in[i]) + MoveCalc(str_in[i]);

        p_result[i] = (calc > 'z') ? (char)(calc - 'z' - 1 + 'a') :
                      (calc < 'a') ? (char)('z' - ('a' - calc  - 1)) : (char)calc;

        if (IsSpecial(p_result[i]))
        {
            p_result[i] = str_in[i];    // Revert if sepcial detected
        }

        i++;
    }

    p_result[i] = '\0';

    return p_result;
}

int main (int argv, char **argc)
{
    char *result;

    printf("%s", result = vowel_back("codewars"));

    free(result);

    return 0;
}
