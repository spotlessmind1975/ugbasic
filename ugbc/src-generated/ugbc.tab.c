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
  YYSYMBOL_RASTER = 20,                    /* RASTER  */
  YYSYMBOL_DONE = 21,                      /* DONE  */
  YYSYMBOL_AT = 22,                        /* AT  */
  YYSYMBOL_COLOR = 23,                     /* COLOR  */
  YYSYMBOL_BORDER = 24,                    /* BORDER  */
  YYSYMBOL_WAIT = 25,                      /* WAIT  */
  YYSYMBOL_NEXT = 26,                      /* NEXT  */
  YYSYMBOL_WITH = 27,                      /* WITH  */
  YYSYMBOL_BANK = 28,                      /* BANK  */
  YYSYMBOL_SPRITE = 29,                    /* SPRITE  */
  YYSYMBOL_DATA = 30,                      /* DATA  */
  YYSYMBOL_FROM = 31,                      /* FROM  */
  YYSYMBOL_OP = 32,                        /* OP  */
  YYSYMBOL_CP = 33,                        /* CP  */
  YYSYMBOL_ENABLE = 34,                    /* ENABLE  */
  YYSYMBOL_DISABLE = 35,                   /* DISABLE  */
  YYSYMBOL_HALT = 36,                      /* HALT  */
  YYSYMBOL_ECM = 37,                       /* ECM  */
  YYSYMBOL_BITMAP = 38,                    /* BITMAP  */
  YYSYMBOL_SCREEN = 39,                    /* SCREEN  */
  YYSYMBOL_ON = 40,                        /* ON  */
  YYSYMBOL_OFF = 41,                       /* OFF  */
  YYSYMBOL_ROWS = 42,                      /* ROWS  */
  YYSYMBOL_VERTICAL = 43,                  /* VERTICAL  */
  YYSYMBOL_SCROLL = 44,                    /* SCROLL  */
  YYSYMBOL_VAR = 45,                       /* VAR  */
  YYSYMBOL_AS = 46,                        /* AS  */
  YYSYMBOL_TEMPORARY = 47,                 /* TEMPORARY  */
  YYSYMBOL_XPEN = 48,                      /* XPEN  */
  YYSYMBOL_YPEN = 49,                      /* YPEN  */
  YYSYMBOL_PEEK = 50,                      /* PEEK  */
  YYSYMBOL_GOTO = 51,                      /* GOTO  */
  YYSYMBOL_HORIZONTAL = 52,                /* HORIZONTAL  */
  YYSYMBOL_MCM = 53,                       /* MCM  */
  YYSYMBOL_COMPRESS = 54,                  /* COMPRESS  */
  YYSYMBOL_EXPAND = 55,                    /* EXPAND  */
  YYSYMBOL_LOOP = 56,                      /* LOOP  */
  YYSYMBOL_REPEAT = 57,                    /* REPEAT  */
  YYSYMBOL_WHILE = 58,                     /* WHILE  */
  YYSYMBOL_TEXT = 59,                      /* TEXT  */
  YYSYMBOL_TILES = 60,                     /* TILES  */
  YYSYMBOL_COLORMAP = 61,                  /* COLORMAP  */
  YYSYMBOL_SELECT = 62,                    /* SELECT  */
  YYSYMBOL_MONOCOLOR = 63,                 /* MONOCOLOR  */
  YYSYMBOL_MULTICOLOR = 64,                /* MULTICOLOR  */
  YYSYMBOL_COLLISION = 65,                 /* COLLISION  */
  YYSYMBOL_IF = 66,                        /* IF  */
  YYSYMBOL_THEN = 67,                      /* THEN  */
  YYSYMBOL_HIT = 68,                       /* HIT  */
  YYSYMBOL_BACKGROUND = 69,                /* BACKGROUND  */
  YYSYMBOL_TO = 70,                        /* TO  */
  YYSYMBOL_RANDOM = 71,                    /* RANDOM  */
  YYSYMBOL_BYTE = 72,                      /* BYTE  */
  YYSYMBOL_WORD = 73,                      /* WORD  */
  YYSYMBOL_POSITION = 74,                  /* POSITION  */
  YYSYMBOL_CODE = 75,                      /* CODE  */
  YYSYMBOL_VARIABLES = 76,                 /* VARIABLES  */
  YYSYMBOL_MS = 77,                        /* MS  */
  YYSYMBOL_CYCLES = 78,                    /* CYCLES  */
  YYSYMBOL_S = 79,                         /* S  */
  YYSYMBOL_HASH = 80,                      /* HASH  */
  YYSYMBOL_WIDTH = 81,                     /* WIDTH  */
  YYSYMBOL_HEIGHT = 82,                    /* HEIGHT  */
  YYSYMBOL_DWORD = 83,                     /* DWORD  */
  YYSYMBOL_PEN = 84,                       /* PEN  */
  YYSYMBOL_CLEAR = 85,                     /* CLEAR  */
  YYSYMBOL_BEG = 86,                       /* BEG  */
  YYSYMBOL_END = 87,                       /* END  */
  YYSYMBOL_GAMELOOP = 88,                  /* GAMELOOP  */
  YYSYMBOL_ENDIF = 89,                     /* ENDIF  */
  YYSYMBOL_UP = 90,                        /* UP  */
  YYSYMBOL_DOWN = 91,                      /* DOWN  */
  YYSYMBOL_LEFT = 92,                      /* LEFT  */
  YYSYMBOL_RIGHT = 93,                     /* RIGHT  */
  YYSYMBOL_DEBUG = 94,                     /* DEBUG  */
  YYSYMBOL_AND = 95,                       /* AND  */
  YYSYMBOL_RANDOMIZE = 96,                 /* RANDOMIZE  */
  YYSYMBOL_GRAPHIC = 97,                   /* GRAPHIC  */
  YYSYMBOL_TEXTMAP = 98,                   /* TEXTMAP  */
  YYSYMBOL_POINT = 99,                     /* POINT  */
  YYSYMBOL_GOSUB = 100,                    /* GOSUB  */
  YYSYMBOL_RETURN = 101,                   /* RETURN  */
  YYSYMBOL_POP = 102,                      /* POP  */
  YYSYMBOL_OR = 103,                       /* OR  */
  YYSYMBOL_ELSE = 104,                     /* ELSE  */
  YYSYMBOL_NOT = 105,                      /* NOT  */
  YYSYMBOL_TRUE = 106,                     /* TRUE  */
  YYSYMBOL_FALSE = 107,                    /* FALSE  */
  YYSYMBOL_DO = 108,                       /* DO  */
  YYSYMBOL_EXIT = 109,                     /* EXIT  */
  YYSYMBOL_WEND = 110,                     /* WEND  */
  YYSYMBOL_UNTIL = 111,                    /* UNTIL  */
  YYSYMBOL_FOR = 112,                      /* FOR  */
  YYSYMBOL_STEP = 113,                     /* STEP  */
  YYSYMBOL_EVERY = 114,                    /* EVERY  */
  YYSYMBOL_MILLISECOND = 115,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 116,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 117,                    /* TICKS  */
  YYSYMBOL_BLACK = 118,                    /* BLACK  */
  YYSYMBOL_WHITE = 119,                    /* WHITE  */
  YYSYMBOL_RED = 120,                      /* RED  */
  YYSYMBOL_CYAN = 121,                     /* CYAN  */
  YYSYMBOL_VIOLET = 122,                   /* VIOLET  */
  YYSYMBOL_GREEN = 123,                    /* GREEN  */
  YYSYMBOL_BLUE = 124,                     /* BLUE  */
  YYSYMBOL_YELLOW = 125,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 126,                   /* ORANGE  */
  YYSYMBOL_BROWN = 127,                    /* BROWN  */
  YYSYMBOL_LIGHT = 128,                    /* LIGHT  */
  YYSYMBOL_DARK = 129,                     /* DARK  */
  YYSYMBOL_GREY = 130,                     /* GREY  */
  YYSYMBOL_GRAY = 131,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 132,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 133,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 134,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 135,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 136,                /* TURQUOISE  */
  YYSYMBOL_TAN = 137,                      /* TAN  */
  YYSYMBOL_PINK = 138,                     /* PINK  */
  YYSYMBOL_PEACH = 139,                    /* PEACH  */
  YYSYMBOL_OLIVE = 140,                    /* OLIVE  */
  YYSYMBOL_Identifier = 141,               /* Identifier  */
  YYSYMBOL_IdentifierString = 142,         /* IdentifierString  */
  YYSYMBOL_String = 143,                   /* String  */
  YYSYMBOL_Integer = 144,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 145,                 /* $accept  */
  YYSYMBOL_direct_integer = 146,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 147, /* random_definition_simple  */
  YYSYMBOL_random_definition = 148,        /* random_definition  */
  YYSYMBOL_color_enumeration = 149,        /* color_enumeration  */
  YYSYMBOL_expression = 150,               /* expression  */
  YYSYMBOL_expressions_raw = 151,          /* expressions_raw  */
  YYSYMBOL_expressions = 152,              /* expressions  */
  YYSYMBOL_position = 153,                 /* position  */
  YYSYMBOL_bank_definition_simple = 154,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 155, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 156,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 157, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 158, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 159,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 160, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 161, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 162,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 163,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 164, /* color_definition_expression  */
  YYSYMBOL_color_definition = 165,         /* color_definition  */
  YYSYMBOL_milliseconds = 166,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 167,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 168, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 169,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 170, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 171, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 172,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 173, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 174, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 175,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 176, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 177, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 178,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 179,   /* text_definition_simple  */
  YYSYMBOL_text_definition = 180,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 181,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 182, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 183,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 184, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 185, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 186,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 187, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 188, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 189,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 190,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 191,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 192,         /* gosub_definition  */
  YYSYMBOL_var_definition = 193,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 194,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 195, /* point_definition_expression  */
  YYSYMBOL_point_definition = 196,         /* point_definition  */
  YYSYMBOL_on_goto_definition = 197,       /* on_goto_definition  */
  YYSYMBOL_198_1 = 198,                    /* $@1  */
  YYSYMBOL_on_gosub_definition = 199,      /* on_gosub_definition  */
  YYSYMBOL_200_2 = 200,                    /* $@2  */
  YYSYMBOL_on_definition = 201,            /* on_definition  */
  YYSYMBOL_202_3 = 202,                    /* $@3  */
  YYSYMBOL_203_4 = 203,                    /* $@4  */
  YYSYMBOL_every_definition = 204,         /* every_definition  */
  YYSYMBOL_statement = 205,                /* statement  */
  YYSYMBOL_206_5 = 206,                    /* $@5  */
  YYSYMBOL_statements_no_linenumbers = 207, /* statements_no_linenumbers  */
  YYSYMBOL_208_6 = 208,                    /* $@6  */
  YYSYMBOL_statements_with_linenumbers = 209, /* statements_with_linenumbers  */
  YYSYMBOL_210_7 = 210,                    /* $@7  */
  YYSYMBOL_statements_complex = 211,       /* statements_complex  */
  YYSYMBOL_program = 212,                  /* program  */
  YYSYMBOL_213_8 = 213                     /* $@8  */
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
#define YYLAST   1084

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  145
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  292
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  497

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   399


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
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144
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
     283,   287,   293,   294,   297,   301,   305,   309,   313,   316,
     319,   322,   325,   328,   334,   338,   338,   341,   344,   347,
     350,   353,   356,   360,   363,   366,   369,   373,   376,   379,
     382,   386,   389,   392,   395,   401,   404,   407,   410,   413,
     418,   419,   422,   425,   430,   433,   438,   439,   442,   445,
     450,   453,   458,   459,   462,   465,   468,   473,   476,   479,
     484,   485,   488,   489,   490,   493,   496,   499,   504,   507,
     510,   516,   517,   520,   523,   526,   529,   532,   535,   538,
     541,   544,   547,   550,   553,   556,   559,   562,   567,   570,
     573,   576,   579,   582,   585,   588,   591,   594,   597,   600,
     603,   606,   609,   614,   615,   618,   621,   624,   627,   630,
     636,   639,   645,   646,   649,   654,   659,   660,   663,   666,
     671,   674,   679,   684,   685,   688,   691,   694,   699,   702,
     708,   709,   712,   715,   718,   721,   724,   729,   732,   735,
     740,   741,   743,   744,   747,   750,   753,   758,   765,   768,
     774,   777,   783,   786,   792,   797,   798,   801,   805,   805,
     810,   814,   814,   819,   819,   822,   822,   827,   830,   833,
     838,   839,   840,   841,   842,   843,   844,   845,   846,   847,
     848,   849,   850,   851,   852,   855,   858,   861,   864,   867,
     870,   873,   873,   878,   881,   884,   887,   890,   893,   896,
     899,   902,   905,   908,   911,   914,   917,   920,   923,   926,
     927,   928,   929,   930,   933,   936,   939,   942,   951,   960,
     963,   964,   968,   969,   969,   973,   973,   980,   981,   982,
     983,   987,   987
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
  "MULTIPLICATION", "RASTER", "DONE", "AT", "COLOR", "BORDER", "WAIT",
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
  "UNTIL", "FOR", "STEP", "EVERY", "MILLISECOND", "MILLISECONDS", "TICKS",
  "BLACK", "WHITE", "RED", "CYAN", "VIOLET", "GREEN", "BLUE", "YELLOW",
  "ORANGE", "BROWN", "LIGHT", "DARK", "GREY", "GRAY", "MAGENTA", "PURPLE",
  "LAVENDER", "GOLD", "TURQUOISE", "TAN", "PINK", "PEACH", "OLIVE",
  "Identifier", "IdentifierString", "String", "Integer", "$accept",
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
     395,   396,   397,   398,   399
};
#endif

