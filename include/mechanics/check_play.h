#ifndef CHECK_PLAY_H
#define CHECK_PLAY_H

#include "../utils/is_in_interval.h"
#include "../utils/is_wild_card.h"
#include "../configs/ansi.h"
#include "../utils/card_skip_next_player.h"
#include "../utils/is_colored_draw_card.h"
#include "../utils/handle_invalid_choice.h"
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
 * @brief Evaluates the effects of a card played by the player and updates the game state accordingly.
 * 
 * This function checks the implications of playing a given card, 
 * including handling special cards (wild cards and action cards), 
 * updating the chosen color, and managing game effects such as skipping turns or drawing cards. 
 * It modifies various game state variables based on the card played.
 * 
 * @param card The card that has been played by the player.
 * @param chosen_color The color chosen for the card play, updated based on the played card and user input.
 * @param player_played Flag indicating if the player has played a card.
 * @param opponent_skip Flag indicating if the opponent's turn should be skipped.
 * @param opponent_cards Pointer to the opponent's hand (array of `Card` structures). This may be updated if cards are added.
 * @param num_opponent_cards Pointer to the number of cards in the opponent's hand. This may be updated if cards are added.
 * @param opponent_draws Flag indicating if the opponent should draw cards.
 * @param player_cards Pointer to the player's hand (array of `Card` structures). This may be updated if cards are reversed.
 * @param num_player_cards Pointer to the number of cards in the player's hand. This may be updated if cards are reversed.
 */
void check_play(Card card, Color *chosen_color, bool player_played, bool *opponent_skip, Card **opponent_cards, int *num_opponent_cards, bool *opponent_draws, Card **player_cards, int *num_player_cards);

#endif