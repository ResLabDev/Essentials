/*
In Racket, the function is called palindrome?

(palindrome? "nope") ; returns #f
(palindrome? "Yay")  ; returns #t
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool is_palindrome(const char *str_in) {

    int j = strlen(str_in);
    if (j < 2)
    {
      return true;
    }

    int middle = j >> 1;

    j--;
    for (int i = 0; i <= middle; i++)
    {
        if (toupper(str_in[i]) != toupper(str_in[j-i]))
        {
            return false;
        }
    }

    return true;
}

int main (void)
{
    printf(is_palindrome("Abba") ? "TRUE" : "FALSE");
}
