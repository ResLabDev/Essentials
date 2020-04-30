/* Note: allocate memory yourself */
/* return NULL in case num == 0 */

/*
Get the number n (n>0) to return the reversed sequence from n to 1.

Example : n=5 >> [5,4,3,2,1]
*/

#include <stdio.h>
#include <stdlib.h>

unsigned short *reverse_seq(unsigned short num)
{
    if (!num)
    {
        return NULL;
    }

    unsigned short *p_result = (unsigned short *) calloc(num, sizeof(unsigned short));
    int i = 0;

    while (num > 0)
    {
        p_result[i++] = num--;
    }

    return p_result;
}

int main (void)
{
    const unsigned short n = 5;
    unsigned short *p_result = reverse_seq(n);


    for (int i = 0; i < n; i++)
    {
        printf("%u, ", p_result[i]);
    }

    free(p_result);

    return 0;
}
