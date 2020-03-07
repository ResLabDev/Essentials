/** @file stack.h
*
*   @brief Basic stack implementation header file.
*
*/

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

// === Constant Definitions ===
//

// === Type Definitions ===
//
typedef struct stackType
{
    int *item;
    size_t size;
    int top;
} stackType_t;


// === Macros ===
//


// === Public Function API ===
//
int InitializeStack(stackType_t *p_stack, size_t size);
void PushStack (stackType_t *p_stack, int data);
int PopStack (stackType_t *p_stack);
int GetStackItem (stackType_t *p_stack);
size_t GetStackSize (stackType_t *p_stack);
int GetStackTop (stackType_t *p_stack);
int StackIsEmpty (stackType_t *p_stack);
void CleanupStack (stackType_t *p_stack);


#endif // STACK_H

/**** EOF ***/
