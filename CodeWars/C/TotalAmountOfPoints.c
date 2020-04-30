/*
Our football team finished the championship. The result of each match look like "x:y". Results of all matches are recorded in the collection.

For example: ["3:1", "2:2", "0:1", ...]

Write a function that takes such collection and counts the points of our team in the championship. Rules for counting points for each match:

if x>y - 3 points
if x<y - 0 point
if x=y - 1 point
Notes:

there are 10 matches in the championship
0 <= x <= 4
0 <= y <= 4
*/

#include <stdio.h>

int points(const char* const games[10])
{
    int count = 0;

    for (int i=0; i<10; ++i)
    {
        count += (games[i][0] > games[i][2]) ? 3 :
                  (games[i][0] == games[i][2]) ? 1 : 0;
    }

    return count;
}

int main (void)
{
    char *match[10] = {"3:1", "2:2", "0:1", "3:1", "2:2", "0:1", "3:1", "2:2", "0:1", "0:1"};

    printf("%d", points(&match));
    return 0;
}
