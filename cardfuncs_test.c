/*  Adhoc Test harness
 *  TEST_ functions return false upon failure.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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
            TEST_CHECK(tdata.value == INVALID_VALUE, "value = %d i = %d payload = %s", tdata.value, i, tpayload)
            TEST_CHECK(tdata.suit == INVALID_SUIT, "TEST FAILED: suit = %d j = %d payload = %s", tdata.suit, j, tpayload)
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
            TEST_CHECK(tdata.value == i, "value = %d i = %d payload = %s", tdata.value, i, tpayload)
            TEST_CHECK(tdata.suit == j, "suit = %d j = %d payload = %s", tdata.suit, j, tpayload)
        }
    }
    
    return true;
}

bool TEST_newEmptyCardList(){
    printf("TEST_newEmptyCardList()\n");
    card_list *p = NULL;
    p = newEmptyCardList();
    if (p){
        TEST_CHECK(p->card.value == NULL_VALUE, "Wrong value: exp %d, recv %d", INVALID_VALUE, p->card.value)
        TEST_CHECK(p->card.suit == INVALID_SUIT, "Wrong value: exp %d, recv %d", INVALID_SUIT, p->card.value)
    }
    return true;
}

bool TEST_newInitializedCardList(){
    printf("TEST_newInitializedCardList()\n");
    int i = 0;
    card_s testdata[8];
    card_list *result = NULL;
    
    for(i=0; i < 8; i++){
        testdata[i].value = i + 4; //middle values
        testdata[i].suit = HEART;
    }
    memset(&testdata[8], 0, sizeof(card_s)); //null terminator
        
    result = newInitializedCardList(testdata, 7);
    TEST_CHECK(result != NULL, "Recieved NULL ptr from function newInitializedCardList()")
    TEST_CHECK(result->card.suit == HEART, "Initialized to wrong suit")
    
    i = 0;
    while(result->next != NULL) {
        TEST_CHECK(result->card.value == i + 4, "Wrong value: exp %d, recv %d", i + 4, result->card.value)
        i++;
        result = result->next;
    }
    
    return true;
}

bool TEST_deleteCardList(){
    printf("TEST_deleteCardList()\n");
    card_list *x = NULL;
    x = newEmptyCardList();
    deleteCardList(x);
    return true; 
}

bool TEST_pushCard(){
    printf("TEST_pushCard()\n");
    card_s a, b;
    card_list *firsthead = NULL, *second = NULL, *target = NULL;
    
    a.value = QUEEN;
    a.suit = HEART;
    
    b.value = ACE;
    b.suit = SPADE;
    
    firsthead = newEmptyCardList();
    target = firsthead;
    TEST_CHECK(target != NULL, "Recieved NULL ptr from function newEmptyCardList()")

    target = pushCard(target, a);
    TEST_CHECK(target != NULL, "Call returned a null")
    TEST_CHECK(target != firsthead, "Call did not change the head of the list")
    TEST_CHECK(target->card.value == QUEEN, "Wrong value: exp %d, recv %d", QUEEN, target->card.value)
    
    second = target;
    target = pushCard(target, b);
    TEST_CHECK(target != second, "Second call did not change the head of the list")
    TEST_CHECK(target->card.value == ACE, "Wrong value: exp %d, recv %d", ACE, target->card.value)


    return true;
}

bool TEST_popCard(){
    printf("TEST_popCard()\n");
    card_s a, b, popped;
    card_list *firsthead = NULL, *second = NULL, *target = NULL ;
    
    a.value = QUEEN;
    a.suit = HEART;
    
    b.value = ACE;
    b.suit = SPADE;
    
    target = newEmptyCardList();
    target = pushCard(target, a);
    target = pushCard(target, b);    
    TEST_CHECK(target != NULL, "Recieved NULL ptr from function after setup attempt")
    
    firsthead = target;
    target = popCard(target, &popped);
    TEST_CHECK(popped.value == ACE, "Wrong value: exp %d, recv %d", ACE, popped.value)
    TEST_CHECK(target != firsthead, "First Call did not change the head of the list")
    
    second = target;
    target = popCard(target, &popped);
    TEST_CHECK(target != second, "Second Call did not change the head of the list")
    TEST_CHECK(firsthead != second, "Call did not changed the head of the list to the same pointer as the first call")
    TEST_CHECK(popped.value == QUEEN, "Wrong value: exp %d, recv %d", QUEEN, popped.value)


    return true;
}