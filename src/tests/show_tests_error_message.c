#include "../../include/tests/show_tests_error_message.h"

void show_tests_error_message(int num_test)
{
    printf("[ERROR] Test %d failed.\n", num_test);
    exit(1);
}