#include "../../include/screens/show_rules_screen.h"

void show_rules_screen()
{
    clear_input_buffer();

    print_bold("Regras do jogo:\n");
    printf("1. Cada jogador recebe 7 cartas\n");
    printf("2. O objetivo é ser o primeiro a descartar todas as cartas\n");
    printf("3. Cartas só podem ser jogadas se tiverem a mesma cor, o mesmo número ou se forem cartas especiais\n");
    printf("4. Cartas especiais têm efeitos diferentes (bloquear, reverter, comprar duas, comprar quatro e trocar cor)\n");
    printf("5. Cartas de número 0 troca as mãos dos jogadores\n");
    printf("6. Ao querer jogar uma penúltima carta da sua mão, diga UNO\n");
    printf("7. Se a regra 6 for desobedecida, você compra duas cartas obrigatoriamente\n");
    printf("8. Caso não tenha cartas possíveis de serem jogadas na mão, compre uma carta\n");

    printf("Pressione qualquer tecla para voltar ao menu principal\n");

    getchar();

    transition(MAIN_MENU);
}