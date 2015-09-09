#ifndef _FUNCTIONS_
#define _FUNCTIONS_




#include "structures.h"
#include "display.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>





/*Structs Decl*/
AST_TREE* no_vazio = NULL;
Sym_Table* symtable = NULL;






AST_TREE* create_Root_node(){
    if(no_vazio == NULL){
        AST_TREE* newNull = (AST_TREE*) calloc(sizeof(AST_TREE),1);
        if(newNull==NULL){
            assert(newNull!=NULL);
        }
        newNull->n_type = NO_NULL;
        newNull->n1 = NULL;
        newNull->n2 = NULL;
        newNull->n3 = NULL;
        newNull->next = NULL;
        no_vazio = newNull;
        return newNull;
    }
    return no_vazio;
}


ID_List* add_ID_to_List(AST_TREE* currentNode, char* id){
    if(currentNode==NULL){
        assert(currentNode!=NULL);
    }
    ID_List* tmp;

    //Criar No do tipo ID
    tmp = (ID_List*) calloc(sizeof(ID_List),1);
    if (tmp != NULL){
        tmp->id  = id;
        tmp->next = currentNode->id;
        currentNode->id = tmp;
    }
    else{
        assert(tmp!=NULL);
    }
    return tmp;
}

AST_TREE* add_Class_to_List(char* id, AST_TREE* statements){

    //Criar No do tipo ID
    AST_TREE* newClass = (AST_TREE*) calloc(sizeof(AST_TREE),1);
    if(newClass==NULL){
        assert(newClass!=NULL);
    }
    newClass->n_type = NO_PROGRAMA;
    newClass->id = add_ID_to_List(newClass, id);
    newClass->next = statements;
    return newClass;
}

ID_List* add_VarID_to_ID_LIST(char* id, ID_List* next){
    ID_List* tmp;
    if(id==NULL){
        assert(id!=NULL);
    }

    //create a new varID Node to add to Multiple ID LIST
    tmp = (ID_List*) calloc(sizeof(ID_List),1);
    if (tmp != NULL){
        tmp->id  = id;
        tmp->next = next;
    }
    else{
        assert(tmp!=NULL);
    }
    return tmp;
}


AST_TREE* add_VarDecl(int type, char* id, ID_List* multi_IDs, AST_TREE* next){
    AST_TREE* newVar = (AST_TREE*) calloc(sizeof(AST_TREE),1);
    if(newVar==NULL){
        assert(newVar!=NULL);
    }
    newVar->n_type = NO_VARDECL;
    newVar->type = (Type)type;
    newVar->id = add_VarID_to_ID_LIST(id, multi_IDs);
    newVar->next = next;
    return newVar;
}

AST_TREE* add_ParamDecl(int type, char* id, ID_List* multi_IDs, AST_TREE* next){
    AST_TREE* newParam;
    newParam = add_VarDecl(type,id,multi_IDs,next);
    newParam->n_type = NO_PARAMDECL;
    return newParam;
}


AST_TREE* add_Method(int type, char* id, AST_TREE* params, AST_TREE* varDecl, AST_TREE* statements){
    AST_TREE* tmp;
    AST_TREE* add_Method = (AST_TREE*) calloc(sizeof(AST_TREE),1);
    if(add_Method==NULL){
        assert(add_Method!=NULL);
    }

    add_Method->n_type = NO_METHODDECL;
    add_Method->type = type;
    add_Method->id = add_ID_to_List(add_Method, id);



    //Method PARAM
    tmp = (AST_TREE*) calloc(sizeof(AST_TREE),1);
    assert(tmp!=NULL);
    tmp->n_type = NO_METHODPARAMS;
    add_Method->n1 = tmp;
    tmp->n1 = params;

    //Method Vardecl
    tmp = (AST_TREE*) calloc(sizeof(AST_TREE),1);
    assert(tmp!=NULL);
    tmp->n_type = NO_METHODBODY;
    add_Method->n2 = tmp;
    tmp->n1 = varDecl;



    tmp = (AST_TREE*) calloc(sizeof(AST_TREE),1);
    assert(tmp!=NULL);
    tmp->n_type = NODE_DONTPRINT;
    add_Method->n3 = tmp;
    tmp->n1 = statements;



    /*set to null the pointer*/
    add_Method->next = NULL;
    return add_Method;
}






