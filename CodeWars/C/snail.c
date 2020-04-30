/*
Snail Sort
Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
For better understanding, please follow the numbers of the next array consecutively:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]
NOTE: The idea is not sort the elements from the lowest value to the highest; the idea is to traverse the 2-d array in a clockwise snailshell pattern.

NOTE 2: The 0x0 (empty matrix) is represented as en empty array inside an array [[]].
*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_OF(x)       (sizeof(x)/sizeof(*x))

typedef enum direction
{
    right,
    down,
    left,
    up
} direction_t;

int *snail (size_t *outsz, const int **mx, size_t m, size_t n)
{
    *outsz = m * n;
    int *p_snail = (int *) calloc(*outsz, sizeof(int));
    if (NULL == p_snail)
    {
        perror("Unable to allocate matrix rows.");
        return NULL;
    }

    int leftCorner = 0;
    int rightCorner = n - 1;
    int topCorner = 1;
    int bottomCorner = m - 1;
    m = 0;
    n = 0;
    direction_t dir = right;
    for (int i = 0; i < *outsz; i++)
    {
        p_snail[i] = mx[m][n];
        switch (dir)
        {
            case right:
                n++;
                if (n == rightCorner)
                {
                    rightCorner--;
                    dir = down;
                }
                break;
            case down:
                m++;
                if (m == bottomCorner)
                {
                    bottomCorner--;
                    dir = left;
                }
                break;
            case left:
                n--;
                if (n == leftCorner)
                {
                    leftCorner++;
                    dir = up;
                }
                break;
            case up:
                m--;
                if (m == topCorner)
                {
                    topCorner++;
                    dir = right;
                }
                break;
            default:
                break;
        }
    }

    return p_snail;
}

int main (void)
{
    const int matrix[][4] =
    {
        {1,2,3,1},
        {4,5,6,4},
        {7,8,9,7},
        {7,8,9,7}
    };

    size_t m = NUM_OF(matrix);
    size_t n = NUM_OF(matrix[0]);

    int **pp_matrix = (int **) calloc(m, sizeof(int *));
    if (NULL == pp_matrix)
    {
        perror("Unable to allocate matrix cols.\n");
        return -1;
    }
    for (int i = 0; i < m; ++i)
    {
        pp_matrix[i] = (int *) calloc(n, sizeof(int));
        if (NULL == pp_matrix[i])
        {
            perror("Unable to allocate matrix rows.\n");
            return -1;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            pp_matrix[i][j] = matrix[i][j];
        }
    }
    int snailSize = 0;

    int *p_snailMatrix = snail(&snailSize, pp_matrix, m, n);

    for (int i = 0; i < snailSize; ++i)
    {
        printf("%d, ", p_snailMatrix[i]);
    }

    free(p_snailMatrix);
    for (int i = 0; i < m; ++i)
    {
        free(pp_matrix[i]);
    }
    free(pp_matrix);

    return 0;
}


