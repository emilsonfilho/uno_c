#include "../../include/mechanics/play_card.h"

Card play_card(Card **cards, int *cards_size, Card *top_card, Color chosen_color, bool *player_played, bool player_skipped)
{
    bool was_valid_play = false, was_last_entry_invalid = false;
    int choice = 0;

    if (!player_skipped)
    {
        while (!was_valid_play)
        {
            printf("Qual carta você quer jogar? ");
            scanf("%d", &choice);

            if (choice < 1 || choice > *cards_size)
            {
                if (choice == -1)
                {
                    *cards = push_card(*cards, cards_size, draw_card());
                    *player_played = false;
                    return (Card){WILD, {.action = ""}, false};
                }

                handle_invalid_choice(&was_last_entry_invalid, "Esta carta não está na sua mão.");
            }
            else
            {
                Card chosen_card = (*cards)[choice - 1];
                if (can_play_card(chosen_card, *top_card, chosen_color))
                {
                    was_valid_play = true;
                }
                else
                {
                    handle_invalid_choice(&was_last_entry_invalid, "Essa carta não pode ser jogada.");
                }
            }
        };

        Card selected_card = (*cards)[choice - 1];
        *cards = compaction(*cards, cards_size, choice - 1);
        *player_played = true;
        return selected_card;
    }
    else
    {
        *player_played = false;

        return (Card){WILD, {.action = ""}, false};
    }
}