AST_TREE* add_Compound_Stmnt(AST_TREE* Expr){
    
    //Not NULL
    if(Expr == NULL || Expr->next == NULL)
        return Expr;

    //Create a new Compound Statemnt Node
    AST_TREE* newCompound = (AST_TREE*) calloc(sizeof(AST_TREE),1);
    if(newCompound==NULL){
        assert(newCompound!=NULL);
    }

    newCompound->n_type = NO_COMPOUNDSTAT;
    newCompound->n1 = Expr;

    return newCompound;
}


AST_TREE* add_While(AST_TREE* Expr, AST_TREE* statements){
    AST_TREE* newWhile = (AST_TREE*) calloc(sizeof(AST_TREE),1);
    if(newWhile==NULL){
        assert(newWhile!=NULL);
    }

    newWhile->n_type = NO_WHILE;
    newWhile->n1 = Expr;
    newWhile->n2 = statements;
    if(Expr == NULL)
        newWhile->n1 = create_Root_node();
    if(statements == NULL)
        newWhile->n2 = create_Root_node();
    newWhile->next   = NULL;

    return newWhile;
}


AST_TREE* add_IF(AST_TREE* Expr, AST_TREE* statement1, AST_TREE* statement2 ) {
    AST_TREE* add_IF = (AST_TREE*) calloc(sizeof(AST_TREE),1);
    if(add_IF == NULL) {
        assert(add_IF != NULL);
    }     

    add_IF->n_type = NO_IFELSE;
    add_IF->n1     = Expr;
    add_IF->n2     = statement1;
    add_IF->n3     = statement2;
    add_IF->next   = NULL;


    if(Expr == NULL)
        add_IF->n1 = create_Root_node();
    if(statement1 == NULL)
        add_IF->n2 = create_Root_node();
    if(statement2 == NULL)
        add_IF->n3 = create_Root_node();

    return add_IF;
}

AST_TREE* add_Print(AST_TREE* Expr){
    AST_TREE* newPrint = (AST_TREE*) calloc(sizeof(AST_TREE),1);
    if(newPrint==NULL){
        assert(newPrint!=NULL);
    }

    newPrint->n_type = NO_PRINT;
    newPrint->n1 = Expr;

    if(Expr == NULL)
        newPrint->n1 = create_Root_node();

    newPrint->next   = NULL;

    return newPrint;
}

AST_TREE* add_Return(AST_TREE* Expr) {

    AST_TREE* newReturn = (AST_TREE*) calloc(sizeof(AST_TREE),1);
    if(newReturn == NULL){
        assert(newReturn != NULL);
    }

    newReturn->n_type = NO_RETURN;
    newReturn->n1 = Expr;

    return newReturn;

}

AST_TREE* add_Store(char* id, AST_TREE* arrayIndex, AST_TREE* Expr){

    AST_TREE* thisNode =  (AST_TREE*) calloc(sizeof(AST_TREE),1);
    if(thisNode == NULL){
        assert(thisNode == NULL);
    }

    thisNode->value = NULL;
    thisNode->n1 = add_Terminal_Node(NO_ID,id);
    thisNode->n2 = arrayIndex;

    if(arrayIndex!=NULL){
        thisNode->n_type = NO_STOREARRAY;
        if(arrayIndex == NULL)
            thisNode->n2 = create_Root_node();
    }else
        thisNode->n_type = NO_STORE;

    thisNode->n3 = Expr;
    if(Expr == NULL)
        thisNode->n3 = create_Root_node();

    thisNode->next = NULL;

    return thisNode;
}

AST_TREE* add_Terminal_Node(int n_type, char* token){

    AST_TREE* newTerminal = (AST_TREE*) calloc(sizeof(AST_TREE),1);
    if(newTerminal == NULL){
        assert(newTerminal != NULL);
    }
    newTerminal->n_type = n_type;
    if(n_type == NO_INTLIT)
        newTerminal->type = TYPE_INT;
    else if(n_type == NO_BOOLLIT)
        newTerminal->type = TYPE_BOOL;
   
    newTerminal->value = token;

    return newTerminal;
}
//add id and Expression
AST_TREE* add_ParseInt(char* id, AST_TREE* indx_Expr){
    AST_TREE* newParseInt = (AST_TREE*) calloc(sizeof(AST_TREE),1);
    if(newParseInt == NULL){
        assert(newParseInt != NULL);
    }
    newParseInt->n_type = NO_PARSEARGS;
    newParseInt->n1 = add_Terminal_Node(NO_ID,id);
    newParseInt->n2 = indx_Expr;
    
    if(indx_Expr == NULL)
        newParseInt->n2 = create_Root_node();

    newParseInt->next = NULL;
    return newParseInt;

}

