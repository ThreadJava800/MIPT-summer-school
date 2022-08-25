//
// Created by vladimir on 25.08.22.
//
#include <stdlib.h>
#include "stdio.h"
#include "string.h"

#include "mstring.h"

int main() {
    char *code = mStrdup("loser");
    printf(code);

    free(code);


    return 0;
}