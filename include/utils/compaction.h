#ifndef COMPACTION_H
#define COMPACTION_H

#include <stdio.h>
#include <stdlib.h>

#include "../configs/types.h"

/**
 * Inherited libs:
 * - stdbool.h
*/

/**
 * Removes an element from an array of Card structures and compacts the array.
 *
 * This function removes an element at the specified index `hole` from the array `arr`
 * of Card structures. It compacts the array by shifting all subsequent elements one
 * position to the left. Memory is reallocated to adjust the size of the array.
 *
 * @param arr       Pointer to a pointer to an array of Card structures.
 *                  Upon returning, this pointer is updated to reflect the compacted array.
 * @param arr_size  Pointer to an integer representing the current size of the array `arr`.
 *                  Upon returning, this value is updated to reflect the reduced size of the array.
 * @param hole      Index of the element to be removed from the array `arr`.
 * @return          Pointer to the updated array `arr` after removing and compacting elements.
 *                  Memory is reallocated as needed. The caller is responsible for freeing this memory
 *                  when no longer needed.
 */
Card *compaction(Card *arr, int *arr_size, int hole);

#endif