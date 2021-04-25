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
  YYSYMBOL_BLACK = 94,                     /* BLACK  */
  YYSYMBOL_WHITE = 95,                     /* WHITE  */
  YYSYMBOL_RED = 96,                       /* RED  */
  YYSYMBOL_CYAN = 97,                      /* CYAN  */
  YYSYMBOL_VIOLET = 98,                    /* VIOLET  */
  YYSYMBOL_GREEN = 99,                     /* GREEN  */
  YYSYMBOL_BLUE = 100,                     /* BLUE  */
  YYSYMBOL_YELLOW = 101,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 102,                   /* ORANGE  */
  YYSYMBOL_BROWN = 103,                    /* BROWN  */
  YYSYMBOL_LIGHT = 104,                    /* LIGHT  */
  YYSYMBOL_DARK = 105,                     /* DARK  */
  YYSYMBOL_GREY = 106,                     /* GREY  */
  YYSYMBOL_GRAY = 107,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 108,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 109,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 110,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 111,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 112,                /* TURQUOISE  */
  YYSYMBOL_TAN = 113,                      /* TAN  */
  YYSYMBOL_PINK = 114,                     /* PINK  */
  YYSYMBOL_PEACH = 115,                    /* PEACH  */
  YYSYMBOL_OLIVE = 116,                    /* OLIVE  */
  YYSYMBOL_Identifier = 117,               /* Identifier  */
  YYSYMBOL_String = 118,                   /* String  */
  YYSYMBOL_Integer = 119,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 120,                 /* $accept  */
  YYSYMBOL_direct_integer = 121,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 122, /* random_definition_simple  */
  YYSYMBOL_random_definition = 123,        /* random_definition  */
  YYSYMBOL_color_enumeration = 124,        /* color_enumeration  */
  YYSYMBOL_expression = 125,               /* expression  */
  YYSYMBOL_expressions_raw = 126,          /* expressions_raw  */
  YYSYMBOL_expressions = 127,              /* expressions  */
  YYSYMBOL_position = 128,                 /* position  */
  YYSYMBOL_bank_definition_simple = 129,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 130, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 131,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 132, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 133, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 134,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 135, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 136, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 137,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 138,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 139, /* color_definition_expression  */
  YYSYMBOL_color_definition = 140,         /* color_definition  */
  YYSYMBOL_wait_definition_simple = 141,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 142, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 143,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 144, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 145, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 146,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 147, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 148, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 149,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 150, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 151, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 152,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 153,   /* text_definition_simple  */
  YYSYMBOL_text_definition = 154,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 155,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 156, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 157,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 158, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 159, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 160,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 161, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 162, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 163,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 164,    /* var_definition_simple  */
  YYSYMBOL_var_definition = 165,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 166,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 167, /* point_definition_expression  */
  YYSYMBOL_point_definition = 168,         /* point_definition  */
  YYSYMBOL_statement = 169,                /* statement  */
  YYSYMBOL_170_1 = 170,                    /* $@1  */
  YYSYMBOL_171_2 = 171,                    /* $@2  */
  YYSYMBOL_statements_no_linenumbers = 172, /* statements_no_linenumbers  */
  YYSYMBOL_173_3 = 173,                    /* $@3  */
  YYSYMBOL_statements_with_linenumbers = 174, /* statements_with_linenumbers  */
  YYSYMBOL_175_4 = 175,                    /* $@4  */
  YYSYMBOL_statements_complex = 176,       /* statements_complex  */
  YYSYMBOL_program = 177                   /* program  */
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
#define YYFINAL  147
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   556

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  120
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  218
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  378

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   374


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
     115,   116,   117,   118,   119
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    63,    66,    69,    72,    75,    78,    81,
      86,    91,    95,    99,   103,   107,   111,   115,   119,   123,
     127,   131,   135,   139,   143,   147,   151,   155,   159,   163,
     167,   171,   175,   179,   183,   187,   191,   195,   201,   204,
     208,   212,   216,   220,   224,   228,   231,   234,   237,   240,
     243,   246,   249,   252,   255,   258,   264,   265,   268,   272,
     278,   282,   282,   285,   288,   291,   294,   297,   300,   303,
     306,   309,   314,   317,   320,   323,   326,   331,   332,   335,
     338,   343,   346,   351,   352,   355,   358,   363,   366,   371,
     372,   375,   378,   381,   386,   389,   392,   397,   398,   401,
     406,   411,   412,   415,   418,   421,   424,   427,   430,   433,
     436,   439,   442,   445,   448,   451,   454,   457,   462,   465,
     468,   471,   474,   477,   480,   483,   486,   489,   492,   495,
     498,   501,   504,   509,   510,   513,   516,   519,   522,   525,
     531,   534,   540,   541,   544,   549,   554,   555,   558,   561,
     566,   569,   574,   579,   580,   583,   586,   589,   594,   597,
     603,   604,   607,   610,   613,   616,   619,   624,   627,   630,
     635,   636,   638,   639,   642,   647,   650,   656,   661,   662,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   682,   684,   682,   687,   690,
     693,   696,   699,   702,   705,   708,   714,   717,   718,   722,
     723,   723,   727,   727,   734,   735,   736,   737,   741
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
  "AND", "RANDOMIZE", "GRAPHIC", "TEXTMAP", "POINT", "BLACK", "WHITE",
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
  "color_definition", "wait_definition_simple",
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
  "screen_definition", "var_definition_simple", "var_definition",
  "point_definition_simple", "point_definition_expression",
  "point_definition", "statement", "$@1", "$@2",
  "statements_no_linenumbers", "$@3", "statements_with_linenumbers", "$@4",
  "statements_complex", "program", YY_NULLPTR
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
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374
};
#endif

