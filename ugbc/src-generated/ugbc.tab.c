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
  YYSYMBOL_BLACK = 176,                    /* BLACK  */
  YYSYMBOL_WHITE = 177,                    /* WHITE  */
  YYSYMBOL_RED = 178,                      /* RED  */
  YYSYMBOL_CYAN = 179,                     /* CYAN  */
  YYSYMBOL_VIOLET = 180,                   /* VIOLET  */
  YYSYMBOL_GREEN = 181,                    /* GREEN  */
  YYSYMBOL_BLUE = 182,                     /* BLUE  */
  YYSYMBOL_YELLOW = 183,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 184,                   /* ORANGE  */
  YYSYMBOL_BROWN = 185,                    /* BROWN  */
  YYSYMBOL_LIGHT = 186,                    /* LIGHT  */
  YYSYMBOL_DARK = 187,                     /* DARK  */
  YYSYMBOL_GREY = 188,                     /* GREY  */
  YYSYMBOL_GRAY = 189,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 190,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 191,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 192,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 193,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 194,                /* TURQUOISE  */
  YYSYMBOL_TAN = 195,                      /* TAN  */
  YYSYMBOL_PINK = 196,                     /* PINK  */
  YYSYMBOL_PEACH = 197,                    /* PEACH  */
  YYSYMBOL_OLIVE = 198,                    /* OLIVE  */
  YYSYMBOL_Identifier = 199,               /* Identifier  */
  YYSYMBOL_String = 200,                   /* String  */
  YYSYMBOL_Integer = 201,                  /* Integer  */
  YYSYMBOL_202_ = 202,                     /* " "  */
  YYSYMBOL_YYACCEPT = 203,                 /* $accept  */
  YYSYMBOL_expr = 204,                     /* expr  */
  YYSYMBOL_expr_math = 205,                /* expr_math  */
  YYSYMBOL_term = 206,                     /* term  */
  YYSYMBOL_modula = 207,                   /* modula  */
  YYSYMBOL_factor = 208,                   /* factor  */
  YYSYMBOL_direct_integer = 209,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 210, /* random_definition_simple  */
  YYSYMBOL_random_definition = 211,        /* random_definition  */
  YYSYMBOL_color_enumeration = 212,        /* color_enumeration  */
  YYSYMBOL_exponential = 213,              /* exponential  */
  YYSYMBOL_214_1 = 214,                    /* $@1  */
  YYSYMBOL_215_2 = 215,                    /* $@2  */
  YYSYMBOL_216_3 = 216,                    /* $@3  */
  YYSYMBOL_position = 217,                 /* position  */
  YYSYMBOL_bank_definition_simple = 218,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 219, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 220,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 221, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 222, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 223,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 224, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 225, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 226,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 227,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 228, /* color_definition_expression  */
  YYSYMBOL_color_definition = 229,         /* color_definition  */
  YYSYMBOL_milliseconds = 230,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 231,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 232, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 233,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 234, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 235, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 236,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 237, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 238, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 239,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 240, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 241, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 242,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 243,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 244, /* text_definition_expression  */
  YYSYMBOL_text_definition = 245,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 246,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 247, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 248,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 249, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 250, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 251,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 252, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 253, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 254,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 255,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 256,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 257,         /* gosub_definition  */
  YYSYMBOL_var_definition = 258,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 259,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 260, /* point_definition_expression  */
  YYSYMBOL_point_definition = 261,         /* point_definition  */
  YYSYMBOL_ink_definition = 262,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 263,       /* on_goto_definition  */
  YYSYMBOL_264_4 = 264,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 265,      /* on_gosub_definition  */
  YYSYMBOL_266_5 = 266,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 267,       /* on_proc_definition  */
  YYSYMBOL_268_6 = 268,                    /* $@6  */
  YYSYMBOL_on_definition = 269,            /* on_definition  */
  YYSYMBOL_270_7 = 270,                    /* $@7  */
  YYSYMBOL_271_8 = 271,                    /* $@8  */
  YYSYMBOL_272_9 = 272,                    /* $@9  */
  YYSYMBOL_every_definition = 273,         /* every_definition  */
  YYSYMBOL_add_definition = 274,           /* add_definition  */
  YYSYMBOL_dimensions = 275,               /* dimensions  */
  YYSYMBOL_datatype = 276,                 /* datatype  */
  YYSYMBOL_dim_definition = 277,           /* dim_definition  */
  YYSYMBOL_278_10 = 278,                   /* $@10  */
  YYSYMBOL_279_11 = 279,                   /* $@11  */
  YYSYMBOL_280_12 = 280,                   /* $@12  */
  YYSYMBOL_dim_definitions = 281,          /* dim_definitions  */
  YYSYMBOL_indexes = 282,                  /* indexes  */
  YYSYMBOL_parameters = 283,               /* parameters  */
  YYSYMBOL_parameters_expr = 284,          /* parameters_expr  */
  YYSYMBOL_values = 285,                   /* values  */
  YYSYMBOL_print_definition = 286,         /* print_definition  */
  YYSYMBOL_287_13 = 287,                   /* $@13  */
  YYSYMBOL_288_14 = 288,                   /* $@14  */
  YYSYMBOL_use_definition = 289,           /* use_definition  */
  YYSYMBOL_writing_mode_definition = 290,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 291,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 292,       /* writing_definition  */
  YYSYMBOL_locate_definition = 293,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 294,         /* cmove_definition  */
  YYSYMBOL_statement = 295,                /* statement  */
  YYSYMBOL_296_15 = 296,                   /* $@15  */
  YYSYMBOL_297_16 = 297,                   /* $@16  */
  YYSYMBOL_298_17 = 298,                   /* $@17  */
  YYSYMBOL_299_18 = 299,                   /* $@18  */
  YYSYMBOL_300_19 = 300,                   /* $@19  */
  YYSYMBOL_301_20 = 301,                   /* $@20  */
  YYSYMBOL_302_21 = 302,                   /* $@21  */
  YYSYMBOL_303_22 = 303,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 304, /* statements_no_linenumbers  */
  YYSYMBOL_305_23 = 305,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 306, /* statements_with_linenumbers  */
  YYSYMBOL_307_24 = 307,                   /* $@24  */
  YYSYMBOL_statements_complex = 308,       /* statements_complex  */
  YYSYMBOL_309_25 = 309,                   /* $@25  */
  YYSYMBOL_program = 310,                  /* program  */
  YYSYMBOL_311_26 = 311                    /* $@26  */
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
#define YYLAST   3026

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  203
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  474
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  921

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   457


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
     195,   196,   197,   198,   199,   200,   201,   202
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
     544,   544,   547,   550,   553,   556,   559,   562,   566,   569,
     572,   575,   579,   582,   585,   588,   592,   595,   598,   601,
     607,   610,   613,   616,   619,   624,   625,   628,   631,   636,
     639,   644,   645,   648,   651,   656,   659,   664,   665,   668,
     671,   674,   679,   682,   685,   690,   691,   694,   695,   696,
     699,   702,   705,   710,   713,   716,   722,   723,   726,   729,
     732,   735,   738,   741,   744,   747,   750,   753,   756,   759,
     762,   765,   768,   773,   776,   779,   782,   785,   788,   791,
     794,   797,   800,   803,   806,   809,   812,   815,   820,   821,
     824,   827,   830,   833,   836,   842,   845,   851,   852,   855,
     860,   865,   866,   869,   872,   877,   880,   885,   886,   889,
     894,   899,   900,   903,   906,   909,   914,   917,   923,   924,
     927,   930,   933,   936,   939,   944,   947,   950,   955,   956,
     958,   959,   962,   965,   968,   973,   980,   983,   989,   992,
     998,  1001,  1007,  1012,  1013,  1016,  1021,  1025,  1025,  1030,
    1034,  1034,  1039,  1043,  1043,  1048,  1048,  1051,  1051,  1054,
    1054,  1059,  1062,  1065,  1070,  1073,  1079,  1083,  1090,  1093,
    1096,  1099,  1102,  1105,  1108,  1111,  1114,  1117,  1122,  1122,
    1130,  1130,  1138,  1138,  1149,  1150,  1154,  1158,  1165,  1170,
    1175,  1180,  1185,  1190,  1198,  1203,  1208,  1213,  1218,  1223,
    1228,  1232,  1239,  1243,  1250,  1253,  1257,  1260,  1260,  1264,
    1264,  1270,  1273,  1279,  1283,  1287,  1291,  1295,  1302,  1306,
    1310,  1314,  1318,  1325,  1331,  1334,  1337,  1343,  1346,  1349,
    1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,
    1365,  1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,
    1377,  1380,  1383,  1386,  1389,  1392,  1395,  1398,  1401,  1404,
    1407,  1410,  1413,  1416,  1419,  1419,  1424,  1427,  1430,  1433,
    1436,  1439,  1442,  1445,  1448,  1451,  1454,  1457,  1460,  1463,
    1467,  1467,  1472,  1475,  1478,  1481,  1484,  1487,  1491,  1495,
    1499,  1499,  1504,  1504,  1509,  1509,  1514,  1517,  1520,  1523,
    1526,  1527,  1530,  1533,  1536,  1539,  1542,  1545,  1546,  1547,
    1548,  1549,  1552,  1555,  1558,  1561,  1564,  1567,  1570,  1573,
    1574,  1575,  1584,  1593,  1593,  1605,  1605,  1622,  1622,  1639,
    1642,  1643,  1647,  1648,  1648,  1652,  1652,  1659,  1659,  1662,
    1663,  1664,  1665,  1669,  1669
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
  "BLACK", "WHITE", "RED", "CYAN", "VIOLET", "GREEN", "BLUE", "YELLOW",
  "ORANGE", "BROWN", "LIGHT", "DARK", "GREY", "GRAY", "MAGENTA", "PURPLE",
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
     455,   456,   457
};
#endif

