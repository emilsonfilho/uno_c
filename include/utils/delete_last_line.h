#ifndef DELETE_LAST_LINE_H
#define DELETE_LAST_LINE_H

#include <stdio.h>

/**
 * @brief Deletes the last printed line in the console output.
 * 
 * This function removes the most recently printed line from the console by 
 * moving the cursor up one line and clearing that line. 
 * This is useful for updating or removing lines in a dynamic text-based user interface.
 */
void delete_last_line();

#endif