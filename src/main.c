#include "../include/tests/run_tests.h"

#include "../include/inits/initialize_random.h"

#include "../include/screens/show_home_screen.h"
#include "../include/screens/show_main_menu_screen.h"
#include "../include/screens/show_new_game_screen.h"
#include "../include/screens/show_rules_screen.h"
#include "../include/screens/show_how_to_play_screen.h"

/**
 * Inherited libs: 
 * - stdio.h
 * - stdbool.h
 * - stdlib.h
 * - string.h
 * - time.h
 * - unistd.h
 * - stdarg.
*/

/**
 * Inherited internal libs: 
 * - types.h
 * - screens.h
 * - general.h
 * - copy_action.h
 * - is_invalid_color.h
 * - count_digits.h
 * - swap.h
 * - compare_cards.h
 * - is_color_match.h
 * - is_number_match.h
 * - is_action_match.h
 * - is_wild_card.h
 * - global.h
 * - is_normal_card.h
 * - random_array_index.h
 * - compaction.h
 * - sort_cards.h
 * - are_strings_equal.h
 * - ansi.h
 * - are_card_arrays_equal.h
 * - are_arrays_equal.h
 * - create_deck.h
 * - get_color_name.h
 * - get_color_ansi.h
 * - reverse.h
 * - str_compaction.h
 * - int_to_string.h
 * - concat_char.h
 * - concat_string.h
 * - int_between_parenthesis.h
 * - is_in_interval.h
 * - can_play_card.h
 * - get_card_for_table.h
 * - push_history.h
 * - push_card.h
 * - show_card_error_message.h
 * - show_tests_error_message.h
 * - tests.h
 * - transition.h
 * - clear_screen.h
 * - sleep_time.h
 * - global.h
 * - general.h
 * - print_bold.h
 * - stylized_print.h
*/

int main()
{
    initialize_random();
    run_tests();

    deck = create_deck();
    deck_size = MAX_CARDS;

    while (state != EXIT)
    {
        switch (state)
        {
        case HOME:
            show_home_screen();
            break;
        case MAIN_MENU:
            show_main_menu_screen();
            break;
        case NEW_GAME:
            show_new_game_screen();
            break;
        case RULES:
            show_rules_screen();
            break;
        case HOW_TO_PLAY:
            show_how_to_play_screen();
            break;
        }
    }

    free(deck);

    printf("Obrigado por jogar!\n");

    return 0;
}