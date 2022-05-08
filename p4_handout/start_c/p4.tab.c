/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "p4_c.y" /* yacc.c:339  */

/* Kenneth Loyola
 * G01211826
 * CS-440
 * 
 * Mython Project 4 - Intermediate Code
 * Translate mython source code to MIPs assembly
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Yacc Variables */
extern int yylineno;
extern int yylex();
int yyerror();

/* Error & Report Messages */
const char* pass_msg = "Input Accepted\n";
const char* mips_entry = "\n.text\n.globl main\nmain:\n";
const char* mips_exit = "\n\tli $v0, 10\n\tsyscall\n";

/* Semantic/IC Functions */
void cleanUp();
void checkAlloc();
void resetScopes();
void resetRegs(int c);
void addToScope();
void printScopes();
void loadStoreRegs(int c);
void pop(); //stack
void push(); //stack
int getOpenReg(int c);
int checkType(char *idName);
int checkID(char *idName);
char* checkIDStr(char *idName);

/* Semantic/IC Variables */
char *funcName = NULL;
char recentReg[5];
int inCall = 0, inPrint = 0, inReturn = 0; //boolean checkers
int callCheck = 0, callArgs = 0; //caller attributes
int strID = 0, stackSize = 0, top = -1, labID = -1; //string and stack/label vars
int *stack = NULL; //stack of labels
int tRegs[8], aRegs[4]; //$t and $a registers (FIXED)

/* Symbol Table Structure */
typedef struct table {
	char *id_name;
	char *strVal;
	int val;
	int type;
} SymbolTable;
//SymbolTable Scope Pointer
SymbolTable *scopes = NULL;
int numScopes = 0; //keeps track number of scopes


#line 126 "p4.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "p4.tab.h".  */
#ifndef YY_YY_P4_TAB_H_INCLUDED
# define YY_YY_P4_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ADD = 258,
    MINUS = 259,
    MUL = 260,
    DIV = 261,
    EQ = 262,
    LT = 263,
    LE = 264,
    GT = 265,
    GE = 266,
    ASSIGN = 267,
    NE = 268,
    DEF = 269,
    ENDDEF = 270,
    IF = 271,
    ENDIF = 272,
    ELSE = 273,
    WHILE = 274,
    ENDWHILE = 275,
    PRINT = 276,
    INPUT = 277,
    TRUE = 278,
    FALSE = 279,
    RETURN = 280,
    LP = 281,
    RP = 282,
    COLON = 283,
    COMMA = 284,
    COMMENT = 285,
    STRING = 286,
    ID = 287,
    NUMBER = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 65 "p4_c.y" /* yacc.c:355  */

	char id_name[25];
	char str[25];
	int num;
	struct {
		char curName[25];
		int reg;
		int val;
		int strChk;
	} local;

#line 212 "p4.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_P4_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 229 "p4.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    87,    94,    97,    99,   109,   113,   117,
     124,   129,   134,   135,   137,   138,   139,   140,   141,   142,
     143,   145,   153,   160,   164,   167,   177,   184,   191,   198,
     205,   212,   219,   223,   230,   237,   244,   251,   258,   265,
     271,   281,   290,   306,   313,   320,   323,   325,   327,   331,
     339,   351,   358,   364,   377,   385,   386,   391,   398,   403,
     409,   409,   420,   421,   423,   423
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "MINUS", "MUL", "DIV", "EQ", "LT",
  "LE", "GT", "GE", "ASSIGN", "NE", "DEF", "ENDDEF", "IF", "ENDIF", "ELSE",
  "WHILE", "ENDWHILE", "PRINT", "INPUT", "TRUE", "FALSE", "RETURN", "LP",
  "RP", "COLON", "COMMA", "COMMENT", "STRING", "ID", "NUMBER", "$accept",
  "program", "func_list_head", "function_list", "function", "func_head",
  "def_head", "parameters", "statements", "statement", "assignment_stmt",
  "assign_head", "return_stmt", "expression", "rel_exp", "exp", "term",
  "factor", "print_stmt", "print_head", "print_exp", "input_stmt",
  "call_stmt", "call_head", "condition_stmt", "if_head", "else_head",
  "while_stmt", "while_head", "$@1", "expr_list", "end_list", "$@2", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
};
# endif

