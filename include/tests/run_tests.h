#ifndef RUN_TESTS_H
#define RUN_TESTS_H


#include <time.h>

#include "../configs/general.h"
#include "../inits/create_deck.h"
#include "../utils/are_arrays_equal.h"
#include "../utils/get_color_name.h"
#include "../utils/get_color_ansi.h"
#include "../utils/reverse.h"
#include "../utils/str_compaction.h"
#include "../utils/int_to_string.h"
#include "../utils/concat_char.h"
#include "../utils/concat_string.h"
#include "../utils/int_between_parenthesis.h"
#include "../utils/is_in_interval.h"
#include "../utils/can_play_card.h"
#include "../mechanics/get_card_for_table.h"
#include "../mechanics/push_history.h"
#include "../mechanics/push_card.h"
#include "show_card_error_message.h"
#include "show_tests_error_message.h"
#include "tests.h"

/**
 * Inherited libs: 
 * - stdio.h
 * - stdbool.h
 * - stdlib.h
 * - string.h
*/

/**
 * Inherited internal libs: 
 * - screens.h
 * - types.h
 * - general.h
 * - copy_action.h
 * - are_strings_equal.h
 * - is_invalid_color.h
 * - ansi.h
 * - count_digits.h
 * - swap.h
 * - compare_cards.h
 * - is_color_match.h
 * - is_number_match.h
 * - is_action_match.h
 * - is_wild_card.h
 * - global.h
 * - is_normal_card.h
 * - random_array_index.h
 * - compaction.h
 * - sort_cards.h
 * - are_card_arrays_equal.h
*/

/**
 * @brief Runs a series of unit tests for the program.
 *
 * This function performs unit tests on various functions within the program.
 * It measures the time taken to run the tests and outputs the results. The
 * current implementation includes tests for the following:
 *
 * - Function `create_deck`: Tests if the created deck of cards matches the
 *   expected deck configuration.
 * - Function `reverse`: Tests whether the function returns the
 *   array of strings in a reversed form
 * - Function `get_color_name`: Tests if it returns the right color
 * - Function `get_color_ansi`: Tests if it returns the right color
 *   in ANSI format
 * - Function `is_normal_card`: Tests if a card is "normal"
 * - Function `is_invalid_color`: Tests if a given color is invalid
 * - Function `compaction`: Tests whether the
 *   Compaction & Left Shifting method is performed correctly
 * - Function `str_compaction`: Tests whether the
 *   Compaction & Left Shifting method for strings is executed correctly
 * - Function `push_history`: Tests whether the history is
 *   updated correctly (See push_history behavior)
 * - Function `count_digits`: Tests the digit count of a number
 * - Function `int_to_string`: Tests whether a number is
 *   converted to a string correctly
 * - Function `concat_char`: Tests if two characters are concatenated
 * - Function `concat_string`: Tests if two strings are concatenated
 * - Function int_between_parenthesis: Tests if a number is
 *   placed inside parentheses
 * - Function `sort_cards`: Tests whether an array
 *   of cards has been sorted correctly
 * - Function `is_color_match`: Test if the colors of two cards are the same
 * - Function `is_number_match`: Test if the numbers on two cards are the same
 * - Function `is_wild_card`: Test if a card is WILD
 * - Function `is_in_interval`: Tests if a number is within a range
 * - Function `can_play_card`:  Test whether a card can be played
 * - Function `push_cards`: A new card has been placed in the hand correctly
 *
 * Any errors detected during the tests will trigger an error message using
 * `show_card_error_message`, which will indicate discrepancies between the
 * expected and actual card properties.
 */
void run_tests();

#endif