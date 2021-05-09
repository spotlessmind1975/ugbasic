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
 

#line 85 "src-generated/ugbc.tab.c"

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
  YYSYMBOL_MILLISECOND = 140,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 141,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 142,                    /* TICKS  */
  YYSYMBOL_BLACK = 143,                    /* BLACK  */
  YYSYMBOL_WHITE = 144,                    /* WHITE  */
  YYSYMBOL_RED = 145,                      /* RED  */
  YYSYMBOL_CYAN = 146,                     /* CYAN  */
  YYSYMBOL_VIOLET = 147,                   /* VIOLET  */
  YYSYMBOL_GREEN = 148,                    /* GREEN  */
  YYSYMBOL_BLUE = 149,                     /* BLUE  */
  YYSYMBOL_YELLOW = 150,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 151,                   /* ORANGE  */
  YYSYMBOL_BROWN = 152,                    /* BROWN  */
  YYSYMBOL_LIGHT = 153,                    /* LIGHT  */
  YYSYMBOL_DARK = 154,                     /* DARK  */
  YYSYMBOL_GREY = 155,                     /* GREY  */
  YYSYMBOL_GRAY = 156,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 157,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 158,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 159,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 160,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 161,                /* TURQUOISE  */
  YYSYMBOL_TAN = 162,                      /* TAN  */
  YYSYMBOL_PINK = 163,                     /* PINK  */
  YYSYMBOL_PEACH = 164,                    /* PEACH  */
  YYSYMBOL_OLIVE = 165,                    /* OLIVE  */
  YYSYMBOL_Identifier = 166,               /* Identifier  */
  YYSYMBOL_String = 167,                   /* String  */
  YYSYMBOL_Integer = 168,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 169,                 /* $accept  */
  YYSYMBOL_expr = 170,                     /* expr  */
  YYSYMBOL_expr_math = 171,                /* expr_math  */
  YYSYMBOL_term = 172,                     /* term  */
  YYSYMBOL_modula = 173,                   /* modula  */
  YYSYMBOL_factor = 174,                   /* factor  */
  YYSYMBOL_direct_integer = 175,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 176, /* random_definition_simple  */
  YYSYMBOL_random_definition = 177,        /* random_definition  */
  YYSYMBOL_color_enumeration = 178,        /* color_enumeration  */
  YYSYMBOL_exponential = 179,              /* exponential  */
  YYSYMBOL_position = 180,                 /* position  */
  YYSYMBOL_bank_definition_simple = 181,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 182, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 183,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 184, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 185, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 186,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 187, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 188, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 189,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 190,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 191, /* color_definition_expression  */
  YYSYMBOL_color_definition = 192,         /* color_definition  */
  YYSYMBOL_milliseconds = 193,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 194,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 195, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 196,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 197, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 198, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 199,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 200, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 201, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 202,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 203, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 204, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 205,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 206,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 207, /* text_definition_expression  */
  YYSYMBOL_text_definition = 208,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 209,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 210, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 211,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 212, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 213, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 214,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 215, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 216, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 217,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 218,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 219,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 220,         /* gosub_definition  */
  YYSYMBOL_var_definition = 221,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 222,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 223, /* point_definition_expression  */
  YYSYMBOL_point_definition = 224,         /* point_definition  */
  YYSYMBOL_ink_definition = 225,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 226,       /* on_goto_definition  */
  YYSYMBOL_227_1 = 227,                    /* $@1  */
  YYSYMBOL_on_gosub_definition = 228,      /* on_gosub_definition  */
  YYSYMBOL_229_2 = 229,                    /* $@2  */
  YYSYMBOL_on_definition = 230,            /* on_definition  */
  YYSYMBOL_231_3 = 231,                    /* $@3  */
  YYSYMBOL_232_4 = 232,                    /* $@4  */
  YYSYMBOL_every_definition = 233,         /* every_definition  */
  YYSYMBOL_add_definition = 234,           /* add_definition  */
  YYSYMBOL_statement = 235,                /* statement  */
  YYSYMBOL_236_5 = 236,                    /* $@5  */
  YYSYMBOL_statements_no_linenumbers = 237, /* statements_no_linenumbers  */
  YYSYMBOL_238_6 = 238,                    /* $@6  */
  YYSYMBOL_statements_with_linenumbers = 239, /* statements_with_linenumbers  */
  YYSYMBOL_240_7 = 240,                    /* $@7  */
  YYSYMBOL_statements_complex = 241,       /* statements_complex  */
  YYSYMBOL_program = 242,                  /* program  */
  YYSYMBOL_243_8 = 243                     /* $@8  */
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
#define YYLAST   1700

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  339
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  668

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   423


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
     165,   166,   167,   168
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    70,    74,    78,    81,    84,    87,    90,
      93,    96,   102,   103,   106,   113,   114,   118,   119,   123,
     130,   131,   138,   143,   146,   149,   152,   155,   158,   161,
     166,   171,   175,   179,   183,   187,   191,   195,   199,   203,
     207,   211,   215,   219,   223,   227,   231,   235,   239,   243,
     247,   251,   255,   259,   263,   267,   271,   275,   281,   284,
     287,   296,   300,   307,   311,   315,   319,   323,   327,   331,
     335,   339,   342,   345,   348,   351,   354,   357,   360,   363,
     366,   369,   372,   375,   378,   381,   384,   387,   390,   393,
     396,   399,   402,   405,   408,   411,   414,   417,   420,   423,
     426,   429,   432,   435,   439,   443,   447,   450,   455,   455,
     458,   461,   464,   467,   470,   473,   477,   480,   483,   486,
     490,   493,   496,   499,   503,   506,   509,   512,   518,   521,
     524,   527,   530,   535,   536,   539,   542,   547,   550,   555,
     556,   559,   562,   567,   570,   575,   576,   579,   582,   585,
     590,   593,   596,   601,   602,   605,   606,   607,   610,   613,
     616,   621,   624,   627,   633,   634,   637,   640,   643,   646,
     649,   652,   655,   658,   661,   664,   667,   670,   673,   676,
     679,   684,   687,   690,   693,   696,   699,   702,   705,   708,
     711,   714,   717,   720,   723,   726,   731,   732,   735,   738,
     741,   744,   747,   753,   756,   762,   763,   766,   771,   776,
     777,   780,   783,   788,   791,   796,   797,   800,   805,   810,
     811,   814,   817,   820,   825,   828,   834,   835,   838,   841,
     844,   847,   850,   855,   858,   861,   866,   867,   869,   870,
     873,   876,   879,   884,   891,   894,   900,   903,   909,   912,
     918,   923,   924,   927,   932,   936,   936,   941,   945,   945,
     950,   950,   953,   953,   958,   961,   964,   969,   972,   978,
     979,   980,   981,   982,   983,   984,   985,   986,   987,   988,
     989,   990,   991,   992,   993,   994,   997,  1000,  1003,  1006,
    1009,  1012,  1015,  1018,  1021,  1021,  1026,  1029,  1032,  1035,
    1038,  1041,  1044,  1047,  1050,  1053,  1056,  1059,  1062,  1065,
    1068,  1071,  1074,  1075,  1076,  1077,  1078,  1081,  1084,  1087,
    1090,  1093,  1096,  1099,  1102,  1111,  1120,  1123,  1124,  1128,
    1129,  1129,  1133,  1133,  1140,  1141,  1142,  1143,  1147,  1147
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
  "MILLISECOND", "MILLISECONDS", "TICKS", "BLACK", "WHITE", "RED", "CYAN",
  "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE", "BROWN", "LIGHT", "DARK",
  "GREY", "GRAY", "MAGENTA", "PURPLE", "LAVENDER", "GOLD", "TURQUOISE",
  "TAN", "PINK", "PEACH", "OLIVE", "Identifier", "String", "Integer",
  "$accept", "expr", "expr_math", "term", "modula", "factor",
  "direct_integer", "random_definition_simple", "random_definition",
  "color_enumeration", "exponential", "position", "bank_definition_simple",
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
  "on_goto_definition", "$@1", "on_gosub_definition", "$@2",
  "on_definition", "$@3", "$@4", "every_definition", "add_definition",
  "statement", "$@5", "statements_no_linenumbers", "$@6",
  "statements_with_linenumbers", "$@7", "statements_complex", "program",
  "$@8", YY_NULLPTR
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
     415,   416,   417,   418,   419,   420,   421,   422,   423
};
#endif

