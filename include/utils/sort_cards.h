#ifndef SORT_CARDS_H
#define SORT_CARDS_H

#include "swap.h"
#include "compare_cards.h"

/**
 * Inherited libs: 
 * - stdbool.h
 * - string.h
*/

/**
 * Inherited internal libs: 
 * - types.h
*/

/**
 * Sorts an array of Card structures based on color and card comparison.
 *
 * This function implements a bubble sort algorithm to sort the array `arr`
 * of Card structures in ascending order based on color first and then by
 * comparing the cards using the `compare_cards` function.
 *
 * @param arr Pointer to an array of Card structures to be sorted.
 * @param n   Number of elements in the array `arr`.
 */
void sort_cards(Card *arr, int n);

#endif