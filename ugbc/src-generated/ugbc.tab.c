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
  YYSYMBOL_MILLISECOND = 149,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 150,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 151,                    /* TICKS  */
  YYSYMBOL_BLACK = 152,                    /* BLACK  */
  YYSYMBOL_WHITE = 153,                    /* WHITE  */
  YYSYMBOL_RED = 154,                      /* RED  */
  YYSYMBOL_CYAN = 155,                     /* CYAN  */
  YYSYMBOL_VIOLET = 156,                   /* VIOLET  */
  YYSYMBOL_GREEN = 157,                    /* GREEN  */
  YYSYMBOL_BLUE = 158,                     /* BLUE  */
  YYSYMBOL_YELLOW = 159,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 160,                   /* ORANGE  */
  YYSYMBOL_BROWN = 161,                    /* BROWN  */
  YYSYMBOL_LIGHT = 162,                    /* LIGHT  */
  YYSYMBOL_DARK = 163,                     /* DARK  */
  YYSYMBOL_GREY = 164,                     /* GREY  */
  YYSYMBOL_GRAY = 165,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 166,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 167,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 168,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 169,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 170,                /* TURQUOISE  */
  YYSYMBOL_TAN = 171,                      /* TAN  */
  YYSYMBOL_PINK = 172,                     /* PINK  */
  YYSYMBOL_PEACH = 173,                    /* PEACH  */
  YYSYMBOL_OLIVE = 174,                    /* OLIVE  */
  YYSYMBOL_Identifier = 175,               /* Identifier  */
  YYSYMBOL_String = 176,                   /* String  */
  YYSYMBOL_Integer = 177,                  /* Integer  */
  YYSYMBOL_178_ = 178,                     /* " "  */
  YYSYMBOL_YYACCEPT = 179,                 /* $accept  */
  YYSYMBOL_expr = 180,                     /* expr  */
  YYSYMBOL_expr_math = 181,                /* expr_math  */
  YYSYMBOL_term = 182,                     /* term  */
  YYSYMBOL_modula = 183,                   /* modula  */
  YYSYMBOL_factor = 184,                   /* factor  */
  YYSYMBOL_direct_integer = 185,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 186, /* random_definition_simple  */
  YYSYMBOL_random_definition = 187,        /* random_definition  */
  YYSYMBOL_color_enumeration = 188,        /* color_enumeration  */
  YYSYMBOL_exponential = 189,              /* exponential  */
  YYSYMBOL_190_1 = 190,                    /* $@1  */
  YYSYMBOL_191_2 = 191,                    /* $@2  */
  YYSYMBOL_position = 192,                 /* position  */
  YYSYMBOL_bank_definition_simple = 193,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 194, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 195,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 196, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 197, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 198,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 199, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 200, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 201,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 202,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 203, /* color_definition_expression  */
  YYSYMBOL_color_definition = 204,         /* color_definition  */
  YYSYMBOL_milliseconds = 205,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 206,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 207, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 208,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 209, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 210, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 211,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 212, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 213, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 214,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 215, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 216, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 217,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 218,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 219, /* text_definition_expression  */
  YYSYMBOL_text_definition = 220,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 221,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 222, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 223,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 224, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 225, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 226,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 227, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 228, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 229,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 230,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 231,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 232,         /* gosub_definition  */
  YYSYMBOL_var_definition = 233,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 234,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 235, /* point_definition_expression  */
  YYSYMBOL_point_definition = 236,         /* point_definition  */
  YYSYMBOL_ink_definition = 237,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 238,       /* on_goto_definition  */
  YYSYMBOL_239_3 = 239,                    /* $@3  */
  YYSYMBOL_on_gosub_definition = 240,      /* on_gosub_definition  */
  YYSYMBOL_241_4 = 241,                    /* $@4  */
  YYSYMBOL_on_proc_definition = 242,       /* on_proc_definition  */
  YYSYMBOL_243_5 = 243,                    /* $@5  */
  YYSYMBOL_on_definition = 244,            /* on_definition  */
  YYSYMBOL_245_6 = 245,                    /* $@6  */
  YYSYMBOL_246_7 = 246,                    /* $@7  */
  YYSYMBOL_247_8 = 247,                    /* $@8  */
  YYSYMBOL_every_definition = 248,         /* every_definition  */
  YYSYMBOL_add_definition = 249,           /* add_definition  */
  YYSYMBOL_dimensions = 250,               /* dimensions  */
  YYSYMBOL_datatype = 251,                 /* datatype  */
  YYSYMBOL_dim_definition = 252,           /* dim_definition  */
  YYSYMBOL_253_9 = 253,                    /* $@9  */
  YYSYMBOL_254_10 = 254,                   /* $@10  */
  YYSYMBOL_255_11 = 255,                   /* $@11  */
  YYSYMBOL_dim_definitions = 256,          /* dim_definitions  */
  YYSYMBOL_indexes = 257,                  /* indexes  */
  YYSYMBOL_parameters = 258,               /* parameters  */
  YYSYMBOL_values = 259,                   /* values  */
  YYSYMBOL_statement = 260,                /* statement  */
  YYSYMBOL_261_12 = 261,                   /* $@12  */
  YYSYMBOL_262_13 = 262,                   /* $@13  */
  YYSYMBOL_263_14 = 263,                   /* $@14  */
  YYSYMBOL_264_15 = 264,                   /* $@15  */
  YYSYMBOL_265_16 = 265,                   /* $@16  */
  YYSYMBOL_266_17 = 266,                   /* $@17  */
  YYSYMBOL_267_18 = 267,                   /* $@18  */
  YYSYMBOL_268_19 = 268,                   /* $@19  */
  YYSYMBOL_statements_no_linenumbers = 269, /* statements_no_linenumbers  */
  YYSYMBOL_270_20 = 270,                   /* $@20  */
  YYSYMBOL_statements_with_linenumbers = 271, /* statements_with_linenumbers  */
  YYSYMBOL_272_21 = 272,                   /* $@21  */
  YYSYMBOL_statements_complex = 273,       /* statements_complex  */
  YYSYMBOL_274_22 = 274,                   /* $@22  */
  YYSYMBOL_program = 275,                  /* program  */
  YYSYMBOL_276_23 = 276                    /* $@23  */
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
#define YYLAST   2060

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  179
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  98
/* YYNRULES -- Number of rules.  */
#define YYNRULES  406
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  790

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   433


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
     175,   176,   177,   178
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    73,    73,    74,    78,    82,    85,    88,    91,    94,
      97,   100,   106,   107,   110,   117,   118,   122,   123,   127,
     134,   135,   139,   146,   151,   154,   157,   160,   163,   166,
     169,   174,   179,   183,   187,   191,   195,   199,   203,   207,
     211,   215,   219,   223,   227,   231,   235,   239,   243,   247,
     251,   255,   259,   263,   267,   271,   275,   279,   283,   289,
     289,   300,   300,   311,   314,   317,   326,   330,   337,   341,
     345,   349,   353,   357,   361,   365,   369,   372,   375,   378,
     381,   384,   387,   390,   393,   396,   399,   402,   405,   408,
     411,   414,   417,   420,   423,   426,   429,   432,   435,   438,
     441,   444,   447,   450,   453,   456,   459,   462,   465,   469,
     473,   477,   480,   483,   488,   488,   491,   494,   497,   500,
     503,   506,   510,   513,   516,   519,   523,   526,   529,   532,
     536,   539,   542,   545,   551,   554,   557,   560,   563,   568,
     569,   572,   575,   580,   583,   588,   589,   592,   595,   600,
     603,   608,   609,   612,   615,   618,   623,   626,   629,   634,
     635,   638,   639,   640,   643,   646,   649,   654,   657,   660,
     666,   667,   670,   673,   676,   679,   682,   685,   688,   691,
     694,   697,   700,   703,   706,   709,   712,   717,   720,   723,
     726,   729,   732,   735,   738,   741,   744,   747,   750,   753,
     756,   759,   764,   765,   768,   771,   774,   777,   780,   786,
     789,   795,   796,   799,   804,   809,   810,   813,   816,   821,
     824,   829,   830,   833,   838,   843,   844,   847,   850,   853,
     858,   861,   867,   868,   871,   874,   877,   880,   883,   888,
     891,   894,   899,   900,   902,   903,   906,   909,   912,   917,
     924,   927,   933,   936,   942,   945,   951,   956,   957,   960,
     965,   969,   969,   974,   978,   978,   983,   987,   987,   992,
     992,   995,   995,   998,   998,  1003,  1006,  1009,  1014,  1017,
    1023,  1027,  1034,  1037,  1040,  1043,  1046,  1049,  1052,  1055,
    1058,  1061,  1066,  1066,  1074,  1074,  1082,  1082,  1093,  1094,
    1098,  1102,  1109,  1114,  1119,  1124,  1129,  1134,  1142,  1146,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,  1169,  1172,  1175,  1178,
    1181,  1184,  1187,  1190,  1193,  1196,  1199,  1199,  1204,  1207,
    1210,  1213,  1216,  1219,  1222,  1225,  1228,  1231,  1234,  1237,
    1240,  1243,  1247,  1247,  1252,  1255,  1258,  1262,  1266,  1270,
    1270,  1275,  1275,  1280,  1280,  1285,  1288,  1291,  1294,  1297,
    1300,  1303,  1304,  1305,  1306,  1307,  1310,  1313,  1316,  1319,
    1322,  1325,  1328,  1329,  1338,  1347,  1347,  1359,  1359,  1376,
    1376,  1393,  1396,  1397,  1401,  1402,  1402,  1406,  1406,  1413,
    1413,  1416,  1417,  1418,  1419,  1423,  1423
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
  "OSP", "CSP", "MILLISECOND", "MILLISECONDS", "TICKS", "BLACK", "WHITE",
  "RED", "CYAN", "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE", "BROWN",
  "LIGHT", "DARK", "GREY", "GRAY", "MAGENTA", "PURPLE", "LAVENDER", "GOLD",
  "TURQUOISE", "TAN", "PINK", "PEACH", "OLIVE", "Identifier", "String",
  "Integer", "\" \"", "$accept", "expr", "expr_math", "term", "modula",
  "factor", "direct_integer", "random_definition_simple",
  "random_definition", "color_enumeration", "exponential", "$@1", "$@2",
  "position", "bank_definition_simple", "bank_definition_with_payload",
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
     425,   426,   427,   428,   429,   430,   431,   432,   433
};
#endif

