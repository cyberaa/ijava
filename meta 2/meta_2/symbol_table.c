#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"

//Sym table
extern Sym_Table* Tabela_sym;
MethodTable* currentLocalTable;



// Create Table Functions
SymTableNode* add_VarNode(VarDecl*, SymTableNode*);
void add_MethodNode(Method_Decl*, SymTableNode*, Sym_Table*);
void create_MethodTable(MethodTable*, Param_List*, VarDecl_List*);


//Get syms fuctions
Type get_sym(char*, int);
Type get_sym_local(char*);
Type get_sym_local_or_global(char*);
Type get_sym_global(char*);
MethodTable* get_local_table(char*);

// Find Semantic errors
void sym_duplicate(char*);


Sym_Table* buildSymbolsTables(Class* myprogram)
{
    Sym_Table* tabela = (Sym_Table*) malloc(sizeof(Sym_Table));
    tabela->id = myprogram->id;
    tabela->entries = NULL;
    Tabela_sym = tabela;
    Decl_List* aux = myprogram->declaracoes;
    SymTableNode* last = NULL, *end = NULL;
    
    for(; aux != NULL; aux = aux->next)
    {
        SymTableNode* new_node = (SymTableNode*) malloc(sizeof(SymTableNode));
        new_node->methodTable = NULL;
        new_node->next = NULL;
        end = new_node;
        if(tabela->entries == NULL)
            tabela->entries = new_node;
        else
            last->next = new_node;

        if(aux->tipo == VARDECL)
            end = add_VarNode(aux->varDecl, new_node);
        else if(aux->tipo == METHODDECL)
            add_MethodNode(aux->methodDecl, new_node, tabela);
        last = end;
    }
    return tabela;
}


void create_MethodTable(MethodTable* methodTable, Param_List* params, VarDecl_List* decls)
{
    Param_List* params_aux = params;
    MethodTableNode* last = NULL;
    for(; params_aux != NULL; params_aux = params_aux->next)
    {
        if(get_sym_local(params_aux->id) != -1)
            sym_duplicate(params_aux->id);

        MethodTableNode* new_node = (MethodTableNode*) malloc(sizeof(MethodTableNode));
        new_node->id = params_aux->id;
        new_node->type = params_aux->tipo;
        new_node->isParam = 1;
        new_node->next = NULL;

        if(methodTable->entries == NULL)
            methodTable->entries = new_node;
        else
            last->next = new_node;

        last = new_node;
    }
    VarDecl_List* aux = decls;
    MethodTableNode* end = NULL;
    for(; aux != NULL; aux = aux->next)
    {
        char* id = aux->declaracao->id_List->id;
        if(get_sym_local(id) != -1)
            sym_duplicate(id);
        MethodTableNode* new_node = (MethodTableNode*) malloc(sizeof(MethodTableNode));
        new_node->id = id;
        new_node->type = aux->declaracao->tipo;
        new_node->isParam = 0;
        new_node->next = NULL;
        MethodTableNode* last2 = new_node;
        ID_List* aux2 = aux->declaracao->id_List->next;
        for(; aux2 != NULL; aux2 = aux2->next){
            if(get_sym_local(aux2->id) != -1)
                sym_duplicate(aux2->id);

            MethodTableNode* newEntry2 = (MethodTableNode*) malloc(sizeof(MethodTableNode));
            newEntry2->id = aux2->id;
            newEntry2->type = aux->declaracao->tipo;
            newEntry2->isParam = 0;
            newEntry2->next = NULL;

            last2->next = newEntry2;
            last2 = newEntry2;
        }
        end = last2;
        if(methodTable->entries == NULL)
            methodTable->entries = new_node;
        else
            last->next = new_node;
        last = end;
    }
}

/*ADD NODES*/
void add_MethodNode(Method_Decl* decl, SymTableNode* tableEntry, Sym_Table* broaderTable)
{
    char* id = decl->id;
    if(get_sym_global(id) != -1)
        sym_duplicate(id);
    tableEntry->id = decl->id;
    tableEntry->type = decl->tipo;
    tableEntry->next = NULL;
    MethodTable* methodTable = (MethodTable*) malloc(sizeof(MethodTable));
    methodTable->broaderTable = broaderTable;
    methodTable->entries = NULL;
    currentLocalTable = methodTable;
    create_MethodTable(methodTable, decl->parametros, decl->declaracoes);
    tableEntry->methodTable = methodTable;
}

SymTableNode* add_VarNode(VarDecl* decl, SymTableNode* tableEntry)
{
    char* id = decl->id_List->id;
    if(get_sym_global(id) != -1)
        sym_duplicate(id);
    tableEntry->id = id;
    tableEntry->type = decl->tipo;
    tableEntry->next = NULL;
    SymTableNode* last = tableEntry;
    ID_List* aux = decl->id_List->next;
    for(; aux != NULL; aux = aux->next)
    {
        if(get_sym_global(aux->id) != -1)
            sym_duplicate(aux->id);
        SymTableNode* new_node = (SymTableNode*) malloc(sizeof(SymTableNode));
        new_node->id = aux->id;
        new_node->type = decl->tipo;
        new_node->methodTable = NULL;
        new_node->next = NULL;
        if(tableEntry->next == NULL)
            tableEntry->next = new_node;
        else
            last->next = new_node;

        last = new_node;
    }

    return last;
}



/*GET*/


Type get_sym(char* id, int isMethod)
{
    if(isMethod)
        return get_sym_global(id);
    else
        return get_sym_local(id);
}

Type get_sym_global(char* id)
{
    SymTableNode* aux = Tabela_sym->entries;
    for(; aux != NULL; aux = aux->next)
    {
        if(aux->id && strcmp(id, aux->id) == 0)
            return aux->type;
    }
    return -1;
}


/*gets*/
Type get_sym_local(char* id)
{
    MethodTableNode* aux = currentLocalTable->entries;
    for(; aux != NULL; aux = aux->next)
    {
        if(aux->id && strcmp(id, aux->id) == 0)
            return aux->type;
    }
    return -1;
}
Type get_sym_local_or_global(char* id)
{
    Type ret = -1;
    if((ret = get_sym_local(id)) == -1)
        ret = get_sym_global(id);
    return ret;
}

MethodTable* get_local_table(char* id)
{
    SymTableNode* aux = Tabela_sym->entries;
    for(; aux != NULL; aux = aux->next)
    {
        if(strcmp(id, aux->id) == 0)
            return aux->methodTable;
    }
    return NULL;
}


/*Aux*/


void sym_duplicate(char* id)
{
    printf("Symbol %s already defined\n", id);
    exit(-1);
}
