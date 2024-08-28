#include "../../include/mechanics/check_winner.h"

void check_winner(int num_cards, bool is_player)
{
    if (num_cards == 0)
    {
        printf("%s\n", is_player ? "Parabens! Voce ganhou" : "Voce perdeu...");
        play_again_choose();
    }
}