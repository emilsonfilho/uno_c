#include "../../include/mechanics/check_play.h"

void check_play(Card card, Color *chosen_color, bool player_played, bool *opponent_skip, Card **opponent_cards, int *num_opponent_cards, bool *opponent_draws, Card **player_cards, int *num_player_cards)
{
    if (player_played)
    {
        if (is_wild_card(card))
        {
            bool was_last_entry_invalid = false, was_valid_play = false;
            int selected_color = 0;

            while (!was_valid_play)
            {
                printf("Qual cor você escolhe?\n");
                printf("%s %s%s%s\n", "[1]", ANSI_RED, "Vermelho", RESET);
                printf("%s %s%s%s\n", "[2]", ANSI_GREEN, "Verde", RESET);
                printf("%s %s%s%s\n", "[3]", ANSI_BLUE, "Azul", RESET);
                printf("%s %s%s%s\n", "[4]", ANSI_YELLOW, "Amarelo", RESET);
                scanf("%d", &selected_color);

                if (is_in_interval(selected_color, 1, 4))
                {
                    *chosen_color = (Color)(selected_color - 1);
                    was_valid_play = true;

                    // The card can be +4 (which skips the next move)
                    if (card_skip_next_player(card))
                    {
                        add_cards_to_other_player(opponent_cards, num_opponent_cards, 4);
                        *opponent_skip = true;
                    }
                }
                else
                {
                    handle_invalid_choice(&was_last_entry_invalid, "Essa não é uma cor válida!");
                }
            }
        }
        else
        {
            // If it's not a special card, the color chosen is the same as the card
            *chosen_color = card.color;

            if (!card.isNumber)
            {
                if (card_skip_next_player(card))
                {
                    *opponent_skip = true;

                    if (is_colored_draw_card(card))
                    {
                        add_cards_to_other_player(opponent_cards, num_opponent_cards, 2);
                        *opponent_draws = true;
                    }
                }
            }
            else if (card.numberAction.number == 0)
            {
                // Change the players' hands
                reverse_hands(player_cards, num_player_cards, opponent_cards, num_opponent_cards);
            }
        }
    }
}