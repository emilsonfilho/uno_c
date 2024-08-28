#ifndef COMPARE_CARDS_H
#define COMPARE_CARDS_H

#include <string.h>

#include "../configs/types.h"

/**
 * Inherited libs:
 * - stdbool.h
*/

/**
 * Compare two cards and tell the program which card is smaller or bigger
 *
 * @param card1 The first card to compare
 * @param card2 The second card to compare
 * @return      A number to identify which card is before
 */
int compare_cards(Card card1, Card card2);

#endif