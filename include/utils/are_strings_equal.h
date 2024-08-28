#ifndef ARE_STRINGS_EQUAL_H
#define ARE_STRINGS_EQUAL_H

#include <stdbool.h>
#include <string.h>

/**
 * @brief Compares two strings for equality.
 *
 * This function checks if two strings are identical by comparing them.
 * It returns `true` if the strings are equal and `false` otherwise.
 *
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 *
 * @return `true` if the strings are equal; `false` otherwise.
 */

bool are_strings_equal(char *str1, char *str2);

#endif