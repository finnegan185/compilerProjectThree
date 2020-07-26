// CMSC 430
// Duane J. Jarc

// This file contains function definitions for the evaluation functions

typedef char *CharPtr;
enum Operators
{
    LESS,
    GREAT,
    EQUAL,
    NOTEQUAL,
    GREATOREQUAL,
    LESSOREQUAL,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    REMAINDER,
    EXPONENT
};

double evaluateReduction(Operators operator_, double head, double tail);
double evaluateRelational(double left, Operators operator_, double right);
double evaluateArithmetic(double left, Operators operator_, double right);
double setCaseAnswer(double answer);
double getCaseAnswer();
