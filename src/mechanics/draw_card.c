#include "../../include/mechanics/draw_card.h"

Card draw_card()
{
    int random_index = random_array_index(deck_size);

    Card random_card = deck[random_index];

    deck = compaction(deck, &deck_size, random_index);

    return random_card;
}