// CMSC 430
// Duane J. Jarc

// This file contains the bodies of the evaluation functions

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#include "values.h"
#include "listing.h"

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
	//	cout
	//		<< left << " % " << right << " = " << result << endl;
		break;
	case EXPONENT:
		result = pow(left, right);
		//cout << left << " ^ " << right << " = " << result << endl;
		break;
	}
	return result;
}