#define YYPACT_NINF (-649)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-386)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -649,    50,   738,  -649,  -649,  -120,  -113,   -18,  -649,    71,
    1415,    52,     5,  1415,  -649,    42,   158,  1571,   -87,  -100,
    -649,  -649,  -649,  1103,   125,    17,  1571,    45,   -46,  -649,
      78,   107,  1571,  1571,  -649,   130,   147,     9,  -649,    35,
     129,  -649,   -54,  -649,  1571,    31,  1259,   170,    60,  1571,
      70,    74,    84,    85,     4,  -649,   209,   216,   221,  -649,
    -649,  -649,  1415,   203,  -649,  -649,  -649,  1415,  1415,  1415,
    -649,  -649,  -649,    76,   947,  -649,  -649,   230,   231,   232,
     133,    92,  -649,  -649,   234,   236,  1571,  -649,  -649,   237,
     238,   239,   242,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   272,   273,   274,   275,  -649,  -649,   276,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,   154,  -649,  -649,    72,
     -71,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
     156,    47,  -649,  -649,   -32,    91,   184,   172,   189,   -19,
    -649,  -649,  -649,  -649,  -649,   -15,   240,   -13,    -6,     1,
       3,   295,  -649,  -649,  -649,   280,   323,  -649,  -649,  -649,
    1415,  -649,  -649,   291,  -649,  -649,  -649,  -649,  -649,  1415,
     277,   278,  -649,  -649,  -649,   -22,  -649,    29,  -649,  -649,
    -649,  -649,  -649,  1571,  1571,  -649,  -649,   314,  -649,  -649,
    -649,  1415,  -649,  -649,  -649,  1415,   297,  -649,  -649,  -649,
     258,  -649,  -649,  -649,  1571,  1571,  -649,  -649,  1415,  -649,
    -649,  -649,   299,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    1571,  1571,  -649,  -649,  -649,  -649,   316,  -649,  -649,   187,
    -649,  1571,   328,  -649,  -649,  -649,    10,   332,  -649,   193,
     194,   196,  -649,  -649,  1571,   329,  -649,  -649,   315,    40,
     863,  -649,   738,   738,   321,   322,  1415,  -649,  -649,   281,
     282,   285,   286,  -649,   317,   326,   327,   330,   331,   139,
     335,  1415,  1415,  1415,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  1571,  1571,  -649,  1571,  1571,  1571,
    1571,  1571,  1571,  1571,  1571,  1571,  1571,  1571,  1571,  1571,
    1571,  1571,  1571,  1571,  1727,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,   333,   337,  -649,  -649,  -649,  -649,  -649,
    -649,  1727,  1727,  1727,  1727,  1727,  1727,  1727,  1727,  1727,
    1727,  1727,  1727,  1727,  1883,  -649,  -649,  -649,  1415,   339,
    -649,  -649,  -649,   334,   240,   340,   240,   350,   240,   351,
     240,   352,   240,  -649,  1571,   345,  -649,  -649,   111,   175,
     102,   110,  -649,  -649,  -649,   349,   240,   354,  -649,  -649,
     191,   195,   116,   145,  -649,  -649,   356,  -649,  -649,  1415,
    -649,  -649,  1415,  1415,  -649,  -649,  -649,   342,   210,  -649,
     384,  1571,  -649,  -649,  -649,  -649,  1415,  -649,   386,   387,
    -649,  -649,  1415,   341,   389,  1571,   298,   394,  1571,  -649,
    -649,  -649,  -649,  -649,  -649,   148,  -649,  -649,   368,   388,
      70,  -649,   257,  -649,   738,  -649,  1571,   372,  1571,  1571,
     378,    -1,  -649,   863,  -649,  -649,   244,   245,  -649,  -649,
    1571,   240,  1571,   240,   246,   249,   250,   251,   252,   379,
     380,   382,  -649,   396,   398,   399,   400,   401,   402,   406,
     414,   415,   417,   404,   405,   408,   409,   438,   411,   412,
     413,   416,   418,   442,   443,   419,   421,   422,    19,   424,
    1571,   184,   184,   247,   247,   247,   247,   247,   247,   247,
     247,   172,   189,   189,  -649,   423,   430,  1415,    14,  -649,
     240,  -649,   240,  -649,   240,  -649,   240,    22,  -649,  1571,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  1571,  -649,
     240,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,   240,
    -649,  -649,  -649,  -649,  -649,  -649,   287,   288,   289,   290,
     447,  1571,   459,   425,   426,  1571,  1571,   462,   463,  -649,
     -39,   403,   301,  1571,   465,  -649,  -649,  -649,   439,   300,
     440,  -649,  1571,   303,  1571,  -649,  -649,  1571,   472,   336,
     473,   446,  1571,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,   305,   306,   308,  -649,  -649,
    -649,  -649,  -649,  -649,  1571,  1571,  1571,  1571,  -649,  -649,
    -649,  -649,  1571,  -649,  -649,  -649,  -649,  -649,  1571,  1571,
    -649,  -649,  -649,  1883,  1571,   451,   313,   318,  -649,  -649,
    -649,  -649,  -649,  -649,   460,  -649,   461,  -649,   319,    88,
    -649,   484,  -649,   485,   487,  -649,   489,  -649,   490,  -649,
     488,  1415,   491,  1571,  1571,   240,   468,   469,  1571,   240,
    -649,  -649,  1571,  -649,    61,  1571,   300,   498,   471,   300,
     359,    25,   361,   362,   476,  1571,  -649,  1571,   499,   478,
    -649,  -649,  -649,   479,   480,   117,   137,   481,   482,   483,
     486,   492,  -649,  -649,  -649,   343,   344,  -649,   493,  -649,
     494,  -649,  1571,   240,   517,   518,   519,  1571,  -649,  -649,
    1571,  -649,  -649,  -649,   515,   516,   495,   497,   427,  1571,
     520,   466,   502,   300,  -649,   504,  -649,   303,   527,    40,
    -649,  -649,   528,  -649,  -649,  1571,   531,  -649,  -649,  1571,
    -649,  1571,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
     364,   369,   511,   512,   287,   288,   289,  -649,  -649,  1571,
    1571,  -649,  -649,  1571,   513,  1571,  1571,  -649,  -649,  -649,
    -649,   303,   542,  1571,  -649,  1571,   522,   523,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,   537,  -649,
    -649,  -649,   303,  -649,  -649,  -649,  -649,  1571,  -649,  -649
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     405,     0,   393,     1,   392,     0,     0,     0,   377,     0,
       0,   350,     0,     0,   369,     0,     0,     0,   244,     0,
     335,   339,   336,     0,     0,     0,     0,     0,   370,   333,
       0,     0,     0,   328,   368,     0,     0,     0,   375,   376,
     331,   334,   341,   338,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   389,   397,   394,   401,   403,   406,
     326,   327,     0,     0,   145,   146,   311,     0,     0,     0,
     159,   160,   313,     0,     0,    79,    80,     0,     0,     0,
       0,     0,   111,   112,     0,     0,     0,   108,   109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   113,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,    44,    49,    50,    51,    52,    53,    54,    57,    58,
       0,    63,    67,    65,     0,     2,    12,    15,    17,     0,
      76,    20,   170,   171,   314,     0,     0,     0,     0,     0,
       0,     0,   139,   140,   310,     0,     0,   202,   203,   315,
       0,   205,   206,   207,   211,   212,   316,   234,   235,     0,
       0,     0,   242,   243,   321,     0,   371,     0,   254,   324,
     250,   251,   372,     0,     0,   217,   218,     0,   221,   222,
     318,     0,   225,   226,   319,     0,   228,   232,   233,   320,
       0,   366,   367,   354,     0,     0,   391,   329,     0,   215,
     216,   317,     0,   257,   258,   322,   252,   253,   373,   343,
       0,     0,   342,   345,   346,   340,     0,   276,   277,     0,
     374,     0,     0,   325,   259,   323,   292,   298,   382,   357,
     351,   358,   399,   365,     0,   387,   359,   356,     0,     0,
     393,   395,   393,   393,     0,     0,     0,   156,   153,     0,
       0,     0,     0,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    24,    25,    27,    29,    30,
      26,    31,   101,    23,     0,     0,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    42,    45,    46,    47,
      48,    43,    56,    64,     0,   161,   167,   162,   163,   168,
     169,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   164,   165,   166,     0,     0,
     151,   152,   312,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,     0,     0,   192,   193,     0,     0,
       0,     0,   189,   188,   114,     0,     0,     0,   177,   178,
       0,     0,     0,     0,   174,   173,     0,   209,   204,     0,
     239,   236,     0,     0,   269,   273,   271,     0,     0,   337,
       0,     0,   224,   223,   230,   227,     0,   330,     0,     0,
     214,   213,     0,     0,   344,     0,     0,     0,     0,   290,
     282,   284,   289,   286,   291,     0,   288,   296,     0,     0,
       0,   361,     0,   363,   393,   383,     0,     0,     0,     0,
       0,   389,   398,   393,   402,   404,     0,     0,   143,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,     5,     7,     8,     9,    10,     6,     3,
       4,    16,    18,    19,    21,     0,     0,     0,     0,   121,
       0,   133,     0,   125,     0,   129,     0,   117,   190,     0,
     197,   196,   201,   200,   195,   199,   194,   198,     0,   175,
       0,   182,   181,   186,   185,   180,   184,   179,   183,     0,
     210,   208,   240,   237,   241,   238,     0,     0,     0,     0,
     245,     0,     0,     0,     0,     0,     0,     0,     0,   332,
       0,     0,     0,     0,   278,   283,   285,   287,     0,     0,
       0,   299,     0,     0,     0,   400,   384,     0,   308,     0,
     300,     0,     0,   396,   144,   142,   158,   155,   157,   154,
      75,    68,    70,    74,    72,     0,     0,     0,    78,    77,
      82,    81,    84,    83,     0,     0,     0,     0,    91,    92,
      93,   100,     0,    94,    95,    96,    97,    98,     0,     0,
     106,   107,   102,     0,     0,     0,     0,     0,   149,   147,
     118,   131,   123,   126,   120,   132,   124,   128,     0,     0,
     187,     0,   172,     0,   260,   270,   263,   274,   266,   272,
     246,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     347,   348,     0,   275,     0,     0,     0,   280,     0,     0,
       0,   302,     0,     0,     0,     0,   360,     0,     0,     0,
      69,    71,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,   150,   148,     0,     0,   134,   119,   130,
     122,   127,     0,     0,     0,     0,     0,     0,   248,   247,
       0,   220,   231,   229,     0,     0,     0,     0,   349,     0,
       0,     0,     0,     0,   293,     0,   362,     0,   303,     0,
     353,   364,     0,   309,   301,     0,     0,    85,    86,     0,
      87,     0,    89,    99,   105,   104,    22,    62,   136,   138,
       0,     0,     0,     0,     0,     0,     0,   249,   219,     0,
       0,   256,   255,     0,     0,     0,     0,   297,   281,   295,
     305,     0,   304,     0,   386,     0,     0,     0,   135,   137,
     191,   176,   262,   265,   268,   378,   379,   355,     0,   380,
     279,   306,     0,   388,   390,    88,    90,     0,   307,   381
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -649,   -10,   -86,   -64,   220,  -193,    59,  -649,  -649,  -649,
    -319,  -649,  -649,   397,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,   428,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -189,
    -649,  -185,  -649,  -184,  -649,  -649,  -649,  -649,  -649,  -649,
    -649,  -603,  -248,  -649,  -649,  -649,  -649,   144,  -478,  -648,
    -522,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,  -649,
    -246,  -649,  -649,  -649,  -232,  -649,  -649,  -649
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   570,   135,   136,   137,   138,   139,   281,   282,   140,
     141,   314,   479,   365,   152,   153,   154,    64,    65,    66,
     340,   341,   342,    70,    71,    72,   320,   142,   143,   144,
     157,   158,   159,   164,   165,   166,   209,   210,   211,   188,
     189,   190,   192,   193,   194,   197,   198,   199,   172,   173,
     174,   178,   182,   218,   179,   213,   214,   215,   235,   635,
     694,   637,   695,   639,   696,   176,   536,   538,   537,   230,
     233,   658,   417,   237,   418,   419,   558,   238,   571,   662,
     569,    56,   183,   422,   428,   562,   564,   248,   427,   249,
      57,   433,    58,   250,    59,   424,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     134,   430,   615,   155,   432,   243,    62,   175,   242,   338,
     243,   344,   244,   187,   221,   494,   200,   244,   346,   245,
     434,   435,   206,   207,   245,   348,   613,   350,    81,   146,
    -294,   384,   717,  -385,   225,   409,   229,   147,  -385,   234,
     660,   195,   663,    81,   202,   718,   620,   315,   316,   387,
       3,   628,   254,   712,   148,    60,   715,   257,   259,   261,
     315,   335,    61,   621,   270,   409,   160,   313,   709,   760,
     629,   388,   156,   719,   145,   180,   286,   181,   161,   162,
     385,   -59,   149,   150,   410,   411,   412,   310,   177,   664,
     222,   622,   623,   311,   669,   413,   710,    67,   203,   321,
     322,   224,    68,   323,   196,   324,   325,   326,   327,   328,
     758,   478,   204,   781,   410,   411,   412,   317,   318,   319,
     688,   255,   386,   223,   729,   413,   258,   260,   262,   163,
     317,   318,   336,   414,   788,   201,   681,   689,   650,   492,
     493,   205,    69,   723,   731,   415,   246,   514,   334,   191,
     377,   246,   730,   416,   208,   516,   515,    63,   274,   380,
     339,   525,   345,   414,   517,   690,   691,   510,   511,   347,
     526,   212,   732,   389,   390,   415,   349,   247,   351,   219,
     151,   392,   247,   416,   216,   394,   217,   573,   329,   724,
     527,   332,   565,   333,   398,   399,   330,   220,   400,   528,
     167,   168,   169,   170,   231,   343,   226,   275,   276,   277,
     403,   404,   171,   449,   450,   251,   278,   279,   280,   378,
     252,   407,   555,   556,   451,   253,   306,   256,   381,   307,
     308,   512,   513,   557,   425,   232,   309,   483,   484,   485,
     486,   487,   488,   489,   490,   236,   438,   521,   522,   239,
     393,   523,   524,   263,   395,   321,   322,   481,   482,   240,
     241,   453,   455,   457,   271,   272,   273,   401,   284,   283,
     285,   287,   288,   289,   459,   460,   290,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   680,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   353,   354,   300,   301,   302,   303,
     304,   305,   355,   312,   331,   439,   356,   357,   334,   352,
     379,   391,    81,   382,   383,   358,   396,   397,   495,   405,
     454,   456,   458,   402,   359,   408,   360,   361,   406,   420,
     421,  -352,   426,   423,   508,   362,   363,   353,   366,   429,
     436,   437,   444,   440,   441,   367,   364,   442,   443,   368,
     369,   445,   446,   497,   500,   447,   448,   -61,   370,   530,
     452,   480,   532,   534,   502,   504,   506,   371,   509,   372,
     373,   542,   498,   518,   539,   540,   543,   520,   374,   375,
     529,   541,   547,   545,   546,   551,   550,   496,   554,   364,
     552,   553,   559,   499,   563,   501,   567,   503,   560,   505,
     549,   507,   572,   594,   585,   586,   566,   587,   568,   574,
     575,   595,   596,   580,   597,   519,   581,   582,   583,   584,
     576,   588,   578,   589,   590,   591,   592,   593,   531,   598,
     599,   533,   535,   600,   601,   602,   603,   604,   605,   608,
     609,   606,   616,   607,   610,   544,   611,   612,   614,   617,
     641,   548,   634,   636,   638,   640,   643,   644,   645,   648,
     649,   762,   655,   656,   659,   652,   653,   657,   661,   665,
     667,   668,   670,   671,   666,   672,   682,   618,   683,   685,
     686,   692,   693,   684,  -261,   687,  -264,  -267,   700,   630,
     577,   697,   579,   704,   705,   713,   714,   716,   631,   720,
     721,   722,   725,   726,   727,   728,   733,   734,   735,   738,
     739,   736,   740,   741,   744,   745,   746,   737,   749,   750,
     751,   642,   752,   755,   761,   646,   647,   757,   756,   759,
     768,   763,   753,   654,   765,   769,   770,   771,   778,   782,
     787,   491,   568,   376,   568,   772,   619,   785,   786,   624,
     773,   625,   774,   626,   561,   627,     0,   337,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   632,
       0,     0,     0,     0,   673,   674,   675,   676,   633,     0,
       0,     0,   677,     0,     0,     0,     0,     0,   678,   679,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   651,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   698,     0,   701,   702,     0,     0,     0,   706,     0,
       0,     0,   708,     0,     0,   711,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   568,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   742,     0,     0,     0,     0,   747,     0,     0,
     748,     0,     0,     0,     0,     0,     0,     0,     0,   754,
     699,     0,     0,     0,   703,     0,     0,     0,   707,     0,
       0,     0,     0,     0,     0,   764,     0,     0,     0,   766,
       0,   767,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   775,
     776,     4,     0,   777,     0,   779,   780,     0,     5,     6,
       0,     0,   743,   783,     0,   784,     0,     0,     0,     0,
       7,     8,     0,     9,     0,    10,    11,     0,    12,    13,
       0,     0,     0,     0,     0,     0,    14,   789,    15,    16,
      17,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    28,     0,    29,
       0,     0,    30,    31,    32,     0,    33,    34,    35,    36,
      37,    38,    39,     0,    40,     0,     0,     0,    41,    42,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     0,    48,
       0,     0,     0,     5,     6,     0,     0,    49,     0,     0,
      50,     0,    51,    52,    53,     7,     8,     0,     9,     0,
      10,    11,     0,    12,    13,     0,     0,     0,     0,     0,
       0,    14,     0,    15,    16,    17,     0,     0,     0,     0,
      18,     0,     0,    54,     0,    55,    19,     0,     0,     0,
       0,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,    29,     0,    73,    30,    31,    32,
       0,    33,    34,    35,    36,    37,    38,    39,     0,    40,
       0,     0,   264,    41,    42,    43,    44,    45,     0,    46,
      47,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,    75,    76,    77,
       0,     0,    49,     0,     0,    50,     0,    51,    52,    53,
       0,     0,     0,     0,    78,     0,     0,    79,     0,     0,
      80,   265,   266,   267,     0,     0,     0,     0,     0,     0,
      82,    83,   268,     0,     0,     0,     0,     0,   431,     0,
       0,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,     0,     0,   101,
     102,   103,   269,   104,   105,   106,     0,   107,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    73,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,     0,     0,   184,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,     0,   185,
     186,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    76,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,    79,     0,     0,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,     0,     0,     0,   101,   102,   103,     0,   104,
     105,   106,     0,   107,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    73,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,     0,     0,
       0,   227,   228,     0,     0,     0,     0,     0,     0,    75,
      76,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,    79,
       0,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,     0,     0,
       0,   101,   102,   103,     0,   104,   105,   106,     0,   107,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    73,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,     0,     0,    79,     0,     0,    80,     0,
       0,     0,     0,     0,     0,     0,     0,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,     0,     0,     0,   101,   102,   103,
       0,   104,   105,   106,     0,   107,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      73,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       0,    79,     0,     0,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
       0,     0,     0,   101,   102,   103,     0,   104,   105,   106,
       0,   107,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    73,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    76,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,    79,     0,     0,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,    88,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,     0,     0,   101,
     102,   103,     0,   104,   105,   106,     0,   107,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    73,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    76,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,    79,     0,     0,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,     0,     0,     0,   101,   102,   103,     0,   104,
     105,   106,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,     0,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133
};

