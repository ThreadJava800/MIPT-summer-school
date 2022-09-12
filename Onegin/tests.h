//
// Created by vladimir on 09.09.22.
//

#ifndef MIPT_SUMMER_SCHOOL_TESTS_H
#define MIPT_SUMMER_SCHOOL_TESTS_H

#include <string.h>
#include <stdio.h>

#include "onegin.h"

struct TestCompare{
    char *str1;
    char *str2;
    int result;
};

struct CharCompare{
    int char1;
    int char2;
    int result;
};

struct QSortTest{
    long int size;
    char (*strings)[];
    long int testComposition[];
};

void testCompare();

void testBytes();

void testCompareFlipped();

bool compareArrays(const long int *arr1, const long int *arr2, long int size);

void printErrorArray(long int *arr, long int size, char *pref);

void testQSort();

/**
 * Starts all tests;
 */
void runTests();

#endif //MIPT_SUMMER_SCHOOL_TESTS_H
