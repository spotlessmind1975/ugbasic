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
  YYSYMBOL_MEMORIZE = 183,                 /* MEMORIZE  */
  YYSYMBOL_REMEMBER = 184,                 /* REMEMBER  */
  YYSYMBOL_BLACK = 185,                    /* BLACK  */
  YYSYMBOL_WHITE = 186,                    /* WHITE  */
  YYSYMBOL_RED = 187,                      /* RED  */
  YYSYMBOL_CYAN = 188,                     /* CYAN  */
  YYSYMBOL_VIOLET = 189,                   /* VIOLET  */
  YYSYMBOL_GREEN = 190,                    /* GREEN  */
  YYSYMBOL_BLUE = 191,                     /* BLUE  */
  YYSYMBOL_YELLOW = 192,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 193,                   /* ORANGE  */
  YYSYMBOL_BROWN = 194,                    /* BROWN  */
  YYSYMBOL_LIGHT = 195,                    /* LIGHT  */
  YYSYMBOL_DARK = 196,                     /* DARK  */
  YYSYMBOL_GREY = 197,                     /* GREY  */
  YYSYMBOL_GRAY = 198,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 199,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 200,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 201,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 202,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 203,                /* TURQUOISE  */
  YYSYMBOL_TAN = 204,                      /* TAN  */
  YYSYMBOL_PINK = 205,                     /* PINK  */
  YYSYMBOL_PEACH = 206,                    /* PEACH  */
  YYSYMBOL_OLIVE = 207,                    /* OLIVE  */
  YYSYMBOL_Identifier = 208,               /* Identifier  */
  YYSYMBOL_String = 209,                   /* String  */
  YYSYMBOL_Integer = 210,                  /* Integer  */
  YYSYMBOL_211_ = 211,                     /* " "  */
  YYSYMBOL_YYACCEPT = 212,                 /* $accept  */
  YYSYMBOL_expr = 213,                     /* expr  */
  YYSYMBOL_expr_math = 214,                /* expr_math  */
  YYSYMBOL_term = 215,                     /* term  */
  YYSYMBOL_modula = 216,                   /* modula  */
  YYSYMBOL_factor = 217,                   /* factor  */
  YYSYMBOL_direct_integer = 218,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 219, /* random_definition_simple  */
  YYSYMBOL_random_definition = 220,        /* random_definition  */
  YYSYMBOL_color_enumeration = 221,        /* color_enumeration  */
  YYSYMBOL_exponential = 222,              /* exponential  */
  YYSYMBOL_223_1 = 223,                    /* $@1  */
  YYSYMBOL_224_2 = 224,                    /* $@2  */
  YYSYMBOL_225_3 = 225,                    /* $@3  */
  YYSYMBOL_position = 226,                 /* position  */
  YYSYMBOL_bank_definition_simple = 227,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 228, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 229,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 230, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 231, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 232,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 233, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 234, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 235,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 236,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 237, /* color_definition_expression  */
  YYSYMBOL_color_definition = 238,         /* color_definition  */
  YYSYMBOL_milliseconds = 239,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 240,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 241, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 242,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 243, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 244, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 245,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 246, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 247, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 248,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 249, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 250, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 251,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 252,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 253, /* text_definition_expression  */
  YYSYMBOL_text_definition = 254,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 255,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 256, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 257,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 258, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 259, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 260,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 261, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 262, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 263,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 264,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 265,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 266,         /* gosub_definition  */
  YYSYMBOL_var_definition = 267,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 268,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 269, /* point_definition_expression  */
  YYSYMBOL_point_definition = 270,         /* point_definition  */
  YYSYMBOL_ink_definition = 271,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 272,       /* on_goto_definition  */
  YYSYMBOL_273_4 = 273,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 274,      /* on_gosub_definition  */
  YYSYMBOL_275_5 = 275,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 276,       /* on_proc_definition  */
  YYSYMBOL_277_6 = 277,                    /* $@6  */
  YYSYMBOL_on_definition = 278,            /* on_definition  */
  YYSYMBOL_279_7 = 279,                    /* $@7  */
  YYSYMBOL_280_8 = 280,                    /* $@8  */
  YYSYMBOL_281_9 = 281,                    /* $@9  */
  YYSYMBOL_every_definition = 282,         /* every_definition  */
  YYSYMBOL_add_definition = 283,           /* add_definition  */
  YYSYMBOL_dimensions = 284,               /* dimensions  */
  YYSYMBOL_datatype = 285,                 /* datatype  */
  YYSYMBOL_dim_definition = 286,           /* dim_definition  */
  YYSYMBOL_287_10 = 287,                   /* $@10  */
  YYSYMBOL_288_11 = 288,                   /* $@11  */
  YYSYMBOL_289_12 = 289,                   /* $@12  */
  YYSYMBOL_dim_definitions = 290,          /* dim_definitions  */
  YYSYMBOL_indexes = 291,                  /* indexes  */
  YYSYMBOL_parameters = 292,               /* parameters  */
  YYSYMBOL_parameters_expr = 293,          /* parameters_expr  */
  YYSYMBOL_values = 294,                   /* values  */
  YYSYMBOL_print_definition = 295,         /* print_definition  */
  YYSYMBOL_296_13 = 296,                   /* $@13  */
  YYSYMBOL_297_14 = 297,                   /* $@14  */
  YYSYMBOL_use_definition = 298,           /* use_definition  */
  YYSYMBOL_writing_mode_definition = 299,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 300,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 301,       /* writing_definition  */
  YYSYMBOL_locate_definition = 302,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 303,         /* cmove_definition  */
  YYSYMBOL_statement = 304,                /* statement  */
  YYSYMBOL_305_15 = 305,                   /* $@15  */
  YYSYMBOL_306_16 = 306,                   /* $@16  */
  YYSYMBOL_307_17 = 307,                   /* $@17  */
  YYSYMBOL_308_18 = 308,                   /* $@18  */
  YYSYMBOL_309_19 = 309,                   /* $@19  */
  YYSYMBOL_310_20 = 310,                   /* $@20  */
  YYSYMBOL_311_21 = 311,                   /* $@21  */
  YYSYMBOL_312_22 = 312,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 313, /* statements_no_linenumbers  */
  YYSYMBOL_314_23 = 314,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 315, /* statements_with_linenumbers  */
  YYSYMBOL_316_24 = 316,                   /* $@24  */
  YYSYMBOL_statements_complex = 317,       /* statements_complex  */
  YYSYMBOL_318_25 = 318,                   /* $@25  */
  YYSYMBOL_program = 319,                  /* program  */
  YYSYMBOL_320_26 = 320                    /* $@26  */
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
#define YYLAST   3175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  212
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  488
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  939

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   466


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
     205,   206,   207,   208,   209,   210,   211
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
    1387,  1388,  1389,  1390,  1391,  1394,  1397,  1398,  1401,  1404,
    1407,  1410,  1413,  1416,  1419,  1422,  1425,  1428,  1431,  1434,
    1437,  1440,  1443,  1446,  1449,  1452,  1455,  1458,  1461,  1461,
    1466,  1469,  1472,  1475,  1478,  1481,  1484,  1487,  1490,  1493,
    1496,  1499,  1502,  1505,  1509,  1509,  1514,  1517,  1520,  1523,
    1526,  1529,  1533,  1537,  1541,  1541,  1546,  1546,  1551,  1551,
    1556,  1559,  1562,  1565,  1568,  1569,  1572,  1575,  1578,  1581,
    1584,  1587,  1588,  1589,  1590,  1591,  1594,  1597,  1600,  1603,
    1606,  1609,  1612,  1615,  1616,  1617,  1626,  1635,  1635,  1647,
    1647,  1664,  1664,  1681,  1684,  1685,  1689,  1690,  1690,  1694,
    1694,  1701,  1701,  1704,  1705,  1706,  1707,  1711,  1711
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
  "CUP", "CDOWN", "CLEFT", "CRIGHT", "CLINE", "XCURS", "YCURS", "MEMORIZE",
  "REMEMBER", "BLACK", "WHITE", "RED", "CYAN", "VIOLET", "GREEN", "BLUE",
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
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466
};
#endif

