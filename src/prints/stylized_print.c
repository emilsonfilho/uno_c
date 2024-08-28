#include "../../include/prints/stylized_print.h"

void stylized_print(char *message, int n, ...)
{
    va_list list;
    va_start(list, n);
    for (int i = 0; i < n; i++)
    {
        char *arg = va_arg(list, char *);
        printf("%s", arg);
    }
    printf("%s" RESET, message);

    va_end(list);
}