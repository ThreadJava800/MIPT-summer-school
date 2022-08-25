//
// Created by vladimir on 25.08.22.
//
#include "stdio.h"
#include "string.h"

#include "mstring.h"

int main() {
    char *s;
    char *code = mStrcpy(s, "hello");
    printf("code:%s cs:%s s:%s", code, "hello", s);

    return 0;
}