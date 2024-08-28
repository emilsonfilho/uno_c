#include "../../include/utils/get_color_name.h"

char *get_color_name(Color color)
{
    if (is_invalid_color(color))
        return "Invalid";

    return color_mapper[color];
}