AST_TREE* add_DotLength(AST_TREE* Expr){
    AST_TREE* newDotLength = (AST_TREE*) calloc(sizeof(AST_TREE),1);
    if(newDotLength == NULL){
        assert(newDotLength != NULL);
    }
    newDotLength->n_type = NO_LENGTH;
    newDotLength->n1 = Expr;
    if(Expr == NULL)
        newDotLength->n1 = create_Root_node();

    newDotLength->next = NULL;
    return newDotLength;
}




AST_TREE * add_NewArray(int type, AST_TREE* Expr) {
    AST_TREE * newArray = (AST_TREE*) calloc (sizeof(AST_TREE),1);
    if(newArray == NULL) {
        assert(newArray != NULL);
    } 

    newArray-> n_type = type;
    newArray->n1 = Expr;
    if(Expr == NULL)
        newArray->n1 = create_Root_node();
    if(type == NO_NEWBOOL)
            newArray->type = TYPE_BOOL_ARRAY;
    if(type == NO_NEWINT)
            newArray->type = TYPE_INT_ARRAY;
    newArray->next = NULL;
    return newArray;
}

AST_TREE* add_LoadArray(AST_TREE* Expr, AST_TREE* indx_Expr){
    AST_TREE* newLoadArray = (AST_TREE*) calloc(sizeof(AST_TREE),1);
    if(newLoadArray == NULL){
        assert(newLoadArray != NULL);
    }
    newLoadArray->n_type = NO_LOADARRAY;
    newLoadArray->n1 = Expr;
    newLoadArray->n2 = indx_Expr;
    if(Expr == NULL)
        newLoadArray->n1 = create_Root_node();
    if(indx_Expr == NULL)
        newLoadArray->n2 = create_Root_node();;

    newLoadArray->next = NULL;
    return newLoadArray;
}

AST_TREE* add_Call(char* id, AST_TREE *args){
    AST_TREE * newCall = (AST_TREE*) calloc (sizeof(AST_TREE),1);
    if(newCall == NULL) {
        assert(newCall != NULL);
    }

    newCall-> n_type = NO_CALL;
    add_ID_to_List(newCall, id);
    newCall->n1 = args;
    newCall->next = NULL;
    return newCall;
}

AST_TREE* add_two_Expr(AST_TREE* exp1,char* op,AST_TREE* exp2){
    AST_TREE * newExpression = (AST_TREE*) calloc (sizeof(AST_TREE),1);
    if(newExpression == NULL) {
        assert(newExpression != NULL);
    }

    newExpression-> n_type = getOPType(op);


    if(newExpression->n_type == -1 )
        exit(-2);
    newExpression->n1 = exp1;
    newExpression->n2 = exp2;
    if(exp1 == NULL)
        newExpression->n1 = create_Root_node();
    if(exp2 == NULL)
        newExpression->n2 = create_Root_node();

    newExpression->next = NULL;
    return newExpression;

}

AST_TREE* add_Expr(char* op,AST_TREE* exp){
    AST_TREE * newExpression = (AST_TREE*) calloc (sizeof(AST_TREE),1);
    if(newExpression == NULL) {
        assert(newExpression != NULL);
    }
    newExpression->n_type = getOPType(op);
    if(newExpression->n_type == -1 )
        exit(-2);

    if(newExpression->n_type == NO_PLUS)
        newExpression->n_type = NO_UNARYPLUS;
    if(newExpression->n_type == NO_MINUS)
        newExpression->n_type = NO_UNARYMINUS;
    newExpression->n1 = exp;
    if(exp == NULL)
        newExpression->n1 = create_Root_node();

    newExpression->next = NULL;
    return newExpression;

}


