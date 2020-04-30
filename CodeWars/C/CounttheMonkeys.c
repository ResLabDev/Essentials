#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

size_t *monkey_count(size_t n, size_t *pResultCount)
{
    size_t *p_count = (size_t *) calloc(n, sizeof(size_t));

    for (int i = 0; i < n; i++)
    {
        p_count[i] = i + 1;
        (*pResultCount)++;
    }

    return p_count;
}

int main (void)
{
    size_t resultCount = 0;
    size_t *p_monkey = monkey_count(10, &resultCount);

    for (int i = 0; i < 10; i++)
    {
        printf("%d - %d\n", p_monkey[i], resultCount);
    }

    free(p_monkey);

    return 0;
}
