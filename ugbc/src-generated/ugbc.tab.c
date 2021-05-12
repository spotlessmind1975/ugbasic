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
  YYSYMBOL_BLACK = 154,                    /* BLACK  */
  YYSYMBOL_WHITE = 155,                    /* WHITE  */
  YYSYMBOL_RED = 156,                      /* RED  */
  YYSYMBOL_CYAN = 157,                     /* CYAN  */
  YYSYMBOL_VIOLET = 158,                   /* VIOLET  */
  YYSYMBOL_GREEN = 159,                    /* GREEN  */
  YYSYMBOL_BLUE = 160,                     /* BLUE  */
  YYSYMBOL_YELLOW = 161,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 162,                   /* ORANGE  */
  YYSYMBOL_BROWN = 163,                    /* BROWN  */
  YYSYMBOL_LIGHT = 164,                    /* LIGHT  */
  YYSYMBOL_DARK = 165,                     /* DARK  */
  YYSYMBOL_GREY = 166,                     /* GREY  */
  YYSYMBOL_GRAY = 167,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 168,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 169,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 170,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 171,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 172,                /* TURQUOISE  */
  YYSYMBOL_TAN = 173,                      /* TAN  */
  YYSYMBOL_PINK = 174,                     /* PINK  */
  YYSYMBOL_PEACH = 175,                    /* PEACH  */
  YYSYMBOL_OLIVE = 176,                    /* OLIVE  */
  YYSYMBOL_Identifier = 177,               /* Identifier  */
  YYSYMBOL_String = 178,                   /* String  */
  YYSYMBOL_Integer = 179,                  /* Integer  */
  YYSYMBOL_180_ = 180,                     /* " "  */
  YYSYMBOL_YYACCEPT = 181,                 /* $accept  */
  YYSYMBOL_expr = 182,                     /* expr  */
  YYSYMBOL_expr_math = 183,                /* expr_math  */
  YYSYMBOL_term = 184,                     /* term  */
  YYSYMBOL_modula = 185,                   /* modula  */
  YYSYMBOL_factor = 186,                   /* factor  */
  YYSYMBOL_direct_integer = 187,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 188, /* random_definition_simple  */
  YYSYMBOL_random_definition = 189,        /* random_definition  */
  YYSYMBOL_color_enumeration = 190,        /* color_enumeration  */
  YYSYMBOL_exponential = 191,              /* exponential  */
  YYSYMBOL_192_1 = 192,                    /* $@1  */
  YYSYMBOL_193_2 = 193,                    /* $@2  */
  YYSYMBOL_position = 194,                 /* position  */
  YYSYMBOL_bank_definition_simple = 195,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 196, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 197,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 198, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 199, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 200,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 201, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 202, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 203,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 204,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 205, /* color_definition_expression  */
  YYSYMBOL_color_definition = 206,         /* color_definition  */
  YYSYMBOL_milliseconds = 207,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 208,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 209, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 210,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 211, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 212, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 213,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 214, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 215, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 216,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 217, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 218, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 219,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 220,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 221, /* text_definition_expression  */
  YYSYMBOL_text_definition = 222,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 223,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 224, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 225,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 226, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 227, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 228,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 229, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 230, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 231,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 232,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 233,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 234,         /* gosub_definition  */
  YYSYMBOL_var_definition = 235,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 236,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 237, /* point_definition_expression  */
  YYSYMBOL_point_definition = 238,         /* point_definition  */
  YYSYMBOL_ink_definition = 239,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 240,       /* on_goto_definition  */
  YYSYMBOL_241_3 = 241,                    /* $@3  */
  YYSYMBOL_on_gosub_definition = 242,      /* on_gosub_definition  */
  YYSYMBOL_243_4 = 243,                    /* $@4  */
  YYSYMBOL_on_proc_definition = 244,       /* on_proc_definition  */
  YYSYMBOL_245_5 = 245,                    /* $@5  */
  YYSYMBOL_on_definition = 246,            /* on_definition  */
  YYSYMBOL_247_6 = 247,                    /* $@6  */
  YYSYMBOL_248_7 = 248,                    /* $@7  */
  YYSYMBOL_249_8 = 249,                    /* $@8  */
  YYSYMBOL_every_definition = 250,         /* every_definition  */
  YYSYMBOL_add_definition = 251,           /* add_definition  */
  YYSYMBOL_dimensions = 252,               /* dimensions  */
  YYSYMBOL_datatype = 253,                 /* datatype  */
  YYSYMBOL_dim_definition = 254,           /* dim_definition  */
  YYSYMBOL_255_9 = 255,                    /* $@9  */
  YYSYMBOL_256_10 = 256,                   /* $@10  */
  YYSYMBOL_257_11 = 257,                   /* $@11  */
  YYSYMBOL_dim_definitions = 258,          /* dim_definitions  */
  YYSYMBOL_indexes = 259,                  /* indexes  */
  YYSYMBOL_parameters = 260,               /* parameters  */
  YYSYMBOL_values = 261,                   /* values  */
  YYSYMBOL_statement = 262,                /* statement  */
  YYSYMBOL_263_12 = 263,                   /* $@12  */
  YYSYMBOL_264_13 = 264,                   /* $@13  */
  YYSYMBOL_265_14 = 265,                   /* $@14  */
  YYSYMBOL_266_15 = 266,                   /* $@15  */
  YYSYMBOL_267_16 = 267,                   /* $@16  */
  YYSYMBOL_268_17 = 268,                   /* $@17  */
  YYSYMBOL_269_18 = 269,                   /* $@18  */
  YYSYMBOL_270_19 = 270,                   /* $@19  */
  YYSYMBOL_statements_no_linenumbers = 271, /* statements_no_linenumbers  */
  YYSYMBOL_272_20 = 272,                   /* $@20  */
  YYSYMBOL_statements_with_linenumbers = 273, /* statements_with_linenumbers  */
  YYSYMBOL_274_21 = 274,                   /* $@21  */
  YYSYMBOL_statements_complex = 275,       /* statements_complex  */
  YYSYMBOL_276_22 = 276,                   /* $@22  */
  YYSYMBOL_program = 277,                  /* program  */
  YYSYMBOL_278_23 = 278                    /* $@23  */
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
#define YYLAST   1999

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  181
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  408
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  794

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   435


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
     175,   176,   177,   178,   179,   180
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
     440,   443,   446,   449,   452,   455,   458,   461,   464,   468,
     472,   476,   479,   482,   487,   487,   490,   493,   496,   499,
     502,   505,   509,   512,   515,   518,   522,   525,   528,   531,
     535,   538,   541,   544,   550,   553,   556,   559,   562,   567,
     568,   571,   574,   579,   582,   587,   588,   591,   594,   599,
     602,   607,   608,   611,   614,   617,   622,   625,   628,   633,
     634,   637,   638,   639,   642,   645,   648,   653,   656,   659,
     665,   666,   669,   672,   675,   678,   681,   684,   687,   690,
     693,   696,   699,   702,   705,   708,   711,   716,   719,   722,
     725,   728,   731,   734,   737,   740,   743,   746,   749,   752,
     755,   758,   763,   764,   767,   770,   773,   776,   779,   785,
     788,   794,   795,   798,   803,   808,   809,   812,   815,   820,
     823,   828,   829,   832,   837,   842,   843,   846,   849,   852,
     857,   860,   866,   867,   870,   873,   876,   879,   882,   887,
     890,   893,   898,   899,   901,   902,   905,   908,   911,   916,
     923,   926,   932,   935,   941,   944,   950,   955,   956,   959,
     964,   968,   968,   973,   977,   977,   982,   986,   986,   991,
     991,   994,   994,   997,   997,  1002,  1005,  1008,  1013,  1016,
    1022,  1026,  1033,  1036,  1039,  1042,  1045,  1048,  1051,  1054,
    1057,  1060,  1065,  1065,  1073,  1073,  1081,  1081,  1092,  1093,
    1097,  1101,  1108,  1113,  1118,  1123,  1128,  1133,  1141,  1145,
    1152,  1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,
    1162,  1163,  1164,  1165,  1166,  1167,  1168,  1171,  1174,  1177,
    1180,  1183,  1186,  1189,  1192,  1195,  1198,  1198,  1203,  1206,
    1209,  1212,  1215,  1218,  1221,  1224,  1227,  1230,  1233,  1236,
    1239,  1242,  1246,  1246,  1251,  1254,  1257,  1260,  1263,  1267,
    1271,  1275,  1275,  1280,  1280,  1285,  1285,  1290,  1293,  1296,
    1299,  1302,  1305,  1308,  1309,  1310,  1311,  1312,  1315,  1318,
    1321,  1324,  1327,  1330,  1333,  1334,  1343,  1352,  1352,  1364,
    1364,  1381,  1381,  1398,  1401,  1402,  1406,  1407,  1407,  1411,
    1411,  1418,  1418,  1421,  1422,  1423,  1424,  1428,  1428
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
  "BLACK", "WHITE", "RED", "CYAN", "VIOLET", "GREEN", "BLUE", "YELLOW",
  "ORANGE", "BROWN", "LIGHT", "DARK", "GREY", "GRAY", "MAGENTA", "PURPLE",
  "LAVENDER", "GOLD", "TURQUOISE", "TAN", "PINK", "PEACH", "OLIVE",
  "Identifier", "String", "Integer", "\" \"", "$accept", "expr",
  "expr_math", "term", "modula", "factor", "direct_integer",
  "random_definition_simple", "random_definition", "color_enumeration",
  "exponential", "$@1", "$@2", "position", "bank_definition_simple",
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
  "on_goto_definition", "$@3", "on_gosub_definition", "$@4",
  "on_proc_definition", "$@5", "on_definition", "$@6", "$@7", "$@8",
  "every_definition", "add_definition", "dimensions", "datatype",
  "dim_definition", "$@9", "$@10", "$@11", "dim_definitions", "indexes",
  "parameters", "values", "statement", "$@12", "$@13", "$@14", "$@15",
  "$@16", "$@17", "$@18", "$@19", "statements_no_linenumbers", "$@20",
  "statements_with_linenumbers", "$@21", "statements_complex", "$@22",
  "program", "$@23", YY_NULLPTR
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
     435
};
#endif

