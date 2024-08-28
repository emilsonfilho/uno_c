#include "../../include/tests/run_tests.h"

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
                    if (!are_strings_equal(card_expected.numberAction.action, card_result.numberAction.action))
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
    for (int i = 0; i < str_compaction_size_invalid; i++)
    {
        str_compaction_array_invalid[i] = strdup("test");
    }
    int str_compaction_hole_invalid = 5; // Invalid index
    char **str_compaction_result_invalid = str_compaction(str_compaction_array_invalid, &str_compaction_size_invalid, str_compaction_hole_invalid);
    TEST_ASSERT_EQUAL(3, str_compaction_size_invalid, num_tests);
    TEST_ASSERT_EQUAL_PTR(str_compaction_array_invalid, str_compaction_result_invalid, num_tests);
    for (int i = 0; i < str_compaction_size_invalid; i++)
    {
        free(str_compaction_array_invalid[i]);
    }
    free(str_compaction_array_invalid);
    num_tests++;

    // Handle the case when the hole index is within bounds
    int str_compaction_size_valid = 3;
    char **str_compaction_array_valid = malloc(str_compaction_size_valid * sizeof(char *));
    for (int i = 0; i < str_compaction_size_valid; i++)
    {
        str_compaction_array_valid[i] = strdup("test");
    }

    int str_compaction_hole_valid = 1;
    char **str_compaction_expected_result_valid = malloc((str_compaction_size_valid - 1) * sizeof(char *));
    for (int i = 0; i < str_compaction_size_valid - 1; i++)
    {
        str_compaction_expected_result_valid[i] = strdup("test");
    }

    str_compaction_array_valid = str_compaction(str_compaction_array_valid, &str_compaction_size_valid, str_compaction_hole_valid);

    TEST_ASSERT_EQUAL(2, str_compaction_size_valid, num_tests);
    TEST_ASSERT_ARRAYS_EQUAL((const char **)str_compaction_expected_result_valid, 2, (const char **)str_compaction_array_valid, 2, num_tests);
    for (int i = 0; i < 2; i++)
    {
        free(str_compaction_expected_result_valid[i]);
    }
    free(str_compaction_expected_result_valid);
    for (int i = 0; i < str_compaction_size_valid; i++)
    {
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
    TEST_ASSERT_EQUAL(3, card_array[0].numberAction.number, num_tests); // Esperado 3
    TEST_ASSERT_EQUAL(2, card_array[1].numberAction.number, num_tests); // Esperado 2
    TEST_ASSERT_EQUAL(1, card_array[2].numberAction.number, num_tests); // Esperado 1
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
        {BLUE, .numberAction.action = "B", .isNumber = false}};

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
    Card card_red_5 = {RED, {.number = 5}, true};
    Card card_green_5 = {GREEN, {.number = 5}, true};
    Card card_red_block = {RED, {.action = "block"}, false};
    Card card_wild_change = {WILD, {.action = "change"}, false};
    Card card_wild_draw_four = {WILD, {.action = "+4"}, false};

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
    Card push_test_card_red_5 = {RED, {.number = 5}, true};
    Card push_test_card_green_5 = {GREEN, {.number = 5}, true};
    Card push_test_card_blue_7 = {BLUE, {.number = 7}, true};
    Card push_test_card_red_skip = {RED, {.action = "block"}, false};

    // Test adding a single card
    cards = push_card(cards, &size, push_test_card_red_5);
    TEST_ASSERT_EQUAL(1, size, num_tests);
    TEST_ASSERT_CARD_ARRAYS_EQUAL(&push_test_card_red_5, 1, cards, 1, num_tests);
    num_tests++;

    // Test adding another card and sorting
    cards = push_card(cards, &size, push_test_card_blue_7);
    Card sorted_cards_2[] = {push_test_card_red_5, push_test_card_blue_7};
    TEST_ASSERT_EQUAL(2, size, num_tests);
    TEST_ASSERT_CARD_ARRAYS_EQUAL(sorted_cards_2, 2, cards, 2, num_tests);
    num_tests++;

    // Test adding a card with the same color but different number
    cards = push_card(cards, &size, push_test_card_green_5);
    Card sorted_cards_3[] = {push_test_card_red_5, push_test_card_green_5, push_test_card_blue_7};
    TEST_ASSERT_EQUAL(3, size, num_tests);
    TEST_ASSERT_CARD_ARRAYS_EQUAL(sorted_cards_3, 3, cards, 3, num_tests);
    num_tests++;

    // Test adding a card with different color and action
    cards = push_card(cards, &size, push_test_card_red_skip);
    Card sorted_cards_4[] = {push_test_card_red_5, push_test_card_red_skip, push_test_card_green_5, push_test_card_blue_7};
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