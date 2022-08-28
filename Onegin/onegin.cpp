//
// Created by vladimir on 26.08.22.
//

#include "stdio.h"
#include "onegin.h"
#include "malloc.h"
#include "string.h"


Strings fromFile(const char *fileAddress) {
    size_t len = 0, lineCount = 0, stringsSize = 1;
    FILE *file = fopen(fileAddress, "r");
    char current;
    char *buffer = (char *) calloc(1, 128);
    char **strings = (char **) calloc(stringsSize, sizeof(char *));

    while ((current = fgetc(file)) != EOF) {
        if (current == '\n') {
            buffer[len] = '\0';

            strings[lineCount] = (char *) calloc(len, sizeof(char));
            strcpy(strings[lineCount], buffer);
            lineCount++;

            if (lineCount == stringsSize) {
                stringsSize *= 2;
                strings = (char **) realloc(strings, stringsSize * sizeof(char *));
            }

            buffer[0] = '\0';
            len = 0;
        } else {
            buffer[len] = current;
            len++;
        }
    }

    buffer[len] = '\0';
    strings[lineCount] = (char *) calloc(len, sizeof(char));
    strcpy(strings[lineCount], buffer);
    lineCount++;

    free(buffer);
    fclose(file);

    return {.array = strings, .size = lineCount};
}

void printStringArray(Strings strings) {
    for (int i = 0; i < strings.size; i++) {
        printf("%s\n", strings.array[i]);
    }
}

void printFile(const char *fileAddress) {
    Strings strings = fromFile(fileAddress);
    printStringArray(strings);

    free(strings.array);
}

int compareString(char *string1, char *string2) {
    while (*string1 != '\0' || *string2 != '\0') {
        if (*string1 == '!' || *string1 == '?' || *string1 == '.' || *string1 == ',' || *string1 == ' ' || *string1 == ';' || *string1 == ':') {
            string1++;
        }
        if (*string2 == '!' || *string2 == '?' || *string2 == '.' || *string2 == ',' || *string2 == ' ' || *string2 == ';' || *string2 == ':') {
            string2++;
        }

        if (*string1 > *string2) {
            return 1;
        }
        if (*string1 < *string2) {
            return -1;
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
//
//
//    return result;
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
//    quickSort(strings, compareFlipped);
//}
