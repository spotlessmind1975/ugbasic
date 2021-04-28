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
  YYSYMBOL_String = 142,                   /* String  */
  YYSYMBOL_Integer = 143,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 144,                 /* $accept  */
  YYSYMBOL_direct_integer = 145,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 146, /* random_definition_simple  */
  YYSYMBOL_random_definition = 147,        /* random_definition  */
  YYSYMBOL_color_enumeration = 148,        /* color_enumeration  */
  YYSYMBOL_expression = 149,               /* expression  */
  YYSYMBOL_expressions_raw = 150,          /* expressions_raw  */
  YYSYMBOL_expressions = 151,              /* expressions  */
  YYSYMBOL_position = 152,                 /* position  */
  YYSYMBOL_bank_definition_simple = 153,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 154, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 155,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 156, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 157, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 158,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 159, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 160, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 161,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 162,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 163, /* color_definition_expression  */
  YYSYMBOL_color_definition = 164,         /* color_definition  */
  YYSYMBOL_milliseconds = 165,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 166,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 167, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 168,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 169, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 170, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 171,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 172, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 173, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 174,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 175, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 176, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 177,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 178,   /* text_definition_simple  */
  YYSYMBOL_text_definition = 179,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 180,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 181, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 182,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 183, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 184, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 185,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 186, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 187, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 188,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 189,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 190,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 191,         /* gosub_definition  */
  YYSYMBOL_var_definition = 192,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 193,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 194, /* point_definition_expression  */
  YYSYMBOL_point_definition = 195,         /* point_definition  */
  YYSYMBOL_on_goto_definition = 196,       /* on_goto_definition  */
  YYSYMBOL_197_1 = 197,                    /* $@1  */
  YYSYMBOL_on_gosub_definition = 198,      /* on_gosub_definition  */
  YYSYMBOL_199_2 = 199,                    /* $@2  */
  YYSYMBOL_on_definition = 200,            /* on_definition  */
  YYSYMBOL_201_3 = 201,                    /* $@3  */
  YYSYMBOL_202_4 = 202,                    /* $@4  */
  YYSYMBOL_every_definition = 203,         /* every_definition  */
  YYSYMBOL_statement = 204,                /* statement  */
  YYSYMBOL_205_5 = 205,                    /* $@5  */
  YYSYMBOL_statements_no_linenumbers = 206, /* statements_no_linenumbers  */
  YYSYMBOL_207_6 = 207,                    /* $@6  */
  YYSYMBOL_statements_with_linenumbers = 208, /* statements_with_linenumbers  */
  YYSYMBOL_209_7 = 209,                    /* $@7  */
  YYSYMBOL_statements_complex = 210,       /* statements_complex  */
  YYSYMBOL_program = 211,                  /* program  */
  YYSYMBOL_212_8 = 212                     /* $@8  */
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
#define YYLAST   884

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  144
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  286
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  481

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   398


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
     135,   136,   137,   138,   139,   140,   141,   142,   143
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
     280,   283,   287,   291,   295,   299,   302,   305,   308,   311,
     314,   320,   324,   324,   327,   330,   333,   336,   339,   342,
     346,   349,   352,   355,   359,   362,   365,   368,   372,   375,
     378,   381,   387,   390,   393,   396,   399,   404,   405,   408,
     411,   416,   419,   424,   425,   428,   431,   436,   439,   444,
     445,   448,   451,   454,   459,   462,   465,   470,   471,   474,
     475,   476,   479,   482,   485,   490,   493,   496,   502,   503,
     506,   509,   512,   515,   518,   521,   524,   527,   530,   533,
     536,   539,   542,   545,   548,   553,   556,   559,   562,   565,
     568,   571,   574,   577,   580,   583,   586,   589,   592,   595,
     600,   601,   604,   607,   610,   613,   616,   622,   625,   631,
     632,   635,   640,   645,   646,   649,   652,   657,   660,   665,
     670,   671,   674,   677,   680,   685,   688,   694,   695,   698,
     701,   704,   707,   710,   715,   718,   721,   726,   727,   729,
     730,   733,   736,   743,   746,   752,   755,   761,   764,   770,
     775,   776,   779,   783,   783,   788,   792,   792,   797,   797,
     800,   800,   805,   808,   811,   816,   817,   818,   819,   820,
     821,   822,   823,   824,   825,   826,   827,   828,   829,   830,
     833,   836,   839,   842,   845,   848,   851,   851,   856,   859,
     862,   865,   868,   871,   874,   877,   880,   883,   886,   889,
     892,   895,   898,   901,   904,   905,   906,   907,   908,   911,
     914,   917,   920,   929,   932,   933,   937,   938,   938,   942,
     942,   949,   950,   951,   952,   956,   956
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
  "Identifier", "String", "Integer", "$accept", "direct_integer",
  "random_definition_simple", "random_definition", "color_enumeration",
  "expression", "expressions_raw", "expressions", "position",
  "bank_definition_simple", "bank_definition_with_payload",
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
     395,   396,   397,   398
};
#endif

