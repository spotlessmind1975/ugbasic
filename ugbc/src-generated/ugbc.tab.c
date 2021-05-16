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
  YYSYMBOL_TAB = 174,                      /* TAB  */
  YYSYMBOL_SET = 175,                      /* SET  */
  YYSYMBOL_CUP = 176,                      /* CUP  */
  YYSYMBOL_CDOWN = 177,                    /* CDOWN  */
  YYSYMBOL_CLEFT = 178,                    /* CLEFT  */
  YYSYMBOL_CRIGHT = 179,                   /* CRIGHT  */
  YYSYMBOL_BLACK = 180,                    /* BLACK  */
  YYSYMBOL_WHITE = 181,                    /* WHITE  */
  YYSYMBOL_RED = 182,                      /* RED  */
  YYSYMBOL_CYAN = 183,                     /* CYAN  */
  YYSYMBOL_VIOLET = 184,                   /* VIOLET  */
  YYSYMBOL_GREEN = 185,                    /* GREEN  */
  YYSYMBOL_BLUE = 186,                     /* BLUE  */
  YYSYMBOL_YELLOW = 187,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 188,                   /* ORANGE  */
  YYSYMBOL_BROWN = 189,                    /* BROWN  */
  YYSYMBOL_LIGHT = 190,                    /* LIGHT  */
  YYSYMBOL_DARK = 191,                     /* DARK  */
  YYSYMBOL_GREY = 192,                     /* GREY  */
  YYSYMBOL_GRAY = 193,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 194,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 195,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 196,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 197,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 198,                /* TURQUOISE  */
  YYSYMBOL_TAN = 199,                      /* TAN  */
  YYSYMBOL_PINK = 200,                     /* PINK  */
  YYSYMBOL_PEACH = 201,                    /* PEACH  */
  YYSYMBOL_OLIVE = 202,                    /* OLIVE  */
  YYSYMBOL_Identifier = 203,               /* Identifier  */
  YYSYMBOL_String = 204,                   /* String  */
  YYSYMBOL_Integer = 205,                  /* Integer  */
  YYSYMBOL_206_ = 206,                     /* " "  */
  YYSYMBOL_YYACCEPT = 207,                 /* $accept  */
  YYSYMBOL_expr = 208,                     /* expr  */
  YYSYMBOL_expr_math = 209,                /* expr_math  */
  YYSYMBOL_term = 210,                     /* term  */
  YYSYMBOL_modula = 211,                   /* modula  */
  YYSYMBOL_factor = 212,                   /* factor  */
  YYSYMBOL_direct_integer = 213,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 214, /* random_definition_simple  */
  YYSYMBOL_random_definition = 215,        /* random_definition  */
  YYSYMBOL_color_enumeration = 216,        /* color_enumeration  */
  YYSYMBOL_exponential = 217,              /* exponential  */
  YYSYMBOL_218_1 = 218,                    /* $@1  */
  YYSYMBOL_219_2 = 219,                    /* $@2  */
  YYSYMBOL_220_3 = 220,                    /* $@3  */
  YYSYMBOL_position = 221,                 /* position  */
  YYSYMBOL_bank_definition_simple = 222,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 223, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 224,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 225, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 226, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 227,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 228, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 229, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 230,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 231,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 232, /* color_definition_expression  */
  YYSYMBOL_color_definition = 233,         /* color_definition  */
  YYSYMBOL_milliseconds = 234,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 235,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 236, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 237,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 238, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 239, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 240,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 241, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 242, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 243,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 244, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 245, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 246,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 247,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 248, /* text_definition_expression  */
  YYSYMBOL_text_definition = 249,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 250,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 251, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 252,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 253, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 254, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 255,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 256, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 257, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 258,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 259,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 260,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 261,         /* gosub_definition  */
  YYSYMBOL_var_definition = 262,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 263,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 264, /* point_definition_expression  */
  YYSYMBOL_point_definition = 265,         /* point_definition  */
  YYSYMBOL_ink_definition = 266,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 267,       /* on_goto_definition  */
  YYSYMBOL_268_4 = 268,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 269,      /* on_gosub_definition  */
  YYSYMBOL_270_5 = 270,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 271,       /* on_proc_definition  */
  YYSYMBOL_272_6 = 272,                    /* $@6  */
  YYSYMBOL_on_definition = 273,            /* on_definition  */
  YYSYMBOL_274_7 = 274,                    /* $@7  */
  YYSYMBOL_275_8 = 275,                    /* $@8  */
  YYSYMBOL_276_9 = 276,                    /* $@9  */
  YYSYMBOL_every_definition = 277,         /* every_definition  */
  YYSYMBOL_add_definition = 278,           /* add_definition  */
  YYSYMBOL_dimensions = 279,               /* dimensions  */
  YYSYMBOL_datatype = 280,                 /* datatype  */
  YYSYMBOL_dim_definition = 281,           /* dim_definition  */
  YYSYMBOL_282_10 = 282,                   /* $@10  */
  YYSYMBOL_283_11 = 283,                   /* $@11  */
  YYSYMBOL_284_12 = 284,                   /* $@12  */
  YYSYMBOL_dim_definitions = 285,          /* dim_definitions  */
  YYSYMBOL_indexes = 286,                  /* indexes  */
  YYSYMBOL_parameters = 287,               /* parameters  */
  YYSYMBOL_parameters_expr = 288,          /* parameters_expr  */
  YYSYMBOL_values = 289,                   /* values  */
  YYSYMBOL_print_definition = 290,         /* print_definition  */
  YYSYMBOL_291_13 = 291,                   /* $@13  */
  YYSYMBOL_292_14 = 292,                   /* $@14  */
  YYSYMBOL_use_definition = 293,           /* use_definition  */
  YYSYMBOL_writing_mode_definition = 294,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 295,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 296,       /* writing_definition  */
  YYSYMBOL_locate_definition = 297,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 298,         /* cmove_definition  */
  YYSYMBOL_statement = 299,                /* statement  */
  YYSYMBOL_300_15 = 300,                   /* $@15  */
  YYSYMBOL_301_16 = 301,                   /* $@16  */
  YYSYMBOL_302_17 = 302,                   /* $@17  */
  YYSYMBOL_303_18 = 303,                   /* $@18  */
  YYSYMBOL_304_19 = 304,                   /* $@19  */
  YYSYMBOL_305_20 = 305,                   /* $@20  */
  YYSYMBOL_306_21 = 306,                   /* $@21  */
  YYSYMBOL_307_22 = 307,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 308, /* statements_no_linenumbers  */
  YYSYMBOL_309_23 = 309,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 310, /* statements_with_linenumbers  */
  YYSYMBOL_311_24 = 311,                   /* $@24  */
  YYSYMBOL_statements_complex = 312,       /* statements_complex  */
  YYSYMBOL_313_25 = 313,                   /* $@25  */
  YYSYMBOL_program = 314,                  /* program  */
  YYSYMBOL_315_26 = 315                    /* $@26  */
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
#define YYLAST   3054

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  207
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  482
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  933

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   461


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
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206
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
     511,   515,   518,   521,   524,   527,   530,   533,   536,   539,
     542,   545,   548,   551,   556,   556,   559,   562,   565,   568,
     571,   574,   578,   581,   584,   587,   591,   594,   597,   600,
     604,   607,   610,   613,   619,   622,   625,   628,   631,   636,
     637,   640,   643,   648,   651,   656,   657,   660,   663,   668,
     671,   676,   677,   680,   683,   686,   691,   694,   697,   702,
     703,   706,   707,   708,   711,   714,   717,   722,   725,   728,
     734,   735,   738,   741,   744,   747,   750,   753,   756,   759,
     762,   765,   768,   771,   774,   777,   780,   785,   788,   791,
     794,   797,   800,   803,   806,   809,   812,   815,   818,   821,
     824,   827,   832,   833,   836,   839,   842,   845,   848,   854,
     857,   863,   864,   867,   872,   877,   878,   881,   884,   889,
     892,   897,   898,   901,   906,   911,   912,   915,   918,   921,
     926,   929,   935,   936,   939,   942,   945,   948,   951,   956,
     959,   962,   967,   968,   970,   971,   974,   977,   980,   985,
     992,   995,  1001,  1004,  1010,  1013,  1019,  1024,  1025,  1028,
    1033,  1037,  1037,  1042,  1046,  1046,  1051,  1055,  1055,  1060,
    1060,  1063,  1063,  1066,  1066,  1071,  1074,  1077,  1082,  1085,
    1091,  1095,  1102,  1105,  1108,  1111,  1114,  1117,  1120,  1123,
    1126,  1129,  1134,  1134,  1142,  1142,  1150,  1150,  1161,  1162,
    1166,  1170,  1177,  1182,  1187,  1192,  1197,  1202,  1210,  1215,
    1220,  1225,  1230,  1235,  1240,  1244,  1251,  1255,  1262,  1265,
    1269,  1272,  1272,  1276,  1276,  1282,  1285,  1291,  1295,  1299,
    1303,  1307,  1314,  1318,  1322,  1326,  1330,  1337,  1343,  1346,
    1349,  1355,  1358,  1361,  1367,  1368,  1369,  1370,  1371,  1372,
    1373,  1374,  1375,  1376,  1377,  1378,  1379,  1380,  1381,  1382,
    1383,  1384,  1385,  1386,  1389,  1392,  1395,  1398,  1401,  1404,
    1407,  1410,  1413,  1416,  1419,  1422,  1425,  1428,  1431,  1434,
    1437,  1440,  1443,  1443,  1448,  1451,  1454,  1457,  1460,  1463,
    1466,  1469,  1472,  1475,  1478,  1481,  1484,  1487,  1491,  1491,
    1496,  1499,  1502,  1505,  1508,  1511,  1515,  1519,  1523,  1523,
    1528,  1528,  1533,  1533,  1538,  1541,  1544,  1547,  1550,  1551,
    1554,  1557,  1560,  1563,  1566,  1569,  1570,  1571,  1572,  1573,
    1576,  1579,  1582,  1585,  1588,  1591,  1594,  1597,  1598,  1599,
    1608,  1617,  1617,  1629,  1629,  1646,  1646,  1663,  1666,  1667,
    1671,  1672,  1672,  1676,  1676,  1683,  1683,  1686,  1687,  1688,
    1689,  1693,  1693
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
  "LOCATE", "CLS", "HOME", "CMOVE", "CENTER", "CENTRE", "TAB", "SET",
  "CUP", "CDOWN", "CLEFT", "CRIGHT", "BLACK", "WHITE", "RED", "CYAN",
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
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461
};
#endif

