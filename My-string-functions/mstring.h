//
// Created by vladimir on 25.08.22.
//

#ifndef MIPT_SUMMER_SCHOOL_MSTRING_H
#define MIPT_SUMMER_SCHOOL_MSTRING_H

const int MAX_STRING = 4096;

/**
 * Prints string
 *
 * @param string - string to print
 * @return error code: EOF on error or amount of characters
 */
int mPuts(const char *string);

char *mStrchr(const char *cs, int c);

/**
 * Returns length of char*
 *
 * @param size_t - length of string
 * @return length of string
 */
int mStrlen(const char *cs);

char *mStrcpy(char *s, const char *cs);

char *mStrncpy(char *s, const char *cs, size_t n);

char *mStrcat(char *s, const char *cs);

#endif //MIPT_SUMMER_SCHOOL_MSTRING_H
