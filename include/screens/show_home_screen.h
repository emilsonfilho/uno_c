#ifndef SHOW_HOME_SCREEN_H
#define SHOW_HOME_SCREEN_H

#include <stdio.h>

#include "../configs/screens.h"
#include "transition.h"

/**
 * Inherited libs:
 * - stlib.h
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
 * @brief Displays the home screen of the UNO_C program.
 *
 * This function presents the user with a welcome message.
 * After a key is pressed, it transitions the program to the
 * main menu.
 */
void show_home_screen();

#endif