#define YYPACT_NINF (-801)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-454)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -801,    61,   874,  -801,  -801,  -134,   -84,   -16,  -801,    33,
    2092,   107,     1,  2092,  -801,    46,   253,  2465,   -74,  -115,
    -801,  -801,  -801,  1732,   128,    22,  2465,  2465,    77,   -30,
    -801,   144,   147,  2465,  2465,  -801,   162,   165,   -39,  2465,
      54,   153,  -801,   -24,  -801,  2465,    13,  1912,   211,    38,
    2465,    50,    71,    81,    84,  -131,  -131,  2465,    75,  2465,
     248,    66,  1177,  -801,  -801,  1372,  2465,  2465,   127,    14,
    -801,   299,   308,   314,  -801,  -801,  -801,  2092,   306,  -801,
    -801,  -801,  2092,  2092,  2092,  -801,  -801,  -801,   160,   342,
    1552,  -801,  -801,   329,   330,   331,   177,   166,  -801,  -801,
      12,   332,   334,  2465,  -801,  -801,   335,   336,   337,   338,
     339,   340,   341,   343,   344,   345,   346,   347,   348,   350,
     351,   352,   353,  -801,  -801,   354,    88,   -48,    16,   356,
     369,   370,  -801,  -801,  -801,  -801,  -801,  -801,  -801,   210,
    -801,  -801,   122,    89,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,   212,    19,  -801,  -801,    63,    83,   262,
     204,   265,    90,  -801,  -801,  -801,  -801,  -801,   -15,   313,
      -9,     2,     6,     7,   373,  -801,  -801,  -801,   202,   257,
    -801,  -801,  -801,  2092,  -801,  -801,   374,  -801,  -801,  -801,
    -801,  -801,  2092,   358,   359,  -801,  -801,  -801,     9,  -801,
     103,  -801,  -801,  -801,  -801,  -801,  2465,  2285,  -801,  -801,
     391,  -801,  -801,  -801,  2092,  -801,  -801,  -801,  2092,   377,
    -801,  -801,  -801,   333,  -801,  -801,  -801,   260,  2465,  2465,
    -801,  -801,  2092,  -801,  -801,  -801,   375,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  2465,  2465,  -801,  -801,  -801,
    -801,   395,  -801,  -801,   258,  -801,  2465,   404,  -801,  -801,
    -801,    56,   406,  -801,   267,   270,   271,    68,   408,  -801,
    -801,   243,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,   409,  -801,  2465,   412,  -801,  2465,
     413,  -801,  -801,  -801,  2465,  -801,  -801,  2465,   410,  -801,
    -801,   387,    52,  1049,  -801,   874,   874,   393,   396,  2092,
    -801,  -801,   355,   357,   360,   361,  -801,   390,   399,   400,
     401,   403,   411,   180,   415,  2092,  2092,  2092,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,   392,  -801,
    -801,  2465,  2465,  -801,  2465,  2465,  2465,  2465,  2465,  2465,
    2465,  2465,  2465,  2465,  2465,  2465,  2465,  2465,  2465,  2465,
    2465,  2645,   394,   231,  -801,  -801,   397,  -801,  -801,   414,
     417,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
     418,  -801,   419,  -801,  -801,  -801,  -801,  -801,  -801,  2645,
    2645,  2645,  2645,  2645,  2645,  2645,  2645,  2645,  2645,  2645,
    2645,  2645,  2825,  -801,  -801,  -801,  2092,   420,  -801,  -801,
    -801,   407,   313,   421,   313,   423,   313,   433,   313,   434,
     313,  -801,  2465,   426,  -801,  -801,   229,   252,    94,    95,
    -801,  -801,  -801,   428,   313,   427,  -801,  -801,   264,   268,
     120,   131,  -801,  -801,   429,  -801,  -801,  2092,  -801,  -801,
    2092,  2092,  -801,  -801,  -801,   424,   244,  -801,   458,  2465,
    -801,  -801,  -801,  -801,  2092,  -801,  2465,   461,   462,  -801,
    -801,  2092,   402,   463,  2465,   371,   465,  2465,  -801,  -801,
    -801,  -801,  -801,  -801,   189,  -801,  -801,   440,   455,    50,
    -801,   349,  -801,  -131,   469,    52,  -131,   203,   269,   -41,
    -801,  2465,  -801,  2465,  -801,   874,  -801,  2465,   443,  2465,
    2465,   444,     8,  -801,  1049,  -801,  -801,   280,   282,  -801,
    -801,  2465,   313,  2465,   313,  2465,   281,   283,   284,   286,
     288,   448,   460,   466,  -801,   467,   468,   470,   471,   472,
     474,  2465,   491,   493,   497,   503,   477,   479,   481,   482,
     511,   484,   485,   487,   488,   492,   519,   521,   494,   495,
     498,    15,   362,   499,  2465,  2465,  2465,   501,  2465,  2465,
     262,   262,   318,   318,   318,   318,   318,   318,   318,   318,
     204,   265,   265,  -801,   507,   508,  2092,    58,  -801,   313,
    -801,   313,  -801,   313,  -801,   313,    37,  -801,  2465,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  2465,  -801,   313,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,   313,  -801,
    -801,  -801,  -801,  -801,  -801,   363,   364,   365,   366,   526,
    2465,   525,   502,   504,   405,  2465,  2465,   533,   534,  -801,
     -63,   475,   367,  2465,   536,  -801,  -801,  -801,   514,   368,
     515,  -801,  2465,   372,  2465,  -801,  -131,   543,  -801,  2465,
    2465,   384,   385,  -801,  -801,  -801,  -801,  -801,  -801,  2465,
     550,   422,   552,   532,  2465,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,   553,  -801,  -801,  -801,  -801,  -801,   376,   378,
     379,  -801,  -801,  -801,  -801,  -801,  -801,   537,  2465,  2465,
    2465,  2465,  -801,  -801,  -801,  -801,  2465,  -801,  -801,  -801,
    -801,  -801,  2465,  2465,  -801,  -801,  -801,  2825,   538,  -801,
     539,   561,   568,  2465,   430,   546,   383,   386,  -801,  -801,
    -801,  -801,  -801,  -801,   554,  -801,   555,  -801,   389,   115,
    -801,   579,  -801,   580,   583,  -801,   584,  -801,   585,  -801,
     581,  2092,   586,  2465,  2465,   313,  -801,   560,   564,  2465,
     313,  -801,  -801,  2465,  -801,    36,  2465,   368,   593,   566,
     368,   456,   224,   457,   459,  -801,  -131,  -801,  -801,  -801,
    -801,   571,  2465,  -801,  2465,   590,   573,  2465,  -801,  -801,
    -801,  -801,   574,   575,    99,   111,   576,   577,   578,   582,
    -801,  -801,  2465,  2465,   587,  -801,  -801,  -801,  -801,   416,
     431,  -801,   589,  -801,   592,  -801,  2465,   313,   607,   608,
     612,  2465,  -801,  -801,  2465,  -801,  -801,  -801,   610,   611,
     594,   595,   512,  2465,   615,   562,   597,   368,  -801,   600,
    -801,   372,   629,    52,  -801,  -801,  -801,   624,  -801,  -801,
    2465,   625,   604,  -801,  -801,  2465,  -801,  2465,  -801,  -801,
    -801,  -801,  -801,   605,   606,  -801,  -801,  -801,   445,   446,
     613,   616,   363,   364,   365,  -801,  -801,  2465,  2465,  -801,
    -801,  2465,   617,  2465,  2465,  -801,  -801,  -801,  -801,   372,
     636,  2465,  -801,  2465,  -801,   618,   619,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,   634,
    -801,  -801,  -801,   372,  -801,  -801,  -801,  -801,  2465,  -801,
    -801
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     473,     0,   461,     1,   460,     0,     0,     0,   444,     0,
       0,   408,     0,     0,   435,     0,     0,     0,   260,     0,
     393,   397,   394,     0,     0,     0,     0,     0,     0,   436,
     391,     0,     0,     0,   386,   434,     0,     0,     0,   441,
     443,   389,   392,   399,   396,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   382,   383,     0,     0,     0,     0,   457,
     465,   462,   469,   471,   474,   384,   385,     0,     0,   161,
     162,   361,     0,     0,     0,   175,   176,   363,     0,     0,
       0,    79,    80,     0,     0,     0,     0,     0,   121,   122,
       0,     0,     0,     0,   112,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   123,     0,     0,     0,     0,     0,
       0,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,    44,    49,    50,    51,    52,    53,
      54,    57,    58,     0,    63,    67,    65,     0,     2,    12,
      15,    17,     0,    76,    20,   186,   187,   364,     0,     0,
       0,     0,     0,     0,     0,   155,   156,   360,     0,     0,
     218,   219,   365,     0,   221,   222,   223,   227,   228,   366,
     250,   251,     0,     0,     0,   258,   259,   371,     0,   437,
       0,   270,   374,   266,   267,   438,     0,     0,   233,   234,
       0,   237,   238,   368,     0,   241,   242,   369,     0,   244,
     248,   249,   370,     0,   426,   432,   433,   414,     0,     0,
     459,   387,     0,   231,   232,   367,     0,   273,   274,   372,
     268,   269,   439,   442,   401,     0,     0,   400,   403,   404,
     398,     0,   292,   293,     0,   440,     0,     0,   375,   275,
     373,   308,   314,   449,   418,   409,   419,   324,   330,   412,
     413,   334,   376,   342,   341,   450,   427,   428,   429,   346,
     344,   343,   345,   347,     0,   430,     0,     0,   377,     0,
       0,   378,   380,   381,     0,   467,   431,     0,   455,   420,
     417,     0,     0,   461,   463,   461,   461,     0,     0,     0,
     172,   169,     0,     0,     0,     0,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    24,
      25,    27,    29,    30,    26,    31,   101,    23,     0,   115,
     116,     0,     0,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   120,     0,   118,   119,     0,
       0,   129,    55,    42,    45,    46,    47,    48,    43,    56,
      64,   108,     0,   177,   183,   178,   179,   184,   185,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   181,   182,     0,     0,   167,   168,
     362,   132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,     0,     0,   208,   209,     0,     0,     0,     0,
     205,   204,   130,     0,     0,     0,   193,   194,     0,     0,
       0,     0,   190,   189,     0,   225,   220,     0,   255,   252,
       0,     0,   285,   289,   287,     0,     0,   395,     0,     0,
     240,   239,   246,   243,     0,   388,     0,     0,     0,   230,
     229,     0,     0,   402,     0,     0,     0,     0,   306,   298,
     300,   305,   302,   307,     0,   304,   312,     0,     0,     0,
     422,     0,   424,     0,   325,     0,     0,   339,   337,     0,
     354,   355,   357,   358,   379,   461,   451,     0,     0,     0,
       0,     0,   457,   466,   461,   470,   472,     0,     0,   159,
     157,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    14,     5,     7,     8,     9,    10,     6,     3,     4,
      16,    18,    19,    21,     0,     0,     0,     0,   137,     0,
     149,     0,   141,     0,   145,     0,   133,   206,     0,   213,
     212,   217,   216,   211,   215,   210,   214,     0,   191,     0,
     198,   197,   202,   201,   196,   200,   195,   199,     0,   226,
     224,   256,   253,   257,   254,     0,     0,     0,     0,   261,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   390,
       0,     0,     0,     0,   294,   299,   301,   303,     0,     0,
       0,   315,     0,     0,     0,   327,     0,   326,   331,     0,
       0,   351,   349,   348,   353,   356,   359,   468,   452,     0,
     332,     0,   316,     0,     0,   464,   160,   158,   174,   171,
     173,   170,     0,    75,    68,    70,    74,    72,     0,     0,
       0,    78,    77,    82,    81,    84,    83,     0,     0,     0,
       0,     0,    91,    92,    93,   100,     0,    94,    95,    96,
      97,    98,     0,     0,   110,   111,   102,     0,     0,   106,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   163,
     134,   147,   139,   142,   136,   148,   140,   144,     0,     0,
     203,     0,   188,     0,   276,   286,   279,   290,   282,   288,
     262,     0,     0,     0,     0,     0,   415,     0,     0,     0,
       0,   405,   406,     0,   291,     0,     0,     0,   296,     0,
       0,     0,   318,     0,     0,   328,     0,   340,   338,   352,
     350,     0,     0,   421,     0,     0,     0,     0,    69,    71,
      73,   124,     0,     0,     0,     0,     0,     0,     0,     0,
     107,   125,     0,     0,     0,   109,    60,   166,   164,     0,
       0,   150,   135,   146,   138,   143,     0,     0,     0,     0,
       0,     0,   264,   263,     0,   236,   247,   245,     0,     0,
       0,     0,   407,     0,     0,     0,     0,     0,   309,     0,
     423,     0,   319,     0,   411,   425,   329,     0,   333,   317,
       0,     0,     0,    85,    86,     0,    87,     0,    89,    99,
     105,   104,    22,     0,     0,    62,   152,   154,     0,     0,
       0,     0,     0,     0,     0,   265,   235,     0,     0,   272,
     271,     0,     0,     0,     0,   313,   297,   311,   321,     0,
     320,     0,   454,     0,   127,     0,     0,   128,   126,   151,
     153,   207,   192,   278,   281,   284,   445,   446,   416,     0,
     447,   295,   322,     0,   456,   458,    88,    90,     0,   323,
     448
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -801,   -10,   -40,   -61,   256,  -298,    74,  -801,  -801,  -801,
    -398,  -801,  -801,  -801,   478,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,   496,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -216,  -801,  -214,  -801,  -213,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -716,  -301,  -801,  -801,  -801,  -801,   173,  -564,
    -800,   -54,  -558,  -300,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -297,  -801,  -801,  -801,  -294,  -801,  -801,  -801
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   672,   158,   159,   160,   161,   162,   335,   336,   163,
     164,   382,   567,   568,   433,   175,   176,   177,    79,    80,
      81,   408,   409,   410,    85,    86,    87,   388,   165,   166,
     167,   180,   181,   182,   187,   188,   189,   233,   234,   235,
     211,   212,   213,   215,   216,   217,   220,   221,   222,   195,
     196,   197,   201,   205,   242,   202,   237,   238,   239,   260,
     745,   818,   747,   819,   749,   820,   199,   625,   627,   626,
     255,   258,   769,   486,   262,   487,   488,   648,   263,   673,
     773,   269,   671,   272,   660,   659,   275,   284,   664,   285,
     288,   291,    71,   206,   491,   509,   652,   654,   301,   508,
     302,    72,   514,    73,   303,    74,   505,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     157,   511,   270,   178,   583,   725,   513,   198,    77,   406,
     724,   515,   516,   210,   296,   412,   223,   224,   295,    97,
     296,   297,   717,   230,   231,   169,   414,   297,   298,   243,
     416,   418,   338,   170,   298,   250,   366,   254,   364,   380,
     259,   888,  -453,   833,   246,   661,   218,   271,  -453,   276,
     171,   836,   287,   -59,   839,   290,   292,   293,    97,    82,
     226,     3,   452,   561,    83,    75,   738,   307,   267,   268,
     183,   834,   310,   312,   314,   493,  -310,   478,   172,   173,
     324,   478,   184,   185,   203,   739,   204,   179,   494,   912,
     730,   389,   390,   343,   771,   391,   774,   392,   393,   394,
     395,   396,   581,   582,    84,   781,   855,   731,   362,   219,
     786,   453,   365,   919,   227,    76,   495,   249,   857,   662,
     247,   886,   363,   455,   663,   200,   479,   480,   481,   168,
     479,   480,   481,   186,   856,   732,   733,   482,   761,   603,
     605,   482,   383,   384,   402,   456,   858,   812,   604,   606,
     339,   308,   214,   454,   367,   299,   311,   313,   315,   804,
     240,   299,   241,   279,   813,   614,   381,   225,   340,   383,
     403,   280,   368,   445,   615,   483,   616,   248,   228,   483,
     397,   229,   448,    78,   407,   617,   232,   484,   398,   236,
     413,   484,   814,   815,   657,   485,   457,   458,   244,   485,
     174,   415,   328,  -336,   460,   417,   419,  -336,   462,  -336,
     300,   667,   251,   385,   386,   387,   300,   675,   467,   468,
     849,   245,   469,   400,   848,   401,   421,   422,   281,   282,
     283,   841,   273,   274,   423,   472,   473,   257,   424,   425,
     385,   386,   404,   411,   842,   256,   476,   426,   497,   261,
     498,   329,   330,   331,   531,   532,   427,   446,   428,   429,
     332,   333,   334,   645,   646,   533,   449,   430,   431,  -335,
     264,   377,   843,  -335,   647,  -335,   500,   378,   432,   502,
     265,   421,   434,   266,   504,   599,   600,   506,   461,   435,
     277,   278,   463,   436,   437,   190,   191,   192,   193,   519,
     373,   294,   438,   374,   375,   304,   470,   194,   601,   602,
     376,   439,   305,   440,   441,   535,   537,   539,   306,   799,
     610,   611,   442,   443,   612,   613,   389,   390,   570,   571,
     309,   542,   543,   432,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   572,   573,   574,   575,   576,   577,   578,   579,   777,
     778,   316,   317,   325,   326,   327,   341,   337,   342,   344,
     345,   346,   347,   348,   349,   350,   369,   351,   352,   353,
     354,   355,   356,   520,   357,   358,   359,   360,   361,   370,
     371,   372,   399,   379,   402,    97,   584,   420,   459,   536,
     538,   540,   465,   447,   450,   451,   464,   466,   474,   471,
     475,   477,   597,   489,   490,   496,   499,  -410,   492,   501,
     503,   510,   517,   507,   525,   518,   541,   521,   562,   522,
     563,   564,   523,   524,   526,   527,   528,   619,   529,   655,
     621,   623,   658,   629,   586,   589,   530,   591,   565,   631,
     534,   566,   -61,   569,   632,   587,   634,   593,   595,   598,
     609,   637,   607,   618,   641,   630,   628,   644,   635,   636,
     640,   639,   643,   642,   649,   650,   656,   669,   674,   676,
     585,   677,   683,   688,   684,   685,   588,   686,   590,   687,
     592,   665,   594,   666,   596,   689,   653,   668,   698,   670,
     699,   690,   691,   692,   700,   693,   694,   695,   608,   696,
     701,   678,   702,   680,   703,   682,   704,   705,   706,   707,
     708,   620,   709,   710,   622,   624,   712,   711,   713,   714,
     715,   697,   753,   716,   719,   723,   726,   727,   633,   751,
     759,   760,   890,   766,   754,   638,   755,   763,   767,   770,
     776,   779,   780,   756,   720,   721,   722,   782,   670,   784,
     787,   718,   744,   746,   748,   750,   764,   785,   802,   768,
     783,   772,   791,   800,   801,   803,   728,   788,   805,   789,
     790,   806,   807,   809,   810,   808,   816,   817,   740,   811,
    -277,  -280,  -283,   824,   821,   828,   679,   741,   681,   829,
     837,   838,   775,   850,   840,   844,   847,   845,   851,   853,
     854,   859,   860,   861,   872,   873,   866,   862,   868,   874,
     752,   869,   865,   877,   878,   757,   758,   881,   883,   879,
     880,   867,   885,   765,   884,   887,   889,   891,   893,   894,
     897,   898,   670,   913,   670,   899,   900,   918,   901,   271,
     271,   902,   909,   916,   917,   580,   903,   444,   405,   904,
     729,   905,   651,   734,     0,   735,     0,   736,     0,   737,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   742,     0,     0,     0,     0,   792,   793,
     794,   795,   743,     0,     0,     0,   796,     0,     0,     0,
       0,     0,   797,   798,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   762,     0,     0,     0,     0,     0,
       0,     0,   846,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   822,     0,   825,   826,     0,     0,     0,     0,   830,
       0,     0,     0,   832,     0,     0,   835,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   670,     0,     0,     0,     0,   852,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   863,   864,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   870,     0,     0,     0,
       0,   875,     0,     0,   876,     0,     0,     0,     0,     0,
       0,     0,     0,   882,     0,   823,     0,     0,     0,   827,
       0,     0,     0,     0,   831,     0,     0,     0,     0,     0,
     892,     0,     0,     0,     0,   895,     0,   896,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   906,   907,     0,
       0,   908,     0,   910,   911,     0,     0,     4,     0,     0,
       0,   914,     0,   915,     5,     6,     0,     0,     0,     0,
       0,   871,     0,     0,     0,     0,     7,     8,     0,     9,
       0,    10,    11,     0,    12,    13,     0,     0,   920,     0,
       0,     0,    14,     0,    15,    16,    17,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,    28,    29,     0,    30,     0,     0,    31,    32,
      33,     0,    34,    35,    36,    37,    38,    39,    40,     0,
      41,     0,     0,     0,    42,    43,    44,    45,    46,     0,
      47,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,    51,     0,    52,    53,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,     0,     0,    58,    59,    60,     0,     0,     0,     0,
      61,     0,    62,    63,    64,    65,    66,    67,     0,    68,
       0,     0,     4,     0,     0,     0,     0,     0,     0,     5,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,    69,     9,    70,    10,    11,     0,    12,
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
      49,     0,     0,     0,   286,     0,    88,     0,    50,     0,
       0,    51,     0,    52,    53,    54,     0,     0,    55,     0,
       0,    89,    56,     0,    57,     0,     0,     0,    58,    59,
      60,    90,     0,     0,     0,    61,     0,    62,    63,    64,
      65,    66,    67,     0,    68,     0,     0,    91,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,     0,     0,    95,   512,     0,
      96,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    99,     0,   100,     0,     0,     0,     0,     0,     0,
       0,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,   104,   105,     0,     0,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     0,     0,     0,   118,
     119,   120,     0,   121,   122,   123,     0,   124,   125,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,     0,   127,     0,     0,     0,   128,     0,     0,
       0,     0,     0,     0,     0,   129,     0,     0,   130,     0,
       0,   131,     0,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   289,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
       0,     0,    95,     0,     0,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    99,     0,   100,     0,
       0,     0,     0,     0,     0,     0,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,     0,   121,   122,
     123,     0,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,   127,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,   130,     0,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    88,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,     0,    89,   318,     0,     0,
       0,     0,     0,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
       0,     0,    95,     0,     0,    96,   319,   320,   321,     0,
       0,     0,     0,     0,     0,    98,    99,   322,   100,     0,
       0,     0,     0,     0,     0,     0,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,   323,   121,   122,
     123,     0,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,   127,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,   130,     0,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    88,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,     0,   207,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,     0,   208,   209,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
       0,     0,    95,     0,     0,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    99,     0,   100,     0,
       0,     0,     0,     0,     0,     0,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,     0,   121,   122,
     123,     0,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,   127,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,   130,     0,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    88,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,   252,   253,     0,     0,     0,     0,
       0,     0,    91,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
       0,     0,    95,     0,     0,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    99,     0,   100,     0,
       0,     0,     0,     0,     0,     0,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,     0,   121,   122,
     123,     0,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,   127,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,   130,     0,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    88,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
       0,     0,    95,     0,     0,    96,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,    99,     0,   100,     0,
       0,     0,     0,     0,     0,     0,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,     0,   121,   122,
     123,     0,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,   127,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,   130,     0,     0,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,     0,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   317,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,     0,     0,    95,     0,     0,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    99,
       0,   100,     0,     0,     0,     0,     0,     0,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
       0,   121,   122,   123,     0,   124,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
       0,   127,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,     0,   129,     0,     0,   130,     0,     0,   131,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    88,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,     0,     0,    95,     0,     0,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    99,
       0,   100,     0,     0,     0,     0,     0,     0,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
       0,   121,   122,   123,     0,   124,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
       0,   127,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,     0,   129,     0,     0,   130,     0,     0,   131,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    88,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,     0,     0,    95,     0,     0,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    99,
       0,   100,     0,     0,     0,     0,     0,     0,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,     0,     0,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
       0,   121,   122,   123,     0,   124,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
       0,   127,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,     0,   129,     0,     0,   130,     0,     0,   131,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    88,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,     0,     0,    95,     0,     0,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    99,
       0,   100,     0,     0,     0,     0,     0,     0,     0,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,     0,     0,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
       0,   121,   122,   123,     0,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
       0,   127,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,     0,   129,     0,     0,   130,     0,     0,   131,
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156
};

