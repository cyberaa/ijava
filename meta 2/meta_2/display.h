#ifndef SHOWS_H
#define SHOWS_H

#include "structures.h"
#include "symbol_table.h"


void print_TREE(Class* class);
void print_MethodDecl(VarDecl_List *decl,int level);
void print(char *s, int level, int linebreak);
char* print_ind_Int(int tipo, char *idLit);
void typeToString(Type type);
void Stmt_To_String(StmtType type);
void print_Args( Args_List *argsList,int level);
void print_indentation(int level);
void print_Stmnt(Stmt *stmt,int level);
void print_Expr(Expr *expr, int level);
void ExprToString(OP type, ExprType op);
void print_VarDecl(Type tipo, char *id, int iStatic, int level);
void print_Method_Params(Param_List *params, int level);
void print_Decl_List(Decl_List* list);
void print_Method_Decl(Method_Decl *method);
void print_Method_Body(Method_Decl *method);
void print_Method_Stmts(Stmt_List *stmts, int level);



/*Sym Table*/
void printSymbolTables(Sym_Table*);
void printMethodTable(SymTableNode* table);
void printSymbolTables(Sym_Table* table);
void Type_To_String_SYM(Type type, char* dest);


#endif
