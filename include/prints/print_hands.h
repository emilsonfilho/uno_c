#ifndef PRINT_HANDS_H
#define PRINT_HANDS_H

#include "print_line.h"
#include "print_opponent_cards.h"
#include "print_player_cards.h"

/**
 * Inherited libs:
 * - stdio.h
 * - stdlib.h
 * - stdbool.h
 * - string.h
*/

/**
 * Inherited internal libs:
 * - general.h
 * - ansi.h
 * - print_line_with_preffix.h
 * - concat_char.h
 * - concat_string.h
 * - int_to_string.h
 * - int_between_parenthesis.h
 * - get_color_ansi.h
 * - count_digits.h
 * - types.h
 */

/**
 * Prints the hands of both the opponent and the player.
 *
 * This function constructs and displays formatted representations of the opponent's
 * and player's card hands. The opponent's hand is represented as a series of 'x' marks
 * enclosed in brackets, while the player's hand displays each card's color and either
 * a number or action associated with it.
 *
 * @param num_opponent_cards The number of cards held by the opponent.
 * @param player_cards      Array of Card structs representing the player's cards.
 * @param num_player_cards  The number of cards held by the player.
 */
void print_hands(int num_opponent_cards, Card *player_cards, int num_player_cards);

#endif