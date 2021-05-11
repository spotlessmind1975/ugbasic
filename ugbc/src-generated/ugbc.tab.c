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
 
extern char DATATYPE_AS_STRING[][16];


#line 87 "src-generated/ugbc.tab.c"

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
  YYSYMBOL_DIM = 142,                      /* DIM  */
  YYSYMBOL_ADDRESS = 143,                  /* ADDRESS  */
  YYSYMBOL_PROC = 144,                     /* PROC  */
  YYSYMBOL_PROCEDURE = 145,                /* PROCEDURE  */
  YYSYMBOL_CALL = 146,                     /* CALL  */
  YYSYMBOL_MILLISECOND = 147,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 148,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 149,                    /* TICKS  */
  YYSYMBOL_BLACK = 150,                    /* BLACK  */
  YYSYMBOL_WHITE = 151,                    /* WHITE  */
  YYSYMBOL_RED = 152,                      /* RED  */
  YYSYMBOL_CYAN = 153,                     /* CYAN  */
  YYSYMBOL_VIOLET = 154,                   /* VIOLET  */
  YYSYMBOL_GREEN = 155,                    /* GREEN  */
  YYSYMBOL_BLUE = 156,                     /* BLUE  */
  YYSYMBOL_YELLOW = 157,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 158,                   /* ORANGE  */
  YYSYMBOL_BROWN = 159,                    /* BROWN  */
  YYSYMBOL_LIGHT = 160,                    /* LIGHT  */
  YYSYMBOL_DARK = 161,                     /* DARK  */
  YYSYMBOL_GREY = 162,                     /* GREY  */
  YYSYMBOL_GRAY = 163,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 164,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 165,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 166,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 167,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 168,                /* TURQUOISE  */
  YYSYMBOL_TAN = 169,                      /* TAN  */
  YYSYMBOL_PINK = 170,                     /* PINK  */
  YYSYMBOL_PEACH = 171,                    /* PEACH  */
  YYSYMBOL_OLIVE = 172,                    /* OLIVE  */
  YYSYMBOL_Identifier = 173,               /* Identifier  */
  YYSYMBOL_String = 174,                   /* String  */
  YYSYMBOL_Integer = 175,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 176,                 /* $accept  */
  YYSYMBOL_expr = 177,                     /* expr  */
  YYSYMBOL_expr_math = 178,                /* expr_math  */
  YYSYMBOL_term = 179,                     /* term  */
  YYSYMBOL_modula = 180,                   /* modula  */
  YYSYMBOL_factor = 181,                   /* factor  */
  YYSYMBOL_direct_integer = 182,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 183, /* random_definition_simple  */
  YYSYMBOL_random_definition = 184,        /* random_definition  */
  YYSYMBOL_color_enumeration = 185,        /* color_enumeration  */
  YYSYMBOL_exponential = 186,              /* exponential  */
  YYSYMBOL_187_1 = 187,                    /* $@1  */
  YYSYMBOL_188_2 = 188,                    /* $@2  */
  YYSYMBOL_position = 189,                 /* position  */
  YYSYMBOL_bank_definition_simple = 190,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 191, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 192,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 193, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 194, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 195,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 196, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 197, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 198,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 199,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 200, /* color_definition_expression  */
  YYSYMBOL_color_definition = 201,         /* color_definition  */
  YYSYMBOL_milliseconds = 202,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 203,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 204, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 205,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 206, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 207, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 208,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 209, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 210, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 211,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 212, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 213, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 214,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 215,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 216, /* text_definition_expression  */
  YYSYMBOL_text_definition = 217,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 218,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 219, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 220,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 221, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 222, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 223,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 224, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 225, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 226,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 227,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 228,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 229,         /* gosub_definition  */
  YYSYMBOL_var_definition = 230,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 231,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 232, /* point_definition_expression  */
  YYSYMBOL_point_definition = 233,         /* point_definition  */
  YYSYMBOL_ink_definition = 234,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 235,       /* on_goto_definition  */
  YYSYMBOL_236_3 = 236,                    /* $@3  */
  YYSYMBOL_on_gosub_definition = 237,      /* on_gosub_definition  */
  YYSYMBOL_238_4 = 238,                    /* $@4  */
  YYSYMBOL_on_proc_definition = 239,       /* on_proc_definition  */
  YYSYMBOL_240_5 = 240,                    /* $@5  */
  YYSYMBOL_on_definition = 241,            /* on_definition  */
  YYSYMBOL_242_6 = 242,                    /* $@6  */
  YYSYMBOL_243_7 = 243,                    /* $@7  */
  YYSYMBOL_244_8 = 244,                    /* $@8  */
  YYSYMBOL_every_definition = 245,         /* every_definition  */
  YYSYMBOL_add_definition = 246,           /* add_definition  */
  YYSYMBOL_dimensions = 247,               /* dimensions  */
  YYSYMBOL_datatype = 248,                 /* datatype  */
  YYSYMBOL_dim_definition = 249,           /* dim_definition  */
  YYSYMBOL_250_9 = 250,                    /* $@9  */
  YYSYMBOL_251_10 = 251,                   /* $@10  */
  YYSYMBOL_252_11 = 252,                   /* $@11  */
  YYSYMBOL_dim_definitions = 253,          /* dim_definitions  */
  YYSYMBOL_indexes = 254,                  /* indexes  */
  YYSYMBOL_statement = 255,                /* statement  */
  YYSYMBOL_256_12 = 256,                   /* $@12  */
  YYSYMBOL_257_13 = 257,                   /* $@13  */
  YYSYMBOL_258_14 = 258,                   /* $@14  */
  YYSYMBOL_259_15 = 259,                   /* $@15  */
  YYSYMBOL_statements_no_linenumbers = 260, /* statements_no_linenumbers  */
  YYSYMBOL_261_16 = 261,                   /* $@16  */
  YYSYMBOL_statements_with_linenumbers = 262, /* statements_with_linenumbers  */
  YYSYMBOL_263_17 = 263,                   /* $@17  */
  YYSYMBOL_statements_complex = 264,       /* statements_complex  */
  YYSYMBOL_265_18 = 265,                   /* $@18  */
  YYSYMBOL_program = 266,                  /* program  */
  YYSYMBOL_267_19 = 267                    /* $@19  */
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
#define YYLAST   2033

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  176
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  92
/* YYNRULES -- Number of rules.  */
#define YYNRULES  390
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  761

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   430


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
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    72,    72,    73,    77,    81,    84,    87,    90,    93,
      96,    99,   105,   106,   109,   116,   117,   121,   122,   126,
     133,   134,   138,   145,   150,   153,   156,   159,   162,   165,
     168,   173,   178,   182,   186,   190,   194,   198,   202,   206,
     210,   214,   218,   222,   226,   230,   234,   238,   242,   246,
     250,   254,   258,   262,   266,   270,   274,   278,   282,   288,
     288,   299,   299,   310,   313,   316,   325,   329,   336,   340,
     344,   348,   352,   356,   360,   364,   368,   371,   374,   377,
     380,   383,   386,   389,   392,   395,   398,   401,   404,   407,
     410,   413,   416,   419,   422,   425,   428,   431,   434,   437,
     440,   443,   446,   449,   452,   455,   458,   461,   464,   468,
     472,   476,   479,   482,   487,   487,   490,   493,   496,   499,
     502,   505,   509,   512,   515,   518,   522,   525,   528,   531,
     535,   538,   541,   544,   550,   553,   556,   559,   562,   567,
     568,   571,   574,   579,   582,   587,   588,   591,   594,   599,
     602,   607,   608,   611,   614,   617,   622,   625,   628,   633,
     634,   637,   638,   639,   642,   645,   648,   653,   656,   659,
     665,   666,   669,   672,   675,   678,   681,   684,   687,   690,
     693,   696,   699,   702,   705,   708,   711,   716,   719,   722,
     725,   728,   731,   734,   737,   740,   743,   746,   749,   752,
     755,   758,   763,   764,   767,   770,   773,   776,   779,   785,
     788,   794,   795,   798,   803,   808,   809,   812,   815,   820,
     823,   828,   829,   832,   837,   842,   843,   846,   849,   852,
     857,   860,   866,   867,   870,   873,   876,   879,   882,   887,
     890,   893,   898,   899,   901,   902,   905,   908,   911,   916,
     923,   926,   932,   935,   941,   944,   950,   955,   956,   959,
     964,   968,   968,   973,   977,   977,   982,   986,   986,   991,
     991,   994,   994,   997,   997,  1002,  1005,  1008,  1013,  1016,
    1022,  1026,  1033,  1036,  1039,  1042,  1045,  1048,  1051,  1054,
    1057,  1060,  1065,  1065,  1073,  1073,  1081,  1081,  1092,  1093,
    1097,  1101,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,
    1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,  1127,
    1130,  1133,  1136,  1139,  1142,  1145,  1148,  1151,  1154,  1154,
    1159,  1162,  1165,  1168,  1171,  1174,  1177,  1180,  1183,  1186,
    1189,  1192,  1195,  1198,  1201,  1204,  1207,  1210,  1213,  1216,
    1219,  1222,  1225,  1228,  1231,  1234,  1235,  1236,  1237,  1238,
    1241,  1244,  1247,  1250,  1253,  1256,  1259,  1260,  1269,  1278,
    1278,  1290,  1290,  1307,  1307,  1324,  1327,  1328,  1332,  1333,
    1333,  1337,  1337,  1344,  1344,  1347,  1348,  1349,  1350,  1354,
    1354
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
  "TIMER", "POWERING", "DIM", "ADDRESS", "PROC", "PROCEDURE", "CALL",
  "MILLISECOND", "MILLISECONDS", "TICKS", "BLACK", "WHITE", "RED", "CYAN",
  "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE", "BROWN", "LIGHT", "DARK",
  "GREY", "GRAY", "MAGENTA", "PURPLE", "LAVENDER", "GOLD", "TURQUOISE",
  "TAN", "PINK", "PEACH", "OLIVE", "Identifier", "String", "Integer",
  "$accept", "expr", "expr_math", "term", "modula", "factor",
  "direct_integer", "random_definition_simple", "random_definition",
  "color_enumeration", "exponential", "$@1", "$@2", "position",
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
  "on_goto_definition", "$@3", "on_gosub_definition", "$@4",
  "on_proc_definition", "$@5", "on_definition", "$@6", "$@7", "$@8",
  "every_definition", "add_definition", "dimensions", "datatype",
  "dim_definition", "$@9", "$@10", "$@11", "dim_definitions", "indexes",
  "statement", "$@12", "$@13", "$@14", "$@15", "statements_no_linenumbers",
  "$@16", "statements_with_linenumbers", "$@17", "statements_complex",
  "$@18", "program", "$@19", YY_NULLPTR
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
     425,   426,   427,   428,   429,   430
};
#endif

