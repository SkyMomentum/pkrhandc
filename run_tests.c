
/*
 *  Poker hand finder.
 *  Input from the command line a list of 7 common playing cards in a format with
 *  face value and suit encoded in two characters. ex: KH JS JD 8C 5H 2S
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "cardfuncs_test.h"

int main() {
    /* TODO: Keep track of the results */
    TEST_parseTwoCharCard_GoodInputs();
    TEST_parseTwoCharCard_BadInputs();
    
    return 0;
}