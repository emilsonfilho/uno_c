#include "../../include/utils/swap.h"

void swap(Card *arr, int i, int j)
{
    Card temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}