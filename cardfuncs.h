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

card_s parseTwoCharCard(char c[3]);

#endif // RD_CARDFUNCS