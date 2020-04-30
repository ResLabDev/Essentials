/*
Complete the function scramble(str1, str2) that returns true if a portion of str1 characters can be rearranged to match str2, otherwise returns false.

Notes:
  Only lower case letters will be used (a-z). No punctuation or digits will be included.
  Performance needs to be considered
  Input strings s1 and s2 are null terminated.

Examples
  scramble('rkqodlw', 'world') ==> True
  scramble('cedewaraaossoqqyt', 'codewars') ==> True
  scramble('katas', 'steak') ==> False
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

#define ABC_SIZE ('z'-'a' + 1)

bool scramble(const char *str1, const char *str2)
{
    size_t str2Size = strlen(str2);
    if ( (str1 == NULL) || (str2 == NULL) || (str2Size > strlen(str1)) )
    {
        return false;
    }

    int i=0;
    int str1Letter[ABC_SIZE] = {0};
    int str2Letter[ABC_SIZE] = {0};

    while (str1[i])
    {
        str1Letter[str1[i]-'a']++;
        if ( i<str2Size )
        {
            str2Letter[str2[i]-'a']++;
        }
        i++;
    }
    // Comparison
    for (i=0; i<ABC_SIZE; i++)
    {
        if ( str1Letter[i] < str2Letter [i])
        {
            return false;
        }
    }

    return true;
}


int main( void )
{
    printf( scramble("rkqodlw", "world") ? "True\n" : "False\n" );
    printf( scramble("cedewaraaossoqqyt", "codewars") ? "True\n" : "False\n" );
    printf( scramble("katas", "steak") ? "True\n" : "False\n" );

    return 0;;
}
