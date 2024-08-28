#ifndef UPDATE_TABLE_H
#define UPDATE_TABLE_H

#include "../configs/types.h"

/**
 * Inhrerited libs:
 * - stdbool.h
*/

/**
 * @brief Updates the top card on the table if a new card has been played.
 * 
 * This function updates the `current` top card on the table with the `new_card` 
 * if the `played` flag is `true`. If no card has been played (`played` is `false`), 
 * the top card remains unchanged.
 * 
 * @param current Pointer to the `Card` currently on top of the table. This will be updated if a new card has been played.
 * @param new_card The `Card` that should be placed on top of the table if a card has been played.
 * @param played Boolean flag indicating whether a card has been played.
 */

void update_table(Card *current, Card new_card, bool played);

#endif