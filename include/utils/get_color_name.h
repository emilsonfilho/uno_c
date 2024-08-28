#ifndef GET_COLOR_NAME_H
#define GET_COLOR_NAME_H

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
 * @brief Retrieves the name associated with the given color.
 *
 * @param color The enum value representing the color.
 * @return A string representing the name of the color.
 *
 * @note If the color is not valid (as determined by is_invalid_color), it returns "Invalid".
 */
char *get_color_name(Color color);

#endif