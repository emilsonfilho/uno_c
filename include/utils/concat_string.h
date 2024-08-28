#ifndef CONCAT_STRING_H
#define CONCAT_STRING_H

#include <string.h>

/**
 * Concatenates a suffix string to a given string.
 *
 * This function appends the string `suffix` to the end of the string `str`.
 *
 * @param str       The original string to which the suffix will be appended.
 * @param str_size  Pointer to an integer storing the current size of the string `str`.
 * @return          A pointer to the updated string `str` with the appended suffix.
 *
 * @note It dynamically reallocates memory for the string to accommodate the new suffix.
 */
char *concat_string(char *str, int *str_size, char *suffix);

#endif