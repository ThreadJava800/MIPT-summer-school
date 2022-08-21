#include <stdio.h>
#include <math.h>

#include "equation.h"

bool isZero(const double value) {
    return fabs(value) < epsilon;
}

double discriminant(const Equation *equation) {
    double a = equation->a, b = equation->b, c = equation->c;
    return b * b - 4 * a * c;
}

EquationSolution solveLinear(const Equation *equation) {
    EquationSolution result = {};
    double b = equation->b, c = equation->c;

    if (isZero(b)) {
        if (isZero(c)) {
            result.status = INFINITE_SOLUTIONS;
        } else {
            result.status = NO_SOLUTIONS;
        }
    } else {
        result.status = ONE_SOLUTION;

        result.solution1 = -c / b;
    }

    return result;
}

EquationSolution solveQuadratic(const Equation *equation) {
    double discriminantValue = discriminant(equation);
    double a = equation->a, b = equation->b;
    EquationSolution result = {};

    if (isZero(discriminantValue)) {
        result.status = ONE_SOLUTION;

        result.solution1 = (-b) / (2 * a);
    } else if (discriminantValue >= 0) {
        result.status = TWO_SOLUTIONS;

        result.solution1 = (-b + sqrt(discriminantValue)) / (2 * a);
        result.solution2 = (-b - sqrt(discriminantValue)) / (2 * a);
    } else {
        result.status = NO_SOLUTIONS;
    }

    return result;
}

EquationSolution solve(const Equation *equation) {
    if (isZero(equation->a)) {
        return solveLinear(equation);
    }
    return solveQuadratic(equation);
}

void printSolutions(const EquationSolution *solution) {
    switch (solution->status) {
        case NO_SOLUTIONS:
            printf("У данного уравнения нет решений!");
            break;
        case ONE_SOLUTION:
            printf("Данное уравнение имеет лишь одно решение: %lf\n", solution->solution1);
            break;
        case TWO_SOLUTIONS:
            printf("Данное уравнение имеет два решения: %lf и %lf\n", solution->solution1, solution->solution2);
            break;
        case INFINITE_SOLUTIONS:
            printf("У данного уравнения бесконечное количество решений!");
            break;
        default:
            fprintf(stderr, "Ошибка. Но не с вашей стороны :) Свяжитесь с разработчиком (неверный .");
    }
}

double readValue(const char type) {
    double val = NAN;
    int inputCode = 0;

    printf("Введите коэффициент %c: ", type);

    inputCode = scanf("%lf", &val);

    while (inputCode == 0) {
        printf("Введите корректное число %c: ", type);
        scanf("%*s");
        inputCode = scanf("%lf", &val);
    }

    return val;
}

Equation readEquation() {
    Equation result = {};

    printf("Программа решает уравнение вида ax^2 + bx + c = 0\n");

    result.a = readValue('a');
    result.b = readValue('b');
    result.c = readValue('c');

    return result;
}

int main() {
    Equation equation = readEquation();

    EquationSolution solution = solve(&equation);
    printSolutions(&solution);

    return 0;
}
