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
  YYSYMBOL_MILLISECOND = 144,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 145,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 146,                    /* TICKS  */
  YYSYMBOL_BLACK = 147,                    /* BLACK  */
  YYSYMBOL_WHITE = 148,                    /* WHITE  */
  YYSYMBOL_RED = 149,                      /* RED  */
  YYSYMBOL_CYAN = 150,                     /* CYAN  */
  YYSYMBOL_VIOLET = 151,                   /* VIOLET  */
  YYSYMBOL_GREEN = 152,                    /* GREEN  */
  YYSYMBOL_BLUE = 153,                     /* BLUE  */
  YYSYMBOL_YELLOW = 154,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 155,                   /* ORANGE  */
  YYSYMBOL_BROWN = 156,                    /* BROWN  */
  YYSYMBOL_LIGHT = 157,                    /* LIGHT  */
  YYSYMBOL_DARK = 158,                     /* DARK  */
  YYSYMBOL_GREY = 159,                     /* GREY  */
  YYSYMBOL_GRAY = 160,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 161,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 162,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 163,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 164,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 165,                /* TURQUOISE  */
  YYSYMBOL_TAN = 166,                      /* TAN  */
  YYSYMBOL_PINK = 167,                     /* PINK  */
  YYSYMBOL_PEACH = 168,                    /* PEACH  */
  YYSYMBOL_OLIVE = 169,                    /* OLIVE  */
  YYSYMBOL_Identifier = 170,               /* Identifier  */
  YYSYMBOL_String = 171,                   /* String  */
  YYSYMBOL_Integer = 172,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 173,                 /* $accept  */
  YYSYMBOL_expr = 174,                     /* expr  */
  YYSYMBOL_expr_math = 175,                /* expr_math  */
  YYSYMBOL_term = 176,                     /* term  */
  YYSYMBOL_modula = 177,                   /* modula  */
  YYSYMBOL_factor = 178,                   /* factor  */
  YYSYMBOL_direct_integer = 179,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 180, /* random_definition_simple  */
  YYSYMBOL_random_definition = 181,        /* random_definition  */
  YYSYMBOL_color_enumeration = 182,        /* color_enumeration  */
  YYSYMBOL_exponential = 183,              /* exponential  */
  YYSYMBOL_184_1 = 184,                    /* $@1  */
  YYSYMBOL_185_2 = 185,                    /* $@2  */
  YYSYMBOL_position = 186,                 /* position  */
  YYSYMBOL_bank_definition_simple = 187,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 188, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 189,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 190, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 191, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 192,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 193, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 194, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 195,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 196,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 197, /* color_definition_expression  */
  YYSYMBOL_color_definition = 198,         /* color_definition  */
  YYSYMBOL_milliseconds = 199,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 200,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 201, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 202,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 203, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 204, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 205,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 206, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 207, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 208,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 209, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 210, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 211,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 212,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 213, /* text_definition_expression  */
  YYSYMBOL_text_definition = 214,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 215,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 216, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 217,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 218, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 219, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 220,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 221, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 222, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 223,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 224,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 225,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 226,         /* gosub_definition  */
  YYSYMBOL_var_definition = 227,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 228,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 229, /* point_definition_expression  */
  YYSYMBOL_point_definition = 230,         /* point_definition  */
  YYSYMBOL_ink_definition = 231,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 232,       /* on_goto_definition  */
  YYSYMBOL_233_3 = 233,                    /* $@3  */
  YYSYMBOL_on_gosub_definition = 234,      /* on_gosub_definition  */
  YYSYMBOL_235_4 = 235,                    /* $@4  */
  YYSYMBOL_on_definition = 236,            /* on_definition  */
  YYSYMBOL_237_5 = 237,                    /* $@5  */
  YYSYMBOL_238_6 = 238,                    /* $@6  */
  YYSYMBOL_every_definition = 239,         /* every_definition  */
  YYSYMBOL_add_definition = 240,           /* add_definition  */
  YYSYMBOL_dimensions = 241,               /* dimensions  */
  YYSYMBOL_datatype = 242,                 /* datatype  */
  YYSYMBOL_dim_definition = 243,           /* dim_definition  */
  YYSYMBOL_244_7 = 244,                    /* $@7  */
  YYSYMBOL_245_8 = 245,                    /* $@8  */
  YYSYMBOL_246_9 = 246,                    /* $@9  */
  YYSYMBOL_dim_definitions = 247,          /* dim_definitions  */
  YYSYMBOL_indexes = 248,                  /* indexes  */
  YYSYMBOL_statement = 249,                /* statement  */
  YYSYMBOL_250_10 = 250,                   /* $@10  */
  YYSYMBOL_251_11 = 251,                   /* $@11  */
  YYSYMBOL_252_12 = 252,                   /* $@12  */
  YYSYMBOL_253_13 = 253,                   /* $@13  */
  YYSYMBOL_statements_no_linenumbers = 254, /* statements_no_linenumbers  */
  YYSYMBOL_255_14 = 255,                   /* $@14  */
  YYSYMBOL_statements_with_linenumbers = 256, /* statements_with_linenumbers  */
  YYSYMBOL_257_15 = 257,                   /* $@15  */
  YYSYMBOL_statements_complex = 258,       /* statements_complex  */
  YYSYMBOL_program = 259,                  /* program  */
  YYSYMBOL_260_16 = 260                    /* $@16  */
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
#define YYLAST   1875

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  173
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  88
/* YYNRULES -- Number of rules.  */
#define YYNRULES  375
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  740

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   427


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
     165,   166,   167,   168,   169,   170,   171,   172
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
     964,   968,   968,   973,   977,   977,   982,   982,   985,   985,
     990,   993,   996,  1001,  1004,  1010,  1014,  1021,  1024,  1027,
    1030,  1033,  1036,  1039,  1042,  1045,  1048,  1053,  1053,  1061,
    1061,  1069,  1069,  1080,  1081,  1085,  1089,  1096,  1097,  1098,
    1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,
    1109,  1110,  1111,  1112,  1115,  1118,  1121,  1124,  1127,  1130,
    1133,  1136,  1139,  1142,  1142,  1147,  1150,  1153,  1156,  1159,
    1162,  1165,  1168,  1171,  1174,  1177,  1180,  1183,  1186,  1189,
    1192,  1195,  1196,  1197,  1198,  1199,  1202,  1205,  1208,  1211,
    1214,  1217,  1220,  1221,  1224,  1233,  1242,  1242,  1254,  1254,
    1271,  1271,  1288,  1291,  1292,  1296,  1297,  1297,  1301,  1301,
    1308,  1309,  1310,  1311,  1315,  1315
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
  "TIMER", "POWERING", "DIM", "ADDRESS", "MILLISECOND", "MILLISECONDS",
  "TICKS", "BLACK", "WHITE", "RED", "CYAN", "VIOLET", "GREEN", "BLUE",
  "YELLOW", "ORANGE", "BROWN", "LIGHT", "DARK", "GREY", "GRAY", "MAGENTA",
  "PURPLE", "LAVENDER", "GOLD", "TURQUOISE", "TAN", "PINK", "PEACH",
  "OLIVE", "Identifier", "String", "Integer", "$accept", "expr",
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
  "on_definition", "$@5", "$@6", "every_definition", "add_definition",
  "dimensions", "datatype", "dim_definition", "$@7", "$@8", "$@9",
  "dim_definitions", "indexes", "statement", "$@10", "$@11", "$@12",
  "$@13", "statements_no_linenumbers", "$@14",
  "statements_with_linenumbers", "$@15", "statements_complex", "program",
  "$@16", YY_NULLPTR
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
     425,   426,   427
};
#endif