#define YYPACT_NINF (-822)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-468)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -822,    72,   887,  -822,  -822,  -139,   -94,   -18,  -822,    47,
    2196,   118,    21,  2196,  -822,    22,   213,  2587,   -84,    60,
    -822,  -822,  -822,  1818,   151,    17,  2587,  2587,    93,   -47,
    -822,   153,   159,  2587,  2587,  -822,   181,   184,    61,  2587,
      78,   182,  -822,   -38,  -822,  2587,    54,  2007,   257,    87,
    2587,    96,    97,    98,    99,   -81,   -81,  2587,    13,  2587,
     185,    77,  1236,  -822,  -822,  1440,  2587,  2587,   134,  -822,
    -822,  -822,  -822,  2587,  -822,  -822,     5,  -822,   303,   306,
     307,  -822,  -822,  -822,  2196,   288,  -822,  -822,  -822,  2196,
    2196,  2196,  -822,  -822,  -822,   105,   296,  1629,  -822,  -822,
     283,   286,   287,   169,   108,  -822,  -822,    11,   289,   290,
    2587,  -822,  -822,   291,   292,   293,   294,   298,   299,   300,
     301,   302,   304,   305,   308,   309,   310,   313,   333,   334,
    -822,  -822,   335,    55,   -35,    12,   317,   320,   321,   350,
     351,   352,   354,  -822,  -822,  -822,  -822,  -822,  -822,  -822,
    -822,  -822,   132,  -822,  -822,    10,   -90,  -822,  -822,  -822,
    -822,  -822,  -822,  -822,  -822,  -822,   186,    16,  -822,  -822,
      63,   121,   245,   242,   250,    86,  -822,  -822,  -822,  -822,
    -822,   -12,   311,    -9,    -5,    -4,    -2,   356,  -822,  -822,
    -822,   341,   387,  -822,  -822,  -822,  2196,  -822,  -822,   353,
    -822,  -822,  -822,  -822,  -822,  2196,   337,   338,  -822,  -822,
    -822,     1,  -822,    48,  -822,  -822,  -822,  -822,  -822,  2587,
    2398,  -822,  -822,   374,  -822,  -822,  -822,  2196,  -822,  -822,
    -822,  2196,   358,  -822,  -822,  -822,   316,  -822,  -822,  -822,
     241,  2587,  2587,  -822,  -822,  2196,  -822,  -822,  -822,   355,
    -822,  -822,  -822,  -822,  -822,  -822,  -822,  -822,  2587,  2587,
    -822,  -822,  -822,  -822,   377,  -822,  -822,   239,  -822,  2587,
     389,  -822,  -822,  -822,    41,   392,  -822,   247,   253,   254,
      57,   395,  -822,  -822,   278,  -822,  -822,  -822,  -822,  -822,
    -822,  -822,  -822,  -822,  -822,  -822,  -822,   396,  -822,  2587,
     397,  -822,  2587,   398,  -822,  -822,  -822,  2587,  -822,  -822,
    -822,  2587,   400,  -822,  -822,   381,    46,  1058,  -822,   887,
     887,   391,   393,  2196,  -822,  -822,   344,   346,   349,   357,
    -822,   394,   390,   399,   401,   402,   403,   103,   404,  2196,
    2196,  2196,  -822,  -822,  -822,  -822,  -822,  -822,  -822,  -822,
    -822,  -822,   406,  -822,  -822,  2587,  2587,  -822,  2587,  2587,
    2587,  2587,  2587,  2587,  2587,  2587,  2587,  2587,  2587,  2587,
    2587,  2587,  2587,  2587,  2587,  2776,   408,   218,  -822,  -822,
     411,  -822,  -822,   412,   413,  -822,  -822,  -822,  -822,  -822,
    -822,  -822,  -822,  -822,  -822,  -822,  -822,  -822,   414,  -822,
     415,  -822,  -822,  -822,  -822,  -822,  -822,  2776,  2776,  2776,
    2776,  2776,  2776,  2776,  2776,  2776,  2776,  2776,  2776,  2776,
    2965,  -822,  -822,  -822,  2196,   407,  -822,  -822,  -822,   379,
     311,   409,   311,   426,   311,   427,   311,   430,   311,  -822,
    2587,   423,  -822,  -822,   155,   190,    31,    39,  -822,  -822,
    -822,   428,   311,   431,  -822,  -822,   216,   230,   180,   188,
    -822,  -822,   432,  -822,  -822,  2196,  -822,  -822,  2196,  2196,
    -822,  -822,  -822,   419,   227,  -822,   458,  2587,  -822,  -822,
    -822,  -822,  2196,  -822,  2587,   461,   462,  -822,  -822,  2196,
     417,   463,  2587,   369,   466,  2587,  -822,  -822,  -822,  -822,
    -822,  -822,   117,  -822,  -822,   441,   456,    96,  -822,   330,
    -822,   -81,   471,    46,   -81,   260,   284,   -19,  -822,  2587,
    -822,  2587,  -822,   887,  -822,  2587,   446,  2587,  2587,   447,
       8,  -822,  1058,  -822,  -822,   275,   276,  -822,  -822,  2587,
     311,  2587,   311,  2587,   277,   279,   280,   281,   282,   453,
     459,   460,  -822,   465,   467,   469,   473,   475,   477,  2587,
     489,   490,   491,   499,   478,   479,   481,   483,   512,   485,
     487,   488,   492,   493,   517,   518,   495,   497,   500,    27,
     318,   501,  2587,  2587,  2587,   505,  2587,  2587,   245,   245,
     285,   285,   285,   285,   285,   285,   285,   285,   242,   250,
     250,  -822,   511,   513,  2196,    70,  -822,   311,  -822,   311,
    -822,   311,  -822,   311,   125,  -822,  2587,  -822,  -822,  -822,
    -822,  -822,  -822,  -822,  -822,  2587,  -822,   311,  -822,  -822,
    -822,  -822,  -822,  -822,  -822,  -822,   311,  -822,  -822,  -822,
    -822,  -822,  -822,   336,   339,   340,   342,   528,  2587,   536,
     503,   510,   405,  2587,  2587,   547,   548,  -822,   -49,   484,
     359,  2587,   550,  -822,  -822,  -822,   525,   360,   526,  -822,
    2587,   361,  2587,  -822,   -81,   554,  -822,  2587,  2587,   410,
     416,  -822,  -822,  -822,  -822,  -822,  -822,  2587,   555,   418,
     556,   529,  2587,  -822,  -822,  -822,  -822,  -822,  -822,  -822,
     558,  -822,  -822,  -822,  -822,  -822,   365,   368,   370,  -822,
    -822,  -822,  -822,  -822,  -822,   533,  2587,  2587,  2587,  2587,
    -822,  -822,  -822,  -822,  2587,  -822,  -822,  -822,  -822,  -822,
    2587,  2587,  -822,  -822,  -822,  2965,   544,  -822,   546,   564,
     575,  2587,   436,   551,   380,   382,  -822,  -822,  -822,  -822,
    -822,  -822,   560,  -822,   562,  -822,   376,   102,  -822,   580,
    -822,   585,   586,  -822,   588,  -822,   589,  -822,   584,  2196,
     591,  2587,  2587,   311,  -822,   565,   566,  2587,   311,  -822,
    -822,  2587,  -822,    53,  2587,   360,   592,   567,   360,   455,
     137,   457,   464,  -822,   -81,  -822,  -822,  -822,  -822,   569,
    2587,  -822,  2587,   594,   573,  2587,  -822,  -822,  -822,  -822,
     578,   579,    76,    88,   581,   582,   583,   587,  -822,  -822,
    2587,  2587,   590,  -822,  -822,  -822,  -822,   420,   421,  -822,
     595,  -822,   597,  -822,  2587,   311,   603,   612,   614,  2587,
    -822,  -822,  2587,  -822,  -822,  -822,   610,   615,   596,   598,
     519,  2587,   619,   563,   601,   360,  -822,   602,  -822,   361,
     620,    46,  -822,  -822,  -822,   626,  -822,  -822,  2587,   627,
     606,  -822,  -822,  2587,  -822,  2587,  -822,  -822,  -822,  -822,
    -822,   607,   611,  -822,  -822,  -822,   438,   439,   617,   618,
     336,   339,   340,  -822,  -822,  2587,  2587,  -822,  -822,  2587,
     621,  2587,  2587,  -822,  -822,  -822,  -822,   361,   638,  2587,
    -822,  2587,  -822,   622,   623,  -822,  -822,  -822,  -822,  -822,
    -822,  -822,  -822,  -822,  -822,  -822,  -822,   636,  -822,  -822,
    -822,   361,  -822,  -822,  -822,  -822,  2587,  -822,  -822
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     487,     0,   475,     1,   474,     0,     0,     0,   458,     0,
       0,   422,     0,     0,   449,     0,     0,     0,   266,     0,
     407,   411,   408,     0,     0,     0,     0,     0,     0,   450,
     405,     0,     0,     0,   400,   448,     0,     0,     0,   455,
     457,   403,   406,   413,   410,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   396,   397,     0,     0,     0,     0,   387,
     388,   389,   390,   391,   384,   385,   471,   479,   476,   483,
     485,   488,   398,   399,     0,     0,   167,   168,   367,     0,
       0,     0,   181,   182,   369,     0,     0,     0,    79,    80,
       0,     0,     0,     0,     0,   121,   122,     0,     0,     0,
       0,   112,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,    44,    49,    50,
      51,    52,    53,    54,    57,    58,     0,    63,    67,    65,
       0,     2,    12,    15,    17,     0,    76,    20,   192,   193,
     370,     0,     0,     0,     0,     0,     0,     0,   161,   162,
     366,     0,     0,   224,   225,   371,     0,   227,   228,   229,
     233,   234,   372,   256,   257,     0,     0,     0,   264,   265,
     377,     0,   451,     0,   276,   380,   272,   273,   452,     0,
       0,   239,   240,     0,   243,   244,   374,     0,   247,   248,
     375,     0,   250,   254,   255,   376,     0,   440,   446,   447,
     428,     0,     0,   473,   401,     0,   237,   238,   373,     0,
     279,   280,   378,   274,   275,   453,   456,   415,     0,     0,
     414,   417,   418,   412,     0,   298,   299,     0,   454,     0,
       0,   381,   281,   379,   314,   320,   463,   432,   423,   433,
     330,   336,   426,   427,   340,   382,   348,   347,   464,   441,
     442,   443,   352,   350,   349,   351,   353,     0,   444,     0,
       0,   383,     0,     0,   386,   394,   395,     0,   392,   481,
     445,     0,   469,   434,   431,     0,     0,   475,   477,   475,
     475,     0,     0,     0,   178,   175,     0,     0,     0,     0,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    24,    25,    27,    29,    30,    26,    31,
     101,    23,     0,   115,   116,     0,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   120,
       0,   118,   119,     0,     0,   133,   127,   128,   129,   130,
      55,    42,    45,    46,    47,    48,    43,    56,    64,   108,
       0,   183,   189,   184,   185,   190,   191,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   186,   187,   188,     0,     0,   173,   174,   368,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
       0,     0,   214,   215,     0,     0,     0,     0,   211,   210,
     136,     0,     0,     0,   199,   200,     0,     0,     0,     0,
     196,   195,     0,   231,   226,     0,   261,   258,     0,     0,
     291,   295,   293,     0,     0,   409,     0,     0,   246,   245,
     252,   249,     0,   402,     0,     0,     0,   236,   235,     0,
       0,   416,     0,     0,     0,     0,   312,   304,   306,   311,
     308,   313,     0,   310,   318,     0,     0,     0,   436,     0,
     438,     0,   331,     0,     0,   345,   343,     0,   360,   361,
     363,   364,   393,   475,   465,     0,     0,     0,     0,     0,
     471,   480,   475,   484,   486,     0,     0,   165,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    14,
       5,     7,     8,     9,    10,     6,     3,     4,    16,    18,
      19,    21,     0,     0,     0,     0,   143,     0,   155,     0,
     147,     0,   151,     0,   139,   212,     0,   219,   218,   223,
     222,   217,   221,   216,   220,     0,   197,     0,   204,   203,
     208,   207,   202,   206,   201,   205,     0,   232,   230,   262,
     259,   263,   260,     0,     0,     0,     0,   267,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   404,     0,     0,
       0,     0,   300,   305,   307,   309,     0,     0,     0,   321,
       0,     0,     0,   333,     0,   332,   337,     0,     0,   357,
     355,   354,   359,   362,   365,   482,   466,     0,   338,     0,
     322,     0,     0,   478,   166,   164,   180,   177,   179,   176,
       0,    75,    68,    70,    74,    72,     0,     0,     0,    78,
      77,    82,    81,    84,    83,     0,     0,     0,     0,     0,
      91,    92,    93,   100,     0,    94,    95,    96,    97,    98,
       0,     0,   110,   111,   102,     0,     0,   106,     0,     0,
       0,     0,     0,     0,     0,     0,   171,   169,   140,   153,
     145,   148,   142,   154,   146,   150,     0,     0,   209,     0,
     194,     0,   282,   292,   285,   296,   288,   294,   268,     0,
       0,     0,     0,     0,   429,     0,     0,     0,     0,   419,
     420,     0,   297,     0,     0,     0,   302,     0,     0,     0,
     324,     0,     0,   334,     0,   346,   344,   358,   356,     0,
       0,   435,     0,     0,     0,     0,    69,    71,    73,   124,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   125,
       0,     0,     0,   109,    60,   172,   170,     0,     0,   156,
     141,   152,   144,   149,     0,     0,     0,     0,     0,     0,
     270,   269,     0,   242,   253,   251,     0,     0,     0,     0,
     421,     0,     0,     0,     0,     0,   315,     0,   437,     0,
     325,     0,   425,   439,   335,     0,   339,   323,     0,     0,
       0,    85,    86,     0,    87,     0,    89,    99,   105,   104,
      22,     0,     0,    62,   158,   160,     0,     0,     0,     0,
       0,     0,     0,   271,   241,     0,     0,   278,   277,     0,
       0,     0,     0,   319,   303,   317,   327,     0,   326,     0,
     468,     0,   131,     0,     0,   132,   126,   157,   159,   213,
     198,   284,   287,   290,   459,   460,   430,     0,   461,   301,
     328,     0,   470,   472,    88,    90,     0,   329,   462
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -822,   -10,  -134,  -109,   233,  -327,    69,  -822,  -822,  -822,
    -416,  -822,  -822,  -822,   472,  -822,  -822,  -822,  -822,  -822,
    -822,  -822,  -822,  -822,  -822,  -822,  -822,   480,  -822,  -822,
    -822,  -822,  -822,  -822,  -822,  -822,  -822,  -822,  -822,  -822,
    -822,  -822,  -822,  -822,  -822,  -822,  -822,  -822,  -822,  -822,
    -822,  -822,  -822,  -822,  -822,  -822,  -822,  -822,  -822,  -822,
    -236,  -822,  -232,  -822,  -231,  -822,  -822,  -822,  -822,  -822,
    -822,  -822,  -723,  -315,  -822,  -822,  -822,  -822,   156,  -579,
    -821,   -54,  -576,  -375,  -822,  -822,  -822,  -822,  -822,  -822,
    -822,  -822,  -822,  -822,  -822,  -822,  -822,  -822,  -822,  -822,
    -822,  -312,  -822,  -822,  -822,  -293,  -822,  -822,  -822
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   690,   171,   172,   173,   174,   175,   349,   350,   176,
     177,   400,   585,   586,   451,   188,   189,   190,    86,    87,
      88,   426,   427,   428,    92,    93,    94,   406,   178,   179,
     180,   193,   194,   195,   200,   201,   202,   246,   247,   248,
     224,   225,   226,   228,   229,   230,   233,   234,   235,   208,
     209,   210,   214,   218,   255,   215,   250,   251,   252,   273,
     763,   836,   765,   837,   767,   838,   212,   643,   645,   644,
     268,   271,   787,   504,   275,   505,   506,   666,   276,   691,
     791,   282,   689,   285,   678,   677,   288,   297,   682,   298,
     301,   304,    78,   219,   509,   527,   670,   672,   315,   526,
     316,    79,   532,    80,   317,    81,   523,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     170,   529,   283,   191,   601,   531,    84,   211,   743,   309,
     742,   310,   424,   223,   310,   430,   236,   237,   311,   432,
     434,   311,   436,   243,   244,   312,   533,   534,   312,   256,
     259,   352,   380,   104,   735,   263,   398,   267,   906,  -467,
     272,   231,  -467,   239,   104,   182,   196,   284,   579,   289,
     -59,   378,   300,   183,   470,   303,   305,   306,   197,   198,
     851,  -316,   854,   308,   511,   857,   496,   679,   473,    82,
     184,   496,     3,    89,   321,   376,   621,   512,    90,   324,
     326,   328,   192,   873,   623,   622,   930,   338,   852,   377,
     474,   599,   600,   624,   789,   875,   792,   240,   185,   186,
     357,   395,   748,   471,   232,   513,   260,   396,   799,   199,
     937,   874,   262,   804,    83,   497,   498,   499,    91,   749,
     497,   498,   499,   876,   213,   379,   500,   280,   281,   407,
     408,   500,   904,   409,   830,   410,   411,   412,   413,   414,
     181,   680,   401,   402,   859,   472,   681,   750,   751,   353,
     381,   831,   313,   322,   756,   313,   420,   860,   325,   327,
     329,   779,   822,   399,   501,   401,   421,   354,   382,   501,
     286,   287,   261,   757,   292,   227,   502,   549,   550,   832,
     833,   502,   293,   238,   503,   861,   463,   241,   551,   503,
      85,   663,   664,   242,   342,   466,   425,   391,   675,   431,
     392,   393,   665,   433,   435,   245,   437,   394,   249,   475,
     476,   617,   618,   403,   404,   405,   314,   478,   415,   314,
     693,   480,   257,   867,   866,   632,   416,   290,   291,   187,
     685,   485,   486,   634,   633,   487,   403,   404,   422,   294,
     295,   296,   635,   343,   344,   345,   619,   620,   490,   491,
     258,   429,   346,   347,   348,   203,   204,   205,   206,   494,
    -342,   418,   264,   419,  -342,   464,  -342,   207,   216,   253,
     217,   254,   628,   629,   467,   590,   591,   592,   593,   594,
     595,   596,   597,   515,  -341,   516,   630,   631,  -341,   518,
    -341,   269,   520,   407,   408,   270,   479,   522,   588,   589,
     481,   524,   795,   796,   274,   277,   278,   279,   307,   318,
     319,   320,   323,   537,   488,   330,   331,   339,   351,   817,
     340,   341,   390,   355,   356,   358,   359,   360,   361,   553,
     555,   557,   362,   363,   364,   365,   366,   383,   367,   368,
     384,   385,   369,   370,   371,   560,   561,   372,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   439,   440,   373,   374,   375,
     386,   387,   388,   441,   389,   417,   397,   442,   443,   420,
     438,   477,   465,   468,   469,   483,   444,   482,   484,   489,
     492,   493,   538,   104,   508,   445,   495,   446,   447,   507,
    -424,   510,   514,   517,   519,   521,   448,   449,   554,   556,
     558,   439,   452,   525,   602,   528,   539,   450,   540,   453,
     535,   541,   536,   454,   455,   544,   581,   605,   543,   542,
     615,   604,   456,   607,   545,   647,   546,   547,   548,   552,
     559,   457,   580,   458,   459,   582,   583,   584,   -61,   587,
     609,   611,   460,   461,   613,   637,   616,   673,   639,   641,
     676,   646,   625,   450,   627,   648,   636,   649,   653,   654,
     658,   660,   650,   661,   652,   667,   668,   671,   674,   655,
     687,   692,   659,   694,   695,   662,   657,   701,   706,   702,
     703,   704,   705,   603,   707,   708,   716,   717,   718,   606,
     709,   608,   710,   610,   711,   612,   719,   614,   712,   683,
     713,   684,   714,   720,   721,   686,   722,   688,   723,   724,
     725,   626,   726,   727,   730,   731,   736,   728,   729,   696,
     732,   698,   733,   700,   638,   734,   737,   640,   642,   741,
     744,   769,   745,   771,   762,   772,   908,   764,   766,   715,
     768,   651,   773,   774,   777,   778,   781,   784,   656,   785,
     788,   794,   800,   802,   803,   805,   801,   782,   809,   790,
     786,   820,   738,   739,   740,   806,   688,   797,   807,   818,
     808,   819,   821,   798,   823,   829,   824,   834,   825,   827,
     826,   828,   835,  -283,   746,  -286,  -289,   839,   842,   855,
     846,   847,   856,   858,   865,   862,   758,   868,   869,   697,
     890,   699,   863,   871,   872,   759,   877,   878,   879,   891,
     793,   892,   880,   895,   886,   883,   887,   907,   896,   884,
     885,   897,   901,   898,   899,   902,   903,   905,   770,   909,
     911,   912,   915,   775,   776,   931,   916,   917,   918,   936,
     598,   783,   919,   920,   921,   423,   927,   934,   935,   922,
     688,   923,   688,   669,   462,     0,     0,   284,   284,     0,
       0,     0,     0,   747,     0,     0,   752,     0,   753,     0,
     754,     0,   755,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   760,     0,     0,     0,
       0,     0,     0,     0,     0,   761,   810,   811,   812,   813,
       0,     0,     0,     0,   814,     0,     0,     0,     0,     0,
     815,   816,     0,     0,     0,     0,     0,   780,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     864,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   840,
       0,   843,   844,     0,     0,     0,     0,   848,     0,     0,
       0,   850,     0,     0,   853,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     688,     0,     0,     0,     0,   870,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     881,   882,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   888,     0,     0,     0,     0,   893,
       0,     0,   894,     0,     0,     0,     0,     0,   841,     0,
       0,   900,   845,     0,     0,     0,     0,   849,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   910,     0,
       0,     0,     0,   913,     0,   914,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   924,   925,     0,     0,   926,
       4,   928,   929,     0,     0,     0,     0,     5,     6,   932,
       0,   933,     0,     0,   889,     0,     0,     0,     0,     7,
       8,     0,     9,     0,    10,    11,     0,    12,    13,     0,
       0,     0,     0,     0,     0,    14,   938,    15,    16,    17,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,    28,    29,     0,    30,     0,
       0,    31,    32,    33,     0,    34,    35,    36,    37,    38,
      39,    40,     0,    41,     0,     0,     0,    42,    43,    44,
      45,    46,     0,    47,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,    50,     0,     0,    51,
       0,    52,    53,    54,     0,     0,    55,     0,     0,     0,
      56,     0,    57,     0,     0,     0,    58,    59,    60,     0,
       0,     0,     0,    61,     0,    62,    63,    64,    65,    66,
      67,     4,    68,    69,    70,    71,    72,    73,     5,     6,
      74,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     9,     0,    10,    11,     0,    12,    13,
       0,     0,     0,     0,     0,    76,    14,    77,    15,    16,
      17,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,    28,    29,     0,    30,
       0,     0,    31,    32,    33,     0,    34,    35,    36,    37,
      38,    39,    40,     0,    41,     0,     0,     0,    42,    43,
      44,    45,    46,     0,    47,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,    50,     0,     0,
      51,     0,    52,    53,    54,     0,     0,    55,     0,     0,
       0,    56,     0,    57,     0,     0,     0,    58,    59,    60,
       0,     0,     0,     0,    61,     0,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,   299,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,     0,     0,     0,     0,     0,   530,     0,     0,     0,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,     0,     0,   102,     0,     0,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     106,     0,   107,     0,     0,     0,     0,     0,     0,     0,
     108,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,   111,   112,     0,     0,     0,     0,
       0,     0,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,     0,     0,     0,   125,   126,
     127,     0,   128,   129,   130,     0,   131,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,     0,   134,     0,     0,     0,   135,     0,     0,     0,
       0,     0,     0,     0,   136,     0,     0,   137,     0,     0,
     138,     0,   139,   140,   141,   142,     0,   143,   144,     0,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   302,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   101,     0,     0,
     102,     0,     0,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,   106,     0,   107,     0,     0,     0,
       0,     0,     0,     0,   108,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,   111,   112,
       0,     0,     0,     0,     0,     0,     0,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
       0,     0,   125,   126,   127,     0,   128,   129,   130,     0,
     131,   132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,     0,   134,     0,     0,     0,
     135,     0,     0,     0,     0,     0,     0,     0,   136,     0,
       0,   137,     0,     0,   138,     0,   139,   140,   141,   142,
       0,   143,   144,     0,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    95,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,     0,     0,    96,   332,     0,     0,     0,     0,     0,
       0,     0,     0,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,     0,     0,   102,
       0,     0,   103,   333,   334,   335,     0,     0,     0,     0,
       0,     0,   105,   106,   336,   107,     0,     0,     0,     0,
       0,     0,     0,   108,   109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   111,   112,     0,
       0,     0,     0,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,     0,
       0,   125,   126,   127,   337,   128,   129,   130,     0,   131,
     132,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   133,     0,   134,     0,     0,     0,   135,
       0,     0,     0,     0,     0,     0,     0,   136,     0,     0,
     137,     0,     0,   138,     0,   139,   140,   141,   142,     0,
     143,   144,     0,     0,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    95,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
       0,     0,   220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,     0,   221,   222,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,     0,     0,   102,     0,
       0,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   106,     0,   107,     0,     0,     0,     0,     0,
       0,     0,   108,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   111,   112,     0,     0,
       0,     0,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,     0,     0,
     125,   126,   127,     0,   128,   129,   130,     0,   131,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   133,     0,   134,     0,     0,     0,   135,     0,
       0,     0,     0,     0,     0,     0,   136,     0,     0,   137,
       0,     0,   138,     0,   139,   140,   141,   142,     0,   143,
     144,     0,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    95,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,     0,
       0,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,     0,     0,     0,     0,     0,     0,     0,   265,
     266,     0,     0,     0,     0,     0,     0,    98,    99,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,     0,     0,   102,     0,     0,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,   106,     0,   107,     0,     0,     0,     0,     0,     0,
       0,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,   111,   112,     0,     0,     0,
       0,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,     0,     0,   125,
     126,   127,     0,   128,   129,   130,     0,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   133,     0,   134,     0,     0,     0,   135,     0,     0,
       0,     0,     0,     0,     0,   136,     0,     0,   137,     0,
       0,   138,     0,   139,   140,   141,   142,     0,   143,   144,
       0,     0,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    95,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,     0,     0,
      96,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,     0,     0,   102,     0,     0,   103,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   107,     0,     0,     0,     0,     0,     0,     0,
     108,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,   111,   112,     0,     0,     0,     0,
       0,     0,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,     0,     0,     0,   125,   126,
     127,     0,   128,   129,   130,     0,   131,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,     0,   134,     0,     0,     0,   135,     0,     0,     0,
       0,     0,     0,     0,   136,     0,     0,   137,     0,     0,
     138,     0,   139,   140,   141,   142,     0,   143,   144,     0,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   331,     0,
       0,     0,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,     0,     0,   102,     0,
       0,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   106,     0,   107,     0,     0,     0,     0,     0,
       0,     0,   108,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   111,   112,     0,     0,
       0,     0,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,     0,     0,
     125,   126,   127,     0,   128,   129,   130,     0,   131,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   133,     0,   134,     0,     0,     0,   135,     0,
       0,     0,     0,     0,     0,     0,   136,     0,     0,   137,
       0,     0,   138,     0,   139,   140,   141,   142,     0,   143,
     144,     0,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    95,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,     0,
       0,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,    99,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,     0,     0,   102,     0,     0,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,   106,     0,   107,     0,     0,     0,     0,     0,     0,
       0,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,   111,   112,     0,     0,     0,
       0,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,     0,     0,   125,
     126,   127,     0,   128,   129,   130,     0,   131,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   133,     0,   134,     0,     0,     0,   135,     0,     0,
       0,     0,     0,     0,     0,   136,     0,     0,   137,     0,
       0,   138,     0,   139,   140,   141,   142,     0,   143,   144,
       0,     0,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    95,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,     0,     0,
      96,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,     0,     0,   102,     0,     0,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     106,     0,   107,     0,     0,     0,     0,     0,     0,     0,
     108,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,   112,     0,     0,     0,     0,
       0,     0,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,     0,     0,     0,   125,   126,
     127,     0,   128,   129,   130,     0,   131,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,     0,   134,     0,     0,     0,   135,     0,     0,     0,
       0,     0,     0,     0,   136,     0,     0,   137,     0,     0,
     138,     0,   139,   140,   141,   142,     0,   143,   144,     0,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    95,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,     0,     0,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    99,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,     0,     0,   102,     0,     0,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   106,
       0,   107,     0,     0,     0,     0,     0,     0,     0,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,   112,     0,     0,     0,     0,     0,
       0,     0,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,     0,     0,     0,   125,   126,   127,
       0,   128,   129,   130,     0,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   133,
       0,   134,     0,     0,     0,   135,     0,     0,     0,     0,
       0,     0,     0,   136,     0,     0,   137,     0,     0,   138,
       0,   139,   140,   141,   142,     0,   143,   144,     0,     0,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169
};

