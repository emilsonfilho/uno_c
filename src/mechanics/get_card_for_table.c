#include "../../include/mechanics/get_card_for_table.h"

Card get_card_for_table()
{
    Card filtered[deck_size];
    int filtered_size = 0;

    for (int i = 0; i < deck_size; i++)
    {
        if (is_normal_card(deck[i]))
        {
            filtered[filtered_size++] = deck[i];
        }
    }

    if (filtered_size == 0)
    {
        printf("[ERROR]: Nenhuma carta correspondente.");
        exit(1);
    }

    int random_index = random_array_index(filtered_size);
    Card selected_card = filtered[random_index];

    // Tem que remover a carta da mesa do deck
    int corresponding_index = -1;
    for (int i = 0; i < deck_size; i++)
    {
        Card current_card = deck[i];

        if ((current_card.color == selected_card.color) && current_card.isNumber && (current_card.numberAction.number == selected_card.numberAction.number))
        {
            corresponding_index = i;
            break;
        }
    }

    if (corresponding_index == -1)
    {
        printf("[ERROR]: Índice correspondente não encontrado.");
        exit(1);
    }

    // Compaction & Left Shifting
    deck = compaction(deck, &deck_size, corresponding_index);

    return selected_card;
}