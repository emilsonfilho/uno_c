#ifndef PRINT_TABLE_H
#define PRINT_TABLE_H

#include "../utils/get_color_ansi.h"
#include "../utils/get_color_name.h"
#include "../utils/int_to_string.h"
#include "print_line.h"
#include "print_line_with_preffix.h"


/**
 * Inherited libs:
 * - stdio.h
 * - stdlib.h
 * - stdbool.h
 * - string.h
*/

/**
 * Inherited internal libs:
 * - general.h
 * - ansi.h
 * - is_invalid_color.h
 * - types.h
 * - count_digits.h
*/

/**
 * @brief Prints the current top card on the table.
 *
 * This function formats and displays the top card on the table,
 * including its color and number or action.
 * It constructs a string representation of the card, applies appropriate ANSI color codes,
 * and prints the card information with a prefix.
 * It handles both numeric and action cards differently by
 * converting their details into a string format suitable for display.
 *
 * @param top_card The card currently on top of the table, containing its color, number, and action.
 *
 * @return void
 */
void print_table(Card top_card);

#endif