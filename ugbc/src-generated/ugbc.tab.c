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
  YYSYMBOL_MILLISECOND = 104,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 105,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 106,                    /* TICKS  */
  YYSYMBOL_BLACK = 107,                    /* BLACK  */
  YYSYMBOL_WHITE = 108,                    /* WHITE  */
  YYSYMBOL_RED = 109,                      /* RED  */
  YYSYMBOL_CYAN = 110,                     /* CYAN  */
  YYSYMBOL_VIOLET = 111,                   /* VIOLET  */
  YYSYMBOL_GREEN = 112,                    /* GREEN  */
  YYSYMBOL_BLUE = 113,                     /* BLUE  */
  YYSYMBOL_YELLOW = 114,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 115,                   /* ORANGE  */
  YYSYMBOL_BROWN = 116,                    /* BROWN  */
  YYSYMBOL_LIGHT = 117,                    /* LIGHT  */
  YYSYMBOL_DARK = 118,                     /* DARK  */
  YYSYMBOL_GREY = 119,                     /* GREY  */
  YYSYMBOL_GRAY = 120,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 121,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 122,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 123,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 124,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 125,                /* TURQUOISE  */
  YYSYMBOL_TAN = 126,                      /* TAN  */
  YYSYMBOL_PINK = 127,                     /* PINK  */
  YYSYMBOL_PEACH = 128,                    /* PEACH  */
  YYSYMBOL_OLIVE = 129,                    /* OLIVE  */
  YYSYMBOL_Identifier = 130,               /* Identifier  */
  YYSYMBOL_String = 131,                   /* String  */
  YYSYMBOL_Integer = 132,                  /* Integer  */
  YYSYMBOL_YYACCEPT = 133,                 /* $accept  */
  YYSYMBOL_direct_integer = 134,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 135, /* random_definition_simple  */
  YYSYMBOL_random_definition = 136,        /* random_definition  */
  YYSYMBOL_color_enumeration = 137,        /* color_enumeration  */
  YYSYMBOL_expression = 138,               /* expression  */
  YYSYMBOL_expressions_raw = 139,          /* expressions_raw  */
  YYSYMBOL_expressions = 140,              /* expressions  */
  YYSYMBOL_position = 141,                 /* position  */
  YYSYMBOL_bank_definition_simple = 142,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 143, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 144,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 145, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 146, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 147,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 148, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 149, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 150,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 151,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 152, /* color_definition_expression  */
  YYSYMBOL_color_definition = 153,         /* color_definition  */
  YYSYMBOL_milliseconds = 154,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 155,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 156, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 157,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 158, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 159, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 160,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 161, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 162, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 163,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 164, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 165, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 166,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 167,   /* text_definition_simple  */
  YYSYMBOL_text_definition = 168,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 169,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 170, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 171,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 172, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 173, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 174,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 175, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 176, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 177,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 178,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 179,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 180,         /* gosub_definition  */
  YYSYMBOL_var_definition = 181,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 182,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 183, /* point_definition_expression  */
  YYSYMBOL_point_definition = 184,         /* point_definition  */
  YYSYMBOL_statement = 185,                /* statement  */
  YYSYMBOL_statements_no_linenumbers = 186, /* statements_no_linenumbers  */
  YYSYMBOL_187_1 = 187,                    /* $@1  */
  YYSYMBOL_statements_with_linenumbers = 188, /* statements_with_linenumbers  */
  YYSYMBOL_189_2 = 189,                    /* $@2  */
  YYSYMBOL_statements_complex = 190,       /* statements_complex  */
  YYSYMBOL_program = 191                   /* program  */
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
#define YYFINAL  159
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   630

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  133
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  250
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  422

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   387


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
     125,   126,   127,   128,   129,   130,   131,   132
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
     247,   250,   253,   256,   259,   262,   268,   269,   272,   276,
     280,   284,   287,   290,   293,   296,   299,   305,   309,   309,
     312,   315,   318,   321,   324,   327,   331,   334,   337,   340,
     344,   347,   350,   353,   357,   360,   363,   366,   372,   375,
     378,   381,   384,   389,   390,   393,   396,   401,   404,   409,
     410,   413,   416,   421,   424,   429,   430,   433,   436,   439,
     444,   447,   450,   455,   456,   459,   460,   461,   464,   467,
     470,   475,   478,   481,   487,   488,   491,   494,   497,   500,
     503,   506,   509,   512,   515,   518,   521,   524,   527,   530,
     533,   538,   541,   544,   547,   550,   553,   556,   559,   562,
     565,   568,   571,   574,   577,   580,   585,   586,   589,   592,
     595,   598,   601,   607,   610,   616,   617,   620,   625,   630,
     631,   634,   637,   642,   645,   650,   655,   656,   659,   662,
     665,   670,   673,   679,   680,   683,   686,   689,   692,   695,
     700,   703,   706,   711,   712,   714,   715,   718,   721,   731,
     734,   740,   743,   749,   752,   758,   763,   764,   767,   768,
     769,   770,   771,   772,   773,   774,   775,   776,   777,   778,
     779,   780,   781,   784,   787,   790,   793,   796,   799,   802,
     805,   808,   809,   810,   813,   816,   819,   822,   828,   831,
     832,   836,   837,   837,   841,   841,   848,   849,   850,   851,
     855
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
  "POINT", "GOSUB", "RETURN", "POP", "OR", "ELSE", "MILLISECOND",
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
  "point_definition_expression", "point_definition", "statement",
  "statements_no_linenumbers", "$@1", "statements_with_linenumbers", "$@2",
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
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387
};
#endif