#define YYPACT_NINF (-581)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-388)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -581,    50,   748,  -581,  -581,  -135,  -112,   -15,  -581,    67,
    1421,    55,    -5,  1421,  -581,    31,   175,  1554,   -76,    32,
    -581,  -581,  -581,  1130,    84,    40,  1554,    21,   -61,  -581,
      88,   103,  1554,  1554,  -581,   116,   130,    57,  -581,    13,
      96,  -581,   -35,  -581,  1554,     1,  1288,   147,    27,  1554,
      44,    58,    77,    79,    80,    80,     4,  -581,   144,   204,
     246,  -581,  -581,  -581,  1421,   234,  -581,  -581,  -581,  1421,
    1421,  1421,  -581,  -581,  -581,    81,   972,  -581,  -581,   227,
     228,   229,   131,    85,  -581,  -581,   231,   235,  1554,  -581,
    -581,   236,   237,   239,   241,   242,   243,   244,   247,   266,
     267,   268,   269,   272,   273,   274,   275,   276,  -581,  -581,
     277,  -581,  -581,  -581,  -581,  -581,  -581,  -581,   154,  -581,
    -581,    66,   -30,  -581,  -581,  -581,  -581,  -581,  -581,  -581,
    -581,  -581,   155,    42,  -581,  -581,   -31,    98,   185,   170,
     189,   -27,  -581,  -581,  -581,  -581,  -581,    -9,   192,    -4,
      -3,     2,    11,   295,  -581,  -581,  -581,   280,   328,  -581,
    -581,  -581,  1421,  -581,  -581,   291,  -581,  -581,  -581,  -581,
    -581,  1421,   278,   281,  -581,  -581,  -581,    -2,  -581,    43,
    -581,  -581,  -581,  -581,  -581,  1554,  1554,  -581,  -581,   314,
    -581,  -581,  -581,  1421,  -581,  -581,  -581,  1421,   293,  -581,
    -581,  -581,   257,  -581,  -581,  -581,  1554,  1554,  -581,  -581,
    1421,  -581,  -581,  -581,   294,  -581,  -581,  -581,  -581,  -581,
    -581,  -581,  1554,  1554,  -581,  -581,  -581,  -581,   316,  -581,
    -581,   178,  -581,  1554,   324,  -581,  -581,  -581,    20,   325,
    -581,   188,   194,   195,    36,  -581,  -581,  -581,  -581,  1554,
     330,  -581,  -581,   310,     6,   888,  -581,   748,   748,   318,
     319,  1421,  -581,  -581,   279,   282,   283,   285,  -581,   315,
     323,   326,   327,   331,    73,   332,  1421,  1421,  1421,  -581,
    -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,  1554,
    1554,  -581,  1554,  1554,  1554,  1554,  1554,  1554,  1554,  1554,
    1554,  1554,  1554,  1554,  1554,  1554,  1554,  1554,  1554,  1687,
    -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,   329,   334,
    -581,  -581,  -581,  -581,  -581,  -581,  1687,  1687,  1687,  1687,
    1687,  1687,  1687,  1687,  1687,  1687,  1687,  1687,  1687,  1820,
    -581,  -581,  -581,  1421,   335,  -581,  -581,  -581,   321,   192,
     346,   192,   347,   192,   348,   192,   352,   192,  -581,  1554,
     350,  -581,  -581,   145,   171,    34,   115,  -581,  -581,  -581,
     345,   192,   354,  -581,  -581,   174,   181,   126,   140,  -581,
    -581,   355,  -581,  -581,  1421,  -581,  -581,  1421,  1421,  -581,
    -581,  -581,   338,   211,  -581,   374,  1554,  -581,  -581,  -581,
    -581,  1421,  -581,   383,   385,  -581,  -581,  1421,   333,   388,
    1554,   296,   389,  1554,  -581,  -581,  -581,  -581,  -581,  -581,
      92,  -581,  -581,   365,   381,    44,  -581,   259,  -581,    80,
     400,     6,   748,  -581,  1554,   375,  1554,  1554,   376,    12,
    -581,   888,  -581,  -581,   245,   248,  -581,  -581,  1554,   192,
    1554,   192,   233,   249,   250,   251,   252,   373,   379,   386,
    -581,   392,   397,   399,   401,   402,   404,   409,   411,   413,
     416,   406,   407,   408,   410,   428,   412,   417,   418,   419,
     420,   437,   441,   421,   422,   423,    -1,   425,  1554,   185,
     185,   240,   240,   240,   240,   240,   240,   240,   240,   170,
     189,   189,  -581,   431,   432,  1421,    25,  -581,   192,  -581,
     192,  -581,   192,  -581,   192,   117,  -581,  1554,  -581,  -581,
    -581,  -581,  -581,  -581,  -581,  -581,  1554,  -581,   192,  -581,
    -581,  -581,  -581,  -581,  -581,  -581,  -581,   192,  -581,  -581,
    -581,  -581,  -581,  -581,   287,   288,   289,   290,   438,  1554,
     455,   426,   429,  1554,  1554,   463,   465,  -581,   -45,   403,
     297,  1554,   466,  -581,  -581,  -581,   442,   298,   444,  -581,
    1554,    80,  1554,  -581,    80,   472,  -581,  -581,  1554,   473,
     336,   474,   447,  1554,  -581,  -581,  -581,  -581,  -581,  -581,
    -581,  -581,  -581,  -581,  -581,  -581,   304,   306,   307,  -581,
    -581,  -581,  -581,  -581,  -581,  1554,  1554,  1554,  1554,  -581,
    -581,  -581,  -581,  1554,  -581,  -581,  -581,  -581,  -581,  1554,
    1554,  -581,  -581,  -581,  1820,  1554,   452,   311,   312,  -581,
    -581,  -581,  -581,  -581,  -581,   461,  -581,   462,  -581,   320,
     121,  -581,   485,  -581,   486,   487,  -581,   489,  -581,   490,
    -581,   488,  1421,   492,  1554,  1554,   192,   467,   468,  1554,
     192,  -581,  -581,  1554,  -581,    51,  1554,   298,   493,   469,
     298,   357,   358,   360,  -581,    80,   475,  1554,  -581,  1554,
     496,   477,  -581,  -581,  -581,   479,   480,    64,    82,   483,
     484,   491,   494,   495,  -581,  -581,  -581,   343,   344,  -581,
     498,  -581,   499,  -581,  1554,   192,   516,   517,   518,  1554,
    -581,  -581,  1554,  -581,  -581,  -581,   519,   520,   500,   501,
     427,  1554,   521,   459,   502,   298,  -581,   503,  -581,  -581,
    -581,  -581,   527,  -581,  -581,  1554,   528,  -581,  -581,  1554,
    -581,  1554,  -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,
     367,   368,   512,   513,   287,   288,   289,  -581,  -581,  1554,
    1554,  -581,  -581,  1554,   514,  1554,  1554,  -581,  -581,  -581,
    1554,  -581,  1554,   515,   522,  -581,  -581,  -581,  -581,  -581,
    -581,  -581,  -581,  -581,  -581,   539,  -581,  -581,  -581,  -581,
    -581,  -581,  1554,  -581
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     407,     0,   395,     1,   394,     0,     0,     0,   379,     0,
       0,   350,     0,     0,   371,     0,     0,     0,   244,     0,
     335,   339,   336,     0,     0,     0,     0,     0,   372,   333,
       0,     0,     0,   328,   370,     0,     0,     0,   377,   378,
     331,   334,   341,   338,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   391,   399,   396,   403,
     405,   408,   326,   327,     0,     0,   145,   146,   311,     0,
       0,     0,   159,   160,   313,     0,     0,    79,    80,     0,
       0,     0,     0,     0,   111,   112,     0,     0,     0,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   113,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,    44,    49,    50,    51,    52,    53,    54,
      57,    58,     0,    63,    67,    65,     0,     2,    12,    15,
      17,     0,    76,    20,   170,   171,   314,     0,     0,     0,
       0,     0,     0,     0,   139,   140,   310,     0,     0,   202,
     203,   315,     0,   205,   206,   207,   211,   212,   316,   234,
     235,     0,     0,     0,   242,   243,   321,     0,   373,     0,
     254,   324,   250,   251,   374,     0,     0,   217,   218,     0,
     221,   222,   318,     0,   225,   226,   319,     0,   228,   232,
     233,   320,     0,   368,   369,   356,     0,     0,   393,   329,
       0,   215,   216,   317,     0,   257,   258,   322,   252,   253,
     375,   343,     0,     0,   342,   345,   346,   340,     0,   276,
     277,     0,   376,     0,     0,   325,   259,   323,   292,   298,
     384,   359,   351,   360,   302,   354,   355,   401,   367,     0,
     389,   361,   358,     0,     0,   395,   397,   395,   395,     0,
       0,     0,   156,   153,     0,     0,     0,     0,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      24,    25,    27,    29,    30,    26,    31,   101,    23,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    42,    45,    46,    47,    48,    43,    56,    64,     0,
     161,   167,   162,   163,   168,   169,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     164,   165,   166,     0,     0,   151,   152,   312,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,     0,
       0,   192,   193,     0,     0,     0,     0,   189,   188,   114,
       0,     0,     0,   177,   178,     0,     0,     0,     0,   174,
     173,     0,   209,   204,     0,   239,   236,     0,     0,   269,
     273,   271,     0,     0,   337,     0,     0,   224,   223,   230,
     227,     0,   330,     0,     0,   214,   213,     0,     0,   344,
       0,     0,     0,     0,   290,   282,   284,   289,   286,   291,
       0,   288,   296,     0,     0,     0,   363,     0,   365,     0,
     303,     0,   395,   385,     0,     0,     0,     0,     0,   391,
     400,   395,   404,   406,     0,     0,   143,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      14,     5,     7,     8,     9,    10,     6,     3,     4,    16,
      18,    19,    21,     0,     0,     0,     0,   121,     0,   133,
       0,   125,     0,   129,     0,   117,   190,     0,   197,   196,
     201,   200,   195,   199,   194,   198,     0,   175,     0,   182,
     181,   186,   185,   180,   184,   179,   183,     0,   210,   208,
     240,   237,   241,   238,     0,     0,     0,     0,   245,     0,
       0,     0,     0,     0,     0,     0,     0,   332,     0,     0,
       0,     0,   278,   283,   285,   287,     0,     0,     0,   299,
       0,     0,     0,   305,     0,   304,   402,   386,     0,   308,
       0,   300,     0,     0,   398,   144,   142,   158,   155,   157,
     154,    75,    68,    70,    74,    72,     0,     0,     0,    78,
      77,    82,    81,    84,    83,     0,     0,     0,     0,    91,
      92,    93,   100,     0,    94,    95,    96,    97,    98,     0,
       0,   106,   107,   102,     0,     0,     0,     0,     0,   149,
     147,   118,   131,   123,   126,   120,   132,   124,   128,     0,
       0,   187,     0,   172,     0,   260,   270,   263,   274,   266,
     272,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   347,   348,     0,   275,     0,     0,     0,   280,     0,
       0,     0,     0,     0,   306,     0,     0,     0,   362,     0,
       0,     0,    69,    71,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60,   150,   148,     0,     0,   134,
     119,   130,   122,   127,     0,     0,     0,     0,     0,     0,
     248,   247,     0,   220,   231,   229,     0,     0,     0,     0,
     349,     0,     0,     0,     0,     0,   293,     0,   364,   353,
     366,   307,     0,   309,   301,     0,     0,    85,    86,     0,
      87,     0,    89,    99,   105,   104,    22,    62,   136,   138,
       0,     0,     0,     0,     0,     0,     0,   249,   219,     0,
       0,   256,   255,     0,     0,     0,     0,   297,   281,   295,
       0,   388,     0,     0,     0,   135,   137,   191,   176,   262,
     265,   268,   380,   381,   357,     0,   382,   279,   390,   392,
      88,    90,     0,   383
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -581,   -10,   -88,   -74,   217,  -268,    62,  -581,  -581,  -581,
    -325,  -581,  -581,   396,  -581,  -581,  -581,  -581,  -581,  -581,
    -581,  -581,  -581,  -581,  -581,  -581,   414,  -581,  -581,  -581,
    -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,
    -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,
    -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,  -198,
    -581,  -197,  -581,  -195,  -581,  -581,  -581,  -581,  -581,  -581,
    -581,  -580,  -249,  -581,  -581,  -581,  -581,   134,  -486,   -54,
    -542,  -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,
    -251,  -581,  -581,  -581,  -246,  -581,  -581,  -581
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   581,   137,   138,   139,   140,   141,   286,   287,   142,
     143,   319,   487,   370,   154,   155,   156,    66,    67,    68,
     345,   346,   347,    72,    73,    74,   325,   144,   145,   146,
     159,   160,   161,   166,   167,   168,   211,   212,   213,   190,
     191,   192,   194,   195,   196,   199,   200,   201,   174,   175,
     176,   180,   184,   220,   181,   215,   216,   217,   237,   646,
     706,   648,   707,   650,   708,   178,   544,   546,   545,   232,
     235,   669,   422,   239,   423,   424,   566,   240,   582,   245,
     580,    58,   185,   427,   436,   570,   572,   253,   435,   254,
      59,   441,    60,   255,    61,   432,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     136,   246,   626,   157,   440,   438,   624,   177,   247,    64,
     248,   442,   443,   189,   502,   343,   202,   249,   248,   148,
     349,   351,   208,   209,   250,   249,   353,   149,   671,   204,
     673,   414,   250,   223,   227,   355,   231,    83,  -387,   236,
    -294,   486,    62,   429,   150,   414,  -387,    83,   320,   321,
       3,   389,   320,   340,   259,   162,   430,   631,   721,   262,
     264,   266,   318,   392,   197,    63,   275,   163,   164,   500,
     501,   739,   151,   152,   632,   158,   -59,   147,   291,   522,
     415,   416,   417,   205,   431,   393,   722,   724,   523,   741,
     727,   418,   676,    69,   415,   416,   417,   681,    70,   740,
     390,   179,   633,   634,   226,   418,   326,   327,   193,   224,
     328,   203,   329,   330,   331,   332,   333,   742,   165,   322,
     323,   324,   206,   322,   323,   341,   260,   198,   339,   419,
     315,   263,   265,   267,   661,   733,   316,   207,    71,   693,
     210,   420,   391,   419,   225,   768,   639,   457,   458,   421,
     256,   251,   382,   700,   214,   420,   279,   221,   459,   251,
     524,   385,    65,   421,   222,   640,   563,   564,   344,   525,
     701,   533,   153,   350,   352,   394,   395,   565,   228,   354,
     534,   233,   575,   397,   252,   535,   576,   399,   356,   337,
     584,   338,   252,   734,   536,   334,   403,   404,   702,   703,
     405,   518,   519,   335,   234,   280,   281,   282,   257,   182,
     348,   183,   408,   409,   283,   284,   285,   169,   170,   171,
     172,   238,   311,   412,   383,   312,   313,   520,   521,   173,
     529,   530,   314,   386,   218,   241,   219,   531,   532,   433,
     491,   492,   493,   494,   495,   496,   497,   498,   326,   327,
     258,   446,   489,   490,   242,   398,   243,   244,   261,   400,
     268,   276,   277,   278,   288,   289,   461,   463,   465,   290,
     292,   293,   406,   294,    83,   295,   296,   297,   298,   467,
     468,   299,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   692,
     300,   301,   302,   303,   358,   359,   304,   305,   306,   307,
     308,   309,   360,   310,   317,   336,   361,   362,   339,   357,
     384,   396,   401,   447,   387,   363,   402,   388,   407,   410,
     411,   413,   425,   503,   364,   426,   365,   366,   462,   464,
     466,  -352,   428,   434,   437,   367,   368,   444,   445,   516,
     452,   448,   358,   371,   449,   450,   369,   451,   453,   505,
     372,   454,   455,   -61,   373,   374,   456,   460,   488,   506,
     508,   510,   512,   375,   538,   573,   514,   540,   542,   526,
     547,   549,   376,   517,   377,   378,   550,   528,   548,   537,
     553,   551,   554,   379,   380,   558,   561,   555,   560,   567,
     559,   568,   557,   562,   369,   504,   571,   574,   596,   578,
     583,   507,   591,   509,   597,   511,   605,   513,   606,   515,
     607,   598,   585,   608,   577,   586,   579,   599,   592,   593,
     594,   595,   600,   527,   601,   613,   602,   603,   587,   604,
     589,   609,   610,   611,   619,   612,   539,   614,   620,   541,
     543,   652,   615,   616,   617,   618,   621,   622,   623,   625,
     627,   628,   654,   552,   645,   647,   649,   651,   655,   556,
     659,   656,   660,   666,   664,   663,   667,   668,   670,   675,
     677,   679,   680,   682,   678,   683,   684,   694,   695,   696,
     697,   698,   704,   705,  -261,   629,  -264,  -267,   699,   712,
     725,   709,   716,   717,   726,   728,   729,   641,   730,   735,
     732,   588,   736,   590,   737,   738,   642,   672,   743,   744,
     674,   748,   749,   754,   755,   756,   745,   750,   751,   746,
     747,   766,   759,   760,   765,   761,   762,   767,   769,   653,
     770,   772,   763,   657,   658,   775,   776,   777,   778,   785,
     790,   665,   792,   499,   381,   342,   779,   791,   780,   569,
     579,   781,   579,     0,     0,     0,     0,   630,     0,     0,
     635,     0,   636,     0,   637,     0,   638,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     643,     0,     0,     0,     0,   685,   686,   687,   688,   644,
       0,     0,     0,   689,     0,     0,     0,     0,     0,   690,
     691,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     662,   731,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   710,     0,   713,   714,     0,     0,     0,   718,
       0,     0,     0,   720,     0,     0,   723,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   579,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   752,     0,     0,     0,     0,   757,
       0,     0,   758,     0,     0,     0,     0,     0,     0,     0,
       0,   764,     0,     0,   711,     0,     0,     0,   715,     0,
       0,     0,   719,     0,     0,   771,     0,     0,     0,   773,
       0,   774,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   782,
     783,     4,     0,   784,     0,   786,   787,     0,     5,     6,
     788,     0,   789,     0,     0,     0,     0,   753,     0,     0,
       7,     8,     0,     9,     0,    10,    11,     0,    12,    13,
       0,     0,   793,     0,     0,     0,    14,     0,    15,    16,
      17,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    28,     0,    29,
       0,     0,    30,    31,    32,     0,    33,    34,    35,    36,
      37,    38,    39,     0,    40,     0,     0,     0,    41,    42,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,    49,     0,     0,
      50,     4,    51,    52,    53,     0,     0,    54,     5,     6,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     9,     0,    10,    11,     0,    12,    13,
       0,     0,     0,     0,     0,    56,    14,    57,    15,    16,
      17,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    28,     0,    29,
       0,    75,    30,    31,    32,     0,    33,    34,    35,    36,
      37,    38,    39,     0,    40,     0,     0,   269,    41,    42,
      43,    44,    45,     0,    46,    47,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,    77,    78,    79,     0,     0,    49,     0,     0,
      50,     0,    51,    52,    53,     0,     0,    54,     0,    80,
       0,    55,    81,     0,     0,    82,   270,   271,   272,     0,
       0,     0,     0,     0,     0,    84,    85,   273,     0,     0,
       0,     0,     0,     0,     0,   439,    86,    87,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,   103,   104,   105,   274,   106,   107,
     108,     0,   109,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,    75,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,   186,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,     0,   187,   188,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    78,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
      81,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,     0,   106,   107,   108,     0,
     109,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,    75,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
     229,   230,     0,     0,     0,     0,     0,     0,    77,    78,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,    81,     0,
       0,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
     103,   104,   105,     0,   106,   107,   108,     0,   109,   110,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    76,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,     0,     0,
       0,    77,    78,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,    81,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,   103,   104,   105,     0,   106,   107,   108,
       0,   109,   110,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    76,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,    77,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,    81,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,   103,   104,   105,     0,
     106,   107,   108,     0,   109,   110,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,    76,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,     0,     0,     0,    77,    78,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,     0,     0,    81,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,    90,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,     0,   106,   107,   108,     0,   109,   110,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,    76,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,     0,     0,     0,
      77,    78,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
      81,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,     0,   106,   107,   108,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,     0,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135
};

