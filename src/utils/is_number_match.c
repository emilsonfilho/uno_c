#include "../../include/utils/is_number_match.h"

bool is_number_match(Card card1, Card card2)
{
    return card1.isNumber && card2.isNumber && card1.numberAction.number == card2.numberAction.number;
}