/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/ugbc.y"


#include "../src/ugbc.h"

int yylex();
int yyerror(Environment *, const char *);
int yydebug=0;
int errors=0;
extern int yylineno;

int yywrap() { return 1; }
 

#line 85 "src-generated/ugbc.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "ugbc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_Remark = 3,                     /* Remark  */
  YYSYMBOL_NewLine = 4,                    /* NewLine  */
  YYSYMBOL_SEMICOLON = 5,                  /* SEMICOLON  */
  YYSYMBOL_COLON = 6,                      /* COLON  */
  YYSYMBOL_COMMA = 7,                      /* COMMA  */
  YYSYMBOL_PLUS = 8,                       /* PLUS  */
  YYSYMBOL_MINUS = 9,                      /* MINUS  */
  YYSYMBOL_INC = 10,                       /* INC  */
  YYSYMBOL_DEC = 11,                       /* DEC  */
  YYSYMBOL_EQUAL = 12,                     /* EQUAL  */
  YYSYMBOL_ASSIGN = 13,                    /* ASSIGN  */
  YYSYMBOL_LT = 14,                        /* LT  */
  YYSYMBOL_LTE = 15,                       /* LTE  */
  YYSYMBOL_GT = 16,                        /* GT  */
  YYSYMBOL_GTE = 17,                       /* GTE  */
  YYSYMBOL_DISEQUAL = 18,                  /* DISEQUAL  */
  YYSYMBOL_MULTIPLICATION = 19,            /* MULTIPLICATION  */
  YYSYMBOL_DOLLAR = 20,                    /* DOLLAR  */
  YYSYMBOL_DIVISION = 21,                  /* DIVISION  */
  YYSYMBOL_RASTER = 22,                    /* RASTER  */
  YYSYMBOL_DONE = 23,                      /* DONE  */
  YYSYMBOL_AT = 24,                        /* AT  */
  YYSYMBOL_COLOR = 25,                     /* COLOR  */
  YYSYMBOL_BORDER = 26,                    /* BORDER  */
  YYSYMBOL_WAIT = 27,                      /* WAIT  */
  YYSYMBOL_NEXT = 28,                      /* NEXT  */
  YYSYMBOL_WITH = 29,                      /* WITH  */
  YYSYMBOL_BANK = 30,                      /* BANK  */
  YYSYMBOL_SPRITE = 31,                    /* SPRITE  */
  YYSYMBOL_DATA = 32,                      /* DATA  */
  YYSYMBOL_FROM = 33,                      /* FROM  */
  YYSYMBOL_OP = 34,                        /* OP  */
  YYSYMBOL_CP = 35,                        /* CP  */
  YYSYMBOL_ENABLE = 36,                    /* ENABLE  */
  YYSYMBOL_DISABLE = 37,                   /* DISABLE  */
  YYSYMBOL_HALT = 38,                      /* HALT  */
  YYSYMBOL_ECM = 39,                       /* ECM  */
  YYSYMBOL_BITMAP = 40,                    /* BITMAP  */
  YYSYMBOL_SCREEN = 41,                    /* SCREEN  */
  YYSYMBOL_ON = 42,                        /* ON  */
  YYSYMBOL_OFF = 43,                       /* OFF  */
  YYSYMBOL_ROWS = 44,                      /* ROWS  */
  YYSYMBOL_VERTICAL = 45,                  /* VERTICAL  */
  YYSYMBOL_SCROLL = 46,                    /* SCROLL  */
  YYSYMBOL_VAR = 47,                       /* VAR  */
  YYSYMBOL_AS = 48,                        /* AS  */
  YYSYMBOL_TEMPORARY = 49,                 /* TEMPORARY  */
  YYSYMBOL_XPEN = 50,                      /* XPEN  */
  YYSYMBOL_YPEN = 51,                      /* YPEN  */
  YYSYMBOL_PEEK = 52,                      /* PEEK  */
  YYSYMBOL_GOTO = 53,                      /* GOTO  */
  YYSYMBOL_HORIZONTAL = 54,                /* HORIZONTAL  */
  YYSYMBOL_MCM = 55,                       /* MCM  */
  YYSYMBOL_COMPRESS = 56,                  /* COMPRESS  */
  YYSYMBOL_EXPAND = 57,                    /* EXPAND  */
  YYSYMBOL_LOOP = 58,                      /* LOOP  */
  YYSYMBOL_REPEAT = 59,                    /* REPEAT  */
  YYSYMBOL_WHILE = 60,                     /* WHILE  */
  YYSYMBOL_TEXT = 61,                      /* TEXT  */
  YYSYMBOL_TILES = 62,                     /* TILES  */
  YYSYMBOL_COLORMAP = 63,                  /* COLORMAP  */
  YYSYMBOL_SELECT = 64,                    /* SELECT  */
  YYSYMBOL_MONOCOLOR = 65,                 /* MONOCOLOR  */
  YYSYMBOL_MULTICOLOR = 66,                /* MULTICOLOR  */
  YYSYMBOL_COLLISION = 67,                 /* COLLISION  */
  YYSYMBOL_IF = 68,                        /* IF  */
  YYSYMBOL_THEN = 69,                      /* THEN  */
  YYSYMBOL_HIT = 70,                       /* HIT  */
  YYSYMBOL_BACKGROUND = 71,                /* BACKGROUND  */
  YYSYMBOL_TO = 72,                        /* TO  */
  YYSYMBOL_RANDOM = 73,                    /* RANDOM  */
  YYSYMBOL_BYTE = 74,                      /* BYTE  */
  YYSYMBOL_WORD = 75,                      /* WORD  */
  YYSYMBOL_POSITION = 76,                  /* POSITION  */
  YYSYMBOL_CODE = 77,                      /* CODE  */
  YYSYMBOL_VARIABLES = 78,                 /* VARIABLES  */
  YYSYMBOL_MS = 79,                        /* MS  */
  YYSYMBOL_CYCLES = 80,                    /* CYCLES  */
  YYSYMBOL_S = 81,                         /* S  */
  YYSYMBOL_HASH = 82,                      /* HASH  */
  YYSYMBOL_WIDTH = 83,                     /* WIDTH  */
  YYSYMBOL_HEIGHT = 84,                    /* HEIGHT  */
  YYSYMBOL_DWORD = 85,                     /* DWORD  */
  YYSYMBOL_PEN = 86,                       /* PEN  */
  YYSYMBOL_CLEAR = 87,                     /* CLEAR  */
  YYSYMBOL_BEG = 88,                       /* BEG  */
  YYSYMBOL_END = 89,                       /* END  */
  YYSYMBOL_GAMELOOP = 90,                  /* GAMELOOP  */
  YYSYMBOL_ENDIF = 91,                     /* ENDIF  */
  YYSYMBOL_UP = 92,                        /* UP  */
  YYSYMBOL_DOWN = 93,                      /* DOWN  */
  YYSYMBOL_LEFT = 94,                      /* LEFT  */
  YYSYMBOL_RIGHT = 95,                     /* RIGHT  */
  YYSYMBOL_DEBUG = 96,                     /* DEBUG  */
  YYSYMBOL_AND = 97,                       /* AND  */
  YYSYMBOL_RANDOMIZE = 98,                 /* RANDOMIZE  */
  YYSYMBOL_GRAPHIC = 99,                   /* GRAPHIC  */
  YYSYMBOL_TEXTMAP = 100,                  /* TEXTMAP  */
  YYSYMBOL_POINT = 101,                    /* POINT  */
  YYSYMBOL_GOSUB = 102,                    /* GOSUB  */
  YYSYMBOL_RETURN = 103,                   /* RETURN  */
  YYSYMBOL_POP = 104,                      /* POP  */
  YYSYMBOL_OR = 105,                       /* OR  */
  YYSYMBOL_ELSE = 106,                     /* ELSE  */
  YYSYMBOL_NOT = 107,                      /* NOT  */
  YYSYMBOL_TRUE = 108,                     /* TRUE  */
  YYSYMBOL_FALSE = 109,                    /* FALSE  */
  YYSYMBOL_DO = 110,                       /* DO  */
  YYSYMBOL_EXIT = 111,                     /* EXIT  */
  YYSYMBOL_WEND = 112,                     /* WEND  */
  YYSYMBOL_UNTIL = 113,                    /* UNTIL  */
  YYSYMBOL_FOR = 114,                      /* FOR  */
  YYSYMBOL_STEP = 115,                     /* STEP  */
  YYSYMBOL_EVERY = 116,                    /* EVERY  */
  YYSYMBOL_MID = 117,                      /* MID  */
  YYSYMBOL_INSTR = 118,                    /* INSTR  */
  YYSYMBOL_UPPER = 119,                    /* UPPER  */
  YYSYMBOL_LOWER = 120,                    /* LOWER  */
  YYSYMBOL_STR = 121,                      /* STR  */
  YYSYMBOL_VAL = 122,                      /* VAL  */
  YYSYMBOL_STRING = 123,                   /* STRING  */
  YYSYMBOL_SPACE = 124,                    /* SPACE  */
  YYSYMBOL_FLIP = 125,                     /* FLIP  */
  YYSYMBOL_CHR = 126,                      /* CHR  */
  YYSYMBOL_ASC = 127,                      /* ASC  */
  YYSYMBOL_LEN = 128,                      /* LEN  */
  YYSYMBOL_POW = 129,                      /* POW  */
  YYSYMBOL_MOD = 130,                      /* MOD  */
  YYSYMBOL_ADD = 131,                      /* ADD  */
  YYSYMBOL_MIN = 132,                      /* MIN  */
  YYSYMBOL_MAX = 133,                      /* MAX  */
  YYSYMBOL_SGN = 134,                      /* SGN  */
  YYSYMBOL_SIGNED = 135,                   /* SIGNED  */
  YYSYMBOL_ABS = 136,                      /* ABS  */
  YYSYMBOL_MILLISECOND = 137,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 138,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 139,                    /* TICKS  */
  YYSYMBOL_BLACK = 140,                    /* BLACK  */
  YYSYMBOL_WHITE = 141,                    /* WHITE  */
  YYSYMBOL_RED = 142,                      /* RED  */
  YYSYMBOL_CYAN = 143,                     /* CYAN  */
  YYSYMBOL_VIOLET = 144,                   /* VIOLET  */
  YYSYMBOL_GREEN = 145,                    /* GREEN  */
  YYSYMBOL_BLUE = 146,                     /* BLUE  */
  YYSYMBOL_YELLOW = 147,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 148,                   /* ORANGE  */
  YYSYMBOL_BROWN = 149,                    /* BROWN  */
  YYSYMBOL_LIGHT = 150,                    /* LIGHT  */
  YYSYMBOL_DARK = 151,                     /* DARK  */
  YYSYMBOL_GREY = 152,                     /* GREY  */
  YYSYMBOL_GRAY = 153,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 154,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 155,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 156,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 157,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 158,                /* TURQUOISE  */
  YYSYMBOL_TAN = 159,                      /* TAN  */
  YYSYMBOL_PINK = 160,                     /* PINK  */
  YYSYMBOL_PEACH = 161,                    /* PEACH  */
  YYSYMBOL_OLIVE = 162,                    /* OLIVE  */
  YYSYMBOL_Identifier = 163,               /* Identifier  */
  YYSYMBOL_String = 164,                   /* String  */
  YYSYMBOL_Integer = 165,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 166,                 /* $accept  */
  YYSYMBOL_expr = 167,                     /* expr  */
  YYSYMBOL_expr_math = 168,                /* expr_math  */
  YYSYMBOL_term = 169,                     /* term  */
  YYSYMBOL_modula = 170,                   /* modula  */
  YYSYMBOL_factor = 171,                   /* factor  */
  YYSYMBOL_direct_integer = 172,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 173, /* random_definition_simple  */
  YYSYMBOL_random_definition = 174,        /* random_definition  */
  YYSYMBOL_color_enumeration = 175,        /* color_enumeration  */
  YYSYMBOL_exponential = 176,              /* exponential  */
  YYSYMBOL_position = 177,                 /* position  */
  YYSYMBOL_bank_definition_simple = 178,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 179, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 180,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 181, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 182, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 183,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 184, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 185, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 186,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 187,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 188, /* color_definition_expression  */
  YYSYMBOL_color_definition = 189,         /* color_definition  */
  YYSYMBOL_milliseconds = 190,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 191,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 192, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 193,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 194, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 195, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 196,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 197, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 198, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 199,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 200, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 201, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 202,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 203,   /* text_definition_simple  */
  YYSYMBOL_text_definition = 204,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 205,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 206, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 207,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 208, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 209, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 210,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 211, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 212, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 213,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 214,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 215,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 216,         /* gosub_definition  */
  YYSYMBOL_var_definition = 217,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 218,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 219, /* point_definition_expression  */
  YYSYMBOL_point_definition = 220,         /* point_definition  */
  YYSYMBOL_on_goto_definition = 221,       /* on_goto_definition  */
  YYSYMBOL_222_1 = 222,                    /* $@1  */
  YYSYMBOL_on_gosub_definition = 223,      /* on_gosub_definition  */
  YYSYMBOL_224_2 = 224,                    /* $@2  */
  YYSYMBOL_on_definition = 225,            /* on_definition  */
  YYSYMBOL_226_3 = 226,                    /* $@3  */
  YYSYMBOL_227_4 = 227,                    /* $@4  */
  YYSYMBOL_every_definition = 228,         /* every_definition  */
  YYSYMBOL_add_definition = 229,           /* add_definition  */
  YYSYMBOL_statement = 230,                /* statement  */
  YYSYMBOL_231_5 = 231,                    /* $@5  */
  YYSYMBOL_statements_no_linenumbers = 232, /* statements_no_linenumbers  */
  YYSYMBOL_233_6 = 233,                    /* $@6  */
  YYSYMBOL_statements_with_linenumbers = 234, /* statements_with_linenumbers  */
  YYSYMBOL_235_7 = 235,                    /* $@7  */
  YYSYMBOL_statements_complex = 236,       /* statements_complex  */
  YYSYMBOL_program = 237,                  /* program  */
  YYSYMBOL_238_8 = 238                     /* $@8  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1462

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  166
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  330
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  646

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   420


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    70,    74,    78,    81,    84,    87,    90,
      93,    96,   102,   103,   106,   113,   114,   118,   119,   123,
     130,   131,   138,   143,   146,   149,   152,   155,   158,   161,
     166,   171,   175,   179,   183,   187,   191,   195,   199,   203,
     207,   211,   215,   219,   223,   227,   231,   235,   239,   243,
     247,   251,   255,   259,   263,   267,   271,   275,   281,   284,
     287,   296,   300,   307,   311,   315,   319,   323,   327,   331,
     335,   339,   342,   345,   348,   351,   354,   357,   360,   363,
     366,   369,   372,   375,   378,   381,   384,   387,   390,   393,
     396,   399,   402,   405,   408,   411,   414,   417,   420,   423,
     426,   429,   432,   436,   442,   442,   445,   448,   451,   454,
     457,   460,   464,   467,   470,   473,   477,   480,   483,   486,
     490,   493,   496,   499,   505,   508,   511,   514,   517,   522,
     523,   526,   529,   534,   537,   542,   543,   546,   549,   554,
     557,   562,   563,   566,   569,   572,   577,   580,   583,   588,
     589,   592,   593,   594,   597,   600,   603,   608,   611,   614,
     620,   621,   624,   627,   630,   633,   636,   639,   642,   645,
     648,   651,   654,   657,   660,   663,   666,   671,   674,   677,
     680,   683,   686,   689,   692,   695,   698,   701,   704,   707,
     710,   713,   718,   719,   722,   725,   728,   731,   734,   740,
     743,   749,   750,   753,   758,   763,   764,   767,   770,   775,
     778,   783,   788,   789,   792,   795,   798,   803,   806,   812,
     813,   816,   819,   822,   825,   828,   833,   836,   839,   844,
     845,   847,   848,   851,   854,   857,   862,   869,   872,   878,
     881,   887,   890,   896,   901,   902,   905,   909,   909,   914,
     918,   918,   923,   923,   926,   926,   931,   934,   937,   942,
     945,   951,   952,   953,   954,   955,   956,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   966,   969,   972,   975,
     978,   981,   984,   987,   990,   993,   993,   998,  1001,  1004,
    1007,  1010,  1013,  1016,  1019,  1022,  1025,  1028,  1031,  1034,
    1037,  1040,  1043,  1046,  1047,  1048,  1049,  1050,  1053,  1056,
    1059,  1062,  1065,  1068,  1071,  1074,  1083,  1092,  1095,  1096,
    1100,  1101,  1101,  1105,  1105,  1112,  1113,  1114,  1115,  1119,
    1119
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "Remark", "NewLine",
  "SEMICOLON", "COLON", "COMMA", "PLUS", "MINUS", "INC", "DEC", "EQUAL",
  "ASSIGN", "LT", "LTE", "GT", "GTE", "DISEQUAL", "MULTIPLICATION",
  "DOLLAR", "DIVISION", "RASTER", "DONE", "AT", "COLOR", "BORDER", "WAIT",
  "NEXT", "WITH", "BANK", "SPRITE", "DATA", "FROM", "OP", "CP", "ENABLE",
  "DISABLE", "HALT", "ECM", "BITMAP", "SCREEN", "ON", "OFF", "ROWS",
  "VERTICAL", "SCROLL", "VAR", "AS", "TEMPORARY", "XPEN", "YPEN", "PEEK",
  "GOTO", "HORIZONTAL", "MCM", "COMPRESS", "EXPAND", "LOOP", "REPEAT",
  "WHILE", "TEXT", "TILES", "COLORMAP", "SELECT", "MONOCOLOR",
  "MULTICOLOR", "COLLISION", "IF", "THEN", "HIT", "BACKGROUND", "TO",
  "RANDOM", "BYTE", "WORD", "POSITION", "CODE", "VARIABLES", "MS",
  "CYCLES", "S", "HASH", "WIDTH", "HEIGHT", "DWORD", "PEN", "CLEAR", "BEG",
  "END", "GAMELOOP", "ENDIF", "UP", "DOWN", "LEFT", "RIGHT", "DEBUG",
  "AND", "RANDOMIZE", "GRAPHIC", "TEXTMAP", "POINT", "GOSUB", "RETURN",
  "POP", "OR", "ELSE", "NOT", "TRUE", "FALSE", "DO", "EXIT", "WEND",
  "UNTIL", "FOR", "STEP", "EVERY", "MID", "INSTR", "UPPER", "LOWER", "STR",
  "VAL", "STRING", "SPACE", "FLIP", "CHR", "ASC", "LEN", "POW", "MOD",
  "ADD", "MIN", "MAX", "SGN", "SIGNED", "ABS", "MILLISECOND",
  "MILLISECONDS", "TICKS", "BLACK", "WHITE", "RED", "CYAN", "VIOLET",
  "GREEN", "BLUE", "YELLOW", "ORANGE", "BROWN", "LIGHT", "DARK", "GREY",
  "GRAY", "MAGENTA", "PURPLE", "LAVENDER", "GOLD", "TURQUOISE", "TAN",
  "PINK", "PEACH", "OLIVE", "Identifier", "String", "Integer", "$accept",
  "expr", "expr_math", "term", "modula", "factor", "direct_integer",
  "random_definition_simple", "random_definition", "color_enumeration",
  "exponential", "position", "bank_definition_simple",
  "bank_definition_with_payload", "bank_definition",
  "raster_definition_simple", "raster_definition_expression",
  "raster_definition", "next_raster_definition_simple",
  "next_raster_definition_expression", "next_raster_definition",
  "color_definition_simple", "color_definition_expression",
  "color_definition", "milliseconds", "wait_definition_simple",
  "wait_definition_expression", "wait_definition",
  "sprite_definition_simple", "sprite_definition_expression",
  "sprite_definition", "bitmap_definition_simple",
  "bitmap_definition_expression", "bitmap_definition",
  "textmap_definition_simple", "textmap_definition_expression",
  "textmap_definition", "text_definition_simple", "text_definition",
  "tiles_definition_simple", "tiles_definition_expression",
  "tiles_definition", "colormap_definition_simple",
  "colormap_definition_expression", "colormap_definition",
  "screen_definition_simple", "screen_definition_expression",
  "screen_definition", "var_definition_simple", "goto_definition",
  "gosub_definition", "var_definition", "point_definition_simple",
  "point_definition_expression", "point_definition", "on_goto_definition",
  "$@1", "on_gosub_definition", "$@2", "on_definition", "$@3", "$@4",
  "every_definition", "add_definition", "statement", "$@5",
  "statements_no_linenumbers", "$@6", "statements_with_linenumbers", "$@7",
  "statements_complex", "program", "$@8", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420
};
#endif

#define YYPACT_NINF (-219)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-251)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -219,    11,   622,  -219,  -219,  -147,  -128,   -21,  -219,    -8,
    1009,    21,    -7,  1009,  -219,    83,   176,  1153,  -115,   -57,
    -219,  -219,  -219,   103,    29,     4,  1153,   -25,    -5,  -219,
      84,    95,  1153,  -219,  -219,    68,   164,     2,  -219,  -219,
     130,  -219,   -48,  -219,  1153,    38,   865,   179,    61,   135,
    -219,   220,   235,   238,  -219,  -219,  -219,  1009,   245,  -219,
    -219,  -219,  1009,  1009,  1009,  -219,  -219,  -219,    94,   721,
    -219,  -219,   237,   242,   243,    49,   105,   244,   248,  1153,
    -219,  -219,   249,   250,   251,   252,   253,   255,   261,   262,
     263,   264,   265,   266,   270,   271,   272,   274,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,   134,  -219,  -219,    47,     8,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,   143,
     289,  -219,  -219,   -11,    64,   180,   159,   182,    58,  -219,
    -219,  -219,  -219,  -219,   -19,   231,   -17,   -16,   -12,   -10,
     290,  -219,  -219,  -219,   149,   236,  -219,  -219,  -219,  1009,
    -219,  -219,   286,  -219,  -219,  -219,  -219,  -219,  1009,   273,
     275,  -219,  -219,  -219,   -38,  -219,    12,  -219,  -219,  -219,
    -219,  -219,  1153,  -219,  -219,  -219,  -219,  1009,  -219,  -219,
    -219,  1009,   287,  -219,  -219,  -219,   256,  -219,  -219,  1153,
    1153,  -219,  1009,  -219,  -219,  -219,   283,  -219,  -219,  -219,
    -219,  -219,  -219,  1153,  1153,  -219,  -219,  -219,   305,  -219,
    -219,   181,  -219,  1153,   316,  -219,  -219,  1153,   311,    -1,
    -219,   622,   622,   298,   299,  1009,  -219,  -219,   257,   258,
     259,   267,  -219,   303,   306,   307,   308,   309,    97,   310,
    1009,  1009,  1009,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  1153,  1153,  -219,  1153,  1153,  1153,  1153,
    1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,  1153,
    1153,  1153,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  1297,  1297,  1297,
    1297,  1297,  1297,  1297,  1297,  1297,  1297,  1297,  1297,  1297,
    1297,  -219,  -219,  -219,  1009,   323,  -219,  -219,  -219,   285,
     231,   324,   231,   325,   231,   326,   231,   327,   231,  -219,
    1153,   301,  -219,  -219,   127,   154,    -9,    77,  -219,  -219,
    -219,   319,   231,   321,  -219,  -219,   160,   166,    98,   121,
    -219,  -219,   322,  -219,  -219,  1009,  -219,  -219,  1009,  1009,
    -219,  -219,   315,   177,  -219,  -219,  -219,  -219,  -219,  1009,
    -219,   352,   354,  -219,  -219,  1009,   293,   356,  1153,   276,
     357,  1153,  -219,  1153,  -219,    -1,  -219,  -219,   202,   203,
    -219,  -219,  1153,   231,  1153,   231,   207,   208,   209,   210,
     211,   332,   333,   342,  -219,   344,   345,   346,   347,   348,
     349,   381,   382,   383,   384,   358,   359,   360,   361,   385,
     362,   363,   364,   365,   366,   395,   396,   369,   370,   180,
     180,   254,   254,   254,   254,   254,   254,   254,   254,   159,
     182,   182,  -219,   377,   378,  1009,     6,  -219,   231,  -219,
     231,  -219,   231,  -219,   231,    48,  -219,  1153,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  1153,  -219,   231,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,   231,  -219,  -219,
    -219,  -219,  -219,  -219,   246,   247,   260,   398,   371,   372,
    1153,  1153,   401,   405,  -219,   -76,   343,   268,  1153,   409,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,   277,   279,   280,  -219,  -219,  -219,  -219,
    -219,  -219,  1153,  1153,  1153,  1153,  -219,  -219,  -219,  -219,
    1153,  -219,  -219,  -219,  -219,  -219,  1153,  1153,  -219,  -219,
     269,   278,  -219,  -219,  -219,  -219,  -219,  -219,   388,  -219,
     389,  -219,   282,    72,  -219,   412,  -219,   413,   414,  -219,
     417,  -219,   415,  1009,  1153,   231,   390,   391,  1153,   231,
    -219,  -219,  1153,  -219,    40,  1153,  -219,  -219,  -219,   392,
     394,    79,   128,   400,   402,   403,  -219,  -219,   284,   288,
    -219,   404,  -219,   407,  -219,  1153,   231,   423,   432,  1153,
    -219,  -219,  -219,  -219,   427,   434,   416,   418,   335,  1153,
     441,   386,  -219,  -219,  1153,  -219,  1153,  -219,  -219,  -219,
    -219,  -219,  -219,   292,   296,   429,   430,   246,   247,  -219,
    1153,  1153,  -219,  -219,  1153,   431,  1153,  1153,   435,   436,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,   449,
    -219,  -219,  -219,  -219,  1153,  -219
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     329,     0,   319,     1,   318,     0,     0,     0,   309,     0,
       0,   297,     0,     0,   302,     0,     0,     0,   231,     0,
     284,   288,   285,     0,     0,     0,     0,     0,     0,   282,
       0,     0,     0,   278,   301,     0,     0,     0,   307,   308,
     280,   283,   290,   287,     0,     0,     0,     0,     0,     0,
     323,   320,   325,   327,   330,   276,   277,     0,     0,   135,
     136,   262,     0,     0,     0,   149,   150,   264,     0,     0,
      74,    75,     0,     0,     0,     0,     0,     0,     0,     0,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,     0,
      43,    48,    49,    50,    51,    52,    53,    56,    57,     0,
      58,    62,    60,     0,     2,    12,    15,    17,     0,    71,
      20,   160,   161,   265,     0,     0,     0,     0,     0,     0,
       0,   129,   130,   261,     0,     0,   192,   193,   266,     0,
     195,   196,   197,   201,   202,   267,   221,   222,     0,     0,
       0,   229,   230,   272,     0,   303,     0,   241,   274,   237,
     238,   304,     0,   207,   208,   209,   269,     0,   212,   213,
     270,     0,   215,   219,   220,   271,     0,   299,   300,     0,
       0,   317,     0,   205,   206,   268,     0,   244,   245,   273,
     239,   240,   305,     0,     0,   292,   293,   289,     0,   257,
     258,     0,   306,     0,     0,   275,   314,     0,     0,   319,
     321,   319,   319,     0,     0,     0,   146,   143,     0,     0,
       0,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    23,    24,    26,    28,    29,    25,
      30,    96,    22,     0,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    41,    44,    45,    46,    47,    42,    55,
      59,   151,   157,   152,   153,   158,   159,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,   155,   156,     0,     0,   141,   142,   263,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
       0,     0,   182,   183,     0,     0,     0,     0,   179,   178,
     104,     0,     0,     0,   167,   168,     0,     0,     0,     0,
     164,   163,     0,   199,   194,     0,   226,   223,     0,     0,
     252,   254,     0,     0,   286,   211,   210,   217,   214,     0,
     279,     0,     0,   204,   203,     0,     0,   291,     0,     0,
       0,     0,   315,     0,   324,   319,   326,   328,     0,     0,
     133,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      14,     5,     7,     8,     9,    10,     6,     3,     4,    16,
      18,    19,    21,     0,     0,     0,     0,   111,     0,   123,
       0,   115,     0,   119,     0,   107,   180,     0,   187,   186,
     191,   190,   185,   189,   184,   188,     0,   165,     0,   172,
     171,   176,   175,   170,   174,   169,   173,     0,   200,   198,
     227,   224,   228,   225,     0,     0,     0,   232,     0,     0,
       0,     0,     0,     0,   281,     0,     0,     0,     0,   259,
     316,   322,   134,   132,   148,   145,   147,   144,    70,    63,
      65,    69,    67,     0,     0,     0,    73,    72,    77,    76,
      79,    78,     0,     0,     0,     0,    86,    87,    88,    95,
       0,    89,    90,    91,    92,    93,     0,     0,   100,   101,
       0,     0,   139,   137,   108,   121,   113,   116,   110,   122,
     114,   118,     0,     0,   177,     0,   162,     0,   246,   253,
     249,   255,   233,     0,     0,     0,     0,     0,     0,     0,
     294,   295,     0,   256,     0,     0,    64,    66,    68,     0,
       0,     0,     0,     0,     0,     0,   140,   138,     0,     0,
     124,   109,   120,   112,   117,     0,     0,     0,     0,     0,
     235,   234,   218,   216,     0,     0,     0,     0,   296,     0,
       0,     0,    80,    81,     0,    82,     0,    84,    94,    99,
      98,   126,   128,     0,     0,     0,     0,     0,     0,   236,
       0,     0,   243,   242,     0,     0,     0,     0,     0,     0,
     125,   127,   181,   166,   248,   251,   310,   311,   298,     0,
     312,   260,    83,    85,     0,   313
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -219,   -13,   -58,   -23,   172,   -32,   145,  -219,  -219,  -219,
     173,   329,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,   350,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -145,  -219,  -142,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -218,  -219,  -219,  -219,
      53,  -219,  -219
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   123,   124,   125,   126,   127,   128,   250,   251,   129,
     130,   331,   141,   142,   143,    59,    60,    61,   306,   307,
     308,    65,    66,    67,   286,   131,   132,   133,   146,   147,
     148,   153,   154,   155,   193,   194,   195,   175,   176,   178,
     179,   180,   183,   184,   185,   161,   162,   163,   167,   171,
     202,   168,   197,   198,   199,   549,   587,   551,   588,   165,
     474,   475,   212,   215,    51,   172,    52,   375,    53,   219,
      54,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     144,   374,     4,    57,   164,   304,    76,   310,   312,     5,
       6,     3,   314,   186,   316,   350,    55,   135,    62,   191,
     204,     7,     8,    63,     9,   136,    10,    11,   181,    12,
      13,   207,   352,   211,    76,    56,   452,    14,   534,    15,
      16,    17,   137,   134,   223,   453,    18,   599,   166,   226,
     228,   230,    19,   177,   353,   535,   239,    20,    21,    22,
      23,    24,    25,    64,   351,   187,   255,    26,   281,   282,
     138,   139,   287,   288,   243,   600,   289,   542,   290,   291,
     292,   293,   294,   536,   537,   188,   604,    27,    28,   560,
      29,   182,   192,    30,    31,    32,   543,    33,    34,    35,
      36,    37,    38,    39,   581,    40,   169,   149,   170,    41,
      42,    43,    44,    45,   605,    46,    47,   205,   189,   150,
     151,   582,   454,   244,   245,   246,   283,   284,   285,   190,
      48,   455,   247,   248,   249,   606,   343,   281,   301,   173,
     174,   216,    58,   463,   305,   346,   311,   313,   217,   583,
     584,   315,   464,   317,   277,   218,   140,   491,   145,   354,
     278,   295,    49,   607,   355,   200,   465,   201,   357,   296,
     152,   391,   392,   319,   320,   466,   361,   362,   298,   363,
     299,   321,   393,   448,   449,   322,   323,   206,   196,   273,
     366,   367,   274,   275,   324,   283,   284,   302,   203,   276,
     370,   208,   224,   325,   372,   326,   327,   227,   229,   231,
     450,   451,   380,   213,   328,   329,   459,   460,   156,   157,
     158,   159,   461,   462,   214,   330,   220,   395,   397,   399,
     160,   421,   422,   423,   424,   425,   426,   427,   428,   221,
     401,   402,   222,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   232,
     319,   332,   287,   288,   419,   420,   430,   431,   333,   225,
     252,   240,   334,   335,   376,   377,   241,   242,   253,   272,
     309,   336,   254,   256,   257,   258,   259,   260,   279,   261,
     337,   433,   338,   339,   344,   262,   263,   264,   265,   266,
     267,   340,   341,   347,   268,   269,   270,   446,   271,   280,
     297,   300,   330,    76,   318,   345,   359,   365,   368,   348,
     369,   349,   356,   371,   373,   360,   358,   378,   379,   382,
     383,   384,   468,   436,   447,   470,   472,   364,   386,   385,
     477,   387,   388,   389,   390,   394,   478,   435,   438,   440,
     442,   444,   482,   456,   458,   486,   467,   476,   489,   480,
     490,   481,   484,   485,   488,   492,   493,   503,   504,   494,
     381,   496,   498,   499,   500,   501,   502,   505,   487,   506,
     507,   508,   509,   510,   511,   396,   398,   400,   512,   513,
     514,   515,   520,   516,   517,   518,   519,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   558,   548,
     550,   553,   559,   554,   555,   562,   565,   578,   579,   585,
     586,  -247,   532,   552,  -250,   594,   595,   602,   589,   603,
     617,   563,   576,   613,   544,   608,   614,   609,   610,   618,
     620,   577,   566,   545,   567,   568,   580,   621,   611,   434,
     624,   622,   612,   623,   626,   437,   630,   439,   627,   441,
     631,   443,   644,   445,   632,   633,   639,   556,   557,   429,
     642,   643,   634,   432,   342,   564,   635,   457,   303,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     469,     0,     0,   471,   473,     0,     0,     0,     0,   569,
     570,   571,   572,     0,   479,     0,     0,   573,     0,     0,
     483,     0,     0,   574,   575,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   495,     0,
     497,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     590,   592,     0,     0,     0,   596,     0,     0,     0,   598,
       0,     0,   601,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   615,     0,     0,     0,   619,     0,     0,     0,
     533,     0,     0,   538,     0,   539,   625,   540,     0,   541,
       0,   628,     0,   629,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   546,     0,     0,     0,   636,   637,     0,
       0,   638,   547,   640,   641,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     0,     0,     0,     0,
     561,   645,     5,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     9,     0,    10,
      11,     0,    12,    13,     0,     0,     0,     0,     0,     0,
      14,     0,    15,    16,    17,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,   591,     0,
     593,     0,     0,     0,   597,     0,     0,     0,     0,     0,
      27,    28,     0,    29,     0,     0,    30,    31,    32,     0,
      33,    34,    35,    36,    37,    38,    39,     0,    40,     0,
      68,   616,    41,    42,    43,    44,    45,     0,    46,    47,
       0,     0,     0,     0,     0,     0,   233,     0,     0,     0,
       0,     0,     0,    48,     0,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,     0,    50,    73,     0,
       0,    74,     0,     0,    75,   234,   235,   236,     0,     0,
       0,     0,     0,     0,     0,     0,   237,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,     0,     0,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,     0,     0,    94,    95,    96,   238,    97,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    68,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,     0,     0,     0,     0,     0,     0,   209,   210,     0,
       0,     0,     0,     0,     0,    70,    71,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    73,     0,     0,    74,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    80,    81,     0,     0,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,     0,     0,    94,    95,    96,
       0,    97,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    68,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
      71,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,     0,     0,    74,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    80,    81,     0,
       0,     0,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,    94,    95,    96,     0,    97,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    68,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    71,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,     0,     0,    74,     0,     0,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,    80,    81,     0,     0,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,     0,     0,     0,    94,    95,    96,     0,    97,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    68,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,    71,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,     0,     0,    74,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,    94,
      95,    96,     0,    97,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122
};

static const yytype_int16 yycheck[] =
{
      13,   219,     3,    24,    17,    24,    82,    24,    24,    10,
      11,     0,    24,    26,    24,    53,   163,    24,    26,    32,
      68,    22,    23,    31,    25,    32,    27,    28,    24,    30,
      31,    44,    20,    46,    82,   163,    45,    38,    32,    40,
      41,    42,    49,    22,    57,    54,    47,     7,   163,    62,
      63,    64,    53,    24,    42,    49,    69,    58,    59,    60,
      61,    62,    63,    71,   102,    90,    79,    68,    79,    80,
      77,    78,     8,     9,    25,    35,    12,    29,    14,    15,
      16,    17,    18,    77,    78,    90,     7,    88,    89,   165,
      91,    87,    24,    94,    95,    96,    48,    98,    99,   100,
     101,   102,   103,   104,    32,   106,   163,    24,   165,   110,
     111,   112,   113,   114,    35,   116,   117,   165,    34,    36,
      37,    49,    45,    74,    75,    76,   137,   138,   139,    34,
     131,    54,    83,    84,    85,     7,   149,    79,    80,    36,
      37,     6,   163,    45,   163,   158,   163,   163,    13,    77,
      78,   163,    54,   163,   146,    20,   163,   375,    13,   172,
     152,    97,   163,    35,   177,   163,    45,   165,   181,   105,
      87,    74,    75,    24,    25,    54,   189,   190,    19,   192,
      21,    32,    85,    56,    57,    36,    37,    42,    24,   142,
     203,   204,   145,   146,    45,   137,   138,   139,    68,   152,
     213,   163,    57,    54,   217,    56,    57,    62,    63,    64,
      56,    57,   225,    34,    65,    66,    56,    57,    42,    43,
      44,    45,    56,    57,   163,    76,     6,   240,   241,   242,
      54,   289,   290,   291,   292,   293,   294,   295,   296,     4,
     253,   254,     4,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   165,
      24,    25,     8,     9,   287,   288,   298,   299,    32,    24,
     165,    34,    36,    37,   221,   222,    34,    34,    34,   145,
     135,    45,    34,    34,    34,    34,    34,    34,   145,    34,
      54,   304,    56,    57,   149,    34,    34,    34,    34,    34,
      34,    65,    66,   158,    34,    34,    34,   320,    34,    20,
     130,   129,    76,    82,    24,    29,    29,    34,    13,    46,
     139,    46,   177,     7,    13,    69,   181,    29,    29,    72,
      72,    72,   345,    48,    33,   348,   349,   192,    35,    72,
     163,    35,    35,    35,    35,    35,   359,    24,    24,    24,
      24,    24,   365,    34,    33,   368,    34,    42,   371,     7,
     373,     7,    69,     7,     7,   163,   163,    35,    35,   382,
     225,   384,   165,   165,   165,   165,   165,    35,   102,    35,
      35,    35,    35,    35,    35,   240,   241,   242,     7,     7,
       7,     7,     7,    35,    35,    35,    35,    35,    35,    35,
      35,    35,     7,     7,    35,    35,    29,    29,     7,   163,
     163,    13,     7,    42,    42,    72,     7,    29,    29,     7,
       7,     7,   435,   163,     7,    35,    35,    35,    13,    35,
       7,   163,   163,    29,   447,    35,    29,    35,    35,     7,
      13,   163,   165,   456,   165,   165,   164,    13,   164,   304,
     115,    35,   164,    35,    13,   310,   164,   312,    72,   314,
     164,   316,    13,   318,    35,    35,    35,   480,   481,   297,
      35,    35,   617,   300,   145,   488,   618,   332,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     345,    -1,    -1,   348,   349,    -1,    -1,    -1,    -1,   512,
     513,   514,   515,    -1,   359,    -1,    -1,   520,    -1,    -1,
     365,    -1,    -1,   526,   527,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   383,    -1,
     385,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     553,   554,    -1,    -1,    -1,   558,    -1,    -1,    -1,   562,
      -1,    -1,   565,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   585,    -1,    -1,    -1,   589,    -1,    -1,    -1,
     435,    -1,    -1,   438,    -1,   440,   599,   442,    -1,   444,
      -1,   604,    -1,   606,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   458,    -1,    -1,    -1,   620,   621,    -1,
      -1,   624,   467,   626,   627,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
     485,   644,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    -1,    25,    -1,    27,
      28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   553,    -1,
     555,    -1,    -1,    -1,   559,    -1,    -1,    -1,    -1,    -1,
      88,    89,    -1,    91,    -1,    -1,    94,    95,    96,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,   106,    -1,
       9,   586,   110,   111,   112,   113,   114,    -1,   116,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,    -1,   165,    67,    -1,
      -1,    70,    -1,    -1,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,   135,   136,    -1,    -1,
      -1,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     9,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,   136,    -1,    -1,    -1,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     9,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,    -1,    -1,    -1,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     9,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,
      -1,    -1,    -1,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     9,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,    -1,    -1,    -1,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   237,   238,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    88,    89,    91,
      94,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     106,   110,   111,   112,   113,   114,   116,   117,   131,   163,
     165,   230,   232,   234,   236,   163,   163,    24,   163,   181,
     182,   183,    26,    31,    71,   187,   188,   189,     9,    34,
      50,    51,    52,    67,    70,    73,    82,    94,    95,   107,
     108,   109,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   132,   133,   134,   136,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   167,   168,   169,   170,   171,   172,   175,
     176,   191,   192,   193,    22,    24,    32,    49,    77,    78,
     163,   178,   179,   180,   167,   172,   194,   195,   196,    24,
      36,    37,    87,   197,   198,   199,    42,    43,    44,    45,
      54,   211,   212,   213,   167,   225,   163,   214,   217,   163,
     165,   215,   231,    36,    37,   203,   204,    24,   205,   206,
     207,    24,    87,   208,   209,   210,   167,    90,    90,    34,
      34,   167,    24,   200,   201,   202,    24,   218,   219,   220,
     163,   165,   216,    68,    68,   165,   172,   167,   163,    42,
      43,   167,   228,    34,   163,   229,     6,    13,    20,   235,
       6,     4,     4,   167,   172,    24,   167,   172,   167,   172,
     167,   172,   165,    25,    74,    75,    76,    85,   135,   167,
      34,    34,    34,    25,    74,    75,    76,    83,    84,    85,
     173,   174,   165,    34,    34,   167,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,   145,   142,   145,   146,   152,   146,   152,   145,
      20,    79,    80,   137,   138,   139,   190,     8,     9,    12,
      14,    15,    16,    17,    18,    97,   105,   130,    19,    21,
     129,    80,   139,   190,    24,   163,   184,   185,   186,   172,
      24,   163,    24,   163,    24,   163,    24,   163,    24,    24,
      25,    32,    36,    37,    45,    54,    56,    57,    65,    66,
      76,   177,    25,    32,    36,    37,    45,    54,    56,    57,
      65,    66,   177,   167,   172,    29,   167,   172,    46,    46,
      53,   102,    20,    42,   167,   167,   172,   167,   172,    29,
      69,   167,   167,   167,   172,    34,   167,   167,    13,   139,
     167,     7,   167,    13,   232,   233,   236,   236,    29,    29,
     167,   172,    72,    72,    72,    72,    35,    35,    35,    35,
      35,    74,    75,    85,    35,   167,   172,   167,   172,   167,
     172,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   169,
     169,   168,   168,   168,   168,   168,   168,   168,   168,   170,
     171,   171,   176,   167,   172,    24,    48,   172,    24,   172,
      24,   172,    24,   172,    24,   172,   167,    33,    56,    57,
      56,    57,    45,    54,    45,    54,    34,   172,    33,    56,
      57,    56,    57,    45,    54,    45,    54,    34,   167,   172,
     167,   172,   167,   172,   226,   227,    42,   163,   167,   172,
       7,     7,   167,   172,    69,     7,   167,   102,     7,   167,
     167,   232,   163,   163,   167,   172,   167,   172,   165,   165,
     165,   165,   165,    35,    35,    35,    35,    35,    35,    35,
      35,    35,     7,     7,     7,     7,    35,    35,    35,    35,
       7,    35,    35,    35,    35,    35,     7,     7,    35,    35,
      29,    29,   167,   172,    32,    49,    77,    78,   172,   172,
     172,   172,    29,    48,   167,   167,   172,   172,   163,   221,
     163,   223,   163,    13,    42,    42,   167,   167,     7,     7,
     165,   172,    72,   163,   167,     7,   165,   165,   165,   167,
     167,   167,   167,   167,   167,   167,   163,   163,    29,    29,
     164,    32,    49,    77,    78,     7,     7,   222,   224,    13,
     167,   172,   167,   172,    35,    35,   167,   172,   167,     7,
      35,   167,    35,    35,     7,    35,     7,    35,    35,    35,
      35,   164,   164,    29,    29,   167,   172,     7,     7,   167,
      13,    13,    35,    35,   115,   167,    13,    72,   167,   167,
     164,   164,    35,    35,   221,   223,   167,   167,   167,    35,
     167,   167,    35,    35,    13,   167
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   166,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   168,   168,   168,   169,   169,   170,   170,   170,
     171,   171,   172,   173,   173,   173,   173,   173,   173,   173,
     174,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   177,   177,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   179,   179,   179,   179,   179,   180,
     180,   181,   181,   182,   182,   183,   183,   184,   184,   185,
     185,   186,   186,   187,   187,   187,   188,   188,   188,   189,
     189,   190,   190,   190,   191,   191,   191,   192,   192,   192,
     193,   193,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   196,   196,   197,   197,   197,   197,   197,   198,
     198,   199,   199,   200,   201,   202,   202,   203,   203,   204,
     205,   206,   207,   207,   208,   208,   208,   209,   209,   210,
     210,   211,   211,   211,   211,   211,   212,   212,   212,   213,
     213,   214,   214,   214,   214,   214,   214,   215,   215,   216,
     216,   217,   218,   219,   220,   220,   221,   222,   221,   223,
     224,   223,   226,   225,   227,   225,   228,   228,   228,   229,
     229,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   231,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     232,   233,   232,   235,   234,   236,   236,   236,   236,   238,
     237
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     3,     3,     1,     3,     1,     3,     3,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     2,
       1,     2,     1,     4,     5,     4,     5,     4,     5,     4,
       4,     1,     4,     4,     1,     1,     4,     4,     4,     4,
       6,     6,     6,     8,     6,     8,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     2,     3,     6,     6,
       4,     4,     1,     1,     1,     1,     2,     3,     4,     5,
       4,     3,     5,     4,     4,     3,     4,     5,     4,     3,
       5,     4,     4,     3,     5,     7,     6,     7,     6,     1,
       1,     3,     4,     3,     4,     1,     1,     3,     4,     3,
       4,     1,     1,     2,     4,     4,     2,     4,     4,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     2,
       1,     1,     4,     2,     2,     3,     7,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     2,     2,
       3,     7,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     2,     1,     1,     1,     3,     2,
       3,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     2,     1,     5,     2,     5,     1,
       1,     1,     1,     2,     3,     3,     2,     3,     3,     1,
       1,     0,     3,     4,     5,     5,     6,     1,     1,     1,
       1,     1,     6,     6,     1,     1,     1,     0,     4,     1,
       0,     4,     0,     4,     0,     4,     4,     1,     1,     3,
       7,     2,     2,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     3,
       1,     4,     1,     1,     1,     0,     3,     1,     1,     2,
       1,     3,     2,     2,     5,     5,     6,     1,     8,     2,
       2,     1,     1,     2,     2,     2,     2,     1,     1,     1,
       8,     8,     8,    10,     2,     3,     4,     2,     1,     0,
       1,     0,     4,     0,     3,     1,     3,     1,     3,     0,
       2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (_environment, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, _environment); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void * _environment)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (_environment);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void * _environment)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, _environment);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, void * _environment)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), _environment);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, _environment); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void * _environment)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (_environment);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void * _environment)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* expr: expr_math AND expr_math  */
