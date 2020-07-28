// CMSC 430
// Code edited by Zack Finnegan from code written by
// Duane J. Jarc
// 7/26/2020

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
double checkCase(double back4, double back2, double forward2, double answer);
double getCaseAnswer();
void caseCalled();
void endcaseCalled();
void nestedCaseCheck(double back4);
void isFirstCheck(double caseExpression);