#define YYPACT_NINF -28

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-28)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -28,    30,   -28,    14,   -28,   -28,   137,    18,   -28,   137,
      31,    67,   -28,    35,    71,     1,   137,   -28,   -28,    55,
     -28,   -28,    67,   -28,   -28,    10,   -28,   137,   -28,   137,
     -28,   102,    -8,    71,   -28,   -28,    67,   -28,    46,   -28,
      45,   -28,   163,    12,   -28,   -28,    67,   -28,    71,    36,
     -28,   -28,   -28,    48,   -28,   -28,   -20,   -28,    36,     2,
     119,    28,   -28,    52,   -28,    29,   -28,    57,   103,   -28,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      61,     8,    58,   -28,    67,   -28,    71,   -28,    64,   137,
     -28,   -28,    73,    76,   -28,   -28,    12,    12,    36,    36,
      36,    36,    36,    36,   -28,   -28,   -28,   -28,   -28,    36,
     -28,   129,   -28,   -28,   -28
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,    64,     3,     1,     2,     0,     0,     4,     0,
       0,     0,    60,     0,     0,     0,    65,    13,    14,     0,
      20,    15,     0,    16,    19,     0,    17,     0,    18,     0,
       9,     0,     0,     0,    43,    44,     0,    41,    42,    40,
       0,    24,    25,    35,    38,    46,     0,    48,     0,    23,
      22,    54,    12,     0,    21,    50,     0,    52,    63,     0,
       0,     0,     6,     0,    11,     0,    45,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,    53,     0,    55,     0,     0,
      59,     8,     0,     0,    32,    39,    33,    34,    26,    28,
      29,    30,    31,    27,    36,    37,    61,    51,    49,    62,
      58,     0,     7,    10,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,    -7,   -15,
     -28,   -28,   -28,   -14,    79,   -10,    -2,   -27,   -28,   -28,
     -28,   -28,    -6,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     3,     8,     9,    10,    65,    16,    17,
      18,    19,    20,    40,    41,    42,    43,    44,    21,    22,
      56,    23,    45,    25,    26,    27,    89,    28,    29,    46,
      59,     5,     6
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      24,    52,    31,    24,    49,    54,    66,    83,    55,    84,
      24,    70,    71,    50,    33,    58,    52,    78,    79,    63,
      60,    24,    61,    24,    64,    24,    68,    51,     7,    85,
       4,    86,    80,    34,    35,    95,    48,    57,    81,    70,
      71,    37,    38,    39,    11,    52,    52,    12,    90,    13,
      30,   104,   105,    14,    24,    24,    92,    32,    93,    33,
      15,    47,    98,    99,   100,   101,   102,   103,    96,    97,
     108,    33,    51,    69,    82,    33,   109,    53,    34,    35,
      91,    36,   111,    24,    94,   107,    37,    38,    39,   106,
      34,    35,   110,    36,    34,    35,    52,    48,    37,    38,
      39,   112,    37,    38,    39,    24,    70,    71,   113,     0,
      72,    73,    74,    75,    76,    67,    77,    62,    11,     0,
       0,    12,     0,    13,     0,     0,     0,    14,     0,     0,
      95,     0,     0,     0,    15,    11,    87,    88,    12,     0,
      13,     0,     0,     0,    14,    11,   114,     0,    12,     0,
      13,    15,     0,    11,    14,     0,    12,     0,    13,     0,
       0,    15,    14,     0,     0,     0,    70,    71,     0,    15,
      72,    73,    74,    75,    76,     0,    77
};

