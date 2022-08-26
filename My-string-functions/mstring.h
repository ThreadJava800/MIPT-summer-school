//
// Created by vladimir on 25.08.22.
//

#ifndef MIPT_SUMMER_SCHOOL_MSTRING_H
#define MIPT_SUMMER_SCHOOL_MSTRING_H

/**
 * Maximum length of string
 */
const int MAX_STRING = 4096;

/**
 * Prints string
 *
 * @param string - string to print
 * @return error code: EOF on error or amount of characters
 */
int mPuts(const char *string);

/**
 * Returns index of first entry of char to string
 *
 * @param cs - string
 * @param c - char to check
 * @return - pointer to first entry of char to string
 */
char *mStrchr(const char *cs, int c);

/**
 * Returns length of char*
 *
 * @param size_t - length of string
 * @return length of string
 */
int mStrlen(const char *cs);

/**
 * Copies one string to another
 *
 * @param s - string where to make copy
 * @param cs - string we are copying
 * @return @s
 */
char *mStrcpy(char *s, const char *cs);

/**
 * Copies only first @n symbols from one string to another
 *
 * @param s - string where to make copy
 * @param cs - string we are copying
 * @param n - amount of symbols
 * @return @s
 */
char *mStrncpy(char *s, const char *cs, size_t n);

/**
 * Concatenates two strings
 *
 * @param s - string where we are going to add new string
 * @param cs - string we concatenate to @s
 * @return @s
 */
char *mStrcat(char *s, const char *cs);

/**
 * Concatenates only n first numbers of @cs
 *
 * @param s - string where we are going to add new string
 * @param cs - string we concatenate to @s (only @n first numbers)
 * @param n - amount of numbers
 * @return @s
 */
char *mStrncat(char *s, const char *cs, int n);

/**
 * Reads n characters from @stream
 *
 * @param s - string we are reading
 * @param n - amount of symbols
 * @param stream - stream
 * @return @s
 */
char *mFgets(char *s, int n, FILE *stream);

/**
 * Allocates new pointer and copies string value there
 *
 * @param str - string to copy
 * @return newly allocated pointer
 */
char *mStrdup(const char *str);

/**
 * Get line
 *
 * Reads string while EOF or \n met. Also if desired you can set a char
 * to read string till
 *
 * @param stream - stream
 * @param s - string we are reading
 * @param *dump - char to stop at (basic value: EOF)
 * @return
 */
char *mGetline(FILE *stream, char *s, char dump = EOF);

#endif //MIPT_SUMMER_SCHOOL_MSTRING_H
