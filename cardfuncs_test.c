#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "cardfuncs.h"
#include "cardfuncs_test.h"

bool TEST_parseTwoCharCard_BadInputs() {
    char thesuits[] = {0, 'x', ' ', 0, '5'};
    char thefaces[] = {0, '$', 'x', 'Z', 10};
    int i = 0, j = 0;
    card_s tdata;
    char tpayload[3] = {0,0,0};
    
    printf("TEST_parseTwoCharCard_BadInputs()\n");
    
    tdata.value = INVALID_VALUE;
    tdata.suit = INVALID_SUIT;
    
    for (j = 1; j < 5; j++) {
        for (i = 1; i < 6; i++){            
            tpayload[0] = thefaces[i];
            tpayload[1] = thesuits[j];
            
            tdata = parseTwoCharCard(tpayload);
            if (tdata.value != INVALID_VALUE ) {
                printf("TEST FAILED: value = %d i = %d payload = %s\n", tdata.value, i, tpayload);
                return false;
            }
            if (tdata.suit != INVALID_SUIT) {
                printf("TEST FAILED: suit = %d j = %d payload = %s\n", tdata.suit, j, tpayload);
                return false;
            }
        }
    }    
    return true;
}


bool TEST_parseTwoCharCard_GoodInputs() {
    char thesuits[] = {0, 'H', 'd', 'c', 'S'};
    char thefaces[] = {'T', 'J', 'Q', 'K', 'A'};
    int i = 0, j = 0;
    card_s tdata;
    char tpayload[3] = {0,0,0};
    
    printf("TEST_parseTwoCharCard_GoodInputs()\n");
    
    tdata.value = INVALID_VALUE;
    tdata.suit = INVALID_SUIT;
    
    for (j = 1; j < 5; j++) {
        for (i = 2; i < 15; i++){
            if (i < 10) {
                tpayload[0] = 48 + i;
            } else {
                tpayload[0] = thefaces[i - 10];
            }
            tpayload[1] = thesuits[j];
            
            tdata = parseTwoCharCard(tpayload);
            if (tdata.value != i) {
                printf("TEST FAILED: value = %d i = %d payload = %s\n", tdata.value, i, tpayload);
                return false;
            }
            if (tdata.suit != j) {
                printf("TEST FAILED: suit = %d j = %d payload = %s\n", tdata.suit, j, tpayload);
                return false;
            }
        }
    }
    
    return true;
}