/*
As you may know, once some people pass their teens, they jokingly only celebrate their 20th or 21st birthday, forever. With some maths skills, that's totally possible -
you only need to select the correct number base!
For example, if they turn 32, that's exactly 20 - in base 16... Already 39? That's just 21, in base 19!
Your task is to translate the given age to the much desired 20 (or 21) years, and indicate the number base, in the format specified below.
Note: input will be always > 21

Examples:
32  -->  "32? That's just 20, in base 16!"
39  -->  "39? That's just 21, in base 19!"
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 40
#define BASE_MAX    60

char *womens_age(int age)
{
    int calcAge = age;
    int base = 11;
    _Bool is21_b = 0;

    while (base <= BASE_MAX)
    {
        is21_b = 0;
        calcAge = 2 * base;

        if (age == calcAge) break;
        is21_b = 1;
        if (age == ++calcAge) break;

        base++;
    }

    char *realAge = (char *)calloc(BUFFER_SIZE, sizeof(char));
    snprintf(realAge, BUFFER_SIZE, "%d? That's just %d, in base %d!", age, (is21_b) ? 21 : 20, base);

    return realAge;
}

char *WomensAge(int age)
{
    char *buffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
    snprintf(buffer, BUFFER_SIZE, "%d? That's just 2%d, in base %d!", age, age%2, age/2);

    return buffer;
}

int main (void)
{
    char *age;

    age = womens_age(32);
    printf("%s\n", age);
    age = womens_age(39);
    printf("%s\n", age);

    age = WomensAge(32);
    printf("%s\n", age);
    age = WomensAge(39);
    printf("%s\n", age);

    free(age);

    return 0;
}
