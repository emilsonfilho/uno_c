#include "../../include/screens/transition.h"

void transition(int next_screen)
{
    clear_screen();
    sleep_time(TRANSITION_TIME);
    state = next_screen;
}