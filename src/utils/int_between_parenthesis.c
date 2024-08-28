#include "../../include/utils/int_between_parenthesis.h"

char *int_between_parenthesis(int number)
{
    int digits = count_digits(number);

    char *str = (char *)malloc((digits + 4) * sizeof(char));

    sprintf(str, "(%d) ", number);

    return str;
}