#define YYPACT_NINF (-182)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-217)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -182,    36,   415,  -182,  -182,   -19,  -182,    13,   271,    30,
     -20,   271,  -182,     6,    20,   741,   -74,   -30,  -182,  -182,
    -182,    69,    49,   -17,   741,    -2,    26,  -182,   741,  -182,
    -182,    86,   101,     9,  -182,  -182,    63,  -182,   -48,  -182,
     741,    -5,   642,    41,  -182,   126,   136,   147,  -182,   271,
     133,  -182,  -182,  -182,   271,   271,   271,  -182,  -182,  -182,
     598,  -182,  -182,   129,   137,   140,    11,    37,   741,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,    58,  -182,
    -182,    14,   -18,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,    61,  -182,  -182,     3,  -182,     7,  -182,    80,
    -182,  -182,  -182,   -16,   106,   -15,   -13,   -10,    -8,   165,
    -182,  -182,  -182,    35,   119,  -182,  -182,  -182,   271,  -182,
    -182,   161,  -182,  -182,  -182,  -182,  -182,   271,   145,   150,
    -182,  -182,  -182,   -21,  -182,   172,  -182,  -182,  -182,  -182,
    -182,   741,  -182,  -182,  -182,  -182,   271,  -182,  -182,  -182,
     271,   186,  -182,  -182,  -182,   148,  -182,  -182,  -182,   271,
    -182,  -182,  -182,   182,  -182,  -182,  -182,  -182,  -182,  -182,
     741,   741,  -182,  -182,  -182,   203,  -182,  -182,   100,  -182,
    -182,   741,   515,  -182,   415,   415,   191,   192,   271,  -182,
    -182,   151,   152,   153,   154,   187,   193,   194,   195,   196,
     197,   271,   271,   271,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,   741,
     741,   741,   741,   741,   741,   741,   741,   741,   741,   741,
    -182,  -182,  -182,   271,   209,  -182,  -182,  -182,   179,   106,
     211,   106,   212,   106,   213,   106,   214,   106,  -182,   106,
     206,  -182,  -182,   109,   111,    21,    23,  -182,  -182,  -182,
     207,   741,   210,  -182,  -182,   113,   121,    45,    53,  -182,
    -182,   215,  -182,  -182,   271,  -182,  -182,   271,   271,  -182,
    -182,    97,  -182,  -182,  -182,  -182,  -182,   271,  -182,  -182,
    -182,   271,   175,   236,   741,   144,  -182,  -182,   515,  -182,
    -182,   104,   108,  -182,  -182,   106,   741,   106,   741,   110,
     112,   114,   115,   116,  -182,   218,   228,   229,   230,   231,
     232,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,   239,   240,   271,     1,  -182,   106,  -182,   106,
    -182,   106,  -182,   106,    -7,  -182,   106,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,   106,  -182,   741,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,   741,  -182,  -182,  -182,
    -182,  -182,  -182,   127,   128,   257,   234,   235,   264,   265,
    -182,   -69,   208,   138,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,   139,   141,  -182,  -182,  -182,  -182,  -182,  -182,
     256,  -182,   260,  -182,   146,    70,  -182,   282,  -182,   284,
     285,  -182,   288,  -182,   271,   106,   741,   106,   741,  -182,
    -182,   741,  -182,  -182,  -182,   155,   157,  -182,   269,  -182,
     273,  -182,   106,   741,   294,   295,  -182,  -182,  -182,  -182,
     275,   276,   198,  -182,  -182,   162,   164,   277,   280,   127,
     128,  -182,  -182,   741,  -182,  -182,  -182,  -182,  -182,  -182,
    -182
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     285,     0,   275,     1,   274,     0,   270,     0,     0,   258,
       0,     0,   263,     0,     0,     0,   199,     0,   245,   249,
     246,     0,     0,     0,     0,     0,     0,   243,     0,   239,
     262,     0,     0,     0,   268,   269,   241,   244,   251,   248,
       0,     0,     0,     0,   279,   276,   281,   283,   286,     0,
       0,   103,   104,   226,     0,     0,     0,   117,   118,   228,
       0,    48,    49,     0,     0,     0,     0,     0,     0,    56,
      57,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,    23,    28,    29,    30,    31,    32,    33,
      36,    37,     0,    38,    39,     0,    45,    59,    71,     0,
     128,   129,   229,     0,     0,     0,     0,     0,     0,     0,
      97,    98,   225,     0,     0,   160,   161,   230,     0,   163,
     164,   165,   169,   170,   231,   189,   190,     0,     0,     0,
     197,   198,   236,     0,   264,     0,   207,   238,   203,   204,
     265,     0,   175,   176,   177,   233,     0,   180,   181,   234,
       0,   183,   187,   188,   235,     0,   260,   261,   273,     0,
     173,   174,   232,     0,   210,   211,   237,   205,   206,   266,
       0,     0,   253,   254,   250,     0,   223,   224,     0,   267,
     271,     0,   275,   277,   275,   275,     0,     0,     0,   111,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     3,     4,     6,     8,     9,
       5,    10,    54,     2,    58,    34,    21,    24,    25,    26,
      27,    22,    35,   119,   122,   120,   121,   123,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,   126,   127,     0,     0,   109,   110,   227,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,     0,
       0,   135,   136,     0,     0,     0,     0,   132,   131,    72,
       0,     0,     0,   150,   151,     0,     0,     0,     0,   147,
     146,     0,   162,   167,     0,   191,   194,     0,     0,   218,
     220,     0,   247,   178,   179,   182,   185,     0,   240,   171,
     172,     0,     0,   252,     0,     0,   272,   280,   275,   282,
     284,     0,     0,    99,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,     0,     0,     0,     0,
       0,    60,    61,    65,    67,    68,    69,    70,    66,    62,
      63,    64,     0,     0,     0,     0,    79,     0,    91,     0,
      83,     0,    87,     0,    75,   133,     0,   140,   139,   144,
     143,   138,   142,   137,   141,     0,   148,     0,   155,   154,
     159,   158,   153,   157,   152,   156,     0,   166,   168,   192,
     195,   193,   196,     0,     0,   200,     0,     0,     0,     0,
     242,     0,     0,     0,   278,   100,   102,   113,   116,   112,
     115,    44,    40,    41,    43,    42,    46,    47,    50,    51,
      52,    53,     0,     0,   105,   107,    76,    89,    81,    84,
      78,    90,    82,    86,     0,     0,   130,     0,   145,     0,
     212,   219,   215,   221,     0,     0,     0,     0,     0,   255,
     256,     0,   222,   106,   108,     0,     0,    92,    77,    88,
      80,    85,     0,     0,     0,     0,   201,   202,   184,   186,
       0,     0,   257,    94,    96,     0,     0,     0,     0,     0,
       0,   208,   209,     0,    93,    95,   134,   149,   214,   217,
     259
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -182,    -3,  -182,  -182,  -182,    -9,   -28,   -11,   201,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,   217,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -152,  -182,  -148,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -181,  -182,  -182,  -182,    -6,  -182,  -182
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    95,   211,   212,    96,    97,    98,    99,   270,   110,
     111,   112,    51,    52,    53,   245,   246,   247,    57,    58,
      59,   228,   100,   101,   102,   115,   116,   117,   122,   123,
     124,   160,   161,   162,   144,   145,   147,   148,   149,   152,
     153,   154,   130,   131,   132,   136,   140,   169,   137,   164,
     165,   166,   431,   454,   433,   455,   134,   383,   384,   179,
      45,   141,    46,   308,    47,   182,    48,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     114,   307,   104,    49,   133,   150,   243,   249,   113,   251,
     105,    67,   253,   155,   255,   229,   230,   158,   171,   231,
     424,   232,   233,   234,   235,   236,   237,   106,   118,   174,
     289,   416,    67,   178,   204,   173,     3,    54,   187,   425,
     119,   120,    55,   190,   192,   194,   186,   180,   417,   200,
     103,   189,   191,   193,   181,   107,   108,   258,   259,   214,
     125,   126,   127,   128,   361,   260,   363,   135,   151,   261,
     262,   146,   129,   362,   439,   364,   418,   419,   263,   290,
     223,   224,    56,   205,   206,   207,   156,   264,   372,   265,
     266,   121,   208,   209,   210,   172,   374,   373,   267,   268,
     448,   248,   238,   142,   143,   375,   220,   283,   159,   269,
     239,   138,   221,   139,   157,   282,   286,   449,   225,   226,
     227,   109,    50,   163,   285,   244,   250,   394,   252,   170,
     292,   254,   183,   256,   216,   294,   175,   217,   218,   296,
     184,   258,   271,   293,   219,   450,   451,   295,   300,   272,
     167,   185,   168,   273,   274,   188,   299,   223,   240,   302,
     303,   201,   275,   357,   358,   359,   360,   368,   369,   202,
     306,   276,   203,   277,   278,   370,   371,   314,   309,   310,
     213,   215,   279,   280,   222,   313,    67,   257,   284,   287,
     326,   328,   330,   269,   288,   225,   226,   241,   325,   327,
     329,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   291,   297,   301,   298,   304,   305,   311,   312,
     319,   315,   316,   317,   318,   345,   320,   321,   322,   323,
     324,   344,   343,   347,   349,   351,   353,   356,   385,   365,
     342,   367,   390,   391,   393,   395,   346,   376,   348,   396,
     350,   406,   352,   401,   354,   402,   355,   403,   404,   405,
     366,   407,   408,   409,   410,   411,   412,   413,   430,   432,
     434,   437,   438,   378,   435,   436,   380,   382,   441,   442,
     443,   377,   444,   445,   379,   381,   387,   446,   447,   452,
     389,   453,  -213,   392,   386,  -216,   465,   463,   388,   464,
     466,   469,   470,    60,   474,   398,   475,   400,   471,   472,
     476,   473,   397,   477,   399,   281,   242,   478,     0,    61,
      62,    63,   479,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   415,     0,     0,    64,     0,     0,    65,
       0,   414,    66,     0,   420,     0,   421,     0,   422,     0,
     423,    67,     0,   426,     0,     0,   428,     0,     0,     0,
       0,     0,   427,     0,     0,   429,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,    69,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   440,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,     0,    94,     0,     0,     0,     4,     0,
       0,     0,     0,   457,     0,   459,     0,   461,     0,     0,
     462,   456,   458,     0,   460,     5,     6,     0,     7,     0,
       8,     9,   468,    10,    11,     0,     0,     0,     0,   467,
       0,    12,     0,    13,    14,    15,     0,     0,     0,     0,
      16,     0,   480,     0,     0,     0,    17,     0,     0,     0,
       0,    18,    19,    20,    21,    22,    23,     0,     0,     0,
       0,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,    27,     0,     0,     0,     0,    28,
       0,    29,    30,    31,    32,    33,    34,    35,     4,    36,
       0,     0,     0,    37,    38,    39,    40,    41,     0,    42,
       0,     0,     0,     0,     0,     5,     6,     0,     7,     0,
       8,     9,     0,    10,    11,     0,     0,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    43,     0,    44,     0,
      16,     0,     0,     0,     0,     0,    17,     0,     0,     0,
       0,    18,    19,    20,    21,    22,    23,     0,     0,     0,
       0,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,    27,     0,     0,     0,     0,    28,
       0,    29,    30,    31,    32,    33,    34,    35,     0,    36,
       0,   195,     0,    37,    38,    39,    40,    41,     0,    42,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    62,    63,     0,
       0,     0,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,     0,    64,     0,     0,    65,     0,     0,    66,
     196,   197,   198,     0,    60,     0,     0,     0,     0,     0,
       0,   199,   176,   177,     0,     0,     0,     0,     0,     0,
      61,    62,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    69,    70,     0,    64,     0,     0,
      65,     0,     0,    66,     0,     0,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,    94,     0,     0,     0,     0,     0,    68,    69,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    60,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,    94,     0,     0,     0,    61,
      62,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,     0,     0,    65,
       0,     0,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,    69,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,     0,    94
};

