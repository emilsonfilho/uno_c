#ifndef CHECK_OPPONENT_PLAY_H
#define CHECK_OPPONENT_PLAY_H

#include "../utils/is_colored_draw_card.h"
#include "../utils/is_wild_card.h"
#include "../utils/card_skip_next_player.h"
#include "add_cards_to_ther_player.h"
#include "reverse_hands.h"

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
 * - screens.h
 * - compaction.h
 * - random_array_index.h
 * - global.h
 * - swap.h
 * - compare_cards.h
 * - sort_cards.h
*/

/**
 * @brief Evaluates the effects of a card played by the opponent and updates the game state accordingly.
 * 
 * This function checks the consequences of the opponent playing a given card. 
 * It handles special cases such as wild cards and action cards, updates the chosen color, 
 * and manages game effects like skipping turns or drawing cards.
 * 
 * @param card The card that has been played by the opponent.
 * @param chosen_color The color chosen for the card play, updated based on the played card and random selection.
 * @param opponent_played Flag indicating if the opponent has played a card.
 * @param player_skip Flag indicating if the player's turn should be skipped.
 * @param player_cards Pointer to the player's hand (array of `Card` structures). This may be updated if cards are added.
 * @param num_player_cards Pointer to the number of cards in the player's hand. This may be updated if cards are added.
 * @param player_draws Flag indicating if the player should draw cards.
 * @param opponent_cards Pointer to the opponent's hand (array of `Card` structures). This may be updated if cards are reversed.
 * @param num_opponent_cards Pointer to the number of cards in the opponent's hand. This may be updated if cards are reversed.
 */
void check_opponent_play(Card card, Color *chosen_color, bool opponent_played, bool *player_skip, Card **player_cards, int *num_player_cards, bool *player_draws, Card **opponent_cards, int *num_opponent_cards);

#endif