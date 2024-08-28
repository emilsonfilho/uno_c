#ifndef CARD_SKIP_NEXT_PLAYER_H
#define CARD_SKIP_NEXT_PLAYER_H

#include "../configs/types.h"
#include "are_strings_equal.h"

/**
 * Inherited libs:
 * - stdbool.h
 * - string.h
*/

/**
 * @brief Determines if a card causes the next player to be skipped or affected.
 * 
 * This function checks if a given card has an action that impacts the next player's turn. 
 * Specifically, it checks if the card's action is one that blocks, reverses, draws 2, or draws 4 cards.
 * 
 * @param[in] card The card to check for special actions.
 * 
 * @return `true` if the card's action causes the next player to be skipped or affected; `false` otherwise.
 */
bool card_skip_next_player(Card card);

#endif