static const yytype_int16 yycheck[] =
{
      10,    55,   488,    13,   255,   254,     7,    17,     4,    24,
       6,   257,   258,    23,   339,    24,    26,    13,     6,    24,
      24,    24,    32,    33,    20,    13,    24,    32,   570,    90,
     572,    25,    20,    68,    44,    24,    46,    82,    34,    49,
      20,   309,   177,     7,    49,    25,    34,    82,    79,    80,
       0,    53,    79,    80,    64,    24,    20,    32,     7,    69,
      70,    71,    20,    20,    24,   177,    76,    36,    37,   337,
     338,     7,    77,    78,    49,    13,    34,    22,    88,    45,
      74,    75,    76,   144,    48,    42,    35,   667,    54,     7,
     670,    85,   578,    26,    74,    75,    76,   583,    31,    35,
     102,   177,    77,    78,    42,    85,     8,     9,    24,   144,
      12,    90,    14,    15,    16,    17,    18,    35,    87,   150,
     151,   152,    34,   150,   151,   152,    64,    87,   129,   123,
     160,    69,    70,    71,   179,   677,   166,    34,    71,   625,
      24,   135,   144,   123,   179,   725,    29,    74,    75,   143,
       6,   147,   162,    32,    24,   135,    25,   144,    85,   147,
      45,   171,   177,   143,    68,    48,    74,    75,   177,    54,
      49,    45,   177,   177,   177,   185,   186,    85,   177,   177,
      54,    34,   431,   193,   180,    45,   432,   197,   177,    19,
     441,    21,   180,   679,    54,    97,   206,   207,    77,    78,
     210,    56,    57,   105,   177,    74,    75,    76,     4,   177,
     148,   179,   222,   223,    83,    84,    85,    42,    43,    44,
      45,   177,   156,   233,   162,   159,   160,    56,    57,    54,
      56,    57,   166,   171,   177,   177,   179,    56,    57,   249,
     328,   329,   330,   331,   332,   333,   334,   335,     8,     9,
       4,   261,   326,   327,   177,   193,   177,   177,    24,   197,
     179,    34,    34,    34,   179,    34,   276,   277,   278,    34,
      34,    34,   210,    34,    82,    34,    34,    34,    34,   289,
     290,    34,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   624,
      34,    34,    34,    34,    24,    25,    34,    34,    34,    34,
      34,    34,    32,   159,   159,   130,    36,    37,   129,    24,
      29,     7,    29,   261,    46,    45,    69,    46,    34,    13,
     152,     7,     7,   343,    54,   147,    56,    57,   276,   277,
     278,   147,   147,    13,    34,    65,    66,    29,    29,   359,
      35,    72,    24,    25,    72,    72,    76,    72,    35,    24,
      32,    35,    35,    34,    36,    37,    35,    35,    34,    48,
      24,    24,    24,    45,   384,   429,    24,   387,   388,    34,
      42,     7,    54,    33,    56,    57,   396,    33,   177,    34,
       7,   401,     7,    65,    66,     7,     7,   407,   102,    34,
     410,    20,    69,   413,    76,   343,   147,     7,    35,    34,
      34,   349,   179,   351,    35,   353,     7,   355,     7,   357,
       7,    35,   177,     7,   434,   177,   436,    35,   179,   179,
     179,   179,    35,   371,    35,     7,    35,    35,   448,    35,
     450,    35,    35,    35,     7,    35,   384,    35,     7,   387,
     388,    13,    35,    35,    35,    35,    35,    35,    35,    34,
      29,    29,     7,   401,   177,   177,   177,   177,    42,   407,
       7,    42,     7,     7,   177,    72,    34,   179,    34,     7,
       7,     7,    35,   179,   148,   179,   179,    35,   177,   177,
      29,    29,     7,     7,     7,   505,     7,     7,   178,     7,
       7,    13,    35,    35,    35,   148,   148,   517,   148,    13,
      35,   449,    35,   451,    35,    35,   526,   571,    35,    35,
     574,   178,   178,     7,     7,     7,    35,    29,    29,    35,
      35,    72,    13,    13,    13,    35,    35,    35,    35,   549,
      13,    13,   115,   553,   554,   178,   178,    35,    35,    35,
      35,   561,    13,   336,   158,   141,   754,    35,   755,   425,
     570,   756,   572,    -1,    -1,    -1,    -1,   505,    -1,    -1,
     508,    -1,   510,    -1,   512,    -1,   514,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     528,    -1,    -1,    -1,    -1,   605,   606,   607,   608,   537,
      -1,    -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,   619,
     620,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     558,   675,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   652,    -1,   654,   655,    -1,    -1,    -1,   659,
      -1,    -1,    -1,   663,    -1,    -1,   666,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   677,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   704,    -1,    -1,    -1,    -1,   709,
      -1,    -1,   712,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   721,    -1,    -1,   652,    -1,    -1,    -1,   656,    -1,
      -1,    -1,   660,    -1,    -1,   735,    -1,    -1,    -1,   739,
      -1,   741,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   759,
     760,     3,    -1,   763,    -1,   765,   766,    -1,    10,    11,
     770,    -1,   772,    -1,    -1,    -1,    -1,   705,    -1,    -1,
      22,    23,    -1,    25,    -1,    27,    28,    -1,    30,    31,
      -1,    -1,   792,    -1,    -1,    -1,    38,    -1,    40,    41,
      42,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
      -1,    -1,    94,    95,    96,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,    -1,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     142,     3,   144,   145,   146,    -1,    -1,   149,    10,    11,
      -1,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    -1,    25,    -1,    27,    28,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,   177,    38,   179,    40,    41,
      42,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
      -1,     9,    94,    95,    96,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,   106,    -1,    -1,    25,   110,   111,
     112,   113,   114,    -1,   116,   117,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
      -1,    -1,    50,    51,    52,    -1,    -1,   139,    -1,    -1,
     142,    -1,   144,   145,   146,    -1,    -1,   149,    -1,    67,
      -1,   153,    70,    -1,    -1,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   177,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,   132,   133,   134,   135,   136,   137,
     138,    -1,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,     9,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,   132,   133,   134,    -1,   136,   137,   138,    -1,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,     9,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,   137,   138,    -1,   140,   141,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    34,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,   138,
      -1,   140,   141,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    34,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,
     136,   137,   138,    -1,   140,   141,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,    34,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,   141,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,    34,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,   132,   133,   134,    -1,   136,   137,   138,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   277,   278,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    88,    89,    91,
      94,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     106,   110,   111,   112,   113,   114,   116,   117,   131,   139,
     142,   144,   145,   146,   149,   153,   177,   179,   262,   271,
     273,   275,   177,   177,    24,   177,   198,   199,   200,    26,
      31,    71,   204,   205,   206,     9,    34,    50,    51,    52,
      67,    70,    73,    82,    83,    84,    94,    95,   107,   108,
     109,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   132,   133,   134,   136,   137,   138,   140,
     141,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   182,   183,   184,   185,
     186,   187,   190,   191,   208,   209,   210,    22,    24,    32,
      49,    77,    78,   177,   195,   196,   197,   182,   187,   211,
     212,   213,    24,    36,    37,    87,   214,   215,   216,    42,
      43,    44,    45,    54,   229,   230,   231,   182,   246,   177,
     232,   235,   177,   179,   233,   263,    24,    36,    37,   182,
     220,   221,   222,    24,   223,   224,   225,    24,    87,   226,
     227,   228,   182,    90,    90,   144,    34,    34,   182,   182,
      24,   217,   218,   219,    24,   236,   237,   238,   177,   179,
     234,   144,    68,    68,   144,   179,   187,   182,   177,    42,
      43,   182,   250,    34,   177,   251,   182,   239,   177,   254,
     258,   177,   177,   177,   177,   260,   260,     4,     6,    13,
      20,   147,   180,   268,   270,   274,     6,     4,     4,   182,
     187,    24,   182,   187,   182,   187,   182,   187,   179,    25,
      74,    75,    76,    85,   135,   182,    34,    34,    34,    25,
      74,    75,    76,    83,    84,    85,   188,   189,   179,    34,
      34,   182,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
     159,   156,   159,   160,   166,   160,   166,   159,    20,   192,
      79,    80,   150,   151,   152,   207,     8,     9,    12,    14,
      15,    16,    17,    18,    97,   105,   130,    19,    21,   129,
      80,   152,   207,    24,   177,   201,   202,   203,   187,    24,
     177,    24,   177,    24,   177,    24,   177,    24,    24,    25,
      32,    36,    37,    45,    54,    56,    57,    65,    66,    76,
     194,    25,    32,    36,    37,    45,    54,    56,    57,    65,
      66,   194,   182,   187,    29,   182,   187,    46,    46,    53,
     102,   144,    20,    42,   182,   182,     7,   182,   187,   182,
     187,    29,    69,   182,   182,   182,   187,    34,   182,   182,
      13,   152,   182,     7,    25,    74,    75,    76,    85,   123,
     135,   143,   253,   255,   256,     7,   147,   264,   147,     7,
      20,    48,   276,   182,    13,   269,   265,    34,   253,   177,
     271,   272,   275,   275,    29,    29,   182,   187,    72,    72,
      72,    72,    35,    35,    35,    35,    35,    74,    75,    85,
      35,   182,   187,   182,   187,   182,   187,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   186,   193,    34,   184,
     184,   183,   183,   183,   183,   183,   183,   183,   183,   185,
     186,   186,   191,   182,   187,    24,    48,   187,    24,   187,
      24,   187,    24,   187,    24,   187,   182,    33,    56,    57,
      56,    57,    45,    54,    45,    54,    34,   187,    33,    56,
      57,    56,    57,    45,    54,    45,    54,    34,   182,   187,
     182,   187,   182,   187,   247,   249,   248,    42,   177,     7,
     182,   182,   187,     7,     7,   182,   187,    69,     7,   182,
     102,     7,   182,    74,    75,    85,   257,    34,    20,   258,
     266,   147,   267,   260,     7,   253,   275,   182,    34,   182,
     261,   182,   259,    34,   271,   177,   177,   182,   187,   182,
     187,   179,   179,   179,   179,   179,    35,    35,    35,    35,
      35,    35,    35,    35,    35,     7,     7,     7,     7,    35,
      35,    35,    35,     7,    35,    35,    35,    35,    35,     7,
       7,    35,    35,    35,     7,    34,   259,    29,    29,   182,
     187,    32,    49,    77,    78,   187,   187,   187,   187,    29,
      48,   182,   182,   187,   187,   177,   240,   177,   242,   177,
     244,   177,    13,   182,     7,    42,    42,   182,   182,     7,
       7,   179,   187,    72,   177,   182,     7,    34,   179,   252,
      34,   261,   260,   261,   260,     7,   259,     7,   148,     7,
      35,   259,   179,   179,   179,   182,   182,   182,   182,   182,
     182,   182,   191,   259,    35,   177,   177,    29,    29,   178,
      32,    49,    77,    78,     7,     7,   241,   243,   245,    13,
     182,   187,     7,   182,   182,   187,    35,    35,   182,   187,
     182,     7,    35,   182,   252,     7,    35,   252,   148,   148,
     148,   260,    35,   261,   259,    13,    35,    35,    35,     7,
      35,     7,    35,    35,    35,    35,    35,    35,   178,   178,
      29,    29,   182,   187,     7,     7,     7,   182,   182,    13,
      13,    35,    35,   115,   182,    13,    72,    35,   252,    35,
      13,   182,    13,   182,   182,   178,   178,    35,    35,   240,
     242,   244,   182,   182,   182,    35,   182,   182,   182,   182,
      35,    35,    13,   182
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   181,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   183,   183,   183,   184,   184,   185,   185,   185,
     186,   186,   186,   187,   188,   188,   188,   188,   188,   188,
     188,   189,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   192,
     191,   193,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   194,   194,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   196,   196,   196,   196,   196,   197,
     197,   198,   198,   199,   199,   200,   200,   201,   201,   202,
     202,   203,   203,   204,   204,   204,   205,   205,   205,   206,
     206,   207,   207,   207,   208,   208,   208,   209,   209,   209,
     210,   210,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   213,   213,   214,   214,   214,   214,   214,   215,
     215,   216,   216,   217,   218,   219,   219,   220,   220,   221,
     221,   222,   222,   223,   224,   225,   225,   226,   226,   226,
     227,   227,   228,   228,   229,   229,   229,   229,   229,   230,
     230,   230,   231,   231,   232,   232,   232,   232,   232,   232,
     233,   233,   234,   234,   235,   236,   237,   238,   238,   239,
     240,   241,   240,   242,   243,   242,   244,   245,   244,   247,
     246,   248,   246,   249,   246,   250,   250,   250,   251,   251,
     252,   252,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   255,   254,   256,   254,   257,   254,   258,   258,
     259,   259,   260,   260,   260,   260,   260,   260,   261,   261,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   263,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   264,   262,   262,   262,   262,   262,   262,   262,
     262,   265,   262,   266,   262,   267,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   268,   262,   269,
     262,   270,   262,   262,   262,   262,   271,   272,   271,   274,
     273,   276,   275,   275,   275,   275,   275,   278,   277
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
       4,     2,     4,     3,     6,     6,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     5,
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
       1,     3,     1,     2,     3,     3,     4,     5,     1,     3,
       2,     2,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       3,     1,     4,     1,     1,     1,     0,     3,     1,     1,
       2,     1,     2,     2,     3,     2,     2,     5,     5,     6,
       1,     2,     0,     6,     2,     2,     2,     8,     2,     2,
       2,     0,     5,     0,     6,     0,     6,     2,     2,     2,
       1,     1,     1,     2,     2,     2,     2,     1,     1,     1,
       8,     8,     8,    10,     2,     3,     4,     0,     7,     0,
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
#line 73 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2569 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 77 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2578 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 81 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2586 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 84 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2594 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 87 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2602 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 90 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2610 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 93 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2618 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 96 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2626 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 99 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2634 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 106 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2642 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 109 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2651 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 122 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2660 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 126 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2669 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 134 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2678 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 138 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 2687 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 145 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2695 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 150 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2703 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 153 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2711 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 156 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2719 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 159 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2727 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 162 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2735 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 165 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2743 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 168 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2751 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 173 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2759 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 178 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2768 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 182 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2777 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 186 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2786 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 190 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2795 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 194 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2804 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 198 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2813 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 202 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2822 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 206 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2831 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 210 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2840 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 214 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2849 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 218 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2858 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 222 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2867 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 226 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2876 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 230 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2885 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 234 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2894 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 238 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2903 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 242 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2912 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 246 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2921 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 250 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2930 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 254 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2939 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 258 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2948 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 262 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2957 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 266 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2966 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 270 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2975 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 274 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2984 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 278 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2993 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 282 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3002 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 288 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3011 "src-generated/ugbc.tab.c"
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
#line 3023 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 299 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3032 "src-generated/ugbc.tab.c"
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
#line 3044 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 310 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3052 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 313 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3060 "src-generated/ugbc.tab.c"
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
#line 3074 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 325 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3083 "src-generated/ugbc.tab.c"
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
#line 3095 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 336 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3104 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 340 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3113 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 344 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3122 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 348 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3131 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 352 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3140 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 356 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3149 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 360 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3158 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 364 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3167 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 368 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3175 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 371 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3183 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 374 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3191 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 377 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3199 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 380 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3207 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 383 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3215 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 386 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3223 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 389 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3231 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 392 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3239 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 395 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3247 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 398 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3255 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 401 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3263 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 404 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3271 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 407 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3279 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 410 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3287 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 413 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3295 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 416 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3303 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 419 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3311 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 422 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3319 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 425 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3327 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 428 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3335 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 431 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3343 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 434 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3351 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 437 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3359 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 440 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3367 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 443 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3375 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 446 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3383 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 449 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3391 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 452 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3399 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 455 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3407 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: SGN OP expr CP  */
#line 458 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3415 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: ABS OP expr CP  */
#line 461 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3423 "src-generated/ugbc.tab.c"
    break;

  case 108: /* exponential: TRUE  */
#line 464 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3432 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: FALSE  */
#line 468 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3441 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: COLORS  */
#line 472 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3450 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: WIDTH  */
#line 476 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3458 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: HEIGHT  */
#line 479 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3466 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: TIMER  */
#line 482 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3474 "src-generated/ugbc.tab.c"
    break;

  case 116: /* bank_definition_simple: AT direct_integer  */
#line 490 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3482 "src-generated/ugbc.tab.c"
    break;

  case 117: /* bank_definition_simple: Identifier AT direct_integer  */
#line 493 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3490 "src-generated/ugbc.tab.c"
    break;

  case 118: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 496 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3498 "src-generated/ugbc.tab.c"
    break;

  case 119: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 499 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3506 "src-generated/ugbc.tab.c"
    break;

  case 120: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 502 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3514 "src-generated/ugbc.tab.c"
    break;

  case 121: /* bank_definition_simple: DATA AT direct_integer  */
#line 505 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3522 "src-generated/ugbc.tab.c"
    break;

  case 122: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 509 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3530 "src-generated/ugbc.tab.c"
    break;

  case 123: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 512 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3538 "src-generated/ugbc.tab.c"
    break;

  case 124: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 515 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3546 "src-generated/ugbc.tab.c"
    break;

  case 125: /* bank_definition_simple: CODE AT direct_integer  */
#line 518 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3554 "src-generated/ugbc.tab.c"
    break;

  case 126: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 522 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3562 "src-generated/ugbc.tab.c"
    break;

  case 127: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 525 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3570 "src-generated/ugbc.tab.c"
    break;

  case 128: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 528 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3578 "src-generated/ugbc.tab.c"
    break;

  case 129: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 531 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3586 "src-generated/ugbc.tab.c"
    break;

  case 130: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 535 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3594 "src-generated/ugbc.tab.c"
    break;

  case 131: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 538 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3602 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 541 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3610 "src-generated/ugbc.tab.c"
    break;

  case 133: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 544 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3618 "src-generated/ugbc.tab.c"
    break;

  case 134: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 550 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3626 "src-generated/ugbc.tab.c"
    break;

  case 135: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 553 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3634 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 556 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3642 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 559 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3650 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 562 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3658 "src-generated/ugbc.tab.c"
    break;

  case 141: /* raster_definition_simple: Identifier AT direct_integer  */
#line 571 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3666 "src-generated/ugbc.tab.c"
    break;

  case 142: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 574 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3674 "src-generated/ugbc.tab.c"
    break;

  case 143: /* raster_definition_expression: Identifier AT expr  */
#line 579 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3682 "src-generated/ugbc.tab.c"
    break;

  case 144: /* raster_definition_expression: AT expr WITH Identifier  */
#line 582 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3690 "src-generated/ugbc.tab.c"
    break;

  case 147: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 591 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3698 "src-generated/ugbc.tab.c"
    break;

  case 148: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 594 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3706 "src-generated/ugbc.tab.c"
    break;

  case 149: /* next_raster_definition_expression: Identifier AT expr  */
#line 599 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3714 "src-generated/ugbc.tab.c"
    break;

  case 150: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 602 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3722 "src-generated/ugbc.tab.c"
    break;

  case 153: /* color_definition_simple: BORDER direct_integer  */
#line 611 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3730 "src-generated/ugbc.tab.c"
    break;

  case 154: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 614 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3738 "src-generated/ugbc.tab.c"
    break;

  case 155: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 617 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3746 "src-generated/ugbc.tab.c"
    break;

  case 156: /* color_definition_expression: BORDER expr  */
#line 622 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3754 "src-generated/ugbc.tab.c"
    break;

  case 157: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 625 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3762 "src-generated/ugbc.tab.c"
    break;

  case 158: /* color_definition_expression: SPRITE expr TO expr  */
#line 628 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3770 "src-generated/ugbc.tab.c"
    break;

  case 164: /* wait_definition_simple: direct_integer CYCLES  */
#line 642 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3778 "src-generated/ugbc.tab.c"
    break;

  case 165: /* wait_definition_simple: direct_integer TICKS  */
#line 645 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3786 "src-generated/ugbc.tab.c"
    break;

  case 166: /* wait_definition_simple: direct_integer milliseconds  */
#line 648 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3794 "src-generated/ugbc.tab.c"
    break;

  case 167: /* wait_definition_expression: expr CYCLES  */
#line 653 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3802 "src-generated/ugbc.tab.c"
    break;

  case 168: /* wait_definition_expression: expr TICKS  */
#line 656 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3810 "src-generated/ugbc.tab.c"
    break;

  case 169: /* wait_definition_expression: expr milliseconds  */
#line 659 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3818 "src-generated/ugbc.tab.c"
    break;

  case 172: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 669 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3826 "src-generated/ugbc.tab.c"
    break;

  case 173: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 672 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3834 "src-generated/ugbc.tab.c"
    break;

  case 174: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 675 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3842 "src-generated/ugbc.tab.c"
    break;

  case 175: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 678 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3850 "src-generated/ugbc.tab.c"
    break;

  case 176: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 681 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3858 "src-generated/ugbc.tab.c"
    break;

  case 177: /* sprite_definition_simple: direct_integer ENABLE  */
#line 684 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3866 "src-generated/ugbc.tab.c"
    break;

  case 178: /* sprite_definition_simple: direct_integer DISABLE  */
#line 687 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3874 "src-generated/ugbc.tab.c"
    break;

  case 179: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 690 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3882 "src-generated/ugbc.tab.c"
    break;

  case 180: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 693 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3890 "src-generated/ugbc.tab.c"
    break;

  case 181: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 696 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3898 "src-generated/ugbc.tab.c"
    break;

  case 182: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 699 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3906 "src-generated/ugbc.tab.c"
    break;

  case 183: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 702 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3914 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 705 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3922 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 708 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3930 "src-generated/ugbc.tab.c"
    break;

  case 186: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 711 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3938 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_expression: expr DATA FROM expr  */
#line 716 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3946 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_expression: expr MULTICOLOR  */
#line 719 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3954 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_expression: expr MONOCOLOR  */
#line 722 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3962 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_expression: expr COLOR expr  */
#line 725 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3970 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 728 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3978 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_expression: expr ENABLE  */
#line 731 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3986 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_expression: expr DISABLE  */
#line 734 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3994 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 737 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4002 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 740 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4010 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 743 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4018 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 746 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4026 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 749 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4034 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 752 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4042 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 755 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4050 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 758 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4058 "src-generated/ugbc.tab.c"
    break;

  case 204: /* bitmap_definition_simple: AT direct_integer  */
#line 767 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4066 "src-generated/ugbc.tab.c"
    break;

  case 205: /* bitmap_definition_simple: ENABLE  */
#line 770 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4074 "src-generated/ugbc.tab.c"
    break;

  case 206: /* bitmap_definition_simple: DISABLE  */
#line 773 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4082 "src-generated/ugbc.tab.c"
    break;

  case 207: /* bitmap_definition_simple: CLEAR  */
#line 776 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4090 "src-generated/ugbc.tab.c"
    break;

  case 208: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 779 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4098 "src-generated/ugbc.tab.c"
    break;

  case 209: /* bitmap_definition_expression: AT expr  */
#line 785 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4106 "src-generated/ugbc.tab.c"
    break;

  case 210: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 788 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4114 "src-generated/ugbc.tab.c"
    break;

  case 213: /* textmap_definition_simple: AT direct_integer  */
#line 798 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4122 "src-generated/ugbc.tab.c"
    break;

  case 214: /* textmap_definition_expression: AT expr  */
#line 803 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4130 "src-generated/ugbc.tab.c"
    break;

  case 217: /* text_definition_simple: ENABLE  */
#line 812 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4138 "src-generated/ugbc.tab.c"
    break;

  case 218: /* text_definition_simple: DISABLE  */
#line 815 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4146 "src-generated/ugbc.tab.c"
    break;

  case 219: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 820 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4154 "src-generated/ugbc.tab.c"
    break;

  case 220: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 823 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4162 "src-generated/ugbc.tab.c"
    break;

  case 223: /* tiles_definition_simple: AT direct_integer  */
#line 832 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4170 "src-generated/ugbc.tab.c"
    break;

  case 224: /* tiles_definition_expression: AT expr  */
#line 837 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4178 "src-generated/ugbc.tab.c"
    break;

  case 227: /* colormap_definition_simple: AT direct_integer  */
#line 846 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4186 "src-generated/ugbc.tab.c"
    break;

  case 228: /* colormap_definition_simple: CLEAR  */
#line 849 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4194 "src-generated/ugbc.tab.c"
    break;

  case 229: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 852 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4202 "src-generated/ugbc.tab.c"
    break;

  case 230: /* colormap_definition_expression: AT expr  */
#line 857 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4210 "src-generated/ugbc.tab.c"
    break;

  case 231: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 860 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4218 "src-generated/ugbc.tab.c"
    break;

  case 234: /* screen_definition_simple: ON  */
#line 870 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4226 "src-generated/ugbc.tab.c"
    break;

  case 235: /* screen_definition_simple: OFF  */
#line 873 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4234 "src-generated/ugbc.tab.c"
    break;

  case 236: /* screen_definition_simple: ROWS direct_integer  */
#line 876 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4242 "src-generated/ugbc.tab.c"
    break;

  case 237: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 879 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4250 "src-generated/ugbc.tab.c"
    break;

  case 238: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 882 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4258 "src-generated/ugbc.tab.c"
    break;

  case 239: /* screen_definition_expression: ROWS expr  */
#line 887 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4266 "src-generated/ugbc.tab.c"
    break;

  case 240: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 890 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4274 "src-generated/ugbc.tab.c"
    break;

  case 241: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 893 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4282 "src-generated/ugbc.tab.c"
    break;

  case 245: /* var_definition_simple: Identifier ON Identifier  */
#line 902 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4290 "src-generated/ugbc.tab.c"
    break;

  case 246: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 905 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4298 "src-generated/ugbc.tab.c"
    break;

  case 247: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 908 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4306 "src-generated/ugbc.tab.c"
    break;

  case 248: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 911 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4316 "src-generated/ugbc.tab.c"
    break;

  case 249: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 916 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4326 "src-generated/ugbc.tab.c"
    break;

  case 250: /* goto_definition: Identifier  */
#line 923 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4334 "src-generated/ugbc.tab.c"
    break;

  case 251: /* goto_definition: Integer  */
#line 926 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4342 "src-generated/ugbc.tab.c"
    break;

  case 252: /* gosub_definition: Identifier  */
#line 932 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4350 "src-generated/ugbc.tab.c"
    break;

  case 253: /* gosub_definition: Integer  */
#line 935 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4358 "src-generated/ugbc.tab.c"
    break;

  case 255: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 944 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4366 "src-generated/ugbc.tab.c"
    break;

  case 256: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 950 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4374 "src-generated/ugbc.tab.c"
    break;

  case 259: /* ink_definition: expr  */
#line 959 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4382 "src-generated/ugbc.tab.c"
    break;

  case 260: /* on_goto_definition: Identifier  */
#line 964 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4391 "src-generated/ugbc.tab.c"
    break;

  case 261: /* $@3: %empty  */
#line 968 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4399 "src-generated/ugbc.tab.c"
    break;

  case 263: /* on_gosub_definition: Identifier  */
#line 973 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4408 "src-generated/ugbc.tab.c"
    break;

  case 264: /* $@4: %empty  */
#line 977 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4416 "src-generated/ugbc.tab.c"
    break;

  case 266: /* on_proc_definition: Identifier  */
#line 982 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4425 "src-generated/ugbc.tab.c"
    break;

  case 267: /* $@5: %empty  */
#line 986 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4433 "src-generated/ugbc.tab.c"
    break;

  case 269: /* $@6: %empty  */
#line 991 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4441 "src-generated/ugbc.tab.c"
    break;

  case 271: /* $@7: %empty  */
#line 994 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4449 "src-generated/ugbc.tab.c"
    break;

  case 273: /* $@8: %empty  */
#line 997 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4457 "src-generated/ugbc.tab.c"
    break;

  case 275: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1002 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4465 "src-generated/ugbc.tab.c"
    break;

  case 276: /* every_definition: ON  */
#line 1005 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4473 "src-generated/ugbc.tab.c"
    break;

  case 277: /* every_definition: OFF  */
#line 1008 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4481 "src-generated/ugbc.tab.c"
    break;

  case 278: /* add_definition: Identifier COMMA expr  */
#line 1013 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4489 "src-generated/ugbc.tab.c"
    break;

  case 279: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1016 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4497 "src-generated/ugbc.tab.c"
    break;

  case 280: /* dimensions: Integer  */
#line 1022 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4506 "src-generated/ugbc.tab.c"
    break;

  case 281: /* dimensions: Integer COMMA dimensions  */
#line 1026 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4515 "src-generated/ugbc.tab.c"
    break;

  case 282: /* datatype: BYTE  */
#line 1033 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 4523 "src-generated/ugbc.tab.c"
    break;

  case 283: /* datatype: SIGNED BYTE  */
#line 1036 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 4531 "src-generated/ugbc.tab.c"
    break;

  case 284: /* datatype: WORD  */
#line 1039 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 4539 "src-generated/ugbc.tab.c"
    break;

  case 285: /* datatype: SIGNED WORD  */
#line 1042 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 4547 "src-generated/ugbc.tab.c"
    break;

  case 286: /* datatype: DWORD  */
#line 1045 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 4555 "src-generated/ugbc.tab.c"
    break;

  case 287: /* datatype: SIGNED DWORD  */
#line 1048 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 4563 "src-generated/ugbc.tab.c"
    break;

  case 288: /* datatype: ADDRESS  */
#line 1051 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 4571 "src-generated/ugbc.tab.c"
    break;

  case 289: /* datatype: POSITION  */
#line 1054 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 4579 "src-generated/ugbc.tab.c"
    break;

  case 290: /* datatype: COLOR  */
#line 1057 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 4587 "src-generated/ugbc.tab.c"
    break;

  case 291: /* datatype: STRING  */
#line 1060 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 4595 "src-generated/ugbc.tab.c"
    break;

  case 292: /* $@9: %empty  */
#line 1065 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4604 "src-generated/ugbc.tab.c"
    break;

  case 293: /* dim_definition: Identifier $@9 OP dimensions CP  */
#line 1068 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 4614 "src-generated/ugbc.tab.c"
    break;

  case 294: /* $@10: %empty  */
#line 1073 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4623 "src-generated/ugbc.tab.c"
    break;

  case 295: /* dim_definition: Identifier $@10 DOLLAR OP dimensions CP  */
#line 1076 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 4633 "src-generated/ugbc.tab.c"
    break;

  case 296: /* $@11: %empty  */
#line 1081 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4642 "src-generated/ugbc.tab.c"
    break;

  case 297: /* dim_definition: Identifier datatype $@11 OP dimensions CP  */
#line 1084 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 4652 "src-generated/ugbc.tab.c"
    break;

  case 300: /* indexes: expr  */
#line 1097 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = (yyvsp[0].string);
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4661 "src-generated/ugbc.tab.c"
    break;

  case 301: /* indexes: expr COMMA indexes  */
#line 1101 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = (yyvsp[-2].string);
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4670 "src-generated/ugbc.tab.c"
    break;

  case 302: /* parameters: Identifier  */
#line 1108 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].string);
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4680 "src-generated/ugbc.tab.c"
    break;

  case 303: /* parameters: Identifier DOLLAR  */
#line 1113 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-1].string);
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4690 "src-generated/ugbc.tab.c"
    break;

  case 304: /* parameters: Identifier AS datatype  */
#line 1118 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].string);
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4700 "src-generated/ugbc.tab.c"
    break;

  case 305: /* parameters: Identifier COMMA parameters  */
#line 1123 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].string);
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4710 "src-generated/ugbc.tab.c"
    break;

  case 306: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1128 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-3].string);
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4720 "src-generated/ugbc.tab.c"
    break;

  case 307: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1133 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-4].string);
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4730 "src-generated/ugbc.tab.c"
    break;

  case 308: /* values: expr  */