#define YYPACT_NINF (-608)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-357)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -608,    33,   695,  -608,  -608,  -105,   -92,   -19,  -608,    38,
    1325,    67,   -20,  1325,  -608,    16,   121,  1451,   -49,   -45,
    -608,  -608,  -608,  1048,   125,    -5,  1451,    56,    95,  -608,
     153,   155,  1451,  1451,  -608,   176,   178,   -31,  -608,  -608,
     136,  -608,   -50,  -608,  1451,    39,  1199,   180,    49,  1451,
      53,   124,  -608,   220,   227,   229,  -608,  -608,  -608,  1325,
     219,  -608,  -608,  -608,  1325,  1325,  1325,  -608,  -608,  -608,
      72,   897,  -608,  -608,   214,   221,   222,    23,    85,  -608,
    -608,   225,   226,  1451,  -608,  -608,   230,   257,   258,   259,
     260,   261,   262,   263,   265,   266,   267,   268,   269,   270,
     271,   272,   273,  -608,  -608,   274,  -608,  -608,  -608,  -608,
    -608,  -608,  -608,   102,  -608,  -608,    86,   -91,  -608,  -608,
    -608,  -608,  -608,  -608,  -608,  -608,  -608,   109,   104,  -608,
    -608,   -53,    29,   179,   165,   181,   -29,  -608,  -608,  -608,
    -608,  -608,   -18,   235,   -16,   -15,   -13,    -9,   287,  -608,
    -608,  -608,   156,   171,  -608,  -608,  -608,  1325,  -608,  -608,
     283,  -608,  -608,  -608,  -608,  -608,  1325,   275,   276,  -608,
    -608,  -608,   -25,  -608,    68,  -608,  -608,  -608,  -608,  -608,
    1451,  1451,  -608,  -608,   311,  -608,  -608,  -608,  1325,  -608,
    -608,  -608,  1325,   290,  -608,  -608,  -608,   251,  -608,  -608,
    1451,  1451,  -608,  -608,  1325,  -608,  -608,  -608,   289,  -608,
    -608,  -608,  -608,  -608,  -608,  1451,  1451,  -608,  -608,  -608,
     312,  -608,  -608,   182,  -608,  1451,   317,  -608,  -608,  -608,
       0,   319,  -608,  -608,  1451,   314,   295,     5,   813,  -608,
     695,   695,   301,   302,  1325,  -608,  -608,   264,   277,   278,
     279,  -608,   298,   299,   300,   303,   304,    94,   305,  1325,
    1325,  1325,  -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,
    -608,  -608,  1451,  1451,  -608,  1451,  1451,  1451,  1451,  1451,
    1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,  1451,
    1451,  1451,  1577,  -608,  -608,  -608,  -608,  -608,  -608,  -608,
    -608,   307,   308,  -608,  -608,  -608,  -608,  -608,  -608,  1577,
    1577,  1577,  1577,  1577,  1577,  1577,  1577,  1577,  1577,  1577,
    1577,  1577,  1703,  -608,  -608,  -608,  1325,   313,  -608,  -608,
    -608,   296,   235,   321,   235,   322,   235,   323,   235,   324,
     235,  -608,  1451,   310,  -608,  -608,    45,   142,    88,    91,
    -608,  -608,  -608,   318,   235,   320,  -608,  -608,   161,   173,
     108,   122,  -608,  -608,   325,  -608,  -608,  1325,  -608,  -608,
    1325,  1325,  -608,  -608,   316,   184,  -608,   348,  1451,  -608,
    -608,  -608,  -608,  1325,  -608,   349,   355,  -608,  -608,  1325,
     294,   357,  1451,   281,   358,  1451,  -608,  -608,  -608,  -608,
    -608,  -608,    98,  -608,  -608,   332,   347,    53,  -608,  1451,
     335,  1451,   336,  -608,   813,  -608,  -608,   201,   202,  -608,
    -608,  1451,   235,  1451,   235,   203,   204,   205,   206,   209,
     339,   352,   354,  -608,   356,   360,   361,   362,   363,   365,
     377,   386,   394,   395,   368,   369,   370,   371,   400,   374,
     375,   379,   380,   381,   405,   410,   383,   384,   385,     3,
     388,  1451,   179,   179,   232,   232,   232,   232,   232,   232,
     232,   232,   165,   181,   181,  -608,   397,   398,  1325,    34,
    -608,   235,  -608,   235,  -608,   235,  -608,   235,    57,  -608,
    1451,  -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,  1451,
    -608,   235,  -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,
     235,  -608,  -608,  -608,  -608,  -608,  -608,   253,   280,   282,
     415,  1451,   422,   389,   390,  1451,  1451,   423,   426,  -608,
     -68,   364,   284,  1451,   427,  -608,  -608,  -608,   401,   285,
     404,  -608,  -608,  1451,   432,   406,  1451,  -608,  -608,  -608,
    -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,   286,
     288,   291,  -608,  -608,  -608,  -608,  -608,  -608,  1451,  1451,
    1451,  1451,  -608,  -608,  -608,  -608,  1451,  -608,  -608,  -608,
    -608,  -608,  1451,  1451,  -608,  -608,  -608,  1703,  1451,   407,
     292,   297,  -608,  -608,  -608,  -608,  -608,  -608,   411,  -608,
     416,  -608,   293,    82,  -608,   437,  -608,   439,   440,  -608,
     441,  -608,   436,  1325,   444,  1451,  1451,   235,   418,   420,
    1451,   235,  -608,  -608,  1451,  -608,    28,  1451,   285,   449,
     424,   285,   430,  1451,   448,   431,  -608,  -608,  -608,   434,
     435,    35,    65,   438,   442,   446,   447,   450,  -608,  -608,
    -608,   315,   326,  -608,   443,  -608,   445,  -608,  1451,   235,
     464,   468,  1451,  -608,  -608,  1451,  -608,  -608,  -608,   466,
     470,   452,   453,   376,  1451,   471,   421,   455,   285,  -608,
     457,   481,  -608,  1451,   482,  -608,  -608,  1451,  -608,  1451,
    -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,   327,   328,
     461,   465,   253,   280,  -608,  -608,  1451,  1451,  -608,  -608,
    1451,   467,  1451,  1451,  -608,  -608,  -608,  1451,  -608,  1451,
     469,   472,  -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,
    -608,   488,  -608,  -608,  -608,  -608,  -608,  -608,  1451,  -608
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     374,     0,   364,     1,   363,     0,     0,     0,   347,     0,
       0,   335,     0,     0,   340,     0,     0,     0,   244,     0,
     322,   326,   323,     0,     0,     0,     0,     0,     0,   320,
       0,     0,     0,   315,   339,     0,     0,     0,   345,   346,
     318,   321,   328,   325,     0,     0,     0,     0,     0,     0,
       0,   360,   368,   365,   370,   372,   375,   313,   314,     0,
       0,   145,   146,   298,     0,     0,     0,   159,   160,   300,
       0,     0,    79,    80,     0,     0,     0,     0,     0,   111,
     112,     0,     0,     0,   108,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,   113,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,    44,    49,
      50,    51,    52,    53,    54,    57,    58,     0,    63,    67,
      65,     0,     2,    12,    15,    17,     0,    76,    20,   170,
     171,   301,     0,     0,     0,     0,     0,     0,     0,   139,
     140,   297,     0,     0,   202,   203,   302,     0,   205,   206,
     207,   211,   212,   303,   234,   235,     0,     0,     0,   242,
     243,   308,     0,   341,     0,   254,   311,   250,   251,   342,
       0,     0,   217,   218,     0,   221,   222,   305,     0,   225,
     226,   306,     0,   228,   232,   233,   307,     0,   337,   338,
       0,     0,   362,   316,     0,   215,   216,   304,     0,   257,
     258,   309,   252,   253,   343,     0,     0,   330,   331,   327,
       0,   271,   272,     0,   344,     0,     0,   312,   259,   310,
     287,   293,   352,   353,     0,   358,     0,     0,   364,   366,
     364,   364,     0,     0,     0,   156,   153,     0,     0,     0,
       0,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    24,    25,    27,    29,    30,    26,    31,
     101,    23,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    42,    45,    46,    47,    48,    43,
      56,    64,     0,   161,   167,   162,   163,   168,   169,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   164,   165,   166,     0,     0,   151,   152,
     299,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,     0,     0,   192,   193,     0,     0,     0,     0,
     189,   188,   114,     0,     0,     0,   177,   178,     0,     0,
       0,     0,   174,   173,     0,   209,   204,     0,   239,   236,
       0,     0,   266,   268,     0,     0,   324,     0,     0,   224,
     223,   230,   227,     0,   317,     0,     0,   214,   213,     0,
       0,   329,     0,     0,     0,     0,   285,   277,   279,   284,
     281,   286,     0,   283,   291,     0,     0,     0,   354,     0,
       0,     0,     0,   369,   364,   371,   373,     0,     0,   143,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    14,     5,     7,     8,     9,    10,     6,
       3,     4,    16,    18,    19,    21,     0,     0,     0,     0,
     121,     0,   133,     0,   125,     0,   129,     0,   117,   190,
       0,   197,   196,   201,   200,   195,   199,   194,   198,     0,
     175,     0,   182,   181,   186,   185,   180,   184,   179,   183,
       0,   210,   208,   240,   237,   241,   238,     0,     0,     0,
     245,     0,     0,     0,     0,     0,     0,     0,     0,   319,
       0,     0,     0,     0,   273,   278,   280,   282,     0,     0,
       0,   294,   355,     0,   295,     0,     0,   367,   144,   142,
     158,   155,   157,   154,    75,    68,    70,    74,    72,     0,
       0,     0,    78,    77,    82,    81,    84,    83,     0,     0,
       0,     0,    91,    92,    93,   100,     0,    94,    95,    96,
      97,    98,     0,     0,   106,   107,   102,     0,     0,     0,
       0,     0,   149,   147,   118,   131,   123,   126,   120,   132,
     124,   128,     0,     0,   187,     0,   172,     0,   260,   267,
     263,   269,   246,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   332,   333,     0,   270,     0,     0,     0,   275,
       0,     0,     0,     0,     0,     0,    69,    71,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,   150,
     148,     0,     0,   134,   119,   130,   122,   127,     0,     0,
       0,     0,     0,   248,   247,     0,   220,   231,   229,     0,
       0,     0,     0,   334,     0,     0,     0,     0,     0,   288,
       0,     0,   296,     0,     0,    85,    86,     0,    87,     0,
      89,    99,   105,   104,    22,    62,   136,   138,     0,     0,
       0,     0,     0,     0,   249,   219,     0,     0,   256,   255,
       0,     0,     0,     0,   292,   276,   290,     0,   357,     0,
       0,     0,   135,   137,   191,   176,   262,   265,   348,   349,
     336,     0,   350,   274,   359,   361,    88,    90,     0,   351
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -608,   -10,   -28,  -215,   186,  -261,    54,  -608,  -608,  -608,
    -305,  -608,  -608,   350,  -608,  -608,  -608,  -608,  -608,  -608,
    -608,  -608,  -608,  -608,  -608,  -608,   372,  -608,  -608,  -608,
    -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,
    -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,
    -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,  -608,  -196,
    -608,  -194,  -608,  -608,  -608,  -608,  -608,  -608,  -607,   306,
    -608,  -608,  -608,  -608,   103,  -459,  -608,  -608,  -608,  -608,
    -608,  -237,  -608,  -608,  -608,    12,  -608,  -608
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   544,   132,   133,   134,   135,   136,   269,   270,   137,
     138,   302,   460,   353,   149,   150,   151,    61,    62,    63,
     328,   329,   330,    67,    68,    69,   308,   139,   140,   141,
     154,   155,   156,   161,   162,   163,   205,   206,   207,   185,
     186,   187,   189,   190,   191,   194,   195,   196,   169,   170,
     171,   175,   179,   214,   176,   209,   210,   211,   229,   609,
     660,   611,   661,   173,   517,   518,   224,   227,   630,   404,
     231,   405,   406,   538,   232,   545,    53,   180,   236,   410,
     237,    54,   414,    55,   238,    56,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     131,   413,   589,   152,   143,    59,   326,   172,   332,   334,
     587,   336,   144,   184,    78,   338,   197,   475,   216,   192,
    -289,   677,   202,   203,   680,   396,   303,   304,   372,   145,
     396,   459,    78,     3,   219,   674,   223,   309,   310,   228,
     157,   311,   687,   312,   313,   314,   315,   316,   262,   242,
     303,   323,   158,   159,   245,   247,   249,   146,   147,   473,
     474,   258,   298,   675,    64,    57,   594,   153,   299,    65,
     688,   715,   689,   274,   397,   398,   399,   373,    58,   397,
     398,   399,   193,   595,   632,   400,   602,   635,   374,   142,
     400,   305,   306,   307,   462,   463,   218,   263,   264,   265,
     690,   491,   492,   160,   622,   603,   266,   267,   268,    66,
     375,   596,   597,   243,   654,   305,   306,   324,   246,   248,
     250,   174,   217,   401,   301,   177,   317,   178,   401,   647,
     233,   655,   322,   495,   318,   402,   497,   234,   -59,   212,
     402,   213,   496,   403,   235,   498,   198,   365,   403,   188,
     148,    60,   327,   506,   333,   335,   368,   337,  -356,   656,
     657,   339,   507,   164,   165,   166,   167,   508,   430,   431,
     376,   377,   535,   536,   682,   168,   509,   547,   379,   432,
     341,   342,   381,   537,   320,   199,   321,   200,   343,   201,
     385,   386,   344,   345,   387,   341,   354,   331,   493,   494,
     204,   346,   208,   355,   215,   390,   391,   356,   357,   220,
     347,   366,   348,   349,   225,   394,   358,   502,   503,   226,
     369,   350,   351,   230,   408,   359,   239,   360,   361,   504,
     505,   240,   352,   241,   419,   294,   362,   363,   295,   296,
     309,   310,   380,   244,   251,   297,   382,   352,   259,   434,
     436,   438,   415,   416,   293,   260,   261,   271,   388,   272,
     273,   300,   440,   441,   275,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   646,   464,   465,   466,   467,   468,   469,   470,
     471,   276,   277,   278,   279,   280,   281,   282,   420,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   319,
     322,   340,   367,   435,   437,   439,   476,    78,   378,   383,
     384,   370,   371,   389,   395,   392,   407,   409,   393,   411,
     417,   418,   489,   425,   426,   427,   421,   478,   428,   429,
     433,   -61,   461,   490,   479,   481,   483,   485,   487,   422,
     423,   424,   499,   501,   520,   521,   525,   511,   519,   510,
     513,   515,   526,   529,   530,   533,   539,   540,   522,   543,
     546,   548,   549,   523,   559,   554,   555,   556,   557,   527,
     477,   558,   531,   532,   568,   534,   480,   560,   482,   561,
     484,   562,   486,   569,   488,   563,   564,   565,   566,   542,
     567,   570,   571,   572,   573,   574,   575,   576,   500,   577,
     578,   550,   582,   552,   579,   580,   581,   583,   584,   585,
     586,   512,   588,   608,   514,   516,   590,   591,   613,   615,
     620,   616,   617,   621,   627,   628,   624,   524,   631,   633,
     651,   634,   648,   528,   658,   652,   659,  -261,  -264,   662,
     610,   665,   612,   669,   625,   670,   678,   629,   636,   679,
     637,   683,   649,   638,   653,   681,   684,   650,   592,   685,
     686,   702,   698,   691,   699,   703,   551,   692,   553,   706,
     604,   693,   694,   707,   712,   695,   696,   708,   709,   605,
     714,   710,   716,   713,   717,   719,   724,   697,   722,   723,
     725,   738,   731,   364,   736,   472,   726,   737,   325,   727,
     541,   614,     0,     0,     0,   618,   619,     0,     0,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,     0,
       0,     0,   593,     0,     0,   598,     0,   599,     0,   600,
       0,   601,     0,   412,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   606,     0,     0,   639,   640,
     641,   642,     0,     0,   607,     0,   643,     0,     0,     0,
       0,     0,   644,   645,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   623,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   663,     0,   666,   667,     0,     0,     0,
     671,     0,     0,     0,   673,     0,     0,   676,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   700,     0,
       0,     0,   704,     0,     0,   705,     0,     0,     0,     0,
       0,     0,     0,     0,   711,     0,     0,   664,     0,     0,
       0,   668,     0,   718,     0,   672,     0,   720,     0,   721,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   728,   729,     4,     0,
     730,     0,   732,   733,     0,     5,     6,   734,     0,   735,
       0,     0,     0,   701,     0,     0,     0,     7,     8,     0,
       9,     0,    10,    11,     0,    12,    13,     0,   739,     0,
       0,     0,     0,    14,     0,    15,    16,    17,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    28,     0,    29,     0,     0,    30,
      31,    32,     0,    33,    34,    35,    36,    37,    38,    39,
       0,    40,     0,     0,     0,    41,    42,    43,    44,    45,
       0,    46,    47,     0,     0,     0,     4,     0,     0,     0,
       0,     0,     0,     5,     6,     0,    48,     0,     0,     0,
       0,     0,     0,     0,    49,     7,     8,    50,     9,     0,
      10,    11,     0,    12,    13,     0,     0,     0,     0,     0,
       0,    14,     0,    15,    16,    17,     0,     0,     0,     0,
      18,     0,     0,     0,     0,    51,    19,    52,     0,     0,
       0,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,    29,     0,    70,    30,    31,    32,
       0,    33,    34,    35,    36,    37,    38,    39,     0,    40,
       0,     0,   252,    41,    42,    43,    44,    45,     0,    46,
      47,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,    72,    73,    74,
       0,     0,    49,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,    75,     0,     0,    76,     0,     0,
      77,   253,   254,   255,     0,     0,     0,     0,     0,     0,
      79,    80,   256,    51,     0,     0,     0,     0,     0,     0,
       0,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    85,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     0,     0,     0,    98,
      99,   100,   257,   101,   102,   103,     0,   104,   105,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    70,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
       0,     0,   181,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,     0,   182,   183,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,     0,     0,    76,     0,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,    84,    85,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,     0,     0,     0,
      98,    99,   100,     0,   101,   102,   103,     0,   104,   105,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    70,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,     0,     0,     0,     0,     0,     0,
       0,   221,   222,     0,     0,     0,     0,     0,     0,    72,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,     0,     0,    76,
       0,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,    85,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,     0,     0,
       0,    98,    99,   100,    70,   101,   102,   103,     0,   104,
     105,     0,     0,     0,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    71,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,     0,     0,     0,    72,    73,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,     0,     0,    76,     0,     0,    77,     0,
       0,     0,     0,     0,     0,     0,     0,    78,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    99,   100,
      70,   101,   102,   103,     0,   104,   105,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    71,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     0,     0,
       0,    72,    73,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    75,     0,
       0,    76,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
       0,     0,     0,    98,    99,   100,    70,   101,   102,   103,
       0,   104,   105,     0,     0,     0,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    71,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     0,     0,     0,    72,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,     0,     0,    76,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     0,     0,     0,    98,
      99,   100,    70,   101,   102,   103,     0,   104,   105,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    71,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
       0,     0,     0,    72,    73,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,     0,     0,    76,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    85,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,     0,     0,     0,    98,    99,   100,     0,   101,
     102,   103,     0,   104,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130
};

