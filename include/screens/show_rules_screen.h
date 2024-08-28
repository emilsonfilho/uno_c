#ifndef SHOW_RULES_SCREEN_H
#define SHOW_RULES_SCREEN_H

#include "../utils/clear_input_buffer.h"
#include "../prints/print_bold.h"
#include "../screens/transition.h"

/**
 * Inherited libs:
 * - stdio.h
 * - stdlib.h
 * - stdbool.h
 * - stdarg.h
 * - unistd.h
*/

/**
 * Inherited internal libs:
 * - ansi.h
 * - stylized_print.h
 * - screens.h
 * - types.h
*/

/**
 * @brief Displays the rules screen of the UNO_C program.
 *
 * This function shows the rules of the game to the user. The rules include:
 * 1. Each player receives 7 cards.
 * 2. The objective is to be the first to discard all cards.
 * 3. Cards can only be played if they match the color, number, or are special cards.
 * 4. Special cards have different effects (block, reverse, draw two, draw four, and change color).
 * 5. Number 0 cards swap players' hands.
 * 6. When playing the second-to-last card, say "UNO".
 * 7. If rule 6 is violated, you must draw two cards.
 * 8. If no playable card is available, draw a card.
 *
 * The user is prompted to press any key to return to the main menu.
 */
void show_rules_screen();

#endif