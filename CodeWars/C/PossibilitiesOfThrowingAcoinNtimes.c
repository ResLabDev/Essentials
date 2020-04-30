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

const char nibbles[16][5] =
{
    "HHHH", "HHHT", "HHTH", "HHTT",
    "HTHH", "HTHT", "HTTH", "HTTT",
    "THHH", "THHT", "THTH", "THTT",
    "TTHH", "TTHT", "TTTH", "TTTT"
};

char *coin(int n)
{
    int possibilities = (2 << (n-1));
    const size_t resultSize = possibilities * (n + 1);

    char *p_result = (char *) calloc(resultSize + 1, sizeof(char));

    if (NULL == p_result)
    {
        return NULL;
    }

    *p_result = '\0';

    char coin;
    int nibbleNum = n / 4;
    int digitRemain = n % 4;

    int commaLimit = possibilities - 1;
    int k = 0;
    for (int i = 0; i < possibilities; i++)
    {
        for (int j = digitRemain; j > 0; j--)
        {
            k = i >> ((nibbleNum * 4) + (j-1));
            coin = (k & 0x1) ? 'T' : 'H';
            strncat(p_result, &coin, 1);
        }
        for (int j = nibbleNum; j > 0; j--)
        {
            k = (i >> (4 * (j-1))) & 0xf;
            strncat(p_result, nibbles[k], 4);
        }
        if (i != commaLimit)
        {
            strncat(p_result, ",", 1);
        }
    }

    return p_result;
}

int main (void)
{
    char *p_coin = coin(8);

    printf("%s", p_coin);

    free(coin);

    return 0;
}
