#ifndef EQUATION_HEADER
#define EQUATION_HEADER

enum ErrorCode {
    SUCCESS = 0,
    UNSUCCESSFUL_INPUT = 1,
    EOF_IN_INPUT = 2,
};

enum SolutionStatus {
    INFINITE_SOLUTIONS = -1,
    NO_SOLUTIONS = 0,
    ONE_SOLUTION = 1,
    TWO_SOLUTIONS = 2,
};

/**
 * Contains all coefficients needed for equation
 *
 * @param a - first coefficient of equation
 * @param b - second coefficient of equation
 * @param c - thirst coefficient of equation
 */
typedef struct Equation {
    double a = NAN, b = NAN, c = NAN;
} Equation;

/**
 * Contains all needed data for equation solution
 *
 * @param solution1 - first solution
 * @param solution2 - second solution
 * @param status - amount of solutions of type @SolutionStatus
 */
typedef struct EquationSolution {
    double solution1 = NAN;
    double solution2 = NAN;
    SolutionStatus status = NO_SOLUTIONS;
} EquationSolution;

/**
 * Constant used to compare double with zero
 */
const double epsilon = 1e-12;

/**
 * Checks whether double value equals zero using @epsilon
 *
 * @param value - double value
 * @return false or true - is value == 0 or not
 */
bool isZero(const double value);

/**
 * Counts discriminant:
 * using formula b^2 - 4ac,
 * where a, b and c - equation coefficients.
 *
 * @param equation - structure with equation data
 * @return double discriminant value
 */
double discriminant(const Equation *equation);

/**
 * Solves linear equation.
 * It is called if a equals 0.
 *
 * @param equation - structure with equation data
 * @return solution of equation of type @EquationSolution
 */
void solveLinear(const Equation *equation, EquationSolution *result);

/**
 * Solves quadratic equation.
 * It is called if a not equals 0.
 * Functions gets equation solutions using basic formulas of mathematics.
 *
 * @param equation - structure with equation data
 * @return solution of equation of type @EquationSolution
 */
void solveQuadratic(const Equation *equation, EquationSolution *result);

/**
 * Figures out what type of equation is this (quadratic or linear)
 * and calls for needed function.
 *
 * @param equation - structure with equation data
 * @return solution of equation of type @EquationSolution.
 */
void solve(const Equation *equation, EquationSolution *result);

/**
 * Prints solutions of equation considering @SolutionStatus enum
 *
 * @param solution - structure with equation solution
 */
void printSolutions(const EquationSolution *solution);

/**
 * Reads values of coefficients
 *
 * @param type - coefficient to be entered
 * @return double read value
 */
int readValue(const char type, double *inputValue);

/**
 * Creates @Equation instance with coefficients read in @printSolutions
 *
 * @return structure with equation
 */
int readEquation(Equation *equation);

/**
 * Main controller of program.
 *
 * @return integer value - result code of program
 */
int main();

#endif