static const yytype_int16 yycheck[] =
{
      10,   316,    56,    13,   420,   317,    24,    17,   587,     4,
     586,     6,    24,    23,     6,    24,    26,    27,    13,    24,
      24,    13,    24,    33,    34,    20,   319,   320,    20,    39,
      68,    20,    20,    82,     7,    45,    20,    47,   859,    34,
      50,    24,    34,    90,    82,    24,    24,    57,   375,    59,
      34,    86,    62,    32,    53,    65,    66,    67,    36,    37,
       7,    20,   785,    73,     7,   788,    25,    86,    20,   208,
      49,    25,     0,    26,    84,    20,    45,    20,    31,    89,
      90,    91,    13,     7,    45,    54,   907,    97,    35,    34,
      42,   418,   419,    54,   670,     7,   672,   144,    77,    78,
     110,   191,    32,   102,    87,    48,   144,   197,   687,    87,
     931,    35,    43,   692,   208,    74,    75,    76,    71,    49,
      74,    75,    76,    35,   208,   160,    85,   208,   209,     8,
       9,    85,   855,    12,    32,    14,    15,    16,    17,    18,
      22,   160,    79,    80,     7,   144,   165,    77,    78,   138,
     138,    49,   147,    84,    29,   147,   129,    20,    89,    90,
      91,   210,   741,   147,   123,    79,    80,   156,   156,   123,
     157,   158,   210,    48,    97,    24,   135,    74,    75,    77,
      78,   135,   105,    90,   143,    48,   196,    34,    85,   143,
     208,    74,    75,    34,    25,   205,   208,   187,   513,   208,
     190,   191,    85,   208,   208,    24,   208,   197,    24,   219,
     220,    56,    57,   150,   151,   152,   211,   227,    97,   211,
     532,   231,   144,   802,   800,    45,   105,    42,    43,   208,
     523,   241,   242,    45,    54,   245,   150,   151,   152,   162,
     163,   164,    54,    74,    75,    76,    56,    57,   258,   259,
      68,   182,    83,    84,    85,    42,    43,    44,    45,   269,
       0,    19,   208,    21,     4,   196,     6,    54,   208,   208,
     210,   210,    56,    57,   205,   409,   410,   411,   412,   413,
     414,   415,   416,     5,     0,     7,    56,    57,     4,   299,
       6,    34,   302,     8,     9,   208,   227,   307,   407,   408,
     231,   311,   677,   678,   208,   208,   208,   208,   174,     6,
       4,     4,    24,   323,   245,   210,    20,    34,   210,   735,
      34,    34,   190,    34,    34,    34,    34,    34,    34,   339,
     340,   341,    34,    34,    34,    34,    34,    20,    34,    34,
      20,    20,    34,    34,    34,   355,   356,    34,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,    24,    25,    34,    34,    34,
      20,    20,    20,    32,    20,   130,   190,    36,    37,   129,
      24,     7,    29,    46,    46,    69,    45,    29,   147,    34,
      13,   152,   323,    82,   147,    54,     7,    56,    57,     7,
     147,   147,     7,     7,     7,     7,    65,    66,   339,   340,
     341,    24,    25,    13,   424,    34,    72,    76,    72,    32,
      29,    72,    29,    36,    37,    35,   208,    48,    34,    72,
     440,    24,    45,    24,    35,   208,    35,    35,    35,    35,
      34,    54,    34,    56,    57,    34,    34,    34,    34,    34,
      24,    24,    65,    66,    24,   465,    33,   511,   468,   469,
     514,    42,    34,    76,    33,     7,    34,   477,     7,     7,
       7,   102,   482,     7,   484,    34,    20,   147,     7,   489,
      34,    34,   492,   208,   208,   495,    69,   210,    35,   210,
     210,   210,   210,   424,    35,    35,     7,     7,     7,   430,
      35,   432,    35,   434,    35,   436,     7,   438,    35,   519,
      35,   521,    35,    35,    35,   525,    35,   527,    35,     7,
      35,   452,    35,    35,     7,     7,   208,    35,    35,   539,
      35,   541,    35,   543,   465,    35,    35,   468,   469,    34,
      29,    13,    29,     7,   208,    42,   861,   208,   208,   559,
     208,   482,    42,   148,     7,     7,    72,     7,   489,    34,
      34,     7,     7,     7,    35,     7,   148,   208,    35,   208,
     210,     7,   582,   583,   584,   210,   586,   167,   210,    35,
     210,    35,     7,   167,   148,   209,    35,     7,   208,    29,
     208,    29,     7,     7,   604,     7,     7,    13,     7,     7,
      35,    35,    35,   148,    35,   148,   616,    13,    35,   540,
       7,   542,   148,    35,    35,   625,    35,    35,    35,     7,
     674,     7,    35,    13,    29,    35,    29,     7,    13,   209,
     209,    35,    13,    35,   115,    72,    35,    35,   648,    13,
      13,    35,    35,   653,   654,     7,    35,   209,   209,    13,
     417,   661,    35,    35,   890,   175,    35,    35,    35,   891,
     670,   892,   672,   507,   192,    -1,    -1,   677,   678,    -1,
      -1,    -1,    -1,   604,    -1,    -1,   607,    -1,   609,    -1,
     611,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   627,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   636,   716,   717,   718,   719,
      -1,    -1,    -1,    -1,   724,    -1,    -1,    -1,    -1,    -1,
     730,   731,    -1,    -1,    -1,    -1,    -1,   658,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     794,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   769,
      -1,   771,   772,    -1,    -1,    -1,    -1,   777,    -1,    -1,
      -1,   781,    -1,    -1,   784,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     800,    -1,    -1,    -1,    -1,   805,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     820,   821,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   834,    -1,    -1,    -1,    -1,   839,
      -1,    -1,   842,    -1,    -1,    -1,    -1,    -1,   769,    -1,
      -1,   851,   773,    -1,    -1,    -1,    -1,   778,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   868,    -1,
      -1,    -1,    -1,   873,    -1,   875,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   895,   896,    -1,    -1,   899,
       3,   901,   902,    -1,    -1,    -1,    -1,    10,    11,   909,
      -1,   911,    -1,    -1,   835,    -1,    -1,    -1,    -1,    22,
      23,    -1,    25,    -1,    27,    28,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,   936,    40,    41,    42,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    88,    89,    -1,    91,    -1,
      -1,    94,    95,    96,    -1,    98,    99,   100,   101,   102,
     103,   104,    -1,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,    -1,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   142,
      -1,   144,   145,   146,    -1,    -1,   149,    -1,    -1,    -1,
     153,    -1,   155,    -1,    -1,    -1,   159,   160,   161,    -1,
      -1,    -1,    -1,   166,    -1,   168,   169,   170,   171,   172,
     173,     3,   175,   176,   177,   178,   179,   180,    10,    11,
     183,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    -1,    25,    -1,    27,    28,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,   208,    38,   210,    40,    41,
      42,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    88,    89,    -1,    91,
      -1,    -1,    94,    95,    96,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,    -1,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     142,    -1,   144,   145,   146,    -1,    -1,   149,    -1,    -1,
      -1,   153,    -1,   155,    -1,    -1,    -1,   159,   160,   161,
      -1,    -1,    -1,    -1,   166,    -1,   168,   169,   170,   171,
     172,   173,    -1,   175,   176,   177,   178,   179,   180,    -1,
      -1,   183,   184,     7,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,
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
     174,    -1,   176,   177,   178,   179,    -1,   181,   182,    -1,
      -1,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,     7,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
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
      -1,   181,   182,    -1,    -1,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,     9,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      -1,    -1,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,   135,   136,   137,   138,    -1,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   154,    -1,   156,    -1,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,
     171,    -1,    -1,   174,    -1,   176,   177,   178,   179,    -1,
     181,   182,    -1,    -1,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,     9,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,   137,   138,    -1,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   154,    -1,   156,    -1,    -1,    -1,   160,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,   171,
      -1,    -1,   174,    -1,   176,   177,   178,   179,    -1,   181,
     182,    -1,    -1,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,     9,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
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
      -1,    -1,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,     9,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,
      84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,   132,   133,
     134,    -1,   136,   137,   138,    -1,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     154,    -1,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   168,    -1,    -1,   171,    -1,    -1,
     174,    -1,   176,   177,   178,   179,    -1,   181,   182,    -1,
      -1,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,   137,   138,    -1,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   154,    -1,   156,    -1,    -1,    -1,   160,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,   171,
      -1,    -1,   174,    -1,   176,   177,   178,   179,    -1,   181,
     182,    -1,    -1,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,     9,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
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
      -1,   174,    -1,   176,   177,   178,   179,    -1,   181,   182,
      -1,    -1,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,     9,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,   132,   133,
     134,    -1,   136,   137,   138,    -1,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     154,    -1,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   168,    -1,    -1,   171,    -1,    -1,
     174,    -1,   176,   177,   178,   179,    -1,   181,   182,    -1,
      -1,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,     9,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    24,
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
      -1,   176,   177,   178,   179,    -1,   181,   182,    -1,    -1,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   319,   320,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    86,    88,    89,
      91,    94,    95,    96,    98,    99,   100,   101,   102,   103,
     104,   106,   110,   111,   112,   113,   114,   116,   117,   131,
     139,   142,   144,   145,   146,   149,   153,   155,   159,   160,
     161,   166,   168,   169,   170,   171,   172,   173,   175,   176,
     177,   178,   179,   180,   183,   184,   208,   210,   304,   313,
     315,   317,   208,   208,    24,   208,   230,   231,   232,    26,
      31,    71,   236,   237,   238,     9,    24,    34,    50,    51,
      52,    67,    70,    73,    82,    83,    84,    86,    94,    95,
     107,   108,   109,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   132,   133,   134,   136,   137,
     138,   140,   141,   154,   156,   160,   168,   171,   174,   176,
     177,   178,   179,   181,   182,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     213,   214,   215,   216,   217,   218,   221,   222,   240,   241,
     242,    22,    24,    32,    49,    77,    78,   208,   227,   228,
     229,   213,   218,   243,   244,   245,    24,    36,    37,    87,
     246,   247,   248,    42,    43,    44,    45,    54,   261,   262,
     263,   213,   278,   208,   264,   267,   208,   210,   265,   305,
      24,    36,    37,   213,   252,   253,   254,    24,   255,   256,
     257,    24,    87,   258,   259,   260,   213,   213,    90,    90,
     144,    34,    34,   213,   213,    24,   249,   250,   251,    24,
     268,   269,   270,   208,   210,   266,   213,   144,    68,    68,
     144,   210,   218,   213,   208,    42,    43,   213,   282,    34,
     208,   283,   213,   271,   208,   286,   290,   208,   208,   208,
     208,   209,   293,   293,   213,   295,   157,   158,   298,   213,
      42,    43,    97,   105,   162,   163,   164,   299,   301,     7,
     213,   302,     7,   213,   303,   213,   213,   174,   213,     4,
       6,    13,    20,   147,   211,   310,   312,   316,     6,     4,
       4,   213,   218,    24,   213,   218,   213,   218,   213,   218,
     210,    20,    25,    74,    75,    76,    85,   135,   213,    34,
      34,    34,    25,    74,    75,    76,    83,    84,    85,   219,
     220,   210,    20,   138,   156,    34,    34,   213,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    20,    34,    86,   160,
      20,   138,   156,    20,    20,    20,    20,    20,    20,    20,
     190,   187,   190,   191,   197,   191,   197,   190,    20,   147,
     223,    79,    80,   150,   151,   152,   239,     8,     9,    12,
      14,    15,    16,    17,    18,    97,   105,   130,    19,    21,
     129,    80,   152,   239,    24,   208,   233,   234,   235,   218,
      24,   208,    24,   208,    24,   208,    24,   208,    24,    24,
      25,    32,    36,    37,    45,    54,    56,    57,    65,    66,
      76,   226,    25,    32,    36,    37,    45,    54,    56,    57,
      65,    66,   226,   213,   218,    29,   213,   218,    46,    46,
      53,   102,   144,    20,    42,   213,   213,     7,   213,   218,
     213,   218,    29,    69,   147,   213,   213,   213,   218,    34,
     213,   213,    13,   152,   213,     7,    25,    74,    75,    76,
      85,   123,   135,   143,   285,   287,   288,     7,   147,   306,
     147,     7,    20,    48,     7,     5,     7,     7,   213,     7,
     213,     7,   213,   318,   213,    13,   311,   307,    34,   285,
     208,   313,   314,   317,   317,    29,    29,   213,   218,    72,
      72,    72,    72,    34,    35,    35,    35,    35,    35,    74,
      75,    85,    35,   213,   218,   213,   218,   213,   218,    34,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   217,
      34,   208,    34,    34,    34,   224,   225,    34,   215,   215,
     214,   214,   214,   214,   214,   214,   214,   214,   216,   217,
     217,   222,   213,   218,    24,    48,   218,    24,   218,    24,
     218,    24,   218,    24,   218,   213,    33,    56,    57,    56,
      57,    45,    54,    45,    54,    34,   218,    33,    56,    57,
      56,    57,    45,    54,    45,    54,    34,   213,   218,   213,
     218,   213,   218,   279,   281,   280,    42,   208,     7,   213,
     213,   218,   213,     7,     7,   213,   218,    69,     7,   213,
     102,     7,   213,    74,    75,    85,   289,    34,    20,   290,
     308,   147,   309,   293,     7,   285,   293,   297,   296,    86,
     160,   165,   300,   213,   213,   317,   213,    34,   213,   294,
     213,   291,    34,   313,   208,   208,   213,   218,   213,   218,
     213,   210,   210,   210,   210,   210,    35,    35,    35,    35,
      35,    35,    35,    35,    35,   213,     7,     7,     7,     7,
      35,    35,    35,    35,     7,    35,    35,    35,    35,    35,
       7,     7,    35,    35,    35,     7,   208,    35,   213,   213,
     213,    34,   294,   291,    29,    29,   213,   218,    32,    49,
      77,    78,   218,   218,   218,   218,    29,    48,   213,   213,
     218,   218,   208,   272,   208,   274,   208,   276,   208,    13,
     213,     7,    42,    42,   148,   213,   213,     7,     7,   210,
     218,    72,   208,   213,     7,    34,   210,   284,    34,   294,
     208,   292,   294,   293,     7,   295,   295,   167,   167,   291,
       7,   148,     7,    35,   291,     7,   210,   210,   210,    35,
     213,   213,   213,   213,   213,   213,   213,   222,    35,    35,
       7,     7,   291,   148,    35,   208,   208,    29,    29,   209,
      32,    49,    77,    78,     7,     7,   273,   275,   277,    13,
     213,   218,     7,   213,   213,   218,    35,    35,   213,   218,
     213,     7,    35,   213,   284,     7,    35,   284,   148,     7,
      20,    48,   148,   148,   293,    35,   294,   291,    13,    35,
     213,    35,    35,     7,    35,     7,    35,    35,    35,    35,
      35,   213,   213,    35,   209,   209,    29,    29,   213,   218,
       7,     7,     7,   213,   213,    13,    13,    35,    35,   115,
     213,    13,    72,    35,   284,    35,   292,     7,   285,    13,
     213,    13,    35,   213,   213,    35,    35,   209,   209,    35,
      35,   272,   274,   276,   213,   213,   213,    35,   213,   213,
     292,     7,   213,   213,    35,    35,    13,   292,   213
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   212,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   214,   214,   214,   215,   215,   216,   216,   216,
     217,   217,   217,   218,   219,   219,   219,   219,   219,   219,
     219,   220,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   223,
     222,   224,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   225,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   226,   226,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   228,   228,   228,   228,
     228,   229,   229,   230,   230,   231,   231,   232,   232,   233,
     233,   234,   234,   235,   235,   236,   236,   236,   237,   237,
     237,   238,   238,   239,   239,   239,   240,   240,   240,   241,
     241,   241,   242,   242,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   245,   245,   246,   246,   246,   246,
     246,   247,   247,   248,   248,   249,   250,   251,   251,   252,
     252,   253,   253,   254,   254,   255,   256,   257,   257,   258,
     258,   258,   259,   259,   260,   260,   261,   261,   261,   261,
     261,   262,   262,   262,   263,   263,   264,   264,   264,   264,
     264,   264,   265,   265,   266,   266,   267,   268,   269,   270,
     270,   271,   272,   273,   272,   274,   275,   274,   276,   277,
     276,   279,   278,   280,   278,   281,   278,   282,   282,   282,
     283,   283,   284,   284,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   287,   286,   288,   286,   289,   286,
     290,   290,   291,   291,   292,   292,   292,   292,   292,   292,
     293,   293,   293,   293,   293,   293,   293,   293,   294,   294,
     295,   295,   295,   296,   295,   297,   295,   298,   298,   299,
     299,   299,   299,   299,   300,   300,   300,   300,   300,   301,
     302,   302,   302,   303,   303,   303,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   305,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   306,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   307,   304,   308,   304,   309,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   310,   304,   311,
     304,   312,   304,   304,   304,   304,   313,   314,   313,   316,
     315,   318,   317,   317,   317,   317,   317,   320,   319
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
       2,     2,     2,     2,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     3,     2,     2,     1,     1,     2,     2,
       1,     2,     3,     1,     4,     1,     1,     1,     0,     3,
       1,     1,     2,     1,     2,     2,     3,     2,     2,     5,
       5,     6,     1,     2,     0,     6,     2,     2,     2,     5,
       8,     2,     2,     2,     0,     5,     0,     6,     0,     6,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     2,     2,     2,     2,     1,     2,     1,     1,     8,
       8,     8,    10,     2,     2,     3,     4,     0,     7,     0,
       8,     0,     8,     2,     1,     0,     1,     0,     4,     0,
       3,     0,     4,     1,     3,     1,     3,     0,     2
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
#line 2928 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 80 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2937 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 84 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2945 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 87 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2953 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 90 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2961 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 93 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2969 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 96 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2977 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 99 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2985 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 102 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2993 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 109 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3001 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 112 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3010 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 125 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3019 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 129 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3028 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 137 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 3037 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 141 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 3046 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 148 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3054 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 153 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3062 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 156 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3070 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 159 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3078 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 162 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3086 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 165 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3094 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 168 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3102 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 171 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3110 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 176 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3118 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 181 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3127 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 185 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3136 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 189 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3145 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 193 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3154 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 197 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3163 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 201 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3172 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 205 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3181 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 209 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3190 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 213 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3199 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 217 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3208 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 221 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3217 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 225 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3226 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 229 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3235 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 233 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3244 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 237 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3253 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 241 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3262 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 245 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3271 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 249 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3280 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 253 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3289 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 257 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3298 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 261 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3307 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 265 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3316 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 269 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3325 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 273 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3334 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 277 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3343 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 281 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3352 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 285 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3361 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 291 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3370 "src-generated/ugbc.tab.c"
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
#line 3382 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 302 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3391 "src-generated/ugbc.tab.c"
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
#line 3403 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 313 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3411 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 316 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3419 "src-generated/ugbc.tab.c"
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
#line 3433 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 328 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3442 "src-generated/ugbc.tab.c"
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
#line 3454 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 339 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3463 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 343 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3472 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 347 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3481 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 351 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3490 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 355 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3499 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 359 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3508 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 363 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3517 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 367 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3526 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 371 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3534 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 374 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3542 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 377 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3550 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 380 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3558 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 383 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3566 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 386 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3574 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 389 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3582 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 392 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3590 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 395 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3598 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 398 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3606 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 401 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3614 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 404 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3622 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 407 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3630 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 410 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3638 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 413 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3646 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 416 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3654 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 419 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3662 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 422 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3670 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 425 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3678 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 428 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3686 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 431 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3694 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 434 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3702 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 437 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3710 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 440 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3718 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 443 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3726 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 446 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3734 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 449 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3742 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 452 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3750 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 455 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3758 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 458 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3766 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 461 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3774 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 464 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3782 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 467 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3790 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 469 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3799 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 473 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3807 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 476 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3815 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 479 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3824 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 483 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3833 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 487 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3842 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: PEN COLORS  */
#line 491 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3851 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: PEN DEFAULT  */
#line 495 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3860 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: DEFAULT PEN  */
#line 499 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3869 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: PAPER COLORS  */
#line 503 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3878 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: PAPER DEFAULT  */
#line 507 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3887 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: DEFAULT PAPER  */
#line 511 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3896 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: WIDTH  */
#line 515 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3904 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: HEIGHT  */
#line 518 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3912 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: TIMER  */
#line 521 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3920 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PEN DOLLAR OP expr CP  */
#line 524 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 3928 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER DOLLAR OP expr CP  */
#line 527 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3936 "src-generated/ugbc.tab.c"
    break;

  case 126: /* exponential: CMOVE DOLLAR OP expr COMMA expr CP  */
#line 530 "src/ugbc.y"
                                         {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3944 "src-generated/ugbc.tab.c"
    break;

  case 127: /* exponential: CUP DOLLAR  */
#line 533 "src/ugbc.y"
                 {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 3952 "src-generated/ugbc.tab.c"
    break;

  case 128: /* exponential: CDOWN DOLLAR  */
#line 536 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 3960 "src-generated/ugbc.tab.c"
    break;

  case 129: /* exponential: CLEFT DOLLAR  */
#line 539 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 3968 "src-generated/ugbc.tab.c"
    break;

  case 130: /* exponential: CRIGHT DOLLAR  */
#line 542 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 3976 "src-generated/ugbc.tab.c"
    break;

  case 131: /* exponential: AT DOLLAR OP expr COMMA expr CP  */
#line 545 "src/ugbc.y"
                                      {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3984 "src-generated/ugbc.tab.c"
    break;

  case 132: /* exponential: LOCATE DOLLAR OP expr COMMA expr CP  */
#line 548 "src/ugbc.y"
                                          {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3992 "src-generated/ugbc.tab.c"
    break;

  case 133: /* exponential: TAB DOLLAR  */
#line 551 "src/ugbc.y"
                 {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 4000 "src-generated/ugbc.tab.c"
    break;

  case 134: /* exponential: XCURS  */
#line 554 "src/ugbc.y"
            {
        (yyval.string) = text_get_xcurs( _environment )->name;
    }
#line 4008 "src-generated/ugbc.tab.c"
    break;

  case 135: /* exponential: YCURS  */
#line 557 "src/ugbc.y"
            {
        (yyval.string) = text_get_ycurs( _environment )->name;
    }
#line 4016 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_simple: AT direct_integer  */
#line 565 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4024 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_simple: Identifier AT direct_integer  */
#line 568 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4032 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 571 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4040 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 574 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4048 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 577 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4056 "src-generated/ugbc.tab.c"
    break;

  case 143: /* bank_definition_simple: DATA AT direct_integer  */
#line 580 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4064 "src-generated/ugbc.tab.c"
    break;

  case 144: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 584 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4072 "src-generated/ugbc.tab.c"
    break;

  case 145: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 587 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4080 "src-generated/ugbc.tab.c"
    break;

  case 146: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 590 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4088 "src-generated/ugbc.tab.c"
    break;

  case 147: /* bank_definition_simple: CODE AT direct_integer  */
#line 593 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4096 "src-generated/ugbc.tab.c"
    break;

  case 148: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 597 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4104 "src-generated/ugbc.tab.c"
    break;

  case 149: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 600 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4112 "src-generated/ugbc.tab.c"
    break;

  case 150: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 603 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4120 "src-generated/ugbc.tab.c"
    break;

  case 151: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 606 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4128 "src-generated/ugbc.tab.c"
    break;

  case 152: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 610 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4136 "src-generated/ugbc.tab.c"
    break;

  case 153: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 613 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4144 "src-generated/ugbc.tab.c"
    break;

  case 154: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 616 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4152 "src-generated/ugbc.tab.c"
    break;

  case 155: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 619 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4160 "src-generated/ugbc.tab.c"
    break;

  case 156: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 625 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4168 "src-generated/ugbc.tab.c"
    break;

  case 157: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 628 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4176 "src-generated/ugbc.tab.c"
    break;

  case 158: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 631 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4184 "src-generated/ugbc.tab.c"
    break;

  case 159: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 634 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4192 "src-generated/ugbc.tab.c"
    break;

  case 160: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 637 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4200 "src-generated/ugbc.tab.c"
    break;

  case 163: /* raster_definition_simple: Identifier AT direct_integer  */
#line 646 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 4208 "src-generated/ugbc.tab.c"
    break;

  case 164: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 649 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 4216 "src-generated/ugbc.tab.c"
    break;

  case 165: /* raster_definition_expression: Identifier AT expr  */
#line 654 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4224 "src-generated/ugbc.tab.c"
    break;

  case 166: /* raster_definition_expression: AT expr WITH Identifier  */
#line 657 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4232 "src-generated/ugbc.tab.c"
    break;

  case 169: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 666 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 4240 "src-generated/ugbc.tab.c"
    break;

  case 170: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 669 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 4248 "src-generated/ugbc.tab.c"
    break;

  case 171: /* next_raster_definition_expression: Identifier AT expr  */
#line 674 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 4256 "src-generated/ugbc.tab.c"
    break;

  case 172: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 677 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4264 "src-generated/ugbc.tab.c"
    break;

  case 175: /* color_definition_simple: BORDER direct_integer  */
#line 686 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 4272 "src-generated/ugbc.tab.c"
    break;

  case 176: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 689 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4280 "src-generated/ugbc.tab.c"
    break;

  case 177: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 692 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4288 "src-generated/ugbc.tab.c"
    break;

  case 178: /* color_definition_expression: BORDER expr  */
#line 697 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 4296 "src-generated/ugbc.tab.c"
    break;

  case 179: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 700 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4304 "src-generated/ugbc.tab.c"
    break;

  case 180: /* color_definition_expression: SPRITE expr TO expr  */
#line 703 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4312 "src-generated/ugbc.tab.c"
    break;

  case 186: /* wait_definition_simple: direct_integer CYCLES  */
#line 717 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4320 "src-generated/ugbc.tab.c"
    break;

  case 187: /* wait_definition_simple: direct_integer TICKS  */
#line 720 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4328 "src-generated/ugbc.tab.c"
    break;

  case 188: /* wait_definition_simple: direct_integer milliseconds  */
#line 723 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4336 "src-generated/ugbc.tab.c"
    break;

  case 189: /* wait_definition_expression: expr CYCLES  */
#line 728 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4344 "src-generated/ugbc.tab.c"
    break;

  case 190: /* wait_definition_expression: expr TICKS  */
#line 731 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4352 "src-generated/ugbc.tab.c"
    break;

  case 191: /* wait_definition_expression: expr milliseconds  */
#line 734 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4360 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 744 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4368 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 747 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4376 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 750 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4384 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 753 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4392 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 756 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4400 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_simple: direct_integer ENABLE  */
#line 759 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4408 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_simple: direct_integer DISABLE  */
#line 762 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4416 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 765 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4424 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 768 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4432 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 771 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4440 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 774 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4448 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 777 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4456 "src-generated/ugbc.tab.c"
    break;

  case 206: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 780 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4464 "src-generated/ugbc.tab.c"
    break;

  case 207: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 783 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4472 "src-generated/ugbc.tab.c"
    break;

  case 208: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 786 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4480 "src-generated/ugbc.tab.c"
    break;

  case 209: /* sprite_definition_expression: expr DATA FROM expr  */
#line 791 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4488 "src-generated/ugbc.tab.c"
    break;

  case 210: /* sprite_definition_expression: expr MULTICOLOR  */
#line 794 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4496 "src-generated/ugbc.tab.c"
    break;

  case 211: /* sprite_definition_expression: expr MONOCOLOR  */
#line 797 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4504 "src-generated/ugbc.tab.c"
    break;

  case 212: /* sprite_definition_expression: expr COLOR expr  */
#line 800 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4512 "src-generated/ugbc.tab.c"
    break;

  case 213: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 803 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4520 "src-generated/ugbc.tab.c"
    break;

  case 214: /* sprite_definition_expression: expr ENABLE  */
#line 806 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4528 "src-generated/ugbc.tab.c"
    break;

  case 215: /* sprite_definition_expression: expr DISABLE  */
#line 809 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4536 "src-generated/ugbc.tab.c"
    break;

  case 216: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 812 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4544 "src-generated/ugbc.tab.c"
    break;

  case 217: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 815 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4552 "src-generated/ugbc.tab.c"
    break;

  case 218: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 818 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4560 "src-generated/ugbc.tab.c"
    break;

  case 219: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 821 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4568 "src-generated/ugbc.tab.c"
    break;

  case 220: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 824 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4576 "src-generated/ugbc.tab.c"
    break;

  case 221: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 827 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4584 "src-generated/ugbc.tab.c"
    break;

  case 222: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 830 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4592 "src-generated/ugbc.tab.c"
    break;

  case 223: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 833 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4600 "src-generated/ugbc.tab.c"
    break;

  case 226: /* bitmap_definition_simple: AT direct_integer  */
#line 842 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4608 "src-generated/ugbc.tab.c"
    break;

  case 227: /* bitmap_definition_simple: ENABLE  */
#line 845 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4616 "src-generated/ugbc.tab.c"
    break;

  case 228: /* bitmap_definition_simple: DISABLE  */
#line 848 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4624 "src-generated/ugbc.tab.c"
    break;

  case 229: /* bitmap_definition_simple: CLEAR  */
#line 851 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4632 "src-generated/ugbc.tab.c"
    break;

  case 230: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 854 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4640 "src-generated/ugbc.tab.c"
    break;

  case 231: /* bitmap_definition_expression: AT expr  */
#line 860 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4648 "src-generated/ugbc.tab.c"
    break;

  case 232: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 863 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4656 "src-generated/ugbc.tab.c"
    break;

  case 235: /* textmap_definition_simple: AT direct_integer  */
#line 873 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4664 "src-generated/ugbc.tab.c"
    break;

  case 236: /* textmap_definition_expression: AT expr  */
#line 878 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4672 "src-generated/ugbc.tab.c"
    break;

  case 239: /* text_definition_simple: ENABLE  */
#line 887 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4680 "src-generated/ugbc.tab.c"
    break;

  case 240: /* text_definition_simple: DISABLE  */
#line 890 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4688 "src-generated/ugbc.tab.c"
    break;

  case 241: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 895 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4696 "src-generated/ugbc.tab.c"
    break;

  case 242: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 898 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4704 "src-generated/ugbc.tab.c"
    break;

  case 245: /* tiles_definition_simple: AT direct_integer  */
#line 907 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4712 "src-generated/ugbc.tab.c"
    break;

  case 246: /* tiles_definition_expression: AT expr  */
#line 912 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4720 "src-generated/ugbc.tab.c"
    break;

  case 249: /* colormap_definition_simple: AT direct_integer  */
#line 921 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4728 "src-generated/ugbc.tab.c"
    break;

  case 250: /* colormap_definition_simple: CLEAR  */
#line 924 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4736 "src-generated/ugbc.tab.c"
    break;

  case 251: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 927 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4744 "src-generated/ugbc.tab.c"
    break;

  case 252: /* colormap_definition_expression: AT expr  */
#line 932 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4752 "src-generated/ugbc.tab.c"
    break;

  case 253: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 935 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4760 "src-generated/ugbc.tab.c"
    break;

  case 256: /* screen_definition_simple: ON  */
#line 945 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4768 "src-generated/ugbc.tab.c"
    break;

  case 257: /* screen_definition_simple: OFF  */
#line 948 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4776 "src-generated/ugbc.tab.c"
    break;

  case 258: /* screen_definition_simple: ROWS direct_integer  */
#line 951 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4784 "src-generated/ugbc.tab.c"
    break;

  case 259: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 954 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4792 "src-generated/ugbc.tab.c"
    break;

  case 260: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 957 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4800 "src-generated/ugbc.tab.c"
    break;

  case 261: /* screen_definition_expression: ROWS expr  */
#line 962 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4808 "src-generated/ugbc.tab.c"
    break;

  case 262: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 965 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4816 "src-generated/ugbc.tab.c"
    break;

  case 263: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 968 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4824 "src-generated/ugbc.tab.c"
    break;

  case 267: /* var_definition_simple: Identifier ON Identifier  */
#line 977 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4832 "src-generated/ugbc.tab.c"
    break;

  case 268: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 980 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4840 "src-generated/ugbc.tab.c"
    break;

  case 269: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 983 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4848 "src-generated/ugbc.tab.c"
    break;

  case 270: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 986 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4858 "src-generated/ugbc.tab.c"
    break;

  case 271: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 991 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4868 "src-generated/ugbc.tab.c"
    break;

  case 272: /* goto_definition: Identifier  */
#line 998 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4876 "src-generated/ugbc.tab.c"
    break;

  case 273: /* goto_definition: Integer  */
#line 1001 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4884 "src-generated/ugbc.tab.c"
    break;

  case 274: /* gosub_definition: Identifier  */
#line 1007 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4892 "src-generated/ugbc.tab.c"
    break;

  case 275: /* gosub_definition: Integer  */
#line 1010 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4900 "src-generated/ugbc.tab.c"
    break;

  case 277: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 1019 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4908 "src-generated/ugbc.tab.c"
    break;

  case 278: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 1025 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4916 "src-generated/ugbc.tab.c"
    break;

  case 281: /* ink_definition: expr  */
#line 1034 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4924 "src-generated/ugbc.tab.c"
    break;

  case 282: /* on_goto_definition: Identifier  */
#line 1039 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4933 "src-generated/ugbc.tab.c"
    break;

  case 283: /* $@4: %empty  */
#line 1043 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4941 "src-generated/ugbc.tab.c"
    break;

  case 285: /* on_gosub_definition: Identifier  */
#line 1048 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4950 "src-generated/ugbc.tab.c"
    break;

  case 286: /* $@5: %empty  */
#line 1052 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4958 "src-generated/ugbc.tab.c"
    break;

  case 288: /* on_proc_definition: Identifier  */
#line 1057 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4967 "src-generated/ugbc.tab.c"
    break;

  case 289: /* $@6: %empty  */
#line 1061 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4975 "src-generated/ugbc.tab.c"
    break;

  case 291: /* $@7: %empty  */
#line 1066 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4983 "src-generated/ugbc.tab.c"
    break;

  case 293: /* $@8: %empty  */
#line 1069 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4991 "src-generated/ugbc.tab.c"
    break;

  case 295: /* $@9: %empty  */
#line 1072 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4999 "src-generated/ugbc.tab.c"
    break;

  case 297: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1077 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 5007 "src-generated/ugbc.tab.c"
    break;

  case 298: /* every_definition: ON  */
#line 1080 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 5015 "src-generated/ugbc.tab.c"
    break;

  case 299: /* every_definition: OFF  */
#line 1083 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 5023 "src-generated/ugbc.tab.c"
    break;

  case 300: /* add_definition: Identifier COMMA expr  */
#line 1088 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 5031 "src-generated/ugbc.tab.c"
    break;

  case 301: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1091 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5039 "src-generated/ugbc.tab.c"
    break;

  case 302: /* dimensions: Integer  */
#line 1097 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5048 "src-generated/ugbc.tab.c"
    break;

  case 303: /* dimensions: Integer COMMA dimensions  */
#line 1101 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5057 "src-generated/ugbc.tab.c"
    break;

  case 304: /* datatype: BYTE  */
#line 1108 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 5065 "src-generated/ugbc.tab.c"
    break;

  case 305: /* datatype: SIGNED BYTE  */
#line 1111 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 5073 "src-generated/ugbc.tab.c"
    break;

  case 306: /* datatype: WORD  */
#line 1114 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 5081 "src-generated/ugbc.tab.c"
    break;

  case 307: /* datatype: SIGNED WORD  */
#line 1117 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 5089 "src-generated/ugbc.tab.c"
    break;

  case 308: /* datatype: DWORD  */
#line 1120 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 5097 "src-generated/ugbc.tab.c"
    break;

  case 309: /* datatype: SIGNED DWORD  */
#line 1123 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 5105 "src-generated/ugbc.tab.c"
    break;

  case 310: /* datatype: ADDRESS  */
#line 1126 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 5113 "src-generated/ugbc.tab.c"
    break;

  case 311: /* datatype: POSITION  */
#line 1129 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 5121 "src-generated/ugbc.tab.c"
    break;

  case 312: /* datatype: COLOR  */
#line 1132 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 5129 "src-generated/ugbc.tab.c"
    break;

  case 313: /* datatype: STRING  */
#line 1135 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 5137 "src-generated/ugbc.tab.c"
    break;

  case 314: /* $@10: %empty  */
#line 1140 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5146 "src-generated/ugbc.tab.c"
    break;

  case 315: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1143 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 5156 "src-generated/ugbc.tab.c"
    break;

  case 316: /* $@11: %empty  */
#line 1148 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5165 "src-generated/ugbc.tab.c"
    break;

  case 317: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1151 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 5175 "src-generated/ugbc.tab.c"
    break;

  case 318: /* $@12: %empty  */
#line 1156 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5184 "src-generated/ugbc.tab.c"
    break;

  case 319: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1159 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 5194 "src-generated/ugbc.tab.c"
    break;

  case 322: /* indexes: expr  */
#line 1172 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5203 "src-generated/ugbc.tab.c"
    break;

  case 323: /* indexes: expr COMMA indexes  */
#line 1176 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5212 "src-generated/ugbc.tab.c"
    break;

  case 324: /* parameters: Identifier  */
#line 1183 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5222 "src-generated/ugbc.tab.c"
    break;

  case 325: /* parameters: Identifier DOLLAR  */
#line 1188 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5232 "src-generated/ugbc.tab.c"
    break;

  case 326: /* parameters: Identifier AS datatype  */
#line 1193 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5242 "src-generated/ugbc.tab.c"
    break;

  case 327: /* parameters: Identifier COMMA parameters  */
#line 1198 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5252 "src-generated/ugbc.tab.c"
    break;

  case 328: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1203 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5262 "src-generated/ugbc.tab.c"
    break;

  case 329: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1208 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5272 "src-generated/ugbc.tab.c"
    break;

  case 330: /* parameters_expr: Identifier  */
#line 1216 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5282 "src-generated/ugbc.tab.c"
    break;

  case 331: /* parameters_expr: Identifier DOLLAR  */
#line 1221 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5292 "src-generated/ugbc.tab.c"
    break;

  case 332: /* parameters_expr: Identifier AS datatype  */
#line 1226 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5302 "src-generated/ugbc.tab.c"
    break;

  case 333: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1231 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5312 "src-generated/ugbc.tab.c"
    break;

  case 334: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1236 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5322 "src-generated/ugbc.tab.c"
    break;

  case 335: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1241 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5332 "src-generated/ugbc.tab.c"
    break;

  case 336: /* parameters_expr: String  */
#line 1246 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5341 "src-generated/ugbc.tab.c"
    break;

  case 337: /* parameters_expr: String COMMA parameters_expr  */
#line 1250 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5350 "src-generated/ugbc.tab.c"
    break;

  case 338: /* values: expr  */
#line 1257 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5359 "src-generated/ugbc.tab.c"
    break;

  case 339: /* values: expr COMMA values  */
#line 1261 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5368 "src-generated/ugbc.tab.c"
    break;

  case 340: /* print_definition: expr  */
#line 1268 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5376 "src-generated/ugbc.tab.c"
    break;

  case 341: /* print_definition: expr COMMA  */
#line 1271 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5385 "src-generated/ugbc.tab.c"
    break;

  case 342: /* print_definition: expr SEMICOLON  */
#line 1275 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5393 "src-generated/ugbc.tab.c"
    break;

  case 343: /* $@13: %empty  */
#line 1278 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5402 "src-generated/ugbc.tab.c"
    break;

  case 345: /* $@14: %empty  */
#line 1282 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5410 "src-generated/ugbc.tab.c"
    break;

  case 347: /* use_definition: ANSI  */
#line 1288 "src/ugbc.y"
         {
        use_ansi( _environment );
    }
#line 5418 "src-generated/ugbc.tab.c"
    break;

  case 348: /* use_definition: SPECIFIC  */
#line 1291 "src/ugbc.y"
             {
        use_specific( _environment );
  }
#line 5426 "src-generated/ugbc.tab.c"
    break;

  case 349: /* writing_mode_definition: REPLACE  */
#line 1297 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5435 "src-generated/ugbc.tab.c"
    break;

  case 350: /* writing_mode_definition: OR  */
#line 1301 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5444 "src-generated/ugbc.tab.c"
    break;

  case 351: /* writing_mode_definition: XOR  */
#line 1305 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5453 "src-generated/ugbc.tab.c"
    break;

  case 352: /* writing_mode_definition: AND  */
#line 1309 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5462 "src-generated/ugbc.tab.c"
    break;

  case 353: /* writing_mode_definition: IGNORE  */
#line 1313 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5471 "src-generated/ugbc.tab.c"
    break;

  case 354: /* writing_part_definition: NORMAL  */
#line 1320 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5480 "src-generated/ugbc.tab.c"
    break;

  case 355: /* writing_part_definition: PAPER  */
#line 1324 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5489 "src-generated/ugbc.tab.c"
    break;

  case 356: /* writing_part_definition: PAPER ONLY  */
#line 1328 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5498 "src-generated/ugbc.tab.c"
    break;

  case 357: /* writing_part_definition: PEN  */
#line 1332 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5507 "src-generated/ugbc.tab.c"
    break;

  case 358: /* writing_part_definition: PEN ONLY  */
#line 1336 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5516 "src-generated/ugbc.tab.c"
    break;

  case 359: /* writing_definition: writing_mode_definition COMMA writing_part_definition  */
#line 1343 "src/ugbc.y"
                                                          {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5524 "src-generated/ugbc.tab.c"
    break;

  case 360: /* locate_definition: COMMA expr  */
#line 1349 "src/ugbc.y"
                {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 5532 "src-generated/ugbc.tab.c"
    break;

  case 361: /* locate_definition: expr COMMA  */
#line 1352 "src/ugbc.y"
                 {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 5540 "src-generated/ugbc.tab.c"
    break;

  case 362: /* locate_definition: expr COMMA expr  */
#line 1355 "src/ugbc.y"
                      {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5548 "src-generated/ugbc.tab.c"
    break;

  case 363: /* cmove_definition: COMMA expr  */
#line 1361 "src/ugbc.y"
                {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 5556 "src-generated/ugbc.tab.c"
    break;

  case 364: /* cmove_definition: expr COMMA  */
#line 1364 "src/ugbc.y"
                 {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 5564 "src-generated/ugbc.tab.c"
    break;

  case 365: /* cmove_definition: expr COMMA expr  */
#line 1367 "src/ugbc.y"
                      {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5572 "src-generated/ugbc.tab.c"
    break;

  case 384: /* statement: MEMORIZE  */
#line 1391 "src/ugbc.y"
             {
      text_memorize( _environment );
  }
#line 5580 "src-generated/ugbc.tab.c"
    break;

  case 385: /* statement: REMEMBER  */
#line 1394 "src/ugbc.y"
             {
      text_remember( _environment );
  }
#line 5588 "src-generated/ugbc.tab.c"
    break;

  case 387: /* statement: CUP  */
#line 1398 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 5596 "src-generated/ugbc.tab.c"
    break;

  case 388: /* statement: CDOWN  */
#line 1401 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 5604 "src-generated/ugbc.tab.c"
    break;

  case 389: /* statement: CLEFT  */
#line 1404 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 5612 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: CRIGHT  */
#line 1407 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 5620 "src-generated/ugbc.tab.c"
    break;

  case 391: /* statement: CLINE  */
#line 1410 "src/ugbc.y"
          {
      text_cline( _environment, NULL );
  }
#line 5628 "src-generated/ugbc.tab.c"
    break;

  case 392: /* statement: CLINE expr  */
#line 1413 "src/ugbc.y"
               {
      text_cline( _environment, (yyvsp[0].string) );
  }
#line 5636 "src-generated/ugbc.tab.c"
    break;

  case 393: /* statement: SET TAB expr  */
#line 1416 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 5644 "src-generated/ugbc.tab.c"
    break;

  case 394: /* statement: CENTER expr  */
#line 1419 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5652 "src-generated/ugbc.tab.c"
    break;

  case 395: /* statement: CENTRE expr  */
#line 1422 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5660 "src-generated/ugbc.tab.c"
    break;

  case 396: /* statement: CLS  */
#line 1425 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 5668 "src-generated/ugbc.tab.c"
    break;

  case 397: /* statement: HOME  */
#line 1428 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 5676 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statement: INC Identifier  */
#line 1431 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 5684 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: DEC Identifier  */
#line 1434 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 5692 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: RANDOMIZE  */
#line 1437 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 5700 "src-generated/ugbc.tab.c"
    break;

  case 401: /* statement: RANDOMIZE expr  */
#line 1440 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 5708 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: IF expr THEN  */
#line 1443 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5716 "src-generated/ugbc.tab.c"
    break;

  case 403: /* statement: ELSE  */
#line 1446 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 5724 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: ELSE IF expr THEN  */
#line 1449 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5732 "src-generated/ugbc.tab.c"
    break;

  case 405: /* statement: ENDIF  */
#line 1452 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5740 "src-generated/ugbc.tab.c"
    break;

  case 406: /* statement: DO  */
#line 1455 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5748 "src-generated/ugbc.tab.c"
    break;

  case 407: /* statement: LOOP  */
#line 1458 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5756 "src-generated/ugbc.tab.c"
    break;

  case 408: /* $@15: %empty  */
#line 1461 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5764 "src-generated/ugbc.tab.c"
    break;

  case 409: /* statement: WHILE $@15 expr  */
#line 1463 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5772 "src-generated/ugbc.tab.c"
    break;

  case 410: /* statement: WEND  */
#line 1466 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5780 "src-generated/ugbc.tab.c"
    break;

  case 411: /* statement: REPEAT  */
#line 1469 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5788 "src-generated/ugbc.tab.c"
    break;

  case 412: /* statement: UNTIL expr  */
#line 1472 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5796 "src-generated/ugbc.tab.c"
    break;

  case 413: /* statement: EXIT  */
#line 1475 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5804 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: EXIT PROC  */
#line 1478 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5812 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: POP PROC  */
#line 1481 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5820 "src-generated/ugbc.tab.c"
    break;

  case 416: /* statement: EXIT IF expr  */
#line 1484 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5828 "src-generated/ugbc.tab.c"
    break;

  case 417: /* statement: EXIT Integer  */
#line 1487 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5836 "src-generated/ugbc.tab.c"
    break;

  case 418: /* statement: EXIT direct_integer  */
#line 1490 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5844 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: EXIT IF expr COMMA Integer  */
#line 1493 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5852 "src-generated/ugbc.tab.c"
    break;

  case 420: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1496 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5860 "src-generated/ugbc.tab.c"
    break;

  case 421: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1499 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5868 "src-generated/ugbc.tab.c"
    break;

  case 422: /* statement: NEXT  */
#line 1502 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5876 "src-generated/ugbc.tab.c"
    break;

  case 423: /* statement: PROCEDURE Identifier  */
#line 1505 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5885 "src-generated/ugbc.tab.c"
    break;

  case 424: /* $@16: %empty  */
#line 1509 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5893 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1511 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5901 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: SHARED parameters_expr  */
#line 1514 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5909 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: GLOBAL parameters_expr  */
#line 1517 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5917 "src-generated/ugbc.tab.c"
    break;

  case 428: /* statement: END PROC  */
#line 1520 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 5925 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: END PROC OSP expr CSP  */
#line 1523 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5933 "src-generated/ugbc.tab.c"
    break;

  case 430: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1526 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5941 "src-generated/ugbc.tab.c"
    break;

  case 431: /* statement: Identifier " "  */
#line 1529 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5950 "src-generated/ugbc.tab.c"
    break;

  case 432: /* statement: PROC Identifier  */
#line 1533 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5959 "src-generated/ugbc.tab.c"
    break;

  case 433: /* statement: CALL Identifier  */
#line 1537 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5968 "src-generated/ugbc.tab.c"
    break;

  case 434: /* $@17: %empty  */
#line 1541 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5976 "src-generated/ugbc.tab.c"
    break;

  case 435: /* statement: Identifier OSP $@17 values CSP  */
#line 1543 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5984 "src-generated/ugbc.tab.c"
    break;

  case 436: /* $@18: %empty  */
#line 1546 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5992 "src-generated/ugbc.tab.c"
    break;

  case 437: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1548 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6000 "src-generated/ugbc.tab.c"
    break;

  case 438: /* $@19: %empty  */
#line 1551 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6008 "src-generated/ugbc.tab.c"
    break;

  case 439: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1553 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6016 "src-generated/ugbc.tab.c"
    break;

  case 440: /* statement: PEN expr  */
#line 1556 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 6024 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: PAPER expr  */
#line 1559 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 6032 "src-generated/ugbc.tab.c"
    break;

  case 442: /* statement: INVERSE ON  */
#line 1562 "src/ugbc.y"
               {
      text_inverse( _environment, 1 );
  }
#line 6040 "src-generated/ugbc.tab.c"
    break;

  case 443: /* statement: INVERSE OFF  */
#line 1565 "src/ugbc.y"
                {
      text_inverse( _environment, 0 );
  }
#line 6048 "src-generated/ugbc.tab.c"
    break;

  case 445: /* statement: Identifier COLON  */
#line 1569 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 6056 "src-generated/ugbc.tab.c"
    break;

  case 446: /* statement: BEG GAMELOOP  */
#line 1572 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 6064 "src-generated/ugbc.tab.c"
    break;

  case 447: /* statement: END GAMELOOP  */
#line 1575 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 6072 "src-generated/ugbc.tab.c"
    break;

  case 448: /* statement: GRAPHIC  */
#line 1578 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 6080 "src-generated/ugbc.tab.c"
    break;

  case 449: /* statement: HALT  */
#line 1581 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 6088 "src-generated/ugbc.tab.c"
    break;

  case 450: /* statement: END  */
#line 1584 "src/ugbc.y"
        {
      end( _environment );
  }
#line 6096 "src-generated/ugbc.tab.c"
    break;

  case 455: /* statement: RETURN  */
#line 1591 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 6104 "src-generated/ugbc.tab.c"
    break;

  case 456: /* statement: RETURN expr  */
#line 1594 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 6112 "src-generated/ugbc.tab.c"
    break;

  case 457: /* statement: POP  */
#line 1597 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 6120 "src-generated/ugbc.tab.c"
    break;

  case 458: /* statement: DONE  */
#line 1600 "src/ugbc.y"
          {
      return 0;
  }
#line 6128 "src-generated/ugbc.tab.c"
    break;

  case 459: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1603 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6136 "src-generated/ugbc.tab.c"
    break;

  case 460: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1606 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6144 "src-generated/ugbc.tab.c"
    break;

  case 461: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1609 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 6152 "src-generated/ugbc.tab.c"
    break;

  case 462: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1612 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6160 "src-generated/ugbc.tab.c"
    break;

  case 465: /* statement: Identifier ASSIGN expr  */
#line 1617 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 6174 "src-generated/ugbc.tab.c"
    break;

  case 466: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1626 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 6188 "src-generated/ugbc.tab.c"
    break;

  case 467: /* $@20: %empty  */
#line 1635 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6197 "src-generated/ugbc.tab.c"
    break;

  case 468: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1639 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 6210 "src-generated/ugbc.tab.c"
    break;

  case 469: /* $@21: %empty  */
#line 1647 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6219 "src-generated/ugbc.tab.c"
    break;

  case 470: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1650 "src/ugbc.y"
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
#line 6238 "src-generated/ugbc.tab.c"
    break;

  case 471: /* $@22: %empty  */
#line 1664 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6247 "src-generated/ugbc.tab.c"
    break;

  case 472: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1667 "src/ugbc.y"
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
#line 6266 "src-generated/ugbc.tab.c"
    break;

  case 473: /* statement: DEBUG expr  */
#line 1681 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 6274 "src-generated/ugbc.tab.c"
    break;

  case 476: /* statements_no_linenumbers: statement  */
#line 1689 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 6280 "src-generated/ugbc.tab.c"
    break;

  case 477: /* $@23: %empty  */
#line 1690 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 6286 "src-generated/ugbc.tab.c"
    break;

  case 479: /* $@24: %empty  */
#line 1694 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 6294 "src-generated/ugbc.tab.c"
    break;

  case 480: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1696 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 6302 "src-generated/ugbc.tab.c"
    break;

  case 481: /* $@25: %empty  */
#line 1701 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 6310 "src-generated/ugbc.tab.c"
    break;

  case 487: /* $@26: %empty  */
#line 1711 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 6316 "src-generated/ugbc.tab.c"
    break;


#line 6320 "src-generated/ugbc.tab.c"

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

#line 1713 "src/ugbc.y"


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

