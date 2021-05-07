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
  YYSYMBOL_MILLISECOND = 132,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 133,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 134,                    /* TICKS  */
  YYSYMBOL_BLACK = 135,                    /* BLACK  */
  YYSYMBOL_WHITE = 136,                    /* WHITE  */
  YYSYMBOL_RED = 137,                      /* RED  */
  YYSYMBOL_CYAN = 138,                     /* CYAN  */
  YYSYMBOL_VIOLET = 139,                   /* VIOLET  */
  YYSYMBOL_GREEN = 140,                    /* GREEN  */
  YYSYMBOL_BLUE = 141,                     /* BLUE  */
  YYSYMBOL_YELLOW = 142,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 143,                   /* ORANGE  */
  YYSYMBOL_BROWN = 144,                    /* BROWN  */
  YYSYMBOL_LIGHT = 145,                    /* LIGHT  */
  YYSYMBOL_DARK = 146,                     /* DARK  */
  YYSYMBOL_GREY = 147,                     /* GREY  */
  YYSYMBOL_GRAY = 148,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 149,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 150,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 151,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 152,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 153,                /* TURQUOISE  */
  YYSYMBOL_TAN = 154,                      /* TAN  */
  YYSYMBOL_PINK = 155,                     /* PINK  */
  YYSYMBOL_PEACH = 156,                    /* PEACH  */
  YYSYMBOL_OLIVE = 157,                    /* OLIVE  */
  YYSYMBOL_Identifier = 158,               /* Identifier  */
  YYSYMBOL_String = 159,                   /* String  */
  YYSYMBOL_Integer = 160,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 161,                 /* $accept  */
  YYSYMBOL_expr = 162,                     /* expr  */
  YYSYMBOL_expr_math = 163,                /* expr_math  */
  YYSYMBOL_term = 164,                     /* term  */
  YYSYMBOL_modula = 165,                   /* modula  */
  YYSYMBOL_factor = 166,                   /* factor  */
  YYSYMBOL_direct_integer = 167,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 168, /* random_definition_simple  */
  YYSYMBOL_random_definition = 169,        /* random_definition  */
  YYSYMBOL_color_enumeration = 170,        /* color_enumeration  */
  YYSYMBOL_exponential = 171,              /* exponential  */
  YYSYMBOL_position = 172,                 /* position  */
  YYSYMBOL_bank_definition_simple = 173,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 174, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 175,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 176, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 177, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 178,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 179, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 180, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 181,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 182,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 183, /* color_definition_expression  */
  YYSYMBOL_color_definition = 184,         /* color_definition  */
  YYSYMBOL_milliseconds = 185,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 186,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 187, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 188,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 189, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 190, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 191,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 192, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 193, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 194,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 195, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 196, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 197,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 198,   /* text_definition_simple  */
  YYSYMBOL_text_definition = 199,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 200,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 201, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 202,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 203, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 204, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 205,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 206, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 207, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 208,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 209,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 210,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 211,         /* gosub_definition  */
  YYSYMBOL_var_definition = 212,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 213,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 214, /* point_definition_expression  */
  YYSYMBOL_point_definition = 215,         /* point_definition  */
  YYSYMBOL_on_goto_definition = 216,       /* on_goto_definition  */
  YYSYMBOL_217_1 = 217,                    /* $@1  */
  YYSYMBOL_on_gosub_definition = 218,      /* on_gosub_definition  */
  YYSYMBOL_219_2 = 219,                    /* $@2  */
  YYSYMBOL_on_definition = 220,            /* on_definition  */
  YYSYMBOL_221_3 = 221,                    /* $@3  */
  YYSYMBOL_222_4 = 222,                    /* $@4  */
  YYSYMBOL_every_definition = 223,         /* every_definition  */
  YYSYMBOL_add_definition = 224,           /* add_definition  */
  YYSYMBOL_statement = 225,                /* statement  */
  YYSYMBOL_226_5 = 226,                    /* $@5  */
  YYSYMBOL_statements_no_linenumbers = 227, /* statements_no_linenumbers  */
  YYSYMBOL_228_6 = 228,                    /* $@6  */
  YYSYMBOL_statements_with_linenumbers = 229, /* statements_with_linenumbers  */
  YYSYMBOL_230_7 = 230,                    /* $@7  */
  YYSYMBOL_statements_complex = 231,       /* statements_complex  */
  YYSYMBOL_program = 232,                  /* program  */
  YYSYMBOL_233_8 = 233                     /* $@8  */
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
#define YYLAST   1406

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  161
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  322
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  614

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   415


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
     155,   156,   157,   158,   159,   160
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
     386,   389,   392,   395,   398,   402,   408,   408,   411,   414,
     417,   420,   423,   426,   430,   433,   436,   439,   443,   446,
     449,   452,   456,   459,   462,   465,   471,   474,   477,   480,
     483,   488,   489,   492,   495,   500,   503,   508,   509,   512,
     515,   520,   523,   528,   529,   532,   535,   538,   543,   546,
     549,   554,   555,   558,   559,   560,   563,   566,   569,   574,
     577,   580,   586,   587,   590,   593,   596,   599,   602,   605,
     608,   611,   614,   617,   620,   623,   626,   629,   632,   637,
     640,   643,   646,   649,   652,   655,   658,   661,   664,   667,
     670,   673,   676,   679,   684,   685,   688,   691,   694,   697,
     700,   706,   709,   715,   716,   719,   724,   729,   730,   733,
     736,   741,   744,   749,   754,   755,   758,   761,   764,   769,
     772,   778,   779,   782,   785,   788,   791,   794,   799,   802,
     805,   810,   811,   813,   814,   817,   820,   823,   828,   835,
     838,   844,   847,   853,   856,   862,   867,   868,   871,   875,
     875,   880,   884,   884,   889,   889,   892,   892,   897,   900,
     903,   908,   911,   917,   918,   919,   920,   921,   922,   923,
     924,   925,   926,   927,   928,   929,   930,   931,   932,   935,
     938,   941,   944,   947,   950,   953,   956,   959,   959,   964,
     967,   970,   973,   976,   979,   982,   985,   988,   991,   994,
     997,  1000,  1003,  1006,  1009,  1012,  1013,  1014,  1015,  1016,
    1019,  1022,  1025,  1028,  1031,  1034,  1037,  1040,  1049,  1058,
    1061,  1062,  1066,  1067,  1067,  1071,  1071,  1078,  1079,  1080,
    1081,  1085,  1085
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
  "ADD", "MILLISECOND", "MILLISECONDS", "TICKS", "BLACK", "WHITE", "RED",
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
     415
};
#endif

