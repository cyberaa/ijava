#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef enum {VOID_T, INT_T, BOOL_T, INTARRAY, BOOLARRAY, STRINGARRAY, METHOD} Type;

typedef enum {VARDECL, METHODDECL} DeclType;

typedef enum {BINOP, UNOP, ID_T, INTLIT_T, BOOLLIT_T, CALL, PARSEINT_T, INDEX, NEWINTARR, NEWBOOLARR} ExprType;

typedef enum {CSTAT, IFELSE, RETURN_T, WHILE_T, PRINT_T, STORE, STOREARRAY} StmtType;

typedef enum {PLUS, MINUS, MUL, DIV, MOD, LESSER, GREATER, LEQ, GEQ, DIF, EQ, DOTLENGTH_T, AND_T, OR_T, NOT_} OP;

typedef struct _args_List Args_List;

typedef struct _expr
{
	char *idLit;
    ExprType type;
    OP op;
    Args_List *argsList;
	struct _expr *expr1;
	struct _expr *expr2;
} Expr;

struct _args_List
{
	Expr *expr;
    struct _args_List *next;
};


typedef struct _stmt{
	Expr *expr1;
	Expr *expr2;
	StmtType tipo;
	struct _stmt_List *stmts;
	char *id;
	struct _stmt *stmt1;
	struct _stmt *stmt2;
	
} Stmt;

typedef struct _stmt_List {
	Stmt *stmt;
	struct _stmt_List *next;
} Stmt_List;

typedef struct _id_List{
	char *id;
	struct _id_List *next;
} ID_List;

typedef struct {
	Type tipo;
	ID_List *id_List;
	int iStatic;
} VarDecl;

typedef struct _varDecl_List {
	VarDecl *declaracao;
	struct _varDecl_List *next;
} VarDecl_List;


typedef struct _param_List {
	Type tipo;
	char *id;
	struct _param_List *next;
} Param_List;

typedef struct {
	Type tipo;
	char *id;
	Param_List *parametros;
	VarDecl_List *declaracoes;
	Stmt_List *stmts;
	
} Method_Decl;


typedef struct _decl_List {
	DeclType tipo;
	union{
		VarDecl *varDecl;
		Method_Decl *methodDecl;
	};
    struct _decl_List *next;
	
} Decl_List;

typedef struct _class {
	char *id;
	Decl_List *declaracoes;
} Class;

ID_List* add_ID_List(char *id, ID_List *listaIDs);
VarDecl* add_VarDecl(Type tipo, char *id, ID_List *listaIDs, int iStatic);
VarDecl* change_to_static(void *vardecl, int d);
VarDecl_List* add_VarDecl_List(VarDecl *vardecl, VarDecl_List *listaDecl);
Class* create_rootClass(char *id, Decl_List *declara);
Args_List* add_Args(Expr *expr, Args_List *list);
Stmt_List *add_Statement_List(Stmt *stmt,Stmt_List *list);
Stmt *add_Statement(StmtType tipo1, char* id, Stmt_List *stmts,Expr *expr,Expr *expr2,Stmt *stmt1,Stmt *stmt2);
Method_Decl* add_MethodDecl(Type tipo1, char *id, Param_List *params, VarDecl_List *declara, Stmt_List *stmts);
Decl_List* add_Decl(DeclType type, void* decl, Decl_List* lista);
Param_List* add_FormalParam(Type tipo, char *id, Param_List *lista, int isHead);
Expr *add_Expression(ExprType type, char *idLit, char *op, Expr *expr1, Expr *expr2, Args_List *argsList);
OP find_OP(char *op);
#endif
