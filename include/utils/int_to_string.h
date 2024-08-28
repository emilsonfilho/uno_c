#ifndef INT_TO_STRING_H
#define INT_TO_STRING_H

#include <stdio.h>
#include <stdlib.h>

#include "count_digits.h"

/**
 * Converts an integer to a string representation.
 *
 * @param number The integer to be converted to a string.
 * @param str    A character array where the resulting string will be stored.
 *               The array must have enough space to store the string representation
 *               of the integer plus the null-terminator.
 * @return       A pointer to the character array `str` containing the string
 *               representation of the integer.
 */
char *int_to_string(int number);

#endif