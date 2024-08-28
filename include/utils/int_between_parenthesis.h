#ifndef INT_BETWEEN_PARENTHESIS_H
#define INT_BETWEEN_PARENTHESIS_H

#include <stdio.h>
#include <stdlib.h>

#include "count_digits.h"

/**
 * Converts an integer to a string surrounded by parentheses.
 *
 * @param number The integer to be converted and enclosed in parentheses.
 * @return       A pointer to a newly allocated string containing the integer `number`
 *               enclosed in parentheses. The caller is responsible for freeing this
 *               memory when no longer needed.
 *
 * @note It dynamically allocates memory for the resulting string.
 */
char *int_between_parenthesis(int number);

#endif