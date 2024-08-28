#ifndef SHOW_MAIN_MENU_SCREEN_H
#define SHOW_MAIN_MENU_SCREEN_H

#include <stdio.h>

#include "transition.h"

/**
 * Inherited libs:
 * - stdlib.h
 * - unistd.h
*/

/**
 * Inherited internal libs:
 * - clear_screen.h
 * - sleep_time.h
 * - global.h
 * - general.h
 * - screens.h
 * - types.h
*/

/**
 * @brief Displays the main menu screen of the UNO_C program.
 *
 * This function presents the user with a list of options to choose from the main menu.
 * The options are:
 * 1. Iniciar novo jogo
 * 2. Regras do jogo
 * 3. Como jogar
 * 4. Sair
 *
 * The user's choice is read and the program transitions to the corresponding state.
 */
void show_main_menu_screen();

#endif