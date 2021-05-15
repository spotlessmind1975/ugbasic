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
  YYSYMBOL_OSP = 147,                      /* OSP  */
  YYSYMBOL_CSP = 148,                      /* CSP  */
  YYSYMBOL_SHARED = 149,                   /* SHARED  */
  YYSYMBOL_MILLISECOND = 150,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 151,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 152,                    /* TICKS  */
  YYSYMBOL_GLOBAL = 153,                   /* GLOBAL  */
  YYSYMBOL_PARAM = 154,                    /* PARAM  */
  YYSYMBOL_PRINT = 155,                    /* PRINT  */
  YYSYMBOL_DEFAULT = 156,                  /* DEFAULT  */
  YYSYMBOL_SPECIFIC = 157,                 /* SPECIFIC  */
  YYSYMBOL_ANSI = 158,                     /* ANSI  */
  YYSYMBOL_USE = 159,                      /* USE  */
  YYSYMBOL_PAPER = 160,                    /* PAPER  */
  YYSYMBOL_INVERSE = 161,                  /* INVERSE  */
  YYSYMBOL_BLACK = 162,                    /* BLACK  */
  YYSYMBOL_WHITE = 163,                    /* WHITE  */
  YYSYMBOL_RED = 164,                      /* RED  */
  YYSYMBOL_CYAN = 165,                     /* CYAN  */
  YYSYMBOL_VIOLET = 166,                   /* VIOLET  */
  YYSYMBOL_GREEN = 167,                    /* GREEN  */
  YYSYMBOL_BLUE = 168,                     /* BLUE  */
  YYSYMBOL_YELLOW = 169,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 170,                   /* ORANGE  */
  YYSYMBOL_BROWN = 171,                    /* BROWN  */
  YYSYMBOL_LIGHT = 172,                    /* LIGHT  */
  YYSYMBOL_DARK = 173,                     /* DARK  */
  YYSYMBOL_GREY = 174,                     /* GREY  */
  YYSYMBOL_GRAY = 175,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 176,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 177,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 178,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 179,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 180,                /* TURQUOISE  */
  YYSYMBOL_TAN = 181,                      /* TAN  */
  YYSYMBOL_PINK = 182,                     /* PINK  */
  YYSYMBOL_PEACH = 183,                    /* PEACH  */
  YYSYMBOL_OLIVE = 184,                    /* OLIVE  */
  YYSYMBOL_Identifier = 185,               /* Identifier  */
  YYSYMBOL_String = 186,                   /* String  */
  YYSYMBOL_Integer = 187,                  /* Integer  */
  YYSYMBOL_188_ = 188,                     /* " "  */
  YYSYMBOL_YYACCEPT = 189,                 /* $accept  */
  YYSYMBOL_expr = 190,                     /* expr  */
  YYSYMBOL_expr_math = 191,                /* expr_math  */
  YYSYMBOL_term = 192,                     /* term  */
  YYSYMBOL_modula = 193,                   /* modula  */
  YYSYMBOL_factor = 194,                   /* factor  */
  YYSYMBOL_direct_integer = 195,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 196, /* random_definition_simple  */
  YYSYMBOL_random_definition = 197,        /* random_definition  */
  YYSYMBOL_color_enumeration = 198,        /* color_enumeration  */
  YYSYMBOL_exponential = 199,              /* exponential  */
  YYSYMBOL_200_1 = 200,                    /* $@1  */
  YYSYMBOL_201_2 = 201,                    /* $@2  */
  YYSYMBOL_202_3 = 202,                    /* $@3  */
  YYSYMBOL_position = 203,                 /* position  */
  YYSYMBOL_bank_definition_simple = 204,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 205, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 206,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 207, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 208, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 209,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 210, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 211, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 212,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 213,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 214, /* color_definition_expression  */
  YYSYMBOL_color_definition = 215,         /* color_definition  */
  YYSYMBOL_milliseconds = 216,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 217,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 218, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 219,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 220, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 221, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 222,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 223, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 224, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 225,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 226, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 227, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 228,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 229,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 230, /* text_definition_expression  */
  YYSYMBOL_text_definition = 231,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 232,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 233, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 234,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 235, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 236, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 237,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 238, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 239, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 240,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 241,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 242,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 243,         /* gosub_definition  */
  YYSYMBOL_var_definition = 244,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 245,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 246, /* point_definition_expression  */
  YYSYMBOL_point_definition = 247,         /* point_definition  */
  YYSYMBOL_ink_definition = 248,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 249,       /* on_goto_definition  */
  YYSYMBOL_250_4 = 250,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 251,      /* on_gosub_definition  */
  YYSYMBOL_252_5 = 252,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 253,       /* on_proc_definition  */
  YYSYMBOL_254_6 = 254,                    /* $@6  */
  YYSYMBOL_on_definition = 255,            /* on_definition  */
  YYSYMBOL_256_7 = 256,                    /* $@7  */
  YYSYMBOL_257_8 = 257,                    /* $@8  */
  YYSYMBOL_258_9 = 258,                    /* $@9  */
  YYSYMBOL_every_definition = 259,         /* every_definition  */
  YYSYMBOL_add_definition = 260,           /* add_definition  */
  YYSYMBOL_dimensions = 261,               /* dimensions  */
  YYSYMBOL_datatype = 262,                 /* datatype  */
  YYSYMBOL_dim_definition = 263,           /* dim_definition  */
  YYSYMBOL_264_10 = 264,                   /* $@10  */
  YYSYMBOL_265_11 = 265,                   /* $@11  */
  YYSYMBOL_266_12 = 266,                   /* $@12  */
  YYSYMBOL_dim_definitions = 267,          /* dim_definitions  */
  YYSYMBOL_indexes = 268,                  /* indexes  */
  YYSYMBOL_parameters = 269,               /* parameters  */
  YYSYMBOL_parameters_expr = 270,          /* parameters_expr  */
  YYSYMBOL_values = 271,                   /* values  */
  YYSYMBOL_print_definition = 272,         /* print_definition  */
  YYSYMBOL_273_13 = 273,                   /* $@13  */
  YYSYMBOL_274_14 = 274,                   /* $@14  */
  YYSYMBOL_use_definition = 275,           /* use_definition  */
  YYSYMBOL_statement = 276,                /* statement  */
  YYSYMBOL_277_15 = 277,                   /* $@15  */
  YYSYMBOL_278_16 = 278,                   /* $@16  */
  YYSYMBOL_279_17 = 279,                   /* $@17  */
  YYSYMBOL_280_18 = 280,                   /* $@18  */
  YYSYMBOL_281_19 = 281,                   /* $@19  */
  YYSYMBOL_282_20 = 282,                   /* $@20  */
  YYSYMBOL_283_21 = 283,                   /* $@21  */
  YYSYMBOL_284_22 = 284,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 285, /* statements_no_linenumbers  */
  YYSYMBOL_286_23 = 286,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 287, /* statements_with_linenumbers  */
  YYSYMBOL_288_24 = 288,                   /* $@24  */
  YYSYMBOL_statements_complex = 289,       /* statements_complex  */
  YYSYMBOL_290_25 = 290,                   /* $@25  */
  YYSYMBOL_program = 291,                  /* program  */
  YYSYMBOL_292_26 = 292                    /* $@26  */
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
#define YYLAST   2157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  189
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  104
/* YYNRULES -- Number of rules.  */
#define YYNRULES  445
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  860

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   443


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
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    73,    73,    74,    78,    82,    85,    88,    91,    94,
      97,   100,   106,   107,   110,   117,   118,   122,   123,   127,
     134,   135,   139,   146,   151,   154,   157,   160,   163,   166,
     169,   174,   179,   183,   187,   191,   195,   199,   203,   207,
     211,   215,   219,   223,   227,   231,   235,   239,   243,   247,
     251,   255,   259,   263,   267,   271,   275,   279,   283,   289,
     289,   300,   300,   311,   314,   317,   326,   330,   337,   341,
     345,   349,   353,   357,   361,   365,   369,   372,   375,   378,
     381,   384,   387,   390,   393,   396,   399,   402,   405,   408,
     411,   414,   417,   420,   423,   426,   429,   432,   435,   438,
     441,   444,   447,   450,   453,   456,   459,   462,   465,   465,
     471,   474,   477,   481,   485,   489,   493,   497,   501,   505,
     509,   513,   516,   519,   522,   525,   530,   530,   533,   536,
     539,   542,   545,   548,   552,   555,   558,   561,   565,   568,
     571,   574,   578,   581,   584,   587,   593,   596,   599,   602,
     605,   610,   611,   614,   617,   622,   625,   630,   631,   634,
     637,   642,   645,   650,   651,   654,   657,   660,   665,   668,
     671,   676,   677,   680,   681,   682,   685,   688,   691,   696,
     699,   702,   708,   709,   712,   715,   718,   721,   724,   727,
     730,   733,   736,   739,   742,   745,   748,   751,   754,   759,
     762,   765,   768,   771,   774,   777,   780,   783,   786,   789,
     792,   795,   798,   801,   806,   807,   810,   813,   816,   819,
     822,   828,   831,   837,   838,   841,   846,   851,   852,   855,
     858,   863,   866,   871,   872,   875,   880,   885,   886,   889,
     892,   895,   900,   903,   909,   910,   913,   916,   919,   922,
     925,   930,   933,   936,   941,   942,   944,   945,   948,   951,
     954,   959,   966,   969,   975,   978,   984,   987,   993,   998,
     999,  1002,  1007,  1011,  1011,  1016,  1020,  1020,  1025,  1029,
    1029,  1034,  1034,  1037,  1037,  1040,  1040,  1045,  1048,  1051,
    1056,  1059,  1065,  1069,  1076,  1079,  1082,  1085,  1088,  1091,
    1094,  1097,  1100,  1103,  1108,  1108,  1116,  1116,  1124,  1124,
    1135,  1136,  1140,  1144,  1151,  1156,  1161,  1166,  1171,  1176,
    1184,  1189,  1194,  1199,  1204,  1209,  1214,  1218,  1225,  1229,
    1236,  1239,  1243,  1246,  1246,  1250,  1250,  1256,  1259,  1265,
    1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,
    1276,  1277,  1278,  1279,  1280,  1281,  1282,  1285,  1288,  1291,
    1294,  1297,  1300,  1303,  1306,  1309,  1312,  1312,  1317,  1320,
    1323,  1326,  1329,  1332,  1335,  1338,  1341,  1344,  1347,  1350,
    1353,  1356,  1360,  1360,  1365,  1368,  1371,  1374,  1377,  1380,
    1384,  1388,  1392,  1392,  1397,  1397,  1402,  1402,  1407,  1410,
    1413,  1416,  1419,  1422,  1425,  1428,  1431,  1434,  1437,  1438,
    1439,  1440,  1441,  1444,  1447,  1450,  1453,  1456,  1459,  1462,
    1465,  1466,  1467,  1476,  1485,  1485,  1497,  1497,  1514,  1514,
    1531,  1534,  1535,  1539,  1540,  1540,  1544,  1544,  1551,  1551,
    1554,  1555,  1556,  1557,  1561,  1561
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
  "OSP", "CSP", "SHARED", "MILLISECOND", "MILLISECONDS", "TICKS", "GLOBAL",
  "PARAM", "PRINT", "DEFAULT", "SPECIFIC", "ANSI", "USE", "PAPER",
  "INVERSE", "BLACK", "WHITE", "RED", "CYAN", "VIOLET", "GREEN", "BLUE",
  "YELLOW", "ORANGE", "BROWN", "LIGHT", "DARK", "GREY", "GRAY", "MAGENTA",
  "PURPLE", "LAVENDER", "GOLD", "TURQUOISE", "TAN", "PINK", "PEACH",
  "OLIVE", "Identifier", "String", "Integer", "\" \"", "$accept", "expr",
  "expr_math", "term", "modula", "factor", "direct_integer",
  "random_definition_simple", "random_definition", "color_enumeration",
  "exponential", "$@1", "$@2", "$@3", "position", "bank_definition_simple",
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
  "on_goto_definition", "$@4", "on_gosub_definition", "$@5",
  "on_proc_definition", "$@6", "on_definition", "$@7", "$@8", "$@9",
  "every_definition", "add_definition", "dimensions", "datatype",
  "dim_definition", "$@10", "$@11", "$@12", "dim_definitions", "indexes",
  "parameters", "parameters_expr", "values", "print_definition", "$@13",
  "$@14", "use_definition", "statement", "$@15", "$@16", "$@17", "$@18",
  "$@19", "$@20", "$@21", "$@22", "statements_no_linenumbers", "$@23",
  "statements_with_linenumbers", "$@24", "statements_complex", "$@25",
  "program", "$@26", YY_NULLPTR
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
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443
};
#endif