#define YYPACT_NINF (-579)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-370)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -579,    62,   725,  -579,  -579,   -55,   -50,   -19,  -579,    46,
    1396,    98,   -12,  1396,  -579,    17,   198,  1550,   -44,  -106,
    -579,  -579,  -579,  1088,   109,    24,  1550,    35,   -52,  -579,
     128,   134,  1550,  1550,  -579,   113,   119,   -90,  -579,    31,
     114,  -579,   -39,  -579,  1550,    16,  1242,   159,    39,  1550,
      47,    52,    54,    57,    22,  -579,   196,   212,   235,  -579,
    -579,  -579,  1396,   230,  -579,  -579,  -579,  1396,  1396,  1396,
    -579,  -579,  -579,    83,   934,  -579,  -579,   223,   225,   232,
     116,    92,  -579,  -579,   234,   236,  1550,  -579,  -579,   259,
     261,   262,   263,   273,   274,   275,   276,   278,   279,   280,
     281,   282,   283,   284,   285,   286,  -579,  -579,   287,  -579,
    -579,  -579,  -579,  -579,  -579,  -579,   167,  -579,  -579,    51,
     -53,  -579,  -579,  -579,  -579,  -579,  -579,  -579,  -579,  -579,
     168,    29,  -579,  -579,   -48,    79,   139,    87,   195,   -34,
    -579,  -579,  -579,  -579,  -579,   -18,   243,   -13,    -9,    -7,
      -6,   302,  -579,  -579,  -579,   172,   199,  -579,  -579,  -579,
    1396,  -579,  -579,   299,  -579,  -579,  -579,  -579,  -579,  1396,
     288,   289,  -579,  -579,  -579,   -32,  -579,    82,  -579,  -579,
    -579,  -579,  -579,  1550,  1550,  -579,  -579,   322,  -579,  -579,
    -579,  1396,  -579,  -579,  -579,  1396,   301,  -579,  -579,  -579,
     264,  -579,  -579,  -579,  1550,  1550,  -579,  -579,  1396,  -579,
    -579,  -579,   297,  -579,  -579,  -579,  -579,  -579,  -579,  -579,
    1550,  1550,  -579,  -579,  -579,  -579,   319,  -579,  -579,   187,
    -579,  1550,   330,  -579,  -579,  -579,    -1,   331,  -579,  -579,
    -579,  -579,  -579,  -579,  1550,   326,  -579,   306,     5,   850,
    -579,   725,   725,   312,   313,  1396,  -579,  -579,   272,   277,
     290,   291,  -579,   310,   311,   315,   316,   317,    64,   318,
    1396,  1396,  1396,  -579,  -579,  -579,  -579,  -579,  -579,  -579,
    -579,  -579,  -579,  1550,  1550,  -579,  1550,  1550,  1550,  1550,
    1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,  1550,
    1550,  1550,  1550,  1704,  -579,  -579,  -579,  -579,  -579,  -579,
    -579,  -579,   314,   320,  -579,  -579,  -579,  -579,  -579,  -579,
    1704,  1704,  1704,  1704,  1704,  1704,  1704,  1704,  1704,  1704,
    1704,  1704,  1704,  1858,  -579,  -579,  -579,  1396,   323,  -579,
    -579,  -579,   307,   243,   332,   243,   333,   243,   335,   243,
     336,   243,  -579,  1550,   328,  -579,  -579,   101,   123,     6,
      76,  -579,  -579,  -579,   342,   243,   334,  -579,  -579,   131,
     162,    90,   102,  -579,  -579,   343,  -579,  -579,  1396,  -579,
    -579,  1396,  1396,  -579,  -579,  -579,   324,   191,  -579,   358,
    1550,  -579,  -579,  -579,  -579,  1396,  -579,   362,   363,  -579,
    -579,  1396,   309,   372,  1550,   293,   374,  1550,  -579,  -579,
    -579,  -579,  -579,  -579,    78,  -579,  -579,   348,   364,    47,
     725,  -579,  1550,   349,  1550,   352,    27,  -579,   850,  -579,
    -579,   214,   215,  -579,  -579,  1550,   243,  1550,   243,   217,
     218,   221,   226,   227,   354,   355,   365,  -579,   368,   369,
     370,   371,   373,   375,   391,   392,   400,   402,   376,   378,
     379,   380,   409,   382,   383,   384,   385,   386,   415,   416,
     389,   393,   394,     3,   396,  1550,   139,   139,   224,   224,
     224,   224,   224,   224,   224,   224,    87,   195,   195,  -579,
     397,   403,  1396,   137,  -579,   243,  -579,   243,  -579,   243,
    -579,   243,    -4,  -579,  1550,  -579,  -579,  -579,  -579,  -579,
    -579,  -579,  -579,  1550,  -579,   243,  -579,  -579,  -579,  -579,
    -579,  -579,  -579,  -579,   243,  -579,  -579,  -579,  -579,  -579,
    -579,   258,   260,   265,   266,   421,  1550,   428,   395,   399,
    1550,  1550,   429,   435,  -579,   -68,   377,   270,  1550,   437,
    -579,  -579,  -579,   411,   292,   413,  -579,  -579,  -579,  1550,
     444,   418,  1550,  -579,  -579,  -579,  -579,  -579,  -579,  -579,
    -579,  -579,  -579,  -579,  -579,   294,   295,   296,  -579,  -579,
    -579,  -579,  -579,  -579,  1550,  1550,  1550,  1550,  -579,  -579,
    -579,  -579,  1550,  -579,  -579,  -579,  -579,  -579,  1550,  1550,
    -579,  -579,  -579,  1858,  1550,   420,   300,   303,  -579,  -579,
    -579,  -579,  -579,  -579,   427,  -579,   430,  -579,   298,   173,
    -579,   450,  -579,   451,   453,  -579,   454,  -579,   455,  -579,
     452,  1396,   456,  1550,  1550,   243,   431,   439,  1550,   243,
    -579,  -579,  1550,  -579,    20,  1550,   292,   457,   440,   292,
     442,  1550,   465,   445,  -579,  -579,  -579,   448,   458,    43,
      75,   460,   461,   462,   464,   466,  -579,  -579,  -579,   305,
     337,  -579,   459,  -579,   463,  -579,  1550,   243,   479,   480,
     482,  1550,  -579,  -579,  1550,  -579,  -579,  -579,   477,   478,
     467,   470,   398,  1550,   487,   434,   472,   292,  -579,   473,
     496,  -579,  1550,   497,  -579,  -579,  1550,  -579,  1550,  -579,
    -579,  -579,  -579,  -579,  -579,  -579,  -579,   338,   340,   481,
     483,   258,   260,   265,  -579,  -579,  1550,  1550,  -579,  -579,
    1550,   484,  1550,  1550,  -579,  -579,  -579,  1550,  -579,  1550,
     485,   486,  -579,  -579,  -579,  -579,  -579,  -579,  -579,  -579,
    -579,  -579,   502,  -579,  -579,  -579,  -579,  -579,  -579,  1550,
    -579
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     389,     0,   377,     1,   376,     0,     0,     0,   361,     0,
       0,   342,     0,     0,   353,     0,     0,     0,   244,     0,
     327,   331,   328,     0,     0,     0,     0,     0,   354,   325,
       0,     0,     0,   320,   352,     0,     0,     0,   359,   360,
     323,   326,   333,   330,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   373,   381,   378,   385,   387,   390,
     318,   319,     0,     0,   145,   146,   303,     0,     0,     0,
     159,   160,   305,     0,     0,    79,    80,     0,     0,     0,
       0,     0,   111,   112,     0,     0,     0,   108,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   113,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,    44,    49,    50,    51,    52,    53,    54,    57,    58,
       0,    63,    67,    65,     0,     2,    12,    15,    17,     0,
      76,    20,   170,   171,   306,     0,     0,     0,     0,     0,
       0,     0,   139,   140,   302,     0,     0,   202,   203,   307,
       0,   205,   206,   207,   211,   212,   308,   234,   235,     0,
       0,     0,   242,   243,   313,     0,   355,     0,   254,   316,
     250,   251,   356,     0,     0,   217,   218,     0,   221,   222,
     310,     0,   225,   226,   311,     0,   228,   232,   233,   312,
       0,   350,   351,   344,     0,     0,   375,   321,     0,   215,
     216,   309,     0,   257,   258,   314,   252,   253,   357,   335,
       0,     0,   334,   337,   338,   332,     0,   276,   277,     0,
     358,     0,     0,   317,   259,   315,   292,   298,   366,   347,
     343,   348,   383,   349,     0,   371,   346,     0,     0,   377,
     379,   377,   377,     0,     0,     0,   156,   153,     0,     0,
       0,     0,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,    24,    25,    27,    29,    30,    26,
      31,   101,    23,     0,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    42,    45,    46,    47,    48,
      43,    56,    64,     0,   161,   167,   162,   163,   168,   169,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   164,   165,   166,     0,     0,   151,
     152,   304,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,     0,     0,   192,   193,     0,     0,     0,
       0,   189,   188,   114,     0,     0,     0,   177,   178,     0,
       0,     0,     0,   174,   173,     0,   209,   204,     0,   239,
     236,     0,     0,   269,   273,   271,     0,     0,   329,     0,
       0,   224,   223,   230,   227,     0,   322,     0,     0,   214,
     213,     0,     0,   336,     0,     0,     0,     0,   290,   282,
     284,   289,   286,   291,     0,   288,   296,     0,     0,     0,
     377,   367,     0,     0,     0,     0,   373,   382,   377,   386,
     388,     0,     0,   143,   141,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,     5,     7,
       8,     9,    10,     6,     3,     4,    16,    18,    19,    21,
       0,     0,     0,     0,   121,     0,   133,     0,   125,     0,
     129,     0,   117,   190,     0,   197,   196,   201,   200,   195,
     199,   194,   198,     0,   175,     0,   182,   181,   186,   185,
     180,   184,   179,   183,     0,   210,   208,   240,   237,   241,
     238,     0,     0,     0,     0,   245,     0,     0,     0,     0,
       0,     0,     0,     0,   324,     0,     0,     0,     0,   278,
     283,   285,   287,     0,     0,     0,   299,   384,   368,     0,
     300,     0,     0,   380,   144,   142,   158,   155,   157,   154,
      75,    68,    70,    74,    72,     0,     0,     0,    78,    77,
      82,    81,    84,    83,     0,     0,     0,     0,    91,    92,
      93,   100,     0,    94,    95,    96,    97,    98,     0,     0,
     106,   107,   102,     0,     0,     0,     0,     0,   149,   147,
     118,   131,   123,   126,   120,   132,   124,   128,     0,     0,
     187,     0,   172,     0,   260,   270,   263,   274,   266,   272,
     246,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     339,   340,     0,   275,     0,     0,     0,   280,     0,     0,
       0,     0,     0,     0,    69,    71,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,   150,   148,     0,
       0,   134,   119,   130,   122,   127,     0,     0,     0,     0,
       0,     0,   248,   247,     0,   220,   231,   229,     0,     0,
       0,     0,   341,     0,     0,     0,     0,     0,   293,     0,
       0,   301,     0,     0,    85,    86,     0,    87,     0,    89,
      99,   105,   104,    22,    62,   136,   138,     0,     0,     0,
       0,     0,     0,     0,   249,   219,     0,     0,   256,   255,
       0,     0,     0,     0,   297,   281,   295,     0,   370,     0,
       0,     0,   135,   137,   191,   176,   262,   265,   268,   362,
     363,   345,     0,   364,   279,   372,   374,    88,    90,     0,
     365
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -579,   -10,   -23,   -74,   192,  -205,   103,  -579,  -579,  -579,
    -332,  -579,  -579,   361,  -579,  -579,  -579,  -579,  -579,  -579,
    -579,  -579,  -579,  -579,  -579,  -579,   388,  -579,  -579,  -579,
    -579,  -579,  -579,  -579,  -579,  -579,  -579,  -579,  -579,  -579,
    -579,  -579,  -579,  -579,  -579,  -579,  -579,  -579,  -579,  -579,
    -579,  -579,  -579,  -579,  -579,  -579,  -579,  -579,  -579,  -198,
    -579,  -197,  -579,  -199,  -579,  -579,  -579,  -579,  -579,  -579,
    -579,  -578,   304,  -579,  -579,  -579,  -579,   110,  -473,  -579,
    -579,  -579,  -579,  -579,  -245,  -579,  -579,  -579,  -243,  -579,
    -579,  -579
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   560,   135,   136,   137,   138,   139,   280,   281,   140,
     141,   313,   474,   364,   152,   153,   154,    64,    65,    66,
     339,   340,   341,    70,    71,    72,   319,   142,   143,   144,
     157,   158,   159,   164,   165,   166,   209,   210,   211,   188,
     189,   190,   192,   193,   194,   197,   198,   199,   172,   173,
     174,   178,   182,   218,   179,   213,   214,   215,   235,   625,
     678,   627,   679,   629,   680,   176,   531,   533,   532,   230,
     233,   648,   416,   237,   417,   418,   553,   238,   561,    56,
     183,   247,   423,   248,    57,   428,    58,   249,    59,   420,
       1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     134,   489,   605,   155,   427,    62,   337,   175,   429,   430,
     603,   343,   146,   187,    81,   345,   200,   347,   349,  -294,
     147,   383,   206,   207,   408,   618,   242,   693,   243,   221,
     408,   314,   315,   243,   225,   244,   229,   148,   202,   234,
     244,   160,   245,    81,   619,   314,   334,   245,   195,   312,
     706,   509,   253,   161,   162,   694,  -369,   256,   258,   260,
     510,  -369,     3,   -59,   269,   149,   150,   180,   696,   181,
     384,   699,    67,   409,   410,   411,   285,    68,   707,   409,
     410,   411,   708,   216,   412,   217,   650,   320,   321,   653,
     412,   322,   203,   323,   324,   325,   326,   327,   473,   316,
     317,   318,   386,   309,   163,   222,   331,   640,   332,   310,
     709,   196,   385,   316,   317,   335,   156,    69,    60,   735,
     145,   511,   413,    61,   387,   201,   487,   488,   413,   177,
     512,   665,   333,   191,   414,   520,   223,   208,   444,   445,
     414,   273,   415,   212,   521,   224,   246,   522,   415,   446,
     376,   246,   550,   551,    63,   338,   523,   505,   506,   379,
     344,   151,   204,   552,   346,   254,   348,   350,   205,   610,
     257,   259,   261,   388,   389,   219,   328,   557,   701,   507,
     508,   391,   220,   563,   329,   393,   611,   516,   517,   226,
     274,   275,   276,   231,   397,   398,   352,   353,   399,   277,
     278,   279,   250,   305,   354,   672,   306,   307,   355,   356,
     402,   403,   232,   308,   612,   613,   251,   357,   518,   519,
     236,   406,   673,   352,   365,   239,   358,   240,   359,   360,
     241,   366,   320,   321,   421,   367,   368,   361,   362,   252,
     167,   168,   169,   170,   369,   433,   476,   477,   363,   342,
     674,   675,   171,   370,   255,   371,   372,   270,   262,   271,
     448,   450,   452,   377,   373,   374,   272,   282,   283,   330,
     284,   664,   380,   454,   455,   363,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   286,   392,   287,   288,   289,   394,   478,
     479,   480,   481,   482,   483,   484,   485,   290,   291,   292,
     293,   400,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   311,   333,    81,   351,   490,   378,   390,
     395,   401,   404,   396,   381,   382,   405,   407,   419,   422,
     424,   431,   432,   503,   435,   439,   440,   492,   -61,   436,
     441,   442,   443,   447,   475,   493,   495,   497,   434,   499,
     501,   504,   437,   438,   535,   536,   534,   515,   525,   540,
     541,   527,   529,   449,   451,   453,   513,   524,   544,   545,
     537,   548,   554,   559,   555,   538,   562,   564,   565,   575,
     576,   542,   570,   571,   546,   547,   572,   549,   584,   585,
     577,   573,   574,   578,   579,   580,   581,   586,   582,   587,
     583,   588,   558,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   566,   606,   568,   601,   602,
     604,   624,   607,   626,   631,   633,   638,   634,   628,   630,
     491,   635,   639,   643,   645,   646,   494,   649,   496,   642,
     498,   651,   500,   652,   502,   666,   669,   676,   677,   670,
    -261,  -264,  -267,   684,   697,   681,   688,   647,   514,   654,
     655,   656,   671,   667,   689,   698,   668,   700,   702,   715,
     703,   526,   608,   704,   528,   530,   721,   722,   717,   723,
     726,   727,   718,   705,   620,   710,   711,   712,   539,   713,
     732,   714,   728,   621,   543,   729,   733,   734,   736,   737,
     739,   716,   742,   730,   743,   759,   744,   375,   745,   752,
     757,   758,   486,   746,   748,   747,   632,   336,     0,   556,
     636,   637,     0,     0,     0,     0,     0,     0,   644,   567,
       0,   569,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   425,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   657,   658,   659,   660,     0,     0,
       0,     0,   661,     0,     0,     0,     0,     0,   662,   663,
       0,     0,     0,     0,     0,   609,     0,     0,   614,     0,
     615,     0,   616,     0,   617,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   622,     0,
       0,   682,     0,   685,   686,     0,     0,   623,   690,     0,
       0,     0,   692,     0,     0,   695,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   641,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   719,     0,     0,     0,
       0,   724,     0,     0,   725,     0,     0,     0,     0,     0,
       0,     0,     0,   731,     0,     0,     0,     0,     0,     0,
       0,     0,   738,     0,     0,     0,   740,     0,   741,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   749,   750,     0,     0,
     751,     0,   753,   754,     0,     0,     0,   755,     4,   756,
       0,     0,     0,     0,   683,     5,     6,     0,   687,     0,
       0,     0,   691,     0,     0,     0,     0,     7,     8,   760,
       9,     0,    10,    11,     0,    12,    13,     0,     0,     0,
       0,     0,     0,    14,     0,    15,    16,    17,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    19,     0,
     720,     0,     0,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    28,     0,    29,     0,     0,    30,
      31,    32,     0,    33,    34,    35,    36,    37,    38,    39,
       0,    40,     0,     0,     0,    41,    42,    43,    44,    45,
       0,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     0,     0,    48,     0,     0,     0,
       5,     6,     0,     0,    49,     0,     0,    50,     0,    51,
      52,    53,     7,     8,     0,     9,     0,    10,    11,     0,
      12,    13,     0,     0,     0,     0,     0,     0,    14,     0,
      15,    16,    17,     0,     0,     0,     0,    18,    54,     0,
      55,     0,     0,    19,     0,     0,     0,     0,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
       0,    29,     0,    73,    30,    31,    32,     0,    33,    34,
      35,    36,    37,    38,    39,     0,    40,     0,     0,   263,
      41,    42,    43,    44,    45,     0,    46,    47,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,    75,    76,    77,     0,     0,    49,
       0,     0,    50,     0,    51,    52,    53,     0,     0,     0,
       0,    78,     0,     0,    79,     0,     0,    80,   264,   265,
     266,     0,     0,     0,     0,     0,     0,    82,    83,   267,
       0,     0,     0,   426,     0,     0,     0,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,     0,     0,     0,     0,     0,     0,
       0,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,     0,     0,   101,   102,   103,   268,
     104,   105,   106,     0,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    73,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
       0,     0,   184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,   185,   186,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    75,    76,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,    79,     0,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     0,     0,     0,
     101,   102,   103,     0,   104,   105,   106,     0,   107,   108,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    73,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,     0,     0,     0,
       0,     0,     0,     0,   227,   228,     0,     0,     0,     0,
       0,     0,    75,    76,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,    79,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,     0,     0,     0,     0,     0,     0,     0,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     0,     0,     0,   101,   102,   103,     0,   104,   105,
     106,     0,   107,   108,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    73,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,    76,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,    79,     0,     0,    80,
       0,     0,     0,     0,     0,     0,     0,     0,    81,    82,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,     0,     0,   101,   102,
     103,     0,   104,   105,   106,     0,   107,   108,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    73,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,    76,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
      79,     0,     0,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
       0,     0,     0,     0,     0,     0,     0,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,     0,
       0,     0,   101,   102,   103,     0,   104,   105,   106,     0,
     107,   108,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    73,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,    79,     0,     0,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,    88,     0,     0,     0,     0,     0,     0,
       0,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,     0,     0,   101,   102,   103,     0,
     104,   105,   106,     0,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    73,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    75,    76,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,    79,     0,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    88,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     0,     0,     0,
     101,   102,   103,     0,   104,   105,   106,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133
};

