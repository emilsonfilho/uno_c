#ifndef CAN_PLAY_CARD_H
#define CAN_PLAY_CARD_H

#include "is_color_match.h"
#include "is_number_match.h"
#include "is_action_match.h"
#include "is_wild_card.h"

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

/**
 * @brief Determines if a card can be legally played based on game rules.
 *
 * This function checks if a given `Card` can be played on top of the current `top_card`
 * according to the game rules. The card can be played if it matches the color, number,
 * or action of the top card, or if it is a wild card. Additionally, if the top card is a wild card,
 * the card can be played if its color matches the chosen color.
 *
 * @param chosen The card that is being evaluated for play.
 * @param top_card The current card on top of the table.
 * @param chosen_color The color chosen for the card play, relevant if the top card is a wild card.
 *
 * @return `true` if the `chosen` card can be played on top of the `top_card` based on the rules, otherwise `false`.
 */
bool can_play_card(Card chosen, Card top_card, Color chosen_color);

#endif