#define YYPACT_NINF (-155)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     268,  -155,   -17,  -155,     5,   472,    22,   -19,   472,  -155,
      -3,    96,   -84,   -42,    84,    40,   -10,   498,   -23,     9,
    -155,   498,  -155,  -155,    51,    57,   -22,  -155,  -155,    35,
      93,  -155,    78,    83,   101,  -155,   122,   472,   110,  -155,
    -155,  -155,   472,   472,   472,  -155,  -155,  -155,   383,  -155,
    -155,   103,   117,   118,    -5,    33,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,    38,  -155,  -155,   -60,   -87,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,    41,  -155,  -155,
      21,  -155,     7,  -155,    81,  -155,  -155,  -155,   -16,    82,
     -15,   -14,    -9,    -7,   139,  -155,  -155,  -155,    29,   130,
    -155,  -155,  -155,   472,  -155,  -155,   140,  -155,  -155,  -155,
    -155,  -155,   472,   127,   128,  -155,  -155,  -155,   134,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,   472,  -155,
    -155,  -155,   472,   148,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,   472,  -155,  -155,  -155,   147,  -155,  -155,  -155,  -155,
    -155,  -155,   498,  -155,   498,   384,  -155,   268,   268,  -155,
     153,   154,   472,  -155,  -155,   113,   119,   120,   121,   159,
     162,   163,   164,   165,   166,   472,   472,   472,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,  -155,  -155,  -155,   472,   178,  -155,  -155,  -155,
     155,    82,   180,    82,   181,    82,   183,    82,   184,    82,
    -155,    82,   176,  -155,  -155,    76,    86,    -4,     3,  -155,
    -155,  -155,   177,   498,   179,  -155,  -155,    89,    91,    18,
      28,  -155,  -155,   182,  -155,  -155,   472,  -155,  -155,   472,
     472,    80,  -155,  -155,  -155,  -155,   472,  -155,  -155,   472,
    -155,  -155,  -155,   384,  -155,  -155,    87,    88,  -155,  -155,
      82,   498,    82,   498,    79,    90,    92,    94,    98,  -155,
     187,   188,   196,   200,   201,   202,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,   186,   190,   472,    11,
    -155,    82,  -155,    82,  -155,    82,  -155,    82,    -6,  -155,
      82,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,    82,
    -155,   498,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
     498,  -155,  -155,  -155,  -155,  -155,  -155,   233,   175,   208,
     242,   243,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
     123,   124,  -155,  -155,  -155,  -155,  -155,  -155,   229,  -155,
     231,  -155,   131,    19,  -155,   256,  -155,   257,   472,    82,
     498,    82,   498,  -155,  -155,   136,   137,  -155,   239,  -155,
     244,  -155,    82,   498,  -155,  -155,  -155,  -155,   240,   245,
    -155,  -155,   143,   145,   246,   247,  -155,  -155,  -155,  -155,
    -155,  -155
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     240,   239,     0,   235,     0,     0,     0,     0,     0,   230,
       0,     0,   195,     0,     0,     0,     0,     0,     0,     0,
     226,     0,   222,   229,     0,     0,     0,   233,   234,   224,
       0,   244,   241,   246,   248,   250,     0,     0,     0,    99,
     100,   209,     0,     0,     0,   113,   114,   211,     0,    48,
      49,     0,     0,     0,     0,     0,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,    23,    28,
      29,    30,    31,    32,    33,    36,    37,     0,    38,    39,
       0,    45,    56,    67,     0,   124,   125,   212,     0,     0,
       0,     0,     0,     0,     0,    93,    94,   208,     0,     0,
     156,   157,   213,     0,   159,   160,   161,   165,   166,   214,
     185,   186,     0,     0,     0,   193,   194,   219,     0,   203,
     221,   199,   200,   231,   171,   172,   173,   216,     0,   176,
     177,   217,     0,   179,   183,   184,   218,   223,   227,   228,
     238,     0,   169,   170,   215,     0,   206,   207,   220,   201,
     202,   232,     0,   236,     0,   240,   242,   240,   240,     1,
       0,     0,     0,   107,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     3,
       4,     6,     8,     9,     5,    10,    54,     2,    34,    21,
      24,    25,    26,    27,    22,    35,   115,   118,   116,   117,
     119,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,   122,   123,     0,     0,   105,   106,   210,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,     0,     0,   131,   132,     0,     0,     0,     0,   128,
     127,    68,     0,     0,     0,   146,   147,     0,     0,     0,
       0,   143,   142,     0,   158,   163,     0,   187,   190,     0,
       0,     0,   174,   175,   178,   181,     0,   167,   168,     0,
     225,   237,   245,   240,   247,   249,     0,     0,    95,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     0,    57,    58,    61,    63,
      64,    65,    66,    62,    59,    60,     0,     0,     0,     0,
      75,     0,    87,     0,    79,     0,    83,     0,    71,   129,
       0,   136,   135,   140,   139,   134,   138,   133,   137,     0,
     144,     0,   151,   150,   155,   154,   149,   153,   148,   152,
       0,   162,   164,   188,   191,   189,   192,   196,     0,     0,
       0,     0,   243,    96,    98,   109,   112,   108,   111,    44,
      40,    41,    43,    42,    46,    47,    50,    51,    52,    53,
       0,     0,   101,   103,    72,    85,    77,    80,    74,    86,
      78,    82,     0,     0,   126,     0,   141,     0,     0,     0,
       0,     0,     0,   102,   104,     0,     0,    88,    73,    84,
      76,    81,     0,     0,   197,   198,   180,   182,     0,     0,
      90,    92,     0,     0,     0,     0,   204,   205,    89,    91,
     130,   145
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -155,     0,  -155,  -155,  -155,   -45,    34,    -8,   185,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,   197,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -154,  -155,  -155,  -155,    -2,  -155
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    80,   185,   186,    81,    82,    83,    84,   242,    95,
      96,    97,    39,    40,    41,   217,   218,   219,    45,    46,
      47,   201,    85,    86,    87,   100,   101,   102,   107,   108,
     109,   142,   143,   144,   126,   127,   129,   130,   131,   134,
     135,   136,   115,   116,   117,   119,   123,   151,   120,   146,
     147,   148,    32,    33,   273,    34,   155,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      99,   272,    89,   174,    37,   215,   221,   223,    98,   137,
      90,   132,   225,   140,   227,   202,   203,   178,   103,   204,
     382,   205,   206,   207,   208,   209,   193,    91,    42,   161,
     104,   105,   194,    43,   164,   166,   168,   160,   325,   383,
     374,    88,   163,   165,   167,   327,   118,   326,   398,   189,
     230,   231,   190,   191,   328,    92,    93,   375,   232,   192,
     336,   128,   233,   234,   138,   399,   179,   180,   181,   337,
     338,   235,   141,    44,   133,   182,   183,   184,   145,   339,
     236,   106,   237,   238,   156,   376,   377,   157,   121,   220,
     122,   239,   240,   400,   401,   255,   139,   196,   197,   153,
     152,   210,   241,   254,   258,   158,   154,   270,   149,   211,
     150,    94,   257,    38,   216,   222,   224,   124,   125,   352,
     263,   226,   159,   228,   265,   198,   199,   200,   262,   321,
     322,   162,   264,   268,   175,   110,   111,   112,   113,   323,
     324,   267,   332,   333,   334,   335,   271,   114,   176,   177,
     188,   230,   243,   195,   279,   274,   275,   196,   212,   244,
     229,    55,   278,   245,   246,   187,   256,   291,   293,   295,
     259,   260,   247,   261,   266,   290,   292,   294,   269,   276,
     277,   248,   280,   249,   250,   198,   199,   213,   281,   282,
     283,   284,   251,   252,   285,   286,   287,   288,   289,   308,
     309,   311,   313,   241,   315,   317,   320,   307,   329,   331,
     347,   359,   370,   340,   389,   306,   371,   353,   354,   364,
     365,   310,   360,   312,   361,   314,   362,   316,   366,   318,
     363,   319,   367,   368,   369,   330,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   388,   390,   342,   391,
     392,   344,   346,   393,   394,   395,   341,   396,   349,   343,
     345,   351,   397,   402,   403,   412,   348,   410,   411,   350,
     413,     1,   416,   356,   418,   358,   419,   417,   420,   421,
     355,   214,   357,     0,   253,     0,     0,     2,     3,     0,
       4,     0,     5,     6,     0,     7,     8,     0,     0,     0,
     373,     0,     0,     9,     0,    10,    11,     0,   372,     0,
       0,   378,    12,   379,     0,   380,     0,   381,    13,     0,
     384,     0,     0,   386,     0,     0,    14,    15,    16,   385,
       0,     0,   387,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,    19,     0,    20,     0,     0,     0,
       0,    21,     0,    22,    23,    24,    25,    26,    27,    28,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
     405,     0,   407,     0,   409,     0,     0,     1,   404,   406,
       0,   408,     0,     0,     0,   415,     0,     0,    30,     0,
      31,     0,   414,     2,     3,   169,     4,     0,     5,     6,
       0,     7,     8,     0,    48,     0,     0,     0,     0,     9,
       0,    10,    11,     0,     0,     0,     0,     0,    12,     0,
      49,    50,    51,     0,    13,     0,     0,     0,     0,     0,
       0,     0,    14,    15,    16,     0,     0,    52,     0,    17,
      53,     0,     0,    54,   170,   171,   172,     0,     0,     0,
       0,     0,     0,     0,     0,   173,     0,     0,     0,    18,
      19,     0,    20,     0,     0,     0,     0,    21,     0,    22,
      23,    24,    25,    26,    27,    28,     0,    29,     0,     0,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    48,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    30,    79,     0,     0,     0,    49,
      50,    51,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,    52,     0,     0,    53,
       0,     0,    54,     0,     0,    49,    50,    51,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,     0,     0,    53,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,     0,    79,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,     0,
      79
};

