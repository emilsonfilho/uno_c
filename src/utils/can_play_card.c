#include "../../include/utils/can_play_card.h"

bool can_play_card(Card chosen, Card top_card, Color chosen_color)
{
    if (
        is_color_match(chosen, top_card) ||
        is_number_match(chosen, top_card) ||
        is_action_match(chosen, top_card) ||
        is_wild_card(chosen) ||
        (is_wild_card(top_card) && chosen.color == chosen_color))
    {
        return true;
    }

    return false;
}