#define YYPACT_NINF (-214)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-243)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -214,    23,   683,  -214,  -214,  -104,   -90,   -21,  -214,   -15,
    1018,    67,     4,  1018,  -214,    82,   133,  1132,   -62,  -113,
    -214,  -214,  -214,   108,    83,    -7,  1132,    24,    32,  -214,
     122,   130,  1132,  -214,  -214,   155,   169,     7,  -214,  -214,
     105,  -214,   -34,  -214,  1132,    58,   904,   162,    59,    12,
    -214,   217,   222,   223,  -214,  -214,  -214,  1018,   204,  -214,
    -214,  -214,  1018,  1018,  1018,  -214,  -214,  -214,   777,  -214,
    -214,   195,   196,   197,    49,    88,   198,   201,  1132,  -214,
    -214,   216,   218,   221,   224,   225,   226,   228,   230,   233,
     234,   235,   237,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
     111,  -214,  -214,    57,     6,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,   116,   243,  -214,  -214,    48,    61,
     127,   149,   141,    56,  -214,  -214,  -214,  -214,  -214,   -19,
     190,   -17,   -16,   -12,   -10,   249,  -214,  -214,  -214,   229,
     252,  -214,  -214,  -214,  1018,  -214,  -214,   246,  -214,  -214,
    -214,  -214,  -214,  1018,   241,   244,  -214,  -214,  -214,   -38,
    -214,     0,  -214,  -214,  -214,  -214,  -214,  1132,  -214,  -214,
    -214,  -214,  1018,  -214,  -214,  -214,  1018,   250,  -214,  -214,
    -214,   212,  -214,  -214,  1132,  1132,  -214,  1018,  -214,  -214,
    -214,   248,  -214,  -214,  -214,  -214,  -214,  -214,  1132,  1132,
    -214,  -214,  -214,   278,  -214,  -214,   158,  -214,  1132,   294,
    -214,  -214,  1132,   289,    -1,  -214,   683,   683,   274,   275,
    1018,  -214,  -214,   238,   239,   240,   242,   272,   280,   281,
     284,   285,   287,  1018,  1018,  1018,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  1132,  1132,  -214,  1132,
    1132,  1132,  1132,  1132,  1132,  1132,  1132,  1132,  1132,  1132,
    1132,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  1246,  1246,  1246,  1246,
    1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,  1246,
    -214,  -214,  -214,  1018,   299,  -214,  -214,  -214,   265,   190,
     302,   190,   303,   190,   305,   190,   306,   190,  -214,  1132,
     298,  -214,  -214,    29,   104,    38,    63,  -214,  -214,  -214,
     300,   190,   304,  -214,  -214,   135,   144,    75,    98,  -214,
    -214,   308,  -214,  -214,  1018,  -214,  -214,  1018,  1018,  -214,
    -214,   290,   175,  -214,  -214,  -214,  -214,  -214,  1018,  -214,
     329,   331,  -214,  -214,  1018,   270,   333,  1132,   251,   336,
    1132,  -214,  1132,  -214,    -1,  -214,  -214,   187,   188,  -214,
    -214,  1132,   190,  1132,   190,   191,   192,   199,   202,   203,
    -214,   313,   315,   319,   320,   321,   322,   354,   357,   358,
     360,   334,   335,   337,   338,   361,   339,   340,   341,   342,
     343,   127,   127,   194,   194,   194,   194,   194,   194,   194,
     194,   149,   141,   141,  -214,   350,   352,  1018,    72,  -214,
     190,  -214,   190,  -214,   190,  -214,   190,    43,  -214,  1132,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  1132,  -214,
     190,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,   190,
    -214,  -214,  -214,  -214,  -214,  -214,   213,   227,   232,   369,
     344,   345,  1132,  1132,   376,   377,  -214,   -76,   316,   245,
    1132,   384,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  1132,  1132,  1132,  1132,  -214,  -214,  -214,  -214,  1132,
    -214,  -214,  -214,  -214,  -214,   247,   253,  -214,  -214,  -214,
    -214,  -214,  -214,   363,  -214,   364,  -214,   254,   106,  -214,
     387,  -214,   388,   389,  -214,   390,  -214,   385,  1018,  1132,
     190,   365,   366,  1132,   190,  -214,  -214,  1132,  -214,    28,
    1132,   367,   371,    31,    36,   372,  -214,  -214,   255,   256,
    -214,   370,  -214,   380,  -214,  1132,   190,   403,   410,  1132,
    -214,  -214,  -214,  -214,   405,   406,   386,   391,   307,  1132,
     407,   355,  -214,  -214,  1132,  -214,  1132,  -214,  -214,  -214,
    -214,   269,   271,   394,   396,   213,   227,  -214,  1132,  1132,
    -214,  -214,  1132,   397,  1132,  1132,   398,   399,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,   411,  -214,  -214,
    -214,  -214,  1132,  -214
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     321,     0,   311,     1,   310,     0,     0,     0,   301,     0,
       0,   289,     0,     0,   294,     0,     0,     0,   223,     0,
     276,   280,   277,     0,     0,     0,     0,     0,     0,   274,
       0,     0,     0,   270,   293,     0,     0,     0,   299,   300,
     272,   275,   282,   279,     0,     0,     0,     0,     0,     0,
     315,   312,   317,   319,   322,   268,   269,     0,     0,   127,
     128,   254,     0,     0,     0,   141,   142,   256,     0,    70,
      71,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,     0,    43,    48,    49,    50,    51,
      52,    53,    56,    57,     0,    58,    61,    60,     0,     2,
      12,    15,    17,     0,    67,    20,   152,   153,   257,     0,
       0,     0,     0,     0,     0,     0,   121,   122,   253,     0,
       0,   184,   185,   258,     0,   187,   188,   189,   193,   194,
     259,   213,   214,     0,     0,     0,   221,   222,   264,     0,
     295,     0,   233,   266,   229,   230,   296,     0,   199,   200,
     201,   261,     0,   204,   205,   262,     0,   207,   211,   212,
     263,     0,   291,   292,     0,     0,   309,     0,   197,   198,
     260,     0,   236,   237,   265,   231,   232,   297,     0,     0,
     284,   285,   281,     0,   249,   250,     0,   298,     0,     0,
     267,   306,     0,     0,   311,   313,   311,   311,     0,     0,
       0,   138,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    23,    24,    26,
      28,    29,    25,    30,    92,    22,     0,     0,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,    41,    44,    45,    46,    47,    42,    55,    59,
     143,   149,   144,   145,   150,   151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   148,     0,     0,   133,   134,   255,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,   174,   175,     0,     0,     0,     0,   171,   170,    96,
       0,     0,     0,   159,   160,     0,     0,     0,     0,   156,
     155,     0,   191,   186,     0,   218,   215,     0,     0,   244,
     246,     0,     0,   278,   203,   202,   209,   206,     0,   271,
       0,     0,   196,   195,     0,     0,   283,     0,     0,     0,
       0,   307,     0,   316,   311,   318,   320,     0,     0,   125,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,     5,     7,     8,     9,    10,     6,     3,
       4,    16,    18,    19,    21,     0,     0,     0,     0,   103,
       0,   115,     0,   107,     0,   111,     0,    99,   172,     0,
     179,   178,   183,   182,   177,   181,   176,   180,     0,   157,
       0,   164,   163,   168,   167,   162,   166,   161,   165,     0,
     192,   190,   219,   216,   220,   217,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,   251,   308,   314,   126,   124,   140,   137,   139,   136,
      66,    62,    63,    65,    64,    69,    68,    73,    72,    75,
      74,     0,     0,     0,     0,    82,    83,    84,    91,     0,
      85,    86,    87,    88,    89,     0,     0,   131,   129,   100,
     113,   105,   108,   102,   114,   106,   110,     0,     0,   169,
       0,   154,     0,   238,   245,   241,   247,   225,     0,     0,
       0,     0,     0,     0,     0,   286,   287,     0,   248,     0,
       0,     0,     0,     0,     0,     0,   132,   130,     0,     0,
     116,   101,   112,   104,   109,     0,     0,     0,     0,     0,
     227,   226,   210,   208,     0,     0,     0,     0,   288,     0,
       0,     0,    76,    77,     0,    78,     0,    80,    90,   118,
     120,     0,     0,     0,     0,     0,     0,   228,     0,     0,
     235,   234,     0,     0,     0,     0,     0,     0,   117,   119,
     173,   158,   240,   243,   302,   303,   290,     0,   304,   252,
      79,    81,     0,   305
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,   -13,   -70,   -71,   150,   -69,   236,  -214,  -214,  -214,
     146,   297,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,   317,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -147,  -214,  -145,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -213,  -214,  -214,  -214,
       8,  -214,  -214
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   118,   119,   120,   121,   122,   123,   243,   244,   124,
     125,   320,   136,   137,   138,    59,    60,    61,   295,   296,
     297,    65,    66,    67,   275,   126,   127,   128,   141,   142,
     143,   148,   149,   150,   188,   189,   190,   170,   171,   173,
     174,   175,   178,   179,   180,   156,   157,   158,   162,   166,
     197,   163,   192,   193,   194,   524,   557,   526,   558,   160,
     456,   457,   207,   210,    51,   167,    52,   364,    53,   214,
      54,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     139,   363,     4,    57,   159,   293,    75,   299,   301,     5,
       6,    62,   303,   181,   305,   339,    63,   176,   211,   186,
     341,     7,     8,     3,     9,   212,    10,    11,   130,    12,
      13,   202,   213,   206,   199,   569,   131,    14,   574,    15,
      16,    17,   342,   576,   218,   164,    18,   165,    75,   221,
     223,   225,    19,   132,    55,   232,    64,    20,    21,    22,
      23,    24,    25,   570,   340,   248,   575,    26,    56,   276,
     277,   577,   517,   278,   236,   279,   280,   281,   282,   283,
     177,   133,   134,   434,   535,   430,   431,    27,    28,   129,
      29,   518,   435,    30,    31,    32,   161,    33,    34,    35,
      36,    37,    38,    39,   509,    40,   144,   172,   436,    41,
      42,    43,    44,    45,   182,    46,    47,   437,   145,   146,
     445,   510,   183,   237,   238,   239,   200,   270,   271,   446,
      48,   332,   240,   241,   242,   270,   290,    58,   551,   294,
     335,   300,   302,   447,   168,   169,   304,   266,   306,   511,
     512,   473,   448,   267,   343,   552,   184,    49,   284,   344,
     432,   433,   135,   346,   185,   195,   285,   196,   287,   147,
     288,   350,   351,   198,   352,   151,   152,   153,   154,   187,
     272,   273,   274,   553,   554,   355,   356,   155,   272,   273,
     291,   441,   442,   191,   262,   359,   208,   263,   264,   361,
     443,   444,   276,   277,   265,   401,   402,   369,   403,   404,
     405,   406,   407,   408,   409,   410,   203,   209,   412,   413,
     381,   383,   385,   215,   365,   366,   216,   217,   220,   233,
     234,   235,   246,   387,   388,   247,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   245,   140,
     249,   261,   250,   308,   309,   251,   268,   286,   252,   253,
     254,   310,   255,   269,   256,   311,   312,   257,   258,   259,
     289,   260,    75,   307,   313,   334,   308,   321,   201,   348,
     415,   349,   354,   314,   322,   315,   316,   337,   323,   324,
     338,   357,   358,   219,   317,   318,   428,   325,   222,   224,
     226,   360,   362,   367,   368,   319,   326,   375,   327,   328,
     371,   372,   373,   418,   374,   376,   377,   329,   330,   378,
     379,   450,   380,   417,   452,   454,   420,   422,   319,   424,
     426,   429,   458,   459,   438,   460,   462,   440,   463,   466,
     467,   464,   449,   470,   468,   474,   475,   471,   485,   472,
     486,   480,   481,   469,   487,   488,   489,   490,   476,   482,
     478,   491,   483,   484,   492,   493,   298,   494,   499,   495,
     496,   523,   497,   498,   500,   501,   502,   503,   504,   505,
     333,   506,   528,   533,   534,   525,   529,   530,   537,   336,
     527,   540,   548,   549,   555,   556,  -239,  -242,   559,   581,
     564,   565,   572,   538,   507,   546,   573,   578,   345,   582,
     585,   547,   347,   550,   579,   580,   519,   586,   588,   589,
     594,   590,   592,   353,   612,   520,   591,   595,   598,   600,
     599,   601,   607,   610,   611,   414,   411,   331,   602,     0,
     292,   603,     0,     0,     0,     0,     0,     0,     0,   531,
     532,     0,     0,     0,     0,     0,   370,   539,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   382,
     384,   386,     0,     0,     0,     0,     0,     0,   541,   542,
     543,   544,     0,     0,     0,     0,   545,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   560,   562,     0,     0,     0,
     566,     0,     0,     0,   568,     0,     0,   571,     0,   416,
       0,     0,     0,     0,     0,   419,     0,   421,     0,   423,
       0,   425,   583,   427,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   593,   439,     0,     0,
       0,   596,     0,   597,     0,     0,     0,     0,     0,     0,
     451,     0,     0,   453,   455,   604,   605,     0,     0,   606,
       0,   608,   609,     0,   461,     0,     0,     0,     0,     0,
     465,     0,     0,     0,     0,     0,     0,     0,     0,   613,
       0,     0,     0,     0,     0,     0,     0,     0,   477,     0,
     479,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   508,     0,     0,   513,     0,   514,     0,
     515,     0,   516,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   521,     0,     0,     0,
       0,     0,     0,     0,     0,   522,     4,     0,     0,     0,
       0,     0,     0,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,   536,     0,     7,     8,     0,     9,     0,
      10,    11,     0,    12,    13,     0,     0,     0,     0,     0,
       0,    14,     0,    15,    16,    17,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   561,     0,   563,     0,     0,     0,
     567,    27,    28,     0,    29,     0,     0,    30,    31,    32,
       0,    33,    34,    35,    36,    37,    38,    39,     0,    40,
       0,     0,   584,    41,    42,    43,    44,    45,     0,    46,
      47,     0,   227,     0,     0,     0,     0,     0,     0,     0,
       0,    68,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,    50,    72,     0,     0,    73,     0,     0,
      74,   228,   229,   230,     0,     0,     0,     0,     0,     0,
       0,     0,   231,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,    79,    80,     0,     0,     0,
       0,     0,     0,     0,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    68,     0,
       0,     0,     0,     0,     0,     0,   204,   205,     0,     0,
       0,     0,     0,     0,    69,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,     0,     0,    73,     0,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,    79,    80,     0,     0,     0,     0,     0,     0,
       0,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    68,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,     0,    69,    70,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,     0,     0,    73,     0,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,    80,     0,     0,
       0,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
       0,     0,     0,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    68,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
       0,     0,    69,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
       0,     0,    73,     0,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
      79,    80,     0,     0,     0,     0,     0,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,     0,     0,     0,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      68,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,     0,     0,    69,    70,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,     0,     0,    73,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,    80,     0,     0,     0,     0,
       0,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,     0,     0,
       0,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117
};

