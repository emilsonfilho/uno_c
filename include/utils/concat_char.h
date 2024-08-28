#ifndef CONCAT_CHAR_H
#define CONCAT_CHAR_H

/**
 * Concatenates a single character to a given string.
 *
 * @param str       The original string to which the character will be appended.
 * @param str_size  Pointer to an integer storing the current size of the string `str`.
 * @return          A pointer to the updated string `str` with the appended character `ch`.
 *
 * @note It dynamically reallocates memory for the string to accommodate the new character.
 */
char *concat_char(char *str, int *str_size, char ch);

#endif