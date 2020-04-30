/*
The new "Avengers" movie has just been released! There are a lot of people at the cinema box office standing in a huge line. Each of them has a single 100, 50 or 25 dollar bill. An "Avengers" ticket costs 25 dollars.

Vasya is currently working as a clerk. He wants to sell a ticket to every single person in this line.

Can Vasya sell a ticket to every person and give change if he initially has no money and sells the tickets strictly in the order people queue?

Return YES, if Vasya can sell a ticket to every person and give change with the bills he has at hand at that moment. Otherwise return NO.

Examples:
tickets(3, {25, 25, 50}) // => true
tickets(2, {25, 100}) // => false. Vasya will not have enough money to give change to 100 dollars
tickets(5, {25, 25, 50, 50, 100}) // => false. Vasya will not have the right bills to give 75 dollars o
*/
#include <stdio.h>
#include <stdlib.h>

int tickets(size_t length, const int people[length])
{
    int count25 = 0;
    int count50 = 0;

    for (int i = 0; i < length; i++)
    {
        switch (people[i])
        {
            case 25:
                count25++;
            break;
            case 50:
                count25--;
                count50++;
            break;
            case 100:
                if (count50)
                {
                    count50--;
                    count25--;
                }
                else
                {
                    count25 -= 3;
                }
            break;
            default:
                // Not accepted dollars
            break;
        }
        if (count25 < 0)
        {
            return 0;
        }
    }

    return 1;
}

int main (void)
{
    printf(tickets(7, (int[]){25, 25, 25, 25, 50, 100, 50}) ? "true\n" : "false\n");

    return 0;
}
