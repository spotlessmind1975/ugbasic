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
  YYSYMBOL_RND = 137,                      /* RND  */
  YYSYMBOL_COLORS = 138,                   /* COLORS  */
  YYSYMBOL_INK = 139,                      /* INK  */
  YYSYMBOL_TIMER = 140,                    /* TIMER  */
  YYSYMBOL_MILLISECOND = 141,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 142,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 143,                    /* TICKS  */
  YYSYMBOL_BLACK = 144,                    /* BLACK  */
  YYSYMBOL_WHITE = 145,                    /* WHITE  */
  YYSYMBOL_RED = 146,                      /* RED  */
  YYSYMBOL_CYAN = 147,                     /* CYAN  */
  YYSYMBOL_VIOLET = 148,                   /* VIOLET  */
  YYSYMBOL_GREEN = 149,                    /* GREEN  */
  YYSYMBOL_BLUE = 150,                     /* BLUE  */
  YYSYMBOL_YELLOW = 151,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 152,                   /* ORANGE  */
  YYSYMBOL_BROWN = 153,                    /* BROWN  */
  YYSYMBOL_LIGHT = 154,                    /* LIGHT  */
  YYSYMBOL_DARK = 155,                     /* DARK  */
  YYSYMBOL_GREY = 156,                     /* GREY  */
  YYSYMBOL_GRAY = 157,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 158,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 159,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 160,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 161,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 162,                /* TURQUOISE  */
  YYSYMBOL_TAN = 163,                      /* TAN  */
  YYSYMBOL_PINK = 164,                     /* PINK  */
  YYSYMBOL_PEACH = 165,                    /* PEACH  */
  YYSYMBOL_OLIVE = 166,                    /* OLIVE  */
  YYSYMBOL_Identifier = 167,               /* Identifier  */
  YYSYMBOL_String = 168,                   /* String  */
  YYSYMBOL_Integer = 169,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 170,                 /* $accept  */
  YYSYMBOL_expr = 171,                     /* expr  */
  YYSYMBOL_expr_math = 172,                /* expr_math  */
  YYSYMBOL_term = 173,                     /* term  */
  YYSYMBOL_modula = 174,                   /* modula  */
  YYSYMBOL_factor = 175,                   /* factor  */
  YYSYMBOL_direct_integer = 176,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 177, /* random_definition_simple  */
  YYSYMBOL_random_definition = 178,        /* random_definition  */
  YYSYMBOL_color_enumeration = 179,        /* color_enumeration  */
  YYSYMBOL_exponential = 180,              /* exponential  */
  YYSYMBOL_position = 181,                 /* position  */
  YYSYMBOL_bank_definition_simple = 182,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 183, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 184,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 185, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 186, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 187,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 188, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 189, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 190,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 191,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 192, /* color_definition_expression  */
  YYSYMBOL_color_definition = 193,         /* color_definition  */
  YYSYMBOL_milliseconds = 194,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 195,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 196, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 197,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 198, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 199, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 200,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 201, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 202, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 203,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 204, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 205, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 206,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 207,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 208, /* text_definition_expression  */
  YYSYMBOL_text_definition = 209,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 210,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 211, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 212,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 213, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 214, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 215,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 216, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 217, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 218,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 219,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 220,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 221,         /* gosub_definition  */
  YYSYMBOL_var_definition = 222,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 223,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 224, /* point_definition_expression  */
  YYSYMBOL_point_definition = 225,         /* point_definition  */
  YYSYMBOL_ink_definition = 226,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 227,       /* on_goto_definition  */
  YYSYMBOL_228_1 = 228,                    /* $@1  */
  YYSYMBOL_on_gosub_definition = 229,      /* on_gosub_definition  */
  YYSYMBOL_230_2 = 230,                    /* $@2  */
  YYSYMBOL_on_definition = 231,            /* on_definition  */
  YYSYMBOL_232_3 = 232,                    /* $@3  */
  YYSYMBOL_233_4 = 233,                    /* $@4  */
  YYSYMBOL_every_definition = 234,         /* every_definition  */
  YYSYMBOL_add_definition = 235,           /* add_definition  */
  YYSYMBOL_statement = 236,                /* statement  */
  YYSYMBOL_237_5 = 237,                    /* $@5  */
  YYSYMBOL_statements_no_linenumbers = 238, /* statements_no_linenumbers  */
  YYSYMBOL_239_6 = 239,                    /* $@6  */
  YYSYMBOL_statements_with_linenumbers = 240, /* statements_with_linenumbers  */
  YYSYMBOL_241_7 = 241,                    /* $@7  */
  YYSYMBOL_statements_complex = 242,       /* statements_complex  */
  YYSYMBOL_program = 243,                  /* program  */
  YYSYMBOL_244_8 = 244                     /* $@8  */
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
#define YYLAST   1827

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  170
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  341
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  670

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   424


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
     165,   166,   167,   168,   169
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
     426,   429,   432,   435,   439,   443,   447,   450,   453,   458,
     458,   461,   464,   467,   470,   473,   476,   480,   483,   486,
     489,   493,   496,   499,   502,   506,   509,   512,   515,   521,
     524,   527,   530,   533,   538,   539,   542,   545,   550,   553,
     558,   559,   562,   565,   570,   573,   578,   579,   582,   585,
     588,   593,   596,   599,   604,   605,   608,   609,   610,   613,
     616,   619,   624,   627,   630,   636,   637,   640,   643,   646,
     649,   652,   655,   658,   661,   664,   667,   670,   673,   676,
     679,   682,   687,   690,   693,   696,   699,   702,   705,   708,
     711,   714,   717,   720,   723,   726,   729,   734,   735,   738,
     741,   744,   747,   750,   756,   759,   765,   766,   769,   774,
     779,   780,   783,   786,   791,   794,   799,   800,   803,   808,
     813,   814,   817,   820,   823,   828,   831,   837,   838,   841,
     844,   847,   850,   853,   858,   861,   864,   869,   870,   872,
     873,   876,   879,   882,   887,   894,   897,   903,   906,   912,
     915,   921,   926,   927,   930,   935,   939,   939,   944,   948,
     948,   953,   953,   956,   956,   961,   964,   967,   972,   975,
     981,   982,   983,   984,   985,   986,   987,   988,   989,   990,
     991,   992,   993,   994,   995,   996,   997,  1000,  1003,  1006,
    1009,  1012,  1015,  1018,  1021,  1024,  1027,  1027,  1032,  1035,
    1038,  1041,  1044,  1047,  1050,  1053,  1056,  1059,  1062,  1065,
    1068,  1071,  1074,  1077,  1080,  1081,  1082,  1083,  1084,  1087,
    1090,  1093,  1096,  1099,  1102,  1105,  1108,  1117,  1126,  1129,
    1130,  1134,  1135,  1135,  1139,  1139,  1146,  1147,  1148,  1149,
    1153,  1153
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
  "ADD", "MIN", "MAX", "SGN", "SIGNED", "ABS", "RND", "COLORS", "INK",
  "TIMER", "MILLISECOND", "MILLISECONDS", "TICKS", "BLACK", "WHITE", "RED",
  "CYAN", "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE", "BROWN", "LIGHT",
  "DARK", "GREY", "GRAY", "MAGENTA", "PURPLE", "LAVENDER", "GOLD",
  "TURQUOISE", "TAN", "PINK", "PEACH", "OLIVE", "Identifier", "String",
  "Integer", "$accept", "expr", "expr_math", "term", "modula", "factor",
  "direct_integer", "random_definition_simple", "random_definition",
  "color_enumeration", "exponential", "position", "bank_definition_simple",
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
  "textmap_definition", "text_definition_simple",
  "text_definition_expression", "text_definition",
  "tiles_definition_simple", "tiles_definition_expression",
  "tiles_definition", "colormap_definition_simple",
  "colormap_definition_expression", "colormap_definition",
  "screen_definition_simple", "screen_definition_expression",
  "screen_definition", "var_definition_simple", "goto_definition",
  "gosub_definition", "var_definition", "point_definition_simple",
  "point_definition_expression", "point_definition", "ink_definition",
  "on_goto_definition", "$@1", "on_gosub_definition", "$@2",
  "on_definition", "$@3", "$@4", "every_definition", "add_definition",
  "statement", "$@5", "statements_no_linenumbers", "$@6",
  "statements_with_linenumbers", "$@7", "statements_complex", "program",
  "$@8", YY_NULLPTR
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
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424
};
#endif

