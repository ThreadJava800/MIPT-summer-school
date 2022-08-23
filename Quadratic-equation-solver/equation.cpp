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
            printf("This equation doesn't have any solutions!");
            break;
        case ONE_SOLUTION:
            printf("This equation has one solution: %lf\n", solution->solution1);
            break;
        case TWO_SOLUTIONS:
            printf("This equation has two solutions: %lf и %lf\n", solution->solution1, solution->solution2);
            break;
        case INFINITE_SOLUTIONS:
            printf("This equation has infinite solutions!");
            break;
        default:
            fprintf(stderr, "Error. But it's not yours :) Please contact developer (incorrect SolutionStatus)\n");
    }
}

int readValue(const char type, double *inputValue) {
    assert(inputValue != nullptr);
    assert(type == 'a' || type == 'b' || type == 'c');

    int inputCode = 0, inputCount = 0;

    printf("Enter coefficient %c: ", type);

    inputCode = scanf("%lf", inputValue);

    while (inputCode != 1) {
        if (inputCode == EOF) {
            return EOF_IN_INPUT;
        }

        if (inputCount == 5) {
            return UNSUCCESSFUL_INPUT;
        }

        inputCount += 1;
        printf("Please provide correct coefficient %c: ", type);
        scanf("%*s");
        inputCode = scanf("%lf", inputValue);
    }

    return SUCCESS;
}

int readEquation(Equation *equation) {
    assert(equation != nullptr);

    int errorCode = 0;

    printf("Program solves equations like ax^2 + bx + c = 0\n");

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

int main() {
    Equation equation = {};
    int errorCode = readEquation(&equation);
    switch (errorCode) {
        case 0:
            break;
        case 1:
            fprintf(stderr, "Too many input attempts (5).");
            return EXIT_FAILURE;
        case 2:
            fprintf(stderr, "EOF in the end of input!");
            return EXIT_FAILURE;
        default:
            fprintf(stderr, "");
    }

    EquationSolution solution = {};
    solve(&equation, &solution);
    printSolutions(&solution);

    return 0;
}
