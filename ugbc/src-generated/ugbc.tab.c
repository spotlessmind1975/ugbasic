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
  YYSYMBOL_CLINE = 180,                    /* CLINE  */
  YYSYMBOL_XCURS = 181,                    /* XCURS  */
  YYSYMBOL_YCURS = 182,                    /* YCURS  */
  YYSYMBOL_BLACK = 183,                    /* BLACK  */
  YYSYMBOL_WHITE = 184,                    /* WHITE  */
  YYSYMBOL_RED = 185,                      /* RED  */
  YYSYMBOL_CYAN = 186,                     /* CYAN  */
  YYSYMBOL_VIOLET = 187,                   /* VIOLET  */
  YYSYMBOL_GREEN = 188,                    /* GREEN  */
  YYSYMBOL_BLUE = 189,                     /* BLUE  */
  YYSYMBOL_YELLOW = 190,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 191,                   /* ORANGE  */
  YYSYMBOL_BROWN = 192,                    /* BROWN  */
  YYSYMBOL_LIGHT = 193,                    /* LIGHT  */
  YYSYMBOL_DARK = 194,                     /* DARK  */
  YYSYMBOL_GREY = 195,                     /* GREY  */
  YYSYMBOL_GRAY = 196,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 197,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 198,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 199,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 200,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 201,                /* TURQUOISE  */
  YYSYMBOL_TAN = 202,                      /* TAN  */
  YYSYMBOL_PINK = 203,                     /* PINK  */
  YYSYMBOL_PEACH = 204,                    /* PEACH  */
  YYSYMBOL_OLIVE = 205,                    /* OLIVE  */
  YYSYMBOL_Identifier = 206,               /* Identifier  */
  YYSYMBOL_String = 207,                   /* String  */
  YYSYMBOL_Integer = 208,                  /* Integer  */
  YYSYMBOL_209_ = 209,                     /* " "  */
  YYSYMBOL_YYACCEPT = 210,                 /* $accept  */
  YYSYMBOL_expr = 211,                     /* expr  */
  YYSYMBOL_expr_math = 212,                /* expr_math  */
  YYSYMBOL_term = 213,                     /* term  */
  YYSYMBOL_modula = 214,                   /* modula  */
  YYSYMBOL_factor = 215,                   /* factor  */
  YYSYMBOL_direct_integer = 216,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 217, /* random_definition_simple  */
  YYSYMBOL_random_definition = 218,        /* random_definition  */
  YYSYMBOL_color_enumeration = 219,        /* color_enumeration  */
  YYSYMBOL_exponential = 220,              /* exponential  */
  YYSYMBOL_221_1 = 221,                    /* $@1  */
  YYSYMBOL_222_2 = 222,                    /* $@2  */
  YYSYMBOL_223_3 = 223,                    /* $@3  */
  YYSYMBOL_position = 224,                 /* position  */
  YYSYMBOL_bank_definition_simple = 225,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 226, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 227,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 228, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 229, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 230,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 231, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 232, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 233,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 234,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 235, /* color_definition_expression  */
  YYSYMBOL_color_definition = 236,         /* color_definition  */
  YYSYMBOL_milliseconds = 237,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 238,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 239, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 240,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 241, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 242, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 243,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 244, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 245, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 246,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 247, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 248, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 249,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 250,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 251, /* text_definition_expression  */
  YYSYMBOL_text_definition = 252,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 253,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 254, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 255,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 256, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 257, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 258,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 259, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 260, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 261,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 262,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 263,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 264,         /* gosub_definition  */
  YYSYMBOL_var_definition = 265,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 266,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 267, /* point_definition_expression  */
  YYSYMBOL_point_definition = 268,         /* point_definition  */
  YYSYMBOL_ink_definition = 269,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 270,       /* on_goto_definition  */
  YYSYMBOL_271_4 = 271,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 272,      /* on_gosub_definition  */
  YYSYMBOL_273_5 = 273,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 274,       /* on_proc_definition  */
  YYSYMBOL_275_6 = 275,                    /* $@6  */
  YYSYMBOL_on_definition = 276,            /* on_definition  */
  YYSYMBOL_277_7 = 277,                    /* $@7  */
  YYSYMBOL_278_8 = 278,                    /* $@8  */
  YYSYMBOL_279_9 = 279,                    /* $@9  */
  YYSYMBOL_every_definition = 280,         /* every_definition  */
  YYSYMBOL_add_definition = 281,           /* add_definition  */
  YYSYMBOL_dimensions = 282,               /* dimensions  */
  YYSYMBOL_datatype = 283,                 /* datatype  */
  YYSYMBOL_dim_definition = 284,           /* dim_definition  */
  YYSYMBOL_285_10 = 285,                   /* $@10  */
  YYSYMBOL_286_11 = 286,                   /* $@11  */
  YYSYMBOL_287_12 = 287,                   /* $@12  */
  YYSYMBOL_dim_definitions = 288,          /* dim_definitions  */
  YYSYMBOL_indexes = 289,                  /* indexes  */
  YYSYMBOL_parameters = 290,               /* parameters  */
  YYSYMBOL_parameters_expr = 291,          /* parameters_expr  */
  YYSYMBOL_values = 292,                   /* values  */
  YYSYMBOL_print_definition = 293,         /* print_definition  */
  YYSYMBOL_294_13 = 294,                   /* $@13  */
  YYSYMBOL_295_14 = 295,                   /* $@14  */
  YYSYMBOL_use_definition = 296,           /* use_definition  */
  YYSYMBOL_writing_mode_definition = 297,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 298,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 299,       /* writing_definition  */
  YYSYMBOL_locate_definition = 300,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 301,         /* cmove_definition  */
  YYSYMBOL_statement = 302,                /* statement  */
  YYSYMBOL_303_15 = 303,                   /* $@15  */
  YYSYMBOL_304_16 = 304,                   /* $@16  */
  YYSYMBOL_305_17 = 305,                   /* $@17  */
  YYSYMBOL_306_18 = 306,                   /* $@18  */
  YYSYMBOL_307_19 = 307,                   /* $@19  */
  YYSYMBOL_308_20 = 308,                   /* $@20  */
  YYSYMBOL_309_21 = 309,                   /* $@21  */
  YYSYMBOL_310_22 = 310,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 311, /* statements_no_linenumbers  */
  YYSYMBOL_312_23 = 312,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 313, /* statements_with_linenumbers  */
  YYSYMBOL_314_24 = 314,                   /* $@24  */
  YYSYMBOL_statements_complex = 315,       /* statements_complex  */
  YYSYMBOL_316_25 = 316,                   /* $@25  */
  YYSYMBOL_program = 317,                  /* program  */
  YYSYMBOL_318_26 = 318                    /* $@26  */
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
#define YYLAST   3133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  210
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  486
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  937

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   464


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
     205,   206,   207,   208,   209
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
     542,   545,   548,   551,   554,   557,   562,   562,   565,   568,
     571,   574,   577,   580,   584,   587,   590,   593,   597,   600,
     603,   606,   610,   613,   616,   619,   625,   628,   631,   634,
     637,   642,   643,   646,   649,   654,   657,   662,   663,   666,
     669,   674,   677,   682,   683,   686,   689,   692,   697,   700,
     703,   708,   709,   712,   713,   714,   717,   720,   723,   728,
     731,   734,   740,   741,   744,   747,   750,   753,   756,   759,
     762,   765,   768,   771,   774,   777,   780,   783,   786,   791,
     794,   797,   800,   803,   806,   809,   812,   815,   818,   821,
     824,   827,   830,   833,   838,   839,   842,   845,   848,   851,
     854,   860,   863,   869,   870,   873,   878,   883,   884,   887,
     890,   895,   898,   903,   904,   907,   912,   917,   918,   921,
     924,   927,   932,   935,   941,   942,   945,   948,   951,   954,
     957,   962,   965,   968,   973,   974,   976,   977,   980,   983,
     986,   991,   998,  1001,  1007,  1010,  1016,  1019,  1025,  1030,
    1031,  1034,  1039,  1043,  1043,  1048,  1052,  1052,  1057,  1061,
    1061,  1066,  1066,  1069,  1069,  1072,  1072,  1077,  1080,  1083,
    1088,  1091,  1097,  1101,  1108,  1111,  1114,  1117,  1120,  1123,
    1126,  1129,  1132,  1135,  1140,  1140,  1148,  1148,  1156,  1156,
    1167,  1168,  1172,  1176,  1183,  1188,  1193,  1198,  1203,  1208,
    1216,  1221,  1226,  1231,  1236,  1241,  1246,  1250,  1257,  1261,
    1268,  1271,  1275,  1278,  1278,  1282,  1282,  1288,  1291,  1297,
    1301,  1305,  1309,  1313,  1320,  1324,  1328,  1332,  1336,  1343,
    1349,  1352,  1355,  1361,  1364,  1367,  1373,  1374,  1375,  1376,
    1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,  1385,  1386,
    1387,  1388,  1389,  1390,  1391,  1392,  1395,  1398,  1401,  1404,
    1407,  1410,  1413,  1416,  1419,  1422,  1425,  1428,  1431,  1434,
    1437,  1440,  1443,  1446,  1449,  1452,  1455,  1455,  1460,  1463,
    1466,  1469,  1472,  1475,  1478,  1481,  1484,  1487,  1490,  1493,
    1496,  1499,  1503,  1503,  1508,  1511,  1514,  1517,  1520,  1523,
    1527,  1531,  1535,  1535,  1540,  1540,  1545,  1545,  1550,  1553,
    1556,  1559,  1562,  1563,  1566,  1569,  1572,  1575,  1578,  1581,
    1582,  1583,  1584,  1585,  1588,  1591,  1594,  1597,  1600,  1603,
    1606,  1609,  1610,  1611,  1620,  1629,  1629,  1641,  1641,  1658,
    1658,  1675,  1678,  1679,  1683,  1684,  1684,  1688,  1688,  1695,
    1695,  1698,  1699,  1700,  1701,  1705,  1705
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
  "CUP", "CDOWN", "CLEFT", "CRIGHT", "CLINE", "XCURS", "YCURS", "BLACK",
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
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464
};
#endif

