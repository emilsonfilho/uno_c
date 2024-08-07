#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define TEST_ASSERT_EQUAL(expected, actual, test_num)                                             \
    if ((expected) != (actual))                                                                   \
    {                                                                                             \
        printf("ERROR: Teste %d falhou. Esperado: %d, Obtido: %d\n", test_num, expected, actual); \
        exit(1);                                                                                  \
    }

#define TEST_ASSERT_EQUAL_PTR(expected, actual, test_num)                                         \
    if (expected != actual)                                                                       \
    {                                                                                             \
        printf("ERROR: Teste %d falhou. Esperado: %p, Obtido: %p\n", test_num, expected, actual); \
        exit(1);                                                                                  \
    }                                                                                             \

#define TEST_ASSERT_EQUAL_STR(expected, actual, test_num)                                                 \
    if (strcmp(expected, actual) != 0)                                                                    \
    {                                                                                                     \
        printf("ERROR: Teste %d falhou. Esperado: \"%s\", Obtido: \"%s\"\n", test_num, expected, actual); \
        exit(1);                                                                                          \
    }
   
#define TEST_ASSERT_ARRAYS_EQUAL(expected, expected_len, actual, actual_len, test_num)                     \
    if (!are_arrays_equal(expected, expected_len, actual, actual_len))                                     \
    {                                                                                                      \
        printf("ERROR: Teste %d falhou. Arrays não são iguais.\n", test_num);                              \
        exit(1);                                                                                           \
    }    

#define TEST_ASSERT_CARD_ARRAYS_EQUAL(expected, expected_len, actual, actual_len, test_num)                     \
    if (!are_card_arrays_equal(expected, expected_len, actual, actual_len))                                     \
    {                                                                                                      \
        printf("ERROR: Teste %d falhou. Arrays não são iguais.\n", test_num);                              \
        exit(1);                                                                                           \
    }    

#define MAX_CARDS 108
#define TRANSITION_TIME 1000
#define SCREEN_LENGTH 40
#define INITIAL_NUMBER_CARDS 7

#define HOME 0
#define MAIN_MENU 1
#define NEW_GAME 2
#define RULES 3
#define HOW_TO_PLAY 4
#define EXIT 99

// Definições de cores ANSI
#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"
#define ITALIC "\x1b[3m"
#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define WHITE "\x1b[37m"

typedef enum
{
    RED,
    GREEN,
    BLUE,
    YELLOW,
    WILD,
} Color;

typedef union
{
    unsigned int number;
    char action[8];
} NumberAction;

typedef struct
{
    Color color;
    NumberAction numberAction;
    bool isNumber;
} Card;

char *color_mapper[] = {
    "Vermelho",
    "Verde",
    "Azul",
    "Amarelo",
    "Especial"};

/**
 * @brief Creates and initializes a deck of cards.
 *
 * This function creates a standard deck of cards used in a game.
 * The deck includes number cards (0-9) in four colors (RED, BLUE, GREEN, YELLOW),
 * special action cards in those colors (block, reverse, +2), and special action
 * cards without a color (change, +4).
 *
 * @return A pointer to the created deck of cards.
 *
 * The deck contains the following:
 * - For each color (RED, BLUE, GREEN, YELLOW):
 *   - One card of number 0.
 *   - Two sets of cards numbered 1 to 9.
 *   - Two sets of special action cards (block, reverse, +2).
 * - Two special action cards without a color (change, +4).
 */
Card *create_deck();

/**
 * @brief Copies an action string into a card's action field.
 *
 * This function copies the specified action string into the action field
 * of the given card.
 *
 * @param last_card Pointer to the card whose action field is to be set.
 * @param action The action string to be copied.
 */
void copy_action(Card *last_card, const char *action);

/**
 * @brief Runs a series of unit tests for the program.
 *
 * This function performs unit tests on various functions within the program.
 * It measures the time taken to run the tests and outputs the results. The
 * current implementation includes tests for the following:
 *
 * - Function `create_deck`: Tests if the created deck of cards matches the
 *   expected deck configuration.
 *
 * Any errors detected during the tests will trigger an error message using
 * `show_card_error_message`, which will indicate discrepancies between the
 * expected and actual card properties.
 */
void run_tests();

/**
 * @brief Displays an error message for a card mismatch and terminates the program.
 *
 * This function prints an error message indicating that there was a mismatch
 * between the expected and actual card properties. It outputs the expected
 * card properties and the actual card properties that caused the error.
 *
 * @param error_message A descriptive error message explaining the type of mismatch.
 * @param card_expected The expected card properties.
 * @param card_result The actual card properties that caused the error.
 */
void show_card_error_message(const char *error_message, const Card card_expected, const Card card_result);

/**
 * @brief Clears the console screen.
 *
 * This function clears the console screen, providing a clean slate for output.
 * It determines the appropriate system command based on the operating system.
 */
void clear_screen();

/**
 * @brief Displays the home screen of the UNO_C program.
 *
 * This function presents the user with a welcome message.
 * After a key is pressed, it transitions the program to the
 * main menu.
 */
void show_home_screen();

/**
 * @brief Displays the main menu screen of the UNO_C program.
 *
 * This function presents the user with a list of options to choose from the main menu.
 * The options are:
 * 1. Iniciar novo jogo
 * 2. Regras do jogo
 * 3. Como jogar
 * 4. Sair
 *
 * The user's choice is read and the program transitions to the corresponding state.
 */
void show_main_menu_screen();

void show_new_game_screen();

/**
 * @brief Displays the rules screen of the UNO_C program.
 *
 * This function shows the rules of the game to the user. The rules include:
 * 1. Each player receives 7 cards.
 * 2. The objective is to be the first to discard all cards.
 * 3. Cards can only be played if they match the color, number, or are special cards.
 * 4. Special cards have different effects (block, reverse, draw two, draw four, and change color).
 * 5. Number 0 cards swap players' hands.
 * 6. When playing the second-to-last card, say "UNO".
 * 7. If rule 6 is violated, you must draw two cards.
 * 8. If no playable card is available, draw a card.
 *
 * The user is prompted to press any key to return to the main menu.
 */
void show_rules_screen();

/**
 * @brief Displays the "How to Play" screen of the UNO_C program.
 *
 * This function provides instructions on how to play the game. The instructions include:
 * 1. To play any card, enter the number corresponding to the card's index.
 * 2. To draw a card, enter 0.
 * 3. To say "UNO", type "uno" immediately after choosing the card index.
 *
 * The user is prompted to press any key to return to the main menu.
 */
void show_how_to_play_screen();

/**
 * @brief Clears the input buffer.
 *
 * This function discards any remaining characters in the input buffer until a newline
 * character or the end-of-file (EOF) is encountered.
 */
void clear_input_buffer();

/**
 * @brief Pauses the program for a specified amount of time.
 *
 * This function pauses the execution of the program for the given number of milliseconds.
 *
 * @param milliseconds The amount of time to sleep, in milliseconds.
 *
 * @note This function uses `usleep`, which takes microseconds as its parameter.
 * Therefore, the input milliseconds are multiplied by 1000 to convert to microseconds.
 */
void sleep_time(int milliseconds);

/**
 * @brief Transitions to the specified screen with a delay.
 *
 * @param next_screen The identifier of the screen to transition to.
 */
void transition(int next_screen);

/**
 * @brief Prints a stylized message to the console.
 *
 * This function prints a message with the specified styles applied.
 *
 * @param message The message to be printed.
 * @param n The number of style arguments provided.
 * @param ... The styles to be applied, passed as additional arguments.
 */
void stylized_print(char *message, int n, ...);

/**
 * @brief Prints a message in bold style to the console.
 *
 * @param message The message to be printed in bold.
 */
void print_bold(char *message);

void print_arr(Card *arr, int size);
void print_game(char **messages, int messages_length, Card top_card, int num_oponent_cards, Card *player_cards, int num_player_cards);
void print_history(char **messages, int messages_length);
void print_table(Card top_card);
void print_line();

/**
 * @brief Reverses the order of strings in an array.
 *
 * If the input array is NULL or the length is zero,
 * the function returns NULL.
 *
 * @param arr The array of strings to be reversed.
 * @param len The number of elements in the array.
 * @return A new array of strings in reverse order.
 *
 * @note The caller is responsible for
 * freeing the memory allocated for the returned array.
 */
char **reverse(char **arr, int len);

/**
 * @brief Retrieves a random normal card from the deck and removes it from the deck.
 *
 * @return The selected card that is removed from the deck.
 *
 * @note If no matching card is found, the function terminates with an error message.
 */

Card get_card_for_table();

/**
 * @brief Retrieves the name associated with the given color.
 *
 * @param color The enum value representing the color.
 * @return A string representing the name of the color.
 *
 * @note If the color is not valid (as determined by is_invalid_color), it returns "Invalid".
 */
char *get_color_name(Color color);

/**
 * @brief Retrieves the ANSI escape code associated with the given color.
 *
 * @param color The enumeration value representing the color.
 * @return A string containing the ANSI escape code for the color, or the ANSI reset code if the color is invalid.
 */
char *get_color_ansi(Color color);

/**
 * @brief Checks if the given card is a normal playing card.
 *
 * This function evaluates whether the provided card is a normal playing card
 * by verifying that its color is not WILD and its number attribute is true.
 *
 * @param card The card structure to be evaluated.
 * @return true if the card is a normal playing card, false otherwise.
 */
bool is_normal_card(Card card);

/**
 * @brief Checks if the given color enum value is invalid.
 *
 * This function evaluates whether the provided color enumeration value
 * is greater than 4, indicating it is out of the valid range of color values.
 *
 * @param color The enumeration value representing the color.
 * @return true if the color is invalid, false otherwise.
 */
bool is_invalid_color(Color color);

/**
 * @brief Checks if two arrays of strings are equal.
 *
 * @param arr1 Pointer to the first array of strings.
 * @param len1 Number of elements in the first array.
 * @param arr2 Pointer to the second array of strings.
 * @param len2 Number of elements in the second array.
 * @return true if the arrays are equal, false otherwise.
 */
bool are_arrays_equal(const char **arr1, int len1, const char **arr2, int len2);

bool are_card_arrays_equal(Card *arr1, int len1, Card *arr2, int len2);

/**
 * @brief Prints a formatted line with a specified prefix and optionally colored card content.
 *
 * This function prints a line of characters, where the first and last characters are '*',
 * and spaces are inserted at the edges. It inserts the provided prefix at the beginning,
 * and if a colored card content is provided, it inserts it preceded by ANSI color escape
 * sequences to format the text. The line is formatted to fit within a predefined screen length.
 *
 * @param prefix The string to be printed at the beginning of the line.
 * @param color_card The string representing the colored card content to be printed.
 *                   If NULL, no colored card content is printed.
 * @param ansi_color The ANSI escape code to apply to the color_card content for formatting.
 *                   Ignored if color_card is NULL.
 */
void print_line_with_prefix(char *prefix, const char *color_card, const char *color_ansi);

/**
 * @brief Prints an error message indicating a test failure and terminates the program.
 *
 * @param num_test The number of the test that failed.
 */
void show_tests_error_message(int num_test);

/**
 * @brief Adds a new message to the history of messages.
 *
 * @param current_history Pointer to the array of strings representing the current message history.
 * @param current_size Pointer to the size of the current message history.
 * @param new_message The new message to be added to the history.
 * @return Updated pointer to the array of strings representing the updated message history.
 *         If memory allocation fails, the function prints an error message and exits the program.
 *
 * @note If the history size (`current_size`) exceeds a predefined limit (3), the oldest message is removed
 * to make room for the new message.
 */
char **push_history(char **current_history, int *current_size, char *new_message);

