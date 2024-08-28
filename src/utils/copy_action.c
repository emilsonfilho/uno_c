#include "../../include/utils/copy_action.h"

void copy_action(Card *last_card, const char *action)
{
    size_t action_buffer_size = sizeof((*last_card).numberAction.action);
    strncpy((*last_card).numberAction.action, action, action_buffer_size);
}