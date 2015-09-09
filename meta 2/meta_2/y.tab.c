/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "ijparser.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"
#include "display.h"

/*Get lexer vars*/
extern int prevLineNo;
extern int prevColNo;
extern int yyleng;
extern char *yytext;


/*errors*/
int yydebug=0;
int erros = 0;

void yyerror(char *s);
int yylex(void);

/*AST Struct*/
Class *myprogram;
/*SYM Struct*/
Sym_Table* Tabela_sym = NULL;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 219 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 232 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   275

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    10,    16,    18,    20,    23,    26,
      29,    41,    43,    45,    49,    54,    55,    60,    61,    63,
      65,    69,    73,    76,    77,    82,    86,    87,    91,    99,
     105,   111,   117,   122,   130,   133,   137,   140,   141,   143,
     145,   150,   154,   158,   162,   166,   170,   174,   177,   180,
     182,   184,   186,   191,   195,   199,   202,   210,   216,   222,
     224,   227
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    20,     7,    23,    24,    -1,
      20,     7,    23,    43,    24,    -1,    44,    -1,    45,    -1,
      43,    44,    -1,    43,    45,    -1,    18,    51,    -1,    17,
      18,    46,     7,    21,    47,    22,    23,    50,    54,    24,
      -1,    49,    -1,    19,    -1,    49,     7,    48,    -1,    36,
      25,    26,     7,    -1,    -1,    48,     4,    49,     7,    -1,
      -1,     6,    -1,     5,    -1,     6,    25,    26,    -1,     5,
      25,    26,    -1,    50,    51,    -1,    -1,    49,     7,    52,
      35,    -1,    52,     4,     7,    -1,    -1,    23,    54,    24,
      -1,     9,    21,    55,    22,    53,    10,    53,    -1,     9,
      21,    55,    22,    53,    -1,    11,    21,    55,    22,    53,
      -1,    13,    21,    55,    22,    35,    -1,     7,    34,    55,
      35,    -1,     7,    25,    55,    26,    34,    55,    35,    -1,
      12,    35,    -1,    12,    55,    35,    -1,    54,    53,    -1,
      -1,    57,    -1,    56,    -1,    56,    25,    55,    26,    -1,
      55,    27,    55,    -1,    55,    28,    55,    -1,    55,    29,
      55,    -1,    55,    30,    55,    -1,    55,    31,    55,    -1,
      55,    32,    55,    -1,    33,    55,    -1,    31,    55,    -1,
       7,    -1,     8,    -1,    14,    -1,     7,    21,    58,    22,
      -1,     7,    21,    22,    -1,    21,    55,    22,    -1,    55,
      37,    -1,    16,    21,     7,    25,    55,    26,    22,    -1,
      15,     6,    25,    55,    26,    -1,    15,     5,    25,    55,
      26,    -1,    55,    -1,    55,    59,    -1,     4,    58,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    80,    80,    84,    85,    90,    91,    92,    93,    97,
     101,   105,   106,   110,   111,   112,   116,   117,   121,   122,
     123,   124,   128,   129,   133,   137,   138,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   154,   155,   159,   160,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   186,   187,   191,
     192,   197
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RESERVED", "COMMA", "BOOL", "INT", "ID",
  "INTLIT", "IF", "ELSE", "WHILE", "RETURN", "PRINT", "BOOLLIT", "NEW",
  "PARSEINT", "PUBLIC", "STATIC", "VOID", "CLASS", "OCURV", "CCURV",
  "OBRACE", "CBRACE", "OSQUARE", "CSQUARE", "AND", "OR", "EQUALITY",
  "RELATIONAL", "ADITIVE", "MULTIPLICATIVE", "NOT", "ASSIGN", "SEMIC",
  "STRING", "DOTLENGTH", "EXPR1REDUCE", "UNARY", "$accept", "grammar",
  "programa", "programa_decomp", "fielddecl", "methoddecl", "type_void",
  "formalparams", "comma_type_id_decomp", "type", "vardecl_decomp",
  "vardecl", "comma_id_decomp", "statement", "statement_decomp", "expr",
  "exprlisted", "exprnotlisted", "args", "argslist", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    44,
      45,    46,    46,    47,    47,    47,    48,    48,    49,    49,
      49,    49,    50,    50,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    58,
      58,    59
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     5,     1,     1,     2,     2,     2,
      11,     1,     1,     3,     4,     0,     4,     0,     1,     1,
       3,     3,     2,     0,     4,     3,     0,     3,     7,     5,
       5,     5,     4,     7,     2,     3,     2,     0,     1,     1,
       4,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       1,     1,     4,     3,     3,     2,     7,     5,     5,     1,
       2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     3,
       0,     5,     6,     0,    19,    18,     0,     9,     4,     7,
       8,    12,     0,    11,     0,     0,    26,     0,    21,    20,
       0,    15,     0,    24,     0,     0,     0,    25,     0,     0,
      17,     0,    23,    13,    14,    37,     0,    22,     0,     0,
       0,     0,     0,     0,     0,    37,    10,    36,    16,     0,
       0,     0,     0,    49,    50,    51,     0,     0,     0,     0,
       0,    34,     0,    39,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    47,     0,     0,
       0,     0,     0,     0,    35,    55,     0,     0,    27,     0,
      32,     0,     0,    53,    59,     0,     0,     0,     0,    54,
      41,    42,    43,    44,    45,    46,     0,     0,     0,    29,
      30,     0,    60,    52,     0,     0,     0,    40,    31,     0,
       0,    61,    58,    57,     0,    33,    28,     0,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    10,    11,    12,    22,    35,    43,    16,
      45,    17,    30,    57,    48,   104,    73,    74,   105,   122
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -99
static const yytype_int16 yypact[] =
{
       1,    16,    31,   -99,    19,   -99,    51,    26,    14,   -99,
      94,   -99,   -99,    45,    38,    42,    73,   -99,   -99,   -99,
     -99,   -99,    76,   -99,    89,    91,   -99,    79,   -99,   -99,
      -2,     5,   109,   -99,    98,   107,   112,   -99,   111,   116,
     -99,   141,   -99,   145,   -99,    14,    14,   -99,    90,   143,
     -20,   138,   139,    41,   140,   -99,   -99,   -99,   -99,    74,
      74,    74,    74,   149,   -99,   -99,    81,   150,    74,    74,
      74,   -99,   207,   144,   -99,    74,    97,   148,   218,   103,
     114,    63,   147,   156,   175,   125,   146,   146,    74,    74,
      74,    74,    74,    74,   -99,   -99,    74,   136,   -99,   159,
     -99,   115,   115,   -99,    -3,   162,    74,    74,   169,   -99,
      29,   238,    61,    15,   -19,   146,   160,   161,    74,   185,
     -99,    74,   -99,   -99,   172,   184,    74,   -99,   -99,   229,
     115,   -99,   -99,   -99,   196,   -99,   -99,   183,   -99
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -99,   -99,   197,   198,   -99,   -99,   -99,    -1,
     -99,   173,   -99,   -98,   151,   -53,   -99,   -99,    96,   -99
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      72,   121,    32,   119,   120,    59,    77,    78,    79,    80,
      14,    15,    23,    93,    60,    85,    86,    87,    95,    14,
      15,     1,    97,     4,    88,    89,    90,    91,    92,    93,
      36,     5,   136,    33,    95,   110,   111,   112,   113,   114,
     115,    34,     6,   116,    13,    49,    92,    93,    63,    64,
      14,    15,    95,   124,   125,    65,    66,    67,    90,    91,
      92,    93,    68,    24,    21,   129,    95,    25,     7,     8,
      63,    64,    69,   134,    70,     9,    71,    65,    66,    67,
      26,    63,    64,    27,    68,   103,    82,    83,    65,    66,
      67,    91,    92,    93,    69,    68,    70,    50,    95,    51,
      31,    52,    53,    54,    50,    69,    51,    70,    52,    53,
      54,     7,     8,    55,    56,    28,    37,    29,    18,    40,
      55,    98,    50,    38,    51,   101,    52,    53,    54,    39,
      88,    89,    90,    91,    92,    93,   102,    41,    55,    42,
      95,    88,    89,    90,    91,    92,    93,   109,    44,    46,
      58,    95,    88,    89,    90,    91,    92,    93,   117,    61,
      62,    75,    95,    88,    89,    90,    91,    92,    93,    96,
      81,    84,   106,    95,    99,    88,    89,    90,    91,    92,
      93,   107,   108,    95,   123,    95,   127,    88,    89,    90,
      91,    92,    93,   118,   126,   130,   128,    95,   132,    88,
      89,    90,    91,    92,    93,   138,    76,    19,    20,    95,
     133,    88,    89,    90,    91,    92,    93,   131,    47,     0,
       0,    95,   137,    88,    89,    90,    91,    92,    93,     0,
       0,     0,     0,    95,    88,    89,    90,    91,    92,    93,
       0,     0,    94,     0,    95,    88,    89,    90,    91,    92,
      93,     0,     0,   100,     0,    95,    88,    89,    90,    91,
      92,    93,     0,     0,   135,    88,    95,    90,    91,    92,
      93,     0,     0,     0,     0,    95
};

