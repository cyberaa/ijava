%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"
#include "display.h"


#define DEBUG 0



/*errors*/
int yydebug=0;
int erros = 0;

void yyerror(char *var);

/*Get lexer vars*/
extern int colNo; /* variavel lex responsavel pela coluna */
extern int yylineno; /*numero da linha*/
extern int yyleng; /* tamanho da character com erro*/
extern char* yytext; /* character com error*/


/*AST Struct*/
AST_TREE* program = NULL;
char Error;
/*SYM Struct*/
Sym_Table* symbols = NULL;

%}

/* Definicao dos tipos das gramaticas */
%union{
    char* token; 
    int type; /* Type do tipo inteiro*/
    struct _node* node; /* No da Arvore Sintaxe Abstracta */
    struct _id_List* listId; /* Tipo de Method Type Decl */
    
}


%token <token> INTLIT BOOLLIT INT BOOL NEW IF ELSE WHILE PRINT PARSEINT CLASS PUBLIC STATIC VOID STRING DOTLENGTH RETURN OCURV CCURV OBRACE CBRACE OSQUARE CSQUARE OP1 OP1OR OP2 OP2EQS OP3 OP4 NOT ASSIGN SEMIC COMMA RESERVED ID



%type<node> Grammar  /* */
%type<node> FieldDecl
%type<node> MethodDecl
%type<node> VarDecl
%type<node> FormalParams
%type<node> multiple_FormalParams 
%type<node> Field_or_Method_Decl
%type<node> Statement_decl_Recursive
%type<node> Statement
%type<node> multiple_statement
%type<node> array_index
%type<node> return_Expr
%type<node> Index_Expr
%type<node> Expr
%type<node> Args_Index
%type<node> Args
%type<node> comma_expr
%type<node> VarDecl_Recursive
%type<listId> nested_var_decl
%type<type> method_type_decl
%type<type> Type


/* Regras de Precedencia */

%nonassoc IFX
%nonassoc ELSE

%left OP1OR
%left OP1
%left OP2EQS
%left OP2
%left OP3
%left OP4
%right NOT
%left OSQUARE DOTLENGTH


%start Grammar

%% 

Grammar :
                CLASS ID OBRACE Field_or_Method_Decl CBRACE          {if(DEBUG)printf("New class\n");$$ = add_Class_to_List($2,$4);program = $$;}
        ;

Field_or_Method_Decl :
                FieldDecl Field_or_Method_Decl               {if(DEBUG)printf("New variable\n");$$ = set_next_Node($1,$2);}
        | 	MethodDecl Field_or_Method_Decl              {if(DEBUG)printf("New Method\n"); $$ = set_next_Node($1,$2);}
        |                                                           {if(DEBUG)printf("NULL\n");$$ = NULL;};

FieldDecl :
                STATIC VarDecl VarDecl_Recursive    {if(DEBUG)printf("Static Variable\n"); $$ = setStatic($2);$$ = set_next_Node($2,$3);};

MethodDecl :
                PUBLIC STATIC method_type_decl ID OCURV FormalParams CCURV OBRACE VarDecl_Recursive Statement_decl_Recursive CBRACE        {if(DEBUG)printf("Create method\n"); $$ = setStatic(add_Method($3,$4,$6,$9,$10));}
        ;

method_type_decl:
                Type            {$$ = $1;}
        |	VOID            {$$ = TYPE_VOID;};

FormalParams : 
                Type ID multiple_FormalParams         {if(DEBUG)printf("Formal Params Other\n");$$ = add_ParamDecl($1,$2,NULL,$3);}
        |	    STRING OSQUARE CSQUARE ID           {if(DEBUG)printf("Formal Params String\n");$$ = add_ParamDecl(TYPE_STRING_ARRAY,$4,NULL,NULL);}
        |                                           {if(DEBUG)printf("No Formal Params\n");$$ = NULL;};

multiple_FormalParams  : 
                COMMA Type ID multiple_FormalParams       {if(DEBUG)printf("Multiple Formal Params\n");$$ = add_ParamDecl($2,$3,NULL,$4);}
        |                                               {if(DEBUG)printf("No more formal params\n");$$ = NULL;};

VarDecl_Recursive:
                VarDecl VarDecl_Recursive      {$$ = set_next_Node($1,$2);}
         |                                      {$$ = NULL;};

VarDecl :
                Type ID nested_var_decl SEMIC      {if(DEBUG)printf("new Var\n");$$ = add_VarDecl($1,$2,$3,NULL);}
        ;

nested_var_decl:
                COMMA ID nested_var_decl       {if(DEBUG)printf("Multiple Vars in same Decl ID(%s)\n",$2);$$ = add_VarID_to_ID_LIST($2,$3);}
        |                                                                   {$$ = NULL;};

