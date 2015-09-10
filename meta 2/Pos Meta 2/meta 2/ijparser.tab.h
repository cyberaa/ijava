/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_IJPARSER_TAB_H_INCLUDED
# define YY_YY_IJPARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTLIT = 258,
     BOOLLIT = 259,
     INT = 260,
     BOOL = 261,
     NEW = 262,
     IF = 263,
     ELSE = 264,
     WHILE = 265,
     PRINT = 266,
     PARSEINT = 267,
     CLASS = 268,
     PUBLIC = 269,
     STATIC = 270,
     VOID = 271,
     STRING = 272,
     DOTLENGTH = 273,
     RETURN = 274,
     OCURV = 275,
     CCURV = 276,
     OBRACE = 277,
     CBRACE = 278,
     OSQUARE = 279,
     CSQUARE = 280,
     OP1 = 281,
     OP1OR = 282,
     OP2 = 283,
     OP2EQS = 284,
     OP3 = 285,
     OP4 = 286,
     NOT = 287,
     ASSIGN = 288,
     SEMIC = 289,
     COMMA = 290,
     RESERVED = 291,
     ID = 292,
     IFX = 293
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 35 "ijparser.y"

    char* token; 
    int type; /* Type do tipo inteiro*/
    struct _node* node; /* No da Arvore Sintaxe Abstracta */
    struct _id_List* listId; /* Tipo de Method Type Decl */
    


/* Line 2053 of yacc.c  */
#line 104 "ijparser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_IJPARSER_TAB_H_INCLUDED  */
