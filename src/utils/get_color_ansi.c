#include "../../include/utils/get_color_ansi.h"

char *get_color_ansi(Color color)
{
    if (is_invalid_color(color))
        return RESET;

    switch (color)
    {
    case 0:
        return ANSI_RED;
        break;
    case 1:
        return ANSI_GREEN;
        break;
    case 2:
        return ANSI_BLUE;
        break;
    case 3:
        return ANSI_YELLOW;
        break;
    default:
        return RESET;
        break;
    }
}