static const yytype_int16 yycheck[] =
{
      10,   333,   475,    13,   249,    24,    24,    17,   251,   252,
       7,    24,    24,    23,    82,    24,    26,    24,    24,    20,
      32,    53,    32,    33,    25,    29,     4,     7,     6,    68,
      25,    79,    80,     6,    44,    13,    46,    49,    90,    49,
      13,    24,    20,    82,    48,    79,    80,    20,    24,    20,
       7,    45,    62,    36,    37,    35,    34,    67,    68,    69,
      54,    34,     0,    34,    74,    77,    78,   173,   646,   175,
     102,   649,    26,    74,    75,    76,    86,    31,    35,    74,
      75,    76,     7,   173,    85,   175,   559,     8,     9,   562,
      85,    12,   144,    14,    15,    16,    17,    18,   303,   147,
     148,   149,    20,   156,    87,   144,    19,   175,    21,   162,
      35,    87,   144,   147,   148,   149,    13,    71,   173,   697,
      22,    45,   123,   173,    42,    90,   331,   332,   123,   173,
      54,   604,   129,    24,   135,    45,   175,    24,    74,    75,
     135,    25,   143,    24,    54,    42,   124,    45,   143,    85,
     160,   124,    74,    75,   173,   173,    54,    56,    57,   169,
     173,   173,    34,    85,   173,    62,   173,   173,    34,    32,
      67,    68,    69,   183,   184,   144,    97,   420,   651,    56,
      57,   191,    68,   428,   105,   195,    49,    56,    57,   173,
      74,    75,    76,    34,   204,   205,    24,    25,   208,    83,
      84,    85,     6,   152,    32,    32,   155,   156,    36,    37,
     220,   221,   173,   162,    77,    78,     4,    45,    56,    57,
     173,   231,    49,    24,    25,   173,    54,   173,    56,    57,
     173,    32,     8,     9,   244,    36,    37,    65,    66,     4,
      42,    43,    44,    45,    45,   255,   320,   321,    76,   146,
      77,    78,    54,    54,    24,    56,    57,    34,   175,    34,
     270,   271,   272,   160,    65,    66,    34,   175,    34,   130,
      34,   603,   169,   283,   284,    76,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,    34,   191,    34,    34,    34,   195,   322,
     323,   324,   325,   326,   327,   328,   329,    34,    34,    34,
      34,   208,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,   155,   155,   129,    82,    24,   337,    29,     7,
      29,    34,    13,    69,    46,    46,   149,     7,     7,    13,
      34,    29,    29,   353,    72,    35,    35,    24,    34,    72,
      35,    35,    35,    35,    34,    48,    24,    24,   255,    24,
      24,    33,    72,    72,   173,     7,    42,    33,   378,     7,
       7,   381,   382,   270,   271,   272,    34,    34,    69,     7,
     390,     7,    34,    34,    20,   395,    34,   173,   173,    35,
      35,   401,   175,   175,   404,   102,   175,   407,     7,     7,
      35,   175,   175,    35,    35,    35,    35,     7,    35,     7,
      35,    35,   422,    35,    35,    35,     7,    35,    35,    35,
      35,    35,     7,     7,    35,   435,    29,   437,    35,    35,
      34,   173,    29,   173,    13,     7,     7,    42,   173,   173,
     337,    42,     7,   173,     7,    34,   343,    34,   345,    72,
     347,     7,   349,    35,   351,    35,    29,     7,     7,    29,
       7,     7,     7,     7,     7,    13,    35,   175,   365,   175,
     175,   175,   174,   173,    35,    35,   173,    35,    13,   174,
      35,   378,   492,    35,   381,   382,     7,     7,    29,     7,
      13,    13,    29,    35,   504,    35,    35,    35,   395,    35,
      13,    35,    35,   513,   401,    35,    72,    35,    35,    13,
      13,   174,   174,   115,   174,    13,    35,   156,    35,    35,
      35,    35,   330,   721,   723,   722,   536,   139,    -1,   419,
     540,   541,    -1,    -1,    -1,    -1,    -1,    -1,   548,   436,
      -1,   438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   584,   585,   586,   587,    -1,    -1,
      -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,   598,   599,
      -1,    -1,    -1,    -1,    -1,   492,    -1,    -1,   495,    -1,
     497,    -1,   499,    -1,   501,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   515,    -1,
      -1,   631,    -1,   633,   634,    -1,    -1,   524,   638,    -1,
      -1,    -1,   642,    -1,    -1,   645,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   545,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   676,    -1,    -1,    -1,
      -1,   681,    -1,    -1,   684,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   693,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   702,    -1,    -1,    -1,   706,    -1,   708,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   726,   727,    -1,    -1,
     730,    -1,   732,   733,    -1,    -1,    -1,   737,     3,   739,
      -1,    -1,    -1,    -1,   631,    10,    11,    -1,   635,    -1,
      -1,    -1,   639,    -1,    -1,    -1,    -1,    22,    23,   759,
      25,    -1,    27,    28,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    42,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,
     677,    -1,    -1,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    91,    -1,    -1,    94,
      95,    96,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
      -1,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,   131,    -1,    -1,    -1,
      10,    11,    -1,    -1,   139,    -1,    -1,   142,    -1,   144,
     145,   146,    22,    23,    -1,    25,    -1,    27,    28,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      40,    41,    42,    -1,    -1,    -1,    -1,    47,   173,    -1,
     175,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      -1,    91,    -1,     9,    94,    95,    96,    -1,    98,    99,
     100,   101,   102,   103,   104,    -1,   106,    -1,    -1,    25,
     110,   111,   112,   113,   114,    -1,   116,   117,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    50,    51,    52,    -1,    -1,   139,
      -1,    -1,   142,    -1,   144,   145,   146,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    70,    -1,    -1,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,   173,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,   132,   133,   134,   135,
     136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     9,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,   137,   138,    -1,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     9,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,
     138,    -1,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     9,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,   132,   133,
     134,    -1,   136,   137,   138,    -1,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,     9,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,     9,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,
     136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     9,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   266,   267,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    88,    89,    91,
      94,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     106,   110,   111,   112,   113,   114,   116,   117,   131,   139,
     142,   144,   145,   146,   173,   175,   255,   260,   262,   264,
     173,   173,    24,   173,   193,   194,   195,    26,    31,    71,
     199,   200,   201,     9,    34,    50,    51,    52,    67,    70,
      73,    82,    83,    84,    94,    95,   107,   108,   109,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   132,   133,   134,   136,   137,   138,   140,   141,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   177,   178,   179,   180,   181,   182,
     185,   186,   203,   204,   205,    22,    24,    32,    49,    77,
      78,   173,   190,   191,   192,   177,   182,   206,   207,   208,
      24,    36,    37,    87,   209,   210,   211,    42,    43,    44,
      45,    54,   224,   225,   226,   177,   241,   173,   227,   230,
     173,   175,   228,   256,    24,    36,    37,   177,   215,   216,
     217,    24,   218,   219,   220,    24,    87,   221,   222,   223,
     177,    90,    90,   144,    34,    34,   177,   177,    24,   212,
     213,   214,    24,   231,   232,   233,   173,   175,   229,   144,
      68,    68,   144,   175,   182,   177,   173,    42,    43,   177,
     245,    34,   173,   246,   177,   234,   173,   249,   253,   173,
     173,   173,     4,     6,    13,    20,   124,   257,   259,   263,
       6,     4,     4,   177,   182,    24,   177,   182,   177,   182,
     177,   182,   175,    25,    74,    75,    76,    85,   135,   177,
      34,    34,    34,    25,    74,    75,    76,    83,    84,    85,
     183,   184,   175,    34,    34,   177,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,   155,   152,   155,   156,   162,   156,
     162,   155,    20,   187,    79,    80,   147,   148,   149,   202,
       8,     9,    12,    14,    15,    16,    17,    18,    97,   105,
     130,    19,    21,   129,    80,   149,   202,    24,   173,   196,
     197,   198,   182,    24,   173,    24,   173,    24,   173,    24,
     173,    24,    24,    25,    32,    36,    37,    45,    54,    56,
      57,    65,    66,    76,   189,    25,    32,    36,    37,    45,
      54,    56,    57,    65,    66,   189,   177,   182,    29,   177,
     182,    46,    46,    53,   102,   144,    20,    42,   177,   177,
       7,   177,   182,   177,   182,    29,    69,   177,   177,   177,
     182,    34,   177,   177,    13,   149,   177,     7,    25,    74,
      75,    76,    85,   123,   135,   143,   248,   250,   251,     7,
     265,   177,    13,   258,    34,   248,   173,   260,   261,   264,
     264,    29,    29,   177,   182,    72,    72,    72,    72,    35,
      35,    35,    35,    35,    74,    75,    85,    35,   177,   182,
     177,   182,   177,   182,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   181,   188,    34,   179,   179,   178,   178,
     178,   178,   178,   178,   178,   178,   180,   181,   181,   186,
     177,   182,    24,    48,   182,    24,   182,    24,   182,    24,
     182,    24,   182,   177,    33,    56,    57,    56,    57,    45,
      54,    45,    54,    34,   182,    33,    56,    57,    56,    57,
      45,    54,    45,    54,    34,   177,   182,   177,   182,   177,
     182,   242,   244,   243,    42,   173,     7,   177,   177,   182,
       7,     7,   177,   182,    69,     7,   177,   102,     7,   177,
      74,    75,    85,   252,    34,    20,   253,   264,   177,    34,
     177,   254,    34,   260,   173,   173,   177,   182,   177,   182,
     175,   175,   175,   175,   175,    35,    35,    35,    35,    35,
      35,    35,    35,    35,     7,     7,     7,     7,    35,    35,
      35,    35,     7,    35,    35,    35,    35,    35,     7,     7,
      35,    35,    35,     7,    34,   254,    29,    29,   177,   182,
      32,    49,    77,    78,   182,   182,   182,   182,    29,    48,
     177,   177,   182,   182,   173,   235,   173,   237,   173,   239,
     173,    13,   177,     7,    42,    42,   177,   177,     7,     7,
     175,   182,    72,   173,   177,     7,    34,   175,   247,    34,
     254,     7,    35,   254,   175,   175,   175,   177,   177,   177,
     177,   177,   177,   177,   186,   254,    35,   173,   173,    29,
      29,   174,    32,    49,    77,    78,     7,     7,   236,   238,
     240,    13,   177,   182,     7,   177,   177,   182,    35,    35,
     177,   182,   177,     7,    35,   177,   247,     7,    35,   247,
      35,   254,    13,    35,    35,    35,     7,    35,     7,    35,
      35,    35,    35,    35,    35,   174,   174,    29,    29,   177,
     182,     7,     7,     7,   177,   177,    13,    13,    35,    35,
     115,   177,    13,    72,    35,   247,    35,    13,   177,    13,
     177,   177,   174,   174,    35,    35,   235,   237,   239,   177,
     177,   177,    35,   177,   177,   177,   177,    35,    35,    13,
     177
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   176,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   178,   178,   178,   179,   179,   180,   180,   180,
     181,   181,   181,   182,   183,   183,   183,   183,   183,   183,
     183,   184,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   187,
     186,   188,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   189,   189,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   191,   191,   191,   191,   191,   192,
     192,   193,   193,   194,   194,   195,   195,   196,   196,   197,
     197,   198,   198,   199,   199,   199,   200,   200,   200,   201,
     201,   202,   202,   202,   203,   203,   203,   204,   204,   204,
     205,   205,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   208,   208,   209,   209,   209,   209,   209,   210,
     210,   211,   211,   212,   213,   214,   214,   215,   215,   216,
     216,   217,   217,   218,   219,   220,   220,   221,   221,   221,
     222,   222,   223,   223,   224,   224,   224,   224,   224,   225,
     225,   225,   226,   226,   227,   227,   227,   227,   227,   227,
     228,   228,   229,   229,   230,   231,   232,   233,   233,   234,
     235,   236,   235,   237,   238,   237,   239,   240,   239,   242,
     241,   243,   241,   244,   241,   245,   245,   245,   246,   246,
     247,   247,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   250,   249,   251,   249,   252,   249,   253,   253,
     254,   254,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   256,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   257,
     255,   258,   255,   259,   255,   255,   255,   255,   260,   261,
     260,   263,   262,   265,   264,   264,   264,   264,   264,   267,
     266
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     3,     3,     1,     3,     1,     3,     3,
       1,     3,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     0,
       5,     0,     6,     1,     2,     1,     2,     1,     4,     5,
       4,     5,     4,     5,     4,     4,     1,     4,     4,     1,
       1,     4,     4,     4,     4,     6,     6,     6,     8,     6,
       8,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     2,     4,     3,     6,     6,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     5,
       4,     3,     5,     4,     4,     3,     4,     5,     4,     3,
       5,     4,     4,     3,     5,     7,     6,     7,     6,     1,
       1,     3,     4,     3,     4,     1,     1,     3,     4,     3,
       4,     1,     1,     2,     4,     4,     2,     4,     4,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     2,
       1,     1,     4,     2,     2,     3,     7,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     2,     2,
       3,     7,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     2,     1,     1,     1,     3,     2,
       3,     1,     1,     2,     2,     1,     1,     1,     1,     6,
       5,     1,     1,     2,     2,     1,     1,     2,     1,     5,
       2,     5,     1,     1,     1,     1,     2,     3,     3,     2,
       3,     3,     1,     1,     0,     3,     4,     5,     5,     6,
       1,     1,     1,     1,     1,     6,     6,     1,     1,     1,
       1,     0,     4,     1,     0,     4,     1,     0,     4,     0,
       4,     0,     4,     0,     4,     4,     1,     1,     3,     7,
       1,     3,     1,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     0,     5,     0,     6,     0,     6,     1,     3,
       1,     3,     2,     2,     3,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     3,     1,     4,     1,     1,     1,     0,     3,
       1,     1,     2,     1,     2,     2,     3,     2,     2,     5,
       5,     6,     1,     2,     2,     8,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     8,     8,     8,    10,     2,     3,     4,     0,
       7,     0,     8,     0,     8,     2,     1,     0,     1,     0,
       4,     0,     3,     0,     4,     1,     3,     1,     3,     0,
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
#line 73 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2552 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 77 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2561 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 81 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2569 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 84 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2577 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 87 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2585 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 90 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2593 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 93 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2601 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 96 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2609 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 99 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2617 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 106 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2625 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 109 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2634 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 122 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2643 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 126 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2652 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 134 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2661 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 138 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 2670 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 145 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2678 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 150 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2686 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 153 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2694 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 156 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2702 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 159 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2710 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 162 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2718 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 165 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2726 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 168 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2734 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 173 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2742 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 178 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2751 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 182 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2760 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 186 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2769 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 190 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2778 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 194 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2787 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 198 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2796 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 202 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2805 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 206 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2814 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 210 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2823 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 214 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2832 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 218 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2841 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 222 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2850 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 226 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2859 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 230 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2868 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 234 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2877 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 238 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2886 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 242 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2895 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 246 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2904 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 250 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2913 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 254 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2922 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 258 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2931 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 262 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2940 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 266 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2949 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 270 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2958 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 274 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2967 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 278 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2976 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 282 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2985 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 288 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 2994 "src-generated/ugbc.tab.c"
    break;

  case 60: /* exponential: Identifier $@1 OP indexes CP  */
#line 292 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-4].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-4].string) )->name;
    }
