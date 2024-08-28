#ifndef PRINT_GAME_H
#define PRINT_GAME_H

#include "../configs/types.h"
#include "../screens/clear_screen.h"
#include "../utils/sleep_time.h"
#include "print_history.h"
#include "print_table.h"
#include "print_hands.h"

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
 * - ansi.h
 * - general.h
 * - print_line.h
 * - print_line_with_preffix.h
 * - get_color_ansi.h
 * - get_color_name.h
 * - int_between_parenthesis.h
 * - int_to_string.h
 * - is_invalid_color.h
 * - types.h
 * - count_digits.h
 * - concat_char.h
 * - concat_string.h
 */

/**
 * @brief Displays the current state of the game to the user.
 *
 * This function clears the screen, prints the game history, displays the top card on the table, and shows the hands of the player and opponents.
 * It pauses for a transition time to allow the user to view the updates.
 *
 * @param messages A pointer to an array of strings representing the game history messages.
 * @param messages_length The number of messages in the history array.
 * @param top_card The card currently on top of the table.
 * @param num_opponent_cards The number of cards held by opponents.
 * @param player_cards A pointer to an array of cards held by the player.
 * @param num_player_cards The number of cards held by the player.
 */
void print_game(char **messages, int messages_length, Card top_card, int num_opponent_cards, Card *player_cards, int num_player_cards);

#endif