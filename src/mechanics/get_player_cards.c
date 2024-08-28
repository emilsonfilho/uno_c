#include "../../include/mechanics/get_player_cards.h"

Card *get_player_cards()
{
    Card *player_cards = (Card *)malloc(INITIAL_NUMBER_CARDS * sizeof(Card));

    if (player_cards == NULL)
    {
        printf("Erro ao alocar memória.");
        exit(1);
    }

    for (int i = 0; i < INITIAL_NUMBER_CARDS; i++)
    {
        int random_index = random_array_index(deck_size);
        player_cards[i] = deck[random_index];
        deck = compaction(deck, &deck_size, random_index);
    }

    return player_cards;
}