static const yytype_int16 yycheck[] =
{
      10,   249,   480,    13,   250,     6,    24,    17,     4,    24,
       6,    24,    13,    23,    68,   334,    26,    13,    24,    20,
     252,   253,    32,    33,    20,    24,     7,    24,    82,    24,
      20,    53,     7,    34,    44,    25,    46,    32,    34,    49,
     562,    24,   564,    82,    90,    20,    32,    79,    80,    20,
       0,    29,    62,   656,    49,   175,   659,    67,    68,    69,
      79,    80,   175,    49,    74,    25,    24,    20,     7,   717,
      48,    42,    13,    48,    22,   175,    86,   177,    36,    37,
     102,    34,    77,    78,    74,    75,    76,   158,   175,   567,
     144,    77,    78,   164,   572,    85,    35,    26,   144,     8,
       9,    42,    31,    12,    87,    14,    15,    16,    17,    18,
     713,   304,    34,   761,    74,    75,    76,   149,   150,   151,
      32,    62,   144,   177,     7,    85,    67,    68,    69,    87,
     149,   150,   151,   123,   782,    90,   614,    49,   177,   332,
     333,    34,    71,   665,     7,   135,   147,    45,   129,    24,
     160,   147,    35,   143,    24,    45,    54,   175,    25,   169,
     175,    45,   175,   123,    54,    77,    78,    56,    57,   175,
      54,    24,    35,   183,   184,   135,   175,   178,   175,   144,
     175,   191,   178,   143,   175,   195,   177,   433,    97,   667,
      45,    19,   424,    21,   204,   205,   105,    68,   208,    54,
      42,    43,    44,    45,    34,   146,   175,    74,    75,    76,
     220,   221,    54,    74,    75,     6,    83,    84,    85,   160,
       4,   231,    74,    75,    85,     4,   154,    24,   169,   157,
     158,    56,    57,    85,   244,   175,   164,   323,   324,   325,
     326,   327,   328,   329,   330,   175,   256,    56,    57,   175,
     191,    56,    57,   177,   195,     8,     9,   321,   322,   175,
     175,   271,   272,   273,    34,    34,    34,   208,    34,   177,
      34,    34,    34,    34,   284,   285,    34,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   613,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    24,    25,    34,    34,    34,    34,
      34,   157,    32,   157,   130,   256,    36,    37,   129,    24,
      29,     7,    82,    46,    46,    45,    29,    69,   338,    13,
     271,   272,   273,    34,    54,     7,    56,    57,   151,     7,
     147,   147,    13,   147,   354,    65,    66,    24,    25,    34,
      29,    29,    35,    72,    72,    32,    76,    72,    72,    36,
      37,    35,    35,    24,    24,    35,    35,    34,    45,   379,
      35,    34,   382,   383,    24,    24,    24,    54,    33,    56,
      57,   391,    48,    34,    42,   175,   396,    33,    65,    66,
      34,     7,   402,     7,     7,   405,     7,   338,   408,    76,
     102,     7,    34,   344,   147,   346,    34,   348,    20,   350,
      69,   352,    34,     7,    35,    35,   426,    35,   428,   175,
     175,     7,     7,   177,     7,   366,   177,   177,   177,   177,
     440,    35,   442,    35,    35,    35,    35,    35,   379,    35,
      35,   382,   383,    35,    35,     7,    35,    35,    35,     7,
       7,    35,    29,    35,    35,   396,    35,    35,    34,    29,
      13,   402,   175,   175,   175,   175,     7,    42,    42,     7,
       7,   719,     7,    34,    34,    72,   175,   177,   175,     7,
       7,    35,   177,   177,   148,   177,    35,   497,   175,    29,
      29,     7,     7,   175,     7,   176,     7,     7,     7,   509,
     441,    13,   443,    35,    35,     7,    35,   148,   518,   148,
     148,    35,    13,    35,    35,    35,    35,    35,    35,   176,
     176,    35,    29,    29,     7,     7,     7,    35,    13,    13,
      35,   541,    35,    13,     7,   545,   546,    35,    72,    35,
     176,    13,   115,   553,    13,   176,    35,    35,    35,     7,
      13,   331,   562,   156,   564,   744,   497,    35,    35,   500,
     745,   502,   746,   504,   420,   506,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   520,
      -1,    -1,    -1,    -1,   594,   595,   596,   597,   529,    -1,
      -1,    -1,   602,    -1,    -1,    -1,    -1,    -1,   608,   609,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   641,    -1,   643,   644,    -1,    -1,    -1,   648,    -1,
      -1,    -1,   652,    -1,    -1,   655,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   665,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   692,    -1,    -1,    -1,    -1,   697,    -1,    -1,
     700,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   709,
     641,    -1,    -1,    -1,   645,    -1,    -1,    -1,   649,    -1,
      -1,    -1,    -1,    -1,    -1,   725,    -1,    -1,    -1,   729,
      -1,   731,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   749,
     750,     3,    -1,   753,    -1,   755,   756,    -1,    10,    11,
      -1,    -1,   693,   763,    -1,   765,    -1,    -1,    -1,    -1,
      22,    23,    -1,    25,    -1,    27,    28,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,   787,    40,    41,
      42,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
      -1,    -1,    94,    95,    96,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,    -1,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,   131,
      -1,    -1,    -1,    10,    11,    -1,    -1,   139,    -1,    -1,
     142,    -1,   144,   145,   146,    22,    23,    -1,    25,    -1,
      27,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,
      47,    -1,    -1,   175,    -1,   177,    53,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    -1,    91,    -1,     9,    94,    95,    96,
      -1,    98,    99,   100,   101,   102,   103,   104,    -1,   106,
      -1,    -1,    25,   110,   111,   112,   113,   114,    -1,   116,
     117,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    50,    51,    52,
      -1,    -1,   139,    -1,    -1,   142,    -1,   144,   145,   146,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,   175,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,   137,   138,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,     9,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,
     137,   138,    -1,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,     9,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,   137,   138,    -1,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,     9,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,   132,   133,   134,
      -1,   136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
       9,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,   138,
      -1,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,     9,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,    -1,   136,   137,   138,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,     9,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,
     137,   138,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   275,   276,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    88,    89,    91,
      94,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     106,   110,   111,   112,   113,   114,   116,   117,   131,   139,
     142,   144,   145,   146,   175,   177,   260,   269,   271,   273,
     175,   175,    24,   175,   196,   197,   198,    26,    31,    71,
     202,   203,   204,     9,    34,    50,    51,    52,    67,    70,
      73,    82,    83,    84,    94,    95,   107,   108,   109,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   132,   133,   134,   136,   137,   138,   140,   141,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   180,   181,   182,   183,   184,   185,
     188,   189,   206,   207,   208,    22,    24,    32,    49,    77,
      78,   175,   193,   194,   195,   180,   185,   209,   210,   211,
      24,    36,    37,    87,   212,   213,   214,    42,    43,    44,
      45,    54,   227,   228,   229,   180,   244,   175,   230,   233,
     175,   177,   231,   261,    24,    36,    37,   180,   218,   219,
     220,    24,   221,   222,   223,    24,    87,   224,   225,   226,
     180,    90,    90,   144,    34,    34,   180,   180,    24,   215,
     216,   217,    24,   234,   235,   236,   175,   177,   232,   144,
      68,    68,   144,   177,   185,   180,   175,    42,    43,   180,
     248,    34,   175,   249,   180,   237,   175,   252,   256,   175,
     175,   175,     4,     6,    13,    20,   147,   178,   266,   268,
     272,     6,     4,     4,   180,   185,    24,   180,   185,   180,
     185,   180,   185,   177,    25,    74,    75,    76,    85,   135,
     180,    34,    34,    34,    25,    74,    75,    76,    83,    84,
      85,   186,   187,   177,    34,    34,   180,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,   157,   154,   157,   158,   164,
     158,   164,   157,    20,   190,    79,    80,   149,   150,   151,
     205,     8,     9,    12,    14,    15,    16,    17,    18,    97,
     105,   130,    19,    21,   129,    80,   151,   205,    24,   175,
     199,   200,   201,   185,    24,   175,    24,   175,    24,   175,
      24,   175,    24,    24,    25,    32,    36,    37,    45,    54,
      56,    57,    65,    66,    76,   192,    25,    32,    36,    37,
      45,    54,    56,    57,    65,    66,   192,   180,   185,    29,
     180,   185,    46,    46,    53,   102,   144,    20,    42,   180,
     180,     7,   180,   185,   180,   185,    29,    69,   180,   180,
     180,   185,    34,   180,   180,    13,   151,   180,     7,    25,
      74,    75,    76,    85,   123,   135,   143,   251,   253,   254,
       7,   147,   262,   147,   274,   180,    13,   267,   263,    34,
     251,   175,   269,   270,   273,   273,    29,    29,   180,   185,
      72,    72,    72,    72,    35,    35,    35,    35,    35,    74,
      75,    85,    35,   180,   185,   180,   185,   180,   185,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   184,   191,
      34,   182,   182,   181,   181,   181,   181,   181,   181,   181,
     181,   183,   184,   184,   189,   180,   185,    24,    48,   185,
      24,   185,    24,   185,    24,   185,    24,   185,   180,    33,
      56,    57,    56,    57,    45,    54,    45,    54,    34,   185,
      33,    56,    57,    56,    57,    45,    54,    45,    54,    34,
     180,   185,   180,   185,   180,   185,   245,   247,   246,    42,
     175,     7,   180,   180,   185,     7,     7,   180,   185,    69,
       7,   180,   102,     7,   180,    74,    75,    85,   255,    34,
      20,   256,   264,   147,   265,   273,   180,    34,   180,   259,
     180,   257,    34,   269,   175,   175,   180,   185,   180,   185,
     177,   177,   177,   177,   177,    35,    35,    35,    35,    35,
      35,    35,    35,    35,     7,     7,     7,     7,    35,    35,
      35,    35,     7,    35,    35,    35,    35,    35,     7,     7,
      35,    35,    35,     7,    34,   257,    29,    29,   180,   185,
      32,    49,    77,    78,   185,   185,   185,   185,    29,    48,
     180,   180,   185,   185,   175,   238,   175,   240,   175,   242,
     175,    13,   180,     7,    42,    42,   180,   180,     7,     7,
     177,   185,    72,   175,   180,     7,    34,   177,   250,    34,
     259,   175,   258,   259,   257,     7,   148,     7,    35,   257,
     177,   177,   177,   180,   180,   180,   180,   180,   180,   180,
     189,   257,    35,   175,   175,    29,    29,   176,    32,    49,
      77,    78,     7,     7,   239,   241,   243,    13,   180,   185,
       7,   180,   180,   185,    35,    35,   180,   185,   180,     7,
      35,   180,   250,     7,    35,   250,   148,     7,    20,    48,
     148,   148,    35,   259,   257,    13,    35,    35,    35,     7,
      35,     7,    35,    35,    35,    35,    35,    35,   176,   176,
      29,    29,   180,   185,     7,     7,     7,   180,   180,    13,
      13,    35,    35,   115,   180,    13,    72,    35,   250,    35,
     258,     7,   251,    13,   180,    13,   180,   180,   176,   176,
      35,    35,   238,   240,   242,   180,   180,   180,    35,   180,
     180,   258,     7,   180,   180,    35,    35,    13,   258,   180
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   179,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   181,   181,   181,   182,   182,   183,   183,   183,
     184,   184,   184,   185,   186,   186,   186,   186,   186,   186,
     186,   187,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   190,
     189,   191,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   192,   192,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   194,   194,   194,   194,   194,   195,
     195,   196,   196,   197,   197,   198,   198,   199,   199,   200,
     200,   201,   201,   202,   202,   202,   203,   203,   203,   204,
     204,   205,   205,   205,   206,   206,   206,   207,   207,   207,
     208,   208,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   211,   211,   212,   212,   212,   212,   212,   213,
     213,   214,   214,   215,   216,   217,   217,   218,   218,   219,
     219,   220,   220,   221,   222,   223,   223,   224,   224,   224,
     225,   225,   226,   226,   227,   227,   227,   227,   227,   228,
     228,   228,   229,   229,   230,   230,   230,   230,   230,   230,
     231,   231,   232,   232,   233,   234,   235,   236,   236,   237,
     238,   239,   238,   240,   241,   240,   242,   243,   242,   245,
     244,   246,   244,   247,   244,   248,   248,   248,   249,   249,
     250,   250,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   253,   252,   254,   252,   255,   252,   256,   256,
     257,   257,   258,   258,   258,   258,   258,   258,   259,   259,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   261,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   262,   260,   260,   260,   260,   260,   260,   263,
     260,   264,   260,   265,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   266,   260,   267,   260,   268,
     260,   260,   260,   260,   269,   270,   269,   272,   271,   274,
     273,   273,   273,   273,   273,   276,   275
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
       1,     2,     0,     6,     2,     8,     2,     2,     2,     0,
       5,     0,     6,     0,     6,     2,     2,     2,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     8,     8,
       8,    10,     2,     3,     4,     0,     7,     0,     8,     0,
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
#line 74 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2577 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 78 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2586 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 82 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2594 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 85 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2602 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 88 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2610 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 91 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2618 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 94 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2626 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 97 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2634 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 100 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2642 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 107 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2650 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 110 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2659 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 123 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2668 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 127 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2677 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 135 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2686 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 139 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 2695 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 146 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2703 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 151 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2711 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 154 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2719 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 157 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2727 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 160 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2735 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 163 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2743 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 166 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2751 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 169 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2759 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 174 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2767 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 179 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2776 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 183 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2785 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 187 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2794 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 191 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2803 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 195 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2812 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 199 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2821 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 203 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2830 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 207 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2839 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 211 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2848 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 215 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2857 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 219 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2866 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 223 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2875 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 227 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2884 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 231 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2893 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 235 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2902 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 239 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2911 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 243 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2920 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 247 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2929 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 251 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2938 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 255 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2947 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 259 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2956 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 263 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2965 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 267 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2974 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 271 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2983 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 275 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2992 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 279 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3001 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 283 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3010 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 289 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3019 "src-generated/ugbc.tab.c"
    break;

  case 60: /* exponential: Identifier $@1 OP indexes CP  */
#line 293 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-4].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-4].string) )->name;
    }