#define YYPACT_NINF (-227)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-259)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -227,    40,    57,  -227,  -227,  -110,  -100,   -22,  -227,    15,
    1288,    49,   -23,  1288,  -227,     6,   136,  1410,   -92,   -57,
    -227,  -227,  -227,  1019,    54,    -6,  1410,    23,    34,  -227,
      74,    93,  1410,  -227,  -227,   151,   162,    29,  -227,  -227,
     121,  -227,   -62,  -227,  1410,    28,  1166,   175,    60,  1410,
      94,  -227,   218,   225,   226,  -227,  -227,  -227,  1288,   208,
    -227,  -227,  -227,  1288,  1288,  1288,  -227,  -227,  -227,    63,
     872,  -227,  -227,   199,   200,   201,   117,    68,  -227,  -227,
     206,   209,  1410,  -227,  -227,   210,   211,   212,   213,   214,
     215,   236,   239,   240,   241,   242,   243,   244,   246,   248,
     251,   252,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
     104,  -227,  -227,    58,  -117,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,   133,   221,  -227,  -227,   -65,   114,
     112,   191,   160,   -51,  -227,  -227,  -227,  -227,  -227,   -19,
     216,   -17,   -12,     0,    11,   266,  -227,  -227,  -227,   247,
     263,  -227,  -227,  -227,  1288,  -227,  -227,   262,  -227,  -227,
    -227,  -227,  -227,  1288,   250,   259,  -227,  -227,  -227,   -37,
    -227,    17,  -227,  -227,  -227,  -227,  -227,  1410,  1410,  -227,
    -227,   286,  -227,  -227,  -227,  1288,  -227,  -227,  -227,  1288,
     265,  -227,  -227,  -227,   228,  -227,  -227,  1410,  1410,  -227,
    1288,  -227,  -227,  -227,   272,  -227,  -227,  -227,  -227,  -227,
    -227,  1410,  1410,  -227,  -227,  -227,   294,  -227,  -227,   167,
    -227,  1410,   303,  -227,  -227,  -227,  -227,  1410,   298,   772,
    -227,    57,    57,   285,   287,  1288,  -227,  -227,   249,   253,
     254,   255,  -227,   280,   289,   295,   296,   297,   -27,   299,
    1288,  1288,  1288,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  1410,  1410,  -227,  1410,  1410,  1410,  1410,
    1410,  1410,  1410,  1410,  1410,  1410,  1410,  1410,  1410,  1410,
    1410,  1410,  1410,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  1532,  1532,
    1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,  1532,
    1532,  1532,  -227,  -227,  -227,  1288,   309,  -227,  -227,  -227,
     274,   216,   311,   216,   312,   216,   313,   216,   314,   216,
    -227,  1410,   307,  -227,  -227,   -34,    46,    16,    47,  -227,
    -227,  -227,   308,   216,   316,  -227,  -227,   126,   148,    51,
      67,  -227,  -227,   310,  -227,  -227,  1288,  -227,  -227,  1288,
    1288,  -227,  -227,   315,   179,  -227,   334,  1410,  -227,  -227,
    -227,  -227,  1288,  -227,   343,   344,  -227,  -227,  1288,   283,
     346,  1410,   256,   348,  1410,  -227,  1410,  -227,   772,  -227,
    -227,   190,   194,  -227,  -227,  1410,   216,  1410,   216,   193,
     195,   196,   198,   202,   327,   332,   337,  -227,   339,   340,
     341,   345,   350,   351,   362,   371,   372,   374,   352,   353,
     354,   355,   376,   356,   357,   359,   360,   361,   390,   394,
     367,   368,   369,   112,   112,   207,   207,   207,   207,   207,
     207,   207,   207,   191,   160,   160,  -227,   377,   378,  1288,
     -15,  -227,   216,  -227,   216,  -227,   216,  -227,   216,    35,
    -227,  1410,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    1410,  -227,   216,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,   216,  -227,  -227,  -227,  -227,  -227,  -227,   245,   257,
     258,   392,  1410,   401,   370,   373,  1410,  1410,   402,   403,
    -227,   -74,   342,   260,  1410,   406,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,   261,
     264,   267,  -227,  -227,  -227,  -227,  -227,  -227,  1410,  1410,
    1410,  1410,  -227,  -227,  -227,  -227,  1410,  -227,  -227,  -227,
    -227,  -227,  1410,  1410,  -227,  -227,  -227,   268,   271,  -227,
    -227,  -227,  -227,  -227,  -227,   387,  -227,   388,  -227,   273,
      -5,  -227,   411,  -227,   412,   413,  -227,   414,  -227,   409,
    1288,   418,  1410,  1410,   216,   393,   395,  1410,   216,  -227,
    -227,  1410,  -227,     4,  1410,  -227,  -227,  -227,   396,   398,
      14,    18,   404,   407,   408,  -227,  -227,   277,   278,  -227,
     417,  -227,   420,  -227,  1410,   216,   431,   434,  1410,  -227,
    -227,  1410,  -227,  -227,  -227,   437,   438,   419,   421,   338,
    1410,   439,   375,  -227,  -227,  1410,  -227,  1410,  -227,  -227,
    -227,  -227,  -227,  -227,   288,   291,   424,   425,   245,   257,
    -227,  -227,  1410,  1410,  -227,  -227,  1410,   426,  1410,  1410,
     427,   428,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,   451,  -227,  -227,  -227,  -227,  1410,  -227
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     338,     0,   328,     1,   327,     0,     0,     0,   318,     0,
       0,   306,     0,     0,   311,     0,     0,     0,   238,     0,
     293,   297,   294,     0,     0,     0,     0,     0,     0,   291,
       0,     0,     0,   287,   310,     0,     0,     0,   316,   317,
     289,   292,   299,   296,     0,     0,     0,     0,     0,     0,
       0,   332,   329,   334,   336,   339,   285,   286,     0,     0,
     139,   140,   270,     0,     0,     0,   153,   154,   272,     0,
       0,    74,    75,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,     0,    43,    48,    49,    50,    51,
      52,    53,    56,    57,     0,    58,    62,    60,     0,     2,
      12,    15,    17,     0,    71,    20,   164,   165,   273,     0,
       0,     0,     0,     0,     0,     0,   133,   134,   269,     0,
       0,   196,   197,   274,     0,   199,   200,   201,   205,   206,
     275,   228,   229,     0,     0,     0,   236,   237,   280,     0,
     312,     0,   248,   283,   244,   245,   313,     0,     0,   211,
     212,     0,   215,   216,   277,     0,   219,   220,   278,     0,
     222,   226,   227,   279,     0,   308,   309,     0,     0,   326,
       0,   209,   210,   276,     0,   251,   252,   281,   246,   247,
     314,     0,     0,   301,   302,   298,     0,   265,   266,     0,
     315,     0,     0,   284,   253,   282,   323,     0,     0,   328,
     330,   328,   328,     0,     0,     0,   150,   147,     0,     0,
       0,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    23,    24,    26,    28,    29,    25,
      30,    96,    22,     0,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    41,    44,    45,    46,    47,    42,
      55,    59,   155,   161,   156,   157,   162,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   158,   159,   160,     0,     0,   145,   146,   271,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,     0,   186,   187,     0,     0,     0,     0,   183,
     182,   108,     0,     0,     0,   171,   172,     0,     0,     0,
       0,   168,   167,     0,   203,   198,     0,   233,   230,     0,
       0,   260,   262,     0,     0,   295,     0,     0,   218,   217,
     224,   221,     0,   288,     0,     0,   208,   207,     0,     0,
     300,     0,     0,     0,     0,   324,     0,   333,   328,   335,
     337,     0,     0,   137,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,     5,     7,     8,     9,    10,
       6,     3,     4,    16,    18,    19,    21,     0,     0,     0,
       0,   115,     0,   127,     0,   119,     0,   123,     0,   111,
     184,     0,   191,   190,   195,   194,   189,   193,   188,   192,
       0,   169,     0,   176,   175,   180,   179,   174,   178,   173,
     177,     0,   204,   202,   234,   231,   235,   232,     0,     0,
       0,   239,     0,     0,     0,     0,     0,     0,     0,     0,
     290,     0,     0,     0,     0,   267,   325,   331,   138,   136,
     152,   149,   151,   148,    70,    63,    65,    69,    67,     0,
       0,     0,    73,    72,    77,    76,    79,    78,     0,     0,
       0,     0,    86,    87,    88,    95,     0,    89,    90,    91,
      92,    93,     0,     0,   101,   102,    97,     0,     0,   143,
     141,   112,   125,   117,   120,   114,   126,   118,   122,     0,
       0,   181,     0,   166,     0,   254,   261,   257,   263,   240,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   303,
     304,     0,   264,     0,     0,    64,    66,    68,     0,     0,
       0,     0,     0,     0,     0,   144,   142,     0,     0,   128,
     113,   124,   116,   121,     0,     0,     0,     0,     0,   242,
     241,     0,   214,   225,   223,     0,     0,     0,     0,   305,
       0,     0,     0,    80,    81,     0,    82,     0,    84,    94,
     100,    99,   130,   132,     0,     0,     0,     0,     0,     0,
     243,   213,     0,     0,   250,   249,     0,     0,     0,     0,
       0,     0,   129,   131,   185,   170,   256,   259,   319,   320,
     307,     0,   321,   268,    83,    85,     0,   322
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -227,   -13,  -167,   -81,   119,   -89,   335,  -227,  -227,  -227,
     154,   317,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,   333,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -170,  -227,  -169,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -226,  -227,
    -227,  -227,    -4,  -227,  -227
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   128,   129,   130,   131,   132,   133,   260,   261,   134,
     135,   342,   146,   147,   148,    60,    61,    62,   317,   318,
     319,    66,    67,    68,   297,   136,   137,   138,   151,   152,
     153,   158,   159,   160,   201,   202,   203,   182,   183,   184,
     186,   187,   188,   191,   192,   193,   166,   167,   168,   172,
     176,   210,   173,   205,   206,   207,   225,   566,   606,   568,
     607,   170,   488,   489,   220,   223,    52,   177,    53,   388,
      54,   229,    55,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     149,   140,    58,   387,   169,   315,   212,   321,    77,   141,
     181,   620,   323,   194,   292,   293,   361,   551,   189,   199,
      77,   625,   462,   463,   325,   627,   142,   600,   292,   312,
     154,   215,   288,   219,   552,   327,   224,   363,   289,   621,
       3,    63,   155,   156,   601,   233,    64,   404,   405,   626,
     236,   238,   240,   628,   143,   144,    56,   249,   406,   364,
       4,   466,   553,   554,   559,   362,    57,     5,     6,   265,
     467,   139,   602,   603,   171,   294,   295,   296,   185,     7,
       8,   190,     9,   560,    10,    11,    65,    12,    13,   294,
     295,   313,   468,   157,   579,    14,   477,    15,    16,    17,
     226,   469,   464,   465,    18,   478,   213,   227,   197,   174,
      19,   175,   479,   195,   228,    20,    21,    22,    23,    24,
      25,   480,   298,   299,   196,    26,   300,   198,   301,   302,
     303,   304,   305,   435,   436,   437,   438,   439,   440,   441,
     442,   354,   253,   145,    59,    27,    28,   316,    29,   322,
     357,    30,    31,    32,   324,    33,    34,    35,    36,    37,
      38,    39,   507,    40,   365,   366,   326,    41,    42,    43,
      44,    45,   368,    46,    47,   200,   370,   328,   161,   162,
     163,   164,   473,   474,   374,   375,   204,   376,    48,   211,
     165,   254,   255,   256,   216,   208,    49,   209,   379,   380,
     257,   258,   259,   284,   475,   476,   285,   286,   383,   221,
     309,   306,   310,   287,   385,   298,   299,   433,   434,   307,
     444,   445,   393,    50,   230,    51,   222,   389,   390,   231,
     232,   242,   235,   250,   251,   252,   262,   408,   410,   412,
     263,   291,   308,   264,   266,   267,   268,   269,   270,   271,
     414,   415,   283,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     272,   330,   331,   273,   274,   275,   276,   277,   278,   332,
     279,   290,   280,   333,   334,   281,   282,   330,   343,   311,
     329,   356,   335,   367,   372,   344,   359,   373,    77,   345,
     346,   336,   447,   337,   338,   360,   378,   381,   347,   382,
     384,   386,   339,   340,   391,   399,   392,   348,   460,   349,
     350,   395,   450,   341,   400,   396,   397,   398,   351,   352,
     401,   402,   403,   449,   407,   452,   454,   456,   458,   341,
     461,   492,   470,   482,   481,   491,   484,   486,   150,   472,
     496,   497,   500,   501,   493,   504,   508,   490,   503,   494,
     509,   514,   519,   515,   516,   498,   517,   520,   502,   528,
     518,   505,   521,   506,   522,   523,   524,   214,   529,   530,
     525,   531,   510,   536,   512,   526,   527,   532,   533,   534,
     535,   537,   538,   234,   539,   540,   541,   542,   237,   239,
     241,   543,   544,   545,   546,   570,   547,   548,   572,   577,
     578,   565,   573,   584,   581,   574,   597,   598,   604,   605,
    -255,  -258,   608,   567,   569,   611,   582,   443,   615,   585,
     616,   623,   586,   624,   595,   587,   549,   596,   638,   629,
     599,   639,   630,   631,   632,   633,   634,   649,   561,   635,
     642,   643,   648,   646,   644,   652,   645,   562,   653,   654,
     655,   661,   664,   665,   666,   446,   314,   353,   656,     0,
     657,     0,     0,     0,     0,   320,     0,     0,     0,   571,
       0,     0,     0,   575,   576,     0,     0,     0,     0,   355,
       0,   583,     0,     0,     0,     0,     0,     0,   358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   588,   589,   590,   591,     0,
     369,     0,     0,   592,   371,     0,     0,     0,     0,   593,
     594,     0,     0,     0,     0,   377,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   609,     0,   612,
     613,     0,     0,     0,   617,     0,     0,     0,   619,     0,
     394,   622,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   409,   411,   413,     0,     0,
       0,   636,     0,     0,     0,   640,     0,     0,   641,     0,
       0,     0,     0,     0,     0,     0,     0,   647,     0,     0,
       0,     0,   650,     0,   651,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   658,
     659,     0,     0,   660,     0,   662,   663,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     448,     0,     0,   667,     0,     0,   451,     0,   453,     0,
     455,     0,   457,     0,   459,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   471,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   483,     0,     0,   485,   487,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   495,     0,     0,
       0,     0,     0,   499,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   511,     0,   513,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     0,     0,     0,     0,
       0,     0,     5,     6,   550,     0,     0,   555,     0,   556,
       0,   557,     0,   558,     7,     8,     0,     9,     0,    10,
      11,     0,    12,    13,     0,     0,     0,   563,     0,     0,
      14,     0,    15,    16,    17,     0,   564,     0,     0,    18,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
      20,    21,    22,    23,    24,    25,   580,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    28,     0,    29,     0,     0,    30,    31,    32,     0,
      33,    34,    35,    36,    37,    38,    39,     0,    40,     0,
       0,    69,    41,    42,    43,    44,    45,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,   243,     0,     0,
       0,     0,     0,    48,     0,   610,    70,     0,     0,   614,
       0,    49,     0,   618,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    74,
     637,     0,    75,     0,     0,    76,   244,   245,   246,     0,
       0,     0,     0,     0,     0,    78,    79,   247,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,     0,     0,     0,    97,    98,    99,   248,   100,   101,
     102,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    69,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     0,     0,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,   179,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    71,
      72,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,     0,     0,    75,
       0,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,     0,     0,
       0,    97,    98,    99,     0,   100,   101,   102,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    69,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,     0,     0,     0,     0,   217,   218,
       0,     0,     0,     0,     0,     0,    71,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,     0,    75,     0,     0,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,     0,     0,    69,    97,    98,
      99,     0,   100,   101,   102,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    70,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,     0,     0,     0,    71,    72,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,     0,    75,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    78,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,     0,     0,    69,
      97,    98,    99,     0,   100,   101,   102,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    70,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     0,     0,     0,
      71,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,     0,     0,
      75,     0,     0,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,     0,
       0,    69,    97,    98,    99,     0,   100,   101,   102,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    70,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     0,
       0,     0,    71,    72,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
       0,     0,    75,     0,     0,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,     0,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,     0,     0,     0,    97,    98,    99,     0,   100,   101,
     102,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127
};

