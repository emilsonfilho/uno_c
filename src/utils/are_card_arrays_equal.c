#include "../../include/utils/are_card_arrays_equal.h"

bool are_card_arrays_equal(Card *arr1, int len1, Card *arr2, int len2)
{
    if (len1 != len2)
        return false;

    for (int i = 0; i < len1; i++)
    {
        if (arr1[i].color != arr2[i].color ||
            arr1[i].isNumber != arr2[i].isNumber ||
            (arr1[i].isNumber && arr1[i].numberAction.number != arr2[i].numberAction.number) ||
            (!arr1[i].isNumber && !are_strings_equal(arr1[i].numberAction.action, arr2[i].numberAction.action)))
        {
            return false;
        }
    }

    return true;
}