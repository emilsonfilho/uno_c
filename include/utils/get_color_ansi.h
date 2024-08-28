#ifndef GET_COLOR_ANSI_H
#define GET_COLOR_ANSI_H

#include "../configs/ansi.h"
#include "is_invalid_color.h"

/**
 * Inherited libs: 
 * - stdbool.h
*/

/**
 * Inherited internal libs: 
 * - types.h
*/

/**
 * @brief Retrieves the ANSI escape code associated with the given color.
 *
 * @param color The enumeration value representing the color.
 * @return A string containing the ANSI escape code for the color, or the ANSI reset code if the color is invalid.
 */
char *get_color_ansi(Color color);

#endif