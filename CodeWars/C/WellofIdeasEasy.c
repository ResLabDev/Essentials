// Well of Ideas - Easy Version
/*
For every good kata idea there seem to be quite a few bad ones!
In this kata you need to check the provided array (x) for good ideas 'good' and bad ideas 'bad'. If there are one or two good ideas, return 'Publish!',
if there are more than 2 return 'I smell a series!'. If there are no good ideas, as is often the case, return 'Fail!'.
In C: do not dynamically allocate memory,
      instead return a string leteral
*/

#include <stdio.h>
#include <stddef.h>

const char* well (size_t n, const char const* ideas[n])
{
    int i, idea = 0;
    for (i = 0; i < n; i++)
    {
        if (ideas[i][0] ==  'g')
            idea++;
    }

    return (!idea) ? "Fail!" :
           (idea <= 2) ? "Publish!" : "I smell a series!";
}

int main (void)
{
    const char const* ideas[] = {"bad", "bad", "bad"};
    printf("%s\n", well(sizeof(ideas) / sizeof(ideas[0]), ideas));

    const char const* ideas1[] = {"good", "bad", "bad", "bad", "bad"};
    printf("%s\n", well(sizeof(ideas1) / sizeof(ideas1[0]), ideas1));

    const char const* ideas2[] = {"good", "bad", "bad", "bad", "bad", "good", "bad", "bad", "good"};
    printf("%s\n", well(sizeof(ideas2) / sizeof(ideas2[0]), ideas2));

    return 0;
}
