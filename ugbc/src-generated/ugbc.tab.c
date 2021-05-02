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
  YYSYMBOL_MILLISECOND = 118,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 119,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 120,                    /* TICKS  */
  YYSYMBOL_BLACK = 121,                    /* BLACK  */
  YYSYMBOL_WHITE = 122,                    /* WHITE  */
  YYSYMBOL_RED = 123,                      /* RED  */
  YYSYMBOL_CYAN = 124,                     /* CYAN  */
  YYSYMBOL_VIOLET = 125,                   /* VIOLET  */
  YYSYMBOL_GREEN = 126,                    /* GREEN  */
  YYSYMBOL_BLUE = 127,                     /* BLUE  */
  YYSYMBOL_YELLOW = 128,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 129,                   /* ORANGE  */
  YYSYMBOL_BROWN = 130,                    /* BROWN  */
  YYSYMBOL_LIGHT = 131,                    /* LIGHT  */
  YYSYMBOL_DARK = 132,                     /* DARK  */
  YYSYMBOL_GREY = 133,                     /* GREY  */
  YYSYMBOL_GRAY = 134,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 135,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 136,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 137,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 138,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 139,                /* TURQUOISE  */
  YYSYMBOL_TAN = 140,                      /* TAN  */
  YYSYMBOL_PINK = 141,                     /* PINK  */
  YYSYMBOL_PEACH = 142,                    /* PEACH  */
  YYSYMBOL_OLIVE = 143,                    /* OLIVE  */
  YYSYMBOL_Identifier = 144,               /* Identifier  */
  YYSYMBOL_String = 145,                   /* String  */
  YYSYMBOL_Integer = 146,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 147,                 /* $accept  */
  YYSYMBOL_direct_integer = 148,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 149, /* random_definition_simple  */
  YYSYMBOL_random_definition = 150,        /* random_definition  */
  YYSYMBOL_color_enumeration = 151,        /* color_enumeration  */
  YYSYMBOL_expression = 152,               /* expression  */
  YYSYMBOL_expressions_raw = 153,          /* expressions_raw  */
  YYSYMBOL_expressions = 154,              /* expressions  */
  YYSYMBOL_position = 155,                 /* position  */
  YYSYMBOL_bank_definition_simple = 156,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 157, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 158,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 159, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 160, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 161,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 162, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 163, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 164,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 165,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 166, /* color_definition_expression  */
  YYSYMBOL_color_definition = 167,         /* color_definition  */
  YYSYMBOL_milliseconds = 168,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 169,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 170, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 171,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 172, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 173, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 174,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 175, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 176, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 177,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 178, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 179, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 180,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 181,   /* text_definition_simple  */
  YYSYMBOL_text_definition = 182,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 183,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 184, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 185,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 186, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 187, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 188,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 189, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 190, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 191,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 192,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 193,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 194,         /* gosub_definition  */
  YYSYMBOL_var_definition = 195,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 196,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 197, /* point_definition_expression  */
  YYSYMBOL_point_definition = 198,         /* point_definition  */
  YYSYMBOL_on_goto_definition = 199,       /* on_goto_definition  */
  YYSYMBOL_200_1 = 200,                    /* $@1  */
  YYSYMBOL_on_gosub_definition = 201,      /* on_gosub_definition  */
  YYSYMBOL_202_2 = 202,                    /* $@2  */
  YYSYMBOL_on_definition = 203,            /* on_definition  */
  YYSYMBOL_204_3 = 204,                    /* $@3  */
  YYSYMBOL_205_4 = 205,                    /* $@4  */
  YYSYMBOL_every_definition = 206,         /* every_definition  */
  YYSYMBOL_statement = 207,                /* statement  */
  YYSYMBOL_208_5 = 208,                    /* $@5  */
  YYSYMBOL_statements_no_linenumbers = 209, /* statements_no_linenumbers  */
  YYSYMBOL_210_6 = 210,                    /* $@6  */
  YYSYMBOL_statements_with_linenumbers = 211, /* statements_with_linenumbers  */
  YYSYMBOL_212_7 = 212,                    /* $@7  */
  YYSYMBOL_statements_complex = 213,       /* statements_complex  */
  YYSYMBOL_program = 214,                  /* program  */
  YYSYMBOL_215_8 = 215                     /* $@8  */
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
#define YYLAST   1151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  147
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  301
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  550

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   401


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
     145,   146
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
     282,   285,   288,   291,   294,   298,   302,   308,   309,   312,
     316,   320,   324,   328,   331,   334,   337,   340,   343,   349,
     353,   353,   356,   359,   362,   365,   368,   371,   375,   378,
     381,   384,   388,   391,   394,   397,   401,   404,   407,   410,
     416,   419,   422,   425,   428,   433,   434,   437,   440,   445,
     448,   453,   454,   457,   460,   465,   468,   473,   474,   477,
     480,   483,   488,   491,   494,   499,   500,   503,   504,   505,
     508,   511,   514,   519,   522,   525,   531,   532,   535,   538,
     541,   544,   547,   550,   553,   556,   559,   562,   565,   568,
     571,   574,   577,   582,   585,   588,   591,   594,   597,   600,
     603,   606,   609,   612,   615,   618,   621,   624,   629,   630,
     633,   636,   639,   642,   645,   651,   654,   660,   661,   664,
     669,   674,   675,   678,   681,   686,   689,   694,   699,   700,
     703,   706,   709,   714,   717,   723,   724,   727,   730,   733,
     736,   739,   744,   747,   750,   755,   756,   758,   759,   762,
     765,   768,   773,   780,   783,   789,   792,   798,   801,   807,
     812,   813,   816,   820,   820,   825,   829,   829,   834,   834,
     837,   837,   842,   845,   848,   853,   854,   855,   856,   857,
     858,   859,   860,   861,   862,   863,   864,   865,   866,   867,
     870,   873,   876,   879,   882,   885,   888,   888,   893,   896,
     899,   902,   905,   908,   911,   914,   917,   920,   923,   926,
     929,   932,   935,   938,   941,   942,   943,   944,   945,   948,
     951,   954,   957,   960,   963,   966,   969,   978,   987,   990,
     991,   995,   996,   996,  1000,  1000,  1007,  1008,  1009,  1010,
    1014,  1014
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
  "UNTIL", "FOR", "STEP", "EVERY", "MID", "INSTR", "MILLISECOND",
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
     395,   396,   397,   398,   399,   400,   401
};
#endif