#define YYPACT_NINF (-142)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      55,  -142,   -15,  -142,    18,   411,    13,   -18,   411,  -142,
     -12,    25,  -110,   -75,    67,    37,   -11,   437,   -16,    -9,
     437,  -142,  -142,    40,    74,     9,  -142,    97,   101,   103,
    -142,   111,   411,   116,  -142,  -142,  -142,   411,   411,   411,
    -142,  -142,  -142,   330,  -142,  -142,   114,   115,   118,    16,
      30,  -142,  -142,  -142,  -142,  -142,  -142,  -142,    38,  -142,
    -142,   -20,   -56,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,    52,  -142,  -142,    81,  -142,   105,  -142,    86,
    -142,  -142,  -142,   -13,    35,    42,    43,    44,   138,  -142,
    -142,  -142,    -3,   166,  -142,  -142,  -142,   411,  -142,  -142,
     141,  -142,  -142,  -142,  -142,  -142,   411,   129,   130,  -142,
    -142,  -142,   135,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
     411,  -142,  -142,  -142,   411,   149,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,   411,  -142,  -142,  -142,   145,  -142,  -142,
    -142,  -142,   437,   273,  -142,    55,    55,  -142,   152,   154,
     411,  -142,  -142,   112,   113,   120,   121,   151,   153,   159,
     160,   161,   164,   411,   411,   411,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,   437,   437,   437,  -142,   411,
     163,  -142,  -142,  -142,   176,   177,   180,   181,   125,  -142,
     125,   182,  -142,  -142,    70,    78,   -27,   -26,  -142,  -142,
    -142,   175,   437,   183,  -142,  -142,    80,    82,     3,    11,
    -142,  -142,   179,  -142,  -142,   411,  -142,  -142,   411,   411,
      85,  -142,  -142,  -142,  -142,   411,   148,  -142,  -142,   411,
    -142,  -142,   273,  -142,  -142,    89,    93,  -142,  -142,   125,
     437,   125,   437,    92,    94,    99,   100,   107,  -142,   189,
     195,   203,   205,   206,   209,  -142,  -142,  -142,   216,   217,
     411,   125,   125,   125,   125,     7,  -142,   125,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,   125,  -142,   437,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,   437,  -142,  -142,
    -142,  -142,  -142,  -142,   227,   207,   211,   273,   236,   239,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,   131,   133,
    -142,  -142,   226,  -142,   231,  -142,   136,    -6,  -142,   246,
    -142,   248,   125,   125,   437,  -142,   125,   437,  -142,  -142,
     139,   140,  -142,   235,  -142,   238,  -142,   125,   437,  -142,
    -142,  -142,   178,   233,   237,  -142,  -142,   147,   150,   240,
     242,  -142,  -142,  -142,  -142,  -142,  -142,  -142
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     208,   207,     0,   203,     0,     0,     0,     0,     0,   201,
       0,     0,   172,     0,     0,     0,     0,     0,     0,     0,
       0,   194,   200,     0,     0,     0,   212,   209,   214,   216,
     218,     0,     0,     0,    83,    84,   181,     0,     0,     0,
      97,    98,   183,     0,    48,    49,     0,     0,     0,     0,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,    23,    28,    29,    30,    31,    32,    33,
      36,    37,     0,    38,    39,     0,    45,    56,    60,     0,
     101,   102,   184,     0,     0,     0,     0,     0,     0,    77,
      78,   180,     0,     0,   133,   134,   185,     0,   136,   137,
     138,   142,   143,   186,   162,   163,     0,     0,     0,   170,
     171,   191,     0,   175,   193,   202,   148,   149,   150,   188,
       0,   153,   154,   189,     0,   156,   160,   161,   190,   195,
     198,   199,   206,     0,   146,   147,   187,     0,   178,   179,
     192,   204,     0,   208,   210,   208,   208,     1,     0,     0,
       0,    91,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     3,     4,     6,
       8,     9,     5,    10,    54,     2,    34,    21,    24,    25,
      26,    27,    22,    35,    99,     0,     0,     0,   100,     0,
       0,    89,    90,   182,     0,     0,     0,     0,     0,    62,
       0,     0,   108,   109,     0,     0,     0,     0,   105,   104,
      61,     0,     0,     0,   123,   124,     0,     0,     0,     0,
     120,   119,     0,   135,   140,     0,   164,   167,     0,     0,
       0,   151,   152,   155,   158,     0,     0,   144,   145,     0,
     205,   213,   208,   215,   217,     0,     0,    79,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,    57,    58,    59,     0,     0,
       0,     0,     0,     0,     0,    63,   106,     0,   113,   112,
     117,   116,   111,   115,   110,   114,     0,   121,     0,   128,
     127,   132,   131,   126,   130,   125,   129,     0,   139,   141,
     165,   168,   166,   169,   173,     0,     0,   208,     0,     0,
     211,    80,    82,    93,    96,    92,    95,    44,    40,    41,
      43,    42,    46,    47,    50,    51,    52,    53,     0,     0,
      85,    87,    65,    71,    67,    69,     0,     0,   103,     0,
     118,     0,     0,     0,     0,   196,     0,     0,    86,    88,
       0,     0,    72,    64,    70,    66,    68,     0,     0,   174,
     157,   159,     0,     0,     0,    74,    76,     0,     0,     0,
       0,   197,   176,   177,    73,    75,   107,   122
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,     0,  -142,  -142,  -142,   220,   -64,    -8,   173,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -141,  -142,  -142,  -142,    -7,  -142
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    75,   173,   174,    76,    77,    78,    79,   211,    89,
      90,    91,    34,    35,    36,   191,   192,   193,    40,    41,
      42,    80,    81,    82,    94,    95,    96,   101,   102,   103,
     134,   135,   136,   118,   119,   121,   122,   123,   126,   127,
     128,   109,   110,   111,   113,   114,   138,   139,   140,    27,
     236,   362,    28,   242,    29,   143,    30,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      93,    32,   241,   189,    97,   124,    84,   112,    92,   129,
     282,   284,   132,   199,   200,   141,    98,    99,   353,   283,
     285,   201,   142,    85,   149,   202,   203,    83,   336,   152,
     154,   156,   148,   166,   204,   354,    37,   151,   153,   155,
     293,    38,   115,   205,   181,   206,   207,   337,   295,   294,
     182,    86,    87,   120,   208,   209,   133,   296,     1,   104,
     105,   106,   107,   355,   356,   210,   130,   100,   125,     2,
       3,   108,     4,   131,     5,     6,   177,     7,     8,   178,
     179,    39,   167,   168,   169,     9,   180,    10,    11,   224,
     137,   170,   171,   172,    12,   116,   117,   223,   227,    88,
      13,   310,    33,   144,   190,   145,   226,   146,    14,    15,
      16,   147,   232,   185,   186,    17,   234,   187,   278,   279,
     231,   265,   266,   267,   233,   238,   280,   281,   289,   290,
     291,   292,   150,   237,   240,    18,    19,   176,   243,   244,
     163,   164,   248,    20,   165,    21,    22,    23,    24,   175,
     247,   183,   194,   184,   198,   260,   262,   264,   188,   195,
     196,   197,   225,   259,   261,   263,   345,   228,   229,   230,
     235,   239,    25,   245,    26,   246,   249,   250,   253,   270,
     254,   269,   199,   212,   251,   252,   255,   256,   257,   268,
     213,   258,   271,   272,   214,   215,   273,   274,   275,    50,
     276,   286,   304,   216,   287,   297,   311,   277,   288,   307,
     312,   317,   217,   318,   218,   219,   322,   299,   319,   320,
     301,   303,   323,   220,   221,   298,   321,   306,   300,   302,
     324,   309,   325,   326,   210,   305,   327,   328,   329,   308,
     342,   343,   314,   346,   316,   344,   347,   350,   348,   313,
     349,   315,   351,   357,   352,   358,   367,   365,   366,   368,
     372,   371,   331,   162,   373,   374,   222,   376,   375,   377,
     330,   332,   333,   334,   335,     0,     1,   338,     0,     0,
     340,     0,     0,     0,     0,     0,   339,     2,     3,   341,
       4,     0,     5,     6,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     9,     0,    10,    11,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,     0,     0,    14,    15,    16,     0,
       0,     0,     0,    17,     0,     0,   361,     0,     0,   364,
       0,     0,   359,   360,     0,     0,   363,   157,     0,     0,
     370,     0,     0,    18,    19,     0,    43,   369,     0,     0,
       0,    20,     0,    21,    22,    23,    24,     0,     0,     0,
       0,     0,    44,    45,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      25,     0,    48,     0,     0,    49,   158,   159,   160,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    43,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,    74,
       0,     0,     0,    44,    45,    46,     0,     0,     0,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
      47,     0,     0,    48,     0,     0,    49,     0,     0,    44,
      45,    46,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,     0,    48,
       0,     0,    49,     0,     0,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
      74,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74
};

