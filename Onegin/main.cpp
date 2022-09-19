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

    writeBytesToFile(strings.buffer, strings.bufferSize, "output.txt");

    freeStrings(&strings);

    return 0;
}