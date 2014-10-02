#include <stdio.h>  /* REMOVE AFTER DEBUGGING  nothing should really print here*/
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cardfuncs.h"
/** @brief Parse two chars to a card_s struct.
 *
 *  @param c An array of two chars.
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


/** @brief Create a new empty card_list struct.
 *  
 */

card_list* newEmptyCardList(){
    void *m = NULL;
    
    m = malloc(sizeof(card_list));
    if(m == NULL) return NULL;
    
    memset(m, 0, sizeof(card_list));
    return (card_list*)m;
}

/** @brief Initialize a new card_list by provided an array of card_s.
 *
 *  @param init_array An array of two chars.
 *  @param length The length of the first passed array.
 *  
 */

card_list* newInitializedCardList(card_s *init_array, int length){
    int i = 0;
    card_list *list = NULL, *head = NULL;
    
    if (init_array == NULL) return NULL;
    
    list = newEmptyCardList();
    head = list;
    
    for (i = 0; i <= length; i++){
        if (i == length) {
            list->next = NULL;
        } else {
            list->next = newEmptyCardList();
            if (list->next == NULL) {
                deleteCardList(head);
                return NULL;
            }
        }
        list->card = init_array[i];
        list = list->next;
    }
    return head;
}

/** @brief Push a card_s to a card_list stack.
 *
 *  @param head The top of a card_list stack.
 *  @param inputcard The card to be pushed.
 *  
 */

card_list* pushCard(card_list *head, card_s inputcard) {
    card_list *newhead = NULL;
    
    if (head == NULL) return NULL;
    
    newhead = newEmptyCardList();
    if (newhead == NULL) return NULL;
    
    newhead->next = head;
    newhead->card = inputcard;
    
    return newhead;
}

/** @brief Pop a card_s from a card_list stack.
 *
 *  @param head The top of a card_list stack.
 *  @param ptr_popped A pointer to a card_s to store the card_s popped from the stack.
 *  
 */

card_list* popCard(card_list *head, card_s *ptr_popped) {
    card_list *newhead = NULL;

    if (head == NULL) return NULL;
    
    ptr_popped->value = head->card.value;
    ptr_popped->suit = head->card.suit;

    newhead = head->next;
    free(head);    

    return newhead; 
}

/** @brief Delete a card_list.
 *  
 *  Delete a card_list following the next link in the list until NULL. Which is the empty base case.
 */

void deleteCardList(card_list *t){
    if (t->next != NULL) {
        deleteCardList(t->next);
    }
    free(t);
}

card_list* find_value_sets(card_list* sorted_cards) {
    return NULL;
}