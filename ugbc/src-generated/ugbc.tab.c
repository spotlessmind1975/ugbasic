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
  YYSYMBOL_BLACK = 168,                    /* BLACK  */
  YYSYMBOL_WHITE = 169,                    /* WHITE  */
  YYSYMBOL_RED = 170,                      /* RED  */
  YYSYMBOL_CYAN = 171,                     /* CYAN  */
  YYSYMBOL_VIOLET = 172,                   /* VIOLET  */
  YYSYMBOL_GREEN = 173,                    /* GREEN  */
  YYSYMBOL_BLUE = 174,                     /* BLUE  */
  YYSYMBOL_YELLOW = 175,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 176,                   /* ORANGE  */
  YYSYMBOL_BROWN = 177,                    /* BROWN  */
  YYSYMBOL_LIGHT = 178,                    /* LIGHT  */
  YYSYMBOL_DARK = 179,                     /* DARK  */
  YYSYMBOL_GREY = 180,                     /* GREY  */
  YYSYMBOL_GRAY = 181,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 182,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 183,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 184,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 185,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 186,                /* TURQUOISE  */
  YYSYMBOL_TAN = 187,                      /* TAN  */
  YYSYMBOL_PINK = 188,                     /* PINK  */
  YYSYMBOL_PEACH = 189,                    /* PEACH  */
  YYSYMBOL_OLIVE = 190,                    /* OLIVE  */
  YYSYMBOL_Identifier = 191,               /* Identifier  */
  YYSYMBOL_String = 192,                   /* String  */
  YYSYMBOL_Integer = 193,                  /* Integer  */
  YYSYMBOL_194_ = 194,                     /* " "  */
  YYSYMBOL_YYACCEPT = 195,                 /* $accept  */
  YYSYMBOL_expr = 196,                     /* expr  */
  YYSYMBOL_expr_math = 197,                /* expr_math  */
  YYSYMBOL_term = 198,                     /* term  */
  YYSYMBOL_modula = 199,                   /* modula  */
  YYSYMBOL_factor = 200,                   /* factor  */
  YYSYMBOL_direct_integer = 201,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 202, /* random_definition_simple  */
  YYSYMBOL_random_definition = 203,        /* random_definition  */
  YYSYMBOL_color_enumeration = 204,        /* color_enumeration  */
  YYSYMBOL_exponential = 205,              /* exponential  */
  YYSYMBOL_206_1 = 206,                    /* $@1  */
  YYSYMBOL_207_2 = 207,                    /* $@2  */
  YYSYMBOL_208_3 = 208,                    /* $@3  */
  YYSYMBOL_position = 209,                 /* position  */
  YYSYMBOL_bank_definition_simple = 210,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 211, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 212,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 213, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 214, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 215,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 216, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 217, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 218,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 219,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 220, /* color_definition_expression  */
  YYSYMBOL_color_definition = 221,         /* color_definition  */
  YYSYMBOL_milliseconds = 222,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 223,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 224, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 225,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 226, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 227, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 228,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 229, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 230, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 231,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 232, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 233, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 234,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 235,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 236, /* text_definition_expression  */
  YYSYMBOL_text_definition = 237,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 238,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 239, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 240,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 241, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 242, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 243,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 244, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 245, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 246,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 247,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 248,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 249,         /* gosub_definition  */
  YYSYMBOL_var_definition = 250,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 251,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 252, /* point_definition_expression  */
  YYSYMBOL_point_definition = 253,         /* point_definition  */
  YYSYMBOL_ink_definition = 254,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 255,       /* on_goto_definition  */
  YYSYMBOL_256_4 = 256,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 257,      /* on_gosub_definition  */
  YYSYMBOL_258_5 = 258,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 259,       /* on_proc_definition  */
  YYSYMBOL_260_6 = 260,                    /* $@6  */
  YYSYMBOL_on_definition = 261,            /* on_definition  */
  YYSYMBOL_262_7 = 262,                    /* $@7  */
  YYSYMBOL_263_8 = 263,                    /* $@8  */
  YYSYMBOL_264_9 = 264,                    /* $@9  */
  YYSYMBOL_every_definition = 265,         /* every_definition  */
  YYSYMBOL_add_definition = 266,           /* add_definition  */
  YYSYMBOL_dimensions = 267,               /* dimensions  */
  YYSYMBOL_datatype = 268,                 /* datatype  */
  YYSYMBOL_dim_definition = 269,           /* dim_definition  */
  YYSYMBOL_270_10 = 270,                   /* $@10  */
  YYSYMBOL_271_11 = 271,                   /* $@11  */
  YYSYMBOL_272_12 = 272,                   /* $@12  */
  YYSYMBOL_dim_definitions = 273,          /* dim_definitions  */
  YYSYMBOL_indexes = 274,                  /* indexes  */
  YYSYMBOL_parameters = 275,               /* parameters  */
  YYSYMBOL_parameters_expr = 276,          /* parameters_expr  */
  YYSYMBOL_values = 277,                   /* values  */
  YYSYMBOL_print_definition = 278,         /* print_definition  */
  YYSYMBOL_279_13 = 279,                   /* $@13  */
  YYSYMBOL_280_14 = 280,                   /* $@14  */
  YYSYMBOL_use_definition = 281,           /* use_definition  */
  YYSYMBOL_writing_mode_definition = 282,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 283,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 284,       /* writing_definition  */
  YYSYMBOL_statement = 285,                /* statement  */
  YYSYMBOL_286_15 = 286,                   /* $@15  */
  YYSYMBOL_287_16 = 287,                   /* $@16  */
  YYSYMBOL_288_17 = 288,                   /* $@17  */
  YYSYMBOL_289_18 = 289,                   /* $@18  */
  YYSYMBOL_290_19 = 290,                   /* $@19  */
  YYSYMBOL_291_20 = 291,                   /* $@20  */
  YYSYMBOL_292_21 = 292,                   /* $@21  */
  YYSYMBOL_293_22 = 293,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 294, /* statements_no_linenumbers  */
  YYSYMBOL_295_23 = 295,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 296, /* statements_with_linenumbers  */
  YYSYMBOL_297_24 = 297,                   /* $@24  */
  YYSYMBOL_statements_complex = 298,       /* statements_complex  */
  YYSYMBOL_299_25 = 299,                   /* $@25  */
  YYSYMBOL_program = 300,                  /* program  */
  YYSYMBOL_301_26 = 301                    /* $@26  */
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
#define YYLAST   2295

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  195
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  107
/* YYNRULES -- Number of rules.  */
#define YYNRULES  457
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  875

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   449


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
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194
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
    1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327,
    1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,  1338,  1341,
    1344,  1347,  1350,  1353,  1356,  1359,  1362,  1365,  1365,  1370,
    1373,  1376,  1379,  1382,  1385,  1388,  1391,  1394,  1397,  1400,
    1403,  1406,  1409,  1413,  1413,  1418,  1421,  1424,  1427,  1430,
    1433,  1437,  1441,  1445,  1445,  1450,  1450,  1455,  1455,  1460,
    1463,  1466,  1469,  1472,  1473,  1476,  1479,  1482,  1485,  1488,
    1491,  1492,  1493,  1494,  1495,  1498,  1501,  1504,  1507,  1510,
    1513,  1516,  1519,  1520,  1521,  1530,  1539,  1539,  1551,  1551,
    1568,  1568,  1585,  1588,  1589,  1593,  1594,  1594,  1598,  1598,
    1605,  1605,  1608,  1609,  1610,  1611,  1615,  1615
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
  "writing_part_definition", "writing_definition", "statement", "$@15",
  "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22",
  "statements_no_linenumbers", "$@23", "statements_with_linenumbers",
  "$@24", "statements_complex", "$@25", "program", "$@26", YY_NULLPTR
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
     445,   446,   447,   448,   449
};
#endif

