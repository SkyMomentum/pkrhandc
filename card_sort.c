#include <stdio.h>
#include <ctype.h>

#include "card_stack.h"

/** @brief Sort in place of a card_list.
 *
 *  @param input_cards A pointer to the head of the list to be sorted.
 *  
 *  Mergesort for value without stability by suit.
 */
 
card_list* sortInputHand(card_list *input_cards) {
    // simple count first
    // divide list into pairs, if odd number of cards collapse last two by sorting 
    // mergesortCardLists(left, right);
    return NULL;
}

/** @brief Mergesort two null terminated lists.
 *
 *  @param left A pointer to the head of the first list.
 *  @param right A pointer to the head of the second list.
 *  
 *  Both lists must be sorted if either is longer than a single element.
 */

card_list* mergesortCardLists(card_list *left, card_list *right) {
    card_list *rethead = NULL, *workingend = NULL;
    
    if( left == NULL || right == NULL) return NULL;

    if(left->card.value > right->card.value) {
        rethead = left;
        left = popCard(left, NULL);
    } else {
        rethead = right;
        right = popCard(right, NULL);
    }
    workingend = rethead;

    while(workingend != NULL) {
        if ( left == NULL || right == NULL) break;
        //printf("VALUE A = %d, VALUE B = %d\n", left->card.value, right->card.value);
        if (left->card.value > right->card.value) {
            workingend->next = left;
            left = popCard(left, NULL);
        } else {
            workingend->next = right;
            right = popCard(right, NULL);
        }
        workingend = workingend->next;
    }
    return rethead;
}
