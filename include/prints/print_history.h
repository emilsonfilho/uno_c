#ifndef PRINT_HISTORY_H
#define PRINT_HISTORY_H

#include "../utils/reverse.h"

#include "print_line.h"
#include "print_line_with_preffix.h"

/**
 * Inherited libs:
 * - stdio.h
 * - stdlib.h
 * - string.h
*/

/**
 * Inherited internal libs:
 * - general.h
 * - ansi.h
*/

/**
 * @brief Prints the last three messages from the game history.
 *
 * This function reverses the order of the history messages and prints the most recent three messages.
 * It formats each message with a prefix and ensures that if there are fewer than three messages,
 * empty lines are printed to maintain a consistent display.
 *
 * @param messages A pointer to an array of strings representing the game history messages.
 * @param messages_length The number of messages in the history array.
 */
void print_history(char **messages, int messages_length);

#endif