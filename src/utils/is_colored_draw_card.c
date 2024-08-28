#include "../../include/utils/is_colored_draw_card.h"

bool is_colored_draw_card(Card card)
{
    return !card.isNumber && are_strings_equal(card.numberAction.action, "+2");
}