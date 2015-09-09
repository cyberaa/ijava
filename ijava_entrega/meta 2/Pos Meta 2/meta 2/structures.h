#ifndef _STRUCTURE_
#define _STRUCTURE_


#define DEBUG 0
#define TRUE 1
#define FALSE 0

typedef enum {TYPE_VOID, TYPE_INT, TYPE_BOOL, TYPE_INT_ARRAY, TYPE_BOOL_ARRAY, TYPE_STRING_ARRAY} Type;

typedef enum {TABLE_CLASS, TABLE_METHOD, TABLE_DECL, TABLE_RETURN} TableType;


typedef enum {NO_PROGRAMA, NO_VARDECL, NO_METHODDECL, NO_METHODPARAMS, NO_METHODBODY, NO_PARAMDECL,
              NO_COMPOUNDSTAT, NO_IFELSE, NO_PRINT, NO_RETURN, NO_STORE, NO_MUL, NO_DIV,
              NO_MOD, NO_NOT, NO_MINUS, NO_PLUS, NO_LENGTH, NO_LOADARRAY, NO_CALL,
              NO_NEWINT, NO_NEWBOOL, NO_PARSEARGS, NO_WHILE, NO_STOREARRAY,
              NO_INTLIT, NO_BOOLLIT, NO_ID, NO_AND, NO_OR,
              NO_LESS, NO_GREATER, NO_LESSEQUAL, NO_GREATEREQUAL,
              NO_DIFFERENT,NO_EQUAL,
              NO_NULL,
              NO_UNARYPLUS,NO_UNARYMINUS,
              NODE_DONTPRINT
              } NodeType;


//ID Nodes or Multiple IDS
typedef struct _id_List
{
	char* id;
	struct _id_List* next;
} ID_List;


typedef struct _node
{
    //Struct Type
    Type type;
    char* value;
    char isStatic;
    ID_List* id;
    NodeType n_type;

    struct _node* n1;
    struct _node* n2;
    struct _node* n3;

    struct _node* next;
}AST_TREE;


typedef struct _TabelaNode
{
    char isParam;
    Type type;
    ID_List* id;
    TableType n_type;
    struct _TabelaNode* next;
    
}Sym_Node;

typedef struct _TabelaSYM{
    Sym_Node* table;
    struct _TabelaSYM* next;
}Sym_Table;






/*Create AST Tree*/
AST_TREE* create_Root_node();



/*ADD Different Node Types*/
AST_TREE* add_Class_to_List(char* id, AST_TREE* statements);
ID_List* add_ID_to_List(AST_TREE* currentNode, char* id);
ID_List* add_VarID_to_ID_LIST(char* id, ID_List* next);
AST_TREE* add_VarDecl(int type, char* id, ID_List* multi_IDs, AST_TREE* next);
AST_TREE* add_ParamDecl(int type, char* id, ID_List* multi_IDs, AST_TREE* next);
AST_TREE* add_Method(int type, char* id, AST_TREE* params, AST_TREE* varDecl, AST_TREE* statements);
AST_TREE* add_Compound_Stmnt(AST_TREE* Expr);
AST_TREE* add_Expr(char* op,AST_TREE* exp);
AST_TREE* add_two_Expr(AST_TREE* exp1,char* op,AST_TREE* exp2);
AST_TREE* add_Terminal_Node(int n_type, char* token);

AST_TREE* add_While(AST_TREE* Expr, AST_TREE* statements);
AST_TREE* add_IF(AST_TREE* Expr, AST_TREE* statement1, AST_TREE* statement2);
AST_TREE* add_Print(AST_TREE* Expr);
AST_TREE* add_Return(AST_TREE* Expr);
AST_TREE* add_Store(char* id, AST_TREE* arrayIndex, AST_TREE* Expr);
AST_TREE* add_DotLength(AST_TREE* Expr);
AST_TREE* add_LoadArray(AST_TREE* Expr, AST_TREE* indx_Expr);
AST_TREE* add_ParseInt(char* id, AST_TREE* indx_Expr);
AST_TREE* add_NewArray(int type, AST_TREE* Expr);
AST_TREE* add_Call(char* id, AST_TREE *args);




Sym_Table* create_SymTable(AST_TREE* ast);
Sym_Node* add_NewDecl_Table_to_Old(char isparam, Sym_Node* symbol, AST_TREE* ast,Sym_Table* table);


/*AUX*/
NodeType getOPType(char* op);


/*Semantic and Sintatic Errors Functions */
void check_Semantic_Errors(AST_TREE* ast, Sym_Table* local, Sym_Table* main);
void check_Errors(AST_TREE* ast, Sym_Table* symbols, Sym_Table* main);
void check_INTLIT(char* lit);
void OP_Error_Type(int op,int n1);
void OP_Error_two_Types(int op,int n1, int n2);
void assignm_Array_Error(char* var, int n1, int n2);
void assign_Error(char* var, int n1, int n2);
void getErrorCall(int i,char* name, int n1, int n2);
void statmnt_Error(int op, int n1,int n2);
void statemnt_Error_3vars(int op, int n1, int n2, int n3);

/*Check Node */
void check_Sym_Exists(char* id, Sym_Table* local);
void check_Types(AST_TREE* ast,Sym_Table* main);
int check_Sym_ID_Exists(char* id,TableType type, Sym_Table* table, Sym_Table* main);

/*Gets and Sets*/
int get_Function_Types();
char* get_Function_ID();
Sym_Table* get_Method_SymTable(Sym_Table* main, char* methodID);
void setTable(Sym_Table * table);
AST_TREE* set_next_Node(AST_TREE* current, AST_TREE* next);
AST_TREE* setStatic(AST_TREE* currentNode);



#endif