/**
 * Prints the hands of both the opponent and the player.
 *
 * This function constructs and displays formatted representations of the opponent's
 * and player's card hands. The opponent's hand is represented as a series of 'x' marks
 * enclosed in brackets, while the player's hand displays each card's color and either
 * a number or action associated with it.
 *
 * @param num_oponent_cards The number of cards held by the opponent.
 * @param player_cards      Array of Card structs representing the player's cards.
 * @param num_player_cards  The number of cards held by the player.
 */
void print_hands(int num_oponent_cards, Card *player_cards, int num_player_cards);

/**
 * Counts the number of digits in a given integer number.
 *
 * @param number The integer number whose digits are to be counted.
 * @return The number of digits in the given integer.
 */
int count_digits(int number);

/**
 * Converts an integer to a string representation.
 *
 * @param number The integer to be converted to a string.
 * @param str    A character array where the resulting string will be stored.
 *               The array must have enough space to store the string representation
 *               of the integer plus the null-terminator.
 * @return       A pointer to the character array `str` containing the string
 *               representation of the integer.
 */
char *int_to_string(int number);

/**
 * Concatenates a single character to a given string.
 *
 * @param str       The original string to which the character will be appended.
 * @param str_size  Pointer to an integer storing the current size of the string `str`.
 * @return          A pointer to the updated string `str` with the appended character `ch`.
 *
 * @note It dynamically reallocates memory for the string to accommodate the new character.
 */
char *concat_char(char *str, int *str_size, char ch);

/**
 * Concatenates a suffix string to a given string.
 *
 * This function appends the string `suffix` to the end of the string `str`.
 *
 * @param str       The original string to which the suffix will be appended.
 * @param str_size  Pointer to an integer storing the current size of the string `str`.
 * @return          A pointer to the updated string `str` with the appended suffix.
 *
 * @note It dynamically reallocates memory for the string to accommodate the new suffix.
 */
char *concat_string(char *str, int *str_size, char *suffix);

/**
 * Converts an integer to a string surrounded by parentheses.
 *
 * @param number The integer to be converted and enclosed in parentheses.
 * @return       A pointer to a newly allocated string containing the integer `number`
 *               enclosed in parentheses. The caller is responsible for freeing this
 *               memory when no longer needed.
 *
 * @note It dynamically allocates memory for the resulting string.
 */
char *int_between_parenthesis(int number);

/**
 * Retrieves player cards from a deck, removing them from the deck.
 *
 * @return          Pointer to an array of Card structures representing the player's cards.
 *                  Memory is dynamically allocated for this array. The caller is responsible for freeing
 *                  this memory when no longer needed.
 *
 * @note Memory is allocated for the player's card array dynamically.
 */
Card *get_player_cards();

/**
 * Removes an element from an array of Card structures and compacts the array.
 *
 * This function removes an element at the specified index `hole` from the array `arr`
 * of Card structures. It compacts the array by shifting all subsequent elements one
 * position to the left. Memory is reallocated to adjust the size of the array.
 *
 * @param arr       Pointer to a pointer to an array of Card structures.
 *                  Upon returning, this pointer is updated to reflect the compacted array.
 * @param arr_size  Pointer to an integer representing the current size of the array `arr`.
 *                  Upon returning, this value is updated to reflect the reduced size of the array.
 * @param hole      Index of the element to be removed from the array `arr`.
 * @return          Pointer to the updated array `arr` after removing and compacting elements.
 *                  Memory is reallocated as needed. The caller is responsible for freeing this memory
 *                  when no longer needed.
 */
Card *compaction(Card *arr, int *arr_size, int hole);

/**
 * Generates a random index within the range of the given array size.
 *
 * @param arr_size The size of the array for which a random index is to be generated.
 * @return         A random integer index within the range [0, arr_size-1].
 */
int random_array_index(int arr_size);

/**
 * Swaps two elements in an array of Card structures.
 *
 * This function swaps the elements at indices `i` and `j` in the array `arr`
 * of Card structures. It does not allocate or deallocate memory.
 *
 * @param arr Pointer to an array of Card structures.
 * @param i   Index of the first element to be swapped.
 * @param j   Index of the second element to be swapped.
 */
void swap(Card *arr, int i, int j);

/**
 * Sorts an array of Card structures based on color and card comparison.
 *
 * This function implements a bubble sort algorithm to sort the array `arr`
 * of Card structures in ascending order based on color first and then by
 * comparing the cards using the `compare_cards` function.
 *
 * @param arr Pointer to an array of Card structures to be sorted.
 * @param n   Number of elements in the array `arr`.
 */
void sort_cards(Card *arr, int n);

char **str_compaction(char **arr, int *arr_size, int hole);
void print_oponent_cards(int num_cards);
void print_player_cards(Card *cards, int num_cards);
Card play_card(Card **cards, int *cards_size, Card *top_card, Color chosen_color, bool *player_played);
void delete_last_line();
void delete_lines_by_errors(bool was_last_entry_invalid);
void show_game_screen(char ***history, int *history_size, Card *player_cards, int *num_player_cards, Card *oponent_cards, int *num_oponent_cards, Card *top_card, Color *chosen_color);
void print_strs(char **matrix, int rows);
void update_table(Card *current, Card new_card, bool played);
Card oponent_play(Card **cards, int *num_cards, Card top_card, Color chosen_color, bool *oponent_played);

bool is_color_match(Card card1, Card card2);
bool is_number_match(Card card1, Card card2);
bool is_action_match(Card card1, Card card2);
bool is_wild_card(Card card);

bool is_in_interval(int number, int min, int max);

void handle_invalid_choice(bool *was_last_entry_invalid, char *message);
bool can_play_card(Card chosen, Card top_card, Color chosen_color);
void check_play(Card card, Color *chosen_color, bool player_played);
void update_history(Card top_card, Color chosen_color, char ***history, int *history_size, bool is_player, bool played);
void check_oponent_play(Card card, Color *chosen_color, bool oponent_played);
void print_card(Card card);
void print_opponent(Card *cards, int num_cards);
Card *push_card(Card *cards, int *size, Card new_card);
Card draw_card();
void initialize_random();



// Function to print details of a single card
void print_card_loop(const Card* card) {
    if (card->isNumber) {
        printf("Card - Color: %s, Number: %u\n", color_mapper[card->color], card->numberAction.number);
    } else {
        printf("Card - Color: %s, Action: %s\n", color_mapper[card->color], card->numberAction.action);
    }
}

// Function to print details of an array of cards
void print_cards(const Card* cards, int size) {
    printf("Cards in array:\n");
    for (int i = 0; i < size; i++) {
        print_card_loop(&cards[i]);
    }
}




void print_str_arr(char **arr, int size);

int state = HOME;
Card *deck;
int deck_size;

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

Card *create_deck()
{
    int index = 0;
    char colorful_special_actions[3][8] = {"block", "reverse", "+2"};
    char special_actions_without_color[2][7] = {"change", "+4"};
    Card *deck = malloc(MAX_CARDS * sizeof(Card));

    for (Color i = RED; i <= YELLOW; i++)
    {
        deck[index] = (Card){
            i, {.number = 0}, true};
        index++;

        for (int j = 1; j <= 2; j++)
        {
            for (int k = 1; k <= 9; k++)
            {
                deck[index] = (Card){
                    i, {.number = k}, true};
                index++;
            }

            for (int k = 0; k < 3; k++)
            {
                deck[index] = (Card){
                    i, {.action = ""}, false};

                copy_action(&deck[index], colorful_special_actions[k]);

                index++;
            }
        }

        for (int j = 0; j < 2; j++)
        {
            deck[index] = (Card){
                WILD, {.action = ""}, false};

            copy_action(&deck[index], special_actions_without_color[j]);

            index++;
        }
    }

    // print_arr(deck, MAX_CARDS);

    return deck;
}

void print_arr(Card arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].color == WILD)
        {
            printf("Carta %d: Cor: %d, Ação: %s\n", i, arr[i].color, arr[i].numberAction.action);
        }
        else
        {
            if (arr[i].isNumber)
            {
                printf("Carta %d: Cor: %d, Número: %d\n", i, arr[i].color, arr[i].numberAction.number);
            }
            else
            {
                printf("Carta %d: Cor: %d, Ação: %s\n", i, arr[i].color, arr[i].numberAction.action);
            }
        }
    }
}

void copy_action(Card *last_card, const char *action)
{
    size_t action_buffer_size = sizeof((*last_card).numberAction.action);
    strncpy((*last_card).numberAction.action, action, action_buffer_size);
}

