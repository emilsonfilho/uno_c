#include "../../include/prints/print_player_cards.h"

void print_player_cards(Card *cards, int num_cards)
{
    for (int i = 0; i < num_cards; i++)
    {
        // String to each player card
        int card_index = i + 1;
        int digits = count_digits(card_index);
        int color_length = strlen(color_mapper[cards[i].color]);
        int current_str_player_length = 0;
        int number_action_length = 0;

        char card_index_str[digits + 1];

        Card current_player_card = cards[i];

        number_action_length = current_player_card.isNumber ? 1 : strlen(current_player_card.numberAction.action);

        char *number_str = int_to_string(current_player_card.numberAction.number);
        /*
         * Example: "Vermelho 9\0" = 11
         * = [color.length] + 1 + [numberAction.length] + 1
         * = [color.length] + [numberAction.length] + 2
         */
        char *current_card = (char *)malloc((color_length + number_action_length + 2) * sizeof(char));

        current_card = concat_string(current_card, &current_str_player_length, color_mapper[current_player_card.color]);

        current_card = concat_char(current_card, &current_str_player_length, ' ');

        if (current_player_card.isNumber)
        {
            current_card = concat_string(current_card, &current_str_player_length, number_str);
        }
        else
        {
            current_card = concat_string(current_card, &current_str_player_length, current_player_card.numberAction.action);
        }

        char *preffix = int_between_parenthesis(card_index);
        print_line_with_prefix(preffix, current_card, get_color_ansi(current_player_card.color));

        free(current_card);
        free(number_str);
    }
}