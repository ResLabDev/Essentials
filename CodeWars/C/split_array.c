#include <stdio.h>

#define NUM_OF(x)  (sizeof(x)/sizeof(*x))

#include <stddef.h>
#include <stdlib.h>

static void SplitArray (size_t si, int *arr_i, size_t so, int *arr_o, int split)
{
    int temp, diff = 0;
    for (int i = 0; i < so; ++i)
    {
        if ((si & 1) & (0 == i))
        {
            temp = arr_i[split++];
            diff = 1;
        }
        else
        {
            arr_o[i] = arr_i[i-diff] + arr_i[split++];
        }
    }
    if (si & 1)
    {
        arr_o[0] = temp;
    }
}

static void CopyArray (size_t s, int *p_arr_i, int **pp_arr_o)
{
    for (int i = 0; i < s; ++i) (*pp_arr_o)[i] = p_arr_i[i];
}

int *split_and_add(size_t si, const int arr[si], int n, size_t *so)
{
    if (n < 1)
    {
        int *p_arr_o = (int *) calloc(*so, sizeof(int));
        if (NULL == p_arr_o) return NULL;
        *so = si;
        CopyArray(si, arr, &p_arr_o);

        return p_arr_o;
    }

    int split = si >> 1;
    *so = split + (si & 1);
    int calc[*so];

    SplitArray(si, arr, *so, calc, split);

    size_t sz = *so;
    while (n --> 1)
    {
        split = sz >> 1;
        *so = split + (sz & 1);
        SplitArray(sz, calc, *so, calc, split);
        sz = *so;
    }

    int *p_result = (int *) calloc(*so, sizeof(int));
    if (NULL == p_result) return NULL;

    CopyArray(*so, calc, &p_result);

    return p_result;
}

int main (void)
{
    const int inp[] = {1, 2, 3, 4, 5};
    int sum_size;
    int *sum = split_and_add(NUM_OF(inp), inp, 3, &sum_size);

    for (int i = 0; i<sum_size; ++i)
    {
        printf("%d, ", *sum);
        sum++;
    }

    free(sum);

    return 0;
}
