#include "../../include/screens/show_home_screen.h"

void show_home_screen()
{
    printf("Bem-vindo ao UNO_C!\n");
    printf("Pressione qualquer tecla para continuar!");

    getchar();

    transition(MAIN_MENU);
}