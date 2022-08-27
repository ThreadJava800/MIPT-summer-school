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
    char **array = {};
    size_t size = 0;
};

/**
 * Transports lines from file to @Strings structure
 *
 * @param fileAddress - address of file on computer
 * @return @Strings - structure with strings
 */
Strings fromFile(const char *fileAddress);

/**
 * Just prints array of string
 *
 * @param strings - structure with array of string
 */
void printStringArray(Strings strings);

/**
 * Prints string provided in file
 *
 * @param file - file address
 */
void printFile(const char *fileAddress);

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

/**
 * My realization of quick sort, used to sort strings using @compareString
 *
 * @param strings - structure with array of strings
 */
void quickSort(Strings strings);

#endif //MIPT_SUMMER_SCHOOL_ONEGIN_H
