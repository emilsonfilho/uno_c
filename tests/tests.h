#ifndef TESTS_H
#define TESTS_H

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

#endif // TESTS_H
