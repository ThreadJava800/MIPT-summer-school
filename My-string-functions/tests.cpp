//
// Created by vladimir on 25.08.22.
//

#include "stdio.h"
#include "mstring.h"
#include "string.h"

#define RED_COLOR   "\x1b[31m"
#define GREEN_COLOR "\x1b[32m"

int testPuts(char *s) {
    int myCode = mPuts(s);
    int cCode = puts(s);

    if (myCode == cCode) {
        printf(GREEN_COLOR "\nTest passed!\n");
    } else {
        printf(RED_COLOR "Test failed");
        printf(RED_COLOR "   string %s", s);
        printf(RED_COLOR "   expected result code: %d", cCode);
        printf(RED_COLOR "   got result code: %d", myCode);
    }
}

int testStrlen(char *s) {
    int myCode = mStrlen(s);
    int cCode = strlen(s);

    if (myCode == cCode) {
        printf(GREEN_COLOR "\nTest passed!\n");
    } else {
        printf(RED_COLOR "Test failed");
        printf(RED_COLOR "   string %s", s);
        printf(RED_COLOR "   expected length: %d", cCode);
        printf(RED_COLOR "   got length: %d", myCode);
    }
}

int runTests() {
    printf("\n ---- Testing puts ---- \n");
    char *strings[5] = {"Print this please", "Hello, world\n", "Test\0", "\0", "\n"};
    for (int i = 0; i < 5; i++) {
        testPuts(strings[i]);
    }

    printf("\n ---- Testing strlen ---- \n");
    for (int i = 0; i < 5; i++) {
        testStrlen(strings[i]);
    }
}

int main() {
    runTests();
}
