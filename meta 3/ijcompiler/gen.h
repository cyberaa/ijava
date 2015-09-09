#ifndef _GEN_H_
#define _GEN_H_



#define DEBUG 0


typedef struct _call{
    char tok[100];
    Tipo tipo;
    struct _call* next;
}call_Struct;



char checkID_Locallity(char* id,char* methodID,Sym_Table* tabela);
char* genCode(AST_TREE* arvore,Sym_Table* tabela);



#endif
