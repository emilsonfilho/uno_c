#ifndef IS_ACTION_MATCH_H
#define IS_ACTION_MATCH_H

#include "../configs/types.h"
#include "are_strings_equal.h"

/**
 * Inherited libs: 
 * - stdbool.h
 * - string.h
*/

/**
 * @brief Checks if two cards have the same action.
 *
 * @param card1 The first `Card` to be compared.
 * @param card2 The second `Card` to be compared.
 *
 * @return `true` if both cards are action cards and have the same action, otherwise `false`.
 */
bool is_action_match(Card card1, Card card2);

#endif