void run_tests()
{
    // Setup
    clock_t start, end;
    double time;
    int num_tests = 0;

    start = clock();

    // Casos de Teste para a função sum
    struct
    {
        int a, b;
        int expected;
    } sum_tests[] = {
        {1, 2, 3},
        {0, 0, 0},
        {-1, 1, 0},
        {100, 200, 300}};

    // Test 1
    Card create_deck_expected[MAX_CARDS] = {
        {RED, {.number = 0}, true},
        {RED, {.number = 1}, true},
        {RED, {.number = 2}, true},
        {RED, {.number = 3}, true},
        {RED, {.number = 4}, true},
        {RED, {.number = 5}, true},
        {RED, {.number = 6}, true},
        {RED, {.number = 7}, true},
        {RED, {.number = 8}, true},
        {RED, {.number = 9}, true},
        {RED, {.action = "block"}, false},
        {RED, {.action = "reverse"}, false},
        {RED, {.action = "+2"}, false},
        {RED, {.number = 1}, true},
        {RED, {.number = 2}, true},
        {RED, {.number = 3}, true},
        {RED, {.number = 4}, true},
        {RED, {.number = 5}, true},
        {RED, {.number = 6}, true},
        {RED, {.number = 7}, true},
        {RED, {.number = 8}, true},
        {RED, {.number = 9}, true},
        {RED, {.action = "block"}, false},
        {RED, {.action = "reverse"}, false},
        {RED, {.action = "+2"}, false},
        {WILD, {.action = "change"}, false},
        {WILD, {.action = "+4"}, false},
        {GREEN, {.number = 0}, true},
        {GREEN, {.number = 1}, true},
        {GREEN, {.number = 2}, true},
        {GREEN, {.number = 3}, true},
        {GREEN, {.number = 4}, true},
        {GREEN, {.number = 5}, true},
        {GREEN, {.number = 6}, true},
        {GREEN, {.number = 7}, true},
        {GREEN, {.number = 8}, true},
        {GREEN, {.number = 9}, true},
        {GREEN, {.action = "block"}, false},
        {GREEN, {.action = "reverse"}, false},
        {GREEN, {.action = "+2"}, false},
        {GREEN, {.number = 1}, true},
        {GREEN, {.number = 2}, true},
        {GREEN, {.number = 3}, true},
        {GREEN, {.number = 4}, true},
        {GREEN, {.number = 5}, true},
        {GREEN, {.number = 6}, true},
        {GREEN, {.number = 7}, true},
        {GREEN, {.number = 8}, true},
        {GREEN, {.number = 9}, true},
        {GREEN, {.action = "block"}, false},
        {GREEN, {.action = "reverse"}, false},
        {GREEN, {.action = "+2"}, false},
        {WILD, {.action = "change"}, false},
        {WILD, {.action = "+4"}, false},
        {BLUE, {.number = 0}, true},
        {BLUE, {.number = 1}, true},
        {BLUE, {.number = 2}, true},
        {BLUE, {.number = 3}, true},
        {BLUE, {.number = 4}, true},
        {BLUE, {.number = 5}, true},
        {BLUE, {.number = 6}, true},
        {BLUE, {.number = 7}, true},
        {BLUE, {.number = 8}, true},
        {BLUE, {.number = 9}, true},
        {BLUE, {.action = "block"}, false},
        {BLUE, {.action = "reverse"}, false},
        {BLUE, {.action = "+2"}, false},
        {BLUE, {.number = 1}, true},
        {BLUE, {.number = 2}, true},
        {BLUE, {.number = 3}, true},
        {BLUE, {.number = 4}, true},
        {BLUE, {.number = 5}, true},
        {BLUE, {.number = 6}, true},
        {BLUE, {.number = 7}, true},
        {BLUE, {.number = 8}, true},
        {BLUE, {.number = 9}, true},
        {BLUE, {.action = "block"}, false},
        {BLUE, {.action = "reverse"}, false},
        {BLUE, {.action = "+2"}, false},
        {WILD, {.action = "change"}, false},
        {WILD, {.action = "+4"}, false},
        {YELLOW, {.number = 0}, true},
        {YELLOW, {.number = 1}, true},
        {YELLOW, {.number = 2}, true},
        {YELLOW, {.number = 3}, true},
        {YELLOW, {.number = 4}, true},
        {YELLOW, {.number = 5}, true},
        {YELLOW, {.number = 6}, true},
        {YELLOW, {.number = 7}, true},
        {YELLOW, {.number = 8}, true},
        {YELLOW, {.number = 9}, true},
        {YELLOW, {.action = "block"}, false},
        {YELLOW, {.action = "reverse"}, false},
        {YELLOW, {.action = "+2"}, false},
        {YELLOW, {.number = 1}, true},
        {YELLOW, {.number = 2}, true},
        {YELLOW, {.number = 3}, true},
        {YELLOW, {.number = 4}, true},
        {YELLOW, {.number = 5}, true},
        {YELLOW, {.number = 6}, true},
        {YELLOW, {.number = 7}, true},
        {YELLOW, {.number = 8}, true},
        {YELLOW, {.number = 9}, true},
        {YELLOW, {.action = "block"}, false},
        {YELLOW, {.action = "reverse"}, false},
        {YELLOW, {.action = "+2"}, false},
        {WILD, {.action = "change"}, false},
        {WILD, {.action = "+4"}, false},
    };

    // Tamanho dos arrays de testes

    // Testes em loop
    Card *create_deck_result = create_deck();
    for (int i = 0; i < MAX_CARDS; i++)
    {
        Card card_expected = create_deck_expected[i];
        Card card_result = create_deck_result[i];

        if (card_expected.color != card_result.color)
        {
            show_card_error_message("Carta não correspondente pela cor", card_expected, card_result);
        }
        else
        {
            if (card_expected.isNumber != card_result.isNumber)
            {
                show_card_error_message("Carta não correspondente pela verificação", card_expected, card_result);
            }
            else
            {
                // Either both are true or both are false
                if (card_expected.isNumber)
                {
                    // These are numbers
                    if (card_expected.numberAction.number != card_result.numberAction.number)
                    {
                        show_card_error_message("Carta não correspondente pelo número", card_expected, card_result);
                    }
                }
                else
                {
                    // These are action cards
                    if (strcmp(card_expected.numberAction.action, card_result.numberAction.action) != 0)
                    {
                        show_card_error_message("Carta não correspondente pela ação", card_expected, card_result);
                    }
                }
            }
        }
    }
    num_tests++;
    free(create_deck_result);

    // Test 2
    char *reverse_test[] = {"hello", "world"};
    char *reverse_expected[] = {"world", "hello"};
    char **reversed_result = reverse(reverse_test, 2);

    if (!are_arrays_equal((const char **)reverse_expected, 2, (const char **)reversed_result, 2))
    {
        show_tests_error_message(num_tests + 1);
    }
    num_tests++;
    free(reversed_result);

    // Test 3
    char *reverse_test2[] = {"one", "two", "three"};
    char *reverse_expected2[] = {"three", "two", "one"};
    reversed_result = reverse(reverse_test2, 3);

    if (!are_arrays_equal((const char **)reverse_expected2, 3, (const char **)reversed_result, 3))
    {
        show_tests_error_message(num_tests + 1);
    }
    num_tests++;
    free(reversed_result);

    // Test 4
    char **reverse_null_test = NULL;
    char **reverse_null_expected = NULL;
    reversed_result = reverse(reverse_null_test, 0);

    if (reversed_result != reverse_null_expected)
    {
        show_tests_error_message(num_tests + 1);
    }
    num_tests++;
    // No need to free reversed_result since it is NULL

    // Test 5
    char *reverse_one_element_test[] = {"test"};
    char *reverse_one_element_expected[] = {"test"};
    reversed_result = reverse(reverse_one_element_test, 1);

    if (!are_arrays_equal((const char **)reverse_one_element_expected, 1, (const char **)reversed_result, 1))
    {
        show_tests_error_message(num_tests + 1);
    }
    num_tests++;
    free(reversed_result);

    // Test 6
    Color red_test = RED;
    char *expected_red_test = "Vermelho";
    char *result_red_test = get_color_name(red_test);
    TEST_ASSERT_EQUAL_STR(expected_red_test, result_red_test, num_tests);
    num_tests++;

    // Test 7
    Color yellow_test = YELLOW;
    char *expected_yellow_test = "Amarelo";
    char *result_yellow_test = get_color_name(yellow_test);
    TEST_ASSERT_EQUAL_STR(expected_yellow_test, result_yellow_test, num_tests);
    num_tests++;

    // Test 8
    Color green_test = GREEN;
    char *expected_green_test = "Verde";
    char *result_green_test = get_color_name(green_test);
    TEST_ASSERT_EQUAL_STR(expected_green_test, result_green_test, num_tests);
    num_tests++;

    // Test 9
    Color blue_test = BLUE;
    char *expected_blue_test = "Azul";
    char *result_blue_test = get_color_name(blue_test);
    TEST_ASSERT_EQUAL_STR(expected_blue_test, result_blue_test, num_tests);
    num_tests++;

    // Test 10
    Color wild_test = WILD;
    char *expected_wild_test = "Especial";
    char *result_wild_test = get_color_name(wild_test);
    TEST_ASSERT_EQUAL_STR(expected_wild_test, result_wild_test, num_tests);
    num_tests++;

    // Test 11
    int strange_test = 999;
    char *expected_strange_test = "Invalid";
    char *result_strange_test = get_color_name(strange_test);
    TEST_ASSERT_EQUAL_STR(expected_strange_test, result_strange_test, num_tests);
    num_tests++;

    char *expected_ansi_red_test = "\x1b[31m";
    char *result_ansi_red_test = get_color_ansi(red_test);
    TEST_ASSERT_EQUAL_STR(expected_ansi_red_test, result_ansi_red_test, num_tests);
    num_tests++;

    char *expected_ansi_blue_test = "\x1b[34m";
    char *result_ansi_blue_test = get_color_ansi(blue_test);
    TEST_ASSERT_EQUAL_STR(expected_ansi_blue_test, result_ansi_blue_test, num_tests);
    num_tests++;

    char *expected_ansi_yellow_test = "\x1b[33m";
    char *result_ansi_yellow_test = get_color_ansi(yellow_test);
    TEST_ASSERT_EQUAL_STR(expected_ansi_yellow_test, result_ansi_yellow_test, num_tests);
    num_tests++;

    char *expected_ansi_green_test = "\x1b[32m";
    char *result_ansi_green_test = get_color_ansi(green_test);
    TEST_ASSERT_EQUAL_STR(expected_ansi_green_test, result_ansi_green_test, num_tests);
    num_tests++;

    char *expected_ansi_wild_test = "\x1b[0m";
    char *result_ansi_wild_test = get_color_ansi(wild_test);
    TEST_ASSERT_EQUAL_STR(expected_ansi_wild_test, result_ansi_wild_test, num_tests);
    num_tests++;

    // bool is_normal_card(Card card);
    Card normal_red_test = (Card){RED, {.number = 0}, true};
    bool expected_normal_red_test = true;
    bool result_normal_red_test = is_normal_card(normal_red_test);
    TEST_ASSERT_EQUAL(expected_normal_red_test, result_normal_red_test, num_tests);
    num_tests++;

    Card normal_yellow_test = (Card){YELLOW, {.number = 0}, true};
    bool expected_normal_yellow_test = true;
    bool result_normal_yellow_test = is_normal_card(normal_yellow_test);
    TEST_ASSERT_EQUAL(expected_normal_yellow_test, result_normal_yellow_test, num_tests);
    num_tests++;

    Card normal_green_test = (Card){GREEN, {.number = 0}, true};
    bool expected_normal_green_test = true;
    bool result_normal_green_test = is_normal_card(normal_green_test);
    TEST_ASSERT_EQUAL(expected_normal_green_test, result_normal_green_test, num_tests);
    num_tests++;

    Card normal_blue_test = (Card){BLUE, {.number = 0}, true};
    bool expected_normal_blue_test = true;
    bool result_normal_blue_test = is_normal_card(normal_blue_test);
    TEST_ASSERT_EQUAL(expected_normal_blue_test, result_normal_blue_test, num_tests);
    num_tests++;

    Card normal_wild_test = (Card){WILD, {.number = 0}, false};
    bool expected_normal_wild_test = false;
    bool result_normal_wild_test = is_normal_card(normal_wild_test);
    TEST_ASSERT_EQUAL(expected_normal_wild_test, result_normal_wild_test, num_tests);
    num_tests++;

    Card normal_extra_number_test = (Card){RED, {.number = 11}, true};
    bool expected_normal_extra_number_test = false;
    bool result_normal_extra_number_test = is_normal_card(normal_extra_number_test);
    TEST_ASSERT_EQUAL(expected_normal_extra_number_test, result_normal_extra_number_test, num_tests);
    num_tests++;

    Card normal_negative_number_test = (Card){YELLOW, {.number = -1}, true};
    bool expected_normal_negative_number_test = false;
    bool result_normal_negative_number_test = is_normal_card(normal_negative_number_test);
    TEST_ASSERT_EQUAL(expected_normal_negative_number_test, result_normal_negative_number_test, num_tests);
    num_tests++;

    bool expected_color_red_test = false;
    bool result_color_red_test = is_invalid_color(red_test);
    TEST_ASSERT_EQUAL(expected_color_red_test, result_color_red_test, num_tests);
    num_tests++;

    bool expected_color_green_test = false;
    bool result_color_green_test = is_invalid_color(green_test);
    TEST_ASSERT_EQUAL(expected_color_green_test, result_color_green_test, num_tests);
    num_tests++;

    bool expected_color_yellow_test = false;
    bool result_color_yellow_test = is_invalid_color(yellow_test);
    TEST_ASSERT_EQUAL(expected_color_yellow_test, result_color_yellow_test, num_tests);
    num_tests++;

    bool expected_color_blue_test = false;
    bool result_color_blue_test = is_invalid_color(blue_test);
    TEST_ASSERT_EQUAL(expected_color_blue_test, result_color_blue_test, num_tests);
    num_tests++;

    bool expected_color_wild_test = false;
    bool result_color_wild_test = is_invalid_color(wild_test);
    TEST_ASSERT_EQUAL(expected_color_wild_test, result_color_wild_test, num_tests);
    num_tests++;

    bool expected_color_negative_test = true;
    bool result_color_negative_test = is_invalid_color(-1);
    TEST_ASSERT_EQUAL(expected_color_negative_test, result_color_negative_test, num_tests);
    num_tests++;

    bool expected_color_exceeding_test = true;
    bool result_color_exceeding_test = is_invalid_color(5);
    TEST_ASSERT_EQUAL(expected_color_exceeding_test, result_color_exceeding_test, num_tests);
    num_tests++;
    
    // Remove an element from the middle of the array
    int size_middle = 5;
    Card *array_middle = (Card *)malloc(size_middle * sizeof(Card));
    for (int i = 0; i < size_middle; i++)
    {
        array_middle[i].color = (Color)i;
        array_middle[i].isNumber = 1;
        array_middle[i].numberAction.number = i;
    }
    int hole_middle = 2;
    Card *result_middle = compaction(array_middle, &size_middle, hole_middle);
    TEST_ASSERT_EQUAL(4, size_middle, num_tests + 1);
    TEST_ASSERT_EQUAL(0, result_middle[0].color, num_tests + 1);
    TEST_ASSERT_EQUAL(1, result_middle[1].color, num_tests + 1);
    TEST_ASSERT_EQUAL(3, result_middle[2].color, num_tests + 1);
    TEST_ASSERT_EQUAL(4, result_middle[3].color, num_tests + 1);
    free(result_middle);
    num_tests++;

    // Remove the first element of the array
    int size_first = 3;
    Card *array_first = (Card *)malloc(size_first * sizeof(Card));
    for (int i = 0; i < size_first; i++)
    {
        array_first[i].color = (Color)i;
        array_first[i].isNumber = 1;
        array_first[i].numberAction.number = i;
    }
    int hole_first = 0;
    Card *result_first = compaction(array_first, &size_first, hole_first);
    TEST_ASSERT_EQUAL(2, size_first, num_tests + 1);
    TEST_ASSERT_EQUAL(1, result_first[0].color, num_tests + 1);
    TEST_ASSERT_EQUAL(2, result_first[1].color, num_tests + 1);
    free(result_first);
    num_tests++;

    // Remove the last element of the array
    int size_last = 4;
    Card *array_last = (Card *)malloc(size_last * sizeof(Card));
    for (int i = 0; i < size_last; i++)
    {
        array_last[i].color = (Color)i;
        array_last[i].isNumber = 1;
        array_last[i].numberAction.number = i;
    }
    int hole_last = 3;
    Card *result_last = compaction(array_last, &size_last, hole_last);
    TEST_ASSERT_EQUAL(3, size_last, num_tests + 1);
    TEST_ASSERT_EQUAL(0, result_last[0].color, num_tests + 1);
    TEST_ASSERT_EQUAL(1, result_last[1].color, num_tests + 1);
    TEST_ASSERT_EQUAL(2, result_last[2].color, num_tests + 1);
    free(result_last);
    num_tests++;

    // Attempt to remove an element with an invalid index
    int size_invalid = 4;
    Card *array_invalid = (Card *)malloc(size_invalid * sizeof(Card));
    for (int i = 0; i < size_invalid; i++)
    {
        array_invalid[i].color = (Color)i;
        array_invalid[i].isNumber = 1;
        array_invalid[i].numberAction.number = i;
    }
    int hole_invalid = 10; // Invalid index
    Card *result_invalid = compaction(array_invalid, &size_invalid, hole_invalid);
    TEST_ASSERT_EQUAL(4, size_invalid, num_tests + 1);
    TEST_ASSERT_EQUAL(0, result_invalid[0].color, num_tests + 1);
    TEST_ASSERT_EQUAL(1, result_invalid[1].color, num_tests + 1);
    TEST_ASSERT_EQUAL(2, result_invalid[2].color, num_tests + 1);
    TEST_ASSERT_EQUAL(3, result_invalid[3].color, num_tests + 1);
    free(result_invalid);
    num_tests++;

    // Handle the case when the array is empty
    int size_empty = 0;
    Card *array_empty = NULL;
    int hole_empty = 0; // Invalid index
    Card *result_empty = compaction(array_empty, &size_empty, hole_empty);
    TEST_ASSERT_EQUAL(0, size_empty, num_tests + 1);
    TEST_ASSERT_EQUAL_PTR(NULL, result_empty, num_tests + 1);
    num_tests++;

    // Handle the case when the array is empty
    int str_compaction_size_empty = 0;
    char **str_compaction_array_empty = NULL;
    int str_compaction_hole_empty = 0; // Invalid index
    char **str_compaction_result_empty = str_compaction(str_compaction_array_empty, &str_compaction_size_empty, str_compaction_hole_empty);
    TEST_ASSERT_EQUAL(0, str_compaction_size_empty, num_tests);
    TEST_ASSERT_EQUAL_PTR(NULL, str_compaction_result_empty, num_tests);
    num_tests++; 

    // Handle the case when the hole index is invalid (greater than size)
    int str_compaction_size_invalid = 3;
    char **str_compaction_array_invalid = malloc(str_compaction_size_invalid * sizeof(char *));
    for (int i = 0; i < str_compaction_size_invalid; i++) {
        str_compaction_array_invalid[i] = strdup("test");
    }
    int str_compaction_hole_invalid = 5; // Invalid index
    char **str_compaction_result_invalid = str_compaction(str_compaction_array_invalid, &str_compaction_size_invalid, str_compaction_hole_invalid);
    TEST_ASSERT_EQUAL(3, str_compaction_size_invalid, num_tests);
    TEST_ASSERT_EQUAL_PTR(str_compaction_array_invalid, str_compaction_result_invalid, num_tests);
    for (int i = 0; i < str_compaction_size_invalid; i++) {
        free(str_compaction_array_invalid[i]);
    }
    free(str_compaction_array_invalid);
    num_tests++;

    // Handle the case when the hole index is within bounds
    int str_compaction_size_valid = 3;
    char **str_compaction_array_valid = malloc(str_compaction_size_valid * sizeof(char *));
    for (int i = 0; i < str_compaction_size_valid; i++) {
        str_compaction_array_valid[i] = strdup("test");
    }


    int str_compaction_hole_valid = 1;
    char **str_compaction_expected_result_valid = malloc((str_compaction_size_valid - 1) * sizeof(char *));
    for (int i = 0; i < str_compaction_size_valid - 1; i++) {
        str_compaction_expected_result_valid[i] = strdup("test");
    }

    str_compaction_array_valid = str_compaction(str_compaction_array_valid, &str_compaction_size_valid, str_compaction_hole_valid);

    TEST_ASSERT_EQUAL(2, str_compaction_size_valid, num_tests);
    TEST_ASSERT_ARRAYS_EQUAL((const char **)str_compaction_expected_result_valid, 2, (const char **)str_compaction_array_valid, 2, num_tests);
    for (int i = 0; i < 2; i++) {
        free(str_compaction_expected_result_valid[i]);
    }
    free(str_compaction_expected_result_valid);
    for (int i = 0; i < str_compaction_size_valid; i++) {
        free(str_compaction_array_valid[i]);
    }
    free(str_compaction_array_valid);
    num_tests++;

    // Handle the case when the array contains a single element and it is removed
    int str_compaction_size_single = 1;
    char **str_compaction_array_single = malloc(str_compaction_size_single * sizeof(char *));
    str_compaction_array_single[0] = strdup("test");
    int str_compaction_hole_single = 0;
    str_compaction_array_single = str_compaction(str_compaction_array_single, &str_compaction_size_single, str_compaction_hole_single);
    TEST_ASSERT_EQUAL(0, str_compaction_size_single, num_tests);
    TEST_ASSERT_EQUAL_PTR(NULL, str_compaction_array_single, num_tests);
    free(str_compaction_array_single);
    num_tests++;
    
    // get_card_for_table test
    deck_size = 5;
    deck = (Card *)malloc(deck_size * sizeof(Card));
    deck[0] = (Card){RED, .numberAction.number = 1, true};
    deck[1] = (Card){GREEN, .numberAction.number = 2, true};
    deck[2] = (Card){BLUE, .numberAction.number = 3, true};
    deck[3] = (Card){WILD, .numberAction.number = 0, false};
    deck[4] = (Card){YELLOW, .numberAction.number = 4, true};

    // Function test
    Card card = get_card_for_table();

    if (!is_normal_card(card))
    {
        printf("[TEST ERROR]: A carta retornada não é uma carta normal.\n");
    }

    // Check if the card has been removed from the deck
    for (int i = 0; i < deck_size; i++)
    {
        if (deck[i].color == card.color && deck[i].isNumber && deck[i].numberAction.number == card.numberAction.number)
        {
            printf("[TEST ERROR]: A carta não foi removida do deck.\n");
            return;
        }
    }
    
    num_tests++;
    free(deck);
    
    // Equal arrays
    const char *test1_arr1[] = {"hello", "world"};
    const char *test1_arr2[] = {"hello", "world"};
    TEST_ASSERT_ARRAYS_EQUAL(test1_arr1, 2, test1_arr2, 2, num_tests + 1);
    num_tests++;

    // Different arrays
    const char *test2_arr1[] = {"hello", "world"};
    const char *test2_arr2[] = {"hello", "everyone"};
    if (are_arrays_equal(test2_arr1, 2, test2_arr2, 2))
    {
        printf("ERROR: Teste %d falhou. Arrays não deveriam ser iguais.\n", num_tests + 1);
        exit(1);
    }
    num_tests++;

    // Arrays of different sizes
    const char *test3_arr1[] = {"hello", "world"};
    const char *test3_arr2[] = {"hello"};
    if (are_arrays_equal(test3_arr1, 2, test3_arr2, 1))
    {
        printf("ERROR: Teste %d falhou. Arrays de tamanhos diferentes não deveriam ser iguais.\n", num_tests + 1);
        exit(1);
    }
    num_tests++;

    // Null arrays
    const char **test4_arr1 = NULL;
    const char **test4_arr2 = NULL;
    TEST_ASSERT_ARRAYS_EQUAL(test4_arr1, 0, test4_arr2, 0, num_tests + 1);
    num_tests++;
    
    char **test_history = NULL;
    int test_size = 0;

    // Insert a message into empty history
    test_history = push_history(test_history, &test_size, "msg1");
    const char *expected1[] = {"msg1"};
    TEST_ASSERT_ARRAYS_EQUAL(expected1, 1, (const char **)test_history, test_size, num_tests + 1);
    num_tests++;

    // Insert a second message into the history with one element
    test_history = push_history(test_history, &test_size, "msg2");
    const char *expected2[] = {"msg1", "msg2"};
    TEST_ASSERT_ARRAYS_EQUAL(expected2, 2, (const char **)test_history, test_size, num_tests + 1);
    num_tests++;
        
    // get_card_for_table test
    deck_size = 5;
    deck = (Card *)malloc(deck_size * sizeof(Card));
    deck[0] = (Card){RED, .numberAction.number = 1, true};
    deck[1] = (Card){GREEN, .numberAction.number = 2, true};
    deck[2] = (Card){BLUE, .numberAction.number = 3, true};
    deck[3] = (Card){WILD, .numberAction.number = 0, false};
    deck[4] = (Card){YELLOW, .numberAction.number = 4, true};

    // Function test
    Card card_table = get_card_for_table();

    if (!is_normal_card(card_table))
    {
        printf("[TEST ERROR]: A carta retornada não é uma carta normal.\n");
    }

    // Check if the card has been removed from the deck
    for (int i = 0; i < deck_size; i++)
    {
        if (deck[i].color == card_table.color && deck[i].isNumber && deck[i].numberAction.number == card_table.numberAction.number)
        {
            printf("[TEST ERROR]: A carta não foi removida do deck.\n");
            return;
        }
    }
    
    num_tests++;
    free(deck);
    
    // Equal arrays
    const char *equal_test1_arr1[] = {"hello", "world"};
    const char *equal_test1_arr2[] = {"hello", "world"};
    TEST_ASSERT_ARRAYS_EQUAL(equal_test1_arr1, 2, equal_test1_arr2, 2, num_tests + 1);
    num_tests++;

    // Different arrays
    const char *equal_test2_arr1[] = {"hello", "world"};
    const char *equal_test2_arr2[] = {"hello", "everyone"};
    if (are_arrays_equal(equal_test2_arr1, 2, equal_test2_arr2, 2))
    {
        printf("ERROR: Teste %d falhou. Arrays não deveriam ser iguais.\n", num_tests + 1);
        exit(1);
    }
    num_tests++;

    // Arrays of different sizes
    const char *equal_test3_arr1[] = {"hello", "world"};
    const char *equal_test3_arr2[] = {"hello"};
    if (are_arrays_equal(equal_test3_arr1, 2, equal_test3_arr2, 1))
    {
        printf("ERROR: Teste %d falhou. Arrays de tamanhos diferentes não deveriam ser iguais.\n", num_tests + 1);
        exit(1);
    }
    num_tests++;

    // Null arrays
    const char **equal_test4_arr1 = NULL;
    const char **equal_test4_arr2 = NULL;
    TEST_ASSERT_ARRAYS_EQUAL(equal_test4_arr1, 0, equal_test4_arr2, 0, num_tests + 1);
    num_tests++;
    
    char **push_history_test_history = NULL;
    int push_history_test_size = 0;

    // Insert a message into empty history
    push_history_test_history = push_history(push_history_test_history, &push_history_test_size, "msg1");
    const char *push_history_expected1[] = {"msg1"};
    TEST_ASSERT_ARRAYS_EQUAL(push_history_expected1, 1, (const char **)push_history_test_history, push_history_test_size, num_tests + 1);
    num_tests++;

    // Insert a second message into the history with one element
    push_history_test_history = push_history(push_history_test_history, &push_history_test_size, "msg2");
    const char *push_history_expected2[] = {"msg1", "msg2"};
    TEST_ASSERT_ARRAYS_EQUAL(push_history_expected2, 2, (const char **)push_history_test_history, push_history_test_size, num_tests + 1);
    num_tests++;

    // Insert a third message into the history with two elements
    push_history_test_history = push_history(push_history_test_history, &push_history_test_size, "msg3");
    const char *push_history_expected3[] = {"msg1", "msg2", "msg3"};
    TEST_ASSERT_ARRAYS_EQUAL(push_history_expected3, 3, (const char **)push_history_test_history, push_history_test_size, num_tests + 1);
    num_tests++;

    // Insert a fourth message in the history with three elements (must move)
    push_history_test_history = push_history(push_history_test_history, &push_history_test_size, "msg4");
    const char *push_history_expected4[] = {"msg2", "msg3", "msg4"};
    TEST_ASSERT_ARRAYS_EQUAL(push_history_expected4, 3, (const char **)push_history_test_history, push_history_test_size, num_tests + 1);
    num_tests++;
    
    // Free memory
    for (int i = 0; i < push_history_test_size; i++)
    {
        free(push_history_test_history[i]);
    }
    free(push_history_test_history);
    
    // Free memory
    for (int i = 0; i < test_size; i++)
    {
        free(test_history[i]);
    }
    free(test_history);
    
    // Testing zero
    int result1 = count_digits(0);
    TEST_ASSERT_EQUAL(1, result1, num_tests + 1);
    num_tests++;

    // Testing single-digit positive number
    int result2 = count_digits(5);
    TEST_ASSERT_EQUAL(1, result2, num_tests + 1);
    num_tests++;

    // Testing multi-digit positive number
    int result3 = count_digits(1234);
    TEST_ASSERT_EQUAL(4, result3, num_tests + 1);
    num_tests++;

    // Testing negative number
    int result4 = count_digits(-567);
    TEST_ASSERT_EQUAL(3, result4, num_tests + 1);
    num_tests++;

    // Testing number with leading zeros
    int result5 = count_digits(1000);
    TEST_ASSERT_EQUAL(4, result5, num_tests + 1);
    num_tests++;
    
    // Test case for zero
    char *result_zero = int_to_string(0);
    const char *expected_zero = "0";
    TEST_ASSERT_EQUAL_STR(expected_zero, result_zero, num_tests + 1);
    free(result_zero);
    num_tests++;

    // Test case for single-digit positive number
    char *result_single_digit = int_to_string(7);
    const char *expected_single_digit = "7";
    TEST_ASSERT_EQUAL_STR(expected_single_digit, result_single_digit, num_tests + 1);
    free(result_single_digit);
    num_tests++;

    // Test case for multi-digit positive number
    char *result_multi_digit = int_to_string(1234);
    const char *expected_multi_digit = "1234";
    TEST_ASSERT_EQUAL_STR(expected_multi_digit, result_multi_digit, num_tests + 1);
    free(result_multi_digit);
    num_tests++;

    // Test case for negative number
    char *result_negative = int_to_string(-567);
    const char *expected_negative = "-567";
    TEST_ASSERT_EQUAL_STR(expected_negative, result_negative, num_tests + 1);
    free(result_negative);
    num_tests++;

    // Test case for a large number
    char *result_large_number = int_to_string(1000000);
    const char *expected_large_number = "1000000";
    TEST_ASSERT_EQUAL_STR(expected_large_number, result_large_number, num_tests + 1);
    free(result_large_number);
    num_tests++;
    
    // Test case for appending to an empty string
    char *str_empty = (char *)malloc(2 * sizeof(char)); // Initial size 1 + 1 for null terminator
    str_empty[0] = '\0';
    int current_size_empty = 0; // Updated variable name
    char *result_str_empty = concat_char(str_empty, &current_size_empty, 'a');
    const char *expected_empty = "a";
    TEST_ASSERT_EQUAL_STR(expected_empty, result_str_empty, num_tests + 1);
    free(str_empty);
    num_tests++;

    // Test case for appending a character to a non-empty string
    char *str_non_empty = (char *)malloc(3 * sizeof(char)); // Initial size 2 + 1 for null terminator
    strcpy(str_non_empty, "b");
    int size_non_empty = 1;
    char *result_non_empty = concat_char(str_non_empty, &size_non_empty, 'c');
    const char *expected_non_empty = "bc";
    TEST_ASSERT_EQUAL_STR(expected_non_empty, result_non_empty, num_tests + 1);
    free(str_non_empty);
    num_tests++;

    // Test case for appending a character to a larger string
    char *str_large = (char *)malloc(5 * sizeof(char)); // Initial size 4 + 1 for null terminator
    strcpy(str_large, "abc");
    int size_large = 3;
    char *result_large = concat_char(str_large, &size_large, 'd');
    const char *expected_large = "abcd";
    TEST_ASSERT_EQUAL_STR(expected_large, result_large, num_tests + 1);
    free(str_large);
    num_tests++;
    
    // Test case for appending an empty string to an empty string
    char *str_empty_empty = (char *)malloc(1 * sizeof(char)); // Initial size 0 + 1 for null terminator
    str_empty_empty[0] = '\0';
    int size_empty_empty = 0;
    char *result_empty_empty = concat_string(str_empty_empty, &size_empty_empty, "");
    const char *expected_empty_empty = "";
    TEST_ASSERT_EQUAL_STR(expected_empty_empty, result_empty_empty, num_tests + 1);
    free(str_empty_empty);
    num_tests++;

    // Test case for appending a non-empty string to an empty string
    char *str_empty_non_empty = (char *)malloc(6 * sizeof(char)); // Initial size 0 + 5 for "hello" + 1 for null terminator
    str_empty_non_empty[0] = '\0';
    int size_empty_non_empty = 0;
    char *result_empty_non_empty = concat_string(str_empty_non_empty, &size_empty_non_empty, "hello");
    const char *expected_empty_non_empty = "hello";
    TEST_ASSERT_EQUAL_STR(expected_empty_non_empty, result_empty_non_empty, num_tests + 1);
    free(str_empty_non_empty);
    num_tests++;

    // Test case for appending a string to a string with content
    char *str_with_content = (char *)malloc(10 * sizeof(char)); // Initial size 4 + 5 for "world" + 1 for null terminator
    strcpy(str_with_content, "test");
    int size_with_content = 4;
    char *result_with_content = concat_string(str_with_content, &size_with_content, "world");
    const char *expected_with_content = "testworld";
    TEST_ASSERT_EQUAL_STR(expected_with_content, result_with_content, num_tests + 1);
    free(str_with_content);
    num_tests++;

    // Test case for appending a string with spaces to a non-empty string
    char *str_with_spaces = (char *)malloc(11 * sizeof(char)); // Initial size 6 + 5 for " test" + 1 for null terminator
    strcpy(str_with_spaces, "hello");
    int size_with_spaces = 5;
    char *result_with_spaces = concat_string(str_with_spaces, &size_with_spaces, " test");
    const char *expected_with_spaces = "hello test";
    TEST_ASSERT_EQUAL_STR(expected_with_spaces, result_with_spaces, num_tests + 1);
    free(str_with_spaces);
    num_tests++;
    
    // Single-digit positive number
    char *result_single_digit_test = int_between_parenthesis(5);
    const char *expected_single_digit_test = "(5) ";
    TEST_ASSERT_EQUAL_STR(expected_single_digit_test, result_single_digit_test, num_tests + 1);
    free(result_single_digit_test);
    num_tests++;

    // Multi-digit positive number
    char *result_multi_digit_test = int_between_parenthesis(1234);
    const char *expected_multi_digit_test = "(1234) ";
    TEST_ASSERT_EQUAL_STR(expected_multi_digit_test, result_multi_digit_test, num_tests + 1);
    free(result_multi_digit_test);
    num_tests++;

    // Zero
    char *result_zero_test = int_between_parenthesis(0);
    const char *expected_zero_test = "(0) ";
    TEST_ASSERT_EQUAL_STR(expected_zero_test, result_zero_test, num_tests + 1);
    free(result_zero_test);
    num_tests++;

    // Negative number
    char *result_negative_test = int_between_parenthesis(-567);
    const char *expected_negative_test = "(-567) ";
    TEST_ASSERT_EQUAL_STR(expected_negative_test, result_negative_test, num_tests + 1);
    free(result_negative_test);
    num_tests++;

    // Large number
    char *result_large_number_test = int_between_parenthesis(1000000);
    const char *expected_large_number_test = "(1000000) ";
    TEST_ASSERT_EQUAL_STR(expected_large_number_test, result_large_number_test, num_tests + 1);
    free(result_large_number_test);
    num_tests++;

    // Valid swap test
    int arr_size = 3;
    Card *card_array = malloc(arr_size * sizeof(Card));
    
    card_array[0].color = RED;
    card_array[0].numberAction.number = 1;
    card_array[0].isNumber = true;

    card_array[1].color = GREEN;
    card_array[1].numberAction.number = 2;
    card_array[1].isNumber = true;

    card_array[2].color = BLUE;
    card_array[2].numberAction.number = 3;
    card_array[2].isNumber = true;

    swap(card_array, 0, 2);

    // Assertion
    TEST_ASSERT_EQUAL(3, card_array[0].numberAction.number, num_tests);  // Esperado 3
    TEST_ASSERT_EQUAL(2, card_array[1].numberAction.number, num_tests);  // Esperado 2
    TEST_ASSERT_EQUAL(1, card_array[2].numberAction.number, num_tests);  // Esperado 1
    num_tests++;

    // Memory free
    free(card_array);

    // Test with a disorganized array
    int sort_cards_size = 4;
    Card *sort_cards_array = malloc(sort_cards_size * sizeof(Card));

    // Initializing the card array
    sort_cards_array[0].color = BLUE;
    sort_cards_array[0].numberAction.number = 5;
    sort_cards_array[0].isNumber = true;

    sort_cards_array[1].color = GREEN;
    strcpy(sort_cards_array[1].numberAction.action, "A");
    sort_cards_array[1].isNumber = false;

    sort_cards_array[2].color = GREEN;
    sort_cards_array[2].numberAction.number = 3;
    sort_cards_array[2].isNumber = true;

    sort_cards_array[3].color = BLUE;
    strcpy(sort_cards_array[3].numberAction.action, "B");
    sort_cards_array[3].isNumber = false;

    // Expected sorting
    Card expected_sorted_array[] = {
        {GREEN, .numberAction.number = 3, .isNumber = true},
        {GREEN, .numberAction.action = "A", .isNumber = false},
        {BLUE, .numberAction.number = 5, .isNumber = true},
        {BLUE, .numberAction.action = "B", .isNumber = false}
    };

    sort_cards(sort_cards_array, sort_cards_size);

    // Assertions
    TEST_ASSERT_CARD_ARRAYS_EQUAL(expected_sorted_array, sort_cards_size, sort_cards_array, sort_cards_size, num_tests);

    num_tests++;

    // Memory free
    free(sort_cards_array);

    // Test when both cards have the same color
    Card card1_match = {RED, .numberAction.number = 5, .isNumber = true};
    Card card2_match = {RED, .numberAction.number = 7, .isNumber = true};
    bool result_match = is_color_match(card1_match, card2_match);
    TEST_ASSERT_EQUAL(true, result_match, num_tests);
    num_tests++;

    // Test when both cards have different colors
    Card card1_no_match = {BLUE, .numberAction.number = 5, .isNumber = true};
    Card card2_no_match = {GREEN, .numberAction.number = 7, .isNumber = true};
    bool result_no_match = is_color_match(card1_no_match, card2_no_match);
    TEST_ASSERT_EQUAL(false, result_no_match, num_tests);
    num_tests++;

    // Test when one card has an action and another card has a number (should not affect color comparison)
    Card card1_action = {YELLOW, .numberAction.action = "block", .isNumber = false};
    Card card2_number = {YELLOW, .numberAction.number = 5, .isNumber = true};
    bool result_action_number = is_color_match(card1_action, card2_number);
    TEST_ASSERT_EQUAL(true, result_action_number, num_tests);
    num_tests++;

    // Test when one card has an action and another card has a different color
    Card card1_action_diff_color = {YELLOW, .numberAction.action = "+2", .isNumber = false};
    Card card2_diff_color = {WILD, .numberAction.number = 5, .isNumber = true};
    bool result_action_diff_color = is_color_match(card1_action_diff_color, card2_diff_color);
    TEST_ASSERT_EQUAL(false, result_action_diff_color, num_tests);
    num_tests++;

    // Test when both cards have the same number and are numbers
    Card number_match_card1_match = {RED, .numberAction.number = 5, .isNumber = true};
    Card number_match_card2_match = {GREEN, .numberAction.number = 5, .isNumber = true};
    bool number_match_result_match = is_number_match(number_match_card1_match, number_match_card2_match);
    TEST_ASSERT_EQUAL(true, number_match_result_match, num_tests);
    num_tests++;

    // Test when both cards have different numbers but are numbers
    Card number_match_card1_no_match = {RED, .numberAction.number = 5, .isNumber = true};
    Card number_match_card2_no_match = {BLUE, .numberAction.number = 7, .isNumber = true};
    bool number_match_result_no_match = is_number_match(number_match_card1_no_match, number_match_card2_no_match);
    TEST_ASSERT_EQUAL(false, number_match_result_no_match, num_tests);
    num_tests++;

    // Test when one card is a number and the other is an action
    Card number_match_card1_action = {YELLOW, .numberAction.number = 5, .isNumber = true};
    Card number_match_card2_action = {RED, .numberAction.action = "block", .isNumber = false};
    bool number_match_result_action = is_number_match(number_match_card1_action, number_match_card2_action);
    TEST_ASSERT_EQUAL(false, number_match_result_action, num_tests);
    num_tests++;

    // Test when neither card is a number
    Card number_match_card1_not_number = {GREEN, .numberAction.action = "+2", .isNumber = false};
    Card number_match_card2_not_number = {BLUE, .numberAction.action = "reverse", .isNumber = false};
    bool number_match_result_not_number = is_number_match(number_match_card1_not_number, number_match_card2_not_number);
    TEST_ASSERT_EQUAL(false, number_match_result_not_number, num_tests);
    num_tests++;

    // Test when only one card is a number
    Card number_match_card1_one_number = {YELLOW, .numberAction.number = 5, .isNumber = true};
    Card number_match_card2_one_not_number = {RED, .numberAction.action = "block", .isNumber = false};
    bool number_match_result_one_number = is_number_match(number_match_card1_one_number, number_match_card2_one_not_number);
    TEST_ASSERT_EQUAL(false, number_match_result_one_number, num_tests);
    num_tests++;

    // Test when both cards have the same action and are not numbers
    Card action_match_card1_action_match = {RED, .numberAction.action = "block", .isNumber = false};
    Card action_match_card2_action_match = {GREEN, .numberAction.action = "block", .isNumber = false};
    bool action_match_result_action_match = is_action_match(action_match_card1_action_match, action_match_card2_action_match);
    TEST_ASSERT_EQUAL(true, action_match_result_action_match, num_tests);
    num_tests++;

    // Test when both cards have different actions but are not numbers
    Card action_match_card1_action_no_match = {RED, .numberAction.action = "block", .isNumber = false};
    Card action_match_card2_action_no_match = {GREEN, .numberAction.action = "Reverse", .isNumber = false};
    bool action_match_result_action_no_match = is_action_match(action_match_card1_action_no_match, action_match_card2_action_no_match);
    TEST_ASSERT_EQUAL(false, action_match_result_action_no_match, num_tests);
    num_tests++;

    // Test when one card is a number and the other is an action
    Card action_match_card1_action = {YELLOW, .numberAction.action = "block", .isNumber = false};
    Card action_match_card2_number_diff = {RED, .numberAction.number = 5, .isNumber = true};
    bool action_match_result_mixed = is_action_match(action_match_card1_action, action_match_card2_number_diff);
    TEST_ASSERT_EQUAL(false, action_match_result_mixed, num_tests);
    num_tests++;

    // Test when neither card has an action (both are numbers)
    Card action_match_card1_number = {GREEN, .numberAction.number = 5, .isNumber = true};
    Card action_match_card2_number = {BLUE, .numberAction.number = 7, .isNumber = true};
    bool action_match_result_no_action = is_action_match(action_match_card1_number, action_match_card2_number);
    TEST_ASSERT_EQUAL(false, action_match_result_no_action, num_tests);
    num_tests++;

    // Test when neither card is an action (one or both are actions)
    Card action_match_card1_no_action = {YELLOW, .numberAction.action = "Draw", .isNumber = false};
    Card action_match_card2_no_action = {BLUE, .numberAction.action = "bl", .isNumber = false};
    bool result_one_action = is_action_match(action_match_card1_no_action, action_match_card2_no_action);
    TEST_ASSERT_EQUAL(false, result_one_action, num_tests);
    num_tests++;

    // Test when the card color is WILD
    Card card_wild = {WILD, .numberAction.number = 0, .isNumber = true};
    bool result_wild = is_wild_card(card_wild);
    TEST_ASSERT_EQUAL(true, result_wild, num_tests);
    num_tests++;

    // Test when the card color is RED
    Card card_red = {RED, .numberAction.number = 5, .isNumber = true};
    bool result_red = is_wild_card(card_red);
    TEST_ASSERT_EQUAL(false, result_red, num_tests);
    num_tests++;

    // Test when the card color is GREEN
    Card card_green = {GREEN, .numberAction.number = 10, .isNumber = false};
    bool result_green = is_wild_card(card_green);
    TEST_ASSERT_EQUAL(false, result_green, num_tests);
    num_tests++;

    // Test when the card color is BLUE
    Card card_blue = {BLUE, .numberAction.action = "Draw", .isNumber = false};
    bool result_blue = is_wild_card(card_blue);
    TEST_ASSERT_EQUAL(false, result_blue, num_tests);
    num_tests++;

    // Test when the card color is YELLOW
    Card card_yellow = {YELLOW, .numberAction.number = 7, .isNumber = true};
    bool result_yellow = is_wild_card(card_yellow);
    TEST_ASSERT_EQUAL(false, result_yellow, num_tests);
    num_tests++;

    // Test when the number is within the interval
    TEST_ASSERT_EQUAL(true, is_in_interval(5, 1, 10), num_tests);
    num_tests++;

    // Test when the number is exactly equal to the minimum boundary
    TEST_ASSERT_EQUAL(true, is_in_interval(1, 1, 10), num_tests);
    num_tests++;

    // Test when the number is exactly equal to the maximum boundary
    TEST_ASSERT_EQUAL(true, is_in_interval(10, 1, 10), num_tests);
    num_tests++;

    // Test when the number is below the minimum boundary
    TEST_ASSERT_EQUAL(false, is_in_interval(0, 1, 10), num_tests);
    num_tests++;

    // Test when the number is above the maximum boundary
    TEST_ASSERT_EQUAL(false, is_in_interval(11, 1, 10), num_tests);
    num_tests++;

    // Test when the number is equal to the minimum and maximum boundary (same boundary)
    TEST_ASSERT_EQUAL(true, is_in_interval(5, 5, 5), num_tests);
    num_tests++;

    // Define some cards for testing
    Card card_red_5 = { RED, { .number = 5 }, true };
    Card card_green_5 = { GREEN, { .number = 5 }, true };
    Card card_red_block = { RED, { .action = "block" }, false };
    Card card_wild_change = { WILD, { .action = "change" }, false };
    Card card_wild_draw_four = { WILD, { .action = "+4" }, false };

    // Test matching colors
    TEST_ASSERT_EQUAL(true, can_play_card(card_red_5, card_green_5, RED), num_tests);
    num_tests++;

    // Test matching numbers
    TEST_ASSERT_EQUAL(true, can_play_card(card_red_5, card_red_5, GREEN), num_tests);
    num_tests++;

    // Test matching actions
    TEST_ASSERT_EQUAL(true, can_play_card(card_red_block, card_red_block, GREEN), num_tests);
    num_tests++;

    // Test wild card
    TEST_ASSERT_EQUAL(true, can_play_card(card_wild_change, card_red_5, GREEN), num_tests);
    num_tests++;

    // Test when top card is wild and chosen card color matches
    TEST_ASSERT_EQUAL(true, can_play_card(card_red_5, card_wild_change, RED), num_tests);
    num_tests++;

    // Test when top card is wild and chosen card color does not match
    TEST_ASSERT_EQUAL(false, can_play_card(card_green_5, card_wild_change, RED), num_tests);
    num_tests++;

    // Test matching number with wild card top card
    TEST_ASSERT_EQUAL(true, can_play_card(card_green_5, card_wild_change, GREEN), num_tests);
    num_tests++;

    // Test matching actions with wild card top card
    TEST_ASSERT_EQUAL(true, can_play_card(card_red_block, card_wild_change, RED), num_tests);
    num_tests++;

    // Test cannot play when no conditions match
    TEST_ASSERT_EQUAL(false, can_play_card(card_red_5, card_wild_draw_four, GREEN), num_tests);
    num_tests++;

    // Test matching wild draw four card
    TEST_ASSERT_EQUAL(true, can_play_card(card_wild_draw_four, card_wild_draw_four, GREEN), num_tests);
    num_tests++;    

    // Initial setup for testing
    int size = 0;
    Card *cards = NULL;

    // Define some cards for testing
    Card push_test_card_red_5 = { RED, { .number = 5 }, true };
    Card push_test_card_green_5 = { GREEN, { .number = 5 }, true };
    Card push_test_card_blue_7 = { BLUE, { .number = 7 }, true };
    Card push_test_card_red_skip = { RED, { .action = "block" }, false };

    // Test adding a single card
    cards = push_card(cards, &size, push_test_card_red_5);
    TEST_ASSERT_EQUAL(1, size, num_tests);
    TEST_ASSERT_CARD_ARRAYS_EQUAL(&push_test_card_red_5, 1, cards, 1, num_tests);
    num_tests++;

    // Test adding another card and sorting
    cards = push_card(cards, &size, push_test_card_blue_7);
    Card sorted_cards_2[] = { push_test_card_red_5, push_test_card_blue_7 };
    TEST_ASSERT_EQUAL(2, size, num_tests);
    TEST_ASSERT_CARD_ARRAYS_EQUAL(sorted_cards_2, 2, cards, 2, num_tests);
    num_tests++;

    // Test adding a card with the same color but different number
    cards = push_card(cards, &size, push_test_card_green_5);
    Card sorted_cards_3[] = { push_test_card_red_5, push_test_card_green_5, push_test_card_blue_7 };
    TEST_ASSERT_EQUAL(3, size, num_tests);
    TEST_ASSERT_CARD_ARRAYS_EQUAL(sorted_cards_3, 3, cards, 3, num_tests);
    num_tests++;

    // Test adding a card with different color and action
    cards = push_card(cards, &size, push_test_card_red_skip);
    Card sorted_cards_4[] = { push_test_card_red_5, push_test_card_red_skip, push_test_card_green_5, push_test_card_blue_7 };
    TEST_ASSERT_EQUAL(4, size, num_tests);
    TEST_ASSERT_CARD_ARRAYS_EQUAL(sorted_cards_4, 4, cards, 4, num_tests);
    num_tests++;

    // Test memory allocation failure (simulated by not freeing memory)
    // In practice, use a debugger or tool to simulate allocation failures.

    // Free allocated memory
    free(cards);

    // Teardown
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("SUCCESS\n%d Test(s) passed in %f seconds\n", num_tests, time);
}

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void show_card_error_message(const char *error_message, const Card card_expected, const Card card_result)
{
    printf("[ERROR]: %s.\n", error_message);
    printf("Expected:\n");
    printf("Cor: %d, ", card_expected.color);
    if (card_expected.isNumber)
    {
        printf("Número: %d\n", card_expected.numberAction.number);
    }
    else
    {
        printf("Ação: %s\n", card_expected.numberAction.action);
    }
    printf("Result:\n");
    printf("Cor: %d, ", card_result.color);
    if (card_result.isNumber)
    {
        printf("Número: %d\n", card_result.numberAction.number);
    }
    else
    {
        printf("Ação: %s\n", card_result.numberAction.action);
    }
    exit(1);
}

