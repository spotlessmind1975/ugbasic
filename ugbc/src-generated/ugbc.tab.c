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
  YYSYMBOL_POWERING = 141,                 /* POWERING  */
  YYSYMBOL_MILLISECOND = 142,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 143,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 144,                    /* TICKS  */
  YYSYMBOL_BLACK = 145,                    /* BLACK  */
  YYSYMBOL_WHITE = 146,                    /* WHITE  */
  YYSYMBOL_RED = 147,                      /* RED  */
  YYSYMBOL_CYAN = 148,                     /* CYAN  */
  YYSYMBOL_VIOLET = 149,                   /* VIOLET  */
  YYSYMBOL_GREEN = 150,                    /* GREEN  */
  YYSYMBOL_BLUE = 151,                     /* BLUE  */
  YYSYMBOL_YELLOW = 152,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 153,                   /* ORANGE  */
  YYSYMBOL_BROWN = 154,                    /* BROWN  */
  YYSYMBOL_LIGHT = 155,                    /* LIGHT  */
  YYSYMBOL_DARK = 156,                     /* DARK  */
  YYSYMBOL_GREY = 157,                     /* GREY  */
  YYSYMBOL_GRAY = 158,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 159,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 160,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 161,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 162,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 163,                /* TURQUOISE  */
  YYSYMBOL_TAN = 164,                      /* TAN  */
  YYSYMBOL_PINK = 165,                     /* PINK  */
  YYSYMBOL_PEACH = 166,                    /* PEACH  */
  YYSYMBOL_OLIVE = 167,                    /* OLIVE  */
  YYSYMBOL_Identifier = 168,               /* Identifier  */
  YYSYMBOL_String = 169,                   /* String  */
  YYSYMBOL_Integer = 170,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 171,                 /* $accept  */
  YYSYMBOL_expr = 172,                     /* expr  */
  YYSYMBOL_expr_math = 173,                /* expr_math  */
  YYSYMBOL_term = 174,                     /* term  */
  YYSYMBOL_modula = 175,                   /* modula  */
  YYSYMBOL_factor = 176,                   /* factor  */
  YYSYMBOL_direct_integer = 177,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 178, /* random_definition_simple  */
  YYSYMBOL_random_definition = 179,        /* random_definition  */
  YYSYMBOL_color_enumeration = 180,        /* color_enumeration  */
  YYSYMBOL_exponential = 181,              /* exponential  */
  YYSYMBOL_position = 182,                 /* position  */
  YYSYMBOL_bank_definition_simple = 183,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 184, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 185,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 186, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 187, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 188,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 189, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 190, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 191,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 192,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 193, /* color_definition_expression  */
  YYSYMBOL_color_definition = 194,         /* color_definition  */
  YYSYMBOL_milliseconds = 195,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 196,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 197, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 198,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 199, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 200, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 201,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 202, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 203, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 204,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 205, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 206, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 207,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 208,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 209, /* text_definition_expression  */
  YYSYMBOL_text_definition = 210,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 211,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 212, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 213,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 214, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 215, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 216,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 217, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 218, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 219,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 220,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 221,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 222,         /* gosub_definition  */
  YYSYMBOL_var_definition = 223,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 224,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 225, /* point_definition_expression  */
  YYSYMBOL_point_definition = 226,         /* point_definition  */
  YYSYMBOL_ink_definition = 227,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 228,       /* on_goto_definition  */
  YYSYMBOL_229_1 = 229,                    /* $@1  */
  YYSYMBOL_on_gosub_definition = 230,      /* on_gosub_definition  */
  YYSYMBOL_231_2 = 231,                    /* $@2  */
  YYSYMBOL_on_definition = 232,            /* on_definition  */
  YYSYMBOL_233_3 = 233,                    /* $@3  */
  YYSYMBOL_234_4 = 234,                    /* $@4  */
  YYSYMBOL_every_definition = 235,         /* every_definition  */
  YYSYMBOL_add_definition = 236,           /* add_definition  */
  YYSYMBOL_statement = 237,                /* statement  */
  YYSYMBOL_238_5 = 238,                    /* $@5  */
  YYSYMBOL_statements_no_linenumbers = 239, /* statements_no_linenumbers  */
  YYSYMBOL_240_6 = 240,                    /* $@6  */
  YYSYMBOL_statements_with_linenumbers = 241, /* statements_with_linenumbers  */
  YYSYMBOL_242_7 = 242,                    /* $@7  */
  YYSYMBOL_statements_complex = 243,       /* statements_complex  */
  YYSYMBOL_program = 244,                  /* program  */
  YYSYMBOL_245_8 = 245                     /* $@8  */
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
#define YYLAST   1995

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  171
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  342
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  676

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   425


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
     165,   166,   167,   168,   169,   170
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    70,    74,    78,    81,    84,    87,    90,
      93,    96,   102,   103,   106,   113,   114,   118,   119,   123,
     130,   131,   135,   142,   147,   150,   153,   156,   159,   162,
     165,   170,   175,   179,   183,   187,   191,   195,   199,   203,
     207,   211,   215,   219,   223,   227,   231,   235,   239,   243,
     247,   251,   255,   259,   263,   267,   271,   275,   279,   285,
     288,   291,   300,   304,   311,   315,   319,   323,   327,   331,
     335,   339,   343,   346,   349,   352,   355,   358,   361,   364,
     367,   370,   373,   376,   379,   382,   385,   388,   391,   394,
     397,   400,   403,   406,   409,   412,   415,   418,   421,   424,
     427,   430,   433,   436,   439,   443,   447,   451,   454,   457,
     462,   462,   465,   468,   471,   474,   477,   480,   484,   487,
     490,   493,   497,   500,   503,   506,   510,   513,   516,   519,
     525,   528,   531,   534,   537,   542,   543,   546,   549,   554,
     557,   562,   563,   566,   569,   574,   577,   582,   583,   586,
     589,   592,   597,   600,   603,   608,   609,   612,   613,   614,
     617,   620,   623,   628,   631,   634,   640,   641,   644,   647,
     650,   653,   656,   659,   662,   665,   668,   671,   674,   677,
     680,   683,   686,   691,   694,   697,   700,   703,   706,   709,
     712,   715,   718,   721,   724,   727,   730,   733,   738,   739,
     742,   745,   748,   751,   754,   760,   763,   769,   770,   773,
     778,   783,   784,   787,   790,   795,   798,   803,   804,   807,
     812,   817,   818,   821,   824,   827,   832,   835,   841,   842,
     845,   848,   851,   854,   857,   862,   865,   868,   873,   874,
     876,   877,   880,   883,   886,   891,   898,   901,   907,   910,
     916,   919,   925,   930,   931,   934,   939,   943,   943,   948,
     952,   952,   957,   957,   960,   960,   965,   968,   971,   976,
     979,   985,   986,   987,   988,   989,   990,   991,   992,   993,
     994,   995,   996,   997,   998,   999,  1000,  1001,  1004,  1007,
    1010,  1013,  1016,  1019,  1022,  1025,  1028,  1031,  1031,  1036,
    1039,  1042,  1045,  1048,  1051,  1054,  1057,  1060,  1063,  1066,
    1069,  1072,  1075,  1078,  1081,  1084,  1085,  1086,  1087,  1088,
    1091,  1094,  1097,  1100,  1103,  1106,  1109,  1112,  1121,  1130,
    1133,  1134,  1138,  1139,  1139,  1143,  1143,  1150,  1151,  1152,
    1153,  1157,  1157
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
  "TIMER", "POWERING", "MILLISECOND", "MILLISECONDS", "TICKS", "BLACK",
  "WHITE", "RED", "CYAN", "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE",
  "BROWN", "LIGHT", "DARK", "GREY", "GRAY", "MAGENTA", "PURPLE",
  "LAVENDER", "GOLD", "TURQUOISE", "TAN", "PINK", "PEACH", "OLIVE",
  "Identifier", "String", "Integer", "$accept", "expr", "expr_math",
  "term", "modula", "factor", "direct_integer", "random_definition_simple",
  "random_definition", "color_enumeration", "exponential", "position",
  "bank_definition_simple", "bank_definition_with_payload",
  "bank_definition", "raster_definition_simple",
  "raster_definition_expression", "raster_definition",
  "next_raster_definition_simple", "next_raster_definition_expression",
  "next_raster_definition", "color_definition_simple",
  "color_definition_expression", "color_definition", "milliseconds",
  "wait_definition_simple", "wait_definition_expression",
  "wait_definition", "sprite_definition_simple",
  "sprite_definition_expression", "sprite_definition",
  "bitmap_definition_simple", "bitmap_definition_expression",
  "bitmap_definition", "textmap_definition_simple",
  "textmap_definition_expression", "textmap_definition",
  "text_definition_simple", "text_definition_expression",
  "text_definition", "tiles_definition_simple",
  "tiles_definition_expression", "tiles_definition",
  "colormap_definition_simple", "colormap_definition_expression",
  "colormap_definition", "screen_definition_simple",
  "screen_definition_expression", "screen_definition",
  "var_definition_simple", "goto_definition", "gosub_definition",
  "var_definition", "point_definition_simple",
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
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425
};
#endif

