/** @file queue.h
*
*   @brief Circular queue header file
*
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

//=== Constant Defintions ===
//
#define QUEUE_SIZE      16


//=== Public Function API Prototypes
//
int *InitializeQueue (int *p_front, int *p_rear, size_t qSize);

#endif // QUEUE_H

/*** EOF ***/
