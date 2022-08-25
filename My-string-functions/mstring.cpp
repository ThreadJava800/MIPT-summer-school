//
// Created by vladimir on 25.08.22.
//

#include <stdio.h>

#include "mstring.h"

int mPuts(const char *string) {
    int resultCode = EOF;

    printf(string);
    resultCode = mStrlen(string) + 1;

    return resultCode;
}

int mStrlen(const char *cs) {
    int stLength = 0;

    while (*cs != '\0') {
        stLength++;
        cs++;
    }

    return stLength;
}
