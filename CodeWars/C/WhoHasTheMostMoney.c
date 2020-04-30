/*
You're going on a trip with some students and it's up to you to keep track of how much money each Student has. A student is defined like this:

#define NAMELIM     0x8

struct student {
    char name[NAMELIM + 1];
    unsigned fives;
    unsigned tens;
    unsigned twenties;
};
As you can tell, each Student has some fives, tens, and twenties. Your job is to return the name of the student with the most money. If every student has the same amount, then return "all".

Notes:

Each student will have a unique name
There will always be a clear winner: either one person has the most, or everyone has the same amount
If there is only one student, then that student has the most money
*/

#include <stdio.h>
#include <stddef.h>

#define NAMELIM     0x8

struct student
{
    char name[NAMELIM+1];
    unsigned fives;
    unsigned tens;
    unsigned twenties;
};

const char *most_money(const struct student *v, size_t n)
{
    if (n == 1)
    {
        return v->name;
    }

    int maxMoneyIndex = 0;
    unsigned maxMoney = 0;
    unsigned currentMoney = 0;
    unsigned countEqual = 1;

    for (int i = 0; i < n; i++)
    {
        currentMoney = 5 * v[i].fives + 10 * v[i].tens + 20 * v[i].twenties;

        if (currentMoney > maxMoney)
        {
            maxMoney = currentMoney;
            maxMoneyIndex = i;
        }
        else if (currentMoney == maxMoney)
        {
            countEqual++;
        }
        else
        {
            // NOP
        }
    }

    return (n == countEqual) ? "all" : v[maxMoneyIndex].name;
}

int main (int argv, char **argc)
{
    const struct student guys[]  =
    {
        {"Cameron",2,2,0},
        {"Geoff",0,3,0},
        {"Phil",2,2,1}
    };

    const struct student guys2[]  =
    {
        {"Cameron",2,2,0},
        {"Geoff",0,3,0},
    };

    const struct student guys3[]  =
    {
        {"Phil",2,2,1}
    };

    const struct student guys4[] =
    {
        {     "Qzhs", 6, 7, 7 },
        {      "Ghr", 3, 6, 7 },
        { "Sujosohn", 2, 7, 4 },
        {   "Xqymhk", 7, 7, 0 },
        {       "Hh", 1, 4, 5 },
        {   "Waouhe", 0, 4, 3 },
        {      "Lha", 2, 1, 7 },
        {      "Efx", 2, 8, 5 },
        {  "Dvwdfft", 3, 4, 0 },
        {  "Qlsoffq", 0, 1, 1 },
        { "Kxjeidfm", 0, 0, 1 },
        {      "Kfi", 2, 0, 4 },
        {    "Tqzfh", 2, 1, 1 },
        {      "Aff", 3, 6, 3 },
        {     "Lrfd", 9, 0, 8 },
        {       "Fa", 3, 4, 6 },
        {     "Tedz", 5, 0, 6 },
        {    "Xqddx", 7, 2, 4 },
        {    "Cbrdv", 7, 1, 4 }
    };
/*
    printf("%s\n", most_money(guys, sizeof(guys) / sizeof(guys[0])));
    printf("%s\n", most_money(guys2, sizeof(guys2) / sizeof(guys2[0])));
    printf("%s\n", most_money(guys3, sizeof(guys3) / sizeof(guys3[0])));
    printf("%s\n", most_money(guys4, sizeof(guys4) / sizeof(guys4[0])));
*/
    struct student *p_guys = guys4;


    printf("%s %u\n", p_guys->name, p_guys->fives);
    printf("%s %u\n", (p_guys + 1)->name, (p_guys + 1)->fives);

    return 0;
}
