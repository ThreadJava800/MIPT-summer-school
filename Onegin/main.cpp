//
// Created by vladimir on 26.08.22.
//

#include "onegin.h"

int main() {
    Strings strings = fromFile("test.txt");

    sortAsc(&strings);
    writeToFile("output.txt", &strings, "w");

    sortReversed(&strings);
    writeToFile("output.txt", &strings);

    resetComposition(&strings);
    writeToFile("output.txt", &strings);

    freeStrings(&strings);

    return 0;
}