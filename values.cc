// CMSC 430
// Code edited by Zack Finnegan from code written by
// Duane J. Jarc
// 7/26/2020

// This file contains the bodies of the evaluation functions

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#include "values.h"
#include "listing.h"

double caseAnswer = NAN;
bool answered = false;
int cases = 0;
bool isNestedCase = false;
bool isOuterCaseBad = false;
bool isFirst = true;
double outerCaseExp = NAN;

double evaluateReduction(Operators operator_, double head, double tail)
{
	if (operator_ == ADD)
		return head + tail;
	return head * tail;
}

double evaluateRelational(double left, Operators operator_, double right)
{
	double result;
	switch (operator_)
	{
	case LESS:
		result = left < right;
		break;
	case GREAT:
		result = left > right;
		break;
	case EQUAL:
		result = left == right;
		break;
	case NOTEQUAL:
		result = left != right;
		break;
	case LESSOREQUAL:
		result = left <= right;
		break;
	case GREATOREQUAL:
		result = left >= right;
		break;
	}
	return result;
}

double evaluateArithmetic(double left, Operators operator_, double right)
{
	cout << endl;
	double result;
	switch (operator_)
	{
	case ADD:
		result = left + right;
		//cout << left << " + " << right << " = " << result << endl;
		break;
	case SUBTRACT:
		result = left - right;
		//cout << left << " - " << right << " = " << result << endl;
		break;
	case MULTIPLY:
		result = left * right;
		//cout << left << " * " << right << " = " << result << endl;
		break;
	case DIVIDE:
		result = left / right;
		//cout << left << " / " << right << " = " << result << endl;
		break;
	case REMAINDER:
		result = (int)round(left) % (int)round(right);
		//cout
		//	<< left << " % " << right << " = " << result << endl;
		break;
	case EXPONENT:
		result = pow(left, right);
		//cout << left << " ^ " << right << " = " << result << endl;
		break;
	}
	return result;
}





/*

	I need to set the outer case expression to a value right away as a global variable.
	RIght now back 6 is not taking the expresson from the outer case but the value before
	the ; in the line directly above it.

*/








double checkCase(double back4, double back2, double forward2, double answer)
{
	isFirstCheck(back2);
	nestedCaseCheck(back4);
	if (back2 == forward2)
	{
		if (cases == 1 || cases > 1 && !isOuterCaseBad)
		{
			if (!answered)
			{
				caseAnswer = answer;
				answered = true;
				return answer;
			}
			return NAN;
		}
		else {
			return NAN;
		}
	}
	else
	{
		return NAN;
	}
}

void nestedCaseCheck(double back4){
	if (cases > 1 && !isNestedCase)
	{
		isNestedCase = true;
		if (outerCaseExp != back4)
		{
			isOuterCaseBad = true;
		}
	}
}

void isFirstCheck(double caseExpression){
	if(isFirst){
		outerCaseExp = caseExpression;
		isFirst = false;
	}
}

double getCaseAnswer()
{
	return caseAnswer;
}

void caseCalled()
{
	cases++;
}

void endcaseCalled()
{
	cases--;
}