#define YYPACT_NINF (-742)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-425)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -742,    83,   808,  -742,  -742,   -87,   -77,   -18,  -742,    32,
    1547,    91,    -5,  1547,  -742,    33,   209,  1688,   -69,    40,
    -742,  -742,  -742,  1240,   118,    19,  1688,  1688,    82,   -34,
    -742,   174,   198,  1688,  1688,  -742,   212,   215,    56,  1688,
     117,   222,  -742,   -30,  -742,  1688,   116,  1406,   270,   141,
    1688,   142,   144,   145,   148,   -17,   -17,  1688,    31,  1688,
     205,    26,  -742,   322,   327,   330,  -742,  -742,  -742,  1547,
     311,  -742,  -742,  -742,  1547,  1547,  1547,  -742,  -742,  -742,
     151,  1074,  -742,  -742,   305,   306,   307,   146,   155,  -742,
    -742,    -8,   310,   312,  1688,  -742,  -742,   313,   314,   315,
     316,   317,   318,   319,   321,   328,   329,   333,   334,   335,
     336,   337,   338,   339,  -742,  -742,   340,    57,   -72,     6,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,   208,  -742,  -742,
      23,   -29,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,   210,     8,  -742,  -742,   -25,   186,   231,   194,   249,
       1,  -742,  -742,  -742,  -742,  -742,    -9,   297,    -6,    -4,
      -3,    -2,   357,  -742,  -742,  -742,   213,   300,  -742,  -742,
    -742,  1547,  -742,  -742,   353,  -742,  -742,  -742,  -742,  -742,
    1547,   341,   342,  -742,  -742,  -742,   -20,  -742,    47,  -742,
    -742,  -742,  -742,  -742,  1688,  1688,  -742,  -742,   376,  -742,
    -742,  -742,  1547,  -742,  -742,  -742,  1547,   355,  -742,  -742,
    -742,   320,  -742,  -742,  -742,   238,  1688,  1688,  -742,  -742,
    1547,  -742,  -742,  -742,   352,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  1688,  1688,  -742,  -742,  -742,  -742,   377,
    -742,  -742,   239,  -742,  1688,   385,  -742,  -742,  -742,    11,
     386,  -742,   247,   248,   251,    54,   389,  -742,  -742,   250,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  1688,
     384,  -742,  -742,   365,    43,   961,  -742,   808,   808,   371,
     372,  1547,  -742,  -742,   331,   332,   343,   344,  -742,   367,
     378,   379,   383,   388,    58,   390,  1547,  1547,  1547,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,   387,
    -742,  -742,  1688,  1688,  -742,  1688,  1688,  1688,  1688,  1688,
    1688,  1688,  1688,  1688,  1688,  1688,  1688,  1688,  1688,  1688,
    1688,  1688,  1829,   392,   221,  -742,  -742,   393,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,   394,  -742,
     396,  -742,  -742,  -742,  -742,  -742,  -742,  1829,  1829,  1829,
    1829,  1829,  1829,  1829,  1829,  1829,  1829,  1829,  1829,  1829,
    1970,  -742,  -742,  -742,  1547,   395,  -742,  -742,  -742,   363,
     297,   407,   297,   409,   297,   410,   297,   413,   297,  -742,
    1688,   405,  -742,  -742,   216,   218,    55,   104,  -742,  -742,
    -742,   406,   297,   408,  -742,  -742,   220,   224,   120,   181,
    -742,  -742,   411,  -742,  -742,  1547,  -742,  -742,  1547,  1547,
    -742,  -742,  -742,   370,   235,  -742,   432,  1688,  -742,  -742,
    -742,  -742,  1547,  -742,  1688,   436,   440,  -742,  -742,  1547,
     380,   444,  1688,   350,   446,  1688,  -742,  -742,  -742,  -742,
    -742,  -742,   143,  -742,  -742,   420,   435,   142,  -742,   309,
    -742,   -17,   450,    43,   -17,   240,   256,   808,  -742,  1688,
     424,  1688,  1688,   426,    28,  -742,   961,  -742,  -742,   277,
     278,  -742,  -742,  1688,   297,  1688,   297,   279,   280,   281,
     282,   283,   430,   437,   439,  -742,   441,   443,   447,   448,
     449,   451,  1688,   464,   472,   478,   480,   453,   454,   455,
     456,   486,   460,   461,   462,   463,   465,   492,   495,   468,
     469,   470,    18,   323,   471,  1688,   473,  1688,  1688,   231,
     231,   257,   257,   257,   257,   257,   257,   257,   257,   194,
     249,   249,  -742,   481,   482,  1547,    44,  -742,   297,  -742,
     297,  -742,   297,  -742,   297,    49,  -742,  1688,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  1688,  -742,   297,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,   297,  -742,  -742,
    -742,  -742,  -742,  -742,   324,   345,   346,   347,   499,  1688,
     506,   474,   477,   366,  1688,  1688,   513,   514,  -742,   -31,
     452,   348,  1688,   515,  -742,  -742,  -742,   489,   349,   491,
    -742,  1688,   354,  1688,  -742,   -17,   519,  -742,  1688,  1688,
    -742,  -742,  1688,   520,   381,   521,   502,  1688,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
     351,   356,   358,  -742,  -742,  -742,  -742,  -742,  -742,   505,
    1688,  1688,  1688,  1688,  -742,  -742,  -742,  -742,  1688,  -742,
    -742,  -742,  -742,  -742,  1688,  1688,  -742,  -742,  -742,  1970,
     507,  -742,   509,  1688,   401,   516,   368,   369,  -742,  -742,
    -742,  -742,  -742,  -742,   512,  -742,   523,  -742,   364,    63,
    -742,   527,  -742,   548,   550,  -742,   551,  -742,   552,  -742,
     547,  1547,   555,  1688,  1688,   297,  -742,   528,   529,  1688,
     297,  -742,  -742,  1688,  -742,    72,  1688,   349,   558,   531,
     349,   419,   157,   421,   422,  -742,   -17,  -742,  -742,   533,
    1688,  -742,  1688,   559,   536,  -742,  -742,  -742,  -742,   538,
     539,    94,   128,   540,   541,   542,   543,  -742,  -742,   545,
    -742,  -742,  -742,  -742,   397,   400,  -742,   553,  -742,   560,
    -742,  1688,   297,   574,   580,   581,  1688,  -742,  -742,  1688,
    -742,  -742,  -742,   577,   578,   561,   562,   479,  1688,   582,
     526,   564,   349,  -742,   565,  -742,   354,   586,    43,  -742,
    -742,  -742,   589,  -742,  -742,  1688,   591,  -742,  -742,  1688,
    -742,  1688,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
     425,   427,   570,   571,   324,   345,   346,  -742,  -742,  1688,
    1688,  -742,  -742,  1688,   583,  1688,  1688,  -742,  -742,  -742,
    -742,   354,   608,  1688,  -742,  1688,   584,   585,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,   604,  -742,
    -742,  -742,   354,  -742,  -742,  -742,  -742,  1688,  -742,  -742
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     444,     0,   432,     1,   431,     0,     0,     0,   415,     0,
       0,   380,     0,     0,   406,     0,     0,     0,   256,     0,
     365,   369,   366,     0,     0,     0,     0,     0,     0,   407,
     363,     0,     0,     0,   358,   405,     0,     0,     0,   412,
     414,   361,   364,   371,   368,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   428,   436,   433,   440,   442,   445,   356,   357,     0,
       0,   157,   158,   340,     0,     0,     0,   171,   172,   342,
       0,     0,    79,    80,     0,     0,     0,     0,     0,   121,
     122,     0,     0,     0,     0,   112,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   123,     0,     0,     0,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,    44,    49,    50,    51,    52,    53,    54,    57,
      58,     0,    63,    67,    65,     0,     2,    12,    15,    17,
       0,    76,    20,   182,   183,   343,     0,     0,     0,     0,
       0,     0,     0,   151,   152,   339,     0,     0,   214,   215,
     344,     0,   217,   218,   219,   223,   224,   345,   246,   247,
       0,     0,     0,   254,   255,   350,     0,   408,     0,   266,
     353,   262,   263,   409,     0,     0,   229,   230,     0,   233,
     234,   347,     0,   237,   238,   348,     0,   240,   244,   245,
     349,     0,   398,   403,   404,   386,     0,     0,   430,   359,
       0,   227,   228,   346,     0,   269,   270,   351,   264,   265,
     410,   413,   373,     0,     0,   372,   375,   376,   370,     0,
     288,   289,     0,   411,     0,     0,   354,   271,   352,   304,
     310,   420,   390,   381,   391,   320,   326,   384,   385,   330,
     355,   338,   337,   421,   399,   400,   401,   438,   402,     0,
     426,   392,   389,     0,     0,   432,   434,   432,   432,     0,
       0,     0,   168,   165,     0,     0,     0,     0,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      24,    25,    27,    29,    30,    26,    31,   101,    23,     0,
     115,   116,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   117,   120,     0,   118,   119,
      55,    42,    45,    46,    47,    48,    43,    56,    64,   108,
       0,   173,   179,   174,   175,   180,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,   177,   178,     0,     0,   163,   164,   341,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
       0,     0,   204,   205,     0,     0,     0,     0,   201,   200,
     126,     0,     0,     0,   189,   190,     0,     0,     0,     0,
     186,   185,     0,   221,   216,     0,   251,   248,     0,     0,
     281,   285,   283,     0,     0,   367,     0,     0,   236,   235,
     242,   239,     0,   360,     0,     0,     0,   226,   225,     0,
       0,   374,     0,     0,     0,     0,   302,   294,   296,   301,
     298,   303,     0,   300,   308,     0,     0,     0,   394,     0,
     396,     0,   321,     0,     0,   335,   333,   432,   422,     0,
       0,     0,     0,     0,   428,   437,   432,   441,   443,     0,
       0,   155,   153,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      14,     5,     7,     8,     9,    10,     6,     3,     4,    16,
      18,    19,    21,     0,     0,     0,     0,   133,     0,   145,
       0,   137,     0,   141,     0,   129,   202,     0,   209,   208,
     213,   212,   207,   211,   206,   210,     0,   187,     0,   194,
     193,   198,   197,   192,   196,   191,   195,     0,   222,   220,
     252,   249,   253,   250,     0,     0,     0,     0,   257,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   362,     0,
       0,     0,     0,   290,   295,   297,   299,     0,     0,     0,
     311,     0,     0,     0,   323,     0,   322,   327,     0,     0,
     439,   423,     0,   328,     0,   312,     0,     0,   435,   156,
     154,   170,   167,   169,   166,    75,    68,    70,    74,    72,
       0,     0,     0,    78,    77,    82,    81,    84,    83,     0,
       0,     0,     0,     0,    91,    92,    93,   100,     0,    94,
      95,    96,    97,    98,     0,     0,   110,   111,   102,     0,
       0,   106,     0,     0,     0,     0,     0,     0,   161,   159,
     130,   143,   135,   138,   132,   144,   136,   140,     0,     0,
     199,     0,   184,     0,   272,   282,   275,   286,   278,   284,
     258,     0,     0,     0,     0,     0,   387,     0,     0,     0,
       0,   377,   378,     0,   287,     0,     0,     0,   292,     0,
       0,     0,   314,     0,     0,   324,     0,   336,   334,     0,
       0,   393,     0,     0,     0,    69,    71,    73,   124,     0,
       0,     0,     0,     0,     0,     0,     0,   107,   125,     0,
     109,    60,   162,   160,     0,     0,   146,   131,   142,   134,
     139,     0,     0,     0,     0,     0,     0,   260,   259,     0,
     232,   243,   241,     0,     0,     0,     0,   379,     0,     0,
       0,     0,     0,   305,     0,   395,     0,   315,     0,   383,
     397,   325,     0,   329,   313,     0,     0,    85,    86,     0,
      87,     0,    89,    99,   105,   104,    22,    62,   148,   150,
       0,     0,     0,     0,     0,     0,     0,   261,   231,     0,
       0,   268,   267,     0,     0,     0,     0,   309,   293,   307,
     317,     0,   316,     0,   425,     0,     0,     0,   147,   149,
     203,   188,   274,   277,   280,   416,   417,   388,     0,   418,
     291,   318,     0,   427,   429,    88,    90,     0,   319,   419
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -742,   -10,   -67,   -73,   254,  -209,    62,  -742,  -742,  -742,
    -369,  -742,  -742,  -742,   457,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,   475,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -192,  -742,  -189,  -742,  -193,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -667,  -270,  -742,  -742,  -742,  -742,   170,  -523,
    -741,   -54,  -519,  -296,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -264,  -742,  -742,  -742,
    -268,  -742,  -742,  -742
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   625,   146,   147,   148,   149,   150,   306,   307,   151,
     152,   350,   526,   527,   401,   163,   164,   165,    71,    72,
      73,   376,   377,   378,    77,    78,    79,   356,   153,   154,
     155,   168,   169,   170,   175,   176,   177,   221,   222,   223,
     199,   200,   201,   203,   204,   205,   208,   209,   210,   183,
     184,   185,   189,   193,   230,   190,   225,   226,   227,   248,
     695,   763,   697,   764,   699,   765,   187,   584,   586,   585,
     243,   246,   719,   454,   250,   455,   456,   607,   251,   626,
     723,   257,   624,   260,   619,   618,   263,    63,   194,   459,
     471,   611,   613,   273,   470,   274,    64,   476,    65,   275,
      66,   467,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     145,   542,   258,   166,   473,   675,    69,   186,   674,   477,
     478,   475,   309,   198,   335,   374,   211,   212,   380,   157,
     382,   384,   386,   218,   219,   669,   337,   158,   348,   231,
     267,  -306,   268,   420,   268,   238,   446,   242,   234,   269,
     247,   269,   -59,   206,   159,   830,   270,   259,   270,   264,
     781,    88,    88,   784,   351,   352,   214,   171,    74,   279,
    -424,   461,  -424,    75,   282,   284,   286,   423,   446,   172,
     173,   295,   160,   161,   462,   167,   680,   333,   688,   778,
     351,   371,   421,     3,   314,   447,   448,   449,   336,   424,
     851,   334,   721,   681,   724,   757,   450,   689,    67,   729,
     562,   799,   463,    76,   734,   237,   207,   779,    68,   563,
     215,   858,   758,   156,   235,   828,   188,   447,   448,   449,
     174,   682,   683,   522,   422,   353,   354,   355,   450,   800,
     310,   280,   492,   493,   451,   801,   283,   285,   287,   345,
     759,   760,   202,   494,   338,   346,   452,   370,   311,   564,
     749,   353,   354,   372,   453,   349,   711,   236,   565,   540,
     541,   413,   339,   802,   786,   573,   451,    70,   255,   256,
     416,   299,   213,   271,   574,   271,   375,   787,   452,   381,
     162,   383,   385,   387,   425,   426,   453,   341,   261,   262,
     342,   343,   428,   616,   357,   358,   430,   344,   359,   620,
     360,   361,   362,   363,   364,   788,   435,   436,   216,   794,
     437,   793,   628,   368,   272,   369,   272,   604,   605,   379,
     300,   301,   302,   440,   441,   191,   575,   192,   606,   303,
     304,   305,   217,   414,   444,   576,   220,   389,   390,   224,
    -332,   228,   417,   229,  -332,   391,  -332,   265,   266,   392,
     393,   178,   179,   180,   181,   465,  -331,   466,   394,   468,
    -331,   232,  -331,   182,   429,   357,   358,   395,   431,   396,
     397,   481,   558,   559,   560,   561,   569,   570,   398,   399,
     571,   572,   438,   365,   529,   530,   496,   498,   500,   400,
     233,   366,   531,   532,   533,   534,   535,   536,   537,   538,
     746,   239,   503,   504,   244,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   727,   728,   389,   402,   245,   249,   276,   252,
     253,   277,   403,   254,   278,   281,   404,   405,   288,   296,
     297,   298,   308,   482,   312,   406,   313,   315,   316,   317,
     318,   319,   320,   321,   407,   322,   408,   409,   497,   499,
     501,   367,   323,   324,   543,   410,   411,   325,   326,   327,
     328,   329,   330,   331,   332,   340,   400,   347,   370,    88,
     556,   388,   415,   427,   432,   434,   439,   418,   419,   433,
     442,   443,   445,   457,   458,  -382,   464,   469,   460,   472,
     479,   480,   487,   483,   484,   578,   524,   614,   580,   582,
     617,   546,   587,   488,   489,   485,   486,   590,   490,   545,
     588,   502,   591,   491,   593,   495,   523,   525,   -61,   596,
     528,   548,   600,   550,   552,   603,   544,   554,   557,   589,
     566,   568,   547,   594,   549,   577,   551,   595,   553,   598,
     555,   599,   601,   602,   608,   609,   612,   615,   622,   621,
     627,   623,   629,   630,   567,   640,   635,   636,   637,   638,
     639,   650,   641,   631,   642,   633,   643,   579,   644,   651,
     581,   583,   645,   646,   647,   652,   648,   653,   654,   655,
     656,   657,   649,   658,   592,   659,   660,   661,   662,   664,
     663,   597,   665,   666,   667,   668,   671,   673,   670,   694,
     676,   677,   701,   703,   706,   672,   704,   623,   832,   705,
     709,   710,   716,   717,   713,   720,   726,   730,   732,   731,
     696,   698,   700,   714,   761,   678,   718,   733,   735,   722,
     738,   754,   747,   736,   748,   737,   632,   690,   634,   750,
     756,   751,   755,   752,   753,   762,   691,  -273,  -276,  -279,
     766,   725,   769,   773,   774,   782,   783,   785,   792,   789,
     790,   796,   795,   797,   798,   803,   804,   805,   806,   702,
     807,   814,   810,   808,   707,   708,   809,   815,   816,   811,
     819,   820,   715,   831,   823,   825,   821,   822,   826,   827,
     829,   623,   833,   623,   835,   840,   841,   679,   259,   259,
     684,   838,   685,   839,   686,   852,   687,   857,   848,   855,
     856,   539,   842,   844,   412,   373,   843,   610,     0,     0,
     692,     0,     0,     0,     0,     0,     0,     0,     0,   693,
     739,   740,   741,   742,     0,     0,     0,     0,   743,     0,
       0,     0,     0,     0,   744,   745,     0,     0,     0,     0,
       0,   712,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   791,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   767,     0,   770,   771,     0,     0,     0,     0,   775,
       0,     0,     0,   777,     0,     0,   780,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     623,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   812,     0,     0,     0,     0,   817,     0,     0,   818,
       0,     0,     0,   768,     0,     0,     0,   772,   824,     0,
       0,     0,   776,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   834,     0,     0,     0,   836,
       0,   837,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   845,
     846,     4,     0,   847,     0,   849,   850,     0,     5,     6,
       0,     0,     0,   853,   813,   854,     0,     0,     0,     0,
       7,     8,     0,     9,     0,    10,    11,     0,    12,    13,
       0,     0,     0,     0,     0,     0,    14,   859,    15,    16,
      17,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,    28,    29,     0,    30,
       0,     0,    31,    32,    33,     0,    34,    35,    36,    37,
      38,    39,    40,     0,    41,     0,     0,     0,    42,    43,
      44,    45,    46,     0,    47,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,    50,     0,     0,
      51,     0,    52,    53,    54,     0,     0,    55,     0,     0,
       0,    56,     0,    57,     4,     0,     0,    58,    59,    60,
       0,     5,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     9,     0,    10,    11,
       0,    12,    13,    61,     0,    62,     0,     0,     0,    14,
       0,    15,    16,    17,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,    28,
      29,     0,    30,     0,     0,    31,    32,    33,     0,    34,
      35,    36,    37,    38,    39,    40,     0,    41,     0,     0,
       0,    42,    43,    44,    45,    46,     0,    47,    48,     0,
       0,     0,     0,    80,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,   289,
      50,     0,     0,    51,     0,    52,    53,    54,    81,     0,
      55,     0,     0,     0,    56,     0,    57,     0,     0,     0,
      58,    59,    60,     0,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,    86,     0,   474,    87,   290,   291,
     292,     0,     0,     0,     0,     0,     0,    89,    90,   293,
      91,     0,     0,     0,     0,     0,     0,     0,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,     0,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,   111,   294,
     112,   113,   114,     0,   115,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,     0,
     118,     0,     0,     0,   119,     0,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    80,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,     0,     0,   195,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,   196,   197,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
      86,     0,     0,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90,     0,    91,     0,     0,     0,
       0,     0,     0,     0,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,   109,   110,   111,     0,   112,   113,   114,     0,
     115,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,     0,   118,     0,     0,     0,
     119,     0,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    80,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,   240,   241,
       0,     0,     0,     0,     0,     0,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,    86,     0,     0,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      90,     0,    91,     0,     0,     0,     0,     0,     0,     0,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,     0,     0,     0,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,   109,   110,
     111,     0,   112,   113,   114,     0,   115,   116,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,     0,
     117,     0,   118,     0,     0,     0,   119,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    81,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,     0,     0,     0,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,     0,     0,    86,     0,     0,
      87,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,     0,    91,     0,     0,     0,     0,     0,     0,
       0,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,     0,     0,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,     0,     0,     0,   109,
     110,   111,     0,   112,   113,   114,     0,   115,   116,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
       0,   117,     0,   118,     0,     0,     0,   119,     0,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    81,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,     0,     0,     0,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,    86,     0,
       0,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,    90,     0,    91,     0,     0,     0,     0,     0,
       0,     0,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,     0,     0,
       0,     0,     0,     0,     0,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,     0,     0,     0,
     109,   110,   111,     0,   112,   113,   114,     0,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,   117,     0,   118,     0,     0,     0,   119,     0,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    81,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     0,     0,     0,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,     0,     0,    86,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,    90,     0,    91,     0,     0,     0,     0,
       0,     0,     0,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,     0,
       0,     0,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   109,   110,   111,     0,   112,   113,   114,     0,   115,
     116,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,   117,     0,   118,     0,     0,     0,   119,
       0,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    81,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,     0,     0,     0,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
      86,     0,     0,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90,     0,    91,     0,     0,     0,
       0,     0,     0,     0,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,   109,   110,   111,     0,   112,   113,   114,     0,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,     0,   118,     0,     0,     0,
     119,     0,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,     0,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144
};

