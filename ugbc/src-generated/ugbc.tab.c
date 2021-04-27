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
  YYSYMBOL_RASTER = 14,                    /* RASTER  */
  YYSYMBOL_DONE = 15,                      /* DONE  */
  YYSYMBOL_AT = 16,                        /* AT  */
  YYSYMBOL_COLOR = 17,                     /* COLOR  */
  YYSYMBOL_BORDER = 18,                    /* BORDER  */
  YYSYMBOL_WAIT = 19,                      /* WAIT  */
  YYSYMBOL_NEXT = 20,                      /* NEXT  */
  YYSYMBOL_WITH = 21,                      /* WITH  */
  YYSYMBOL_BANK = 22,                      /* BANK  */
  YYSYMBOL_SPRITE = 23,                    /* SPRITE  */
  YYSYMBOL_DATA = 24,                      /* DATA  */
  YYSYMBOL_FROM = 25,                      /* FROM  */
  YYSYMBOL_OP = 26,                        /* OP  */
  YYSYMBOL_CP = 27,                        /* CP  */
  YYSYMBOL_ENABLE = 28,                    /* ENABLE  */
  YYSYMBOL_DISABLE = 29,                   /* DISABLE  */
  YYSYMBOL_HALT = 30,                      /* HALT  */
  YYSYMBOL_ECM = 31,                       /* ECM  */
  YYSYMBOL_BITMAP = 32,                    /* BITMAP  */
  YYSYMBOL_SCREEN = 33,                    /* SCREEN  */
  YYSYMBOL_ON = 34,                        /* ON  */
  YYSYMBOL_OFF = 35,                       /* OFF  */
  YYSYMBOL_ROWS = 36,                      /* ROWS  */
  YYSYMBOL_VERTICAL = 37,                  /* VERTICAL  */
  YYSYMBOL_SCROLL = 38,                    /* SCROLL  */
  YYSYMBOL_VAR = 39,                       /* VAR  */
  YYSYMBOL_AS = 40,                        /* AS  */
  YYSYMBOL_TEMPORARY = 41,                 /* TEMPORARY  */
  YYSYMBOL_XPEN = 42,                      /* XPEN  */
  YYSYMBOL_YPEN = 43,                      /* YPEN  */
  YYSYMBOL_PEEK = 44,                      /* PEEK  */
  YYSYMBOL_GOTO = 45,                      /* GOTO  */
  YYSYMBOL_HORIZONTAL = 46,                /* HORIZONTAL  */
  YYSYMBOL_MCM = 47,                       /* MCM  */
  YYSYMBOL_COMPRESS = 48,                  /* COMPRESS  */
  YYSYMBOL_EXPAND = 49,                    /* EXPAND  */
  YYSYMBOL_LOOP = 50,                      /* LOOP  */
  YYSYMBOL_REPEAT = 51,                    /* REPEAT  */
  YYSYMBOL_WHILE = 52,                     /* WHILE  */
  YYSYMBOL_TEXT = 53,                      /* TEXT  */
  YYSYMBOL_TILES = 54,                     /* TILES  */
  YYSYMBOL_COLORMAP = 55,                  /* COLORMAP  */
  YYSYMBOL_SELECT = 56,                    /* SELECT  */
  YYSYMBOL_MONOCOLOR = 57,                 /* MONOCOLOR  */
  YYSYMBOL_MULTICOLOR = 58,                /* MULTICOLOR  */
  YYSYMBOL_COLLISION = 59,                 /* COLLISION  */
  YYSYMBOL_IF = 60,                        /* IF  */
  YYSYMBOL_THEN = 61,                      /* THEN  */
  YYSYMBOL_HIT = 62,                       /* HIT  */
  YYSYMBOL_BACKGROUND = 63,                /* BACKGROUND  */
  YYSYMBOL_TO = 64,                        /* TO  */
  YYSYMBOL_RANDOM = 65,                    /* RANDOM  */
  YYSYMBOL_BYTE = 66,                      /* BYTE  */
  YYSYMBOL_WORD = 67,                      /* WORD  */
  YYSYMBOL_POSITION = 68,                  /* POSITION  */
  YYSYMBOL_CODE = 69,                      /* CODE  */
  YYSYMBOL_VARIABLES = 70,                 /* VARIABLES  */
  YYSYMBOL_MS = 71,                        /* MS  */
  YYSYMBOL_CYCLES = 72,                    /* CYCLES  */
  YYSYMBOL_S = 73,                         /* S  */
  YYSYMBOL_HASH = 74,                      /* HASH  */
  YYSYMBOL_WIDTH = 75,                     /* WIDTH  */
  YYSYMBOL_HEIGHT = 76,                    /* HEIGHT  */
  YYSYMBOL_DWORD = 77,                     /* DWORD  */
  YYSYMBOL_PEN = 78,                       /* PEN  */
  YYSYMBOL_CLEAR = 79,                     /* CLEAR  */
  YYSYMBOL_BEG = 80,                       /* BEG  */
  YYSYMBOL_END = 81,                       /* END  */
  YYSYMBOL_GAMELOOP = 82,                  /* GAMELOOP  */
  YYSYMBOL_ENDIF = 83,                     /* ENDIF  */
  YYSYMBOL_UP = 84,                        /* UP  */
  YYSYMBOL_DOWN = 85,                      /* DOWN  */
  YYSYMBOL_LEFT = 86,                      /* LEFT  */
  YYSYMBOL_RIGHT = 87,                     /* RIGHT  */
  YYSYMBOL_DEBUG = 88,                     /* DEBUG  */
  YYSYMBOL_AND = 89,                       /* AND  */
  YYSYMBOL_RANDOMIZE = 90,                 /* RANDOMIZE  */
  YYSYMBOL_GRAPHIC = 91,                   /* GRAPHIC  */
  YYSYMBOL_TEXTMAP = 92,                   /* TEXTMAP  */
  YYSYMBOL_POINT = 93,                     /* POINT  */
  YYSYMBOL_GOSUB = 94,                     /* GOSUB  */
  YYSYMBOL_RETURN = 95,                    /* RETURN  */
  YYSYMBOL_POP = 96,                       /* POP  */
  YYSYMBOL_OR = 97,                        /* OR  */
  YYSYMBOL_MILLISECOND = 98,               /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 99,              /* MILLISECONDS  */
  YYSYMBOL_TICKS = 100,                    /* TICKS  */
  YYSYMBOL_BLACK = 101,                    /* BLACK  */
  YYSYMBOL_WHITE = 102,                    /* WHITE  */
  YYSYMBOL_RED = 103,                      /* RED  */
  YYSYMBOL_CYAN = 104,                     /* CYAN  */
  YYSYMBOL_VIOLET = 105,                   /* VIOLET  */
  YYSYMBOL_GREEN = 106,                    /* GREEN  */
  YYSYMBOL_BLUE = 107,                     /* BLUE  */
  YYSYMBOL_YELLOW = 108,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 109,                   /* ORANGE  */
  YYSYMBOL_BROWN = 110,                    /* BROWN  */
  YYSYMBOL_LIGHT = 111,                    /* LIGHT  */
  YYSYMBOL_DARK = 112,                     /* DARK  */
  YYSYMBOL_GREY = 113,                     /* GREY  */
  YYSYMBOL_GRAY = 114,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 115,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 116,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 117,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 118,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 119,                /* TURQUOISE  */
  YYSYMBOL_TAN = 120,                      /* TAN  */
  YYSYMBOL_PINK = 121,                     /* PINK  */
  YYSYMBOL_PEACH = 122,                    /* PEACH  */
  YYSYMBOL_OLIVE = 123,                    /* OLIVE  */
  YYSYMBOL_Identifier = 124,               /* Identifier  */
  YYSYMBOL_String = 125,                   /* String  */
  YYSYMBOL_Integer = 126,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 127,                 /* $accept  */
  YYSYMBOL_direct_integer = 128,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 129, /* random_definition_simple  */
  YYSYMBOL_random_definition = 130,        /* random_definition  */
  YYSYMBOL_color_enumeration = 131,        /* color_enumeration  */
  YYSYMBOL_expression = 132,               /* expression  */
  YYSYMBOL_expressions_raw = 133,          /* expressions_raw  */
  YYSYMBOL_expressions = 134,              /* expressions  */
  YYSYMBOL_position = 135,                 /* position  */
  YYSYMBOL_bank_definition_simple = 136,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 137, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 138,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 139, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 140, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 141,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 142, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 143, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 144,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 145,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 146, /* color_definition_expression  */
  YYSYMBOL_color_definition = 147,         /* color_definition  */
  YYSYMBOL_milliseconds = 148,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 149,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 150, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 151,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 152, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 153, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 154,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 155, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 156, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 157,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 158, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 159, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 160,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 161,   /* text_definition_simple  */
  YYSYMBOL_text_definition = 162,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 163,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 164, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 165,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 166, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 167, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 168,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 169, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 170, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 171,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 172,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 173,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 174,         /* gosub_definition  */
  YYSYMBOL_var_definition = 175,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 176,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 177, /* point_definition_expression  */
  YYSYMBOL_point_definition = 178,         /* point_definition  */
  YYSYMBOL_statement = 179,                /* statement  */
  YYSYMBOL_180_1 = 180,                    /* $@1  */
  YYSYMBOL_181_2 = 181,                    /* $@2  */
  YYSYMBOL_statements_no_linenumbers = 182, /* statements_no_linenumbers  */
  YYSYMBOL_183_3 = 183,                    /* $@3  */
  YYSYMBOL_statements_with_linenumbers = 184, /* statements_with_linenumbers  */
  YYSYMBOL_185_4 = 185,                    /* $@4  */
  YYSYMBOL_statements_complex = 186,       /* statements_complex  */
  YYSYMBOL_program = 187                   /* program  */
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
#define YYFINAL  156
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   669

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  127
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  244
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  413

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   381


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
     125,   126
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    66,    69,    72,    75,    78,    81,    84,
      89,    94,    98,   102,   106,   110,   114,   118,   122,   126,
     130,   134,   138,   142,   146,   150,   154,   158,   162,   166,
     170,   174,   178,   182,   186,   190,   194,   198,   204,   207,
     211,   215,   219,   223,   227,   231,   234,   237,   240,   243,
     246,   249,   252,   255,   258,   261,   267,   268,   271,   275,
     279,   283,   289,   293,   293,   296,   299,   302,   305,   308,
     311,   315,   318,   321,   324,   328,   331,   334,   337,   341,
     344,   347,   350,   356,   359,   362,   365,   368,   373,   374,
     377,   380,   385,   388,   393,   394,   397,   400,   405,   408,
     413,   414,   417,   420,   423,   428,   431,   434,   439,   440,
     443,   444,   445,   448,   451,   454,   459,   462,   465,   471,
     472,   475,   478,   481,   484,   487,   490,   493,   496,   499,
     502,   505,   508,   511,   514,   517,   522,   525,   528,   531,
     534,   537,   540,   543,   546,   549,   552,   555,   558,   561,
     564,   569,   570,   573,   576,   579,   582,   585,   591,   594,
     600,   601,   604,   609,   614,   615,   618,   621,   626,   629,
     634,   639,   640,   643,   646,   649,   654,   657,   663,   664,
     667,   670,   673,   676,   679,   684,   687,   690,   695,   696,
     698,   699,   702,   705,   715,   718,   724,   727,   733,   736,
     742,   747,   748,   751,   752,   753,   754,   755,   756,   757,
     758,   759,   760,   761,   762,   763,   764,   765,   768,   770,
     768,   773,   776,   779,   782,   785,   786,   787,   790,   793,
     796,   799,   805,   808,   809,   813,   814,   814,   818,   818,
     825,   826,   827,   828,   832
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
  "EQUAL", "ASSIGN", "RASTER", "DONE", "AT", "COLOR", "BORDER", "WAIT",
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
  "POP", "OR", "MILLISECOND", "MILLISECONDS", "TICKS", "BLACK", "WHITE",
  "RED", "CYAN", "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE", "BROWN",
  "LIGHT", "DARK", "GREY", "GRAY", "MAGENTA", "PURPLE", "LAVENDER", "GOLD",
  "TURQUOISE", "TAN", "PINK", "PEACH", "OLIVE", "Identifier", "String",
  "Integer", "$accept", "direct_integer", "random_definition_simple",
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
  "point_definition_expression", "point_definition", "statement", "$@1",
  "$@2", "statements_no_linenumbers", "$@3", "statements_with_linenumbers",
  "$@4", "statements_complex", "program", YY_NULLPTR
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
     375,   376,   377,   378,   379,   380,   381
};
#endif

