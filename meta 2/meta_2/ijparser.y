%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"
#include "display.h"

/*Get lexer vars*/
extern int prevLineNo;
extern int prevColNo;
extern int yyleng;
extern char *yytext;


/*errors*/
int yydebug=0;
int erros = 0;

void yyerror(char *s);
int yylex(void);

/*AST Struct*/
Class *myprogram;
/*SYM Struct*/
Sym_Table* Tabela_sym = NULL;

%}

%union{
	char *token;
	Type type;
	ExprType exprtype;
	struct _class *class;
	Decl_List *decllist;
	VarDecl *vardecl;
	Method_Decl *methoddecl;
	Param_List *paramlist;
	VarDecl_List *vardecllist;
	ID_List *idlist;	
	Stmt_List *stmtlist;
	Stmt *stmt;	
	Expr *expr;
	Args_List *argslist;
}


%token <token> RESERVED COMMA BOOL INT ID INTLIT IF ELSE WHILE RETURN PRINT BOOLLIT NEW PARSEINT PUBLIC STATIC VOID CLASS OCURV CCURV OBRACE CBRACE OSQUARE CSQUARE AND OR EQUALITY RELATIONAL ADITIVE MULTIPLICATIVE NOT ASSIGN SEMIC STRING DOTLENGTH
%type <class>		programa
%type <decllist>	programa_decomp
%type <methoddecl>	methoddecl
%type <vardecl>		vardecl fielddecl
%type <paramlist>	formalparams comma_type_id_decomp
%type <vardecllist>	vardecl_decomp  
%type <stmt>		statement
%type <idlist>		comma_id_decomp
%type <stmtlist>	statement_decomp 
%type <expr>		expr exprlisted exprnotlisted
%type <argslist> 	args argslist
%type <type>		type_void type

%nonassoc EXPR1REDUCE
%nonassoc IF 
%nonassoc ELSE
%left OR
%left AND
%left EQUALITY
%left RELATIONAL
%left ADITIVE
%left MULTIPLICATIVE
%right ASSIGN
%left OBRACE
%right UNARY
%left OSQUARE DOTLENGTH

%start grammar

%% 

grammar
	:	programa
	;

programa
	:	CLASS ID OBRACE CBRACE						{$$ = create_rootClass($2, NULL); myprogram = $$;}
	|	CLASS ID OBRACE programa_decomp CBRACE		{$$ = create_rootClass($2, $4); myprogram = $$;}
	;

	
programa_decomp
	:	fielddecl									{$$=add_Decl(VARDECL, $1, NULL);}
	|	methoddecl									{$$=add_Decl(METHODDECL, $1, NULL);}
	|	programa_decomp fielddecl					{$$=add_Decl(VARDECL, $2, $1);}
	|	programa_decomp methoddecl					{$$=add_Decl(METHODDECL, $2, $1);}
	;

fielddecl
	:	STATIC vardecl								{$$ = change_to_static($2,1);}
	;
	
methoddecl
	:	PUBLIC STATIC type_void ID OCURV formalparams CCURV OBRACE vardecl_decomp statement_decomp CBRACE		{$$ = add_MethodDecl($3, $4, $6, $9, $10);}
	;
	
type_void
	:	type		{$$ = $1;}
	|	VOID		{$$ = VOID_T;}
	;

formalparams
	:	type ID comma_type_id_decomp				{$$ = add_FormalParam($1, $2, $3, 1);}
	|	STRING OSQUARE CSQUARE ID				{$$ = add_FormalParam(STRINGARRAY, $4, NULL, 1);}
	|											{$$ = NULL;}
	;
	
comma_type_id_decomp
	:	comma_type_id_decomp COMMA type ID		{$$ = add_FormalParam($3, $4, $1, 0);}
	|											{$$ = NULL;}
	;
	
type
	:	INT										{$$ = INT_T;}
	|	BOOL									{$$ = BOOL_T;}
	|	INT OSQUARE CSQUARE						{$$ = INTARRAY;}
	|	BOOL OSQUARE CSQUARE					{$$ = BOOLARRAY;}
	;
	
vardecl_decomp 
	:	vardecl_decomp vardecl					{$$ = add_VarDecl_List($2, $1);}
	|											{$$ = NULL;}
	;
	
vardecl
	:	type ID comma_id_decomp SEMIC		{$$ = add_VarDecl($1, $2, $3, 0);}
	;

comma_id_decomp
	:	comma_id_decomp COMMA ID				{$$ = add_ID_List($3, $1);}
	|										{$$ = NULL;}
	;
	
