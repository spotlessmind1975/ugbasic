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
  YYSYMBOL_REPLACE = 162,                  /* REPLACE  */
  YYSYMBOL_XOR = 163,                      /* XOR  */
  YYSYMBOL_IGNORE = 164,                   /* IGNORE  */
  YYSYMBOL_NORMAL = 165,                   /* NORMAL  */
  YYSYMBOL_WRITING = 166,                  /* WRITING  */
  YYSYMBOL_ONLY = 167,                     /* ONLY  */
  YYSYMBOL_LOCATE = 168,                   /* LOCATE  */
  YYSYMBOL_CLS = 169,                      /* CLS  */
  YYSYMBOL_HOME = 170,                     /* HOME  */
  YYSYMBOL_CMOVE = 171,                    /* CMOVE  */
  YYSYMBOL_BLACK = 172,                    /* BLACK  */
  YYSYMBOL_WHITE = 173,                    /* WHITE  */
  YYSYMBOL_RED = 174,                      /* RED  */
  YYSYMBOL_CYAN = 175,                     /* CYAN  */
  YYSYMBOL_VIOLET = 176,                   /* VIOLET  */
  YYSYMBOL_GREEN = 177,                    /* GREEN  */
  YYSYMBOL_BLUE = 178,                     /* BLUE  */
  YYSYMBOL_YELLOW = 179,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 180,                   /* ORANGE  */
  YYSYMBOL_BROWN = 181,                    /* BROWN  */
  YYSYMBOL_LIGHT = 182,                    /* LIGHT  */
  YYSYMBOL_DARK = 183,                     /* DARK  */
  YYSYMBOL_GREY = 184,                     /* GREY  */
  YYSYMBOL_GRAY = 185,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 186,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 187,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 188,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 189,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 190,                /* TURQUOISE  */
  YYSYMBOL_TAN = 191,                      /* TAN  */
  YYSYMBOL_PINK = 192,                     /* PINK  */
  YYSYMBOL_PEACH = 193,                    /* PEACH  */
  YYSYMBOL_OLIVE = 194,                    /* OLIVE  */
  YYSYMBOL_Identifier = 195,               /* Identifier  */
  YYSYMBOL_String = 196,                   /* String  */
  YYSYMBOL_Integer = 197,                  /* Integer  */
  YYSYMBOL_198_ = 198,                     /* " "  */
  YYSYMBOL_YYACCEPT = 199,                 /* $accept  */
  YYSYMBOL_expr = 200,                     /* expr  */
  YYSYMBOL_expr_math = 201,                /* expr_math  */
  YYSYMBOL_term = 202,                     /* term  */
  YYSYMBOL_modula = 203,                   /* modula  */
  YYSYMBOL_factor = 204,                   /* factor  */
  YYSYMBOL_direct_integer = 205,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 206, /* random_definition_simple  */
  YYSYMBOL_random_definition = 207,        /* random_definition  */
  YYSYMBOL_color_enumeration = 208,        /* color_enumeration  */
  YYSYMBOL_exponential = 209,              /* exponential  */
  YYSYMBOL_210_1 = 210,                    /* $@1  */
  YYSYMBOL_211_2 = 211,                    /* $@2  */
  YYSYMBOL_212_3 = 212,                    /* $@3  */
  YYSYMBOL_position = 213,                 /* position  */
  YYSYMBOL_bank_definition_simple = 214,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 215, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 216,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 217, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 218, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 219,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 220, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 221, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 222,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 223,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 224, /* color_definition_expression  */
  YYSYMBOL_color_definition = 225,         /* color_definition  */
  YYSYMBOL_milliseconds = 226,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 227,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 228, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 229,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 230, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 231, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 232,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 233, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 234, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 235,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 236, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 237, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 238,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 239,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 240, /* text_definition_expression  */
  YYSYMBOL_text_definition = 241,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 242,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 243, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 244,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 245, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 246, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 247,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 248, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 249, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 250,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 251,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 252,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 253,         /* gosub_definition  */
  YYSYMBOL_var_definition = 254,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 255,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 256, /* point_definition_expression  */
  YYSYMBOL_point_definition = 257,         /* point_definition  */
  YYSYMBOL_ink_definition = 258,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 259,       /* on_goto_definition  */
  YYSYMBOL_260_4 = 260,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 261,      /* on_gosub_definition  */
  YYSYMBOL_262_5 = 262,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 263,       /* on_proc_definition  */
  YYSYMBOL_264_6 = 264,                    /* $@6  */
  YYSYMBOL_on_definition = 265,            /* on_definition  */
  YYSYMBOL_266_7 = 266,                    /* $@7  */
  YYSYMBOL_267_8 = 267,                    /* $@8  */
  YYSYMBOL_268_9 = 268,                    /* $@9  */
  YYSYMBOL_every_definition = 269,         /* every_definition  */
  YYSYMBOL_add_definition = 270,           /* add_definition  */
  YYSYMBOL_dimensions = 271,               /* dimensions  */
  YYSYMBOL_datatype = 272,                 /* datatype  */
  YYSYMBOL_dim_definition = 273,           /* dim_definition  */
  YYSYMBOL_274_10 = 274,                   /* $@10  */
  YYSYMBOL_275_11 = 275,                   /* $@11  */
  YYSYMBOL_276_12 = 276,                   /* $@12  */
  YYSYMBOL_dim_definitions = 277,          /* dim_definitions  */
  YYSYMBOL_indexes = 278,                  /* indexes  */
  YYSYMBOL_parameters = 279,               /* parameters  */
  YYSYMBOL_parameters_expr = 280,          /* parameters_expr  */
  YYSYMBOL_values = 281,                   /* values  */
  YYSYMBOL_print_definition = 282,         /* print_definition  */
  YYSYMBOL_283_13 = 283,                   /* $@13  */
  YYSYMBOL_284_14 = 284,                   /* $@14  */
  YYSYMBOL_use_definition = 285,           /* use_definition  */
  YYSYMBOL_writing_mode_definition = 286,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 287,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 288,       /* writing_definition  */
  YYSYMBOL_locate_definition = 289,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 290,         /* cmove_definition  */
  YYSYMBOL_statement = 291,                /* statement  */
  YYSYMBOL_292_15 = 292,                   /* $@15  */
  YYSYMBOL_293_16 = 293,                   /* $@16  */
  YYSYMBOL_294_17 = 294,                   /* $@17  */
  YYSYMBOL_295_18 = 295,                   /* $@18  */
  YYSYMBOL_296_19 = 296,                   /* $@19  */
  YYSYMBOL_297_20 = 297,                   /* $@20  */
  YYSYMBOL_298_21 = 298,                   /* $@21  */
  YYSYMBOL_299_22 = 299,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 300, /* statements_no_linenumbers  */
  YYSYMBOL_301_23 = 301,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 302, /* statements_with_linenumbers  */
  YYSYMBOL_303_24 = 303,                   /* $@24  */
  YYSYMBOL_statements_complex = 304,       /* statements_complex  */
  YYSYMBOL_305_25 = 305,                   /* $@25  */
  YYSYMBOL_program = 306,                  /* program  */
  YYSYMBOL_307_26 = 307                    /* $@26  */
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
#define YYLAST   2744

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  199
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  467
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  891

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   453


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
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    75,    79,    83,    86,    89,    92,    95,
      98,   101,   107,   108,   111,   118,   119,   123,   124,   128,
     135,   136,   140,   147,   152,   155,   158,   161,   164,   167,
     170,   175,   180,   184,   188,   192,   196,   200,   204,   208,
     212,   216,   220,   224,   228,   232,   236,   240,   244,   248,
     252,   256,   260,   264,   268,   272,   276,   280,   284,   290,
     290,   301,   301,   312,   315,   318,   327,   331,   338,   342,
     346,   350,   354,   358,   362,   366,   370,   373,   376,   379,
     382,   385,   388,   391,   394,   397,   400,   403,   406,   409,
     412,   415,   418,   421,   424,   427,   430,   433,   436,   439,
     442,   445,   448,   451,   454,   457,   460,   463,   466,   466,
     472,   475,   478,   482,   486,   490,   494,   498,   502,   506,
     510,   514,   517,   520,   523,   526,   531,   531,   534,   537,
     540,   543,   546,   549,   553,   556,   559,   562,   566,   569,
     572,   575,   579,   582,   585,   588,   594,   597,   600,   603,
     606,   611,   612,   615,   618,   623,   626,   631,   632,   635,
     638,   643,   646,   651,   652,   655,   658,   661,   666,   669,
     672,   677,   678,   681,   682,   683,   686,   689,   692,   697,
     700,   703,   709,   710,   713,   716,   719,   722,   725,   728,
     731,   734,   737,   740,   743,   746,   749,   752,   755,   760,
     763,   766,   769,   772,   775,   778,   781,   784,   787,   790,
     793,   796,   799,   802,   807,   808,   811,   814,   817,   820,
     823,   829,   832,   838,   839,   842,   847,   852,   853,   856,
     859,   864,   867,   872,   873,   876,   881,   886,   887,   890,
     893,   896,   901,   904,   910,   911,   914,   917,   920,   923,
     926,   931,   934,   937,   942,   943,   945,   946,   949,   952,
     955,   960,   967,   970,   976,   979,   985,   988,   994,   999,
    1000,  1003,  1008,  1012,  1012,  1017,  1021,  1021,  1026,  1030,
    1030,  1035,  1035,  1038,  1038,  1041,  1041,  1046,  1049,  1052,
    1057,  1060,  1066,  1070,  1077,  1080,  1083,  1086,  1089,  1092,
    1095,  1098,  1101,  1104,  1109,  1109,  1117,  1117,  1125,  1125,
    1136,  1137,  1141,  1145,  1152,  1157,  1162,  1167,  1172,  1177,
    1185,  1190,  1195,  1200,  1205,  1210,  1215,  1219,  1226,  1230,
    1237,  1240,  1244,  1247,  1247,  1251,  1251,  1257,  1260,  1266,
    1270,  1274,  1278,  1282,  1289,  1293,  1297,  1301,  1305,  1312,
    1318,  1321,  1324,  1330,  1333,  1336,  1342,  1343,  1344,  1345,
    1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,
    1356,  1357,  1358,  1359,  1360,  1361,  1364,  1367,  1370,  1373,
    1376,  1379,  1382,  1385,  1388,  1391,  1394,  1397,  1397,  1402,
    1405,  1408,  1411,  1414,  1417,  1420,  1423,  1426,  1429,  1432,
    1435,  1438,  1441,  1445,  1445,  1450,  1453,  1456,  1459,  1462,
    1465,  1469,  1473,  1477,  1477,  1482,  1482,  1487,  1487,  1492,
    1495,  1498,  1501,  1504,  1505,  1508,  1511,  1514,  1517,  1520,
    1523,  1524,  1525,  1526,  1527,  1530,  1533,  1536,  1539,  1542,
    1545,  1548,  1551,  1552,  1553,  1562,  1571,  1571,  1583,  1583,
    1600,  1600,  1617,  1620,  1621,  1625,  1626,  1626,  1630,  1630,
    1637,  1637,  1640,  1641,  1642,  1643,  1647,  1647
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
  "INVERSE", "REPLACE", "XOR", "IGNORE", "NORMAL", "WRITING", "ONLY",
  "LOCATE", "CLS", "HOME", "CMOVE", "BLACK", "WHITE", "RED", "CYAN",
  "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE", "BROWN", "LIGHT", "DARK",
  "GREY", "GRAY", "MAGENTA", "PURPLE", "LAVENDER", "GOLD", "TURQUOISE",
  "TAN", "PINK", "PEACH", "OLIVE", "Identifier", "String", "Integer",
  "\" \"", "$accept", "expr", "expr_math", "term", "modula", "factor",
  "direct_integer", "random_definition_simple", "random_definition",
  "color_enumeration", "exponential", "$@1", "$@2", "$@3", "position",
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
  "on_goto_definition", "$@4", "on_gosub_definition", "$@5",
  "on_proc_definition", "$@6", "on_definition", "$@7", "$@8", "$@9",
  "every_definition", "add_definition", "dimensions", "datatype",
  "dim_definition", "$@10", "$@11", "$@12", "dim_definitions", "indexes",
  "parameters", "parameters_expr", "values", "print_definition", "$@13",
  "$@14", "use_definition", "writing_mode_definition",
  "writing_part_definition", "writing_definition", "locate_definition",
  "cmove_definition", "statement", "$@15", "$@16", "$@17", "$@18", "$@19",
  "$@20", "$@21", "$@22", "statements_no_linenumbers", "$@23",
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
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453
};
#endif

