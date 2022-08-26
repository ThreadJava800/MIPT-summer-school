//
// Created by vladimir on 25.08.22.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>

#include "assert.h"

#include "mstring.h"

int mPuts(const char *string) {
    int resultCode = EOF;

    printf(string);
    resultCode = mStrlen(string) + 1;

    return resultCode;
}

char *mStrchr(const char *cs, int c) {
    int n = mStrlen(cs);
    char *result = (char *) malloc(n + 1);


    for (int i = 0; i < n; i++) {
        if (cs[i] == c) {
            for (int j = 0; j < n - i; j++) {
                result[j] = cs[i + j];
            }
            return result;
        }
    }

    return NULL;
}

int mStrlen(const char *cs) {
    int stLength = 0;

    while (*cs != '\0') {
        stLength++;
        cs++;
    }

    return stLength;
}

char *mStrcpy(char *s, const char *cs) {
    for (int i = 0; i <= mStrlen(cs); i++) {
        s[i] = cs[i];
    }

    return s;
}

char *mStrncpy(char *s, const char *cs, size_t n) {
    assert(isfinite(n));

    size_t csLen = mStrlen(cs);

    if (csLen < n) {
        mStrcpy(s, cs);

        for (int i = csLen + 1; i < csLen + csLen - n; i++) {
            s[i] = '\0';
            s++;
        }
    }
    else {
        char newString[MAX_STRING] = "";
        for (int i = 0; i < n; i++) {
            newString[i] = cs[i];
        }
        mStrcpy(s, newString);
    }

    return s;
}


char *mStrcat(char *s, const char *cs) {
    int sLen = mStrlen(s), csLen = mStrlen(cs);

    for (int i = 0; i < csLen; i++) {
        s[i + sLen] = cs[i];
    }

    return s;
}

char *mStrncat(char *s, const char *cs, int n) {
    int sLen = mStrlen(s), csLen = mStrlen(cs);

    if (sLen < n) {
        mStrcat(s, cs);
    } else {
        char newString[MAX_STRING] = "";

        for (int i = 0; i < n; i++) {
            newString[i] = cs[i];
        }

        mStrcat(s, newString);
    }

    mStrcat(s, "\0");

    return s;
}

// TODO
char *mFgets(char *s, int n, FILE *stream) {
    if (stream != nullptr) {
        for (int i = 0; i < n; i++) {
            char val = fgetc(stream);

            if (val == '\n' || val == EOF) {
                return NULL;
            }

            s[i] = val;
        }

        mStrcat(s, "\0");

        return s;
    }

    return NULL;
}

char *mStrdup(const char *str) {
    char *result = (char *) malloc(mStrlen(str) + 1);
    mStrcpy(result, str);
    mStrcat(result, "\0");

    return result;
}

char *mGetline(FILE *stream, char *s, char dump) {
    int val = fgetc(stream);

    if (val == EOF || val == '\n' || val == dump) {
        return NULL;
    }

    while (val != EOF && val != '\n' && val != dump) {
        *s = val;
        s++;

        val = fgetc(stream);
    }

    return s;
}
