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
#define YYLAST   2068

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  183
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  103
/* YYNRULES -- Number of rules.  */
#define YYNRULES  430
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  832

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
    1373,  1376,  1379,  1382,  1385,  1386,  1387,  1388,  1389,  1392,
    1395,  1398,  1401,  1404,  1407,  1410,  1413,  1414,  1423,  1432,
    1432,  1444,  1444,  1461,  1461,  1478,  1481,  1482,  1486,  1487,
    1487,  1491,  1491,  1498,  1498,  1501,  1502,  1503,  1504,  1508,
    1508
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

#define YYPACT_NINF (-719)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-410)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -719,    88,   780,  -719,  -719,  -169,  -137,    -9,  -719,    37,
    1482,    53,     5,  1482,  -719,    29,   176,  1617,   -84,   -67,
    -719,  -719,  -719,  1187,   106,    17,  1617,    46,   -55,  -719,
     140,   157,  1617,  1617,  -719,   124,   173,   -15,  1617,    65,
     146,  -719,   -23,  -719,  1617,    48,  1347,   205,    70,  1617,
      74,    90,    91,    92,  -122,  -122,  1617,    13,  -719,   227,
     242,   261,  -719,  -719,  -719,  1482,   251,  -719,  -719,  -719,
    1482,  1482,  1482,  -719,  -719,  -719,    95,  1027,  -719,  -719,
     243,   244,   246,   167,   100,  -719,  -719,   248,   249,  1617,
    -719,  -719,   250,   253,   272,   273,   274,   275,   276,   279,
     280,   281,   282,   284,   286,   288,   292,   295,   296,  -719,
    -719,   297,    97,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
     160,  -719,  -719,    86,   -69,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,   172,    10,  -719,  -719,    -8,   220,
     206,   184,   208,    61,  -719,  -719,  -719,  -719,  -719,    -6,
     256,    -4,    -3,     1,     3,   321,  -719,  -719,  -719,   287,
     303,  -719,  -719,  -719,  1482,  -719,  -719,   317,  -719,  -719,
    -719,  -719,  -719,  1482,   301,   308,  -719,  -719,  -719,   -21,
    -719,    54,  -719,  -719,  -719,  -719,  -719,  1617,  1617,  -719,
    -719,   348,  -719,  -719,  -719,  1482,  -719,  -719,  -719,  1482,
     327,  -719,  -719,  -719,   293,  -719,  -719,   214,  1617,  1617,
    -719,  -719,  1482,  -719,  -719,  -719,   330,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  1617,  1617,  -719,  -719,  -719,
    -719,   352,  -719,  -719,   215,  -719,  1617,   359,  -719,  -719,
    -719,    44,   371,  -719,   233,   234,   235,    36,   377,  -719,
    -719,   181,  -719,  -719,  -719,  1617,   376,  -719,  -719,   356,
      26,   927,  -719,   780,   780,   362,   363,  1482,  -719,  -719,
     322,   324,   325,   326,  -719,   358,   364,   366,   368,   369,
      12,   370,  1482,  1482,  1482,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  1617,  1617,  -719,  1617,  1617,
    1617,  1617,  1617,  1617,  1617,  1617,  1617,  1617,  1617,  1617,
    1617,  1617,  1617,  1617,  1617,  1752,   372,   229,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,   375,  -719,   378,  -719,
    -719,  -719,  -719,  -719,  -719,  1752,  1752,  1752,  1752,  1752,
    1752,  1752,  1752,  1752,  1752,  1752,  1752,  1752,  1887,  -719,
    -719,  -719,  1482,   387,  -719,  -719,  -719,   367,   256,   390,
     256,   392,   256,   393,   256,   394,   256,  -719,  1617,   388,
    -719,  -719,   166,   168,   101,   114,  -719,  -719,  -719,   386,
     256,   389,  -719,  -719,   199,   202,   117,   127,  -719,  -719,
     396,  -719,  -719,  1482,  -719,  -719,  1482,  1482,  -719,  -719,
    -719,   381,   245,  -719,   419,  1617,  -719,  -719,  -719,  -719,
    1482,  -719,  1617,   421,   425,  -719,  -719,  1482,   365,   428,
    1617,   334,   431,  1617,  -719,  -719,  -719,  -719,  -719,  -719,
      60,  -719,  -719,   406,   422,    74,  -719,   294,  -719,  -122,
     436,    26,  -122,   190,   204,   780,  -719,  1617,   410,  1617,
    1617,   411,    18,  -719,   927,  -719,  -719,   267,   269,  -719,
    -719,  1617,   256,  1617,   256,   268,   271,   277,   278,   285,
     415,   420,   426,  -719,   427,   430,   432,   433,   434,   435,
     447,   449,   450,   464,   437,   438,   439,   440,   469,   443,
     444,   445,   446,   448,   475,   478,   451,   452,   453,    -2,
     310,   455,   457,  1617,  1617,   206,   206,   252,   252,   252,
     252,   252,   252,   252,   252,   184,   208,   208,  -719,   463,
     465,  1482,    73,  -719,   256,  -719,   256,  -719,   256,  -719,
     256,    62,  -719,  1617,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  1617,  -719,   256,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,   256,  -719,  -719,  -719,  -719,  -719,  -719,
     316,   318,   319,   320,   483,  1617,   493,   459,   461,   357,
    1617,  1617,   497,   499,  -719,   -68,   441,   328,  1617,   501,
    -719,  -719,  -719,   476,   331,   480,  -719,  1617,   336,  1617,
    -719,  -122,   502,  -719,  1617,  1617,  -719,  -719,  1617,   509,
     373,   510,   484,  1617,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,   337,   339,   341,  -719,
    -719,  -719,  -719,  -719,  -719,  1617,  1617,  1617,  1617,  -719,
    -719,  -719,  -719,  1617,  -719,  -719,  -719,  -719,  -719,  1617,
    1617,  -719,  -719,  -719,  1887,   489,  -719,  1617,   379,   490,
     347,   349,  -719,  -719,  -719,  -719,  -719,  -719,   504,  -719,
     505,  -719,   350,    75,  -719,   528,  -719,   529,   531,  -719,
     532,  -719,   533,  -719,   530,  1482,   534,  1617,  1617,   256,
    -719,   507,   511,  1617,   256,  -719,  -719,  1617,  -719,    41,
    1617,   331,   537,   512,   331,   397,   108,   400,   401,  -719,
    -122,  -719,  -719,   515,  1617,  -719,  1617,   538,   517,  -719,
    -719,  -719,   518,   519,    42,    43,   521,   522,   523,   524,
    -719,   527,  -719,  -719,  -719,  -719,   383,   384,  -719,   536,
    -719,   540,  -719,  1617,   256,   559,   560,   563,  1617,  -719,
    -719,  1617,  -719,  -719,  -719,   558,   561,   541,   543,   458,
    1617,   562,   500,   545,   331,  -719,   546,  -719,   336,   575,
      26,  -719,  -719,  -719,   570,  -719,  -719,  1617,   573,  -719,
    -719,  1617,  -719,  1617,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,   407,   409,   555,   557,   316,   318,   319,  -719,
    -719,  1617,  1617,  -719,  -719,  1617,   564,  1617,  1617,  -719,
    -719,  -719,  -719,   336,   587,  1617,  -719,  1617,   565,   566,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
     583,  -719,  -719,  -719,   336,  -719,  -719,  -719,  -719,  1617,
    -719,  -719
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     429,     0,   417,     1,   416,     0,     0,     0,   401,     0,
       0,   370,     0,     0,   392,     0,     0,     0,   248,     0,
     355,   359,   356,     0,     0,     0,     0,     0,   393,   353,
       0,     0,     0,   348,   391,     0,     0,     0,   398,   400,
     351,   354,   361,   358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   413,   421,   418,
     425,   427,   430,   346,   347,     0,     0,   149,   150,   330,
       0,     0,     0,   163,   164,   332,     0,     0,    79,    80,
       0,     0,     0,     0,     0,   115,   116,     0,     0,     0,
     112,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     117,     0,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,    44,    49,    50,    51,    52,
      53,    54,    57,    58,     0,    63,    67,    65,     0,     2,
      12,    15,    17,     0,    76,    20,   174,   175,   333,     0,
       0,     0,     0,     0,     0,     0,   143,   144,   329,     0,
       0,   206,   207,   334,     0,   209,   210,   211,   215,   216,
     335,   238,   239,     0,     0,     0,   246,   247,   340,     0,
     394,     0,   258,   343,   254,   255,   395,     0,     0,   221,
     222,     0,   225,   226,   337,     0,   229,   230,   338,     0,
     232,   236,   237,   339,     0,   389,   390,   376,     0,     0,
     415,   349,     0,   219,   220,   336,     0,   261,   262,   341,
     256,   257,   396,   399,   363,     0,     0,   362,   365,   366,
     360,     0,   280,   281,     0,   397,     0,     0,   344,   263,
     342,   296,   302,   406,   380,   371,   381,   312,   318,   374,
     375,   322,   345,   423,   388,     0,   411,   382,   379,     0,
       0,   417,   419,   417,   417,     0,     0,     0,   160,   157,
       0,     0,     0,     0,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    24,    25,    27,    29,
      30,    26,    31,   101,    23,     0,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    42,
      45,    46,    47,    48,    43,    56,    64,   108,     0,   165,
     171,   166,   167,   172,   173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   168,
     169,   170,     0,     0,   155,   156,   331,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   119,     0,     0,
     196,   197,     0,     0,     0,     0,   193,   192,   118,     0,
       0,     0,   181,   182,     0,     0,     0,     0,   178,   177,
       0,   213,   208,     0,   243,   240,     0,     0,   273,   277,
     275,     0,     0,   357,     0,     0,   228,   227,   234,   231,
       0,   350,     0,     0,     0,   218,   217,     0,     0,   364,
       0,     0,     0,     0,   294,   286,   288,   293,   290,   295,
       0,   292,   300,     0,     0,     0,   384,     0,   386,     0,
     313,     0,     0,   327,   325,   417,   407,     0,     0,     0,
       0,     0,   413,   422,   417,   426,   428,     0,     0,   147,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,     5,     7,     8,
       9,    10,     6,     3,     4,    16,    18,    19,    21,     0,
       0,     0,     0,   125,     0,   137,     0,   129,     0,   133,
       0,   121,   194,     0,   201,   200,   205,   204,   199,   203,
     198,   202,     0,   179,     0,   186,   185,   190,   189,   184,
     188,   183,   187,     0,   214,   212,   244,   241,   245,   242,
       0,     0,     0,     0,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   352,     0,     0,     0,     0,   282,
     287,   289,   291,     0,     0,     0,   303,     0,     0,     0,
     315,     0,   314,   319,     0,     0,   424,   408,     0,   320,
       0,   304,     0,     0,   420,   148,   146,   162,   159,   161,
     158,    75,    68,    70,    74,    72,     0,     0,     0,    78,
      77,    82,    81,    84,    83,     0,     0,     0,     0,    91,
      92,    93,   100,     0,    94,    95,    96,    97,    98,     0,
       0,   110,   111,   102,     0,     0,   106,     0,     0,     0,
       0,     0,   153,   151,   122,   135,   127,   130,   124,   136,
     128,   132,     0,     0,   191,     0,   176,     0,   264,   274,
     267,   278,   270,   276,   250,     0,     0,     0,     0,     0,
     377,     0,     0,     0,     0,   367,   368,     0,   279,     0,
       0,     0,   284,     0,     0,     0,   306,     0,     0,   316,
       0,   328,   326,     0,     0,   383,     0,     0,     0,    69,
      71,    73,     0,     0,     0,     0,     0,     0,     0,     0,
     107,     0,   109,    60,   154,   152,     0,     0,   138,   123,
     134,   126,   131,     0,     0,     0,     0,     0,     0,   252,
     251,     0,   224,   235,   233,     0,     0,     0,     0,   369,
       0,     0,     0,     0,     0,   297,     0,   385,     0,   307,
       0,   373,   387,   317,     0,   321,   305,     0,     0,    85,
      86,     0,    87,     0,    89,    99,   105,   104,    22,    62,
     140,   142,     0,     0,     0,     0,     0,     0,     0,   253,
     223,     0,     0,   260,   259,     0,     0,     0,     0,   301,
     285,   299,   309,     0,   308,     0,   410,     0,     0,     0,
     139,   141,   195,   180,   266,   269,   272,   402,   403,   378,
       0,   404,   283,   310,     0,   412,   414,    88,    90,     0,
     311,   405
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -719,   -10,    33,   -72,   257,  -221,    67,  -719,  -719,  -719,
    -339,  -719,  -719,  -719,   454,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,   460,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -188,  -719,  -183,  -719,  -182,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -621,  -258,  -719,  -719,  -719,  -719,   170,  -500,
    -718,   -54,  -497,  -327,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -253,  -719,  -719,  -719,  -252,
    -719,  -719,  -719
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   601,   139,   140,   141,   142,   143,   292,   293,   144,
     145,   328,   502,   503,   379,   156,   157,   158,    67,    68,
      69,   354,   355,   356,    73,    74,    75,   334,   146,   147,
     148,   161,   162,   163,   168,   169,   170,   213,   214,   215,
     192,   193,   194,   196,   197,   198,   201,   202,   203,   176,
     177,   178,   182,   186,   222,   183,   217,   218,   219,   240,
     669,   735,   671,   736,   673,   737,   180,   560,   562,   561,
     235,   238,   693,   432,   242,   433,   434,   583,   243,   602,
     697,   249,   600,   252,   595,   594,    59,   187,   437,   449,
     587,   589,   259,   448,   260,    60,   454,    61,   261,    62,
     445,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     138,   250,   451,   159,   649,   644,   648,   179,   453,   518,
      63,   455,   456,   191,    84,    65,   204,   253,   352,   254,
     358,   360,   210,   211,   254,   362,   255,   364,   223,   150,
     326,   255,   398,   256,   230,   206,   234,   151,   256,   239,
     802,   199,    64,   439,   -59,   226,   251,  -409,   750,   771,
     773,   424,  -409,   164,   152,   265,   440,   247,   248,    84,
     268,   270,   272,    70,  -298,   165,   166,   281,    71,   424,
     753,   329,   330,   756,   401,   149,   751,   772,   774,   297,
     160,   399,   153,   154,   441,   823,   470,   471,     3,   207,
     695,   662,   698,   323,   499,   181,   402,   472,   703,   324,
     425,   426,   427,   708,   200,   654,   830,   729,    72,   229,
     663,   428,   184,   685,   185,   758,   167,   316,   425,   426,
     427,   227,   655,   400,   730,   516,   517,   348,   759,   428,
     195,   317,   266,   800,   580,   581,   205,   269,   271,   273,
     329,   349,   331,   332,   333,   582,   538,   721,   212,   429,
     656,   657,   731,   732,   391,   539,   760,   327,   228,   540,
     257,   430,   549,   394,   220,   257,   221,   429,   541,   431,
      66,   550,   551,   353,   208,   359,   361,   403,   404,   430,
     363,   552,   365,   592,   155,   406,   443,   431,   444,   408,
    -324,   209,   285,   596,  -324,   258,  -324,   216,   413,   414,
     258,   604,   415,   346,  -323,   347,   766,   765,  -323,   224,
    -323,   331,   332,   350,   225,   418,   419,   357,   171,   172,
     173,   174,   534,   535,   536,   537,   422,   231,   335,   336,
     175,   392,   337,   262,   338,   339,   340,   341,   342,   236,
     395,   286,   287,   288,   319,   446,   263,   320,   321,   237,
     289,   290,   291,   241,   322,   545,   546,   459,   547,   548,
     335,   336,   407,   505,   506,   264,   409,   701,   702,   244,
     245,   246,   474,   476,   478,   267,   274,   282,   283,   416,
     284,   294,   295,   296,   298,   480,   481,   299,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   719,   300,   301,   302,   303,
     304,   367,   368,   305,   306,   307,   308,   343,   309,   369,
     310,   318,   311,   370,   371,   344,   312,   367,   380,   313,
     314,   315,   372,   325,   460,   381,   345,   348,    84,   382,
     383,   373,   519,   374,   375,   366,   393,   396,   384,   475,
     477,   479,   376,   377,   397,   405,   410,   385,   532,   386,
     387,   412,   411,   378,   417,   420,   423,   421,   388,   389,
     507,   508,   509,   510,   511,   512,   513,   514,   435,   378,
     436,  -372,   438,   554,   442,   590,   556,   558,   593,   447,
     450,   457,   458,   465,   461,   566,   462,   463,   464,   466,
     567,   467,   569,   468,   469,   473,   500,   572,   501,   -61,
     576,   521,   504,   579,   524,   522,   526,   528,   530,   520,
     542,   533,   544,   563,   564,   523,   565,   525,   570,   527,
     553,   529,   571,   531,   574,   575,   577,   597,   578,   599,
     584,   588,   585,   591,   598,   603,   605,   543,   606,   611,
     616,   607,   612,   609,   625,   617,   626,   627,   613,   614,
     555,   618,   619,   557,   559,   620,   615,   621,   622,   623,
     624,   628,   629,   630,   631,   632,   633,   568,   634,   635,
     636,   637,   639,   638,   573,   640,   641,   642,   643,   645,
     646,   647,   650,   599,   651,   668,   675,   670,   672,   674,
     677,   678,   804,   679,   683,   680,   684,   688,   690,   700,
     691,   652,   692,   687,   694,   696,   704,   706,   709,   707,
     710,   705,   711,   664,   720,   723,   724,   722,   725,   608,
     728,   610,   665,   726,   727,   733,   734,   699,  -265,  -268,
    -271,   741,   745,   738,   754,   757,   746,   755,   761,   762,
     764,   767,   768,   769,   770,   676,   775,   776,   777,   778,
     681,   682,   779,   780,   781,   782,   786,   787,   689,   783,
     788,   791,   798,   795,   792,   797,   793,   599,   794,   599,
     799,   801,   803,   805,   251,   251,   807,   810,   653,   811,
     812,   658,   813,   659,   824,   660,   829,   661,   814,   820,
     827,   828,   515,   351,   815,   586,   816,     0,     0,     0,
       0,   666,     0,     0,   390,   712,   713,   714,   715,     0,
     667,     0,     0,   716,     0,     0,     0,     0,     0,   717,
     718,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   686,     0,     0,     0,   763,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   739,     0,   742,   743,     0,
       0,     0,     0,   747,     0,     0,     0,   749,     0,     0,
     752,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   784,     0,     0,     0,     0,   789,     0,
       0,   790,     0,     0,     0,     0,     0,     0,     0,     0,
     796,     0,   740,     0,     0,     0,   744,     0,     0,     0,
       0,   748,     0,     0,     0,     0,     0,   806,     0,     0,
       0,   808,     0,   809,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   817,   818,     4,     0,   819,     0,   821,   822,     0,
       5,     6,     0,     0,     0,   825,     0,   826,     0,     0,
       0,   785,     7,     8,     0,     9,     0,    10,    11,     0,
      12,    13,     0,     0,     0,     0,     0,     0,    14,   831,
      15,    16,    17,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
       0,    29,     0,     0,    30,    31,    32,     0,    33,    34,
      35,    36,    37,    38,    39,     0,    40,     0,     0,     0,
      41,    42,    43,    44,    45,     0,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,    49,
       0,     0,    50,     0,    51,    52,    53,     0,     0,    54,
       4,     0,     0,    55,     0,    56,     0,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     9,     0,    10,    11,     0,    12,    13,    57,
       0,    58,     0,     0,     0,    14,     0,    15,    16,    17,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    28,     0,    29,     0,
       0,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,     0,    40,     0,     0,    76,    41,    42,    43,
      44,    45,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,   275,     0,     0,     0,     0,     0,    48,     0,
       0,    77,     0,     0,     0,     0,    49,     0,     0,    50,
       0,    51,    52,    53,     0,     0,    54,    78,    79,    80,
      55,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,    82,     0,     0,
      83,   276,   277,   278,     0,     0,   452,     0,     0,     0,
      85,    86,   279,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   106,   280,   107,   108,   109,     0,   110,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    76,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,     0,
       0,   188,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,     0,   189,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,    82,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   106,     0,   107,   108,   109,     0,   110,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    76,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,   232,
     233,     0,     0,     0,     0,     0,     0,    78,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,    82,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   106,     0,   107,   108,   109,     0,   110,   111,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    77,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,     0,
       0,     0,    78,    79,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,    82,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      90,    91,     0,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,   104,   105,   106,     0,   107,   108,
     109,     0,   110,   111,     0,     0,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    77,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,    78,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,    82,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   106,     0,   107,   108,   109,     0,   110,   111,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,    77,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,     0,
       0,     0,    78,    79,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,    82,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,     0,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,   104,   105,   106,     0,   107,   108,
     109,     0,   110,   111,     0,     0,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,    77,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,    78,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,    82,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,     0,     0,     0,
       0,     0,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   106,     0,   107,   108,   109,     0,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137
};