#define YYPACT_NINF (-188)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-222)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -188,    27,   446,  -188,  -188,   -17,  -188,    34,   841,    18,
     -19,   841,  -188,    13,   107,   940,  -105,   -42,  -188,  -188,
    -188,    84,    37,    -6,   940,     0,    22,  -188,   940,  -188,
    -188,    47,    82,   -36,  -188,  -188,    46,  -188,   -47,  -188,
     940,   -26,   742,    94,   121,  -188,   115,   132,   139,  -188,
     841,   123,  -188,  -188,  -188,   841,   841,   841,  -188,  -188,
    -188,   629,  -188,  -188,   135,   137,   150,     8,    41,   154,
     940,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
      48,  -188,  -188,    54,   -90,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,    64,  -188,  -188,  -188,  -188,    16,
    -188,     6,  -188,    39,  -188,  -188,  -188,   -16,   109,   -15,
     -14,   -13,   -12,   166,  -188,  -188,  -188,    32,   138,  -188,
    -188,  -188,   841,  -188,  -188,   164,  -188,  -188,  -188,  -188,
    -188,   841,   151,   155,  -188,  -188,  -188,    -8,  -188,   160,
     163,  -188,  -188,  -188,  -188,  -188,   940,  -188,  -188,  -188,
    -188,   841,  -188,  -188,  -188,   841,   167,  -188,  -188,  -188,
     140,  -188,  -188,  -188,   841,  -188,  -188,  -188,   172,  -188,
    -188,  -188,  -188,  -188,  -188,   940,   940,  -188,  -188,  -188,
     192,  -188,  -188,    89,  -188,  -188,   940,   940,   546,  -188,
     446,   446,   181,   183,   841,  -188,  -188,   141,   143,   144,
     145,   184,   185,   186,   187,   188,   204,   841,   841,   841,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
     940,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,   940,   940,   940,   940,
     940,   940,   940,   940,   940,   940,   940,  -188,  -188,  -188,
     841,   194,  -188,  -188,  -188,   179,   109,   216,   109,   218,
     109,   219,   109,   220,   109,  -188,   109,   212,  -188,  -188,
      87,    97,    -1,     9,  -188,  -188,  -188,   213,   940,   215,
    -188,  -188,   103,   108,    21,    31,  -188,  -188,   217,  -188,
    -188,   841,  -188,  -188,   841,   841,  -188,  -188,   106,   110,
    -188,  -188,  -188,  -188,  -188,   841,  -188,  -188,  -188,   841,
     177,   241,   940,   152,  -188,  -188,  -188,   546,  -188,  -188,
     112,   113,  -188,  -188,   109,   940,   109,   940,   111,   114,
     116,   117,   118,  -188,   223,   224,   226,   230,   231,   233,
     243,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,   242,   245,   841,     2,  -188,   109,  -188,   109,
    -188,   109,  -188,   109,    14,  -188,   109,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,   109,  -188,   940,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,   940,  -188,  -188,  -188,
    -188,  -188,  -188,   127,   129,   261,   263,   238,   246,   275,
     278,  -188,   -68,   221,   146,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,   940,   147,   148,  -188,  -188,  -188,  -188,
    -188,  -188,   265,  -188,   266,  -188,   153,    38,  -188,   283,
    -188,   288,   290,  -188,   292,  -188,   841,   940,   109,   940,
     109,   940,  -188,  -188,   940,  -188,   267,  -188,  -188,   159,
     161,  -188,   276,  -188,   280,  -188,   109,   940,   298,   301,
    -188,  -188,  -188,  -188,  -188,   279,   282,   198,  -188,  -188,
    -188,   170,   174,   285,   286,   127,   129,  -188,  -188,   940,
    -188,  -188,  -188,  -188,  -188,  -188,  -188
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     291,     0,   281,     1,   280,     0,   275,     0,     0,   263,
       0,     0,   268,     0,     0,     0,   202,     0,   250,   254,
     251,     0,     0,     0,     0,     0,     0,   248,     0,   244,
     267,     0,     0,     0,   273,   274,   246,   249,   256,   253,
       0,     0,     0,     0,     0,   285,   282,   287,   289,   292,
       0,     0,   106,   107,   231,     0,     0,     0,   120,   121,
     233,     0,    50,    51,     0,     0,     0,     0,     0,     0,
       0,    59,    60,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,    23,    28,    29,    30,    31,
      32,    33,    36,    37,     0,    38,    39,    41,    40,     0,
      47,    62,    74,     0,   131,   132,   234,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   230,     0,     0,   163,
     164,   235,     0,   166,   167,   168,   172,   173,   236,   192,
     193,     0,     0,     0,   200,   201,   241,     0,   269,     0,
       0,   212,   243,   208,   209,   270,     0,   178,   179,   180,
     238,     0,   183,   184,   239,     0,   186,   190,   191,   240,
       0,   265,   266,   279,     0,   176,   177,   237,     0,   215,
     216,   242,   210,   211,   271,     0,     0,   258,   259,   255,
       0,   228,   229,     0,   272,   276,     0,     0,   281,   283,
     281,   281,     0,     0,     0,   114,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     3,     4,     6,     8,     9,     5,    10,    57,     2,
       0,    61,    34,    21,    24,    25,    26,    27,    22,    35,
     122,   125,   123,   124,   126,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,   129,   130,
       0,     0,   112,   113,   232,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,     0,     0,   138,   139,
       0,     0,     0,     0,   135,   134,    75,     0,     0,     0,
     153,   154,     0,     0,     0,     0,   150,   149,     0,   165,
     170,     0,   194,   197,     0,     0,   223,   225,     0,     0,
     252,   181,   182,   185,   188,     0,   245,   174,   175,     0,
       0,   257,     0,     0,   277,   278,   286,   281,   288,   290,
       0,     0,   102,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    68,    70,    71,    72,    73,    69,    65,
      66,    67,     0,     0,     0,     0,    82,     0,    94,     0,
      86,     0,    90,     0,    78,   136,     0,   143,   142,   147,
     146,   141,   145,   140,   144,     0,   151,     0,   158,   157,
     162,   161,   156,   160,   155,   159,     0,   169,   171,   195,
     198,   196,   199,     0,     0,   203,   204,     0,     0,     0,
       0,   247,     0,     0,     0,   284,   103,   105,   116,   119,
     115,   118,    46,    42,    43,    45,    44,    48,    49,    52,
      53,    54,    55,     0,     0,     0,   108,   110,    79,    92,
      84,    87,    81,    93,    85,    89,     0,     0,   133,     0,
     148,     0,   217,   224,   220,   226,     0,     0,     0,     0,
       0,     0,   260,   261,     0,   227,     0,   109,   111,     0,
       0,    95,    80,    91,    83,    88,     0,     0,     0,     0,
     205,   206,   207,   187,   189,     0,     0,   262,    56,    97,
      99,     0,     0,     0,     0,     0,     0,   213,   214,     0,
      96,    98,   137,   152,   219,   222,   264
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -188,    15,  -188,  -188,  -188,   -40,   -10,   -11,   203,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,   222,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -163,  -188,  -160,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -187,  -188,  -188,  -188,   -52,  -188,  -188
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    99,   217,   218,   100,   101,   102,   103,   277,   114,
     115,   116,    52,    53,    54,   252,   253,   254,    58,    59,
      60,   235,   104,   105,   106,   119,   120,   121,   126,   127,
     128,   165,   166,   167,   149,   150,   152,   153,   154,   157,
     158,   159,   134,   135,   136,   141,   145,   174,   142,   169,
     170,   171,   443,   468,   445,   469,   138,   393,   394,   184,
      46,   146,    47,   317,    48,   188,    49,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     118,   316,   183,   108,   137,    50,   250,   256,   258,   260,
     262,   109,    68,   160,   236,   237,   155,   163,   238,   176,
     239,   240,   241,   242,   243,   244,   117,     3,   110,   179,
     221,   210,   428,    68,   227,   122,   139,   140,   107,   193,
     228,   436,   371,   296,   196,   198,   200,   123,   124,   429,
     206,   372,   373,   178,   265,   266,   111,   112,    55,   151,
     437,   374,   267,    56,   382,   192,   268,   269,   462,   164,
     195,   197,   199,   383,   384,   270,   452,   430,   431,   156,
     211,   212,   213,   385,   271,   463,   272,   273,   161,   214,
     215,   216,   297,   230,   231,   274,   275,   177,   125,   143,
     185,   245,   144,    57,   168,   172,   276,   186,   173,   246,
     162,   290,   175,   464,   465,   180,   230,   247,   147,   148,
     293,   189,   113,   255,    51,   251,   257,   259,   261,   263,
     405,   232,   233,   234,   187,   300,   190,   289,   318,   319,
     302,   367,   368,   191,   304,   194,   292,   129,   130,   131,
     132,   369,   370,   308,   232,   233,   248,   378,   379,   133,
     265,   278,   380,   381,   310,   311,   301,   207,   279,   208,
     303,   222,   280,   281,   223,   314,   315,   224,   225,   307,
     340,   282,   209,   323,   226,   219,   220,   229,   264,    68,
     283,   291,   284,   285,   305,   294,   335,   337,   339,   295,
     298,   286,   287,   299,   309,   312,   313,   306,   320,   322,
     321,   324,   276,   325,   326,   327,   354,   328,   329,   330,
     331,   332,   334,   336,   338,   355,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   333,   357,   353,
     359,   361,   363,   366,   401,   375,   377,   395,   402,   386,
     423,   396,   404,   406,   407,   412,   417,   418,   413,   419,
     414,   415,   416,   420,   421,   352,   422,   376,   442,   424,
     444,   356,   425,   358,   446,   360,   447,   362,   448,   364,
     388,   365,   450,   390,   392,   451,   449,   455,   457,   458,
     466,   454,   459,   460,   398,   467,   461,  -218,   400,  -221,
     478,   403,   479,   481,   480,   485,   387,   482,   486,   389,
     391,   489,   487,   490,   409,   488,   411,   491,   492,   493,
     397,   288,   494,     0,   399,   249,   495,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   408,
       0,   410,     0,   427,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   440,     0,     0,   426,
       0,     0,   432,     0,   433,   441,   434,     0,   435,     0,
       0,   438,     0,   456,     0,     0,     0,     0,     0,     0,
     439,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   453,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   471,   472,     0,   474,     0,
     476,     0,     0,   477,     0,     0,     0,     0,     0,     4,
       0,     0,     0,     0,     0,     0,   484,     0,     0,     0,
       0,   470,     0,   473,     0,   475,     5,     6,     0,     7,
       0,     8,     9,     0,    10,    11,     0,     0,   496,     0,
       0,   483,    12,     0,    13,    14,    15,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,    17,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,     0,     0,
       0,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,     0,    27,     0,     0,     0,     0,
      28,     0,    29,    30,    31,    32,    33,    34,    35,     4,
      36,     0,     0,     0,    37,    38,    39,    40,    41,     0,
      42,     0,     0,     0,     0,     0,     5,     6,     0,     7,
       0,     8,     9,     0,    10,    11,     0,     0,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    43,    44,     0,
      45,    16,     0,     0,     0,     0,     0,    17,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,     0,     0,
       0,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,     0,    27,     0,     0,     0,     0,
      28,     0,    29,    30,    31,    32,    33,    34,    35,     0,
      36,     0,   201,     0,    37,    38,    39,    40,    41,     0,
      42,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,    43,    44,     0,
       0,     0,     0,     0,    65,     0,     0,    66,     0,     0,
      67,   202,   203,   204,     0,     0,     0,     0,     0,     0,
       0,     0,   205,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    71,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       0,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    61,     0,     0,     0,     0,     0,
       0,     0,   181,   182,     0,     0,     0,     0,     0,     0,
      62,    63,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,     0,
      66,     0,     0,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,    71,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    61,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,     0,     0,    62,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,     0,     0,    66,
       0,     0,    67,     0,     0,     0,     0,     0,     0,     0,
       0,    68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    61,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,     0,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,     0,     0,    66,     0,
       0,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,    71,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98
};