void show_home_screen()
{
    printf("Bem-vindo ao UNO_C!\n");
    printf("Pressione qualquer tecla para continuar!");

    getchar();

    transition(MAIN_MENU);
}

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

void show_new_game_screen()
{
    clear_input_buffer();

    char **history = NULL;
    int history_size = 0, num_cards_player = INITIAL_NUMBER_CARDS, num_cards_oponent = INITIAL_NUMBER_CARDS;
    Card *player_cards = get_player_cards();
    Card *oponent_cards = get_player_cards();
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

    show_game_screen(&history, &history_size, player_cards, &num_cards_player, oponent_cards, &num_cards_oponent, &top_card, &chosen_color);

    free(history);
    free(player_cards);
}

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

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // It just keeps reading and discarding characters
    }
}

void sleep_time(int milliseconds)
{
    usleep(milliseconds * 100);
}

void transition(int next_screen)
{
    clear_screen();
    sleep_time(TRANSITION_TIME);
    state = next_screen;
}

void stylized_print(char *message, int n, ...)
{
    va_list list;
    va_start(list, n);
    for (int i = 0; i < n; i++)
    {
        char *arg = va_arg(list, char *);
        printf("%s", arg);
    }
    printf("%s" RESET, message);

    va_end(list);
}

void print_bold(char *message)
{
    stylized_print(message, 1, BOLD);
}

