//
// Created by vladimir on 25.08.22.
//

#include <stdio.h>
#include <stdlib.h>

#include "mstring.h"

int mPuts(const char *string) {
    int resultCode = EOF;

    printf(string);
    resultCode = mStrlen(string) + 1;

    return resultCode;
}

char *mStrchr(const char *cs, int c) {
    for (int i = 0; i < mStrlen(cs); i++) {
        if (cs[i] == c) {
            return (char*)cs[i];
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
    size_t csLen = mStrlen(cs);

    if (csLen < n) {
        mStrcpy(s, cs);

        for (int i = csLen + 1; i < csLen + csLen - n; i++) {
            s[i] = '\0';
            s++;
        }

        //printf("%s\n", s);
    }
    else {
        for (int i = 0; i <= n; i++) {
            s[i] = cs[i];
        }
    }

    return s;
}