#define YYPACT_NINF (-315)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-261)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -315,    29,   717,  -315,  -315,  -119,  -106,   -21,  -315,    37,
    1378,    45,   -17,  1378,  -315,    22,    74,  1527,   -94,   -91,
    -315,  -315,  -315,  1080,    69,     0,  1527,    13,    24,  -315,
      91,   106,  1527,  1527,  -315,   135,   137,   -31,  -315,  -315,
      97,  -315,   -57,  -315,  1527,     2,  1229,   143,    15,  1527,
      58,  -315,   179,   187,   188,  -315,  -315,  -315,  1378,   170,
    -315,  -315,  -315,  1378,  1378,  1378,  -315,  -315,  -315,    27,
     931,  -315,  -315,   164,   165,   166,    14,    33,  -315,  -315,
     172,   173,  1527,  -315,  -315,   174,   175,   176,   178,   180,
     182,   184,   185,   186,   189,   190,   200,   201,   202,   203,
     205,   209,  -315,  -315,   210,  -315,  -315,  -315,  -315,  -315,
    -315,  -315,    63,  -315,  -315,    -9,     3,  -315,  -315,  -315,
    -315,  -315,  -315,  -315,  -315,  -315,    71,   225,  -315,  -315,
     -62,    26,    92,   136,   117,   -58,  -315,  -315,  -315,  -315,
    -315,   -19,   167,   -18,   -15,   -12,   -10,   223,  -315,  -315,
    -315,    70,   139,  -315,  -315,  -315,  1378,  -315,  -315,   219,
    -315,  -315,  -315,  -315,  -315,  1378,   204,   206,  -315,  -315,
    -315,   -30,  -315,    28,  -315,  -315,  -315,  -315,  -315,  1527,
    1527,  -315,  -315,   244,  -315,  -315,  -315,  1378,  -315,  -315,
    -315,  1378,   226,  -315,  -315,  -315,   207,  -315,  -315,  1527,
    1527,  -315,  -315,  1378,  -315,  -315,  -315,   240,  -315,  -315,
    -315,  -315,  -315,  -315,  1527,  1527,  -315,  -315,  -315,   262,
    -315,  -315,   133,  -315,  1527,   271,  -315,  -315,  -315,  -315,
    1527,   266,   835,  -315,   717,   717,   251,   252,  1378,  -315,
    -315,   211,   212,   213,   214,  -315,   247,   253,   254,   255,
     256,    47,   257,  1378,  1378,  1378,  -315,  -315,  -315,  -315,
    -315,  -315,  -315,  -315,  -315,  -315,  1527,  1527,  -315,  1527,
    1527,  1527,  1527,  1527,  1527,  1527,  1527,  1527,  1527,  1527,
    1527,  1527,  1527,  1527,  1527,  1527,  1676,  -315,  -315,  -315,
    -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,
    -315,  -315,  1676,  1676,  1676,  1676,  1676,  1676,  1676,  1676,
    1676,  1676,  1676,  1676,  1676,  1825,  -315,  -315,  -315,  1378,
     263,  -315,  -315,  -315,   245,   167,   270,   167,   272,   167,
     273,   167,   274,   167,  -315,  1527,   267,  -315,  -315,    77,
      88,    46,    51,  -315,  -315,  -315,   261,   167,   268,  -315,
    -315,   112,   116,    56,    75,  -315,  -315,   265,  -315,  -315,
    1378,  -315,  -315,  1378,  1378,  -315,  -315,   269,   140,  -315,
     296,  1527,  -315,  -315,  -315,  -315,  1378,  -315,   297,   298,
    -315,  -315,  1378,   238,   302,  1527,   208,   305,  1527,  -315,
    1527,  -315,   835,  -315,  -315,   145,   146,  -315,  -315,  1527,
     167,  1527,   167,   147,   149,   150,   151,   156,   280,   281,
     292,  -315,   293,   294,   295,   299,   300,   301,   324,   325,
     326,   330,   303,   304,   306,   307,   333,   308,   309,   310,
     311,   313,   342,   345,   318,   319,   320,     1,    92,    92,
     171,   171,   171,   171,   171,   171,   171,   171,   136,   117,
     117,  -315,   327,   328,  1378,    -2,  -315,   167,  -315,   167,
    -315,   167,  -315,   167,    44,  -315,  1527,  -315,  -315,  -315,
    -315,  -315,  -315,  -315,  -315,  1527,  -315,   167,  -315,  -315,
    -315,  -315,  -315,  -315,  -315,  -315,   167,  -315,  -315,  -315,
    -315,  -315,  -315,   191,   192,   193,   349,  1527,   357,   323,
     329,  1527,  1527,   359,   360,  -315,   -66,   312,   215,  1527,
     361,  -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,
    -315,  -315,  -315,  -315,   217,   220,   221,  -315,  -315,  -315,
    -315,  -315,  -315,  1527,  1527,  1527,  1527,  -315,  -315,  -315,
    -315,  1527,  -315,  -315,  -315,  -315,  -315,  1527,  1527,  -315,
    -315,  -315,  1825,   224,   227,  -315,  -315,  -315,  -315,  -315,
    -315,   341,  -315,   344,  -315,   216,    34,  -315,   367,  -315,
     369,   371,  -315,   372,  -315,   368,  1378,   373,  1527,  1527,
     167,   347,   354,  1527,   167,  -315,  -315,  1527,  -315,    20,
    1527,  -315,  -315,  -315,   358,   362,    21,    30,   363,   364,
     365,   366,  -315,  -315,   234,   235,  -315,   376,  -315,   377,
    -315,  1527,   167,   387,   389,  1527,  -315,  -315,  1527,  -315,
    -315,  -315,   394,   395,   374,   375,   314,  1527,   398,   340,
    -315,  -315,  1527,  -315,  1527,  -315,  -315,  -315,  -315,  -315,
    -315,  -315,   246,   248,   378,   379,   191,   192,  -315,  -315,
    1527,  1527,  -315,  -315,  1527,   383,  1527,  1527,   384,   385,
    -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,   408,
    -315,  -315,  -315,  -315,  1527,  -315
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     341,     0,   331,     1,   330,     0,     0,     0,   321,     0,
       0,   309,     0,     0,   314,     0,     0,     0,   240,     0,
     296,   300,   297,     0,     0,     0,     0,     0,     0,   294,
       0,     0,     0,   289,   313,     0,     0,     0,   319,   320,
     292,   295,   302,   299,     0,     0,     0,     0,     0,     0,
       0,   335,   332,   337,   339,   342,   287,   288,     0,     0,
     141,   142,   272,     0,     0,     0,   155,   156,   274,     0,
       0,    75,    76,     0,     0,     0,     0,     0,   107,   108,
       0,     0,     0,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   106,   109,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,    44,    49,    50,
      51,    52,    53,    54,    57,    58,     0,    59,    63,    61,
       0,     2,    12,    15,    17,     0,    72,    20,   166,   167,
     275,     0,     0,     0,     0,     0,     0,     0,   135,   136,
     271,     0,     0,   198,   199,   276,     0,   201,   202,   203,
     207,   208,   277,   230,   231,     0,     0,     0,   238,   239,
     282,     0,   315,     0,   250,   285,   246,   247,   316,     0,
       0,   213,   214,     0,   217,   218,   279,     0,   221,   222,
     280,     0,   224,   228,   229,   281,     0,   311,   312,     0,
       0,   329,   290,     0,   211,   212,   278,     0,   253,   254,
     283,   248,   249,   317,     0,     0,   304,   305,   301,     0,
     267,   268,     0,   318,     0,     0,   286,   255,   284,   326,
       0,     0,   331,   333,   331,   331,     0,     0,     0,   152,
     149,     0,     0,     0,     0,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    24,    25,    27,
      29,    30,    26,    31,    97,    23,     0,     0,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    42,    45,
      46,    47,    48,    43,    56,    60,   157,   163,   158,   159,
     164,   165,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   160,   161,   162,     0,
       0,   147,   148,   273,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,     0,     0,   188,   189,     0,
       0,     0,     0,   185,   184,   110,     0,     0,     0,   173,
     174,     0,     0,     0,     0,   170,   169,     0,   205,   200,
       0,   235,   232,     0,     0,   262,   264,     0,     0,   298,
       0,     0,   220,   219,   226,   223,     0,   291,     0,     0,
     210,   209,     0,     0,   303,     0,     0,     0,     0,   327,
       0,   336,   331,   338,   340,     0,     0,   139,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    14,
       5,     7,     8,     9,    10,     6,     3,     4,    16,    18,
      19,    21,     0,     0,     0,     0,   117,     0,   129,     0,
     121,     0,   125,     0,   113,   186,     0,   193,   192,   197,
     196,   191,   195,   190,   194,     0,   171,     0,   178,   177,
     182,   181,   176,   180,   175,   179,     0,   206,   204,   236,
     233,   237,   234,     0,     0,     0,   241,     0,     0,     0,
       0,     0,     0,     0,     0,   293,     0,     0,     0,     0,
     269,   328,   334,   140,   138,   154,   151,   153,   150,    71,
      64,    66,    70,    68,     0,     0,     0,    74,    73,    78,
      77,    80,    79,     0,     0,     0,     0,    87,    88,    89,
      96,     0,    90,    91,    92,    93,    94,     0,     0,   102,
     103,    98,     0,     0,     0,   145,   143,   114,   127,   119,
     122,   116,   128,   120,   124,     0,     0,   183,     0,   168,
       0,   256,   263,   259,   265,   242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,   307,     0,   266,     0,
       0,    65,    67,    69,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   144,     0,     0,   130,   115,   126,   118,
     123,     0,     0,     0,     0,     0,   244,   243,     0,   216,
     227,   225,     0,     0,     0,     0,   308,     0,     0,     0,
      81,    82,     0,    83,     0,    85,    95,   101,   100,    22,
     132,   134,     0,     0,     0,     0,     0,     0,   245,   215,
       0,     0,   252,   251,     0,     0,     0,     0,     0,     0,
     131,   133,   187,   172,   258,   261,   322,   323,   310,     0,
     324,   270,    84,    86,     0,   325
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -315,   -13,   -78,  -121,   110,  -260,   260,  -315,  -315,  -315,
    -314,   275,  -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,
    -315,  -315,  -315,  -315,   288,  -315,  -315,  -315,  -315,  -315,
    -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,
    -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,
    -315,  -315,  -315,  -315,  -315,  -315,  -315,  -222,  -315,  -221,
    -315,  -315,  -315,  -315,  -315,  -315,  -315,  -315,  -230,  -315,
    -315,  -315,   -46,  -315,  -315
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   130,   131,   132,   133,   134,   135,   263,   264,   136,
     137,   346,   148,   149,   150,    60,    61,    62,   321,   322,
     323,    66,    67,    68,   301,   138,   139,   140,   153,   154,
     155,   160,   161,   162,   204,   205,   206,   184,   185,   186,
     188,   189,   190,   193,   194,   195,   168,   169,   170,   174,
     178,   213,   175,   208,   209,   210,   228,   572,   613,   574,
     614,   172,   493,   494,   223,   226,    52,   179,    53,   392,
      54,   232,    55,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     151,   451,   391,    58,   171,   319,   325,   142,   552,   327,
     183,   215,   329,   196,   331,   143,    77,   296,   297,   201,
     202,   296,   316,   365,   191,    77,   437,   627,   632,     3,
     557,   218,   144,   222,   302,   303,   227,   634,   304,   256,
     305,   306,   307,   308,   309,   236,   156,   558,   367,    56,
     239,   241,   243,   449,   450,   628,   633,   252,   157,   158,
     145,   146,    57,    63,   229,   635,   607,   141,    64,   268,
     368,   230,   366,   565,   173,   559,   560,   176,   231,   177,
     298,   299,   300,   608,   298,   299,   317,   192,   257,   258,
     259,   471,   566,   187,   334,   335,   473,   260,   261,   262,
     472,   482,   336,   197,   585,   474,   337,   338,    65,   159,
     483,   609,   610,   216,   198,   339,   163,   164,   165,   166,
     484,   408,   409,   310,   340,   199,   341,   342,   167,   485,
     315,   311,   410,   467,   468,   343,   344,   211,   288,   212,
     200,   289,   290,   358,   469,   470,   345,    59,   291,   320,
     326,   147,   361,   328,   292,   313,   330,   314,   332,   203,
     293,   207,   512,   334,   347,   214,   369,   370,   478,   479,
     219,   348,   480,   481,   372,   349,   350,   224,   374,   302,
     303,   438,   439,   225,   351,   233,   378,   379,   393,   394,
     380,   234,   235,   352,   238,   353,   354,   245,   253,   254,
     255,   383,   384,   265,   355,   356,   266,   267,   269,   270,
     271,   387,   272,   287,   273,   345,   274,   389,   275,   276,
     277,   294,   312,   278,   279,   397,   440,   441,   442,   443,
     444,   445,   446,   447,   280,   281,   282,   283,   601,   284,
     412,   414,   416,   285,   286,   295,   315,   333,   360,    77,
     363,   371,   364,   418,   419,   376,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   152,   382,   385,   377,   386,   388,   390,
     395,   396,   403,   399,   400,   401,   402,   454,   404,   405,
     406,   407,   411,   455,   457,   475,   459,   461,   463,   486,
     466,   477,   217,   497,   501,   502,   452,   505,   496,   506,
     508,   495,   509,   513,   514,   524,   525,   519,   237,   520,
     521,   522,   465,   240,   242,   244,   523,   526,   527,   528,
     529,   533,   534,   535,   530,   531,   532,   536,   537,   538,
     541,   539,   540,   542,   543,   544,   545,   487,   546,   547,
     489,   491,   548,   549,   550,   551,   553,   554,   498,   571,
     573,   575,   576,   499,   578,   579,   583,   584,   590,   503,
     604,   580,   507,   605,   611,   510,   612,   511,  -257,  -260,
     618,   615,   622,   588,   587,   606,   515,   591,   517,   623,
     592,   593,   602,   630,   646,   603,   647,   631,   636,   637,
     638,   639,   324,   640,   641,   642,   643,   650,   651,   652,
     653,   656,   657,   662,   663,   660,   359,   661,   669,   672,
     673,   674,   448,   318,   664,   362,   665,   357,     0,   654,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,   373,     0,     0,
       0,   375,     0,   567,     0,     0,     0,     0,     0,     0,
       0,     0,   568,   381,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   577,     0,     0,     0,   581,   582,
       0,     0,     0,     0,     0,     0,   589,     0,   398,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   413,   415,   417,     0,     0,     0,     0,
     594,   595,   596,   597,     0,     0,     0,     0,   598,     0,
       0,     0,     0,     0,   599,   600,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   616,     0,   619,   620,     0,     0,     0,
     624,     0,     0,     0,   626,     0,     0,   629,     0,   453,
       0,     0,     0,     0,     0,   456,     0,   458,     0,   460,
       0,   462,     0,   464,     0,     0,     0,     0,   644,     0,
       0,     0,   648,     0,     0,   649,     0,   476,     0,     0,
       0,     0,     0,     0,   655,     0,     0,     0,     0,   658,
     488,   659,     0,   490,   492,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   500,   666,   667,     0,
       0,   668,   504,   670,   671,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     516,   675,   518,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   556,     0,     0,   561,     0,   562,
       4,   563,     0,   564,     0,     0,     0,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,   569,     0,     7,
       8,     0,     9,     0,    10,    11,   570,    12,    13,     0,
       0,     0,     0,     0,     0,    14,     0,    15,    16,    17,
       0,     0,     0,     0,    18,     0,   586,     0,     0,     0,
      19,     0,     0,     0,     0,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    28,     0,    29,     0,
       0,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,     0,    40,     0,     0,     0,    41,    42,    43,
      44,    45,     0,    46,    47,     0,   617,     0,     4,     0,
     621,     0,     0,     0,   625,     5,     6,     0,    48,     0,
       0,     0,     0,     0,     0,     0,    49,     7,     8,     0,
       9,     0,    10,    11,     0,    12,    13,     0,     0,     0,
       0,     0,   645,    14,     0,    15,    16,    17,     0,     0,
       0,     0,    18,     0,     0,    50,     0,    51,    19,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    28,     0,    29,     0,     0,    30,
      31,    32,     0,    33,    34,    35,    36,    37,    38,    39,
      69,    40,     0,     0,     0,    41,    42,    43,    44,    45,
       0,    46,    47,     0,     0,     0,   246,     0,     0,     0,
       0,     0,     0,     0,     0,    70,    48,     0,     0,     0,
       0,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,    71,    72,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,     0,
       0,    75,     0,    50,    76,   247,   248,   249,     0,     0,
       0,     0,     0,     0,    78,    79,   250,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
       0,     0,     0,    97,    98,    99,   251,   100,   101,   102,
       0,   103,   104,     0,     0,     0,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    69,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,   181,   182,     0,     0,
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
     103,   104,     0,     0,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    69,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,     0,     0,     0,     0,     0,
       0,   220,   221,     0,     0,     0,     0,     0,     0,    71,
      72,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,     0,     0,    75,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,     0,     0,
       0,    97,    98,    99,     0,   100,   101,   102,     0,   103,
     104,     0,     0,     0,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    69,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    71,    72,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,     0,    75,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    78,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,     0,     0,     0,
      97,    98,    99,     0,   100,   101,   102,     0,   103,   104,
       0,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    69,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    71,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,     0,    75,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,     0,     0,     0,    97,
      98,    99,     0,   100,   101,   102,     0,   103,   104,     0,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    69,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,     0,    75,     0,     0,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,     0,     0,     0,    97,    98,
      99,     0,   100,   101,   102,     0,   103,   104,     0,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    69,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,    72,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,    75,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    84,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,     0,     0,     0,    97,    98,    99,
       0,   100,   101,   102,     0,   103,     0,     0,     0,     0,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129
};