#define YYPACT_NINF (-807)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-466)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -807,    32,   885,  -807,  -807,  -170,  -144,   -14,  -807,   134,
    2164,    44,    18,  2164,  -807,    98,   200,  2551,  -137,   -17,
    -807,  -807,  -807,  1790,    89,    17,  2551,  2551,    36,   -47,
    -807,   116,   154,  2551,  2551,  -807,   115,   182,     3,  2551,
      88,   148,  -807,   -38,  -807,  2551,    52,  1977,   237,    80,
    2551,    85,   104,   107,   109,  -133,  -133,  2551,    82,  2551,
     170,    33,  1214,  -807,  -807,  1416,  2551,  2551,   108,  -807,
    -807,  -807,  -807,  2551,     5,  -807,   287,   300,   314,  -807,
    -807,  -807,  2164,   306,  -807,  -807,  -807,  2164,  2164,  2164,
    -807,  -807,  -807,   123,   304,  1603,  -807,  -807,   298,   299,
     301,   151,   126,  -807,  -807,     6,   303,   305,  2551,  -807,
    -807,   307,   308,   311,   331,   332,   333,   334,   335,   336,
     338,   340,   343,   344,   345,   346,   347,   348,  -807,  -807,
     349,   197,   -40,    11,   318,   320,   353,   365,   366,   367,
     368,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
     201,  -807,  -807,    67,    71,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,   203,    25,  -807,  -807,    -9,    72,
     262,   232,   265,    -4,  -807,  -807,  -807,  -807,  -807,   -12,
     315,    -5,    -3,    -2,     4,   374,  -807,  -807,  -807,   260,
     339,  -807,  -807,  -807,  2164,  -807,  -807,   370,  -807,  -807,
    -807,  -807,  -807,  2164,   354,   355,  -807,  -807,  -807,     1,
    -807,    87,  -807,  -807,  -807,  -807,  -807,  2551,  2364,  -807,
    -807,   395,  -807,  -807,  -807,  2164,  -807,  -807,  -807,  2164,
     380,  -807,  -807,  -807,   341,  -807,  -807,  -807,   256,  2551,
    2551,  -807,  -807,  2164,  -807,  -807,  -807,   377,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  2551,  2551,  -807,  -807,
    -807,  -807,   400,  -807,  -807,   266,  -807,  2551,   407,  -807,
    -807,  -807,    40,   409,  -807,   270,   272,   273,   133,   414,
    -807,  -807,   276,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,   415,  -807,  2551,   416,  -807,
    2551,   417,  -807,  -807,  -807,  2551,  -807,  -807,  -807,  2551,
     412,  -807,  -807,   392,    43,  1056,  -807,   885,   885,   398,
     401,  2164,  -807,  -807,   357,   359,   360,   361,  -807,   402,
     399,   403,   404,   405,   406,   105,   408,  2164,  2164,  2164,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
     410,  -807,  -807,  2551,  2551,  -807,  2551,  2551,  2551,  2551,
    2551,  2551,  2551,  2551,  2551,  2551,  2551,  2551,  2551,  2551,
    2551,  2551,  2551,  2738,   411,   229,  -807,  -807,   413,  -807,
    -807,   418,   420,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,   425,  -807,   426,  -807,
    -807,  -807,  -807,  -807,  -807,  2738,  2738,  2738,  2738,  2738,
    2738,  2738,  2738,  2738,  2738,  2738,  2738,  2738,  2925,  -807,
    -807,  -807,  2164,   422,  -807,  -807,  -807,   389,   315,   424,
     315,   427,   315,   437,   315,   438,   315,  -807,  2551,   430,
    -807,  -807,   244,   246,    55,    79,  -807,  -807,  -807,   432,
     315,   431,  -807,  -807,   250,   252,   128,   205,  -807,  -807,
     433,  -807,  -807,  2164,  -807,  -807,  2164,  2164,  -807,  -807,
    -807,   429,   236,  -807,   442,  2551,  -807,  -807,  -807,  -807,
    2164,  -807,  2551,   443,   461,  -807,  -807,  2164,   419,   462,
    2551,   371,   467,  2551,  -807,  -807,  -807,  -807,  -807,  -807,
     163,  -807,  -807,   441,   456,    85,  -807,   337,  -807,  -133,
     471,    43,  -133,   261,   264,   -33,  -807,  2551,  -807,  2551,
    -807,   885,  -807,  2551,   445,  2551,  2551,   447,    14,  -807,
    1056,  -807,  -807,   279,   281,  -807,  -807,  2551,   315,  2551,
     315,  2551,   274,   278,   282,   284,   285,   454,   459,   460,
    -807,   463,   465,   469,   473,   475,   476,  2551,   489,   495,
     499,   505,   479,   481,   482,   483,   513,   486,   487,   488,
     490,   491,   517,   521,   498,   502,   503,    26,   324,   504,
    2551,  2551,  2551,   500,  2551,  2551,   262,   262,   280,   280,
     280,   280,   280,   280,   280,   280,   232,   265,   265,  -807,
     511,   512,  2164,    59,  -807,   315,  -807,   315,  -807,   315,
    -807,   315,   139,  -807,  2551,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  2551,  -807,   315,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,   315,  -807,  -807,  -807,  -807,  -807,
    -807,   342,   351,   352,   356,   529,  2551,   536,   508,   509,
     396,  2551,  2551,   538,   545,  -807,   -44,   492,   362,  2551,
     546,  -807,  -807,  -807,   520,   358,   525,  -807,  2551,   363,
    2551,  -807,  -133,   548,  -807,  2551,  2551,   393,   394,  -807,
    -807,  -807,  -807,  -807,  -807,  2551,   556,   428,   558,   532,
    2551,  -807,  -807,  -807,  -807,  -807,  -807,  -807,   566,  -807,
    -807,  -807,  -807,  -807,   369,   372,   373,  -807,  -807,  -807,
    -807,  -807,  -807,   540,  2551,  2551,  2551,  2551,  -807,  -807,
    -807,  -807,  2551,  -807,  -807,  -807,  -807,  -807,  2551,  2551,
    -807,  -807,  -807,  2925,   543,  -807,   544,   575,   576,  2551,
     436,   550,   381,   382,  -807,  -807,  -807,  -807,  -807,  -807,
     557,  -807,   560,  -807,   383,   122,  -807,   584,  -807,   586,
     587,  -807,   588,  -807,   589,  -807,   585,  2164,   590,  2551,
    2551,   315,  -807,   564,   565,  2551,   315,  -807,  -807,  2551,
    -807,    76,  2551,   358,   594,   567,   358,   455,   221,   457,
     458,  -807,  -133,  -807,  -807,  -807,  -807,   573,  2551,  -807,
    2551,   597,   577,  2551,  -807,  -807,  -807,  -807,   579,   580,
      86,   167,   581,   582,   591,   592,  -807,  -807,  2551,  2551,
     593,  -807,  -807,  -807,  -807,   423,   439,  -807,   595,  -807,
     596,  -807,  2551,   315,   604,   612,   613,  2551,  -807,  -807,
    2551,  -807,  -807,  -807,   608,   609,   598,   599,   514,  2551,
     610,   559,   600,   358,  -807,   602,  -807,   363,   625,    43,
    -807,  -807,  -807,   626,  -807,  -807,  2551,   627,   603,  -807,
    -807,  2551,  -807,  2551,  -807,  -807,  -807,  -807,  -807,   615,
     616,  -807,  -807,  -807,   440,   446,   617,   619,   342,   351,
     352,  -807,  -807,  2551,  2551,  -807,  -807,  2551,   620,  2551,
    2551,  -807,  -807,  -807,  -807,   363,   636,  2551,  -807,  2551,
    -807,   621,   622,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,   631,  -807,  -807,  -807,   363,
    -807,  -807,  -807,  -807,  2551,  -807,  -807
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     485,     0,   473,     1,   472,     0,     0,     0,   456,     0,
       0,   420,     0,     0,   447,     0,     0,     0,   266,     0,
     405,   409,   406,     0,     0,     0,     0,     0,     0,   448,
     403,     0,     0,     0,   398,   446,     0,     0,     0,   453,
     455,   401,   404,   411,   408,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   394,   395,     0,     0,     0,     0,   385,
     386,   387,   388,   389,   469,   477,   474,   481,   483,   486,
     396,   397,     0,     0,   167,   168,   367,     0,     0,     0,
     181,   182,   369,     0,     0,     0,    79,    80,     0,     0,
       0,     0,     0,   121,   122,     0,     0,     0,     0,   112,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,    44,    49,    50,    51,    52,
      53,    54,    57,    58,     0,    63,    67,    65,     0,     2,
      12,    15,    17,     0,    76,    20,   192,   193,   370,     0,
       0,     0,     0,     0,     0,     0,   161,   162,   366,     0,
       0,   224,   225,   371,     0,   227,   228,   229,   233,   234,
     372,   256,   257,     0,     0,     0,   264,   265,   377,     0,
     449,     0,   276,   380,   272,   273,   450,     0,     0,   239,
     240,     0,   243,   244,   374,     0,   247,   248,   375,     0,
     250,   254,   255,   376,     0,   438,   444,   445,   426,     0,
       0,   471,   399,     0,   237,   238,   373,     0,   279,   280,
     378,   274,   275,   451,   454,   413,     0,     0,   412,   415,
     416,   410,     0,   298,   299,     0,   452,     0,     0,   381,
     281,   379,   314,   320,   461,   430,   421,   431,   330,   336,
     424,   425,   340,   382,   348,   347,   462,   439,   440,   441,
     352,   350,   349,   351,   353,     0,   442,     0,     0,   383,
       0,     0,   384,   392,   393,     0,   390,   479,   443,     0,
     467,   432,   429,     0,     0,   473,   475,   473,   473,     0,
       0,     0,   178,   175,     0,     0,     0,     0,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    24,    25,    27,    29,    30,    26,    31,   101,    23,
       0,   115,   116,     0,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,   120,     0,   118,
     119,     0,     0,   133,   127,   128,   129,   130,    55,    42,
      45,    46,    47,    48,    43,    56,    64,   108,     0,   183,
     189,   184,   185,   190,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   186,
     187,   188,     0,     0,   173,   174,   368,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
     214,   215,     0,     0,     0,     0,   211,   210,   136,     0,
       0,     0,   199,   200,     0,     0,     0,     0,   196,   195,
       0,   231,   226,     0,   261,   258,     0,     0,   291,   295,
     293,     0,     0,   407,     0,     0,   246,   245,   252,   249,
       0,   400,     0,     0,     0,   236,   235,     0,     0,   414,
       0,     0,     0,     0,   312,   304,   306,   311,   308,   313,
       0,   310,   318,     0,     0,     0,   434,     0,   436,     0,
     331,     0,     0,   345,   343,     0,   360,   361,   363,   364,
     391,   473,   463,     0,     0,     0,     0,     0,   469,   478,
     473,   482,   484,     0,     0,   165,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,     5,     7,
       8,     9,    10,     6,     3,     4,    16,    18,    19,    21,
       0,     0,     0,     0,   143,     0,   155,     0,   147,     0,
     151,     0,   139,   212,     0,   219,   218,   223,   222,   217,
     221,   216,   220,     0,   197,     0,   204,   203,   208,   207,
     202,   206,   201,   205,     0,   232,   230,   262,   259,   263,
     260,     0,     0,     0,     0,   267,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   402,     0,     0,     0,     0,
     300,   305,   307,   309,     0,     0,     0,   321,     0,     0,
       0,   333,     0,   332,   337,     0,     0,   357,   355,   354,
     359,   362,   365,   480,   464,     0,   338,     0,   322,     0,
       0,   476,   166,   164,   180,   177,   179,   176,     0,    75,
      68,    70,    74,    72,     0,     0,     0,    78,    77,    82,
      81,    84,    83,     0,     0,     0,     0,     0,    91,    92,
      93,   100,     0,    94,    95,    96,    97,    98,     0,     0,
     110,   111,   102,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     0,     0,   171,   169,   140,   153,   145,   148,
     142,   154,   146,   150,     0,     0,   209,     0,   194,     0,
     282,   292,   285,   296,   288,   294,   268,     0,     0,     0,
       0,     0,   427,     0,     0,     0,     0,   417,   418,     0,
     297,     0,     0,     0,   302,     0,     0,     0,   324,     0,
       0,   334,     0,   346,   344,   358,   356,     0,     0,   433,
       0,     0,     0,     0,    69,    71,    73,   124,     0,     0,
       0,     0,     0,     0,     0,     0,   107,   125,     0,     0,
       0,   109,    60,   172,   170,     0,     0,   156,   141,   152,
     144,   149,     0,     0,     0,     0,     0,     0,   270,   269,
       0,   242,   253,   251,     0,     0,     0,     0,   419,     0,
       0,     0,     0,     0,   315,     0,   435,     0,   325,     0,
     423,   437,   335,     0,   339,   323,     0,     0,     0,    85,
      86,     0,    87,     0,    89,    99,   105,   104,    22,     0,
       0,    62,   158,   160,     0,     0,     0,     0,     0,     0,
       0,   271,   241,     0,     0,   278,   277,     0,     0,     0,
       0,   319,   303,   317,   327,     0,   326,     0,   466,     0,
     131,     0,     0,   132,   126,   157,   159,   213,   198,   284,
     287,   290,   457,   458,   428,     0,   459,   301,   328,     0,
     468,   470,    88,    90,     0,   329,   460
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -807,   -10,  -134,   -85,   230,  -315,    69,  -807,  -807,  -807,
    -414,  -807,  -807,  -807,   472,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,   494,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -240,  -807,  -230,  -807,  -229,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -722,  -313,  -807,  -807,  -807,  -807,   158,  -580,
    -806,   -54,  -576,  -353,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,  -807,
    -807,  -309,  -807,  -807,  -807,  -303,  -807,  -807,  -807
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   688,   169,   170,   171,   172,   173,   347,   348,   174,
     175,   398,   583,   584,   449,   186,   187,   188,    84,    85,
      86,   424,   425,   426,    90,    91,    92,   404,   176,   177,
     178,   191,   192,   193,   198,   199,   200,   244,   245,   246,
     222,   223,   224,   226,   227,   228,   231,   232,   233,   206,
     207,   208,   212,   216,   253,   213,   248,   249,   250,   271,
     761,   834,   763,   835,   765,   836,   210,   641,   643,   642,
     266,   269,   785,   502,   273,   503,   504,   664,   274,   689,
     789,   280,   687,   283,   676,   675,   286,   295,   680,   296,
     299,   302,    76,   217,   507,   525,   668,   670,   313,   524,
     314,    77,   530,    78,   315,    79,   521,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     168,   527,   281,   189,   599,   741,   529,   209,   740,   307,
      82,   308,   422,   221,   531,   532,   234,   235,   309,   428,
     308,   430,   432,   241,   242,   310,   350,   309,   434,   254,
     257,   378,     3,   733,   310,   261,    80,   265,   102,  -465,
     270,   229,   180,   237,   102,   396,   376,   282,  -465,   287,
     181,   904,   298,   677,   468,   301,   303,   304,   577,   -59,
    -316,   852,    81,   306,   855,   494,   179,   182,   494,   211,
     399,   400,   319,   278,   279,   399,   419,   322,   324,   326,
     405,   406,   190,   849,   407,   336,   408,   409,   410,   411,
     412,   746,   787,   871,   790,   183,   184,   238,   355,   928,
     619,   597,   598,   469,   230,   797,   258,   471,   747,   620,
     802,   850,   260,   225,   495,   496,   497,   495,   496,   497,
     377,   872,   194,   935,   621,   498,   236,   678,   498,   472,
     290,   902,   679,   622,   195,   196,   748,   749,   291,   243,
     509,   401,   402,   403,   351,   470,   401,   402,   420,   379,
     239,   320,   311,   510,   828,   418,   323,   325,   327,   820,
      87,   311,   352,   499,   777,    88,   499,   380,   754,   413,
     259,   829,   397,   630,   873,   500,   340,   414,   500,   547,
     548,   511,   631,   501,   461,   197,   501,   755,   240,   214,
     549,   215,    83,   464,   423,   292,   293,   294,   673,   830,
     831,   429,   874,   431,   433,    89,   247,   473,   474,   251,
     435,   252,   288,   289,   312,   476,   256,   374,   683,   478,
     865,   691,   864,   312,   185,   341,   342,   343,   857,   483,
     484,   375,   255,   485,   344,   345,   346,   661,   662,   284,
     285,   858,   201,   202,   203,   204,   488,   489,   663,   427,
     632,   416,   389,   417,   205,   390,   391,   492,   262,   633,
     393,  -342,   392,   462,  -341,  -342,   394,  -342,  -341,   859,
    -341,   267,   465,   588,   589,   590,   591,   592,   593,   594,
     595,   513,   305,   514,   437,   438,   268,   516,   405,   406,
     518,   272,   439,   316,   477,   520,   440,   441,   479,   522,
     615,   616,   617,   618,   317,   442,   626,   627,   628,   629,
     275,   535,   486,   276,   443,   277,   444,   445,   318,   815,
     586,   587,   793,   794,   329,   446,   447,   551,   553,   555,
     321,   328,   337,   338,   349,   339,   448,   353,   381,   354,
     382,   356,   357,   558,   559,   358,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   437,   450,   359,   360,   361,   362,   363,
     364,   451,   365,   383,   366,   452,   453,   367,   368,   369,
     370,   371,   372,   373,   454,   384,   385,   386,   387,   388,
     536,   395,   415,   455,   418,   456,   457,   102,   436,   463,
     466,   467,   475,   482,   458,   459,   552,   554,   556,   480,
     481,   487,   600,   490,   493,   448,   505,   506,   491,  -422,
     508,   512,   515,   517,   519,   523,   526,   533,   613,   537,
     534,   538,   539,   540,   542,   579,   541,   603,   543,   544,
     545,   546,   645,   550,   557,   578,   602,   580,   605,   646,
     651,   607,   581,   635,   582,   671,   637,   639,   674,   -61,
     585,   609,   611,   614,   625,   647,   623,   634,   652,   656,
     648,   644,   650,   658,   659,   665,   666,   653,   672,   685,
     657,   690,   699,   660,   669,   692,   700,   693,   655,   704,
     701,   601,   702,   703,   705,   706,   714,   604,   707,   606,
     708,   608,   715,   610,   709,   612,   716,   681,   710,   682,
     711,   712,   717,   684,   718,   686,   719,   720,   721,   624,
     722,   723,   724,   725,   728,   726,   727,   694,   729,   696,
     734,   698,   636,   730,   739,   638,   640,   731,   732,   735,
     742,   743,   767,   769,   772,   775,   906,   713,   760,   649,
     770,   771,   776,   782,   783,   792,   654,   762,   764,   786,
     795,   796,   766,   798,   779,   800,   784,   801,   780,   788,
     736,   737,   738,   803,   686,   807,   799,   804,   816,   817,
     805,   806,   818,   819,   821,   822,   825,   823,   824,   826,
     827,   832,   744,   833,  -283,  -286,  -289,   840,   837,   844,
     845,   853,   854,   856,   756,   860,   861,   695,   863,   697,
     866,   888,   867,   757,   869,   870,   875,   876,   791,   889,
     890,   893,   894,   899,   884,   885,   877,   878,   881,   897,
     882,   900,   905,   895,   896,   901,   768,   903,   910,   907,
     909,   773,   774,   929,   934,   596,   883,   915,   919,   781,
     913,   914,   917,   916,   918,   925,   932,   933,   686,   920,
     686,   921,   460,   667,     0,   282,   282,   421,     0,     0,
       0,   745,     0,     0,   750,     0,   751,     0,   752,     0,
     753,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   758,     0,     0,     0,     0,     0,
       0,     0,     0,   759,   808,   809,   810,   811,     0,     0,
       0,     0,   812,     0,     0,     0,     0,     0,   813,   814,
       0,     0,     0,     0,     0,   778,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   862,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   838,     0,   841,
     842,     0,     0,     0,     0,   846,     0,     0,     0,   848,
       0,     0,   851,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   686,     0,
       0,     0,     0,   868,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   879,   880,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   886,     0,     0,     0,     0,   891,     0,     0,
     892,     0,     0,     0,     0,     0,   839,     0,     0,   898,
     843,     0,     0,     0,     0,   847,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   908,     0,     0,     0,
       0,   911,     0,   912,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   922,   923,     0,     0,   924,     4,   926,
     927,     0,     0,     0,     0,     5,     6,   930,     0,   931,
       0,     0,   887,     0,     0,     0,     0,     7,     8,     0,
       9,     0,    10,    11,     0,    12,    13,     0,     0,     0,
       0,     0,     0,    14,   936,    15,    16,    17,     0,     0,
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
      53,    54,     0,     0,    55,     0,     0,     0,    56,     0,
      57,     0,     0,     0,    58,    59,    60,     0,     0,     0,
       0,    61,     0,    62,    63,    64,    65,    66,    67,     4,
      68,    69,    70,    71,    72,    73,     5,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     9,     0,    10,    11,     0,    12,    13,     0,     0,
       0,    74,     0,    75,    14,     0,    15,    16,    17,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,    28,    29,     0,    30,     0,     0,
      31,    32,    33,     0,    34,    35,    36,    37,    38,    39,
      40,     0,    41,     0,     0,     0,    42,    43,    44,    45,
      46,     0,    47,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,    51,     0,
      52,    53,    54,     0,     0,    55,     0,     0,     0,    56,
       0,    57,     0,     0,     0,    58,    59,    60,     0,     0,
       0,   297,    61,    93,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,     0,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,    96,    97,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,     0,     0,   100,     0,     0,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,     0,
     105,     0,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,     0,
     132,     0,     0,     0,   133,     0,     0,     0,     0,     0,
       0,     0,   134,     0,     0,   135,     0,     0,   136,     0,
     137,   138,   139,   140,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   300,     0,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,     0,     0,   100,     0,     0,   101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,     0,   105,     0,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,     0,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,     0,   132,     0,     0,     0,   133,     0,     0,     0,
       0,     0,     0,     0,   134,     0,     0,   135,     0,     0,
     136,     0,   137,   138,   139,   140,     0,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    93,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,     0,     0,    94,   330,     0,
       0,     0,     0,     0,     0,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,     0,     0,   100,     0,     0,   101,   331,   332,   333,
       0,     0,     0,     0,     0,     0,   103,   104,   334,   105,
       0,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,   109,   110,     0,     0,     0,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,     0,     0,     0,   123,   124,   125,   335,   126,
     127,   128,     0,   129,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,     0,   132,
       0,     0,     0,   133,     0,     0,     0,     0,     0,     0,
       0,   134,     0,     0,   135,     0,     0,   136,     0,   137,
     138,   139,   140,     0,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    93,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,     0,     0,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,     0,   219,   220,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,     0,     0,
     100,     0,     0,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,     0,   105,     0,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,   109,   110,
       0,     0,     0,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
       0,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,     0,   132,     0,     0,     0,
     133,     0,     0,     0,     0,     0,     0,     0,   134,     0,
       0,   135,     0,     0,   136,     0,   137,   138,   139,   140,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    93,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,     0,
       0,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,   263,
     264,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,   100,     0,     0,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,   104,     0,   105,     0,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   109,   110,     0,     0,     0,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     0,     0,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,     0,   132,     0,     0,     0,   133,     0,     0,
       0,     0,     0,     0,     0,   134,     0,     0,   135,     0,
       0,   136,     0,   137,   138,   139,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    93,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     0,     0,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,     0,     0,   100,     0,     0,   101,     0,     0,
       0,     0,     0,     0,     0,     0,   102,   103,   104,     0,
     105,     0,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,     0,
     132,     0,     0,     0,   133,     0,     0,     0,     0,     0,
       0,     0,   134,     0,     0,   135,     0,     0,   136,     0,
     137,   138,   139,   140,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   329,     0,     0,     0,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,     0,     0,   100,     0,     0,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,     0,
     105,     0,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,     0,
     132,     0,     0,     0,   133,     0,     0,     0,     0,     0,
       0,     0,   134,     0,     0,   135,     0,     0,   136,     0,
     137,   138,   139,   140,     0,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      93,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,     0,     0,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,     0,
       0,   100,     0,     0,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,   104,     0,   105,     0,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,     0,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,     0,   132,     0,     0,
       0,   133,     0,     0,     0,     0,     0,     0,     0,   134,
       0,     0,   135,     0,     0,   136,     0,   137,   138,   139,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,    93,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,     0,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,     0,     0,   100,     0,
       0,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,     0,   105,     0,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   110,     0,     0,
       0,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,     0,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,   130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,     0,   132,     0,     0,     0,   133,     0,
       0,     0,     0,     0,     0,     0,   134,     0,     0,   135,
       0,     0,   136,     0,   137,   138,   139,   140,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    93,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,     0,     0,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,     0,     0,   100,     0,     0,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,   104,
       0,   105,     0,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,   110,     0,     0,     0,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,     0,     0,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
       0,   132,     0,     0,     0,   133,     0,     0,     0,     0,
       0,     0,     0,   134,     0,     0,   135,     0,     0,   136,
       0,   137,   138,   139,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167
};