static const yytype_int16 yycheck[] =
{
      11,   182,    22,    22,    15,    22,    22,    22,    11,    22,
      30,    80,    22,    24,    22,     8,     9,    28,    66,    12,
      27,    14,    15,    16,    17,    18,    19,    47,    22,    40,
      51,    30,    80,    42,    23,    38,     0,    24,    49,    46,
      34,    35,    29,    54,    55,    56,    49,     6,    47,    60,
      20,    54,    55,    56,    13,    75,    76,    22,    23,    68,
      40,    41,    42,    43,    43,    30,    43,   141,    85,    34,
      35,    22,    52,    52,   143,    52,    75,    76,    43,   100,
      77,    78,    69,    72,    73,    74,    88,    52,    43,    54,
      55,    85,    81,    82,    83,   143,    43,    52,    63,    64,
      30,   104,    95,    34,    35,    52,   124,   118,    22,    74,
     103,   141,   130,   143,    88,   118,   127,    47,   115,   116,
     117,   141,   141,    22,   127,   141,   141,   308,   141,    66,
     141,   141,     6,   141,   120,   146,   141,   123,   124,   150,
       4,    22,    23,   146,   130,    75,    76,   150,   159,    30,
     141,     4,   143,    34,    35,    22,   159,    77,    78,   170,
     171,    32,    43,    54,    55,    54,    55,    54,    55,    32,
     181,    52,    32,    54,    55,    54,    55,   188,   184,   185,
     143,   123,    63,    64,   123,   188,    80,    22,    27,    44,
     201,   202,   203,    74,    44,   115,   116,   117,   201,   202,
     203,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,    40,    27,    32,    67,    13,   117,    27,    27,
      33,    70,    70,    70,    70,    46,    33,    33,    33,    33,
      33,    22,   243,    22,    22,    22,    22,    31,   141,    32,
     243,    31,    67,     7,   100,   141,   249,    32,   251,   141,
     253,    33,   255,   143,   257,   143,   259,   143,   143,   143,
     271,    33,    33,    33,    33,    33,    27,    27,   141,   141,
      13,     7,     7,   284,    40,    40,   287,   288,    70,   141,
     141,   284,   141,    27,   287,   288,   297,    27,   142,     7,
     301,     7,     7,   304,   297,     7,    27,   142,   301,   142,
      27,     7,     7,    32,   142,   316,   142,   318,    33,    33,
      33,   113,   315,    33,   317,   114,    99,   469,    -1,    48,
      49,    50,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   344,    -1,    -1,    65,    -1,    -1,    68,
      -1,   344,    71,    -1,   347,    -1,   349,    -1,   351,    -1,
     353,    80,    -1,   356,    -1,    -1,   367,    -1,    -1,    -1,
      -1,    -1,   365,    -1,    -1,   376,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   391,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,    -1,   143,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,   434,    -1,   436,    -1,   438,    -1,    -1,
     441,   434,   435,    -1,   437,    20,    21,    -1,    23,    -1,
      25,    26,   453,    28,    29,    -1,    -1,    -1,    -1,   452,
      -1,    36,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      45,    -1,   473,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    -1,    89,    -1,    -1,    -1,    -1,    94,
      -1,    96,    97,    98,    99,   100,   101,   102,     3,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    23,    -1,
      25,    26,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    38,    39,    40,   141,    -1,   143,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    -1,    89,    -1,    -1,    -1,    -1,    94,
      -1,    96,    97,    98,    99,   100,   101,   102,    -1,   104,
      -1,    23,    -1,   108,   109,   110,   111,   112,    -1,   114,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    68,    -1,    -1,    71,
      72,    73,    74,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,    -1,    65,    -1,    -1,
      68,    -1,    -1,    71,    -1,    -1,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    32,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,   143,    -1,    -1,    -1,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    68,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,    -1,   143
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   211,   212,     0,     3,    20,    21,    23,    25,    26,
      28,    29,    36,    38,    39,    40,    45,    51,    56,    57,
      58,    59,    60,    61,    66,    86,    87,    89,    94,    96,
      97,    98,    99,   100,   101,   102,   104,   108,   109,   110,
     111,   112,   114,   141,   143,   204,   206,   208,   210,    22,
     141,   156,   157,   158,    24,    29,    69,   162,   163,   164,
      32,    48,    49,    50,    65,    68,    71,    80,   105,   106,
     107,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   143,   145,   148,   149,   150,   151,
     166,   167,   168,    20,    22,    30,    47,    75,    76,   141,
     153,   154,   155,   145,   151,   169,   170,   171,    22,    34,
      35,    85,   172,   173,   174,    40,    41,    42,    43,    52,
     186,   187,   188,   151,   200,   141,   189,   192,   141,   143,
     190,   205,    34,    35,   178,   179,    22,   180,   181,   182,
      22,    85,   183,   184,   185,   151,    88,    88,   151,    22,
     175,   176,   177,    22,   193,   194,   195,   141,   143,   191,
      66,    66,   143,   145,   151,   141,    40,    41,   149,   203,
       6,    13,   209,     6,     4,     4,   145,   151,    22,   145,
     151,   145,   151,   145,   151,    23,    72,    73,    74,    83,
     151,    32,    32,    32,    23,    72,    73,    74,    81,    82,
      83,   146,   147,   143,   149,   123,   120,   123,   124,   130,
     124,   130,   123,    77,    78,   115,   116,   117,   165,     8,
       9,    12,    14,    15,    16,    17,    18,    19,    95,   103,
      78,   117,   165,    22,   141,   159,   160,   161,   145,    22,
     141,    22,   141,    22,   141,    22,   141,    22,    22,    23,
      30,    34,    35,    43,    52,    54,    55,    63,    64,    74,
     152,    23,    30,    34,    35,    43,    52,    54,    55,    63,
      64,   152,   145,   151,    27,   145,   151,    44,    44,    51,
     100,    40,   151,   145,   151,   145,   151,    27,    67,   145,
     151,    32,   151,   151,    13,   117,   151,   206,   207,   210,
     210,    27,    27,   145,   151,    70,    70,    70,    70,    33,
      33,    33,    33,    33,    33,   145,   151,   145,   151,   145,
     151,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   145,   151,    22,    46,   145,    22,   145,    22,
     145,    22,   145,    22,   145,   145,    31,    54,    55,    54,
      55,    43,    52,    43,    52,    32,   151,    31,    54,    55,
      54,    55,    43,    52,    43,    52,    32,   145,   151,   145,
     151,   145,   151,   201,   202,   141,   145,   151,   145,   151,
      67,     7,   151,   100,   206,   141,   141,   145,   151,   145,
     151,   143,   143,   143,   143,   143,    33,    33,    33,    33,
      33,    33,    27,    27,   145,   151,    30,    47,    75,    76,
     145,   145,   145,   145,    27,    46,   145,   145,   151,   151,
     141,   196,   141,   198,    13,    40,    40,     7,     7,   143,
     145,    70,   141,   141,   141,    27,    27,   142,    30,    47,
      75,    76,     7,     7,   197,   199,   145,   151,   145,   151,
     145,   151,   151,   142,   142,    27,    27,   145,   151,     7,
       7,    33,    33,   113,   142,   142,    33,    33,   196,   198,
     151
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   144,   145,   146,   146,   146,   146,   146,   146,   146,
     147,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   151,   152,   152,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   154,   154,   154,   154,   154,   155,   155,   156,
     156,   157,   157,   158,   158,   159,   159,   160,   160,   161,
     161,   162,   162,   162,   163,   163,   163,   164,   164,   165,
     165,   165,   166,   166,   166,   167,   167,   167,   168,   168,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     171,   171,   172,   172,   172,   172,   172,   173,   173,   174,
     174,   175,   176,   177,   177,   178,   178,   179,   180,   181,
     182,   182,   183,   183,   183,   184,   184,   185,   185,   186,
     186,   186,   186,   186,   187,   187,   187,   188,   188,   189,
     189,   189,   189,   190,   190,   191,   191,   192,   193,   194,
     195,   195,   196,   197,   196,   198,   199,   198,   201,   200,
     202,   200,   203,   203,   203,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   205,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   206,   207,   206,   209,
     208,   210,   210,   210,   210,   212,   211
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
       3,     5,     5,     1,     1,     1,     1,     1,     6,     6,
       1,     1,     1,     0,     4,     1,     0,     4,     0,     4,
       0,     4,     4,     1,     1,     2,     2,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       3,     1,     4,     1,     1,     1,     0,     3,     1,     1,
       2,     1,     3,     2,     2,     5,     5,     6,     1,     8,
       2,     2,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     2,     3,     2,     1,     0,     1,     0,     4,     0,
       3,     1,     3,     1,     3,     0,     2
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
#line 2126 "src-generated/ugbc.tab.c"
    break;

  case 3: /* random_definition_simple: BYTE  */
#line 67 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2134 "src-generated/ugbc.tab.c"
    break;

  case 4: /* random_definition_simple: WORD  */
#line 70 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2142 "src-generated/ugbc.tab.c"
    break;

  case 5: /* random_definition_simple: DWORD  */
#line 73 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2150 "src-generated/ugbc.tab.c"
    break;

  case 6: /* random_definition_simple: POSITION  */
#line 76 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2158 "src-generated/ugbc.tab.c"
    break;

  case 7: /* random_definition_simple: COLOR  */
#line 79 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2166 "src-generated/ugbc.tab.c"
    break;

  case 8: /* random_definition_simple: WIDTH  */
#line 82 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2174 "src-generated/ugbc.tab.c"
    break;

  case 9: /* random_definition_simple: HEIGHT  */
#line 85 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2182 "src-generated/ugbc.tab.c"
    break;

  case 10: /* random_definition: random_definition_simple  */
#line 90 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2190 "src-generated/ugbc.tab.c"
    break;

  case 11: /* color_enumeration: BLACK  */
#line 95 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2199 "src-generated/ugbc.tab.c"
    break;

  case 12: /* color_enumeration: WHITE  */
#line 99 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2208 "src-generated/ugbc.tab.c"
    break;

  case 13: /* color_enumeration: RED  */
#line 103 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2217 "src-generated/ugbc.tab.c"
    break;

  case 14: /* color_enumeration: CYAN  */
#line 107 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2226 "src-generated/ugbc.tab.c"
    break;

  case 15: /* color_enumeration: VIOLET  */
#line 111 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2235 "src-generated/ugbc.tab.c"
    break;

  case 16: /* color_enumeration: GREEN  */
#line 115 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2244 "src-generated/ugbc.tab.c"
    break;

  case 17: /* color_enumeration: BLUE  */
#line 119 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2253 "src-generated/ugbc.tab.c"
    break;

  case 18: /* color_enumeration: YELLOW  */
#line 123 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2262 "src-generated/ugbc.tab.c"
    break;

  case 19: /* color_enumeration: ORANGE  */
#line 127 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2271 "src-generated/ugbc.tab.c"
    break;

  case 20: /* color_enumeration: BROWN  */
#line 131 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2280 "src-generated/ugbc.tab.c"
    break;

  case 21: /* color_enumeration: LIGHT RED  */
#line 135 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2289 "src-generated/ugbc.tab.c"
    break;

  case 22: /* color_enumeration: DARK GREY  */
#line 139 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2298 "src-generated/ugbc.tab.c"
    break;

  case 23: /* color_enumeration: GREY  */
#line 143 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2307 "src-generated/ugbc.tab.c"
    break;

  case 24: /* color_enumeration: LIGHT GREEN  */
#line 147 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2316 "src-generated/ugbc.tab.c"
    break;

  case 25: /* color_enumeration: LIGHT BLUE  */
#line 151 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2325 "src-generated/ugbc.tab.c"
    break;

  case 26: /* color_enumeration: LIGHT GREY  */
#line 155 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2334 "src-generated/ugbc.tab.c"
    break;

  case 27: /* color_enumeration: DARK BLUE  */
#line 159 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2343 "src-generated/ugbc.tab.c"
    break;

  case 28: /* color_enumeration: MAGENTA  */
#line 163 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2352 "src-generated/ugbc.tab.c"
    break;

  case 29: /* color_enumeration: PURPLE  */
#line 167 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2361 "src-generated/ugbc.tab.c"
    break;

  case 30: /* color_enumeration: LAVENDER  */
#line 171 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2370 "src-generated/ugbc.tab.c"
    break;

  case 31: /* color_enumeration: GOLD  */
#line 175 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2379 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: TURQUOISE  */
#line 179 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2388 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: TAN  */
#line 183 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2397 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: YELLOW GREEN  */
#line 187 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2406 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: OLIVE GREEN  */
#line 191 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2415 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: PINK  */
#line 195 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2424 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: PEACH  */
#line 199 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2433 "src-generated/ugbc.tab.c"
    break;

  case 38: /* expression: Identifier  */
#line 205 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2441 "src-generated/ugbc.tab.c"
    break;

  case 39: /* expression: Integer  */
#line 208 "src/ugbc.y"
              { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2450 "src-generated/ugbc.tab.c"
    break;

  case 40: /* expression: OP BYTE CP Integer  */
#line 212 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2459 "src-generated/ugbc.tab.c"
    break;

  case 41: /* expression: OP WORD CP Integer  */
#line 216 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2468 "src-generated/ugbc.tab.c"
    break;

  case 42: /* expression: OP DWORD CP Integer  */
#line 220 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2477 "src-generated/ugbc.tab.c"
    break;

  case 43: /* expression: OP POSITION CP Integer  */
#line 224 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2486 "src-generated/ugbc.tab.c"
    break;

  case 44: /* expression: OP COLOR CP Integer  */
#line 228 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2495 "src-generated/ugbc.tab.c"
    break;

  case 45: /* expression: color_enumeration  */
#line 232 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2503 "src-generated/ugbc.tab.c"
    break;

  case 46: /* expression: PEEK OP direct_integer CP  */
#line 235 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2511 "src-generated/ugbc.tab.c"
    break;

  case 47: /* expression: PEEK OP expressions CP  */
#line 238 "src/ugbc.y"
                             {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 2519 "src-generated/ugbc.tab.c"
    break;

  case 48: /* expression: XPEN  */
#line 241 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 2527 "src-generated/ugbc.tab.c"
    break;

  case 49: /* expression: YPEN  */
#line 244 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 2535 "src-generated/ugbc.tab.c"
    break;

  case 50: /* expression: COLLISION OP direct_integer CP  */
#line 247 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2543 "src-generated/ugbc.tab.c"
    break;

  case 51: /* expression: COLLISION OP expressions CP  */
#line 250 "src/ugbc.y"
                                  {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2551 "src-generated/ugbc.tab.c"
    break;

  case 52: /* expression: HIT OP direct_integer CP  */
#line 253 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2559 "src-generated/ugbc.tab.c"
    break;

  case 53: /* expression: HIT OP expressions CP  */
#line 256 "src/ugbc.y"
                            {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2567 "src-generated/ugbc.tab.c"
    break;

  case 54: /* expression: RANDOM random_definition  */
#line 259 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 2575 "src-generated/ugbc.tab.c"
    break;

  case 55: /* expression: OP expressions CP  */
#line 262 "src/ugbc.y"
                        {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 2583 "src-generated/ugbc.tab.c"
    break;

  case 56: /* expression: TRUE  */
#line 265 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 2592 "src-generated/ugbc.tab.c"
    break;

  case 57: /* expression: FALSE  */
#line 269 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 2601 "src-generated/ugbc.tab.c"
    break;

  case 58: /* expression: NOT expression  */
#line 273 "src/ugbc.y"
                     {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2609 "src-generated/ugbc.tab.c"
    break;

  case 59: /* expressions_raw: expression  */
#line 279 "src/ugbc.y"
                 { (yyval.string) = (yyvsp[0].string); }
#line 2615 "src-generated/ugbc.tab.c"
    break;

  case 60: /* expressions_raw: expression PLUS expressions_raw  */
#line 280 "src/ugbc.y"
                                      {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2623 "src-generated/ugbc.tab.c"
    break;

  case 61: /* expressions_raw: expression MINUS expressions_raw  */
#line 283 "src/ugbc.y"
                                       {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2632 "src-generated/ugbc.tab.c"
    break;

  case 62: /* expressions_raw: expression MULTIPLICATION expressions_raw  */
#line 287 "src/ugbc.y"
                                                {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2641 "src-generated/ugbc.tab.c"
    break;

  case 63: /* expressions_raw: expression AND expressions_raw  */
#line 291 "src/ugbc.y"
                                     {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2650 "src-generated/ugbc.tab.c"
    break;

  case 64: /* expressions_raw: expression OR expressions_raw  */
#line 295 "src/ugbc.y"
                                    {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2659 "src-generated/ugbc.tab.c"
    break;

  case 65: /* expressions_raw: expression EQUAL expressions_raw  */
#line 299 "src/ugbc.y"
                                       {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2667 "src-generated/ugbc.tab.c"
    break;

  case 66: /* expressions_raw: expression DISEQUAL expressions_raw  */
#line 302 "src/ugbc.y"
                                          {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2675 "src-generated/ugbc.tab.c"
    break;

  case 67: /* expressions_raw: expression LT expressions_raw  */
#line 305 "src/ugbc.y"
                                    {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2683 "src-generated/ugbc.tab.c"
    break;

  case 68: /* expressions_raw: expression LTE expressions_raw  */
#line 308 "src/ugbc.y"
                                     {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2691 "src-generated/ugbc.tab.c"
    break;

  case 69: /* expressions_raw: expression GT expressions_raw  */
#line 311 "src/ugbc.y"
                                    {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2699 "src-generated/ugbc.tab.c"
    break;

  case 70: /* expressions_raw: expression GTE expressions_raw  */
#line 314 "src/ugbc.y"
                                     {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2707 "src-generated/ugbc.tab.c"
    break;

  case 71: /* expressions: expressions_raw  */
#line 320 "src/ugbc.y"
                    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2715 "src-generated/ugbc.tab.c"
    break;

  case 74: /* bank_definition_simple: AT direct_integer  */
#line 327 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2723 "src-generated/ugbc.tab.c"
    break;

  case 75: /* bank_definition_simple: Identifier AT direct_integer  */
#line 330 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2731 "src-generated/ugbc.tab.c"
    break;

  case 76: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 333 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2739 "src-generated/ugbc.tab.c"
    break;

  case 77: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 336 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2747 "src-generated/ugbc.tab.c"
    break;

  case 78: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 339 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2755 "src-generated/ugbc.tab.c"
    break;

  case 79: /* bank_definition_simple: DATA AT direct_integer  */
#line 342 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2763 "src-generated/ugbc.tab.c"
    break;

  case 80: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 346 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2771 "src-generated/ugbc.tab.c"
    break;

  case 81: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 349 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2779 "src-generated/ugbc.tab.c"
    break;

  case 82: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 352 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2787 "src-generated/ugbc.tab.c"
    break;

  case 83: /* bank_definition_simple: CODE AT direct_integer  */
#line 355 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2795 "src-generated/ugbc.tab.c"
    break;

  case 84: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 359 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2803 "src-generated/ugbc.tab.c"
    break;

  case 85: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 362 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2811 "src-generated/ugbc.tab.c"
    break;

  case 86: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 365 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 2819 "src-generated/ugbc.tab.c"
    break;

  case 87: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 368 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 2827 "src-generated/ugbc.tab.c"
    break;

  case 88: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 372 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 2835 "src-generated/ugbc.tab.c"
    break;

  case 89: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 375 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 2843 "src-generated/ugbc.tab.c"
    break;

  case 90: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 378 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 2851 "src-generated/ugbc.tab.c"
    break;

  case 91: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 381 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 2859 "src-generated/ugbc.tab.c"
    break;

  case 92: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 387 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2867 "src-generated/ugbc.tab.c"
    break;

  case 93: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 390 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 2875 "src-generated/ugbc.tab.c"
    break;

  case 94: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 393 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2883 "src-generated/ugbc.tab.c"
    break;

  case 95: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 396 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 2891 "src-generated/ugbc.tab.c"
    break;

  case 96: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 399 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2899 "src-generated/ugbc.tab.c"
    break;

  case 99: /* raster_definition_simple: Identifier AT direct_integer  */
#line 408 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 2907 "src-generated/ugbc.tab.c"
    break;

  case 100: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 411 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 2915 "src-generated/ugbc.tab.c"
    break;

  case 101: /* raster_definition_expression: Identifier AT expressions  */
#line 416 "src/ugbc.y"
                              {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2923 "src-generated/ugbc.tab.c"
    break;

  case 102: /* raster_definition_expression: AT expressions WITH Identifier  */
#line 419 "src/ugbc.y"
                                   {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2931 "src-generated/ugbc.tab.c"
    break;

  case 105: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 428 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 2939 "src-generated/ugbc.tab.c"
    break;

  case 106: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 431 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 2947 "src-generated/ugbc.tab.c"
    break;

  case 107: /* next_raster_definition_expression: Identifier AT expressions  */
#line 436 "src/ugbc.y"
                              {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 2955 "src-generated/ugbc.tab.c"
    break;

  case 108: /* next_raster_definition_expression: AT expressions WITH Identifier  */
#line 439 "src/ugbc.y"
                                   {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2963 "src-generated/ugbc.tab.c"
    break;

  case 111: /* color_definition_simple: BORDER direct_integer  */
#line 448 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 2971 "src-generated/ugbc.tab.c"
    break;

  case 112: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 451 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 2979 "src-generated/ugbc.tab.c"
    break;

  case 113: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 454 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 2987 "src-generated/ugbc.tab.c"
    break;

  case 114: /* color_definition_expression: BORDER expressions  */
#line 459 "src/ugbc.y"
                       {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 2995 "src-generated/ugbc.tab.c"
    break;

  case 115: /* color_definition_expression: BACKGROUND expressions TO expressions  */
#line 462 "src/ugbc.y"
                                          {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3003 "src-generated/ugbc.tab.c"
    break;

  case 116: /* color_definition_expression: SPRITE expressions TO expressions  */
#line 465 "src/ugbc.y"
                                      {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3011 "src-generated/ugbc.tab.c"
    break;

  case 122: /* wait_definition_simple: direct_integer CYCLES  */
#line 479 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3019 "src-generated/ugbc.tab.c"
    break;

  case 123: /* wait_definition_simple: direct_integer TICKS  */
#line 482 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3027 "src-generated/ugbc.tab.c"
    break;

  case 124: /* wait_definition_simple: direct_integer milliseconds  */
#line 485 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3035 "src-generated/ugbc.tab.c"
    break;

  case 125: /* wait_definition_expression: expressions CYCLES  */
#line 490 "src/ugbc.y"
                         {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3043 "src-generated/ugbc.tab.c"
    break;

  case 126: /* wait_definition_expression: expressions TICKS  */
#line 493 "src/ugbc.y"
                        {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3051 "src-generated/ugbc.tab.c"
    break;

  case 127: /* wait_definition_expression: expressions milliseconds  */
#line 496 "src/ugbc.y"
                               {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3059 "src-generated/ugbc.tab.c"
    break;

  case 130: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 506 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3067 "src-generated/ugbc.tab.c"
    break;

  case 131: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 509 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3075 "src-generated/ugbc.tab.c"
    break;

  case 132: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 512 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3083 "src-generated/ugbc.tab.c"
    break;

  case 133: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 515 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3091 "src-generated/ugbc.tab.c"
    break;

  case 134: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 518 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3099 "src-generated/ugbc.tab.c"
    break;

  case 135: /* sprite_definition_simple: direct_integer ENABLE  */
#line 521 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3107 "src-generated/ugbc.tab.c"
    break;

  case 136: /* sprite_definition_simple: direct_integer DISABLE  */
#line 524 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3115 "src-generated/ugbc.tab.c"
    break;

  case 137: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 527 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3123 "src-generated/ugbc.tab.c"
    break;

  case 138: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 530 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3131 "src-generated/ugbc.tab.c"
    break;

  case 139: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 533 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3139 "src-generated/ugbc.tab.c"
    break;

  case 140: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 536 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3147 "src-generated/ugbc.tab.c"
    break;

  case 141: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 539 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3155 "src-generated/ugbc.tab.c"
    break;

  case 142: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 542 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3163 "src-generated/ugbc.tab.c"
    break;

  case 143: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 545 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3171 "src-generated/ugbc.tab.c"
    break;

  case 144: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 548 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3179 "src-generated/ugbc.tab.c"
    break;

  case 145: /* sprite_definition_expression: expressions DATA FROM expressions  */
#line 553 "src/ugbc.y"
                                      {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3187 "src-generated/ugbc.tab.c"
    break;

  case 146: /* sprite_definition_expression: expressions MULTICOLOR  */
#line 556 "src/ugbc.y"
                           {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3195 "src-generated/ugbc.tab.c"
    break;

  case 147: /* sprite_definition_expression: expressions MONOCOLOR  */
#line 559 "src/ugbc.y"
                          {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3203 "src-generated/ugbc.tab.c"
    break;

  case 148: /* sprite_definition_expression: expressions COLOR expressions  */
#line 562 "src/ugbc.y"
                                  {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3211 "src-generated/ugbc.tab.c"
    break;

  case 149: /* sprite_definition_expression: expressions position OP expressions COMMA expressions CP  */
#line 565 "src/ugbc.y"
                                                             {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3219 "src-generated/ugbc.tab.c"
    break;

  case 150: /* sprite_definition_expression: expressions ENABLE  */
#line 568 "src/ugbc.y"
                       {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3227 "src-generated/ugbc.tab.c"
    break;

  case 151: /* sprite_definition_expression: expressions DISABLE  */
#line 571 "src/ugbc.y"
                        {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3235 "src-generated/ugbc.tab.c"
    break;

  case 152: /* sprite_definition_expression: expressions EXPAND VERTICAL  */
#line 574 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3243 "src-generated/ugbc.tab.c"
    break;

  case 153: /* sprite_definition_expression: expressions COMPRESS VERTICAL  */
#line 577 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3251 "src-generated/ugbc.tab.c"
    break;

  case 154: /* sprite_definition_expression: expressions VERTICAL EXPAND  */
#line 580 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3259 "src-generated/ugbc.tab.c"
    break;

  case 155: /* sprite_definition_expression: expressions VERTICAL COMPRESS  */
#line 583 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3267 "src-generated/ugbc.tab.c"
    break;

  case 156: /* sprite_definition_expression: expressions EXPAND HORIZONTAL  */
#line 586 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3275 "src-generated/ugbc.tab.c"
    break;

  case 157: /* sprite_definition_expression: expressions COMPRESS HORIZONTAL  */
#line 589 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3283 "src-generated/ugbc.tab.c"
    break;

  case 158: /* sprite_definition_expression: expressions HORIZONTAL EXPAND  */
#line 592 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3291 "src-generated/ugbc.tab.c"
    break;

  case 159: /* sprite_definition_expression: expressions HORIZONTAL COMPRESS  */
#line 595 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3299 "src-generated/ugbc.tab.c"
    break;

  case 162: /* bitmap_definition_simple: AT direct_integer  */
#line 604 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3307 "src-generated/ugbc.tab.c"
    break;

  case 163: /* bitmap_definition_simple: ENABLE  */
#line 607 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3315 "src-generated/ugbc.tab.c"
    break;

  case 164: /* bitmap_definition_simple: DISABLE  */
#line 610 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 3323 "src-generated/ugbc.tab.c"
    break;

  case 165: /* bitmap_definition_simple: CLEAR  */
#line 613 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 3331 "src-generated/ugbc.tab.c"
    break;

  case 166: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 616 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 3339 "src-generated/ugbc.tab.c"
    break;

  case 167: /* bitmap_definition_expression: AT expressions  */
#line 622 "src/ugbc.y"
                   {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3347 "src-generated/ugbc.tab.c"
    break;

  case 168: /* bitmap_definition_expression: CLEAR WITH expressions  */
#line 625 "src/ugbc.y"
                           {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 3355 "src-generated/ugbc.tab.c"
    break;

  case 171: /* textmap_definition_simple: AT direct_integer  */
#line 635 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3363 "src-generated/ugbc.tab.c"
    break;

  case 172: /* textmap_definition_expression: AT expressions  */
#line 640 "src/ugbc.y"
                   {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3371 "src-generated/ugbc.tab.c"
    break;

  case 175: /* text_definition_simple: ENABLE  */
#line 649 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3379 "src-generated/ugbc.tab.c"
    break;

  case 176: /* text_definition_simple: DISABLE  */
#line 652 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 3387 "src-generated/ugbc.tab.c"
    break;

  case 178: /* tiles_definition_simple: AT direct_integer  */
#line 660 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 3395 "src-generated/ugbc.tab.c"
    break;

  case 179: /* tiles_definition_expression: AT expressions  */
#line 665 "src/ugbc.y"
                   {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 3403 "src-generated/ugbc.tab.c"
    break;

  case 182: /* colormap_definition_simple: AT direct_integer  */
#line 674 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 3411 "src-generated/ugbc.tab.c"
    break;

  case 183: /* colormap_definition_simple: CLEAR  */
#line 677 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 3419 "src-generated/ugbc.tab.c"
    break;

  case 184: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 680 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3427 "src-generated/ugbc.tab.c"
    break;

  case 185: /* colormap_definition_expression: AT expressions  */
#line 685 "src/ugbc.y"
                   {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3435 "src-generated/ugbc.tab.c"
    break;

  case 186: /* colormap_definition_expression: CLEAR WITH expressions ON expressions  */
#line 688 "src/ugbc.y"
                                          {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3443 "src-generated/ugbc.tab.c"
    break;

  case 189: /* screen_definition_simple: ON  */
#line 698 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 3451 "src-generated/ugbc.tab.c"
    break;

  case 190: /* screen_definition_simple: OFF  */
#line 701 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 3459 "src-generated/ugbc.tab.c"
    break;

  case 191: /* screen_definition_simple: ROWS direct_integer  */
#line 704 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 3467 "src-generated/ugbc.tab.c"
    break;

  case 192: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 707 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3475 "src-generated/ugbc.tab.c"
    break;

  case 193: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 710 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3483 "src-generated/ugbc.tab.c"
    break;

  case 194: /* screen_definition_expression: ROWS expressions  */
#line 715 "src/ugbc.y"
                     {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 3491 "src-generated/ugbc.tab.c"
    break;

  case 195: /* screen_definition_expression: VERTICAL SCROLL expressions  */
#line 718 "src/ugbc.y"
                                {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3499 "src-generated/ugbc.tab.c"
    break;

  case 196: /* screen_definition_expression: HORIZONTAL SCROLL expressions  */
#line 721 "src/ugbc.y"
                                  {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3507 "src-generated/ugbc.tab.c"
    break;

  case 200: /* var_definition_simple: Identifier ON Identifier  */
#line 730 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 3515 "src-generated/ugbc.tab.c"
    break;

  case 201: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 733 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 3523 "src-generated/ugbc.tab.c"
    break;

  case 202: /* var_definition_simple: Identifier ON Identifier ASSIGN expressions  */
#line 736 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 3533 "src-generated/ugbc.tab.c"
    break;

  case 203: /* goto_definition: Identifier  */
#line 743 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 3541 "src-generated/ugbc.tab.c"
    break;

  case 204: /* goto_definition: Integer  */
#line 746 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 3549 "src-generated/ugbc.tab.c"
    break;

  case 205: /* gosub_definition: Identifier  */
#line 752 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 3557 "src-generated/ugbc.tab.c"
    break;

  case 206: /* gosub_definition: Integer  */
#line 755 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 3565 "src-generated/ugbc.tab.c"
    break;

  case 208: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 764 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 3573 "src-generated/ugbc.tab.c"
    break;

  case 209: /* point_definition_expression: AT OP expressions COMMA expressions CP  */
#line 770 "src/ugbc.y"
                                             {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 3581 "src-generated/ugbc.tab.c"
    break;

  case 212: /* on_goto_definition: Identifier  */
#line 779 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 3590 "src-generated/ugbc.tab.c"
    break;

  case 213: /* $@1: %empty  */
#line 783 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 3598 "src-generated/ugbc.tab.c"
    break;

  case 215: /* on_gosub_definition: Identifier  */
#line 788 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 3607 "src-generated/ugbc.tab.c"
    break;

  case 216: /* $@2: %empty  */
#line 792 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 3615 "src-generated/ugbc.tab.c"
    break;

  case 218: /* $@3: %empty  */
#line 797 "src/ugbc.y"
                       {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 3623 "src-generated/ugbc.tab.c"
    break;

  case 220: /* $@4: %empty  */
#line 800 "src/ugbc.y"
                        {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 3631 "src-generated/ugbc.tab.c"
    break;

  case 222: /* every_definition: expression TICKS GOSUB Identifier  */
#line 805 "src/ugbc.y"
                                        {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 3639 "src-generated/ugbc.tab.c"
    break;

  case 223: /* every_definition: ON  */
#line 808 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 3647 "src-generated/ugbc.tab.c"
    break;

  case 224: /* every_definition: OFF  */
#line 811 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 3655 "src-generated/ugbc.tab.c"
    break;

  case 239: /* statement: RANDOMIZE  */
#line 830 "src/ugbc.y"
              {
      randomize( _environment );
  }
#line 3663 "src-generated/ugbc.tab.c"
    break;

  case 240: /* statement: IF expressions THEN  */
#line 833 "src/ugbc.y"
                        {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 3671 "src-generated/ugbc.tab.c"
    break;

  case 241: /* statement: ELSE  */
#line 836 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 3679 "src-generated/ugbc.tab.c"
    break;

  case 242: /* statement: ELSE IF expressions THEN  */
#line 839 "src/ugbc.y"
                             {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 3687 "src-generated/ugbc.tab.c"
    break;

  case 243: /* statement: ENDIF  */
#line 842 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 3695 "src-generated/ugbc.tab.c"
    break;

  case 244: /* statement: DO  */
#line 845 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 3703 "src-generated/ugbc.tab.c"
    break;

  case 245: /* statement: LOOP  */
#line 848 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 3711 "src-generated/ugbc.tab.c"
    break;

  case 246: /* $@5: %empty  */
#line 851 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 3719 "src-generated/ugbc.tab.c"
    break;

  case 247: /* statement: WHILE $@5 expressions  */
#line 853 "src/ugbc.y"
                {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 3727 "src-generated/ugbc.tab.c"
    break;

  case 248: /* statement: WEND  */
#line 856 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 3735 "src-generated/ugbc.tab.c"
    break;

  case 249: /* statement: REPEAT  */
#line 859 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 3743 "src-generated/ugbc.tab.c"
    break;

  case 250: /* statement: UNTIL expressions  */
#line 862 "src/ugbc.y"
                      {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 3751 "src-generated/ugbc.tab.c"
    break;

  case 251: /* statement: EXIT  */
#line 865 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 3759 "src-generated/ugbc.tab.c"
    break;

  case 252: /* statement: EXIT IF expressions  */
#line 868 "src/ugbc.y"
                        {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 3767 "src-generated/ugbc.tab.c"
    break;

  case 253: /* statement: EXIT Integer  */
#line 871 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 3775 "src-generated/ugbc.tab.c"
    break;

  case 254: /* statement: EXIT direct_integer  */
#line 874 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 3783 "src-generated/ugbc.tab.c"
    break;

  case 255: /* statement: EXIT IF expressions COMMA Integer  */
#line 877 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 3791 "src-generated/ugbc.tab.c"
    break;

  case 256: /* statement: EXIT IF expressions COMMA direct_integer  */
#line 880 "src/ugbc.y"
                                             {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 3799 "src-generated/ugbc.tab.c"
    break;

  case 257: /* statement: FOR Identifier ASSIGN expressions TO expressions  */
#line 883 "src/ugbc.y"
                                                     {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 3807 "src-generated/ugbc.tab.c"
    break;

  case 258: /* statement: NEXT  */
#line 886 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 3815 "src-generated/ugbc.tab.c"
    break;

  case 259: /* statement: FOR Identifier ASSIGN expressions TO expressions STEP expressions  */
#line 889 "src/ugbc.y"
                                                                      {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 3823 "src-generated/ugbc.tab.c"
    break;

  case 260: /* statement: BEG GAMELOOP  */
#line 892 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 3831 "src-generated/ugbc.tab.c"
    break;

  case 261: /* statement: END GAMELOOP  */
#line 895 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 3839 "src-generated/ugbc.tab.c"
    break;

  case 262: /* statement: GRAPHIC  */
#line 898 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 3847 "src-generated/ugbc.tab.c"
    break;

  case 263: /* statement: HALT  */
#line 901 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 3855 "src-generated/ugbc.tab.c"
    break;

  case 268: /* statement: RETURN  */
#line 908 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 3863 "src-generated/ugbc.tab.c"
    break;

  case 269: /* statement: POP  */
#line 911 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 3871 "src-generated/ugbc.tab.c"
    break;

  case 270: /* statement: DONE  */
#line 914 "src/ugbc.y"
          {
      return 0;
  }
#line 3879 "src-generated/ugbc.tab.c"
    break;

  case 271: /* statement: Identifier COLON  */
#line 917 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 3887 "src-generated/ugbc.tab.c"
    break;

  case 272: /* statement: Identifier ASSIGN expressions  */
#line 920 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expressions = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expressions->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 3901 "src-generated/ugbc.tab.c"
    break;

  case 273: /* statement: DEBUG expressions  */
#line 929 "src/ugbc.y"
                      {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 3909 "src-generated/ugbc.tab.c"
    break;

  case 276: /* statements_no_linenumbers: statement  */
#line 937 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 3915 "src-generated/ugbc.tab.c"
    break;

  case 277: /* $@6: %empty  */
#line 938 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 3921 "src-generated/ugbc.tab.c"
    break;

  case 279: /* $@7: %empty  */
#line 942 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 3929 "src-generated/ugbc.tab.c"
    break;

  case 280: /* statements_with_linenumbers: Integer $@7 statements_no_linenumbers  */
#line 944 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 3937 "src-generated/ugbc.tab.c"
    break;

  case 285: /* $@8: %empty  */
#line 956 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 3943 "src-generated/ugbc.tab.c"
    break;


#line 3947 "src-generated/ugbc.tab.c"

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

#line 958 "src/ugbc.y"


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