static const yytype_int8 yycheck[] =
{
       6,    16,     9,     9,    14,    19,    33,    27,    22,    29,
      16,     3,     4,    12,     4,    25,    31,     5,     6,    27,
      27,    27,    29,    29,    32,    31,    36,    26,    14,    27,
       0,    29,    46,    23,    24,    27,    26,    27,    48,     3,
       4,    31,    32,    33,    16,    60,    61,    19,    20,    21,
      32,    78,    79,    25,    60,    61,    27,    26,    29,     4,
      32,    26,    72,    73,    74,    75,    76,    77,    70,    71,
      84,     4,    26,    28,    26,     4,    86,    22,    23,    24,
      28,    26,    89,    89,    27,    27,    31,    32,    33,    28,
      23,    24,    28,    26,    23,    24,   111,    26,    31,    32,
      33,    28,    31,    32,    33,   111,     3,     4,    32,    -1,
       7,     8,     9,    10,    11,    36,    13,    15,    16,    -1,
      -1,    19,    -1,    21,    -1,    -1,    -1,    25,    -1,    -1,
      27,    -1,    -1,    -1,    32,    16,    17,    18,    19,    -1,
      21,    -1,    -1,    -1,    25,    16,    17,    -1,    19,    -1,
      21,    32,    -1,    16,    25,    -1,    19,    -1,    21,    -1,
      -1,    32,    25,    -1,    -1,    -1,     3,     4,    -1,    32,
       7,     8,     9,    10,    11,    -1,    13
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    36,    37,     0,    65,    66,    14,    38,    39,
      40,    16,    19,    21,    25,    32,    42,    43,    44,    45,
      46,    52,    53,    55,    56,    57,    58,    59,    61,    62,
      32,    42,    26,     4,    23,    24,    26,    31,    32,    33,
      47,    48,    49,    50,    51,    56,    63,    26,    26,    49,
      12,    26,    43,    22,    47,    47,    54,    27,    49,    64,
      42,    42,    15,    27,    32,    41,    51,    48,    49,    28,
       3,     4,     7,     8,     9,    10,    11,    13,     5,     6,
      47,    49,    26,    27,    29,    27,    29,    17,    18,    60,
      20,    28,    27,    29,    27,    27,    50,    50,    49,    49,
      49,    49,    49,    49,    51,    51,    28,    27,    47,    49,
      28,    42,    28,    32,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    37,    37,    38,    39,    39,    40,
      41,    41,    42,    42,    43,    43,    43,    43,    43,    43,
      43,    44,    45,    46,    47,    47,    48,    48,    48,    48,
      48,    48,    48,    49,    49,    49,    50,    50,    50,    51,
      51,    51,    51,    51,    51,    51,    51,    52,    53,    54,
      54,    55,    56,    56,    57,    58,    58,    59,    60,    61,
      63,    62,    64,    64,    66,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     0,     3,     5,     4,     2,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     1,     1,     1,     1,     2,     1,     3,     2,     3,
       1,     4,     2,     3,     2,     3,     5,     3,     2,     3,
       0,     4,     3,     1,     0,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 87 "p4_c.y" /* yacc.c:1646  */
    {
			resetScopes(); //clears out the scope list
			resetRegs(1); //clears out the registers (t's and a's)
			funcName = strdup("global"); //sets function name
			checkAlloc(funcName); //checks allocation
		}
#line 1404 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 94 "p4_c.y" /* yacc.c:1646  */
    { 
	       		resetScopes(); //clears out the scope list
		}
#line 1412 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 99 "p4_c.y" /* yacc.c:1646  */
    {
			resetRegs(0); //clears out only t regs
			//if coming from return, then move return value
			if(inReturn) printf("\tmove $v0, %s\n", recentReg);
			//loads return address and returns
			printf("\tlw $ra, %s_RA\n", funcName); 
			printf("\tjr $ra\n");
			resetRegs(0); //resets the registers once again
		}
#line 1426 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 109 "p4_c.y" /* yacc.c:1646  */
    {
			printf(".text\n\tsw $ra, %s_RA\n", funcName);
			printScopes(); //prints out the scopes 
		}
#line 1435 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 113 "p4_c.y" /* yacc.c:1646  */
    {
			printf(".text\n\tsw $ra, %s_RA\n", funcName);
		}
#line 1443 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 117 "p4_c.y" /* yacc.c:1646  */
    {
			printf(".text\n%s:\n.data\n%s_RA: .word 0\n.align 2\n", (yyvsp[0].str), (yyvsp[0].str));
			funcName = strdup((yyvsp[0].str));	//allocates the ID to funcName
			checkAlloc(funcName); //checks allocation
			printf("%s_registers: .space 48\n", funcName);
		}
#line 1454 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 124 "p4_c.y" /* yacc.c:1646  */
    {
	   		//Prints out the parameters and adds it to the scope
			printf("%s_%s: .word 0\n", funcName, (yyvsp[0].str));
			addToScope((yyvsp[0].str), "", 2, 0);
		}
#line 1464 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 129 "p4_c.y" /* yacc.c:1646  */
    {
			printf("%s_%s: .word 0\n", funcName, (yyvsp[0].str));
			addToScope((yyvsp[0].str), "", 2, 0); //adds param to scope
		}
#line 1473 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 145 "p4_c.y" /* yacc.c:1646  */
    {
			//uses the recent reg available
			printf("\tsw %s,%s_%s\n", recentReg, funcName, (yyvsp[-1].id_name));
			resetRegs(0); //resets the registers
			//adds to the scope
			addToScope((yyvsp[-1].id_name), (yyvsp[0].local).curName, (yyvsp[0].local).strChk, (yyvsp[0].local).val);
		}
#line 1485 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 153 "p4_c.y" /* yacc.c:1646  */
    {
			if(checkID((yyvsp[-1].str)) == -1){
				printf(".data\n.align 2\n%s_%s: .word 0\n.text\n", funcName, (yyvsp[-1].str));
				strcpy((yyval.id_name), (yyvsp[-1].str)); //assign the ID to the NT attribute
			}
		}
#line 1496 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 160 "p4_c.y" /* yacc.c:1646  */
    {
			inReturn = 1;
		}
#line 1504 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 164 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = (yyvsp[0].local).reg; //assigns the attribute value
		}
