//
// Created by vladimir on 26.08.22.
//

#include <stdlib.h>
#include "stdio.h"
#include "onegin.h"
#include "malloc.h"
#include "string.h"
#include "errno.h"
#include "assert.h"


Strings fromFile(const char *fileAddress) {
    size_t len = 0, lineCount = 0;
    FILE *file = fopen(fileAddress, "r");
    char *currentLine = (char *) malloc(sizeof(char *));
    char **strings = (char **) malloc(sizeof(char *));

    while (getline(&currentLine, &len, file) != -1) {
        strings = (char **) realloc(strings, (lineCount + 1) * sizeof(char *));
        strings[lineCount] = (char *) malloc((strlen(currentLine) + 1) * sizeof(char));
        strcpy(strings[lineCount], currentLine);

        lineCount++;
    }

    return {.array = strings, .size = lineCount};
}

void printStringArray(Strings strings) {
    for (int i = 0; i < strings.size; i++) {
        printf("%s", strings.array[i]);
    }
}

void printFile(const char *fileAddress) {
    Strings strings = fromFile(fileAddress);
    printStringArray(strings);

    free(strings.array);
}

char *removePuncts(char *string) {
    int stringLen = strlen(string), noPunctIndex = 0;
    char *noPunct = (char *) malloc((stringLen) * sizeof(char));

    for (int i = 0; i < stringLen; i++) {
        if (string[i] != '.' && string[i] != ',' && string[i] != '!' && string[i] != '?' && string[i] != ';' && string[i] != ':') {
            noPunct[noPunctIndex] = string[i];
            noPunctIndex++;
        }
    }

    noPunct[noPunctIndex - 1] = '\0';

    return noPunct;
}

int compareString(char *string1, char *string2) {
    char *noPunct1 = removePuncts(string1);
    char *noPunct2 = removePuncts(string2);

    assert(noPunct1 != nullptr);
    assert(noPunct2 != nullptr);

    int result = strcmp(noPunct1, noPunct2);

    free(noPunct1);
    free(noPunct2);

    return result;
}

void quickSort(Strings strings) {
    int pivot = strings.size / 2;
    int l = 0, r = strings.size - 1;

    while (l <= r) {
        while (compareString(strings.array[l], strings.array[pivot]) < 0) {
            l++;
        }
        while (compareString(strings.array[r], strings.array[pivot]) > 0) {
            r--;
        }

        if (l < r) {
            char *tmp = strings.array[l];
            strings.array[l] = strings.array[r];
            strings.array[r] = tmp;

            l++;
            r--;
        }
    }
}
