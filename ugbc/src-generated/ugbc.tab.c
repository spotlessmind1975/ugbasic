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
  YYSYMBOL_BLACK = 156,                    /* BLACK  */
  YYSYMBOL_WHITE = 157,                    /* WHITE  */
  YYSYMBOL_RED = 158,                      /* RED  */
  YYSYMBOL_CYAN = 159,                     /* CYAN  */
  YYSYMBOL_VIOLET = 160,                   /* VIOLET  */
  YYSYMBOL_GREEN = 161,                    /* GREEN  */
  YYSYMBOL_BLUE = 162,                     /* BLUE  */
  YYSYMBOL_YELLOW = 163,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 164,                   /* ORANGE  */
  YYSYMBOL_BROWN = 165,                    /* BROWN  */
  YYSYMBOL_LIGHT = 166,                    /* LIGHT  */
  YYSYMBOL_DARK = 167,                     /* DARK  */
  YYSYMBOL_GREY = 168,                     /* GREY  */
  YYSYMBOL_GRAY = 169,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 170,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 171,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 172,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 173,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 174,                /* TURQUOISE  */
  YYSYMBOL_TAN = 175,                      /* TAN  */
  YYSYMBOL_PINK = 176,                     /* PINK  */
  YYSYMBOL_PEACH = 177,                    /* PEACH  */
  YYSYMBOL_OLIVE = 178,                    /* OLIVE  */
  YYSYMBOL_Identifier = 179,               /* Identifier  */
  YYSYMBOL_String = 180,                   /* String  */
  YYSYMBOL_Integer = 181,                  /* Integer  */
  YYSYMBOL_182_ = 182,                     /* " "  */
  YYSYMBOL_YYACCEPT = 183,                 /* $accept  */
  YYSYMBOL_expr = 184,                     /* expr  */
  YYSYMBOL_expr_math = 185,                /* expr_math  */
  YYSYMBOL_term = 186,                     /* term  */
  YYSYMBOL_modula = 187,                   /* modula  */
  YYSYMBOL_factor = 188,                   /* factor  */
  YYSYMBOL_direct_integer = 189,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 190, /* random_definition_simple  */
  YYSYMBOL_random_definition = 191,        /* random_definition  */
  YYSYMBOL_color_enumeration = 192,        /* color_enumeration  */
  YYSYMBOL_exponential = 193,              /* exponential  */
  YYSYMBOL_194_1 = 194,                    /* $@1  */
  YYSYMBOL_195_2 = 195,                    /* $@2  */
  YYSYMBOL_196_3 = 196,                    /* $@3  */
  YYSYMBOL_position = 197,                 /* position  */
  YYSYMBOL_bank_definition_simple = 198,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 199, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 200,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 201, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 202, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 203,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 204, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 205, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 206,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 207,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 208, /* color_definition_expression  */
  YYSYMBOL_color_definition = 209,         /* color_definition  */
  YYSYMBOL_milliseconds = 210,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 211,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 212, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 213,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 214, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 215, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 216,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 217, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 218, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 219,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 220, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 221, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 222,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 223,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 224, /* text_definition_expression  */
  YYSYMBOL_text_definition = 225,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 226,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 227, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 228,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 229, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 230, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 231,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 232, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 233, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 234,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 235,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 236,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 237,         /* gosub_definition  */
  YYSYMBOL_var_definition = 238,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 239,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 240, /* point_definition_expression  */
  YYSYMBOL_point_definition = 241,         /* point_definition  */
  YYSYMBOL_ink_definition = 242,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 243,       /* on_goto_definition  */
  YYSYMBOL_244_4 = 244,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 245,      /* on_gosub_definition  */
  YYSYMBOL_246_5 = 246,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 247,       /* on_proc_definition  */
  YYSYMBOL_248_6 = 248,                    /* $@6  */
  YYSYMBOL_on_definition = 249,            /* on_definition  */
  YYSYMBOL_250_7 = 250,                    /* $@7  */
  YYSYMBOL_251_8 = 251,                    /* $@8  */
  YYSYMBOL_252_9 = 252,                    /* $@9  */
  YYSYMBOL_every_definition = 253,         /* every_definition  */
  YYSYMBOL_add_definition = 254,           /* add_definition  */
  YYSYMBOL_dimensions = 255,               /* dimensions  */
  YYSYMBOL_datatype = 256,                 /* datatype  */
  YYSYMBOL_dim_definition = 257,           /* dim_definition  */
  YYSYMBOL_258_10 = 258,                   /* $@10  */
  YYSYMBOL_259_11 = 259,                   /* $@11  */
  YYSYMBOL_260_12 = 260,                   /* $@12  */
  YYSYMBOL_dim_definitions = 261,          /* dim_definitions  */
  YYSYMBOL_indexes = 262,                  /* indexes  */
  YYSYMBOL_parameters = 263,               /* parameters  */
  YYSYMBOL_parameters_expr = 264,          /* parameters_expr  */
  YYSYMBOL_values = 265,                   /* values  */
  YYSYMBOL_print_definition = 266,         /* print_definition  */
  YYSYMBOL_267_13 = 267,                   /* $@13  */
  YYSYMBOL_268_14 = 268,                   /* $@14  */
  YYSYMBOL_statement = 269,                /* statement  */
  YYSYMBOL_270_15 = 270,                   /* $@15  */
  YYSYMBOL_271_16 = 271,                   /* $@16  */
  YYSYMBOL_272_17 = 272,                   /* $@17  */
  YYSYMBOL_273_18 = 273,                   /* $@18  */
  YYSYMBOL_274_19 = 274,                   /* $@19  */
  YYSYMBOL_275_20 = 275,                   /* $@20  */
  YYSYMBOL_276_21 = 276,                   /* $@21  */
  YYSYMBOL_277_22 = 277,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 278, /* statements_no_linenumbers  */
  YYSYMBOL_279_23 = 279,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 280, /* statements_with_linenumbers  */
  YYSYMBOL_281_24 = 281,                   /* $@24  */
  YYSYMBOL_statements_complex = 282,       /* statements_complex  */
  YYSYMBOL_283_25 = 283,                   /* $@25  */
  YYSYMBOL_program = 284,                  /* program  */
  YYSYMBOL_285_26 = 285                    /* $@26  */
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
#define YYLAST   2073

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  183
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  103
/* YYNRULES -- Number of rules.  */
#define YYNRULES  431
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  834

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   437


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
     175,   176,   177,   178,   179,   180,   181,   182
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
     470,   473,   476,   480,   484,   488,   491,   494,   499,   499,
     502,   505,   508,   511,   514,   517,   521,   524,   527,   530,
     534,   537,   540,   543,   547,   550,   553,   556,   562,   565,
     568,   571,   574,   579,   580,   583,   586,   591,   594,   599,
     600,   603,   606,   611,   614,   619,   620,   623,   626,   629,
     634,   637,   640,   645,   646,   649,   650,   651,   654,   657,
     660,   665,   668,   671,   677,   678,   681,   684,   687,   690,
     693,   696,   699,   702,   705,   708,   711,   714,   717,   720,
     723,   728,   731,   734,   737,   740,   743,   746,   749,   752,
     755,   758,   761,   764,   767,   770,   775,   776,   779,   782,
     785,   788,   791,   797,   800,   806,   807,   810,   815,   820,
     821,   824,   827,   832,   835,   840,   841,   844,   849,   854,
     855,   858,   861,   864,   869,   872,   878,   879,   882,   885,
     888,   891,   894,   899,   902,   905,   910,   911,   913,   914,
     917,   920,   923,   928,   935,   938,   944,   947,   953,   956,
     962,   967,   968,   971,   976,   980,   980,   985,   989,   989,
     994,   998,   998,  1003,  1003,  1006,  1006,  1009,  1009,  1014,
    1017,  1020,  1025,  1028,  1034,  1038,  1045,  1048,  1051,  1054,
    1057,  1060,  1063,  1066,  1069,  1072,  1077,  1077,  1085,  1085,
    1093,  1093,  1104,  1105,  1109,  1113,  1120,  1125,  1130,  1135,
    1140,  1145,  1153,  1158,  1163,  1168,  1173,  1178,  1183,  1187,
    1194,  1198,  1205,  1208,  1212,  1215,  1215,  1219,  1219,  1225,
    1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,
    1236,  1237,  1238,  1239,  1240,  1241,  1242,  1245,  1248,  1251,
    1254,  1257,  1260,  1263,  1266,  1269,  1272,  1272,  1277,  1280,
    1283,  1286,  1289,  1292,  1295,  1298,  1301,  1304,  1307,  1310,
    1313,  1316,  1320,  1320,  1325,  1328,  1331,  1334,  1337,  1340,
    1344,  1348,  1352,  1352,  1357,  1357,  1362,  1362,  1367,  1370,
    1373,  1376,  1379,  1382,  1385,  1388,  1389,  1390,  1391,  1392,
    1395,  1398,  1401,  1404,  1407,  1410,  1413,  1416,  1417,  1426,
    1435,  1435,  1447,  1447,  1464,  1464,  1481,  1484,  1485,  1489,
    1490,  1490,  1494,  1494,  1501,  1501,  1504,  1505,  1506,  1507,
    1511,  1511
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
  "PARAM", "PRINT", "BLACK", "WHITE", "RED", "CYAN", "VIOLET", "GREEN",
  "BLUE", "YELLOW", "ORANGE", "BROWN", "LIGHT", "DARK", "GREY", "GRAY",
  "MAGENTA", "PURPLE", "LAVENDER", "GOLD", "TURQUOISE", "TAN", "PINK",
  "PEACH", "OLIVE", "Identifier", "String", "Integer", "\" \"", "$accept",
  "expr", "expr_math", "term", "modula", "factor", "direct_integer",
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
  "$@14", "statement", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20",
  "$@21", "$@22", "statements_no_linenumbers", "$@23",
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
     435,   436,   437
};
#endif

