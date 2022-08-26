//
// Created by vladimir on 26.08.22.
//

#include <cstring>
#include "stdio.h"
#include "onegin.h"
#include "malloc.h"


Strings fromFile(const char *fileAddress) {
    size_t len = 0, lineCount = 0;
    FILE *file = fopen(fileAddress, "r");
    char *currentLine = (char *) malloc(sizeof(char *));
    char **strings = (char **) malloc(sizeof(char *));

    while (getline(&currentLine, &len, file) != -1) {
        strings = (char **) realloc(strings, (lineCount + 1) * sizeof(char *));
        strings[lineCount] = (char *) malloc(strlen(currentLine) * sizeof(char));
        strcpy(strings[lineCount], currentLine);

        lineCount++;
    }

    return {.array = strings, .size = lineCount};
}

void printFile(const char *fileAddress) {
    Strings strings = fromFile(fileAddress);

    printf("%s", strings.array[2]);

//    for (int i = 0; i < strings.size; i++) {
//        printf("%s\n", strings.array[i]);
//    }
}
