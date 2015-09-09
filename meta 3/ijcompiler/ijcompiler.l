%{
	#include <string.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "structures.h"


	#define DEBUG 0

	extern int yyval;

	int lineScom=0,colScom=0;
	int colNo=1;


%}

%option yylineno

RESERVED "++"|"--"|abstract|continue|for|switch|assert|default|goto|package|synchronized|do|private|this|break|double|implements|protected|throw|byte|import|throws|case|enum|instanceof|transient|catch|extends|short|try|char|final|interface|finally|long|strictfp|volatile|const|float|native|super|null

ID			[a-zA-Z_$]([a-zA-Z_$0-9])* 
INTLIT		(([0-9])+|("0x"[0-9a-fA-F]+)) 


%X COMMENT

%%


{INTLIT}          {if(DEBUG)if(DEBUG)printf("INTLIT(%s)\n",yytext);   colNo += yyleng;yylval.token = strdup(yytext);return INTLIT;}
"true"|"false"                          {if(DEBUG)if(DEBUG)printf("BOOLLIT(%s)\n",yytext);  colNo += yyleng;yylval.token = strdup(yytext);return BOOLLIT;}
"int" 					{if(DEBUG)printf("INT\n");                          colNo += yyleng;return INT;}
"boolean" 				{if(DEBUG)printf("BOOL\n");                         colNo += yyleng;return BOOL;}
"new" 					{if(DEBUG)printf("NEW\n");                          colNo += yyleng;return NEW;}
"if"					{if(DEBUG)printf("IF\n");                           colNo += yyleng;return IF;}
"else"					{if(DEBUG)printf("ELSE\n");                         colNo += yyleng;return ELSE;}
"while"					{if(DEBUG)printf("WHILE\n");                        colNo += yyleng;return WHILE;}
"System.out.println"                    {if(DEBUG)printf("PRINT\n");                        colNo += yyleng;return PRINT;}
"Integer.parseInt"                      {if(DEBUG)printf("PARSEINT\n");                     colNo += yyleng;return PARSEINT;}
"class"                                 {if(DEBUG)printf("CLASS\n");                        colNo += yyleng;return CLASS;}
"public"                                {if(DEBUG)printf("PUBLIC\n");                       colNo += yyleng;return PUBLIC;}
"static"                                {if(DEBUG)printf("STATIC\n");                       colNo += yyleng;return STATIC;}
"void"                                  {if(DEBUG)printf("VOID\n");                         colNo += yyleng;return VOID;}
"String"                                {if(DEBUG)printf("STRING\n");                       colNo += yyleng;return STRING;}
".length"                               {if(DEBUG)printf("DOTLENGTH\n");                    colNo += yyleng;return DOTLENGTH;}
"return"                                {if(DEBUG)printf("RETURN\n");                       colNo += yyleng;return RETURN;}
"("             			{if(DEBUG)printf("OCURV\n");                        colNo += yyleng;return OCURV;}
")"         				{if(DEBUG)printf("CCURV\n");                        colNo += yyleng;return CCURV;}
"{"         				{if(DEBUG)printf("OBRACE\n");                       colNo += yyleng;return OBRACE;}
"}"         				{if(DEBUG)printf("CBRACE\n");                       colNo += yyleng;return CBRACE;}
"["         				{if(DEBUG)printf("OSQUARE\n");                      colNo += yyleng;return OSQUARE;}
"]"         				{if(DEBUG)printf("CSQUARE\n");                      colNo += yyleng;return CSQUARE;}
"&&"                                    {if(DEBUG)printf("OP1&&(%s)\n",yytext);             colNo += yyleng;yylval.token = strdup(yytext);return OP1;}
"||"                                    {if(DEBUG)printf("OP1||(%s)\n",yytext);             colNo += yyleng;yylval.token = strdup(yytext);return OP1OR;}
("<"|">"|"<="|">=")                     {if(DEBUG)printf("OP2(%s)\n",yytext);               colNo += yyleng;yylval.token = strdup(yytext);return OP2;}
("=="|"!=")                             {if(DEBUG)printf("OP2(%s)\n",yytext);               colNo += yyleng;yylval.token = strdup(yytext);return OP2EQS;}
("+"|"-")                               {if(DEBUG)printf("OP3(%s)\n",yytext);               colNo += yyleng;yylval.token = strdup(yytext);return OP3;}
("*"|"/"|"%")                           {if(DEBUG)printf("OP4(%s)\n",yytext);               colNo += yyleng;yylval.token = strdup(yytext);return OP4;}
"!"                                     {if(DEBUG)printf("NOT\n");                          colNo += yyleng;yylval.token = strdup(yytext);return NOT;}
"="                                     {if(DEBUG)printf("ASSIGN\n");                       colNo += yyleng;yylval.token = strdup(yytext);return ASSIGN;}
";"                                     {if(DEBUG)printf("SEMIC\n");                        colNo += yyleng;return SEMIC;}
","                                     {if(DEBUG)printf("COMMA\n");                        colNo += yyleng;return COMMA;}


{RESERVED}                              {if(DEBUG)printf("RESERVED(%s)\n",yytext);          colNo += yyleng;return RESERVED;}
{ID}            						 {if(DEBUG)printf("ID(%s)\n",yytext);                colNo += yyleng; yylval.token = strdup(yytext); return ID;}


<COMMENT><<EOF>> {BEGIN 0;printf("Line %d, col %d: unterminated comment\n",lineScom,colScom);}
<COMMENT>"*/" {BEGIN 0;colNo += yyleng;}
<COMMENT>"\n" {colNo = 1;}
<COMMENT>. {colNo += yyleng;}
"/*"	{BEGIN COMMENT;colScom=colNo;colNo += yyleng;lineScom = yylineno;}
"//".* {colNo=1;}

" "|"\t" 				{colNo  +=  yyleng;}
"\n" 					{colNo  =   1;}


.     {printf("Line %d, col %d: illegal character ('%s')\n",yylineno,colNo,yytext);        colNo += yyleng;}
%%

int yywrap()
{
return 1;
}
