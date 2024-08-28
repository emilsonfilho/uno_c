#ifndef DRAW_CARD_H
#define DRAW_CARD_H

#include "../utils/compaction.h"
#include "../utils/random_array_index.h"
#include "../configs/global.h"


/**
 * Inherited libs:
 * - stdio.h
 * - stdlib.h
 * - stdbool.h
*/

/**
 * Inherited internal libs:
 * - types.h
 * - screens.h
*/

/**
 * @brief Draws a random card from the deck and removes it from the deck.
 * 
 * This function selects a random card from the global deck, removes it from the deck, and returns it. 
 * The deck is updated to reflect the removal of the drawn card.
 * 
 * @return The randomly drawn card from the deck.
 */
Card draw_card();

#endif