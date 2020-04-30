/*
Story
    The Pied Piper has been enlisted to play his magical tune and coax all the rats out of town.

    But some of the rats are deaf and are going the wrong way!

    Kata Task
    How many deaf rats are there?

    Legend
    P = The Pied Piper
    O~ = Rat going left
    ~O = Rat going right
    Example
    ex1 ~O~O~O~O P has 0 deaf rats
    ex2 P O~ O~ ~O O~ has 1 deaf rat
    ex3 ~O~O~O~OP~O~OO~ has 2 deaf rats
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define RAT_LEFT    "O~"
#define RAT_RIGHT   "~O"
#define PIED_PIPER  'P'

static int DetectDeafRat (const char *rat, bool b_leftDirection)
{
    bool b_deafRat = false;

    if (b_leftDirection)
    {
        b_deafRat = (strcmp(rat, RAT_LEFT)) ? false : true;
    }
    else
    {
        b_deafRat = (strcmp(rat, RAT_RIGHT)) ? false : true;
    }

    return (b_deafRat) ? 1 : 0;
}

int countDeafRats(const char *town)
{
    bool b_leftDirection = true;
    int deafRats = 0;
    char rat[3] = {'\0'};
    int ratPartIndex = 0;

    for (int i = 0; i < strlen(town); i++)
    {
        // Check direction
        if (town[i] == PIED_PIPER)
        {
            b_leftDirection = false;
        }
        // Check acceptable values
        if ((town[i] == RAT_LEFT[0]) || (town[i] == RAT_LEFT[1]))
        {
            rat[ratPartIndex] = town[i];
            ratPartIndex++;
            if (ratPartIndex == strlen(RAT_LEFT))
            {
                deafRats += DetectDeafRat(rat, b_leftDirection);
                ratPartIndex = 0;
            }
        }
    }

    return deafRats;
}

int main (void)
{
    printf("%d\n", countDeafRats("~O~O~O~O P"));
    printf("%d\n", countDeafRats("P O~ O~ ~O O~"));
    printf("%d\n", countDeafRats("~O~O~O~OP~O~OO~"));

    return 0;
}
