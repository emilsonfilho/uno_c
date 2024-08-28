#include "../../include/mechanics/check_opponent_play.h"

void check_opponent_play(Card card, Color *chosen_color, bool opponent_played, bool *player_skip, Card **player_cards, int *num_player_cards, bool *player_draws, Card **opponent_cards, int *num_opponent_cards)
{
    if (opponent_played)
    {
        if (is_wild_card(card))
        {
            int random_color = random_array_index(4);
            *chosen_color = random_color;

            if (card_skip_next_player(card))
            {
                // The only card that can jump on WILD is +4
                add_cards_to_other_player(player_cards, num_player_cards, 4);
                *player_skip = true;
            }
        }
        else
        {
            *chosen_color = card.color;

            if (!card.isNumber)
            {
                if (card_skip_next_player(card))
                {
                    *player_skip = true;

                    if (is_colored_draw_card(card))
                    {
                        add_cards_to_other_player(player_cards, num_player_cards, 2);
                        *player_draws = true;
                    }
                }
            } else if (card.numberAction.number == 0) {
                reverse_hands(player_cards, num_player_cards, opponent_cards, num_opponent_cards);
            }
        }
    }
}