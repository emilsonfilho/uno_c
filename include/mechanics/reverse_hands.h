#ifndef REVERSE_HANDS_H
#define REVERSE_HANDS_H

#include <stdlib.h>
#include <string.h>

#include "../configs/types.h"

/**
 * Inherited libs:
 * - stdbool.h
*/

/**
 * @brief Swaps the hands of two players.
 * 
 * This function exchanges the card arrays between two players, effectively reversing their hands. 
 * It reallocates memory if necessary to ensure that both players' hands fit in the allocated space. 
 * The sizes of the hands are also updated accordingly.
 * 
 * @param cards1 Pointer to the array of cards for the first player. This array will be updated to contain the cards from the second player.
 * @param len1 Pointer to the number of cards in the first player's hand. This will be updated to reflect the new hand size.
 * @param cards2 Pointer to the array of cards for the second player. This array will be updated to contain the cards from the first player.
 * @param len2 Pointer to the number of cards in the second player's hand. This will be updated to reflect the new hand size.
 */
void reverse_hands(Card **cards1, int *len1, Card **cards2, int *len2);

#endif