#include <stdio.h>
#include <math.h>

#include "equation.h"

bool isZero(const double value) {
    return fabs(value) < epsilon;
}

double discriminant(const struct Equation *equation) {
    double a = equation->a, b = equation->b, c = equation->c;
    return b * b - 4 * a * c;
}

struct EquationSolution solveLinear(const struct Equation *equation) {
    EquationSolution result = EquationSolution();
    double b = equation->b, c = equation->c;

    if (isZero(b)) {
        if (isZero(c)) {
            result.status = INFINITE_SOLUTIONS;
        } else {
            result.status = NO_SOLUTIONS;
        }
    } else {
        result.solution1 = (-c) / (b);

        result.status = ONE_SOLUTION;
    }

    return result;
}

struct EquationSolution solveQuadratic(const struct Equation *equation) {
    double discriminantValue = discriminant(equation);
    double a = equation->a, b = equation->b, c = equation->c;
    EquationSolution result = EquationSolution();

    if (isZero(discriminantValue)) {
        result.solution1 = (-b) / (2 * a);

        result.status = ONE_SOLUTION;
    } else if (discriminantValue >= 0) {
        result.solution1 = (-b + sqrt(discriminantValue)) / (2 * a);
        result.solution2 = (-b - sqrt(discriminantValue)) / (2 * a);

        result.status = TWO_SOLUTIONS;
    } else {
        result.status = NO_SOLUTIONS;
    }

    return result;
}

struct EquationSolution solve(const struct Equation *equation) {
    if (isZero(equation->a)) {
        return solveLinear(equation);
    }
    return solveQuadratic(equation);
}

void printSolutions(const struct EquationSolution *solution) {
    switch (solution->status) {
        case NO_SOLUTIONS:
            printf("У данного уравнения нет решений!");
            break;
        case ONE_SOLUTION:
            printf("Данное уравнение имеет лишь одно решение: %f\n", solution->solution1);
            break;
        case TWO_SOLUTIONS:
            printf("Данное уравнение имеет два решения: %f и %f\n", solution->solution1, solution->solution2);
            break;
        case INFINITE_SOLUTIONS:
            printf("У данного уравнения бесконечное количество решений!");
            break;
        default:
            fprintf(stderr, "Ошибка. Попробуйте ввести уравнение ещё раз");
    }
}

double readValue(const char type) {
    double val = NAN;
    int inputCode = 0;

    printf("Введите коэффициент %c: ", type);

    inputCode = scanf("%lf", &val);

    while(inputCode == 0) {
        printf("Введите корректное число %c: ", type);
        scanf("%*s");
        inputCode = scanf("%lf", &val);
    }

    return val;
}

struct Equation readEquation() {
    Equation result = Equation();

    printf("Программа решает уравнение вида a * x * x + b * x + c = 0\n");

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
