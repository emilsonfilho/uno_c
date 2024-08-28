#ifndef IS_NUMBER_MATCH_H
#define IS_NUMBER_MATCH_H

#include "../configs/types.h"

/**
 * Inherited libs:
 * - stdbool.h
*/

/**
 * @brief Checks if two cards have the same number value.
 *
 * @param card1 The first `Card` to be compared.
 * @param card2 The second `Card` to be compared.
 *
 * @return `true` if both cards are number cards and have the same number value, otherwise `false`.
 */
bool is_number_match(Card card1, Card card2);

#endif