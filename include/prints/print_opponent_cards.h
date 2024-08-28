#ifndef PRINT_OPPONENT_CARDS_H
#define PRINT_OPPONENT_CARDS_H

#include <stdlib.h>

#include "print_line_with_preffix.h"

/**
 * Inherited libs:
 * - stdio.h
 * - string.h
*/

/**
 * Inherited internal libs:
 * - general.h
 * - ansi.h
*/

/**
 * @brief Prints a placeholder representation of the opponent's cards.
 *
 * This function constructs and displays a string
 * that represents the opponent's cards using placeholder characters.
 * Each card is represented by the character 'x', and the entire hand is enclosed in square brackets.
 * The representation is then printed with a prefix "Oponente: ".
 *
 * @param num_cards The number of opponent's cards to be represented in the output.
 *
 * @return void
 */
void print_opponent_cards(int num_cards);

#endif