Sym_Table* create_SymTable(AST_TREE* ast){

    Sym_Node* temp = NULL;
    Sym_Node * symbol = NULL;
    Sym_Node* auxiliar = NULL;
    Sym_Table* mainTable = NULL;
    Sym_Table* currentTable = NULL;
    Sym_Table* tempTable = NULL;
    AST_TREE* aux;

    if(ast!=NULL && ast->n_type == NO_PROGRAMA){
        if(mainTable == NULL){
            //create the table
            mainTable = (Sym_Table*) calloc (sizeof(Sym_Table),1);
            assert(mainTable!=NULL);


            //create the Sym_Node and add it to the table
            temp = (Sym_Node*) calloc (sizeof(Sym_Node),1);
            assert(temp!=NULL);
            temp->n_type = TABLE_CLASS;
            temp->id = ast->id;

            mainTable->table = temp;
            currentTable = mainTable;
            symbol = temp;
        }else{
            assert(mainTable!=NULL);
        }
        ast = ast->next;
    }
    while(ast!=NULL){
        if( ast->n_type == NO_VARDECL){
            symbol = add_NewDecl_Table_to_Old(0, symbol,ast, mainTable);
            ast = ast->next;
        }
        else if( ast->n_type == NO_METHODDECL){
            //Create Sym Table
            tempTable = (Sym_Table*) calloc (sizeof(Sym_Table),1);
            assert(tempTable!=NULL);
            currentTable->next = tempTable;
            currentTable = tempTable;

            check_Sym_Exists(ast->id->id,mainTable);

            //add the method decl
            temp = (Sym_Node*) calloc (sizeof(Sym_Node),1);
            assert(temp!=NULL);
            symbol->next = temp;
            symbol = temp;
            symbol->n_type = TABLE_METHOD;
            symbol->type = ast->type;
            symbol->id = ast->id;
            auxiliar = temp;

            //create the two first symbols of the table
            temp = (Sym_Node*) calloc (sizeof(Sym_Node),1);
            assert(temp!=NULL);


            currentTable->table = temp;
            symbol = temp;
            symbol->n_type = TABLE_METHOD;
            symbol->type = ast->type;
            symbol->id = ast->id;

            //add Params Method to MethodDecl
            if(ast->n1->n1!=NULL){
                aux = ast->n1->n1;
                while(aux!=NULL){
                    symbol = add_NewDecl_Table_to_Old(1,symbol,aux, currentTable);
                    aux = aux->next;
               }
            }
            //add DeclsMethod to  MethodDecl
            if(ast->n2->n1!=NULL){
                aux = ast->n2->n1;
                while(aux!=NULL){
                    symbol = add_NewDecl_Table_to_Old(0,symbol,aux, currentTable);
                    aux = aux->next;
                }
            }
            symbol = auxiliar;
            ast = ast->next;
        }
    }
    return mainTable;
}

Sym_Node* add_NewDecl_Table_to_Old(char isparam, Sym_Node* symbol, AST_TREE* ast,Sym_Table* table){
    Sym_Node* temp;
    ID_List* aux;
    check_Sym_Exists(ast->id->id,table);
    temp = (Sym_Node*) calloc (sizeof(Sym_Node),1);
    assert(temp!=NULL);
    symbol->next = temp;
    symbol = temp;
    symbol->n_type = TABLE_DECL;
    symbol->type = ast->type;
    symbol->id = ast->id;
    symbol->isParam = isparam;


    //multiple id declared 
    if(symbol->id->next!=NULL){
        aux = symbol->id->next;
        while(aux!=NULL){
            check_Sym_Exists(aux->id,table);
            temp = (Sym_Node*) calloc (sizeof(Sym_Node),1);
            assert(temp!=NULL);
            symbol->next = temp;
            symbol = temp;
            symbol->n_type = TABLE_DECL;
            symbol->type = ast->type;
            symbol->id = aux;
            aux = aux->next;
        }
    }
    return temp;
}





/*AUX FUNCTIONS*/




