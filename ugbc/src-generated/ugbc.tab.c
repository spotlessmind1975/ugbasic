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
  YYSYMBOL_MILLISECOND = 134,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 135,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 136,                    /* TICKS  */
  YYSYMBOL_BLACK = 137,                    /* BLACK  */
  YYSYMBOL_WHITE = 138,                    /* WHITE  */
  YYSYMBOL_RED = 139,                      /* RED  */
  YYSYMBOL_CYAN = 140,                     /* CYAN  */
  YYSYMBOL_VIOLET = 141,                   /* VIOLET  */
  YYSYMBOL_GREEN = 142,                    /* GREEN  */
  YYSYMBOL_BLUE = 143,                     /* BLUE  */
  YYSYMBOL_YELLOW = 144,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 145,                   /* ORANGE  */
  YYSYMBOL_BROWN = 146,                    /* BROWN  */
  YYSYMBOL_LIGHT = 147,                    /* LIGHT  */
  YYSYMBOL_DARK = 148,                     /* DARK  */
  YYSYMBOL_GREY = 149,                     /* GREY  */
  YYSYMBOL_GRAY = 150,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 151,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 152,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 153,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 154,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 155,                /* TURQUOISE  */
  YYSYMBOL_TAN = 156,                      /* TAN  */
  YYSYMBOL_PINK = 157,                     /* PINK  */
  YYSYMBOL_PEACH = 158,                    /* PEACH  */
  YYSYMBOL_OLIVE = 159,                    /* OLIVE  */
  YYSYMBOL_Identifier = 160,               /* Identifier  */
  YYSYMBOL_String = 161,                   /* String  */
  YYSYMBOL_Integer = 162,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 163,                 /* $accept  */
  YYSYMBOL_expr = 164,                     /* expr  */
  YYSYMBOL_expr_math = 165,                /* expr_math  */
  YYSYMBOL_term = 166,                     /* term  */
  YYSYMBOL_modula = 167,                   /* modula  */
  YYSYMBOL_factor = 168,                   /* factor  */
  YYSYMBOL_direct_integer = 169,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 170, /* random_definition_simple  */
  YYSYMBOL_random_definition = 171,        /* random_definition  */
  YYSYMBOL_color_enumeration = 172,        /* color_enumeration  */
  YYSYMBOL_exponential = 173,              /* exponential  */
  YYSYMBOL_position = 174,                 /* position  */
  YYSYMBOL_bank_definition_simple = 175,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 176, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 177,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 178, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 179, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 180,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 181, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 182, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 183,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 184,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 185, /* color_definition_expression  */
  YYSYMBOL_color_definition = 186,         /* color_definition  */
  YYSYMBOL_milliseconds = 187,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 188,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 189, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 190,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 191, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 192, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 193,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 194, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 195, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 196,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 197, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 198, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 199,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 200,   /* text_definition_simple  */
  YYSYMBOL_text_definition = 201,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 202,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 203, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 204,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 205, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 206, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 207,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 208, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 209, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 210,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 211,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 212,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 213,         /* gosub_definition  */
  YYSYMBOL_var_definition = 214,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 215,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 216, /* point_definition_expression  */
  YYSYMBOL_point_definition = 217,         /* point_definition  */
  YYSYMBOL_on_goto_definition = 218,       /* on_goto_definition  */
  YYSYMBOL_219_1 = 219,                    /* $@1  */
  YYSYMBOL_on_gosub_definition = 220,      /* on_gosub_definition  */
  YYSYMBOL_221_2 = 221,                    /* $@2  */
  YYSYMBOL_on_definition = 222,            /* on_definition  */
  YYSYMBOL_223_3 = 223,                    /* $@3  */
  YYSYMBOL_224_4 = 224,                    /* $@4  */
  YYSYMBOL_every_definition = 225,         /* every_definition  */
  YYSYMBOL_add_definition = 226,           /* add_definition  */
  YYSYMBOL_statement = 227,                /* statement  */
  YYSYMBOL_228_5 = 228,                    /* $@5  */
  YYSYMBOL_statements_no_linenumbers = 229, /* statements_no_linenumbers  */
  YYSYMBOL_230_6 = 230,                    /* $@6  */
  YYSYMBOL_statements_with_linenumbers = 231, /* statements_with_linenumbers  */
  YYSYMBOL_232_7 = 232,                    /* $@7  */
  YYSYMBOL_statements_complex = 233,       /* statements_complex  */
  YYSYMBOL_program = 234,                  /* program  */
  YYSYMBOL_235_8 = 235                     /* $@8  */
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
#define YYLAST   1359

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  163
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  324
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  626

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   417


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
     155,   156,   157,   158,   159,   160,   161,   162
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    69,    73,    77,    80,    83,    86,    89,
      92,    95,   101,   102,   105,   112,   113,   117,   118,   122,
     129,   130,   137,   142,   145,   148,   151,   154,   157,   160,
     165,   170,   174,   178,   182,   186,   190,   194,   198,   202,
     206,   210,   214,   218,   222,   226,   230,   234,   238,   242,
     246,   250,   254,   258,   262,   266,   270,   274,   280,   283,
     286,   290,   297,   301,   305,   309,   313,   317,   320,   323,
     326,   329,   332,   335,   338,   341,   344,   347,   350,   353,
     356,   359,   362,   365,   368,   371,   374,   377,   380,   383,
     386,   389,   392,   395,   398,   401,   404,   408,   414,   414,
     417,   420,   423,   426,   429,   432,   436,   439,   442,   445,
     449,   452,   455,   458,   462,   465,   468,   471,   477,   480,
     483,   486,   489,   494,   495,   498,   501,   506,   509,   514,
     515,   518,   521,   526,   529,   534,   535,   538,   541,   544,
     549,   552,   555,   560,   561,   564,   565,   566,   569,   572,
     575,   580,   583,   586,   592,   593,   596,   599,   602,   605,
     608,   611,   614,   617,   620,   623,   626,   629,   632,   635,
     638,   643,   646,   649,   652,   655,   658,   661,   664,   667,
     670,   673,   676,   679,   682,   685,   690,   691,   694,   697,
     700,   703,   706,   712,   715,   721,   722,   725,   730,   735,
     736,   739,   742,   747,   750,   755,   760,   761,   764,   767,
     770,   775,   778,   784,   785,   788,   791,   794,   797,   800,
     805,   808,   811,   816,   817,   819,   820,   823,   826,   829,
     834,   841,   844,   850,   853,   859,   862,   868,   873,   874,
     877,   881,   881,   886,   890,   890,   895,   895,   898,   898,
     903,   906,   909,   914,   917,   923,   924,   925,   926,   927,
     928,   929,   930,   931,   932,   933,   934,   935,   936,   937,
     938,   941,   944,   947,   950,   953,   956,   959,   962,   965,
     965,   970,   973,   976,   979,   982,   985,   988,   991,   994,
     997,  1000,  1003,  1006,  1009,  1012,  1015,  1018,  1019,  1020,
    1021,  1022,  1025,  1028,  1031,  1034,  1037,  1040,  1043,  1046,
    1055,  1064,  1067,  1068,  1072,  1073,  1073,  1077,  1077,  1084,
    1085,  1086,  1087,  1091,  1091
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
  "ADD", "MIN", "MAX", "MILLISECOND", "MILLISECONDS", "TICKS", "BLACK",
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
  "text_definition_simple", "text_definition", "tiles_definition_simple",
  "tiles_definition_expression", "tiles_definition",
  "colormap_definition_simple", "colormap_definition_expression",
  "colormap_definition", "screen_definition_simple",
  "screen_definition_expression", "screen_definition",
  "var_definition_simple", "goto_definition", "gosub_definition",
  "var_definition", "point_definition_simple",
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
     415,   416,   417
};
#endif