#line 1512 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 167 "p4_c.y" /* yacc.c:1646  */
    {
			//assigns the attribute values for the NT
			(yyval.local).reg = (yyvsp[0].local).reg;
			(yyval.local).val = (yyvsp[0].local).val;
			(yyval.local).strChk = (yyvsp[0].local).strChk;
			strcpy((yyval.local).curName, (yyvsp[0].local).curName); //gets the name
		}
#line 1524 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 177 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = (yyvsp[-2].local).reg; //assigns the register used
			//prints out the relation expression
			printf("\tseq $t%d,$t%d,$t%d\n", (yyvsp[-2].local).reg, (yyvsp[-2].local).reg, (yyvsp[0].local).reg);
			tRegs[(yyval.local).reg] = 0; //clears the 2 t registers
			tRegs[(yyvsp[0].local).reg] = 0;
		}
#line 1536 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 184 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = (yyvsp[-2].local).reg; //assigns the register used
			//prints out the relation expression
			printf("\tsne $t%d,$t%d,$t%d\n", (yyvsp[-2].local).reg, (yyvsp[-2].local).reg, (yyvsp[0].local).reg);
			tRegs[(yyval.local).reg] = 0; //clears the 2 t registers
			tRegs[(yyvsp[0].local).reg] = 0;
		}
#line 1548 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 191 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = (yyvsp[-2].local).reg; //assigns the register used
			//prints out the relation expression
			printf("\tslt $t%d,$t%d,$t%d\n", (yyvsp[-2].local).reg, (yyvsp[-2].local).reg, (yyvsp[0].local).reg);
			tRegs[(yyval.local).reg] = 0; //clears the 2 t registers
			tRegs[(yyvsp[0].local).reg] = 0;
		}
#line 1560 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 198 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = (yyvsp[-2].local).reg; //assigns the register used
			//prints out the relation expression
			printf("\tsle $t%d,$t%d,$t%d\n", (yyvsp[-2].local).reg, (yyvsp[-2].local).reg, (yyvsp[0].local).reg);
			tRegs[(yyval.local).reg] = 0; //clears the 2 t registers
			tRegs[(yyvsp[0].local).reg] = 0;
		}
#line 1572 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 205 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = (yyvsp[-2].local).reg; //assigns the register used
			//prints out the relation expression
			printf("\tsgt $t%d,$t%d,$t%d\n", (yyvsp[-2].local).reg, (yyvsp[-2].local).reg, (yyvsp[0].local).reg);
			tRegs[(yyval.local).reg] = 0; //clears the 2 t registers
			tRegs[(yyvsp[0].local).reg] = 0;
		}
