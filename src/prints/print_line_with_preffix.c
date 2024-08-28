#include "../../include/prints/print_line_with_preffix.h"

void print_line_with_prefix(char *prefix, const char *color_card, const char *ansi_color)
{
    int prefix_len = strlen(prefix);
    int card_len = color_card != NULL ? strlen(color_card) : 0;

    for (int j = 0; j < SCREEN_LENGTH; j++)
    {
        if (j == 0 || j == SCREEN_LENGTH - 1)
        {
            printf("*");
            if (j == SCREEN_LENGTH - 1)
            {
                printf("\n");
            }
        }
        else if (j == 1 || j == SCREEN_LENGTH - 2)
        {
            printf(" ");
        }
        else
        {
            if (j - 2 < prefix_len)
            {
                printf("%c", prefix[j - 2]);
            }
            else if (color_card != NULL && j - 2 < prefix_len + card_len)
            {
                printf("%s%c%s", ansi_color, color_card[j - 2 - prefix_len], RESET);
            }
            else
            {
                printf(" ");
            }
        }
    }
}