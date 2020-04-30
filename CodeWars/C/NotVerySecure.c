/*
In this example you have to validate if a user input string is alphanumeric. The given string is not nil, so you don't have to check that.

The string has the following conditions to be alphanumeric:

At least one character ("" is not valid)
Allowed characters are uppercase / lowercase latin letters and digits from 0 to 9
No whitespaces/underscore
*/

#include <stdio.h>
#include <stdbool.h>

bool alphanumeric(const char* strin)
{
    if ( strin[0] == '\0' ) return false;       // Detect empty string
    int i=0;
    while ( strin[i] )
    {
        if ( (strin[i] < '0') || (strin[i] > 'z') ) return false;       // Out of Alphanumeric range
        if ( (strin[i] < 'a') && (strin[i] > 'Z') ) return false;       // Out of Lower case letter range
        if ( (strin[i] < 'A') && (strin[i] > '9') ) return false;       // Out of Lower case letter range
        i++;
    }
    return true;
}

int main ( void )
{
    printf( alphanumeric("hello_world") ? "True\n" : "False\n" );
    printf( alphanumeric("PassW0rd") ? "True\n" : "False\n" );
    printf( alphanumeric("     ") ? "True\n" : "False\n" );
    printf( alphanumeric("a") ? "True\n" : "False\n" );
    printf( alphanumeric("") ? "True\n" : "False\n" );

    return 0;
}
