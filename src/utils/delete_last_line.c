#include "../../include/utils/delete_last_line.h"

void delete_last_line()
{
    printf("\033[F");
    printf("\033[K");
}