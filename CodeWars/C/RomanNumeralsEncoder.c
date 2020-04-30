/*
Create a function taking a positive integer as its parameter and returning a string containing the Roman Numeral representation of that integer.

Modern Roman numerals are written by expressing each digit separately starting with the left most digit and skipping any digit with a value of zero.
In Roman numerals 1990 is rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC. 2008 is written as 2000=MM, 8=VIII; or MMVIII.
1666 uses each Roman symbol in descending order: MDCLXVI.

Symbol    Value
I          1
V          5
X          10
L          50
C          100
D          500
M          1,000
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROMAN_LENGTH 100
typedef struct roman
{
    unsigned int value;
    char *symbol;
} roman_t;

const roman_t symbols[] =
{
    { 1, "I"},
    { 4, "IV"},
    { 5, "V"},
    { 9, "IX"},
    { 10, "X"},
    { 40, "XL"},
    { 50, "L"},
    { 90, "XC"},
    { 100, "C"},
    { 400, "CD"},
    { 500, "D"},
    { 900, "CM"},
    { 1000, "M"}
};

char *solution(int n)
{
    static char result[ROMAN_LENGTH];
    int i = sizeof(symbols) / sizeof(roman_t) - 1;
    int num = n;
    int romanDigit, j;

    result[0] = '\0';
    // Compare the input with the symbol value
    while (i)
    {
        if (n >= symbols[i].value)
        {
            break;
        }
        i--;
    }
    while (num)
    {
        romanDigit = num / symbols[i].value;
        num %= symbols[i].value;
        for (j=0; j<romanDigit; j++)
        {
            strcat(result, symbols[i].symbol);
        }
        i--;
    }

    return result;
}

int main (void)
{
    int input;
    do
    {
        printf("Number: ");
        scanf("%d", &input);
        printf("%s\n", solution(input));
    } while (getchar() != '27');

    return 0;
}