static const yytype_int16 yycheck[] =
{
      10,   238,   461,    13,    24,    24,    24,    17,    24,    24,
       7,    24,    32,    23,    82,    24,    26,   322,    68,    24,
      20,   628,    32,    33,   631,    25,    79,    80,    53,    49,
      25,   292,    82,     0,    44,     7,    46,     8,     9,    49,
      24,    12,     7,    14,    15,    16,    17,    18,    25,    59,
      79,    80,    36,    37,    64,    65,    66,    77,    78,   320,
     321,    71,   153,    35,    26,   170,    32,    13,   159,    31,
      35,   678,     7,    83,    74,    75,    76,   102,   170,    74,
      75,    76,    87,    49,   543,    85,    29,   546,    20,    22,
      85,   144,   145,   146,   309,   310,    42,    74,    75,    76,
      35,    56,    57,    87,   172,    48,    83,    84,    85,    71,
      42,    77,    78,    59,    32,   144,   145,   146,    64,    65,
      66,   170,   172,   123,    20,   170,    97,   172,   123,   588,
       6,    49,   129,    45,   105,   135,    45,    13,    34,   170,
     135,   172,    54,   143,    20,    54,    90,   157,   143,    24,
     170,   170,   170,    45,   170,   170,   166,   170,    34,    77,
      78,   170,    54,    42,    43,    44,    45,    45,    74,    75,
     180,   181,    74,    75,   633,    54,    54,   414,   188,    85,
      24,    25,   192,    85,    19,    90,    21,    34,    32,    34,
     200,   201,    36,    37,   204,    24,    25,   143,    56,    57,
      24,    45,    24,    32,    68,   215,   216,    36,    37,   170,
      54,   157,    56,    57,    34,   225,    45,    56,    57,   170,
     166,    65,    66,   170,   234,    54,     6,    56,    57,    56,
      57,     4,    76,     4,   244,   149,    65,    66,   152,   153,
       8,     9,   188,    24,   172,   159,   192,    76,    34,   259,
     260,   261,   240,   241,   152,    34,    34,   172,   204,    34,
      34,   152,   272,   273,    34,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   587,   311,   312,   313,   314,   315,   316,   317,
     318,    34,    34,    34,    34,    34,    34,    34,   244,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,   130,
     129,    24,    29,   259,   260,   261,   326,    82,     7,    29,
      69,    46,    46,    34,     7,    13,     7,    13,   146,    34,
      29,    29,   342,    35,    35,    35,    72,    24,    35,    35,
      35,    34,    34,    33,    48,    24,    24,    24,    24,    72,
      72,    72,    34,    33,   170,     7,     7,   367,    42,    34,
     370,   371,     7,    69,     7,     7,    34,    20,   378,    34,
      34,   170,   170,   383,    35,   172,   172,   172,   172,   389,
     326,   172,   392,   102,     7,   395,   332,    35,   334,    35,
     336,    35,   338,     7,   340,    35,    35,    35,    35,   409,
      35,     7,     7,    35,    35,    35,    35,     7,   354,    35,
      35,   421,     7,   423,    35,    35,    35,     7,    35,    35,
      35,   367,    34,   170,   370,   371,    29,    29,    13,     7,
       7,    42,    42,     7,     7,    34,    72,   383,    34,     7,
      29,    35,    35,   389,     7,    29,     7,     7,     7,    13,
     170,     7,   170,    35,   170,    35,     7,   172,   172,    35,
     172,    13,   170,   172,   171,    35,    35,   170,   478,    35,
      35,     7,    29,    35,    29,     7,   422,    35,   424,    13,
     490,    35,    35,    13,    13,    35,   171,    35,    35,   499,
      35,   115,    35,    72,    13,    13,    35,   171,   171,   171,
      35,    13,    35,   153,    35,   319,   702,    35,   136,   703,
     407,   521,    -1,    -1,    -1,   525,   526,    -1,    -1,    -1,
      -1,    -1,    -1,   533,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   478,    -1,    -1,   481,    -1,   483,    -1,   485,
      -1,   487,    -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   501,    -1,    -1,   568,   569,
     570,   571,    -1,    -1,   510,    -1,   576,    -1,    -1,    -1,
      -1,    -1,   582,   583,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   530,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   613,    -1,   615,   616,    -1,    -1,    -1,
     620,    -1,    -1,    -1,   624,    -1,    -1,   627,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   658,    -1,
      -1,    -1,   662,    -1,    -1,   665,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   674,    -1,    -1,   613,    -1,    -1,
      -1,   617,    -1,   683,    -1,   621,    -1,   687,    -1,   689,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   706,   707,     3,    -1,
     710,    -1,   712,   713,    -1,    10,    11,   717,    -1,   719,
      -1,    -1,    -1,   659,    -1,    -1,    -1,    22,    23,    -1,
      25,    -1,    27,    28,    -1,    30,    31,    -1,   738,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    42,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    91,    -1,    -1,    94,
      95,    96,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
      -1,   116,   117,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    22,    23,   142,    25,    -1,
      27,    28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,   170,    53,   172,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    -1,    91,    -1,     9,    94,    95,    96,
      -1,    98,    99,   100,   101,   102,   103,   104,    -1,   106,
      -1,    -1,    25,   110,   111,   112,   113,   114,    -1,   116,
     117,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,    -1,    -1,    50,    51,    52,
      -1,    -1,   139,    -1,    -1,   142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,   170,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,   135,   136,   137,   138,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     9,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
     132,   133,   134,    -1,   136,   137,   138,    -1,   140,   141,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,     9,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   132,   133,   134,     9,   136,   137,   138,    -1,   140,
     141,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,    34,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    50,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,   132,   133,   134,
       9,   136,   137,   138,    -1,   140,   141,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,    34,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,   132,   133,   134,     9,   136,   137,   138,
      -1,   140,   141,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    34,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,   132,
     133,   134,     9,   136,   137,   138,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,    34,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
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
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    -1,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   259,   260,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    88,    89,    91,
      94,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     106,   110,   111,   112,   113,   114,   116,   117,   131,   139,
     142,   170,   172,   249,   254,   256,   258,   170,   170,    24,
     170,   190,   191,   192,    26,    31,    71,   196,   197,   198,
       9,    34,    50,    51,    52,    67,    70,    73,    82,    83,
      84,    94,    95,   107,   108,   109,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   132,   133,
     134,   136,   137,   138,   140,   141,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   174,   175,   176,   177,   178,   179,   182,   183,   200,
     201,   202,    22,    24,    32,    49,    77,    78,   170,   187,
     188,   189,   174,   179,   203,   204,   205,    24,    36,    37,
      87,   206,   207,   208,    42,    43,    44,    45,    54,   221,
     222,   223,   174,   236,   170,   224,   227,   170,   172,   225,
     250,    24,    36,    37,   174,   212,   213,   214,    24,   215,
     216,   217,    24,    87,   218,   219,   220,   174,    90,    90,
      34,    34,   174,   174,    24,   209,   210,   211,    24,   228,
     229,   230,   170,   172,   226,    68,    68,   172,   179,   174,
     170,    42,    43,   174,   239,    34,   170,   240,   174,   231,
     170,   243,   247,     6,    13,    20,   251,   253,   257,     6,
       4,     4,   174,   179,    24,   174,   179,   174,   179,   174,
     179,   172,    25,    74,    75,    76,    85,   135,   174,    34,
      34,    34,    25,    74,    75,    76,    83,    84,    85,   180,
     181,   172,    34,    34,   174,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,   152,   149,   152,   153,   159,   153,   159,
     152,    20,   184,    79,    80,   144,   145,   146,   199,     8,
       9,    12,    14,    15,    16,    17,    18,    97,   105,   130,
      19,    21,   129,    80,   146,   199,    24,   170,   193,   194,
     195,   179,    24,   170,    24,   170,    24,   170,    24,   170,
      24,    24,    25,    32,    36,    37,    45,    54,    56,    57,
      65,    66,    76,   186,    25,    32,    36,    37,    45,    54,
      56,    57,    65,    66,   186,   174,   179,    29,   174,   179,
      46,    46,    53,   102,    20,    42,   174,   174,     7,   174,
     179,   174,   179,    29,    69,   174,   174,   174,   179,    34,
     174,   174,    13,   146,   174,     7,    25,    74,    75,    76,
      85,   123,   135,   143,   242,   244,   245,     7,   174,    13,
     252,    34,   242,   254,   255,   258,   258,    29,    29,   174,
     179,    72,    72,    72,    72,    35,    35,    35,    35,    35,
      74,    75,    85,    35,   174,   179,   174,   179,   174,   179,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   178,
     185,    34,   176,   176,   175,   175,   175,   175,   175,   175,
     175,   175,   177,   178,   178,   183,   174,   179,    24,    48,
     179,    24,   179,    24,   179,    24,   179,    24,   179,   174,
      33,    56,    57,    56,    57,    45,    54,    45,    54,    34,
     179,    33,    56,    57,    56,    57,    45,    54,    45,    54,
      34,   174,   179,   174,   179,   174,   179,   237,   238,    42,
     170,     7,   174,   174,   179,     7,     7,   174,   179,    69,
       7,   174,   102,     7,   174,    74,    75,    85,   246,    34,
      20,   247,   174,    34,   174,   248,    34,   254,   170,   170,
     174,   179,   174,   179,   172,   172,   172,   172,   172,    35,
      35,    35,    35,    35,    35,    35,    35,    35,     7,     7,
       7,     7,    35,    35,    35,    35,     7,    35,    35,    35,
      35,    35,     7,     7,    35,    35,    35,     7,    34,   248,
      29,    29,   174,   179,    32,    49,    77,    78,   179,   179,
     179,   179,    29,    48,   174,   174,   179,   179,   170,   232,
     170,   234,   170,    13,   174,     7,    42,    42,   174,   174,
       7,     7,   172,   179,    72,   170,   174,     7,    34,   172,
     241,    34,   248,     7,    35,   248,   172,   172,   172,   174,
     174,   174,   174,   174,   174,   174,   183,   248,    35,   170,
     170,    29,    29,   171,    32,    49,    77,    78,     7,     7,
     233,   235,    13,   174,   179,     7,   174,   174,   179,    35,
      35,   174,   179,   174,     7,    35,   174,   241,     7,    35,
     241,    35,   248,    13,    35,    35,    35,     7,    35,     7,
      35,    35,    35,    35,    35,    35,   171,   171,    29,    29,
     174,   179,     7,     7,   174,   174,    13,    13,    35,    35,
     115,   174,    13,    72,    35,   241,    35,    13,   174,    13,
     174,   174,   171,   171,    35,    35,   232,   234,   174,   174,
     174,    35,   174,   174,   174,   174,    35,    35,    13,   174
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   173,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   175,   175,   175,   176,   176,   177,   177,   177,
     178,   178,   178,   179,   180,   180,   180,   180,   180,   180,
     180,   181,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   184,
     183,   185,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   186,   186,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   188,   188,   188,   188,   188,   189,
     189,   190,   190,   191,   191,   192,   192,   193,   193,   194,
     194,   195,   195,   196,   196,   196,   197,   197,   197,   198,
     198,   199,   199,   199,   200,   200,   200,   201,   201,   201,
     202,   202,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   205,   205,   206,   206,   206,   206,   206,   207,
     207,   208,   208,   209,   210,   211,   211,   212,   212,   213,
     213,   214,   214,   215,   216,   217,   217,   218,   218,   218,
     219,   219,   220,   220,   221,   221,   221,   221,   221,   222,
     222,   222,   223,   223,   224,   224,   224,   224,   224,   224,
     225,   225,   226,   226,   227,   228,   229,   230,   230,   231,
     232,   233,   232,   234,   235,   234,   237,   236,   238,   236,
     239,   239,   239,   240,   240,   241,   241,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   244,   243,   245,
     243,   246,   243,   247,   247,   248,   248,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   250,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   251,   249,   252,   249,
     253,   249,   249,   249,   249,   254,   255,   254,   257,   256,
     258,   258,   258,   258,   260,   259
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
       1,     0,     4,     1,     0,     4,     0,     4,     0,     4,
       4,     1,     1,     3,     7,     1,     3,     1,     2,     1,
       2,     1,     2,     1,     1,     1,     1,     0,     5,     0,
       6,     0,     6,     1,     3,     1,     3,     2,     2,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     2,     3,     1,     4,
       1,     1,     1,     0,     3,     1,     1,     2,     1,     3,
       2,     2,     5,     5,     6,     1,     8,     2,     2,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     8,     8,
       8,    10,     2,     2,     3,     4,     0,     7,     0,     8,
       0,     8,     2,     1,     0,     1,     0,     4,     0,     3,
       1,     3,     1,     3,     0,     2
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
#line 2494 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 77 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2503 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 81 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2511 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 84 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2519 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 87 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2527 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 90 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2535 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 93 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2543 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 96 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2551 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 99 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2559 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 106 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2567 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 109 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2576 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 122 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2585 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 126 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2594 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 134 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2603 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 138 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 2612 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 145 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2620 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 150 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2628 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 153 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2636 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 156 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2644 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 159 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2652 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 162 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2660 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 165 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2668 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 168 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2676 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 173 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2684 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 178 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2693 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 182 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2702 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 186 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2711 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 190 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2720 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 194 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2729 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 198 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2738 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 202 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2747 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 206 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2756 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 210 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2765 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 214 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2774 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 218 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2783 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 222 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2792 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 226 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2801 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 230 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2810 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 234 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2819 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 238 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2828 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 242 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2837 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 246 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2846 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 250 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2855 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 254 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2864 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 258 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2873 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 262 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2882 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 266 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2891 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 270 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2900 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 274 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2909 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 278 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2918 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 282 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2927 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 288 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 2936 "src-generated/ugbc.tab.c"
    break;

  case 60: /* exponential: Identifier $@1 OP indexes CP  */
#line 292 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve( _environment, (yyvsp[-4].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-4].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-4].string) )->name;
    }
