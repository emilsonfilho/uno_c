#ifndef GET_CARD_FOR_TABLE_H
#define GET_CARD_FOR_TABLE_H

#include "../configs/global.h"
#include "../utils/is_normal_card.h"
#include "../utils/random_array_index.h"
#include "../utils/compaction.h"

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
 * @brief Retrieves a random normal card from the deck and removes it from the deck.
 *
 * @return The selected card that is removed from the deck.
 *
 * @note If no matching card is found, the function terminates with an error message.
 */

Card get_card_for_table();

#endif