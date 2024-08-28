#include "../../include/utils/concat_string.h"

char *concat_string(char *str, int *str_size, char *suffix)
{
    int suffix_size = strlen(suffix);

    strcpy(str + *str_size, suffix);

    *str_size += suffix_size;

    return str;
}