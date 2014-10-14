#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "card_stack.h"
#include "card_sort.h"

/** @brief Sort in place of a card_list.
 *
 *  @param input_cards A pointer to the head of the list to be sorted.
 *  
 *  Mergesort for value without stability by suit.
 */
 
card_list* sortInputHand(card_list *input_cards) {
    // simple count first
    int count = 0, passcount = 0;
    int i = 0;
    card_list *headCard = NULL, *nextCard = NULL, *listIterator = NULL;
    headCard = input_cards;
    
    while (headCard != NULL) {
        count++;
        headCard = headCard->next;
    }
    
    listIterator = headCard = input_cards;

    card_list **arrayOfPartialSorts = malloc(sizeof(card_list*) * ((count/2) +1));
    
    // Prep pass
    while (listIterator != NULL) {
        // take two from input, sort them, put that list into next arrayOfPartialSorts
        // headcard is set to listIterator, which is initially the argument input_cards
        // and subsequently updated on each loop
        headCard = listIterator;
        
        // Check there are two cards, existence of the first checked by the while loop
        if ( listIterator->next != NULL ){
            //Save pointers to ->next elements then NULL them on the working elements
            nextCard = headCard->next; 
            headCard->next = NULL;
            listIterator = nextCard->next;
            nextCard->next = NULL;
            arrayOfPartialSorts[passcount] = mergesortCardLists( headCard, nextCard );
        } else {
            listIterator = NULL;
            // TODO: The work, dropping the last card if odd because lazy
            //merge with the last partial sort
            
        }
        passcount++;
    }
    
    //Forward run over partial sorts, merge sort adjacent items
    /*  -P-
     *  while thiscount > 1
     *      thiscount = 0
     *      loop the partials
     *          mergesorting
     *          thiscount++
     *  end loop because mergesort did the final left and right
     */
    for (i = 0; i < passcount; i++) {
        *(arrayOfPtrInputCards + i) = headCard;
        headCard = headCard->next;
    }

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
        left = left->next;
    } else {
        rethead = right;
        right = right->next;
    }
    workingend = rethead;
    
    while(workingend != NULL) {
        if(left == NULL) {
            workingend->next = right;
            right->next = NULL;
        } else if (right == NULL) {
            workingend->next = left;
            left->next = NULL;
        } else if ( left->card.value == NULL_VALUE || right->card.value == NULL_VALUE ) { 
            break; 
        } else if (left->card.value > right->card.value) {
            workingend->next = left;
            left = left->next;
        } else {
            workingend->next = right;
            right = right->next;
        }
        workingend = workingend->next;
    }

    return rethead;
}

card_list* find_value_sets(card_list* sorted_cards) {
    return NULL;
    return sorted_cards; //Suppressing -Wextra warning until function exists
}


