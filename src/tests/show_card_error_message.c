#include "../../include/tests/show_card_error_message.h"

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