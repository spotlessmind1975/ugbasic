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
  YYSYMBOL_BLACK = 160,                    /* BLACK  */
  YYSYMBOL_WHITE = 161,                    /* WHITE  */
  YYSYMBOL_RED = 162,                      /* RED  */
  YYSYMBOL_CYAN = 163,                     /* CYAN  */
  YYSYMBOL_VIOLET = 164,                   /* VIOLET  */
  YYSYMBOL_GREEN = 165,                    /* GREEN  */
  YYSYMBOL_BLUE = 166,                     /* BLUE  */
  YYSYMBOL_YELLOW = 167,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 168,                   /* ORANGE  */
  YYSYMBOL_BROWN = 169,                    /* BROWN  */
  YYSYMBOL_LIGHT = 170,                    /* LIGHT  */
  YYSYMBOL_DARK = 171,                     /* DARK  */
  YYSYMBOL_GREY = 172,                     /* GREY  */
  YYSYMBOL_GRAY = 173,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 174,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 175,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 176,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 177,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 178,                /* TURQUOISE  */
  YYSYMBOL_TAN = 179,                      /* TAN  */
  YYSYMBOL_PINK = 180,                     /* PINK  */
  YYSYMBOL_PEACH = 181,                    /* PEACH  */
  YYSYMBOL_OLIVE = 182,                    /* OLIVE  */
  YYSYMBOL_Identifier = 183,               /* Identifier  */
  YYSYMBOL_String = 184,                   /* String  */
  YYSYMBOL_Integer = 185,                  /* Integer  */
  YYSYMBOL_186_ = 186,                     /* " "  */
  YYSYMBOL_YYACCEPT = 187,                 /* $accept  */
  YYSYMBOL_expr = 188,                     /* expr  */
  YYSYMBOL_expr_math = 189,                /* expr_math  */
  YYSYMBOL_term = 190,                     /* term  */
  YYSYMBOL_modula = 191,                   /* modula  */
  YYSYMBOL_factor = 192,                   /* factor  */
  YYSYMBOL_direct_integer = 193,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 194, /* random_definition_simple  */
  YYSYMBOL_random_definition = 195,        /* random_definition  */
  YYSYMBOL_color_enumeration = 196,        /* color_enumeration  */
  YYSYMBOL_exponential = 197,              /* exponential  */
  YYSYMBOL_198_1 = 198,                    /* $@1  */
  YYSYMBOL_199_2 = 199,                    /* $@2  */
  YYSYMBOL_200_3 = 200,                    /* $@3  */
  YYSYMBOL_position = 201,                 /* position  */
  YYSYMBOL_bank_definition_simple = 202,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 203, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 204,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 205, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 206, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 207,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 208, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 209, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 210,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 211,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 212, /* color_definition_expression  */
  YYSYMBOL_color_definition = 213,         /* color_definition  */
  YYSYMBOL_milliseconds = 214,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 215,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 216, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 217,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 218, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 219, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 220,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 221, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 222, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 223,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 224, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 225, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 226,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 227,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 228, /* text_definition_expression  */
  YYSYMBOL_text_definition = 229,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 230,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 231, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 232,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 233, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 234, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 235,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 236, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 237, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 238,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 239,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 240,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 241,         /* gosub_definition  */
  YYSYMBOL_var_definition = 242,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 243,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 244, /* point_definition_expression  */
  YYSYMBOL_point_definition = 245,         /* point_definition  */
  YYSYMBOL_ink_definition = 246,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 247,       /* on_goto_definition  */
  YYSYMBOL_248_4 = 248,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 249,      /* on_gosub_definition  */
  YYSYMBOL_250_5 = 250,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 251,       /* on_proc_definition  */
  YYSYMBOL_252_6 = 252,                    /* $@6  */
  YYSYMBOL_on_definition = 253,            /* on_definition  */
  YYSYMBOL_254_7 = 254,                    /* $@7  */
  YYSYMBOL_255_8 = 255,                    /* $@8  */
  YYSYMBOL_256_9 = 256,                    /* $@9  */
  YYSYMBOL_every_definition = 257,         /* every_definition  */
  YYSYMBOL_add_definition = 258,           /* add_definition  */
  YYSYMBOL_dimensions = 259,               /* dimensions  */
  YYSYMBOL_datatype = 260,                 /* datatype  */
  YYSYMBOL_dim_definition = 261,           /* dim_definition  */
  YYSYMBOL_262_10 = 262,                   /* $@10  */
  YYSYMBOL_263_11 = 263,                   /* $@11  */
  YYSYMBOL_264_12 = 264,                   /* $@12  */
  YYSYMBOL_dim_definitions = 265,          /* dim_definitions  */
  YYSYMBOL_indexes = 266,                  /* indexes  */
  YYSYMBOL_parameters = 267,               /* parameters  */
  YYSYMBOL_parameters_expr = 268,          /* parameters_expr  */
  YYSYMBOL_values = 269,                   /* values  */
  YYSYMBOL_print_definition = 270,         /* print_definition  */
  YYSYMBOL_271_13 = 271,                   /* $@13  */
  YYSYMBOL_272_14 = 272,                   /* $@14  */
  YYSYMBOL_use_definition = 273,           /* use_definition  */
  YYSYMBOL_statement = 274,                /* statement  */
  YYSYMBOL_275_15 = 275,                   /* $@15  */
  YYSYMBOL_276_16 = 276,                   /* $@16  */
  YYSYMBOL_277_17 = 277,                   /* $@17  */
  YYSYMBOL_278_18 = 278,                   /* $@18  */
  YYSYMBOL_279_19 = 279,                   /* $@19  */
  YYSYMBOL_280_20 = 280,                   /* $@20  */
  YYSYMBOL_281_21 = 281,                   /* $@21  */
  YYSYMBOL_282_22 = 282,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 283, /* statements_no_linenumbers  */
  YYSYMBOL_284_23 = 284,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 285, /* statements_with_linenumbers  */
  YYSYMBOL_286_24 = 286,                   /* $@24  */
  YYSYMBOL_statements_complex = 287,       /* statements_complex  */
  YYSYMBOL_288_25 = 288,                   /* $@25  */
  YYSYMBOL_program = 289,                  /* program  */
  YYSYMBOL_290_26 = 290                    /* $@26  */
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
#define YYLAST   2123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  187
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  104
/* YYNRULES -- Number of rules.  */
#define YYNRULES  437
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  845

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   441


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
     185,   186
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
     440,   443,   446,   449,   452,   455,   458,   461,   464,   464,
     470,   473,   476,   480,   484,   488,   492,   496,   499,   502,
     505,   510,   510,   513,   516,   519,   522,   525,   528,   532,
     535,   538,   541,   545,   548,   551,   554,   558,   561,   564,
     567,   573,   576,   579,   582,   585,   590,   591,   594,   597,
     602,   605,   610,   611,   614,   617,   622,   625,   630,   631,
     634,   637,   640,   645,   648,   651,   656,   657,   660,   661,
     662,   665,   668,   671,   676,   679,   682,   688,   689,   692,
     695,   698,   701,   704,   707,   710,   713,   716,   719,   722,
     725,   728,   731,   734,   739,   742,   745,   748,   751,   754,
     757,   760,   763,   766,   769,   772,   775,   778,   781,   786,
     787,   790,   793,   796,   799,   802,   808,   811,   817,   818,
     821,   826,   831,   832,   835,   838,   843,   846,   851,   852,
     855,   860,   865,   866,   869,   872,   875,   880,   883,   889,
     890,   893,   896,   899,   902,   905,   910,   913,   916,   921,
     922,   924,   925,   928,   931,   934,   939,   946,   949,   955,
     958,   964,   967,   973,   978,   979,   982,   987,   991,   991,
     996,  1000,  1000,  1005,  1009,  1009,  1014,  1014,  1017,  1017,
    1020,  1020,  1025,  1028,  1031,  1036,  1039,  1045,  1049,  1056,
    1059,  1062,  1065,  1068,  1071,  1074,  1077,  1080,  1083,  1088,
    1088,  1096,  1096,  1104,  1104,  1115,  1116,  1120,  1124,  1131,
    1136,  1141,  1146,  1151,  1156,  1164,  1169,  1174,  1179,  1184,
    1189,  1194,  1198,  1205,  1209,  1216,  1219,  1223,  1226,  1226,
    1230,  1230,  1236,  1239,  1245,  1246,  1247,  1248,  1249,  1250,
    1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,
    1261,  1262,  1265,  1268,  1271,  1274,  1277,  1280,  1283,  1286,
    1289,  1292,  1292,  1297,  1300,  1303,  1306,  1309,  1312,  1315,
    1318,  1321,  1324,  1327,  1330,  1333,  1336,  1340,  1340,  1345,
    1348,  1351,  1354,  1357,  1360,  1364,  1368,  1372,  1372,  1377,
    1377,  1382,  1382,  1387,  1390,  1393,  1396,  1399,  1402,  1405,
    1408,  1409,  1410,  1411,  1412,  1415,  1418,  1421,  1424,  1427,
    1430,  1433,  1436,  1437,  1438,  1447,  1456,  1456,  1468,  1468,
    1485,  1485,  1502,  1505,  1506,  1510,  1511,  1511,  1515,  1515,
    1522,  1522,  1525,  1526,  1527,  1528,  1532,  1532
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
  "PARAM", "PRINT", "DEFAULT", "SPECIFIC", "ANSI", "USE", "BLACK", "WHITE",
  "RED", "CYAN", "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE", "BROWN",
  "LIGHT", "DARK", "GREY", "GRAY", "MAGENTA", "PURPLE", "LAVENDER", "GOLD",
  "TURQUOISE", "TAN", "PINK", "PEACH", "OLIVE", "Identifier", "String",
  "Integer", "\" \"", "$accept", "expr", "expr_math", "term", "modula",
  "factor", "direct_integer", "random_definition_simple",
  "random_definition", "color_enumeration", "exponential", "$@1", "$@2",
  "$@3", "position", "bank_definition_simple",
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
     435,   436,   437,   438,   439,   440,   441
};
#endif

