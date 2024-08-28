#ifndef PLAY_AGAIN_CHOOSE_H
#define PLAY_AGAIN_CHOOSE_H

#include <stdbool.h>

#include "../utils/clear_input_buffer.h"
#include "../screens/show_new_game_screen.h"
#include "../utils/handle_invalid_choice.h"

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
 * @brief Prompts the user to choose whether to play the game again or exit.
 * 
 * This function displays a prompt asking the user if they want to play again. 
 * It waits for a valid response (`'s'` for yes or `'n'` for no). 
 * Based on the user's input, it either starts a new game or exits the program.
 * 
 * The function handles invalid inputs by prompting the user again until a valid response is received.
 */
void play_again_choose();

#endif