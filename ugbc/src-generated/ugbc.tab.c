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
  YYSYMBOL_CENTER = 172,                   /* CENTER  */
  YYSYMBOL_CENTRE = 173,                   /* CENTRE  */
  YYSYMBOL_BLACK = 174,                    /* BLACK  */
  YYSYMBOL_WHITE = 175,                    /* WHITE  */
  YYSYMBOL_RED = 176,                      /* RED  */
  YYSYMBOL_CYAN = 177,                     /* CYAN  */
  YYSYMBOL_VIOLET = 178,                   /* VIOLET  */
  YYSYMBOL_GREEN = 179,                    /* GREEN  */
  YYSYMBOL_BLUE = 180,                     /* BLUE  */
  YYSYMBOL_YELLOW = 181,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 182,                   /* ORANGE  */
  YYSYMBOL_BROWN = 183,                    /* BROWN  */
  YYSYMBOL_LIGHT = 184,                    /* LIGHT  */
  YYSYMBOL_DARK = 185,                     /* DARK  */
  YYSYMBOL_GREY = 186,                     /* GREY  */
  YYSYMBOL_GRAY = 187,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 188,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 189,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 190,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 191,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 192,                /* TURQUOISE  */
  YYSYMBOL_TAN = 193,                      /* TAN  */
  YYSYMBOL_PINK = 194,                     /* PINK  */
  YYSYMBOL_PEACH = 195,                    /* PEACH  */
  YYSYMBOL_OLIVE = 196,                    /* OLIVE  */
  YYSYMBOL_Identifier = 197,               /* Identifier  */
  YYSYMBOL_String = 198,                   /* String  */
  YYSYMBOL_Integer = 199,                  /* Integer  */
  YYSYMBOL_200_ = 200,                     /* " "  */
  YYSYMBOL_YYACCEPT = 201,                 /* $accept  */
  YYSYMBOL_expr = 202,                     /* expr  */
  YYSYMBOL_expr_math = 203,                /* expr_math  */
  YYSYMBOL_term = 204,                     /* term  */
  YYSYMBOL_modula = 205,                   /* modula  */
  YYSYMBOL_factor = 206,                   /* factor  */
  YYSYMBOL_direct_integer = 207,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 208, /* random_definition_simple  */
  YYSYMBOL_random_definition = 209,        /* random_definition  */
  YYSYMBOL_color_enumeration = 210,        /* color_enumeration  */
  YYSYMBOL_exponential = 211,              /* exponential  */
  YYSYMBOL_212_1 = 212,                    /* $@1  */
  YYSYMBOL_213_2 = 213,                    /* $@2  */
  YYSYMBOL_214_3 = 214,                    /* $@3  */
  YYSYMBOL_position = 215,                 /* position  */
  YYSYMBOL_bank_definition_simple = 216,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 217, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 218,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 219, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 220, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 221,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 222, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 223, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 224,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 225,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 226, /* color_definition_expression  */
  YYSYMBOL_color_definition = 227,         /* color_definition  */
  YYSYMBOL_milliseconds = 228,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 229,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 230, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 231,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 232, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 233, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 234,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 235, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 236, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 237,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 238, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 239, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 240,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 241,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 242, /* text_definition_expression  */
  YYSYMBOL_text_definition = 243,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 244,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 245, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 246,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 247, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 248, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 249,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 250, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 251, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 252,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 253,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 254,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 255,         /* gosub_definition  */
  YYSYMBOL_var_definition = 256,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 257,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 258, /* point_definition_expression  */
  YYSYMBOL_point_definition = 259,         /* point_definition  */
  YYSYMBOL_ink_definition = 260,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 261,       /* on_goto_definition  */
  YYSYMBOL_262_4 = 262,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 263,      /* on_gosub_definition  */
  YYSYMBOL_264_5 = 264,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 265,       /* on_proc_definition  */
  YYSYMBOL_266_6 = 266,                    /* $@6  */
  YYSYMBOL_on_definition = 267,            /* on_definition  */
  YYSYMBOL_268_7 = 268,                    /* $@7  */
  YYSYMBOL_269_8 = 269,                    /* $@8  */
  YYSYMBOL_270_9 = 270,                    /* $@9  */
  YYSYMBOL_every_definition = 271,         /* every_definition  */
  YYSYMBOL_add_definition = 272,           /* add_definition  */
  YYSYMBOL_dimensions = 273,               /* dimensions  */
  YYSYMBOL_datatype = 274,                 /* datatype  */
  YYSYMBOL_dim_definition = 275,           /* dim_definition  */
  YYSYMBOL_276_10 = 276,                   /* $@10  */
  YYSYMBOL_277_11 = 277,                   /* $@11  */
  YYSYMBOL_278_12 = 278,                   /* $@12  */
  YYSYMBOL_dim_definitions = 279,          /* dim_definitions  */
  YYSYMBOL_indexes = 280,                  /* indexes  */
  YYSYMBOL_parameters = 281,               /* parameters  */
  YYSYMBOL_parameters_expr = 282,          /* parameters_expr  */
  YYSYMBOL_values = 283,                   /* values  */
  YYSYMBOL_print_definition = 284,         /* print_definition  */
  YYSYMBOL_285_13 = 285,                   /* $@13  */
  YYSYMBOL_286_14 = 286,                   /* $@14  */
  YYSYMBOL_use_definition = 287,           /* use_definition  */
  YYSYMBOL_writing_mode_definition = 288,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 289,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 290,       /* writing_definition  */
  YYSYMBOL_locate_definition = 291,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 292,         /* cmove_definition  */
  YYSYMBOL_statement = 293,                /* statement  */
  YYSYMBOL_294_15 = 294,                   /* $@15  */
  YYSYMBOL_295_16 = 295,                   /* $@16  */
  YYSYMBOL_296_17 = 296,                   /* $@17  */
  YYSYMBOL_297_18 = 297,                   /* $@18  */
  YYSYMBOL_298_19 = 298,                   /* $@19  */
  YYSYMBOL_299_20 = 299,                   /* $@20  */
  YYSYMBOL_300_21 = 300,                   /* $@21  */
  YYSYMBOL_301_22 = 301,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 302, /* statements_no_linenumbers  */
  YYSYMBOL_303_23 = 303,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 304, /* statements_with_linenumbers  */
  YYSYMBOL_305_24 = 305,                   /* $@24  */
  YYSYMBOL_statements_complex = 306,       /* statements_complex  */
  YYSYMBOL_307_25 = 307,                   /* $@25  */
  YYSYMBOL_program = 308,                  /* program  */
  YYSYMBOL_309_26 = 309                    /* $@26  */
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
#define YYLAST   2979

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  201
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  472
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  916

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   455


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
     195,   196,   197,   198,   199,   200
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    75,    75,    76,    80,    84,    87,    90,    93,    96,
      99,   102,   108,   109,   112,   119,   120,   124,   125,   129,
     136,   137,   141,   148,   153,   156,   159,   162,   165,   168,
     171,   176,   181,   185,   189,   193,   197,   201,   205,   209,
     213,   217,   221,   225,   229,   233,   237,   241,   245,   249,
     253,   257,   261,   265,   269,   273,   277,   281,   285,   291,
     291,   302,   302,   313,   316,   319,   328,   332,   339,   343,
     347,   351,   355,   359,   363,   367,   371,   374,   377,   380,
     383,   386,   389,   392,   395,   398,   401,   404,   407,   410,
     413,   416,   419,   422,   425,   428,   431,   434,   437,   440,
     443,   446,   449,   452,   455,   458,   461,   464,   467,   467,
     473,   476,   479,   483,   487,   491,   495,   499,   503,   507,
     511,   515,   518,   521,   524,   527,   530,   533,   536,   541,
     541,   544,   547,   550,   553,   556,   559,   563,   566,   569,
     572,   576,   579,   582,   585,   589,   592,   595,   598,   604,
     607,   610,   613,   616,   621,   622,   625,   628,   633,   636,
     641,   642,   645,   648,   653,   656,   661,   662,   665,   668,
     671,   676,   679,   682,   687,   688,   691,   692,   693,   696,
     699,   702,   707,   710,   713,   719,   720,   723,   726,   729,
     732,   735,   738,   741,   744,   747,   750,   753,   756,   759,
     762,   765,   770,   773,   776,   779,   782,   785,   788,   791,
     794,   797,   800,   803,   806,   809,   812,   817,   818,   821,
     824,   827,   830,   833,   839,   842,   848,   849,   852,   857,
     862,   863,   866,   869,   874,   877,   882,   883,   886,   891,
     896,   897,   900,   903,   906,   911,   914,   920,   921,   924,
     927,   930,   933,   936,   941,   944,   947,   952,   953,   955,
     956,   959,   962,   965,   970,   977,   980,   986,   989,   995,
     998,  1004,  1009,  1010,  1013,  1018,  1022,  1022,  1027,  1031,
    1031,  1036,  1040,  1040,  1045,  1045,  1048,  1048,  1051,  1051,
    1056,  1059,  1062,  1067,  1070,  1076,  1080,  1087,  1090,  1093,
    1096,  1099,  1102,  1105,  1108,  1111,  1114,  1119,  1119,  1127,
    1127,  1135,  1135,  1146,  1147,  1151,  1155,  1162,  1167,  1172,
    1177,  1182,  1187,  1195,  1200,  1205,  1210,  1215,  1220,  1225,
    1229,  1236,  1240,  1247,  1250,  1254,  1257,  1257,  1261,  1261,
    1267,  1270,  1276,  1280,  1284,  1288,  1292,  1299,  1303,  1307,
    1311,  1315,  1322,  1328,  1331,  1334,  1340,  1343,  1346,  1352,
    1353,  1354,  1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,
    1363,  1364,  1365,  1366,  1367,  1368,  1369,  1370,  1371,  1374,
    1377,  1380,  1383,  1386,  1389,  1392,  1395,  1398,  1401,  1404,
    1407,  1410,  1413,  1413,  1418,  1421,  1424,  1427,  1430,  1433,
    1436,  1439,  1442,  1445,  1448,  1451,  1454,  1457,  1461,  1461,
    1466,  1469,  1472,  1475,  1478,  1481,  1485,  1489,  1493,  1493,
    1498,  1498,  1503,  1503,  1508,  1511,  1514,  1517,  1520,  1521,
    1524,  1527,  1530,  1533,  1536,  1539,  1540,  1541,  1542,  1543,
    1546,  1549,  1552,  1555,  1558,  1561,  1564,  1567,  1568,  1569,
    1578,  1587,  1587,  1599,  1599,  1616,  1616,  1633,  1636,  1637,
    1641,  1642,  1642,  1646,  1646,  1653,  1653,  1656,  1657,  1658,
    1659,  1663,  1663
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
  "LOCATE", "CLS", "HOME", "CMOVE", "CENTER", "CENTRE", "BLACK", "WHITE",
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
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455
};
#endif

