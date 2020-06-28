// https://www.codewars.com/kata/52742f58faf5485cae000b9a/train/c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE     100
#define SEC_PER_YEAR    31536000u
#define SEC_PER_DAY     86400u
#define SEC_PER_HOUR    3600u
#define SEC_PER_MIN     60u

typedef enum
{
    YEAR,
    DAY,
    HOUR,
    MINUTE,
    SECOND
} timeState_t;

char *formatDuration (int n)
{
    if (n <= 0)
    {
        return strdup("now");
    }

    char buffer[BUFFER_SIZE] = {'\0'};
    int currentTime = 0;
    timeState_t timeState = YEAR;

    while (n)
    {
        switch (timeState)
        {
            case YEAR:
                if (n >= SEC_PER_YEAR)
                {
                    currentTime = n / SEC_PER_YEAR;
                    n %= SEC_PER_YEAR;
                    sprintf(buffer, (1 == currentTime) ? "%d year" : "%d years", currentTime);
                }
                timeState = DAY;
                break;
            case DAY:
                if (n >= SEC_PER_DAY)
                {
                    currentTime = n / SEC_PER_DAY;
                    n %= SEC_PER_DAY;
                    if (strlen(buffer))
                    {
                        sprintf(buffer, (n) ? "%s, " : "%s and ", buffer);
                    }
                    sprintf(buffer, (1 == currentTime) ? "%s%d day" : "%s%d days", buffer, currentTime);
                }
                timeState = HOUR;
                break;
            case HOUR:
                if (n >= SEC_PER_HOUR)
                {
                    currentTime = n / SEC_PER_HOUR;
                    n %= SEC_PER_HOUR;
                    if (strlen(buffer))
                    {
                        sprintf(buffer, (n) ? "%s, " : "%s and ", buffer);
                    }
                    sprintf(buffer, (1 == currentTime) ? "%s%d hour" : "%s%d hours", buffer, currentTime);
                }
                timeState = MINUTE;
                break;
            case MINUTE:
                if (n >= SEC_PER_MIN)
                {
                    currentTime = n / SEC_PER_MIN;
                    n %= SEC_PER_MIN;
                    if (strlen(buffer))
                    {
                        sprintf(buffer, (n) ? "%s, " : "%s and ", buffer);
                    }
                    sprintf(buffer, (1 == currentTime) ? "%s%d minute" : "%s%d minutes", buffer, currentTime);
                }
                timeState = SECOND;
                break;
            case SECOND:
                if (n)
                {
                    if (strlen(buffer))
                    {
                        sprintf(buffer, "%s and ", buffer);
                    }
                    sprintf(buffer, (1 == n) ? "%s%d second" : "%s%d seconds", buffer, n);
                    n = 0;
                }
                break;
            default:
                break;
        }
    }

    return strdup(buffer);
}

int main (void)
{
    char *p_result;
#if 1
    p_result = formatDuration(0);
    printf("%s - %d\n", p_result, strcmp(p_result, "now"));
    p_result = formatDuration(1);
    printf("%s - %d\n", p_result, strcmp(p_result, "1 second"));
    p_result = formatDuration(3600);
    printf("%s | %d\n", p_result, strcmp(p_result, "1 hour"));
    p_result = formatDuration(120);
    printf("%s | %d\n", p_result, strcmp(p_result, "2 minutes"));
    p_result = formatDuration(62);
    printf("%s | %d\n", p_result, strcmp(p_result, "1 minute and 2 seconds"));
    p_result = formatDuration(3662);
    printf("%s | %d\n", p_result, strcmp(p_result, "1 hour, 1 minute and 2 seconds"));
#endif // 0
    p_result = formatDuration(132030240);
    printf("%s | %d\n", p_result, strcmp(p_result, "4 years, 68 days, 3 hours and 4 minutes"));

    free(p_result);

    return 0;
}
