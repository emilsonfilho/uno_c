#include "../../include/screens/show_game_screen.h"

void show_game_screen(char ***history, int *history_size, Card *player_cards, int *num_player_cards, Card *opponent_cards, int *num_opponent_cards, Card *top_card, Color *chosen_color, bool *player_skipped, bool *opponent_skipped, bool *player_drawed, bool *opponent_drawed)
{
    print_game(*history, *history_size, *top_card, *num_opponent_cards, player_cards, *num_player_cards);

    bool player_played = true;
    Card played_card = play_card(&player_cards, num_player_cards, top_card, *chosen_color, &player_played, *player_skipped);
    check_play(played_card, chosen_color, player_played, opponent_skipped, &opponent_cards, num_opponent_cards, opponent_drawed, &player_cards, num_player_cards);
    update_table(top_card, played_card, player_played);
    update_history(*top_card, *chosen_color, history, history_size, true, player_played, *player_skipped, *player_drawed);
    *player_skipped = false;
    *player_drawed = false;

    check_winner(*num_player_cards, true);
    sleep_time(1000);

    bool opponent_played = false;
    Card opponent_played_card = opponent_play(&opponent_cards, num_opponent_cards, *top_card, *chosen_color, &opponent_played, *opponent_skipped);
    check_opponent_play(opponent_played_card, chosen_color, opponent_played, player_skipped, &player_cards, num_player_cards, player_drawed, &opponent_cards, num_opponent_cards);
    update_table(top_card, opponent_played_card, opponent_played);
    update_history(*top_card, *chosen_color, history, history_size, false, opponent_played, *opponent_skipped, *opponent_drawed);
    *opponent_skipped = false;
    *opponent_drawed = false;

    check_winner(*num_opponent_cards, false);
    sleep_time(1000);

    show_game_screen(history, history_size, player_cards, num_player_cards, opponent_cards, num_opponent_cards, top_card, chosen_color, player_skipped, opponent_skipped, player_drawed, opponent_drawed);

    getchar();
}