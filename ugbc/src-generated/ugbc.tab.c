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
  YYSYMBOL_MILLISECOND = 120,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 121,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 122,                    /* TICKS  */
  YYSYMBOL_BLACK = 123,                    /* BLACK  */
  YYSYMBOL_WHITE = 124,                    /* WHITE  */
  YYSYMBOL_RED = 125,                      /* RED  */
  YYSYMBOL_CYAN = 126,                     /* CYAN  */
  YYSYMBOL_VIOLET = 127,                   /* VIOLET  */
  YYSYMBOL_GREEN = 128,                    /* GREEN  */
  YYSYMBOL_BLUE = 129,                     /* BLUE  */
  YYSYMBOL_YELLOW = 130,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 131,                   /* ORANGE  */
  YYSYMBOL_BROWN = 132,                    /* BROWN  */
  YYSYMBOL_LIGHT = 133,                    /* LIGHT  */
  YYSYMBOL_DARK = 134,                     /* DARK  */
  YYSYMBOL_GREY = 135,                     /* GREY  */
  YYSYMBOL_GRAY = 136,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 137,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 138,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 139,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 140,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 141,                /* TURQUOISE  */
  YYSYMBOL_TAN = 142,                      /* TAN  */
  YYSYMBOL_PINK = 143,                     /* PINK  */
  YYSYMBOL_PEACH = 144,                    /* PEACH  */
  YYSYMBOL_OLIVE = 145,                    /* OLIVE  */
  YYSYMBOL_Identifier = 146,               /* Identifier  */
  YYSYMBOL_String = 147,                   /* String  */
  YYSYMBOL_Integer = 148,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 149,                 /* $accept  */
  YYSYMBOL_direct_integer = 150,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 151, /* random_definition_simple  */
  YYSYMBOL_random_definition = 152,        /* random_definition  */
  YYSYMBOL_color_enumeration = 153,        /* color_enumeration  */
  YYSYMBOL_expression = 154,               /* expression  */
  YYSYMBOL_expressions_raw = 155,          /* expressions_raw  */
  YYSYMBOL_expressions = 156,              /* expressions  */
  YYSYMBOL_position = 157,                 /* position  */
  YYSYMBOL_bank_definition_simple = 158,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 159, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 160,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 161, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 162, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 163,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 164, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 165, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 166,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 167,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 168, /* color_definition_expression  */
  YYSYMBOL_color_definition = 169,         /* color_definition  */
  YYSYMBOL_milliseconds = 170,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 171,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 172, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 173,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 174, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 175, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 176,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 177, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 178, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 179,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 180, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 181, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 182,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 183,   /* text_definition_simple  */
  YYSYMBOL_text_definition = 184,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 185,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 186, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 187,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 188, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 189, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 190,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 191, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 192, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 193,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 194,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 195,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 196,         /* gosub_definition  */
  YYSYMBOL_var_definition = 197,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 198,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 199, /* point_definition_expression  */
  YYSYMBOL_point_definition = 200,         /* point_definition  */
  YYSYMBOL_on_goto_definition = 201,       /* on_goto_definition  */
  YYSYMBOL_202_1 = 202,                    /* $@1  */
  YYSYMBOL_on_gosub_definition = 203,      /* on_gosub_definition  */
  YYSYMBOL_204_2 = 204,                    /* $@2  */
  YYSYMBOL_on_definition = 205,            /* on_definition  */
  YYSYMBOL_206_3 = 206,                    /* $@3  */
  YYSYMBOL_207_4 = 207,                    /* $@4  */
  YYSYMBOL_every_definition = 208,         /* every_definition  */
  YYSYMBOL_statement = 209,                /* statement  */
  YYSYMBOL_210_5 = 210,                    /* $@5  */
  YYSYMBOL_statements_no_linenumbers = 211, /* statements_no_linenumbers  */
  YYSYMBOL_212_6 = 212,                    /* $@6  */
  YYSYMBOL_statements_with_linenumbers = 213, /* statements_with_linenumbers  */
  YYSYMBOL_214_7 = 214,                    /* $@7  */
  YYSYMBOL_statements_complex = 215,       /* statements_complex  */
  YYSYMBOL_program = 216,                  /* program  */
  YYSYMBOL_217_8 = 217                     /* $@8  */
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
#define YYLAST   1167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  149
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  303
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  558

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   403


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
     145,   146,   147,   148
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
     282,   285,   288,   291,   294,   297,   300,   304,   308,   314,
     315,   318,   322,   326,   330,   334,   337,   340,   343,   346,
     349,   355,   359,   359,   362,   365,   368,   371,   374,   377,
     381,   384,   387,   390,   394,   397,   400,   403,   407,   410,
     413,   416,   422,   425,   428,   431,   434,   439,   440,   443,
     446,   451,   454,   459,   460,   463,   466,   471,   474,   479,
     480,   483,   486,   489,   494,   497,   500,   505,   506,   509,
     510,   511,   514,   517,   520,   525,   528,   531,   537,   538,
     541,   544,   547,   550,   553,   556,   559,   562,   565,   568,
     571,   574,   577,   580,   583,   588,   591,   594,   597,   600,
     603,   606,   609,   612,   615,   618,   621,   624,   627,   630,
     635,   636,   639,   642,   645,   648,   651,   657,   660,   666,
     667,   670,   675,   680,   681,   684,   687,   692,   695,   700,
     705,   706,   709,   712,   715,   720,   723,   729,   730,   733,
     736,   739,   742,   745,   750,   753,   756,   761,   762,   764,
     765,   768,   771,   774,   779,   786,   789,   795,   798,   804,
     807,   813,   818,   819,   822,   826,   826,   831,   835,   835,
     840,   840,   843,   843,   848,   851,   854,   859,   860,   861,
     862,   863,   864,   865,   866,   867,   868,   869,   870,   871,
     872,   873,   876,   879,   882,   885,   888,   891,   894,   894,
     899,   902,   905,   908,   911,   914,   917,   920,   923,   926,
     929,   932,   935,   938,   941,   944,   947,   948,   949,   950,
     951,   954,   957,   960,   963,   966,   969,   972,   975,   984,
     993,   996,   997,  1001,  1002,  1002,  1006,  1006,  1013,  1014,
    1015,  1016,  1020,  1020
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
  "UNTIL", "FOR", "STEP", "EVERY", "MID", "INSTR", "UPPER", "LOWER",
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
     395,   396,   397,   398,   399,   400,   401,   402,   403
};
#endif

