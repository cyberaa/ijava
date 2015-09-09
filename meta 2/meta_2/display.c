#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "symbol_table.h"

#define LINE_INDENT 2

char aux[40];

void print_Method_Decl(Method_Decl *method){
	print_indentation(1);
	printf("MethodDecl\n");
	print_indentation(2);
	typeToString(method->tipo);
	print_indentation(2);
	printf("Id(%s)\n", method->id);
	print_Method_Params(method->parametros, 2);
	print_Method_Body(method);	
}

void print_Method_Body(Method_Decl *method){
	print_indentation(2);
	printf("MethodBody\n");
	if(method->declaracoes != NULL)
		print_MethodDecl(method->declaracoes, 3);	
	if(method->stmts != NULL)
		print_Method_Stmts(method->stmts, 3);
}

void print_Method_Stmts(Stmt_List *stmts, int level){
	Stmt_List* aux = stmts;
    for(; aux != NULL; aux = aux->next){
		print_Stmnt(aux->stmt,level);
	}
}

void print_MethodDecl(VarDecl_List *decl,int level){
    VarDecl_List* aux = decl;
    for(; aux != NULL; aux = aux->next){
        ID_List* auxID = aux->declaracao->id_List ;
		print_VarDecl(aux->declaracao->tipo, auxID->id, 0, level);
        for(auxID = auxID->next; auxID != NULL; auxID = auxID->next){
			print_indentation(level + 1);
			printf("Id(%s)\n", auxID->id);
        }
    }
}
void print_Method_Params(Param_List *params, int level){
	print_indentation(level);
	printf("MethodParams\n");
	Param_List* aux = params;
    for(; aux != NULL; aux = aux->next){
		print_indentation(level + 1);
		printf("ParamDeclaration\n");
		
		print_indentation(level + 2);
		typeToString(aux->tipo);
		
		print_indentation(level + 2);
		printf("Id(%s)\n", aux->id);

	}
}

void print_Stmnt(Stmt *stmt,int level){
	print_indentation(level);
	if(stmt == NULL){
		printf("Null\n");
		return;
	}
    Stmt_To_String(stmt->tipo);
    if(stmt->tipo==IFELSE){
        print_Expr(stmt->expr1,level);
        print_Stmnt(stmt->stmt1,level + 1);
        print_Stmnt(stmt->stmt2,level + 1);
    }
    else if(stmt->tipo==CSTAT){
        print_Method_Stmts(stmt->stmts,level + 1);
    }
    else if(stmt->tipo==RETURN_T){
        if(stmt->expr1 != NULL)
            print_Expr(stmt->expr1,level);
    }
    else if(stmt->tipo==WHILE_T){
        print_Expr(stmt->expr1,level);
		print_Stmnt(stmt->stmt1,level + 1);
    }
    else if(stmt->tipo==PRINT_T){
        print_Expr(stmt->expr1,level);
        
    }
    else if(stmt->tipo==STORE){
		print_indentation(level + 1);
		printf("Id(%s)\n", stmt->id);

        print_Expr(stmt->expr1, level);

    }
    else if(stmt->tipo==STOREARRAY){
		print_indentation(level + 1);
		printf("Id(%s)\n", stmt->id);
        print_Expr(stmt->expr1, level);
        print_Expr(stmt->expr2, level);
    }
    
}
void print_TREE(Class* class){
    printf("Program\n");
    printf("  Id(%s)\n", class->id);
    if(class->declaracoes != NULL)
        print_Decl_List(class->declaracoes);

}

void print_Decl_List(Decl_List* list)
{
    Decl_List* aux = list;
    for(; aux != NULL; aux = aux->next){
        if(aux->tipo == VARDECL){

			ID_List* auxID = aux->varDecl->id_List ;
			print_VarDecl(aux->varDecl->tipo, auxID->id, 0, 1);
			
			for(auxID = auxID->next; auxID != NULL; auxID = auxID->next){
				print_indentation(2);
				printf("Id(%s)\n", auxID->id);
			}
		}
        else if(aux->tipo == METHODDECL)
            print_Method_Decl(aux->methodDecl);
    }
}
void print_Expr(Expr *expr, int level){
	print_indentation(level + 1);
    if(expr->type == BINOP){
		ExprToString(expr->op, BINOP);
		print_Expr(expr->expr1,level + 1);
        print_Expr(expr->expr2,level + 1);
		

    }
    else if(expr->type == UNOP){
		ExprToString(expr->op, UNOP);
		print_Expr(expr->expr1, level + 1);
	}

    else if(expr->type == ID_T){
		printf("Id(%s)\n", expr->idLit);
	}

    else if(expr->type == INTLIT_T){
		printf("IntLit(%s)\n", expr->idLit);
	}
    
    else if(expr->type == BOOLLIT_T){
		printf("BoolLit(%s)\n", expr->idLit);
	}
    
    else if(expr->type == CALL){	
		printf("Call\n");
		print_indentation(level + 2); printf("Id(%s)\n", expr->idLit);
		print_Args(expr->argsList,level);
    }
    else if(expr->type == PARSEINT_T){
		printf("ParseArgs\n");
        print_indentation(level + 2);
		printf("Id(%s)\n", expr->idLit);
        print_Expr(expr->expr1,level+1);
    }
    else if(expr->type == INDEX){
		printf("LoadArray\n");
        print_Expr(expr->expr1,level+1);
        print_Expr(expr->expr2,level+1);
    }
    else if(expr->type == NEWINTARR){
		printf("NewInt\n");
        print_Expr(expr->expr1,level+1);
    }
    else if(expr->type == NEWBOOLARR){
		printf("NewBool\n");
        print_Expr(expr->expr1,level+1);
    }
}
void print_VarDecl(Type tipo, char *id, int iStatic, int level){
	print_indentation(level);
    printf("VarDecl\n");
	print_indentation(level + 1);
	typeToString(tipo);
	print_indentation(level + 1);
	printf("Id(%s)\n", id);

}
void print_Args( Args_List *argsList,int level){
    Args_List* aux = argsList;
    for(; aux != NULL; aux = aux->next)
        print_Expr(aux->expr,level+1);

}



