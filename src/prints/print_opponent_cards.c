#include "../../include/prints/print_opponent_cards.h"

void print_opponent_cards(int num_cards)
{
    char *opponent_hand = (char *)malloc((2 * num_cards + 3) * sizeof(char));
    int current_str_opponent_length = 0;

    strcpy(opponent_hand + current_str_opponent_length, "[ ");
    current_str_opponent_length += 2;

    for (int i = 0; i < num_cards; i++)
    {
        strcpy(opponent_hand + current_str_opponent_length, "x ");
        current_str_opponent_length += 2;
    }

    strcpy(opponent_hand + current_str_opponent_length, "]");
    current_str_opponent_length += 1;

    print_line_with_prefix("Oponente: ", opponent_hand, RESET);

    free(opponent_hand);
}