static const yytype_int16 yycheck[] =
{
      13,   214,     3,    24,    17,    24,    82,    24,    24,    10,
      11,    26,    24,    26,    24,    53,    31,    24,     6,    32,
      20,    22,    23,     0,    25,    13,    27,    28,    24,    30,
      31,    44,    20,    46,    68,     7,    32,    38,     7,    40,
      41,    42,    42,     7,    57,   158,    47,   160,    82,    62,
      63,    64,    53,    49,   158,    68,    71,    58,    59,    60,
      61,    62,    63,    35,   102,    78,    35,    68,   158,     8,
       9,    35,    29,    12,    25,    14,    15,    16,    17,    18,
      87,    77,    78,    45,   160,    56,    57,    88,    89,    22,
      91,    48,    54,    94,    95,    96,   158,    98,    99,   100,
     101,   102,   103,   104,    32,   106,    24,    24,    45,   110,
     111,   112,   113,   114,    90,   116,   117,    54,    36,    37,
      45,    49,    90,    74,    75,    76,   160,    79,    80,    54,
     131,   144,    83,    84,    85,    79,    80,   158,    32,   158,
     153,   158,   158,    45,    36,    37,   158,   141,   158,    77,
      78,   364,    54,   147,   167,    49,    34,   158,    97,   172,
      56,    57,   158,   176,    34,   158,   105,   160,    19,    87,
      21,   184,   185,    68,   187,    42,    43,    44,    45,    24,
     132,   133,   134,    77,    78,   198,   199,    54,   132,   133,
     134,    56,    57,    24,   137,   208,    34,   140,   141,   212,
      56,    57,     8,     9,   147,   276,   277,   220,   278,   279,
     280,   281,   282,   283,   284,   285,   158,   158,   287,   288,
     233,   234,   235,     6,   216,   217,     4,     4,    24,    34,
      34,    34,    34,   246,   247,    34,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   160,    13,
      34,   140,    34,    24,    25,    34,   140,   130,    34,    34,
      34,    32,    34,    20,    34,    36,    37,    34,    34,    34,
     129,    34,    82,    24,    45,    29,    24,    25,    42,    29,
     293,    69,    34,    54,    32,    56,    57,    46,    36,    37,
      46,    13,   134,    57,    65,    66,   309,    45,    62,    63,
      64,     7,    13,    29,    29,    76,    54,    35,    56,    57,
      72,    72,    72,    48,    72,    35,    35,    65,    66,    35,
      35,   334,    35,    24,   337,   338,    24,    24,    76,    24,
      24,    33,    42,   158,    34,   348,     7,    33,     7,    69,
       7,   354,    34,     7,   357,   158,   158,   360,    35,   362,
      35,   160,   160,   102,    35,    35,    35,    35,   371,   160,
     373,     7,   160,   160,     7,     7,   130,     7,     7,    35,
      35,   158,    35,    35,    35,    35,    35,    35,    35,    29,
     144,    29,    13,     7,     7,   158,    42,    42,    72,   153,
     158,     7,    29,    29,     7,     7,     7,     7,    13,    29,
      35,    35,    35,   158,   417,   158,    35,    35,   172,    29,
       7,   158,   176,   159,   159,   159,   429,     7,    13,    13,
      13,    35,   115,   187,    13,   438,    35,    72,   159,    35,
     159,    35,    35,    35,    35,   289,   286,   140,   585,    -1,
     123,   586,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   462,
     463,    -1,    -1,    -1,    -1,    -1,   220,   470,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,    -1,   491,   492,
     493,   494,    -1,    -1,    -1,    -1,   499,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   528,   529,    -1,    -1,    -1,
     533,    -1,    -1,    -1,   537,    -1,    -1,   540,    -1,   293,
      -1,    -1,    -1,    -1,    -1,   299,    -1,   301,    -1,   303,
      -1,   305,   555,   307,    -1,    -1,   559,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   569,   321,    -1,    -1,
      -1,   574,    -1,   576,    -1,    -1,    -1,    -1,    -1,    -1,
     334,    -1,    -1,   337,   338,   588,   589,    -1,    -1,   592,
      -1,   594,   595,    -1,   348,    -1,    -1,    -1,    -1,    -1,
     354,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   612,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,
     374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   417,    -1,    -1,   420,    -1,   422,    -1,
     424,    -1,   426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   440,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   449,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   467,    -1,    22,    23,    -1,    25,    -1,
      27,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   528,    -1,   530,    -1,    -1,    -1,
     534,    88,    89,    -1,    91,    -1,    -1,    94,    95,    96,
      -1,    98,    99,   100,   101,   102,   103,   104,    -1,   106,
      -1,    -1,   556,   110,   111,   112,   113,   114,    -1,   116,
     117,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,    -1,   160,    67,    -1,    -1,    70,    -1,    -1,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    34,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,    34,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      34,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    -1,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   232,   233,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    88,    89,    91,
      94,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     106,   110,   111,   112,   113,   114,   116,   117,   131,   158,
     160,   225,   227,   229,   231,   158,   158,    24,   158,   176,
     177,   178,    26,    31,    71,   182,   183,   184,    34,    50,
      51,    52,    67,    70,    73,    82,    94,    95,   107,   108,
     109,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   162,   163,
     164,   165,   166,   167,   170,   171,   186,   187,   188,    22,
      24,    32,    49,    77,    78,   158,   173,   174,   175,   162,
     167,   189,   190,   191,    24,    36,    37,    87,   192,   193,
     194,    42,    43,    44,    45,    54,   206,   207,   208,   162,
     220,   158,   209,   212,   158,   160,   210,   226,    36,    37,
     198,   199,    24,   200,   201,   202,    24,    87,   203,   204,
     205,   162,    90,    90,    34,    34,   162,    24,   195,   196,
     197,    24,   213,   214,   215,   158,   160,   211,    68,    68,
     160,   167,   162,   158,    42,    43,   162,   223,    34,   158,
     224,     6,    13,    20,   230,     6,     4,     4,   162,   167,
      24,   162,   167,   162,   167,   162,   167,    25,    74,    75,
      76,    85,   162,    34,    34,    34,    25,    74,    75,    76,
      83,    84,    85,   168,   169,   160,    34,    34,   162,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,   140,   137,   140,   141,   147,   141,   147,   140,    20,
      79,    80,   132,   133,   134,   185,     8,     9,    12,    14,
      15,    16,    17,    18,    97,   105,   130,    19,    21,   129,
      80,   134,   185,    24,   158,   179,   180,   181,   167,    24,
     158,    24,   158,    24,   158,    24,   158,    24,    24,    25,
      32,    36,    37,    45,    54,    56,    57,    65,    66,    76,
     172,    25,    32,    36,    37,    45,    54,    56,    57,    65,
      66,   172,   162,   167,    29,   162,   167,    46,    46,    53,
     102,    20,    42,   162,   162,   167,   162,   167,    29,    69,
     162,   162,   162,   167,    34,   162,   162,    13,   134,   162,
       7,   162,    13,   227,   228,   231,   231,    29,    29,   162,
     167,    72,    72,    72,    72,    35,    35,    35,    35,    35,
      35,   162,   167,   162,   167,   162,   167,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   164,   164,   163,   163,   163,   163,   163,   163,   163,
     163,   165,   166,   166,   171,   162,   167,    24,    48,   167,
      24,   167,    24,   167,    24,   167,    24,   167,   162,    33,
      56,    57,    56,    57,    45,    54,    45,    54,    34,   167,
      33,    56,    57,    56,    57,    45,    54,    45,    54,    34,
     162,   167,   162,   167,   162,   167,   221,   222,    42,   158,
     162,   167,     7,     7,   162,   167,    69,     7,   162,   102,
       7,   162,   162,   227,   158,   158,   162,   167,   162,   167,
     160,   160,   160,   160,   160,    35,    35,    35,    35,    35,
      35,     7,     7,     7,     7,    35,    35,    35,    35,     7,
      35,    35,    35,    35,    35,    29,    29,   162,   167,    32,
      49,    77,    78,   167,   167,   167,   167,    29,    48,   162,
     162,   167,   167,   158,   216,   158,   218,   158,    13,    42,
      42,   162,   162,     7,     7,   160,   167,    72,   158,   162,
       7,   162,   162,   162,   162,   162,   158,   158,    29,    29,
     159,    32,    49,    77,    78,     7,     7,   217,   219,    13,
     162,   167,   162,   167,    35,    35,   162,   167,   162,     7,
      35,   162,    35,    35,     7,    35,     7,    35,    35,   159,
     159,    29,    29,   162,   167,     7,     7,   162,    13,    13,
      35,    35,   115,   162,    13,    72,   162,   162,   159,   159,
      35,    35,   216,   218,   162,   162,   162,    35,   162,   162,
      35,    35,    13,   162
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   161,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   163,   163,   163,   164,   164,   165,   165,   165,
     166,   166,   167,   168,   168,   168,   168,   168,   168,   168,
     169,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   172,   172,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   174,   174,   174,   174,
     174,   175,   175,   176,   176,   177,   177,   178,   178,   179,
     179,   180,   180,   181,   181,   182,   182,   182,   183,   183,
     183,   184,   184,   185,   185,   185,   186,   186,   186,   187,
     187,   187,   188,   188,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   191,   191,   192,   192,   192,   192,
     192,   193,   193,   194,   194,   195,   196,   197,   197,   198,
     198,   199,   200,   201,   202,   202,   203,   203,   203,   204,
     204,   205,   205,   206,   206,   206,   206,   206,   207,   207,
     207,   208,   208,   209,   209,   209,   209,   209,   209,   210,
     210,   211,   211,   212,   213,   214,   215,   215,   216,   217,
     216,   218,   219,   218,   221,   220,   222,   220,   223,   223,
     223,   224,   224,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   226,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   227,   228,   227,   230,   229,   231,   231,   231,
     231,   233,   232
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
       6,     4,     2,     3,     1,     1,     1,     1,     2,     3,
       4,     5,     4,     3,     5,     4,     4,     3,     4,     5,
       4,     3,     5,     4,     4,     3,     5,     7,     6,     7,
       6,     1,     1,     3,     4,     3,     4,     1,     1,     3,
       4,     3,     4,     1,     1,     2,     4,     4,     2,     4,
       4,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     1,     1,     4,     2,     2,     3,     7,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       2,     2,     3,     7,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     2,     1,     1,     1,
       3,     2,     3,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     2,     1,     5,     2,
       5,     1,     1,     1,     1,     2,     3,     3,     2,     3,
       3,     1,     1,     0,     3,     4,     5,     5,     6,     1,
       1,     1,     1,     1,     6,     6,     1,     1,     1,     0,
       4,     1,     0,     4,     0,     4,     0,     4,     4,     1,
       1,     3,     7,     2,     2,     3,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     3,     1,     4,     1,     1,     1,     0,     3,     1,
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
#line 69 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2310 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 73 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2319 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 77 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2327 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 80 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2335 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 83 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2343 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 86 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2351 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 89 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2359 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 92 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2367 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 95 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2375 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 102 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2383 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 105 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2392 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 118 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2401 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 122 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2410 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 130 "src/ugbc.y"
                               {
        (yyval.string) = variable_pow( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2419 "src-generated/ugbc.tab.c"
    break;

  case 22: /* direct_integer: HASH Integer  */
#line 137 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2427 "src-generated/ugbc.tab.c"
    break;

  case 23: /* random_definition_simple: BYTE  */
#line 142 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2435 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: WORD  */
#line 145 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2443 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: DWORD  */
#line 148 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2451 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: POSITION  */
#line 151 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2459 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: COLOR  */
#line 154 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2467 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: WIDTH  */
#line 157 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2475 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: HEIGHT  */
#line 160 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2483 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition: random_definition_simple  */
#line 165 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2491 "src-generated/ugbc.tab.c"
    break;

  case 31: /* color_enumeration: BLACK  */
#line 170 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2500 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: WHITE  */
#line 174 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2509 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: RED  */
#line 178 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2518 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: CYAN  */
#line 182 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2527 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: VIOLET  */
#line 186 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2536 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: GREEN  */
#line 190 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2545 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: BLUE  */
#line 194 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2554 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: YELLOW  */
#line 198 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2563 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: ORANGE  */
#line 202 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2572 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: BROWN  */
#line 206 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2581 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: LIGHT RED  */
#line 210 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2590 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: DARK GREY  */
#line 214 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2599 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: GREY  */
#line 218 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2608 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: LIGHT GREEN  */
#line 222 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2617 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT BLUE  */
#line 226 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2626 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT GREY  */
#line 230 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2635 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: DARK BLUE  */
#line 234 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2644 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: MAGENTA  */
#line 238 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2653 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: PURPLE  */
#line 242 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2662 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: LAVENDER  */
#line 246 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2671 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: GOLD  */
#line 250 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2680 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: TURQUOISE  */
#line 254 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2689 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TAN  */
#line 258 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2698 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: YELLOW GREEN  */
#line 262 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2707 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: OLIVE GREEN  */
#line 266 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2716 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: PINK  */
#line 270 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2725 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PEACH  */
#line 274 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2734 "src-generated/ugbc.tab.c"
    break;

  case 58: /* exponential: Identifier  */
#line 280 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2742 "src-generated/ugbc.tab.c"
    break;

  case 59: /* exponential: Identifier DOLLAR  */
#line 283 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[-1].string);
      }
#line 2750 "src-generated/ugbc.tab.c"
    break;

  case 60: /* exponential: Integer  */
#line 286 "src/ugbc.y"
              { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2759 "src-generated/ugbc.tab.c"
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
#line 2771 "src-generated/ugbc.tab.c"
    break;

  case 62: /* exponential: OP BYTE CP Integer  */
#line 297 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2780 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: OP WORD CP Integer  */
#line 301 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2789 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: OP DWORD CP Integer  */
#line 305 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2798 "src-generated/ugbc.tab.c"
    break;

  case 65: /* exponential: OP POSITION CP Integer  */
#line 309 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2807 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: OP COLOR CP Integer  */
#line 313 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2816 "src-generated/ugbc.tab.c"
    break;

  case 67: /* exponential: color_enumeration  */
#line 317 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2824 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: PEEK OP direct_integer CP  */
#line 320 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2832 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: PEEK OP expr CP  */
#line 323 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 2840 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: XPEN  */
#line 326 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 2848 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: YPEN  */
#line 329 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 2856 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: COLLISION OP direct_integer CP  */
#line 332 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2864 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: COLLISION OP expr CP  */
#line 335 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2872 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: HIT OP direct_integer CP  */
#line 338 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2880 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: HIT OP expr CP  */
#line 341 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2888 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: LEFT OP expr COMMA expr CP  */
#line 344 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2896 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 347 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2904 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: MID OP expr COMMA expr CP  */
#line 350 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 2912 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 353 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2920 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: INSTR OP expr COMMA expr CP  */
#line 356 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 2928 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 359 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2936 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: UPPER OP expr CP  */
#line 362 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 2944 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: LOWER OP expr CP  */
#line 365 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 2952 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: STR OP expr CP  */
#line 368 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 2960 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: SPACE OP expr CP  */
#line 371 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 2968 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: FLIP OP expr CP  */
#line 374 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 2976 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: CHR OP expr CP  */
#line 377 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 2984 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: ASC OP expr CP  */
#line 380 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 2992 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: LEN OP expr CP  */
#line 383 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3000 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: STRING OP expr COMMA expr CP  */
#line 386 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3008 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: VAL OP expr CP  */
#line 389 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3016 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: RANDOM random_definition  */
#line 392 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3024 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: OP expr CP  */
#line 395 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3032 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: TRUE  */
#line 398 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3041 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FALSE  */
#line 402 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3050 "src-generated/ugbc.tab.c"
    break;

  case 98: /* bank_definition_simple: AT direct_integer  */
#line 411 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3058 "src-generated/ugbc.tab.c"
    break;

  case 99: /* bank_definition_simple: Identifier AT direct_integer  */
#line 414 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3066 "src-generated/ugbc.tab.c"
    break;

  case 100: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 417 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3074 "src-generated/ugbc.tab.c"
    break;

  case 101: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 420 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3082 "src-generated/ugbc.tab.c"
    break;

  case 102: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 423 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3090 "src-generated/ugbc.tab.c"
    break;

  case 103: /* bank_definition_simple: DATA AT direct_integer  */
#line 426 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3098 "src-generated/ugbc.tab.c"
    break;

  case 104: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 430 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3106 "src-generated/ugbc.tab.c"
    break;

  case 105: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 433 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3114 "src-generated/ugbc.tab.c"
    break;

  case 106: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 436 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3122 "src-generated/ugbc.tab.c"
    break;

  case 107: /* bank_definition_simple: CODE AT direct_integer  */
#line 439 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3130 "src-generated/ugbc.tab.c"
    break;

  case 108: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 443 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3138 "src-generated/ugbc.tab.c"
    break;

  case 109: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 446 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3146 "src-generated/ugbc.tab.c"
    break;

  case 110: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 449 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3154 "src-generated/ugbc.tab.c"
    break;

  case 111: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 452 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3162 "src-generated/ugbc.tab.c"
    break;

  case 112: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 456 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3170 "src-generated/ugbc.tab.c"
    break;

  case 113: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 459 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3178 "src-generated/ugbc.tab.c"
    break;

  case 114: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 462 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3186 "src-generated/ugbc.tab.c"
    break;

  case 115: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 465 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3194 "src-generated/ugbc.tab.c"
    break;

  case 116: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 471 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3202 "src-generated/ugbc.tab.c"
    break;

  case 117: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 474 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3210 "src-generated/ugbc.tab.c"
    break;

  case 118: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 477 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3218 "src-generated/ugbc.tab.c"
    break;

  case 119: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 480 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3226 "src-generated/ugbc.tab.c"
    break;

  case 120: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 483 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3234 "src-generated/ugbc.tab.c"
    break;

  case 123: /* raster_definition_simple: Identifier AT direct_integer  */
#line 492 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3242 "src-generated/ugbc.tab.c"
    break;

  case 124: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 495 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3250 "src-generated/ugbc.tab.c"
    break;

  case 125: /* raster_definition_expression: Identifier AT expr  */
#line 500 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3258 "src-generated/ugbc.tab.c"
    break;

  case 126: /* raster_definition_expression: AT expr WITH Identifier  */
#line 503 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3266 "src-generated/ugbc.tab.c"
    break;

  case 129: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 512 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3274 "src-generated/ugbc.tab.c"
    break;

  case 130: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 515 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3282 "src-generated/ugbc.tab.c"
    break;

  case 131: /* next_raster_definition_expression: Identifier AT expr  */
#line 520 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3290 "src-generated/ugbc.tab.c"
    break;

  case 132: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 523 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3298 "src-generated/ugbc.tab.c"
    break;

  case 135: /* color_definition_simple: BORDER direct_integer  */
#line 532 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3306 "src-generated/ugbc.tab.c"
    break;

  case 136: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 535 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3314 "src-generated/ugbc.tab.c"
    break;

  case 137: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 538 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3322 "src-generated/ugbc.tab.c"
    break;

  case 138: /* color_definition_expression: BORDER expr  */
#line 543 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3330 "src-generated/ugbc.tab.c"
    break;

  case 139: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 546 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3338 "src-generated/ugbc.tab.c"
    break;

  case 140: /* color_definition_expression: SPRITE expr TO expr  */
#line 549 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3346 "src-generated/ugbc.tab.c"
    break;

  case 146: /* wait_definition_simple: direct_integer CYCLES  */
#line 563 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3354 "src-generated/ugbc.tab.c"
    break;

  case 147: /* wait_definition_simple: direct_integer TICKS  */
#line 566 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3362 "src-generated/ugbc.tab.c"
    break;

  case 148: /* wait_definition_simple: direct_integer milliseconds  */
#line 569 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3370 "src-generated/ugbc.tab.c"
    break;

  case 149: /* wait_definition_expression: expr CYCLES  */
#line 574 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3378 "src-generated/ugbc.tab.c"
    break;

  case 150: /* wait_definition_expression: expr TICKS  */
#line 577 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3386 "src-generated/ugbc.tab.c"
    break;

  case 151: /* wait_definition_expression: expr milliseconds  */
#line 580 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3394 "src-generated/ugbc.tab.c"
    break;

  case 154: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 590 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3402 "src-generated/ugbc.tab.c"
    break;

  case 155: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 593 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3410 "src-generated/ugbc.tab.c"
    break;

  case 156: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 596 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3418 "src-generated/ugbc.tab.c"
    break;

  case 157: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 599 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3426 "src-generated/ugbc.tab.c"
    break;

  case 158: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 602 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3434 "src-generated/ugbc.tab.c"
    break;

  case 159: /* sprite_definition_simple: direct_integer ENABLE  */
#line 605 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3442 "src-generated/ugbc.tab.c"
    break;

  case 160: /* sprite_definition_simple: direct_integer DISABLE  */
#line 608 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3450 "src-generated/ugbc.tab.c"
    break;

  case 161: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 611 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3458 "src-generated/ugbc.tab.c"
    break;

  case 162: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 614 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3466 "src-generated/ugbc.tab.c"
    break;

  case 163: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 617 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3474 "src-generated/ugbc.tab.c"
    break;

  case 164: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 620 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3482 "src-generated/ugbc.tab.c"
    break;

  case 165: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 623 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3490 "src-generated/ugbc.tab.c"
    break;

  case 166: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 626 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3498 "src-generated/ugbc.tab.c"
    break;

  case 167: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 629 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3506 "src-generated/ugbc.tab.c"
    break;

  case 168: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 632 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3514 "src-generated/ugbc.tab.c"
    break;

  case 169: /* sprite_definition_expression: expr DATA FROM expr  */
#line 637 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3522 "src-generated/ugbc.tab.c"
    break;

  case 170: /* sprite_definition_expression: expr MULTICOLOR  */
#line 640 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3530 "src-generated/ugbc.tab.c"
    break;

  case 171: /* sprite_definition_expression: expr MONOCOLOR  */
#line 643 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3538 "src-generated/ugbc.tab.c"
    break;

  case 172: /* sprite_definition_expression: expr COLOR expr  */
#line 646 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3546 "src-generated/ugbc.tab.c"
    break;

  case 173: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 649 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3554 "src-generated/ugbc.tab.c"
    break;

  case 174: /* sprite_definition_expression: expr ENABLE  */
#line 652 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3562 "src-generated/ugbc.tab.c"
    break;

  case 175: /* sprite_definition_expression: expr DISABLE  */
#line 655 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3570 "src-generated/ugbc.tab.c"
    break;

  case 176: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 658 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3578 "src-generated/ugbc.tab.c"
    break;

  case 177: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 661 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3586 "src-generated/ugbc.tab.c"
    break;

  case 178: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 664 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3594 "src-generated/ugbc.tab.c"
    break;

  case 179: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 667 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3602 "src-generated/ugbc.tab.c"
    break;

  case 180: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 670 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3610 "src-generated/ugbc.tab.c"
    break;

  case 181: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 673 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3618 "src-generated/ugbc.tab.c"
    break;

  case 182: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 676 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3626 "src-generated/ugbc.tab.c"
    break;

  case 183: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 679 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3634 "src-generated/ugbc.tab.c"
    break;

  case 186: /* bitmap_definition_simple: AT direct_integer  */
#line 688 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3642 "src-generated/ugbc.tab.c"
    break;

  case 187: /* bitmap_definition_simple: ENABLE  */
#line 691 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3650 "src-generated/ugbc.tab.c"
    break;

  case 188: /* bitmap_definition_simple: DISABLE  */
#line 694 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 3658 "src-generated/ugbc.tab.c"
    break;

  case 189: /* bitmap_definition_simple: CLEAR  */
#line 697 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 3666 "src-generated/ugbc.tab.c"
    break;

  case 190: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 700 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 3674 "src-generated/ugbc.tab.c"
    break;

  case 191: /* bitmap_definition_expression: AT expr  */
#line 706 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3682 "src-generated/ugbc.tab.c"
    break;

  case 192: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 709 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 3690 "src-generated/ugbc.tab.c"
    break;

  case 195: /* textmap_definition_simple: AT direct_integer  */
#line 719 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3698 "src-generated/ugbc.tab.c"
    break;

  case 196: /* textmap_definition_expression: AT expr  */
#line 724 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3706 "src-generated/ugbc.tab.c"
    break;

  case 199: /* text_definition_simple: ENABLE  */
#line 733 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3714 "src-generated/ugbc.tab.c"
    break;

  case 200: /* text_definition_simple: DISABLE  */
#line 736 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 3722 "src-generated/ugbc.tab.c"
    break;

  case 202: /* tiles_definition_simple: AT direct_integer  */
#line 744 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 3730 "src-generated/ugbc.tab.c"
    break;

  case 203: /* tiles_definition_expression: AT expr  */
#line 749 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 3738 "src-generated/ugbc.tab.c"
    break;

  case 206: /* colormap_definition_simple: AT direct_integer  */
#line 758 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 3746 "src-generated/ugbc.tab.c"
    break;

  case 207: /* colormap_definition_simple: CLEAR  */
#line 761 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 3754 "src-generated/ugbc.tab.c"
    break;

  case 208: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 764 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3762 "src-generated/ugbc.tab.c"
    break;

  case 209: /* colormap_definition_expression: AT expr  */
#line 769 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3770 "src-generated/ugbc.tab.c"
    break;

  case 210: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 772 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3778 "src-generated/ugbc.tab.c"
    break;

  case 213: /* screen_definition_simple: ON  */
#line 782 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 3786 "src-generated/ugbc.tab.c"
    break;

  case 214: /* screen_definition_simple: OFF  */
#line 785 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 3794 "src-generated/ugbc.tab.c"
    break;

  case 215: /* screen_definition_simple: ROWS direct_integer  */
#line 788 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 3802 "src-generated/ugbc.tab.c"
    break;

  case 216: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 791 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3810 "src-generated/ugbc.tab.c"
    break;

  case 217: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 794 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3818 "src-generated/ugbc.tab.c"
    break;

  case 218: /* screen_definition_expression: ROWS expr  */
#line 799 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 3826 "src-generated/ugbc.tab.c"
    break;

  case 219: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 802 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3834 "src-generated/ugbc.tab.c"
    break;

  case 220: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 805 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3842 "src-generated/ugbc.tab.c"
    break;

  case 224: /* var_definition_simple: Identifier ON Identifier  */
#line 814 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 3850 "src-generated/ugbc.tab.c"
    break;

  case 225: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 817 "src/ugbc.y"
                                    {
      variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 3858 "src-generated/ugbc.tab.c"
    break;

  case 226: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 820 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 3866 "src-generated/ugbc.tab.c"
    break;

  case 227: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 823 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 3876 "src-generated/ugbc.tab.c"
    break;

  case 228: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 828 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 3886 "src-generated/ugbc.tab.c"
    break;

  case 229: /* goto_definition: Identifier  */
#line 835 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 3894 "src-generated/ugbc.tab.c"
    break;

  case 230: /* goto_definition: Integer  */
#line 838 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 3902 "src-generated/ugbc.tab.c"
    break;

  case 231: /* gosub_definition: Identifier  */
#line 844 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 3910 "src-generated/ugbc.tab.c"
    break;

  case 232: /* gosub_definition: Integer  */
#line 847 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 3918 "src-generated/ugbc.tab.c"
    break;

  case 234: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 856 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 3926 "src-generated/ugbc.tab.c"
    break;

  case 235: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 862 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 3934 "src-generated/ugbc.tab.c"
    break;

  case 238: /* on_goto_definition: Identifier  */
#line 871 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 3943 "src-generated/ugbc.tab.c"
    break;

  case 239: /* $@1: %empty  */
#line 875 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 3951 "src-generated/ugbc.tab.c"
    break;

  case 241: /* on_gosub_definition: Identifier  */
#line 880 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 3960 "src-generated/ugbc.tab.c"
    break;

  case 242: /* $@2: %empty  */
#line 884 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 3968 "src-generated/ugbc.tab.c"
    break;

  case 244: /* $@3: %empty  */
#line 889 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 3976 "src-generated/ugbc.tab.c"
    break;

  case 246: /* $@4: %empty  */
#line 892 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 3984 "src-generated/ugbc.tab.c"
    break;

  case 248: /* every_definition: expr TICKS GOSUB Identifier  */
#line 897 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 3992 "src-generated/ugbc.tab.c"
    break;

  case 249: /* every_definition: ON  */
#line 900 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4000 "src-generated/ugbc.tab.c"
    break;

  case 250: /* every_definition: OFF  */
#line 903 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4008 "src-generated/ugbc.tab.c"
    break;

  case 251: /* add_definition: Identifier COMMA expr  */
#line 908 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4016 "src-generated/ugbc.tab.c"
    break;

  case 252: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 911 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4024 "src-generated/ugbc.tab.c"
    break;

  case 268: /* statement: INC Identifier  */
#line 932 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 4032 "src-generated/ugbc.tab.c"
    break;

  case 269: /* statement: DEC Identifier  */
#line 935 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 4040 "src-generated/ugbc.tab.c"
    break;

  case 270: /* statement: RANDOMIZE  */
#line 938 "src/ugbc.y"
              {
      randomize( _environment );
  }
#line 4048 "src-generated/ugbc.tab.c"
    break;

  case 271: /* statement: IF expr THEN  */
#line 941 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4056 "src-generated/ugbc.tab.c"
    break;

  case 272: /* statement: ELSE  */
#line 944 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 4064 "src-generated/ugbc.tab.c"
    break;

  case 273: /* statement: ELSE IF expr THEN  */
#line 947 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4072 "src-generated/ugbc.tab.c"
    break;

  case 274: /* statement: ENDIF  */
#line 950 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 4080 "src-generated/ugbc.tab.c"
    break;

  case 275: /* statement: DO  */
#line 953 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 4088 "src-generated/ugbc.tab.c"
    break;

  case 276: /* statement: LOOP  */
#line 956 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 4096 "src-generated/ugbc.tab.c"
    break;

  case 277: /* $@5: %empty  */
#line 959 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 4104 "src-generated/ugbc.tab.c"
    break;

  case 278: /* statement: WHILE $@5 expr  */
#line 961 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 4112 "src-generated/ugbc.tab.c"
    break;

  case 279: /* statement: WEND  */
#line 964 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 4120 "src-generated/ugbc.tab.c"
    break;

  case 280: /* statement: REPEAT  */
#line 967 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 4128 "src-generated/ugbc.tab.c"
    break;

  case 281: /* statement: UNTIL expr  */
#line 970 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 4136 "src-generated/ugbc.tab.c"
    break;

  case 282: /* statement: EXIT  */
#line 973 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 4144 "src-generated/ugbc.tab.c"
    break;

  case 283: /* statement: EXIT IF expr  */
#line 976 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 4152 "src-generated/ugbc.tab.c"
    break;

  case 284: /* statement: EXIT Integer  */
#line 979 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4160 "src-generated/ugbc.tab.c"
    break;

  case 285: /* statement: EXIT direct_integer  */
#line 982 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4168 "src-generated/ugbc.tab.c"
    break;

  case 286: /* statement: EXIT IF expr COMMA Integer  */
#line 985 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4176 "src-generated/ugbc.tab.c"
    break;

  case 287: /* statement: EXIT IF expr COMMA direct_integer  */
#line 988 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4184 "src-generated/ugbc.tab.c"
    break;

  case 288: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 991 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4192 "src-generated/ugbc.tab.c"
    break;

  case 289: /* statement: NEXT  */
#line 994 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 4200 "src-generated/ugbc.tab.c"
    break;

  case 290: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 997 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4208 "src-generated/ugbc.tab.c"
    break;

  case 291: /* statement: BEG GAMELOOP  */
#line 1000 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 4216 "src-generated/ugbc.tab.c"
    break;

  case 292: /* statement: END GAMELOOP  */
#line 1003 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 4224 "src-generated/ugbc.tab.c"
    break;

  case 293: /* statement: GRAPHIC  */
#line 1006 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 4232 "src-generated/ugbc.tab.c"
    break;

  case 294: /* statement: HALT  */
#line 1009 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 4240 "src-generated/ugbc.tab.c"
    break;

  case 299: /* statement: RETURN  */
#line 1016 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 4248 "src-generated/ugbc.tab.c"
    break;

  case 300: /* statement: POP  */
#line 1019 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 4256 "src-generated/ugbc.tab.c"
    break;

  case 301: /* statement: DONE  */
#line 1022 "src/ugbc.y"
          {
      return 0;
  }
#line 4264 "src-generated/ugbc.tab.c"
    break;

  case 302: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1025 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4272 "src-generated/ugbc.tab.c"
    break;

  case 303: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1028 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4280 "src-generated/ugbc.tab.c"
    break;

  case 304: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1031 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 4288 "src-generated/ugbc.tab.c"
    break;

  case 305: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1034 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4296 "src-generated/ugbc.tab.c"
    break;

  case 306: /* statement: Identifier COLON  */
#line 1037 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 4304 "src-generated/ugbc.tab.c"
    break;

  case 307: /* statement: Identifier ASSIGN expr  */
#line 1040 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 4318 "src-generated/ugbc.tab.c"
    break;

  case 308: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1049 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 4332 "src-generated/ugbc.tab.c"
    break;

  case 309: /* statement: DEBUG expr  */
#line 1058 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 4340 "src-generated/ugbc.tab.c"
    break;

  case 312: /* statements_no_linenumbers: statement  */
#line 1066 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 4346 "src-generated/ugbc.tab.c"
    break;

  case 313: /* $@6: %empty  */
#line 1067 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 4352 "src-generated/ugbc.tab.c"
    break;

  case 315: /* $@7: %empty  */
#line 1071 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 4360 "src-generated/ugbc.tab.c"
    break;

  case 316: /* statements_with_linenumbers: Integer $@7 statements_no_linenumbers  */
#line 1073 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 4368 "src-generated/ugbc.tab.c"
    break;

  case 321: /* $@8: %empty  */
#line 1085 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 4374 "src-generated/ugbc.tab.c"
    break;


#line 4378 "src-generated/ugbc.tab.c"

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

#line 1087 "src/ugbc.y"


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

