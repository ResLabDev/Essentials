/** @file main.c
*
*   @brief Udemy Course: Data Structures and Algorithms Through C In Depth
*
*   @link https://www.udemy.com/course/data-structures-and-algorithms-in-c/
*
*/

//=== Header Files ===
//
#include <stdio.h>

#include "../Src/callback.h"
#include "../Src/linked_list.h"
#include "../Src/queue.h"
#include "../Src/recursion.h"
#include "../Src/tricks.h"

#define QUEUE_EN			1
#define CALLBACK_EN         1
#define LINKED_LIST_EN      1
#define TRICKS_EN           1
#define RECURSION_EN        1


//=== MAIN Function ===
//
/*!
* @brief Main function entry point
*
* @param[in] argv Number of input arguments
* @param[in] argc Array of input argument strings
*
* @return 0 => no error / -1 => error
*/
int main (int argv, char **argc)
{

//=== Queue ===
#if QUEUE_EN
    int front;
    int rear;
    int *p_queue = InitializeQueue(&front, &rear, QUEUE_SIZE);
    printf("%d, %d: %d", front, rear, QUEUE_SIZE);

#endif // QUEUE_EN

//=== Callback ===
#if CALLBACK_EN

#if 1
    printf("%d\n", Callback(&add, 9, 5));
    printf("%d\n", Callback(&subtract, 9, 5));
    printf("%d\n", Callback(&multiply, 9, 5));
#endif // 0
    function_t *call[3] = {add(9, 5), subtract(9, 5), multiply(9, 5)};
    for (int i = 0; i < NUM_OF(call); i++)
    {
        printf("%d\n", call[i]);
    }

#endif // CALLBACK_EN

//=== Linked List ===
#if LINKED_LIST_EN
    atexit(ExitLinkedList);

    nodeData_t agent = {"Andrea Parker", 7};
    node_t *p_root = CreateRoot(agent);

    nodeData_t agent2 = {"Nadine Kruger", 4};
    PushList(p_root, agent2);

    nodeData_t agent3 = {"Verona Feldbush", 9};
    PushList(p_root, agent3);

    nodeData_t agent4 = {"Gemma Arteron", 6};
    PushList(p_root, agent4);
    PrintList(p_root);
    PopList(p_root);
    puts("");
    PrintList(p_root);
    PushListRootBefore(&p_root, agent4);
    puts("");
    PrintList(p_root);
    nodeData_t agent5 = {"Karen Vodermann", 5};
    InsertListAfter(p_root, agent5, 3);
    puts("");
    PrintList(p_root);
    puts("");
    CleanList(&p_root);
    puts("");
    PrintList(p_root);

#endif // LINKED_LIST_EN

// === Tricks ===
#if TRICKS_EN
    atexit(ExitTricks);
    testNumOf_t testNumLUT[] =
    {
        { 12, 15, "Test1" },
        { 4, 5, "Test2"   },
        { 56, 91, "Test3" },
        { 15, 45, "Test4" }
    };

    testNumOf_t *p_testNum = testNumLUT;
    int testNumSize = NUM_OF(testNumLUT);
    printf("Size: %d\n", testNumSize);

    for (int i = 0; i < testNumSize; i++)
    {
        printf("%2d %2d %s\n", (p_testNum + i)->a, (p_testNum + i)->b, (p_testNum + i)->name);
    }

    SWAP(p_testNum[2].a, p_testNum[2].b);
    printf("-----\n%2d %2d %s\n", p_testNum[2].a, p_testNum[2].b, p_testNum[2].name);

    GoesTo(10);

    int matrix[3][3] =
    {
        #include "initMatrix.txt"
    };

    puts("\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%2d, ", matrix[i][j]);
        }
        puts("");
    }

    int sorting[] =
    {
        #include "sorting.txt"
    };

    puts("\n");
    for (int i = 0; i < NUM_OF(sorting); i++)
    {
        printf("%d, ", sorting[i]);
    }
    BubbleSort(sorting, NUM_OF(sorting));
    puts("");
    for (int i = 0; i < NUM_OF(sorting); i++)
    {
        printf("%d, ", sorting[i]);
    }
    puts("\n--- Binary File Access ---");
    FILE *p_file = fopen("data.bin", "wb");
    if (NULL == p_file)
    {
        perror("Unable to create binary file.\n");
        return -1;
    }

    binaryData_t binData;
    for (int i = 0; i < 5; i++)
    {
        binData.a = 3*i + 15;
        binData.b = i * 2;
        fwrite(&binData, sizeof(binaryData_t), 1, p_file);
    }
    fclose(p_file);

    FILE *p_fileRead = fopen("data.bin", "rb");
    if (NULL == p_fileRead)
    {
        perror("Unable to create binary file.\n");
        return -1;
    }

    binaryData_t binDataRead;
    for (int i = 0; i < 5; i++)
    {
        fread(&binDataRead, sizeof(binDataRead), 1, p_fileRead);
        printf("%d. %d, %d\n", (i + 1), binDataRead.a, binDataRead.b);
    }
    fclose(p_fileRead);

    // Pointer To Array And Array Of Pointers
    int *p_arr1[5];     // Array of 5 integer pointers
    int (*p_arr2)[5];   // Pointer to an array of 5 integers
    int * (p_arr3[5]);  // Same as p_arr1

#endif // TRICKS_EN

// === Recursion ===
#if RECURSION_EN
    printf("Factorial: %d\n", Factorial(4));
    printf("Fibonacci: %d\n", Fibonacci(10));
    printf("Power of 10 integer: %u\n", Pow10Int(3));
    printf("Bitwise addition: %d", BitwiseAdd(11, 7));
#endif // 0

    return 0;
}


/*** EOF ***/
