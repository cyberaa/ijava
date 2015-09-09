%x	MCOMMENT

%{
	#include <string.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include "structures.h"
	#include "y.tab.h"
	
	void col_counter(int n);
	int colNo = 1;
	int prevColNo = 1;
	int lineNo = 1;
	int prevLineNo = 1;
	int lineScom = 0, colScom = 0;
	

%}

RESERVED	"++"|"--"|abstract|continue|for|switch|assert|default|goto|package|synchronized|do|private|this|break|double|implements|protected|throw|byte|import|throws|case|enum|instanceof|transient|catch|extends|short|try|char|final|interface|finally|long|strictfp|volatile|const|float|native|super|null

ID			[a-zA-Z_$][a-zA-Z_$0-9]*
INTLIT		[0-9]+|0x[0-9a-fA-F]+



BOOLLIT		true|false
INT			int
BOOL		boolean
NEW			new
IF			if
ELSE		else
WHILE		while
PRINT		"System.out.println"
PARSEINT	"Integer.parseInt"
CLASS		class
PUBLIC		public
STATIC		static
VOID		void
STRING		String
DOTLENGTH	".length"
RETURN		return
OCURV		"("
CCURV		")"
OBRACE		"{"
CBRACE		"}"
OSQUARE		"["
CSQUARE		"]"
AND			"&&"
OR          "||"
EQUALITY	"=="|"!="
RELATIONAL	("<"|">"|"<="|">=")
ADITIVE		("+"|"-")
MULTIPLICATIVE			("*"|"/"|"%")
NOT			"!"
ASSIGN		"="
SEMIC		";"
COMMA		","

INITCOM		"/*"
FIMCOM		"*/"
COMMENT	"//".*

%%

{BOOLLIT}		{col_counter(yyleng); yylval.token = strdup(yytext); return BOOLLIT;}
{INT}			{col_counter(yyleng); return INT;}
{BOOL}			{col_counter(yyleng); return BOOL;}
{NEW}			{col_counter(yyleng); return NEW;}
{IF}			{col_counter(yyleng); return IF;}
{ELSE}			{col_counter(yyleng); return ELSE;}
{WHILE}			{col_counter(yyleng); return WHILE;}
{PRINT}			{col_counter(yyleng); return PRINT;}
{PARSEINT}		{col_counter(yyleng); return PARSEINT;}
{CLASS}			{col_counter(yyleng); return CLASS;}
{PUBLIC}		{col_counter(yyleng); return PUBLIC;}
{STATIC}		{col_counter(yyleng); return STATIC;}
{VOID}			{col_counter(yyleng); return VOID;}
{STRING}		{col_counter(yyleng); return STRING;}
{DOTLENGTH}		{col_counter(yyleng); return DOTLENGTH;}
{RETURN}		{col_counter(yyleng); return RETURN;}
{OCURV}			{col_counter(yyleng); return OCURV;}
{CCURV}			{col_counter(yyleng); return CCURV;}
{OBRACE}		{col_counter(yyleng); return OBRACE;}
{CBRACE}		{col_counter(yyleng); return CBRACE;}
{OSQUARE}		{col_counter(yyleng); return OSQUARE;}
{CSQUARE}		{col_counter(yyleng); return CSQUARE;}
{AND}			{col_counter(yyleng); yylval.token = strdup(yytext); return AND;}
{OR}			{col_counter(yyleng); yylval.token = strdup(yytext); return OR;}
{EQUALITY}			{col_counter(yyleng); yylval.token = strdup(yytext); return EQUALITY;}
{RELATIONAL}			{col_counter(yyleng); yylval.token = strdup(yytext); return RELATIONAL;}
{ADITIVE}			{col_counter(yyleng); yylval.token = strdup(yytext); return ADITIVE;}
{MULTIPLICATIVE}			{col_counter(yyleng); yylval.token = strdup(yytext); return MULTIPLICATIVE;}
{NOT}			{col_counter(yyleng); yylval.token = strdup(yytext); return NOT;}
{ASSIGN}		{col_counter(yyleng); return ASSIGN;}
{SEMIC}			{col_counter(yyleng); return SEMIC;}
{COMMA}			{col_counter(yyleng); return COMMA;}
                                   
{RESERVED}		{yylval.token = strdup(yytext); col_counter(yyleng); return RESERVED;}

{ID}			{col_counter(yyleng); yylval.token = strdup(yytext); return ID;}
{INTLIT}		{col_counter(yyleng); yylval.token = strdup(yytext); return INTLIT;}

{COMMENT}		{prevColNo = colNo; colNo = 1;}

{INITCOM}					{BEGIN MCOMMENT; lineScom = lineNo; colScom = colNo; col_counter(yyleng);}
<MCOMMENT>.				{col_counter(yyleng);}
<MCOMMENT>"\n"			{prevLineNo = lineNo++; prevColNo = colNo; colNo = 1;}
<MCOMMENT><<EOF>>		{col_counter(0); printf("Line %d, col %d: unterminated comment\n",lineScom, colScom); return 0;}
<MCOMMENT>{FIMCOM}		{col_counter(yyleng); BEGIN 0;  }

\n							{prevLineNo = lineNo++; prevColNo = colNo; colNo = 1;}
[ \t\f\r]					{col_counter(yyleng);}
<<EOF>> 					{col_counter(0); return yytext[0];}


.			{printf("Line %d, col %d: illegal character ('%s')\n", lineNo, colNo, yytext); colNo++;}
%%

void col_counter(int n){
	prevLineNo = lineNo;
	prevColNo = colNo;
	colNo += n;
}

int yywrap()
{
	return 1;
}