static const yytype_int16 yycheck[] =
{
       8,    16,   143,    16,    16,    16,    24,   117,     8,    17,
      37,    37,    20,    16,    17,     6,    28,    29,    24,    46,
      46,    24,    13,    41,    32,    28,    29,    14,    21,    37,
      38,    39,    32,    17,    37,    41,    18,    37,    38,    39,
      37,    23,   117,    46,   100,    48,    49,    40,    37,    46,
     106,    69,    70,    16,    57,    58,    16,    46,     3,    34,
      35,    36,    37,    69,    70,    68,    82,    79,    79,    14,
      15,    46,    17,    82,    19,    20,    96,    22,    23,    99,
     100,    63,    66,    67,    68,    30,   106,    32,    33,    97,
      16,    75,    76,    77,    39,    28,    29,    97,   106,   117,
      45,   242,   117,     6,   117,     4,   106,     4,    53,    54,
      55,     0,   120,     8,     9,    60,   124,    12,    48,    49,
     120,   185,   186,   187,   124,   133,    48,    49,    48,    49,
      48,    49,    16,   133,   142,    80,    81,    99,   145,   146,
      26,    26,   150,    88,    26,    90,    91,    92,    93,   119,
     150,    99,   117,    72,    16,   163,   164,   165,    72,   117,
     117,   117,    21,   163,   164,   165,   307,    38,    38,    34,
      21,    26,   117,    21,   119,    21,    64,    64,    27,    16,
      27,   189,    16,    17,    64,    64,    27,    27,    27,   189,
      24,    27,    16,    16,    28,    29,    16,    16,   198,    74,
     200,    26,   117,    37,   212,    26,   117,    25,    25,    61,
     117,   119,    46,   119,    48,    49,    27,   225,   119,   119,
     228,   229,    27,    57,    58,   225,   119,   235,   228,   229,
      27,   239,    27,    27,    68,   235,    27,    21,    21,   239,
      13,    34,   250,     7,   252,    34,     7,    21,   117,   249,
     117,   251,    21,     7,   118,     7,    21,   118,   118,    21,
      27,    83,   270,    43,    27,   118,    93,    27,   118,    27,
     270,   271,   272,   273,   274,    -1,     3,   277,    -1,    -1,
     288,    -1,    -1,    -1,    -1,    -1,   286,    14,    15,   297,
      17,    -1,    19,    20,    -1,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    -1,
      -1,    -1,    -1,    60,    -1,    -1,   344,    -1,    -1,   347,
      -1,    -1,   342,   343,    -1,    -1,   346,    17,    -1,    -1,
     358,    -1,    -1,    80,    81,    -1,    26,   357,    -1,    -1,
      -1,    88,    -1,    90,    91,    92,    93,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
     117,    -1,    62,    -1,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    26,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,    -1,   119,
      -1,    -1,    -1,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    62,    -1,    -1,    65,    -1,    -1,    42,
      43,    44,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    62,
      -1,    -1,    65,    -1,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
     119,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    -1,   119
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    14,    15,    17,    19,    20,    22,    23,    30,
      32,    33,    39,    45,    53,    54,    55,    60,    80,    81,
      88,    90,    91,    92,    93,   117,   119,   169,   172,   174,
     176,   177,    16,   117,   132,   133,   134,    18,    23,    63,
     138,   139,   140,    26,    42,    43,    44,    59,    62,    65,
      74,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   119,   121,   124,   125,   126,   127,
     141,   142,   143,    14,    24,    41,    69,    70,   117,   129,
     130,   131,   121,   127,   144,   145,   146,    16,    28,    29,
      79,   147,   148,   149,    34,    35,    36,    37,    46,   161,
     162,   163,   117,   164,   165,   117,    28,    29,   153,   154,
      16,   155,   156,   157,    16,    79,   158,   159,   160,   127,
      82,    82,   127,    16,   150,   151,   152,    16,   166,   167,
     168,     6,    13,   175,     6,     4,     4,     0,   121,   127,
      16,   121,   127,   121,   127,   121,   127,    17,    66,    67,
      68,    77,   125,    26,    26,    26,    17,    66,    67,    68,
      75,    76,    77,   122,   123,   119,    99,    96,    99,   100,
     106,   100,   106,    99,    72,     8,     9,    12,    72,    16,
     117,   135,   136,   137,   117,   117,   117,   117,    16,    16,
      17,    24,    28,    29,    37,    46,    48,    49,    57,    58,
      68,   128,    17,    24,    28,    29,    37,    46,    48,    49,
      57,    58,   128,   121,   127,    21,   121,   127,    38,    38,
      34,   121,   127,   121,   127,    21,   170,   121,   127,    26,
     127,   172,   173,   176,   176,    21,    21,   121,   127,    64,
      64,    64,    64,    27,    27,    27,    27,    27,    27,   121,
     127,   121,   127,   121,   127,   126,   126,   126,   121,   127,
      16,    16,    16,    16,    16,   121,   121,    25,    48,    49,
      48,    49,    37,    46,    37,    46,    26,   127,    25,    48,
      49,    48,    49,    37,    46,    37,    46,    26,   121,   127,
     121,   127,   121,   127,   117,   121,   127,    61,   121,   127,
     172,   117,   117,   121,   127,   121,   127,   119,   119,   119,
     119,   119,    27,    27,    27,    27,    27,    27,    21,    21,
     121,   127,   121,   121,   121,   121,    21,    40,   121,   121,
     127,   127,    13,    34,    34,   172,     7,     7,   117,   117,
      21,    21,   118,    24,    41,    69,    70,     7,     7,   121,
     121,   127,   171,   121,   127,   118,   118,    21,    21,   121,
     127,    83,    27,    27,   118,   118,    27,    27
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   120,   121,   122,   122,   122,   122,   122,   122,   122,
     123,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   126,   126,   126,   126,
     127,   128,   128,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   130,   130,   130,   130,   130,   131,   131,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   138,   138,   138,   139,   139,   139,   140,   140,   141,
     142,   143,   143,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   146,   146,   147,   147,   147,   147,   147,
     148,   148,   149,   149,   150,   151,   152,   152,   153,   153,
     154,   155,   156,   157,   157,   158,   158,   158,   159,   159,
     160,   160,   161,   161,   161,   161,   161,   162,   162,   162,
     163,   163,   164,   164,   164,   165,   166,   167,   168,   168,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   170,   171,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   172,
     173,   172,   175,   174,   176,   176,   176,   176,   177
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
       1,     1,     1,     3,     5,     4,     5,     4,     5,     4,
       5,     4,     5,     7,     6,     7,     6,     1,     1,     3,
       4,     3,     4,     1,     1,     3,     4,     3,     4,     1,
       1,     2,     4,     4,     2,     4,     4,     1,     1,     2,
       2,     1,     1,     4,     2,     2,     3,     7,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     2,
       2,     3,     7,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     2,     1,     1,     1,     3,
       2,     3,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     2,     1,     5,     2,     5,
       1,     1,     1,     1,     2,     3,     3,     2,     3,     3,
       1,     1,     0,     3,     5,     1,     6,     6,     1,     1,
       2,     2,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     0,     0,     7,     2,     2,
       1,     1,     2,     1,     2,     3,     2,     1,     0,     1,
       0,     4,     0,     3,     1,     3,     1,     3,     1
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
#line 58 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 1958 "src-generated/ugbc.tab.c"
    break;

  case 3: /* random_definition_simple: BYTE  */
#line 63 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 1966 "src-generated/ugbc.tab.c"
    break;

  case 4: /* random_definition_simple: WORD  */
#line 66 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 1974 "src-generated/ugbc.tab.c"
    break;

  case 5: /* random_definition_simple: DWORD  */
#line 69 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 1982 "src-generated/ugbc.tab.c"
    break;

  case 6: /* random_definition_simple: POSITION  */
#line 72 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 1990 "src-generated/ugbc.tab.c"
    break;

  case 7: /* random_definition_simple: COLOR  */
#line 75 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 1998 "src-generated/ugbc.tab.c"
    break;

  case 8: /* random_definition_simple: WIDTH  */
#line 78 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2006 "src-generated/ugbc.tab.c"
    break;

  case 9: /* random_definition_simple: HEIGHT  */
#line 81 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2014 "src-generated/ugbc.tab.c"
    break;

  case 10: /* random_definition: random_definition_simple  */
#line 86 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2022 "src-generated/ugbc.tab.c"
    break;

  case 11: /* color_enumeration: BLACK  */
#line 91 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2031 "src-generated/ugbc.tab.c"
    break;

  case 12: /* color_enumeration: WHITE  */
#line 95 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2040 "src-generated/ugbc.tab.c"
    break;

  case 13: /* color_enumeration: RED  */
#line 99 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2049 "src-generated/ugbc.tab.c"
    break;

  case 14: /* color_enumeration: CYAN  */
#line 103 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2058 "src-generated/ugbc.tab.c"
    break;

  case 15: /* color_enumeration: VIOLET  */
#line 107 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2067 "src-generated/ugbc.tab.c"
    break;

  case 16: /* color_enumeration: GREEN  */
#line 111 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2076 "src-generated/ugbc.tab.c"
    break;

  case 17: /* color_enumeration: BLUE  */
#line 115 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2085 "src-generated/ugbc.tab.c"
    break;

  case 18: /* color_enumeration: YELLOW  */
#line 119 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2094 "src-generated/ugbc.tab.c"
    break;

  case 19: /* color_enumeration: ORANGE  */
#line 123 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2103 "src-generated/ugbc.tab.c"
    break;

  case 20: /* color_enumeration: BROWN  */
#line 127 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2112 "src-generated/ugbc.tab.c"
    break;

  case 21: /* color_enumeration: LIGHT RED  */
#line 131 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2121 "src-generated/ugbc.tab.c"
    break;

  case 22: /* color_enumeration: DARK GREY  */
#line 135 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2130 "src-generated/ugbc.tab.c"
    break;

  case 23: /* color_enumeration: GREY  */
#line 139 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2139 "src-generated/ugbc.tab.c"
    break;

  case 24: /* color_enumeration: LIGHT GREEN  */
#line 143 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2148 "src-generated/ugbc.tab.c"
    break;

  case 25: /* color_enumeration: LIGHT BLUE  */
#line 147 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2157 "src-generated/ugbc.tab.c"
    break;

  case 26: /* color_enumeration: LIGHT GREY  */
#line 151 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2166 "src-generated/ugbc.tab.c"
    break;

  case 27: /* color_enumeration: DARK BLUE  */
#line 155 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2175 "src-generated/ugbc.tab.c"
    break;

  case 28: /* color_enumeration: MAGENTA  */
#line 159 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2184 "src-generated/ugbc.tab.c"
    break;

  case 29: /* color_enumeration: PURPLE  */
#line 163 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2193 "src-generated/ugbc.tab.c"
    break;

  case 30: /* color_enumeration: LAVENDER  */
#line 167 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2202 "src-generated/ugbc.tab.c"
    break;

  case 31: /* color_enumeration: GOLD  */
#line 171 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2211 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: TURQUOISE  */
#line 175 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2220 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: TAN  */
#line 179 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2229 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: YELLOW GREEN  */
#line 183 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2238 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: OLIVE GREEN  */
#line 187 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2247 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: PINK  */
#line 191 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2256 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: PEACH  */
#line 195 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2265 "src-generated/ugbc.tab.c"
    break;

  case 38: /* expression: Identifier  */
#line 201 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2273 "src-generated/ugbc.tab.c"
    break;

  case 39: /* expression: Integer  */
#line 204 "src/ugbc.y"
              { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2282 "src-generated/ugbc.tab.c"
    break;

  case 40: /* expression: OP BYTE CP Integer  */
#line 208 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2291 "src-generated/ugbc.tab.c"
    break;

  case 41: /* expression: OP WORD CP Integer  */
#line 212 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2300 "src-generated/ugbc.tab.c"
    break;

  case 42: /* expression: OP DWORD CP Integer  */
#line 216 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2309 "src-generated/ugbc.tab.c"
    break;

  case 43: /* expression: OP POSITION CP Integer  */
#line 220 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2318 "src-generated/ugbc.tab.c"
    break;

  case 44: /* expression: OP COLOR CP Integer  */
#line 224 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2327 "src-generated/ugbc.tab.c"
    break;

  case 45: /* expression: color_enumeration  */
#line 228 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2335 "src-generated/ugbc.tab.c"
    break;

  case 46: /* expression: PEEK OP direct_integer CP  */
#line 231 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2343 "src-generated/ugbc.tab.c"
    break;

  case 47: /* expression: PEEK OP expressions CP  */
#line 234 "src/ugbc.y"
                             {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 2351 "src-generated/ugbc.tab.c"
    break;

  case 48: /* expression: XPEN  */
#line 237 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 2359 "src-generated/ugbc.tab.c"
    break;

  case 49: /* expression: YPEN  */
#line 240 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 2367 "src-generated/ugbc.tab.c"
    break;

  case 50: /* expression: COLLISION OP direct_integer CP  */
#line 243 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2375 "src-generated/ugbc.tab.c"
    break;

  case 51: /* expression: COLLISION OP expressions CP  */
#line 246 "src/ugbc.y"
                                  {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2383 "src-generated/ugbc.tab.c"
    break;

  case 52: /* expression: HIT OP direct_integer CP  */
#line 249 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2391 "src-generated/ugbc.tab.c"
    break;

  case 53: /* expression: HIT OP expressions CP  */
#line 252 "src/ugbc.y"
                            {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2399 "src-generated/ugbc.tab.c"
    break;

  case 54: /* expression: RANDOM random_definition  */
#line 255 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 2407 "src-generated/ugbc.tab.c"
    break;

  case 55: /* expression: OP expression CP  */
#line 258 "src/ugbc.y"
                       {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 2415 "src-generated/ugbc.tab.c"
    break;

  case 56: /* expressions_raw: expression  */
#line 264 "src/ugbc.y"
                 { (yyval.string) = (yyvsp[0].string); }
#line 2421 "src-generated/ugbc.tab.c"
    break;

  case 57: /* expressions_raw: expression PLUS expressions_raw  */
#line 265 "src/ugbc.y"
                                      {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2429 "src-generated/ugbc.tab.c"
    break;

  case 58: /* expressions_raw: expression MINUS expressions_raw  */
#line 268 "src/ugbc.y"
                                       {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2438 "src-generated/ugbc.tab.c"
    break;

  case 59: /* expressions_raw: expression EQUAL expressions_raw  */
#line 272 "src/ugbc.y"
                                       {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2446 "src-generated/ugbc.tab.c"
    break;

  case 60: /* expressions: expressions_raw  */
#line 278 "src/ugbc.y"
                    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2454 "src-generated/ugbc.tab.c"
    break;

  case 63: /* bank_definition_simple: Identifier AT direct_integer  */
#line 285 "src/ugbc.y"
                               {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2462 "src-generated/ugbc.tab.c"
    break;

  case 64: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 288 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2470 "src-generated/ugbc.tab.c"
    break;

  case 65: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 291 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2478 "src-generated/ugbc.tab.c"
    break;

  case 66: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 294 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2486 "src-generated/ugbc.tab.c"
    break;

  case 67: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 297 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2494 "src-generated/ugbc.tab.c"
    break;

  case 68: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 300 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2502 "src-generated/ugbc.tab.c"
    break;

  case 69: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 303 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 2510 "src-generated/ugbc.tab.c"
    break;

  case 70: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 306 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 2518 "src-generated/ugbc.tab.c"
    break;

  case 71: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 309 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 2526 "src-generated/ugbc.tab.c"
    break;

  case 72: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 314 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2534 "src-generated/ugbc.tab.c"
    break;

  case 73: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 317 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 2542 "src-generated/ugbc.tab.c"
    break;

  case 74: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 320 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2550 "src-generated/ugbc.tab.c"
    break;

  case 75: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 323 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 2558 "src-generated/ugbc.tab.c"
    break;

  case 76: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 326 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2566 "src-generated/ugbc.tab.c"
    break;

  case 79: /* raster_definition_simple: Identifier AT direct_integer  */
#line 335 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 2574 "src-generated/ugbc.tab.c"
    break;

  case 80: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 338 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 2582 "src-generated/ugbc.tab.c"
    break;

  case 81: /* raster_definition_expression: Identifier AT expressions  */
#line 343 "src/ugbc.y"
                              {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2590 "src-generated/ugbc.tab.c"
    break;

  case 82: /* raster_definition_expression: AT expressions WITH Identifier  */
#line 346 "src/ugbc.y"
                                   {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2598 "src-generated/ugbc.tab.c"
    break;

  case 85: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 355 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 2606 "src-generated/ugbc.tab.c"
    break;

  case 86: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 358 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 2614 "src-generated/ugbc.tab.c"
    break;

  case 87: /* next_raster_definition_expression: Identifier AT expressions  */
#line 363 "src/ugbc.y"
                              {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 2622 "src-generated/ugbc.tab.c"
    break;

  case 88: /* next_raster_definition_expression: AT expressions WITH Identifier  */
#line 366 "src/ugbc.y"
                                   {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2630 "src-generated/ugbc.tab.c"
    break;

  case 91: /* color_definition_simple: BORDER direct_integer  */
#line 375 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 2638 "src-generated/ugbc.tab.c"
    break;

  case 92: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 378 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 2646 "src-generated/ugbc.tab.c"
    break;

  case 93: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 381 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 2654 "src-generated/ugbc.tab.c"
    break;

  case 94: /* color_definition_expression: BORDER expressions  */
#line 386 "src/ugbc.y"
                       {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 2662 "src-generated/ugbc.tab.c"
    break;

  case 95: /* color_definition_expression: BACKGROUND expressions TO expressions  */
#line 389 "src/ugbc.y"
                                          {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 2670 "src-generated/ugbc.tab.c"
    break;

  case 96: /* color_definition_expression: SPRITE expressions TO expressions  */
#line 392 "src/ugbc.y"
                                      {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 2678 "src-generated/ugbc.tab.c"
    break;

  case 99: /* wait_definition_simple: direct_integer CYCLES  */
#line 401 "src/ugbc.y"
                          {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 2686 "src-generated/ugbc.tab.c"
    break;

  case 100: /* wait_definition_expression: expressions CYCLES  */
#line 406 "src/ugbc.y"
                       {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 2694 "src-generated/ugbc.tab.c"
    break;

  case 103: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 415 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 2702 "src-generated/ugbc.tab.c"
    break;

  case 104: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 418 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 2710 "src-generated/ugbc.tab.c"
    break;

  case 105: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 421 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 2718 "src-generated/ugbc.tab.c"
    break;

  case 106: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 424 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 2726 "src-generated/ugbc.tab.c"
    break;

  case 107: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 427 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 2734 "src-generated/ugbc.tab.c"
    break;

  case 108: /* sprite_definition_simple: direct_integer ENABLE  */
#line 430 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 2742 "src-generated/ugbc.tab.c"
    break;

  case 109: /* sprite_definition_simple: direct_integer DISABLE  */
#line 433 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 2750 "src-generated/ugbc.tab.c"
    break;

  case 110: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 436 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 2758 "src-generated/ugbc.tab.c"
    break;

  case 111: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 439 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 2766 "src-generated/ugbc.tab.c"
    break;

  case 112: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 442 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 2774 "src-generated/ugbc.tab.c"
    break;

  case 113: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 445 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 2782 "src-generated/ugbc.tab.c"
    break;

  case 114: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 448 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 2790 "src-generated/ugbc.tab.c"
    break;

  case 115: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 451 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 2798 "src-generated/ugbc.tab.c"
    break;

  case 116: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 454 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 2806 "src-generated/ugbc.tab.c"
    break;

  case 117: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 457 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 2814 "src-generated/ugbc.tab.c"
    break;

  case 118: /* sprite_definition_expression: expressions DATA FROM expressions  */
#line 462 "src/ugbc.y"
                                      {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 2822 "src-generated/ugbc.tab.c"
    break;

  case 119: /* sprite_definition_expression: expressions MULTICOLOR  */
#line 465 "src/ugbc.y"
                           {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 2830 "src-generated/ugbc.tab.c"
    break;

  case 120: /* sprite_definition_expression: expressions MONOCOLOR  */
#line 468 "src/ugbc.y"
                          {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 2838 "src-generated/ugbc.tab.c"
    break;

  case 121: /* sprite_definition_expression: expressions COLOR expressions  */
#line 471 "src/ugbc.y"
                                  {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 2846 "src-generated/ugbc.tab.c"
    break;

  case 122: /* sprite_definition_expression: expressions position OP expressions COMMA expressions CP  */
#line 474 "src/ugbc.y"
                                                             {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 2854 "src-generated/ugbc.tab.c"
    break;

  case 123: /* sprite_definition_expression: expressions ENABLE  */
#line 477 "src/ugbc.y"
                       {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 2862 "src-generated/ugbc.tab.c"
    break;

  case 124: /* sprite_definition_expression: expressions DISABLE  */
#line 480 "src/ugbc.y"
                        {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 2870 "src-generated/ugbc.tab.c"
    break;

  case 125: /* sprite_definition_expression: expressions EXPAND VERTICAL  */
#line 483 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 2878 "src-generated/ugbc.tab.c"
    break;

  case 126: /* sprite_definition_expression: expressions COMPRESS VERTICAL  */
#line 486 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 2886 "src-generated/ugbc.tab.c"
    break;

  case 127: /* sprite_definition_expression: expressions VERTICAL EXPAND  */
#line 489 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 2894 "src-generated/ugbc.tab.c"
    break;

  case 128: /* sprite_definition_expression: expressions VERTICAL COMPRESS  */
#line 492 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 2902 "src-generated/ugbc.tab.c"
    break;

  case 129: /* sprite_definition_expression: expressions EXPAND HORIZONTAL  */
#line 495 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 2910 "src-generated/ugbc.tab.c"
    break;

  case 130: /* sprite_definition_expression: expressions COMPRESS HORIZONTAL  */
#line 498 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 2918 "src-generated/ugbc.tab.c"
    break;

  case 131: /* sprite_definition_expression: expressions HORIZONTAL EXPAND  */
#line 501 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 2926 "src-generated/ugbc.tab.c"
    break;

  case 132: /* sprite_definition_expression: expressions HORIZONTAL COMPRESS  */
#line 504 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 2934 "src-generated/ugbc.tab.c"
    break;

  case 135: /* bitmap_definition_simple: AT direct_integer  */
#line 513 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 2942 "src-generated/ugbc.tab.c"
    break;

  case 136: /* bitmap_definition_simple: ENABLE  */
#line 516 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 2950 "src-generated/ugbc.tab.c"
    break;

  case 137: /* bitmap_definition_simple: DISABLE  */
#line 519 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 2958 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bitmap_definition_simple: CLEAR  */
#line 522 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 2966 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 525 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 2974 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bitmap_definition_expression: AT expressions  */
#line 531 "src/ugbc.y"
                   {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 2982 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bitmap_definition_expression: CLEAR WITH expressions  */
#line 534 "src/ugbc.y"
                           {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 2990 "src-generated/ugbc.tab.c"
    break;

  case 144: /* textmap_definition_simple: AT direct_integer  */
#line 544 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 2998 "src-generated/ugbc.tab.c"
    break;

  case 145: /* textmap_definition_expression: AT expressions  */
#line 549 "src/ugbc.y"
                   {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3006 "src-generated/ugbc.tab.c"
    break;

  case 148: /* text_definition_simple: ENABLE  */
#line 558 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3014 "src-generated/ugbc.tab.c"
    break;

  case 149: /* text_definition_simple: DISABLE  */
#line 561 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 3022 "src-generated/ugbc.tab.c"
    break;

  case 151: /* tiles_definition_simple: AT direct_integer  */
#line 569 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 3030 "src-generated/ugbc.tab.c"
    break;

  case 152: /* tiles_definition_expression: AT expressions  */
#line 574 "src/ugbc.y"
                   {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 3038 "src-generated/ugbc.tab.c"
    break;

  case 155: /* colormap_definition_simple: AT direct_integer  */
#line 583 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 3046 "src-generated/ugbc.tab.c"
    break;

  case 156: /* colormap_definition_simple: CLEAR  */
#line 586 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 3054 "src-generated/ugbc.tab.c"
    break;

  case 157: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 589 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3062 "src-generated/ugbc.tab.c"
    break;

  case 158: /* colormap_definition_expression: AT expressions  */
#line 594 "src/ugbc.y"
                   {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3070 "src-generated/ugbc.tab.c"
    break;

  case 159: /* colormap_definition_expression: CLEAR WITH expressions ON expressions  */
#line 597 "src/ugbc.y"
                                          {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3078 "src-generated/ugbc.tab.c"
    break;

  case 162: /* screen_definition_simple: ON  */
#line 607 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 3086 "src-generated/ugbc.tab.c"
    break;

  case 163: /* screen_definition_simple: OFF  */
#line 610 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 3094 "src-generated/ugbc.tab.c"
    break;

  case 164: /* screen_definition_simple: ROWS direct_integer  */
#line 613 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 3102 "src-generated/ugbc.tab.c"
    break;

  case 165: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 616 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3110 "src-generated/ugbc.tab.c"
    break;

  case 166: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 619 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3118 "src-generated/ugbc.tab.c"
    break;

  case 167: /* screen_definition_expression: ROWS expressions  */
#line 624 "src/ugbc.y"
                     {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 3126 "src-generated/ugbc.tab.c"
    break;

  case 168: /* screen_definition_expression: VERTICAL SCROLL expressions  */
#line 627 "src/ugbc.y"
                                {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3134 "src-generated/ugbc.tab.c"
    break;

  case 169: /* screen_definition_expression: HORIZONTAL SCROLL expressions  */
#line 630 "src/ugbc.y"
                                  {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3142 "src-generated/ugbc.tab.c"
    break;

  case 173: /* var_definition_simple: Identifier ON Identifier  */
#line 639 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 3150 "src-generated/ugbc.tab.c"
    break;

  case 174: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 642 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, 0 );
  }
#line 3158 "src-generated/ugbc.tab.c"
    break;

  case 176: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 650 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 3166 "src-generated/ugbc.tab.c"
    break;

  case 177: /* point_definition_expression: AT OP expressions COMMA expressions CP  */
#line 656 "src/ugbc.y"
                                             {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 3174 "src-generated/ugbc.tab.c"
    break;

  case 194: /* statement: RANDOMIZE  */
#line 679 "src/ugbc.y"
              {
      randomize( _environment );
  }
#line 3182 "src-generated/ugbc.tab.c"
    break;

  case 195: /* $@1: %empty  */
#line 682 "src/ugbc.y"
                   {
      if_then( _environment, (yyvsp[0].string) );  
  }
#line 3190 "src-generated/ugbc.tab.c"
    break;

  case 196: /* $@2: %empty  */
#line 684 "src/ugbc.y"
                                   {
      end_if_then( _environment );
  }
#line 3198 "src-generated/ugbc.tab.c"
    break;

  case 198: /* statement: BEG GAMELOOP  */
#line 687 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 3206 "src-generated/ugbc.tab.c"
    break;

  case 199: /* statement: END GAMELOOP  */
#line 690 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 3214 "src-generated/ugbc.tab.c"
    break;

  case 200: /* statement: GRAPHIC  */
#line 693 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 3222 "src-generated/ugbc.tab.c"
    break;

  case 201: /* statement: HALT  */
#line 696 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 3230 "src-generated/ugbc.tab.c"
    break;

  case 202: /* statement: GOTO Identifier  */
#line 699 "src/ugbc.y"
                    {
      goto_label( _environment, (yyvsp[0].string) );      
  }
#line 3238 "src-generated/ugbc.tab.c"
    break;

  case 203: /* statement: DONE  */
#line 702 "src/ugbc.y"
          {
      return 0;
  }
#line 3246 "src-generated/ugbc.tab.c"
    break;

  case 204: /* statement: Identifier COLON  */
#line 705 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 3254 "src-generated/ugbc.tab.c"
    break;

  case 205: /* statement: Identifier ASSIGN expressions  */
#line 708 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expressions = variable_retrieve( _environment, (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expressions->type, 0 )->name;
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 3265 "src-generated/ugbc.tab.c"
    break;

  case 206: /* statement: DEBUG expressions  */
#line 714 "src/ugbc.y"
                      {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 3273 "src-generated/ugbc.tab.c"
    break;

  case 209: /* statements_no_linenumbers: statement  */
#line 722 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 3279 "src-generated/ugbc.tab.c"
    break;

  case 210: /* $@3: %empty  */
#line 723 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 3285 "src-generated/ugbc.tab.c"
    break;

  case 212: /* $@4: %empty  */
#line 727 "src/ugbc.y"
              {
        outhead1("_line%d:", (yyvsp[0].integer));
    }
#line 3293 "src-generated/ugbc.tab.c"
    break;

  case 213: /* statements_with_linenumbers: Integer $@4 statements_no_linenumbers  */
#line 729 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 3301 "src-generated/ugbc.tab.c"
    break;


#line 3305 "src-generated/ugbc.tab.c"

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

#line 743 "src/ugbc.y"


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

