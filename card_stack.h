#ifndef RD_CARD_STACK
#define RD_CARD_STACK

typedef enum {
    INVALID_SUIT = 0, HEART, DIAMOND, CLUB, SPADE
} suit_t;

typedef enum {
    NULL_VALUE = 0, INVALID_VALUE = 1, TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
} facevalue_t;

typedef struct {
    facevalue_t value;
    suit_t suit;
} card_s;

typedef struct card_list{
    card_s card;
    struct card_list* next;
} card_list;

typedef struct card_list card_stack;

card_list* newEmptyCardList();
card_list* newInitializedCardList(card_s *init_array, int length);
void deleteCardList(card_list *t);

card_stack* newCardStack(card_list *list);

card_stack* pushCard(card_stack *head, card_s inputcard);
card_stack* popCard(card_stack *head, card_s *ptr_popped);

card_stack* find_value_sets(card_list* sorted_cards);

card_s parseTwoCharCard(char c[3]);

#endif // RD_CARD_STACK