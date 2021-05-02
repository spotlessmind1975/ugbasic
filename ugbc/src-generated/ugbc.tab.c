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
  YYSYMBOL_MILLISECOND = 127,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 128,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 129,                    /* TICKS  */
  YYSYMBOL_BLACK = 130,                    /* BLACK  */
  YYSYMBOL_WHITE = 131,                    /* WHITE  */
  YYSYMBOL_RED = 132,                      /* RED  */
  YYSYMBOL_CYAN = 133,                     /* CYAN  */
  YYSYMBOL_VIOLET = 134,                   /* VIOLET  */
  YYSYMBOL_GREEN = 135,                    /* GREEN  */
  YYSYMBOL_BLUE = 136,                     /* BLUE  */
  YYSYMBOL_YELLOW = 137,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 138,                   /* ORANGE  */
  YYSYMBOL_BROWN = 139,                    /* BROWN  */
  YYSYMBOL_LIGHT = 140,                    /* LIGHT  */
  YYSYMBOL_DARK = 141,                     /* DARK  */
  YYSYMBOL_GREY = 142,                     /* GREY  */
  YYSYMBOL_GRAY = 143,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 144,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 145,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 146,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 147,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 148,                /* TURQUOISE  */
  YYSYMBOL_TAN = 149,                      /* TAN  */
  YYSYMBOL_PINK = 150,                     /* PINK  */
  YYSYMBOL_PEACH = 151,                    /* PEACH  */
  YYSYMBOL_OLIVE = 152,                    /* OLIVE  */
  YYSYMBOL_Identifier = 153,               /* Identifier  */
  YYSYMBOL_String = 154,                   /* String  */
  YYSYMBOL_Integer = 155,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 156,                 /* $accept  */
  YYSYMBOL_direct_integer = 157,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 158, /* random_definition_simple  */
  YYSYMBOL_random_definition = 159,        /* random_definition  */
  YYSYMBOL_color_enumeration = 160,        /* color_enumeration  */
  YYSYMBOL_expression = 161,               /* expression  */
  YYSYMBOL_expressions_raw = 162,          /* expressions_raw  */
  YYSYMBOL_expressions = 163,              /* expressions  */
  YYSYMBOL_position = 164,                 /* position  */
  YYSYMBOL_bank_definition_simple = 165,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 166, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 167,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 168, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 169, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 170,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 171, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 172, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 173,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 174,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 175, /* color_definition_expression  */
  YYSYMBOL_color_definition = 176,         /* color_definition  */
  YYSYMBOL_milliseconds = 177,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 178,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 179, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 180,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 181, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 182, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 183,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 184, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 185, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 186,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 187, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 188, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 189,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 190,   /* text_definition_simple  */
  YYSYMBOL_text_definition = 191,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 192,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 193, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 194,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 195, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 196, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 197,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 198, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 199, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 200,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 201,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 202,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 203,         /* gosub_definition  */
  YYSYMBOL_var_definition = 204,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 205,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 206, /* point_definition_expression  */
  YYSYMBOL_point_definition = 207,         /* point_definition  */
  YYSYMBOL_on_goto_definition = 208,       /* on_goto_definition  */
  YYSYMBOL_209_1 = 209,                    /* $@1  */
  YYSYMBOL_on_gosub_definition = 210,      /* on_gosub_definition  */
  YYSYMBOL_211_2 = 211,                    /* $@2  */
  YYSYMBOL_on_definition = 212,            /* on_definition  */
  YYSYMBOL_213_3 = 213,                    /* $@3  */
  YYSYMBOL_214_4 = 214,                    /* $@4  */
  YYSYMBOL_every_definition = 215,         /* every_definition  */
  YYSYMBOL_statement = 216,                /* statement  */
  YYSYMBOL_217_5 = 217,                    /* $@5  */
  YYSYMBOL_statements_no_linenumbers = 218, /* statements_no_linenumbers  */
  YYSYMBOL_219_6 = 219,                    /* $@6  */
  YYSYMBOL_statements_with_linenumbers = 220, /* statements_with_linenumbers  */
  YYSYMBOL_221_7 = 221,                    /* $@7  */
  YYSYMBOL_statements_complex = 222,       /* statements_complex  */
  YYSYMBOL_program = 223,                  /* program  */
  YYSYMBOL_224_8 = 224                     /* $@8  */
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
#define YYLAST   1075

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  156
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  310
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  588

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   410


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
     155
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
     312,   315,   318,   321,   325,   329,   335,   336,   339,   343,
     347,   351,   355,   358,   361,   364,   367,   370,   376,   380,
     380,   383,   386,   389,   392,   395,   398,   402,   405,   408,
     411,   415,   418,   421,   424,   428,   431,   434,   437,   443,
     446,   449,   452,   455,   460,   461,   464,   467,   472,   475,
     480,   481,   484,   487,   492,   495,   500,   501,   504,   507,
     510,   515,   518,   521,   526,   527,   530,   531,   532,   535,
     538,   541,   546,   549,   552,   558,   559,   562,   565,   568,
     571,   574,   577,   580,   583,   586,   589,   592,   595,   598,
     601,   604,   609,   612,   615,   618,   621,   624,   627,   630,
     633,   636,   639,   642,   645,   648,   651,   656,   657,   660,
     663,   666,   669,   672,   678,   681,   687,   688,   691,   696,
     701,   702,   705,   708,   713,   716,   721,   726,   727,   730,
     733,   736,   741,   744,   750,   751,   754,   757,   760,   763,
     766,   771,   774,   777,   782,   783,   785,   786,   789,   792,
     795,   800,   807,   810,   816,   819,   825,   828,   834,   839,
     840,   843,   847,   847,   852,   856,   856,   861,   861,   864,
     864,   869,   872,   875,   880,   881,   882,   883,   884,   885,
     886,   887,   888,   889,   890,   891,   892,   893,   894,   897,
     900,   903,   906,   909,   912,   915,   915,   920,   923,   926,
     929,   932,   935,   938,   941,   944,   947,   950,   953,   956,
     959,   962,   965,   968,   969,   970,   971,   972,   975,   978,
     981,   984,   987,   990,   993,   996,  1005,  1014,  1017,  1018,
    1022,  1023,  1023,  1027,  1027,  1034,  1035,  1036,  1037,  1041,
    1041
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
  "VAL", "STRING", "SPACE", "FLIP", "CHR", "ASC", "MILLISECOND",
  "MILLISECONDS", "TICKS", "BLACK", "WHITE", "RED", "CYAN", "VIOLET",
  "GREEN", "BLUE", "YELLOW", "ORANGE", "BROWN", "LIGHT", "DARK", "GREY",
  "GRAY", "MAGENTA", "PURPLE", "LAVENDER", "GOLD", "TURQUOISE", "TAN",
  "PINK", "PEACH", "OLIVE", "Identifier", "String", "Integer", "$accept",
  "direct_integer", "random_definition_simple", "random_definition",
  "color_enumeration", "expression", "expressions_raw", "expressions",
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
  "text_definition_simple", "text_definition", "tiles_definition_simple",
  "tiles_definition_expression", "tiles_definition",
  "colormap_definition_simple", "colormap_definition_expression",
  "colormap_definition", "screen_definition_simple",
  "screen_definition_expression", "screen_definition",
  "var_definition_simple", "goto_definition", "gosub_definition",
  "var_definition", "point_definition_simple",
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
     405,   406,   407,   408,   409,   410
};
#endif

