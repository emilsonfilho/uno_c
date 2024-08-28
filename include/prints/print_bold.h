#ifndef PRINT_BOLD_H
#define PRINT_BOLD_H

#include "stylized_print.h"

/**
 * Internal libs:
 * - stdio.h
 * - stdarg.h
*/

/**
 * Inherited internal libs:
 * - ansi.h
*/

/**
 * @brief Prints a message in bold style to the console.
 *
 * @param message The message to be printed in bold.
 */
void print_bold(char *message);

#endif