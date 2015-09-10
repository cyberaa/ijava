/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "ijparser.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"
#include "display.h"


#define DEBUG 0



/*errors*/
int yydebug=0;
int erros = 0;

void yyerror(char *var);

/*Get lexer vars*/
extern int colNo; /* variavel lex responsavel pela coluna */
extern int yylineno; /*numero da linha*/
extern int yyleng; /* tamanho da character com erro*/
extern char* yytext; /* character com error*/


/*AST Struct*/
AST_TREE* program = NULL;
char Error;
/*SYM Struct*/
Sym_Table* symbols = NULL;


/* Line 371 of yacc.c  */
#line 101 "ijparser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "ijparser.tab.h".  */
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
/* Line 387 of yacc.c  */
#line 35 "ijparser.y"

    char* token; 
    int type; /* Type do tipo inteiro*/
    struct _node* node; /* No da Arvore Sintaxe Abstracta */
    struct _id_List* listId; /* Tipo de Method Type Decl */
    


/* Line 387 of yacc.c  */
#line 191 "ijparser.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 219 "ijparser.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   230

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNRULES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    12,    15,    16,    20,    32,    34,
      36,    40,    45,    46,    51,    52,    55,    56,    61,    65,
      66,    70,    74,    76,    78,    81,    82,    86,    92,   100,
     106,   112,   118,   122,   125,   126,   130,   131,   133,   134,
     136,   138,   140,   145,   149,   152,   157,   165,   169,   173,
     177,   181,   185,   189,   192,   195,   201,   207,   209,   211,
     212,   215,   219
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    13,    37,    22,    41,    23,    -1,    42,
      41,    -1,    43,    41,    -1,    -1,    15,    48,    47,    -1,
      14,    15,    44,    37,    20,    45,    21,    22,    47,    51,
      23,    -1,    50,    -1,    16,    -1,    50,    37,    46,    -1,
      17,    24,    25,    37,    -1,    -1,    35,    50,    37,    46,
      -1,    -1,    48,    47,    -1,    -1,    50,    37,    49,    34,
      -1,    35,    37,    49,    -1,    -1,     5,    24,    25,    -1,
       6,    24,    25,    -1,     5,    -1,     6,    -1,    52,    51,
      -1,    -1,    22,    53,    23,    -1,     8,    20,    57,    21,
      52,    -1,     8,    20,    57,    21,    52,     9,    52,    -1,
      10,    20,    57,    21,    52,    -1,    11,    20,    57,    21,
      34,    -1,    37,    54,    33,    57,    34,    -1,    19,    55,
      34,    -1,    52,    53,    -1,    -1,    24,    57,    25,    -1,
      -1,    57,    -1,    -1,    37,    -1,     3,    -1,     4,    -1,
      37,    20,    58,    21,    -1,    20,    57,    21,    -1,    57,
      18,    -1,    56,    24,    57,    25,    -1,    12,    20,    37,
      24,    57,    25,    21,    -1,    57,    26,    57,    -1,    57,
      27,    57,    -1,    57,    31,    57,    -1,    57,    30,    57,
      -1,    57,    28,    57,    -1,    57,    29,    57,    -1,    30,
      57,    -1,    32,    57,    -1,     7,     5,    24,    57,    25,
      -1,     7,     6,    24,    57,    25,    -1,    56,    -1,    59,
      -1,    -1,    57,    60,    -1,    35,    57,    60,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    91,    91,    95,    96,    97,   100,   103,   107,   108,
     111,   112,   113,   116,   117,   120,   121,   124,   128,   129,
     132,   133,   134,   135,   140,   141,   145,   146,   147,   148,
     149,   150,   151,   155,   156,   160,   161,   165,   166,   169,
     170,   171,   172,   173,   174,   175,   176,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   192,   193,
     196,   199,   200
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTLIT", "BOOLLIT", "INT", "BOOL",
  "NEW", "IF", "ELSE", "WHILE", "PRINT", "PARSEINT", "CLASS", "PUBLIC",
  "STATIC", "VOID", "STRING", "DOTLENGTH", "RETURN", "OCURV", "CCURV",
  "OBRACE", "CBRACE", "OSQUARE", "CSQUARE", "OP1", "OP1OR", "OP2",
  "OP2EQS", "OP3", "OP4", "NOT", "ASSIGN", "SEMIC", "COMMA", "RESERVED",
  "ID", "IFX", "$accept", "Grammar", "Field_or_Method_Decl", "FieldDecl",
  "MethodDecl", "method_type_decl", "FormalParams",
  "multiple_FormalParams", "VarDecl_Recursive", "VarDecl",
  "nested_var_decl", "Type", "Statement_decl_Recursive", "Statement",
  "multiple_statement", "array_indexOPTIONAL", "return_Expr", "Index_Expr",
  "Expr", "Args_OPTIONAL", "Args", "comma_expr", YY_NULL
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
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    41,    42,    43,    44,    44,
      45,    45,    45,    46,    46,    47,    47,    48,    49,    49,
      50,    50,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      59,    60,    60
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     2,     0,     3,    11,     1,     1,
       3,     4,     0,     4,     0,     2,     0,     4,     3,     0,
       3,     3,     1,     1,     2,     0,     3,     5,     7,     5,
       5,     5,     3,     2,     0,     3,     0,     1,     0,     1,
       1,     1,     4,     3,     2,     4,     7,     3,     3,     3,
       3,     3,     3,     2,     2,     5,     5,     1,     1,     0,
       2,     3,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     5,     0,     0,     0,     5,
       5,     0,    22,    23,    16,     0,     2,     3,     4,     9,
       0,     8,     0,     0,     6,    16,    19,     0,    20,    21,
      15,     0,     0,    12,    19,    17,     0,     0,     0,    18,
       0,     0,    14,     0,    16,     0,    10,    11,    25,     0,
       0,     0,     0,    38,    34,    36,     0,    25,    14,     0,
       0,     0,    40,    41,     0,     0,     0,     0,     0,    39,
       0,    57,    37,    34,     0,     0,     0,     7,    24,    13,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    59,
      32,     0,    44,     0,     0,     0,     0,     0,     0,    33,
      26,     0,     0,     0,     0,     0,     0,     0,     0,    43,
      62,     0,    58,     0,    47,    48,    51,    52,    50,    49,
      35,     0,    27,    29,    30,     0,     0,     0,     0,    60,
      42,    45,    31,     0,    55,    56,     0,    62,    28,     0,
      61,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    20,    37,    46,    24,    25,
      32,    15,    56,    57,    74,    76,    70,    71,    72,   111,
     112,   129
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -56
static const yytype_int16 yypact[] =
{
      18,     7,    33,    24,   -56,    -5,    39,    55,    59,    -5,
      -5,     2,    70,    72,    55,    11,   -56,   -56,   -56,   -56,
      56,   -56,    73,    82,   -56,    55,    62,    79,   -56,   -56,
     -56,    75,    76,    63,    62,   -56,    87,    92,    84,   -56,
      97,   103,    89,    90,    55,    55,   -56,   -56,    48,    98,
     106,   118,   119,    25,    48,   112,   117,    48,    89,    25,
      25,    25,   -56,   -56,    69,   121,    25,    25,    25,   129,
     120,   126,   199,    48,   147,    25,   138,   -56,   -56,   -56,
      88,   102,   116,   128,   148,   136,   130,   135,   135,    25,
     -56,    25,   -56,    25,    25,    25,    25,    25,    25,   -56,
     -56,   137,    25,    48,    48,   140,    25,    25,   160,   -56,
      60,   154,   -56,   151,    35,    -4,   -15,    53,    -1,   135,
     -56,    74,   176,   -56,   -56,   165,   179,    25,    25,   -56,
     -56,   -56,   -56,    48,   -56,   -56,   193,    60,   -56,   166,
     -56,   -56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -56,   -56,    67,   -56,   -56,   -56,   -56,   131,   -23,   181,
     152,   -10,   141,   -54,   127,   -56,   -56,   -56,   -55,   -56,
     -56,    64
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      73,    21,    30,    92,    80,    81,    82,    12,    13,     6,
       7,    86,    87,    88,    92,    97,    98,    92,    19,    73,
     101,    48,    93,    38,    95,    96,    97,    98,    62,    63,
      98,     1,    64,     4,   110,    49,   113,    65,   114,   115,
     116,   117,   118,   119,     3,    66,     5,   121,    26,   122,
     123,   125,   126,    92,    11,    67,    50,    68,    51,    52,
      12,    13,    69,    95,    96,    97,    98,    53,    12,    13,
      54,    92,   136,   137,    83,    84,    17,    18,    92,   138,
      36,    95,    16,    97,    98,    55,    93,    94,    95,    96,
      97,    98,    92,    27,    22,   128,    23,    31,    28,    33,
      93,    94,    95,    96,    97,    98,    92,    29,   132,   103,
      35,    40,    34,    41,    93,    94,    95,    96,    97,    98,
      92,    42,    43,   104,    45,    44,    59,    47,    93,    94,
      95,    96,    97,    98,    92,    58,    75,   105,    60,    61,
      77,    85,    93,    94,    95,    96,    97,    98,    92,    89,
      91,   109,   106,    92,    90,    92,    93,    94,    95,    96,
      97,    98,   120,    93,    94,    95,    96,    97,    98,    92,
     100,   102,   107,   108,   124,   130,   131,    93,    94,    95,
      96,    97,    98,    92,   127,   133,    39,   141,    14,    79,
     134,    93,    94,    95,    96,    97,    98,    92,    78,     0,
      99,   140,     0,     0,   135,    93,    94,    95,    96,    97,
      98,    92,     0,     0,     0,     0,     0,    92,   139,    93,
      94,    95,    96,    97,    98,    93,    94,    95,    96,    97,
      98
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-56)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      54,    11,    25,    18,    59,    60,    61,     5,     6,    14,
      15,    66,    67,    68,    18,    30,    31,    18,    16,    73,
      75,    44,    26,    33,    28,    29,    30,    31,     3,     4,
      31,    13,     7,     0,    89,    45,    91,    12,    93,    94,
      95,    96,    97,    98,    37,    20,    22,   102,    37,   103,
     104,   106,   107,    18,    15,    30,     8,    32,    10,    11,
       5,     6,    37,    28,    29,    30,    31,    19,     5,     6,
      22,    18,   127,   128,     5,     6,     9,    10,    18,   133,
      17,    28,    23,    30,    31,    37,    26,    27,    28,    29,
      30,    31,    18,    37,    24,    35,    24,    35,    25,    20,
      26,    27,    28,    29,    30,    31,    18,    25,    34,    21,
      34,    24,    37,    21,    26,    27,    28,    29,    30,    31,
      18,    37,    25,    21,    35,    22,    20,    37,    26,    27,
      28,    29,    30,    31,    18,    37,    24,    21,    20,    20,
      23,    20,    26,    27,    28,    29,    30,    31,    18,    20,
      24,    21,    24,    18,    34,    18,    26,    27,    28,    29,
      30,    31,    25,    26,    27,    28,    29,    30,    31,    18,
      23,    33,    24,    37,    34,    21,    25,    26,    27,    28,
      29,    30,    31,    18,    24,     9,    34,    21,     7,    58,
      25,    26,    27,    28,    29,    30,    31,    18,    57,    -1,
      73,   137,    -1,    -1,    25,    26,    27,    28,    29,    30,
      31,    18,    -1,    -1,    -1,    -1,    -1,    18,    25,    26,
      27,    28,    29,    30,    31,    26,    27,    28,    29,    30,
      31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    40,    37,     0,    22,    14,    15,    41,    42,
      43,    15,     5,     6,    48,    50,    23,    41,    41,    16,
      44,    50,    24,    24,    47,    48,    37,    37,    25,    25,
      47,    35,    49,    20,    37,    34,    17,    45,    50,    49,
      24,    21,    37,    25,    22,    35,    46,    37,    47,    50,
       8,    10,    11,    19,    22,    37,    51,    52,    37,    20,
      20,    20,     3,     4,     7,    12,    20,    30,    32,    37,
      55,    56,    57,    52,    53,    24,    54,    23,    51,    46,
      57,    57,    57,     5,     6,    20,    57,    57,    57,    20,
      34,    24,    18,    26,    27,    28,    29,    30,    31,    53,
      23,    57,    33,    21,    21,    21,    24,    24,    37,    21,
      57,    58,    59,    57,    57,    57,    57,    57,    57,    57,
      25,    57,    52,    52,    34,    57,    57,    24,    35,    60,
      21,    25,    34,     9,    25,    25,    57,    57,    52,    25,
      60,    21
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
/* Line 1787 of yacc.c  */
#line 91 "ijparser.y"
    {if(DEBUG)printf("New class\n");(yyval.node) = add_Class_to_List((yyvsp[(2) - (5)].token),(yyvsp[(4) - (5)].node));program = (yyval.node);}
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 95 "ijparser.y"
    {if(DEBUG)printf("New variable\n");(yyval.node) = set_next_Node((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 96 "ijparser.y"
    {if(DEBUG)printf("New Method\n"); (yyval.node) = set_next_Node((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 97 "ijparser.y"
    {if(DEBUG)printf("NULL\n");(yyval.node) = NULL;}
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 100 "ijparser.y"
    {if(DEBUG)printf("Static Variable\n"); (yyval.node) = setStatic((yyvsp[(2) - (3)].node));(yyval.node) = set_next_Node((yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 103 "ijparser.y"
    {if(DEBUG)printf("Create method\n"); (yyval.node) = setStatic(add_Method((yyvsp[(3) - (11)].type),(yyvsp[(4) - (11)].token),(yyvsp[(6) - (11)].node),(yyvsp[(9) - (11)].node),(yyvsp[(10) - (11)].node)));}
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 107 "ijparser.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 108 "ijparser.y"
    {(yyval.type) = TYPE_VOID;}
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 111 "ijparser.y"
    {if(DEBUG)printf("Formal Params Other\n");(yyval.node) = add_ParamDecl((yyvsp[(1) - (3)].type),(yyvsp[(2) - (3)].token),NULL,(yyvsp[(3) - (3)].node));}
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 112 "ijparser.y"
    {if(DEBUG)printf("Formal Params String\n");(yyval.node) = add_ParamDecl(TYPE_STRING_ARRAY,(yyvsp[(4) - (4)].token),NULL,NULL);}
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 113 "ijparser.y"
    {if(DEBUG)printf("No Formal Params\n");(yyval.node) = NULL;}
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 116 "ijparser.y"
    {if(DEBUG)printf("Multiple Formal Params\n");(yyval.node) = add_ParamDecl((yyvsp[(2) - (4)].type),(yyvsp[(3) - (4)].token),NULL,(yyvsp[(4) - (4)].node));}
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 117 "ijparser.y"
    {if(DEBUG)printf("No more formal params\n");(yyval.node) = NULL;}
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 120 "ijparser.y"
    {(yyval.node) = set_next_Node((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 121 "ijparser.y"
    {(yyval.node) = NULL;}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 124 "ijparser.y"
    {if(DEBUG)printf("new Var\n");(yyval.node) = add_VarDecl((yyvsp[(1) - (4)].type),(yyvsp[(2) - (4)].token),(yyvsp[(3) - (4)].listId),NULL);}
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 128 "ijparser.y"
    {if(DEBUG)printf("Multiple Vars in same Decl ID(%s)\n",(yyvsp[(2) - (3)].token));(yyval.listId) = add_VarID_to_ID_LIST((yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].listId));}
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 129 "ijparser.y"
    {(yyval.listId) = NULL;}
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 132 "ijparser.y"
    {(yyval.type) = TYPE_INT_ARRAY;}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 133 "ijparser.y"
    {(yyval.type) = TYPE_BOOL_ARRAY;}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 134 "ijparser.y"
    {(yyval.type) = TYPE_INT;}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 135 "ijparser.y"
    {(yyval.type) = TYPE_BOOL;}
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 140 "ijparser.y"
    {(yyval.node) = set_next_Node((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 141 "ijparser.y"
    {(yyval.node) = NULL;}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 145 "ijparser.y"
    {(yyval.node) = add_Compound_Stmnt((yyvsp[(2) - (3)].node));}
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 146 "ijparser.y"
    {(yyval.node) = add_IF((yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node),NULL);}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 147 "ijparser.y"
    {(yyval.node) = add_IF((yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 148 "ijparser.y"
    {(yyval.node) = add_While((yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node));}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 149 "ijparser.y"
    {(yyval.node) = add_Print((yyvsp[(3) - (5)].node));}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 150 "ijparser.y"
    {(yyval.node) = add_Store((yyvsp[(1) - (5)].token),(yyvsp[(2) - (5)].node),(yyvsp[(4) - (5)].node));}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 151 "ijparser.y"
    {(yyval.node) = add_Return((yyvsp[(2) - (3)].node));}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 155 "ijparser.y"
    {(yyval.node) = set_next_Node((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 156 "ijparser.y"
    {(yyval.node) = NULL;}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 160 "ijparser.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 161 "ijparser.y"
    {(yyval.node) = NULL;}
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 165 "ijparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 166 "ijparser.y"
    {(yyval.node) = NULL;}
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 169 "ijparser.y"
    {(yyval.node) = add_Terminal_Node(NO_ID,(yyvsp[(1) - (1)].token));}
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 170 "ijparser.y"
    {(yyval.node) = add_Terminal_Node(NO_INTLIT,(yyvsp[(1) - (1)].token));}
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 171 "ijparser.y"
    {(yyval.node) = add_Terminal_Node(NO_BOOLLIT,(yyvsp[(1) - (1)].token));}
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 172 "ijparser.y"
    {(yyval.node) = add_Call((yyvsp[(1) - (4)].token),(yyvsp[(3) - (4)].node));}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 173 "ijparser.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 174 "ijparser.y"
    {(yyval.node) = add_DotLength((yyvsp[(1) - (2)].node));}
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 175 "ijparser.y"
    {(yyval.node) = add_LoadArray((yyvsp[(1) - (4)].node),(yyvsp[(3) - (4)].node));}
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 176 "ijparser.y"
    {(yyval.node) = add_ParseInt((yyvsp[(3) - (7)].token),(yyvsp[(5) - (7)].node));}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 179 "ijparser.y"
    {(yyval.node) = add_two_Expr((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].node));}
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 180 "ijparser.y"
    {(yyval.node) = add_two_Expr((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].node));}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 181 "ijparser.y"
    {(yyval.node) = add_two_Expr((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].node));}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 182 "ijparser.y"
    {(yyval.node) = add_two_Expr((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].node));}
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 183 "ijparser.y"
    {(yyval.node) = add_two_Expr((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].node));}
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 184 "ijparser.y"
    {(yyval.node) = add_two_Expr((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].token),(yyvsp[(3) - (3)].node));}
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 185 "ijparser.y"
    {(yyval.node) = add_Expr((yyvsp[(1) - (2)].token),(yyvsp[(2) - (2)].node));}
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 186 "ijparser.y"
    {(yyval.node) = add_Expr((yyvsp[(1) - (2)].token),(yyvsp[(2) - (2)].node));}
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 187 "ijparser.y"
    {(yyval.node) = add_NewArray(NO_NEWINT,(yyvsp[(4) - (5)].node));}
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 188 "ijparser.y"
    {(yyval.node) = add_NewArray(NO_NEWBOOL,(yyvsp[(4) - (5)].node));}
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 189 "ijparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 192 "ijparser.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 193 "ijparser.y"
    {(yyval.node) = NULL;}
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 196 "ijparser.y"
    {(yyval.node) = set_next_Node((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 199 "ijparser.y"
    {(yyval.node) = set_next_Node((yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 200 "ijparser.y"
    {(yyval.node) = NULL;}
    break;


/* Line 1787 of yacc.c  */
#line 1913 "ijparser.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2050 of yacc.c  */
#line 202 "ijparser.y"


int main(int argc, char *argv[]){
    int i, print_AST, printSYMvar;
    Error = 0;
    yyparse();	/*Funcao Responsavel pelos erros gramaticais */
    print_AST = printSYMvar = 0;


	for(i=0; i < argc; i++)
	{
		if(strcmp(argv[i], "-s") == 0)
		{
            printSYMvar = 1;
		}
		else if(strcmp(argv[i], "-t") == 0)
		{
			print_AST = 1;
		}
	}
        if(Error)
            return 0;
        if(print_AST)
            print_TREE(program);
        if(printSYMvar){
            symbols = create_SymTable(program);
            if(program!=NULL)
                setTable(symbols);
                check_Semantic_Errors(program, symbols, symbols);
            printSymbolTables(symbols);


        }
        //genCode(program);
		
    return 0;
}

void yyerror (char *var) {
        printf ("Line %d, col %d: %s: %s\n",yylineno, (int)(colNo-strlen(yytext)), var, yytext);
        Error = 1;
}
