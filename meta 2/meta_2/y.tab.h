/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     RESERVED = 258,
     COMMA = 259,
     BOOL = 260,
     INT = 261,
     ID = 262,
     INTLIT = 263,
     IF = 264,
     ELSE = 265,
     WHILE = 266,
     RETURN = 267,
     PRINT = 268,
     BOOLLIT = 269,
     NEW = 270,
     PARSEINT = 271,
     PUBLIC = 272,
     STATIC = 273,
     VOID = 274,
     CLASS = 275,
     OCURV = 276,
     CCURV = 277,
     OBRACE = 278,
     CBRACE = 279,
     OSQUARE = 280,
     CSQUARE = 281,
     AND = 282,
     OR = 283,
     EQUALITY = 284,
     RELATIONAL = 285,
     ADITIVE = 286,
     MULTIPLICATIVE = 287,
     NOT = 288,
     ASSIGN = 289,
     SEMIC = 290,
     STRING = 291,
     DOTLENGTH = 292,
     EXPR1REDUCE = 293,
     UNARY = 294
   };
#endif
/* Tokens.  */
#define RESERVED 258
#define COMMA 259
#define BOOL 260
#define INT 261
#define ID 262
#define INTLIT 263
#define IF 264
#define ELSE 265
#define WHILE 266
#define RETURN 267
#define PRINT 268
#define BOOLLIT 269
#define NEW 270
#define PARSEINT 271
#define PUBLIC 272
#define STATIC 273
#define VOID 274
#define CLASS 275
#define OCURV 276
#define CCURV 277
#define OBRACE 278
#define CBRACE 279
#define OSQUARE 280
#define CSQUARE 281
#define AND 282
#define OR 283
#define EQUALITY 284
#define RELATIONAL 285
#define ADITIVE 286
#define MULTIPLICATIVE 287
#define NOT 288
#define ASSIGN 289
#define SEMIC 290
#define STRING 291
#define DOTLENGTH 292
#define EXPR1REDUCE 293
#define UNARY 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 29 "ijparser.y"
{
	char *token;
	Type type;
	ExprType exprtype;
	struct _class *class;
	Decl_List *decllist;
	VarDecl *vardecl;
	Method_Decl *methoddecl;
	Param_List *paramlist;
	VarDecl_List *vardecllist;
	ID_List *idlist;	
	Stmt_List *stmtlist;
	Stmt *stmt;	
	Expr *expr;
	Args_List *argslist;
}
/* Line 1529 of yacc.c.  */
#line 144 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