#define YYPACT_NINF (-203)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-236)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -203,    25,   506,  -203,  -203,   -15,  -203,    46,   810,    22,
     -21,   810,  -203,     9,    70,   920,   -93,  -127,  -203,  -203,
    -203,    92,    40,   -16,   920,     8,    26,  -203,    60,    89,
     920,  -203,  -203,   130,   136,    13,  -203,  -203,    63,  -203,
     -64,  -203,   920,    23,   329,   141,    88,  -203,   169,   176,
     177,  -203,   810,   159,  -203,  -203,  -203,   810,   810,   810,
    -203,  -203,  -203,   700,  -203,  -203,   150,   151,   152,    -1,
      31,   154,   156,   920,  -203,  -203,   158,   160,   161,   162,
     183,   184,   185,   187,   188,   190,   192,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,    57,  -203,  -203,   -36,    19,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,    75,   204,
    -203,  -203,   -63,  -203,    21,  -203,   -25,  -203,  -203,  -203,
     -14,   147,   -12,    -9,    -5,    -3,   206,  -203,  -203,  -203,
      54,   191,  -203,  -203,  -203,   810,  -203,  -203,   202,  -203,
    -203,  -203,  -203,  -203,   810,   186,   193,  -203,  -203,  -203,
     -40,  -203,    38,  -203,  -203,  -203,  -203,  -203,   920,  -203,
    -203,  -203,  -203,   810,  -203,  -203,  -203,   810,   208,  -203,
    -203,  -203,   171,  -203,  -203,   920,   920,  -203,   810,  -203,
    -203,  -203,   207,  -203,  -203,  -203,  -203,  -203,  -203,   920,
     920,  -203,  -203,  -203,   224,  -203,  -203,   112,  -203,   920,
    -203,   920,   229,   610,  -203,   506,   506,   215,   217,   810,
    -203,  -203,   178,   179,   180,   181,   214,   219,   220,   223,
     225,   226,   810,   810,   810,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,   920,   920,  -203,   920,   920,
     920,   920,   920,   920,   920,   920,   920,   920,   920,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,   920,   920,   920,   920,   920,   920,
     920,   920,   920,   920,   920,  -203,  -203,  -203,   810,   235,
    -203,  -203,  -203,   216,   147,   238,   147,   239,   147,   241,
     147,   242,   147,  -203,   147,   247,  -203,  -203,   102,   107,
      82,    90,  -203,  -203,  -203,   248,   920,   250,  -203,  -203,
     109,   114,    96,    98,  -203,  -203,   251,  -203,  -203,   810,
    -203,  -203,   810,   810,  -203,  -203,   244,   127,  -203,  -203,
    -203,  -203,  -203,   810,  -203,   276,   279,  -203,  -203,   810,
     221,   280,   920,   189,   284,  -203,   920,  -203,   610,  -203,
    -203,   139,   140,  -203,  -203,   147,   920,   147,   920,   142,
     144,   146,   148,   155,  -203,   271,   272,   273,   275,   281,
     282,   306,   307,   310,   311,   285,   286,   287,   289,   317,
     291,   292,   293,   296,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,   308,   309,   810,    11,  -203,
     147,  -203,   147,  -203,   147,  -203,   147,    58,  -203,   147,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,   147,  -203,
     920,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,   920,
    -203,  -203,  -203,  -203,  -203,  -203,   195,   197,   198,   321,
     297,   298,   920,   920,   333,   334,  -203,   -75,   283,   199,
     920,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
     920,   920,   920,   920,  -203,  -203,  -203,  -203,   920,  -203,
    -203,  -203,  -203,   200,   203,  -203,  -203,  -203,  -203,  -203,
    -203,   314,  -203,   316,  -203,   201,    44,  -203,   339,  -203,
     350,   351,  -203,   352,  -203,   347,   810,   147,   920,   327,
     330,   147,   920,  -203,  -203,   920,  -203,    15,   332,   335,
      17,    50,   338,  -203,  -203,   209,   222,  -203,   340,  -203,
     345,  -203,   147,   920,   367,   368,   920,  -203,  -203,  -203,
    -203,   364,   369,   349,   353,   267,   920,   371,  -203,  -203,
     920,  -203,   920,  -203,  -203,  -203,  -203,   231,   234,   355,
     356,   195,   197,  -203,   920,   920,  -203,  -203,   920,   357,
     920,   358,   359,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,   381,  -203,  -203,  -203,   920,  -203
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     309,     0,   299,     1,   298,     0,   289,     0,     0,   277,
       0,     0,   282,     0,     0,     0,   216,     0,   264,   268,
     265,     0,     0,     0,     0,     0,     0,   262,     0,     0,
       0,   258,   281,     0,     0,     0,   287,   288,   260,   263,
     270,   267,     0,     0,     0,     0,     0,   303,   300,   305,
     307,   310,     0,     0,   120,   121,   245,     0,     0,     0,
     134,   135,   247,     0,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,    73,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,    23,
      28,    29,    30,    31,    32,    33,    36,    37,     0,    38,
      41,    40,     0,    47,    76,    88,     0,   145,   146,   248,
       0,     0,     0,     0,     0,     0,     0,   114,   115,   244,
       0,     0,   177,   178,   249,     0,   180,   181,   182,   186,
     187,   250,   206,   207,     0,     0,     0,   214,   215,   255,
       0,   283,     0,   226,   257,   222,   223,   284,     0,   192,
     193,   194,   252,     0,   197,   198,   253,     0,   200,   204,
     205,   254,     0,   279,   280,     0,     0,   297,     0,   190,
     191,   251,     0,   229,   230,   256,   224,   225,   285,     0,
       0,   272,   273,   269,     0,   242,   243,     0,   286,     0,
     294,     0,     0,   299,   301,   299,   299,     0,     0,     0,
     128,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     3,     4,     6,     8,
       9,     5,    10,    71,     2,     0,     0,    75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      21,    24,    25,    26,    27,    22,    35,    39,   136,   139,
     137,   138,   140,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,   143,   144,     0,     0,
     126,   127,   246,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,     0,     0,   152,   153,     0,     0,
       0,     0,   149,   148,    89,     0,     0,     0,   167,   168,
       0,     0,     0,     0,   164,   163,     0,   179,   184,     0,
     208,   211,     0,     0,   237,   239,     0,     0,   266,   195,
     196,   199,   202,     0,   259,     0,     0,   188,   189,     0,
       0,   271,     0,     0,     0,   295,     0,   304,   299,   306,
     308,     0,     0,   116,   118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    82,    84,    85,    86,
      87,    83,    79,    80,    81,     0,     0,     0,     0,    96,
       0,   108,     0,   100,     0,   104,     0,    92,   150,     0,
     157,   156,   161,   160,   155,   159,   154,   158,     0,   165,
       0,   172,   171,   176,   175,   170,   174,   169,   173,     0,
     183,   185,   209,   212,   210,   213,     0,     0,     0,   217,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
       0,   296,   302,   117,   119,   130,   133,   129,   132,    46,
      42,    43,    45,    44,    48,    49,    52,    53,    54,    55,
       0,     0,     0,     0,    62,    63,    64,    70,     0,    65,
      66,    67,    68,     0,     0,   122,   124,    93,   106,    98,
     101,    95,   107,    99,   103,     0,     0,   147,     0,   162,
       0,   231,   238,   234,   240,   218,     0,     0,     0,     0,
       0,     0,     0,   274,   275,     0,   241,     0,     0,     0,
       0,     0,     0,   123,   125,     0,     0,   109,    94,   105,
      97,   102,     0,     0,     0,     0,     0,   219,   220,   201,
     203,     0,     0,     0,     0,   276,     0,     0,    56,    57,
       0,    58,     0,    60,    69,   111,   113,     0,     0,     0,
       0,     0,     0,   221,     0,     0,   227,   228,     0,     0,
       0,     0,     0,   110,   112,   151,   166,   233,   236,   290,
     291,   278,     0,   292,    59,    61,     0,   293
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -203,    10,  -203,  -203,  -203,   -39,     4,   -11,   265,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,   290,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -164,  -203,  -163,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -202,  -203,  -203,  -203,   -34,  -203,  -203
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   112,   232,   233,   113,   114,   115,   116,   305,   127,
     128,   129,    54,    55,    56,   280,   281,   282,    60,    61,
      62,   263,   117,   118,   119,   132,   133,   134,   139,   140,
     141,   179,   180,   181,   161,   162,   164,   165,   166,   169,
     170,   171,   147,   148,   149,   153,   157,   188,   154,   183,
     184,   185,   502,   534,   504,   535,   151,   436,   437,   198,
      48,   158,    49,   348,    50,   203,    51,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     131,   347,   121,   190,   150,   197,    70,   167,    52,   278,
     122,   284,   324,   172,   286,   258,   259,    70,   288,   177,
     290,   130,   546,   225,   550,     3,   155,   123,   156,   264,
     265,   193,   135,   266,   237,   267,   268,   269,   270,   271,
     272,   208,   487,   120,   136,   137,   211,   213,   215,   547,
     192,   551,   221,   258,   275,   124,   125,   552,   326,   488,
     152,   325,   207,   163,   260,   261,   262,   210,   212,   214,
     168,    57,   226,   227,   228,   528,    58,   293,   294,   327,
     513,   229,   230,   231,   553,   295,   495,   489,   490,   296,
     297,   191,   529,   175,   200,   138,   250,   173,   298,   251,
     252,   201,   260,   261,   276,   496,   253,   299,   202,   300,
     301,   142,   143,   144,   145,   174,    59,   273,   302,   303,
     530,   531,   176,   146,   318,   274,   414,   159,   160,   304,
     189,   283,   126,   321,   416,   415,   335,   336,    53,   279,
     425,   285,   427,   417,   287,   317,   452,   328,   289,   426,
     291,   428,   330,   178,   320,   254,   332,   410,   411,   182,
     344,   255,   412,   413,   421,   422,   186,   338,   187,   423,
     424,   349,   350,   329,   199,   204,   194,   331,   340,   341,
     205,   206,   209,   222,   223,   224,   234,   235,   337,   236,
     345,   238,   249,   239,   240,   241,   371,   372,   354,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     256,   366,   368,   370,   293,   306,   242,   243,   244,   353,
     245,   246,   307,   247,   257,   248,   308,   309,    70,   292,
     319,   322,   365,   367,   369,   310,   333,   342,   323,   334,
     339,   343,   346,   351,   311,   352,   312,   313,   359,   355,
     356,   357,   358,   360,   361,   314,   315,   362,   397,   363,
     364,   400,   402,   398,   404,   406,   304,   396,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   409,
     439,   418,   420,   442,   429,   438,   443,   447,   395,   446,
     449,   450,   453,   454,   399,   419,   401,   459,   403,   460,
     405,   461,   407,   462,   408,   464,   465,   466,   431,   467,
     463,   433,   435,   470,   471,   468,   469,   472,   473,   474,
     475,   476,   441,   477,   478,   479,   480,   481,   445,   430,
     482,   448,   432,   434,   506,   451,   483,   484,   507,   508,
     511,   512,   525,   440,   526,   456,   532,   458,   501,   444,
     503,   505,   516,   523,   515,   527,   524,   533,  -232,  -235,
     536,   541,    63,   555,   542,   455,   548,   457,   557,   549,
     195,   196,   554,   558,   561,   562,   556,   564,    64,    65,
      66,   568,   565,   566,   570,   573,   486,   567,   574,   575,
     576,   582,   584,   585,   586,    67,   316,   577,    68,   578,
       0,    69,     0,   509,   510,     0,   277,   485,     0,   499,
     491,   517,   492,     0,   493,     0,   494,     0,   500,   497,
       0,     0,    71,    72,     0,     0,     0,     0,   498,     0,
       0,   518,   519,   520,   521,    73,    74,    75,     0,   522,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,   514,     0,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   538,     0,   540,     0,     0,
       0,   544,     0,     0,   545,     0,     0,   569,     0,     4,
       0,   571,     0,   572,     0,     0,   537,   539,     0,     0,
       0,   543,   560,     0,     0,   563,     0,     5,     6,     0,
       7,     0,     8,     9,     0,    10,    11,     0,     0,     0,
       0,     0,   559,    12,     0,    13,    14,    15,     0,     0,
       0,     0,    16,   579,   580,     0,     0,   581,    17,   583,
       0,     0,     0,    18,    19,    20,    21,    22,    23,     0,
       0,     0,     0,    24,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,     0,    27,     0,     0,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
       0,    38,     0,     4,     0,    39,    40,    41,    42,    43,
       0,    44,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     0,     7,     0,     8,     9,     0,    10,
      11,     0,     0,     0,     0,     0,     0,    12,     0,    13,
      14,    15,     0,     0,     0,     0,    16,     0,     0,    46,
       0,    47,    17,     0,     0,     0,     0,    18,    19,    20,
      21,    22,    23,     0,     0,     0,     0,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,     0,
      27,     0,     0,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,     0,    38,     0,     0,     0,    39,
      40,    41,    42,    43,   216,    44,    45,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      65,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,    67,     0,     0,    68,
       0,     0,    69,   217,   218,   219,     0,     0,     0,     0,
       0,     0,     0,     0,   220,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,    74,    75,     0,
       0,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    63,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     0,     0,     0,    64,
      65,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,     0,     0,    68,
       0,     0,    69,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,    74,    75,     0,
       0,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    63,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     0,     0,     0,    64,
      65,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,     0,     0,    68,
       0,     0,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,    74,    75,     0,
       0,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111
};

