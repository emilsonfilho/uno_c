#include "../../include/mechanics/play_again_choose.h"

void play_again_choose()
{
    clear_input_buffer();

    // ...
    bool was_valid_choice = false, was_last_entry_invalid = false;
    char choice = ' ';

    while (!was_valid_choice) {
        printf("Deseja jogar novamente? [s/n] ");
        scanf(" %c", &choice);

        if (choice == 'S' || choice == 's' || choice == 'N' || choice == 'n') {
            if (choice == 'S' || choice == 's') {
                show_new_game_screen();
            } else {
                printf("Foi um prazer te ter como player! :)\n");
                exit(1);
            }
        } else {
            handle_invalid_choice(&was_last_entry_invalid, "Essa opção não é válida!");
        }
    }
}