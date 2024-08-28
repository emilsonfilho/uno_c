#ifndef PRINT_LINE_WITH_PREFFIX
#define PRINT_LINE_WITH_PREFFIX

#include <stdio.h>
#include <string.h>

#include "../configs/general.h"
#include "../configs/ansi.h"

/**
 * @brief Prints a formatted line with a specified prefix and optionally colored card content.
 *
 * This function prints a line of characters, where the first and last characters are '*',
 * and spaces are inserted at the edges. It inserts the provided prefix at the beginning,
 * and if a colored card content is provided, it inserts it preceded by ANSI color escape
 * sequences to format the text. The line is formatted to fit within a predefined screen length.
 *
 * @param prefix The string to be printed at the beginning of the line.
 * @param color_card The string representing the colored card content to be printed.
 *                   If NULL, no colored card content is printed.
 * @param ansi_color The ANSI escape code to apply to the color_card content for formatting.
 *                   Ignored if color_card is NULL.
 */
void print_line_with_prefix(char *prefix, const char *color_card, const char *color_ansi);

#endif