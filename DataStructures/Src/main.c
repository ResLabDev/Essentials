/** @file main.c
*
*   @brief Udemy Course: Fundamental Data Structures & Algorithms using C language.
*
*   @link https://www.udemy.com/course/data-structures-stack-queue-linkedlist/
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "ui.h"

#define TEST_EN 0

//=== Private Functions ===
//
/*!
*  @brief Finished Execution Status
*  @return void
*/
static void FinishedStatus (void)
{
    puts("\n\n=== Execution is Finished ===");
}

//=== MAIN Function ===
//
/*!
*  @brief Software's entry point
*  @param[in] argv Number of command line input arguments
*  @param[in] **argc Command line input arguments
*  @return 0: No error, -1: Error
*/
int main (int argv, char **argc)
{

#   if TEST_EN
    // TestQueue(0);
    // TestBinarySearch(0);
    // TestRecursion(0);
    // TestBinarySearchTree(0);
    // TestMorse(0);
    // TestHeap(0);
    // TestSorting(0);

#   else

    MenuInit();

    int select = 2;
    const int exit = 0;

	MenuPrint(exit);

	// ToDo: scanf() does not work with cygwin
	// scanf("%d", &select);

	select = tolower(select);
	MenuUI(&select, exit);
	fflush(stdin);

#   endif // TEST_EN

    atexit(FinishedStatus);

    return 0;
}

/**** EOF ***/
