//
// Created by vladimir on 26.08.22.
//
#include "stdlib.h"

#include "onegin.h"
#include "locale.h"

int main() {
    Strings strings = fromFile("/home/vladimir/Projects/MIPT summer school/Onegin/test.txt");
    for (int i = 0; i < strings.size; i++) {
        printf("%d ", strings.composition[i]);
    }

//    sortAsc(&strings);
//    writeToFile("/home/vladimir/Projects/MIPT summer school/Onegin/output.txt", &strings);

    sortDesc(&strings);
    writeToFile("/home/vladimir/Projects/MIPT summer school/Onegin/output.txt", &strings);

//    FILE *file = fopen("/home/vladimir/Projects/MIPT summer school/Onegin/output.txt", "a");
//
//    while (*strings.buffer != '\0') {
//        writeToFile(file, strings.buffer);
//        while (*strings.buffer != '\n') {
//            strings.buffer++;
//        }
//        strings.buffer++;
//    }

    //printStringArray(strings);

//    free(strings.array);
//    free(strings.buffer);
//    free(strings.composition);

    return 0;
}