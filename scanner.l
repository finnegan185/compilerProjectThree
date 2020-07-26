/* Compiler Theory and Design
   Code edited by Zack Finnegan 
   from code created by Dr. Duane J. Jarc
   Date: 7.9.2020 */

/* This file contains flex input file */

%{
#include <cstdio>
#include <string>

using namespace std;

#include "values.h"
#include "listing.h"
#include "tokens.h"

%}

%option noyywrap

ws			[ \t\r]+
comment	\-\-.*\n|\/\/.*\n
line		[\n]
id			[A-Za-z][A-Za-z0-9]*(\_?[A-Za-z0-9]+)*
digit		[0-9]
int		{digit}+
punc		[\(\),:;]
real_lit	{int}*(\.?{int}*)?([eE][+|-]?{int}+)?
%%

{ws}		   { ECHO; }
{comment}	{ ECHO; nextLine();}
{line}		{ ECHO; nextLine();}
"<"		   { ECHO; yylval.oper = LESS; return(RELOP); }
">"		   { ECHO; yylval.oper = GREAT; return(RELOP); }
"="		   { ECHO; yylval.oper = EQUAL; return(RELOP); }
"<="		   { ECHO; yylval.oper = LESSOREQUAL; return(RELOP); }
">="		   { ECHO; yylval.oper = GREATOREQUAL; return(RELOP); }
"/="		   { ECHO; yylval.oper = NOTEQUAL; return(RELOP); }
"+"		   { ECHO; yylval.oper = ADD; return(ADDOP); }
"-"		   { ECHO; yylval.oper = SUBTRACT; return(ADDOP); }
"*"		   { ECHO; yylval.oper = MULTIPLY; return(MULOP); }
"/"		   { ECHO; yylval.oper = DIVIDE; return(MULOP); }
"rem"		   { ECHO; yylval.oper = REMAINDER; return(MULOP); }
"**"		   { ECHO; yylval.oper = EXPONENT; return(EXPOP); }
begin	   	{ ECHO; return(BEGIN_); }
boolean		{ ECHO; return(BOOLEAN); }
end		   { ECHO; return(END); }
endreduce	{ ECHO; return(ENDREDUCE); }
function 	{ ECHO; return(FUNCTION); }
integer		{ ECHO; return(INTEGER); }
real		   { ECHO; return(REAL); }
true		   { ECHO; yylval.value = 1; return(BOOL_LITERAL); }
false		   { ECHO; yylval.value = 0; return(BOOL_LITERAL); }
is		      { ECHO; return(IS); }
reduce		{ ECHO; return(REDUCE); }
returns		{ ECHO; return(RETURNS); }
endif		   { ECHO; return(ENDIF); }
if			   { ECHO; return(IF); }
else		   { ECHO; return(ELSE); }
then		   { ECHO; return(THEN); }
and		   { ECHO; return(ANDOP); }
or			   { ECHO; return(OROP); }
not			{ ECHO; return(NOTOP); }
{id}		   { ECHO; yylval.iden = (CharPtr)malloc(yyleng + 1); 
			      strcpy(yylval.iden, yytext); return(IDENTIFIER);}
{int}		   { ECHO; yylval.value = atoi(yytext); return(INT_LITERAL); }
{real_lit}	{ ECHO; yylval.value = atof(yytext); return(REAL_LITERAL); }
{punc}		{ ECHO; return(yytext[0]); }
.		      { ECHO; appendError(LEXICAL, yytext); }

%%