#define YYPACT_NINF (-231)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-260)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -231,    56,   698,  -231,  -231,  -108,   -97,   -22,  -231,    15,
    1362,   101,   -17,  1362,  -231,     6,    68,  1510,   -70,   -88,
    -231,  -231,  -231,  1066,   102,   -10,  1510,    43,    45,  -231,
     119,   122,  1510,  1510,  -231,   137,   145,   -48,  -231,  -231,
      91,  -231,   -60,  -231,  1510,    13,  1214,   142,    14,  1510,
      74,  -231,   176,   180,   183,  -231,  -231,  -231,  1362,   164,
    -231,  -231,  -231,  1362,  1362,  1362,  -231,  -231,  -231,    21,
     918,  -231,  -231,   157,   159,   162,    -9,    30,  -231,  -231,
     163,   168,  1510,  -231,  -231,   171,   172,   173,   174,   175,
     177,   178,   179,   181,   184,   185,   186,   187,   188,   189,
     199,   200,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,    49,  -231,  -231,     8,   -72,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,    86,   197,  -231,  -231,   -51,
       9,   106,   113,   108,   -42,  -231,  -231,  -231,  -231,  -231,
     -21,   156,   -19,   -18,   -15,   -12,   218,  -231,  -231,  -231,
      71,   138,  -231,  -231,  -231,  1362,  -231,  -231,   214,  -231,
    -231,  -231,  -231,  -231,  1362,   198,   201,  -231,  -231,  -231,
     -14,  -231,    29,  -231,  -231,  -231,  -231,  -231,  1510,  1510,
    -231,  -231,   238,  -231,  -231,  -231,  1362,  -231,  -231,  -231,
    1362,   217,  -231,  -231,  -231,   182,  -231,  -231,  1510,  1510,
    -231,  -231,  1362,  -231,  -231,  -231,   215,  -231,  -231,  -231,
    -231,  -231,  -231,  1510,  1510,  -231,  -231,  -231,   235,  -231,
    -231,   107,  -231,  1510,   247,  -231,  -231,  -231,  -231,  1510,
     260,   822,  -231,   698,   698,   245,   246,  1362,  -231,  -231,
     204,   205,   206,   207,  -231,   248,   249,   250,   251,   252,
     -27,   253,  1362,  1362,  1362,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  1510,  1510,  -231,  1510,  1510,
    1510,  1510,  1510,  1510,  1510,  1510,  1510,  1510,  1510,  1510,
    1510,  1510,  1510,  1510,  1510,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,  1658,
    1658,  1658,  1658,  1658,  -231,  -231,  -231,  1362,   256,  -231,
    -231,  -231,   233,   156,   258,   156,   265,   156,   266,   156,
     267,   156,  -231,  1510,   261,  -231,  -231,    26,    48,    -1,
      10,  -231,  -231,  -231,   262,   156,   264,  -231,  -231,    82,
      84,    70,    75,  -231,  -231,   268,  -231,  -231,  1362,  -231,
    -231,  1362,  1362,  -231,  -231,   257,   125,  -231,   286,  1510,
    -231,  -231,  -231,  -231,  1362,  -231,   288,   291,  -231,  -231,
    1362,   231,   296,  1510,   203,   299,  1510,  -231,  1510,  -231,
     822,  -231,  -231,   140,   141,  -231,  -231,  1510,   156,  1510,
     156,   143,   144,   146,   147,   149,   274,   275,   276,  -231,
     279,   284,   290,   292,   293,   294,   314,   319,   323,   324,
     297,   298,   300,   301,   327,   302,   303,   304,   305,   306,
     335,   336,   309,   311,   312,   106,   106,   135,   135,   135,
     135,   135,   135,   135,   135,   113,   108,   108,  -231,   321,
     322,  1362,    40,  -231,   156,  -231,   156,  -231,   156,  -231,
     156,    25,  -231,  1510,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  1510,  -231,   156,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,   156,  -231,  -231,  -231,  -231,  -231,  -231,
     190,   191,   192,   339,  1510,   346,   313,   318,  1510,  1510,
     347,   355,  -231,   -71,   307,   196,  1510,   357,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,   202,   208,   209,  -231,  -231,  -231,  -231,  -231,  -231,
    1510,  1510,  1510,  1510,  -231,  -231,  -231,  -231,  1510,  -231,
    -231,  -231,  -231,  -231,  1510,  1510,  -231,  -231,  -231,   213,
     216,  -231,  -231,  -231,  -231,  -231,  -231,   337,  -231,   340,
    -231,   219,    53,  -231,   358,  -231,   361,   365,  -231,   367,
    -231,   363,  1362,   374,  1510,  1510,   156,   350,   353,  1510,
     156,  -231,  -231,  1510,  -231,    27,  1510,  -231,  -231,  -231,
     354,   356,    28,    33,   359,   360,   362,  -231,  -231,   222,
     224,  -231,   364,  -231,   369,  -231,  1510,   156,   375,   389,
    1510,  -231,  -231,  1510,  -231,  -231,  -231,   386,   388,   368,
     370,   287,  1510,   391,   334,  -231,  -231,  1510,  -231,  1510,
    -231,  -231,  -231,  -231,  -231,  -231,   239,   240,   376,   377,
     190,   191,  -231,  -231,  1510,  1510,  -231,  -231,  1510,   378,
    1510,  1510,   380,   381,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,   396,  -231,  -231,  -231,  -231,  1510,  -231
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     340,     0,   330,     1,   329,     0,     0,     0,   320,     0,
       0,   308,     0,     0,   313,     0,     0,     0,   239,     0,
     295,   299,   296,     0,     0,     0,     0,     0,     0,   293,
       0,     0,     0,   288,   312,     0,     0,     0,   318,   319,
     291,   294,   301,   298,     0,     0,     0,     0,     0,     0,
       0,   334,   331,   336,   338,   341,   286,   287,     0,     0,
     140,   141,   271,     0,     0,     0,   154,   155,   273,     0,
       0,    74,    75,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,   108,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,     0,    43,    48,    49,    50,
      51,    52,    53,    56,    57,     0,    58,    62,    60,     0,
       2,    12,    15,    17,     0,    71,    20,   165,   166,   274,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   270,
       0,     0,   197,   198,   275,     0,   200,   201,   202,   206,
     207,   276,   229,   230,     0,     0,     0,   237,   238,   281,
       0,   314,     0,   249,   284,   245,   246,   315,     0,     0,
     212,   213,     0,   216,   217,   278,     0,   220,   221,   279,
       0,   223,   227,   228,   280,     0,   310,   311,     0,     0,
     328,   289,     0,   210,   211,   277,     0,   252,   253,   282,
     247,   248,   316,     0,     0,   303,   304,   300,     0,   266,
     267,     0,   317,     0,     0,   285,   254,   283,   325,     0,
       0,   330,   332,   330,   330,     0,     0,     0,   151,   148,
       0,     0,     0,     0,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    23,    24,    26,    28,
      29,    25,    30,    96,    22,     0,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    41,    44,    45,    46,
      47,    42,    55,    59,   156,   162,   157,   158,   163,   164,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   159,   160,   161,     0,     0,   146,
     147,   272,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,     0,     0,   187,   188,     0,     0,     0,
       0,   184,   183,   109,     0,     0,     0,   172,   173,     0,
       0,     0,     0,   169,   168,     0,   204,   199,     0,   234,
     231,     0,     0,   261,   263,     0,     0,   297,     0,     0,
     219,   218,   225,   222,     0,   290,     0,     0,   209,   208,
       0,     0,   302,     0,     0,     0,     0,   326,     0,   335,
     330,   337,   339,     0,     0,   138,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,     5,     7,     8,
       9,    10,     6,     3,     4,    16,    18,    19,    21,     0,
       0,     0,     0,   116,     0,   128,     0,   120,     0,   124,
       0,   112,   185,     0,   192,   191,   196,   195,   190,   194,
     189,   193,     0,   170,     0,   177,   176,   181,   180,   175,
     179,   174,   178,     0,   205,   203,   235,   232,   236,   233,
       0,     0,     0,   240,     0,     0,     0,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,   268,   327,   333,
     139,   137,   153,   150,   152,   149,    70,    63,    65,    69,
      67,     0,     0,     0,    73,    72,    77,    76,    79,    78,
       0,     0,     0,     0,    86,    87,    88,    95,     0,    89,
      90,    91,    92,    93,     0,     0,   101,   102,    97,     0,
       0,   144,   142,   113,   126,   118,   121,   115,   127,   119,
     123,     0,     0,   182,     0,   167,     0,   255,   262,   258,
     264,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   305,   306,     0,   265,     0,     0,    64,    66,    68,
       0,     0,     0,     0,     0,     0,     0,   145,   143,     0,
       0,   129,   114,   125,   117,   122,     0,     0,     0,     0,
       0,   243,   242,     0,   215,   226,   224,     0,     0,     0,
       0,   307,     0,     0,     0,    80,    81,     0,    82,     0,
      84,    94,   100,    99,   131,   133,     0,     0,     0,     0,
       0,     0,   244,   214,     0,     0,   251,   250,     0,     0,
       0,     0,     0,     0,   130,   132,   186,   171,   257,   260,
     321,   322,   309,     0,   323,   269,    83,    85,     0,   324
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,   -13,   -77,  -133,   100,  -140,   259,  -231,  -231,  -231,
     104,   269,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,   285,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -222,  -231,  -220,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -230,  -231,
    -231,  -231,   -55,  -231,  -231
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   129,   130,   131,   132,   133,   134,   262,   263,   135,
     136,   344,   147,   148,   149,    60,    61,    62,   319,   320,
     321,    66,    67,    68,   299,   137,   138,   139,   152,   153,
     154,   159,   160,   161,   203,   204,   205,   183,   184,   185,
     187,   188,   189,   192,   193,   194,   167,   168,   169,   173,
     177,   212,   174,   207,   208,   209,   227,   568,   608,   570,
     609,   171,   490,   491,   222,   225,    52,   178,    53,   390,
      54,   231,    55,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     150,   389,    58,   317,   170,   323,   325,   141,   214,   327,
     182,    77,   329,   195,   190,   142,   255,   300,   301,   200,
     201,   302,    77,   303,   304,   305,   306,   307,   294,   295,
     155,   217,   143,   221,   622,   627,   226,   294,   314,   363,
     629,    63,   156,   157,   468,   235,    64,   406,   407,   365,
     238,   240,   242,   469,   561,   470,     3,   251,   408,    56,
     144,   145,   623,   628,   471,   256,   257,   258,   630,   267,
      57,   366,   553,   562,   259,   260,   261,   191,   290,   175,
     228,   176,   464,   465,   291,   602,    65,   229,   364,   554,
     296,   297,   298,   158,   230,   332,   333,   172,   581,   296,
     297,   315,   603,   334,   466,   467,   308,   335,   336,   215,
     162,   163,   164,   165,   309,   479,   337,   555,   556,   210,
     481,   211,   166,   140,   480,   338,   186,   339,   340,   482,
     604,   605,   311,   196,   312,   197,   341,   342,   475,   476,
     477,   478,   356,   300,   301,    59,   318,   343,   324,   326,
     146,   359,   328,   198,   286,   330,   199,   287,   288,   213,
     509,   202,   332,   345,   289,   367,   368,   435,   436,   206,
     346,   446,   447,   370,   347,   348,   223,   372,   391,   392,
     218,   224,   232,   349,   233,   376,   377,   234,   237,   378,
     244,   252,   350,   253,   351,   352,   254,   265,   285,   264,
     381,   382,   266,   353,   354,   268,   269,   270,   271,   272,
     385,   273,   274,   275,   343,   276,   387,   293,   277,   278,
     279,   280,   281,   282,   395,   437,   438,   439,   440,   441,
     442,   443,   444,   283,   284,   292,   310,   313,    77,   410,
     412,   414,   331,   358,   361,   369,   374,   362,   383,   380,
     384,   375,   416,   417,   386,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   151,   388,   393,   394,   397,   398,   399,   400,
     451,   452,   454,   401,   402,   403,   404,   405,   409,   456,
     458,   460,   493,   494,   463,   498,   472,   474,   499,   492,
     502,   216,   483,   503,   449,   505,   506,   510,   511,   521,
     522,   523,   516,   517,   524,   518,   519,   236,   520,   525,
     462,   530,   239,   241,   243,   526,   531,   527,   528,   529,
     532,   533,   534,   535,   538,   536,   537,   539,   540,   541,
     542,   543,   544,   545,   546,   484,   547,   548,   486,   488,
     549,   550,   572,   574,   579,   575,   495,   567,   569,   571,
     576,   496,   580,   584,   586,   606,   599,   500,   607,   600,
     504,   587,  -256,   507,  -259,   508,   610,   588,   589,   583,
     597,   613,   640,   598,   512,   617,   514,   601,   618,   625,
     634,   626,   635,   636,   631,   632,   641,   633,   637,   644,
     322,   645,   648,   646,   650,   647,   651,   654,   655,   668,
     445,   656,   657,   663,   357,   666,   667,   448,   658,   316,
     355,   659,     0,   360,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   551,     0,
       0,     0,     0,     0,     0,   371,     0,     0,     0,   373,
     563,     0,     0,     0,     0,     0,     0,     0,     0,   564,
       0,   379,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   573,     0,     0,     0,   577,   578,     0,     0,     0,
       0,     0,     0,   585,     0,     0,   396,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   411,   413,   415,     0,     0,     0,   590,   591,   592,
     593,     0,     0,     0,     0,   594,     0,     0,     0,     0,
       0,   595,   596,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   611,
       0,   614,   615,     0,     0,     0,   619,     0,     0,     0,
     621,     0,     0,   624,     0,     0,   450,     0,     0,     0,
       0,     0,   453,     0,   455,     0,   457,     0,   459,     0,
     461,     0,     0,   638,     0,     0,     0,   642,     0,     0,
     643,     0,     0,     0,   473,     0,     0,     0,     0,   649,
       0,     0,     0,     0,   652,     0,   653,   485,     0,     0,
     487,   489,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   660,   661,   497,     0,   662,     0,   664,   665,   501,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   669,     0,   513,     0,   515,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     0,     0,     0,     0,     0,     0,     5,     6,
     552,     0,     0,   557,     0,   558,     0,   559,     0,   560,
       7,     8,     0,     9,     0,    10,    11,     0,    12,    13,
       0,     0,     0,   565,     0,     0,    14,     0,    15,    16,
      17,     0,   566,     0,     0,    18,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,    20,    21,    22,    23,
      24,    25,   582,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    28,     0,    29,
       0,     0,    30,    31,    32,     0,    33,    34,    35,    36,
      37,    38,    39,     0,    40,     0,     0,     0,    41,    42,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     0,     0,     0,    48,
       0,   612,     5,     6,     0,   616,     0,    49,     0,   620,
       0,     0,     0,     0,     7,     8,     0,     9,     0,    10,
      11,     0,    12,    13,     0,     0,     0,     0,     0,     0,
      14,     0,    15,    16,    17,    50,   639,    51,     0,    18,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    28,     0,    29,     0,     0,    30,    31,    32,     0,
      33,    34,    35,    36,    37,    38,    39,    69,    40,     0,
       0,     0,    41,    42,    43,    44,    45,     0,    46,    47,
       0,     0,     0,   245,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    48,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,    71,    72,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,     0,    75,    50,
       0,    76,   246,   247,   248,     0,     0,     0,     0,     0,
       0,    78,    79,   249,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,     0,     0,     0,
      97,    98,    99,   250,   100,   101,   102,     0,   103,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    69,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,     0,     0,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,   180,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,     0,    75,     0,     0,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,     0,     0,     0,    97,    98,
      99,     0,   100,   101,   102,     0,   103,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    69,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,     0,     0,     0,     0,     0,   219,   220,     0,     0,
       0,     0,     0,     0,    71,    72,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,     0,     0,    75,     0,     0,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,     0,     0,     0,    97,    98,    99,     0,
     100,   101,   102,     0,   103,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    69,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
       0,     0,    75,     0,     0,    76,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,     0,     0,     0,    97,    98,    99,     0,   100,   101,
     102,     0,   103,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    69,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,     0,     0,
      75,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,     0,
       0,     0,    97,    98,    99,     0,   100,   101,   102,     0,
     103,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    69,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    71,    72,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,     0,    75,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,     0,     0,     0,
      97,    98,    99,     0,   100,   101,   102,     0,   103,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128
};

