#include <stdio.h>
#include <stddef.h>
#include <string.h>


typedef struct Character_Count_Pair
{
    char character;
    size_t count;
} ccp;

ccp* ordered_count(const char *strin, size_t *szout)
{
    size_t len = strlen(strin);
    ccp *ordered = (ccp *) calloc(len, sizeof(ccp));

    ordered[0].character = *strin;
    ordered[0].count = 0;
    _Bool match = 0;
    len = 1;
    while (*strin)
    {
        for (int i = 0; i < len; ++i)
        {
            if (ordered[i].character == *strin)
            {
                ordered[i].count++;
                match = 1;
                break;
            }
        }

        if (!match)
        {
            ordered[len].character = *strin;
            ordered[len++].count = 1;
        }
        else
        {
            match = 0;
        }

        strin++;
    }

    *szout = len;
    return ordered;
}

int main (void)
{
    size_t res_size;
    ccp *res = ordered_count("abracadabra", &res_size);
    printf("%d\n", res_size);

    for(int i = 0; i < res_size; ++i)
    {
        printf("{%c, %d}, ", res[i].character, res[i].count);
    }
}
