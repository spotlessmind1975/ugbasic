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
  YYSYMBOL_BLACK = 155,                    /* BLACK  */
  YYSYMBOL_WHITE = 156,                    /* WHITE  */
  YYSYMBOL_RED = 157,                      /* RED  */
  YYSYMBOL_CYAN = 158,                     /* CYAN  */
  YYSYMBOL_VIOLET = 159,                   /* VIOLET  */
  YYSYMBOL_GREEN = 160,                    /* GREEN  */
  YYSYMBOL_BLUE = 161,                     /* BLUE  */
  YYSYMBOL_YELLOW = 162,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 163,                   /* ORANGE  */
  YYSYMBOL_BROWN = 164,                    /* BROWN  */
  YYSYMBOL_LIGHT = 165,                    /* LIGHT  */
  YYSYMBOL_DARK = 166,                     /* DARK  */
  YYSYMBOL_GREY = 167,                     /* GREY  */
  YYSYMBOL_GRAY = 168,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 169,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 170,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 171,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 172,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 173,                /* TURQUOISE  */
  YYSYMBOL_TAN = 174,                      /* TAN  */
  YYSYMBOL_PINK = 175,                     /* PINK  */
  YYSYMBOL_PEACH = 176,                    /* PEACH  */
  YYSYMBOL_OLIVE = 177,                    /* OLIVE  */
  YYSYMBOL_Identifier = 178,               /* Identifier  */
  YYSYMBOL_String = 179,                   /* String  */
  YYSYMBOL_Integer = 180,                  /* Integer  */
  YYSYMBOL_181_ = 181,                     /* " "  */
  YYSYMBOL_YYACCEPT = 182,                 /* $accept  */
  YYSYMBOL_expr = 183,                     /* expr  */
  YYSYMBOL_expr_math = 184,                /* expr_math  */
  YYSYMBOL_term = 185,                     /* term  */
  YYSYMBOL_modula = 186,                   /* modula  */
  YYSYMBOL_factor = 187,                   /* factor  */
  YYSYMBOL_direct_integer = 188,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 189, /* random_definition_simple  */
  YYSYMBOL_random_definition = 190,        /* random_definition  */
  YYSYMBOL_color_enumeration = 191,        /* color_enumeration  */
  YYSYMBOL_exponential = 192,              /* exponential  */
  YYSYMBOL_193_1 = 193,                    /* $@1  */
  YYSYMBOL_194_2 = 194,                    /* $@2  */
  YYSYMBOL_195_3 = 195,                    /* $@3  */
  YYSYMBOL_position = 196,                 /* position  */
  YYSYMBOL_bank_definition_simple = 197,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 198, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 199,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 200, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 201, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 202,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 203, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 204, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 205,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 206,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 207, /* color_definition_expression  */
  YYSYMBOL_color_definition = 208,         /* color_definition  */
  YYSYMBOL_milliseconds = 209,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 210,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 211, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 212,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 213, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 214, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 215,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 216, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 217, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 218,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 219, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 220, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 221,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 222,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 223, /* text_definition_expression  */
  YYSYMBOL_text_definition = 224,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 225,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 226, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 227,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 228, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 229, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 230,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 231, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 232, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 233,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 234,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 235,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 236,         /* gosub_definition  */
  YYSYMBOL_var_definition = 237,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 238,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 239, /* point_definition_expression  */
  YYSYMBOL_point_definition = 240,         /* point_definition  */
  YYSYMBOL_ink_definition = 241,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 242,       /* on_goto_definition  */
  YYSYMBOL_243_4 = 243,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 244,      /* on_gosub_definition  */
  YYSYMBOL_245_5 = 245,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 246,       /* on_proc_definition  */
  YYSYMBOL_247_6 = 247,                    /* $@6  */
  YYSYMBOL_on_definition = 248,            /* on_definition  */
  YYSYMBOL_249_7 = 249,                    /* $@7  */
  YYSYMBOL_250_8 = 250,                    /* $@8  */
  YYSYMBOL_251_9 = 251,                    /* $@9  */
  YYSYMBOL_every_definition = 252,         /* every_definition  */
  YYSYMBOL_add_definition = 253,           /* add_definition  */
  YYSYMBOL_dimensions = 254,               /* dimensions  */
  YYSYMBOL_datatype = 255,                 /* datatype  */
  YYSYMBOL_dim_definition = 256,           /* dim_definition  */
  YYSYMBOL_257_10 = 257,                   /* $@10  */
  YYSYMBOL_258_11 = 258,                   /* $@11  */
  YYSYMBOL_259_12 = 259,                   /* $@12  */
  YYSYMBOL_dim_definitions = 260,          /* dim_definitions  */
  YYSYMBOL_indexes = 261,                  /* indexes  */
  YYSYMBOL_parameters = 262,               /* parameters  */
  YYSYMBOL_parameters_expr = 263,          /* parameters_expr  */
  YYSYMBOL_values = 264,                   /* values  */
  YYSYMBOL_statement = 265,                /* statement  */
  YYSYMBOL_266_13 = 266,                   /* $@13  */
  YYSYMBOL_267_14 = 267,                   /* $@14  */
  YYSYMBOL_268_15 = 268,                   /* $@15  */
  YYSYMBOL_269_16 = 269,                   /* $@16  */
  YYSYMBOL_270_17 = 270,                   /* $@17  */
  YYSYMBOL_271_18 = 271,                   /* $@18  */
  YYSYMBOL_272_19 = 272,                   /* $@19  */
  YYSYMBOL_273_20 = 273,                   /* $@20  */
  YYSYMBOL_statements_no_linenumbers = 274, /* statements_no_linenumbers  */
  YYSYMBOL_275_21 = 275,                   /* $@21  */
  YYSYMBOL_statements_with_linenumbers = 276, /* statements_with_linenumbers  */
  YYSYMBOL_277_22 = 277,                   /* $@22  */
  YYSYMBOL_statements_complex = 278,       /* statements_complex  */
  YYSYMBOL_279_23 = 279,                   /* $@23  */
  YYSYMBOL_program = 280,                  /* program  */
  YYSYMBOL_281_24 = 281                    /* $@24  */
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
#define YYLAST   2049

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  182
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  422
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  823

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   436


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
     175,   176,   177,   178,   179,   180,   181
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
    1194,  1198,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,
    1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1224,
    1227,  1230,  1233,  1236,  1239,  1242,  1245,  1248,  1251,  1251,
    1256,  1259,  1262,  1265,  1268,  1271,  1274,  1277,  1280,  1283,
    1286,  1289,  1292,  1295,  1299,  1299,  1304,  1307,  1310,  1313,
    1316,  1319,  1323,  1327,  1331,  1331,  1336,  1336,  1341,  1341,
    1346,  1349,  1352,  1355,  1358,  1361,  1364,  1365,  1366,  1367,
    1368,  1371,  1374,  1377,  1380,  1383,  1386,  1389,  1392,  1393,
    1402,  1411,  1411,  1423,  1423,  1440,  1440,  1457,  1460,  1461,
    1465,  1466,  1466,  1470,  1470,  1477,  1477,  1480,  1481,  1482,
    1483,  1487,  1487
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
  "PARAM", "BLACK", "WHITE", "RED", "CYAN", "VIOLET", "GREEN", "BLUE",
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
  "parameters", "parameters_expr", "values", "statement", "$@13", "$@14",
  "$@15", "$@16", "$@17", "$@18", "$@19", "$@20",
  "statements_no_linenumbers", "$@21", "statements_with_linenumbers",
  "$@22", "statements_complex", "$@23", "program", "$@24", YY_NULLPTR
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
     435,   436
};
#endif

