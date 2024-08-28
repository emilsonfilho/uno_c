#ifndef IS_COLORED_DRAW_CARD_H
#define IS_COLORED_DRAW_CARD_H

#include "../configs/types.h"

#include "are_strings_equal.h"

/**
 * Inherited libs:
 * - stdbool.h
 * - string.h
*/

/**
 * @brief Checks if a card is a colored draw card.
 * 
 * This function determines if a given card is a colored draw card, 
 * specifically a card with the "+2" action that affects the next player. 
 * The card is considered a colored draw card if it is not a number card and has the "+2" action.
 * 
 * @param[in] card The card to check.
 * 
 * @return `true` if the card is a colored draw card; `false` otherwise.
 */
bool is_colored_draw_card(Card card);

#endif