#line 3006 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 299 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3015 "src-generated/ugbc.tab.c"
    break;

  case 62: /* exponential: Identifier DOLLAR $@2 OP indexes CP  */
#line 303 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-5].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-5].string) )->name;
    }
#line 3027 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 310 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3035 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 313 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3043 "src-generated/ugbc.tab.c"
    break;

  case 65: /* exponential: Integer  */
#line 316 "src/ugbc.y"
              { 
        if ( (yyvsp[0].integer) < 0 ) {
            (yyval.string) = variable_temporary( _environment, VT_SWORD, "(signed integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        } else {
            (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        }
      }
#line 3057 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 325 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3066 "src-generated/ugbc.tab.c"
    break;

  case 67: /* exponential: String  */
#line 329 "src/ugbc.y"
             { 
        outline1("; (expr string: \"%s\")", (yyvsp[0].string) );
        (yyval.string) = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", (yyval.string) );
        variable_store_string( _environment, (yyval.string), (yyvsp[0].string) );
        outline2("; variable stored: %s = %s", (yyval.string), (yyvsp[0].string) );
      }
#line 3078 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 336 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3087 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 340 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3096 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 344 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3105 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 348 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3114 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 352 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3123 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 356 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3132 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 360 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3141 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 364 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3150 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 368 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3158 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 371 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3166 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 374 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3174 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 377 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3182 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 380 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3190 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 383 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3198 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 386 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3206 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 389 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3214 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 392 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3222 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 395 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3230 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 398 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3238 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 401 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3246 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 404 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3254 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 407 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3262 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 410 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3270 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 413 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3278 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 416 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3286 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 419 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3294 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 422 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3302 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 425 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3310 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 428 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3318 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 431 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3326 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 434 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3334 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 437 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3342 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 440 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3350 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 443 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3358 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 446 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3366 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 449 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3374 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 452 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3382 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 455 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3390 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: SGN OP expr CP  */
#line 458 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3398 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: ABS OP expr CP  */
#line 461 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3406 "src-generated/ugbc.tab.c"
    break;

  case 108: /* exponential: TRUE  */
#line 464 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3415 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: FALSE  */
#line 468 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3424 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: COLORS  */
#line 472 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3433 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: WIDTH  */
#line 476 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3441 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: HEIGHT  */
#line 479 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3449 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: TIMER  */
#line 482 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3457 "src-generated/ugbc.tab.c"
    break;

  case 116: /* bank_definition_simple: AT direct_integer  */
#line 490 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3465 "src-generated/ugbc.tab.c"
    break;

  case 117: /* bank_definition_simple: Identifier AT direct_integer  */
#line 493 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3473 "src-generated/ugbc.tab.c"
    break;

  case 118: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 496 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3481 "src-generated/ugbc.tab.c"
    break;

  case 119: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 499 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3489 "src-generated/ugbc.tab.c"
    break;

  case 120: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 502 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3497 "src-generated/ugbc.tab.c"
    break;

  case 121: /* bank_definition_simple: DATA AT direct_integer  */
#line 505 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3505 "src-generated/ugbc.tab.c"
    break;

  case 122: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 509 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3513 "src-generated/ugbc.tab.c"
    break;

  case 123: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 512 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3521 "src-generated/ugbc.tab.c"
    break;

  case 124: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 515 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3529 "src-generated/ugbc.tab.c"
    break;

  case 125: /* bank_definition_simple: CODE AT direct_integer  */
#line 518 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3537 "src-generated/ugbc.tab.c"
    break;

  case 126: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 522 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3545 "src-generated/ugbc.tab.c"
    break;

  case 127: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 525 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3553 "src-generated/ugbc.tab.c"
    break;

  case 128: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 528 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3561 "src-generated/ugbc.tab.c"
    break;

  case 129: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 531 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3569 "src-generated/ugbc.tab.c"
    break;

  case 130: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 535 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3577 "src-generated/ugbc.tab.c"
    break;

  case 131: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 538 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3585 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 541 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3593 "src-generated/ugbc.tab.c"
    break;

  case 133: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 544 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3601 "src-generated/ugbc.tab.c"
    break;

  case 134: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 550 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3609 "src-generated/ugbc.tab.c"
    break;

  case 135: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 553 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3617 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 556 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3625 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 559 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3633 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 562 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3641 "src-generated/ugbc.tab.c"
    break;

  case 141: /* raster_definition_simple: Identifier AT direct_integer  */
#line 571 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3649 "src-generated/ugbc.tab.c"
    break;

  case 142: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 574 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3657 "src-generated/ugbc.tab.c"
    break;

  case 143: /* raster_definition_expression: Identifier AT expr  */
#line 579 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3665 "src-generated/ugbc.tab.c"
    break;

  case 144: /* raster_definition_expression: AT expr WITH Identifier  */
#line 582 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3673 "src-generated/ugbc.tab.c"
    break;

  case 147: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 591 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3681 "src-generated/ugbc.tab.c"
    break;

  case 148: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 594 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3689 "src-generated/ugbc.tab.c"
    break;

  case 149: /* next_raster_definition_expression: Identifier AT expr  */
#line 599 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3697 "src-generated/ugbc.tab.c"
    break;

  case 150: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 602 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3705 "src-generated/ugbc.tab.c"
    break;

  case 153: /* color_definition_simple: BORDER direct_integer  */
#line 611 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3713 "src-generated/ugbc.tab.c"
    break;

  case 154: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 614 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3721 "src-generated/ugbc.tab.c"
    break;

  case 155: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 617 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3729 "src-generated/ugbc.tab.c"
    break;

  case 156: /* color_definition_expression: BORDER expr  */
#line 622 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3737 "src-generated/ugbc.tab.c"
    break;

  case 157: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 625 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3745 "src-generated/ugbc.tab.c"
    break;

  case 158: /* color_definition_expression: SPRITE expr TO expr  */
#line 628 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3753 "src-generated/ugbc.tab.c"
    break;

  case 164: /* wait_definition_simple: direct_integer CYCLES  */
#line 642 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3761 "src-generated/ugbc.tab.c"
    break;

  case 165: /* wait_definition_simple: direct_integer TICKS  */
#line 645 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3769 "src-generated/ugbc.tab.c"
    break;

  case 166: /* wait_definition_simple: direct_integer milliseconds  */
#line 648 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3777 "src-generated/ugbc.tab.c"
    break;

  case 167: /* wait_definition_expression: expr CYCLES  */
#line 653 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3785 "src-generated/ugbc.tab.c"
    break;

  case 168: /* wait_definition_expression: expr TICKS  */
#line 656 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3793 "src-generated/ugbc.tab.c"
    break;

  case 169: /* wait_definition_expression: expr milliseconds  */
#line 659 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3801 "src-generated/ugbc.tab.c"
    break;

  case 172: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 669 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3809 "src-generated/ugbc.tab.c"
    break;

  case 173: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 672 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3817 "src-generated/ugbc.tab.c"
    break;

  case 174: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 675 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3825 "src-generated/ugbc.tab.c"
    break;

  case 175: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 678 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3833 "src-generated/ugbc.tab.c"
    break;

  case 176: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 681 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3841 "src-generated/ugbc.tab.c"
    break;

  case 177: /* sprite_definition_simple: direct_integer ENABLE  */
#line 684 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3849 "src-generated/ugbc.tab.c"
    break;

  case 178: /* sprite_definition_simple: direct_integer DISABLE  */
#line 687 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3857 "src-generated/ugbc.tab.c"
    break;

  case 179: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 690 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3865 "src-generated/ugbc.tab.c"
    break;

  case 180: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 693 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3873 "src-generated/ugbc.tab.c"
    break;

  case 181: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 696 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3881 "src-generated/ugbc.tab.c"
    break;

  case 182: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 699 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3889 "src-generated/ugbc.tab.c"
    break;

  case 183: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 702 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3897 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 705 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3905 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 708 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3913 "src-generated/ugbc.tab.c"
    break;

  case 186: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 711 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3921 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_expression: expr DATA FROM expr  */
#line 716 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3929 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_expression: expr MULTICOLOR  */
#line 719 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3937 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_expression: expr MONOCOLOR  */
#line 722 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3945 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_expression: expr COLOR expr  */
#line 725 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3953 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 728 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3961 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_expression: expr ENABLE  */
#line 731 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3969 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_expression: expr DISABLE  */
#line 734 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3977 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 737 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3985 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 740 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3993 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 743 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4001 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 746 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4009 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 749 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4017 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 752 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4025 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 755 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4033 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 758 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4041 "src-generated/ugbc.tab.c"
    break;

  case 204: /* bitmap_definition_simple: AT direct_integer  */
#line 767 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4049 "src-generated/ugbc.tab.c"
    break;

  case 205: /* bitmap_definition_simple: ENABLE  */
#line 770 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4057 "src-generated/ugbc.tab.c"
    break;

  case 206: /* bitmap_definition_simple: DISABLE  */
#line 773 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4065 "src-generated/ugbc.tab.c"
    break;

  case 207: /* bitmap_definition_simple: CLEAR  */
#line 776 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4073 "src-generated/ugbc.tab.c"
    break;

  case 208: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 779 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4081 "src-generated/ugbc.tab.c"
    break;

  case 209: /* bitmap_definition_expression: AT expr  */
#line 785 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4089 "src-generated/ugbc.tab.c"
    break;

  case 210: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 788 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4097 "src-generated/ugbc.tab.c"
    break;

  case 213: /* textmap_definition_simple: AT direct_integer  */
#line 798 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4105 "src-generated/ugbc.tab.c"
    break;

  case 214: /* textmap_definition_expression: AT expr  */
#line 803 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4113 "src-generated/ugbc.tab.c"
    break;

  case 217: /* text_definition_simple: ENABLE  */
#line 812 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4121 "src-generated/ugbc.tab.c"
    break;

  case 218: /* text_definition_simple: DISABLE  */
#line 815 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4129 "src-generated/ugbc.tab.c"
    break;

  case 219: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 820 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4137 "src-generated/ugbc.tab.c"
    break;

  case 220: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 823 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4145 "src-generated/ugbc.tab.c"
    break;

  case 223: /* tiles_definition_simple: AT direct_integer  */
#line 832 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4153 "src-generated/ugbc.tab.c"
    break;

  case 224: /* tiles_definition_expression: AT expr  */
#line 837 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4161 "src-generated/ugbc.tab.c"
    break;

  case 227: /* colormap_definition_simple: AT direct_integer  */
#line 846 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4169 "src-generated/ugbc.tab.c"
    break;

  case 228: /* colormap_definition_simple: CLEAR  */
#line 849 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4177 "src-generated/ugbc.tab.c"
    break;

  case 229: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 852 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4185 "src-generated/ugbc.tab.c"
    break;

  case 230: /* colormap_definition_expression: AT expr  */
#line 857 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4193 "src-generated/ugbc.tab.c"
    break;

  case 231: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 860 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4201 "src-generated/ugbc.tab.c"
    break;

  case 234: /* screen_definition_simple: ON  */
#line 870 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4209 "src-generated/ugbc.tab.c"
    break;

  case 235: /* screen_definition_simple: OFF  */
#line 873 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4217 "src-generated/ugbc.tab.c"
    break;

  case 236: /* screen_definition_simple: ROWS direct_integer  */
#line 876 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4225 "src-generated/ugbc.tab.c"
    break;

  case 237: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 879 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4233 "src-generated/ugbc.tab.c"
    break;

  case 238: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 882 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4241 "src-generated/ugbc.tab.c"
    break;

  case 239: /* screen_definition_expression: ROWS expr  */
#line 887 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4249 "src-generated/ugbc.tab.c"
    break;

  case 240: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 890 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4257 "src-generated/ugbc.tab.c"
    break;

  case 241: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 893 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4265 "src-generated/ugbc.tab.c"
    break;

  case 245: /* var_definition_simple: Identifier ON Identifier  */
#line 902 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4273 "src-generated/ugbc.tab.c"
    break;

  case 246: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 905 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4281 "src-generated/ugbc.tab.c"
    break;

  case 247: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 908 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4289 "src-generated/ugbc.tab.c"
    break;

  case 248: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 911 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4299 "src-generated/ugbc.tab.c"
    break;

  case 249: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 916 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4309 "src-generated/ugbc.tab.c"
    break;

  case 250: /* goto_definition: Identifier  */
#line 923 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4317 "src-generated/ugbc.tab.c"
    break;

  case 251: /* goto_definition: Integer  */
#line 926 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4325 "src-generated/ugbc.tab.c"
    break;

  case 252: /* gosub_definition: Identifier  */
#line 932 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4333 "src-generated/ugbc.tab.c"
    break;

  case 253: /* gosub_definition: Integer  */
#line 935 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4341 "src-generated/ugbc.tab.c"
    break;

  case 255: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 944 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4349 "src-generated/ugbc.tab.c"
    break;

  case 256: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 950 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4357 "src-generated/ugbc.tab.c"
    break;

  case 259: /* ink_definition: expr  */
#line 959 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4365 "src-generated/ugbc.tab.c"
    break;

  case 260: /* on_goto_definition: Identifier  */
#line 964 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4374 "src-generated/ugbc.tab.c"
    break;

  case 261: /* $@3: %empty  */
#line 968 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4382 "src-generated/ugbc.tab.c"
    break;

  case 263: /* on_gosub_definition: Identifier  */
#line 973 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4391 "src-generated/ugbc.tab.c"
    break;

  case 264: /* $@4: %empty  */
#line 977 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4399 "src-generated/ugbc.tab.c"
    break;

  case 266: /* on_proc_definition: Identifier  */
#line 982 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4408 "src-generated/ugbc.tab.c"
    break;

  case 267: /* $@5: %empty  */
#line 986 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4416 "src-generated/ugbc.tab.c"
    break;

  case 269: /* $@6: %empty  */
#line 991 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4424 "src-generated/ugbc.tab.c"
    break;

  case 271: /* $@7: %empty  */
#line 994 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4432 "src-generated/ugbc.tab.c"
    break;

  case 273: /* $@8: %empty  */
#line 997 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4440 "src-generated/ugbc.tab.c"
    break;

  case 275: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1002 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4448 "src-generated/ugbc.tab.c"
    break;

  case 276: /* every_definition: ON  */
#line 1005 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4456 "src-generated/ugbc.tab.c"
    break;

  case 277: /* every_definition: OFF  */
#line 1008 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4464 "src-generated/ugbc.tab.c"
    break;

  case 278: /* add_definition: Identifier COMMA expr  */
#line 1013 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4472 "src-generated/ugbc.tab.c"
    break;

  case 279: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1016 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4480 "src-generated/ugbc.tab.c"
    break;

  case 280: /* dimensions: Integer  */
#line 1022 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4489 "src-generated/ugbc.tab.c"
    break;

  case 281: /* dimensions: Integer COMMA dimensions  */
#line 1026 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4498 "src-generated/ugbc.tab.c"
    break;

  case 282: /* datatype: BYTE  */
#line 1033 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 4506 "src-generated/ugbc.tab.c"
    break;

  case 283: /* datatype: SIGNED BYTE  */
#line 1036 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 4514 "src-generated/ugbc.tab.c"
    break;

  case 284: /* datatype: WORD  */
#line 1039 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 4522 "src-generated/ugbc.tab.c"
    break;

  case 285: /* datatype: SIGNED WORD  */
#line 1042 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 4530 "src-generated/ugbc.tab.c"
    break;

  case 286: /* datatype: DWORD  */
#line 1045 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 4538 "src-generated/ugbc.tab.c"
    break;

  case 287: /* datatype: SIGNED DWORD  */
#line 1048 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 4546 "src-generated/ugbc.tab.c"
    break;

  case 288: /* datatype: ADDRESS  */
#line 1051 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 4554 "src-generated/ugbc.tab.c"
    break;

  case 289: /* datatype: POSITION  */
#line 1054 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 4562 "src-generated/ugbc.tab.c"
    break;

  case 290: /* datatype: COLOR  */
#line 1057 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 4570 "src-generated/ugbc.tab.c"
    break;

  case 291: /* datatype: STRING  */
#line 1060 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 4578 "src-generated/ugbc.tab.c"
    break;

  case 292: /* $@9: %empty  */
#line 1065 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4587 "src-generated/ugbc.tab.c"
    break;

  case 293: /* dim_definition: Identifier $@9 OP dimensions CP  */
#line 1068 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 4597 "src-generated/ugbc.tab.c"
    break;

  case 294: /* $@10: %empty  */
#line 1073 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4606 "src-generated/ugbc.tab.c"
    break;

  case 295: /* dim_definition: Identifier $@10 DOLLAR OP dimensions CP  */
#line 1076 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 4616 "src-generated/ugbc.tab.c"
    break;

  case 296: /* $@11: %empty  */
#line 1081 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4625 "src-generated/ugbc.tab.c"
    break;

  case 297: /* dim_definition: Identifier datatype $@11 OP dimensions CP  */
#line 1084 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 4635 "src-generated/ugbc.tab.c"
    break;

  case 300: /* indexes: expr  */
#line 1097 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = (yyvsp[0].string);
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4644 "src-generated/ugbc.tab.c"
    break;

  case 301: /* indexes: expr COMMA indexes  */
#line 1101 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = (yyvsp[-2].string);
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4653 "src-generated/ugbc.tab.c"
    break;

  case 318: /* statement: INC Identifier  */
#line 1124 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 4661 "src-generated/ugbc.tab.c"
    break;

  case 319: /* statement: DEC Identifier  */
#line 1127 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 4669 "src-generated/ugbc.tab.c"
    break;

  case 320: /* statement: RANDOMIZE  */
#line 1130 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 4677 "src-generated/ugbc.tab.c"
    break;

  case 321: /* statement: RANDOMIZE expr  */
#line 1133 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 4685 "src-generated/ugbc.tab.c"
    break;

  case 322: /* statement: IF expr THEN  */
#line 1136 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4693 "src-generated/ugbc.tab.c"
    break;

  case 323: /* statement: ELSE  */
#line 1139 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 4701 "src-generated/ugbc.tab.c"
    break;

  case 324: /* statement: ELSE IF expr THEN  */
#line 1142 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4709 "src-generated/ugbc.tab.c"
    break;

  case 325: /* statement: ENDIF  */
#line 1145 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 4717 "src-generated/ugbc.tab.c"
    break;

  case 326: /* statement: DO  */
#line 1148 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 4725 "src-generated/ugbc.tab.c"
    break;

  case 327: /* statement: LOOP  */
#line 1151 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 4733 "src-generated/ugbc.tab.c"
    break;

  case 328: /* $@12: %empty  */
#line 1154 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 4741 "src-generated/ugbc.tab.c"
    break;

  case 329: /* statement: WHILE $@12 expr  */
#line 1156 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 4749 "src-generated/ugbc.tab.c"
    break;

  case 330: /* statement: WEND  */
#line 1159 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 4757 "src-generated/ugbc.tab.c"
    break;

  case 331: /* statement: REPEAT  */
#line 1162 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 4765 "src-generated/ugbc.tab.c"
    break;

  case 332: /* statement: UNTIL expr  */
#line 1165 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 4773 "src-generated/ugbc.tab.c"
    break;

  case 333: /* statement: EXIT  */
#line 1168 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 4781 "src-generated/ugbc.tab.c"
    break;

  case 334: /* statement: EXIT PROC  */
#line 1171 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 4789 "src-generated/ugbc.tab.c"
    break;

  case 335: /* statement: POP PROC  */
#line 1174 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 4797 "src-generated/ugbc.tab.c"
    break;

  case 336: /* statement: EXIT IF expr  */
#line 1177 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 4805 "src-generated/ugbc.tab.c"
    break;

  case 337: /* statement: EXIT Integer  */
#line 1180 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4813 "src-generated/ugbc.tab.c"
    break;

  case 338: /* statement: EXIT direct_integer  */
#line 1183 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4821 "src-generated/ugbc.tab.c"
    break;

  case 339: /* statement: EXIT IF expr COMMA Integer  */
#line 1186 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4829 "src-generated/ugbc.tab.c"
    break;

  case 340: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1189 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4837 "src-generated/ugbc.tab.c"
    break;

  case 341: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1192 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4845 "src-generated/ugbc.tab.c"
    break;

  case 342: /* statement: NEXT  */
#line 1195 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 4853 "src-generated/ugbc.tab.c"
    break;

  case 343: /* statement: PROCEDURE Identifier  */
#line 1198 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 4861 "src-generated/ugbc.tab.c"
    break;

  case 344: /* statement: END PROC  */
#line 1201 "src/ugbc.y"
             {
      end_procedure( _environment );
  }
#line 4869 "src-generated/ugbc.tab.c"
    break;

  case 345: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1204 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4877 "src-generated/ugbc.tab.c"
    break;

  case 346: /* statement: Identifier SPACE  */
#line 1207 "src/ugbc.y"
                     {
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 4885 "src-generated/ugbc.tab.c"
    break;

  case 347: /* statement: PROC Identifier  */
#line 1210 "src/ugbc.y"
                    {
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 4893 "src-generated/ugbc.tab.c"
    break;

  case 348: /* statement: CALL Identifier  */
#line 1213 "src/ugbc.y"
                    {
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 4901 "src-generated/ugbc.tab.c"
    break;

  case 349: /* statement: Identifier COLON  */
#line 1216 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 4909 "src-generated/ugbc.tab.c"
    break;

  case 350: /* statement: BEG GAMELOOP  */
#line 1219 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 4917 "src-generated/ugbc.tab.c"
    break;

  case 351: /* statement: END GAMELOOP  */
#line 1222 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 4925 "src-generated/ugbc.tab.c"
    break;

  case 352: /* statement: GRAPHIC  */
#line 1225 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 4933 "src-generated/ugbc.tab.c"
    break;

  case 353: /* statement: HALT  */
#line 1228 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 4941 "src-generated/ugbc.tab.c"
    break;

  case 354: /* statement: END  */
#line 1231 "src/ugbc.y"
        {
      end( _environment );
  }
#line 4949 "src-generated/ugbc.tab.c"
    break;

  case 359: /* statement: RETURN  */
#line 1238 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 4957 "src-generated/ugbc.tab.c"
    break;

  case 360: /* statement: POP  */
#line 1241 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 4965 "src-generated/ugbc.tab.c"
    break;

  case 361: /* statement: DONE  */
#line 1244 "src/ugbc.y"
          {
      return 0;
  }
#line 4973 "src-generated/ugbc.tab.c"
    break;

  case 362: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1247 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4981 "src-generated/ugbc.tab.c"
    break;

  case 363: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1250 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4989 "src-generated/ugbc.tab.c"
    break;

  case 364: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1253 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 4997 "src-generated/ugbc.tab.c"
    break;

  case 365: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1256 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5005 "src-generated/ugbc.tab.c"
    break;

  case 367: /* statement: Identifier ASSIGN expr  */
#line 1260 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 5019 "src-generated/ugbc.tab.c"
    break;

  case 368: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1269 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 5033 "src-generated/ugbc.tab.c"
    break;

  case 369: /* $@13: %empty  */
#line 1278 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5042 "src-generated/ugbc.tab.c"
    break;

  case 370: /* statement: Identifier $@13 OP indexes CP ASSIGN expr  */
#line 1282 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 5055 "src-generated/ugbc.tab.c"
    break;

  case 371: /* $@14: %empty  */
#line 1290 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5064 "src-generated/ugbc.tab.c"
    break;

  case 372: /* statement: Identifier DOLLAR $@14 OP indexes CP ASSIGN expr  */
#line 1293 "src/ugbc.y"
                                {
        Variable * x = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * a = variable_retrieve( _environment, (yyvsp[-7].string) );
        if ( x->type != VT_STRING ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[x->type], DATATYPE_AS_STRING[VT_STRING] );
        }
        if ( a->type != VT_ARRAY ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->type], DATATYPE_AS_STRING[VT_ARRAY] );
        }
        if ( a->arrayType != VT_STRING ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->arrayType], DATATYPE_AS_STRING[VT_STRING] );
        }
        variable_move_array_string( _environment, (yyvsp[-7].string), x->name );
  }