static const yytype_int16 yycheck[] =
{
       8,   155,    21,    48,    21,    21,    21,    21,     8,    17,
      29,    21,    21,    21,    21,     8,     9,    22,    21,    12,
      26,    14,    15,    16,    17,    18,   113,    46,    23,    37,
      33,    34,   119,    28,    42,    43,    44,    37,    42,    45,
      29,    19,    42,    43,    44,    42,   130,    51,    29,   109,
      21,    22,   112,   113,    51,    74,    75,    46,    29,   119,
      42,    21,    33,    34,    87,    46,    71,    72,    73,    51,
      42,    42,    21,    68,    84,    80,    81,    82,    21,    51,
      51,    84,    53,    54,     6,    74,    75,     4,   130,    89,
     132,    62,    63,    74,    75,   103,    87,    76,    77,     6,
      65,    94,    73,   103,   112,     4,    13,   152,   130,   102,
     132,   130,   112,   130,   130,   130,   130,    33,    34,   273,
     128,   130,     0,   130,   132,   104,   105,   106,   128,    53,
      54,    21,   132,   141,    31,    39,    40,    41,    42,    53,
      54,   141,    53,    54,    53,    54,   154,    51,    31,    31,
     112,    21,    22,   112,   162,   157,   158,    76,    77,    29,
      21,    79,   162,    33,    34,   132,    26,   175,   176,   177,
      43,    43,    42,    39,    26,   175,   176,   177,    31,    26,
      26,    51,    69,    53,    54,   104,   105,   106,    69,    69,
      69,    32,    62,    63,    32,    32,    32,    32,    32,    21,
      45,    21,    21,    73,    21,    21,    30,   215,    31,    30,
     130,   132,    26,    31,    39,   215,    26,   130,   130,    32,
      32,   221,   132,   223,   132,   225,   132,   227,    32,   229,
     132,   231,    32,    32,    32,   243,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    13,    39,   256,     7,
       7,   259,   260,   130,   130,    26,   256,    26,   266,   259,
     260,   269,   131,     7,     7,    26,   266,   131,   131,   269,
      26,     3,    32,   281,   131,   283,   131,    32,    32,    32,
     280,    84,   282,    -1,    99,    -1,    -1,    19,    20,    -1,
      22,    -1,    24,    25,    -1,    27,    28,    -1,    -1,    -1,
     308,    -1,    -1,    35,    -1,    37,    38,    -1,   308,    -1,
      -1,   311,    44,   313,    -1,   315,    -1,   317,    50,    -1,
     320,    -1,    -1,   331,    -1,    -1,    58,    59,    60,   329,
      -1,    -1,   340,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    93,    -1,    95,    96,    97,    98,    99,   100,   101,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     388,    -1,   390,    -1,   392,    -1,    -1,     3,   388,   389,
      -1,   391,    -1,    -1,    -1,   403,    -1,    -1,   130,    -1,
     132,    -1,   402,    19,    20,    22,    22,    -1,    24,    25,
      -1,    27,    28,    -1,    31,    -1,    -1,    -1,    -1,    35,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      47,    48,    49,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    -1,    -1,    64,    -1,    65,
      67,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    85,
      86,    -1,    88,    -1,    -1,    -1,    -1,    93,    -1,    95,
      96,    97,    98,    99,   100,   101,    -1,   103,    -1,    -1,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    31,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   130,   132,    -1,    -1,    -1,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    67,
      -1,    -1,    70,    -1,    -1,    47,    48,    49,    -1,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,    -1,    67,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,   132,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
     132
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    19,    20,    22,    24,    25,    27,    28,    35,
      37,    38,    44,    50,    58,    59,    60,    65,    85,    86,
      88,    93,    95,    96,    97,    98,    99,   100,   101,   103,
     130,   132,   185,   186,   188,   190,   191,    21,   130,   145,
     146,   147,    23,    28,    68,   151,   152,   153,    31,    47,
      48,    49,    64,    67,    70,    79,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   132,
     134,   137,   138,   139,   140,   155,   156,   157,    19,    21,
      29,    46,    74,    75,   130,   142,   143,   144,   134,   140,
     158,   159,   160,    21,    33,    34,    84,   161,   162,   163,
      39,    40,    41,    42,    51,   175,   176,   177,   130,   178,
     181,   130,   132,   179,    33,    34,   167,   168,    21,   169,
     170,   171,    21,    84,   172,   173,   174,   140,    87,    87,
     140,    21,   164,   165,   166,    21,   182,   183,   184,   130,
     132,   180,    65,     6,    13,   189,     6,     4,     4,     0,
     134,   140,    21,   134,   140,   134,   140,   134,   140,    22,
      71,    72,    73,    82,   138,    31,    31,    31,    22,    71,
      72,    73,    80,    81,    82,   135,   136,   132,   112,   109,
     112,   113,   119,   113,   119,   112,    76,    77,   104,   105,
     106,   154,     8,     9,    12,    14,    15,    16,    17,    18,
      94,   102,    77,   106,   154,    21,   130,   148,   149,   150,
     134,    21,   130,    21,   130,    21,   130,    21,   130,    21,
      21,    22,    29,    33,    34,    42,    51,    53,    54,    62,
      63,    73,   141,    22,    29,    33,    34,    42,    51,    53,
      54,    62,    63,   141,   134,   140,    26,   134,   140,    43,
      43,    39,   134,   140,   134,   140,    26,   134,   140,    31,
     138,   140,   186,   187,   190,   190,    26,    26,   134,   140,
      69,    69,    69,    69,    32,    32,    32,    32,    32,    32,
     134,   140,   134,   140,   134,   140,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   134,   140,    21,    45,
     134,    21,   134,    21,   134,    21,   134,    21,   134,   134,
      30,    53,    54,    53,    54,    42,    51,    42,    51,    31,
     140,    30,    53,    54,    53,    54,    42,    51,    42,    51,
      31,   134,   140,   134,   140,   134,   140,   130,   134,   140,
     134,   140,   186,   130,   130,   134,   140,   134,   140,   132,
     132,   132,   132,   132,    32,    32,    32,    32,    32,    32,
      26,    26,   134,   140,    29,    46,    74,    75,   134,   134,
     134,   134,    26,    45,   134,   134,   140,   140,    13,    39,
      39,     7,     7,   130,   130,    26,    26,   131,    29,    46,
      74,    75,     7,     7,   134,   140,   134,   140,   134,   140,
     131,   131,    26,    26,   134,   140,    32,    32,   131,   131,
      32,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   133,   134,   135,   135,   135,   135,   135,   135,   135,
     136,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   140,   141,   141,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   143,   143,
     143,   143,   143,   144,   144,   145,   145,   146,   146,   147,
     147,   148,   148,   149,   149,   150,   150,   151,   151,   151,
     152,   152,   152,   153,   153,   154,   154,   154,   155,   155,
     155,   156,   156,   156,   157,   157,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   160,   160,   161,   161,
     161,   161,   161,   162,   162,   163,   163,   164,   165,   166,
     166,   167,   167,   168,   169,   170,   171,   171,   172,   172,
     172,   173,   173,   174,   174,   175,   175,   175,   175,   175,
     176,   176,   176,   177,   177,   178,   178,   178,   178,   179,
     179,   180,   180,   181,   182,   183,   184,   184,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   186,   187,   186,   189,   188,   190,   190,   190,   190,
     191
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
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       2,     3,     4,     5,     4,     3,     5,     4,     4,     3,
       4,     5,     4,     3,     5,     4,     4,     3,     5,     7,
       6,     7,     6,     1,     1,     3,     4,     3,     4,     1,
       1,     3,     4,     3,     4,     1,     1,     2,     4,     4,
       2,     4,     4,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     1,     1,     4,     2,     2,     3,
       7,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     2,     2,     3,     7,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     2,     1,
       1,     1,     3,     2,     3,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     2,     1,
       5,     2,     5,     1,     1,     1,     1,     2,     3,     3,
       2,     3,     3,     1,     1,     0,     3,     5,     5,     1,
       1,     1,     1,     1,     6,     6,     1,     1,     2,     2,
       3,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     1,     3,     1,     2,     2,     1,
       1,     2,     2,     1,     1,     1,     2,     3,     2,     1,
       0,     1,     0,     4,     0,     3,     1,     3,     1,     3,
       1
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
#line 2020 "src-generated/ugbc.tab.c"
    break;

  case 3: /* random_definition_simple: BYTE  */
#line 67 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 2028 "src-generated/ugbc.tab.c"
    break;

  case 4: /* random_definition_simple: WORD  */
#line 70 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 2036 "src-generated/ugbc.tab.c"
    break;

  case 5: /* random_definition_simple: DWORD  */
#line 73 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 2044 "src-generated/ugbc.tab.c"
    break;

  case 6: /* random_definition_simple: POSITION  */
#line 76 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 2052 "src-generated/ugbc.tab.c"
    break;

  case 7: /* random_definition_simple: COLOR  */
#line 79 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 2060 "src-generated/ugbc.tab.c"
    break;

  case 8: /* random_definition_simple: WIDTH  */
#line 82 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 2068 "src-generated/ugbc.tab.c"
    break;

  case 9: /* random_definition_simple: HEIGHT  */
#line 85 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 2076 "src-generated/ugbc.tab.c"
    break;

  case 10: /* random_definition: random_definition_simple  */
#line 90 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 2084 "src-generated/ugbc.tab.c"
    break;

  case 11: /* color_enumeration: BLACK  */
#line 95 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 2093 "src-generated/ugbc.tab.c"
    break;

  case 12: /* color_enumeration: WHITE  */
#line 99 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 2102 "src-generated/ugbc.tab.c"
    break;

  case 13: /* color_enumeration: RED  */
#line 103 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 2111 "src-generated/ugbc.tab.c"
    break;

  case 14: /* color_enumeration: CYAN  */
#line 107 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 2120 "src-generated/ugbc.tab.c"
    break;

  case 15: /* color_enumeration: VIOLET  */
#line 111 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 2129 "src-generated/ugbc.tab.c"
    break;

  case 16: /* color_enumeration: GREEN  */
#line 115 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 2138 "src-generated/ugbc.tab.c"
    break;

  case 17: /* color_enumeration: BLUE  */
#line 119 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 2147 "src-generated/ugbc.tab.c"
    break;

  case 18: /* color_enumeration: YELLOW  */
#line 123 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 2156 "src-generated/ugbc.tab.c"
    break;

  case 19: /* color_enumeration: ORANGE  */
#line 127 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 2165 "src-generated/ugbc.tab.c"
    break;

  case 20: /* color_enumeration: BROWN  */
#line 131 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 2174 "src-generated/ugbc.tab.c"
    break;

  case 21: /* color_enumeration: LIGHT RED  */
#line 135 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 2183 "src-generated/ugbc.tab.c"
    break;

  case 22: /* color_enumeration: DARK GREY  */
#line 139 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 2192 "src-generated/ugbc.tab.c"
    break;

  case 23: /* color_enumeration: GREY  */
#line 143 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 2201 "src-generated/ugbc.tab.c"
    break;

  case 24: /* color_enumeration: LIGHT GREEN  */
#line 147 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 2210 "src-generated/ugbc.tab.c"
    break;

  case 25: /* color_enumeration: LIGHT BLUE  */
#line 151 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 2219 "src-generated/ugbc.tab.c"
    break;

  case 26: /* color_enumeration: LIGHT GREY  */
#line 155 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 2228 "src-generated/ugbc.tab.c"
    break;

  case 27: /* color_enumeration: DARK BLUE  */
#line 159 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 2237 "src-generated/ugbc.tab.c"
    break;

  case 28: /* color_enumeration: MAGENTA  */
#line 163 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 2246 "src-generated/ugbc.tab.c"
    break;

  case 29: /* color_enumeration: PURPLE  */
#line 167 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 2255 "src-generated/ugbc.tab.c"
    break;

  case 30: /* color_enumeration: LAVENDER  */
#line 171 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 2264 "src-generated/ugbc.tab.c"
    break;

  case 31: /* color_enumeration: GOLD  */
#line 175 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 2273 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: TURQUOISE  */
#line 179 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 2282 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: TAN  */
#line 183 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 2291 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: YELLOW GREEN  */
#line 187 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 2300 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: OLIVE GREEN  */
#line 191 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 2309 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: PINK  */
#line 195 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 2318 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: PEACH  */
#line 199 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 2327 "src-generated/ugbc.tab.c"
    break;

  case 38: /* expression: Identifier  */
#line 205 "src/ugbc.y"
                 { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2335 "src-generated/ugbc.tab.c"
    break;

  case 39: /* expression: Integer  */
#line 208 "src/ugbc.y"
              { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2344 "src-generated/ugbc.tab.c"
    break;

  case 40: /* expression: OP BYTE CP Integer  */
#line 212 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2353 "src-generated/ugbc.tab.c"
    break;

  case 41: /* expression: OP WORD CP Integer  */
#line 216 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2362 "src-generated/ugbc.tab.c"
    break;

  case 42: /* expression: OP DWORD CP Integer  */
#line 220 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2371 "src-generated/ugbc.tab.c"
    break;

  case 43: /* expression: OP POSITION CP Integer  */
#line 224 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2380 "src-generated/ugbc.tab.c"
    break;

  case 44: /* expression: OP COLOR CP Integer  */
#line 228 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 2389 "src-generated/ugbc.tab.c"
    break;

  case 45: /* expression: color_enumeration  */
#line 232 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 2397 "src-generated/ugbc.tab.c"
    break;

  case 46: /* expression: PEEK OP direct_integer CP  */
#line 235 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2405 "src-generated/ugbc.tab.c"
    break;

  case 47: /* expression: PEEK OP expressions CP  */
#line 238 "src/ugbc.y"
                             {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 2413 "src-generated/ugbc.tab.c"
    break;

  case 48: /* expression: XPEN  */
#line 241 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 2421 "src-generated/ugbc.tab.c"
    break;

  case 49: /* expression: YPEN  */
#line 244 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 2429 "src-generated/ugbc.tab.c"
    break;

  case 50: /* expression: COLLISION OP direct_integer CP  */
#line 247 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2437 "src-generated/ugbc.tab.c"
    break;

  case 51: /* expression: COLLISION OP expressions CP  */
#line 250 "src/ugbc.y"
                                  {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2445 "src-generated/ugbc.tab.c"
    break;

  case 52: /* expression: HIT OP direct_integer CP  */
#line 253 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 2453 "src-generated/ugbc.tab.c"
    break;

  case 53: /* expression: HIT OP expressions CP  */
#line 256 "src/ugbc.y"
                            {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 2461 "src-generated/ugbc.tab.c"
    break;

  case 54: /* expression: RANDOM random_definition  */
#line 259 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 2469 "src-generated/ugbc.tab.c"
    break;

  case 55: /* expression: OP expression CP  */
#line 262 "src/ugbc.y"
                       {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 2477 "src-generated/ugbc.tab.c"
    break;

  case 56: /* expressions_raw: expression  */
#line 268 "src/ugbc.y"
                 { (yyval.string) = (yyvsp[0].string); }
#line 2483 "src-generated/ugbc.tab.c"
    break;

  case 57: /* expressions_raw: expression PLUS expressions_raw  */
#line 269 "src/ugbc.y"
                                      {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2491 "src-generated/ugbc.tab.c"
    break;

  case 58: /* expressions_raw: expression MINUS expressions_raw  */
#line 272 "src/ugbc.y"
                                       {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2500 "src-generated/ugbc.tab.c"
    break;

  case 59: /* expressions_raw: expression AND expressions_raw  */
#line 276 "src/ugbc.y"
                                     {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2509 "src-generated/ugbc.tab.c"
    break;

  case 60: /* expressions_raw: expression OR expressions_raw  */
#line 280 "src/ugbc.y"
                                    {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2518 "src-generated/ugbc.tab.c"
    break;

  case 61: /* expressions_raw: expression EQUAL expressions_raw  */
#line 284 "src/ugbc.y"
                                       {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2526 "src-generated/ugbc.tab.c"
    break;

  case 62: /* expressions_raw: expression DISEQUAL expressions_raw  */
#line 287 "src/ugbc.y"
                                          {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2534 "src-generated/ugbc.tab.c"
    break;

  case 63: /* expressions_raw: expression LT expressions_raw  */
#line 290 "src/ugbc.y"
                                    {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2542 "src-generated/ugbc.tab.c"
    break;

  case 64: /* expressions_raw: expression LTE expressions_raw  */
#line 293 "src/ugbc.y"
                                     {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2550 "src-generated/ugbc.tab.c"
    break;

  case 65: /* expressions_raw: expression GT expressions_raw  */
#line 296 "src/ugbc.y"
                                    {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2558 "src-generated/ugbc.tab.c"
    break;

  case 66: /* expressions_raw: expression GTE expressions_raw  */
#line 299 "src/ugbc.y"
                                     {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2566 "src-generated/ugbc.tab.c"
    break;

  case 67: /* expressions: expressions_raw  */
#line 305 "src/ugbc.y"
                    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2574 "src-generated/ugbc.tab.c"
    break;

  case 70: /* bank_definition_simple: AT direct_integer  */
#line 312 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2582 "src-generated/ugbc.tab.c"
    break;

  case 71: /* bank_definition_simple: Identifier AT direct_integer  */
#line 315 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2590 "src-generated/ugbc.tab.c"
    break;

  case 72: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 318 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2598 "src-generated/ugbc.tab.c"
    break;

  case 73: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 321 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 2606 "src-generated/ugbc.tab.c"
    break;

  case 74: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 324 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2614 "src-generated/ugbc.tab.c"
    break;

  case 75: /* bank_definition_simple: DATA AT direct_integer  */
#line 327 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 2622 "src-generated/ugbc.tab.c"
    break;

  case 76: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 331 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2630 "src-generated/ugbc.tab.c"
    break;

  case 77: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 334 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 2638 "src-generated/ugbc.tab.c"
    break;

  case 78: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 337 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2646 "src-generated/ugbc.tab.c"
    break;

  case 79: /* bank_definition_simple: CODE AT direct_integer  */
#line 340 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 2654 "src-generated/ugbc.tab.c"
    break;

  case 80: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 344 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2662 "src-generated/ugbc.tab.c"
    break;

  case 81: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 347 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 2670 "src-generated/ugbc.tab.c"
    break;

  case 82: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 350 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 2678 "src-generated/ugbc.tab.c"
    break;

  case 83: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 353 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 2686 "src-generated/ugbc.tab.c"
    break;

  case 84: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 357 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 2694 "src-generated/ugbc.tab.c"
    break;

  case 85: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 360 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 2702 "src-generated/ugbc.tab.c"
    break;

  case 86: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 363 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 2710 "src-generated/ugbc.tab.c"
    break;

  case 87: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 366 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 2718 "src-generated/ugbc.tab.c"
    break;

  case 88: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 372 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2726 "src-generated/ugbc.tab.c"
    break;

  case 89: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 375 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 2734 "src-generated/ugbc.tab.c"
    break;

  case 90: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 378 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2742 "src-generated/ugbc.tab.c"
    break;

  case 91: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 381 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 2750 "src-generated/ugbc.tab.c"
    break;

  case 92: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 384 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 2758 "src-generated/ugbc.tab.c"
    break;

  case 95: /* raster_definition_simple: Identifier AT direct_integer  */
#line 393 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 2766 "src-generated/ugbc.tab.c"
    break;

  case 96: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 396 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 2774 "src-generated/ugbc.tab.c"
    break;

  case 97: /* raster_definition_expression: Identifier AT expressions  */
#line 401 "src/ugbc.y"
                              {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2782 "src-generated/ugbc.tab.c"
    break;

  case 98: /* raster_definition_expression: AT expressions WITH Identifier  */
#line 404 "src/ugbc.y"
                                   {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2790 "src-generated/ugbc.tab.c"
    break;

  case 101: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 413 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 2798 "src-generated/ugbc.tab.c"
    break;

  case 102: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 416 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 2806 "src-generated/ugbc.tab.c"
    break;

  case 103: /* next_raster_definition_expression: Identifier AT expressions  */
#line 421 "src/ugbc.y"
                              {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 2814 "src-generated/ugbc.tab.c"
    break;

  case 104: /* next_raster_definition_expression: AT expressions WITH Identifier  */
#line 424 "src/ugbc.y"
                                   {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2822 "src-generated/ugbc.tab.c"
    break;

  case 107: /* color_definition_simple: BORDER direct_integer  */
#line 433 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 2830 "src-generated/ugbc.tab.c"
    break;

  case 108: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 436 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 2838 "src-generated/ugbc.tab.c"
    break;

  case 109: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 439 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 2846 "src-generated/ugbc.tab.c"
    break;

  case 110: /* color_definition_expression: BORDER expressions  */
#line 444 "src/ugbc.y"
                       {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 2854 "src-generated/ugbc.tab.c"
    break;

  case 111: /* color_definition_expression: BACKGROUND expressions TO expressions  */
#line 447 "src/ugbc.y"
                                          {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 2862 "src-generated/ugbc.tab.c"
    break;

  case 112: /* color_definition_expression: SPRITE expressions TO expressions  */
#line 450 "src/ugbc.y"
                                      {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 2870 "src-generated/ugbc.tab.c"
    break;

  case 118: /* wait_definition_simple: direct_integer CYCLES  */
#line 464 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 2878 "src-generated/ugbc.tab.c"
    break;

  case 119: /* wait_definition_simple: direct_integer TICKS  */
#line 467 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 2886 "src-generated/ugbc.tab.c"
    break;

  case 120: /* wait_definition_simple: direct_integer milliseconds  */
#line 470 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 2894 "src-generated/ugbc.tab.c"
    break;

  case 121: /* wait_definition_expression: expressions CYCLES  */
#line 475 "src/ugbc.y"
                         {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 2902 "src-generated/ugbc.tab.c"
    break;

  case 122: /* wait_definition_expression: expressions TICKS  */
#line 478 "src/ugbc.y"
                        {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 2910 "src-generated/ugbc.tab.c"
    break;

  case 123: /* wait_definition_expression: expressions milliseconds  */
#line 481 "src/ugbc.y"
                               {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 2918 "src-generated/ugbc.tab.c"
    break;

  case 126: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 491 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 2926 "src-generated/ugbc.tab.c"
    break;

  case 127: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 494 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 2934 "src-generated/ugbc.tab.c"
    break;

  case 128: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 497 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 2942 "src-generated/ugbc.tab.c"
    break;

  case 129: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 500 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 2950 "src-generated/ugbc.tab.c"
    break;

  case 130: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 503 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 2958 "src-generated/ugbc.tab.c"
    break;

  case 131: /* sprite_definition_simple: direct_integer ENABLE  */
#line 506 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 2966 "src-generated/ugbc.tab.c"
    break;

  case 132: /* sprite_definition_simple: direct_integer DISABLE  */
#line 509 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 2974 "src-generated/ugbc.tab.c"
    break;

  case 133: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 512 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 2982 "src-generated/ugbc.tab.c"
    break;

  case 134: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 515 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 2990 "src-generated/ugbc.tab.c"
    break;

  case 135: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 518 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 2998 "src-generated/ugbc.tab.c"
    break;

  case 136: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 521 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 3006 "src-generated/ugbc.tab.c"
    break;

  case 137: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 524 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3014 "src-generated/ugbc.tab.c"
    break;

  case 138: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 527 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3022 "src-generated/ugbc.tab.c"
    break;

  case 139: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 530 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3030 "src-generated/ugbc.tab.c"
    break;

  case 140: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 533 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 3038 "src-generated/ugbc.tab.c"
    break;

  case 141: /* sprite_definition_expression: expressions DATA FROM expressions  */
#line 538 "src/ugbc.y"
                                      {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 3046 "src-generated/ugbc.tab.c"
    break;

  case 142: /* sprite_definition_expression: expressions MULTICOLOR  */
#line 541 "src/ugbc.y"
                           {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3054 "src-generated/ugbc.tab.c"
    break;

  case 143: /* sprite_definition_expression: expressions MONOCOLOR  */
#line 544 "src/ugbc.y"
                          {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 3062 "src-generated/ugbc.tab.c"
    break;

  case 144: /* sprite_definition_expression: expressions COLOR expressions  */
#line 547 "src/ugbc.y"
                                  {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3070 "src-generated/ugbc.tab.c"
    break;

  case 145: /* sprite_definition_expression: expressions position OP expressions COMMA expressions CP  */
#line 550 "src/ugbc.y"
                                                             {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 3078 "src-generated/ugbc.tab.c"
    break;

  case 146: /* sprite_definition_expression: expressions ENABLE  */
#line 553 "src/ugbc.y"
                       {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 3086 "src-generated/ugbc.tab.c"
    break;

  case 147: /* sprite_definition_expression: expressions DISABLE  */
#line 556 "src/ugbc.y"
                        {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 3094 "src-generated/ugbc.tab.c"
    break;

  case 148: /* sprite_definition_expression: expressions EXPAND VERTICAL  */
#line 559 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3102 "src-generated/ugbc.tab.c"
    break;

  case 149: /* sprite_definition_expression: expressions COMPRESS VERTICAL  */
#line 562 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3110 "src-generated/ugbc.tab.c"
    break;

  case 150: /* sprite_definition_expression: expressions VERTICAL EXPAND  */
#line 565 "src/ugbc.y"
                                {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3118 "src-generated/ugbc.tab.c"
    break;

  case 151: /* sprite_definition_expression: expressions VERTICAL COMPRESS  */
#line 568 "src/ugbc.y"
                                  {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 3126 "src-generated/ugbc.tab.c"
    break;

  case 152: /* sprite_definition_expression: expressions EXPAND HORIZONTAL  */
#line 571 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3134 "src-generated/ugbc.tab.c"
    break;

  case 153: /* sprite_definition_expression: expressions COMPRESS HORIZONTAL  */
#line 574 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3142 "src-generated/ugbc.tab.c"
    break;

  case 154: /* sprite_definition_expression: expressions HORIZONTAL EXPAND  */
#line 577 "src/ugbc.y"
                                  {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3150 "src-generated/ugbc.tab.c"
    break;

  case 155: /* sprite_definition_expression: expressions HORIZONTAL COMPRESS  */
#line 580 "src/ugbc.y"
                                    {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 3158 "src-generated/ugbc.tab.c"
    break;

  case 158: /* bitmap_definition_simple: AT direct_integer  */
#line 589 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3166 "src-generated/ugbc.tab.c"
    break;

  case 159: /* bitmap_definition_simple: ENABLE  */
#line 592 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 3174 "src-generated/ugbc.tab.c"
    break;

  case 160: /* bitmap_definition_simple: DISABLE  */
#line 595 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 3182 "src-generated/ugbc.tab.c"
    break;

  case 161: /* bitmap_definition_simple: CLEAR  */
#line 598 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 3190 "src-generated/ugbc.tab.c"
    break;

  case 162: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 601 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 3198 "src-generated/ugbc.tab.c"
    break;

  case 163: /* bitmap_definition_expression: AT expressions  */
#line 607 "src/ugbc.y"
                   {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3206 "src-generated/ugbc.tab.c"
    break;

  case 164: /* bitmap_definition_expression: CLEAR WITH expressions  */
#line 610 "src/ugbc.y"
                           {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 3214 "src-generated/ugbc.tab.c"
    break;

  case 167: /* textmap_definition_simple: AT direct_integer  */
#line 620 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 3222 "src-generated/ugbc.tab.c"
    break;

  case 168: /* textmap_definition_expression: AT expressions  */
#line 625 "src/ugbc.y"
                   {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3230 "src-generated/ugbc.tab.c"
    break;

  case 171: /* text_definition_simple: ENABLE  */
#line 634 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 3238 "src-generated/ugbc.tab.c"
    break;

  case 172: /* text_definition_simple: DISABLE  */
#line 637 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 3246 "src-generated/ugbc.tab.c"
    break;

  case 174: /* tiles_definition_simple: AT direct_integer  */
#line 645 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 3254 "src-generated/ugbc.tab.c"
    break;

  case 175: /* tiles_definition_expression: AT expressions  */
#line 650 "src/ugbc.y"
                   {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 3262 "src-generated/ugbc.tab.c"
    break;

  case 178: /* colormap_definition_simple: AT direct_integer  */
#line 659 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 3270 "src-generated/ugbc.tab.c"
    break;

  case 179: /* colormap_definition_simple: CLEAR  */
#line 662 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 3278 "src-generated/ugbc.tab.c"
    break;

  case 180: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 665 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 3286 "src-generated/ugbc.tab.c"
    break;

  case 181: /* colormap_definition_expression: AT expressions  */
#line 670 "src/ugbc.y"
                   {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 3294 "src-generated/ugbc.tab.c"
    break;

  case 182: /* colormap_definition_expression: CLEAR WITH expressions ON expressions  */
#line 673 "src/ugbc.y"
                                          {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 3302 "src-generated/ugbc.tab.c"
    break;

  case 185: /* screen_definition_simple: ON  */
#line 683 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 3310 "src-generated/ugbc.tab.c"
    break;

  case 186: /* screen_definition_simple: OFF  */
#line 686 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 3318 "src-generated/ugbc.tab.c"
    break;

  case 187: /* screen_definition_simple: ROWS direct_integer  */
#line 689 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 3326 "src-generated/ugbc.tab.c"
    break;

  case 188: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 692 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3334 "src-generated/ugbc.tab.c"
    break;

  case 189: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 695 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 3342 "src-generated/ugbc.tab.c"
    break;

  case 190: /* screen_definition_expression: ROWS expressions  */
#line 700 "src/ugbc.y"
                     {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 3350 "src-generated/ugbc.tab.c"
    break;

  case 191: /* screen_definition_expression: VERTICAL SCROLL expressions  */
#line 703 "src/ugbc.y"
                                {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3358 "src-generated/ugbc.tab.c"
    break;

  case 192: /* screen_definition_expression: HORIZONTAL SCROLL expressions  */
#line 706 "src/ugbc.y"
                                  {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 3366 "src-generated/ugbc.tab.c"
    break;

  case 196: /* var_definition_simple: Identifier ON Identifier  */
#line 715 "src/ugbc.y"
                             {
      variable_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 3374 "src-generated/ugbc.tab.c"
    break;

  case 197: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 718 "src/ugbc.y"
                                                   {
      variable_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 3382 "src-generated/ugbc.tab.c"
    break;

  case 198: /* var_definition_simple: Identifier ON Identifier ASSIGN expressions  */
#line 721 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      if ( v == NULL ) {
          CRITICAL("Variable not found");
      }
      Variable * d = variable_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 3395 "src-generated/ugbc.tab.c"
    break;

  case 199: /* goto_definition: Identifier  */
#line 731 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 3403 "src-generated/ugbc.tab.c"
    break;

  case 200: /* goto_definition: Integer  */
#line 734 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 3411 "src-generated/ugbc.tab.c"
    break;

  case 201: /* gosub_definition: Identifier  */
#line 740 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 3419 "src-generated/ugbc.tab.c"
    break;

  case 202: /* gosub_definition: Integer  */
#line 743 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 3427 "src-generated/ugbc.tab.c"
    break;

  case 204: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 752 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 3435 "src-generated/ugbc.tab.c"
    break;

  case 205: /* point_definition_expression: AT OP expressions COMMA expressions CP  */
#line 758 "src/ugbc.y"
                                             {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 3443 "src-generated/ugbc.tab.c"
    break;

  case 222: /* statement: RANDOMIZE  */
#line 781 "src/ugbc.y"
              {
      randomize( _environment );
  }
#line 3451 "src-generated/ugbc.tab.c"
    break;

  case 223: /* statement: IF expressions  */
#line 784 "src/ugbc.y"
                   {
      if_then( _environment, (yyvsp[0].string) );  
  }
#line 3459 "src-generated/ugbc.tab.c"
    break;

  case 224: /* statement: ELSE  */
#line 787 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 3467 "src-generated/ugbc.tab.c"
    break;

  case 225: /* statement: ELSE IF expression  */
#line 790 "src/ugbc.y"
                       {
      else_if_then( _environment, (yyvsp[0].string) );  
  }
#line 3475 "src-generated/ugbc.tab.c"
    break;

  case 226: /* statement: ENDIF  */
#line 793 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 3483 "src-generated/ugbc.tab.c"
    break;

  case 227: /* statement: BEG GAMELOOP  */
#line 796 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 3491 "src-generated/ugbc.tab.c"
    break;

  case 228: /* statement: END GAMELOOP  */
#line 799 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 3499 "src-generated/ugbc.tab.c"
    break;

  case 229: /* statement: GRAPHIC  */
#line 802 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 3507 "src-generated/ugbc.tab.c"
    break;

  case 230: /* statement: HALT  */
#line 805 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 3515 "src-generated/ugbc.tab.c"
    break;

  case 233: /* statement: RETURN  */
#line 810 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 3523 "src-generated/ugbc.tab.c"
    break;

  case 234: /* statement: POP  */
#line 813 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 3531 "src-generated/ugbc.tab.c"
    break;

  case 235: /* statement: DONE  */
#line 816 "src/ugbc.y"
          {
      return 0;
  }
#line 3539 "src-generated/ugbc.tab.c"
    break;

  case 236: /* statement: Identifier COLON  */
#line 819 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 3547 "src-generated/ugbc.tab.c"
    break;

  case 237: /* statement: Identifier ASSIGN expressions  */
#line 822 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expressions = variable_retrieve( _environment, (yyvsp[0].string) );
        variable_define( _environment, (yyvsp[-2].string), expressions->type, 0 )->name;
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 3558 "src-generated/ugbc.tab.c"
    break;

  case 238: /* statement: DEBUG expressions  */
#line 828 "src/ugbc.y"
                      {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 3566 "src-generated/ugbc.tab.c"
    break;

  case 241: /* statements_no_linenumbers: statement  */
#line 836 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 3572 "src-generated/ugbc.tab.c"
    break;

  case 242: /* $@1: %empty  */
#line 837 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 3578 "src-generated/ugbc.tab.c"
    break;

  case 244: /* $@2: %empty  */
#line 841 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 3586 "src-generated/ugbc.tab.c"
    break;

  case 245: /* statements_with_linenumbers: Integer $@2 statements_no_linenumbers  */
#line 843 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 3594 "src-generated/ugbc.tab.c"
    break;


#line 3598 "src-generated/ugbc.tab.c"

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

#line 857 "src/ugbc.y"


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

