#ifndef COPY_ACTION_H
#define COPY_ACTION_H

#include <stdio.h>
#include <string.h>

#include "../configs/types.h"

/**
 * Inherited libs:
 * - stdbool.h
*/

/**
 * @brief Copies an action string into a card's action field.
 *
 * This function copies the specified action string into the action field
 * of the given card.
 *
 * @param last_card Pointer to the card whose action field is to be set.
 * @param action The action string to be copied.
 */
void copy_action(Card *last_card, const char *action);

#endif