char* print_ind_Int(int tipo, char *idLit){
	char *aux = (char*) malloc(sizeof(char) * 25);
	char t[8];
	if(tipo == 0)
		sprintf(t, "Id");
	else if(tipo == 1)
		sprintf(t, "IntLit");
	else
		sprintf(t, "BoolLit");
		
	
	sprintf(aux, "%s(%s)", t, idLit);
	return aux;
}


/*AUX*/
void print_indentation(int level){
	char spaces[16];
	int i;
	for(i = 0; i < LINE_INDENT * level; i++){
		printf(" ", spaces);
	}

}

void typeToString(Type type)
{
    if(type == INT_T)
		printf("Int\n");
    else if(type == BOOL_T)
		printf("Bool\n");
    else if(type == INTARRAY)
		printf("IntArray\n");
    else if(type == BOOLARRAY)
		printf("BoolArray\n");
    else if(type == VOID_T)
		printf("Void\n");
    else if(type == STRINGARRAY)
		printf("StringArray\n");

}

void Stmt_To_String(StmtType type)
{
    if(type == CSTAT)
		printf("CompoundStat\n");
    else if(type == IFELSE)
		printf("IfElse\n");
    else if(type == RETURN_T)
		printf("Return\n");
    else if(type == WHILE_T)
		printf("While\n");
    else if(type == PRINT_T)
		printf("Print\n");
    else if(type == STORE)
		printf("Store\n");
	else if(type == STOREARRAY)
		printf("StoreArray\n");

}
void print(char *s, int level, int linebreak){
	char spaces[16];
	char lb = (linebreak == 1) ? '\n' : '\0';
	int i;
	
	for(i = 0; i < LINE_INDENT * level; i++){
		spaces[i] = ' ';
		if(i == LINE_INDENT * level - 1)
            spaces[i + 1] = '\0';
	}
		
	printf("%s%s\n", spaces, s);
	
}


void ExprToString(OP type, ExprType op){

    if(type == PLUS){
		if(op == BINOP)
			printf("Add\n");
		else
			printf("Plus\n");
			
    }
	else if(type == MINUS){
        if(op == BINOP)
			printf("Sub\n");
		else
			printf("Minus\n");
			
    }else if(type == MUL)
		printf("Mul\n");
		
    else if(type == DIV)
		printf("Div\n");
		
    else if(type == MOD)
		printf("Mod\n");
		
    else if(type == LESSER)
		printf("Lt\n");

    else if(type == GREATER)
		printf("Gt\n");

	else if(type == EQ)
		printf("Eq\n");

    else if(type == LEQ)
		printf("Leq\n");

    else if(type == GEQ)
		printf("Geq\n");

    else if(type == DOTLENGTH_T)
		printf("Length\n");

    else if(type == AND_T)
		printf("And\n");

    else if(type == OR_T)
		printf("Or\n");

    else if(type == NOT_)
		printf("Not\n");

	else if(type == DIF)
		printf("Neq\n");

 }

 /*Sym Table*/
void Type_To_String_SYM(Type type, char* dest)
{
    if(type == INT_T)
        sprintf(dest, "%s", "int");
    else if(type == BOOL_T)
        sprintf(dest, "%s", "boolean");
    else if(type == INTARRAY)
        sprintf(dest, "%s", "int[]");
    else if(type == BOOLARRAY)
        sprintf(dest, "%s", "boolean[]");
    else if(type == VOID_T)
        sprintf(dest, "%s", "void");
    else if(type == STRINGARRAY)
        sprintf(dest, "%s", "String[]");
}
 void printSymbolTables(Sym_Table* table)
{
    printf("===== Class %s Symbol Table =====\n", table->id);

    char type[40];
    SymTableNode* aux = table->entries;
    for(; aux != NULL; aux = aux->next)
    {
        if(aux->methodTable == NULL) 
        {
            Type_To_String_SYM(aux->type, type);
            printf("%s\t%s\n", aux->id, type);
        }
        else 
            printf("%s\tmethod\n", aux->id);
    }

    aux = table->entries;
    for(; aux != NULL; aux = aux->next)
    {
        if(aux->methodTable != NULL) 
            printMethodTable(aux);
    }
}

void printMethodTable(SymTableNode* table)
{
    char type[40];
    Type_To_String_SYM(table->type, type);
    printf("\n===== Method %s Symbol Table =====\n", table->id);
    printf("return\t%s\n", type);
    MethodTableNode* aux = table->methodTable->entries;
    for(; aux != NULL; aux = aux->next)
    {
        Type_To_String_SYM(aux->type, type);
        printf("%s\t%s", aux->id, type);
        if(aux->isParam)
            printf("\tparam");
        printf("\n");
    }
}

