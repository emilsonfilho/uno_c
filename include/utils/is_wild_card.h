#ifndef IS_WILD_CARD_H
#define IS_WILD_CARD_H

#include "../configs/types.h"

/**
 * Inherited libs:
 * - stdbool.h
*/

/**
 * @brief Checks if a card is a wild card.
 *
 * @param card The `Card` to be checked.
 *
 * @return `true` if the card is a wild card, otherwise `false`.
 */

bool is_wild_card(Card card);

#endif