#include <stdio.h>
#include <math.h>

static const double DELTA = 0.00001;

enum EquationSolutionStatus {
    NO_SOLUTIONS,
    ONE_SOLUTION,
    TWO_SOLUTIONS,
    INFINITE_SOLUTIONS
};

struct Equation {
    // public
    double a, b, c;
} EquationDefault = {0, 0, 0};

struct EquationResult {
    // public
    double *solutions;
    enum EquationSolutionStatus solutionStatus;
} EquationResultDefault = {NULL, NO_SOLUTIONS};

double discriminant(const struct Equation *equation) {
    return equation->b * equation->b - 4 * equation->a * equation->c;
}

struct EquationResult solve(const struct Equation *equation) {
    double discriminantValue = NAN;
    struct EquationResult result = EquationResultDefault;

    // check if equation is linear
    if (fabs(equation->a) < DELTA) {
        if (fabs(equation->b) < DELTA && fabs(equation->c) < DELTA) {
            result.solutions = NULL;
            result.solutionStatus = INFINITE_SOLUTIONS;
        } else {
            double solutions[1] = {(-1.0 * equation->c) / (equation->b)};
            result.solutions = solutions;
            result.solutionStatus = ONE_SOLUTION;
        }
        return result;
    }

    discriminantValue = discriminant(equation);
    if (fabs(discriminantValue) < DELTA) { // comparing double with zero
        double solutions[1] = {(-1.0 * equation->b) / (2 * equation->a)};
        result.solutions = solutions;
        result.solutionStatus = ONE_SOLUTION;
    } else if (discriminantValue >= DELTA) {
        double firstSolution = (-1.0 * equation->b + sqrt(discriminantValue)) / (2 * equation->a);
        double secondSolution = (-1.0 * equation->b - sqrt(discriminantValue)) / (2 * equation->a);
        double solutions[2] = {firstSolution, secondSolution};
        result.solutions = solutions;
        result.solutionStatus = TWO_SOLUTIONS;
    } else {
        result.solutions = NULL;
        result.solutionStatus = NO_SOLUTIONS;
    }
    return result;
}

void printSolutions(const struct EquationResult *result) {
    if (result->solutionStatus == NO_SOLUTIONS) {
        printf("У данного уравнения нет решений!");
    } else if (result->solutionStatus == ONE_SOLUTION) {
        printf("%s %f\n", "Данное уравнение имеет лишь одно решение:", result->solutions[0]);
    } else if (result->solutionStatus == TWO_SOLUTIONS) {
        printf("%s %f %s %f\n", "Данное уравнение имеет два решения:", result->solutions[0], "и",
               result->solutions[1]);/**/
    } else {
        printf("У данного уравнения бесконечное количество решений!");
    }
}

double readValue(const char type) {
    double val = NAN;
    printf("%s %c%s", "Введите коэффициент", type, ": ");
    scanf("%lf", &val);
    return val;
}

struct Equation readEquation() {
    struct Equation result = EquationDefault;
    printf("Программа решает уравнение вида a * x * x + b * x + c = 0\n");
    result.a = readValue('a');
    result.b = readValue('b');
    result.c = readValue('c');
    return result;
}

int main() {
    struct Equation equation = readEquation();
    struct EquationResult equationResult = solve(&equation);
    printSolutions(&equationResult);
    return 0;
}