#line 2948 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 299 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 2957 "src-generated/ugbc.tab.c"
    break;

  case 62: /* exponential: Identifier DOLLAR $@2 OP indexes CP  */
#line 303 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve( _environment, (yyvsp[-5].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-5].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-5].string) )->name;
    }
#line 2969 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 310 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2977 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 313 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[-1].string);
      }
#line 2985 "src-generated/ugbc.tab.c"
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
#line 2999 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 325 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3008 "src-generated/ugbc.tab.c"
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
#line 3020 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 336 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3029 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 340 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3038 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 344 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3047 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 348 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3056 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 352 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3065 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 356 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3074 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 360 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3083 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 364 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3092 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 368 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3100 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 371 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3108 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 374 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3116 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 377 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3124 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 380 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3132 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 383 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3140 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 386 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3148 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 389 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3156 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 392 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3164 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 395 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3172 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 398 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3180 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 401 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3188 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 404 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3196 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 407 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3204 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 410 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3212 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 413 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3220 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 416 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3228 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 419 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3236 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 422 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3244 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 425 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3252 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 428 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3260 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 431 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3268 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 434 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3276 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 437 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3284 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 440 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3292 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 443 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3300 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 446 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3308 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 449 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3316 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 452 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3324 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 455 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3332 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: SGN OP expr CP  */
#line 458 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3340 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: ABS OP expr CP  */
#line 461 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3348 "src-generated/ugbc.tab.c"
    break;

  case 108: /* exponential: TRUE  */
