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
  YYSYMBOL_BLACK = 161,                    /* BLACK  */
  YYSYMBOL_WHITE = 162,                    /* WHITE  */
  YYSYMBOL_RED = 163,                      /* RED  */
  YYSYMBOL_CYAN = 164,                     /* CYAN  */
  YYSYMBOL_VIOLET = 165,                   /* VIOLET  */
  YYSYMBOL_GREEN = 166,                    /* GREEN  */
  YYSYMBOL_BLUE = 167,                     /* BLUE  */
  YYSYMBOL_YELLOW = 168,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 169,                   /* ORANGE  */
  YYSYMBOL_BROWN = 170,                    /* BROWN  */
  YYSYMBOL_LIGHT = 171,                    /* LIGHT  */
  YYSYMBOL_DARK = 172,                     /* DARK  */
  YYSYMBOL_GREY = 173,                     /* GREY  */
  YYSYMBOL_GRAY = 174,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 175,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 176,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 177,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 178,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 179,                /* TURQUOISE  */
  YYSYMBOL_TAN = 180,                      /* TAN  */
  YYSYMBOL_PINK = 181,                     /* PINK  */
  YYSYMBOL_PEACH = 182,                    /* PEACH  */
  YYSYMBOL_OLIVE = 183,                    /* OLIVE  */
  YYSYMBOL_Identifier = 184,               /* Identifier  */
  YYSYMBOL_String = 185,                   /* String  */
  YYSYMBOL_Integer = 186,                  /* Integer  */
  YYSYMBOL_187_ = 187,                     /* " "  */
  YYSYMBOL_YYACCEPT = 188,                 /* $accept  */
  YYSYMBOL_expr = 189,                     /* expr  */
  YYSYMBOL_expr_math = 190,                /* expr_math  */
  YYSYMBOL_term = 191,                     /* term  */
  YYSYMBOL_modula = 192,                   /* modula  */
  YYSYMBOL_factor = 193,                   /* factor  */
  YYSYMBOL_direct_integer = 194,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 195, /* random_definition_simple  */
  YYSYMBOL_random_definition = 196,        /* random_definition  */
  YYSYMBOL_color_enumeration = 197,        /* color_enumeration  */
  YYSYMBOL_exponential = 198,              /* exponential  */
  YYSYMBOL_199_1 = 199,                    /* $@1  */
  YYSYMBOL_200_2 = 200,                    /* $@2  */
  YYSYMBOL_201_3 = 201,                    /* $@3  */
  YYSYMBOL_position = 202,                 /* position  */
  YYSYMBOL_bank_definition_simple = 203,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 204, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 205,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 206, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 207, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 208,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 209, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 210, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 211,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 212,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 213, /* color_definition_expression  */
  YYSYMBOL_color_definition = 214,         /* color_definition  */
  YYSYMBOL_milliseconds = 215,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 216,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 217, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 218,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 219, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 220, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 221,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 222, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 223, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 224,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 225, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 226, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 227,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 228,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 229, /* text_definition_expression  */
  YYSYMBOL_text_definition = 230,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 231,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 232, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 233,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 234, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 235, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 236,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 237, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 238, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 239,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 240,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 241,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 242,         /* gosub_definition  */
  YYSYMBOL_var_definition = 243,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 244,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 245, /* point_definition_expression  */
  YYSYMBOL_point_definition = 246,         /* point_definition  */
  YYSYMBOL_ink_definition = 247,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 248,       /* on_goto_definition  */
  YYSYMBOL_249_4 = 249,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 250,      /* on_gosub_definition  */
  YYSYMBOL_251_5 = 251,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 252,       /* on_proc_definition  */
  YYSYMBOL_253_6 = 253,                    /* $@6  */
  YYSYMBOL_on_definition = 254,            /* on_definition  */
  YYSYMBOL_255_7 = 255,                    /* $@7  */
  YYSYMBOL_256_8 = 256,                    /* $@8  */
  YYSYMBOL_257_9 = 257,                    /* $@9  */
  YYSYMBOL_every_definition = 258,         /* every_definition  */
  YYSYMBOL_add_definition = 259,           /* add_definition  */
  YYSYMBOL_dimensions = 260,               /* dimensions  */
  YYSYMBOL_datatype = 261,                 /* datatype  */
  YYSYMBOL_dim_definition = 262,           /* dim_definition  */
  YYSYMBOL_263_10 = 263,                   /* $@10  */
  YYSYMBOL_264_11 = 264,                   /* $@11  */
  YYSYMBOL_265_12 = 265,                   /* $@12  */
  YYSYMBOL_dim_definitions = 266,          /* dim_definitions  */
  YYSYMBOL_indexes = 267,                  /* indexes  */
  YYSYMBOL_parameters = 268,               /* parameters  */
  YYSYMBOL_parameters_expr = 269,          /* parameters_expr  */
  YYSYMBOL_values = 270,                   /* values  */
  YYSYMBOL_print_definition = 271,         /* print_definition  */
  YYSYMBOL_272_13 = 272,                   /* $@13  */
  YYSYMBOL_273_14 = 273,                   /* $@14  */
  YYSYMBOL_use_definition = 274,           /* use_definition  */
  YYSYMBOL_statement = 275,                /* statement  */
  YYSYMBOL_276_15 = 276,                   /* $@15  */
  YYSYMBOL_277_16 = 277,                   /* $@16  */
  YYSYMBOL_278_17 = 278,                   /* $@17  */
  YYSYMBOL_279_18 = 279,                   /* $@18  */
  YYSYMBOL_280_19 = 280,                   /* $@19  */
  YYSYMBOL_281_20 = 281,                   /* $@20  */
  YYSYMBOL_282_21 = 282,                   /* $@21  */
  YYSYMBOL_283_22 = 283,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 284, /* statements_no_linenumbers  */
  YYSYMBOL_285_23 = 285,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 286, /* statements_with_linenumbers  */
  YYSYMBOL_287_24 = 287,                   /* $@24  */
  YYSYMBOL_statements_complex = 288,       /* statements_complex  */
  YYSYMBOL_289_25 = 289,                   /* $@25  */
  YYSYMBOL_program = 290,                  /* program  */
  YYSYMBOL_291_26 = 291                    /* $@26  */
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
#define YYLAST   2133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  188
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  104
/* YYNRULES -- Number of rules.  */
#define YYNRULES  442
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  853

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   442


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
     185,   186,   187
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
     509,   513,   516,   519,   522,   527,   527,   530,   533,   536,
     539,   542,   545,   549,   552,   555,   558,   562,   565,   568,
     571,   575,   578,   581,   584,   590,   593,   596,   599,   602,
     607,   608,   611,   614,   619,   622,   627,   628,   631,   634,
     639,   642,   647,   648,   651,   654,   657,   662,   665,   668,
     673,   674,   677,   678,   679,   682,   685,   688,   693,   696,
     699,   705,   706,   709,   712,   715,   718,   721,   724,   727,
     730,   733,   736,   739,   742,   745,   748,   751,   756,   759,
     762,   765,   768,   771,   774,   777,   780,   783,   786,   789,
     792,   795,   798,   803,   804,   807,   810,   813,   816,   819,
     825,   828,   834,   835,   838,   843,   848,   849,   852,   855,
     860,   863,   868,   869,   872,   877,   882,   883,   886,   889,
     892,   897,   900,   906,   907,   910,   913,   916,   919,   922,
     927,   930,   933,   938,   939,   941,   942,   945,   948,   951,
     956,   963,   966,   972,   975,   981,   984,   990,   995,   996,
     999,  1004,  1008,  1008,  1013,  1017,  1017,  1022,  1026,  1026,
    1031,  1031,  1034,  1034,  1037,  1037,  1042,  1045,  1048,  1053,
    1056,  1062,  1066,  1073,  1076,  1079,  1082,  1085,  1088,  1091,
    1094,  1097,  1100,  1105,  1105,  1113,  1113,  1121,  1121,  1132,
    1133,  1137,  1141,  1148,  1153,  1158,  1163,  1168,  1173,  1181,
    1186,  1191,  1196,  1201,  1206,  1211,  1215,  1222,  1226,  1233,
    1236,  1240,  1243,  1243,  1247,  1247,  1253,  1256,  1262,  1263,
    1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,
    1274,  1275,  1276,  1277,  1278,  1279,  1282,  1285,  1288,  1291,
    1294,  1297,  1300,  1303,  1306,  1309,  1309,  1314,  1317,  1320,
    1323,  1326,  1329,  1332,  1335,  1338,  1341,  1344,  1347,  1350,
    1353,  1357,  1357,  1362,  1365,  1368,  1371,  1374,  1377,  1381,
    1385,  1389,  1389,  1394,  1394,  1399,  1399,  1404,  1407,  1410,
    1413,  1416,  1419,  1422,  1425,  1428,  1429,  1430,  1431,  1432,
    1435,  1438,  1441,  1444,  1447,  1450,  1453,  1456,  1457,  1458,
    1467,  1476,  1476,  1488,  1488,  1505,  1505,  1522,  1525,  1526,
    1530,  1531,  1531,  1535,  1535,  1542,  1542,  1545,  1546,  1547,
    1548,  1552,  1552
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
  "PARAM", "PRINT", "DEFAULT", "SPECIFIC", "ANSI", "USE", "PAPER", "BLACK",
  "WHITE", "RED", "CYAN", "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE",
  "BROWN", "LIGHT", "DARK", "GREY", "GRAY", "MAGENTA", "PURPLE",
  "LAVENDER", "GOLD", "TURQUOISE", "TAN", "PINK", "PEACH", "OLIVE",
  "Identifier", "String", "Integer", "\" \"", "$accept", "expr",
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
     435,   436,   437,   438,   439,   440,   441,   442
};
#endif

