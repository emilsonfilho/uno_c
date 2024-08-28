#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>

#include "../utils/are_card_arrays_equal.h"

/**
 * Inherited libs: 
 * - stdbool.h
 * - string.h
*/

/**
 * Inherited internal libs: 
 * - types.h
 * - are_strings_equal.h
*/

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
    }

#define TEST_ASSERT_EQUAL_STR(expected, actual, test_num)                                                 \
    if (strcmp(expected, actual) != 0)                                                                    \
    {                                                                                                     \
        printf("ERROR: Teste %d falhou. Esperado: \"%s\", Obtido: \"%s\"\n", test_num, expected, actual); \
        exit(1);                                                                                          \
    }

#define TEST_ASSERT_ARRAYS_EQUAL(expected, expected_len, actual, actual_len, test_num) \
    if (!are_arrays_equal(expected, expected_len, actual, actual_len))                 \
    {                                                                                  \
        printf("ERROR: Teste %d falhou. Arrays não são iguais.\n", test_num);          \
        exit(1);                                                                       \
    }

#define TEST_ASSERT_CARD_ARRAYS_EQUAL(expected, expected_len, actual, actual_len, test_num) \
    if (!are_card_arrays_equal(expected, expected_len, actual, actual_len))                 \
    {                                                                                       \
        printf("ERROR: Teste %d falhou. Arrays não são iguais.\n", test_num);               \
        exit(1);                                                                            \
    }

#endif