#define YYPACT_NINF (-152)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     306,  -152,   -12,  -152,    13,   517,    15,   -13,   517,  -152,
       9,    43,   -74,  -110,    17,    58,   -14,   543,    14,    16,
     543,  -152,  -152,   111,   122,   -62,  -152,  -152,    84,  -152,
      94,   136,   137,  -152,   142,   517,   128,  -152,  -152,  -152,
     517,   517,   517,  -152,  -152,  -152,   429,  -152,  -152,   119,
     121,   124,    -7,    26,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,    47,  -152,  -152,   -40,   -83,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,    50,  -152,  -152,   -51,  -152,
      10,  -152,   -17,  -152,  -152,  -152,   -11,    80,    -9,    -3,
      -1,     1,   139,  -152,  -152,  -152,   100,   154,  -152,  -152,
    -152,   517,  -152,  -152,   140,  -152,  -152,  -152,  -152,  -152,
     517,   125,   129,  -152,  -152,  -152,   126,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,   517,  -152,  -152,  -152,
     517,   141,  -152,  -152,  -152,  -152,  -152,  -152,  -152,   517,
    -152,  -152,  -152,   143,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,   543,   389,  -152,   306,   306,  -152,   155,   156,   517,
    -152,  -152,   115,   116,   117,   120,   148,   158,   160,   161,
     162,   163,   517,   517,   517,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,   543,
     543,   543,   543,   543,  -152,  -152,  -152,   517,   176,  -152,
    -152,  -152,   153,    80,   178,    80,   179,    80,   180,    80,
     181,    80,  -152,    80,   173,  -152,  -152,    55,    57,     7,
      38,  -152,  -152,  -152,   175,   543,   183,  -152,  -152,    60,
      71,    48,    49,  -152,  -152,   184,  -152,  -152,   517,  -152,
    -152,   517,   517,    81,  -152,  -152,  -152,  -152,   517,   145,
    -152,  -152,   517,  -152,  -152,   389,  -152,  -152,    85,    90,
    -152,  -152,    80,   543,    80,   543,    78,    92,    98,    99,
     102,  -152,   189,   193,   199,   202,   203,   204,  -152,  -152,
    -152,  -152,  -152,   211,   212,   517,   -18,  -152,    80,  -152,
      80,  -152,    80,  -152,    80,    18,  -152,    80,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,    80,  -152,   543,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,   543,  -152,  -152,
    -152,  -152,  -152,  -152,   221,   201,   205,   389,   229,   230,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,   114,   118,
    -152,  -152,  -152,  -152,  -152,  -152,   220,  -152,   224,  -152,
     130,     2,  -152,   239,  -152,   240,   517,    80,   543,  -152,
      80,   543,  -152,  -152,   131,   132,  -152,   228,  -152,   232,
    -152,    80,   543,  -152,  -152,  -152,  -152,   177,   234,   236,
    -152,  -152,   134,   144,   237,   241,  -152,  -152,  -152,  -152,
    -152,  -152,  -152
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     234,   233,     0,   229,     0,     0,     0,     0,     0,   224,
       0,     0,   190,     0,     0,     0,     0,     0,     0,     0,
       0,   217,   223,     0,     0,     0,   227,   228,     0,   238,
     235,   240,   242,   244,     0,     0,     0,    94,    95,   204,
       0,     0,     0,   108,   109,   206,     0,    48,    49,     0,
       0,     0,     0,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,    23,    28,    29,    30,
      31,    32,    33,    36,    37,     0,    38,    39,     0,    45,
      56,    62,     0,   119,   120,   207,     0,     0,     0,     0,
       0,     0,     0,    88,    89,   203,     0,     0,   151,   152,
     208,     0,   154,   155,   156,   160,   161,   209,   180,   181,
       0,     0,     0,   188,   189,   214,     0,   198,   216,   194,
     195,   225,   166,   167,   168,   211,     0,   171,   172,   212,
       0,   174,   178,   179,   213,   218,   221,   222,   232,     0,
     164,   165,   210,     0,   201,   202,   215,   196,   197,   226,
     230,     0,   234,   236,   234,   234,     1,     0,     0,     0,
     102,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     3,     4,     6,     8,
       9,     5,    10,    54,     2,    34,    21,    24,    25,    26,
      27,    22,    35,   110,   113,   111,   112,   114,   115,     0,
       0,     0,     0,     0,   116,   117,   118,     0,     0,   100,
     101,   205,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,     0,     0,   126,   127,     0,     0,     0,
       0,   123,   122,    63,     0,     0,     0,   141,   142,     0,
       0,     0,     0,   138,   137,     0,   153,   158,     0,   182,
     185,     0,     0,     0,   169,   170,   173,   176,     0,     0,
     162,   163,     0,   231,   239,   234,   241,   243,     0,     0,
      90,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,    57,    58,
      61,    59,    60,     0,     0,     0,     0,    70,     0,    82,
       0,    74,     0,    78,     0,    66,   124,     0,   131,   130,
     135,   134,   129,   133,   128,   132,     0,   139,     0,   146,
     145,   150,   149,   144,   148,   143,   147,     0,   157,   159,
     183,   186,   184,   187,   191,     0,     0,   234,     0,     0,
     237,    91,    93,   104,   107,   103,   106,    44,    40,    41,
      43,    42,    46,    47,    50,    51,    52,    53,     0,     0,
      96,    98,    67,    80,    72,    75,    69,    81,    73,    77,
       0,     0,   121,     0,   136,     0,     0,     0,     0,   219,
       0,     0,    97,    99,     0,     0,    83,    68,    79,    71,
      76,     0,     0,   192,   193,   175,   177,     0,     0,     0,
      85,    87,     0,     0,     0,     0,   220,   199,   200,    84,
      86,   125,   140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,     0,  -152,  -152,  -152,   225,   -67,    -8,   169,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,   188,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -151,  -152,  -152,  -152,   -63,
    -152
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    78,   182,   183,    79,    80,    81,    82,   234,    93,
      94,    95,    37,    38,    39,   209,   210,   211,    43,    44,
      45,   198,    83,    84,    85,    98,    99,   100,   105,   106,
     107,   140,   141,   142,   124,   125,   127,   128,   129,   132,
     133,   134,   113,   114,   115,   117,   121,   149,   118,   144,
     145,   146,    30,   259,   397,    31,   265,    32,   152,    33,
      34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      97,   264,   130,    87,    35,   207,   362,   213,    96,   135,
     175,    88,   138,   215,   119,   217,   120,   219,   199,   200,
     193,   194,   201,   363,   190,   101,   387,   158,    89,    86,
     191,    40,   161,   163,   165,   157,    41,   102,   103,   370,
     160,   162,   164,   388,   312,   122,   123,   195,   196,   197,
     116,   364,   365,   313,   193,   204,    90,    91,   371,   176,
     177,   178,   147,   186,   148,   131,   187,   188,   179,   180,
     181,   389,   390,   189,   126,   314,    42,   108,   109,   110,
     111,   195,   196,   205,   315,   323,   325,   212,   104,   112,
     150,   266,   267,   247,   324,   326,   136,   151,   137,   202,
     153,   246,   250,   308,   309,   310,   311,   203,   319,   320,
     249,    92,    36,   208,   340,   214,   222,   223,   255,   321,
     322,   216,   257,   218,   224,   220,   254,   139,   225,   226,
     256,   261,   288,   289,   290,   291,   292,   227,   143,   260,
     154,   155,   156,   263,   159,   172,   228,   173,   229,   230,
     174,   271,   184,   185,    53,   221,   192,   231,   232,   270,
     253,   248,   258,   251,   283,   285,   287,   252,   233,   262,
     222,   235,   282,   284,   286,   276,   268,   269,   236,   272,
     273,   274,   237,   238,   275,   277,   379,   278,   279,   280,
     281,   239,   295,   296,   298,   300,   302,   304,   307,   294,
     240,   316,   241,   242,   347,   334,   337,   293,   318,   341,
     327,   243,   244,   297,   342,   299,   352,   301,   348,   303,
     353,   305,   233,   306,   349,   350,   354,   317,   351,   355,
     356,   357,   358,   359,   376,   377,   380,   381,   382,   378,
     329,   384,   383,   331,   333,   385,   391,   392,   328,   402,
     336,   330,   332,   403,   339,   386,   400,   401,   335,   409,
     406,   407,   338,   408,   411,   344,   245,   346,   412,   410,
     206,   171,   343,     0,   345,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   361,     0,     0,
       0,     0,     0,     0,     0,   360,     0,     0,   366,     0,
     367,     0,   368,     0,   369,     0,     0,   372,     0,     1,
     374,     0,     0,     0,     0,     0,   373,     0,     0,   375,
       2,     3,     0,     4,     0,     5,     6,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     9,     0,    10,    11,
       0,     0,     0,     0,     0,    12,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     0,     0,    14,
      15,    16,     0,     0,     0,     0,    17,     0,   394,     0,
     396,     0,     0,   399,     0,     0,   393,   395,     0,     0,
     398,     0,     0,     0,   405,     0,    18,    19,     0,     0,
       0,   404,     1,     0,    20,     0,    21,    22,    23,    24,
      25,    26,    27,     2,     3,     0,     4,     0,     5,     6,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     9,
       0,    10,    11,     0,     0,     0,     0,     0,    12,     0,
      28,     0,    29,     0,    13,     0,     0,     0,     0,     0,
       0,     0,    14,    15,    16,     0,   166,     0,     0,    17,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      19,    47,    48,    49,     0,     0,     0,    20,     0,    21,
      22,    23,    24,    25,    26,    27,     0,     0,    50,     0,
       0,    51,     0,     0,    52,   167,   168,   169,     0,     0,
       0,     0,     0,     0,     0,     0,   170,     0,     0,     0,
       0,     0,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    46,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,     0,    77,     0,     0,     0,    47,
      48,    49,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,    50,     0,     0,    51,
       0,     0,    52,     0,     0,    47,    48,    49,     0,     0,
       0,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,     0,     0,    51,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,     0,    77,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,     0,    77
};