void print_history(char **messages, int messages_length)
{
    messages = reverse(messages, messages_length);

    print_line();

    for (int i = 2; i >= 0; i--)
    {
        if (i <= messages_length - 1)
        {
            print_line_with_prefix("", messages[i], RESET);
        }
        else
        {
            print_line_with_prefix("", "", RESET);
        }
    }

    print_line();
}

void print_line()
{
    for (int i = 0; i < SCREEN_LENGTH; i++)
    {
        printf("*");
    }
    printf("\n");
}

// essa função não precisa de realocaçaõ nem de alocação
char **reverse(char **arr, int len)
{
    if (arr == NULL || len == 0)
        return NULL;

    char **reversed_array = (char **)malloc(len * sizeof(char *));

    for (int i = 0; i < len; i++)
    {
        reversed_array[i] = arr[len - 1 - i];
    }

    return reversed_array;
}

void print_game(char **messages, int messages_length, Card top_card, int num_oponent_cards, Card *player_cards, int num_player_cards)
{
    clear_screen();
    print_history(messages, messages_length);
    print_table(top_card);
    print_hands(num_oponent_cards, player_cards, num_player_cards);

    sleep_time(TRANSITION_TIME * 2);
}

void print_table(Card top_card)
{
    print_line();

    char *color_card = get_color_name(top_card.color);
    char *ansi_color = get_color_ansi(top_card.color);

    int numberAction_length = 0;
    char *numberAction_str;

    if (top_card.isNumber)
    {
        numberAction_length = count_digits(top_card.numberAction.number);
        numberAction_str = int_to_string(top_card.numberAction.number);
    }
    else
    {
        numberAction_length = strlen(top_card.numberAction.action);
        numberAction_str = (char *)malloc((numberAction_length + 1) * sizeof(char));
        strncpy(numberAction_str, top_card.numberAction.action, numberAction_length);
        numberAction_str[numberAction_length] = '\0';
    }

    int card_string_length = strlen(color_card) + 1 + numberAction_length + 1;
    char *card_string = (char *)malloc(card_string_length + 1);
    sprintf(card_string, "%s %s", color_card, numberAction_str);

    print_line_with_prefix("Topo: ", card_string, ansi_color);

    print_line();

    free(numberAction_str);
    free(card_string);
}

