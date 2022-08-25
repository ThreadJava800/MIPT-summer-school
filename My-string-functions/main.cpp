//
// Created by vladimir on 25.08.22.
//
#include "stdio.h"
#include "string.h"

#include "mstring.h"

int main() {
    char s[MAX_STRING] = "petya ";
    char *code = mStrncat(s, "haha", 0);
    printf(s);

    return 0;
}