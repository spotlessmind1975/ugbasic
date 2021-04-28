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
  YYSYMBOL_RASTER = 19,                    /* RASTER  */
  YYSYMBOL_DONE = 20,                      /* DONE  */
  YYSYMBOL_AT = 21,                        /* AT  */
  YYSYMBOL_COLOR = 22,                     /* COLOR  */
  YYSYMBOL_BORDER = 23,                    /* BORDER  */
  YYSYMBOL_WAIT = 24,                      /* WAIT  */
  YYSYMBOL_NEXT = 25,                      /* NEXT  */
  YYSYMBOL_WITH = 26,                      /* WITH  */
  YYSYMBOL_BANK = 27,                      /* BANK  */
  YYSYMBOL_SPRITE = 28,                    /* SPRITE  */
  YYSYMBOL_DATA = 29,                      /* DATA  */
  YYSYMBOL_FROM = 30,                      /* FROM  */
  YYSYMBOL_OP = 31,                        /* OP  */
  YYSYMBOL_CP = 32,                        /* CP  */
  YYSYMBOL_ENABLE = 33,                    /* ENABLE  */
  YYSYMBOL_DISABLE = 34,                   /* DISABLE  */
  YYSYMBOL_HALT = 35,                      /* HALT  */
  YYSYMBOL_ECM = 36,                       /* ECM  */
  YYSYMBOL_BITMAP = 37,                    /* BITMAP  */
  YYSYMBOL_SCREEN = 38,                    /* SCREEN  */
  YYSYMBOL_ON = 39,                        /* ON  */
  YYSYMBOL_OFF = 40,                       /* OFF  */
  YYSYMBOL_ROWS = 41,                      /* ROWS  */
  YYSYMBOL_VERTICAL = 42,                  /* VERTICAL  */
  YYSYMBOL_SCROLL = 43,                    /* SCROLL  */
  YYSYMBOL_VAR = 44,                       /* VAR  */
  YYSYMBOL_AS = 45,                        /* AS  */
  YYSYMBOL_TEMPORARY = 46,                 /* TEMPORARY  */
  YYSYMBOL_XPEN = 47,                      /* XPEN  */
  YYSYMBOL_YPEN = 48,                      /* YPEN  */
  YYSYMBOL_PEEK = 49,                      /* PEEK  */
  YYSYMBOL_GOTO = 50,                      /* GOTO  */
  YYSYMBOL_HORIZONTAL = 51,                /* HORIZONTAL  */
  YYSYMBOL_MCM = 52,                       /* MCM  */
  YYSYMBOL_COMPRESS = 53,                  /* COMPRESS  */
  YYSYMBOL_EXPAND = 54,                    /* EXPAND  */
  YYSYMBOL_LOOP = 55,                      /* LOOP  */
  YYSYMBOL_REPEAT = 56,                    /* REPEAT  */
  YYSYMBOL_WHILE = 57,                     /* WHILE  */
  YYSYMBOL_TEXT = 58,                      /* TEXT  */
  YYSYMBOL_TILES = 59,                     /* TILES  */
  YYSYMBOL_COLORMAP = 60,                  /* COLORMAP  */
  YYSYMBOL_SELECT = 61,                    /* SELECT  */
  YYSYMBOL_MONOCOLOR = 62,                 /* MONOCOLOR  */
  YYSYMBOL_MULTICOLOR = 63,                /* MULTICOLOR  */
  YYSYMBOL_COLLISION = 64,                 /* COLLISION  */
  YYSYMBOL_IF = 65,                        /* IF  */
  YYSYMBOL_THEN = 66,                      /* THEN  */
  YYSYMBOL_HIT = 67,                       /* HIT  */
  YYSYMBOL_BACKGROUND = 68,                /* BACKGROUND  */
  YYSYMBOL_TO = 69,                        /* TO  */
  YYSYMBOL_RANDOM = 70,                    /* RANDOM  */
  YYSYMBOL_BYTE = 71,                      /* BYTE  */
  YYSYMBOL_WORD = 72,                      /* WORD  */
  YYSYMBOL_POSITION = 73,                  /* POSITION  */
  YYSYMBOL_CODE = 74,                      /* CODE  */
  YYSYMBOL_VARIABLES = 75,                 /* VARIABLES  */
  YYSYMBOL_MS = 76,                        /* MS  */
  YYSYMBOL_CYCLES = 77,                    /* CYCLES  */
  YYSYMBOL_S = 78,                         /* S  */
  YYSYMBOL_HASH = 79,                      /* HASH  */
  YYSYMBOL_WIDTH = 80,                     /* WIDTH  */
  YYSYMBOL_HEIGHT = 81,                    /* HEIGHT  */
  YYSYMBOL_DWORD = 82,                     /* DWORD  */
  YYSYMBOL_PEN = 83,                       /* PEN  */
  YYSYMBOL_CLEAR = 84,                     /* CLEAR  */
  YYSYMBOL_BEG = 85,                       /* BEG  */
  YYSYMBOL_END = 86,                       /* END  */
  YYSYMBOL_GAMELOOP = 87,                  /* GAMELOOP  */
  YYSYMBOL_ENDIF = 88,                     /* ENDIF  */
  YYSYMBOL_UP = 89,                        /* UP  */
  YYSYMBOL_DOWN = 90,                      /* DOWN  */
  YYSYMBOL_LEFT = 91,                      /* LEFT  */
  YYSYMBOL_RIGHT = 92,                     /* RIGHT  */
  YYSYMBOL_DEBUG = 93,                     /* DEBUG  */
  YYSYMBOL_AND = 94,                       /* AND  */
  YYSYMBOL_RANDOMIZE = 95,                 /* RANDOMIZE  */
  YYSYMBOL_GRAPHIC = 96,                   /* GRAPHIC  */
  YYSYMBOL_TEXTMAP = 97,                   /* TEXTMAP  */
  YYSYMBOL_POINT = 98,                     /* POINT  */
  YYSYMBOL_GOSUB = 99,                     /* GOSUB  */
  YYSYMBOL_RETURN = 100,                   /* RETURN  */
  YYSYMBOL_POP = 101,                      /* POP  */
  YYSYMBOL_OR = 102,                       /* OR  */
  YYSYMBOL_ELSE = 103,                     /* ELSE  */
  YYSYMBOL_NOT = 104,                      /* NOT  */
  YYSYMBOL_TRUE = 105,                     /* TRUE  */
  YYSYMBOL_FALSE = 106,                    /* FALSE  */
  YYSYMBOL_DO = 107,                       /* DO  */
  YYSYMBOL_EXIT = 108,                     /* EXIT  */
  YYSYMBOL_WEND = 109,                     /* WEND  */
  YYSYMBOL_UNTIL = 110,                    /* UNTIL  */
  YYSYMBOL_FOR = 111,                      /* FOR  */
  YYSYMBOL_STEP = 112,                     /* STEP  */
  YYSYMBOL_EVERY = 113,                    /* EVERY  */
  YYSYMBOL_MILLISECOND = 114,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 115,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 116,                    /* TICKS  */
  YYSYMBOL_BLACK = 117,                    /* BLACK  */
  YYSYMBOL_WHITE = 118,                    /* WHITE  */
  YYSYMBOL_RED = 119,                      /* RED  */
  YYSYMBOL_CYAN = 120,                     /* CYAN  */
  YYSYMBOL_VIOLET = 121,                   /* VIOLET  */
  YYSYMBOL_GREEN = 122,                    /* GREEN  */
  YYSYMBOL_BLUE = 123,                     /* BLUE  */
  YYSYMBOL_YELLOW = 124,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 125,                   /* ORANGE  */
  YYSYMBOL_BROWN = 126,                    /* BROWN  */
  YYSYMBOL_LIGHT = 127,                    /* LIGHT  */
  YYSYMBOL_DARK = 128,                     /* DARK  */
  YYSYMBOL_GREY = 129,                     /* GREY  */
  YYSYMBOL_GRAY = 130,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 131,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 132,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 133,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 134,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 135,                /* TURQUOISE  */
  YYSYMBOL_TAN = 136,                      /* TAN  */
  YYSYMBOL_PINK = 137,                     /* PINK  */
  YYSYMBOL_PEACH = 138,                    /* PEACH  */
  YYSYMBOL_OLIVE = 139,                    /* OLIVE  */
  YYSYMBOL_Identifier = 140,               /* Identifier  */
  YYSYMBOL_String = 141,                   /* String  */
  YYSYMBOL_Integer = 142,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 143,                 /* $accept  */
  YYSYMBOL_direct_integer = 144,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 145, /* random_definition_simple  */
  YYSYMBOL_random_definition = 146,        /* random_definition  */
  YYSYMBOL_color_enumeration = 147,        /* color_enumeration  */
  YYSYMBOL_expression = 148,               /* expression  */
  YYSYMBOL_expressions_raw = 149,          /* expressions_raw  */
  YYSYMBOL_expressions = 150,              /* expressions  */
  YYSYMBOL_position = 151,                 /* position  */
  YYSYMBOL_bank_definition_simple = 152,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 153, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 154,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 155, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 156, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 157,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 158, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 159, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 160,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 161,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 162, /* color_definition_expression  */
  YYSYMBOL_color_definition = 163,         /* color_definition  */
  YYSYMBOL_milliseconds = 164,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 165,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 166, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 167,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 168, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 169, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 170,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 171, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 172, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 173,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 174, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 175, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 176,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 177,   /* text_definition_simple  */
  YYSYMBOL_text_definition = 178,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 179,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 180, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 181,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 182, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 183, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 184,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 185, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 186, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 187,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 188,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 189,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 190,         /* gosub_definition  */
  YYSYMBOL_var_definition = 191,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 192,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 193, /* point_definition_expression  */
  YYSYMBOL_point_definition = 194,         /* point_definition  */
  YYSYMBOL_on_goto_definition = 195,       /* on_goto_definition  */
  YYSYMBOL_196_1 = 196,                    /* $@1  */
  YYSYMBOL_on_gosub_definition = 197,      /* on_gosub_definition  */
  YYSYMBOL_198_2 = 198,                    /* $@2  */
  YYSYMBOL_on_definition = 199,            /* on_definition  */
  YYSYMBOL_200_3 = 200,                    /* $@3  */
  YYSYMBOL_201_4 = 201,                    /* $@4  */
  YYSYMBOL_every_definition = 202,         /* every_definition  */
  YYSYMBOL_statement = 203,                /* statement  */
  YYSYMBOL_statements_no_linenumbers = 204, /* statements_no_linenumbers  */
  YYSYMBOL_205_5 = 205,                    /* $@5  */
  YYSYMBOL_statements_with_linenumbers = 206, /* statements_with_linenumbers  */
  YYSYMBOL_207_6 = 207,                    /* $@6  */
  YYSYMBOL_statements_complex = 208,       /* statements_complex  */
  YYSYMBOL_program = 209                   /* program  */
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
#define YYFINAL  184
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   884

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  143
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  283
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  477

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   397


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
     135,   136,   137,   138,   139,   140,   141,   142
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    67,    70,    73,    76,    79,    82,    85,
      90,    95,    99,   103,   107,   111,   115,   119,   123,   127,
     131,   135,   139,   143,   147,   151,   155,   159,   163,   167,
     171,   175,   179,   183,   187,   191,   195,   199,   205,   208,
     212,   216,   220,   224,   228,   232,   235,   238,   241,   244,
     247,   250,   253,   256,   259,   262,   265,   269,   273,   279,
     280,   283,   287,   291,   295,   298,   301,   304,   307,   310,
     316,   320,   320,   323,   326,   329,   332,   335,   338,   342,
     345,   348,   351,   355,   358,   361,   364,   368,   371,   374,
     377,   383,   386,   389,   392,   395,   400,   401,   404,   407,
     412,   415,   420,   421,   424,   427,   432,   435,   440,   441,
     444,   447,   450,   455,   458,   461,   466,   467,   470,   471,
     472,   475,   478,   481,   486,   489,   492,   498,   499,   502,
     505,   508,   511,   514,   517,   520,   523,   526,   529,   532,
     535,   538,   541,   544,   549,   552,   555,   558,   561,   564,
     567,   570,   573,   576,   579,   582,   585,   588,   591,   596,
     597,   600,   603,   606,   609,   612,   618,   621,   627,   628,
     631,   636,   641,   642,   645,   648,   653,   656,   661,   666,
     667,   670,   673,   676,   681,   684,   690,   691,   694,   697,
     700,   703,   706,   711,   714,   717,   722,   723,   725,   726,
     729,   732,   742,   745,   751,   754,   760,   763,   769,   774,
     775,   778,   782,   782,   787,   791,   791,   796,   796,   799,
     799,   804,   807,   810,   815,   816,   817,   818,   819,   820,
     821,   822,   823,   824,   825,   826,   827,   828,   829,   832,
     835,   838,   841,   844,   847,   850,   853,   856,   859,   862,
     865,   868,   871,   874,   877,   880,   883,   886,   889,   892,
     895,   898,   901,   902,   903,   904,   905,   908,   911,   914,
     917,   926,   929,   930,   934,   935,   935,   939,   939,   946,
     947,   948,   949,   953
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
  "EQUAL", "ASSIGN", "LT", "LTE", "GT", "GTE", "DISEQUAL", "RASTER",
  "DONE", "AT", "COLOR", "BORDER", "WAIT", "NEXT", "WITH", "BANK",
  "SPRITE", "DATA", "FROM", "OP", "CP", "ENABLE", "DISABLE", "HALT", "ECM",
  "BITMAP", "SCREEN", "ON", "OFF", "ROWS", "VERTICAL", "SCROLL", "VAR",
  "AS", "TEMPORARY", "XPEN", "YPEN", "PEEK", "GOTO", "HORIZONTAL", "MCM",
  "COMPRESS", "EXPAND", "LOOP", "REPEAT", "WHILE", "TEXT", "TILES",
  "COLORMAP", "SELECT", "MONOCOLOR", "MULTICOLOR", "COLLISION", "IF",
  "THEN", "HIT", "BACKGROUND", "TO", "RANDOM", "BYTE", "WORD", "POSITION",
  "CODE", "VARIABLES", "MS", "CYCLES", "S", "HASH", "WIDTH", "HEIGHT",
  "DWORD", "PEN", "CLEAR", "BEG", "END", "GAMELOOP", "ENDIF", "UP", "DOWN",
  "LEFT", "RIGHT", "DEBUG", "AND", "RANDOMIZE", "GRAPHIC", "TEXTMAP",
  "POINT", "GOSUB", "RETURN", "POP", "OR", "ELSE", "NOT", "TRUE", "FALSE",
  "DO", "EXIT", "WEND", "UNTIL", "FOR", "STEP", "EVERY", "MILLISECOND",
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
  "every_definition", "statement", "statements_no_linenumbers", "$@5",
  "statements_with_linenumbers", "$@6", "statements_complex", "program", YY_NULLPTR
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
     395,   396,   397
};
#endif

