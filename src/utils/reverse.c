#include "../../include/utils/reverse.h"

char **reverse(char **arr, int len)
{
    if (arr == NULL || len == 0)
        return NULL;

    char **reversed_array = (char **)malloc(len * sizeof(char *));

    for (int i = 0; i < len; i++)
    {
        reversed_array[i] = arr[len - 1 - i];
    }

    return reversed_array;
}