NodeType getOPType(char* op){
    if(strcmp(op, "&&") == 0)
        return NO_AND;
    else if(strcmp(op, "||") == 0)
        return NO_OR;
    else if(strcmp(op, "<") == 0)
        return NO_LESS;
    else if(strcmp(op, ">") == 0)
        return NO_GREATER;
    else if(strcmp(op, "<=") == 0)
        return NO_LESSEQUAL;
    else if(strcmp(op, ">=") == 0)
        return NO_GREATEREQUAL;
    else if(strcmp(op, "!=") == 0)
        return NO_DIFFERENT;
    else if(strcmp(op, "==") == 0)
        return NO_EQUAL;
    else if(strcmp(op, "!") == 0)
        return NO_NOT;
    else if(strcmp(op, "+") == 0)
        return NO_PLUS;
    else if(strcmp(op, "-") == 0)
        return NO_MINUS;
    else if(strcmp(op, "*") == 0)
        return NO_MUL;
    else if(strcmp(op, "/") == 0)
        return NO_DIV;
    else if(strcmp(op, "%") == 0)
        return NO_MOD;

    return -1;
}

//Check if Symbol exist in the sym table
void check_Sym_Exists(char* id, Sym_Table* table){
    Sym_Node* local = table->table->next;
    while(local!=NULL){
        if((local->n_type == TABLE_DECL || local->n_type == TABLE_METHOD) && strcmp(id,local->id->id)==0){
            printf("Symbol %s already defined\n",id);
            exit(0);
        }
        local = local->next;
    }
}

//returns type of id of sym table
int check_Sym_ID_Exists(char* id,TableType type, Sym_Table* table, Sym_Table* main){
    Sym_Node* local = table->table->next;
    while(local!=NULL){
        if((local->n_type == type) && strcmp(id,local->id->id)==0){
            return local->type;
        }
        local = local->next;
    }
    local = main->table->next;
    while(local!=NULL){
        if((local->n_type == type) && strcmp(id,local->id->id)==0){
            return local->type;
        }
        local = local->next;
    }

    printf("Cannot find symbol %s\n",id);
    exit(0);
}



Sym_Table* get_Method_SymTable(Sym_Table* main, char* methodID){
    while(main!=NULL){
        if(main->table->n_type == TABLE_METHOD && strcmp(methodID,main->table->id->id)==0)
            return main;
        else
            main = main->next;
   }
   return main;
}