#define YYPACT_NINF (-733)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-417)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -733,    93,   796,  -733,  -733,   -95,   -73,   -14,  -733,    82,
    1521,   117,     1,  1521,  -733,    30,   168,  1660,   -59,  -134,
    -733,  -733,  -733,  1218,   155,    20,  1660,  1660,    96,   -32,
    -733,   163,   180,  1660,  1660,  -733,   207,   210,  -100,  1660,
      99,   179,  -733,   -23,  -733,  1660,    73,  1382,   211,    79,
    1660,   114,   132,   136,   137,    43,    43,  1660,    -6,     8,
    -733,   245,   261,   318,  -733,  -733,  -733,  1521,   301,  -733,
    -733,  -733,  1521,  1521,  1521,  -733,  -733,  -733,   141,  1054,
    -733,  -733,   293,   294,   296,    62,   148,  -733,  -733,    12,
     298,   300,  1660,  -733,  -733,   303,   304,   305,   306,   307,
     309,   311,   312,   313,   314,   315,   316,   317,   320,   326,
     327,   328,  -733,  -733,   329,    52,  -733,  -733,  -733,  -733,
    -733,  -733,  -733,   201,  -733,  -733,    88,    -7,  -733,  -733,
    -733,  -733,  -733,  -733,  -733,  -733,  -733,   202,     2,  -733,
    -733,   -24,   224,   239,   177,   241,   -19,  -733,  -733,  -733,
    -733,  -733,   -13,   289,    -9,    -5,     6,     7,   348,  -733,
    -733,  -733,   192,   299,  -733,  -733,  -733,  1521,  -733,  -733,
     344,  -733,  -733,  -733,  -733,  -733,  1521,   330,   331,  -733,
    -733,  -733,    -1,  -733,    33,  -733,  -733,  -733,  -733,  -733,
    1660,  1660,  -733,  -733,   367,  -733,  -733,  -733,  1521,  -733,
    -733,  -733,  1521,   349,  -733,  -733,  -733,   310,  -733,  -733,
    -733,   234,  1660,  1660,  -733,  -733,  1521,  -733,  -733,  -733,
     346,  -733,  -733,  -733,  -733,  -733,  -733,  -733,  -733,  1660,
    1660,  -733,  -733,  -733,  -733,   369,  -733,  -733,   232,  -733,
    1660,   376,  -733,  -733,  -733,    21,   378,  -733,   240,   242,
     243,   147,   379,  -733,  -733,   218,  -733,  -733,  -733,  -733,
    -733,  -733,  1660,   375,  -733,  -733,   357,    40,   936,  -733,
     796,   796,   363,   365,  1521,  -733,  -733,   332,   334,   335,
     336,  -733,   364,   366,   368,   374,   380,   102,   381,  1521,
    1521,  1521,  -733,  -733,  -733,  -733,  -733,  -733,  -733,  -733,
    -733,  -733,   377,  -733,  -733,  1660,  1660,  -733,  1660,  1660,
    1660,  1660,  1660,  1660,  1660,  1660,  1660,  1660,  1660,  1660,
    1660,  1660,  1660,  1660,  1660,  1799,   384,   217,  -733,  -733,
    -733,  -733,  -733,  -733,  -733,  -733,   385,  -733,   387,  -733,
    -733,  -733,  -733,  -733,  -733,  1799,  1799,  1799,  1799,  1799,
    1799,  1799,  1799,  1799,  1799,  1799,  1799,  1799,  1938,  -733,
    -733,  -733,  1521,   389,  -733,  -733,  -733,   354,   289,   390,
     289,   398,   289,   400,   289,   401,   289,  -733,  1660,   393,
    -733,  -733,   226,   229,    35,    64,  -733,  -733,  -733,   394,
     289,   396,  -733,  -733,   231,   233,   128,   164,  -733,  -733,
     397,  -733,  -733,  1521,  -733,  -733,  1521,  1521,  -733,  -733,
    -733,   391,   244,  -733,   425,  1660,  -733,  -733,  -733,  -733,
    1521,  -733,  1660,   427,   428,  -733,  -733,  1521,   370,   430,
    1660,   339,   436,  1660,  -733,  -733,  -733,  -733,  -733,  -733,
     130,  -733,  -733,   411,   426,   114,  -733,   308,  -733,    43,
     441,    40,    43,   255,   263,   796,  -733,  1660,   416,  1660,
    1660,   417,    14,  -733,   936,  -733,  -733,   269,   270,  -733,
    -733,  1660,   289,  1660,   289,   271,   272,   274,   275,   277,
     419,   429,   431,  -733,   432,   433,   434,   435,   437,   438,
    1660,   458,   469,   470,   471,   444,   446,   447,   448,   477,
     450,   451,   452,   454,   455,   484,   485,   459,   461,   462,
      31,   319,   463,   465,  1660,  1660,   239,   239,   283,   283,
     283,   283,   283,   283,   283,   283,   177,   241,   241,  -733,
     464,   472,  1521,    42,  -733,   289,  -733,   289,  -733,   289,
    -733,   289,   143,  -733,  1660,  -733,  -733,  -733,  -733,  -733,
    -733,  -733,  -733,  1660,  -733,   289,  -733,  -733,  -733,  -733,
    -733,  -733,  -733,  -733,   289,  -733,  -733,  -733,  -733,  -733,
    -733,   322,   323,   325,   333,   487,  1660,   496,   467,   468,
     371,  1660,  1660,   504,   505,  -733,   -56,   442,   337,  1660,
     506,  -733,  -733,  -733,   481,   338,   483,  -733,  1660,   341,
    1660,  -733,    43,   511,  -733,  1660,  1660,  -733,  -733,  1660,
     514,   382,   518,   491,  1660,  -733,  -733,  -733,  -733,  -733,
    -733,  -733,  -733,  -733,  -733,  -733,  -733,   342,   343,   347,
    -733,  -733,  -733,  -733,  -733,  -733,   494,  1660,  1660,  1660,
    1660,  -733,  -733,  -733,  -733,  1660,  -733,  -733,  -733,  -733,
    -733,  1660,  1660,  -733,  -733,  -733,  1938,   498,  -733,  1660,
     383,   500,   353,   355,  -733,  -733,  -733,  -733,  -733,  -733,
     508,  -733,   510,  -733,   360,    45,  -733,   534,  -733,   538,
     539,  -733,   540,  -733,   542,  -733,   537,  1521,   544,  1660,
    1660,   289,  -733,   517,   519,  1660,   289,  -733,  -733,  1660,
    -733,    36,  1660,   338,   546,   520,   338,   408,   151,   409,
     410,  -733,    43,  -733,  -733,   524,  1660,  -733,  1660,   547,
     526,  -733,  -733,  -733,  -733,   527,   528,    69,    95,   529,
     530,   532,   533,  -733,   535,  -733,  -733,  -733,  -733,   392,
     399,  -733,   545,  -733,   548,  -733,  1660,   289,   562,   566,
     568,  1660,  -733,  -733,  1660,  -733,  -733,  -733,   565,   567,
     549,   550,   466,  1660,   569,   515,   551,   338,  -733,   554,
    -733,   341,   584,    40,  -733,  -733,  -733,   579,  -733,  -733,
    1660,   580,  -733,  -733,  1660,  -733,  1660,  -733,  -733,  -733,
    -733,  -733,  -733,  -733,  -733,   413,   414,   559,   564,   322,
     323,   325,  -733,  -733,  1660,  1660,  -733,  -733,  1660,   571,
    1660,  1660,  -733,  -733,  -733,  -733,   341,   594,  1660,  -733,
    1660,   573,   575,  -733,  -733,  -733,  -733,  -733,  -733,  -733,
    -733,  -733,  -733,   589,  -733,  -733,  -733,   341,  -733,  -733,
    -733,  -733,  1660,  -733,  -733
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     436,     0,   424,     1,   423,     0,     0,     0,   407,     0,
       0,   375,     0,     0,   398,     0,     0,     0,   251,     0,
     360,   364,   361,     0,     0,     0,     0,     0,     0,   399,
     358,     0,     0,     0,   353,   397,     0,     0,     0,   404,
     406,   356,   359,   366,   363,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   420,
     428,   425,   432,   434,   437,   351,   352,     0,     0,   152,
     153,   335,     0,     0,     0,   166,   167,   337,     0,     0,
      79,    80,     0,     0,     0,     0,     0,   117,   118,     0,
       0,     0,     0,   112,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   119,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,    44,    49,
      50,    51,    52,    53,    54,    57,    58,     0,    63,    67,
      65,     0,     2,    12,    15,    17,     0,    76,    20,   177,
     178,   338,     0,     0,     0,     0,     0,     0,     0,   146,
     147,   334,     0,     0,   209,   210,   339,     0,   212,   213,
     214,   218,   219,   340,   241,   242,     0,     0,     0,   249,
     250,   345,     0,   400,     0,   261,   348,   257,   258,   401,
       0,     0,   224,   225,     0,   228,   229,   342,     0,   232,
     233,   343,     0,   235,   239,   240,   344,     0,   393,   395,
     396,   381,     0,     0,   422,   354,     0,   222,   223,   341,
       0,   264,   265,   346,   259,   260,   402,   405,   368,     0,
       0,   367,   370,   371,   365,     0,   283,   284,     0,   403,
       0,     0,   349,   266,   347,   299,   305,   412,   385,   376,
     386,   315,   321,   379,   380,   325,   350,   333,   332,   413,
     430,   394,     0,   418,   387,   384,     0,     0,   424,   426,
     424,   424,     0,     0,     0,   163,   160,     0,     0,     0,
       0,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    24,    25,    27,    29,    30,    26,    31,
     101,    23,     0,   115,   116,     0,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    42,
      45,    46,    47,    48,    43,    56,    64,   108,     0,   168,
     174,   169,   170,   175,   176,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   171,
     172,   173,     0,     0,   158,   159,   336,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,     0,
     199,   200,     0,     0,     0,     0,   196,   195,   121,     0,
       0,     0,   184,   185,     0,     0,     0,     0,   181,   180,
       0,   216,   211,     0,   246,   243,     0,     0,   276,   280,
     278,     0,     0,   362,     0,     0,   231,   230,   237,   234,
       0,   355,     0,     0,     0,   221,   220,     0,     0,   369,
       0,     0,     0,     0,   297,   289,   291,   296,   293,   298,
       0,   295,   303,     0,     0,     0,   389,     0,   391,     0,
     316,     0,     0,   330,   328,   424,   414,     0,     0,     0,
       0,     0,   420,   429,   424,   433,   435,     0,     0,   150,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,     5,     7,
       8,     9,    10,     6,     3,     4,    16,    18,    19,    21,
       0,     0,     0,     0,   128,     0,   140,     0,   132,     0,
     136,     0,   124,   197,     0,   204,   203,   208,   207,   202,
     206,   201,   205,     0,   182,     0,   189,   188,   193,   192,
     187,   191,   186,   190,     0,   217,   215,   247,   244,   248,
     245,     0,     0,     0,     0,   252,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   357,     0,     0,     0,     0,
     285,   290,   292,   294,     0,     0,     0,   306,     0,     0,
       0,   318,     0,   317,   322,     0,     0,   431,   415,     0,
     323,     0,   307,     0,     0,   427,   151,   149,   165,   162,
     164,   161,    75,    68,    70,    74,    72,     0,     0,     0,
      78,    77,    82,    81,    84,    83,     0,     0,     0,     0,
       0,    91,    92,    93,   100,     0,    94,    95,    96,    97,
      98,     0,     0,   110,   111,   102,     0,     0,   106,     0,
       0,     0,     0,     0,   156,   154,   125,   138,   130,   133,
     127,   139,   131,   135,     0,     0,   194,     0,   179,     0,
     267,   277,   270,   281,   273,   279,   253,     0,     0,     0,
       0,     0,   382,     0,     0,     0,     0,   372,   373,     0,
     282,     0,     0,     0,   287,     0,     0,     0,   309,     0,
       0,   319,     0,   331,   329,     0,     0,   388,     0,     0,
       0,    69,    71,    73,   120,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,   109,    60,   157,   155,     0,
       0,   141,   126,   137,   129,   134,     0,     0,     0,     0,
       0,     0,   255,   254,     0,   227,   238,   236,     0,     0,
       0,     0,   374,     0,     0,     0,     0,     0,   300,     0,
     390,     0,   310,     0,   378,   392,   320,     0,   324,   308,
       0,     0,    85,    86,     0,    87,     0,    89,    99,   105,
     104,    22,    62,   143,   145,     0,     0,     0,     0,     0,
       0,     0,   256,   226,     0,     0,   263,   262,     0,     0,
       0,     0,   304,   288,   302,   312,     0,   311,     0,   417,
       0,     0,     0,   142,   144,   198,   183,   269,   272,   275,
     408,   409,   383,     0,   410,   286,   313,     0,   419,   421,
      88,    90,     0,   314,   411
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -733,   -10,   -76,   -52,   249,  -257,    68,  -733,  -733,  -733,
    -340,  -733,  -733,  -733,   449,  -733,  -733,  -733,  -733,  -733,
    -733,  -733,  -733,  -733,  -733,  -733,  -733,   473,  -733,  -733,
    -733,  -733,  -733,  -733,  -733,  -733,  -733,  -733,  -733,  -733,
    -733,  -733,  -733,  -733,  -733,  -733,  -733,  -733,  -733,  -733,
    -733,  -733,  -733,  -733,  -733,  -733,  -733,  -733,  -733,  -733,
    -188,  -733,  -187,  -733,  -186,  -733,  -733,  -733,  -733,  -733,
    -733,  -733,  -633,  -266,  -733,  -733,  -733,  -733,   169,  -511,
    -732,   -54,  -508,  -288,  -733,  -733,  -733,  -733,  -733,  -733,
    -733,  -733,  -733,  -733,  -733,  -733,  -263,  -733,  -733,  -733,
    -262,  -733,  -733,  -733
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   612,   142,   143,   144,   145,   146,   299,   300,   147,
     148,   338,   513,   514,   389,   159,   160,   161,    69,    70,
      71,   364,   365,   366,    75,    76,    77,   344,   149,   150,
     151,   164,   165,   166,   171,   172,   173,   217,   218,   219,
     195,   196,   197,   199,   200,   201,   204,   205,   206,   179,
     180,   181,   185,   189,   226,   186,   221,   222,   223,   244,
     681,   748,   683,   749,   685,   750,   183,   571,   573,   572,
     239,   242,   705,   442,   246,   443,   444,   594,   247,   613,
     709,   253,   611,   256,   606,   605,   259,    61,   190,   447,
     459,   598,   600,   266,   458,   267,    62,   464,    63,   268,
      64,   455,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     141,   461,   254,   162,   661,   463,   660,   182,   465,   466,
      67,   362,   260,   194,   261,   368,   207,   208,   529,   370,
     261,   262,   336,   214,   215,   153,    86,   262,   263,   227,
     372,   374,   302,   154,   263,   234,   -59,   238,   656,   815,
     243,  -301,  -416,   763,   202,   230,   434,   255,  -416,   187,
     155,   188,   408,   411,   167,   339,   340,   272,   210,    86,
     339,   359,   275,   277,   279,   434,   168,   169,   510,   288,
     766,   764,   326,   769,   666,   412,   784,   742,   156,   157,
     549,   163,   307,   224,   836,   225,   327,   292,    65,   550,
     707,   667,   710,     3,   743,   435,   436,   437,   715,   527,
     528,   409,   786,   720,   785,   843,   438,   203,    72,   551,
      66,   233,   211,    73,   435,   436,   437,   170,   552,   668,
     669,   231,   744,   745,   184,   438,   341,   342,   343,   697,
     787,   341,   342,   360,   813,   273,   293,   294,   295,   152,
     276,   278,   280,   410,   439,   296,   297,   298,   734,   337,
     303,   257,   258,    74,   449,   264,   440,   401,   771,   333,
     358,   264,   232,   439,   441,   334,   404,   450,   304,    68,
     363,   772,   674,   560,   369,   440,   480,   481,   371,   198,
     413,   414,   561,   441,   158,   603,   209,   482,   416,   373,
     375,   675,   418,   607,   265,   451,   356,   212,   357,   773,
     265,   615,   423,   424,   591,   592,   425,   779,   778,   562,
     174,   175,   176,   177,   213,   593,   377,   378,   563,   428,
     429,   367,   178,   453,   379,   454,   251,   252,   380,   381,
     432,   216,   345,   346,   220,   402,   347,   382,   348,   349,
     350,   351,   352,   228,   405,   240,   383,   229,   384,   385,
     329,   269,   456,   330,   331,  -327,   235,   386,   387,  -327,
     332,  -327,   241,  -326,   469,   270,   417,  -326,   388,  -326,
     419,   518,   519,   520,   521,   522,   523,   524,   525,   484,
     486,   488,   545,   546,   426,   547,   548,   556,   557,   558,
     559,   345,   346,   516,   517,   491,   492,   245,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   248,   732,   713,   714,   249,
     250,   353,   271,   377,   390,   274,   281,   289,   290,   354,
     291,   391,   305,   301,   306,   392,   393,   308,   309,   310,
     311,   312,   470,   313,   394,   314,   315,   316,   317,   318,
     319,   320,   530,   395,   321,   396,   397,   485,   487,   489,
     322,   323,   324,   325,   398,   399,   328,   335,   543,   355,
     358,    86,   376,   403,   415,   388,   406,   407,   420,   421,
     427,   422,   430,   433,   431,   445,   452,   446,   457,  -377,
     448,   460,   467,   565,   468,   601,   567,   569,   604,   475,
     512,   476,   533,   477,   471,   577,   472,   473,   474,   478,
     578,   490,   580,   532,   535,   479,   483,   583,   511,   -61,
     587,   515,   537,   590,   539,   541,   544,   575,   553,   555,
     531,   564,   576,   574,   581,   582,   534,   586,   536,   585,
     538,   588,   540,   589,   542,   595,   596,   608,   602,   610,
     609,   614,   616,   617,   627,   599,   622,   623,   554,   624,
     625,   618,   626,   620,   628,   637,   629,   630,   631,   632,
     633,   566,   634,   635,   568,   570,   638,   639,   640,   641,
     636,   642,   643,   644,   645,   646,   647,   648,   579,   649,
     650,   651,   652,   662,   653,   584,   654,   655,   658,   659,
     687,   663,   657,   689,   610,   680,   682,   817,   684,   690,
     691,   695,   696,   702,   699,   703,   686,   706,   712,   692,
     700,   716,   664,   704,   708,   718,   719,   721,   722,   724,
     717,   735,   723,   733,   676,   736,   737,   739,   738,   740,
     619,   746,   621,   677,   741,   747,  -268,  -271,   711,  -274,
     751,   754,   758,   767,   759,   768,   770,   774,   775,   777,
     780,   781,   782,   783,   788,   789,   688,   790,   791,   799,
     792,   693,   694,   800,   795,   801,   793,   796,   804,   701,
     805,   808,   810,   794,   806,   807,   812,   811,   610,   814,
     610,   816,   818,   820,   825,   255,   255,   823,   824,   826,
     665,   837,   842,   670,   526,   671,   833,   672,   840,   673,
     841,   827,   400,   828,   597,   829,     0,     0,     0,   361,
       0,     0,     0,   678,     0,     0,     0,   725,   726,   727,
     728,     0,   679,     0,     0,   729,     0,     0,     0,     0,
       0,   730,   731,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   698,     0,     0,     0,   776,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   752,     0,   755,
     756,     0,     0,     0,     0,   760,     0,     0,     0,   762,
       0,     0,   765,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   610,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   797,     0,     0,     0,
       0,   802,     0,     0,   803,     0,     0,     0,     0,     0,
       0,     0,     0,   809,     0,   753,     0,     0,     0,   757,
       0,     0,     0,     0,   761,     0,     0,     0,     0,     0,
     819,     0,     0,     0,   821,     0,   822,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   830,   831,     0,     0,   832,     4,
     834,   835,     0,     0,     0,     0,     5,     6,   838,     0,
     839,     0,     0,     0,     0,   798,     0,     0,     7,     8,
       0,     9,     0,    10,    11,     0,    12,    13,     0,     0,
       0,     0,   844,     0,    14,     0,    15,    16,    17,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,    28,    29,     0,    30,     0,     0,
      31,    32,    33,     0,    34,    35,    36,    37,    38,    39,
      40,     0,    41,     0,     0,     0,    42,    43,    44,    45,
      46,     0,    47,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,    51,     4,
      52,    53,    54,     0,     0,    55,     5,     6,     0,    56,
       0,    57,     0,     0,     0,    58,     0,     0,     7,     8,
       0,     9,     0,    10,    11,     0,    12,    13,     0,     0,
       0,     0,     0,     0,    14,     0,    15,    16,    17,    59,
       0,    60,     0,    18,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,    28,    29,     0,    30,     0,     0,
      31,    32,    33,     0,    34,    35,    36,    37,    38,    39,
      40,     0,    41,     0,     0,     0,    42,    43,    44,    45,
      46,     0,    47,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,    51,   282,
      52,    53,    54,     0,     0,    55,     0,     0,    79,    56,
       0,    57,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   462,
       0,    83,     0,     0,    84,     0,     0,    85,   283,   284,
     285,     0,     0,     0,     0,     0,     0,    87,    88,   286,
      89,     0,     0,     0,     0,     0,     0,     0,    90,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    93,    94,     0,     0,     0,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,   107,   108,   109,   287,
     110,   111,   112,     0,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,     0,
       0,     0,     0,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    78,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   191,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,   192,   193,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,     0,     0,    84,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,     0,    89,     0,     0,     0,     0,     0,
       0,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
     107,   108,   109,     0,   110,   111,   112,     0,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,     0,     0,     0,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    78,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
       0,     0,     0,     0,   236,   237,     0,     0,     0,     0,
       0,     0,    80,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
       0,     0,    84,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,    88,     0,    89,     0,
       0,     0,     0,     0,     0,     0,    90,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      93,    94,     0,     0,     0,     0,     0,     0,     0,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,   107,   108,   109,     0,   110,   111,
     112,     0,   113,   114,     0,     0,     0,     0,     0,     0,
      78,     0,     0,     0,     0,     0,   115,     0,     0,     0,
       0,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    79,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,    80,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
       0,    84,     0,     0,    85,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,     0,    89,     0,     0,
       0,     0,     0,     0,     0,    90,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      94,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,     0,   107,   108,   109,     0,   110,   111,   112,
       0,   113,   114,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,   115,     0,     0,     0,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    79,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
      80,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,     0,
      84,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,     0,    89,     0,     0,     0,
       0,     0,     0,     0,    90,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
       0,     0,   107,   108,   109,     0,   110,   111,   112,     0,
     113,   114,     0,     0,     0,     0,     0,     0,    78,     0,
       0,     0,     0,     0,   115,     0,     0,     0,     0,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    79,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,     0,    80,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,     0,    84,
       0,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,    88,     0,    89,     0,     0,     0,     0,
       0,     0,     0,    90,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,    94,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,     0,     0,
       0,   107,   108,   109,     0,   110,   111,   112,     0,   113,
     114,     0,     0,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,   115,     0,     0,     0,     0,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    79,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,    80,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,     0,     0,    84,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,     0,    89,     0,     0,     0,     0,     0,
       0,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,    94,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
     107,   108,   109,     0,   110,   111,   112,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,     0,     0,     0,     0,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140
};