#define YYPACT_NINF (-751)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-447)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -751,    66,   849,  -751,  -751,  -144,   -91,   -13,  -751,    30,
    2019,   109,     1,  2019,  -751,    49,   198,  2195,   -75,    51,
    -751,  -751,  -751,  1667,   114,    20,  2195,  2195,    90,   -47,
    -751,   151,   161,  2195,  2195,  -751,   174,   178,    68,  2195,
      69,   163,  -751,   -41,  -751,  2195,    43,  1843,   246,    95,
    2195,    97,   103,   105,   106,  -112,  -112,  2195,   100,  2195,
     179,   -17,  1124,  -751,  -751,  1315,    26,  -751,   247,   287,
     289,  -751,  -751,  -751,  2019,   271,  -751,  -751,  -751,  2019,
    2019,  2019,  -751,  -751,  -751,   110,  1491,  -751,  -751,   263,
     269,   274,    84,   112,  -751,  -751,    -6,   276,   288,  2195,
    -751,  -751,   306,   307,   310,   311,   312,   313,   314,   315,
     317,   319,   322,   323,   324,   325,   326,   327,   328,  -751,
    -751,   330,   117,   -44,     6,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,   175,  -751,  -751,    77,    36,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,   188,    14,  -751,  -751,
     -26,   191,   236,   228,   238,   -22,  -751,  -751,  -751,  -751,
    -751,   -12,   286,    -9,    -4,    -3,    -2,   345,  -751,  -751,
    -751,   318,   355,  -751,  -751,  -751,  2019,  -751,  -751,   341,
    -751,  -751,  -751,  -751,  -751,  2019,   331,   332,  -751,  -751,
    -751,   -25,  -751,    48,  -751,  -751,  -751,  -751,  -751,  2195,
    2195,  -751,  -751,   364,  -751,  -751,  -751,  2019,  -751,  -751,
    -751,  2019,   347,  -751,  -751,  -751,   316,  -751,  -751,  -751,
     234,  2195,  2195,  -751,  -751,  2019,  -751,  -751,  -751,   352,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  2195,  2195,
    -751,  -751,  -751,  -751,   380,  -751,  -751,   243,  -751,  2195,
     389,  -751,  -751,  -751,   102,   390,  -751,   252,   254,   255,
      75,   396,  -751,  -751,   259,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,   397,  -751,  2195,
     398,  -751,  2195,   399,  -751,  -751,  -751,  2195,   394,  -751,
    -751,   374,   159,  1011,  -751,   849,   849,   381,   384,  2019,
    -751,  -751,   342,   343,   344,   346,  -751,   382,   387,   395,
     401,   402,    96,   403,  2019,  2019,  2019,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,   385,  -751,  -751,
    2195,  2195,  -751,  2195,  2195,  2195,  2195,  2195,  2195,  2195,
    2195,  2195,  2195,  2195,  2195,  2195,  2195,  2195,  2195,  2195,
    2371,   400,   229,  -751,  -751,   405,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,   407,  -751,   409,  -751,
    -751,  -751,  -751,  -751,  -751,  2371,  2371,  2371,  2371,  2371,
    2371,  2371,  2371,  2371,  2371,  2371,  2371,  2371,  2547,  -751,
    -751,  -751,  2019,   408,  -751,  -751,  -751,   404,   286,   420,
     286,   421,   286,   422,   286,   424,   286,  -751,  2195,   416,
    -751,  -751,   211,   214,    60,    98,  -751,  -751,  -751,   417,
     286,   423,  -751,  -751,   217,   219,   120,   134,  -751,  -751,
     425,  -751,  -751,  2019,  -751,  -751,  2019,  2019,  -751,  -751,
    -751,   391,   260,  -751,   447,  2195,  -751,  -751,  -751,  -751,
    2019,  -751,  2195,   450,   451,  -751,  -751,  2019,   360,   453,
    2195,   359,   455,  2195,  -751,  -751,  -751,  -751,  -751,  -751,
     142,  -751,  -751,   429,   444,    97,  -751,   320,  -751,  -112,
     458,   159,  -112,   226,   256,   -50,  -751,  2195,  -751,  2195,
     849,  -751,  2195,   434,  2195,  2195,   435,    25,  -751,  1011,
    -751,  -751,   275,   278,  -751,  -751,  2195,   286,  2195,   286,
     284,   290,   291,   292,   293,   436,   440,   448,  -751,   456,
     457,   460,   462,   464,   465,  2195,   478,   479,   486,   494,
     467,   468,   469,   470,   499,   473,   474,   477,   481,   482,
     506,   507,   483,   484,   485,    11,   333,   487,  2195,   489,
    2195,  2195,   236,   236,   270,   270,   270,   270,   270,   270,
     270,   270,   228,   238,   238,  -751,   492,   496,  2019,    64,
    -751,   286,  -751,   286,  -751,   286,  -751,   286,    52,  -751,
    2195,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  2195,
    -751,   286,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
     286,  -751,  -751,  -751,  -751,  -751,  -751,   334,   335,   338,
     339,   513,  2195,   520,   493,   495,   388,  2195,  2195,   532,
     534,  -751,   -63,   471,   349,  2195,   535,  -751,  -751,  -751,
     511,   350,   512,  -751,  2195,   353,  2195,  -751,  -112,   542,
    -751,  2195,  2195,   383,   386,  -751,  -751,  -751,  -751,  -751,
    -751,  2195,   544,   406,   545,   521,  2195,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,   358,
     362,   363,  -751,  -751,  -751,  -751,  -751,  -751,   522,  2195,
    2195,  2195,  2195,  -751,  -751,  -751,  -751,  2195,  -751,  -751,
    -751,  -751,  -751,  2195,  2195,  -751,  -751,  -751,  2547,   526,
    -751,   527,  2195,   415,   529,   370,   371,  -751,  -751,  -751,
    -751,  -751,  -751,   538,  -751,   539,  -751,   373,    86,  -751,
     564,  -751,   565,   566,  -751,   567,  -751,   568,  -751,   563,
    2019,   570,  2195,  2195,   286,  -751,   543,   547,  2195,   286,
    -751,  -751,  2195,  -751,    56,  2195,   350,   573,   550,   350,
     438,   101,   439,   441,  -751,  -112,  -751,  -751,  -751,  -751,
     553,  2195,  -751,  2195,   577,   556,  -751,  -751,  -751,  -751,
     557,   558,    58,    67,   559,   560,   561,   562,  -751,  -751,
     569,  -751,  -751,  -751,  -751,   410,   413,  -751,   571,  -751,
     572,  -751,  2195,   286,   591,   592,   596,  2195,  -751,  -751,
    2195,  -751,  -751,  -751,   597,   598,   578,   579,   490,  2195,
     599,   546,   581,   350,  -751,   582,  -751,   353,   612,   159,
    -751,  -751,  -751,   607,  -751,  -751,  2195,   608,  -751,  -751,
    2195,  -751,  2195,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,   426,   427,   590,   593,   334,   335,   338,  -751,  -751,
    2195,  2195,  -751,  -751,  2195,   594,  2195,  2195,  -751,  -751,
    -751,  -751,   353,   620,  2195,  -751,  2195,   595,   600,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,   621,
    -751,  -751,  -751,   353,  -751,  -751,  -751,  -751,  2195,  -751,
    -751
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     466,     0,   454,     1,   453,     0,     0,     0,   437,     0,
       0,   401,     0,     0,   428,     0,     0,     0,   256,     0,
     386,   390,   387,     0,     0,     0,     0,     0,     0,   429,
     384,     0,     0,     0,   379,   427,     0,     0,     0,   434,
     436,   382,   385,   392,   389,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   375,   376,     0,   450,   458,   455,   462,
     464,   467,   377,   378,     0,     0,   157,   158,   357,     0,
       0,     0,   171,   172,   359,     0,     0,    79,    80,     0,
       0,     0,     0,     0,   121,   122,     0,     0,     0,     0,
     112,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     123,     0,     0,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,    44,    49,    50,
      51,    52,    53,    54,    57,    58,     0,    63,    67,    65,
       0,     2,    12,    15,    17,     0,    76,    20,   182,   183,
     360,     0,     0,     0,     0,     0,     0,     0,   151,   152,
     356,     0,     0,   214,   215,   361,     0,   217,   218,   219,
     223,   224,   362,   246,   247,     0,     0,     0,   254,   255,
     367,     0,   430,     0,   266,   370,   262,   263,   431,     0,
       0,   229,   230,     0,   233,   234,   364,     0,   237,   238,
     365,     0,   240,   244,   245,   366,     0,   419,   425,   426,
     407,     0,     0,   452,   380,     0,   227,   228,   363,     0,
     269,   270,   368,   264,   265,   432,   435,   394,     0,     0,
     393,   396,   397,   391,     0,   288,   289,     0,   433,     0,
       0,   371,   271,   369,   304,   310,   442,   411,   402,   412,
     320,   326,   405,   406,   330,   372,   338,   337,   443,   420,
     421,   422,   342,   340,   339,   341,   343,     0,   423,     0,
       0,   373,     0,     0,   374,   460,   424,     0,   448,   413,
     410,     0,     0,   454,   456,   454,   454,     0,     0,     0,
     168,   165,     0,     0,     0,     0,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    24,    25,
      27,    29,    30,    26,    31,   101,    23,     0,   115,   116,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   117,   120,     0,   118,   119,    55,    42,
      45,    46,    47,    48,    43,    56,    64,   108,     0,   173,
     179,   174,   175,   180,   181,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   176,
     177,   178,     0,     0,   163,   164,   358,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
     204,   205,     0,     0,     0,     0,   201,   200,   126,     0,
       0,     0,   189,   190,     0,     0,     0,     0,   186,   185,
       0,   221,   216,     0,   251,   248,     0,     0,   281,   285,
     283,     0,     0,   388,     0,     0,   236,   235,   242,   239,
       0,   381,     0,     0,     0,   226,   225,     0,     0,   395,
       0,     0,     0,     0,   302,   294,   296,   301,   298,   303,
       0,   300,   308,     0,     0,     0,   415,     0,   417,     0,
     321,     0,     0,   335,   333,     0,   350,   351,   353,   354,
     454,   444,     0,     0,     0,     0,     0,   450,   459,   454,
     463,   465,     0,     0,   155,   153,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    14,     5,     7,     8,     9,    10,     6,
       3,     4,    16,    18,    19,    21,     0,     0,     0,     0,
     133,     0,   145,     0,   137,     0,   141,     0,   129,   202,
       0,   209,   208,   213,   212,   207,   211,   206,   210,     0,
     187,     0,   194,   193,   198,   197,   192,   196,   191,   195,
       0,   222,   220,   252,   249,   253,   250,     0,     0,     0,
       0,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   383,     0,     0,     0,     0,   290,   295,   297,   299,
       0,     0,     0,   311,     0,     0,     0,   323,     0,   322,
     327,     0,     0,   347,   345,   344,   349,   352,   355,   461,
     445,     0,   328,     0,   312,     0,     0,   457,   156,   154,
     170,   167,   169,   166,    75,    68,    70,    74,    72,     0,
       0,     0,    78,    77,    82,    81,    84,    83,     0,     0,
       0,     0,     0,    91,    92,    93,   100,     0,    94,    95,
      96,    97,    98,     0,     0,   110,   111,   102,     0,     0,
     106,     0,     0,     0,     0,     0,     0,   161,   159,   130,
     143,   135,   138,   132,   144,   136,   140,     0,     0,   199,
       0,   184,     0,   272,   282,   275,   286,   278,   284,   258,
       0,     0,     0,     0,     0,   408,     0,     0,     0,     0,
     398,   399,     0,   287,     0,     0,     0,   292,     0,     0,
       0,   314,     0,     0,   324,     0,   336,   334,   348,   346,
       0,     0,   414,     0,     0,     0,    69,    71,    73,   124,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   125,
       0,   109,    60,   162,   160,     0,     0,   146,   131,   142,
     134,   139,     0,     0,     0,     0,     0,     0,   260,   259,
       0,   232,   243,   241,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,   305,     0,   416,     0,   315,     0,
     404,   418,   325,     0,   329,   313,     0,     0,    85,    86,
       0,    87,     0,    89,    99,   105,   104,    22,    62,   148,
     150,     0,     0,     0,     0,     0,     0,     0,   261,   231,
       0,     0,   268,   267,     0,     0,     0,     0,   309,   293,
     307,   317,     0,   316,     0,   447,     0,     0,     0,   147,
     149,   203,   188,   274,   277,   280,   438,   439,   409,     0,
     440,   291,   318,     0,   449,   451,    88,    90,     0,   319,
     441
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -751,   -10,   -65,   -92,   248,  -288,    74,  -751,  -751,  -751,
    -387,  -751,  -751,  -751,   466,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,   488,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -209,  -751,  -207,  -751,  -210,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -674,  -287,  -751,  -751,  -751,  -751,   165,  -545,
    -750,   -54,  -542,  -355,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,  -751,
    -751,  -289,  -751,  -751,  -751,  -286,  -751,  -751,  -751
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   654,   151,   152,   153,   154,   155,   324,   325,   156,
     157,   368,   549,   550,   419,   168,   169,   170,    76,    77,
      78,   394,   395,   396,    82,    83,    84,   374,   158,   159,
     160,   173,   174,   175,   180,   181,   182,   226,   227,   228,
     204,   205,   206,   208,   209,   210,   213,   214,   215,   188,
     189,   190,   194,   198,   235,   195,   230,   231,   232,   253,
     724,   794,   726,   795,   728,   796,   192,   607,   609,   608,
     248,   251,   748,   472,   255,   473,   474,   630,   256,   655,
     752,   262,   653,   265,   642,   641,   268,   277,   646,   278,
     281,   284,    68,   199,   477,   494,   634,   636,   291,   493,
     292,    69,   499,    70,   293,    71,   490,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     150,   565,   263,   171,   498,   496,   704,   191,   703,   500,
     501,    74,   392,   203,   327,   398,   216,   217,   698,    93,
     400,   402,   404,   223,   224,   162,   355,   239,   438,   236,
     285,   286,   286,   163,   366,   243,   643,   247,   287,   287,
     252,    93,   353,   219,   211,   288,   288,   264,   -59,   269,
     164,    72,   280,   369,   370,   283,    79,   369,   389,  -446,
    -446,    80,   545,   809,   297,   830,     3,   861,   441,   300,
     302,   304,   812,   176,   832,   815,   313,   439,   165,   166,
     272,   717,   479,   260,   261,   177,   178,   172,   273,   332,
     442,   810,   750,   831,   753,   480,   709,   220,   563,   564,
     718,    81,   833,   240,    73,   585,   760,   212,   817,   317,
     644,   765,   882,   710,   586,   645,   354,   242,   788,   440,
     193,   818,  -306,   481,   371,   372,   373,   464,   371,   372,
     390,   161,   328,   889,   740,   789,   179,   351,   207,   859,
     388,   711,   712,   587,   356,   274,   275,   276,   298,   819,
     329,   352,   588,   301,   303,   305,   241,   780,   318,   319,
     320,   367,   357,   790,   791,   596,   431,   321,   322,   323,
     515,   516,   289,   289,   597,   434,   465,   466,   467,   598,
     218,   517,    75,   393,   464,   221,   399,   468,   599,   443,
     444,   401,   403,   405,   639,   222,   167,   446,   225,   375,
     376,   448,   229,   377,   649,   378,   379,   380,   381,   382,
     657,   453,   454,   237,   363,   455,   627,   628,   825,   824,
     364,   270,   271,   290,   290,   469,  -332,   629,   458,   459,
    -332,   238,  -332,   465,   466,   467,   397,   470,   244,   462,
     183,   184,   185,   186,   468,   471,   196,   386,   197,   387,
     432,   359,   187,   294,   360,   361,  -331,   266,   267,   435,
    -331,   362,  -331,   233,   483,   234,   484,   581,   582,   486,
     583,   584,   488,   592,   593,   594,   595,   491,   375,   376,
     249,   447,   469,   552,   553,   449,   756,   757,   383,   504,
     250,   295,   254,   296,   470,   299,   384,   314,   257,   456,
     258,   259,   471,   315,   519,   521,   523,   306,   316,   326,
     330,   777,   554,   555,   556,   557,   558,   559,   560,   561,
     526,   527,   331,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     333,   334,   407,   408,   335,   336,   337,   338,   339,   340,
     409,   341,   358,   342,   410,   411,   343,   344,   345,   346,
     347,   348,   349,   412,   350,   365,   385,   388,    93,   406,
     433,   445,   413,   505,   414,   415,   450,   436,   437,   407,
     420,   452,   566,   416,   417,   451,   457,   421,   520,   522,
     524,   422,   423,   460,   418,   461,   463,   475,   579,   476,
     424,  -403,   478,   482,   485,   487,   489,   492,   495,   425,
     502,   426,   427,   503,   506,   507,   508,   510,   509,   525,
     428,   429,   511,   601,   547,   637,   603,   605,   640,   621,
     512,   418,   568,   610,   546,   613,   513,   514,   518,   548,
     614,   -61,   616,   551,   571,   573,   575,   619,   577,   580,
     623,   589,   569,   626,   612,   611,   591,   617,   618,   600,
     622,   624,   625,   631,   632,   638,   567,   635,   651,   656,
     658,   669,   570,   659,   572,   670,   574,   647,   576,   648,
     578,   664,   650,   671,   652,   679,   680,   665,   666,   667,
     668,   672,   673,   681,   590,   674,   660,   675,   662,   676,
     677,   682,   683,   684,   685,   686,   687,   602,   688,   689,
     604,   606,   690,   693,   694,   678,   691,   692,   695,   696,
     697,   705,   700,   702,   615,   706,   730,   732,   699,   723,
     725,   620,   863,   727,   729,   733,   735,   734,   701,   738,
     652,   739,   745,   742,   743,   746,   749,   747,   751,   755,
     758,   761,   763,   759,   762,   766,   764,   769,   707,   767,
     768,   778,   779,   781,   782,   783,   784,   785,   786,   787,
     719,   792,   793,  -273,  -276,  -279,   797,   800,   804,   720,
     813,   661,   805,   663,   754,   814,   816,   820,   823,   821,
     826,   827,   828,   829,   834,   835,   836,   837,   845,   846,
     841,   842,   731,   847,   838,   854,   839,   736,   737,   840,
     850,   851,   856,   852,   853,   744,   858,   860,   857,   862,
     864,   866,   869,   870,   652,   871,   652,   883,   872,   879,
     886,   264,   264,   562,   888,   887,   873,   875,   430,   874,
     633,     0,   708,   391,     0,   713,     0,   714,     0,   715,
       0,   716,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   721,     0,     0,     0,   770,
     771,   772,   773,     0,   722,     0,     0,   774,     0,     0,
       0,     0,     0,   775,   776,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   741,     0,     0,     0,
       0,   822,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     798,     0,   801,   802,     0,     0,     0,     0,   806,     0,
       0,     0,   808,     0,     0,   811,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   652,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   843,     0,     0,     0,     0,   848,     0,     0,
     849,     0,     0,     0,     0,     0,     0,     0,     0,   855,
       0,     0,     0,     0,   799,     0,     0,     0,   803,     0,
       0,     0,     0,   807,     0,     0,   865,     0,     0,     0,
     867,     0,   868,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     876,   877,     0,     0,   878,     0,   880,   881,     0,     0,
       0,     0,     4,     0,   884,     0,   885,     0,     0,     5,
       6,     0,     0,     0,     0,     0,     0,   844,     0,     0,
       0,     7,     8,     0,     9,     0,    10,    11,   890,    12,
      13,     0,     0,     0,     0,     0,     0,    14,     0,    15,
      16,    17,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,    19,     0,     0,     0,     0,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,    28,    29,     0,
      30,     0,     0,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,     0,    41,     0,     0,     0,    42,
      43,    44,    45,    46,     0,    47,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,    51,     0,    52,    53,    54,     0,     0,    55,     0,
       0,     0,    56,     0,    57,     0,     0,     0,    58,    59,
      60,     0,     0,     0,     4,    61,     0,    62,    63,    64,
      65,     5,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     9,     0,    10,    11,
       0,    12,    13,     0,    66,     0,    67,     0,     0,    14,
       0,    15,    16,    17,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,    28,
      29,     0,    30,     0,     0,    31,    32,    33,     0,    34,
      35,    36,    37,    38,    39,    40,     0,    41,     0,     0,
       0,    42,    43,    44,    45,    46,     0,    47,    48,     0,
       0,   279,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,     0,    51,     0,    52,    53,    54,    86,     0,
      55,     0,     0,     0,    56,     0,    57,     0,     0,     0,
      58,    59,    60,     0,    87,    88,    89,    61,     0,    62,
      63,    64,    65,     0,     0,     0,     0,     0,     0,     0,
       0,    90,     0,     0,    91,     0,     0,    92,     0,     0,
       0,     0,     0,     0,     0,     0,   497,    94,    95,     0,
      96,     0,     0,     0,     0,     0,     0,     0,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,     0,     0,     0,   114,   115,   116,     0,
     117,   118,   119,     0,   120,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,     0,
     123,     0,     0,     0,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   282,     0,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,     0,     0,    91,     0,     0,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,    96,     0,     0,     0,     0,     0,     0,     0,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,   100,   101,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,     0,     0,     0,   114,   115,   116,
       0,   117,   118,   119,     0,   120,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
       0,   123,     0,     0,     0,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      85,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,     0,   307,     0,     0,     0,
       0,     0,     0,     0,     0,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,    91,     0,     0,    92,   308,   309,   310,     0,     0,
       0,     0,     0,     0,    94,    95,   311,    96,     0,     0,
       0,     0,     0,     0,     0,    97,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   100,
     101,     0,     0,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
       0,     0,     0,   114,   115,   116,   312,   117,   118,   119,
       0,   120,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   122,     0,   123,     0,     0,
       0,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    85,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,     0,
       0,   200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,     0,   201,   202,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,    91,     0,     0,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,     0,    96,     0,     0,     0,     0,     0,     0,
       0,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,   100,   101,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     0,     0,     0,   114,
     115,   116,     0,   117,   118,   119,     0,   120,   121,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,     0,   123,     0,     0,     0,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    85,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,     0,     0,
       0,     0,     0,     0,     0,   245,   246,     0,     0,     0,
       0,     0,     0,    87,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,     0,    91,     0,     0,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,     0,    96,
       0,     0,     0,     0,     0,     0,     0,    97,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     0,     0,     0,   114,   115,   116,     0,   117,
     118,   119,     0,   120,   121,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,   123,
       0,     0,     0,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    85,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,     0,     0,    91,
       0,     0,    92,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    95,     0,    96,     0,     0,     0,     0,
       0,     0,     0,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,   100,   101,     0,
       0,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,     0,     0,
       0,   114,   115,   116,     0,   117,   118,   119,     0,   120,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   122,     0,   123,     0,     0,     0,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,    85,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,     0,     0,    91,     0,     0,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,    96,     0,     0,     0,     0,     0,     0,     0,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,   100,   101,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,     0,     0,     0,   114,   115,   116,
       0,   117,   118,   119,     0,   120,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
       0,   123,     0,     0,     0,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      85,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,    91,     0,     0,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,     0,    96,     0,     0,
       0,     0,     0,     0,     0,    97,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     101,     0,     0,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
       0,     0,     0,   114,   115,   116,     0,   117,   118,   119,
       0,   120,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   122,     0,   123,     0,     0,
       0,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,    85,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,    91,     0,     0,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,     0,    96,     0,     0,     0,     0,     0,     0,
       0,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     0,     0,     0,   114,
     115,   116,     0,   117,   118,   119,     0,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,     0,   123,     0,     0,     0,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149
};

