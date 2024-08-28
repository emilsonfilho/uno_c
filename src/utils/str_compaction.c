#include "../../include/utils/str_compaction.h"

char **str_compaction(char **arr, int *arr_size, int hole)
{
    if (hole < 0 || hole >= *arr_size)
    {
        return arr; // Retorna o ponteiro original se o índice do buraco for inválido.
    }

    int new_size = *arr_size - 1;

    // Desalocar a string na posição 'hole'
    free(arr[hole]);

    for (int i = hole; i < new_size; i++)
    {
        arr[i] = arr[i + 1];
    }

    // Realocar o array de ponteiros
    char **temp = (char **)realloc(arr, new_size * sizeof(char *));

    if (temp == NULL && new_size > 0)
    {
        printf("[ERROR]: Falha ao realocar memória.\n");
        exit(1);
    }

    *arr_size = new_size;
    return temp;
}