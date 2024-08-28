#ifndef PLAY_CARD_H
#define PLAY_CARD_H

#include "../utils/can_play_card.h"
#include "../utils/handle_invalid_choice.h"
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
 * - swap.h
 * - compare_cards.h
 * - compaction.h
 * - random_array_index.h
 * - global.h
 * - is_color_match.h
 * - is_number_match.h
 * - is_action_match.h
 * - is_wild_card.h
 * - are_strings_equal.h
*/

/**
 * @brief Handles the player's choice of a card to play and updates the game state accordingly.
 * 
 * This function prompts the player to select a card from their hand to play. 
 * It checks if the selected card is valid and can be played based on the top card and chosen color. 
 * It also handles special cases where the player opts to draw a new card 
 * or if the player has skipped their turn.
 * 
 * @param cards Pointer to the player's hand (array of `Card` structures). 
 *                      This will be updated if the chosen card is removed from the hand.
 * @param cards_size Pointer to the size of the player's hand. 
 *                           This will be updated if the chosen card is removed from the hand.
 * @param top_card Pointer to the current top card on the table.
 * @param chosen_color The color chosen for the card to be played.
 * @param player_played Flag indicating if the player has played a card.
 * @param player_skipped Flag indicating if the player has skipped their turn.
 * 
 * @return The `Card` that the player has chosen to play, 
 *         or a default `WILD` card if the player has skipped or drawn a new card.
 */
Card play_card(Card **cards, int *cards_size, Card *top_card, Color chosen_color, bool *player_played, bool player_skipped);

#endif