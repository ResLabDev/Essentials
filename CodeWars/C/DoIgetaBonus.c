/*
It's bonus time in the big city! The fatcats are rubbing their paws in anticipation... but who is going to make the most money?

Build a function that takes in two arguments (salary, bonus). Salary will be an integer, and bonus a boolean.

If bonus is true, the salary should be multiplied by 10. If bonus is false, the fatcat did not make enough money and must receive only his stated salary.

Return the total figure the individual will receive as a string prefixed with "$" (C#, C++, Ruby, Clojure, Elixir, PHP and Python, Haskell, Lua).
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SALARY_LENGHT 20

typedef unsigned long long ull;

char *bonus_time(ull salary, bool bonus)
{
    char *p_totalPay = (char *)calloc(SALARY_LENGHT + 1, sizeof(char));
    if (NULL == p_totalPay)
    {
        return NULL;
    }

    char addBonus = (bonus == true) ? '0' : '\0';
    snprintf(p_totalPay, SALARY_LENGHT, "$%llu%c", salary, addBonus);

    return p_totalPay;
}

int main (void)
{
    char *p_getSalary = bonus_time(5000, true);

    printf("Salary: %s\n", p_getSalary);

    free(p_getSalary);

    return 0;
}
