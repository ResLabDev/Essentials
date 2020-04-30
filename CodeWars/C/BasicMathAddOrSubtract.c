/*
In this kata, you will do addition and subtraction on a given string. The return value must be also a string.
Note: the input will not be empty.
Examples

"1plus2plus3plus4"  --> "10"
"1plus2plus3minus4" -->  "2"
*/

#include <stdio.h>

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 10

char *calc (const char *s)
{
    char buffer[BUFFER_SIZE] = {'\0'};
    int i = 0, result = 0;
    char op = '\0';

    while (*s)
    {
        if (isdigit(*s))
        {
            buffer[i++] = *s;
        }
        else if ( ('p' == *s) || ('m' == *s) )
        {
            buffer[i] = '\0';
            result = ('\0' == op) ? atoi(buffer) :
                     ('p' == op)  ? result + atoi(buffer) : result - atoi(buffer);
            i = 0;
            op = *s;
        }
        s++;
    }

    buffer[i] = '\0';
    result += ('p' == op)  ? atoi(buffer) : (-1 * atoi(buffer));

    snprintf(buffer, BUFFER_SIZE, "%d", result);
    char *p_ret = (char *)calloc(strlen(buffer) + 1, sizeof(char));
    strcpy(p_ret, buffer);

    return p_ret;
}


int main (void)
{

    printf("%s\n", calc("39plus0plus119plus121minus96minus117plus93"));
    return 0;
}