static const yytype_int16 yycheck[] =
{
      10,   314,    56,    13,   418,   585,   315,    17,   584,     4,
      24,     6,    24,    23,   317,   318,    26,    27,    13,    24,
       6,    24,    24,    33,    34,    20,    20,    13,    24,    39,
      68,    20,     0,     7,    20,    45,   206,    47,    82,    34,
      50,    24,    24,    90,    82,    20,    86,    57,    34,    59,
      32,   857,    62,    86,    53,    65,    66,    67,   373,    34,
      20,   783,   206,    73,   786,    25,    22,    49,    25,   206,
      79,    80,    82,   206,   207,    79,    80,    87,    88,    89,
       8,     9,    13,     7,    12,    95,    14,    15,    16,    17,
      18,    32,   668,     7,   670,    77,    78,   144,   108,   905,
      45,   416,   417,   102,    87,   685,   144,    20,    49,    54,
     690,    35,    43,    24,    74,    75,    76,    74,    75,    76,
     160,    35,    24,   929,    45,    85,    90,   160,    85,    42,
      97,   853,   165,    54,    36,    37,    77,    78,   105,    24,
       7,   150,   151,   152,   138,   144,   150,   151,   152,   138,
      34,    82,   147,    20,    32,   129,    87,    88,    89,   739,
      26,   147,   156,   123,   208,    31,   123,   156,    29,    97,
     208,    49,   147,    45,     7,   135,    25,   105,   135,    74,
      75,    48,    54,   143,   194,    87,   143,    48,    34,   206,
      85,   208,   206,   203,   206,   162,   163,   164,   511,    77,
      78,   206,    35,   206,   206,    71,    24,   217,   218,   206,
     206,   208,    42,    43,   209,   225,    68,    20,   521,   229,
     800,   530,   798,   209,   206,    74,    75,    76,     7,   239,
     240,    34,   144,   243,    83,    84,    85,    74,    75,   157,
     158,    20,    42,    43,    44,    45,   256,   257,    85,   180,
      45,    19,   185,    21,    54,   188,   189,   267,   206,    54,
     189,     0,   195,   194,     0,     4,   195,     6,     4,    48,
       6,    34,   203,   407,   408,   409,   410,   411,   412,   413,
     414,     5,   174,     7,    24,    25,   206,   297,     8,     9,
     300,   206,    32,     6,   225,   305,    36,    37,   229,   309,
      56,    57,    56,    57,     4,    45,    56,    57,    56,    57,
     206,   321,   243,   206,    54,   206,    56,    57,     4,   733,
     405,   406,   675,   676,    20,    65,    66,   337,   338,   339,
      24,   208,    34,    34,   208,    34,    76,    34,    20,    34,
      20,    34,    34,   353,   354,    34,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,    24,    25,    34,    34,    34,    34,    34,
      34,    32,    34,    20,    34,    36,    37,    34,    34,    34,
      34,    34,    34,    34,    45,    20,    20,    20,    20,   188,
     321,   188,   130,    54,   129,    56,    57,    82,    24,    29,
      46,    46,     7,   147,    65,    66,   337,   338,   339,    29,
      69,    34,   422,    13,     7,    76,     7,   147,   152,   147,
     147,     7,     7,     7,     7,    13,    34,    29,   438,    72,
      29,    72,    72,    72,    35,   206,    34,    48,    35,    35,
      35,    35,   206,    35,    34,    34,    24,    34,    24,     7,
       7,    24,    34,   463,    34,   509,   466,   467,   512,    34,
      34,    24,    24,    33,    33,   475,    34,    34,     7,     7,
     480,    42,   482,   102,     7,    34,    20,   487,     7,    34,
     490,    34,   208,   493,   147,   206,   208,   206,    69,    35,
     208,   422,   208,   208,    35,    35,     7,   428,    35,   430,
      35,   432,     7,   434,    35,   436,     7,   517,    35,   519,
      35,    35,     7,   523,    35,   525,    35,    35,    35,   450,
       7,    35,    35,    35,     7,    35,    35,   537,     7,   539,
     206,   541,   463,    35,    34,   466,   467,    35,    35,    35,
      29,    29,    13,     7,   148,     7,   859,   557,   206,   480,
      42,    42,     7,     7,    34,     7,   487,   206,   206,    34,
     167,   167,   206,     7,    72,     7,   208,    35,   206,   206,
     580,   581,   582,     7,   584,    35,   148,   208,    35,    35,
     208,   208,     7,     7,   148,    35,    29,   206,   206,    29,
     207,     7,   602,     7,     7,     7,     7,     7,    13,    35,
      35,     7,    35,   148,   614,   148,   148,   538,    35,   540,
      13,     7,    35,   623,    35,    35,    35,    35,   672,     7,
       7,    13,    13,    13,    29,    29,    35,    35,    35,   115,
     207,    72,     7,    35,    35,    35,   646,    35,    35,    13,
      13,   651,   652,     7,    13,   415,   207,   207,   888,   659,
      35,    35,    35,   207,    35,    35,    35,    35,   668,   889,
     670,   890,   190,   505,    -1,   675,   676,   173,    -1,    -1,
      -1,   602,    -1,    -1,   605,    -1,   607,    -1,   609,    -1,
     611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   625,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   634,   714,   715,   716,   717,    -1,    -1,
      -1,    -1,   722,    -1,    -1,    -1,    -1,    -1,   728,   729,
      -1,    -1,    -1,    -1,    -1,   656,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   792,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   767,    -1,   769,
     770,    -1,    -1,    -1,    -1,   775,    -1,    -1,    -1,   779,
      -1,    -1,   782,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   798,    -1,
      -1,    -1,    -1,   803,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   818,   819,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   832,    -1,    -1,    -1,    -1,   837,    -1,    -1,
     840,    -1,    -1,    -1,    -1,    -1,   767,    -1,    -1,   849,
     771,    -1,    -1,    -1,    -1,   776,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   866,    -1,    -1,    -1,
      -1,   871,    -1,   873,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   893,   894,    -1,    -1,   897,     3,   899,
     900,    -1,    -1,    -1,    -1,    10,    11,   907,    -1,   909,
      -1,    -1,   833,    -1,    -1,    -1,    -1,    22,    23,    -1,
      25,    -1,    27,    28,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,   934,    40,    41,    42,    -1,    -1,
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
     145,   146,    -1,    -1,   149,    -1,    -1,    -1,   153,    -1,
     155,    -1,    -1,    -1,   159,   160,   161,    -1,    -1,    -1,
      -1,   166,    -1,   168,   169,   170,   171,   172,   173,     3,
     175,   176,   177,   178,   179,   180,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      -1,    25,    -1,    27,    28,    -1,    30,    31,    -1,    -1,
      -1,   206,    -1,   208,    38,    -1,    40,    41,    42,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    88,    89,    -1,    91,    -1,    -1,
      94,    95,    96,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,    -1,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,    -1,
     144,   145,   146,    -1,    -1,   149,    -1,    -1,    -1,   153,
      -1,   155,    -1,    -1,    -1,   159,   160,   161,    -1,    -1,
      -1,     7,   166,     9,   168,   169,   170,   171,   172,   173,
      -1,   175,   176,   177,   178,   179,   180,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   206,    -1,    50,    51,    52,    -1,    -1,    -1,
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
     176,   177,   178,   179,    -1,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,     7,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     174,    -1,   176,   177,   178,   179,    -1,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,     9,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    70,    -1,    -1,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,   132,   133,   134,   135,   136,
     137,   138,    -1,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,
      -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   168,    -1,    -1,   171,    -1,    -1,   174,    -1,   176,
     177,   178,   179,    -1,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     9,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
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
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,
      -1,   171,    -1,    -1,   174,    -1,   176,   177,   178,   179,
      -1,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     9,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
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
      -1,   174,    -1,   176,   177,   178,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,     9,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,
     136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
     156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   168,    -1,    -1,   171,    -1,    -1,   174,    -1,
     176,   177,   178,   179,    -1,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    -1,
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
     176,   177,   178,   179,    -1,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
       9,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,    24,    -1,    -1,    -1,    -1,
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
     179,    -1,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,     9,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,   137,   138,    -1,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   154,    -1,   156,    -1,    -1,    -1,   160,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,   171,
      -1,    -1,   174,    -1,   176,   177,   178,   179,    -1,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     9,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,    24,
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
      -1,   136,   137,   138,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,
      -1,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   168,    -1,    -1,   171,    -1,    -1,   174,
      -1,   176,   177,   178,   179,    -1,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   317,   318,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    86,    88,    89,
      91,    94,    95,    96,    98,    99,   100,   101,   102,   103,
     104,   106,   110,   111,   112,   113,   114,   116,   117,   131,
     139,   142,   144,   145,   146,   149,   153,   155,   159,   160,
     161,   166,   168,   169,   170,   171,   172,   173,   175,   176,
     177,   178,   179,   180,   206,   208,   302,   311,   313,   315,
     206,   206,    24,   206,   228,   229,   230,    26,    31,    71,
     234,   235,   236,     9,    24,    34,    50,    51,    52,    67,
      70,    73,    82,    83,    84,    86,    94,    95,   107,   108,
     109,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   132,   133,   134,   136,   137,   138,   140,
     141,   154,   156,   160,   168,   171,   174,   176,   177,   178,
     179,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   211,   212,
     213,   214,   215,   216,   219,   220,   238,   239,   240,    22,
      24,    32,    49,    77,    78,   206,   225,   226,   227,   211,
     216,   241,   242,   243,    24,    36,    37,    87,   244,   245,
     246,    42,    43,    44,    45,    54,   259,   260,   261,   211,
     276,   206,   262,   265,   206,   208,   263,   303,    24,    36,
      37,   211,   250,   251,   252,    24,   253,   254,   255,    24,
      87,   256,   257,   258,   211,   211,    90,    90,   144,    34,
      34,   211,   211,    24,   247,   248,   249,    24,   266,   267,
     268,   206,   208,   264,   211,   144,    68,    68,   144,   208,
     216,   211,   206,    42,    43,   211,   280,    34,   206,   281,
     211,   269,   206,   284,   288,   206,   206,   206,   206,   207,
     291,   291,   211,   293,   157,   158,   296,   211,    42,    43,
      97,   105,   162,   163,   164,   297,   299,     7,   211,   300,
       7,   211,   301,   211,   211,   174,   211,     4,     6,    13,
      20,   147,   209,   308,   310,   314,     6,     4,     4,   211,
     216,    24,   211,   216,   211,   216,   211,   216,   208,    20,
      25,    74,    75,    76,    85,   135,   211,    34,    34,    34,
      25,    74,    75,    76,    83,    84,    85,   217,   218,   208,
      20,   138,   156,    34,    34,   211,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    20,    34,    86,   160,    20,   138,
     156,    20,    20,    20,    20,    20,    20,    20,   188,   185,
     188,   189,   195,   189,   195,   188,    20,   147,   221,    79,
      80,   150,   151,   152,   237,     8,     9,    12,    14,    15,
      16,    17,    18,    97,   105,   130,    19,    21,   129,    80,
     152,   237,    24,   206,   231,   232,   233,   216,    24,   206,
      24,   206,    24,   206,    24,   206,    24,    24,    25,    32,
      36,    37,    45,    54,    56,    57,    65,    66,    76,   224,
      25,    32,    36,    37,    45,    54,    56,    57,    65,    66,
     224,   211,   216,    29,   211,   216,    46,    46,    53,   102,
     144,    20,    42,   211,   211,     7,   211,   216,   211,   216,
      29,    69,   147,   211,   211,   211,   216,    34,   211,   211,
      13,   152,   211,     7,    25,    74,    75,    76,    85,   123,
     135,   143,   283,   285,   286,     7,   147,   304,   147,     7,
      20,    48,     7,     5,     7,     7,   211,     7,   211,     7,
     211,   316,   211,    13,   309,   305,    34,   283,   206,   311,
     312,   315,   315,    29,    29,   211,   216,    72,    72,    72,
      72,    34,    35,    35,    35,    35,    35,    74,    75,    85,
      35,   211,   216,   211,   216,   211,   216,    34,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   215,    34,   206,
      34,    34,    34,   222,   223,    34,   213,   213,   212,   212,
     212,   212,   212,   212,   212,   212,   214,   215,   215,   220,
     211,   216,    24,    48,   216,    24,   216,    24,   216,    24,
     216,    24,   216,   211,    33,    56,    57,    56,    57,    45,
      54,    45,    54,    34,   216,    33,    56,    57,    56,    57,
      45,    54,    45,    54,    34,   211,   216,   211,   216,   211,
     216,   277,   279,   278,    42,   206,     7,   211,   211,   216,
     211,     7,     7,   211,   216,    69,     7,   211,   102,     7,
     211,    74,    75,    85,   287,    34,    20,   288,   306,   147,
     307,   291,     7,   283,   291,   295,   294,    86,   160,   165,
     298,   211,   211,   315,   211,    34,   211,   292,   211,   289,
      34,   311,   206,   206,   211,   216,   211,   216,   211,   208,
     208,   208,   208,   208,    35,    35,    35,    35,    35,    35,
      35,    35,    35,   211,     7,     7,     7,     7,    35,    35,
      35,    35,     7,    35,    35,    35,    35,    35,     7,     7,
      35,    35,    35,     7,   206,    35,   211,   211,   211,    34,
     292,   289,    29,    29,   211,   216,    32,    49,    77,    78,
     216,   216,   216,   216,    29,    48,   211,   211,   216,   216,
     206,   270,   206,   272,   206,   274,   206,    13,   211,     7,
      42,    42,   148,   211,   211,     7,     7,   208,   216,    72,
     206,   211,     7,    34,   208,   282,    34,   292,   206,   290,
     292,   291,     7,   293,   293,   167,   167,   289,     7,   148,
       7,    35,   289,     7,   208,   208,   208,    35,   211,   211,
     211,   211,   211,   211,   211,   220,    35,    35,     7,     7,
     289,   148,    35,   206,   206,    29,    29,   207,    32,    49,
      77,    78,     7,     7,   271,   273,   275,    13,   211,   216,
       7,   211,   211,   216,    35,    35,   211,   216,   211,     7,
      35,   211,   282,     7,    35,   282,   148,     7,    20,    48,
     148,   148,   291,    35,   292,   289,    13,    35,   211,    35,
      35,     7,    35,     7,    35,    35,    35,    35,    35,   211,
     211,    35,   207,   207,    29,    29,   211,   216,     7,     7,
       7,   211,   211,    13,    13,    35,    35,   115,   211,    13,
      72,    35,   282,    35,   290,     7,   283,    13,   211,    13,
      35,   211,   211,    35,    35,   207,   207,    35,    35,   270,
     272,   274,   211,   211,   211,    35,   211,   211,   290,     7,
     211,   211,    35,    35,    13,   290,   211
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   210,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   212,   212,   212,   213,   213,   214,   214,   214,
     215,   215,   215,   216,   217,   217,   217,   217,   217,   217,
     217,   218,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   221,
     220,   222,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   223,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   224,   224,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   226,   226,   226,   226,
     226,   227,   227,   228,   228,   229,   229,   230,   230,   231,
     231,   232,   232,   233,   233,   234,   234,   234,   235,   235,
     235,   236,   236,   237,   237,   237,   238,   238,   238,   239,
     239,   239,   240,   240,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   243,   243,   244,   244,   244,   244,
     244,   245,   245,   246,   246,   247,   248,   249,   249,   250,
     250,   251,   251,   252,   252,   253,   254,   255,   255,   256,
     256,   256,   257,   257,   258,   258,   259,   259,   259,   259,
     259,   260,   260,   260,   261,   261,   262,   262,   262,   262,
     262,   262,   263,   263,   264,   264,   265,   266,   267,   268,
     268,   269,   270,   271,   270,   272,   273,   272,   274,   275,
     274,   277,   276,   278,   276,   279,   276,   280,   280,   280,
     281,   281,   282,   282,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   285,   284,   286,   284,   287,   284,
     288,   288,   289,   289,   290,   290,   290,   290,   290,   290,
     291,   291,   291,   291,   291,   291,   291,   291,   292,   292,
     293,   293,   293,   294,   293,   295,   293,   296,   296,   297,
     297,   297,   297,   297,   298,   298,   298,   298,   298,   299,
     300,   300,   300,   301,   301,   301,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   303,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   304,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   305,   302,   306,   302,   307,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   308,   302,   309,   302,   310,
     302,   302,   302,   302,   311,   312,   311,   314,   313,   316,
     315,   315,   315,   315,   315,   318,   317
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
       2,     7,     7,     2,     1,     1,     1,     1,     2,     3,
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
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       2,     3,     2,     2,     1,     1,     2,     2,     1,     2,
       3,     1,     4,     1,     1,     1,     0,     3,     1,     1,
       2,     1,     2,     2,     3,     2,     2,     5,     5,     6,
       1,     2,     0,     6,     2,     2,     2,     5,     8,     2,
       2,     2,     0,     5,     0,     6,     0,     6,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     2,
       2,     2,     2,     1,     2,     1,     1,     8,     8,     8,
      10,     2,     2,     3,     4,     0,     7,     0,     8,     0,
       8,     2,     1,     0,     1,     0,     4,     0,     3,     0,
       4,     1,     3,     1,     3,     0,     2
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
#line 2917 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 80 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2926 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 84 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2934 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 87 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2942 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 90 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2950 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 93 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2958 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 96 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2966 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 99 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2974 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 102 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2982 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 109 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2990 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 112 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2999 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 125 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3008 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 129 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3017 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 137 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 3026 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 141 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 3035 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 148 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3043 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 153 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3051 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 156 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3059 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 159 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3067 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 162 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3075 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 165 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3083 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 168 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3091 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 171 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3099 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 176 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3107 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 181 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3116 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 185 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3125 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 189 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3134 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 193 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3143 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 197 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3152 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 201 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3161 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 205 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3170 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 209 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3179 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 213 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3188 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 217 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3197 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 221 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3206 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 225 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3215 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 229 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3224 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 233 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3233 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 237 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3242 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 241 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3251 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 245 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3260 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 249 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3269 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 253 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3278 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 257 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3287 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 261 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3296 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 265 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3305 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 269 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3314 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 273 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3323 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 277 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3332 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 281 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3341 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 285 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3350 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 291 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3359 "src-generated/ugbc.tab.c"
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
#line 3371 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 302 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3380 "src-generated/ugbc.tab.c"
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
#line 3392 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 313 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3400 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 316 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3408 "src-generated/ugbc.tab.c"
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
#line 3422 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 328 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3431 "src-generated/ugbc.tab.c"
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
#line 3443 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 339 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3452 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 343 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3461 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 347 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3470 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 351 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3479 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 355 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3488 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 359 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3497 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 363 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3506 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 367 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3515 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 371 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3523 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 374 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3531 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 377 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3539 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 380 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3547 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 383 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3555 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 386 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3563 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 389 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3571 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 392 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3579 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 395 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3587 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 398 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3595 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 401 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3603 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 404 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3611 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 407 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3619 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 410 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3627 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 413 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3635 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 416 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3643 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 419 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3651 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 422 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3659 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 425 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3667 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 428 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3675 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 431 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3683 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 434 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3691 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 437 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3699 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 440 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3707 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 443 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3715 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 446 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3723 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 449 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3731 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 452 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3739 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 455 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3747 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 458 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3755 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 461 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3763 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 464 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3771 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 467 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3779 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 469 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3788 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 473 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3796 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 476 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3804 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 479 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3813 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 483 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3822 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 487 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3831 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: PEN COLORS  */
#line 491 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3840 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: PEN DEFAULT  */
#line 495 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3849 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: DEFAULT PEN  */
#line 499 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3858 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: PAPER COLORS  */
#line 503 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3867 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: PAPER DEFAULT  */
#line 507 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3876 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: DEFAULT PAPER  */
#line 511 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3885 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: WIDTH  */
#line 515 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3893 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: HEIGHT  */
#line 518 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3901 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: TIMER  */
#line 521 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3909 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PEN DOLLAR OP expr CP  */
#line 524 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 3917 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER DOLLAR OP expr CP  */
#line 527 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3925 "src-generated/ugbc.tab.c"
    break;

  case 126: /* exponential: CMOVE DOLLAR OP expr COMMA expr CP  */
#line 530 "src/ugbc.y"
                                         {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3933 "src-generated/ugbc.tab.c"
    break;

  case 127: /* exponential: CUP DOLLAR  */
#line 533 "src/ugbc.y"
                 {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 3941 "src-generated/ugbc.tab.c"
    break;

  case 128: /* exponential: CDOWN DOLLAR  */
#line 536 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 3949 "src-generated/ugbc.tab.c"
    break;

  case 129: /* exponential: CLEFT DOLLAR  */
#line 539 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 3957 "src-generated/ugbc.tab.c"
    break;

  case 130: /* exponential: CRIGHT DOLLAR  */
#line 542 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 3965 "src-generated/ugbc.tab.c"
    break;

  case 131: /* exponential: AT DOLLAR OP expr COMMA expr CP  */
#line 545 "src/ugbc.y"
                                      {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3973 "src-generated/ugbc.tab.c"
    break;

  case 132: /* exponential: LOCATE DOLLAR OP expr COMMA expr CP  */
#line 548 "src/ugbc.y"
                                          {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3981 "src-generated/ugbc.tab.c"
    break;

  case 133: /* exponential: TAB DOLLAR  */
#line 551 "src/ugbc.y"
                 {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 3989 "src-generated/ugbc.tab.c"
    break;

  case 134: /* exponential: XCURS  */
#line 554 "src/ugbc.y"
            {
        (yyval.string) = text_get_xcurs( _environment )->name;
    }
#line 3997 "src-generated/ugbc.tab.c"
    break;

  case 135: /* exponential: YCURS  */
#line 557 "src/ugbc.y"
            {
        (yyval.string) = text_get_ycurs( _environment )->name;
    }
#line 4005 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_simple: AT direct_integer  */
#line 565 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4013 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_simple: Identifier AT direct_integer  */
#line 568 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4021 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 571 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4029 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 574 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4037 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 577 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4045 "src-generated/ugbc.tab.c"
    break;

  case 143: /* bank_definition_simple: DATA AT direct_integer  */
#line 580 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4053 "src-generated/ugbc.tab.c"
    break;

  case 144: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 584 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4061 "src-generated/ugbc.tab.c"
    break;

  case 145: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 587 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4069 "src-generated/ugbc.tab.c"
    break;

  case 146: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 590 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4077 "src-generated/ugbc.tab.c"
    break;

  case 147: /* bank_definition_simple: CODE AT direct_integer  */
#line 593 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4085 "src-generated/ugbc.tab.c"
    break;

  case 148: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 597 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4093 "src-generated/ugbc.tab.c"
    break;

  case 149: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 600 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4101 "src-generated/ugbc.tab.c"
    break;

  case 150: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 603 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4109 "src-generated/ugbc.tab.c"
    break;

  case 151: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 606 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4117 "src-generated/ugbc.tab.c"
    break;

  case 152: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 610 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4125 "src-generated/ugbc.tab.c"
    break;

  case 153: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 613 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4133 "src-generated/ugbc.tab.c"
    break;

  case 154: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 616 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4141 "src-generated/ugbc.tab.c"
    break;

  case 155: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 619 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4149 "src-generated/ugbc.tab.c"
    break;

  case 156: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 625 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4157 "src-generated/ugbc.tab.c"
    break;

  case 157: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 628 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4165 "src-generated/ugbc.tab.c"
    break;

  case 158: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 631 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4173 "src-generated/ugbc.tab.c"
    break;

  case 159: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 634 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4181 "src-generated/ugbc.tab.c"
    break;

  case 160: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 637 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4189 "src-generated/ugbc.tab.c"
    break;

  case 163: /* raster_definition_simple: Identifier AT direct_integer  */
#line 646 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 4197 "src-generated/ugbc.tab.c"
    break;

  case 164: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 649 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 4205 "src-generated/ugbc.tab.c"
    break;

  case 165: /* raster_definition_expression: Identifier AT expr  */
#line 654 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4213 "src-generated/ugbc.tab.c"
    break;

  case 166: /* raster_definition_expression: AT expr WITH Identifier  */
#line 657 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4221 "src-generated/ugbc.tab.c"
    break;

  case 169: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 666 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 4229 "src-generated/ugbc.tab.c"
    break;

  case 170: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 669 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 4237 "src-generated/ugbc.tab.c"
    break;

  case 171: /* next_raster_definition_expression: Identifier AT expr  */
#line 674 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 4245 "src-generated/ugbc.tab.c"
    break;

  case 172: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 677 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4253 "src-generated/ugbc.tab.c"
    break;

  case 175: /* color_definition_simple: BORDER direct_integer  */
#line 686 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 4261 "src-generated/ugbc.tab.c"
    break;

  case 176: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 689 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4269 "src-generated/ugbc.tab.c"
    break;

  case 177: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 692 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4277 "src-generated/ugbc.tab.c"
    break;

  case 178: /* color_definition_expression: BORDER expr  */
#line 697 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 4285 "src-generated/ugbc.tab.c"
    break;

  case 179: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 700 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4293 "src-generated/ugbc.tab.c"
    break;

  case 180: /* color_definition_expression: SPRITE expr TO expr  */
#line 703 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4301 "src-generated/ugbc.tab.c"
    break;

  case 186: /* wait_definition_simple: direct_integer CYCLES  */
#line 717 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4309 "src-generated/ugbc.tab.c"
    break;

  case 187: /* wait_definition_simple: direct_integer TICKS  */
#line 720 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4317 "src-generated/ugbc.tab.c"
    break;

  case 188: /* wait_definition_simple: direct_integer milliseconds  */
#line 723 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4325 "src-generated/ugbc.tab.c"
    break;

  case 189: /* wait_definition_expression: expr CYCLES  */
#line 728 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4333 "src-generated/ugbc.tab.c"
    break;

  case 190: /* wait_definition_expression: expr TICKS  */
#line 731 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4341 "src-generated/ugbc.tab.c"
    break;

  case 191: /* wait_definition_expression: expr milliseconds  */
#line 734 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4349 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 744 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4357 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 747 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4365 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 750 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4373 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 753 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4381 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 756 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4389 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_simple: direct_integer ENABLE  */
#line 759 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4397 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_simple: direct_integer DISABLE  */
#line 762 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4405 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 765 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4413 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 768 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4421 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 771 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4429 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 774 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4437 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 777 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4445 "src-generated/ugbc.tab.c"
    break;

  case 206: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 780 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4453 "src-generated/ugbc.tab.c"
    break;

  case 207: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 783 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4461 "src-generated/ugbc.tab.c"
    break;

  case 208: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 786 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4469 "src-generated/ugbc.tab.c"
    break;

  case 209: /* sprite_definition_expression: expr DATA FROM expr  */
#line 791 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4477 "src-generated/ugbc.tab.c"
    break;

  case 210: /* sprite_definition_expression: expr MULTICOLOR  */
#line 794 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4485 "src-generated/ugbc.tab.c"
    break;

  case 211: /* sprite_definition_expression: expr MONOCOLOR  */
#line 797 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4493 "src-generated/ugbc.tab.c"
    break;

  case 212: /* sprite_definition_expression: expr COLOR expr  */
#line 800 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4501 "src-generated/ugbc.tab.c"
    break;

  case 213: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 803 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4509 "src-generated/ugbc.tab.c"
    break;

  case 214: /* sprite_definition_expression: expr ENABLE  */
#line 806 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4517 "src-generated/ugbc.tab.c"
    break;

  case 215: /* sprite_definition_expression: expr DISABLE  */
#line 809 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4525 "src-generated/ugbc.tab.c"
    break;

  case 216: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 812 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4533 "src-generated/ugbc.tab.c"
    break;

  case 217: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 815 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4541 "src-generated/ugbc.tab.c"
    break;

  case 218: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 818 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4549 "src-generated/ugbc.tab.c"
    break;

  case 219: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 821 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4557 "src-generated/ugbc.tab.c"
    break;

  case 220: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 824 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4565 "src-generated/ugbc.tab.c"
    break;

  case 221: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 827 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4573 "src-generated/ugbc.tab.c"
    break;

  case 222: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 830 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4581 "src-generated/ugbc.tab.c"
    break;

  case 223: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 833 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4589 "src-generated/ugbc.tab.c"
    break;

  case 226: /* bitmap_definition_simple: AT direct_integer  */
#line 842 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4597 "src-generated/ugbc.tab.c"
    break;

  case 227: /* bitmap_definition_simple: ENABLE  */
#line 845 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4605 "src-generated/ugbc.tab.c"
    break;

  case 228: /* bitmap_definition_simple: DISABLE  */
#line 848 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4613 "src-generated/ugbc.tab.c"
    break;

  case 229: /* bitmap_definition_simple: CLEAR  */
#line 851 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4621 "src-generated/ugbc.tab.c"
    break;

  case 230: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 854 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4629 "src-generated/ugbc.tab.c"
    break;

  case 231: /* bitmap_definition_expression: AT expr  */
#line 860 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4637 "src-generated/ugbc.tab.c"
    break;

  case 232: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 863 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4645 "src-generated/ugbc.tab.c"
    break;

  case 235: /* textmap_definition_simple: AT direct_integer  */
#line 873 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4653 "src-generated/ugbc.tab.c"
    break;

  case 236: /* textmap_definition_expression: AT expr  */
#line 878 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4661 "src-generated/ugbc.tab.c"
    break;

  case 239: /* text_definition_simple: ENABLE  */
#line 887 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4669 "src-generated/ugbc.tab.c"
    break;

  case 240: /* text_definition_simple: DISABLE  */
#line 890 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4677 "src-generated/ugbc.tab.c"
    break;

  case 241: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 895 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4685 "src-generated/ugbc.tab.c"
    break;

  case 242: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 898 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4693 "src-generated/ugbc.tab.c"
    break;

  case 245: /* tiles_definition_simple: AT direct_integer  */
#line 907 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4701 "src-generated/ugbc.tab.c"
    break;

  case 246: /* tiles_definition_expression: AT expr  */
#line 912 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4709 "src-generated/ugbc.tab.c"
    break;

  case 249: /* colormap_definition_simple: AT direct_integer  */
#line 921 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4717 "src-generated/ugbc.tab.c"
    break;

  case 250: /* colormap_definition_simple: CLEAR  */
#line 924 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4725 "src-generated/ugbc.tab.c"
    break;

  case 251: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 927 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4733 "src-generated/ugbc.tab.c"
    break;

  case 252: /* colormap_definition_expression: AT expr  */
#line 932 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4741 "src-generated/ugbc.tab.c"
    break;

  case 253: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 935 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4749 "src-generated/ugbc.tab.c"
    break;

  case 256: /* screen_definition_simple: ON  */
#line 945 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4757 "src-generated/ugbc.tab.c"
    break;

  case 257: /* screen_definition_simple: OFF  */
#line 948 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4765 "src-generated/ugbc.tab.c"
    break;

  case 258: /* screen_definition_simple: ROWS direct_integer  */
#line 951 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4773 "src-generated/ugbc.tab.c"
    break;

  case 259: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 954 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4781 "src-generated/ugbc.tab.c"
    break;

  case 260: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 957 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4789 "src-generated/ugbc.tab.c"
    break;

  case 261: /* screen_definition_expression: ROWS expr  */
#line 962 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4797 "src-generated/ugbc.tab.c"
    break;

  case 262: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 965 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4805 "src-generated/ugbc.tab.c"
    break;

  case 263: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 968 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4813 "src-generated/ugbc.tab.c"
    break;

  case 267: /* var_definition_simple: Identifier ON Identifier  */
#line 977 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4821 "src-generated/ugbc.tab.c"
    break;

  case 268: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 980 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4829 "src-generated/ugbc.tab.c"
    break;

  case 269: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 983 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4837 "src-generated/ugbc.tab.c"
    break;

  case 270: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 986 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4847 "src-generated/ugbc.tab.c"
    break;

  case 271: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 991 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4857 "src-generated/ugbc.tab.c"
    break;

  case 272: /* goto_definition: Identifier  */
#line 998 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4865 "src-generated/ugbc.tab.c"
    break;

  case 273: /* goto_definition: Integer  */
#line 1001 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4873 "src-generated/ugbc.tab.c"
    break;

  case 274: /* gosub_definition: Identifier  */
#line 1007 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4881 "src-generated/ugbc.tab.c"
    break;

  case 275: /* gosub_definition: Integer  */
#line 1010 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4889 "src-generated/ugbc.tab.c"
    break;

  case 277: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 1019 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4897 "src-generated/ugbc.tab.c"
    break;

  case 278: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 1025 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4905 "src-generated/ugbc.tab.c"
    break;

  case 281: /* ink_definition: expr  */
#line 1034 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4913 "src-generated/ugbc.tab.c"
    break;

  case 282: /* on_goto_definition: Identifier  */
#line 1039 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4922 "src-generated/ugbc.tab.c"
    break;

  case 283: /* $@4: %empty  */
#line 1043 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4930 "src-generated/ugbc.tab.c"
    break;

  case 285: /* on_gosub_definition: Identifier  */
#line 1048 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4939 "src-generated/ugbc.tab.c"
    break;

  case 286: /* $@5: %empty  */
#line 1052 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4947 "src-generated/ugbc.tab.c"
    break;

  case 288: /* on_proc_definition: Identifier  */
#line 1057 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4956 "src-generated/ugbc.tab.c"
    break;

  case 289: /* $@6: %empty  */
#line 1061 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4964 "src-generated/ugbc.tab.c"
    break;

  case 291: /* $@7: %empty  */
#line 1066 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4972 "src-generated/ugbc.tab.c"
    break;

  case 293: /* $@8: %empty  */
#line 1069 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4980 "src-generated/ugbc.tab.c"
    break;

  case 295: /* $@9: %empty  */
#line 1072 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4988 "src-generated/ugbc.tab.c"
    break;

  case 297: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1077 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4996 "src-generated/ugbc.tab.c"
    break;

  case 298: /* every_definition: ON  */
#line 1080 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 5004 "src-generated/ugbc.tab.c"
    break;

  case 299: /* every_definition: OFF  */
#line 1083 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 5012 "src-generated/ugbc.tab.c"
    break;

  case 300: /* add_definition: Identifier COMMA expr  */
#line 1088 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 5020 "src-generated/ugbc.tab.c"
    break;

  case 301: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1091 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5028 "src-generated/ugbc.tab.c"
    break;

  case 302: /* dimensions: Integer  */
#line 1097 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5037 "src-generated/ugbc.tab.c"
    break;

  case 303: /* dimensions: Integer COMMA dimensions  */
#line 1101 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5046 "src-generated/ugbc.tab.c"
    break;

  case 304: /* datatype: BYTE  */
#line 1108 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 5054 "src-generated/ugbc.tab.c"
    break;

  case 305: /* datatype: SIGNED BYTE  */
#line 1111 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 5062 "src-generated/ugbc.tab.c"
    break;

  case 306: /* datatype: WORD  */
#line 1114 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 5070 "src-generated/ugbc.tab.c"
    break;

  case 307: /* datatype: SIGNED WORD  */
#line 1117 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 5078 "src-generated/ugbc.tab.c"
    break;

  case 308: /* datatype: DWORD  */
#line 1120 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 5086 "src-generated/ugbc.tab.c"
    break;

  case 309: /* datatype: SIGNED DWORD  */
#line 1123 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 5094 "src-generated/ugbc.tab.c"
    break;

  case 310: /* datatype: ADDRESS  */
#line 1126 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 5102 "src-generated/ugbc.tab.c"
    break;

  case 311: /* datatype: POSITION  */
#line 1129 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 5110 "src-generated/ugbc.tab.c"
    break;

  case 312: /* datatype: COLOR  */
#line 1132 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 5118 "src-generated/ugbc.tab.c"
    break;

  case 313: /* datatype: STRING  */
#line 1135 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 5126 "src-generated/ugbc.tab.c"
    break;

  case 314: /* $@10: %empty  */
#line 1140 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5135 "src-generated/ugbc.tab.c"
    break;

  case 315: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1143 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 5145 "src-generated/ugbc.tab.c"
    break;

  case 316: /* $@11: %empty  */
#line 1148 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5154 "src-generated/ugbc.tab.c"
    break;

  case 317: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1151 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 5164 "src-generated/ugbc.tab.c"
    break;

  case 318: /* $@12: %empty  */
#line 1156 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5173 "src-generated/ugbc.tab.c"
    break;

  case 319: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1159 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 5183 "src-generated/ugbc.tab.c"
    break;

  case 322: /* indexes: expr  */
#line 1172 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5192 "src-generated/ugbc.tab.c"
    break;

  case 323: /* indexes: expr COMMA indexes  */
#line 1176 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5201 "src-generated/ugbc.tab.c"
    break;

  case 324: /* parameters: Identifier  */
#line 1183 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5211 "src-generated/ugbc.tab.c"
    break;

  case 325: /* parameters: Identifier DOLLAR  */
#line 1188 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5221 "src-generated/ugbc.tab.c"
    break;

  case 326: /* parameters: Identifier AS datatype  */
#line 1193 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5231 "src-generated/ugbc.tab.c"
    break;

  case 327: /* parameters: Identifier COMMA parameters  */
#line 1198 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5241 "src-generated/ugbc.tab.c"
    break;

  case 328: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1203 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5251 "src-generated/ugbc.tab.c"
    break;

  case 329: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1208 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5261 "src-generated/ugbc.tab.c"
    break;

  case 330: /* parameters_expr: Identifier  */
#line 1216 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5271 "src-generated/ugbc.tab.c"
    break;

  case 331: /* parameters_expr: Identifier DOLLAR  */
#line 1221 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5281 "src-generated/ugbc.tab.c"
    break;

  case 332: /* parameters_expr: Identifier AS datatype  */
#line 1226 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5291 "src-generated/ugbc.tab.c"
    break;

  case 333: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1231 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5301 "src-generated/ugbc.tab.c"
    break;

  case 334: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1236 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5311 "src-generated/ugbc.tab.c"
    break;

  case 335: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1241 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5321 "src-generated/ugbc.tab.c"
    break;

  case 336: /* parameters_expr: String  */
#line 1246 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5330 "src-generated/ugbc.tab.c"
    break;

  case 337: /* parameters_expr: String COMMA parameters_expr  */
#line 1250 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5339 "src-generated/ugbc.tab.c"
    break;

  case 338: /* values: expr  */
#line 1257 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5348 "src-generated/ugbc.tab.c"
    break;

  case 339: /* values: expr COMMA values  */
#line 1261 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5357 "src-generated/ugbc.tab.c"
    break;

  case 340: /* print_definition: expr  */
#line 1268 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5365 "src-generated/ugbc.tab.c"
    break;

  case 341: /* print_definition: expr COMMA  */
#line 1271 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5374 "src-generated/ugbc.tab.c"
    break;

  case 342: /* print_definition: expr SEMICOLON  */
#line 1275 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5382 "src-generated/ugbc.tab.c"
    break;

  case 343: /* $@13: %empty  */
#line 1278 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5391 "src-generated/ugbc.tab.c"
    break;

  case 345: /* $@14: %empty  */
#line 1282 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5399 "src-generated/ugbc.tab.c"
    break;

  case 347: /* use_definition: ANSI  */
#line 1288 "src/ugbc.y"
         {
        use_ansi( _environment );
    }
#line 5407 "src-generated/ugbc.tab.c"
    break;

  case 348: /* use_definition: SPECIFIC  */
#line 1291 "src/ugbc.y"
             {
        use_specific( _environment );
  }
#line 5415 "src-generated/ugbc.tab.c"
    break;

  case 349: /* writing_mode_definition: REPLACE  */
#line 1297 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5424 "src-generated/ugbc.tab.c"
    break;

  case 350: /* writing_mode_definition: OR  */
#line 1301 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5433 "src-generated/ugbc.tab.c"
    break;

  case 351: /* writing_mode_definition: XOR  */
#line 1305 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5442 "src-generated/ugbc.tab.c"
    break;

  case 352: /* writing_mode_definition: AND  */
#line 1309 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5451 "src-generated/ugbc.tab.c"
    break;

  case 353: /* writing_mode_definition: IGNORE  */
#line 1313 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5460 "src-generated/ugbc.tab.c"
    break;

  case 354: /* writing_part_definition: NORMAL  */
#line 1320 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5469 "src-generated/ugbc.tab.c"
    break;

  case 355: /* writing_part_definition: PAPER  */
#line 1324 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5478 "src-generated/ugbc.tab.c"
    break;

  case 356: /* writing_part_definition: PAPER ONLY  */
#line 1328 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5487 "src-generated/ugbc.tab.c"
    break;

  case 357: /* writing_part_definition: PEN  */
#line 1332 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5496 "src-generated/ugbc.tab.c"
    break;

  case 358: /* writing_part_definition: PEN ONLY  */
#line 1336 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5505 "src-generated/ugbc.tab.c"
    break;

  case 359: /* writing_definition: writing_mode_definition COMMA writing_part_definition  */
#line 1343 "src/ugbc.y"
                                                          {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5513 "src-generated/ugbc.tab.c"
    break;

  case 360: /* locate_definition: COMMA expr  */
#line 1349 "src/ugbc.y"
                {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 5521 "src-generated/ugbc.tab.c"
    break;

  case 361: /* locate_definition: expr COMMA  */
#line 1352 "src/ugbc.y"
                 {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 5529 "src-generated/ugbc.tab.c"
    break;

  case 362: /* locate_definition: expr COMMA expr  */
#line 1355 "src/ugbc.y"
                      {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5537 "src-generated/ugbc.tab.c"
    break;

  case 363: /* cmove_definition: COMMA expr  */
#line 1361 "src/ugbc.y"
                {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 5545 "src-generated/ugbc.tab.c"
    break;

  case 364: /* cmove_definition: expr COMMA  */
#line 1364 "src/ugbc.y"
                 {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 5553 "src-generated/ugbc.tab.c"
    break;

  case 365: /* cmove_definition: expr COMMA expr  */
#line 1367 "src/ugbc.y"
                      {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5561 "src-generated/ugbc.tab.c"
    break;

  case 385: /* statement: CUP  */
#line 1392 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 5569 "src-generated/ugbc.tab.c"
    break;

  case 386: /* statement: CDOWN  */
#line 1395 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 5577 "src-generated/ugbc.tab.c"
    break;

  case 387: /* statement: CLEFT  */
#line 1398 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 5585 "src-generated/ugbc.tab.c"
    break;

  case 388: /* statement: CRIGHT  */
#line 1401 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 5593 "src-generated/ugbc.tab.c"
    break;

  case 389: /* statement: CLINE  */
#line 1404 "src/ugbc.y"
          {
      text_cline( _environment, NULL );
  }
#line 5601 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: CLINE expr  */
#line 1407 "src/ugbc.y"
               {
      text_cline( _environment, (yyvsp[0].string) );
  }
#line 5609 "src-generated/ugbc.tab.c"
    break;

  case 391: /* statement: SET TAB expr  */
#line 1410 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 5617 "src-generated/ugbc.tab.c"
    break;

  case 392: /* statement: CENTER expr  */
#line 1413 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5625 "src-generated/ugbc.tab.c"
    break;

  case 393: /* statement: CENTRE expr  */
#line 1416 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5633 "src-generated/ugbc.tab.c"
    break;

  case 394: /* statement: CLS  */
#line 1419 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 5641 "src-generated/ugbc.tab.c"
    break;

  case 395: /* statement: HOME  */
#line 1422 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 5649 "src-generated/ugbc.tab.c"
    break;

  case 396: /* statement: INC Identifier  */
#line 1425 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 5657 "src-generated/ugbc.tab.c"
    break;

  case 397: /* statement: DEC Identifier  */
#line 1428 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 5665 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statement: RANDOMIZE  */
#line 1431 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 5673 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: RANDOMIZE expr  */
#line 1434 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 5681 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: IF expr THEN  */
#line 1437 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5689 "src-generated/ugbc.tab.c"
    break;

  case 401: /* statement: ELSE  */
#line 1440 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 5697 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: ELSE IF expr THEN  */
#line 1443 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5705 "src-generated/ugbc.tab.c"
    break;

  case 403: /* statement: ENDIF  */
#line 1446 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5713 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: DO  */
#line 1449 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5721 "src-generated/ugbc.tab.c"
    break;

  case 405: /* statement: LOOP  */
#line 1452 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5729 "src-generated/ugbc.tab.c"
    break;

  case 406: /* $@15: %empty  */
#line 1455 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5737 "src-generated/ugbc.tab.c"
    break;

  case 407: /* statement: WHILE $@15 expr  */
#line 1457 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5745 "src-generated/ugbc.tab.c"
    break;

  case 408: /* statement: WEND  */
#line 1460 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5753 "src-generated/ugbc.tab.c"
    break;

  case 409: /* statement: REPEAT  */
#line 1463 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5761 "src-generated/ugbc.tab.c"
    break;

  case 410: /* statement: UNTIL expr  */
#line 1466 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5769 "src-generated/ugbc.tab.c"
    break;

  case 411: /* statement: EXIT  */
#line 1469 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5777 "src-generated/ugbc.tab.c"
    break;

  case 412: /* statement: EXIT PROC  */
#line 1472 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5785 "src-generated/ugbc.tab.c"
    break;

  case 413: /* statement: POP PROC  */
#line 1475 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5793 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: EXIT IF expr  */
#line 1478 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5801 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: EXIT Integer  */
#line 1481 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5809 "src-generated/ugbc.tab.c"
    break;

  case 416: /* statement: EXIT direct_integer  */
#line 1484 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5817 "src-generated/ugbc.tab.c"
    break;

  case 417: /* statement: EXIT IF expr COMMA Integer  */
#line 1487 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5825 "src-generated/ugbc.tab.c"
    break;

  case 418: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1490 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5833 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1493 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5841 "src-generated/ugbc.tab.c"
    break;

  case 420: /* statement: NEXT  */
#line 1496 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5849 "src-generated/ugbc.tab.c"
    break;

  case 421: /* statement: PROCEDURE Identifier  */
#line 1499 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5858 "src-generated/ugbc.tab.c"
    break;

  case 422: /* $@16: %empty  */
#line 1503 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5866 "src-generated/ugbc.tab.c"
    break;

  case 423: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1505 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5874 "src-generated/ugbc.tab.c"
    break;

  case 424: /* statement: SHARED parameters_expr  */
#line 1508 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5882 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: GLOBAL parameters_expr  */
#line 1511 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5890 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: END PROC  */
#line 1514 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 5898 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: END PROC OSP expr CSP  */
#line 1517 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5906 "src-generated/ugbc.tab.c"
    break;

  case 428: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1520 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5914 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: Identifier " "  */
#line 1523 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5923 "src-generated/ugbc.tab.c"
    break;

  case 430: /* statement: PROC Identifier  */
#line 1527 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5932 "src-generated/ugbc.tab.c"
    break;

  case 431: /* statement: CALL Identifier  */
#line 1531 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5941 "src-generated/ugbc.tab.c"
    break;

  case 432: /* $@17: %empty  */
#line 1535 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5949 "src-generated/ugbc.tab.c"
    break;

  case 433: /* statement: Identifier OSP $@17 values CSP  */
#line 1537 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5957 "src-generated/ugbc.tab.c"
    break;

  case 434: /* $@18: %empty  */
#line 1540 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5965 "src-generated/ugbc.tab.c"
    break;

  case 435: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1542 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5973 "src-generated/ugbc.tab.c"
    break;

  case 436: /* $@19: %empty  */
#line 1545 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5981 "src-generated/ugbc.tab.c"
    break;

  case 437: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1547 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5989 "src-generated/ugbc.tab.c"
    break;

  case 438: /* statement: PEN expr  */
#line 1550 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 5997 "src-generated/ugbc.tab.c"
    break;

  case 439: /* statement: PAPER expr  */
#line 1553 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 6005 "src-generated/ugbc.tab.c"
    break;

  case 440: /* statement: INVERSE ON  */
#line 1556 "src/ugbc.y"
               {
      text_inverse( _environment, 1 );
  }
#line 6013 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: INVERSE OFF  */
#line 1559 "src/ugbc.y"
                {
      text_inverse( _environment, 0 );
  }
#line 6021 "src-generated/ugbc.tab.c"
    break;

  case 443: /* statement: Identifier COLON  */
#line 1563 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 6029 "src-generated/ugbc.tab.c"
    break;

  case 444: /* statement: BEG GAMELOOP  */
#line 1566 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 6037 "src-generated/ugbc.tab.c"
    break;

  case 445: /* statement: END GAMELOOP  */
#line 1569 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 6045 "src-generated/ugbc.tab.c"
    break;

  case 446: /* statement: GRAPHIC  */
#line 1572 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 6053 "src-generated/ugbc.tab.c"
    break;

  case 447: /* statement: HALT  */
#line 1575 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 6061 "src-generated/ugbc.tab.c"
    break;

  case 448: /* statement: END  */
#line 1578 "src/ugbc.y"
        {
      end( _environment );
  }
#line 6069 "src-generated/ugbc.tab.c"
    break;

  case 453: /* statement: RETURN  */
#line 1585 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 6077 "src-generated/ugbc.tab.c"
    break;

  case 454: /* statement: RETURN expr  */
#line 1588 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 6085 "src-generated/ugbc.tab.c"
    break;

  case 455: /* statement: POP  */
#line 1591 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 6093 "src-generated/ugbc.tab.c"
    break;

  case 456: /* statement: DONE  */
#line 1594 "src/ugbc.y"
          {
      return 0;
  }
#line 6101 "src-generated/ugbc.tab.c"
    break;

  case 457: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1597 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6109 "src-generated/ugbc.tab.c"
    break;

  case 458: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1600 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6117 "src-generated/ugbc.tab.c"
    break;

  case 459: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1603 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 6125 "src-generated/ugbc.tab.c"
    break;

  case 460: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1606 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6133 "src-generated/ugbc.tab.c"
    break;

  case 463: /* statement: Identifier ASSIGN expr  */
#line 1611 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 6147 "src-generated/ugbc.tab.c"
    break;

  case 464: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1620 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 6161 "src-generated/ugbc.tab.c"
    break;

  case 465: /* $@20: %empty  */
#line 1629 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6170 "src-generated/ugbc.tab.c"
    break;

  case 466: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1633 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 6183 "src-generated/ugbc.tab.c"
    break;

  case 467: /* $@21: %empty  */
#line 1641 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6192 "src-generated/ugbc.tab.c"
    break;

  case 468: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1644 "src/ugbc.y"
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
#line 6211 "src-generated/ugbc.tab.c"
    break;

  case 469: /* $@22: %empty  */
#line 1658 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6220 "src-generated/ugbc.tab.c"
    break;

  case 470: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1661 "src/ugbc.y"
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
#line 6239 "src-generated/ugbc.tab.c"
    break;

  case 471: /* statement: DEBUG expr  */
#line 1675 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 6247 "src-generated/ugbc.tab.c"
    break;

  case 474: /* statements_no_linenumbers: statement  */
#line 1683 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 6253 "src-generated/ugbc.tab.c"
    break;

  case 475: /* $@23: %empty  */
#line 1684 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 6259 "src-generated/ugbc.tab.c"
    break;

  case 477: /* $@24: %empty  */
#line 1688 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 6267 "src-generated/ugbc.tab.c"
    break;

  case 478: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1690 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 6275 "src-generated/ugbc.tab.c"
    break;

  case 479: /* $@25: %empty  */
#line 1695 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 6283 "src-generated/ugbc.tab.c"
    break;

  case 485: /* $@26: %empty  */
#line 1705 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 6289 "src-generated/ugbc.tab.c"
    break;


#line 6293 "src-generated/ugbc.tab.c"

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

#line 1707 "src/ugbc.y"


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

