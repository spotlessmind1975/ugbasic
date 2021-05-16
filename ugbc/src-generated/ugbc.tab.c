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
  YYSYMBOL_BLACK = 181,                    /* BLACK  */
  YYSYMBOL_WHITE = 182,                    /* WHITE  */
  YYSYMBOL_RED = 183,                      /* RED  */
  YYSYMBOL_CYAN = 184,                     /* CYAN  */
  YYSYMBOL_VIOLET = 185,                   /* VIOLET  */
  YYSYMBOL_GREEN = 186,                    /* GREEN  */
  YYSYMBOL_BLUE = 187,                     /* BLUE  */
  YYSYMBOL_YELLOW = 188,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 189,                   /* ORANGE  */
  YYSYMBOL_BROWN = 190,                    /* BROWN  */
  YYSYMBOL_LIGHT = 191,                    /* LIGHT  */
  YYSYMBOL_DARK = 192,                     /* DARK  */
  YYSYMBOL_GREY = 193,                     /* GREY  */
  YYSYMBOL_GRAY = 194,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 195,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 196,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 197,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 198,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 199,                /* TURQUOISE  */
  YYSYMBOL_TAN = 200,                      /* TAN  */
  YYSYMBOL_PINK = 201,                     /* PINK  */
  YYSYMBOL_PEACH = 202,                    /* PEACH  */
  YYSYMBOL_OLIVE = 203,                    /* OLIVE  */
  YYSYMBOL_Identifier = 204,               /* Identifier  */
  YYSYMBOL_String = 205,                   /* String  */
  YYSYMBOL_Integer = 206,                  /* Integer  */
  YYSYMBOL_207_ = 207,                     /* " "  */
  YYSYMBOL_YYACCEPT = 208,                 /* $accept  */
  YYSYMBOL_expr = 209,                     /* expr  */
  YYSYMBOL_expr_math = 210,                /* expr_math  */
  YYSYMBOL_term = 211,                     /* term  */
  YYSYMBOL_modula = 212,                   /* modula  */
  YYSYMBOL_factor = 213,                   /* factor  */
  YYSYMBOL_direct_integer = 214,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 215, /* random_definition_simple  */
  YYSYMBOL_random_definition = 216,        /* random_definition  */
  YYSYMBOL_color_enumeration = 217,        /* color_enumeration  */
  YYSYMBOL_exponential = 218,              /* exponential  */
  YYSYMBOL_219_1 = 219,                    /* $@1  */
  YYSYMBOL_220_2 = 220,                    /* $@2  */
  YYSYMBOL_221_3 = 221,                    /* $@3  */
  YYSYMBOL_position = 222,                 /* position  */
  YYSYMBOL_bank_definition_simple = 223,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 224, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 225,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 226, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 227, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 228,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 229, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 230, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 231,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 232,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 233, /* color_definition_expression  */
  YYSYMBOL_color_definition = 234,         /* color_definition  */
  YYSYMBOL_milliseconds = 235,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 236,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 237, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 238,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 239, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 240, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 241,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 242, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 243, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 244,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 245, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 246, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 247,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 248,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 249, /* text_definition_expression  */
  YYSYMBOL_text_definition = 250,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 251,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 252, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 253,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 254, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 255, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 256,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 257, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 258, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 259,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 260,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 261,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 262,         /* gosub_definition  */
  YYSYMBOL_var_definition = 263,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 264,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 265, /* point_definition_expression  */
  YYSYMBOL_point_definition = 266,         /* point_definition  */
  YYSYMBOL_ink_definition = 267,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 268,       /* on_goto_definition  */
  YYSYMBOL_269_4 = 269,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 270,      /* on_gosub_definition  */
  YYSYMBOL_271_5 = 271,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 272,       /* on_proc_definition  */
  YYSYMBOL_273_6 = 273,                    /* $@6  */
  YYSYMBOL_on_definition = 274,            /* on_definition  */
  YYSYMBOL_275_7 = 275,                    /* $@7  */
  YYSYMBOL_276_8 = 276,                    /* $@8  */
  YYSYMBOL_277_9 = 277,                    /* $@9  */
  YYSYMBOL_every_definition = 278,         /* every_definition  */
  YYSYMBOL_add_definition = 279,           /* add_definition  */
  YYSYMBOL_dimensions = 280,               /* dimensions  */
  YYSYMBOL_datatype = 281,                 /* datatype  */
  YYSYMBOL_dim_definition = 282,           /* dim_definition  */
  YYSYMBOL_283_10 = 283,                   /* $@10  */
  YYSYMBOL_284_11 = 284,                   /* $@11  */
  YYSYMBOL_285_12 = 285,                   /* $@12  */
  YYSYMBOL_dim_definitions = 286,          /* dim_definitions  */
  YYSYMBOL_indexes = 287,                  /* indexes  */
  YYSYMBOL_parameters = 288,               /* parameters  */
  YYSYMBOL_parameters_expr = 289,          /* parameters_expr  */
  YYSYMBOL_values = 290,                   /* values  */
  YYSYMBOL_print_definition = 291,         /* print_definition  */
  YYSYMBOL_292_13 = 292,                   /* $@13  */
  YYSYMBOL_293_14 = 293,                   /* $@14  */
  YYSYMBOL_use_definition = 294,           /* use_definition  */
  YYSYMBOL_writing_mode_definition = 295,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 296,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 297,       /* writing_definition  */
  YYSYMBOL_locate_definition = 298,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 299,         /* cmove_definition  */
  YYSYMBOL_statement = 300,                /* statement  */
  YYSYMBOL_301_15 = 301,                   /* $@15  */
  YYSYMBOL_302_16 = 302,                   /* $@16  */
  YYSYMBOL_303_17 = 303,                   /* $@17  */
  YYSYMBOL_304_18 = 304,                   /* $@18  */
  YYSYMBOL_305_19 = 305,                   /* $@19  */
  YYSYMBOL_306_20 = 306,                   /* $@20  */
  YYSYMBOL_307_21 = 307,                   /* $@21  */
  YYSYMBOL_308_22 = 308,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 309, /* statements_no_linenumbers  */
  YYSYMBOL_310_23 = 310,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 311, /* statements_with_linenumbers  */
  YYSYMBOL_312_24 = 312,                   /* $@24  */
  YYSYMBOL_statements_complex = 313,       /* statements_complex  */
  YYSYMBOL_314_25 = 314,                   /* $@25  */
  YYSYMBOL_program = 315,                  /* program  */
  YYSYMBOL_316_26 = 316                    /* $@26  */
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
#define YYLAST   3111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  208
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  484
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  935

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   462


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
     205,   206,   207
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
    1437,  1440,  1443,  1446,  1449,  1449,  1454,  1457,  1460,  1463,
    1466,  1469,  1472,  1475,  1478,  1481,  1484,  1487,  1490,  1493,
    1497,  1497,  1502,  1505,  1508,  1511,  1514,  1517,  1521,  1525,
    1529,  1529,  1534,  1534,  1539,  1539,  1544,  1547,  1550,  1553,
    1556,  1557,  1560,  1563,  1566,  1569,  1572,  1575,  1576,  1577,
    1578,  1579,  1582,  1585,  1588,  1591,  1594,  1597,  1600,  1603,
    1604,  1605,  1614,  1623,  1623,  1635,  1635,  1652,  1652,  1669,
    1672,  1673,  1677,  1678,  1678,  1682,  1682,  1689,  1689,  1692,
    1693,  1694,  1695,  1699,  1699
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
  "CUP", "CDOWN", "CLEFT", "CRIGHT", "CLINE", "BLACK", "WHITE", "RED",
  "CYAN", "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE", "BROWN", "LIGHT",
  "DARK", "GREY", "GRAY", "MAGENTA", "PURPLE", "LAVENDER", "GOLD",
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
     455,   456,   457,   458,   459,   460,   461,   462
};
#endif

