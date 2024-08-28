#include "../../include/utils/are_arrays_equal.h"

bool are_arrays_equal(const char **arr1, int len1, const char **arr2, int len2)
{
    if (len1 != len2)
        return false;

    for (int i = 0; i < len1; i++)
    {
        if (!are_strings_equal((char *)arr1[i], (char *)arr2[i]))
            return false;
    }

    return true;
}