/*Node Types*/
void check_Types(AST_TREE* ast, Sym_Table *main){

    if(ast->n_type == NO_GREATER || ast->n_type == NO_LESS || ast->n_type == NO_GREATEREQUAL || ast->n_type == NO_LESSEQUAL ){
        if(ast->n1->type != TYPE_INT || ast->n2->type != TYPE_INT){
            OP_Error_two_Types(ast->n_type,ast->n1->type,ast->n2->type);
        }
        ast->type = TYPE_BOOL;
    }
    else if(ast->n_type == NO_PLUS || ast->n_type == NO_MINUS || ast->n_type == NO_DIV || ast->n_type == NO_MUL || ast->n_type == NO_MOD){
        if(ast->n1->type != TYPE_INT || ast->n2->type != TYPE_INT){
            OP_Error_two_Types(ast->n_type,ast->n1->type,ast->n2->type);
        }
        ast->type = TYPE_INT;
    }
    else if(ast->n_type == NO_EQUAL || ast->n_type == NO_DIFFERENT){
        if(ast->n1->type != ast->n2->type){
            OP_Error_two_Types(ast->n_type,ast->n1->type,ast->n2->type);
        }
        ast->type = TYPE_BOOL;
    }
    else if(ast->n_type == NO_AND || ast->n_type == NO_OR){
        if(ast->n1->type != TYPE_BOOL || ast->n2->type != TYPE_BOOL){
            OP_Error_two_Types(ast->n_type,ast->n1->type,ast->n2->type);
        }
        ast->type = TYPE_BOOL;
    }
    else if(ast->n_type == NO_LOADARRAY ){
        if(ast->n2->type != TYPE_INT || (ast->n1->type != TYPE_BOOL_ARRAY && ast->n1->type != TYPE_INT_ARRAY)){
            OP_Error_two_Types(ast->n_type,ast->n1->type,ast->n2->type);
        }
        if(ast->n1->type == TYPE_INT_ARRAY)
            ast->type = TYPE_INT;
        else if(ast->n1->type == TYPE_BOOL_ARRAY)
            ast->type = TYPE_BOOL;
        else{
            ast->type = ast->n1->type;
        }
    }
    else if( ast->n_type == NO_NEWINT || ast->n_type == NO_NEWBOOL ){
        assert(ast->n1!=NULL);
        if(ast->n1->type != TYPE_INT){
            OP_Error_Type(ast->n_type,ast->n1->type);
        }
        if(ast->n_type == NO_NEWINT)
            ast->type = TYPE_INT_ARRAY;
        else
            ast->type = TYPE_BOOL_ARRAY;
    }
    else if( ast->n_type == NO_LENGTH){
        if((ast->n1->type != TYPE_BOOL_ARRAY && ast->n1->type != TYPE_INT_ARRAY && ast->n1->type != TYPE_STRING_ARRAY)){
            OP_Error_Type(ast->n_type,ast->n1->type);
        }
        ast->type = TYPE_INT;
    }
    else if( ast->n_type == NO_UNARYPLUS || ast->n_type == NO_UNARYMINUS){
        if((ast->n1->type != TYPE_INT)){
            OP_Error_Type(ast->n_type,ast->n1->type);
        }
        ast->type = TYPE_INT;
    }
    else if(ast->n_type == NO_NOT){
        if((ast->n1->type != TYPE_BOOL)){
            OP_Error_Type(ast->n_type,ast->n1->type);
        }
        ast->type = TYPE_BOOL;
    }
    else if( ast->n_type == NO_PARSEARGS){
        if((ast->n1->type != TYPE_STRING_ARRAY || ast->n2->type != TYPE_INT)){
            OP_Error_two_Types(ast->n_type,ast->n1->type,ast->n2->type);
        }
        ast->type = TYPE_INT;
    }
    else if (ast->n_type == NO_CALL){
        int i = 0;
        Type astType, tableType;

        char* id = ast->id->id;
        Sym_Table* aux= get_Method_SymTable(main, id);
        Sym_Node* table;
        table = aux->table->next;

        ast->type = aux->table->type;
        ast = ast->n1;
        while(ast!=NULL || table!=NULL){
            astType = TYPE_VOID;
            tableType = TYPE_VOID;

            if(ast!=NULL){
                astType = ast->type;
                ast = ast->next;
            }

            if(table!=NULL){
                //Param TYPE
                if(table->isParam == 1){
                    tableType = table->type;
                    table = table->next;
                }else{
                    table = NULL;
                }
            }

            if(astType != tableType){
                getErrorCall(i,id, astType, tableType);
            }
            i++;
        }

    }
    //Statement 
    else if( ast->n_type == NO_IFELSE || ast->n_type == NO_WHILE){
        if((ast->n1->type != TYPE_BOOL)){
            statmnt_Error(ast->n_type,ast->n1->type,TYPE_BOOL);
        }
    }
    else if( ast->n_type == NO_PRINT){
        if((ast->n1->type != TYPE_BOOL && ast->n1->type != TYPE_INT)){
            statemnt_Error_3vars(ast->n_type,ast->n1->type,TYPE_BOOL,TYPE_INT);
        }
        ast->type = TYPE_INT;
    }else if(ast->n_type == NO_COMPOUNDSTAT){
        ast->type = ast->n1->type;
    }
    else if(ast->n_type == NO_STORE || ast->n_type == NO_STOREARRAY){

        //if is not null its a STORE 
        if(ast->n2!=NULL){
            if(ast->n2->type != TYPE_INT || (ast->n1->type != TYPE_BOOL_ARRAY && ast->n1->type != TYPE_INT_ARRAY)){
                OP_Error_two_Types(NO_LOADARRAY,ast->n1->type,ast->n2->type);
            }

            if(ast->n1->type == TYPE_INT_ARRAY)
                ast->n1->type = TYPE_INT;
            else if(ast->n1->type == TYPE_BOOL_ARRAY)
                ast->n1->type = TYPE_BOOL;
        }
        // id is equal to expr
        if(ast->n1->type != ast->n3->type){
            if(ast->n_type == NO_STORE)
                assign_Error(ast->n1->value,ast->n3->type,ast->n1->type);
            else
                assignm_Array_Error(ast->n1->value,ast->n3->type,ast->n1->type);
        }
        ast->type = ast->n1->type;
    }

    else if( ast->n_type == NO_RETURN){
        if(ast->n1!=NULL){
            if((ast->n1->type != get_Function_Types())){
                statmnt_Error(ast->n_type,ast->n1->type,get_Function_Types());
            }
        }else if(get_Function_Types()!=TYPE_VOID){
            statmnt_Error(ast->n_type,TYPE_VOID,get_Function_Types());
        }
    }
}