#line 3031 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 300 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3040 "src-generated/ugbc.tab.c"
    break;

  case 62: /* exponential: Identifier DOLLAR $@2 OP indexes CP  */
#line 304 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-5].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-5].string) )->name;
    }
#line 3052 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 311 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3060 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 314 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3068 "src-generated/ugbc.tab.c"
    break;

  case 65: /* exponential: Integer  */
#line 317 "src/ugbc.y"
              { 
        if ( (yyvsp[0].integer) < 0 ) {
            (yyval.string) = variable_temporary( _environment, VT_SWORD, "(signed integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        } else {
            (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        }
      }
#line 3082 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 326 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3091 "src-generated/ugbc.tab.c"
    break;

  case 67: /* exponential: String  */
#line 330 "src/ugbc.y"
             { 
        outline1("; (expr string: \"%s\")", (yyvsp[0].string) );
        (yyval.string) = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", (yyval.string) );
        variable_store_string( _environment, (yyval.string), (yyvsp[0].string) );
        outline2("; variable stored: %s = %s", (yyval.string), (yyvsp[0].string) );
      }
#line 3103 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 337 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3112 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 341 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3121 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 345 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3130 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 349 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3139 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 353 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3148 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 357 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3157 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 361 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3166 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 365 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3175 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 369 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3183 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 372 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3191 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 375 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3199 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 378 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3207 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 381 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3215 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 384 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3223 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 387 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3231 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 390 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3239 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 393 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3247 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 396 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3255 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 399 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3263 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 402 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3271 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 405 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3279 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 408 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3287 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 411 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3295 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 414 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3303 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 417 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3311 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 420 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3319 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 423 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3327 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 426 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3335 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 429 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3343 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 432 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3351 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 435 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3359 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 438 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3367 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 441 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3375 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 444 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3383 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 447 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3391 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 450 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3399 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 453 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3407 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 456 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3415 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: SGN OP expr CP  */
#line 459 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3423 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: ABS OP expr CP  */
#line 462 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3431 "src-generated/ugbc.tab.c"
    break;

  case 108: /* exponential: TRUE  */
#line 465 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3440 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: FALSE  */
#line 469 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3449 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: COLORS  */
#line 473 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3458 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: WIDTH  */
#line 477 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3466 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: HEIGHT  */
#line 480 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3474 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: TIMER  */
#line 483 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3482 "src-generated/ugbc.tab.c"
    break;

  case 116: /* bank_definition_simple: AT direct_integer  */
#line 491 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3490 "src-generated/ugbc.tab.c"
    break;

  case 117: /* bank_definition_simple: Identifier AT direct_integer  */
#line 494 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3498 "src-generated/ugbc.tab.c"
    break;

  case 118: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 497 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3506 "src-generated/ugbc.tab.c"
    break;

  case 119: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 500 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3514 "src-generated/ugbc.tab.c"
    break;

  case 120: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 503 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3522 "src-generated/ugbc.tab.c"
    break;

  case 121: /* bank_definition_simple: DATA AT direct_integer  */
#line 506 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3530 "src-generated/ugbc.tab.c"
    break;

  case 122: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 510 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3538 "src-generated/ugbc.tab.c"
    break;

  case 123: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 513 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3546 "src-generated/ugbc.tab.c"
    break;

  case 124: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 516 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3554 "src-generated/ugbc.tab.c"
    break;

  case 125: /* bank_definition_simple: CODE AT direct_integer  */
#line 519 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3562 "src-generated/ugbc.tab.c"
    break;

  case 126: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 523 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3570 "src-generated/ugbc.tab.c"
    break;

  case 127: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 526 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3578 "src-generated/ugbc.tab.c"
    break;

  case 128: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 529 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3586 "src-generated/ugbc.tab.c"
    break;

  case 129: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 532 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3594 "src-generated/ugbc.tab.c"
    break;

  case 130: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 536 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3602 "src-generated/ugbc.tab.c"
    break;

  case 131: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 539 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3610 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 542 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3618 "src-generated/ugbc.tab.c"
    break;

  case 133: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 545 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3626 "src-generated/ugbc.tab.c"
    break;

  case 134: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 551 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3634 "src-generated/ugbc.tab.c"
    break;

  case 135: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 554 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3642 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 557 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3650 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 560 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3658 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 563 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3666 "src-generated/ugbc.tab.c"
    break;

  case 141: /* raster_definition_simple: Identifier AT direct_integer  */
#line 572 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3674 "src-generated/ugbc.tab.c"
    break;

  case 142: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 575 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3682 "src-generated/ugbc.tab.c"
    break;

  case 143: /* raster_definition_expression: Identifier AT expr  */
#line 580 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3690 "src-generated/ugbc.tab.c"
    break;

  case 144: /* raster_definition_expression: AT expr WITH Identifier  */
#line 583 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3698 "src-generated/ugbc.tab.c"
    break;

  case 147: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 592 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3706 "src-generated/ugbc.tab.c"
    break;

  case 148: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 595 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3714 "src-generated/ugbc.tab.c"
    break;

  case 149: /* next_raster_definition_expression: Identifier AT expr  */
#line 600 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3722 "src-generated/ugbc.tab.c"
    break;

  case 150: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 603 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3730 "src-generated/ugbc.tab.c"
    break;

  case 153: /* color_definition_simple: BORDER direct_integer  */
#line 612 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3738 "src-generated/ugbc.tab.c"
    break;

  case 154: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 615 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3746 "src-generated/ugbc.tab.c"
    break;

  case 155: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 618 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3754 "src-generated/ugbc.tab.c"
    break;

  case 156: /* color_definition_expression: BORDER expr  */
#line 623 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3762 "src-generated/ugbc.tab.c"
    break;

  case 157: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 626 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3770 "src-generated/ugbc.tab.c"
    break;

  case 158: /* color_definition_expression: SPRITE expr TO expr  */
#line 629 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3778 "src-generated/ugbc.tab.c"
    break;

  case 164: /* wait_definition_simple: direct_integer CYCLES  */
#line 643 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3786 "src-generated/ugbc.tab.c"
    break;

  case 165: /* wait_definition_simple: direct_integer TICKS  */
#line 646 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3794 "src-generated/ugbc.tab.c"
    break;

  case 166: /* wait_definition_simple: direct_integer milliseconds  */
#line 649 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3802 "src-generated/ugbc.tab.c"
    break;

  case 167: /* wait_definition_expression: expr CYCLES  */
#line 654 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3810 "src-generated/ugbc.tab.c"
    break;

  case 168: /* wait_definition_expression: expr TICKS  */
#line 657 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3818 "src-generated/ugbc.tab.c"
    break;

  case 169: /* wait_definition_expression: expr milliseconds  */
#line 660 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3826 "src-generated/ugbc.tab.c"
    break;

  case 172: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 670 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3834 "src-generated/ugbc.tab.c"
    break;

  case 173: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 673 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3842 "src-generated/ugbc.tab.c"
    break;

  case 174: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 676 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3850 "src-generated/ugbc.tab.c"
    break;

  case 175: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 679 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3858 "src-generated/ugbc.tab.c"
    break;

  case 176: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 682 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3866 "src-generated/ugbc.tab.c"
    break;

  case 177: /* sprite_definition_simple: direct_integer ENABLE  */
#line 685 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3874 "src-generated/ugbc.tab.c"
    break;

  case 178: /* sprite_definition_simple: direct_integer DISABLE  */
#line 688 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3882 "src-generated/ugbc.tab.c"
    break;

  case 179: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 691 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3890 "src-generated/ugbc.tab.c"
    break;

  case 180: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 694 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3898 "src-generated/ugbc.tab.c"
    break;

  case 181: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 697 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3906 "src-generated/ugbc.tab.c"
    break;

  case 182: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 700 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3914 "src-generated/ugbc.tab.c"
    break;

  case 183: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 703 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3922 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 706 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3930 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 709 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3938 "src-generated/ugbc.tab.c"
    break;

  case 186: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 712 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3946 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_expression: expr DATA FROM expr  */
#line 717 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3954 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_expression: expr MULTICOLOR  */
#line 720 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3962 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_expression: expr MONOCOLOR  */
#line 723 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3970 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_expression: expr COLOR expr  */
#line 726 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3978 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 729 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3986 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_expression: expr ENABLE  */
#line 732 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3994 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_expression: expr DISABLE  */
#line 735 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4002 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 738 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4010 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 741 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4018 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 744 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4026 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 747 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4034 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 750 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4042 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 753 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4050 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 756 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4058 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 759 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4066 "src-generated/ugbc.tab.c"
    break;

  case 204: /* bitmap_definition_simple: AT direct_integer  */
#line 768 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4074 "src-generated/ugbc.tab.c"
    break;

  case 205: /* bitmap_definition_simple: ENABLE  */
#line 771 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4082 "src-generated/ugbc.tab.c"
    break;

  case 206: /* bitmap_definition_simple: DISABLE  */
#line 774 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4090 "src-generated/ugbc.tab.c"
    break;

  case 207: /* bitmap_definition_simple: CLEAR  */
#line 777 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4098 "src-generated/ugbc.tab.c"
    break;

  case 208: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 780 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4106 "src-generated/ugbc.tab.c"
    break;

  case 209: /* bitmap_definition_expression: AT expr  */
#line 786 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4114 "src-generated/ugbc.tab.c"
    break;

  case 210: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 789 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4122 "src-generated/ugbc.tab.c"
    break;

  case 213: /* textmap_definition_simple: AT direct_integer  */
#line 799 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4130 "src-generated/ugbc.tab.c"
    break;

  case 214: /* textmap_definition_expression: AT expr  */
#line 804 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4138 "src-generated/ugbc.tab.c"
    break;

  case 217: /* text_definition_simple: ENABLE  */
#line 813 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4146 "src-generated/ugbc.tab.c"
    break;

  case 218: /* text_definition_simple: DISABLE  */
#line 816 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4154 "src-generated/ugbc.tab.c"
    break;

  case 219: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 821 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4162 "src-generated/ugbc.tab.c"
    break;

  case 220: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 824 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4170 "src-generated/ugbc.tab.c"
    break;

  case 223: /* tiles_definition_simple: AT direct_integer  */
#line 833 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4178 "src-generated/ugbc.tab.c"
    break;

  case 224: /* tiles_definition_expression: AT expr  */
#line 838 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4186 "src-generated/ugbc.tab.c"
    break;

  case 227: /* colormap_definition_simple: AT direct_integer  */
#line 847 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4194 "src-generated/ugbc.tab.c"
    break;

  case 228: /* colormap_definition_simple: CLEAR  */
#line 850 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4202 "src-generated/ugbc.tab.c"
    break;

  case 229: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 853 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4210 "src-generated/ugbc.tab.c"
    break;

  case 230: /* colormap_definition_expression: AT expr  */
#line 858 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4218 "src-generated/ugbc.tab.c"
    break;

  case 231: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 861 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4226 "src-generated/ugbc.tab.c"
    break;

  case 234: /* screen_definition_simple: ON  */
#line 871 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4234 "src-generated/ugbc.tab.c"
    break;

  case 235: /* screen_definition_simple: OFF  */
#line 874 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4242 "src-generated/ugbc.tab.c"
    break;

  case 236: /* screen_definition_simple: ROWS direct_integer  */
#line 877 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4250 "src-generated/ugbc.tab.c"
    break;

  case 237: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 880 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4258 "src-generated/ugbc.tab.c"
    break;

  case 238: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 883 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4266 "src-generated/ugbc.tab.c"
    break;

  case 239: /* screen_definition_expression: ROWS expr  */
#line 888 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4274 "src-generated/ugbc.tab.c"
    break;

  case 240: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 891 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4282 "src-generated/ugbc.tab.c"
    break;

  case 241: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 894 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4290 "src-generated/ugbc.tab.c"
    break;

  case 245: /* var_definition_simple: Identifier ON Identifier  */
#line 903 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4298 "src-generated/ugbc.tab.c"
    break;

  case 246: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 906 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4306 "src-generated/ugbc.tab.c"
    break;

  case 247: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 909 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4314 "src-generated/ugbc.tab.c"
    break;

  case 248: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 912 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4324 "src-generated/ugbc.tab.c"
    break;

  case 249: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 917 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4334 "src-generated/ugbc.tab.c"
    break;

  case 250: /* goto_definition: Identifier  */
#line 924 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4342 "src-generated/ugbc.tab.c"
    break;

  case 251: /* goto_definition: Integer  */
#line 927 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4350 "src-generated/ugbc.tab.c"
    break;

  case 252: /* gosub_definition: Identifier  */
#line 933 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4358 "src-generated/ugbc.tab.c"
    break;

  case 253: /* gosub_definition: Integer  */
#line 936 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4366 "src-generated/ugbc.tab.c"
    break;

  case 255: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 945 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4374 "src-generated/ugbc.tab.c"
    break;

  case 256: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 951 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4382 "src-generated/ugbc.tab.c"
    break;

  case 259: /* ink_definition: expr  */
#line 960 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4390 "src-generated/ugbc.tab.c"
    break;

  case 260: /* on_goto_definition: Identifier  */
#line 965 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4399 "src-generated/ugbc.tab.c"
    break;

  case 261: /* $@3: %empty  */
#line 969 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4407 "src-generated/ugbc.tab.c"
    break;

  case 263: /* on_gosub_definition: Identifier  */
#line 974 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4416 "src-generated/ugbc.tab.c"
    break;

  case 264: /* $@4: %empty  */
#line 978 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4424 "src-generated/ugbc.tab.c"
    break;

  case 266: /* on_proc_definition: Identifier  */
#line 983 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4433 "src-generated/ugbc.tab.c"
    break;

  case 267: /* $@5: %empty  */
#line 987 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 4441 "src-generated/ugbc.tab.c"
    break;

  case 269: /* $@6: %empty  */
#line 992 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4449 "src-generated/ugbc.tab.c"
    break;

  case 271: /* $@7: %empty  */
#line 995 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 4457 "src-generated/ugbc.tab.c"
    break;

  case 273: /* $@8: %empty  */
#line 998 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4465 "src-generated/ugbc.tab.c"
    break;

  case 275: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1003 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4473 "src-generated/ugbc.tab.c"
    break;

  case 276: /* every_definition: ON  */
#line 1006 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4481 "src-generated/ugbc.tab.c"
    break;

  case 277: /* every_definition: OFF  */
#line 1009 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4489 "src-generated/ugbc.tab.c"
    break;

  case 278: /* add_definition: Identifier COMMA expr  */
#line 1014 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4497 "src-generated/ugbc.tab.c"
    break;

  case 279: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1017 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4505 "src-generated/ugbc.tab.c"
    break;

  case 280: /* dimensions: Integer  */
#line 1023 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4514 "src-generated/ugbc.tab.c"
    break;

  case 281: /* dimensions: Integer COMMA dimensions  */
#line 1027 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4523 "src-generated/ugbc.tab.c"
    break;

  case 282: /* datatype: BYTE  */
#line 1034 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 4531 "src-generated/ugbc.tab.c"
    break;

  case 283: /* datatype: SIGNED BYTE  */
#line 1037 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 4539 "src-generated/ugbc.tab.c"
    break;

  case 284: /* datatype: WORD  */
#line 1040 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 4547 "src-generated/ugbc.tab.c"
    break;

  case 285: /* datatype: SIGNED WORD  */
#line 1043 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 4555 "src-generated/ugbc.tab.c"
    break;

  case 286: /* datatype: DWORD  */
#line 1046 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 4563 "src-generated/ugbc.tab.c"
    break;

  case 287: /* datatype: SIGNED DWORD  */
#line 1049 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 4571 "src-generated/ugbc.tab.c"
    break;

  case 288: /* datatype: ADDRESS  */
#line 1052 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 4579 "src-generated/ugbc.tab.c"
    break;

  case 289: /* datatype: POSITION  */
#line 1055 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 4587 "src-generated/ugbc.tab.c"
    break;

  case 290: /* datatype: COLOR  */
#line 1058 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 4595 "src-generated/ugbc.tab.c"
    break;

  case 291: /* datatype: STRING  */
#line 1061 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 4603 "src-generated/ugbc.tab.c"
    break;

  case 292: /* $@9: %empty  */
#line 1066 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4612 "src-generated/ugbc.tab.c"
    break;

  case 293: /* dim_definition: Identifier $@9 OP dimensions CP  */
#line 1069 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 4622 "src-generated/ugbc.tab.c"
    break;

  case 294: /* $@10: %empty  */
#line 1074 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4631 "src-generated/ugbc.tab.c"
    break;

  case 295: /* dim_definition: Identifier $@10 DOLLAR OP dimensions CP  */
#line 1077 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 4641 "src-generated/ugbc.tab.c"
    break;

  case 296: /* $@11: %empty  */
#line 1082 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4650 "src-generated/ugbc.tab.c"
    break;

  case 297: /* dim_definition: Identifier datatype $@11 OP dimensions CP  */
#line 1085 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 4660 "src-generated/ugbc.tab.c"
    break;

  case 300: /* indexes: expr  */
#line 1098 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = (yyvsp[0].string);
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4669 "src-generated/ugbc.tab.c"
    break;

  case 301: /* indexes: expr COMMA indexes  */
#line 1102 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = (yyvsp[-2].string);
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4678 "src-generated/ugbc.tab.c"
    break;

  case 302: /* parameters: Identifier  */
#line 1109 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].string);
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4688 "src-generated/ugbc.tab.c"
    break;

  case 303: /* parameters: Identifier DOLLAR  */
#line 1114 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-1].string);
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4698 "src-generated/ugbc.tab.c"
    break;

  case 304: /* parameters: Identifier AS datatype  */
#line 1119 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].string);
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4708 "src-generated/ugbc.tab.c"
    break;

  case 305: /* parameters: Identifier COMMA parameters  */
#line 1124 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].string);
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4718 "src-generated/ugbc.tab.c"
    break;

  case 306: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1129 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-3].string);
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4728 "src-generated/ugbc.tab.c"
    break;

  case 307: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1134 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-4].string);
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4738 "src-generated/ugbc.tab.c"
    break;

  case 308: /* values: expr  */