#define YYPACT_NINF (-709)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-402)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -709,    52,   771,  -709,  -709,  -116,   -81,   -15,  -709,    54,
    1467,    86,    -5,  1467,  -709,    33,   162,  1601,   -47,   -51,
    -709,  -709,  -709,  1174,   113,    23,  1601,    57,   -55,  -709,
     110,   127,  1601,  1601,  -709,   154,   157,   -13,  1601,    45,
     117,  -709,   -39,  -709,  1601,    30,  1333,   178,    60,  1601,
      63,    79,    85,    87,    21,    21,    11,  -709,   224,   231,
     245,  -709,  -709,  -709,  1467,   229,  -709,  -709,  -709,  1467,
    1467,  1467,  -709,  -709,  -709,    81,  1015,  -709,  -709,   230,
     232,   233,   135,    88,  -709,  -709,   238,   239,  1601,  -709,
    -709,   240,   242,   243,   244,   246,   250,   269,   270,   273,
     274,   275,   276,   277,   278,   280,   282,   287,  -709,  -709,
     288,    22,  -709,  -709,  -709,  -709,  -709,  -709,  -709,   119,
    -709,  -709,    83,  -112,  -709,  -709,  -709,  -709,  -709,  -709,
    -709,  -709,  -709,   121,    17,  -709,  -709,   -12,   134,   185,
     207,   194,     4,  -709,  -709,  -709,  -709,  -709,    -4,   248,
      -3,     2,     9,    16,   300,  -709,  -709,  -709,   281,   295,
    -709,  -709,  -709,  1467,  -709,  -709,   296,  -709,  -709,  -709,
    -709,  -709,  1467,   283,   290,  -709,  -709,  -709,   -23,  -709,
      71,  -709,  -709,  -709,  -709,  -709,  1601,  1601,  -709,  -709,
     326,  -709,  -709,  -709,  1467,  -709,  -709,  -709,  1467,   305,
    -709,  -709,  -709,   272,  -709,  -709,   201,  1601,  1601,  -709,
    -709,  1467,  -709,  -709,  -709,   308,  -709,  -709,  -709,  -709,
    -709,  -709,  -709,  -709,  1601,  1601,  -709,  -709,  -709,  -709,
     337,  -709,  -709,   202,  -709,  1601,   346,  -709,  -709,  -709,
      94,   349,  -709,   211,   212,   223,    74,   365,  -709,  -709,
    -709,  -709,  1601,   360,  -709,  -709,   340,   -11,   915,  -709,
     771,   771,   347,   348,  1467,  -709,  -709,   303,   306,   307,
     309,  -709,   351,   352,   353,   354,   355,    97,   356,  1467,
    1467,  1467,  -709,  -709,  -709,  -709,  -709,  -709,  -709,  -709,
    -709,  -709,  1601,  1601,  -709,  1601,  1601,  1601,  1601,  1601,
    1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,
    1601,  1601,  1735,   359,   216,  -709,  -709,  -709,  -709,  -709,
    -709,  -709,  -709,   361,  -709,   362,  -709,  -709,  -709,  -709,
    -709,  -709,  1735,  1735,  1735,  1735,  1735,  1735,  1735,  1735,
    1735,  1735,  1735,  1735,  1735,  1869,  -709,  -709,  -709,  1467,
     374,  -709,  -709,  -709,   357,   248,   376,   248,   377,   248,
     378,   248,   379,   248,  -709,  1601,   373,  -709,  -709,   176,
     189,    48,    55,  -709,  -709,  -709,   375,   248,   381,  -709,
    -709,   191,   195,   112,   141,  -709,  -709,   382,  -709,  -709,
    1467,  -709,  -709,  1467,  1467,  -709,  -709,  -709,   366,   234,
    -709,   404,  1601,  -709,  -709,  -709,  -709,  1467,  -709,  1601,
     408,   410,  -709,  -709,  1467,   364,   411,  1601,   318,   415,
    1601,  -709,  -709,  -709,  -709,  -709,  -709,   149,  -709,  -709,
     390,   406,    63,  -709,   284,  -709,    21,   421,   -11,    21,
     771,  -709,  1601,   395,  1601,  1601,   396,    12,  -709,   915,
    -709,  -709,   257,   258,  -709,  -709,  1601,   248,  1601,   248,
     259,   260,   262,   263,   264,   402,   403,   412,  -709,   414,
     416,   417,   418,   420,   424,   438,   443,   449,   453,   426,
     427,   428,   429,   458,   431,   432,   433,   434,   435,   465,
     466,   439,   440,   441,     1,   299,   444,   446,  1601,  1601,
     185,   185,   247,   247,   247,   247,   247,   247,   247,   247,
     207,   194,   194,  -709,   452,   454,  1467,    26,  -709,   248,
    -709,   248,  -709,   248,  -709,   248,    70,  -709,  1601,  -709,
    -709,  -709,  -709,  -709,  -709,  -709,  -709,  1601,  -709,   248,
    -709,  -709,  -709,  -709,  -709,  -709,  -709,  -709,   248,  -709,
    -709,  -709,  -709,  -709,  -709,   304,   311,   312,   313,   471,
    1601,   478,   445,   450,   338,  1601,  1601,   486,   487,  -709,
     -44,   423,   319,  1601,   491,  -709,  -709,  -709,   467,   320,
     468,  -709,  1601,   321,  1601,  -709,    21,   496,  -709,  -709,
    -709,  1601,   497,   363,   498,   472,  1601,  -709,  -709,  -709,
    -709,  -709,  -709,  -709,  -709,  -709,  -709,  -709,  -709,   328,
     329,   330,  -709,  -709,  -709,  -709,  -709,  -709,  1601,  1601,
    1601,  1601,  -709,  -709,  -709,  -709,  1601,  -709,  -709,  -709,
    -709,  -709,  1601,  1601,  -709,  -709,  -709,  1869,   477,  -709,
    1601,   367,   479,   335,   339,  -709,  -709,  -709,  -709,  -709,
    -709,   490,  -709,   493,  -709,   341,    39,  -709,   509,  -709,
     517,   518,  -709,   519,  -709,   521,  -709,   516,  1467,   523,
    1601,  1601,   248,  -709,   499,   500,  1601,   248,  -709,  -709,
    1601,  -709,    41,  1601,   320,   524,   501,   320,   385,    75,
     389,   391,  -709,    21,   503,  1601,  -709,  1601,   527,   506,
    -709,  -709,  -709,   507,   508,    80,    91,   510,   511,   512,
     513,  -709,   514,  -709,  -709,  -709,  -709,   372,   380,  -709,
     515,  -709,   525,  -709,  1601,   248,   545,   546,   550,  1601,
    -709,  -709,  1601,  -709,  -709,  -709,   547,   548,   529,   530,
     447,  1601,   553,   495,   533,   320,  -709,   534,  -709,   321,
     551,   -11,  -709,  -709,  -709,   557,  -709,  -709,  1601,   558,
    -709,  -709,  1601,  -709,  1601,  -709,  -709,  -709,  -709,  -709,
    -709,  -709,  -709,   394,   397,   540,   542,   304,   311,   312,
    -709,  -709,  1601,  1601,  -709,  -709,  1601,   543,  1601,  1601,
    -709,  -709,  -709,  -709,   321,   572,  1601,  -709,  1601,   549,
     555,  -709,  -709,  -709,  -709,  -709,  -709,  -709,  -709,  -709,
    -709,   568,  -709,  -709,  -709,   321,  -709,  -709,  -709,  -709,
    1601,  -709,  -709
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     421,     0,   409,     1,   408,     0,     0,     0,   393,     0,
       0,   362,     0,     0,   384,     0,     0,     0,   248,     0,
     347,   351,   348,     0,     0,     0,     0,     0,   385,   345,
       0,     0,     0,   340,   383,     0,     0,     0,   390,   392,
     343,   346,   353,   350,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   405,   413,   410,   417,
     419,   422,   338,   339,     0,     0,   149,   150,   323,     0,
       0,     0,   163,   164,   325,     0,     0,    79,    80,     0,
       0,     0,     0,     0,   115,   116,     0,     0,     0,   112,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   117,
       0,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,    44,    49,    50,    51,    52,    53,
      54,    57,    58,     0,    63,    67,    65,     0,     2,    12,
      15,    17,     0,    76,    20,   174,   175,   326,     0,     0,
       0,     0,     0,     0,     0,   143,   144,   322,     0,     0,
     206,   207,   327,     0,   209,   210,   211,   215,   216,   328,
     238,   239,     0,     0,     0,   246,   247,   333,     0,   386,
       0,   258,   336,   254,   255,   387,     0,     0,   221,   222,
       0,   225,   226,   330,     0,   229,   230,   331,     0,   232,
     236,   237,   332,     0,   381,   382,   368,     0,     0,   407,
     341,     0,   219,   220,   329,     0,   261,   262,   334,   256,
     257,   388,   391,   355,     0,     0,   354,   357,   358,   352,
       0,   280,   281,     0,   389,     0,     0,   337,   263,   335,
     296,   302,   398,   372,   363,   373,   312,   318,   366,   367,
     415,   380,     0,   403,   374,   371,     0,     0,   409,   411,
     409,   409,     0,     0,     0,   160,   157,     0,     0,     0,
       0,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    24,    25,    27,    29,    30,    26,    31,
     101,    23,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    42,    45,    46,    47,
      48,    43,    56,    64,   108,     0,   165,   171,   166,   167,
     172,   173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   168,   169,   170,     0,
       0,   155,   156,   324,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,     0,     0,   196,   197,     0,
       0,     0,     0,   193,   192,   118,     0,     0,     0,   181,
     182,     0,     0,     0,     0,   178,   177,     0,   213,   208,
       0,   243,   240,     0,     0,   273,   277,   275,     0,     0,
     349,     0,     0,   228,   227,   234,   231,     0,   342,     0,
       0,     0,   218,   217,     0,     0,   356,     0,     0,     0,
       0,   294,   286,   288,   293,   290,   295,     0,   292,   300,
       0,     0,     0,   376,     0,   378,     0,   313,     0,     0,
     409,   399,     0,     0,     0,     0,     0,   405,   414,   409,
     418,   420,     0,     0,   147,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    14,     5,     7,     8,     9,    10,     6,     3,     4,
      16,    18,    19,    21,     0,     0,     0,     0,   125,     0,
     137,     0,   129,     0,   133,     0,   121,   194,     0,   201,
     200,   205,   204,   199,   203,   198,   202,     0,   179,     0,
     186,   185,   190,   189,   184,   188,   183,   187,     0,   214,
     212,   244,   241,   245,   242,     0,     0,     0,     0,   249,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   344,
       0,     0,     0,     0,   282,   287,   289,   291,     0,     0,
       0,   303,     0,     0,     0,   315,     0,   314,   319,   416,
     400,     0,   320,     0,   304,     0,     0,   412,   148,   146,
     162,   159,   161,   158,    75,    68,    70,    74,    72,     0,
       0,     0,    78,    77,    82,    81,    84,    83,     0,     0,
       0,     0,    91,    92,    93,   100,     0,    94,    95,    96,
      97,    98,     0,     0,   110,   111,   102,     0,     0,   106,
       0,     0,     0,     0,     0,   153,   151,   122,   135,   127,
     130,   124,   136,   128,   132,     0,     0,   191,     0,   176,
       0,   264,   274,   267,   278,   270,   276,   250,     0,     0,
       0,     0,     0,   369,     0,     0,     0,     0,   359,   360,
       0,   279,     0,     0,     0,   284,     0,     0,     0,   306,
       0,     0,   316,     0,     0,     0,   375,     0,     0,     0,
      69,    71,    73,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,   109,    60,   154,   152,     0,     0,   138,
     123,   134,   126,   131,     0,     0,     0,     0,     0,     0,
     252,   251,     0,   224,   235,   233,     0,     0,     0,     0,
     361,     0,     0,     0,     0,     0,   297,     0,   377,     0,
     307,     0,   365,   379,   317,     0,   321,   305,     0,     0,
      85,    86,     0,    87,     0,    89,    99,   105,   104,    22,
      62,   140,   142,     0,     0,     0,     0,     0,     0,     0,
     253,   223,     0,     0,   260,   259,     0,     0,     0,     0,
     301,   285,   299,   309,     0,   308,     0,   402,     0,     0,
       0,   139,   141,   195,   180,   266,   269,   272,   394,   395,
     370,     0,   396,   283,   310,     0,   404,   406,    88,    90,
       0,   311,   397
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -709,   -10,    28,   -73,   249,  -122,    64,  -709,  -709,  -709,
    -335,  -709,  -709,  -709,   436,  -709,  -709,  -709,  -709,  -709,
    -709,  -709,  -709,  -709,  -709,  -709,  -709,   451,  -709,  -709,
    -709,  -709,  -709,  -709,  -709,  -709,  -709,  -709,  -709,  -709,
    -709,  -709,  -709,  -709,  -709,  -709,  -709,  -709,  -709,  -709,
    -709,  -709,  -709,  -709,  -709,  -709,  -709,  -709,  -709,  -709,
    -195,  -709,  -192,  -709,  -191,  -709,  -709,  -709,  -709,  -709,
    -709,  -709,  -634,  -255,  -709,  -709,  -709,  -709,   160,  -495,
    -708,   -54,  -492,  -709,  -709,  -709,  -709,  -709,  -709,  -709,
    -709,  -709,  -253,  -709,  -709,  -709,  -249,  -709,  -709,  -709
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   594,   138,   139,   140,   141,   142,   289,   290,   143,
     144,   325,   497,   498,   376,   155,   156,   157,    66,    67,
      68,   351,   352,   353,    72,    73,    74,   331,   145,   146,
     147,   160,   161,   162,   167,   168,   169,   212,   213,   214,
     191,   192,   193,   195,   196,   197,   200,   201,   202,   175,
     176,   177,   181,   185,   221,   182,   216,   217,   218,   239,
     662,   726,   664,   727,   666,   728,   179,   555,   557,   556,
     234,   237,   686,   429,   241,   430,   431,   578,   242,   595,
     690,   248,   593,    58,   186,   434,   444,   582,   584,   256,
     443,   257,    59,   449,    60,   258,    61,   440,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     137,   249,   446,   158,   642,   448,   641,   178,   637,    64,
     513,   450,   451,   190,   421,   250,   203,   251,   251,   149,
     349,   355,   209,   210,   252,   252,   357,   150,   222,   225,
     395,   253,   253,   359,   229,   205,   233,   323,    83,   238,
     361,   793,   313,    83,   151,  -401,  -401,   198,   741,   320,
     744,   -59,     3,   747,   262,   321,   314,   163,   647,   265,
     267,   269,    62,   422,   423,   424,   278,   326,   327,   164,
     165,   720,   152,   153,   425,   648,   742,   159,   294,   396,
      69,   436,   749,   326,   346,    70,   814,   762,   721,   206,
     688,   398,   691,   533,   437,   750,   694,    63,   764,   655,
     535,   699,   534,   649,   650,   226,   228,   821,   148,   536,
     199,   791,   426,   399,  -298,   763,   722,   723,   656,   421,
     166,   397,   438,   751,   427,    71,   765,   183,   263,   184,
     345,   180,   428,   266,   268,   270,   678,   194,   328,   329,
     330,   227,   332,   333,   207,   712,   334,   204,   335,   336,
     337,   338,   339,   388,   328,   329,   347,   544,   254,   254,
     282,   208,   391,    65,   324,   219,   545,   220,   422,   423,
     424,   465,   466,   154,   350,   356,   400,   401,   211,   425,
     358,   215,   467,   587,   403,   224,   546,   360,   405,   223,
     494,   589,   255,   255,   362,   547,   597,   410,   411,   246,
     247,   412,   757,   756,   170,   171,   172,   173,   230,   283,
     284,   285,   235,   354,   415,   416,   174,   426,   286,   287,
     288,   511,   512,   575,   576,   419,   343,   389,   344,   427,
     259,   340,   529,   530,   577,   260,   392,   428,   236,   341,
     316,   240,   441,   317,   318,   531,   532,   540,   541,   261,
     319,   542,   543,   264,   454,   332,   333,   243,   404,   500,
     501,   271,   406,   244,   279,   245,   280,   281,   291,   469,
     471,   473,   292,   293,   295,   413,   296,   297,   298,   315,
     299,   322,   475,   476,   300,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   710,   301,   302,   364,   365,   303,   304,   305,
     306,   307,   308,   366,   309,   342,   310,   367,   368,   364,
     377,   311,   312,   345,   363,   390,   369,   378,   455,   393,
      83,   379,   380,   402,   407,   370,   394,   371,   372,   514,
     381,   408,   414,   470,   472,   474,   373,   374,   409,   382,
     417,   383,   384,   420,   418,   527,   432,   375,   433,  -364,
     385,   386,   502,   503,   504,   505,   506,   507,   508,   509,
     435,   375,   439,   442,   445,   456,   452,   453,   457,   458,
     549,   459,   585,   551,   553,   588,   460,   461,   462,   463,
     464,   468,   561,   495,   496,   -61,   499,   562,   516,   564,
     519,   521,   523,   525,   567,   517,   528,   571,   558,   537,
     574,   560,   559,   515,   539,   565,   548,   566,   570,   518,
     572,   520,   573,   522,   579,   524,   580,   526,   586,   591,
     596,   583,   590,   569,   592,   598,   599,   609,   610,   604,
     605,   538,   606,   607,   608,   618,   600,   611,   602,   612,
     619,   613,   614,   615,   550,   616,   620,   552,   554,   617,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   563,   632,   633,   634,   635,   636,   638,   568,   639,
     640,   643,   661,   644,   668,   670,   673,   671,   592,   663,
     665,   667,   672,   676,   677,   680,   795,   681,   683,   689,
     685,   684,   687,   693,   695,   697,   645,   698,   700,   701,
     702,   696,   711,   715,   714,   713,   724,   716,   657,   717,
     719,   601,   718,   603,   725,  -265,  -268,   658,  -271,   729,
     732,   745,   692,   748,   736,   737,   746,   752,   755,   753,
     758,   759,   760,   761,   773,   766,   767,   768,   769,   770,
     669,   771,   777,   778,   774,   674,   675,   779,   794,   772,
     782,   783,   786,   682,   784,   785,   788,   789,   790,   792,
     796,   798,   592,   801,   592,   803,   802,   804,   811,   815,
     646,   820,   805,   651,   818,   652,   806,   653,   807,   654,
     819,   510,   581,   348,     0,   387,     0,     0,     0,     0,
       0,     0,     0,   659,     0,     0,     0,     0,   703,   704,
     705,   706,   660,     0,     0,     0,   707,     0,     0,     0,
       0,     0,   708,   709,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   679,     0,     0,     0,     0,   754,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   730,     0,
     733,   734,     0,     0,     0,     0,   738,     0,     0,     0,
     740,     0,     0,   743,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   592,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   775,     0,     0,     0,     0,   780,
       0,     0,   781,     0,     0,     0,     0,     0,     0,     0,
       0,   787,   731,     0,     0,     0,   735,     0,     0,     0,
       0,   739,     0,     0,     0,     0,     0,     0,   797,     0,
       0,     0,   799,     0,   800,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   808,   809,     4,     0,   810,     0,   812,   813,
       0,     5,     6,     0,     0,     0,   816,     0,   817,   776,
       0,     0,     0,     7,     8,     0,     9,     0,    10,    11,
       0,    12,    13,     0,     0,     0,     0,     0,     0,    14,
     822,    15,    16,    17,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      28,     0,    29,     0,     0,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,    39,     0,    40,     0,     0,
       0,    41,    42,    43,    44,    45,     0,    46,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,    50,     0,    51,    52,    53,     4,     0,
      54,     0,     0,     0,    55,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       9,     0,    10,    11,     0,    12,    13,     0,     0,    56,
       0,    57,     0,    14,     0,    15,    16,    17,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    28,     0,    29,     0,     0,    30,
      31,    32,     0,    33,    34,    35,    36,    37,    38,    39,
       0,    40,     0,     0,    75,    41,    42,    43,    44,    45,
       0,    46,    47,     0,     0,     0,     0,     0,     0,     0,
     272,     0,     0,     0,     0,     0,    48,     0,     0,    76,
       0,     0,     0,     0,    49,     0,     0,    50,     0,    51,
      52,    53,     0,     0,    54,    77,    78,    79,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,    81,     0,     0,    82,   273,
     274,   275,     0,   447,     0,     0,     0,     0,    84,    85,
     276,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,   104,   105,
     277,   106,   107,   108,     0,   109,   110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    75,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,     0,     0,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,     0,
     188,   189,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,    81,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,   103,   104,   105,     0,
     106,   107,   108,     0,   109,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    75,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,     0,     0,     0,   231,   232,     0,     0,     0,
       0,     0,     0,    77,    78,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,     0,    81,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,   105,     0,   106,
     107,   108,     0,   109,   110,     0,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    76,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,    77,    78,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,     0,     0,    81,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,     0,   106,   107,   108,     0,   109,   110,     0,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    76,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,    77,    78,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,    81,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,   103,   104,   105,     0,   106,   107,   108,
       0,   109,   110,     0,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,    76,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,     0,     0,     0,    77,    78,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,    81,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,   104,   105,
       0,   106,   107,   108,     0,   109,   110,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,    76,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,    77,
      78,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,    81,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,    90,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,   103,   104,   105,     0,   106,   107,   108,     0,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136
};

