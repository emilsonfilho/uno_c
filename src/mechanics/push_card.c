#include "../../include/mechanics/push_card.h"

Card *push_card(Card *cards, int *size, Card new_card)
{
    Card *temp = realloc(cards, (*size + 1) * sizeof(Card));

    if (temp == NULL)
    {
        printf("Error allocating memory.\n");
        exit(1);
    }

    temp[*size] = new_card;
    (*size)++;

    sort_cards(temp, *size);

    return temp;
}