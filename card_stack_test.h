#ifndef RD_CARD_STACK_TEST
#define RD_CARD_STACK_TEST

#define TEST_CHECK_VARGS(pred, fmt, ...) if(!(pred)) {printf("TEST FAILED:\t");printf(fmt, ##__VA_ARGS__); putchar('\n');return false;}
#define TEST_CHECK_FIXED(pred, str) if(!(pred)) {printf("TEST FAILED:\t");printf(str); putchar('\n');return false;}

bool TEST_parseTwoCharCard_GoodInputs();
bool TEST_parseTwoCharCard_BadInputs();

bool TEST_newEmptyCardList();
bool TEST_newInitializedCardList();
bool TEST_deleteCardList();

bool TEST_pushCard();
bool TEST_popCard();

bool TEST_sortInputHand();
bool TEST_mergesortCardLists();

bool TEST_cardStackFromCStr();

bool TEST_concatCardLists();

#endif // RD_CARD_STACK_TEST