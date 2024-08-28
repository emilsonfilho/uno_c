#include "../../include/prints/print_history.h"

void print_history(char **messages, int messages_length)
{
    messages = reverse(messages, messages_length);

    print_line();

    for (int i = 2; i >= 0; i--)
    {
        if (i <= messages_length - 1)
        {
            print_line_with_prefix("", messages[i], RESET);
        }
        else
        {
            print_line_with_prefix("", "", RESET);
        }
    }

    print_line();
}