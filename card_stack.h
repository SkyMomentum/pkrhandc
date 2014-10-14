#ifndef RD_CARD_STACK
#define RD_CARD_STACK

typedef enum {
    INVALID_SUIT = 0, HEART, DIAMOND, CLUB, SPADE
} suit_t;

typedef enum {
    NULL_VALUE = 0, INVALID_VALUE = 1, TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
} facevalue_t;

extern const char suitToCharTable[];
extern const char faceToCharTable[];

typedef struct {
    facevalue_t value;
    suit_t suit;
} card_t;

typedef struct card_list{
    card_t card;
    struct card_list* next;
} card_list;

typedef struct card_list card_stack;

card_list* newEmptyCardList();
card_list* newInitializedCardList(card_t *init_array, int length);
void deleteCardList(card_list *t);

card_stack* newCardStack(card_list *list);

card_stack* pushCard(card_stack *head, card_t inputcard);
card_stack* popCard(card_stack *head, card_t *ptr_popped);

card_t parseTwoCharCard(char c[3]);

void printCardStack(card_stack *head);
card_stack* cardStackFromCStr(char *input);

card_list* concatCardLists(card_list *first, card_list *second);

#endif // RD_CARD_STACK