#line 464 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3357 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: FALSE  */
#line 468 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3366 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: COLORS  */
#line 472 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3375 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: WIDTH  */
#line 476 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3383 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: HEIGHT  */
#line 479 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3391 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: TIMER  */
#line 482 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3399 "src-generated/ugbc.tab.c"
    break;

  case 116: /* bank_definition_simple: AT direct_integer  */
#line 490 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3407 "src-generated/ugbc.tab.c"
    break;

  case 117: /* bank_definition_simple: Identifier AT direct_integer  */
#line 493 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3415 "src-generated/ugbc.tab.c"
    break;

  case 118: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 496 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3423 "src-generated/ugbc.tab.c"
    break;

  case 119: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 499 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3431 "src-generated/ugbc.tab.c"
    break;

  case 120: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 502 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3439 "src-generated/ugbc.tab.c"
    break;

  case 121: /* bank_definition_simple: DATA AT direct_integer  */
#line 505 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3447 "src-generated/ugbc.tab.c"
    break;

  case 122: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 509 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3455 "src-generated/ugbc.tab.c"
    break;

  case 123: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 512 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3463 "src-generated/ugbc.tab.c"
    break;

  case 124: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 515 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3471 "src-generated/ugbc.tab.c"
    break;

  case 125: /* bank_definition_simple: CODE AT direct_integer  */
