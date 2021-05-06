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
  YYSYMBOL_INCREMENT = 10,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 11,                 /* DECREMENT  */
  YYSYMBOL_EQUAL = 12,                     /* EQUAL  */
  YYSYMBOL_ASSIGN = 13,                    /* ASSIGN  */
  YYSYMBOL_LT = 14,                        /* LT  */
  YYSYMBOL_LTE = 15,                       /* LTE  */
  YYSYMBOL_GT = 16,                        /* GT  */
  YYSYMBOL_GTE = 17,                       /* GTE  */
  YYSYMBOL_DISEQUAL = 18,                  /* DISEQUAL  */
  YYSYMBOL_MULTIPLICATION = 19,            /* MULTIPLICATION  */
  YYSYMBOL_DOLLAR = 20,                    /* DOLLAR  */
  YYSYMBOL_RASTER = 21,                    /* RASTER  */
  YYSYMBOL_DONE = 22,                      /* DONE  */
  YYSYMBOL_AT = 23,                        /* AT  */
  YYSYMBOL_COLOR = 24,                     /* COLOR  */
  YYSYMBOL_BORDER = 25,                    /* BORDER  */
  YYSYMBOL_WAIT = 26,                      /* WAIT  */
  YYSYMBOL_NEXT = 27,                      /* NEXT  */
  YYSYMBOL_WITH = 28,                      /* WITH  */
  YYSYMBOL_BANK = 29,                      /* BANK  */
  YYSYMBOL_SPRITE = 30,                    /* SPRITE  */
  YYSYMBOL_DATA = 31,                      /* DATA  */
  YYSYMBOL_FROM = 32,                      /* FROM  */
  YYSYMBOL_OP = 33,                        /* OP  */
  YYSYMBOL_CP = 34,                        /* CP  */
  YYSYMBOL_ENABLE = 35,                    /* ENABLE  */
  YYSYMBOL_DISABLE = 36,                   /* DISABLE  */
  YYSYMBOL_HALT = 37,                      /* HALT  */
  YYSYMBOL_ECM = 38,                       /* ECM  */
  YYSYMBOL_BITMAP = 39,                    /* BITMAP  */
  YYSYMBOL_SCREEN = 40,                    /* SCREEN  */
  YYSYMBOL_ON = 41,                        /* ON  */
  YYSYMBOL_OFF = 42,                       /* OFF  */
  YYSYMBOL_ROWS = 43,                      /* ROWS  */
  YYSYMBOL_VERTICAL = 44,                  /* VERTICAL  */
  YYSYMBOL_SCROLL = 45,                    /* SCROLL  */
  YYSYMBOL_VAR = 46,                       /* VAR  */
  YYSYMBOL_AS = 47,                        /* AS  */
  YYSYMBOL_TEMPORARY = 48,                 /* TEMPORARY  */
  YYSYMBOL_XPEN = 49,                      /* XPEN  */
  YYSYMBOL_YPEN = 50,                      /* YPEN  */
  YYSYMBOL_PEEK = 51,                      /* PEEK  */
  YYSYMBOL_GOTO = 52,                      /* GOTO  */
  YYSYMBOL_HORIZONTAL = 53,                /* HORIZONTAL  */
  YYSYMBOL_MCM = 54,                       /* MCM  */
  YYSYMBOL_COMPRESS = 55,                  /* COMPRESS  */
  YYSYMBOL_EXPAND = 56,                    /* EXPAND  */
  YYSYMBOL_LOOP = 57,                      /* LOOP  */
  YYSYMBOL_REPEAT = 58,                    /* REPEAT  */
  YYSYMBOL_WHILE = 59,                     /* WHILE  */
  YYSYMBOL_TEXT = 60,                      /* TEXT  */
  YYSYMBOL_TILES = 61,                     /* TILES  */
  YYSYMBOL_COLORMAP = 62,                  /* COLORMAP  */
  YYSYMBOL_SELECT = 63,                    /* SELECT  */
  YYSYMBOL_MONOCOLOR = 64,                 /* MONOCOLOR  */
  YYSYMBOL_MULTICOLOR = 65,                /* MULTICOLOR  */
  YYSYMBOL_COLLISION = 66,                 /* COLLISION  */
  YYSYMBOL_IF = 67,                        /* IF  */
  YYSYMBOL_THEN = 68,                      /* THEN  */
  YYSYMBOL_HIT = 69,                       /* HIT  */
  YYSYMBOL_BACKGROUND = 70,                /* BACKGROUND  */
  YYSYMBOL_TO = 71,                        /* TO  */
  YYSYMBOL_RANDOM = 72,                    /* RANDOM  */
  YYSYMBOL_BYTE = 73,                      /* BYTE  */
  YYSYMBOL_WORD = 74,                      /* WORD  */
  YYSYMBOL_POSITION = 75,                  /* POSITION  */
  YYSYMBOL_CODE = 76,                      /* CODE  */
  YYSYMBOL_VARIABLES = 77,                 /* VARIABLES  */
  YYSYMBOL_MS = 78,                        /* MS  */
  YYSYMBOL_CYCLES = 79,                    /* CYCLES  */
  YYSYMBOL_S = 80,                         /* S  */
  YYSYMBOL_HASH = 81,                      /* HASH  */
  YYSYMBOL_WIDTH = 82,                     /* WIDTH  */
  YYSYMBOL_HEIGHT = 83,                    /* HEIGHT  */
  YYSYMBOL_DWORD = 84,                     /* DWORD  */
  YYSYMBOL_PEN = 85,                       /* PEN  */
  YYSYMBOL_CLEAR = 86,                     /* CLEAR  */
  YYSYMBOL_BEG = 87,                       /* BEG  */
  YYSYMBOL_END = 88,                       /* END  */
  YYSYMBOL_GAMELOOP = 89,                  /* GAMELOOP  */
  YYSYMBOL_ENDIF = 90,                     /* ENDIF  */
  YYSYMBOL_UP = 91,                        /* UP  */
  YYSYMBOL_DOWN = 92,                      /* DOWN  */
  YYSYMBOL_LEFT = 93,                      /* LEFT  */
  YYSYMBOL_RIGHT = 94,                     /* RIGHT  */
  YYSYMBOL_DEBUG = 95,                     /* DEBUG  */
  YYSYMBOL_AND = 96,                       /* AND  */
  YYSYMBOL_RANDOMIZE = 97,                 /* RANDOMIZE  */
  YYSYMBOL_GRAPHIC = 98,                   /* GRAPHIC  */
  YYSYMBOL_TEXTMAP = 99,                   /* TEXTMAP  */
  YYSYMBOL_POINT = 100,                    /* POINT  */
  YYSYMBOL_GOSUB = 101,                    /* GOSUB  */
  YYSYMBOL_RETURN = 102,                   /* RETURN  */
  YYSYMBOL_POP = 103,                      /* POP  */
  YYSYMBOL_OR = 104,                       /* OR  */
  YYSYMBOL_ELSE = 105,                     /* ELSE  */
  YYSYMBOL_NOT = 106,                      /* NOT  */
  YYSYMBOL_TRUE = 107,                     /* TRUE  */
  YYSYMBOL_FALSE = 108,                    /* FALSE  */
  YYSYMBOL_DO = 109,                       /* DO  */
  YYSYMBOL_EXIT = 110,                     /* EXIT  */
  YYSYMBOL_WEND = 111,                     /* WEND  */
  YYSYMBOL_UNTIL = 112,                    /* UNTIL  */
  YYSYMBOL_FOR = 113,                      /* FOR  */
  YYSYMBOL_STEP = 114,                     /* STEP  */
  YYSYMBOL_EVERY = 115,                    /* EVERY  */
  YYSYMBOL_MID = 116,                      /* MID  */
  YYSYMBOL_INSTR = 117,                    /* INSTR  */
  YYSYMBOL_UPPER = 118,                    /* UPPER  */
  YYSYMBOL_LOWER = 119,                    /* LOWER  */
  YYSYMBOL_STR = 120,                      /* STR  */
  YYSYMBOL_VAL = 121,                      /* VAL  */
  YYSYMBOL_STRING = 122,                   /* STRING  */
  YYSYMBOL_SPACE = 123,                    /* SPACE  */
  YYSYMBOL_FLIP = 124,                     /* FLIP  */
  YYSYMBOL_CHR = 125,                      /* CHR  */
  YYSYMBOL_ASC = 126,                      /* ASC  */
  YYSYMBOL_LEN = 127,                      /* LEN  */
  YYSYMBOL_POW = 128,                      /* POW  */
  YYSYMBOL_MILLISECOND = 129,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 130,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 131,                    /* TICKS  */
  YYSYMBOL_BLACK = 132,                    /* BLACK  */
  YYSYMBOL_WHITE = 133,                    /* WHITE  */
  YYSYMBOL_RED = 134,                      /* RED  */
  YYSYMBOL_CYAN = 135,                     /* CYAN  */
  YYSYMBOL_VIOLET = 136,                   /* VIOLET  */
  YYSYMBOL_GREEN = 137,                    /* GREEN  */
  YYSYMBOL_BLUE = 138,                     /* BLUE  */
  YYSYMBOL_YELLOW = 139,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 140,                   /* ORANGE  */
  YYSYMBOL_BROWN = 141,                    /* BROWN  */
  YYSYMBOL_LIGHT = 142,                    /* LIGHT  */
  YYSYMBOL_DARK = 143,                     /* DARK  */
  YYSYMBOL_GREY = 144,                     /* GREY  */
  YYSYMBOL_GRAY = 145,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 146,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 147,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 148,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 149,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 150,                /* TURQUOISE  */
  YYSYMBOL_TAN = 151,                      /* TAN  */
  YYSYMBOL_PINK = 152,                     /* PINK  */
  YYSYMBOL_PEACH = 153,                    /* PEACH  */
  YYSYMBOL_OLIVE = 154,                    /* OLIVE  */
  YYSYMBOL_Identifier = 155,               /* Identifier  */
  YYSYMBOL_String = 156,                   /* String  */
  YYSYMBOL_Integer = 157,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 158,                 /* $accept  */
  YYSYMBOL_direct_integer = 159,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 160, /* random_definition_simple  */
  YYSYMBOL_random_definition = 161,        /* random_definition  */
  YYSYMBOL_color_enumeration = 162,        /* color_enumeration  */
  YYSYMBOL_expression = 163,               /* expression  */
  YYSYMBOL_expressions_raw = 164,          /* expressions_raw  */
  YYSYMBOL_expressions = 165,              /* expressions  */
  YYSYMBOL_position = 166,                 /* position  */
  YYSYMBOL_bank_definition_simple = 167,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 168, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 169,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 170, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 171, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 172,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 173, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 174, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 175,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 176,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 177, /* color_definition_expression  */
  YYSYMBOL_color_definition = 178,         /* color_definition  */
  YYSYMBOL_milliseconds = 179,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 180,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 181, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 182,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 183, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 184, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 185,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 186, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 187, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 188,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 189, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 190, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 191,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 192,   /* text_definition_simple  */
  YYSYMBOL_text_definition = 193,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 194,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 195, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 196,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 197, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 198, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 199,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 200, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 201, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 202,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 203,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 204,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 205,         /* gosub_definition  */
  YYSYMBOL_var_definition = 206,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 207,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 208, /* point_definition_expression  */
  YYSYMBOL_point_definition = 209,         /* point_definition  */
  YYSYMBOL_on_goto_definition = 210,       /* on_goto_definition  */
  YYSYMBOL_211_1 = 211,                    /* $@1  */
  YYSYMBOL_on_gosub_definition = 212,      /* on_gosub_definition  */
  YYSYMBOL_213_2 = 213,                    /* $@2  */
  YYSYMBOL_on_definition = 214,            /* on_definition  */
  YYSYMBOL_215_3 = 215,                    /* $@3  */
  YYSYMBOL_216_4 = 216,                    /* $@4  */
  YYSYMBOL_every_definition = 217,         /* every_definition  */
  YYSYMBOL_statement = 218,                /* statement  */
  YYSYMBOL_219_5 = 219,                    /* $@5  */
  YYSYMBOL_statements_no_linenumbers = 220, /* statements_no_linenumbers  */
  YYSYMBOL_221_6 = 221,                    /* $@6  */
  YYSYMBOL_statements_with_linenumbers = 222, /* statements_with_linenumbers  */
  YYSYMBOL_223_7 = 223,                    /* $@7  */
  YYSYMBOL_statements_complex = 224,       /* statements_complex  */
  YYSYMBOL_program = 225,                  /* program  */
  YYSYMBOL_226_8 = 226                     /* $@8  */
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
#define YYLAST   1078

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  158
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  312
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  594

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   412


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
     155,   156,   157
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    68,    71,    74,    77,    80,    83,    86,
      91,    96,   100,   104,   108,   112,   116,   120,   124,   128,
     132,   136,   140,   144,   148,   152,   156,   160,   164,   168,
     172,   176,   180,   184,   188,   192,   196,   200,   206,   209,
     212,   216,   223,   227,   231,   235,   239,   243,   246,   249,
     252,   255,   258,   261,   264,   267,   270,   273,   276,   279,
     282,   285,   288,   291,   294,   297,   300,   303,   306,   309,
     312,   315,   318,   321,   324,   328,   332,   338,   339,   342,
     346,   350,   354,   358,   362,   365,   368,   371,   374,   377,
     383,   387,   387,   390,   393,   396,   399,   402,   405,   409,
     412,   415,   418,   422,   425,   428,   431,   435,   438,   441,
     444,   450,   453,   456,   459,   462,   467,   468,   471,   474,
     479,   482,   487,   488,   491,   494,   499,   502,   507,   508,
     511,   514,   517,   522,   525,   528,   533,   534,   537,   538,
     539,   542,   545,   548,   553,   556,   559,   565,   566,   569,
     572,   575,   578,   581,   584,   587,   590,   593,   596,   599,
     602,   605,   608,   611,   616,   619,   622,   625,   628,   631,
     634,   637,   640,   643,   646,   649,   652,   655,   658,   663,
     664,   667,   670,   673,   676,   679,   685,   688,   694,   695,
     698,   703,   708,   709,   712,   715,   720,   723,   728,   733,
     734,   737,   740,   743,   748,   751,   757,   758,   761,   764,
     767,   770,   773,   778,   781,   784,   789,   790,   792,   793,
     796,   799,   802,   807,   814,   817,   823,   826,   832,   835,
     841,   846,   847,   850,   854,   854,   859,   863,   863,   868,
     868,   871,   871,   876,   879,   882,   887,   888,   889,   890,
     891,   892,   893,   894,   895,   896,   897,   898,   899,   900,
     901,   904,   907,   910,   913,   916,   919,   922,   922,   927,
     930,   933,   936,   939,   942,   945,   948,   951,   954,   957,
     960,   963,   966,   969,   972,   975,   976,   977,   978,   979,
     982,   985,   988,   991,   994,   997,  1000,  1003,  1012,  1021,
    1024,  1025,  1029,  1030,  1030,  1034,  1034,  1041,  1042,  1043,
    1044,  1048,  1048
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
  "SEMICOLON", "COLON", "COMMA", "PLUS", "MINUS", "INCREMENT", "DECREMENT",
  "EQUAL", "ASSIGN", "LT", "LTE", "GT", "GTE", "DISEQUAL",
  "MULTIPLICATION", "DOLLAR", "RASTER", "DONE", "AT", "COLOR", "BORDER",
  "WAIT", "NEXT", "WITH", "BANK", "SPRITE", "DATA", "FROM", "OP", "CP",
  "ENABLE", "DISABLE", "HALT", "ECM", "BITMAP", "SCREEN", "ON", "OFF",
  "ROWS", "VERTICAL", "SCROLL", "VAR", "AS", "TEMPORARY", "XPEN", "YPEN",
  "PEEK", "GOTO", "HORIZONTAL", "MCM", "COMPRESS", "EXPAND", "LOOP",
  "REPEAT", "WHILE", "TEXT", "TILES", "COLORMAP", "SELECT", "MONOCOLOR",
  "MULTICOLOR", "COLLISION", "IF", "THEN", "HIT", "BACKGROUND", "TO",
  "RANDOM", "BYTE", "WORD", "POSITION", "CODE", "VARIABLES", "MS",
  "CYCLES", "S", "HASH", "WIDTH", "HEIGHT", "DWORD", "PEN", "CLEAR", "BEG",
  "END", "GAMELOOP", "ENDIF", "UP", "DOWN", "LEFT", "RIGHT", "DEBUG",
  "AND", "RANDOMIZE", "GRAPHIC", "TEXTMAP", "POINT", "GOSUB", "RETURN",
  "POP", "OR", "ELSE", "NOT", "TRUE", "FALSE", "DO", "EXIT", "WEND",
  "UNTIL", "FOR", "STEP", "EVERY", "MID", "INSTR", "UPPER", "LOWER", "STR",
  "VAL", "STRING", "SPACE", "FLIP", "CHR", "ASC", "LEN", "POW",
  "MILLISECOND", "MILLISECONDS", "TICKS", "BLACK", "WHITE", "RED", "CYAN",
  "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE", "BROWN", "LIGHT", "DARK",
  "GREY", "GRAY", "MAGENTA", "PURPLE", "LAVENDER", "GOLD", "TURQUOISE",
  "TAN", "PINK", "PEACH", "OLIVE", "Identifier", "String", "Integer",
  "$accept", "direct_integer", "random_definition_simple",
  "random_definition", "color_enumeration", "expression",
  "expressions_raw", "expressions", "position", "bank_definition_simple",
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
  "textmap_definition", "text_definition_simple", "text_definition",
  "tiles_definition_simple", "tiles_definition_expression",
  "tiles_definition", "colormap_definition_simple",
  "colormap_definition_expression", "colormap_definition",
  "screen_definition_simple", "screen_definition_expression",
  "screen_definition", "var_definition_simple", "goto_definition",
  "gosub_definition", "var_definition", "point_definition_simple",
  "point_definition_expression", "point_definition", "on_goto_definition",
  "$@1", "on_gosub_definition", "$@2", "on_definition", "$@3", "$@4",
  "every_definition", "statement", "$@5", "statements_no_linenumbers",
  "$@6", "statements_with_linenumbers", "$@7", "statements_complex",
  "program", "$@8", YY_NULLPTR
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
     405,   406,   407,   408,   409,   410,   411,   412
};
#endif