#line 1141 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].string);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4739 "src-generated/ugbc.tab.c"
    break;

  case 309: /* values: expr COMMA values  */
#line 1145 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].string);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4748 "src-generated/ugbc.tab.c"
    break;

  case 326: /* statement: INC Identifier  */
#line 1168 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 4756 "src-generated/ugbc.tab.c"
    break;

  case 327: /* statement: DEC Identifier  */
#line 1171 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 4764 "src-generated/ugbc.tab.c"
    break;

  case 328: /* statement: RANDOMIZE  */
#line 1174 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 4772 "src-generated/ugbc.tab.c"
    break;

  case 329: /* statement: RANDOMIZE expr  */
#line 1177 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 4780 "src-generated/ugbc.tab.c"
    break;

  case 330: /* statement: IF expr THEN  */
#line 1180 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4788 "src-generated/ugbc.tab.c"
    break;

  case 331: /* statement: ELSE  */
#line 1183 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 4796 "src-generated/ugbc.tab.c"
    break;

  case 332: /* statement: ELSE IF expr THEN  */
#line 1186 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4804 "src-generated/ugbc.tab.c"
    break;

  case 333: /* statement: ENDIF  */
#line 1189 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 4812 "src-generated/ugbc.tab.c"
    break;

  case 334: /* statement: DO  */