statement
    :   OBRACE statement_decomp CBRACE				    {$$=add_Statement(CSTAT,NULL,$2,NULL,NULL,NULL,NULL);}
	|   IF OCURV expr CCURV statement ELSE statement  %prec ELSE   {$$=add_Statement(IFELSE,NULL,NULL,$3,NULL,$5,$7);}    
	|   IF OCURV expr CCURV statement     	%prec IF	    	{$$=add_Statement(IFELSE,NULL,NULL,$3,NULL,$5,NULL);}
    |   WHILE OCURV expr CCURV statement                {$$=add_Statement(WHILE_T,NULL,NULL,$3,NULL,$5,NULL);}
    |   PRINT OCURV expr CCURV SEMIC                    {$$=add_Statement(PRINT_T,NULL,NULL,$3,NULL,NULL,NULL);}
    |   ID ASSIGN expr SEMIC                            {$$=add_Statement(STORE,$1,NULL,$3,NULL,NULL,NULL);}
    |   ID OSQUARE expr CSQUARE ASSIGN expr SEMIC       {$$=add_Statement(STOREARRAY,$1,NULL,$3,$6,NULL,NULL);}
    |   RETURN SEMIC                                    {$$=add_Statement(RETURN_T,NULL,NULL,NULL,NULL,NULL,NULL);}
    |   RETURN expr SEMIC                               {$$=add_Statement(RETURN_T,NULL,NULL,$2,NULL,NULL,NULL);}
    ;
    
statement_decomp      
    :   statement_decomp statement   {$$ = add_Statement_List($2,$1);}
    |                               {$$ = NULL;}  
    ;
	
expr
    :   exprnotlisted                                    {$$=$1;}
	|	exprlisted   %prec EXPR1REDUCE                   {$$=$1;}                                  
	;
    
    
exprlisted
	:   exprlisted OSQUARE expr CSQUARE                  {$$=add_Expression(INDEX,NULL, NULL,$1,$3,NULL);}   
    |   expr AND expr                                   {$$=add_Expression(BINOP, NULL,$2,$1,$3,NULL);}
    |   expr OR expr                                    {$$=add_Expression(BINOP, NULL,$2,$1,$3,NULL);}
    |   expr EQUALITY expr                              {$$=add_Expression(BINOP, NULL,$2,$1,$3,NULL);}
    |   expr RELATIONAL expr                            {$$=add_Expression(BINOP, NULL,$2,$1,$3,NULL);}
    |   expr ADITIVE expr                                   {$$=add_Expression(BINOP, NULL,$2,$1,$3,NULL);}
    |   expr MULTIPLICATIVE expr                                   {$$=add_Expression(BINOP, NULL,$2,$1,$3,NULL);}
	|   NOT expr          %prec UNARY                   {$$=add_Expression(UNOP, NULL,$1,$2,NULL,NULL);}
    |   ADITIVE expr          %prec UNARY                   {$$=add_Expression(UNOP, NULL,$1,$2,NULL,NULL);}
    |	ID												{$$=add_Expression(ID_T, $1, NULL,NULL,NULL,NULL);}
	|	INTLIT											{$$=add_Expression(INTLIT_T, $1, NULL,NULL,NULL,NULL);}
	|	BOOLLIT											{$$=add_Expression(BOOLLIT_T, $1, NULL,NULL,NULL,NULL);}
	|   ID OCURV args CCURV                             {$$=add_Expression(CALL, $1,NULL,NULL,NULL,$3);}
	|   ID OCURV CCURV                                  {$$=add_Expression(CALL, $1,NULL,NULL,NULL,NULL);}
	|   OCURV expr CCURV                                {$$=$2;}
    |   expr DOTLENGTH                                  {$$=add_Expression(UNOP, NULL,".length",$1,NULL,NULL);}
    |   PARSEINT OCURV ID OSQUARE expr CSQUARE CCURV    {$$=add_Expression(PARSEINT_T, $3,NULL,$5,NULL,NULL);}

    ;

exprnotlisted
    :   NEW INT OSQUARE expr CSQUARE                    {$$=add_Expression(NEWINTARR,NULL,NULL,$4,NULL,NULL);}
    |   NEW BOOL OSQUARE expr CSQUARE                   {$$=add_Expression(NEWBOOLARR,NULL,NULL,$4,NULL,NULL);}
    ;

args
	:	expr                         {$$=add_Args($1, NULL);}
	|	expr argslist                {$$=add_Args($1, $2);}
  
	;
 
argslist
	:	COMMA args                 {$$=$2;}
	;

	
%%

int main(int argc, char *argv[])
{
	yyparse();
	int i;
	int print_AST;
	int printSymbols;
	print_AST = printSymbols = 0;
	for(i=0; i < argc; i++)
	{
		if(strcmp(argv[i], "-s") == 0){
			printSymbols = 1;
			break;
		}
		else if(strcmp(argv[i], "-t") == 0){
			print_AST = 1;
			break;
		}
	}
	Tabela_sym = buildSymbolsTables(myprogram);
	if(print_AST && erros == 0)
		print_TREE(myprogram);	
	else if(printSymbols && erros == 0)
		printSymbolTables(Tabela_sym);
    return 0;
}

void yyerror(char *s) {
	printf("Line %d, col %d: %s: %s\n", prevLineNo, prevColNo, s, yytext);
	erros++;
}
