//
// Created by vladimir on 26.08.22.
//

#ifndef MIPT_SUMMER_SCHOOL_ONEGIN_H
#define MIPT_SUMMER_SCHOOL_ONEGIN_H

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/**
 * Length of max string
 */
const int MAX_STRING = 4096;

/**
 * Structure with array of string and amount of them
 *
 * @param array - array with string
 * @param composition - array with indexes of how strings should be printer
 * @param size - amount of lines
 */
struct Strings {
    char **array = {};
    long int *composition = {};
    long int size = 0;
};

/**
 * Transports lines from file to @Strings structure
 *
 * @param fileAddress - address of file on computer
 * @return @Strings - structure with strings
 */
Strings fromFile(const char *fileAddress);

/**
 *  Writes string to file
 *
 * @param file - file
 * @param string  - string
 */
void writeToFile(FILE *file, const char *string);

/**
 * Writes array of strings into file
 *
 * @param fileAddress - absolute address to file
 * @param strings - array of strings
 */
void writeToFile(const char *fileAddress, const Strings *strings);

/**
 * Just prints array of string
 *
 * @param strings - structure with array of string
 */
void printStringArray(Strings *strings);

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

/**
 * Compares 2 byte chars
 *
 * @param char1
 * @param char2
 * @return 0 if equal, positive value if char 1 > char2 and negative value if char1 < char2
 */
int compareBytes(int char1, int char2);

/**
 * Compares strings from the end, ignoring puncts
 *
 * @param string1 - string1
 * @param string2 - string2
 * @return negative value if string1 < string2, 0 if equals and
 * positive value if string1 > string2
 */
int compareFlipped(char *string1, char *string2);

/**
 * My realization of quick sort, used to sort strings using @compareString
 *
 * @param strings - structure with array of strings
 * @param comparator - pointer to compare function
 * @param first - left border
 * @param last - right border
 */
void quickSort(Strings *strings, int (*comparator)(char *string1, char *string2), long int first, long int last);

/**
 * Sorts strings in alphabetic order from the beginning
 *
 * @param strings - pointer to structure with array of strings
 */
void sortAsc(Strings *strings);

/**
 * Sorts strings in alphabetic order from the end
 *
 * @param strings - pointer to structure with array of strings
 */
void sortDesc(Strings *strings);

/**
 * Resets composition to (0, 1, 2...)
 *
 * @param strings
 */
void resetComposition(Strings *strings);

/**
 * Generates nonsense ryphm
 *
 * @param strings
 */
void breadGenerator(Strings *strings);

#endif //MIPT_SUMMER_SCHOOL_ONEGIN_H
