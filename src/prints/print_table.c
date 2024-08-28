#include "../../include/prints/print_table.h"

void print_table(Card top_card)
{
    print_line();

    char *color_card = get_color_name(top_card.color);
    char *ansi_color = get_color_ansi(top_card.color);

    int numberAction_length = 0;
    char *numberAction_str;

    if (top_card.isNumber)
    {
        numberAction_length = count_digits(top_card.numberAction.number);
        numberAction_str = int_to_string(top_card.numberAction.number);
    }
    else
    {
        numberAction_length = strlen(top_card.numberAction.action);
        numberAction_str = (char *)malloc((numberAction_length + 1) * sizeof(char));
        strncpy(numberAction_str, top_card.numberAction.action, numberAction_length);
        numberAction_str[numberAction_length] = '\0';
    }

    int card_string_length = strlen(color_card) + 1 + numberAction_length + 1;
    char *card_string = (char *)malloc(card_string_length + 1);
    sprintf(card_string, "%s %s", color_card, numberAction_str);

    print_line_with_prefix("Topo: ", card_string, ansi_color);

    print_line();

    free(numberAction_str);
    free(card_string);
}