#line 1142 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].string);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4747 "src-generated/ugbc.tab.c"
    break;

  case 309: /* values: expr COMMA values  */
#line 1146 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].string);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 4756 "src-generated/ugbc.tab.c"
    break;

  case 326: /* statement: INC Identifier  */
#line 1169 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 4764 "src-generated/ugbc.tab.c"
    break;

  case 327: /* statement: DEC Identifier  */
#line 1172 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 4772 "src-generated/ugbc.tab.c"
    break;

  case 328: /* statement: RANDOMIZE  */
#line 1175 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 4780 "src-generated/ugbc.tab.c"
    break;

  case 329: /* statement: RANDOMIZE expr  */
#line 1178 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 4788 "src-generated/ugbc.tab.c"
    break;

  case 330: /* statement: IF expr THEN  */
#line 1181 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4796 "src-generated/ugbc.tab.c"
    break;

  case 331: /* statement: ELSE  */
#line 1184 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 4804 "src-generated/ugbc.tab.c"
    break;

  case 332: /* statement: ELSE IF expr THEN  */
#line 1187 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4812 "src-generated/ugbc.tab.c"
    break;

  case 333: /* statement: ENDIF  */
#line 1190 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 4820 "src-generated/ugbc.tab.c"
    break;

  case 334: /* statement: DO  */
