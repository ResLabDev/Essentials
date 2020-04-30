/*
The bookseller has lots of books classified in 26 categories labeled A, B, ... Z. Each book has a code c of 3, 4, 5 or more capitals letters. The 1st letter of a code is the capital letter of the book category. In the bookseller's stocklist each code c is followed by a space and by a positive integer n (int n >= 0) which indicates the quantity of books of this code in stock.

For example an extract of one of the stocklists could be:

L = {"ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"}.
or

L = ["ABART 20", "CDXEF 50", "BKWRK 25", "BTSQZ 89", "DRTYM 60"] or ....
You will be given a stocklist (e.g. : L) and a list of categories in capital letters e.g :

  M = {"A", "B", "C", "W"}
or

  M = ["A", "B", "C", "W"] or ...
and your task is to find all the books of L with codes belonging to each category of M and to sum their quantity according to each category.

For the lists L and M of example you have to return the string (in Haskell/Clojure/Racket a list of pairs):

  (A : 20) - (B : 114) - (C : 50) - (W : 0)
where A, B, C, W are the categories, 20 is the sum of the unique book of category A, 114 the sum corresponding to "BKWRK" and "BTSQZ", 50 corresponding to "CDXEF" and 0 to category 'W' since there are no code beginning with W.

If L or M are empty return string is "" (Clojure and Racket should return an empty array/list instead).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 120

// szlst is lstOfArt size, szcat is categories size
char* stockSummary(char** lstOfArt, int szlst, char** categories, int szcat)
{
    int sumList['Z' + 1] = {0};
    char *p_result = (char *) malloc(BUFFER_SIZE * sizeof(char));

    if (NULL == p_result)
    {
        return NULL;
    }

    if (!szlst || !szcat)
    {
        strcpy(p_result, "");
        return p_result;
    }

    for (int j = 0; j < szcat; j++)
    {
        for (int i = 0; i < szlst; i++)
        {
            if (lstOfArt[i][0] == categories[j][0])
            {
                while (*lstOfArt[i] != ' ')
                {
                    lstOfArt[i]++;
                }

                sumList[categories[j][0]] += atoi(++lstOfArt[i]);
            }
        }
    }

    snprintf(p_result, BUFFER_SIZE, "(%s : %d)", categories[0], sumList[categories[0][0]]);
    char partResult[BUFFER_SIZE] = "";
    for (int i = 1; i < szcat; i++)
    {
      strcpy(partResult, p_result);
      snprintf(p_result, BUFFER_SIZE, "%s - (%s : %d)", partResult, categories[i], sumList[categories[i][0]]);
    }

    return p_result;
}

int main (int argv, char **argc)
{
    const char *stockList[] = {"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
    const char *categories[] = {"A", "B"};

    char *p_result = stockSummary(stockList, sizeof(stockList) / sizeof(stockList[0]), categories, sizeof(categories) / sizeof(categories[0]));

    printf("%s", p_result);

    free(p_result);

    return 0;
}