#line 1192 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 4820 "src-generated/ugbc.tab.c"
    break;

  case 335: /* statement: LOOP  */
#line 1195 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 4828 "src-generated/ugbc.tab.c"
    break;

  case 336: /* $@12: %empty  */
#line 1198 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 4836 "src-generated/ugbc.tab.c"
    break;

  case 337: /* statement: WHILE $@12 expr  */
#line 1200 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 4844 "src-generated/ugbc.tab.c"
    break;

  case 338: /* statement: WEND  */
#line 1203 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 4852 "src-generated/ugbc.tab.c"
    break;

  case 339: /* statement: REPEAT  */
#line 1206 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 4860 "src-generated/ugbc.tab.c"
    break;

  case 340: /* statement: UNTIL expr  */
#line 1209 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 4868 "src-generated/ugbc.tab.c"
    break;

  case 341: /* statement: EXIT  */
#line 1212 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 4876 "src-generated/ugbc.tab.c"
    break;

  case 342: /* statement: EXIT PROC  */
#line 1215 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 4884 "src-generated/ugbc.tab.c"
    break;

  case 343: /* statement: POP PROC  */
#line 1218 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 4892 "src-generated/ugbc.tab.c"
    break;

  case 344: /* statement: EXIT IF expr  */
#line 1221 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 4900 "src-generated/ugbc.tab.c"
    break;

  case 345: /* statement: EXIT Integer  */