#define YYPACT_NINF (-748)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-437)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -748,    57,   823,  -748,  -748,  -107,  -101,   -18,  -748,    60,
    1586,    87,     1,  1586,  -748,    34,   207,  1758,   -58,   -50,
    -748,  -748,  -748,  1242,   135,     2,  1758,  1758,    54,   -22,
    -748,   118,   150,  1758,  1758,  -748,   154,   167,    51,  1758,
      72,   130,  -748,   -26,  -748,  1758,    30,  1414,   230,    50,
    1758,    64,    68,    85,   121,    41,    41,  1758,   105,  1758,
     229,   -36,    28,  -748,   303,   337,   338,  -748,  -748,  -748,
    1586,   319,  -748,  -748,  -748,  1586,  1586,  1586,  -748,  -748,
    -748,   153,  1070,  -748,  -748,   313,   314,   315,   155,   157,
    -748,  -748,     7,   318,   320,  1758,  -748,  -748,   321,   322,
     323,   324,   325,   327,   329,   335,   336,   341,   342,   343,
     344,   345,   346,   347,   348,  -748,  -748,   349,    63,   -43,
       8,  -748,  -748,  -748,  -748,  -748,  -748,  -748,   187,  -748,
    -748,   100,  -100,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,   198,    10,  -748,  -748,   -16,    98,   255,   235,
     257,    76,  -748,  -748,  -748,  -748,  -748,   -15,   305,    -9,
      -4,    -3,    -2,   365,  -748,  -748,  -748,   221,   308,  -748,
    -748,  -748,  1586,  -748,  -748,   361,  -748,  -748,  -748,  -748,
    -748,  1586,   350,   351,  -748,  -748,  -748,   -14,  -748,    53,
    -748,  -748,  -748,  -748,  -748,  1758,  1758,  -748,  -748,   384,
    -748,  -748,  -748,  1586,  -748,  -748,  -748,  1586,   363,  -748,
    -748,  -748,   330,  -748,  -748,  -748,   246,  1758,  1758,  -748,
    -748,  1586,  -748,  -748,  -748,   360,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  1758,  1758,  -748,  -748,  -748,  -748,
     382,  -748,  -748,   248,  -748,  1758,   391,  -748,  -748,  -748,
      26,   394,  -748,   256,   258,   259,   122,   395,  -748,  -748,
     176,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,   397,  -748,  -748,  -748,  1758,   396,  -748,
    -748,   373,   125,   970,  -748,   823,   823,   379,   381,  1586,
    -748,  -748,   339,   340,   352,   354,  -748,   385,   386,   387,
     388,   392,    73,   393,  1586,  1586,  1586,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,   380,  -748,  -748,
    1758,  1758,  -748,  1758,  1758,  1758,  1758,  1758,  1758,  1758,
    1758,  1758,  1758,  1758,  1758,  1758,  1758,  1758,  1758,  1758,
    1930,   399,   228,  -748,  -748,   400,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,   401,  -748,   402,  -748,
    -748,  -748,  -748,  -748,  -748,  1930,  1930,  1930,  1930,  1930,
    1930,  1930,  1930,  1930,  1930,  1930,  1930,  1930,  2102,  -748,
    -748,  -748,  1586,   405,  -748,  -748,  -748,   383,   305,   414,
     305,   415,   305,   417,   305,   418,   305,  -748,  1758,   412,
    -748,  -748,   225,   236,   120,   159,  -748,  -748,  -748,   413,
     305,   416,  -748,  -748,   250,   274,   164,   169,  -748,  -748,
     419,  -748,  -748,  1586,  -748,  -748,  1586,  1586,  -748,  -748,
    -748,   404,   260,  -748,   441,  1758,  -748,  -748,  -748,  -748,
    1586,  -748,  1758,   448,   450,  -748,  -748,  1586,   390,   453,
    1758,   359,   455,  1758,  -748,  -748,  -748,  -748,  -748,  -748,
     162,  -748,  -748,   429,   444,    64,  -748,   328,  -748,    41,
     458,   125,    41,   284,   285,   -67,   823,  -748,  1758,   432,
    1758,  1758,   433,    25,  -748,   970,  -748,  -748,   278,   280,
    -748,  -748,  1758,   305,  1758,   305,   281,   283,   286,   287,
     288,   438,   442,   443,  -748,   451,   452,   456,   457,   459,
     460,  1758,   476,   483,   486,   489,   462,   463,   464,   465,
     496,   469,   470,   471,   472,   473,   503,   504,   477,   478,
     479,    11,   332,   480,  1758,   482,  1758,  1758,   255,   255,
     326,   326,   326,   326,   326,   326,   326,   326,   235,   257,
     257,  -748,   488,   490,  1586,     4,  -748,   305,  -748,   305,
    -748,   305,  -748,   305,    48,  -748,  1758,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  1758,  -748,   305,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,   305,  -748,  -748,  -748,
    -748,  -748,  -748,   334,   355,   356,   357,   505,  1758,   513,
     485,   487,   389,  1758,  1758,   514,   521,  -748,   -68,   461,
     358,  1758,   523,  -748,  -748,  -748,   497,   366,   498,  -748,
    1758,   362,  1758,  -748,    41,   527,  -748,  1758,  1758,   368,
     369,  -748,  -748,  -748,  -748,  1758,   531,   403,   532,   506,
    1758,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,   367,   370,   371,  -748,  -748,  -748,  -748,
    -748,  -748,   507,  1758,  1758,  1758,  1758,  -748,  -748,  -748,
    -748,  1758,  -748,  -748,  -748,  -748,  -748,  1758,  1758,  -748,
    -748,  -748,  2102,   508,  -748,   510,  1758,   406,   515,   375,
     376,  -748,  -748,  -748,  -748,  -748,  -748,   511,  -748,   529,
    -748,   377,   128,  -748,   545,  -748,   554,   555,  -748,   561,
    -748,   564,  -748,   559,  1586,   566,  1758,  1758,   305,  -748,
     539,   540,  1758,   305,  -748,  -748,  1758,  -748,    69,  1758,
     366,   569,   542,   366,   430,   146,   431,   434,  -748,    41,
    -748,  -748,  -748,  -748,   546,  1758,  -748,  1758,   567,   548,
    -748,  -748,  -748,  -748,   549,   550,   144,   161,   551,   552,
     556,   557,  -748,  -748,   560,  -748,  -748,  -748,  -748,   398,
     407,  -748,   568,  -748,   571,  -748,  1758,   305,   582,   589,
     591,  1758,  -748,  -748,  1758,  -748,  -748,  -748,   590,   592,
     572,   573,   491,  1758,   596,   530,   576,   366,  -748,   578,
    -748,   362,   597,   125,  -748,  -748,  -748,   601,  -748,  -748,
    1758,   602,  -748,  -748,  1758,  -748,  1758,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,   428,   435,   587,   593,   334,
     355,   356,  -748,  -748,  1758,  1758,  -748,  -748,  1758,   594,
    1758,  1758,  -748,  -748,  -748,  -748,   362,   617,  1758,  -748,
    1758,   595,   598,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,   613,  -748,  -748,  -748,   362,  -748,  -748,
    -748,  -748,  1758,  -748,  -748
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     456,     0,   444,     1,   443,     0,     0,     0,   427,     0,
       0,   391,     0,     0,   418,     0,     0,     0,   256,     0,
     376,   380,   377,     0,     0,     0,     0,     0,     0,   419,
     374,     0,     0,     0,   369,   417,     0,     0,     0,   424,
     426,   372,   375,   382,   379,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   440,   448,   445,   452,   454,   457,   367,   368,
       0,     0,   157,   158,   351,     0,     0,     0,   171,   172,
     353,     0,     0,    79,    80,     0,     0,     0,     0,     0,
     121,   122,     0,     0,     0,     0,   112,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   123,     0,     0,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,    44,    49,    50,    51,    52,    53,    54,
      57,    58,     0,    63,    67,    65,     0,     2,    12,    15,
      17,     0,    76,    20,   182,   183,   354,     0,     0,     0,
       0,     0,     0,     0,   151,   152,   350,     0,     0,   214,
     215,   355,     0,   217,   218,   219,   223,   224,   356,   246,
     247,     0,     0,     0,   254,   255,   361,     0,   420,     0,
     266,   364,   262,   263,   421,     0,     0,   229,   230,     0,
     233,   234,   358,     0,   237,   238,   359,     0,   240,   244,
     245,   360,     0,   409,   415,   416,   397,     0,     0,   442,
     370,     0,   227,   228,   357,     0,   269,   270,   362,   264,
     265,   422,   425,   384,     0,     0,   383,   386,   387,   381,
       0,   288,   289,     0,   423,     0,     0,   365,   271,   363,
     304,   310,   432,   401,   392,   402,   320,   326,   395,   396,
     330,   366,   338,   337,   433,   410,   411,   412,   342,   340,
     339,   341,   343,     0,   413,   450,   414,     0,   438,   403,
     400,     0,     0,   444,   446,   444,   444,     0,     0,     0,
     168,   165,     0,     0,     0,     0,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    24,    25,
      27,    29,    30,    26,    31,   101,    23,     0,   115,   116,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   117,   120,     0,   118,   119,    55,    42,
      45,    46,    47,    48,    43,    56,    64,   108,     0,   173,
     179,   174,   175,   180,   181,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   176,
     177,   178,     0,     0,   163,   164,   352,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
     204,   205,     0,     0,     0,     0,   201,   200,   126,     0,
       0,     0,   189,   190,     0,     0,     0,     0,   186,   185,
       0,   221,   216,     0,   251,   248,     0,     0,   281,   285,
     283,     0,     0,   378,     0,     0,   236,   235,   242,   239,
       0,   371,     0,     0,     0,   226,   225,     0,     0,   385,
       0,     0,     0,     0,   302,   294,   296,   301,   298,   303,
       0,   300,   308,     0,     0,     0,   405,     0,   407,     0,
     321,     0,     0,   335,   333,     0,   444,   434,     0,     0,
       0,     0,     0,   440,   449,   444,   453,   455,     0,     0,
     155,   153,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,    14,
       5,     7,     8,     9,    10,     6,     3,     4,    16,    18,
      19,    21,     0,     0,     0,     0,   133,     0,   145,     0,
     137,     0,   141,     0,   129,   202,     0,   209,   208,   213,
     212,   207,   211,   206,   210,     0,   187,     0,   194,   193,
     198,   197,   192,   196,   191,   195,     0,   222,   220,   252,
     249,   253,   250,     0,     0,     0,     0,   257,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   373,     0,     0,
       0,     0,   290,   295,   297,   299,     0,     0,     0,   311,
       0,     0,     0,   323,     0,   322,   327,     0,     0,   347,
     345,   344,   349,   451,   435,     0,   328,     0,   312,     0,
       0,   447,   156,   154,   170,   167,   169,   166,    75,    68,
      70,    74,    72,     0,     0,     0,    78,    77,    82,    81,
      84,    83,     0,     0,     0,     0,     0,    91,    92,    93,
     100,     0,    94,    95,    96,    97,    98,     0,     0,   110,
     111,   102,     0,     0,   106,     0,     0,     0,     0,     0,
       0,   161,   159,   130,   143,   135,   138,   132,   144,   136,
     140,     0,     0,   199,     0,   184,     0,   272,   282,   275,
     286,   278,   284,   258,     0,     0,     0,     0,     0,   398,
       0,     0,     0,     0,   388,   389,     0,   287,     0,     0,
       0,   292,     0,     0,     0,   314,     0,     0,   324,     0,
     336,   334,   348,   346,     0,     0,   404,     0,     0,     0,
      69,    71,    73,   124,     0,     0,     0,     0,     0,     0,
       0,     0,   107,   125,     0,   109,    60,   162,   160,     0,
       0,   146,   131,   142,   134,   139,     0,     0,     0,     0,
       0,     0,   260,   259,     0,   232,   243,   241,     0,     0,
       0,     0,   390,     0,     0,     0,     0,     0,   305,     0,
     406,     0,   315,     0,   394,   408,   325,     0,   329,   313,
       0,     0,    85,    86,     0,    87,     0,    89,    99,   105,
     104,    22,    62,   148,   150,     0,     0,     0,     0,     0,
       0,     0,   261,   231,     0,     0,   268,   267,     0,     0,
       0,     0,   309,   293,   307,   317,     0,   316,     0,   437,
       0,     0,     0,   147,   149,   203,   188,   274,   277,   280,
     428,   429,   399,     0,   430,   291,   318,     0,   439,   441,
      88,    90,     0,   319,   431
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -748,   -10,   -69,   -29,   261,  -253,    62,  -748,  -748,  -748,
    -374,  -748,  -748,  -748,   466,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,   481,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,
    -198,  -748,  -195,  -748,  -194,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -678,  -281,  -748,  -748,  -748,  -748,   173,  -532,
    -747,   -54,  -528,  -289,  -748,  -748,  -748,  -748,  -748,  -748,
    -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -748,  -273,
    -748,  -748,  -748,  -274,  -748,  -748,  -748
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   638,   147,   148,   149,   150,   151,   314,   315,   152,
     153,   358,   535,   536,   409,   164,   165,   166,    72,    73,
      74,   384,   385,   386,    78,    79,    80,   364,   154,   155,
     156,   169,   170,   171,   176,   177,   178,   222,   223,   224,
     200,   201,   202,   204,   205,   206,   209,   210,   211,   184,
     185,   186,   190,   194,   231,   191,   226,   227,   228,   249,
     708,   778,   710,   779,   712,   780,   188,   593,   595,   594,
     244,   247,   732,   462,   251,   463,   464,   616,   252,   639,
     736,   258,   637,   261,   628,   627,   264,   273,   632,   274,
      64,   195,   467,   480,   620,   622,   281,   479,   282,    65,
     485,    66,   283,    67,   476,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     146,   482,   259,   167,   551,   688,    70,   187,   687,   382,
     484,   486,   487,   199,    89,   388,   212,   213,   682,   629,
     390,   392,   394,   219,   220,   158,   207,   317,   345,   232,
     356,   276,   275,   159,   276,   239,   693,   243,   277,   428,
     248,   277,   235,   343,   -59,   278,  -306,   260,   278,   265,
     160,   454,   796,   694,   845,   799,    89,     3,   172,  -436,
     287,   268,  -436,   359,   360,   290,   292,   294,   215,   269,
     173,   174,   303,   431,   353,   168,   793,   701,   161,   162,
     354,   695,   696,   341,    68,   322,    75,   531,   429,   208,
      69,    76,   734,   630,   737,   432,   702,   342,   631,   866,
     455,   456,   457,   744,   794,   238,   365,   366,   749,   157,
     367,   458,   368,   369,   370,   371,   372,   344,   236,   843,
     873,   175,   216,   549,   550,   724,   270,   271,   272,   469,
     430,    77,   288,   189,   361,   362,   363,   291,   293,   295,
     378,   192,   470,   193,   214,   318,   346,   501,   502,   459,
     454,   814,   217,   801,   764,   359,   379,   357,   503,   203,
     772,   460,   421,   319,   347,   571,   802,   237,   816,   461,
     471,   424,   279,    71,   572,   279,   383,   773,   221,   815,
     307,   473,   389,   474,   218,   433,   434,   391,   393,   395,
     625,   225,   163,   436,   803,   373,   817,   438,   234,   455,
     456,   457,   633,   374,   573,   774,   775,   443,   444,   582,
     458,   445,   641,   574,   584,   809,   233,   808,   583,   280,
     387,   240,   280,   585,   448,   449,   361,   362,   380,   308,
     309,   310,   256,   257,   422,   452,   613,   614,   311,   312,
     313,   246,   229,   425,   230,   397,   398,   615,   459,   179,
     180,   181,   182,   399,   376,   250,   377,   400,   401,   253,
     460,   183,   262,   263,   245,   437,   402,   477,   461,   439,
     349,   266,   267,   350,   351,   403,   254,   404,   405,   490,
     352,   567,   568,   446,  -332,  -331,   406,   407,  -332,  -331,
    -332,  -331,   569,   570,   505,   507,   509,   408,   540,   541,
     542,   543,   544,   545,   546,   547,   578,   579,   761,   284,
     512,   513,   255,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     580,   581,   397,   410,   365,   366,   538,   539,   740,   741,
     411,   285,   286,   289,   412,   413,   296,   304,   305,   306,
     316,   491,   320,   414,   321,   323,   324,   325,   326,   327,
     348,   328,   415,   329,   416,   417,   506,   508,   510,   330,
     331,   355,   552,   418,   419,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   408,   375,   378,    89,   565,   396,
     423,   435,   440,   442,   447,   450,   426,   427,   453,   441,
     451,   465,   472,   466,   475,  -393,   468,   481,   488,   478,
     489,   492,   493,   587,   511,   623,   589,   591,   626,   533,
     496,   497,   498,   499,   494,   599,   495,   500,   504,   554,
     600,   555,   602,   532,   534,   -61,   537,   605,   557,   559,
     609,   561,   563,   612,   553,   566,   596,   575,   598,   577,
     556,   597,   558,   586,   560,   603,   562,   604,   564,   607,
     608,   610,   611,   617,   618,   624,   635,   640,   634,   642,
     636,   643,   576,   653,   648,   621,   649,   654,   655,   650,
     651,   652,   644,   663,   646,   588,   656,   657,   590,   592,
     664,   658,   659,   665,   660,   661,   666,   667,   668,   669,
     670,   662,   601,   671,   672,   673,   674,   675,   676,   606,
     677,   678,   679,   680,   681,   684,   686,   689,   714,   690,
     716,   722,   847,   683,   685,   707,   636,   717,   723,   718,
     729,   730,   733,   726,   739,   742,   743,   719,   745,   747,
     769,   748,   753,   762,   691,   763,   709,   711,   713,   727,
     766,   746,   776,   735,   765,   645,   703,   647,   770,   731,
     750,   777,  -273,   751,   752,   704,   767,   768,  -276,   771,
     738,  -279,   781,   784,   788,   789,   797,   798,   800,   804,
     810,   807,   805,   811,   812,   813,   818,   819,   715,   829,
     823,   820,   821,   720,   721,   822,   830,   825,   831,   824,
     826,   728,   841,   834,   846,   835,   838,   836,   837,   840,
     636,   842,   636,   844,   848,   850,   692,   260,   260,   697,
     853,   698,   855,   699,   867,   700,   872,   854,   856,   863,
     870,   857,   381,   871,   420,   858,   548,   859,   619,   705,
       0,     0,     0,     0,     0,     0,     0,     0,   706,     0,
       0,     0,     0,   754,   755,   756,   757,     0,     0,     0,
       0,   758,     0,     0,     0,     0,     0,   759,   760,     0,
     725,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   806,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   782,     0,   785,   786,     0,     0,
       0,     0,   790,     0,     0,     0,   792,     0,     0,   795,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   636,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   827,     0,     0,     0,
       0,   832,     0,     0,   833,     0,   783,     0,     0,     0,
     787,     0,     0,   839,     0,   791,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     849,     0,     0,     0,   851,     0,   852,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   860,   861,     4,     0,   862,     0,
     864,   865,     0,     5,     6,     0,     0,     0,   868,   828,
     869,     0,     0,     0,     0,     7,     8,     0,     9,     0,
      10,    11,     0,    12,    13,     0,     0,     0,     0,     0,
       0,    14,   874,    15,    16,    17,     0,     0,     0,     0,
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
       0,     0,    55,     4,     0,     0,    56,     0,    57,     0,
       5,     6,    58,    59,    60,     0,     0,     0,     0,    61,
       0,     0,     7,     8,     0,     9,     0,    10,    11,     0,
      12,    13,     0,     0,     0,     0,     0,     0,    14,     0,
      15,    16,    17,     0,    62,     0,    63,    18,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,    28,    29,
       0,    30,     0,     0,    31,    32,    33,     0,    34,    35,
      36,    37,    38,    39,    40,     0,    41,     0,     0,    81,
      42,    43,    44,    45,    46,     0,    47,    48,     0,     0,
       0,     0,     0,     0,     0,   297,     0,     0,     0,     0,
       0,    49,     0,     0,    82,     0,     0,     0,     0,    50,
       0,     0,    51,     0,    52,    53,    54,     0,     0,    55,
      83,    84,    85,    56,     0,    57,     0,     0,     0,    58,
      59,    60,     0,     0,     0,     0,    61,    86,     0,     0,
      87,     0,     0,    88,   298,   299,   300,     0,     0,     0,
       0,     0,     0,    90,    91,   301,    92,     0,     0,     0,
       0,   483,     0,     0,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
       0,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,     0,   110,   111,   112,   302,   113,   114,   115,     0,
     116,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,     0,   119,     0,     0,     0,
     120,     0,     0,     0,     0,     0,     0,     0,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    81,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,   196,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,   197,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
       0,     0,    87,     0,     0,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,     0,    92,     0,
       0,     0,     0,     0,     0,     0,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,    97,     0,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,     0,   110,   111,   112,     0,   113,   114,
     115,     0,   116,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,     0,   119,     0,
       0,     0,   120,     0,     0,     0,     0,     0,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    81,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,   241,   242,     0,     0,
       0,     0,     0,     0,    83,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,     0,     0,    87,     0,     0,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,     0,
      92,     0,     0,     0,     0,     0,     0,     0,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,    97,     0,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,     0,   110,   111,   112,     0,
     113,   114,   115,     0,   116,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,     0,
     119,     0,     0,     0,   120,     0,     0,     0,     0,     0,
       0,     0,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    81,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,     0,     0,    87,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,     0,    92,     0,     0,     0,     0,     0,     0,     0,
      93,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,    97,     0,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,     0,     0,   110,   111,
     112,     0,   113,   114,   115,     0,   116,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,     0,   119,     0,     0,     0,   120,     0,     0,     0,
       0,     0,     0,     0,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    81,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,     0,     0,    87,     0,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,     0,    92,     0,     0,     0,     0,     0,
       0,     0,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    97,     0,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,     0,     0,
     110,   111,   112,     0,   113,   114,   115,     0,   116,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   118,     0,   119,     0,     0,     0,   120,     0,
       0,     0,     0,     0,     0,     0,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    81,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,     0,     0,
      87,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,     0,    92,     0,     0,     0,
       0,     0,     0,     0,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
       0,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,     0,   110,   111,   112,     0,   113,   114,   115,     0,
     116,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,     0,   119,     0,     0,     0,
     120,     0,     0,     0,     0,     0,     0,     0,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    81,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
       0,     0,    87,     0,     0,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,     0,    92,     0,
       0,     0,     0,     0,     0,     0,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,     0,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,     0,   110,   111,   112,     0,   113,   114,
     115,     0,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,     0,   119,     0,
       0,     0,   120,     0,     0,     0,     0,     0,     0,     0,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,     0,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145
};

