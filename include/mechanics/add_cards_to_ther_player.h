#ifndef ADD_CARDS_TO_OTHER_PLAYER_H
#define ADD_CARDS_TO_OTHER_PLAYER_H

#include "draw_card.h"
#include "push_card.h"

/**
 * Inherited libs:
 * - stdio.h
 * - stdlib.h
 * - stdbool.h
 * - string.h
*/

/**
 * Inherited internal libs:
 * - types.h
 * - screens.h
 * - compaction.h
 * - random_array_index.h
 * - global.h
 * - swap.h
 * - compare_cards.h
 * - sort_cards.h
*/

/**
 * @brief Adds a specified number of cards to another player's hand.
 * 
 * This function draws a number of cards from the deck and adds them to the other player's hand. 
 * It updates the player's card array and the count of cards accordingly.
 * 
 * @param cards Pointer to the array of cards for the player to receive the new cards.
 * @param num_cards Pointer to the number of cards in the player's hand. This will be incremented by the number of cards added.
 * @param num_cards_to_add The number of cards to draw from the deck and add to the player's hand.
 */
void add_cards_to_other_player(Card **cards, int *num_cards, int num_cards_to_add);

#endif