#define YYPACT_NINF (-720)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-411)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -720,    43,   785,  -720,  -720,  -133,  -128,   -12,  -720,    18,
    1487,    36,     1,  1487,  -720,    40,   187,  1622,   -88,    16,
    -720,  -720,  -720,  1192,    70,    29,  1622,  1622,    12,   -48,
    -720,    92,   112,  1622,  1622,  -720,   128,   132,    24,  1622,
      58,   143,  -720,   -30,  -720,  1622,    45,  1352,   181,    48,
    1622,    74,    77,   129,   136,    56,    56,  1622,    14,  -720,
     213,   238,   264,  -720,  -720,  -720,  1487,   249,  -720,  -720,
    -720,  1487,  1487,  1487,  -720,  -720,  -720,   100,  1032,  -720,
    -720,   255,   282,   284,   138,   139,  -720,  -720,   289,   290,
    1622,  -720,  -720,   291,   292,   293,   294,   295,   297,   298,
     299,   300,   301,   302,   303,   306,   309,   311,   312,   313,
    -720,  -720,   314,   104,  -720,  -720,  -720,  -720,  -720,  -720,
    -720,   158,  -720,  -720,   102,   -81,  -720,  -720,  -720,  -720,
    -720,  -720,  -720,  -720,  -720,   188,    11,  -720,  -720,    20,
      57,   222,   189,   227,    42,  -720,  -720,  -720,  -720,  -720,
      -5,   275,    -3,     4,     6,     8,   334,  -720,  -720,  -720,
     201,   285,  -720,  -720,  -720,  1487,  -720,  -720,   330,  -720,
    -720,  -720,  -720,  -720,  1487,   324,   325,  -720,  -720,  -720,
     -14,  -720,    81,  -720,  -720,  -720,  -720,  -720,  1622,  1622,
    -720,  -720,   365,  -720,  -720,  -720,  1487,  -720,  -720,  -720,
    1487,   344,  -720,  -720,  -720,   305,  -720,  -720,  -720,   228,
    1622,  1622,  -720,  -720,  1487,  -720,  -720,  -720,   342,  -720,
    -720,  -720,  -720,  -720,  -720,  -720,  -720,  1622,  1622,  -720,
    -720,  -720,  -720,   364,  -720,  -720,   226,  -720,  1622,   372,
    -720,  -720,  -720,    34,   373,  -720,   234,   235,   236,    63,
     377,  -720,  -720,   244,  -720,  -720,  -720,  1622,   378,  -720,
    -720,   352,    30,   932,  -720,   785,   785,   363,   366,  1487,
    -720,  -720,   321,   322,   326,   327,  -720,   361,   368,   370,
     371,   375,    59,   376,  1487,  1487,  1487,  -720,  -720,  -720,
    -720,  -720,  -720,  -720,  -720,  -720,  -720,  1622,  1622,  -720,
    1622,  1622,  1622,  1622,  1622,  1622,  1622,  1622,  1622,  1622,
    1622,  1622,  1622,  1622,  1622,  1622,  1622,  1757,   367,   221,
    -720,  -720,  -720,  -720,  -720,  -720,  -720,  -720,   374,  -720,
     379,  -720,  -720,  -720,  -720,  -720,  -720,  1757,  1757,  1757,
    1757,  1757,  1757,  1757,  1757,  1757,  1757,  1757,  1757,  1757,
    1892,  -720,  -720,  -720,  1487,   383,  -720,  -720,  -720,   369,
     275,   390,   275,   392,   275,   394,   275,   395,   275,  -720,
    1622,   387,  -720,  -720,    75,   205,    39,    94,  -720,  -720,
    -720,   388,   275,   391,  -720,  -720,   215,   223,   105,   121,
    -720,  -720,   393,  -720,  -720,  1487,  -720,  -720,  1487,  1487,
    -720,  -720,  -720,   384,   242,  -720,   418,  1622,  -720,  -720,
    -720,  -720,  1487,  -720,  1622,   421,   423,  -720,  -720,  1487,
     380,   425,  1622,   332,   429,  1622,  -720,  -720,  -720,  -720,
    -720,  -720,   165,  -720,  -720,   404,   420,    74,  -720,   296,
    -720,    56,   435,    30,    56,   248,   278,   785,  -720,  1622,
     410,  1622,  1622,   411,     2,  -720,   932,  -720,  -720,   267,
     268,  -720,  -720,  1622,   275,  1622,   275,   269,   271,   273,
     276,   279,   413,   424,   426,  -720,   427,   428,   430,   431,
     434,   436,   449,   451,   463,   465,   438,   439,   440,   441,
     470,   443,   444,   445,   447,   448,   477,   478,   452,   454,
     455,     7,   307,   456,   458,  1622,  1622,   222,   222,   277,
     277,   277,   277,   277,   277,   277,   277,   189,   227,   227,
    -720,   464,   467,  1487,   111,  -720,   275,  -720,   275,  -720,
     275,  -720,   275,    89,  -720,  1622,  -720,  -720,  -720,  -720,
    -720,  -720,  -720,  -720,  1622,  -720,   275,  -720,  -720,  -720,
    -720,  -720,  -720,  -720,  -720,   275,  -720,  -720,  -720,  -720,
    -720,  -720,   315,   318,   319,   320,   487,  1622,   495,   461,
     462,   357,  1622,  1622,   499,   500,  -720,   -56,   437,   329,
    1622,   503,  -720,  -720,  -720,   480,   331,   481,  -720,  1622,
     337,  1622,  -720,    56,   504,  -720,  1622,  1622,  -720,  -720,
    1622,   510,   381,   511,   484,  1622,  -720,  -720,  -720,  -720,
    -720,  -720,  -720,  -720,  -720,  -720,  -720,  -720,   339,   340,
     341,  -720,  -720,  -720,  -720,  -720,  -720,  1622,  1622,  1622,
    1622,  -720,  -720,  -720,  -720,  1622,  -720,  -720,  -720,  -720,
    -720,  1622,  1622,  -720,  -720,  -720,  1892,   488,  -720,  1622,
     382,   489,   347,   348,  -720,  -720,  -720,  -720,  -720,  -720,
     502,  -720,   507,  -720,   358,   167,  -720,   521,  -720,   525,
     530,  -720,   533,  -720,   534,  -720,   529,  1487,   536,  1622,
    1622,   275,  -720,   509,   512,  1622,   275,  -720,  -720,  1622,
    -720,    60,  1622,   331,   538,   513,   331,   398,   161,   401,
     402,  -720,    56,  -720,  -720,   516,  1622,  -720,  1622,   539,
     518,  -720,  -720,  -720,   519,   520,    78,   110,   523,   524,
     526,   531,  -720,   532,  -720,  -720,  -720,  -720,   385,   389,
    -720,   527,  -720,   535,  -720,  1622,   275,   553,   561,   564,
    1622,  -720,  -720,  1622,  -720,  -720,  -720,   559,   560,   540,
     541,   459,  1622,   565,   505,   545,   331,  -720,   547,  -720,
     337,   576,    30,  -720,  -720,  -720,   571,  -720,  -720,  1622,
     572,  -720,  -720,  1622,  -720,  1622,  -720,  -720,  -720,  -720,
    -720,  -720,  -720,  -720,   408,   409,   555,   556,   315,   318,
     319,  -720,  -720,  1622,  1622,  -720,  -720,  1622,   558,  1622,
    1622,  -720,  -720,  -720,  -720,   337,   587,  1622,  -720,  1622,
     563,   567,  -720,  -720,  -720,  -720,  -720,  -720,  -720,  -720,
    -720,  -720,   583,  -720,  -720,  -720,   337,  -720,  -720,  -720,
    -720,  1622,  -720,  -720
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     430,     0,   418,     1,   417,     0,     0,     0,   402,     0,
       0,   370,     0,     0,   393,     0,     0,     0,   248,     0,
     355,   359,   356,     0,     0,     0,     0,     0,     0,   394,
     353,     0,     0,     0,   348,   392,     0,     0,     0,   399,
     401,   351,   354,   361,   358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   414,   422,
     419,   426,   428,   431,   346,   347,     0,     0,   149,   150,
     330,     0,     0,     0,   163,   164,   332,     0,     0,    79,
      80,     0,     0,     0,     0,     0,   115,   116,     0,     0,
       0,   112,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   117,     0,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,    44,    49,    50,    51,
      52,    53,    54,    57,    58,     0,    63,    67,    65,     0,
       2,    12,    15,    17,     0,    76,    20,   174,   175,   333,
       0,     0,     0,     0,     0,     0,     0,   143,   144,   329,
       0,     0,   206,   207,   334,     0,   209,   210,   211,   215,
     216,   335,   238,   239,     0,     0,     0,   246,   247,   340,
       0,   395,     0,   258,   343,   254,   255,   396,     0,     0,
     221,   222,     0,   225,   226,   337,     0,   229,   230,   338,
       0,   232,   236,   237,   339,     0,   388,   390,   391,   376,
       0,     0,   416,   349,     0,   219,   220,   336,     0,   261,
     262,   341,   256,   257,   397,   400,   363,     0,     0,   362,
     365,   366,   360,     0,   280,   281,     0,   398,     0,     0,
     344,   263,   342,   296,   302,   407,   380,   371,   381,   312,
     318,   374,   375,   322,   345,   424,   389,     0,   412,   382,
     379,     0,     0,   418,   420,   418,   418,     0,     0,     0,
     160,   157,     0,     0,     0,     0,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    24,    25,
      27,    29,    30,    26,    31,   101,    23,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    42,    45,    46,    47,    48,    43,    56,    64,   108,
       0,   165,   171,   166,   167,   172,   173,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   168,   169,   170,     0,     0,   155,   156,   331,   120,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
       0,     0,   196,   197,     0,     0,     0,     0,   193,   192,
     118,     0,     0,     0,   181,   182,     0,     0,     0,     0,
     178,   177,     0,   213,   208,     0,   243,   240,     0,     0,
     273,   277,   275,     0,     0,   357,     0,     0,   228,   227,
     234,   231,     0,   350,     0,     0,     0,   218,   217,     0,
       0,   364,     0,     0,     0,     0,   294,   286,   288,   293,
     290,   295,     0,   292,   300,     0,     0,     0,   384,     0,
     386,     0,   313,     0,     0,   327,   325,   418,   408,     0,
       0,     0,     0,     0,   414,   423,   418,   427,   429,     0,
       0,   147,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,     5,
       7,     8,     9,    10,     6,     3,     4,    16,    18,    19,
      21,     0,     0,     0,     0,   125,     0,   137,     0,   129,
       0,   133,     0,   121,   194,     0,   201,   200,   205,   204,
     199,   203,   198,   202,     0,   179,     0,   186,   185,   190,
     189,   184,   188,   183,   187,     0,   214,   212,   244,   241,
     245,   242,     0,     0,     0,     0,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   352,     0,     0,     0,
       0,   282,   287,   289,   291,     0,     0,     0,   303,     0,
       0,     0,   315,     0,   314,   319,     0,     0,   425,   409,
       0,   320,     0,   304,     0,     0,   421,   148,   146,   162,
     159,   161,   158,    75,    68,    70,    74,    72,     0,     0,
       0,    78,    77,    82,    81,    84,    83,     0,     0,     0,
       0,    91,    92,    93,   100,     0,    94,    95,    96,    97,
      98,     0,     0,   110,   111,   102,     0,     0,   106,     0,
       0,     0,     0,     0,   153,   151,   122,   135,   127,   130,
     124,   136,   128,   132,     0,     0,   191,     0,   176,     0,
     264,   274,   267,   278,   270,   276,   250,     0,     0,     0,
       0,     0,   377,     0,     0,     0,     0,   367,   368,     0,
     279,     0,     0,     0,   284,     0,     0,     0,   306,     0,
       0,   316,     0,   328,   326,     0,     0,   383,     0,     0,
       0,    69,    71,    73,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,   109,    60,   154,   152,     0,     0,
     138,   123,   134,   126,   131,     0,     0,     0,     0,     0,
       0,   252,   251,     0,   224,   235,   233,     0,     0,     0,
       0,   369,     0,     0,     0,     0,     0,   297,     0,   385,
       0,   307,     0,   373,   387,   317,     0,   321,   305,     0,
       0,    85,    86,     0,    87,     0,    89,    99,   105,   104,
      22,    62,   140,   142,     0,     0,     0,     0,     0,     0,
       0,   253,   223,     0,     0,   260,   259,     0,     0,     0,
       0,   301,   285,   299,   309,     0,   308,     0,   411,     0,
       0,     0,   139,   141,   195,   180,   266,   269,   272,   403,
     404,   378,     0,   405,   283,   310,     0,   413,   415,    88,
      90,     0,   311,   406
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -720,   -10,    23,   -26,   253,  -220,    69,  -720,  -720,  -720,
    -339,  -720,  -720,  -720,   442,  -720,  -720,  -720,  -720,  -720,
    -720,  -720,  -720,  -720,  -720,  -720,  -720,   460,  -720,  -720,
    -720,  -720,  -720,  -720,  -720,  -720,  -720,  -720,  -720,  -720,
    -720,  -720,  -720,  -720,  -720,  -720,  -720,  -720,  -720,  -720,
    -720,  -720,  -720,  -720,  -720,  -720,  -720,  -720,  -720,  -720,
    -183,  -720,  -182,  -720,  -184,  -720,  -720,  -720,  -720,  -720,
    -720,  -720,  -636,  -261,  -720,  -720,  -720,  -720,   171,  -502,
    -719,   -54,  -499,  -283,  -720,  -720,  -720,  -720,  -720,  -720,
    -720,  -720,  -720,  -720,  -720,  -258,  -720,  -720,  -720,  -256,
    -720,  -720,  -720
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   603,   140,   141,   142,   143,   144,   294,   295,   145,
     146,   330,   504,   505,   381,   157,   158,   159,    68,    69,
      70,   356,   357,   358,    74,    75,    76,   336,   147,   148,
     149,   162,   163,   164,   169,   170,   171,   215,   216,   217,
     193,   194,   195,   197,   198,   199,   202,   203,   204,   177,
     178,   179,   183,   187,   224,   184,   219,   220,   221,   242,
     671,   737,   673,   738,   675,   739,   181,   562,   564,   563,
     237,   240,   695,   434,   244,   435,   436,   585,   245,   604,
     699,   251,   602,   254,   597,   596,    60,   188,   439,   451,
     589,   591,   261,   450,   262,    61,   456,    62,   263,    63,
     447,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     139,   453,   252,   160,   651,   455,   650,   180,   256,   457,
     458,   520,    66,   192,   646,   257,   205,   206,   255,   354,
     256,   360,   258,   212,   213,   151,    85,   257,   362,   225,
     364,   328,   366,   152,   258,   232,  -410,   236,   228,   400,
     241,   804,   208,     3,    71,   -59,    64,   253,  -410,    72,
     153,    65,    85,   200,  -298,   426,   267,   755,   150,   426,
     758,   270,   272,   274,   165,   337,   338,   752,   283,   339,
     441,   340,   341,   342,   343,   344,   166,   167,   154,   155,
     299,   325,   161,   442,   540,   773,   825,   326,   401,    73,
     697,   182,   700,   541,   196,   753,   209,   501,   705,   331,
     332,   403,   207,   710,   427,   428,   429,   832,   427,   428,
     429,   443,   231,   774,   229,   430,   201,   775,   664,   430,
     802,   331,   351,   404,   318,   687,   210,   168,   518,   519,
     402,   536,   537,   472,   473,   268,   350,   665,   319,   542,
     271,   273,   275,   656,   474,   776,   211,   723,   543,   259,
     551,   230,   214,   431,   345,   393,   218,   431,   329,   552,
     657,   259,   346,   287,   396,   432,   553,    67,   760,   432,
     333,   334,   335,   433,   355,   554,   361,   433,   405,   406,
     156,   761,   594,   363,   260,   365,   408,   367,   658,   659,
     410,   598,   333,   334,   352,   185,   260,   186,   606,   731,
     415,   416,   226,   222,   417,   223,   768,   767,   348,   762,
     349,   227,   288,   289,   290,   238,   732,   420,   421,   264,
     359,   291,   292,   293,   233,   369,   370,   239,   424,   172,
     173,   174,   175,   371,   394,   249,   250,   372,   373,   582,
     583,   176,   265,   397,   733,   734,   374,   448,  -324,   445,
     584,   446,  -324,   243,  -324,   375,   246,   376,   377,   461,
     321,   538,   539,   322,   323,   409,   378,   379,   266,   411,
     324,   547,   548,   269,   476,   478,   480,   380,  -323,   549,
     550,   276,  -323,   418,  -323,   337,   338,   482,   483,   284,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   721,   247,   369,
     382,   507,   508,   703,   704,   248,   285,   383,   286,   320,
     296,   384,   385,   297,   298,   300,   301,   302,   303,   304,
     386,   305,   306,   307,   308,   309,   310,   311,   462,   387,
     312,   388,   389,   313,   521,   314,   315,   316,   317,   327,
     390,   391,   347,   477,   479,   481,   350,    85,   368,   395,
     534,   380,   509,   510,   511,   512,   513,   514,   515,   516,
     398,   399,   407,   412,   413,   414,   419,   422,   423,   425,
     437,   438,  -372,   440,   444,   556,   452,   592,   558,   560,
     595,   449,   459,   463,   464,   460,   467,   568,   465,   466,
     503,   502,   569,   468,   571,   469,   470,   523,   -61,   574,
     471,   475,   578,   506,   526,   581,   528,   524,   530,   532,
     535,   566,   544,   522,   546,   567,   565,   555,   572,   525,
     573,   527,   577,   529,   579,   531,   580,   533,   586,   599,
     587,   601,   593,   590,   600,   605,   607,   608,   618,   576,
     613,   545,   614,   609,   615,   611,   627,   616,   628,   619,
     617,   620,   621,   622,   557,   623,   624,   559,   561,   625,
     629,   626,   630,   631,   632,   633,   634,   635,   636,   637,
     638,   570,   639,   640,   641,   642,   647,   643,   575,   644,
     645,   648,   649,   652,   670,   601,   653,   672,   674,   676,
     677,   806,   679,   680,   681,   682,   685,   686,   690,   689,
     692,   702,   694,   654,   693,   696,   698,   706,   708,   709,
     711,   712,   713,   722,   725,   666,   726,   727,   735,   707,
     724,   728,   736,   610,   667,   612,   729,  -265,   730,   701,
    -268,  -271,   740,   743,   747,   756,   759,   748,   757,   763,
     764,   766,   769,   770,   771,   772,   784,   678,   777,   778,
     788,   779,   683,   684,   785,   782,   780,   781,   789,   783,
     691,   790,   793,   794,   797,   795,   796,   800,   799,   601,
     801,   601,   803,   805,   807,   809,   253,   253,   812,   813,
     814,   815,   655,   822,   826,   660,   831,   661,   829,   662,
     517,   663,   830,   392,   353,   816,   818,   817,   588,     0,
       0,     0,     0,     0,     0,   668,     0,   714,   715,   716,
     717,     0,     0,     0,   669,   718,     0,     0,     0,     0,
       0,   719,   720,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   688,     0,   765,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   741,     0,   744,
     745,     0,     0,     0,     0,   749,     0,     0,     0,   751,
       0,     0,   754,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   786,     0,     0,     0,     0,
     791,     0,     0,   792,     0,     0,     0,     0,     0,     0,
       0,     0,   798,     0,     0,     0,   742,     0,     0,     0,
     746,     0,     0,     0,     0,   750,     0,     0,     0,   808,
       0,     0,     0,   810,     0,   811,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   819,   820,     0,     0,   821,     4,   823,
     824,     0,     0,     0,     0,     5,     6,   827,     0,   828,
       0,     0,     0,     0,     0,   787,     0,     7,     8,     0,
       9,     0,    10,    11,     0,    12,    13,     0,     0,     0,
       0,   833,     0,    14,     0,    15,    16,    17,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,    28,    29,     0,    30,     0,     0,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
       0,    41,     0,     0,     0,    42,    43,    44,    45,    46,
       0,    47,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,     0,     0,     0,
       0,     0,     0,     0,    50,     0,     0,    51,     0,    52,
      53,    54,     0,     0,    55,     4,     0,     0,    56,     0,
      57,     0,     5,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     9,     0,    10,
      11,     0,    12,    13,    58,     0,    59,     0,     0,     0,
      14,     0,    15,    16,    17,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
      28,    29,     0,    30,     0,     0,    31,    32,    33,     0,
      34,    35,    36,    37,    38,    39,    40,     0,    41,     0,
       0,    77,    42,    43,    44,    45,    46,     0,    47,    48,
       0,     0,     0,     0,     0,     0,     0,   277,     0,     0,
       0,     0,     0,    49,     0,     0,    78,     0,     0,     0,
       0,    50,     0,     0,    51,     0,    52,    53,    54,     0,
       0,    55,    79,    80,    81,    56,     0,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
       0,     0,    83,     0,     0,    84,   278,   279,   280,     0,
       0,   454,     0,     0,     0,    86,    87,   281,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   105,   106,   107,   282,   108,   109,
     110,     0,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    77,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,   189,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,   190,   191,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
       0,     0,    83,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   105,   106,   107,     0,   108,   109,
     110,     0,   111,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    77,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,   234,   235,     0,     0,     0,     0,
       0,     0,    79,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
       0,     0,    83,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   105,   106,   107,     0,   108,   109,
     110,     0,   111,   112,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    78,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,    79,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,    83,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      86,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,     0,     0,     0,
       0,     0,     0,     0,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,     0,   105,
     106,   107,     0,   108,   109,   110,     0,   111,   112,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    78,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,     0,
       0,     0,    79,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
       0,     0,    83,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   105,   106,   107,     0,   108,   109,
     110,     0,   111,   112,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,    78,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,    79,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,    83,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,     0,     0,     0,
       0,     0,     0,     0,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,     0,   105,
     106,   107,     0,   108,   109,   110,     0,   111,   112,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    78,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,     0,
       0,     0,    79,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
       0,     0,    83,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,     0,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   105,   106,   107,     0,   108,   109,
     110,     0,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,     0,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138
};