#define YYPACT_NINF (-194)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-227)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -194,    22,   504,  -194,  -194,   -21,  -194,    19,   904,    59,
     -16,   904,  -194,    -7,    55,  1005,  -107,  -121,  -194,  -194,
    -194,    27,    91,    -3,  1005,     1,    33,  -194,   100,   109,
    1005,  -194,  -194,   130,   131,   -68,  -194,  -194,    89,  -194,
     -64,  -194,  1005,    13,   803,   126,    30,  -194,   155,   158,
     159,  -194,   904,   142,  -194,  -194,  -194,   904,   904,   904,
    -194,  -194,  -194,   689,  -194,  -194,   133,   134,   135,    18,
      25,   140,   141,  1005,  -194,  -194,   143,   144,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,    49,  -194,  -194,   -20,  -100,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,    52,
     160,  -194,  -194,    16,  -194,    56,  -194,    26,  -194,  -194,
    -194,   -17,    98,   -15,   -14,   -13,   -12,   163,  -194,  -194,
    -194,   161,   197,  -194,  -194,  -194,   904,  -194,  -194,   154,
    -194,  -194,  -194,  -194,  -194,   904,   145,   146,  -194,  -194,
    -194,   -47,  -194,    -6,  -194,  -194,  -194,  -194,  -194,  1005,
    -194,  -194,  -194,  -194,   904,  -194,  -194,  -194,   904,   165,
    -194,  -194,  -194,   120,  -194,  -194,  1005,  1005,  -194,   904,
    -194,  -194,  -194,   162,  -194,  -194,  -194,  -194,  -194,  -194,
    1005,  1005,  -194,  -194,  -194,   181,  -194,  -194,    79,  -194,
    1005,  -194,  1005,   187,   605,  -194,   504,   504,   173,   178,
     904,  -194,  -194,   136,   139,   147,   148,   179,   188,   189,
     190,   193,   196,   904,   904,   904,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  1005,  1005,  -194,  1005,
    1005,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  1005,  1005,  1005,  1005,
    1005,  1005,  1005,  1005,  1005,  1005,  1005,  -194,  -194,  -194,
     904,   192,  -194,  -194,  -194,   184,    98,   211,    98,   212,
      98,   214,    98,   215,    98,  -194,    98,   207,  -194,  -194,
       3,    61,    65,    66,  -194,  -194,  -194,   213,  1005,   208,
    -194,  -194,    70,    84,    67,    68,  -194,  -194,   218,  -194,
    -194,   904,  -194,  -194,   904,   904,  -194,  -194,   204,   103,
    -194,  -194,  -194,  -194,  -194,   904,  -194,   241,   247,  -194,
    -194,   904,   191,   248,  1005,   156,   249,  -194,  1005,  -194,
     605,  -194,  -194,   114,   116,  -194,  -194,    98,  1005,    98,
    1005,   117,   118,   119,   121,   122,  -194,   232,   235,   236,
     237,   239,   240,   268,   269,   284,   285,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,   270,   272,
     904,   -10,  -194,    98,  -194,    98,  -194,    98,  -194,    98,
       6,  -194,    98,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,    98,  -194,  1005,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  1005,  -194,  -194,  -194,  -194,  -194,  -194,   152,
     164,   167,   289,   265,   266,  1005,  1005,   302,   305,  -194,
     -69,   243,   171,  1005,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  1005,  1005,  1005,  1005,   172,   174,  -194,
    -194,  -194,  -194,  -194,  -194,   291,  -194,   292,  -194,   176,
       8,  -194,   315,  -194,   316,   317,  -194,   318,  -194,   313,
     904,    98,  1005,   294,   297,    98,  1005,  -194,  -194,  1005,
    -194,    11,   298,   301,    17,    23,  -194,  -194,   194,   195,
    -194,   308,  -194,   309,  -194,    98,  1005,   331,   334,  1005,
    -194,  -194,  -194,  -194,   329,   330,   311,   312,   233,  1005,
     335,  -194,  -194,  1005,  -194,  1005,  -194,  -194,  -194,   206,
     209,   319,   321,   152,   164,  -194,  1005,  1005,  -194,  -194,
    1005,   322,  1005,   323,   324,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,   336,  -194,  -194,  -194,  1005,  -194
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     300,     0,   290,     1,   289,     0,   280,     0,     0,   268,
       0,     0,   273,     0,     0,     0,   207,     0,   255,   259,
     256,     0,     0,     0,     0,     0,     0,   253,     0,     0,
       0,   249,   272,     0,     0,     0,   278,   279,   251,   254,
     261,   258,     0,     0,     0,     0,     0,   294,   291,   296,
     298,   301,     0,     0,   111,   112,   236,     0,     0,     0,
     125,   126,   238,     0,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    65,     0,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
      23,    28,    29,    30,    31,    32,    33,    36,    37,     0,
      38,    41,    40,     0,    47,    67,    79,     0,   136,   137,
     239,     0,     0,     0,     0,     0,     0,     0,   105,   106,
     235,     0,     0,   168,   169,   240,     0,   171,   172,   173,
     177,   178,   241,   197,   198,     0,     0,     0,   205,   206,
     246,     0,   274,     0,   217,   248,   213,   214,   275,     0,
     183,   184,   185,   243,     0,   188,   189,   244,     0,   191,
     195,   196,   245,     0,   270,   271,     0,     0,   288,     0,
     181,   182,   242,     0,   220,   221,   247,   215,   216,   276,
       0,     0,   263,   264,   260,     0,   233,   234,     0,   277,
       0,   285,     0,     0,   290,   292,   290,   290,     0,     0,
       0,   119,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     3,     4,     6,
       8,     9,     5,    10,    62,     2,     0,     0,    66,     0,
       0,    34,    21,    24,    25,    26,    27,    22,    35,    39,
     127,   130,   128,   129,   131,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   133,   134,   135,
       0,     0,   117,   118,   237,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,     0,   143,   144,
       0,     0,     0,     0,   140,   139,    80,     0,     0,     0,
     158,   159,     0,     0,     0,     0,   155,   154,     0,   170,
     175,     0,   199,   202,     0,     0,   228,   230,     0,     0,
     257,   186,   187,   190,   193,     0,   250,     0,     0,   179,
     180,     0,     0,   262,     0,     0,     0,   286,     0,   295,
     290,   297,   299,     0,     0,   107,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,    69,    73,
      75,    76,    77,    78,    74,    70,    71,    72,     0,     0,
       0,     0,    87,     0,    99,     0,    91,     0,    95,     0,
      83,   141,     0,   148,   147,   152,   151,   146,   150,   145,
     149,     0,   156,     0,   163,   162,   167,   166,   161,   165,
     160,   164,     0,   174,   176,   200,   203,   201,   204,     0,
       0,     0,   208,     0,     0,     0,     0,     0,     0,   252,
       0,     0,     0,     0,   287,   293,   108,   110,   121,   124,
     120,   123,    46,    42,    43,    45,    44,    48,    49,    52,
      53,    54,    55,     0,     0,     0,     0,     0,     0,   113,
     115,    84,    97,    89,    92,    86,    98,    90,    94,     0,
       0,   138,     0,   153,     0,   222,   229,   225,   231,   209,
       0,     0,     0,     0,     0,     0,     0,   265,   266,     0,
     232,     0,     0,     0,     0,     0,   114,   116,     0,     0,
     100,    85,    96,    88,    93,     0,     0,     0,     0,     0,
     210,   211,   192,   194,     0,     0,     0,     0,   267,     0,
       0,    56,    57,     0,    58,     0,    60,   102,   104,     0,
       0,     0,     0,     0,     0,   212,     0,     0,   218,   219,
       0,     0,     0,     0,     0,   101,   103,   142,   157,   224,
     227,   281,   282,   269,     0,   283,    59,    61,     0,   284
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -194,    29,  -194,  -194,  -194,   -18,    32,   -11,   230,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,   253,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -162,  -194,  -161,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -193,  -194,  -194,  -194,   -46,  -194,  -194
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   103,   223,   224,   104,   105,   106,   107,   287,   118,
     119,   120,    54,    55,    56,   262,   263,   264,    60,    61,
      62,   245,   108,   109,   110,   123,   124,   125,   130,   131,
     132,   170,   171,   172,   152,   153,   155,   156,   157,   160,
     161,   162,   138,   139,   140,   144,   148,   179,   145,   174,
     175,   176,   466,   497,   468,   498,   142,   409,   410,   189,
      48,   149,    49,   330,    50,   194,    51,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     122,   329,    52,   181,   141,   306,   260,   112,   266,   268,
     270,   272,    70,   163,   308,   113,   126,    70,   509,   168,
     158,   451,     3,   146,   513,   147,   188,   236,   127,   128,
     515,   184,   114,   237,   459,   309,   191,   143,   452,   491,
     121,   199,   216,   192,    57,   510,   202,   204,   206,    58,
     193,   514,   212,   460,   307,   228,   492,   516,   383,   384,
     115,   116,   150,   151,   246,   247,   453,   454,   248,   183,
     249,   250,   251,   252,   253,   254,   177,   477,   178,   129,
     111,   198,   182,   159,   493,   494,   201,   203,   205,    59,
     164,   217,   218,   219,   240,   241,   133,   134,   135,   136,
     220,   221,   222,   232,   240,   257,   233,   234,   137,   387,
     389,   398,   400,   235,   154,   300,   385,   386,   388,   390,
     399,   401,   165,    53,   303,   394,   395,   261,   117,   267,
     269,   271,   273,   166,   242,   243,   244,   425,   310,   396,
     397,   265,   167,   312,   242,   243,   258,   314,   317,   318,
     331,   332,   255,   169,   173,   299,   180,   185,   320,   190,
     256,   195,   196,   197,   302,   200,   213,   214,   215,   322,
     323,   225,   326,   226,   227,   231,   229,   230,   238,    70,
     239,   327,   301,   311,   275,   276,   274,   313,   316,   336,
     304,   305,   277,   315,   324,   321,   278,   279,   319,   325,
     328,   333,   348,   350,   352,   280,   334,   337,   353,   354,
     338,   355,   356,   341,   281,   370,   282,   283,   339,   340,
     275,   288,   342,   343,   344,   284,   285,   345,   289,   335,
     346,   371,   290,   291,   373,   375,   286,   377,   379,   382,
     393,   292,   347,   349,   351,   411,   391,   412,   415,   369,
     293,   402,   294,   295,   416,   420,   423,   422,   426,   419,
     427,   296,   297,   432,   433,   434,   437,   435,   436,   438,
     439,   440,   286,   441,   442,   443,   444,   392,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     404,   445,   446,   406,   408,   372,   465,   374,   447,   376,
     448,   378,   470,   380,   414,   381,   471,   472,   467,   475,
     418,   469,   476,   421,   479,   480,   486,   424,   487,   488,
     489,   490,   495,   496,  -223,  -226,   499,   429,   504,   431,
     403,   505,   511,   405,   407,   512,   519,   520,   523,   517,
     518,   524,   526,   527,   413,   528,   529,   530,   532,   548,
     417,   535,   298,   537,   536,   538,   544,   546,   547,   450,
     259,   539,     0,   540,     0,     0,   428,     0,   430,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   463,     0,     0,     0,     0,     0,     0,     0,
       0,   464,     0,     0,     0,     0,     0,   473,   474,   449,
       0,     0,   455,     0,   456,   481,   457,     0,   458,     0,
       0,   461,     0,     0,     0,     0,     0,     0,     0,     0,
     462,     0,     0,     0,     0,   482,   483,   484,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   478,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   501,
       0,   503,     0,     0,     0,   507,     0,     0,   508,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   522,     0,     0,   525,     0,
       0,   531,     0,     0,     0,   533,     0,   534,     0,   500,
     502,     0,     0,     0,   506,     0,     0,     4,     0,     0,
       0,     0,     0,     0,     0,   541,   542,     0,     0,   543,
       0,   545,     0,     0,   521,     5,     6,     0,     7,     0,
       8,     9,     0,    10,    11,     0,     0,   549,     0,     0,
       0,    12,     0,    13,    14,    15,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,    17,     0,     0,     0,
       0,    18,    19,    20,    21,    22,    23,     0,     0,     0,
       0,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,    27,     0,     0,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,     4,    38,
       0,     0,     0,    39,    40,    41,    42,    43,     0,    44,
      45,     0,     0,     0,     0,     0,     5,     6,     0,     7,
       0,     8,     9,     0,    10,    11,     0,     0,     0,     0,
       0,     0,    12,     0,    13,    14,    15,     0,    46,     0,
      47,    16,     0,     0,     0,     0,     0,    17,     0,     0,
       0,     0,    18,    19,    20,    21,    22,    23,     0,     0,
       0,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,     0,    27,     0,     0,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,     0,
      38,     0,     0,   207,    39,    40,    41,    42,    43,     0,
      44,    45,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    65,
      66,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,    67,     0,     0,    68,     0,
       0,    69,   208,   209,   210,     0,     0,     0,     0,     0,
       0,     0,     0,   211,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,    75,     0,     0,
       0,     0,     0,     0,     0,    76,    77,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    63,     0,     0,     0,
       0,     0,     0,     0,   186,   187,     0,     0,     0,     0,
       0,     0,    64,    65,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,     0,    68,     0,     0,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    75,     0,     0,     0,     0,     0,     0,     0,    76,
      77,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    63,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,    64,    65,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,     0,     0,    68,     0,     0,    69,     0,     0,     0,
       0,     0,     0,     0,     0,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    71,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,    75,     0,     0,     0,     0,     0,     0,     0,
      76,    77,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    63,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,    64,    65,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,     0,     0,    68,     0,     0,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    71,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,    75,     0,     0,     0,     0,     0,     0,
       0,    76,    77,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102
};