static const yytype_int16 yycheck[] =
{
      13,   315,   232,    24,    17,    24,    24,    24,     7,    24,
      23,    68,    24,    26,    24,    32,    82,    79,    80,    32,
      33,    79,    80,    53,    24,    82,   286,     7,     7,     0,
      32,    44,    49,    46,     8,     9,    49,     7,    12,    25,
      14,    15,    16,    17,    18,    58,    24,    49,    20,   168,
      63,    64,    65,   313,   314,    35,    35,    70,    36,    37,
      77,    78,   168,    26,     6,    35,    32,    22,    31,    82,
      42,    13,   102,    29,   168,    77,    78,   168,    20,   170,
     142,   143,   144,    49,   142,   143,   144,    87,    74,    75,
      76,    45,    48,    24,    24,    25,    45,    83,    84,    85,
      54,    45,    32,    90,   170,    54,    36,    37,    71,    87,
      54,    77,    78,   170,    90,    45,    42,    43,    44,    45,
      45,    74,    75,    97,    54,    34,    56,    57,    54,    54,
     129,   105,    85,    56,    57,    65,    66,   168,   147,   170,
      34,   150,   151,   156,    56,    57,    76,   168,   157,   168,
     168,   168,   165,   168,   151,    19,   168,    21,   168,    24,
     157,    24,   392,    24,    25,    68,   179,   180,    56,    57,
     168,    32,    56,    57,   187,    36,    37,    34,   191,     8,
       9,   302,   303,   168,    45,     6,   199,   200,   234,   235,
     203,     4,     4,    54,    24,    56,    57,   170,    34,    34,
      34,   214,   215,   170,    65,    66,    34,    34,    34,    34,
      34,   224,    34,   150,    34,    76,    34,   230,    34,    34,
      34,   150,   130,    34,    34,   238,   304,   305,   306,   307,
     308,   309,   310,   311,    34,    34,    34,    34,   552,    34,
     253,   254,   255,    34,    34,    20,   129,    24,    29,    82,
      46,     7,    46,   266,   267,    29,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,    13,    34,    13,    69,   144,     7,    13,
      29,    29,    35,    72,    72,    72,    72,    24,    35,    35,
      35,    35,    35,    48,    24,    34,    24,    24,    24,    34,
      33,    33,    42,     7,     7,     7,   319,    69,   168,     7,
     102,    42,     7,   168,   168,    35,    35,   170,    58,   170,
     170,   170,   335,    63,    64,    65,   170,    35,    35,    35,
      35,     7,     7,     7,    35,    35,    35,     7,    35,    35,
       7,    35,    35,    35,    35,    35,    35,   360,    35,     7,
     363,   364,     7,    35,    35,    35,    29,    29,   371,   168,
     168,   168,    13,   376,     7,    42,     7,     7,     7,   382,
      29,    42,   385,    29,     7,   388,     7,   390,     7,     7,
       7,    13,    35,   168,    72,   169,   399,   170,   401,    35,
     170,   170,   168,    35,     7,   168,     7,    35,    35,    35,
      35,    35,   142,   169,   169,    29,    29,    13,    13,    35,
      35,    13,    72,    35,    35,   169,   156,   169,    35,    35,
      35,    13,   312,   135,   646,   165,   647,   152,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   454,    -1,    -1,    -1,    -1,    -1,   187,    -1,    -1,
      -1,   191,    -1,   466,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   475,   203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   497,    -1,    -1,    -1,   501,   502,
      -1,    -1,    -1,    -1,    -1,    -1,   509,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   254,   255,    -1,    -1,    -1,    -1,
     533,   534,   535,   536,    -1,    -1,    -1,    -1,   541,    -1,
      -1,    -1,    -1,    -1,   547,   548,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   576,    -1,   578,   579,    -1,    -1,    -1,
     583,    -1,    -1,    -1,   587,    -1,    -1,   590,    -1,   319,
      -1,    -1,    -1,    -1,    -1,   325,    -1,   327,    -1,   329,
      -1,   331,    -1,   333,    -1,    -1,    -1,    -1,   611,    -1,
      -1,    -1,   615,    -1,    -1,   618,    -1,   347,    -1,    -1,
      -1,    -1,    -1,    -1,   627,    -1,    -1,    -1,    -1,   632,
     360,   634,    -1,   363,   364,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   376,   650,   651,    -1,
      -1,   654,   382,   656,   657,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     400,   674,   402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   454,    -1,    -1,   457,    -1,   459,
       3,   461,    -1,   463,    -1,    -1,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   477,    -1,    22,
      23,    -1,    25,    -1,    27,    28,   486,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    42,
      -1,    -1,    -1,    -1,    47,    -1,   506,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,    -1,
      -1,    94,    95,    96,    -1,    98,    99,   100,   101,   102,
     103,   104,    -1,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,    -1,   116,   117,    -1,   576,    -1,     3,    -1,
     580,    -1,    -1,    -1,   584,    10,    11,    -1,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    22,    23,    -1,
      25,    -1,    27,    28,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,   612,    38,    -1,    40,    41,    42,    -1,    -1,
      -1,    -1,    47,    -1,    -1,   168,    -1,   170,    53,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    91,    -1,    -1,    94,
      95,    96,    -1,    98,    99,   100,   101,   102,   103,   104,
       9,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
      -1,   116,   117,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    70,    -1,   168,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,   135,   136,   137,   138,
      -1,   140,   141,    -1,    -1,    -1,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,     9,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    36,    37,    -1,    -1,
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
     140,   141,    -1,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     9,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,   137,   138,    -1,   140,
     141,    -1,    -1,    -1,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     9,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,   137,   138,    -1,   140,   141,
      -1,    -1,    -1,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     9,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,   141,    -1,
      -1,    -1,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     9,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,   132,   133,
     134,    -1,   136,   137,   138,    -1,   140,   141,    -1,    -1,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     9,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,   136,   137,   138,    -1,   140,    -1,    -1,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    -1,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   244,   245,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    88,    89,    91,
      94,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     106,   110,   111,   112,   113,   114,   116,   117,   131,   139,
     168,   170,   237,   239,   241,   243,   168,   168,    24,   168,
     186,   187,   188,    26,    31,    71,   192,   193,   194,     9,
      34,    50,    51,    52,    67,    70,    73,    82,    83,    84,
      94,    95,   107,   108,   109,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   132,   133,   134,
     136,   137,   138,   140,   141,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     172,   173,   174,   175,   176,   177,   180,   181,   196,   197,
     198,    22,    24,    32,    49,    77,    78,   168,   183,   184,
     185,   172,   177,   199,   200,   201,    24,    36,    37,    87,
     202,   203,   204,    42,    43,    44,    45,    54,   217,   218,
     219,   172,   232,   168,   220,   223,   168,   170,   221,   238,
      24,    36,    37,   172,   208,   209,   210,    24,   211,   212,
     213,    24,    87,   214,   215,   216,   172,    90,    90,    34,
      34,   172,   172,    24,   205,   206,   207,    24,   224,   225,
     226,   168,   170,   222,    68,    68,   170,   177,   172,   168,
      42,    43,   172,   235,    34,   168,   236,   172,   227,     6,
      13,    20,   242,     6,     4,     4,   172,   177,    24,   172,
     177,   172,   177,   172,   177,   170,    25,    74,    75,    76,
      85,   135,   172,    34,    34,    34,    25,    74,    75,    76,
      83,    84,    85,   178,   179,   170,    34,    34,   172,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,   150,   147,   150,
     151,   157,   151,   157,   150,    20,    79,    80,   142,   143,
     144,   195,     8,     9,    12,    14,    15,    16,    17,    18,
      97,   105,   130,    19,    21,   129,    80,   144,   195,    24,
     168,   189,   190,   191,   177,    24,   168,    24,   168,    24,
     168,    24,   168,    24,    24,    25,    32,    36,    37,    45,
      54,    56,    57,    65,    66,    76,   182,    25,    32,    36,
      37,    45,    54,    56,    57,    65,    66,   182,   172,   177,
      29,   172,   177,    46,    46,    53,   102,    20,    42,   172,
     172,     7,   172,   177,   172,   177,    29,    69,   172,   172,
     172,   177,    34,   172,   172,    13,   144,   172,     7,   172,
      13,   239,   240,   243,   243,    29,    29,   172,   177,    72,
      72,    72,    72,    35,    35,    35,    35,    35,    74,    75,
      85,    35,   172,   177,   172,   177,   172,   177,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   176,   174,   174,
     173,   173,   173,   173,   173,   173,   173,   173,   175,   176,
     176,   181,   172,   177,    24,    48,   177,    24,   177,    24,
     177,    24,   177,    24,   177,   172,    33,    56,    57,    56,
      57,    45,    54,    45,    54,    34,   177,    33,    56,    57,
      56,    57,    45,    54,    45,    54,    34,   172,   177,   172,
     177,   172,   177,   233,   234,    42,   168,     7,   172,   172,
     177,     7,     7,   172,   177,    69,     7,   172,   102,     7,
     172,   172,   239,   168,   168,   172,   177,   172,   177,   170,
     170,   170,   170,   170,    35,    35,    35,    35,    35,    35,
      35,    35,    35,     7,     7,     7,     7,    35,    35,    35,
      35,     7,    35,    35,    35,    35,    35,     7,     7,    35,
      35,    35,     7,    29,    29,   172,   177,    32,    49,    77,
      78,   177,   177,   177,   177,    29,    48,   172,   172,   177,
     177,   168,   228,   168,   230,   168,    13,   172,     7,    42,
      42,   172,   172,     7,     7,   170,   177,    72,   168,   172,
       7,   170,   170,   170,   172,   172,   172,   172,   172,   172,
     172,   181,   168,   168,    29,    29,   169,    32,    49,    77,
      78,     7,     7,   229,   231,    13,   172,   177,     7,   172,
     172,   177,    35,    35,   172,   177,   172,     7,    35,   172,
      35,    35,     7,    35,     7,    35,    35,    35,    35,    35,
     169,   169,    29,    29,   172,   177,     7,     7,   172,   172,
      13,    13,    35,    35,   115,   172,    13,    72,   172,   172,
     169,   169,    35,    35,   228,   230,   172,   172,   172,    35,
     172,   172,    35,    35,    13,   172
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   171,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   173,   173,   173,   174,   174,   175,   175,   175,
     176,   176,   176,   177,   178,   178,   178,   178,   178,   178,
     178,   179,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     182,   182,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     184,   184,   184,   184,   184,   185,   185,   186,   186,   187,
     187,   188,   188,   189,   189,   190,   190,   191,   191,   192,
     192,   192,   193,   193,   193,   194,   194,   195,   195,   195,
     196,   196,   196,   197,   197,   197,   198,   198,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   201,   201,
     202,   202,   202,   202,   202,   203,   203,   204,   204,   205,
     206,   207,   207,   208,   208,   209,   209,   210,   210,   211,
     212,   213,   213,   214,   214,   214,   215,   215,   216,   216,
     217,   217,   217,   217,   217,   218,   218,   218,   219,   219,
     220,   220,   220,   220,   220,   220,   221,   221,   222,   222,
     223,   224,   225,   226,   226,   227,   228,   229,   228,   230,
     231,   230,   233,   232,   234,   232,   235,   235,   235,   236,
     236,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   238,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   239,   240,   239,   242,   241,   243,   243,   243,
     243,   245,   244
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     3,     3,     1,     3,     1,     3,     3,
       1,     3,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       2,     1,     2,     1,     4,     5,     4,     5,     4,     5,
       4,     4,     1,     4,     4,     1,     1,     4,     4,     4,
       4,     6,     6,     6,     8,     6,     8,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     2,     4,     3,
       6,     6,     4,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     4,     5,     4,     3,     5,     4,
       4,     3,     4,     5,     4,     3,     5,     4,     4,     3,
       5,     7,     6,     7,     6,     1,     1,     3,     4,     3,
       4,     1,     1,     3,     4,     3,     4,     1,     1,     2,
       4,     4,     2,     4,     4,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     1,     1,     4,     2,
       2,     3,     7,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     2,     2,     3,     7,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       2,     1,     1,     1,     3,     2,     3,     1,     1,     2,
       2,     1,     1,     1,     1,     6,     5,     1,     1,     2,
       2,     1,     1,     2,     1,     5,     2,     5,     1,     1,
       1,     1,     2,     3,     3,     2,     3,     3,     1,     1,
       0,     3,     4,     5,     5,     6,     1,     1,     1,     1,
       1,     6,     6,     1,     1,     1,     1,     0,     4,     1,
       0,     4,     0,     4,     0,     4,     4,     1,     1,     3,
       7,     2,     2,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     3,     1,     4,     1,     1,     1,     0,     3,     1,
       1,     2,     1,     3,     2,     2,     5,     5,     6,     1,
       8,     2,     2,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     8,     8,     8,    10,     2,     3,     4,     2,
       1,     0,     1,     0,     4,     0,     3,     1,     3,     1,
       3,     0,     2
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
#line 2470 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 74 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2479 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 78 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2487 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 81 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2495 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 84 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2503 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 87 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2511 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 90 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2519 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 93 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2527 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 96 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2535 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 103 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2543 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 106 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2552 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 119 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2561 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 123 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2570 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 131 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2579 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 135 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 2588 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 142 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2596 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 147 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2604 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 150 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2612 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 153 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2620 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 156 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2628 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 159 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2636 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 162 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2644 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 165 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2652 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 170 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2660 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 175 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2669 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 179 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2678 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 183 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2687 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 187 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2696 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 191 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2705 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 195 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2714 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 199 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2723 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 203 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2732 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 207 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2741 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 211 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2750 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 215 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2759 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 219 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2768 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 223 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2777 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 227 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2786 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 231 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2795 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 235 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2804 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 239 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2813 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 243 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2822 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 247 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2831 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 251 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2840 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 255 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2849 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 259 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2858 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 263 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2867 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 267 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2876 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 271 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2885 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 275 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2894 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 279 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2903 "src-generated/ugbc.tab.c"
    break;

  case 59: /* exponential: Identifier  */
#line 285 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2911 "src-generated/ugbc.tab.c"
    break;

  case 60: /* exponential: Identifier DOLLAR  */
#line 288 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[-1].string);
      }