Type :
                INT OSQUARE CSQUARE        {$$ = TYPE_INT_ARRAY;}
       |        BOOL OSQUARE CSQUARE       {$$ = TYPE_BOOL_ARRAY;}
       |        INT                        {$$ = TYPE_INT;}
       |        BOOL                       {$$ = TYPE_BOOL;}
       ;
	

Statement_decl_Recursive:
                Statement Statement_decl_Recursive          {$$ = set_next_Node($1,$2);}
        |                                                           {$$ = NULL;}
        ;

Statement : 
                OBRACE multiple_statement CBRACE                     {$$ = add_Compound_Stmnt($2);}
        |	IF OCURV Expr CCURV Statement %prec IFX             {$$ = add_IF($3,$5,NULL);}
        |	IF OCURV Expr CCURV Statement ELSE Statement        {$$ = add_IF($3, $5, $7);}
        |	WHILE OCURV Expr CCURV Statement                    {$$ = add_While($3,$5);}
        |	PRINT OCURV Expr CCURV SEMIC                        {$$ = add_Print($3);}
        |	ID array_index ASSIGN Expr SEMIC            {$$ = add_Store($1,$2,$4);}
        |	RETURN return_Expr SEMIC                      {$$ = add_Return($2);}
        ;

multiple_statement:
                Statement multiple_statement     {$$ = set_next_Node($1,$2);}
        |                                       {$$ = NULL;}
        ;

array_index:
                OSQUARE Expr CSQUARE        {$$ = $2;}
        |                                   {$$ = NULL;}
        ;

return_Expr : 
                Expr    {$$ = $1;}
        |               {$$ = NULL;};

Index_Expr: 
                ID                                                  {$$ = add_Terminal_Node(NO_ID,$1);}
        |	INTLIT                                              {$$ = add_Terminal_Node(NO_INTLIT,$1);}
        |	BOOLLIT                                             {$$ = add_Terminal_Node(NO_BOOLLIT,$1);}
        |	ID OCURV Args_Index CCURV                        {$$ = add_Call($1,$3);}
        |	OCURV Expr CCURV                                    {$$ = $2;}
        |	Expr DOTLENGTH                                      {$$ = add_DotLength($1);}
        |	Index_Expr OSQUARE Expr CSQUARE                  {$$ = add_LoadArray($1,$3);}
        |	PARSEINT OCURV ID OSQUARE Expr CSQUARE CCURV        {$$ = add_ParseInt($3,$5);};

Expr : 
                Expr OP1 Expr %prec OP1                 {$$ = add_two_Expr($1,$2,$3);}
        |       Expr OP1OR Expr %prec OP1OR             {$$ = add_two_Expr($1,$2,$3);}
        |       Expr OP4 Expr %prec OP4                 {$$ = add_two_Expr($1,$2,$3);}
        |       Expr OP3 Expr %prec OP3                 {$$ = add_two_Expr($1,$2,$3);}
        |       Expr OP2 Expr %prec OP2                 {$$ = add_two_Expr($1,$2,$3);}
        |       Expr OP2EQS Expr %prec OP2EQS           {$$ = add_two_Expr($1,$2,$3);}
        |	    OP3 Expr %prec NOT                      {$$ = add_Expr($1,$2);}
        |	    NOT Expr %prec NOT                      {$$ = add_Expr($1,$2);}
        |	    NEW INT OSQUARE Expr CSQUARE            {$$ = add_NewArray(NO_NEWINT,$4);}
        |	    NEW BOOL OSQUARE Expr CSQUARE           {$$ = add_NewArray(NO_NEWBOOL,$4);}
        |	    Index_Expr                           {$$ = $1;};

Args_Index:
                Args    {$$ = $1;}
        |               {$$ = NULL;};

Args:
                Expr comma_expr     {$$ = set_next_Node($1,$2);};

comma_expr: 
                COMMA Expr comma_expr       {$$ = set_next_Node($2,$3);}
        |                                   {$$ = NULL;};

%%

int main(int argc, char *argv[]){
    int i, print_AST, printSYMvar;
    Error = 0;
    yyparse();	/*Funcao Responsavel pelos erros gramaticais */
    print_AST = printSYMvar = 0;


	for(i=0; i < argc; i++)
	{
		if(strcmp(argv[i], "-s") == 0)
		{
            printSYMvar = 1;
		}
		else if(strcmp(argv[i], "-t") == 0)
		{
			print_AST = 1;
		}
	}
        if(Error)
            return 0;
        if(print_AST)
            print_TREE(program);

        symbols = create_SymTable(program);

        if(program!=NULL){
            setTable(symbols);
            check_Semantic_Errors(program,symbols,symbols);

        }
        if(printSYMvar){
                printSymbolTables(symbols);
        }
        genCode(program);
		
    return 0;
}

void yyerror (char *var) {
        printf ("Line %d, col %d: %s: %s\n",yylineno, (int)(colNo-strlen(yytext)), var, yytext);
        Error = 1;
}