#define YYPACT_NINF (-216)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-245)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -216,    54,   626,  -216,  -216,  -117,  -113,   -21,  -216,   -15,
     965,    63,     4,   965,  -216,    47,   127,  1081,   -69,   -88,
    -216,  -216,  -216,   115,    72,    -7,  1081,    17,    35,  -216,
      87,    95,  1081,  -216,  -216,   136,   143,   -56,  -216,  -216,
      64,  -216,   -48,  -216,  1081,    15,   849,   155,    38,    12,
    -216,   189,   206,   221,  -216,  -216,  -216,   965,   210,  -216,
    -216,  -216,   965,   965,   965,  -216,  -216,  -216,   720,  -216,
    -216,   203,   218,   222,    43,    93,   223,   224,  1081,  -216,
    -216,   225,   226,   228,   230,   233,   234,   235,   236,   237,
     238,   239,   241,   242,   243,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,   121,  -216,  -216,    57,  -101,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,   138,   258,  -216,  -216,
      44,    61,   149,   128,   152,    56,  -216,  -216,  -216,  -216,
    -216,   -19,   200,   -17,   -16,   -12,   -10,   263,  -216,  -216,
    -216,   229,   266,  -216,  -216,  -216,   965,  -216,  -216,   259,
    -216,  -216,  -216,  -216,  -216,   965,   246,   247,  -216,  -216,
    -216,   -38,  -216,     3,  -216,  -216,  -216,  -216,  -216,  1081,
    -216,  -216,  -216,  -216,   965,  -216,  -216,  -216,   965,   260,
    -216,  -216,  -216,   227,  -216,  -216,  1081,  1081,  -216,   965,
    -216,  -216,  -216,   265,  -216,  -216,  -216,  -216,  -216,  -216,
    1081,  1081,  -216,  -216,  -216,   284,  -216,  -216,   168,  -216,
    1081,   299,  -216,  -216,  1081,   294,    -1,  -216,   626,   626,
     279,   280,   965,  -216,  -216,   240,   244,   245,   249,   275,
     278,   283,   291,   292,   295,   965,   965,   965,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  1081,  1081,
    -216,  1081,  1081,  1081,  1081,  1081,  1081,  1081,  1081,  1081,
    1081,  1081,  1081,  1081,  1081,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    1197,  1197,  1197,  1197,  1197,  1197,  1197,  1197,  1197,  1197,
    1197,  1197,  1197,  1197,  -216,  -216,  -216,   965,   290,  -216,
    -216,  -216,   271,   200,   309,   200,   310,   200,   311,   200,
     312,   200,  -216,  1081,   304,  -216,  -216,   137,   146,    77,
      92,  -216,  -216,  -216,   306,   200,   305,  -216,  -216,   148,
     151,   100,   123,  -216,  -216,   307,  -216,  -216,   965,  -216,
    -216,   965,   965,  -216,  -216,   302,   186,  -216,  -216,  -216,
    -216,  -216,   965,  -216,   342,   343,  -216,  -216,   965,   285,
     345,  1081,   253,   349,  1081,  -216,  1081,  -216,    -1,  -216,
    -216,   197,   199,  -216,  -216,  1081,   200,  1081,   200,   198,
     201,   204,   205,   207,  -216,   326,   330,   333,   335,   336,
     337,   366,   367,   368,   369,   344,   346,   347,   348,   370,
     350,   351,   352,   353,   354,   371,   373,   149,   149,   154,
     154,   154,   154,   154,   154,   154,   154,   128,   152,   152,
    -216,   355,   361,   965,   106,  -216,   200,  -216,   200,  -216,
     200,  -216,   200,    60,  -216,  1081,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  1081,  -216,   200,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,   200,  -216,  -216,  -216,  -216,
    -216,  -216,   232,   248,   251,   380,   356,   357,  1081,  1081,
     387,   388,  -216,   -76,   324,   252,  1081,   390,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  1081,  1081,  1081,
    1081,  -216,  -216,  -216,  -216,  1081,  -216,  -216,  -216,  -216,
    -216,  1081,  1081,   254,   255,  -216,  -216,  -216,  -216,  -216,
    -216,   372,  -216,   374,  -216,   256,   108,  -216,   393,  -216,
     395,   400,  -216,   402,  -216,   403,   965,  1081,   200,   378,
     383,  1081,   200,  -216,  -216,  1081,  -216,    28,  1081,   384,
     385,    31,    85,   386,   389,   391,  -216,  -216,   262,   264,
    -216,   398,  -216,   399,  -216,  1081,   200,   422,   423,  1081,
    -216,  -216,  -216,  -216,   419,   420,   401,   404,   319,  1081,
     424,   363,  -216,  -216,  1081,  -216,  1081,  -216,  -216,  -216,
    -216,  -216,  -216,   277,   281,   405,   406,   232,   248,  -216,
    1081,  1081,  -216,  -216,  1081,   408,  1081,  1081,   409,   410,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,   433,
    -216,  -216,  -216,  -216,  1081,  -216
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     323,     0,   313,     1,   312,     0,     0,     0,   303,     0,
       0,   291,     0,     0,   296,     0,     0,     0,   225,     0,
     278,   282,   279,     0,     0,     0,     0,     0,     0,   276,
       0,     0,     0,   272,   295,     0,     0,     0,   301,   302,
     274,   277,   284,   281,     0,     0,     0,     0,     0,     0,
     317,   314,   319,   321,   324,   270,   271,     0,     0,   129,
     130,   256,     0,     0,     0,   143,   144,   258,     0,    70,
      71,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,     0,    43,    48,    49,
      50,    51,    52,    53,    56,    57,     0,    58,    61,    60,
       0,     2,    12,    15,    17,     0,    67,    20,   154,   155,
     259,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     255,     0,     0,   186,   187,   260,     0,   189,   190,   191,
     195,   196,   261,   215,   216,     0,     0,     0,   223,   224,
     266,     0,   297,     0,   235,   268,   231,   232,   298,     0,
     201,   202,   203,   263,     0,   206,   207,   264,     0,   209,
     213,   214,   265,     0,   293,   294,     0,     0,   311,     0,
     199,   200,   262,     0,   238,   239,   267,   233,   234,   299,
       0,     0,   286,   287,   283,     0,   251,   252,     0,   300,
       0,     0,   269,   308,     0,     0,   313,   315,   313,   313,
       0,     0,     0,   140,   137,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    23,
      24,    26,    28,    29,    25,    30,    92,    22,     0,     0,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    41,    44,    45,    46,
      47,    42,    55,    59,   145,   151,   146,   147,   152,   153,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,   149,   150,     0,     0,   135,
     136,   257,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,     0,     0,   176,   177,     0,     0,     0,
       0,   173,   172,    98,     0,     0,     0,   161,   162,     0,
       0,     0,     0,   158,   157,     0,   193,   188,     0,   220,
     217,     0,     0,   246,   248,     0,     0,   280,   205,   204,
     211,   208,     0,   273,     0,     0,   198,   197,     0,     0,
     285,     0,     0,     0,     0,   309,     0,   318,   313,   320,
     322,     0,     0,   127,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,     5,
       7,     8,     9,    10,     6,     3,     4,    16,    18,    19,
      21,     0,     0,     0,     0,   105,     0,   117,     0,   109,
       0,   113,     0,   101,   174,     0,   181,   180,   185,   184,
     179,   183,   178,   182,     0,   159,     0,   166,   165,   170,
     169,   164,   168,   163,   167,     0,   194,   192,   221,   218,
     222,   219,     0,     0,     0,   226,     0,     0,     0,     0,
       0,     0,   275,     0,     0,     0,     0,   253,   310,   316,
     128,   126,   142,   139,   141,   138,    66,    62,    63,    65,
      64,    69,    68,    73,    72,    75,    74,     0,     0,     0,
       0,    82,    83,    84,    91,     0,    85,    86,    87,    88,
      89,     0,     0,     0,     0,   133,   131,   102,   115,   107,
     110,   104,   116,   108,   112,     0,     0,   171,     0,   156,
       0,   240,   247,   243,   249,   227,     0,     0,     0,     0,
       0,     0,     0,   288,   289,     0,   250,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   132,     0,     0,
     118,   103,   114,   106,   111,     0,     0,     0,     0,     0,
     229,   228,   212,   210,     0,     0,     0,     0,   290,     0,
       0,     0,    76,    77,     0,    78,     0,    80,    90,    95,
      94,   120,   122,     0,     0,     0,     0,     0,     0,   230,
       0,     0,   237,   236,     0,     0,     0,     0,     0,     0,
     119,   121,   175,   160,   242,   245,   304,   305,   292,     0,
     306,   254,    79,    81,     0,   307
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -216,   -13,   -70,   -60,   157,   -64,   169,  -216,  -216,  -216,
     156,   308,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,   323,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -146,  -216,  -145,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -215,  -216,  -216,  -216,
      11,  -216,  -216
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   120,   121,   122,   123,   124,   125,   245,   246,   126,
     127,   324,   138,   139,   140,    59,    60,    61,   299,   300,
     301,    65,    66,    67,   279,   128,   129,   130,   143,   144,
     145,   150,   151,   152,   190,   191,   192,   172,   173,   175,
     176,   177,   180,   181,   182,   158,   159,   160,   164,   168,
     199,   165,   194,   195,   196,   532,   567,   534,   568,   162,
     462,   463,   209,   212,    51,   169,    52,   368,    53,   216,
      54,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     141,   367,     4,    57,   161,   297,    75,   303,   305,     5,
       6,    62,   307,   183,   309,   343,    63,   178,   213,   188,
     201,     7,     8,   345,     9,   214,    10,    11,   132,    12,
      13,   204,   215,   208,    75,   579,   133,    14,   584,    15,
      16,    17,   270,    55,   220,   346,    18,    56,   271,   223,
     225,   227,    19,   134,     3,   234,    64,    20,    21,    22,
      23,    24,    25,   580,   344,   250,   585,    26,   238,   280,
     281,   146,   166,   282,   167,   283,   284,   285,   286,   287,
     179,   135,   136,   147,   148,   131,   543,    27,    28,   525,
      29,   163,   586,    30,    31,    32,   174,    33,    34,    35,
      36,    37,    38,    39,   197,    40,   198,   184,   526,    41,
      42,    43,    44,    45,   202,    46,    47,   239,   240,   241,
     587,   186,   440,   274,   275,   185,   242,   243,   244,   187,
      48,   441,   200,   336,   149,   274,   294,   442,   517,    58,
     561,   298,   339,   304,   306,   451,   443,   291,   308,   292,
     310,   170,   171,   479,   452,   518,   347,   562,   288,    49,
     189,   348,   280,   281,   137,   350,   289,   193,   453,   153,
     154,   155,   156,   354,   355,   205,   356,   454,   276,   277,
     278,   157,   142,   519,   520,   563,   564,   359,   360,   210,
     276,   277,   295,   436,   437,   217,   266,   363,   211,   267,
     268,   365,   438,   439,   447,   448,   269,   449,   450,   373,
     218,   203,   409,   410,   411,   412,   413,   414,   415,   416,
     407,   408,   385,   387,   389,   219,   221,   418,   419,   369,
     370,   224,   226,   228,   222,   391,   392,   235,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   236,   312,   313,   247,   237,   248,   249,   251,
     252,   314,   253,   265,   254,   315,   316,   255,   256,   257,
     258,   259,   260,   261,   317,   262,   263,   264,   273,   290,
     272,   293,    75,   318,   421,   319,   320,   311,   338,   352,
     312,   325,   341,   342,   321,   322,   353,   361,   326,   358,
     434,   302,   327,   328,   362,   323,   364,   366,   371,   372,
     379,   329,   375,   380,   423,   337,   376,   377,   381,   424,
     330,   378,   331,   332,   340,   456,   382,   383,   458,   460,
     384,   333,   334,   426,   428,   430,   432,   435,   446,   466,
     444,   455,   323,   349,   464,   470,   465,   351,   474,   468,
     469,   477,   473,   478,   472,   475,   476,   480,   357,   481,
     486,   491,   482,   487,   484,   492,   488,   489,   493,   490,
     494,   495,   496,   497,   498,   499,   500,   505,   511,   501,
     512,   502,   503,   504,   513,   506,   507,   508,   509,   510,
     514,   374,   531,   536,   541,   542,   545,   548,   537,   538,
     565,   558,   566,   559,   386,   388,   390,  -241,   533,  -244,
     515,   535,   546,   574,   556,   557,   569,   560,   575,   582,
     583,   588,   527,   591,   589,   592,   590,   593,   594,   597,
     598,   528,   600,   601,   604,   607,   602,   606,   610,   603,
     612,   613,   611,   619,   622,   623,   624,   417,   296,   420,
     335,   614,     0,   615,     0,   539,   540,     0,     0,     0,
       0,     0,     0,   547,     0,     0,   422,     0,     0,     0,
       0,     0,   425,     0,   427,     0,   429,     0,   431,     0,
     433,     0,     0,     0,   549,   550,   551,   552,     0,     0,
       0,     0,   553,     0,   445,     0,     0,     0,   554,   555,
       0,     0,     0,     0,     0,     0,     0,   457,     0,     0,
     459,   461,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   467,     0,   570,   572,     0,     0,   471,   576,     0,
       0,     0,   578,     0,     0,   581,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   483,     0,   485,     0,     0,
       0,     0,   595,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   605,     0,     0,     0,
       0,   608,     0,   609,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   616,   617,     0,
       0,   618,   516,   620,   621,   521,     0,   522,     0,   523,
       0,   524,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   625,     0,     0,     0,   529,     0,     0,     0,     0,
       0,     0,     0,     0,   530,     0,     0,     0,     0,     4,
       0,     0,     0,     0,     0,     0,     5,     6,     0,     0,
       0,     0,   544,     0,     0,     0,     0,     0,     7,     8,
       0,     9,     0,    10,    11,     0,    12,    13,     0,     0,
       0,     0,     0,     0,    14,     0,    15,    16,    17,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   571,     0,   573,     0,     0,
       0,   577,     0,     0,    27,    28,     0,    29,     0,     0,
      30,    31,    32,     0,    33,    34,    35,    36,    37,    38,
      39,     0,    40,     0,     0,   596,    41,    42,    43,    44,
      45,     0,    46,    47,     0,   229,     0,     0,     0,     0,
       0,     0,     0,     0,    68,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,    70,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,    72,    50,     0,
      73,     0,     0,    74,   230,   231,   232,     0,     0,     0,
       0,     0,     0,     0,     0,   233,     0,     0,     0,     0,
       0,     0,     0,     0,    76,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,    79,    80,
       0,     0,     0,     0,     0,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,    93,    94,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    68,     0,     0,     0,     0,     0,     0,
       0,   206,   207,     0,     0,     0,     0,     0,     0,    69,
      70,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,     0,     0,    73,
       0,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,    79,    80,     0,
       0,     0,     0,     0,     0,     0,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,    93,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    68,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,     0,     0,     0,    69,    70,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,     0,     0,    73,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,    75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    79,    80,     0,     0,     0,     0,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,     0,     0,     0,    93,    94,     0,
       0,     0,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    68,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
       0,    69,    70,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,     0,
       0,    73,     0,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    79,
      80,     0,     0,     0,     0,     0,     0,     0,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,    93,    94,     0,     0,     0,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    68,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,     0,     0,     0,    69,    70,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,     0,     0,    73,     0,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    80,     0,     0,     0,
       0,     0,     0,     0,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,     0,     0,     0,    93,
      94,     0,     0,     0,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119
};

