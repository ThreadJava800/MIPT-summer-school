#include <bits/stdc++.h>

using namespace std;

enum class SolutionCount {
    ZERO, ONE, TWO
};

enum class Coefficients {
    a, b, c
};

map<Coefficients, string> str_coefficients = {{Coefficients::a, "a"},
                                              {Coefficients::b, "b"},
                                              {Coefficients::c, "c"}};

class Equation {
private:
    int a, b, c;
    double discriminantValue{};

    [[nodiscard]] double discriminant() const;

    [[nodiscard]] double solveWithOneSolution() const;

    [[nodiscard]] vector<double> solveWithTwoSolutions() const;

public:
    Equation(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    pair<vector<double>, SolutionCount> solve();
};

double Equation::discriminant() const {
    return b * b - 4 * a * c;
}

double Equation::solveWithOneSolution() const {
    return (-1.0 * b) / (2 * a);
}

vector<double> Equation::solveWithTwoSolutions() const {
    double first, second;
    first = (-1.0 * b + sqrt(discriminantValue)) / (2 * a);
    second = (-1.0 * b - sqrt(discriminantValue)) / (2 * a);
    return {first, second};
}

pair<vector<double>, SolutionCount> Equation::solve() {
    this->discriminantValue = discriminant();
    if (discriminantValue == 0) return {{solveWithOneSolution()}, SolutionCount::ONE};
    else if (discriminantValue > 0) return {solveWithTwoSolutions(), SolutionCount::TWO};
    return {vector<double>(), SolutionCount::ZERO};
}

void printSolutions(const pair<vector<double>, SolutionCount> &solution) {
    if (solution.second == SolutionCount::ZERO) {
        cout << "У данного уравнения нет решений!";
    } else if (solution.second == SolutionCount::ONE) {
        cout << "Данное уравнение имеет лишь одно решение: " << solution.first[0];
    } else {
        cout << "Данное уравнение имеет два решения: " << solution.first[0] << " и " << solution.first[1];
    }
}

int readValue(Coefficients type) {
    int val;
    if (type == Coefficients::a) {
        cout << "Введите коэффициент a (!= 0): ";
        cin >> val;
        while (val == 0 || cin.fail()) {
            cout << "Введите корректное число! Обратите внимание, что a != 0!\n";
            cout << "Введите коэффициент " + str_coefficients[type] + ": ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> val;
        }
    } else {
        cout << "Введите коэффициент " + str_coefficients[type] + ": ";
        cin >> val;
        while (cin.fail()) {
            cout << "Введите корректное число!\n";
            cout << "Введите коэффициент " + str_coefficients[type] + ": ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> val;
        }
    }
    return val;
}

Equation readEquation() {
    int a = 0, b, c;
    cout << "Программа решает уравнение вида a * x * x + b * x + c = 0\n";
    a = readValue(Coefficients::a);
    b = readValue(Coefficients::b);
    c = readValue(Coefficients::c);
    return {a, b, c};
}

int main() {
    Equation equation = readEquation();
    printSolutions(equation.solve());
    return 0;
}