#line 1193 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 4828 "src-generated/ugbc.tab.c"
    break;

  case 335: /* statement: LOOP  */
#line 1196 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 4836 "src-generated/ugbc.tab.c"
    break;

  case 336: /* $@12: %empty  */
#line 1199 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 4844 "src-generated/ugbc.tab.c"
    break;

  case 337: /* statement: WHILE $@12 expr  */
#line 1201 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 4852 "src-generated/ugbc.tab.c"
    break;

  case 338: /* statement: WEND  */
#line 1204 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 4860 "src-generated/ugbc.tab.c"
    break;

  case 339: /* statement: REPEAT  */
#line 1207 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 4868 "src-generated/ugbc.tab.c"
    break;

  case 340: /* statement: UNTIL expr  */
#line 1210 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 4876 "src-generated/ugbc.tab.c"
    break;

  case 341: /* statement: EXIT  */
#line 1213 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 4884 "src-generated/ugbc.tab.c"
    break;

  case 342: /* statement: EXIT PROC  */
#line 1216 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 4892 "src-generated/ugbc.tab.c"
    break;

  case 343: /* statement: POP PROC  */
#line 1219 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 4900 "src-generated/ugbc.tab.c"
    break;

  case 344: /* statement: EXIT IF expr  */
#line 1222 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 4908 "src-generated/ugbc.tab.c"
    break;

  case 345: /* statement: EXIT Integer  */