#define YYPACT_NINF (-802)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-464)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -802,    48,   883,  -802,  -802,  -153,  -136,   -15,  -802,    43,
    2152,    53,    12,  2152,  -802,    47,   206,  2535,   -80,  -113,
    -802,  -802,  -802,  1782,   150,     9,  2535,  2535,    81,   -47,
    -802,   145,   153,  2535,  2535,  -802,   166,   195,   -93,  2535,
      99,   136,  -802,   -37,  -802,  2535,    49,  1967,   212,    52,
    2535,    65,    75,    77,    83,    25,    25,  2535,    66,  2535,
     220,   -17,  1212,  -802,  -802,  1412,  2535,  2535,   117,  -802,
    -802,  -802,  -802,  2535,     8,  -802,   283,   297,   307,  -802,
    -802,  -802,  2152,   289,  -802,  -802,  -802,  2152,  2152,  2152,
    -802,  -802,  -802,   112,   300,  1597,  -802,  -802,   288,   294,
     301,   183,   130,  -802,  -802,     6,   303,   304,  2535,  -802,
    -802,   305,   306,   309,   329,   330,   331,   332,   333,   334,
     336,   338,   341,   342,   343,   344,   345,   346,  -802,  -802,
     347,   144,   -45,    14,   351,   363,   364,   365,   366,   367,
     369,  -802,  -802,  -802,  -802,  -802,  -802,  -802,   204,  -802,
    -802,    10,  -129,  -802,  -802,  -802,  -802,  -802,  -802,  -802,
    -802,  -802,   209,    26,  -802,  -802,   -14,   224,   262,   216,
     267,    60,  -802,  -802,  -802,  -802,  -802,    -9,   315,    -5,
      -4,    -2,     3,   374,  -802,  -802,  -802,   258,   337,  -802,
    -802,  -802,  2152,  -802,  -802,   370,  -802,  -802,  -802,  -802,
    -802,  2152,   354,   355,  -802,  -802,  -802,    -3,  -802,    39,
    -802,  -802,  -802,  -802,  -802,  2535,  2350,  -802,  -802,   400,
    -802,  -802,  -802,  2152,  -802,  -802,  -802,  2152,   379,  -802,
    -802,  -802,   340,  -802,  -802,  -802,   264,  2535,  2535,  -802,
    -802,  2152,  -802,  -802,  -802,   378,  -802,  -802,  -802,  -802,
    -802,  -802,  -802,  -802,  2535,  2535,  -802,  -802,  -802,  -802,
     401,  -802,  -802,   263,  -802,  2535,   409,  -802,  -802,  -802,
      42,   410,  -802,   271,   272,   273,    80,   414,  -802,  -802,
     247,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,
    -802,  -802,  -802,   415,  -802,  2535,   416,  -802,  2535,   417,
    -802,  -802,  -802,  2535,  -802,  -802,  -802,  2535,   412,  -802,
    -802,   393,    45,  1054,  -802,   883,   883,   399,   402,  2152,
    -802,  -802,   357,   358,   360,   361,  -802,   403,   404,   405,
     406,   407,   408,   101,   411,  2152,  2152,  2152,  -802,  -802,
    -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,   413,  -802,
    -802,  2535,  2535,  -802,  2535,  2535,  2535,  2535,  2535,  2535,
    2535,  2535,  2535,  2535,  2535,  2535,  2535,  2535,  2535,  2535,
    2535,  2720,   418,   230,  -802,  -802,   423,  -802,  -802,   424,
     425,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,
    -802,  -802,  -802,  -802,   426,  -802,   427,  -802,  -802,  -802,
    -802,  -802,  -802,  2720,  2720,  2720,  2720,  2720,  2720,  2720,
    2720,  2720,  2720,  2720,  2720,  2720,  2905,  -802,  -802,  -802,
    2152,   420,  -802,  -802,  -802,   387,   315,   421,   315,   438,
     315,   440,   315,   441,   315,  -802,  2535,   433,  -802,  -802,
     208,   243,   127,   147,  -802,  -802,  -802,   435,   315,   434,
    -802,  -802,   249,   251,   164,   180,  -802,  -802,   437,  -802,
    -802,  2152,  -802,  -802,  2152,  2152,  -802,  -802,  -802,   394,
     234,  -802,   442,  2535,  -802,  -802,  -802,  -802,  2152,  -802,
    2535,   443,   465,  -802,  -802,  2152,   419,   466,  2535,   372,
     469,  2535,  -802,  -802,  -802,  -802,  -802,  -802,   109,  -802,
    -802,   445,   428,    65,  -802,   335,  -802,    25,   470,    45,
      25,   280,   298,   -56,  -802,  2535,  -802,  2535,  -802,   883,
    -802,  2535,   446,  2535,  2535,   449,    19,  -802,  1054,  -802,
    -802,   281,   282,  -802,  -802,  2535,   315,  2535,   315,  2535,
     278,   284,   285,   286,   287,   452,   459,   461,  -802,   463,
     467,   471,   473,   474,   475,  2535,   493,   497,   505,   507,
     480,   481,   483,   484,   513,   486,   487,   488,   489,   491,
     521,   524,   500,   501,   502,    31,   328,   503,  2535,  2535,
    2535,   506,  2535,  2535,   262,   262,   308,   308,   308,   308,
     308,   308,   308,   308,   216,   267,   267,  -802,   510,   512,
    2152,    54,  -802,   315,  -802,   315,  -802,   315,  -802,   315,
     119,  -802,  2535,  -802,  -802,  -802,  -802,  -802,  -802,  -802,
    -802,  2535,  -802,   315,  -802,  -802,  -802,  -802,  -802,  -802,
    -802,  -802,   315,  -802,  -802,  -802,  -802,  -802,  -802,   339,
     348,   349,   352,   529,  2535,   537,   508,   509,   429,  2535,
    2535,   541,   542,  -802,   -64,   485,   356,  2535,   548,  -802,
    -802,  -802,   525,   359,   527,  -802,  2535,   362,  2535,  -802,
      25,   551,  -802,  2535,  2535,   395,   396,  -802,  -802,  -802,
    -802,  -802,  -802,  2535,   557,   430,   560,   536,  2535,  -802,
    -802,  -802,  -802,  -802,  -802,  -802,   566,  -802,  -802,  -802,
    -802,  -802,   368,   373,   375,  -802,  -802,  -802,  -802,  -802,
    -802,   540,  2535,  2535,  2535,  2535,  -802,  -802,  -802,  -802,
    2535,  -802,  -802,  -802,  -802,  -802,  2535,  2535,  -802,  -802,
    -802,  2905,   545,  -802,   547,   569,   576,  2535,   436,   550,
     382,   383,  -802,  -802,  -802,  -802,  -802,  -802,   559,  -802,
     562,  -802,   384,    76,  -802,   585,  -802,   586,   587,  -802,
     588,  -802,   589,  -802,   584,  2152,   591,  2535,  2535,   315,
    -802,   564,   565,  2535,   315,  -802,  -802,  2535,  -802,    88,
    2535,   359,   594,   568,   359,   456,   115,   458,   460,  -802,
      25,  -802,  -802,  -802,  -802,   574,  2535,  -802,  2535,   597,
     577,  2535,  -802,  -802,  -802,  -802,   578,   579,    94,   126,
     580,   582,   583,   590,  -802,  -802,  2535,  2535,   592,  -802,
    -802,  -802,  -802,   431,   432,  -802,   593,  -802,   595,  -802,
    2535,   315,   612,   613,   614,  2535,  -802,  -802,  2535,  -802,
    -802,  -802,   610,   615,   596,   598,   511,  2535,   616,   558,
     600,   359,  -802,   603,  -802,   362,   625,    45,  -802,  -802,
    -802,   628,  -802,  -802,  2535,   629,   608,  -802,  -802,  2535,
    -802,  2535,  -802,  -802,  -802,  -802,  -802,   609,   611,  -802,
    -802,  -802,   444,   447,   618,   619,   339,   348,   349,  -802,
    -802,  2535,  2535,  -802,  -802,  2535,   620,  2535,  2535,  -802,
    -802,  -802,  -802,   362,   638,  2535,  -802,  2535,  -802,   622,
     624,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,
    -802,  -802,  -802,   635,  -802,  -802,  -802,   362,  -802,  -802,
    -802,  -802,  2535,  -802,  -802
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     483,     0,   471,     1,   470,     0,     0,     0,   454,     0,
       0,   418,     0,     0,   445,     0,     0,     0,   264,     0,
     403,   407,   404,     0,     0,     0,     0,     0,     0,   446,
     401,     0,     0,     0,   396,   444,     0,     0,     0,   451,
     453,   399,   402,   409,   406,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   392,   393,     0,     0,     0,     0,   383,
     384,   385,   386,   387,   467,   475,   472,   479,   481,   484,
     394,   395,     0,     0,   165,   166,   365,     0,     0,     0,
     179,   180,   367,     0,     0,     0,    79,    80,     0,     0,
       0,     0,     0,   121,   122,     0,     0,     0,     0,   112,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,    44,    49,    50,    51,    52,    53,    54,
      57,    58,     0,    63,    67,    65,     0,     2,    12,    15,
      17,     0,    76,    20,   190,   191,   368,     0,     0,     0,
       0,     0,     0,     0,   159,   160,   364,     0,     0,   222,
     223,   369,     0,   225,   226,   227,   231,   232,   370,   254,
     255,     0,     0,     0,   262,   263,   375,     0,   447,     0,
     274,   378,   270,   271,   448,     0,     0,   237,   238,     0,
     241,   242,   372,     0,   245,   246,   373,     0,   248,   252,
     253,   374,     0,   436,   442,   443,   424,     0,     0,   469,
     397,     0,   235,   236,   371,     0,   277,   278,   376,   272,
     273,   449,   452,   411,     0,     0,   410,   413,   414,   408,
       0,   296,   297,     0,   450,     0,     0,   379,   279,   377,
     312,   318,   459,   428,   419,   429,   328,   334,   422,   423,
     338,   380,   346,   345,   460,   437,   438,   439,   350,   348,
     347,   349,   351,     0,   440,     0,     0,   381,     0,     0,
     382,   390,   391,     0,   388,   477,   441,     0,   465,   430,
     427,     0,     0,   471,   473,   471,   471,     0,     0,     0,
     176,   173,     0,     0,     0,     0,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    24,
      25,    27,    29,    30,    26,    31,   101,    23,     0,   115,
     116,     0,     0,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   120,     0,   118,   119,     0,
       0,   133,   127,   128,   129,   130,    55,    42,    45,    46,
      47,    48,    43,    56,    64,   108,     0,   181,   187,   182,
     183,   188,   189,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   184,   185,   186,
       0,     0,   171,   172,   366,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   135,     0,     0,   212,   213,
       0,     0,     0,     0,   209,   208,   134,     0,     0,     0,
     197,   198,     0,     0,     0,     0,   194,   193,     0,   229,
     224,     0,   259,   256,     0,     0,   289,   293,   291,     0,
       0,   405,     0,     0,   244,   243,   250,   247,     0,   398,
       0,     0,     0,   234,   233,     0,     0,   412,     0,     0,
       0,     0,   310,   302,   304,   309,   306,   311,     0,   308,
     316,     0,     0,     0,   432,     0,   434,     0,   329,     0,
       0,   343,   341,     0,   358,   359,   361,   362,   389,   471,
     461,     0,     0,     0,     0,     0,   467,   476,   471,   480,
     482,     0,     0,   163,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    14,     5,     7,     8,     9,
      10,     6,     3,     4,    16,    18,    19,    21,     0,     0,
       0,     0,   141,     0,   153,     0,   145,     0,   149,     0,
     137,   210,     0,   217,   216,   221,   220,   215,   219,   214,
     218,     0,   195,     0,   202,   201,   206,   205,   200,   204,
     199,   203,     0,   230,   228,   260,   257,   261,   258,     0,
       0,     0,     0,   265,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   400,     0,     0,     0,     0,   298,   303,
     305,   307,     0,     0,     0,   319,     0,     0,     0,   331,
       0,   330,   335,     0,     0,   355,   353,   352,   357,   360,
     363,   478,   462,     0,   336,     0,   320,     0,     0,   474,
     164,   162,   178,   175,   177,   174,     0,    75,    68,    70,
      74,    72,     0,     0,     0,    78,    77,    82,    81,    84,
      83,     0,     0,     0,     0,     0,    91,    92,    93,   100,
       0,    94,    95,    96,    97,    98,     0,     0,   110,   111,
     102,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   167,   138,   151,   143,   146,   140,   152,
     144,   148,     0,     0,   207,     0,   192,     0,   280,   290,
     283,   294,   286,   292,   266,     0,     0,     0,     0,     0,
     425,     0,     0,     0,     0,   415,   416,     0,   295,     0,
       0,     0,   300,     0,     0,     0,   322,     0,     0,   332,
       0,   344,   342,   356,   354,     0,     0,   431,     0,     0,
       0,     0,    69,    71,    73,   124,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   125,     0,     0,     0,   109,
      60,   170,   168,     0,     0,   154,   139,   150,   142,   147,
       0,     0,     0,     0,     0,     0,   268,   267,     0,   240,
     251,   249,     0,     0,     0,     0,   417,     0,     0,     0,
       0,     0,   313,     0,   433,     0,   323,     0,   421,   435,
     333,     0,   337,   321,     0,     0,     0,    85,    86,     0,
      87,     0,    89,    99,   105,   104,    22,     0,     0,    62,
     156,   158,     0,     0,     0,     0,     0,     0,     0,   269,
     239,     0,     0,   276,   275,     0,     0,     0,     0,   317,
     301,   315,   325,     0,   324,     0,   464,     0,   131,     0,
       0,   132,   126,   155,   157,   211,   196,   282,   285,   288,
     455,   456,   426,     0,   457,   299,   326,     0,   466,   468,
      88,    90,     0,   327,   458
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -802,   -10,  -134,   -73,   237,  -265,    69,  -802,  -802,  -802,
    -412,  -802,  -802,  -802,   472,  -802,  -802,  -802,  -802,  -802,
    -802,  -802,  -802,  -802,  -802,  -802,  -802,   490,  -802,  -802,
    -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,
    -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,
    -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,
    -235,  -802,  -225,  -802,  -223,  -802,  -802,  -802,  -802,  -802,
    -802,  -802,  -708,  -311,  -802,  -802,  -802,  -802,   163,  -578,
    -801,   -54,  -574,  -341,  -802,  -802,  -802,  -802,  -802,  -802,
    -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,  -802,
    -802,  -307,  -802,  -802,  -802,  -305,  -802,  -802,  -802
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   686,   167,   168,   169,   170,   171,   345,   346,   172,
     173,   396,   581,   582,   447,   184,   185,   186,    84,    85,
      86,   422,   423,   424,    90,    91,    92,   402,   174,   175,
     176,   189,   190,   191,   196,   197,   198,   242,   243,   244,
     220,   221,   222,   224,   225,   226,   229,   230,   231,   204,
     205,   206,   210,   214,   251,   211,   246,   247,   248,   269,
     759,   832,   761,   833,   763,   834,   208,   639,   641,   640,
     264,   267,   783,   500,   271,   501,   502,   662,   272,   687,
     787,   278,   685,   281,   674,   673,   284,   293,   678,   294,
     297,   300,    76,   215,   505,   523,   666,   668,   311,   522,
     312,    77,   528,    78,   313,    79,   519,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     166,   525,   279,   187,   597,   739,   527,   207,   738,    82,
     529,   530,   305,   219,   306,   420,   232,   233,   102,   426,
     428,   307,   430,   239,   240,   306,   348,   432,   308,   252,
     675,   255,   307,   227,   376,   259,   178,   263,   731,   308,
     268,   374,  -463,   235,   179,   102,   394,   280,     3,   285,
     466,    80,   296,  -463,   902,   299,   301,   302,   391,   469,
     -59,   180,  -314,   304,   392,   397,   398,   492,    81,    87,
     492,   192,   317,   850,    88,   177,   853,   320,   322,   324,
     288,   470,   188,   193,   194,   334,   744,   507,   289,   181,
     182,   212,   785,   213,   788,   847,   228,   236,   353,   467,
     508,   869,   926,   745,   676,   795,   575,   256,   826,   677,
     800,   249,   258,   250,    89,   375,   493,   494,   495,   493,
     494,   495,   855,   848,   209,   827,   933,   496,   509,   870,
     496,   746,   747,   871,   195,   856,   399,   400,   401,   397,
     417,   468,   775,   900,   349,   290,   291,   292,   752,   595,
     596,   318,   377,   828,   829,   309,   321,   323,   325,   818,
     416,   872,   350,   857,   372,   497,   309,   753,   497,   257,
     378,   234,   617,   395,   223,   545,   546,   498,   373,   237,
     498,   618,   459,   659,   660,   499,   547,   238,   499,    83,
     241,   462,   619,   387,   661,   421,   388,   389,   671,   427,
     429,   620,   431,   390,   254,   471,   472,   433,   338,   628,
     399,   400,   418,   474,   681,   310,   183,   476,   629,   245,
     863,   689,   862,   282,   283,   630,   310,   481,   482,   276,
     277,   483,   403,   404,   631,   414,   405,   415,   406,   407,
     408,   409,   410,   253,   486,   487,   265,   425,   199,   200,
     201,   202,   511,   260,   512,   490,   266,   339,   340,   341,
     203,   460,   286,   287,   613,   614,   342,   343,   344,   270,
     463,   586,   587,   588,   589,   590,   591,   592,   593,   273,
    -340,   274,   435,   436,  -340,   514,  -340,   275,   516,   314,
     437,   303,   475,   518,   438,   439,   477,   520,  -339,   615,
     616,   315,  -339,   440,  -339,   624,   625,   626,   627,   533,
     484,   316,   441,   319,   442,   443,   403,   404,   326,   813,
     327,   411,   335,   444,   445,   549,   551,   553,   336,   412,
     584,   585,   791,   792,   446,   337,   347,   351,   352,   354,
     355,   556,   557,   356,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   435,   448,   357,   358,   359,   360,   361,   362,   449,
     363,   379,   364,   450,   451,   365,   366,   367,   368,   369,
     370,   371,   452,   380,   381,   382,   383,   384,   534,   385,
     386,   453,   413,   454,   455,   393,   416,   102,   434,   461,
     464,   465,   456,   457,   550,   552,   554,   473,   478,   479,
     598,   480,   485,   446,   488,   489,   491,   503,   504,  -420,
     506,   510,   513,   515,   517,   521,   611,   524,   531,   535,
     536,   532,   537,   538,   577,   601,   642,   539,   643,   540,
     541,   542,   543,   544,   600,   603,   548,   555,   664,   644,
     649,   633,   576,   669,   635,   637,   672,   578,   579,   580,
     -61,   583,   605,   645,   607,   609,   612,   623,   646,   621,
     648,   632,   650,   654,   656,   651,   657,   670,   655,   663,
     683,   658,   667,   688,   697,   690,   691,   702,   653,   599,
     698,   699,   700,   701,   703,   602,   704,   604,   705,   606,
     712,   608,   706,   610,   713,   679,   707,   680,   708,   709,
     710,   682,   714,   684,   715,   716,   717,   622,   718,   719,
     720,   721,   722,   723,   724,   692,   725,   694,   726,   696,
     634,   727,   732,   636,   638,   728,   729,   730,   733,   740,
     737,   741,   765,   758,   767,   711,   904,   647,   773,   774,
     768,   769,   760,   762,   652,   780,   764,   777,   790,   781,
     778,   784,   793,   794,   796,   782,   786,   798,   734,   735,
     736,   799,   684,   801,   802,   805,   816,   770,   797,   803,
     814,   804,   815,   817,   819,   820,   821,   822,   823,   825,
     742,   824,   830,   831,  -281,  -284,  -287,   835,   838,   842,
     843,   851,   754,   852,   854,   693,   858,   695,   859,   861,
     864,   755,   865,   867,   868,   873,   789,   874,   875,   886,
     887,   888,   882,   891,   883,   876,   895,   879,   892,   897,
     898,   893,   903,   894,   766,   899,   880,   881,   901,   771,
     772,   905,   907,   908,   911,   927,   912,   779,   932,   913,
     594,   917,   914,   915,   916,   923,   684,   930,   684,   931,
     458,   419,   918,   280,   280,   919,   665,     0,     0,   743,
       0,     0,   748,     0,   749,     0,   750,     0,   751,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   756,     0,     0,     0,     0,     0,     0,     0,
       0,   757,   806,   807,   808,   809,     0,     0,     0,     0,
     810,     0,     0,     0,     0,     0,   811,   812,     0,     0,
       0,     0,     0,   776,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   860,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   836,     0,   839,   840,     0,
       0,     0,     0,   844,     0,     0,     0,   846,     0,     0,
     849,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   684,     0,     0,     0,
       0,   866,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   877,   878,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     884,     0,     0,     0,     0,   889,     0,     0,   890,     0,
       0,     0,     0,     0,   837,     0,     0,   896,   841,     0,
       0,     0,     0,   845,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   906,     0,     0,     0,     0,   909,
       0,   910,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   920,   921,     0,     0,   922,     4,   924,   925,     0,
       0,     0,     0,     5,     6,   928,     0,   929,     0,     0,
     885,     0,     0,     0,     0,     7,     8,     0,     9,     0,
      10,    11,     0,    12,    13,     0,     0,     0,     0,     0,
       0,    14,   934,    15,    16,    17,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,    28,    29,     0,    30,     0,     0,    31,    32,    33,
       0,    34,    35,    36,    37,    38,    39,    40,     0,    41,
       0,     0,     0,    42,    43,    44,    45,    46,     0,    47,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,     0,    50,     0,     0,    51,     0,    52,    53,    54,
       0,     0,    55,     0,     0,     0,    56,     0,    57,     0,
       0,     0,    58,    59,    60,     0,     0,     0,     0,    61,
       0,    62,    63,    64,    65,    66,    67,     4,    68,    69,
      70,    71,    72,    73,     5,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     9,
       0,    10,    11,     0,    12,    13,     0,    74,     0,    75,
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
       0,     0,     0,    58,    59,    60,     0,     0,     0,   295,
      61,    93,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,     0,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   526,     0,
       0,     0,    96,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
       0,     0,   100,     0,     0,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,     0,   105,     0,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,     0,   132,     0,
       0,     0,   133,     0,     0,     0,     0,     0,     0,     0,
     134,     0,     0,   135,     0,     0,   136,     0,   137,   138,
     139,   140,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,     0,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   298,
       0,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
       0,     0,   100,     0,     0,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,     0,   105,     0,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,     0,   132,     0,
       0,     0,   133,     0,     0,     0,     0,     0,     0,     0,
     134,     0,     0,   135,     0,     0,   136,     0,   137,   138,
     139,   140,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    93,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,     0,
       0,    94,   328,     0,     0,     0,     0,     0,     0,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,   100,     0,     0,
     101,   329,   330,   331,     0,     0,     0,     0,     0,     0,
     103,   104,   332,   105,     0,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   109,   110,     0,     0,     0,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     0,     0,     0,   123,
     124,   125,   333,   126,   127,   128,     0,   129,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,     0,   132,     0,     0,     0,   133,     0,     0,
       0,     0,     0,     0,     0,   134,     0,     0,   135,     0,
       0,   136,     0,   137,   138,   139,   140,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,    93,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,     0,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,     0,   217,   218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
       0,     0,   100,     0,     0,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,     0,   105,     0,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,     0,   132,     0,
       0,     0,   133,     0,     0,     0,     0,     0,     0,     0,
     134,     0,     0,   135,     0,     0,   136,     0,   137,   138,
     139,   140,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    93,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,     0,
       0,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,   261,
     262,     0,     0,     0,     0,     0,     0,    96,    97,    98,
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
     153,    93,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,     0,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
       0,     0,   100,     0,     0,   101,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,     0,   105,     0,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,     0,   132,     0,
       0,     0,   133,     0,     0,     0,     0,     0,     0,     0,
     134,     0,     0,   135,     0,     0,   136,     0,   137,   138,
     139,   140,     0,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,     0,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     327,     0,     0,     0,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,     0,     0,     0,     0,     0,
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
     150,   151,   152,   153,    93,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,     0,     0,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,     0,     0,   100,     0,     0,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,   104,
       0,   105,     0,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,   109,   110,     0,     0,     0,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,     0,     0,   123,   124,   125,
       0,   126,   127,   128,     0,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
       0,   132,     0,     0,     0,   133,     0,     0,     0,     0,
       0,     0,     0,   134,     0,     0,   135,     0,     0,   136,
       0,   137,   138,   139,   140,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,    93,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     0,     0,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,     0,     0,
     100,     0,     0,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,     0,   105,     0,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
       0,     0,     0,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
       0,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,     0,   132,     0,     0,     0,
     133,     0,     0,     0,     0,     0,     0,     0,   134,     0,
       0,   135,     0,     0,   136,     0,   137,   138,   139,   140,
       0,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    93,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,     0,     0,    94,
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
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165
};

