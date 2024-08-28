#include "../../include/utils/delete_lines_by_errors.h"

void delete_lines_by_errors(bool was_last_entry_invalid)
{
    if (was_last_entry_invalid)
        delete_last_line();
    delete_last_line();
}