#line 1224 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4908 "src-generated/ugbc.tab.c"
    break;

  case 346: /* statement: EXIT direct_integer  */
#line 1227 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4916 "src-generated/ugbc.tab.c"
    break;

  case 347: /* statement: EXIT IF expr COMMA Integer  */
#line 1230 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4924 "src-generated/ugbc.tab.c"
    break;

  case 348: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1233 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4932 "src-generated/ugbc.tab.c"
    break;

  case 349: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1236 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4940 "src-generated/ugbc.tab.c"
    break;

  case 350: /* statement: NEXT  */
#line 1239 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 4948 "src-generated/ugbc.tab.c"
    break;

  case 351: /* statement: PROCEDURE Identifier  */
#line 1242 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 4957 "src-generated/ugbc.tab.c"
    break;

  case 352: /* $@13: %empty  */
#line 1246 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 4965 "src-generated/ugbc.tab.c"
    break;

  case 353: /* statement: PROCEDURE Identifier $@13 OSP parameters CSP  */
#line 1248 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 4973 "src-generated/ugbc.tab.c"
    break;

  case 354: /* statement: SHARED parameters  */
#line 1251 "src/ugbc.y"
                      {
      shared( _environment );
  }
#line 4981 "src-generated/ugbc.tab.c"
    break;

  case 355: /* statement: GLOBAL parameters  */