#define YYPACT_NINF (-196)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-229)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -196,    14,   512,  -196,  -196,   -21,  -196,     8,   916,     7,
     -16,   916,  -196,    -1,    69,  1019,  -110,  -109,  -196,  -196,
    -196,    23,    39,    -3,  1019,   -36,   -24,  -196,    38,    49,
    1019,  -196,  -196,    80,    91,   -28,  -196,  -196,    52,  -196,
     -64,  -196,  1019,   -25,   813,   102,    44,  -196,   138,   152,
     157,  -196,   916,   140,  -196,  -196,  -196,   916,   916,   916,
    -196,  -196,  -196,   697,  -196,  -196,   131,   134,   135,    18,
      21,   137,   142,  1019,  -196,  -196,   143,   144,   145,   146,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,    53,  -196,  -196,
      30,  -108,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,    54,   153,  -196,  -196,    16,  -196,    58,  -196,    26,
    -196,  -196,  -196,   -17,    99,   -15,   -14,   -13,   -12,   161,
    -196,  -196,  -196,   194,   231,  -196,  -196,  -196,   916,  -196,
    -196,   158,  -196,  -196,  -196,  -196,  -196,   916,   147,   148,
    -196,  -196,  -196,   -47,  -196,     3,  -196,  -196,  -196,  -196,
    -196,  1019,  -196,  -196,  -196,  -196,   916,  -196,  -196,  -196,
     916,   159,  -196,  -196,  -196,   120,  -196,  -196,  1019,  1019,
    -196,   916,  -196,  -196,  -196,   162,  -196,  -196,  -196,  -196,
    -196,  -196,  1019,  1019,  -196,  -196,  -196,   177,  -196,  -196,
      74,  -196,  1019,  -196,  1019,   181,   613,  -196,   512,   512,
     169,   170,   916,  -196,  -196,   128,   130,   132,   136,   168,
     174,   175,   178,   185,   186,   916,   916,   916,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  1019,  1019,
    -196,  1019,  1019,  1019,  1019,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    1019,  1019,  1019,  1019,  1019,  1019,  1019,  1019,  1019,  1019,
    1019,  -196,  -196,  -196,   916,   198,  -196,  -196,  -196,   176,
      99,   199,    99,   201,    99,   203,    99,   204,    99,  -196,
      99,   196,  -196,  -196,   -31,    68,    45,    46,  -196,  -196,
    -196,   200,  1019,   202,  -196,  -196,    72,    86,    62,    63,
    -196,  -196,   206,  -196,  -196,   916,  -196,  -196,   916,   916,
    -196,  -196,   191,    89,  -196,  -196,  -196,  -196,  -196,   916,
    -196,   229,   230,  -196,  -196,   916,   172,   234,  1019,   141,
     236,  -196,  1019,  -196,   613,  -196,  -196,   105,   106,  -196,
    -196,    99,  1019,    99,  1019,   100,   108,   109,   112,   113,
    -196,   237,   238,   239,   240,   242,   243,   256,   257,   258,
     261,   244,   245,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,   252,   254,   916,    20,  -196,    99,
    -196,    99,  -196,    99,  -196,    99,     2,  -196,    99,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,    99,  -196,  1019,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  1019,  -196,
    -196,  -196,  -196,  -196,  -196,   124,   139,   154,   270,   247,
     248,  1019,  1019,   283,   284,  -196,   -69,   221,   156,  1019,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  1019,
    1019,  1019,  1019,  -196,  -196,   164,   165,  -196,  -196,  -196,
    -196,  -196,  -196,   276,  -196,   285,  -196,   171,    32,  -196,
     305,  -196,   308,   309,  -196,   312,  -196,   307,   916,    99,
    1019,   288,   289,    99,  1019,  -196,  -196,  1019,  -196,     9,
     290,   291,    11,    22,  -196,  -196,   179,   180,  -196,   300,
    -196,   301,  -196,    99,  1019,   323,   325,  1019,  -196,  -196,
    -196,  -196,   322,   326,   302,   306,   227,  1019,   329,  -196,
    -196,  1019,  -196,  1019,  -196,  -196,  -196,   197,   205,   311,
     313,   124,   139,  -196,  1019,  1019,  -196,  -196,  1019,   315,
    1019,   316,   317,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,   330,  -196,  -196,  -196,  1019,  -196
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     302,     0,   292,     1,   291,     0,   282,     0,     0,   270,
       0,     0,   275,     0,     0,     0,   209,     0,   257,   261,
     258,     0,     0,     0,     0,     0,     0,   255,     0,     0,
       0,   251,   274,     0,     0,     0,   280,   281,   253,   256,
     263,   260,     0,     0,     0,     0,     0,   296,   293,   298,
     300,   303,     0,     0,   113,   114,   238,     0,     0,     0,
     127,   128,   240,     0,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,    66,    67,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,    23,    28,    29,    30,    31,    32,    33,    36,
      37,     0,    38,    41,    40,     0,    47,    69,    81,     0,
     138,   139,   241,     0,     0,     0,     0,     0,     0,     0,
     107,   108,   237,     0,     0,   170,   171,   242,     0,   173,
     174,   175,   179,   180,   243,   199,   200,     0,     0,     0,
     207,   208,   248,     0,   276,     0,   219,   250,   215,   216,
     277,     0,   185,   186,   187,   245,     0,   190,   191,   246,
       0,   193,   197,   198,   247,     0,   272,   273,     0,     0,
     290,     0,   183,   184,   244,     0,   222,   223,   249,   217,
     218,   278,     0,     0,   265,   266,   262,     0,   235,   236,
       0,   279,     0,   287,     0,     0,   292,   294,   292,   292,
       0,     0,     0,   121,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     3,
       4,     6,     8,     9,     5,    10,    64,     2,     0,     0,
      68,     0,     0,     0,     0,    34,    21,    24,    25,    26,
      27,    22,    35,    39,   129,   132,   130,   131,   133,   134,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,   136,   137,     0,     0,   119,   120,   239,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
       0,     0,   145,   146,     0,     0,     0,     0,   142,   141,
      82,     0,     0,     0,   160,   161,     0,     0,     0,     0,
     157,   156,     0,   172,   177,     0,   201,   204,     0,     0,
     230,   232,     0,     0,   259,   188,   189,   192,   195,     0,
     252,     0,     0,   181,   182,     0,     0,   264,     0,     0,
       0,   288,     0,   297,   292,   299,   301,     0,     0,   109,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    71,    75,    77,    78,    79,    80,
      76,    72,    73,    74,     0,     0,     0,     0,    89,     0,
     101,     0,    93,     0,    97,     0,    85,   143,     0,   150,
     149,   154,   153,   148,   152,   147,   151,     0,   158,     0,
     165,   164,   169,   168,   163,   167,   162,   166,     0,   176,
     178,   202,   205,   203,   206,     0,     0,     0,   210,     0,
       0,     0,     0,     0,     0,   254,     0,     0,     0,     0,
     289,   295,   110,   112,   123,   126,   122,   125,    46,    42,
      43,    45,    44,    48,    49,    52,    53,    54,    55,     0,
       0,     0,     0,    62,    63,     0,     0,   115,   117,    86,
      99,    91,    94,    88,   100,    92,    96,     0,     0,   140,
       0,   155,     0,   224,   231,   227,   233,   211,     0,     0,
       0,     0,     0,     0,     0,   267,   268,     0,   234,     0,
       0,     0,     0,     0,   116,   118,     0,     0,   102,    87,
      98,    90,    95,     0,     0,     0,     0,     0,   212,   213,
     194,   196,     0,     0,     0,     0,   269,     0,     0,    56,
      57,     0,    58,     0,    60,   104,   106,     0,     0,     0,
       0,     0,     0,   214,     0,     0,   220,   221,     0,     0,
       0,     0,     0,   103,   105,   144,   159,   226,   229,   283,
     284,   271,     0,   285,    59,    61,     0,   286
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,    29,  -196,  -196,  -196,   -18,   123,   -11,   222,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,   246,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -178,  -196,  -176,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -195,  -196,  -196,  -196,   -46,  -196,  -196
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   105,   225,   226,   106,   107,   108,   109,   291,   120,
     121,   122,    54,    55,    56,   266,   267,   268,    60,    61,
      62,   249,   110,   111,   112,   125,   126,   127,   132,   133,
     134,   172,   173,   174,   154,   155,   157,   158,   159,   162,
     163,   164,   140,   141,   142,   146,   150,   181,   147,   176,
     177,   178,   474,   505,   476,   506,   144,   415,   416,   191,
      48,   151,    49,   334,    50,   196,    51,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     124,   333,    52,   183,   143,   310,   264,   114,   270,   272,
     274,   276,    70,   165,     3,   115,   517,    70,   521,   170,
     160,   240,   128,   312,   389,   390,   190,   241,   113,   523,
     467,   186,   116,    57,   129,   130,   145,   148,    58,   149,
     123,   201,   218,   518,   313,   522,   204,   206,   208,   468,
     193,   459,   214,   166,   311,   230,   524,   194,   152,   153,
     117,   118,   156,   499,   195,   167,   250,   251,   460,   185,
     252,   168,   253,   254,   255,   256,   257,   258,    59,   485,
     500,   200,   169,   161,   184,   131,   203,   205,   207,   393,
     395,   219,   220,   221,   244,   245,   461,   462,   394,   396,
     222,   223,   224,   171,   244,   261,   404,   406,   501,   502,
     135,   136,   137,   138,   175,   405,   407,   304,   179,   182,
     180,   187,   139,   391,   392,    53,   307,   400,   401,   265,
     119,   271,   273,   275,   277,   192,   246,   247,   248,   431,
     314,   402,   403,   269,   197,   316,   246,   247,   262,   318,
     321,   322,   335,   336,   259,   236,   198,   303,   237,   238,
     324,   199,   260,   202,   215,   239,   306,   216,   217,   227,
     228,   326,   327,   243,   330,   229,   231,   232,   233,   234,
      70,   235,   242,   331,   278,   315,   305,   319,   320,   317,
     328,   340,   308,   309,   332,   325,   329,   337,   338,   341,
     323,   342,   345,   343,   352,   354,   356,   344,   346,   347,
     357,   358,   348,   359,   360,   361,   362,   279,   280,   349,
     350,   376,   379,   377,   381,   281,   383,   385,   388,   282,
     283,   339,   417,   397,   399,   418,   421,   422,   284,   408,
     425,   426,   428,   429,   351,   353,   355,   285,   438,   286,
     287,   432,   433,   375,   279,   292,   439,   440,   288,   289,
     441,   442,   293,   449,   450,   451,   294,   295,   452,   290,
     473,   443,   444,   445,   446,   296,   447,   448,   453,   454,
     455,   398,   456,   478,   297,   475,   298,   299,   479,   480,
     483,   484,   487,   374,   410,   300,   301,   412,   414,   378,
     477,   380,   488,   382,   496,   384,   290,   386,   420,   387,
     494,   495,   503,   497,   424,   504,  -225,   427,   498,  -228,
     507,   430,   512,   513,   519,   520,   525,   526,   527,   528,
     531,   435,   532,   437,   409,   534,   536,   411,   413,   535,
     537,   538,   540,   556,   543,   545,   302,   546,   419,   552,
     554,   555,   544,   547,   423,   263,   548,     0,     0,     0,
       0,     0,     0,     0,     0,   458,     0,     0,     0,     0,
     434,     0,   436,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,     0,     0,     0,     0,   471,     0,
       0,     0,     0,     0,     0,     0,     0,   472,     0,     0,
       0,     0,     0,   481,   482,   457,     0,     0,   463,     0,
     464,   489,   465,     0,   466,     0,     0,   469,     0,     0,
       0,     0,     0,     0,     0,     0,   470,     0,     0,     0,
       0,   490,   491,   492,   493,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   486,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   509,     0,   511,
       0,     0,     0,   515,     0,     0,   516,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   530,     0,     0,   533,     0,     0,   539,
       0,     0,     0,   541,     0,   542,     0,   508,   510,     0,
       0,     0,   514,     0,     0,     4,     0,     0,     0,     0,
       0,     0,     0,   549,   550,     0,     0,   551,     0,   553,
       0,     0,   529,     5,     6,     0,     7,     0,     8,     9,
       0,    10,    11,     0,     0,   557,     0,     0,     0,    12,
       0,    13,    14,    15,     0,     0,     0,     0,    16,     0,
       0,     0,     0,     0,    17,     0,     0,     0,     0,    18,
      19,    20,    21,    22,    23,     0,     0,     0,     0,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,     0,    27,     0,     0,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,     4,    38,     0,     0,
       0,    39,    40,    41,    42,    43,     0,    44,    45,     0,
       0,     0,     0,     0,     5,     6,     0,     7,     0,     8,
       9,     0,    10,    11,     0,     0,     0,     0,     0,     0,
      12,     0,    13,    14,    15,     0,     0,     0,    46,    16,
      47,     0,     0,     0,     0,    17,     0,     0,     0,     0,
      18,    19,    20,    21,    22,    23,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,     0,    27,     0,     0,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,     0,    38,     0,
       0,   209,    39,    40,    41,    42,    43,     0,    44,    45,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,    67,     0,     0,    68,     0,     0,    69,
     210,   211,   212,     0,     0,     0,     0,     0,     0,     0,
       0,   213,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,    75,     0,     0,     0,     0,
       0,     0,     0,    76,    77,    78,    79,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,     0,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    63,     0,     0,     0,
       0,     0,     0,     0,   188,   189,     0,     0,     0,     0,
       0,     0,    64,    65,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,     0,    68,     0,     0,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    75,     0,     0,     0,     0,     0,     0,     0,    76,
      77,    78,    79,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    63,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,     0,    64,    65,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,     0,     0,    68,     0,     0,    69,     0,
       0,     0,     0,     0,     0,     0,     0,    70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    71,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    73,    74,    75,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    78,    79,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    63,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,     0,    64,    65,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,     0,     0,    68,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,    75,     0,     0,
       0,     0,     0,     0,     0,    76,    77,    78,    79,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     0,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104
};