static const yytype_int16 yycheck[] =
{
      10,   282,    56,    13,   378,   537,    24,    17,   536,    24,
     283,   285,   286,    23,    82,    24,    26,    27,     7,    86,
      24,    24,    24,    33,    34,    24,    24,    20,    20,    39,
      20,     6,     4,    32,     6,    45,    32,    47,    13,    53,
      50,    13,    68,    86,    34,    20,    20,    57,    20,    59,
      49,    25,   730,    49,   801,   733,    82,     0,    24,    34,
      70,    97,    34,    79,    80,    75,    76,    77,    90,   105,
      36,    37,    82,    20,   174,    13,     7,    29,    77,    78,
     180,    77,    78,    20,   191,    95,    26,   340,   102,    87,
     191,    31,   620,   160,   622,    42,    48,    34,   165,   846,
      74,    75,    76,   635,    35,    43,     8,     9,   640,    22,
      12,    85,    14,    15,    16,    17,    18,   160,   144,   797,
     867,    87,   144,   376,   377,   193,   162,   163,   164,     7,
     144,    71,    70,   191,   150,   151,   152,    75,    76,    77,
     129,   191,    20,   193,    90,   138,   138,    74,    75,   123,
      25,     7,    34,     7,   686,    79,    80,   147,    85,    24,
      32,   135,   172,   156,   156,    45,    20,   193,     7,   143,
      48,   181,   147,   191,    54,   147,   191,    49,    24,    35,
      25,     5,   191,     7,    34,   195,   196,   191,   191,   191,
     471,    24,   191,   203,    48,    97,    35,   207,    68,    74,
      75,    76,   476,   105,    45,    77,    78,   217,   218,    45,
      85,   221,   485,    54,    45,   747,   144,   745,    54,   194,
     158,   191,   194,    54,   234,   235,   150,   151,   152,    74,
      75,    76,   191,   192,   172,   245,    74,    75,    83,    84,
      85,   191,   191,   181,   193,    24,    25,    85,   123,    42,
      43,    44,    45,    32,    19,   191,    21,    36,    37,   191,
     135,    54,   157,   158,    34,   203,    45,   277,   143,   207,
     170,    42,    43,   173,   174,    54,   191,    56,    57,   289,
     180,    56,    57,   221,     0,     0,    65,    66,     4,     4,
       6,     6,    56,    57,   304,   305,   306,    76,   367,   368,
     369,   370,   371,   372,   373,   374,    56,    57,   682,     6,
     320,   321,   191,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
      56,    57,    24,    25,     8,     9,   365,   366,   627,   628,
      32,     4,     4,    24,    36,    37,   193,    34,    34,    34,
     193,   289,    34,    45,    34,    34,    34,    34,    34,    34,
     173,    34,    54,    34,    56,    57,   304,   305,   306,    34,
      34,   173,   382,    65,    66,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    76,   130,   129,    82,   398,    24,
      29,     7,    29,   147,    34,    13,    46,    46,     7,    69,
     152,     7,     7,   147,     7,   147,   147,    34,    29,    13,
      29,    72,    72,   423,    34,   469,   426,   427,   472,   191,
      35,    35,    35,    35,    72,   435,    72,    35,    35,    24,
     440,    48,   442,    34,    34,    34,    34,   447,    24,    24,
     450,    24,    24,   453,   382,    33,    42,    34,     7,    33,
     388,   191,   390,    34,   392,     7,   394,     7,   396,    69,
       7,   102,     7,    34,    20,     7,    34,    34,   478,   191,
     480,   191,   410,    35,   193,   147,   193,    35,    35,   193,
     193,   193,   492,     7,   494,   423,    35,    35,   426,   427,
       7,    35,    35,     7,    35,    35,     7,    35,    35,    35,
      35,   511,   440,     7,    35,    35,    35,    35,    35,   447,
       7,     7,    35,    35,    35,    35,    34,    29,    13,    29,
       7,     7,   803,   191,   534,   191,   536,    42,     7,    42,
       7,    34,    34,    72,     7,   167,   167,   148,     7,     7,
      29,    35,    35,    35,   554,    35,   191,   191,   191,   191,
      35,   148,     7,   191,   148,   493,   566,   495,    29,   193,
     193,     7,     7,   193,   193,   575,   191,   191,     7,   192,
     624,     7,    13,     7,    35,    35,     7,    35,   148,   148,
      13,    35,   148,    35,    35,    35,    35,    35,   598,     7,
     192,    35,    35,   603,   604,    35,     7,    29,     7,   192,
      29,   611,    72,    13,     7,    13,   115,    35,    35,    13,
     620,    35,   622,    35,    13,    13,   554,   627,   628,   557,
     192,   559,    35,   561,     7,   563,    13,   192,    35,    35,
      35,   829,   151,    35,   168,   830,   375,   831,   465,   577,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   586,    -1,
      -1,    -1,    -1,   663,   664,   665,   666,    -1,    -1,    -1,
      -1,   671,    -1,    -1,    -1,    -1,    -1,   677,   678,    -1,
     608,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   739,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   714,    -1,   716,   717,    -1,    -1,
      -1,    -1,   722,    -1,    -1,    -1,   726,    -1,    -1,   729,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   745,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   776,    -1,    -1,    -1,
      -1,   781,    -1,    -1,   784,    -1,   714,    -1,    -1,    -1,
     718,    -1,    -1,   793,    -1,   723,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     810,    -1,    -1,    -1,   814,    -1,   816,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   834,   835,     3,    -1,   838,    -1,
     840,   841,    -1,    10,    11,    -1,    -1,    -1,   848,   777,
     850,    -1,    -1,    -1,    -1,    22,    23,    -1,    25,    -1,
      27,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,   872,    40,    41,    42,    -1,    -1,    -1,    -1,
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
      -1,    -1,   149,     3,    -1,    -1,   153,    -1,   155,    -1,
      10,    11,   159,   160,   161,    -1,    -1,    -1,    -1,   166,
      -1,    -1,    22,    23,    -1,    25,    -1,    27,    28,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      40,    41,    42,    -1,   191,    -1,   193,    47,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    88,    89,
      -1,    91,    -1,    -1,    94,    95,    96,    -1,    98,    99,
     100,   101,   102,   103,   104,    -1,   106,    -1,    -1,     9,
     110,   111,   112,   113,   114,    -1,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,   131,    -1,    -1,    34,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,    -1,   144,   145,   146,    -1,    -1,   149,
      50,    51,    52,   153,    -1,   155,    -1,    -1,    -1,   159,
     160,   161,    -1,    -1,    -1,    -1,   166,    67,    -1,    -1,
      70,    -1,    -1,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    86,    -1,    -1,    -1,
      -1,   191,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,   132,   133,   134,   135,   136,   137,   138,    -1,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,    -1,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,     9,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    24,    -1,    -1,    -1,
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
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,     9,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
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
      -1,    -1,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,     9,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,     9,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,     9,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,     9,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,
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
     138,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,   156,    -1,
      -1,    -1,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   300,   301,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    86,    88,    89,
      91,    94,    95,    96,    98,    99,   100,   101,   102,   103,
     104,   106,   110,   111,   112,   113,   114,   116,   117,   131,
     139,   142,   144,   145,   146,   149,   153,   155,   159,   160,
     161,   166,   191,   193,   285,   294,   296,   298,   191,   191,
      24,   191,   213,   214,   215,    26,    31,    71,   219,   220,
     221,     9,    34,    50,    51,    52,    67,    70,    73,    82,
      83,    84,    86,    94,    95,   107,   108,   109,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     132,   133,   134,   136,   137,   138,   140,   141,   154,   156,
     160,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   196,   197,   198,   199,
     200,   201,   204,   205,   223,   224,   225,    22,    24,    32,
      49,    77,    78,   191,   210,   211,   212,   196,   201,   226,
     227,   228,    24,    36,    37,    87,   229,   230,   231,    42,
      43,    44,    45,    54,   244,   245,   246,   196,   261,   191,
     247,   250,   191,   193,   248,   286,    24,    36,    37,   196,
     235,   236,   237,    24,   238,   239,   240,    24,    87,   241,
     242,   243,   196,   196,    90,    90,   144,    34,    34,   196,
     196,    24,   232,   233,   234,    24,   251,   252,   253,   191,
     193,   249,   196,   144,    68,    68,   144,   193,   201,   196,
     191,    42,    43,   196,   265,    34,   191,   266,   196,   254,
     191,   269,   273,   191,   191,   191,   191,   192,   276,   276,
     196,   278,   157,   158,   281,   196,    42,    43,    97,   105,
     162,   163,   164,   282,   284,     4,     6,    13,    20,   147,
     194,   291,   293,   297,     6,     4,     4,   196,   201,    24,
     196,   201,   196,   201,   196,   201,   193,    25,    74,    75,
      76,    85,   135,   196,    34,    34,    34,    25,    74,    75,
      76,    83,    84,    85,   202,   203,   193,    20,   138,   156,
      34,    34,   196,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    20,    34,    86,   160,    20,   138,   156,   173,   170,
     173,   174,   180,   174,   180,   173,    20,   147,   206,    79,
      80,   150,   151,   152,   222,     8,     9,    12,    14,    15,
      16,    17,    18,    97,   105,   130,    19,    21,   129,    80,
     152,   222,    24,   191,   216,   217,   218,   201,    24,   191,
      24,   191,    24,   191,    24,   191,    24,    24,    25,    32,
      36,    37,    45,    54,    56,    57,    65,    66,    76,   209,
      25,    32,    36,    37,    45,    54,    56,    57,    65,    66,
     209,   196,   201,    29,   196,   201,    46,    46,    53,   102,
     144,    20,    42,   196,   196,     7,   196,   201,   196,   201,
      29,    69,   147,   196,   196,   196,   201,    34,   196,   196,
      13,   152,   196,     7,    25,    74,    75,    76,    85,   123,
     135,   143,   268,   270,   271,     7,   147,   287,   147,     7,
      20,    48,     7,     5,     7,     7,   299,   196,    13,   292,
     288,    34,   268,   191,   294,   295,   298,   298,    29,    29,
     196,   201,    72,    72,    72,    72,    35,    35,    35,    35,
      35,    74,    75,    85,    35,   196,   201,   196,   201,   196,
     201,    34,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   200,    34,   191,    34,   207,   208,    34,   198,   198,
     197,   197,   197,   197,   197,   197,   197,   197,   199,   200,
     200,   205,   196,   201,    24,    48,   201,    24,   201,    24,
     201,    24,   201,    24,   201,   196,    33,    56,    57,    56,
      57,    45,    54,    45,    54,    34,   201,    33,    56,    57,
      56,    57,    45,    54,    45,    54,    34,   196,   201,   196,
     201,   196,   201,   262,   264,   263,    42,   191,     7,   196,
     196,   201,   196,     7,     7,   196,   201,    69,     7,   196,
     102,     7,   196,    74,    75,    85,   272,    34,    20,   273,
     289,   147,   290,   276,     7,   268,   276,   280,   279,    86,
     160,   165,   283,   298,   196,    34,   196,   277,   196,   274,
      34,   294,   191,   191,   196,   201,   196,   201,   193,   193,
     193,   193,   193,    35,    35,    35,    35,    35,    35,    35,
      35,    35,   196,     7,     7,     7,     7,    35,    35,    35,
      35,     7,    35,    35,    35,    35,    35,     7,     7,    35,
      35,    35,     7,   191,    35,   196,    34,   277,   274,    29,
      29,   196,   201,    32,    49,    77,    78,   201,   201,   201,
     201,    29,    48,   196,   196,   201,   201,   191,   255,   191,
     257,   191,   259,   191,    13,   196,     7,    42,    42,   148,
     196,   196,     7,     7,   193,   201,    72,   191,   196,     7,
      34,   193,   267,    34,   277,   191,   275,   277,   276,     7,
     278,   278,   167,   167,   274,     7,   148,     7,    35,   274,
     193,   193,   193,    35,   196,   196,   196,   196,   196,   196,
     196,   205,    35,    35,   274,   148,    35,   191,   191,    29,
      29,   192,    32,    49,    77,    78,     7,     7,   256,   258,
     260,    13,   196,   201,     7,   196,   196,   201,    35,    35,
     196,   201,   196,     7,    35,   196,   267,     7,    35,   267,
     148,     7,    20,    48,   148,   148,   276,    35,   277,   274,
      13,    35,    35,    35,     7,    35,     7,    35,    35,    35,
      35,    35,    35,   192,   192,    29,    29,   196,   201,     7,
       7,     7,   196,   196,    13,    13,    35,    35,   115,   196,
      13,    72,    35,   267,    35,   275,     7,   268,    13,   196,
      13,   196,   196,   192,   192,    35,    35,   255,   257,   259,
     196,   196,   196,    35,   196,   196,   275,     7,   196,   196,
      35,    35,    13,   275,   196
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   195,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   197,   197,   197,   198,   198,   199,   199,   199,
     200,   200,   200,   201,   202,   202,   202,   202,   202,   202,
     202,   203,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   206,
     205,   207,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   208,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   209,   209,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   211,   211,   211,   211,
     211,   212,   212,   213,   213,   214,   214,   215,   215,   216,
     216,   217,   217,   218,   218,   219,   219,   219,   220,   220,
     220,   221,   221,   222,   222,   222,   223,   223,   223,   224,
     224,   224,   225,   225,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   228,   228,   229,   229,   229,   229,
     229,   230,   230,   231,   231,   232,   233,   234,   234,   235,
     235,   236,   236,   237,   237,   238,   239,   240,   240,   241,
     241,   241,   242,   242,   243,   243,   244,   244,   244,   244,
     244,   245,   245,   245,   246,   246,   247,   247,   247,   247,
     247,   247,   248,   248,   249,   249,   250,   251,   252,   253,
     253,   254,   255,   256,   255,   257,   258,   257,   259,   260,
     259,   262,   261,   263,   261,   264,   261,   265,   265,   265,
     266,   266,   267,   267,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   270,   269,   271,   269,   272,   269,
     273,   273,   274,   274,   275,   275,   275,   275,   275,   275,
     276,   276,   276,   276,   276,   276,   276,   276,   277,   277,
     278,   278,   278,   279,   278,   280,   278,   281,   281,   282,
     282,   282,   282,   282,   283,   283,   283,   283,   283,   284,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   286,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   287,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   288,   285,   289,   285,   290,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   291,   285,   292,   285,
     293,   285,   285,   285,   285,   294,   295,   294,   297,   296,
     299,   298,   298,   298,   298,   298,   301,   300
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
       2,     2,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
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
#line 2699 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 79 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2708 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 83 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2716 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 86 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2724 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 89 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2732 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 92 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2740 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 95 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2748 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 98 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2756 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 101 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2764 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 108 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2772 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 111 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2781 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 124 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2790 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 128 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2799 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 136 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2808 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 140 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 2817 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 147 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2825 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 152 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2833 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 155 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2841 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 158 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2849 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 161 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2857 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 164 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2865 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 167 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2873 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 170 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2881 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 175 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2889 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 180 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2898 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 184 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2907 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 188 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2916 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 192 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2925 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 196 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2934 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 200 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2943 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 204 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2952 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 208 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2961 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 212 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2970 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 216 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2979 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 220 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2988 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 224 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2997 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 228 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3006 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 232 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3015 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 236 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3024 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 240 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3033 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 244 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3042 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 248 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3051 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 252 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3060 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 256 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3069 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 260 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3078 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 264 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3087 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 268 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3096 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 272 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3105 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 276 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3114 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 280 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3123 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 284 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3132 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 290 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3141 "src-generated/ugbc.tab.c"
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
#line 3153 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 301 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3162 "src-generated/ugbc.tab.c"
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
#line 3174 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 312 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3182 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 315 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3190 "src-generated/ugbc.tab.c"
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
#line 3204 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 327 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3213 "src-generated/ugbc.tab.c"
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
#line 3225 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 338 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3234 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 342 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3243 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 346 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3252 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 350 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3261 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 354 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3270 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 358 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3279 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 362 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3288 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 366 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3297 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 370 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3305 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 373 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3313 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 376 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3321 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 379 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3329 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 382 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3337 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 385 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3345 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 388 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3353 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 391 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3361 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 394 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3369 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 397 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3377 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 400 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3385 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 403 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3393 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 406 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3401 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 409 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3409 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 412 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3417 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 415 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3425 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 418 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3433 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 421 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3441 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 424 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3449 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 427 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3457 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 430 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3465 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 433 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3473 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 436 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3481 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 439 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3489 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 442 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3497 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 445 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3505 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 448 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3513 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 451 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3521 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 454 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3529 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 457 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3537 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 460 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3545 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 463 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3553 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 466 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3561 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 468 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3570 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 472 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3578 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 475 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3586 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 478 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3595 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 482 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3604 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 486 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3613 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: PEN COLORS  */
#line 490 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3622 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: PEN DEFAULT  */
#line 494 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3631 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: DEFAULT PEN  */
#line 498 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3640 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: PAPER COLORS  */
#line 502 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3649 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: PAPER DEFAULT  */
#line 506 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3658 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: DEFAULT PAPER  */
#line 510 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3667 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: WIDTH  */
#line 514 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3675 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: HEIGHT  */
#line 517 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3683 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: TIMER  */
#line 520 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3691 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PEN DOLLAR OP expr CP  */
#line 523 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 3699 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER DOLLAR OP expr CP  */
#line 526 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3707 "src-generated/ugbc.tab.c"
    break;

  case 128: /* bank_definition_simple: AT direct_integer  */
#line 534 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3715 "src-generated/ugbc.tab.c"
    break;

  case 129: /* bank_definition_simple: Identifier AT direct_integer  */
#line 537 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3723 "src-generated/ugbc.tab.c"
    break;

  case 130: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 540 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3731 "src-generated/ugbc.tab.c"
    break;

  case 131: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 543 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3739 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 546 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3747 "src-generated/ugbc.tab.c"
    break;

  case 133: /* bank_definition_simple: DATA AT direct_integer  */
#line 549 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3755 "src-generated/ugbc.tab.c"
    break;

  case 134: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 553 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3763 "src-generated/ugbc.tab.c"
    break;

  case 135: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 556 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3771 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 559 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3779 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bank_definition_simple: CODE AT direct_integer  */
#line 562 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3787 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 566 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3795 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 569 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3803 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 572 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3811 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 575 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3819 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 579 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3827 "src-generated/ugbc.tab.c"
    break;

  case 143: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 582 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3835 "src-generated/ugbc.tab.c"
    break;

  case 144: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 585 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3843 "src-generated/ugbc.tab.c"
    break;

  case 145: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 588 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3851 "src-generated/ugbc.tab.c"
    break;

  case 146: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 594 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3859 "src-generated/ugbc.tab.c"
    break;

  case 147: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 597 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3867 "src-generated/ugbc.tab.c"
    break;

  case 148: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 600 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3875 "src-generated/ugbc.tab.c"
    break;

  case 149: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 603 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3883 "src-generated/ugbc.tab.c"
    break;

  case 150: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 606 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3891 "src-generated/ugbc.tab.c"
    break;

  case 153: /* raster_definition_simple: Identifier AT direct_integer  */
#line 615 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3899 "src-generated/ugbc.tab.c"
    break;

  case 154: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 618 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3907 "src-generated/ugbc.tab.c"
    break;

  case 155: /* raster_definition_expression: Identifier AT expr  */
#line 623 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3915 "src-generated/ugbc.tab.c"
    break;

  case 156: /* raster_definition_expression: AT expr WITH Identifier  */
#line 626 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3923 "src-generated/ugbc.tab.c"
    break;

  case 159: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 635 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3931 "src-generated/ugbc.tab.c"
    break;

  case 160: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 638 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3939 "src-generated/ugbc.tab.c"
    break;

  case 161: /* next_raster_definition_expression: Identifier AT expr  */
#line 643 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3947 "src-generated/ugbc.tab.c"
    break;

  case 162: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 646 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3955 "src-generated/ugbc.tab.c"
    break;

  case 165: /* color_definition_simple: BORDER direct_integer  */
#line 655 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3963 "src-generated/ugbc.tab.c"
    break;

  case 166: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 658 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3971 "src-generated/ugbc.tab.c"
    break;

  case 167: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 661 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3979 "src-generated/ugbc.tab.c"
    break;

  case 168: /* color_definition_expression: BORDER expr  */
#line 666 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3987 "src-generated/ugbc.tab.c"
    break;

  case 169: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 669 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3995 "src-generated/ugbc.tab.c"
    break;

  case 170: /* color_definition_expression: SPRITE expr TO expr  */
#line 672 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4003 "src-generated/ugbc.tab.c"
    break;

  case 176: /* wait_definition_simple: direct_integer CYCLES  */
#line 686 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4011 "src-generated/ugbc.tab.c"
    break;

  case 177: /* wait_definition_simple: direct_integer TICKS  */
#line 689 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4019 "src-generated/ugbc.tab.c"
    break;

  case 178: /* wait_definition_simple: direct_integer milliseconds  */
#line 692 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4027 "src-generated/ugbc.tab.c"
    break;

  case 179: /* wait_definition_expression: expr CYCLES  */
#line 697 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4035 "src-generated/ugbc.tab.c"
    break;

  case 180: /* wait_definition_expression: expr TICKS  */
#line 700 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4043 "src-generated/ugbc.tab.c"
    break;

  case 181: /* wait_definition_expression: expr milliseconds  */
#line 703 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4051 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 713 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4059 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 716 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4067 "src-generated/ugbc.tab.c"
    break;

  case 186: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 719 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4075 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 722 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4083 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 725 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4091 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_simple: direct_integer ENABLE  */
#line 728 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4099 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_simple: direct_integer DISABLE  */
#line 731 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4107 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 734 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4115 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 737 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4123 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 740 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4131 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 743 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4139 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 746 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4147 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 749 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4155 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 752 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4163 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 755 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4171 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_expression: expr DATA FROM expr  */
#line 760 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4179 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_expression: expr MULTICOLOR  */
#line 763 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4187 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_expression: expr MONOCOLOR  */
#line 766 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4195 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_expression: expr COLOR expr  */
#line 769 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4203 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 772 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4211 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_expression: expr ENABLE  */
#line 775 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4219 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_expression: expr DISABLE  */
#line 778 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4227 "src-generated/ugbc.tab.c"
    break;

  case 206: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 781 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4235 "src-generated/ugbc.tab.c"
    break;

  case 207: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 784 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4243 "src-generated/ugbc.tab.c"
    break;

  case 208: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 787 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4251 "src-generated/ugbc.tab.c"
    break;

  case 209: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 790 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4259 "src-generated/ugbc.tab.c"
    break;

  case 210: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 793 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4267 "src-generated/ugbc.tab.c"
    break;

  case 211: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 796 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4275 "src-generated/ugbc.tab.c"
    break;

  case 212: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 799 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4283 "src-generated/ugbc.tab.c"
    break;

  case 213: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 802 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4291 "src-generated/ugbc.tab.c"
    break;

  case 216: /* bitmap_definition_simple: AT direct_integer  */
#line 811 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4299 "src-generated/ugbc.tab.c"
    break;

  case 217: /* bitmap_definition_simple: ENABLE  */
#line 814 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4307 "src-generated/ugbc.tab.c"
    break;

  case 218: /* bitmap_definition_simple: DISABLE  */
#line 817 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4315 "src-generated/ugbc.tab.c"
    break;

  case 219: /* bitmap_definition_simple: CLEAR  */
#line 820 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4323 "src-generated/ugbc.tab.c"
    break;

  case 220: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 823 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4331 "src-generated/ugbc.tab.c"
    break;

  case 221: /* bitmap_definition_expression: AT expr  */
#line 829 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4339 "src-generated/ugbc.tab.c"
    break;

  case 222: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 832 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4347 "src-generated/ugbc.tab.c"
    break;

  case 225: /* textmap_definition_simple: AT direct_integer  */
#line 842 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4355 "src-generated/ugbc.tab.c"
    break;

  case 226: /* textmap_definition_expression: AT expr  */
#line 847 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4363 "src-generated/ugbc.tab.c"
    break;

  case 229: /* text_definition_simple: ENABLE  */
#line 856 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4371 "src-generated/ugbc.tab.c"
    break;

  case 230: /* text_definition_simple: DISABLE  */
#line 859 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4379 "src-generated/ugbc.tab.c"
    break;

  case 231: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 864 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4387 "src-generated/ugbc.tab.c"
    break;

  case 232: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 867 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4395 "src-generated/ugbc.tab.c"
    break;

  case 235: /* tiles_definition_simple: AT direct_integer  */
#line 876 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4403 "src-generated/ugbc.tab.c"
    break;

  case 236: /* tiles_definition_expression: AT expr  */
#line 881 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4411 "src-generated/ugbc.tab.c"
    break;

  case 239: /* colormap_definition_simple: AT direct_integer  */
#line 890 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4419 "src-generated/ugbc.tab.c"
    break;

  case 240: /* colormap_definition_simple: CLEAR  */
#line 893 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4427 "src-generated/ugbc.tab.c"
    break;

  case 241: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 896 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4435 "src-generated/ugbc.tab.c"
    break;

  case 242: /* colormap_definition_expression: AT expr  */
#line 901 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4443 "src-generated/ugbc.tab.c"
    break;

  case 243: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 904 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4451 "src-generated/ugbc.tab.c"
    break;

  case 246: /* screen_definition_simple: ON  */
#line 914 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4459 "src-generated/ugbc.tab.c"
    break;

  case 247: /* screen_definition_simple: OFF  */
#line 917 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4467 "src-generated/ugbc.tab.c"
    break;

  case 248: /* screen_definition_simple: ROWS direct_integer  */
#line 920 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4475 "src-generated/ugbc.tab.c"
    break;

  case 249: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 923 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4483 "src-generated/ugbc.tab.c"
    break;

  case 250: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 926 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4491 "src-generated/ugbc.tab.c"
    break;

  case 251: /* screen_definition_expression: ROWS expr  */
#line 931 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4499 "src-generated/ugbc.tab.c"
    break;

  case 252: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 934 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4507 "src-generated/ugbc.tab.c"
    break;

  case 253: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 937 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4515 "src-generated/ugbc.tab.c"
    break;

  case 257: /* var_definition_simple: Identifier ON Identifier  */
#line 946 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4523 "src-generated/ugbc.tab.c"
    break;

  case 258: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 949 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4531 "src-generated/ugbc.tab.c"
    break;

  case 259: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 952 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4539 "src-generated/ugbc.tab.c"
    break;

  case 260: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 955 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4549 "src-generated/ugbc.tab.c"
    break;

  case 261: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 960 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4559 "src-generated/ugbc.tab.c"
    break;

  case 262: /* goto_definition: Identifier  */
#line 967 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4567 "src-generated/ugbc.tab.c"
    break;

  case 263: /* goto_definition: Integer  */
#line 970 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4575 "src-generated/ugbc.tab.c"
    break;

  case 264: /* gosub_definition: Identifier  */
#line 976 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4583 "src-generated/ugbc.tab.c"
    break;

  case 265: /* gosub_definition: Integer  */
#line 979 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4591 "src-generated/ugbc.tab.c"
    break;

  case 267: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 988 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4599 "src-generated/ugbc.tab.c"
    break;

  case 268: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 994 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4607 "src-generated/ugbc.tab.c"
    break;

  case 271: /* ink_definition: expr  */
#line 1003 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4615 "src-generated/ugbc.tab.c"
    break;

  case 272: /* on_goto_definition: Identifier  */
#line 1008 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4624 "src-generated/ugbc.tab.c"
    break;

  case 273: /* $@4: %empty  */
#line 1012 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4632 "src-generated/ugbc.tab.c"
    break;

  case 275: /* on_gosub_definition: Identifier  */
#line 1017 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4641 "src-generated/ugbc.tab.c"
    break;

  case 276: /* $@5: %empty  */
#line 1021 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4649 "src-generated/ugbc.tab.c"
    break;

  case 278: /* on_proc_definition: Identifier  */
#line 1026 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4658 "src-generated/ugbc.tab.c"
    break;

  case 279: /* $@6: %empty  */
#line 1030 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4666 "src-generated/ugbc.tab.c"
    break;

  case 281: /* $@7: %empty  */
#line 1035 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4674 "src-generated/ugbc.tab.c"
    break;

  case 283: /* $@8: %empty  */
#line 1038 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4682 "src-generated/ugbc.tab.c"
    break;

  case 285: /* $@9: %empty  */
#line 1041 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4690 "src-generated/ugbc.tab.c"
    break;

  case 287: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1046 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4698 "src-generated/ugbc.tab.c"
    break;

  case 288: /* every_definition: ON  */
#line 1049 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4706 "src-generated/ugbc.tab.c"
    break;

  case 289: /* every_definition: OFF  */
#line 1052 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4714 "src-generated/ugbc.tab.c"
    break;

  case 290: /* add_definition: Identifier COMMA expr  */
#line 1057 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4722 "src-generated/ugbc.tab.c"
    break;

  case 291: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1060 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4730 "src-generated/ugbc.tab.c"
    break;

  case 292: /* dimensions: Integer  */
#line 1066 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4739 "src-generated/ugbc.tab.c"
    break;

  case 293: /* dimensions: Integer COMMA dimensions  */
#line 1070 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4748 "src-generated/ugbc.tab.c"
    break;

  case 294: /* datatype: BYTE  */
#line 1077 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 4756 "src-generated/ugbc.tab.c"
    break;

  case 295: /* datatype: SIGNED BYTE  */
#line 1080 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 4764 "src-generated/ugbc.tab.c"
    break;

  case 296: /* datatype: WORD  */
#line 1083 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 4772 "src-generated/ugbc.tab.c"
    break;

  case 297: /* datatype: SIGNED WORD  */
#line 1086 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 4780 "src-generated/ugbc.tab.c"
    break;

  case 298: /* datatype: DWORD  */
#line 1089 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 4788 "src-generated/ugbc.tab.c"
    break;

  case 299: /* datatype: SIGNED DWORD  */
#line 1092 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 4796 "src-generated/ugbc.tab.c"
    break;

  case 300: /* datatype: ADDRESS  */
#line 1095 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 4804 "src-generated/ugbc.tab.c"
    break;

  case 301: /* datatype: POSITION  */
#line 1098 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 4812 "src-generated/ugbc.tab.c"
    break;

  case 302: /* datatype: COLOR  */
#line 1101 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 4820 "src-generated/ugbc.tab.c"
    break;

  case 303: /* datatype: STRING  */
#line 1104 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 4828 "src-generated/ugbc.tab.c"
    break;

  case 304: /* $@10: %empty  */
#line 1109 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4837 "src-generated/ugbc.tab.c"
    break;

  case 305: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1112 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 4847 "src-generated/ugbc.tab.c"
    break;

  case 306: /* $@11: %empty  */
#line 1117 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4856 "src-generated/ugbc.tab.c"
    break;

  case 307: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1120 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 4866 "src-generated/ugbc.tab.c"
    break;

  case 308: /* $@12: %empty  */
#line 1125 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4875 "src-generated/ugbc.tab.c"
    break;

  case 309: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1128 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 4885 "src-generated/ugbc.tab.c"
    break;

  case 312: /* indexes: expr  */
#line 1141 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4894 "src-generated/ugbc.tab.c"
    break;

  case 313: /* indexes: expr COMMA indexes  */
#line 1145 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4903 "src-generated/ugbc.tab.c"
    break;

  case 314: /* parameters: Identifier  */
#line 1152 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4913 "src-generated/ugbc.tab.c"
    break;

  case 315: /* parameters: Identifier DOLLAR  */
#line 1157 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4923 "src-generated/ugbc.tab.c"
    break;

  case 316: /* parameters: Identifier AS datatype  */
#line 1162 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4933 "src-generated/ugbc.tab.c"
    break;

  case 317: /* parameters: Identifier COMMA parameters  */
#line 1167 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4943 "src-generated/ugbc.tab.c"
    break;

  case 318: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1172 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4953 "src-generated/ugbc.tab.c"
    break;

  case 319: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1177 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4963 "src-generated/ugbc.tab.c"
    break;

  case 320: /* parameters_expr: Identifier  */
#line 1185 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4973 "src-generated/ugbc.tab.c"
    break;

  case 321: /* parameters_expr: Identifier DOLLAR  */
#line 1190 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4983 "src-generated/ugbc.tab.c"
    break;

  case 322: /* parameters_expr: Identifier AS datatype  */
#line 1195 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4993 "src-generated/ugbc.tab.c"
    break;

  case 323: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1200 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5003 "src-generated/ugbc.tab.c"
    break;

  case 324: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1205 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5013 "src-generated/ugbc.tab.c"
    break;

  case 325: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1210 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5023 "src-generated/ugbc.tab.c"
    break;

  case 326: /* parameters_expr: String  */
#line 1215 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5032 "src-generated/ugbc.tab.c"
    break;

  case 327: /* parameters_expr: String COMMA parameters_expr  */
#line 1219 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5041 "src-generated/ugbc.tab.c"
    break;

  case 328: /* values: expr  */
#line 1226 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5050 "src-generated/ugbc.tab.c"
    break;

  case 329: /* values: expr COMMA values  */
#line 1230 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5059 "src-generated/ugbc.tab.c"
    break;

  case 330: /* print_definition: expr  */
#line 1237 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5067 "src-generated/ugbc.tab.c"
    break;

  case 331: /* print_definition: expr COMMA  */
#line 1240 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5076 "src-generated/ugbc.tab.c"
    break;

  case 332: /* print_definition: expr SEMICOLON  */
#line 1244 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5084 "src-generated/ugbc.tab.c"
    break;

  case 333: /* $@13: %empty  */
#line 1247 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5093 "src-generated/ugbc.tab.c"
    break;

  case 335: /* $@14: %empty  */
#line 1251 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5101 "src-generated/ugbc.tab.c"
    break;

  case 337: /* use_definition: ANSI  */
#line 1257 "src/ugbc.y"
         {
        use_ansi( _environment );
    }
#line 5109 "src-generated/ugbc.tab.c"
    break;

  case 338: /* use_definition: SPECIFIC  */
#line 1260 "src/ugbc.y"
             {
        use_specific( _environment );
  }
#line 5117 "src-generated/ugbc.tab.c"
    break;

  case 339: /* writing_mode_definition: REPLACE  */
#line 1266 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5126 "src-generated/ugbc.tab.c"
    break;

  case 340: /* writing_mode_definition: OR  */
#line 1270 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5135 "src-generated/ugbc.tab.c"
    break;

  case 341: /* writing_mode_definition: XOR  */
#line 1274 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5144 "src-generated/ugbc.tab.c"
    break;

  case 342: /* writing_mode_definition: AND  */
#line 1278 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5153 "src-generated/ugbc.tab.c"
    break;

  case 343: /* writing_mode_definition: IGNORE  */
#line 1282 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5162 "src-generated/ugbc.tab.c"
    break;

  case 344: /* writing_part_definition: NORMAL  */
#line 1289 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5171 "src-generated/ugbc.tab.c"
    break;

  case 345: /* writing_part_definition: PAPER  */
#line 1293 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5180 "src-generated/ugbc.tab.c"
    break;

  case 346: /* writing_part_definition: PAPER ONLY  */
#line 1297 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5189 "src-generated/ugbc.tab.c"
    break;

  case 347: /* writing_part_definition: PEN  */
#line 1301 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5198 "src-generated/ugbc.tab.c"
    break;

  case 348: /* writing_part_definition: PEN ONLY  */
#line 1305 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5207 "src-generated/ugbc.tab.c"
    break;

  case 349: /* writing_definition: writing_mode_definition COMMA writing_part_definition  */
#line 1312 "src/ugbc.y"
                                                          {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5215 "src-generated/ugbc.tab.c"
    break;

  case 367: /* statement: INC Identifier  */
#line 1335 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 5223 "src-generated/ugbc.tab.c"
    break;

  case 368: /* statement: DEC Identifier  */
#line 1338 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 5231 "src-generated/ugbc.tab.c"
    break;

  case 369: /* statement: RANDOMIZE  */
#line 1341 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 5239 "src-generated/ugbc.tab.c"
    break;

  case 370: /* statement: RANDOMIZE expr  */
#line 1344 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 5247 "src-generated/ugbc.tab.c"
    break;

  case 371: /* statement: IF expr THEN  */
#line 1347 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5255 "src-generated/ugbc.tab.c"
    break;

  case 372: /* statement: ELSE  */
#line 1350 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 5263 "src-generated/ugbc.tab.c"
    break;

  case 373: /* statement: ELSE IF expr THEN  */
#line 1353 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5271 "src-generated/ugbc.tab.c"
    break;

  case 374: /* statement: ENDIF  */
#line 1356 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5279 "src-generated/ugbc.tab.c"
    break;

  case 375: /* statement: DO  */
#line 1359 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5287 "src-generated/ugbc.tab.c"
    break;

  case 376: /* statement: LOOP  */
#line 1362 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5295 "src-generated/ugbc.tab.c"
    break;

  case 377: /* $@15: %empty  */
#line 1365 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5303 "src-generated/ugbc.tab.c"
    break;

  case 378: /* statement: WHILE $@15 expr  */
#line 1367 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5311 "src-generated/ugbc.tab.c"
    break;

  case 379: /* statement: WEND  */
#line 1370 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5319 "src-generated/ugbc.tab.c"
    break;

  case 380: /* statement: REPEAT  */
#line 1373 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5327 "src-generated/ugbc.tab.c"
    break;

  case 381: /* statement: UNTIL expr  */
#line 1376 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5335 "src-generated/ugbc.tab.c"
    break;

  case 382: /* statement: EXIT  */
#line 1379 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5343 "src-generated/ugbc.tab.c"
    break;

  case 383: /* statement: EXIT PROC  */
#line 1382 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5351 "src-generated/ugbc.tab.c"
    break;

  case 384: /* statement: POP PROC  */
#line 1385 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5359 "src-generated/ugbc.tab.c"
    break;

  case 385: /* statement: EXIT IF expr  */
#line 1388 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5367 "src-generated/ugbc.tab.c"
    break;

  case 386: /* statement: EXIT Integer  */
#line 1391 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5375 "src-generated/ugbc.tab.c"
    break;

  case 387: /* statement: EXIT direct_integer  */
#line 1394 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5383 "src-generated/ugbc.tab.c"
    break;

  case 388: /* statement: EXIT IF expr COMMA Integer  */
#line 1397 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5391 "src-generated/ugbc.tab.c"
    break;

  case 389: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1400 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5399 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1403 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5407 "src-generated/ugbc.tab.c"
    break;

  case 391: /* statement: NEXT  */
#line 1406 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5415 "src-generated/ugbc.tab.c"
    break;

  case 392: /* statement: PROCEDURE Identifier  */
#line 1409 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5424 "src-generated/ugbc.tab.c"
    break;

  case 393: /* $@16: %empty  */
#line 1413 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5432 "src-generated/ugbc.tab.c"
    break;

  case 394: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1415 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5440 "src-generated/ugbc.tab.c"
    break;

  case 395: /* statement: SHARED parameters_expr  */
#line 1418 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5448 "src-generated/ugbc.tab.c"
    break;

  case 396: /* statement: GLOBAL parameters_expr  */
#line 1421 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5456 "src-generated/ugbc.tab.c"
    break;

  case 397: /* statement: END PROC  */
#line 1424 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 5464 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statement: END PROC OSP expr CSP  */
#line 1427 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5472 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1430 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5480 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: Identifier " "  */
#line 1433 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5489 "src-generated/ugbc.tab.c"
    break;

  case 401: /* statement: PROC Identifier  */
#line 1437 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5498 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: CALL Identifier  */
#line 1441 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5507 "src-generated/ugbc.tab.c"
    break;

  case 403: /* $@17: %empty  */
#line 1445 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5515 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: Identifier OSP $@17 values CSP  */
#line 1447 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5523 "src-generated/ugbc.tab.c"
    break;

  case 405: /* $@18: %empty  */
#line 1450 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5531 "src-generated/ugbc.tab.c"
    break;

  case 406: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1452 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5539 "src-generated/ugbc.tab.c"
    break;

  case 407: /* $@19: %empty  */
#line 1455 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5547 "src-generated/ugbc.tab.c"
    break;

  case 408: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1457 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5555 "src-generated/ugbc.tab.c"
    break;

  case 409: /* statement: PEN expr  */
#line 1460 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 5563 "src-generated/ugbc.tab.c"
    break;

  case 410: /* statement: PAPER expr  */
#line 1463 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 5571 "src-generated/ugbc.tab.c"
    break;

  case 411: /* statement: INVERSE ON  */
#line 1466 "src/ugbc.y"
               {
      text_inverse( _environment, 1 );
  }
#line 5579 "src-generated/ugbc.tab.c"
    break;

  case 412: /* statement: INVERSE OFF  */
#line 1469 "src/ugbc.y"
                {
      text_inverse( _environment, 0 );
  }
#line 5587 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: Identifier COLON  */
#line 1473 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 5595 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: BEG GAMELOOP  */
#line 1476 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 5603 "src-generated/ugbc.tab.c"
    break;

  case 416: /* statement: END GAMELOOP  */
#line 1479 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 5611 "src-generated/ugbc.tab.c"
    break;

  case 417: /* statement: GRAPHIC  */
#line 1482 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 5619 "src-generated/ugbc.tab.c"
    break;

  case 418: /* statement: HALT  */
#line 1485 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 5627 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: END  */
#line 1488 "src/ugbc.y"
        {
      end( _environment );
  }
#line 5635 "src-generated/ugbc.tab.c"
    break;

  case 424: /* statement: RETURN  */
#line 1495 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 5643 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: RETURN expr  */
#line 1498 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 5651 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: POP  */
#line 1501 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 5659 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: DONE  */
#line 1504 "src/ugbc.y"
          {
      return 0;
  }
#line 5667 "src-generated/ugbc.tab.c"
    break;

  case 428: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1507 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5675 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1510 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5683 "src-generated/ugbc.tab.c"
    break;

  case 430: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1513 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 5691 "src-generated/ugbc.tab.c"
    break;

  case 431: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1516 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5699 "src-generated/ugbc.tab.c"
    break;

  case 434: /* statement: Identifier ASSIGN expr  */
#line 1521 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 5713 "src-generated/ugbc.tab.c"
    break;

  case 435: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1530 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 5727 "src-generated/ugbc.tab.c"
    break;

  case 436: /* $@20: %empty  */
#line 1539 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5736 "src-generated/ugbc.tab.c"
    break;

  case 437: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1543 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 5749 "src-generated/ugbc.tab.c"
    break;

  case 438: /* $@21: %empty  */
#line 1551 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5758 "src-generated/ugbc.tab.c"
    break;

  case 439: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1554 "src/ugbc.y"
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
#line 5777 "src-generated/ugbc.tab.c"
    break;

  case 440: /* $@22: %empty  */
#line 1568 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5786 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1571 "src/ugbc.y"
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
#line 5805 "src-generated/ugbc.tab.c"
    break;

  case 442: /* statement: DEBUG expr  */
#line 1585 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 5813 "src-generated/ugbc.tab.c"
    break;

  case 445: /* statements_no_linenumbers: statement  */
#line 1593 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 5819 "src-generated/ugbc.tab.c"
    break;

  case 446: /* $@23: %empty  */
#line 1594 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 5825 "src-generated/ugbc.tab.c"
    break;

  case 448: /* $@24: %empty  */
#line 1598 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 5833 "src-generated/ugbc.tab.c"
    break;

  case 449: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1600 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 5841 "src-generated/ugbc.tab.c"
    break;

  case 450: /* $@25: %empty  */
#line 1605 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 5849 "src-generated/ugbc.tab.c"
    break;

  case 456: /* $@26: %empty  */
#line 1615 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 5855 "src-generated/ugbc.tab.c"
    break;


#line 5859 "src-generated/ugbc.tab.c"

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

#line 1617 "src/ugbc.y"


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

