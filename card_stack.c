#include <stdio.h>  /* REMOVE AFTER DEBUGGING  nothing should really print here*/
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "card_stack.h"

const char suitToCharTable[] = {0, 'H', 'D', 'C', 'S'};
const char faceToCharTable[] = {0, 0, '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};


/** @brief Parse two chars to a card_t struct.
 *
 *  @param c An array of two chars.
 *
 *  Convert the char representing the value of the card to facevalue_t by
 *  converting to int for simple case, or selecting for letters for higher cards.
 *  The default case in the switch having eliminated all valid options sets 
 *  an error state.
 */
card_t parseTwoCharCard(char c[3]){
    card_t retval;
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

/** @brief Initialize a new card_list by provided an array of card_t.
 *
 *  @param init_array An array of two chars.
 *  @param length The length of the first passed array.
 *  
 */

card_list* newInitializedCardList(card_t *init_array, int length){
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

/** @brief Push a card_t to a card_list stack.
 *
 *  @param head The top of a card_list stack.
 *  @param inputcard The card to be pushed.
 *  
 */

card_stack* pushCard(card_stack *head, card_t inputcard) {
    card_list *newhead = NULL;
    
    if (head == NULL) return NULL;
    
    newhead = newEmptyCardList();
    if (newhead == NULL) return NULL;
    
    newhead->next = head;
    newhead->card = inputcard;
    
    return newhead;
}

/** @brief Pop a card_t from a card_list stack.
 *
 *  @param head The top of a card_list stack.
 *  @param ptr_popped A pointer to a card_t to store the card_t popped from the stack.
 *  
 */

card_stack* popCard(card_stack *head, card_t *ptr_popped) {
    card_list *newhead = NULL;

    if (head == NULL) return NULL;
    
    if (ptr_popped != NULL) {
        ptr_popped->value = head->card.value;
        ptr_popped->suit = head->card.suit;
    }

    newhead = head->next;
    free(head);    

    return newhead; 
}

/** @brief Print a card_stack to stdio in the same format as input.
 *  
 *  @param head A pointer to the head of a list to be printed.
 *  
 */

void printCardStack(card_stack *head) {
    while (head != NULL) {
        putchar(faceToCharTable[head->card.value]);
        putchar(suitToCharTable[head->card.suit]);
        putchar(' ');
        head = head->next;
    }
}

/** @brief Construct a new card_list from a C string.
 *  
 *  @param input The string of cards encoded in two char text. Space separated, null terminated.
 */ 

card_stack* cardStackFromCStr(char *input) {
    char *argStr = NULL, *endPtr = NULL;
    card_list* output = NULL;
    card_t parsedCard;
    
    output = newEmptyCardList();
    
    int cnt = 0;
    
    while (*(input + cnt) != NULL){
        cnt++;
    }
    endPtr = input + cnt;

    while (endPtr > input) {
        argStr = endPtr - 2;
        /*  Look back 2 chars from the end, if it's a space 
         *  null it out and move the input pointer for the next pass.
         */
        if (*(endPtr - 3) == ' '){
            *(endPtr - 3) = 0;
        }
        endPtr -= 3;
        *(argStr + 2) = 0;//ensure the null
        parsedCard = parseTwoCharCard(argStr);
        /* Check for error state after parsing attempt. pushCard() if not. */
        if ((parsedCard.value != NULL_VALUE) &&
            (parsedCard.value != INVALID_VALUE) &&
            (parsedCard.suit != INVALID_SUIT)) {
                output = pushCard(output, parsedCard);
            } else {
                deleteCardList(output);
                return NULL;
            }
    }
    return output;
}

/** @brief Delete a card_list.
 *  
 *  Delete a card_list following the next link in the list until NULL. Which is the
 *  empty base case. This should fail spectacularly so there is no test case.
 *  
 *  TODO: Decide if I care about long lists and how this will fail spectacularly.
 */

void deleteCardList(card_list *t){
    if (t->next != NULL) {
        deleteCardList(t->next);
    }
    free(t);
}

card_stack* newCardStack(card_list *list) {
    return (card_stack*)list;
}