#line 1584 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 212 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = (yyvsp[-2].local).reg; //assigns the register used
			//prints out the relation expression
			printf("\tsge $t%d,$t%d,$t%d\n", (yyvsp[-2].local).reg, (yyvsp[-2].local).reg, (yyvsp[0].local).reg);
			tRegs[(yyval.local).reg] = 0; //clears the 2 t registers
			tRegs[(yyvsp[0].local).reg] = 0;
		}
#line 1596 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 219 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = (yyvsp[-1].local).reg; //gets the rel_exp reg
		}
#line 1604 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 223 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = (yyvsp[-2].local).reg; //gets the first register
			(yyval.local).val = (yyvsp[-2].local).val + (yyvsp[0].local).val; //adds them up
			printf("\tadd $t%d,$t%d,$t%d\n", (yyvsp[-2].local).reg, (yyvsp[-2].local).reg, (yyvsp[0].local).reg);
			snprintf(recentReg, 4, "$t%d", (yyval.local).reg); //sets recent reg
			tRegs[(yyvsp[0].local).reg] = 0; //clears operand reg
		}
#line 1616 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 230 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = (yyvsp[-2].local).reg; //gets the first register
			(yyval.local).val = (yyvsp[-2].local).val - (yyvsp[0].local).val; //subtracts them
			printf("\tsub $t%d,$t%d,$t%d\n", (yyvsp[-2].local).reg, (yyvsp[-2].local).reg, (yyvsp[0].local).reg);
			snprintf(recentReg, 4, "$t%d", (yyval.local).reg); //sets recent reg
			tRegs[(yyvsp[0].local).reg] = 0; //clears operand reg
		}
#line 1628 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 237 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = (yyvsp[0].local).reg; //gets the first reg
			(yyval.local).val = (yyvsp[0].local).val; //gets the value from term attribute
			(yyval.local).strChk = (yyvsp[0].local).strChk; //string checker
			strcpy((yyval.local).curName, (yyvsp[0].local).curName); //gets name
		}
#line 1639 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 244 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = (yyvsp[-2].local).reg; //gets the first register
			(yyval.local).val = (yyvsp[-2].local).val * (yyvsp[0].local).val; //gets product
			printf("\tmul $t%d,$t%d,$t%d\n", (yyvsp[-2].local).reg, (yyvsp[-2].local).reg, (yyvsp[0].local).reg);
			snprintf(recentReg, 4, "$t%d", (yyval.local).reg); //sets recent reg
			tRegs[(yyvsp[0].local).reg] = 0; //clears operand reg
		}
#line 1651 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 251 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = (yyvsp[-2].local).reg; //gets the first register
			(yyval.local).val = (yyvsp[-2].local).val / (yyvsp[0].local).val; //divides them (Int)
			printf("\tdiv $t%d,$t%d,$t%d\n", (yyvsp[-2].local).reg, (yyvsp[-2].local).reg, (yyvsp[0].local).reg);
			snprintf(recentReg, 4, "$t%d", (yyval.local).reg); //sets recent reg
			tRegs[(yyvsp[0].local).reg] = 0; //clears operand reg
		}
#line 1663 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 258 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = (yyvsp[0].local).reg; //gets the first reg
			(yyval.local).val = (yyvsp[0].local).val; //gets the value from factor attribute
			(yyval.local).strChk = (yyvsp[0].local).strChk; //string checker
			strcpy((yyval.local).curName, (yyvsp[0].local).curName); //gets name
		}
#line 1674 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 265 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = (yyvsp[-1].local).reg; //gets the reg from exp
			(yyval.local).val = (yyvsp[-1].local).val; //gets the val
			(yyval.local).strChk = (yyvsp[-1].local).strChk; //string checker
			strcpy((yyval.local).curName, (yyvsp[-1].local).curName);
		}
#line 1685 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 271 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = getOpenReg(0); //gets an open reg
			(yyval.local).val = (yyvsp[0].num); //gets the value of number
			printf("\tli $t%d, %d\n", (yyval.local).reg, (yyvsp[0].num));
			snprintf(recentReg, 4, "$t%d", (yyval.local).reg);
			if(inCall){ //if procedure call
				printf("\tmove $a%d, $t%d\n", getOpenReg(1), (yyval.local).reg);
				resetRegs(0);
			}
		}