#define YYPACT_NINF (-737)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-422)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -737,    32,   804,  -737,  -737,   -93,   -82,   -13,  -737,    46,
    1527,    86,    18,  1527,  -737,    50,   171,  1667,   -53,  -129,
    -737,  -737,  -737,  1222,   141,    47,  1667,  1667,    80,   -44,
    -737,   170,   177,  1667,  1667,  -737,   153,   208,   -35,  1667,
      90,   187,  -737,   -30,  -737,  1667,    56,  1387,   226,    94,
    1667,    96,   102,   110,   111,    15,    15,  1667,    72,  1667,
      14,  -737,   258,   292,   293,  -737,  -737,  -737,  1527,   274,
    -737,  -737,  -737,  1527,  1527,  1527,  -737,  -737,  -737,   134,
    1057,  -737,  -737,   287,   288,   289,   143,   139,  -737,  -737,
      -6,   294,   295,  1667,  -737,  -737,   296,   297,   299,   301,
     303,   306,   307,   308,   309,   310,   311,   323,   330,   331,
     332,   335,   336,  -737,  -737,   337,    48,   -47,   -23,  -737,
    -737,  -737,  -737,  -737,  -737,  -737,   206,  -737,  -737,    85,
     -89,  -737,  -737,  -737,  -737,  -737,  -737,  -737,  -737,  -737,
     207,    11,  -737,  -737,   -26,   227,   244,   138,   246,    42,
    -737,  -737,  -737,  -737,  -737,    -9,   254,    -2,     1,     4,
       6,   353,  -737,  -737,  -737,   225,   302,  -737,  -737,  -737,
    1527,  -737,  -737,   350,  -737,  -737,  -737,  -737,  -737,  1527,
     334,   338,  -737,  -737,  -737,   -17,  -737,    55,  -737,  -737,
    -737,  -737,  -737,  1667,  1667,  -737,  -737,   374,  -737,  -737,
    -737,  1527,  -737,  -737,  -737,  1527,   354,  -737,  -737,  -737,
     313,  -737,  -737,  -737,   238,  1667,  1667,  -737,  -737,  1527,
    -737,  -737,  -737,   352,  -737,  -737,  -737,  -737,  -737,  -737,
    -737,  -737,  1667,  1667,  -737,  -737,  -737,  -737,   375,  -737,
    -737,   235,  -737,  1667,   382,  -737,  -737,  -737,    31,   383,
    -737,   245,   247,   248,    53,   384,  -737,  -737,   191,  -737,
    -737,  -737,  -737,  -737,  -737,  -737,  1667,   380,  -737,  -737,
     362,    44,   944,  -737,   804,   804,   368,   369,  1527,  -737,
    -737,   327,   328,   339,   340,  -737,   367,   372,   373,   379,
     381,    70,   386,  1527,  1527,  1527,  -737,  -737,  -737,  -737,
    -737,  -737,  -737,  -737,  -737,  -737,   376,  -737,  -737,  1667,
    1667,  -737,  1667,  1667,  1667,  1667,  1667,  1667,  1667,  1667,
    1667,  1667,  1667,  1667,  1667,  1667,  1667,  1667,  1667,  1807,
     385,   231,  -737,  -737,  -737,  -737,  -737,  -737,  -737,  -737,
    -737,  -737,  -737,  -737,   388,  -737,   389,  -737,  -737,  -737,
    -737,  -737,  -737,  1807,  1807,  1807,  1807,  1807,  1807,  1807,
    1807,  1807,  1807,  1807,  1807,  1807,  1947,  -737,  -737,  -737,
    1527,   393,  -737,  -737,  -737,   361,   254,   400,   254,   402,
     254,   403,   254,   405,   254,  -737,  1667,   397,  -737,  -737,
     197,   210,   108,   119,  -737,  -737,  -737,   398,   254,   401,
    -737,  -737,   215,   218,   158,   192,  -737,  -737,   399,  -737,
    -737,  1527,  -737,  -737,  1527,  1527,  -737,  -737,  -737,   394,
     251,  -737,   430,  1667,  -737,  -737,  -737,  -737,  1527,  -737,
    1667,   432,   433,  -737,  -737,  1527,   378,   434,  1667,   341,
     435,  1667,  -737,  -737,  -737,  -737,  -737,  -737,   146,  -737,
    -737,   411,   429,    96,  -737,   304,  -737,    15,   446,    44,
      15,   172,   259,   804,  -737,  1667,   420,  1667,  1667,   422,
      -1,  -737,   944,  -737,  -737,   275,   276,  -737,  -737,  1667,
     254,  1667,   254,   272,   277,   278,   279,   281,   426,   427,
     437,  -737,   438,   439,   440,   441,   442,   443,  1667,   461,
     463,   473,   474,   449,   450,   451,   452,   482,   455,   456,
     457,   458,   459,   488,   490,   464,   465,   466,    34,   314,
     467,   470,  1667,  1667,   244,   244,   268,   268,   268,   268,
     268,   268,   268,   268,   138,   246,   246,  -737,   476,   477,
    1527,    61,  -737,   254,  -737,   254,  -737,   254,  -737,   254,
      99,  -737,  1667,  -737,  -737,  -737,  -737,  -737,  -737,  -737,
    -737,  1667,  -737,   254,  -737,  -737,  -737,  -737,  -737,  -737,
    -737,  -737,   254,  -737,  -737,  -737,  -737,  -737,  -737,   324,
     325,   326,   329,   494,  1667,   507,   475,   478,   370,  1667,
    1667,   508,   509,  -737,   -56,   447,   342,  1667,   514,  -737,
    -737,  -737,   489,   343,   491,  -737,  1667,   344,  1667,  -737,
      15,   515,  -737,  1667,  1667,  -737,  -737,  1667,   517,   387,
     520,   496,  1667,  -737,  -737,  -737,  -737,  -737,  -737,  -737,
    -737,  -737,  -737,  -737,  -737,   346,   347,   348,  -737,  -737,
    -737,  -737,  -737,  -737,   501,  1667,  1667,  1667,  1667,  -737,
    -737,  -737,  -737,  1667,  -737,  -737,  -737,  -737,  -737,  1667,
    1667,  -737,  -737,  -737,  1947,   502,  -737,  1667,   390,   504,
     356,   357,  -737,  -737,  -737,  -737,  -737,  -737,   516,  -737,
     518,  -737,   358,   103,  -737,   537,  -737,   539,   542,  -737,
     545,  -737,   546,  -737,   541,  1527,   548,  1667,  1667,   254,
    -737,   522,   523,  1667,   254,  -737,  -737,  1667,  -737,    54,
    1667,   343,   552,   525,   343,   413,    92,   414,   415,  -737,
      15,  -737,  -737,   529,  1667,  -737,  1667,   553,   530,  -737,
    -737,  -737,  -737,   532,   533,    59,    69,   534,   535,   536,
     538,  -737,   540,  -737,  -737,  -737,  -737,   391,   392,  -737,
     543,  -737,   549,  -737,  1667,   254,   574,   575,   576,  1667,
    -737,  -737,  1667,  -737,  -737,  -737,   571,   572,   551,   554,
     479,  1667,   577,   519,   557,   343,  -737,   558,  -737,   344,
     581,    44,  -737,  -737,  -737,   582,  -737,  -737,  1667,   584,
    -737,  -737,  1667,  -737,  1667,  -737,  -737,  -737,  -737,  -737,
    -737,  -737,  -737,   416,   417,   564,   565,   324,   325,   326,
    -737,  -737,  1667,  1667,  -737,  -737,  1667,   570,  1667,  1667,
    -737,  -737,  -737,  -737,   344,   599,  1667,  -737,  1667,   579,
     583,  -737,  -737,  -737,  -737,  -737,  -737,  -737,  -737,  -737,
    -737,   594,  -737,  -737,  -737,   344,  -737,  -737,  -737,  -737,
    1667,  -737,  -737
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     441,     0,   429,     1,   428,     0,     0,     0,   412,     0,
       0,   379,     0,     0,   403,     0,     0,     0,   255,     0,
     364,   368,   365,     0,     0,     0,     0,     0,     0,   404,
     362,     0,     0,     0,   357,   402,     0,     0,     0,   409,
     411,   360,   363,   370,   367,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     425,   433,   430,   437,   439,   442,   355,   356,     0,     0,
     156,   157,   339,     0,     0,     0,   170,   171,   341,     0,
       0,    79,    80,     0,     0,     0,     0,     0,   121,   122,
       0,     0,     0,     0,   112,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   123,     0,     0,     0,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,    44,    49,    50,    51,    52,    53,    54,    57,    58,
       0,    63,    67,    65,     0,     2,    12,    15,    17,     0,
      76,    20,   181,   182,   342,     0,     0,     0,     0,     0,
       0,     0,   150,   151,   338,     0,     0,   213,   214,   343,
       0,   216,   217,   218,   222,   223,   344,   245,   246,     0,
       0,     0,   253,   254,   349,     0,   405,     0,   265,   352,
     261,   262,   406,     0,     0,   228,   229,     0,   232,   233,
     346,     0,   236,   237,   347,     0,   239,   243,   244,   348,
       0,   397,   400,   401,   385,     0,     0,   427,   358,     0,
     226,   227,   345,     0,   268,   269,   350,   263,   264,   407,
     410,   372,     0,     0,   371,   374,   375,   369,     0,   287,
     288,     0,   408,     0,     0,   353,   270,   351,   303,   309,
     417,   389,   380,   390,   319,   325,   383,   384,   329,   354,
     337,   336,   418,   398,   435,   399,     0,   423,   391,   388,
       0,     0,   429,   431,   429,   429,     0,     0,     0,   167,
     164,     0,     0,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    24,    25,    27,
      29,    30,    26,    31,   101,    23,     0,   115,   116,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117,   120,   118,   119,    55,    42,    45,    46,
      47,    48,    43,    56,    64,   108,     0,   172,   178,   173,
     174,   179,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   175,   176,   177,
       0,     0,   162,   163,   340,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,     0,     0,   203,   204,
       0,     0,     0,     0,   200,   199,   125,     0,     0,     0,
     188,   189,     0,     0,     0,     0,   185,   184,     0,   220,
     215,     0,   250,   247,     0,     0,   280,   284,   282,     0,
       0,   366,     0,     0,   235,   234,   241,   238,     0,   359,
       0,     0,     0,   225,   224,     0,     0,   373,     0,     0,
       0,     0,   301,   293,   295,   300,   297,   302,     0,   299,
     307,     0,     0,     0,   393,     0,   395,     0,   320,     0,
       0,   334,   332,   429,   419,     0,     0,     0,     0,     0,
     425,   434,   429,   438,   440,     0,     0,   154,   152,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    14,     5,     7,     8,     9,
      10,     6,     3,     4,    16,    18,    19,    21,     0,     0,
       0,     0,   132,     0,   144,     0,   136,     0,   140,     0,
     128,   201,     0,   208,   207,   212,   211,   206,   210,   205,
     209,     0,   186,     0,   193,   192,   197,   196,   191,   195,
     190,   194,     0,   221,   219,   251,   248,   252,   249,     0,
       0,     0,     0,   256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   361,     0,     0,     0,     0,   289,   294,
     296,   298,     0,     0,     0,   310,     0,     0,     0,   322,
       0,   321,   326,     0,     0,   436,   420,     0,   327,     0,
     311,     0,     0,   432,   155,   153,   169,   166,   168,   165,
      75,    68,    70,    74,    72,     0,     0,     0,    78,    77,
      82,    81,    84,    83,     0,     0,     0,     0,     0,    91,
      92,    93,   100,     0,    94,    95,    96,    97,    98,     0,
       0,   110,   111,   102,     0,     0,   106,     0,     0,     0,
       0,     0,   160,   158,   129,   142,   134,   137,   131,   143,
     135,   139,     0,     0,   198,     0,   183,     0,   271,   281,
     274,   285,   277,   283,   257,     0,     0,     0,     0,     0,
     386,     0,     0,     0,     0,   376,   377,     0,   286,     0,
       0,     0,   291,     0,     0,     0,   313,     0,     0,   323,
       0,   335,   333,     0,     0,   392,     0,     0,     0,    69,
      71,    73,   124,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,   109,    60,   161,   159,     0,     0,   145,
     130,   141,   133,   138,     0,     0,     0,     0,     0,     0,
     259,   258,     0,   231,   242,   240,     0,     0,     0,     0,
     378,     0,     0,     0,     0,     0,   304,     0,   394,     0,
     314,     0,   382,   396,   324,     0,   328,   312,     0,     0,
      85,    86,     0,    87,     0,    89,    99,   105,   104,    22,
      62,   147,   149,     0,     0,     0,     0,     0,     0,     0,
     260,   230,     0,     0,   267,   266,     0,     0,     0,     0,
     308,   292,   306,   316,     0,   315,     0,   422,     0,     0,
       0,   146,   148,   202,   187,   273,   276,   279,   413,   414,
     387,     0,   415,   290,   317,     0,   424,   426,    88,    90,
       0,   318,   416
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -737,   -10,    -7,   -65,   249,  -285,    68,  -737,  -737,  -737,
    -345,  -737,  -737,  -737,   444,  -737,  -737,  -737,  -737,  -737,
    -737,  -737,  -737,  -737,  -737,  -737,  -737,   460,  -737,  -737,
    -737,  -737,  -737,  -737,  -737,  -737,  -737,  -737,  -737,  -737,
    -737,  -737,  -737,  -737,  -737,  -737,  -737,  -737,  -737,  -737,
    -737,  -737,  -737,  -737,  -737,  -737,  -737,  -737,  -737,  -737,
    -191,  -737,  -189,  -737,  -188,  -737,  -737,  -737,  -737,  -737,
    -737,  -737,  -652,  -270,  -737,  -737,  -737,  -737,   167,  -519,
    -736,   -54,  -516,  -321,  -737,  -737,  -737,  -737,  -737,  -737,
    -737,  -737,  -737,  -737,  -737,  -737,  -262,  -737,  -737,  -737,
    -266,  -737,  -737,  -737
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   620,   145,   146,   147,   148,   149,   303,   304,   150,
     151,   346,   521,   522,   397,   162,   163,   164,    70,    71,
      72,   372,   373,   374,    76,    77,    78,   352,   152,   153,
     154,   167,   168,   169,   174,   175,   176,   220,   221,   222,
     198,   199,   200,   202,   203,   204,   207,   208,   209,   182,
     183,   184,   188,   192,   229,   189,   224,   225,   226,   247,
     689,   756,   691,   757,   693,   758,   186,   579,   581,   580,
     242,   245,   713,   450,   249,   451,   452,   602,   250,   621,
     717,   256,   619,   259,   614,   613,   262,    62,   193,   455,
     467,   606,   608,   270,   466,   271,    63,   472,    64,   272,
      65,   463,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     144,   469,   257,   165,   669,   265,   668,   185,   473,   474,
     471,    68,   266,   197,   306,   370,   210,   211,   264,   267,
     265,   537,   376,   217,   218,   378,    87,   266,   380,   230,
     382,   344,     3,  -421,   267,   237,   416,   241,   233,   332,
     246,   664,   156,   823,   518,   -59,   213,   258,  -421,   263,
     157,  -305,    87,   347,   348,   190,   442,   191,   276,   774,
     457,   771,   777,   279,   281,   283,   792,   158,   330,   442,
     292,   205,    73,   458,   170,   419,   794,    74,   341,   535,
     536,   166,   331,   311,   342,   417,   171,   172,   844,   772,
     715,    66,   718,   674,   793,   159,   160,   420,   723,   779,
     214,   459,    67,   728,   795,   443,   444,   445,   155,   851,
     675,   236,   780,   333,   234,   334,   446,    75,   443,   444,
     445,   347,   367,   821,   349,   350,   351,   418,   682,   446,
     705,   187,   307,   335,   206,   750,   277,   173,   676,   677,
     781,   280,   282,   284,   488,   489,   268,   683,   742,   227,
     308,   228,   751,   557,   447,   490,   235,   364,   345,   365,
     409,   268,   558,   366,   559,   201,   448,   447,   296,   412,
     212,    69,  -331,   560,   449,   371,  -331,   219,  -331,   448,
     752,   753,   377,   421,   422,   379,   269,   449,   381,   611,
     383,   424,   349,   350,   368,   426,   461,   615,   462,   254,
     255,   269,   161,   568,   215,   431,   432,   787,   786,   433,
     623,   216,   569,   177,   178,   179,   180,   297,   298,   299,
     599,   600,   436,   437,   375,   181,   300,   301,   302,   260,
     261,   601,   223,   440,   231,   353,   354,   570,   410,   355,
     238,   356,   357,   358,   359,   360,   571,   413,   337,   385,
     386,   338,   339,   553,   554,   232,   464,   387,   340,  -330,
     243,   388,   389,  -330,   273,  -330,   555,   556,   477,   425,
     390,   564,   565,   427,   566,   567,   353,   354,   244,   391,
     248,   392,   393,   492,   494,   496,   251,   434,   524,   525,
     394,   395,   721,   722,   252,   253,   274,   275,   278,   499,
     500,   396,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   740,
     285,   293,   294,   295,   361,   305,   385,   398,   309,   310,
     312,   313,   362,   314,   399,   315,    87,   316,   400,   401,
     317,   318,   319,   320,   321,   322,   478,   402,   526,   527,
     528,   529,   530,   531,   532,   533,   403,   323,   404,   405,
     538,   493,   495,   497,   324,   325,   326,   406,   407,   327,
     328,   329,   336,   343,   363,   366,   551,   384,   396,   411,
     414,   423,   429,   428,   415,   430,   435,   439,   438,   441,
     453,   460,   454,   465,  -381,   456,   468,   475,   476,   479,
     480,   573,   483,   609,   575,   577,   612,   484,   485,   541,
     498,   481,   482,   585,   486,   520,   487,   540,   586,   519,
     588,   491,   -61,   523,   543,   591,   545,   547,   595,   549,
     552,   598,   561,   572,   563,   583,   582,   584,   539,   589,
     590,   594,   597,   596,   542,   603,   544,   593,   546,   604,
     548,   607,   550,   610,   617,   616,   622,   618,   630,   624,
     625,   635,   636,   631,   632,   633,   562,   634,   645,   626,
     646,   628,   637,   638,   639,   640,   641,   642,   643,   574,
     647,   648,   576,   578,   649,   650,   651,   652,   644,   653,
     654,   655,   656,   657,   658,   659,   587,   660,   665,   661,
     662,   663,   666,   592,   667,   670,   671,   695,   688,   690,
     692,   825,   618,   694,   697,   703,   704,   698,   700,   707,
     699,   710,   720,   711,   724,   714,   708,   726,   716,   712,
     672,   727,   729,   730,   731,   725,   732,   741,   743,   744,
     745,   746,   684,   749,   754,   747,   755,   748,   627,  -272,
     629,   685,  -275,  -278,   759,   762,   719,   766,   767,   775,
     776,   778,   782,   783,   785,   789,   788,   790,   791,   796,
     797,   798,   803,   799,   696,   800,   801,   802,   804,   701,
     702,   807,   808,   809,   812,   813,   814,   709,   824,   815,
     818,   819,   820,   822,   816,   826,   618,   828,   618,   833,
     834,   831,   832,   258,   258,   841,   845,   850,   673,   369,
     408,   678,   534,   679,   848,   680,   835,   681,   849,   836,
     605,   837,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   686,     0,     0,     0,   733,   734,   735,   736,     0,
     687,     0,     0,   737,     0,     0,     0,     0,     0,   738,
     739,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   706,     0,     0,     0,   784,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   760,     0,   763,   764,     0,
       0,     0,     0,   768,     0,     0,     0,   770,     0,     0,
     773,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   618,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   805,     0,     0,     0,     0,   810,
       0,     0,   811,     0,     0,     0,     0,     0,     0,     0,
       0,   817,     0,   761,     0,     0,     0,   765,     0,     0,
       0,     0,   769,     0,     0,     0,     0,     0,   827,     0,
       0,     0,   829,     0,   830,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   838,   839,     0,     0,   840,     4,   842,   843,
       0,     0,     0,     0,     5,     6,   846,     0,   847,     0,
       0,     0,     0,   806,     0,     0,     7,     8,     0,     9,
       0,    10,    11,     0,    12,    13,     0,     0,     0,     0,
     852,     0,    14,     0,    15,    16,    17,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,    28,    29,     0,    30,     0,     0,    31,    32,
      33,     0,    34,    35,    36,    37,    38,    39,    40,     0,
      41,     0,     0,     0,    42,    43,    44,    45,    46,     0,
      47,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,    51,     4,    52,    53,
      54,     0,     0,    55,     5,     6,     0,    56,     0,    57,
       0,     0,     0,    58,    59,     0,     7,     8,     0,     9,
       0,    10,    11,     0,    12,    13,     0,     0,     0,     0,
       0,     0,    14,     0,    15,    16,    17,     0,    60,     0,
      61,    18,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,    28,    29,     0,    30,     0,     0,    31,    32,
      33,     0,    34,    35,    36,    37,    38,    39,    40,     0,
      41,     0,     0,     0,    42,    43,    44,    45,    46,     0,
      47,    48,     0,     0,     0,     0,    79,     0,     0,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,   286,    50,     0,     0,    51,     0,    52,    53,
      54,    80,     0,    55,     0,     0,     0,    56,     0,    57,
       0,     0,     0,    58,    59,     0,     0,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,    85,   470,     0,
      86,   287,   288,   289,     0,     0,     0,     0,     0,     0,
      88,    89,   290,    90,     0,     0,     0,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,     0,     0,   108,
     109,   110,   291,   111,   112,   113,     0,   114,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,     0,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    79,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,     0,   194,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,   195,   196,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,    82,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,     0,    85,     0,     0,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,     0,    90,     0,
       0,     0,     0,     0,     0,     0,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
      94,    95,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,     0,     0,   108,   109,   110,     0,   111,   112,
     113,     0,   114,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    79,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,     0,     0,     0,     0,     0,   239,
     240,     0,     0,     0,     0,     0,     0,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,    85,     0,     0,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,     0,    90,     0,     0,     0,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,     0,     0,   108,
     109,   110,     0,   111,   112,   113,     0,   114,   115,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
       0,   116,     0,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    80,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,     0,     0,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,    85,     0,     0,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      88,    89,     0,    90,     0,     0,     0,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,     0,     0,   108,
     109,   110,     0,   111,   112,   113,     0,   114,   115,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
       0,   116,     0,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    80,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,     0,     0,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,    85,     0,     0,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,     0,    90,     0,     0,     0,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,     0,     0,   108,
     109,   110,     0,   111,   112,   113,     0,   114,   115,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
       0,   116,     0,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    80,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,     0,     0,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,    85,     0,     0,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,     0,    90,     0,     0,     0,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,     0,     0,   108,
     109,   110,     0,   111,   112,   113,     0,   114,   115,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
       0,   116,     0,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,    80,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,     0,     0,     0,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,    85,     0,     0,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,     0,    90,     0,     0,     0,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,     0,     0,     0,   108,
     109,   110,     0,   111,   112,   113,     0,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,     0,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143
};

