/*
In this kata you will be given an integer n, which is the number of times that is thown a coin. You will have to return an array of string for all the possibilities (heads[H] and tails[T]). Examples:

coin(1) should return {"H", "T"}
coin(2) should return {"HH", "HT", "TH", "TT"}
coin(3) should return {"HHH", "HHT", "HTH", "HTT", "THH", "THT", "TTH", "TTT"}

When finished sort them alphabetically.

In C and C++ just return a char* with all elements separated by, (without space):
coin(2) should return "HH,HT,TH,TT"

INPUT:
0 < n < 18

Careful with performance!! You'll have to pass 3 basic test (n = 1, n = 2, n = 3), many medium tests (3 < n <= 10) and many large tests (10 < n < 18)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* coin(int n)
{
    int possibilities = (2 << (n-1));
    char coin;
    const size_t resultSize = possibilities * (n + 1);

    char *p_result = (char *) calloc(resultSize + 1, sizeof(char));

    char resultShadow[resultSize + 1];
    char buffer[n + 1];

    if (NULL == p_result)
    {
        return NULL;
    }

    p_result[0] = '\0';
    resultShadow[0] = '\0';
    for (int i = 0; i < possibilities; i++)
    {
        buffer[0] = '\0';
        for (int j = (n - 1); j >= 0; j--)
        {
            coin = ((i >> j) & 0x1) ? 'T' : 'H';
            strncat(buffer, &coin, 1);
        }

        strcpy(resultShadow, p_result);
        snprintf(p_result, resultSize, "%s%s,", resultShadow, buffer);
    }

    return p_result;
}

int main (void)
{
    char *p_coin = coin(15);
    printf("%s", p_coin);

    free(p_coin);

    return 0;
}
