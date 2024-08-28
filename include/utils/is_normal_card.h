#ifndef IS_NORMAL_CARD_H
#define IS_NORMAL_CARD_H

#include "../configs/types.h"

/**
 * Inherited libs:
 * - stdbool.h
*/

/**
 * @brief Checks if the given card is a normal playing card.
 *
 * This function evaluates whether the provided card is a normal playing card
 * by verifying that its color is not WILD and its number attribute is true.
 *
 * @param card The card structure to be evaluated.
 * @return true if the card is a normal playing card, false otherwise.
 */
bool is_normal_card(Card card);

#endif