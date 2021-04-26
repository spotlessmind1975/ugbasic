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
  YYSYMBOL_MILLISECOND = 97,               /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 98,              /* MILLISECONDS  */
  YYSYMBOL_TICKS = 99,                     /* TICKS  */
  YYSYMBOL_BLACK = 100,                    /* BLACK  */
  YYSYMBOL_WHITE = 101,                    /* WHITE  */
  YYSYMBOL_RED = 102,                      /* RED  */
  YYSYMBOL_CYAN = 103,                     /* CYAN  */
  YYSYMBOL_VIOLET = 104,                   /* VIOLET  */
  YYSYMBOL_GREEN = 105,                    /* GREEN  */
  YYSYMBOL_BLUE = 106,                     /* BLUE  */
  YYSYMBOL_YELLOW = 107,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 108,                   /* ORANGE  */
  YYSYMBOL_BROWN = 109,                    /* BROWN  */
  YYSYMBOL_LIGHT = 110,                    /* LIGHT  */
  YYSYMBOL_DARK = 111,                     /* DARK  */
  YYSYMBOL_GREY = 112,                     /* GREY  */
  YYSYMBOL_GRAY = 113,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 114,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 115,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 116,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 117,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 118,                /* TURQUOISE  */
  YYSYMBOL_TAN = 119,                      /* TAN  */
  YYSYMBOL_PINK = 120,                     /* PINK  */
  YYSYMBOL_PEACH = 121,                    /* PEACH  */
  YYSYMBOL_OLIVE = 122,                    /* OLIVE  */
  YYSYMBOL_Identifier = 123,               /* Identifier  */
  YYSYMBOL_String = 124,                   /* String  */
  YYSYMBOL_Integer = 125,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 126,                 /* $accept  */
  YYSYMBOL_direct_integer = 127,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 128, /* random_definition_simple  */
  YYSYMBOL_random_definition = 129,        /* random_definition  */
  YYSYMBOL_color_enumeration = 130,        /* color_enumeration  */
  YYSYMBOL_expression = 131,               /* expression  */
  YYSYMBOL_expressions_raw = 132,          /* expressions_raw  */
  YYSYMBOL_expressions = 133,              /* expressions  */
  YYSYMBOL_position = 134,                 /* position  */
  YYSYMBOL_bank_definition_simple = 135,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 136, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 137,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 138, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 139, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 140,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 141, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 142, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 143,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 144,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 145, /* color_definition_expression  */
  YYSYMBOL_color_definition = 146,         /* color_definition  */
  YYSYMBOL_milliseconds = 147,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 148,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 149, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 150,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 151, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 152, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 153,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 154, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 155, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 156,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 157, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 158, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 159,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 160,   /* text_definition_simple  */
  YYSYMBOL_text_definition = 161,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 162,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 163, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 164,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 165, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 166, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 167,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 168, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 169, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 170,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 171,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 172,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 173,         /* gosub_definition  */
  YYSYMBOL_var_definition = 174,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 175,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 176, /* point_definition_expression  */
  YYSYMBOL_point_definition = 177,         /* point_definition  */
  YYSYMBOL_statement = 178,                /* statement  */
  YYSYMBOL_179_1 = 179,                    /* $@1  */
  YYSYMBOL_180_2 = 180,                    /* $@2  */
  YYSYMBOL_statements_no_linenumbers = 181, /* statements_no_linenumbers  */
  YYSYMBOL_182_3 = 182,                    /* $@3  */
  YYSYMBOL_statements_with_linenumbers = 183, /* statements_with_linenumbers  */
  YYSYMBOL_184_4 = 184,                    /* $@4  */
  YYSYMBOL_statements_complex = 185,       /* statements_complex  */
  YYSYMBOL_program = 186                   /* program  */
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
#define YYLAST   649

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  126
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  242
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  409

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   380


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
     125
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    65,    68,    71,    74,    77,    80,    83,
      88,    93,    97,   101,   105,   109,   113,   117,   121,   125,
     129,   133,   137,   141,   145,   149,   153,   157,   161,   165,
     169,   173,   177,   181,   185,   189,   193,   197,   203,   206,
     210,   214,   218,   222,   226,   230,   233,   236,   239,   242,
     245,   248,   251,   254,   257,   260,   266,   267,   270,   274,
     280,   284,   284,   287,   290,   293,   296,   299,   302,   306,
     309,   312,   315,   319,   322,   325,   328,   332,   335,   338,
     341,   347,   350,   353,   356,   359,   364,   365,   368,   371,
     376,   379,   384,   385,   388,   391,   396,   399,   404,   405,
     408,   411,   414,   419,   422,   425,   430,   431,   434,   435,
     436,   439,   442,   445,   450,   453,   456,   462,   463,   466,
     469,   472,   475,   478,   481,   484,   487,   490,   493,   496,
     499,   502,   505,   508,   513,   516,   519,   522,   525,   528,
     531,   534,   537,   540,   543,   546,   549,   552,   555,   560,
     561,   564,   567,   570,   573,   576,   582,   585,   591,   592,
     595,   600,   605,   606,   609,   612,   617,   620,   625,   630,
     631,   634,   637,   640,   645,   648,   654,   655,   658,   661,
     664,   667,   670,   675,   678,   681,   686,   687,   689,   690,
     693,   696,   706,   709,   715,   718,   724,   727,   733,   738,
     739,   742,   743,   744,   745,   746,   747,   748,   749,   750,
     751,   752,   753,   754,   755,   756,   759,   761,   759,   764,
     767,   770,   773,   776,   777,   778,   781,   784,   787,   790,
     796,   799,   800,   804,   805,   805,   809,   809,   816,   817,
     818,   819,   823
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
  "POP", "MILLISECOND", "MILLISECONDS", "TICKS", "BLACK", "WHITE", "RED",
  "CYAN", "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE", "BROWN", "LIGHT",
  "DARK", "GREY", "GRAY", "MAGENTA", "PURPLE", "LAVENDER", "GOLD",
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
     375,   376,   377,   378,   379,   380
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
     254,  -152,   -14,  -152,    29,   498,    15,   -10,   498,  -152,
     -13,    62,   -97,   -86,    60,    30,   -11,   524,    18,    43,
     524,  -152,  -152,    56,    67,    -4,  -152,  -152,     5,  -152,
      88,   125,   131,  -152,   142,   498,   128,  -152,  -152,  -152,
     498,   498,   498,  -152,  -152,  -152,   411,  -152,  -152,   120,
     123,   126,     3,    33,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,    50,  -152,  -152,    48,   -45,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,    58,  -152,  -152,   -49,  -152,
      16,  -152,    35,  -152,  -152,  -152,   -12,    96,    -9,    -6,
      -3,     1,   155,  -152,  -152,  -152,    27,    99,  -152,  -152,
    -152,   498,  -152,  -152,   154,  -152,  -152,  -152,  -152,  -152,
     498,   138,   139,  -152,  -152,  -152,   144,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,   498,  -152,  -152,  -152,
     498,   158,  -152,  -152,  -152,  -152,  -152,  -152,  -152,   498,
    -152,  -152,  -152,   157,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,   524,   371,  -152,   254,   254,  -152,   159,   160,   498,
    -152,  -152,   121,   122,   124,   127,   162,   163,   165,   166,
     167,   168,   498,   498,   498,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,   524,
     524,   524,  -152,  -152,  -152,   498,   171,  -152,  -152,  -152,
     156,    96,   182,    96,   183,    96,   184,    96,   185,    96,
    -152,    96,   177,  -152,  -152,     9,    89,   -16,    17,  -152,
    -152,  -152,   178,   524,   181,  -152,  -152,    92,   113,    28,
      40,  -152,  -152,   186,  -152,  -152,   498,  -152,  -152,   498,
     498,    61,  -152,  -152,  -152,  -152,   498,   146,  -152,  -152,
     498,  -152,  -152,   371,  -152,  -152,    80,    85,  -152,  -152,
      96,   524,    96,   524,    84,    91,    93,    95,    97,  -152,
     187,   196,   197,   199,   200,   201,  -152,  -152,  -152,   189,
     208,   498,    12,  -152,    96,  -152,    96,  -152,    96,  -152,
      96,    -2,  -152,    96,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,    96,  -152,   524,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,   524,  -152,  -152,  -152,  -152,  -152,  -152,
     217,   198,   202,   371,   224,   226,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,   111,   112,  -152,  -152,  -152,  -152,
    -152,  -152,   216,  -152,   218,  -152,   116,    21,  -152,   236,
    -152,   237,   498,    96,   524,  -152,    96,   524,  -152,  -152,
     129,   130,  -152,   230,  -152,   234,  -152,    96,   524,  -152,
    -152,  -152,  -152,   164,   231,   232,  -152,  -152,   137,   140,
     235,   239,  -152,  -152,  -152,  -152,  -152,  -152,  -152
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     232,   231,     0,   227,     0,     0,     0,     0,     0,   222,
       0,     0,   188,     0,     0,     0,     0,     0,     0,     0,
       0,   215,   221,     0,     0,     0,   225,   226,     0,   236,
     233,   238,   240,   242,     0,     0,     0,    92,    93,   202,
       0,     0,     0,   106,   107,   204,     0,    48,    49,     0,
       0,     0,     0,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,    23,    28,    29,    30,
      31,    32,    33,    36,    37,     0,    38,    39,     0,    45,
      56,    60,     0,   117,   118,   205,     0,     0,     0,     0,
       0,     0,     0,    86,    87,   201,     0,     0,   149,   150,
     206,     0,   152,   153,   154,   158,   159,   207,   178,   179,
       0,     0,     0,   186,   187,   212,     0,   196,   214,   192,
     193,   223,   164,   165,   166,   209,     0,   169,   170,   210,
       0,   172,   176,   177,   211,   216,   219,   220,   230,     0,
     162,   163,   208,     0,   199,   200,   213,   194,   195,   224,
     228,     0,   232,   234,   232,   232,     1,     0,     0,     0,
     100,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     3,     4,     6,     8,
       9,     5,    10,    54,     2,    34,    21,    24,    25,    26,
      27,    22,    35,   108,   111,   109,   110,   112,   113,     0,
       0,     0,   114,   115,   116,     0,     0,    98,    99,   203,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,     0,     0,   124,   125,     0,     0,     0,     0,   121,
     120,    61,     0,     0,     0,   139,   140,     0,     0,     0,
       0,   136,   135,     0,   151,   156,     0,   180,   183,     0,
       0,     0,   167,   168,   171,   174,     0,     0,   160,   161,
       0,   229,   237,   232,   239,   241,     0,     0,    88,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     0,    57,    58,    59,     0,
       0,     0,     0,    68,     0,    80,     0,    72,     0,    76,
       0,    64,   122,     0,   129,   128,   133,   132,   127,   131,
     126,   130,     0,   137,     0,   144,   143,   148,   147,   142,
     146,   141,   145,     0,   155,   157,   181,   184,   182,   185,
     189,     0,     0,   232,     0,     0,   235,    89,    91,   102,
     105,   101,   104,    44,    40,    41,    43,    42,    46,    47,
      50,    51,    52,    53,     0,     0,    94,    96,    65,    78,
      70,    73,    67,    79,    71,    75,     0,     0,   119,     0,
     134,     0,     0,     0,     0,   217,     0,     0,    95,    97,
       0,     0,    81,    66,    77,    69,    74,     0,     0,   190,
     191,   173,   175,     0,     0,     0,    83,    85,     0,     0,
       0,     0,   218,   197,   198,    82,    84,   123,   138
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,     0,  -152,  -152,  -152,   221,   -96,    -8,   148,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,   193,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -151,  -152,  -152,  -152,    14,
    -152
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    78,   182,   183,    79,    80,    81,    82,   232,    93,
      94,    95,    37,    38,    39,   207,   208,   209,    43,    44,
      45,   198,    83,    84,    85,    98,    99,   100,   105,   106,
     107,   140,   141,   142,   124,   125,   127,   128,   129,   132,
     133,   134,   113,   114,   115,   117,   121,   149,   118,   144,
     145,   146,    30,   257,   393,    31,   263,    32,   152,    33,
      34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      97,   262,    35,   101,   205,   130,    87,   211,    96,   135,
     213,   150,   138,   215,    88,   102,   103,   217,   151,   366,
     175,   308,   193,   194,   199,   200,   116,   158,   201,    86,
     309,    89,   161,   163,   165,   157,   358,   119,   367,   120,
     160,   162,   164,   220,   221,   383,   126,    40,   195,   196,
     197,   222,    41,   359,   310,   223,   224,   304,   305,    90,
      91,   190,   384,   311,   225,   319,   104,   191,   131,   176,
     177,   178,   139,   226,   320,   227,   228,   321,   179,   180,
     181,   360,   361,   143,   229,   230,   322,   210,   122,   123,
     385,   386,    42,   245,   153,   231,   108,   109,   110,   111,
     136,   244,   248,   286,   287,   288,   193,   202,   112,    36,
     247,   206,   336,    92,   212,   220,   233,   214,   253,   147,
     216,   148,   255,   234,   218,   137,   252,   235,   236,   154,
     254,   259,   195,   196,   203,   155,   237,   306,   307,   258,
     315,   316,   156,   261,   159,   238,   172,   239,   240,   173,
     186,   269,   174,   187,   188,   185,   241,   242,   184,   268,
     189,   317,   318,   192,   281,   283,   285,   231,   264,   265,
      53,   219,   280,   282,   284,   246,   249,   250,   251,   256,
     266,   267,   375,   260,   330,   270,   271,   291,   272,   274,
     275,   273,   276,   277,   278,   279,   292,   290,   294,   296,
     298,   300,   303,   337,   312,   289,   314,   333,   338,   343,
     354,   293,   323,   295,   348,   297,   344,   299,   345,   301,
     346,   302,   347,   349,   350,   313,   351,   352,   353,   355,
     372,   376,   373,   377,   378,   379,   374,   380,   325,   381,
     382,   327,   329,   387,   388,   243,   324,   402,   332,   326,
     328,   398,   335,   396,   397,   399,   331,     1,   403,   404,
     334,   405,   407,   340,   406,   342,   408,   171,     2,     3,
     339,     4,   341,     5,     6,   204,     7,     8,     0,     0,
       0,     0,     0,   357,     9,     0,    10,    11,     0,     0,
       0,   356,     0,    12,   362,     0,   363,     0,   364,    13,
     365,     0,     0,   368,     0,     0,   370,    14,    15,    16,
       0,     0,   369,     0,    17,   371,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    19,     0,     0,     0,     0,
       0,     0,    20,     0,    21,    22,    23,    24,    25,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   390,     0,   392,     0,     0,   395,
       0,     0,   389,   391,     1,     0,   394,    28,     0,    29,
     401,     0,     0,     0,     0,     2,     3,   400,     4,     0,
       5,     6,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     9,     0,    10,    11,     0,     0,     0,     0,     0,
      12,     0,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,     0,     0,    14,    15,    16,     0,   166,     0,
       0,    17,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    19,    47,    48,    49,     0,     0,     0,    20,
       0,    21,    22,    23,    24,    25,    26,    27,     0,     0,
      50,     0,     0,    51,     0,     0,    52,   167,   168,   169,
       0,     0,     0,     0,     0,     0,     0,     0,   170,     0,
       0,     0,     0,     0,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    46,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,     0,    77,     0,     0,     0,
      47,    48,    49,     0,     0,     0,     0,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,    50,     0,     0,
      51,     0,     0,    52,     0,     0,    47,    48,    49,     0,
       0,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,    51,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,     0,    77,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,     0,    77
};

