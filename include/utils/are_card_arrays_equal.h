#ifndef ARE_CARD_ARRAYS_EQUAL_H
#define ARE_CARD_ARRAYS_EQUAL_H

#include "../configs/types.h"
#include "are_strings_equal.h"

/**
 * Inherited libs: 
 * - stdbool.h
 * - string.h
*/

/**
 * @brief Compares two arrays of cards to determine if they are equal.
 *
 * This function checks if two arrays of cards are identical in terms of length and content.
 * The comparison includes card color, type (number or action), and for number cards, the number itself.
 * For action cards, it checks if the action strings are equal.
 *
 * @param arr1 Pointer to the first array of `Card` structures.
 * @param len1 The length of the first array.
 * @param arr2 Pointer to the second array of `Card` structures.
 * @param len2 The length of the second array.
 *
 * @return `true` if the arrays are equal, `false` otherwise.
 */
bool are_card_arrays_equal(Card *arr1, int len1, Card *arr2, int len2);

#endif