#define YYPACT_NINF (-203)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-238)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -203,    16,   512,  -203,  -203,   -20,  -203,    34,   809,    32,
     -22,   809,  -203,     0,    73,   921,   -90,  -127,  -203,  -203,
    -203,    67,    52,    -1,   921,    33,    42,  -203,    72,   103,
     921,  -203,  -203,   118,   129,  -115,  -203,  -203,    92,  -203,
     -61,  -203,   921,     1,   334,   121,    19,  -203,   154,   158,
     159,  -203,   809,   141,  -203,  -203,  -203,   809,   809,   809,
    -203,  -203,  -203,   697,  -203,  -203,   132,   134,   136,     9,
      13,   138,   139,   921,  -203,  -203,   140,   142,   143,   144,
     148,   149,   150,   151,   152,   153,   155,   160,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,    50,  -203,  -203,   -37,  -101,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,    55,
     174,  -203,  -203,   -21,  -203,    62,  -203,   -18,  -203,  -203,
    -203,   -16,   114,   -15,   -13,   -12,    -8,   173,  -203,  -203,
    -203,   192,   207,  -203,  -203,  -203,   809,  -203,  -203,   189,
    -203,  -203,  -203,  -203,  -203,   809,   176,   177,  -203,  -203,
    -203,   -38,  -203,    -3,  -203,  -203,  -203,  -203,  -203,   921,
    -203,  -203,  -203,  -203,   809,  -203,  -203,  -203,   809,   190,
    -203,  -203,  -203,   156,  -203,  -203,   921,   921,  -203,   809,
    -203,  -203,  -203,   186,  -203,  -203,  -203,  -203,  -203,  -203,
     921,   921,  -203,  -203,  -203,   212,  -203,  -203,    98,  -203,
     921,  -203,   921,   213,   613,  -203,   512,   512,   204,   209,
     809,  -203,  -203,   168,   169,   170,   175,   210,   215,   216,
     218,   219,   220,   809,   809,   809,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,   921,   921,  -203,   921,
     921,   921,   921,   921,   921,   921,   921,   921,   921,   921,
     921,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,   921,   921,   921,   921,
     921,   921,   921,   921,   921,   921,   921,   921,  -203,  -203,
    -203,   809,   232,  -203,  -203,  -203,   211,   114,   236,   114,
     238,   114,   241,   114,   242,   114,  -203,   114,   234,  -203,
    -203,    65,    68,    45,    46,  -203,  -203,  -203,   235,   921,
     237,  -203,  -203,    89,    95,    74,    75,  -203,  -203,   240,
    -203,  -203,   809,  -203,  -203,   809,   809,  -203,  -203,   233,
     120,  -203,  -203,  -203,  -203,  -203,   809,  -203,   269,   270,
    -203,  -203,   809,   217,   271,   921,   178,   273,  -203,   921,
    -203,   613,  -203,  -203,   126,   128,  -203,  -203,   114,   921,
     114,   921,   127,   130,   131,   133,   135,  -203,   252,   255,
     259,   260,   261,   262,   293,   295,   297,   299,   274,   275,
     276,   278,   306,   282,   283,   284,   285,   286,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
     294,   296,   809,    -4,  -203,   114,  -203,   114,  -203,   114,
    -203,   114,    59,  -203,   114,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,   114,  -203,   921,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,   921,  -203,  -203,  -203,  -203,  -203,
    -203,   166,   171,   172,   310,   287,   288,   921,   921,   323,
     326,  -203,   -69,   266,   184,   921,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,   921,   921,   921,   921,  -203,
    -203,  -203,  -203,   921,  -203,  -203,  -203,  -203,  -203,   185,
     187,  -203,  -203,  -203,  -203,  -203,  -203,   313,  -203,   315,
    -203,   188,    18,  -203,   338,  -203,   340,   342,  -203,   344,
    -203,   352,   809,   114,   921,   332,   335,   114,   921,  -203,
    -203,   921,  -203,    11,   337,   339,    17,    22,   343,  -203,
    -203,   222,   223,  -203,   346,  -203,   353,  -203,   114,   921,
     365,   373,   921,  -203,  -203,  -203,  -203,   369,   374,   354,
     355,   272,   921,   377,  -203,  -203,   921,  -203,   921,  -203,
    -203,  -203,  -203,   239,   243,   358,   359,   166,   171,  -203,
     921,   921,  -203,  -203,   921,   360,   921,   362,   363,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,   385,  -203,
    -203,  -203,   921,  -203
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     311,     0,   301,     1,   300,     0,   291,     0,     0,   279,
       0,     0,   284,     0,     0,     0,   218,     0,   266,   270,
     267,     0,     0,     0,     0,     0,     0,   264,     0,     0,
       0,   260,   283,     0,     0,     0,   289,   290,   262,   265,
     272,   269,     0,     0,     0,     0,     0,   305,   302,   307,
     309,   312,     0,     0,   122,   123,   247,     0,     0,     0,
     136,   137,   249,     0,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
      23,    28,    29,    30,    31,    32,    33,    36,    37,     0,
      38,    41,    40,     0,    47,    77,    90,     0,   147,   148,
     250,     0,     0,     0,     0,     0,     0,     0,   116,   117,
     246,     0,     0,   179,   180,   251,     0,   182,   183,   184,
     188,   189,   252,   208,   209,     0,     0,     0,   216,   217,
     257,     0,   285,     0,   228,   259,   224,   225,   286,     0,
     194,   195,   196,   254,     0,   199,   200,   255,     0,   202,
     206,   207,   256,     0,   281,   282,     0,     0,   299,     0,
     192,   193,   253,     0,   231,   232,   258,   226,   227,   287,
       0,     0,   274,   275,   271,     0,   244,   245,     0,   288,
       0,   296,     0,     0,   301,   303,   301,   301,     0,     0,
       0,   130,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     3,     4,     6,
       8,     9,     5,    10,    72,     2,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    21,    24,    25,    26,    27,    22,    35,    39,
     138,   141,   139,   140,   142,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144,   145,
     146,     0,     0,   128,   129,   248,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,   154,
     155,     0,     0,     0,     0,   151,   150,    91,     0,     0,
       0,   169,   170,     0,     0,     0,     0,   166,   165,     0,
     181,   186,     0,   210,   213,     0,     0,   239,   241,     0,
       0,   268,   197,   198,   201,   204,     0,   261,     0,     0,
     190,   191,     0,     0,   273,     0,     0,     0,   297,     0,
     306,   301,   308,   310,     0,     0,   118,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    79,
      84,    86,    87,    88,    89,    85,    80,    81,    82,    83,
       0,     0,     0,     0,    98,     0,   110,     0,   102,     0,
     106,     0,    94,   152,     0,   159,   158,   163,   162,   157,
     161,   156,   160,     0,   167,     0,   174,   173,   178,   177,
     172,   176,   171,   175,     0,   185,   187,   211,   214,   212,
     215,     0,     0,     0,   219,     0,     0,     0,     0,     0,
       0,   263,     0,     0,     0,     0,   298,   304,   119,   121,
     132,   135,   131,   134,    46,    42,    43,    45,    44,    48,
      49,    52,    53,    54,    55,     0,     0,     0,     0,    62,
      63,    64,    71,     0,    65,    66,    67,    68,    69,     0,
       0,   124,   126,    95,   108,   100,   103,    97,   109,   101,
     105,     0,     0,   149,     0,   164,     0,   233,   240,   236,
     242,   220,     0,     0,     0,     0,     0,     0,     0,   276,
     277,     0,   243,     0,     0,     0,     0,     0,     0,   125,
     127,     0,     0,   111,    96,   107,    99,   104,     0,     0,
       0,     0,     0,   221,   222,   203,   205,     0,     0,     0,
       0,   278,     0,     0,    56,    57,     0,    58,     0,    60,
      70,   113,   115,     0,     0,     0,     0,     0,     0,   223,
       0,     0,   229,   230,     0,     0,     0,     0,     0,   112,
     114,   153,   168,   235,   238,   292,   293,   280,     0,   294,
      59,    61,     0,   295
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -203,    10,  -203,  -203,  -203,   -39,    87,   -11,   279,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,   290,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -166,  -203,  -164,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -202,  -203,  -203,  -203,   -77,  -203,  -203
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   113,   233,   234,   114,   115,   116,   117,   308,   128,
     129,   130,    54,    55,    56,   283,   284,   285,    60,    61,
      62,   265,   118,   119,   120,   133,   134,   135,   140,   141,
     142,   180,   181,   182,   162,   163,   165,   166,   167,   170,
     171,   172,   148,   149,   150,   154,   158,   189,   155,   184,
     185,   186,   508,   540,   510,   541,   152,   441,   442,   199,
      48,   159,    49,   351,    50,   204,    51,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     132,   122,   350,    52,   151,   198,   191,   281,   287,   123,
     289,   291,    70,   173,   327,   293,     3,   329,   552,   178,
      70,   131,   168,   136,   556,   201,   124,   493,   156,   558,
     157,   194,   202,   226,   238,   137,   138,   256,   330,   203,
     187,   209,   188,   257,   494,   553,   212,   214,   216,   534,
     193,   557,   222,   121,   125,   126,   559,   260,   261,    57,
     260,   278,   208,   328,    58,   153,   535,   211,   213,   215,
     266,   267,   495,   496,   268,   164,   269,   270,   271,   272,
     273,   274,   227,   228,   229,   169,   139,   501,   519,   419,
     421,   230,   231,   232,   536,   537,   192,   252,   420,   422,
     253,   254,   160,   161,    59,   176,   502,   255,   262,   263,
     264,   262,   263,   279,   143,   144,   145,   146,   430,   432,
     415,   416,   174,   417,   418,   321,   147,   431,   433,   352,
     353,   175,   286,   127,   324,    53,   177,   338,   339,   282,
     288,   179,   290,   292,   426,   427,   320,   294,   331,   457,
     428,   429,   183,   333,   200,   323,   195,   335,   275,   190,
     205,   347,   206,   207,   210,   223,   276,   224,   341,   225,
     235,   236,   237,   239,   332,   240,   241,   242,   334,   343,
     344,   243,   244,   245,   246,   247,   248,   251,   249,   340,
     277,   348,   258,   250,   259,    70,   295,   374,   375,   357,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   369,   371,   373,   296,   297,   322,   336,   342,
     356,   325,   326,   298,   337,   345,   349,   299,   300,   346,
     296,   309,   354,   368,   370,   372,   301,   355,   310,   358,
     359,   360,   311,   312,   362,   302,   361,   303,   304,   363,
     364,   313,   365,   366,   367,   402,   305,   306,   403,   405,
     314,   407,   315,   316,   409,   411,   414,   307,   423,   425,
     401,   317,   318,   434,   443,   444,   447,   448,   452,   454,
     455,   458,   307,   459,   464,   451,   469,   465,   466,   470,
     467,   400,   468,   471,   472,   473,   474,   404,   424,   406,
     475,   408,   476,   410,   477,   412,   478,   413,   479,   480,
     481,   436,   482,   483,   438,   440,   484,   485,   486,   487,
     488,   507,   489,   512,   490,   446,   509,   511,   513,   514,
     517,   450,   435,   518,   453,   437,   439,   521,   456,   522,
     529,   531,   530,   532,   533,   538,   445,   539,   461,  -234,
     463,  -237,   449,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   542,   547,    63,   460,   548,
     462,   554,   567,   555,   563,   196,   197,   560,   561,   562,
     568,   564,   570,    64,    65,    66,   574,   571,   572,   573,
     576,   492,   581,   582,   588,   579,   590,   591,   592,   580,
      67,   583,     0,    68,   584,     0,    69,   280,   515,   516,
       0,   319,   491,     0,   505,   497,   523,   498,     0,   499,
       0,   500,     0,   506,   503,     0,     0,    71,    72,     0,
       0,     0,     0,   504,     0,     0,   524,   525,   526,   527,
      73,    74,    75,     0,   528,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,   520,     0,     0,     0,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   544,     0,   546,     0,     0,     0,   550,     0,     0,
     551,     0,     0,   575,     0,     4,     0,   577,     0,   578,
       0,     0,   543,   545,     0,     0,     0,   549,   566,     0,
       0,   569,     0,     5,     6,     0,     7,     0,     8,     9,
       0,    10,    11,     0,     0,     0,     0,     0,   565,    12,
       0,    13,    14,    15,     0,     0,     0,     0,    16,   585,
     586,     0,     0,   587,    17,   589,     0,     0,     0,    18,
      19,    20,    21,    22,    23,     0,     0,     0,     0,    24,
       0,   593,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,     0,    27,     0,     0,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,     4,    38,     0,     0,
       0,    39,    40,    41,    42,    43,     0,    44,    45,     0,
       0,     0,     0,     0,     5,     6,     0,     7,     0,     8,
       9,     0,    10,    11,     0,     0,     0,     0,     0,     0,
      12,     0,    13,    14,    15,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,    17,     0,    46,     0,    47,
      18,    19,    20,    21,    22,    23,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,    27,     0,     0,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,     0,    38,     0,
       0,   217,    39,    40,    41,    42,    43,     0,    44,    45,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,     0,     0,    68,     0,    46,    69,
     218,   219,   220,     0,     0,     0,     0,     0,     0,     0,
       0,   221,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,    75,     0,     0,     0,     0,
       0,     0,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    63,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,     0,     0,    64,    65,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,     0,     0,    68,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,    75,     0,     0,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,     0,
       0,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    63,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,     0,     0,
      64,    65,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,     0,     0,
      68,     0,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    71,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,    75,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,     0,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112
};