void print_line_with_prefix(char *prefix, const char *color_card, const char *ansi_color)
{
    int prefix_len = strlen(prefix);
    int card_len = color_card != NULL ? strlen(color_card) : 0;

    for (int j = 0; j < SCREEN_LENGTH; j++)
    {
        if (j == 0 || j == SCREEN_LENGTH - 1)
        {
            printf("*");
            if (j == SCREEN_LENGTH - 1)
            {
                printf("\n");
            }
        }
        else if (j == 1 || j == SCREEN_LENGTH - 2)
        {
            printf(" ");
        }
        else
        {
            if (j - 2 < prefix_len)
            {
                printf("%c", prefix[j - 2]);
            }
            else if (color_card != NULL && j - 2 < prefix_len + card_len)
            {
                printf("%s%c%s", ansi_color, color_card[j - 2 - prefix_len], RESET);
            }
            else
            {
                printf(" ");
            }
        }
    }
}

// When this function is called, the deck size will always be equivalent to the maximum card size
Card get_card_for_table()
{
    Card filtered[deck_size];
    int filtered_size = 0;

    for (int i = 0; i < deck_size; i++)
    {
        if (is_normal_card(deck[i]))
        {
            filtered[filtered_size++] = deck[i];
        }
    }

    if (filtered_size == 0)
    {
        printf("[ERROR]: Nenhuma carta correspondente.");
        exit(1);
    }

    int random_index = random_array_index(filtered_size);
    Card selected_card = filtered[random_index];

    // Tem que remover a carta da mesa do deck
    int corresponding_index = -1;
    for (int i = 0; i < deck_size; i++)
    {
        Card current_card = deck[i];

        if ((current_card.color == selected_card.color) && current_card.isNumber && (current_card.numberAction.number == selected_card.numberAction.number))
        {
            corresponding_index = i;
            break;
        }
    }

    if (corresponding_index == -1)
    {
        printf("[ERROR]: Índice correspondente não encontrado.");
        exit(1);
    }

    // Compaction & Left Shifting
    deck = compaction(deck, &deck_size, corresponding_index);

    return selected_card;
}

