#include "../../include/utils/is_invalid_color.h"

bool is_invalid_color(Color color)
{
    return (color < 0 || color > 4);
}