static const yytype_int16 yycheck[] =
{
      10,    55,   257,    13,   499,   258,   498,    17,     7,    24,
     345,   260,   261,    23,    25,     4,    26,     6,     6,    24,
      24,    24,    32,    33,    13,    13,    24,    32,    38,    68,
      53,    20,    20,    24,    44,    90,    46,    20,    82,    49,
      24,   749,    20,    82,    49,    34,    34,    24,     7,   161,
     684,    34,     0,   687,    64,   167,    34,    24,    32,    69,
      70,    71,   178,    74,    75,    76,    76,    79,    80,    36,
      37,    32,    77,    78,    85,    49,    35,    13,    88,   102,
      26,     7,     7,    79,    80,    31,   794,     7,    49,   144,
     582,    20,   584,    45,    20,    20,   591,   178,     7,    29,
      45,   596,    54,    77,    78,   144,    42,   815,    22,    54,
      87,   745,   123,    42,    20,    35,    77,    78,    48,    25,
      87,   144,    48,    48,   135,    71,    35,   178,    64,   180,
     129,   178,   143,    69,    70,    71,   180,    24,   150,   151,
     152,   180,     8,     9,    34,   640,    12,    90,    14,    15,
      16,    17,    18,   163,   150,   151,   152,    45,   147,   147,
      25,    34,   172,   178,   147,   178,    54,   180,    74,    75,
      76,    74,    75,   178,   178,   178,   186,   187,    24,    85,
     178,    24,    85,   438,   194,    68,    45,   178,   198,   144,
     312,   440,   181,   181,   178,    54,   449,   207,   208,   178,
     179,   211,   697,   695,    42,    43,    44,    45,   178,    74,
      75,    76,    34,   149,   224,   225,    54,   123,    83,    84,
      85,   343,   344,    74,    75,   235,    19,   163,    21,   135,
       6,    97,    56,    57,    85,     4,   172,   143,   178,   105,
     157,   178,   252,   160,   161,    56,    57,    56,    57,     4,
     167,    56,    57,    24,   264,     8,     9,   178,   194,   332,
     333,   180,   198,   178,    34,   178,    34,    34,   180,   279,
     280,   281,    34,    34,    34,   211,    34,    34,    34,   160,
      34,   160,   292,   293,    34,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   637,    34,    34,    24,    25,    34,    34,    34,
      34,    34,    34,    32,    34,   130,    34,    36,    37,    24,
      25,    34,    34,   129,    24,    29,    45,    32,   264,    46,
      82,    36,    37,     7,    29,    54,    46,    56,    57,   349,
      45,    69,    34,   279,   280,   281,    65,    66,   147,    54,
      13,    56,    57,     7,   152,   365,     7,    76,   147,   147,
      65,    66,   334,   335,   336,   337,   338,   339,   340,   341,
     147,    76,     7,    13,    34,    72,    29,    29,    72,    72,
     390,    72,   436,   393,   394,   439,    35,    35,    35,    35,
      35,    35,   402,    34,   178,    34,    34,   407,    24,   409,
      24,    24,    24,    24,   414,    48,    33,   417,    42,    34,
     420,     7,   178,   349,    33,     7,    34,     7,     7,   355,
     102,   357,     7,   359,    34,   361,    20,   363,     7,    34,
      34,   147,   442,    69,   444,   178,   178,    35,    35,   180,
     180,   377,   180,   180,   180,     7,   456,    35,   458,    35,
       7,    35,    35,    35,   390,    35,     7,   393,   394,    35,
       7,    35,    35,    35,    35,     7,    35,    35,    35,    35,
      35,   407,     7,     7,    35,    35,    35,   178,   414,    35,
      34,    29,   178,    29,    13,     7,   148,    42,   498,   178,
     178,   178,    42,     7,     7,    72,   751,   178,     7,   178,
     180,    34,    34,     7,     7,     7,   516,    35,   180,   180,
     180,   148,    35,   178,    35,   148,     7,   178,   528,    29,
     179,   457,    29,   459,     7,     7,     7,   537,     7,    13,
       7,     7,   586,   148,    35,    35,    35,   148,    35,   148,
      13,    35,    35,    35,    29,    35,    35,    35,    35,    35,
     560,   179,     7,     7,    29,   565,   566,     7,     7,   179,
      13,    13,   115,   573,    35,    35,    13,    72,    35,    35,
      13,    13,   582,   179,   584,    35,   179,    35,    35,     7,
     516,    13,   777,   519,    35,   521,   778,   523,   779,   525,
      35,   342,   432,   142,    -1,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   539,    -1,    -1,    -1,    -1,   618,   619,
     620,   621,   548,    -1,    -1,    -1,   626,    -1,    -1,    -1,
      -1,    -1,   632,   633,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   570,    -1,    -1,    -1,    -1,   693,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   668,    -1,
     670,   671,    -1,    -1,    -1,    -1,   676,    -1,    -1,    -1,
     680,    -1,    -1,   683,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   695,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   724,    -1,    -1,    -1,    -1,   729,
      -1,    -1,   732,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   741,   668,    -1,    -1,    -1,   672,    -1,    -1,    -1,
      -1,   677,    -1,    -1,    -1,    -1,    -1,    -1,   758,    -1,
      -1,    -1,   762,    -1,   764,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   782,   783,     3,    -1,   786,    -1,   788,   789,
      -1,    10,    11,    -1,    -1,    -1,   796,    -1,   798,   725,
      -1,    -1,    -1,    22,    23,    -1,    25,    -1,    27,    28,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
     820,    40,    41,    42,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    -1,    91,    -1,    -1,    94,    95,    96,    -1,    98,
      99,   100,   101,   102,   103,   104,    -1,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,    -1,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,   142,    -1,   144,   145,   146,     3,    -1,
     149,    -1,    -1,    -1,   153,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    -1,
      25,    -1,    27,    28,    -1,    30,    31,    -1,    -1,   178,
      -1,   180,    -1,    38,    -1,    40,    41,    42,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    91,    -1,    -1,    94,
      95,    96,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,   106,    -1,    -1,     9,   110,   111,   112,   113,   114,
      -1,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    34,
      -1,    -1,    -1,    -1,   139,    -1,    -1,   142,    -1,   144,
     145,   146,    -1,    -1,   149,    50,    51,    52,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,    74,
      75,    76,    -1,   178,    -1,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,   132,   133,   134,
     135,   136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,     9,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,
     136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,     9,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,
     137,   138,    -1,   140,   141,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    34,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,   141,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    34,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,   138,
      -1,   140,   141,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    34,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,   136,   137,   138,    -1,   140,   141,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    34,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,   137,   138,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    -1,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   280,   281,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    88,    89,    91,
      94,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     106,   110,   111,   112,   113,   114,   116,   117,   131,   139,
     142,   144,   145,   146,   149,   153,   178,   180,   265,   274,
     276,   278,   178,   178,    24,   178,   200,   201,   202,    26,
      31,    71,   206,   207,   208,     9,    34,    50,    51,    52,
      67,    70,    73,    82,    83,    84,    94,    95,   107,   108,
     109,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   132,   133,   134,   136,   137,   138,   140,
     141,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   183,   184,   185,
     186,   187,   188,   191,   192,   210,   211,   212,    22,    24,
      32,    49,    77,    78,   178,   197,   198,   199,   183,   188,
     213,   214,   215,    24,    36,    37,    87,   216,   217,   218,
      42,    43,    44,    45,    54,   231,   232,   233,   183,   248,
     178,   234,   237,   178,   180,   235,   266,    24,    36,    37,
     183,   222,   223,   224,    24,   225,   226,   227,    24,    87,
     228,   229,   230,   183,    90,    90,   144,    34,    34,   183,
     183,    24,   219,   220,   221,    24,   238,   239,   240,   178,
     180,   236,   183,   144,    68,    68,   144,   180,   188,   183,
     178,    42,    43,   183,   252,    34,   178,   253,   183,   241,
     178,   256,   260,   178,   178,   178,   178,   179,   263,   263,
       4,     6,    13,    20,   147,   181,   271,   273,   277,     6,
       4,     4,   183,   188,    24,   183,   188,   183,   188,   183,
     188,   180,    25,    74,    75,    76,    85,   135,   183,    34,
      34,    34,    25,    74,    75,    76,    83,    84,    85,   189,
     190,   180,    34,    34,   183,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    20,    34,   160,   157,   160,   161,   167,
     161,   167,   160,    20,   147,   193,    79,    80,   150,   151,
     152,   209,     8,     9,    12,    14,    15,    16,    17,    18,
      97,   105,   130,    19,    21,   129,    80,   152,   209,    24,
     178,   203,   204,   205,   188,    24,   178,    24,   178,    24,
     178,    24,   178,    24,    24,    25,    32,    36,    37,    45,
      54,    56,    57,    65,    66,    76,   196,    25,    32,    36,
      37,    45,    54,    56,    57,    65,    66,   196,   183,   188,
      29,   183,   188,    46,    46,    53,   102,   144,    20,    42,
     183,   183,     7,   183,   188,   183,   188,    29,    69,   147,
     183,   183,   183,   188,    34,   183,   183,    13,   152,   183,
       7,    25,    74,    75,    76,    85,   123,   135,   143,   255,
     257,   258,     7,   147,   267,   147,     7,    20,    48,     7,
     279,   183,    13,   272,   268,    34,   255,   178,   274,   275,
     278,   278,    29,    29,   183,   188,    72,    72,    72,    72,
      35,    35,    35,    35,    35,    74,    75,    85,    35,   183,
     188,   183,   188,   183,   188,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   187,    34,   178,   194,   195,    34,
     185,   185,   184,   184,   184,   184,   184,   184,   184,   184,
     186,   187,   187,   192,   183,   188,    24,    48,   188,    24,
     188,    24,   188,    24,   188,    24,   188,   183,    33,    56,
      57,    56,    57,    45,    54,    45,    54,    34,   188,    33,
      56,    57,    56,    57,    45,    54,    45,    54,    34,   183,
     188,   183,   188,   183,   188,   249,   251,   250,    42,   178,
       7,   183,   183,   188,   183,     7,     7,   183,   188,    69,
       7,   183,   102,     7,   183,    74,    75,    85,   259,    34,
      20,   260,   269,   147,   270,   263,     7,   255,   263,   278,
     183,    34,   183,   264,   183,   261,    34,   274,   178,   178,
     183,   188,   183,   188,   180,   180,   180,   180,   180,    35,
      35,    35,    35,    35,    35,    35,    35,    35,     7,     7,
       7,     7,    35,    35,    35,    35,     7,    35,    35,    35,
      35,    35,     7,     7,    35,    35,    35,     7,   178,    35,
      34,   264,   261,    29,    29,   183,   188,    32,    49,    77,
      78,   188,   188,   188,   188,    29,    48,   183,   183,   188,
     188,   178,   242,   178,   244,   178,   246,   178,    13,   183,
       7,    42,    42,   148,   183,   183,     7,     7,   180,   188,
      72,   178,   183,     7,    34,   180,   254,    34,   264,   178,
     262,   264,   263,     7,   261,     7,   148,     7,    35,   261,
     180,   180,   180,   183,   183,   183,   183,   183,   183,   183,
     192,    35,   261,   148,    35,   178,   178,    29,    29,   179,
      32,    49,    77,    78,     7,     7,   243,   245,   247,    13,
     183,   188,     7,   183,   183,   188,    35,    35,   183,   188,
     183,     7,    35,   183,   254,     7,    35,   254,   148,     7,
      20,    48,   148,   148,   263,    35,   264,   261,    13,    35,
      35,    35,     7,    35,     7,    35,    35,    35,    35,    35,
      35,   179,   179,    29,    29,   183,   188,     7,     7,     7,
     183,   183,    13,    13,    35,    35,   115,   183,    13,    72,
      35,   254,    35,   262,     7,   255,    13,   183,    13,   183,
     183,   179,   179,    35,    35,   242,   244,   246,   183,   183,
     183,    35,   183,   183,   262,     7,   183,   183,    35,    35,
      13,   262,   183
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   182,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   184,   184,   184,   185,   185,   186,   186,   186,
     187,   187,   187,   188,   189,   189,   189,   189,   189,   189,
     189,   190,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   193,
     192,   194,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   195,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   196,   196,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   198,   198,
     198,   198,   198,   199,   199,   200,   200,   201,   201,   202,
     202,   203,   203,   204,   204,   205,   205,   206,   206,   206,
     207,   207,   207,   208,   208,   209,   209,   209,   210,   210,
     210,   211,   211,   211,   212,   212,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   215,   215,   216,   216,
     216,   216,   216,   217,   217,   218,   218,   219,   220,   221,
     221,   222,   222,   223,   223,   224,   224,   225,   226,   227,
     227,   228,   228,   228,   229,   229,   230,   230,   231,   231,
     231,   231,   231,   232,   232,   232,   233,   233,   234,   234,
     234,   234,   234,   234,   235,   235,   236,   236,   237,   238,
     239,   240,   240,   241,   242,   243,   242,   244,   245,   244,
     246,   247,   246,   249,   248,   250,   248,   251,   248,   252,
     252,   252,   253,   253,   254,   254,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   257,   256,   258,   256,
     259,   256,   260,   260,   261,   261,   262,   262,   262,   262,
     262,   262,   263,   263,   263,   263,   263,   263,   263,   263,
     264,   264,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   266,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   267,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   268,   265,   269,   265,   270,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   271,   265,   272,   265,   273,   265,   265,   265,   265,
     274,   275,   274,   277,   276,   279,   278,   278,   278,   278,
     278,   281,   280
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
       1,     3,     2,     2,     3,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     3,     1,     4,     1,     1,     1,     0,     3,
       1,     1,     2,     1,     2,     2,     3,     2,     2,     5,
       5,     6,     1,     2,     0,     6,     2,     2,     2,     5,
       8,     2,     2,     2,     0,     5,     0,     6,     0,     6,
       2,     2,     2,     1,     1,     1,     2,     2,     2,     2,
       1,     2,     1,     1,     8,     8,     8,    10,     2,     3,
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
#line 73 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2597 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 77 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2606 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 81 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2614 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 84 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2622 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 87 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2630 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 90 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2638 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 93 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2646 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 96 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2654 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 99 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2662 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 106 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2670 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 109 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2679 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 122 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2688 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 126 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2697 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 134 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2706 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 138 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 2715 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 145 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2723 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 150 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2731 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 153 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2739 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 156 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2747 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 159 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2755 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 162 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2763 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 165 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2771 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 168 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2779 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 173 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2787 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 178 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2796 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 182 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2805 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 186 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2814 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 190 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2823 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 194 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2832 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 198 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2841 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 202 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2850 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 206 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2859 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 210 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2868 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 214 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2877 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 218 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2886 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 222 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2895 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 226 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2904 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 230 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2913 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 234 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2922 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 238 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2931 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 242 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2940 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 246 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2949 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 250 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2958 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 254 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2967 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 258 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2976 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 262 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2985 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 266 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2994 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 270 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3003 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 274 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3012 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 278 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3021 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 282 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3030 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 288 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3039 "src-generated/ugbc.tab.c"
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
#line 3051 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 299 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3060 "src-generated/ugbc.tab.c"
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
#line 3072 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 310 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3080 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 313 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3088 "src-generated/ugbc.tab.c"
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
#line 3102 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 325 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3111 "src-generated/ugbc.tab.c"
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
#line 3123 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 336 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3132 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 340 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3141 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 344 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3150 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 348 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3159 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 352 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3168 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 356 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3177 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 360 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3186 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 364 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3195 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 368 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3203 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 371 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3211 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 374 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3219 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 377 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3227 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 380 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3235 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 383 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3243 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 386 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3251 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 389 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3259 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 392 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3267 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 395 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3275 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 398 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3283 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 401 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3291 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 404 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3299 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 407 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3307 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 410 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3315 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 413 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3323 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 416 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3331 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 419 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3339 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 422 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3347 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 425 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3355 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 428 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3363 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 431 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3371 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 434 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3379 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 437 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3387 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 440 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3395 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 443 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3403 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 446 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3411 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 449 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3419 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 452 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3427 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 455 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3435 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 458 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3443 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 461 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3451 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 464 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3459 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 466 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3468 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 470 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3476 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 473 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3484 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 476 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3493 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 480 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3502 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 484 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3511 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: WIDTH  */
#line 488 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3519 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: HEIGHT  */
#line 491 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3527 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: TIMER  */
#line 494 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3535 "src-generated/ugbc.tab.c"
    break;

  case 120: /* bank_definition_simple: AT direct_integer  */
#line 502 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3543 "src-generated/ugbc.tab.c"
    break;

  case 121: /* bank_definition_simple: Identifier AT direct_integer  */
#line 505 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3551 "src-generated/ugbc.tab.c"
    break;

  case 122: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 508 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3559 "src-generated/ugbc.tab.c"
    break;

  case 123: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 511 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3567 "src-generated/ugbc.tab.c"
    break;

  case 124: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 514 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3575 "src-generated/ugbc.tab.c"
    break;

  case 125: /* bank_definition_simple: DATA AT direct_integer  */
#line 517 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3583 "src-generated/ugbc.tab.c"
    break;

  case 126: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 521 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3591 "src-generated/ugbc.tab.c"
    break;

  case 127: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 524 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3599 "src-generated/ugbc.tab.c"
    break;

  case 128: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 527 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3607 "src-generated/ugbc.tab.c"
    break;

  case 129: /* bank_definition_simple: CODE AT direct_integer  */
#line 530 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3615 "src-generated/ugbc.tab.c"
    break;

  case 130: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 534 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3623 "src-generated/ugbc.tab.c"
    break;

  case 131: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 537 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3631 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 540 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3639 "src-generated/ugbc.tab.c"
    break;

  case 133: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 543 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3647 "src-generated/ugbc.tab.c"
    break;

  case 134: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 547 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3655 "src-generated/ugbc.tab.c"
    break;

  case 135: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 550 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3663 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 553 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3671 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 556 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3679 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 562 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3687 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 565 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3695 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 568 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3703 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 571 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3711 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 574 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3719 "src-generated/ugbc.tab.c"
    break;

  case 145: /* raster_definition_simple: Identifier AT direct_integer  */
#line 583 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3727 "src-generated/ugbc.tab.c"
    break;

  case 146: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 586 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3735 "src-generated/ugbc.tab.c"
    break;

  case 147: /* raster_definition_expression: Identifier AT expr  */
#line 591 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3743 "src-generated/ugbc.tab.c"
    break;

  case 148: /* raster_definition_expression: AT expr WITH Identifier  */
#line 594 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3751 "src-generated/ugbc.tab.c"
    break;

  case 151: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 603 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3759 "src-generated/ugbc.tab.c"
    break;

  case 152: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 606 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3767 "src-generated/ugbc.tab.c"
    break;

  case 153: /* next_raster_definition_expression: Identifier AT expr  */
#line 611 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3775 "src-generated/ugbc.tab.c"
    break;

  case 154: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 614 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3783 "src-generated/ugbc.tab.c"
    break;

  case 157: /* color_definition_simple: BORDER direct_integer  */
#line 623 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3791 "src-generated/ugbc.tab.c"
    break;

  case 158: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 626 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3799 "src-generated/ugbc.tab.c"
    break;

  case 159: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 629 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3807 "src-generated/ugbc.tab.c"
    break;

  case 160: /* color_definition_expression: BORDER expr  */
#line 634 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3815 "src-generated/ugbc.tab.c"
    break;

  case 161: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 637 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3823 "src-generated/ugbc.tab.c"
    break;

  case 162: /* color_definition_expression: SPRITE expr TO expr  */
#line 640 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3831 "src-generated/ugbc.tab.c"
    break;

  case 168: /* wait_definition_simple: direct_integer CYCLES  */
#line 654 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3839 "src-generated/ugbc.tab.c"
    break;

  case 169: /* wait_definition_simple: direct_integer TICKS  */
#line 657 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3847 "src-generated/ugbc.tab.c"
    break;

  case 170: /* wait_definition_simple: direct_integer milliseconds  */
#line 660 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3855 "src-generated/ugbc.tab.c"
    break;

  case 171: /* wait_definition_expression: expr CYCLES  */
#line 665 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3863 "src-generated/ugbc.tab.c"
    break;

  case 172: /* wait_definition_expression: expr TICKS  */
#line 668 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3871 "src-generated/ugbc.tab.c"
    break;

  case 173: /* wait_definition_expression: expr milliseconds  */
#line 671 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3879 "src-generated/ugbc.tab.c"
    break;

  case 176: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 681 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3887 "src-generated/ugbc.tab.c"
    break;

  case 177: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 684 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3895 "src-generated/ugbc.tab.c"
    break;

  case 178: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 687 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3903 "src-generated/ugbc.tab.c"
    break;

  case 179: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 690 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3911 "src-generated/ugbc.tab.c"
    break;

  case 180: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 693 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3919 "src-generated/ugbc.tab.c"
    break;

  case 181: /* sprite_definition_simple: direct_integer ENABLE  */
#line 696 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3927 "src-generated/ugbc.tab.c"
    break;

  case 182: /* sprite_definition_simple: direct_integer DISABLE  */
#line 699 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3935 "src-generated/ugbc.tab.c"
    break;

  case 183: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 702 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3943 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 705 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3951 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 708 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3959 "src-generated/ugbc.tab.c"
    break;

  case 186: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 711 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3967 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 714 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3975 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 717 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3983 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 720 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3991 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 723 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3999 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_expression: expr DATA FROM expr  */
#line 728 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4007 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_expression: expr MULTICOLOR  */
#line 731 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4015 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_expression: expr MONOCOLOR  */
#line 734 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4023 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_expression: expr COLOR expr  */
#line 737 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4031 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 740 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4039 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_expression: expr ENABLE  */
#line 743 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4047 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_expression: expr DISABLE  */
#line 746 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4055 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 749 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4063 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 752 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4071 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 755 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4079 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 758 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4087 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 761 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4095 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 764 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4103 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 767 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4111 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 770 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4119 "src-generated/ugbc.tab.c"
    break;

  case 208: /* bitmap_definition_simple: AT direct_integer  */
#line 779 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4127 "src-generated/ugbc.tab.c"
    break;

  case 209: /* bitmap_definition_simple: ENABLE  */
#line 782 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4135 "src-generated/ugbc.tab.c"
    break;

  case 210: /* bitmap_definition_simple: DISABLE  */
#line 785 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4143 "src-generated/ugbc.tab.c"
    break;

  case 211: /* bitmap_definition_simple: CLEAR  */
#line 788 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4151 "src-generated/ugbc.tab.c"
    break;

  case 212: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 791 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4159 "src-generated/ugbc.tab.c"
    break;

  case 213: /* bitmap_definition_expression: AT expr  */
#line 797 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4167 "src-generated/ugbc.tab.c"
    break;

  case 214: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 800 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4175 "src-generated/ugbc.tab.c"
    break;

  case 217: /* textmap_definition_simple: AT direct_integer  */
#line 810 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4183 "src-generated/ugbc.tab.c"
    break;

  case 218: /* textmap_definition_expression: AT expr  */
#line 815 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4191 "src-generated/ugbc.tab.c"
    break;

  case 221: /* text_definition_simple: ENABLE  */
#line 824 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4199 "src-generated/ugbc.tab.c"
    break;

  case 222: /* text_definition_simple: DISABLE  */
#line 827 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4207 "src-generated/ugbc.tab.c"
    break;

  case 223: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 832 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4215 "src-generated/ugbc.tab.c"
    break;

  case 224: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 835 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4223 "src-generated/ugbc.tab.c"
    break;

  case 227: /* tiles_definition_simple: AT direct_integer  */
#line 844 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4231 "src-generated/ugbc.tab.c"
    break;

  case 228: /* tiles_definition_expression: AT expr  */
#line 849 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4239 "src-generated/ugbc.tab.c"
    break;

  case 231: /* colormap_definition_simple: AT direct_integer  */
#line 858 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4247 "src-generated/ugbc.tab.c"
    break;

  case 232: /* colormap_definition_simple: CLEAR  */
#line 861 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4255 "src-generated/ugbc.tab.c"
    break;

  case 233: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 864 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4263 "src-generated/ugbc.tab.c"
    break;

  case 234: /* colormap_definition_expression: AT expr  */
#line 869 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4271 "src-generated/ugbc.tab.c"
    break;

  case 235: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 872 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4279 "src-generated/ugbc.tab.c"
    break;

  case 238: /* screen_definition_simple: ON  */
#line 882 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4287 "src-generated/ugbc.tab.c"
    break;

  case 239: /* screen_definition_simple: OFF  */
#line 885 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4295 "src-generated/ugbc.tab.c"
    break;

  case 240: /* screen_definition_simple: ROWS direct_integer  */
#line 888 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4303 "src-generated/ugbc.tab.c"
    break;

  case 241: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 891 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4311 "src-generated/ugbc.tab.c"
    break;

  case 242: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 894 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4319 "src-generated/ugbc.tab.c"
    break;

  case 243: /* screen_definition_expression: ROWS expr  */
#line 899 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4327 "src-generated/ugbc.tab.c"
    break;

  case 244: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 902 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4335 "src-generated/ugbc.tab.c"
    break;

  case 245: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 905 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4343 "src-generated/ugbc.tab.c"
    break;

  case 249: /* var_definition_simple: Identifier ON Identifier  */
#line 914 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4351 "src-generated/ugbc.tab.c"
    break;

  case 250: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 917 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4359 "src-generated/ugbc.tab.c"
    break;

  case 251: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 920 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4367 "src-generated/ugbc.tab.c"
    break;

  case 252: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 923 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4377 "src-generated/ugbc.tab.c"
    break;

  case 253: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 928 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4387 "src-generated/ugbc.tab.c"
    break;

  case 254: /* goto_definition: Identifier  */
#line 935 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4395 "src-generated/ugbc.tab.c"
    break;

  case 255: /* goto_definition: Integer  */
#line 938 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4403 "src-generated/ugbc.tab.c"
    break;

  case 256: /* gosub_definition: Identifier  */
#line 944 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4411 "src-generated/ugbc.tab.c"
    break;

  case 257: /* gosub_definition: Integer  */
#line 947 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4419 "src-generated/ugbc.tab.c"
    break;

  case 259: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 956 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4427 "src-generated/ugbc.tab.c"
    break;

  case 260: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 962 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4435 "src-generated/ugbc.tab.c"
    break;

  case 263: /* ink_definition: expr  */
#line 971 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4443 "src-generated/ugbc.tab.c"
    break;

  case 264: /* on_goto_definition: Identifier  */
#line 976 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4452 "src-generated/ugbc.tab.c"
    break;

  case 265: /* $@4: %empty  */
#line 980 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4460 "src-generated/ugbc.tab.c"
    break;

  case 267: /* on_gosub_definition: Identifier  */
#line 985 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4469 "src-generated/ugbc.tab.c"
    break;

  case 268: /* $@5: %empty  */
#line 989 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4477 "src-generated/ugbc.tab.c"
    break;

  case 270: /* on_proc_definition: Identifier  */
#line 994 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4486 "src-generated/ugbc.tab.c"
    break;

  case 271: /* $@6: %empty  */
#line 998 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4494 "src-generated/ugbc.tab.c"
    break;

  case 273: /* $@7: %empty  */
#line 1003 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4502 "src-generated/ugbc.tab.c"
    break;

  case 275: /* $@8: %empty  */
#line 1006 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4510 "src-generated/ugbc.tab.c"
    break;

  case 277: /* $@9: %empty  */
#line 1009 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4518 "src-generated/ugbc.tab.c"
    break;

  case 279: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1014 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4526 "src-generated/ugbc.tab.c"
    break;

  case 280: /* every_definition: ON  */
#line 1017 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4534 "src-generated/ugbc.tab.c"
    break;

  case 281: /* every_definition: OFF  */
#line 1020 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4542 "src-generated/ugbc.tab.c"
    break;

  case 282: /* add_definition: Identifier COMMA expr  */
#line 1025 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4550 "src-generated/ugbc.tab.c"
    break;

  case 283: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1028 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4558 "src-generated/ugbc.tab.c"
    break;

  case 284: /* dimensions: Integer  */
#line 1034 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4567 "src-generated/ugbc.tab.c"
    break;

  case 285: /* dimensions: Integer COMMA dimensions  */
#line 1038 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4576 "src-generated/ugbc.tab.c"
    break;

  case 286: /* datatype: BYTE  */
#line 1045 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 4584 "src-generated/ugbc.tab.c"
    break;

  case 287: /* datatype: SIGNED BYTE  */
#line 1048 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 4592 "src-generated/ugbc.tab.c"
    break;

  case 288: /* datatype: WORD  */
#line 1051 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 4600 "src-generated/ugbc.tab.c"
    break;

  case 289: /* datatype: SIGNED WORD  */
#line 1054 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 4608 "src-generated/ugbc.tab.c"
    break;

  case 290: /* datatype: DWORD  */
#line 1057 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 4616 "src-generated/ugbc.tab.c"
    break;

  case 291: /* datatype: SIGNED DWORD  */
#line 1060 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 4624 "src-generated/ugbc.tab.c"
    break;

  case 292: /* datatype: ADDRESS  */
#line 1063 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 4632 "src-generated/ugbc.tab.c"
    break;

  case 293: /* datatype: POSITION  */
#line 1066 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 4640 "src-generated/ugbc.tab.c"
    break;

  case 294: /* datatype: COLOR  */
#line 1069 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 4648 "src-generated/ugbc.tab.c"
    break;

  case 295: /* datatype: STRING  */
#line 1072 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 4656 "src-generated/ugbc.tab.c"
    break;

  case 296: /* $@10: %empty  */
#line 1077 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4665 "src-generated/ugbc.tab.c"
    break;

  case 297: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1080 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 4675 "src-generated/ugbc.tab.c"
    break;

  case 298: /* $@11: %empty  */
#line 1085 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4684 "src-generated/ugbc.tab.c"
    break;

  case 299: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1088 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 4694 "src-generated/ugbc.tab.c"
    break;

  case 300: /* $@12: %empty  */
#line 1093 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4703 "src-generated/ugbc.tab.c"
    break;

  case 301: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1096 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 4713 "src-generated/ugbc.tab.c"
    break;

  case 304: /* indexes: expr  */
#line 1109 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4722 "src-generated/ugbc.tab.c"
    break;

  case 305: /* indexes: expr COMMA indexes  */
#line 1113 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4731 "src-generated/ugbc.tab.c"
    break;

  case 306: /* parameters: Identifier  */
#line 1120 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4741 "src-generated/ugbc.tab.c"
    break;

  case 307: /* parameters: Identifier DOLLAR  */
#line 1125 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4751 "src-generated/ugbc.tab.c"
    break;

  case 308: /* parameters: Identifier AS datatype  */
#line 1130 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4761 "src-generated/ugbc.tab.c"
    break;

  case 309: /* parameters: Identifier COMMA parameters  */
#line 1135 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4771 "src-generated/ugbc.tab.c"
    break;

  case 310: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1140 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4781 "src-generated/ugbc.tab.c"
    break;

  case 311: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1145 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4791 "src-generated/ugbc.tab.c"
    break;

  case 312: /* parameters_expr: Identifier  */
#line 1153 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4801 "src-generated/ugbc.tab.c"
    break;

  case 313: /* parameters_expr: Identifier DOLLAR  */
#line 1158 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4811 "src-generated/ugbc.tab.c"
    break;

  case 314: /* parameters_expr: Identifier AS datatype  */
#line 1163 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4821 "src-generated/ugbc.tab.c"
    break;

  case 315: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1168 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4831 "src-generated/ugbc.tab.c"
    break;

  case 316: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1173 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4841 "src-generated/ugbc.tab.c"
    break;

  case 317: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1178 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4851 "src-generated/ugbc.tab.c"
    break;

  case 318: /* parameters_expr: String  */
#line 1183 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4860 "src-generated/ugbc.tab.c"
    break;

  case 319: /* parameters_expr: String COMMA parameters_expr  */
#line 1187 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4869 "src-generated/ugbc.tab.c"
    break;

  case 320: /* values: expr  */
#line 1194 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4878 "src-generated/ugbc.tab.c"
    break;

  case 321: /* values: expr COMMA values  */
#line 1198 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4887 "src-generated/ugbc.tab.c"
    break;

  case 338: /* statement: INC Identifier  */
#line 1221 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 4895 "src-generated/ugbc.tab.c"
    break;

  case 339: /* statement: DEC Identifier  */
#line 1224 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 4903 "src-generated/ugbc.tab.c"
    break;

  case 340: /* statement: RANDOMIZE  */
#line 1227 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 4911 "src-generated/ugbc.tab.c"
    break;

  case 341: /* statement: RANDOMIZE expr  */
#line 1230 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 4919 "src-generated/ugbc.tab.c"
    break;

  case 342: /* statement: IF expr THEN  */
#line 1233 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4927 "src-generated/ugbc.tab.c"
    break;

  case 343: /* statement: ELSE  */
#line 1236 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 4935 "src-generated/ugbc.tab.c"
    break;

  case 344: /* statement: ELSE IF expr THEN  */
#line 1239 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4943 "src-generated/ugbc.tab.c"
    break;

  case 345: /* statement: ENDIF  */
#line 1242 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 4951 "src-generated/ugbc.tab.c"
    break;

  case 346: /* statement: DO  */
#line 1245 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 4959 "src-generated/ugbc.tab.c"
    break;

  case 347: /* statement: LOOP  */
#line 1248 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 4967 "src-generated/ugbc.tab.c"
    break;

  case 348: /* $@13: %empty  */
#line 1251 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 4975 "src-generated/ugbc.tab.c"
    break;

  case 349: /* statement: WHILE $@13 expr  */
#line 1253 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 4983 "src-generated/ugbc.tab.c"
    break;

  case 350: /* statement: WEND  */
#line 1256 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 4991 "src-generated/ugbc.tab.c"
    break;

  case 351: /* statement: REPEAT  */
#line 1259 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 4999 "src-generated/ugbc.tab.c"
    break;

  case 352: /* statement: UNTIL expr  */
#line 1262 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5007 "src-generated/ugbc.tab.c"
    break;

  case 353: /* statement: EXIT  */
#line 1265 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5015 "src-generated/ugbc.tab.c"
    break;

  case 354: /* statement: EXIT PROC  */
#line 1268 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5023 "src-generated/ugbc.tab.c"
    break;

  case 355: /* statement: POP PROC  */
#line 1271 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5031 "src-generated/ugbc.tab.c"
    break;

  case 356: /* statement: EXIT IF expr  */
#line 1274 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5039 "src-generated/ugbc.tab.c"
    break;

  case 357: /* statement: EXIT Integer  */
#line 1277 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5047 "src-generated/ugbc.tab.c"
    break;

  case 358: /* statement: EXIT direct_integer  */
#line 1280 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5055 "src-generated/ugbc.tab.c"
    break;

  case 359: /* statement: EXIT IF expr COMMA Integer  */
#line 1283 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5063 "src-generated/ugbc.tab.c"
    break;

  case 360: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1286 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5071 "src-generated/ugbc.tab.c"
    break;

  case 361: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1289 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5079 "src-generated/ugbc.tab.c"
    break;

  case 362: /* statement: NEXT  */
#line 1292 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5087 "src-generated/ugbc.tab.c"
    break;

  case 363: /* statement: PROCEDURE Identifier  */
#line 1295 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5096 "src-generated/ugbc.tab.c"
    break;

  case 364: /* $@14: %empty  */
#line 1299 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5104 "src-generated/ugbc.tab.c"
    break;

  case 365: /* statement: PROCEDURE Identifier $@14 OSP parameters CSP  */
#line 1301 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5112 "src-generated/ugbc.tab.c"
    break;

  case 366: /* statement: SHARED parameters_expr  */
#line 1304 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5120 "src-generated/ugbc.tab.c"
    break;

  case 367: /* statement: GLOBAL parameters_expr  */
#line 1307 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5128 "src-generated/ugbc.tab.c"
    break;

  case 368: /* statement: END PROC  */
#line 1310 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 5136 "src-generated/ugbc.tab.c"
    break;

  case 369: /* statement: END PROC OSP expr CSP  */
#line 1313 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5144 "src-generated/ugbc.tab.c"
    break;

  case 370: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1316 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5152 "src-generated/ugbc.tab.c"
    break;

  case 371: /* statement: Identifier " "  */
#line 1319 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5161 "src-generated/ugbc.tab.c"
    break;

  case 372: /* statement: PROC Identifier  */
#line 1323 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5170 "src-generated/ugbc.tab.c"
    break;

  case 373: /* statement: CALL Identifier  */
#line 1327 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5179 "src-generated/ugbc.tab.c"
    break;

  case 374: /* $@15: %empty  */
#line 1331 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5187 "src-generated/ugbc.tab.c"
    break;

  case 375: /* statement: Identifier OSP $@15 values CSP  */
#line 1333 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5195 "src-generated/ugbc.tab.c"
    break;

  case 376: /* $@16: %empty  */
#line 1336 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5203 "src-generated/ugbc.tab.c"
    break;

  case 377: /* statement: PROC Identifier OSP $@16 values CSP  */
#line 1338 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5211 "src-generated/ugbc.tab.c"
    break;

  case 378: /* $@17: %empty  */
#line 1341 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5219 "src-generated/ugbc.tab.c"
    break;

  case 379: /* statement: CALL Identifier OSP $@17 values CSP  */
#line 1343 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5227 "src-generated/ugbc.tab.c"
    break;

  case 380: /* statement: Identifier COLON  */
#line 1346 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 5235 "src-generated/ugbc.tab.c"
    break;

  case 381: /* statement: BEG GAMELOOP  */
#line 1349 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 5243 "src-generated/ugbc.tab.c"
    break;

  case 382: /* statement: END GAMELOOP  */
#line 1352 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 5251 "src-generated/ugbc.tab.c"
    break;

  case 383: /* statement: GRAPHIC  */
#line 1355 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 5259 "src-generated/ugbc.tab.c"
    break;

  case 384: /* statement: HALT  */
#line 1358 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 5267 "src-generated/ugbc.tab.c"
    break;

  case 385: /* statement: END  */
#line 1361 "src/ugbc.y"
        {
      end( _environment );
  }
#line 5275 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: RETURN  */
#line 1368 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 5283 "src-generated/ugbc.tab.c"
    break;

  case 391: /* statement: RETURN expr  */
#line 1371 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 5291 "src-generated/ugbc.tab.c"
    break;

  case 392: /* statement: POP  */
#line 1374 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 5299 "src-generated/ugbc.tab.c"
    break;

  case 393: /* statement: DONE  */
#line 1377 "src/ugbc.y"
          {
      return 0;
  }
#line 5307 "src-generated/ugbc.tab.c"
    break;

  case 394: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1380 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5315 "src-generated/ugbc.tab.c"
    break;

  case 395: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1383 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5323 "src-generated/ugbc.tab.c"
    break;

  case 396: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1386 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 5331 "src-generated/ugbc.tab.c"
    break;

  case 397: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1389 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5339 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: Identifier ASSIGN expr  */
#line 1393 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 5353 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1402 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 5367 "src-generated/ugbc.tab.c"
    break;

  case 401: /* $@18: %empty  */
#line 1411 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5376 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: Identifier $@18 OP indexes CP ASSIGN expr  */
#line 1415 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 5389 "src-generated/ugbc.tab.c"
    break;

  case 403: /* $@19: %empty  */
#line 1423 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5398 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: Identifier DOLLAR $@19 OP indexes CP ASSIGN expr  */
#line 1426 "src/ugbc.y"
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
#line 5417 "src-generated/ugbc.tab.c"
    break;

  case 405: /* $@20: %empty  */
#line 1440 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5426 "src-generated/ugbc.tab.c"
    break;

  case 406: /* statement: Identifier $@20 datatype OP indexes CP ASSIGN expr  */
#line 1443 "src/ugbc.y"
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
#line 5445 "src-generated/ugbc.tab.c"
    break;

  case 407: /* statement: DEBUG expr  */
#line 1457 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 5453 "src-generated/ugbc.tab.c"
    break;

  case 410: /* statements_no_linenumbers: statement  */
#line 1465 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 5459 "src-generated/ugbc.tab.c"
    break;

  case 411: /* $@21: %empty  */
#line 1466 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 5465 "src-generated/ugbc.tab.c"
    break;

  case 413: /* $@22: %empty  */
#line 1470 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 5473 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statements_with_linenumbers: Integer $@22 statements_no_linenumbers  */
#line 1472 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 5481 "src-generated/ugbc.tab.c"
    break;

  case 415: /* $@23: %empty  */
#line 1477 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 5489 "src-generated/ugbc.tab.c"
    break;

  case 421: /* $@24: %empty  */
#line 1487 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 5495 "src-generated/ugbc.tab.c"
    break;


#line 5499 "src-generated/ugbc.tab.c"

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

#line 1489 "src/ugbc.y"


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

