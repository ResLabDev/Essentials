/*
You probably know the "like" system from Facebook and other pages. People can "like" blog posts, pictures or other items. We want to create the text that should be displayed next to such an item.
Implement a function likes :: [String] -> String, which must take in input array, containing the names of people who like an item. It must return the display text as shown in the examples:
* return must be an allocated string
* do not mutate input
likes({})                                   // should return "no one likes this"
likes({"Peter"})                            // should return "Peter likes this"
likes({"Jacob", "Alex"})                    // should return "Jacob and Alex like this"
likes({"Max","John","Mark"})                // should return "Max, John and Mark like this"
likes({"Alex", "Jacob", "Mark", "Max"})     // should return "Alex, Jacob and 2 others like this"
For 4 or more names, the number in and 2 others simply increases.
*/

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

// A constant pointer to a constant char
char* likes(size_t n, const char *const names[n])
{
    int i;
    size_t resLength = strlen(names[0]);
    if ( n > 1)
    {
        for (i=1; i<n; i++)
        {
            resLength += strlen(names[i]);
        }
    }
    resLength += 25;
    char *res;
    res = (char *)calloc( resLength, sizeof(char) );
    switch ( n )
    {
        case 0:
            sprintf(res, "no one likes this");
            break;
        case 1:
            sprintf(res, "%s likes this", names[0]);
            break;
        case 2:
            sprintf(res, "%s and %s like this", names[0], names[1]);
            break;
        case 3:
            sprintf(res, "%s, %s and %s like this", names[0], names[1], names[2]);
            break;
        default:
            sprintf(res, "%s, %s and %d others like this", names[0], names[1], n-2);
            break;
    }
    return res;
}

int main ( void )
{
    const char *const names[] = {"Jade", "Alex", "Jacob", "Mark", "Max", "Judith"};
    printf( "%s\n", likes( sizeof(names)/sizeof(names[0]), names ) );
    return 0;
}
