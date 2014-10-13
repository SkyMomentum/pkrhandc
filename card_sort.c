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
    //  card_list *rethead, *workingend;
    //  if a->card.value > b->card.value then rethead = a, pop left
    //  else rethead = b, pop right
    //  workingend = rethead;
    
    //  for each element in a
    //      if a->card.value > b->card.value then head->next = a, pop left
    //      else head->next = b, pop right
    //      workingend = workingend->next
    return NULL;
}
