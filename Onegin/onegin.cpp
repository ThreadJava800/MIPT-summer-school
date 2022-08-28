//
// Created by vladimir on 26.08.22.
//

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <ctype.h>

#include "onegin.h"



Strings fromFile(const char *fileAddress) {
    int stringAmount = 0;
    char current = EOF;
    FILE *file = fopen(fileAddress, "rb+");

    assert(file != nullptr);

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, SEEK_END - 2, SEEK_SET);

    char *buffer = (char *) calloc(fileSize, sizeof(char));
    fread(buffer, sizeof(char), fileSize, file);

    for (int i = 0; i <= fileSize; i++) {
        if (buffer[i] == '\n' || buffer[i] == '\0') {
            stringAmount++;
        }
    }

    char **strings = (char **) calloc(stringAmount, sizeof(char *));
    int stringsIndex = 1;
    strings[0] = &buffer[0];
    for (int i = 0; i < fileSize; i++) {
        if (buffer[i] == '\n' || buffer[i] == '\0') {
            buffer[i] = '\0';
            strings[stringsIndex] = &buffer[i + 1];

            stringsIndex++;
        }
    }

    fclose(file);

    return {.buffer = buffer, .array = strings, .size = stringAmount};
}

void writeToFile(FILE *file, const char *string) {
    fprintf(file, "%s\n", string);
}

void writeToFile(const char *fileAddress, const Strings *strings) {
    FILE *file = fopen(fileAddress, "w");

    for (int i = 0; i < strings->size; i++) {
        writeToFile(file, strings->array[i]);
    }
}

void printStringArray(Strings strings) {
    for (int i = 0; i < strings.size; i++) {
        printf("%s\n", strings.array[i]);
    }
}

int compareString(char *string1, char *string2) {
    while (*string1 != '\0' || *string2 != '\0') {
        while (!isalnum(*string1) && *string1 == ' ') {
            string1++;
        }
        while (!isalnum(*string2) && *string2 == ' ') {
            string2++;
        }

        int result = *string1 - *string2;
        if (result != 0) {
            return result;
        }

        if (*string1 == '\0') {
            return 1;
        }
        if (*string2 == '\0') {
            return -1;
        }

        string1++;
        string2++;
    }

    return 0;
}

//int compareFlipped(char *string1, char *string2) {
//    int index1 =
//}

void quickSort(Strings strings, int (*comparator)(char *string1, char *string2)) {
    int pivot = strings.size / 2;
    int l = 0, r = strings.size - 1;

    while (l <= r) {
        while (comparator(strings.array[l], strings.array[pivot]) < 0) {
            l++;
        }
        while (comparator(strings.array[r], strings.array[pivot]) > 0) {
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

void sortAsc(Strings strings) {
    quickSort(strings, compareString);
}

//void sortDesc(Strings strings) {
//    quickSort(strx`ings, compareFlipped);
//}