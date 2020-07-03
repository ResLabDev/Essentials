/*
Positive integers have so many gorgeous features. Some of them could be expressed as a sum of two or more consecutive positive numbers.

Consider an Example :
10 , could be expressed as a sum of 1 + 2 + 3 + 4.
Task
Given Positive integer, N , Return true if it could be expressed as a sum of two or more consecutive positive numbers , OtherWise return false .

Notes
Guaranteed constraint : 2 ≤ N ≤ (2^32) -1 .

* consecutiveDucks(9)  ==>  return (true)  //  9 , could be expressed as a sum of ( 2 + 3 + 4 ) or ( 4 + 5 ) .
* consecutiveDucks(64)  ==>  return (false)
* consecutiveDucks(42)  ==>  return (true) //  42 , could be expressed as a sum of ( 9 + 10 + 11 + 12 )  .
*/


#include <stdio.h>
#include <stdbool.h>

bool consecutive_ducks (unsigned int n)
{
    if (n & 1)
    {
        return true;
    }

    unsigned int sum, j;
    for (unsigned int i=1; i<=n; i++)
    {
        sum = i;
        j = i+1;
        while (sum < n)
        {
            sum += j;
            if (sum == n)
            {
                return true;
            }
            j++;
        }
    }

    return false;
}

int main(void)
{
    printf(consecutive_ducks(9) == true ? "TRUE\n" : "FALSE\n");
    printf(consecutive_ducks(64) == true ? "TRUE\n" : "FALSE\n");
    printf(consecutive_ducks(42) == true ? "TRUE\n" : "FALSE\n");

    return 0;
}
