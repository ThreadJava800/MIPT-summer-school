#include <stdio.h>
#include <math.h>
#include <cassert>

#include "equation.h"

bool isZero(const double value) {
    return fabs(value) < epsilon;
}

double discriminant(const Equation *equation) {
    assert(equation != nullptr);

    double a = equation->a, b = equation->b, c = equation->c;

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    return b * b - 4 * a * c;
}

void solveLinear(const Equation *equation, EquationSolution *result) {
    assert(equation != nullptr);
    assert(result != nullptr);

    double b = equation->b, c = equation->c;

    assert(isfinite(b));
    assert(isfinite(c));

    if (isZero(b)) {
        if (isZero(c)) {
            result->status = INFINITE_SOLUTIONS;
        } else {
            result->status = NO_SOLUTIONS;
        }
    } else {
        result->status = ONE_SOLUTION;

        result->solution1 = -c / b;
    }
}

void solveQuadratic(const Equation *equation, EquationSolution *result) {
    assert(equation != nullptr);
    assert(result != nullptr);

    double discriminantValue = discriminant(equation);
    double a = equation->a, b = equation->b;

    if (isZero(discriminantValue)) {
        result->status = ONE_SOLUTION;

        result->solution1 = (-b) / (2 * a);
    } else if (discriminantValue > 0) {
        result->status = TWO_SOLUTIONS;

        result->solution1 = (-b + sqrt(discriminantValue)) / (2 * a);
        result->solution2 = (-b - sqrt(discriminantValue)) / (2 * a);
    } else {
        result->status = NO_SOLUTIONS;
    }
}

void solve(const Equation *equation, EquationSolution *result) {
    assert(equation != nullptr);
    assert(result != nullptr);

    if (isZero(equation->a)) {
        solveLinear(equation, result);
    } else {
        solveQuadratic(equation, result);
    }
}

void printSolutions(const EquationSolution *solution) {
    assert(solution != nullptr);

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
            fprintf(stderr, "Ошибка. Но не с вашей стороны :) Свяжитесь с разработчиком (неверный)\n");
    }
}

int readValue(const char type, double *inputValue) {
    assert(inputValue != nullptr);
    assert(type == 'a' || type == 'b' || type == 'c');

    int inputCode = 0, inputCount = 0;

    printf("Введите коэффициент %c: ", type);

    inputCode = scanf("%lf", inputValue);

    while (inputCode != 1) {
        if (inputCode == EOF) {
            return EOF_IN_INPUT;
        }

        if (inputCount == 5) {
            return UNSUCCESSFUL_INPUT;
        }

        inputCount += 1;
        printf("Введите корректное число %c: ", type);
        scanf("%*s");
        inputCode = scanf("%lf", inputValue);
    }

    return SUCCESS;
}

int readEquation(Equation *equation) {
    assert(equation != nullptr);

    int errorCode = 0;

    printf("Программа решает уравнение вида ax^2 + bx + c = 0\n");

    errorCode = readValue('a', &equation->a);
    if (errorCode != SUCCESS) {
        return errorCode;
    }

    errorCode = readValue('b', &equation->b);
    if (errorCode != SUCCESS) {
        return errorCode;
    }

    errorCode = readValue('c', &equation->c);
    if (errorCode != SUCCESS) {
        return errorCode;
    }

    return SUCCESS;
}

//int main() {
//    Equation equation = {};
//    int errorCode = readEquation(&equation);
//    switch (errorCode) {
//        case 0:
//            break;
//        case 1:
//            fprintf(stderr, "Превышено количество попыток ввода (5).");
//            exit(1);
//        case 2:
//            fprintf(stderr, "EOF в конце ввода!");
//            exit(1);
//        default:
//            fprintf(stderr, "");
//    }
//
//    EquationSolution solution = {};
//    solve(&equation, &solution);
//    printSolutions(&solution);
//
//    return 0;
//}
