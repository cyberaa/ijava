#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

Class* create_rootClass(char *id, Decl_List *declara){
	Class *class_node = (Class*) malloc(sizeof(Class));
	class_node->id = id;
	class_node->declaracoes = declara;
	return class_node;
}


Param_List* add_FormalParam(Type tipo, char *id, Param_List *lista, int isHead){
	Param_List *newn = (Param_List*) malloc(sizeof(Param_List));
	newn->tipo = tipo;
	newn->id = id;
	newn->next = NULL;
	if(isHead || !lista){
        newn->next = lista;
        return newn;
    }
	Param_List* aux = lista;
	for(; aux->next != NULL; aux = aux->next);
	aux->next = newn;
	return lista;
}


ID_List* add_ID_List(char *id, ID_List *listaIDs){
	ID_List* newId = (ID_List*) malloc(sizeof(ID_List));
    newId->id = id;
    newId->next = NULL;
	if(listaIDs == NULL)
		return newId;
	ID_List* aux = listaIDs;
	for(; aux->next != NULL; aux = aux->next);
	aux->next = newId;
	return listaIDs;
}
Decl_List* add_Decl(DeclType type, void* decl, Decl_List* lista)
{
    Decl_List* newDecl = (Decl_List*) malloc(sizeof(Decl_List));
    newDecl->tipo = type;
    if(type == VARDECL)
        newDecl->varDecl = (VarDecl*) decl;
    else
        newDecl->methodDecl = (Method_Decl*) decl;
    newDecl->next = NULL;
    if(lista == NULL)
        return newDecl;
    Decl_List* aux = lista;
    for(; aux->next != NULL; aux = aux->next);
    aux->next = newDecl;
    return lista;
}
VarDecl* add_VarDecl(Type tipo, char *id, ID_List *listaIDs, int iStatic){
	VarDecl *newVar = (VarDecl*) malloc(sizeof(VarDecl));
	ID_List *n = (ID_List*) malloc(sizeof(ID_List));
	newVar->iStatic = iStatic;
	newVar->tipo = tipo;
	n->id = id;
	n->next = listaIDs;
	newVar->id_List = n;
	return newVar;

}


Stmt *add_Statement(StmtType tipo1, char* id, Stmt_List *stmts, Expr *expr, Expr *expr2, Stmt *stmt1, Stmt *stmt2){
    
	if(tipo1 == CSTAT)
		if(stmts == NULL)
			return NULL;
		else if(stmts->next == NULL)
			return stmts->stmt;	
	Stmt *novo = (Stmt*) malloc(sizeof(Stmt));
    novo->tipo = tipo1;
	novo->id = id;
    novo->stmts = stmts;
    novo->expr1 = expr;
    novo->expr2 = expr2;
    novo->stmt1 = stmt1;
    novo->stmt2 = stmt2;
    return novo;
}
VarDecl_List* add_VarDecl_List(VarDecl *vardecl, VarDecl_List *listaDecl){
	VarDecl_List *newList = (VarDecl_List*) malloc(sizeof(VarDecl_List));
	newList->declaracao = vardecl;
	newList->next = NULL;
	if(listaDecl == NULL)
		return newList;	
	VarDecl_List* aux = listaDecl;
	for(; aux->next != NULL; aux = aux->next);
	aux->next = newList;
	return listaDecl;
}


Method_Decl* add_MethodDecl(Type tipo1, char *id, Param_List *params, VarDecl_List *declara, Stmt_List *stmts){
	Method_Decl *newmeth = (Method_Decl*) malloc(sizeof(Method_Decl));
	newmeth->tipo = tipo1;
	newmeth->id = id;
	newmeth->parametros = params;
	newmeth->declaracoes = declara;
	newmeth->stmts = stmts;
	return newmeth;
}
Args_List* add_Args(Expr *expr, Args_List *list){
	Args_List *no = (Args_List*) malloc(sizeof(Args_List));
	no->expr = expr;
	no->next = list;
	return no;
}
Stmt_List *add_Statement_List(Stmt *stmt, Stmt_List *list){
    if(!stmt)
        return list;
    Stmt_List* newstmtlist = (Stmt_List*) malloc(sizeof(Stmt_List));
    newstmtlist->stmt = stmt;
    newstmtlist->next = NULL;
    if(list == NULL)
        return newstmtlist;
    Stmt_List* aux = list;
    for(; aux->next != NULL; aux = aux->next);
    aux->next = newstmtlist;
    return list;
}

Expr *add_Expression(ExprType type, char *idLit, char *op, Expr *expr1, Expr *expr2, Args_List *argsList){
    Expr *no = (Expr*) malloc(sizeof(Expr));
    no->type = type;
	no->idLit = idLit;
    no->op = (op != NULL) ? find_OP(op) : -1;
    no->expr1 =  expr1;
    no->expr2 = expr2;
    no->argsList = argsList;
    return no; 
}








/*AUX*/
OP find_OP(char *op){

    if(strcmp(op, "&&") == 0)
        return AND_T;
    else if(strcmp(op, "||") == 0)
        return OR_T;
    else if(strcmp(op, ">") == 0)
        return GREATER;
    else if(strcmp(op, "<") == 0)
        return LESSER;
    else if(strcmp(op, ">=") == 0)
        return GEQ;
    else if(strcmp(op, "<=") == 0)
        return LEQ;
    else if(strcmp(op, "!=") == 0)
        return DIF;
    else if(strcmp(op, "==") == 0)
        return EQ;
    else if(strcmp(op, "!") == 0)
        return NOT_;
    else if(strcmp(op, "+") == 0)
        return PLUS;
    else if(strcmp(op, "-") == 0)
        return MINUS;
    else if(strcmp(op, "*") == 0)
        return MUL;
    else if(strcmp(op, "/") == 0)
        return DIV;
    else if(strcmp(op, "%") == 0)
        return MOD;
    else if(strcmp(op, ".length") == 0)
        return DOTLENGTH_T;
    return -1;

}
VarDecl* change_to_static(void *vardecl, int d){
	VarDecl *vd = (VarDecl*) vardecl;
	vd = (VarDecl*) vardecl;
	vd->iStatic = d;
	return vd;

}
