#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define DIM_OF(x)					(sizeof(x) / sizeof(*x))

// @file: spi_test.c
void SPI_Send (void);

// @file: cycle.c
void CycleTest (void);

#endif // MAIN_H_