#define YYPACT_NINF (-786)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-452)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -786,   109,   869,  -786,  -786,   -73,   -65,   -16,  -786,    59,
    2055,   120,     4,  2055,  -786,    65,   263,  2424,   -33,  -111,
    -786,  -786,  -786,  1699,   173,    39,  2424,  2424,   125,   -40,
    -786,   165,   185,  2424,  2424,  -786,   208,   211,   -23,  2424,
      99,   189,  -786,   -48,  -786,  2424,    66,  1877,   236,    76,
    2424,    81,    85,    92,    98,  -154,  -154,  2424,    73,  2424,
     207,   -27,  1150,  -786,  -786,  1343,  2424,  2424,    26,  -786,
     293,   299,   307,  -786,  -786,  -786,  2055,   295,  -786,  -786,
    -786,  2055,  2055,  2055,  -786,  -786,  -786,   131,   328,  1521,
    -786,  -786,   317,   318,   319,   153,   155,  -786,  -786,     2,
     321,   322,  2424,  -786,  -786,   324,   326,   329,   330,   331,
     332,   333,   334,   335,   337,   338,   339,   340,   341,   342,
     343,   344,  -786,  -786,   349,    34,   -38,     6,   364,   365,
    -786,  -786,  -786,  -786,  -786,  -786,  -786,   180,  -786,  -786,
      82,   -41,  -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,
    -786,   209,     7,  -786,  -786,    -4,   195,   256,   140,   260,
      18,  -786,  -786,  -786,  -786,  -786,   -12,   305,    -9,    -6,
      -5,     1,   369,  -786,  -786,  -786,   215,   325,  -786,  -786,
    -786,  2055,  -786,  -786,   366,  -786,  -786,  -786,  -786,  -786,
    2055,   348,   353,  -786,  -786,  -786,   -11,  -786,    42,  -786,
    -786,  -786,  -786,  -786,  2424,  2246,  -786,  -786,   393,  -786,
    -786,  -786,  2055,  -786,  -786,  -786,  2055,   373,  -786,  -786,
    -786,   336,  -786,  -786,  -786,   257,  2424,  2424,  -786,  -786,
    2055,  -786,  -786,  -786,   372,  -786,  -786,  -786,  -786,  -786,
    -786,  -786,  -786,  2424,  2424,  -786,  -786,  -786,  -786,   390,
    -786,  -786,   255,  -786,  2424,   402,  -786,  -786,  -786,    44,
     403,  -786,   264,   265,   266,    60,   407,  -786,  -786,   177,
    -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,
    -786,  -786,   408,  -786,  2424,   409,  -786,  2424,   410,  -786,
    -786,  -786,  -786,  -786,  2424,   405,  -786,  -786,   385,    40,
    1022,  -786,   869,   869,   391,   392,  2055,  -786,  -786,   350,
     351,   352,   354,  -786,   394,   395,   396,   397,   399,   404,
     115,   406,  2055,  2055,  2055,  -786,  -786,  -786,  -786,  -786,
    -786,  -786,  -786,  -786,  -786,   412,  -786,  -786,  2424,  2424,
    -786,  2424,  2424,  2424,  2424,  2424,  2424,  2424,  2424,  2424,
    2424,  2424,  2424,  2424,  2424,  2424,  2424,  2424,  2602,   413,
     228,  -786,  -786,   414,  -786,  -786,   415,   417,  -786,  -786,
    -786,  -786,  -786,  -786,  -786,  -786,   419,  -786,   420,  -786,
    -786,  -786,  -786,  -786,  -786,  2602,  2602,  2602,  2602,  2602,
    2602,  2602,  2602,  2602,  2602,  2602,  2602,  2602,  2780,  -786,
    -786,  -786,  2055,   416,  -786,  -786,  -786,   379,   305,   418,
     305,   431,   305,   432,   305,   434,   305,  -786,  2424,   411,
    -786,  -786,   197,   219,    29,    49,  -786,  -786,  -786,   425,
     305,   428,  -786,  -786,   241,   245,   132,   151,  -786,  -786,
     430,  -786,  -786,  2055,  -786,  -786,  2055,  2055,  -786,  -786,
    -786,   387,   246,  -786,   455,  2424,  -786,  -786,  -786,  -786,
    2055,  -786,  2424,   458,   459,  -786,  -786,  2055,   398,   461,
    2424,   367,   463,  2424,  -786,  -786,  -786,  -786,  -786,  -786,
     171,  -786,  -786,   437,   452,    81,  -786,   327,  -786,  -154,
     466,    40,  -154,   218,   279,   -53,  -786,  2424,  -786,  2424,
     869,  -786,  2424,   441,  2424,  2424,   443,    25,  -786,  1022,
    -786,  -786,   281,   282,  -786,  -786,  2424,   305,  2424,   305,
    2424,   284,   286,   292,   294,   296,   445,   446,   462,  -786,
     464,   465,   467,   468,   470,   472,  2424,   489,   491,   494,
     502,   476,   477,   478,   479,   508,   481,   483,   484,   487,
     488,   517,   518,   492,   493,   495,    14,   345,   496,  2424,
    2424,  2424,   498,  2424,  2424,   256,   256,   258,   258,   258,
     258,   258,   258,   258,   258,   140,   260,   260,  -786,   500,
     504,  2055,   210,  -786,   305,  -786,   305,  -786,   305,  -786,
     305,   105,  -786,  2424,  -786,  -786,  -786,  -786,  -786,  -786,
    -786,  -786,  2424,  -786,   305,  -786,  -786,  -786,  -786,  -786,
    -786,  -786,  -786,   305,  -786,  -786,  -786,  -786,  -786,  -786,
     346,   347,   355,   357,   522,  2424,   529,   497,   503,   389,
    2424,  2424,   531,   539,  -786,   -68,   475,   358,  2424,   541,
    -786,  -786,  -786,   523,   359,   525,  -786,  2424,   363,  2424,
    -786,  -154,   549,  -786,  2424,  2424,   400,   401,  -786,  -786,
    -786,  -786,  -786,  -786,  2424,   554,   421,   555,   528,  2424,
    -786,  -786,  -786,  -786,  -786,  -786,  -786,   557,  -786,  -786,
    -786,  -786,  -786,   371,   374,   375,  -786,  -786,  -786,  -786,
    -786,  -786,   530,  2424,  2424,  2424,  2424,  -786,  -786,  -786,
    -786,  2424,  -786,  -786,  -786,  -786,  -786,  2424,  2424,  -786,
    -786,  -786,  2780,   537,  -786,   540,   559,   569,  2424,   429,
     543,   382,   383,  -786,  -786,  -786,  -786,  -786,  -786,   552,
    -786,   553,  -786,   386,   216,  -786,   578,  -786,   579,   580,
    -786,   581,  -786,   582,  -786,   577,  2055,   587,  2424,  2424,
     305,  -786,   560,   561,  2424,   305,  -786,  -786,  2424,  -786,
      70,  2424,   359,   591,   564,   359,   453,    93,   454,   456,
    -786,  -154,  -786,  -786,  -786,  -786,   565,  2424,  -786,  2424,
     590,   570,  2424,  -786,  -786,  -786,  -786,   571,   572,   103,
     114,   573,   574,   575,   576,  -786,  -786,  2424,  2424,   583,
    -786,  -786,  -786,  -786,   424,   426,  -786,   584,  -786,   585,
    -786,  2424,   305,   605,   609,   610,  2424,  -786,  -786,  2424,
    -786,  -786,  -786,   606,   612,   588,   592,   511,  2424,   616,
     558,   596,   359,  -786,   597,  -786,   363,   626,    40,  -786,
    -786,  -786,   621,  -786,  -786,  2424,   622,   601,  -786,  -786,
    2424,  -786,  2424,  -786,  -786,  -786,  -786,  -786,   603,   607,
    -786,  -786,  -786,   442,   448,   608,   613,   346,   347,   355,
    -786,  -786,  2424,  2424,  -786,  -786,  2424,   614,  2424,  2424,
    -786,  -786,  -786,  -786,   363,   634,  2424,  -786,  2424,  -786,
     615,   617,  -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,
    -786,  -786,  -786,  -786,   638,  -786,  -786,  -786,   363,  -786,
    -786,  -786,  -786,  2424,  -786,  -786
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     471,     0,   459,     1,   458,     0,     0,     0,   442,     0,
       0,   406,     0,     0,   433,     0,     0,     0,   259,     0,
     391,   395,   392,     0,     0,     0,     0,     0,     0,   434,
     389,     0,     0,     0,   384,   432,     0,     0,     0,   439,
     441,   387,   390,   397,   394,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   380,   381,     0,     0,     0,   455,   463,
     460,   467,   469,   472,   382,   383,     0,     0,   160,   161,
     360,     0,     0,     0,   174,   175,   362,     0,     0,     0,
      79,    80,     0,     0,     0,     0,     0,   121,   122,     0,
       0,     0,     0,   112,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   123,     0,     0,     0,     0,     0,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,    44,    49,    50,    51,    52,    53,    54,    57,
      58,     0,    63,    67,    65,     0,     2,    12,    15,    17,
       0,    76,    20,   185,   186,   363,     0,     0,     0,     0,
       0,     0,     0,   154,   155,   359,     0,     0,   217,   218,
     364,     0,   220,   221,   222,   226,   227,   365,   249,   250,
       0,     0,     0,   257,   258,   370,     0,   435,     0,   269,
     373,   265,   266,   436,     0,     0,   232,   233,     0,   236,
     237,   367,     0,   240,   241,   368,     0,   243,   247,   248,
     369,     0,   424,   430,   431,   412,     0,     0,   457,   385,
       0,   230,   231,   366,     0,   272,   273,   371,   267,   268,
     437,   440,   399,     0,     0,   398,   401,   402,   396,     0,
     291,   292,     0,   438,     0,     0,   374,   274,   372,   307,
     313,   447,   416,   407,   417,   323,   329,   410,   411,   333,
     375,   341,   340,   448,   425,   426,   427,   345,   343,   342,
     344,   346,     0,   428,     0,     0,   376,     0,     0,   377,
     378,   379,   465,   429,     0,   453,   418,   415,     0,     0,
     459,   461,   459,   459,     0,     0,     0,   171,   168,     0,
       0,     0,     0,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    24,    25,    27,    29,
      30,    26,    31,   101,    23,     0,   115,   116,     0,     0,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   117,   120,     0,   118,   119,     0,     0,    55,    42,
      45,    46,    47,    48,    43,    56,    64,   108,     0,   176,
     182,   177,   178,   183,   184,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   179,
     180,   181,     0,     0,   166,   167,   361,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,     0,     0,
     207,   208,     0,     0,     0,     0,   204,   203,   129,     0,
       0,     0,   192,   193,     0,     0,     0,     0,   189,   188,
       0,   224,   219,     0,   254,   251,     0,     0,   284,   288,
     286,     0,     0,   393,     0,     0,   239,   238,   245,   242,
       0,   386,     0,     0,     0,   229,   228,     0,     0,   400,
       0,     0,     0,     0,   305,   297,   299,   304,   301,   306,
       0,   303,   311,     0,     0,     0,   420,     0,   422,     0,
     324,     0,     0,   338,   336,     0,   353,   354,   356,   357,
     459,   449,     0,     0,     0,     0,     0,   455,   464,   459,
     468,   470,     0,     0,   158,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,     5,     7,     8,
       9,    10,     6,     3,     4,    16,    18,    19,    21,     0,
       0,     0,     0,   136,     0,   148,     0,   140,     0,   144,
       0,   132,   205,     0,   212,   211,   216,   215,   210,   214,
     209,   213,     0,   190,     0,   197,   196,   201,   200,   195,
     199,   194,   198,     0,   225,   223,   255,   252,   256,   253,
       0,     0,     0,     0,   260,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   388,     0,     0,     0,     0,   293,
     298,   300,   302,     0,     0,     0,   314,     0,     0,     0,
     326,     0,   325,   330,     0,     0,   350,   348,   347,   352,
     355,   358,   466,   450,     0,   331,     0,   315,     0,     0,
     462,   159,   157,   173,   170,   172,   169,     0,    75,    68,
      70,    74,    72,     0,     0,     0,    78,    77,    82,    81,
      84,    83,     0,     0,     0,     0,     0,    91,    92,    93,
     100,     0,    94,    95,    96,    97,    98,     0,     0,   110,
     111,   102,     0,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,   164,   162,   133,   146,   138,   141,   135,
     147,   139,   143,     0,     0,   202,     0,   187,     0,   275,
     285,   278,   289,   281,   287,   261,     0,     0,     0,     0,
       0,   413,     0,     0,     0,     0,   403,   404,     0,   290,
       0,     0,     0,   295,     0,     0,     0,   317,     0,     0,
     327,     0,   339,   337,   351,   349,     0,     0,   419,     0,
       0,     0,     0,    69,    71,    73,   124,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   125,     0,     0,     0,
     109,    60,   165,   163,     0,     0,   149,   134,   145,   137,
     142,     0,     0,     0,     0,     0,     0,   263,   262,     0,
     235,   246,   244,     0,     0,     0,     0,   405,     0,     0,
       0,     0,     0,   308,     0,   421,     0,   318,     0,   409,
     423,   328,     0,   332,   316,     0,     0,     0,    85,    86,
       0,    87,     0,    89,    99,   105,   104,    22,     0,     0,
      62,   151,   153,     0,     0,     0,     0,     0,     0,     0,
     264,   234,     0,     0,   271,   270,     0,     0,     0,     0,
     312,   296,   310,   320,     0,   319,     0,   452,     0,   127,
       0,     0,   128,   126,   150,   152,   206,   191,   277,   280,
     283,   443,   444,   414,     0,   445,   294,   321,     0,   454,
     456,    88,    90,     0,   322,   446
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -786,   -10,   -67,   -76,   252,  -231,    74,  -786,  -786,  -786,
    -394,  -786,  -786,  -786,   480,  -786,  -786,  -786,  -786,  -786,
    -786,  -786,  -786,  -786,  -786,  -786,  -786,   499,  -786,  -786,
    -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,
    -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,
    -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,
    -214,  -786,  -212,  -786,  -215,  -786,  -786,  -786,  -786,  -786,
    -786,  -786,  -704,  -298,  -786,  -786,  -786,  -786,   176,  -558,
    -785,   -54,  -554,  -339,  -786,  -786,  -786,  -786,  -786,  -786,
    -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,  -786,
    -786,  -295,  -786,  -786,  -786,  -292,  -786,  -786,  -786
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   667,   156,   157,   158,   159,   160,   332,   333,   161,
     162,   378,   562,   563,   429,   173,   174,   175,    78,    79,
      80,   404,   405,   406,    84,    85,    86,   384,   163,   164,
     165,   178,   179,   180,   185,   186,   187,   231,   232,   233,
     209,   210,   211,   213,   214,   215,   218,   219,   220,   193,
     194,   195,   199,   203,   240,   200,   235,   236,   237,   258,
     740,   813,   742,   814,   744,   815,   197,   620,   622,   621,
     253,   256,   764,   482,   260,   483,   484,   643,   261,   668,
     768,   267,   666,   270,   655,   654,   273,   282,   659,   283,
     286,   289,    70,   204,   487,   504,   647,   649,   298,   503,
     299,    71,   509,    72,   300,    73,   500,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     155,   506,   268,   176,   578,   508,   720,   196,    76,   719,
     510,   511,   402,   208,    96,   408,   221,   222,   410,   412,
     244,   712,   335,   228,   229,   414,   363,   376,   167,   241,
     292,   293,   293,   656,    96,   248,   168,   252,   294,   294,
     257,   -59,   448,   265,   266,   295,   295,   269,   361,   274,
     224,   883,   285,   169,   359,   288,   290,   291,   831,  -451,
    -451,   834,   451,   216,  -309,   474,   304,   489,   360,   474,
     277,   307,   309,   311,   598,   379,   380,   828,   278,   321,
     490,   170,   171,   599,   452,    81,   201,   177,   202,   181,
      82,   449,   340,   766,   600,   769,   245,   379,   399,   907,
     836,   182,   183,   601,   225,   829,   776,   657,   491,     3,
     850,   781,   658,   837,   475,   476,   477,   247,   475,   476,
     477,   852,   362,   914,    74,   478,   217,   556,   881,   478,
      83,   756,    75,   450,   733,   279,   280,   281,   851,   373,
     336,   838,   166,   398,   364,   374,   381,   382,   383,   853,
     305,   246,   184,   734,   377,   308,   310,   312,   337,   396,
     799,   397,   365,   479,   198,   576,   577,   479,   381,   382,
     400,   441,   296,   296,   238,   480,   239,   609,   325,   480,
     444,    77,   493,   481,   494,   403,   610,   481,   409,   526,
     527,   411,   413,   652,   453,   454,   611,   212,   415,   226,
     528,   172,   456,   385,   386,   612,   458,   387,   662,   388,
     389,   390,   391,   392,   670,   223,   463,   464,  -335,   227,
     465,   844,  -335,   843,  -335,   297,   297,   326,   327,   328,
     271,   272,   230,   468,   469,   234,   329,   330,   331,   417,
     418,   407,   725,   242,   472,   640,   641,   419,   807,   275,
     276,   420,   421,   594,   595,   442,   642,   243,   369,   726,
     422,   370,   371,   249,   445,   808,   385,   386,   372,   423,
     254,   424,   425,   255,   496,   596,   597,   498,   259,  -334,
     426,   427,   262,  -334,   501,  -334,   457,   727,   728,   263,
     459,   428,   393,   809,   810,   264,   514,   605,   606,   301,
     394,   607,   608,   302,   466,   188,   189,   190,   191,   565,
     566,   303,   530,   532,   534,   772,   773,   192,   794,   306,
     567,   568,   569,   570,   571,   572,   573,   574,   537,   538,
     313,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   314,   417,
     430,   322,   323,   324,   334,   338,   339,   431,   341,   368,
     342,   432,   433,   343,   344,   345,   346,   347,   348,   349,
     434,   350,   351,   352,   353,   354,   355,   356,   357,   435,
     515,   436,   437,   358,   366,   367,   395,    96,   375,   398,
     438,   439,   579,   416,   446,   443,   531,   533,   535,   447,
     455,   428,   460,   470,   462,   461,   467,   471,   592,   473,
     485,   486,  -408,   488,   492,   495,   497,   499,   502,   505,
     512,   513,   516,   517,   518,   558,   519,   582,   520,   623,
     521,   522,   523,   614,   524,   650,   616,   618,   653,   525,
     581,   529,   584,   624,   593,   626,   536,   557,   559,   560,
     627,   561,   629,   -61,   564,   586,   588,   632,   590,   602,
     636,   604,   625,   639,   613,   630,   631,   634,   635,   637,
     638,   644,   645,   651,   648,   664,   580,   669,   671,   672,
     683,   684,   583,   678,   585,   679,   587,   660,   589,   661,
     591,   680,   663,   681,   665,   682,   693,   685,   694,   686,
     687,   695,   688,   689,   603,   690,   673,   691,   675,   696,
     677,   697,   698,   699,   700,   701,   702,   615,   703,   704,
     617,   619,   705,   706,   707,   708,   692,   709,   710,   721,
     711,   714,   718,   722,   628,   746,   748,   751,   754,   749,
     885,   633,   713,   739,   741,   750,   755,   758,   761,   715,
     716,   717,   743,   665,   745,   759,   771,   762,   763,   765,
     767,   777,   779,   780,   782,   786,   797,   774,   775,   778,
     783,   723,   795,   784,   785,   796,   798,   800,   801,   802,
     803,   804,   805,   735,   806,   811,   812,  -276,  -279,  -282,
     816,   674,   736,   676,   819,   823,   824,   770,   832,   833,
     842,   835,   839,   845,   840,   846,   848,   849,   854,   855,
     856,   857,   867,   863,   864,   747,   868,   869,   860,   872,
     752,   753,   861,   874,   862,   873,   876,   875,   760,   878,
     879,   880,   882,   884,   886,   888,   889,   665,   892,   665,
     894,   908,   893,   896,   269,   269,   895,   575,   897,   904,
     911,   913,   912,   898,   900,   724,   899,   440,   729,   401,
     730,   646,   731,     0,   732,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   737,     0,
       0,     0,     0,   787,   788,   789,   790,   738,     0,     0,
       0,   791,     0,     0,     0,     0,     0,   792,   793,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   757,
       0,     0,     0,     0,     0,     0,     0,   841,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   817,     0,   820,   821,
       0,     0,     0,     0,   825,     0,     0,     0,   827,     0,
       0,   830,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   665,     0,     0,
       0,     0,   847,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   858,   859,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   865,     0,     0,     0,     0,   870,     0,     0,   871,
       0,     0,     0,     0,     0,     0,     0,     0,   877,     0,
     818,     0,     0,     0,   822,     0,     0,     0,     0,   826,
       0,     0,     0,     0,     0,   887,     0,     0,     0,     0,
     890,     0,   891,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   901,   902,     0,     0,   903,     0,   905,   906,
       0,     0,     4,     0,     0,     0,   909,     0,   910,     5,
       6,     0,     0,     0,     0,     0,   866,     0,     0,     0,
       0,     7,     8,     0,     9,     0,    10,    11,     0,    12,
      13,     0,     0,   915,     0,     0,     0,    14,     0,    15,
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
       0,     0,    56,     0,    57,     4,     0,     0,    58,    59,
      60,     0,     5,     6,     0,    61,     0,    62,    63,    64,
      65,    66,    67,     0,     7,     8,     0,     9,     0,    10,
      11,     0,    12,    13,     0,     0,     0,     0,     0,     0,
      14,     0,    15,    16,    17,     0,    68,     0,    69,    18,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
      28,    29,     0,    30,     0,     0,    31,    32,    33,     0,
      34,    35,    36,    37,    38,    39,    40,     0,    41,     0,
       0,     0,    42,    43,    44,    45,    46,     0,    47,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,     0,   284,     0,    87,
       0,    50,     0,     0,    51,     0,    52,    53,    54,     0,
       0,    55,     0,     0,    88,    56,     0,    57,     0,     0,
       0,    58,    59,    60,    89,     0,     0,     0,    61,     0,
      62,    63,    64,    65,    66,    67,     0,     0,     0,     0,
      90,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,     0,   507,
      94,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,     0,    99,     0,     0,     0,
       0,     0,     0,     0,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
       0,     0,     0,     0,     0,     0,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,     0,   117,   118,   119,     0,   120,   121,   122,     0,
     123,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,     0,   126,     0,     0,     0,
     127,     0,     0,     0,     0,     0,     0,     0,   128,     0,
       0,   129,     0,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,     0,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     287,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,    94,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,    98,     0,    99,
       0,     0,     0,     0,     0,     0,     0,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     102,   103,   104,     0,     0,     0,     0,     0,     0,     0,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,     0,     0,   117,   118,   119,     0,   120,
     121,   122,     0,   123,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,     0,   126,
       0,     0,     0,   127,     0,     0,     0,     0,     0,     0,
       0,   128,     0,     0,   129,     0,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
      87,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,     0,    88,   315,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,     0,
       0,    94,     0,     0,    95,   316,   317,   318,     0,     0,
       0,     0,     0,     0,    97,    98,   319,    99,     0,     0,
       0,     0,     0,     0,     0,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,   117,   118,   119,   320,   120,   121,   122,
       0,   123,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,     0,   126,     0,     0,
       0,   127,     0,     0,     0,     0,     0,     0,     0,   128,
       0,     0,   129,     0,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    87,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,     0,   205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,   206,   207,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,     0,     0,    94,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    98,     0,    99,     0,     0,     0,     0,
       0,     0,     0,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,     0,
       0,   117,   118,   119,     0,   120,   121,   122,     0,   123,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,   126,     0,     0,     0,   127,
       0,     0,     0,     0,     0,     0,     0,   128,     0,     0,
     129,     0,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    87,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,   250,
     251,     0,     0,     0,     0,     0,     0,    90,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,     0,     0,    94,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,    98,     0,    99,     0,     0,     0,     0,     0,     0,
       0,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,   117,
     118,   119,     0,   120,   121,   122,     0,   123,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,     0,   126,     0,     0,     0,   127,     0,     0,
       0,     0,     0,     0,     0,   128,     0,     0,   129,     0,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    87,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,    94,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,    99,     0,     0,     0,     0,     0,     0,     0,   100,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,   117,   118,   119,
       0,   120,   121,   122,     0,   123,   124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
       0,   126,     0,     0,     0,   127,     0,     0,     0,     0,
       0,     0,     0,   128,     0,     0,   129,     0,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,     0,     0,     0,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,    94,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      98,     0,    99,     0,     0,     0,     0,     0,     0,     0,
     100,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,     0,     0,     0,     0,
       0,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,     0,     0,   117,   118,
     119,     0,   120,   121,   122,     0,   123,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,     0,   126,     0,     0,     0,   127,     0,     0,     0,
       0,     0,     0,     0,   128,     0,     0,   129,     0,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    87,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,    94,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,     0,
      99,     0,     0,     0,     0,     0,     0,     0,   100,   101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,     0,     0,   117,   118,   119,     0,
     120,   121,   122,     0,   123,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   125,     0,
     126,     0,     0,     0,   127,     0,     0,     0,     0,     0,
       0,     0,   128,     0,     0,   129,     0,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,    87,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
       0,     0,    94,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    98,     0,    99,     0,
       0,     0,     0,     0,     0,     0,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,   104,     0,     0,     0,     0,     0,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,     0,     0,   117,   118,   119,     0,   120,   121,
     122,     0,   123,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,     0,   126,     0,
       0,     0,   127,     0,     0,     0,     0,     0,     0,     0,
     128,     0,     0,   129,     0,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,    87,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,     0,     0,
      94,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,     0,    99,     0,     0,     0,
       0,     0,     0,     0,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,   104,
       0,     0,     0,     0,     0,     0,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,     0,   117,   118,   119,     0,   120,   121,   122,     0,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,     0,   126,     0,     0,     0,
     127,     0,     0,     0,     0,     0,     0,     0,   128,     0,
       0,   129,     0,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,     0,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154
};