static const yytype_int16 yycheck[] =
{
      11,   188,    42,    22,    15,    22,    22,    22,    22,    22,
      22,    30,    80,    24,     8,     9,    22,    28,    12,    66,
      14,    15,    16,    17,    18,    19,    11,     0,    47,    40,
      70,    23,    30,    80,   124,    22,   141,   142,    20,    50,
     130,    27,    43,    51,    55,    56,    57,    34,    35,    47,
      61,    52,    43,    38,    22,    23,    75,    76,    24,    22,
      46,    52,    30,    29,    43,    50,    34,    35,    30,    22,
      55,    56,    57,    52,    43,    43,   144,    75,    76,    85,
      72,    73,    74,    52,    52,    47,    54,    55,    88,    81,
      82,    83,   100,    77,    78,    63,    64,   144,    85,   141,
       6,    95,   144,    69,    22,   141,    74,    13,   144,   103,
      88,   122,    66,    75,    76,   141,    77,    78,    34,    35,
     131,     6,   141,   108,   141,   141,   141,   141,   141,   141,
     317,   115,   116,   117,    13,   146,     4,   122,   190,   191,
     151,    54,    55,     4,   155,    22,   131,    40,    41,    42,
      43,    54,    55,   164,   115,   116,   117,    54,    55,    52,
      22,    23,    54,    55,   175,   176,   151,    32,    30,    32,
     155,   123,    34,    35,   120,   186,   187,   123,   124,   164,
     220,    43,    32,   194,   130,   144,    32,   123,    22,    80,
      52,    27,    54,    55,    27,    44,   207,   208,   209,    44,
      40,    63,    64,    40,    32,    13,   117,    67,    27,   194,
      27,    70,    74,    70,    70,    70,    22,    33,    33,    33,
      33,    33,   207,   208,   209,    46,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,    33,    22,   250,
      22,    22,    22,    31,    67,    32,    31,   141,     7,    32,
       7,   141,   100,   141,   141,   144,    33,    33,   144,    33,
     144,   144,   144,    33,    33,   250,    33,   278,   141,    27,
     141,   256,    27,   258,    13,   260,    13,   262,    40,   264,
     291,   266,     7,   294,   295,     7,    40,   141,   141,   141,
       7,    70,    27,    27,   305,     7,   143,     7,   309,     7,
      33,   312,   143,    27,   143,     7,   291,    27,     7,   294,
     295,   113,    33,   143,   325,    33,   327,   143,    33,    33,
     305,   118,   485,    -1,   309,   103,   486,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,
      -1,   326,    -1,   354,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,    -1,   354,
      -1,    -1,   357,    -1,   359,   386,   361,    -1,   363,    -1,
      -1,   366,    -1,   423,    -1,    -1,    -1,    -1,    -1,    -1,
     375,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   402,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   446,   447,    -1,   449,    -1,
     451,    -1,    -1,   454,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,   467,    -1,    -1,    -1,
      -1,   446,    -1,   448,    -1,   450,    20,    21,    -1,    23,
      -1,    25,    26,    -1,    28,    29,    -1,    -1,   489,    -1,
      -1,   466,    36,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    -1,    89,    -1,    -1,    -1,    -1,
      94,    -1,    96,    97,    98,    99,   100,   101,   102,     3,
     104,    -1,    -1,    -1,   108,   109,   110,   111,   112,    -1,
     114,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    23,
      -1,    25,    26,    -1,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    38,    39,    40,   141,   142,    -1,
     144,    45,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    -1,    89,    -1,    -1,    -1,    -1,
      94,    -1,    96,    97,    98,    99,   100,   101,   102,    -1,
     104,    -1,    23,    -1,   108,   109,   110,   111,   112,    -1,
     114,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    68,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      68,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    32,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    68,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    32,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    68,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,   106,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   212,   213,     0,     3,    20,    21,    23,    25,    26,
      28,    29,    36,    38,    39,    40,    45,    51,    56,    57,
      58,    59,    60,    61,    66,    86,    87,    89,    94,    96,
      97,    98,    99,   100,   101,   102,   104,   108,   109,   110,
     111,   112,   114,   141,   142,   144,   205,   207,   209,   211,
      22,   141,   157,   158,   159,    24,    29,    69,   163,   164,
     165,    32,    48,    49,    50,    65,    68,    71,    80,    92,
     105,   106,   107,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   146,
     149,   150,   151,   152,   167,   168,   169,    20,    22,    30,
      47,    75,    76,   141,   154,   155,   156,   146,   152,   170,
     171,   172,    22,    34,    35,    85,   173,   174,   175,    40,
      41,    42,    43,    52,   187,   188,   189,   152,   201,   141,
     142,   190,   193,   141,   144,   191,   206,    34,    35,   179,
     180,    22,   181,   182,   183,    22,    85,   184,   185,   186,
     152,    88,    88,   152,    22,   176,   177,   178,    22,   194,
     195,   196,   141,   144,   192,    66,    66,   144,   146,   152,
     141,    40,    41,   150,   204,     6,    13,    13,   210,     6,
       4,     4,   146,   152,    22,   146,   152,   146,   152,   146,
     152,    23,    72,    73,    74,    83,   152,    32,    32,    32,
      23,    72,    73,    74,    81,    82,    83,   147,   148,   144,
      32,   150,   123,   120,   123,   124,   130,   124,   130,   123,
      77,    78,   115,   116,   117,   166,     8,     9,    12,    14,
      15,    16,    17,    18,    19,    95,   103,    78,   117,   166,
      22,   141,   160,   161,   162,   146,    22,   141,    22,   141,
      22,   141,    22,   141,    22,    22,    23,    30,    34,    35,
      43,    52,    54,    55,    63,    64,    74,   153,    23,    30,
      34,    35,    43,    52,    54,    55,    63,    64,   153,   146,
     152,    27,   146,   152,    44,    44,    51,   100,    40,    40,
     152,   146,   152,   146,   152,    27,    67,   146,   152,    32,
     152,   152,    13,   117,   152,   152,   207,   208,   211,   211,
      27,    27,   146,   152,    70,    70,    70,    70,    33,    33,
      33,    33,    33,    33,   146,   152,   146,   152,   146,   152,
     150,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   146,   152,    22,    46,   146,    22,   146,    22,
     146,    22,   146,    22,   146,   146,    31,    54,    55,    54,
      55,    43,    52,    43,    52,    32,   152,    31,    54,    55,
      54,    55,    43,    52,    43,    52,    32,   146,   152,   146,
     152,   146,   152,   202,   203,   141,   141,   146,   152,   146,
     152,    67,     7,   152,   100,   207,   141,   141,   146,   152,
     146,   152,   144,   144,   144,   144,   144,    33,    33,    33,
      33,    33,    33,     7,    27,    27,   146,   152,    30,    47,
      75,    76,   146,   146,   146,   146,    27,    46,   146,   146,
     152,   152,   141,   197,   141,   199,    13,    13,    40,    40,
       7,     7,   144,   146,    70,   141,   150,   141,   141,    27,
      27,   143,    30,    47,    75,    76,     7,     7,   198,   200,
     146,   152,   152,   146,   152,   146,   152,   152,    33,   143,
     143,    27,    27,   146,   152,     7,     7,    33,    33,   113,
     143,   143,    33,    33,   197,   199,   152
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   145,   146,   147,   147,   147,   147,   147,   147,   147,
     148,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   152,   153,   153,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   155,   155,   155,   155,   155,
     156,   156,   157,   157,   158,   158,   159,   159,   160,   160,
     161,   161,   162,   162,   163,   163,   163,   164,   164,   164,
     165,   165,   166,   166,   166,   167,   167,   167,   168,   168,
     168,   169,   169,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   172,   172,   173,   173,   173,   173,   173,
     174,   174,   175,   175,   176,   177,   178,   178,   179,   179,
     180,   181,   182,   183,   183,   184,   184,   184,   185,   185,
     186,   186,   187,   187,   187,   187,   187,   188,   188,   188,
     189,   189,   190,   190,   190,   190,   190,   190,   191,   191,
     192,   192,   193,   194,   195,   196,   196,   197,   198,   197,
     199,   200,   199,   202,   201,   203,   201,   204,   204,   204,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   206,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   207,   208,   207,   210,   209,   211,   211,   211,
     211,   213,   212
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     1,     4,     4,
       1,     1,     4,     4,     4,     4,     6,     2,     3,     1,
       1,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     2,     3,     4,
       5,     4,     3,     5,     4,     4,     3,     4,     5,     4,
       3,     5,     4,     4,     3,     5,     7,     6,     7,     6,
       1,     1,     3,     4,     3,     4,     1,     1,     3,     4,
       3,     4,     1,     1,     2,     4,     4,     2,     4,     4,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     1,     1,     4,     2,     2,     3,     7,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     2,
       2,     3,     7,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     2,     1,     1,     1,     3,
       2,     3,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     2,     1,     5,     2,     5,
       1,     1,     1,     1,     2,     3,     3,     2,     3,     3,
       1,     1,     0,     3,     3,     5,     5,     5,     1,     1,
       1,     1,     1,     6,     6,     1,     1,     1,     0,     4,
       1,     0,     4,     0,     4,     0,     4,     4,     1,     1,
       2,     2,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     3,     1,     4,     1,     1,
       1,     0,     3,     1,     1,     2,     1,     3,     2,     2,
       5,     5,     6,     1,     8,     2,     2,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     2,     3,     3,     2,
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
#line 2173 "src-generated/ugbc.tab.c"
    break;

  case 3: /* random_definition_simple: BYTE  */
#line 68 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2181 "src-generated/ugbc.tab.c"
    break;

  case 4: /* random_definition_simple: WORD  */
#line 71 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2189 "src-generated/ugbc.tab.c"
    break;

  case 5: /* random_definition_simple: DWORD  */
#line 74 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2197 "src-generated/ugbc.tab.c"
    break;

  case 6: /* random_definition_simple: POSITION  */
#line 77 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2205 "src-generated/ugbc.tab.c"
    break;

  case 7: /* random_definition_simple: COLOR  */
#line 80 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2213 "src-generated/ugbc.tab.c"
    break;

  case 8: /* random_definition_simple: WIDTH  */
#line 83 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2221 "src-generated/ugbc.tab.c"
    break;

  case 9: /* random_definition_simple: HEIGHT  */
#line 86 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2229 "src-generated/ugbc.tab.c"
    break;

  case 10: /* random_definition: random_definition_simple  */
#line 91 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2237 "src-generated/ugbc.tab.c"
    break;

  case 11: /* color_enumeration: BLACK  */
#line 96 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2246 "src-generated/ugbc.tab.c"
    break;

  case 12: /* color_enumeration: WHITE  */
#line 100 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2255 "src-generated/ugbc.tab.c"
    break;

  case 13: /* color_enumeration: RED  */
#line 104 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2264 "src-generated/ugbc.tab.c"
    break;

  case 14: /* color_enumeration: CYAN  */
#line 108 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2273 "src-generated/ugbc.tab.c"
    break;

  case 15: /* color_enumeration: VIOLET  */
#line 112 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2282 "src-generated/ugbc.tab.c"
    break;

  case 16: /* color_enumeration: GREEN  */
#line 116 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2291 "src-generated/ugbc.tab.c"
    break;

  case 17: /* color_enumeration: BLUE  */
#line 120 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2300 "src-generated/ugbc.tab.c"
    break;

  case 18: /* color_enumeration: YELLOW  */
#line 124 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2309 "src-generated/ugbc.tab.c"
    break;

  case 19: /* color_enumeration: ORANGE  */
#line 128 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2318 "src-generated/ugbc.tab.c"
    break;

  case 20: /* color_enumeration: BROWN  */
#line 132 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2327 "src-generated/ugbc.tab.c"
    break;

  case 21: /* color_enumeration: LIGHT RED  */
#line 136 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2336 "src-generated/ugbc.tab.c"
    break;

  case 22: /* color_enumeration: DARK GREY  */
#line 140 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2345 "src-generated/ugbc.tab.c"
    break;

  case 23: /* color_enumeration: GREY  */
#line 144 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2354 "src-generated/ugbc.tab.c"
    break;

  case 24: /* color_enumeration: LIGHT GREEN  */
#line 148 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2363 "src-generated/ugbc.tab.c"
    break;

  case 25: /* color_enumeration: LIGHT BLUE  */
#line 152 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2372 "src-generated/ugbc.tab.c"
    break;

  case 26: /* color_enumeration: LIGHT GREY  */
#line 156 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2381 "src-generated/ugbc.tab.c"
    break;

  case 27: /* color_enumeration: DARK BLUE  */
#line 160 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2390 "src-generated/ugbc.tab.c"
    break;

  case 28: /* color_enumeration: MAGENTA  */
#line 164 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2399 "src-generated/ugbc.tab.c"
    break;

  case 29: /* color_enumeration: PURPLE  */
#line 168 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2408 "src-generated/ugbc.tab.c"
    break;

  case 30: /* color_enumeration: LAVENDER  */
#line 172 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2417 "src-generated/ugbc.tab.c"
    break;

  case 31: /* color_enumeration: GOLD  */
#line 176 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2426 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: TURQUOISE  */
#line 180 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2435 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: TAN  */
#line 184 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2444 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: YELLOW GREEN  */
#line 188 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2453 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: OLIVE GREEN  */
#line 192 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2462 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: PINK  */
#line 196 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2471 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: PEACH  */
#line 200 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2480 "src-generated/ugbc.tab.c"
    break;

  case 38: /* expression: Identifier  */
#line 206 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2488 "src-generated/ugbc.tab.c"
    break;

  case 39: /* expression: IdentifierString  */
#line 209 "src/ugbc.y"
                       { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2496 "src-generated/ugbc.tab.c"
    break;

  case 40: /* expression: Integer  */
#line 212 "src/ugbc.y"
              { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2505 "src-generated/ugbc.tab.c"
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
#line 2517 "src-generated/ugbc.tab.c"
    break;

  case 42: /* expression: OP BYTE CP Integer  */
#line 223 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2526 "src-generated/ugbc.tab.c"
    break;

  case 43: /* expression: OP WORD CP Integer  */
#line 227 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2535 "src-generated/ugbc.tab.c"
    break;

  case 44: /* expression: OP DWORD CP Integer  */
#line 231 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2544 "src-generated/ugbc.tab.c"
    break;

  case 45: /* expression: OP POSITION CP Integer  */
#line 235 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2553 "src-generated/ugbc.tab.c"
    break;

  case 46: /* expression: OP COLOR CP Integer  */
#line 239 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2562 "src-generated/ugbc.tab.c"
    break;

  case 47: /* expression: color_enumeration  */
#line 243 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2570 "src-generated/ugbc.tab.c"
    break;

  case 48: /* expression: PEEK OP direct_integer CP  */
#line 246 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2578 "src-generated/ugbc.tab.c"
    break;

  case 49: /* expression: PEEK OP expressions CP  */
#line 249 "src/ugbc.y"
                             {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 2586 "src-generated/ugbc.tab.c"
    break;

  case 50: /* expression: XPEN  */
#line 252 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 2594 "src-generated/ugbc.tab.c"
    break;

  case 51: /* expression: YPEN  */
#line 255 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 2602 "src-generated/ugbc.tab.c"
    break;

  case 52: /* expression: COLLISION OP direct_integer CP  */
#line 258 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2610 "src-generated/ugbc.tab.c"
    break;

  case 53: /* expression: COLLISION OP expressions CP  */
#line 261 "src/ugbc.y"
                                  {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2618 "src-generated/ugbc.tab.c"
    break;

  case 54: /* expression: HIT OP direct_integer CP  */
#line 264 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2626 "src-generated/ugbc.tab.c"
    break;

  case 55: /* expression: HIT OP expressions CP  */
#line 267 "src/ugbc.y"
                            {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2634 "src-generated/ugbc.tab.c"
    break;

  case 56: /* expression: LEFT OP expression COMMA expression CP  */
#line 270 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2642 "src-generated/ugbc.tab.c"
    break;

  case 57: /* expression: RANDOM random_definition  */
#line 273 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 2650 "src-generated/ugbc.tab.c"
    break;

  case 58: /* expression: OP expressions CP  */
#line 276 "src/ugbc.y"
                        {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 2658 "src-generated/ugbc.tab.c"
    break;

  case 59: /* expression: TRUE  */
#line 279 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 2667 "src-generated/ugbc.tab.c"
    break;

  case 60: /* expression: FALSE  */
#line 283 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 2676 "src-generated/ugbc.tab.c"
    break;

  case 61: /* expression: NOT expression  */
#line 287 "src/ugbc.y"
                     {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2684 "src-generated/ugbc.tab.c"
    break;

  case 62: /* expressions_raw: expression  */
#line 293 "src/ugbc.y"
                 { (yyval.string) = (yyvsp[0].string); }
#line 2690 "src-generated/ugbc.tab.c"
    break;

  case 63: /* expressions_raw: expression PLUS expressions_raw  */
#line 294 "src/ugbc.y"
                                      {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2698 "src-generated/ugbc.tab.c"
    break;

  case 64: /* expressions_raw: expression MINUS expressions_raw  */
#line 297 "src/ugbc.y"
                                       {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2707 "src-generated/ugbc.tab.c"
    break;

  case 65: /* expressions_raw: expression MULTIPLICATION expressions_raw  */
#line 301 "src/ugbc.y"
                                                {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2716 "src-generated/ugbc.tab.c"
    break;

  case 66: /* expressions_raw: expression AND expressions_raw  */
#line 305 "src/ugbc.y"
                                     {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2725 "src-generated/ugbc.tab.c"
    break;

  case 67: /* expressions_raw: expression OR expressions_raw  */
#line 309 "src/ugbc.y"
                                    {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2734 "src-generated/ugbc.tab.c"
    break;

  case 68: /* expressions_raw: expression EQUAL expressions_raw  */
#line 313 "src/ugbc.y"
                                       {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2742 "src-generated/ugbc.tab.c"
    break;

  case 69: /* expressions_raw: expression DISEQUAL expressions_raw  */
#line 316 "src/ugbc.y"
                                          {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2750 "src-generated/ugbc.tab.c"
    break;

  case 70: /* expressions_raw: expression LT expressions_raw  */
#line 319 "src/ugbc.y"
                                    {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2758 "src-generated/ugbc.tab.c"
    break;

  case 71: /* expressions_raw: expression LTE expressions_raw  */
#line 322 "src/ugbc.y"
                                     {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2766 "src-generated/ugbc.tab.c"
    break;

  case 72: /* expressions_raw: expression GT expressions_raw  */
#line 325 "src/ugbc.y"
                                    {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2774 "src-generated/ugbc.tab.c"
    break;

  case 73: /* expressions_raw: expression GTE expressions_raw  */
#line 328 "src/ugbc.y"
                                     {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2782 "src-generated/ugbc.tab.c"
    break;

  case 74: /* expressions: expressions_raw  */
#line 334 "src/ugbc.y"
                    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2790 "src-generated/ugbc.tab.c"
    break;

  case 77: /* bank_definition_simple: AT direct_integer  */
#line 341 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2798 "src-generated/ugbc.tab.c"
    break;

  case 78: /* bank_definition_simple: Identifier AT direct_integer  */
#line 344 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2806 "src-generated/ugbc.tab.c"
    break;

  case 79: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 347 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2814 "src-generated/ugbc.tab.c"
    break;

  case 80: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 350 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2822 "src-generated/ugbc.tab.c"
    break;

  case 81: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 353 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2830 "src-generated/ugbc.tab.c"
    break;

  case 82: /* bank_definition_simple: DATA AT direct_integer  */
#line 356 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2838 "src-generated/ugbc.tab.c"
    break;

  case 83: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 360 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2846 "src-generated/ugbc.tab.c"
    break;

  case 84: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 363 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2854 "src-generated/ugbc.tab.c"
    break;

  case 85: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 366 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2862 "src-generated/ugbc.tab.c"
    break;

  case 86: /* bank_definition_simple: CODE AT direct_integer  */
#line 369 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2870 "src-generated/ugbc.tab.c"
    break;

  case 87: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 373 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2878 "src-generated/ugbc.tab.c"
    break;

  case 88: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 376 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2886 "src-generated/ugbc.tab.c"
    break;

  case 89: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 379 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 2894 "src-generated/ugbc.tab.c"
    break;

  case 90: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 382 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 2902 "src-generated/ugbc.tab.c"
    break;

  case 91: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 386 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 2910 "src-generated/ugbc.tab.c"
    break;

  case 92: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 389 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 2918 "src-generated/ugbc.tab.c"
    break;

  case 93: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 392 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 2926 "src-generated/ugbc.tab.c"
    break;

  case 94: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 395 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 2934 "src-generated/ugbc.tab.c"
    break;

  case 95: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 401 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2942 "src-generated/ugbc.tab.c"
    break;

  case 96: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 404 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 2950 "src-generated/ugbc.tab.c"
    break;

  case 97: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 407 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2958 "src-generated/ugbc.tab.c"
    break;

  case 98: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 410 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 2966 "src-generated/ugbc.tab.c"
    break;

  case 99: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 413 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2974 "src-generated/ugbc.tab.c"
    break;

  case 102: /* raster_definition_simple: Identifier AT direct_integer  */
#line 422 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 2982 "src-generated/ugbc.tab.c"
    break;

  case 103: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 425 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 2990 "src-generated/ugbc.tab.c"
    break;

  case 104: /* raster_definition_expression: Identifier AT expressions  */
#line 430 "src/ugbc.y"
                              {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2998 "src-generated/ugbc.tab.c"
    break;

  case 105: /* raster_definition_expression: AT expressions WITH Identifier  */
#line 433 "src/ugbc.y"
                                   {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3006 "src-generated/ugbc.tab.c"
    break;

  case 108: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 442 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3014 "src-generated/ugbc.tab.c"
    break;

  case 109: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 445 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3022 "src-generated/ugbc.tab.c"
    break;

  case 110: /* next_raster_definition_expression: Identifier AT expressions  */
#line 450 "src/ugbc.y"
                              {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3030 "src-generated/ugbc.tab.c"
    break;

  case 111: /* next_raster_definition_expression: AT expressions WITH Identifier  */
#line 453 "src/ugbc.y"
                                   {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3038 "src-generated/ugbc.tab.c"
    break;

  case 114: /* color_definition_simple: BORDER direct_integer  */
#line 462 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3046 "src-generated/ugbc.tab.c"
    break;

  case 115: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 465 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3054 "src-generated/ugbc.tab.c"
    break;

  case 116: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 468 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3062 "src-generated/ugbc.tab.c"
    break;

  case 117: /* color_definition_expression: BORDER expressions  */
#line 473 "src/ugbc.y"
                       {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3070 "src-generated/ugbc.tab.c"
    break;

  case 118: /* color_definition_expression: BACKGROUND expressions TO expressions  */
#line 476 "src/ugbc.y"
                                          {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3078 "src-generated/ugbc.tab.c"
    break;

  case 119: /* color_definition_expression: SPRITE expressions TO expressions  */
#line 479 "src/ugbc.y"
                                      {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3086 "src-generated/ugbc.tab.c"
    break;

  case 125: /* wait_definition_simple: direct_integer CYCLES  */
#line 493 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3094 "src-generated/ugbc.tab.c"
    break;

  case 126: /* wait_definition_simple: direct_integer TICKS  */
#line 496 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3102 "src-generated/ugbc.tab.c"
    break;

  case 127: /* wait_definition_simple: direct_integer milliseconds  */
#line 499 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3110 "src-generated/ugbc.tab.c"
    break;

  case 128: /* wait_definition_expression: expressions CYCLES  */
#line 504 "src/ugbc.y"
                         {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3118 "src-generated/ugbc.tab.c"
    break;

  case 129: /* wait_definition_expression: expressions TICKS  */
#line 507 "src/ugbc.y"
                        {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3126 "src-generated/ugbc.tab.c"
    break;

  case 130: /* wait_definition_expression: expressions milliseconds  */
#line 510 "src/ugbc.y"
                               {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3134 "src-generated/ugbc.tab.c"
    break;

  case 133: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 520 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3142 "src-generated/ugbc.tab.c"
    break;

  case 134: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 523 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3150 "src-generated/ugbc.tab.c"
    break;

  case 135: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 526 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3158 "src-generated/ugbc.tab.c"
    break;

  case 136: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 529 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3166 "src-generated/ugbc.tab.c"
    break;

  case 137: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 532 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3174 "src-generated/ugbc.tab.c"
    break;

  case 138: /* sprite_definition_simple: direct_integer ENABLE  */
#line 535 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3182 "src-generated/ugbc.tab.c"
    break;

  case 139: /* sprite_definition_simple: direct_integer DISABLE  */
#line 538 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3190 "src-generated/ugbc.tab.c"
    break;

  case 140: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 541 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3198 "src-generated/ugbc.tab.c"
    break;

  case 141: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 544 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3206 "src-generated/ugbc.tab.c"
    break;

  case 142: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 547 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3214 "src-generated/ugbc.tab.c"
    break;

  case 143: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 550 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3222 "src-generated/ugbc.tab.c"
    break;

  case 144: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 553 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3230 "src-generated/ugbc.tab.c"
    break;

  case 145: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 556 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3238 "src-generated/ugbc.tab.c"
    break;

  case 146: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 559 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3246 "src-generated/ugbc.tab.c"
    break;

  case 147: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 562 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3254 "src-generated/ugbc.tab.c"
    break;

  case 148: /* sprite_definition_expression: expressions DATA FROM expressions  */
#line 567 "src/ugbc.y"
                                      {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3262 "src-generated/ugbc.tab.c"
    break;

  case 149: /* sprite_definition_expression: expressions MULTICOLOR  */
#line 570 "src/ugbc.y"
                           {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3270 "src-generated/ugbc.tab.c"
    break;

  case 150: /* sprite_definition_expression: expressions MONOCOLOR  */
#line 573 "src/ugbc.y"
                          {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3278 "src-generated/ugbc.tab.c"
    break;

  case 151: /* sprite_definition_expression: expressions COLOR expressions  */
#line 576 "src/ugbc.y"
                                  {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3286 "src-generated/ugbc.tab.c"
    break;

  case 152: /* sprite_definition_expression: expressions position OP expressions COMMA expressions CP  */
#line 579 "src/ugbc.y"
                                                             {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3294 "src-generated/ugbc.tab.c"
    break;

  case 153: /* sprite_definition_expression: expressions ENABLE  */
#line 582 "src/ugbc.y"
                       {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3302 "src-generated/ugbc.tab.c"
    break;

  case 154: /* sprite_definition_expression: expressions DISABLE  */
#line 585 "src/ugbc.y"
                        {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3310 "src-generated/ugbc.tab.c"
    break;

  case 155: /* sprite_definition_expression: expressions EXPAND VERTICAL  */
#line 588 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3318 "src-generated/ugbc.tab.c"
    break;

  case 156: /* sprite_definition_expression: expressions COMPRESS VERTICAL  */
#line 591 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3326 "src-generated/ugbc.tab.c"
    break;

  case 157: /* sprite_definition_expression: expressions VERTICAL EXPAND  */
#line 594 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3334 "src-generated/ugbc.tab.c"
    break;

  case 158: /* sprite_definition_expression: expressions VERTICAL COMPRESS  */
#line 597 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3342 "src-generated/ugbc.tab.c"
    break;

  case 159: /* sprite_definition_expression: expressions EXPAND HORIZONTAL  */
#line 600 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3350 "src-generated/ugbc.tab.c"
    break;

  case 160: /* sprite_definition_expression: expressions COMPRESS HORIZONTAL  */
#line 603 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3358 "src-generated/ugbc.tab.c"
    break;

  case 161: /* sprite_definition_expression: expressions HORIZONTAL EXPAND  */
#line 606 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3366 "src-generated/ugbc.tab.c"
    break;

  case 162: /* sprite_definition_expression: expressions HORIZONTAL COMPRESS  */
#line 609 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3374 "src-generated/ugbc.tab.c"
    break;

  case 165: /* bitmap_definition_simple: AT direct_integer  */
#line 618 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3382 "src-generated/ugbc.tab.c"
    break;

  case 166: /* bitmap_definition_simple: ENABLE  */
#line 621 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3390 "src-generated/ugbc.tab.c"
    break;

  case 167: /* bitmap_definition_simple: DISABLE  */
#line 624 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 3398 "src-generated/ugbc.tab.c"
    break;

  case 168: /* bitmap_definition_simple: CLEAR  */
#line 627 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 3406 "src-generated/ugbc.tab.c"
    break;

  case 169: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 630 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 3414 "src-generated/ugbc.tab.c"
    break;

  case 170: /* bitmap_definition_expression: AT expressions  */
#line 636 "src/ugbc.y"
                   {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3422 "src-generated/ugbc.tab.c"
    break;

  case 171: /* bitmap_definition_expression: CLEAR WITH expressions  */
#line 639 "src/ugbc.y"
                           {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 3430 "src-generated/ugbc.tab.c"
    break;

  case 174: /* textmap_definition_simple: AT direct_integer  */
#line 649 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3438 "src-generated/ugbc.tab.c"
    break;

  case 175: /* textmap_definition_expression: AT expressions  */
#line 654 "src/ugbc.y"
                   {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3446 "src-generated/ugbc.tab.c"
    break;

  case 178: /* text_definition_simple: ENABLE  */
#line 663 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3454 "src-generated/ugbc.tab.c"
    break;

  case 179: /* text_definition_simple: DISABLE  */
#line 666 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 3462 "src-generated/ugbc.tab.c"
    break;

  case 181: /* tiles_definition_simple: AT direct_integer  */
#line 674 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 3470 "src-generated/ugbc.tab.c"
    break;

  case 182: /* tiles_definition_expression: AT expressions  */
#line 679 "src/ugbc.y"
                   {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 3478 "src-generated/ugbc.tab.c"
    break;

  case 185: /* colormap_definition_simple: AT direct_integer  */
#line 688 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 3486 "src-generated/ugbc.tab.c"
    break;

  case 186: /* colormap_definition_simple: CLEAR  */
#line 691 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 3494 "src-generated/ugbc.tab.c"
    break;

  case 187: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 694 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3502 "src-generated/ugbc.tab.c"
    break;

  case 188: /* colormap_definition_expression: AT expressions  */
#line 699 "src/ugbc.y"
                   {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3510 "src-generated/ugbc.tab.c"
    break;

  case 189: /* colormap_definition_expression: CLEAR WITH expressions ON expressions  */
#line 702 "src/ugbc.y"
                                          {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3518 "src-generated/ugbc.tab.c"
    break;

  case 192: /* screen_definition_simple: ON  */
#line 712 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 3526 "src-generated/ugbc.tab.c"
    break;

  case 193: /* screen_definition_simple: OFF  */
#line 715 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 3534 "src-generated/ugbc.tab.c"
    break;

  case 194: /* screen_definition_simple: ROWS direct_integer  */
#line 718 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 3542 "src-generated/ugbc.tab.c"
    break;

  case 195: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 721 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3550 "src-generated/ugbc.tab.c"
    break;

  case 196: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 724 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3558 "src-generated/ugbc.tab.c"
    break;

  case 197: /* screen_definition_expression: ROWS expressions  */
#line 729 "src/ugbc.y"
                     {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 3566 "src-generated/ugbc.tab.c"
    break;

  case 198: /* screen_definition_expression: VERTICAL SCROLL expressions  */
#line 732 "src/ugbc.y"
                                {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3574 "src-generated/ugbc.tab.c"
    break;

  case 199: /* screen_definition_expression: HORIZONTAL SCROLL expressions  */
#line 735 "src/ugbc.y"
                                  {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3582 "src-generated/ugbc.tab.c"
    break;

  case 203: /* var_definition_simple: Identifier ON Identifier  */
#line 744 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 3590 "src-generated/ugbc.tab.c"
    break;

  case 204: /* var_definition_simple: IdentifierString ON Identifier  */
#line 747 "src/ugbc.y"
                                   {
      variable_define( _environment, (yyvsp[-2].string), VT_STRING, 0 );
  }
#line 3598 "src-generated/ugbc.tab.c"
    break;

  case 205: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 750 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 3606 "src-generated/ugbc.tab.c"
    break;

  case 206: /* var_definition_simple: Identifier ON Identifier ASSIGN expressions  */
#line 753 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 3616 "src-generated/ugbc.tab.c"
    break;

  case 207: /* var_definition_simple: IdentifierString ON Identifier ASSIGN expressions  */
#line 758 "src/ugbc.y"
                                                      {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-4].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 3626 "src-generated/ugbc.tab.c"
    break;

  case 208: /* goto_definition: Identifier  */
#line 765 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 3634 "src-generated/ugbc.tab.c"
    break;

  case 209: /* goto_definition: Integer  */
#line 768 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 3642 "src-generated/ugbc.tab.c"
    break;

  case 210: /* gosub_definition: Identifier  */
#line 774 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 3650 "src-generated/ugbc.tab.c"
    break;

  case 211: /* gosub_definition: Integer  */
#line 777 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 3658 "src-generated/ugbc.tab.c"
    break;

  case 213: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 786 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 3666 "src-generated/ugbc.tab.c"
    break;

  case 214: /* point_definition_expression: AT OP expressions COMMA expressions CP  */
#line 792 "src/ugbc.y"
                                             {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 3674 "src-generated/ugbc.tab.c"
    break;

  case 217: /* on_goto_definition: Identifier  */
#line 801 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 3683 "src-generated/ugbc.tab.c"
    break;

  case 218: /* $@1: %empty  */
#line 805 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 3691 "src-generated/ugbc.tab.c"
    break;

  case 220: /* on_gosub_definition: Identifier  */
#line 810 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 3700 "src-generated/ugbc.tab.c"
    break;

  case 221: /* $@2: %empty  */
#line 814 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 3708 "src-generated/ugbc.tab.c"
    break;

  case 223: /* $@3: %empty  */
#line 819 "src/ugbc.y"
                       {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 3716 "src-generated/ugbc.tab.c"
    break;

  case 225: /* $@4: %empty  */
#line 822 "src/ugbc.y"
                        {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 3724 "src-generated/ugbc.tab.c"
    break;

  case 227: /* every_definition: expression TICKS GOSUB Identifier  */
#line 827 "src/ugbc.y"
                                        {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 3732 "src-generated/ugbc.tab.c"
    break;

  case 228: /* every_definition: ON  */
#line 830 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 3740 "src-generated/ugbc.tab.c"
    break;

  case 229: /* every_definition: OFF  */
#line 833 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 3748 "src-generated/ugbc.tab.c"
    break;

  case 244: /* statement: RANDOMIZE  */
#line 852 "src/ugbc.y"
              {
      randomize( _environment );
  }
#line 3756 "src-generated/ugbc.tab.c"
    break;

  case 245: /* statement: IF expressions THEN  */
#line 855 "src/ugbc.y"
                        {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 3764 "src-generated/ugbc.tab.c"
    break;

  case 246: /* statement: ELSE  */
#line 858 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 3772 "src-generated/ugbc.tab.c"
    break;

  case 247: /* statement: ELSE IF expressions THEN  */
#line 861 "src/ugbc.y"
                             {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 3780 "src-generated/ugbc.tab.c"
    break;

  case 248: /* statement: ENDIF  */
#line 864 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 3788 "src-generated/ugbc.tab.c"
    break;

  case 249: /* statement: DO  */
#line 867 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 3796 "src-generated/ugbc.tab.c"
    break;

  case 250: /* statement: LOOP  */
#line 870 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 3804 "src-generated/ugbc.tab.c"
    break;

  case 251: /* $@5: %empty  */
#line 873 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 3812 "src-generated/ugbc.tab.c"
    break;

  case 252: /* statement: WHILE $@5 expressions  */
#line 875 "src/ugbc.y"
                {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 3820 "src-generated/ugbc.tab.c"
    break;

  case 253: /* statement: WEND  */
#line 878 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 3828 "src-generated/ugbc.tab.c"
    break;

  case 254: /* statement: REPEAT  */
#line 881 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 3836 "src-generated/ugbc.tab.c"
    break;

  case 255: /* statement: UNTIL expressions  */
#line 884 "src/ugbc.y"
                      {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 3844 "src-generated/ugbc.tab.c"
    break;

  case 256: /* statement: EXIT  */
#line 887 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 3852 "src-generated/ugbc.tab.c"
    break;

  case 257: /* statement: EXIT IF expressions  */
#line 890 "src/ugbc.y"
                        {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 3860 "src-generated/ugbc.tab.c"
    break;

  case 258: /* statement: EXIT Integer  */
#line 893 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 3868 "src-generated/ugbc.tab.c"
    break;

  case 259: /* statement: EXIT direct_integer  */
#line 896 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 3876 "src-generated/ugbc.tab.c"
    break;

  case 260: /* statement: EXIT IF expressions COMMA Integer  */
#line 899 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 3884 "src-generated/ugbc.tab.c"
    break;

  case 261: /* statement: EXIT IF expressions COMMA direct_integer  */
#line 902 "src/ugbc.y"
                                             {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 3892 "src-generated/ugbc.tab.c"
    break;

  case 262: /* statement: FOR Identifier ASSIGN expressions TO expressions  */
#line 905 "src/ugbc.y"
                                                     {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 3900 "src-generated/ugbc.tab.c"
    break;

  case 263: /* statement: NEXT  */
#line 908 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 3908 "src-generated/ugbc.tab.c"
    break;

  case 264: /* statement: FOR Identifier ASSIGN expressions TO expressions STEP expressions  */
#line 911 "src/ugbc.y"
                                                                      {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 3916 "src-generated/ugbc.tab.c"
    break;

  case 265: /* statement: BEG GAMELOOP  */
#line 914 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 3924 "src-generated/ugbc.tab.c"
    break;

  case 266: /* statement: END GAMELOOP  */
#line 917 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 3932 "src-generated/ugbc.tab.c"
    break;

  case 267: /* statement: GRAPHIC  */
#line 920 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 3940 "src-generated/ugbc.tab.c"
    break;

  case 268: /* statement: HALT  */
#line 923 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 3948 "src-generated/ugbc.tab.c"
    break;

  case 273: /* statement: RETURN  */
#line 930 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 3956 "src-generated/ugbc.tab.c"
    break;

  case 274: /* statement: POP  */
#line 933 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 3964 "src-generated/ugbc.tab.c"
    break;

  case 275: /* statement: DONE  */
#line 936 "src/ugbc.y"
          {
      return 0;
  }
#line 3972 "src-generated/ugbc.tab.c"
    break;

  case 276: /* statement: Identifier COLON  */
#line 939 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 3980 "src-generated/ugbc.tab.c"
    break;

  case 277: /* statement: Identifier ASSIGN expressions  */
#line 942 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expressions = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expressions->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 3994 "src-generated/ugbc.tab.c"
    break;

  case 278: /* statement: IdentifierString ASSIGN expressions  */
#line 951 "src/ugbc.y"
                                        {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expressions = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 4008 "src-generated/ugbc.tab.c"
    break;

  case 279: /* statement: DEBUG expressions  */
#line 960 "src/ugbc.y"
                      {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 4016 "src-generated/ugbc.tab.c"
    break;

  case 282: /* statements_no_linenumbers: statement  */
#line 968 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 4022 "src-generated/ugbc.tab.c"
    break;

  case 283: /* $@6: %empty  */
#line 969 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 4028 "src-generated/ugbc.tab.c"
    break;

  case 285: /* $@7: %empty  */
#line 973 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 4036 "src-generated/ugbc.tab.c"
    break;

  case 286: /* statements_with_linenumbers: Integer $@7 statements_no_linenumbers  */
#line 975 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 4044 "src-generated/ugbc.tab.c"
    break;

  case 291: /* $@8: %empty  */
#line 987 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 4050 "src-generated/ugbc.tab.c"
    break;


#line 4054 "src-generated/ugbc.tab.c"

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

#line 989 "src/ugbc.y"


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