static const yytype_int16 yycheck[] =
{
      11,    23,   204,    23,    15,    44,    67,    23,    23,    31,
      23,    23,    81,    24,    52,    23,     0,    20,     7,    30,
      81,    11,    23,    23,     7,     6,    48,    31,   155,     7,
     157,    42,    13,    24,    73,    35,    36,   138,    41,    20,
     155,    52,   157,   144,    48,    34,    57,    58,    59,    31,
      40,    34,    63,    21,    76,    77,    34,    78,    79,    25,
      78,    79,    52,   101,    30,   155,    48,    57,    58,    59,
       8,     9,    76,    77,    12,    23,    14,    15,    16,    17,
      18,    19,    73,    74,    75,    86,    86,    28,   157,    44,
      44,    82,    83,    84,    76,    77,   157,   134,    53,    53,
     137,   138,    35,    36,    70,    33,    47,   144,   129,   130,
     131,   129,   130,   131,    41,    42,    43,    44,    44,    44,
      55,    56,    89,    55,    56,   136,    53,    53,    53,   206,
     207,    89,   122,   155,   145,   155,    33,   176,   177,   155,
     155,    23,   155,   155,    55,    56,   136,   155,   159,   351,
      55,    56,    23,   164,    33,   145,   155,   168,    96,    67,
       6,   200,     4,     4,    23,    33,   104,    33,   179,    33,
     157,    33,    33,    33,   164,    33,    33,    33,   168,   190,
     191,    33,    33,    33,    33,    33,    33,   137,    33,   179,
     128,   202,   137,    33,    20,    81,    23,   236,   237,   210,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   223,   224,   225,    23,    24,    28,    28,    33,
     210,    45,    45,    31,    68,    13,    13,    35,    36,   131,
      23,    24,    28,   223,   224,   225,    44,    28,    31,    71,
      71,    71,    35,    36,    34,    53,    71,    55,    56,    34,
      34,    44,    34,    34,    34,    23,    64,    65,    47,    23,
      53,    23,    55,    56,    23,    23,    32,    75,    33,    32,
     281,    64,    65,    33,    41,   155,     7,     7,     7,   101,
       7,   155,    75,   155,   157,    68,    34,   157,   157,    34,
     157,   281,   157,    34,    34,    34,    34,   287,   309,   289,
       7,   291,     7,   293,     7,   295,     7,   297,    34,    34,
      34,   322,    34,     7,   325,   326,    34,    34,    34,    34,
      34,   155,    28,    13,    28,   336,   155,   155,    41,    41,
       7,   342,   322,     7,   345,   325,   326,    71,   349,   155,
     155,    28,   155,    28,   156,     7,   336,     7,   359,     7,
     361,     7,   342,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,    13,    34,    33,   358,    34,
     360,    34,     7,    34,    28,    41,    42,    34,   156,   156,
       7,    28,    13,    49,    50,    51,   114,    13,    34,    34,
      13,   402,    34,    34,    34,   156,    34,    34,    13,   156,
      66,   567,    -1,    69,   568,    -1,    72,   117,   447,   448,
      -1,   132,   402,    -1,   425,   405,   455,   407,    -1,   409,
      -1,   411,    -1,   434,   414,    -1,    -1,    93,    94,    -1,
      -1,    -1,    -1,   423,    -1,    -1,   475,   476,   477,   478,
     106,   107,   108,    -1,   483,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   452,    -1,    -1,    -1,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   512,    -1,   514,    -1,    -1,    -1,   518,    -1,    -1,
     521,    -1,    -1,   552,    -1,     3,    -1,   556,    -1,   558,
      -1,    -1,   512,   513,    -1,    -1,    -1,   517,   539,    -1,
      -1,   542,    -1,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    29,    30,    -1,    -1,    -1,    -1,    -1,   538,    37,
      -1,    39,    40,    41,    -1,    -1,    -1,    -1,    46,   570,
     571,    -1,    -1,   574,    52,   576,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      -1,   592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    -1,    90,    -1,    -1,    93,    94,    95,    -1,    97,
      98,    99,   100,   101,   102,   103,     3,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,    -1,   115,   116,    -1,
      -1,    -1,    -1,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    39,    40,    41,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    52,    -1,   155,    -1,   157,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    -1,    90,    -1,    -1,    93,    94,    95,    -1,
      97,    98,    99,   100,   101,   102,   103,    -1,   105,    -1,
      -1,    24,   109,   110,   111,   112,   113,    -1,   115,   116,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    69,    -1,   155,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    33,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,    -1,    -1,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    69,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    33,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    -1,    -1,    -1,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      69,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
      -1,    -1,    -1,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   225,   226,     0,     3,    21,    22,    24,    26,    27,
      29,    30,    37,    39,    40,    41,    46,    52,    57,    58,
      59,    60,    61,    62,    67,    87,    88,    90,    93,    94,
      95,    97,    98,    99,   100,   101,   102,   103,   105,   109,
     110,   111,   112,   113,   115,   116,   155,   157,   218,   220,
     222,   224,    23,   155,   170,   171,   172,    25,    30,    70,
     176,   177,   178,    33,    49,    50,    51,    66,    69,    72,
      81,    93,    94,   106,   107,   108,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   159,   162,   163,   164,   165,   180,   181,
     182,    21,    23,    31,    48,    76,    77,   155,   167,   168,
     169,   159,   165,   183,   184,   185,    23,    35,    36,    86,
     186,   187,   188,    41,    42,    43,    44,    53,   200,   201,
     202,   165,   214,   155,   203,   206,   155,   157,   204,   219,
      35,    36,   192,   193,    23,   194,   195,   196,    23,    86,
     197,   198,   199,   165,    89,    89,    33,    33,   165,    23,
     189,   190,   191,    23,   207,   208,   209,   155,   157,   205,
      67,    67,   157,   159,   165,   155,    41,    42,   163,   217,
      33,     6,    13,    20,   223,     6,     4,     4,   159,   165,
      23,   159,   165,   159,   165,   159,   165,    24,    73,    74,
      75,    84,   165,    33,    33,    33,    24,    73,    74,    75,
      82,    83,    84,   160,   161,   157,    33,    33,   163,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,   137,   134,   137,   138,   144,   138,   144,   137,    20,
      78,    79,   129,   130,   131,   179,     8,     9,    12,    14,
      15,    16,    17,    18,    19,    96,   104,   128,    79,   131,
     179,    23,   155,   173,   174,   175,   159,    23,   155,    23,
     155,    23,   155,    23,   155,    23,    23,    24,    31,    35,
      36,    44,    53,    55,    56,    64,    65,    75,   166,    24,
      31,    35,    36,    44,    53,    55,    56,    64,    65,   166,
     159,   165,    28,   159,   165,    45,    45,    52,   101,    20,
      41,   165,   159,   165,   159,   165,    28,    68,   163,   163,
     159,   165,    33,   165,   165,    13,   131,   163,   165,    13,
     220,   221,   224,   224,    28,    28,   159,   165,    71,    71,
      71,    71,    34,    34,    34,    34,    34,    34,   159,   165,
     159,   165,   159,   165,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     159,   165,    23,    47,   159,    23,   159,    23,   159,    23,
     159,    23,   159,   159,    32,    55,    56,    55,    56,    44,
      53,    44,    53,    33,   165,    32,    55,    56,    55,    56,
      44,    53,    44,    53,    33,   159,   165,   159,   165,   159,
     165,   215,   216,    41,   155,   159,   165,     7,     7,   159,
     165,    68,     7,   165,   101,     7,   165,   220,   155,   155,
     159,   165,   159,   165,   157,   157,   157,   157,   157,    34,
      34,    34,    34,    34,    34,     7,     7,     7,     7,    34,
      34,    34,    34,     7,    34,    34,    34,    34,    34,    28,
      28,   159,   165,    31,    48,    76,    77,   159,   159,   159,
     159,    28,    47,   159,   159,   165,   165,   155,   210,   155,
     212,   155,    13,    41,    41,   163,   163,     7,     7,   157,
     159,    71,   155,   163,   163,   163,   163,   163,   163,   155,
     155,    28,    28,   156,    31,    48,    76,    77,     7,     7,
     211,   213,    13,   159,   165,   159,   165,    34,    34,   159,
     165,   165,     7,    34,    34,    34,     7,    34,     7,    34,
      34,   156,   156,    28,    28,   159,   165,     7,     7,   165,
      13,    13,    34,    34,   114,   163,    13,   163,   163,   156,
     156,    34,    34,   210,   212,   165,   165,   165,    34,   165,
      34,    34,    13,   165
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   158,   159,   160,   160,   160,   160,   160,   160,   160,
     161,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     165,   166,   166,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   168,   168,   168,   168,   168,   169,   169,   170,   170,
     171,   171,   172,   172,   173,   173,   174,   174,   175,   175,
     176,   176,   176,   177,   177,   177,   178,   178,   179,   179,
     179,   180,   180,   180,   181,   181,   181,   182,   182,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   185,
     185,   186,   186,   186,   186,   186,   187,   187,   188,   188,
     189,   190,   191,   191,   192,   192,   193,   194,   195,   196,
     196,   197,   197,   197,   198,   198,   199,   199,   200,   200,
     200,   200,   200,   201,   201,   201,   202,   202,   203,   203,
     203,   203,   203,   203,   204,   204,   205,   205,   206,   207,
     208,   209,   209,   210,   211,   210,   212,   213,   212,   215,
     214,   216,   214,   217,   217,   217,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   219,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   220,   221,   220,   223,   222,   224,   224,   224,
     224,   226,   225
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     2,
       1,     1,     4,     4,     4,     4,     4,     1,     4,     4,
       1,     1,     4,     4,     4,     4,     6,     6,     6,     8,
       6,     8,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     2,     3,     1,     1,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     2,     3,     4,     5,     4,     3,     5,
       4,     4,     3,     4,     5,     4,     3,     5,     4,     4,
       3,     5,     7,     6,     7,     6,     1,     1,     3,     4,
       3,     4,     1,     1,     3,     4,     3,     4,     1,     1,
       2,     4,     4,     2,     4,     4,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     1,     1,     4,
       2,     2,     3,     7,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     2,     2,     3,     7,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     2,     1,     1,     1,     3,     2,     3,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     2,     1,     5,     2,     5,     1,     1,     1,     1,
       2,     3,     3,     2,     3,     3,     1,     1,     0,     3,
       4,     5,     5,     6,     1,     1,     1,     1,     1,     6,
       6,     1,     1,     1,     0,     4,     1,     0,     4,     0,
       4,     0,     4,     4,     1,     1,     2,     2,     3,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     3,     1,     4,     1,     1,     1,     0,     3,     1,
       1,     2,     1,     3,     2,     2,     5,     5,     6,     1,
       8,     2,     2,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     8,     8,     8,    10,     2,     3,     4,     2,
       1,     0,     1,     0,     4,     0,     3,     1,     3,     1,
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
  case 2: /* direct_integer: HASH Integer  */
#line 63 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2224 "src-generated/ugbc.tab.c"
    break;

  case 3: /* random_definition_simple: BYTE  */
#line 68 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2232 "src-generated/ugbc.tab.c"
    break;

  case 4: /* random_definition_simple: WORD  */
#line 71 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2240 "src-generated/ugbc.tab.c"
    break;

  case 5: /* random_definition_simple: DWORD  */
#line 74 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2248 "src-generated/ugbc.tab.c"
    break;

  case 6: /* random_definition_simple: POSITION  */
#line 77 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2256 "src-generated/ugbc.tab.c"
    break;

  case 7: /* random_definition_simple: COLOR  */
#line 80 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2264 "src-generated/ugbc.tab.c"
    break;

  case 8: /* random_definition_simple: WIDTH  */
#line 83 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2272 "src-generated/ugbc.tab.c"
    break;

  case 9: /* random_definition_simple: HEIGHT  */
#line 86 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2280 "src-generated/ugbc.tab.c"
    break;

  case 10: /* random_definition: random_definition_simple  */
#line 91 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2288 "src-generated/ugbc.tab.c"
    break;

  case 11: /* color_enumeration: BLACK  */
#line 96 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2297 "src-generated/ugbc.tab.c"
    break;

  case 12: /* color_enumeration: WHITE  */
#line 100 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2306 "src-generated/ugbc.tab.c"
    break;

  case 13: /* color_enumeration: RED  */
#line 104 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2315 "src-generated/ugbc.tab.c"
    break;

  case 14: /* color_enumeration: CYAN  */
#line 108 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2324 "src-generated/ugbc.tab.c"
    break;

  case 15: /* color_enumeration: VIOLET  */
#line 112 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2333 "src-generated/ugbc.tab.c"
    break;

  case 16: /* color_enumeration: GREEN  */
#line 116 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2342 "src-generated/ugbc.tab.c"
    break;

  case 17: /* color_enumeration: BLUE  */
#line 120 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2351 "src-generated/ugbc.tab.c"
    break;

  case 18: /* color_enumeration: YELLOW  */
#line 124 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2360 "src-generated/ugbc.tab.c"
    break;

  case 19: /* color_enumeration: ORANGE  */
#line 128 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2369 "src-generated/ugbc.tab.c"
    break;

  case 20: /* color_enumeration: BROWN  */
#line 132 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2378 "src-generated/ugbc.tab.c"
    break;

  case 21: /* color_enumeration: LIGHT RED  */
#line 136 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2387 "src-generated/ugbc.tab.c"
    break;

  case 22: /* color_enumeration: DARK GREY  */
#line 140 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2396 "src-generated/ugbc.tab.c"
    break;

  case 23: /* color_enumeration: GREY  */
#line 144 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2405 "src-generated/ugbc.tab.c"
    break;

  case 24: /* color_enumeration: LIGHT GREEN  */
#line 148 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2414 "src-generated/ugbc.tab.c"
    break;

  case 25: /* color_enumeration: LIGHT BLUE  */
#line 152 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2423 "src-generated/ugbc.tab.c"
    break;

  case 26: /* color_enumeration: LIGHT GREY  */
#line 156 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2432 "src-generated/ugbc.tab.c"
    break;

  case 27: /* color_enumeration: DARK BLUE  */
#line 160 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2441 "src-generated/ugbc.tab.c"
    break;

  case 28: /* color_enumeration: MAGENTA  */
#line 164 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2450 "src-generated/ugbc.tab.c"
    break;

  case 29: /* color_enumeration: PURPLE  */
#line 168 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2459 "src-generated/ugbc.tab.c"
    break;

  case 30: /* color_enumeration: LAVENDER  */
#line 172 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2468 "src-generated/ugbc.tab.c"
    break;

  case 31: /* color_enumeration: GOLD  */
#line 176 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2477 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: TURQUOISE  */
#line 180 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2486 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: TAN  */
#line 184 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2495 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: YELLOW GREEN  */
#line 188 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2504 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: OLIVE GREEN  */
#line 192 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2513 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: PINK  */
#line 196 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2522 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: PEACH  */
#line 200 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2531 "src-generated/ugbc.tab.c"
    break;

  case 38: /* expression: Identifier  */
#line 206 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2539 "src-generated/ugbc.tab.c"
    break;

  case 39: /* expression: Identifier DOLLAR  */
#line 209 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[-1].string);
      }
