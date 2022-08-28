//
// Created by vladimir on 26.08.22.
//

#ifndef MIPT_SUMMER_SCHOOL_ONEGIN_H
#define MIPT_SUMMER_SCHOOL_ONEGIN_H

#include "stdio.h"

/**
 * Length of max string
 */
const int MAX_STRING = 4096;

/**
 * Structure with array of string and amount of them
 *
 * @param array - array with string
 * @param size - amount of lines
 */
struct Strings {
    char *buffer = {};
    char **array = {};
    int size = 0;
};

/**
 * Transports lines from file to @Strings structure
 *
 * @param fileAddress - address of file on computer
 * @return @Strings - structure with strings
 */
Strings fromFile(const char *fileAddress);

void writeToFile(FILE *file, const char *string);

void writeToFile(const char *fileAddress, const Strings *strings);

/**
 * Just prints array of string
 *
 * @param strings - structure with array of string
 */
void printStringArray(Strings strings);

/**
 * Removes punctuation marks from string and returns reference
 * to string without them
 *
 * @param string - string to reform
 * @return reference to string without punctuation marks
 */
char *removePuncts(char *string);

/**
 * Compares strings using ascii codes
 * I use basic c function strcmp there
 *
 * @param string1 - first string
 * @param string2 - second string to compare
 * @return negative value if string1 < string2, 0 if equals and
 * positive value if string1 > string2
 */
int compareString(char *string1, char *string2);

int compareFlipped(char *string1, char *string2);

/**
 * My realization of quick sort, used to sort strings using @compareString
 *
 * @param strings - structure with array of strings
 */
void quickSort(Strings strings, int (*comparator)(char *string1, char *string2));

void sortAsc(Strings strings);

void sortDesc(Strings strings);

#endif //MIPT_SUMMER_SCHOOL_ONEGIN_H
