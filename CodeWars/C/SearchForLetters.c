// https://www.codewars.com/kata/52dbae61ca039685460001ae/train/c

#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <ctype.h>

#define ABC_LEN 26

char *change(const char *str_in)
{
    char *res = (char *) calloc( ABC_LEN + 1, sizeof(char) );

    int i;
    for (i = 0; i < ABC_LEN; ++i)
    {
        res[i] = '0';
    }
    res[ABC_LEN] = '\0';

    while (*str_in)
    {
        if (isalpha(*str_in) )
        {
            i = isupper(*str_in) ? (int) (*str_in - 'A') : (int) (*str_in - 'a');
            if ( '0' == res[i] )
            {
                res[i] = '1';
            }
        }

        str_in++;
    }

    return res;
}

int main (void)
{
    char *res = change("a **&  bZ");
    printf("%s", res);

    free(res);

    return 0;
}
