#include "../../include/prints/print_hands.h"

void print_hands(int num_opponent_cards, Card *player_cards, int num_player_cards)
{
    // opponent hand
    print_line();

    print_opponent_cards(num_opponent_cards);
    print_player_cards(player_cards, num_player_cards);

    print_line();
}