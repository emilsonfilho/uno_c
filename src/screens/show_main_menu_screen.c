#include "../../include/screens/show_main_menu_screen.h"

void show_main_menu_screen()
{
    int choise;

    printf("Bem-vindo ao UNO_C!\n");
    printf("1. Iniciar novo jogo\n");
    printf("2. Regras do jogo\n");
    printf("3. Como jogar\n");
    printf("4. Sair\n");

    scanf("%d", &choise);

    switch (choise)
    {
    case 1:
        transition(NEW_GAME);
        break;
    case 2:
        transition(RULES);
        break;
    case 3:
        transition(HOW_TO_PLAY);
        break;
    case 4:
        transition(EXIT);
        break;
    default:
        transition(MAIN_MENU);
        break;
    }
}