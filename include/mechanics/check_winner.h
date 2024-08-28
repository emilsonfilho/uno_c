#ifndef CHECK_WINNER_H
#define CHECK_WINNER_H

#include "play_again_choose.h"

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
 */

/**
 * @brief Checks if a player or opponent has won the game based on the number of remaining cards.
 * 
 * This function determines if a player or opponent has won the game 
 * by checking if their number of remaining cards is zero. 
 * If so, it displays a win or loss message and triggers the option to play again.
 * 
 * @param num_cards The number of cards remaining for the player or opponent.
 * @param is_player Flag indicating if the check is for the player (`true`) or the opponent (`false`).
 */
void check_winner(int num_cards, bool is_player);

#endif
