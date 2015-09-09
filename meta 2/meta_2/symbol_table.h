#ifndef SYMBOLS_H
#define SYMBOLS_H

#include "structures.h"


typedef struct _MethodTableNode
{
    char* id;
    int isParam;
    Type type;
    struct _MethodTableNode* next;
} MethodTableNode;

typedef struct _methodTable
{
    MethodTableNode* entries;
    struct _classTable* broaderTable;

} MethodTable;

typedef struct _SymTableNode
{
    char* id;
    MethodTable* methodTable;
    Type type;
    struct _SymTableNode* next;
} SymTableNode;

typedef struct _classTable
{
    char* id;
    SymTableNode* entries;
} Sym_Table;

Sym_Table* buildSymbolsTables(Class*);
#endif
