#ifndef IS_INVALID_COLOR_H
#define IS_INVALID_COLOR_H

#include "../configs/types.h"

/**
 * Inherited libs:
 * - stdbool.h
*/

/**
 * @brief Checks if the given color enum value is invalid.
 *
 * This function evaluates whether the provided color enumeration value
 * is greater than 4, indicating it is out of the valid range of color values.
 *
 * @param color The enumeration value representing the color.
 * @return true if the color is invalid, false otherwise.
 */
bool is_invalid_color(Color color);

#endif