#line 70 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2341 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 74 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2350 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 78 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2358 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 81 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2366 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 84 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2374 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 87 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2382 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 90 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2390 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 93 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2398 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 96 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2406 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 103 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2414 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 106 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2423 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 119 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2432 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 123 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2441 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 131 "src/ugbc.y"
                               {
        (yyval.string) = variable_pow( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2450 "src-generated/ugbc.tab.c"
    break;

  case 22: /* direct_integer: HASH Integer  */
#line 138 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2458 "src-generated/ugbc.tab.c"
    break;

  case 23: /* random_definition_simple: BYTE  */
#line 143 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2466 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: WORD  */
#line 146 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2474 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: DWORD  */
#line 149 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2482 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: POSITION  */
#line 152 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2490 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: COLOR  */
#line 155 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2498 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: WIDTH  */
#line 158 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2506 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: HEIGHT  */
#line 161 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2514 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition: random_definition_simple  */
#line 166 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2522 "src-generated/ugbc.tab.c"
    break;

  case 31: /* color_enumeration: BLACK  */
#line 171 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2531 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: WHITE  */
#line 175 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2540 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: RED  */
#line 179 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2549 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: CYAN  */
#line 183 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2558 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: VIOLET  */
#line 187 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2567 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: GREEN  */
#line 191 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2576 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: BLUE  */
#line 195 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2585 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: YELLOW  */
#line 199 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2594 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: ORANGE  */
#line 203 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2603 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: BROWN  */
#line 207 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2612 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: LIGHT RED  */
#line 211 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2621 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: DARK GREY  */
#line 215 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2630 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: GREY  */
#line 219 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2639 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: LIGHT GREEN  */
#line 223 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2648 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT BLUE  */
#line 227 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2657 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT GREY  */
#line 231 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2666 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: DARK BLUE  */
#line 235 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2675 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: MAGENTA  */
#line 239 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2684 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: PURPLE  */
#line 243 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2693 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: LAVENDER  */
#line 247 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2702 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: GOLD  */
#line 251 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2711 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: TURQUOISE  */
#line 255 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2720 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TAN  */
#line 259 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2729 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: YELLOW GREEN  */
#line 263 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2738 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: OLIVE GREEN  */
#line 267 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2747 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: PINK  */
#line 271 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2756 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PEACH  */
#line 275 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2765 "src-generated/ugbc.tab.c"
    break;

  case 58: /* exponential: Identifier  */
#line 281 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2773 "src-generated/ugbc.tab.c"
    break;

  case 59: /* exponential: Identifier DOLLAR  */
#line 284 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[-1].string);
      }
#line 2781 "src-generated/ugbc.tab.c"
    break;

  case 60: /* exponential: Integer  */
#line 287 "src/ugbc.y"
              { 
        if ( (yyvsp[0].integer) < 0 ) {
            (yyval.string) = variable_temporary( _environment, VT_SWORD, "(signed integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        } else {
            (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        }
      }
#line 2795 "src-generated/ugbc.tab.c"
    break;

  case 61: /* exponential: MINUS Integer  */
#line 296 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 2804 "src-generated/ugbc.tab.c"
    break;

  case 62: /* exponential: String  */
#line 300 "src/ugbc.y"
             { 
        outline1("; (expr string: \"%s\")", (yyvsp[0].string) );
        (yyval.string) = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", (yyval.string) );
        variable_store_string( _environment, (yyval.string), (yyvsp[0].string) );
        outline2("; variable stored: %s = %s", (yyval.string), (yyvsp[0].string) );
      }
#line 2816 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: OP BYTE CP Integer  */
#line 307 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2825 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: OP SIGNED BYTE CP Integer  */
#line 311 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2834 "src-generated/ugbc.tab.c"
    break;

  case 65: /* exponential: OP WORD CP Integer  */
#line 315 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2843 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: OP SIGNED WORD CP Integer  */
#line 319 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2852 "src-generated/ugbc.tab.c"
    break;

  case 67: /* exponential: OP DWORD CP Integer  */
#line 323 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2861 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP SIGNED DWORD CP Integer  */
#line 327 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2870 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP POSITION CP Integer  */
#line 331 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2879 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP COLOR CP Integer  */
#line 335 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2888 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: color_enumeration  */
#line 339 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2896 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: PEEK OP direct_integer CP  */
#line 342 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2904 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: PEEK OP expr CP  */
#line 345 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 2912 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: XPEN  */
#line 348 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 2920 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: YPEN  */
#line 351 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 2928 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: COLLISION OP direct_integer CP  */
#line 354 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2936 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: COLLISION OP expr CP  */
#line 357 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2944 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: HIT OP direct_integer CP  */
#line 360 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2952 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: HIT OP expr CP  */
#line 363 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2960 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: LEFT OP expr COMMA expr CP  */
#line 366 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2968 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 369 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2976 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: MID OP expr COMMA expr CP  */
#line 372 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 2984 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 375 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2992 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: INSTR OP expr COMMA expr CP  */
#line 378 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3000 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 381 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3008 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: UPPER OP expr CP  */
#line 384 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3016 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: LOWER OP expr CP  */
#line 387 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3024 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: STR OP expr CP  */
#line 390 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3032 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: SPACE OP expr CP  */
#line 393 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3040 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: FLIP OP expr CP  */
#line 396 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3048 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: CHR OP expr CP  */
#line 399 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3056 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: ASC OP expr CP  */
#line 402 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3064 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: LEN OP expr CP  */
#line 405 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3072 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: STRING OP expr COMMA expr CP  */
#line 408 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3080 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: VAL OP expr CP  */
#line 411 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3088 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: RANDOM random_definition  */
#line 414 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3096 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: OP expr CP  */
#line 417 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3104 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: MAX OP expr COMMA expr CP  */
#line 420 "src/ugbc.y"
                                {
        (yyval.string) = variable_max( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3112 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: MIN OP expr COMMA expr CP  */
#line 423 "src/ugbc.y"
                                {
        (yyval.string) = variable_min( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3120 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: SGN OP expr CP  */
#line 426 "src/ugbc.y"
                     {
        (yyval.string) = variable_sgn( _environment, (yyvsp[-1].string) )->name;
    }
#line 3128 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: ABS OP expr CP  */
#line 429 "src/ugbc.y"
                     {
        (yyval.string) = variable_abs( _environment, (yyvsp[-1].string) )->name;
    }
#line 3136 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: TRUE  */
#line 432 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3145 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: FALSE  */
#line 436 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3154 "src-generated/ugbc.tab.c"
    break;

  case 106: /* bank_definition_simple: AT direct_integer  */
#line 445 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3162 "src-generated/ugbc.tab.c"
    break;

  case 107: /* bank_definition_simple: Identifier AT direct_integer  */
#line 448 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3170 "src-generated/ugbc.tab.c"
    break;

  case 108: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 451 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3178 "src-generated/ugbc.tab.c"
    break;

  case 109: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 454 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3186 "src-generated/ugbc.tab.c"
    break;

  case 110: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 457 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3194 "src-generated/ugbc.tab.c"
    break;

  case 111: /* bank_definition_simple: DATA AT direct_integer  */
#line 460 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3202 "src-generated/ugbc.tab.c"
    break;

  case 112: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 464 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3210 "src-generated/ugbc.tab.c"
    break;

  case 113: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 467 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3218 "src-generated/ugbc.tab.c"
    break;

  case 114: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 470 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3226 "src-generated/ugbc.tab.c"
    break;

  case 115: /* bank_definition_simple: CODE AT direct_integer  */
#line 473 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3234 "src-generated/ugbc.tab.c"
    break;

  case 116: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 477 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3242 "src-generated/ugbc.tab.c"
    break;

  case 117: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 480 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3250 "src-generated/ugbc.tab.c"
    break;

  case 118: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 483 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3258 "src-generated/ugbc.tab.c"
    break;

  case 119: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 486 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3266 "src-generated/ugbc.tab.c"
    break;

  case 120: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 490 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3274 "src-generated/ugbc.tab.c"
    break;

  case 121: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 493 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3282 "src-generated/ugbc.tab.c"
    break;

  case 122: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 496 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3290 "src-generated/ugbc.tab.c"
    break;

  case 123: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 499 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3298 "src-generated/ugbc.tab.c"
    break;

  case 124: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 505 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3306 "src-generated/ugbc.tab.c"
    break;

  case 125: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 508 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3314 "src-generated/ugbc.tab.c"
    break;

  case 126: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 511 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3322 "src-generated/ugbc.tab.c"
    break;

  case 127: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 514 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3330 "src-generated/ugbc.tab.c"
    break;

  case 128: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 517 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3338 "src-generated/ugbc.tab.c"
    break;

  case 131: /* raster_definition_simple: Identifier AT direct_integer  */
#line 526 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3346 "src-generated/ugbc.tab.c"
    break;

  case 132: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 529 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3354 "src-generated/ugbc.tab.c"
    break;

  case 133: /* raster_definition_expression: Identifier AT expr  */
#line 534 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3362 "src-generated/ugbc.tab.c"
    break;

  case 134: /* raster_definition_expression: AT expr WITH Identifier  */
#line 537 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3370 "src-generated/ugbc.tab.c"
    break;

  case 137: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 546 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3378 "src-generated/ugbc.tab.c"
    break;

  case 138: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 549 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3386 "src-generated/ugbc.tab.c"
    break;

  case 139: /* next_raster_definition_expression: Identifier AT expr  */
#line 554 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3394 "src-generated/ugbc.tab.c"
    break;

  case 140: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 557 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3402 "src-generated/ugbc.tab.c"
    break;

  case 143: /* color_definition_simple: BORDER direct_integer  */
#line 566 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3410 "src-generated/ugbc.tab.c"
    break;

  case 144: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 569 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3418 "src-generated/ugbc.tab.c"
    break;

  case 145: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 572 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3426 "src-generated/ugbc.tab.c"
    break;

  case 146: /* color_definition_expression: BORDER expr  */
#line 577 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3434 "src-generated/ugbc.tab.c"
    break;

  case 147: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 580 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3442 "src-generated/ugbc.tab.c"
    break;

  case 148: /* color_definition_expression: SPRITE expr TO expr  */
#line 583 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3450 "src-generated/ugbc.tab.c"
    break;

  case 154: /* wait_definition_simple: direct_integer CYCLES  */
#line 597 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3458 "src-generated/ugbc.tab.c"
    break;

  case 155: /* wait_definition_simple: direct_integer TICKS  */
#line 600 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3466 "src-generated/ugbc.tab.c"
    break;

  case 156: /* wait_definition_simple: direct_integer milliseconds  */
#line 603 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3474 "src-generated/ugbc.tab.c"
    break;

  case 157: /* wait_definition_expression: expr CYCLES  */
#line 608 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3482 "src-generated/ugbc.tab.c"
    break;

  case 158: /* wait_definition_expression: expr TICKS  */
#line 611 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3490 "src-generated/ugbc.tab.c"
    break;

  case 159: /* wait_definition_expression: expr milliseconds  */
#line 614 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3498 "src-generated/ugbc.tab.c"
    break;

  case 162: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 624 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3506 "src-generated/ugbc.tab.c"
    break;

  case 163: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 627 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3514 "src-generated/ugbc.tab.c"
    break;

  case 164: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 630 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3522 "src-generated/ugbc.tab.c"
    break;

  case 165: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 633 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3530 "src-generated/ugbc.tab.c"
    break;

  case 166: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 636 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3538 "src-generated/ugbc.tab.c"
    break;

  case 167: /* sprite_definition_simple: direct_integer ENABLE  */
#line 639 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3546 "src-generated/ugbc.tab.c"
    break;

  case 168: /* sprite_definition_simple: direct_integer DISABLE  */
#line 642 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3554 "src-generated/ugbc.tab.c"
    break;

  case 169: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 645 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3562 "src-generated/ugbc.tab.c"
    break;

  case 170: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 648 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3570 "src-generated/ugbc.tab.c"
    break;

  case 171: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 651 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3578 "src-generated/ugbc.tab.c"
    break;

  case 172: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 654 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3586 "src-generated/ugbc.tab.c"
    break;

  case 173: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 657 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3594 "src-generated/ugbc.tab.c"
    break;

  case 174: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 660 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3602 "src-generated/ugbc.tab.c"
    break;

  case 175: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 663 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3610 "src-generated/ugbc.tab.c"
    break;

  case 176: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 666 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3618 "src-generated/ugbc.tab.c"
    break;

  case 177: /* sprite_definition_expression: expr DATA FROM expr  */
#line 671 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3626 "src-generated/ugbc.tab.c"
    break;

  case 178: /* sprite_definition_expression: expr MULTICOLOR  */
#line 674 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3634 "src-generated/ugbc.tab.c"
    break;

  case 179: /* sprite_definition_expression: expr MONOCOLOR  */
#line 677 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3642 "src-generated/ugbc.tab.c"
    break;

  case 180: /* sprite_definition_expression: expr COLOR expr  */
#line 680 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3650 "src-generated/ugbc.tab.c"
    break;

  case 181: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 683 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3658 "src-generated/ugbc.tab.c"
    break;

  case 182: /* sprite_definition_expression: expr ENABLE  */
#line 686 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3666 "src-generated/ugbc.tab.c"
    break;

  case 183: /* sprite_definition_expression: expr DISABLE  */
#line 689 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3674 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 692 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3682 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 695 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3690 "src-generated/ugbc.tab.c"
    break;

  case 186: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 698 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3698 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 701 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3706 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 704 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3714 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 707 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3722 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 710 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3730 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 713 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3738 "src-generated/ugbc.tab.c"
    break;

  case 194: /* bitmap_definition_simple: AT direct_integer  */
#line 722 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3746 "src-generated/ugbc.tab.c"
    break;

  case 195: /* bitmap_definition_simple: ENABLE  */
#line 725 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3754 "src-generated/ugbc.tab.c"
    break;

  case 196: /* bitmap_definition_simple: DISABLE  */
#line 728 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 3762 "src-generated/ugbc.tab.c"
    break;

  case 197: /* bitmap_definition_simple: CLEAR  */
#line 731 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 3770 "src-generated/ugbc.tab.c"
    break;

  case 198: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 734 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 3778 "src-generated/ugbc.tab.c"
    break;

  case 199: /* bitmap_definition_expression: AT expr  */
#line 740 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3786 "src-generated/ugbc.tab.c"
    break;

  case 200: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 743 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 3794 "src-generated/ugbc.tab.c"
    break;

  case 203: /* textmap_definition_simple: AT direct_integer  */
#line 753 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3802 "src-generated/ugbc.tab.c"
    break;

  case 204: /* textmap_definition_expression: AT expr  */
#line 758 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3810 "src-generated/ugbc.tab.c"
    break;

  case 207: /* text_definition_simple: ENABLE  */
#line 767 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3818 "src-generated/ugbc.tab.c"
    break;

  case 208: /* text_definition_simple: DISABLE  */
#line 770 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 3826 "src-generated/ugbc.tab.c"
    break;

  case 210: /* tiles_definition_simple: AT direct_integer  */
#line 778 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 3834 "src-generated/ugbc.tab.c"
    break;

  case 211: /* tiles_definition_expression: AT expr  */
#line 783 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 3842 "src-generated/ugbc.tab.c"
    break;

  case 214: /* colormap_definition_simple: AT direct_integer  */
#line 792 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 3850 "src-generated/ugbc.tab.c"
    break;

  case 215: /* colormap_definition_simple: CLEAR  */
#line 795 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 3858 "src-generated/ugbc.tab.c"
    break;

  case 216: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 798 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3866 "src-generated/ugbc.tab.c"
    break;

  case 217: /* colormap_definition_expression: AT expr  */
#line 803 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3874 "src-generated/ugbc.tab.c"
    break;

  case 218: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 806 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3882 "src-generated/ugbc.tab.c"
    break;

  case 221: /* screen_definition_simple: ON  */
#line 816 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 3890 "src-generated/ugbc.tab.c"
    break;

  case 222: /* screen_definition_simple: OFF  */
#line 819 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 3898 "src-generated/ugbc.tab.c"
    break;

  case 223: /* screen_definition_simple: ROWS direct_integer  */
#line 822 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 3906 "src-generated/ugbc.tab.c"
    break;

  case 224: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 825 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3914 "src-generated/ugbc.tab.c"
    break;

  case 225: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 828 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3922 "src-generated/ugbc.tab.c"
    break;

  case 226: /* screen_definition_expression: ROWS expr  */
#line 833 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 3930 "src-generated/ugbc.tab.c"
    break;

  case 227: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 836 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3938 "src-generated/ugbc.tab.c"
    break;

  case 228: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 839 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3946 "src-generated/ugbc.tab.c"
    break;

  case 232: /* var_definition_simple: Identifier ON Identifier  */
#line 848 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 3954 "src-generated/ugbc.tab.c"
    break;

  case 233: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 851 "src/ugbc.y"
                                    {
      variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 3962 "src-generated/ugbc.tab.c"
    break;

  case 234: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 854 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 3970 "src-generated/ugbc.tab.c"
    break;

  case 235: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 857 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 3980 "src-generated/ugbc.tab.c"
    break;

  case 236: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 862 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 3990 "src-generated/ugbc.tab.c"
    break;

  case 237: /* goto_definition: Identifier  */
#line 869 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 3998 "src-generated/ugbc.tab.c"
    break;

  case 238: /* goto_definition: Integer  */
#line 872 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4006 "src-generated/ugbc.tab.c"
    break;

  case 239: /* gosub_definition: Identifier  */
#line 878 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4014 "src-generated/ugbc.tab.c"
    break;

  case 240: /* gosub_definition: Integer  */
#line 881 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4022 "src-generated/ugbc.tab.c"
    break;

  case 242: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 890 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4030 "src-generated/ugbc.tab.c"
    break;

  case 243: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 896 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4038 "src-generated/ugbc.tab.c"
    break;

  case 246: /* on_goto_definition: Identifier  */
#line 905 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4047 "src-generated/ugbc.tab.c"
    break;

  case 247: /* $@1: %empty  */
#line 909 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4055 "src-generated/ugbc.tab.c"
    break;

  case 249: /* on_gosub_definition: Identifier  */
#line 914 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4064 "src-generated/ugbc.tab.c"
    break;

  case 250: /* $@2: %empty  */
#line 918 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4072 "src-generated/ugbc.tab.c"
    break;

  case 252: /* $@3: %empty  */
#line 923 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4080 "src-generated/ugbc.tab.c"
    break;

  case 254: /* $@4: %empty  */
#line 926 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4088 "src-generated/ugbc.tab.c"
    break;

  case 256: /* every_definition: expr TICKS GOSUB Identifier  */
#line 931 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4096 "src-generated/ugbc.tab.c"
    break;

  case 257: /* every_definition: ON  */
#line 934 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4104 "src-generated/ugbc.tab.c"
    break;

  case 258: /* every_definition: OFF  */
#line 937 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4112 "src-generated/ugbc.tab.c"
    break;

  case 259: /* add_definition: Identifier COMMA expr  */
#line 942 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4120 "src-generated/ugbc.tab.c"
    break;

  case 260: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 945 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4128 "src-generated/ugbc.tab.c"
    break;

  case 276: /* statement: INC Identifier  */
#line 966 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 4136 "src-generated/ugbc.tab.c"
    break;

  case 277: /* statement: DEC Identifier  */
#line 969 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 4144 "src-generated/ugbc.tab.c"
    break;

  case 278: /* statement: RANDOMIZE  */
#line 972 "src/ugbc.y"
              {
      randomize( _environment );
  }
#line 4152 "src-generated/ugbc.tab.c"
    break;

  case 279: /* statement: IF expr THEN  */
#line 975 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4160 "src-generated/ugbc.tab.c"
    break;

  case 280: /* statement: ELSE  */
#line 978 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 4168 "src-generated/ugbc.tab.c"
    break;

  case 281: /* statement: ELSE IF expr THEN  */
#line 981 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4176 "src-generated/ugbc.tab.c"
    break;

  case 282: /* statement: ENDIF  */
#line 984 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 4184 "src-generated/ugbc.tab.c"
    break;

  case 283: /* statement: DO  */
#line 987 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 4192 "src-generated/ugbc.tab.c"
    break;

  case 284: /* statement: LOOP  */
#line 990 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 4200 "src-generated/ugbc.tab.c"
    break;

  case 285: /* $@5: %empty  */
#line 993 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 4208 "src-generated/ugbc.tab.c"
    break;

  case 286: /* statement: WHILE $@5 expr  */
#line 995 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 4216 "src-generated/ugbc.tab.c"
    break;

  case 287: /* statement: WEND  */
#line 998 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 4224 "src-generated/ugbc.tab.c"
    break;

  case 288: /* statement: REPEAT  */
#line 1001 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 4232 "src-generated/ugbc.tab.c"
    break;

  case 289: /* statement: UNTIL expr  */
#line 1004 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 4240 "src-generated/ugbc.tab.c"
    break;

  case 290: /* statement: EXIT  */
#line 1007 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 4248 "src-generated/ugbc.tab.c"
    break;

  case 291: /* statement: EXIT IF expr  */
#line 1010 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 4256 "src-generated/ugbc.tab.c"
    break;

  case 292: /* statement: EXIT Integer  */
#line 1013 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4264 "src-generated/ugbc.tab.c"
    break;

  case 293: /* statement: EXIT direct_integer  */
#line 1016 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4272 "src-generated/ugbc.tab.c"
    break;

  case 294: /* statement: EXIT IF expr COMMA Integer  */
#line 1019 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4280 "src-generated/ugbc.tab.c"
    break;

  case 295: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1022 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4288 "src-generated/ugbc.tab.c"
    break;

  case 296: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1025 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4296 "src-generated/ugbc.tab.c"
    break;

  case 297: /* statement: NEXT  */
#line 1028 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 4304 "src-generated/ugbc.tab.c"
    break;

  case 298: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1031 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4312 "src-generated/ugbc.tab.c"
    break;

  case 299: /* statement: BEG GAMELOOP  */
#line 1034 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 4320 "src-generated/ugbc.tab.c"
    break;

  case 300: /* statement: END GAMELOOP  */
#line 1037 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 4328 "src-generated/ugbc.tab.c"
    break;

  case 301: /* statement: GRAPHIC  */
#line 1040 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 4336 "src-generated/ugbc.tab.c"
    break;

  case 302: /* statement: HALT  */
#line 1043 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 4344 "src-generated/ugbc.tab.c"
    break;

  case 307: /* statement: RETURN  */
#line 1050 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 4352 "src-generated/ugbc.tab.c"
    break;

  case 308: /* statement: POP  */
#line 1053 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 4360 "src-generated/ugbc.tab.c"
    break;

  case 309: /* statement: DONE  */
#line 1056 "src/ugbc.y"
          {
      return 0;
  }
#line 4368 "src-generated/ugbc.tab.c"
    break;

  case 310: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1059 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4376 "src-generated/ugbc.tab.c"
    break;

  case 311: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1062 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4384 "src-generated/ugbc.tab.c"
    break;

  case 312: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1065 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 4392 "src-generated/ugbc.tab.c"
    break;

  case 313: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1068 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4400 "src-generated/ugbc.tab.c"
    break;

  case 314: /* statement: Identifier COLON  */
#line 1071 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 4408 "src-generated/ugbc.tab.c"
    break;

  case 315: /* statement: Identifier ASSIGN expr  */
#line 1074 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 4422 "src-generated/ugbc.tab.c"
    break;

  case 316: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1083 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 4436 "src-generated/ugbc.tab.c"
    break;

  case 317: /* statement: DEBUG expr  */
#line 1092 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 4444 "src-generated/ugbc.tab.c"
    break;

  case 320: /* statements_no_linenumbers: statement  */
#line 1100 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 4450 "src-generated/ugbc.tab.c"
    break;

  case 321: /* $@6: %empty  */
#line 1101 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 4456 "src-generated/ugbc.tab.c"
    break;

  case 323: /* $@7: %empty  */
#line 1105 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 4464 "src-generated/ugbc.tab.c"
    break;

  case 324: /* statements_with_linenumbers: Integer $@7 statements_no_linenumbers  */
#line 1107 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 4472 "src-generated/ugbc.tab.c"
    break;

  case 329: /* $@8: %empty  */
#line 1119 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 4478 "src-generated/ugbc.tab.c"
    break;


#line 4482 "src-generated/ugbc.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (_environment, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, _environment);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, _environment);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (_environment, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, _environment);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, _environment);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1121 "src/ugbc.y"


void show_usage_and_exit( int _argc, char *_argv[] ) {

    printf("ugBASIC Compiler v1.0\n");
    printf("---------------------\n");
    printf("Copyright 2021 Marco Spedaletti (asimov@mclink.it)\n\n");
    printf("Licensed under the Apache License, Version 2.0 (the \"License\");\n");
    printf("you may not use this program except in compliance with the License.\n\n");

    printf("usage: %s [-c <file>] <source> <asm>\n\n", _argv[0] );

    printf("Options and parameters:\n" );
    printf("\t<source>     Input filename with ugBASIC source code" );
    printf("\t<asm>        Output filename with ASM source code" );
    printf("\t-c <file>    Output filename with linker configuration" );
    printf("\t-W           Enable warnings during compilation" );
    exit(EXIT_FAILURE);
}

int main( int _argc, char *_argv[] ) {
    extern FILE *yyin;
    int flags, opt;
    int nsecs, tfnd;
    Environment * _environment = malloc(sizeof(Environment));

    _environment->warningsEnabled = 0;

    while ((opt = getopt(_argc, _argv, "e:c:W")) != -1) {
        switch (opt) {
                case 'c':
                    _environment->configurationFileName = strdup(optarg);
                    break;
                case 'W':
                    _environment->warningsEnabled = 1;
                    break;
                default: /* '?' */
                    show_usage_and_exit( _argc, _argv );
                }
    }

    _environment->sourceFileName = strdup(_argv[optind] );
    _environment->asmFileName = strdup(_argv[optind+1] );
    
    yyin = fopen( _environment->sourceFileName, "r" );
    if ( ! yyin ) {
        fprintf(stderr, "Unable to open source file: %s\n", _environment->sourceFileName );
        exit(EXIT_FAILURE);
    }
    _environment->asmFile = fopen( _environment->asmFileName, "wt");
    if ( ! _environment->asmFile ) {
        fprintf(stderr, "Unable to open output file: %s\n", _environment->asmFileName );
        exit(EXIT_FAILURE);
    }

    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x4000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x4100, NULL );

    if ( _environment->configurationFileName ) {
        _environment->configurationFile = fopen( _environment->configurationFileName, "wt");
        if ( ! _environment->configurationFile ) {
            fprintf(stderr, "Unable to open configuration file: %s\n", _environment->configurationFileName );
            exit(EXIT_FAILURE);
        }
        linker_setup( _environment );
        outhead0(".segment \"CODE\"");
        variable_define( _environment, "strings_address", VT_ADDRESS, 0x4200 );
        bank_define( _environment, "STRINGS", BT_STRINGS, 0x4200, NULL );
    } else {
        outhead0("org 32768");
        variable_define( _environment, "strings_address", VT_ADDRESS, 0xa000 );
    }


    yydebug = 1;
    errors = 0;
    yyparse (_environment);

    gameloop_cleanup( _environment );
    bank_cleanup( _environment );
    variable_cleanup( _environment );

    if ( _environment->configurationFileName ) {
        linker_cleanup( _environment );
        fclose(_environment->configurationFile);
    }

    fclose(_environment->asmFile);

}

int yyerror (Environment * _ignored, const char *s) /* Called by yyparse on error */
{
        // TODO: better error message (like other compilers)
      printf( "*** ERROR: %s at %d\n", s, yylineno);
      exit(EXIT_FAILURE);
}

