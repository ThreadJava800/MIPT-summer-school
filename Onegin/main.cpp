//
// Created by vladimir on 26.08.22.
//

#include "onegin.h"

int main() {
    Strings strings = fromFile("/home/vladimir/Projects/MIPT summer school/Onegin/test.txt");

    sortAsc(&strings);
    writeToFile("/home/vladimir/Projects/MIPT summer school/Onegin/output.txt", &strings);

    sortReversed(&strings);
    writeToFile("/home/vladimir/Projects/MIPT summer school/Onegin/output.txt", &strings);

    resetComposition(&strings);
    writeToFile("/home/vladimir/Projects/MIPT summer school/Onegin/output.txt", &strings);

    free(strings.array);
    free(strings.composition);

    return 0;
}