static const yytype_int16 yycheck[] =
{
      11,   196,    23,    67,    15,    52,    23,    23,    23,    23,
      23,    23,    81,    24,     0,    31,     7,    81,     7,    30,
      23,   129,    23,    20,    55,    56,    44,   135,    21,     7,
      28,    42,    48,    25,    35,    36,   146,   146,    30,   148,
      11,    52,    24,    34,    41,    34,    57,    58,    59,    47,
       6,    31,    63,    89,   101,    73,    34,    13,    35,    36,
      76,    77,    23,    31,    20,    89,     8,     9,    48,    40,
      12,    33,    14,    15,    16,    17,    18,    19,    70,   148,
      48,    52,    33,    86,   148,    86,    57,    58,    59,    44,
      44,    73,    74,    75,    78,    79,    76,    77,    53,    53,
      82,    83,    84,    23,    78,    79,    44,    44,    76,    77,
      41,    42,    43,    44,    23,    53,    53,   128,   146,    67,
     148,   146,    53,    55,    56,   146,   137,    55,    56,   146,
     146,   146,   146,   146,   146,    33,   120,   121,   122,   334,
     151,    55,    56,   114,     6,   156,   120,   121,   122,   160,
     168,   169,   198,   199,    96,   125,     4,   128,   128,   129,
     171,     4,   104,    23,    33,   135,   137,    33,    33,   148,
      33,   182,   183,    20,   192,    33,    33,    33,    33,    33,
      81,   128,   128,   194,    23,   156,    28,    28,    68,   160,
      13,   202,    45,    45,    13,    33,   122,    28,    28,    71,
     171,    71,    34,    71,   215,   216,   217,    71,    34,    34,
     228,   229,    34,   231,   232,   233,   234,    23,    24,    34,
      34,    23,    23,    47,    23,    31,    23,    23,    32,    35,
      36,   202,    41,    33,    32,   146,     7,     7,    44,    33,
      68,     7,   101,     7,   215,   216,   217,    53,   148,    55,
      56,   146,   146,   264,    23,    24,   148,   148,    64,    65,
     148,   148,    31,     7,     7,     7,    35,    36,     7,    75,
     146,    34,    34,    34,    34,    44,    34,    34,    34,    34,
      28,   292,    28,    13,    53,   146,    55,    56,    41,    41,
       7,     7,    71,   264,   305,    64,    65,   308,   309,   270,
     146,   272,   146,   274,    28,   276,    75,   278,   319,   280,
     146,   146,     7,    28,   325,     7,     7,   328,   147,     7,
      13,   332,    34,    34,    34,    34,   147,   147,    28,    28,
       7,   342,     7,   344,   305,    13,    34,   308,   309,    13,
      34,   114,    13,    13,   147,    34,   124,    34,   319,    34,
      34,    34,   147,   531,   325,   109,   532,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   376,    -1,    -1,    -1,    -1,
     341,    -1,   343,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   399,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,    -1,    -1,
      -1,    -1,    -1,   421,   422,   376,    -1,    -1,   379,    -1,
     381,   429,   383,    -1,   385,    -1,    -1,   388,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   397,    -1,    -1,    -1,
      -1,   449,   450,   451,   452,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   426,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   478,    -1,   480,
      -1,    -1,    -1,   484,    -1,    -1,   487,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   504,    -1,    -1,   507,    -1,    -1,   517,
      -1,    -1,    -1,   521,    -1,   523,    -1,   478,   479,    -1,
      -1,    -1,   483,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   534,   535,    -1,    -1,   538,    -1,   540,
      -1,    -1,   503,    21,    22,    -1,    24,    -1,    26,    27,
      -1,    29,    30,    -1,    -1,   556,    -1,    -1,    -1,    37,
      -1,    39,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    -1,    90,    -1,    -1,    93,    94,    95,    -1,    97,
      98,    99,   100,   101,   102,   103,     3,   105,    -1,    -1,
      -1,   109,   110,   111,   112,   113,    -1,   115,   116,    -1,
      -1,    -1,    -1,    -1,    21,    22,    -1,    24,    -1,    26,
      27,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    39,    40,    41,    -1,    -1,    -1,   146,    46,
     148,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    -1,    90,    -1,    -1,    93,    94,    95,    -1,
      97,    98,    99,   100,   101,   102,   103,    -1,   105,    -1,
      -1,    24,   109,   110,   111,   112,   113,    -1,   115,   116,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,
      -1,    -1,    -1,    66,    -1,    -1,    69,    -1,    -1,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,   118,   119,    -1,    -1,    -1,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    -1,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    69,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,
     107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,    33,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    49,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    69,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,    -1,    -1,    -1,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    33,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    69,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,    -1,
      -1,    -1,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,    -1,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   216,   217,     0,     3,    21,    22,    24,    26,    27,
      29,    30,    37,    39,    40,    41,    46,    52,    57,    58,
      59,    60,    61,    62,    67,    87,    88,    90,    93,    94,
      95,    97,    98,    99,   100,   101,   102,   103,   105,   109,
     110,   111,   112,   113,   115,   116,   146,   148,   209,   211,
     213,   215,    23,   146,   161,   162,   163,    25,    30,    70,
     167,   168,   169,    33,    49,    50,    51,    66,    69,    72,
      81,    93,    94,   106,   107,   108,   116,   117,   118,   119,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   150,   153,   154,   155,   156,
     171,   172,   173,    21,    23,    31,    48,    76,    77,   146,
     158,   159,   160,   150,   156,   174,   175,   176,    23,    35,
      36,    86,   177,   178,   179,    41,    42,    43,    44,    53,
     191,   192,   193,   156,   205,   146,   194,   197,   146,   148,
     195,   210,    35,    36,   183,   184,    23,   185,   186,   187,
      23,    86,   188,   189,   190,   156,    89,    89,    33,    33,
     156,    23,   180,   181,   182,    23,   198,   199,   200,   146,
     148,   196,    67,    67,   148,   150,   156,   146,    41,    42,
     154,   208,    33,     6,    13,    20,   214,     6,     4,     4,
     150,   156,    23,   150,   156,   150,   156,   150,   156,    24,
      73,    74,    75,    84,   156,    33,    33,    33,    24,    73,
      74,    75,    82,    83,    84,   151,   152,   148,    33,    33,
     154,    33,    33,    33,    33,   128,   125,   128,   129,   135,
     129,   135,   128,    20,    78,    79,   120,   121,   122,   170,
       8,     9,    12,    14,    15,    16,    17,    18,    19,    96,
     104,    79,   122,   170,    23,   146,   164,   165,   166,   150,
      23,   146,    23,   146,    23,   146,    23,   146,    23,    23,
      24,    31,    35,    36,    44,    53,    55,    56,    64,    65,
      75,   157,    24,    31,    35,    36,    44,    53,    55,    56,
      64,    65,   157,   150,   156,    28,   150,   156,    45,    45,
      52,   101,    20,    41,   156,   150,   156,   150,   156,    28,
      68,   154,   154,   150,   156,    33,   156,   156,    13,   122,
     154,   156,    13,   211,   212,   215,   215,    28,    28,   150,
     156,    71,    71,    71,    71,    34,    34,    34,    34,    34,
      34,   150,   156,   150,   156,   150,   156,   154,   154,   154,
     154,   154,   154,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   150,   156,    23,    47,   150,    23,
     150,    23,   150,    23,   150,    23,   150,   150,    32,    55,
      56,    55,    56,    44,    53,    44,    53,    33,   156,    32,
      55,    56,    55,    56,    44,    53,    44,    53,    33,   150,
     156,   150,   156,   150,   156,   206,   207,    41,   146,   150,
     156,     7,     7,   150,   156,    68,     7,   156,   101,     7,
     156,   211,   146,   146,   150,   156,   150,   156,   148,   148,
     148,   148,   148,    34,    34,    34,    34,    34,    34,     7,
       7,     7,     7,    34,    34,    28,    28,   150,   156,    31,
      48,    76,    77,   150,   150,   150,   150,    28,    47,   150,
     150,   156,   156,   146,   201,   146,   203,   146,    13,    41,
      41,   154,   154,     7,     7,   148,   150,    71,   146,   154,
     154,   154,   154,   154,   146,   146,    28,    28,   147,    31,
      48,    76,    77,     7,     7,   202,   204,    13,   150,   156,
     150,   156,    34,    34,   150,   156,   156,     7,    34,    34,
      34,     7,    34,     7,    34,   147,   147,    28,    28,   150,
     156,     7,     7,   156,    13,    13,    34,    34,   114,   154,
      13,   154,   154,   147,   147,    34,    34,   201,   203,   156,
     156,   156,    34,   156,    34,    34,    13,   156
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   149,   150,   151,   151,   151,   151,   151,   151,   151,
     152,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   156,   157,   157,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   159,   159,   159,   159,   159,   160,   160,   161,
     161,   162,   162,   163,   163,   164,   164,   165,   165,   166,
     166,   167,   167,   167,   168,   168,   168,   169,   169,   170,
     170,   170,   171,   171,   171,   172,   172,   172,   173,   173,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     176,   176,   177,   177,   177,   177,   177,   178,   178,   179,
     179,   180,   181,   182,   182,   183,   183,   184,   185,   186,
     187,   187,   188,   188,   188,   189,   189,   190,   190,   191,
     191,   191,   191,   191,   192,   192,   192,   193,   193,   194,
     194,   194,   194,   194,   194,   195,   195,   196,   196,   197,
     198,   199,   200,   200,   201,   202,   201,   203,   204,   203,
     206,   205,   207,   205,   208,   208,   208,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   210,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   211,   212,   211,   214,   213,   215,   215,
     215,   215,   217,   216
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
       6,     8,     4,     4,     2,     3,     1,     1,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     2,     3,     4,     5,     4,     3,
       5,     4,     4,     3,     4,     5,     4,     3,     5,     4,
       4,     3,     5,     7,     6,     7,     6,     1,     1,     3,
       4,     3,     4,     1,     1,     3,     4,     3,     4,     1,
       1,     2,     4,     4,     2,     4,     4,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     1,     1,
       4,     2,     2,     3,     7,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     2,     2,     3,     7,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     2,     1,     1,     1,     3,     2,     3,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     2,     1,     5,     2,     5,     1,     1,     1,
       1,     2,     3,     3,     2,     3,     3,     1,     1,     0,
       3,     4,     5,     5,     6,     1,     1,     1,     1,     1,
       6,     6,     1,     1,     1,     0,     4,     1,     0,     4,
       0,     4,     0,     4,     4,     1,     1,     2,     2,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     3,     1,     4,     1,     1,     1,     0,     3,
       1,     1,     2,     1,     3,     2,     2,     5,     5,     6,
       1,     8,     2,     2,     1,     1,     2,     2,     2,     2,
       1,     1,     1,     8,     8,     8,    10,     2,     3,     4,
       2,     1,     0,     1,     0,     4,     0,     3,     1,     3,
       1,     3,     0,     2
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
#line 2215 "src-generated/ugbc.tab.c"
    break;

  case 3: /* random_definition_simple: BYTE  */
#line 68 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2223 "src-generated/ugbc.tab.c"
    break;

  case 4: /* random_definition_simple: WORD  */
#line 71 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2231 "src-generated/ugbc.tab.c"
    break;

  case 5: /* random_definition_simple: DWORD  */
#line 74 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2239 "src-generated/ugbc.tab.c"
    break;

  case 6: /* random_definition_simple: POSITION  */
#line 77 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2247 "src-generated/ugbc.tab.c"
    break;

  case 7: /* random_definition_simple: COLOR  */
#line 80 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2255 "src-generated/ugbc.tab.c"
    break;

  case 8: /* random_definition_simple: WIDTH  */
#line 83 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2263 "src-generated/ugbc.tab.c"
    break;

  case 9: /* random_definition_simple: HEIGHT  */
#line 86 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2271 "src-generated/ugbc.tab.c"
    break;

  case 10: /* random_definition: random_definition_simple  */
#line 91 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2279 "src-generated/ugbc.tab.c"
    break;

  case 11: /* color_enumeration: BLACK  */
#line 96 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2288 "src-generated/ugbc.tab.c"
    break;

  case 12: /* color_enumeration: WHITE  */
#line 100 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2297 "src-generated/ugbc.tab.c"
    break;

  case 13: /* color_enumeration: RED  */
#line 104 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2306 "src-generated/ugbc.tab.c"
    break;

  case 14: /* color_enumeration: CYAN  */
#line 108 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2315 "src-generated/ugbc.tab.c"
    break;

  case 15: /* color_enumeration: VIOLET  */
#line 112 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2324 "src-generated/ugbc.tab.c"
    break;

  case 16: /* color_enumeration: GREEN  */
#line 116 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2333 "src-generated/ugbc.tab.c"
    break;

  case 17: /* color_enumeration: BLUE  */
#line 120 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2342 "src-generated/ugbc.tab.c"
    break;

  case 18: /* color_enumeration: YELLOW  */
#line 124 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2351 "src-generated/ugbc.tab.c"
    break;

  case 19: /* color_enumeration: ORANGE  */
#line 128 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2360 "src-generated/ugbc.tab.c"
    break;

  case 20: /* color_enumeration: BROWN  */
#line 132 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2369 "src-generated/ugbc.tab.c"
    break;

  case 21: /* color_enumeration: LIGHT RED  */
#line 136 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2378 "src-generated/ugbc.tab.c"
    break;

  case 22: /* color_enumeration: DARK GREY  */
#line 140 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2387 "src-generated/ugbc.tab.c"
    break;

  case 23: /* color_enumeration: GREY  */
#line 144 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2396 "src-generated/ugbc.tab.c"
    break;

  case 24: /* color_enumeration: LIGHT GREEN  */
#line 148 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2405 "src-generated/ugbc.tab.c"
    break;

  case 25: /* color_enumeration: LIGHT BLUE  */
#line 152 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2414 "src-generated/ugbc.tab.c"
    break;

  case 26: /* color_enumeration: LIGHT GREY  */
#line 156 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2423 "src-generated/ugbc.tab.c"
    break;

  case 27: /* color_enumeration: DARK BLUE  */
#line 160 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2432 "src-generated/ugbc.tab.c"
    break;

  case 28: /* color_enumeration: MAGENTA  */
#line 164 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2441 "src-generated/ugbc.tab.c"
    break;

  case 29: /* color_enumeration: PURPLE  */
#line 168 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2450 "src-generated/ugbc.tab.c"
    break;

  case 30: /* color_enumeration: LAVENDER  */
#line 172 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2459 "src-generated/ugbc.tab.c"
    break;

  case 31: /* color_enumeration: GOLD  */
#line 176 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2468 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: TURQUOISE  */
#line 180 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2477 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: TAN  */
#line 184 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2486 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: YELLOW GREEN  */
#line 188 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2495 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: OLIVE GREEN  */
#line 192 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2504 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: PINK  */
#line 196 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2513 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: PEACH  */
#line 200 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2522 "src-generated/ugbc.tab.c"
    break;

  case 38: /* expression: Identifier  */
#line 206 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2530 "src-generated/ugbc.tab.c"
    break;

  case 39: /* expression: Identifier DOLLAR  */
#line 209 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[-1].string);
      }
