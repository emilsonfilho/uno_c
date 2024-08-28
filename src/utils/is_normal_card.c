#include "../../include/utils/is_normal_card.h"

bool is_normal_card(Card card)
{
    return (card.color != WILD && card.isNumber == true && 0 <= card.numberAction.number && card.numberAction.number < 10);
}