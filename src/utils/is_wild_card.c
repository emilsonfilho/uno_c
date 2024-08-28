#include "../../include/utils/is_wild_card.h"

bool is_wild_card(Card card)
{
    return card.color == WILD;
}