#include "../../include/mechanics/opponent_play.h"

Card opponent_play(Card **cards, int *num_cards, Card top_card, Color chosen_color, bool *opponent_played, bool opponent_skipped)
{

    if (!opponent_skipped)
    {
        for (int i = 0; i < *num_cards; i++)
        {
            Card current_card = (*cards)[i];
            if (can_play_card(current_card, top_card, chosen_color))
            {
                *cards = compaction(*cards, num_cards, i);
                *opponent_played = true;
                return current_card;

                // Make if statement for when the card to skip the next move
            }
        }

        *cards = push_card(*cards, num_cards, draw_card());
    }

    *opponent_played = false;
    return (Card){WILD, {.action = ""}, false};
}