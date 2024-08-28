#ifndef SHOW_GAME_SCREEN_H
#define SHOW_GAME_SCREEN_H

#include "../prints/print_game.h"
#include "../mechanics/play_card.h"
#include "../updates/update_table.h"
#include "../updates/update_history.h"
#include "../mechanics/check_play.h"
#include "../mechanics/check_opponent_play.h"
#include "../mechanics/check_winner.h"
#include "../mechanics/opponent_play.h"

/**
 * Inherired libs:
 * - stdio.h
 * - stdlib.h
 * - stdbool.h
 * - string.h
 * - unistd.h
*/

/**
 * Inherited internal libs:
 * - types.h
 * - clear_screen.h
 * - sleep_time.h
 * - print_history.h
 * - print_table.h
 * - print_hands.h
 * - ansi.h
 * - general.h
 * - print_line.h
 * - print_line_with_preffix.h
 * - get_color_ansi.h
 * - get_color_name.h
 * - int_between_parenthesis.h
 * - int_to_string.h
 * - is_invalid_color.h
 * - count_digits.h
 * - concat_char.h
 * - concat_string.h
 * - can_play_card.h
 * - draw_card.h
 * - push_card.h
 * - swap.h
 * - compare_cards.h
 * - compaction.h
 * - random_array_index.h
 * - global.h
 * - is_color_match.h
 * - is_number_match.h
 * - is_action_match.h
 * - is_wild_card.h
 * - is_normal_card.h
 * - are_strings_equal.h
 * - screens.h
 * - sort_cards.h
*/

/**
 * @brief Displays the current game screen and manages the game flow for both the player and the opponent.
 * 
 * This function orchestrates the game screen updates, including displaying the current state of the game, 
 * handling player and opponent actions, updating the game state, and checking for winners. 
 * It calls various functions to process card plays, update the game table, and manage the game history.
 * 
 * @param history Pointer to a pointer to the history array of strings. This will be updated with new game history.
 * @param history_size Pointer to the size of the history array. This will be updated if the history grows.
 * @param player_cards Pointer to the array of `Card` structures representing the player's hand. This will be updated if the player plays or draws cards.
 * @param num_player_cards Pointer to the number of cards in the player's hand. This will be updated as cards are played or drawn.
 * @param opponent_cards Pointer to the array of `Card` structures representing the opponent's hand. This will be updated if the opponent plays or draws cards.
 * @param num_opponent_cards Pointer to the number of cards in the opponent's hand. This will be updated as cards are played or drawn.
 * @param top_card Pointer to the `Card` currently on top of the table. This will be updated based on card plays.
 * @param chosen_color Pointer to the color chosen for card plays. This will be updated as needed.
 * @param player_skipped Pointer to a boolean flag indicating if the player has skipped their turn. This will be updated.
 * @param opponent_skipped Pointer to a boolean flag indicating if the opponent has skipped their turn. This will be updated.
 * @param player_drawed Pointer to a boolean flag indicating if the player has drawn a card. This will be updated.
 * @param opponent_drawed Pointer to a boolean flag indicating if the opponent has drawn a card. This will be updated.
 */
void show_game_screen(char ***history, int *history_size, Card *player_cards, int *num_player_cards, Card *opponent_cards, int *num_opponent_cards, Card *top_card, Color *chosen_color, bool *player_skipped, bool *opponent_skipped, bool *player_drawed, bool *opponent_drawed);

#endif