#line 1700 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 281 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = getOpenReg(0); //gets open t reg
			(yyval.local).strChk = 1; //string checker to true (1)
			strcpy((yyval.local).curName, (yyvsp[0].str)); //sets the current name
			printf(".data\nstr%d:\t.asciiz %s\n.text\n", strID, (yyvsp[0].str));
			snprintf(recentReg, 4, "$t%d", (yyval.local).reg);
			printf("\tla $t%d, str%d\n", (yyval.local).reg, strID);
			strID += 1; //increments string counter
		}
#line 1714 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 290 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = getOpenReg(0); //gets open t reg
			(yyval.local).strChk = checkType((yyvsp[0].str)); //check the type of ID
			if((yyval.local).strChk){ //if string, then set current name
				strcpy((yyval.local).curName, checkIDStr((yyvsp[0].str)));
				checkAlloc((yyval.local).curName);
			}
			else //else, set the value to int value of ID
				(yyval.local).val = checkID((yyvsp[0].str));
			snprintf(recentReg, 4, "$t%d", (yyval.local).reg); //sets the recent reg
			printf("\tlw %s, %s_%s\n", recentReg, funcName, (yyvsp[0].str));
			if(inCall){ //if procedure all
				printf("\tmove $a%d, $t%d\n", getOpenReg(1), (yyval.local).reg);
				resetRegs(0); //resets the t regs
			}
		}
#line 1735 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 306 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).val = 1; //1 for TRUE
			(yyval.local).reg = getOpenReg(0);
			snprintf(recentReg, 4, "$t%d", (yyval.local).reg);
			(yyval.local).strChk = 0;
			printf("\tli $t%d, 1\n", (yyval.local).reg);
		}
#line 1747 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 313 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = getOpenReg(0); //gets open reg
			(yyval.local).val = 0; //0 for FALSE
			snprintf(recentReg, 4, "$t%d", (yyval.local).reg);
			(yyval.local).strChk = 0;
			printf("\tli $t%d, 0\n", (yyval.local).reg);
		}
#line 1759 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 320 "p4_c.y" /* yacc.c:1646  */
    {
			printf("\tneg $t%d,$t%d\n", (yyvsp[0].local).reg, (yyvsp[0].local).reg);
		}
#line 1767 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 327 "p4_c.y" /* yacc.c:1646  */
    {
			inPrint = 1; //now in print stmt
		}
#line 1775 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 331 "p4_c.y" /* yacc.c:1646  */
    {
			if(inPrint){
				//if string, then syscall 4, else 1
				int sysID = ((yyvsp[0].local).strChk) ? 4 : 1;
				printf("\tli $v0,%d\n\tmove $a0,%s\n\tsyscall\n", sysID, recentReg);
				resetRegs(0); //resets the t regs
			}
		}
#line 1788 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 339 "p4_c.y" /* yacc.c:1646  */
    {
			(yyval.local).reg = (yyvsp[0].local).reg; //gets the expression reg
			(yyval.local).val = (yyvsp[0].local).val; //gets the expression val
			strcpy((yyval.local).curName, (yyvsp[0].local).curName); //gets string
			if(inPrint){
				//if string, then syscall 4, else 1
				int sysID = ((yyvsp[0].local).strChk) ? 4 : 1;
				printf("\tli $v0,%d\n\tmove $a0,%s\n\tsyscall\n", sysID, recentReg);
				resetRegs(0); //resets the t regs
			}
		}
#line 1804 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 351 "p4_c.y" /* yacc.c:1646  */
    {
	   		//syscall on input
			printf("\tli $v0,5\n\tsyscall\n");
			snprintf(recentReg, 4, "$v0"); //stores return value from input call
			printf("\tsw %s,%s_%s\n", recentReg, funcName, (yyvsp[-3].id_name));
		}
#line 1815 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 358 "p4_c.y" /* yacc.c:1646  */
    {
			printf("\tjal %s\n", (yyvsp[-1].str)); //jump and link
			loadStoreRegs(1); //shows the loading of registers after call
			printf("\tmove $t%d, $v0\n", getOpenReg(0)); //gets return value
			resetRegs(1); //clears out the a and t regs
		}