static const yytype_int16 yycheck[] =
{
      10,   370,    56,    13,   274,   528,    24,    17,   527,   277,
     278,   275,    20,    23,    86,    24,    26,    27,    24,    24,
      24,    24,    24,    33,    34,     7,    20,    32,    20,    39,
       4,    20,     6,    53,     6,    45,    25,    47,    68,    13,
      50,    13,    34,    24,    49,   786,    20,    57,    20,    59,
     717,    82,    82,   720,    79,    80,    90,    24,    26,    69,
      34,     7,    34,    31,    74,    75,    76,    20,    25,    36,
      37,    81,    77,    78,    20,    13,    32,    20,    29,     7,
      79,    80,   102,     0,    94,    74,    75,    76,   160,    42,
     831,    34,   611,    49,   613,    32,    85,    48,   185,   622,
      45,     7,    48,    71,   627,    43,    87,    35,   185,    54,
     144,   852,    49,    22,   144,   782,   185,    74,    75,    76,
      87,    77,    78,   332,   144,   150,   151,   152,    85,    35,
     138,    69,    74,    75,   123,     7,    74,    75,    76,   168,
      77,    78,    24,    85,   138,   174,   135,   129,   156,    45,
     673,   150,   151,   152,   143,   147,   187,   187,    54,   368,
     369,   171,   156,    35,     7,    45,   123,   185,   185,   186,
     180,    25,    90,   147,    54,   147,   185,    20,   135,   185,
     185,   185,   185,   185,   194,   195,   143,   164,   157,   158,
     167,   168,   202,   463,     8,     9,   206,   174,    12,   467,
      14,    15,    16,    17,    18,    48,   216,   217,    34,   732,
     220,   730,   476,    19,   188,    21,   188,    74,    75,   157,
      74,    75,    76,   233,   234,   185,    45,   187,    85,    83,
      84,    85,    34,   171,   244,    54,    24,    24,    25,    24,
       0,   185,   180,   187,     4,    32,     6,    42,    43,    36,
      37,    42,    43,    44,    45,     5,     0,     7,    45,   269,
       4,   144,     6,    54,   202,     8,     9,    54,   206,    56,
      57,   281,    56,    57,    56,    57,    56,    57,    65,    66,
      56,    57,   220,    97,   357,   358,   296,   297,   298,    76,
      68,   105,   359,   360,   361,   362,   363,   364,   365,   366,
     669,   185,   312,   313,    34,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   618,   619,    24,    25,   185,   185,     6,   185,
     185,     4,    32,   185,     4,    24,    36,    37,   187,    34,
      34,    34,   187,   281,    34,    45,    34,    34,    34,    34,
      34,    34,    34,    34,    54,    34,    56,    57,   296,   297,
     298,   130,    34,    34,   374,    65,    66,    34,    34,    34,
      34,    34,    34,    34,    34,   167,    76,   167,   129,    82,
     390,    24,    29,     7,    29,   147,    34,    46,    46,    69,
      13,   152,     7,     7,   147,   147,     7,    13,   147,    34,
      29,    29,    35,    72,    72,   415,   185,   461,   418,   419,
     464,    48,    42,    35,    35,    72,    72,   427,    35,    24,
     185,    34,   432,    35,   434,    35,    34,    34,    34,   439,
      34,    24,   442,    24,    24,   445,   374,    24,    33,     7,
      34,    33,   380,     7,   382,    34,   384,     7,   386,    69,
     388,     7,   102,     7,    34,    20,   147,     7,    34,   469,
      34,   471,   185,   185,   402,    35,   187,   187,   187,   187,
     187,     7,    35,   483,    35,   485,    35,   415,    35,     7,
     418,   419,    35,    35,    35,     7,    35,     7,    35,    35,
      35,    35,   502,     7,   432,    35,    35,    35,    35,     7,
      35,   439,     7,    35,    35,    35,    35,    34,   185,   185,
      29,    29,    13,     7,   148,   525,    42,   527,   788,    42,
       7,     7,     7,    34,    72,    34,     7,     7,     7,   148,
     185,   185,   185,   185,     7,   545,   187,    35,   187,   185,
      35,    29,    35,   187,    35,   187,   484,   557,   486,   148,
     186,    35,    29,   185,   185,     7,   566,     7,     7,     7,
      13,   615,     7,    35,    35,     7,    35,   148,    35,   148,
     148,    35,    13,    35,    35,    35,    35,    35,    35,   589,
      35,     7,    29,   186,   594,   595,   186,     7,     7,    29,
      13,    13,   602,     7,   115,    13,    35,    35,    72,    35,
      35,   611,    13,   613,    13,    35,    35,   545,   618,   619,
     548,   186,   550,   186,   552,     7,   554,    13,    35,    35,
      35,   367,   814,   816,   167,   150,   815,   457,    -1,    -1,
     568,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   577,
     650,   651,   652,   653,    -1,    -1,    -1,    -1,   658,    -1,
      -1,    -1,    -1,    -1,   664,   665,    -1,    -1,    -1,    -1,
      -1,   599,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   726,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   701,    -1,   703,   704,    -1,    -1,    -1,    -1,   709,
      -1,    -1,    -1,   713,    -1,    -1,   716,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     730,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   761,    -1,    -1,    -1,    -1,   766,    -1,    -1,   769,
      -1,    -1,    -1,   701,    -1,    -1,    -1,   705,   778,    -1,
      -1,    -1,   710,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   795,    -1,    -1,    -1,   799,
      -1,   801,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   819,
     820,     3,    -1,   823,    -1,   825,   826,    -1,    10,    11,
      -1,    -1,    -1,   833,   762,   835,    -1,    -1,    -1,    -1,
      22,    23,    -1,    25,    -1,    27,    28,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,   857,    40,    41,
      42,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    88,    89,    -1,    91,
      -1,    -1,    94,    95,    96,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,    -1,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     142,    -1,   144,   145,   146,    -1,    -1,   149,    -1,    -1,
      -1,   153,    -1,   155,     3,    -1,    -1,   159,   160,   161,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    -1,    25,    -1,    27,    28,
      -1,    30,    31,   185,    -1,   187,    -1,    -1,    -1,    38,
      -1,    40,    41,    42,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    88,
      89,    -1,    91,    -1,    -1,    94,    95,    96,    -1,    98,
      99,   100,   101,   102,   103,   104,    -1,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,    -1,   116,   117,    -1,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    25,
     139,    -1,    -1,   142,    -1,   144,   145,   146,    34,    -1,
     149,    -1,    -1,    -1,   153,    -1,   155,    -1,    -1,    -1,
     159,   160,   161,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    70,    -1,   185,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,   132,   133,   134,   135,
     136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
     156,    -1,    -1,    -1,   160,    -1,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,     9,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,   132,   133,   134,    -1,   136,   137,   138,    -1,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,    -1,
     160,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,     9,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,   132,   133,
     134,    -1,   136,   137,   138,    -1,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
     154,    -1,   156,    -1,    -1,    -1,   160,    -1,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    34,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      -1,   154,    -1,   156,    -1,    -1,    -1,   160,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    34,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,   137,   138,    -1,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,   154,    -1,   156,    -1,    -1,    -1,   160,    -1,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    34,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,   137,   138,    -1,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      -1,    -1,    -1,   154,    -1,   156,    -1,    -1,    -1,   160,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    34,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,   132,   133,   134,    -1,   136,   137,   138,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,    -1,
     160,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   291,   292,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    86,    88,    89,
      91,    94,    95,    96,    98,    99,   100,   101,   102,   103,
     104,   106,   110,   111,   112,   113,   114,   116,   117,   131,
     139,   142,   144,   145,   146,   149,   153,   155,   159,   160,
     161,   185,   187,   276,   285,   287,   289,   185,   185,    24,
     185,   207,   208,   209,    26,    31,    71,   213,   214,   215,
       9,    34,    50,    51,    52,    67,    70,    73,    82,    83,
      84,    86,    94,    95,   107,   108,   109,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   132,
     133,   134,   136,   137,   138,   140,   141,   154,   156,   160,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   190,   191,   192,   193,   194,
     195,   198,   199,   217,   218,   219,    22,    24,    32,    49,
      77,    78,   185,   204,   205,   206,   190,   195,   220,   221,
     222,    24,    36,    37,    87,   223,   224,   225,    42,    43,
      44,    45,    54,   238,   239,   240,   190,   255,   185,   241,
     244,   185,   187,   242,   277,    24,    36,    37,   190,   229,
     230,   231,    24,   232,   233,   234,    24,    87,   235,   236,
     237,   190,   190,    90,    90,   144,    34,    34,   190,   190,
      24,   226,   227,   228,    24,   245,   246,   247,   185,   187,
     243,   190,   144,    68,    68,   144,   187,   195,   190,   185,
      42,    43,   190,   259,    34,   185,   260,   190,   248,   185,
     263,   267,   185,   185,   185,   185,   186,   270,   270,   190,
     272,   157,   158,   275,   190,    42,    43,     4,     6,    13,
      20,   147,   188,   282,   284,   288,     6,     4,     4,   190,
     195,    24,   190,   195,   190,   195,   190,   195,   187,    25,
      74,    75,    76,    85,   135,   190,    34,    34,    34,    25,
      74,    75,    76,    83,    84,    85,   196,   197,   187,    20,
     138,   156,    34,    34,   190,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    20,    34,    86,   160,    20,   138,   156,
     167,   164,   167,   168,   174,   168,   174,   167,    20,   147,
     200,    79,    80,   150,   151,   152,   216,     8,     9,    12,
      14,    15,    16,    17,    18,    97,   105,   130,    19,    21,
     129,    80,   152,   216,    24,   185,   210,   211,   212,   195,
      24,   185,    24,   185,    24,   185,    24,   185,    24,    24,
      25,    32,    36,    37,    45,    54,    56,    57,    65,    66,
      76,   203,    25,    32,    36,    37,    45,    54,    56,    57,
      65,    66,   203,   190,   195,    29,   190,   195,    46,    46,
      53,   102,   144,    20,    42,   190,   190,     7,   190,   195,
     190,   195,    29,    69,   147,   190,   190,   190,   195,    34,
     190,   190,    13,   152,   190,     7,    25,    74,    75,    76,
      85,   123,   135,   143,   262,   264,   265,     7,   147,   278,
     147,     7,    20,    48,     7,     5,     7,   290,   190,    13,
     283,   279,    34,   262,   185,   285,   286,   289,   289,    29,
      29,   190,   195,    72,    72,    72,    72,    35,    35,    35,
      35,    35,    74,    75,    85,    35,   190,   195,   190,   195,
     190,   195,    34,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   194,    34,   185,    34,   201,   202,    34,   192,
     192,   191,   191,   191,   191,   191,   191,   191,   191,   193,
     194,   194,   199,   190,   195,    24,    48,   195,    24,   195,
      24,   195,    24,   195,    24,   195,   190,    33,    56,    57,
      56,    57,    45,    54,    45,    54,    34,   195,    33,    56,
      57,    56,    57,    45,    54,    45,    54,    34,   190,   195,
     190,   195,   190,   195,   256,   258,   257,    42,   185,     7,
     190,   190,   195,   190,     7,     7,   190,   195,    69,     7,
     190,   102,     7,   190,    74,    75,    85,   266,    34,    20,
     267,   280,   147,   281,   270,     7,   262,   270,   274,   273,
     289,   190,    34,   190,   271,   190,   268,    34,   285,   185,
     185,   190,   195,   190,   195,   187,   187,   187,   187,   187,
      35,    35,    35,    35,    35,    35,    35,    35,    35,   190,
       7,     7,     7,     7,    35,    35,    35,    35,     7,    35,
      35,    35,    35,    35,     7,     7,    35,    35,    35,     7,
     185,    35,   190,    34,   271,   268,    29,    29,   190,   195,
      32,    49,    77,    78,   195,   195,   195,   195,    29,    48,
     190,   190,   195,   195,   185,   249,   185,   251,   185,   253,
     185,    13,   190,     7,    42,    42,   148,   190,   190,     7,
       7,   187,   195,    72,   185,   190,     7,    34,   187,   261,
      34,   271,   185,   269,   271,   270,     7,   272,   272,   268,
       7,   148,     7,    35,   268,   187,   187,   187,    35,   190,
     190,   190,   190,   190,   190,   190,   199,    35,    35,   268,
     148,    35,   185,   185,    29,    29,   186,    32,    49,    77,
      78,     7,     7,   250,   252,   254,    13,   190,   195,     7,
     190,   190,   195,    35,    35,   190,   195,   190,     7,    35,
     190,   261,     7,    35,   261,   148,     7,    20,    48,   148,
     148,   270,    35,   271,   268,    13,    35,    35,    35,     7,
      35,     7,    35,    35,    35,    35,    35,    35,   186,   186,
      29,    29,   190,   195,     7,     7,     7,   190,   190,    13,
      13,    35,    35,   115,   190,    13,    72,    35,   261,    35,
     269,     7,   262,    13,   190,    13,   190,   190,   186,   186,
      35,    35,   249,   251,   253,   190,   190,   190,    35,   190,
     190,   269,     7,   190,   190,    35,    35,    13,   269,   190
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   189,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   191,   191,   191,   192,   192,   193,   193,   193,
     194,   194,   194,   195,   196,   196,   196,   196,   196,   196,
     196,   197,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   200,
     199,   201,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   202,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   203,   203,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   205,   205,   205,   205,
     205,   206,   206,   207,   207,   208,   208,   209,   209,   210,
     210,   211,   211,   212,   212,   213,   213,   213,   214,   214,
     214,   215,   215,   216,   216,   216,   217,   217,   217,   218,
     218,   218,   219,   219,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   222,   222,   223,   223,   223,   223,
     223,   224,   224,   225,   225,   226,   227,   228,   228,   229,
     229,   230,   230,   231,   231,   232,   233,   234,   234,   235,
     235,   235,   236,   236,   237,   237,   238,   238,   238,   238,
     238,   239,   239,   239,   240,   240,   241,   241,   241,   241,
     241,   241,   242,   242,   243,   243,   244,   245,   246,   247,
     247,   248,   249,   250,   249,   251,   252,   251,   253,   254,
     253,   256,   255,   257,   255,   258,   255,   259,   259,   259,
     260,   260,   261,   261,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   264,   263,   265,   263,   266,   263,
     267,   267,   268,   268,   269,   269,   269,   269,   269,   269,
     270,   270,   270,   270,   270,   270,   270,   270,   271,   271,
     272,   272,   272,   273,   272,   274,   272,   275,   275,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   277,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   278,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   279,   276,   280,   276,   281,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   282,   276,   283,   276,   284,   276,
     276,   276,   276,   285,   286,   285,   288,   287,   290,   289,
     289,   289,   289,   289,   292,   291
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
       4,     2,     4,     3,     6,     6,     4,     5,     0,     5,
       4,     4,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     5,     5,     1,     1,     2,     3,
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
       1,     6,     5,     1,     1,     2,     2,     1,     1,     2,
       1,     5,     2,     5,     1,     1,     1,     1,     2,     3,
       3,     2,     3,     3,     1,     1,     0,     3,     4,     5,
       5,     6,     1,     1,     1,     1,     1,     6,     6,     1,
       1,     1,     1,     0,     4,     1,     0,     4,     1,     0,
       4,     0,     4,     0,     4,     0,     4,     4,     1,     1,
       3,     7,     1,     3,     1,     2,     1,     2,     1,     2,
       1,     1,     1,     1,     0,     5,     0,     6,     0,     6,
       1,     3,     1,     3,     1,     2,     3,     3,     4,     5,
       1,     2,     3,     3,     4,     5,     1,     3,     1,     3,
       1,     2,     2,     0,     4,     0,     4,     1,     1,     2,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       3,     1,     4,     1,     1,     1,     0,     3,     1,     1,
       2,     1,     2,     2,     3,     2,     2,     5,     5,     6,
       1,     2,     0,     6,     2,     2,     2,     5,     8,     2,
       2,     2,     0,     5,     0,     6,     0,     6,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     2,     2,
       2,     2,     1,     2,     1,     1,     8,     8,     8,    10,
       2,     2,     3,     4,     0,     7,     0,     8,     0,     8,
       2,     1,     0,     1,     0,     4,     0,     3,     0,     4,
       1,     3,     1,     3,     0,     2
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
#line 74 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2650 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 78 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2659 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 82 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2667 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 85 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2675 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 88 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2683 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 91 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2691 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 94 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2699 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 97 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2707 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 100 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2715 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 107 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2723 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 110 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2732 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 123 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2741 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 127 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2750 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 135 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2759 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 139 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 2768 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 146 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2776 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 151 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2784 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 154 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2792 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 157 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2800 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 160 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2808 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 163 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2816 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 166 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2824 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 169 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2832 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 174 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2840 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 179 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2849 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 183 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2858 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 187 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2867 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 191 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2876 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 195 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2885 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 199 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2894 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 203 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2903 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 207 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2912 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 211 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2921 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 215 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2930 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 219 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2939 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 223 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2948 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 227 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2957 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 231 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2966 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 235 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2975 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 239 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2984 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 243 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2993 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 247 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3002 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 251 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3011 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 255 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3020 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 259 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3029 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 263 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3038 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 267 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3047 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 271 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3056 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 275 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3065 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 279 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3074 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 283 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3083 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 289 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3092 "src-generated/ugbc.tab.c"
    break;

  case 60: /* exponential: Identifier $@1 OP indexes CP  */
#line 293 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-4].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-4].string) )->name;
    }
