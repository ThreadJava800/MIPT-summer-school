//
// Created by vladimir on 26.08.22.
//

#ifndef MIPT_SUMMER_SCHOOL_ONEGIN_H
#define MIPT_SUMMER_SCHOOL_ONEGIN_H

#include "stdio.h"

const int MAX_STRING = 4096;

struct Strings {
    char **array = {};
    size_t size = 0;
};

Strings fromFile(const char *fileAddress);

/**
 * Prints string provided in file
 *
 * @param file - file address
 */
void printFile(const char *fileAddress);

#endif //MIPT_SUMMER_SCHOOL_ONEGIN_H
