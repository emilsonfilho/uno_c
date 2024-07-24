#ifndef PRINTS_H
#define PRINTS_H

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

/**
 * @brief Prints a message in bold style to the console.
 *
 * @param message The message to be printed in bold.
 */
void print_bold(char *message);

#endif // PRINTS_H
