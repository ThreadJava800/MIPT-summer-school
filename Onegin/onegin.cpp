//
// Created by vladimir on 26.08.22.
//

#include <valarray>
#include "onegin.h"
#include <string.h>



Strings fromFile(const char *fileAddress) {
    int stringAmount = 0;
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
    int *composition = (int *) calloc(stringAmount, sizeof(int));

    int stringsIndex = 1;
    strings[0] = &buffer[0];
    composition[0] = 0;

    for (int i = 0; i < fileSize; i++) {
        if (buffer[i] == '\n' || buffer[i] == '\0') {
            buffer[i] = '\0';
            strings[stringsIndex] = &buffer[i + 1];

            composition[stringsIndex] = stringsIndex;

            stringsIndex++;
        }
    }
    buffer -= fileSize;

    printf("%s", buffer);

    fclose(file);

    return {.buffer = buffer, .array = strings, .composition = composition, .size = stringAmount};
}

void writeToFile(FILE *file, const char *string) {
    fprintf(file, "%s\n", string);
}

void writeToFile(const char *fileAddress, const Strings *strings) {
    FILE *file = fopen(fileAddress, "a");

    for (int i = 0; i < strings->size; i++) {
        writeToFile(file, strings->array[strings->composition[i]]);
    }
    writeToFile(file, "\n");

    fclose(file);
}

void printStringArray(Strings *strings) {
    for (int i = 0; i < strings->size; i++) {
        printf("%s\n", strings->array[i]);
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

        printf("%s %s\n", string1, string2);

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

int compareFlipped(char *string1, char *string2) {
    strrev();

//    while ((end1 >= string1) || (end2 >= string2)) {
//        while (!isalnum(*end1) && *end1 == ' ') {
//            end1--;
//        }
//        while (!isalnum(*end2) && *end2 == ' ') {
//            end2--;
//        }
//
//        if (*end1 > *end2) {
//            return 1;
//        }
//        if (*end1 < *end2) {
//            return -1;
//        }
//
//        if (end1 == string1) {
//            return 1;
//        }
//        if (end2 == string2) {
//            return -1;
//        }
//
//        end1--;
//        end2--;
//    }

    return 0;
}

void quickSort(Strings *strings, int (*comparator)(char *string1, char *string2)) {
    resetComposition(strings);

    int pivot = strings->size / 2;
    int l = 0, r = strings->size - 1;

    while (l <= r) {
        while (comparator(strings->array[l], strings->array[pivot]) < 0) {
            l++;
        }
        while (comparator(strings->array[r], strings->array[pivot]) > 0) {
            r--;
        }

        if (l < r) {
            int tmp = strings->composition[l];
            strings->composition[l] = strings->composition[r];
            strings->composition[r] = tmp;

            l++;
            r--;
        }
    }
}

void sortAsc(Strings *strings) {
    quickSort(strings, compareString);
}

void sortDesc(Strings *strings) {
    quickSort(strings, compareFlipped);
}

void resetComposition(Strings *strings) {
    for (int i = 0; i < strings->size; i++) {
        strings->composition[i] = i;
    }
}