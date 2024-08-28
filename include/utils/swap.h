#ifndef SWAP_H
#define SWAP_H

#include "../configs/types.h"

/**
 * Swaps two elements in an array of Card structures.
 *
 * This function swaps the elements at indices `i` and `j` in the array `arr`
 * of Card structures. It does not allocate or deallocate memory.
 *
 * @param arr Pointer to an array of Card structures.
 * @param i   Index of the first element to be swapped.
 * @param j   Index of the second element to be swapped.
 */
void swap(Card *arr, int i, int j);

#endif