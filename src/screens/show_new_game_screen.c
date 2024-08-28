#include "../../include/screens/show_new_game_screen.h"

void show_new_game_screen()
{
    clear_input_buffer();

    bool player_skipped = false, opponent_skipped = false, player_drawed = false, opponent_drawed = false;
    char **history = NULL;
    int history_size = 0, num_cards_player = INITIAL_NUMBER_CARDS, num_cards_opponent = INITIAL_NUMBER_CARDS;
    Card *player_cards = get_player_cards();
    Card *opponent_cards = get_player_cards();
    Card top_card = get_card_for_table();
    Color chosen_color = top_card.color;
    sort_cards(player_cards, INITIAL_NUMBER_CARDS);

    history = push_history(history, &history_size, "Pegando carta inicial...");

    print_game(history, history_size, top_card, 0, player_cards, 0);

    history = push_history(history, &history_size, "Distribuindo cartas...");

    for (int i = 0; i <= INITIAL_NUMBER_CARDS; i++)
    {
        print_game(history, history_size, top_card, i, player_cards, i);
    }

    show_game_screen(&history, &history_size, player_cards, &num_cards_player, opponent_cards, &num_cards_opponent, &top_card, &chosen_color, &player_skipped, &opponent_skipped, &player_drawed, &opponent_drawed);

    free(history);
    free(player_cards);
}