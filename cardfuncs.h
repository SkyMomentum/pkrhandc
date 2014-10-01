#ifndef RD_CARDFUNCS
#define RD_CARDFUNCS

typedef enum {
    INVALID_SUIT = 0, HEART, DIAMOND, CLUB, SPADE
} suit_t;

typedef enum {
    INVALID_VALUE = 1, TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
} facevalue_t;

typedef struct {
    facevalue_t value;
    suit_t suit;
} card_s;

typedef struct {
    card_s card;
    card_s* next;
} card_list;

card_list* newEmptyCardList(int length);
card_list* newInitializedCardList(card_s *init_array); //null terminated array.
void deleteCardList(card_list *t);

card_list* pushCard(cardlist *head, card_s card);
card_list* popCard(cardlist *head, card_s card);

card_list* find_value_sets(card_list* sorted_cards);

card_s parseTwoCharCard(char c[3]);

#endif // RD_CARDFUNCS