static const yytype_int16 yycheck[] =
{
      10,   388,    56,    13,   293,   292,   551,    17,   550,   295,
     296,    24,    24,    23,    20,    24,    26,    27,     7,    82,
      24,    24,    24,    33,    34,    24,    20,    68,    53,    39,
       4,     6,     6,    32,    20,    45,    86,    47,    13,    13,
      50,    82,    86,    90,    24,    20,    20,    57,    34,    59,
      49,   195,    62,    79,    80,    65,    26,    79,    80,    34,
      34,    31,   350,     7,    74,     7,     0,   817,    20,    79,
      80,    81,   746,    24,     7,   749,    86,   102,    77,    78,
      97,    29,     7,   195,   196,    36,    37,    13,   105,    99,
      42,    35,   634,    35,   636,    20,    32,   144,   386,   387,
      48,    71,    35,   144,   195,    45,   651,    87,     7,    25,
     160,   656,   862,    49,    54,   165,   160,    43,    32,   144,
     195,    20,    20,    48,   150,   151,   152,    25,   150,   151,
     152,    22,   138,   883,   197,    49,    87,    20,    24,   813,
     129,    77,    78,    45,   138,   162,   163,   164,    74,    48,
     156,    34,    54,    79,    80,    81,   197,   702,    74,    75,
      76,   147,   156,    77,    78,    45,   176,    83,    84,    85,
      74,    75,   147,   147,    54,   185,    74,    75,    76,    45,
      90,    85,   195,   195,    25,    34,   195,    85,    54,   199,
     200,   195,   195,   195,   481,    34,   195,   207,    24,     8,
       9,   211,    24,    12,   490,    14,    15,    16,    17,    18,
     499,   221,   222,   144,   178,   225,    74,    75,   763,   761,
     184,    42,    43,   198,   198,   123,     0,    85,   238,   239,
       4,    68,     6,    74,    75,    76,   162,   135,   195,   249,
      42,    43,    44,    45,    85,   143,   195,    19,   197,    21,
     176,   174,    54,     6,   177,   178,     0,   157,   158,   185,
       4,   184,     6,   195,     5,   197,     7,    56,    57,   279,
      56,    57,   282,    56,    57,    56,    57,   287,     8,     9,
      34,   207,   123,   375,   376,   211,   641,   642,    97,   299,
     195,     4,   195,     4,   135,    24,   105,    34,   195,   225,
     195,   195,   143,    34,   314,   315,   316,   197,    34,   197,
      34,   698,   377,   378,   379,   380,   381,   382,   383,   384,
     330,   331,    34,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
      34,    34,    24,    25,    34,    34,    34,    34,    34,    34,
      32,    34,   177,    34,    36,    37,    34,    34,    34,    34,
      34,    34,    34,    45,    34,   177,   130,   129,    82,    24,
      29,     7,    54,   299,    56,    57,    29,    46,    46,    24,
      25,   147,   392,    65,    66,    69,    34,    32,   314,   315,
     316,    36,    37,    13,    76,   152,     7,     7,   408,   147,
      45,   147,   147,     7,     7,     7,     7,    13,    34,    54,
      29,    56,    57,    29,    72,    72,    72,    35,    72,    34,
      65,    66,    35,   433,   195,   479,   436,   437,   482,    69,
      35,    76,    24,    42,    34,   445,    35,    35,    35,    34,
     450,    34,   452,    34,    24,    24,    24,   457,    24,    33,
     460,    34,    48,   463,     7,   195,    33,     7,     7,    34,
       7,   102,     7,    34,    20,     7,   392,   147,    34,    34,
     195,    35,   398,   195,   400,    35,   402,   487,   404,   489,
     406,   197,   492,    35,   494,     7,     7,   197,   197,   197,
     197,    35,    35,     7,   420,    35,   506,    35,   508,    35,
      35,     7,    35,    35,    35,    35,     7,   433,    35,    35,
     436,   437,    35,     7,     7,   525,    35,    35,    35,    35,
      35,    29,    35,    34,   450,    29,    13,     7,   195,   195,
     195,   457,   819,   195,   195,    42,   148,    42,   548,     7,
     550,     7,     7,    72,   195,    34,    34,   197,   195,     7,
     167,     7,     7,   167,   148,   197,    35,    35,   568,   197,
     197,    35,    35,   148,    35,   195,   195,    29,    29,   196,
     580,     7,     7,     7,     7,     7,    13,     7,    35,   589,
       7,   507,    35,   509,   638,    35,   148,   148,    35,   148,
      13,    35,    35,    35,    35,    35,    35,    35,     7,     7,
      29,    29,   612,     7,    35,   115,   196,   617,   618,   196,
      13,    13,    13,    35,    35,   625,    35,    35,    72,     7,
      13,    13,   196,   196,   634,    35,   636,     7,    35,    35,
      35,   641,   642,   385,    13,    35,   845,   847,   172,   846,
     475,    -1,   568,   155,    -1,   571,    -1,   573,    -1,   575,
      -1,   577,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   591,    -1,    -1,    -1,   679,
     680,   681,   682,    -1,   600,    -1,    -1,   687,    -1,    -1,
      -1,    -1,    -1,   693,   694,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,    -1,    -1,
      -1,   755,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     730,    -1,   732,   733,    -1,    -1,    -1,    -1,   738,    -1,
      -1,    -1,   742,    -1,    -1,   745,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   761,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   792,    -1,    -1,    -1,    -1,   797,    -1,    -1,
     800,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   809,
      -1,    -1,    -1,    -1,   730,    -1,    -1,    -1,   734,    -1,
      -1,    -1,    -1,   739,    -1,    -1,   826,    -1,    -1,    -1,
     830,    -1,   832,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     850,   851,    -1,    -1,   854,    -1,   856,   857,    -1,    -1,
      -1,    -1,     3,    -1,   864,    -1,   866,    -1,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,   793,    -1,    -1,
      -1,    22,    23,    -1,    25,    -1,    27,    28,   888,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    88,    89,    -1,
      91,    -1,    -1,    94,    95,    96,    -1,    98,    99,   100,
     101,   102,   103,   104,    -1,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,    -1,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,   142,    -1,   144,   145,   146,    -1,    -1,   149,    -1,
      -1,    -1,   153,    -1,   155,    -1,    -1,    -1,   159,   160,
     161,    -1,    -1,    -1,     3,   166,    -1,   168,   169,   170,
     171,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    -1,    25,    -1,    27,    28,
      -1,    30,    31,    -1,   195,    -1,   197,    -1,    -1,    38,
      -1,    40,    41,    42,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    88,
      89,    -1,    91,    -1,    -1,    94,    95,    96,    -1,    98,
      99,   100,   101,   102,   103,   104,    -1,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,    -1,   116,   117,    -1,
      -1,     7,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,   142,    -1,   144,   145,   146,    34,    -1,
     149,    -1,    -1,    -1,   153,    -1,   155,    -1,    -1,    -1,
     159,   160,   161,    -1,    50,    51,    52,   166,    -1,   168,
     169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,    83,    84,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,
     136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
     156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,     7,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,   136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,
      -1,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
       9,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    70,    -1,    -1,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,   135,   136,   137,   138,
      -1,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,     9,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,   156,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,     9,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,
     137,   138,    -1,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,     9,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,   137,   138,    -1,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   154,    -1,   156,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,     9,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,   136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,
      -1,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
       9,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,   138,
      -1,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,     9,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
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
      -1,   154,    -1,   156,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   306,   307,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    86,    88,    89,
      91,    94,    95,    96,    98,    99,   100,   101,   102,   103,
     104,   106,   110,   111,   112,   113,   114,   116,   117,   131,
     139,   142,   144,   145,   146,   149,   153,   155,   159,   160,
     161,   166,   168,   169,   170,   171,   195,   197,   291,   300,
     302,   304,   195,   195,    24,   195,   217,   218,   219,    26,
      31,    71,   223,   224,   225,     9,    34,    50,    51,    52,
      67,    70,    73,    82,    83,    84,    86,    94,    95,   107,
     108,   109,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   132,   133,   134,   136,   137,   138,
     140,   141,   154,   156,   160,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     200,   201,   202,   203,   204,   205,   208,   209,   227,   228,
     229,    22,    24,    32,    49,    77,    78,   195,   214,   215,
     216,   200,   205,   230,   231,   232,    24,    36,    37,    87,
     233,   234,   235,    42,    43,    44,    45,    54,   248,   249,
     250,   200,   265,   195,   251,   254,   195,   197,   252,   292,
      24,    36,    37,   200,   239,   240,   241,    24,   242,   243,
     244,    24,    87,   245,   246,   247,   200,   200,    90,    90,
     144,    34,    34,   200,   200,    24,   236,   237,   238,    24,
     255,   256,   257,   195,   197,   253,   200,   144,    68,    68,
     144,   197,   205,   200,   195,    42,    43,   200,   269,    34,
     195,   270,   200,   258,   195,   273,   277,   195,   195,   195,
     195,   196,   280,   280,   200,   282,   157,   158,   285,   200,
      42,    43,    97,   105,   162,   163,   164,   286,   288,     7,
     200,   289,     7,   200,   290,     4,     6,    13,    20,   147,
     198,   297,   299,   303,     6,     4,     4,   200,   205,    24,
     200,   205,   200,   205,   200,   205,   197,    25,    74,    75,
      76,    85,   135,   200,    34,    34,    34,    25,    74,    75,
      76,    83,    84,    85,   206,   207,   197,    20,   138,   156,
      34,    34,   200,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    20,    34,    86,   160,    20,   138,   156,   177,   174,
     177,   178,   184,   178,   184,   177,    20,   147,   210,    79,
      80,   150,   151,   152,   226,     8,     9,    12,    14,    15,
      16,    17,    18,    97,   105,   130,    19,    21,   129,    80,
     152,   226,    24,   195,   220,   221,   222,   205,    24,   195,
      24,   195,    24,   195,    24,   195,    24,    24,    25,    32,
      36,    37,    45,    54,    56,    57,    65,    66,    76,   213,
      25,    32,    36,    37,    45,    54,    56,    57,    65,    66,
     213,   200,   205,    29,   200,   205,    46,    46,    53,   102,
     144,    20,    42,   200,   200,     7,   200,   205,   200,   205,
      29,    69,   147,   200,   200,   200,   205,    34,   200,   200,
      13,   152,   200,     7,    25,    74,    75,    76,    85,   123,
     135,   143,   272,   274,   275,     7,   147,   293,   147,     7,
      20,    48,     7,     5,     7,     7,   200,     7,   200,     7,
     305,   200,    13,   298,   294,    34,   272,   195,   300,   301,
     304,   304,    29,    29,   200,   205,    72,    72,    72,    72,
      35,    35,    35,    35,    35,    74,    75,    85,    35,   200,
     205,   200,   205,   200,   205,    34,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   204,    34,   195,    34,   211,
     212,    34,   202,   202,   201,   201,   201,   201,   201,   201,
     201,   201,   203,   204,   204,   209,   200,   205,    24,    48,
     205,    24,   205,    24,   205,    24,   205,    24,   205,   200,
      33,    56,    57,    56,    57,    45,    54,    45,    54,    34,
     205,    33,    56,    57,    56,    57,    45,    54,    45,    54,
      34,   200,   205,   200,   205,   200,   205,   266,   268,   267,
      42,   195,     7,   200,   200,   205,   200,     7,     7,   200,
     205,    69,     7,   200,   102,     7,   200,    74,    75,    85,
     276,    34,    20,   277,   295,   147,   296,   280,     7,   272,
     280,   284,   283,    86,   160,   165,   287,   200,   200,   304,
     200,    34,   200,   281,   200,   278,    34,   300,   195,   195,
     200,   205,   200,   205,   197,   197,   197,   197,   197,    35,
      35,    35,    35,    35,    35,    35,    35,    35,   200,     7,
       7,     7,     7,    35,    35,    35,    35,     7,    35,    35,
      35,    35,    35,     7,     7,    35,    35,    35,     7,   195,
      35,   200,    34,   281,   278,    29,    29,   200,   205,    32,
      49,    77,    78,   205,   205,   205,   205,    29,    48,   200,
     200,   205,   205,   195,   259,   195,   261,   195,   263,   195,
      13,   200,     7,    42,    42,   148,   200,   200,     7,     7,
     197,   205,    72,   195,   200,     7,    34,   197,   271,    34,
     281,   195,   279,   281,   280,     7,   282,   282,   167,   167,
     278,     7,   148,     7,    35,   278,   197,   197,   197,    35,
     200,   200,   200,   200,   200,   200,   200,   209,    35,    35,
     278,   148,    35,   195,   195,    29,    29,   196,    32,    49,
      77,    78,     7,     7,   260,   262,   264,    13,   200,   205,
       7,   200,   200,   205,    35,    35,   200,   205,   200,     7,
      35,   200,   271,     7,    35,   271,   148,     7,    20,    48,
     148,   148,   280,    35,   281,   278,    13,    35,    35,    35,
       7,    35,     7,    35,    35,    35,    35,    35,    35,   196,
     196,    29,    29,   200,   205,     7,     7,     7,   200,   200,
      13,    13,    35,    35,   115,   200,    13,    72,    35,   271,
      35,   279,     7,   272,    13,   200,    13,   200,   200,   196,
     196,    35,    35,   259,   261,   263,   200,   200,   200,    35,
     200,   200,   279,     7,   200,   200,    35,    35,    13,   279,
     200
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   199,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   201,   201,   201,   202,   202,   203,   203,   203,
     204,   204,   204,   205,   206,   206,   206,   206,   206,   206,
     206,   207,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   210,
     209,   211,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   212,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   213,   213,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   215,   215,   215,   215,
     215,   216,   216,   217,   217,   218,   218,   219,   219,   220,
     220,   221,   221,   222,   222,   223,   223,   223,   224,   224,
     224,   225,   225,   226,   226,   226,   227,   227,   227,   228,
     228,   228,   229,   229,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   232,   232,   233,   233,   233,   233,
     233,   234,   234,   235,   235,   236,   237,   238,   238,   239,
     239,   240,   240,   241,   241,   242,   243,   244,   244,   245,
     245,   245,   246,   246,   247,   247,   248,   248,   248,   248,
     248,   249,   249,   249,   250,   250,   251,   251,   251,   251,
     251,   251,   252,   252,   253,   253,   254,   255,   256,   257,
     257,   258,   259,   260,   259,   261,   262,   261,   263,   264,
     263,   266,   265,   267,   265,   268,   265,   269,   269,   269,
     270,   270,   271,   271,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   274,   273,   275,   273,   276,   273,
     277,   277,   278,   278,   279,   279,   279,   279,   279,   279,
     280,   280,   280,   280,   280,   280,   280,   280,   281,   281,
     282,   282,   282,   283,   282,   284,   282,   285,   285,   286,
     286,   286,   286,   286,   287,   287,   287,   287,   287,   288,
     289,   289,   289,   290,   290,   290,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   292,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   293,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   294,   291,   295,   291,   296,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   297,   291,   298,   291,
     299,   291,   291,   291,   291,   300,   301,   300,   303,   302,
     305,   304,   304,   304,   304,   304,   307,   306
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
       1,     2,     2,     0,     4,     0,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     3,
       2,     2,     3,     2,     2,     3,     2,     2,     3,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     2,     2,     1,
       2,     3,     1,     4,     1,     1,     1,     0,     3,     1,
       1,     2,     1,     2,     2,     3,     2,     2,     5,     5,
       6,     1,     2,     0,     6,     2,     2,     2,     5,     8,
       2,     2,     2,     0,     5,     0,     6,     0,     6,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
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
#line 75 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2807 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 79 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2816 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 83 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2824 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 86 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2832 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 89 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2840 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 92 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2848 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 95 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2856 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 98 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2864 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 101 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2872 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 108 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2880 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 111 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2889 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 124 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2898 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 128 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2907 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 136 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2916 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 140 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 2925 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 147 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2933 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 152 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2941 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 155 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2949 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 158 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2957 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 161 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2965 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 164 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2973 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 167 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2981 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 170 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2989 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 175 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2997 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 180 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3006 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 184 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3015 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 188 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3024 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 192 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3033 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 196 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3042 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 200 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3051 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 204 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3060 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 208 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3069 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 212 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3078 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 216 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3087 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 220 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3096 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 224 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3105 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 228 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3114 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 232 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3123 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 236 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3132 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 240 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3141 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 244 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3150 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 248 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3159 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 252 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3168 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 256 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3177 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 260 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3186 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 264 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3195 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 268 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3204 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 272 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3213 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 276 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3222 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 280 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3231 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 284 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3240 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 290 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3249 "src-generated/ugbc.tab.c"
    break;

  case 60: /* exponential: Identifier $@1 OP indexes CP  */
#line 294 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-4].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-4].string) )->name;
    }
