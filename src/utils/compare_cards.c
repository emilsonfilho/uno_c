#include "../../include/utils/compare_cards.h"

int compare_cards(Card card1, Card card2)
{
    if (card1.isNumber && card2.isNumber)
    {
        return card1.numberAction.number - card2.numberAction.number;
    }
    else if (!card1.isNumber && !card2.isNumber)
    {
        return strcmp(card1.numberAction.action, card2.numberAction.action);
    }
    else
    {
        return card2.isNumber - card1.isNumber;
    }
}