static const yytype_int16 yycheck[] =
{
      53,     4,     4,   101,   102,    25,    59,    60,    61,    62,
       5,     6,    13,    32,    34,    68,    69,    70,    37,     5,
       6,    20,    75,     7,    27,    28,    29,    30,    31,    32,
      31,     0,   130,    35,    37,    88,    89,    90,    91,    92,
      93,    36,    23,    96,    18,    46,    31,    32,     7,     8,
       5,     6,    37,   106,   107,    14,    15,    16,    29,    30,
      31,    32,    21,    25,    19,   118,    37,    25,    17,    18,
       7,     8,    31,   126,    33,    24,    35,    14,    15,    16,
       7,     7,     8,     7,    21,    22,     5,     6,    14,    15,
      16,    30,    31,    32,    31,    21,    33,     7,    37,     9,
      21,    11,    12,    13,     7,    31,     9,    33,    11,    12,
      13,    17,    18,    23,    24,    26,     7,    26,    24,     7,
      23,    24,     7,    25,     9,    22,    11,    12,    13,    22,
      27,    28,    29,    30,    31,    32,    22,    26,    23,    23,
      37,    27,    28,    29,    30,    31,    32,    22,     7,     4,
       7,    37,    27,    28,    29,    30,    31,    32,    22,    21,
      21,    21,    37,    27,    28,    29,    30,    31,    32,    25,
      21,    21,    25,    37,    26,    27,    28,    29,    30,    31,
      32,    25,     7,    37,    22,    37,    26,    27,    28,    29,
      30,    31,    32,    34,    25,    10,    35,    37,    26,    27,
      28,    29,    30,    31,    32,    22,    55,    10,    10,    37,
      26,    27,    28,    29,    30,    31,    32,   121,    45,    -1,
      -1,    37,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    37,    27,    28,    29,    30,    31,    32,
      -1,    -1,    35,    -1,    37,    27,    28,    29,    30,    31,
      32,    -1,    -1,    35,    -1,    37,    27,    28,    29,    30,
      31,    32,    -1,    -1,    35,    27,    37,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    41,    42,     7,     0,    23,    17,    18,    24,
      43,    44,    45,    18,     5,     6,    49,    51,    24,    44,
      45,    19,    46,    49,    25,    25,     7,     7,    26,    26,
      52,    21,     4,    35,    36,    47,    49,     7,    25,    22,
       7,    26,    23,    48,     7,    50,     4,    51,    54,    49,
       7,     9,    11,    12,    13,    23,    24,    53,     7,    25,
      34,    21,    21,     7,     8,    14,    15,    16,    21,    31,
      33,    35,    55,    56,    57,    21,    54,    55,    55,    55,
      55,    21,     5,     6,    21,    55,    55,    55,    27,    28,
      29,    30,    31,    32,    35,    37,    25,    55,    24,    26,
      35,    22,    22,    22,    55,    58,    25,    25,     7,    22,
      55,    55,    55,    55,    55,    55,    55,    22,    34,    53,
      53,     4,    59,    22,    55,    55,    25,    26,    35,    55,
      10,    58,    26,    26,    55,    35,    53,    26,    22
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 84 "ijparser.y"
    {(yyval.class) = create_rootClass((yyvsp[(2) - (4)].token), NULL); myprogram = (yyval.class);}
    break;

  case 4:
#line 85 "ijparser.y"
    {(yyval.class) = create_rootClass((yyvsp[(2) - (5)].token), (yyvsp[(4) - (5)].decllist)); myprogram = (yyval.class);}
    break;

  case 5:
#line 90 "ijparser.y"
    {(yyval.decllist)=add_Decl(VARDECL, (yyvsp[(1) - (1)].vardecl), NULL);}
    break;

  case 6:
#line 91 "ijparser.y"
    {(yyval.decllist)=add_Decl(METHODDECL, (yyvsp[(1) - (1)].methoddecl), NULL);}
    break;

  case 7:
#line 92 "ijparser.y"
    {(yyval.decllist)=add_Decl(VARDECL, (yyvsp[(2) - (2)].vardecl), (yyvsp[(1) - (2)].decllist));}
    break;

  case 8:
#line 93 "ijparser.y"
    {(yyval.decllist)=add_Decl(METHODDECL, (yyvsp[(2) - (2)].methoddecl), (yyvsp[(1) - (2)].decllist));}
    break;

  case 9:
#line 97 "ijparser.y"
    {(yyval.vardecl) = change_to_static((yyvsp[(2) - (2)].vardecl),1);}
    break;

  case 10:
#line 101 "ijparser.y"
    {(yyval.methoddecl) = add_MethodDecl((yyvsp[(3) - (11)].type), (yyvsp[(4) - (11)].token), (yyvsp[(6) - (11)].paramlist), (yyvsp[(9) - (11)].vardecllist), (yyvsp[(10) - (11)].stmtlist));}
    break;

  case 11:
#line 105 "ijparser.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 12:
#line 106 "ijparser.y"
    {(yyval.type) = VOID_T;}
    break;

  case 13:
#line 110 "ijparser.y"
    {(yyval.paramlist) = add_FormalParam((yyvsp[(1) - (3)].type), (yyvsp[(2) - (3)].token), (yyvsp[(3) - (3)].paramlist), 1);}
    break;

  case 14:
#line 111 "ijparser.y"
    {(yyval.paramlist) = add_FormalParam(STRINGARRAY, (yyvsp[(4) - (4)].token), NULL, 1);}
    break;

  case 15:
#line 112 "ijparser.y"
    {(yyval.paramlist) = NULL;}
    break;

  case 16:
#line 116 "ijparser.y"
    {(yyval.paramlist) = add_FormalParam((yyvsp[(3) - (4)].type), (yyvsp[(4) - (4)].token), (yyvsp[(1) - (4)].paramlist), 0);}
    break;

  case 17:
#line 117 "ijparser.y"
    {(yyval.paramlist) = NULL;}
    break;

  case 18:
#line 121 "ijparser.y"
    {(yyval.type) = INT_T;}
    break;

  case 19:
#line 122 "ijparser.y"
    {(yyval.type) = BOOL_T;}
    break;

  case 20:
#line 123 "ijparser.y"
    {(yyval.type) = INTARRAY;}
    break;

  case 21:
#line 124 "ijparser.y"
    {(yyval.type) = BOOLARRAY;}
    break;

  case 22:
#line 128 "ijparser.y"
    {(yyval.vardecllist) = add_VarDecl_List((yyvsp[(2) - (2)].vardecl), (yyvsp[(1) - (2)].vardecllist));}
    break;

  case 23:
#line 129 "ijparser.y"
    {(yyval.vardecllist) = NULL;}
    break;

  case 24:
#line 133 "ijparser.y"
    {(yyval.vardecl) = add_VarDecl((yyvsp[(1) - (4)].type), (yyvsp[(2) - (4)].token), (yyvsp[(3) - (4)].idlist), 0);}
    break;

  case 25:
#line 137 "ijparser.y"
    {(yyval.idlist) = add_ID_List((yyvsp[(3) - (3)].token), (yyvsp[(1) - (3)].idlist));}
    break;

  case 26:
#line 138 "ijparser.y"
    {(yyval.idlist) = NULL;}
    break;

  case 27:
#line 142 "ijparser.y"
    {(yyval.stmt)=add_Statement(CSTAT,NULL,(yyvsp[(2) - (3)].stmtlist),NULL,NULL,NULL,NULL);}
    break;

  case 28:
#line 143 "ijparser.y"
    {(yyval.stmt)=add_Statement(IFELSE,NULL,NULL,(yyvsp[(3) - (7)].expr),NULL,(yyvsp[(5) - (7)].stmt),(yyvsp[(7) - (7)].stmt));}
    break;

  case 29:
#line 144 "ijparser.y"
    {(yyval.stmt)=add_Statement(IFELSE,NULL,NULL,(yyvsp[(3) - (5)].expr),NULL,(yyvsp[(5) - (5)].stmt),NULL);}
    break;

  case 30:
#line 145 "ijparser.y"
    {(yyval.stmt)=add_Statement(WHILE_T,NULL,NULL,(yyvsp[(3) - (5)].expr),NULL,(yyvsp[(5) - (5)].stmt),NULL);}
    break;

  case 31:
#line 146 "ijparser.y"
    {(yyval.stmt)=add_Statement(PRINT_T,NULL,NULL,(yyvsp[(3) - (5)].expr),NULL,NULL,NULL);}
    break;

  case 32:
#line 147 "ijparser.y"
    {(yyval.stmt)=add_Statement(STORE,(yyvsp[(1) - (4)].token),NULL,(yyvsp[(3) - (4)].expr),NULL,NULL,NULL);}
    break;

  case 33:
#line 148 "ijparser.y"
    {(yyval.stmt)=add_Statement(STOREARRAY,(yyvsp[(1) - (7)].token),NULL,(yyvsp[(3) - (7)].expr),(yyvsp[(6) - (7)].expr),NULL,NULL);}
    break;

  case 34:
#line 149 "ijparser.y"
    {(yyval.stmt)=add_Statement(RETURN_T,NULL,NULL,NULL,NULL,NULL,NULL);}
    break;

  case 35:
#line 150 "ijparser.y"
    {(yyval.stmt)=add_Statement(RETURN_T,NULL,NULL,(yyvsp[(2) - (3)].expr),NULL,NULL,NULL);}
    break;

  case 36:
#line 154 "ijparser.y"
    {(yyval.stmtlist) = add_Statement_List((yyvsp[(2) - (2)].stmt),(yyvsp[(1) - (2)].stmtlist));}
    break;

  case 37:
#line 155 "ijparser.y"
    {(yyval.stmtlist) = NULL;}
    break;

  case 38:
#line 159 "ijparser.y"
    {(yyval.expr)=(yyvsp[(1) - (1)].expr);}
    break;

  case 39:
#line 160 "ijparser.y"
    {(yyval.expr)=(yyvsp[(1) - (1)].expr);}
    break;

  case 40:
#line 165 "ijparser.y"
    {(yyval.expr)=add_Expression(INDEX,NULL, NULL,(yyvsp[(1) - (4)].expr),(yyvsp[(3) - (4)].expr),NULL);}
    break;

  case 41:
#line 166 "ijparser.y"
    {(yyval.expr)=add_Expression(BINOP, NULL,(yyvsp[(2) - (3)].token),(yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),NULL);}
    break;

  case 42:
#line 167 "ijparser.y"
    {(yyval.expr)=add_Expression(BINOP, NULL,(yyvsp[(2) - (3)].token),(yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),NULL);}
    break;

  case 43:
#line 168 "ijparser.y"
    {(yyval.expr)=add_Expression(BINOP, NULL,(yyvsp[(2) - (3)].token),(yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),NULL);}
    break;

  case 44:
#line 169 "ijparser.y"
    {(yyval.expr)=add_Expression(BINOP, NULL,(yyvsp[(2) - (3)].token),(yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),NULL);}
    break;

  case 45:
#line 170 "ijparser.y"
    {(yyval.expr)=add_Expression(BINOP, NULL,(yyvsp[(2) - (3)].token),(yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),NULL);}
    break;

  case 46:
#line 171 "ijparser.y"
    {(yyval.expr)=add_Expression(BINOP, NULL,(yyvsp[(2) - (3)].token),(yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),NULL);}
    break;

  case 47:
#line 172 "ijparser.y"
    {(yyval.expr)=add_Expression(UNOP, NULL,(yyvsp[(1) - (2)].token),(yyvsp[(2) - (2)].expr),NULL,NULL);}
    break;

  case 48:
#line 173 "ijparser.y"
    {(yyval.expr)=add_Expression(UNOP, NULL,(yyvsp[(1) - (2)].token),(yyvsp[(2) - (2)].expr),NULL,NULL);}
    break;

  case 49:
#line 174 "ijparser.y"
    {(yyval.expr)=add_Expression(ID_T, (yyvsp[(1) - (1)].token), NULL,NULL,NULL,NULL);}
    break;

  case 50:
#line 175 "ijparser.y"
    {(yyval.expr)=add_Expression(INTLIT_T, (yyvsp[(1) - (1)].token), NULL,NULL,NULL,NULL);}
    break;

  case 51:
#line 176 "ijparser.y"
    {(yyval.expr)=add_Expression(BOOLLIT_T, (yyvsp[(1) - (1)].token), NULL,NULL,NULL,NULL);}
    break;

  case 52:
#line 177 "ijparser.y"
    {(yyval.expr)=add_Expression(CALL, (yyvsp[(1) - (4)].token),NULL,NULL,NULL,(yyvsp[(3) - (4)].argslist));}
    break;

  case 53:
#line 178 "ijparser.y"
    {(yyval.expr)=add_Expression(CALL, (yyvsp[(1) - (3)].token),NULL,NULL,NULL,NULL);}
    break;

  case 54:
#line 179 "ijparser.y"
    {(yyval.expr)=(yyvsp[(2) - (3)].expr);}
    break;

  case 55:
#line 180 "ijparser.y"
    {(yyval.expr)=add_Expression(UNOP, NULL,".length",(yyvsp[(1) - (2)].expr),NULL,NULL);}
    break;

  case 56:
#line 181 "ijparser.y"
    {(yyval.expr)=add_Expression(PARSEINT_T, (yyvsp[(3) - (7)].token),NULL,(yyvsp[(5) - (7)].expr),NULL,NULL);}
    break;

  case 57:
#line 186 "ijparser.y"
    {(yyval.expr)=add_Expression(NEWINTARR,NULL,NULL,(yyvsp[(4) - (5)].expr),NULL,NULL);}
    break;

  case 58:
#line 187 "ijparser.y"
    {(yyval.expr)=add_Expression(NEWBOOLARR,NULL,NULL,(yyvsp[(4) - (5)].expr),NULL,NULL);}
    break;

  case 59:
#line 191 "ijparser.y"
    {(yyval.argslist)=add_Args((yyvsp[(1) - (1)].expr), NULL);}
    break;

  case 60:
#line 192 "ijparser.y"
    {(yyval.argslist)=add_Args((yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].argslist));}
    break;

  case 61:
#line 197 "ijparser.y"
    {(yyval.argslist)=(yyvsp[(2) - (2)].argslist);}
    break;


/* Line 1267 of yacc.c.  */
#line 1862 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 201 "ijparser.y"


int main(int argc, char *argv[])
{
	yyparse();
	int i;
	int print_AST;
	int printSymbols;
	print_AST = printSymbols = 0;
	for(i=0; i < argc; i++)
	{
		if(strcmp(argv[i], "-s") == 0){
			printSymbols = 1;
			break;
		}
		else if(strcmp(argv[i], "-t") == 0){
			print_AST = 1;
			break;
		}
	}
	Tabela_sym = buildSymbolsTables(myprogram);
	if(print_AST && erros == 0)
		print_TREE(myprogram);	
	else if(printSymbols && erros == 0)
		printSymbolTables(Tabela_sym);
    return 0;
}

void yyerror(char *s) {
	printf("Line %d, col %d: %s: %s\n", prevLineNo, prevColNo, s, yytext);
	erros++;
}