static const yytype_int16 yycheck[] =
{
      11,   194,    23,    67,    15,    52,    23,    23,    23,    23,
      23,    23,    81,    24,    20,    31,    23,    81,     7,    30,
      23,    31,     0,   144,     7,   146,    44,   127,    35,    36,
       7,    42,    48,   133,    28,    41,     6,   144,    48,    31,
      11,    52,    24,    13,    25,    34,    57,    58,    59,    30,
      20,    34,    63,    47,   101,    73,    48,    34,    55,    56,
      76,    77,    35,    36,     8,     9,    76,    77,    12,    40,
      14,    15,    16,    17,    18,    19,   144,   146,   146,    86,
      21,    52,   146,    86,    76,    77,    57,    58,    59,    70,
      89,    73,    74,    75,    78,    79,    41,    42,    43,    44,
      82,    83,    84,   123,    78,    79,   126,   127,    53,    44,
      44,    44,    44,   133,    23,   126,    55,    56,    53,    53,
      53,    53,    89,   144,   135,    55,    56,   144,   144,   144,
     144,   144,   144,    33,   118,   119,   120,   330,   149,    55,
      56,   112,    33,   154,   118,   119,   120,   158,   166,   167,
     196,   197,    96,    23,    23,   126,    67,   144,   169,    33,
     104,     6,     4,     4,   135,    23,    33,    33,    33,   180,
     181,   146,   190,    33,    33,   126,    33,    33,   126,    81,
      20,   192,    28,   154,    23,    24,    23,   158,    68,   200,
      45,    45,    31,    28,    13,    33,    35,    36,   169,   120,
      13,    28,   213,   214,   215,    44,    28,    71,   226,   227,
      71,   229,   230,    34,    53,    23,    55,    56,    71,    71,
      23,    24,    34,    34,    34,    64,    65,    34,    31,   200,
      34,    47,    35,    36,    23,    23,    75,    23,    23,    32,
      32,    44,   213,   214,   215,    41,    33,   144,     7,   260,
      53,    33,    55,    56,     7,     7,     7,   101,   144,    68,
     144,    64,    65,   146,   146,   146,    34,   146,   146,    34,
      34,    34,    75,    34,    34,     7,     7,   288,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   260,
     301,     7,     7,   304,   305,   266,   144,   268,    28,   270,
      28,   272,    13,   274,   315,   276,    41,    41,   144,     7,
     321,   144,     7,   324,    71,   144,   144,   328,   144,    28,
      28,   145,     7,     7,     7,     7,    13,   338,    34,   340,
     301,    34,    34,   304,   305,    34,    28,    28,     7,   145,
     145,     7,    13,    13,   315,    34,    34,   114,    13,    13,
     321,   145,   122,    34,   145,    34,    34,    34,    34,   370,
     107,   523,    -1,   524,    -1,    -1,   337,    -1,   339,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   393,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   402,    -1,    -1,    -1,    -1,    -1,   415,   416,   370,
      -1,    -1,   373,    -1,   375,   423,   377,    -1,   379,    -1,
      -1,   382,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     391,    -1,    -1,    -1,    -1,   443,   444,   445,   446,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,
      -1,   472,    -1,    -1,    -1,   476,    -1,    -1,   479,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   496,    -1,    -1,   499,    -1,
      -1,   509,    -1,    -1,    -1,   513,    -1,   515,    -1,   470,
     471,    -1,    -1,    -1,   475,    -1,    -1,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   526,   527,    -1,    -1,   530,
      -1,   532,    -1,    -1,   495,    21,    22,    -1,    24,    -1,
      26,    27,    -1,    29,    30,    -1,    -1,   548,    -1,    -1,
      -1,    37,    -1,    39,    40,    41,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    90,    -1,    -1,    93,    94,    95,
      -1,    97,    98,    99,   100,   101,   102,   103,     3,   105,
      -1,    -1,    -1,   109,   110,   111,   112,   113,    -1,   115,
     116,    -1,    -1,    -1,    -1,    -1,    21,    22,    -1,    24,
      -1,    26,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    39,    40,    41,    -1,   144,    -1,
     146,    46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    -1,    90,    -1,    -1,    93,    94,
      95,    -1,    97,    98,    99,   100,   101,   102,   103,    -1,
     105,    -1,    -1,    24,   109,   110,   111,   112,   113,    -1,
     115,   116,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    69,    -1,
      -1,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    69,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,
     107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,    -1,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    33,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
      -1,    -1,    -1,    49,    50,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    69,    -1,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    33,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    -1,    -1,    -1,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    69,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,   117,    -1,    -1,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   214,   215,     0,     3,    21,    22,    24,    26,    27,
      29,    30,    37,    39,    40,    41,    46,    52,    57,    58,
      59,    60,    61,    62,    67,    87,    88,    90,    93,    94,
      95,    97,    98,    99,   100,   101,   102,   103,   105,   109,
     110,   111,   112,   113,   115,   116,   144,   146,   207,   209,
     211,   213,    23,   144,   159,   160,   161,    25,    30,    70,
     165,   166,   167,    33,    49,    50,    51,    66,    69,    72,
      81,    93,    94,   106,   107,   108,   116,   117,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   148,   151,   152,   153,   154,   169,   170,
     171,    21,    23,    31,    48,    76,    77,   144,   156,   157,
     158,   148,   154,   172,   173,   174,    23,    35,    36,    86,
     175,   176,   177,    41,    42,    43,    44,    53,   189,   190,
     191,   154,   203,   144,   192,   195,   144,   146,   193,   208,
      35,    36,   181,   182,    23,   183,   184,   185,    23,    86,
     186,   187,   188,   154,    89,    89,    33,    33,   154,    23,
     178,   179,   180,    23,   196,   197,   198,   144,   146,   194,
      67,    67,   146,   148,   154,   144,    41,    42,   152,   206,
      33,     6,    13,    20,   212,     6,     4,     4,   148,   154,
      23,   148,   154,   148,   154,   148,   154,    24,    73,    74,
      75,    84,   154,    33,    33,    33,    24,    73,    74,    75,
      82,    83,    84,   149,   150,   146,    33,    33,   152,    33,
      33,   126,   123,   126,   127,   133,   127,   133,   126,    20,
      78,    79,   118,   119,   120,   168,     8,     9,    12,    14,
      15,    16,    17,    18,    19,    96,   104,    79,   120,   168,
      23,   144,   162,   163,   164,   148,    23,   144,    23,   144,
      23,   144,    23,   144,    23,    23,    24,    31,    35,    36,
      44,    53,    55,    56,    64,    65,    75,   155,    24,    31,
      35,    36,    44,    53,    55,    56,    64,    65,   155,   148,
     154,    28,   148,   154,    45,    45,    52,   101,    20,    41,
     154,   148,   154,   148,   154,    28,    68,   152,   152,   148,
     154,    33,   154,   154,    13,   120,   152,   154,    13,   209,
     210,   213,   213,    28,    28,   148,   154,    71,    71,    71,
      71,    34,    34,    34,    34,    34,    34,   148,   154,   148,
     154,   148,   154,   152,   152,   152,   152,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   148,   154,
      23,    47,   148,    23,   148,    23,   148,    23,   148,    23,
     148,   148,    32,    55,    56,    55,    56,    44,    53,    44,
      53,    33,   154,    32,    55,    56,    55,    56,    44,    53,
      44,    53,    33,   148,   154,   148,   154,   148,   154,   204,
     205,    41,   144,   148,   154,     7,     7,   148,   154,    68,
       7,   154,   101,     7,   154,   209,   144,   144,   148,   154,
     148,   154,   146,   146,   146,   146,   146,    34,    34,    34,
      34,    34,    34,     7,     7,     7,     7,    28,    28,   148,
     154,    31,    48,    76,    77,   148,   148,   148,   148,    28,
      47,   148,   148,   154,   154,   144,   199,   144,   201,   144,
      13,    41,    41,   152,   152,     7,     7,   146,   148,    71,
     144,   152,   152,   152,   152,   152,   144,   144,    28,    28,
     145,    31,    48,    76,    77,     7,     7,   200,   202,    13,
     148,   154,   148,   154,    34,    34,   148,   154,   154,     7,
      34,    34,    34,     7,    34,     7,    34,   145,   145,    28,
      28,   148,   154,     7,     7,   154,    13,    13,    34,    34,
     114,   152,    13,   152,   152,   145,   145,    34,    34,   199,
     201,   154,   154,   154,    34,   154,    34,    34,    13,   154
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   147,   148,   149,   149,   149,   149,   149,   149,   149,
     150,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   154,
     155,   155,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     157,   157,   157,   157,   157,   158,   158,   159,   159,   160,
     160,   161,   161,   162,   162,   163,   163,   164,   164,   165,
     165,   165,   166,   166,   166,   167,   167,   168,   168,   168,
     169,   169,   169,   170,   170,   170,   171,   171,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   174,   174,
     175,   175,   175,   175,   175,   176,   176,   177,   177,   178,
     179,   180,   180,   181,   181,   182,   183,   184,   185,   185,
     186,   186,   186,   187,   187,   188,   188,   189,   189,   189,
     189,   189,   190,   190,   190,   191,   191,   192,   192,   192,
     192,   192,   192,   193,   193,   194,   194,   195,   196,   197,
     198,   198,   199,   200,   199,   201,   202,   201,   204,   203,
     205,   203,   206,   206,   206,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   208,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   209,   210,   209,   212,   211,   213,   213,   213,   213,
     215,   214
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
       6,     8,     2,     3,     1,     1,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     2,     3,     4,     5,     4,     3,     5,     4,
       4,     3,     4,     5,     4,     3,     5,     4,     4,     3,
       5,     7,     6,     7,     6,     1,     1,     3,     4,     3,
       4,     1,     1,     3,     4,     3,     4,     1,     1,     2,
       4,     4,     2,     4,     4,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     1,     1,     4,     2,
       2,     3,     7,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     2,     2,     3,     7,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       2,     1,     1,     1,     3,     2,     3,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       2,     1,     5,     2,     5,     1,     1,     1,     1,     2,
       3,     3,     2,     3,     3,     1,     1,     0,     3,     4,
       5,     5,     6,     1,     1,     1,     1,     1,     6,     6,
       1,     1,     1,     0,     4,     1,     0,     4,     0,     4,
       0,     4,     4,     1,     1,     2,     2,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       3,     1,     4,     1,     1,     1,     0,     3,     1,     1,
       2,     1,     3,     2,     2,     5,     5,     6,     1,     8,
       2,     2,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     8,     8,     8,    10,     2,     3,     4,     2,     1,
       0,     1,     0,     4,     0,     3,     1,     3,     1,     3,
       0,     2
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
#line 2208 "src-generated/ugbc.tab.c"
    break;

  case 3: /* random_definition_simple: BYTE  */
#line 68 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2216 "src-generated/ugbc.tab.c"
    break;

  case 4: /* random_definition_simple: WORD  */
#line 71 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2224 "src-generated/ugbc.tab.c"
    break;

  case 5: /* random_definition_simple: DWORD  */
#line 74 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2232 "src-generated/ugbc.tab.c"
    break;

  case 6: /* random_definition_simple: POSITION  */
#line 77 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2240 "src-generated/ugbc.tab.c"
    break;

  case 7: /* random_definition_simple: COLOR  */
#line 80 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2248 "src-generated/ugbc.tab.c"
    break;

  case 8: /* random_definition_simple: WIDTH  */
#line 83 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2256 "src-generated/ugbc.tab.c"
    break;

  case 9: /* random_definition_simple: HEIGHT  */
#line 86 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2264 "src-generated/ugbc.tab.c"
    break;

  case 10: /* random_definition: random_definition_simple  */
#line 91 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2272 "src-generated/ugbc.tab.c"
    break;

  case 11: /* color_enumeration: BLACK  */
#line 96 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2281 "src-generated/ugbc.tab.c"
    break;

  case 12: /* color_enumeration: WHITE  */
#line 100 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2290 "src-generated/ugbc.tab.c"
    break;

  case 13: /* color_enumeration: RED  */
#line 104 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2299 "src-generated/ugbc.tab.c"
    break;

  case 14: /* color_enumeration: CYAN  */
#line 108 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2308 "src-generated/ugbc.tab.c"
    break;

  case 15: /* color_enumeration: VIOLET  */
#line 112 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2317 "src-generated/ugbc.tab.c"
    break;

  case 16: /* color_enumeration: GREEN  */
#line 116 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2326 "src-generated/ugbc.tab.c"
    break;

  case 17: /* color_enumeration: BLUE  */
#line 120 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2335 "src-generated/ugbc.tab.c"
    break;

  case 18: /* color_enumeration: YELLOW  */
#line 124 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2344 "src-generated/ugbc.tab.c"
    break;

  case 19: /* color_enumeration: ORANGE  */
#line 128 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2353 "src-generated/ugbc.tab.c"
    break;

  case 20: /* color_enumeration: BROWN  */
#line 132 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2362 "src-generated/ugbc.tab.c"
    break;

  case 21: /* color_enumeration: LIGHT RED  */
#line 136 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2371 "src-generated/ugbc.tab.c"
    break;

  case 22: /* color_enumeration: DARK GREY  */
#line 140 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2380 "src-generated/ugbc.tab.c"
    break;

  case 23: /* color_enumeration: GREY  */
#line 144 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2389 "src-generated/ugbc.tab.c"
    break;

  case 24: /* color_enumeration: LIGHT GREEN  */
#line 148 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2398 "src-generated/ugbc.tab.c"
    break;

  case 25: /* color_enumeration: LIGHT BLUE  */
#line 152 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2407 "src-generated/ugbc.tab.c"
    break;

  case 26: /* color_enumeration: LIGHT GREY  */
#line 156 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2416 "src-generated/ugbc.tab.c"
    break;

  case 27: /* color_enumeration: DARK BLUE  */
#line 160 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2425 "src-generated/ugbc.tab.c"
    break;

  case 28: /* color_enumeration: MAGENTA  */
#line 164 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2434 "src-generated/ugbc.tab.c"
    break;

  case 29: /* color_enumeration: PURPLE  */
#line 168 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2443 "src-generated/ugbc.tab.c"
    break;

  case 30: /* color_enumeration: LAVENDER  */
#line 172 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2452 "src-generated/ugbc.tab.c"
    break;

  case 31: /* color_enumeration: GOLD  */
#line 176 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2461 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: TURQUOISE  */
#line 180 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2470 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: TAN  */
#line 184 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2479 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: YELLOW GREEN  */
#line 188 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2488 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: OLIVE GREEN  */
#line 192 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2497 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: PINK  */
#line 196 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2506 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: PEACH  */
#line 200 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2515 "src-generated/ugbc.tab.c"
    break;

  case 38: /* expression: Identifier  */
#line 206 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2523 "src-generated/ugbc.tab.c"
    break;

  case 39: /* expression: Identifier DOLLAR  */
#line 209 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[-1].string);
      }
