#ifndef CREATE_DECK_H
#define CREATE_DECK_H

#include <stdlib.h>

#include "../configs/general.h"
#include "../utils/copy_action.h"

/**
 * Inherited libs: 
 * - stdio.h
 * - stdbool.h
 * - string.h
*/

/**
 * @brief Creates and initializes a deck of cards.
 *
 * This function creates a standard deck of cards used in a game.
 * The deck includes number cards (0-9) in four colors (RED, BLUE, GREEN, YELLOW),
 * special action cards in those colors (block, reverse, +2), and special action
 * cards without a color (change, +4).
 *
 * @return A pointer to the created deck of cards.
 *
 * The deck contains the following:
 * - For each color (RED, BLUE, GREEN, YELLOW):
 *   - One card of number 0.
 *   - Two sets of cards numbered 1 to 9.
 *   - Two sets of special action cards (block, reverse, +2).
 * - Two special action cards without a color (change, +4).
 */
Card *create_deck();

#endif