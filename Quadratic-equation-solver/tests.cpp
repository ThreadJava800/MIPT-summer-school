#include <cmath>
#include <cstdio>
#include "equation.h"

#define RED_COLOR "\x1b[31m"
#define GREEN_COLOR "\x1b[32m"

struct TestEquation {
    Equation equation;
    EquationSolution solution;
};

bool compareDoubles(const double *val1, const double *val2) {
    return isZero(*val1 - *val2);
}

bool compare(EquationSolution *humanSolution, EquationSolution *machineSolution) {
    if ((machineSolution->status == humanSolution->status && humanSolution->status == NO_SOLUTIONS) ||
            (machineSolution->status == humanSolution->status && humanSolution->status == INFINITE_SOLUTIONS)) {
        return true;
    } else {
        return ((compareDoubles(&machineSolution->solution1, &humanSolution->solution1) &&
                 compareDoubles(&machineSolution->solution1, &humanSolution->solution1)) ||
                (compareDoubles(&machineSolution->solution1, &humanSolution->solution2) &&
                 compareDoubles(&machineSolution->solution2, &humanSolution->solution1)));
    }
}

void printTestSolution(char *pref, EquationSolution *equation) {
    switch (equation->status) {
        case NO_SOLUTIONS:
            printf(RED_COLOR"    %s: no roots\n", pref);
            break;
        case ONE_SOLUTION:
            printf(RED_COLOR"    %s: one root, x1 = %lf\n", pref, equation->solution1);
            break;
        case TWO_SOLUTIONS:
            printf(RED_COLOR"    %s: two roots, x1 = %lf, x2 = %lf\n", pref, equation->solution1, equation->solution2);
            break;
        case INFINITE_SOLUTIONS:
            printf(RED_COLOR"    %s: infinite roots\n", pref);
            break;
        default:
            fprintf(stderr, "    Please contact developer!\n");
    }
}

int runTests() {
    int successfulTests = 0;
    TestEquation tests[10] = {{{.a =  1, .b = -2, .c =  1}, {.solution1 = 1, .solution2 = NAN, .status = ONE_SOLUTION}},
                              {{.a = 1, .b = 2, .c = 1},    {.solution1 = -1, .solution2 = NAN, .status = ONE_SOLUTION}},
                              {{.a = 0, .b = 0, .c = 0},    {.solution1 = NAN, .solution2 =  NAN, .status = INFINITE_SOLUTIONS}},
                              {{.a = 1, .b = 3, .c = 2},    {.solution1 = -1, .solution2 = -2, .status = TWO_SOLUTIONS}},
                              {{.a = 5, .b = 3, .c = 2},    {.solution1 = NAN, .solution2 =  NAN, .status = NO_SOLUTIONS}},
                              {{.a = 8, .b = 3, .c = 2},    {.solution1 = NAN, .solution2 =  NAN, .status = NO_SOLUTIONS}},
                              {{.a = 1, .b = 8, .c = 16},    {.solution1 = -4, .solution2 =  NAN, .status = ONE_SOLUTION}},
                              {{.a = 2, .b = 8, .c = 16},    {.solution1 = NAN, .solution2 =  NAN, .status = NO_SOLUTIONS}},
                              {{.a = 2, .b = -5, .c = 2},    {.solution1 = 0.5, .solution2 =  2, .status = TWO_SOLUTIONS}},
                              {{.a = 1, .b = -6, .c = 9},    {.solution1 = 3, .solution2 =  NAN, .status = ONE_SOLUTION}}};

    for (int i = 0; i < 10; i++) {
        Equation *equation = &tests[i].equation;
        EquationSolution humanSolution = tests[i].solution;
        EquationSolution machineSolution = {};
        solve(equation, &machineSolution);
        if (compare(&humanSolution, &machineSolution)) {
            printf(GREEN_COLOR"Test №%d: PASSED\n", i + 1);
            successfulTests++;
        } else {
            printf(RED_COLOR"Test №%d: FAILED\nInfo about equation:\n", i + 1);
            printf(RED_COLOR"    a = %lf, b = %lf, c = %lf\n", equation->a, equation->b, equation->c);
            printTestSolution("Expected", &humanSolution);
            printTestSolution("Given", &machineSolution);
        }
    }

    return successfulTests;
}


int main() {
    int passed = runTests();
    printf(GREEN_COLOR "Tests passed %d/10\n", passed);
    if (passed < 10) {
        printf(RED_COLOR "Tests failed %d/10", 10 - passed);
    }

    return 0;
}