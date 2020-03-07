#include "main.h"


void CycleTest (void)
{
    uint8_t cycle = 5;
    uint8_t iteration = 1;

    printf(" === while (cycle) === \n");
    while (cycle)
    {
        printf("Iteration: %u | Cycle: %u\n", iteration, cycle);
        iteration++;
        cycle--;
    }

    cycle = 5;
    iteration = 1;
    printf("\n === while (cycle --> 0) === \n");
    while (cycle --> 0)
    {
        printf("Iteration: %u | Cycle: %u\n", iteration, cycle);
        iteration++;
    }

    cycle = 5;
    iteration = 1;
    printf("\n === do {} while (cycle --> 0) === \n");
    do
    {
        printf("Iteration: %u | Cycle: %u\n", iteration, cycle);
        iteration++;
    } while (cycle --> 0);
}
