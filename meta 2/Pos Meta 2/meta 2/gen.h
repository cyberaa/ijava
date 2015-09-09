#ifndef _GEN_
#define _GEN_




static const char * llvm_types[] = {"void","i32","i1","i32*","i1*","i8*","Id","i32","i1","i1*",};


typedef struct _calls{
		char tok[100];
		Type tipo;
		struct _calls * next;

}chamada_params;

static const char* OPERATORS_LLVM[] = {
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
                 "mul",
                 "sdiv",
                 "%",
                 "!",
                 "sub",
                 "add",
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
                 "slt",
                 "sgt",
                 "sle",
                 "sge",
                 "ne",
                 "eq",
                 "null",
                 "+",
                 "-"

};




char * genCode(AST_TREE * arvore,Sym_Table * tabela);
#endif