#define YYPACT_NINF (-180)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-216)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     418,  -180,   -19,  -180,    15,   699,     0,   -15,   699,  -180,
       7,    46,   742,   -88,  -120,  -180,  -180,   742,    73,    36,
     -13,   742,   -21,   -12,  -180,   742,  -180,  -180,    59,    82,
     -40,  -180,  -180,    48,  -180,   -58,  -180,   742,   -29,   273,
      45,  -180,   110,   115,   119,  -180,   128,   699,   114,  -180,
    -180,  -180,   699,   699,   699,  -180,  -180,  -180,   600,  -180,
    -180,   131,   132,   134,    -4,     3,   742,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,    44,  -180,  -180,    10,
     -34,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
      47,  -180,  -180,   -52,  -180,    18,  -180,    38,  -180,  -180,
    -180,   -18,    89,   -16,   -10,    -9,    -6,   146,  -180,  -180,
    -180,   122,   177,  -180,  -180,  -180,   699,  -180,  -180,   144,
    -180,  -180,  -180,  -180,  -180,   699,   129,   135,  -180,  -180,
    -180,   -27,  -180,   138,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,   699,  -180,  -180,  -180,   699,   148,
    -180,  -180,  -180,   116,  -180,  -180,  -180,   699,  -180,  -180,
    -180,   149,  -180,  -180,  -180,  -180,  -180,  -180,   742,   742,
    -180,  -180,  -180,   168,  -180,  -180,    67,  -180,  -180,   742,
     517,  -180,   418,   418,  -180,   160,   161,   699,  -180,  -180,
     121,   127,   136,   139,   156,   159,   165,   169,   175,   180,
     699,   699,   699,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,   742,   742,
     742,   742,   742,   742,   742,   742,   742,   742,  -180,  -180,
    -180,   699,   179,  -180,  -180,  -180,   164,    89,   192,    89,
     193,    89,   194,    89,   195,    89,  -180,    89,   187,  -180,
    -180,    56,    84,    31,    39,  -180,  -180,  -180,   189,   742,
     188,  -180,  -180,    88,    94,    50,    54,  -180,  -180,   190,
    -180,  -180,   699,  -180,  -180,   699,   699,  -180,  -180,    83,
    -180,  -180,  -180,  -180,   699,  -180,  -180,  -180,   699,   158,
     215,   742,   126,  -180,  -180,   517,  -180,  -180,    86,    87,
    -180,  -180,    89,   742,    89,   742,    90,    92,    93,    95,
      96,  -180,   197,   204,   209,   210,   212,   213,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,   220,   221,
     699,    19,  -180,    89,  -180,    89,  -180,    89,  -180,    89,
      16,  -180,    89,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,    89,  -180,   742,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,   742,  -180,  -180,  -180,  -180,  -180,  -180,   108,
     112,   241,   217,   219,   253,   265,  -180,   -63,   206,   133,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,   140,   141,
    -180,  -180,  -180,  -180,  -180,  -180,   250,  -180,   256,  -180,
     142,    24,  -180,   272,  -180,   278,   282,  -180,   284,  -180,
     699,    89,   742,    89,   742,  -180,  -180,   742,  -180,  -180,
    -180,   151,   153,  -180,   269,  -180,   271,  -180,    89,   742,
     291,   292,  -180,  -180,  -180,  -180,   270,   274,   191,  -180,
    -180,   167,   170,   277,   283,   108,   112,  -180,  -180,   742,
    -180,  -180,  -180,  -180,  -180,  -180,  -180
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     273,   272,     0,   268,     0,     0,   256,     0,     0,   261,
       0,     0,     0,   198,     0,   244,   247,     0,     0,     0,
       0,     0,     0,     0,   242,     0,   238,   260,     0,     0,
       0,   266,   267,   240,   243,   249,   246,     0,     0,     0,
       0,   277,   274,   279,   281,   283,     0,     0,     0,   102,
     103,   225,     0,     0,     0,   116,   117,   227,     0,    48,
      49,     0,     0,     0,     0,     0,     0,    56,    57,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,    23,    28,    29,    30,    31,    32,    33,    36,    37,
       0,    38,    39,     0,    45,    59,    70,     0,   127,   128,
     228,     0,     0,     0,     0,     0,     0,     0,    96,    97,
     224,     0,     0,   159,   160,   229,     0,   162,   163,   164,
     168,   169,   230,   188,   189,     0,     0,     0,   196,   197,
     235,     0,   262,     0,   206,   237,   202,   203,   263,   245,
     174,   175,   176,   232,     0,   179,   180,   233,     0,   182,
     186,   187,   234,     0,   258,   259,   271,     0,   172,   173,
     231,     0,   209,   210,   236,   204,   205,   264,     0,     0,
     251,   252,   248,     0,   222,   223,     0,   265,   269,     0,
     273,   275,   273,   273,     1,     0,     0,     0,   110,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     3,     4,     6,     8,     9,     5,
      10,    54,     2,    58,    34,    21,    24,    25,    26,    27,
      22,    35,   118,   121,   119,   120,   122,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,   125,
     126,     0,     0,   108,   109,   226,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,     0,     0,   134,
     135,     0,     0,     0,     0,   131,   130,    71,     0,     0,
       0,   149,   150,     0,     0,     0,     0,   146,   145,     0,
     161,   166,     0,   190,   193,     0,     0,   217,   219,     0,
     177,   178,   181,   184,     0,   239,   170,   171,     0,     0,
     250,     0,     0,   270,   278,   273,   280,   282,     0,     0,
      98,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,    60,    61,
      64,    66,    67,    68,    69,    65,    62,    63,     0,     0,
       0,     0,    78,     0,    90,     0,    82,     0,    86,     0,
      74,   132,     0,   139,   138,   143,   142,   137,   141,   136,
     140,     0,   147,     0,   154,   153,   158,   157,   152,   156,
     151,   155,     0,   165,   167,   191,   194,   192,   195,     0,
       0,   199,     0,     0,     0,     0,   241,     0,     0,     0,
     276,    99,   101,   112,   115,   111,   114,    44,    40,    41,
      43,    42,    46,    47,    50,    51,    52,    53,     0,     0,
     104,   106,    75,    88,    80,    83,    77,    89,    81,    85,
       0,     0,   129,     0,   144,     0,   211,   218,   214,   220,
       0,     0,     0,     0,     0,   253,   254,     0,   221,   105,
     107,     0,     0,    91,    76,    87,    79,    84,     0,     0,
       0,     0,   200,   201,   183,   185,     0,     0,   255,    93,
      95,     0,     0,     0,     0,     0,     0,   207,   208,     0,
      92,    94,   133,   148,   213,   216,   257
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -180,     2,  -180,  -180,  -180,     8,    34,    -8,   198,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,   222,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -164,  -180,  -149,  -180,  -180,  -180,  -180,  -180,
    -180,  -179,  -180,  -180,  -180,   -25,  -180
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    93,   210,   211,    94,    95,    96,    97,   268,   108,
     109,   110,    49,    50,    51,   243,   244,   245,    55,    56,
      57,   227,    98,    99,   100,   113,   114,   115,   120,   121,
     122,   158,   159,   160,   142,   143,   145,   146,   147,   150,
     151,   152,   128,   129,   130,   134,   138,   167,   135,   162,
     163,   164,   427,   450,   429,   451,   132,   379,   380,   177,
      42,    43,   305,    44,   180,    45,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     112,   304,    47,   241,   131,   247,   102,   169,   148,   139,
     111,   249,   251,   153,   103,   253,    65,   156,   203,   101,
     136,    65,   137,   287,   222,   223,   228,   229,   116,   172,
     230,   104,   231,   232,   233,   234,   235,   171,    52,   186,
     117,   118,   420,    53,   189,   191,   193,   176,   412,   185,
     199,   178,   133,   444,   188,   190,   192,   144,   179,   105,
     106,   421,   224,   225,   226,   413,   154,   204,   205,   206,
     445,   149,   288,   357,   213,   155,   207,   208,   209,   435,
     157,   359,   358,    54,   170,   123,   124,   125,   126,   219,
     360,   119,   368,   414,   415,   220,   370,   127,   446,   447,
     165,   369,   166,   161,   246,   371,   140,   141,   281,   353,
     354,   173,   236,   168,   222,   238,   181,   284,   280,   182,
     237,    48,   242,   183,   248,   107,   390,   283,   184,   215,
     250,   252,   216,   217,   254,   187,   291,   355,   356,   218,
     293,   364,   365,   256,   257,   212,   290,   366,   367,   297,
     292,   258,   224,   225,   239,   259,   260,   306,   307,   296,
     299,   300,   200,   201,   261,   202,   214,   255,    65,   221,
     282,   303,   285,   262,   294,   263,   264,   289,   286,   311,
     298,   301,   295,   302,   265,   266,   308,   309,   316,   310,
     312,   317,   323,   325,   327,   267,   313,   318,   256,   269,
     340,   319,   322,   324,   326,   314,   270,   320,   315,   341,
     271,   272,   321,   343,   345,   347,   349,   352,   363,   273,
     361,   372,   387,   381,   386,   389,   391,   392,   274,   402,
     275,   276,   397,   339,   398,   399,   403,   400,   401,   277,
     278,   404,   405,   338,   406,   407,   408,   409,   426,   342,
     267,   344,   428,   346,   430,   348,   431,   350,   432,   351,
     433,   362,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   434,   438,   374,   437,   441,   376,   378,   448,
     439,   440,   442,   443,   373,   449,   383,   375,   377,  -212,
     385,  -215,   459,   388,   460,   461,   382,   462,   465,   466,
     384,   474,   467,   469,    58,   394,   468,   396,   470,   472,
     279,   471,   174,   175,   393,   473,   395,   475,     0,   240,
      59,    60,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   411,     0,     0,     0,     0,    62,     0,     0,
      63,     0,   410,    64,     0,   416,     0,   417,     0,   418,
       0,   419,     0,     0,   422,   424,     0,     0,     0,     0,
       0,     0,     0,   423,   425,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,    67,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   436,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,    92,     0,     0,     0,     0,
       0,     1,   453,     0,   455,     0,   457,     0,     0,   458,
       0,     0,   452,   454,     0,   456,     0,     2,     3,     0,
       4,   464,     5,     6,     0,     7,     8,     0,     0,     0,
     463,     0,     0,     9,     0,    10,    11,    12,     0,     0,
       0,   476,    13,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,    15,    16,    17,    18,    19,    20,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,     0,    24,     0,     0,     0,
       0,    25,     0,    26,    27,    28,    29,    30,    31,    32,
       1,    33,     0,     0,     0,    34,    35,    36,    37,    38,
       0,    39,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     5,     6,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     9,     0,    10,    11,    12,     0,    40,     0,
      41,    13,     0,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    23,     0,    24,     0,     0,     0,     0,
      25,     0,    26,    27,    28,    29,    30,    31,    32,     0,
      33,     0,   194,     0,    34,    35,    36,    37,    38,     0,
      39,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    59,    60,    61,
       0,     0,     0,     0,     0,     0,     0,    40,     0,     0,
       0,     0,     0,     0,    62,     0,     0,    63,     0,     0,
      64,   195,   196,   197,     0,     0,     0,     0,     0,     0,
       0,     0,   198,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    66,    67,    68,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      58,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    59,    60,    61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    62,     0,     0,    63,     0,     0,    64,
       0,     0,     0,    58,     0,     0,     0,     0,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    59,
      60,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    67,    68,    62,     0,     0,    63,
       0,     0,    64,     0,     0,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       0,    92,     0,     0,     0,     0,    66,    67,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,    92
};