#line 1254 "src/ugbc.y"
                      {
      global( _environment );
  }
#line 4989 "src-generated/ugbc.tab.c"
    break;

  case 356: /* statement: END PROC  */
#line 1257 "src/ugbc.y"
             {
      end_procedure( _environment );
  }
#line 4997 "src-generated/ugbc.tab.c"
    break;

  case 357: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1260 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5005 "src-generated/ugbc.tab.c"
    break;

  case 358: /* statement: Identifier " "  */
#line 1263 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5014 "src-generated/ugbc.tab.c"
    break;

  case 359: /* statement: PROC Identifier  */
#line 1267 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5023 "src-generated/ugbc.tab.c"
    break;

  case 360: /* statement: CALL Identifier  */
#line 1271 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5032 "src-generated/ugbc.tab.c"
    break;

  case 361: /* $@14: %empty  */
#line 1275 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5040 "src-generated/ugbc.tab.c"
    break;

  case 362: /* statement: Identifier OSP $@14 values CSP  */
#line 1277 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5048 "src-generated/ugbc.tab.c"
    break;

  case 363: /* $@15: %empty  */
#line 1280 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5056 "src-generated/ugbc.tab.c"
    break;

  case 364: /* statement: PROC Identifier OSP $@15 values CSP  */
#line 1282 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5064 "src-generated/ugbc.tab.c"
    break;

  case 365: /* $@16: %empty  */