#line 3104 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 300 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3113 "src-generated/ugbc.tab.c"
    break;

  case 62: /* exponential: Identifier DOLLAR $@2 OP indexes CP  */
#line 304 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-5].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-5].string) )->name;
    }
#line 3125 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 311 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3133 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 314 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3141 "src-generated/ugbc.tab.c"
    break;

  case 65: /* exponential: Integer  */
#line 317 "src/ugbc.y"
              { 
        if ( (yyvsp[0].integer) < 0 ) {
            (yyval.string) = variable_temporary( _environment, VT_SWORD, "(signed integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        } else {
            (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        }
      }
#line 3155 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 326 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3164 "src-generated/ugbc.tab.c"
    break;

  case 67: /* exponential: String  */
#line 330 "src/ugbc.y"
             { 
        outline1("; (expr string: \"%s\")", (yyvsp[0].string) );
        (yyval.string) = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", (yyval.string) );
        variable_store_string( _environment, (yyval.string), (yyvsp[0].string) );
        outline2("; variable stored: %s = %s", (yyval.string), (yyvsp[0].string) );
      }
#line 3176 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 337 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3185 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 341 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3194 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 345 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3203 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 349 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3212 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 353 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3221 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 357 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3230 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 361 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3239 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 365 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3248 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 369 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3256 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 372 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3264 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 375 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3272 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 378 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3280 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 381 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3288 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 384 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3296 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 387 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3304 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 390 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3312 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 393 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3320 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 396 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3328 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 399 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3336 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 402 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3344 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 405 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3352 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 408 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3360 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 411 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3368 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 414 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3376 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 417 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3384 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 420 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3392 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 423 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3400 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 426 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3408 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 429 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3416 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 432 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3424 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 435 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3432 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 438 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3440 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 441 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3448 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 444 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3456 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 447 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3464 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 450 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3472 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 453 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3480 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 456 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3488 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 459 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3496 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 462 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3504 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 465 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3512 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 467 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3521 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 471 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3529 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 474 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3537 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 477 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3546 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 481 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3555 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 485 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3564 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: PEN COLORS  */
#line 489 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3573 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: PEN DEFAULT  */
#line 493 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3582 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: DEFAULT PEN  */
#line 497 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3591 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: PAPER COLORS  */
#line 501 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3600 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: PAPER DEFAULT  */
#line 505 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3609 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: DEFAULT PAPER  */
#line 509 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3618 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: WIDTH  */
#line 513 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3626 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: HEIGHT  */
#line 516 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3634 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: TIMER  */
#line 519 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3642 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PEN DOLLAR OP expr CP  */
#line 522 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 3650 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER DOLLAR OP expr CP  */
#line 525 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3658 "src-generated/ugbc.tab.c"
    break;

  case 128: /* bank_definition_simple: AT direct_integer  */
#line 533 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3666 "src-generated/ugbc.tab.c"
    break;

  case 129: /* bank_definition_simple: Identifier AT direct_integer  */
#line 536 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3674 "src-generated/ugbc.tab.c"
    break;

  case 130: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 539 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3682 "src-generated/ugbc.tab.c"
    break;

  case 131: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 542 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3690 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 545 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3698 "src-generated/ugbc.tab.c"
    break;

  case 133: /* bank_definition_simple: DATA AT direct_integer  */
#line 548 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3706 "src-generated/ugbc.tab.c"
    break;

  case 134: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 552 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3714 "src-generated/ugbc.tab.c"
    break;

  case 135: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 555 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3722 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 558 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3730 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bank_definition_simple: CODE AT direct_integer  */
#line 561 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3738 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 565 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3746 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 568 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3754 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 571 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3762 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 574 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3770 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 578 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3778 "src-generated/ugbc.tab.c"
    break;

  case 143: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 581 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3786 "src-generated/ugbc.tab.c"
    break;

  case 144: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 584 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3794 "src-generated/ugbc.tab.c"
    break;

  case 145: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 587 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3802 "src-generated/ugbc.tab.c"
    break;

  case 146: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 593 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3810 "src-generated/ugbc.tab.c"
    break;

  case 147: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 596 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3818 "src-generated/ugbc.tab.c"
    break;

  case 148: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 599 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3826 "src-generated/ugbc.tab.c"
    break;

  case 149: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 602 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3834 "src-generated/ugbc.tab.c"
    break;

  case 150: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 605 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3842 "src-generated/ugbc.tab.c"
    break;

  case 153: /* raster_definition_simple: Identifier AT direct_integer  */
#line 614 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3850 "src-generated/ugbc.tab.c"
    break;

  case 154: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 617 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3858 "src-generated/ugbc.tab.c"
    break;

  case 155: /* raster_definition_expression: Identifier AT expr  */
#line 622 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3866 "src-generated/ugbc.tab.c"
    break;

  case 156: /* raster_definition_expression: AT expr WITH Identifier  */
#line 625 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3874 "src-generated/ugbc.tab.c"
    break;

  case 159: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 634 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3882 "src-generated/ugbc.tab.c"
    break;

  case 160: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 637 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3890 "src-generated/ugbc.tab.c"
    break;

  case 161: /* next_raster_definition_expression: Identifier AT expr  */
#line 642 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3898 "src-generated/ugbc.tab.c"
    break;

  case 162: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 645 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3906 "src-generated/ugbc.tab.c"
    break;

  case 165: /* color_definition_simple: BORDER direct_integer  */
#line 654 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3914 "src-generated/ugbc.tab.c"
    break;

  case 166: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 657 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3922 "src-generated/ugbc.tab.c"
    break;

  case 167: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 660 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3930 "src-generated/ugbc.tab.c"
    break;

  case 168: /* color_definition_expression: BORDER expr  */
#line 665 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3938 "src-generated/ugbc.tab.c"
    break;

  case 169: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 668 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3946 "src-generated/ugbc.tab.c"
    break;

  case 170: /* color_definition_expression: SPRITE expr TO expr  */
#line 671 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3954 "src-generated/ugbc.tab.c"
    break;

  case 176: /* wait_definition_simple: direct_integer CYCLES  */
#line 685 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3962 "src-generated/ugbc.tab.c"
    break;

  case 177: /* wait_definition_simple: direct_integer TICKS  */
#line 688 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3970 "src-generated/ugbc.tab.c"
    break;

  case 178: /* wait_definition_simple: direct_integer milliseconds  */
#line 691 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3978 "src-generated/ugbc.tab.c"
    break;

  case 179: /* wait_definition_expression: expr CYCLES  */
#line 696 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3986 "src-generated/ugbc.tab.c"
    break;

  case 180: /* wait_definition_expression: expr TICKS  */
#line 699 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3994 "src-generated/ugbc.tab.c"
    break;

  case 181: /* wait_definition_expression: expr milliseconds  */
#line 702 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4002 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 712 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4010 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 715 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4018 "src-generated/ugbc.tab.c"
    break;

  case 186: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 718 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4026 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 721 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4034 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 724 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4042 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_simple: direct_integer ENABLE  */
#line 727 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4050 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_simple: direct_integer DISABLE  */
#line 730 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4058 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 733 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4066 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 736 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4074 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 739 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4082 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 742 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4090 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 745 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4098 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 748 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4106 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 751 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4114 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 754 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4122 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_expression: expr DATA FROM expr  */
#line 759 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4130 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_expression: expr MULTICOLOR  */
#line 762 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4138 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_expression: expr MONOCOLOR  */
#line 765 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4146 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_expression: expr COLOR expr  */
#line 768 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4154 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 771 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4162 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_expression: expr ENABLE  */
#line 774 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4170 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_expression: expr DISABLE  */
#line 777 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4178 "src-generated/ugbc.tab.c"
    break;

  case 206: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 780 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4186 "src-generated/ugbc.tab.c"
    break;

  case 207: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 783 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4194 "src-generated/ugbc.tab.c"
    break;

  case 208: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 786 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4202 "src-generated/ugbc.tab.c"
    break;

  case 209: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 789 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4210 "src-generated/ugbc.tab.c"
    break;

  case 210: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 792 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4218 "src-generated/ugbc.tab.c"
    break;

  case 211: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 795 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4226 "src-generated/ugbc.tab.c"
    break;

  case 212: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 798 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4234 "src-generated/ugbc.tab.c"
    break;

  case 213: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 801 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4242 "src-generated/ugbc.tab.c"
    break;

  case 216: /* bitmap_definition_simple: AT direct_integer  */
#line 810 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4250 "src-generated/ugbc.tab.c"
    break;

  case 217: /* bitmap_definition_simple: ENABLE  */
#line 813 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4258 "src-generated/ugbc.tab.c"
    break;

  case 218: /* bitmap_definition_simple: DISABLE  */
#line 816 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4266 "src-generated/ugbc.tab.c"
    break;

  case 219: /* bitmap_definition_simple: CLEAR  */
#line 819 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4274 "src-generated/ugbc.tab.c"
    break;

  case 220: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 822 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4282 "src-generated/ugbc.tab.c"
    break;

  case 221: /* bitmap_definition_expression: AT expr  */
#line 828 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4290 "src-generated/ugbc.tab.c"
    break;

  case 222: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 831 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4298 "src-generated/ugbc.tab.c"
    break;

  case 225: /* textmap_definition_simple: AT direct_integer  */
#line 841 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4306 "src-generated/ugbc.tab.c"
    break;

  case 226: /* textmap_definition_expression: AT expr  */
#line 846 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4314 "src-generated/ugbc.tab.c"
    break;

  case 229: /* text_definition_simple: ENABLE  */
#line 855 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4322 "src-generated/ugbc.tab.c"
    break;

  case 230: /* text_definition_simple: DISABLE  */
#line 858 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4330 "src-generated/ugbc.tab.c"
    break;

  case 231: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 863 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4338 "src-generated/ugbc.tab.c"
    break;

  case 232: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 866 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4346 "src-generated/ugbc.tab.c"
    break;

  case 235: /* tiles_definition_simple: AT direct_integer  */
#line 875 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4354 "src-generated/ugbc.tab.c"
    break;

  case 236: /* tiles_definition_expression: AT expr  */
#line 880 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4362 "src-generated/ugbc.tab.c"
    break;

  case 239: /* colormap_definition_simple: AT direct_integer  */
#line 889 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4370 "src-generated/ugbc.tab.c"
    break;

  case 240: /* colormap_definition_simple: CLEAR  */
#line 892 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4378 "src-generated/ugbc.tab.c"
    break;

  case 241: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 895 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4386 "src-generated/ugbc.tab.c"
    break;

  case 242: /* colormap_definition_expression: AT expr  */
#line 900 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4394 "src-generated/ugbc.tab.c"
    break;

  case 243: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 903 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4402 "src-generated/ugbc.tab.c"
    break;

  case 246: /* screen_definition_simple: ON  */
#line 913 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4410 "src-generated/ugbc.tab.c"
    break;

  case 247: /* screen_definition_simple: OFF  */
#line 916 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4418 "src-generated/ugbc.tab.c"
    break;

  case 248: /* screen_definition_simple: ROWS direct_integer  */
#line 919 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4426 "src-generated/ugbc.tab.c"
    break;

  case 249: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 922 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4434 "src-generated/ugbc.tab.c"
    break;

  case 250: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 925 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4442 "src-generated/ugbc.tab.c"
    break;

  case 251: /* screen_definition_expression: ROWS expr  */
#line 930 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4450 "src-generated/ugbc.tab.c"
    break;

  case 252: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 933 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4458 "src-generated/ugbc.tab.c"
    break;

  case 253: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 936 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4466 "src-generated/ugbc.tab.c"
    break;

  case 257: /* var_definition_simple: Identifier ON Identifier  */
#line 945 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4474 "src-generated/ugbc.tab.c"
    break;

  case 258: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 948 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4482 "src-generated/ugbc.tab.c"
    break;

  case 259: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 951 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4490 "src-generated/ugbc.tab.c"
    break;

  case 260: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 954 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4500 "src-generated/ugbc.tab.c"
    break;

  case 261: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 959 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4510 "src-generated/ugbc.tab.c"
    break;

  case 262: /* goto_definition: Identifier  */
#line 966 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4518 "src-generated/ugbc.tab.c"
    break;

  case 263: /* goto_definition: Integer  */
#line 969 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4526 "src-generated/ugbc.tab.c"
    break;

  case 264: /* gosub_definition: Identifier  */
#line 975 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4534 "src-generated/ugbc.tab.c"
    break;

  case 265: /* gosub_definition: Integer  */
#line 978 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4542 "src-generated/ugbc.tab.c"
    break;

  case 267: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 987 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4550 "src-generated/ugbc.tab.c"
    break;

  case 268: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 993 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4558 "src-generated/ugbc.tab.c"
    break;

  case 271: /* ink_definition: expr  */
#line 1002 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4566 "src-generated/ugbc.tab.c"
    break;

  case 272: /* on_goto_definition: Identifier  */
#line 1007 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4575 "src-generated/ugbc.tab.c"
    break;

  case 273: /* $@4: %empty  */
#line 1011 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4583 "src-generated/ugbc.tab.c"
    break;

  case 275: /* on_gosub_definition: Identifier  */
#line 1016 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4592 "src-generated/ugbc.tab.c"
    break;

  case 276: /* $@5: %empty  */
#line 1020 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4600 "src-generated/ugbc.tab.c"
    break;

  case 278: /* on_proc_definition: Identifier  */
#line 1025 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4609 "src-generated/ugbc.tab.c"
    break;

  case 279: /* $@6: %empty  */
#line 1029 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4617 "src-generated/ugbc.tab.c"
    break;

  case 281: /* $@7: %empty  */
#line 1034 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4625 "src-generated/ugbc.tab.c"
    break;

  case 283: /* $@8: %empty  */
#line 1037 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4633 "src-generated/ugbc.tab.c"
    break;

  case 285: /* $@9: %empty  */
#line 1040 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4641 "src-generated/ugbc.tab.c"
    break;

  case 287: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1045 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4649 "src-generated/ugbc.tab.c"
    break;

  case 288: /* every_definition: ON  */
#line 1048 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4657 "src-generated/ugbc.tab.c"
    break;

  case 289: /* every_definition: OFF  */
#line 1051 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4665 "src-generated/ugbc.tab.c"
    break;

  case 290: /* add_definition: Identifier COMMA expr  */
#line 1056 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4673 "src-generated/ugbc.tab.c"
    break;

  case 291: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1059 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4681 "src-generated/ugbc.tab.c"
    break;

  case 292: /* dimensions: Integer  */
#line 1065 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4690 "src-generated/ugbc.tab.c"
    break;

  case 293: /* dimensions: Integer COMMA dimensions  */
#line 1069 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4699 "src-generated/ugbc.tab.c"
    break;

  case 294: /* datatype: BYTE  */
#line 1076 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 4707 "src-generated/ugbc.tab.c"
    break;

  case 295: /* datatype: SIGNED BYTE  */
#line 1079 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 4715 "src-generated/ugbc.tab.c"
    break;

  case 296: /* datatype: WORD  */
#line 1082 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 4723 "src-generated/ugbc.tab.c"
    break;

  case 297: /* datatype: SIGNED WORD  */
#line 1085 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 4731 "src-generated/ugbc.tab.c"
    break;

  case 298: /* datatype: DWORD  */
#line 1088 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 4739 "src-generated/ugbc.tab.c"
    break;

  case 299: /* datatype: SIGNED DWORD  */
#line 1091 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 4747 "src-generated/ugbc.tab.c"
    break;

  case 300: /* datatype: ADDRESS  */
#line 1094 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 4755 "src-generated/ugbc.tab.c"
    break;

  case 301: /* datatype: POSITION  */
#line 1097 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 4763 "src-generated/ugbc.tab.c"
    break;

  case 302: /* datatype: COLOR  */
#line 1100 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 4771 "src-generated/ugbc.tab.c"
    break;

  case 303: /* datatype: STRING  */
#line 1103 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 4779 "src-generated/ugbc.tab.c"
    break;

  case 304: /* $@10: %empty  */
#line 1108 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4788 "src-generated/ugbc.tab.c"
    break;

  case 305: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1111 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 4798 "src-generated/ugbc.tab.c"
    break;

  case 306: /* $@11: %empty  */
#line 1116 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4807 "src-generated/ugbc.tab.c"
    break;

  case 307: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1119 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 4817 "src-generated/ugbc.tab.c"
    break;

  case 308: /* $@12: %empty  */
#line 1124 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4826 "src-generated/ugbc.tab.c"
    break;

  case 309: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1127 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 4836 "src-generated/ugbc.tab.c"
    break;

  case 312: /* indexes: expr  */
#line 1140 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4845 "src-generated/ugbc.tab.c"
    break;

  case 313: /* indexes: expr COMMA indexes  */
#line 1144 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4854 "src-generated/ugbc.tab.c"
    break;

  case 314: /* parameters: Identifier  */
#line 1151 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4864 "src-generated/ugbc.tab.c"
    break;

  case 315: /* parameters: Identifier DOLLAR  */
#line 1156 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4874 "src-generated/ugbc.tab.c"
    break;

  case 316: /* parameters: Identifier AS datatype  */
#line 1161 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4884 "src-generated/ugbc.tab.c"
    break;

  case 317: /* parameters: Identifier COMMA parameters  */
#line 1166 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4894 "src-generated/ugbc.tab.c"
    break;

  case 318: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1171 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4904 "src-generated/ugbc.tab.c"
    break;

  case 319: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1176 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4914 "src-generated/ugbc.tab.c"
    break;

  case 320: /* parameters_expr: Identifier  */
#line 1184 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4924 "src-generated/ugbc.tab.c"
    break;

  case 321: /* parameters_expr: Identifier DOLLAR  */
#line 1189 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4934 "src-generated/ugbc.tab.c"
    break;

  case 322: /* parameters_expr: Identifier AS datatype  */
#line 1194 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4944 "src-generated/ugbc.tab.c"
    break;

  case 323: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1199 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4954 "src-generated/ugbc.tab.c"
    break;

  case 324: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1204 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4964 "src-generated/ugbc.tab.c"
    break;

  case 325: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1209 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4974 "src-generated/ugbc.tab.c"
    break;

  case 326: /* parameters_expr: String  */
#line 1214 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4983 "src-generated/ugbc.tab.c"
    break;

  case 327: /* parameters_expr: String COMMA parameters_expr  */
#line 1218 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4992 "src-generated/ugbc.tab.c"
    break;

  case 328: /* values: expr  */
#line 1225 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5001 "src-generated/ugbc.tab.c"
    break;

  case 329: /* values: expr COMMA values  */
#line 1229 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5010 "src-generated/ugbc.tab.c"
    break;

  case 330: /* print_definition: expr  */
#line 1236 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5018 "src-generated/ugbc.tab.c"
    break;

  case 331: /* print_definition: expr COMMA  */
#line 1239 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5027 "src-generated/ugbc.tab.c"
    break;

  case 332: /* print_definition: expr SEMICOLON  */
#line 1243 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5035 "src-generated/ugbc.tab.c"
    break;

  case 333: /* $@13: %empty  */
#line 1246 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5044 "src-generated/ugbc.tab.c"
    break;

  case 335: /* $@14: %empty  */
#line 1250 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5052 "src-generated/ugbc.tab.c"
    break;

  case 337: /* use_definition: ANSI  */
#line 1256 "src/ugbc.y"
         {
        use_ansi( _environment );
    }
#line 5060 "src-generated/ugbc.tab.c"
    break;

  case 338: /* use_definition: SPECIFIC  */
#line 1259 "src/ugbc.y"
             {
        use_specific( _environment );
  }
#line 5068 "src-generated/ugbc.tab.c"
    break;

  case 356: /* statement: INC Identifier  */
#line 1282 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 5076 "src-generated/ugbc.tab.c"
    break;

  case 357: /* statement: DEC Identifier  */
#line 1285 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 5084 "src-generated/ugbc.tab.c"
    break;

  case 358: /* statement: RANDOMIZE  */
#line 1288 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 5092 "src-generated/ugbc.tab.c"
    break;

  case 359: /* statement: RANDOMIZE expr  */
#line 1291 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 5100 "src-generated/ugbc.tab.c"
    break;

  case 360: /* statement: IF expr THEN  */
#line 1294 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5108 "src-generated/ugbc.tab.c"
    break;

  case 361: /* statement: ELSE  */
#line 1297 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 5116 "src-generated/ugbc.tab.c"
    break;

  case 362: /* statement: ELSE IF expr THEN  */
#line 1300 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5124 "src-generated/ugbc.tab.c"
    break;

  case 363: /* statement: ENDIF  */
#line 1303 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5132 "src-generated/ugbc.tab.c"
    break;

  case 364: /* statement: DO  */
#line 1306 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5140 "src-generated/ugbc.tab.c"
    break;

  case 365: /* statement: LOOP  */
#line 1309 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5148 "src-generated/ugbc.tab.c"
    break;

  case 366: /* $@15: %empty  */
#line 1312 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5156 "src-generated/ugbc.tab.c"
    break;

  case 367: /* statement: WHILE $@15 expr  */
#line 1314 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5164 "src-generated/ugbc.tab.c"
    break;

  case 368: /* statement: WEND  */
#line 1317 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5172 "src-generated/ugbc.tab.c"
    break;

  case 369: /* statement: REPEAT  */
#line 1320 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5180 "src-generated/ugbc.tab.c"
    break;

  case 370: /* statement: UNTIL expr  */
#line 1323 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5188 "src-generated/ugbc.tab.c"
    break;

  case 371: /* statement: EXIT  */
#line 1326 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5196 "src-generated/ugbc.tab.c"
    break;

  case 372: /* statement: EXIT PROC  */
#line 1329 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5204 "src-generated/ugbc.tab.c"
    break;

  case 373: /* statement: POP PROC  */
#line 1332 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5212 "src-generated/ugbc.tab.c"
    break;

  case 374: /* statement: EXIT IF expr  */
#line 1335 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5220 "src-generated/ugbc.tab.c"
    break;

  case 375: /* statement: EXIT Integer  */
#line 1338 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5228 "src-generated/ugbc.tab.c"
    break;

  case 376: /* statement: EXIT direct_integer  */
#line 1341 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5236 "src-generated/ugbc.tab.c"
    break;

  case 377: /* statement: EXIT IF expr COMMA Integer  */
#line 1344 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5244 "src-generated/ugbc.tab.c"
    break;

  case 378: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1347 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5252 "src-generated/ugbc.tab.c"
    break;

  case 379: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1350 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5260 "src-generated/ugbc.tab.c"
    break;

  case 380: /* statement: NEXT  */
#line 1353 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5268 "src-generated/ugbc.tab.c"
    break;

  case 381: /* statement: PROCEDURE Identifier  */
#line 1356 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5277 "src-generated/ugbc.tab.c"
    break;

  case 382: /* $@16: %empty  */
#line 1360 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5285 "src-generated/ugbc.tab.c"
    break;

  case 383: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1362 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5293 "src-generated/ugbc.tab.c"
    break;

  case 384: /* statement: SHARED parameters_expr  */
#line 1365 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5301 "src-generated/ugbc.tab.c"
    break;

  case 385: /* statement: GLOBAL parameters_expr  */
#line 1368 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5309 "src-generated/ugbc.tab.c"
    break;

  case 386: /* statement: END PROC  */
#line 1371 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 5317 "src-generated/ugbc.tab.c"
    break;

  case 387: /* statement: END PROC OSP expr CSP  */
#line 1374 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5325 "src-generated/ugbc.tab.c"
    break;

  case 388: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1377 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5333 "src-generated/ugbc.tab.c"
    break;

  case 389: /* statement: Identifier " "  */
#line 1380 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5342 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: PROC Identifier  */
#line 1384 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5351 "src-generated/ugbc.tab.c"
    break;

  case 391: /* statement: CALL Identifier  */
#line 1388 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5360 "src-generated/ugbc.tab.c"
    break;

  case 392: /* $@17: %empty  */
#line 1392 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5368 "src-generated/ugbc.tab.c"
    break;

  case 393: /* statement: Identifier OSP $@17 values CSP  */
#line 1394 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5376 "src-generated/ugbc.tab.c"
    break;

  case 394: /* $@18: %empty  */
#line 1397 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5384 "src-generated/ugbc.tab.c"
    break;

  case 395: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1399 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5392 "src-generated/ugbc.tab.c"
    break;

  case 396: /* $@19: %empty  */
#line 1402 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5400 "src-generated/ugbc.tab.c"
    break;

  case 397: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1404 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5408 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statement: PEN expr  */
#line 1407 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 5416 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: PAPER expr  */
#line 1410 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 5424 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: INVERSE ON  */
#line 1413 "src/ugbc.y"
               {
      text_inverse( _environment, 1 );
  }
#line 5432 "src-generated/ugbc.tab.c"
    break;

  case 401: /* statement: INVERSE OFF  */
#line 1416 "src/ugbc.y"
                {
      text_inverse( _environment, 0 );
  }
#line 5440 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: Identifier COLON  */
#line 1419 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 5448 "src-generated/ugbc.tab.c"
    break;

  case 403: /* statement: BEG GAMELOOP  */
#line 1422 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 5456 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: END GAMELOOP  */
#line 1425 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 5464 "src-generated/ugbc.tab.c"
    break;

  case 405: /* statement: GRAPHIC  */
#line 1428 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 5472 "src-generated/ugbc.tab.c"
    break;

  case 406: /* statement: HALT  */
#line 1431 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 5480 "src-generated/ugbc.tab.c"
    break;

  case 407: /* statement: END  */
#line 1434 "src/ugbc.y"
        {
      end( _environment );
  }
#line 5488 "src-generated/ugbc.tab.c"
    break;

  case 412: /* statement: RETURN  */
#line 1441 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 5496 "src-generated/ugbc.tab.c"
    break;

  case 413: /* statement: RETURN expr  */
#line 1444 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 5504 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: POP  */
#line 1447 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 5512 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: DONE  */
#line 1450 "src/ugbc.y"
          {
      return 0;
  }
#line 5520 "src-generated/ugbc.tab.c"
    break;

  case 416: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1453 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5528 "src-generated/ugbc.tab.c"
    break;

  case 417: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1456 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5536 "src-generated/ugbc.tab.c"
    break;

  case 418: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1459 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 5544 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1462 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5552 "src-generated/ugbc.tab.c"
    break;

  case 422: /* statement: Identifier ASSIGN expr  */
#line 1467 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 5566 "src-generated/ugbc.tab.c"
    break;

  case 423: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1476 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 5580 "src-generated/ugbc.tab.c"
    break;

  case 424: /* $@20: %empty  */
#line 1485 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5589 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1489 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 5602 "src-generated/ugbc.tab.c"
    break;

  case 426: /* $@21: %empty  */
#line 1497 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5611 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1500 "src/ugbc.y"
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
#line 5630 "src-generated/ugbc.tab.c"
    break;

  case 428: /* $@22: %empty  */
#line 1514 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5639 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1517 "src/ugbc.y"
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
#line 5658 "src-generated/ugbc.tab.c"
    break;

  case 430: /* statement: DEBUG expr  */
#line 1531 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 5666 "src-generated/ugbc.tab.c"
    break;

  case 433: /* statements_no_linenumbers: statement  */
#line 1539 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 5672 "src-generated/ugbc.tab.c"
    break;

  case 434: /* $@23: %empty  */
#line 1540 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 5678 "src-generated/ugbc.tab.c"
    break;

  case 436: /* $@24: %empty  */
#line 1544 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 5686 "src-generated/ugbc.tab.c"
    break;

  case 437: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1546 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 5694 "src-generated/ugbc.tab.c"
    break;

  case 438: /* $@25: %empty  */
#line 1551 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 5702 "src-generated/ugbc.tab.c"
    break;

  case 444: /* $@26: %empty  */
#line 1561 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 5708 "src-generated/ugbc.tab.c"
    break;


#line 5712 "src-generated/ugbc.tab.c"

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

#line 1563 "src/ugbc.y"


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
        variable_define( _environment, "stringsAddress", VT_ADDRESS, 0x4200 );
        variable_global( _environment, "stringsAddress" );
        bank_define( _environment, "STRINGS", BT_STRINGS, 0x4200, NULL );
        variable_define( _environment, "textAddress", VT_ADDRESS, 0x0400 );
        variable_global( _environment, "textAddress" );
        variable_define( _environment, "colormapAddress", VT_ADDRESS, 0xD800 );
        variable_global( _environment, "colormapAddress" );
    } else {
        outhead0("org 32768");
        variable_define( _environment, "stringsAddress", VT_ADDRESS, 0xa000 );
        variable_global( _environment, "stringsAddress" );
        variable_define( _environment, "bitmap_enabled", VT_BYTE, 0 );
        variable_global( _environment, "bitmap_enabled" );
    }

    setup_text_variables( _environment );

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

