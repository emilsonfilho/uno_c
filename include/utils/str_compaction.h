#ifndef STR_COMPACTION_H
#define STR_COMPACTION_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Removes an element from a dynamically allocated array of strings and resizes the array.
 *
 * This function removes the string at the specified index (`hole`) from an array of string pointers.
 * It then compacts the array by shifting the remaining elements and resizes the array to reflect the new size.
 * Memory is managed by freeing the removed string and reallocating the array.
 *
 * @param arr Pointer to the array of strings.
 * @param arr_size Pointer to the size of the array. This will be updated to reflect the new size after compaction.
 * @param hole Index of the element to be removed from the array.
 *
 * @return A pointer to the resized array of strings.
 */
char **str_compaction(char **arr, int *arr_size, int hole);

#endif