/* Compiler Theory and Design
   Code edited by Zack Finnegan
   From code written by
   Dr. Duane J. Jarc */

%{

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#include "values.h"
#include "listing.h"
#include "symbols.h"

int yylex();
void yyerror(const char* message);

Symbols<int> symbols;

double result;

%}

%error-verbose

%union
{
	CharPtr iden;
	Operators oper;
	int value;
}

%token <iden> IDENTIFIER
%token <value> INT_LITERAL REAL_LITERAL BOOL_LITERAL

%token <oper> ADDOP MULOP RELOP EXPOP REMOP 
%token ANDOP OROP NOTOP ARROW

%token BEGIN_ BOOLEAN END ENDREDUCE FUNCTION INTEGER IS REDUCE RETURNS REAL IF ENDIF ELSE THEN


%type <value> body statement_ statement reductions expression relation term
	factor primary exp binary_logic unary_logic
%type <oper> operator

%%

function:	
	function_header optional_variable body {result = $3;} ;
	
function_header:	
	FUNCTION IDENTIFIER parameters RETURNS type ';' |
	error ';' ;

optional_variable:
	optional_variable variable | error ';' | ;

variable:	
	IDENTIFIER ':' type IS statement_ {symbols.insert($1, $5);} ;

parameters:
	parameters ',' parameter | parameter | ;

parameter:
	IDENTIFIER ':' type;

type:
	INTEGER |
	REAL |
	BOOLEAN ;

body:
	BEGIN_ statement_ END ';' {$$ = $2;} ;
    
statement_:
	statement ';' |
	error ';' {$$ = 0;} ;
	
statement:
	expression |
	REDUCE operator reductions ENDREDUCE {$$ = $3;} |
	IF expression THEN statement_ ELSE statement_ ENDIF {$$ = $2 ? $4 : $6;};

operator:
	ADDOP |	MULOP | REMOP | EXPOP | RELOP ;

reductions:
	reductions statement_ {$$ = evaluateReduction($<oper>0, $1, $2);} |
	{$$ = $<oper>0 == ADD ? 0 : 1;} ;

expression:
	expression OROP binary_logic {$$ = $1 || $3;} |
	binary_logic ;

binary_logic:
	binary_logic ANDOP unary_logic {$$ = $1 && $3;} |
	unary_logic ;

unary_logic:
	NOTOP unary_logic {$$ = ! $2;}|
	relation ;

relation:
	relation RELOP term {$$ = evaluateRelational($1, $2, $3);} |
	term ;

term:
	term ADDOP factor {$$ = evaluateArithmetic($1, $2, $3);} |
	factor ;
      
factor:
	factor MULOP exp {$$ = evaluateArithmetic($1, $2, $3);} |
	factor REMOP exp {$$ = evaluateArithmetic($1, $2, $3);} |
	exp ;

exp:
	primary |
	primary EXPOP exp {$$ = evaluateArithmetic($1, $2, $3);} ;

primary:
	'(' expression ')' {$$ = $2;} |
	INT_LITERAL | REAL_LITERAL | BOOL_LITERAL |
	IDENTIFIER {if (!symbols.find($1, $$)) appendError(UNDECLARED, $1);} ;

%%

void yyerror(const char* message)
{
	appendError(SYNTAX, message);
}

int main(int argc, char *argv[])    
{
	firstLine();
	yyparse();
	if (lastLine() == 0)
		cout << "Result = " << result << endl;
	return 0;
} 