#line 1285 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5072 "src-generated/ugbc.tab.c"
    break;

  case 366: /* statement: CALL Identifier OSP $@16 values CSP  */
#line 1287 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5080 "src-generated/ugbc.tab.c"
    break;

  case 367: /* statement: Identifier COLON  */
#line 1290 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 5088 "src-generated/ugbc.tab.c"
    break;

  case 368: /* statement: BEG GAMELOOP  */
#line 1293 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 5096 "src-generated/ugbc.tab.c"
    break;

  case 369: /* statement: END GAMELOOP  */
#line 1296 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 5104 "src-generated/ugbc.tab.c"
    break;

  case 370: /* statement: GRAPHIC  */
#line 1299 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 5112 "src-generated/ugbc.tab.c"
    break;

  case 371: /* statement: HALT  */
#line 1302 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 5120 "src-generated/ugbc.tab.c"
    break;

  case 372: /* statement: END  */
#line 1305 "src/ugbc.y"
        {
      end( _environment );
  }
#line 5128 "src-generated/ugbc.tab.c"
    break;

  case 377: /* statement: RETURN  */
#line 1312 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 5136 "src-generated/ugbc.tab.c"
    break;

  case 378: /* statement: POP  */
#line 1315 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 5144 "src-generated/ugbc.tab.c"
    break;

  case 379: /* statement: DONE  */
#line 1318 "src/ugbc.y"
          {
      return 0;
  }
#line 5152 "src-generated/ugbc.tab.c"
    break;

  case 380: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1321 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5160 "src-generated/ugbc.tab.c"
    break;

  case 381: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1324 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5168 "src-generated/ugbc.tab.c"
    break;

  case 382: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1327 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 5176 "src-generated/ugbc.tab.c"
    break;

  case 383: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1330 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5184 "src-generated/ugbc.tab.c"
    break;

  case 385: /* statement: Identifier ASSIGN expr  */
#line 1334 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 5198 "src-generated/ugbc.tab.c"
    break;

  case 386: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1343 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 5212 "src-generated/ugbc.tab.c"
    break;

  case 387: /* $@17: %empty  */
#line 1352 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5221 "src-generated/ugbc.tab.c"
    break;

  case 388: /* statement: Identifier $@17 OP indexes CP ASSIGN expr  */
#line 1356 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 5234 "src-generated/ugbc.tab.c"
    break;

  case 389: /* $@18: %empty  */
#line 1364 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5243 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: Identifier DOLLAR $@18 OP indexes CP ASSIGN expr  */
#line 1367 "src/ugbc.y"
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
#line 5262 "src-generated/ugbc.tab.c"
    break;

  case 391: /* $@19: %empty  */
#line 1381 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5271 "src-generated/ugbc.tab.c"
    break;

  case 392: /* statement: Identifier $@19 datatype OP indexes CP ASSIGN expr  */
#line 1384 "src/ugbc.y"
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
#line 5290 "src-generated/ugbc.tab.c"
    break;

  case 393: /* statement: DEBUG expr  */
#line 1398 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 5298 "src-generated/ugbc.tab.c"
    break;

  case 396: /* statements_no_linenumbers: statement  */
#line 1406 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 5304 "src-generated/ugbc.tab.c"
    break;

  case 397: /* $@20: %empty  */
#line 1407 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 5310 "src-generated/ugbc.tab.c"
    break;

  case 399: /* $@21: %empty  */
#line 1411 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 5318 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statements_with_linenumbers: Integer $@21 statements_no_linenumbers  */
#line 1413 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 5326 "src-generated/ugbc.tab.c"
    break;

  case 401: /* $@22: %empty  */
#line 1418 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 5334 "src-generated/ugbc.tab.c"
    break;

  case 407: /* $@23: %empty  */
#line 1428 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 5340 "src-generated/ugbc.tab.c"
    break;


#line 5344 "src-generated/ugbc.tab.c"

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

#line 1430 "src/ugbc.y"


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