#line 5083 "src-generated/ugbc.tab.c"
    break;

  case 373: /* $@15: %empty  */
#line 1307 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5092 "src-generated/ugbc.tab.c"
    break;

  case 374: /* statement: Identifier $@15 datatype OP indexes CP ASSIGN expr  */
#line 1310 "src/ugbc.y"
                                         {
        Variable * x = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * a = variable_retrieve( _environment, (yyvsp[-7].string) );
        if ( x->type != (yyvsp[-5].integer) ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[x->type], DATATYPE_AS_STRING[(yyvsp[-5].integer)] );
        }
        if ( a->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-7].string) );
        }
        if ( a->arrayType != (yyvsp[-5].integer) ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->arrayType], DATATYPE_AS_STRING[(yyvsp[-5].integer)] );
        }
        variable_move_array( _environment, (yyvsp[-7].string), x->name );
  }
#line 5111 "src-generated/ugbc.tab.c"
    break;

  case 375: /* statement: DEBUG expr  */
#line 1324 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 5119 "src-generated/ugbc.tab.c"
    break;

  case 378: /* statements_no_linenumbers: statement  */
#line 1332 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 5125 "src-generated/ugbc.tab.c"
    break;

  case 379: /* $@16: %empty  */
#line 1333 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 5131 "src-generated/ugbc.tab.c"
    break;

  case 381: /* $@17: %empty  */
#line 1337 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 5139 "src-generated/ugbc.tab.c"
    break;

  case 382: /* statements_with_linenumbers: Integer $@17 statements_no_linenumbers  */
#line 1339 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 5147 "src-generated/ugbc.tab.c"
    break;

  case 383: /* $@18: %empty  */
#line 1344 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 5155 "src-generated/ugbc.tab.c"
    break;

  case 389: /* $@19: %empty  */
#line 1354 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 5161 "src-generated/ugbc.tab.c"
    break;


#line 5165 "src-generated/ugbc.tab.c"

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

#line 1356 "src/ugbc.y"


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
        variable_global( _environment, "strings_address" );
        bank_define( _environment, "STRINGS", BT_STRINGS, 0x4200, NULL );
        variable_define( _environment, "text_address", VT_ADDRESS, 0x0400 );
        variable_global( _environment, "text_address" );
    } else {
        outhead0("org 32768");
        variable_define( _environment, "strings_address", VT_ADDRESS, 0xa000 );
        variable_global( _environment, "strings_address" );
        variable_define( _environment, "bitmap_enabled", VT_BYTE, 0 );
        variable_global( _environment, "bitmap_enabled" );
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

