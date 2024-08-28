#include "../../include/utils/sleep_time.h"

void sleep_time(int milliseconds)
{
    usleep(milliseconds * 100);
}