static const yytype_int16 yycheck[] =
{
      13,   231,    24,    24,    17,    24,    24,    24,    68,    24,
      23,    82,    24,    26,    24,    32,    25,     8,     9,    32,
      33,    12,    82,    14,    15,    16,    17,    18,    79,    80,
      24,    44,    49,    46,     7,     7,    49,    79,    80,    53,
       7,    26,    36,    37,    45,    58,    31,    74,    75,    20,
      63,    64,    65,    54,    29,    45,     0,    70,    85,   167,
      77,    78,    35,    35,    54,    74,    75,    76,    35,    82,
     167,    42,    32,    48,    83,    84,    85,    87,   150,   167,
       6,   169,    56,    57,   156,    32,    71,    13,   102,    49,
     141,   142,   143,    87,    20,    24,    25,   167,   169,   141,
     142,   143,    49,    32,    56,    57,    97,    36,    37,   169,
      42,    43,    44,    45,   105,    45,    45,    77,    78,   167,
      45,   169,    54,    22,    54,    54,    24,    56,    57,    54,
      77,    78,    19,    90,    21,    90,    65,    66,    56,    57,
      56,    57,   155,     8,     9,   167,   167,    76,   167,   167,
     167,   164,   167,    34,   146,   167,    34,   149,   150,    68,
     390,    24,    24,    25,   156,   178,   179,   300,   301,    24,
      32,   311,   312,   186,    36,    37,    34,   190,   233,   234,
     167,   167,     6,    45,     4,   198,   199,     4,    24,   202,
     169,    34,    54,    34,    56,    57,    34,    34,   149,   169,
     213,   214,    34,    65,    66,    34,    34,    34,    34,    34,
     223,    34,    34,    34,    76,    34,   229,    20,    34,    34,
      34,    34,    34,    34,   237,   302,   303,   304,   305,   306,
     307,   308,   309,    34,    34,   149,   130,   129,    82,   252,
     253,   254,    24,    29,    46,     7,    29,    46,    13,    34,
     143,    69,   265,   266,     7,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,    13,    13,    29,    29,    72,    72,    72,    72,
      24,    48,    24,    35,    35,    35,    35,    35,    35,    24,
      24,    24,   167,     7,    33,     7,    34,    33,     7,    42,
      69,    42,    34,     7,   317,   102,     7,   167,   167,    35,
      35,    35,   169,   169,    35,   169,   169,    58,   169,    35,
     333,     7,    63,    64,    65,    35,     7,    35,    35,    35,
       7,     7,    35,    35,     7,    35,    35,    35,    35,    35,
      35,    35,     7,     7,    35,   358,    35,    35,   361,   362,
      29,    29,    13,     7,     7,    42,   369,   167,   167,   167,
      42,   374,     7,   167,     7,     7,    29,   380,     7,    29,
     383,   169,     7,   386,     7,   388,    13,   169,   169,    72,
     167,     7,     7,   167,   397,    35,   399,   168,    35,    35,
     168,    35,   168,    29,    35,    35,     7,    35,    29,    13,
     141,    13,   115,    35,    13,    35,    72,   168,   168,    13,
     310,    35,    35,    35,   155,    35,    35,   313,   640,   134,
     151,   641,    -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   451,    -1,
      -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,   190,
     463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   472,
      -1,   202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   494,    -1,    -1,    -1,   498,   499,    -1,    -1,    -1,
      -1,    -1,    -1,   506,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   252,   253,   254,    -1,    -1,    -1,   530,   531,   532,
     533,    -1,    -1,    -1,    -1,   538,    -1,    -1,    -1,    -1,
      -1,   544,   545,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   572,
      -1,   574,   575,    -1,    -1,    -1,   579,    -1,    -1,    -1,
     583,    -1,    -1,   586,    -1,    -1,   317,    -1,    -1,    -1,
      -1,    -1,   323,    -1,   325,    -1,   327,    -1,   329,    -1,
     331,    -1,    -1,   606,    -1,    -1,    -1,   610,    -1,    -1,
     613,    -1,    -1,    -1,   345,    -1,    -1,    -1,    -1,   622,
      -1,    -1,    -1,    -1,   627,    -1,   629,   358,    -1,    -1,
     361,   362,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   644,   645,   374,    -1,   648,    -1,   650,   651,   380,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   668,    -1,   398,    -1,   400,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,
     451,    -1,    -1,   454,    -1,   456,    -1,   458,    -1,   460,
      22,    23,    -1,    25,    -1,    27,    28,    -1,    30,    31,
      -1,    -1,    -1,   474,    -1,    -1,    38,    -1,    40,    41,
      42,    -1,   483,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,   503,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
      -1,    -1,    94,    95,    96,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,    -1,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,   131,
      -1,   572,    10,    11,    -1,   576,    -1,   139,    -1,   580,
      -1,    -1,    -1,    -1,    22,    23,    -1,    25,    -1,    27,
      28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    40,    41,    42,   167,   607,   169,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    -1,    91,    -1,    -1,    94,    95,    96,    -1,
      98,    99,   100,   101,   102,   103,   104,     9,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,    -1,   116,   117,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,   131,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,   167,
      -1,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,   135,   136,   137,   138,    -1,   140,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,     9,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,   132,   133,
     134,    -1,   136,   137,   138,    -1,   140,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,     9,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,
     136,   137,   138,    -1,   140,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,     9,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,
     138,    -1,   140,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,     9,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,   132,   133,   134,    -1,   136,   137,   138,    -1,
     140,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     9,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,   137,   138,    -1,   140,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   243,   244,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    88,    89,    91,
      94,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     106,   110,   111,   112,   113,   114,   116,   117,   131,   139,
     167,   169,   236,   238,   240,   242,   167,   167,    24,   167,
     185,   186,   187,    26,    31,    71,   191,   192,   193,     9,
      34,    50,    51,    52,    67,    70,    73,    82,    83,    84,
      94,    95,   107,   108,   109,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   132,   133,   134,
     136,   137,   138,   140,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   171,
     172,   173,   174,   175,   176,   179,   180,   195,   196,   197,
      22,    24,    32,    49,    77,    78,   167,   182,   183,   184,
     171,   176,   198,   199,   200,    24,    36,    37,    87,   201,
     202,   203,    42,    43,    44,    45,    54,   216,   217,   218,
     171,   231,   167,   219,   222,   167,   169,   220,   237,    24,
      36,    37,   171,   207,   208,   209,    24,   210,   211,   212,
      24,    87,   213,   214,   215,   171,    90,    90,    34,    34,
     171,   171,    24,   204,   205,   206,    24,   223,   224,   225,
     167,   169,   221,    68,    68,   169,   176,   171,   167,    42,
      43,   171,   234,    34,   167,   235,   171,   226,     6,    13,
      20,   241,     6,     4,     4,   171,   176,    24,   171,   176,
     171,   176,   171,   176,   169,    25,    74,    75,    76,    85,
     135,   171,    34,    34,    34,    25,    74,    75,    76,    83,
      84,    85,   177,   178,   169,    34,    34,   171,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,   149,   146,   149,   150,   156,
     150,   156,   149,    20,    79,    80,   141,   142,   143,   194,
       8,     9,    12,    14,    15,    16,    17,    18,    97,   105,
     130,    19,    21,   129,    80,   143,   194,    24,   167,   188,
     189,   190,   176,    24,   167,    24,   167,    24,   167,    24,
     167,    24,    24,    25,    32,    36,    37,    45,    54,    56,
      57,    65,    66,    76,   181,    25,    32,    36,    37,    45,
      54,    56,    57,    65,    66,   181,   171,   176,    29,   171,
     176,    46,    46,    53,   102,    20,    42,   171,   171,     7,
     171,   176,   171,   176,    29,    69,   171,   171,   171,   176,
      34,   171,   171,    13,   143,   171,     7,   171,    13,   238,
     239,   242,   242,    29,    29,   171,   176,    72,    72,    72,
      72,    35,    35,    35,    35,    35,    74,    75,    85,    35,
     171,   176,   171,   176,   171,   176,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   173,   173,   172,   172,   172,
     172,   172,   172,   172,   172,   174,   175,   175,   180,   171,
     176,    24,    48,   176,    24,   176,    24,   176,    24,   176,
      24,   176,   171,    33,    56,    57,    56,    57,    45,    54,
      45,    54,    34,   176,    33,    56,    57,    56,    57,    45,
      54,    45,    54,    34,   171,   176,   171,   176,   171,   176,
     232,   233,    42,   167,     7,   171,   171,   176,     7,     7,
     171,   176,    69,     7,   171,   102,     7,   171,   171,   238,
     167,   167,   171,   176,   171,   176,   169,   169,   169,   169,
     169,    35,    35,    35,    35,    35,    35,    35,    35,    35,
       7,     7,     7,     7,    35,    35,    35,    35,     7,    35,
      35,    35,    35,    35,     7,     7,    35,    35,    35,    29,
      29,   171,   176,    32,    49,    77,    78,   176,   176,   176,
     176,    29,    48,   171,   171,   176,   176,   167,   227,   167,
     229,   167,    13,   171,     7,    42,    42,   171,   171,     7,
       7,   169,   176,    72,   167,   171,     7,   169,   169,   169,
     171,   171,   171,   171,   171,   171,   171,   167,   167,    29,
      29,   168,    32,    49,    77,    78,     7,     7,   228,   230,
      13,   171,   176,     7,   171,   171,   176,    35,    35,   171,
     176,   171,     7,    35,   171,    35,    35,     7,    35,     7,
      35,    35,    35,    35,   168,   168,    29,    29,   171,   176,
       7,     7,   171,   171,    13,    13,    35,    35,   115,   171,
      13,    72,   171,   171,   168,   168,    35,    35,   227,   229,
     171,   171,   171,    35,   171,   171,    35,    35,    13,   171
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   170,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   172,   172,   172,   173,   173,   174,   174,   174,
     175,   175,   176,   177,   177,   177,   177,   177,   177,   177,
     178,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   181,
     181,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   183,
     183,   183,   183,   183,   184,   184,   185,   185,   186,   186,
     187,   187,   188,   188,   189,   189,   190,   190,   191,   191,
     191,   192,   192,   192,   193,   193,   194,   194,   194,   195,
     195,   195,   196,   196,   196,   197,   197,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   200,   200,   201,
     201,   201,   201,   201,   202,   202,   203,   203,   204,   205,
     206,   206,   207,   207,   208,   208,   209,   209,   210,   211,
     212,   212,   213,   213,   213,   214,   214,   215,   215,   216,
     216,   216,   216,   216,   217,   217,   217,   218,   218,   219,
     219,   219,   219,   219,   219,   220,   220,   221,   221,   222,
     223,   224,   225,   225,   226,   227,   228,   227,   229,   230,
     229,   232,   231,   233,   231,   234,   234,   234,   235,   235,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   237,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   238,   239,   238,   241,   240,   242,   242,   242,   242,
     244,   243
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
       4,     4,     4,     4,     6,     4,     2,     4,     3,     6,
       6,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     4,     5,     4,     3,     5,     4,     4,
       3,     4,     5,     4,     3,     5,     4,     4,     3,     5,
       7,     6,     7,     6,     1,     1,     3,     4,     3,     4,
       1,     1,     3,     4,     3,     4,     1,     1,     2,     4,
       4,     2,     4,     4,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     1,     1,     4,     2,     2,
       3,     7,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     2,     2,     3,     7,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       1,     1,     1,     3,     2,     3,     1,     1,     2,     2,
       1,     1,     1,     1,     6,     5,     1,     1,     2,     2,
       1,     1,     2,     1,     5,     2,     5,     1,     1,     1,
       1,     2,     3,     3,     2,     3,     3,     1,     1,     0,
       3,     4,     5,     5,     6,     1,     1,     1,     1,     1,
       6,     6,     1,     1,     1,     1,     0,     4,     1,     0,
       4,     0,     4,     0,     4,     4,     1,     1,     3,     7,
       2,     2,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       3,     1,     4,     1,     1,     1,     0,     3,     1,     1,
       2,     1,     3,     2,     2,     5,     5,     6,     1,     8,
       2,     2,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     8,     8,     8,    10,     2,     3,     4,     2,     1,
       0,     1,     0,     4,     0,     3,     1,     3,     1,     3,
       0,     2
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
#line 2430 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 74 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2439 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 78 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2447 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 81 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2455 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 84 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2463 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 87 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2471 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 90 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2479 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 93 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2487 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 96 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2495 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 103 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2503 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 106 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2512 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 119 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2521 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 123 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2530 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 131 "src/ugbc.y"
                               {
        (yyval.string) = variable_pow( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2539 "src-generated/ugbc.tab.c"
    break;

  case 22: /* direct_integer: HASH Integer  */
#line 138 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2547 "src-generated/ugbc.tab.c"
    break;

  case 23: /* random_definition_simple: BYTE  */
#line 143 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2555 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: WORD  */
#line 146 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2563 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: DWORD  */
#line 149 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2571 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: POSITION  */
#line 152 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2579 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: COLOR  */
#line 155 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2587 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: WIDTH  */
#line 158 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2595 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: HEIGHT  */
#line 161 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2603 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition: random_definition_simple  */
#line 166 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2611 "src-generated/ugbc.tab.c"
    break;

  case 31: /* color_enumeration: BLACK  */
#line 171 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2620 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: WHITE  */
#line 175 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2629 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: RED  */
#line 179 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2638 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: CYAN  */
#line 183 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2647 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: VIOLET  */
#line 187 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2656 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: GREEN  */
#line 191 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2665 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: BLUE  */
#line 195 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2674 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: YELLOW  */
#line 199 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2683 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: ORANGE  */
#line 203 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2692 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: BROWN  */
#line 207 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2701 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: LIGHT RED  */
#line 211 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2710 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: DARK GREY  */
#line 215 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2719 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: GREY  */
#line 219 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2728 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: LIGHT GREEN  */
#line 223 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2737 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT BLUE  */
#line 227 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2746 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT GREY  */
#line 231 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2755 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: DARK BLUE  */
#line 235 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2764 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: MAGENTA  */
#line 239 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2773 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: PURPLE  */
#line 243 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2782 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: LAVENDER  */
#line 247 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2791 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: GOLD  */
#line 251 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2800 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: TURQUOISE  */
#line 255 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2809 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TAN  */
#line 259 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2818 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: YELLOW GREEN  */
#line 263 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2827 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: OLIVE GREEN  */
#line 267 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2836 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: PINK  */
#line 271 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2845 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PEACH  */
#line 275 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2854 "src-generated/ugbc.tab.c"
    break;

  case 58: /* exponential: Identifier  */
#line 281 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2862 "src-generated/ugbc.tab.c"
    break;

  case 59: /* exponential: Identifier DOLLAR  */
#line 284 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[-1].string);
      }
#line 2870 "src-generated/ugbc.tab.c"
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
#line 2884 "src-generated/ugbc.tab.c"
    break;

  case 61: /* exponential: MINUS Integer  */
#line 296 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 2893 "src-generated/ugbc.tab.c"
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
#line 2905 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: OP BYTE CP Integer  */
#line 307 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2914 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: OP SIGNED BYTE CP Integer  */
#line 311 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2923 "src-generated/ugbc.tab.c"
    break;

  case 65: /* exponential: OP WORD CP Integer  */
#line 315 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2932 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: OP SIGNED WORD CP Integer  */
#line 319 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2941 "src-generated/ugbc.tab.c"
    break;

  case 67: /* exponential: OP DWORD CP Integer  */
#line 323 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2950 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP SIGNED DWORD CP Integer  */
#line 327 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2959 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP POSITION CP Integer  */
#line 331 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2968 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP COLOR CP Integer  */
#line 335 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2977 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: color_enumeration  */
#line 339 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2985 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: PEEK OP direct_integer CP  */
#line 342 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2993 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: PEEK OP expr CP  */
#line 345 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3001 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: XPEN  */
#line 348 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3009 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: YPEN  */
#line 351 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3017 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: COLLISION OP direct_integer CP  */
#line 354 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3025 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: COLLISION OP expr CP  */
#line 357 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3033 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: HIT OP direct_integer CP  */
#line 360 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3041 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: HIT OP expr CP  */
#line 363 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3049 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: LEFT OP expr COMMA expr CP  */
#line 366 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3057 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 369 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3065 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: MID OP expr COMMA expr CP  */
#line 372 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3073 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 375 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3081 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: INSTR OP expr COMMA expr CP  */
#line 378 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3089 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 381 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3097 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: UPPER OP expr CP  */
#line 384 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3105 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: LOWER OP expr CP  */
#line 387 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3113 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: STR OP expr CP  */
#line 390 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3121 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: SPACE OP expr CP  */
#line 393 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3129 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: FLIP OP expr CP  */
#line 396 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3137 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: CHR OP expr CP  */
#line 399 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3145 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: ASC OP expr CP  */
#line 402 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3153 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: LEN OP expr CP  */
#line 405 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3161 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: STRING OP expr COMMA expr CP  */
#line 408 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3169 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: VAL OP expr CP  */
#line 411 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3177 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: RANDOM random_definition  */
#line 414 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3185 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: RND OP expr CP  */
#line 417 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3193 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: OP expr CP  */
#line 420 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3201 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: MAX OP expr COMMA expr CP  */
#line 423 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3209 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: MIN OP expr COMMA expr CP  */
#line 426 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3217 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: SGN OP expr CP  */
#line 429 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3225 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: ABS OP expr CP  */
#line 432 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3233 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: TRUE  */
#line 435 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3242 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: FALSE  */
#line 439 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3251 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: COLORS  */
#line 443 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3260 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: WIDTH  */
#line 447 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3268 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: HEIGHT  */
#line 450 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3276 "src-generated/ugbc.tab.c"
    break;

  case 108: /* exponential: TIMER  */
#line 453 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3284 "src-generated/ugbc.tab.c"
    break;

  case 111: /* bank_definition_simple: AT direct_integer  */
#line 461 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3292 "src-generated/ugbc.tab.c"
    break;

  case 112: /* bank_definition_simple: Identifier AT direct_integer  */
#line 464 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3300 "src-generated/ugbc.tab.c"
    break;

  case 113: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 467 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3308 "src-generated/ugbc.tab.c"
    break;

  case 114: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 470 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3316 "src-generated/ugbc.tab.c"
    break;

  case 115: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 473 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3324 "src-generated/ugbc.tab.c"
    break;

  case 116: /* bank_definition_simple: DATA AT direct_integer  */
#line 476 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3332 "src-generated/ugbc.tab.c"
    break;

  case 117: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 480 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3340 "src-generated/ugbc.tab.c"
    break;

  case 118: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 483 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3348 "src-generated/ugbc.tab.c"
    break;

  case 119: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 486 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3356 "src-generated/ugbc.tab.c"
    break;

  case 120: /* bank_definition_simple: CODE AT direct_integer  */
#line 489 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3364 "src-generated/ugbc.tab.c"
    break;

  case 121: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 493 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3372 "src-generated/ugbc.tab.c"
    break;

  case 122: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 496 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3380 "src-generated/ugbc.tab.c"
    break;

  case 123: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 499 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3388 "src-generated/ugbc.tab.c"
    break;

  case 124: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 502 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3396 "src-generated/ugbc.tab.c"
    break;

  case 125: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 506 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3404 "src-generated/ugbc.tab.c"
    break;

  case 126: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 509 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3412 "src-generated/ugbc.tab.c"
    break;

  case 127: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 512 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3420 "src-generated/ugbc.tab.c"
    break;

  case 128: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 515 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3428 "src-generated/ugbc.tab.c"
    break;

  case 129: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 521 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3436 "src-generated/ugbc.tab.c"
    break;

  case 130: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 524 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3444 "src-generated/ugbc.tab.c"
    break;

  case 131: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 527 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3452 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 530 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3460 "src-generated/ugbc.tab.c"
    break;

  case 133: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 533 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3468 "src-generated/ugbc.tab.c"
    break;

  case 136: /* raster_definition_simple: Identifier AT direct_integer  */
#line 542 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3476 "src-generated/ugbc.tab.c"
    break;

  case 137: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 545 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3484 "src-generated/ugbc.tab.c"
    break;

  case 138: /* raster_definition_expression: Identifier AT expr  */
#line 550 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3492 "src-generated/ugbc.tab.c"
    break;

  case 139: /* raster_definition_expression: AT expr WITH Identifier  */
#line 553 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3500 "src-generated/ugbc.tab.c"
    break;

  case 142: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 562 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3508 "src-generated/ugbc.tab.c"
    break;

  case 143: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 565 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3516 "src-generated/ugbc.tab.c"
    break;

  case 144: /* next_raster_definition_expression: Identifier AT expr  */
#line 570 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3524 "src-generated/ugbc.tab.c"
    break;

  case 145: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 573 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3532 "src-generated/ugbc.tab.c"
    break;

  case 148: /* color_definition_simple: BORDER direct_integer  */
#line 582 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3540 "src-generated/ugbc.tab.c"
    break;

  case 149: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 585 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3548 "src-generated/ugbc.tab.c"
    break;

  case 150: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 588 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3556 "src-generated/ugbc.tab.c"
    break;

  case 151: /* color_definition_expression: BORDER expr  */
#line 593 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3564 "src-generated/ugbc.tab.c"
    break;

  case 152: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 596 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3572 "src-generated/ugbc.tab.c"
    break;

  case 153: /* color_definition_expression: SPRITE expr TO expr  */
#line 599 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3580 "src-generated/ugbc.tab.c"
    break;

  case 159: /* wait_definition_simple: direct_integer CYCLES  */
#line 613 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3588 "src-generated/ugbc.tab.c"
    break;

  case 160: /* wait_definition_simple: direct_integer TICKS  */
#line 616 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3596 "src-generated/ugbc.tab.c"
    break;

  case 161: /* wait_definition_simple: direct_integer milliseconds  */
#line 619 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3604 "src-generated/ugbc.tab.c"
    break;

  case 162: /* wait_definition_expression: expr CYCLES  */
#line 624 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3612 "src-generated/ugbc.tab.c"
    break;

  case 163: /* wait_definition_expression: expr TICKS  */
#line 627 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3620 "src-generated/ugbc.tab.c"
    break;

  case 164: /* wait_definition_expression: expr milliseconds  */
#line 630 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3628 "src-generated/ugbc.tab.c"
    break;

  case 167: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 640 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3636 "src-generated/ugbc.tab.c"
    break;

  case 168: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 643 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3644 "src-generated/ugbc.tab.c"
    break;

  case 169: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 646 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3652 "src-generated/ugbc.tab.c"
    break;

  case 170: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 649 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3660 "src-generated/ugbc.tab.c"
    break;

  case 171: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 652 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3668 "src-generated/ugbc.tab.c"
    break;

  case 172: /* sprite_definition_simple: direct_integer ENABLE  */
#line 655 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3676 "src-generated/ugbc.tab.c"
    break;

  case 173: /* sprite_definition_simple: direct_integer DISABLE  */
#line 658 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3684 "src-generated/ugbc.tab.c"
    break;

  case 174: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 661 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3692 "src-generated/ugbc.tab.c"
    break;

  case 175: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 664 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3700 "src-generated/ugbc.tab.c"
    break;

  case 176: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 667 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3708 "src-generated/ugbc.tab.c"
    break;

  case 177: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 670 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3716 "src-generated/ugbc.tab.c"
    break;

  case 178: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 673 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3724 "src-generated/ugbc.tab.c"
    break;

  case 179: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 676 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3732 "src-generated/ugbc.tab.c"
    break;

  case 180: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 679 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3740 "src-generated/ugbc.tab.c"
    break;

  case 181: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 682 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3748 "src-generated/ugbc.tab.c"
    break;

  case 182: /* sprite_definition_expression: expr DATA FROM expr  */
#line 687 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3756 "src-generated/ugbc.tab.c"
    break;

  case 183: /* sprite_definition_expression: expr MULTICOLOR  */
#line 690 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3764 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_expression: expr MONOCOLOR  */
#line 693 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3772 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_expression: expr COLOR expr  */
#line 696 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3780 "src-generated/ugbc.tab.c"
    break;

  case 186: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 699 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3788 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_expression: expr ENABLE  */
#line 702 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3796 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_expression: expr DISABLE  */
#line 705 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3804 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 708 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3812 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 711 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3820 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 714 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3828 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 717 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3836 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 720 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3844 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 723 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3852 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 726 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3860 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 729 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3868 "src-generated/ugbc.tab.c"
    break;

  case 199: /* bitmap_definition_simple: AT direct_integer  */
#line 738 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3876 "src-generated/ugbc.tab.c"
    break;

  case 200: /* bitmap_definition_simple: ENABLE  */
#line 741 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3884 "src-generated/ugbc.tab.c"
    break;

  case 201: /* bitmap_definition_simple: DISABLE  */
#line 744 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 3892 "src-generated/ugbc.tab.c"
    break;

  case 202: /* bitmap_definition_simple: CLEAR  */
#line 747 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 3900 "src-generated/ugbc.tab.c"
    break;

  case 203: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 750 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 3908 "src-generated/ugbc.tab.c"
    break;

  case 204: /* bitmap_definition_expression: AT expr  */
#line 756 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3916 "src-generated/ugbc.tab.c"
    break;

  case 205: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 759 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 3924 "src-generated/ugbc.tab.c"
    break;

  case 208: /* textmap_definition_simple: AT direct_integer  */
#line 769 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3932 "src-generated/ugbc.tab.c"
    break;

  case 209: /* textmap_definition_expression: AT expr  */
#line 774 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3940 "src-generated/ugbc.tab.c"
    break;

  case 212: /* text_definition_simple: ENABLE  */
#line 783 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3948 "src-generated/ugbc.tab.c"
    break;

  case 213: /* text_definition_simple: DISABLE  */
#line 786 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 3956 "src-generated/ugbc.tab.c"
    break;

  case 214: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 791 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 3964 "src-generated/ugbc.tab.c"
    break;

  case 215: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 794 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 3972 "src-generated/ugbc.tab.c"
    break;

  case 218: /* tiles_definition_simple: AT direct_integer  */
#line 803 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 3980 "src-generated/ugbc.tab.c"
    break;

  case 219: /* tiles_definition_expression: AT expr  */
#line 808 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 3988 "src-generated/ugbc.tab.c"
    break;

  case 222: /* colormap_definition_simple: AT direct_integer  */
#line 817 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 3996 "src-generated/ugbc.tab.c"
    break;

  case 223: /* colormap_definition_simple: CLEAR  */
#line 820 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4004 "src-generated/ugbc.tab.c"
    break;

  case 224: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 823 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4012 "src-generated/ugbc.tab.c"
    break;

  case 225: /* colormap_definition_expression: AT expr  */
#line 828 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4020 "src-generated/ugbc.tab.c"
    break;

  case 226: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 831 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4028 "src-generated/ugbc.tab.c"
    break;

  case 229: /* screen_definition_simple: ON  */
#line 841 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4036 "src-generated/ugbc.tab.c"
    break;

  case 230: /* screen_definition_simple: OFF  */
#line 844 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4044 "src-generated/ugbc.tab.c"
    break;

  case 231: /* screen_definition_simple: ROWS direct_integer  */
#line 847 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4052 "src-generated/ugbc.tab.c"
    break;

  case 232: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 850 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4060 "src-generated/ugbc.tab.c"
    break;

  case 233: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 853 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4068 "src-generated/ugbc.tab.c"
    break;

  case 234: /* screen_definition_expression: ROWS expr  */
#line 858 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4076 "src-generated/ugbc.tab.c"
    break;

  case 235: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 861 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4084 "src-generated/ugbc.tab.c"
    break;

  case 236: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 864 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4092 "src-generated/ugbc.tab.c"
    break;

  case 240: /* var_definition_simple: Identifier ON Identifier  */
#line 873 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4100 "src-generated/ugbc.tab.c"
    break;

  case 241: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 876 "src/ugbc.y"
                                    {
      variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4108 "src-generated/ugbc.tab.c"
    break;

  case 242: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 879 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4116 "src-generated/ugbc.tab.c"
    break;

  case 243: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 882 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4126 "src-generated/ugbc.tab.c"
    break;

  case 244: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 887 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4136 "src-generated/ugbc.tab.c"
    break;

  case 245: /* goto_definition: Identifier  */
#line 894 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4144 "src-generated/ugbc.tab.c"
    break;

  case 246: /* goto_definition: Integer  */
#line 897 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4152 "src-generated/ugbc.tab.c"
    break;

  case 247: /* gosub_definition: Identifier  */
#line 903 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4160 "src-generated/ugbc.tab.c"
    break;

  case 248: /* gosub_definition: Integer  */
#line 906 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4168 "src-generated/ugbc.tab.c"
    break;

  case 250: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 915 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4176 "src-generated/ugbc.tab.c"
    break;

  case 251: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 921 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4184 "src-generated/ugbc.tab.c"
    break;

  case 254: /* ink_definition: expr  */
#line 930 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4192 "src-generated/ugbc.tab.c"
    break;

  case 255: /* on_goto_definition: Identifier  */
#line 935 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4201 "src-generated/ugbc.tab.c"
    break;

  case 256: /* $@1: %empty  */
#line 939 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4209 "src-generated/ugbc.tab.c"
    break;

  case 258: /* on_gosub_definition: Identifier  */
#line 944 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4218 "src-generated/ugbc.tab.c"
    break;

  case 259: /* $@2: %empty  */
#line 948 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4226 "src-generated/ugbc.tab.c"
    break;

  case 261: /* $@3: %empty  */
#line 953 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4234 "src-generated/ugbc.tab.c"
    break;

  case 263: /* $@4: %empty  */
#line 956 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4242 "src-generated/ugbc.tab.c"
    break;

  case 265: /* every_definition: expr TICKS GOSUB Identifier  */
#line 961 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4250 "src-generated/ugbc.tab.c"
    break;

  case 266: /* every_definition: ON  */
#line 964 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4258 "src-generated/ugbc.tab.c"
    break;

  case 267: /* every_definition: OFF  */
#line 967 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4266 "src-generated/ugbc.tab.c"
    break;

  case 268: /* add_definition: Identifier COMMA expr  */
#line 972 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4274 "src-generated/ugbc.tab.c"
    break;

  case 269: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 975 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4282 "src-generated/ugbc.tab.c"
    break;

  case 286: /* statement: INC Identifier  */
#line 997 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 4290 "src-generated/ugbc.tab.c"
    break;

  case 287: /* statement: DEC Identifier  */
#line 1000 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 4298 "src-generated/ugbc.tab.c"
    break;

  case 288: /* statement: RANDOMIZE  */
#line 1003 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 4306 "src-generated/ugbc.tab.c"
    break;

  case 289: /* statement: RANDOMIZE expr  */
#line 1006 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 4314 "src-generated/ugbc.tab.c"
    break;

  case 290: /* statement: IF expr THEN  */
#line 1009 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4322 "src-generated/ugbc.tab.c"
    break;

  case 291: /* statement: ELSE  */
#line 1012 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 4330 "src-generated/ugbc.tab.c"
    break;

  case 292: /* statement: ELSE IF expr THEN  */
#line 1015 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4338 "src-generated/ugbc.tab.c"
    break;

  case 293: /* statement: ENDIF  */
#line 1018 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 4346 "src-generated/ugbc.tab.c"
    break;

  case 294: /* statement: DO  */
#line 1021 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 4354 "src-generated/ugbc.tab.c"
    break;

  case 295: /* statement: LOOP  */
#line 1024 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 4362 "src-generated/ugbc.tab.c"
    break;

  case 296: /* $@5: %empty  */
#line 1027 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 4370 "src-generated/ugbc.tab.c"
    break;

  case 297: /* statement: WHILE $@5 expr  */
#line 1029 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 4378 "src-generated/ugbc.tab.c"
    break;

  case 298: /* statement: WEND  */
#line 1032 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 4386 "src-generated/ugbc.tab.c"
    break;

  case 299: /* statement: REPEAT  */
#line 1035 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 4394 "src-generated/ugbc.tab.c"
    break;

  case 300: /* statement: UNTIL expr  */
#line 1038 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 4402 "src-generated/ugbc.tab.c"
    break;

  case 301: /* statement: EXIT  */
#line 1041 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 4410 "src-generated/ugbc.tab.c"
    break;

  case 302: /* statement: EXIT IF expr  */
#line 1044 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 4418 "src-generated/ugbc.tab.c"
    break;

  case 303: /* statement: EXIT Integer  */
#line 1047 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4426 "src-generated/ugbc.tab.c"
    break;

  case 304: /* statement: EXIT direct_integer  */
#line 1050 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4434 "src-generated/ugbc.tab.c"
    break;

  case 305: /* statement: EXIT IF expr COMMA Integer  */
#line 1053 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4442 "src-generated/ugbc.tab.c"
    break;

  case 306: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1056 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4450 "src-generated/ugbc.tab.c"
    break;

  case 307: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1059 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4458 "src-generated/ugbc.tab.c"
    break;

  case 308: /* statement: NEXT  */
#line 1062 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 4466 "src-generated/ugbc.tab.c"
    break;

  case 309: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1065 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4474 "src-generated/ugbc.tab.c"
    break;

  case 310: /* statement: BEG GAMELOOP  */
#line 1068 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 4482 "src-generated/ugbc.tab.c"
    break;

  case 311: /* statement: END GAMELOOP  */
#line 1071 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 4490 "src-generated/ugbc.tab.c"
    break;

  case 312: /* statement: GRAPHIC  */
#line 1074 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 4498 "src-generated/ugbc.tab.c"
    break;

  case 313: /* statement: HALT  */
#line 1077 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 4506 "src-generated/ugbc.tab.c"
    break;

  case 318: /* statement: RETURN  */
#line 1084 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 4514 "src-generated/ugbc.tab.c"
    break;

  case 319: /* statement: POP  */
#line 1087 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 4522 "src-generated/ugbc.tab.c"
    break;

  case 320: /* statement: DONE  */
#line 1090 "src/ugbc.y"
          {
      return 0;
  }
#line 4530 "src-generated/ugbc.tab.c"
    break;

  case 321: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1093 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4538 "src-generated/ugbc.tab.c"
    break;

  case 322: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1096 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4546 "src-generated/ugbc.tab.c"
    break;

  case 323: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1099 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 4554 "src-generated/ugbc.tab.c"
    break;

  case 324: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1102 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4562 "src-generated/ugbc.tab.c"
    break;

  case 325: /* statement: Identifier COLON  */
#line 1105 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 4570 "src-generated/ugbc.tab.c"
    break;

  case 326: /* statement: Identifier ASSIGN expr  */
#line 1108 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 4584 "src-generated/ugbc.tab.c"
    break;

  case 327: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1117 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 4598 "src-generated/ugbc.tab.c"
    break;

  case 328: /* statement: DEBUG expr  */
#line 1126 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 4606 "src-generated/ugbc.tab.c"
    break;

  case 331: /* statements_no_linenumbers: statement  */
#line 1134 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 4612 "src-generated/ugbc.tab.c"
    break;

  case 332: /* $@6: %empty  */
#line 1135 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 4618 "src-generated/ugbc.tab.c"
    break;

  case 334: /* $@7: %empty  */
#line 1139 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 4626 "src-generated/ugbc.tab.c"
    break;

  case 335: /* statements_with_linenumbers: Integer $@7 statements_no_linenumbers  */
#line 1141 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 4634 "src-generated/ugbc.tab.c"
    break;

  case 340: /* $@8: %empty  */
#line 1153 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 4640 "src-generated/ugbc.tab.c"
    break;


#line 4644 "src-generated/ugbc.tab.c"

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

#line 1155 "src/ugbc.y"


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
        variable_define( _environment, "text_address", VT_ADDRESS, 0x0400 );
    } else {
        outhead0("org 32768");
        variable_define( _environment, "strings_address", VT_ADDRESS, 0xa000 );
        variable_define( _environment, "bitmap_enabled", VT_BYTE, 0 );
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

