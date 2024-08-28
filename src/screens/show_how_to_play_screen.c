#include "../../include/screens/show_how_to_play_screen.h"

void show_how_to_play_screen()
{
    clear_input_buffer();

    print_bold("Como jogar:\n");
    printf("1. Para jogar qualquer carta, digite o número correspondente ao índice da carta\n");
    printf("2. Para puxar uma carta, digite 0\n");
    printf("3. Para dizer uno, insira \"uno\" logo após o índice escolhido\n");

    printf("Pressione qualquer tecla para voltar ao menu principal\n");

    getchar();

    transition(MAIN_MENU);
}