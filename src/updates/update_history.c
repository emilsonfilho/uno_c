#include "../../include/updates/update_history.h"

void update_history(Card top_card, Color chosen_color, char ***history, int *history_size, bool is_player, bool played, bool skipped, bool drawed)
{
    if (played)
    {
        char *played_message = is_player ? "Voce jogou uma carta" : "Oponente jogou uma carta";
        *history = push_history(*history, history_size, played_message);

        if (is_wild_card(top_card))
        {
            char *preffix = is_player ? "Voce escolheu a cor:" : "Oponente escolheu a cor:";
            char *color_name = get_color_name(chosen_color);
            int message_size = strlen(preffix) + strlen(color_name) + 2;
            char *message = malloc(message_size * sizeof(char));
            sprintf(message, "%s %s", preffix, color_name);

            *history = push_history(*history, history_size, message);

            free(message);
        }
    }
    else if (skipped)
    {
        if (drawed)
        {
            char *message = is_player ? "Voce puxou cartas" : "Oponente puxou cartas";
            *history = push_history(*history, history_size, message);
        }
        else
        {
            char *message = is_player ? "Voce foi bloqueado" : "Oponente foi bloqueado";
            *history = push_history(*history, history_size, message);
        }
    }
    else
    {
        char *message = is_player ? "Voce puxou uma carta" : "Oponente puxou uma carta";
        *history = push_history(*history, history_size, message);
    }
}