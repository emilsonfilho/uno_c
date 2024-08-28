#ifndef PRINT_PLAYER_CARDS_H
#define PRINT_PLAYER_CARDS_H

#include "../utils/concat_char.h"
#include "../utils/concat_string.h"
#include "../utils/int_to_string.h"
#include "../utils/int_between_parenthesis.h"
#include "../utils/get_color_ansi.h"
#include "print_line_with_preffix.h"

/**
 * Inherited libs:
 * - stdio.h
 * - stdlib.h
 * - stdbool.h
 * - string.h
*/

/**
 * Inherited internal libs:
 * - count_digits.h
 * - general.h
 * - ansi.h
 * - types.h
*/

/**
 * @brief Prints the player's cards with their respective details.
 *
 * This function iterates through an array of player's cards
 * and prints each card with its color and number or action.
 * Each card is formatted with a prefix indicating its index and is displayed using a corresponding color.
 *
 * @param cards Pointer to an array of `Card` structures representing the player's cards.
 * @param num_cards The number of cards in the player's hand.
 *
 * @return void
 */
void print_player_cards(Card *cards, int num_cards);

#endif