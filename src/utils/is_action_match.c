#include "../../include/utils/is_action_match.h"

bool is_action_match(Card card1, Card card2)
{
    return !card1.isNumber && !card2.isNumber && are_strings_equal(card1.numberAction.action, card2.numberAction.action);
}