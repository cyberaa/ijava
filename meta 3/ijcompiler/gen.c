#ifndef _GENCODE_
#define _GENCODE_



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "structures.h"
#include "gen.h"
#include "display.h"

#define PARAMETRO 1
#define VAR_LOCAL 2
#define VAR_GLOBAL 3

#define DEBUG 0



int tipo_funcao;
int countreturn;
int ident = 0;
int index_var = 0;
int flag_bool = 0;
int s1 = 0;
int s2  = 1;
int s3 = 2;

char* curr_Method;
char function_body  = FALSE;
char flag_hasparam = FALSE;
char valor_return[100];
char flagparam = FALSE;
char testflag = TRUE;






char* genCode(AST_TREE* arvore,Sym_Table* tabela){
    ID_List* aux;
	char value1[100];
	char value2[100];
	char value3[100];


    if(arvore!=NULL){
        if(arvore->tipo_no == NO_PROGRAMA){
            printf("declare i32 @printf(i8* noalias nocapture, ...)\n");
            printf("declare noalias i8* @calloc(i32, i32) nounwind\n");
            printf("declare i32 @atoi(i8*) nounwind readonly\n");
            printf("@.printInt = private constant [4 x i8] c\"%%d\\0A\\00\"\n");
            printf("@.true = private constant [6 x i8] c\"true\\0A\\00\"\n");
            printf("@.false = private constant [7 x i8] c\"false\\0A\\00\"\n");
            printf("@.printBool = private constant [2 x i8*] [i8* getelementptr inbounds ([7 x i8]* @.false, i32 0, i32 0),i8* getelementptr inbounds ([6 x i8]* @.true, i32 0, i32 0)]\n\n");
            printf("%%.ArrayInt = type { i32, i32* }\n");
            printf("%%.ArrayBool = type { i32, i1* }\n");

            //Start of program
            //init the counter
            countreturn = 0;
        }
        else if(arvore->tipo_no == NO_VARDECL){
            if(function_body == FALSE ){
                aux = arvore->id;
                while(aux!=NULL){
                    if(arvore->type == TYPE_INT || arvore->type == TYPE_BOOL)
                        printf("@%s = global %s 0\n",aux->id,llvm_Types[arvore->type]);
                    else{
                        if(arvore->type == TYPE_INT_ARRAY)
                            printf("@%s = global %s {i32 0, i32* null}\n",aux->id,llvm_Types[arvore->type]);
                        else if(arvore->type == TYPE_BOOL_ARRAY)
                            printf("@%s = global %s {i32 0, i1* null}\n",aux->id,llvm_Types[arvore->type]);
                    }
                    aux = aux->next;
                }
            }
            else{
                aux = arvore->id;
                while(aux!=NULL){
                    print_indentation(ident);
                    printf("%%%s = alloca %s\n",aux->id,llvm_Types[arvore->type]);
                    aux = aux->next;
                }
           }
        }
        else if(arvore->tipo_no == NO_METHODDECL){
            curr_Method = arvore->id->id;
            index_var = 0;
            function_body = TRUE;
            ident++;
            if(strcmp(arvore->id->id,"main")==0){
                tipo_funcao = TYPE_INT;
                if(arvore->n1->n1!=NULL)
                    printf("\n\ndefine i32 @main(i32 %%..argc, i8** %%%s){\n",arvore->n1->n1->id->id);
                else
                    printf("\n\ndefine i32 @main(i32 %%..argc, i8** argv){\n");
            }
            else{
                tipo_funcao = arvore->type;
                printf("\ndefine %s @%s(",llvm_Types[arvore->type],arvore->id->id);
                genCode(arvore->n1->n1,tabela);
                if(arvore->n1->n1==NULL)
                    printf("){\n");
            }
            flag_hasparam = FALSE;
            genCode(arvore->n2->n1,tabela);
            printf("\n");
            genCode(arvore->n3->n1,tabela);
            printf("\n");
            print_indentation(ident);
            if(tipo_funcao == TYPE_INT)
                printf("ret i32 0\n");
            else if(tipo_funcao == TYPE_BOOL)
                printf("ret i1 0\n");
            else if(tipo_funcao == TYPE_INT_ARRAY)
                printf("ret %%.ArrayInt {i32 0, i32* null}\n");
            else if(tipo_funcao == TYPE_BOOL_ARRAY)
                printf("ret %%.ArrayBool {i32 0, i1* null}\n");
            else if(tipo_funcao == TYPE_VOID)
                printf("ret void\n");
            printf("}\n\n");
            ident--;
            function_body = FALSE;
        }
        else if(arvore->tipo_no == NO_PARAMDECL){
            if(flag_hasparam == TRUE)
                printf(",");
            flag_hasparam = TRUE;
            printf("%s %%.%s",llvm_Types[arvore->type],arvore->id->id);
            genCode(arvore->next,tabela);
            if(arvore->next == NULL)
                printf("){\n");
            printf("%%%s  = alloca %s\n",arvore->id->id,llvm_Types[arvore->type]);
            printf("store %s %%.%s, %s* %%%s",llvm_Types[arvore->type],arvore->id->id,llvm_Types[arvore->type],arvore->id->id);
            return valor_return;
        }
        else if(arvore->tipo_no == NO_PLUS || arvore->tipo_no == NO_MINUS || arvore->tipo_no == NO_MUL || arvore->tipo_no == NO_DIV || arvore->tipo_no == NO_MOD){
            strcpy(value1,genCode(arvore->n1,tabela));
            strcpy(value2,genCode(arvore->n2,tabela));
            print_indentation(ident);
            index_var++;
            printf("%%..%d = %s %s %s , %s\n\n",index_var,LLVM_OPERATORS[arvore->tipo_no],llvm_Types[arvore->n1->type],value1,value2);   //<result> = add/sub/mul/sdiv <ty> <op1>, <op2>
            sprintf(valor_return,"%%..%d",index_var);
            return valor_return;
        }
        else if(arvore->tipo_no == NO_OR){
            strcpy(value1,genCode(arvore->n1,tabela));
            int tmp = countreturn;
            int temp2;
            print_indentation(ident);
            index_var++;
            temp2 = index_var;
            printf("%%..%d = alloca i1\n",index_var);
            print_indentation(ident);
            printf("store i1 %s, i1* %%..%d\n",value1,index_var);


            //AFTER
            print_indentation(ident);
            index_var++;
            printf("%%..%d = icmp eq i1 0, %s\n", index_var, value1);
            print_indentation(ident);
            printf("br i1 %%..%d, label %%and.do%d, label %%and.end%d\n",index_var,tmp,tmp);
            printf("and.do%d:\n",tmp);
            countreturn++;
            strcpy(value2,genCode(arvore->n2,tabela));
            print_indentation(ident);
            printf("store i1 %s, i1* %%..%d\n",value2,temp2);
            print_indentation(ident);
            printf("br label %%and.end%d\n",tmp);
            printf("and.end%d:\n",tmp);
            index_var++;
            print_indentation(ident);
            printf("%%..%d = load i1* %%..%d\n",index_var,temp2);
            sprintf(valor_return,"%%..%d",index_var);
            return valor_return;
        }
        else if(arvore->tipo_no == NO_AND){
            strcpy(value1,genCode(arvore->n1,tabela));
            int tmp = countreturn;
            int temp2;
            print_indentation(ident);
            index_var++;
            temp2 = index_var;
            printf("%%..%d = alloca i1\n",index_var);
            print_indentation(ident);
            printf("store i1 %s, i1* %%..%d\n",value1,index_var);

            print_indentation(ident);
            index_var++;
            printf("%%..%d = icmp eq i1 1, %s\n", index_var, value1);
            print_indentation(ident);
            printf("br i1 %%..%d, label %%and.do%d, label %%and.end%d\n",index_var,tmp,tmp);
            printf("and.do%d:\n",tmp);
            countreturn++;
            strcpy(value2,genCode(arvore->n2,tabela));
            print_indentation(ident);
            printf("store i1 %s, i1* %%..%d\n",value2,temp2);
            print_indentation(ident);
            printf("br label %%and.end%d\n",tmp);
            printf("and.end%d:\n",tmp);
            index_var++;
            print_indentation(ident);
            printf("%%..%d = load i1* %%..%d\n",index_var,temp2);
            sprintf(valor_return,"%%..%d",index_var);
            return valor_return;
        }
        else if(arvore->tipo_no == NO_INTLIT){
            //DEC?
            if(*(arvore->value)!='0'){
                sprintf(valor_return,"%d",atoi(arvore->value));
                return valor_return;
            }
            //HEX?
            int len = strlen(arvore->value);
            if(len>0 && *(arvore->value+1) == 'x'){
                sprintf(valor_return,"%ld",strtol((arvore->value+2),NULL,16));
                return valor_return;
            }
            sprintf(valor_return,"%ld",strtol(arvore->value,NULL,8));


            return valor_return;
        }
        else if(arvore->tipo_no == NO_BOOLLIT){
            if(strcmp(arvore->value,"true")==0)
                sprintf(valor_return,"%d",1);
            else
                sprintf(valor_return,"%d",0);
            return valor_return;
        }
        else if(arvore->tipo_no == NO_UNARYPLUS){
            return genCode(arvore->n1,tabela);

        }
        else if(arvore->tipo_no == NO_UNARYMINUS){
            strcpy(value1,genCode(arvore->n1,tabela));
            print_indentation(ident);

            index_var++;
           
            printf("%%..%d = mul %s -1 , %s\n",index_var,llvm_Types[arvore->type],value1);
            sprintf(valor_return,"%%..%d",index_var);


            return valor_return;

        }

        else if(arvore->tipo_no == NO_NOT){
            strcpy(value1,genCode(arvore->n1,tabela));
            print_indentation(ident);

            index_var++;
            
            printf("%%..%d = sub i1 1, %s\n",index_var,value1);
            sprintf(valor_return,"%%..%d",index_var);


            return valor_return;
        }
        else if(arvore->tipo_no == NO_GREATER || arvore->tipo_no == NO_LESS || arvore->tipo_no == NO_GREATEREQUAL || arvore->tipo_no == NO_LESSEQUAL || arvore->tipo_no == NO_EQUAL || arvore->tipo_no == NO_DIFFERENT){
            strcpy(value1,genCode(arvore->n1,tabela));
            strcpy(value2,genCode(arvore->n2,tabela));
            print_indentation(ident);

            index_var++;
            printf("%%..%d = icmp %s %s %s, %s\n",index_var,LLVM_OPERATORS[arvore->tipo_no],llvm_Types[arvore->n1->type] ,value1,value2);
            sprintf(valor_return,"%%..%d",index_var);


            return valor_return;
        }
        else if(arvore->tipo_no == NO_ID){

            print_indentation(ident);
            char result = checkID_Locallity(arvore->value,curr_Method,tabela);
            if(result != VAR_GLOBAL){
                index_var++;
                printf("%%..%d = load %s* %%%s\n",index_var,llvm_Types[arvore->type],arvore->value);
            }
            else{
                index_var++;
                printf("%%..%d = load %s* @%s\n",index_var,llvm_Types[arvore->type],arvore->value);
            }
            sprintf(valor_return,"%%..%d",index_var);


            return valor_return;
        }
		//store i32 3, i32* %ptr
        else if(arvore->tipo_no == NO_STORE){ 	 
            char tmp;
            printf(";STORE\n");
            strcpy(value1,genCode(arvore->n3,tabela));
            print_indentation(ident);
            tmp = checkID_Locallity(arvore->n1->value,curr_Method,tabela);
            if(tmp!=VAR_GLOBAL){
                printf("store %s %s, %s* %%%s\n\n",llvm_Types[arvore->n1->type],value1,llvm_Types[arvore->n1->type],arvore->n1->value);
            }
            else{
                printf("store %s %s, %s* @%s\n\n",llvm_Types[arvore->n1->type],value1,llvm_Types[arvore->n1->type],arvore->n1->value);
            }

        }
        else if(arvore->tipo_no == NO_STOREARRAY){


            printf(";STOREARRAY\n");
            printf(";ARRAY\n");
            strcpy(value1,genCode(arvore->n1,tabela));
            printf(";INDEX\n");
            strcpy(value2,genCode(arvore->n2,tabela));
            printf(";VALUE\n");
            strcpy(value3,genCode(arvore->n3,tabela));

            printf(";STORE\n");
            index_var++;
            print_indentation(ident);
            printf("%%..%d = extractvalue %s %s, 1\n", index_var, llvm_Types[arvore->n1->type], value1);
            index_var++;
            print_indentation(ident);
            printf("%%..%d = getelementptr %s* %%..%d, i32 %s\n", index_var, llvm_Types[arvore->n3->type], index_var -1, value2);
            print_indentation(ident);
            printf("store %s %s, %s* %%..%d\n", llvm_Types[arvore->n3->type], value3, llvm_Types[arvore->n3->type], index_var);


        }
        else if(arvore->tipo_no == NO_LOADARRAY){

            printf(";LOADARRAY\n");
            strcpy(value1,genCode(arvore->n1,tabela));
            strcpy(value2,genCode(arvore->n2,tabela));

            index_var++;
            print_indentation(ident);
            printf("%%..%d = extractvalue %s %s, 1\n", index_var,llvm_Types[arvore->n1->type], value1);
            if(arvore->n1->type == TYPE_BOOL_ARRAY){
                index_var++;
                print_indentation(ident);
                printf("%%..%d = getelementptr i1* %%..%d, i32 %s\n",index_var,index_var-1,value2);
                index_var++;
                print_indentation(ident);
                printf("%%..%d = load i1* %%..%d\n",index_var,index_var-1);
            }else if(arvore->n1->type == TYPE_INT_ARRAY){

                index_var++;
                print_indentation(ident);
                printf("%%..%d = getelementptr i32* %%..%d, i32 %s\n",index_var,index_var-1,value2);
                index_var++;
                print_indentation(ident);
                printf("%%..%d = load i32* %%..%d\n",index_var,index_var-1);
            }
            sprintf(valor_return,"%%..%d",index_var);
            return valor_return;

        }
        else if(arvore->tipo_no == NO_NEWINT){

            printf(";NEWINTARRAY\n");

            strcpy(value1,genCode(arvore->n1,tabela));
            index_var++;
            print_indentation(ident);
            printf("%%..%d = call noalias i8* @calloc(i32 %s, i32 4) nounwind\n\n", index_var, value1);
            index_var++;
            print_indentation(ident);
            printf("%%..%d = bitcast i8* %%..%d to i32*\n", index_var, index_var -1);
            index_var++;
            print_indentation(ident);
            printf("%%..%d = insertvalue %%.ArrayInt undef, i32 %s, 0\n", index_var, value1);
            index_var++;
            print_indentation(ident);
            printf("%%..%d = insertvalue %%.ArrayInt %%..%d, i32* %%..%d, 1\n", index_var, index_var -1, index_var -2);
            sprintf(valor_return,"%%..%d",index_var);


            return valor_return;


       }
        else if(arvore->tipo_no == NO_NEWBOOL){


            printf(";NEWBOOLARRAY\n");
            strcpy(value1,genCode(arvore->n1,tabela));
            index_var++;
            print_indentation(ident);
            printf("%%..%d = call noalias i8* @calloc(i32 %s, i32 1) nounwind\n\n", index_var, value1);
            index_var++;
            print_indentation(ident);
            printf("%%..%d = bitcast i8* %%..%d to i1*\n", index_var, index_var -1);
            index_var++;
            print_indentation(ident);
            printf("%%..%d = insertvalue %%.ArrayBool undef, i32 %s, 0\n", index_var, value1);
            index_var++;
            print_indentation(ident);
            printf("%%..%d = insertvalue %%.ArrayBool %%..%d, i1* %%..%d, 1\n", index_var, index_var -1, index_var -2);
            sprintf(valor_return,"%%..%d",index_var);

            return valor_return;

        }
        else if(arvore->tipo_no == NO_CALL){
            //%retval = call i32 @test(i32 %argc)
            print_indentation(ident);
            AST_TREE* aux;
            char flagzinhafofinha = FALSE;
            call_Struct* params = (call_Struct*)calloc(sizeof(call_Struct),1);
            call_Struct* current = params;
            assert(params!=NULL);

            //PARAMS
            aux = arvore->n1;
            while(aux!=NULL){
                current->next = (call_Struct*)calloc(sizeof(call_Struct),1);
                assert(current->next!=NULL);
                current = current->next;
                current->next = NULL;

                strcpy(current->tok,genCode(aux,tabela));
                current->tipo = aux->type;

                aux = aux->next;

            }


            index_var++;
            printf("%%..%d = call %s @%s(",index_var,llvm_Types[arvore->type],arvore->id->id);
            flagzinhafofinha = FALSE;
            current = params;
            params = params->next;
            free(current);
            while(params!=NULL){

                if(flagzinhafofinha==TRUE)
                    printf(",");
                else
                    flagzinhafofinha = TRUE;

                printf(" %s %s ",llvm_Types[params->tipo],params->tok);
                current = params;
                params = params->next;
                free(current);

            }

            printf(")\n\n");
            sprintf(valor_return,"%%..%d",index_var);
            return valor_return;

        }
        else if(arvore->tipo_no == NO_LENGTH){

            printf(";.LENGTH\n");
            if(arvore->n1->type != TYPE_STRING_ARRAY){
                strcpy(value1,genCode(arvore->n1,tabela));
                index_var++;
                print_indentation(ident);
                printf("%%..%d = extractvalue %s %s, 0\n", index_var,llvm_Types[arvore->n1->type], value1);
                sprintf(valor_return,"%%..%d",index_var);
            }
            else{
               index_var++;
               print_indentation(ident);
               printf("%%..%d = sub i32 %%..argc , 1\n",index_var);
               sprintf(valor_return,"%%..%d",index_var);
            }
            return valor_return;
        }

        else if(arvore->tipo_no == NO_COMPOUNDSTAT){
            ident++;
            genCode(arvore->n1,tabela);
            ident--;
        }
        else if(arvore->tipo_no == NO_PARSEARGS){
            printf(";PARSEARGS\n");
            strcpy(value2,genCode(arvore->n2,tabela));

            //GET ARRAY THEN POINTER AND VALUE
            index_var++;
            print_indentation(ident);
            printf("%%..%d = add i32 1 , %s\n",index_var,value2);
            index_var++;
            print_indentation(ident);
            printf("%%..%d = getelementptr inbounds i8** %%%s, i32 %%..%d\n",index_var,arvore->n1->value,index_var-1);
            index_var++;
            print_indentation(ident);
            printf("%%..%d = load i8** %%..%d\n",index_var,index_var-1);
            index_var++;
            print_indentation(ident);
            printf("%%..%d = call i32 @atoi(i8* %%..%d) nounwind readonly\n",index_var,index_var-1);
            sprintf(valor_return,"%%..%d",index_var);



            return valor_return;
        }
        else if(arvore->tipo_no == NO_IFELSE){
            strcpy(value1,genCode(arvore->n1,tabela));
            int tmp = countreturn;
            countreturn++;
            int temp2;
            //ISPARAM
            index_var++;
            temp2 = index_var;
            print_indentation(ident);
            printf("%%..%d = icmp eq i1 1, %s\n", index_var, value1);
            print_indentation(ident);
            


            printf("br i1 %%..%d, label %%if.do%d, label %%if.else%d\n",index_var,tmp,tmp);
            printf("if.do%d:\n",tmp);
                ident++;
                genCode(arvore->n2,tabela);
                print_indentation(ident);
                printf("br label %%if.end%d\n",tmp);
                ident--;



            printf("if.else%d:\n",tmp);
                ident++;
                genCode(arvore->n3,tabela);
                ident--;
            print_indentation(ident);
            printf("br label %%if.end%d\n",tmp);
            printf("if.end%d:\n",tmp);
        }
        else if(arvore->tipo_no == NO_WHILE){
            int tmp = countreturn;
            countreturn++;
            int temp2;
            printf("br label %%while.do%d\n",tmp);
            printf("while.do%d:\n",tmp);
            strcpy(value1,genCode(arvore->n1,tabela));
            index_var++;
            temp2 = index_var;
            print_indentation(ident);
            printf("%%..%d = icmp eq i1 1, %s\n", index_var, value1);
            print_indentation(ident);
            printf("br i1 %%..%d, label %%while.continue%d, label %%while.end%d\n",index_var,tmp,tmp);
            printf("while.continue%d:\n",tmp);
                ident++;
                genCode(arvore->n2,tabela);
                print_indentation(ident);
                ident--;
            print_indentation(ident);
            printf("br label %%while.do%d\n",tmp);
            printf("while.end%d:\n",tmp);
        }
        else if(arvore->tipo_no == NO_RETURN){
            printf(";RETURN\n");
            if(arvore->n1!=NULL){
                strcpy(value1,genCode(arvore->n1,tabela));
                print_indentation(ident);
                printf("ret %s %s\n",llvm_Types[tipo_funcao],value1);
            }
            else{
                if(tipo_funcao == TYPE_INT)
                    printf("ret i32 0\n");
                else if(tipo_funcao == TYPE_BOOL)
                    printf("ret i1 0\n");
                else if(tipo_funcao == TYPE_VOID)
                    printf("ret void\n");
                else if(tipo_funcao == TYPE_INT_ARRAY)
                    printf("ret %%.ArrayInt {i32 0, i32* null}\n");
                else if(tipo_funcao == TYPE_BOOL_ARRAY)
                    printf("ret %%.ArrayBool {i32 0, i1* null}\n");
            }
        }
        else if(arvore->tipo_no == NO_PRINT){
            printf(";PRINT\n");
            strcpy(value1,genCode(arvore->n1,tabela));
            print_indentation(ident);
            index_var++;
            if(arvore->n1->type == TYPE_BOOL){
                printf("%%..%d = zext i1 %s to i32\n", index_var,value1);
                index_var++;
                print_indentation(ident);
                printf("%%..%d = getelementptr inbounds [2 x i8*]* @.printBool, i32 0, i32 %%..%d\n", index_var, index_var -1);
                index_var++;
                print_indentation(ident);
                printf("%%..%d = load i8** %%..%d\n", index_var, index_var -1);
                print_indentation(ident);
                printf("call i32 (i8*, ...)* @printf(i8* %%..%d)\n\n", index_var);
                index_var++;
            }else
                printf("call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.printInt, i32 0, i32 0), i32 %s)\n\n",value1);
        }
        genCode(arvore->next,tabela);
    }
    return NULL;

}


char checkID_Locallity(char* id,char* methodID,Sym_Table* tabela) {
    char returnFlag = PARAMETRO;
    Sym_Table* table = get_Method_SymTable(tabela, methodID);
    Sym_Node* local;
    local = table->table->next;
    while(local != NULL) {
        if(local->isParam == FALSE)
            returnFlag =  VAR_LOCAL;
        if((local->tipo_no == TABLE_DECL) && strcmp(id,local->id->id) == 0) {
            return returnFlag;
        }
        local = local->next;
    }
    return VAR_GLOBAL;
}

#endif
