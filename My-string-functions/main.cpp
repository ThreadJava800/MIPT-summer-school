//
// Created by vladimir on 25.08.22.
//
#include "stdio.h"
#include "string.h"

#include "mstring.h"

int main() {
    char s[100] = "testtq";
    char *code = mStrncpy(s, "hello", 10);

    return 0;
}