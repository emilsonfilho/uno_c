#ifndef DELETE_LINES_BY_ERRORS_H
#define DELETE_LINES_BY_ERRORS_H

#include <stdbool.h>

#include "delete_last_line.h"

/**
 * Inherited libs:
 * - stdio.h
*/

/**
 * @brief Deletes lines from the console based on error status.
 * 
 * This function removes one or two lines from the console output depending on whether the last entry was invalid. 
 * If the last entry was invalid, it removes the most recent line (which typically contains the error message) 
 * and then deletes the line immediately before it.
 * 
 * @param was_last_entry_invalid A boolean flag indicating whether the last entry was invalid. 
 *                               If `true`, the most recent line is removed before deleting the next line.
 */
void delete_lines_by_errors(bool was_last_entry_invalid);

#endif