#line 518 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3479 "src-generated/ugbc.tab.c"
    break;

  case 126: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 522 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3487 "src-generated/ugbc.tab.c"
    break;

  case 127: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 525 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3495 "src-generated/ugbc.tab.c"
    break;

  case 128: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 528 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3503 "src-generated/ugbc.tab.c"
    break;

  case 129: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 531 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3511 "src-generated/ugbc.tab.c"
    break;

  case 130: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 535 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3519 "src-generated/ugbc.tab.c"
    break;

  case 131: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 538 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3527 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 541 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3535 "src-generated/ugbc.tab.c"
    break;

  case 133: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 544 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3543 "src-generated/ugbc.tab.c"
    break;

  case 134: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 550 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3551 "src-generated/ugbc.tab.c"
    break;

  case 135: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 553 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3559 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 556 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3567 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 559 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3575 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 562 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3583 "src-generated/ugbc.tab.c"
    break;

  case 141: /* raster_definition_simple: Identifier AT direct_integer  */
#line 571 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3591 "src-generated/ugbc.tab.c"
    break;

  case 142: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 574 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3599 "src-generated/ugbc.tab.c"
    break;

  case 143: /* raster_definition_expression: Identifier AT expr  */
#line 579 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3607 "src-generated/ugbc.tab.c"
    break;

  case 144: /* raster_definition_expression: AT expr WITH Identifier  */
#line 582 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3615 "src-generated/ugbc.tab.c"
    break;

  case 147: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 591 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3623 "src-generated/ugbc.tab.c"
    break;

  case 148: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 594 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3631 "src-generated/ugbc.tab.c"
    break;

  case 149: /* next_raster_definition_expression: Identifier AT expr  */
#line 599 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3639 "src-generated/ugbc.tab.c"
    break;

  case 150: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 602 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3647 "src-generated/ugbc.tab.c"
    break;

  case 153: /* color_definition_simple: BORDER direct_integer  */
#line 611 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3655 "src-generated/ugbc.tab.c"
    break;

  case 154: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 614 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3663 "src-generated/ugbc.tab.c"
    break;

  case 155: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 617 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3671 "src-generated/ugbc.tab.c"
    break;

  case 156: /* color_definition_expression: BORDER expr  */
#line 622 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3679 "src-generated/ugbc.tab.c"
    break;

  case 157: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 625 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3687 "src-generated/ugbc.tab.c"
    break;

  case 158: /* color_definition_expression: SPRITE expr TO expr  */
#line 628 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3695 "src-generated/ugbc.tab.c"
    break;

  case 164: /* wait_definition_simple: direct_integer CYCLES  */
#line 642 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3703 "src-generated/ugbc.tab.c"
    break;

  case 165: /* wait_definition_simple: direct_integer TICKS  */
#line 645 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3711 "src-generated/ugbc.tab.c"
    break;

  case 166: /* wait_definition_simple: direct_integer milliseconds  */
#line 648 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3719 "src-generated/ugbc.tab.c"
    break;

  case 167: /* wait_definition_expression: expr CYCLES  */
#line 653 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3727 "src-generated/ugbc.tab.c"
    break;

  case 168: /* wait_definition_expression: expr TICKS  */
#line 656 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3735 "src-generated/ugbc.tab.c"
    break;

  case 169: /* wait_definition_expression: expr milliseconds  */
#line 659 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3743 "src-generated/ugbc.tab.c"
    break;

  case 172: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 669 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3751 "src-generated/ugbc.tab.c"
    break;

  case 173: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 672 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3759 "src-generated/ugbc.tab.c"
    break;

  case 174: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 675 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3767 "src-generated/ugbc.tab.c"
    break;

  case 175: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 678 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3775 "src-generated/ugbc.tab.c"
    break;

  case 176: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 681 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3783 "src-generated/ugbc.tab.c"
    break;

  case 177: /* sprite_definition_simple: direct_integer ENABLE  */
#line 684 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3791 "src-generated/ugbc.tab.c"
    break;

  case 178: /* sprite_definition_simple: direct_integer DISABLE  */
#line 687 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3799 "src-generated/ugbc.tab.c"
    break;

  case 179: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 690 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3807 "src-generated/ugbc.tab.c"
    break;

  case 180: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 693 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3815 "src-generated/ugbc.tab.c"
    break;

  case 181: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 696 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3823 "src-generated/ugbc.tab.c"
    break;

  case 182: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 699 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3831 "src-generated/ugbc.tab.c"
    break;

  case 183: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 702 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3839 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 705 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3847 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 708 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3855 "src-generated/ugbc.tab.c"
    break;

  case 186: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 711 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3863 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_expression: expr DATA FROM expr  */
