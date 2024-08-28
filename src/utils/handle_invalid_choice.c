#include "../../include/utils/handle_invalid_choice.h"

void handle_invalid_choice(bool *was_last_entry_invalid, char *message)
{
    delete_lines_by_errors(*was_last_entry_invalid);
    *was_last_entry_invalid = true;
    printf("%s\n", message);
}