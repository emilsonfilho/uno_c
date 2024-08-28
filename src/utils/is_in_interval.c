#include "../../include/utils/is_in_interval.h"

bool is_in_interval(int number, int min, int max)
{
    return min <= number && number <= max;
}