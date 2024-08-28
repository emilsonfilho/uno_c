#ifndef IS_IN_INTERVAL_H
#define IS_IN_INTERVAL_H

#include <stdbool.h>

/**
 * @brief Checks if a number is within a specified interval.
 *
 * @param number The integer to be checked.
 * @param min The lower bound of the interval (inclusive).
 * @param max The upper bound of the interval (inclusive).
 *
 * @return `true` if the number is within the interval `[min, max]`, otherwise `false`.
 */
bool is_in_interval(int number, int min, int max);

#endif