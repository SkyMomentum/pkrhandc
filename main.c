
/*
 *  Poker hand finder.
 *  Input from the command line a list of 7 common playing cards in a format with
 *  face value and suit encoded in two characters. ex: KH JS JD 8C 5H 2S
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "card_stack.h"

int main(int argc, char **argv) {
    /*  -P-
        card_s input_cards[7];
        
        char str_cards[3] = {0,0,0};
        for argc 1 to 8
        str_cards[0] = *argv[argc];
        str_cards[1] = *argv[argc]++;
        input_cards[argc-1] = parseTwoCharCard(str_card);
        
        sorted_cards = sortInputHand(input_cards);
        
        five_suited_cards = find_flush(sorted_cards);
        five_straight_cards = find_straight(sorted_cards);
        if above are same cards == straight flush
        
        all_sets = find_value_sets(sorted_cards);
            will return all pairs, trips, quads. with 7 card input max of 3 can be returned, 3 pair, or 2 pair and a trip
            will need to resolve into fullhouse(s) if applicable
        
    */
    
    return 0;
}