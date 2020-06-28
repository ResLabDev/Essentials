// https://www.codew{ars.com/kata/59cfc000aeb2844d16000075/train/c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **capitalize(const char *test_str) {
    char **pp_res = (char **)calloc(2, sizeof(char *));
    pp_res[0] = (char *)calloc(strlen(test_str)+1, sizeof(char));
    pp_res[1] = (char *)calloc(strlen(test_str)+1, sizeof(char));

    int i = 0;
    while (*test_str)
    {
        pp_res[0][i] =   (i & 1) ? tolower(*test_str) : toupper(*test_str);
        pp_res[1][i++] = (i & 1) ? toupper(*test_str) : tolower(*test_str);
        test_str++;
    }

    pp_res[0][i] = '\0';
    pp_res[1][i] = '\0';

    return pp_res;
}

int main (void)
{
    char **pp_cap = capitalize("abcdef");
    printf("%s, %s", pp_cap[0], pp_cap[1]);

    return 0;
}
