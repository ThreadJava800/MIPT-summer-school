//
// Created by vladimir on 26.08.22.
//
#include "stdlib.h"

#include "onegin.h"

int main() {
    Strings strings = fromFile("/home/vladimir/Projects/MIPT summer school/Onegin/test.txt");
    sortAsc(strings);

    free(strings.array);
    return 0;
}