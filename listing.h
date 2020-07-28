// Compiler Theory and Design
// Code Edited by Zack Finnegan From
// code written by Dr. Duane J. Jarc
// Date 7.26.2020

// This file contains the function prototypes for the functions that produce the // compilation listing

enum ErrorCategories
{
	LEXICAL,
	SYNTAX,
	GENERAL_SEMANTIC,
	DUPLICATE_IDENTIFIER,
	UNDECLARED
};

void firstLine();
void nextLine();
int lastLine();
void appendError(ErrorCategories errorCategory, string message);
