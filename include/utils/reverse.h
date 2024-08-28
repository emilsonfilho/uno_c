#ifndef REVERSE_H
#define REVERSE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Reverses the order of strings in an array.
 *
 * If the input array is NULL or the length is zero,
 * the function returns NULL.
 *
 * @param arr The array of strings to be reversed.
 * @param len The number of elements in the array.
 * @return A new array of strings in reverse order.
 *
 * @note The caller is responsible for
 * freeing the memory allocated for the returned array.
 */
char **reverse(char **arr, int len);

#endif