#ifndef _DISPLAY_
#define _DISPLAY_

#include "structures.h"

static const char* NODE_TYPES[] = {    
                "Void",  
                "Int",    
                "Bool",
                "IntArray",    
                "BoolArray",  
                "StringArray",   
                "Id",    
                "IntLit",
                "BoolLit",   
                "BoolArray", 

};

static const char* SYMBOLS_TYPE[] = {   
                "void",   
                "int",     
                "boolean",
                "int[]",    
                "boolean[]",    
                "String[]",    
                "Id",    
                "IntLit",
                "BoolLit",     
                "BoolArray",  
};


static const char *OP_TO_STRING[] = {
                "Program",
                 "VarDecl",
                 "MethodDecl",
                 "MethodParams",
                 "MethodBody",
                 "ParamDeclaration",
                 "CompoundStat",
                 "IfElse",
                 "Print",
                 "Return",
                 "Store",
                 "Mul",
                 "Div",
                 "Mod",
                 "Not",
                 "Sub",
                 "Add",
                 "Length",
                 "LoadArray",
                 "Call",
                 "NewInt",
                 "NewBool",
                 "ParseArgs",
                 "While",
                 "StoreArray",
                 "IntLit",
                 "BoolLit",
                 "Id",
                 "And",
                 "Or",
                 "Lt",
                 "Gt",
                 "Leq",
                 "Geq",
                 "Neq",
                 "Eq",
                 "Null",
                 "Plus",
                 "Minus"
 };
/* For semantic errors */

static const char *OPERATORS[] = {
                "Program",
                 "VarDecl",
                 "MethodDecl",
                 "MethodParams",
                 "MethodBody",
                 "ParamDeclaration",
                 "CompoundStat",
                 "if",
                 "System.out.println",
                 "return",
                 "=",
                 "*",
                 "/",
                 "%",
                 "!",
                 "-",
                 "+",
                 ".length",
                 "[",
                 "call",
                 "new int",
                 "new boolean",
                 "Integer.parseInt",
                 "while",
                 "=",
                 "IntLit",
                 "BoolLit",
                 "Id",
                 "&&",
                 "||",
                 "<",
                 ">",
                 "<=",
                 ">=",
                 "!=",
                 "==",
                 "null",
                 "+",
                 "-"
};
static const char *LLVM_OPERATORS[] = {"Program","VarDecl","MethodDecl","MethodParams","MethodBody", "ParamDeclaration","CompoundStat", 
                 "if","System.out.println","return","=","mul","sdiv","srem","!",
                 "sub","add",".length", "[","call","new int","new boolean",
                 "Integer.parseInt","while","=","IntLit","BoolLit",
                 "Id", "and", "or",
                 "slt","sgt","sle","sge","ne","eq","null",
                 "+","-"
                 };

static const char* llvm_Types[] = {"void","i32","i1","%.ArrayInt","%.ArrayBool", "i8*","Id","i32","i1","i1*", };



void print_ID(ID_List* ids,int tabs, int n_type, int type);
void print_TREE(AST_TREE* AST);
void print_lowerTreelevels(AST_TREE* currentNode, int tabs);
void printSymbolTables(Sym_Table* table);
void printSymbol_Decl(Sym_Node* tableNode);
#endif
