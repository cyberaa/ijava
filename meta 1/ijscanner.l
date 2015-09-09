%{
#include <string.h>
#include <stdio.h>
#include <ctype.h>
int line = 1;
int col = 1;
int cline,ccol;	
%}


%X MCOMMENT COMMENT


/*regular definitions*/

reserved abstract|continue|for|switch|assert|default|goto|package|synchronized|do|private|this|break|double|implements|protected|throw|byte|import|throws|case|enum|instanceof|transient|catch|extends|short|try|char|final|interface|finally|long|strictfp|volatile|const|float|native|super|null
intlit ([0-9]+)|((0x)[0-9a-fA-F]+)
id ([a-zA-Z_$])([a-zA-Z_$0-9])*


%%

("true"|"false") 			{printf("BOOLLIT(%s)\n",yytext);col += yyleng;}
"class" 					{printf("CLASS\n");col += yyleng;} 
"if" 						{printf("IF\n");col += yyleng;}
"int" 						{printf("INT\n");col += yyleng;}
"boolean" 					{printf("BOOL\n");col += yyleng;}
"System.out.println"		{printf("PRINT\n");col += yyleng;}
"Integer.parseInt"			{printf("PARSEINT\n");col += yyleng;}
"new"						{printf("NEW\n");col += yyleng;}
"else" 						{printf("ELSE\n");col += yyleng;}
"while" 					{printf("WHILE\n");col += yyleng;}
"public"					{printf("PUBLIC\n");col += yyleng;}
"static"					{printf("STATIC\n");col += yyleng;}
"void"	 					{printf("VOID\n");col += yyleng;}
"String" 					{printf("STRING\n");col += yyleng;}
".length" 					{printf("DOTLENGTH\n");col += yyleng;}
"return" 					{printf("RETURN\n");col += yyleng;}
"("					    {printf("OCURV\n");col += yyleng;}
")"					    {printf("CCURV\n");col += yyleng;}
"{"						{printf("OBRACE\n");col += yyleng;}
"}"	 					{printf("CBRACE\n");col += yyleng;}
"[" 					{printf("OSQUARE\n");col += yyleng;}
"]"	 					{printf("CSQUARE\n");col += yyleng;}
("&&")|("||")				{ printf("OP1(%s)\n", yytext); col+=yyleng;}
("<")|(">")|("==")|("!=")|("<=")|(">=")	{printf("OP2(%s)\n", yytext); col+=yyleng;}
("+")|("-")								{printf("OP3(%s)\n", yytext); col+=yyleng;}
("*")|("/")|("%")						{printf("OP4(%s)\n", yytext); col+=yyleng;}
"!"										{printf("NOT\n");col += yyleng;}
"="							    {printf("ASSIGN\n");col += yyleng;}
";"								{printf("SEMIC\n");col += yyleng;}
","	 							{printf("COMMA\n");col += yyleng;}
{reserved} 					    {printf("RESERVED(%s)\n", yytext); col+=yyleng; }

{intlit} {printf("INTLIT(%s)\n",yytext);col += yyleng;}
{id} {printf("ID(%s)\n",yytext);col += yyleng;}

"//"	{BEGIN COMMENT; col+=yyleng;}
<COMMENT>. {col+=yyleng;}
<COMMENT>"\n" {line++;col=1; BEGIN 0;}
<COMMENT><<EOF>> {col+=yyleng;BEGIN 0;}

"/*"	{BEGIN MCOMMENT;cline=line; ccol=col; col+=yyleng;}
<MCOMMENT>.  {col+=yyleng;}
<MCOMMENT>"\n" {line+=1; col=1;}
<MCOMMENT>"*/"	{col+=yyleng;BEGIN 0;}
<MCOMMENT><<EOF>> { printf("Line %d, col %d: unterminated comment\n", cline, ccol); col+=yyleng; BEGIN 0; }

(" "|\t)+ 	{col+=yyleng;}
\n			{line++;col=1;}
. 			{printf("Line %d, col %d: illegal character ('%s')\n",line,col,yytext); col+=yyleng; }
<<EOF>> 	{ col+=yyleng; yyterminate(); } 




%%
int main()
{
	yylex();
	return 0;
}

int yywrap()
{
	return 1;
}