char *get_color_name(Color color)
{
    if (is_invalid_color(color))
        return "Invalid";

    return color_mapper[color];
}

char *get_color_ansi(Color color)
{
    if (is_invalid_color(color))
        return RESET;

    switch (color)
    {
    case 0:
        return ANSI_RED;
    case 1:
        return ANSI_GREEN;
    case 2:
        return ANSI_BLUE;
    case 3:
        return ANSI_YELLOW;
    default:
        return RESET;
    }
}

bool is_normal_card(Card card)
{
    return (card.color != WILD && card.isNumber == true && 0 <= card.numberAction.number && card.numberAction.number < 10);
}

bool is_invalid_color(Color color)
{
    return (color < 0 || color > 4);
}

bool are_arrays_equal(const char **arr1, int len1, const char **arr2, int len2)
{
    if (len1 != len2)
        return false;

    for (int i = 0; i < len1; i++)
    {
        if (strcmp(arr1[i], arr2[i]) != 0)
            return false;
    }

    return true;
}

bool are_card_arrays_equal(Card *arr1, int len1, Card *arr2, int len2)
{
    if (len1 != len2)
        return false;

    for (int i = 0; i < len1; i++)
    {
        if (arr1[i].color != arr2[i].color ||
            arr1[i].isNumber != arr2[i].isNumber ||
            (arr1[i].isNumber && arr1[i].numberAction.number != arr2[i].numberAction.number) ||
            (!arr1[i].isNumber && strcmp(arr1[i].numberAction.action, arr2[i].numberAction.action) != 0))
        {
            return false;
        }
    }

    return true;
}

void show_tests_error_message(int num_test)
{
    printf("[ERROR] Test %d failed.\n", num_test);
    exit(1);
}

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

void print_hands(int num_oponent_cards, Card *player_cards, int num_player_cards)
{
    // Oponent hand
    print_line();

    print_oponent_cards(num_oponent_cards);
    print_player_cards(player_cards, num_player_cards);

    print_line();
}

char *int_between_parenthesis(int number)
{
    int digits = count_digits(number);

    char *str = (char *)malloc((digits + 4) * sizeof(char));

    sprintf(str, "(%d) ", number);

    return str;
}

int count_digits(int number)
{
    int count = 0;

    if (number == 0)
        return 1;

    while (number != 0)
    {
        number /= 10;
        count++;
    }

    return count;
}

char *int_to_string(int number)
{
    int digits = count_digits(number);
    char *str = (char *)malloc((digits + 1) * sizeof(char));

    sprintf(str, "%d", number);

    return str;
}

char *concat_char(char *str, int *str_size, char ch)
{
    // char* new_str = (char*) realloc(str, (*str_size + 1) * sizeof(char));
    str[*str_size] = ch;
    (*str_size)++;
    str[*str_size] = '\0';

    return str;
}

char *concat_string(char *str, int *str_size, char *suffix)
{
    int suffix_size = strlen(suffix);

    strcpy(str + *str_size, suffix);

    *str_size += suffix_size;

    return str;
}

