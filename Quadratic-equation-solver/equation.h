#ifndef EQUATION_HEADER
#define EQUATION_HEADER

/**
 * Constant used to compare double with zero
 */
static const double epsilon = 1e-6;

/**
 * Enum of amount of values
 * Can have no solutions, one and two.
 * Also infinite solutions used for equations like 0 * x * x + 0 * x + 0 = 0
 */
typedef enum {
    NO_SOLUTIONS,
    ONE_SOLUTION,
    TWO_SOLUTIONS,
    INFINITE_SOLUTIONS
} SolutionStatus;

/**
 * Contains all coefficients needed for equation
 *
 * @param a, b, c - coefficients
 */
typedef struct Equation {
    double a = NAN, b = NAN, c = NAN;
} Equation;

/**
 * Contains all needed data for equation solution
 *
 * @param solution1, solution2 - solutions
 * @param status - amount of solutions of type @SolutionStatus
 */
typedef struct EquationSolution {
    double solution1 = NAN;
    double solution2 = NAN;
    SolutionStatus status = NO_SOLUTIONS;
} EquationSolution;


/**
 * Counts discriminant:
 * using formula b * b - 4 * a * c,
 * where a, b and c - equation coefficients.
 *
 * @param equation - structure with equation data
 * @return double discriminant value
 */
double discriminant(const struct Equation *equation);

/**
 * Solves linear equation.
 * It is called if a equals 0.
 *
 * @param equation - structure with equation data
 * @return solution of equation of type @EquationSolution
 */
struct EquationSolution solveLinear(const struct Equation *equation);

/**
 * Solves quadratic equation.
 * It is called if a not equals 0.
 * Functions gets equation solutions using basic formulas of mathematics.
 *
 * @param equation - structure with equation data
 * @return solution of equation of type @EquationSolution
 */
struct EquationSolution solveQuadratic(const struct Equation *equation);

/**
 * Figures out what type of equation is this (quadratic or linear)
 * and calls for needed function.
 *
 * @param equation - structure with equation data
 * @return solution of equation of type @EquationSolution.
 */
struct EquationSolution solve(const struct Equation *equation);

/**
 * Prints solutions of equation considering @SolutionStatus enum
 *
 * @param solution - structure with equation solution
 */
void printSolutions(const struct EquationSolution *solution);

/**
 * Reads values of coefficients
 *
 * @param type - coefficient to be entered
 * @return double read value
 */
double readValue(char type);

/**
 * Creates @Equation instance with coefficients read in @printSolutions
 *
 * @return structure with equation
 */
struct Equation readEquation();

/**
 * Main controller of program.
 *
 * @return integer value - result code of program
 */
int main();

#endif
