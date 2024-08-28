#ifndef OPPONENT_PLAY_H
#define OPPONENT_PLAY_H

#include "../utils/can_play_card.h"
#include "../utils/compaction.h"
#include "push_card.h"

#include "draw_card.h"

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
 * - are_strings_equal.h
 * - swap.h
 * - compare_card.h
 * - screens.h
*/

/**
 * @brief Determines and executes the opponent's move in the game.
 * 
 * This function simulates the opponent's turn by selecting a valid card from their hand to play. 
 * If no valid card is found, the opponent draws a new card. 
 * The function updates the game state based on whether the opponent plays a card or not.
 * 
 * @param cards Pointer to the opponent's hand (array of `Card` structures). 
 *              This will be updated if a card is played or drawn.
 * @param num_cards Pointer to the number of cards in the opponent's hand. 
 *                  This will be updated if a card is played or drawn.
 * @param top_card The `Card` currently on top of the table.
 * @param chosen_color The color chosen for the card to be played.
 * @param opponent_played Flag indicating if the opponent has played a card.
 * @param opponent_skipped Flag indicating if the opponent has skipped their turn.
 * 
 * @return The `Card` that the opponent has chosen to play, or a default `WILD` card if no card was played.
 */
Card opponent_play(Card **cards, int *num_cards, Card top_card, Color chosen_color, bool *opponent_played, bool opponent_skipped);

#endif 