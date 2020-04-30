/*
We search positive integer numbers, with at most 3 digits, such as the sum of the cubes of their digits is the number itself; we will call them "cubic" numbers.

153 is such a "cubic" number : 1^3 + 5^3 + 3^3 = 153
These "cubic" numbers of at most 3 digits are easy to find, even by hand, so they are "hidden" with other numbers and characters in a string.

The task is to found, or not, the "cubic" numbers in the string and then to make the sum of these "cubic" numbers found in the string, if any, and to return a string such as:

"number1 number2 (and so on if necessary) sumOfCubicNumbers Lucky"
if "cubic" numbers number1, number2, ... were found. The numbers in the output are to be in the order in which they are encountered in the input string.

If no cubic numbers are found return the string:

"Unlucky".
Examples:

 s = "aqdf& 0 1 xyz 153 777.777" must return "0 1 153 154 Lucky"

 s = "QK29 45[&erui" must return "Unlucky".
Note: In the string "001234" where 3 digits or more follow each other the fist packet to examine is "001" and the following is "234". If a packet of at most three digits has been taken, whether or not "cubic", it's over for that packet.

When a continous string of digits exceeds 3, the string is split into groups of 3 from the left. The last grouping could have 3, 2 or 1 digits. e.g "24172410" becomes 3 strings comprising "241", "724" and "10" e.g "0785" becomes 2 strings comprising "078" and "5".
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 120

#include <stdio.h>

static bool IsHiddenCubic (int num)
{
    if (num < 2)
    {
        return true;
    }

    int digit = num % 10;
    int sum = digit * digit * digit;
    int splitNum = num / 10;

    while (splitNum > 0)
    {
        digit = splitNum % 10;
        sum += digit * digit * digit;
        splitNum /= 10;
    }

    return (num == sum) ? true : false;
}

char* isSumOfCubes(char* str)
{
    char *p_result = (char *) calloc(BUFFER_SIZE, sizeof(char));
    if (NULL == p_result)
    {
        return NULL;
    }

    char buffer[BUFFER_SIZE];

    buffer[0] = '\0';
    p_result[0] = '\0';

    int num = 0;
    while (*str)
    {
        if (isdigit(*str))
        {
            sscanf(str, "%d", &num);
            if (IsHiddenCubic(num))
            {
                strcpy(buffer, p_result);
                snprintf(p_result, BUFFER_SIZE, "%s%d ", buffer, num);
            }
            while (isdigit(*str))
            {
                str++;
            }
        }
        else
        {
            str++;
        }
    }

    if (strlen(p_result))
    {
        strcat(p_result, "Lucky");
    }
    else
    {
        strcpy(p_result, "Unlucky");
    }

    return p_result;
}


int main (void)
{
    char *p_result = isSumOfCubes("&z _153upon 407298a --- ??407?ry241, ww/100 I thought, 631str*ng and w===y -721&()");
    printf("%s", p_result);

    free(p_result);

    return 0;
}

/*
    if (sscanf(str, "%*[^0123456789]%d", &num) == 1)
    {
        printf("%d, ", num);
    }
*/
