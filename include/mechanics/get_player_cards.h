#ifndef GET_PLAYER_CARDS_H
#define GET_PLAYER_CARDS_H

#include "../configs/general.h"
#include "../configs/global.h"
#include "../utils/random_array_index.h"
#include "../utils/compaction.h"

/**
 * Inherited libs:
 * - stdbool.h
 * - stdlib.h
 * - stdio.h
*/

/**
 * Inherited internal libs:
 * - types.h
 * - screens.h
*/

/**
 * Retrieves player cards from a deck, removing them from the deck.
 *
 * @return          Pointer to an array of Card structures representing the player's cards.
 *                  Memory is dynamically allocated for this array. The caller is responsible for freeing
 *                  this memory when no longer needed.
 *
 * @note Memory is allocated for the player's card array dynamically.
 */
Card *get_player_cards();

#endif