static const yytype_int16 yycheck[] =
{
      13,   216,     3,    24,    17,    24,    82,    24,    24,    10,
      11,    26,    24,    26,    24,    53,    31,    24,     6,    32,
      68,    22,    23,    20,    25,    13,    27,    28,    24,    30,
      31,    44,    20,    46,    82,     7,    32,    38,     7,    40,
      41,    42,   143,   160,    57,    42,    47,   160,   149,    62,
      63,    64,    53,    49,     0,    68,    71,    58,    59,    60,
      61,    62,    63,    35,   102,    78,    35,    68,    25,     8,
       9,    24,   160,    12,   162,    14,    15,    16,    17,    18,
      87,    77,    78,    36,    37,    22,   162,    88,    89,    29,
      91,   160,     7,    94,    95,    96,    24,    98,    99,   100,
     101,   102,   103,   104,   160,   106,   162,    90,    48,   110,
     111,   112,   113,   114,   162,   116,   117,    74,    75,    76,
      35,    34,    45,    79,    80,    90,    83,    84,    85,    34,
     131,    54,    68,   146,    87,    79,    80,    45,    32,   160,
      32,   160,   155,   160,   160,    45,    54,    19,   160,    21,
     160,    36,    37,   368,    54,    49,   169,    49,    97,   160,
      24,   174,     8,     9,   160,   178,   105,    24,    45,    42,
      43,    44,    45,   186,   187,   160,   189,    54,   134,   135,
     136,    54,    13,    77,    78,    77,    78,   200,   201,    34,
     134,   135,   136,    56,    57,     6,   139,   210,   160,   142,
     143,   214,    56,    57,    56,    57,   149,    56,    57,   222,
       4,    42,   282,   283,   284,   285,   286,   287,   288,   289,
     280,   281,   235,   236,   237,     4,    57,   291,   292,   218,
     219,    62,    63,    64,    24,   248,   249,    34,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,    34,    24,    25,   162,    34,    34,    34,    34,
      34,    32,    34,   142,    34,    36,    37,    34,    34,    34,
      34,    34,    34,    34,    45,    34,    34,    34,    20,   130,
     142,   129,    82,    54,   297,    56,    57,    24,    29,    29,
      24,    25,    46,    46,    65,    66,    69,    13,    32,    34,
     313,   132,    36,    37,   136,    76,     7,    13,    29,    29,
      35,    45,    72,    35,    24,   146,    72,    72,    35,    48,
      54,    72,    56,    57,   155,   338,    35,    35,   341,   342,
      35,    65,    66,    24,    24,    24,    24,    33,    33,   352,
      34,    34,    76,   174,    42,   358,   160,   178,   361,     7,
       7,   364,     7,   366,    69,   102,     7,   160,   189,   160,
     162,    35,   375,   162,   377,    35,   162,   162,    35,   162,
      35,    35,    35,     7,     7,     7,     7,     7,     7,    35,
       7,    35,    35,    35,    29,    35,    35,    35,    35,    35,
      29,   222,   160,    13,     7,     7,    72,     7,    42,    42,
       7,    29,     7,    29,   235,   236,   237,     7,   160,     7,
     423,   160,   160,    35,   160,   160,    13,   161,    35,    35,
      35,    35,   435,   161,    35,   161,    35,    29,    29,     7,
       7,   444,    13,    13,   115,    72,    35,    13,   161,    35,
      35,    35,   161,    35,    35,    35,    13,   290,   125,   293,
     142,   597,    -1,   598,    -1,   468,   469,    -1,    -1,    -1,
      -1,    -1,    -1,   476,    -1,    -1,   297,    -1,    -1,    -1,
      -1,    -1,   303,    -1,   305,    -1,   307,    -1,   309,    -1,
     311,    -1,    -1,    -1,   497,   498,   499,   500,    -1,    -1,
      -1,    -1,   505,    -1,   325,    -1,    -1,    -1,   511,   512,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,    -1,    -1,
     341,   342,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   352,    -1,   536,   537,    -1,    -1,   358,   541,    -1,
      -1,    -1,   545,    -1,    -1,   548,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   376,    -1,   378,    -1,    -1,
      -1,    -1,   565,    -1,    -1,    -1,   569,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   579,    -1,    -1,    -1,
      -1,   584,    -1,   586,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   600,   601,    -1,
      -1,   604,   423,   606,   607,   426,    -1,   428,    -1,   430,
      -1,   432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   624,    -1,    -1,    -1,   446,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    -1,    -1,
      -1,    -1,   473,    -1,    -1,    -1,    -1,    -1,    22,    23,
      -1,    25,    -1,    27,    28,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    40,    41,    42,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   536,    -1,   538,    -1,    -1,
      -1,   542,    -1,    -1,    88,    89,    -1,    91,    -1,    -1,
      94,    95,    96,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,   106,    -1,    -1,   566,   110,   111,   112,   113,
     114,    -1,   116,   117,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   160,    67,   162,    -1,
      70,    -1,    -1,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,   132,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,   132,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    34,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,   132,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    34,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,   132,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    34,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   234,   235,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    88,    89,    91,
      94,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     106,   110,   111,   112,   113,   114,   116,   117,   131,   160,
     162,   227,   229,   231,   233,   160,   160,    24,   160,   178,
     179,   180,    26,    31,    71,   184,   185,   186,    34,    50,
      51,    52,    67,    70,    73,    82,    94,    95,   107,   108,
     109,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   132,   133,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     164,   165,   166,   167,   168,   169,   172,   173,   188,   189,
     190,    22,    24,    32,    49,    77,    78,   160,   175,   176,
     177,   164,   169,   191,   192,   193,    24,    36,    37,    87,
     194,   195,   196,    42,    43,    44,    45,    54,   208,   209,
     210,   164,   222,   160,   211,   214,   160,   162,   212,   228,
      36,    37,   200,   201,    24,   202,   203,   204,    24,    87,
     205,   206,   207,   164,    90,    90,    34,    34,   164,    24,
     197,   198,   199,    24,   215,   216,   217,   160,   162,   213,
      68,    68,   162,   169,   164,   160,    42,    43,   164,   225,
      34,   160,   226,     6,    13,    20,   232,     6,     4,     4,
     164,   169,    24,   164,   169,   164,   169,   164,   169,    25,
      74,    75,    76,    85,   164,    34,    34,    34,    25,    74,
      75,    76,    83,    84,    85,   170,   171,   162,    34,    34,
     164,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,   142,   139,   142,   143,   149,
     143,   149,   142,    20,    79,    80,   134,   135,   136,   187,
       8,     9,    12,    14,    15,    16,    17,    18,    97,   105,
     130,    19,    21,   129,    80,   136,   187,    24,   160,   181,
     182,   183,   169,    24,   160,    24,   160,    24,   160,    24,
     160,    24,    24,    25,    32,    36,    37,    45,    54,    56,
      57,    65,    66,    76,   174,    25,    32,    36,    37,    45,
      54,    56,    57,    65,    66,   174,   164,   169,    29,   164,
     169,    46,    46,    53,   102,    20,    42,   164,   164,   169,
     164,   169,    29,    69,   164,   164,   164,   169,    34,   164,
     164,    13,   136,   164,     7,   164,    13,   229,   230,   233,
     233,    29,    29,   164,   169,    72,    72,    72,    72,    35,
      35,    35,    35,    35,    35,   164,   169,   164,   169,   164,
     169,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   166,   166,   165,
     165,   165,   165,   165,   165,   165,   165,   167,   168,   168,
     173,   164,   169,    24,    48,   169,    24,   169,    24,   169,
      24,   169,    24,   169,   164,    33,    56,    57,    56,    57,
      45,    54,    45,    54,    34,   169,    33,    56,    57,    56,
      57,    45,    54,    45,    54,    34,   164,   169,   164,   169,
     164,   169,   223,   224,    42,   160,   164,   169,     7,     7,
     164,   169,    69,     7,   164,   102,     7,   164,   164,   229,
     160,   160,   164,   169,   164,   169,   162,   162,   162,   162,
     162,    35,    35,    35,    35,    35,    35,     7,     7,     7,
       7,    35,    35,    35,    35,     7,    35,    35,    35,    35,
      35,     7,     7,    29,    29,   164,   169,    32,    49,    77,
      78,   169,   169,   169,   169,    29,    48,   164,   164,   169,
     169,   160,   218,   160,   220,   160,    13,    42,    42,   164,
     164,     7,     7,   162,   169,    72,   160,   164,     7,   164,
     164,   164,   164,   164,   164,   164,   160,   160,    29,    29,
     161,    32,    49,    77,    78,     7,     7,   219,   221,    13,
     164,   169,   164,   169,    35,    35,   164,   169,   164,     7,
      35,   164,    35,    35,     7,    35,     7,    35,    35,    35,
      35,   161,   161,    29,    29,   164,   169,     7,     7,   164,
      13,    13,    35,    35,   115,   164,    13,    72,   164,   164,
     161,   161,    35,    35,   218,   220,   164,   164,   164,    35,
     164,   164,    35,    35,    13,   164
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   163,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   165,   165,   165,   166,   166,   167,   167,   167,
     168,   168,   169,   170,   170,   170,   170,   170,   170,   170,
     171,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   174,   174,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   176,   176,
     176,   176,   176,   177,   177,   178,   178,   179,   179,   180,
     180,   181,   181,   182,   182,   183,   183,   184,   184,   184,
     185,   185,   185,   186,   186,   187,   187,   187,   188,   188,
     188,   189,   189,   189,   190,   190,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   193,   193,   194,   194,
     194,   194,   194,   195,   195,   196,   196,   197,   198,   199,
     199,   200,   200,   201,   202,   203,   204,   204,   205,   205,
     205,   206,   206,   207,   207,   208,   208,   208,   208,   208,
     209,   209,   209,   210,   210,   211,   211,   211,   211,   211,
     211,   212,   212,   213,   213,   214,   215,   216,   217,   217,
     218,   219,   218,   220,   221,   220,   223,   222,   224,   222,
     225,   225,   225,   226,   226,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   228,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   229,   230,   229,   232,   231,   233,
     233,   233,   233,   235,   234
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
       1,     1,     4,     4,     4,     4,     4,     1,     4,     4,
       1,     1,     4,     4,     4,     4,     6,     6,     6,     8,
       6,     8,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     2,     3,     6,     6,     1,     1,     1,     1,
       2,     3,     4,     5,     4,     3,     5,     4,     4,     3,
       4,     5,     4,     3,     5,     4,     4,     3,     5,     7,
       6,     7,     6,     1,     1,     3,     4,     3,     4,     1,
       1,     3,     4,     3,     4,     1,     1,     2,     4,     4,
       2,     4,     4,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     1,     1,     4,     2,     2,     3,
       7,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     2,     2,     3,     7,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     2,     1,
       1,     1,     3,     2,     3,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     2,     1,
       5,     2,     5,     1,     1,     1,     1,     2,     3,     3,
       2,     3,     3,     1,     1,     0,     3,     4,     5,     5,
       6,     1,     1,     1,     1,     1,     6,     6,     1,     1,
       1,     0,     4,     1,     0,     4,     0,     4,     0,     4,
       4,     1,     1,     3,     7,     2,     2,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     3,     1,     4,     1,     1,     1,     0,
       3,     1,     1,     2,     1,     3,     2,     2,     5,     5,
       6,     1,     8,     2,     2,     1,     1,     2,     2,     2,
       2,     1,     1,     1,     8,     8,     8,    10,     2,     3,
       4,     2,     1,     0,     1,     0,     4,     0,     3,     1,
       3,     1,     3,     0,     2
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
#line 69 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2306 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 73 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2315 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 77 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2323 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 80 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2331 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 83 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2339 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 86 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2347 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 89 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2355 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 92 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2363 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 95 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2371 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 102 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2379 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 105 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2388 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 118 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2397 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 122 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2406 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 130 "src/ugbc.y"
                               {
        (yyval.string) = variable_pow( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2415 "src-generated/ugbc.tab.c"
    break;

  case 22: /* direct_integer: HASH Integer  */
#line 137 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2423 "src-generated/ugbc.tab.c"
    break;

  case 23: /* random_definition_simple: BYTE  */
#line 142 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2431 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: WORD  */
#line 145 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2439 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: DWORD  */
#line 148 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2447 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: POSITION  */
#line 151 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2455 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: COLOR  */
#line 154 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2463 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: WIDTH  */
#line 157 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2471 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: HEIGHT  */
#line 160 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2479 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition: random_definition_simple  */
#line 165 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2487 "src-generated/ugbc.tab.c"
    break;

  case 31: /* color_enumeration: BLACK  */
#line 170 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2496 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: WHITE  */
#line 174 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2505 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: RED  */
#line 178 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2514 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: CYAN  */
#line 182 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2523 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: VIOLET  */
#line 186 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2532 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: GREEN  */
#line 190 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2541 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: BLUE  */
#line 194 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2550 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: YELLOW  */
#line 198 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2559 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: ORANGE  */
#line 202 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2568 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: BROWN  */
#line 206 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2577 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: LIGHT RED  */
#line 210 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2586 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: DARK GREY  */
#line 214 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2595 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: GREY  */
#line 218 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2604 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: LIGHT GREEN  */
#line 222 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2613 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT BLUE  */
#line 226 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2622 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT GREY  */
#line 230 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2631 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: DARK BLUE  */
#line 234 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2640 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: MAGENTA  */
#line 238 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2649 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: PURPLE  */
#line 242 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2658 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: LAVENDER  */
#line 246 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2667 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: GOLD  */
#line 250 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2676 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: TURQUOISE  */
#line 254 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2685 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TAN  */
#line 258 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2694 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: YELLOW GREEN  */
#line 262 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2703 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: OLIVE GREEN  */
#line 266 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2712 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: PINK  */
#line 270 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2721 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PEACH  */
#line 274 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2730 "src-generated/ugbc.tab.c"
    break;

  case 58: /* exponential: Identifier  */
#line 280 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2738 "src-generated/ugbc.tab.c"
    break;

  case 59: /* exponential: Identifier DOLLAR  */
#line 283 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[-1].string);
      }
#line 2746 "src-generated/ugbc.tab.c"
    break;

  case 60: /* exponential: Integer  */
#line 286 "src/ugbc.y"
              { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2755 "src-generated/ugbc.tab.c"
    break;

  case 61: /* exponential: String  */
#line 290 "src/ugbc.y"
             { 
        outline1("; (expr string: \"%s\")", (yyvsp[0].string) );
        (yyval.string) = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", (yyval.string) );
        variable_store_string( _environment, (yyval.string), (yyvsp[0].string) );
        outline2("; variable stored: %s = %s", (yyval.string), (yyvsp[0].string) );
      }
#line 2767 "src-generated/ugbc.tab.c"
    break;

  case 62: /* exponential: OP BYTE CP Integer  */
#line 297 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2776 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: OP WORD CP Integer  */
#line 301 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2785 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: OP DWORD CP Integer  */
#line 305 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2794 "src-generated/ugbc.tab.c"
    break;

  case 65: /* exponential: OP POSITION CP Integer  */
#line 309 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2803 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: OP COLOR CP Integer  */
#line 313 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2812 "src-generated/ugbc.tab.c"
    break;

  case 67: /* exponential: color_enumeration  */
#line 317 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2820 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: PEEK OP direct_integer CP  */
#line 320 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2828 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: PEEK OP expr CP  */
#line 323 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 2836 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: XPEN  */
#line 326 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 2844 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: YPEN  */
#line 329 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 2852 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: COLLISION OP direct_integer CP  */
#line 332 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2860 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: COLLISION OP expr CP  */
#line 335 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2868 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: HIT OP direct_integer CP  */
#line 338 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2876 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: HIT OP expr CP  */
#line 341 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2884 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: LEFT OP expr COMMA expr CP  */
#line 344 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2892 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 347 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2900 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: MID OP expr COMMA expr CP  */
#line 350 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 2908 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 353 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2916 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: INSTR OP expr COMMA expr CP  */
#line 356 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 2924 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 359 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2932 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: UPPER OP expr CP  */
#line 362 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 2940 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: LOWER OP expr CP  */
#line 365 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 2948 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: STR OP expr CP  */
#line 368 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 2956 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: SPACE OP expr CP  */
#line 371 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 2964 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: FLIP OP expr CP  */
#line 374 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 2972 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: CHR OP expr CP  */
#line 377 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 2980 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: ASC OP expr CP  */
#line 380 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 2988 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: LEN OP expr CP  */
#line 383 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 2996 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: STRING OP expr COMMA expr CP  */
#line 386 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3004 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: VAL OP expr CP  */
#line 389 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3012 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: RANDOM random_definition  */
#line 392 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3020 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: OP expr CP  */
#line 395 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3028 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: MAX OP expr COMMA expr CP  */
#line 398 "src/ugbc.y"
                                {
        (yyval.string) = variable_max( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3036 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: MIN OP expr COMMA expr CP  */
#line 401 "src/ugbc.y"
                                {
        (yyval.string) = variable_min( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3044 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: TRUE  */
#line 404 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3053 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: FALSE  */
#line 408 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3062 "src-generated/ugbc.tab.c"
    break;

  case 100: /* bank_definition_simple: AT direct_integer  */
#line 417 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3070 "src-generated/ugbc.tab.c"
    break;

  case 101: /* bank_definition_simple: Identifier AT direct_integer  */
#line 420 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3078 "src-generated/ugbc.tab.c"
    break;

  case 102: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 423 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3086 "src-generated/ugbc.tab.c"
    break;

  case 103: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 426 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3094 "src-generated/ugbc.tab.c"
    break;

  case 104: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 429 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3102 "src-generated/ugbc.tab.c"
    break;

  case 105: /* bank_definition_simple: DATA AT direct_integer  */
#line 432 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3110 "src-generated/ugbc.tab.c"
    break;

  case 106: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 436 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3118 "src-generated/ugbc.tab.c"
    break;

  case 107: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 439 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3126 "src-generated/ugbc.tab.c"
    break;

  case 108: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 442 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3134 "src-generated/ugbc.tab.c"
    break;

  case 109: /* bank_definition_simple: CODE AT direct_integer  */
#line 445 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3142 "src-generated/ugbc.tab.c"
    break;

  case 110: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 449 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3150 "src-generated/ugbc.tab.c"
    break;

  case 111: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 452 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3158 "src-generated/ugbc.tab.c"
    break;

  case 112: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 455 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3166 "src-generated/ugbc.tab.c"
    break;

  case 113: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 458 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3174 "src-generated/ugbc.tab.c"
    break;

  case 114: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 462 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3182 "src-generated/ugbc.tab.c"
    break;

  case 115: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 465 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3190 "src-generated/ugbc.tab.c"
    break;

  case 116: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 468 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3198 "src-generated/ugbc.tab.c"
    break;

  case 117: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 471 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3206 "src-generated/ugbc.tab.c"
    break;

  case 118: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 477 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3214 "src-generated/ugbc.tab.c"
    break;

  case 119: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 480 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3222 "src-generated/ugbc.tab.c"
    break;

  case 120: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 483 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3230 "src-generated/ugbc.tab.c"
    break;

  case 121: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 486 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3238 "src-generated/ugbc.tab.c"
    break;

  case 122: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 489 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3246 "src-generated/ugbc.tab.c"
    break;

  case 125: /* raster_definition_simple: Identifier AT direct_integer  */
#line 498 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3254 "src-generated/ugbc.tab.c"
    break;

  case 126: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 501 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3262 "src-generated/ugbc.tab.c"
    break;

  case 127: /* raster_definition_expression: Identifier AT expr  */
#line 506 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3270 "src-generated/ugbc.tab.c"
    break;

  case 128: /* raster_definition_expression: AT expr WITH Identifier  */
#line 509 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3278 "src-generated/ugbc.tab.c"
    break;

  case 131: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 518 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3286 "src-generated/ugbc.tab.c"
    break;

  case 132: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 521 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3294 "src-generated/ugbc.tab.c"
    break;

  case 133: /* next_raster_definition_expression: Identifier AT expr  */
#line 526 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3302 "src-generated/ugbc.tab.c"
    break;

  case 134: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 529 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3310 "src-generated/ugbc.tab.c"
    break;

  case 137: /* color_definition_simple: BORDER direct_integer  */
#line 538 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3318 "src-generated/ugbc.tab.c"
    break;

  case 138: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 541 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3326 "src-generated/ugbc.tab.c"
    break;

  case 139: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 544 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3334 "src-generated/ugbc.tab.c"
    break;

  case 140: /* color_definition_expression: BORDER expr  */
#line 549 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3342 "src-generated/ugbc.tab.c"
    break;

  case 141: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 552 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3350 "src-generated/ugbc.tab.c"
    break;

  case 142: /* color_definition_expression: SPRITE expr TO expr  */
#line 555 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3358 "src-generated/ugbc.tab.c"
    break;

  case 148: /* wait_definition_simple: direct_integer CYCLES  */
#line 569 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3366 "src-generated/ugbc.tab.c"
    break;

  case 149: /* wait_definition_simple: direct_integer TICKS  */
#line 572 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3374 "src-generated/ugbc.tab.c"
    break;

  case 150: /* wait_definition_simple: direct_integer milliseconds  */
#line 575 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3382 "src-generated/ugbc.tab.c"
    break;

  case 151: /* wait_definition_expression: expr CYCLES  */
#line 580 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3390 "src-generated/ugbc.tab.c"
    break;

  case 152: /* wait_definition_expression: expr TICKS  */
#line 583 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3398 "src-generated/ugbc.tab.c"
    break;

  case 153: /* wait_definition_expression: expr milliseconds  */
#line 586 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3406 "src-generated/ugbc.tab.c"
    break;

  case 156: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 596 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3414 "src-generated/ugbc.tab.c"
    break;

  case 157: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 599 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3422 "src-generated/ugbc.tab.c"
    break;

  case 158: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 602 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3430 "src-generated/ugbc.tab.c"
    break;

  case 159: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 605 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3438 "src-generated/ugbc.tab.c"
    break;

  case 160: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 608 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3446 "src-generated/ugbc.tab.c"
    break;

  case 161: /* sprite_definition_simple: direct_integer ENABLE  */
#line 611 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3454 "src-generated/ugbc.tab.c"
    break;

  case 162: /* sprite_definition_simple: direct_integer DISABLE  */
#line 614 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3462 "src-generated/ugbc.tab.c"
    break;

  case 163: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 617 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3470 "src-generated/ugbc.tab.c"
    break;

  case 164: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 620 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3478 "src-generated/ugbc.tab.c"
    break;

  case 165: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 623 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3486 "src-generated/ugbc.tab.c"
    break;

  case 166: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 626 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3494 "src-generated/ugbc.tab.c"
    break;

  case 167: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 629 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3502 "src-generated/ugbc.tab.c"
    break;

  case 168: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 632 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3510 "src-generated/ugbc.tab.c"
    break;

  case 169: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 635 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3518 "src-generated/ugbc.tab.c"
    break;

  case 170: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 638 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3526 "src-generated/ugbc.tab.c"
    break;

  case 171: /* sprite_definition_expression: expr DATA FROM expr  */
#line 643 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3534 "src-generated/ugbc.tab.c"
    break;

  case 172: /* sprite_definition_expression: expr MULTICOLOR  */
#line 646 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3542 "src-generated/ugbc.tab.c"
    break;

  case 173: /* sprite_definition_expression: expr MONOCOLOR  */
#line 649 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3550 "src-generated/ugbc.tab.c"
    break;

  case 174: /* sprite_definition_expression: expr COLOR expr  */
#line 652 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3558 "src-generated/ugbc.tab.c"
    break;

  case 175: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 655 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3566 "src-generated/ugbc.tab.c"
    break;

  case 176: /* sprite_definition_expression: expr ENABLE  */
#line 658 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3574 "src-generated/ugbc.tab.c"
    break;

  case 177: /* sprite_definition_expression: expr DISABLE  */
#line 661 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3582 "src-generated/ugbc.tab.c"
    break;

  case 178: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 664 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3590 "src-generated/ugbc.tab.c"
    break;

  case 179: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 667 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3598 "src-generated/ugbc.tab.c"
    break;

  case 180: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 670 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3606 "src-generated/ugbc.tab.c"
    break;

  case 181: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 673 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3614 "src-generated/ugbc.tab.c"
    break;

  case 182: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 676 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3622 "src-generated/ugbc.tab.c"
    break;

  case 183: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 679 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3630 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 682 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3638 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 685 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3646 "src-generated/ugbc.tab.c"
    break;

  case 188: /* bitmap_definition_simple: AT direct_integer  */
#line 694 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3654 "src-generated/ugbc.tab.c"
    break;

  case 189: /* bitmap_definition_simple: ENABLE  */
#line 697 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3662 "src-generated/ugbc.tab.c"
    break;

  case 190: /* bitmap_definition_simple: DISABLE  */
#line 700 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 3670 "src-generated/ugbc.tab.c"
    break;

  case 191: /* bitmap_definition_simple: CLEAR  */
#line 703 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 3678 "src-generated/ugbc.tab.c"
    break;

  case 192: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 706 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 3686 "src-generated/ugbc.tab.c"
    break;

  case 193: /* bitmap_definition_expression: AT expr  */
#line 712 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3694 "src-generated/ugbc.tab.c"
    break;

  case 194: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 715 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 3702 "src-generated/ugbc.tab.c"
    break;

  case 197: /* textmap_definition_simple: AT direct_integer  */
#line 725 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3710 "src-generated/ugbc.tab.c"
    break;

  case 198: /* textmap_definition_expression: AT expr  */
#line 730 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3718 "src-generated/ugbc.tab.c"
    break;

  case 201: /* text_definition_simple: ENABLE  */
#line 739 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3726 "src-generated/ugbc.tab.c"
    break;

  case 202: /* text_definition_simple: DISABLE  */
#line 742 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 3734 "src-generated/ugbc.tab.c"
    break;

  case 204: /* tiles_definition_simple: AT direct_integer  */
#line 750 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 3742 "src-generated/ugbc.tab.c"
    break;

  case 205: /* tiles_definition_expression: AT expr  */
#line 755 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 3750 "src-generated/ugbc.tab.c"
    break;

  case 208: /* colormap_definition_simple: AT direct_integer  */
#line 764 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 3758 "src-generated/ugbc.tab.c"
    break;

  case 209: /* colormap_definition_simple: CLEAR  */
#line 767 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 3766 "src-generated/ugbc.tab.c"
    break;

  case 210: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 770 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3774 "src-generated/ugbc.tab.c"
    break;

  case 211: /* colormap_definition_expression: AT expr  */
#line 775 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3782 "src-generated/ugbc.tab.c"
    break;

  case 212: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 778 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3790 "src-generated/ugbc.tab.c"
    break;

  case 215: /* screen_definition_simple: ON  */
#line 788 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 3798 "src-generated/ugbc.tab.c"
    break;

  case 216: /* screen_definition_simple: OFF  */
#line 791 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 3806 "src-generated/ugbc.tab.c"
    break;

  case 217: /* screen_definition_simple: ROWS direct_integer  */
#line 794 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 3814 "src-generated/ugbc.tab.c"
    break;

  case 218: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 797 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3822 "src-generated/ugbc.tab.c"
    break;

  case 219: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 800 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3830 "src-generated/ugbc.tab.c"
    break;

  case 220: /* screen_definition_expression: ROWS expr  */
#line 805 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 3838 "src-generated/ugbc.tab.c"
    break;

  case 221: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 808 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3846 "src-generated/ugbc.tab.c"
    break;

  case 222: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 811 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3854 "src-generated/ugbc.tab.c"
    break;

  case 226: /* var_definition_simple: Identifier ON Identifier  */
#line 820 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 3862 "src-generated/ugbc.tab.c"
    break;

  case 227: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 823 "src/ugbc.y"
                                    {
      variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 3870 "src-generated/ugbc.tab.c"
    break;

  case 228: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 826 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 3878 "src-generated/ugbc.tab.c"
    break;

  case 229: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 829 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 3888 "src-generated/ugbc.tab.c"
    break;

  case 230: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 834 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 3898 "src-generated/ugbc.tab.c"
    break;

  case 231: /* goto_definition: Identifier  */
#line 841 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 3906 "src-generated/ugbc.tab.c"
    break;

  case 232: /* goto_definition: Integer  */
#line 844 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 3914 "src-generated/ugbc.tab.c"
    break;

  case 233: /* gosub_definition: Identifier  */
#line 850 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 3922 "src-generated/ugbc.tab.c"
    break;

  case 234: /* gosub_definition: Integer  */
#line 853 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 3930 "src-generated/ugbc.tab.c"
    break;

  case 236: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 862 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 3938 "src-generated/ugbc.tab.c"
    break;

  case 237: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 868 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 3946 "src-generated/ugbc.tab.c"
    break;

  case 240: /* on_goto_definition: Identifier  */
#line 877 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 3955 "src-generated/ugbc.tab.c"
    break;

  case 241: /* $@1: %empty  */
#line 881 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 3963 "src-generated/ugbc.tab.c"
    break;

  case 243: /* on_gosub_definition: Identifier  */
#line 886 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 3972 "src-generated/ugbc.tab.c"
    break;

  case 244: /* $@2: %empty  */
#line 890 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 3980 "src-generated/ugbc.tab.c"
    break;

  case 246: /* $@3: %empty  */
#line 895 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 3988 "src-generated/ugbc.tab.c"
    break;

  case 248: /* $@4: %empty  */
#line 898 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 3996 "src-generated/ugbc.tab.c"
    break;

  case 250: /* every_definition: expr TICKS GOSUB Identifier  */
#line 903 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4004 "src-generated/ugbc.tab.c"
    break;

  case 251: /* every_definition: ON  */
#line 906 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4012 "src-generated/ugbc.tab.c"
    break;

  case 252: /* every_definition: OFF  */
#line 909 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4020 "src-generated/ugbc.tab.c"
    break;

  case 253: /* add_definition: Identifier COMMA expr  */
#line 914 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4028 "src-generated/ugbc.tab.c"
    break;

  case 254: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 917 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4036 "src-generated/ugbc.tab.c"
    break;

  case 270: /* statement: INC Identifier  */
#line 938 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 4044 "src-generated/ugbc.tab.c"
    break;

  case 271: /* statement: DEC Identifier  */
#line 941 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 4052 "src-generated/ugbc.tab.c"
    break;

  case 272: /* statement: RANDOMIZE  */
#line 944 "src/ugbc.y"
              {
      randomize( _environment );
  }
#line 4060 "src-generated/ugbc.tab.c"
    break;

  case 273: /* statement: IF expr THEN  */
#line 947 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4068 "src-generated/ugbc.tab.c"
    break;

  case 274: /* statement: ELSE  */
#line 950 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 4076 "src-generated/ugbc.tab.c"
    break;

  case 275: /* statement: ELSE IF expr THEN  */
#line 953 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4084 "src-generated/ugbc.tab.c"
    break;

  case 276: /* statement: ENDIF  */
#line 956 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 4092 "src-generated/ugbc.tab.c"
    break;

  case 277: /* statement: DO  */
#line 959 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 4100 "src-generated/ugbc.tab.c"
    break;

  case 278: /* statement: LOOP  */
#line 962 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 4108 "src-generated/ugbc.tab.c"
    break;

  case 279: /* $@5: %empty  */
#line 965 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 4116 "src-generated/ugbc.tab.c"
    break;

  case 280: /* statement: WHILE $@5 expr  */
#line 967 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 4124 "src-generated/ugbc.tab.c"
    break;

  case 281: /* statement: WEND  */
#line 970 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 4132 "src-generated/ugbc.tab.c"
    break;

  case 282: /* statement: REPEAT  */
#line 973 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 4140 "src-generated/ugbc.tab.c"
    break;

  case 283: /* statement: UNTIL expr  */
#line 976 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 4148 "src-generated/ugbc.tab.c"
    break;

  case 284: /* statement: EXIT  */
#line 979 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 4156 "src-generated/ugbc.tab.c"
    break;

  case 285: /* statement: EXIT IF expr  */
#line 982 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 4164 "src-generated/ugbc.tab.c"
    break;

  case 286: /* statement: EXIT Integer  */
#line 985 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4172 "src-generated/ugbc.tab.c"
    break;

  case 287: /* statement: EXIT direct_integer  */
#line 988 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4180 "src-generated/ugbc.tab.c"
    break;

  case 288: /* statement: EXIT IF expr COMMA Integer  */
#line 991 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4188 "src-generated/ugbc.tab.c"
    break;

  case 289: /* statement: EXIT IF expr COMMA direct_integer  */
#line 994 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4196 "src-generated/ugbc.tab.c"
    break;

  case 290: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 997 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4204 "src-generated/ugbc.tab.c"
    break;

  case 291: /* statement: NEXT  */
#line 1000 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 4212 "src-generated/ugbc.tab.c"
    break;

  case 292: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1003 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4220 "src-generated/ugbc.tab.c"
    break;

  case 293: /* statement: BEG GAMELOOP  */
#line 1006 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 4228 "src-generated/ugbc.tab.c"
    break;

  case 294: /* statement: END GAMELOOP  */
#line 1009 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 4236 "src-generated/ugbc.tab.c"
    break;

  case 295: /* statement: GRAPHIC  */
#line 1012 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 4244 "src-generated/ugbc.tab.c"
    break;

  case 296: /* statement: HALT  */
#line 1015 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 4252 "src-generated/ugbc.tab.c"
    break;

  case 301: /* statement: RETURN  */
#line 1022 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 4260 "src-generated/ugbc.tab.c"
    break;

  case 302: /* statement: POP  */
#line 1025 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 4268 "src-generated/ugbc.tab.c"
    break;

  case 303: /* statement: DONE  */
#line 1028 "src/ugbc.y"
          {
      return 0;
  }
#line 4276 "src-generated/ugbc.tab.c"
    break;

  case 304: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1031 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4284 "src-generated/ugbc.tab.c"
    break;

  case 305: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1034 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4292 "src-generated/ugbc.tab.c"
    break;

  case 306: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1037 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 4300 "src-generated/ugbc.tab.c"
    break;

  case 307: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1040 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4308 "src-generated/ugbc.tab.c"
    break;

  case 308: /* statement: Identifier COLON  */
#line 1043 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 4316 "src-generated/ugbc.tab.c"
    break;

  case 309: /* statement: Identifier ASSIGN expr  */
#line 1046 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 4330 "src-generated/ugbc.tab.c"
    break;

  case 310: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1055 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 4344 "src-generated/ugbc.tab.c"
    break;

  case 311: /* statement: DEBUG expr  */
#line 1064 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 4352 "src-generated/ugbc.tab.c"
    break;

  case 314: /* statements_no_linenumbers: statement  */
#line 1072 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 4358 "src-generated/ugbc.tab.c"
    break;

  case 315: /* $@6: %empty  */
#line 1073 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 4364 "src-generated/ugbc.tab.c"
    break;

  case 317: /* $@7: %empty  */
#line 1077 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 4372 "src-generated/ugbc.tab.c"
    break;

  case 318: /* statements_with_linenumbers: Integer $@7 statements_no_linenumbers  */
#line 1079 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 4380 "src-generated/ugbc.tab.c"
    break;

  case 323: /* $@8: %empty  */
#line 1091 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 4386 "src-generated/ugbc.tab.c"
    break;


#line 4390 "src-generated/ugbc.tab.c"

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

#line 1093 "src/ugbc.y"


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
    exit(EXIT_FAILURE);
}

int main( int _argc, char *_argv[] ) {
    extern FILE *yyin;
    int flags, opt;
    int nsecs, tfnd;
    Environment * _environment = malloc(sizeof(Environment));

    while ((opt = getopt(_argc, _argv, "e:c:")) != -1) {
        switch (opt) {
                case 'c':
                    _environment->configurationFileName = strdup(optarg);
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