static const yytype_int16 yycheck[] =
{
       8,   152,    16,    16,    16,    16,    16,    16,     8,    17,
      16,     6,    20,    16,    24,    28,    29,    16,    13,    21,
      17,    37,    71,    72,     8,     9,   123,    35,    12,    14,
      46,    41,    40,    41,    42,    35,    24,   123,    40,   125,
      40,    41,    42,    16,    17,    24,    16,    18,    97,    98,
      99,    24,    23,    41,    37,    28,    29,    48,    49,    69,
      70,   106,    41,    46,    37,    37,    79,   112,    79,    66,
      67,    68,    16,    46,    46,    48,    49,    37,    75,    76,
      77,    69,    70,    16,    57,    58,    46,    87,    28,    29,
      69,    70,    63,   101,     6,    68,    34,    35,    36,    37,
      82,   101,   110,   199,   200,   201,    71,    72,    46,   123,
     110,   123,   263,   123,   123,    16,    17,   123,   126,   123,
     123,   125,   130,    24,   123,    82,   126,    28,    29,     4,
     130,   139,    97,    98,    99,     4,    37,    48,    49,   139,
      48,    49,     0,   151,    16,    46,    26,    48,    49,    26,
     102,   159,    26,   105,   106,   105,    57,    58,   125,   159,
     112,    48,    49,   105,   172,   173,   174,    68,   154,   155,
      74,    16,   172,   173,   174,    21,    38,    38,    34,    21,
      21,    21,   333,    26,   123,    64,    64,    16,    64,    27,
      27,    64,    27,    27,    27,    27,    40,   205,    16,    16,
      16,    16,    25,   123,    26,   205,    25,    61,   123,   125,
      21,   211,    26,   213,    27,   215,   125,   217,   125,   219,
     125,   221,   125,    27,    27,   233,    27,    27,    27,    21,
      13,     7,    34,     7,   123,   123,    34,    21,   246,    21,
     124,   249,   250,     7,     7,    97,   246,    83,   256,   249,
     250,    21,   260,   124,   124,    21,   256,     3,    27,    27,
     260,   124,    27,   271,   124,   273,    27,    46,    14,    15,
     270,    17,   272,    19,    20,    82,    22,    23,    -1,    -1,
      -1,    -1,    -1,   291,    30,    -1,    32,    33,    -1,    -1,
      -1,   291,    -1,    39,   294,    -1,   296,    -1,   298,    45,
     300,    -1,    -1,   303,    -1,    -1,   314,    53,    54,    55,
      -1,    -1,   312,    -1,    60,   323,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    -1,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   372,    -1,   374,    -1,    -1,   377,
      -1,    -1,   372,   373,     3,    -1,   376,   123,    -1,   125,
     388,    -1,    -1,    -1,    -1,    14,    15,   387,    17,    -1,
      19,    20,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    -1,    17,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    42,    43,    44,    -1,    -1,    -1,    88,
      -1,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      59,    -1,    -1,    62,    -1,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    26,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    -1,   125,    -1,    -1,    -1,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      62,    -1,    -1,    65,    -1,    -1,    42,    43,    44,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    62,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    -1,   125,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    -1,   125
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    14,    15,    17,    19,    20,    22,    23,    30,
      32,    33,    39,    45,    53,    54,    55,    60,    80,    81,
      88,    90,    91,    92,    93,    94,    95,    96,   123,   125,
     178,   181,   183,   185,   186,    16,   123,   138,   139,   140,
      18,    23,    63,   144,   145,   146,    26,    42,    43,    44,
      59,    62,    65,    74,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   125,   127,   130,
     131,   132,   133,   148,   149,   150,    14,    16,    24,    41,
      69,    70,   123,   135,   136,   137,   127,   133,   151,   152,
     153,    16,    28,    29,    79,   154,   155,   156,    34,    35,
      36,    37,    46,   168,   169,   170,   123,   171,   174,   123,
     125,   172,    28,    29,   160,   161,    16,   162,   163,   164,
      16,    79,   165,   166,   167,   133,    82,    82,   133,    16,
     157,   158,   159,    16,   175,   176,   177,   123,   125,   173,
       6,    13,   184,     6,     4,     4,     0,   127,   133,    16,
     127,   133,   127,   133,   127,   133,    17,    66,    67,    68,
      77,   131,    26,    26,    26,    17,    66,    67,    68,    75,
      76,    77,   128,   129,   125,   105,   102,   105,   106,   112,
     106,   112,   105,    71,    72,    97,    98,    99,   147,     8,
       9,    12,    72,    99,   147,    16,   123,   141,   142,   143,
     127,    16,   123,    16,   123,    16,   123,    16,   123,    16,
      16,    17,    24,    28,    29,    37,    46,    48,    49,    57,
      58,    68,   134,    17,    24,    28,    29,    37,    46,    48,
      49,    57,    58,   134,   127,   133,    21,   127,   133,    38,
      38,    34,   127,   133,   127,   133,    21,   179,   127,   133,
      26,   133,   181,   182,   185,   185,    21,    21,   127,   133,
      64,    64,    64,    64,    27,    27,    27,    27,    27,    27,
     127,   133,   127,   133,   127,   133,   132,   132,   132,   127,
     133,    16,    40,   127,    16,   127,    16,   127,    16,   127,
      16,   127,   127,    25,    48,    49,    48,    49,    37,    46,
      37,    46,    26,   133,    25,    48,    49,    48,    49,    37,
      46,    37,    46,    26,   127,   133,   127,   133,   127,   133,
     123,   127,   133,    61,   127,   133,   181,   123,   123,   127,
     133,   127,   133,   125,   125,   125,   125,   125,    27,    27,
      27,    27,    27,    27,    21,    21,   127,   133,    24,    41,
      69,    70,   127,   127,   127,   127,    21,    40,   127,   127,
     133,   133,    13,    34,    34,   181,     7,     7,   123,   123,
      21,    21,   124,    24,    41,    69,    70,     7,     7,   127,
     133,   127,   133,   180,   127,   133,   124,   124,    21,    21,
     127,   133,    83,    27,    27,   124,   124,    27,    27
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   126,   127,   128,   128,   128,   128,   128,   128,   128,
     129,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   132,   132,   132,   132,
     133,   134,   134,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   136,   136,   136,   136,   136,   137,   137,   138,   138,
     139,   139,   140,   140,   141,   141,   142,   142,   143,   143,
     144,   144,   144,   145,   145,   145,   146,   146,   147,   147,
     147,   148,   148,   148,   149,   149,   149,   150,   150,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   153,
     153,   154,   154,   154,   154,   154,   155,   155,   156,   156,
     157,   158,   159,   159,   160,   160,   161,   162,   163,   164,
     164,   165,   165,   165,   166,   166,   167,   167,   168,   168,
     168,   168,   168,   169,   169,   169,   170,   170,   171,   171,
     171,   171,   172,   172,   173,   173,   174,   175,   176,   177,
     177,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   179,   180,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   181,   182,   181,   184,   183,   185,   185,
     185,   185,   186
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
       1,     2,     2,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     0,     0,     7,     2,
       2,     1,     1,     2,     2,     1,     1,     1,     2,     3,
       2,     1,     0,     1,     0,     4,     0,     3,     1,     3,
       1,     3,     1
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
#line 60 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 2008 "src-generated/ugbc.tab.c"
    break;

  case 3: /* random_definition_simple: BYTE  */
#line 65 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2016 "src-generated/ugbc.tab.c"
    break;

  case 4: /* random_definition_simple: WORD  */
#line 68 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2024 "src-generated/ugbc.tab.c"
    break;

  case 5: /* random_definition_simple: DWORD  */
#line 71 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2032 "src-generated/ugbc.tab.c"
    break;

  case 6: /* random_definition_simple: POSITION  */
#line 74 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2040 "src-generated/ugbc.tab.c"
    break;

  case 7: /* random_definition_simple: COLOR  */
#line 77 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2048 "src-generated/ugbc.tab.c"
    break;

  case 8: /* random_definition_simple: WIDTH  */
#line 80 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2056 "src-generated/ugbc.tab.c"
    break;

  case 9: /* random_definition_simple: HEIGHT  */
#line 83 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2064 "src-generated/ugbc.tab.c"
    break;

  case 10: /* random_definition: random_definition_simple  */
#line 88 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2072 "src-generated/ugbc.tab.c"
    break;

  case 11: /* color_enumeration: BLACK  */
#line 93 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2081 "src-generated/ugbc.tab.c"
    break;

  case 12: /* color_enumeration: WHITE  */
#line 97 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2090 "src-generated/ugbc.tab.c"
    break;

  case 13: /* color_enumeration: RED  */
#line 101 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2099 "src-generated/ugbc.tab.c"
    break;

  case 14: /* color_enumeration: CYAN  */
#line 105 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2108 "src-generated/ugbc.tab.c"
    break;

  case 15: /* color_enumeration: VIOLET  */
#line 109 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2117 "src-generated/ugbc.tab.c"
    break;

  case 16: /* color_enumeration: GREEN  */
#line 113 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2126 "src-generated/ugbc.tab.c"
    break;

  case 17: /* color_enumeration: BLUE  */
#line 117 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2135 "src-generated/ugbc.tab.c"
    break;

  case 18: /* color_enumeration: YELLOW  */
#line 121 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2144 "src-generated/ugbc.tab.c"
    break;

  case 19: /* color_enumeration: ORANGE  */
#line 125 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2153 "src-generated/ugbc.tab.c"
    break;

  case 20: /* color_enumeration: BROWN  */
#line 129 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2162 "src-generated/ugbc.tab.c"
    break;

  case 21: /* color_enumeration: LIGHT RED  */
#line 133 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2171 "src-generated/ugbc.tab.c"
    break;

  case 22: /* color_enumeration: DARK GREY  */
#line 137 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2180 "src-generated/ugbc.tab.c"
    break;

  case 23: /* color_enumeration: GREY  */
#line 141 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2189 "src-generated/ugbc.tab.c"
    break;

  case 24: /* color_enumeration: LIGHT GREEN  */
#line 145 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2198 "src-generated/ugbc.tab.c"
    break;

  case 25: /* color_enumeration: LIGHT BLUE  */
#line 149 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2207 "src-generated/ugbc.tab.c"
    break;

  case 26: /* color_enumeration: LIGHT GREY  */
#line 153 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2216 "src-generated/ugbc.tab.c"
    break;

  case 27: /* color_enumeration: DARK BLUE  */
#line 157 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2225 "src-generated/ugbc.tab.c"
    break;

  case 28: /* color_enumeration: MAGENTA  */
#line 161 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2234 "src-generated/ugbc.tab.c"
    break;

  case 29: /* color_enumeration: PURPLE  */
#line 165 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2243 "src-generated/ugbc.tab.c"
    break;

  case 30: /* color_enumeration: LAVENDER  */
#line 169 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2252 "src-generated/ugbc.tab.c"
    break;

  case 31: /* color_enumeration: GOLD  */
#line 173 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2261 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: TURQUOISE  */
#line 177 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2270 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: TAN  */
#line 181 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2279 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: YELLOW GREEN  */
#line 185 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2288 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: OLIVE GREEN  */
#line 189 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2297 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: PINK  */
#line 193 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2306 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: PEACH  */
#line 197 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2315 "src-generated/ugbc.tab.c"
    break;

  case 38: /* expression: Identifier  */
#line 203 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2323 "src-generated/ugbc.tab.c"
    break;

  case 39: /* expression: Integer  */
#line 206 "src/ugbc.y"
              { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2332 "src-generated/ugbc.tab.c"
    break;

  case 40: /* expression: OP BYTE CP Integer  */
#line 210 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2341 "src-generated/ugbc.tab.c"
    break;

  case 41: /* expression: OP WORD CP Integer  */
#line 214 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2350 "src-generated/ugbc.tab.c"
    break;

  case 42: /* expression: OP DWORD CP Integer  */
#line 218 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2359 "src-generated/ugbc.tab.c"
    break;

  case 43: /* expression: OP POSITION CP Integer  */
#line 222 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2368 "src-generated/ugbc.tab.c"
    break;

  case 44: /* expression: OP COLOR CP Integer  */
#line 226 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2377 "src-generated/ugbc.tab.c"
    break;

  case 45: /* expression: color_enumeration  */
#line 230 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2385 "src-generated/ugbc.tab.c"
    break;

  case 46: /* expression: PEEK OP direct_integer CP  */
#line 233 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2393 "src-generated/ugbc.tab.c"
    break;

  case 47: /* expression: PEEK OP expressions CP  */
#line 236 "src/ugbc.y"
                             {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 2401 "src-generated/ugbc.tab.c"
    break;

  case 48: /* expression: XPEN  */
#line 239 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 2409 "src-generated/ugbc.tab.c"
    break;

  case 49: /* expression: YPEN  */
#line 242 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 2417 "src-generated/ugbc.tab.c"
    break;

  case 50: /* expression: COLLISION OP direct_integer CP  */
#line 245 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2425 "src-generated/ugbc.tab.c"
    break;

  case 51: /* expression: COLLISION OP expressions CP  */
#line 248 "src/ugbc.y"
                                  {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2433 "src-generated/ugbc.tab.c"
    break;

  case 52: /* expression: HIT OP direct_integer CP  */
#line 251 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2441 "src-generated/ugbc.tab.c"
    break;

  case 53: /* expression: HIT OP expressions CP  */
#line 254 "src/ugbc.y"
                            {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2449 "src-generated/ugbc.tab.c"
    break;

  case 54: /* expression: RANDOM random_definition  */
#line 257 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 2457 "src-generated/ugbc.tab.c"
    break;

  case 55: /* expression: OP expression CP  */
#line 260 "src/ugbc.y"
                       {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 2465 "src-generated/ugbc.tab.c"
    break;

  case 56: /* expressions_raw: expression  */
#line 266 "src/ugbc.y"
                 { (yyval.string) = (yyvsp[0].string); }
#line 2471 "src-generated/ugbc.tab.c"
    break;

  case 57: /* expressions_raw: expression PLUS expressions_raw  */
#line 267 "src/ugbc.y"
                                      {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2479 "src-generated/ugbc.tab.c"
    break;

  case 58: /* expressions_raw: expression MINUS expressions_raw  */
#line 270 "src/ugbc.y"
                                       {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2488 "src-generated/ugbc.tab.c"
    break;

  case 59: /* expressions_raw: expression EQUAL expressions_raw  */
#line 274 "src/ugbc.y"
                                       {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2496 "src-generated/ugbc.tab.c"
    break;

  case 60: /* expressions: expressions_raw  */
#line 280 "src/ugbc.y"
                    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2504 "src-generated/ugbc.tab.c"
    break;

  case 63: /* bank_definition_simple: AT direct_integer  */
#line 287 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2512 "src-generated/ugbc.tab.c"
    break;

  case 64: /* bank_definition_simple: Identifier AT direct_integer  */
#line 290 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2520 "src-generated/ugbc.tab.c"
    break;

  case 65: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 293 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2528 "src-generated/ugbc.tab.c"
    break;

  case 66: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 296 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2536 "src-generated/ugbc.tab.c"
    break;

  case 67: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 299 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2544 "src-generated/ugbc.tab.c"
    break;

  case 68: /* bank_definition_simple: DATA AT direct_integer  */
#line 302 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2552 "src-generated/ugbc.tab.c"
    break;

  case 69: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 306 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2560 "src-generated/ugbc.tab.c"
    break;

  case 70: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 309 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2568 "src-generated/ugbc.tab.c"
    break;

  case 71: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 312 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2576 "src-generated/ugbc.tab.c"
    break;

  case 72: /* bank_definition_simple: CODE AT direct_integer  */
#line 315 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2584 "src-generated/ugbc.tab.c"
    break;

  case 73: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 319 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2592 "src-generated/ugbc.tab.c"
    break;

  case 74: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 322 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2600 "src-generated/ugbc.tab.c"
    break;

  case 75: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 325 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 2608 "src-generated/ugbc.tab.c"
    break;

  case 76: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 328 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 2616 "src-generated/ugbc.tab.c"
    break;

  case 77: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 332 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 2624 "src-generated/ugbc.tab.c"
    break;

  case 78: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 335 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 2632 "src-generated/ugbc.tab.c"
    break;

  case 79: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 338 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 2640 "src-generated/ugbc.tab.c"
    break;

  case 80: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 341 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 2648 "src-generated/ugbc.tab.c"
    break;

  case 81: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 347 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2656 "src-generated/ugbc.tab.c"
    break;

  case 82: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 350 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 2664 "src-generated/ugbc.tab.c"
    break;

  case 83: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 353 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2672 "src-generated/ugbc.tab.c"
    break;

  case 84: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 356 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 2680 "src-generated/ugbc.tab.c"
    break;

  case 85: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 359 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2688 "src-generated/ugbc.tab.c"
    break;

  case 88: /* raster_definition_simple: Identifier AT direct_integer  */
#line 368 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 2696 "src-generated/ugbc.tab.c"
    break;

  case 89: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 371 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 2704 "src-generated/ugbc.tab.c"
    break;

  case 90: /* raster_definition_expression: Identifier AT expressions  */
#line 376 "src/ugbc.y"
                              {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2712 "src-generated/ugbc.tab.c"
    break;

  case 91: /* raster_definition_expression: AT expressions WITH Identifier  */
#line 379 "src/ugbc.y"
                                   {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2720 "src-generated/ugbc.tab.c"
    break;

  case 94: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 388 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 2728 "src-generated/ugbc.tab.c"
    break;

  case 95: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 391 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 2736 "src-generated/ugbc.tab.c"
    break;

  case 96: /* next_raster_definition_expression: Identifier AT expressions  */
#line 396 "src/ugbc.y"
                              {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 2744 "src-generated/ugbc.tab.c"
    break;

  case 97: /* next_raster_definition_expression: AT expressions WITH Identifier  */
#line 399 "src/ugbc.y"
                                   {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2752 "src-generated/ugbc.tab.c"
    break;

  case 100: /* color_definition_simple: BORDER direct_integer  */
#line 408 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 2760 "src-generated/ugbc.tab.c"
    break;

  case 101: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 411 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 2768 "src-generated/ugbc.tab.c"
    break;

  case 102: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 414 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 2776 "src-generated/ugbc.tab.c"
    break;

  case 103: /* color_definition_expression: BORDER expressions  */
#line 419 "src/ugbc.y"
                       {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 2784 "src-generated/ugbc.tab.c"
    break;

  case 104: /* color_definition_expression: BACKGROUND expressions TO expressions  */
#line 422 "src/ugbc.y"
                                          {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 2792 "src-generated/ugbc.tab.c"
    break;

  case 105: /* color_definition_expression: SPRITE expressions TO expressions  */
#line 425 "src/ugbc.y"
                                      {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 2800 "src-generated/ugbc.tab.c"
    break;

  case 111: /* wait_definition_simple: direct_integer CYCLES  */
#line 439 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 2808 "src-generated/ugbc.tab.c"
    break;

  case 112: /* wait_definition_simple: direct_integer TICKS  */
#line 442 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 2816 "src-generated/ugbc.tab.c"
    break;

  case 113: /* wait_definition_simple: direct_integer milliseconds  */
#line 445 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 2824 "src-generated/ugbc.tab.c"
    break;

  case 114: /* wait_definition_expression: expressions CYCLES  */
#line 450 "src/ugbc.y"
                         {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 2832 "src-generated/ugbc.tab.c"
    break;

  case 115: /* wait_definition_expression: expressions TICKS  */
#line 453 "src/ugbc.y"
                        {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 2840 "src-generated/ugbc.tab.c"
    break;

  case 116: /* wait_definition_expression: expressions milliseconds  */
#line 456 "src/ugbc.y"
                               {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 2848 "src-generated/ugbc.tab.c"
    break;

  case 119: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 466 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 2856 "src-generated/ugbc.tab.c"
    break;

  case 120: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 469 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 2864 "src-generated/ugbc.tab.c"
    break;

  case 121: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 472 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 2872 "src-generated/ugbc.tab.c"
    break;

  case 122: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 475 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 2880 "src-generated/ugbc.tab.c"
    break;

  case 123: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 478 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 2888 "src-generated/ugbc.tab.c"
    break;

  case 124: /* sprite_definition_simple: direct_integer ENABLE  */
#line 481 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 2896 "src-generated/ugbc.tab.c"
    break;

  case 125: /* sprite_definition_simple: direct_integer DISABLE  */
#line 484 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 2904 "src-generated/ugbc.tab.c"
    break;

  case 126: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 487 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 2912 "src-generated/ugbc.tab.c"
    break;

  case 127: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 490 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 2920 "src-generated/ugbc.tab.c"
    break;

  case 128: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 493 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 2928 "src-generated/ugbc.tab.c"
    break;

  case 129: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 496 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 2936 "src-generated/ugbc.tab.c"
    break;

  case 130: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 499 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 2944 "src-generated/ugbc.tab.c"
    break;

  case 131: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 502 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 2952 "src-generated/ugbc.tab.c"
    break;

  case 132: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 505 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 2960 "src-generated/ugbc.tab.c"
    break;

  case 133: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 508 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 2968 "src-generated/ugbc.tab.c"
    break;

  case 134: /* sprite_definition_expression: expressions DATA FROM expressions  */
#line 513 "src/ugbc.y"
                                      {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 2976 "src-generated/ugbc.tab.c"
    break;

  case 135: /* sprite_definition_expression: expressions MULTICOLOR  */
#line 516 "src/ugbc.y"
                           {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 2984 "src-generated/ugbc.tab.c"
    break;

  case 136: /* sprite_definition_expression: expressions MONOCOLOR  */
#line 519 "src/ugbc.y"
                          {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 2992 "src-generated/ugbc.tab.c"
    break;

  case 137: /* sprite_definition_expression: expressions COLOR expressions  */
#line 522 "src/ugbc.y"
                                  {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3000 "src-generated/ugbc.tab.c"
    break;

  case 138: /* sprite_definition_expression: expressions position OP expressions COMMA expressions CP  */
#line 525 "src/ugbc.y"
                                                             {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3008 "src-generated/ugbc.tab.c"
    break;

  case 139: /* sprite_definition_expression: expressions ENABLE  */
#line 528 "src/ugbc.y"
                       {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3016 "src-generated/ugbc.tab.c"
    break;

  case 140: /* sprite_definition_expression: expressions DISABLE  */
#line 531 "src/ugbc.y"
                        {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3024 "src-generated/ugbc.tab.c"
    break;

  case 141: /* sprite_definition_expression: expressions EXPAND VERTICAL  */
#line 534 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3032 "src-generated/ugbc.tab.c"
    break;

  case 142: /* sprite_definition_expression: expressions COMPRESS VERTICAL  */
#line 537 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3040 "src-generated/ugbc.tab.c"
    break;

  case 143: /* sprite_definition_expression: expressions VERTICAL EXPAND  */
#line 540 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3048 "src-generated/ugbc.tab.c"
    break;

  case 144: /* sprite_definition_expression: expressions VERTICAL COMPRESS  */
#line 543 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3056 "src-generated/ugbc.tab.c"
    break;

  case 145: /* sprite_definition_expression: expressions EXPAND HORIZONTAL  */
#line 546 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3064 "src-generated/ugbc.tab.c"
    break;

  case 146: /* sprite_definition_expression: expressions COMPRESS HORIZONTAL  */
#line 549 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3072 "src-generated/ugbc.tab.c"
    break;

  case 147: /* sprite_definition_expression: expressions HORIZONTAL EXPAND  */
#line 552 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3080 "src-generated/ugbc.tab.c"
    break;

  case 148: /* sprite_definition_expression: expressions HORIZONTAL COMPRESS  */
#line 555 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3088 "src-generated/ugbc.tab.c"
    break;

  case 151: /* bitmap_definition_simple: AT direct_integer  */
#line 564 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3096 "src-generated/ugbc.tab.c"
    break;

  case 152: /* bitmap_definition_simple: ENABLE  */
#line 567 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3104 "src-generated/ugbc.tab.c"
    break;

  case 153: /* bitmap_definition_simple: DISABLE  */
#line 570 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 3112 "src-generated/ugbc.tab.c"
    break;

  case 154: /* bitmap_definition_simple: CLEAR  */
#line 573 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 3120 "src-generated/ugbc.tab.c"
    break;

  case 155: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 576 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 3128 "src-generated/ugbc.tab.c"
    break;

  case 156: /* bitmap_definition_expression: AT expressions  */
#line 582 "src/ugbc.y"
                   {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3136 "src-generated/ugbc.tab.c"
    break;

  case 157: /* bitmap_definition_expression: CLEAR WITH expressions  */
#line 585 "src/ugbc.y"
                           {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 3144 "src-generated/ugbc.tab.c"
    break;

  case 160: /* textmap_definition_simple: AT direct_integer  */
#line 595 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3152 "src-generated/ugbc.tab.c"
    break;

  case 161: /* textmap_definition_expression: AT expressions  */
#line 600 "src/ugbc.y"
                   {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3160 "src-generated/ugbc.tab.c"
    break;

  case 164: /* text_definition_simple: ENABLE  */
#line 609 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3168 "src-generated/ugbc.tab.c"
    break;

  case 165: /* text_definition_simple: DISABLE  */
#line 612 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 3176 "src-generated/ugbc.tab.c"
    break;

  case 167: /* tiles_definition_simple: AT direct_integer  */
#line 620 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 3184 "src-generated/ugbc.tab.c"
    break;

  case 168: /* tiles_definition_expression: AT expressions  */
#line 625 "src/ugbc.y"
                   {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 3192 "src-generated/ugbc.tab.c"
    break;

  case 171: /* colormap_definition_simple: AT direct_integer  */
#line 634 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 3200 "src-generated/ugbc.tab.c"
    break;

  case 172: /* colormap_definition_simple: CLEAR  */
#line 637 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 3208 "src-generated/ugbc.tab.c"
    break;

  case 173: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 640 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3216 "src-generated/ugbc.tab.c"
    break;

  case 174: /* colormap_definition_expression: AT expressions  */
#line 645 "src/ugbc.y"
                   {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3224 "src-generated/ugbc.tab.c"
    break;

  case 175: /* colormap_definition_expression: CLEAR WITH expressions ON expressions  */
#line 648 "src/ugbc.y"
                                          {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3232 "src-generated/ugbc.tab.c"
    break;

  case 178: /* screen_definition_simple: ON  */
#line 658 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 3240 "src-generated/ugbc.tab.c"
    break;

  case 179: /* screen_definition_simple: OFF  */
#line 661 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 3248 "src-generated/ugbc.tab.c"
    break;

  case 180: /* screen_definition_simple: ROWS direct_integer  */
#line 664 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 3256 "src-generated/ugbc.tab.c"
    break;

  case 181: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 667 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3264 "src-generated/ugbc.tab.c"
    break;

  case 182: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 670 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3272 "src-generated/ugbc.tab.c"
    break;

  case 183: /* screen_definition_expression: ROWS expressions  */
#line 675 "src/ugbc.y"
                     {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 3280 "src-generated/ugbc.tab.c"
    break;

  case 184: /* screen_definition_expression: VERTICAL SCROLL expressions  */
#line 678 "src/ugbc.y"
                                {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3288 "src-generated/ugbc.tab.c"
    break;

  case 185: /* screen_definition_expression: HORIZONTAL SCROLL expressions  */
#line 681 "src/ugbc.y"
                                  {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3296 "src-generated/ugbc.tab.c"
    break;

  case 189: /* var_definition_simple: Identifier ON Identifier  */
#line 690 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 3304 "src-generated/ugbc.tab.c"
    break;

  case 190: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 693 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 3312 "src-generated/ugbc.tab.c"
    break;

  case 191: /* var_definition_simple: Identifier ON Identifier ASSIGN expressions  */
#line 696 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      if ( v == NULL ) {
          CRITICAL("Variable not found");
      }
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 3325 "src-generated/ugbc.tab.c"
    break;

  case 192: /* goto_definition: Identifier  */
#line 706 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 3333 "src-generated/ugbc.tab.c"
    break;

  case 193: /* goto_definition: Integer  */
#line 709 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 3341 "src-generated/ugbc.tab.c"
    break;

  case 194: /* gosub_definition: Identifier  */
#line 715 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 3349 "src-generated/ugbc.tab.c"
    break;

  case 195: /* gosub_definition: Integer  */
#line 718 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 3357 "src-generated/ugbc.tab.c"
    break;

  case 197: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 727 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 3365 "src-generated/ugbc.tab.c"
    break;

  case 198: /* point_definition_expression: AT OP expressions COMMA expressions CP  */
#line 733 "src/ugbc.y"
                                             {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 3373 "src-generated/ugbc.tab.c"
    break;

  case 215: /* statement: RANDOMIZE  */
#line 756 "src/ugbc.y"
              {
      randomize( _environment );
  }
#line 3381 "src-generated/ugbc.tab.c"
    break;

  case 216: /* $@1: %empty  */
#line 759 "src/ugbc.y"
                   {
      if_then( _environment, (yyvsp[0].string) );  
  }
#line 3389 "src-generated/ugbc.tab.c"
    break;

  case 217: /* $@2: %empty  */
#line 761 "src/ugbc.y"
                                   {
      end_if_then( _environment );
  }
#line 3397 "src-generated/ugbc.tab.c"
    break;

  case 219: /* statement: BEG GAMELOOP  */
#line 764 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 3405 "src-generated/ugbc.tab.c"
    break;

  case 220: /* statement: END GAMELOOP  */
#line 767 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 3413 "src-generated/ugbc.tab.c"
    break;

  case 221: /* statement: GRAPHIC  */
#line 770 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 3421 "src-generated/ugbc.tab.c"
    break;

  case 222: /* statement: HALT  */
#line 773 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 3429 "src-generated/ugbc.tab.c"
    break;

  case 225: /* statement: RETURN  */
#line 778 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 3437 "src-generated/ugbc.tab.c"
    break;

  case 226: /* statement: POP  */
#line 781 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 3445 "src-generated/ugbc.tab.c"
    break;

  case 227: /* statement: DONE  */
#line 784 "src/ugbc.y"
          {
      return 0;
  }
#line 3453 "src-generated/ugbc.tab.c"
    break;

  case 228: /* statement: Identifier COLON  */
#line 787 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 3461 "src-generated/ugbc.tab.c"
    break;

  case 229: /* statement: Identifier ASSIGN expressions  */
#line 790 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expressions = variable_retrieve( _environment, (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expressions->type, 0 )->name;
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 3472 "src-generated/ugbc.tab.c"
    break;

  case 230: /* statement: DEBUG expressions  */
#line 796 "src/ugbc.y"
                      {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 3480 "src-generated/ugbc.tab.c"
    break;

  case 233: /* statements_no_linenumbers: statement  */
#line 804 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 3486 "src-generated/ugbc.tab.c"
    break;

  case 234: /* $@3: %empty  */
#line 805 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 3492 "src-generated/ugbc.tab.c"
    break;

  case 236: /* $@4: %empty  */
#line 809 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 3500 "src-generated/ugbc.tab.c"
    break;

  case 237: /* statements_with_linenumbers: Integer $@4 statements_no_linenumbers  */
#line 811 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 3508 "src-generated/ugbc.tab.c"
    break;


#line 3512 "src-generated/ugbc.tab.c"

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

#line 825 "src/ugbc.y"


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

