#ifndef SHOW_CARD_ERROR_MESSAGE_H
#define SHOW_CARD_ERROR_MESSAGE_H

#include <stdio.h>
#include <stdlib.h>

#include "../configs/types.h"

/**
 * Inherited libs: 
 * - stdbool.h
*/

/**
 * @brief Displays an error message for a card mismatch and terminates the program.
 *
 * This function prints an error message indicating that there was a mismatch
 * between the expected and actual card properties. It outputs the expected
 * card properties and the actual card properties that caused the error.
 *
 * @param error_message A descriptive error message explaining the type of mismatch.
 * @param card_expected The expected card properties.
 * @param card_result The actual card properties that caused the error.
 */
void show_card_error_message(const char *error_message, const Card card_expected, const Card card_result);

#endif