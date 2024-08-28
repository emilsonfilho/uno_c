#include "../../include/prints/print_bold.h"

void print_bold(char *message)
{
    stylized_print(message, 1, BOLD);
}