#line 1225 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4916 "src-generated/ugbc.tab.c"
    break;

  case 346: /* statement: EXIT direct_integer  */
#line 1228 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4924 "src-generated/ugbc.tab.c"
    break;

  case 347: /* statement: EXIT IF expr COMMA Integer  */
#line 1231 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4932 "src-generated/ugbc.tab.c"
    break;

  case 348: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1234 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4940 "src-generated/ugbc.tab.c"
    break;

  case 349: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1237 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4948 "src-generated/ugbc.tab.c"
    break;

  case 350: /* statement: NEXT  */
#line 1240 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 4956 "src-generated/ugbc.tab.c"
    break;

  case 351: /* statement: PROCEDURE Identifier  */
#line 1243 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 4965 "src-generated/ugbc.tab.c"
    break;

  case 352: /* $@13: %empty  */
#line 1247 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 4973 "src-generated/ugbc.tab.c"
    break;

  case 353: /* statement: PROCEDURE Identifier $@13 OSP parameters CSP  */
#line 1249 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 4981 "src-generated/ugbc.tab.c"
    break;

  case 354: /* statement: END PROC  */
#line 1252 "src/ugbc.y"
             {
      end_procedure( _environment );
  }
#line 4989 "src-generated/ugbc.tab.c"
    break;

  case 355: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1255 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4997 "src-generated/ugbc.tab.c"
    break;

  case 356: /* statement: Identifier " "  */
