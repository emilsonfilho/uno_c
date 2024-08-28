#ifndef UPDATE_HISTORY_H
#define UPDATE_HISTORY_H

#include "../mechanics/push_history.h"
#include "../utils/is_wild_card.h"
#include "../utils/get_color_name.h"

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
 * - is_invalid_color.h
*/

/**
 * @brief Updates the game history based on the current actions and state.
 * 
 * This function appends new entries to the game history based on whether a card was played, 
 * skipped, or drawn. 
 * It records actions taken by the player or the opponent, 
 * including special cases such as choosing a color for a wild card.
 * 
 * @param top_card The card that is currently on top of the table.
 * @param chosen_color The color chosen if a wild card was played.
 * @param history Pointer to the history array of messages. This will be updated with new entries.
 * @param history_size Pointer to the number of entries in the history. This will be updated if new entries are added.
 * @param is_player Flag indicating if the action was performed by the player (`true`) or the opponent (`false`).
 * @param played Flag indicating if a card was played (`true`) or not (`false`).
 * @param skipped Flag indicating if the turn was skipped (`true`) or not (`false`).
 * @param drawed Flag indicating if cards were drawn (`true`) or not (`false`).
 */
void update_history(Card top_card, Color chosen_color, char ***history, int *history_size, bool is_player, bool played, bool skipped, bool drawed);

#endif