#line 1826 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 364 "p4_c.y" /* yacc.c:1646  */
    {
			printf("\tjal %s\n", (yyvsp[-2].str)); //jump and link
			loadStoreRegs(1); //shows the recovery of regs after call
			printf("\tmove %s,$v0\n", recentReg); //return value
			if(callCheck == 2){ //call checker
				printf("\tmove $a%d,%s\n", callArgs, recentReg);
				callArgs += 1; //increments the arg register counter
			}
			resetRegs(2); //resets only the a regs
			if(strcmp(funcName, "global") == 0) //if global
				callCheck -= 1; //decrements the checker
		}
#line 1843 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 377 "p4_c.y" /* yacc.c:1646  */
    {
			if(strcmp(funcName, "global") == 0)
				callCheck += 1; //if global, increase call checker
			loadStoreRegs(0); //shows the storing of registers before call
			inCall = 1;
			strcpy((yyval.str), (yyvsp[-1].str)); //copies the string ID
		}
#line 1855 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 386 "p4_c.y" /* yacc.c:1646  */
    {
			printf("\nL%d:\n", stack[top]); //shows label
			pop(); //pops off the stack
		}
#line 1864 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 391 "p4_c.y" /* yacc.c:1646  */
    {
			labID += 2; //increase the label IDs
			push(); //push the labels onto stack
			//prints out the label to jump to
			printf("\tbeqz $t%d,L%d\n", (yyvsp[-1].local).reg, stack[top-1]);	
		}
#line 1875 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 398 "p4_c.y" /* yacc.c:1646  */
    {
	  		//prints out the labels
			printf("\tb L%d\nL%d:\n", stack[top], stack[top-1]);
		}
#line 1884 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 403 "p4_c.y" /* yacc.c:1646  */
    {
	   		//prints the labels
			printf("\tb L%d\nL%d:\n", stack[top-1], stack[top]);
			pop(); //pops out the labels
		}
#line 1894 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 409 "p4_c.y" /* yacc.c:1646  */
    {
			labID += 2; //increase the label counter
			push(); //push the labels onto stack
			printf("L%d:\t", stack[top-1]);
		}
#line 1904 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 414 "p4_c.y" /* yacc.c:1646  */
    {
			//prints out the expression's resulting reg and label
			printf("\tbeqz $t%d,L%d\n", (yyvsp[-1].local).reg, stack[top]);
			int tmpReg = getOpenReg(0); //takes a t reg
		}
#line 1914 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 423 "p4_c.y" /* yacc.c:1646  */
    { 
	 		// generate .main 
            		printf(mips_entry);
			printf("\n.data\n.align 2\nglobal_registers: .space 48\n.text\n");
          	}
#line 1924 "p4.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 428 "p4_c.y" /* yacc.c:1646  */
    { 
			//generate exit 
           		printf(mips_exit);
          	}
#line 1933 "p4.tab.c" /* yacc.c:1646  */
    break;


#line 1937 "p4.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 433 "p4_c.y" /* yacc.c:1906  */


/* MAIN METHOD */
int main() {
	//Parser Begins
 	yyparse();
	
	//YAY, REACHED PASS AND GET OUTTA HERE
	fprintf(stderr, "%s", pass_msg);
   	return 0;
}
 
/* YYERROR FUNCTION */
int yyerror(){
	//prints out an error for syntax
   	fprintf(stderr, "Syntax Error at Line %d\n", yylineno);
	cleanUp(); //cleans up memory alloc
   	exit(-1);
}

/* Resets the scope to NULL while freeing up its elements */
void resetScopes(){
	if(scopes){
		//loops through array of scopes
		for(int i = 0; i < numScopes; ++i){
			//free its members
			if(scopes[i].id_name) free(scopes[i].id_name);
			if(scopes[i].strVal) free(scopes[i].strVal);
			scopes[i].id_name = NULL;
			scopes[i].strVal = NULL;
			//free(scopes[i]); //frees the struct
		}
		free(scopes); //frees the scopes array
		scopes = NULL;
	}
}

/* Cleans up memory allocated variables */
void cleanUp(){
	resetScopes(); //cleans up the scope
	if(funcName) free(funcName); //if defined, then free
	if(stack) free(stack); //same here
}

/* Checks for improper memory allocation */
void checkAlloc(char *str){
	if(str == NULL){
		fprintf(stderr, "ERROR: Malloc Null at Line %d\n", yylineno);
		cleanUp(); //cleans up
		exit(-1);
	}
}

