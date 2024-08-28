#include "../../include/utils/compaction.h"

Card *compaction(Card *arr, int *arr_size, int hole)
{
    if (hole < 0 || hole >= *arr_size)
    {
        return arr;
    }

    int new_size = *arr_size - 1;

    for (int i = hole; i < new_size; i++)
    {
        arr[i] = arr[i + 1];
    }

    Card *temp = (Card *)realloc(arr, new_size * sizeof(Card));

    if (temp == NULL && new_size > 0)
    {
        printf("[ERROR]: Falha ao realocar memória.\n");
        exit(1);
    }

    *arr_size = new_size;
    return temp;
}