#line 3261 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 301 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3270 "src-generated/ugbc.tab.c"
    break;

  case 62: /* exponential: Identifier DOLLAR $@2 OP indexes CP  */
#line 305 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-5].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-5].string) )->name;
    }
#line 3282 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 312 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3290 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 315 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3298 "src-generated/ugbc.tab.c"
    break;

  case 65: /* exponential: Integer  */
#line 318 "src/ugbc.y"
              { 
        if ( (yyvsp[0].integer) < 0 ) {
            (yyval.string) = variable_temporary( _environment, VT_SWORD, "(signed integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        } else {
            (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        }
      }
#line 3312 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 327 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3321 "src-generated/ugbc.tab.c"
    break;

  case 67: /* exponential: String  */
#line 331 "src/ugbc.y"
             { 
        outline1("; (expr string: \"%s\")", (yyvsp[0].string) );
        (yyval.string) = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", (yyval.string) );
        variable_store_string( _environment, (yyval.string), (yyvsp[0].string) );
        outline2("; variable stored: %s = %s", (yyval.string), (yyvsp[0].string) );
      }
#line 3333 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 338 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3342 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 342 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3351 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 346 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3360 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 350 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3369 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 354 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3378 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 358 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3387 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 362 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3396 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 366 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3405 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 370 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3413 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 373 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3421 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 376 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3429 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 379 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3437 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 382 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3445 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 385 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3453 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 388 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3461 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 391 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3469 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 394 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3477 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 397 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3485 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 400 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3493 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 403 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3501 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 406 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3509 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 409 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3517 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 412 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3525 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 415 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3533 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 418 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3541 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 421 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3549 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 424 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3557 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 427 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3565 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 430 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3573 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 433 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3581 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 436 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3589 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 439 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3597 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 442 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3605 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 445 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3613 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 448 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3621 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 451 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3629 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 454 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3637 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 457 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3645 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 460 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3653 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 463 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3661 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 466 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3669 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 468 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3678 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 472 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3686 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 475 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3694 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 478 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3703 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 482 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3712 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 486 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3721 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: PEN COLORS  */
#line 490 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3730 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: PEN DEFAULT  */
#line 494 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3739 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: DEFAULT PEN  */
#line 498 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3748 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: PAPER COLORS  */
#line 502 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3757 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: PAPER DEFAULT  */
#line 506 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3766 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: DEFAULT PAPER  */
#line 510 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3775 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: WIDTH  */
#line 514 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3783 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: HEIGHT  */
#line 517 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3791 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: TIMER  */
#line 520 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3799 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PEN DOLLAR OP expr CP  */
#line 523 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 3807 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER DOLLAR OP expr CP  */
#line 526 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3815 "src-generated/ugbc.tab.c"
    break;

  case 128: /* bank_definition_simple: AT direct_integer  */
#line 534 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3823 "src-generated/ugbc.tab.c"
    break;

  case 129: /* bank_definition_simple: Identifier AT direct_integer  */
#line 537 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3831 "src-generated/ugbc.tab.c"
    break;

  case 130: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 540 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3839 "src-generated/ugbc.tab.c"
    break;

  case 131: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 543 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3847 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 546 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3855 "src-generated/ugbc.tab.c"
    break;

  case 133: /* bank_definition_simple: DATA AT direct_integer  */
#line 549 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3863 "src-generated/ugbc.tab.c"
    break;

  case 134: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 553 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3871 "src-generated/ugbc.tab.c"
    break;

  case 135: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 556 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3879 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 559 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3887 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bank_definition_simple: CODE AT direct_integer  */
#line 562 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3895 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 566 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3903 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 569 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3911 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 572 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3919 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 575 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3927 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 579 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3935 "src-generated/ugbc.tab.c"
    break;

  case 143: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 582 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3943 "src-generated/ugbc.tab.c"
    break;

  case 144: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 585 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3951 "src-generated/ugbc.tab.c"
    break;

  case 145: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 588 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3959 "src-generated/ugbc.tab.c"
    break;

  case 146: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 594 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3967 "src-generated/ugbc.tab.c"
    break;

  case 147: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 597 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3975 "src-generated/ugbc.tab.c"
    break;

  case 148: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 600 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3983 "src-generated/ugbc.tab.c"
    break;

  case 149: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 603 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3991 "src-generated/ugbc.tab.c"
    break;

  case 150: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 606 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3999 "src-generated/ugbc.tab.c"
    break;

  case 153: /* raster_definition_simple: Identifier AT direct_integer  */
#line 615 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 4007 "src-generated/ugbc.tab.c"
    break;

  case 154: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 618 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 4015 "src-generated/ugbc.tab.c"
    break;

  case 155: /* raster_definition_expression: Identifier AT expr  */
#line 623 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4023 "src-generated/ugbc.tab.c"
    break;

  case 156: /* raster_definition_expression: AT expr WITH Identifier  */
#line 626 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4031 "src-generated/ugbc.tab.c"
    break;

  case 159: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 635 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 4039 "src-generated/ugbc.tab.c"
    break;

  case 160: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 638 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 4047 "src-generated/ugbc.tab.c"
    break;

  case 161: /* next_raster_definition_expression: Identifier AT expr  */
#line 643 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 4055 "src-generated/ugbc.tab.c"
    break;

  case 162: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 646 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4063 "src-generated/ugbc.tab.c"
    break;

  case 165: /* color_definition_simple: BORDER direct_integer  */
#line 655 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 4071 "src-generated/ugbc.tab.c"
    break;

  case 166: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 658 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4079 "src-generated/ugbc.tab.c"
    break;

  case 167: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 661 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4087 "src-generated/ugbc.tab.c"
    break;

  case 168: /* color_definition_expression: BORDER expr  */
#line 666 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 4095 "src-generated/ugbc.tab.c"
    break;

  case 169: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 669 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4103 "src-generated/ugbc.tab.c"
    break;

  case 170: /* color_definition_expression: SPRITE expr TO expr  */
#line 672 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4111 "src-generated/ugbc.tab.c"
    break;

  case 176: /* wait_definition_simple: direct_integer CYCLES  */
#line 686 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4119 "src-generated/ugbc.tab.c"
    break;

  case 177: /* wait_definition_simple: direct_integer TICKS  */
#line 689 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4127 "src-generated/ugbc.tab.c"
    break;

  case 178: /* wait_definition_simple: direct_integer milliseconds  */
#line 692 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4135 "src-generated/ugbc.tab.c"
    break;

  case 179: /* wait_definition_expression: expr CYCLES  */
#line 697 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4143 "src-generated/ugbc.tab.c"
    break;

  case 180: /* wait_definition_expression: expr TICKS  */
#line 700 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4151 "src-generated/ugbc.tab.c"
    break;

  case 181: /* wait_definition_expression: expr milliseconds  */
#line 703 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4159 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 713 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4167 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 716 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4175 "src-generated/ugbc.tab.c"
    break;

  case 186: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 719 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4183 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 722 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4191 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 725 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4199 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_simple: direct_integer ENABLE  */
#line 728 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4207 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_simple: direct_integer DISABLE  */
#line 731 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4215 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 734 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4223 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 737 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4231 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 740 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4239 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 743 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4247 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 746 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4255 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 749 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4263 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 752 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4271 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 755 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4279 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_expression: expr DATA FROM expr  */
#line 760 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4287 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_expression: expr MULTICOLOR  */
#line 763 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4295 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_expression: expr MONOCOLOR  */
#line 766 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4303 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_expression: expr COLOR expr  */
#line 769 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4311 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 772 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4319 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_expression: expr ENABLE  */
#line 775 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4327 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_expression: expr DISABLE  */
#line 778 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4335 "src-generated/ugbc.tab.c"
    break;

  case 206: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 781 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4343 "src-generated/ugbc.tab.c"
    break;

  case 207: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 784 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4351 "src-generated/ugbc.tab.c"
    break;

  case 208: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 787 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4359 "src-generated/ugbc.tab.c"
    break;

  case 209: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 790 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4367 "src-generated/ugbc.tab.c"
    break;

  case 210: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 793 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4375 "src-generated/ugbc.tab.c"
    break;

  case 211: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 796 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4383 "src-generated/ugbc.tab.c"
    break;

  case 212: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 799 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4391 "src-generated/ugbc.tab.c"
    break;

  case 213: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 802 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4399 "src-generated/ugbc.tab.c"
    break;

  case 216: /* bitmap_definition_simple: AT direct_integer  */
#line 811 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4407 "src-generated/ugbc.tab.c"
    break;

  case 217: /* bitmap_definition_simple: ENABLE  */
#line 814 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4415 "src-generated/ugbc.tab.c"
    break;

  case 218: /* bitmap_definition_simple: DISABLE  */
#line 817 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4423 "src-generated/ugbc.tab.c"
    break;

  case 219: /* bitmap_definition_simple: CLEAR  */
#line 820 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4431 "src-generated/ugbc.tab.c"
    break;

  case 220: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 823 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4439 "src-generated/ugbc.tab.c"
    break;

  case 221: /* bitmap_definition_expression: AT expr  */
#line 829 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4447 "src-generated/ugbc.tab.c"
    break;

  case 222: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 832 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4455 "src-generated/ugbc.tab.c"
    break;

  case 225: /* textmap_definition_simple: AT direct_integer  */
#line 842 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4463 "src-generated/ugbc.tab.c"
    break;

  case 226: /* textmap_definition_expression: AT expr  */
#line 847 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4471 "src-generated/ugbc.tab.c"
    break;

  case 229: /* text_definition_simple: ENABLE  */
#line 856 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4479 "src-generated/ugbc.tab.c"
    break;

  case 230: /* text_definition_simple: DISABLE  */
#line 859 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4487 "src-generated/ugbc.tab.c"
    break;

  case 231: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 864 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4495 "src-generated/ugbc.tab.c"
    break;

  case 232: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 867 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4503 "src-generated/ugbc.tab.c"
    break;

  case 235: /* tiles_definition_simple: AT direct_integer  */
#line 876 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4511 "src-generated/ugbc.tab.c"
    break;

  case 236: /* tiles_definition_expression: AT expr  */
#line 881 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4519 "src-generated/ugbc.tab.c"
    break;

  case 239: /* colormap_definition_simple: AT direct_integer  */
#line 890 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4527 "src-generated/ugbc.tab.c"
    break;

  case 240: /* colormap_definition_simple: CLEAR  */
#line 893 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4535 "src-generated/ugbc.tab.c"
    break;

  case 241: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 896 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4543 "src-generated/ugbc.tab.c"
    break;

  case 242: /* colormap_definition_expression: AT expr  */
#line 901 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4551 "src-generated/ugbc.tab.c"
    break;

  case 243: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 904 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4559 "src-generated/ugbc.tab.c"
    break;

  case 246: /* screen_definition_simple: ON  */
#line 914 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4567 "src-generated/ugbc.tab.c"
    break;

  case 247: /* screen_definition_simple: OFF  */
#line 917 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4575 "src-generated/ugbc.tab.c"
    break;

  case 248: /* screen_definition_simple: ROWS direct_integer  */
#line 920 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4583 "src-generated/ugbc.tab.c"
    break;

  case 249: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 923 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4591 "src-generated/ugbc.tab.c"
    break;

  case 250: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 926 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4599 "src-generated/ugbc.tab.c"
    break;

  case 251: /* screen_definition_expression: ROWS expr  */
#line 931 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4607 "src-generated/ugbc.tab.c"
    break;

  case 252: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 934 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4615 "src-generated/ugbc.tab.c"
    break;

  case 253: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 937 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4623 "src-generated/ugbc.tab.c"
    break;

  case 257: /* var_definition_simple: Identifier ON Identifier  */
#line 946 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4631 "src-generated/ugbc.tab.c"
    break;

  case 258: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 949 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4639 "src-generated/ugbc.tab.c"
    break;

  case 259: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 952 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4647 "src-generated/ugbc.tab.c"
    break;

  case 260: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 955 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4657 "src-generated/ugbc.tab.c"
    break;

  case 261: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 960 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4667 "src-generated/ugbc.tab.c"
    break;

  case 262: /* goto_definition: Identifier  */
#line 967 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4675 "src-generated/ugbc.tab.c"
    break;

  case 263: /* goto_definition: Integer  */
#line 970 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4683 "src-generated/ugbc.tab.c"
    break;

  case 264: /* gosub_definition: Identifier  */
#line 976 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4691 "src-generated/ugbc.tab.c"
    break;

  case 265: /* gosub_definition: Integer  */
#line 979 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4699 "src-generated/ugbc.tab.c"
    break;

  case 267: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 988 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4707 "src-generated/ugbc.tab.c"
    break;

  case 268: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 994 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4715 "src-generated/ugbc.tab.c"
    break;

  case 271: /* ink_definition: expr  */
#line 1003 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4723 "src-generated/ugbc.tab.c"
    break;

  case 272: /* on_goto_definition: Identifier  */
#line 1008 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4732 "src-generated/ugbc.tab.c"
    break;

  case 273: /* $@4: %empty  */
#line 1012 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4740 "src-generated/ugbc.tab.c"
    break;

  case 275: /* on_gosub_definition: Identifier  */
#line 1017 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4749 "src-generated/ugbc.tab.c"
    break;

  case 276: /* $@5: %empty  */
#line 1021 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4757 "src-generated/ugbc.tab.c"
    break;

  case 278: /* on_proc_definition: Identifier  */
#line 1026 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4766 "src-generated/ugbc.tab.c"
    break;

  case 279: /* $@6: %empty  */
#line 1030 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4774 "src-generated/ugbc.tab.c"
    break;

  case 281: /* $@7: %empty  */
#line 1035 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4782 "src-generated/ugbc.tab.c"
    break;

  case 283: /* $@8: %empty  */
#line 1038 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4790 "src-generated/ugbc.tab.c"
    break;

  case 285: /* $@9: %empty  */
#line 1041 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4798 "src-generated/ugbc.tab.c"
    break;

  case 287: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1046 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4806 "src-generated/ugbc.tab.c"
    break;

  case 288: /* every_definition: ON  */
#line 1049 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4814 "src-generated/ugbc.tab.c"
    break;

  case 289: /* every_definition: OFF  */
#line 1052 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4822 "src-generated/ugbc.tab.c"
    break;

  case 290: /* add_definition: Identifier COMMA expr  */
#line 1057 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4830 "src-generated/ugbc.tab.c"
    break;

  case 291: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1060 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4838 "src-generated/ugbc.tab.c"
    break;

  case 292: /* dimensions: Integer  */
#line 1066 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4847 "src-generated/ugbc.tab.c"
    break;

  case 293: /* dimensions: Integer COMMA dimensions  */
#line 1070 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4856 "src-generated/ugbc.tab.c"
    break;

  case 294: /* datatype: BYTE  */
#line 1077 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 4864 "src-generated/ugbc.tab.c"
    break;

  case 295: /* datatype: SIGNED BYTE  */
#line 1080 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 4872 "src-generated/ugbc.tab.c"
    break;

  case 296: /* datatype: WORD  */
#line 1083 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 4880 "src-generated/ugbc.tab.c"
    break;

  case 297: /* datatype: SIGNED WORD  */
#line 1086 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 4888 "src-generated/ugbc.tab.c"
    break;

  case 298: /* datatype: DWORD  */
#line 1089 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 4896 "src-generated/ugbc.tab.c"
    break;

  case 299: /* datatype: SIGNED DWORD  */
#line 1092 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 4904 "src-generated/ugbc.tab.c"
    break;

  case 300: /* datatype: ADDRESS  */
#line 1095 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 4912 "src-generated/ugbc.tab.c"
    break;

  case 301: /* datatype: POSITION  */
#line 1098 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 4920 "src-generated/ugbc.tab.c"
    break;

  case 302: /* datatype: COLOR  */
#line 1101 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 4928 "src-generated/ugbc.tab.c"
    break;

  case 303: /* datatype: STRING  */
#line 1104 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 4936 "src-generated/ugbc.tab.c"
    break;

  case 304: /* $@10: %empty  */
#line 1109 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4945 "src-generated/ugbc.tab.c"
    break;

  case 305: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1112 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 4955 "src-generated/ugbc.tab.c"
    break;

  case 306: /* $@11: %empty  */
#line 1117 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4964 "src-generated/ugbc.tab.c"
    break;

  case 307: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1120 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 4974 "src-generated/ugbc.tab.c"
    break;

  case 308: /* $@12: %empty  */
#line 1125 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4983 "src-generated/ugbc.tab.c"
    break;

  case 309: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1128 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 4993 "src-generated/ugbc.tab.c"
    break;

  case 312: /* indexes: expr  */
#line 1141 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5002 "src-generated/ugbc.tab.c"
    break;

  case 313: /* indexes: expr COMMA indexes  */
#line 1145 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5011 "src-generated/ugbc.tab.c"
    break;

  case 314: /* parameters: Identifier  */
#line 1152 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5021 "src-generated/ugbc.tab.c"
    break;

  case 315: /* parameters: Identifier DOLLAR  */
#line 1157 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5031 "src-generated/ugbc.tab.c"
    break;

  case 316: /* parameters: Identifier AS datatype  */
#line 1162 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5041 "src-generated/ugbc.tab.c"
    break;

  case 317: /* parameters: Identifier COMMA parameters  */
#line 1167 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5051 "src-generated/ugbc.tab.c"
    break;

  case 318: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1172 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5061 "src-generated/ugbc.tab.c"
    break;

  case 319: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1177 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5071 "src-generated/ugbc.tab.c"
    break;

  case 320: /* parameters_expr: Identifier  */
#line 1185 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5081 "src-generated/ugbc.tab.c"
    break;

  case 321: /* parameters_expr: Identifier DOLLAR  */
#line 1190 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5091 "src-generated/ugbc.tab.c"
    break;

  case 322: /* parameters_expr: Identifier AS datatype  */
#line 1195 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5101 "src-generated/ugbc.tab.c"
    break;

  case 323: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1200 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5111 "src-generated/ugbc.tab.c"
    break;

  case 324: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1205 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5121 "src-generated/ugbc.tab.c"
    break;

  case 325: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1210 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5131 "src-generated/ugbc.tab.c"
    break;

  case 326: /* parameters_expr: String  */
#line 1215 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5140 "src-generated/ugbc.tab.c"
    break;

  case 327: /* parameters_expr: String COMMA parameters_expr  */
#line 1219 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5149 "src-generated/ugbc.tab.c"
    break;

  case 328: /* values: expr  */
#line 1226 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5158 "src-generated/ugbc.tab.c"
    break;

  case 329: /* values: expr COMMA values  */
#line 1230 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5167 "src-generated/ugbc.tab.c"
    break;

  case 330: /* print_definition: expr  */
#line 1237 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5175 "src-generated/ugbc.tab.c"
    break;

  case 331: /* print_definition: expr COMMA  */
#line 1240 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5184 "src-generated/ugbc.tab.c"
    break;

  case 332: /* print_definition: expr SEMICOLON  */
#line 1244 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5192 "src-generated/ugbc.tab.c"
    break;

  case 333: /* $@13: %empty  */
#line 1247 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5201 "src-generated/ugbc.tab.c"
    break;

  case 335: /* $@14: %empty  */
#line 1251 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5209 "src-generated/ugbc.tab.c"
    break;

  case 337: /* use_definition: ANSI  */
#line 1257 "src/ugbc.y"
         {
        use_ansi( _environment );
    }
#line 5217 "src-generated/ugbc.tab.c"
    break;

  case 338: /* use_definition: SPECIFIC  */
#line 1260 "src/ugbc.y"
             {
        use_specific( _environment );
  }
#line 5225 "src-generated/ugbc.tab.c"
    break;

  case 339: /* writing_mode_definition: REPLACE  */
#line 1266 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5234 "src-generated/ugbc.tab.c"
    break;

  case 340: /* writing_mode_definition: OR  */
#line 1270 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5243 "src-generated/ugbc.tab.c"
    break;

  case 341: /* writing_mode_definition: XOR  */
#line 1274 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5252 "src-generated/ugbc.tab.c"
    break;

  case 342: /* writing_mode_definition: AND  */
#line 1278 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5261 "src-generated/ugbc.tab.c"
    break;

  case 343: /* writing_mode_definition: IGNORE  */
#line 1282 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5270 "src-generated/ugbc.tab.c"
    break;

  case 344: /* writing_part_definition: NORMAL  */
#line 1289 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5279 "src-generated/ugbc.tab.c"
    break;

  case 345: /* writing_part_definition: PAPER  */
#line 1293 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5288 "src-generated/ugbc.tab.c"
    break;

  case 346: /* writing_part_definition: PAPER ONLY  */
#line 1297 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5297 "src-generated/ugbc.tab.c"
    break;

  case 347: /* writing_part_definition: PEN  */
#line 1301 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5306 "src-generated/ugbc.tab.c"
    break;

  case 348: /* writing_part_definition: PEN ONLY  */
#line 1305 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5315 "src-generated/ugbc.tab.c"
    break;

  case 349: /* writing_definition: writing_mode_definition COMMA writing_part_definition  */
#line 1312 "src/ugbc.y"
                                                          {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5323 "src-generated/ugbc.tab.c"
    break;

  case 350: /* locate_definition: COMMA expr  */
#line 1318 "src/ugbc.y"
                {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 5331 "src-generated/ugbc.tab.c"
    break;

  case 351: /* locate_definition: expr COMMA  */
#line 1321 "src/ugbc.y"
                 {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 5339 "src-generated/ugbc.tab.c"
    break;

  case 352: /* locate_definition: expr COMMA expr  */
#line 1324 "src/ugbc.y"
                      {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5347 "src-generated/ugbc.tab.c"
    break;

  case 353: /* cmove_definition: COMMA expr  */
#line 1330 "src/ugbc.y"
                {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 5355 "src-generated/ugbc.tab.c"
    break;

  case 354: /* cmove_definition: expr COMMA  */
#line 1333 "src/ugbc.y"
                 {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 5363 "src-generated/ugbc.tab.c"
    break;

  case 355: /* cmove_definition: expr COMMA expr  */
#line 1336 "src/ugbc.y"
                      {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5371 "src-generated/ugbc.tab.c"
    break;

  case 375: /* statement: CLS  */
#line 1361 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 5379 "src-generated/ugbc.tab.c"
    break;

  case 376: /* statement: HOME  */
#line 1364 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 5387 "src-generated/ugbc.tab.c"
    break;

  case 377: /* statement: INC Identifier  */
#line 1367 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 5395 "src-generated/ugbc.tab.c"
    break;

  case 378: /* statement: DEC Identifier  */
#line 1370 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 5403 "src-generated/ugbc.tab.c"
    break;

  case 379: /* statement: RANDOMIZE  */
#line 1373 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 5411 "src-generated/ugbc.tab.c"
    break;

  case 380: /* statement: RANDOMIZE expr  */
#line 1376 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 5419 "src-generated/ugbc.tab.c"
    break;

  case 381: /* statement: IF expr THEN  */
#line 1379 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5427 "src-generated/ugbc.tab.c"
    break;

  case 382: /* statement: ELSE  */
#line 1382 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 5435 "src-generated/ugbc.tab.c"
    break;

  case 383: /* statement: ELSE IF expr THEN  */
#line 1385 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5443 "src-generated/ugbc.tab.c"
    break;

  case 384: /* statement: ENDIF  */
#line 1388 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5451 "src-generated/ugbc.tab.c"
    break;

  case 385: /* statement: DO  */
#line 1391 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5459 "src-generated/ugbc.tab.c"
    break;

  case 386: /* statement: LOOP  */
#line 1394 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5467 "src-generated/ugbc.tab.c"
    break;

  case 387: /* $@15: %empty  */
#line 1397 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5475 "src-generated/ugbc.tab.c"
    break;

  case 388: /* statement: WHILE $@15 expr  */
#line 1399 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5483 "src-generated/ugbc.tab.c"
    break;

  case 389: /* statement: WEND  */
#line 1402 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5491 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: REPEAT  */
#line 1405 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5499 "src-generated/ugbc.tab.c"
    break;

  case 391: /* statement: UNTIL expr  */
#line 1408 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5507 "src-generated/ugbc.tab.c"
    break;

  case 392: /* statement: EXIT  */
#line 1411 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5515 "src-generated/ugbc.tab.c"
    break;

  case 393: /* statement: EXIT PROC  */
#line 1414 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5523 "src-generated/ugbc.tab.c"
    break;

  case 394: /* statement: POP PROC  */
#line 1417 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5531 "src-generated/ugbc.tab.c"
    break;

  case 395: /* statement: EXIT IF expr  */
#line 1420 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5539 "src-generated/ugbc.tab.c"
    break;

  case 396: /* statement: EXIT Integer  */
#line 1423 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5547 "src-generated/ugbc.tab.c"
    break;

  case 397: /* statement: EXIT direct_integer  */
#line 1426 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5555 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statement: EXIT IF expr COMMA Integer  */
#line 1429 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5563 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1432 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5571 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1435 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5579 "src-generated/ugbc.tab.c"
    break;

  case 401: /* statement: NEXT  */
#line 1438 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5587 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: PROCEDURE Identifier  */
#line 1441 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5596 "src-generated/ugbc.tab.c"
    break;

  case 403: /* $@16: %empty  */
#line 1445 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5604 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1447 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5612 "src-generated/ugbc.tab.c"
    break;

  case 405: /* statement: SHARED parameters_expr  */
#line 1450 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5620 "src-generated/ugbc.tab.c"
    break;

  case 406: /* statement: GLOBAL parameters_expr  */
#line 1453 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5628 "src-generated/ugbc.tab.c"
    break;

  case 407: /* statement: END PROC  */
#line 1456 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 5636 "src-generated/ugbc.tab.c"
    break;

  case 408: /* statement: END PROC OSP expr CSP  */
#line 1459 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5644 "src-generated/ugbc.tab.c"
    break;

  case 409: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1462 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5652 "src-generated/ugbc.tab.c"
    break;

  case 410: /* statement: Identifier " "  */
#line 1465 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5661 "src-generated/ugbc.tab.c"
    break;

  case 411: /* statement: PROC Identifier  */
#line 1469 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5670 "src-generated/ugbc.tab.c"
    break;

  case 412: /* statement: CALL Identifier  */
#line 1473 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5679 "src-generated/ugbc.tab.c"
    break;

  case 413: /* $@17: %empty  */
#line 1477 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5687 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: Identifier OSP $@17 values CSP  */
#line 1479 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5695 "src-generated/ugbc.tab.c"
    break;

  case 415: /* $@18: %empty  */
#line 1482 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5703 "src-generated/ugbc.tab.c"
    break;

  case 416: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1484 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5711 "src-generated/ugbc.tab.c"
    break;

  case 417: /* $@19: %empty  */
#line 1487 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5719 "src-generated/ugbc.tab.c"
    break;

  case 418: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1489 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5727 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: PEN expr  */
#line 1492 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 5735 "src-generated/ugbc.tab.c"
    break;

  case 420: /* statement: PAPER expr  */
#line 1495 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 5743 "src-generated/ugbc.tab.c"
    break;

  case 421: /* statement: INVERSE ON  */
#line 1498 "src/ugbc.y"
               {
      text_inverse( _environment, 1 );
  }
#line 5751 "src-generated/ugbc.tab.c"
    break;

  case 422: /* statement: INVERSE OFF  */
#line 1501 "src/ugbc.y"
                {
      text_inverse( _environment, 0 );
  }
#line 5759 "src-generated/ugbc.tab.c"
    break;

  case 424: /* statement: Identifier COLON  */
#line 1505 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 5767 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: BEG GAMELOOP  */
#line 1508 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 5775 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: END GAMELOOP  */
#line 1511 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 5783 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: GRAPHIC  */
#line 1514 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 5791 "src-generated/ugbc.tab.c"
    break;

  case 428: /* statement: HALT  */
#line 1517 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 5799 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: END  */
#line 1520 "src/ugbc.y"
        {
      end( _environment );
  }
#line 5807 "src-generated/ugbc.tab.c"
    break;

  case 434: /* statement: RETURN  */
#line 1527 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 5815 "src-generated/ugbc.tab.c"
    break;

  case 435: /* statement: RETURN expr  */
#line 1530 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 5823 "src-generated/ugbc.tab.c"
    break;

  case 436: /* statement: POP  */
#line 1533 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 5831 "src-generated/ugbc.tab.c"
    break;

  case 437: /* statement: DONE  */
#line 1536 "src/ugbc.y"
          {
      return 0;
  }
#line 5839 "src-generated/ugbc.tab.c"
    break;

  case 438: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1539 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5847 "src-generated/ugbc.tab.c"
    break;

  case 439: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1542 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5855 "src-generated/ugbc.tab.c"
    break;

  case 440: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1545 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 5863 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1548 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5871 "src-generated/ugbc.tab.c"
    break;

  case 444: /* statement: Identifier ASSIGN expr  */
#line 1553 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 5885 "src-generated/ugbc.tab.c"
    break;

  case 445: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1562 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 5899 "src-generated/ugbc.tab.c"
    break;

  case 446: /* $@20: %empty  */
#line 1571 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5908 "src-generated/ugbc.tab.c"
    break;

  case 447: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1575 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 5921 "src-generated/ugbc.tab.c"
    break;

  case 448: /* $@21: %empty  */
#line 1583 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5930 "src-generated/ugbc.tab.c"
    break;

  case 449: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1586 "src/ugbc.y"
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
#line 5949 "src-generated/ugbc.tab.c"
    break;

  case 450: /* $@22: %empty  */
#line 1600 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5958 "src-generated/ugbc.tab.c"
    break;

  case 451: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1603 "src/ugbc.y"
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
#line 5977 "src-generated/ugbc.tab.c"
    break;

  case 452: /* statement: DEBUG expr  */
#line 1617 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 5985 "src-generated/ugbc.tab.c"
    break;

  case 455: /* statements_no_linenumbers: statement  */
#line 1625 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 5991 "src-generated/ugbc.tab.c"
    break;

  case 456: /* $@23: %empty  */
#line 1626 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 5997 "src-generated/ugbc.tab.c"
    break;

  case 458: /* $@24: %empty  */
#line 1630 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 6005 "src-generated/ugbc.tab.c"
    break;

  case 459: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1632 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 6013 "src-generated/ugbc.tab.c"
    break;

  case 460: /* $@25: %empty  */
#line 1637 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 6021 "src-generated/ugbc.tab.c"
    break;

  case 466: /* $@26: %empty  */
#line 1647 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 6027 "src-generated/ugbc.tab.c"
    break;


#line 6031 "src-generated/ugbc.tab.c"

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

#line 1649 "src/ugbc.y"


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