Card *get_player_cards()
{
    Card *player_cards = (Card *)malloc(INITIAL_NUMBER_CARDS * sizeof(Card));

    if (player_cards == NULL)
    {
        printf("Erro ao alocar memória.");
        exit(1);
    }

    for (int i = 0; i < INITIAL_NUMBER_CARDS; i++)
    {
        int random_index = random_array_index(deck_size);
        player_cards[i] = deck[random_index];
        deck = compaction(deck, &deck_size, random_index);
    }

    return player_cards;
}

int random_array_index(int arr_size)
{
    return rand() % arr_size;
}

Card *compaction(Card *arr, int *arr_size, int hole)
{
    if (hole < 0 || hole >= *arr_size)
    {
        return arr;
    }

    int new_size = *arr_size - 1;

    for (int i = hole; i < new_size; i++)
    {
        arr[i] = arr[i + 1];
    }

    Card *temp = (Card *)realloc(arr, new_size * sizeof(Card));

    if (temp == NULL && new_size > 0)
    {
        printf("[ERROR]: Falha ao realocar memória.\n");
        exit(1);
    }

    *arr_size = new_size;
    return temp;
}

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

int compare_cards(Card card1, Card card2)
{
    if (card1.isNumber && card2.isNumber)
    {
        return card1.numberAction.number - card2.numberAction.number;
    }
    else if (!card1.isNumber && !card2.isNumber)
    {
        return strcmp(card1.numberAction.action, card2.numberAction.action);
    }
    else
    {
        return card2.isNumber - card1.isNumber;
    }
}

void swap(Card *arr, int i, int j)
{
    Card temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort_cards(Card *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].color > arr[j + 1].color ||
                (arr[j].color == arr[j + 1].color && compare_cards(arr[j], arr[j + 1]) > 0))
            {
                swap(arr, j, j + 1);
            }
        }
    }
}

void print_strs(char **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        printf("%s\n", matrix[i]);
    }
}

void print_oponent_cards(int num_cards)
{
    char *oponent_hand = (char *)malloc((2 * num_cards + 3) * sizeof(char));
    int current_str_oponent_length = 0;

    strcpy(oponent_hand + current_str_oponent_length, "[ ");
    current_str_oponent_length += 2;

    for (int i = 0; i < num_cards; i++)
    {
        strcpy(oponent_hand + current_str_oponent_length, "x ");
        current_str_oponent_length += 2;
    }

    strcpy(oponent_hand + current_str_oponent_length, "]");
    current_str_oponent_length += 1;

    print_line_with_prefix("Oponente: ", oponent_hand, RESET);

    free(oponent_hand);
}

void print_player_cards(Card *cards, int num_cards)
{
    for (int i = 0; i < num_cards; i++)
    {
        // String to each player card
        int card_index = i + 1;
        int digits = count_digits(card_index);
        int color_length = strlen(color_mapper[cards[i].color]);
        int current_str_player_length = 0;
        int number_action_length = 0;

        char card_index_str[digits + 1];

        Card current_player_card = cards[i];

        number_action_length = current_player_card.isNumber ? 1 : strlen(current_player_card.numberAction.action);

        char *number_str = int_to_string(current_player_card.numberAction.number);
        /*
         * Example: "Vermelho 9\0" = 11
         * = [color.length] + 1 + [numberAction.length] + 1
         * = [color.length] + [numberAction.length] + 2
         */
        char *current_card = (char *)malloc((color_length + number_action_length + 2) * sizeof(char));

        current_card = concat_string(current_card, &current_str_player_length, color_mapper[current_player_card.color]);

        current_card = concat_char(current_card, &current_str_player_length, ' ');

        if (current_player_card.isNumber)
        {
            current_card = concat_string(current_card, &current_str_player_length, number_str);
        }
        else
        {
            current_card = concat_string(current_card, &current_str_player_length, current_player_card.numberAction.action);
        }

        char *preffix = int_between_parenthesis(card_index);
        print_line_with_prefix(preffix, current_card, get_color_ansi(current_player_card.color));

        free(current_card);
        free(number_str);
    }
}

Card play_card(Card **cards, int *cards_size, Card *top_card, Color chosen_color, bool *player_played)
{
    bool was_valid_play = false, was_last_entry_invalid = false;
    int choice = 0;

    while (!was_valid_play)
    {
        printf("Qual carta você quer jogar? ");
        scanf("%d", &choice);

        if (choice < 1 || choice > *cards_size)
        {
            if (choice == -1) {
                
                *cards = push_card(*cards, cards_size, draw_card());
                *player_played = false;
                return (Card) { WILD, {.action = ""}, false };
            }
            
            handle_invalid_choice(&was_last_entry_invalid, "Esta carta não está na sua mão.");
        }
        else
        {
            Card chosen_card = (*cards)[choice - 1];
            if (can_play_card(chosen_card, *top_card, chosen_color))
            {
                was_valid_play = true;
            }
            else
            {
                handle_invalid_choice(&was_last_entry_invalid, "Essa carta não pode ser jogada.");
            }
        }
    };

    Card selected_card = (*cards)[choice - 1];
    *cards = compaction(*cards, cards_size, choice - 1);
    *player_played = true;
    return selected_card;
}

void delete_last_line()
{
    printf("\033[F");
    printf("\033[K");
}

void delete_lines_by_errors(bool was_last_entry_invalid)
{
    if (was_last_entry_invalid)
        delete_last_line();
    delete_last_line();
}

void show_game_screen(char ***history, int *history_size, Card *player_cards, int *num_player_cards, Card *oponent_cards, int *num_oponent_cards, Card *top_card, Color *chosen_color)
{
    print_game(*history, *history_size, *top_card, *num_oponent_cards, player_cards, *num_player_cards);

    bool player_played = true;
    Card played_card = play_card(&player_cards, num_player_cards, top_card, *chosen_color, &player_played);
    check_play(played_card, chosen_color, player_played);
    update_table(top_card, played_card, player_played);
    update_history(*top_card, *chosen_color, history, history_size, true, player_played);

    bool oponent_played = false;
    Card oponent_played_card = oponent_play(&oponent_cards, num_oponent_cards, *top_card, *chosen_color, &oponent_played);
    check_oponent_play(oponent_played_card, chosen_color, oponent_played);
    update_table(top_card, oponent_played_card, oponent_played);
    update_history(*top_card, *chosen_color, history,  history_size, false, oponent_played);

    show_game_screen(history, history_size, player_cards, num_player_cards, oponent_cards, num_oponent_cards, top_card, chosen_color);

    getchar();
}

void update_table(Card *current, Card new_card, bool played)
{
    if (played) *current = new_card;
}

Card oponent_play(Card **cards, int *num_cards, Card top_card, Color chosen_color, bool *oponent_played)
{
    for (int i = 0; i < *num_cards; i++)
    {
        Card current_card = (*cards)[i];
        if (can_play_card(current_card, top_card, chosen_color))
        {
            *cards = compaction(*cards, num_cards, i);
            *oponent_played = true;
            return current_card;
        }
    }
    
    *cards = push_card(*cards, num_cards, draw_card());
    *oponent_played = false;
    return (Card) { WILD, {.action = ""}, false };
}

bool is_color_match(Card card1, Card card2)
{
    return card1.color == card2.color;
}

bool is_number_match(Card card1, Card card2)
{
    return card1.isNumber && card2.isNumber && card1.numberAction.number == card2.numberAction.number;
}

bool is_action_match(Card card1, Card card2)
{
    return !card1.isNumber && !card2.isNumber && strcmp(card1.numberAction.action, card2.numberAction.action) == 0;
}

bool is_wild_card(Card card)
{
    return card.color == WILD;
}

void handle_invalid_choice(bool *was_last_entry_invalid, char *message)
{
    delete_lines_by_errors(*was_last_entry_invalid);
    *was_last_entry_invalid = true;
    printf("%s\n", message);
}

bool can_play_card(Card chosen, Card top_card, Color chosen_color)
{
    if (
        is_color_match(chosen, top_card) ||
        is_number_match(chosen, top_card) ||
        is_action_match(chosen, top_card) ||
        is_wild_card(chosen) ||
        (is_wild_card(top_card) && chosen.color == chosen_color)
    )
    {
        return true;
    }

    return false;
}

void check_play(Card card, Color *chosen_color, bool player_played)
{
    if (player_played) {
        if (is_wild_card(card))
        {
            bool was_last_entry_invalid = false, was_valid_play = false;
            int selected_color = 0;

            while (!was_valid_play)
            {
                printf("Qual cor você escolhe?\n");
                printf("[1] Vermelho\n");
                printf("[2] Verde\n");
                printf("[3] Azul\n");
                printf("[4] Amarelo\n");
                scanf("%d", &selected_color);

                if (is_in_interval(selected_color, 1, 4))
                {
                    *chosen_color = (Color)(selected_color - 1);
                    was_valid_play = true;
                }
                else
                {
                    handle_invalid_choice(&was_last_entry_invalid, "Essa não é uma cor válida!");
                }
            }
        }
        else
        {
            // If it's not a special card, the color chosen is the same as the card
            *chosen_color = card.color;
        }
    }
}

bool is_in_interval(int number, int min, int max)
{
    return min <= number && number <= max;
}

void update_history(Card top_card, Color chosen_color, char ***history, int *history_size, bool is_player, bool played)
{
    if (played) {
        char *played_message = is_player ? "Voce jogou uma carta" : "Oponente jogou uma carta";
        *history = push_history(*history, history_size, played_message);
    
        if (is_wild_card(top_card))
        {
            char *preffix = is_player ? "Voce escolheu a cor:" : "Oponente escolheu a cor:";
            char *color_name = get_color_name(chosen_color);
            int message_size = strlen(preffix) + strlen(color_name) + 2;
            char *message = malloc(message_size * sizeof(char));
            sprintf(message, "%s %s", preffix, color_name);

            *history = push_history(*history, history_size, message);

            free(message);
        }
    } else {
        char *message = is_player ? "Voce puxou uma carta" : "Oponente puxou uma carta";
        *history = push_history(*history, history_size, message);
    }
}

void check_oponent_play(Card card, Color *chosen_color, bool oponent_played) {
    if (oponent_played) {
        if (is_wild_card(card)) {
            int random_color = random_array_index(4);
            *chosen_color = random_color;
        } else {
            *chosen_color = card.color;
        }
    }
}

void print_card(Card card) {
    const char *colors[] = { "RED", "GREEN", "BLUE", "YELLOW", "WILD" };
    printf("Card: color=%s, ", colors[card.color]);
    if (card.isNumber) {
        printf("number=%d", card.numberAction.number);
    } else {
        printf("action=%s", card.numberAction.action);
    }
    printf(", isNumber=%d\n", card.isNumber);
}

void print_opponent(Card *cards, int num_cards) {
    printf("Cartas do oponente:\n");
    for (int i = 0; i < num_cards; i++) {
        print_card(cards[i]);
    }
    printf("\n");
}

Card *push_card(Card *cards, int *size, Card new_card) {
    Card *temp = realloc(cards, (*size + 1) * sizeof(Card));
    
    if (temp == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }
    
    temp[*size] = new_card;
    (*size)++;
    
    sort_cards(temp, *size);
    
    return temp;
}

Card draw_card() {
    int random_index = random_array_index(deck_size);
    
    Card random_card = deck[random_index];
    
    deck = compaction(deck, &deck_size, random_index);
    
    return random_card;
}

void initialize_random() {
    srand(time(NULL));
}

void print_str_arr(char **arr, int arr_size) {
    if (arr == NULL || arr_size <= 0) {
        printf("Array is empty or NULL.\n");
        return;
    }

    printf("Array of strings (%d elements):\n", arr_size);
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] != NULL) {
            printf("[%d]: %s\n", i, arr[i]);
        } else {
            printf("[%d]: NULL\n", i);
        }
    }
}
