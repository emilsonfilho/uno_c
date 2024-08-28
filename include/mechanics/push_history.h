#ifndef PUSH_HISTORY_H
#define PUSH_HISTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Adds a new message to the history of messages.
 *
 * @param current_history Pointer to the array of strings representing the current message history.
 * @param current_size Pointer to the size of the current message history.
 * @param new_message The new message to be added to the history.
 * @return Updated pointer to the array of strings representing the updated message history.
 *         If memory allocation fails, the function prints an error message and exits the program.
 *
 * @note If the history size (`current_size`) exceeds a predefined limit (3), the oldest message is removed
 * to make room for the new message.
 */
char **push_history(char **current_history, int *current_size, char *new_message);

#endif