#define YYPACT_NINF (-796)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-462)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -796,    75,   881,  -796,  -796,  -139,  -118,    -9,  -796,    60,
    2100,    92,    21,  2100,  -796,    64,   197,  2481,   -60,   -61,
    -796,  -796,  -796,  1732,   134,    39,  2481,  2481,    94,   -40,
    -796,   161,   181,  2481,  2481,  -796,   199,   210,    -3,  2481,
      85,   184,  -796,   -49,  -796,  2481,    55,  1916,   257,    67,
    2481,    96,    98,   117,   123,   -57,   -57,  2481,    50,  2481,
     127,    69,  1165,  -796,  -796,  1364,  2481,  2481,   147,  -796,
    -796,  -796,  -796,     8,  -796,   316,   323,   324,  -796,  -796,
    -796,  2100,   305,  -796,  -796,  -796,  2100,  2100,  2100,  -796,
    -796,  -796,   125,   311,  1548,  -796,  -796,   298,   299,   300,
     162,   130,  -796,  -796,    12,   302,   303,  2481,  -796,  -796,
     304,   307,   325,   326,   327,   330,   331,   332,   333,   334,
     335,   337,   339,   342,   343,   344,   345,  -796,  -796,   346,
      45,   -35,    16,   352,   361,   362,   364,   365,   366,   367,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,   203,  -796,  -796,
      80,   -96,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,   204,    14,  -796,  -796,   -11,   120,   260,   236,   262,
      28,  -796,  -796,  -796,  -796,  -796,    -4,   314,    -2,     3,
       6,     7,   373,  -796,  -796,  -796,   224,   338,  -796,  -796,
    -796,  2100,  -796,  -796,   369,  -796,  -796,  -796,  -796,  -796,
    2100,   353,   354,  -796,  -796,  -796,     1,  -796,    40,  -796,
    -796,  -796,  -796,  -796,  2481,  2297,  -796,  -796,   394,  -796,
    -796,  -796,  2100,  -796,  -796,  -796,  2100,   376,  -796,  -796,
    -796,   347,  -796,  -796,  -796,   255,  2481,  2481,  -796,  -796,
    2100,  -796,  -796,  -796,   372,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  2481,  2481,  -796,  -796,  -796,  -796,   399,
    -796,  -796,   261,  -796,  2481,   400,  -796,  -796,  -796,    42,
     408,  -796,   270,   271,   272,    54,   413,  -796,  -796,   266,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,   414,  -796,  2481,   415,  -796,  2481,   416,  -796,
    -796,  -796,  2481,  -796,  -796,  2481,   412,  -796,  -796,   392,
      48,  1052,  -796,   881,   881,   398,   401,  2100,  -796,  -796,
     356,   357,   359,   360,  -796,   402,   403,   404,   405,   406,
     407,   101,   409,  2100,  2100,  2100,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,   411,  -796,  -796,  2481,
    2481,  -796,  2481,  2481,  2481,  2481,  2481,  2481,  2481,  2481,
    2481,  2481,  2481,  2481,  2481,  2481,  2481,  2481,  2481,  2665,
     421,   230,  -796,  -796,   422,  -796,  -796,   423,   424,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,   425,  -796,   426,  -796,  -796,  -796,  -796,  -796,
    -796,  2665,  2665,  2665,  2665,  2665,  2665,  2665,  2665,  2665,
    2665,  2665,  2665,  2665,  2849,  -796,  -796,  -796,  2100,   410,
    -796,  -796,  -796,   387,   314,   419,   314,   438,   314,   439,
     314,   440,   314,  -796,  2481,   417,  -796,  -796,   132,   218,
     128,   174,  -796,  -796,  -796,   431,   314,   434,  -796,  -796,
     237,   240,   205,   223,  -796,  -796,   435,  -796,  -796,  2100,
    -796,  -796,  2100,  2100,  -796,  -796,  -796,   395,   243,  -796,
     441,  2481,  -796,  -796,  -796,  -796,  2100,  -796,  2481,   463,
     464,  -796,  -796,  2100,   378,   465,  2481,   375,   467,  2481,
    -796,  -796,  -796,  -796,  -796,  -796,   118,  -796,  -796,   444,
     455,    96,  -796,   336,  -796,   -57,   473,    48,   -57,   279,
     282,   -45,  -796,  2481,  -796,  2481,  -796,   881,  -796,  2481,
     447,  2481,  2481,   448,     5,  -796,  1052,  -796,  -796,   281,
     283,  -796,  -796,  2481,   314,  2481,   314,  2481,   280,   284,
     285,   286,   287,   452,   453,   458,  -796,   460,   461,   462,
     466,   472,   475,  2481,   491,   492,   505,   506,   479,   480,
     481,   482,   511,   484,   485,   486,   489,   493,   519,   522,
     495,   496,   497,    31,   341,   498,  2481,  2481,  2481,   500,
    2481,  2481,   260,   260,   295,   295,   295,   295,   295,   295,
     295,   295,   236,   262,   262,  -796,   507,   508,  2100,    34,
    -796,   314,  -796,   314,  -796,   314,  -796,   314,   119,  -796,
    2481,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  2481,
    -796,   314,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
     314,  -796,  -796,  -796,  -796,  -796,  -796,   348,   350,   351,
     355,   527,  2481,   534,   503,   513,   427,  2481,  2481,   535,
     540,  -796,   -56,   476,   358,  2481,   542,  -796,  -796,  -796,
     516,   368,   523,  -796,  2481,   371,  2481,  -796,   -57,   549,
    -796,  2481,  2481,   393,   396,  -796,  -796,  -796,  -796,  -796,
    -796,  2481,   555,   428,   557,   530,  2481,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,   562,  -796,  -796,  -796,  -796,  -796,
     374,   377,   379,  -796,  -796,  -796,  -796,  -796,  -796,   536,
    2481,  2481,  2481,  2481,  -796,  -796,  -796,  -796,  2481,  -796,
    -796,  -796,  -796,  -796,  2481,  2481,  -796,  -796,  -796,  2849,
     537,  -796,   543,   570,   573,  2481,   433,   548,   382,   383,
    -796,  -796,  -796,  -796,  -796,  -796,   558,  -796,   560,  -796,
     386,   186,  -796,   584,  -796,   585,   586,  -796,   587,  -796,
     588,  -796,   583,  2100,   590,  2481,  2481,   314,  -796,   563,
     564,  2481,   314,  -796,  -796,  2481,  -796,    37,  2481,   368,
     594,   567,   368,   456,    73,   457,   459,  -796,   -57,  -796,
    -796,  -796,  -796,   568,  2481,  -796,  2481,   593,   576,  2481,
    -796,  -796,  -796,  -796,   578,   580,    52,    74,   581,   582,
     589,   591,  -796,  -796,  2481,  2481,   592,  -796,  -796,  -796,
    -796,   418,   429,  -796,   579,  -796,   596,  -796,  2481,   314,
     611,   612,   613,  2481,  -796,  -796,  2481,  -796,  -796,  -796,
     608,   610,   595,   599,   514,  2481,   615,   559,   600,   368,
    -796,   601,  -796,   371,   632,    48,  -796,  -796,  -796,   627,
    -796,  -796,  2481,   628,   607,  -796,  -796,  2481,  -796,  2481,
    -796,  -796,  -796,  -796,  -796,   609,   614,  -796,  -796,  -796,
     442,   443,   616,   617,   348,   350,   351,  -796,  -796,  2481,
    2481,  -796,  -796,  2481,   618,  2481,  2481,  -796,  -796,  -796,
    -796,   371,   636,  2481,  -796,  2481,  -796,   620,   622,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,   635,  -796,  -796,  -796,   371,  -796,  -796,  -796,  -796,
    2481,  -796,  -796
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     481,     0,   469,     1,   468,     0,     0,     0,   452,     0,
       0,   416,     0,     0,   443,     0,     0,     0,   264,     0,
     401,   405,   402,     0,     0,     0,     0,     0,     0,   444,
     399,     0,     0,     0,   394,   442,     0,     0,     0,   449,
     451,   397,   400,   407,   404,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   390,   391,     0,     0,     0,     0,   383,
     384,   385,   386,   465,   473,   470,   477,   479,   482,   392,
     393,     0,     0,   165,   166,   365,     0,     0,     0,   179,
     180,   367,     0,     0,     0,    79,    80,     0,     0,     0,
       0,     0,   121,   122,     0,     0,     0,     0,   112,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,    44,    49,    50,    51,    52,    53,    54,    57,
      58,     0,    63,    67,    65,     0,     2,    12,    15,    17,
       0,    76,    20,   190,   191,   368,     0,     0,     0,     0,
       0,     0,     0,   159,   160,   364,     0,     0,   222,   223,
     369,     0,   225,   226,   227,   231,   232,   370,   254,   255,
       0,     0,     0,   262,   263,   375,     0,   445,     0,   274,
     378,   270,   271,   446,     0,     0,   237,   238,     0,   241,
     242,   372,     0,   245,   246,   373,     0,   248,   252,   253,
     374,     0,   434,   440,   441,   422,     0,     0,   467,   395,
       0,   235,   236,   371,     0,   277,   278,   376,   272,   273,
     447,   450,   409,     0,     0,   408,   411,   412,   406,     0,
     296,   297,     0,   448,     0,     0,   379,   279,   377,   312,
     318,   457,   426,   417,   427,   328,   334,   420,   421,   338,
     380,   346,   345,   458,   435,   436,   437,   350,   348,   347,
     349,   351,     0,   438,     0,     0,   381,     0,     0,   382,
     388,   389,     0,   475,   439,     0,   463,   428,   425,     0,
       0,   469,   471,   469,   469,     0,     0,     0,   176,   173,
       0,     0,     0,     0,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    24,    25,    27,
      29,    30,    26,    31,   101,    23,     0,   115,   116,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117,   120,     0,   118,   119,     0,     0,   133,
     127,   128,   129,   130,    55,    42,    45,    46,    47,    48,
      43,    56,    64,   108,     0,   181,   187,   182,   183,   188,
     189,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,   185,   186,     0,     0,
     171,   172,   366,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   135,     0,     0,   212,   213,     0,     0,
       0,     0,   209,   208,   134,     0,     0,     0,   197,   198,
       0,     0,     0,     0,   194,   193,     0,   229,   224,     0,
     259,   256,     0,     0,   289,   293,   291,     0,     0,   403,
       0,     0,   244,   243,   250,   247,     0,   396,     0,     0,
       0,   234,   233,     0,     0,   410,     0,     0,     0,     0,
     310,   302,   304,   309,   306,   311,     0,   308,   316,     0,
       0,     0,   430,     0,   432,     0,   329,     0,     0,   343,
     341,     0,   358,   359,   361,   362,   387,   469,   459,     0,
       0,     0,     0,     0,   465,   474,   469,   478,   480,     0,
       0,   163,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    14,     5,     7,     8,     9,    10,     6,
       3,     4,    16,    18,    19,    21,     0,     0,     0,     0,
     141,     0,   153,     0,   145,     0,   149,     0,   137,   210,
       0,   217,   216,   221,   220,   215,   219,   214,   218,     0,
     195,     0,   202,   201,   206,   205,   200,   204,   199,   203,
       0,   230,   228,   260,   257,   261,   258,     0,     0,     0,
       0,   265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   398,     0,     0,     0,     0,   298,   303,   305,   307,
       0,     0,     0,   319,     0,     0,     0,   331,     0,   330,
     335,     0,     0,   355,   353,   352,   357,   360,   363,   476,
     460,     0,   336,     0,   320,     0,     0,   472,   164,   162,
     178,   175,   177,   174,     0,    75,    68,    70,    74,    72,
       0,     0,     0,    78,    77,    82,    81,    84,    83,     0,
       0,     0,     0,     0,    91,    92,    93,   100,     0,    94,
      95,    96,    97,    98,     0,     0,   110,   111,   102,     0,
       0,   106,     0,     0,     0,     0,     0,     0,     0,     0,
     169,   167,   138,   151,   143,   146,   140,   152,   144,   148,
       0,     0,   207,     0,   192,     0,   280,   290,   283,   294,
     286,   292,   266,     0,     0,     0,     0,     0,   423,     0,
       0,     0,     0,   413,   414,     0,   295,     0,     0,     0,
     300,     0,     0,     0,   322,     0,     0,   332,     0,   344,
     342,   356,   354,     0,     0,   429,     0,     0,     0,     0,
      69,    71,    73,   124,     0,     0,     0,     0,     0,     0,
       0,     0,   107,   125,     0,     0,     0,   109,    60,   170,
     168,     0,     0,   154,   139,   150,   142,   147,     0,     0,
       0,     0,     0,     0,   268,   267,     0,   240,   251,   249,
       0,     0,     0,     0,   415,     0,     0,     0,     0,     0,
     313,     0,   431,     0,   323,     0,   419,   433,   333,     0,
     337,   321,     0,     0,     0,    85,    86,     0,    87,     0,
      89,    99,   105,   104,    22,     0,     0,    62,   156,   158,
       0,     0,     0,     0,     0,     0,     0,   269,   239,     0,
       0,   276,   275,     0,     0,     0,     0,   317,   301,   315,
     325,     0,   324,     0,   462,     0,   131,     0,     0,   132,
     126,   155,   157,   211,   196,   282,   285,   288,   453,   454,
     424,     0,   455,   299,   326,     0,   464,   466,    88,    90,
       0,   327,   456
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -796,   -10,   -95,   -84,   239,  -216,    76,  -796,  -796,  -796,
    -410,  -796,  -796,  -796,   471,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,   490,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -225,  -796,  -222,  -796,  -221,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -736,  -309,  -796,  -796,  -796,  -796,   163,  -576,
    -795,   -54,  -572,  -366,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -305,  -796,  -796,  -796,  -304,  -796,  -796,  -796
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   684,   166,   167,   168,   169,   170,   343,   344,   171,
     172,   394,   579,   580,   445,   183,   184,   185,    83,    84,
      85,   420,   421,   422,    89,    90,    91,   400,   173,   174,
     175,   188,   189,   190,   195,   196,   197,   241,   242,   243,
     219,   220,   221,   223,   224,   225,   228,   229,   230,   203,
     204,   205,   209,   213,   250,   210,   245,   246,   247,   268,
     757,   830,   759,   831,   761,   832,   207,   637,   639,   638,
     263,   266,   781,   498,   270,   499,   500,   660,   271,   685,
     785,   277,   683,   280,   672,   671,   283,   292,   676,   293,
     296,   299,    75,   214,   503,   521,   664,   666,   309,   520,
     310,    76,   526,    77,   311,    78,   517,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     165,   523,   278,   186,   595,   737,   525,   206,   736,   527,
     528,   304,   303,   218,   304,    81,   231,   232,   305,   254,
     418,   305,   424,   238,   239,   306,   101,   426,   306,   251,
     428,   430,   346,   101,   392,   258,   374,   262,   729,  -461,
     267,   673,  -461,   848,   845,   177,   851,   279,   -59,   284,
     234,   372,   295,   178,   464,   298,   300,   301,   900,   867,
     467,   505,  -314,   226,    79,   370,   742,   490,   395,   396,
     179,   315,   846,   490,   506,     3,   318,   320,   322,   371,
     853,   869,   468,   743,   332,    80,    86,   868,   191,   187,
     389,    87,   783,   854,   786,   255,   390,   351,   180,   181,
     192,   193,   507,   465,   235,   793,   924,   395,   415,   870,
     798,   744,   745,   898,   176,   674,   491,   492,   493,   257,
     675,   855,   491,   492,   493,   373,   227,   494,   401,   402,
     931,    88,   403,   494,   404,   405,   406,   407,   408,   397,
     398,   399,   211,   208,   212,   466,   275,   276,   750,   773,
     347,   194,   307,   573,   375,   307,   256,   316,   222,   816,
     414,   393,   319,   321,   323,   495,   287,   751,   348,   285,
     286,   495,   376,   615,   288,   543,   544,   496,   397,   398,
     416,   457,   616,   496,   233,   497,   545,   336,   611,   612,
     460,   497,   657,   658,    82,   236,   593,   594,   669,   419,
     248,   425,   249,   659,   469,   470,   427,   281,   282,   429,
     431,   308,   472,   679,   308,   237,   474,   409,   824,   617,
     861,   687,   860,   240,   182,   410,   479,   480,   618,   252,
     481,   289,   290,   291,   244,   825,   337,   338,   339,   198,
     199,   200,   201,   484,   485,   340,   341,   342,   433,   434,
     626,   202,   253,   423,   488,   412,   435,   413,   259,   627,
     436,   437,   385,   826,   827,   386,   387,   458,   628,   438,
     265,   509,   388,   510,   613,   614,   461,   629,   439,  -340,
     440,   441,  -339,  -340,   512,  -340,  -339,   514,  -339,   442,
     443,   264,   516,   622,   623,   518,   624,   625,   473,   269,
     444,   272,   475,   401,   402,   789,   790,   531,   584,   585,
     586,   587,   588,   589,   590,   591,   482,   582,   583,   811,
     273,   302,   312,   547,   549,   551,   274,   313,   314,   317,
     324,   325,   333,   334,   335,   345,   349,   350,   352,   554,
     555,   353,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   354,
     355,   356,   433,   446,   357,   358,   359,   360,   361,   362,
     447,   363,   377,   364,   448,   449,   365,   366,   367,   368,
     369,   378,   379,   450,   380,   381,   382,   383,   384,   391,
     411,   414,   451,   532,   452,   453,   101,   432,   459,   462,
     463,   471,   478,   454,   455,   476,   483,   489,   596,   548,
     550,   552,   486,   487,   444,   501,   477,   502,  -418,   504,
     508,   511,   513,   515,   609,   519,   522,   529,   533,   534,
     530,   535,   536,   575,   598,   599,   537,   640,   538,   539,
     540,   541,   542,   601,   546,   553,   641,   651,   642,   631,
     610,   667,   633,   635,   670,   574,   576,   577,   578,   -61,
     581,   643,   603,   605,   607,   619,   644,   621,   646,   630,
     647,   648,   652,   649,   655,   662,   653,   654,   661,   656,
     668,   681,   686,   665,   688,   695,   689,   700,   701,   696,
     697,   698,   699,   702,   597,   703,   704,   705,   710,   711,
     600,   706,   602,   677,   604,   678,   606,   707,   608,   680,
     708,   682,   712,   713,   714,   715,   716,   717,   718,   719,
     720,   721,   620,   690,   722,   692,   724,   694,   723,   725,
     726,   727,   728,   731,   735,   632,   738,   739,   634,   636,
     763,   765,   771,   709,   730,   766,   902,   772,   775,   778,
     779,   756,   645,   758,   760,   767,   788,   782,   762,   650,
     791,   776,   794,   792,   796,   797,   732,   733,   734,   799,
     682,   803,   812,   780,   784,   768,   795,   814,   813,   800,
     815,   817,   801,   818,   802,   819,   820,   821,   740,   822,
     823,   828,   829,  -281,  -284,  -287,   833,   836,   840,   841,
     752,   849,   850,   859,   852,   856,   862,   857,   880,   753,
     691,   863,   693,   865,   787,   866,   871,   872,   884,   885,
     886,   889,   878,   890,   873,   881,   874,   877,   895,   893,
     891,   896,   764,   879,   892,   897,   899,   769,   770,   901,
     903,   905,   906,   925,   909,   777,   911,   912,   930,   910,
     592,   913,   914,   921,   682,   928,   682,   929,   456,   915,
     417,   279,   279,   916,   663,   917,     0,     0,     0,     0,
       0,     0,     0,     0,   741,     0,     0,   746,     0,   747,
       0,   748,     0,   749,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   754,     0,     0,
     804,   805,   806,   807,     0,     0,   755,     0,   808,     0,
       0,     0,     0,     0,   809,   810,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   774,     0,
       0,     0,     0,     0,   858,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   834,     0,   837,   838,     0,     0,     0,
       0,   842,     0,     0,     0,   844,     0,     0,   847,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   682,     0,     0,     0,     0,   864,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   875,   876,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   882,     0,
       0,     0,     0,   887,     0,     0,   888,     0,     0,     0,
       0,     0,     0,     0,     0,   894,     0,     0,     0,   835,
       0,     0,     0,   839,     0,     0,     0,     0,   843,     0,
       0,     0,   904,     0,     0,     0,     0,   907,     0,   908,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   918,
     919,     0,     0,   920,     4,   922,   923,     0,     0,     0,
       0,     5,     6,   926,     0,   927,     0,     0,     0,     0,
       0,     0,     0,     7,     8,   883,     9,     0,    10,    11,
       0,    12,    13,     0,     0,     0,     0,     0,     0,    14,
     932,    15,    16,    17,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,    28,
      29,     0,    30,     0,     0,    31,    32,    33,     0,    34,
      35,    36,    37,    38,    39,    40,     0,    41,     0,     0,
       0,    42,    43,    44,    45,    46,     0,    47,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      50,     0,     0,    51,     0,    52,    53,    54,     0,     0,
      55,     0,     0,     0,    56,     0,    57,     0,     0,     0,
      58,    59,    60,     0,     0,     0,     0,    61,     0,    62,
      63,    64,    65,    66,    67,     4,    68,    69,    70,    71,
      72,     0,     5,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     9,     0,    10,
      11,     0,    12,    13,    73,     0,    74,     0,     0,     0,
      14,     0,    15,    16,    17,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
      28,    29,     0,    30,     0,     0,    31,    32,    33,     0,
      34,    35,    36,    37,    38,    39,    40,     0,    41,     0,
       0,     0,    42,    43,    44,    45,    46,     0,    47,    48,
       0,     0,   294,     0,    92,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,     0,     0,     0,    93,
       0,    50,     0,     0,    51,     0,    52,    53,    54,    94,
       0,    55,     0,     0,     0,    56,     0,    57,     0,     0,
       0,    58,    59,    60,     0,    95,    96,    97,    61,     0,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    98,     0,     0,    99,     0,     0,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,   103,
       0,   104,     0,     0,     0,   524,     0,     0,     0,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,   108,   109,     0,     0,     0,     0,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,     0,     0,     0,   122,   123,   124,
       0,   125,   126,   127,     0,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
       0,   131,     0,     0,     0,   132,     0,     0,     0,     0,
       0,     0,     0,   133,     0,     0,   134,     0,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   297,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,    99,     0,     0,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   103,     0,
     104,     0,     0,     0,     0,     0,     0,     0,   105,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,   108,   109,     0,     0,     0,     0,     0,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,     0,     0,     0,   122,   123,   124,     0,
     125,   126,   127,     0,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   130,     0,
     131,     0,     0,     0,   132,     0,     0,     0,     0,     0,
       0,     0,   133,     0,     0,   134,     0,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    92,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
       0,     0,    93,   326,     0,     0,     0,     0,     0,     0,
       0,     0,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,     0,     0,    99,     0,
       0,   100,   327,   328,   329,     0,     0,     0,     0,     0,
       0,   102,   103,   330,   104,     0,     0,     0,     0,     0,
       0,     0,   105,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   108,   109,     0,     0,
       0,     0,     0,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,     0,     0,     0,
     122,   123,   124,   331,   125,   126,   127,     0,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,     0,   131,     0,     0,     0,   132,     0,
       0,     0,     0,     0,     0,     0,   133,     0,     0,   134,
       0,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    92,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,     0,     0,   215,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,     0,   216,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
       0,     0,    99,     0,     0,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   103,     0,   104,     0,
       0,     0,     0,     0,     0,     0,   105,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
     108,   109,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,     0,     0,     0,   122,   123,   124,     0,   125,   126,
     127,     0,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,     0,   131,     0,
       0,     0,   132,     0,     0,     0,     0,     0,     0,     0,
     133,     0,     0,   134,     0,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    92,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,     0,     0,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     0,     0,     0,     0,     0,     0,     0,   260,   261,
       0,     0,     0,     0,     0,     0,    95,    96,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,     0,     0,    99,     0,     0,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   102,
     103,     0,   104,     0,     0,     0,     0,     0,     0,     0,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,   108,   109,     0,     0,     0,     0,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,     0,     0,     0,   122,   123,
     124,     0,   125,   126,   127,     0,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,     0,   131,     0,     0,     0,   132,     0,     0,     0,
       0,     0,     0,     0,   133,     0,     0,   134,     0,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,    92,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,     0,     0,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    96,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,     0,     0,
      99,     0,     0,   100,     0,     0,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   104,     0,     0,     0,
       0,     0,     0,     0,   105,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,   108,   109,
       0,     0,     0,     0,     0,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,     0,
       0,     0,   122,   123,   124,     0,   125,   126,   127,     0,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,     0,   131,     0,     0,     0,
     132,     0,     0,     0,     0,     0,     0,     0,   133,     0,
       0,   134,     0,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   325,     0,     0,
       0,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,     0,     0,    99,     0,     0,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     102,   103,     0,   104,     0,     0,     0,     0,     0,     0,
       0,   105,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   108,   109,     0,     0,     0,
       0,     0,     0,     0,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,     0,     0,     0,   122,
     123,   124,     0,   125,   126,   127,     0,   128,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,     0,   131,     0,     0,     0,   132,     0,     0,
       0,     0,     0,     0,     0,   133,     0,     0,   134,     0,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      92,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,     0,
       0,    99,     0,     0,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   103,     0,   104,     0,     0,
       0,     0,     0,     0,     0,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,     0,     0,     0,     0,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
       0,     0,     0,   122,   123,   124,     0,   125,   126,   127,
       0,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,     0,   131,     0,     0,
       0,   132,     0,     0,     0,     0,     0,     0,     0,   133,
       0,     0,   134,     0,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    92,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,     0,     0,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,     0,     0,    99,     0,     0,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,   103,
       0,   104,     0,     0,     0,     0,     0,     0,     0,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,   109,     0,     0,     0,     0,     0,
       0,     0,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,     0,     0,     0,   122,   123,   124,
       0,   125,   126,   127,     0,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
       0,   131,     0,     0,     0,   132,     0,     0,     0,     0,
       0,     0,     0,   133,     0,     0,   134,     0,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    92,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,     0,     0,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,     0,     0,    99,
       0,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   102,   103,     0,   104,     0,     0,     0,     0,
       0,     0,     0,   105,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,   109,     0,
       0,     0,     0,     0,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,     0,     0,
       0,   122,   123,   124,     0,   125,   126,   127,     0,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,     0,   131,     0,     0,     0,   132,
       0,     0,     0,     0,     0,     0,     0,   133,     0,     0,
     134,     0,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164
};

