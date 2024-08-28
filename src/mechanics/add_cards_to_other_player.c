#include "../../include/mechanics/add_cards_to_ther_player.h"

void add_cards_to_other_player(Card **cards, int *num_cards, int num_cards_to_add)
{
    for (int i = 0; i < num_cards_to_add; i++)
    {
        *cards = push_card(*cards, num_cards, draw_card());
    }
}