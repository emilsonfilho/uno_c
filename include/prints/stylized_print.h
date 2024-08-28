#ifndef STYLIZED_PRINT_H
#define STYLIZED_PRINT_H

#include <stdio.h>
#include <stdarg.h>

#include "../configs/ansi.h"

/**
 * @brief Prints a stylized message to the console.
 *
 * This function prints a message with the specified styles applied.
 *
 * @param message The message to be printed.
 * @param n The number of style arguments provided.
 * @param ... The styles to be applied, passed as additional arguments.
 */
void stylized_print(char *message, int n, ...);

#endif