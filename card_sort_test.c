#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "card_stack.h"
#include "card_stack_test.h"
#include "card_sort.h"

bool TEST_sortInputHand() {
    printf("TEST_sortInputHand()\n");
    return false;
}

bool TEST_mergesortCardLists() {
    printf("TEST_mergesortCardLists()\n");
    
    char thesuits[] = {'H', 'S', 'D', 'C', 'H'};
    char leftfaces[] = {'2', '4', '6', '8', 'T'};
    char rightfaces[] = {'A', '3', '5', '7', '9'};
    char cardString[3] = {0,0,0};
    
    int i = 0;
    
    card_stack *lhead = NULL, *rhead = NULL, *rethead = NULL, *working = NULL;
    card_s parsedCard;
    
    lhead = newEmptyCardList();
    rhead = newEmptyCardList();
    
    for (i = 0; i <5; i++){
        cardString[0] = leftfaces[i];
        cardString[0] = thesuits[i];
        parsedCard = parseTwoCharCard(cardString);
        lhead = pushCard(lhead, parsedCard);
        
        cardString[0] = rightfaces[i];
        cardString[0] = thesuits[4-i];
        parsedCard = parseTwoCharCard(cardString);
        rhead = pushCard(rhead, parsedCard);
    }
    
    rethead = mergesortCardLists(lhead, rhead);
    
    TEST_CHECK_FIXED( ((rethead == lhead) || (rethead == rhead)), "Head of returned sorted list did not match either supplied head")

    working = rethead;
    for (i = 0; i <10; i++){
        TEST_CHECK_VARGS( 
            (working->card.value > working->next->card.value),
            "Values are not in sequence, %d - %d",
            working->card.value , working->next->card.value
        )
    }
    
    return false;
}