#ifndef TRANSITION_H
#define TRANSITION_H

#include "../configs/global.h"
#include "../configs/general.h"
#include "../utils/sleep_time.h"
#include "clear_screen.h"

/**
 * Inherited libs: 
 * - stdlib.h
 * - unistd.h
 * - stdbool.h
*/

/**
 * Inherited internal libs:
 * - screens.h
 * - types.h
*/

/**
 * @brief Transitions to the specified screen with a delay.
 *
 * @param next_screen The identifier of the screen to transition to.
 */
void transition(int next_screen);

#endif