#line 2547 "src-generated/ugbc.tab.c"
    break;

  case 40: /* expression: Integer  */
#line 212 "src/ugbc.y"
              { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2556 "src-generated/ugbc.tab.c"
    break;

  case 41: /* expression: String  */
#line 216 "src/ugbc.y"
             { 
        outline1("; (expression string: \"%s\")", (yyvsp[0].string) );
        (yyval.string) = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", (yyval.string) );
        variable_store_string( _environment, (yyval.string), (yyvsp[0].string) );
        outline2("; variable stored: %s = %s", (yyval.string), (yyvsp[0].string) );
      }
#line 2568 "src-generated/ugbc.tab.c"
    break;

  case 42: /* expression: OP BYTE CP Integer  */
#line 223 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2577 "src-generated/ugbc.tab.c"
    break;

  case 43: /* expression: OP WORD CP Integer  */
#line 227 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2586 "src-generated/ugbc.tab.c"
    break;

  case 44: /* expression: OP DWORD CP Integer  */
#line 231 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2595 "src-generated/ugbc.tab.c"
    break;

  case 45: /* expression: OP POSITION CP Integer  */
#line 235 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2604 "src-generated/ugbc.tab.c"
    break;

  case 46: /* expression: OP COLOR CP Integer  */
#line 239 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2613 "src-generated/ugbc.tab.c"
    break;

  case 47: /* expression: color_enumeration  */
#line 243 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2621 "src-generated/ugbc.tab.c"
    break;

  case 48: /* expression: PEEK OP direct_integer CP  */
#line 246 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2629 "src-generated/ugbc.tab.c"
    break;

  case 49: /* expression: PEEK OP expressions CP  */
#line 249 "src/ugbc.y"
                             {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 2637 "src-generated/ugbc.tab.c"
    break;

  case 50: /* expression: XPEN  */
#line 252 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 2645 "src-generated/ugbc.tab.c"
    break;

  case 51: /* expression: YPEN  */
#line 255 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 2653 "src-generated/ugbc.tab.c"
    break;

  case 52: /* expression: COLLISION OP direct_integer CP  */
#line 258 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2661 "src-generated/ugbc.tab.c"
    break;

  case 53: /* expression: COLLISION OP expressions CP  */
#line 261 "src/ugbc.y"
                                  {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2669 "src-generated/ugbc.tab.c"
    break;

  case 54: /* expression: HIT OP direct_integer CP  */
#line 264 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2677 "src-generated/ugbc.tab.c"
    break;

  case 55: /* expression: HIT OP expressions CP  */
#line 267 "src/ugbc.y"
                            {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2685 "src-generated/ugbc.tab.c"
    break;

  case 56: /* expression: LEFT OP expression COMMA expression CP  */
#line 270 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2693 "src-generated/ugbc.tab.c"
    break;

  case 57: /* expression: RIGHT OP expression COMMA expression CP  */
#line 273 "src/ugbc.y"
                                              {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2701 "src-generated/ugbc.tab.c"
    break;

  case 58: /* expression: MID OP expression COMMA expression CP  */
#line 276 "src/ugbc.y"
                                            {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 2709 "src-generated/ugbc.tab.c"
    break;

  case 59: /* expression: MID OP expression COMMA expression COMMA expression CP  */
#line 279 "src/ugbc.y"
                                                             {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2717 "src-generated/ugbc.tab.c"
    break;

  case 60: /* expression: INSTR OP expression COMMA expression CP  */
#line 282 "src/ugbc.y"
                                              {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 2725 "src-generated/ugbc.tab.c"
    break;

  case 61: /* expression: INSTR OP expression COMMA expression COMMA expression CP  */
#line 285 "src/ugbc.y"
                                                               {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2733 "src-generated/ugbc.tab.c"
    break;

  case 62: /* expression: UPPER OP expression CP  */
#line 288 "src/ugbc.y"
                             {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 2741 "src-generated/ugbc.tab.c"
    break;

  case 63: /* expression: LOWER OP expression CP  */
#line 291 "src/ugbc.y"
                             {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 2749 "src-generated/ugbc.tab.c"
    break;

  case 64: /* expression: STR OP expression CP  */
#line 294 "src/ugbc.y"
                           {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 2757 "src-generated/ugbc.tab.c"
    break;

  case 65: /* expression: SPACE OP expression CP  */
#line 297 "src/ugbc.y"
                             {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 2765 "src-generated/ugbc.tab.c"
    break;

  case 66: /* expression: FLIP OP expression CP  */
#line 300 "src/ugbc.y"
                            {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 2773 "src-generated/ugbc.tab.c"
    break;

  case 67: /* expression: CHR OP expression CP  */
#line 303 "src/ugbc.y"
                           {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 2781 "src-generated/ugbc.tab.c"
    break;

  case 68: /* expression: ASC OP expression CP  */
#line 306 "src/ugbc.y"
                           {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 2789 "src-generated/ugbc.tab.c"
    break;

  case 69: /* expression: LEN OP expression CP  */
#line 309 "src/ugbc.y"
                           {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 2797 "src-generated/ugbc.tab.c"
    break;

  case 70: /* expression: STRING OP expression COMMA expression CP  */
#line 312 "src/ugbc.y"
                                               {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2805 "src-generated/ugbc.tab.c"
    break;

  case 71: /* expression: VAL OP expression CP  */
#line 315 "src/ugbc.y"
                           {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 2813 "src-generated/ugbc.tab.c"
    break;

  case 72: /* expression: RANDOM random_definition  */
#line 318 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 2821 "src-generated/ugbc.tab.c"
    break;

  case 73: /* expression: OP expressions CP  */
#line 321 "src/ugbc.y"
                        {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 2829 "src-generated/ugbc.tab.c"
    break;

  case 74: /* expression: TRUE  */
#line 324 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 2838 "src-generated/ugbc.tab.c"
    break;

  case 75: /* expression: FALSE  */
#line 328 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 2847 "src-generated/ugbc.tab.c"
    break;

  case 76: /* expression: NOT expression  */
#line 332 "src/ugbc.y"
                     {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2855 "src-generated/ugbc.tab.c"
    break;

  case 77: /* expressions_raw: expression  */
#line 338 "src/ugbc.y"
                 { (yyval.string) = (yyvsp[0].string); }
#line 2861 "src-generated/ugbc.tab.c"
    break;

  case 78: /* expressions_raw: expression PLUS expressions_raw  */
#line 339 "src/ugbc.y"
                                      {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2869 "src-generated/ugbc.tab.c"
    break;

  case 79: /* expressions_raw: expression MINUS expressions_raw  */
#line 342 "src/ugbc.y"
                                       {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2878 "src-generated/ugbc.tab.c"
    break;

  case 80: /* expressions_raw: expression MULTIPLICATION expressions_raw  */
#line 346 "src/ugbc.y"
                                                {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2887 "src-generated/ugbc.tab.c"
    break;

  case 81: /* expressions_raw: expression AND expressions_raw  */
#line 350 "src/ugbc.y"
                                     {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2896 "src-generated/ugbc.tab.c"
    break;

  case 82: /* expressions_raw: expression OR expressions_raw  */
#line 354 "src/ugbc.y"
                                    {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2905 "src-generated/ugbc.tab.c"
    break;

  case 83: /* expressions_raw: expression POW expressions_raw  */
#line 358 "src/ugbc.y"
                                     {
        (yyval.string) = variable_pow( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2914 "src-generated/ugbc.tab.c"
    break;

  case 84: /* expressions_raw: expression EQUAL expressions_raw  */
#line 362 "src/ugbc.y"
                                       {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2922 "src-generated/ugbc.tab.c"
    break;

  case 85: /* expressions_raw: expression DISEQUAL expressions_raw  */
#line 365 "src/ugbc.y"
                                          {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2930 "src-generated/ugbc.tab.c"
    break;

  case 86: /* expressions_raw: expression LT expressions_raw  */
#line 368 "src/ugbc.y"
                                    {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2938 "src-generated/ugbc.tab.c"
    break;

  case 87: /* expressions_raw: expression LTE expressions_raw  */
#line 371 "src/ugbc.y"
                                     {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2946 "src-generated/ugbc.tab.c"
    break;

  case 88: /* expressions_raw: expression GT expressions_raw  */
#line 374 "src/ugbc.y"
                                    {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2954 "src-generated/ugbc.tab.c"
    break;

  case 89: /* expressions_raw: expression GTE expressions_raw  */
#line 377 "src/ugbc.y"
                                     {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2962 "src-generated/ugbc.tab.c"
    break;

  case 90: /* expressions: expressions_raw  */
#line 383 "src/ugbc.y"
                    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2970 "src-generated/ugbc.tab.c"
    break;

  case 93: /* bank_definition_simple: AT direct_integer  */
#line 390 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2978 "src-generated/ugbc.tab.c"
    break;

  case 94: /* bank_definition_simple: Identifier AT direct_integer  */
#line 393 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2986 "src-generated/ugbc.tab.c"
    break;

  case 95: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 396 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2994 "src-generated/ugbc.tab.c"
    break;

  case 96: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 399 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 3002 "src-generated/ugbc.tab.c"
    break;

  case 97: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 402 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3010 "src-generated/ugbc.tab.c"
    break;

  case 98: /* bank_definition_simple: DATA AT direct_integer  */
#line 405 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 3018 "src-generated/ugbc.tab.c"
    break;

  case 99: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 409 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3026 "src-generated/ugbc.tab.c"
    break;

  case 100: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 412 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3034 "src-generated/ugbc.tab.c"
    break;

  case 101: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 415 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3042 "src-generated/ugbc.tab.c"
    break;

  case 102: /* bank_definition_simple: CODE AT direct_integer  */
#line 418 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3050 "src-generated/ugbc.tab.c"
    break;

  case 103: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 422 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3058 "src-generated/ugbc.tab.c"
    break;

  case 104: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 425 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3066 "src-generated/ugbc.tab.c"
    break;

  case 105: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 428 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3074 "src-generated/ugbc.tab.c"
    break;

  case 106: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 431 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3082 "src-generated/ugbc.tab.c"
    break;

  case 107: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 435 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3090 "src-generated/ugbc.tab.c"
    break;

  case 108: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 438 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3098 "src-generated/ugbc.tab.c"
    break;

  case 109: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 441 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3106 "src-generated/ugbc.tab.c"
    break;

  case 110: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 444 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3114 "src-generated/ugbc.tab.c"
    break;

  case 111: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 450 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3122 "src-generated/ugbc.tab.c"
    break;

  case 112: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 453 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3130 "src-generated/ugbc.tab.c"
    break;

  case 113: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 456 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3138 "src-generated/ugbc.tab.c"
    break;

  case 114: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 459 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3146 "src-generated/ugbc.tab.c"
    break;

  case 115: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 462 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3154 "src-generated/ugbc.tab.c"
    break;

  case 118: /* raster_definition_simple: Identifier AT direct_integer  */
#line 471 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3162 "src-generated/ugbc.tab.c"
    break;

  case 119: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 474 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3170 "src-generated/ugbc.tab.c"
    break;

  case 120: /* raster_definition_expression: Identifier AT expressions  */
#line 479 "src/ugbc.y"
                              {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3178 "src-generated/ugbc.tab.c"
    break;

  case 121: /* raster_definition_expression: AT expressions WITH Identifier  */
#line 482 "src/ugbc.y"
                                   {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3186 "src-generated/ugbc.tab.c"
    break;

  case 124: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 491 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3194 "src-generated/ugbc.tab.c"
    break;

  case 125: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 494 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3202 "src-generated/ugbc.tab.c"
    break;

  case 126: /* next_raster_definition_expression: Identifier AT expressions  */
#line 499 "src/ugbc.y"
                              {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3210 "src-generated/ugbc.tab.c"
    break;

  case 127: /* next_raster_definition_expression: AT expressions WITH Identifier  */
#line 502 "src/ugbc.y"
                                   {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3218 "src-generated/ugbc.tab.c"
    break;

  case 130: /* color_definition_simple: BORDER direct_integer  */
#line 511 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3226 "src-generated/ugbc.tab.c"
    break;

  case 131: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 514 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3234 "src-generated/ugbc.tab.c"
    break;

  case 132: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 517 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3242 "src-generated/ugbc.tab.c"
    break;

  case 133: /* color_definition_expression: BORDER expressions  */
#line 522 "src/ugbc.y"
                       {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3250 "src-generated/ugbc.tab.c"
    break;

  case 134: /* color_definition_expression: BACKGROUND expressions TO expressions  */
#line 525 "src/ugbc.y"
                                          {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3258 "src-generated/ugbc.tab.c"
    break;

  case 135: /* color_definition_expression: SPRITE expressions TO expressions  */
#line 528 "src/ugbc.y"
                                      {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3266 "src-generated/ugbc.tab.c"
    break;

  case 141: /* wait_definition_simple: direct_integer CYCLES  */
#line 542 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3274 "src-generated/ugbc.tab.c"
    break;

  case 142: /* wait_definition_simple: direct_integer TICKS  */
#line 545 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3282 "src-generated/ugbc.tab.c"
    break;

  case 143: /* wait_definition_simple: direct_integer milliseconds  */
#line 548 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3290 "src-generated/ugbc.tab.c"
    break;

  case 144: /* wait_definition_expression: expressions CYCLES  */
#line 553 "src/ugbc.y"
                         {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3298 "src-generated/ugbc.tab.c"
    break;

  case 145: /* wait_definition_expression: expressions TICKS  */
#line 556 "src/ugbc.y"
                        {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3306 "src-generated/ugbc.tab.c"
    break;

  case 146: /* wait_definition_expression: expressions milliseconds  */
#line 559 "src/ugbc.y"
                               {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3314 "src-generated/ugbc.tab.c"
    break;

  case 149: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 569 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3322 "src-generated/ugbc.tab.c"
    break;

  case 150: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 572 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3330 "src-generated/ugbc.tab.c"
    break;

  case 151: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 575 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3338 "src-generated/ugbc.tab.c"
    break;

  case 152: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 578 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3346 "src-generated/ugbc.tab.c"
    break;

  case 153: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 581 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3354 "src-generated/ugbc.tab.c"
    break;

  case 154: /* sprite_definition_simple: direct_integer ENABLE  */
#line 584 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3362 "src-generated/ugbc.tab.c"
    break;

  case 155: /* sprite_definition_simple: direct_integer DISABLE  */
#line 587 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3370 "src-generated/ugbc.tab.c"
    break;

  case 156: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 590 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3378 "src-generated/ugbc.tab.c"
    break;

  case 157: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 593 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3386 "src-generated/ugbc.tab.c"
    break;

  case 158: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 596 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3394 "src-generated/ugbc.tab.c"
    break;

  case 159: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 599 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3402 "src-generated/ugbc.tab.c"
    break;

  case 160: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 602 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3410 "src-generated/ugbc.tab.c"
    break;

  case 161: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 605 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3418 "src-generated/ugbc.tab.c"
    break;

  case 162: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 608 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3426 "src-generated/ugbc.tab.c"
    break;

  case 163: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 611 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3434 "src-generated/ugbc.tab.c"
    break;

  case 164: /* sprite_definition_expression: expressions DATA FROM expressions  */
#line 616 "src/ugbc.y"
                                      {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3442 "src-generated/ugbc.tab.c"
    break;

  case 165: /* sprite_definition_expression: expressions MULTICOLOR  */
#line 619 "src/ugbc.y"
                           {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3450 "src-generated/ugbc.tab.c"
    break;

  case 166: /* sprite_definition_expression: expressions MONOCOLOR  */
#line 622 "src/ugbc.y"
                          {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3458 "src-generated/ugbc.tab.c"
    break;

  case 167: /* sprite_definition_expression: expressions COLOR expressions  */
#line 625 "src/ugbc.y"
                                  {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3466 "src-generated/ugbc.tab.c"
    break;

  case 168: /* sprite_definition_expression: expressions position OP expressions COMMA expressions CP  */
#line 628 "src/ugbc.y"
                                                             {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3474 "src-generated/ugbc.tab.c"
    break;

  case 169: /* sprite_definition_expression: expressions ENABLE  */
#line 631 "src/ugbc.y"
                       {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3482 "src-generated/ugbc.tab.c"
    break;

  case 170: /* sprite_definition_expression: expressions DISABLE  */
#line 634 "src/ugbc.y"
                        {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3490 "src-generated/ugbc.tab.c"
    break;

  case 171: /* sprite_definition_expression: expressions EXPAND VERTICAL  */
#line 637 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3498 "src-generated/ugbc.tab.c"
    break;

  case 172: /* sprite_definition_expression: expressions COMPRESS VERTICAL  */
#line 640 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3506 "src-generated/ugbc.tab.c"
    break;

  case 173: /* sprite_definition_expression: expressions VERTICAL EXPAND  */
#line 643 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3514 "src-generated/ugbc.tab.c"
    break;

  case 174: /* sprite_definition_expression: expressions VERTICAL COMPRESS  */
#line 646 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3522 "src-generated/ugbc.tab.c"
    break;

  case 175: /* sprite_definition_expression: expressions EXPAND HORIZONTAL  */
#line 649 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3530 "src-generated/ugbc.tab.c"
    break;

  case 176: /* sprite_definition_expression: expressions COMPRESS HORIZONTAL  */
#line 652 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3538 "src-generated/ugbc.tab.c"
    break;

  case 177: /* sprite_definition_expression: expressions HORIZONTAL EXPAND  */
#line 655 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3546 "src-generated/ugbc.tab.c"
    break;

  case 178: /* sprite_definition_expression: expressions HORIZONTAL COMPRESS  */
#line 658 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3554 "src-generated/ugbc.tab.c"
    break;

  case 181: /* bitmap_definition_simple: AT direct_integer  */
#line 667 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3562 "src-generated/ugbc.tab.c"
    break;

  case 182: /* bitmap_definition_simple: ENABLE  */
#line 670 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3570 "src-generated/ugbc.tab.c"
    break;

  case 183: /* bitmap_definition_simple: DISABLE  */
#line 673 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 3578 "src-generated/ugbc.tab.c"
    break;

  case 184: /* bitmap_definition_simple: CLEAR  */
#line 676 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 3586 "src-generated/ugbc.tab.c"
    break;

  case 185: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 679 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 3594 "src-generated/ugbc.tab.c"
    break;

  case 186: /* bitmap_definition_expression: AT expressions  */
#line 685 "src/ugbc.y"
                   {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3602 "src-generated/ugbc.tab.c"
    break;

  case 187: /* bitmap_definition_expression: CLEAR WITH expressions  */
#line 688 "src/ugbc.y"
                           {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 3610 "src-generated/ugbc.tab.c"
    break;

  case 190: /* textmap_definition_simple: AT direct_integer  */
#line 698 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3618 "src-generated/ugbc.tab.c"
    break;

  case 191: /* textmap_definition_expression: AT expressions  */
#line 703 "src/ugbc.y"
                   {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3626 "src-generated/ugbc.tab.c"
    break;

  case 194: /* text_definition_simple: ENABLE  */
#line 712 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3634 "src-generated/ugbc.tab.c"
    break;

  case 195: /* text_definition_simple: DISABLE  */
#line 715 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 3642 "src-generated/ugbc.tab.c"
    break;

  case 197: /* tiles_definition_simple: AT direct_integer  */
#line 723 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 3650 "src-generated/ugbc.tab.c"
    break;

  case 198: /* tiles_definition_expression: AT expressions  */
#line 728 "src/ugbc.y"
                   {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 3658 "src-generated/ugbc.tab.c"
    break;

  case 201: /* colormap_definition_simple: AT direct_integer  */
#line 737 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 3666 "src-generated/ugbc.tab.c"
    break;

  case 202: /* colormap_definition_simple: CLEAR  */
#line 740 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 3674 "src-generated/ugbc.tab.c"
    break;

  case 203: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 743 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3682 "src-generated/ugbc.tab.c"
    break;

  case 204: /* colormap_definition_expression: AT expressions  */
#line 748 "src/ugbc.y"
                   {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3690 "src-generated/ugbc.tab.c"
    break;

  case 205: /* colormap_definition_expression: CLEAR WITH expressions ON expressions  */
#line 751 "src/ugbc.y"
                                          {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3698 "src-generated/ugbc.tab.c"
    break;

  case 208: /* screen_definition_simple: ON  */
#line 761 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 3706 "src-generated/ugbc.tab.c"
    break;

  case 209: /* screen_definition_simple: OFF  */
#line 764 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 3714 "src-generated/ugbc.tab.c"
    break;

  case 210: /* screen_definition_simple: ROWS direct_integer  */
#line 767 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 3722 "src-generated/ugbc.tab.c"
    break;

  case 211: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 770 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3730 "src-generated/ugbc.tab.c"
    break;

  case 212: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 773 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3738 "src-generated/ugbc.tab.c"
    break;

  case 213: /* screen_definition_expression: ROWS expressions  */
#line 778 "src/ugbc.y"
                     {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 3746 "src-generated/ugbc.tab.c"
    break;

  case 214: /* screen_definition_expression: VERTICAL SCROLL expressions  */
#line 781 "src/ugbc.y"
                                {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3754 "src-generated/ugbc.tab.c"
    break;

  case 215: /* screen_definition_expression: HORIZONTAL SCROLL expressions  */
#line 784 "src/ugbc.y"
                                  {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3762 "src-generated/ugbc.tab.c"
    break;

  case 219: /* var_definition_simple: Identifier ON Identifier  */
#line 793 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 3770 "src-generated/ugbc.tab.c"
    break;

  case 220: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 796 "src/ugbc.y"
                                    {
      variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 3778 "src-generated/ugbc.tab.c"
    break;

  case 221: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 799 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 3786 "src-generated/ugbc.tab.c"
    break;

  case 222: /* var_definition_simple: Identifier ON Identifier ASSIGN expressions  */
#line 802 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 3796 "src-generated/ugbc.tab.c"
    break;

  case 223: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expressions  */
#line 807 "src/ugbc.y"
                                                       {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 3806 "src-generated/ugbc.tab.c"
    break;

  case 224: /* goto_definition: Identifier  */
#line 814 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 3814 "src-generated/ugbc.tab.c"
    break;

  case 225: /* goto_definition: Integer  */
#line 817 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 3822 "src-generated/ugbc.tab.c"
    break;

  case 226: /* gosub_definition: Identifier  */
#line 823 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 3830 "src-generated/ugbc.tab.c"
    break;

  case 227: /* gosub_definition: Integer  */
#line 826 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 3838 "src-generated/ugbc.tab.c"
    break;

  case 229: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 835 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 3846 "src-generated/ugbc.tab.c"
    break;

  case 230: /* point_definition_expression: AT OP expressions COMMA expressions CP  */
#line 841 "src/ugbc.y"
                                             {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 3854 "src-generated/ugbc.tab.c"
    break;

  case 233: /* on_goto_definition: Identifier  */
#line 850 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 3863 "src-generated/ugbc.tab.c"
    break;

  case 234: /* $@1: %empty  */
#line 854 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 3871 "src-generated/ugbc.tab.c"
    break;

  case 236: /* on_gosub_definition: Identifier  */
#line 859 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 3880 "src-generated/ugbc.tab.c"
    break;

  case 237: /* $@2: %empty  */
#line 863 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 3888 "src-generated/ugbc.tab.c"
    break;

  case 239: /* $@3: %empty  */
#line 868 "src/ugbc.y"
                       {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 3896 "src-generated/ugbc.tab.c"
    break;

  case 241: /* $@4: %empty  */
#line 871 "src/ugbc.y"
                        {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 3904 "src-generated/ugbc.tab.c"
    break;

  case 243: /* every_definition: expression TICKS GOSUB Identifier  */
#line 876 "src/ugbc.y"
                                        {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 3912 "src-generated/ugbc.tab.c"
    break;

  case 244: /* every_definition: ON  */
#line 879 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 3920 "src-generated/ugbc.tab.c"
    break;

  case 245: /* every_definition: OFF  */
#line 882 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 3928 "src-generated/ugbc.tab.c"
    break;

  case 260: /* statement: RANDOMIZE  */
#line 901 "src/ugbc.y"
              {
      randomize( _environment );
  }
#line 3936 "src-generated/ugbc.tab.c"
    break;

  case 261: /* statement: IF expressions THEN  */
#line 904 "src/ugbc.y"
                        {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 3944 "src-generated/ugbc.tab.c"
    break;

  case 262: /* statement: ELSE  */
#line 907 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 3952 "src-generated/ugbc.tab.c"
    break;

  case 263: /* statement: ELSE IF expressions THEN  */
#line 910 "src/ugbc.y"
                             {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 3960 "src-generated/ugbc.tab.c"
    break;

  case 264: /* statement: ENDIF  */
#line 913 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 3968 "src-generated/ugbc.tab.c"
    break;

  case 265: /* statement: DO  */
#line 916 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 3976 "src-generated/ugbc.tab.c"
    break;

  case 266: /* statement: LOOP  */
#line 919 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 3984 "src-generated/ugbc.tab.c"
    break;

  case 267: /* $@5: %empty  */
#line 922 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 3992 "src-generated/ugbc.tab.c"
    break;

  case 268: /* statement: WHILE $@5 expressions  */
#line 924 "src/ugbc.y"
                {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 4000 "src-generated/ugbc.tab.c"
    break;

  case 269: /* statement: WEND  */
#line 927 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 4008 "src-generated/ugbc.tab.c"
    break;

  case 270: /* statement: REPEAT  */
#line 930 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 4016 "src-generated/ugbc.tab.c"
    break;

  case 271: /* statement: UNTIL expressions  */
#line 933 "src/ugbc.y"
                      {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 4024 "src-generated/ugbc.tab.c"
    break;

  case 272: /* statement: EXIT  */
#line 936 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 4032 "src-generated/ugbc.tab.c"
    break;

  case 273: /* statement: EXIT IF expressions  */
#line 939 "src/ugbc.y"
                        {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 4040 "src-generated/ugbc.tab.c"
    break;

  case 274: /* statement: EXIT Integer  */
#line 942 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4048 "src-generated/ugbc.tab.c"
    break;

  case 275: /* statement: EXIT direct_integer  */
#line 945 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4056 "src-generated/ugbc.tab.c"
    break;

  case 276: /* statement: EXIT IF expressions COMMA Integer  */
#line 948 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4064 "src-generated/ugbc.tab.c"
    break;

  case 277: /* statement: EXIT IF expressions COMMA direct_integer  */
#line 951 "src/ugbc.y"
                                             {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4072 "src-generated/ugbc.tab.c"
    break;

  case 278: /* statement: FOR Identifier ASSIGN expressions TO expressions  */
#line 954 "src/ugbc.y"
                                                     {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4080 "src-generated/ugbc.tab.c"
    break;

  case 279: /* statement: NEXT  */
#line 957 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 4088 "src-generated/ugbc.tab.c"
    break;

  case 280: /* statement: FOR Identifier ASSIGN expressions TO expressions STEP expressions  */
#line 960 "src/ugbc.y"
                                                                      {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4096 "src-generated/ugbc.tab.c"
    break;

  case 281: /* statement: BEG GAMELOOP  */
#line 963 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 4104 "src-generated/ugbc.tab.c"
    break;

  case 282: /* statement: END GAMELOOP  */
#line 966 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 4112 "src-generated/ugbc.tab.c"
    break;

  case 283: /* statement: GRAPHIC  */
#line 969 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 4120 "src-generated/ugbc.tab.c"
    break;

  case 284: /* statement: HALT  */
#line 972 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 4128 "src-generated/ugbc.tab.c"
    break;

  case 289: /* statement: RETURN  */
#line 979 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 4136 "src-generated/ugbc.tab.c"
    break;

  case 290: /* statement: POP  */
#line 982 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 4144 "src-generated/ugbc.tab.c"
    break;

  case 291: /* statement: DONE  */
#line 985 "src/ugbc.y"
          {
      return 0;
  }
#line 4152 "src-generated/ugbc.tab.c"
    break;

  case 292: /* statement: LEFT OP expression COMMA expression CP ASSIGN expressions  */
#line 988 "src/ugbc.y"
                                                              {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4160 "src-generated/ugbc.tab.c"
    break;

  case 293: /* statement: RIGHT OP expression COMMA expression CP ASSIGN expressions  */
#line 991 "src/ugbc.y"
                                                               {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4168 "src-generated/ugbc.tab.c"
    break;

  case 294: /* statement: MID OP expression COMMA expression CP ASSIGN expressions  */
#line 994 "src/ugbc.y"
                                                             {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 4176 "src-generated/ugbc.tab.c"
    break;

  case 295: /* statement: MID OP expression COMMA expression COMMA expression CP ASSIGN expressions  */
#line 997 "src/ugbc.y"
                                                                              {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4184 "src-generated/ugbc.tab.c"
    break;

  case 296: /* statement: Identifier COLON  */
#line 1000 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 4192 "src-generated/ugbc.tab.c"
    break;

  case 297: /* statement: Identifier ASSIGN expressions  */
#line 1003 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expressions = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expressions->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 4206 "src-generated/ugbc.tab.c"
    break;

  case 298: /* statement: Identifier DOLLAR ASSIGN expressions  */
#line 1012 "src/ugbc.y"
                                         {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expressions = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 4220 "src-generated/ugbc.tab.c"
    break;

  case 299: /* statement: DEBUG expressions  */
#line 1021 "src/ugbc.y"
                      {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 4228 "src-generated/ugbc.tab.c"
    break;

  case 302: /* statements_no_linenumbers: statement  */
#line 1029 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 4234 "src-generated/ugbc.tab.c"
    break;

  case 303: /* $@6: %empty  */
#line 1030 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 4240 "src-generated/ugbc.tab.c"
    break;

  case 305: /* $@7: %empty  */
#line 1034 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 4248 "src-generated/ugbc.tab.c"
    break;

  case 306: /* statements_with_linenumbers: Integer $@7 statements_no_linenumbers  */
#line 1036 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 4256 "src-generated/ugbc.tab.c"
    break;

  case 311: /* $@8: %empty  */
#line 1048 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 4262 "src-generated/ugbc.tab.c"
    break;


#line 4266 "src-generated/ugbc.tab.c"

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

#line 1050 "src/ugbc.y"


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
    exit(EXIT_FAILURE);
}

int main( int _argc, char *_argv[] ) {
    extern FILE *yyin;
    int flags, opt;
    int nsecs, tfnd;
    Environment * _environment = malloc(sizeof(Environment));

    while ((opt = getopt(_argc, _argv, "e:c:")) != -1) {
        switch (opt) {
                case 'c':
                    _environment->configurationFileName = strdup(optarg);
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

