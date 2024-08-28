#include "../../include/utils/card_skip_next_player.h"

bool card_skip_next_player(Card card)
{
    return are_strings_equal(card.numberAction.action, "block") ||
           are_strings_equal(card.numberAction.action, "reverse") ||
           are_strings_equal(card.numberAction.action, "+2") ||
           are_strings_equal(card.numberAction.action, "+4");
}