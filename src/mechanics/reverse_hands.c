#include "../../include/mechanics/reverse_hands.h"

void reverse_hands(Card **cards1, int *len1, Card **cards2, int *len2)
{
    if (*len1 > *len2)
    {
        *cards2 = realloc(*cards2, *len1 * sizeof(Card));
    }
    else if (*len2 > *len1)
    {
        *cards1 = realloc(*cards1, *len2 * sizeof(Card));
    }

    Card *temp = (Card *)malloc(*len1 * sizeof(Card));
    memcpy(temp, *cards1, *len1 * sizeof(Card));

    memcpy(*cards1, *cards2, *len2 * sizeof(Card));
    memcpy(*cards2, temp, *len1 * sizeof(Card));

    free(temp);

    int temp_size = *len1;
    *len1 = *len2;
    *len2 = temp_size;

    if (*len1 > *len2) {
        *cards2 = realloc(*cards2, *len2 * sizeof(Card));
    } else {
        *cards1 = realloc(*cards1, *len1 * sizeof(Card));
    }
}