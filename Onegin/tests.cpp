//
// Created by vladimir on 09.09.22.
//
#include "tests.h"

#define BLACK_COLOR  "\x1B[0m"
#define RED_COLOR    "\x1b[31m"
#define GREEN_COLOR  "\x1b[32m"

void testCompare() {
    const int testCount = 5;
    int successful = 0;
    TestCompare test[testCount] = {
            {.str1 = "Владимир", .str2 = "Ян", .result = -1},
            {.str1 = " ", .str2 = " ", .result = 0},
            {.str1 = "Привет", .str2 = "Мир", .result = 1},
            {.str1 = "Владимир", .str2 = "Владимир", .result = 0},
            {.str1 = "Ян", .str2 = "Владимир", .result = 1}
    };

    for (int i = 0; i < testCount; i++) {
        int machineSolution = compareString(test[i].str1, test[i].str2);
        if (!((machineSolution >= 0) ^ (test[i].result >= 0))) {
            printf(GREEN_COLOR"Test №%d: PASSED\n", i + 1);
            successful++;
        } else {
            printf(RED_COLOR"Test №%d: FAILED\nInfo about test:\n", i + 1);
            printf(RED_COLOR"    string1 = %s, string2 = %s\n", test[i].str1, test[i].str2);
            printf(RED_COLOR"Expected: result %d\n", test[i].result);
            printf(RED_COLOR"Got: result %d\n", machineSolution);
        }
    }

    if (successful < testCount) {
        printf(RED_COLOR "Tests failed %d/%d\n", successful, testCount);
    } else {
        printf(GREEN_COLOR "Tests passed %d/%d\n", successful, testCount);
    }
}

void testBytes() {
    const int testCount = 5;
    int successful = 0;
    CharCompare test[testCount] = {
            {.char1 = 255, .char2 = 255, .result = 0},
            {.char1 = 256, .char2 = 255, .result = -1},
            {.char1 = 190, .char2 = 1000, .result = -1},
            {.char1 = 0, .char2 = 1, .result = -1},
            {.char1 = 0, .char2 = 0, .result = 0},
    };

    for (int i = 0; i < testCount; i++) {
        int machineSolution = compareBytes(test[i].char1, test[i].char2);
        if (!((machineSolution >= 0) ^ (test[i].result >= 0))) {
            printf(GREEN_COLOR"Test №%d: PASSED\n", i + 1);
            successful++;
        } else {
            printf(RED_COLOR"Test №%d: FAILED\nInfo about test:\n", i + 1);
            printf(RED_COLOR"    byte1 = %d, byte2 = %d\n", test[i].char1, test[i].char2);
            printf(RED_COLOR"Expected: result %d\n", test[i].result);
            printf(RED_COLOR"Got: result %d\n", machineSolution);
        }
    }

    if (successful < testCount) {
        printf(RED_COLOR "Tests failed %d/%d\n", successful, testCount);
    } else {
        printf(GREEN_COLOR "Tests passed %d/%d\n", successful, testCount);
    }
}

void testCompareFlipped() {
    const int testCount = 5;
    int successful = 0;
    TestCompare test[testCount] = {
            {.str1 = "Владимир", .str2 = "Ян", .result = 1},
            {.str1 = " ", .str2 = " ", .result = 0},
            {.str1 = "Привет", .str2 = "Мир", .result = 1},
            {.str1 = "Владимир", .str2 = "Владимир", .result = 0},
            {.str1 = "Ян", .str2 = "Владимир", .result = -1}
    };

    for (int i = 0; i < testCount; i++) {
        int machineSolution = compareFlipped(test[i].str1, test[i].str2);
        if (!((machineSolution >= 0) ^ (test[i].result >= 0))) {
            printf(GREEN_COLOR"Test №%d: PASSED\n", i + 1);
            successful++;
        } else {
            printf(RED_COLOR"Test №%d: FAILED\nInfo about test:\n", i + 1);
            printf(RED_COLOR"    string1 = %s, string2 = %s\n", test[i].str1, test[i].str2);
            printf(RED_COLOR"Expected: result %d\n", test[i].result);
            printf(RED_COLOR"Got: result %d\n", machineSolution);
        }
    }

    if (successful < testCount) {
        printf(RED_COLOR "Tests failed %d/%d\n", successful, testCount);
    } else {
        printf(GREEN_COLOR "Tests passed %d/%d\n", successful, testCount);
    }
}

bool compareArrays(const int arr1[], const int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

void printErrorArray(int *arr, int size, char *pref) {
    printf(RED_COLOR"%s: ", pref);
    for (int i = 0;  i < size; i++) {
        printf(RED_COLOR"%d ", arr[i]);
    }
    printf("\n");
}

void testQSort() {
    const int testCount = 1;
    int successful = 0;

    char *test[] = {"Владимир", "Андрей", "Андроник"};
    int composition[] = {0, 1, 2};
    int corrComp[] = {1, 2, 0};
    Strings string = {.array = test, .composition = composition, .size = 3};

    for (int i = 0; i < testCount; i++) {
        quickSort(&string, compareString, 0, string.size);
        if (compareArrays(corrComp, string.composition, string.size)) {
            printf(GREEN_COLOR"Test №%d: PASSED\n", i + 1);
            successful++;
        } else {
            printf(RED_COLOR"Test №%d: FAILED\nInfo about test:\n", i + 1);
            printErrorArray(corrComp, string.size, "Expected");
            printErrorArray(string.composition, string.size, "Got");
        }
    }

    if (successful < testCount) {
        printf(RED_COLOR "Tests failed %d/%d\n", successful, testCount);
    } else {
        printf(GREEN_COLOR "Tests passed %d/%d\n", successful, testCount);
    }
}

void runTests() {
    printf(BLACK_COLOR"---Normal string compare---\n");
    testCompare();

    printf(BLACK_COLOR"\n---Bytes compare---\n");
    testBytes();

    printf(BLACK_COLOR"\n---Flipped strings compare---\n");
    testCompareFlipped();

    printf(BLACK_COLOR"\n---Qsort test---\n");
    testQSort();
}