static const yytype_int16 yycheck[] =
{
       8,   152,    16,    16,    16,    16,    24,    16,     8,    17,
      17,    24,    20,    16,   124,    16,   126,    16,     8,     9,
      71,    72,    12,    41,   107,    16,    24,    35,    41,    14,
     113,    18,    40,    41,    42,    35,    23,    28,    29,    21,
      40,    41,    42,    41,    37,    28,    29,    98,    99,   100,
     124,    69,    70,    46,    71,    72,    69,    70,    40,    66,
      67,    68,   124,   103,   126,    79,   106,   107,    75,    76,
      77,    69,    70,   113,    16,    37,    63,    34,    35,    36,
      37,    98,    99,   100,    46,    37,    37,    87,    79,    46,
       6,   154,   155,   101,    46,    46,    82,    13,    82,    89,
       6,   101,   110,    48,    49,    48,    49,    97,    48,    49,
     110,   124,   124,   124,   265,   124,    16,    17,   126,    48,
      49,   124,   130,   124,    24,   124,   126,    16,    28,    29,
     130,   139,   199,   200,   201,   202,   203,    37,    16,   139,
       4,     4,     0,   151,    16,    26,    46,    26,    48,    49,
      26,   159,   126,   106,    74,    16,   106,    57,    58,   159,
      34,    21,    21,    38,   172,   173,   174,    38,    68,    26,
      16,    17,   172,   173,   174,    27,    21,    21,    24,    64,
      64,    64,    28,    29,    64,    27,   337,    27,    27,    27,
      27,    37,    16,    40,    16,    16,    16,    16,    25,   207,
      46,    26,    48,    49,   126,   124,    61,   207,    25,   124,
      26,    57,    58,   213,   124,   215,    27,   217,   126,   219,
      27,   221,    68,   223,   126,   126,    27,   235,   126,    27,
      27,    27,    21,    21,    13,    34,     7,     7,   124,    34,
     248,    21,   124,   251,   252,    21,     7,     7,   248,    21,
     258,   251,   252,    21,   262,   125,   125,   125,   258,   125,
      83,    27,   262,    27,    27,   273,    97,   275,    27,   125,
      82,    46,   272,    -1,   274,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   295,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   295,    -1,    -1,   298,    -1,
     300,    -1,   302,    -1,   304,    -1,    -1,   307,    -1,     3,
     318,    -1,    -1,    -1,    -1,    -1,   316,    -1,    -1,   327,
      14,    15,    -1,    17,    -1,    19,    20,    -1,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    -1,    -1,    -1,    -1,    60,    -1,   376,    -1,
     378,    -1,    -1,   381,    -1,    -1,   376,   377,    -1,    -1,
     380,    -1,    -1,    -1,   392,    -1,    80,    81,    -1,    -1,
      -1,   391,     3,    -1,    88,    -1,    90,    91,    92,    93,
      94,    95,    96,    14,    15,    -1,    17,    -1,    19,    20,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    39,    -1,
     124,    -1,   126,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    -1,    17,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    42,    43,    44,    -1,    -1,    -1,    88,    -1,    90,
      91,    92,    93,    94,    95,    96,    -1,    -1,    59,    -1,
      -1,    62,    -1,    -1,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    26,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,   126,    -1,    -1,    -1,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    62,
      -1,    -1,    65,    -1,    -1,    42,    43,    44,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    62,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,   126,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,   126
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    14,    15,    17,    19,    20,    22,    23,    30,
      32,    33,    39,    45,    53,    54,    55,    60,    80,    81,
      88,    90,    91,    92,    93,    94,    95,    96,   124,   126,
     179,   182,   184,   186,   187,    16,   124,   139,   140,   141,
      18,    23,    63,   145,   146,   147,    26,    42,    43,    44,
      59,    62,    65,    74,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   126,   128,   131,
     132,   133,   134,   149,   150,   151,    14,    16,    24,    41,
      69,    70,   124,   136,   137,   138,   128,   134,   152,   153,
     154,    16,    28,    29,    79,   155,   156,   157,    34,    35,
      36,    37,    46,   169,   170,   171,   124,   172,   175,   124,
     126,   173,    28,    29,   161,   162,    16,   163,   164,   165,
      16,    79,   166,   167,   168,   134,    82,    82,   134,    16,
     158,   159,   160,    16,   176,   177,   178,   124,   126,   174,
       6,    13,   185,     6,     4,     4,     0,   128,   134,    16,
     128,   134,   128,   134,   128,   134,    17,    66,    67,    68,
      77,   132,    26,    26,    26,    17,    66,    67,    68,    75,
      76,    77,   129,   130,   126,   106,   103,   106,   107,   113,
     107,   113,   106,    71,    72,    98,    99,   100,   148,     8,
       9,    12,    89,    97,    72,   100,   148,    16,   124,   142,
     143,   144,   128,    16,   124,    16,   124,    16,   124,    16,
     124,    16,    16,    17,    24,    28,    29,    37,    46,    48,
      49,    57,    58,    68,   135,    17,    24,    28,    29,    37,
      46,    48,    49,    57,    58,   135,   128,   134,    21,   128,
     134,    38,    38,    34,   128,   134,   128,   134,    21,   180,
     128,   134,    26,   134,   182,   183,   186,   186,    21,    21,
     128,   134,    64,    64,    64,    64,    27,    27,    27,    27,
      27,    27,   128,   134,   128,   134,   128,   134,   133,   133,
     133,   133,   133,   128,   134,    16,    40,   128,    16,   128,
      16,   128,    16,   128,    16,   128,   128,    25,    48,    49,
      48,    49,    37,    46,    37,    46,    26,   134,    25,    48,
      49,    48,    49,    37,    46,    37,    46,    26,   128,   134,
     128,   134,   128,   134,   124,   128,   134,    61,   128,   134,
     182,   124,   124,   128,   134,   128,   134,   126,   126,   126,
     126,   126,    27,    27,    27,    27,    27,    27,    21,    21,
     128,   134,    24,    41,    69,    70,   128,   128,   128,   128,
      21,    40,   128,   128,   134,   134,    13,    34,    34,   182,
       7,     7,   124,   124,    21,    21,   125,    24,    41,    69,
      70,     7,     7,   128,   134,   128,   134,   181,   128,   134,
     125,   125,    21,    21,   128,   134,    83,    27,    27,   125,
     125,    27,    27
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   127,   128,   129,   129,   129,   129,   129,   129,   129,
     130,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   133,   133,   133,   133,
     133,   133,   134,   135,   135,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   137,   137,   137,   137,   137,   138,   138,
     139,   139,   140,   140,   141,   141,   142,   142,   143,   143,
     144,   144,   145,   145,   145,   146,   146,   146,   147,   147,
     148,   148,   148,   149,   149,   149,   150,   150,   150,   151,
     151,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   154,   154,   155,   155,   155,   155,   155,   156,   156,
     157,   157,   158,   159,   160,   160,   161,   161,   162,   163,
     164,   165,   165,   166,   166,   166,   167,   167,   168,   168,
     169,   169,   169,   169,   169,   170,   170,   170,   171,   171,
     172,   172,   172,   172,   173,   173,   174,   174,   175,   176,
     177,   178,   178,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   180,   181,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   182,   183,   182,   185,   184,
     186,   186,   186,   186,   187
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     1,     4,     4,     1,     1,
       4,     4,     4,     4,     2,     3,     1,     3,     3,     3,
       3,     3,     1,     1,     1,     2,     3,     4,     5,     4,
       3,     5,     4,     4,     3,     4,     5,     4,     3,     5,
       4,     4,     3,     5,     7,     6,     7,     6,     1,     1,
       3,     4,     3,     4,     1,     1,     3,     4,     3,     4,
       1,     1,     2,     4,     4,     2,     4,     4,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     1,
       1,     4,     2,     2,     3,     7,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     2,     2,     3,
       7,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     2,     1,     1,     1,     3,     2,     3,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     2,     1,     5,     2,     5,     1,     1,
       1,     1,     2,     3,     3,     2,     3,     3,     1,     1,
       0,     3,     5,     5,     1,     1,     1,     1,     1,     6,
       6,     1,     1,     2,     2,     3,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     0,     0,
       7,     2,     2,     1,     1,     2,     2,     1,     1,     1,
       2,     3,     2,     1,     0,     1,     0,     4,     0,     3,
       1,     3,     1,     3,     1
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
#line 61 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2016 "src-generated/ugbc.tab.c"
    break;

  case 3: /* random_definition_simple: BYTE  */
#line 66 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2024 "src-generated/ugbc.tab.c"
    break;

  case 4: /* random_definition_simple: WORD  */
#line 69 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2032 "src-generated/ugbc.tab.c"
    break;

  case 5: /* random_definition_simple: DWORD  */
#line 72 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2040 "src-generated/ugbc.tab.c"
    break;

  case 6: /* random_definition_simple: POSITION  */
#line 75 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2048 "src-generated/ugbc.tab.c"
    break;

  case 7: /* random_definition_simple: COLOR  */
#line 78 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2056 "src-generated/ugbc.tab.c"
    break;

  case 8: /* random_definition_simple: WIDTH  */
#line 81 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2064 "src-generated/ugbc.tab.c"
    break;

  case 9: /* random_definition_simple: HEIGHT  */
#line 84 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2072 "src-generated/ugbc.tab.c"
    break;

  case 10: /* random_definition: random_definition_simple  */
#line 89 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2080 "src-generated/ugbc.tab.c"
    break;

  case 11: /* color_enumeration: BLACK  */
#line 94 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2089 "src-generated/ugbc.tab.c"
    break;

  case 12: /* color_enumeration: WHITE  */
#line 98 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2098 "src-generated/ugbc.tab.c"
    break;

  case 13: /* color_enumeration: RED  */
#line 102 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2107 "src-generated/ugbc.tab.c"
    break;

  case 14: /* color_enumeration: CYAN  */
#line 106 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2116 "src-generated/ugbc.tab.c"
    break;

  case 15: /* color_enumeration: VIOLET  */
#line 110 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2125 "src-generated/ugbc.tab.c"
    break;

  case 16: /* color_enumeration: GREEN  */
#line 114 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2134 "src-generated/ugbc.tab.c"
    break;

  case 17: /* color_enumeration: BLUE  */
#line 118 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2143 "src-generated/ugbc.tab.c"
    break;

  case 18: /* color_enumeration: YELLOW  */
#line 122 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2152 "src-generated/ugbc.tab.c"
    break;

  case 19: /* color_enumeration: ORANGE  */
#line 126 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2161 "src-generated/ugbc.tab.c"
    break;

  case 20: /* color_enumeration: BROWN  */
#line 130 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2170 "src-generated/ugbc.tab.c"
    break;

  case 21: /* color_enumeration: LIGHT RED  */
#line 134 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2179 "src-generated/ugbc.tab.c"
    break;

  case 22: /* color_enumeration: DARK GREY  */
#line 138 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2188 "src-generated/ugbc.tab.c"
    break;

  case 23: /* color_enumeration: GREY  */
#line 142 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2197 "src-generated/ugbc.tab.c"
    break;

  case 24: /* color_enumeration: LIGHT GREEN  */
#line 146 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2206 "src-generated/ugbc.tab.c"
    break;

  case 25: /* color_enumeration: LIGHT BLUE  */
#line 150 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2215 "src-generated/ugbc.tab.c"
    break;

  case 26: /* color_enumeration: LIGHT GREY  */
#line 154 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2224 "src-generated/ugbc.tab.c"
    break;

  case 27: /* color_enumeration: DARK BLUE  */
#line 158 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2233 "src-generated/ugbc.tab.c"
    break;

  case 28: /* color_enumeration: MAGENTA  */
#line 162 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2242 "src-generated/ugbc.tab.c"
    break;

  case 29: /* color_enumeration: PURPLE  */
#line 166 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2251 "src-generated/ugbc.tab.c"
    break;

  case 30: /* color_enumeration: LAVENDER  */
#line 170 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2260 "src-generated/ugbc.tab.c"
    break;

  case 31: /* color_enumeration: GOLD  */
#line 174 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2269 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: TURQUOISE  */
#line 178 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2278 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: TAN  */
#line 182 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2287 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: YELLOW GREEN  */
#line 186 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2296 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: OLIVE GREEN  */
#line 190 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2305 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: PINK  */
#line 194 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2314 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: PEACH  */
#line 198 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2323 "src-generated/ugbc.tab.c"
    break;

  case 38: /* expression: Identifier  */
#line 204 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2331 "src-generated/ugbc.tab.c"
    break;

  case 39: /* expression: Integer  */
#line 207 "src/ugbc.y"
              { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2340 "src-generated/ugbc.tab.c"
    break;

  case 40: /* expression: OP BYTE CP Integer  */
#line 211 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2349 "src-generated/ugbc.tab.c"
    break;

  case 41: /* expression: OP WORD CP Integer  */
#line 215 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2358 "src-generated/ugbc.tab.c"
    break;

  case 42: /* expression: OP DWORD CP Integer  */
#line 219 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2367 "src-generated/ugbc.tab.c"
    break;

  case 43: /* expression: OP POSITION CP Integer  */
#line 223 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2376 "src-generated/ugbc.tab.c"
    break;

  case 44: /* expression: OP COLOR CP Integer  */
#line 227 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2385 "src-generated/ugbc.tab.c"
    break;

  case 45: /* expression: color_enumeration  */
#line 231 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2393 "src-generated/ugbc.tab.c"
    break;

  case 46: /* expression: PEEK OP direct_integer CP  */
#line 234 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2401 "src-generated/ugbc.tab.c"
    break;

  case 47: /* expression: PEEK OP expressions CP  */
#line 237 "src/ugbc.y"
                             {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 2409 "src-generated/ugbc.tab.c"
    break;

  case 48: /* expression: XPEN  */
#line 240 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 2417 "src-generated/ugbc.tab.c"
    break;

  case 49: /* expression: YPEN  */
#line 243 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 2425 "src-generated/ugbc.tab.c"
    break;

  case 50: /* expression: COLLISION OP direct_integer CP  */
#line 246 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2433 "src-generated/ugbc.tab.c"
    break;

  case 51: /* expression: COLLISION OP expressions CP  */
#line 249 "src/ugbc.y"
                                  {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2441 "src-generated/ugbc.tab.c"
    break;

  case 52: /* expression: HIT OP direct_integer CP  */
#line 252 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2449 "src-generated/ugbc.tab.c"
    break;

  case 53: /* expression: HIT OP expressions CP  */
#line 255 "src/ugbc.y"
                            {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2457 "src-generated/ugbc.tab.c"
    break;

  case 54: /* expression: RANDOM random_definition  */
#line 258 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 2465 "src-generated/ugbc.tab.c"
    break;

  case 55: /* expression: OP expression CP  */
#line 261 "src/ugbc.y"
                       {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 2473 "src-generated/ugbc.tab.c"
    break;

  case 56: /* expressions_raw: expression  */
#line 267 "src/ugbc.y"
                 { (yyval.string) = (yyvsp[0].string); }
#line 2479 "src-generated/ugbc.tab.c"
    break;

  case 57: /* expressions_raw: expression PLUS expressions_raw  */
#line 268 "src/ugbc.y"
                                      {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2487 "src-generated/ugbc.tab.c"
    break;

  case 58: /* expressions_raw: expression MINUS expressions_raw  */
#line 271 "src/ugbc.y"
                                       {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2496 "src-generated/ugbc.tab.c"
    break;

  case 59: /* expressions_raw: expression AND expressions_raw  */
#line 275 "src/ugbc.y"
                                     {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2505 "src-generated/ugbc.tab.c"
    break;

  case 60: /* expressions_raw: expression OR expressions_raw  */
#line 279 "src/ugbc.y"
                                    {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2514 "src-generated/ugbc.tab.c"
    break;

  case 61: /* expressions_raw: expression EQUAL expressions_raw  */
#line 283 "src/ugbc.y"
                                       {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2522 "src-generated/ugbc.tab.c"
    break;

  case 62: /* expressions: expressions_raw  */
#line 289 "src/ugbc.y"
                    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2530 "src-generated/ugbc.tab.c"
    break;

  case 65: /* bank_definition_simple: AT direct_integer  */
#line 296 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2538 "src-generated/ugbc.tab.c"
    break;

  case 66: /* bank_definition_simple: Identifier AT direct_integer  */
#line 299 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2546 "src-generated/ugbc.tab.c"
    break;

  case 67: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 302 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2554 "src-generated/ugbc.tab.c"
    break;

  case 68: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 305 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2562 "src-generated/ugbc.tab.c"
    break;

  case 69: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 308 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2570 "src-generated/ugbc.tab.c"
    break;

  case 70: /* bank_definition_simple: DATA AT direct_integer  */
#line 311 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2578 "src-generated/ugbc.tab.c"
    break;

  case 71: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 315 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2586 "src-generated/ugbc.tab.c"
    break;

  case 72: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 318 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2594 "src-generated/ugbc.tab.c"
    break;

  case 73: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 321 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2602 "src-generated/ugbc.tab.c"
    break;

  case 74: /* bank_definition_simple: CODE AT direct_integer  */
#line 324 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2610 "src-generated/ugbc.tab.c"
    break;

  case 75: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 328 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2618 "src-generated/ugbc.tab.c"
    break;

  case 76: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 331 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2626 "src-generated/ugbc.tab.c"
    break;

  case 77: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 334 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 2634 "src-generated/ugbc.tab.c"
    break;

  case 78: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 337 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 2642 "src-generated/ugbc.tab.c"
    break;

  case 79: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 341 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 2650 "src-generated/ugbc.tab.c"
    break;

  case 80: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 344 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 2658 "src-generated/ugbc.tab.c"
    break;

  case 81: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 347 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 2666 "src-generated/ugbc.tab.c"
    break;

  case 82: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 350 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 2674 "src-generated/ugbc.tab.c"
    break;

  case 83: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 356 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2682 "src-generated/ugbc.tab.c"
    break;

  case 84: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 359 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 2690 "src-generated/ugbc.tab.c"
    break;

  case 85: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 362 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2698 "src-generated/ugbc.tab.c"
    break;

  case 86: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 365 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 2706 "src-generated/ugbc.tab.c"
    break;

  case 87: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 368 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2714 "src-generated/ugbc.tab.c"
    break;

  case 90: /* raster_definition_simple: Identifier AT direct_integer  */
#line 377 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 2722 "src-generated/ugbc.tab.c"
    break;

  case 91: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 380 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 2730 "src-generated/ugbc.tab.c"
    break;

  case 92: /* raster_definition_expression: Identifier AT expressions  */
#line 385 "src/ugbc.y"
                              {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2738 "src-generated/ugbc.tab.c"
    break;

  case 93: /* raster_definition_expression: AT expressions WITH Identifier  */
#line 388 "src/ugbc.y"
                                   {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2746 "src-generated/ugbc.tab.c"
    break;

  case 96: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 397 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 2754 "src-generated/ugbc.tab.c"
    break;

  case 97: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 400 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 2762 "src-generated/ugbc.tab.c"
    break;

  case 98: /* next_raster_definition_expression: Identifier AT expressions  */
#line 405 "src/ugbc.y"
                              {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 2770 "src-generated/ugbc.tab.c"
    break;

  case 99: /* next_raster_definition_expression: AT expressions WITH Identifier  */
#line 408 "src/ugbc.y"
                                   {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2778 "src-generated/ugbc.tab.c"
    break;

  case 102: /* color_definition_simple: BORDER direct_integer  */
#line 417 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 2786 "src-generated/ugbc.tab.c"
    break;

  case 103: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 420 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 2794 "src-generated/ugbc.tab.c"
    break;

  case 104: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 423 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 2802 "src-generated/ugbc.tab.c"
    break;

  case 105: /* color_definition_expression: BORDER expressions  */
#line 428 "src/ugbc.y"
                       {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 2810 "src-generated/ugbc.tab.c"
    break;

  case 106: /* color_definition_expression: BACKGROUND expressions TO expressions  */
#line 431 "src/ugbc.y"
                                          {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 2818 "src-generated/ugbc.tab.c"
    break;

  case 107: /* color_definition_expression: SPRITE expressions TO expressions  */
#line 434 "src/ugbc.y"
                                      {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 2826 "src-generated/ugbc.tab.c"
    break;

  case 113: /* wait_definition_simple: direct_integer CYCLES  */
#line 448 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 2834 "src-generated/ugbc.tab.c"
    break;

  case 114: /* wait_definition_simple: direct_integer TICKS  */
#line 451 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 2842 "src-generated/ugbc.tab.c"
    break;

  case 115: /* wait_definition_simple: direct_integer milliseconds  */
#line 454 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 2850 "src-generated/ugbc.tab.c"
    break;

  case 116: /* wait_definition_expression: expressions CYCLES  */
#line 459 "src/ugbc.y"
                         {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 2858 "src-generated/ugbc.tab.c"
    break;

  case 117: /* wait_definition_expression: expressions TICKS  */
#line 462 "src/ugbc.y"
                        {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 2866 "src-generated/ugbc.tab.c"
    break;

  case 118: /* wait_definition_expression: expressions milliseconds  */
#line 465 "src/ugbc.y"
                               {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 2874 "src-generated/ugbc.tab.c"
    break;

  case 121: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 475 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 2882 "src-generated/ugbc.tab.c"
    break;

  case 122: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 478 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 2890 "src-generated/ugbc.tab.c"
    break;

  case 123: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 481 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 2898 "src-generated/ugbc.tab.c"
    break;

  case 124: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 484 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 2906 "src-generated/ugbc.tab.c"
    break;

  case 125: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 487 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 2914 "src-generated/ugbc.tab.c"
    break;

  case 126: /* sprite_definition_simple: direct_integer ENABLE  */
#line 490 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 2922 "src-generated/ugbc.tab.c"
    break;

  case 127: /* sprite_definition_simple: direct_integer DISABLE  */
#line 493 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 2930 "src-generated/ugbc.tab.c"
    break;

  case 128: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 496 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 2938 "src-generated/ugbc.tab.c"
    break;

  case 129: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 499 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 2946 "src-generated/ugbc.tab.c"
    break;

  case 130: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 502 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 2954 "src-generated/ugbc.tab.c"
    break;

  case 131: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 505 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 2962 "src-generated/ugbc.tab.c"
    break;

  case 132: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 508 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 2970 "src-generated/ugbc.tab.c"
    break;

  case 133: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 511 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 2978 "src-generated/ugbc.tab.c"
    break;

  case 134: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 514 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 2986 "src-generated/ugbc.tab.c"
    break;

  case 135: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 517 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 2994 "src-generated/ugbc.tab.c"
    break;

  case 136: /* sprite_definition_expression: expressions DATA FROM expressions  */
#line 522 "src/ugbc.y"
                                      {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3002 "src-generated/ugbc.tab.c"
    break;

  case 137: /* sprite_definition_expression: expressions MULTICOLOR  */
#line 525 "src/ugbc.y"
                           {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3010 "src-generated/ugbc.tab.c"
    break;

  case 138: /* sprite_definition_expression: expressions MONOCOLOR  */
#line 528 "src/ugbc.y"
                          {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3018 "src-generated/ugbc.tab.c"
    break;

  case 139: /* sprite_definition_expression: expressions COLOR expressions  */
#line 531 "src/ugbc.y"
                                  {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3026 "src-generated/ugbc.tab.c"
    break;

  case 140: /* sprite_definition_expression: expressions position OP expressions COMMA expressions CP  */
#line 534 "src/ugbc.y"
                                                             {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3034 "src-generated/ugbc.tab.c"
    break;

  case 141: /* sprite_definition_expression: expressions ENABLE  */
#line 537 "src/ugbc.y"
                       {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3042 "src-generated/ugbc.tab.c"
    break;

  case 142: /* sprite_definition_expression: expressions DISABLE  */
#line 540 "src/ugbc.y"
                        {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3050 "src-generated/ugbc.tab.c"
    break;

  case 143: /* sprite_definition_expression: expressions EXPAND VERTICAL  */
#line 543 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3058 "src-generated/ugbc.tab.c"
    break;

  case 144: /* sprite_definition_expression: expressions COMPRESS VERTICAL  */
#line 546 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3066 "src-generated/ugbc.tab.c"
    break;

  case 145: /* sprite_definition_expression: expressions VERTICAL EXPAND  */
#line 549 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3074 "src-generated/ugbc.tab.c"
    break;

  case 146: /* sprite_definition_expression: expressions VERTICAL COMPRESS  */
#line 552 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3082 "src-generated/ugbc.tab.c"
    break;

  case 147: /* sprite_definition_expression: expressions EXPAND HORIZONTAL  */
#line 555 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3090 "src-generated/ugbc.tab.c"
    break;

  case 148: /* sprite_definition_expression: expressions COMPRESS HORIZONTAL  */
#line 558 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3098 "src-generated/ugbc.tab.c"
    break;

  case 149: /* sprite_definition_expression: expressions HORIZONTAL EXPAND  */
#line 561 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3106 "src-generated/ugbc.tab.c"
    break;

  case 150: /* sprite_definition_expression: expressions HORIZONTAL COMPRESS  */
#line 564 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3114 "src-generated/ugbc.tab.c"
    break;

  case 153: /* bitmap_definition_simple: AT direct_integer  */
#line 573 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3122 "src-generated/ugbc.tab.c"
    break;

  case 154: /* bitmap_definition_simple: ENABLE  */
#line 576 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3130 "src-generated/ugbc.tab.c"
    break;

  case 155: /* bitmap_definition_simple: DISABLE  */
#line 579 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 3138 "src-generated/ugbc.tab.c"
    break;

  case 156: /* bitmap_definition_simple: CLEAR  */
#line 582 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 3146 "src-generated/ugbc.tab.c"
    break;

  case 157: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 585 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 3154 "src-generated/ugbc.tab.c"
    break;

  case 158: /* bitmap_definition_expression: AT expressions  */
#line 591 "src/ugbc.y"
                   {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3162 "src-generated/ugbc.tab.c"
    break;

  case 159: /* bitmap_definition_expression: CLEAR WITH expressions  */
#line 594 "src/ugbc.y"
                           {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 3170 "src-generated/ugbc.tab.c"
    break;

  case 162: /* textmap_definition_simple: AT direct_integer  */
#line 604 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3178 "src-generated/ugbc.tab.c"
    break;

  case 163: /* textmap_definition_expression: AT expressions  */
#line 609 "src/ugbc.y"
                   {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3186 "src-generated/ugbc.tab.c"
    break;

  case 166: /* text_definition_simple: ENABLE  */
#line 618 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3194 "src-generated/ugbc.tab.c"
    break;

  case 167: /* text_definition_simple: DISABLE  */
#line 621 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 3202 "src-generated/ugbc.tab.c"
    break;

  case 169: /* tiles_definition_simple: AT direct_integer  */
#line 629 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 3210 "src-generated/ugbc.tab.c"
    break;

  case 170: /* tiles_definition_expression: AT expressions  */
#line 634 "src/ugbc.y"
                   {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 3218 "src-generated/ugbc.tab.c"
    break;

  case 173: /* colormap_definition_simple: AT direct_integer  */
#line 643 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 3226 "src-generated/ugbc.tab.c"
    break;

  case 174: /* colormap_definition_simple: CLEAR  */
#line 646 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 3234 "src-generated/ugbc.tab.c"
    break;

  case 175: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 649 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3242 "src-generated/ugbc.tab.c"
    break;

  case 176: /* colormap_definition_expression: AT expressions  */
#line 654 "src/ugbc.y"
                   {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3250 "src-generated/ugbc.tab.c"
    break;

  case 177: /* colormap_definition_expression: CLEAR WITH expressions ON expressions  */
#line 657 "src/ugbc.y"
                                          {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3258 "src-generated/ugbc.tab.c"
    break;

  case 180: /* screen_definition_simple: ON  */
#line 667 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 3266 "src-generated/ugbc.tab.c"
    break;

  case 181: /* screen_definition_simple: OFF  */
#line 670 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 3274 "src-generated/ugbc.tab.c"
    break;

  case 182: /* screen_definition_simple: ROWS direct_integer  */
#line 673 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 3282 "src-generated/ugbc.tab.c"
    break;

  case 183: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 676 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3290 "src-generated/ugbc.tab.c"
    break;

  case 184: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 679 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3298 "src-generated/ugbc.tab.c"
    break;

  case 185: /* screen_definition_expression: ROWS expressions  */
#line 684 "src/ugbc.y"
                     {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 3306 "src-generated/ugbc.tab.c"
    break;

  case 186: /* screen_definition_expression: VERTICAL SCROLL expressions  */
#line 687 "src/ugbc.y"
                                {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3314 "src-generated/ugbc.tab.c"
    break;

  case 187: /* screen_definition_expression: HORIZONTAL SCROLL expressions  */
#line 690 "src/ugbc.y"
                                  {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3322 "src-generated/ugbc.tab.c"
    break;

  case 191: /* var_definition_simple: Identifier ON Identifier  */
#line 699 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 3330 "src-generated/ugbc.tab.c"
    break;

  case 192: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 702 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 3338 "src-generated/ugbc.tab.c"
    break;

  case 193: /* var_definition_simple: Identifier ON Identifier ASSIGN expressions  */
#line 705 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      if ( v == NULL ) {
          CRITICAL("Variable not found");
      }
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 3351 "src-generated/ugbc.tab.c"
    break;

  case 194: /* goto_definition: Identifier  */
#line 715 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 3359 "src-generated/ugbc.tab.c"
    break;

  case 195: /* goto_definition: Integer  */
#line 718 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 3367 "src-generated/ugbc.tab.c"
    break;

  case 196: /* gosub_definition: Identifier  */
#line 724 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 3375 "src-generated/ugbc.tab.c"
    break;

  case 197: /* gosub_definition: Integer  */
#line 727 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 3383 "src-generated/ugbc.tab.c"
    break;

  case 199: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 736 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 3391 "src-generated/ugbc.tab.c"
    break;

  case 200: /* point_definition_expression: AT OP expressions COMMA expressions CP  */
#line 742 "src/ugbc.y"
                                             {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 3399 "src-generated/ugbc.tab.c"
    break;

  case 217: /* statement: RANDOMIZE  */
#line 765 "src/ugbc.y"
              {
      randomize( _environment );
  }
#line 3407 "src-generated/ugbc.tab.c"
    break;

  case 218: /* $@1: %empty  */
#line 768 "src/ugbc.y"
                   {
      if_then( _environment, (yyvsp[0].string) );  
  }
#line 3415 "src-generated/ugbc.tab.c"
    break;

  case 219: /* $@2: %empty  */
#line 770 "src/ugbc.y"
                                   {
      end_if_then( _environment );
  }
#line 3423 "src-generated/ugbc.tab.c"
    break;

  case 221: /* statement: BEG GAMELOOP  */
#line 773 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 3431 "src-generated/ugbc.tab.c"
    break;

  case 222: /* statement: END GAMELOOP  */
#line 776 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 3439 "src-generated/ugbc.tab.c"
    break;

  case 223: /* statement: GRAPHIC  */
#line 779 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 3447 "src-generated/ugbc.tab.c"
    break;

  case 224: /* statement: HALT  */
#line 782 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 3455 "src-generated/ugbc.tab.c"
    break;

  case 227: /* statement: RETURN  */
#line 787 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 3463 "src-generated/ugbc.tab.c"
    break;

  case 228: /* statement: POP  */
#line 790 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 3471 "src-generated/ugbc.tab.c"
    break;

  case 229: /* statement: DONE  */
#line 793 "src/ugbc.y"
          {
      return 0;
  }
#line 3479 "src-generated/ugbc.tab.c"
    break;

  case 230: /* statement: Identifier COLON  */
#line 796 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 3487 "src-generated/ugbc.tab.c"
    break;

  case 231: /* statement: Identifier ASSIGN expressions  */
#line 799 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expressions = variable_retrieve( _environment, (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expressions->type, 0 )->name;
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 3498 "src-generated/ugbc.tab.c"
    break;

  case 232: /* statement: DEBUG expressions  */
#line 805 "src/ugbc.y"
                      {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 3506 "src-generated/ugbc.tab.c"
    break;

  case 235: /* statements_no_linenumbers: statement  */
#line 813 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 3512 "src-generated/ugbc.tab.c"
    break;

  case 236: /* $@3: %empty  */
#line 814 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 3518 "src-generated/ugbc.tab.c"
    break;

  case 238: /* $@4: %empty  */
#line 818 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 3526 "src-generated/ugbc.tab.c"
    break;

  case 239: /* statements_with_linenumbers: Integer $@4 statements_no_linenumbers  */
#line 820 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 3534 "src-generated/ugbc.tab.c"
    break;


#line 3538 "src-generated/ugbc.tab.c"

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

#line 834 "src/ugbc.y"


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

