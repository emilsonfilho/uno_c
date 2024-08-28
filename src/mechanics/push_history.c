#include "../../include/mechanics/push_history.h"

char **push_history(char **current_history, int *current_size, char *new_message)
{
    if (*current_size < 3)
    {
        current_history = (char **)realloc(current_history, (*current_size + 1) * sizeof(char *));

        if (current_history == NULL)
        {
            fprintf(stderr, "Erro ao alocar memória.\n");
            exit(1);
        }

        (*current_size)++;
    }
    else
    {
        for (int i = 0; i < *current_size; i++)
        {
            current_history[i] = current_history[i + 1];
        }
    }

    current_history[*current_size - 1] = (char *)malloc((strlen(new_message) + 1) * sizeof(char));

    if (current_history[*current_size - 1] == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }

    strcpy(current_history[*current_size - 1], new_message);
    current_history[*current_size - 1][strlen(new_message)] = '\0';

    return current_history;
}