static const yytype_int16 yycheck[] =
{
      10,   271,    56,    13,   523,     6,   522,    17,   274,   275,
     272,    24,    13,    23,    20,    24,    26,    27,     4,    20,
       6,   366,    24,    33,    34,    24,    82,    13,    24,    39,
      24,    20,     0,    34,    20,    45,    53,    47,    68,    86,
      50,     7,    24,   779,   329,    34,    90,    57,    34,    59,
      32,    20,    82,    79,    80,   184,    25,   186,    68,   711,
       7,     7,   714,    73,    74,    75,     7,    49,    20,    25,
      80,    24,    26,    20,    24,    20,     7,    31,   167,   364,
     365,    13,    34,    93,   173,   102,    36,    37,   824,    35,
     606,   184,   608,    32,    35,    77,    78,    42,   617,     7,
     144,    48,   184,   622,    35,    74,    75,    76,    22,   845,
      49,    43,    20,   160,   144,   138,    85,    71,    74,    75,
      76,    79,    80,   775,   150,   151,   152,   144,    29,    85,
     186,   184,   138,   156,    87,    32,    68,    87,    77,    78,
      48,    73,    74,    75,    74,    75,   147,    48,   667,   184,
     156,   186,    49,    45,   123,    85,   186,    19,   147,    21,
     170,   147,    54,   129,    45,    24,   135,   123,    25,   179,
      90,   184,     0,    54,   143,   184,     4,    24,     6,   135,
      77,    78,   184,   193,   194,   184,   187,   143,   184,   459,
     184,   201,   150,   151,   152,   205,     5,   463,     7,   184,
     185,   187,   184,    45,    34,   215,   216,   726,   724,   219,
     472,    34,    54,    42,    43,    44,    45,    74,    75,    76,
      74,    75,   232,   233,   156,    54,    83,    84,    85,   157,
     158,    85,    24,   243,   144,     8,     9,    45,   170,    12,
     184,    14,    15,    16,    17,    18,    54,   179,   163,    24,
      25,   166,   167,    56,    57,    68,   266,    32,   173,     0,
      34,    36,    37,     4,     6,     6,    56,    57,   278,   201,
      45,    56,    57,   205,    56,    57,     8,     9,   184,    54,
     184,    56,    57,   293,   294,   295,   184,   219,   353,   354,
      65,    66,   613,   614,   184,   184,     4,     4,    24,   309,
     310,    76,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   664,
     186,    34,    34,    34,    97,   186,    24,    25,    34,    34,
      34,    34,   105,    34,    32,    34,    82,    34,    36,    37,
      34,    34,    34,    34,    34,    34,   278,    45,   355,   356,
     357,   358,   359,   360,   361,   362,    54,    34,    56,    57,
     370,   293,   294,   295,    34,    34,    34,    65,    66,    34,
      34,    34,   166,   166,   130,   129,   386,    24,    76,    29,
      46,     7,    69,    29,    46,   147,    34,   152,    13,     7,
       7,     7,   147,    13,   147,   147,    34,    29,    29,    72,
      72,   411,    35,   457,   414,   415,   460,    35,    35,    48,
      34,    72,    72,   423,    35,   184,    35,    24,   428,    34,
     430,    35,    34,    34,    24,   435,    24,    24,   438,    24,
      33,   441,    34,    34,    33,   184,    42,     7,   370,     7,
       7,     7,     7,   102,   376,    34,   378,    69,   380,    20,
     382,   147,   384,     7,    34,   465,    34,   467,   186,   184,
     184,    35,    35,   186,   186,   186,   398,   186,     7,   479,
       7,   481,    35,    35,    35,    35,    35,    35,    35,   411,
       7,     7,   414,   415,    35,    35,    35,    35,   498,     7,
      35,    35,    35,    35,    35,     7,   428,     7,   184,    35,
      35,    35,    35,   435,    34,    29,    29,    13,   184,   184,
     184,   781,   522,   184,     7,     7,     7,    42,   148,    72,
      42,     7,     7,    34,     7,    34,   184,     7,   184,   186,
     540,    35,   186,   186,   186,   148,    35,    35,   148,    35,
     184,   184,   552,   185,     7,    29,     7,    29,   480,     7,
     482,   561,     7,     7,    13,     7,   610,    35,    35,     7,
      35,   148,   148,   148,    35,    35,    13,    35,    35,    35,
      35,    35,    29,    35,   584,    35,   185,   185,    29,   589,
     590,     7,     7,     7,    13,    13,    35,   597,     7,    35,
      13,    72,    35,    35,   115,    13,   606,    13,   608,    35,
      35,   185,   185,   613,   614,    35,     7,    13,   540,   149,
     166,   543,   363,   545,    35,   547,   807,   549,    35,   808,
     453,   809,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   563,    -1,    -1,    -1,   645,   646,   647,   648,    -1,
     572,    -1,    -1,   653,    -1,    -1,    -1,    -1,    -1,   659,
     660,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   594,    -1,    -1,    -1,   720,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   695,    -1,   697,   698,    -1,
      -1,    -1,    -1,   703,    -1,    -1,    -1,   707,    -1,    -1,
     710,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   724,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   754,    -1,    -1,    -1,    -1,   759,
      -1,    -1,   762,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   771,    -1,   695,    -1,    -1,    -1,   699,    -1,    -1,
      -1,    -1,   704,    -1,    -1,    -1,    -1,    -1,   788,    -1,
      -1,    -1,   792,    -1,   794,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   812,   813,    -1,    -1,   816,     3,   818,   819,
      -1,    -1,    -1,    -1,    10,    11,   826,    -1,   828,    -1,
      -1,    -1,    -1,   755,    -1,    -1,    22,    23,    -1,    25,
      -1,    27,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,
     850,    -1,    38,    -1,    40,    41,    42,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    88,    89,    -1,    91,    -1,    -1,    94,    95,
      96,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,    -1,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,    -1,    -1,   142,     3,   144,   145,
     146,    -1,    -1,   149,    10,    11,    -1,   153,    -1,   155,
      -1,    -1,    -1,   159,   160,    -1,    22,    23,    -1,    25,
      -1,    27,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    40,    41,    42,    -1,   184,    -1,
     186,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    88,    89,    -1,    91,    -1,    -1,    94,    95,
      96,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,    -1,
     116,   117,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   139,    -1,    -1,   142,    -1,   144,   145,
     146,    34,    -1,   149,    -1,    -1,    -1,   153,    -1,   155,
      -1,    -1,    -1,   159,   160,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,   184,    -1,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,   137,   138,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,   156,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     9,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,    -1,
      -1,    -1,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     9,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,   154,    -1,   156,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    34,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,   154,    -1,   156,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    34,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,   154,    -1,   156,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    34,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,   154,    -1,   156,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    34,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,   156,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   290,   291,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    86,    88,    89,
      91,    94,    95,    96,    98,    99,   100,   101,   102,   103,
     104,   106,   110,   111,   112,   113,   114,   116,   117,   131,
     139,   142,   144,   145,   146,   149,   153,   155,   159,   160,
     184,   186,   275,   284,   286,   288,   184,   184,    24,   184,
     206,   207,   208,    26,    31,    71,   212,   213,   214,     9,
      34,    50,    51,    52,    67,    70,    73,    82,    83,    84,
      86,    94,    95,   107,   108,   109,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   132,   133,
     134,   136,   137,   138,   140,   141,   154,   156,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   189,   190,   191,   192,   193,   194,
     197,   198,   216,   217,   218,    22,    24,    32,    49,    77,
      78,   184,   203,   204,   205,   189,   194,   219,   220,   221,
      24,    36,    37,    87,   222,   223,   224,    42,    43,    44,
      45,    54,   237,   238,   239,   189,   254,   184,   240,   243,
     184,   186,   241,   276,    24,    36,    37,   189,   228,   229,
     230,    24,   231,   232,   233,    24,    87,   234,   235,   236,
     189,   189,    90,    90,   144,    34,    34,   189,   189,    24,
     225,   226,   227,    24,   244,   245,   246,   184,   186,   242,
     189,   144,    68,    68,   144,   186,   194,   189,   184,    42,
      43,   189,   258,    34,   184,   259,   189,   247,   184,   262,
     266,   184,   184,   184,   184,   185,   269,   269,   189,   271,
     157,   158,   274,   189,     4,     6,    13,    20,   147,   187,
     281,   283,   287,     6,     4,     4,   189,   194,    24,   189,
     194,   189,   194,   189,   194,   186,    25,    74,    75,    76,
      85,   135,   189,    34,    34,    34,    25,    74,    75,    76,
      83,    84,    85,   195,   196,   186,    20,   138,   156,    34,
      34,   189,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      20,    34,    86,   160,   138,   156,   166,   163,   166,   167,
     173,   167,   173,   166,    20,   147,   199,    79,    80,   150,
     151,   152,   215,     8,     9,    12,    14,    15,    16,    17,
      18,    97,   105,   130,    19,    21,   129,    80,   152,   215,
      24,   184,   209,   210,   211,   194,    24,   184,    24,   184,
      24,   184,    24,   184,    24,    24,    25,    32,    36,    37,
      45,    54,    56,    57,    65,    66,    76,   202,    25,    32,
      36,    37,    45,    54,    56,    57,    65,    66,   202,   189,
     194,    29,   189,   194,    46,    46,    53,   102,   144,    20,
      42,   189,   189,     7,   189,   194,   189,   194,    29,    69,
     147,   189,   189,   189,   194,    34,   189,   189,    13,   152,
     189,     7,    25,    74,    75,    76,    85,   123,   135,   143,
     261,   263,   264,     7,   147,   277,   147,     7,    20,    48,
       7,     5,     7,   289,   189,    13,   282,   278,    34,   261,
     184,   284,   285,   288,   288,    29,    29,   189,   194,    72,
      72,    72,    72,    35,    35,    35,    35,    35,    74,    75,
      85,    35,   189,   194,   189,   194,   189,   194,    34,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   193,    34,
     184,   200,   201,    34,   191,   191,   190,   190,   190,   190,
     190,   190,   190,   190,   192,   193,   193,   198,   189,   194,
      24,    48,   194,    24,   194,    24,   194,    24,   194,    24,
     194,   189,    33,    56,    57,    56,    57,    45,    54,    45,
      54,    34,   194,    33,    56,    57,    56,    57,    45,    54,
      45,    54,    34,   189,   194,   189,   194,   189,   194,   255,
     257,   256,    42,   184,     7,   189,   189,   194,   189,     7,
       7,   189,   194,    69,     7,   189,   102,     7,   189,    74,
      75,    85,   265,    34,    20,   266,   279,   147,   280,   269,
       7,   261,   269,   273,   272,   288,   189,    34,   189,   270,
     189,   267,    34,   284,   184,   184,   189,   194,   189,   194,
     186,   186,   186,   186,   186,    35,    35,    35,    35,    35,
      35,    35,    35,    35,   189,     7,     7,     7,     7,    35,
      35,    35,    35,     7,    35,    35,    35,    35,    35,     7,
       7,    35,    35,    35,     7,   184,    35,    34,   270,   267,
      29,    29,   189,   194,    32,    49,    77,    78,   194,   194,
     194,   194,    29,    48,   189,   189,   194,   194,   184,   248,
     184,   250,   184,   252,   184,    13,   189,     7,    42,    42,
     148,   189,   189,     7,     7,   186,   194,    72,   184,   189,
       7,    34,   186,   260,    34,   270,   184,   268,   270,   269,
       7,   271,   271,   267,     7,   148,     7,    35,   267,   186,
     186,   186,    35,   189,   189,   189,   189,   189,   189,   189,
     198,    35,   267,   148,    35,   184,   184,    29,    29,   185,
      32,    49,    77,    78,     7,     7,   249,   251,   253,    13,
     189,   194,     7,   189,   189,   194,    35,    35,   189,   194,
     189,     7,    35,   189,   260,     7,    35,   260,   148,     7,
      20,    48,   148,   148,   269,    35,   270,   267,    13,    35,
      35,    35,     7,    35,     7,    35,    35,    35,    35,    35,
      35,   185,   185,    29,    29,   189,   194,     7,     7,     7,
     189,   189,    13,    13,    35,    35,   115,   189,    13,    72,
      35,   260,    35,   268,     7,   261,    13,   189,    13,   189,
     189,   185,   185,    35,    35,   248,   250,   252,   189,   189,
     189,    35,   189,   189,   268,     7,   189,   189,    35,    35,
      13,   268,   189
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   188,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   190,   190,   190,   191,   191,   192,   192,   192,
     193,   193,   193,   194,   195,   195,   195,   195,   195,   195,
     195,   196,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   199,
     198,   200,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   201,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   202,   202,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   204,   204,   204,   204,   204,
     205,   205,   206,   206,   207,   207,   208,   208,   209,   209,
     210,   210,   211,   211,   212,   212,   212,   213,   213,   213,
     214,   214,   215,   215,   215,   216,   216,   216,   217,   217,
     217,   218,   218,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   221,   221,   222,   222,   222,   222,   222,
     223,   223,   224,   224,   225,   226,   227,   227,   228,   228,
     229,   229,   230,   230,   231,   232,   233,   233,   234,   234,
     234,   235,   235,   236,   236,   237,   237,   237,   237,   237,
     238,   238,   238,   239,   239,   240,   240,   240,   240,   240,
     240,   241,   241,   242,   242,   243,   244,   245,   246,   246,
     247,   248,   249,   248,   250,   251,   250,   252,   253,   252,
     255,   254,   256,   254,   257,   254,   258,   258,   258,   259,
     259,   260,   260,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   263,   262,   264,   262,   265,   262,   266,
     266,   267,   267,   268,   268,   268,   268,   268,   268,   269,
     269,   269,   269,   269,   269,   269,   269,   270,   270,   271,
     271,   271,   272,   271,   273,   271,   274,   274,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   276,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   277,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   278,   275,   279,   275,   280,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   281,   275,   282,   275,   283,   275,   275,   275,   275,
     284,   285,   284,   287,   286,   289,   288,   288,   288,   288,
     288,   291,   290
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
       2,     1,     1,     1,     5,     1,     1,     2,     3,     4,
       5,     4,     3,     5,     4,     4,     3,     4,     5,     4,
       3,     5,     4,     4,     3,     5,     7,     6,     7,     6,
       1,     1,     3,     4,     3,     4,     1,     1,     3,     4,
       3,     4,     1,     1,     2,     4,     4,     2,     4,     4,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     1,     1,     4,     2,     2,     3,     7,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     2,
       2,     3,     7,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     2,     1,     1,     1,     3,
       2,     3,     1,     1,     2,     2,     1,     1,     1,     1,
       6,     5,     1,     1,     2,     2,     1,     1,     2,     1,
       5,     2,     5,     1,     1,     1,     1,     2,     3,     3,
       2,     3,     3,     1,     1,     0,     3,     4,     5,     5,
       6,     1,     1,     1,     1,     1,     6,     6,     1,     1,
       1,     1,     0,     4,     1,     0,     4,     1,     0,     4,
       0,     4,     0,     4,     0,     4,     4,     1,     1,     3,
       7,     1,     3,     1,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     0,     5,     0,     6,     0,     6,     1,
       3,     1,     3,     1,     2,     3,     3,     4,     5,     1,
       2,     3,     3,     4,     5,     1,     3,     1,     3,     1,
       2,     2,     0,     4,     0,     4,     1,     1,     2,     2,
       3,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     2,     3,
       1,     4,     1,     1,     1,     0,     3,     1,     1,     2,
       1,     2,     2,     3,     2,     2,     5,     5,     6,     1,
       2,     0,     6,     2,     2,     2,     5,     8,     2,     2,
       2,     0,     5,     0,     6,     0,     6,     2,     2,     2,
       2,     2,     1,     1,     1,     2,     2,     2,     2,     1,
       2,     1,     1,     8,     8,     8,    10,     2,     2,     3,
       4,     0,     7,     0,     8,     0,     8,     2,     1,     0,
       1,     0,     4,     0,     3,     0,     4,     1,     3,     1,
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
#line 74 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2645 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 78 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2654 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 82 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2662 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 85 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2670 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 88 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2678 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 91 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2686 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 94 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2694 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 97 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2702 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 100 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2710 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 107 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2718 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 110 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2727 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 123 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2736 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 127 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2745 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 135 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2754 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 139 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 2763 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 146 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2771 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 151 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2779 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 154 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2787 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 157 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2795 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 160 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2803 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 163 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2811 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 166 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2819 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 169 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2827 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 174 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2835 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 179 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2844 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 183 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2853 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 187 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2862 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 191 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2871 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 195 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2880 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 199 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2889 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 203 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2898 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 207 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2907 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 211 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2916 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 215 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2925 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 219 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2934 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 223 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2943 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 227 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2952 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 231 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2961 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 235 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2970 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 239 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2979 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 243 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2988 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 247 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2997 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 251 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3006 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 255 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3015 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 259 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3024 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 263 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3033 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 267 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3042 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 271 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3051 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 275 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3060 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 279 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3069 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 283 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3078 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 289 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3087 "src-generated/ugbc.tab.c"
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
#line 3099 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 300 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3108 "src-generated/ugbc.tab.c"
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
#line 3120 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 311 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3128 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 314 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3136 "src-generated/ugbc.tab.c"
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
#line 3150 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 326 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3159 "src-generated/ugbc.tab.c"
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
#line 3171 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 337 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3180 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 341 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3189 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 345 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3198 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 349 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3207 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 353 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3216 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 357 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3225 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 361 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3234 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 365 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3243 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 369 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3251 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 372 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3259 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 375 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3267 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 378 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3275 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 381 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3283 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 384 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3291 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 387 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3299 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 390 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3307 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 393 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3315 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 396 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3323 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 399 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3331 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 402 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3339 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 405 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3347 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 408 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3355 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 411 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3363 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 414 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3371 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 417 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3379 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 420 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3387 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 423 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3395 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 426 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3403 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 429 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3411 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 432 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3419 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 435 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3427 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 438 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3435 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 441 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3443 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 444 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3451 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 447 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3459 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 450 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3467 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 453 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3475 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 456 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3483 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 459 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3491 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 462 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3499 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 465 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3507 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 467 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3516 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 471 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3524 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 474 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3532 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 477 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3541 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 481 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3550 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 485 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3559 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: PEN COLORS  */
#line 489 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3568 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: PEN DEFAULT  */
#line 493 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3577 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: DEFAULT PEN  */
#line 497 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3586 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: PAPER COLORS  */
#line 501 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3595 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: PAPER DEFAULT  */
#line 505 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3604 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: DEFAULT PAPER  */
#line 509 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3613 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: WIDTH  */
#line 513 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3621 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: HEIGHT  */
#line 516 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3629 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: TIMER  */
#line 519 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3637 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PEN DOLLAR OP expr CP  */
#line 522 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 3645 "src-generated/ugbc.tab.c"
    break;

  case 127: /* bank_definition_simple: AT direct_integer  */
#line 530 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3653 "src-generated/ugbc.tab.c"
    break;

  case 128: /* bank_definition_simple: Identifier AT direct_integer  */
#line 533 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3661 "src-generated/ugbc.tab.c"
    break;

  case 129: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 536 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3669 "src-generated/ugbc.tab.c"
    break;

  case 130: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 539 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3677 "src-generated/ugbc.tab.c"
    break;

  case 131: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 542 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3685 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_simple: DATA AT direct_integer  */
#line 545 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3693 "src-generated/ugbc.tab.c"
    break;

  case 133: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 549 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3701 "src-generated/ugbc.tab.c"
    break;

  case 134: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 552 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3709 "src-generated/ugbc.tab.c"
    break;

  case 135: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 555 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3717 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bank_definition_simple: CODE AT direct_integer  */
#line 558 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3725 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 562 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3733 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 565 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3741 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 568 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3749 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 571 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3757 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 575 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3765 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 578 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3773 "src-generated/ugbc.tab.c"
    break;

  case 143: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 581 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3781 "src-generated/ugbc.tab.c"
    break;

  case 144: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 584 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3789 "src-generated/ugbc.tab.c"
    break;

  case 145: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 590 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3797 "src-generated/ugbc.tab.c"
    break;

  case 146: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 593 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3805 "src-generated/ugbc.tab.c"
    break;

  case 147: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 596 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3813 "src-generated/ugbc.tab.c"
    break;

  case 148: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 599 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3821 "src-generated/ugbc.tab.c"
    break;

  case 149: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 602 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3829 "src-generated/ugbc.tab.c"
    break;

  case 152: /* raster_definition_simple: Identifier AT direct_integer  */
#line 611 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3837 "src-generated/ugbc.tab.c"
    break;

  case 153: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 614 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3845 "src-generated/ugbc.tab.c"
    break;

  case 154: /* raster_definition_expression: Identifier AT expr  */
#line 619 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3853 "src-generated/ugbc.tab.c"
    break;

  case 155: /* raster_definition_expression: AT expr WITH Identifier  */
#line 622 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3861 "src-generated/ugbc.tab.c"
    break;

  case 158: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 631 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3869 "src-generated/ugbc.tab.c"
    break;

  case 159: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 634 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3877 "src-generated/ugbc.tab.c"
    break;

  case 160: /* next_raster_definition_expression: Identifier AT expr  */
#line 639 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3885 "src-generated/ugbc.tab.c"
    break;

  case 161: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 642 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3893 "src-generated/ugbc.tab.c"
    break;

  case 164: /* color_definition_simple: BORDER direct_integer  */
#line 651 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3901 "src-generated/ugbc.tab.c"
    break;

  case 165: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 654 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3909 "src-generated/ugbc.tab.c"
    break;

  case 166: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 657 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3917 "src-generated/ugbc.tab.c"
    break;

  case 167: /* color_definition_expression: BORDER expr  */
#line 662 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3925 "src-generated/ugbc.tab.c"
    break;

  case 168: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 665 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3933 "src-generated/ugbc.tab.c"
    break;

  case 169: /* color_definition_expression: SPRITE expr TO expr  */
#line 668 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3941 "src-generated/ugbc.tab.c"
    break;

  case 175: /* wait_definition_simple: direct_integer CYCLES  */
#line 682 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3949 "src-generated/ugbc.tab.c"
    break;

  case 176: /* wait_definition_simple: direct_integer TICKS  */
#line 685 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3957 "src-generated/ugbc.tab.c"
    break;

  case 177: /* wait_definition_simple: direct_integer milliseconds  */
#line 688 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3965 "src-generated/ugbc.tab.c"
    break;

  case 178: /* wait_definition_expression: expr CYCLES  */
#line 693 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3973 "src-generated/ugbc.tab.c"
    break;

  case 179: /* wait_definition_expression: expr TICKS  */
#line 696 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3981 "src-generated/ugbc.tab.c"
    break;

  case 180: /* wait_definition_expression: expr milliseconds  */
#line 699 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3989 "src-generated/ugbc.tab.c"
    break;

  case 183: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 709 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3997 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 712 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4005 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 715 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4013 "src-generated/ugbc.tab.c"
    break;

  case 186: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 718 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4021 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 721 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4029 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_simple: direct_integer ENABLE  */
#line 724 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4037 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_simple: direct_integer DISABLE  */
#line 727 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4045 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 730 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4053 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 733 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4061 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 736 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4069 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 739 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4077 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 742 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4085 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 745 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4093 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 748 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4101 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 751 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4109 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_expression: expr DATA FROM expr  */
#line 756 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4117 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_expression: expr MULTICOLOR  */
#line 759 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4125 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_expression: expr MONOCOLOR  */
#line 762 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4133 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_expression: expr COLOR expr  */
#line 765 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4141 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 768 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4149 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_expression: expr ENABLE  */
#line 771 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4157 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_expression: expr DISABLE  */
#line 774 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4165 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 777 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4173 "src-generated/ugbc.tab.c"
    break;

  case 206: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 780 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4181 "src-generated/ugbc.tab.c"
    break;

  case 207: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 783 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4189 "src-generated/ugbc.tab.c"
    break;

  case 208: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 786 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4197 "src-generated/ugbc.tab.c"
    break;

  case 209: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 789 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4205 "src-generated/ugbc.tab.c"
    break;

  case 210: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 792 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4213 "src-generated/ugbc.tab.c"
    break;

  case 211: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 795 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4221 "src-generated/ugbc.tab.c"
    break;

  case 212: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 798 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4229 "src-generated/ugbc.tab.c"
    break;

  case 215: /* bitmap_definition_simple: AT direct_integer  */
#line 807 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4237 "src-generated/ugbc.tab.c"
    break;

  case 216: /* bitmap_definition_simple: ENABLE  */
#line 810 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4245 "src-generated/ugbc.tab.c"
    break;

  case 217: /* bitmap_definition_simple: DISABLE  */
#line 813 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4253 "src-generated/ugbc.tab.c"
    break;

  case 218: /* bitmap_definition_simple: CLEAR  */
#line 816 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4261 "src-generated/ugbc.tab.c"
    break;

  case 219: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 819 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4269 "src-generated/ugbc.tab.c"
    break;

  case 220: /* bitmap_definition_expression: AT expr  */
#line 825 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4277 "src-generated/ugbc.tab.c"
    break;

  case 221: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 828 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4285 "src-generated/ugbc.tab.c"
    break;

  case 224: /* textmap_definition_simple: AT direct_integer  */
#line 838 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4293 "src-generated/ugbc.tab.c"
    break;

  case 225: /* textmap_definition_expression: AT expr  */
#line 843 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4301 "src-generated/ugbc.tab.c"
    break;

  case 228: /* text_definition_simple: ENABLE  */
#line 852 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4309 "src-generated/ugbc.tab.c"
    break;

  case 229: /* text_definition_simple: DISABLE  */
#line 855 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4317 "src-generated/ugbc.tab.c"
    break;

  case 230: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 860 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4325 "src-generated/ugbc.tab.c"
    break;

  case 231: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 863 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4333 "src-generated/ugbc.tab.c"
    break;

  case 234: /* tiles_definition_simple: AT direct_integer  */
#line 872 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4341 "src-generated/ugbc.tab.c"
    break;

  case 235: /* tiles_definition_expression: AT expr  */
#line 877 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4349 "src-generated/ugbc.tab.c"
    break;

  case 238: /* colormap_definition_simple: AT direct_integer  */
#line 886 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4357 "src-generated/ugbc.tab.c"
    break;

  case 239: /* colormap_definition_simple: CLEAR  */
#line 889 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4365 "src-generated/ugbc.tab.c"
    break;

  case 240: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 892 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4373 "src-generated/ugbc.tab.c"
    break;

  case 241: /* colormap_definition_expression: AT expr  */
#line 897 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4381 "src-generated/ugbc.tab.c"
    break;

  case 242: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 900 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4389 "src-generated/ugbc.tab.c"
    break;

  case 245: /* screen_definition_simple: ON  */
#line 910 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4397 "src-generated/ugbc.tab.c"
    break;

  case 246: /* screen_definition_simple: OFF  */
#line 913 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4405 "src-generated/ugbc.tab.c"
    break;

  case 247: /* screen_definition_simple: ROWS direct_integer  */
#line 916 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4413 "src-generated/ugbc.tab.c"
    break;

  case 248: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 919 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4421 "src-generated/ugbc.tab.c"
    break;

  case 249: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 922 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4429 "src-generated/ugbc.tab.c"
    break;

  case 250: /* screen_definition_expression: ROWS expr  */
#line 927 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4437 "src-generated/ugbc.tab.c"
    break;

  case 251: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 930 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4445 "src-generated/ugbc.tab.c"
    break;

  case 252: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 933 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4453 "src-generated/ugbc.tab.c"
    break;

  case 256: /* var_definition_simple: Identifier ON Identifier  */
#line 942 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4461 "src-generated/ugbc.tab.c"
    break;

  case 257: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 945 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4469 "src-generated/ugbc.tab.c"
    break;

  case 258: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 948 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4477 "src-generated/ugbc.tab.c"
    break;

  case 259: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 951 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4487 "src-generated/ugbc.tab.c"
    break;

  case 260: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 956 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4497 "src-generated/ugbc.tab.c"
    break;

  case 261: /* goto_definition: Identifier  */
#line 963 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4505 "src-generated/ugbc.tab.c"
    break;

  case 262: /* goto_definition: Integer  */
#line 966 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4513 "src-generated/ugbc.tab.c"
    break;

  case 263: /* gosub_definition: Identifier  */
#line 972 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4521 "src-generated/ugbc.tab.c"
    break;

  case 264: /* gosub_definition: Integer  */
#line 975 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4529 "src-generated/ugbc.tab.c"
    break;

  case 266: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 984 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4537 "src-generated/ugbc.tab.c"
    break;

  case 267: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 990 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4545 "src-generated/ugbc.tab.c"
    break;

  case 270: /* ink_definition: expr  */
#line 999 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4553 "src-generated/ugbc.tab.c"
    break;

  case 271: /* on_goto_definition: Identifier  */
#line 1004 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4562 "src-generated/ugbc.tab.c"
    break;

  case 272: /* $@4: %empty  */
#line 1008 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4570 "src-generated/ugbc.tab.c"
    break;

  case 274: /* on_gosub_definition: Identifier  */
#line 1013 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4579 "src-generated/ugbc.tab.c"
    break;

  case 275: /* $@5: %empty  */
#line 1017 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4587 "src-generated/ugbc.tab.c"
    break;

  case 277: /* on_proc_definition: Identifier  */
#line 1022 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4596 "src-generated/ugbc.tab.c"
    break;

  case 278: /* $@6: %empty  */
#line 1026 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4604 "src-generated/ugbc.tab.c"
    break;

  case 280: /* $@7: %empty  */
#line 1031 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4612 "src-generated/ugbc.tab.c"
    break;

  case 282: /* $@8: %empty  */
#line 1034 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4620 "src-generated/ugbc.tab.c"
    break;

  case 284: /* $@9: %empty  */
#line 1037 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4628 "src-generated/ugbc.tab.c"
    break;

  case 286: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1042 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4636 "src-generated/ugbc.tab.c"
    break;

  case 287: /* every_definition: ON  */
#line 1045 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4644 "src-generated/ugbc.tab.c"
    break;

  case 288: /* every_definition: OFF  */
#line 1048 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4652 "src-generated/ugbc.tab.c"
    break;

  case 289: /* add_definition: Identifier COMMA expr  */
#line 1053 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4660 "src-generated/ugbc.tab.c"
    break;

  case 290: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1056 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4668 "src-generated/ugbc.tab.c"
    break;

  case 291: /* dimensions: Integer  */
#line 1062 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4677 "src-generated/ugbc.tab.c"
    break;

  case 292: /* dimensions: Integer COMMA dimensions  */
#line 1066 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4686 "src-generated/ugbc.tab.c"
    break;

  case 293: /* datatype: BYTE  */
#line 1073 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 4694 "src-generated/ugbc.tab.c"
    break;

  case 294: /* datatype: SIGNED BYTE  */
#line 1076 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 4702 "src-generated/ugbc.tab.c"
    break;

  case 295: /* datatype: WORD  */
#line 1079 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 4710 "src-generated/ugbc.tab.c"
    break;

  case 296: /* datatype: SIGNED WORD  */
#line 1082 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 4718 "src-generated/ugbc.tab.c"
    break;

  case 297: /* datatype: DWORD  */
#line 1085 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 4726 "src-generated/ugbc.tab.c"
    break;

  case 298: /* datatype: SIGNED DWORD  */
#line 1088 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 4734 "src-generated/ugbc.tab.c"
    break;

  case 299: /* datatype: ADDRESS  */
#line 1091 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 4742 "src-generated/ugbc.tab.c"
    break;

  case 300: /* datatype: POSITION  */
#line 1094 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 4750 "src-generated/ugbc.tab.c"
    break;

  case 301: /* datatype: COLOR  */
#line 1097 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 4758 "src-generated/ugbc.tab.c"
    break;

  case 302: /* datatype: STRING  */
#line 1100 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 4766 "src-generated/ugbc.tab.c"
    break;

  case 303: /* $@10: %empty  */
#line 1105 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4775 "src-generated/ugbc.tab.c"
    break;

  case 304: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1108 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 4785 "src-generated/ugbc.tab.c"
    break;

  case 305: /* $@11: %empty  */
#line 1113 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4794 "src-generated/ugbc.tab.c"
    break;

  case 306: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1116 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 4804 "src-generated/ugbc.tab.c"
    break;

  case 307: /* $@12: %empty  */
#line 1121 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4813 "src-generated/ugbc.tab.c"
    break;

  case 308: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1124 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 4823 "src-generated/ugbc.tab.c"
    break;

  case 311: /* indexes: expr  */
#line 1137 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4832 "src-generated/ugbc.tab.c"
    break;

  case 312: /* indexes: expr COMMA indexes  */
#line 1141 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4841 "src-generated/ugbc.tab.c"
    break;

  case 313: /* parameters: Identifier  */
#line 1148 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4851 "src-generated/ugbc.tab.c"
    break;

  case 314: /* parameters: Identifier DOLLAR  */
#line 1153 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4861 "src-generated/ugbc.tab.c"
    break;

  case 315: /* parameters: Identifier AS datatype  */
#line 1158 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4871 "src-generated/ugbc.tab.c"
    break;

  case 316: /* parameters: Identifier COMMA parameters  */
#line 1163 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4881 "src-generated/ugbc.tab.c"
    break;

  case 317: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1168 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4891 "src-generated/ugbc.tab.c"
    break;

  case 318: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1173 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4901 "src-generated/ugbc.tab.c"
    break;

  case 319: /* parameters_expr: Identifier  */
#line 1181 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4911 "src-generated/ugbc.tab.c"
    break;

  case 320: /* parameters_expr: Identifier DOLLAR  */
#line 1186 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4921 "src-generated/ugbc.tab.c"
    break;

  case 321: /* parameters_expr: Identifier AS datatype  */
#line 1191 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4931 "src-generated/ugbc.tab.c"
    break;

  case 322: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1196 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4941 "src-generated/ugbc.tab.c"
    break;

  case 323: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1201 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4951 "src-generated/ugbc.tab.c"
    break;

  case 324: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1206 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4961 "src-generated/ugbc.tab.c"
    break;

  case 325: /* parameters_expr: String  */
#line 1211 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4970 "src-generated/ugbc.tab.c"
    break;

  case 326: /* parameters_expr: String COMMA parameters_expr  */
#line 1215 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4979 "src-generated/ugbc.tab.c"
    break;

  case 327: /* values: expr  */
#line 1222 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4988 "src-generated/ugbc.tab.c"
    break;

  case 328: /* values: expr COMMA values  */
#line 1226 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4997 "src-generated/ugbc.tab.c"
    break;

  case 329: /* print_definition: expr  */
#line 1233 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5005 "src-generated/ugbc.tab.c"
    break;

  case 330: /* print_definition: expr COMMA  */
#line 1236 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5014 "src-generated/ugbc.tab.c"
    break;

  case 331: /* print_definition: expr SEMICOLON  */
#line 1240 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5022 "src-generated/ugbc.tab.c"
    break;

  case 332: /* $@13: %empty  */
#line 1243 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5031 "src-generated/ugbc.tab.c"
    break;

  case 334: /* $@14: %empty  */
#line 1247 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5039 "src-generated/ugbc.tab.c"
    break;

  case 336: /* use_definition: ANSI  */
#line 1253 "src/ugbc.y"
         {
        use_ansi( _environment );
    }
#line 5047 "src-generated/ugbc.tab.c"
    break;

  case 337: /* use_definition: SPECIFIC  */
#line 1256 "src/ugbc.y"
             {
        use_specific( _environment );
  }
#line 5055 "src-generated/ugbc.tab.c"
    break;

  case 355: /* statement: INC Identifier  */
#line 1279 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 5063 "src-generated/ugbc.tab.c"
    break;

  case 356: /* statement: DEC Identifier  */
#line 1282 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 5071 "src-generated/ugbc.tab.c"
    break;

  case 357: /* statement: RANDOMIZE  */
#line 1285 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 5079 "src-generated/ugbc.tab.c"
    break;

  case 358: /* statement: RANDOMIZE expr  */
#line 1288 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 5087 "src-generated/ugbc.tab.c"
    break;

  case 359: /* statement: IF expr THEN  */
#line 1291 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5095 "src-generated/ugbc.tab.c"
    break;

  case 360: /* statement: ELSE  */
#line 1294 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 5103 "src-generated/ugbc.tab.c"
    break;

  case 361: /* statement: ELSE IF expr THEN  */
#line 1297 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5111 "src-generated/ugbc.tab.c"
    break;

  case 362: /* statement: ENDIF  */
#line 1300 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5119 "src-generated/ugbc.tab.c"
    break;

  case 363: /* statement: DO  */
#line 1303 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5127 "src-generated/ugbc.tab.c"
    break;

  case 364: /* statement: LOOP  */
#line 1306 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5135 "src-generated/ugbc.tab.c"
    break;

  case 365: /* $@15: %empty  */
#line 1309 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5143 "src-generated/ugbc.tab.c"
    break;

  case 366: /* statement: WHILE $@15 expr  */
#line 1311 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5151 "src-generated/ugbc.tab.c"
    break;

  case 367: /* statement: WEND  */
#line 1314 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5159 "src-generated/ugbc.tab.c"
    break;

  case 368: /* statement: REPEAT  */
#line 1317 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5167 "src-generated/ugbc.tab.c"
    break;

  case 369: /* statement: UNTIL expr  */
#line 1320 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5175 "src-generated/ugbc.tab.c"
    break;

  case 370: /* statement: EXIT  */
#line 1323 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5183 "src-generated/ugbc.tab.c"
    break;

  case 371: /* statement: EXIT PROC  */
#line 1326 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5191 "src-generated/ugbc.tab.c"
    break;

  case 372: /* statement: POP PROC  */
#line 1329 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5199 "src-generated/ugbc.tab.c"
    break;

  case 373: /* statement: EXIT IF expr  */
#line 1332 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5207 "src-generated/ugbc.tab.c"
    break;

  case 374: /* statement: EXIT Integer  */
#line 1335 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5215 "src-generated/ugbc.tab.c"
    break;

  case 375: /* statement: EXIT direct_integer  */
#line 1338 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5223 "src-generated/ugbc.tab.c"
    break;

  case 376: /* statement: EXIT IF expr COMMA Integer  */
#line 1341 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5231 "src-generated/ugbc.tab.c"
    break;

  case 377: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1344 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5239 "src-generated/ugbc.tab.c"
    break;

  case 378: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1347 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5247 "src-generated/ugbc.tab.c"
    break;

  case 379: /* statement: NEXT  */
#line 1350 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5255 "src-generated/ugbc.tab.c"
    break;

  case 380: /* statement: PROCEDURE Identifier  */
#line 1353 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5264 "src-generated/ugbc.tab.c"
    break;

  case 381: /* $@16: %empty  */
#line 1357 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5272 "src-generated/ugbc.tab.c"
    break;

  case 382: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1359 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5280 "src-generated/ugbc.tab.c"
    break;

  case 383: /* statement: SHARED parameters_expr  */
#line 1362 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5288 "src-generated/ugbc.tab.c"
    break;

  case 384: /* statement: GLOBAL parameters_expr  */
#line 1365 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5296 "src-generated/ugbc.tab.c"
    break;

  case 385: /* statement: END PROC  */
#line 1368 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 5304 "src-generated/ugbc.tab.c"
    break;

  case 386: /* statement: END PROC OSP expr CSP  */
#line 1371 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5312 "src-generated/ugbc.tab.c"
    break;

  case 387: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1374 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5320 "src-generated/ugbc.tab.c"
    break;

  case 388: /* statement: Identifier " "  */
#line 1377 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5329 "src-generated/ugbc.tab.c"
    break;

  case 389: /* statement: PROC Identifier  */
#line 1381 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5338 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: CALL Identifier  */
#line 1385 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5347 "src-generated/ugbc.tab.c"
    break;

  case 391: /* $@17: %empty  */
#line 1389 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5355 "src-generated/ugbc.tab.c"
    break;

  case 392: /* statement: Identifier OSP $@17 values CSP  */
#line 1391 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5363 "src-generated/ugbc.tab.c"
    break;

  case 393: /* $@18: %empty  */
#line 1394 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5371 "src-generated/ugbc.tab.c"
    break;

  case 394: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1396 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5379 "src-generated/ugbc.tab.c"
    break;

  case 395: /* $@19: %empty  */
#line 1399 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5387 "src-generated/ugbc.tab.c"
    break;

  case 396: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1401 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5395 "src-generated/ugbc.tab.c"
    break;

  case 397: /* statement: PEN expr  */
#line 1404 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 5403 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statement: PAPER expr  */
#line 1407 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 5411 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: Identifier COLON  */
#line 1410 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 5419 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: BEG GAMELOOP  */
#line 1413 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 5427 "src-generated/ugbc.tab.c"
    break;

  case 401: /* statement: END GAMELOOP  */
#line 1416 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 5435 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: GRAPHIC  */
#line 1419 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 5443 "src-generated/ugbc.tab.c"
    break;

  case 403: /* statement: HALT  */
#line 1422 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 5451 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: END  */
#line 1425 "src/ugbc.y"
        {
      end( _environment );
  }
#line 5459 "src-generated/ugbc.tab.c"
    break;

  case 409: /* statement: RETURN  */
#line 1432 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 5467 "src-generated/ugbc.tab.c"
    break;

  case 410: /* statement: RETURN expr  */
#line 1435 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 5475 "src-generated/ugbc.tab.c"
    break;

  case 411: /* statement: POP  */
#line 1438 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 5483 "src-generated/ugbc.tab.c"
    break;

  case 412: /* statement: DONE  */
#line 1441 "src/ugbc.y"
          {
      return 0;
  }
#line 5491 "src-generated/ugbc.tab.c"
    break;

  case 413: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1444 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5499 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1447 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5507 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1450 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 5515 "src-generated/ugbc.tab.c"
    break;

  case 416: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1453 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5523 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: Identifier ASSIGN expr  */
#line 1458 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 5537 "src-generated/ugbc.tab.c"
    break;

  case 420: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1467 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 5551 "src-generated/ugbc.tab.c"
    break;

  case 421: /* $@20: %empty  */
#line 1476 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5560 "src-generated/ugbc.tab.c"
    break;

  case 422: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1480 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 5573 "src-generated/ugbc.tab.c"
    break;

  case 423: /* $@21: %empty  */
#line 1488 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5582 "src-generated/ugbc.tab.c"
    break;

  case 424: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1491 "src/ugbc.y"
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
#line 5601 "src-generated/ugbc.tab.c"
    break;

  case 425: /* $@22: %empty  */
#line 1505 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5610 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1508 "src/ugbc.y"
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
#line 5629 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: DEBUG expr  */
#line 1522 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 5637 "src-generated/ugbc.tab.c"
    break;

  case 430: /* statements_no_linenumbers: statement  */
#line 1530 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 5643 "src-generated/ugbc.tab.c"
    break;

  case 431: /* $@23: %empty  */
#line 1531 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 5649 "src-generated/ugbc.tab.c"
    break;

  case 433: /* $@24: %empty  */
#line 1535 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 5657 "src-generated/ugbc.tab.c"
    break;

  case 434: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1537 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 5665 "src-generated/ugbc.tab.c"
    break;

  case 435: /* $@25: %empty  */
#line 1542 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 5673 "src-generated/ugbc.tab.c"
    break;

  case 441: /* $@26: %empty  */
#line 1552 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 5679 "src-generated/ugbc.tab.c"
    break;


#line 5683 "src-generated/ugbc.tab.c"

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

#line 1554 "src/ugbc.y"


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