static const yytype_int16 yycheck[] =
{
      10,   312,    56,    13,   416,   583,   313,    17,   582,    24,
     315,   316,     4,    23,     6,    24,    26,    27,    82,    24,
      24,    13,    24,    33,    34,     6,    20,    24,    20,    39,
      86,    68,    13,    24,    20,    45,    24,    47,     7,    20,
      50,    86,    34,    90,    32,    82,    20,    57,     0,    59,
      53,   204,    62,    34,   855,    65,    66,    67,   187,    20,
      34,    49,    20,    73,   193,    79,    80,    25,   204,    26,
      25,    24,    82,   781,    31,    22,   784,    87,    88,    89,
      97,    42,    13,    36,    37,    95,    32,     7,   105,    77,
      78,   204,   666,   206,   668,     7,    87,   144,   108,   102,
      20,     7,   903,    49,   160,   683,   371,   144,    32,   165,
     688,   204,    43,   206,    71,   160,    74,    75,    76,    74,
      75,    76,     7,    35,   204,    49,   927,    85,    48,    35,
      85,    77,    78,     7,    87,    20,   150,   151,   152,    79,
      80,   144,   206,   851,   138,   162,   163,   164,    29,   414,
     415,    82,   138,    77,    78,   147,    87,    88,    89,   737,
     129,    35,   156,    48,    20,   123,   147,    48,   123,   206,
     156,    90,    45,   147,    24,    74,    75,   135,    34,    34,
     135,    54,   192,    74,    75,   143,    85,    34,   143,   204,
      24,   201,    45,   183,    85,   204,   186,   187,   509,   204,
     204,    54,   204,   193,    68,   215,   216,   204,    25,    45,
     150,   151,   152,   223,   519,   207,   204,   227,    54,    24,
     798,   528,   796,   157,   158,    45,   207,   237,   238,   204,
     205,   241,     8,     9,    54,    19,    12,    21,    14,    15,
      16,    17,    18,   144,   254,   255,    34,   178,    42,    43,
      44,    45,     5,   204,     7,   265,   204,    74,    75,    76,
      54,   192,    42,    43,    56,    57,    83,    84,    85,   204,
     201,   405,   406,   407,   408,   409,   410,   411,   412,   204,
       0,   204,    24,    25,     4,   295,     6,   204,   298,     6,
      32,   174,   223,   303,    36,    37,   227,   307,     0,    56,
      57,     4,     4,    45,     6,    56,    57,    56,    57,   319,
     241,     4,    54,    24,    56,    57,     8,     9,   206,   731,
      20,    97,    34,    65,    66,   335,   336,   337,    34,   105,
     403,   404,   673,   674,    76,    34,   206,    34,    34,    34,
      34,   351,   352,    34,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,    24,    25,    34,    34,    34,    34,    34,    34,    32,
      34,    20,    34,    36,    37,    34,    34,    34,    34,    34,
      34,    34,    45,    20,    20,    20,    20,    20,   319,    20,
     186,    54,   130,    56,    57,   186,   129,    82,    24,    29,
      46,    46,    65,    66,   335,   336,   337,     7,    29,    69,
     420,   147,    34,    76,    13,   152,     7,     7,   147,   147,
     147,     7,     7,     7,     7,    13,   436,    34,    29,    72,
      72,    29,    72,    72,   204,    48,    42,    34,   204,    35,
      35,    35,    35,    35,    24,    24,    35,    34,    20,     7,
       7,   461,    34,   507,   464,   465,   510,    34,    34,    34,
      34,    34,    24,   473,    24,    24,    33,    33,   478,    34,
     480,    34,     7,     7,   102,   485,     7,     7,   488,    34,
      34,   491,   147,    34,   206,   204,   204,    35,    69,   420,
     206,   206,   206,   206,    35,   426,    35,   428,    35,   430,
       7,   432,    35,   434,     7,   515,    35,   517,    35,    35,
      35,   521,     7,   523,     7,    35,    35,   448,    35,    35,
       7,    35,    35,    35,    35,   535,    35,   537,     7,   539,
     461,     7,   204,   464,   465,    35,    35,    35,    35,    29,
      34,    29,    13,   204,     7,   555,   857,   478,     7,     7,
      42,    42,   204,   204,   485,     7,   204,    72,     7,    34,
     204,    34,   167,   167,     7,   206,   204,     7,   578,   579,
     580,    35,   582,     7,   206,    35,     7,   148,   148,   206,
      35,   206,    35,     7,   148,    35,   204,   204,    29,   205,
     600,    29,     7,     7,     7,     7,     7,    13,     7,    35,
      35,     7,   612,    35,   148,   536,   148,   538,   148,    35,
      13,   621,    35,    35,    35,    35,   670,    35,    35,     7,
       7,     7,    29,    13,    29,    35,   115,    35,    13,    13,
      72,    35,     7,    35,   644,    35,   205,   205,    35,   649,
     650,    13,    13,    35,    35,     7,    35,   657,    13,   205,
     413,   886,   205,    35,    35,    35,   666,    35,   668,    35,
     188,   171,   887,   673,   674,   888,   503,    -1,    -1,   600,
      -1,    -1,   603,    -1,   605,    -1,   607,    -1,   609,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   632,   712,   713,   714,   715,    -1,    -1,    -1,    -1,
     720,    -1,    -1,    -1,    -1,    -1,   726,   727,    -1,    -1,
      -1,    -1,    -1,   654,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   790,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   765,    -1,   767,   768,    -1,
      -1,    -1,    -1,   773,    -1,    -1,    -1,   777,    -1,    -1,
     780,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   796,    -1,    -1,    -1,
      -1,   801,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   816,   817,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     830,    -1,    -1,    -1,    -1,   835,    -1,    -1,   838,    -1,
      -1,    -1,    -1,    -1,   765,    -1,    -1,   847,   769,    -1,
      -1,    -1,    -1,   774,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   864,    -1,    -1,    -1,    -1,   869,
      -1,   871,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   891,   892,    -1,    -1,   895,     3,   897,   898,    -1,
      -1,    -1,    -1,    10,    11,   905,    -1,   907,    -1,    -1,
     831,    -1,    -1,    -1,    -1,    22,    23,    -1,    25,    -1,
      27,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,   932,    40,    41,    42,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    88,    89,    -1,    91,    -1,    -1,    94,    95,    96,
      -1,    98,    99,   100,   101,   102,   103,   104,    -1,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,    -1,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,    -1,    -1,   142,    -1,   144,   145,   146,
      -1,    -1,   149,    -1,    -1,    -1,   153,    -1,   155,    -1,
      -1,    -1,   159,   160,   161,    -1,    -1,    -1,    -1,   166,
      -1,   168,   169,   170,   171,   172,   173,     3,   175,   176,
     177,   178,   179,   180,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    -1,    25,
      -1,    27,    28,    -1,    30,    31,    -1,   204,    -1,   206,
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
      -1,    -1,    -1,   159,   160,   161,    -1,    -1,    -1,     7,
     166,     9,   168,   169,   170,   171,   172,   173,    -1,   175,
     176,   177,   178,   179,   180,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,
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
     178,   179,    -1,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,     7,
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
     178,   179,    -1,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     9,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,   137,   138,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,    -1,   156,    -1,    -1,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,   171,    -1,
      -1,   174,    -1,   176,   177,   178,   179,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,     9,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,    24,    -1,    -1,    -1,
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
     178,   179,    -1,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     9,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
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
     193,     9,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,    24,    -1,    -1,    -1,
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
     178,   179,    -1,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
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
     190,   191,   192,   193,     9,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,    24,
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
      -1,   176,   177,   178,   179,    -1,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,     9,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
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
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,    -1,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,
      -1,   171,    -1,    -1,   174,    -1,   176,   177,   178,   179,
      -1,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     9,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,    24,
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
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   315,   316,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    86,    88,    89,
      91,    94,    95,    96,    98,    99,   100,   101,   102,   103,
     104,   106,   110,   111,   112,   113,   114,   116,   117,   131,
     139,   142,   144,   145,   146,   149,   153,   155,   159,   160,
     161,   166,   168,   169,   170,   171,   172,   173,   175,   176,
     177,   178,   179,   180,   204,   206,   300,   309,   311,   313,
     204,   204,    24,   204,   226,   227,   228,    26,    31,    71,
     232,   233,   234,     9,    24,    34,    50,    51,    52,    67,
      70,    73,    82,    83,    84,    86,    94,    95,   107,   108,
     109,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   132,   133,   134,   136,   137,   138,   140,
     141,   154,   156,   160,   168,   171,   174,   176,   177,   178,
     179,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   209,   210,   211,   212,
     213,   214,   217,   218,   236,   237,   238,    22,    24,    32,
      49,    77,    78,   204,   223,   224,   225,   209,   214,   239,
     240,   241,    24,    36,    37,    87,   242,   243,   244,    42,
      43,    44,    45,    54,   257,   258,   259,   209,   274,   204,
     260,   263,   204,   206,   261,   301,    24,    36,    37,   209,
     248,   249,   250,    24,   251,   252,   253,    24,    87,   254,
     255,   256,   209,   209,    90,    90,   144,    34,    34,   209,
     209,    24,   245,   246,   247,    24,   264,   265,   266,   204,
     206,   262,   209,   144,    68,    68,   144,   206,   214,   209,
     204,    42,    43,   209,   278,    34,   204,   279,   209,   267,
     204,   282,   286,   204,   204,   204,   204,   205,   289,   289,
     209,   291,   157,   158,   294,   209,    42,    43,    97,   105,
     162,   163,   164,   295,   297,     7,   209,   298,     7,   209,
     299,   209,   209,   174,   209,     4,     6,    13,    20,   147,
     207,   306,   308,   312,     6,     4,     4,   209,   214,    24,
     209,   214,   209,   214,   209,   214,   206,    20,    25,    74,
      75,    76,    85,   135,   209,    34,    34,    34,    25,    74,
      75,    76,    83,    84,    85,   215,   216,   206,    20,   138,
     156,    34,    34,   209,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    20,    34,    86,   160,    20,   138,   156,    20,
      20,    20,    20,    20,    20,    20,   186,   183,   186,   187,
     193,   187,   193,   186,    20,   147,   219,    79,    80,   150,
     151,   152,   235,     8,     9,    12,    14,    15,    16,    17,
      18,    97,   105,   130,    19,    21,   129,    80,   152,   235,
      24,   204,   229,   230,   231,   214,    24,   204,    24,   204,
      24,   204,    24,   204,    24,    24,    25,    32,    36,    37,
      45,    54,    56,    57,    65,    66,    76,   222,    25,    32,
      36,    37,    45,    54,    56,    57,    65,    66,   222,   209,
     214,    29,   209,   214,    46,    46,    53,   102,   144,    20,
      42,   209,   209,     7,   209,   214,   209,   214,    29,    69,
     147,   209,   209,   209,   214,    34,   209,   209,    13,   152,
     209,     7,    25,    74,    75,    76,    85,   123,   135,   143,
     281,   283,   284,     7,   147,   302,   147,     7,    20,    48,
       7,     5,     7,     7,   209,     7,   209,     7,   209,   314,
     209,    13,   307,   303,    34,   281,   204,   309,   310,   313,
     313,    29,    29,   209,   214,    72,    72,    72,    72,    34,
      35,    35,    35,    35,    35,    74,    75,    85,    35,   209,
     214,   209,   214,   209,   214,    34,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   213,    34,   204,    34,    34,
      34,   220,   221,    34,   211,   211,   210,   210,   210,   210,
     210,   210,   210,   210,   212,   213,   213,   218,   209,   214,
      24,    48,   214,    24,   214,    24,   214,    24,   214,    24,
     214,   209,    33,    56,    57,    56,    57,    45,    54,    45,
      54,    34,   214,    33,    56,    57,    56,    57,    45,    54,
      45,    54,    34,   209,   214,   209,   214,   209,   214,   275,
     277,   276,    42,   204,     7,   209,   209,   214,   209,     7,
       7,   209,   214,    69,     7,   209,   102,     7,   209,    74,
      75,    85,   285,    34,    20,   286,   304,   147,   305,   289,
       7,   281,   289,   293,   292,    86,   160,   165,   296,   209,
     209,   313,   209,    34,   209,   290,   209,   287,    34,   309,
     204,   204,   209,   214,   209,   214,   209,   206,   206,   206,
     206,   206,    35,    35,    35,    35,    35,    35,    35,    35,
      35,   209,     7,     7,     7,     7,    35,    35,    35,    35,
       7,    35,    35,    35,    35,    35,     7,     7,    35,    35,
      35,     7,   204,    35,   209,   209,   209,    34,   290,   287,
      29,    29,   209,   214,    32,    49,    77,    78,   214,   214,
     214,   214,    29,    48,   209,   209,   214,   214,   204,   268,
     204,   270,   204,   272,   204,    13,   209,     7,    42,    42,
     148,   209,   209,     7,     7,   206,   214,    72,   204,   209,
       7,    34,   206,   280,    34,   290,   204,   288,   290,   289,
       7,   291,   291,   167,   167,   287,     7,   148,     7,    35,
     287,     7,   206,   206,   206,    35,   209,   209,   209,   209,
     209,   209,   209,   218,    35,    35,     7,     7,   287,   148,
      35,   204,   204,    29,    29,   205,    32,    49,    77,    78,
       7,     7,   269,   271,   273,    13,   209,   214,     7,   209,
     209,   214,    35,    35,   209,   214,   209,     7,    35,   209,
     280,     7,    35,   280,   148,     7,    20,    48,   148,   148,
     289,    35,   290,   287,    13,    35,   209,    35,    35,     7,
      35,     7,    35,    35,    35,    35,    35,   209,   209,    35,
     205,   205,    29,    29,   209,   214,     7,     7,     7,   209,
     209,    13,    13,    35,    35,   115,   209,    13,    72,    35,
     280,    35,   288,     7,   281,    13,   209,    13,    35,   209,
     209,    35,    35,   205,   205,    35,    35,   268,   270,   272,
     209,   209,   209,    35,   209,   209,   288,     7,   209,   209,
      35,    35,    13,   288,   209
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   208,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   210,   210,   210,   211,   211,   212,   212,   212,
     213,   213,   213,   214,   215,   215,   215,   215,   215,   215,
     215,   216,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   219,
     218,   220,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   221,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   222,   222,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   224,   224,   224,   224,   224,   225,
     225,   226,   226,   227,   227,   228,   228,   229,   229,   230,
     230,   231,   231,   232,   232,   232,   233,   233,   233,   234,
     234,   235,   235,   235,   236,   236,   236,   237,   237,   237,
     238,   238,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   241,   241,   242,   242,   242,   242,   242,   243,
     243,   244,   244,   245,   246,   247,   247,   248,   248,   249,
     249,   250,   250,   251,   252,   253,   253,   254,   254,   254,
     255,   255,   256,   256,   257,   257,   257,   257,   257,   258,
     258,   258,   259,   259,   260,   260,   260,   260,   260,   260,
     261,   261,   262,   262,   263,   264,   265,   266,   266,   267,
     268,   269,   268,   270,   271,   270,   272,   273,   272,   275,
     274,   276,   274,   277,   274,   278,   278,   278,   279,   279,
     280,   280,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   283,   282,   284,   282,   285,   282,   286,   286,
     287,   287,   288,   288,   288,   288,   288,   288,   289,   289,
     289,   289,   289,   289,   289,   289,   290,   290,   291,   291,
     291,   292,   291,   293,   291,   294,   294,   295,   295,   295,
     295,   295,   296,   296,   296,   296,   296,   297,   298,   298,
     298,   299,   299,   299,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   301,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     302,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     303,   300,   304,   300,   305,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   306,   300,   307,   300,   308,   300,   300,
     300,   300,   309,   310,   309,   312,   311,   314,   313,   313,
     313,   313,   313,   316,   315
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
       2,     2,     2,     1,     1,     1,     1,     1,     2,     3,
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
#line 2911 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 80 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2920 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 84 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2928 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 87 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2936 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 90 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2944 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 93 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2952 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 96 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2960 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 99 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2968 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 102 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2976 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 109 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2984 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 112 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2993 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 125 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3002 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 129 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3011 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 137 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 3020 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 141 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 3029 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 148 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3037 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 153 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3045 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 156 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3053 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 159 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3061 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 162 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3069 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 165 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3077 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 168 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3085 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 171 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3093 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 176 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3101 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 181 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3110 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 185 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3119 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 189 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3128 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 193 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3137 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 197 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3146 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 201 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3155 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 205 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3164 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 209 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3173 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 213 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3182 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 217 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3191 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 221 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3200 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 225 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3209 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 229 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3218 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 233 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3227 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 237 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3236 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 241 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3245 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 245 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3254 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 249 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3263 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 253 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3272 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 257 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3281 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 261 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3290 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 265 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3299 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 269 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3308 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 273 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3317 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 277 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3326 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 281 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3335 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 285 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3344 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 291 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3353 "src-generated/ugbc.tab.c"
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
#line 3365 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 302 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3374 "src-generated/ugbc.tab.c"
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
#line 3386 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 313 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3394 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 316 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3402 "src-generated/ugbc.tab.c"
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
#line 3416 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 328 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3425 "src-generated/ugbc.tab.c"
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
#line 3437 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 339 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3446 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 343 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3455 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 347 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3464 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 351 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3473 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 355 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3482 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 359 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3491 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 363 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3500 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 367 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3509 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 371 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3517 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 374 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3525 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 377 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3533 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 380 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3541 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 383 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3549 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 386 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3557 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 389 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3565 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 392 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3573 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 395 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3581 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 398 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3589 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 401 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3597 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 404 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3605 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 407 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3613 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 410 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3621 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 413 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3629 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 416 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3637 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 419 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3645 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 422 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3653 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 425 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3661 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 428 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3669 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 431 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3677 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 434 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3685 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 437 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3693 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 440 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3701 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 443 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3709 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 446 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3717 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 449 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3725 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 452 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3733 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 455 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3741 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 458 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3749 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 461 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3757 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 464 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3765 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 467 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3773 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 469 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3782 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 473 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3790 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 476 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3798 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 479 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3807 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 483 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3816 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 487 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3825 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: PEN COLORS  */
#line 491 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3834 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: PEN DEFAULT  */
#line 495 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3843 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: DEFAULT PEN  */
#line 499 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3852 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: PAPER COLORS  */
#line 503 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3861 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: PAPER DEFAULT  */
#line 507 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3870 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: DEFAULT PAPER  */
#line 511 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3879 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: WIDTH  */
#line 515 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3887 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: HEIGHT  */
#line 518 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3895 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: TIMER  */
#line 521 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3903 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PEN DOLLAR OP expr CP  */
#line 524 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 3911 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER DOLLAR OP expr CP  */
#line 527 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3919 "src-generated/ugbc.tab.c"
    break;

  case 126: /* exponential: CMOVE DOLLAR OP expr COMMA expr CP  */
#line 530 "src/ugbc.y"
                                         {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3927 "src-generated/ugbc.tab.c"
    break;

  case 127: /* exponential: CUP DOLLAR  */
#line 533 "src/ugbc.y"
                 {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 3935 "src-generated/ugbc.tab.c"
    break;

  case 128: /* exponential: CDOWN DOLLAR  */
#line 536 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 3943 "src-generated/ugbc.tab.c"
    break;

  case 129: /* exponential: CLEFT DOLLAR  */
#line 539 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 3951 "src-generated/ugbc.tab.c"
    break;

  case 130: /* exponential: CRIGHT DOLLAR  */
#line 542 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 3959 "src-generated/ugbc.tab.c"
    break;

  case 131: /* exponential: AT DOLLAR OP expr COMMA expr CP  */
#line 545 "src/ugbc.y"
                                      {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3967 "src-generated/ugbc.tab.c"
    break;

  case 132: /* exponential: LOCATE DOLLAR OP expr COMMA expr CP  */
#line 548 "src/ugbc.y"
                                          {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3975 "src-generated/ugbc.tab.c"
    break;

  case 133: /* exponential: TAB DOLLAR  */
#line 551 "src/ugbc.y"
                 {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 3983 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bank_definition_simple: AT direct_integer  */
#line 559 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3991 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bank_definition_simple: Identifier AT direct_integer  */
#line 562 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3999 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 565 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4007 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 568 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4015 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 571 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4023 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_simple: DATA AT direct_integer  */
#line 574 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4031 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 578 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4039 "src-generated/ugbc.tab.c"
    break;

  case 143: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 581 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4047 "src-generated/ugbc.tab.c"
    break;

  case 144: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 584 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4055 "src-generated/ugbc.tab.c"
    break;

  case 145: /* bank_definition_simple: CODE AT direct_integer  */
#line 587 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4063 "src-generated/ugbc.tab.c"
    break;

  case 146: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 591 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4071 "src-generated/ugbc.tab.c"
    break;

  case 147: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 594 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4079 "src-generated/ugbc.tab.c"
    break;

  case 148: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 597 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4087 "src-generated/ugbc.tab.c"
    break;

  case 149: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 600 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4095 "src-generated/ugbc.tab.c"
    break;

  case 150: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 604 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4103 "src-generated/ugbc.tab.c"
    break;

  case 151: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 607 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4111 "src-generated/ugbc.tab.c"
    break;

  case 152: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 610 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4119 "src-generated/ugbc.tab.c"
    break;

  case 153: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 613 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4127 "src-generated/ugbc.tab.c"
    break;

  case 154: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 619 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4135 "src-generated/ugbc.tab.c"
    break;

  case 155: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 622 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4143 "src-generated/ugbc.tab.c"
    break;

  case 156: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 625 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4151 "src-generated/ugbc.tab.c"
    break;

  case 157: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 628 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4159 "src-generated/ugbc.tab.c"
    break;

  case 158: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 631 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4167 "src-generated/ugbc.tab.c"
    break;

  case 161: /* raster_definition_simple: Identifier AT direct_integer  */
#line 640 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 4175 "src-generated/ugbc.tab.c"
    break;

  case 162: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 643 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 4183 "src-generated/ugbc.tab.c"
    break;

  case 163: /* raster_definition_expression: Identifier AT expr  */
#line 648 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4191 "src-generated/ugbc.tab.c"
    break;

  case 164: /* raster_definition_expression: AT expr WITH Identifier  */
#line 651 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4199 "src-generated/ugbc.tab.c"
    break;

  case 167: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 660 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 4207 "src-generated/ugbc.tab.c"
    break;

  case 168: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 663 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 4215 "src-generated/ugbc.tab.c"
    break;

  case 169: /* next_raster_definition_expression: Identifier AT expr  */
#line 668 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 4223 "src-generated/ugbc.tab.c"
    break;

  case 170: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 671 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4231 "src-generated/ugbc.tab.c"
    break;

  case 173: /* color_definition_simple: BORDER direct_integer  */
#line 680 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 4239 "src-generated/ugbc.tab.c"
    break;

  case 174: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 683 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4247 "src-generated/ugbc.tab.c"
    break;

  case 175: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 686 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4255 "src-generated/ugbc.tab.c"
    break;

  case 176: /* color_definition_expression: BORDER expr  */
#line 691 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 4263 "src-generated/ugbc.tab.c"
    break;

  case 177: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 694 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4271 "src-generated/ugbc.tab.c"
    break;

  case 178: /* color_definition_expression: SPRITE expr TO expr  */
#line 697 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4279 "src-generated/ugbc.tab.c"
    break;

  case 184: /* wait_definition_simple: direct_integer CYCLES  */
#line 711 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4287 "src-generated/ugbc.tab.c"
    break;

  case 185: /* wait_definition_simple: direct_integer TICKS  */
#line 714 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4295 "src-generated/ugbc.tab.c"
    break;

  case 186: /* wait_definition_simple: direct_integer milliseconds  */
#line 717 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4303 "src-generated/ugbc.tab.c"
    break;

  case 187: /* wait_definition_expression: expr CYCLES  */
#line 722 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4311 "src-generated/ugbc.tab.c"
    break;

  case 188: /* wait_definition_expression: expr TICKS  */
#line 725 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4319 "src-generated/ugbc.tab.c"
    break;

  case 189: /* wait_definition_expression: expr milliseconds  */
#line 728 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4327 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 738 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4335 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 741 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4343 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 744 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4351 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 747 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4359 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 750 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4367 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_simple: direct_integer ENABLE  */
#line 753 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4375 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_simple: direct_integer DISABLE  */
#line 756 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4383 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 759 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4391 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 762 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4399 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 765 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4407 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 768 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4415 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 771 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4423 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 774 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4431 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 777 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4439 "src-generated/ugbc.tab.c"
    break;

  case 206: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 780 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4447 "src-generated/ugbc.tab.c"
    break;

  case 207: /* sprite_definition_expression: expr DATA FROM expr  */
#line 785 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4455 "src-generated/ugbc.tab.c"
    break;

  case 208: /* sprite_definition_expression: expr MULTICOLOR  */
#line 788 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4463 "src-generated/ugbc.tab.c"
    break;

  case 209: /* sprite_definition_expression: expr MONOCOLOR  */
#line 791 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4471 "src-generated/ugbc.tab.c"
    break;

  case 210: /* sprite_definition_expression: expr COLOR expr  */
#line 794 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4479 "src-generated/ugbc.tab.c"
    break;

  case 211: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 797 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4487 "src-generated/ugbc.tab.c"
    break;

  case 212: /* sprite_definition_expression: expr ENABLE  */
#line 800 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4495 "src-generated/ugbc.tab.c"
    break;

  case 213: /* sprite_definition_expression: expr DISABLE  */
#line 803 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4503 "src-generated/ugbc.tab.c"
    break;

  case 214: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 806 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4511 "src-generated/ugbc.tab.c"
    break;

  case 215: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 809 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4519 "src-generated/ugbc.tab.c"
    break;

  case 216: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 812 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4527 "src-generated/ugbc.tab.c"
    break;

  case 217: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 815 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4535 "src-generated/ugbc.tab.c"
    break;

  case 218: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 818 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4543 "src-generated/ugbc.tab.c"
    break;

  case 219: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 821 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4551 "src-generated/ugbc.tab.c"
    break;

  case 220: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 824 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4559 "src-generated/ugbc.tab.c"
    break;

  case 221: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 827 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4567 "src-generated/ugbc.tab.c"
    break;

  case 224: /* bitmap_definition_simple: AT direct_integer  */
#line 836 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4575 "src-generated/ugbc.tab.c"
    break;

  case 225: /* bitmap_definition_simple: ENABLE  */
#line 839 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4583 "src-generated/ugbc.tab.c"
    break;

  case 226: /* bitmap_definition_simple: DISABLE  */
#line 842 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4591 "src-generated/ugbc.tab.c"
    break;

  case 227: /* bitmap_definition_simple: CLEAR  */
#line 845 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4599 "src-generated/ugbc.tab.c"
    break;

  case 228: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 848 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4607 "src-generated/ugbc.tab.c"
    break;

  case 229: /* bitmap_definition_expression: AT expr  */
#line 854 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4615 "src-generated/ugbc.tab.c"
    break;

  case 230: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 857 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4623 "src-generated/ugbc.tab.c"
    break;

  case 233: /* textmap_definition_simple: AT direct_integer  */
#line 867 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4631 "src-generated/ugbc.tab.c"
    break;

  case 234: /* textmap_definition_expression: AT expr  */
#line 872 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4639 "src-generated/ugbc.tab.c"
    break;

  case 237: /* text_definition_simple: ENABLE  */
#line 881 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4647 "src-generated/ugbc.tab.c"
    break;

  case 238: /* text_definition_simple: DISABLE  */
#line 884 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4655 "src-generated/ugbc.tab.c"
    break;

  case 239: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 889 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4663 "src-generated/ugbc.tab.c"
    break;

  case 240: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 892 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4671 "src-generated/ugbc.tab.c"
    break;

  case 243: /* tiles_definition_simple: AT direct_integer  */
#line 901 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4679 "src-generated/ugbc.tab.c"
    break;

  case 244: /* tiles_definition_expression: AT expr  */
#line 906 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4687 "src-generated/ugbc.tab.c"
    break;

  case 247: /* colormap_definition_simple: AT direct_integer  */
#line 915 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4695 "src-generated/ugbc.tab.c"
    break;

  case 248: /* colormap_definition_simple: CLEAR  */
#line 918 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4703 "src-generated/ugbc.tab.c"
    break;

  case 249: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 921 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4711 "src-generated/ugbc.tab.c"
    break;

  case 250: /* colormap_definition_expression: AT expr  */
#line 926 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4719 "src-generated/ugbc.tab.c"
    break;

  case 251: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 929 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4727 "src-generated/ugbc.tab.c"
    break;

  case 254: /* screen_definition_simple: ON  */
#line 939 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4735 "src-generated/ugbc.tab.c"
    break;

  case 255: /* screen_definition_simple: OFF  */
#line 942 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4743 "src-generated/ugbc.tab.c"
    break;

  case 256: /* screen_definition_simple: ROWS direct_integer  */
#line 945 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4751 "src-generated/ugbc.tab.c"
    break;

  case 257: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 948 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4759 "src-generated/ugbc.tab.c"
    break;

  case 258: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 951 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4767 "src-generated/ugbc.tab.c"
    break;

  case 259: /* screen_definition_expression: ROWS expr  */
#line 956 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4775 "src-generated/ugbc.tab.c"
    break;

  case 260: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 959 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4783 "src-generated/ugbc.tab.c"
    break;

  case 261: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 962 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4791 "src-generated/ugbc.tab.c"
    break;

  case 265: /* var_definition_simple: Identifier ON Identifier  */
#line 971 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4799 "src-generated/ugbc.tab.c"
    break;

  case 266: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 974 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4807 "src-generated/ugbc.tab.c"
    break;

  case 267: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 977 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4815 "src-generated/ugbc.tab.c"
    break;

  case 268: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 980 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4825 "src-generated/ugbc.tab.c"
    break;

  case 269: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 985 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4835 "src-generated/ugbc.tab.c"
    break;

  case 270: /* goto_definition: Identifier  */
#line 992 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4843 "src-generated/ugbc.tab.c"
    break;

  case 271: /* goto_definition: Integer  */
#line 995 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4851 "src-generated/ugbc.tab.c"
    break;

  case 272: /* gosub_definition: Identifier  */
#line 1001 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4859 "src-generated/ugbc.tab.c"
    break;

  case 273: /* gosub_definition: Integer  */
#line 1004 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4867 "src-generated/ugbc.tab.c"
    break;

  case 275: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 1013 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4875 "src-generated/ugbc.tab.c"
    break;

  case 276: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 1019 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4883 "src-generated/ugbc.tab.c"
    break;

  case 279: /* ink_definition: expr  */
#line 1028 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4891 "src-generated/ugbc.tab.c"
    break;

  case 280: /* on_goto_definition: Identifier  */
#line 1033 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4900 "src-generated/ugbc.tab.c"
    break;

  case 281: /* $@4: %empty  */
#line 1037 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4908 "src-generated/ugbc.tab.c"
    break;

  case 283: /* on_gosub_definition: Identifier  */
#line 1042 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4917 "src-generated/ugbc.tab.c"
    break;

  case 284: /* $@5: %empty  */
#line 1046 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4925 "src-generated/ugbc.tab.c"
    break;

  case 286: /* on_proc_definition: Identifier  */
#line 1051 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4934 "src-generated/ugbc.tab.c"
    break;

  case 287: /* $@6: %empty  */
#line 1055 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4942 "src-generated/ugbc.tab.c"
    break;

  case 289: /* $@7: %empty  */
#line 1060 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4950 "src-generated/ugbc.tab.c"
    break;

  case 291: /* $@8: %empty  */
#line 1063 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4958 "src-generated/ugbc.tab.c"
    break;

  case 293: /* $@9: %empty  */
#line 1066 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4966 "src-generated/ugbc.tab.c"
    break;

  case 295: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1071 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4974 "src-generated/ugbc.tab.c"
    break;

  case 296: /* every_definition: ON  */
#line 1074 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4982 "src-generated/ugbc.tab.c"
    break;

  case 297: /* every_definition: OFF  */
#line 1077 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4990 "src-generated/ugbc.tab.c"
    break;

  case 298: /* add_definition: Identifier COMMA expr  */
#line 1082 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4998 "src-generated/ugbc.tab.c"
    break;

  case 299: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1085 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5006 "src-generated/ugbc.tab.c"
    break;

  case 300: /* dimensions: Integer  */
#line 1091 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5015 "src-generated/ugbc.tab.c"
    break;

  case 301: /* dimensions: Integer COMMA dimensions  */
#line 1095 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5024 "src-generated/ugbc.tab.c"
    break;

  case 302: /* datatype: BYTE  */
#line 1102 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 5032 "src-generated/ugbc.tab.c"
    break;

  case 303: /* datatype: SIGNED BYTE  */
#line 1105 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 5040 "src-generated/ugbc.tab.c"
    break;

  case 304: /* datatype: WORD  */
#line 1108 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 5048 "src-generated/ugbc.tab.c"
    break;

  case 305: /* datatype: SIGNED WORD  */
#line 1111 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 5056 "src-generated/ugbc.tab.c"
    break;

  case 306: /* datatype: DWORD  */
#line 1114 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 5064 "src-generated/ugbc.tab.c"
    break;

  case 307: /* datatype: SIGNED DWORD  */
#line 1117 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 5072 "src-generated/ugbc.tab.c"
    break;

  case 308: /* datatype: ADDRESS  */
#line 1120 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 5080 "src-generated/ugbc.tab.c"
    break;

  case 309: /* datatype: POSITION  */
#line 1123 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 5088 "src-generated/ugbc.tab.c"
    break;

  case 310: /* datatype: COLOR  */
#line 1126 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 5096 "src-generated/ugbc.tab.c"
    break;

  case 311: /* datatype: STRING  */
#line 1129 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 5104 "src-generated/ugbc.tab.c"
    break;

  case 312: /* $@10: %empty  */
#line 1134 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5113 "src-generated/ugbc.tab.c"
    break;

  case 313: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1137 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 5123 "src-generated/ugbc.tab.c"
    break;

  case 314: /* $@11: %empty  */
#line 1142 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5132 "src-generated/ugbc.tab.c"
    break;

  case 315: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1145 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 5142 "src-generated/ugbc.tab.c"
    break;

  case 316: /* $@12: %empty  */
#line 1150 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5151 "src-generated/ugbc.tab.c"
    break;

  case 317: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1153 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 5161 "src-generated/ugbc.tab.c"
    break;

  case 320: /* indexes: expr  */
#line 1166 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5170 "src-generated/ugbc.tab.c"
    break;

  case 321: /* indexes: expr COMMA indexes  */
#line 1170 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5179 "src-generated/ugbc.tab.c"
    break;

  case 322: /* parameters: Identifier  */
#line 1177 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5189 "src-generated/ugbc.tab.c"
    break;

  case 323: /* parameters: Identifier DOLLAR  */
#line 1182 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5199 "src-generated/ugbc.tab.c"
    break;

  case 324: /* parameters: Identifier AS datatype  */
#line 1187 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5209 "src-generated/ugbc.tab.c"
    break;

  case 325: /* parameters: Identifier COMMA parameters  */
#line 1192 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5219 "src-generated/ugbc.tab.c"
    break;

  case 326: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1197 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5229 "src-generated/ugbc.tab.c"
    break;

  case 327: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1202 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5239 "src-generated/ugbc.tab.c"
    break;

  case 328: /* parameters_expr: Identifier  */
#line 1210 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5249 "src-generated/ugbc.tab.c"
    break;

  case 329: /* parameters_expr: Identifier DOLLAR  */
#line 1215 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5259 "src-generated/ugbc.tab.c"
    break;

  case 330: /* parameters_expr: Identifier AS datatype  */
#line 1220 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5269 "src-generated/ugbc.tab.c"
    break;

  case 331: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1225 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5279 "src-generated/ugbc.tab.c"
    break;

  case 332: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1230 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5289 "src-generated/ugbc.tab.c"
    break;

  case 333: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1235 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5299 "src-generated/ugbc.tab.c"
    break;

  case 334: /* parameters_expr: String  */
#line 1240 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5308 "src-generated/ugbc.tab.c"
    break;

  case 335: /* parameters_expr: String COMMA parameters_expr  */
#line 1244 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5317 "src-generated/ugbc.tab.c"
    break;

  case 336: /* values: expr  */
#line 1251 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5326 "src-generated/ugbc.tab.c"
    break;

  case 337: /* values: expr COMMA values  */
#line 1255 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5335 "src-generated/ugbc.tab.c"
    break;

  case 338: /* print_definition: expr  */
#line 1262 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5343 "src-generated/ugbc.tab.c"
    break;

  case 339: /* print_definition: expr COMMA  */
#line 1265 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5352 "src-generated/ugbc.tab.c"
    break;

  case 340: /* print_definition: expr SEMICOLON  */
#line 1269 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5360 "src-generated/ugbc.tab.c"
    break;

  case 341: /* $@13: %empty  */
#line 1272 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5369 "src-generated/ugbc.tab.c"
    break;

  case 343: /* $@14: %empty  */
#line 1276 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5377 "src-generated/ugbc.tab.c"
    break;

  case 345: /* use_definition: ANSI  */
#line 1282 "src/ugbc.y"
         {
        use_ansi( _environment );
    }
#line 5385 "src-generated/ugbc.tab.c"
    break;

  case 346: /* use_definition: SPECIFIC  */
#line 1285 "src/ugbc.y"
             {
        use_specific( _environment );
  }
#line 5393 "src-generated/ugbc.tab.c"
    break;

  case 347: /* writing_mode_definition: REPLACE  */
#line 1291 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5402 "src-generated/ugbc.tab.c"
    break;

  case 348: /* writing_mode_definition: OR  */
#line 1295 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5411 "src-generated/ugbc.tab.c"
    break;

  case 349: /* writing_mode_definition: XOR  */
#line 1299 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5420 "src-generated/ugbc.tab.c"
    break;

  case 350: /* writing_mode_definition: AND  */
#line 1303 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5429 "src-generated/ugbc.tab.c"
    break;

  case 351: /* writing_mode_definition: IGNORE  */
#line 1307 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5438 "src-generated/ugbc.tab.c"
    break;

  case 352: /* writing_part_definition: NORMAL  */
#line 1314 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5447 "src-generated/ugbc.tab.c"
    break;

  case 353: /* writing_part_definition: PAPER  */
#line 1318 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5456 "src-generated/ugbc.tab.c"
    break;

  case 354: /* writing_part_definition: PAPER ONLY  */
#line 1322 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5465 "src-generated/ugbc.tab.c"
    break;

  case 355: /* writing_part_definition: PEN  */
#line 1326 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5474 "src-generated/ugbc.tab.c"
    break;

  case 356: /* writing_part_definition: PEN ONLY  */
#line 1330 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5483 "src-generated/ugbc.tab.c"
    break;

  case 357: /* writing_definition: writing_mode_definition COMMA writing_part_definition  */
#line 1337 "src/ugbc.y"
                                                          {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5491 "src-generated/ugbc.tab.c"
    break;

  case 358: /* locate_definition: COMMA expr  */
#line 1343 "src/ugbc.y"
                {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 5499 "src-generated/ugbc.tab.c"
    break;

  case 359: /* locate_definition: expr COMMA  */
#line 1346 "src/ugbc.y"
                 {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 5507 "src-generated/ugbc.tab.c"
    break;

  case 360: /* locate_definition: expr COMMA expr  */
#line 1349 "src/ugbc.y"
                      {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5515 "src-generated/ugbc.tab.c"
    break;

  case 361: /* cmove_definition: COMMA expr  */
#line 1355 "src/ugbc.y"
                {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 5523 "src-generated/ugbc.tab.c"
    break;

  case 362: /* cmove_definition: expr COMMA  */
#line 1358 "src/ugbc.y"
                 {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 5531 "src-generated/ugbc.tab.c"
    break;

  case 363: /* cmove_definition: expr COMMA expr  */
#line 1361 "src/ugbc.y"
                      {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5539 "src-generated/ugbc.tab.c"
    break;

  case 383: /* statement: CUP  */
#line 1386 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 5547 "src-generated/ugbc.tab.c"
    break;

  case 384: /* statement: CDOWN  */
#line 1389 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 5555 "src-generated/ugbc.tab.c"
    break;

  case 385: /* statement: CLEFT  */
#line 1392 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 5563 "src-generated/ugbc.tab.c"
    break;

  case 386: /* statement: CRIGHT  */
#line 1395 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 5571 "src-generated/ugbc.tab.c"
    break;

  case 387: /* statement: CLINE  */
#line 1398 "src/ugbc.y"
          {
      text_cline( _environment, NULL );
  }
#line 5579 "src-generated/ugbc.tab.c"
    break;

  case 388: /* statement: CLINE expr  */
#line 1401 "src/ugbc.y"
               {
      text_cline( _environment, (yyvsp[0].string) );
  }
#line 5587 "src-generated/ugbc.tab.c"
    break;

  case 389: /* statement: SET TAB expr  */
#line 1404 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 5595 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: CENTER expr  */
#line 1407 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5603 "src-generated/ugbc.tab.c"
    break;

  case 391: /* statement: CENTRE expr  */
#line 1410 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5611 "src-generated/ugbc.tab.c"
    break;

  case 392: /* statement: CLS  */
#line 1413 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 5619 "src-generated/ugbc.tab.c"
    break;

  case 393: /* statement: HOME  */
#line 1416 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 5627 "src-generated/ugbc.tab.c"
    break;

  case 394: /* statement: INC Identifier  */
#line 1419 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 5635 "src-generated/ugbc.tab.c"
    break;

  case 395: /* statement: DEC Identifier  */
#line 1422 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 5643 "src-generated/ugbc.tab.c"
    break;

  case 396: /* statement: RANDOMIZE  */
#line 1425 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 5651 "src-generated/ugbc.tab.c"
    break;

  case 397: /* statement: RANDOMIZE expr  */
#line 1428 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 5659 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statement: IF expr THEN  */
#line 1431 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5667 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: ELSE  */
#line 1434 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 5675 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: ELSE IF expr THEN  */
#line 1437 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5683 "src-generated/ugbc.tab.c"
    break;

  case 401: /* statement: ENDIF  */
#line 1440 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5691 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: DO  */
#line 1443 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5699 "src-generated/ugbc.tab.c"
    break;

  case 403: /* statement: LOOP  */
#line 1446 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5707 "src-generated/ugbc.tab.c"
    break;

  case 404: /* $@15: %empty  */
#line 1449 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5715 "src-generated/ugbc.tab.c"
    break;

  case 405: /* statement: WHILE $@15 expr  */
#line 1451 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5723 "src-generated/ugbc.tab.c"
    break;

  case 406: /* statement: WEND  */
#line 1454 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5731 "src-generated/ugbc.tab.c"
    break;

  case 407: /* statement: REPEAT  */
#line 1457 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5739 "src-generated/ugbc.tab.c"
    break;

  case 408: /* statement: UNTIL expr  */
#line 1460 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5747 "src-generated/ugbc.tab.c"
    break;

  case 409: /* statement: EXIT  */
#line 1463 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5755 "src-generated/ugbc.tab.c"
    break;

  case 410: /* statement: EXIT PROC  */
#line 1466 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5763 "src-generated/ugbc.tab.c"
    break;

  case 411: /* statement: POP PROC  */
#line 1469 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5771 "src-generated/ugbc.tab.c"
    break;

  case 412: /* statement: EXIT IF expr  */
#line 1472 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5779 "src-generated/ugbc.tab.c"
    break;

  case 413: /* statement: EXIT Integer  */
#line 1475 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5787 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: EXIT direct_integer  */
#line 1478 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5795 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: EXIT IF expr COMMA Integer  */
#line 1481 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5803 "src-generated/ugbc.tab.c"
    break;

  case 416: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1484 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5811 "src-generated/ugbc.tab.c"
    break;

  case 417: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1487 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5819 "src-generated/ugbc.tab.c"
    break;

  case 418: /* statement: NEXT  */
#line 1490 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5827 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: PROCEDURE Identifier  */
#line 1493 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5836 "src-generated/ugbc.tab.c"
    break;

  case 420: /* $@16: %empty  */
#line 1497 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5844 "src-generated/ugbc.tab.c"
    break;

  case 421: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1499 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5852 "src-generated/ugbc.tab.c"
    break;

  case 422: /* statement: SHARED parameters_expr  */
#line 1502 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5860 "src-generated/ugbc.tab.c"
    break;

  case 423: /* statement: GLOBAL parameters_expr  */
#line 1505 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5868 "src-generated/ugbc.tab.c"
    break;

  case 424: /* statement: END PROC  */
#line 1508 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 5876 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: END PROC OSP expr CSP  */
#line 1511 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5884 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1514 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5892 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: Identifier " "  */
#line 1517 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5901 "src-generated/ugbc.tab.c"
    break;

  case 428: /* statement: PROC Identifier  */
#line 1521 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5910 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: CALL Identifier  */
#line 1525 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5919 "src-generated/ugbc.tab.c"
    break;

  case 430: /* $@17: %empty  */
#line 1529 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5927 "src-generated/ugbc.tab.c"
    break;

  case 431: /* statement: Identifier OSP $@17 values CSP  */
#line 1531 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5935 "src-generated/ugbc.tab.c"
    break;

  case 432: /* $@18: %empty  */
#line 1534 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5943 "src-generated/ugbc.tab.c"
    break;

  case 433: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1536 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5951 "src-generated/ugbc.tab.c"
    break;

  case 434: /* $@19: %empty  */
#line 1539 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5959 "src-generated/ugbc.tab.c"
    break;

  case 435: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1541 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5967 "src-generated/ugbc.tab.c"
    break;

  case 436: /* statement: PEN expr  */
#line 1544 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 5975 "src-generated/ugbc.tab.c"
    break;

  case 437: /* statement: PAPER expr  */
#line 1547 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 5983 "src-generated/ugbc.tab.c"
    break;

  case 438: /* statement: INVERSE ON  */
#line 1550 "src/ugbc.y"
               {
      text_inverse( _environment, 1 );
  }
#line 5991 "src-generated/ugbc.tab.c"
    break;

  case 439: /* statement: INVERSE OFF  */
#line 1553 "src/ugbc.y"
                {
      text_inverse( _environment, 0 );
  }
#line 5999 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: Identifier COLON  */
#line 1557 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 6007 "src-generated/ugbc.tab.c"
    break;

  case 442: /* statement: BEG GAMELOOP  */
#line 1560 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 6015 "src-generated/ugbc.tab.c"
    break;

  case 443: /* statement: END GAMELOOP  */
#line 1563 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 6023 "src-generated/ugbc.tab.c"
    break;

  case 444: /* statement: GRAPHIC  */
#line 1566 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 6031 "src-generated/ugbc.tab.c"
    break;

  case 445: /* statement: HALT  */
#line 1569 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 6039 "src-generated/ugbc.tab.c"
    break;

  case 446: /* statement: END  */
#line 1572 "src/ugbc.y"
        {
      end( _environment );
  }
#line 6047 "src-generated/ugbc.tab.c"
    break;

  case 451: /* statement: RETURN  */
#line 1579 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 6055 "src-generated/ugbc.tab.c"
    break;

  case 452: /* statement: RETURN expr  */
#line 1582 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 6063 "src-generated/ugbc.tab.c"
    break;

  case 453: /* statement: POP  */
#line 1585 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 6071 "src-generated/ugbc.tab.c"
    break;

  case 454: /* statement: DONE  */
#line 1588 "src/ugbc.y"
          {
      return 0;
  }
#line 6079 "src-generated/ugbc.tab.c"
    break;

  case 455: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1591 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6087 "src-generated/ugbc.tab.c"
    break;

  case 456: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1594 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6095 "src-generated/ugbc.tab.c"
    break;

  case 457: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1597 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 6103 "src-generated/ugbc.tab.c"
    break;

  case 458: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1600 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6111 "src-generated/ugbc.tab.c"
    break;

  case 461: /* statement: Identifier ASSIGN expr  */
#line 1605 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 6125 "src-generated/ugbc.tab.c"
    break;

  case 462: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1614 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 6139 "src-generated/ugbc.tab.c"
    break;

  case 463: /* $@20: %empty  */
#line 1623 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6148 "src-generated/ugbc.tab.c"
    break;

  case 464: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1627 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 6161 "src-generated/ugbc.tab.c"
    break;

  case 465: /* $@21: %empty  */
#line 1635 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6170 "src-generated/ugbc.tab.c"
    break;

  case 466: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1638 "src/ugbc.y"
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
#line 6189 "src-generated/ugbc.tab.c"
    break;

  case 467: /* $@22: %empty  */
#line 1652 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6198 "src-generated/ugbc.tab.c"
    break;

  case 468: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1655 "src/ugbc.y"
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
#line 6217 "src-generated/ugbc.tab.c"
    break;

  case 469: /* statement: DEBUG expr  */
#line 1669 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 6225 "src-generated/ugbc.tab.c"
    break;

  case 472: /* statements_no_linenumbers: statement  */
#line 1677 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 6231 "src-generated/ugbc.tab.c"
    break;

  case 473: /* $@23: %empty  */
#line 1678 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 6237 "src-generated/ugbc.tab.c"
    break;

  case 475: /* $@24: %empty  */
#line 1682 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 6245 "src-generated/ugbc.tab.c"
    break;

  case 476: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1684 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 6253 "src-generated/ugbc.tab.c"
    break;

  case 477: /* $@25: %empty  */
#line 1689 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 6261 "src-generated/ugbc.tab.c"
    break;

  case 483: /* $@26: %empty  */
#line 1699 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 6267 "src-generated/ugbc.tab.c"
    break;


#line 6271 "src-generated/ugbc.tab.c"

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

#line 1701 "src/ugbc.y"


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