static const yytype_int16 yycheck[] =
{
      10,   299,    56,    13,   398,   300,   564,    17,    24,   563,
     302,   303,    24,    23,    82,    24,    26,    27,    24,    24,
      68,     7,    20,    33,    34,    24,    20,    20,    24,    39,
       4,     6,     6,    86,    82,    45,    32,    47,    13,    13,
      50,    34,    53,   197,   198,    20,    20,    57,    86,    59,
      90,   836,    62,    49,    20,    65,    66,    67,   762,    34,
      34,   765,    20,    24,    20,    25,    76,     7,    34,    25,
      97,    81,    82,    83,    45,    79,    80,     7,   105,    89,
      20,    77,    78,    54,    42,    26,   197,    13,   199,    24,
      31,   102,   102,   647,    45,   649,   144,    79,    80,   884,
       7,    36,    37,    54,   144,    35,   664,   160,    48,     0,
       7,   669,   165,    20,    74,    75,    76,    43,    74,    75,
      76,     7,   160,   908,   197,    85,    87,   358,   832,    85,
      71,   199,   197,   144,    29,   162,   163,   164,    35,   180,
     138,    48,    22,   129,   138,   186,   150,   151,   152,    35,
      76,   199,    87,    48,   147,    81,    82,    83,   156,    19,
     718,    21,   156,   123,   197,   396,   397,   123,   150,   151,
     152,   181,   147,   147,   197,   135,   199,    45,    25,   135,
     190,   197,     5,   143,     7,   197,    54,   143,   197,    74,
      75,   197,   197,   491,   204,   205,    45,    24,   197,    34,
      85,   197,   212,     8,     9,    54,   216,    12,   500,    14,
      15,    16,    17,    18,   509,    90,   226,   227,     0,    34,
     230,   779,     4,   777,     6,   200,   200,    74,    75,    76,
     157,   158,    24,   243,   244,    24,    83,    84,    85,    24,
      25,   167,    32,   144,   254,    74,    75,    32,    32,    42,
      43,    36,    37,    56,    57,   181,    85,    68,   176,    49,
      45,   179,   180,   197,   190,    49,     8,     9,   186,    54,
      34,    56,    57,   197,   284,    56,    57,   287,   197,     0,
      65,    66,   197,     4,   294,     6,   212,    77,    78,   197,
     216,    76,    97,    77,    78,   197,   306,    56,    57,     6,
     105,    56,    57,     4,   230,    42,    43,    44,    45,   385,
     386,     4,   322,   323,   324,   654,   655,    54,   712,    24,
     387,   388,   389,   390,   391,   392,   393,   394,   338,   339,
     199,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,    20,    24,
      25,    34,    34,    34,   199,    34,    34,    32,    34,   179,
      34,    36,    37,    34,    34,    34,    34,    34,    34,    34,
      45,    34,    34,    34,    34,    34,    34,    34,    34,    54,
     306,    56,    57,    34,    20,    20,   130,    82,   179,   129,
      65,    66,   402,    24,    46,    29,   322,   323,   324,    46,
       7,    76,    29,    13,   147,    69,    34,   152,   418,     7,
       7,   147,   147,   147,     7,     7,     7,     7,    13,    34,
      29,    29,    72,    72,    72,   197,    72,    48,    34,    42,
      35,    35,    35,   443,    35,   489,   446,   447,   492,    35,
      24,    35,    24,   197,    33,   455,    34,    34,    34,    34,
     460,    34,   462,    34,    34,    24,    24,   467,    24,    34,
     470,    33,     7,   473,    34,     7,     7,    69,     7,   102,
       7,    34,    20,     7,   147,    34,   402,    34,   197,   197,
      35,    35,   408,   199,   410,   199,   412,   497,   414,   499,
     416,   199,   502,   199,   504,   199,     7,    35,     7,    35,
      35,     7,    35,    35,   430,    35,   516,    35,   518,     7,
     520,    35,    35,    35,    35,     7,    35,   443,    35,    35,
     446,   447,    35,    35,     7,     7,   536,    35,    35,    29,
      35,    35,    34,    29,   460,    13,     7,   148,     7,    42,
     838,   467,   197,   197,   197,    42,     7,    72,     7,   559,
     560,   561,   197,   563,   197,   197,     7,    34,   199,    34,
     197,     7,     7,    35,     7,    35,     7,   167,   167,   148,
     199,   581,    35,   199,   199,    35,     7,   148,    35,   197,
     197,    29,    29,   593,   198,     7,     7,     7,     7,     7,
      13,   517,   602,   519,     7,    35,    35,   651,     7,    35,
      35,   148,   148,    13,   148,    35,    35,    35,    35,    35,
      35,    35,     7,    29,    29,   625,     7,     7,    35,    13,
     630,   631,   198,    35,   198,    13,   115,    35,   638,    13,
      72,    35,    35,     7,    13,    13,    35,   647,    35,   649,
     198,     7,    35,    35,   654,   655,   198,   395,    35,    35,
      35,    13,    35,   867,   869,   581,   868,   177,   584,   160,
     586,   485,   588,    -1,   590,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   604,    -1,
      -1,    -1,    -1,   693,   694,   695,   696,   613,    -1,    -1,
      -1,   701,    -1,    -1,    -1,    -1,    -1,   707,   708,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   635,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   771,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   746,    -1,   748,   749,
      -1,    -1,    -1,    -1,   754,    -1,    -1,    -1,   758,    -1,
      -1,   761,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   777,    -1,    -1,
      -1,    -1,   782,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   797,   798,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   811,    -1,    -1,    -1,    -1,   816,    -1,    -1,   819,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   828,    -1,
     746,    -1,    -1,    -1,   750,    -1,    -1,    -1,    -1,   755,
      -1,    -1,    -1,    -1,    -1,   845,    -1,    -1,    -1,    -1,
     850,    -1,   852,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   872,   873,    -1,    -1,   876,    -1,   878,   879,
      -1,    -1,     3,    -1,    -1,    -1,   886,    -1,   888,    10,
      11,    -1,    -1,    -1,    -1,    -1,   812,    -1,    -1,    -1,
      -1,    22,    23,    -1,    25,    -1,    27,    28,    -1,    30,
      31,    -1,    -1,   913,    -1,    -1,    -1,    38,    -1,    40,
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
      -1,    -1,   153,    -1,   155,     3,    -1,    -1,   159,   160,
     161,    -1,    10,    11,    -1,   166,    -1,   168,   169,   170,
     171,   172,   173,    -1,    22,    23,    -1,    25,    -1,    27,
      28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    40,    41,    42,    -1,   197,    -1,   199,    47,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      88,    89,    -1,    91,    -1,    -1,    94,    95,    96,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,    -1,   116,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,     7,    -1,     9,
      -1,   139,    -1,    -1,   142,    -1,   144,   145,   146,    -1,
      -1,   149,    -1,    -1,    24,   153,    -1,   155,    -1,    -1,
      -1,   159,   160,   161,    34,    -1,    -1,    -1,   166,    -1,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,   197,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,   132,   133,   134,    -1,   136,   137,   138,    -1,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,    -1,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,
      -1,   171,    -1,    -1,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
       7,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   168,    -1,    -1,   171,    -1,    -1,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       9,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,    -1,    -1,    24,    25,    -1,    -1,    -1,
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
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
      -1,    -1,   171,    -1,    -1,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     9,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,   137,   138,    -1,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   154,    -1,   156,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,
     171,    -1,    -1,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     9,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,   156,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,   171,    -1,
      -1,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     9,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,   136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,
      -1,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   168,    -1,    -1,   171,    -1,    -1,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     154,    -1,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   168,    -1,    -1,   171,    -1,    -1,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     9,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,
     136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
     156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   168,    -1,    -1,   171,    -1,    -1,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     9,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,
     138,    -1,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,    -1,
      -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     168,    -1,    -1,   171,    -1,    -1,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     9,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,
      -1,   171,    -1,    -1,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,    -1,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   308,   309,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    86,    88,    89,
      91,    94,    95,    96,    98,    99,   100,   101,   102,   103,
     104,   106,   110,   111,   112,   113,   114,   116,   117,   131,
     139,   142,   144,   145,   146,   149,   153,   155,   159,   160,
     161,   166,   168,   169,   170,   171,   172,   173,   197,   199,
     293,   302,   304,   306,   197,   197,    24,   197,   219,   220,
     221,    26,    31,    71,   225,   226,   227,     9,    24,    34,
      50,    51,    52,    67,    70,    73,    82,    83,    84,    86,
      94,    95,   107,   108,   109,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   132,   133,   134,
     136,   137,   138,   140,   141,   154,   156,   160,   168,   171,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   202,   203,   204,   205,   206,
     207,   210,   211,   229,   230,   231,    22,    24,    32,    49,
      77,    78,   197,   216,   217,   218,   202,   207,   232,   233,
     234,    24,    36,    37,    87,   235,   236,   237,    42,    43,
      44,    45,    54,   250,   251,   252,   202,   267,   197,   253,
     256,   197,   199,   254,   294,    24,    36,    37,   202,   241,
     242,   243,    24,   244,   245,   246,    24,    87,   247,   248,
     249,   202,   202,    90,    90,   144,    34,    34,   202,   202,
      24,   238,   239,   240,    24,   257,   258,   259,   197,   199,
     255,   202,   144,    68,    68,   144,   199,   207,   202,   197,
      42,    43,   202,   271,    34,   197,   272,   202,   260,   197,
     275,   279,   197,   197,   197,   197,   198,   282,   282,   202,
     284,   157,   158,   287,   202,    42,    43,    97,   105,   162,
     163,   164,   288,   290,     7,   202,   291,     7,   202,   292,
     202,   202,     4,     6,    13,    20,   147,   200,   299,   301,
     305,     6,     4,     4,   202,   207,    24,   202,   207,   202,
     207,   202,   207,   199,    20,    25,    74,    75,    76,    85,
     135,   202,    34,    34,    34,    25,    74,    75,    76,    83,
      84,    85,   208,   209,   199,    20,   138,   156,    34,    34,
     202,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    20,
      34,    86,   160,    20,   138,   156,    20,    20,   179,   176,
     179,   180,   186,   180,   186,   179,    20,   147,   212,    79,
      80,   150,   151,   152,   228,     8,     9,    12,    14,    15,
      16,    17,    18,    97,   105,   130,    19,    21,   129,    80,
     152,   228,    24,   197,   222,   223,   224,   207,    24,   197,
      24,   197,    24,   197,    24,   197,    24,    24,    25,    32,
      36,    37,    45,    54,    56,    57,    65,    66,    76,   215,
      25,    32,    36,    37,    45,    54,    56,    57,    65,    66,
     215,   202,   207,    29,   202,   207,    46,    46,    53,   102,
     144,    20,    42,   202,   202,     7,   202,   207,   202,   207,
      29,    69,   147,   202,   202,   202,   207,    34,   202,   202,
      13,   152,   202,     7,    25,    74,    75,    76,    85,   123,
     135,   143,   274,   276,   277,     7,   147,   295,   147,     7,
      20,    48,     7,     5,     7,     7,   202,     7,   202,     7,
     307,   202,    13,   300,   296,    34,   274,   197,   302,   303,
     306,   306,    29,    29,   202,   207,    72,    72,    72,    72,
      34,    35,    35,    35,    35,    35,    74,    75,    85,    35,
     202,   207,   202,   207,   202,   207,    34,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   206,    34,   197,    34,
      34,    34,   213,   214,    34,   204,   204,   203,   203,   203,
     203,   203,   203,   203,   203,   205,   206,   206,   211,   202,
     207,    24,    48,   207,    24,   207,    24,   207,    24,   207,
      24,   207,   202,    33,    56,    57,    56,    57,    45,    54,
      45,    54,    34,   207,    33,    56,    57,    56,    57,    45,
      54,    45,    54,    34,   202,   207,   202,   207,   202,   207,
     268,   270,   269,    42,   197,     7,   202,   202,   207,   202,
       7,     7,   202,   207,    69,     7,   202,   102,     7,   202,
      74,    75,    85,   278,    34,    20,   279,   297,   147,   298,
     282,     7,   274,   282,   286,   285,    86,   160,   165,   289,
     202,   202,   306,   202,    34,   202,   283,   202,   280,    34,
     302,   197,   197,   202,   207,   202,   207,   202,   199,   199,
     199,   199,   199,    35,    35,    35,    35,    35,    35,    35,
      35,    35,   202,     7,     7,     7,     7,    35,    35,    35,
      35,     7,    35,    35,    35,    35,    35,     7,     7,    35,
      35,    35,     7,   197,    35,   202,   202,   202,    34,   283,
     280,    29,    29,   202,   207,    32,    49,    77,    78,   207,
     207,   207,   207,    29,    48,   202,   202,   207,   207,   197,
     261,   197,   263,   197,   265,   197,    13,   202,     7,    42,
      42,   148,   202,   202,     7,     7,   199,   207,    72,   197,
     202,     7,    34,   199,   273,    34,   283,   197,   281,   283,
     282,     7,   284,   284,   167,   167,   280,     7,   148,     7,
      35,   280,     7,   199,   199,   199,    35,   202,   202,   202,
     202,   202,   202,   202,   211,    35,    35,     7,     7,   280,
     148,    35,   197,   197,    29,    29,   198,    32,    49,    77,
      78,     7,     7,   262,   264,   266,    13,   202,   207,     7,
     202,   202,   207,    35,    35,   202,   207,   202,     7,    35,
     202,   273,     7,    35,   273,   148,     7,    20,    48,   148,
     148,   282,    35,   283,   280,    13,    35,   202,    35,    35,
       7,    35,     7,    35,    35,    35,    35,    35,   202,   202,
      35,   198,   198,    29,    29,   202,   207,     7,     7,     7,
     202,   202,    13,    13,    35,    35,   115,   202,    13,    72,
      35,   273,    35,   281,     7,   274,    13,   202,    13,    35,
     202,   202,    35,    35,   198,   198,    35,    35,   261,   263,
     265,   202,   202,   202,    35,   202,   202,   281,     7,   202,
     202,    35,    35,    13,   281,   202
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   201,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   203,   203,   203,   204,   204,   205,   205,   205,
     206,   206,   206,   207,   208,   208,   208,   208,   208,   208,
     208,   209,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   212,
     211,   213,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   214,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   215,
     215,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   217,
     217,   217,   217,   217,   218,   218,   219,   219,   220,   220,
     221,   221,   222,   222,   223,   223,   224,   224,   225,   225,
     225,   226,   226,   226,   227,   227,   228,   228,   228,   229,
     229,   229,   230,   230,   230,   231,   231,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   234,   234,   235,
     235,   235,   235,   235,   236,   236,   237,   237,   238,   239,
     240,   240,   241,   241,   242,   242,   243,   243,   244,   245,
     246,   246,   247,   247,   247,   248,   248,   249,   249,   250,
     250,   250,   250,   250,   251,   251,   251,   252,   252,   253,
     253,   253,   253,   253,   253,   254,   254,   255,   255,   256,
     257,   258,   259,   259,   260,   261,   262,   261,   263,   264,
     263,   265,   266,   265,   268,   267,   269,   267,   270,   267,
     271,   271,   271,   272,   272,   273,   273,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   276,   275,   277,
     275,   278,   275,   279,   279,   280,   280,   281,   281,   281,
     281,   281,   281,   282,   282,   282,   282,   282,   282,   282,
     282,   283,   283,   284,   284,   284,   285,   284,   286,   284,
     287,   287,   288,   288,   288,   288,   288,   289,   289,   289,
     289,   289,   290,   291,   291,   291,   292,   292,   292,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   294,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   295,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   296,   293,
     297,   293,   298,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   299,   293,   300,   293,   301,   293,   293,   293,   293,
     302,   303,   302,   305,   304,   307,   306,   306,   306,   306,
     306,   309,   308
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
       2,     1,     1,     1,     5,     5,     7,     7,     7,     1,
       1,     2,     3,     4,     5,     4,     3,     5,     4,     4,
       3,     4,     5,     4,     3,     5,     4,     4,     3,     5,
       7,     6,     7,     6,     1,     1,     3,     4,     3,     4,
       1,     1,     3,     4,     3,     4,     1,     1,     2,     4,
       4,     2,     4,     4,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     1,     1,     4,     2,     2,
       3,     7,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     2,     2,     3,     7,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       1,     1,     1,     3,     2,     3,     1,     1,     2,     2,
       1,     1,     1,     1,     6,     5,     1,     1,     2,     2,
       1,     1,     2,     1,     5,     2,     5,     1,     1,     1,
       1,     2,     3,     3,     2,     3,     3,     1,     1,     0,
       3,     4,     5,     5,     6,     1,     1,     1,     1,     1,
       6,     6,     1,     1,     1,     1,     0,     4,     1,     0,
       4,     1,     0,     4,     0,     4,     0,     4,     0,     4,
       4,     1,     1,     3,     7,     1,     3,     1,     2,     1,
       2,     1,     2,     1,     1,     1,     1,     0,     5,     0,
       6,     0,     6,     1,     3,     1,     3,     1,     2,     3,
       3,     4,     5,     1,     2,     3,     3,     4,     5,     1,
       3,     1,     3,     1,     2,     2,     0,     4,     0,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     3,     2,     2,     3,     2,     2,     3,     2,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     2,     2,     1,     2,     3,     1,     4,     1,
       1,     1,     0,     3,     1,     1,     2,     1,     2,     2,
       3,     2,     2,     5,     5,     6,     1,     2,     0,     6,
       2,     2,     2,     5,     8,     2,     2,     2,     0,     5,
       0,     6,     0,     6,     2,     2,     2,     2,     2,     2,
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
#line 76 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2865 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 80 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2874 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 84 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2882 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 87 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2890 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 90 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2898 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 93 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2906 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 96 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2914 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 99 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2922 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 102 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2930 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 109 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2938 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 112 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2947 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 125 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2956 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 129 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2965 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 137 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2974 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 141 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 2983 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 148 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2991 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 153 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2999 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 156 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3007 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 159 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3015 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 162 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3023 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 165 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3031 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 168 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3039 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 171 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3047 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 176 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3055 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 181 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3064 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 185 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3073 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 189 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3082 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 193 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3091 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 197 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3100 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 201 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3109 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 205 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3118 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 209 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3127 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 213 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3136 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 217 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3145 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 221 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3154 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 225 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3163 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 229 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3172 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 233 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3181 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 237 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3190 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 241 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3199 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 245 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3208 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 249 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3217 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 253 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3226 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 257 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3235 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 261 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3244 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 265 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3253 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 269 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3262 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 273 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3271 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 277 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3280 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 281 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3289 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 285 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3298 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 291 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3307 "src-generated/ugbc.tab.c"
    break;

  case 60: /* exponential: Identifier $@1 OP indexes CP  */
#line 295 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-4].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-4].string) )->name;
    }
