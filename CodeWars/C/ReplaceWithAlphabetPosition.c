/*
    In this kata you are required to, given a string, replace every letter with its position in the alphabet.
    Example:
    alphabet_position("The sunset sets at twelve o' clock.");
    Should return "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11" (as a string)
*/
#include<stdio.h>
#include<string.h>


char *alphabet_position(char *text)
{
    char position;
    char position_string[3];
    static char result[100];

    result[0] = '\0';           // Initialize the result string
    while (*text)
    {
        if ((*text >= 'a') && ((*text <= 'z')))       // Detect Lower Case
        {
            position = (int)(*text) - 'a' + 1;
        }
        else if ((*text >= 'A') && ((*text <= 'Z')))  // Detect Upper Case
        {
            position = (int)(*text) - 'A' + 1;
        }
        else                                                        // Outside the accepted interval: a-z and A-Z
        {
            text++;
            continue;
        }

        // Position number to string conversion
        if(position / 10)           // Two digits
        {
            position_string[0] = (position / 10) + '0';
            position_string[1] = (position % 10) + '0';
            position_string[2] = '\0';
        }
        else                        // Single digit
        {
            position_string[0] = position + '0';
            position_string[1] = '\0';
        }

        strcat(result, position_string);    // Concatenate position strings
        text++;
        strcat(result, " ");                // Add space after each number
    }

    result[strlen(result) - 1] = '\0';     // Delete last space
    text = result;

    return text;                          // Copy the final string result
}

// Main Function
int main (int argc, char **argv)
{
    char *result;

    result = alphabet_position("The sunset sets at twelve o' clock.");
    printf("%s \nEvaluate: %d\n", result, strcasecmp(result, "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11"));


    result = alphabet_position("The narwhal bacons at midnight.");
    printf("%s \nEvaluate: %d", result, strcasecmp(result, "20 8 5 14 1 18 23 8 1 12 2 1 3 15 14 19 1 20 13 9 4 14 9 7 8 20"));

    return 0;
}

