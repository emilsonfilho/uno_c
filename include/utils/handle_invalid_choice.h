#ifndef HANDLE_INVALID_CHOICE_H
#define HANDLE_INVALID_CHOICE_H

#include "delete_lines_by_errors.h"

/**
 * Inherited libs:
 * - stdio.h
 * - stdbool.h
*/

/**
 * @brief Handles the display of an error message for an invalid choice.
 * 
 * This function manages the display of error messages when an invalid choice is made. 
 * It updates the error state, clears any previous error messages, and prints the new error message.
 * 
 * @param was_last_entry_invalid Pointer to a boolean flag indicating if the last entry was invalid. This will be updated to `true`.
 * @param message The error message to be displayed to the user.
 */
void handle_invalid_choice(bool *was_last_entry_invalid, char *message);

#endif