static const yytype_int16 yycheck[] =
{
      10,    55,   260,    13,   504,     7,   503,    17,   261,   348,
     179,   263,   264,    23,    82,    24,    26,     4,    24,     6,
      24,    24,    32,    33,     6,    24,    13,    24,    38,    24,
      20,    13,    53,    20,    44,    90,    46,    32,    20,    49,
     758,    24,   179,     7,    34,    68,    56,    34,     7,     7,
       7,    25,    34,    24,    49,    65,    20,   179,   180,    82,
      70,    71,    72,    26,    20,    36,    37,    77,    31,    25,
     691,    79,    80,   694,    20,    22,    35,    35,    35,    89,
      13,   102,    77,    78,    48,   803,    74,    75,     0,   144,
     587,    29,   589,   162,   315,   179,    42,    85,   598,   168,
      74,    75,    76,   603,    87,    32,   824,    32,    71,    42,
      48,    85,   179,   181,   181,     7,    87,    20,    74,    75,
      76,   144,    49,   144,    49,   346,   347,   129,    20,    85,
      24,    34,    65,   754,    74,    75,    90,    70,    71,    72,
      79,    80,   150,   151,   152,    85,    45,   647,    24,   123,
      77,    78,    77,    78,   164,    54,    48,   147,   181,    45,
     147,   135,    45,   173,   179,   147,   181,   123,    54,   143,
     179,    54,    45,   179,    34,   179,   179,   187,   188,   135,
     179,    54,   179,   441,   179,   195,     5,   143,     7,   199,
       0,    34,    25,   445,     4,   182,     6,    24,   208,   209,
     182,   454,   212,    19,     0,    21,   706,   704,     4,   144,
       6,   150,   151,   152,    68,   225,   226,   150,    42,    43,
      44,    45,    56,    57,    56,    57,   236,   179,     8,     9,
      54,   164,    12,     6,    14,    15,    16,    17,    18,    34,
     173,    74,    75,    76,   158,   255,     4,   161,   162,   179,
      83,    84,    85,   179,   168,    56,    57,   267,    56,    57,
       8,     9,   195,   335,   336,     4,   199,   594,   595,   179,
     179,   179,   282,   283,   284,    24,   181,    34,    34,   212,
      34,   181,    34,    34,    34,   295,   296,    34,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   644,    34,    34,    34,    34,
      34,    24,    25,    34,    34,    34,    34,    97,    34,    32,
      34,   161,    34,    36,    37,   105,    34,    24,    25,    34,
      34,    34,    45,   161,   267,    32,   130,   129,    82,    36,
      37,    54,   352,    56,    57,    24,    29,    46,    45,   282,
     283,   284,    65,    66,    46,     7,    29,    54,   368,    56,
      57,   147,    69,    76,    34,    13,     7,   152,    65,    66,
     337,   338,   339,   340,   341,   342,   343,   344,     7,    76,
     147,   147,   147,   393,     7,   439,   396,   397,   442,    13,
      34,    29,    29,    35,    72,   405,    72,    72,    72,    35,
     410,    35,   412,    35,    35,    35,    34,   417,   179,    34,
     420,    24,    34,   423,    24,    48,    24,    24,    24,   352,
      34,    33,    33,    42,   179,   358,     7,   360,     7,   362,
      34,   364,     7,   366,    69,     7,   102,   447,     7,   449,
      34,   147,    20,     7,    34,    34,   179,   380,   179,   181,
      35,   461,   181,   463,     7,    35,     7,     7,   181,   181,
     393,    35,    35,   396,   397,    35,   181,    35,    35,    35,
      35,     7,    35,    35,    35,    35,     7,   410,    35,    35,
      35,    35,     7,    35,   417,     7,    35,    35,    35,   179,
      35,    34,    29,   503,    29,   179,    13,   179,   179,   179,
       7,    42,   760,    42,     7,   148,     7,   179,     7,     7,
      34,   521,   181,    72,    34,   179,     7,     7,   181,    35,
     181,   148,   181,   533,    35,    35,   179,   148,   179,   462,
     180,   464,   542,    29,    29,     7,     7,   591,     7,     7,
       7,     7,    35,    13,     7,   148,    35,    35,   148,   148,
      35,    13,    35,    35,    35,   565,    35,    35,    35,    35,
     570,   571,    35,   180,   180,    29,     7,     7,   578,    29,
       7,    13,    72,   115,    13,    13,    35,   587,    35,   589,
      35,    35,     7,    13,   594,   595,    13,   180,   521,   180,
      35,   524,    35,   526,     7,   528,    13,   530,   786,    35,
      35,    35,   345,   143,   787,   435,   788,    -1,    -1,    -1,
      -1,   544,    -1,    -1,   160,   625,   626,   627,   628,    -1,
     553,    -1,    -1,   633,    -1,    -1,    -1,    -1,    -1,   639,
     640,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   575,    -1,    -1,    -1,   700,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   675,    -1,   677,   678,    -1,
      -1,    -1,    -1,   683,    -1,    -1,    -1,   687,    -1,    -1,
     690,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   704,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   733,    -1,    -1,    -1,    -1,   738,    -1,
      -1,   741,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     750,    -1,   675,    -1,    -1,    -1,   679,    -1,    -1,    -1,
      -1,   684,    -1,    -1,    -1,    -1,    -1,   767,    -1,    -1,
      -1,   771,    -1,   773,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   791,   792,     3,    -1,   795,    -1,   797,   798,    -1,
      10,    11,    -1,    -1,    -1,   805,    -1,   807,    -1,    -1,
      -1,   734,    22,    23,    -1,    25,    -1,    27,    28,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,   829,
      40,    41,    42,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      -1,    91,    -1,    -1,    94,    95,    96,    -1,    98,    99,
     100,   101,   102,   103,   104,    -1,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,    -1,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,    -1,   144,   145,   146,    -1,    -1,   149,
       3,    -1,    -1,   153,    -1,   155,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    -1,    25,    -1,    27,    28,    -1,    30,    31,   179,
      -1,   181,    -1,    -1,    -1,    38,    -1,    40,    41,    42,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,    -1,
      -1,    94,    95,    96,    -1,    98,    99,   100,   101,   102,
     103,   104,    -1,   106,    -1,    -1,     9,   110,   111,   112,
     113,   114,    -1,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    34,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,
      -1,   144,   145,   146,    -1,    -1,   149,    50,    51,    52,
     153,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    74,    75,    76,    -1,    -1,   179,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,   137,   138,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     9,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,     9,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     133,   134,    -1,   136,   137,   138,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   284,   285,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    88,    89,    91,
      94,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     106,   110,   111,   112,   113,   114,   116,   117,   131,   139,
     142,   144,   145,   146,   149,   153,   155,   179,   181,   269,
     278,   280,   282,   179,   179,    24,   179,   201,   202,   203,
      26,    31,    71,   207,   208,   209,     9,    34,    50,    51,
      52,    67,    70,    73,    82,    83,    84,    94,    95,   107,
     108,   109,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   132,   133,   134,   136,   137,   138,
     140,   141,   154,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   184,   185,
     186,   187,   188,   189,   192,   193,   211,   212,   213,    22,
      24,    32,    49,    77,    78,   179,   198,   199,   200,   184,
     189,   214,   215,   216,    24,    36,    37,    87,   217,   218,
     219,    42,    43,    44,    45,    54,   232,   233,   234,   184,
     249,   179,   235,   238,   179,   181,   236,   270,    24,    36,
      37,   184,   223,   224,   225,    24,   226,   227,   228,    24,
      87,   229,   230,   231,   184,    90,    90,   144,    34,    34,
     184,   184,    24,   220,   221,   222,    24,   239,   240,   241,
     179,   181,   237,   184,   144,    68,    68,   144,   181,   189,
     184,   179,    42,    43,   184,   253,    34,   179,   254,   184,
     242,   179,   257,   261,   179,   179,   179,   179,   180,   264,
     264,   184,   266,     4,     6,    13,    20,   147,   182,   275,
     277,   281,     6,     4,     4,   184,   189,    24,   184,   189,
     184,   189,   184,   189,   181,    25,    74,    75,    76,    85,
     135,   184,    34,    34,    34,    25,    74,    75,    76,    83,
      84,    85,   190,   191,   181,    34,    34,   184,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    20,    34,   161,   158,
     161,   162,   168,   162,   168,   161,    20,   147,   194,    79,
      80,   150,   151,   152,   210,     8,     9,    12,    14,    15,
      16,    17,    18,    97,   105,   130,    19,    21,   129,    80,
     152,   210,    24,   179,   204,   205,   206,   189,    24,   179,
      24,   179,    24,   179,    24,   179,    24,    24,    25,    32,
      36,    37,    45,    54,    56,    57,    65,    66,    76,   197,
      25,    32,    36,    37,    45,    54,    56,    57,    65,    66,
     197,   184,   189,    29,   184,   189,    46,    46,    53,   102,
     144,    20,    42,   184,   184,     7,   184,   189,   184,   189,
      29,    69,   147,   184,   184,   184,   189,    34,   184,   184,
      13,   152,   184,     7,    25,    74,    75,    76,    85,   123,
     135,   143,   256,   258,   259,     7,   147,   271,   147,     7,
      20,    48,     7,     5,     7,   283,   184,    13,   276,   272,
      34,   256,   179,   278,   279,   282,   282,    29,    29,   184,
     189,    72,    72,    72,    72,    35,    35,    35,    35,    35,
      74,    75,    85,    35,   184,   189,   184,   189,   184,   189,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   188,
      34,   179,   195,   196,    34,   186,   186,   185,   185,   185,
     185,   185,   185,   185,   185,   187,   188,   188,   193,   184,
     189,    24,    48,   189,    24,   189,    24,   189,    24,   189,
      24,   189,   184,    33,    56,    57,    56,    57,    45,    54,
      45,    54,    34,   189,    33,    56,    57,    56,    57,    45,
      54,    45,    54,    34,   184,   189,   184,   189,   184,   189,
     250,   252,   251,    42,   179,     7,   184,   184,   189,   184,
       7,     7,   184,   189,    69,     7,   184,   102,     7,   184,
      74,    75,    85,   260,    34,    20,   261,   273,   147,   274,
     264,     7,   256,   264,   268,   267,   282,   184,    34,   184,
     265,   184,   262,    34,   278,   179,   179,   184,   189,   184,
     189,   181,   181,   181,   181,   181,    35,    35,    35,    35,
      35,    35,    35,    35,    35,     7,     7,     7,     7,    35,
      35,    35,    35,     7,    35,    35,    35,    35,    35,     7,
       7,    35,    35,    35,     7,   179,    35,    34,   265,   262,
      29,    29,   184,   189,    32,    49,    77,    78,   189,   189,
     189,   189,    29,    48,   184,   184,   189,   189,   179,   243,
     179,   245,   179,   247,   179,    13,   184,     7,    42,    42,
     148,   184,   184,     7,     7,   181,   189,    72,   179,   184,
       7,    34,   181,   255,    34,   265,   179,   263,   265,   264,
       7,   266,   266,   262,     7,   148,     7,    35,   262,   181,
     181,   181,   184,   184,   184,   184,   184,   184,   184,   193,
      35,   262,   148,    35,   179,   179,    29,    29,   180,    32,
      49,    77,    78,     7,     7,   244,   246,   248,    13,   184,
     189,     7,   184,   184,   189,    35,    35,   184,   189,   184,
       7,    35,   184,   255,     7,    35,   255,   148,     7,    20,
      48,   148,   148,   264,    35,   265,   262,    13,    35,    35,
      35,     7,    35,     7,    35,    35,    35,    35,    35,    35,
     180,   180,    29,    29,   184,   189,     7,     7,     7,   184,
     184,    13,    13,    35,    35,   115,   184,    13,    72,    35,
     255,    35,   263,     7,   256,    13,   184,    13,   184,   184,
     180,   180,    35,    35,   243,   245,   247,   184,   184,   184,
      35,   184,   184,   263,     7,   184,   184,    35,    35,    13,
     263,   184
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
     269,   269,   269,   269,   269,   269,   269,   269,   269,   275,
     269,   276,   269,   277,   269,   269,   269,   269,   278,   279,
     278,   281,   280,   283,   282,   282,   282,   282,   282,   285,
     284
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
       2,     1,     1,     1,     2,     2,     2,     2,     1,     2,
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
#line 2614 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 77 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2623 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 81 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2631 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 84 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2639 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 87 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2647 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 90 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2655 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 93 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2663 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 96 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2671 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 99 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2679 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 106 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2687 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 109 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2696 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 122 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2705 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 126 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2714 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 134 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2723 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 138 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 2732 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 145 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2740 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 150 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2748 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 153 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2756 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 156 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2764 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 159 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2772 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 162 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2780 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 165 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2788 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 168 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2796 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 173 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2804 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 178 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2813 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 182 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2822 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 186 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2831 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 190 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2840 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 194 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2849 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 198 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2858 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 202 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2867 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 206 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2876 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 210 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2885 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 214 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2894 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 218 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2903 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 222 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2912 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 226 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2921 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 230 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2930 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 234 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2939 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 238 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2948 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 242 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2957 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 246 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2966 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 250 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2975 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 254 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2984 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 258 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2993 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 262 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3002 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 266 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3011 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 270 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3020 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 274 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3029 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 278 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3038 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 282 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3047 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 288 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3056 "src-generated/ugbc.tab.c"
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
#line 3068 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 299 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3077 "src-generated/ugbc.tab.c"
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
#line 3089 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 310 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3097 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 313 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3105 "src-generated/ugbc.tab.c"
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
#line 3119 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 325 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3128 "src-generated/ugbc.tab.c"
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
#line 3140 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 336 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3149 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 340 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3158 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 344 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3167 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 348 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3176 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 352 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3185 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 356 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3194 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 360 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3203 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 364 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3212 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 368 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3220 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 371 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3228 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 374 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3236 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 377 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3244 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 380 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3252 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 383 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3260 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 386 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3268 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 389 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3276 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 392 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3284 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 395 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3292 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 398 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3300 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 401 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3308 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 404 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3316 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 407 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3324 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 410 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3332 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 413 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3340 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 416 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3348 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 419 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3356 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 422 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3364 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 425 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3372 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 428 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3380 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 431 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3388 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 434 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3396 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 437 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3404 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 440 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3412 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 443 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3420 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 446 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3428 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 449 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3436 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 452 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3444 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 455 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3452 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 458 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3460 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 461 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3468 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 464 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3476 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 466 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3485 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 470 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3493 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 473 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3501 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 476 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3510 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 480 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3519 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 484 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3528 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: WIDTH  */
#line 488 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3536 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: HEIGHT  */
#line 491 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3544 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: TIMER  */
#line 494 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3552 "src-generated/ugbc.tab.c"
    break;

  case 120: /* bank_definition_simple: AT direct_integer  */
#line 502 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3560 "src-generated/ugbc.tab.c"
    break;

  case 121: /* bank_definition_simple: Identifier AT direct_integer  */
#line 505 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3568 "src-generated/ugbc.tab.c"
    break;

  case 122: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 508 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3576 "src-generated/ugbc.tab.c"
    break;

  case 123: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 511 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3584 "src-generated/ugbc.tab.c"
    break;

  case 124: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 514 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3592 "src-generated/ugbc.tab.c"
    break;

  case 125: /* bank_definition_simple: DATA AT direct_integer  */
#line 517 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3600 "src-generated/ugbc.tab.c"
    break;

  case 126: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 521 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3608 "src-generated/ugbc.tab.c"
    break;

  case 127: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 524 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3616 "src-generated/ugbc.tab.c"
    break;

  case 128: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 527 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3624 "src-generated/ugbc.tab.c"
    break;

  case 129: /* bank_definition_simple: CODE AT direct_integer  */
#line 530 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3632 "src-generated/ugbc.tab.c"
    break;

  case 130: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 534 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3640 "src-generated/ugbc.tab.c"
    break;

  case 131: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 537 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3648 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 540 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3656 "src-generated/ugbc.tab.c"
    break;

  case 133: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 543 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3664 "src-generated/ugbc.tab.c"
    break;

  case 134: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 547 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3672 "src-generated/ugbc.tab.c"
    break;

  case 135: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 550 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3680 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 553 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3688 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 556 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3696 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 562 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3704 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 565 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3712 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 568 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3720 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 571 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3728 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 574 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3736 "src-generated/ugbc.tab.c"
    break;

  case 145: /* raster_definition_simple: Identifier AT direct_integer  */
#line 583 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3744 "src-generated/ugbc.tab.c"
    break;

  case 146: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 586 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3752 "src-generated/ugbc.tab.c"
    break;

  case 147: /* raster_definition_expression: Identifier AT expr  */
#line 591 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3760 "src-generated/ugbc.tab.c"
    break;

  case 148: /* raster_definition_expression: AT expr WITH Identifier  */
#line 594 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3768 "src-generated/ugbc.tab.c"
    break;

  case 151: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 603 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3776 "src-generated/ugbc.tab.c"
    break;

  case 152: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 606 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3784 "src-generated/ugbc.tab.c"
    break;

  case 153: /* next_raster_definition_expression: Identifier AT expr  */
#line 611 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3792 "src-generated/ugbc.tab.c"
    break;

  case 154: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 614 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3800 "src-generated/ugbc.tab.c"
    break;

  case 157: /* color_definition_simple: BORDER direct_integer  */
#line 623 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3808 "src-generated/ugbc.tab.c"
    break;

  case 158: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 626 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3816 "src-generated/ugbc.tab.c"
    break;

  case 159: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 629 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3824 "src-generated/ugbc.tab.c"
    break;

  case 160: /* color_definition_expression: BORDER expr  */
#line 634 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3832 "src-generated/ugbc.tab.c"
    break;

  case 161: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 637 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3840 "src-generated/ugbc.tab.c"
    break;

  case 162: /* color_definition_expression: SPRITE expr TO expr  */
#line 640 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3848 "src-generated/ugbc.tab.c"
    break;

  case 168: /* wait_definition_simple: direct_integer CYCLES  */
#line 654 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3856 "src-generated/ugbc.tab.c"
    break;

  case 169: /* wait_definition_simple: direct_integer TICKS  */
#line 657 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3864 "src-generated/ugbc.tab.c"
    break;

  case 170: /* wait_definition_simple: direct_integer milliseconds  */
#line 660 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3872 "src-generated/ugbc.tab.c"
    break;

  case 171: /* wait_definition_expression: expr CYCLES  */
#line 665 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3880 "src-generated/ugbc.tab.c"
    break;

  case 172: /* wait_definition_expression: expr TICKS  */
#line 668 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3888 "src-generated/ugbc.tab.c"
    break;

  case 173: /* wait_definition_expression: expr milliseconds  */
#line 671 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3896 "src-generated/ugbc.tab.c"
    break;

  case 176: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 681 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3904 "src-generated/ugbc.tab.c"
    break;

  case 177: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 684 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3912 "src-generated/ugbc.tab.c"
    break;

  case 178: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 687 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3920 "src-generated/ugbc.tab.c"
    break;

  case 179: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 690 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3928 "src-generated/ugbc.tab.c"
    break;

  case 180: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 693 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3936 "src-generated/ugbc.tab.c"
    break;

  case 181: /* sprite_definition_simple: direct_integer ENABLE  */
#line 696 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3944 "src-generated/ugbc.tab.c"
    break;

  case 182: /* sprite_definition_simple: direct_integer DISABLE  */
#line 699 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3952 "src-generated/ugbc.tab.c"
    break;

  case 183: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 702 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3960 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 705 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3968 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 708 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3976 "src-generated/ugbc.tab.c"
    break;

  case 186: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 711 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3984 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 714 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3992 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 717 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4000 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 720 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4008 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 723 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4016 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_expression: expr DATA FROM expr  */
#line 728 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4024 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_expression: expr MULTICOLOR  */
#line 731 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4032 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_expression: expr MONOCOLOR  */
#line 734 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4040 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_expression: expr COLOR expr  */
#line 737 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4048 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 740 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4056 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_expression: expr ENABLE  */
#line 743 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4064 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_expression: expr DISABLE  */
#line 746 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4072 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 749 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4080 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 752 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4088 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 755 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4096 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 758 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4104 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 761 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4112 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 764 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4120 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 767 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4128 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 770 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4136 "src-generated/ugbc.tab.c"
    break;

  case 208: /* bitmap_definition_simple: AT direct_integer  */
#line 779 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4144 "src-generated/ugbc.tab.c"
    break;

  case 209: /* bitmap_definition_simple: ENABLE  */
#line 782 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4152 "src-generated/ugbc.tab.c"
    break;

  case 210: /* bitmap_definition_simple: DISABLE  */
#line 785 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4160 "src-generated/ugbc.tab.c"
    break;

  case 211: /* bitmap_definition_simple: CLEAR  */
#line 788 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4168 "src-generated/ugbc.tab.c"
    break;

  case 212: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 791 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4176 "src-generated/ugbc.tab.c"
    break;

  case 213: /* bitmap_definition_expression: AT expr  */
#line 797 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4184 "src-generated/ugbc.tab.c"
    break;

  case 214: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 800 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4192 "src-generated/ugbc.tab.c"
    break;

  case 217: /* textmap_definition_simple: AT direct_integer  */
#line 810 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4200 "src-generated/ugbc.tab.c"
    break;

  case 218: /* textmap_definition_expression: AT expr  */
#line 815 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4208 "src-generated/ugbc.tab.c"
    break;

  case 221: /* text_definition_simple: ENABLE  */
#line 824 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4216 "src-generated/ugbc.tab.c"
    break;

  case 222: /* text_definition_simple: DISABLE  */
#line 827 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4224 "src-generated/ugbc.tab.c"
    break;

  case 223: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 832 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4232 "src-generated/ugbc.tab.c"
    break;

  case 224: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 835 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4240 "src-generated/ugbc.tab.c"
    break;

  case 227: /* tiles_definition_simple: AT direct_integer  */
#line 844 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4248 "src-generated/ugbc.tab.c"
    break;

  case 228: /* tiles_definition_expression: AT expr  */
#line 849 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4256 "src-generated/ugbc.tab.c"
    break;

  case 231: /* colormap_definition_simple: AT direct_integer  */
#line 858 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4264 "src-generated/ugbc.tab.c"
    break;

  case 232: /* colormap_definition_simple: CLEAR  */
#line 861 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4272 "src-generated/ugbc.tab.c"
    break;

  case 233: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 864 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4280 "src-generated/ugbc.tab.c"
    break;

  case 234: /* colormap_definition_expression: AT expr  */
#line 869 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4288 "src-generated/ugbc.tab.c"
    break;

  case 235: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 872 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4296 "src-generated/ugbc.tab.c"
    break;

  case 238: /* screen_definition_simple: ON  */
#line 882 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4304 "src-generated/ugbc.tab.c"
    break;

  case 239: /* screen_definition_simple: OFF  */
#line 885 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4312 "src-generated/ugbc.tab.c"
    break;

  case 240: /* screen_definition_simple: ROWS direct_integer  */
#line 888 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4320 "src-generated/ugbc.tab.c"
    break;

  case 241: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 891 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4328 "src-generated/ugbc.tab.c"
    break;

  case 242: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 894 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4336 "src-generated/ugbc.tab.c"
    break;

  case 243: /* screen_definition_expression: ROWS expr  */
#line 899 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4344 "src-generated/ugbc.tab.c"
    break;

  case 244: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 902 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4352 "src-generated/ugbc.tab.c"
    break;

  case 245: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 905 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4360 "src-generated/ugbc.tab.c"
    break;

  case 249: /* var_definition_simple: Identifier ON Identifier  */
#line 914 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4368 "src-generated/ugbc.tab.c"
    break;

  case 250: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 917 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4376 "src-generated/ugbc.tab.c"
    break;

  case 251: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 920 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4384 "src-generated/ugbc.tab.c"
    break;

  case 252: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 923 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4394 "src-generated/ugbc.tab.c"
    break;

  case 253: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 928 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4404 "src-generated/ugbc.tab.c"
    break;

  case 254: /* goto_definition: Identifier  */
#line 935 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4412 "src-generated/ugbc.tab.c"
    break;

  case 255: /* goto_definition: Integer  */
#line 938 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4420 "src-generated/ugbc.tab.c"
    break;

  case 256: /* gosub_definition: Identifier  */
#line 944 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4428 "src-generated/ugbc.tab.c"
    break;

  case 257: /* gosub_definition: Integer  */
#line 947 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4436 "src-generated/ugbc.tab.c"
    break;

  case 259: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 956 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4444 "src-generated/ugbc.tab.c"
    break;

  case 260: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 962 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4452 "src-generated/ugbc.tab.c"
    break;

  case 263: /* ink_definition: expr  */
#line 971 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4460 "src-generated/ugbc.tab.c"
    break;

  case 264: /* on_goto_definition: Identifier  */
#line 976 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4469 "src-generated/ugbc.tab.c"
    break;

  case 265: /* $@4: %empty  */
#line 980 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4477 "src-generated/ugbc.tab.c"
    break;

  case 267: /* on_gosub_definition: Identifier  */
#line 985 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4486 "src-generated/ugbc.tab.c"
    break;

  case 268: /* $@5: %empty  */
#line 989 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4494 "src-generated/ugbc.tab.c"
    break;

  case 270: /* on_proc_definition: Identifier  */
#line 994 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4503 "src-generated/ugbc.tab.c"
    break;

  case 271: /* $@6: %empty  */
#line 998 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4511 "src-generated/ugbc.tab.c"
    break;

  case 273: /* $@7: %empty  */
#line 1003 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4519 "src-generated/ugbc.tab.c"
    break;

  case 275: /* $@8: %empty  */
#line 1006 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4527 "src-generated/ugbc.tab.c"
    break;

  case 277: /* $@9: %empty  */
#line 1009 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4535 "src-generated/ugbc.tab.c"
    break;

  case 279: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1014 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4543 "src-generated/ugbc.tab.c"
    break;

  case 280: /* every_definition: ON  */
#line 1017 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4551 "src-generated/ugbc.tab.c"
    break;

  case 281: /* every_definition: OFF  */
#line 1020 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4559 "src-generated/ugbc.tab.c"
    break;

  case 282: /* add_definition: Identifier COMMA expr  */
#line 1025 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4567 "src-generated/ugbc.tab.c"
    break;

  case 283: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1028 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4575 "src-generated/ugbc.tab.c"
    break;

  case 284: /* dimensions: Integer  */
#line 1034 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4584 "src-generated/ugbc.tab.c"
    break;

  case 285: /* dimensions: Integer COMMA dimensions  */
#line 1038 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4593 "src-generated/ugbc.tab.c"
    break;

  case 286: /* datatype: BYTE  */
#line 1045 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 4601 "src-generated/ugbc.tab.c"
    break;

  case 287: /* datatype: SIGNED BYTE  */
#line 1048 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 4609 "src-generated/ugbc.tab.c"
    break;

  case 288: /* datatype: WORD  */
#line 1051 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 4617 "src-generated/ugbc.tab.c"
    break;

  case 289: /* datatype: SIGNED WORD  */
#line 1054 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 4625 "src-generated/ugbc.tab.c"
    break;

  case 290: /* datatype: DWORD  */
#line 1057 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 4633 "src-generated/ugbc.tab.c"
    break;

  case 291: /* datatype: SIGNED DWORD  */
#line 1060 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 4641 "src-generated/ugbc.tab.c"
    break;

  case 292: /* datatype: ADDRESS  */
#line 1063 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 4649 "src-generated/ugbc.tab.c"
    break;

  case 293: /* datatype: POSITION  */
#line 1066 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 4657 "src-generated/ugbc.tab.c"
    break;

  case 294: /* datatype: COLOR  */
#line 1069 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 4665 "src-generated/ugbc.tab.c"
    break;

  case 295: /* datatype: STRING  */
#line 1072 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 4673 "src-generated/ugbc.tab.c"
    break;

  case 296: /* $@10: %empty  */
#line 1077 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4682 "src-generated/ugbc.tab.c"
    break;

  case 297: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1080 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 4692 "src-generated/ugbc.tab.c"
    break;

  case 298: /* $@11: %empty  */
#line 1085 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4701 "src-generated/ugbc.tab.c"
    break;

  case 299: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1088 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 4711 "src-generated/ugbc.tab.c"
    break;

  case 300: /* $@12: %empty  */
#line 1093 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4720 "src-generated/ugbc.tab.c"
    break;

  case 301: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1096 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 4730 "src-generated/ugbc.tab.c"
    break;

  case 304: /* indexes: expr  */
#line 1109 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4739 "src-generated/ugbc.tab.c"
    break;

  case 305: /* indexes: expr COMMA indexes  */
#line 1113 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4748 "src-generated/ugbc.tab.c"
    break;

  case 306: /* parameters: Identifier  */
#line 1120 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4758 "src-generated/ugbc.tab.c"
    break;

  case 307: /* parameters: Identifier DOLLAR  */
#line 1125 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4768 "src-generated/ugbc.tab.c"
    break;

  case 308: /* parameters: Identifier AS datatype  */
#line 1130 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4778 "src-generated/ugbc.tab.c"
    break;

  case 309: /* parameters: Identifier COMMA parameters  */
#line 1135 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4788 "src-generated/ugbc.tab.c"
    break;

  case 310: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1140 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4798 "src-generated/ugbc.tab.c"
    break;

  case 311: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1145 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4808 "src-generated/ugbc.tab.c"
    break;

  case 312: /* parameters_expr: Identifier  */
#line 1153 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4818 "src-generated/ugbc.tab.c"
    break;

  case 313: /* parameters_expr: Identifier DOLLAR  */
#line 1158 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4828 "src-generated/ugbc.tab.c"
    break;

  case 314: /* parameters_expr: Identifier AS datatype  */
#line 1163 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4838 "src-generated/ugbc.tab.c"
    break;

  case 315: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1168 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4848 "src-generated/ugbc.tab.c"
    break;

  case 316: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1173 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4858 "src-generated/ugbc.tab.c"
    break;

  case 317: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1178 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4868 "src-generated/ugbc.tab.c"
    break;

  case 318: /* parameters_expr: String  */
#line 1183 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4877 "src-generated/ugbc.tab.c"
    break;

  case 319: /* parameters_expr: String COMMA parameters_expr  */
#line 1187 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4886 "src-generated/ugbc.tab.c"
    break;

  case 320: /* values: expr  */
#line 1194 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4895 "src-generated/ugbc.tab.c"
    break;

  case 321: /* values: expr COMMA values  */
#line 1198 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4904 "src-generated/ugbc.tab.c"
    break;

  case 322: /* print_definition: expr  */
#line 1205 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 4912 "src-generated/ugbc.tab.c"
    break;

  case 323: /* print_definition: expr COMMA  */
#line 1208 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 4921 "src-generated/ugbc.tab.c"
    break;

  case 324: /* print_definition: expr SEMICOLON  */
#line 1212 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 4929 "src-generated/ugbc.tab.c"
    break;

  case 325: /* $@13: %empty  */
#line 1215 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 4938 "src-generated/ugbc.tab.c"
    break;

  case 327: /* $@14: %empty  */
#line 1219 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 4946 "src-generated/ugbc.tab.c"
    break;

  case 346: /* statement: INC Identifier  */
#line 1242 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 4954 "src-generated/ugbc.tab.c"
    break;

  case 347: /* statement: DEC Identifier  */
#line 1245 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 4962 "src-generated/ugbc.tab.c"
    break;

  case 348: /* statement: RANDOMIZE  */
#line 1248 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 4970 "src-generated/ugbc.tab.c"
    break;

  case 349: /* statement: RANDOMIZE expr  */
#line 1251 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 4978 "src-generated/ugbc.tab.c"
    break;

  case 350: /* statement: IF expr THEN  */
#line 1254 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4986 "src-generated/ugbc.tab.c"
    break;

  case 351: /* statement: ELSE  */
#line 1257 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 4994 "src-generated/ugbc.tab.c"
    break;

  case 352: /* statement: ELSE IF expr THEN  */
#line 1260 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5002 "src-generated/ugbc.tab.c"
    break;

  case 353: /* statement: ENDIF  */
#line 1263 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5010 "src-generated/ugbc.tab.c"
    break;

  case 354: /* statement: DO  */
#line 1266 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5018 "src-generated/ugbc.tab.c"
    break;

  case 355: /* statement: LOOP  */
#line 1269 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5026 "src-generated/ugbc.tab.c"
    break;

  case 356: /* $@15: %empty  */
#line 1272 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5034 "src-generated/ugbc.tab.c"
    break;

  case 357: /* statement: WHILE $@15 expr  */
#line 1274 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5042 "src-generated/ugbc.tab.c"
    break;

  case 358: /* statement: WEND  */
#line 1277 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5050 "src-generated/ugbc.tab.c"
    break;

  case 359: /* statement: REPEAT  */
#line 1280 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5058 "src-generated/ugbc.tab.c"
    break;

  case 360: /* statement: UNTIL expr  */
#line 1283 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5066 "src-generated/ugbc.tab.c"
    break;

  case 361: /* statement: EXIT  */
#line 1286 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5074 "src-generated/ugbc.tab.c"
    break;

  case 362: /* statement: EXIT PROC  */
#line 1289 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5082 "src-generated/ugbc.tab.c"
    break;

  case 363: /* statement: POP PROC  */
#line 1292 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5090 "src-generated/ugbc.tab.c"
    break;

  case 364: /* statement: EXIT IF expr  */
#line 1295 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5098 "src-generated/ugbc.tab.c"
    break;

  case 365: /* statement: EXIT Integer  */
#line 1298 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5106 "src-generated/ugbc.tab.c"
    break;

  case 366: /* statement: EXIT direct_integer  */
#line 1301 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5114 "src-generated/ugbc.tab.c"
    break;

  case 367: /* statement: EXIT IF expr COMMA Integer  */
#line 1304 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5122 "src-generated/ugbc.tab.c"
    break;

  case 368: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1307 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5130 "src-generated/ugbc.tab.c"
    break;

  case 369: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1310 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5138 "src-generated/ugbc.tab.c"
    break;

  case 370: /* statement: NEXT  */
#line 1313 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5146 "src-generated/ugbc.tab.c"
    break;

  case 371: /* statement: PROCEDURE Identifier  */
#line 1316 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5155 "src-generated/ugbc.tab.c"
    break;

  case 372: /* $@16: %empty  */
#line 1320 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5163 "src-generated/ugbc.tab.c"
    break;

  case 373: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1322 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5171 "src-generated/ugbc.tab.c"
    break;

  case 374: /* statement: SHARED parameters_expr  */
#line 1325 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5179 "src-generated/ugbc.tab.c"
    break;

  case 375: /* statement: GLOBAL parameters_expr  */
#line 1328 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5187 "src-generated/ugbc.tab.c"
    break;

  case 376: /* statement: END PROC  */
#line 1331 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 5195 "src-generated/ugbc.tab.c"
    break;

  case 377: /* statement: END PROC OSP expr CSP  */
#line 1334 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5203 "src-generated/ugbc.tab.c"
    break;

  case 378: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1337 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5211 "src-generated/ugbc.tab.c"
    break;

  case 379: /* statement: Identifier " "  */
#line 1340 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5220 "src-generated/ugbc.tab.c"
    break;

  case 380: /* statement: PROC Identifier  */
#line 1344 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5229 "src-generated/ugbc.tab.c"
    break;

  case 381: /* statement: CALL Identifier  */
#line 1348 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5238 "src-generated/ugbc.tab.c"
    break;

  case 382: /* $@17: %empty  */
#line 1352 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5246 "src-generated/ugbc.tab.c"
    break;

  case 383: /* statement: Identifier OSP $@17 values CSP  */
#line 1354 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5254 "src-generated/ugbc.tab.c"
    break;

  case 384: /* $@18: %empty  */
#line 1357 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5262 "src-generated/ugbc.tab.c"
    break;

  case 385: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1359 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5270 "src-generated/ugbc.tab.c"
    break;

  case 386: /* $@19: %empty  */
#line 1362 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5278 "src-generated/ugbc.tab.c"
    break;

  case 387: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1364 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5286 "src-generated/ugbc.tab.c"
    break;

  case 388: /* statement: Identifier COLON  */
#line 1367 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 5294 "src-generated/ugbc.tab.c"
    break;

  case 389: /* statement: BEG GAMELOOP  */
#line 1370 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 5302 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: END GAMELOOP  */
#line 1373 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 5310 "src-generated/ugbc.tab.c"
    break;

  case 391: /* statement: GRAPHIC  */
#line 1376 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 5318 "src-generated/ugbc.tab.c"
    break;

  case 392: /* statement: HALT  */
#line 1379 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 5326 "src-generated/ugbc.tab.c"
    break;

  case 393: /* statement: END  */
#line 1382 "src/ugbc.y"
        {
      end( _environment );
  }
#line 5334 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statement: RETURN  */
#line 1389 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 5342 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: RETURN expr  */
#line 1392 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 5350 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: POP  */
#line 1395 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 5358 "src-generated/ugbc.tab.c"
    break;

  case 401: /* statement: DONE  */
#line 1398 "src/ugbc.y"
          {
      return 0;
  }
#line 5366 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1401 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5374 "src-generated/ugbc.tab.c"
    break;

  case 403: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1404 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5382 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1407 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 5390 "src-generated/ugbc.tab.c"
    break;

  case 405: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1410 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5398 "src-generated/ugbc.tab.c"
    break;

  case 407: /* statement: Identifier ASSIGN expr  */
#line 1414 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 5412 "src-generated/ugbc.tab.c"
    break;

  case 408: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1423 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 5426 "src-generated/ugbc.tab.c"
    break;

  case 409: /* $@20: %empty  */
#line 1432 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5435 "src-generated/ugbc.tab.c"
    break;

  case 410: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1436 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 5448 "src-generated/ugbc.tab.c"
    break;

  case 411: /* $@21: %empty  */
#line 1444 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5457 "src-generated/ugbc.tab.c"
    break;

  case 412: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1447 "src/ugbc.y"
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
#line 5476 "src-generated/ugbc.tab.c"
    break;

  case 413: /* $@22: %empty  */
#line 1461 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5485 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1464 "src/ugbc.y"
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
#line 5504 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: DEBUG expr  */
#line 1478 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 5512 "src-generated/ugbc.tab.c"
    break;

  case 418: /* statements_no_linenumbers: statement  */
#line 1486 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 5518 "src-generated/ugbc.tab.c"
    break;

  case 419: /* $@23: %empty  */
#line 1487 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 5524 "src-generated/ugbc.tab.c"
    break;

  case 421: /* $@24: %empty  */
#line 1491 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 5532 "src-generated/ugbc.tab.c"
    break;

  case 422: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1493 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 5540 "src-generated/ugbc.tab.c"
    break;

  case 423: /* $@25: %empty  */
#line 1498 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 5548 "src-generated/ugbc.tab.c"
    break;

  case 429: /* $@26: %empty  */
#line 1508 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 5554 "src-generated/ugbc.tab.c"
    break;


#line 5558 "src-generated/ugbc.tab.c"

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

#line 1510 "src/ugbc.y"


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

