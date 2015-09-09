#ifndef _GENCODE_
#define _GENCODE_

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "display.h"
#include "gen.h"


#define MAX_LLVM_TYPE_SIZE 15
#define PARAMETRO 1
#define LOCAL 2
#define GLOBAL 3



#define DEBUG 0








char function_body = FALSE;
char flag_alreadyhasparam = FALSE;
int ident = 0;
char * curr_Metodo;
int index_var = 0;
char returnValor[100];



char check_IDLocality(Sym_Table * table,char * id_method,char * id)
{
	char is_returnflag = PARAMETRO;

	Sym_Table * tabela = get_Method_SymTable(table,id_method);
	Sym_Node * islocal; 
	islocal = tabela->table->next;

	while(islocal != NULL)
	{
		if(islocal->isParam == FALSE)
		{
			is_returnflag = LOCAL;
		}
		if((islocal->n_type == TABLE_DECL) && strcmp (id,islocal->id->id) == 0)
		{
			return is_returnflag;
		}
		islocal = islocal->next;
	}
	return GLOBAL;
}






char * genCode(AST_TREE * arvore,Sym_Table * tabela)
{
	ID_List * aux;
	char save1[120];
	char save2[120];
	char save3[120];

	if(arvore != NULL)
	{
		if(arvore->n_type == NO_PROGRAMA)
		{
			printf("declare i32 @printf(i8* noalias nocapture, ...)\n");
            printf("@.printInt = private constant [4 x i8] c\"%%d\\0A\\00\"\n");
            printf("@.true = private constant [6 x i8] c\"true\\0A\\00\"\n");
            printf("@.false = private constant [7 x i8] c\"false\\0A\\00\"\n");
            printf("@.printBool = private constant [2 x i8*] [i8* getelementptr inbounds ([7 x i8]* @.false, i32 0, i32 0),i8* getelementptr inbounds ([6 x i8]* @.true, i32 0, i32 0)]\n\n");
		}
		if(arvore->n_type == NO_METHODDECL)
		{
			curr_Metodo = arvore->id->id;
			index_var = 0;
			function_body = TRUE;
			ident ++;
			/*Check type*/
			if(arvore-> type == TYPE_BOOL){
			    printf("\ndefine %s @%s(",llvm_types[arvore->type],arvore->id->id);
			    genCode(arvore->n1->n1,tabela);
			    printf("){\n");
			    genCode(arvore->n2->n1,tabela);
			    printf("\n");
			    genCode(arvore->n3->n1,tabela);
			    printf("\n");
			    printf("\tret i1 0}\n");

			}
			else{
				if(strcmp(arvore->id->id,"main") == 0)
				{
					printf("\n\ndefine i32 @main(i32 %%argc, i8** %%argv");
				}
				else
				{
					printf("\ndefine %s @%s(",llvm_types[arvore->type],arvore->id->id);
					genCode(arvore->n1->n1,tabela);
				}
				printf("){\n");
				genCode(arvore->n2->n1,tabela);
				printf("\n");
				genCode(arvore->n3->n1,tabela);
				printf("\n");
                printf("\tret i32 0\n}\n");
			}
			ident--;
			function_body = FALSE;

		}
		else if(arvore->n_type == NO_VARDECL){
			if(function_body == FALSE)
			{
				aux = arvore->id;
				while(aux!=NULL){
					if(arvore->type == TYPE_INT || arvore->type == TYPE_BOOL)
						printf("@%s = global %s 0\n",aux->id,llvm_types[arvore->type]);
					else
						printf("@%s = global %s null\n",aux->id,llvm_types[arvore->type]);

					aux = aux->next;
				}
			}
			else{
				print_indentation(ident);
				printf("%%%s = alloca %s\n",arvore->id->id,llvm_types[arvore->type]);

			}
		}
		else if(arvore->n_type == NO_PARAMDECL)
		{
		    if(flag_alreadyhasparam == TRUE){
		    	printf(",");

		    }
		    flag_alreadyhasparam = TRUE;
		    printf("%s %%%s",llvm_types[arvore->type],arvore->id->id);

		}
		else if(arvore->n_type == NO_PLUS|| arvore->n_type == NO_MINUS || arvore->n_type == NO_MUL || arvore->n_type == NO_DIV)
		{
			strcpy(save1,genCode(arvore->n1,tabela));
			strcpy(save2,genCode(arvore->n2,tabela));
			print_indentation(ident);
			index_var ++;
			//result = ty <op1>, <op2>
			printf("%%%d = %s %s %s , %s\n\n",index_var,OPERATORS_LLVM[arvore->n_type],llvm_types[arvore->type],save1,save2);   
			sprintf(returnValor,"%%%d",index_var);
			return returnValor;
		}
		else if(arvore->n_type == NO_INTLIT)
		{
			//is_DEC?
			if(*(arvore->value)!='0')
			{
				sprintf(returnValor,"%d",atoi(arvore->value));
				return returnValor;
			}
			//is_HEX?
			int lengths = strlen(arvore->value);
			if(lengths>0 && *(arvore->value+1) =='x' )
			{
				sprintf(returnValor,"%ld",strtol((arvore->value+2),NULL,16));
				return returnValor;
			}
			sprintf(returnValor,"%ld",strtol(arvore->value,NULL,8));
			return returnValor;

		}
		else if(arvore->n_type == NO_BOOLLIT)
		{
			if(strcmp(arvore->value,"true")==0)
			{
				 sprintf(returnValor,"%d",1);
			}
			else
			{
				sprintf(returnValor,"%d",0);
			}
			return returnValor;
		}
		else if(arvore->n_type == NO_ID)
		{
			//print ident equal to ouput provided
			print_indentation(ident);
			char IDLocal = check_IDLocality(tabela,curr_Metodo,arvore->value);
			if(IDLocal == LOCAL)
			{
				index_var++;
				printf("%%%d = load %s* %%%s\n",index_var,llvm_types[arvore->type],arvore->value);

			}
			else if(IDLocal == PARAMETRO)
			{
				sprintf(returnValor,"%%%s",arvore->value);
				return returnValor;
			}
			else
			{
				index_var++;
				printf("%%%d = load %s* @%s\n",index_var,llvm_types[arvore->type],arvore->value);

			}
			sprintf(returnValor,"%%%d",index_var);
			return returnValor;
		}
		else if(arvore->n_type == NO_LOADARRAY)
		{
			printf(";LOADARRAY\n");
			strcpy(save1,genCode(arvore->n1,tabela));
			strcpy(save2,genCode(arvore->n2,tabela));
			//CASE : SIZE OF ARRAY
			index_var++;
			print_indentation(ident);
			printf("%%%d = add i32 1, %s\n",index_var,save2);
		    sprintf(save2,"%%%d",index_var);
		    //CASE: GET POINTER
		    index_var++;
		    print_indentation(ident);
            printf("%%%d = getelementptr inbounds %s %s, i32 %s\n",index_var,llvm_types[arvore->n1->type],save1,save2);
            sprintf(save2,"%%%d",index_var);
            //CASE: EXTRACT VALUE
            index_var++;
            print_indentation(ident);
            printf("%%%d = load %s* %s\n",index_var,llvm_types[arvore->type],save2);
            sprintf(returnValor,"%%%d",index_var);
            return returnValor;



		}
		else if(arvore->n_type == NO_STORE)
		{
			//store i32 3, i32* %ptr
			printf(";STORE\n");
			strcpy(save1,genCode(arvore->n3,tabela));
			print_indentation(ident);
			if(check_IDLocality(tabela,curr_Metodo,arvore->n1->value)!=GLOBAL)
			{
                printf("store %s %s, %s* %%%s\n\n",llvm_types[arvore->n1->type],save1,llvm_types[arvore->n1->type],arvore->n1->value);
			}
			else
			{
                printf("store %s %s, %s* @%s\n\n",llvm_types[arvore->n1->type],save1,llvm_types[arvore->n1->type],arvore->n1->value);
			}

		}
		else if(arvore->n_type == NO_STOREARRAY)
		{
			printf(";STOREARRAY\n");
            strcpy(save1,genCode(arvore->n1,tabela));
            strcpy(save2,genCode(arvore->n2,tabela));
            strcpy(save3,genCode(arvore->n3,tabela));
          	//CASE : GET SIZE OF ARRAY
          	index_var++;
          	print_indentation(ident);
          	printf("%%%d = add i32 1, %s\n",index_var,save2);
            sprintf(save2,"%%%d",index_var);
           	//CASE: GET POINTER
          	index_var++;
          	print_indentation(ident);
            printf("%%%d = getelementptr inbounds %s %s, i32 %s\n",index_var,llvm_types[arvore->n1->type],save1,save2);
            sprintf(save2,"%%%d",index_var);
          	print_indentation(ident);
            printf("store %s %s, %s %s\n\n",llvm_types[arvore->n3->type],save3,llvm_types[arvore->type],save2);

		}
		else if(arvore->n_type == NO_NEWINT || arvore->n_type == NO_NEWBOOL)
		{
			printf(";NEWINT\n");
		    strcpy(save1,genCode(arvore->n1,tabela));
		    print_indentation(ident);
		    index_var++;
		    printf("%%%d = add i32 1, %s\n",index_var,save1);
		    sprintf(save1,"%%%d",index_var);
		    print_indentation(ident);
		    index_var++;
		    if(arvore->type==TYPE_BOOL_ARRAY)
		    {
		    	printf("%%%d = alloca i1, %s %s \n",index_var,llvm_types[arvore->n1->type],save1);
		    }
		    else
		    	printf("%%%d = alloca i32, %s %s \n",index_var,llvm_types[arvore->n1->type],save1);
            sprintf(returnValor,"%%%d",index_var);
            return returnValor;
		}
		else if(arvore->n_type == NO_PRINT)
		{
		    printf(";PRINT\n");
		    strcpy(save1,genCode(arvore->n1,tabela));
		   	print_indentation(ident);
		   	index_var++;
		   	if(arvore->n1->type == TYPE_BOOL)
		   	{
		   		//
		   		printf("%%%d = zext i1 %s to i32\n", index_var,save1);
		   		index_var++;
		   		print_indentation(ident);
		   		printf("%%%d = getelementptr inbounds [2 x i8*]* @.printBool, i32 0, i32 %%%d\n", index_var, index_var -1);
		   		index_var++;
		   		//
		   		print_indentation(ident);
		   	    printf("%%%d = load i8** %%%d\n", index_var, index_var -1);
		   		print_indentation(ident);
                printf("call i32 (i8*, ...)* @printf(i8* %%%d)\n\n", index_var);
		   		index_var++;



		   	}
		   	else
		   	{
		   		printf("call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.printInt, i32 0, i32 0), i32 %s)\n\n",save1);
		   	}

		}
		else if(arvore->n_type == NO_NOT)
		{
			strcpy(save1,genCode(arvore->n1,tabela));
			print_indentation(ident);
			index_var++;
			printf("%%%d = sub i1 1, %s\n",index_var,save1);
            sprintf(returnValor,"%%%d",index_var);
            return returnValor;

		}
		else if(arvore->n_type == NO_UNARYMINUS)
		{
			strcpy(save1,genCode(arvore->n1,tabela));
		    print_indentation(ident);
		    index_var++;
		    printf("%%%d = mul %s -1 , %s\n",index_var,llvm_types[arvore->type],save1);
		    sprintf(returnValor,"%%%d",index_var);
		    return returnValor;
		}
		else if(arvore->n_type == NO_GREATER || arvore->n_type == NO_LESS || arvore->n_type == NO_GREATEREQUAL || arvore->n_type == NO_LESSEQUAL || arvore->n_type == NO_EQUAL || arvore->n_type == NO_DIFFERENT)
		{
			strcpy(save1,genCode(arvore->n1,tabela));
			strcpy(save2,genCode(arvore->n2,tabela));
			print_indentation(ident);
			index_var++;
			printf("%%%d = icmp %s i32 %s, %s\n",index_var,OPERATORS_LLVM[arvore->n_type],save1,save2);
			sprintf(returnValor,"%%%d",index_var);
			return returnValor;
		}
		else if(arvore->n_type == NO_CALL)
		{
			print_indentation(ident);
			AST_TREE * no;

			chamada_params * parametros = (chamada_params*)malloc(sizeof(chamada_params));
			chamada_params * curr = parametros;

			assert(parametros!=NULL);



			no = arvore->n1;
			while(no !=NULL)
			{
				curr->next = (chamada_params*)malloc(sizeof(chamada_params));

				assert(curr->next != NULL);
				curr = curr-> next;
				curr ->next = NULL;
				strcpy(curr->tok,genCode(no,tabela));
				curr->tipo = no->type;
				no = no->next;

			}
			index_var++;
			printf("%%%d = call %s @%s(",index_var,llvm_types[arvore->type],arvore->id->id);
			char flag = FALSE;
			parametros = parametros->next;
			while(parametros != NULL)
			{
				if(flag == TRUE)
				    printf(",");
				else
					flag = TRUE;

				printf(" %s %s ",llvm_types[parametros->tipo],parametros->tok);
				curr = parametros;
				parametros = parametros->next;
				free(curr);
			}
			printf(")\n\n");
			sprintf(returnValor,"%%%d",index_var);
			return returnValor;


		}
		genCode(arvore->next,tabela);

	}
	return NULL;


}

#endif
