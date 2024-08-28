#include "../../include/inits/create_deck.h"

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

    return deck;
}