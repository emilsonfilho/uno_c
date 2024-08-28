#include "../../include/utils/concat_char.h"

char *concat_char(char *str, int *str_size, char ch)
{
    // char* new_str = (char*) realloc(str, (*str_size + 1) * sizeof(char));
    str[*str_size] = ch;
    (*str_size)++;
    str[*str_size] = '\0';

    return str;
}