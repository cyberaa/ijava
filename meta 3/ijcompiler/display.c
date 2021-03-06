#ifndef _DISPLAYF_
#define _DISPLAYF_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "structures.h"


void print_indentation(int i) {
    while(i > 0) {
        printf("  ");
        i--;
    }
}

//Print one AST AST_TREE depending on the type
void printAST_Node( AST_TREE* currentNode, int tabs) {

    if(currentNode->tipo_no == NODE_DONTPRINT)
           return;
    else if(currentNode->tipo_no == NO_BOOLLIT || currentNode->tipo_no == NO_INTLIT || currentNode->tipo_no == NO_ID ) {
        print_indentation(tabs);
        printf("%s(%s)\n",OP_TO_STRING[currentNode->tipo_no], currentNode->value);
    }
    else {
        print_indentation(tabs);
        printf("%s\n", OP_TO_STRING[currentNode->tipo_no]);
        if(currentNode->tipo_no == NO_VARDECL || currentNode->tipo_no == NO_PARAMDECL || currentNode->tipo_no == NO_METHODDECL){
            print_indentation(tabs + 1);
            printf("%s\n",NODE_TYPES[currentNode->type]);
        }
        print_ID(currentNode->id,tabs+1, currentNode->tipo_no, currentNode->type);
    }
        
}

//Print ID Nodes with correct identation
void print_ID(ID_List* ids,int tabs, int tipo_no, int type) {
    while(ids != NULL) {
        print_indentation(tabs);
        printf("Id(%s)\n",ids->id);
        ids = ids->next;
    }
}

//Recursion to print all nodes from each node
void print_lowerTreelevels(AST_TREE* currentNode, int tabs) {
    printAST_Node(currentNode, tabs);
        //Recursion
            //From AST_TREE 1 to 3
            if(currentNode->n1 != NULL){
                print_lowerTreelevels(currentNode->n1, tabs + 1);
            }
            if(currentNode->n2 != NULL){
                print_lowerTreelevels(currentNode->n2, tabs + 1);
            }
            if(currentNode->n3 != NULL){
                print_lowerTreelevels(currentNode->n3, tabs + 1);
            }
    //next
    if(currentNode->next != NULL)
        print_lowerTreelevels(currentNode->next, tabs);
    
}

/*Print Tree and Lower levels node*/
void print_TREE(AST_TREE* AST) {
    if(AST != NULL) {
        printf("%s\n", OP_TO_STRING[AST->tipo_no]);  
        print_indentation(1);
        printf("Id(%s)\n", AST->id->id);   
    }
    
    if(AST->next != NULL)
        print_lowerTreelevels(AST->next,1);
}


/*SYM Print Functions */
void printSymbol_Decl(Sym_Node* tableNode){
    if(tableNode!=NULL){
        if(tableNode->tipo_no == TABLE_METHOD)
            printf("%s\tmethod\n",tableNode->id->id);
        else{
            if(tableNode->isParam)
                printf("%s\t%s\tparam\n",tableNode->id->id,SYMBOLS_TYPE[tableNode->type]);
            else
                printf("%s\t%s\n",tableNode->id->id,SYMBOLS_TYPE[tableNode->type]);
        }
        printSymbol_Decl(tableNode->next);
    }
}

/*Sym Sym_Table creation*/
void printSymbolTables(Sym_Table* table){
    if(table!=NULL){
        if(table->table->tipo_no == TABLE_CLASS){
            printf("===== Class %s Symbol Table =====\n",table->table->id->id);
            printSymbol_Decl(table->table->next);
        }
        else if(table->table->tipo_no == TABLE_METHOD){
            printf("\n===== Method %s Symbol Table =====\nreturn\t%s\n",table->table->id->id,SYMBOLS_TYPE[table->table->type]);
            printSymbol_Decl(table->table->next);
        }
        printSymbolTables(table->next);
    }
}
#endif