static const yytype_int16 yycheck[] =
{
      10,   310,    56,    13,   414,   581,   311,    17,   580,   313,
     314,     6,     4,    23,     6,    24,    26,    27,    13,    68,
      24,    13,    24,    33,    34,    20,    82,    24,    20,    39,
      24,    24,    20,    82,    20,    45,    20,    47,     7,    34,
      50,    86,    34,   779,     7,    24,   782,    57,    34,    59,
      90,    86,    62,    32,    53,    65,    66,    67,   853,     7,
      20,     7,    20,    24,   203,    20,    32,    25,    79,    80,
      49,    81,    35,    25,    20,     0,    86,    87,    88,    34,
       7,     7,    42,    49,    94,   203,    26,    35,    24,    13,
     186,    31,   664,    20,   666,   144,   192,   107,    77,    78,
      36,    37,    48,   102,   144,   681,   901,    79,    80,    35,
     686,    77,    78,   849,    22,   160,    74,    75,    76,    43,
     165,    48,    74,    75,    76,   160,    87,    85,     8,     9,
     925,    71,    12,    85,    14,    15,    16,    17,    18,   150,
     151,   152,   203,   203,   205,   144,   203,   204,    29,   205,
     138,    87,   147,   369,   138,   147,   205,    81,    24,   735,
     129,   147,    86,    87,    88,   123,    97,    48,   156,    42,
      43,   123,   156,    45,   105,    74,    75,   135,   150,   151,
     152,   191,    54,   135,    90,   143,    85,    25,    56,    57,
     200,   143,    74,    75,   203,    34,   412,   413,   507,   203,
     203,   203,   205,    85,   214,   215,   203,   157,   158,   203,
     203,   206,   222,   517,   206,    34,   226,    97,    32,    45,
     796,   526,   794,    24,   203,   105,   236,   237,    54,   144,
     240,   162,   163,   164,    24,    49,    74,    75,    76,    42,
      43,    44,    45,   253,   254,    83,    84,    85,    24,    25,
      45,    54,    68,   177,   264,    19,    32,    21,   203,    54,
      36,    37,   182,    77,    78,   185,   186,   191,    45,    45,
     203,     5,   192,     7,    56,    57,   200,    54,    54,     0,
      56,    57,     0,     4,   294,     6,     4,   297,     6,    65,
      66,    34,   302,    56,    57,   305,    56,    57,   222,   203,
      76,   203,   226,     8,     9,   671,   672,   317,   403,   404,
     405,   406,   407,   408,   409,   410,   240,   401,   402,   729,
     203,   174,     6,   333,   334,   335,   203,     4,     4,    24,
     205,    20,    34,    34,    34,   205,    34,    34,    34,   349,
     350,    34,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,    34,
      34,    34,    24,    25,    34,    34,    34,    34,    34,    34,
      32,    34,    20,    34,    36,    37,    34,    34,    34,    34,
      34,    20,    20,    45,    20,    20,    20,    20,   185,   185,
     130,   129,    54,   317,    56,    57,    82,    24,    29,    46,
      46,     7,   147,    65,    66,    29,    34,     7,   418,   333,
     334,   335,    13,   152,    76,     7,    69,   147,   147,   147,
       7,     7,     7,     7,   434,    13,    34,    29,    72,    72,
      29,    72,    72,   203,    24,    48,    34,    42,    35,    35,
      35,    35,    35,    24,    35,    34,   203,    69,     7,   459,
      33,   505,   462,   463,   508,    34,    34,    34,    34,    34,
      34,   471,    24,    24,    24,    34,   476,    33,   478,    34,
       7,     7,     7,   483,     7,    20,   486,   102,    34,   489,
       7,    34,    34,   147,   203,   205,   203,    35,    35,   205,
     205,   205,   205,    35,   418,    35,    35,    35,     7,     7,
     424,    35,   426,   513,   428,   515,   430,    35,   432,   519,
      35,   521,     7,     7,    35,    35,    35,    35,     7,    35,
      35,    35,   446,   533,    35,   535,     7,   537,    35,     7,
      35,    35,    35,    35,    34,   459,    29,    29,   462,   463,
      13,     7,     7,   553,   203,    42,   855,     7,    72,     7,
      34,   203,   476,   203,   203,    42,     7,    34,   203,   483,
     167,   203,     7,   167,     7,    35,   576,   577,   578,     7,
     580,    35,    35,   205,   203,   148,   148,     7,    35,   205,
       7,   148,   205,    35,   205,   203,   203,    29,   598,    29,
     204,     7,     7,     7,     7,     7,    13,     7,    35,    35,
     610,     7,    35,    35,   148,   148,    13,   148,    29,   619,
     534,    35,   536,    35,   668,    35,    35,    35,     7,     7,
       7,    13,   204,    13,    35,    29,    35,    35,    13,   115,
      35,    72,   642,   204,    35,    35,    35,   647,   648,     7,
      13,    13,    35,     7,    35,   655,   204,   204,    13,    35,
     411,    35,    35,    35,   664,    35,   666,    35,   187,   884,
     170,   671,   672,   885,   501,   886,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   598,    -1,    -1,   601,    -1,   603,
      -1,   605,    -1,   607,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   621,    -1,    -1,
     710,   711,   712,   713,    -1,    -1,   630,    -1,   718,    -1,
      -1,    -1,    -1,    -1,   724,   725,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   652,    -1,
      -1,    -1,    -1,    -1,   788,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   763,    -1,   765,   766,    -1,    -1,    -1,
      -1,   771,    -1,    -1,    -1,   775,    -1,    -1,   778,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   794,    -1,    -1,    -1,    -1,   799,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   814,   815,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   828,    -1,
      -1,    -1,    -1,   833,    -1,    -1,   836,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   845,    -1,    -1,    -1,   763,
      -1,    -1,    -1,   767,    -1,    -1,    -1,    -1,   772,    -1,
      -1,    -1,   862,    -1,    -1,    -1,    -1,   867,    -1,   869,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   889,
     890,    -1,    -1,   893,     3,   895,   896,    -1,    -1,    -1,
      -1,    10,    11,   903,    -1,   905,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,   829,    25,    -1,    27,    28,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
     930,    40,    41,    42,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    88,
      89,    -1,    91,    -1,    -1,    94,    95,    96,    -1,    98,
      99,   100,   101,   102,   103,   104,    -1,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,    -1,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,   142,    -1,   144,   145,   146,    -1,    -1,
     149,    -1,    -1,    -1,   153,    -1,   155,    -1,    -1,    -1,
     159,   160,   161,    -1,    -1,    -1,    -1,   166,    -1,   168,
     169,   170,   171,   172,   173,     3,   175,   176,   177,   178,
     179,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    23,    -1,    25,    -1,    27,
      28,    -1,    30,    31,   203,    -1,   205,    -1,    -1,    -1,
      38,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      88,    89,    -1,    91,    -1,    -1,    94,    95,    96,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,    -1,   116,   117,
      -1,    -1,     7,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    24,
      -1,   139,    -1,    -1,   142,    -1,   144,   145,   146,    34,
      -1,   149,    -1,    -1,    -1,   153,    -1,   155,    -1,    -1,
      -1,   159,   160,   161,    -1,    50,    51,    52,   166,    -1,
     168,   169,   170,   171,   172,   173,    -1,   175,   176,   177,
     178,   179,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      -1,    86,    -1,    -1,    -1,   203,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,   136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,
      -1,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   168,    -1,    -1,   171,    -1,    -1,   174,
      -1,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,     7,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
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
      -1,    -1,   168,    -1,    -1,   171,    -1,    -1,   174,    -1,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     9,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
      -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      -1,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,   135,   136,   137,   138,    -1,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   154,    -1,   156,    -1,    -1,    -1,   160,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,   171,
      -1,    -1,   174,    -1,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     9,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,    -1,    -1,    24,    -1,    -1,    -1,
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
      -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     168,    -1,    -1,   171,    -1,    -1,   174,    -1,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     9,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     154,    -1,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   168,    -1,    -1,   171,    -1,    -1,
     174,    -1,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     9,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,   132,   133,   134,    -1,   136,   137,   138,    -1,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,    -1,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,
      -1,   171,    -1,    -1,   174,    -1,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,    -1,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,   171,    -1,
      -1,   174,    -1,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       9,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,   138,
      -1,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,
      -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,
      -1,    -1,   171,    -1,    -1,   174,    -1,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     9,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,   136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,
      -1,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   168,    -1,    -1,   171,    -1,    -1,   174,
      -1,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     9,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,   137,   138,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   154,    -1,   156,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,
     171,    -1,    -1,   174,    -1,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   314,   315,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    86,    88,    89,
      91,    94,    95,    96,    98,    99,   100,   101,   102,   103,
     104,   106,   110,   111,   112,   113,   114,   116,   117,   131,
     139,   142,   144,   145,   146,   149,   153,   155,   159,   160,
     161,   166,   168,   169,   170,   171,   172,   173,   175,   176,
     177,   178,   179,   203,   205,   299,   308,   310,   312,   203,
     203,    24,   203,   225,   226,   227,    26,    31,    71,   231,
     232,   233,     9,    24,    34,    50,    51,    52,    67,    70,
      73,    82,    83,    84,    86,    94,    95,   107,   108,   109,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   132,   133,   134,   136,   137,   138,   140,   141,
     154,   156,   160,   168,   171,   174,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   208,   209,   210,   211,   212,
     213,   216,   217,   235,   236,   237,    22,    24,    32,    49,
      77,    78,   203,   222,   223,   224,   208,   213,   238,   239,
     240,    24,    36,    37,    87,   241,   242,   243,    42,    43,
      44,    45,    54,   256,   257,   258,   208,   273,   203,   259,
     262,   203,   205,   260,   300,    24,    36,    37,   208,   247,
     248,   249,    24,   250,   251,   252,    24,    87,   253,   254,
     255,   208,   208,    90,    90,   144,    34,    34,   208,   208,
      24,   244,   245,   246,    24,   263,   264,   265,   203,   205,
     261,   208,   144,    68,    68,   144,   205,   213,   208,   203,
      42,    43,   208,   277,    34,   203,   278,   208,   266,   203,
     281,   285,   203,   203,   203,   203,   204,   288,   288,   208,
     290,   157,   158,   293,   208,    42,    43,    97,   105,   162,
     163,   164,   294,   296,     7,   208,   297,     7,   208,   298,
     208,   208,   174,     4,     6,    13,    20,   147,   206,   305,
     307,   311,     6,     4,     4,   208,   213,    24,   208,   213,
     208,   213,   208,   213,   205,    20,    25,    74,    75,    76,
      85,   135,   208,    34,    34,    34,    25,    74,    75,    76,
      83,    84,    85,   214,   215,   205,    20,   138,   156,    34,
      34,   208,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      20,    34,    86,   160,    20,   138,   156,    20,    20,    20,
      20,    20,    20,    20,   185,   182,   185,   186,   192,   186,
     192,   185,    20,   147,   218,    79,    80,   150,   151,   152,
     234,     8,     9,    12,    14,    15,    16,    17,    18,    97,
     105,   130,    19,    21,   129,    80,   152,   234,    24,   203,
     228,   229,   230,   213,    24,   203,    24,   203,    24,   203,
      24,   203,    24,    24,    25,    32,    36,    37,    45,    54,
      56,    57,    65,    66,    76,   221,    25,    32,    36,    37,
      45,    54,    56,    57,    65,    66,   221,   208,   213,    29,
     208,   213,    46,    46,    53,   102,   144,    20,    42,   208,
     208,     7,   208,   213,   208,   213,    29,    69,   147,   208,
     208,   208,   213,    34,   208,   208,    13,   152,   208,     7,
      25,    74,    75,    76,    85,   123,   135,   143,   280,   282,
     283,     7,   147,   301,   147,     7,    20,    48,     7,     5,
       7,     7,   208,     7,   208,     7,   208,   313,   208,    13,
     306,   302,    34,   280,   203,   308,   309,   312,   312,    29,
      29,   208,   213,    72,    72,    72,    72,    34,    35,    35,
      35,    35,    35,    74,    75,    85,    35,   208,   213,   208,
     213,   208,   213,    34,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   212,    34,   203,    34,    34,    34,   219,
     220,    34,   210,   210,   209,   209,   209,   209,   209,   209,
     209,   209,   211,   212,   212,   217,   208,   213,    24,    48,
     213,    24,   213,    24,   213,    24,   213,    24,   213,   208,
      33,    56,    57,    56,    57,    45,    54,    45,    54,    34,
     213,    33,    56,    57,    56,    57,    45,    54,    45,    54,
      34,   208,   213,   208,   213,   208,   213,   274,   276,   275,
      42,   203,     7,   208,   208,   213,   208,     7,     7,   208,
     213,    69,     7,   208,   102,     7,   208,    74,    75,    85,
     284,    34,    20,   285,   303,   147,   304,   288,     7,   280,
     288,   292,   291,    86,   160,   165,   295,   208,   208,   312,
     208,    34,   208,   289,   208,   286,    34,   308,   203,   203,
     208,   213,   208,   213,   208,   205,   205,   205,   205,   205,
      35,    35,    35,    35,    35,    35,    35,    35,    35,   208,
       7,     7,     7,     7,    35,    35,    35,    35,     7,    35,
      35,    35,    35,    35,     7,     7,    35,    35,    35,     7,
     203,    35,   208,   208,   208,    34,   289,   286,    29,    29,
     208,   213,    32,    49,    77,    78,   213,   213,   213,   213,
      29,    48,   208,   208,   213,   213,   203,   267,   203,   269,
     203,   271,   203,    13,   208,     7,    42,    42,   148,   208,
     208,     7,     7,   205,   213,    72,   203,   208,     7,    34,
     205,   279,    34,   289,   203,   287,   289,   288,     7,   290,
     290,   167,   167,   286,     7,   148,     7,    35,   286,     7,
     205,   205,   205,    35,   208,   208,   208,   208,   208,   208,
     208,   217,    35,    35,     7,     7,   286,   148,    35,   203,
     203,    29,    29,   204,    32,    49,    77,    78,     7,     7,
     268,   270,   272,    13,   208,   213,     7,   208,   208,   213,
      35,    35,   208,   213,   208,     7,    35,   208,   279,     7,
      35,   279,   148,     7,    20,    48,   148,   148,   288,    35,
     289,   286,    13,    35,   208,    35,    35,     7,    35,     7,
      35,    35,    35,    35,    35,   208,   208,    35,   204,   204,
      29,    29,   208,   213,     7,     7,     7,   208,   208,    13,
      13,    35,    35,   115,   208,    13,    72,    35,   279,    35,
     287,     7,   280,    13,   208,    13,    35,   208,   208,    35,
      35,   204,   204,    35,    35,   267,   269,   271,   208,   208,
     208,    35,   208,   208,   287,     7,   208,   208,    35,    35,
      13,   287,   208
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   207,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   209,   209,   209,   210,   210,   211,   211,   211,
     212,   212,   212,   213,   214,   214,   214,   214,   214,   214,
     214,   215,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   218,
     217,   219,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   220,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   221,   221,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   223,   223,   223,   223,   223,   224,
     224,   225,   225,   226,   226,   227,   227,   228,   228,   229,
     229,   230,   230,   231,   231,   231,   232,   232,   232,   233,
     233,   234,   234,   234,   235,   235,   235,   236,   236,   236,
     237,   237,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   240,   240,   241,   241,   241,   241,   241,   242,
     242,   243,   243,   244,   245,   246,   246,   247,   247,   248,
     248,   249,   249,   250,   251,   252,   252,   253,   253,   253,
     254,   254,   255,   255,   256,   256,   256,   256,   256,   257,
     257,   257,   258,   258,   259,   259,   259,   259,   259,   259,
     260,   260,   261,   261,   262,   263,   264,   265,   265,   266,
     267,   268,   267,   269,   270,   269,   271,   272,   271,   274,
     273,   275,   273,   276,   273,   277,   277,   277,   278,   278,
     279,   279,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   282,   281,   283,   281,   284,   281,   285,   285,
     286,   286,   287,   287,   287,   287,   287,   287,   288,   288,
     288,   288,   288,   288,   288,   288,   289,   289,   290,   290,
     290,   291,   290,   292,   290,   293,   293,   294,   294,   294,
     294,   294,   295,   295,   295,   295,   295,   296,   297,   297,
     297,   298,   298,   298,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   300,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   301,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   302,   299,
     303,   299,   304,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   305,   299,   306,   299,   307,   299,   299,   299,   299,
     308,   309,   308,   311,   310,   313,   312,   312,   312,   312,
     312,   315,   314
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
       2,     1,     1,     1,     5,     5,     7,     2,     2,     2,
       2,     7,     7,     2,     1,     1,     2,     3,     4,     5,
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
       1,     3,     1,     2,     3,     3,     4,     5,     1,     2,
       3,     3,     4,     5,     1,     3,     1,     3,     1,     2,
       2,     0,     4,     0,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     3,     2,     2,
       3,     2,     2,     3,     2,     2,     3,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     3,     2,     2,
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
#line 2898 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 80 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2907 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 84 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2915 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 87 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2923 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 90 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2931 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 93 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2939 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 96 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2947 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 99 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2955 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 102 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2963 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 109 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2971 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 112 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2980 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 125 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2989 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 129 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2998 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 137 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 3007 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 141 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 3016 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 148 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3024 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 153 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3032 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 156 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3040 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 159 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3048 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 162 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3056 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 165 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3064 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 168 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3072 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 171 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3080 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 176 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3088 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 181 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3097 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 185 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3106 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 189 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3115 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 193 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3124 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 197 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3133 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 201 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3142 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 205 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3151 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 209 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3160 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 213 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3169 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 217 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3178 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 221 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3187 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 225 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3196 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 229 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3205 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 233 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3214 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 237 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3223 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 241 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3232 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 245 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3241 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 249 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3250 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 253 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3259 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 257 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3268 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 261 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3277 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 265 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3286 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 269 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3295 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 273 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3304 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 277 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3313 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 281 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3322 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 285 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3331 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 291 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3340 "src-generated/ugbc.tab.c"
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
#line 3352 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 302 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3361 "src-generated/ugbc.tab.c"
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
#line 3373 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 313 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3381 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 316 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3389 "src-generated/ugbc.tab.c"
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
#line 3403 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 328 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3412 "src-generated/ugbc.tab.c"
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
#line 3424 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 339 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3433 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 343 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3442 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 347 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3451 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 351 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3460 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 355 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3469 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 359 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3478 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 363 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3487 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 367 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3496 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 371 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3504 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 374 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3512 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 377 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3520 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 380 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3528 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 383 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3536 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 386 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3544 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 389 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3552 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 392 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3560 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 395 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3568 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 398 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3576 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 401 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3584 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 404 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3592 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 407 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3600 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 410 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3608 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 413 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3616 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 416 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3624 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 419 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3632 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 422 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3640 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 425 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3648 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 428 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3656 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 431 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3664 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 434 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3672 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 437 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3680 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 440 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3688 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 443 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3696 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 446 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3704 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 449 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3712 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 452 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3720 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 455 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3728 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 458 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3736 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 461 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3744 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 464 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3752 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 467 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3760 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 469 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3769 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 473 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3777 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 476 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3785 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 479 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3794 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 483 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3803 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 487 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3812 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: PEN COLORS  */
#line 491 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3821 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: PEN DEFAULT  */
#line 495 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3830 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: DEFAULT PEN  */
#line 499 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3839 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: PAPER COLORS  */
#line 503 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3848 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: PAPER DEFAULT  */
#line 507 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3857 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: DEFAULT PAPER  */
#line 511 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3866 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: WIDTH  */
#line 515 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3874 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: HEIGHT  */
#line 518 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3882 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: TIMER  */
#line 521 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3890 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PEN DOLLAR OP expr CP  */
#line 524 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 3898 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER DOLLAR OP expr CP  */
#line 527 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3906 "src-generated/ugbc.tab.c"
    break;

  case 126: /* exponential: CMOVE DOLLAR OP expr COMMA expr CP  */
#line 530 "src/ugbc.y"
                                         {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3914 "src-generated/ugbc.tab.c"
    break;

  case 127: /* exponential: CUP DOLLAR  */
#line 533 "src/ugbc.y"
                 {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 3922 "src-generated/ugbc.tab.c"
    break;

  case 128: /* exponential: CDOWN DOLLAR  */
#line 536 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 3930 "src-generated/ugbc.tab.c"
    break;

  case 129: /* exponential: CLEFT DOLLAR  */
#line 539 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 3938 "src-generated/ugbc.tab.c"
    break;

  case 130: /* exponential: CRIGHT DOLLAR  */
#line 542 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 3946 "src-generated/ugbc.tab.c"
    break;

  case 131: /* exponential: AT DOLLAR OP expr COMMA expr CP  */
#line 545 "src/ugbc.y"
                                      {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3954 "src-generated/ugbc.tab.c"
    break;

  case 132: /* exponential: LOCATE DOLLAR OP expr COMMA expr CP  */
#line 548 "src/ugbc.y"
                                          {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3962 "src-generated/ugbc.tab.c"
    break;

  case 133: /* exponential: TAB DOLLAR  */
#line 551 "src/ugbc.y"
                 {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 3970 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bank_definition_simple: AT direct_integer  */
#line 559 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3978 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bank_definition_simple: Identifier AT direct_integer  */
#line 562 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3986 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 565 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3994 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 568 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4002 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 571 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4010 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_simple: DATA AT direct_integer  */
#line 574 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4018 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 578 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4026 "src-generated/ugbc.tab.c"
    break;

  case 143: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 581 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4034 "src-generated/ugbc.tab.c"
    break;

  case 144: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 584 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4042 "src-generated/ugbc.tab.c"
    break;

  case 145: /* bank_definition_simple: CODE AT direct_integer  */
#line 587 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4050 "src-generated/ugbc.tab.c"
    break;

  case 146: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 591 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4058 "src-generated/ugbc.tab.c"
    break;

  case 147: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 594 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4066 "src-generated/ugbc.tab.c"
    break;

  case 148: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 597 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4074 "src-generated/ugbc.tab.c"
    break;

  case 149: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 600 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4082 "src-generated/ugbc.tab.c"
    break;

  case 150: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 604 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4090 "src-generated/ugbc.tab.c"
    break;

  case 151: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 607 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4098 "src-generated/ugbc.tab.c"
    break;

  case 152: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 610 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4106 "src-generated/ugbc.tab.c"
    break;

  case 153: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 613 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4114 "src-generated/ugbc.tab.c"
    break;

  case 154: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 619 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4122 "src-generated/ugbc.tab.c"
    break;

  case 155: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 622 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4130 "src-generated/ugbc.tab.c"
    break;

  case 156: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 625 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4138 "src-generated/ugbc.tab.c"
    break;

  case 157: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 628 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4146 "src-generated/ugbc.tab.c"
    break;

  case 158: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 631 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4154 "src-generated/ugbc.tab.c"
    break;

  case 161: /* raster_definition_simple: Identifier AT direct_integer  */
#line 640 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 4162 "src-generated/ugbc.tab.c"
    break;

  case 162: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 643 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 4170 "src-generated/ugbc.tab.c"
    break;

  case 163: /* raster_definition_expression: Identifier AT expr  */
#line 648 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4178 "src-generated/ugbc.tab.c"
    break;

  case 164: /* raster_definition_expression: AT expr WITH Identifier  */
#line 651 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4186 "src-generated/ugbc.tab.c"
    break;

  case 167: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 660 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 4194 "src-generated/ugbc.tab.c"
    break;

  case 168: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 663 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 4202 "src-generated/ugbc.tab.c"
    break;

  case 169: /* next_raster_definition_expression: Identifier AT expr  */
#line 668 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 4210 "src-generated/ugbc.tab.c"
    break;

  case 170: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 671 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4218 "src-generated/ugbc.tab.c"
    break;

  case 173: /* color_definition_simple: BORDER direct_integer  */
#line 680 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 4226 "src-generated/ugbc.tab.c"
    break;

  case 174: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 683 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4234 "src-generated/ugbc.tab.c"
    break;

  case 175: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 686 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4242 "src-generated/ugbc.tab.c"
    break;

  case 176: /* color_definition_expression: BORDER expr  */
#line 691 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 4250 "src-generated/ugbc.tab.c"
    break;

  case 177: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 694 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4258 "src-generated/ugbc.tab.c"
    break;

  case 178: /* color_definition_expression: SPRITE expr TO expr  */
#line 697 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4266 "src-generated/ugbc.tab.c"
    break;

  case 184: /* wait_definition_simple: direct_integer CYCLES  */
#line 711 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4274 "src-generated/ugbc.tab.c"
    break;

  case 185: /* wait_definition_simple: direct_integer TICKS  */
#line 714 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4282 "src-generated/ugbc.tab.c"
    break;

  case 186: /* wait_definition_simple: direct_integer milliseconds  */
#line 717 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4290 "src-generated/ugbc.tab.c"
    break;

  case 187: /* wait_definition_expression: expr CYCLES  */
#line 722 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4298 "src-generated/ugbc.tab.c"
    break;

  case 188: /* wait_definition_expression: expr TICKS  */
#line 725 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4306 "src-generated/ugbc.tab.c"
    break;

  case 189: /* wait_definition_expression: expr milliseconds  */
#line 728 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4314 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 738 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4322 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 741 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4330 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 744 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4338 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 747 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4346 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 750 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4354 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_simple: direct_integer ENABLE  */
#line 753 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4362 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_simple: direct_integer DISABLE  */
#line 756 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4370 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 759 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4378 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 762 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4386 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 765 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4394 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 768 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4402 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 771 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4410 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 774 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4418 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 777 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4426 "src-generated/ugbc.tab.c"
    break;

  case 206: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 780 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4434 "src-generated/ugbc.tab.c"
    break;

  case 207: /* sprite_definition_expression: expr DATA FROM expr  */
#line 785 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4442 "src-generated/ugbc.tab.c"
    break;

  case 208: /* sprite_definition_expression: expr MULTICOLOR  */
#line 788 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4450 "src-generated/ugbc.tab.c"
    break;

  case 209: /* sprite_definition_expression: expr MONOCOLOR  */
#line 791 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4458 "src-generated/ugbc.tab.c"
    break;

  case 210: /* sprite_definition_expression: expr COLOR expr  */
#line 794 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4466 "src-generated/ugbc.tab.c"
    break;

  case 211: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 797 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4474 "src-generated/ugbc.tab.c"
    break;

  case 212: /* sprite_definition_expression: expr ENABLE  */
#line 800 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4482 "src-generated/ugbc.tab.c"
    break;

  case 213: /* sprite_definition_expression: expr DISABLE  */
#line 803 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4490 "src-generated/ugbc.tab.c"
    break;

  case 214: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 806 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4498 "src-generated/ugbc.tab.c"
    break;

  case 215: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 809 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4506 "src-generated/ugbc.tab.c"
    break;

  case 216: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 812 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4514 "src-generated/ugbc.tab.c"
    break;

  case 217: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 815 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4522 "src-generated/ugbc.tab.c"
    break;

  case 218: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 818 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4530 "src-generated/ugbc.tab.c"
    break;

  case 219: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 821 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4538 "src-generated/ugbc.tab.c"
    break;

  case 220: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 824 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4546 "src-generated/ugbc.tab.c"
    break;

  case 221: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 827 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4554 "src-generated/ugbc.tab.c"
    break;

  case 224: /* bitmap_definition_simple: AT direct_integer  */
#line 836 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4562 "src-generated/ugbc.tab.c"
    break;

  case 225: /* bitmap_definition_simple: ENABLE  */
#line 839 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4570 "src-generated/ugbc.tab.c"
    break;

  case 226: /* bitmap_definition_simple: DISABLE  */
#line 842 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4578 "src-generated/ugbc.tab.c"
    break;

  case 227: /* bitmap_definition_simple: CLEAR  */
#line 845 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4586 "src-generated/ugbc.tab.c"
    break;

  case 228: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 848 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4594 "src-generated/ugbc.tab.c"
    break;

  case 229: /* bitmap_definition_expression: AT expr  */
#line 854 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4602 "src-generated/ugbc.tab.c"
    break;

  case 230: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 857 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4610 "src-generated/ugbc.tab.c"
    break;

  case 233: /* textmap_definition_simple: AT direct_integer  */
#line 867 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4618 "src-generated/ugbc.tab.c"
    break;

  case 234: /* textmap_definition_expression: AT expr  */
#line 872 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4626 "src-generated/ugbc.tab.c"
    break;

  case 237: /* text_definition_simple: ENABLE  */
#line 881 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4634 "src-generated/ugbc.tab.c"
    break;

  case 238: /* text_definition_simple: DISABLE  */
#line 884 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4642 "src-generated/ugbc.tab.c"
    break;

  case 239: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 889 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4650 "src-generated/ugbc.tab.c"
    break;

  case 240: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 892 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4658 "src-generated/ugbc.tab.c"
    break;

  case 243: /* tiles_definition_simple: AT direct_integer  */
#line 901 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4666 "src-generated/ugbc.tab.c"
    break;

  case 244: /* tiles_definition_expression: AT expr  */
#line 906 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4674 "src-generated/ugbc.tab.c"
    break;

  case 247: /* colormap_definition_simple: AT direct_integer  */
#line 915 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4682 "src-generated/ugbc.tab.c"
    break;

  case 248: /* colormap_definition_simple: CLEAR  */
#line 918 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4690 "src-generated/ugbc.tab.c"
    break;

  case 249: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 921 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4698 "src-generated/ugbc.tab.c"
    break;

  case 250: /* colormap_definition_expression: AT expr  */
#line 926 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4706 "src-generated/ugbc.tab.c"
    break;

  case 251: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 929 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4714 "src-generated/ugbc.tab.c"
    break;

  case 254: /* screen_definition_simple: ON  */
#line 939 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4722 "src-generated/ugbc.tab.c"
    break;

  case 255: /* screen_definition_simple: OFF  */
#line 942 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4730 "src-generated/ugbc.tab.c"
    break;

  case 256: /* screen_definition_simple: ROWS direct_integer  */
#line 945 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4738 "src-generated/ugbc.tab.c"
    break;

  case 257: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 948 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4746 "src-generated/ugbc.tab.c"
    break;

  case 258: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 951 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4754 "src-generated/ugbc.tab.c"
    break;

  case 259: /* screen_definition_expression: ROWS expr  */
#line 956 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4762 "src-generated/ugbc.tab.c"
    break;

  case 260: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 959 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4770 "src-generated/ugbc.tab.c"
    break;

  case 261: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 962 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4778 "src-generated/ugbc.tab.c"
    break;

  case 265: /* var_definition_simple: Identifier ON Identifier  */
#line 971 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4786 "src-generated/ugbc.tab.c"
    break;

  case 266: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 974 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4794 "src-generated/ugbc.tab.c"
    break;

  case 267: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 977 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4802 "src-generated/ugbc.tab.c"
    break;

  case 268: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 980 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4812 "src-generated/ugbc.tab.c"
    break;

  case 269: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 985 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4822 "src-generated/ugbc.tab.c"
    break;

  case 270: /* goto_definition: Identifier  */
#line 992 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4830 "src-generated/ugbc.tab.c"
    break;

  case 271: /* goto_definition: Integer  */
#line 995 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4838 "src-generated/ugbc.tab.c"
    break;

  case 272: /* gosub_definition: Identifier  */
#line 1001 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4846 "src-generated/ugbc.tab.c"
    break;

  case 273: /* gosub_definition: Integer  */
#line 1004 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4854 "src-generated/ugbc.tab.c"
    break;

  case 275: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 1013 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4862 "src-generated/ugbc.tab.c"
    break;

  case 276: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 1019 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4870 "src-generated/ugbc.tab.c"
    break;

  case 279: /* ink_definition: expr  */
#line 1028 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4878 "src-generated/ugbc.tab.c"
    break;

  case 280: /* on_goto_definition: Identifier  */
#line 1033 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4887 "src-generated/ugbc.tab.c"
    break;

  case 281: /* $@4: %empty  */
#line 1037 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4895 "src-generated/ugbc.tab.c"
    break;

  case 283: /* on_gosub_definition: Identifier  */
#line 1042 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4904 "src-generated/ugbc.tab.c"
    break;

  case 284: /* $@5: %empty  */
#line 1046 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4912 "src-generated/ugbc.tab.c"
    break;

  case 286: /* on_proc_definition: Identifier  */
#line 1051 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4921 "src-generated/ugbc.tab.c"
    break;

  case 287: /* $@6: %empty  */
#line 1055 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4929 "src-generated/ugbc.tab.c"
    break;

  case 289: /* $@7: %empty  */
#line 1060 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4937 "src-generated/ugbc.tab.c"
    break;

  case 291: /* $@8: %empty  */
#line 1063 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4945 "src-generated/ugbc.tab.c"
    break;

  case 293: /* $@9: %empty  */
#line 1066 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4953 "src-generated/ugbc.tab.c"
    break;

  case 295: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1071 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4961 "src-generated/ugbc.tab.c"
    break;

  case 296: /* every_definition: ON  */
#line 1074 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4969 "src-generated/ugbc.tab.c"
    break;

  case 297: /* every_definition: OFF  */
#line 1077 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4977 "src-generated/ugbc.tab.c"
    break;

  case 298: /* add_definition: Identifier COMMA expr  */
#line 1082 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4985 "src-generated/ugbc.tab.c"
    break;

  case 299: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1085 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4993 "src-generated/ugbc.tab.c"
    break;

  case 300: /* dimensions: Integer  */
#line 1091 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5002 "src-generated/ugbc.tab.c"
    break;

  case 301: /* dimensions: Integer COMMA dimensions  */
#line 1095 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5011 "src-generated/ugbc.tab.c"
    break;

  case 302: /* datatype: BYTE  */
#line 1102 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 5019 "src-generated/ugbc.tab.c"
    break;

  case 303: /* datatype: SIGNED BYTE  */
#line 1105 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 5027 "src-generated/ugbc.tab.c"
    break;

  case 304: /* datatype: WORD  */
#line 1108 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 5035 "src-generated/ugbc.tab.c"
    break;

  case 305: /* datatype: SIGNED WORD  */
#line 1111 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 5043 "src-generated/ugbc.tab.c"
    break;

  case 306: /* datatype: DWORD  */
#line 1114 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 5051 "src-generated/ugbc.tab.c"
    break;

  case 307: /* datatype: SIGNED DWORD  */
#line 1117 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 5059 "src-generated/ugbc.tab.c"
    break;

  case 308: /* datatype: ADDRESS  */
#line 1120 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 5067 "src-generated/ugbc.tab.c"
    break;

  case 309: /* datatype: POSITION  */
#line 1123 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 5075 "src-generated/ugbc.tab.c"
    break;

  case 310: /* datatype: COLOR  */
#line 1126 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 5083 "src-generated/ugbc.tab.c"
    break;

  case 311: /* datatype: STRING  */
#line 1129 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 5091 "src-generated/ugbc.tab.c"
    break;

  case 312: /* $@10: %empty  */
#line 1134 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5100 "src-generated/ugbc.tab.c"
    break;

  case 313: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1137 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 5110 "src-generated/ugbc.tab.c"
    break;

  case 314: /* $@11: %empty  */
#line 1142 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5119 "src-generated/ugbc.tab.c"
    break;

  case 315: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1145 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 5129 "src-generated/ugbc.tab.c"
    break;

  case 316: /* $@12: %empty  */
#line 1150 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5138 "src-generated/ugbc.tab.c"
    break;

  case 317: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1153 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 5148 "src-generated/ugbc.tab.c"
    break;

  case 320: /* indexes: expr  */
#line 1166 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5157 "src-generated/ugbc.tab.c"
    break;

  case 321: /* indexes: expr COMMA indexes  */
#line 1170 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5166 "src-generated/ugbc.tab.c"
    break;

  case 322: /* parameters: Identifier  */
#line 1177 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5176 "src-generated/ugbc.tab.c"
    break;

  case 323: /* parameters: Identifier DOLLAR  */
#line 1182 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5186 "src-generated/ugbc.tab.c"
    break;

  case 324: /* parameters: Identifier AS datatype  */
#line 1187 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5196 "src-generated/ugbc.tab.c"
    break;

  case 325: /* parameters: Identifier COMMA parameters  */
#line 1192 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5206 "src-generated/ugbc.tab.c"
    break;

  case 326: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1197 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5216 "src-generated/ugbc.tab.c"
    break;

  case 327: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1202 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5226 "src-generated/ugbc.tab.c"
    break;

  case 328: /* parameters_expr: Identifier  */
#line 1210 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5236 "src-generated/ugbc.tab.c"
    break;

  case 329: /* parameters_expr: Identifier DOLLAR  */
#line 1215 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5246 "src-generated/ugbc.tab.c"
    break;

  case 330: /* parameters_expr: Identifier AS datatype  */
#line 1220 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5256 "src-generated/ugbc.tab.c"
    break;

  case 331: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1225 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5266 "src-generated/ugbc.tab.c"
    break;

  case 332: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1230 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5276 "src-generated/ugbc.tab.c"
    break;

  case 333: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1235 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5286 "src-generated/ugbc.tab.c"
    break;

  case 334: /* parameters_expr: String  */
#line 1240 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5295 "src-generated/ugbc.tab.c"
    break;

  case 335: /* parameters_expr: String COMMA parameters_expr  */
#line 1244 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5304 "src-generated/ugbc.tab.c"
    break;

  case 336: /* values: expr  */
#line 1251 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5313 "src-generated/ugbc.tab.c"
    break;

  case 337: /* values: expr COMMA values  */
#line 1255 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5322 "src-generated/ugbc.tab.c"
    break;

  case 338: /* print_definition: expr  */
#line 1262 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5330 "src-generated/ugbc.tab.c"
    break;

  case 339: /* print_definition: expr COMMA  */
#line 1265 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5339 "src-generated/ugbc.tab.c"
    break;

  case 340: /* print_definition: expr SEMICOLON  */
#line 1269 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5347 "src-generated/ugbc.tab.c"
    break;

  case 341: /* $@13: %empty  */
#line 1272 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5356 "src-generated/ugbc.tab.c"
    break;

  case 343: /* $@14: %empty  */
#line 1276 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5364 "src-generated/ugbc.tab.c"
    break;

  case 345: /* use_definition: ANSI  */
#line 1282 "src/ugbc.y"
         {
        use_ansi( _environment );
    }
#line 5372 "src-generated/ugbc.tab.c"
    break;

  case 346: /* use_definition: SPECIFIC  */
#line 1285 "src/ugbc.y"
             {
        use_specific( _environment );
  }
#line 5380 "src-generated/ugbc.tab.c"
    break;

  case 347: /* writing_mode_definition: REPLACE  */
#line 1291 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5389 "src-generated/ugbc.tab.c"
    break;

  case 348: /* writing_mode_definition: OR  */
#line 1295 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5398 "src-generated/ugbc.tab.c"
    break;

  case 349: /* writing_mode_definition: XOR  */
#line 1299 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5407 "src-generated/ugbc.tab.c"
    break;

  case 350: /* writing_mode_definition: AND  */
#line 1303 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5416 "src-generated/ugbc.tab.c"
    break;

  case 351: /* writing_mode_definition: IGNORE  */
#line 1307 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5425 "src-generated/ugbc.tab.c"
    break;

  case 352: /* writing_part_definition: NORMAL  */
#line 1314 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5434 "src-generated/ugbc.tab.c"
    break;

  case 353: /* writing_part_definition: PAPER  */
#line 1318 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5443 "src-generated/ugbc.tab.c"
    break;

  case 354: /* writing_part_definition: PAPER ONLY  */
#line 1322 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5452 "src-generated/ugbc.tab.c"
    break;

  case 355: /* writing_part_definition: PEN  */
#line 1326 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5461 "src-generated/ugbc.tab.c"
    break;

  case 356: /* writing_part_definition: PEN ONLY  */
#line 1330 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5470 "src-generated/ugbc.tab.c"
    break;

  case 357: /* writing_definition: writing_mode_definition COMMA writing_part_definition  */
#line 1337 "src/ugbc.y"
                                                          {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5478 "src-generated/ugbc.tab.c"
    break;

  case 358: /* locate_definition: COMMA expr  */
#line 1343 "src/ugbc.y"
                {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 5486 "src-generated/ugbc.tab.c"
    break;

  case 359: /* locate_definition: expr COMMA  */
#line 1346 "src/ugbc.y"
                 {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 5494 "src-generated/ugbc.tab.c"
    break;

  case 360: /* locate_definition: expr COMMA expr  */
#line 1349 "src/ugbc.y"
                      {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5502 "src-generated/ugbc.tab.c"
    break;

  case 361: /* cmove_definition: COMMA expr  */
#line 1355 "src/ugbc.y"
                {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 5510 "src-generated/ugbc.tab.c"
    break;

  case 362: /* cmove_definition: expr COMMA  */
#line 1358 "src/ugbc.y"
                 {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 5518 "src-generated/ugbc.tab.c"
    break;

  case 363: /* cmove_definition: expr COMMA expr  */
#line 1361 "src/ugbc.y"
                      {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5526 "src-generated/ugbc.tab.c"
    break;

  case 383: /* statement: CUP  */
#line 1386 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 5534 "src-generated/ugbc.tab.c"
    break;

  case 384: /* statement: CDOWN  */
#line 1389 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 5542 "src-generated/ugbc.tab.c"
    break;

  case 385: /* statement: CLEFT  */
#line 1392 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 5550 "src-generated/ugbc.tab.c"
    break;

  case 386: /* statement: CRIGHT  */
#line 1395 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 5558 "src-generated/ugbc.tab.c"
    break;

  case 387: /* statement: SET TAB expr  */
#line 1398 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 5566 "src-generated/ugbc.tab.c"
    break;

  case 388: /* statement: CENTER expr  */
#line 1401 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5574 "src-generated/ugbc.tab.c"
    break;

  case 389: /* statement: CENTRE expr  */
#line 1404 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5582 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: CLS  */
#line 1407 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 5590 "src-generated/ugbc.tab.c"
    break;

  case 391: /* statement: HOME  */
#line 1410 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 5598 "src-generated/ugbc.tab.c"
    break;

  case 392: /* statement: INC Identifier  */
#line 1413 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 5606 "src-generated/ugbc.tab.c"
    break;

  case 393: /* statement: DEC Identifier  */
#line 1416 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 5614 "src-generated/ugbc.tab.c"
    break;

  case 394: /* statement: RANDOMIZE  */
#line 1419 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 5622 "src-generated/ugbc.tab.c"
    break;

  case 395: /* statement: RANDOMIZE expr  */
#line 1422 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 5630 "src-generated/ugbc.tab.c"
    break;

  case 396: /* statement: IF expr THEN  */
#line 1425 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5638 "src-generated/ugbc.tab.c"
    break;

  case 397: /* statement: ELSE  */
#line 1428 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 5646 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statement: ELSE IF expr THEN  */
#line 1431 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5654 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: ENDIF  */
#line 1434 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5662 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: DO  */
#line 1437 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5670 "src-generated/ugbc.tab.c"
    break;

  case 401: /* statement: LOOP  */
#line 1440 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5678 "src-generated/ugbc.tab.c"
    break;

  case 402: /* $@15: %empty  */
#line 1443 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5686 "src-generated/ugbc.tab.c"
    break;

  case 403: /* statement: WHILE $@15 expr  */
#line 1445 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5694 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: WEND  */
#line 1448 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5702 "src-generated/ugbc.tab.c"
    break;

  case 405: /* statement: REPEAT  */
#line 1451 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5710 "src-generated/ugbc.tab.c"
    break;

  case 406: /* statement: UNTIL expr  */
#line 1454 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5718 "src-generated/ugbc.tab.c"
    break;

  case 407: /* statement: EXIT  */
#line 1457 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5726 "src-generated/ugbc.tab.c"
    break;

  case 408: /* statement: EXIT PROC  */
#line 1460 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5734 "src-generated/ugbc.tab.c"
    break;

  case 409: /* statement: POP PROC  */
#line 1463 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5742 "src-generated/ugbc.tab.c"
    break;

  case 410: /* statement: EXIT IF expr  */
#line 1466 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5750 "src-generated/ugbc.tab.c"
    break;

  case 411: /* statement: EXIT Integer  */
#line 1469 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5758 "src-generated/ugbc.tab.c"
    break;

  case 412: /* statement: EXIT direct_integer  */
#line 1472 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5766 "src-generated/ugbc.tab.c"
    break;

  case 413: /* statement: EXIT IF expr COMMA Integer  */
#line 1475 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5774 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1478 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5782 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1481 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5790 "src-generated/ugbc.tab.c"
    break;

  case 416: /* statement: NEXT  */
#line 1484 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5798 "src-generated/ugbc.tab.c"
    break;

  case 417: /* statement: PROCEDURE Identifier  */
#line 1487 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5807 "src-generated/ugbc.tab.c"
    break;

  case 418: /* $@16: %empty  */
#line 1491 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5815 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1493 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5823 "src-generated/ugbc.tab.c"
    break;

  case 420: /* statement: SHARED parameters_expr  */
#line 1496 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5831 "src-generated/ugbc.tab.c"
    break;

  case 421: /* statement: GLOBAL parameters_expr  */
#line 1499 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5839 "src-generated/ugbc.tab.c"
    break;

  case 422: /* statement: END PROC  */
#line 1502 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 5847 "src-generated/ugbc.tab.c"
    break;

  case 423: /* statement: END PROC OSP expr CSP  */
#line 1505 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5855 "src-generated/ugbc.tab.c"
    break;

  case 424: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1508 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5863 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: Identifier " "  */
#line 1511 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5872 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: PROC Identifier  */
#line 1515 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5881 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: CALL Identifier  */
#line 1519 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5890 "src-generated/ugbc.tab.c"
    break;

  case 428: /* $@17: %empty  */
#line 1523 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5898 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: Identifier OSP $@17 values CSP  */
#line 1525 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5906 "src-generated/ugbc.tab.c"
    break;

  case 430: /* $@18: %empty  */
#line 1528 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5914 "src-generated/ugbc.tab.c"
    break;

  case 431: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1530 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5922 "src-generated/ugbc.tab.c"
    break;

  case 432: /* $@19: %empty  */
#line 1533 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5930 "src-generated/ugbc.tab.c"
    break;

  case 433: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1535 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5938 "src-generated/ugbc.tab.c"
    break;

  case 434: /* statement: PEN expr  */
#line 1538 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 5946 "src-generated/ugbc.tab.c"
    break;

  case 435: /* statement: PAPER expr  */
#line 1541 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 5954 "src-generated/ugbc.tab.c"
    break;

  case 436: /* statement: INVERSE ON  */
#line 1544 "src/ugbc.y"
               {
      text_inverse( _environment, 1 );
  }
#line 5962 "src-generated/ugbc.tab.c"
    break;

  case 437: /* statement: INVERSE OFF  */
#line 1547 "src/ugbc.y"
                {
      text_inverse( _environment, 0 );
  }
#line 5970 "src-generated/ugbc.tab.c"
    break;

  case 439: /* statement: Identifier COLON  */
#line 1551 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 5978 "src-generated/ugbc.tab.c"
    break;

  case 440: /* statement: BEG GAMELOOP  */
#line 1554 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 5986 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: END GAMELOOP  */
#line 1557 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 5994 "src-generated/ugbc.tab.c"
    break;

  case 442: /* statement: GRAPHIC  */
#line 1560 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 6002 "src-generated/ugbc.tab.c"
    break;

  case 443: /* statement: HALT  */
#line 1563 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 6010 "src-generated/ugbc.tab.c"
    break;

  case 444: /* statement: END  */
#line 1566 "src/ugbc.y"
        {
      end( _environment );
  }
#line 6018 "src-generated/ugbc.tab.c"
    break;

  case 449: /* statement: RETURN  */
#line 1573 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 6026 "src-generated/ugbc.tab.c"
    break;

  case 450: /* statement: RETURN expr  */
#line 1576 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 6034 "src-generated/ugbc.tab.c"
    break;

  case 451: /* statement: POP  */
#line 1579 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 6042 "src-generated/ugbc.tab.c"
    break;

  case 452: /* statement: DONE  */
#line 1582 "src/ugbc.y"
          {
      return 0;
  }
#line 6050 "src-generated/ugbc.tab.c"
    break;

  case 453: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1585 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6058 "src-generated/ugbc.tab.c"
    break;

  case 454: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1588 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6066 "src-generated/ugbc.tab.c"
    break;

  case 455: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1591 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 6074 "src-generated/ugbc.tab.c"
    break;

  case 456: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1594 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6082 "src-generated/ugbc.tab.c"
    break;

  case 459: /* statement: Identifier ASSIGN expr  */
#line 1599 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 6096 "src-generated/ugbc.tab.c"
    break;

  case 460: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1608 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 6110 "src-generated/ugbc.tab.c"
    break;

  case 461: /* $@20: %empty  */
#line 1617 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6119 "src-generated/ugbc.tab.c"
    break;

  case 462: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1621 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 6132 "src-generated/ugbc.tab.c"
    break;

  case 463: /* $@21: %empty  */
#line 1629 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6141 "src-generated/ugbc.tab.c"
    break;

  case 464: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1632 "src/ugbc.y"
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
#line 6160 "src-generated/ugbc.tab.c"
    break;

  case 465: /* $@22: %empty  */
#line 1646 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6169 "src-generated/ugbc.tab.c"
    break;

  case 466: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1649 "src/ugbc.y"
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
#line 6188 "src-generated/ugbc.tab.c"
    break;

  case 467: /* statement: DEBUG expr  */
#line 1663 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 6196 "src-generated/ugbc.tab.c"
    break;

  case 470: /* statements_no_linenumbers: statement  */
#line 1671 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 6202 "src-generated/ugbc.tab.c"
    break;

  case 471: /* $@23: %empty  */
#line 1672 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 6208 "src-generated/ugbc.tab.c"
    break;

  case 473: /* $@24: %empty  */
#line 1676 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 6216 "src-generated/ugbc.tab.c"
    break;

  case 474: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1678 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 6224 "src-generated/ugbc.tab.c"
    break;

  case 475: /* $@25: %empty  */
#line 1683 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 6232 "src-generated/ugbc.tab.c"
    break;

  case 481: /* $@26: %empty  */
#line 1693 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 6238 "src-generated/ugbc.tab.c"
    break;


#line 6242 "src-generated/ugbc.tab.c"

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

#line 1695 "src/ugbc.y"


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

