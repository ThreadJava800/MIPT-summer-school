//
// Created by vladimir on 25.08.22.
//
#include "stdio.h"

#include "mstring.h"

int main() {
    char s[MAX_STRING] = "test";
    char *code = mGetline(stdin, s, 'a');
    printf("%s", s);

    return 0;
}