void check_INTLIT(char* lit){
    int len = strlen(lit);

    //IF its DECIMAL
    if(lit[0]!='0')
        return;

    //IF its HEX
    if(len>0 && lit[1] == 'x')
        return;

    //IF its Octa
    while(len>0){
        if(lit[len] > '7'){
            printf("Invalid literal %s\n",lit);
            exit(0);
        }
        len--;
    }
    return;
}



/*Gets and Sets*/
int get_Function_Types(){
    return symtable->table->type;
}
char* get_Function_ID(){
    return symtable->table->id->id;
}
AST_TREE* set_next_Node(AST_TREE* current, AST_TREE* next){
    if(current == NULL)
        return next;
    else{
        current->next = next;
        return current;
    }
}


void setTable(Sym_Table * table){
    symtable = table;
}
AST_TREE* setStatic(AST_TREE* currentNode){
    if(currentNode==NULL){
        return currentNode;
    }
    currentNode->isStatic = TRUE;
    return currentNode;
}





/*Error Printing Functions*/
void assign_Error(char* var, int n1, int n2){
    printf("Incompatible type in assignment to %s (got %s, required %s)\n",var,SYMBOLS_TYPE[n1],SYMBOLS_TYPE[n2]);
    exit(0);
}
void assignm_Array_Error(char* var, int n1, int n2){
    printf("Incompatible type in assignment to %s[] (got %s, required %s)\n",var,SYMBOLS_TYPE[n1],SYMBOLS_TYPE[n2]);
    exit(0);
}
void OP_Error_two_Types(int op,int n1, int n2){
    printf("Operator %s cannot be applied to types %s, %s\n",OPERATORS[op],SYMBOLS_TYPE[n1],SYMBOLS_TYPE[n2]);
    exit(0);
}
void OP_Error_Type(int op,int n1){
    printf("Operator %s cannot be applied to type %s\n",OPERATORS[op],SYMBOLS_TYPE[n1]);
    exit(0);
}
void getErrorCall(int i,char* name, int n1, int n2){
    printf("Incompatible type of argument %d in call to method %s (got %s, required %s)\n",i,name,SYMBOLS_TYPE[n1],SYMBOLS_TYPE[n2]);
    exit(0);
}
void statmnt_Error(int op, int n1,int n2){
     printf("Incompatible type in %s statement (got %s, required %s)\n",OPERATORS[op],SYMBOLS_TYPE[n1],SYMBOLS_TYPE[n2]);
     exit(0);
}
void statemnt_Error_3vars(int op, int n1, int n2, int n3){
    printf("Incompatible type in %s statement (got %s, required %s or %s)\n",OPERATORS[op],SYMBOLS_TYPE[n1],SYMBOLS_TYPE[n2],SYMBOLS_TYPE[n3]);
     exit(0);
}









/* Error Finding Functions*/
void check_Semantic_Errors(AST_TREE* ast, Sym_Table* local, Sym_Table* main){

    if(ast->n_type == NO_METHODDECL){
        local = get_Method_SymTable(main,ast->id->id);
        setTable(local);
    }
    //Node 1 to 3
    if(ast->n1 != NULL){
        check_Semantic_Errors(ast->n1, local, main);
    }
    if(ast->n2 != NULL){
        check_Semantic_Errors(ast->n2, local, main);
    }
    if(ast->n3 != NULL){
        check_Semantic_Errors(ast->n3, local, main);
    }

    check_Errors(ast,local,main);

    //next node in the tree
    if(ast->next != NULL)
        check_Semantic_Errors(ast->next, local, main);

    return;
}

void check_Errors(AST_TREE* ast, Sym_Table* symbols, Sym_Table* main){
    if(ast->n_type == NO_CALL){
        ast->type = check_Sym_ID_Exists(ast->id->id,TABLE_METHOD,symbols,main);
    }
    else if(ast->n_type == NO_ID){
        ast->type = check_Sym_ID_Exists(ast->value,TABLE_DECL,symbols,main);
    }
    else if(ast->n_type == NO_INTLIT){
        check_INTLIT(ast->value);
    }
    check_Types(ast,main);

}



#endif
