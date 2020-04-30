/*
Suppose you have 4 numbers: '0', '9', '6', '4' and 3 strings composed with them:

s1 = "6900690040"
s2 = "4690606946"
s3 = "9990494604"
Compare s1 and s2 to see how many positions they have in common: 0 at index 3, 6 at index 4, 4 at index 8 ie 3 common positions out of ten.

Compare s1 and s3 to see how many positions they have in common: 9 at index 1, 0 at index 3, 9 at index 5 ie 3 common positions out of ten.

Compare s2 and s3. We find 2 common positions out of ten.

So for the 3 strings we have 8 common positions out of 30 ie 0.2666... or 26.666...%

Given n substrings (n >= 2) in a string s our function pos_average will calculate the average percentage of positions that are the same between the (n * (n-1)) / 2 sets of substrings taken amongst the given n substrings. It can happen that some substrings are duplicate but since their ranks are not the same in s they are considered as different substrings.

The function returns the percentage formatted as a float with 10 decimals but the result is tested at 1e.-9 (see function assertFuzzy in the tests).

Example:
Given string s = "444996, 699990, 666690, 096904, 600644, 640646, 606469, 409694, 666094, 606490" composing a set of n = 10 substrings (hence 45 combinations), pos_average returns 29.2592592593.

In a set the n substrings will have the same length ( > 0 ).

Notes
You can see other examples in the "Sample tests".
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 120
#define SEPARATOR   ','

static unsigned CalcMatch (const char *p_str1, const char *p_str2)
{
    unsigned match = 0;

    int i = 0;
    while (p_str1[i])
    {
        if (p_str1[i] == p_str2[i])
        {
            match++;
        }

        i++;
    }

    return match;
}

/* n - a number of substrings */
double pos_average(char *s, unsigned n)
{
    char *p_seek = s;
    char buffer[BUFFER_SIZE];
    char numbers[n][BUFFER_SIZE];
    unsigned match = 0;

    int i = 0;
    int j = 0;
    while (*p_seek)
    {
        if (isdigit(*p_seek) && (i < (int)n))
        {
            buffer[j] = *p_seek;
            j++;
        }
        else if (SEPARATOR == *p_seek)
        {
            buffer[j] = '\0';
            strcpy(numbers[i], buffer);
            i++;
            j = 0;
        }
        else
        {
            // NOP
        }

        p_seek++;
    }

    buffer[j] = '\0';
    strcpy(numbers[i], buffer);

    for (int k = 0; k < (n-1); k++)
    {
        for (int z = k + 1; z < n; z++)
        {
            match += CalcMatch(numbers[k], numbers[z]);
        }
    }

    return ( 100 * match / (double) (strlen(numbers[0]) * (n *(n -1) / 2)) );
}


int main (void)
{
    const char strIn1[] = "6900690040, 4690606946, 9990494604";
    const char strIn2[] = "444996, 699990, 666690, 096904, 600644, 640646, 606469, 409694, 666094, 606490";

    printf("%lf\n", pos_average(strIn1, 3u));
    printf("%lf\n", pos_average(strIn2, 10u));

    return 0;
}