static const yytype_int16 yycheck[] =
{
      10,   267,    56,    13,   515,   268,   514,    17,   270,   271,
      24,    24,     4,    23,     6,    24,    26,    27,   358,    24,
       6,    13,    20,    33,    34,    24,    82,    13,    20,    39,
      24,    24,    20,    32,    20,    45,    34,    47,     7,   771,
      50,    20,    34,     7,    24,    68,    25,    57,    34,   183,
      49,   185,    53,    20,    24,    79,    80,    67,    90,    82,
      79,    80,    72,    73,    74,    25,    36,    37,   325,    79,
     703,    35,    20,   706,    32,    42,     7,    32,    77,    78,
      45,    13,    92,   183,   816,   185,    34,    25,   183,    54,
     598,    49,   600,     0,    49,    74,    75,    76,   609,   356,
     357,   102,     7,   614,    35,   837,    85,    87,    26,    45,
     183,    43,   144,    31,    74,    75,    76,    87,    54,    77,
      78,   144,    77,    78,   183,    85,   150,   151,   152,   185,
      35,   150,   151,   152,   767,    67,    74,    75,    76,    22,
      72,    73,    74,   144,   123,    83,    84,    85,   659,   147,
     138,   157,   158,    71,     7,   147,   135,   167,     7,   166,
     129,   147,   185,   123,   143,   172,   176,    20,   156,   183,
     183,    20,    29,    45,   183,   135,    74,    75,   183,    24,
     190,   191,    54,   143,   183,   451,    90,    85,   198,   183,
     183,    48,   202,   455,   186,    48,    19,    34,    21,    48,
     186,   464,   212,   213,    74,    75,   216,   718,   716,    45,
      42,    43,    44,    45,    34,    85,    24,    25,    54,   229,
     230,   153,    54,     5,    32,     7,   183,   184,    36,    37,
     240,    24,     8,     9,    24,   167,    12,    45,    14,    15,
      16,    17,    18,   144,   176,    34,    54,    68,    56,    57,
     162,     6,   262,   165,   166,     0,   183,    65,    66,     4,
     172,     6,   183,     0,   274,     4,   198,     4,    76,     6,
     202,   347,   348,   349,   350,   351,   352,   353,   354,   289,
     290,   291,    56,    57,   216,    56,    57,    56,    57,    56,
      57,     8,     9,   345,   346,   305,   306,   183,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   183,   656,   605,   606,   183,
     183,    97,     4,    24,    25,    24,   185,    34,    34,   105,
      34,    32,    34,   185,    34,    36,    37,    34,    34,    34,
      34,    34,   274,    34,    45,    34,    34,    34,    34,    34,
      34,    34,   362,    54,    34,    56,    57,   289,   290,   291,
      34,    34,    34,    34,    65,    66,   165,   165,   378,   130,
     129,    82,    24,    29,     7,    76,    46,    46,    29,    69,
      34,   147,    13,     7,   152,     7,     7,   147,    13,   147,
     147,    34,    29,   403,    29,   449,   406,   407,   452,    35,
     183,    35,    48,    35,    72,   415,    72,    72,    72,    35,
     420,    34,   422,    24,    24,    35,    35,   427,    34,    34,
     430,    34,    24,   433,    24,    24,    33,   183,    34,    33,
     362,    34,     7,    42,     7,     7,   368,     7,   370,    69,
     372,   102,   374,     7,   376,    34,    20,   457,     7,   459,
      34,    34,   183,   183,    35,   147,   185,   185,   390,   185,
     185,   471,   185,   473,    35,     7,    35,    35,    35,    35,
      35,   403,    35,    35,   406,   407,     7,     7,     7,    35,
     490,    35,    35,    35,     7,    35,    35,    35,   420,    35,
      35,     7,     7,    29,    35,   427,    35,    35,    35,    34,
      13,    29,   183,     7,   514,   183,   183,   773,   183,    42,
      42,     7,     7,     7,    72,    34,   183,    34,     7,   148,
     183,     7,   532,   185,   183,     7,    35,   185,   185,    35,
     148,   148,   185,    35,   544,    35,   183,    29,   183,    29,
     472,     7,   474,   553,   184,     7,     7,     7,   602,     7,
      13,     7,    35,     7,    35,    35,   148,   148,   148,    35,
      13,    35,    35,    35,    35,    35,   576,    35,    35,     7,
      35,   581,   582,     7,    29,     7,   184,    29,    13,   589,
      13,   115,    13,   184,    35,    35,    35,    72,   598,    35,
     600,     7,    13,    13,    35,   605,   606,   184,   184,    35,
     532,     7,    13,   535,   355,   537,    35,   539,    35,   541,
      35,   799,   163,   800,   445,   801,    -1,    -1,    -1,   146,
      -1,    -1,    -1,   555,    -1,    -1,    -1,   637,   638,   639,
     640,    -1,   564,    -1,    -1,   645,    -1,    -1,    -1,    -1,
      -1,   651,   652,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   586,    -1,    -1,    -1,   712,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   687,    -1,   689,
     690,    -1,    -1,    -1,    -1,   695,    -1,    -1,    -1,   699,
      -1,    -1,   702,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   716,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   746,    -1,    -1,    -1,
      -1,   751,    -1,    -1,   754,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   763,    -1,   687,    -1,    -1,    -1,   691,
      -1,    -1,    -1,    -1,   696,    -1,    -1,    -1,    -1,    -1,
     780,    -1,    -1,    -1,   784,    -1,   786,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   804,   805,    -1,    -1,   808,     3,
     810,   811,    -1,    -1,    -1,    -1,    10,    11,   818,    -1,
     820,    -1,    -1,    -1,    -1,   747,    -1,    -1,    22,    23,
      -1,    25,    -1,    27,    28,    -1,    30,    31,    -1,    -1,
      -1,    -1,   842,    -1,    38,    -1,    40,    41,    42,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    88,    89,    -1,    91,    -1,    -1,
      94,    95,    96,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,    -1,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,     3,
     144,   145,   146,    -1,    -1,   149,    10,    11,    -1,   153,
      -1,   155,    -1,    -1,    -1,   159,    -1,    -1,    22,    23,
      -1,    25,    -1,    27,    28,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    40,    41,    42,   183,
      -1,   185,    -1,    47,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    88,    89,    -1,    91,    -1,    -1,
      94,    95,    96,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,    -1,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,    25,
     144,   145,   146,    -1,    -1,   149,    -1,    -1,    34,   153,
      -1,   155,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,
      -1,    67,    -1,    -1,    70,    -1,    -1,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,   132,   133,   134,   135,
     136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     9,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,   137,   138,    -1,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     9,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,
     138,    -1,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    34,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,   138,
      -1,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    34,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,   132,   133,   134,    -1,   136,   137,   138,    -1,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    34,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    -1,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,   137,   138,    -1,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    34,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,   137,   138,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   289,   290,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    86,    88,    89,
      91,    94,    95,    96,    98,    99,   100,   101,   102,   103,
     104,   106,   110,   111,   112,   113,   114,   116,   117,   131,
     139,   142,   144,   145,   146,   149,   153,   155,   159,   183,
     185,   274,   283,   285,   287,   183,   183,    24,   183,   205,
     206,   207,    26,    31,    71,   211,   212,   213,     9,    34,
      50,    51,    52,    67,    70,    73,    82,    83,    84,    86,
      94,    95,   107,   108,   109,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   132,   133,   134,
     136,   137,   138,   140,   141,   154,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   188,   189,   190,   191,   192,   193,   196,   197,   215,
     216,   217,    22,    24,    32,    49,    77,    78,   183,   202,
     203,   204,   188,   193,   218,   219,   220,    24,    36,    37,
      87,   221,   222,   223,    42,    43,    44,    45,    54,   236,
     237,   238,   188,   253,   183,   239,   242,   183,   185,   240,
     275,    24,    36,    37,   188,   227,   228,   229,    24,   230,
     231,   232,    24,    87,   233,   234,   235,   188,   188,    90,
      90,   144,    34,    34,   188,   188,    24,   224,   225,   226,
      24,   243,   244,   245,   183,   185,   241,   188,   144,    68,
      68,   144,   185,   193,   188,   183,    42,    43,   188,   257,
      34,   183,   258,   188,   246,   183,   261,   265,   183,   183,
     183,   183,   184,   268,   268,   188,   270,   157,   158,   273,
       4,     6,    13,    20,   147,   186,   280,   282,   286,     6,
       4,     4,   188,   193,    24,   188,   193,   188,   193,   188,
     193,   185,    25,    74,    75,    76,    85,   135,   188,    34,
      34,    34,    25,    74,    75,    76,    83,    84,    85,   194,
     195,   185,    20,   138,   156,    34,    34,   188,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    20,    34,   165,   162,
     165,   166,   172,   166,   172,   165,    20,   147,   198,    79,
      80,   150,   151,   152,   214,     8,     9,    12,    14,    15,
      16,    17,    18,    97,   105,   130,    19,    21,   129,    80,
     152,   214,    24,   183,   208,   209,   210,   193,    24,   183,
      24,   183,    24,   183,    24,   183,    24,    24,    25,    32,
      36,    37,    45,    54,    56,    57,    65,    66,    76,   201,
      25,    32,    36,    37,    45,    54,    56,    57,    65,    66,
     201,   188,   193,    29,   188,   193,    46,    46,    53,   102,
     144,    20,    42,   188,   188,     7,   188,   193,   188,   193,
      29,    69,   147,   188,   188,   188,   193,    34,   188,   188,
      13,   152,   188,     7,    25,    74,    75,    76,    85,   123,
     135,   143,   260,   262,   263,     7,   147,   276,   147,     7,
      20,    48,     7,     5,     7,   288,   188,    13,   281,   277,
      34,   260,   183,   283,   284,   287,   287,    29,    29,   188,
     193,    72,    72,    72,    72,    35,    35,    35,    35,    35,
      74,    75,    85,    35,   188,   193,   188,   193,   188,   193,
      34,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     192,    34,   183,   199,   200,    34,   190,   190,   189,   189,
     189,   189,   189,   189,   189,   189,   191,   192,   192,   197,
     188,   193,    24,    48,   193,    24,   193,    24,   193,    24,
     193,    24,   193,   188,    33,    56,    57,    56,    57,    45,
      54,    45,    54,    34,   193,    33,    56,    57,    56,    57,
      45,    54,    45,    54,    34,   188,   193,   188,   193,   188,
     193,   254,   256,   255,    42,   183,     7,   188,   188,   193,
     188,     7,     7,   188,   193,    69,     7,   188,   102,     7,
     188,    74,    75,    85,   264,    34,    20,   265,   278,   147,
     279,   268,     7,   260,   268,   272,   271,   287,   188,    34,
     188,   269,   188,   266,    34,   283,   183,   183,   188,   193,
     188,   193,   185,   185,   185,   185,   185,    35,    35,    35,
      35,    35,    35,    35,    35,    35,   188,     7,     7,     7,
       7,    35,    35,    35,    35,     7,    35,    35,    35,    35,
      35,     7,     7,    35,    35,    35,     7,   183,    35,    34,
     269,   266,    29,    29,   188,   193,    32,    49,    77,    78,
     193,   193,   193,   193,    29,    48,   188,   188,   193,   193,
     183,   247,   183,   249,   183,   251,   183,    13,   188,     7,
      42,    42,   148,   188,   188,     7,     7,   185,   193,    72,
     183,   188,     7,    34,   185,   259,    34,   269,   183,   267,
     269,   268,     7,   270,   270,   266,     7,   148,     7,    35,
     266,   185,   185,   185,    35,   188,   188,   188,   188,   188,
     188,   188,   197,    35,   266,   148,    35,   183,   183,    29,
      29,   184,    32,    49,    77,    78,     7,     7,   248,   250,
     252,    13,   188,   193,     7,   188,   188,   193,    35,    35,
     188,   193,   188,     7,    35,   188,   259,     7,    35,   259,
     148,     7,    20,    48,   148,   148,   268,    35,   269,   266,
      13,    35,    35,    35,     7,    35,     7,    35,    35,    35,
      35,    35,    35,   184,   184,    29,    29,   188,   193,     7,
       7,     7,   188,   188,    13,    13,    35,    35,   115,   188,
      13,    72,    35,   259,    35,   267,     7,   260,    13,   188,
      13,   188,   188,   184,   184,    35,    35,   247,   249,   251,
     188,   188,   188,    35,   188,   188,   267,     7,   188,   188,
      35,    35,    13,   267,   188
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   187,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   189,   189,   189,   190,   190,   191,   191,   191,
     192,   192,   192,   193,   194,   194,   194,   194,   194,   194,
     194,   195,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   198,
     197,   199,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   200,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   201,   201,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   203,   203,   203,   203,   203,   204,   204,   205,   205,
     206,   206,   207,   207,   208,   208,   209,   209,   210,   210,
     211,   211,   211,   212,   212,   212,   213,   213,   214,   214,
     214,   215,   215,   215,   216,   216,   216,   217,   217,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   220,
     220,   221,   221,   221,   221,   221,   222,   222,   223,   223,
     224,   225,   226,   226,   227,   227,   228,   228,   229,   229,
     230,   231,   232,   232,   233,   233,   233,   234,   234,   235,
     235,   236,   236,   236,   236,   236,   237,   237,   237,   238,
     238,   239,   239,   239,   239,   239,   239,   240,   240,   241,
     241,   242,   243,   244,   245,   245,   246,   247,   248,   247,
     249,   250,   249,   251,   252,   251,   254,   253,   255,   253,
     256,   253,   257,   257,   257,   258,   258,   259,   259,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   262,
     261,   263,   261,   264,   261,   265,   265,   266,   266,   267,
     267,   267,   267,   267,   267,   268,   268,   268,   268,   268,
     268,   268,   268,   269,   269,   270,   270,   270,   271,   270,
     272,   270,   273,   273,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   275,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   276,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   277,   274,   278,
     274,   279,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   280,   274,   281,   274,
     282,   274,   274,   274,   274,   283,   284,   283,   286,   285,
     288,   287,   287,   287,   287,   287,   290,   289
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
       4,     4,     1,     1,     1,     2,     2,     1,     1,     1,
       5,     1,     1,     2,     3,     4,     5,     4,     3,     5,
       4,     4,     3,     4,     5,     4,     3,     5,     4,     4,
       3,     5,     7,     6,     7,     6,     1,     1,     3,     4,
       3,     4,     1,     1,     3,     4,     3,     4,     1,     1,
       2,     4,     4,     2,     4,     4,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     1,     1,     4,
       2,     2,     3,     7,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     2,     2,     3,     7,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     2,     1,     1,     1,     3,     2,     3,     1,     1,
       2,     2,     1,     1,     1,     1,     6,     5,     1,     1,
       2,     2,     1,     1,     2,     1,     5,     2,     5,     1,
       1,     1,     1,     2,     3,     3,     2,     3,     3,     1,
       1,     0,     3,     4,     5,     5,     6,     1,     1,     1,
       1,     1,     6,     6,     1,     1,     1,     1,     0,     4,
       1,     0,     4,     1,     0,     4,     0,     4,     0,     4,
       0,     4,     4,     1,     1,     3,     7,     1,     3,     1,
       2,     1,     2,     1,     2,     1,     1,     1,     1,     0,
       5,     0,     6,     0,     6,     1,     3,     1,     3,     1,
       2,     3,     3,     4,     5,     1,     2,     3,     3,     4,
       5,     1,     3,     1,     3,     1,     2,     2,     0,     4,
       0,     4,     1,     1,     2,     2,     3,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     3,     1,     4,     1,     1,
       1,     0,     3,     1,     1,     2,     1,     2,     2,     3,
       2,     2,     5,     5,     6,     1,     2,     0,     6,     2,
       2,     2,     5,     8,     2,     2,     2,     0,     5,     0,
       6,     0,     6,     2,     2,     2,     2,     1,     1,     1,
       2,     2,     2,     2,     1,     2,     1,     1,     8,     8,
       8,    10,     2,     2,     3,     4,     0,     7,     0,     8,
       0,     8,     2,     1,     0,     1,     0,     4,     0,     3,
       0,     4,     1,     3,     1,     3,     0,     2
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
#line 2636 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 77 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2645 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 81 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2653 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 84 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2661 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 87 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2669 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 90 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2677 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 93 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2685 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 96 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2693 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 99 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2701 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 106 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2709 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 109 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2718 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 122 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2727 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 126 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2736 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 134 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2745 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 138 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 2754 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 145 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2762 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 150 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2770 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 153 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2778 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 156 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2786 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 159 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2794 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 162 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2802 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 165 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2810 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 168 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2818 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 173 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2826 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 178 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2835 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 182 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2844 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 186 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2853 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 190 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2862 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 194 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2871 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 198 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2880 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 202 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2889 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 206 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2898 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 210 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2907 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 214 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2916 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 218 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2925 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 222 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2934 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 226 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2943 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 230 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2952 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 234 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2961 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 238 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2970 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 242 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2979 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 246 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2988 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 250 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2997 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 254 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3006 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 258 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3015 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 262 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3024 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 266 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3033 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 270 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3042 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 274 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3051 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 278 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3060 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 282 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3069 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 288 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3078 "src-generated/ugbc.tab.c"
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
#line 3090 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 299 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3099 "src-generated/ugbc.tab.c"
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
#line 3111 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 310 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3119 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 313 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3127 "src-generated/ugbc.tab.c"
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
#line 3141 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 325 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3150 "src-generated/ugbc.tab.c"
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
#line 3162 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 336 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3171 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 340 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3180 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 344 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3189 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 348 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3198 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 352 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3207 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 356 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3216 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 360 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3225 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 364 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3234 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 368 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3242 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 371 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3250 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 374 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3258 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 377 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3266 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 380 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3274 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 383 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3282 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 386 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3290 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 389 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3298 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 392 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3306 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 395 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3314 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 398 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3322 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 401 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3330 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 404 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3338 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 407 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3346 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 410 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3354 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 413 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3362 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 416 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3370 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 419 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3378 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 422 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3386 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 425 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3394 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 428 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3402 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 431 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3410 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 434 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3418 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 437 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3426 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 440 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3434 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 443 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3442 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 446 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3450 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 449 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3458 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 452 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3466 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 455 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3474 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 458 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3482 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 461 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3490 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 464 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3498 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 466 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3507 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 470 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3515 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 473 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3523 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 476 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3532 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 480 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3541 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 484 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3550 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: PEN COLORS  */
#line 488 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3559 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: PEN DEFAULT  */
#line 492 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3568 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: WIDTH  */
#line 496 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3576 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: HEIGHT  */
#line 499 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3584 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: TIMER  */
#line 502 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3592 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: PEN DOLLAR OP expr CP  */
#line 505 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 3600 "src-generated/ugbc.tab.c"
    break;

  case 123: /* bank_definition_simple: AT direct_integer  */
#line 513 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3608 "src-generated/ugbc.tab.c"
    break;

  case 124: /* bank_definition_simple: Identifier AT direct_integer  */
#line 516 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3616 "src-generated/ugbc.tab.c"
    break;

  case 125: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 519 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3624 "src-generated/ugbc.tab.c"
    break;

  case 126: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 522 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3632 "src-generated/ugbc.tab.c"
    break;

  case 127: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 525 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3640 "src-generated/ugbc.tab.c"
    break;

  case 128: /* bank_definition_simple: DATA AT direct_integer  */
#line 528 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3648 "src-generated/ugbc.tab.c"
    break;

  case 129: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 532 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3656 "src-generated/ugbc.tab.c"
    break;

  case 130: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 535 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3664 "src-generated/ugbc.tab.c"
    break;

  case 131: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 538 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3672 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_simple: CODE AT direct_integer  */
#line 541 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3680 "src-generated/ugbc.tab.c"
    break;

  case 133: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 545 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3688 "src-generated/ugbc.tab.c"
    break;

  case 134: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 548 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3696 "src-generated/ugbc.tab.c"
    break;

  case 135: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 551 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3704 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 554 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3712 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 558 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3720 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 561 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3728 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 564 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3736 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 567 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3744 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 573 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3752 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 576 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3760 "src-generated/ugbc.tab.c"
    break;

  case 143: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 579 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3768 "src-generated/ugbc.tab.c"
    break;

  case 144: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 582 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3776 "src-generated/ugbc.tab.c"
    break;

  case 145: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 585 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3784 "src-generated/ugbc.tab.c"
    break;

  case 148: /* raster_definition_simple: Identifier AT direct_integer  */
#line 594 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3792 "src-generated/ugbc.tab.c"
    break;

  case 149: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 597 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3800 "src-generated/ugbc.tab.c"
    break;

  case 150: /* raster_definition_expression: Identifier AT expr  */
#line 602 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3808 "src-generated/ugbc.tab.c"
    break;

  case 151: /* raster_definition_expression: AT expr WITH Identifier  */
#line 605 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3816 "src-generated/ugbc.tab.c"
    break;

  case 154: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 614 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3824 "src-generated/ugbc.tab.c"
    break;

  case 155: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 617 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3832 "src-generated/ugbc.tab.c"
    break;

  case 156: /* next_raster_definition_expression: Identifier AT expr  */
#line 622 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3840 "src-generated/ugbc.tab.c"
    break;

  case 157: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 625 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3848 "src-generated/ugbc.tab.c"
    break;

  case 160: /* color_definition_simple: BORDER direct_integer  */
#line 634 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3856 "src-generated/ugbc.tab.c"
    break;

  case 161: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 637 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3864 "src-generated/ugbc.tab.c"
    break;

  case 162: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 640 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3872 "src-generated/ugbc.tab.c"
    break;

  case 163: /* color_definition_expression: BORDER expr  */
#line 645 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3880 "src-generated/ugbc.tab.c"
    break;

  case 164: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 648 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3888 "src-generated/ugbc.tab.c"
    break;

  case 165: /* color_definition_expression: SPRITE expr TO expr  */
#line 651 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3896 "src-generated/ugbc.tab.c"
    break;

  case 171: /* wait_definition_simple: direct_integer CYCLES  */
#line 665 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3904 "src-generated/ugbc.tab.c"
    break;

  case 172: /* wait_definition_simple: direct_integer TICKS  */
#line 668 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3912 "src-generated/ugbc.tab.c"
    break;

  case 173: /* wait_definition_simple: direct_integer milliseconds  */
#line 671 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3920 "src-generated/ugbc.tab.c"
    break;

  case 174: /* wait_definition_expression: expr CYCLES  */
#line 676 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3928 "src-generated/ugbc.tab.c"
    break;

  case 175: /* wait_definition_expression: expr TICKS  */
#line 679 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3936 "src-generated/ugbc.tab.c"
    break;

  case 176: /* wait_definition_expression: expr milliseconds  */
#line 682 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3944 "src-generated/ugbc.tab.c"
    break;

  case 179: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 692 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3952 "src-generated/ugbc.tab.c"
    break;

  case 180: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 695 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3960 "src-generated/ugbc.tab.c"
    break;

  case 181: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 698 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3968 "src-generated/ugbc.tab.c"
    break;

  case 182: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 701 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3976 "src-generated/ugbc.tab.c"
    break;

  case 183: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 704 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3984 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_simple: direct_integer ENABLE  */
#line 707 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3992 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_simple: direct_integer DISABLE  */
#line 710 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4000 "src-generated/ugbc.tab.c"
    break;

  case 186: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 713 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4008 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 716 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4016 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 719 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4024 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 722 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4032 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 725 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4040 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 728 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4048 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 731 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4056 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 734 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4064 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_expression: expr DATA FROM expr  */
#line 739 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4072 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_expression: expr MULTICOLOR  */
#line 742 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4080 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_expression: expr MONOCOLOR  */
#line 745 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4088 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_expression: expr COLOR expr  */
#line 748 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4096 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 751 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4104 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_expression: expr ENABLE  */
#line 754 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4112 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_expression: expr DISABLE  */
#line 757 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4120 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 760 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4128 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 763 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4136 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 766 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4144 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 769 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4152 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 772 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4160 "src-generated/ugbc.tab.c"
    break;

  case 206: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 775 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4168 "src-generated/ugbc.tab.c"
    break;

  case 207: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 778 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4176 "src-generated/ugbc.tab.c"
    break;

  case 208: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 781 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4184 "src-generated/ugbc.tab.c"
    break;

  case 211: /* bitmap_definition_simple: AT direct_integer  */
#line 790 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4192 "src-generated/ugbc.tab.c"
    break;

  case 212: /* bitmap_definition_simple: ENABLE  */
#line 793 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4200 "src-generated/ugbc.tab.c"
    break;

  case 213: /* bitmap_definition_simple: DISABLE  */
#line 796 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4208 "src-generated/ugbc.tab.c"
    break;

  case 214: /* bitmap_definition_simple: CLEAR  */
#line 799 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4216 "src-generated/ugbc.tab.c"
    break;

  case 215: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 802 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4224 "src-generated/ugbc.tab.c"
    break;

  case 216: /* bitmap_definition_expression: AT expr  */
#line 808 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4232 "src-generated/ugbc.tab.c"
    break;

  case 217: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 811 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4240 "src-generated/ugbc.tab.c"
    break;

  case 220: /* textmap_definition_simple: AT direct_integer  */
#line 821 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4248 "src-generated/ugbc.tab.c"
    break;

  case 221: /* textmap_definition_expression: AT expr  */
#line 826 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4256 "src-generated/ugbc.tab.c"
    break;

  case 224: /* text_definition_simple: ENABLE  */
#line 835 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4264 "src-generated/ugbc.tab.c"
    break;

  case 225: /* text_definition_simple: DISABLE  */
#line 838 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4272 "src-generated/ugbc.tab.c"
    break;

  case 226: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 843 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4280 "src-generated/ugbc.tab.c"
    break;

  case 227: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 846 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4288 "src-generated/ugbc.tab.c"
    break;

  case 230: /* tiles_definition_simple: AT direct_integer  */
#line 855 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4296 "src-generated/ugbc.tab.c"
    break;

  case 231: /* tiles_definition_expression: AT expr  */
#line 860 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4304 "src-generated/ugbc.tab.c"
    break;

  case 234: /* colormap_definition_simple: AT direct_integer  */
#line 869 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4312 "src-generated/ugbc.tab.c"
    break;

  case 235: /* colormap_definition_simple: CLEAR  */
#line 872 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4320 "src-generated/ugbc.tab.c"
    break;

  case 236: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 875 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4328 "src-generated/ugbc.tab.c"
    break;

  case 237: /* colormap_definition_expression: AT expr  */
#line 880 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4336 "src-generated/ugbc.tab.c"
    break;

  case 238: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 883 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4344 "src-generated/ugbc.tab.c"
    break;

  case 241: /* screen_definition_simple: ON  */
#line 893 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4352 "src-generated/ugbc.tab.c"
    break;

  case 242: /* screen_definition_simple: OFF  */
#line 896 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4360 "src-generated/ugbc.tab.c"
    break;

  case 243: /* screen_definition_simple: ROWS direct_integer  */
#line 899 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4368 "src-generated/ugbc.tab.c"
    break;

  case 244: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 902 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4376 "src-generated/ugbc.tab.c"
    break;

  case 245: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 905 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4384 "src-generated/ugbc.tab.c"
    break;

  case 246: /* screen_definition_expression: ROWS expr  */
#line 910 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4392 "src-generated/ugbc.tab.c"
    break;

  case 247: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 913 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4400 "src-generated/ugbc.tab.c"
    break;

  case 248: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 916 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4408 "src-generated/ugbc.tab.c"
    break;

  case 252: /* var_definition_simple: Identifier ON Identifier  */
#line 925 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4416 "src-generated/ugbc.tab.c"
    break;

  case 253: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 928 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4424 "src-generated/ugbc.tab.c"
    break;

  case 254: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 931 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4432 "src-generated/ugbc.tab.c"
    break;

  case 255: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 934 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4442 "src-generated/ugbc.tab.c"
    break;

  case 256: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 939 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4452 "src-generated/ugbc.tab.c"
    break;

  case 257: /* goto_definition: Identifier  */
#line 946 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4460 "src-generated/ugbc.tab.c"
    break;

  case 258: /* goto_definition: Integer  */
#line 949 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4468 "src-generated/ugbc.tab.c"
    break;

  case 259: /* gosub_definition: Identifier  */
#line 955 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4476 "src-generated/ugbc.tab.c"
    break;

  case 260: /* gosub_definition: Integer  */
#line 958 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4484 "src-generated/ugbc.tab.c"
    break;

  case 262: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 967 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4492 "src-generated/ugbc.tab.c"
    break;

  case 263: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 973 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4500 "src-generated/ugbc.tab.c"
    break;

  case 266: /* ink_definition: expr  */
#line 982 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4508 "src-generated/ugbc.tab.c"
    break;

  case 267: /* on_goto_definition: Identifier  */
#line 987 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4517 "src-generated/ugbc.tab.c"
    break;

  case 268: /* $@4: %empty  */
#line 991 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4525 "src-generated/ugbc.tab.c"
    break;

  case 270: /* on_gosub_definition: Identifier  */
#line 996 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4534 "src-generated/ugbc.tab.c"
    break;

  case 271: /* $@5: %empty  */
#line 1000 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4542 "src-generated/ugbc.tab.c"
    break;

  case 273: /* on_proc_definition: Identifier  */
#line 1005 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4551 "src-generated/ugbc.tab.c"
    break;

  case 274: /* $@6: %empty  */
#line 1009 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4559 "src-generated/ugbc.tab.c"
    break;

  case 276: /* $@7: %empty  */
#line 1014 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4567 "src-generated/ugbc.tab.c"
    break;

  case 278: /* $@8: %empty  */
#line 1017 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4575 "src-generated/ugbc.tab.c"
    break;

  case 280: /* $@9: %empty  */
#line 1020 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4583 "src-generated/ugbc.tab.c"
    break;

  case 282: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1025 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4591 "src-generated/ugbc.tab.c"
    break;

  case 283: /* every_definition: ON  */
#line 1028 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4599 "src-generated/ugbc.tab.c"
    break;

  case 284: /* every_definition: OFF  */
#line 1031 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4607 "src-generated/ugbc.tab.c"
    break;

  case 285: /* add_definition: Identifier COMMA expr  */
#line 1036 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4615 "src-generated/ugbc.tab.c"
    break;

  case 286: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1039 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4623 "src-generated/ugbc.tab.c"
    break;

  case 287: /* dimensions: Integer  */
#line 1045 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4632 "src-generated/ugbc.tab.c"
    break;

  case 288: /* dimensions: Integer COMMA dimensions  */
#line 1049 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4641 "src-generated/ugbc.tab.c"
    break;

  case 289: /* datatype: BYTE  */
#line 1056 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 4649 "src-generated/ugbc.tab.c"
    break;

  case 290: /* datatype: SIGNED BYTE  */
#line 1059 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 4657 "src-generated/ugbc.tab.c"
    break;

  case 291: /* datatype: WORD  */
#line 1062 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 4665 "src-generated/ugbc.tab.c"
    break;

  case 292: /* datatype: SIGNED WORD  */
#line 1065 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 4673 "src-generated/ugbc.tab.c"
    break;

  case 293: /* datatype: DWORD  */
#line 1068 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 4681 "src-generated/ugbc.tab.c"
    break;

  case 294: /* datatype: SIGNED DWORD  */
#line 1071 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 4689 "src-generated/ugbc.tab.c"
    break;

  case 295: /* datatype: ADDRESS  */
#line 1074 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 4697 "src-generated/ugbc.tab.c"
    break;

  case 296: /* datatype: POSITION  */
#line 1077 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 4705 "src-generated/ugbc.tab.c"
    break;

  case 297: /* datatype: COLOR  */
#line 1080 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 4713 "src-generated/ugbc.tab.c"
    break;

  case 298: /* datatype: STRING  */
#line 1083 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 4721 "src-generated/ugbc.tab.c"
    break;

  case 299: /* $@10: %empty  */
#line 1088 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4730 "src-generated/ugbc.tab.c"
    break;

  case 300: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1091 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 4740 "src-generated/ugbc.tab.c"
    break;

  case 301: /* $@11: %empty  */
#line 1096 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4749 "src-generated/ugbc.tab.c"
    break;

  case 302: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1099 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 4759 "src-generated/ugbc.tab.c"
    break;

  case 303: /* $@12: %empty  */
#line 1104 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4768 "src-generated/ugbc.tab.c"
    break;

  case 304: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1107 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 4778 "src-generated/ugbc.tab.c"
    break;

  case 307: /* indexes: expr  */
#line 1120 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4787 "src-generated/ugbc.tab.c"
    break;

  case 308: /* indexes: expr COMMA indexes  */
#line 1124 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4796 "src-generated/ugbc.tab.c"
    break;

  case 309: /* parameters: Identifier  */
#line 1131 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4806 "src-generated/ugbc.tab.c"
    break;

  case 310: /* parameters: Identifier DOLLAR  */
#line 1136 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4816 "src-generated/ugbc.tab.c"
    break;

  case 311: /* parameters: Identifier AS datatype  */
#line 1141 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4826 "src-generated/ugbc.tab.c"
    break;

  case 312: /* parameters: Identifier COMMA parameters  */
#line 1146 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4836 "src-generated/ugbc.tab.c"
    break;

  case 313: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1151 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4846 "src-generated/ugbc.tab.c"
    break;

  case 314: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1156 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4856 "src-generated/ugbc.tab.c"
    break;

  case 315: /* parameters_expr: Identifier  */
#line 1164 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4866 "src-generated/ugbc.tab.c"
    break;

  case 316: /* parameters_expr: Identifier DOLLAR  */
#line 1169 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4876 "src-generated/ugbc.tab.c"
    break;

  case 317: /* parameters_expr: Identifier AS datatype  */
#line 1174 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4886 "src-generated/ugbc.tab.c"
    break;

  case 318: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1179 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4896 "src-generated/ugbc.tab.c"
    break;

  case 319: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1184 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4906 "src-generated/ugbc.tab.c"
    break;

  case 320: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1189 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4916 "src-generated/ugbc.tab.c"
    break;

  case 321: /* parameters_expr: String  */
#line 1194 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4925 "src-generated/ugbc.tab.c"
    break;

  case 322: /* parameters_expr: String COMMA parameters_expr  */
#line 1198 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4934 "src-generated/ugbc.tab.c"
    break;

  case 323: /* values: expr  */
#line 1205 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4943 "src-generated/ugbc.tab.c"
    break;

  case 324: /* values: expr COMMA values  */
#line 1209 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4952 "src-generated/ugbc.tab.c"
    break;

  case 325: /* print_definition: expr  */
#line 1216 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 4960 "src-generated/ugbc.tab.c"
    break;

  case 326: /* print_definition: expr COMMA  */
#line 1219 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 4969 "src-generated/ugbc.tab.c"
    break;

  case 327: /* print_definition: expr SEMICOLON  */
#line 1223 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 4977 "src-generated/ugbc.tab.c"
    break;

  case 328: /* $@13: %empty  */
#line 1226 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 4986 "src-generated/ugbc.tab.c"
    break;

  case 330: /* $@14: %empty  */
#line 1230 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 4994 "src-generated/ugbc.tab.c"
    break;

  case 332: /* use_definition: ANSI  */
#line 1236 "src/ugbc.y"
         {
        use_ansi( _environment );
    }
#line 5002 "src-generated/ugbc.tab.c"
    break;

  case 333: /* use_definition: SPECIFIC  */
#line 1239 "src/ugbc.y"
             {
        use_specific( _environment );
  }
#line 5010 "src-generated/ugbc.tab.c"
    break;

  case 351: /* statement: INC Identifier  */
#line 1262 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 5018 "src-generated/ugbc.tab.c"
    break;

  case 352: /* statement: DEC Identifier  */
#line 1265 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 5026 "src-generated/ugbc.tab.c"
    break;

  case 353: /* statement: RANDOMIZE  */
#line 1268 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 5034 "src-generated/ugbc.tab.c"
    break;

  case 354: /* statement: RANDOMIZE expr  */
#line 1271 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 5042 "src-generated/ugbc.tab.c"
    break;

  case 355: /* statement: IF expr THEN  */
#line 1274 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5050 "src-generated/ugbc.tab.c"
    break;

  case 356: /* statement: ELSE  */
#line 1277 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 5058 "src-generated/ugbc.tab.c"
    break;

  case 357: /* statement: ELSE IF expr THEN  */
#line 1280 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5066 "src-generated/ugbc.tab.c"
    break;

  case 358: /* statement: ENDIF  */
#line 1283 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5074 "src-generated/ugbc.tab.c"
    break;

  case 359: /* statement: DO  */
#line 1286 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5082 "src-generated/ugbc.tab.c"
    break;

  case 360: /* statement: LOOP  */
#line 1289 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5090 "src-generated/ugbc.tab.c"
    break;

  case 361: /* $@15: %empty  */
#line 1292 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5098 "src-generated/ugbc.tab.c"
    break;

  case 362: /* statement: WHILE $@15 expr  */
#line 1294 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5106 "src-generated/ugbc.tab.c"
    break;

  case 363: /* statement: WEND  */
#line 1297 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5114 "src-generated/ugbc.tab.c"
    break;

  case 364: /* statement: REPEAT  */
#line 1300 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5122 "src-generated/ugbc.tab.c"
    break;

  case 365: /* statement: UNTIL expr  */
#line 1303 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5130 "src-generated/ugbc.tab.c"
    break;

  case 366: /* statement: EXIT  */
#line 1306 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5138 "src-generated/ugbc.tab.c"
    break;

  case 367: /* statement: EXIT PROC  */
#line 1309 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5146 "src-generated/ugbc.tab.c"
    break;

  case 368: /* statement: POP PROC  */
#line 1312 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5154 "src-generated/ugbc.tab.c"
    break;

  case 369: /* statement: EXIT IF expr  */
#line 1315 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5162 "src-generated/ugbc.tab.c"
    break;

  case 370: /* statement: EXIT Integer  */
#line 1318 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5170 "src-generated/ugbc.tab.c"
    break;

  case 371: /* statement: EXIT direct_integer  */
#line 1321 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5178 "src-generated/ugbc.tab.c"
    break;

  case 372: /* statement: EXIT IF expr COMMA Integer  */
#line 1324 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5186 "src-generated/ugbc.tab.c"
    break;

  case 373: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1327 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5194 "src-generated/ugbc.tab.c"
    break;

  case 374: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1330 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5202 "src-generated/ugbc.tab.c"
    break;

  case 375: /* statement: NEXT  */
#line 1333 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5210 "src-generated/ugbc.tab.c"
    break;

  case 376: /* statement: PROCEDURE Identifier  */
#line 1336 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5219 "src-generated/ugbc.tab.c"
    break;

  case 377: /* $@16: %empty  */
#line 1340 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5227 "src-generated/ugbc.tab.c"
    break;

  case 378: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1342 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5235 "src-generated/ugbc.tab.c"
    break;

  case 379: /* statement: SHARED parameters_expr  */
#line 1345 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5243 "src-generated/ugbc.tab.c"
    break;

  case 380: /* statement: GLOBAL parameters_expr  */
#line 1348 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5251 "src-generated/ugbc.tab.c"
    break;

  case 381: /* statement: END PROC  */
#line 1351 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 5259 "src-generated/ugbc.tab.c"
    break;

  case 382: /* statement: END PROC OSP expr CSP  */
#line 1354 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5267 "src-generated/ugbc.tab.c"
    break;

  case 383: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1357 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5275 "src-generated/ugbc.tab.c"
    break;

  case 384: /* statement: Identifier " "  */
#line 1360 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5284 "src-generated/ugbc.tab.c"
    break;

  case 385: /* statement: PROC Identifier  */
#line 1364 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5293 "src-generated/ugbc.tab.c"
    break;

  case 386: /* statement: CALL Identifier  */
#line 1368 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5302 "src-generated/ugbc.tab.c"
    break;

  case 387: /* $@17: %empty  */
#line 1372 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5310 "src-generated/ugbc.tab.c"
    break;

  case 388: /* statement: Identifier OSP $@17 values CSP  */
#line 1374 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5318 "src-generated/ugbc.tab.c"
    break;

  case 389: /* $@18: %empty  */
#line 1377 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5326 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1379 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5334 "src-generated/ugbc.tab.c"
    break;

  case 391: /* $@19: %empty  */
#line 1382 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5342 "src-generated/ugbc.tab.c"
    break;

  case 392: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1384 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5350 "src-generated/ugbc.tab.c"
    break;

  case 393: /* statement: PEN expr  */
#line 1387 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 5358 "src-generated/ugbc.tab.c"
    break;

  case 394: /* statement: Identifier COLON  */
#line 1390 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 5366 "src-generated/ugbc.tab.c"
    break;

  case 395: /* statement: BEG GAMELOOP  */
#line 1393 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 5374 "src-generated/ugbc.tab.c"
    break;

  case 396: /* statement: END GAMELOOP  */
#line 1396 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 5382 "src-generated/ugbc.tab.c"
    break;

  case 397: /* statement: GRAPHIC  */
#line 1399 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 5390 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statement: HALT  */
#line 1402 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 5398 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: END  */
#line 1405 "src/ugbc.y"
        {
      end( _environment );
  }
#line 5406 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: RETURN  */
#line 1412 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 5414 "src-generated/ugbc.tab.c"
    break;

  case 405: /* statement: RETURN expr  */
#line 1415 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 5422 "src-generated/ugbc.tab.c"
    break;

  case 406: /* statement: POP  */
#line 1418 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 5430 "src-generated/ugbc.tab.c"
    break;

  case 407: /* statement: DONE  */
#line 1421 "src/ugbc.y"
          {
      return 0;
  }
#line 5438 "src-generated/ugbc.tab.c"
    break;

  case 408: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1424 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5446 "src-generated/ugbc.tab.c"
    break;

  case 409: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1427 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5454 "src-generated/ugbc.tab.c"
    break;

  case 410: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1430 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 5462 "src-generated/ugbc.tab.c"
    break;

  case 411: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1433 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5470 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: Identifier ASSIGN expr  */
#line 1438 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 5484 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1447 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 5498 "src-generated/ugbc.tab.c"
    break;

  case 416: /* $@20: %empty  */
#line 1456 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5507 "src-generated/ugbc.tab.c"
    break;

  case 417: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1460 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 5520 "src-generated/ugbc.tab.c"
    break;

  case 418: /* $@21: %empty  */
#line 1468 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5529 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1471 "src/ugbc.y"
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
#line 5548 "src-generated/ugbc.tab.c"
    break;

  case 420: /* $@22: %empty  */
#line 1485 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5557 "src-generated/ugbc.tab.c"
    break;

  case 421: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1488 "src/ugbc.y"
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
#line 5576 "src-generated/ugbc.tab.c"
    break;

  case 422: /* statement: DEBUG expr  */
#line 1502 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 5584 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statements_no_linenumbers: statement  */
#line 1510 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 5590 "src-generated/ugbc.tab.c"
    break;

  case 426: /* $@23: %empty  */
#line 1511 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 5596 "src-generated/ugbc.tab.c"
    break;

  case 428: /* $@24: %empty  */
#line 1515 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 5604 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1517 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 5612 "src-generated/ugbc.tab.c"
    break;

  case 430: /* $@25: %empty  */
#line 1522 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 5620 "src-generated/ugbc.tab.c"
    break;

  case 436: /* $@26: %empty  */
#line 1532 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 5626 "src-generated/ugbc.tab.c"
    break;


#line 5630 "src-generated/ugbc.tab.c"

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

#line 1534 "src/ugbc.y"


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

