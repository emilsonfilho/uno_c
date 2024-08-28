#ifndef ARE_ARRAYS_EQUAL_H
#define ARE_ARRAYS_EQUAL_H

#include "are_strings_equal.h"

/**
 * Inherited libs: 
 * - stdbool.h
 * - string.h
*/

/**
 * @brief Checks if two arrays of strings are equal.
 *
 * @param arr1 Pointer to the first array of strings.
 * @param len1 Number of elements in the first array.
 * @param arr2 Pointer to the second array of strings.
 * @param len2 Number of elements in the second array.
 * @return true if the arrays are equal, false otherwise.
 */
bool are_arrays_equal(const char **arr1, int len1, const char **arr2, int len2);

#endif