#line 2538 "src-generated/ugbc.tab.c"
    break;

  case 40: /* expression: Integer  */
#line 212 "src/ugbc.y"
              { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2547 "src-generated/ugbc.tab.c"
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
#line 2559 "src-generated/ugbc.tab.c"
    break;

  case 42: /* expression: OP BYTE CP Integer  */
#line 223 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2568 "src-generated/ugbc.tab.c"
    break;

  case 43: /* expression: OP WORD CP Integer  */
#line 227 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2577 "src-generated/ugbc.tab.c"
    break;

  case 44: /* expression: OP DWORD CP Integer  */
#line 231 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2586 "src-generated/ugbc.tab.c"
    break;

  case 45: /* expression: OP POSITION CP Integer  */
#line 235 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2595 "src-generated/ugbc.tab.c"
    break;

  case 46: /* expression: OP COLOR CP Integer  */
#line 239 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2604 "src-generated/ugbc.tab.c"
    break;

  case 47: /* expression: color_enumeration  */
#line 243 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2612 "src-generated/ugbc.tab.c"
    break;

  case 48: /* expression: PEEK OP direct_integer CP  */
#line 246 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2620 "src-generated/ugbc.tab.c"
    break;

  case 49: /* expression: PEEK OP expressions CP  */
#line 249 "src/ugbc.y"
                             {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 2628 "src-generated/ugbc.tab.c"
    break;

  case 50: /* expression: XPEN  */
#line 252 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 2636 "src-generated/ugbc.tab.c"
    break;

  case 51: /* expression: YPEN  */
#line 255 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 2644 "src-generated/ugbc.tab.c"
    break;

  case 52: /* expression: COLLISION OP direct_integer CP  */
#line 258 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2652 "src-generated/ugbc.tab.c"
    break;

  case 53: /* expression: COLLISION OP expressions CP  */
#line 261 "src/ugbc.y"
                                  {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2660 "src-generated/ugbc.tab.c"
    break;

  case 54: /* expression: HIT OP direct_integer CP  */
#line 264 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2668 "src-generated/ugbc.tab.c"
    break;

  case 55: /* expression: HIT OP expressions CP  */
#line 267 "src/ugbc.y"
                            {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2676 "src-generated/ugbc.tab.c"
    break;

  case 56: /* expression: LEFT OP expression COMMA expression CP  */
#line 270 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2684 "src-generated/ugbc.tab.c"
    break;

  case 57: /* expression: RIGHT OP expression COMMA expression CP  */
#line 273 "src/ugbc.y"
                                              {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2692 "src-generated/ugbc.tab.c"
    break;

  case 58: /* expression: MID OP expression COMMA expression CP  */
#line 276 "src/ugbc.y"
                                            {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 2700 "src-generated/ugbc.tab.c"
    break;

  case 59: /* expression: MID OP expression COMMA expression COMMA expression CP  */
#line 279 "src/ugbc.y"
                                                             {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2708 "src-generated/ugbc.tab.c"
    break;

  case 60: /* expression: INSTR OP expression COMMA expression CP  */
#line 282 "src/ugbc.y"
                                              {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 2716 "src-generated/ugbc.tab.c"
    break;

  case 61: /* expression: INSTR OP expression COMMA expression COMMA expression CP  */
#line 285 "src/ugbc.y"
                                                               {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2724 "src-generated/ugbc.tab.c"
    break;

  case 62: /* expression: UPPER OP expression CP  */
#line 288 "src/ugbc.y"
                             {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 2732 "src-generated/ugbc.tab.c"
    break;

  case 63: /* expression: LOWER OP expression CP  */
#line 291 "src/ugbc.y"
                             {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 2740 "src-generated/ugbc.tab.c"
    break;

  case 64: /* expression: RANDOM random_definition  */
#line 294 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 2748 "src-generated/ugbc.tab.c"
    break;

  case 65: /* expression: OP expressions CP  */
#line 297 "src/ugbc.y"
                        {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 2756 "src-generated/ugbc.tab.c"
    break;

  case 66: /* expression: TRUE  */
#line 300 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 2765 "src-generated/ugbc.tab.c"
    break;

  case 67: /* expression: FALSE  */
#line 304 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 2774 "src-generated/ugbc.tab.c"
    break;

  case 68: /* expression: NOT expression  */
#line 308 "src/ugbc.y"
                     {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2782 "src-generated/ugbc.tab.c"
    break;

  case 69: /* expressions_raw: expression  */
#line 314 "src/ugbc.y"
                 { (yyval.string) = (yyvsp[0].string); }
#line 2788 "src-generated/ugbc.tab.c"
    break;

  case 70: /* expressions_raw: expression PLUS expressions_raw  */
#line 315 "src/ugbc.y"
                                      {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2796 "src-generated/ugbc.tab.c"
    break;

  case 71: /* expressions_raw: expression MINUS expressions_raw  */
#line 318 "src/ugbc.y"
                                       {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2805 "src-generated/ugbc.tab.c"
    break;

  case 72: /* expressions_raw: expression MULTIPLICATION expressions_raw  */
#line 322 "src/ugbc.y"
                                                {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2814 "src-generated/ugbc.tab.c"
    break;

  case 73: /* expressions_raw: expression AND expressions_raw  */
#line 326 "src/ugbc.y"
                                     {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2823 "src-generated/ugbc.tab.c"
    break;

  case 74: /* expressions_raw: expression OR expressions_raw  */
#line 330 "src/ugbc.y"
                                    {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2832 "src-generated/ugbc.tab.c"
    break;

  case 75: /* expressions_raw: expression EQUAL expressions_raw  */
#line 334 "src/ugbc.y"
                                       {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2840 "src-generated/ugbc.tab.c"
    break;

  case 76: /* expressions_raw: expression DISEQUAL expressions_raw  */
#line 337 "src/ugbc.y"
                                          {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2848 "src-generated/ugbc.tab.c"
    break;

  case 77: /* expressions_raw: expression LT expressions_raw  */
#line 340 "src/ugbc.y"
                                    {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2856 "src-generated/ugbc.tab.c"
    break;

  case 78: /* expressions_raw: expression LTE expressions_raw  */
#line 343 "src/ugbc.y"
                                     {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2864 "src-generated/ugbc.tab.c"
    break;

  case 79: /* expressions_raw: expression GT expressions_raw  */
#line 346 "src/ugbc.y"
                                    {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2872 "src-generated/ugbc.tab.c"
    break;

  case 80: /* expressions_raw: expression GTE expressions_raw  */
#line 349 "src/ugbc.y"
                                     {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2880 "src-generated/ugbc.tab.c"
    break;

  case 81: /* expressions: expressions_raw  */
#line 355 "src/ugbc.y"
                    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2888 "src-generated/ugbc.tab.c"
    break;

  case 84: /* bank_definition_simple: AT direct_integer  */
#line 362 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2896 "src-generated/ugbc.tab.c"
    break;

  case 85: /* bank_definition_simple: Identifier AT direct_integer  */
#line 365 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2904 "src-generated/ugbc.tab.c"
    break;

  case 86: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 368 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2912 "src-generated/ugbc.tab.c"
    break;

  case 87: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 371 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2920 "src-generated/ugbc.tab.c"
    break;

  case 88: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 374 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2928 "src-generated/ugbc.tab.c"
    break;

  case 89: /* bank_definition_simple: DATA AT direct_integer  */
#line 377 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2936 "src-generated/ugbc.tab.c"
    break;

  case 90: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 381 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2944 "src-generated/ugbc.tab.c"
    break;

  case 91: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 384 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2952 "src-generated/ugbc.tab.c"
    break;

  case 92: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 387 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2960 "src-generated/ugbc.tab.c"
    break;

  case 93: /* bank_definition_simple: CODE AT direct_integer  */
#line 390 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2968 "src-generated/ugbc.tab.c"
    break;

  case 94: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 394 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2976 "src-generated/ugbc.tab.c"
    break;

  case 95: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 397 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2984 "src-generated/ugbc.tab.c"
    break;

  case 96: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 400 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 2992 "src-generated/ugbc.tab.c"
    break;

  case 97: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 403 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 3000 "src-generated/ugbc.tab.c"
    break;

  case 98: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 407 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3008 "src-generated/ugbc.tab.c"
    break;

  case 99: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 410 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 3016 "src-generated/ugbc.tab.c"
    break;

  case 100: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 413 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3024 "src-generated/ugbc.tab.c"
    break;

  case 101: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 416 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3032 "src-generated/ugbc.tab.c"
    break;

  case 102: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 422 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3040 "src-generated/ugbc.tab.c"
    break;

  case 103: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 425 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3048 "src-generated/ugbc.tab.c"
    break;

  case 104: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 428 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3056 "src-generated/ugbc.tab.c"
    break;

  case 105: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 431 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3064 "src-generated/ugbc.tab.c"
    break;

  case 106: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 434 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3072 "src-generated/ugbc.tab.c"
    break;

  case 109: /* raster_definition_simple: Identifier AT direct_integer  */
#line 443 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3080 "src-generated/ugbc.tab.c"
    break;

  case 110: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 446 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3088 "src-generated/ugbc.tab.c"
    break;

  case 111: /* raster_definition_expression: Identifier AT expressions  */
#line 451 "src/ugbc.y"
                              {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3096 "src-generated/ugbc.tab.c"
    break;

  case 112: /* raster_definition_expression: AT expressions WITH Identifier  */
#line 454 "src/ugbc.y"
                                   {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3104 "src-generated/ugbc.tab.c"
    break;

  case 115: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 463 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3112 "src-generated/ugbc.tab.c"
    break;

  case 116: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 466 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3120 "src-generated/ugbc.tab.c"
    break;

  case 117: /* next_raster_definition_expression: Identifier AT expressions  */
#line 471 "src/ugbc.y"
                              {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3128 "src-generated/ugbc.tab.c"
    break;

  case 118: /* next_raster_definition_expression: AT expressions WITH Identifier  */
#line 474 "src/ugbc.y"
                                   {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3136 "src-generated/ugbc.tab.c"
    break;

  case 121: /* color_definition_simple: BORDER direct_integer  */
#line 483 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3144 "src-generated/ugbc.tab.c"
    break;

  case 122: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 486 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3152 "src-generated/ugbc.tab.c"
    break;

  case 123: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 489 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3160 "src-generated/ugbc.tab.c"
    break;

  case 124: /* color_definition_expression: BORDER expressions  */
#line 494 "src/ugbc.y"
                       {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3168 "src-generated/ugbc.tab.c"
    break;

  case 125: /* color_definition_expression: BACKGROUND expressions TO expressions  */
#line 497 "src/ugbc.y"
                                          {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3176 "src-generated/ugbc.tab.c"
    break;

  case 126: /* color_definition_expression: SPRITE expressions TO expressions  */
#line 500 "src/ugbc.y"
                                      {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3184 "src-generated/ugbc.tab.c"
    break;

  case 132: /* wait_definition_simple: direct_integer CYCLES  */
#line 514 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3192 "src-generated/ugbc.tab.c"
    break;

  case 133: /* wait_definition_simple: direct_integer TICKS  */
#line 517 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3200 "src-generated/ugbc.tab.c"
    break;

  case 134: /* wait_definition_simple: direct_integer milliseconds  */
#line 520 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3208 "src-generated/ugbc.tab.c"
    break;

  case 135: /* wait_definition_expression: expressions CYCLES  */
#line 525 "src/ugbc.y"
                         {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3216 "src-generated/ugbc.tab.c"
    break;

  case 136: /* wait_definition_expression: expressions TICKS  */
#line 528 "src/ugbc.y"
                        {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3224 "src-generated/ugbc.tab.c"
    break;

  case 137: /* wait_definition_expression: expressions milliseconds  */
#line 531 "src/ugbc.y"
                               {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3232 "src-generated/ugbc.tab.c"
    break;

  case 140: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 541 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3240 "src-generated/ugbc.tab.c"
    break;

  case 141: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 544 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3248 "src-generated/ugbc.tab.c"
    break;

  case 142: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 547 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3256 "src-generated/ugbc.tab.c"
    break;

  case 143: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 550 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3264 "src-generated/ugbc.tab.c"
    break;

  case 144: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 553 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3272 "src-generated/ugbc.tab.c"
    break;

  case 145: /* sprite_definition_simple: direct_integer ENABLE  */
#line 556 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3280 "src-generated/ugbc.tab.c"
    break;

  case 146: /* sprite_definition_simple: direct_integer DISABLE  */
#line 559 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3288 "src-generated/ugbc.tab.c"
    break;

  case 147: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 562 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3296 "src-generated/ugbc.tab.c"
    break;

  case 148: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 565 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3304 "src-generated/ugbc.tab.c"
    break;

  case 149: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 568 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3312 "src-generated/ugbc.tab.c"
    break;

  case 150: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 571 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3320 "src-generated/ugbc.tab.c"
    break;

  case 151: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 574 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3328 "src-generated/ugbc.tab.c"
    break;

  case 152: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 577 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3336 "src-generated/ugbc.tab.c"
    break;

  case 153: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 580 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3344 "src-generated/ugbc.tab.c"
    break;

  case 154: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 583 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3352 "src-generated/ugbc.tab.c"
    break;

  case 155: /* sprite_definition_expression: expressions DATA FROM expressions  */
#line 588 "src/ugbc.y"
                                      {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3360 "src-generated/ugbc.tab.c"
    break;

  case 156: /* sprite_definition_expression: expressions MULTICOLOR  */
#line 591 "src/ugbc.y"
                           {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3368 "src-generated/ugbc.tab.c"
    break;

  case 157: /* sprite_definition_expression: expressions MONOCOLOR  */
#line 594 "src/ugbc.y"
                          {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3376 "src-generated/ugbc.tab.c"
    break;

  case 158: /* sprite_definition_expression: expressions COLOR expressions  */
#line 597 "src/ugbc.y"
                                  {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3384 "src-generated/ugbc.tab.c"
    break;

  case 159: /* sprite_definition_expression: expressions position OP expressions COMMA expressions CP  */
#line 600 "src/ugbc.y"
                                                             {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3392 "src-generated/ugbc.tab.c"
    break;

  case 160: /* sprite_definition_expression: expressions ENABLE  */
#line 603 "src/ugbc.y"
                       {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3400 "src-generated/ugbc.tab.c"
    break;

  case 161: /* sprite_definition_expression: expressions DISABLE  */
#line 606 "src/ugbc.y"
                        {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3408 "src-generated/ugbc.tab.c"
    break;

  case 162: /* sprite_definition_expression: expressions EXPAND VERTICAL  */
#line 609 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3416 "src-generated/ugbc.tab.c"
    break;

  case 163: /* sprite_definition_expression: expressions COMPRESS VERTICAL  */
#line 612 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3424 "src-generated/ugbc.tab.c"
    break;

  case 164: /* sprite_definition_expression: expressions VERTICAL EXPAND  */
#line 615 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3432 "src-generated/ugbc.tab.c"
    break;

  case 165: /* sprite_definition_expression: expressions VERTICAL COMPRESS  */
#line 618 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3440 "src-generated/ugbc.tab.c"
    break;

  case 166: /* sprite_definition_expression: expressions EXPAND HORIZONTAL  */
#line 621 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3448 "src-generated/ugbc.tab.c"
    break;

  case 167: /* sprite_definition_expression: expressions COMPRESS HORIZONTAL  */
#line 624 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3456 "src-generated/ugbc.tab.c"
    break;

  case 168: /* sprite_definition_expression: expressions HORIZONTAL EXPAND  */
#line 627 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3464 "src-generated/ugbc.tab.c"
    break;

  case 169: /* sprite_definition_expression: expressions HORIZONTAL COMPRESS  */
#line 630 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3472 "src-generated/ugbc.tab.c"
    break;

  case 172: /* bitmap_definition_simple: AT direct_integer  */
#line 639 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3480 "src-generated/ugbc.tab.c"
    break;

  case 173: /* bitmap_definition_simple: ENABLE  */
#line 642 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3488 "src-generated/ugbc.tab.c"
    break;

  case 174: /* bitmap_definition_simple: DISABLE  */
#line 645 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 3496 "src-generated/ugbc.tab.c"
    break;

  case 175: /* bitmap_definition_simple: CLEAR  */
#line 648 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 3504 "src-generated/ugbc.tab.c"
    break;

  case 176: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 651 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 3512 "src-generated/ugbc.tab.c"
    break;

  case 177: /* bitmap_definition_expression: AT expressions  */
#line 657 "src/ugbc.y"
                   {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3520 "src-generated/ugbc.tab.c"
    break;

  case 178: /* bitmap_definition_expression: CLEAR WITH expressions  */
#line 660 "src/ugbc.y"
                           {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 3528 "src-generated/ugbc.tab.c"
    break;

  case 181: /* textmap_definition_simple: AT direct_integer  */
#line 670 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3536 "src-generated/ugbc.tab.c"
    break;

  case 182: /* textmap_definition_expression: AT expressions  */
#line 675 "src/ugbc.y"
                   {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3544 "src-generated/ugbc.tab.c"
    break;

  case 185: /* text_definition_simple: ENABLE  */
#line 684 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3552 "src-generated/ugbc.tab.c"
    break;

  case 186: /* text_definition_simple: DISABLE  */
#line 687 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 3560 "src-generated/ugbc.tab.c"
    break;

  case 188: /* tiles_definition_simple: AT direct_integer  */
#line 695 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 3568 "src-generated/ugbc.tab.c"
    break;

  case 189: /* tiles_definition_expression: AT expressions  */
#line 700 "src/ugbc.y"
                   {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 3576 "src-generated/ugbc.tab.c"
    break;

  case 192: /* colormap_definition_simple: AT direct_integer  */
#line 709 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 3584 "src-generated/ugbc.tab.c"
    break;

  case 193: /* colormap_definition_simple: CLEAR  */
#line 712 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 3592 "src-generated/ugbc.tab.c"
    break;

  case 194: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 715 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3600 "src-generated/ugbc.tab.c"
    break;

  case 195: /* colormap_definition_expression: AT expressions  */
#line 720 "src/ugbc.y"
                   {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3608 "src-generated/ugbc.tab.c"
    break;

  case 196: /* colormap_definition_expression: CLEAR WITH expressions ON expressions  */
#line 723 "src/ugbc.y"
                                          {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3616 "src-generated/ugbc.tab.c"
    break;

  case 199: /* screen_definition_simple: ON  */
#line 733 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 3624 "src-generated/ugbc.tab.c"
    break;

  case 200: /* screen_definition_simple: OFF  */
#line 736 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 3632 "src-generated/ugbc.tab.c"
    break;

  case 201: /* screen_definition_simple: ROWS direct_integer  */
#line 739 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 3640 "src-generated/ugbc.tab.c"
    break;

  case 202: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 742 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3648 "src-generated/ugbc.tab.c"
    break;

  case 203: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 745 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3656 "src-generated/ugbc.tab.c"
    break;

  case 204: /* screen_definition_expression: ROWS expressions  */
#line 750 "src/ugbc.y"
                     {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 3664 "src-generated/ugbc.tab.c"
    break;

  case 205: /* screen_definition_expression: VERTICAL SCROLL expressions  */
#line 753 "src/ugbc.y"
                                {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3672 "src-generated/ugbc.tab.c"
    break;

  case 206: /* screen_definition_expression: HORIZONTAL SCROLL expressions  */
#line 756 "src/ugbc.y"
                                  {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3680 "src-generated/ugbc.tab.c"
    break;

  case 210: /* var_definition_simple: Identifier ON Identifier  */
#line 765 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 3688 "src-generated/ugbc.tab.c"
    break;

  case 211: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 768 "src/ugbc.y"
                                    {
      variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 3696 "src-generated/ugbc.tab.c"
    break;

  case 212: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 771 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 3704 "src-generated/ugbc.tab.c"
    break;

  case 213: /* var_definition_simple: Identifier ON Identifier ASSIGN expressions  */
#line 774 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 3714 "src-generated/ugbc.tab.c"
    break;

  case 214: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expressions  */
#line 779 "src/ugbc.y"
                                                       {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 3724 "src-generated/ugbc.tab.c"
    break;

  case 215: /* goto_definition: Identifier  */
#line 786 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 3732 "src-generated/ugbc.tab.c"
    break;

  case 216: /* goto_definition: Integer  */
#line 789 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 3740 "src-generated/ugbc.tab.c"
    break;

  case 217: /* gosub_definition: Identifier  */
#line 795 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 3748 "src-generated/ugbc.tab.c"
    break;

  case 218: /* gosub_definition: Integer  */
#line 798 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 3756 "src-generated/ugbc.tab.c"
    break;

  case 220: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 807 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 3764 "src-generated/ugbc.tab.c"
    break;

  case 221: /* point_definition_expression: AT OP expressions COMMA expressions CP  */
#line 813 "src/ugbc.y"
                                             {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 3772 "src-generated/ugbc.tab.c"
    break;

  case 224: /* on_goto_definition: Identifier  */
#line 822 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 3781 "src-generated/ugbc.tab.c"
    break;

  case 225: /* $@1: %empty  */
#line 826 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 3789 "src-generated/ugbc.tab.c"
    break;

  case 227: /* on_gosub_definition: Identifier  */
#line 831 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 3798 "src-generated/ugbc.tab.c"
    break;

  case 228: /* $@2: %empty  */
#line 835 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 3806 "src-generated/ugbc.tab.c"
    break;

  case 230: /* $@3: %empty  */
#line 840 "src/ugbc.y"
                       {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 3814 "src-generated/ugbc.tab.c"
    break;

  case 232: /* $@4: %empty  */
#line 843 "src/ugbc.y"
                        {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 3822 "src-generated/ugbc.tab.c"
    break;

  case 234: /* every_definition: expression TICKS GOSUB Identifier  */
#line 848 "src/ugbc.y"
                                        {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 3830 "src-generated/ugbc.tab.c"
    break;

  case 235: /* every_definition: ON  */
#line 851 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 3838 "src-generated/ugbc.tab.c"
    break;

  case 236: /* every_definition: OFF  */
#line 854 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 3846 "src-generated/ugbc.tab.c"
    break;

  case 251: /* statement: RANDOMIZE  */
#line 873 "src/ugbc.y"
              {
      randomize( _environment );
  }
#line 3854 "src-generated/ugbc.tab.c"
    break;

  case 252: /* statement: IF expressions THEN  */
#line 876 "src/ugbc.y"
                        {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 3862 "src-generated/ugbc.tab.c"
    break;

  case 253: /* statement: ELSE  */
#line 879 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 3870 "src-generated/ugbc.tab.c"
    break;

  case 254: /* statement: ELSE IF expressions THEN  */
#line 882 "src/ugbc.y"
                             {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 3878 "src-generated/ugbc.tab.c"
    break;

  case 255: /* statement: ENDIF  */
#line 885 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 3886 "src-generated/ugbc.tab.c"
    break;

  case 256: /* statement: DO  */
#line 888 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 3894 "src-generated/ugbc.tab.c"
    break;

  case 257: /* statement: LOOP  */
#line 891 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 3902 "src-generated/ugbc.tab.c"
    break;

  case 258: /* $@5: %empty  */
#line 894 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 3910 "src-generated/ugbc.tab.c"
    break;

  case 259: /* statement: WHILE $@5 expressions  */
#line 896 "src/ugbc.y"
                {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 3918 "src-generated/ugbc.tab.c"
    break;

  case 260: /* statement: WEND  */
#line 899 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 3926 "src-generated/ugbc.tab.c"
    break;

  case 261: /* statement: REPEAT  */
#line 902 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 3934 "src-generated/ugbc.tab.c"
    break;

  case 262: /* statement: UNTIL expressions  */
#line 905 "src/ugbc.y"
                      {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 3942 "src-generated/ugbc.tab.c"
    break;

  case 263: /* statement: EXIT  */
#line 908 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 3950 "src-generated/ugbc.tab.c"
    break;

  case 264: /* statement: EXIT IF expressions  */
#line 911 "src/ugbc.y"
                        {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 3958 "src-generated/ugbc.tab.c"
    break;

  case 265: /* statement: EXIT Integer  */
#line 914 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 3966 "src-generated/ugbc.tab.c"
    break;

  case 266: /* statement: EXIT direct_integer  */
#line 917 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 3974 "src-generated/ugbc.tab.c"
    break;

  case 267: /* statement: EXIT IF expressions COMMA Integer  */
#line 920 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 3982 "src-generated/ugbc.tab.c"
    break;

  case 268: /* statement: EXIT IF expressions COMMA direct_integer  */
#line 923 "src/ugbc.y"
                                             {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 3990 "src-generated/ugbc.tab.c"
    break;

  case 269: /* statement: FOR Identifier ASSIGN expressions TO expressions  */
#line 926 "src/ugbc.y"
                                                     {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 3998 "src-generated/ugbc.tab.c"
    break;

  case 270: /* statement: NEXT  */
#line 929 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 4006 "src-generated/ugbc.tab.c"
    break;

  case 271: /* statement: FOR Identifier ASSIGN expressions TO expressions STEP expressions  */
#line 932 "src/ugbc.y"
                                                                      {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 4014 "src-generated/ugbc.tab.c"
    break;

  case 272: /* statement: BEG GAMELOOP  */
#line 935 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 4022 "src-generated/ugbc.tab.c"
    break;

  case 273: /* statement: END GAMELOOP  */
#line 938 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 4030 "src-generated/ugbc.tab.c"
    break;

  case 274: /* statement: GRAPHIC  */
#line 941 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 4038 "src-generated/ugbc.tab.c"
    break;

  case 275: /* statement: HALT  */
#line 944 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 4046 "src-generated/ugbc.tab.c"
    break;

  case 280: /* statement: RETURN  */
#line 951 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 4054 "src-generated/ugbc.tab.c"
    break;

  case 281: /* statement: POP  */
#line 954 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 4062 "src-generated/ugbc.tab.c"
    break;

  case 282: /* statement: DONE  */
#line 957 "src/ugbc.y"
          {
      return 0;
  }
#line 4070 "src-generated/ugbc.tab.c"
    break;

  case 283: /* statement: LEFT OP expression COMMA expression CP ASSIGN expressions  */
#line 960 "src/ugbc.y"
                                                              {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4078 "src-generated/ugbc.tab.c"
    break;

  case 284: /* statement: RIGHT OP expression COMMA expression CP ASSIGN expressions  */
#line 963 "src/ugbc.y"
                                                               {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4086 "src-generated/ugbc.tab.c"
    break;

  case 285: /* statement: MID OP expression COMMA expression CP ASSIGN expressions  */
#line 966 "src/ugbc.y"
                                                             {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 4094 "src-generated/ugbc.tab.c"
    break;

  case 286: /* statement: MID OP expression COMMA expression COMMA expression CP ASSIGN expressions  */
#line 969 "src/ugbc.y"
                                                                              {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4102 "src-generated/ugbc.tab.c"
    break;

  case 287: /* statement: Identifier COLON  */
#line 972 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 4110 "src-generated/ugbc.tab.c"
    break;

  case 288: /* statement: Identifier ASSIGN expressions  */
#line 975 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expressions = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expressions->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 4124 "src-generated/ugbc.tab.c"
    break;

  case 289: /* statement: Identifier DOLLAR ASSIGN expressions  */
#line 984 "src/ugbc.y"
                                         {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expressions = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 4138 "src-generated/ugbc.tab.c"
    break;

  case 290: /* statement: DEBUG expressions  */
#line 993 "src/ugbc.y"
                      {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 4146 "src-generated/ugbc.tab.c"
    break;

  case 293: /* statements_no_linenumbers: statement  */
#line 1001 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 4152 "src-generated/ugbc.tab.c"
    break;

  case 294: /* $@6: %empty  */
#line 1002 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 4158 "src-generated/ugbc.tab.c"
    break;

  case 296: /* $@7: %empty  */
#line 1006 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 4166 "src-generated/ugbc.tab.c"
    break;

  case 297: /* statements_with_linenumbers: Integer $@7 statements_no_linenumbers  */
#line 1008 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 4174 "src-generated/ugbc.tab.c"
    break;

  case 302: /* $@8: %empty  */
#line 1020 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 4180 "src-generated/ugbc.tab.c"
    break;


#line 4184 "src-generated/ugbc.tab.c"

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

#line 1022 "src/ugbc.y"


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