#line 3319 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 302 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3328 "src-generated/ugbc.tab.c"
    break;

  case 62: /* exponential: Identifier DOLLAR $@2 OP indexes CP  */
#line 306 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-5].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-5].string) )->name;
    }
#line 3340 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 313 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3348 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 316 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3356 "src-generated/ugbc.tab.c"
    break;

  case 65: /* exponential: Integer  */
#line 319 "src/ugbc.y"
              { 
        if ( (yyvsp[0].integer) < 0 ) {
            (yyval.string) = variable_temporary( _environment, VT_SWORD, "(signed integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        } else {
            (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        }
      }
#line 3370 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 328 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3379 "src-generated/ugbc.tab.c"
    break;

  case 67: /* exponential: String  */
#line 332 "src/ugbc.y"
             { 
        outline1("; (expr string: \"%s\")", (yyvsp[0].string) );
        (yyval.string) = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", (yyval.string) );
        variable_store_string( _environment, (yyval.string), (yyvsp[0].string) );
        outline2("; variable stored: %s = %s", (yyval.string), (yyvsp[0].string) );
      }
#line 3391 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 339 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3400 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 343 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3409 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 347 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3418 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 351 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3427 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 355 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3436 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 359 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3445 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 363 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3454 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 367 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3463 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 371 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3471 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 374 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3479 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 377 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3487 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 380 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3495 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 383 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3503 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 386 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3511 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 389 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3519 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 392 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3527 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 395 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3535 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 398 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3543 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 401 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3551 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 404 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3559 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 407 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3567 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 410 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3575 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 413 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3583 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 416 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3591 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 419 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3599 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 422 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3607 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 425 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3615 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 428 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3623 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 431 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3631 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 434 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3639 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 437 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3647 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 440 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3655 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 443 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3663 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 446 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3671 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 449 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3679 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 452 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3687 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 455 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3695 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 458 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3703 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 461 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3711 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 464 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3719 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 467 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3727 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 469 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3736 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 473 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3744 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 476 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3752 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 479 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3761 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 483 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3770 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 487 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3779 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: PEN COLORS  */
#line 491 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3788 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: PEN DEFAULT  */
#line 495 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3797 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: DEFAULT PEN  */
#line 499 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3806 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: PAPER COLORS  */
#line 503 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3815 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: PAPER DEFAULT  */
#line 507 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3824 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: DEFAULT PAPER  */
#line 511 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3833 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: WIDTH  */
#line 515 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3841 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: HEIGHT  */
#line 518 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3849 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: TIMER  */
#line 521 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3857 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PEN DOLLAR OP expr CP  */
#line 524 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 3865 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER DOLLAR OP expr CP  */
#line 527 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3873 "src-generated/ugbc.tab.c"
    break;

  case 126: /* exponential: CMOVE DOLLAR OP expr COMMA expr CP  */
#line 530 "src/ugbc.y"
                                         {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3881 "src-generated/ugbc.tab.c"
    break;

  case 127: /* exponential: AT DOLLAR OP expr COMMA expr CP  */
#line 533 "src/ugbc.y"
                                      {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3889 "src-generated/ugbc.tab.c"
    break;

  case 128: /* exponential: LOCATE DOLLAR OP expr COMMA expr CP  */
#line 536 "src/ugbc.y"
                                          {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3897 "src-generated/ugbc.tab.c"
    break;

  case 131: /* bank_definition_simple: AT direct_integer  */
#line 544 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3905 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_simple: Identifier AT direct_integer  */
#line 547 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3913 "src-generated/ugbc.tab.c"
    break;

  case 133: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 550 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3921 "src-generated/ugbc.tab.c"
    break;

  case 134: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 553 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3929 "src-generated/ugbc.tab.c"
    break;

  case 135: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 556 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3937 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bank_definition_simple: DATA AT direct_integer  */
#line 559 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3945 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 563 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3953 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 566 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3961 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 569 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3969 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_simple: CODE AT direct_integer  */
#line 572 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3977 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 576 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3985 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 579 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3993 "src-generated/ugbc.tab.c"
    break;

  case 143: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 582 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4001 "src-generated/ugbc.tab.c"
    break;

  case 144: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 585 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4009 "src-generated/ugbc.tab.c"
    break;

  case 145: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 589 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4017 "src-generated/ugbc.tab.c"
    break;

  case 146: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 592 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4025 "src-generated/ugbc.tab.c"
    break;

  case 147: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 595 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4033 "src-generated/ugbc.tab.c"
    break;

  case 148: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 598 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4041 "src-generated/ugbc.tab.c"
    break;

  case 149: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 604 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4049 "src-generated/ugbc.tab.c"
    break;

  case 150: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 607 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4057 "src-generated/ugbc.tab.c"
    break;

  case 151: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 610 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4065 "src-generated/ugbc.tab.c"
    break;

  case 152: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 613 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4073 "src-generated/ugbc.tab.c"
    break;

  case 153: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 616 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4081 "src-generated/ugbc.tab.c"
    break;

  case 156: /* raster_definition_simple: Identifier AT direct_integer  */
#line 625 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 4089 "src-generated/ugbc.tab.c"
    break;

  case 157: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 628 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 4097 "src-generated/ugbc.tab.c"
    break;

  case 158: /* raster_definition_expression: Identifier AT expr  */
#line 633 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4105 "src-generated/ugbc.tab.c"
    break;

  case 159: /* raster_definition_expression: AT expr WITH Identifier  */
#line 636 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4113 "src-generated/ugbc.tab.c"
    break;

  case 162: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 645 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 4121 "src-generated/ugbc.tab.c"
    break;

  case 163: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 648 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 4129 "src-generated/ugbc.tab.c"
    break;

  case 164: /* next_raster_definition_expression: Identifier AT expr  */
#line 653 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 4137 "src-generated/ugbc.tab.c"
    break;

  case 165: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 656 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4145 "src-generated/ugbc.tab.c"
    break;

  case 168: /* color_definition_simple: BORDER direct_integer  */
#line 665 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 4153 "src-generated/ugbc.tab.c"
    break;

  case 169: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 668 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4161 "src-generated/ugbc.tab.c"
    break;

  case 170: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 671 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4169 "src-generated/ugbc.tab.c"
    break;

  case 171: /* color_definition_expression: BORDER expr  */
#line 676 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 4177 "src-generated/ugbc.tab.c"
    break;

  case 172: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 679 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4185 "src-generated/ugbc.tab.c"
    break;

  case 173: /* color_definition_expression: SPRITE expr TO expr  */
#line 682 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4193 "src-generated/ugbc.tab.c"
    break;

  case 179: /* wait_definition_simple: direct_integer CYCLES  */
#line 696 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4201 "src-generated/ugbc.tab.c"
    break;

  case 180: /* wait_definition_simple: direct_integer TICKS  */
#line 699 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4209 "src-generated/ugbc.tab.c"
    break;

  case 181: /* wait_definition_simple: direct_integer milliseconds  */
#line 702 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4217 "src-generated/ugbc.tab.c"
    break;

  case 182: /* wait_definition_expression: expr CYCLES  */
#line 707 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4225 "src-generated/ugbc.tab.c"
    break;

  case 183: /* wait_definition_expression: expr TICKS  */
#line 710 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4233 "src-generated/ugbc.tab.c"
    break;

  case 184: /* wait_definition_expression: expr milliseconds  */
#line 713 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4241 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 723 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4249 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 726 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4257 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 729 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4265 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 732 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4273 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 735 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4281 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_simple: direct_integer ENABLE  */
#line 738 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4289 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_simple: direct_integer DISABLE  */
#line 741 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4297 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 744 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4305 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 747 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4313 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 750 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4321 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 753 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4329 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 756 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4337 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 759 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4345 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 762 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4353 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 765 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4361 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_expression: expr DATA FROM expr  */
#line 770 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4369 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_expression: expr MULTICOLOR  */
#line 773 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4377 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_expression: expr MONOCOLOR  */
#line 776 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4385 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_expression: expr COLOR expr  */
#line 779 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4393 "src-generated/ugbc.tab.c"
    break;

  case 206: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 782 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4401 "src-generated/ugbc.tab.c"
    break;

  case 207: /* sprite_definition_expression: expr ENABLE  */
#line 785 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4409 "src-generated/ugbc.tab.c"
    break;

  case 208: /* sprite_definition_expression: expr DISABLE  */
#line 788 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4417 "src-generated/ugbc.tab.c"
    break;

  case 209: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 791 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4425 "src-generated/ugbc.tab.c"
    break;

  case 210: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 794 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4433 "src-generated/ugbc.tab.c"
    break;

  case 211: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 797 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4441 "src-generated/ugbc.tab.c"
    break;

  case 212: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 800 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4449 "src-generated/ugbc.tab.c"
    break;

  case 213: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 803 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4457 "src-generated/ugbc.tab.c"
    break;

  case 214: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 806 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4465 "src-generated/ugbc.tab.c"
    break;

  case 215: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 809 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4473 "src-generated/ugbc.tab.c"
    break;

  case 216: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 812 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4481 "src-generated/ugbc.tab.c"
    break;

  case 219: /* bitmap_definition_simple: AT direct_integer  */
#line 821 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4489 "src-generated/ugbc.tab.c"
    break;

  case 220: /* bitmap_definition_simple: ENABLE  */
#line 824 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4497 "src-generated/ugbc.tab.c"
    break;

  case 221: /* bitmap_definition_simple: DISABLE  */
#line 827 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4505 "src-generated/ugbc.tab.c"
    break;

  case 222: /* bitmap_definition_simple: CLEAR  */
#line 830 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4513 "src-generated/ugbc.tab.c"
    break;

  case 223: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 833 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4521 "src-generated/ugbc.tab.c"
    break;

  case 224: /* bitmap_definition_expression: AT expr  */
#line 839 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4529 "src-generated/ugbc.tab.c"
    break;

  case 225: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 842 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4537 "src-generated/ugbc.tab.c"
    break;

  case 228: /* textmap_definition_simple: AT direct_integer  */
#line 852 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4545 "src-generated/ugbc.tab.c"
    break;

  case 229: /* textmap_definition_expression: AT expr  */
#line 857 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4553 "src-generated/ugbc.tab.c"
    break;

  case 232: /* text_definition_simple: ENABLE  */
#line 866 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4561 "src-generated/ugbc.tab.c"
    break;

  case 233: /* text_definition_simple: DISABLE  */
#line 869 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4569 "src-generated/ugbc.tab.c"
    break;

  case 234: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 874 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4577 "src-generated/ugbc.tab.c"
    break;

  case 235: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 877 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4585 "src-generated/ugbc.tab.c"
    break;

  case 238: /* tiles_definition_simple: AT direct_integer  */
#line 886 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4593 "src-generated/ugbc.tab.c"
    break;

  case 239: /* tiles_definition_expression: AT expr  */
#line 891 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4601 "src-generated/ugbc.tab.c"
    break;

  case 242: /* colormap_definition_simple: AT direct_integer  */
#line 900 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4609 "src-generated/ugbc.tab.c"
    break;

  case 243: /* colormap_definition_simple: CLEAR  */
#line 903 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4617 "src-generated/ugbc.tab.c"
    break;

  case 244: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 906 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4625 "src-generated/ugbc.tab.c"
    break;

  case 245: /* colormap_definition_expression: AT expr  */
#line 911 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4633 "src-generated/ugbc.tab.c"
    break;

  case 246: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 914 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4641 "src-generated/ugbc.tab.c"
    break;

  case 249: /* screen_definition_simple: ON  */
#line 924 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4649 "src-generated/ugbc.tab.c"
    break;

  case 250: /* screen_definition_simple: OFF  */
#line 927 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4657 "src-generated/ugbc.tab.c"
    break;

  case 251: /* screen_definition_simple: ROWS direct_integer  */
#line 930 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4665 "src-generated/ugbc.tab.c"
    break;

  case 252: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 933 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4673 "src-generated/ugbc.tab.c"
    break;

  case 253: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 936 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4681 "src-generated/ugbc.tab.c"
    break;

  case 254: /* screen_definition_expression: ROWS expr  */
#line 941 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4689 "src-generated/ugbc.tab.c"
    break;

  case 255: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 944 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4697 "src-generated/ugbc.tab.c"
    break;

  case 256: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 947 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4705 "src-generated/ugbc.tab.c"
    break;

  case 260: /* var_definition_simple: Identifier ON Identifier  */
#line 956 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4713 "src-generated/ugbc.tab.c"
    break;

  case 261: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 959 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4721 "src-generated/ugbc.tab.c"
    break;

  case 262: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 962 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4729 "src-generated/ugbc.tab.c"
    break;

  case 263: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 965 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4739 "src-generated/ugbc.tab.c"
    break;

  case 264: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 970 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4749 "src-generated/ugbc.tab.c"
    break;

  case 265: /* goto_definition: Identifier  */
#line 977 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4757 "src-generated/ugbc.tab.c"
    break;

  case 266: /* goto_definition: Integer  */
#line 980 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4765 "src-generated/ugbc.tab.c"
    break;

  case 267: /* gosub_definition: Identifier  */
#line 986 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4773 "src-generated/ugbc.tab.c"
    break;

  case 268: /* gosub_definition: Integer  */
#line 989 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4781 "src-generated/ugbc.tab.c"
    break;

  case 270: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 998 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4789 "src-generated/ugbc.tab.c"
    break;

  case 271: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 1004 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4797 "src-generated/ugbc.tab.c"
    break;

  case 274: /* ink_definition: expr  */
#line 1013 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4805 "src-generated/ugbc.tab.c"
    break;

  case 275: /* on_goto_definition: Identifier  */
#line 1018 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4814 "src-generated/ugbc.tab.c"
    break;

  case 276: /* $@4: %empty  */
#line 1022 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4822 "src-generated/ugbc.tab.c"
    break;

  case 278: /* on_gosub_definition: Identifier  */
#line 1027 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4831 "src-generated/ugbc.tab.c"
    break;

  case 279: /* $@5: %empty  */
#line 1031 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4839 "src-generated/ugbc.tab.c"
    break;

  case 281: /* on_proc_definition: Identifier  */
#line 1036 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4848 "src-generated/ugbc.tab.c"
    break;

  case 282: /* $@6: %empty  */
#line 1040 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4856 "src-generated/ugbc.tab.c"
    break;

  case 284: /* $@7: %empty  */
#line 1045 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4864 "src-generated/ugbc.tab.c"
    break;

  case 286: /* $@8: %empty  */
#line 1048 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4872 "src-generated/ugbc.tab.c"
    break;

  case 288: /* $@9: %empty  */
#line 1051 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4880 "src-generated/ugbc.tab.c"
    break;

  case 290: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1056 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4888 "src-generated/ugbc.tab.c"
    break;

  case 291: /* every_definition: ON  */
#line 1059 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4896 "src-generated/ugbc.tab.c"
    break;

  case 292: /* every_definition: OFF  */
#line 1062 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4904 "src-generated/ugbc.tab.c"
    break;

  case 293: /* add_definition: Identifier COMMA expr  */
#line 1067 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4912 "src-generated/ugbc.tab.c"
    break;

  case 294: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1070 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4920 "src-generated/ugbc.tab.c"
    break;

  case 295: /* dimensions: Integer  */
#line 1076 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4929 "src-generated/ugbc.tab.c"
    break;

  case 296: /* dimensions: Integer COMMA dimensions  */
#line 1080 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4938 "src-generated/ugbc.tab.c"
    break;

  case 297: /* datatype: BYTE  */
#line 1087 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 4946 "src-generated/ugbc.tab.c"
    break;

  case 298: /* datatype: SIGNED BYTE  */
#line 1090 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 4954 "src-generated/ugbc.tab.c"
    break;

  case 299: /* datatype: WORD  */
#line 1093 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 4962 "src-generated/ugbc.tab.c"
    break;

  case 300: /* datatype: SIGNED WORD  */
#line 1096 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 4970 "src-generated/ugbc.tab.c"
    break;

  case 301: /* datatype: DWORD  */
#line 1099 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 4978 "src-generated/ugbc.tab.c"
    break;

  case 302: /* datatype: SIGNED DWORD  */
#line 1102 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 4986 "src-generated/ugbc.tab.c"
    break;

  case 303: /* datatype: ADDRESS  */
#line 1105 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 4994 "src-generated/ugbc.tab.c"
    break;

  case 304: /* datatype: POSITION  */
#line 1108 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 5002 "src-generated/ugbc.tab.c"
    break;

  case 305: /* datatype: COLOR  */
#line 1111 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 5010 "src-generated/ugbc.tab.c"
    break;

  case 306: /* datatype: STRING  */
#line 1114 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 5018 "src-generated/ugbc.tab.c"
    break;

  case 307: /* $@10: %empty  */
#line 1119 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5027 "src-generated/ugbc.tab.c"
    break;

  case 308: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1122 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 5037 "src-generated/ugbc.tab.c"
    break;

  case 309: /* $@11: %empty  */
#line 1127 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5046 "src-generated/ugbc.tab.c"
    break;

  case 310: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1130 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 5056 "src-generated/ugbc.tab.c"
    break;

  case 311: /* $@12: %empty  */
#line 1135 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5065 "src-generated/ugbc.tab.c"
    break;

  case 312: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1138 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 5075 "src-generated/ugbc.tab.c"
    break;

  case 315: /* indexes: expr  */
#line 1151 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5084 "src-generated/ugbc.tab.c"
    break;

  case 316: /* indexes: expr COMMA indexes  */
#line 1155 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5093 "src-generated/ugbc.tab.c"
    break;

  case 317: /* parameters: Identifier  */
#line 1162 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5103 "src-generated/ugbc.tab.c"
    break;

  case 318: /* parameters: Identifier DOLLAR  */
#line 1167 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5113 "src-generated/ugbc.tab.c"
    break;

  case 319: /* parameters: Identifier AS datatype  */
#line 1172 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5123 "src-generated/ugbc.tab.c"
    break;

  case 320: /* parameters: Identifier COMMA parameters  */
#line 1177 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5133 "src-generated/ugbc.tab.c"
    break;

  case 321: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1182 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5143 "src-generated/ugbc.tab.c"
    break;

  case 322: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1187 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5153 "src-generated/ugbc.tab.c"
    break;

  case 323: /* parameters_expr: Identifier  */
#line 1195 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5163 "src-generated/ugbc.tab.c"
    break;

  case 324: /* parameters_expr: Identifier DOLLAR  */
#line 1200 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5173 "src-generated/ugbc.tab.c"
    break;

  case 325: /* parameters_expr: Identifier AS datatype  */
#line 1205 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5183 "src-generated/ugbc.tab.c"
    break;

  case 326: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1210 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5193 "src-generated/ugbc.tab.c"
    break;

  case 327: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1215 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5203 "src-generated/ugbc.tab.c"
    break;

  case 328: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1220 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5213 "src-generated/ugbc.tab.c"
    break;

  case 329: /* parameters_expr: String  */
#line 1225 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5222 "src-generated/ugbc.tab.c"
    break;

  case 330: /* parameters_expr: String COMMA parameters_expr  */
#line 1229 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5231 "src-generated/ugbc.tab.c"
    break;

  case 331: /* values: expr  */
#line 1236 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5240 "src-generated/ugbc.tab.c"
    break;

  case 332: /* values: expr COMMA values  */
#line 1240 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5249 "src-generated/ugbc.tab.c"
    break;

  case 333: /* print_definition: expr  */
#line 1247 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5257 "src-generated/ugbc.tab.c"
    break;

  case 334: /* print_definition: expr COMMA  */
#line 1250 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5266 "src-generated/ugbc.tab.c"
    break;

  case 335: /* print_definition: expr SEMICOLON  */
#line 1254 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5274 "src-generated/ugbc.tab.c"
    break;

  case 336: /* $@13: %empty  */
#line 1257 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5283 "src-generated/ugbc.tab.c"
    break;

  case 338: /* $@14: %empty  */
#line 1261 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5291 "src-generated/ugbc.tab.c"
    break;

  case 340: /* use_definition: ANSI  */
#line 1267 "src/ugbc.y"
         {
        use_ansi( _environment );
    }
#line 5299 "src-generated/ugbc.tab.c"
    break;

  case 341: /* use_definition: SPECIFIC  */
#line 1270 "src/ugbc.y"
             {
        use_specific( _environment );
  }
#line 5307 "src-generated/ugbc.tab.c"
    break;

  case 342: /* writing_mode_definition: REPLACE  */
#line 1276 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5316 "src-generated/ugbc.tab.c"
    break;

  case 343: /* writing_mode_definition: OR  */
#line 1280 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5325 "src-generated/ugbc.tab.c"
    break;

  case 344: /* writing_mode_definition: XOR  */
#line 1284 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5334 "src-generated/ugbc.tab.c"
    break;

  case 345: /* writing_mode_definition: AND  */
#line 1288 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5343 "src-generated/ugbc.tab.c"
    break;

  case 346: /* writing_mode_definition: IGNORE  */
#line 1292 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5352 "src-generated/ugbc.tab.c"
    break;

  case 347: /* writing_part_definition: NORMAL  */
#line 1299 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5361 "src-generated/ugbc.tab.c"
    break;

  case 348: /* writing_part_definition: PAPER  */
#line 1303 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5370 "src-generated/ugbc.tab.c"
    break;

  case 349: /* writing_part_definition: PAPER ONLY  */
#line 1307 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5379 "src-generated/ugbc.tab.c"
    break;

  case 350: /* writing_part_definition: PEN  */
#line 1311 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5388 "src-generated/ugbc.tab.c"
    break;

  case 351: /* writing_part_definition: PEN ONLY  */
#line 1315 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5397 "src-generated/ugbc.tab.c"
    break;

  case 352: /* writing_definition: writing_mode_definition COMMA writing_part_definition  */
#line 1322 "src/ugbc.y"
                                                          {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5405 "src-generated/ugbc.tab.c"
    break;

  case 353: /* locate_definition: COMMA expr  */
#line 1328 "src/ugbc.y"
                {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 5413 "src-generated/ugbc.tab.c"
    break;

  case 354: /* locate_definition: expr COMMA  */
#line 1331 "src/ugbc.y"
                 {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 5421 "src-generated/ugbc.tab.c"
    break;

  case 355: /* locate_definition: expr COMMA expr  */
#line 1334 "src/ugbc.y"
                      {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5429 "src-generated/ugbc.tab.c"
    break;

  case 356: /* cmove_definition: COMMA expr  */
#line 1340 "src/ugbc.y"
                {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 5437 "src-generated/ugbc.tab.c"
    break;

  case 357: /* cmove_definition: expr COMMA  */
#line 1343 "src/ugbc.y"
                 {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 5445 "src-generated/ugbc.tab.c"
    break;

  case 358: /* cmove_definition: expr COMMA expr  */
#line 1346 "src/ugbc.y"
                      {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5453 "src-generated/ugbc.tab.c"
    break;

  case 378: /* statement: CENTER expr  */
#line 1371 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5461 "src-generated/ugbc.tab.c"
    break;

  case 379: /* statement: CENTRE expr  */
#line 1374 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5469 "src-generated/ugbc.tab.c"
    break;

  case 380: /* statement: CLS  */
#line 1377 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 5477 "src-generated/ugbc.tab.c"
    break;

  case 381: /* statement: HOME  */
#line 1380 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 5485 "src-generated/ugbc.tab.c"
    break;

  case 382: /* statement: INC Identifier  */
#line 1383 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 5493 "src-generated/ugbc.tab.c"
    break;

  case 383: /* statement: DEC Identifier  */
#line 1386 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 5501 "src-generated/ugbc.tab.c"
    break;

  case 384: /* statement: RANDOMIZE  */
#line 1389 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 5509 "src-generated/ugbc.tab.c"
    break;

  case 385: /* statement: RANDOMIZE expr  */
#line 1392 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 5517 "src-generated/ugbc.tab.c"
    break;

  case 386: /* statement: IF expr THEN  */
#line 1395 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5525 "src-generated/ugbc.tab.c"
    break;

  case 387: /* statement: ELSE  */
#line 1398 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 5533 "src-generated/ugbc.tab.c"
    break;

  case 388: /* statement: ELSE IF expr THEN  */
#line 1401 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5541 "src-generated/ugbc.tab.c"
    break;

  case 389: /* statement: ENDIF  */
#line 1404 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5549 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: DO  */
#line 1407 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5557 "src-generated/ugbc.tab.c"
    break;

  case 391: /* statement: LOOP  */
#line 1410 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5565 "src-generated/ugbc.tab.c"
    break;

  case 392: /* $@15: %empty  */
#line 1413 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5573 "src-generated/ugbc.tab.c"
    break;

  case 393: /* statement: WHILE $@15 expr  */
#line 1415 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5581 "src-generated/ugbc.tab.c"
    break;

  case 394: /* statement: WEND  */
#line 1418 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5589 "src-generated/ugbc.tab.c"
    break;

  case 395: /* statement: REPEAT  */
#line 1421 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5597 "src-generated/ugbc.tab.c"
    break;

  case 396: /* statement: UNTIL expr  */
#line 1424 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5605 "src-generated/ugbc.tab.c"
    break;

  case 397: /* statement: EXIT  */
#line 1427 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5613 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statement: EXIT PROC  */
#line 1430 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5621 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: POP PROC  */
#line 1433 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5629 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: EXIT IF expr  */
#line 1436 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5637 "src-generated/ugbc.tab.c"
    break;

  case 401: /* statement: EXIT Integer  */
#line 1439 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5645 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: EXIT direct_integer  */
#line 1442 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5653 "src-generated/ugbc.tab.c"
    break;

  case 403: /* statement: EXIT IF expr COMMA Integer  */
#line 1445 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5661 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1448 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5669 "src-generated/ugbc.tab.c"
    break;

  case 405: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1451 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5677 "src-generated/ugbc.tab.c"
    break;

  case 406: /* statement: NEXT  */
#line 1454 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5685 "src-generated/ugbc.tab.c"
    break;

  case 407: /* statement: PROCEDURE Identifier  */
#line 1457 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5694 "src-generated/ugbc.tab.c"
    break;

  case 408: /* $@16: %empty  */
#line 1461 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5702 "src-generated/ugbc.tab.c"
    break;

  case 409: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1463 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5710 "src-generated/ugbc.tab.c"
    break;

  case 410: /* statement: SHARED parameters_expr  */
#line 1466 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5718 "src-generated/ugbc.tab.c"
    break;

  case 411: /* statement: GLOBAL parameters_expr  */
#line 1469 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5726 "src-generated/ugbc.tab.c"
    break;

  case 412: /* statement: END PROC  */
#line 1472 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 5734 "src-generated/ugbc.tab.c"
    break;

  case 413: /* statement: END PROC OSP expr CSP  */
#line 1475 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5742 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1478 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5750 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: Identifier " "  */
#line 1481 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5759 "src-generated/ugbc.tab.c"
    break;

  case 416: /* statement: PROC Identifier  */
#line 1485 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5768 "src-generated/ugbc.tab.c"
    break;

  case 417: /* statement: CALL Identifier  */
#line 1489 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5777 "src-generated/ugbc.tab.c"
    break;

  case 418: /* $@17: %empty  */
#line 1493 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5785 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: Identifier OSP $@17 values CSP  */
#line 1495 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5793 "src-generated/ugbc.tab.c"
    break;

  case 420: /* $@18: %empty  */
#line 1498 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5801 "src-generated/ugbc.tab.c"
    break;

  case 421: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1500 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5809 "src-generated/ugbc.tab.c"
    break;

  case 422: /* $@19: %empty  */
#line 1503 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5817 "src-generated/ugbc.tab.c"
    break;

  case 423: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1505 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5825 "src-generated/ugbc.tab.c"
    break;

  case 424: /* statement: PEN expr  */
#line 1508 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 5833 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: PAPER expr  */
#line 1511 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 5841 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: INVERSE ON  */
#line 1514 "src/ugbc.y"
               {
      text_inverse( _environment, 1 );
  }
#line 5849 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: INVERSE OFF  */
#line 1517 "src/ugbc.y"
                {
      text_inverse( _environment, 0 );
  }
#line 5857 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: Identifier COLON  */
#line 1521 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 5865 "src-generated/ugbc.tab.c"
    break;

  case 430: /* statement: BEG GAMELOOP  */
#line 1524 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 5873 "src-generated/ugbc.tab.c"
    break;

  case 431: /* statement: END GAMELOOP  */
#line 1527 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 5881 "src-generated/ugbc.tab.c"
    break;

  case 432: /* statement: GRAPHIC  */
#line 1530 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 5889 "src-generated/ugbc.tab.c"
    break;

  case 433: /* statement: HALT  */
#line 1533 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 5897 "src-generated/ugbc.tab.c"
    break;

  case 434: /* statement: END  */
#line 1536 "src/ugbc.y"
        {
      end( _environment );
  }
#line 5905 "src-generated/ugbc.tab.c"
    break;

  case 439: /* statement: RETURN  */
#line 1543 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 5913 "src-generated/ugbc.tab.c"
    break;

  case 440: /* statement: RETURN expr  */
#line 1546 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 5921 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: POP  */
#line 1549 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 5929 "src-generated/ugbc.tab.c"
    break;

  case 442: /* statement: DONE  */
#line 1552 "src/ugbc.y"
          {
      return 0;
  }
#line 5937 "src-generated/ugbc.tab.c"
    break;

  case 443: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1555 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5945 "src-generated/ugbc.tab.c"
    break;

  case 444: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1558 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5953 "src-generated/ugbc.tab.c"
    break;

  case 445: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1561 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 5961 "src-generated/ugbc.tab.c"
    break;

  case 446: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1564 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5969 "src-generated/ugbc.tab.c"
    break;

  case 449: /* statement: Identifier ASSIGN expr  */
#line 1569 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 5983 "src-generated/ugbc.tab.c"
    break;

  case 450: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1578 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 5997 "src-generated/ugbc.tab.c"
    break;

  case 451: /* $@20: %empty  */
#line 1587 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6006 "src-generated/ugbc.tab.c"
    break;

  case 452: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1591 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 6019 "src-generated/ugbc.tab.c"
    break;

  case 453: /* $@21: %empty  */
#line 1599 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6028 "src-generated/ugbc.tab.c"
    break;

  case 454: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1602 "src/ugbc.y"
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
#line 6047 "src-generated/ugbc.tab.c"
    break;

  case 455: /* $@22: %empty  */
#line 1616 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6056 "src-generated/ugbc.tab.c"
    break;

  case 456: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1619 "src/ugbc.y"
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
#line 6075 "src-generated/ugbc.tab.c"
    break;

  case 457: /* statement: DEBUG expr  */
#line 1633 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 6083 "src-generated/ugbc.tab.c"
    break;

  case 460: /* statements_no_linenumbers: statement  */
#line 1641 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 6089 "src-generated/ugbc.tab.c"
    break;

  case 461: /* $@23: %empty  */
#line 1642 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 6095 "src-generated/ugbc.tab.c"
    break;

  case 463: /* $@24: %empty  */
#line 1646 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 6103 "src-generated/ugbc.tab.c"
    break;

  case 464: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1648 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 6111 "src-generated/ugbc.tab.c"
    break;

  case 465: /* $@25: %empty  */
#line 1653 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 6119 "src-generated/ugbc.tab.c"
    break;

  case 471: /* $@26: %empty  */
#line 1663 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 6125 "src-generated/ugbc.tab.c"
    break;


#line 6129 "src-generated/ugbc.tab.c"

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

#line 1665 "src/ugbc.y"


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

