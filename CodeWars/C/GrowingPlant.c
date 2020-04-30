#include <stdio.h>
#include <stdbool.h>

int growingPlant(int upSpeed, int downSpeed, int desiredHeight)
{
    if (upSpeed <= downSpeed)
    {
        return 0;
    }

    int height = 0;
    int day = 1;
    bool b_growUp = true;
    while (b_growUp)
    {
        height += upSpeed;
        if (height < desiredHeight)
        {
            height -= downSpeed;
            day++;
        }
        else
        {
            b_growUp = false;
        }
    }

    return day;
}

int main (void)
{
    printf("%d", growingPlant(100, 10, 910));

    return 0;
}
