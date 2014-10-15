#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "card_stack.h"
#include "card_stack_test.h"
#include "card_sort.h"

bool TEST_sortInputHand() {
    printf("TEST_sortInputHand()\n");
    
    char cards[] = "TD 6D 8D 8H 3H 2C AS";
    card_stack *payload = cardStackFromCStr(cards);
    printCardStack(payload); putchar('\n');
    card_stack *result = NULL;
    
    result = sortInputHand(payload);

    printCardStack(result); putchar('\n');
    
    return false;
}

bool TEST_mergesortCardLists() {
    printf("TEST_mergesortCardLists()\n");
    
    char thesuits[] = {'H', 'S', 'D', 'C', 'H'};
    char leftfaces[] = {'2', '4', '6', '8', 'T'};
    char rightfaces[] = {'3', '5', '7', '9', 'A'};
    char cardString[3] = {0,0,0};
    
    int i = 0;
    
    card_stack *lhead = NULL, *rhead = NULL, *rethead = NULL, *working = NULL;
    card_t parsedCard;
    
    lhead = newEmptyCardList();
    rhead = newEmptyCardList();
    
    for (i = 0; i <5; i++){
        cardString[0] = leftfaces[i];
        cardString[1] = thesuits[i];
        parsedCard = parseTwoCharCard(cardString);
        lhead = pushCard(lhead, parsedCard);
        
        cardString[0] = rightfaces[i];
        cardString[1] = thesuits[4-i];
        parsedCard = parseTwoCharCard(cardString);
        rhead = pushCard(rhead, parsedCard);
    }
    //putchar('\t'); printCardStack(lhead); putchar('\n');
    //putchar('\t'); printCardStack(rhead); putchar('\n');
    
    rethead = mergesortCardLists(lhead, rhead);
    //putchar('\t'); printCardStack(rethead); putchar('\n');
    
    TEST_CHECK_FIXED( ((rethead == lhead) || (rethead == rhead)), "Head of returned sorted list did not match either supplied head")

    working = rethead;
    for (i = 0; i <10; i++){
        TEST_CHECK_VARGS( 
            (working->card.value > working->next->card.value),
            "Values are not in sequence, %d - %d",
            working->card.value , working->next->card.value
        )
    }

    return true;
}