#line 2531 "src-generated/ugbc.tab.c"
    break;

  case 40: /* expression: Integer  */
#line 212 "src/ugbc.y"
              { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2540 "src-generated/ugbc.tab.c"
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
#line 2552 "src-generated/ugbc.tab.c"
    break;

  case 42: /* expression: OP BYTE CP Integer  */
#line 223 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2561 "src-generated/ugbc.tab.c"
    break;

  case 43: /* expression: OP WORD CP Integer  */
#line 227 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2570 "src-generated/ugbc.tab.c"
    break;

  case 44: /* expression: OP DWORD CP Integer  */
#line 231 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2579 "src-generated/ugbc.tab.c"
    break;

  case 45: /* expression: OP POSITION CP Integer  */
#line 235 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2588 "src-generated/ugbc.tab.c"
    break;

  case 46: /* expression: OP COLOR CP Integer  */
#line 239 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2597 "src-generated/ugbc.tab.c"
    break;

  case 47: /* expression: color_enumeration  */
#line 243 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2605 "src-generated/ugbc.tab.c"
    break;

  case 48: /* expression: PEEK OP direct_integer CP  */
#line 246 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2613 "src-generated/ugbc.tab.c"
    break;

  case 49: /* expression: PEEK OP expressions CP  */
#line 249 "src/ugbc.y"
                             {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 2621 "src-generated/ugbc.tab.c"
    break;

  case 50: /* expression: XPEN  */
#line 252 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 2629 "src-generated/ugbc.tab.c"
    break;

  case 51: /* expression: YPEN  */
#line 255 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 2637 "src-generated/ugbc.tab.c"
    break;

  case 52: /* expression: COLLISION OP direct_integer CP  */
#line 258 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2645 "src-generated/ugbc.tab.c"
    break;

  case 53: /* expression: COLLISION OP expressions CP  */
#line 261 "src/ugbc.y"
                                  {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2653 "src-generated/ugbc.tab.c"
    break;

  case 54: /* expression: HIT OP direct_integer CP  */
#line 264 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2661 "src-generated/ugbc.tab.c"
    break;

  case 55: /* expression: HIT OP expressions CP  */
#line 267 "src/ugbc.y"
                            {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2669 "src-generated/ugbc.tab.c"
    break;

  case 56: /* expression: LEFT OP expression COMMA expression CP  */
#line 270 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2677 "src-generated/ugbc.tab.c"
    break;

  case 57: /* expression: RIGHT OP expression COMMA expression CP  */
#line 273 "src/ugbc.y"
                                              {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2685 "src-generated/ugbc.tab.c"
    break;

  case 58: /* expression: MID OP expression COMMA expression CP  */
#line 276 "src/ugbc.y"
                                            {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 2693 "src-generated/ugbc.tab.c"
    break;

  case 59: /* expression: MID OP expression COMMA expression COMMA expression CP  */
#line 279 "src/ugbc.y"
                                                             {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2701 "src-generated/ugbc.tab.c"
    break;

  case 60: /* expression: INSTR OP expression COMMA expression CP  */
#line 282 "src/ugbc.y"
                                              {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 2709 "src-generated/ugbc.tab.c"
    break;

  case 61: /* expression: INSTR OP expression COMMA expression COMMA expression CP  */
#line 285 "src/ugbc.y"
                                                               {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 2717 "src-generated/ugbc.tab.c"
    break;

  case 62: /* expression: RANDOM random_definition  */
#line 288 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 2725 "src-generated/ugbc.tab.c"
    break;

  case 63: /* expression: OP expressions CP  */
#line 291 "src/ugbc.y"
                        {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 2733 "src-generated/ugbc.tab.c"
    break;

  case 64: /* expression: TRUE  */
#line 294 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 2742 "src-generated/ugbc.tab.c"
    break;

  case 65: /* expression: FALSE  */
#line 298 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 2751 "src-generated/ugbc.tab.c"
    break;

  case 66: /* expression: NOT expression  */
#line 302 "src/ugbc.y"
                     {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 2759 "src-generated/ugbc.tab.c"
    break;

  case 67: /* expressions_raw: expression  */
#line 308 "src/ugbc.y"
                 { (yyval.string) = (yyvsp[0].string); }
#line 2765 "src-generated/ugbc.tab.c"
    break;

  case 68: /* expressions_raw: expression PLUS expressions_raw  */
#line 309 "src/ugbc.y"
                                      {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2773 "src-generated/ugbc.tab.c"
    break;

  case 69: /* expressions_raw: expression MINUS expressions_raw  */
#line 312 "src/ugbc.y"
                                       {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2782 "src-generated/ugbc.tab.c"
    break;

  case 70: /* expressions_raw: expression MULTIPLICATION expressions_raw  */
#line 316 "src/ugbc.y"
                                                {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2791 "src-generated/ugbc.tab.c"
    break;

  case 71: /* expressions_raw: expression AND expressions_raw  */
#line 320 "src/ugbc.y"
                                     {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2800 "src-generated/ugbc.tab.c"
    break;

  case 72: /* expressions_raw: expression OR expressions_raw  */
#line 324 "src/ugbc.y"
                                    {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2809 "src-generated/ugbc.tab.c"
    break;

  case 73: /* expressions_raw: expression EQUAL expressions_raw  */
#line 328 "src/ugbc.y"
                                       {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2817 "src-generated/ugbc.tab.c"
    break;

  case 74: /* expressions_raw: expression DISEQUAL expressions_raw  */
#line 331 "src/ugbc.y"
                                          {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2825 "src-generated/ugbc.tab.c"
    break;

  case 75: /* expressions_raw: expression LT expressions_raw  */
#line 334 "src/ugbc.y"
                                    {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2833 "src-generated/ugbc.tab.c"
    break;

  case 76: /* expressions_raw: expression LTE expressions_raw  */
#line 337 "src/ugbc.y"
                                     {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2841 "src-generated/ugbc.tab.c"
    break;

  case 77: /* expressions_raw: expression GT expressions_raw  */
#line 340 "src/ugbc.y"
                                    {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2849 "src-generated/ugbc.tab.c"
    break;

  case 78: /* expressions_raw: expression GTE expressions_raw  */
#line 343 "src/ugbc.y"
                                     {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2857 "src-generated/ugbc.tab.c"
    break;

  case 79: /* expressions: expressions_raw  */
#line 349 "src/ugbc.y"
                    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2865 "src-generated/ugbc.tab.c"
    break;

  case 82: /* bank_definition_simple: AT direct_integer  */
#line 356 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2873 "src-generated/ugbc.tab.c"
    break;

  case 83: /* bank_definition_simple: Identifier AT direct_integer  */
#line 359 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2881 "src-generated/ugbc.tab.c"
    break;

  case 84: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 362 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2889 "src-generated/ugbc.tab.c"
    break;

  case 85: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 365 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2897 "src-generated/ugbc.tab.c"
    break;

  case 86: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 368 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2905 "src-generated/ugbc.tab.c"
    break;

  case 87: /* bank_definition_simple: DATA AT direct_integer  */
#line 371 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2913 "src-generated/ugbc.tab.c"
    break;

  case 88: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 375 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2921 "src-generated/ugbc.tab.c"
    break;

  case 89: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 378 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2929 "src-generated/ugbc.tab.c"
    break;

  case 90: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 381 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2937 "src-generated/ugbc.tab.c"
    break;

  case 91: /* bank_definition_simple: CODE AT direct_integer  */
#line 384 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2945 "src-generated/ugbc.tab.c"
    break;

  case 92: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 388 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2953 "src-generated/ugbc.tab.c"
    break;

  case 93: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 391 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2961 "src-generated/ugbc.tab.c"
    break;

  case 94: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 394 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 2969 "src-generated/ugbc.tab.c"
    break;

  case 95: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 397 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 2977 "src-generated/ugbc.tab.c"
    break;

  case 96: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 401 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 2985 "src-generated/ugbc.tab.c"
    break;

  case 97: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 404 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 2993 "src-generated/ugbc.tab.c"
    break;

  case 98: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 407 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3001 "src-generated/ugbc.tab.c"
    break;

  case 99: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 410 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 3009 "src-generated/ugbc.tab.c"
    break;

  case 100: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 416 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3017 "src-generated/ugbc.tab.c"
    break;

  case 101: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 419 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3025 "src-generated/ugbc.tab.c"
    break;

  case 102: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 422 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3033 "src-generated/ugbc.tab.c"
    break;

  case 103: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 425 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 3041 "src-generated/ugbc.tab.c"
    break;

  case 104: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 428 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 3049 "src-generated/ugbc.tab.c"
    break;

  case 107: /* raster_definition_simple: Identifier AT direct_integer  */
#line 437 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 3057 "src-generated/ugbc.tab.c"
    break;

  case 108: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 440 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 3065 "src-generated/ugbc.tab.c"
    break;

  case 109: /* raster_definition_expression: Identifier AT expressions  */
#line 445 "src/ugbc.y"
                              {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3073 "src-generated/ugbc.tab.c"
    break;

  case 110: /* raster_definition_expression: AT expressions WITH Identifier  */
#line 448 "src/ugbc.y"
                                   {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3081 "src-generated/ugbc.tab.c"
    break;

  case 113: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 457 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 3089 "src-generated/ugbc.tab.c"
    break;

  case 114: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 460 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 3097 "src-generated/ugbc.tab.c"
    break;

  case 115: /* next_raster_definition_expression: Identifier AT expressions  */
#line 465 "src/ugbc.y"
                              {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 3105 "src-generated/ugbc.tab.c"
    break;

  case 116: /* next_raster_definition_expression: AT expressions WITH Identifier  */
#line 468 "src/ugbc.y"
                                   {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3113 "src-generated/ugbc.tab.c"
    break;

  case 119: /* color_definition_simple: BORDER direct_integer  */
#line 477 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 3121 "src-generated/ugbc.tab.c"
    break;

  case 120: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 480 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3129 "src-generated/ugbc.tab.c"
    break;

  case 121: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 483 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3137 "src-generated/ugbc.tab.c"
    break;

  case 122: /* color_definition_expression: BORDER expressions  */
#line 488 "src/ugbc.y"
                       {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 3145 "src-generated/ugbc.tab.c"
    break;

  case 123: /* color_definition_expression: BACKGROUND expressions TO expressions  */
#line 491 "src/ugbc.y"
                                          {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3153 "src-generated/ugbc.tab.c"
    break;

  case 124: /* color_definition_expression: SPRITE expressions TO expressions  */
#line 494 "src/ugbc.y"
                                      {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3161 "src-generated/ugbc.tab.c"
    break;

  case 130: /* wait_definition_simple: direct_integer CYCLES  */
#line 508 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 3169 "src-generated/ugbc.tab.c"
    break;

  case 131: /* wait_definition_simple: direct_integer TICKS  */
#line 511 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 3177 "src-generated/ugbc.tab.c"
    break;

  case 132: /* wait_definition_simple: direct_integer milliseconds  */
#line 514 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 3185 "src-generated/ugbc.tab.c"
    break;

  case 133: /* wait_definition_expression: expressions CYCLES  */
#line 519 "src/ugbc.y"
                         {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 3193 "src-generated/ugbc.tab.c"
    break;

  case 134: /* wait_definition_expression: expressions TICKS  */
#line 522 "src/ugbc.y"
                        {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 3201 "src-generated/ugbc.tab.c"
    break;

  case 135: /* wait_definition_expression: expressions milliseconds  */
#line 525 "src/ugbc.y"
                               {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 3209 "src-generated/ugbc.tab.c"
    break;

  case 138: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 535 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 3217 "src-generated/ugbc.tab.c"
    break;

  case 139: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 538 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 3225 "src-generated/ugbc.tab.c"
    break;

  case 140: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 541 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 3233 "src-generated/ugbc.tab.c"
    break;

  case 141: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 544 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3241 "src-generated/ugbc.tab.c"
    break;

  case 142: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 547 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 3249 "src-generated/ugbc.tab.c"
    break;

  case 143: /* sprite_definition_simple: direct_integer ENABLE  */
#line 550 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 3257 "src-generated/ugbc.tab.c"
    break;

  case 144: /* sprite_definition_simple: direct_integer DISABLE  */
#line 553 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 3265 "src-generated/ugbc.tab.c"
    break;

  case 145: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 556 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3273 "src-generated/ugbc.tab.c"
    break;

  case 146: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 559 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3281 "src-generated/ugbc.tab.c"
    break;

  case 147: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 562 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3289 "src-generated/ugbc.tab.c"
    break;

  case 148: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 565 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3297 "src-generated/ugbc.tab.c"
    break;

  case 149: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 568 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3305 "src-generated/ugbc.tab.c"
    break;

  case 150: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 571 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3313 "src-generated/ugbc.tab.c"
    break;

  case 151: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 574 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3321 "src-generated/ugbc.tab.c"
    break;

  case 152: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 577 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3329 "src-generated/ugbc.tab.c"
    break;

  case 153: /* sprite_definition_expression: expressions DATA FROM expressions  */
#line 582 "src/ugbc.y"
                                      {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3337 "src-generated/ugbc.tab.c"
    break;

  case 154: /* sprite_definition_expression: expressions MULTICOLOR  */
#line 585 "src/ugbc.y"
                           {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3345 "src-generated/ugbc.tab.c"
    break;

  case 155: /* sprite_definition_expression: expressions MONOCOLOR  */
#line 588 "src/ugbc.y"
                          {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3353 "src-generated/ugbc.tab.c"
    break;

  case 156: /* sprite_definition_expression: expressions COLOR expressions  */
#line 591 "src/ugbc.y"
                                  {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3361 "src-generated/ugbc.tab.c"
    break;

  case 157: /* sprite_definition_expression: expressions position OP expressions COMMA expressions CP  */
#line 594 "src/ugbc.y"
                                                             {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3369 "src-generated/ugbc.tab.c"
    break;

  case 158: /* sprite_definition_expression: expressions ENABLE  */
#line 597 "src/ugbc.y"
                       {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3377 "src-generated/ugbc.tab.c"
    break;

  case 159: /* sprite_definition_expression: expressions DISABLE  */
#line 600 "src/ugbc.y"
                        {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3385 "src-generated/ugbc.tab.c"
    break;

  case 160: /* sprite_definition_expression: expressions EXPAND VERTICAL  */
#line 603 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3393 "src-generated/ugbc.tab.c"
    break;

  case 161: /* sprite_definition_expression: expressions COMPRESS VERTICAL  */
#line 606 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3401 "src-generated/ugbc.tab.c"
    break;

  case 162: /* sprite_definition_expression: expressions VERTICAL EXPAND  */
#line 609 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3409 "src-generated/ugbc.tab.c"
    break;

  case 163: /* sprite_definition_expression: expressions VERTICAL COMPRESS  */
#line 612 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3417 "src-generated/ugbc.tab.c"
    break;

  case 164: /* sprite_definition_expression: expressions EXPAND HORIZONTAL  */
#line 615 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3425 "src-generated/ugbc.tab.c"
    break;

  case 165: /* sprite_definition_expression: expressions COMPRESS HORIZONTAL  */
#line 618 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3433 "src-generated/ugbc.tab.c"
    break;

  case 166: /* sprite_definition_expression: expressions HORIZONTAL EXPAND  */
#line 621 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3441 "src-generated/ugbc.tab.c"
    break;

  case 167: /* sprite_definition_expression: expressions HORIZONTAL COMPRESS  */
#line 624 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3449 "src-generated/ugbc.tab.c"
    break;

  case 170: /* bitmap_definition_simple: AT direct_integer  */
#line 633 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3457 "src-generated/ugbc.tab.c"
    break;

  case 171: /* bitmap_definition_simple: ENABLE  */
#line 636 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3465 "src-generated/ugbc.tab.c"
    break;

  case 172: /* bitmap_definition_simple: DISABLE  */
#line 639 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 3473 "src-generated/ugbc.tab.c"
    break;

  case 173: /* bitmap_definition_simple: CLEAR  */
#line 642 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 3481 "src-generated/ugbc.tab.c"
    break;

  case 174: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 645 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 3489 "src-generated/ugbc.tab.c"
    break;

  case 175: /* bitmap_definition_expression: AT expressions  */
#line 651 "src/ugbc.y"
                   {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3497 "src-generated/ugbc.tab.c"
    break;

  case 176: /* bitmap_definition_expression: CLEAR WITH expressions  */
#line 654 "src/ugbc.y"
                           {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 3505 "src-generated/ugbc.tab.c"
    break;

  case 179: /* textmap_definition_simple: AT direct_integer  */
#line 664 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3513 "src-generated/ugbc.tab.c"
    break;

  case 180: /* textmap_definition_expression: AT expressions  */
#line 669 "src/ugbc.y"
                   {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3521 "src-generated/ugbc.tab.c"
    break;

  case 183: /* text_definition_simple: ENABLE  */
#line 678 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3529 "src-generated/ugbc.tab.c"
    break;

  case 184: /* text_definition_simple: DISABLE  */
#line 681 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 3537 "src-generated/ugbc.tab.c"
    break;

  case 186: /* tiles_definition_simple: AT direct_integer  */
#line 689 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 3545 "src-generated/ugbc.tab.c"
    break;

  case 187: /* tiles_definition_expression: AT expressions  */
#line 694 "src/ugbc.y"
                   {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 3553 "src-generated/ugbc.tab.c"
    break;

  case 190: /* colormap_definition_simple: AT direct_integer  */
#line 703 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 3561 "src-generated/ugbc.tab.c"
    break;

  case 191: /* colormap_definition_simple: CLEAR  */
#line 706 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 3569 "src-generated/ugbc.tab.c"
    break;

  case 192: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 709 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3577 "src-generated/ugbc.tab.c"
    break;

  case 193: /* colormap_definition_expression: AT expressions  */
#line 714 "src/ugbc.y"
                   {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3585 "src-generated/ugbc.tab.c"
    break;

  case 194: /* colormap_definition_expression: CLEAR WITH expressions ON expressions  */
#line 717 "src/ugbc.y"
                                          {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3593 "src-generated/ugbc.tab.c"
    break;

  case 197: /* screen_definition_simple: ON  */
#line 727 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 3601 "src-generated/ugbc.tab.c"
    break;

  case 198: /* screen_definition_simple: OFF  */
#line 730 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 3609 "src-generated/ugbc.tab.c"
    break;

  case 199: /* screen_definition_simple: ROWS direct_integer  */
#line 733 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 3617 "src-generated/ugbc.tab.c"
    break;

  case 200: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 736 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3625 "src-generated/ugbc.tab.c"
    break;

  case 201: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 739 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3633 "src-generated/ugbc.tab.c"
    break;

  case 202: /* screen_definition_expression: ROWS expressions  */
#line 744 "src/ugbc.y"
                     {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 3641 "src-generated/ugbc.tab.c"
    break;

  case 203: /* screen_definition_expression: VERTICAL SCROLL expressions  */
#line 747 "src/ugbc.y"
                                {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3649 "src-generated/ugbc.tab.c"
    break;

  case 204: /* screen_definition_expression: HORIZONTAL SCROLL expressions  */
#line 750 "src/ugbc.y"
                                  {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3657 "src-generated/ugbc.tab.c"
    break;

  case 208: /* var_definition_simple: Identifier ON Identifier  */
#line 759 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 3665 "src-generated/ugbc.tab.c"
    break;

  case 209: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 762 "src/ugbc.y"
                                    {
      variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 3673 "src-generated/ugbc.tab.c"
    break;

  case 210: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 765 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 3681 "src-generated/ugbc.tab.c"
    break;

  case 211: /* var_definition_simple: Identifier ON Identifier ASSIGN expressions  */
#line 768 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 3691 "src-generated/ugbc.tab.c"
    break;

  case 212: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expressions  */
#line 773 "src/ugbc.y"
                                                       {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 3701 "src-generated/ugbc.tab.c"
    break;

  case 213: /* goto_definition: Identifier  */
#line 780 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 3709 "src-generated/ugbc.tab.c"
    break;

  case 214: /* goto_definition: Integer  */
#line 783 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 3717 "src-generated/ugbc.tab.c"
    break;

  case 215: /* gosub_definition: Identifier  */
#line 789 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 3725 "src-generated/ugbc.tab.c"
    break;

  case 216: /* gosub_definition: Integer  */
#line 792 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 3733 "src-generated/ugbc.tab.c"
    break;

  case 218: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 801 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 3741 "src-generated/ugbc.tab.c"
    break;

  case 219: /* point_definition_expression: AT OP expressions COMMA expressions CP  */
#line 807 "src/ugbc.y"
                                             {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 3749 "src-generated/ugbc.tab.c"
    break;

  case 222: /* on_goto_definition: Identifier  */
#line 816 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 3758 "src-generated/ugbc.tab.c"
    break;

  case 223: /* $@1: %empty  */
#line 820 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 3766 "src-generated/ugbc.tab.c"
    break;

  case 225: /* on_gosub_definition: Identifier  */
#line 825 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 3775 "src-generated/ugbc.tab.c"
    break;

  case 226: /* $@2: %empty  */
#line 829 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 3783 "src-generated/ugbc.tab.c"
    break;

  case 228: /* $@3: %empty  */
#line 834 "src/ugbc.y"
                       {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 3791 "src-generated/ugbc.tab.c"
    break;

  case 230: /* $@4: %empty  */
#line 837 "src/ugbc.y"
                        {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 3799 "src-generated/ugbc.tab.c"
    break;

  case 232: /* every_definition: expression TICKS GOSUB Identifier  */
#line 842 "src/ugbc.y"
                                        {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 3807 "src-generated/ugbc.tab.c"
    break;

  case 233: /* every_definition: ON  */
#line 845 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 3815 "src-generated/ugbc.tab.c"
    break;

  case 234: /* every_definition: OFF  */
#line 848 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 3823 "src-generated/ugbc.tab.c"
    break;

  case 249: /* statement: RANDOMIZE  */
#line 867 "src/ugbc.y"
              {
      randomize( _environment );
  }
#line 3831 "src-generated/ugbc.tab.c"
    break;

  case 250: /* statement: IF expressions THEN  */
#line 870 "src/ugbc.y"
                        {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 3839 "src-generated/ugbc.tab.c"
    break;

  case 251: /* statement: ELSE  */
#line 873 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 3847 "src-generated/ugbc.tab.c"
    break;

  case 252: /* statement: ELSE IF expressions THEN  */
#line 876 "src/ugbc.y"
                             {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 3855 "src-generated/ugbc.tab.c"
    break;

  case 253: /* statement: ENDIF  */
#line 879 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 3863 "src-generated/ugbc.tab.c"
    break;

  case 254: /* statement: DO  */
#line 882 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 3871 "src-generated/ugbc.tab.c"
    break;

  case 255: /* statement: LOOP  */
#line 885 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 3879 "src-generated/ugbc.tab.c"
    break;

  case 256: /* $@5: %empty  */
#line 888 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 3887 "src-generated/ugbc.tab.c"
    break;

  case 257: /* statement: WHILE $@5 expressions  */
#line 890 "src/ugbc.y"
                {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 3895 "src-generated/ugbc.tab.c"
    break;

  case 258: /* statement: WEND  */
#line 893 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 3903 "src-generated/ugbc.tab.c"
    break;

  case 259: /* statement: REPEAT  */
#line 896 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 3911 "src-generated/ugbc.tab.c"
    break;

  case 260: /* statement: UNTIL expressions  */
#line 899 "src/ugbc.y"
                      {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 3919 "src-generated/ugbc.tab.c"
    break;

  case 261: /* statement: EXIT  */
#line 902 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 3927 "src-generated/ugbc.tab.c"
    break;

  case 262: /* statement: EXIT IF expressions  */
#line 905 "src/ugbc.y"
                        {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 3935 "src-generated/ugbc.tab.c"
    break;

  case 263: /* statement: EXIT Integer  */
#line 908 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 3943 "src-generated/ugbc.tab.c"
    break;

  case 264: /* statement: EXIT direct_integer  */
#line 911 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 3951 "src-generated/ugbc.tab.c"
    break;

  case 265: /* statement: EXIT IF expressions COMMA Integer  */
#line 914 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 3959 "src-generated/ugbc.tab.c"
    break;

  case 266: /* statement: EXIT IF expressions COMMA direct_integer  */
#line 917 "src/ugbc.y"
                                             {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 3967 "src-generated/ugbc.tab.c"
    break;

  case 267: /* statement: FOR Identifier ASSIGN expressions TO expressions  */
#line 920 "src/ugbc.y"
                                                     {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 3975 "src-generated/ugbc.tab.c"
    break;

  case 268: /* statement: NEXT  */
#line 923 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 3983 "src-generated/ugbc.tab.c"
    break;

  case 269: /* statement: FOR Identifier ASSIGN expressions TO expressions STEP expressions  */
#line 926 "src/ugbc.y"
                                                                      {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 3991 "src-generated/ugbc.tab.c"
    break;

  case 270: /* statement: BEG GAMELOOP  */
#line 929 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 3999 "src-generated/ugbc.tab.c"
    break;

  case 271: /* statement: END GAMELOOP  */
#line 932 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 4007 "src-generated/ugbc.tab.c"
    break;

  case 272: /* statement: GRAPHIC  */
#line 935 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 4015 "src-generated/ugbc.tab.c"
    break;

  case 273: /* statement: HALT  */
#line 938 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 4023 "src-generated/ugbc.tab.c"
    break;

  case 278: /* statement: RETURN  */
#line 945 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 4031 "src-generated/ugbc.tab.c"
    break;

  case 279: /* statement: POP  */
#line 948 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 4039 "src-generated/ugbc.tab.c"
    break;

  case 280: /* statement: DONE  */
#line 951 "src/ugbc.y"
          {
      return 0;
  }
#line 4047 "src-generated/ugbc.tab.c"
    break;

  case 281: /* statement: LEFT OP expression COMMA expression CP ASSIGN expressions  */
#line 954 "src/ugbc.y"
                                                              {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4055 "src-generated/ugbc.tab.c"
    break;

  case 282: /* statement: RIGHT OP expression COMMA expression CP ASSIGN expressions  */
#line 957 "src/ugbc.y"
                                                               {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4063 "src-generated/ugbc.tab.c"
    break;

  case 283: /* statement: MID OP expression COMMA expression CP ASSIGN expressions  */
#line 960 "src/ugbc.y"
                                                             {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 4071 "src-generated/ugbc.tab.c"
    break;

  case 284: /* statement: MID OP expression COMMA expression COMMA expression CP ASSIGN expressions  */
#line 963 "src/ugbc.y"
                                                                              {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4079 "src-generated/ugbc.tab.c"
    break;

  case 285: /* statement: Identifier COLON  */
#line 966 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 4087 "src-generated/ugbc.tab.c"
    break;

  case 286: /* statement: Identifier ASSIGN expressions  */
#line 969 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expressions = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expressions->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 4101 "src-generated/ugbc.tab.c"
    break;

  case 287: /* statement: Identifier DOLLAR ASSIGN expressions  */
#line 978 "src/ugbc.y"
                                         {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expressions = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 4115 "src-generated/ugbc.tab.c"
    break;

  case 288: /* statement: DEBUG expressions  */
#line 987 "src/ugbc.y"
                      {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 4123 "src-generated/ugbc.tab.c"
    break;

  case 291: /* statements_no_linenumbers: statement  */
#line 995 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 4129 "src-generated/ugbc.tab.c"
    break;

  case 292: /* $@6: %empty  */
#line 996 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 4135 "src-generated/ugbc.tab.c"
    break;

  case 294: /* $@7: %empty  */
#line 1000 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 4143 "src-generated/ugbc.tab.c"
    break;

  case 295: /* statements_with_linenumbers: Integer $@7 statements_no_linenumbers  */
#line 1002 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 4151 "src-generated/ugbc.tab.c"
    break;

  case 300: /* $@8: %empty  */
#line 1014 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 4157 "src-generated/ugbc.tab.c"
    break;


#line 4161 "src-generated/ugbc.tab.c"

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

#line 1016 "src/ugbc.y"


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

