//
// Created by vladimir on 26.08.22.
//

#include <valarray>
#include "onegin.h"
#include <string.h>
#include <clocale>


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

int compareBytes(int char1, int char2) {
    int res1 = 0, res2 = 0;

    for (int i = 0; i < 8; i++) {
        res1 += ((!!((char1 << i) & 0x80)) * (int)pow(2, 8 - i - 1));
        res2 += ((!!((char2 << i) & 0x80)) * (int)pow(2, 8 - i - 1));
    }

    return res1 - res2;
}

int compareFlipped(char *string1, char *string2) {
    int count1 = 0, count2 = 0;

    while (*string1 != '\0') {
        string1++;
        count1++;
    }
    while (*string2 != '\0') {
        string2++;
        count2++;
    }

    while (count1 >= 0 || count2 >= 0) {
        while (!isalnum(*string1) && (!!((*string1 << 0) & 0x80)) == 0) {
            count1--;
            string1--;
        }
        while (!isalnum(*string2) && (!!((*string2 << 0) & 0x80)) == 0) {
            count2--;
            string2--;
        }

        if ((!!((*string1 << 0) & 0x80)) == 1) {
            if ((!!((*string2 << 0) & 0x80)) == 1) {
                int secondPart = compareBytes(*string1, *string2);

                string1--;
                string2--;

                count1--;
                count2--;

                int firstPart = compareBytes(*string1, *string2);
                if (firstPart > 0) {
                    return 1;
                } else if (firstPart < 0) {
                    return -1;
                } else {
                    if (secondPart != 0) {
                        return secondPart;
                    }
                }
            } else {
                return 1;
            }
        } else {
            if ((!!((*string2 << 0) & 0x80)) == 1) {
                return -1;
            } else {
                int result = compareBytes(*string1, *string2);

                if (result != 0) {
                    return result;
                }
            }
        }



        if (count1 <= 0) {
            break;
        }
        if (count2 <= 0) {
            break;
        }

        count1--;
        count2--;
        string1--;
        string2--;
    }

    return 0;
}

void quickSort(Strings *strings, int (*comparator)(char *string1, char *string2), int first, int last) {
    if (first < last) {
        int pivot = first;
        int l = first, r = last;

        while (l < r) {
            while (comparator(strings->array[strings->composition[l]], strings->array[strings->composition[pivot]]) < 0 && l < last) {
                l++;
            }
            while (comparator(strings->array[strings->composition[r]], strings->array[strings->composition[pivot]]) > 0) {
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

        int tmp = strings->composition[pivot];
        strings->composition[pivot]=strings->composition[r];
        strings->composition[r]=tmp;

        quickSort(strings, comparator, first, r - 1);
        quickSort(strings, comparator, r + 1, last);
    }
}

void sortAsc(Strings *strings) {
    quickSort(strings, compareString, 0, strings->size);
}

void sortDesc(Strings *strings) {
    quickSort(strings, compareFlipped, 0, strings->size);
}

void resetComposition(Strings *strings) {
    for (int i = 0; i < strings->size; i++) {
        strings->composition[i] = i;
    }
}