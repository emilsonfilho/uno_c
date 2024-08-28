#ifndef IS_COLOR_MATCH
#define IS_COLOR_MATCH

#include "../configs/types.h"

/**
 * Inherited libs:
 * - stdbool.h
*/

/**
 * @brief Checks if two cards have the same color.
 *
 * @param card1 The first `Card` to be compared.
 * @param card2 The second `Card` to be compared.
 *
 * @return `true` if the colors of `card1` and `card2` match, otherwise `false`.
 */
bool is_color_match(Card card1, Card card2);

#endif