#line 1258 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 5006 "src-generated/ugbc.tab.c"
    break;

  case 357: /* statement: PROC Identifier  */
#line 1262 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5015 "src-generated/ugbc.tab.c"
    break;

  case 358: /* statement: CALL Identifier  */
#line 1266 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 5024 "src-generated/ugbc.tab.c"
    break;

  case 359: /* $@14: %empty  */
#line 1270 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5032 "src-generated/ugbc.tab.c"
    break;

  case 360: /* statement: Identifier OSP $@14 values CSP  */
#line 1272 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5040 "src-generated/ugbc.tab.c"
    break;

  case 361: /* $@15: %empty  */
#line 1275 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5048 "src-generated/ugbc.tab.c"
    break;

  case 362: /* statement: PROC Identifier OSP $@15 values CSP  */
#line 1277 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5056 "src-generated/ugbc.tab.c"
    break;

  case 363: /* $@16: %empty  */
#line 1280 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5064 "src-generated/ugbc.tab.c"
    break;

  case 364: /* statement: CALL Identifier OSP $@16 values CSP  */
#line 1282 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5072 "src-generated/ugbc.tab.c"
    break;

  case 365: /* statement: Identifier COLON  */
#line 1285 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 5080 "src-generated/ugbc.tab.c"
    break;

  case 366: /* statement: BEG GAMELOOP  */
#line 1288 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 5088 "src-generated/ugbc.tab.c"
    break;

  case 367: /* statement: END GAMELOOP  */
#line 1291 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 5096 "src-generated/ugbc.tab.c"
    break;

  case 368: /* statement: GRAPHIC  */
#line 1294 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 5104 "src-generated/ugbc.tab.c"
    break;

  case 369: /* statement: HALT  */
#line 1297 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 5112 "src-generated/ugbc.tab.c"
    break;

  case 370: /* statement: END  */
#line 1300 "src/ugbc.y"
        {
      end( _environment );
  }
#line 5120 "src-generated/ugbc.tab.c"
    break;

  case 375: /* statement: RETURN  */
#line 1307 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 5128 "src-generated/ugbc.tab.c"
    break;

  case 376: /* statement: POP  */
#line 1310 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 5136 "src-generated/ugbc.tab.c"
    break;

  case 377: /* statement: DONE  */
#line 1313 "src/ugbc.y"
          {
      return 0;
  }
#line 5144 "src-generated/ugbc.tab.c"
    break;

  case 378: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1316 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5152 "src-generated/ugbc.tab.c"
    break;

  case 379: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1319 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5160 "src-generated/ugbc.tab.c"
    break;

  case 380: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1322 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 5168 "src-generated/ugbc.tab.c"
    break;

  case 381: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1325 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5176 "src-generated/ugbc.tab.c"
    break;

  case 383: /* statement: Identifier ASSIGN expr  */
#line 1329 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 5190 "src-generated/ugbc.tab.c"
    break;

  case 384: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1338 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 5204 "src-generated/ugbc.tab.c"
    break;

  case 385: /* $@17: %empty  */
#line 1347 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5213 "src-generated/ugbc.tab.c"
    break;

  case 386: /* statement: Identifier $@17 OP indexes CP ASSIGN expr  */
#line 1351 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 5226 "src-generated/ugbc.tab.c"
    break;

  case 387: /* $@18: %empty  */
#line 1359 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5235 "src-generated/ugbc.tab.c"
    break;

  case 388: /* statement: Identifier DOLLAR $@18 OP indexes CP ASSIGN expr  */
#line 1362 "src/ugbc.y"
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
#line 5254 "src-generated/ugbc.tab.c"
    break;

  case 389: /* $@19: %empty  */
#line 1376 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 5263 "src-generated/ugbc.tab.c"
    break;

  case 390: /* statement: Identifier $@19 datatype OP indexes CP ASSIGN expr  */
#line 1379 "src/ugbc.y"
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
#line 5282 "src-generated/ugbc.tab.c"
    break;

  case 391: /* statement: DEBUG expr  */
#line 1393 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 5290 "src-generated/ugbc.tab.c"
    break;

  case 394: /* statements_no_linenumbers: statement  */
#line 1401 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 5296 "src-generated/ugbc.tab.c"
    break;

  case 395: /* $@20: %empty  */
#line 1402 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 5302 "src-generated/ugbc.tab.c"
    break;

  case 397: /* $@21: %empty  */
#line 1406 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 5310 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statements_with_linenumbers: Integer $@21 statements_no_linenumbers  */
#line 1408 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 5318 "src-generated/ugbc.tab.c"
    break;

  case 399: /* $@22: %empty  */
#line 1413 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 5326 "src-generated/ugbc.tab.c"
    break;

  case 405: /* $@23: %empty  */
#line 1423 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 5332 "src-generated/ugbc.tab.c"
    break;


#line 5336 "src-generated/ugbc.tab.c"

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

#line 1425 "src/ugbc.y"


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