static const yytype_int16 yycheck[] =
{
       8,   180,    21,    21,    12,    21,    21,    65,    21,    17,
       8,    21,    21,    21,    29,    21,    79,    25,    22,    19,
     140,    79,   142,    50,    76,    77,     8,     9,    21,    37,
      12,    46,    14,    15,    16,    17,    18,    35,    23,    47,
      33,    34,    26,    28,    52,    53,    54,    39,    29,    47,
      58,     6,   140,    29,    52,    53,    54,    21,    13,    74,
      75,    45,   114,   115,   116,    46,    87,    71,    72,    73,
      46,    84,    99,    42,    66,    87,    80,    81,    82,   142,
      21,    42,    51,    68,   142,    39,    40,    41,    42,   123,
      51,    84,    42,    74,    75,   129,    42,    51,    74,    75,
     140,    51,   142,    21,   102,    51,    33,    34,   116,    53,
      54,   140,    94,    65,    76,    77,     6,   125,   116,     4,
     102,   140,   140,     4,   140,   140,   305,   125,     0,   119,
     140,   140,   122,   123,   140,    21,   144,    53,    54,   129,
     148,    53,    54,    21,    22,   142,   144,    53,    54,   157,
     148,    29,   114,   115,   116,    33,    34,   182,   183,   157,
     168,   169,    31,    31,    42,    31,   122,    21,    79,   122,
      26,   179,    43,    51,    26,    53,    54,    39,    43,   187,
      31,    13,    66,   116,    62,    63,    26,    26,    32,   187,
      69,    32,   200,   201,   202,    73,    69,    32,    21,    22,
      21,    32,   200,   201,   202,    69,    29,    32,    69,    45,
      33,    34,    32,    21,    21,    21,    21,    30,    30,    42,
      31,    31,     7,   140,    66,    99,   140,   140,    51,    32,
      53,    54,   142,   241,   142,   142,    32,   142,   142,    62,
      63,    32,    32,   241,    32,    32,    26,    26,   140,   247,
      73,   249,   140,   251,    13,   253,    39,   255,    39,   257,
       7,   269,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     7,   140,   282,    69,    26,   285,   286,     7,
     140,   140,    26,   141,   282,     7,   294,   285,   286,     7,
     298,     7,   141,   301,   141,    26,   294,    26,     7,     7,
     298,   465,    32,   112,    31,   313,    32,   315,   141,    32,
     112,   141,    39,    40,   312,    32,   314,   466,    -1,    97,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   340,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      67,    -1,   340,    70,    -1,   343,    -1,   345,    -1,   347,
      -1,   349,    -1,    -1,   352,   363,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   361,   372,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   387,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,    -1,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,    -1,   142,    -1,    -1,    -1,    -1,
      -1,     3,   430,    -1,   432,    -1,   434,    -1,    -1,   437,
      -1,    -1,   430,   431,    -1,   433,    -1,    19,    20,    -1,
      22,   449,    24,    25,    -1,    27,    28,    -1,    -1,    -1,
     448,    -1,    -1,    35,    -1,    37,    38,    39,    -1,    -1,
      -1,   469,    44,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    93,    -1,    95,    96,    97,    98,    99,   100,   101,
       3,   103,    -1,    -1,    -1,   107,   108,   109,   110,   111,
      -1,   113,    -1,    -1,    -1,    -1,    19,    20,    -1,    22,
      -1,    24,    25,    -1,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    37,    38,    39,    -1,   140,    -1,
     142,    44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,
      93,    -1,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,    -1,    22,    -1,   107,   108,   109,   110,   111,    -1,
     113,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    67,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      31,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,    -1,    -1,    -1,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    67,    -1,    -1,    70,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,   105,   106,    64,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,    -1,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
      -1,   142,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    -1,   142
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    19,    20,    22,    24,    25,    27,    28,    35,
      37,    38,    39,    44,    50,    55,    56,    57,    58,    59,
      60,    65,    85,    86,    88,    93,    95,    96,    97,    98,
      99,   100,   101,   103,   107,   108,   109,   110,   111,   113,
     140,   142,   203,   204,   206,   208,   209,    21,   140,   155,
     156,   157,    23,    28,    68,   161,   162,   163,    31,    47,
      48,    49,    64,    67,    70,    79,   104,   105,   106,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   142,   144,   147,   148,   149,   150,   165,   166,
     167,    19,    21,    29,    46,    74,    75,   140,   152,   153,
     154,   144,   150,   168,   169,   170,    21,    33,    34,    84,
     171,   172,   173,    39,    40,    41,    42,    51,   185,   186,
     187,   150,   199,   140,   188,   191,   140,   142,   189,   150,
      33,    34,   177,   178,    21,   179,   180,   181,    21,    84,
     182,   183,   184,   150,    87,    87,   150,    21,   174,   175,
     176,    21,   192,   193,   194,   140,   142,   190,    65,    65,
     142,   144,   150,   140,    39,    40,   148,   202,     6,    13,
     207,     6,     4,     4,     0,   144,   150,    21,   144,   150,
     144,   150,   144,   150,    22,    71,    72,    73,    82,   150,
      31,    31,    31,    22,    71,    72,    73,    80,    81,    82,
     145,   146,   142,   148,   122,   119,   122,   123,   129,   123,
     129,   122,    76,    77,   114,   115,   116,   164,     8,     9,
      12,    14,    15,    16,    17,    18,    94,   102,    77,   116,
     164,    21,   140,   158,   159,   160,   144,    21,   140,    21,
     140,    21,   140,    21,   140,    21,    21,    22,    29,    33,
      34,    42,    51,    53,    54,    62,    63,    73,   151,    22,
      29,    33,    34,    42,    51,    53,    54,    62,    63,   151,
     144,   150,    26,   144,   150,    43,    43,    50,    99,    39,
     144,   150,   144,   150,    26,    66,   144,   150,    31,   150,
     150,    13,   116,   150,   204,   205,   208,   208,    26,    26,
     144,   150,    69,    69,    69,    69,    32,    32,    32,    32,
      32,    32,   144,   150,   144,   150,   144,   150,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   144,   150,
      21,    45,   144,    21,   144,    21,   144,    21,   144,    21,
     144,   144,    30,    53,    54,    53,    54,    42,    51,    42,
      51,    31,   150,    30,    53,    54,    53,    54,    42,    51,
      42,    51,    31,   144,   150,   144,   150,   144,   150,   200,
     201,   140,   144,   150,   144,   150,    66,     7,   150,    99,
     204,   140,   140,   144,   150,   144,   150,   142,   142,   142,
     142,   142,    32,    32,    32,    32,    32,    32,    26,    26,
     144,   150,    29,    46,    74,    75,   144,   144,   144,   144,
      26,    45,   144,   144,   150,   150,   140,   195,   140,   197,
      13,    39,    39,     7,     7,   142,   144,    69,   140,   140,
     140,    26,    26,   141,    29,    46,    74,    75,     7,     7,
     196,   198,   144,   150,   144,   150,   144,   150,   150,   141,
     141,    26,    26,   144,   150,     7,     7,    32,    32,   112,
     141,   141,    32,    32,   195,   197,   150
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   143,   144,   145,   145,   145,   145,   145,   145,   145,
     146,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     150,   151,   151,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   153,   153,   153,   153,   153,   154,   154,   155,   155,
     156,   156,   157,   157,   158,   158,   159,   159,   160,   160,
     161,   161,   161,   162,   162,   162,   163,   163,   164,   164,
     164,   165,   165,   165,   166,   166,   166,   167,   167,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   170,
     170,   171,   171,   171,   171,   171,   172,   172,   173,   173,
     174,   175,   176,   176,   177,   177,   178,   179,   180,   181,
     181,   182,   182,   182,   183,   183,   184,   184,   185,   185,
     185,   185,   185,   186,   186,   186,   187,   187,   188,   188,
     188,   188,   189,   189,   190,   190,   191,   192,   193,   194,
     194,   195,   196,   195,   197,   198,   197,   200,   199,   201,
     199,   202,   202,   202,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   204,   205,   204,   207,   206,   208,
     208,   208,   208,   209
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     1,     4,     4,     1,     1,
       4,     4,     4,     4,     2,     3,     1,     1,     2,     1,
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
       5,     5,     1,     1,     1,     1,     1,     6,     6,     1,
       1,     1,     0,     4,     1,     0,     4,     0,     4,     0,
       4,     4,     1,     1,     2,     2,     3,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     3,
       1,     4,     1,     1,     1,     2,     1,     1,     2,     1,
       3,     2,     2,     5,     5,     6,     1,     8,     2,     2,
       1,     1,     2,     2,     2,     2,     1,     1,     1,     2,
       3,     2,     1,     0,     1,     0,     4,     0,     3,     1,
       3,     1,     3,     1
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
#line 62 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2118 "src-generated/ugbc.tab.c"
    break;

  case 3: /* random_definition_simple: BYTE  */
#line 67 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2126 "src-generated/ugbc.tab.c"
    break;

  case 4: /* random_definition_simple: WORD  */
#line 70 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2134 "src-generated/ugbc.tab.c"
    break;

  case 5: /* random_definition_simple: DWORD  */
#line 73 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2142 "src-generated/ugbc.tab.c"
    break;

  case 6: /* random_definition_simple: POSITION  */
#line 76 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2150 "src-generated/ugbc.tab.c"
    break;

  case 7: /* random_definition_simple: COLOR  */
#line 79 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2158 "src-generated/ugbc.tab.c"
    break;

  case 8: /* random_definition_simple: WIDTH  */
#line 82 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2166 "src-generated/ugbc.tab.c"
    break;

  case 9: /* random_definition_simple: HEIGHT  */
#line 85 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2174 "src-generated/ugbc.tab.c"
    break;

  case 10: /* random_definition: random_definition_simple  */
#line 90 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2182 "src-generated/ugbc.tab.c"
    break;

  case 11: /* color_enumeration: BLACK  */
#line 95 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2191 "src-generated/ugbc.tab.c"
    break;

  case 12: /* color_enumeration: WHITE  */
#line 99 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2200 "src-generated/ugbc.tab.c"
    break;

  case 13: /* color_enumeration: RED  */
#line 103 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2209 "src-generated/ugbc.tab.c"
    break;

  case 14: /* color_enumeration: CYAN  */
#line 107 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2218 "src-generated/ugbc.tab.c"
    break;

  case 15: /* color_enumeration: VIOLET  */
#line 111 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2227 "src-generated/ugbc.tab.c"
    break;

  case 16: /* color_enumeration: GREEN  */
#line 115 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2236 "src-generated/ugbc.tab.c"
    break;

  case 17: /* color_enumeration: BLUE  */
#line 119 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2245 "src-generated/ugbc.tab.c"
    break;

  case 18: /* color_enumeration: YELLOW  */
#line 123 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2254 "src-generated/ugbc.tab.c"
    break;

  case 19: /* color_enumeration: ORANGE  */
#line 127 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2263 "src-generated/ugbc.tab.c"
    break;

  case 20: /* color_enumeration: BROWN  */
#line 131 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2272 "src-generated/ugbc.tab.c"
    break;

  case 21: /* color_enumeration: LIGHT RED  */
#line 135 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2281 "src-generated/ugbc.tab.c"
    break;

  case 22: /* color_enumeration: DARK GREY  */
#line 139 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2290 "src-generated/ugbc.tab.c"
    break;

  case 23: /* color_enumeration: GREY  */
#line 143 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2299 "src-generated/ugbc.tab.c"
    break;

  case 24: /* color_enumeration: LIGHT GREEN  */
#line 147 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2308 "src-generated/ugbc.tab.c"
    break;

  case 25: /* color_enumeration: LIGHT BLUE  */
#line 151 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2317 "src-generated/ugbc.tab.c"
    break;

  case 26: /* color_enumeration: LIGHT GREY  */
#line 155 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2326 "src-generated/ugbc.tab.c"
    break;

  case 27: /* color_enumeration: DARK BLUE  */
#line 159 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2335 "src-generated/ugbc.tab.c"
    break;

  case 28: /* color_enumeration: MAGENTA  */
#line 163 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2344 "src-generated/ugbc.tab.c"
    break;

  case 29: /* color_enumeration: PURPLE  */
#line 167 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2353 "src-generated/ugbc.tab.c"
    break;

  case 30: /* color_enumeration: LAVENDER  */
#line 171 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2362 "src-generated/ugbc.tab.c"
    break;

  case 31: /* color_enumeration: GOLD  */
#line 175 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2371 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: TURQUOISE  */
#line 179 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2380 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: TAN  */
#line 183 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2389 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: YELLOW GREEN  */
#line 187 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2398 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: OLIVE GREEN  */
#line 191 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2407 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: PINK  */
#line 195 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2416 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: PEACH  */
#line 199 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2425 "src-generated/ugbc.tab.c"
    break;

  case 38: /* expression: Identifier  */
#line 205 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2433 "src-generated/ugbc.tab.c"
    break;

  case 39: /* expression: Integer  */
#line 208 "src/ugbc.y"
              { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2442 "src-generated/ugbc.tab.c"
    break;

  case 40: /* expression: OP BYTE CP Integer  */
#line 212 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2451 "src-generated/ugbc.tab.c"
    break;

  case 41: /* expression: OP WORD CP Integer  */
#line 216 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2460 "src-generated/ugbc.tab.c"
    break;

  case 42: /* expression: OP DWORD CP Integer  */
#line 220 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2469 "src-generated/ugbc.tab.c"
    break;

  case 43: /* expression: OP POSITION CP Integer  */
#line 224 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2478 "src-generated/ugbc.tab.c"
    break;

  case 44: /* expression: OP COLOR CP Integer  */
#line 228 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2487 "src-generated/ugbc.tab.c"
    break;

  case 45: /* expression: color_enumeration  */
#line 232 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2495 "src-generated/ugbc.tab.c"
    break;

  case 46: /* expression: PEEK OP direct_integer CP  */
#line 235 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2503 "src-generated/ugbc.tab.c"
    break;

  case 47: /* expression: PEEK OP expressions CP  */
#line 238 "src/ugbc.y"
                             {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 2511 "src-generated/ugbc.tab.c"
    break;

  case 48: /* expression: XPEN  */
#line 241 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 2519 "src-generated/ugbc.tab.c"
    break;

  case 49: /* expression: YPEN  */
#line 244 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 2527 "src-generated/ugbc.tab.c"
    break;

  case 50: /* expression: COLLISION OP direct_integer CP  */
#line 247 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2535 "src-generated/ugbc.tab.c"
    break;

  case 51: /* expression: COLLISION OP expressions CP  */
#line 250 "src/ugbc.y"
                                  {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2543 "src-generated/ugbc.tab.c"
    break;

  case 52: /* expression: HIT OP direct_integer CP  */
#line 253 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2551 "src-generated/ugbc.tab.c"
    break;

  case 53: /* expression: HIT OP expressions CP  */
#line 256 "src/ugbc.y"
                            {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2559 "src-generated/ugbc.tab.c"
    break;

  case 54: /* expression: RANDOM random_definition  */
#line 259 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 2567 "src-generated/ugbc.tab.c"
    break;

  case 55: /* expression: OP expressions CP  */
#line 262 "src/ugbc.y"
                        {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 2575 "src-generated/ugbc.tab.c"
    break;

  case 56: /* expression: TRUE  */
#line 265 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 2584 "src-generated/ugbc.tab.c"
    break;

  case 57: /* expression: FALSE  */
#line 269 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 2593 "src-generated/ugbc.tab.c"
    break;

  case 58: /* expression: NOT expression  */
#line 273 "src/ugbc.y"
                     {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2601 "src-generated/ugbc.tab.c"
    break;

  case 59: /* expressions_raw: expression  */
#line 279 "src/ugbc.y"
                 { (yyval.string) = (yyvsp[0].string); }
#line 2607 "src-generated/ugbc.tab.c"
    break;

  case 60: /* expressions_raw: expression PLUS expressions_raw  */
#line 280 "src/ugbc.y"
                                      {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2615 "src-generated/ugbc.tab.c"
    break;

  case 61: /* expressions_raw: expression MINUS expressions_raw  */
#line 283 "src/ugbc.y"
                                       {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2624 "src-generated/ugbc.tab.c"
    break;

  case 62: /* expressions_raw: expression AND expressions_raw  */
#line 287 "src/ugbc.y"
                                     {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2633 "src-generated/ugbc.tab.c"
    break;

  case 63: /* expressions_raw: expression OR expressions_raw  */
#line 291 "src/ugbc.y"
                                    {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2642 "src-generated/ugbc.tab.c"
    break;

  case 64: /* expressions_raw: expression EQUAL expressions_raw  */
#line 295 "src/ugbc.y"
                                       {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2650 "src-generated/ugbc.tab.c"
    break;

  case 65: /* expressions_raw: expression DISEQUAL expressions_raw  */
#line 298 "src/ugbc.y"
                                          {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2658 "src-generated/ugbc.tab.c"
    break;

  case 66: /* expressions_raw: expression LT expressions_raw  */
#line 301 "src/ugbc.y"
                                    {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2666 "src-generated/ugbc.tab.c"
    break;

  case 67: /* expressions_raw: expression LTE expressions_raw  */
#line 304 "src/ugbc.y"
                                     {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2674 "src-generated/ugbc.tab.c"
    break;

  case 68: /* expressions_raw: expression GT expressions_raw  */
#line 307 "src/ugbc.y"
                                    {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2682 "src-generated/ugbc.tab.c"
    break;

  case 69: /* expressions_raw: expression GTE expressions_raw  */
#line 310 "src/ugbc.y"
                                     {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2690 "src-generated/ugbc.tab.c"
    break;

  case 70: /* expressions: expressions_raw  */
#line 316 "src/ugbc.y"
                    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2698 "src-generated/ugbc.tab.c"
    break;

  case 73: /* bank_definition_simple: AT direct_integer  */
#line 323 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2706 "src-generated/ugbc.tab.c"
    break;

  case 74: /* bank_definition_simple: Identifier AT direct_integer  */
#line 326 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2714 "src-generated/ugbc.tab.c"
    break;

  case 75: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 329 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2722 "src-generated/ugbc.tab.c"
    break;

  case 76: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 332 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2730 "src-generated/ugbc.tab.c"
    break;

  case 77: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 335 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2738 "src-generated/ugbc.tab.c"
    break;

  case 78: /* bank_definition_simple: DATA AT direct_integer  */
#line 338 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2746 "src-generated/ugbc.tab.c"
    break;

  case 79: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 342 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2754 "src-generated/ugbc.tab.c"
    break;

  case 80: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 345 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2762 "src-generated/ugbc.tab.c"
    break;

  case 81: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 348 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2770 "src-generated/ugbc.tab.c"
    break;

  case 82: /* bank_definition_simple: CODE AT direct_integer  */
#line 351 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2778 "src-generated/ugbc.tab.c"
    break;

  case 83: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 355 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2786 "src-generated/ugbc.tab.c"
    break;

  case 84: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 358 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2794 "src-generated/ugbc.tab.c"
    break;

  case 85: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 361 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 2802 "src-generated/ugbc.tab.c"
    break;

  case 86: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 364 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 2810 "src-generated/ugbc.tab.c"
    break;

  case 87: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 368 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 2818 "src-generated/ugbc.tab.c"
    break;

  case 88: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 371 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 2826 "src-generated/ugbc.tab.c"
    break;

  case 89: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 374 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 2834 "src-generated/ugbc.tab.c"
    break;

  case 90: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 377 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 2842 "src-generated/ugbc.tab.c"
    break;

  case 91: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 383 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2850 "src-generated/ugbc.tab.c"
    break;

  case 92: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 386 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 2858 "src-generated/ugbc.tab.c"
    break;

  case 93: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 389 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2866 "src-generated/ugbc.tab.c"
    break;

  case 94: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 392 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 2874 "src-generated/ugbc.tab.c"
    break;

  case 95: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 395 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2882 "src-generated/ugbc.tab.c"
    break;

  case 98: /* raster_definition_simple: Identifier AT direct_integer  */
#line 404 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 2890 "src-generated/ugbc.tab.c"
    break;

  case 99: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 407 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 2898 "src-generated/ugbc.tab.c"
    break;

  case 100: /* raster_definition_expression: Identifier AT expressions  */
#line 412 "src/ugbc.y"
                              {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2906 "src-generated/ugbc.tab.c"
    break;

  case 101: /* raster_definition_expression: AT expressions WITH Identifier  */
#line 415 "src/ugbc.y"
                                   {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2914 "src-generated/ugbc.tab.c"
    break;

  case 104: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 424 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 2922 "src-generated/ugbc.tab.c"
    break;

  case 105: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 427 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 2930 "src-generated/ugbc.tab.c"
    break;

  case 106: /* next_raster_definition_expression: Identifier AT expressions  */
#line 432 "src/ugbc.y"
                              {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 2938 "src-generated/ugbc.tab.c"
    break;

  case 107: /* next_raster_definition_expression: AT expressions WITH Identifier  */
#line 435 "src/ugbc.y"
                                   {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2946 "src-generated/ugbc.tab.c"
    break;

  case 110: /* color_definition_simple: BORDER direct_integer  */
#line 444 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 2954 "src-generated/ugbc.tab.c"
    break;

  case 111: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 447 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 2962 "src-generated/ugbc.tab.c"
    break;

  case 112: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 450 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 2970 "src-generated/ugbc.tab.c"
    break;

  case 113: /* color_definition_expression: BORDER expressions  */
#line 455 "src/ugbc.y"
                       {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 2978 "src-generated/ugbc.tab.c"
    break;

  case 114: /* color_definition_expression: BACKGROUND expressions TO expressions  */
#line 458 "src/ugbc.y"
                                          {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 2986 "src-generated/ugbc.tab.c"
    break;

  case 115: /* color_definition_expression: SPRITE expressions TO expressions  */
#line 461 "src/ugbc.y"
                                      {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 2994 "src-generated/ugbc.tab.c"
    break;

  case 121: /* wait_definition_simple: direct_integer CYCLES  */
#line 475 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3002 "src-generated/ugbc.tab.c"
    break;

  case 122: /* wait_definition_simple: direct_integer TICKS  */
#line 478 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3010 "src-generated/ugbc.tab.c"
    break;

  case 123: /* wait_definition_simple: direct_integer milliseconds  */
#line 481 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3018 "src-generated/ugbc.tab.c"
    break;

  case 124: /* wait_definition_expression: expressions CYCLES  */
#line 486 "src/ugbc.y"
                         {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3026 "src-generated/ugbc.tab.c"
    break;

  case 125: /* wait_definition_expression: expressions TICKS  */
#line 489 "src/ugbc.y"
                        {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3034 "src-generated/ugbc.tab.c"
    break;

  case 126: /* wait_definition_expression: expressions milliseconds  */
#line 492 "src/ugbc.y"
                               {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3042 "src-generated/ugbc.tab.c"
    break;

  case 129: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 502 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3050 "src-generated/ugbc.tab.c"
    break;

  case 130: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 505 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3058 "src-generated/ugbc.tab.c"
    break;

  case 131: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 508 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3066 "src-generated/ugbc.tab.c"
    break;

  case 132: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 511 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3074 "src-generated/ugbc.tab.c"
    break;

  case 133: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 514 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3082 "src-generated/ugbc.tab.c"
    break;

  case 134: /* sprite_definition_simple: direct_integer ENABLE  */
#line 517 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3090 "src-generated/ugbc.tab.c"
    break;

  case 135: /* sprite_definition_simple: direct_integer DISABLE  */
#line 520 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3098 "src-generated/ugbc.tab.c"
    break;

  case 136: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 523 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3106 "src-generated/ugbc.tab.c"
    break;

  case 137: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 526 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3114 "src-generated/ugbc.tab.c"
    break;

  case 138: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 529 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3122 "src-generated/ugbc.tab.c"
    break;

  case 139: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 532 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3130 "src-generated/ugbc.tab.c"
    break;

  case 140: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 535 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3138 "src-generated/ugbc.tab.c"
    break;

  case 141: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 538 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3146 "src-generated/ugbc.tab.c"
    break;

  case 142: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 541 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3154 "src-generated/ugbc.tab.c"
    break;

  case 143: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 544 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3162 "src-generated/ugbc.tab.c"
    break;

  case 144: /* sprite_definition_expression: expressions DATA FROM expressions  */
#line 549 "src/ugbc.y"
                                      {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3170 "src-generated/ugbc.tab.c"
    break;

  case 145: /* sprite_definition_expression: expressions MULTICOLOR  */
#line 552 "src/ugbc.y"
                           {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3178 "src-generated/ugbc.tab.c"
    break;

  case 146: /* sprite_definition_expression: expressions MONOCOLOR  */
#line 555 "src/ugbc.y"
                          {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3186 "src-generated/ugbc.tab.c"
    break;

  case 147: /* sprite_definition_expression: expressions COLOR expressions  */
#line 558 "src/ugbc.y"
                                  {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3194 "src-generated/ugbc.tab.c"
    break;

  case 148: /* sprite_definition_expression: expressions position OP expressions COMMA expressions CP  */
#line 561 "src/ugbc.y"
                                                             {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3202 "src-generated/ugbc.tab.c"
    break;

  case 149: /* sprite_definition_expression: expressions ENABLE  */
#line 564 "src/ugbc.y"
                       {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3210 "src-generated/ugbc.tab.c"
    break;

  case 150: /* sprite_definition_expression: expressions DISABLE  */
#line 567 "src/ugbc.y"
                        {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3218 "src-generated/ugbc.tab.c"
    break;

  case 151: /* sprite_definition_expression: expressions EXPAND VERTICAL  */
#line 570 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3226 "src-generated/ugbc.tab.c"
    break;

  case 152: /* sprite_definition_expression: expressions COMPRESS VERTICAL  */
#line 573 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3234 "src-generated/ugbc.tab.c"
    break;

  case 153: /* sprite_definition_expression: expressions VERTICAL EXPAND  */
#line 576 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3242 "src-generated/ugbc.tab.c"
    break;

  case 154: /* sprite_definition_expression: expressions VERTICAL COMPRESS  */
#line 579 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3250 "src-generated/ugbc.tab.c"
    break;

  case 155: /* sprite_definition_expression: expressions EXPAND HORIZONTAL  */
#line 582 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3258 "src-generated/ugbc.tab.c"
    break;

  case 156: /* sprite_definition_expression: expressions COMPRESS HORIZONTAL  */
#line 585 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3266 "src-generated/ugbc.tab.c"
    break;

  case 157: /* sprite_definition_expression: expressions HORIZONTAL EXPAND  */
#line 588 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3274 "src-generated/ugbc.tab.c"
    break;

  case 158: /* sprite_definition_expression: expressions HORIZONTAL COMPRESS  */
#line 591 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3282 "src-generated/ugbc.tab.c"
    break;

  case 161: /* bitmap_definition_simple: AT direct_integer  */
#line 600 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3290 "src-generated/ugbc.tab.c"
    break;

  case 162: /* bitmap_definition_simple: ENABLE  */
#line 603 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3298 "src-generated/ugbc.tab.c"
    break;

  case 163: /* bitmap_definition_simple: DISABLE  */
#line 606 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 3306 "src-generated/ugbc.tab.c"
    break;

  case 164: /* bitmap_definition_simple: CLEAR  */
#line 609 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 3314 "src-generated/ugbc.tab.c"
    break;

  case 165: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 612 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 3322 "src-generated/ugbc.tab.c"
    break;

  case 166: /* bitmap_definition_expression: AT expressions  */
#line 618 "src/ugbc.y"
                   {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3330 "src-generated/ugbc.tab.c"
    break;

  case 167: /* bitmap_definition_expression: CLEAR WITH expressions  */
#line 621 "src/ugbc.y"
                           {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 3338 "src-generated/ugbc.tab.c"
    break;

  case 170: /* textmap_definition_simple: AT direct_integer  */
#line 631 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3346 "src-generated/ugbc.tab.c"
    break;

  case 171: /* textmap_definition_expression: AT expressions  */
#line 636 "src/ugbc.y"
                   {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3354 "src-generated/ugbc.tab.c"
    break;

  case 174: /* text_definition_simple: ENABLE  */
#line 645 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3362 "src-generated/ugbc.tab.c"
    break;

  case 175: /* text_definition_simple: DISABLE  */
#line 648 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 3370 "src-generated/ugbc.tab.c"
    break;

  case 177: /* tiles_definition_simple: AT direct_integer  */
#line 656 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 3378 "src-generated/ugbc.tab.c"
    break;

  case 178: /* tiles_definition_expression: AT expressions  */
#line 661 "src/ugbc.y"
                   {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 3386 "src-generated/ugbc.tab.c"
    break;

  case 181: /* colormap_definition_simple: AT direct_integer  */
#line 670 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 3394 "src-generated/ugbc.tab.c"
    break;

  case 182: /* colormap_definition_simple: CLEAR  */
#line 673 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 3402 "src-generated/ugbc.tab.c"
    break;

  case 183: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 676 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3410 "src-generated/ugbc.tab.c"
    break;

  case 184: /* colormap_definition_expression: AT expressions  */
#line 681 "src/ugbc.y"
                   {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3418 "src-generated/ugbc.tab.c"
    break;

  case 185: /* colormap_definition_expression: CLEAR WITH expressions ON expressions  */
#line 684 "src/ugbc.y"
                                          {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3426 "src-generated/ugbc.tab.c"
    break;

  case 188: /* screen_definition_simple: ON  */
#line 694 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 3434 "src-generated/ugbc.tab.c"
    break;

  case 189: /* screen_definition_simple: OFF  */
#line 697 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 3442 "src-generated/ugbc.tab.c"
    break;

  case 190: /* screen_definition_simple: ROWS direct_integer  */
#line 700 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 3450 "src-generated/ugbc.tab.c"
    break;

  case 191: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 703 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3458 "src-generated/ugbc.tab.c"
    break;

  case 192: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 706 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3466 "src-generated/ugbc.tab.c"
    break;

  case 193: /* screen_definition_expression: ROWS expressions  */
#line 711 "src/ugbc.y"
                     {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 3474 "src-generated/ugbc.tab.c"
    break;

  case 194: /* screen_definition_expression: VERTICAL SCROLL expressions  */
#line 714 "src/ugbc.y"
                                {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3482 "src-generated/ugbc.tab.c"
    break;

  case 195: /* screen_definition_expression: HORIZONTAL SCROLL expressions  */
#line 717 "src/ugbc.y"
                                  {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3490 "src-generated/ugbc.tab.c"
    break;

  case 199: /* var_definition_simple: Identifier ON Identifier  */
#line 726 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 3498 "src-generated/ugbc.tab.c"
    break;

  case 200: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 729 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 3506 "src-generated/ugbc.tab.c"
    break;

  case 201: /* var_definition_simple: Identifier ON Identifier ASSIGN expressions  */
#line 732 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      if ( v == NULL ) {
          CRITICAL("Variable not found");
      }
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 3519 "src-generated/ugbc.tab.c"
    break;

  case 202: /* goto_definition: Identifier  */
#line 742 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 3527 "src-generated/ugbc.tab.c"
    break;

  case 203: /* goto_definition: Integer  */
#line 745 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 3535 "src-generated/ugbc.tab.c"
    break;

  case 204: /* gosub_definition: Identifier  */
#line 751 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 3543 "src-generated/ugbc.tab.c"
    break;

  case 205: /* gosub_definition: Integer  */
#line 754 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 3551 "src-generated/ugbc.tab.c"
    break;

  case 207: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 763 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 3559 "src-generated/ugbc.tab.c"
    break;

  case 208: /* point_definition_expression: AT OP expressions COMMA expressions CP  */
#line 769 "src/ugbc.y"
                                             {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 3567 "src-generated/ugbc.tab.c"
    break;

  case 211: /* on_goto_definition: Identifier  */
#line 778 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 3576 "src-generated/ugbc.tab.c"
    break;

  case 212: /* $@1: %empty  */
#line 782 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 3584 "src-generated/ugbc.tab.c"
    break;

  case 214: /* on_gosub_definition: Identifier  */
#line 787 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 3593 "src-generated/ugbc.tab.c"
    break;

  case 215: /* $@2: %empty  */
#line 791 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 3601 "src-generated/ugbc.tab.c"
    break;

  case 217: /* $@3: %empty  */
#line 796 "src/ugbc.y"
                       {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 3609 "src-generated/ugbc.tab.c"
    break;

  case 219: /* $@4: %empty  */
#line 799 "src/ugbc.y"
                        {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 3617 "src-generated/ugbc.tab.c"
    break;

  case 221: /* every_definition: expression TICKS GOSUB Identifier  */
#line 804 "src/ugbc.y"
                                        {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 3625 "src-generated/ugbc.tab.c"
    break;

  case 222: /* every_definition: ON  */
#line 807 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 3633 "src-generated/ugbc.tab.c"
    break;

  case 223: /* every_definition: OFF  */
#line 810 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 3641 "src-generated/ugbc.tab.c"
    break;

  case 238: /* statement: RANDOMIZE  */
#line 829 "src/ugbc.y"
              {
      randomize( _environment );
  }
#line 3649 "src-generated/ugbc.tab.c"
    break;

  case 239: /* statement: IF expressions THEN  */
#line 832 "src/ugbc.y"
                        {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 3657 "src-generated/ugbc.tab.c"
    break;

  case 240: /* statement: ELSE  */
#line 835 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 3665 "src-generated/ugbc.tab.c"
    break;

  case 241: /* statement: ELSE IF expressions THEN  */
#line 838 "src/ugbc.y"
                             {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 3673 "src-generated/ugbc.tab.c"
    break;

  case 242: /* statement: ENDIF  */
#line 841 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 3681 "src-generated/ugbc.tab.c"
    break;

  case 243: /* statement: DO  */
#line 844 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 3689 "src-generated/ugbc.tab.c"
    break;

  case 244: /* statement: LOOP  */
#line 847 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 3697 "src-generated/ugbc.tab.c"
    break;

  case 245: /* statement: WHILE expressions  */
#line 850 "src/ugbc.y"
                      {
      begin_while( _environment, (yyvsp[0].string) );  
  }
#line 3705 "src-generated/ugbc.tab.c"
    break;

  case 246: /* statement: WEND  */
#line 853 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 3713 "src-generated/ugbc.tab.c"
    break;

  case 247: /* statement: REPEAT  */
#line 856 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 3721 "src-generated/ugbc.tab.c"
    break;

  case 248: /* statement: UNTIL expressions  */
#line 859 "src/ugbc.y"
                      {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 3729 "src-generated/ugbc.tab.c"
    break;

  case 249: /* statement: EXIT  */
#line 862 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 3737 "src-generated/ugbc.tab.c"
    break;

  case 250: /* statement: EXIT IF expressions  */
#line 865 "src/ugbc.y"
                        {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 3745 "src-generated/ugbc.tab.c"
    break;

  case 251: /* statement: EXIT Integer  */
#line 868 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 3753 "src-generated/ugbc.tab.c"
    break;

  case 252: /* statement: EXIT direct_integer  */
#line 871 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 3761 "src-generated/ugbc.tab.c"
    break;

  case 253: /* statement: EXIT IF expressions COMMA Integer  */
#line 874 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 3769 "src-generated/ugbc.tab.c"
    break;

  case 254: /* statement: EXIT IF expressions COMMA direct_integer  */
#line 877 "src/ugbc.y"
                                             {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 3777 "src-generated/ugbc.tab.c"
    break;

  case 255: /* statement: FOR Identifier ASSIGN expressions TO expressions  */
#line 880 "src/ugbc.y"
                                                     {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 3785 "src-generated/ugbc.tab.c"
    break;

  case 256: /* statement: NEXT  */
#line 883 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 3793 "src-generated/ugbc.tab.c"
    break;

  case 257: /* statement: FOR Identifier ASSIGN expressions TO expressions STEP expressions  */
#line 886 "src/ugbc.y"
                                                                      {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 3801 "src-generated/ugbc.tab.c"
    break;

  case 258: /* statement: BEG GAMELOOP  */
#line 889 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 3809 "src-generated/ugbc.tab.c"
    break;

  case 259: /* statement: END GAMELOOP  */
#line 892 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 3817 "src-generated/ugbc.tab.c"
    break;

  case 260: /* statement: GRAPHIC  */
#line 895 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 3825 "src-generated/ugbc.tab.c"
    break;

  case 261: /* statement: HALT  */
#line 898 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 3833 "src-generated/ugbc.tab.c"
    break;

  case 266: /* statement: RETURN  */
#line 905 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 3841 "src-generated/ugbc.tab.c"
    break;

  case 267: /* statement: POP  */
#line 908 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 3849 "src-generated/ugbc.tab.c"
    break;

  case 268: /* statement: DONE  */
#line 911 "src/ugbc.y"
          {
      return 0;
  }
#line 3857 "src-generated/ugbc.tab.c"
    break;

  case 269: /* statement: Identifier COLON  */
#line 914 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 3865 "src-generated/ugbc.tab.c"
    break;

  case 270: /* statement: Identifier ASSIGN expressions  */
#line 917 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expressions = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expressions->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 3879 "src-generated/ugbc.tab.c"
    break;

  case 271: /* statement: DEBUG expressions  */
#line 926 "src/ugbc.y"
                      {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 3887 "src-generated/ugbc.tab.c"
    break;

  case 274: /* statements_no_linenumbers: statement  */
#line 934 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 3893 "src-generated/ugbc.tab.c"
    break;

  case 275: /* $@5: %empty  */
#line 935 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 3899 "src-generated/ugbc.tab.c"
    break;

  case 277: /* $@6: %empty  */
#line 939 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 3907 "src-generated/ugbc.tab.c"
    break;

  case 278: /* statements_with_linenumbers: Integer $@6 statements_no_linenumbers  */
#line 941 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 3915 "src-generated/ugbc.tab.c"
    break;


#line 3919 "src-generated/ugbc.tab.c"

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

#line 955 "src/ugbc.y"


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

    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x4000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x4100, NULL );

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

