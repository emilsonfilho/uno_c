#include "../../include/prints/print_line.h"

void print_line()
{
    for (int i = 0; i < SCREEN_LENGTH; i++)
    {
        printf("*");
    }
    printf("\n");
}