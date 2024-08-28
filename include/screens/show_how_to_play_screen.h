#ifndef SHOW_HOW_TO_PLAY_H
#define SHOW_HOW_TO_PLAY_H

#include "../utils/clear_input_buffer.h"
#include "../prints/print_bold.h"
#include "../screens/transition.h"

/**
 * Inherited libs:
 * - stdio.h
 * - stdlib.h
 * - stdbool.h
 * - strarg.h
 * - unistd.h
*/

/**
 * Inherited internal libs:
 * - stylized_print.h
 * - ansi.h
 * - screens.h
 * - types.h
*/

/**
 * @brief Displays the "How to Play" screen of the UNO_C program.
 *
 * This function provides instructions on how to play the game. The instructions include:
 * 1. To play any card, enter the number corresponding to the card's index.
 * 2. To draw a card, enter 0.
 * 3. To say "UNO", type "uno" immediately after choosing the card index.
 *
 * The user is prompted to press any key to return to the main menu.
 */
void show_how_to_play_screen();

#endif