static const yytype_int16 yycheck[] =
{
      11,   203,    23,    67,    15,    44,    81,    23,    23,    23,
      31,    23,    52,    24,    23,    78,    79,    81,    23,    30,
      23,    11,     7,    24,     7,     0,   153,    48,   155,     8,
       9,    42,    23,    12,    73,    14,    15,    16,    17,    18,
      19,    52,    31,    21,    35,    36,    57,    58,    59,    34,
      40,    34,    63,    78,    79,    76,    77,     7,    20,    48,
     153,   101,    52,    23,   127,   128,   129,    57,    58,    59,
      86,    25,    73,    74,    75,    31,    30,    23,    24,    41,
     155,    82,    83,    84,    34,    31,    28,    76,    77,    35,
      36,   155,    48,    33,     6,    86,   132,    89,    44,   135,
     136,    13,   127,   128,   129,    47,   142,    53,    20,    55,
      56,    41,    42,    43,    44,    89,    70,    96,    64,    65,
      76,    77,    33,    53,   135,   104,    44,    35,    36,    75,
      67,   121,   153,   144,    44,    53,   175,   176,   153,   153,
      44,   153,    44,    53,   153,   135,   348,   158,   153,    53,
     153,    53,   163,    23,   144,   136,   167,    55,    56,    23,
     199,   142,    55,    56,    55,    56,   153,   178,   155,    55,
      56,   205,   206,   163,    33,     6,   153,   167,   189,   190,
       4,     4,    23,    33,    33,    33,   155,    33,   178,    33,
     201,    33,   135,    33,    33,    33,   235,   236,   209,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     135,   222,   223,   224,    23,    24,    33,    33,    33,   209,
      33,    33,    31,    33,    20,    33,    35,    36,    81,    23,
      28,    45,   222,   223,   224,    44,    28,    13,    45,    68,
      33,   129,    13,    28,    53,    28,    55,    56,    34,    71,
      71,    71,    71,    34,    34,    64,    65,    34,    23,    34,
      34,    23,    23,    47,    23,    23,    75,   278,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,    32,
     153,    33,    32,     7,    33,    41,     7,     7,   278,    68,
     101,     7,   153,   153,   284,   306,   286,   155,   288,   155,
     290,   155,   292,   155,   294,    34,    34,    34,   319,    34,
     155,   322,   323,     7,     7,    34,    34,     7,     7,    34,
      34,    34,   333,    34,     7,    34,    34,    34,   339,   319,
      34,   342,   322,   323,    13,   346,    28,    28,    41,    41,
       7,     7,    28,   333,    28,   356,     7,   358,   153,   339,
     153,   153,   153,   153,    71,   154,   153,     7,     7,     7,
      13,    34,    33,   154,    34,   355,    34,   357,    28,    34,
      41,    42,    34,    28,     7,     7,   154,    13,    49,    50,
      51,   114,    13,    34,    13,   154,   397,    34,   154,    34,
      34,    34,    34,    34,    13,    66,   131,   561,    69,   562,
      -1,    72,    -1,   442,   443,    -1,   116,   397,    -1,   420,
     400,   450,   402,    -1,   404,    -1,   406,    -1,   429,   409,
      -1,    -1,    93,    94,    -1,    -1,    -1,    -1,   418,    -1,
      -1,   470,   471,   472,   473,   106,   107,   108,    -1,   478,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,   447,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   506,    -1,   508,    -1,    -1,
      -1,   512,    -1,    -1,   515,    -1,    -1,   546,    -1,     3,
      -1,   550,    -1,   552,    -1,    -1,   506,   507,    -1,    -1,
      -1,   511,   533,    -1,    -1,   536,    -1,    21,    22,    -1,
      24,    -1,    26,    27,    -1,    29,    30,    -1,    -1,    -1,
      -1,    -1,   532,    37,    -1,    39,    40,    41,    -1,    -1,
      -1,    -1,    46,   564,   565,    -1,    -1,   568,    52,   570,
      -1,    -1,    -1,    57,    58,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    -1,   586,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    -1,    90,    -1,    -1,    93,
      94,    95,    -1,    97,    98,    99,   100,   101,   102,   103,
      -1,   105,    -1,     3,    -1,   109,   110,   111,   112,   113,
      -1,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    -1,    24,    -1,    26,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    39,
      40,    41,    -1,    -1,    -1,    -1,    46,    -1,    -1,   153,
      -1,   155,    52,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,
      90,    -1,    -1,    93,    94,    95,    -1,    97,    98,    99,
     100,   101,   102,   103,    -1,   105,    -1,    -1,    -1,   109,
     110,   111,   112,   113,    24,   115,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,    66,    -1,    -1,    69,
      -1,    -1,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    33,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    69,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    33,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    69,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    -1,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   223,   224,     0,     3,    21,    22,    24,    26,    27,
      29,    30,    37,    39,    40,    41,    46,    52,    57,    58,
      59,    60,    61,    62,    67,    87,    88,    90,    93,    94,
      95,    97,    98,    99,   100,   101,   102,   103,   105,   109,
     110,   111,   112,   113,   115,   116,   153,   155,   216,   218,
     220,   222,    23,   153,   168,   169,   170,    25,    30,    70,
     174,   175,   176,    33,    49,    50,    51,    66,    69,    72,
      81,    93,    94,   106,   107,   108,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   157,   160,   161,   162,   163,   178,   179,   180,
      21,    23,    31,    48,    76,    77,   153,   165,   166,   167,
     157,   163,   181,   182,   183,    23,    35,    36,    86,   184,
     185,   186,    41,    42,    43,    44,    53,   198,   199,   200,
     163,   212,   153,   201,   204,   153,   155,   202,   217,    35,
      36,   190,   191,    23,   192,   193,   194,    23,    86,   195,
     196,   197,   163,    89,    89,    33,    33,   163,    23,   187,
     188,   189,    23,   205,   206,   207,   153,   155,   203,    67,
      67,   155,   157,   163,   153,    41,    42,   161,   215,    33,
       6,    13,    20,   221,     6,     4,     4,   157,   163,    23,
     157,   163,   157,   163,   157,   163,    24,    73,    74,    75,
      84,   163,    33,    33,    33,    24,    73,    74,    75,    82,
      83,    84,   158,   159,   155,    33,    33,   161,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,   135,
     132,   135,   136,   142,   136,   142,   135,    20,    78,    79,
     127,   128,   129,   177,     8,     9,    12,    14,    15,    16,
      17,    18,    19,    96,   104,    79,   129,   177,    23,   153,
     171,   172,   173,   157,    23,   153,    23,   153,    23,   153,
      23,   153,    23,    23,    24,    31,    35,    36,    44,    53,
      55,    56,    64,    65,    75,   164,    24,    31,    35,    36,
      44,    53,    55,    56,    64,    65,   164,   157,   163,    28,
     157,   163,    45,    45,    52,   101,    20,    41,   163,   157,
     163,   157,   163,    28,    68,   161,   161,   157,   163,    33,
     163,   163,    13,   129,   161,   163,    13,   218,   219,   222,
     222,    28,    28,   157,   163,    71,    71,    71,    71,    34,
      34,    34,    34,    34,    34,   157,   163,   157,   163,   157,
     163,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   157,   163,    23,    47,   157,
      23,   157,    23,   157,    23,   157,    23,   157,   157,    32,
      55,    56,    55,    56,    44,    53,    44,    53,    33,   163,
      32,    55,    56,    55,    56,    44,    53,    44,    53,    33,
     157,   163,   157,   163,   157,   163,   213,   214,    41,   153,
     157,   163,     7,     7,   157,   163,    68,     7,   163,   101,
       7,   163,   218,   153,   153,   157,   163,   157,   163,   155,
     155,   155,   155,   155,    34,    34,    34,    34,    34,    34,
       7,     7,     7,     7,    34,    34,    34,    34,     7,    34,
      34,    34,    34,    28,    28,   157,   163,    31,    48,    76,
      77,   157,   157,   157,   157,    28,    47,   157,   157,   163,
     163,   153,   208,   153,   210,   153,    13,    41,    41,   161,
     161,     7,     7,   155,   157,    71,   153,   161,   161,   161,
     161,   161,   161,   153,   153,    28,    28,   154,    31,    48,
      76,    77,     7,     7,   209,   211,    13,   157,   163,   157,
     163,    34,    34,   157,   163,   163,     7,    34,    34,    34,
       7,    34,     7,    34,    34,   154,   154,    28,    28,   157,
     163,     7,     7,   163,    13,    13,    34,    34,   114,   161,
      13,   161,   161,   154,   154,    34,    34,   208,   210,   163,
     163,   163,    34,   163,    34,    34,    13,   163
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   156,   157,   158,   158,   158,   158,   158,   158,   158,
     159,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   163,   164,
     164,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   166,
     166,   166,   166,   166,   167,   167,   168,   168,   169,   169,
     170,   170,   171,   171,   172,   172,   173,   173,   174,   174,
     174,   175,   175,   175,   176,   176,   177,   177,   177,   178,
     178,   178,   179,   179,   179,   180,   180,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   183,   183,   184,
     184,   184,   184,   184,   185,   185,   186,   186,   187,   188,
     189,   189,   190,   190,   191,   192,   193,   194,   194,   195,
     195,   195,   196,   196,   197,   197,   198,   198,   198,   198,
     198,   199,   199,   199,   200,   200,   201,   201,   201,   201,
     201,   201,   202,   202,   203,   203,   204,   205,   206,   207,
     207,   208,   209,   208,   210,   211,   210,   213,   212,   214,
     212,   215,   215,   215,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   217,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     218,   219,   218,   221,   220,   222,   222,   222,   222,   224,
     223
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
       6,     8,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     2,     3,     1,     1,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     2,     3,     4,     5,     4,     3,     5,     4,     4,
       3,     4,     5,     4,     3,     5,     4,     4,     3,     5,
       7,     6,     7,     6,     1,     1,     3,     4,     3,     4,
       1,     1,     3,     4,     3,     4,     1,     1,     2,     4,
       4,     2,     4,     4,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     1,     1,     4,     2,     2,
       3,     7,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     2,     2,     3,     7,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       1,     1,     1,     3,     2,     3,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     2,
       1,     5,     2,     5,     1,     1,     1,     1,     2,     3,
       3,     2,     3,     3,     1,     1,     0,     3,     4,     5,
       5,     6,     1,     1,     1,     1,     1,     6,     6,     1,
       1,     1,     0,     4,     1,     0,     4,     0,     4,     0,
       4,     4,     1,     1,     2,     2,     3,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     3,
       1,     4,     1,     1,     1,     0,     3,     1,     1,     2,
       1,     3,     2,     2,     5,     5,     6,     1,     8,     2,
       2,     1,     1,     2,     2,     2,     2,     1,     1,     1,
       8,     8,     8,    10,     2,     3,     4,     2,     1,     0,
       1,     0,     4,     0,     3,     1,     3,     1,     3,     0,
       2
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
#line 2219 "src-generated/ugbc.tab.c"
    break;

  case 3: /* random_definition_simple: BYTE  */
#line 68 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2227 "src-generated/ugbc.tab.c"
    break;

  case 4: /* random_definition_simple: WORD  */
#line 71 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2235 "src-generated/ugbc.tab.c"
    break;

  case 5: /* random_definition_simple: DWORD  */
#line 74 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2243 "src-generated/ugbc.tab.c"
    break;

  case 6: /* random_definition_simple: POSITION  */
#line 77 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2251 "src-generated/ugbc.tab.c"
    break;

  case 7: /* random_definition_simple: COLOR  */
#line 80 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2259 "src-generated/ugbc.tab.c"
    break;

  case 8: /* random_definition_simple: WIDTH  */
#line 83 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2267 "src-generated/ugbc.tab.c"
    break;

  case 9: /* random_definition_simple: HEIGHT  */
#line 86 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2275 "src-generated/ugbc.tab.c"
    break;

  case 10: /* random_definition: random_definition_simple  */
#line 91 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2283 "src-generated/ugbc.tab.c"
    break;

  case 11: /* color_enumeration: BLACK  */
#line 96 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2292 "src-generated/ugbc.tab.c"
    break;

  case 12: /* color_enumeration: WHITE  */
#line 100 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2301 "src-generated/ugbc.tab.c"
    break;

  case 13: /* color_enumeration: RED  */
#line 104 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2310 "src-generated/ugbc.tab.c"
    break;

  case 14: /* color_enumeration: CYAN  */
#line 108 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2319 "src-generated/ugbc.tab.c"
    break;

  case 15: /* color_enumeration: VIOLET  */
#line 112 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2328 "src-generated/ugbc.tab.c"
    break;

  case 16: /* color_enumeration: GREEN  */
#line 116 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2337 "src-generated/ugbc.tab.c"
    break;

  case 17: /* color_enumeration: BLUE  */
#line 120 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2346 "src-generated/ugbc.tab.c"
    break;

  case 18: /* color_enumeration: YELLOW  */
#line 124 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2355 "src-generated/ugbc.tab.c"
    break;

  case 19: /* color_enumeration: ORANGE  */
#line 128 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2364 "src-generated/ugbc.tab.c"
    break;

  case 20: /* color_enumeration: BROWN  */
#line 132 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2373 "src-generated/ugbc.tab.c"
    break;

  case 21: /* color_enumeration: LIGHT RED  */
#line 136 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2382 "src-generated/ugbc.tab.c"
    break;

  case 22: /* color_enumeration: DARK GREY  */
#line 140 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2391 "src-generated/ugbc.tab.c"
    break;

  case 23: /* color_enumeration: GREY  */
#line 144 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2400 "src-generated/ugbc.tab.c"
    break;

  case 24: /* color_enumeration: LIGHT GREEN  */
#line 148 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2409 "src-generated/ugbc.tab.c"
    break;

  case 25: /* color_enumeration: LIGHT BLUE  */
#line 152 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2418 "src-generated/ugbc.tab.c"
    break;

  case 26: /* color_enumeration: LIGHT GREY  */
#line 156 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2427 "src-generated/ugbc.tab.c"
    break;

  case 27: /* color_enumeration: DARK BLUE  */
#line 160 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2436 "src-generated/ugbc.tab.c"
    break;

  case 28: /* color_enumeration: MAGENTA  */
#line 164 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2445 "src-generated/ugbc.tab.c"
    break;

  case 29: /* color_enumeration: PURPLE  */
#line 168 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2454 "src-generated/ugbc.tab.c"
    break;

  case 30: /* color_enumeration: LAVENDER  */
#line 172 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2463 "src-generated/ugbc.tab.c"
    break;

  case 31: /* color_enumeration: GOLD  */
#line 176 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2472 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: TURQUOISE  */
#line 180 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2481 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: TAN  */
#line 184 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2490 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: YELLOW GREEN  */
#line 188 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2499 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: OLIVE GREEN  */
#line 192 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2508 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: PINK  */
#line 196 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2517 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: PEACH  */
#line 200 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2526 "src-generated/ugbc.tab.c"
    break;

  case 38: /* expression: Identifier  */
#line 206 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2534 "src-generated/ugbc.tab.c"
    break;

  case 39: /* expression: Identifier DOLLAR  */
#line 209 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[-1].string);
      }