static const yytype_int16 yycheck[] =
{
      10,   262,    56,    13,   506,   263,   505,    17,     6,   265,
     266,   350,    24,    23,     7,    13,    26,    27,     4,    24,
       6,    24,    20,    33,    34,    24,    82,    13,    24,    39,
      24,    20,    24,    32,    20,    45,    34,    47,    68,    53,
      50,   760,    90,     0,    26,    34,   179,    57,    34,    31,
      49,   179,    82,    24,    20,    25,    66,   693,    22,    25,
     696,    71,    72,    73,    24,     8,     9,     7,    78,    12,
       7,    14,    15,    16,    17,    18,    36,    37,    77,    78,
      90,   162,    13,    20,    45,     7,   805,   168,   102,    71,
     589,   179,   591,    54,    24,    35,   144,   317,   600,    79,
      80,    20,    90,   605,    74,    75,    76,   826,    74,    75,
      76,    48,    43,    35,   144,    85,    87,     7,    29,    85,
     756,    79,    80,    42,    20,   181,    34,    87,   348,   349,
     144,    56,    57,    74,    75,    66,   129,    48,    34,    45,
      71,    72,    73,    32,    85,    35,    34,   649,    54,   147,
      45,   181,    24,   123,    97,   165,    24,   123,   147,    54,
      49,   147,   105,    25,   174,   135,    45,   179,     7,   135,
     150,   151,   152,   143,   179,    54,   179,   143,   188,   189,
     179,    20,   443,   179,   182,   179,   196,   179,    77,    78,
     200,   447,   150,   151,   152,   179,   182,   181,   456,    32,
     210,   211,   144,   179,   214,   181,   708,   706,    19,    48,
      21,    68,    74,    75,    76,    34,    49,   227,   228,     6,
     151,    83,    84,    85,   179,    24,    25,   179,   238,    42,
      43,    44,    45,    32,   165,   179,   180,    36,    37,    74,
      75,    54,     4,   174,    77,    78,    45,   257,     0,     5,
      85,     7,     4,   179,     6,    54,   179,    56,    57,   269,
     158,    56,    57,   161,   162,   196,    65,    66,     4,   200,
     168,    56,    57,    24,   284,   285,   286,    76,     0,    56,
      57,   181,     4,   214,     6,     8,     9,   297,   298,    34,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   646,   179,    24,
      25,   337,   338,   596,   597,   179,    34,    32,    34,   161,
     181,    36,    37,    34,    34,    34,    34,    34,    34,    34,
      45,    34,    34,    34,    34,    34,    34,    34,   269,    54,
      34,    56,    57,    34,   354,    34,    34,    34,    34,   161,
      65,    66,   130,   284,   285,   286,   129,    82,    24,    29,
     370,    76,   339,   340,   341,   342,   343,   344,   345,   346,
      46,    46,     7,    29,    69,   147,    34,    13,   152,     7,
       7,   147,   147,   147,     7,   395,    34,   441,   398,   399,
     444,    13,    29,    72,    72,    29,    35,   407,    72,    72,
     179,    34,   412,    35,   414,    35,    35,    24,    34,   419,
      35,    35,   422,    34,    24,   425,    24,    48,    24,    24,
      33,   179,    34,   354,    33,     7,    42,    34,     7,   360,
       7,   362,     7,   364,   102,   366,     7,   368,    34,   449,
      20,   451,     7,   147,    34,    34,   179,   179,    35,    69,
     181,   382,   181,   463,   181,   465,     7,   181,     7,    35,
     181,    35,    35,    35,   395,    35,    35,   398,   399,    35,
       7,    35,     7,    35,    35,    35,    35,     7,    35,    35,
      35,   412,    35,    35,     7,     7,   179,    35,   419,    35,
      35,    35,    34,    29,   179,   505,    29,   179,   179,   179,
      13,   762,     7,    42,    42,   148,     7,     7,   179,    72,
       7,     7,   181,   523,    34,    34,   179,     7,     7,    35,
     181,   181,   181,    35,    35,   535,   179,   179,     7,   148,
     148,    29,     7,   464,   544,   466,    29,     7,   180,   593,
       7,     7,    13,     7,    35,     7,   148,    35,    35,   148,
     148,    35,    13,    35,    35,    35,    29,   567,    35,    35,
       7,    35,   572,   573,    29,   180,    35,    35,     7,   180,
     580,     7,    13,    13,   115,    35,    35,    72,    13,   589,
      35,   591,    35,     7,    13,    13,   596,   597,   180,   180,
      35,    35,   523,    35,     7,   526,    13,   528,    35,   530,
     347,   532,    35,   161,   144,   788,   790,   789,   437,    -1,
      -1,    -1,    -1,    -1,    -1,   546,    -1,   627,   628,   629,
     630,    -1,    -1,    -1,   555,   635,    -1,    -1,    -1,    -1,
      -1,   641,   642,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   577,    -1,   702,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   677,    -1,   679,
     680,    -1,    -1,    -1,    -1,   685,    -1,    -1,    -1,   689,
      -1,    -1,   692,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   706,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   735,    -1,    -1,    -1,    -1,
     740,    -1,    -1,   743,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   752,    -1,    -1,    -1,   677,    -1,    -1,    -1,
     681,    -1,    -1,    -1,    -1,   686,    -1,    -1,    -1,   769,
      -1,    -1,    -1,   773,    -1,   775,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   793,   794,    -1,    -1,   797,     3,   799,
     800,    -1,    -1,    -1,    -1,    10,    11,   807,    -1,   809,
      -1,    -1,    -1,    -1,    -1,   736,    -1,    22,    23,    -1,
      25,    -1,    27,    28,    -1,    30,    31,    -1,    -1,    -1,
      -1,   831,    -1,    38,    -1,    40,    41,    42,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    88,    89,    -1,    91,    -1,    -1,    94,
      95,    96,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
      -1,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    -1,    -1,   142,    -1,   144,
     145,   146,    -1,    -1,   149,     3,    -1,    -1,   153,    -1,
     155,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    -1,    25,    -1,    27,
      28,    -1,    30,    31,   179,    -1,   181,    -1,    -1,    -1,
      38,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      88,    89,    -1,    91,    -1,    -1,    94,    95,    96,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,   106,    -1,
      -1,     9,   110,   111,   112,   113,   114,    -1,   116,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    34,    -1,    -1,    -1,
      -1,   139,    -1,    -1,   142,    -1,   144,   145,   146,    -1,
      -1,   149,    50,    51,    52,   153,    -1,   155,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    73,    74,    75,    76,    -1,
      -1,   179,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,   132,   133,   134,   135,   136,   137,
     138,    -1,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,     9,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,     9,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    -1,    -1,    -1,
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
     138,    -1,   140,   141,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    34,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,   141,    -1,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    34,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,
     138,    -1,   140,   141,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    34,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,   141,    -1,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    34,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,
     138,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   284,   285,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    86,    88,    89,
      91,    94,    95,    96,    98,    99,   100,   101,   102,   103,
     104,   106,   110,   111,   112,   113,   114,   116,   117,   131,
     139,   142,   144,   145,   146,   149,   153,   155,   179,   181,
     269,   278,   280,   282,   179,   179,    24,   179,   201,   202,
     203,    26,    31,    71,   207,   208,   209,     9,    34,    50,
      51,    52,    67,    70,    73,    82,    83,    84,    94,    95,
     107,   108,   109,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   132,   133,   134,   136,   137,
     138,   140,   141,   154,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   184,
     185,   186,   187,   188,   189,   192,   193,   211,   212,   213,
      22,    24,    32,    49,    77,    78,   179,   198,   199,   200,
     184,   189,   214,   215,   216,    24,    36,    37,    87,   217,
     218,   219,    42,    43,    44,    45,    54,   232,   233,   234,
     184,   249,   179,   235,   238,   179,   181,   236,   270,    24,
      36,    37,   184,   223,   224,   225,    24,   226,   227,   228,
      24,    87,   229,   230,   231,   184,   184,    90,    90,   144,
      34,    34,   184,   184,    24,   220,   221,   222,    24,   239,
     240,   241,   179,   181,   237,   184,   144,    68,    68,   144,
     181,   189,   184,   179,    42,    43,   184,   253,    34,   179,
     254,   184,   242,   179,   257,   261,   179,   179,   179,   179,
     180,   264,   264,   184,   266,     4,     6,    13,    20,   147,
     182,   275,   277,   281,     6,     4,     4,   184,   189,    24,
     184,   189,   184,   189,   184,   189,   181,    25,    74,    75,
      76,    85,   135,   184,    34,    34,    34,    25,    74,    75,
      76,    83,    84,    85,   190,   191,   181,    34,    34,   184,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    20,    34,
     161,   158,   161,   162,   168,   162,   168,   161,    20,   147,
     194,    79,    80,   150,   151,   152,   210,     8,     9,    12,
      14,    15,    16,    17,    18,    97,   105,   130,    19,    21,
     129,    80,   152,   210,    24,   179,   204,   205,   206,   189,
      24,   179,    24,   179,    24,   179,    24,   179,    24,    24,
      25,    32,    36,    37,    45,    54,    56,    57,    65,    66,
      76,   197,    25,    32,    36,    37,    45,    54,    56,    57,
      65,    66,   197,   184,   189,    29,   184,   189,    46,    46,
      53,   102,   144,    20,    42,   184,   184,     7,   184,   189,
     184,   189,    29,    69,   147,   184,   184,   184,   189,    34,
     184,   184,    13,   152,   184,     7,    25,    74,    75,    76,
      85,   123,   135,   143,   256,   258,   259,     7,   147,   271,
     147,     7,    20,    48,     7,     5,     7,   283,   184,    13,
     276,   272,    34,   256,   179,   278,   279,   282,   282,    29,
      29,   184,   189,    72,    72,    72,    72,    35,    35,    35,
      35,    35,    74,    75,    85,    35,   184,   189,   184,   189,
     184,   189,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   188,    34,   179,   195,   196,    34,   186,   186,   185,
     185,   185,   185,   185,   185,   185,   185,   187,   188,   188,
     193,   184,   189,    24,    48,   189,    24,   189,    24,   189,
      24,   189,    24,   189,   184,    33,    56,    57,    56,    57,
      45,    54,    45,    54,    34,   189,    33,    56,    57,    56,
      57,    45,    54,    45,    54,    34,   184,   189,   184,   189,
     184,   189,   250,   252,   251,    42,   179,     7,   184,   184,
     189,   184,     7,     7,   184,   189,    69,     7,   184,   102,
       7,   184,    74,    75,    85,   260,    34,    20,   261,   273,
     147,   274,   264,     7,   256,   264,   268,   267,   282,   184,
      34,   184,   265,   184,   262,    34,   278,   179,   179,   184,
     189,   184,   189,   181,   181,   181,   181,   181,    35,    35,
      35,    35,    35,    35,    35,    35,    35,     7,     7,     7,
       7,    35,    35,    35,    35,     7,    35,    35,    35,    35,
      35,     7,     7,    35,    35,    35,     7,   179,    35,    34,
     265,   262,    29,    29,   184,   189,    32,    49,    77,    78,
     189,   189,   189,   189,    29,    48,   184,   184,   189,   189,
     179,   243,   179,   245,   179,   247,   179,    13,   184,     7,
      42,    42,   148,   184,   184,     7,     7,   181,   189,    72,
     179,   184,     7,    34,   181,   255,    34,   265,   179,   263,
     265,   264,     7,   266,   266,   262,     7,   148,     7,    35,
     262,   181,   181,   181,   184,   184,   184,   184,   184,   184,
     184,   193,    35,   262,   148,    35,   179,   179,    29,    29,
     180,    32,    49,    77,    78,     7,     7,   244,   246,   248,
      13,   184,   189,     7,   184,   184,   189,    35,    35,   184,
     189,   184,     7,    35,   184,   255,     7,    35,   255,   148,
       7,    20,    48,   148,   148,   264,    35,   265,   262,    13,
      35,    35,    35,     7,    35,     7,    35,    35,    35,    35,
      35,    35,   180,   180,    29,    29,   184,   189,     7,     7,
       7,   184,   184,    13,    13,    35,    35,   115,   184,    13,
      72,    35,   255,    35,   263,     7,   256,    13,   184,    13,
     184,   184,   180,   180,    35,    35,   243,   245,   247,   184,
     184,   184,    35,   184,   184,   263,     7,   184,   184,    35,
      35,    13,   263,   184
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   183,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   185,   185,   185,   186,   186,   187,   187,   187,
     188,   188,   188,   189,   190,   190,   190,   190,   190,   190,
     190,   191,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   194,
     193,   195,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   196,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   197,   197,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   199,   199,
     199,   199,   199,   200,   200,   201,   201,   202,   202,   203,
     203,   204,   204,   205,   205,   206,   206,   207,   207,   207,
     208,   208,   208,   209,   209,   210,   210,   210,   211,   211,
     211,   212,   212,   212,   213,   213,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   216,   216,   217,   217,
     217,   217,   217,   218,   218,   219,   219,   220,   221,   222,
     222,   223,   223,   224,   224,   225,   225,   226,   227,   228,
     228,   229,   229,   229,   230,   230,   231,   231,   232,   232,
     232,   232,   232,   233,   233,   233,   234,   234,   235,   235,
     235,   235,   235,   235,   236,   236,   237,   237,   238,   239,
     240,   241,   241,   242,   243,   244,   243,   245,   246,   245,
     247,   248,   247,   250,   249,   251,   249,   252,   249,   253,
     253,   253,   254,   254,   255,   255,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   258,   257,   259,   257,
     260,   257,   261,   261,   262,   262,   263,   263,   263,   263,
     263,   263,   264,   264,   264,   264,   264,   264,   264,   264,
     265,   265,   266,   266,   266,   267,   266,   268,   266,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   270,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   271,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   272,   269,   273,   269,   274,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     275,   269,   276,   269,   277,   269,   269,   269,   269,   278,
     279,   278,   281,   280,   283,   282,   282,   282,   282,   282,
     285,   284
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
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     6,     5,     1,     1,     2,     2,     1,
       1,     2,     1,     5,     2,     5,     1,     1,     1,     1,
       2,     3,     3,     2,     3,     3,     1,     1,     0,     3,
       4,     5,     5,     6,     1,     1,     1,     1,     1,     6,
       6,     1,     1,     1,     1,     0,     4,     1,     0,     4,
       1,     0,     4,     0,     4,     0,     4,     0,     4,     4,
       1,     1,     3,     7,     1,     3,     1,     2,     1,     2,
       1,     2,     1,     1,     1,     1,     0,     5,     0,     6,
       0,     6,     1,     3,     1,     3,     1,     2,     3,     3,
       4,     5,     1,     2,     3,     3,     4,     5,     1,     3,
       1,     3,     1,     2,     2,     0,     4,     0,     4,     2,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       3,     1,     4,     1,     1,     1,     0,     3,     1,     1,
       2,     1,     2,     2,     3,     2,     2,     5,     5,     6,
       1,     2,     0,     6,     2,     2,     2,     5,     8,     2,
       2,     2,     0,     5,     0,     6,     0,     6,     2,     2,
       2,     2,     1,     1,     1,     2,     2,     2,     2,     1,
       2,     1,     1,     8,     8,     8,    10,     2,     3,     4,
       0,     7,     0,     8,     0,     8,     2,     1,     0,     1,
       0,     4,     0,     3,     0,     4,     1,     3,     1,     3,
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
#line 73 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2616 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 77 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2625 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 81 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2633 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 84 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2641 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 87 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2649 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 90 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2657 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 93 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2665 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 96 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2673 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 99 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2681 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 106 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2689 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 109 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2698 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 122 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2707 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 126 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2716 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 134 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2725 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 138 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 2734 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 145 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2742 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 150 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2750 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 153 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2758 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 156 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2766 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 159 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2774 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 162 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2782 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 165 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2790 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 168 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2798 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 173 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2806 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 178 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2815 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 182 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2824 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 186 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2833 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 190 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2842 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 194 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2851 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 198 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2860 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 202 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2869 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 206 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2878 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 210 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2887 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 214 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2896 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 218 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2905 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 222 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2914 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 226 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2923 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 230 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2932 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 234 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2941 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 238 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2950 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 242 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2959 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 246 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2968 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 250 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2977 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 254 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2986 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 258 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2995 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 262 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3004 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 266 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3013 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 270 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3022 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 274 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3031 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 278 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3040 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 282 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3049 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 288 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3058 "src-generated/ugbc.tab.c"
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
#line 3070 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 299 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3079 "src-generated/ugbc.tab.c"
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
#line 3091 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 310 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3099 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 313 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3107 "src-generated/ugbc.tab.c"
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
#line 3121 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 325 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3130 "src-generated/ugbc.tab.c"
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
#line 3142 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 336 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3151 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 340 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3160 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 344 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3169 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 348 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3178 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 352 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3187 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 356 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3196 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 360 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3205 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 364 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3214 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 368 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3222 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 371 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3230 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 374 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3238 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 377 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3246 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 380 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3254 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 383 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3262 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 386 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3270 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 389 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3278 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 392 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3286 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 395 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3294 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 398 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3302 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 401 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3310 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 404 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3318 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 407 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3326 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 410 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3334 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 413 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3342 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 416 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3350 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 419 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3358 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 422 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3366 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 425 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3374 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 428 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3382 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 431 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3390 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 434 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3398 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 437 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3406 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 440 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3414 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 443 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3422 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 446 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3430 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 449 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3438 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 452 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3446 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 455 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3454 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 458 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3462 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 461 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3470 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 464 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3478 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 466 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3487 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 470 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3495 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 473 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3503 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 476 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3512 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 480 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3521 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 484 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3530 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: WIDTH  */
#line 488 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3538 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: HEIGHT  */
#line 491 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3546 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: TIMER  */
#line 494 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3554 "src-generated/ugbc.tab.c"
    break;

  case 120: /* bank_definition_simple: AT direct_integer  */
#line 502 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3562 "src-generated/ugbc.tab.c"
    break;

  case 121: /* bank_definition_simple: Identifier AT direct_integer  */
#line 505 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3570 "src-generated/ugbc.tab.c"
    break;

  case 122: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 508 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3578 "src-generated/ugbc.tab.c"
    break;

  case 123: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 511 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3586 "src-generated/ugbc.tab.c"
    break;

  case 124: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 514 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3594 "src-generated/ugbc.tab.c"
    break;

  case 125: /* bank_definition_simple: DATA AT direct_integer  */
#line 517 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3602 "src-generated/ugbc.tab.c"
    break;

  case 126: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 521 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3610 "src-generated/ugbc.tab.c"
    break;

  case 127: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 524 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3618 "src-generated/ugbc.tab.c"
    break;

  case 128: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 527 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3626 "src-generated/ugbc.tab.c"
    break;

  case 129: /* bank_definition_simple: CODE AT direct_integer  */
#line 530 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3634 "src-generated/ugbc.tab.c"
    break;

  case 130: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 534 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3642 "src-generated/ugbc.tab.c"
    break;

  case 131: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 537 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3650 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 540 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3658 "src-generated/ugbc.tab.c"
    break;

  case 133: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 543 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3666 "src-generated/ugbc.tab.c"
    break;

  case 134: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 547 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3674 "src-generated/ugbc.tab.c"
    break;

  case 135: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 550 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3682 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 553 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3690 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 556 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3698 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 562 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3706 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 565 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3714 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 568 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3722 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 571 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3730 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 574 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3738 "src-generated/ugbc.tab.c"
    break;

  case 145: /* raster_definition_simple: Identifier AT direct_integer  */
#line 583 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3746 "src-generated/ugbc.tab.c"
    break;

  case 146: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 586 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3754 "src-generated/ugbc.tab.c"
    break;

  case 147: /* raster_definition_expression: Identifier AT expr  */
#line 591 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3762 "src-generated/ugbc.tab.c"
    break;

  case 148: /* raster_definition_expression: AT expr WITH Identifier  */
#line 594 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3770 "src-generated/ugbc.tab.c"
    break;

  case 151: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 603 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3778 "src-generated/ugbc.tab.c"
    break;

  case 152: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 606 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3786 "src-generated/ugbc.tab.c"
    break;

  case 153: /* next_raster_definition_expression: Identifier AT expr  */
#line 611 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3794 "src-generated/ugbc.tab.c"
    break;

  case 154: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 614 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3802 "src-generated/ugbc.tab.c"
    break;

  case 157: /* color_definition_simple: BORDER direct_integer  */
#line 623 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3810 "src-generated/ugbc.tab.c"
    break;

  case 158: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 626 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3818 "src-generated/ugbc.tab.c"
    break;

  case 159: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 629 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3826 "src-generated/ugbc.tab.c"
    break;

  case 160: /* color_definition_expression: BORDER expr  */
#line 634 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3834 "src-generated/ugbc.tab.c"
    break;

  case 161: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 637 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3842 "src-generated/ugbc.tab.c"
    break;

  case 162: /* color_definition_expression: SPRITE expr TO expr  */
#line 640 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3850 "src-generated/ugbc.tab.c"
    break;

  case 168: /* wait_definition_simple: direct_integer CYCLES  */
#line 654 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3858 "src-generated/ugbc.tab.c"
    break;

  case 169: /* wait_definition_simple: direct_integer TICKS  */
#line 657 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3866 "src-generated/ugbc.tab.c"
    break;

  case 170: /* wait_definition_simple: direct_integer milliseconds  */
#line 660 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3874 "src-generated/ugbc.tab.c"
    break;

  case 171: /* wait_definition_expression: expr CYCLES  */
#line 665 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3882 "src-generated/ugbc.tab.c"
    break;

  case 172: /* wait_definition_expression: expr TICKS  */
#line 668 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3890 "src-generated/ugbc.tab.c"
    break;

  case 173: /* wait_definition_expression: expr milliseconds  */
#line 671 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3898 "src-generated/ugbc.tab.c"
    break;

  case 176: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 681 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3906 "src-generated/ugbc.tab.c"
    break;

  case 177: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 684 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3914 "src-generated/ugbc.tab.c"
    break;

  case 178: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 687 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3922 "src-generated/ugbc.tab.c"
    break;

  case 179: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 690 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3930 "src-generated/ugbc.tab.c"
    break;

  case 180: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 693 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3938 "src-generated/ugbc.tab.c"
    break;

  case 181: /* sprite_definition_simple: direct_integer ENABLE  */
#line 696 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3946 "src-generated/ugbc.tab.c"
    break;

  case 182: /* sprite_definition_simple: direct_integer DISABLE  */
#line 699 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3954 "src-generated/ugbc.tab.c"
    break;

  case 183: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 702 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3962 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 705 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3970 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 708 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3978 "src-generated/ugbc.tab.c"
    break;

  case 186: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 711 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3986 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 714 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3994 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 717 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4002 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 720 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4010 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 723 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4018 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_expression: expr DATA FROM expr  */
#line 728 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4026 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_expression: expr MULTICOLOR  */
#line 731 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4034 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_expression: expr MONOCOLOR  */
#line 734 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4042 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_expression: expr COLOR expr  */
#line 737 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4050 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 740 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4058 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_expression: expr ENABLE  */
#line 743 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4066 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_expression: expr DISABLE  */
#line 746 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4074 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 749 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4082 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 752 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4090 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 755 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4098 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 758 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4106 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 761 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4114 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 764 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4122 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 767 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4130 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 770 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4138 "src-generated/ugbc.tab.c"
    break;

  case 208: /* bitmap_definition_simple: AT direct_integer  */
#line 779 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4146 "src-generated/ugbc.tab.c"
    break;

  case 209: /* bitmap_definition_simple: ENABLE  */
#line 782 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4154 "src-generated/ugbc.tab.c"
    break;

  case 210: /* bitmap_definition_simple: DISABLE  */
#line 785 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4162 "src-generated/ugbc.tab.c"
    break;

  case 211: /* bitmap_definition_simple: CLEAR  */
#line 788 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4170 "src-generated/ugbc.tab.c"
    break;

  case 212: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 791 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4178 "src-generated/ugbc.tab.c"
    break;

  case 213: /* bitmap_definition_expression: AT expr  */
#line 797 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4186 "src-generated/ugbc.tab.c"
    break;

  case 214: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 800 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4194 "src-generated/ugbc.tab.c"
    break;

  case 217: /* textmap_definition_simple: AT direct_integer  */
#line 810 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4202 "src-generated/ugbc.tab.c"
    break;

  case 218: /* textmap_definition_expression: AT expr  */
#line 815 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4210 "src-generated/ugbc.tab.c"
    break;

  case 221: /* text_definition_simple: ENABLE  */
#line 824 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4218 "src-generated/ugbc.tab.c"
    break;

  case 222: /* text_definition_simple: DISABLE  */
#line 827 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4226 "src-generated/ugbc.tab.c"
    break;

  case 223: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 832 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4234 "src-generated/ugbc.tab.c"
    break;

  case 224: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 835 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4242 "src-generated/ugbc.tab.c"
    break;

  case 227: /* tiles_definition_simple: AT direct_integer  */
#line 844 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4250 "src-generated/ugbc.tab.c"
    break;

  case 228: /* tiles_definition_expression: AT expr  */
#line 849 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4258 "src-generated/ugbc.tab.c"
    break;

  case 231: /* colormap_definition_simple: AT direct_integer  */
#line 858 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4266 "src-generated/ugbc.tab.c"
    break;

  case 232: /* colormap_definition_simple: CLEAR  */
#line 861 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4274 "src-generated/ugbc.tab.c"
    break;

  case 233: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 864 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4282 "src-generated/ugbc.tab.c"
    break;

  case 234: /* colormap_definition_expression: AT expr  */
#line 869 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4290 "src-generated/ugbc.tab.c"
    break;

  case 235: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 872 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4298 "src-generated/ugbc.tab.c"
    break;

  case 238: /* screen_definition_simple: ON  */
#line 882 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4306 "src-generated/ugbc.tab.c"
    break;

  case 239: /* screen_definition_simple: OFF  */
#line 885 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4314 "src-generated/ugbc.tab.c"
    break;

  case 240: /* screen_definition_simple: ROWS direct_integer  */
#line 888 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4322 "src-generated/ugbc.tab.c"
    break;

  case 241: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 891 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4330 "src-generated/ugbc.tab.c"
    break;

  case 242: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 894 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4338 "src-generated/ugbc.tab.c"
    break;

  case 243: /* screen_definition_expression: ROWS expr  */
#line 899 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4346 "src-generated/ugbc.tab.c"
    break;

  case 244: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 902 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4354 "src-generated/ugbc.tab.c"
    break;

  case 245: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 905 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4362 "src-generated/ugbc.tab.c"
    break;

  case 249: /* var_definition_simple: Identifier ON Identifier  */
#line 914 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4370 "src-generated/ugbc.tab.c"
    break;

  case 250: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 917 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4378 "src-generated/ugbc.tab.c"
    break;

  case 251: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 920 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4386 "src-generated/ugbc.tab.c"
    break;

  case 252: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 923 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4396 "src-generated/ugbc.tab.c"
    break;

  case 253: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 928 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4406 "src-generated/ugbc.tab.c"
    break;

  case 254: /* goto_definition: Identifier  */
#line 935 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4414 "src-generated/ugbc.tab.c"
    break;

  case 255: /* goto_definition: Integer  */
#line 938 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4422 "src-generated/ugbc.tab.c"
    break;

  case 256: /* gosub_definition: Identifier  */
#line 944 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4430 "src-generated/ugbc.tab.c"
    break;

  case 257: /* gosub_definition: Integer  */
#line 947 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4438 "src-generated/ugbc.tab.c"
    break;

  case 259: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 956 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4446 "src-generated/ugbc.tab.c"
    break;

  case 260: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 962 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4454 "src-generated/ugbc.tab.c"
    break;

  case 263: /* ink_definition: expr  */
#line 971 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4462 "src-generated/ugbc.tab.c"
    break;

  case 264: /* on_goto_definition: Identifier  */
#line 976 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4471 "src-generated/ugbc.tab.c"
    break;

  case 265: /* $@4: %empty  */
#line 980 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4479 "src-generated/ugbc.tab.c"
    break;

  case 267: /* on_gosub_definition: Identifier  */
#line 985 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4488 "src-generated/ugbc.tab.c"
    break;

  case 268: /* $@5: %empty  */
#line 989 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4496 "src-generated/ugbc.tab.c"
    break;

  case 270: /* on_proc_definition: Identifier  */
#line 994 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4505 "src-generated/ugbc.tab.c"
    break;

  case 271: /* $@6: %empty  */
#line 998 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4513 "src-generated/ugbc.tab.c"
    break;

  case 273: /* $@7: %empty  */
#line 1003 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4521 "src-generated/ugbc.tab.c"
    break;

  case 275: /* $@8: %empty  */
#line 1006 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4529 "src-generated/ugbc.tab.c"
    break;

  case 277: /* $@9: %empty  */
#line 1009 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4537 "src-generated/ugbc.tab.c"
    break;

  case 279: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1014 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4545 "src-generated/ugbc.tab.c"
    break;

  case 280: /* every_definition: ON  */
#line 1017 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4553 "src-generated/ugbc.tab.c"
    break;

  case 281: /* every_definition: OFF  */
#line 1020 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4561 "src-generated/ugbc.tab.c"
    break;

  case 282: /* add_definition: Identifier COMMA expr  */
#line 1025 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4569 "src-generated/ugbc.tab.c"
    break;

  case 283: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1028 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4577 "src-generated/ugbc.tab.c"
    break;

  case 284: /* dimensions: Integer  */
#line 1034 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4586 "src-generated/ugbc.tab.c"
    break;

  case 285: /* dimensions: Integer COMMA dimensions  */
#line 1038 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4595 "src-generated/ugbc.tab.c"
    break;

  case 286: /* datatype: BYTE  */
#line 1045 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 4603 "src-generated/ugbc.tab.c"
    break;

  case 287: /* datatype: SIGNED BYTE  */
#line 1048 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 4611 "src-generated/ugbc.tab.c"
    break;

  case 288: /* datatype: WORD  */
#line 1051 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 4619 "src-generated/ugbc.tab.c"
    break;

  case 289: /* datatype: SIGNED WORD  */
#line 1054 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 4627 "src-generated/ugbc.tab.c"
    break;

  case 290: /* datatype: DWORD  */
#line 1057 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 4635 "src-generated/ugbc.tab.c"
    break;

  case 291: /* datatype: SIGNED DWORD  */
#line 1060 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 4643 "src-generated/ugbc.tab.c"
    break;

  case 292: /* datatype: ADDRESS  */
#line 1063 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 4651 "src-generated/ugbc.tab.c"
    break;

  case 293: /* datatype: POSITION  */
#line 1066 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 4659 "src-generated/ugbc.tab.c"
    break;

  case 294: /* datatype: COLOR  */
#line 1069 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 4667 "src-generated/ugbc.tab.c"
    break;

  case 295: /* datatype: STRING  */
#line 1072 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 4675 "src-generated/ugbc.tab.c"
    break;

  case 296: /* $@10: %empty  */
#line 1077 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4684 "src-generated/ugbc.tab.c"
    break;

  case 297: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1080 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 4694 "src-generated/ugbc.tab.c"
    break;

  case 298: /* $@11: %empty  */
#line 1085 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4703 "src-generated/ugbc.tab.c"
    break;

  case 299: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1088 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 4713 "src-generated/ugbc.tab.c"
    break;

  case 300: /* $@12: %empty  */
#line 1093 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4722 "src-generated/ugbc.tab.c"
    break;

  case 301: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1096 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 4732 "src-generated/ugbc.tab.c"
    break;

  case 304: /* indexes: expr  */
#line 1109 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4741 "src-generated/ugbc.tab.c"
    break;

  case 305: /* indexes: expr COMMA indexes  */
#line 1113 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4750 "src-generated/ugbc.tab.c"
    break;

  case 306: /* parameters: Identifier  */
#line 1120 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4760 "src-generated/ugbc.tab.c"
    break;

  case 307: /* parameters: Identifier DOLLAR  */
#line 1125 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4770 "src-generated/ugbc.tab.c"
    break;

  case 308: /* parameters: Identifier AS datatype  */
#line 1130 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4780 "src-generated/ugbc.tab.c"
    break;

  case 309: /* parameters: Identifier COMMA parameters  */
#line 1135 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4790 "src-generated/ugbc.tab.c"
    break;

  case 310: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1140 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4800 "src-generated/ugbc.tab.c"
    break;

  case 311: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1145 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4810 "src-generated/ugbc.tab.c"
    break;

  case 312: /* parameters_expr: Identifier  */
#line 1153 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4820 "src-generated/ugbc.tab.c"
    break;

  case 313: /* parameters_expr: Identifier DOLLAR  */
#line 1158 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4830 "src-generated/ugbc.tab.c"
    break;

  case 314: /* parameters_expr: Identifier AS datatype  */
#line 1163 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4840 "src-generated/ugbc.tab.c"
    break;

  case 315: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1168 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4850 "src-generated/ugbc.tab.c"
    break;

  case 316: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1173 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4860 "src-generated/ugbc.tab.c"
    break;

  case 317: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1178 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4870 "src-generated/ugbc.tab.c"
    break;

  case 318: /* parameters_expr: String  */
#line 1183 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4879 "src-generated/ugbc.tab.c"
    break;

  case 319: /* parameters_expr: String COMMA parameters_expr  */
#line 1187 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4888 "src-generated/ugbc.tab.c"
    break;

  case 320: /* values: expr  */
#line 1194 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4897 "src-generated/ugbc.tab.c"
    break;

  case 321: /* values: expr COMMA values  */
#line 1198 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4906 "src-generated/ugbc.tab.c"
    break;

  case 322: /* print_definition: expr  */
#line 1205 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 4914 "src-generated/ugbc.tab.c"
    break;

  case 323: /* print_definition: expr COMMA  */
#line 1208 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 4923 "src-generated/ugbc.tab.c"
    break;

  case 324: /* print_definition: expr SEMICOLON  */
#line 1212 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 4931 "src-generated/ugbc.tab.c"
    break;

  case 325: /* $@13: %empty  */
#line 1215 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 4940 "src-generated/ugbc.tab.c"
    break;

  case 327: /* $@14: %empty  */
#line 1219 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 4948 "src-generated/ugbc.tab.c"
    break;

  case 346: /* statement: INC Identifier  */
#line 1242 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 4956 "src-generated/ugbc.tab.c"
    break;

  case 347: /* statement: DEC Identifier  */
#line 1245 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 4964 "src-generated/ugbc.tab.c"
    break;

  case 348: /* statement: RANDOMIZE  */
#line 1248 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 4972 "src-generated/ugbc.tab.c"
    break;

  case 349: /* statement: RANDOMIZE expr  */
#line 1251 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 4980 "src-generated/ugbc.tab.c"
    break;

  case 350: /* statement: IF expr THEN  */
#line 1254 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4988 "src-generated/ugbc.tab.c"
    break;

  case 351: /* statement: ELSE  */
#line 1257 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 4996 "src-generated/ugbc.tab.c"
    break;

  case 352: /* statement: ELSE IF expr THEN  */
#line 1260 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5004 "src-generated/ugbc.tab.c"
    break;

  case 353: /* statement: ENDIF  */
#line 1263 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5012 "src-generated/ugbc.tab.c"
    break;

  case 354: /* statement: DO  */
#line 1266 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5020 "src-generated/ugbc.tab.c"
    break;

  case 355: /* statement: LOOP  */
#line 1269 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5028 "src-generated/ugbc.tab.c"
    break;

  case 356: /* $@15: %empty  */
#line 1272 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5036 "src-generated/ugbc.tab.c"
    break;

  case 357: /* statement: WHILE $@15 expr  */
#line 1274 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5044 "src-generated/ugbc.tab.c"
    break;

  case 358: /* statement: WEND  */
#line 1277 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5052 "src-generated/ugbc.tab.c"
    break;

  case 359: /* statement: REPEAT  */
#line 1280 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5060 "src-generated/ugbc.tab.c"
    break;

  case 360: /* statement: UNTIL expr  */
#line 1283 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5068 "src-generated/ugbc.tab.c"
    break;

  case 361: /* statement: EXIT  */
#line 1286 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5076 "src-generated/ugbc.tab.c"
    break;

  case 362: /* statement: EXIT PROC  */
#line 1289 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5084 "src-generated/ugbc.tab.c"
    break;

  case 363: /* statement: POP PROC  */
#line 1292 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5092 "src-generated/ugbc.tab.c"
    break;

  case 364: /* statement: EXIT IF expr  */
#line 1295 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5100 "src-generated/ugbc.tab.c"
    break;

  case 365: /* statement: EXIT Integer  */
#line 1298 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5108 "src-generated/ugbc.tab.c"
    break;

  case 366: /* statement: EXIT direct_integer  */
#line 1301 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5116 "src-generated/ugbc.tab.c"
    break;

  case 367: /* statement: EXIT IF expr COMMA Integer  */
#line 1304 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5124 "src-generated/ugbc.tab.c"
    break;

  case 368: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1307 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5132 "src-generated/ugbc.tab.c"
    break;

  case 369: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1310 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5140 "src-generated/ugbc.tab.c"
    break;

  case 370: /* statement: NEXT  */
#line 1313 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5148 "src-generated/ugbc.tab.c"
    break;

  case 371: /* statement: PROCEDURE Identifier  */
#line 1316 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5157 "src-generated/ugbc.tab.c"
    break;

  case 372: /* $@16: %empty  */
#line 1320 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5165 "src-generated/ugbc.tab.c"
    break;

  case 373: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1322 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5173 "src-generated/ugbc.tab.c"
    break;

  case 374: /* statement: SHARED parameters_expr  */
#line 1325 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5181 "src-generated/ugbc.tab.c"
    break;

  case 375: /* statement: GLOBAL parameters_expr  */
#line 1328 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5189 "src-generated/ugbc.tab.c"
    break;

  case 376: /* statement: END PROC  */
#line 1331 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 5197 "src-generated/ugbc.tab.c"
    break;

  case 377: /* statement: END PROC OSP expr CSP  */
#line 1334 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5205 "src-generated/ugbc.tab.c"
    break;

  case 378: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1337 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5213 "src-generated/ugbc.tab.c"
    break;

  case 379: /* statement: Identifier " "  */
#line 1340 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5222 "src-generated/ugbc.tab.c"
    break;

  case 380: /* statement: PROC Identifier  */
#line 1344 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5231 "src-generated/ugbc.tab.c"
    break;

  case 381: /* statement: CALL Identifier  */
#line 1348 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5240 "src-generated/ugbc.tab.c"
    break;

  case 382: /* $@17: %empty  */
#line 1352 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5248 "src-generated/ugbc.tab.c"
    break;

  case 383: /* statement: Identifier OSP $@17 values CSP  */
#line 1354 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5256 "src-generated/ugbc.tab.c"
    break;

  case 384: /* $@18: %empty  */
#line 1357 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5264 "src-generated/ugbc.tab.c"
    break;

  case 385: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1359 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5272 "src-generated/ugbc.tab.c"
    break;

  case 386: /* $@19: %empty  */
#line 1362 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5280 "src-generated/ugbc.tab.c"
    break;

  case 387: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1364 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5288 "src-generated/ugbc.tab.c"
    break;

  case 388: /* statement: PEN expr  */
#line 1367 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 5296 "src-generated/ugbc.tab.c"
    break;

  case 389: /* statement: Identifier COLON  */
#line 1370 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 5304 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: BEG GAMELOOP  */
#line 1373 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 5312 "src-generated/ugbc.tab.c"
    break;

  case 391: /* statement: END GAMELOOP  */
#line 1376 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 5320 "src-generated/ugbc.tab.c"
    break;

  case 392: /* statement: GRAPHIC  */
#line 1379 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 5328 "src-generated/ugbc.tab.c"
    break;

  case 393: /* statement: HALT  */
#line 1382 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 5336 "src-generated/ugbc.tab.c"
    break;

  case 394: /* statement: END  */
#line 1385 "src/ugbc.y"
        {
      end( _environment );
  }
#line 5344 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: RETURN  */
#line 1392 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 5352 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: RETURN expr  */
#line 1395 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 5360 "src-generated/ugbc.tab.c"
    break;

  case 401: /* statement: POP  */
#line 1398 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 5368 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: DONE  */
#line 1401 "src/ugbc.y"
          {
      return 0;
  }
#line 5376 "src-generated/ugbc.tab.c"
    break;

  case 403: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1404 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5384 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1407 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5392 "src-generated/ugbc.tab.c"
    break;

  case 405: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1410 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 5400 "src-generated/ugbc.tab.c"
    break;

  case 406: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1413 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5408 "src-generated/ugbc.tab.c"
    break;

  case 408: /* statement: Identifier ASSIGN expr  */
#line 1417 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 5422 "src-generated/ugbc.tab.c"
    break;

  case 409: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1426 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 5436 "src-generated/ugbc.tab.c"
    break;

  case 410: /* $@20: %empty  */
#line 1435 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5445 "src-generated/ugbc.tab.c"
    break;

  case 411: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1439 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 5458 "src-generated/ugbc.tab.c"
    break;

  case 412: /* $@21: %empty  */
#line 1447 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5467 "src-generated/ugbc.tab.c"
    break;

  case 413: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1450 "src/ugbc.y"
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
#line 5486 "src-generated/ugbc.tab.c"
    break;

  case 414: /* $@22: %empty  */
#line 1464 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5495 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1467 "src/ugbc.y"
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
#line 5514 "src-generated/ugbc.tab.c"
    break;

  case 416: /* statement: DEBUG expr  */
#line 1481 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 5522 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statements_no_linenumbers: statement  */
#line 1489 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 5528 "src-generated/ugbc.tab.c"
    break;

  case 420: /* $@23: %empty  */
#line 1490 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 5534 "src-generated/ugbc.tab.c"
    break;

  case 422: /* $@24: %empty  */
#line 1494 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 5542 "src-generated/ugbc.tab.c"
    break;

  case 423: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1496 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 5550 "src-generated/ugbc.tab.c"
    break;

  case 424: /* $@25: %empty  */
#line 1501 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 5558 "src-generated/ugbc.tab.c"
    break;

  case 430: /* $@26: %empty  */
#line 1511 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 5564 "src-generated/ugbc.tab.c"
    break;


#line 5568 "src-generated/ugbc.tab.c"

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

#line 1513 "src/ugbc.y"


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

