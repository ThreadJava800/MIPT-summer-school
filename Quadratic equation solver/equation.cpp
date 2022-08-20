#include <stdio.h>
#include <math.h>

static const double epsilon = 0.00001;

enum SolutionStatus {
    NO_SOLUTIONS,
    ONE_SOLUTION,
    TWO_SOLUTIONS,
    INFINITE_SOLUTIONS
};

struct Equation {
    double a = NAN, b = NAN, c = NAN;
};

struct EquationSolution {
    double solution1 = NAN;
    double solution2 = NAN;
    SolutionStatus status = NO_SOLUTIONS;
};

double discriminant(const struct Equation *equation) {
    return equation->b * equation->b - 4 * equation->a * equation->c;
}

struct EquationSolution solveLinear(const struct Equation *equation) {
    struct EquationSolution result = EquationSolution();

    if (fabs(equation->b) < epsilon && fabs(equation->c) < epsilon) {
        result.status = INFINITE_SOLUTIONS;
    } else if (fabs(equation->b) < epsilon) {
        result.status = NO_SOLUTIONS;
    } else {
        result.solution1 = (-equation->c) / (equation->b);

        result.status = ONE_SOLUTION;
    }

    return result;
}

struct EquationSolution solveQuadratic(const struct Equation *equation) {
    double discriminantValue = discriminant(equation);
    struct EquationSolution result = EquationSolution();

    if (fabs(discriminantValue) < epsilon) { // comparing double with zero
        result.solution1 = (-equation->b) / (2 * equation->a);

        result.status = ONE_SOLUTION;
    } else if (discriminantValue >= 0) {
        result.solution1 = (-equation->b + sqrt(discriminantValue)) / (2 * equation->a);
        result.solution2 = (-equation->b - sqrt(discriminantValue)) / (2 * equation->a);

        result.status = TWO_SOLUTIONS;
    } else {
        result.status = NO_SOLUTIONS;
    }

    return result;
}

struct EquationSolution solve(const struct Equation *equation) {
    // check if equation is linear
    if (fabs(equation->a) < epsilon) {
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
            printf("Ошибка. Введите другое уравнение!");
    }
}

double readValue(const char type) {
    double val = NAN;

    printf("Введите коэффициент %c: ", type);
    scanf("%lf", &val);

    return val;
}

struct Equation readEquation() {
    struct Equation result = Equation();

    printf("Программа решает уравнение вида a * x * x + b * x + c = 0\n");

    result.a = readValue('a');
    result.b = readValue('b');
    result.c = readValue('c');

    return result;
}

int main() {
    struct Equation equation = readEquation();

    struct EquationSolution solution = solve(&equation);
    printSolutions(&solution);

    return 0;
}
