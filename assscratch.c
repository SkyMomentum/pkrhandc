#include <stdio.h>
#include <stdbool.h>
#define TEST_CHECK(pred, fmt, ...) if(!(pred)) {printf("TEST FAILED:\t");printf(fmt, ##__VA_ARGS__); return false;}

int main(){
    TEST_CHECK(1 == 2, "HELLO WORLD \n")
}