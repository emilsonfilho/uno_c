#ifndef SHOW_NEW_GAME_SCREEN_H
#define SHOW_NEW_GAME_SCREEN_H

#include "../mechanics/get_player_cards.h"
#include "../mechanics/get_card_for_table.h"
#include "../utils/clear_input_buffer.h"
#include "../mechanics/push_history.h"

#include "show_game_screen.h"

/**
 * Inherited libs:
 * - stdio.h
 * - stdlib.h
 * - stdbool.h
 * - string.h
 * - unistd.h
*/

/**
 * Inherited internal libs:
 * - types.h
 * - screens.h
 * - global.h
 * - is_normal_card.h
 * - random_array_index.h
 * - compaction.h
 * - swap.h
 * - compare_cards.h
 * - ansi.h
 * - general.h
 * - print_line.h
 * - print_line_with_preffix.h
 * - get_color_ansi.h
 * - get_color_name.h
 * - int_to_string.h
 * - is_invalid_color.h
 * - count_digits.h
 * - clear_screen.h
 * - sleep_time.h
 * - print_history.h
 * - print_table.h
 * - print_hands.h
 * - int_between_parenthesis.h
 * - concat_char.h
 * - concat_string.h
 * - can_play_card.h
 * - draw_card.h
 * - push_card.h
 * - is_color_match.h
 * - is_number_match.h
 * - is_action_match.h
 * - is_wild_card.h
 * - are_strings_equal.h
 * - sort_cards.h
 * - print_game.h
 * - play_card.h
 * - update_table.h
 * - update_history.h
 * - check_play.h
 * - check_opponent_play.h
 * - check_winner.h
 * - opponent_play.h
 */


/**
 * @brief Initializes and displays the screen for a new game.
 *
 * This function sets up the initial state for a new game by clearing the input buffer and initializing various game variables.
 * It handles the process of drawing and distributing cards, updating the game history, and showing the game screen.
 * It also manages the display of the game at different stages of setup.
 *
 * The function performs the following steps:
 * 1. Clears the input buffer.
 * 2. Initializes variables related to game state, history, and cards.
 * 3. Retrieves initial cards for both the player and opponent, and sets up the top card on the table.
 * 4. Sorts the player's cards and updates the game history.
 * 5. Displays the game screen at various stages of card distribution.
 * 6. Calls the `show_game_screen` function to present the final setup.
 * 7. Frees allocated memory for the history and player cards.
 *
 * @param None
 *
 * @return void
 */

void show_new_game_screen();

#endif