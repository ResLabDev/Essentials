/*
The borrowers are tiny tiny fictional people. As tiny tiny people they have to be sure they aren't spotted, or more importantly, stepped on.

As a result, the borrowers talk very very quietly. They find that capitals and punctuation of any sort lead them to raise their voices and put them in danger.

The young borrowers have begged their parents to stop using caps and punctuation.

Change the input text 's' to new borrower speak. Help save the next generation!
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *borrow(const char *source)
{
    char *p_result = (char *) calloc(strlen(source) + 1, sizeof(char));
    if (NULL == p_result)
    {
        return NULL;
    }

    int i = 0;
    while (*source)
    {
        if (isalpha(*source))
        {
            p_result[i] = tolower(*source);
            i++;
        }

        source++;
    }

    p_result[i] = '\0';

    return p_result;
}

int main (void)
{
    char *p_borrower = borrow("WhAt! FiCK! DaMn CAke?");

    printf("%s", p_borrower);

    free(p_borrower);

    return 0;
}