#line 2542 "src-generated/ugbc.tab.c"
    break;

  case 40: /* expression: Integer  */
#line 212 "src/ugbc.y"
              { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2551 "src-generated/ugbc.tab.c"
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
#line 2563 "src-generated/ugbc.tab.c"
    break;

  case 42: /* expression: OP BYTE CP Integer  */
#line 223 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2572 "src-generated/ugbc.tab.c"
    break;

  case 43: /* expression: OP WORD CP Integer  */
#line 227 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2581 "src-generated/ugbc.tab.c"
    break;

  case 44: /* expression: OP DWORD CP Integer  */
#line 231 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2590 "src-generated/ugbc.tab.c"
    break;

  case 45: /* expression: OP POSITION CP Integer  */
#line 235 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2599 "src-generated/ugbc.tab.c"
    break;

  case 46: /* expression: OP COLOR CP Integer  */
#line 239 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2608 "src-generated/ugbc.tab.c"
    break;

  case 47: /* expression: color_enumeration  */
#line 243 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2616 "src-generated/ugbc.tab.c"
    break;

  case 48: /* expression: PEEK OP direct_integer CP  */
#line 246 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2624 "src-generated/ugbc.tab.c"
    break;

  case 49: /* expression: PEEK OP expressions CP  */
#line 249 "src/ugbc.y"
                             {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 2632 "src-generated/ugbc.tab.c"
    break;

  case 50: /* expression: XPEN  */
#line 252 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 2640 "src-generated/ugbc.tab.c"
    break;

  case 51: /* expression: YPEN  */
#line 255 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 2648 "src-generated/ugbc.tab.c"
    break;

  case 52: /* expression: COLLISION OP direct_integer CP  */
#line 258 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2656 "src-generated/ugbc.tab.c"
    break;

  case 53: /* expression: COLLISION OP expressions CP  */
#line 261 "src/ugbc.y"
                                  {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2664 "src-generated/ugbc.tab.c"
    break;

  case 54: /* expression: HIT OP direct_integer CP  */
#line 264 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2672 "src-generated/ugbc.tab.c"
    break;

  case 55: /* expression: HIT OP expressions CP  */
#line 267 "src/ugbc.y"
                            {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2680 "src-generated/ugbc.tab.c"
    break;

  case 56: /* expression: LEFT OP expression COMMA expression CP  */
#line 270 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2688 "src-generated/ugbc.tab.c"
    break;

  case 57: /* expression: RIGHT OP expression COMMA expression CP  */
#line 273 "src/ugbc.y"
                                              {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2696 "src-generated/ugbc.tab.c"
    break;

  case 58: /* expression: MID OP expression COMMA expression CP  */
#line 276 "src/ugbc.y"
                                            {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 2704 "src-generated/ugbc.tab.c"
    break;

  case 59: /* expression: MID OP expression COMMA expression COMMA expression CP  */
#line 279 "src/ugbc.y"
                                                             {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2712 "src-generated/ugbc.tab.c"
    break;

  case 60: /* expression: INSTR OP expression COMMA expression CP  */
#line 282 "src/ugbc.y"
                                              {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 2720 "src-generated/ugbc.tab.c"
    break;

  case 61: /* expression: INSTR OP expression COMMA expression COMMA expression CP  */
#line 285 "src/ugbc.y"
                                                               {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2728 "src-generated/ugbc.tab.c"
    break;

  case 62: /* expression: UPPER OP expression CP  */
#line 288 "src/ugbc.y"
                             {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 2736 "src-generated/ugbc.tab.c"
    break;

  case 63: /* expression: LOWER OP expression CP  */
#line 291 "src/ugbc.y"
                             {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 2744 "src-generated/ugbc.tab.c"
    break;

  case 64: /* expression: STR OP expression CP  */
#line 294 "src/ugbc.y"
                           {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 2752 "src-generated/ugbc.tab.c"
    break;

  case 65: /* expression: SPACE OP expression CP  */
#line 297 "src/ugbc.y"
                             {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 2760 "src-generated/ugbc.tab.c"
    break;

  case 66: /* expression: FLIP OP expression CP  */
#line 300 "src/ugbc.y"
                            {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 2768 "src-generated/ugbc.tab.c"
    break;

  case 67: /* expression: CHR OP expression CP  */
#line 303 "src/ugbc.y"
                           {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 2776 "src-generated/ugbc.tab.c"
    break;

  case 68: /* expression: ASC OP expression CP  */
#line 306 "src/ugbc.y"
                           {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 2784 "src-generated/ugbc.tab.c"
    break;

  case 69: /* expression: STRING OP expression COMMA expression CP  */
#line 309 "src/ugbc.y"
                                               {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2792 "src-generated/ugbc.tab.c"
    break;

  case 70: /* expression: VAL OP expression CP  */
#line 312 "src/ugbc.y"
                           {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 2800 "src-generated/ugbc.tab.c"
    break;

  case 71: /* expression: RANDOM random_definition  */
#line 315 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 2808 "src-generated/ugbc.tab.c"
    break;

  case 72: /* expression: OP expressions CP  */
#line 318 "src/ugbc.y"
                        {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 2816 "src-generated/ugbc.tab.c"
    break;

  case 73: /* expression: TRUE  */
#line 321 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 2825 "src-generated/ugbc.tab.c"
    break;

  case 74: /* expression: FALSE  */
#line 325 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 2834 "src-generated/ugbc.tab.c"
    break;

  case 75: /* expression: NOT expression  */
#line 329 "src/ugbc.y"
                     {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2842 "src-generated/ugbc.tab.c"
    break;

  case 76: /* expressions_raw: expression  */
#line 335 "src/ugbc.y"
                 { (yyval.string) = (yyvsp[0].string); }
#line 2848 "src-generated/ugbc.tab.c"
    break;

  case 77: /* expressions_raw: expression PLUS expressions_raw  */
#line 336 "src/ugbc.y"
                                      {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2856 "src-generated/ugbc.tab.c"
    break;

  case 78: /* expressions_raw: expression MINUS expressions_raw  */
#line 339 "src/ugbc.y"
                                       {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2865 "src-generated/ugbc.tab.c"
    break;

  case 79: /* expressions_raw: expression MULTIPLICATION expressions_raw  */
#line 343 "src/ugbc.y"
                                                {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2874 "src-generated/ugbc.tab.c"
    break;

  case 80: /* expressions_raw: expression AND expressions_raw  */
#line 347 "src/ugbc.y"
                                     {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2883 "src-generated/ugbc.tab.c"
    break;

  case 81: /* expressions_raw: expression OR expressions_raw  */
#line 351 "src/ugbc.y"
                                    {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2892 "src-generated/ugbc.tab.c"
    break;

  case 82: /* expressions_raw: expression EQUAL expressions_raw  */
#line 355 "src/ugbc.y"
                                       {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2900 "src-generated/ugbc.tab.c"
    break;

  case 83: /* expressions_raw: expression DISEQUAL expressions_raw  */
#line 358 "src/ugbc.y"
                                          {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2908 "src-generated/ugbc.tab.c"
    break;

  case 84: /* expressions_raw: expression LT expressions_raw  */
#line 361 "src/ugbc.y"
                                    {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2916 "src-generated/ugbc.tab.c"
    break;

  case 85: /* expressions_raw: expression LTE expressions_raw  */
#line 364 "src/ugbc.y"
                                     {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2924 "src-generated/ugbc.tab.c"
    break;

  case 86: /* expressions_raw: expression GT expressions_raw  */
#line 367 "src/ugbc.y"
                                    {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2932 "src-generated/ugbc.tab.c"
    break;

  case 87: /* expressions_raw: expression GTE expressions_raw  */
#line 370 "src/ugbc.y"
                                     {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2940 "src-generated/ugbc.tab.c"
    break;

  case 88: /* expressions: expressions_raw  */
#line 376 "src/ugbc.y"
                    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2948 "src-generated/ugbc.tab.c"
    break;

  case 91: /* bank_definition_simple: AT direct_integer  */
#line 383 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2956 "src-generated/ugbc.tab.c"
    break;

  case 92: /* bank_definition_simple: Identifier AT direct_integer  */
#line 386 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2964 "src-generated/ugbc.tab.c"
    break;

  case 93: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 389 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2972 "src-generated/ugbc.tab.c"
    break;

  case 94: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 392 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2980 "src-generated/ugbc.tab.c"
    break;

  case 95: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 395 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2988 "src-generated/ugbc.tab.c"
    break;

  case 96: /* bank_definition_simple: DATA AT direct_integer  */
#line 398 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2996 "src-generated/ugbc.tab.c"
    break;

  case 97: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 402 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3004 "src-generated/ugbc.tab.c"
    break;

  case 98: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 405 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 3012 "src-generated/ugbc.tab.c"
    break;

  case 99: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 408 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3020 "src-generated/ugbc.tab.c"
    break;

  case 100: /* bank_definition_simple: CODE AT direct_integer  */
#line 411 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 3028 "src-generated/ugbc.tab.c"
    break;

  case 101: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 415 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3036 "src-generated/ugbc.tab.c"
    break;

  case 102: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 418 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 3044 "src-generated/ugbc.tab.c"
    break;

  case 103: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 421 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3052 "src-generated/ugbc.tab.c"
    break;

  case 104: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 424 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3060 "src-generated/ugbc.tab.c"
    break;

  case 105: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 428 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3068 "src-generated/ugbc.tab.c"
    break;

  case 106: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 431 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3076 "src-generated/ugbc.tab.c"
    break;

  case 107: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 434 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3084 "src-generated/ugbc.tab.c"
    break;

  case 108: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 437 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3092 "src-generated/ugbc.tab.c"
    break;

  case 109: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 443 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3100 "src-generated/ugbc.tab.c"
    break;

  case 110: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 446 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3108 "src-generated/ugbc.tab.c"
    break;

  case 111: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 449 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3116 "src-generated/ugbc.tab.c"
    break;

  case 112: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 452 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3124 "src-generated/ugbc.tab.c"
    break;

  case 113: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 455 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3132 "src-generated/ugbc.tab.c"
    break;

  case 116: /* raster_definition_simple: Identifier AT direct_integer  */
#line 464 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3140 "src-generated/ugbc.tab.c"
    break;

  case 117: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 467 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3148 "src-generated/ugbc.tab.c"
    break;

  case 118: /* raster_definition_expression: Identifier AT expressions  */
#line 472 "src/ugbc.y"
                              {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3156 "src-generated/ugbc.tab.c"
    break;

  case 119: /* raster_definition_expression: AT expressions WITH Identifier  */
#line 475 "src/ugbc.y"
                                   {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3164 "src-generated/ugbc.tab.c"
    break;

  case 122: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 484 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3172 "src-generated/ugbc.tab.c"
    break;

  case 123: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 487 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3180 "src-generated/ugbc.tab.c"
    break;

  case 124: /* next_raster_definition_expression: Identifier AT expressions  */
#line 492 "src/ugbc.y"
                              {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3188 "src-generated/ugbc.tab.c"
    break;

  case 125: /* next_raster_definition_expression: AT expressions WITH Identifier  */
#line 495 "src/ugbc.y"
                                   {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3196 "src-generated/ugbc.tab.c"
    break;

  case 128: /* color_definition_simple: BORDER direct_integer  */
#line 504 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3204 "src-generated/ugbc.tab.c"
    break;

  case 129: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 507 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3212 "src-generated/ugbc.tab.c"
    break;

  case 130: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 510 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3220 "src-generated/ugbc.tab.c"
    break;

  case 131: /* color_definition_expression: BORDER expressions  */
#line 515 "src/ugbc.y"
                       {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3228 "src-generated/ugbc.tab.c"
    break;

  case 132: /* color_definition_expression: BACKGROUND expressions TO expressions  */
#line 518 "src/ugbc.y"
                                          {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3236 "src-generated/ugbc.tab.c"
    break;

  case 133: /* color_definition_expression: SPRITE expressions TO expressions  */
#line 521 "src/ugbc.y"
                                      {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3244 "src-generated/ugbc.tab.c"
    break;

  case 139: /* wait_definition_simple: direct_integer CYCLES  */
#line 535 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3252 "src-generated/ugbc.tab.c"
    break;

  case 140: /* wait_definition_simple: direct_integer TICKS  */
#line 538 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3260 "src-generated/ugbc.tab.c"
    break;

  case 141: /* wait_definition_simple: direct_integer milliseconds  */
#line 541 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3268 "src-generated/ugbc.tab.c"
    break;

  case 142: /* wait_definition_expression: expressions CYCLES  */
#line 546 "src/ugbc.y"
                         {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3276 "src-generated/ugbc.tab.c"
    break;

  case 143: /* wait_definition_expression: expressions TICKS  */
#line 549 "src/ugbc.y"
                        {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3284 "src-generated/ugbc.tab.c"
    break;

  case 144: /* wait_definition_expression: expressions milliseconds  */
#line 552 "src/ugbc.y"
                               {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3292 "src-generated/ugbc.tab.c"
    break;

  case 147: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 562 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3300 "src-generated/ugbc.tab.c"
    break;

  case 148: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 565 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3308 "src-generated/ugbc.tab.c"
    break;

  case 149: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 568 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3316 "src-generated/ugbc.tab.c"
    break;

  case 150: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 571 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3324 "src-generated/ugbc.tab.c"
    break;

  case 151: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 574 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3332 "src-generated/ugbc.tab.c"
    break;

  case 152: /* sprite_definition_simple: direct_integer ENABLE  */
#line 577 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3340 "src-generated/ugbc.tab.c"
    break;

  case 153: /* sprite_definition_simple: direct_integer DISABLE  */
#line 580 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3348 "src-generated/ugbc.tab.c"
    break;

  case 154: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 583 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3356 "src-generated/ugbc.tab.c"
    break;

  case 155: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 586 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3364 "src-generated/ugbc.tab.c"
    break;

  case 156: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 589 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3372 "src-generated/ugbc.tab.c"
    break;

  case 157: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 592 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3380 "src-generated/ugbc.tab.c"
    break;

  case 158: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 595 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3388 "src-generated/ugbc.tab.c"
    break;

  case 159: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 598 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3396 "src-generated/ugbc.tab.c"
    break;

  case 160: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 601 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3404 "src-generated/ugbc.tab.c"
    break;

  case 161: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 604 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3412 "src-generated/ugbc.tab.c"
    break;

  case 162: /* sprite_definition_expression: expressions DATA FROM expressions  */
#line 609 "src/ugbc.y"
                                      {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3420 "src-generated/ugbc.tab.c"
    break;

  case 163: /* sprite_definition_expression: expressions MULTICOLOR  */
#line 612 "src/ugbc.y"
                           {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3428 "src-generated/ugbc.tab.c"
    break;

  case 164: /* sprite_definition_expression: expressions MONOCOLOR  */
#line 615 "src/ugbc.y"
                          {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3436 "src-generated/ugbc.tab.c"
    break;

  case 165: /* sprite_definition_expression: expressions COLOR expressions  */
#line 618 "src/ugbc.y"
                                  {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3444 "src-generated/ugbc.tab.c"
    break;

  case 166: /* sprite_definition_expression: expressions position OP expressions COMMA expressions CP  */
#line 621 "src/ugbc.y"
                                                             {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3452 "src-generated/ugbc.tab.c"
    break;

  case 167: /* sprite_definition_expression: expressions ENABLE  */
#line 624 "src/ugbc.y"
                       {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3460 "src-generated/ugbc.tab.c"
    break;

  case 168: /* sprite_definition_expression: expressions DISABLE  */
#line 627 "src/ugbc.y"
                        {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3468 "src-generated/ugbc.tab.c"
    break;

  case 169: /* sprite_definition_expression: expressions EXPAND VERTICAL  */
#line 630 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3476 "src-generated/ugbc.tab.c"
    break;

  case 170: /* sprite_definition_expression: expressions COMPRESS VERTICAL  */
#line 633 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3484 "src-generated/ugbc.tab.c"
    break;

  case 171: /* sprite_definition_expression: expressions VERTICAL EXPAND  */
#line 636 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3492 "src-generated/ugbc.tab.c"
    break;

  case 172: /* sprite_definition_expression: expressions VERTICAL COMPRESS  */
#line 639 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3500 "src-generated/ugbc.tab.c"
    break;

  case 173: /* sprite_definition_expression: expressions EXPAND HORIZONTAL  */
#line 642 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3508 "src-generated/ugbc.tab.c"
    break;

  case 174: /* sprite_definition_expression: expressions COMPRESS HORIZONTAL  */
#line 645 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3516 "src-generated/ugbc.tab.c"
    break;

  case 175: /* sprite_definition_expression: expressions HORIZONTAL EXPAND  */
#line 648 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3524 "src-generated/ugbc.tab.c"
    break;

  case 176: /* sprite_definition_expression: expressions HORIZONTAL COMPRESS  */
#line 651 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3532 "src-generated/ugbc.tab.c"
    break;

  case 179: /* bitmap_definition_simple: AT direct_integer  */
#line 660 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3540 "src-generated/ugbc.tab.c"
    break;

  case 180: /* bitmap_definition_simple: ENABLE  */
#line 663 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3548 "src-generated/ugbc.tab.c"
    break;

  case 181: /* bitmap_definition_simple: DISABLE  */
#line 666 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 3556 "src-generated/ugbc.tab.c"
    break;

  case 182: /* bitmap_definition_simple: CLEAR  */
#line 669 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 3564 "src-generated/ugbc.tab.c"
    break;

  case 183: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 672 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 3572 "src-generated/ugbc.tab.c"
    break;

  case 184: /* bitmap_definition_expression: AT expressions  */
#line 678 "src/ugbc.y"
                   {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3580 "src-generated/ugbc.tab.c"
    break;

  case 185: /* bitmap_definition_expression: CLEAR WITH expressions  */
#line 681 "src/ugbc.y"
                           {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 3588 "src-generated/ugbc.tab.c"
    break;

  case 188: /* textmap_definition_simple: AT direct_integer  */
#line 691 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3596 "src-generated/ugbc.tab.c"
    break;

  case 189: /* textmap_definition_expression: AT expressions  */
#line 696 "src/ugbc.y"
                   {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3604 "src-generated/ugbc.tab.c"
    break;

  case 192: /* text_definition_simple: ENABLE  */
#line 705 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3612 "src-generated/ugbc.tab.c"
    break;

  case 193: /* text_definition_simple: DISABLE  */
#line 708 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 3620 "src-generated/ugbc.tab.c"
    break;

  case 195: /* tiles_definition_simple: AT direct_integer  */
#line 716 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 3628 "src-generated/ugbc.tab.c"
    break;

  case 196: /* tiles_definition_expression: AT expressions  */
#line 721 "src/ugbc.y"
                   {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 3636 "src-generated/ugbc.tab.c"
    break;

  case 199: /* colormap_definition_simple: AT direct_integer  */
#line 730 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 3644 "src-generated/ugbc.tab.c"
    break;

  case 200: /* colormap_definition_simple: CLEAR  */
#line 733 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 3652 "src-generated/ugbc.tab.c"
    break;

  case 201: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 736 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3660 "src-generated/ugbc.tab.c"
    break;

  case 202: /* colormap_definition_expression: AT expressions  */
#line 741 "src/ugbc.y"
                   {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3668 "src-generated/ugbc.tab.c"
    break;

  case 203: /* colormap_definition_expression: CLEAR WITH expressions ON expressions  */
#line 744 "src/ugbc.y"
                                          {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3676 "src-generated/ugbc.tab.c"
    break;

  case 206: /* screen_definition_simple: ON  */
#line 754 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 3684 "src-generated/ugbc.tab.c"
    break;

  case 207: /* screen_definition_simple: OFF  */
#line 757 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 3692 "src-generated/ugbc.tab.c"
    break;

  case 208: /* screen_definition_simple: ROWS direct_integer  */
#line 760 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 3700 "src-generated/ugbc.tab.c"
    break;

  case 209: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 763 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3708 "src-generated/ugbc.tab.c"
    break;

  case 210: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 766 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3716 "src-generated/ugbc.tab.c"
    break;

  case 211: /* screen_definition_expression: ROWS expressions  */
#line 771 "src/ugbc.y"
                     {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 3724 "src-generated/ugbc.tab.c"
    break;

  case 212: /* screen_definition_expression: VERTICAL SCROLL expressions  */
#line 774 "src/ugbc.y"
                                {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3732 "src-generated/ugbc.tab.c"
    break;

  case 213: /* screen_definition_expression: HORIZONTAL SCROLL expressions  */
#line 777 "src/ugbc.y"
                                  {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3740 "src-generated/ugbc.tab.c"
    break;

  case 217: /* var_definition_simple: Identifier ON Identifier  */
#line 786 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 3748 "src-generated/ugbc.tab.c"
    break;

  case 218: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 789 "src/ugbc.y"
                                    {
      variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 3756 "src-generated/ugbc.tab.c"
    break;

  case 219: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 792 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 3764 "src-generated/ugbc.tab.c"
    break;

  case 220: /* var_definition_simple: Identifier ON Identifier ASSIGN expressions  */
#line 795 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 3774 "src-generated/ugbc.tab.c"
    break;

  case 221: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expressions  */
#line 800 "src/ugbc.y"
                                                       {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 3784 "src-generated/ugbc.tab.c"
    break;

  case 222: /* goto_definition: Identifier  */
#line 807 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 3792 "src-generated/ugbc.tab.c"
    break;

  case 223: /* goto_definition: Integer  */
#line 810 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 3800 "src-generated/ugbc.tab.c"
    break;

  case 224: /* gosub_definition: Identifier  */
#line 816 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 3808 "src-generated/ugbc.tab.c"
    break;

  case 225: /* gosub_definition: Integer  */
#line 819 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 3816 "src-generated/ugbc.tab.c"
    break;

  case 227: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 828 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 3824 "src-generated/ugbc.tab.c"
    break;

  case 228: /* point_definition_expression: AT OP expressions COMMA expressions CP  */
#line 834 "src/ugbc.y"
                                             {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 3832 "src-generated/ugbc.tab.c"
    break;

  case 231: /* on_goto_definition: Identifier  */
#line 843 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 3841 "src-generated/ugbc.tab.c"
    break;

  case 232: /* $@1: %empty  */
#line 847 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 3849 "src-generated/ugbc.tab.c"
    break;

  case 234: /* on_gosub_definition: Identifier  */
#line 852 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 3858 "src-generated/ugbc.tab.c"
    break;

  case 235: /* $@2: %empty  */
#line 856 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 3866 "src-generated/ugbc.tab.c"
    break;

  case 237: /* $@3: %empty  */
#line 861 "src/ugbc.y"
                       {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 3874 "src-generated/ugbc.tab.c"
    break;

  case 239: /* $@4: %empty  */
#line 864 "src/ugbc.y"
                        {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 3882 "src-generated/ugbc.tab.c"
    break;

  case 241: /* every_definition: expression TICKS GOSUB Identifier  */
#line 869 "src/ugbc.y"
                                        {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 3890 "src-generated/ugbc.tab.c"
    break;

  case 242: /* every_definition: ON  */
#line 872 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 3898 "src-generated/ugbc.tab.c"
    break;

  case 243: /* every_definition: OFF  */
#line 875 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 3906 "src-generated/ugbc.tab.c"
    break;

  case 258: /* statement: RANDOMIZE  */
#line 894 "src/ugbc.y"
              {
      randomize( _environment );
  }
#line 3914 "src-generated/ugbc.tab.c"
    break;

  case 259: /* statement: IF expressions THEN  */
#line 897 "src/ugbc.y"
                        {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 3922 "src-generated/ugbc.tab.c"
    break;

  case 260: /* statement: ELSE  */
#line 900 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 3930 "src-generated/ugbc.tab.c"
    break;

  case 261: /* statement: ELSE IF expressions THEN  */
#line 903 "src/ugbc.y"
                             {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 3938 "src-generated/ugbc.tab.c"
    break;

  case 262: /* statement: ENDIF  */
#line 906 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 3946 "src-generated/ugbc.tab.c"
    break;

  case 263: /* statement: DO  */
#line 909 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 3954 "src-generated/ugbc.tab.c"
    break;

  case 264: /* statement: LOOP  */
#line 912 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 3962 "src-generated/ugbc.tab.c"
    break;

  case 265: /* $@5: %empty  */
#line 915 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 3970 "src-generated/ugbc.tab.c"
    break;

  case 266: /* statement: WHILE $@5 expressions  */
#line 917 "src/ugbc.y"
                {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 3978 "src-generated/ugbc.tab.c"
    break;

  case 267: /* statement: WEND  */
#line 920 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 3986 "src-generated/ugbc.tab.c"
    break;

  case 268: /* statement: REPEAT  */
#line 923 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 3994 "src-generated/ugbc.tab.c"
    break;

  case 269: /* statement: UNTIL expressions  */
#line 926 "src/ugbc.y"
                      {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 4002 "src-generated/ugbc.tab.c"
    break;

  case 270: /* statement: EXIT  */
#line 929 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 4010 "src-generated/ugbc.tab.c"
    break;

  case 271: /* statement: EXIT IF expressions  */
#line 932 "src/ugbc.y"
                        {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 4018 "src-generated/ugbc.tab.c"
    break;

  case 272: /* statement: EXIT Integer  */
#line 935 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4026 "src-generated/ugbc.tab.c"
    break;

  case 273: /* statement: EXIT direct_integer  */
#line 938 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 4034 "src-generated/ugbc.tab.c"
    break;

  case 274: /* statement: EXIT IF expressions COMMA Integer  */
#line 941 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4042 "src-generated/ugbc.tab.c"
    break;

  case 275: /* statement: EXIT IF expressions COMMA direct_integer  */
#line 944 "src/ugbc.y"
                                             {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 4050 "src-generated/ugbc.tab.c"
    break;

  case 276: /* statement: FOR Identifier ASSIGN expressions TO expressions  */
#line 947 "src/ugbc.y"
                                                     {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4058 "src-generated/ugbc.tab.c"
    break;

  case 277: /* statement: NEXT  */
#line 950 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 4066 "src-generated/ugbc.tab.c"
    break;

  case 278: /* statement: FOR Identifier ASSIGN expressions TO expressions STEP expressions  */
#line 953 "src/ugbc.y"
                                                                      {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4074 "src-generated/ugbc.tab.c"
    break;

  case 279: /* statement: BEG GAMELOOP  */
#line 956 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 4082 "src-generated/ugbc.tab.c"
    break;

  case 280: /* statement: END GAMELOOP  */
#line 959 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 4090 "src-generated/ugbc.tab.c"
    break;

  case 281: /* statement: GRAPHIC  */
#line 962 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 4098 "src-generated/ugbc.tab.c"
    break;

  case 282: /* statement: HALT  */
#line 965 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 4106 "src-generated/ugbc.tab.c"
    break;

  case 287: /* statement: RETURN  */
#line 972 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 4114 "src-generated/ugbc.tab.c"
    break;

  case 288: /* statement: POP  */
#line 975 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 4122 "src-generated/ugbc.tab.c"
    break;

  case 289: /* statement: DONE  */
#line 978 "src/ugbc.y"
          {
      return 0;
  }
#line 4130 "src-generated/ugbc.tab.c"
    break;

  case 290: /* statement: LEFT OP expression COMMA expression CP ASSIGN expressions  */
#line 981 "src/ugbc.y"
                                                              {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4138 "src-generated/ugbc.tab.c"
    break;

  case 291: /* statement: RIGHT OP expression COMMA expression CP ASSIGN expressions  */
#line 984 "src/ugbc.y"
                                                               {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4146 "src-generated/ugbc.tab.c"
    break;

  case 292: /* statement: MID OP expression COMMA expression CP ASSIGN expressions  */
#line 987 "src/ugbc.y"
                                                             {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 4154 "src-generated/ugbc.tab.c"
    break;

  case 293: /* statement: MID OP expression COMMA expression COMMA expression CP ASSIGN expressions  */
#line 990 "src/ugbc.y"
                                                                              {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4162 "src-generated/ugbc.tab.c"
    break;

  case 294: /* statement: Identifier COLON  */
#line 993 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 4170 "src-generated/ugbc.tab.c"
    break;

  case 295: /* statement: Identifier ASSIGN expressions  */
#line 996 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expressions = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expressions->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 4184 "src-generated/ugbc.tab.c"
    break;

  case 296: /* statement: Identifier DOLLAR ASSIGN expressions  */
#line 1005 "src/ugbc.y"
                                         {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expressions = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 4198 "src-generated/ugbc.tab.c"
    break;

  case 297: /* statement: DEBUG expressions  */
#line 1014 "src/ugbc.y"
                      {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 4206 "src-generated/ugbc.tab.c"
    break;

  case 300: /* statements_no_linenumbers: statement  */
#line 1022 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 4212 "src-generated/ugbc.tab.c"
    break;

  case 301: /* $@6: %empty  */
#line 1023 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 4218 "src-generated/ugbc.tab.c"
    break;

  case 303: /* $@7: %empty  */
#line 1027 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 4226 "src-generated/ugbc.tab.c"
    break;

  case 304: /* statements_with_linenumbers: Integer $@7 statements_no_linenumbers  */
#line 1029 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 4234 "src-generated/ugbc.tab.c"
    break;

  case 309: /* $@8: %empty  */
#line 1041 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 4240 "src-generated/ugbc.tab.c"
    break;


#line 4244 "src-generated/ugbc.tab.c"

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

#line 1043 "src/ugbc.y"


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

    if ( _environment->configurationFileName ) {
        _environment->configurationFile = fopen( _environment->configurationFileName, "wt");
        if ( ! _environment->configurationFile ) {
            fprintf(stderr, "Unable to open configuration file: %s\n", _environment->configurationFileName );
            exit(EXIT_FAILURE);
        }
        linker_setup( _environment );
        outhead0(".segment \"CODE\"");
    } else {
        outhead0("org 32768");
    }

    variable_define( _environment, "strings_address", VT_ADDRESS, 0x4200 );
    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x4000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x4100, NULL );
    bank_define( _environment, "STRINGS", BT_STRINGS, 0x4200, NULL );

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

