#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <ctype.h>

#define size(x)  (sizeof(x) / sizeof((x)[0]))

struct Equation {
    // public
    int a, b, c;
    double discriminantValue;
};

struct pair_arr_int {
    // public
    double *first;
    int second;
};

double *returnLink(const double *arr, int size) {
    double *new_arr = malloc(sizeof(double) * size);
    for (int i = 0; i < size; ++i) {
        new_arr[i] = arr[i];
    }
    return new_arr;
}

double discriminant(struct Equation equation) {
    return equation.b * equation.b - 4 * equation.a * equation.c;
}

double *solveWithOneSolution(struct Equation equation) {
    double value = (-1.0 * equation.b) / (2 * equation.a);
    double result[] = {value};
    return returnLink(result, 1);
}

double *solveWithTwoSolutions(struct Equation equation, double discriminantValue) {
    double first, second;
    first = (-1.0 * equation.b + sqrt(discriminantValue)) / (2 * equation.a);
    second = (-1.0 * equation.b - sqrt(discriminantValue)) / (2 * equation.a);
    double result[] = {first, second};
    return returnLink(result, 2);
}

struct pair_arr_int solve(struct Equation equation) {
    double discriminantValue = discriminant(equation);
    struct pair_arr_int result;
    if (discriminantValue == 0) {
        result.first = solveWithOneSolution(equation);
        result.second = 1;
    } else if (discriminantValue > 0) {
        result.first = solveWithTwoSolutions(equation, discriminantValue);
        result.second = 2;
    } else {
        result.first = NULL;
        result.second = 0;
    }
    return result;
}

void printSolutions(const struct pair_arr_int solution) {
    if (solution.second == 0) {
        printf("У данного уравнения нет решений!");
    } else if (solution.second == 1) {
        printf("%s %f\n", "Данное уравнение имеет лишь одно решение:", solution.first[0]);
    } else {
        printf("%s %f %s %f\n", "Данное уравнение имеет два решения:", solution.first[0], "и",
               solution.first[1]);/**/
    }
}

int readValue(char type) {
    int val;
    if (type == 'a') {
        printf("Введите коэффициент a (!= 0): ");
        scanf("%d", &val);
        if (!isdigit(val)) printf("test");
    } else {
        printf("%s %c %s", "Введите коэффициент ", type, ": ");
        scanf("%d", &val);
    }
    return val;
}

struct Equation readEquation() {
    struct Equation result;
    printf("Программа решает уравнение вида a * x * x + b * x + c = 0\n");
    result.a = readValue('a');
    result.b = readValue('b');
    result.c = readValue('c');
    return result;
}

int main() {
    struct Equation equation = readEquation();
    printSolutions(solve(equation));
    return 0;
}