#line 716 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3871 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_expression: expr MULTICOLOR  */
#line 719 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3879 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_expression: expr MONOCOLOR  */
#line 722 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3887 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_expression: expr COLOR expr  */
#line 725 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3895 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 728 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3903 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_expression: expr ENABLE  */
#line 731 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3911 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_expression: expr DISABLE  */
#line 734 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3919 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 737 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3927 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 740 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3935 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 743 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3943 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 746 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3951 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 749 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3959 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 752 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3967 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 755 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3975 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 758 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3983 "src-generated/ugbc.tab.c"
    break;

  case 204: /* bitmap_definition_simple: AT direct_integer  */
#line 767 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3991 "src-generated/ugbc.tab.c"
    break;

  case 205: /* bitmap_definition_simple: ENABLE  */
#line 770 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3999 "src-generated/ugbc.tab.c"
    break;

  case 206: /* bitmap_definition_simple: DISABLE  */
#line 773 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4007 "src-generated/ugbc.tab.c"
    break;

  case 207: /* bitmap_definition_simple: CLEAR  */
#line 776 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4015 "src-generated/ugbc.tab.c"
    break;

  case 208: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 779 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4023 "src-generated/ugbc.tab.c"
    break;

  case 209: /* bitmap_definition_expression: AT expr  */
#line 785 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4031 "src-generated/ugbc.tab.c"
    break;

  case 210: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 788 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4039 "src-generated/ugbc.tab.c"
    break;

  case 213: /* textmap_definition_simple: AT direct_integer  */
#line 798 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4047 "src-generated/ugbc.tab.c"
    break;

  case 214: /* textmap_definition_expression: AT expr  */
#line 803 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4055 "src-generated/ugbc.tab.c"
    break;

  case 217: /* text_definition_simple: ENABLE  */
#line 812 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4063 "src-generated/ugbc.tab.c"
    break;

  case 218: /* text_definition_simple: DISABLE  */
#line 815 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4071 "src-generated/ugbc.tab.c"
    break;

  case 219: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 820 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4079 "src-generated/ugbc.tab.c"
    break;

  case 220: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 823 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4087 "src-generated/ugbc.tab.c"
    break;

  case 223: /* tiles_definition_simple: AT direct_integer  */
#line 832 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4095 "src-generated/ugbc.tab.c"
    break;

  case 224: /* tiles_definition_expression: AT expr  */
#line 837 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4103 "src-generated/ugbc.tab.c"
    break;

  case 227: /* colormap_definition_simple: AT direct_integer  */
#line 846 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4111 "src-generated/ugbc.tab.c"
    break;

  case 228: /* colormap_definition_simple: CLEAR  */
#line 849 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4119 "src-generated/ugbc.tab.c"
    break;

  case 229: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 852 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4127 "src-generated/ugbc.tab.c"
    break;

  case 230: /* colormap_definition_expression: AT expr  */
#line 857 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4135 "src-generated/ugbc.tab.c"
    break;

  case 231: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 860 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4143 "src-generated/ugbc.tab.c"
    break;

  case 234: /* screen_definition_simple: ON  */
#line 870 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4151 "src-generated/ugbc.tab.c"
    break;

  case 235: /* screen_definition_simple: OFF  */
#line 873 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4159 "src-generated/ugbc.tab.c"
    break;

  case 236: /* screen_definition_simple: ROWS direct_integer  */
#line 876 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4167 "src-generated/ugbc.tab.c"
    break;

  case 237: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 879 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4175 "src-generated/ugbc.tab.c"
    break;

  case 238: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 882 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4183 "src-generated/ugbc.tab.c"
    break;

  case 239: /* screen_definition_expression: ROWS expr  */
#line 887 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4191 "src-generated/ugbc.tab.c"
    break;

  case 240: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 890 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4199 "src-generated/ugbc.tab.c"
    break;

  case 241: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 893 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4207 "src-generated/ugbc.tab.c"
    break;

  case 245: /* var_definition_simple: Identifier ON Identifier  */
