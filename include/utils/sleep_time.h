#ifndef SLEEP_TIME_H
#define SLEEP_TIME_H

#include <unistd.h>

/**
 * @brief Pauses the program for a specified amount of time.
 *
 * This function pauses the execution of the program for the given number of milliseconds.
 *
 * @param milliseconds The amount of time to sleep, in milliseconds.
 *
 * @note This function uses `usleep`, which takes microseconds as its parameter.
 * Therefore, the input milliseconds are multiplied by 1000 to convert to microseconds.
 */
void sleep_time(int milliseconds);

#endif