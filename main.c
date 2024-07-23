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

#define TEST_ASSERT_EQUAL_STR(expected, actual, test_num)                                                 \
    if (strcmp(expected, actual) != 0)                                                                    \
    {                                                                                                     \
        printf("ERROR: Teste %d falhou. Esperado: \"%s\", Obtido: \"%s\"\n", test_num, expected, actual); \
        exit(1);                                                                                          \
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

void show_new_game_screen(Card *deck, int *deck_size);

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
void reverse(char **arr, int len);

/**
 * @brief Retrieves a random normal card from the deck and removes it from the deck.
 *
 * @param deck A pointer to the array of cards.
 * @param deck_size A pointer to the size of the deck (number of elements).
 * @return The selected card that is removed from the deck.
 *
 * @note If no matching card is found, the function terminates with an error message.
 */

Card get_card_for_table(Card **deck, int *deck_size);

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
 * @param deck      Pointer to a pointer to an array of Card structures representing the deck.
 *                  Upon returning, this pointer is updated to reflect the compacted deck.
 * @param deck_size Pointer to an integer representing the current size of the deck.
 *                  Upon returning, this value is updated to reflect the reduced size of the deck.
 * @return          Pointer to an array of Card structures representing the player's cards.
 *                  Memory is dynamically allocated for this array. The caller is responsible for freeing
 *                  this memory when no longer needed.
 *
 * @note Memory is allocated for the player's card array dynamically.
 */
Card *get_player_cards(Card **deck, int *deck_size);

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
void compaction(Card *arr, int *arr_size, int hole);

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

void str_compaction(char **arr, int *arr_size, int hole);

int state = HOME;

int main()
{
    run_tests();

    Card *deck = create_deck();
    int deck_size = MAX_CARDS;

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
            show_new_game_screen(deck, &deck_size);
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

    // "reverse" function test
    // Test 2
    char *reverse_test[] = {"hello", "world"};
    char *reverse_expected[] = {"world", "hello"};
    reverse(reverse_test, 2);
    for (int i = 0; i < 2; i++)
    {
        printf("%s\n", reverse_test[i]);
    }

    if (!are_arrays_equal((const char **)reverse_expected, 2, (const char **)reverse_test, 2))
    {
        show_tests_error_message(num_tests + 1);
    }

    num_tests++;

    // Test 3
    char *reverse_test2[] = {"one", "two", "three"};
    char *reverse_expected2[] = {"three", "two", "one"};
    reverse(reverse_test2, 3);

    if (!are_arrays_equal((const char **)reverse_expected2, 3, (const char **)reverse_test2, 3))
    {
        show_tests_error_message(num_tests + 1);
    }

    num_tests++;

    // Test 4
    char **reverse_null_test = NULL;
    char **reverse_null_expected = NULL;
    reverse(reverse_null_test, 0);

    if (reverse_null_test != reverse_null_expected)
    {
        show_tests_error_message(num_tests + 1);
    }
    num_tests++;

    // Test 5
    char *reverse_one_element_test[] = {"test"};
    char *reverse_one_element_expected[] = {"test"};
    reverse(reverse_one_element_test, 1);

    if (!are_arrays_equal((const char **)reverse_one_element_expected, 1, (const char **)reverse_one_element_test, 1))
    {
        show_tests_error_message(num_tests + 1);
    }
    num_tests++;

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

void show_new_game_screen(Card *deck, int *deck_size)
{
    clear_input_buffer();

    char **history = NULL;
    int history_size = 0;
    Card *player_cards = get_player_cards(&deck, deck_size);
    sort_cards(player_cards, INITIAL_NUMBER_CARDS);

    history = push_history(history, &history_size, "Pegando carta inicial...");

    Card top_card = get_card_for_table(&deck, deck_size);

    print_game(history, history_size, top_card, 0, player_cards, 0);

    history = push_history(history, &history_size, "Distribuindo cartas...");

    for (int i = 0; i <= INITIAL_NUMBER_CARDS; i++)
    {
        print_game(history, history_size, top_card, i, player_cards, i);
    }

    getchar();

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
    reverse(messages, messages_length);

    print_line();

    for (int i = 3 - 1; i >= 0; i--)
    {
        print_line_with_prefix("", messages[i], RESET);
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
void reverse(char **arr, int len)
{
    if (arr == NULL || len == 0)
        return;

    for (int i = 0; i < len / 2; i++)
    {
        char *temp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = temp;
    }
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

    int number_length = snprintf(NULL, 0, "%d", top_card.numberAction.number);
    char *number_card = (char *)malloc(number_length + 1);
    snprintf(number_card, number_length + 1, "%d", top_card.numberAction.number);

    int card_string_length = strlen(color_card) + 1 + number_length + 1;
    char *card_string = (char *)malloc(card_string_length + 1);
    sprintf(card_string, "%s %s", color_card, number_card);

    print_line_with_prefix("Topo: ", card_string, ansi_color);

    print_line();

    free(number_card);
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
Card get_card_for_table(Card **deck, int *deck_size)
{
    Card filtered[(*deck_size)];
    int filtered_size = 0;

    for (int i = 0; i < *deck_size; i++)
    {
        if (is_normal_card((*deck)[i]))
        {
            filtered[filtered_size++] = (*deck)[i];
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
    for (int i = 0; i < *deck_size; i++)
    {
        Card current_card = (*deck)[i];

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
    compaction(*deck, deck_size, corresponding_index);

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
        free(current_history[0]);
        // Compaction & Left Shifting
        // for (int i = 0; i < *current_size - 1; i++)
        // {
        //     current_history[i] = current_history[i + 1];
        // }
        str_compaction(current_history, current_size, 0);
    }

    current_history[*current_size - 1] = (char *)malloc(strlen(new_message) + 1);

    if (current_history[*current_size - 1] == NULL)
    {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }

    strcpy(current_history[*current_size - 1], new_message);

    return current_history;
}

void print_hands(int num_oponent_cards, Card *player_cards, int num_player_cards)
{
    // Oponent hand
    // Allocation with number of oponent's cards considering spaces and brackets
    char *oponent_hand = (char *)malloc((2 * num_oponent_cards + 3) * sizeof(char *));
    int current_str_oponent_length = 0;

    strcpy(oponent_hand + current_str_oponent_length, "[ ");
    current_str_oponent_length += 2;

    for (int i = 0; i < num_oponent_cards; i++)
    {
        strcpy(oponent_hand + current_str_oponent_length, "x ");
        current_str_oponent_length += 2;
    }

    strcpy(oponent_hand + current_str_oponent_length, "]");
    current_str_oponent_length += 1;

    print_line();
    print_line_with_prefix("Oponente: ", oponent_hand, RESET);

    // Player hand
    for (int i = 0; i < num_player_cards; i++)
    {
        // String to each player card
        int card_index = i + 1;
        int digits = count_digits(card_index);
        int color_length = strlen(color_mapper[player_cards[i].color]);
        int current_str_player_length = 0;
        int number_action_length = 0;

        char card_index_str[digits + 1];

        Card current_player_card = player_cards[i];

        number_action_length = current_player_card.isNumber ? 1 : strlen(current_player_card.numberAction.action);

        char *number_str = int_to_string(current_player_card.numberAction.number);
        /*
         * Example: "Vermelho 9\0" = 11
         * = [color.length] + 1 + [numberAction.length] + 1
         * = [color.length] + [numberAction.length] + 2
         */
        char *current_card = (char *)malloc((color_length + number_action_length + 2) * sizeof(char));

        // printf("length: %d\n", color_length + number_action_length + 2);

        current_card = concat_string(current_card, &current_str_player_length, color_mapper[current_player_card.color]);

        concat_char(current_card, &current_str_player_length, ' ');

        if (current_player_card.isNumber)
        {
            current_card = concat_string(current_card, &current_str_player_length, number_str);
        }
        else
        {
            current_card = concat_string(current_card, &current_str_player_length, current_player_card.numberAction.action);
        }

        // print_player_card(card_index, current_player_card);
        char *preffix = int_between_parenthesis(card_index);
        int preffix_length = (int)(strlen(preffix));
        preffix = concat_char(preffix, &preffix_length, ' ');
        print_line_with_prefix(preffix, current_card, get_color_ansi(current_player_card.color));

        free(current_card);
        free(number_str);
    }

    print_line();

    free(oponent_hand);
}

char *int_between_parenthesis(int number)
{
    int digits = count_digits(number);

    char *str = (char *)malloc((digits + 2 + 1) * sizeof(char));

    sprintf(str, "(%d)", number);

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

    // char* new_str = (char*) realloc(str, (*str_size + suffix_size) * sizeof(char));

    strcpy(str + *str_size, suffix);

    *str_size += suffix_size;

    return str;
}

Card *get_player_cards(Card **deck, int *deck_size)
{
    Card *player_cards = (Card *)malloc(INITIAL_NUMBER_CARDS * sizeof(Card));

    if (player_cards == NULL)
    {
        printf("Erro ao alocar memória.");
        exit(1);
    }

    for (int i = 0; i < INITIAL_NUMBER_CARDS; i++)
    {
        int random_index = random_array_index(*deck_size);
        player_cards[i] = (*deck)[random_index];
        compaction(*deck, deck_size, random_index);
    }

    return player_cards;
}

int random_array_index(int arr_size)
{
    srand(time(NULL));
    return random() % arr_size;
}

void compaction(Card *arr, int *arr_size, int hole)
{
    if (hole < 0 || hole >= *arr_size)
    {
        return;
    }

    int new_size = *arr_size - 1;

    for (int i = hole; i < *arr_size; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr = (Card *)realloc(arr, new_size * sizeof(Card));

    if (arr == NULL)
    {
        printf("[ERROR]: Falha ao realocar memória.\n");
        exit(1);
    }

    *arr_size = new_size;
}

void str_compaction(char **arr, int *arr_size, int hole)
{
    if (hole < 0 || hole >= *arr_size)
    {
        return;
    }

    for (int i = hole; i < *arr_size; i++)
    {
        int new_length = strlen(arr[i + 1]);
        arr[i] = (char *)realloc(arr[i], (new_length + 1) * sizeof(char));

        arr[i] = arr[i + 1];
    }
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
    int i, j;

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

/*
 * PENDÊNCIAS
 * [o] - Escreva os testes unitários para as funções que precisarem
 * [] - Faça as documentações das funções
 * [] - Ajeite a função `int_to_string` para que ela aloque memória suficiente para o uso da string como representação do número. E ajeite a documentação dela logo em seguida.
 * [] - Continure programando a exibição do jogo
     Falta ainda:
         - Animação de distribuição de cartas
         - Verificar se, quando as cartas vão ser distribuídas para os jogadores, que a carta da mesa já tenha sido retirada
         - Colocar cores nas cartas da mesa
         - Mão do personagem
         - Ponta para o início da jogatina
*/
