#ifndef RD_CARDFUNCS_TEST
#define RD_CARDFUNCS_TEST

#define TEST_CHECK(pred, fmt, ...) if(!(pred)) {printf("TEST FAILED:\t");printf(fmt, ##__VA_ARGS__); putchar('\n');return false;}

bool TEST_parseTwoCharCard_GoodInputs();
bool TEST_parseTwoCharCard_BadInputs();

bool TEST_newEmptyCardList();
bool TEST_newInitializedCardList();
bool TEST_deleteCardList();

bool TEST_pushCard();
bool TEST_popCard();

#endif // RD_CARDFUNCS_TEST