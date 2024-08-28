#ifndef PUSH_CARD_H
#define PUSH_CARD_H

#include <stdio.h>
#include <stdlib.h>

#include "../utils/sort_cards.h"

/**
 * Inherited libs: 
 * - stdbool.h
 * - string.h
*/

/**
 * Inherited internal libs: 
 * - types.h
 * - swap.h
 * - compare_cards.h
*/

/**
 * @brief Adds a new card to the end of the card array and sorts the array.
 *
 * This function reallocates memory for the card array to accommodate one additional card,
 * appends the new card to the end of the array, and then sorts the array.
 *
 * @param cards Pointer to the current array of cards.
 * @param size Pointer to the number of cards in the array. This will be incremented by 1.
 * @param new_card The card to be added to the array.
 *
 * @return A pointer to the reallocated and sorted array of cards.
 */
Card *push_card(Card *cards, int *size, Card new_card);

#endif