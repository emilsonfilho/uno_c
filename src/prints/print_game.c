#include "../../include/prints/print_game.h"

void print_game(char **messages, int messages_length, Card top_card, int num_opponent_cards, Card *player_cards, int num_player_cards)
{
    clear_screen();
    print_history(messages, messages_length);
    print_table(top_card);
    print_hands(num_opponent_cards, player_cards, num_player_cards);

    sleep_time(TRANSITION_TIME * 2);
}