#line 2919 "src-generated/ugbc.tab.c"
    break;

  case 61: /* exponential: Integer  */
#line 291 "src/ugbc.y"
              { 
        if ( (yyvsp[0].integer) < 0 ) {
            (yyval.string) = variable_temporary( _environment, VT_SWORD, "(signed integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        } else {
            (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        }
      }
#line 2933 "src-generated/ugbc.tab.c"
    break;

  case 62: /* exponential: MINUS Integer  */
#line 300 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 2942 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: String  */
#line 304 "src/ugbc.y"
             { 
        outline1("; (expr string: \"%s\")", (yyvsp[0].string) );
        (yyval.string) = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", (yyval.string) );
        variable_store_string( _environment, (yyval.string), (yyvsp[0].string) );
        outline2("; variable stored: %s = %s", (yyval.string), (yyvsp[0].string) );
      }
#line 2954 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: OP BYTE CP Integer  */
#line 311 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2963 "src-generated/ugbc.tab.c"
    break;

  case 65: /* exponential: OP SIGNED BYTE CP Integer  */
#line 315 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2972 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: OP WORD CP Integer  */
#line 319 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2981 "src-generated/ugbc.tab.c"
    break;

  case 67: /* exponential: OP SIGNED WORD CP Integer  */
#line 323 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2990 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP DWORD CP Integer  */
#line 327 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2999 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED DWORD CP Integer  */
#line 331 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3008 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP POSITION CP Integer  */
#line 335 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3017 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP COLOR CP Integer  */
#line 339 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3026 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: color_enumeration  */
#line 343 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3034 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: PEEK OP direct_integer CP  */
#line 346 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3042 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: PEEK OP expr CP  */
#line 349 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3050 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: XPEN  */
#line 352 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3058 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: YPEN  */
#line 355 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3066 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: COLLISION OP direct_integer CP  */
#line 358 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3074 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: COLLISION OP expr CP  */
#line 361 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3082 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: HIT OP direct_integer CP  */
#line 364 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3090 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: HIT OP expr CP  */
#line 367 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3098 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: LEFT OP expr COMMA expr CP  */
#line 370 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3106 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 373 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3114 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: MID OP expr COMMA expr CP  */
#line 376 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3122 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 379 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3130 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: INSTR OP expr COMMA expr CP  */
#line 382 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3138 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 385 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3146 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: UPPER OP expr CP  */
#line 388 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3154 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: LOWER OP expr CP  */
#line 391 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3162 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: STR OP expr CP  */
#line 394 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3170 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: SPACE OP expr CP  */
#line 397 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3178 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: FLIP OP expr CP  */
#line 400 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3186 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: CHR OP expr CP  */
#line 403 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3194 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: ASC OP expr CP  */
#line 406 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3202 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: LEN OP expr CP  */
#line 409 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3210 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: STRING OP expr COMMA expr CP  */
#line 412 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3218 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: VAL OP expr CP  */
#line 415 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3226 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: RANDOM random_definition  */
#line 418 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3234 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: RND OP expr CP  */
#line 421 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3242 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: OP expr CP  */
#line 424 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3250 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: MAX OP expr COMMA expr CP  */
#line 427 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3258 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: MIN OP expr COMMA expr CP  */
#line 430 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3266 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: SGN OP expr CP  */
#line 433 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3274 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: ABS OP expr CP  */
#line 436 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3282 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: TRUE  */
#line 439 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3291 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: FALSE  */
#line 443 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3300 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: COLORS  */
#line 447 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3309 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: WIDTH  */
#line 451 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3317 "src-generated/ugbc.tab.c"
    break;

  case 108: /* exponential: HEIGHT  */
#line 454 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3325 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: TIMER  */
#line 457 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3333 "src-generated/ugbc.tab.c"
    break;

  case 112: /* bank_definition_simple: AT direct_integer  */
#line 465 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3341 "src-generated/ugbc.tab.c"
    break;

  case 113: /* bank_definition_simple: Identifier AT direct_integer  */
#line 468 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3349 "src-generated/ugbc.tab.c"
    break;

  case 114: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 471 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3357 "src-generated/ugbc.tab.c"
    break;

  case 115: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 474 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3365 "src-generated/ugbc.tab.c"
    break;

  case 116: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 477 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3373 "src-generated/ugbc.tab.c"
    break;

  case 117: /* bank_definition_simple: DATA AT direct_integer  */
#line 480 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3381 "src-generated/ugbc.tab.c"
    break;

  case 118: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 484 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3389 "src-generated/ugbc.tab.c"
    break;

  case 119: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 487 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3397 "src-generated/ugbc.tab.c"
    break;

  case 120: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 490 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3405 "src-generated/ugbc.tab.c"
    break;

  case 121: /* bank_definition_simple: CODE AT direct_integer  */
#line 493 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3413 "src-generated/ugbc.tab.c"
    break;

  case 122: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 497 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3421 "src-generated/ugbc.tab.c"
    break;

  case 123: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 500 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3429 "src-generated/ugbc.tab.c"
    break;

  case 124: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 503 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3437 "src-generated/ugbc.tab.c"
    break;

  case 125: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 506 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3445 "src-generated/ugbc.tab.c"
    break;

  case 126: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 510 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3453 "src-generated/ugbc.tab.c"
    break;

  case 127: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 513 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3461 "src-generated/ugbc.tab.c"
    break;

  case 128: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 516 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3469 "src-generated/ugbc.tab.c"
    break;

  case 129: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 519 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3477 "src-generated/ugbc.tab.c"
    break;

  case 130: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 525 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3485 "src-generated/ugbc.tab.c"
    break;

  case 131: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 528 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3493 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 531 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3501 "src-generated/ugbc.tab.c"
    break;

  case 133: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 534 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3509 "src-generated/ugbc.tab.c"
    break;

  case 134: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 537 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3517 "src-generated/ugbc.tab.c"
    break;

  case 137: /* raster_definition_simple: Identifier AT direct_integer  */
#line 546 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3525 "src-generated/ugbc.tab.c"
    break;

  case 138: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 549 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3533 "src-generated/ugbc.tab.c"
    break;

  case 139: /* raster_definition_expression: Identifier AT expr  */
#line 554 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3541 "src-generated/ugbc.tab.c"
    break;

  case 140: /* raster_definition_expression: AT expr WITH Identifier  */
#line 557 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3549 "src-generated/ugbc.tab.c"
    break;

  case 143: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 566 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3557 "src-generated/ugbc.tab.c"
    break;

  case 144: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 569 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3565 "src-generated/ugbc.tab.c"
    break;

  case 145: /* next_raster_definition_expression: Identifier AT expr  */
#line 574 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3573 "src-generated/ugbc.tab.c"
    break;

  case 146: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 577 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3581 "src-generated/ugbc.tab.c"
    break;

  case 149: /* color_definition_simple: BORDER direct_integer  */
#line 586 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3589 "src-generated/ugbc.tab.c"
    break;

  case 150: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 589 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3597 "src-generated/ugbc.tab.c"
    break;

  case 151: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 592 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3605 "src-generated/ugbc.tab.c"
    break;

  case 152: /* color_definition_expression: BORDER expr  */
#line 597 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3613 "src-generated/ugbc.tab.c"
    break;

  case 153: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 600 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3621 "src-generated/ugbc.tab.c"
    break;

  case 154: /* color_definition_expression: SPRITE expr TO expr  */
#line 603 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3629 "src-generated/ugbc.tab.c"
    break;

  case 160: /* wait_definition_simple: direct_integer CYCLES  */
#line 617 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3637 "src-generated/ugbc.tab.c"
    break;

  case 161: /* wait_definition_simple: direct_integer TICKS  */
#line 620 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3645 "src-generated/ugbc.tab.c"
    break;

  case 162: /* wait_definition_simple: direct_integer milliseconds  */
#line 623 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3653 "src-generated/ugbc.tab.c"
    break;

  case 163: /* wait_definition_expression: expr CYCLES  */
#line 628 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3661 "src-generated/ugbc.tab.c"
    break;

  case 164: /* wait_definition_expression: expr TICKS  */
#line 631 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3669 "src-generated/ugbc.tab.c"
    break;

  case 165: /* wait_definition_expression: expr milliseconds  */
#line 634 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3677 "src-generated/ugbc.tab.c"
    break;

  case 168: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 644 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3685 "src-generated/ugbc.tab.c"
    break;

  case 169: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 647 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3693 "src-generated/ugbc.tab.c"
    break;

  case 170: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 650 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3701 "src-generated/ugbc.tab.c"
    break;

  case 171: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 653 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3709 "src-generated/ugbc.tab.c"
    break;

  case 172: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 656 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3717 "src-generated/ugbc.tab.c"
    break;

  case 173: /* sprite_definition_simple: direct_integer ENABLE  */
#line 659 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3725 "src-generated/ugbc.tab.c"
    break;

  case 174: /* sprite_definition_simple: direct_integer DISABLE  */
#line 662 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3733 "src-generated/ugbc.tab.c"
    break;

  case 175: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 665 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3741 "src-generated/ugbc.tab.c"
    break;

  case 176: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 668 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3749 "src-generated/ugbc.tab.c"
    break;

  case 177: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 671 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3757 "src-generated/ugbc.tab.c"
    break;

  case 178: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 674 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3765 "src-generated/ugbc.tab.c"
    break;

  case 179: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 677 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3773 "src-generated/ugbc.tab.c"
    break;

  case 180: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 680 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3781 "src-generated/ugbc.tab.c"
    break;

  case 181: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 683 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3789 "src-generated/ugbc.tab.c"
    break;

  case 182: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 686 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3797 "src-generated/ugbc.tab.c"
    break;

  case 183: /* sprite_definition_expression: expr DATA FROM expr  */
#line 691 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3805 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_expression: expr MULTICOLOR  */
#line 694 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3813 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_expression: expr MONOCOLOR  */
#line 697 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3821 "src-generated/ugbc.tab.c"
    break;

  case 186: /* sprite_definition_expression: expr COLOR expr  */
#line 700 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3829 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 703 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3837 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_expression: expr ENABLE  */
#line 706 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3845 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_expression: expr DISABLE  */
#line 709 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3853 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 712 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3861 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 715 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3869 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 718 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3877 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 721 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3885 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 724 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3893 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 727 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3901 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 730 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3909 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 733 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3917 "src-generated/ugbc.tab.c"
    break;

  case 200: /* bitmap_definition_simple: AT direct_integer  */
#line 742 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3925 "src-generated/ugbc.tab.c"
    break;

  case 201: /* bitmap_definition_simple: ENABLE  */
#line 745 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3933 "src-generated/ugbc.tab.c"
    break;

  case 202: /* bitmap_definition_simple: DISABLE  */
#line 748 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 3941 "src-generated/ugbc.tab.c"
    break;

  case 203: /* bitmap_definition_simple: CLEAR  */
#line 751 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 3949 "src-generated/ugbc.tab.c"
    break;

  case 204: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 754 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 3957 "src-generated/ugbc.tab.c"
    break;

  case 205: /* bitmap_definition_expression: AT expr  */
#line 760 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3965 "src-generated/ugbc.tab.c"
    break;

  case 206: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 763 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 3973 "src-generated/ugbc.tab.c"
    break;

  case 209: /* textmap_definition_simple: AT direct_integer  */
#line 773 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3981 "src-generated/ugbc.tab.c"
    break;

  case 210: /* textmap_definition_expression: AT expr  */
#line 778 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3989 "src-generated/ugbc.tab.c"
    break;

  case 213: /* text_definition_simple: ENABLE  */
#line 787 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3997 "src-generated/ugbc.tab.c"
    break;

  case 214: /* text_definition_simple: DISABLE  */
#line 790 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4005 "src-generated/ugbc.tab.c"
    break;

  case 215: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 795 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4013 "src-generated/ugbc.tab.c"
    break;

  case 216: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 798 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4021 "src-generated/ugbc.tab.c"
    break;

  case 219: /* tiles_definition_simple: AT direct_integer  */
#line 807 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4029 "src-generated/ugbc.tab.c"
    break;

  case 220: /* tiles_definition_expression: AT expr  */
#line 812 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4037 "src-generated/ugbc.tab.c"
    break;

  case 223: /* colormap_definition_simple: AT direct_integer  */
#line 821 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4045 "src-generated/ugbc.tab.c"
    break;

  case 224: /* colormap_definition_simple: CLEAR  */
#line 824 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4053 "src-generated/ugbc.tab.c"
    break;

  case 225: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 827 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4061 "src-generated/ugbc.tab.c"
    break;

  case 226: /* colormap_definition_expression: AT expr  */
#line 832 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4069 "src-generated/ugbc.tab.c"
    break;

  case 227: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 835 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4077 "src-generated/ugbc.tab.c"
    break;

  case 230: /* screen_definition_simple: ON  */
#line 845 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4085 "src-generated/ugbc.tab.c"
    break;

  case 231: /* screen_definition_simple: OFF  */
#line 848 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4093 "src-generated/ugbc.tab.c"
    break;

  case 232: /* screen_definition_simple: ROWS direct_integer  */
#line 851 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4101 "src-generated/ugbc.tab.c"
    break;

  case 233: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 854 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4109 "src-generated/ugbc.tab.c"
    break;

  case 234: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 857 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4117 "src-generated/ugbc.tab.c"
    break;

  case 235: /* screen_definition_expression: ROWS expr  */
#line 862 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4125 "src-generated/ugbc.tab.c"
    break;

  case 236: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 865 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4133 "src-generated/ugbc.tab.c"
    break;

  case 237: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 868 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4141 "src-generated/ugbc.tab.c"
    break;

  case 241: /* var_definition_simple: Identifier ON Identifier  */
#line 877 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4149 "src-generated/ugbc.tab.c"
    break;

  case 242: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 880 "src/ugbc.y"
                                    {
      variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4157 "src-generated/ugbc.tab.c"
    break;

  case 243: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 883 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4165 "src-generated/ugbc.tab.c"
    break;

  case 244: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 886 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4175 "src-generated/ugbc.tab.c"
    break;

  case 245: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 891 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4185 "src-generated/ugbc.tab.c"
    break;

  case 246: /* goto_definition: Identifier  */
#line 898 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4193 "src-generated/ugbc.tab.c"
    break;

  case 247: /* goto_definition: Integer  */
#line 901 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4201 "src-generated/ugbc.tab.c"
    break;

  case 248: /* gosub_definition: Identifier  */
#line 907 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4209 "src-generated/ugbc.tab.c"
    break;

  case 249: /* gosub_definition: Integer  */
#line 910 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4217 "src-generated/ugbc.tab.c"
    break;

  case 251: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 919 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4225 "src-generated/ugbc.tab.c"
    break;

  case 252: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 925 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4233 "src-generated/ugbc.tab.c"
    break;

  case 255: /* ink_definition: expr  */
#line 934 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4241 "src-generated/ugbc.tab.c"
    break;

  case 256: /* on_goto_definition: Identifier  */
#line 939 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4250 "src-generated/ugbc.tab.c"
    break;

  case 257: /* $@1: %empty  */
#line 943 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4258 "src-generated/ugbc.tab.c"
    break;

  case 259: /* on_gosub_definition: Identifier  */
#line 948 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4267 "src-generated/ugbc.tab.c"
    break;

  case 260: /* $@2: %empty  */
#line 952 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4275 "src-generated/ugbc.tab.c"
    break;

  case 262: /* $@3: %empty  */
#line 957 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4283 "src-generated/ugbc.tab.c"
    break;

  case 264: /* $@4: %empty  */
#line 960 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4291 "src-generated/ugbc.tab.c"
    break;

  case 266: /* every_definition: expr TICKS GOSUB Identifier  */
#line 965 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4299 "src-generated/ugbc.tab.c"
    break;

  case 267: /* every_definition: ON  */
#line 968 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4307 "src-generated/ugbc.tab.c"
    break;

  case 268: /* every_definition: OFF  */
#line 971 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4315 "src-generated/ugbc.tab.c"
    break;

  case 269: /* add_definition: Identifier COMMA expr  */
#line 976 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4323 "src-generated/ugbc.tab.c"
    break;

  case 270: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 979 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4331 "src-generated/ugbc.tab.c"
    break;

  case 287: /* statement: INC Identifier  */
#line 1001 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 4339 "src-generated/ugbc.tab.c"
    break;

  case 288: /* statement: DEC Identifier  */
#line 1004 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 4347 "src-generated/ugbc.tab.c"
    break;

  case 289: /* statement: RANDOMIZE  */
#line 1007 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 4355 "src-generated/ugbc.tab.c"
    break;

  case 290: /* statement: RANDOMIZE expr  */
#line 1010 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 4363 "src-generated/ugbc.tab.c"
    break;

  case 291: /* statement: IF expr THEN  */
#line 1013 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4371 "src-generated/ugbc.tab.c"
    break;

  case 292: /* statement: ELSE  */
#line 1016 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 4379 "src-generated/ugbc.tab.c"
    break;

  case 293: /* statement: ELSE IF expr THEN  */
#line 1019 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4387 "src-generated/ugbc.tab.c"
    break;

  case 294: /* statement: ENDIF  */
#line 1022 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 4395 "src-generated/ugbc.tab.c"
    break;

  case 295: /* statement: DO  */
#line 1025 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 4403 "src-generated/ugbc.tab.c"
    break;

  case 296: /* statement: LOOP  */
#line 1028 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 4411 "src-generated/ugbc.tab.c"
    break;

  case 297: /* $@5: %empty  */
#line 1031 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 4419 "src-generated/ugbc.tab.c"
    break;

  case 298: /* statement: WHILE $@5 expr  */
#line 1033 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 4427 "src-generated/ugbc.tab.c"
    break;

  case 299: /* statement: WEND  */
#line 1036 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 4435 "src-generated/ugbc.tab.c"
    break;

  case 300: /* statement: REPEAT  */
#line 1039 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 4443 "src-generated/ugbc.tab.c"
    break;

  case 301: /* statement: UNTIL expr  */
#line 1042 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 4451 "src-generated/ugbc.tab.c"
    break;

  case 302: /* statement: EXIT  */
#line 1045 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 4459 "src-generated/ugbc.tab.c"
    break;

  case 303: /* statement: EXIT IF expr  */
#line 1048 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 4467 "src-generated/ugbc.tab.c"
    break;

  case 304: /* statement: EXIT Integer  */
#line 1051 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4475 "src-generated/ugbc.tab.c"
    break;

  case 305: /* statement: EXIT direct_integer  */
#line 1054 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4483 "src-generated/ugbc.tab.c"
    break;

  case 306: /* statement: EXIT IF expr COMMA Integer  */
#line 1057 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4491 "src-generated/ugbc.tab.c"
    break;

  case 307: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1060 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4499 "src-generated/ugbc.tab.c"
    break;

  case 308: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1063 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4507 "src-generated/ugbc.tab.c"
    break;

  case 309: /* statement: NEXT  */
#line 1066 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 4515 "src-generated/ugbc.tab.c"
    break;

  case 310: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1069 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4523 "src-generated/ugbc.tab.c"
    break;

  case 311: /* statement: BEG GAMELOOP  */
#line 1072 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 4531 "src-generated/ugbc.tab.c"
    break;

  case 312: /* statement: END GAMELOOP  */
#line 1075 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 4539 "src-generated/ugbc.tab.c"
    break;

  case 313: /* statement: GRAPHIC  */
#line 1078 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 4547 "src-generated/ugbc.tab.c"
    break;

  case 314: /* statement: HALT  */
#line 1081 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 4555 "src-generated/ugbc.tab.c"
    break;

  case 319: /* statement: RETURN  */
#line 1088 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 4563 "src-generated/ugbc.tab.c"
    break;

  case 320: /* statement: POP  */
#line 1091 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 4571 "src-generated/ugbc.tab.c"
    break;

  case 321: /* statement: DONE  */
#line 1094 "src/ugbc.y"
          {
      return 0;
  }
#line 4579 "src-generated/ugbc.tab.c"
    break;

  case 322: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1097 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4587 "src-generated/ugbc.tab.c"
    break;

  case 323: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1100 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4595 "src-generated/ugbc.tab.c"
    break;

  case 324: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1103 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 4603 "src-generated/ugbc.tab.c"
    break;

  case 325: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1106 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4611 "src-generated/ugbc.tab.c"
    break;

  case 326: /* statement: Identifier COLON  */
#line 1109 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 4619 "src-generated/ugbc.tab.c"
    break;

  case 327: /* statement: Identifier ASSIGN expr  */
#line 1112 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 4633 "src-generated/ugbc.tab.c"
    break;

  case 328: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1121 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 4647 "src-generated/ugbc.tab.c"
    break;

  case 329: /* statement: DEBUG expr  */
#line 1130 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 4655 "src-generated/ugbc.tab.c"
    break;

  case 332: /* statements_no_linenumbers: statement  */
#line 1138 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 4661 "src-generated/ugbc.tab.c"
    break;

  case 333: /* $@6: %empty  */
#line 1139 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 4667 "src-generated/ugbc.tab.c"
    break;

  case 335: /* $@7: %empty  */
#line 1143 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 4675 "src-generated/ugbc.tab.c"
    break;

  case 336: /* statements_with_linenumbers: Integer $@7 statements_no_linenumbers  */
#line 1145 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 4683 "src-generated/ugbc.tab.c"
    break;

  case 341: /* $@8: %empty  */
#line 1157 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 4689 "src-generated/ugbc.tab.c"
    break;


#line 4693 "src-generated/ugbc.tab.c"

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

#line 1159 "src/ugbc.y"


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