#line 902 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4215 "src-generated/ugbc.tab.c"
    break;

  case 246: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 905 "src/ugbc.y"
                                    {
      variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4223 "src-generated/ugbc.tab.c"
    break;

  case 247: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 908 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4231 "src-generated/ugbc.tab.c"
    break;

  case 248: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 911 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4241 "src-generated/ugbc.tab.c"
    break;

  case 249: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 916 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4251 "src-generated/ugbc.tab.c"
    break;

  case 250: /* goto_definition: Identifier  */
#line 923 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4259 "src-generated/ugbc.tab.c"
    break;

  case 251: /* goto_definition: Integer  */
#line 926 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4267 "src-generated/ugbc.tab.c"
    break;

  case 252: /* gosub_definition: Identifier  */
#line 932 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4275 "src-generated/ugbc.tab.c"
    break;

  case 253: /* gosub_definition: Integer  */
#line 935 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4283 "src-generated/ugbc.tab.c"
    break;

  case 255: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 944 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4291 "src-generated/ugbc.tab.c"
    break;

  case 256: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 950 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4299 "src-generated/ugbc.tab.c"
    break;

  case 259: /* ink_definition: expr  */
#line 959 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4307 "src-generated/ugbc.tab.c"
    break;

  case 260: /* on_goto_definition: Identifier  */
#line 964 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4316 "src-generated/ugbc.tab.c"
    break;

  case 261: /* $@3: %empty  */
#line 968 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4324 "src-generated/ugbc.tab.c"
    break;

  case 263: /* on_gosub_definition: Identifier  */
#line 973 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4333 "src-generated/ugbc.tab.c"
    break;

  case 264: /* $@4: %empty  */
#line 977 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4341 "src-generated/ugbc.tab.c"
    break;

  case 266: /* $@5: %empty  */
#line 982 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4349 "src-generated/ugbc.tab.c"
    break;

  case 268: /* $@6: %empty  */
#line 985 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4357 "src-generated/ugbc.tab.c"
    break;

  case 270: /* every_definition: expr TICKS GOSUB Identifier  */
#line 990 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4365 "src-generated/ugbc.tab.c"
    break;

  case 271: /* every_definition: ON  */
#line 993 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4373 "src-generated/ugbc.tab.c"
    break;

  case 272: /* every_definition: OFF  */
#line 996 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4381 "src-generated/ugbc.tab.c"
    break;

  case 273: /* add_definition: Identifier COMMA expr  */
#line 1001 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4389 "src-generated/ugbc.tab.c"
    break;

  case 274: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1004 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4397 "src-generated/ugbc.tab.c"
    break;

  case 275: /* dimensions: Integer  */
#line 1010 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4406 "src-generated/ugbc.tab.c"
    break;

  case 276: /* dimensions: Integer COMMA dimensions  */
#line 1014 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 4415 "src-generated/ugbc.tab.c"
    break;

  case 277: /* datatype: BYTE  */
#line 1021 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 4423 "src-generated/ugbc.tab.c"
    break;

  case 278: /* datatype: SIGNED BYTE  */
#line 1024 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 4431 "src-generated/ugbc.tab.c"
    break;

  case 279: /* datatype: WORD  */
#line 1027 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 4439 "src-generated/ugbc.tab.c"
    break;

  case 280: /* datatype: SIGNED WORD  */
#line 1030 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 4447 "src-generated/ugbc.tab.c"
    break;

  case 281: /* datatype: DWORD  */
#line 1033 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 4455 "src-generated/ugbc.tab.c"
    break;

  case 282: /* datatype: SIGNED DWORD  */
#line 1036 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 4463 "src-generated/ugbc.tab.c"
    break;

  case 283: /* datatype: ADDRESS  */
#line 1039 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 4471 "src-generated/ugbc.tab.c"
    break;

  case 284: /* datatype: POSITION  */
#line 1042 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 4479 "src-generated/ugbc.tab.c"
    break;

  case 285: /* datatype: COLOR  */
#line 1045 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 4487 "src-generated/ugbc.tab.c"
    break;

  case 286: /* datatype: STRING  */
#line 1048 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 4495 "src-generated/ugbc.tab.c"
    break;

  case 287: /* $@7: %empty  */
#line 1053 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4504 "src-generated/ugbc.tab.c"
    break;

  case 288: /* dim_definition: Identifier $@7 OP dimensions CP  */
#line 1056 "src/ugbc.y"
                         {
        variable_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 4514 "src-generated/ugbc.tab.c"
    break;

  case 289: /* $@8: %empty  */
#line 1061 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4523 "src-generated/ugbc.tab.c"
    break;

  case 290: /* dim_definition: Identifier $@8 DOLLAR OP dimensions CP  */
#line 1064 "src/ugbc.y"
                                {
        variable_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 4533 "src-generated/ugbc.tab.c"
    break;

  case 291: /* $@9: %empty  */
#line 1069 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 4542 "src-generated/ugbc.tab.c"
    break;

  case 292: /* dim_definition: Identifier datatype $@9 OP dimensions CP  */
#line 1072 "src/ugbc.y"
                         {
        variable_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 4552 "src-generated/ugbc.tab.c"
    break;

  case 295: /* indexes: expr  */
#line 1085 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = (yyvsp[0].string);
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4561 "src-generated/ugbc.tab.c"
    break;

  case 296: /* indexes: expr COMMA indexes  */
#line 1089 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = (yyvsp[-2].string);
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 4570 "src-generated/ugbc.tab.c"
    break;

  case 313: /* statement: INC Identifier  */
#line 1112 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 4578 "src-generated/ugbc.tab.c"
    break;

  case 314: /* statement: DEC Identifier  */
#line 1115 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 4586 "src-generated/ugbc.tab.c"
    break;

  case 315: /* statement: RANDOMIZE  */
#line 1118 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 4594 "src-generated/ugbc.tab.c"
    break;

  case 316: /* statement: RANDOMIZE expr  */
#line 1121 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 4602 "src-generated/ugbc.tab.c"
    break;

  case 317: /* statement: IF expr THEN  */
#line 1124 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4610 "src-generated/ugbc.tab.c"
    break;

  case 318: /* statement: ELSE  */
#line 1127 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 4618 "src-generated/ugbc.tab.c"
    break;

  case 319: /* statement: ELSE IF expr THEN  */
#line 1130 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4626 "src-generated/ugbc.tab.c"
    break;

  case 320: /* statement: ENDIF  */
#line 1133 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 4634 "src-generated/ugbc.tab.c"
    break;

  case 321: /* statement: DO  */
#line 1136 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 4642 "src-generated/ugbc.tab.c"
    break;

  case 322: /* statement: LOOP  */
#line 1139 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 4650 "src-generated/ugbc.tab.c"
    break;

  case 323: /* $@10: %empty  */
#line 1142 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 4658 "src-generated/ugbc.tab.c"
    break;

  case 324: /* statement: WHILE $@10 expr  */
#line 1144 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 4666 "src-generated/ugbc.tab.c"
    break;

  case 325: /* statement: WEND  */
#line 1147 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 4674 "src-generated/ugbc.tab.c"
    break;

  case 326: /* statement: REPEAT  */
#line 1150 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 4682 "src-generated/ugbc.tab.c"
    break;

  case 327: /* statement: UNTIL expr  */
#line 1153 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 4690 "src-generated/ugbc.tab.c"
    break;

  case 328: /* statement: EXIT  */
#line 1156 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 4698 "src-generated/ugbc.tab.c"
    break;

  case 329: /* statement: EXIT IF expr  */
#line 1159 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 4706 "src-generated/ugbc.tab.c"
    break;

  case 330: /* statement: EXIT Integer  */
#line 1162 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4714 "src-generated/ugbc.tab.c"
    break;

  case 331: /* statement: EXIT direct_integer  */
#line 1165 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4722 "src-generated/ugbc.tab.c"
    break;

  case 332: /* statement: EXIT IF expr COMMA Integer  */
#line 1168 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4730 "src-generated/ugbc.tab.c"
    break;

  case 333: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1171 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4738 "src-generated/ugbc.tab.c"
    break;

  case 334: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1174 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4746 "src-generated/ugbc.tab.c"
    break;

  case 335: /* statement: NEXT  */
#line 1177 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 4754 "src-generated/ugbc.tab.c"
    break;

  case 336: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1180 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4762 "src-generated/ugbc.tab.c"
    break;

  case 337: /* statement: BEG GAMELOOP  */
#line 1183 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 4770 "src-generated/ugbc.tab.c"
    break;

  case 338: /* statement: END GAMELOOP  */
#line 1186 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 4778 "src-generated/ugbc.tab.c"
    break;

  case 339: /* statement: GRAPHIC  */
#line 1189 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 4786 "src-generated/ugbc.tab.c"
    break;

  case 340: /* statement: HALT  */
#line 1192 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 4794 "src-generated/ugbc.tab.c"
    break;

  case 345: /* statement: RETURN  */
#line 1199 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 4802 "src-generated/ugbc.tab.c"
    break;

  case 346: /* statement: POP  */
#line 1202 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 4810 "src-generated/ugbc.tab.c"
    break;

  case 347: /* statement: DONE  */
#line 1205 "src/ugbc.y"
          {
      return 0;
  }
#line 4818 "src-generated/ugbc.tab.c"
    break;

  case 348: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1208 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4826 "src-generated/ugbc.tab.c"
    break;

  case 349: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1211 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4834 "src-generated/ugbc.tab.c"
    break;

  case 350: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1214 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 4842 "src-generated/ugbc.tab.c"
    break;

  case 351: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1217 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4850 "src-generated/ugbc.tab.c"
    break;

  case 353: /* statement: Identifier COLON  */
#line 1221 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 4858 "src-generated/ugbc.tab.c"
    break;

  case 354: /* statement: Identifier ASSIGN expr  */
#line 1224 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 4872 "src-generated/ugbc.tab.c"
    break;

  case 355: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1233 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 4886 "src-generated/ugbc.tab.c"
    break;

  case 356: /* $@11: %empty  */
#line 1242 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 4895 "src-generated/ugbc.tab.c"
    break;

  case 357: /* statement: Identifier $@11 OP indexes CP ASSIGN expr  */
#line 1246 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 4908 "src-generated/ugbc.tab.c"
    break;

  case 358: /* $@12: %empty  */
#line 1254 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 4917 "src-generated/ugbc.tab.c"
    break;

  case 359: /* statement: Identifier DOLLAR $@12 OP indexes CP ASSIGN expr  */
#line 1257 "src/ugbc.y"
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
#line 4936 "src-generated/ugbc.tab.c"
    break;

  case 360: /* $@13: %empty  */
#line 1271 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 4945 "src-generated/ugbc.tab.c"
    break;

  case 361: /* statement: Identifier $@13 datatype OP indexes CP ASSIGN expr  */
#line 1274 "src/ugbc.y"
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
#line 4964 "src-generated/ugbc.tab.c"
    break;

  case 362: /* statement: DEBUG expr  */
#line 1288 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 4972 "src-generated/ugbc.tab.c"
    break;

  case 365: /* statements_no_linenumbers: statement  */
#line 1296 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 4978 "src-generated/ugbc.tab.c"
    break;

  case 366: /* $@14: %empty  */
#line 1297 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 4984 "src-generated/ugbc.tab.c"
    break;

  case 368: /* $@15: %empty  */
#line 1301 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 4992 "src-generated/ugbc.tab.c"
    break;

  case 369: /* statements_with_linenumbers: Integer $@15 statements_no_linenumbers  */
#line 1303 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 5000 "src-generated/ugbc.tab.c"
    break;

  case 374: /* $@16: %empty  */
#line 1315 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 5006 "src-generated/ugbc.tab.c"
    break;


#line 5010 "src-generated/ugbc.tab.c"

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

#line 1317 "src/ugbc.y"


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
        bank_define( _environment, "STRINGS", BT_STRINGS, 0x4200, NULL );
        variable_define( _environment, "text_address", VT_ADDRESS, 0x0400 );
    } else {
        outhead0("org 32768");
        variable_define( _environment, "strings_address", VT_ADDRESS, 0xa000 );
        variable_define( _environment, "bitmap_enabled", VT_BYTE, 0 );
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

