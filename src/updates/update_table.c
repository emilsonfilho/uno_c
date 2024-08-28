#include "../../include/updates/update_table.h"

void update_table(Card *current, Card new_card, bool played)
{
    if (played)
        *current = new_card;
}