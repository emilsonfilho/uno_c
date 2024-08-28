#include "../../include/utils/sort_cards.h"

void sort_cards(Card *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].color > arr[j + 1].color ||
                (arr[j].color == arr[j + 1].color && compare_cards(arr[j], arr[j + 1]) > 0))
            {
                swap(arr, j, j + 1);
            }
        }
    }
}