static const yytype_int16 yycheck[] =
{
      10,   302,    56,    13,   402,   569,   303,    17,    24,    24,
     568,   305,   306,    23,     6,    24,    26,    27,     4,    82,
       6,    13,     7,    33,    34,    24,    24,    13,    20,    39,
      24,    24,    20,    32,    20,    45,    20,    47,    86,    20,
      50,   841,    34,     7,    68,    86,    24,    57,    34,    59,
      49,   767,    62,    34,   770,    65,    66,    67,    82,    26,
      90,     0,    53,   361,    31,   199,    29,    77,   199,   200,
      24,    35,    82,    83,    84,     7,    20,    25,    77,    78,
      90,    25,    36,    37,   199,    48,   201,    13,    20,   889,
      32,     8,     9,   103,   652,    12,   654,    14,    15,    16,
      17,    18,   400,   401,    71,   669,     7,    49,    20,    87,
     674,   102,   160,   913,   144,   199,    48,    43,     7,   160,
     144,   837,    34,    20,   165,   199,    74,    75,    76,    22,
      74,    75,    76,    87,    35,    77,    78,    85,   201,    45,
      45,    85,    79,    80,   129,    42,    35,    32,    54,    54,
     138,    77,    24,   144,   138,   147,    82,    83,    84,   723,
     199,   147,   201,    97,    49,    45,   147,    90,   156,    79,
      80,   105,   156,   183,    54,   123,    45,   201,    34,   123,
      97,    34,   192,   199,   199,    54,    24,   135,   105,    24,
     199,   135,    77,    78,   495,   143,   206,   207,   144,   143,
     199,   199,    25,     0,   214,   199,   199,     4,   218,     6,
     202,   505,   199,   150,   151,   152,   202,   514,   228,   229,
     784,    68,   232,    19,   782,    21,    24,    25,   162,   163,
     164,     7,   157,   158,    32,   245,   246,   199,    36,    37,
     150,   151,   152,   169,    20,    34,   256,    45,     5,   199,
       7,    74,    75,    76,    74,    75,    54,   183,    56,    57,
      83,    84,    85,    74,    75,    85,   192,    65,    66,     0,
     199,   182,    48,     4,    85,     6,   286,   188,    76,   289,
     199,    24,    25,   199,   294,    56,    57,   297,   214,    32,
      42,    43,   218,    36,    37,    42,    43,    44,    45,   309,
     178,   174,    45,   181,   182,     6,   232,    54,    56,    57,
     188,    54,     4,    56,    57,   325,   326,   327,     4,   717,
      56,    57,    65,    66,    56,    57,     8,     9,   389,   390,
      24,   341,   342,    76,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   391,   392,   393,   394,   395,   396,   397,   398,   659,
     660,   201,    20,    34,    34,    34,    34,   201,    34,    34,
      34,    34,    34,    34,    34,    34,    20,    34,    34,    34,
      34,    34,    34,   309,    34,    34,    34,    34,    34,    20,
      20,   181,   130,   181,   129,    82,   406,    24,     7,   325,
     326,   327,    69,    29,    46,    46,    29,   147,    13,    34,
     152,     7,   422,     7,   147,     7,     7,   147,   147,     7,
       7,    34,    29,    13,    34,    29,    34,    72,    34,    72,
     199,    34,    72,    72,    35,    35,    35,   447,    35,   493,
     450,   451,   496,   199,    24,    24,    35,    24,    34,   459,
      35,    34,    34,    34,   464,    48,   466,    24,    24,    33,
      33,   471,    34,    34,   474,     7,    42,   477,     7,     7,
       7,    69,     7,   102,    34,    20,     7,    34,    34,   199,
     406,   199,   201,    35,   201,   201,   412,   201,   414,   201,
     416,   501,   418,   503,   420,    35,   147,   507,     7,   509,
       7,    35,    35,    35,     7,    35,    35,    35,   434,    35,
       7,   521,    35,   523,    35,   525,    35,    35,     7,    35,
      35,   447,    35,    35,   450,   451,     7,    35,     7,    35,
      35,   541,     7,    35,    35,    34,    29,    29,   464,    13,
       7,     7,   843,     7,    42,   471,    42,    72,    34,    34,
       7,   167,   167,   148,   564,   565,   566,     7,   568,     7,
       7,   199,   199,   199,   199,   199,   199,    35,     7,   201,
     148,   199,    35,    35,    35,     7,   586,   201,   148,   201,
     201,    35,   199,    29,    29,   199,     7,     7,   598,   200,
       7,     7,     7,     7,    13,    35,   522,   607,   524,    35,
       7,    35,   656,    13,   148,   148,    35,   148,    35,    35,
      35,    35,    35,    35,     7,     7,   200,    35,    29,     7,
     630,    29,    35,    13,    13,   635,   636,   115,    13,    35,
      35,   200,    35,   643,    72,    35,     7,    13,    13,    35,
      35,    35,   652,     7,   654,   200,   200,    13,    35,   659,
     660,    35,    35,    35,    35,   399,   872,   179,   162,   873,
     586,   874,   489,   589,    -1,   591,    -1,   593,    -1,   595,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   609,    -1,    -1,    -1,    -1,   698,   699,
     700,   701,   618,    -1,    -1,    -1,   706,    -1,    -1,    -1,
      -1,    -1,   712,   713,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   640,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   776,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   751,    -1,   753,   754,    -1,    -1,    -1,    -1,   759,
      -1,    -1,    -1,   763,    -1,    -1,   766,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   782,    -1,    -1,    -1,    -1,   787,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   802,   803,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   816,    -1,    -1,    -1,
      -1,   821,    -1,    -1,   824,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   833,    -1,   751,    -1,    -1,    -1,   755,
      -1,    -1,    -1,    -1,   760,    -1,    -1,    -1,    -1,    -1,
     850,    -1,    -1,    -1,    -1,   855,    -1,   857,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   877,   878,    -1,
      -1,   881,    -1,   883,   884,    -1,    -1,     3,    -1,    -1,
      -1,   891,    -1,   893,    10,    11,    -1,    -1,    -1,    -1,
      -1,   817,    -1,    -1,    -1,    -1,    22,    23,    -1,    25,
      -1,    27,    28,    -1,    30,    31,    -1,    -1,   918,    -1,
      -1,    -1,    38,    -1,    40,    41,    42,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    88,    89,    -1,    91,    -1,    -1,    94,    95,
      96,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,    -1,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,    -1,    -1,   142,    -1,   144,   145,
     146,    -1,    -1,   149,    -1,    -1,    -1,   153,    -1,   155,
      -1,    -1,    -1,   159,   160,   161,    -1,    -1,    -1,    -1,
     166,    -1,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,   199,    25,   201,    27,    28,    -1,    30,
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
     131,    -1,    -1,    -1,     7,    -1,     9,    -1,   139,    -1,
      -1,   142,    -1,   144,   145,   146,    -1,    -1,   149,    -1,
      -1,    24,   153,    -1,   155,    -1,    -1,    -1,   159,   160,
     161,    34,    -1,    -1,    -1,   166,    -1,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,   199,    -1,
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
     183,   184,   185,   186,   187,   188,    -1,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,     7,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
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
     188,     9,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,    -1,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,   132,   133,   134,   135,   136,   137,
     138,    -1,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,    -1,
      -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     168,    -1,    -1,   171,    -1,    -1,   174,    -1,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     9,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,    -1,    -1,    24,    -1,    -1,    -1,
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
     188,     9,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,    -1,    -1,    24,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,    -1,
      -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     168,    -1,    -1,   171,    -1,    -1,   174,    -1,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     9,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    83,    84,    -1,    86,    -1,
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
     188,    -1,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,
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
      -1,    -1,    -1,   168,    -1,    -1,   171,    -1,    -1,   174,
      -1,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     9,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,    -1,    24,
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
      -1,    -1,    -1,   168,    -1,    -1,   171,    -1,    -1,   174,
      -1,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     9,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,    -1,    24,
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
     185,   186,   187,   188,     9,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,    -1,    24,
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
      -1,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,    -1,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   310,   311,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    86,    88,    89,
      91,    94,    95,    96,    98,    99,   100,   101,   102,   103,
     104,   106,   110,   111,   112,   113,   114,   116,   117,   131,
     139,   142,   144,   145,   146,   149,   153,   155,   159,   160,
     161,   166,   168,   169,   170,   171,   172,   173,   175,   199,
     201,   295,   304,   306,   308,   199,   199,    24,   199,   221,
     222,   223,    26,    31,    71,   227,   228,   229,     9,    24,
      34,    50,    51,    52,    67,    70,    73,    82,    83,    84,
      86,    94,    95,   107,   108,   109,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   132,   133,
     134,   136,   137,   138,   140,   141,   154,   156,   160,   168,
     171,   174,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   204,   205,   206,
     207,   208,   209,   212,   213,   231,   232,   233,    22,    24,
      32,    49,    77,    78,   199,   218,   219,   220,   204,   209,
     234,   235,   236,    24,    36,    37,    87,   237,   238,   239,
      42,    43,    44,    45,    54,   252,   253,   254,   204,   269,
     199,   255,   258,   199,   201,   256,   296,    24,    36,    37,
     204,   243,   244,   245,    24,   246,   247,   248,    24,    87,
     249,   250,   251,   204,   204,    90,    90,   144,    34,    34,
     204,   204,    24,   240,   241,   242,    24,   259,   260,   261,
     199,   201,   257,   204,   144,    68,    68,   144,   201,   209,
     204,   199,    42,    43,   204,   273,    34,   199,   274,   204,
     262,   199,   277,   281,   199,   199,   199,   199,   200,   284,
     284,   204,   286,   157,   158,   289,   204,    42,    43,    97,
     105,   162,   163,   164,   290,   292,     7,   204,   293,     7,
     204,   294,   204,   204,   174,     4,     6,    13,    20,   147,
     202,   301,   303,   307,     6,     4,     4,   204,   209,    24,
     204,   209,   204,   209,   204,   209,   201,    20,    25,    74,
      75,    76,    85,   135,   204,    34,    34,    34,    25,    74,
      75,    76,    83,    84,    85,   210,   211,   201,    20,   138,
     156,    34,    34,   204,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    20,    34,    86,   160,    20,   138,   156,    20,
      20,    20,   181,   178,   181,   182,   188,   182,   188,   181,
      20,   147,   214,    79,    80,   150,   151,   152,   230,     8,
       9,    12,    14,    15,    16,    17,    18,    97,   105,   130,
      19,    21,   129,    80,   152,   230,    24,   199,   224,   225,
     226,   209,    24,   199,    24,   199,    24,   199,    24,   199,
      24,    24,    25,    32,    36,    37,    45,    54,    56,    57,
      65,    66,    76,   217,    25,    32,    36,    37,    45,    54,
      56,    57,    65,    66,   217,   204,   209,    29,   204,   209,
      46,    46,    53,   102,   144,    20,    42,   204,   204,     7,
     204,   209,   204,   209,    29,    69,   147,   204,   204,   204,
     209,    34,   204,   204,    13,   152,   204,     7,    25,    74,
      75,    76,    85,   123,   135,   143,   276,   278,   279,     7,
     147,   297,   147,     7,    20,    48,     7,     5,     7,     7,
     204,     7,   204,     7,   204,   309,   204,    13,   302,   298,
      34,   276,   199,   304,   305,   308,   308,    29,    29,   204,
     209,    72,    72,    72,    72,    34,    35,    35,    35,    35,
      35,    74,    75,    85,    35,   204,   209,   204,   209,   204,
     209,    34,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   208,    34,   199,    34,    34,    34,   215,   216,    34,
     206,   206,   205,   205,   205,   205,   205,   205,   205,   205,
     207,   208,   208,   213,   204,   209,    24,    48,   209,    24,
     209,    24,   209,    24,   209,    24,   209,   204,    33,    56,
      57,    56,    57,    45,    54,    45,    54,    34,   209,    33,
      56,    57,    56,    57,    45,    54,    45,    54,    34,   204,
     209,   204,   209,   204,   209,   270,   272,   271,    42,   199,
       7,   204,   204,   209,   204,     7,     7,   204,   209,    69,
       7,   204,   102,     7,   204,    74,    75,    85,   280,    34,
      20,   281,   299,   147,   300,   284,     7,   276,   284,   288,
     287,    86,   160,   165,   291,   204,   204,   308,   204,    34,
     204,   285,   204,   282,    34,   304,   199,   199,   204,   209,
     204,   209,   204,   201,   201,   201,   201,   201,    35,    35,
      35,    35,    35,    35,    35,    35,    35,   204,     7,     7,
       7,     7,    35,    35,    35,    35,     7,    35,    35,    35,
      35,    35,     7,     7,    35,    35,    35,     7,   199,    35,
     204,   204,   204,    34,   285,   282,    29,    29,   204,   209,
      32,    49,    77,    78,   209,   209,   209,   209,    29,    48,
     204,   204,   209,   209,   199,   263,   199,   265,   199,   267,
     199,    13,   204,     7,    42,    42,   148,   204,   204,     7,
       7,   201,   209,    72,   199,   204,     7,    34,   201,   275,
      34,   285,   199,   283,   285,   284,     7,   286,   286,   167,
     167,   282,     7,   148,     7,    35,   282,     7,   201,   201,
     201,    35,   204,   204,   204,   204,   204,   204,   204,   213,
      35,    35,     7,     7,   282,   148,    35,   199,   199,    29,
      29,   200,    32,    49,    77,    78,     7,     7,   264,   266,
     268,    13,   204,   209,     7,   204,   204,   209,    35,    35,
     204,   209,   204,     7,    35,   204,   275,     7,    35,   275,
     148,     7,    20,    48,   148,   148,   284,    35,   285,   282,
      13,    35,   204,    35,    35,     7,    35,     7,    35,    35,
      35,    35,    35,   204,   204,    35,   200,   200,    29,    29,
     204,   209,     7,     7,     7,   204,   204,    13,    13,    35,
      35,   115,   204,    13,    72,    35,   275,    35,   283,     7,
     276,    13,   204,    13,    35,   204,   204,    35,    35,   200,
     200,    35,    35,   263,   265,   267,   204,   204,   204,    35,
     204,   204,   283,     7,   204,   204,    35,    35,    13,   283,
     204
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   203,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   205,   205,   205,   206,   206,   207,   207,   207,
     208,   208,   208,   209,   210,   210,   210,   210,   210,   210,
     210,   211,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   214,
     213,   215,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   216,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     217,   217,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     219,   219,   219,   219,   219,   220,   220,   221,   221,   222,
     222,   223,   223,   224,   224,   225,   225,   226,   226,   227,
     227,   227,   228,   228,   228,   229,   229,   230,   230,   230,
     231,   231,   231,   232,   232,   232,   233,   233,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   236,   236,
     237,   237,   237,   237,   237,   238,   238,   239,   239,   240,
     241,   242,   242,   243,   243,   244,   244,   245,   245,   246,
     247,   248,   248,   249,   249,   249,   250,   250,   251,   251,
     252,   252,   252,   252,   252,   253,   253,   253,   254,   254,
     255,   255,   255,   255,   255,   255,   256,   256,   257,   257,
     258,   259,   260,   261,   261,   262,   263,   264,   263,   265,
     266,   265,   267,   268,   267,   270,   269,   271,   269,   272,
     269,   273,   273,   273,   274,   274,   275,   275,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   278,   277,
     279,   277,   280,   277,   281,   281,   282,   282,   283,   283,
     283,   283,   283,   283,   284,   284,   284,   284,   284,   284,
     284,   284,   285,   285,   286,   286,   286,   287,   286,   288,
     286,   289,   289,   290,   290,   290,   290,   290,   291,   291,
     291,   291,   291,   292,   293,   293,   293,   294,   294,   294,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   296,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     297,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     298,   295,   299,   295,   300,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   301,   295,   302,   295,   303,   295,   295,
     295,   295,   304,   305,   304,   307,   306,   309,   308,   308,
     308,   308,   308,   311,   310
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
       2,     1,     1,     1,     5,     5,     7,     7,     7,     2,
       1,     1,     2,     3,     4,     5,     4,     3,     5,     4,
       4,     3,     4,     5,     4,     3,     5,     4,     4,     3,
       5,     7,     6,     7,     6,     1,     1,     3,     4,     3,
       4,     1,     1,     3,     4,     3,     4,     1,     1,     2,
       4,     4,     2,     4,     4,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     1,     1,     4,     2,
       2,     3,     7,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     2,     2,     3,     7,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       2,     1,     1,     1,     3,     2,     3,     1,     1,     2,
       2,     1,     1,     1,     1,     6,     5,     1,     1,     2,
       2,     1,     1,     2,     1,     5,     2,     5,     1,     1,
       1,     1,     2,     3,     3,     2,     3,     3,     1,     1,
       0,     3,     4,     5,     5,     6,     1,     1,     1,     1,
       1,     6,     6,     1,     1,     1,     1,     0,     4,     1,
       0,     4,     1,     0,     4,     0,     4,     0,     4,     0,
       4,     4,     1,     1,     3,     7,     1,     3,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     0,     5,
       0,     6,     0,     6,     1,     3,     1,     3,     1,     2,
       3,     3,     4,     5,     1,     2,     3,     3,     4,     5,
       1,     3,     1,     3,     1,     2,     2,     0,     4,     0,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     3,     2,     2,     3,     2,     2,     3,
       2,     2,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       2,     2,     1,     1,     2,     2,     1,     2,     3,     1,
       4,     1,     1,     1,     0,     3,     1,     1,     2,     1,
       2,     2,     3,     2,     2,     5,     5,     6,     1,     2,
       0,     6,     2,     2,     2,     5,     8,     2,     2,     2,
       0,     5,     0,     6,     0,     6,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     2,     2,     2,
       2,     1,     2,     1,     1,     8,     8,     8,    10,     2,
       2,     3,     4,     0,     7,     0,     8,     0,     8,     2,
       1,     0,     1,     0,     4,     0,     3,     0,     4,     1,
       3,     1,     3,     0,     2
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
#line 2880 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 80 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2889 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 84 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2897 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 87 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2905 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 90 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2913 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 93 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2921 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 96 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2929 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 99 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2937 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 102 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2945 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 109 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2953 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 112 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2962 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 125 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2971 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 129 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2980 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 137 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2989 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 141 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 2998 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 148 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3006 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 153 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3014 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 156 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3022 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 159 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3030 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 162 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3038 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 165 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3046 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 168 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3054 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 171 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3062 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 176 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3070 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 181 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3079 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 185 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3088 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 189 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3097 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 193 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3106 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 197 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3115 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 201 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3124 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 205 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3133 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 209 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3142 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 213 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3151 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 217 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3160 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 221 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3169 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 225 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3178 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 229 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3187 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 233 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3196 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 237 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3205 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 241 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3214 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 245 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3223 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 249 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3232 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 253 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3241 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 257 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3250 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 261 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3259 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 265 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3268 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 269 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3277 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 273 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3286 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 277 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3295 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 281 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3304 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 285 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3313 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 291 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3322 "src-generated/ugbc.tab.c"
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
#line 3334 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 302 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3343 "src-generated/ugbc.tab.c"
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
#line 3355 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 313 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3363 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 316 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3371 "src-generated/ugbc.tab.c"
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
#line 3385 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 328 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3394 "src-generated/ugbc.tab.c"
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
#line 3406 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 339 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3415 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 343 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3424 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 347 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3433 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 351 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3442 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 355 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3451 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 359 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3460 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 363 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3469 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 367 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3478 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 371 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3486 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 374 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3494 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 377 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3502 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 380 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3510 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 383 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3518 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 386 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3526 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 389 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3534 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 392 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3542 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 395 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3550 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 398 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3558 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 401 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3566 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 404 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3574 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 407 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3582 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 410 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3590 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 413 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3598 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 416 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3606 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 419 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3614 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 422 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3622 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 425 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3630 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 428 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3638 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 431 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3646 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 434 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3654 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 437 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3662 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 440 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3670 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 443 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3678 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 446 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3686 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 449 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3694 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 452 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3702 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 455 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3710 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 458 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3718 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 461 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3726 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 464 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3734 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 467 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3742 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 469 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3751 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 473 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3759 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 476 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3767 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 479 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3776 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 483 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3785 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 487 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3794 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: PEN COLORS  */
#line 491 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3803 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: PEN DEFAULT  */
#line 495 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3812 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: DEFAULT PEN  */
#line 499 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3821 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: PAPER COLORS  */
#line 503 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3830 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: PAPER DEFAULT  */
#line 507 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3839 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: DEFAULT PAPER  */
#line 511 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3848 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: WIDTH  */
#line 515 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3856 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: HEIGHT  */
#line 518 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3864 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: TIMER  */
#line 521 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3872 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PEN DOLLAR OP expr CP  */
#line 524 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 3880 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER DOLLAR OP expr CP  */
#line 527 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3888 "src-generated/ugbc.tab.c"
    break;

  case 126: /* exponential: CMOVE DOLLAR OP expr COMMA expr CP  */
#line 530 "src/ugbc.y"
                                         {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3896 "src-generated/ugbc.tab.c"
    break;

  case 127: /* exponential: AT DOLLAR OP expr COMMA expr CP  */
#line 533 "src/ugbc.y"
                                      {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3904 "src-generated/ugbc.tab.c"
    break;

  case 128: /* exponential: LOCATE DOLLAR OP expr COMMA expr CP  */
#line 536 "src/ugbc.y"
                                          {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3912 "src-generated/ugbc.tab.c"
    break;

  case 129: /* exponential: TAB DOLLAR  */
#line 539 "src/ugbc.y"
                 {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 3920 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_simple: AT direct_integer  */
#line 547 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3928 "src-generated/ugbc.tab.c"
    break;

  case 133: /* bank_definition_simple: Identifier AT direct_integer  */
#line 550 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3936 "src-generated/ugbc.tab.c"
    break;

  case 134: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 553 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3944 "src-generated/ugbc.tab.c"
    break;

  case 135: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 556 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3952 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 559 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3960 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bank_definition_simple: DATA AT direct_integer  */
#line 562 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3968 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 566 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3976 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 569 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3984 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 572 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3992 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_simple: CODE AT direct_integer  */
#line 575 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4000 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 579 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4008 "src-generated/ugbc.tab.c"
    break;

  case 143: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 582 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4016 "src-generated/ugbc.tab.c"
    break;

  case 144: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 585 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4024 "src-generated/ugbc.tab.c"
    break;

  case 145: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 588 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4032 "src-generated/ugbc.tab.c"
    break;

  case 146: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 592 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4040 "src-generated/ugbc.tab.c"
    break;

  case 147: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 595 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4048 "src-generated/ugbc.tab.c"
    break;

  case 148: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 598 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4056 "src-generated/ugbc.tab.c"
    break;

  case 149: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 601 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4064 "src-generated/ugbc.tab.c"
    break;

  case 150: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 607 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4072 "src-generated/ugbc.tab.c"
    break;

  case 151: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 610 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4080 "src-generated/ugbc.tab.c"
    break;

  case 152: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 613 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4088 "src-generated/ugbc.tab.c"
    break;

  case 153: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 616 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4096 "src-generated/ugbc.tab.c"
    break;

  case 154: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 619 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4104 "src-generated/ugbc.tab.c"
    break;

  case 157: /* raster_definition_simple: Identifier AT direct_integer  */
#line 628 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 4112 "src-generated/ugbc.tab.c"
    break;

  case 158: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 631 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 4120 "src-generated/ugbc.tab.c"
    break;

  case 159: /* raster_definition_expression: Identifier AT expr  */
#line 636 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4128 "src-generated/ugbc.tab.c"
    break;

  case 160: /* raster_definition_expression: AT expr WITH Identifier  */
#line 639 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4136 "src-generated/ugbc.tab.c"
    break;

  case 163: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 648 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 4144 "src-generated/ugbc.tab.c"
    break;

  case 164: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 651 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 4152 "src-generated/ugbc.tab.c"
    break;

  case 165: /* next_raster_definition_expression: Identifier AT expr  */
#line 656 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 4160 "src-generated/ugbc.tab.c"
    break;

  case 166: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 659 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4168 "src-generated/ugbc.tab.c"
    break;

  case 169: /* color_definition_simple: BORDER direct_integer  */
#line 668 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 4176 "src-generated/ugbc.tab.c"
    break;

  case 170: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 671 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4184 "src-generated/ugbc.tab.c"
    break;

  case 171: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 674 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4192 "src-generated/ugbc.tab.c"
    break;

  case 172: /* color_definition_expression: BORDER expr  */
#line 679 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 4200 "src-generated/ugbc.tab.c"
    break;

  case 173: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 682 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4208 "src-generated/ugbc.tab.c"
    break;

  case 174: /* color_definition_expression: SPRITE expr TO expr  */
#line 685 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4216 "src-generated/ugbc.tab.c"
    break;

  case 180: /* wait_definition_simple: direct_integer CYCLES  */
#line 699 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4224 "src-generated/ugbc.tab.c"
    break;

  case 181: /* wait_definition_simple: direct_integer TICKS  */
#line 702 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4232 "src-generated/ugbc.tab.c"
    break;

  case 182: /* wait_definition_simple: direct_integer milliseconds  */
#line 705 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4240 "src-generated/ugbc.tab.c"
    break;

  case 183: /* wait_definition_expression: expr CYCLES  */
#line 710 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4248 "src-generated/ugbc.tab.c"
    break;

  case 184: /* wait_definition_expression: expr TICKS  */
#line 713 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4256 "src-generated/ugbc.tab.c"
    break;

  case 185: /* wait_definition_expression: expr milliseconds  */
#line 716 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4264 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 726 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4272 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 729 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4280 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 732 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4288 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 735 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4296 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 738 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4304 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_simple: direct_integer ENABLE  */
#line 741 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4312 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_simple: direct_integer DISABLE  */
#line 744 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4320 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 747 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4328 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 750 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4336 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 753 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4344 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 756 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4352 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 759 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4360 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 762 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4368 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 765 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4376 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 768 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4384 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_expression: expr DATA FROM expr  */
#line 773 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4392 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_expression: expr MULTICOLOR  */
#line 776 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4400 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_expression: expr MONOCOLOR  */
#line 779 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4408 "src-generated/ugbc.tab.c"
    break;

  case 206: /* sprite_definition_expression: expr COLOR expr  */
#line 782 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4416 "src-generated/ugbc.tab.c"
    break;

  case 207: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 785 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4424 "src-generated/ugbc.tab.c"
    break;

  case 208: /* sprite_definition_expression: expr ENABLE  */
#line 788 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4432 "src-generated/ugbc.tab.c"
    break;

  case 209: /* sprite_definition_expression: expr DISABLE  */
#line 791 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4440 "src-generated/ugbc.tab.c"
    break;

  case 210: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 794 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4448 "src-generated/ugbc.tab.c"
    break;

  case 211: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 797 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4456 "src-generated/ugbc.tab.c"
    break;

  case 212: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 800 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4464 "src-generated/ugbc.tab.c"
    break;

  case 213: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 803 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4472 "src-generated/ugbc.tab.c"
    break;

  case 214: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 806 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4480 "src-generated/ugbc.tab.c"
    break;

  case 215: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 809 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4488 "src-generated/ugbc.tab.c"
    break;

  case 216: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 812 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4496 "src-generated/ugbc.tab.c"
    break;

  case 217: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 815 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4504 "src-generated/ugbc.tab.c"
    break;

  case 220: /* bitmap_definition_simple: AT direct_integer  */
#line 824 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4512 "src-generated/ugbc.tab.c"
    break;

  case 221: /* bitmap_definition_simple: ENABLE  */
#line 827 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4520 "src-generated/ugbc.tab.c"
    break;

  case 222: /* bitmap_definition_simple: DISABLE  */
#line 830 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4528 "src-generated/ugbc.tab.c"
    break;

  case 223: /* bitmap_definition_simple: CLEAR  */
#line 833 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4536 "src-generated/ugbc.tab.c"
    break;

  case 224: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 836 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4544 "src-generated/ugbc.tab.c"
    break;

  case 225: /* bitmap_definition_expression: AT expr  */
#line 842 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4552 "src-generated/ugbc.tab.c"
    break;

  case 226: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 845 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4560 "src-generated/ugbc.tab.c"
    break;

  case 229: /* textmap_definition_simple: AT direct_integer  */
#line 855 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4568 "src-generated/ugbc.tab.c"
    break;

  case 230: /* textmap_definition_expression: AT expr  */
#line 860 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4576 "src-generated/ugbc.tab.c"
    break;

  case 233: /* text_definition_simple: ENABLE  */
#line 869 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4584 "src-generated/ugbc.tab.c"
    break;

  case 234: /* text_definition_simple: DISABLE  */
#line 872 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4592 "src-generated/ugbc.tab.c"
    break;

  case 235: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 877 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4600 "src-generated/ugbc.tab.c"
    break;

  case 236: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 880 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4608 "src-generated/ugbc.tab.c"
    break;

  case 239: /* tiles_definition_simple: AT direct_integer  */
#line 889 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4616 "src-generated/ugbc.tab.c"
    break;

  case 240: /* tiles_definition_expression: AT expr  */
#line 894 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4624 "src-generated/ugbc.tab.c"
    break;

  case 243: /* colormap_definition_simple: AT direct_integer  */
#line 903 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4632 "src-generated/ugbc.tab.c"
    break;

  case 244: /* colormap_definition_simple: CLEAR  */
#line 906 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4640 "src-generated/ugbc.tab.c"
    break;

  case 245: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 909 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4648 "src-generated/ugbc.tab.c"
    break;

  case 246: /* colormap_definition_expression: AT expr  */
#line 914 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4656 "src-generated/ugbc.tab.c"
    break;

  case 247: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 917 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4664 "src-generated/ugbc.tab.c"
    break;

  case 250: /* screen_definition_simple: ON  */
#line 927 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4672 "src-generated/ugbc.tab.c"
    break;

  case 251: /* screen_definition_simple: OFF  */
#line 930 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4680 "src-generated/ugbc.tab.c"
    break;

  case 252: /* screen_definition_simple: ROWS direct_integer  */
#line 933 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4688 "src-generated/ugbc.tab.c"
    break;

  case 253: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 936 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4696 "src-generated/ugbc.tab.c"
    break;

  case 254: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 939 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4704 "src-generated/ugbc.tab.c"
    break;

  case 255: /* screen_definition_expression: ROWS expr  */
#line 944 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4712 "src-generated/ugbc.tab.c"
    break;

  case 256: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 947 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4720 "src-generated/ugbc.tab.c"
    break;

  case 257: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 950 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4728 "src-generated/ugbc.tab.c"
    break;

  case 261: /* var_definition_simple: Identifier ON Identifier  */
#line 959 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4736 "src-generated/ugbc.tab.c"
    break;

  case 262: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 962 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4744 "src-generated/ugbc.tab.c"
    break;

  case 263: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 965 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4752 "src-generated/ugbc.tab.c"
    break;

  case 264: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 968 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4762 "src-generated/ugbc.tab.c"
    break;

  case 265: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 973 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4772 "src-generated/ugbc.tab.c"
    break;

  case 266: /* goto_definition: Identifier  */
#line 980 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4780 "src-generated/ugbc.tab.c"
    break;

  case 267: /* goto_definition: Integer  */
#line 983 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4788 "src-generated/ugbc.tab.c"
    break;

  case 268: /* gosub_definition: Identifier  */
#line 989 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4796 "src-generated/ugbc.tab.c"
    break;

  case 269: /* gosub_definition: Integer  */
#line 992 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4804 "src-generated/ugbc.tab.c"
    break;

  case 271: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 1001 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4812 "src-generated/ugbc.tab.c"
    break;

  case 272: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 1007 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4820 "src-generated/ugbc.tab.c"
    break;

  case 275: /* ink_definition: expr  */
#line 1016 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4828 "src-generated/ugbc.tab.c"
    break;

  case 276: /* on_goto_definition: Identifier  */
#line 1021 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4837 "src-generated/ugbc.tab.c"
    break;

  case 277: /* $@4: %empty  */
#line 1025 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4845 "src-generated/ugbc.tab.c"
    break;

  case 279: /* on_gosub_definition: Identifier  */
#line 1030 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4854 "src-generated/ugbc.tab.c"
    break;

  case 280: /* $@5: %empty  */
#line 1034 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4862 "src-generated/ugbc.tab.c"
    break;

  case 282: /* on_proc_definition: Identifier  */
#line 1039 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4871 "src-generated/ugbc.tab.c"
    break;

  case 283: /* $@6: %empty  */
#line 1043 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4879 "src-generated/ugbc.tab.c"
    break;

  case 285: /* $@7: %empty  */
#line 1048 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4887 "src-generated/ugbc.tab.c"
    break;

  case 287: /* $@8: %empty  */
#line 1051 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4895 "src-generated/ugbc.tab.c"
    break;

  case 289: /* $@9: %empty  */
#line 1054 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4903 "src-generated/ugbc.tab.c"
    break;

  case 291: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1059 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4911 "src-generated/ugbc.tab.c"
    break;

  case 292: /* every_definition: ON  */
#line 1062 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4919 "src-generated/ugbc.tab.c"
    break;

  case 293: /* every_definition: OFF  */
#line 1065 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4927 "src-generated/ugbc.tab.c"
    break;

  case 294: /* add_definition: Identifier COMMA expr  */
#line 1070 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4935 "src-generated/ugbc.tab.c"
    break;

  case 295: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1073 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4943 "src-generated/ugbc.tab.c"
    break;

  case 296: /* dimensions: Integer  */
#line 1079 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4952 "src-generated/ugbc.tab.c"
    break;

  case 297: /* dimensions: Integer COMMA dimensions  */
#line 1083 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4961 "src-generated/ugbc.tab.c"
    break;

  case 298: /* datatype: BYTE  */
#line 1090 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 4969 "src-generated/ugbc.tab.c"
    break;

  case 299: /* datatype: SIGNED BYTE  */
#line 1093 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 4977 "src-generated/ugbc.tab.c"
    break;

  case 300: /* datatype: WORD  */
#line 1096 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 4985 "src-generated/ugbc.tab.c"
    break;

  case 301: /* datatype: SIGNED WORD  */
#line 1099 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 4993 "src-generated/ugbc.tab.c"
    break;

  case 302: /* datatype: DWORD  */
#line 1102 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 5001 "src-generated/ugbc.tab.c"
    break;

  case 303: /* datatype: SIGNED DWORD  */
#line 1105 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 5009 "src-generated/ugbc.tab.c"
    break;

  case 304: /* datatype: ADDRESS  */
#line 1108 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 5017 "src-generated/ugbc.tab.c"
    break;

  case 305: /* datatype: POSITION  */
#line 1111 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 5025 "src-generated/ugbc.tab.c"
    break;

  case 306: /* datatype: COLOR  */
#line 1114 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 5033 "src-generated/ugbc.tab.c"
    break;

  case 307: /* datatype: STRING  */
#line 1117 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 5041 "src-generated/ugbc.tab.c"
    break;

  case 308: /* $@10: %empty  */
#line 1122 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5050 "src-generated/ugbc.tab.c"
    break;

  case 309: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1125 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 5060 "src-generated/ugbc.tab.c"
    break;

  case 310: /* $@11: %empty  */
#line 1130 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5069 "src-generated/ugbc.tab.c"
    break;

  case 311: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1133 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 5079 "src-generated/ugbc.tab.c"
    break;

  case 312: /* $@12: %empty  */
#line 1138 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5088 "src-generated/ugbc.tab.c"
    break;

  case 313: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1141 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 5098 "src-generated/ugbc.tab.c"
    break;

  case 316: /* indexes: expr  */
#line 1154 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5107 "src-generated/ugbc.tab.c"
    break;

  case 317: /* indexes: expr COMMA indexes  */
#line 1158 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5116 "src-generated/ugbc.tab.c"
    break;

  case 318: /* parameters: Identifier  */
#line 1165 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5126 "src-generated/ugbc.tab.c"
    break;

  case 319: /* parameters: Identifier DOLLAR  */
#line 1170 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5136 "src-generated/ugbc.tab.c"
    break;

  case 320: /* parameters: Identifier AS datatype  */
#line 1175 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5146 "src-generated/ugbc.tab.c"
    break;

  case 321: /* parameters: Identifier COMMA parameters  */
#line 1180 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5156 "src-generated/ugbc.tab.c"
    break;

  case 322: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1185 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5166 "src-generated/ugbc.tab.c"
    break;

  case 323: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1190 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5176 "src-generated/ugbc.tab.c"
    break;

  case 324: /* parameters_expr: Identifier  */
#line 1198 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5186 "src-generated/ugbc.tab.c"
    break;

  case 325: /* parameters_expr: Identifier DOLLAR  */
#line 1203 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5196 "src-generated/ugbc.tab.c"
    break;

  case 326: /* parameters_expr: Identifier AS datatype  */
#line 1208 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5206 "src-generated/ugbc.tab.c"
    break;

  case 327: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1213 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5216 "src-generated/ugbc.tab.c"
    break;

  case 328: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1218 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5226 "src-generated/ugbc.tab.c"
    break;

  case 329: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1223 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5236 "src-generated/ugbc.tab.c"
    break;

  case 330: /* parameters_expr: String  */
#line 1228 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5245 "src-generated/ugbc.tab.c"
    break;

  case 331: /* parameters_expr: String COMMA parameters_expr  */
#line 1232 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5254 "src-generated/ugbc.tab.c"
    break;

  case 332: /* values: expr  */
#line 1239 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5263 "src-generated/ugbc.tab.c"
    break;

  case 333: /* values: expr COMMA values  */
#line 1243 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5272 "src-generated/ugbc.tab.c"
    break;

  case 334: /* print_definition: expr  */
#line 1250 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5280 "src-generated/ugbc.tab.c"
    break;

  case 335: /* print_definition: expr COMMA  */
#line 1253 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5289 "src-generated/ugbc.tab.c"
    break;

  case 336: /* print_definition: expr SEMICOLON  */
#line 1257 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5297 "src-generated/ugbc.tab.c"
    break;

  case 337: /* $@13: %empty  */
#line 1260 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5306 "src-generated/ugbc.tab.c"
    break;

  case 339: /* $@14: %empty  */
#line 1264 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5314 "src-generated/ugbc.tab.c"
    break;

  case 341: /* use_definition: ANSI  */
#line 1270 "src/ugbc.y"
         {
        use_ansi( _environment );
    }
#line 5322 "src-generated/ugbc.tab.c"
    break;

  case 342: /* use_definition: SPECIFIC  */
#line 1273 "src/ugbc.y"
             {
        use_specific( _environment );
  }
#line 5330 "src-generated/ugbc.tab.c"
    break;

  case 343: /* writing_mode_definition: REPLACE  */
#line 1279 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5339 "src-generated/ugbc.tab.c"
    break;

  case 344: /* writing_mode_definition: OR  */
#line 1283 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5348 "src-generated/ugbc.tab.c"
    break;

  case 345: /* writing_mode_definition: XOR  */
#line 1287 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5357 "src-generated/ugbc.tab.c"
    break;

  case 346: /* writing_mode_definition: AND  */
#line 1291 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5366 "src-generated/ugbc.tab.c"
    break;

  case 347: /* writing_mode_definition: IGNORE  */
#line 1295 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5375 "src-generated/ugbc.tab.c"
    break;

  case 348: /* writing_part_definition: NORMAL  */
#line 1302 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5384 "src-generated/ugbc.tab.c"
    break;

  case 349: /* writing_part_definition: PAPER  */
#line 1306 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5393 "src-generated/ugbc.tab.c"
    break;

  case 350: /* writing_part_definition: PAPER ONLY  */
#line 1310 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5402 "src-generated/ugbc.tab.c"
    break;

  case 351: /* writing_part_definition: PEN  */
#line 1314 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5411 "src-generated/ugbc.tab.c"
    break;

  case 352: /* writing_part_definition: PEN ONLY  */
#line 1318 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5420 "src-generated/ugbc.tab.c"
    break;

  case 353: /* writing_definition: writing_mode_definition COMMA writing_part_definition  */
#line 1325 "src/ugbc.y"
                                                          {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5428 "src-generated/ugbc.tab.c"
    break;

  case 354: /* locate_definition: COMMA expr  */
#line 1331 "src/ugbc.y"
                {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 5436 "src-generated/ugbc.tab.c"
    break;

  case 355: /* locate_definition: expr COMMA  */
#line 1334 "src/ugbc.y"
                 {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 5444 "src-generated/ugbc.tab.c"
    break;

  case 356: /* locate_definition: expr COMMA expr  */
#line 1337 "src/ugbc.y"
                      {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5452 "src-generated/ugbc.tab.c"
    break;

  case 357: /* cmove_definition: COMMA expr  */
#line 1343 "src/ugbc.y"
                {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 5460 "src-generated/ugbc.tab.c"
    break;

  case 358: /* cmove_definition: expr COMMA  */
#line 1346 "src/ugbc.y"
                 {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 5468 "src-generated/ugbc.tab.c"
    break;

  case 359: /* cmove_definition: expr COMMA expr  */
#line 1349 "src/ugbc.y"
                      {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5476 "src-generated/ugbc.tab.c"
    break;

  case 379: /* statement: SET TAB expr  */
#line 1374 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 5484 "src-generated/ugbc.tab.c"
    break;

  case 380: /* statement: CENTER expr  */
#line 1377 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5492 "src-generated/ugbc.tab.c"
    break;

  case 381: /* statement: CENTRE expr  */
#line 1380 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5500 "src-generated/ugbc.tab.c"
    break;

  case 382: /* statement: CLS  */
#line 1383 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 5508 "src-generated/ugbc.tab.c"
    break;

  case 383: /* statement: HOME  */
#line 1386 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 5516 "src-generated/ugbc.tab.c"
    break;

  case 384: /* statement: INC Identifier  */
#line 1389 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 5524 "src-generated/ugbc.tab.c"
    break;

  case 385: /* statement: DEC Identifier  */
#line 1392 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 5532 "src-generated/ugbc.tab.c"
    break;

  case 386: /* statement: RANDOMIZE  */
#line 1395 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 5540 "src-generated/ugbc.tab.c"
    break;

  case 387: /* statement: RANDOMIZE expr  */
#line 1398 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 5548 "src-generated/ugbc.tab.c"
    break;

  case 388: /* statement: IF expr THEN  */
#line 1401 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5556 "src-generated/ugbc.tab.c"
    break;

  case 389: /* statement: ELSE  */
#line 1404 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 5564 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: ELSE IF expr THEN  */
#line 1407 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5572 "src-generated/ugbc.tab.c"
    break;

  case 391: /* statement: ENDIF  */
#line 1410 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5580 "src-generated/ugbc.tab.c"
    break;

  case 392: /* statement: DO  */
#line 1413 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5588 "src-generated/ugbc.tab.c"
    break;

  case 393: /* statement: LOOP  */
#line 1416 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5596 "src-generated/ugbc.tab.c"
    break;

  case 394: /* $@15: %empty  */
#line 1419 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5604 "src-generated/ugbc.tab.c"
    break;

  case 395: /* statement: WHILE $@15 expr  */
#line 1421 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5612 "src-generated/ugbc.tab.c"
    break;

  case 396: /* statement: WEND  */
#line 1424 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5620 "src-generated/ugbc.tab.c"
    break;

  case 397: /* statement: REPEAT  */
#line 1427 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5628 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statement: UNTIL expr  */
#line 1430 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5636 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: EXIT  */
#line 1433 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5644 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: EXIT PROC  */
#line 1436 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5652 "src-generated/ugbc.tab.c"
    break;

  case 401: /* statement: POP PROC  */
#line 1439 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5660 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: EXIT IF expr  */
#line 1442 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5668 "src-generated/ugbc.tab.c"
    break;

  case 403: /* statement: EXIT Integer  */
#line 1445 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5676 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: EXIT direct_integer  */
#line 1448 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5684 "src-generated/ugbc.tab.c"
    break;

  case 405: /* statement: EXIT IF expr COMMA Integer  */
#line 1451 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5692 "src-generated/ugbc.tab.c"
    break;

  case 406: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1454 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5700 "src-generated/ugbc.tab.c"
    break;

  case 407: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1457 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5708 "src-generated/ugbc.tab.c"
    break;

  case 408: /* statement: NEXT  */
#line 1460 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5716 "src-generated/ugbc.tab.c"
    break;

  case 409: /* statement: PROCEDURE Identifier  */
#line 1463 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5725 "src-generated/ugbc.tab.c"
    break;

  case 410: /* $@16: %empty  */
#line 1467 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5733 "src-generated/ugbc.tab.c"
    break;

  case 411: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1469 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5741 "src-generated/ugbc.tab.c"
    break;

  case 412: /* statement: SHARED parameters_expr  */
#line 1472 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5749 "src-generated/ugbc.tab.c"
    break;

  case 413: /* statement: GLOBAL parameters_expr  */
#line 1475 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5757 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: END PROC  */
#line 1478 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 5765 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: END PROC OSP expr CSP  */
#line 1481 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5773 "src-generated/ugbc.tab.c"
    break;

  case 416: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1484 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5781 "src-generated/ugbc.tab.c"
    break;

  case 417: /* statement: Identifier " "  */
#line 1487 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5790 "src-generated/ugbc.tab.c"
    break;

  case 418: /* statement: PROC Identifier  */
#line 1491 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5799 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: CALL Identifier  */
#line 1495 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5808 "src-generated/ugbc.tab.c"
    break;

  case 420: /* $@17: %empty  */
#line 1499 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5816 "src-generated/ugbc.tab.c"
    break;

  case 421: /* statement: Identifier OSP $@17 values CSP  */
#line 1501 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5824 "src-generated/ugbc.tab.c"
    break;

  case 422: /* $@18: %empty  */
#line 1504 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5832 "src-generated/ugbc.tab.c"
    break;

  case 423: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1506 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5840 "src-generated/ugbc.tab.c"
    break;

  case 424: /* $@19: %empty  */
#line 1509 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5848 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1511 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5856 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: PEN expr  */
#line 1514 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 5864 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: PAPER expr  */
#line 1517 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 5872 "src-generated/ugbc.tab.c"
    break;

  case 428: /* statement: INVERSE ON  */
#line 1520 "src/ugbc.y"
               {
      text_inverse( _environment, 1 );
  }
#line 5880 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: INVERSE OFF  */
#line 1523 "src/ugbc.y"
                {
      text_inverse( _environment, 0 );
  }
#line 5888 "src-generated/ugbc.tab.c"
    break;

  case 431: /* statement: Identifier COLON  */
#line 1527 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 5896 "src-generated/ugbc.tab.c"
    break;

  case 432: /* statement: BEG GAMELOOP  */
#line 1530 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 5904 "src-generated/ugbc.tab.c"
    break;

  case 433: /* statement: END GAMELOOP  */
#line 1533 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 5912 "src-generated/ugbc.tab.c"
    break;

  case 434: /* statement: GRAPHIC  */
#line 1536 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 5920 "src-generated/ugbc.tab.c"
    break;

  case 435: /* statement: HALT  */
#line 1539 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 5928 "src-generated/ugbc.tab.c"
    break;

  case 436: /* statement: END  */
#line 1542 "src/ugbc.y"
        {
      end( _environment );
  }
#line 5936 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: RETURN  */
#line 1549 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 5944 "src-generated/ugbc.tab.c"
    break;

  case 442: /* statement: RETURN expr  */
#line 1552 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 5952 "src-generated/ugbc.tab.c"
    break;

  case 443: /* statement: POP  */
#line 1555 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 5960 "src-generated/ugbc.tab.c"
    break;

  case 444: /* statement: DONE  */
#line 1558 "src/ugbc.y"
          {
      return 0;
  }
#line 5968 "src-generated/ugbc.tab.c"
    break;

  case 445: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1561 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5976 "src-generated/ugbc.tab.c"
    break;

  case 446: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1564 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5984 "src-generated/ugbc.tab.c"
    break;

  case 447: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1567 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 5992 "src-generated/ugbc.tab.c"
    break;

  case 448: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1570 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6000 "src-generated/ugbc.tab.c"
    break;

  case 451: /* statement: Identifier ASSIGN expr  */
#line 1575 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 6014 "src-generated/ugbc.tab.c"
    break;

  case 452: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1584 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 6028 "src-generated/ugbc.tab.c"
    break;

  case 453: /* $@20: %empty  */
#line 1593 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6037 "src-generated/ugbc.tab.c"
    break;

  case 454: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1597 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 6050 "src-generated/ugbc.tab.c"
    break;

  case 455: /* $@21: %empty  */
#line 1605 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6059 "src-generated/ugbc.tab.c"
    break;

  case 456: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1608 "src/ugbc.y"
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
#line 6078 "src-generated/ugbc.tab.c"
    break;

  case 457: /* $@22: %empty  */
#line 1622 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6087 "src-generated/ugbc.tab.c"
    break;

  case 458: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1625 "src/ugbc.y"
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
#line 6106 "src-generated/ugbc.tab.c"
    break;

  case 459: /* statement: DEBUG expr  */
#line 1639 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 6114 "src-generated/ugbc.tab.c"
    break;

  case 462: /* statements_no_linenumbers: statement  */
#line 1647 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 6120 "src-generated/ugbc.tab.c"
    break;

  case 463: /* $@23: %empty  */
#line 1648 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 6126 "src-generated/ugbc.tab.c"
    break;

  case 465: /* $@24: %empty  */
#line 1652 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 6134 "src-generated/ugbc.tab.c"
    break;

  case 466: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1654 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 6142 "src-generated/ugbc.tab.c"
    break;

  case 467: /* $@25: %empty  */
#line 1659 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 6150 "src-generated/ugbc.tab.c"
    break;

  case 473: /* $@26: %empty  */
#line 1669 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 6156 "src-generated/ugbc.tab.c"
    break;


#line 6160 "src-generated/ugbc.tab.c"

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

#line 1671 "src/ugbc.y"


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

