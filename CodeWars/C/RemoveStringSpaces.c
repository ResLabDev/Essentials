/*
Simple, remove the spaces from the string, then return the resultant string.

For C, you must return a new dynamically allocated string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *no_space(const char *str_in)
{
    char *p_buffer = (char *) calloc(length + 1, sizeof(char));
    if (NULL == p_buffer)
    {
        return NULL;
    }
    char *p_result = p_buffer;

    while (*str_in)
    {
        if (*str_in != ' ')
        {
            *p_buffer++ = *str_in;
        }
        str_in++;
    }
    *p_buffer = '\0';

    return p_result;
}

int main (void)
{
    char input[] = "HELLO WORLD";
    char *p_res = no_space(input);

    printf("%s - %s", input, p_res);

    free(p_res);
}