/* Resets the registers of t and a */
void resetRegs(int c){
	//var c determines whether to reset t, a, or both
	if(c == 0 || c == 1){
		for(int i = 0; i < 7; ++i) //8 registers of $t
			tRegs[i] = 0; //resets to 0
	}
	
	if(c == 1 || c == 2){
		for(int k = 0; k < 3; ++k) //4 registers of $a
			aRegs[k] = 0; //resets to 0
	}
}

/* Adds scope to scopes array */
void addToScope(char *idName, char* str, int type, int val){
	numScopes += 1; //increments # of scopes for memory alloc
	
	//Extend the memory of scopes
	scopes = realloc(scopes, sizeof *scopes * numScopes);
	
	//Sets the members of the new struct
	int ind = numScopes - 1; //index of new struct
	scopes[ind].id_name = strdup(idName);
	scopes[ind].strVal = strdup(str); //deep copies
	scopes[ind].val = val;
	scopes[ind].type = type;
}

/* Prints out the scopes */
void printScopes(){
	//Loops through the array of scopes
	for(int i = 0; i < numScopes; ++i){
		//prints the scope name and current function name
		printf("\tsw $a%d,%s_%s\n", i, funcName, scopes[i].id_name);
	}
}

/* Prints out the loading/storing of registers after/before procedure */
void loadStoreRegs(int c){
	//If loading, then set string to lw, else sw
	char ins[3];
	if(c == 1)
		strcpy(ins, "lw");
	else
		strcpy(ins, "sw");

	//prints out first load without offset
	printf("\t%s $t0, %s_registers\n", ins, funcName);

	//Int offset for registers
	int offset = 4;
	for(int i = 1; i < 8; ++i){ //loops thru t registers
		printf("\t%s $t%d, %s_registers+%d\n", ins, i, funcName, offset);
		offset += 4;
	}
	
	//Now loop through the a registers
	for(int k = 0; k < 4; ++k){
		printf("\t%s $a%d, %s_registers+%d\n", ins, k, funcName, offset);
		offset += 4; //increments offset by 4 bytes
	}
}

/* Pops the two labels off the stack */
void pop(){
	stack[top] = 0; //'frees' the top of the stack
	--top; //decrements
	stack[top] = 0; //frees the next top
	--top;

	stackSize -= 2; //decreases size

	//Reallocates the stack
	stack = realloc(stack, sizeof *stack * stackSize);
}

/* Push two labels onto the stack */
void push(){
	//Reallocates the stack for two more labels
	stackSize += 2; //increases size
	stack = realloc(stack, sizeof *stack * stackSize);
	
	//increases top and sets it to the labels
	++top;
	stack[top] = labID;
	++top;
	stack[top] = labID + 1;
}

/* Gets an available t or a register (via c var) */
int getOpenReg(int c){
	if(c == 0){ //if t regs, then loop and find one
		for(int i = 0; i < 8; ++i){
			if(tRegs[i] == 0){
				tRegs[i] = 1;
				return i; //return reg number(index)
			}
		}
	}
	else{ //else loop through the arg regs
		for(int k = 0; k < 4; ++k){
			if(aRegs[k] == 0){
				aRegs[k] = 1;
				return k; //return a reg num
			}
		}
	}

	return -1; //satisfies -Wreturn-type warning
}

/* Checks the type of the idName if in scope */
int checkType(char *idName){
	//Loops through the scopes
	for(int i = 0; i < numScopes; ++i){
		if(strcmp(scopes[i].id_name, idName) == 0)
			return scopes[i].type;
	}
	//else return -1;
	return -1;
}

/* Checks for ID within the scopes array */
int checkID(char *idName){
	//Loops thru the scopes
	for(int i = 0; i < numScopes; ++i){
		if(strcmp(scopes[i].id_name, idName) == 0) //compare check
			return scopes[i].val;
	}
	return -1;
}

/* Checks for the string val of the given ID within the scopes */
char* checkIDStr(char *idName){
	//Loops thru the scopes
	for(int i = 0; i < numScopes; ++i){
		if(strcmp(scopes[i].id_name, idName) == 0) //compare check
			return scopes[i].strVal;
	}
	return "";
}












