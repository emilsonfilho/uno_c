#include "../../include/utils/int_to_string.h"

char *int_to_string(int number)
{
    int digits = count_digits(number);
    char *str = (char *)malloc((digits + 1) * sizeof(char));

    sprintf(str, "%d", number);

    return str;
}