static const yytype_int16 yycheck[] =
{
      13,    24,    24,   229,    17,    24,    68,    24,    82,    32,
      23,     7,    24,    26,    79,    80,    53,    32,    24,    32,
      82,     7,    56,    57,    24,     7,    49,    32,    79,    80,
      24,    44,   149,    46,    49,    24,    49,    20,   155,    35,
       0,    26,    36,    37,    49,    58,    31,    74,    75,    35,
      63,    64,    65,    35,    77,    78,   166,    70,    85,    42,
       3,    45,    77,    78,    29,   102,   166,    10,    11,    82,
      54,    22,    77,    78,   166,   140,   141,   142,    24,    22,
      23,    87,    25,    48,    27,    28,    71,    30,    31,   140,
     141,   142,    45,    87,   168,    38,    45,    40,    41,    42,
       6,    54,    56,    57,    47,    54,   168,    13,    34,   166,
      53,   168,    45,    90,    20,    58,    59,    60,    61,    62,
      63,    54,     8,     9,    90,    68,    12,    34,    14,    15,
      16,    17,    18,   300,   301,   302,   303,   304,   305,   306,
     307,   154,    25,   166,   166,    88,    89,   166,    91,   166,
     163,    94,    95,    96,   166,    98,    99,   100,   101,   102,
     103,   104,   388,   106,   177,   178,   166,   110,   111,   112,
     113,   114,   185,   116,   117,    24,   189,   166,    42,    43,
      44,    45,    56,    57,   197,   198,    24,   200,   131,    68,
      54,    74,    75,    76,   166,   166,   139,   168,   211,   212,
      83,    84,    85,   145,    56,    57,   148,   149,   221,    34,
      19,    97,    21,   155,   227,     8,     9,   298,   299,   105,
     309,   310,   235,   166,     6,   168,   166,   231,   232,     4,
       4,   168,    24,    34,    34,    34,   168,   250,   251,   252,
      34,    20,   130,    34,    34,    34,    34,    34,    34,    34,
     263,   264,   148,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
      34,    24,    25,    34,    34,    34,    34,    34,    34,    32,
      34,   148,    34,    36,    37,    34,    34,    24,    25,   129,
      24,    29,    45,     7,    29,    32,    46,    69,    82,    36,
      37,    54,   315,    56,    57,    46,    34,    13,    45,   142,
       7,    13,    65,    66,    29,    35,    29,    54,   331,    56,
      57,    72,    48,    76,    35,    72,    72,    72,    65,    66,
      35,    35,    35,    24,    35,    24,    24,    24,    24,    76,
      33,     7,    34,   356,    34,   166,   359,   360,    13,    33,
       7,     7,    69,     7,   367,     7,   166,    42,   102,   372,
     166,   168,    35,   168,   168,   378,   168,    35,   381,     7,
     168,   384,    35,   386,    35,    35,    35,    42,     7,     7,
      35,     7,   395,     7,   397,    35,    35,    35,    35,    35,
      35,    35,    35,    58,    35,    35,    35,     7,    63,    64,
      65,     7,    35,    35,    35,    13,    29,    29,     7,     7,
       7,   166,    42,     7,    72,    42,    29,    29,     7,     7,
       7,     7,    13,   166,   166,     7,   166,   308,    35,   168,
      35,    35,   168,    35,   166,   168,   449,   166,     7,    35,
     167,     7,    35,    35,   167,   167,    29,    72,   461,    29,
      13,    13,    13,   115,    35,   167,    35,   470,   167,    35,
      35,    35,    35,    35,    13,   311,   133,   150,   638,    -1,
     639,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,   492,
      -1,    -1,    -1,   496,   497,    -1,    -1,    -1,    -1,   154,
      -1,   504,    -1,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   528,   529,   530,   531,    -1,
     185,    -1,    -1,   536,   189,    -1,    -1,    -1,    -1,   542,
     543,    -1,    -1,    -1,    -1,   200,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   570,    -1,   572,
     573,    -1,    -1,    -1,   577,    -1,    -1,    -1,   581,    -1,
     235,   584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   250,   251,   252,    -1,    -1,
      -1,   604,    -1,    -1,    -1,   608,    -1,    -1,   611,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   620,    -1,    -1,
      -1,    -1,   625,    -1,   627,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   642,
     643,    -1,    -1,   646,    -1,   648,   649,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     315,    -1,    -1,   666,    -1,    -1,   321,    -1,   323,    -1,
     325,    -1,   327,    -1,   329,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   343,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   356,    -1,    -1,   359,   360,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,
      -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   396,    -1,   398,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    11,   449,    -1,    -1,   452,    -1,   454,
      -1,   456,    -1,   458,    22,    23,    -1,    25,    -1,    27,
      28,    -1,    30,    31,    -1,    -1,    -1,   472,    -1,    -1,
      38,    -1,    40,    41,    42,    -1,   481,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,   501,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    -1,    91,    -1,    -1,    94,    95,    96,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,   106,    -1,
      -1,     9,   110,   111,   112,   113,   114,    -1,   116,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,   131,    -1,   570,    34,    -1,    -1,   574,
      -1,   139,    -1,   578,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,    67,
     605,    -1,    70,    -1,    -1,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,   132,   133,   134,   135,   136,   137,
     138,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,     9,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    -1,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,   132,   133,   134,    -1,   136,   137,   138,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,     9,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,     9,   132,   133,
     134,    -1,   136,   137,   138,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,    34,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,     9,
     132,   133,   134,    -1,   136,   137,   138,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,    34,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,     9,   132,   133,   134,    -1,   136,   137,   138,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    34,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,   132,   133,   134,    -1,   136,   137,
     138,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   242,   243,     0,     3,    10,    11,    22,    23,    25,
      27,    28,    30,    31,    38,    40,    41,    42,    47,    53,
      58,    59,    60,    61,    62,    63,    68,    88,    89,    91,
      94,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     106,   110,   111,   112,   113,   114,   116,   117,   131,   139,
     166,   168,   235,   237,   239,   241,   166,   166,    24,   166,
     184,   185,   186,    26,    31,    71,   190,   191,   192,     9,
      34,    50,    51,    52,    67,    70,    73,    82,    83,    84,
      94,    95,   107,   108,   109,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   132,   133,   134,
     136,   137,   138,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   170,   171,
     172,   173,   174,   175,   178,   179,   194,   195,   196,    22,
      24,    32,    49,    77,    78,   166,   181,   182,   183,   170,
     175,   197,   198,   199,    24,    36,    37,    87,   200,   201,
     202,    42,    43,    44,    45,    54,   215,   216,   217,   170,
     230,   166,   218,   221,   166,   168,   219,   236,    24,    36,
      37,   170,   206,   207,   208,    24,   209,   210,   211,    24,
      87,   212,   213,   214,   170,    90,    90,    34,    34,   170,
      24,   203,   204,   205,    24,   222,   223,   224,   166,   168,
     220,    68,    68,   168,   175,   170,   166,    42,    43,   170,
     233,    34,   166,   234,   170,   225,     6,    13,    20,   240,
       6,     4,     4,   170,   175,    24,   170,   175,   170,   175,
     170,   175,   168,    25,    74,    75,    76,    85,   135,   170,
      34,    34,    34,    25,    74,    75,    76,    83,    84,    85,
     176,   177,   168,    34,    34,   170,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,   148,   145,   148,   149,   155,   149,   155,
     148,    20,    79,    80,   140,   141,   142,   193,     8,     9,
      12,    14,    15,    16,    17,    18,    97,   105,   130,    19,
      21,   129,    80,   142,   193,    24,   166,   187,   188,   189,
     175,    24,   166,    24,   166,    24,   166,    24,   166,    24,
      24,    25,    32,    36,    37,    45,    54,    56,    57,    65,
      66,    76,   180,    25,    32,    36,    37,    45,    54,    56,
      57,    65,    66,   180,   170,   175,    29,   170,   175,    46,
      46,    53,   102,    20,    42,   170,   170,     7,   170,   175,
     170,   175,    29,    69,   170,   170,   170,   175,    34,   170,
     170,    13,   142,   170,     7,   170,    13,   237,   238,   241,
     241,    29,    29,   170,   175,    72,    72,    72,    72,    35,
      35,    35,    35,    35,    74,    75,    85,    35,   170,   175,
     170,   175,   170,   175,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   172,   172,   171,   171,   171,   171,   171,
     171,   171,   171,   173,   174,   174,   179,   170,   175,    24,
      48,   175,    24,   175,    24,   175,    24,   175,    24,   175,
     170,    33,    56,    57,    56,    57,    45,    54,    45,    54,
      34,   175,    33,    56,    57,    56,    57,    45,    54,    45,
      54,    34,   170,   175,   170,   175,   170,   175,   231,   232,
      42,   166,     7,   170,   170,   175,     7,     7,   170,   175,
      69,     7,   170,   102,     7,   170,   170,   237,   166,   166,
     170,   175,   170,   175,   168,   168,   168,   168,   168,    35,
      35,    35,    35,    35,    35,    35,    35,    35,     7,     7,
       7,     7,    35,    35,    35,    35,     7,    35,    35,    35,
      35,    35,     7,     7,    35,    35,    35,    29,    29,   170,
     175,    32,    49,    77,    78,   175,   175,   175,   175,    29,
      48,   170,   170,   175,   175,   166,   226,   166,   228,   166,
      13,   170,     7,    42,    42,   170,   170,     7,     7,   168,
     175,    72,   166,   170,     7,   168,   168,   168,   170,   170,
     170,   170,   170,   170,   170,   166,   166,    29,    29,   167,
      32,    49,    77,    78,     7,     7,   227,   229,    13,   170,
     175,     7,   170,   170,   175,    35,    35,   170,   175,   170,
       7,    35,   170,    35,    35,     7,    35,     7,    35,    35,
      35,    35,   167,   167,    29,    29,   170,   175,     7,     7,
     170,   170,    13,    13,    35,    35,   115,   170,    13,    72,
     170,   170,   167,   167,    35,    35,   226,   228,   170,   170,
     170,    35,   170,   170,    35,    35,    13,   170
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   169,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   171,   171,   171,   172,   172,   173,   173,   173,
     174,   174,   175,   176,   176,   176,   176,   176,   176,   176,
     177,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   180,   180,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   182,   182,
     182,   182,   182,   183,   183,   184,   184,   185,   185,   186,
     186,   187,   187,   188,   188,   189,   189,   190,   190,   190,
     191,   191,   191,   192,   192,   193,   193,   193,   194,   194,
     194,   195,   195,   195,   196,   196,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   199,   199,   200,   200,
     200,   200,   200,   201,   201,   202,   202,   203,   204,   205,
     205,   206,   206,   207,   207,   208,   208,   209,   210,   211,
     211,   212,   212,   212,   213,   213,   214,   214,   215,   215,
     215,   215,   215,   216,   216,   216,   217,   217,   218,   218,
     218,   218,   218,   218,   219,   219,   220,   220,   221,   222,
     223,   224,   224,   225,   226,   227,   226,   228,   229,   228,
     231,   230,   232,   230,   233,   233,   233,   234,   234,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   236,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   237,
     238,   237,   240,   239,   241,   241,   241,   241,   243,   242
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     3,     3,     1,     3,     1,     3,     3,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     2,
       1,     2,     1,     4,     5,     4,     5,     4,     5,     4,
       4,     1,     4,     4,     1,     1,     4,     4,     4,     4,
       6,     6,     6,     8,     6,     8,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     2,     4,     3,     6,
       6,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     4,     5,     4,     3,     5,     4,     4,     3,
       4,     5,     4,     3,     5,     4,     4,     3,     5,     7,
       6,     7,     6,     1,     1,     3,     4,     3,     4,     1,
       1,     3,     4,     3,     4,     1,     1,     2,     4,     4,
       2,     4,     4,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     1,     1,     4,     2,     2,     3,
       7,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     2,     2,     3,     7,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     2,     1,
       1,     1,     3,     2,     3,     1,     1,     2,     2,     1,
       1,     1,     1,     6,     5,     1,     1,     2,     2,     1,
       1,     2,     1,     5,     2,     5,     1,     1,     1,     1,
       2,     3,     3,     2,     3,     3,     1,     1,     0,     3,
       4,     5,     5,     6,     1,     1,     1,     1,     1,     6,
       6,     1,     1,     1,     1,     0,     4,     1,     0,     4,
       0,     4,     0,     4,     4,     1,     1,     3,     7,     2,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     3,     1,
       4,     1,     1,     1,     0,     3,     1,     1,     2,     1,
       3,     2,     2,     5,     5,     6,     1,     8,     2,     2,
       1,     1,     2,     2,     2,     2,     1,     1,     1,     8,
       8,     8,    10,     2,     3,     4,     2,     1,     0,     1,
       0,     4,     0,     3,     1,     3,     1,     3,     0,     2
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
#line 70 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2402 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 74 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2411 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 78 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2419 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 81 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2427 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 84 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2435 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 87 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2443 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 90 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2451 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 93 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2459 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 96 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2467 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 103 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2475 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 106 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2484 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 119 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2493 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 123 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2502 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 131 "src/ugbc.y"
                               {
        (yyval.string) = variable_pow( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 2511 "src-generated/ugbc.tab.c"
    break;

  case 22: /* direct_integer: HASH Integer  */
#line 138 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2519 "src-generated/ugbc.tab.c"
    break;

  case 23: /* random_definition_simple: BYTE  */
#line 143 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2527 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: WORD  */
#line 146 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2535 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: DWORD  */
#line 149 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2543 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: POSITION  */
#line 152 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2551 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: COLOR  */
#line 155 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2559 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: WIDTH  */
#line 158 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2567 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: HEIGHT  */
#line 161 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2575 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition: random_definition_simple  */
#line 166 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2583 "src-generated/ugbc.tab.c"
    break;

  case 31: /* color_enumeration: BLACK  */
#line 171 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2592 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: WHITE  */
#line 175 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2601 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: RED  */
#line 179 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2610 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: CYAN  */
#line 183 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2619 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: VIOLET  */
#line 187 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2628 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: GREEN  */
#line 191 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2637 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: BLUE  */
#line 195 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2646 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: YELLOW  */
#line 199 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2655 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: ORANGE  */
#line 203 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2664 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: BROWN  */
#line 207 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2673 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: LIGHT RED  */
#line 211 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2682 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: DARK GREY  */
#line 215 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2691 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: GREY  */
#line 219 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2700 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: LIGHT GREEN  */
#line 223 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2709 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT BLUE  */
#line 227 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2718 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT GREY  */
#line 231 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2727 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: DARK BLUE  */
#line 235 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2736 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: MAGENTA  */
#line 239 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2745 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: PURPLE  */
#line 243 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2754 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: LAVENDER  */
#line 247 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2763 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: GOLD  */
#line 251 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2772 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: TURQUOISE  */
#line 255 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2781 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TAN  */
#line 259 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2790 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: YELLOW GREEN  */
#line 263 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2799 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: OLIVE GREEN  */
#line 267 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2808 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: PINK  */
#line 271 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2817 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PEACH  */
#line 275 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2826 "src-generated/ugbc.tab.c"
    break;

  case 58: /* exponential: Identifier  */
#line 281 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2834 "src-generated/ugbc.tab.c"
    break;

  case 59: /* exponential: Identifier DOLLAR  */
#line 284 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[-1].string);
      }
#line 2842 "src-generated/ugbc.tab.c"
    break;

  case 60: /* exponential: Integer  */
#line 287 "src/ugbc.y"
              { 
        if ( (yyvsp[0].integer) < 0 ) {
            (yyval.string) = variable_temporary( _environment, VT_SWORD, "(signed integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        } else {
            (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        }
      }
#line 2856 "src-generated/ugbc.tab.c"
    break;

  case 61: /* exponential: MINUS Integer  */
#line 296 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 2865 "src-generated/ugbc.tab.c"
    break;

  case 62: /* exponential: String  */
#line 300 "src/ugbc.y"
             { 
        outline1("; (expr string: \"%s\")", (yyvsp[0].string) );
        (yyval.string) = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", (yyval.string) );
        variable_store_string( _environment, (yyval.string), (yyvsp[0].string) );
        outline2("; variable stored: %s = %s", (yyval.string), (yyvsp[0].string) );
      }
#line 2877 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: OP BYTE CP Integer  */
#line 307 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2886 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: OP SIGNED BYTE CP Integer  */
#line 311 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2895 "src-generated/ugbc.tab.c"
    break;

  case 65: /* exponential: OP WORD CP Integer  */
#line 315 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2904 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: OP SIGNED WORD CP Integer  */
#line 319 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2913 "src-generated/ugbc.tab.c"
    break;

  case 67: /* exponential: OP DWORD CP Integer  */
#line 323 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2922 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP SIGNED DWORD CP Integer  */
#line 327 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2931 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP POSITION CP Integer  */
#line 331 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2940 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP COLOR CP Integer  */
#line 335 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2949 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: color_enumeration  */
#line 339 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2957 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: PEEK OP direct_integer CP  */
#line 342 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2965 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: PEEK OP expr CP  */
#line 345 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 2973 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: XPEN  */
#line 348 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 2981 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: YPEN  */
#line 351 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 2989 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: COLLISION OP direct_integer CP  */
#line 354 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2997 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: COLLISION OP expr CP  */
#line 357 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3005 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: HIT OP direct_integer CP  */
#line 360 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3013 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: HIT OP expr CP  */
#line 363 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3021 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: LEFT OP expr COMMA expr CP  */
#line 366 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3029 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 369 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3037 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: MID OP expr COMMA expr CP  */
#line 372 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3045 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 375 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3053 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: INSTR OP expr COMMA expr CP  */
#line 378 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3061 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 381 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3069 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: UPPER OP expr CP  */
#line 384 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3077 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: LOWER OP expr CP  */
#line 387 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3085 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: STR OP expr CP  */
#line 390 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3093 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: SPACE OP expr CP  */
#line 393 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3101 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: FLIP OP expr CP  */
#line 396 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3109 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: CHR OP expr CP  */
#line 399 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3117 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: ASC OP expr CP  */
#line 402 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3125 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: LEN OP expr CP  */
#line 405 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3133 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: STRING OP expr COMMA expr CP  */
#line 408 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3141 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: VAL OP expr CP  */
#line 411 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3149 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: RANDOM random_definition  */
#line 414 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3157 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: RND OP expr CP  */
#line 417 "src/ugbc.y"
                     {
        (yyval.string) = variable_rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3165 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: OP expr CP  */
#line 420 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3173 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: MAX OP expr COMMA expr CP  */
#line 423 "src/ugbc.y"
                                {
        (yyval.string) = variable_max( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3181 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: MIN OP expr COMMA expr CP  */
#line 426 "src/ugbc.y"
                                {
        (yyval.string) = variable_min( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3189 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: SGN OP expr CP  */
#line 429 "src/ugbc.y"
                     {
        (yyval.string) = variable_sgn( _environment, (yyvsp[-1].string) )->name;
    }
#line 3197 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: ABS OP expr CP  */
#line 432 "src/ugbc.y"
                     {
        (yyval.string) = variable_abs( _environment, (yyvsp[-1].string) )->name;
    }
#line 3205 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: TRUE  */
#line 435 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3214 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: FALSE  */
#line 439 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3223 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: COLORS  */
#line 443 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3232 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: WIDTH  */
#line 447 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3240 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: HEIGHT  */
#line 450 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3248 "src-generated/ugbc.tab.c"
    break;

  case 110: /* bank_definition_simple: AT direct_integer  */
#line 458 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3256 "src-generated/ugbc.tab.c"
    break;

  case 111: /* bank_definition_simple: Identifier AT direct_integer  */
#line 461 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3264 "src-generated/ugbc.tab.c"
    break;

  case 112: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 464 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3272 "src-generated/ugbc.tab.c"
    break;

  case 113: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 467 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3280 "src-generated/ugbc.tab.c"
    break;

  case 114: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 470 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3288 "src-generated/ugbc.tab.c"
    break;

  case 115: /* bank_definition_simple: DATA AT direct_integer  */
#line 473 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3296 "src-generated/ugbc.tab.c"
    break;

  case 116: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 477 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3304 "src-generated/ugbc.tab.c"
    break;

  case 117: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 480 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3312 "src-generated/ugbc.tab.c"
    break;

  case 118: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 483 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3320 "src-generated/ugbc.tab.c"
    break;

  case 119: /* bank_definition_simple: CODE AT direct_integer  */
#line 486 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3328 "src-generated/ugbc.tab.c"
    break;

  case 120: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 490 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3336 "src-generated/ugbc.tab.c"
    break;

  case 121: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 493 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3344 "src-generated/ugbc.tab.c"
    break;

  case 122: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 496 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3352 "src-generated/ugbc.tab.c"
    break;

  case 123: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 499 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3360 "src-generated/ugbc.tab.c"
    break;

  case 124: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 503 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3368 "src-generated/ugbc.tab.c"
    break;

  case 125: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 506 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3376 "src-generated/ugbc.tab.c"
    break;

  case 126: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 509 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3384 "src-generated/ugbc.tab.c"
    break;

  case 127: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 512 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3392 "src-generated/ugbc.tab.c"
    break;

  case 128: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 518 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3400 "src-generated/ugbc.tab.c"
    break;

  case 129: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 521 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3408 "src-generated/ugbc.tab.c"
    break;

  case 130: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 524 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3416 "src-generated/ugbc.tab.c"
    break;

  case 131: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 527 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3424 "src-generated/ugbc.tab.c"
    break;

  case 132: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 530 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3432 "src-generated/ugbc.tab.c"
    break;

  case 135: /* raster_definition_simple: Identifier AT direct_integer  */
#line 539 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3440 "src-generated/ugbc.tab.c"
    break;

  case 136: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 542 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3448 "src-generated/ugbc.tab.c"
    break;

  case 137: /* raster_definition_expression: Identifier AT expr  */
#line 547 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3456 "src-generated/ugbc.tab.c"
    break;

  case 138: /* raster_definition_expression: AT expr WITH Identifier  */
#line 550 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3464 "src-generated/ugbc.tab.c"
    break;

  case 141: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 559 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3472 "src-generated/ugbc.tab.c"
    break;

  case 142: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 562 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3480 "src-generated/ugbc.tab.c"
    break;

  case 143: /* next_raster_definition_expression: Identifier AT expr  */
#line 567 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3488 "src-generated/ugbc.tab.c"
    break;

  case 144: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 570 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3496 "src-generated/ugbc.tab.c"
    break;

  case 147: /* color_definition_simple: BORDER direct_integer  */
#line 579 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3504 "src-generated/ugbc.tab.c"
    break;

  case 148: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 582 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3512 "src-generated/ugbc.tab.c"
    break;

  case 149: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 585 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3520 "src-generated/ugbc.tab.c"
    break;

  case 150: /* color_definition_expression: BORDER expr  */
#line 590 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3528 "src-generated/ugbc.tab.c"
    break;

  case 151: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 593 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3536 "src-generated/ugbc.tab.c"
    break;

  case 152: /* color_definition_expression: SPRITE expr TO expr  */
#line 596 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3544 "src-generated/ugbc.tab.c"
    break;

  case 158: /* wait_definition_simple: direct_integer CYCLES  */
#line 610 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3552 "src-generated/ugbc.tab.c"
    break;

  case 159: /* wait_definition_simple: direct_integer TICKS  */
#line 613 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3560 "src-generated/ugbc.tab.c"
    break;

  case 160: /* wait_definition_simple: direct_integer milliseconds  */
#line 616 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3568 "src-generated/ugbc.tab.c"
    break;

  case 161: /* wait_definition_expression: expr CYCLES  */
#line 621 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3576 "src-generated/ugbc.tab.c"
    break;

  case 162: /* wait_definition_expression: expr TICKS  */
#line 624 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3584 "src-generated/ugbc.tab.c"
    break;

  case 163: /* wait_definition_expression: expr milliseconds  */
#line 627 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3592 "src-generated/ugbc.tab.c"
    break;

  case 166: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 637 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3600 "src-generated/ugbc.tab.c"
    break;

  case 167: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 640 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3608 "src-generated/ugbc.tab.c"
    break;

  case 168: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 643 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3616 "src-generated/ugbc.tab.c"
    break;

  case 169: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 646 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3624 "src-generated/ugbc.tab.c"
    break;

  case 170: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 649 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3632 "src-generated/ugbc.tab.c"
    break;

  case 171: /* sprite_definition_simple: direct_integer ENABLE  */
#line 652 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3640 "src-generated/ugbc.tab.c"
    break;

  case 172: /* sprite_definition_simple: direct_integer DISABLE  */
#line 655 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3648 "src-generated/ugbc.tab.c"
    break;

  case 173: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 658 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3656 "src-generated/ugbc.tab.c"
    break;

  case 174: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 661 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3664 "src-generated/ugbc.tab.c"
    break;

  case 175: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 664 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3672 "src-generated/ugbc.tab.c"
    break;

  case 176: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 667 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3680 "src-generated/ugbc.tab.c"
    break;

  case 177: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 670 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3688 "src-generated/ugbc.tab.c"
    break;

  case 178: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 673 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3696 "src-generated/ugbc.tab.c"
    break;

  case 179: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 676 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3704 "src-generated/ugbc.tab.c"
    break;

  case 180: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 679 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3712 "src-generated/ugbc.tab.c"
    break;

  case 181: /* sprite_definition_expression: expr DATA FROM expr  */
#line 684 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3720 "src-generated/ugbc.tab.c"
    break;

  case 182: /* sprite_definition_expression: expr MULTICOLOR  */
#line 687 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3728 "src-generated/ugbc.tab.c"
    break;

  case 183: /* sprite_definition_expression: expr MONOCOLOR  */
#line 690 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3736 "src-generated/ugbc.tab.c"
    break;

  case 184: /* sprite_definition_expression: expr COLOR expr  */
#line 693 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3744 "src-generated/ugbc.tab.c"
    break;

  case 185: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 696 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3752 "src-generated/ugbc.tab.c"
    break;

  case 186: /* sprite_definition_expression: expr ENABLE  */
#line 699 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3760 "src-generated/ugbc.tab.c"
    break;

  case 187: /* sprite_definition_expression: expr DISABLE  */
#line 702 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3768 "src-generated/ugbc.tab.c"
    break;

  case 188: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 705 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3776 "src-generated/ugbc.tab.c"
    break;

  case 189: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 708 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3784 "src-generated/ugbc.tab.c"
    break;

  case 190: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 711 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3792 "src-generated/ugbc.tab.c"
    break;

  case 191: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 714 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3800 "src-generated/ugbc.tab.c"
    break;

  case 192: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 717 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3808 "src-generated/ugbc.tab.c"
    break;

  case 193: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 720 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3816 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 723 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3824 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 726 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3832 "src-generated/ugbc.tab.c"
    break;

  case 198: /* bitmap_definition_simple: AT direct_integer  */
#line 735 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3840 "src-generated/ugbc.tab.c"
    break;

  case 199: /* bitmap_definition_simple: ENABLE  */
#line 738 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3848 "src-generated/ugbc.tab.c"
    break;

  case 200: /* bitmap_definition_simple: DISABLE  */
#line 741 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 3856 "src-generated/ugbc.tab.c"
    break;

  case 201: /* bitmap_definition_simple: CLEAR  */
#line 744 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 3864 "src-generated/ugbc.tab.c"
    break;

  case 202: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 747 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 3872 "src-generated/ugbc.tab.c"
    break;

  case 203: /* bitmap_definition_expression: AT expr  */
#line 753 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3880 "src-generated/ugbc.tab.c"
    break;

  case 204: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 756 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 3888 "src-generated/ugbc.tab.c"
    break;

  case 207: /* textmap_definition_simple: AT direct_integer  */
#line 766 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3896 "src-generated/ugbc.tab.c"
    break;

  case 208: /* textmap_definition_expression: AT expr  */
#line 771 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3904 "src-generated/ugbc.tab.c"
    break;

  case 211: /* text_definition_simple: ENABLE  */
#line 780 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3912 "src-generated/ugbc.tab.c"
    break;

  case 212: /* text_definition_simple: DISABLE  */
#line 783 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 3920 "src-generated/ugbc.tab.c"
    break;

  case 213: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 788 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 3928 "src-generated/ugbc.tab.c"
    break;

  case 214: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 791 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 3936 "src-generated/ugbc.tab.c"
    break;

  case 217: /* tiles_definition_simple: AT direct_integer  */
#line 800 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 3944 "src-generated/ugbc.tab.c"
    break;

  case 218: /* tiles_definition_expression: AT expr  */
#line 805 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 3952 "src-generated/ugbc.tab.c"
    break;

  case 221: /* colormap_definition_simple: AT direct_integer  */
#line 814 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 3960 "src-generated/ugbc.tab.c"
    break;

  case 222: /* colormap_definition_simple: CLEAR  */
#line 817 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 3968 "src-generated/ugbc.tab.c"
    break;

  case 223: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 820 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3976 "src-generated/ugbc.tab.c"
    break;

  case 224: /* colormap_definition_expression: AT expr  */
#line 825 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3984 "src-generated/ugbc.tab.c"
    break;

  case 225: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 828 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3992 "src-generated/ugbc.tab.c"
    break;

  case 228: /* screen_definition_simple: ON  */
#line 838 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4000 "src-generated/ugbc.tab.c"
    break;

  case 229: /* screen_definition_simple: OFF  */
#line 841 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4008 "src-generated/ugbc.tab.c"
    break;

  case 230: /* screen_definition_simple: ROWS direct_integer  */
#line 844 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4016 "src-generated/ugbc.tab.c"
    break;

  case 231: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 847 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4024 "src-generated/ugbc.tab.c"
    break;

  case 232: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 850 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4032 "src-generated/ugbc.tab.c"
    break;

  case 233: /* screen_definition_expression: ROWS expr  */
#line 855 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4040 "src-generated/ugbc.tab.c"
    break;

  case 234: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 858 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4048 "src-generated/ugbc.tab.c"
    break;

  case 235: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 861 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4056 "src-generated/ugbc.tab.c"
    break;

  case 239: /* var_definition_simple: Identifier ON Identifier  */
#line 870 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4064 "src-generated/ugbc.tab.c"
    break;

  case 240: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 873 "src/ugbc.y"
                                    {
      variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4072 "src-generated/ugbc.tab.c"
    break;

  case 241: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 876 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4080 "src-generated/ugbc.tab.c"
    break;

  case 242: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 879 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4090 "src-generated/ugbc.tab.c"
    break;

  case 243: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 884 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4100 "src-generated/ugbc.tab.c"
    break;

  case 244: /* goto_definition: Identifier  */
#line 891 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4108 "src-generated/ugbc.tab.c"
    break;

  case 245: /* goto_definition: Integer  */
#line 894 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4116 "src-generated/ugbc.tab.c"
    break;

  case 246: /* gosub_definition: Identifier  */
#line 900 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4124 "src-generated/ugbc.tab.c"
    break;

  case 247: /* gosub_definition: Integer  */
#line 903 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4132 "src-generated/ugbc.tab.c"
    break;

  case 249: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 912 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4140 "src-generated/ugbc.tab.c"
    break;

  case 250: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 918 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4148 "src-generated/ugbc.tab.c"
    break;

  case 253: /* ink_definition: expr  */
#line 927 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4156 "src-generated/ugbc.tab.c"
    break;

  case 254: /* on_goto_definition: Identifier  */
#line 932 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4165 "src-generated/ugbc.tab.c"
    break;

  case 255: /* $@1: %empty  */
#line 936 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4173 "src-generated/ugbc.tab.c"
    break;

  case 257: /* on_gosub_definition: Identifier  */
#line 941 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4182 "src-generated/ugbc.tab.c"
    break;

  case 258: /* $@2: %empty  */
#line 945 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4190 "src-generated/ugbc.tab.c"
    break;

  case 260: /* $@3: %empty  */
#line 950 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 4198 "src-generated/ugbc.tab.c"
    break;

  case 262: /* $@4: %empty  */
#line 953 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 4206 "src-generated/ugbc.tab.c"
    break;

  case 264: /* every_definition: expr TICKS GOSUB Identifier  */
#line 958 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 4214 "src-generated/ugbc.tab.c"
    break;

  case 265: /* every_definition: ON  */
#line 961 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 4222 "src-generated/ugbc.tab.c"
    break;

  case 266: /* every_definition: OFF  */
#line 964 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 4230 "src-generated/ugbc.tab.c"
    break;

  case 267: /* add_definition: Identifier COMMA expr  */
#line 969 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 4238 "src-generated/ugbc.tab.c"
    break;

  case 268: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 972 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4246 "src-generated/ugbc.tab.c"
    break;

  case 285: /* statement: INC Identifier  */
#line 994 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 4254 "src-generated/ugbc.tab.c"
    break;

  case 286: /* statement: DEC Identifier  */
#line 997 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 4262 "src-generated/ugbc.tab.c"
    break;

  case 287: /* statement: RANDOMIZE  */
#line 1000 "src/ugbc.y"
              {
      randomize( _environment );
  }
#line 4270 "src-generated/ugbc.tab.c"
    break;

  case 288: /* statement: IF expr THEN  */
#line 1003 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4278 "src-generated/ugbc.tab.c"
    break;

  case 289: /* statement: ELSE  */
#line 1006 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 4286 "src-generated/ugbc.tab.c"
    break;

  case 290: /* statement: ELSE IF expr THEN  */
#line 1009 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 4294 "src-generated/ugbc.tab.c"
    break;

  case 291: /* statement: ENDIF  */
#line 1012 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 4302 "src-generated/ugbc.tab.c"
    break;

  case 292: /* statement: DO  */
#line 1015 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 4310 "src-generated/ugbc.tab.c"
    break;

  case 293: /* statement: LOOP  */
#line 1018 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 4318 "src-generated/ugbc.tab.c"
    break;

  case 294: /* $@5: %empty  */
#line 1021 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 4326 "src-generated/ugbc.tab.c"
    break;

  case 295: /* statement: WHILE $@5 expr  */
#line 1023 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 4334 "src-generated/ugbc.tab.c"
    break;

  case 296: /* statement: WEND  */
#line 1026 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 4342 "src-generated/ugbc.tab.c"
    break;

  case 297: /* statement: REPEAT  */
#line 1029 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 4350 "src-generated/ugbc.tab.c"
    break;

  case 298: /* statement: UNTIL expr  */
#line 1032 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 4358 "src-generated/ugbc.tab.c"
    break;

  case 299: /* statement: EXIT  */
#line 1035 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 4366 "src-generated/ugbc.tab.c"
    break;

  case 300: /* statement: EXIT IF expr  */
#line 1038 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 4374 "src-generated/ugbc.tab.c"
    break;

  case 301: /* statement: EXIT Integer  */
#line 1041 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4382 "src-generated/ugbc.tab.c"
    break;

  case 302: /* statement: EXIT direct_integer  */
#line 1044 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4390 "src-generated/ugbc.tab.c"
    break;

  case 303: /* statement: EXIT IF expr COMMA Integer  */
#line 1047 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4398 "src-generated/ugbc.tab.c"
    break;

  case 304: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1050 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4406 "src-generated/ugbc.tab.c"
    break;

  case 305: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1053 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4414 "src-generated/ugbc.tab.c"
    break;

  case 306: /* statement: NEXT  */
#line 1056 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 4422 "src-generated/ugbc.tab.c"
    break;

  case 307: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1059 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4430 "src-generated/ugbc.tab.c"
    break;

  case 308: /* statement: BEG GAMELOOP  */
#line 1062 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 4438 "src-generated/ugbc.tab.c"
    break;

  case 309: /* statement: END GAMELOOP  */
#line 1065 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 4446 "src-generated/ugbc.tab.c"
    break;

  case 310: /* statement: GRAPHIC  */
#line 1068 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 4454 "src-generated/ugbc.tab.c"
    break;

  case 311: /* statement: HALT  */
#line 1071 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 4462 "src-generated/ugbc.tab.c"
    break;

  case 316: /* statement: RETURN  */
#line 1078 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 4470 "src-generated/ugbc.tab.c"
    break;

  case 317: /* statement: POP  */
#line 1081 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 4478 "src-generated/ugbc.tab.c"
    break;

  case 318: /* statement: DONE  */
#line 1084 "src/ugbc.y"
          {
      return 0;
  }
#line 4486 "src-generated/ugbc.tab.c"
    break;

  case 319: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1087 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4494 "src-generated/ugbc.tab.c"
    break;

  case 320: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1090 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4502 "src-generated/ugbc.tab.c"
    break;

  case 321: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1093 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 4510 "src-generated/ugbc.tab.c"
    break;

  case 322: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1096 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4518 "src-generated/ugbc.tab.c"
    break;

  case 323: /* statement: Identifier COLON  */
#line 1099 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 4526 "src-generated/ugbc.tab.c"
    break;

  case 324: /* statement: Identifier ASSIGN expr  */
#line 1102 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 4540 "src-generated/ugbc.tab.c"
    break;

  case 325: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1111 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 4554 "src-generated/ugbc.tab.c"
    break;

  case 326: /* statement: DEBUG expr  */
#line 1120 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 4562 "src-generated/ugbc.tab.c"
    break;

  case 329: /* statements_no_linenumbers: statement  */
#line 1128 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 4568 "src-generated/ugbc.tab.c"
    break;

  case 330: /* $@6: %empty  */
#line 1129 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 4574 "src-generated/ugbc.tab.c"
    break;

  case 332: /* $@7: %empty  */
#line 1133 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 4582 "src-generated/ugbc.tab.c"
    break;

  case 333: /* statements_with_linenumbers: Integer $@7 statements_no_linenumbers  */
#line 1135 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 4590 "src-generated/ugbc.tab.c"
    break;

  case 338: /* $@8: %empty  */
#line 1147 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 4596 "src-generated/ugbc.tab.c"
    break;


#line 4600 "src-generated/ugbc.tab.c"

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

#line 1149 "src/ugbc.y"


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

