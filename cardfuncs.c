#include <stdio.h>  /* REMOVE AFTER DEBUGGING  nothing should really print here*/
#include <stdlib.h>
#include <ctype.h>

#include "cardfuncs.h"
/*
 *  Name: parseTwoCharCard
 *  Arguments: c, an array of two chars.
 *
 *  Convert the char representing the value of the card to facevalue_t by
 *  converting to int for simple case, or selecting for letters for higher cards.
 *  The default case in the switch having eliminated all valid options sets 
 *  an error state.
 */
card_s parseTwoCharCard(char c[3]){
    card_s retval;
    int value = 0;

    char valuestr[2] = {c[0], 0};
    value = atoi(valuestr);
    if (value <= 1) {
        switch (toupper((int)c[0])) {
            case 'T':
                value = 10;
                break;
            case 'J':
                value = 11;
                break;
            case 'Q':
                value = 12;
                break;
            case 'K':
                value = 13;
                break;
            case 'A':
                value = 14;
                break;
            default:
                value = 1;
        }
    }
    retval.value = (facevalue_t) value;
    
    switch (toupper((int)c[1])) {
        case 'H':
            retval.suit = HEART;
            break;
        case 'D':
            retval.suit = DIAMOND;
            break;
        case 'C':
            retval.suit = CLUB;
            break;
        case 'S':
            retval.suit = SPADE;
            break;
        default:
            retval.suit = INVALID_SUIT;
    }
    return retval;
}