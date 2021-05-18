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
 
extern char DATATYPE_AS_STRING[][16];


#line 87 "src-generated/ugbc.tab.c"

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
  YYSYMBOL_INC = 10,                       /* INC  */
  YYSYMBOL_DEC = 11,                       /* DEC  */
  YYSYMBOL_EQUAL = 12,                     /* EQUAL  */
  YYSYMBOL_ASSIGN = 13,                    /* ASSIGN  */
  YYSYMBOL_LT = 14,                        /* LT  */
  YYSYMBOL_LTE = 15,                       /* LTE  */
  YYSYMBOL_GT = 16,                        /* GT  */
  YYSYMBOL_GTE = 17,                       /* GTE  */
  YYSYMBOL_DISEQUAL = 18,                  /* DISEQUAL  */
  YYSYMBOL_MULTIPLICATION = 19,            /* MULTIPLICATION  */
  YYSYMBOL_DOLLAR = 20,                    /* DOLLAR  */
  YYSYMBOL_DIVISION = 21,                  /* DIVISION  */
  YYSYMBOL_QM = 22,                        /* QM  */
  YYSYMBOL_RASTER = 23,                    /* RASTER  */
  YYSYMBOL_DONE = 24,                      /* DONE  */
  YYSYMBOL_AT = 25,                        /* AT  */
  YYSYMBOL_COLOR = 26,                     /* COLOR  */
  YYSYMBOL_BORDER = 27,                    /* BORDER  */
  YYSYMBOL_WAIT = 28,                      /* WAIT  */
  YYSYMBOL_NEXT = 29,                      /* NEXT  */
  YYSYMBOL_WITH = 30,                      /* WITH  */
  YYSYMBOL_BANK = 31,                      /* BANK  */
  YYSYMBOL_SPRITE = 32,                    /* SPRITE  */
  YYSYMBOL_DATA = 33,                      /* DATA  */
  YYSYMBOL_FROM = 34,                      /* FROM  */
  YYSYMBOL_OP = 35,                        /* OP  */
  YYSYMBOL_CP = 36,                        /* CP  */
  YYSYMBOL_ENABLE = 37,                    /* ENABLE  */
  YYSYMBOL_DISABLE = 38,                   /* DISABLE  */
  YYSYMBOL_HALT = 39,                      /* HALT  */
  YYSYMBOL_ECM = 40,                       /* ECM  */
  YYSYMBOL_BITMAP = 41,                    /* BITMAP  */
  YYSYMBOL_SCREEN = 42,                    /* SCREEN  */
  YYSYMBOL_ON = 43,                        /* ON  */
  YYSYMBOL_OFF = 44,                       /* OFF  */
  YYSYMBOL_ROWS = 45,                      /* ROWS  */
  YYSYMBOL_VERTICAL = 46,                  /* VERTICAL  */
  YYSYMBOL_SCROLL = 47,                    /* SCROLL  */
  YYSYMBOL_VAR = 48,                       /* VAR  */
  YYSYMBOL_AS = 49,                        /* AS  */
  YYSYMBOL_TEMPORARY = 50,                 /* TEMPORARY  */
  YYSYMBOL_XPEN = 51,                      /* XPEN  */
  YYSYMBOL_YPEN = 52,                      /* YPEN  */
  YYSYMBOL_PEEK = 53,                      /* PEEK  */
  YYSYMBOL_GOTO = 54,                      /* GOTO  */
  YYSYMBOL_HORIZONTAL = 55,                /* HORIZONTAL  */
  YYSYMBOL_MCM = 56,                       /* MCM  */
  YYSYMBOL_COMPRESS = 57,                  /* COMPRESS  */
  YYSYMBOL_EXPAND = 58,                    /* EXPAND  */
  YYSYMBOL_LOOP = 59,                      /* LOOP  */
  YYSYMBOL_REPEAT = 60,                    /* REPEAT  */
  YYSYMBOL_WHILE = 61,                     /* WHILE  */
  YYSYMBOL_TEXT = 62,                      /* TEXT  */
  YYSYMBOL_TILES = 63,                     /* TILES  */
  YYSYMBOL_COLORMAP = 64,                  /* COLORMAP  */
  YYSYMBOL_SELECT = 65,                    /* SELECT  */
  YYSYMBOL_MONOCOLOR = 66,                 /* MONOCOLOR  */
  YYSYMBOL_MULTICOLOR = 67,                /* MULTICOLOR  */
  YYSYMBOL_COLLISION = 68,                 /* COLLISION  */
  YYSYMBOL_IF = 69,                        /* IF  */
  YYSYMBOL_THEN = 70,                      /* THEN  */
  YYSYMBOL_HIT = 71,                       /* HIT  */
  YYSYMBOL_BACKGROUND = 72,                /* BACKGROUND  */
  YYSYMBOL_TO = 73,                        /* TO  */
  YYSYMBOL_RANDOM = 74,                    /* RANDOM  */
  YYSYMBOL_BYTE = 75,                      /* BYTE  */
  YYSYMBOL_WORD = 76,                      /* WORD  */
  YYSYMBOL_POSITION = 77,                  /* POSITION  */
  YYSYMBOL_CODE = 78,                      /* CODE  */
  YYSYMBOL_VARIABLES = 79,                 /* VARIABLES  */
  YYSYMBOL_MS = 80,                        /* MS  */
  YYSYMBOL_CYCLES = 81,                    /* CYCLES  */
  YYSYMBOL_S = 82,                         /* S  */
  YYSYMBOL_HASH = 83,                      /* HASH  */
  YYSYMBOL_WIDTH = 84,                     /* WIDTH  */
  YYSYMBOL_HEIGHT = 85,                    /* HEIGHT  */
  YYSYMBOL_DWORD = 86,                     /* DWORD  */
  YYSYMBOL_PEN = 87,                       /* PEN  */
  YYSYMBOL_CLEAR = 88,                     /* CLEAR  */
  YYSYMBOL_BEG = 89,                       /* BEG  */
  YYSYMBOL_END = 90,                       /* END  */
  YYSYMBOL_GAMELOOP = 91,                  /* GAMELOOP  */
  YYSYMBOL_ENDIF = 92,                     /* ENDIF  */
  YYSYMBOL_UP = 93,                        /* UP  */
  YYSYMBOL_DOWN = 94,                      /* DOWN  */
  YYSYMBOL_LEFT = 95,                      /* LEFT  */
  YYSYMBOL_RIGHT = 96,                     /* RIGHT  */
  YYSYMBOL_DEBUG = 97,                     /* DEBUG  */
  YYSYMBOL_AND = 98,                       /* AND  */
  YYSYMBOL_RANDOMIZE = 99,                 /* RANDOMIZE  */
  YYSYMBOL_GRAPHIC = 100,                  /* GRAPHIC  */
  YYSYMBOL_TEXTMAP = 101,                  /* TEXTMAP  */
  YYSYMBOL_POINT = 102,                    /* POINT  */
  YYSYMBOL_GOSUB = 103,                    /* GOSUB  */
  YYSYMBOL_RETURN = 104,                   /* RETURN  */
  YYSYMBOL_POP = 105,                      /* POP  */
  YYSYMBOL_OR = 106,                       /* OR  */
  YYSYMBOL_ELSE = 107,                     /* ELSE  */
  YYSYMBOL_NOT = 108,                      /* NOT  */
  YYSYMBOL_TRUE = 109,                     /* TRUE  */
  YYSYMBOL_FALSE = 110,                    /* FALSE  */
  YYSYMBOL_DO = 111,                       /* DO  */
  YYSYMBOL_EXIT = 112,                     /* EXIT  */
  YYSYMBOL_WEND = 113,                     /* WEND  */
  YYSYMBOL_UNTIL = 114,                    /* UNTIL  */
  YYSYMBOL_FOR = 115,                      /* FOR  */
  YYSYMBOL_STEP = 116,                     /* STEP  */
  YYSYMBOL_EVERY = 117,                    /* EVERY  */
  YYSYMBOL_MID = 118,                      /* MID  */
  YYSYMBOL_INSTR = 119,                    /* INSTR  */
  YYSYMBOL_UPPER = 120,                    /* UPPER  */
  YYSYMBOL_LOWER = 121,                    /* LOWER  */
  YYSYMBOL_STR = 122,                      /* STR  */
  YYSYMBOL_VAL = 123,                      /* VAL  */
  YYSYMBOL_STRING = 124,                   /* STRING  */
  YYSYMBOL_SPACE = 125,                    /* SPACE  */
  YYSYMBOL_FLIP = 126,                     /* FLIP  */
  YYSYMBOL_CHR = 127,                      /* CHR  */
  YYSYMBOL_ASC = 128,                      /* ASC  */
  YYSYMBOL_LEN = 129,                      /* LEN  */
  YYSYMBOL_POW = 130,                      /* POW  */
  YYSYMBOL_MOD = 131,                      /* MOD  */
  YYSYMBOL_ADD = 132,                      /* ADD  */
  YYSYMBOL_MIN = 133,                      /* MIN  */
  YYSYMBOL_MAX = 134,                      /* MAX  */
  YYSYMBOL_SGN = 135,                      /* SGN  */
  YYSYMBOL_SIGNED = 136,                   /* SIGNED  */
  YYSYMBOL_ABS = 137,                      /* ABS  */
  YYSYMBOL_RND = 138,                      /* RND  */
  YYSYMBOL_COLORS = 139,                   /* COLORS  */
  YYSYMBOL_INK = 140,                      /* INK  */
  YYSYMBOL_TIMER = 141,                    /* TIMER  */
  YYSYMBOL_POWERING = 142,                 /* POWERING  */
  YYSYMBOL_DIM = 143,                      /* DIM  */
  YYSYMBOL_ADDRESS = 144,                  /* ADDRESS  */
  YYSYMBOL_PROC = 145,                     /* PROC  */
  YYSYMBOL_PROCEDURE = 146,                /* PROCEDURE  */
  YYSYMBOL_CALL = 147,                     /* CALL  */
  YYSYMBOL_OSP = 148,                      /* OSP  */
  YYSYMBOL_CSP = 149,                      /* CSP  */
  YYSYMBOL_SHARED = 150,                   /* SHARED  */
  YYSYMBOL_MILLISECOND = 151,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 152,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 153,                    /* TICKS  */
  YYSYMBOL_GLOBAL = 154,                   /* GLOBAL  */
  YYSYMBOL_PARAM = 155,                    /* PARAM  */
  YYSYMBOL_PRINT = 156,                    /* PRINT  */
  YYSYMBOL_DEFAULT = 157,                  /* DEFAULT  */
  YYSYMBOL_SPECIFIC = 158,                 /* SPECIFIC  */
  YYSYMBOL_ANSI = 159,                     /* ANSI  */
  YYSYMBOL_USE = 160,                      /* USE  */
  YYSYMBOL_PAPER = 161,                    /* PAPER  */
  YYSYMBOL_INVERSE = 162,                  /* INVERSE  */
  YYSYMBOL_REPLACE = 163,                  /* REPLACE  */
  YYSYMBOL_XOR = 164,                      /* XOR  */
  YYSYMBOL_IGNORE = 165,                   /* IGNORE  */
  YYSYMBOL_NORMAL = 166,                   /* NORMAL  */
  YYSYMBOL_WRITING = 167,                  /* WRITING  */
  YYSYMBOL_ONLY = 168,                     /* ONLY  */
  YYSYMBOL_LOCATE = 169,                   /* LOCATE  */
  YYSYMBOL_CLS = 170,                      /* CLS  */
  YYSYMBOL_HOME = 171,                     /* HOME  */
  YYSYMBOL_CMOVE = 172,                    /* CMOVE  */
  YYSYMBOL_CENTER = 173,                   /* CENTER  */
  YYSYMBOL_CENTRE = 174,                   /* CENTRE  */
  YYSYMBOL_TAB = 175,                      /* TAB  */
  YYSYMBOL_SET = 176,                      /* SET  */
  YYSYMBOL_CUP = 177,                      /* CUP  */
  YYSYMBOL_CDOWN = 178,                    /* CDOWN  */
  YYSYMBOL_CLEFT = 179,                    /* CLEFT  */
  YYSYMBOL_CRIGHT = 180,                   /* CRIGHT  */
  YYSYMBOL_CLINE = 181,                    /* CLINE  */
  YYSYMBOL_XCURS = 182,                    /* XCURS  */
  YYSYMBOL_YCURS = 183,                    /* YCURS  */
  YYSYMBOL_MEMORIZE = 184,                 /* MEMORIZE  */
  YYSYMBOL_REMEMBER = 185,                 /* REMEMBER  */
  YYSYMBOL_HSCROLL = 186,                  /* HSCROLL  */
  YYSYMBOL_VSCROLL = 187,                  /* VSCROLL  */
  YYSYMBOL_BLACK = 188,                    /* BLACK  */
  YYSYMBOL_WHITE = 189,                    /* WHITE  */
  YYSYMBOL_RED = 190,                      /* RED  */
  YYSYMBOL_CYAN = 191,                     /* CYAN  */
  YYSYMBOL_VIOLET = 192,                   /* VIOLET  */
  YYSYMBOL_GREEN = 193,                    /* GREEN  */
  YYSYMBOL_BLUE = 194,                     /* BLUE  */
  YYSYMBOL_YELLOW = 195,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 196,                   /* ORANGE  */
  YYSYMBOL_BROWN = 197,                    /* BROWN  */
  YYSYMBOL_LIGHT = 198,                    /* LIGHT  */
  YYSYMBOL_DARK = 199,                     /* DARK  */
  YYSYMBOL_GREY = 200,                     /* GREY  */
  YYSYMBOL_GRAY = 201,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 202,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 203,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 204,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 205,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 206,                /* TURQUOISE  */
  YYSYMBOL_TAN = 207,                      /* TAN  */
  YYSYMBOL_PINK = 208,                     /* PINK  */
  YYSYMBOL_PEACH = 209,                    /* PEACH  */
  YYSYMBOL_OLIVE = 210,                    /* OLIVE  */
  YYSYMBOL_Identifier = 211,               /* Identifier  */
  YYSYMBOL_String = 212,                   /* String  */
  YYSYMBOL_Integer = 213,                  /* Integer  */
  YYSYMBOL_214_ = 214,                     /* " "  */
  YYSYMBOL_YYACCEPT = 215,                 /* $accept  */
  YYSYMBOL_expr = 216,                     /* expr  */
  YYSYMBOL_expr_math = 217,                /* expr_math  */
  YYSYMBOL_term = 218,                     /* term  */
  YYSYMBOL_modula = 219,                   /* modula  */
  YYSYMBOL_factor = 220,                   /* factor  */
  YYSYMBOL_direct_integer = 221,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 222, /* random_definition_simple  */
  YYSYMBOL_random_definition = 223,        /* random_definition  */
  YYSYMBOL_color_enumeration = 224,        /* color_enumeration  */
  YYSYMBOL_exponential = 225,              /* exponential  */
  YYSYMBOL_226_1 = 226,                    /* $@1  */
  YYSYMBOL_227_2 = 227,                    /* $@2  */
  YYSYMBOL_228_3 = 228,                    /* $@3  */
  YYSYMBOL_position = 229,                 /* position  */
  YYSYMBOL_bank_definition_simple = 230,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 231, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 232,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 233, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 234, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 235,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 236, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 237, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 238,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 239,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 240, /* color_definition_expression  */
  YYSYMBOL_color_definition = 241,         /* color_definition  */
  YYSYMBOL_milliseconds = 242,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 243,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 244, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 245,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 246, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 247, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 248,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 249, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 250, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 251,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 252, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 253, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 254,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 255,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 256, /* text_definition_expression  */
  YYSYMBOL_text_definition = 257,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 258,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 259, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 260,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 261, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 262, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 263,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 264, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 265, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 266,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 267,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 268,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 269,         /* gosub_definition  */
  YYSYMBOL_var_definition = 270,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 271,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 272, /* point_definition_expression  */
  YYSYMBOL_point_definition = 273,         /* point_definition  */
  YYSYMBOL_ink_definition = 274,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 275,       /* on_goto_definition  */
  YYSYMBOL_276_4 = 276,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 277,      /* on_gosub_definition  */
  YYSYMBOL_278_5 = 278,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 279,       /* on_proc_definition  */
  YYSYMBOL_280_6 = 280,                    /* $@6  */
  YYSYMBOL_on_definition = 281,            /* on_definition  */
  YYSYMBOL_282_7 = 282,                    /* $@7  */
  YYSYMBOL_283_8 = 283,                    /* $@8  */
  YYSYMBOL_284_9 = 284,                    /* $@9  */
  YYSYMBOL_every_definition = 285,         /* every_definition  */
  YYSYMBOL_add_definition = 286,           /* add_definition  */
  YYSYMBOL_dimensions = 287,               /* dimensions  */
  YYSYMBOL_datatype = 288,                 /* datatype  */
  YYSYMBOL_dim_definition = 289,           /* dim_definition  */
  YYSYMBOL_290_10 = 290,                   /* $@10  */
  YYSYMBOL_291_11 = 291,                   /* $@11  */
  YYSYMBOL_292_12 = 292,                   /* $@12  */
  YYSYMBOL_dim_definitions = 293,          /* dim_definitions  */
  YYSYMBOL_indexes = 294,                  /* indexes  */
  YYSYMBOL_parameters = 295,               /* parameters  */
  YYSYMBOL_parameters_expr = 296,          /* parameters_expr  */
  YYSYMBOL_values = 297,                   /* values  */
  YYSYMBOL_print_definition = 298,         /* print_definition  */
  YYSYMBOL_299_13 = 299,                   /* $@13  */
  YYSYMBOL_300_14 = 300,                   /* $@14  */
  YYSYMBOL_use_definition = 301,           /* use_definition  */
  YYSYMBOL_writing_mode_definition = 302,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 303,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 304,       /* writing_definition  */
  YYSYMBOL_locate_definition = 305,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 306,         /* cmove_definition  */
  YYSYMBOL_hscroll_definition = 307,       /* hscroll_definition  */
  YYSYMBOL_vscroll_definition = 308,       /* vscroll_definition  */
  YYSYMBOL_statement = 309,                /* statement  */
  YYSYMBOL_310_15 = 310,                   /* $@15  */
  YYSYMBOL_311_16 = 311,                   /* $@16  */
  YYSYMBOL_312_17 = 312,                   /* $@17  */
  YYSYMBOL_313_18 = 313,                   /* $@18  */
  YYSYMBOL_314_19 = 314,                   /* $@19  */
  YYSYMBOL_315_20 = 315,                   /* $@20  */
  YYSYMBOL_316_21 = 316,                   /* $@21  */
  YYSYMBOL_317_22 = 317,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 318, /* statements_no_linenumbers  */
  YYSYMBOL_319_23 = 319,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 320, /* statements_with_linenumbers  */
  YYSYMBOL_321_24 = 321,                   /* $@24  */
  YYSYMBOL_statements_complex = 322,       /* statements_complex  */
  YYSYMBOL_323_25 = 323,                   /* $@25  */
  YYSYMBOL_program = 324,                  /* program  */
  YYSYMBOL_325_26 = 325                    /* $@26  */
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
#define YYLAST   3227

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  215
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  111
/* YYNRULES -- Number of rules.  */
#define YYNRULES  497
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  953

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   469


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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    77,    77,    78,    82,    86,    89,    92,    95,    98,
     101,   104,   110,   111,   114,   121,   122,   126,   127,   131,
     138,   139,   143,   150,   155,   158,   161,   164,   167,   170,
     173,   178,   183,   187,   191,   195,   199,   203,   207,   211,
     215,   219,   223,   227,   231,   235,   239,   243,   247,   251,
     255,   259,   263,   267,   271,   275,   279,   283,   287,   293,
     293,   304,   304,   315,   318,   321,   330,   334,   341,   345,
     349,   353,   357,   361,   365,   369,   373,   376,   379,   382,
     385,   388,   391,   394,   397,   400,   403,   406,   409,   412,
     415,   418,   421,   424,   427,   430,   433,   436,   439,   442,
     445,   448,   451,   454,   457,   460,   463,   466,   469,   469,
     475,   478,   481,   485,   489,   493,   497,   501,   505,   509,
     513,   517,   520,   523,   526,   529,   532,   535,   538,   541,
     544,   547,   550,   553,   556,   559,   564,   564,   567,   570,
     573,   576,   579,   582,   586,   589,   592,   595,   599,   602,
     605,   608,   612,   615,   618,   621,   627,   630,   633,   636,
     639,   644,   645,   648,   651,   656,   659,   664,   665,   668,
     671,   676,   679,   684,   685,   688,   691,   694,   699,   702,
     705,   710,   711,   714,   715,   716,   719,   722,   725,   730,
     733,   736,   742,   743,   746,   749,   752,   755,   758,   761,
     764,   767,   770,   773,   776,   779,   782,   785,   788,   793,
     796,   799,   802,   805,   808,   811,   814,   817,   820,   823,
     826,   829,   832,   835,   840,   841,   844,   847,   850,   853,
     856,   862,   865,   871,   872,   875,   880,   885,   886,   889,
     892,   897,   900,   905,   906,   909,   914,   919,   920,   923,
     926,   929,   934,   937,   943,   944,   947,   950,   953,   956,
     959,   964,   967,   970,   975,   976,   978,   979,   982,   985,
     988,   993,  1000,  1003,  1009,  1012,  1018,  1021,  1027,  1032,
    1033,  1036,  1041,  1045,  1045,  1050,  1054,  1054,  1059,  1063,
    1063,  1068,  1068,  1071,  1071,  1074,  1074,  1079,  1082,  1085,
    1090,  1093,  1099,  1103,  1110,  1113,  1116,  1119,  1122,  1125,
    1128,  1131,  1134,  1137,  1142,  1142,  1150,  1150,  1158,  1158,
    1169,  1170,  1174,  1178,  1185,  1190,  1195,  1200,  1205,  1210,
    1218,  1223,  1228,  1233,  1238,  1243,  1248,  1252,  1259,  1263,
    1270,  1273,  1277,  1280,  1280,  1284,  1284,  1290,  1293,  1299,
    1303,  1307,  1311,  1315,  1322,  1326,  1330,  1334,  1338,  1345,
    1351,  1354,  1357,  1363,  1366,  1369,  1375,  1378,  1381,  1384,
    1390,  1393,  1399,  1400,  1401,  1402,  1403,  1404,  1405,  1406,
    1407,  1408,  1409,  1410,  1411,  1412,  1413,  1414,  1415,  1416,
    1417,  1418,  1421,  1424,  1425,  1426,  1427,  1430,  1433,  1436,
    1439,  1442,  1445,  1448,  1451,  1454,  1457,  1460,  1463,  1466,
    1469,  1472,  1475,  1478,  1481,  1484,  1487,  1490,  1490,  1495,
    1498,  1501,  1504,  1507,  1510,  1513,  1516,  1519,  1522,  1525,
    1528,  1531,  1534,  1538,  1538,  1543,  1546,  1549,  1552,  1555,
    1558,  1562,  1566,  1570,  1570,  1575,  1575,  1580,  1580,  1585,
    1588,  1591,  1594,  1597,  1598,  1601,  1604,  1607,  1610,  1613,
    1616,  1617,  1618,  1619,  1620,  1623,  1626,  1629,  1632,  1635,
    1638,  1641,  1644,  1645,  1646,  1655,  1664,  1664,  1676,  1676,
    1693,  1693,  1710,  1713,  1714,  1718,  1719,  1719,  1723,  1723,
    1730,  1730,  1733,  1734,  1735,  1736,  1740,  1740
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
  "SEMICOLON", "COLON", "COMMA", "PLUS", "MINUS", "INC", "DEC", "EQUAL",
  "ASSIGN", "LT", "LTE", "GT", "GTE", "DISEQUAL", "MULTIPLICATION",
  "DOLLAR", "DIVISION", "QM", "RASTER", "DONE", "AT", "COLOR", "BORDER",
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
  "VAL", "STRING", "SPACE", "FLIP", "CHR", "ASC", "LEN", "POW", "MOD",
  "ADD", "MIN", "MAX", "SGN", "SIGNED", "ABS", "RND", "COLORS", "INK",
  "TIMER", "POWERING", "DIM", "ADDRESS", "PROC", "PROCEDURE", "CALL",
  "OSP", "CSP", "SHARED", "MILLISECOND", "MILLISECONDS", "TICKS", "GLOBAL",
  "PARAM", "PRINT", "DEFAULT", "SPECIFIC", "ANSI", "USE", "PAPER",
  "INVERSE", "REPLACE", "XOR", "IGNORE", "NORMAL", "WRITING", "ONLY",
  "LOCATE", "CLS", "HOME", "CMOVE", "CENTER", "CENTRE", "TAB", "SET",
  "CUP", "CDOWN", "CLEFT", "CRIGHT", "CLINE", "XCURS", "YCURS", "MEMORIZE",
  "REMEMBER", "HSCROLL", "VSCROLL", "BLACK", "WHITE", "RED", "CYAN",
  "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE", "BROWN", "LIGHT", "DARK",
  "GREY", "GRAY", "MAGENTA", "PURPLE", "LAVENDER", "GOLD", "TURQUOISE",
  "TAN", "PINK", "PEACH", "OLIVE", "Identifier", "String", "Integer",
  "\" \"", "$accept", "expr", "expr_math", "term", "modula", "factor",
  "direct_integer", "random_definition_simple", "random_definition",
  "color_enumeration", "exponential", "$@1", "$@2", "$@3", "position",
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
  "text_definition_simple", "text_definition_expression",
  "text_definition", "tiles_definition_simple",
  "tiles_definition_expression", "tiles_definition",
  "colormap_definition_simple", "colormap_definition_expression",
  "colormap_definition", "screen_definition_simple",
  "screen_definition_expression", "screen_definition",
  "var_definition_simple", "goto_definition", "gosub_definition",
  "var_definition", "point_definition_simple",
  "point_definition_expression", "point_definition", "ink_definition",
  "on_goto_definition", "$@4", "on_gosub_definition", "$@5",
  "on_proc_definition", "$@6", "on_definition", "$@7", "$@8", "$@9",
  "every_definition", "add_definition", "dimensions", "datatype",
  "dim_definition", "$@10", "$@11", "$@12", "dim_definitions", "indexes",
  "parameters", "parameters_expr", "values", "print_definition", "$@13",
  "$@14", "use_definition", "writing_mode_definition",
  "writing_part_definition", "writing_definition", "locate_definition",
  "cmove_definition", "hscroll_definition", "vscroll_definition",
  "statement", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21",
  "$@22", "statements_no_linenumbers", "$@23",
  "statements_with_linenumbers", "$@24", "statements_complex", "$@25",
  "program", "$@26", YY_NULLPTR
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
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469
};
#endif

#define YYPACT_NINF (-816)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-477)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -816,    76,   909,  -816,  -816,  -174,  -157,  2630,   -19,  -816,
     118,  2233,    56,    30,  2233,  -816,    27,   190,  2630,  -125,
      -9,  -816,  -816,  -816,  1849,    71,    37,  2630,  2630,    19,
     -41,  -816,    81,   107,  2630,  2630,  -816,   139,   147,    59,
    2630,    31,   115,  -816,   -43,  -816,  2630,     4,  2041,   164,
      36,  2630,    48,   102,   104,   129,     8,     8,  2630,    93,
    2630,   235,    46,  1258,  -816,  -816,  1465,  2630,  2630,    52,
    -816,  -816,  -816,  -816,  2630,  -816,  -816,    39,   188,    10,
    -816,   238,   284,   288,  -816,  -816,  -816,    95,   309,  1657,
    -816,  -816,   306,   307,   308,   137,  -816,  -816,     9,   310,
     311,  2630,  -816,  -816,   312,   315,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,  -816,  -816,   348,    54,   -44,    16,   324,   364,   365,
     366,   367,   368,   369,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,   197,  -816,  -816,    97,    77,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,   198,    11,  -816,
    -816,   268,    83,   262,   263,   264,  -816,  -816,  -816,  2233,
     370,  -816,  -816,  -816,  2233,  2233,  2233,  -816,  -816,  -816,
     179,   -32,   -12,  -816,  -816,  -816,   -15,   313,   -13,   -10,
      -6,    -3,   372,  -816,  -816,  -816,   228,   243,  -816,  -816,
    -816,  2233,  -816,  -816,   371,  -816,  -816,  -816,  -816,  -816,
    2233,   351,   352,  -816,  -816,  -816,   -16,  -816,    50,  -816,
    -816,  -816,  -816,  -816,  2630,  2438,  -816,  -816,   393,  -816,
    -816,  -816,  2233,  -816,  -816,  -816,  2233,   373,  -816,  -816,
    -816,   332,  -816,  -816,  -816,   256,  2630,  2630,  -816,  -816,
    2233,  -816,  -816,  -816,   374,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  2630,  2630,  -816,  -816,  -816,  -816,   392,
    -816,  -816,   253,  -816,  2630,   400,  -816,  -816,  -816,    51,
     401,  -816,   265,   266,   267,    65,   403,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,   404,  -816,  2630,   409,  -816,  2630,   410,  -816,  -816,
    -816,  2630,  -816,   207,  -816,  -816,  -816,   213,  -816,  -816,
    -816,  2630,   406,  -816,  -816,   385,    47,  1101,  -816,   909,
     909,  -816,   386,   390,   391,   394,   395,   396,   162,   397,
    2233,  2233,  2233,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,   387,  -816,  -816,  2630,  2630,  -816,  2630,  2630,
    2630,  2630,  2630,  2630,  2630,  2630,  2630,  2630,  2630,  2630,
    2630,  2630,  2630,  2630,  2630,  2822,   399,   217,  -816,  -816,
     402,  -816,  -816,   405,   407,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,   408,  -816,
     411,    84,   258,  2822,  2822,  2822,  2822,  2822,  2822,  2822,
    2822,  2822,  2822,  2822,  2822,  2822,  3014,   414,   417,  2233,
    -816,  -816,   362,   375,   376,   378,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  2233,   413,  -816,  -816,
    -816,   412,   313,   416,   313,   427,   313,   428,   313,   429,
     313,  -816,  2630,   421,  -816,  -816,   254,   259,   133,   151,
    -816,  -816,  -816,   422,   313,   424,  -816,  -816,   261,   274,
     161,   200,  -816,  -816,   425,  -816,  -816,  2233,  -816,  -816,
    2233,  2233,  -816,  -816,  -816,   419,   245,  -816,   432,  2630,
    -816,  -816,  -816,  -816,  2233,  -816,  2630,   456,   457,  -816,
    -816,  2233,   418,   458,  2630,   363,   460,  2630,  -816,  -816,
    -816,  -816,  -816,  -816,   174,  -816,  -816,   434,   452,    48,
    -816,   327,  -816,     8,   469,    47,     8,   -30,  -816,  2630,
    -816,  2630,  -816,  -816,  -816,  -816,  -816,   909,  -816,  2630,
     442,  2630,  2630,   443,    12,  -816,  1101,  -816,  -816,  2630,
     270,   271,   273,   277,   278,   444,   459,   462,  -816,   465,
     466,   467,   468,   470,   471,  2630,   472,   485,   486,   489,
     473,   474,   475,   476,   498,   477,   478,   479,   480,   481,
     501,   511,   483,   484,   487,    35,   314,   490,  2630,  2630,
    2630,   492,  2630,  2630,  2630,  2630,   262,   262,   328,   328,
     328,   328,   328,   328,   328,   328,   263,   264,   264,  -816,
     317,   318,  -816,  -816,  2630,   313,  2630,   313,   491,   500,
    2233,    33,  -816,   313,  -816,   313,  -816,   313,  -816,   313,
     144,  -816,  2630,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  2630,  -816,   313,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,   313,  -816,  -816,  -816,  -816,  -816,  -816,   320,
     322,   325,   326,   522,  2630,   531,   496,   497,   398,  2630,
    2630,   534,   536,  -816,   -59,   482,   349,  2630,   539,  -816,
    -816,  -816,   513,   350,   514,  -816,  2630,   353,  2630,  -816,
       8,   544,  -816,   384,   388,  -816,  -816,  -816,  -816,  -816,
    -816,  2630,   546,   420,   547,   521,  2630,  -816,   552,  -816,
    -816,  -816,  -816,  -816,   354,   355,   357,  -816,  -816,  -816,
    -816,  -816,  -816,   525,  2630,  2630,  2630,  2630,  -816,  -816,
    -816,  -816,  2630,  -816,  -816,  -816,  -816,  -816,  2630,  2630,
    -816,  -816,  -816,  3014,   526,  -816,   529,   559,   564,  2630,
     423,   537,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
     381,   382,  -816,  -816,  -816,  -816,  -816,  -816,   545,  -816,
     548,  -816,   383,    99,  -816,   567,  -816,   569,   570,  -816,
     572,  -816,   573,  -816,   571,  2233,   579,  2630,  2630,   313,
    -816,   558,   560,  2630,   313,  -816,  -816,  2630,  -816,   146,
    2630,   350,   590,   562,   350,   450,   131,   451,   453,  -816,
       8,  -816,  -816,   565,  2630,  -816,  2630,   591,   574,  2630,
    -816,  -816,  -816,  -816,   575,   576,   149,   150,   578,   580,
     581,   582,  -816,  -816,  2630,  2630,   583,  -816,  -816,  -816,
    -816,   415,   426,  -816,   585,  -816,   592,  -816,  2630,   313,
     596,   598,   599,  2630,  -816,  -816,  2630,  -816,  -816,  -816,
     595,   607,   587,   588,   505,  2630,   613,   555,   593,   350,
    -816,   594,  -816,   353,   624,    47,  -816,  -816,  -816,   619,
    -816,  -816,  2630,   620,   600,  -816,  -816,  2630,  -816,  2630,
    -816,  -816,  -816,  -816,  -816,   601,   603,  -816,  -816,  -816,
     430,   431,   604,   605,   320,   322,   325,  -816,  -816,  2630,
    2630,  -816,  -816,  2630,   608,  2630,  2630,  -816,  -816,  -816,
    -816,   353,   638,  2630,  -816,  2630,  -816,   610,   611,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,   635,  -816,  -816,  -816,   353,  -816,  -816,  -816,  -816,
    2630,  -816,  -816
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     496,     0,   484,     1,   483,     0,     0,     0,     0,   467,
       0,     0,   431,     0,     0,   458,     0,     0,     0,   266,
       0,   416,   420,   417,     0,     0,     0,     0,     0,     0,
     459,   414,     0,     0,     0,   409,   457,     0,     0,     0,
     464,   466,   412,   415,   422,   419,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   405,   406,     0,     0,     0,     0,
     396,   397,   398,   399,   400,   391,   392,     0,     0,   480,
     488,   485,   492,   494,   497,   407,   408,     0,     0,     0,
      79,    80,     0,     0,     0,     0,   121,   122,     0,     0,
       0,     0,   112,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,    44,    49,
      50,    51,    52,    53,    54,    57,    58,     0,    63,    67,
      65,   340,     2,    12,    15,    17,    76,    20,   389,     0,
       0,   167,   168,   373,     0,     0,     0,   181,   182,   375,
       0,     0,     0,   192,   193,   376,     0,     0,     0,     0,
       0,     0,     0,   161,   162,   372,     0,     0,   224,   225,
     377,     0,   227,   228,   229,   233,   234,   378,   256,   257,
       0,     0,     0,   264,   265,   383,     0,   460,     0,   276,
     386,   272,   273,   461,     0,     0,   239,   240,     0,   243,
     244,   380,     0,   247,   248,   381,     0,   250,   254,   255,
     382,     0,   449,   455,   456,   437,     0,     0,   482,   410,
       0,   237,   238,   379,     0,   279,   280,   384,   274,   275,
     462,   465,   424,     0,     0,   423,   426,   427,   421,     0,
     298,   299,     0,   463,     0,     0,   387,   281,   385,   314,
     320,   472,   441,   432,   442,   330,   336,   435,   436,   388,
     348,   347,   473,   450,   451,   452,   352,   350,   349,   351,
     353,     0,   453,     0,     0,   390,     0,     0,   395,   403,
     404,     0,   401,     0,   366,   368,   393,     0,   394,   490,
     454,     0,   478,   443,   440,     0,     0,   484,   486,   484,
     484,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,    24,    25,    27,    29,    30,    26,
      31,   101,     0,   115,   116,     0,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   120,
       0,   118,   119,     0,     0,   133,   127,   128,   129,   130,
      55,    42,    45,    46,    47,    48,    43,    56,    64,   108,
       0,   345,   343,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     178,   175,     0,     0,     0,     0,    23,   183,   189,   184,
     185,   190,   191,   186,   187,   188,     0,     0,   173,   174,
     374,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,   214,   215,     0,     0,     0,     0,
     211,   210,   136,     0,     0,     0,   199,   200,     0,     0,
       0,     0,   196,   195,     0,   231,   226,     0,   261,   258,
       0,     0,   291,   295,   293,     0,     0,   418,     0,     0,
     246,   245,   252,   249,     0,   411,     0,     0,     0,   236,
     235,     0,     0,   425,     0,     0,     0,     0,   312,   304,
     306,   311,   308,   313,     0,   310,   318,     0,     0,     0,
     445,     0,   447,     0,   331,     0,     0,     0,   360,   361,
     363,   364,   402,   367,   369,   370,   371,   484,   474,     0,
       0,     0,     0,     0,   480,   489,   484,   493,   495,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,     5,     7,
       8,     9,    10,     6,     3,     4,    16,    18,    19,    21,
       0,     0,   165,   163,     0,     0,     0,     0,     0,     0,
       0,     0,   143,     0,   155,     0,   147,     0,   151,     0,
     139,   212,     0,   219,   218,   223,   222,   217,   221,   216,
     220,     0,   197,     0,   204,   203,   208,   207,   202,   206,
     201,   205,     0,   232,   230,   262,   259,   263,   260,     0,
       0,     0,     0,   267,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   413,     0,     0,     0,     0,   300,   305,
     307,   309,     0,     0,     0,   321,     0,     0,     0,   333,
       0,   332,   337,   357,   355,   354,   359,   362,   365,   491,
     475,     0,   338,     0,   322,     0,     0,   487,     0,    75,
      68,    70,    74,    72,     0,     0,     0,    78,    77,    82,
      81,    84,    83,     0,     0,     0,     0,     0,    91,    92,
      93,   100,     0,    94,    95,    96,    97,    98,     0,     0,
     110,   111,   102,     0,     0,   106,     0,     0,     0,     0,
       0,     0,   346,   344,   166,   164,   180,   177,   179,   176,
       0,     0,   171,   169,   140,   153,   145,   148,   142,   154,
     146,   150,     0,     0,   209,     0,   194,     0,   282,   292,
     285,   296,   288,   294,   268,     0,     0,     0,     0,     0,
     438,     0,     0,     0,     0,   428,   429,     0,   297,     0,
       0,     0,   302,     0,     0,     0,   324,     0,     0,   334,
       0,   358,   356,     0,     0,   444,     0,     0,     0,     0,
      69,    71,    73,   124,     0,     0,     0,     0,     0,     0,
       0,     0,   107,   125,     0,     0,     0,   109,    60,   172,
     170,     0,     0,   156,   141,   152,   144,   149,     0,     0,
       0,     0,     0,     0,   270,   269,     0,   242,   253,   251,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
     315,     0,   446,     0,   325,     0,   434,   448,   335,     0,
     339,   323,     0,     0,     0,    85,    86,     0,    87,     0,
      89,    99,   105,   104,    22,     0,     0,    62,   158,   160,
       0,     0,     0,     0,     0,     0,     0,   271,   241,     0,
       0,   278,   277,     0,     0,     0,     0,   319,   303,   317,
     327,     0,   326,     0,   477,     0,   131,     0,     0,   132,
     126,   157,   159,   213,   198,   284,   287,   290,   468,   469,
     439,     0,   470,   301,   328,     0,   479,   481,    88,    90,
       0,   329,   471
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -816,    -7,   -84,   -65,   236,  -268,   249,  -816,  -816,  -816,
    -413,  -816,  -816,  -816,   454,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,   493,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -254,  -816,  -253,  -816,  -252,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -726,  -325,  -816,  -816,  -816,  -816,   134,  -588,
    -815,   -55,  -583,   -50,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -314,  -816,  -816,  -816,  -295,  -816,  -816,
    -816
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   704,   162,   163,   164,   165,   182,   350,   351,   166,
     167,   400,   591,   592,   463,   193,   194,   195,   171,   172,
     173,   438,   439,   440,   177,   178,   179,   432,   183,   184,
     185,   198,   199,   200,   205,   206,   207,   251,   252,   253,
     229,   230,   231,   233,   234,   235,   238,   239,   240,   213,
     214,   215,   219,   223,   260,   220,   255,   256,   257,   278,
     779,   850,   781,   851,   783,   852,   217,   659,   661,   660,
     273,   276,   803,   516,   280,   517,   518,   682,   281,   705,
     807,   287,   703,   168,   595,   594,   292,   301,   696,   302,
     305,   308,   316,   318,    81,   224,   521,   541,   686,   688,
     325,   540,   326,    82,   546,    83,   327,    84,   537,     1,
       2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     161,   543,   288,   609,   181,   751,   169,   196,   289,   750,
     436,   216,   442,   545,   319,   444,   320,   228,   320,   446,
     241,   242,   448,   321,   180,   321,   264,   248,   249,   352,
     322,   398,   322,   261,   547,   548,   380,    85,   482,   268,
     180,   272,   743,   378,   277,  -476,   -59,  -476,   427,   428,
     244,   161,   201,   293,    86,   187,   304,   693,   920,   307,
     309,   310,   236,   188,   202,   203,   764,   312,   427,   433,
     485,  -316,   523,   508,   376,   868,     3,   508,   871,   186,
     189,   313,   339,   765,  -342,   524,   218,   483,  -342,   377,
    -342,   403,   404,   486,   357,   405,   232,   406,   407,   408,
     409,   410,   265,   805,   245,   808,   944,   585,   190,   191,
     243,   766,   767,   813,   525,   204,   246,   379,   818,   429,
     430,   431,   509,   510,   511,   237,   509,   510,   511,   484,
     951,   694,   844,   512,   314,   315,   695,   512,   873,   429,
     430,   434,   247,   918,   296,   174,   607,   608,   353,   845,
     175,   874,   297,   865,   795,   381,   887,   889,   323,   399,
     323,   836,   417,   343,   250,   416,   354,   420,   422,   424,
     266,   513,   254,   382,   772,   513,   262,   846,   847,   637,
     875,   411,   866,   514,   263,   888,   890,   514,   638,   412,
     176,   515,   170,   773,   475,   515,   437,   639,   443,   274,
     691,   445,   221,   478,   222,   447,   640,   648,   449,   298,
     299,   300,   344,   345,   346,   269,   649,   487,   488,   285,
     286,   347,   348,   349,   324,   490,   324,   311,   881,   492,
     317,   880,   707,   208,   209,   210,   211,   555,   556,   497,
     498,   192,   699,   499,   328,   212,   650,   275,   557,   679,
     680,   290,   291,   451,   452,   651,   502,   503,  -341,   279,
     681,   453,  -341,   197,  -341,   454,   455,   506,   451,   464,
     258,   395,   259,   401,   456,   402,   465,   396,   294,   295,
     466,   467,   414,   457,   415,   458,   459,   391,   329,   468,
     392,   393,   330,   267,   460,   461,   528,   394,   469,   530,
     470,   471,   533,   534,   532,   462,   535,   536,   331,   472,
     473,   633,   634,   282,   538,   283,   635,   636,   644,   645,
     462,   598,   599,   600,   601,   602,   603,   604,   605,   332,
     831,   646,   647,   559,   561,   563,   403,   404,   596,   597,
     284,   340,   341,   342,   383,   355,   356,   358,   566,   567,
     359,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   384,   385,   386,   387,   388,   389,
     390,   397,   426,   413,   416,   419,   180,   450,   480,   481,
     489,   477,   495,   494,   496,   504,   505,   507,   519,   501,
     526,   527,   612,   520,  -433,   522,   529,   531,   418,   539,
     542,   549,   565,   421,   423,   425,   550,   551,   587,   618,
     552,   553,   554,   558,   586,   614,   441,   588,   620,   664,
     589,   623,   590,   -61,   610,   631,   593,   611,   615,   616,
     476,   617,   625,   627,   629,   632,   663,   641,   643,   479,
     652,   621,   662,   669,   670,   674,   676,   677,   689,   683,
     653,   692,   684,   655,   657,   687,   690,   701,   706,   724,
     714,   491,   665,   709,   710,   493,   711,   666,   673,   668,
     712,   713,   725,   726,   671,   715,   727,   675,   716,   500,
     678,   717,   718,   719,   720,   732,   721,   722,   738,   728,
     729,   730,   731,   733,   734,   735,   736,   737,   739,   740,
     741,   760,   697,   742,   698,   744,   745,   749,   754,   755,
     761,   778,   700,   780,   702,   785,   782,   784,   787,   788,
     789,   793,   708,   794,   752,   753,   800,   790,   801,   804,
     922,   810,   811,   814,   816,   797,   812,   817,   723,   819,
     798,   823,   832,   802,   806,   833,   834,   820,   821,   815,
     822,   835,   837,   838,   848,   841,   849,  -283,   842,  -286,
    -289,   746,   747,   748,   853,   702,   856,   161,   161,   560,
     562,   564,   839,   840,   860,   843,   861,   869,   870,   872,
     876,   879,   877,   904,   882,   905,   906,   756,   909,   758,
     883,   885,   886,   762,   891,   900,   892,   893,   894,   897,
     910,   913,   901,   911,   912,   774,   915,   898,   916,   917,
     919,   921,   923,   925,   775,   809,   926,   929,   899,   930,
     933,   934,   931,   932,   941,   945,   948,   949,   950,   606,
     935,   474,   936,   685,   937,     0,     0,   786,     0,     0,
       0,     0,   791,   792,     0,     0,     0,     0,   613,     0,
     799,     0,     0,     0,     0,   435,     0,     0,     0,   702,
       0,   702,     0,     0,     0,   619,     0,     0,     0,     0,
       0,   622,     0,   624,     0,   626,     0,   628,     0,   630,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   642,     0,     0,     0,   824,   825,   826,
     827,     0,     0,     0,     0,   828,   654,     0,     0,   656,
     658,   829,   830,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   667,     0,     0,     0,     0,     0,     0,
     672,     0,     0,     0,     0,   878,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   854,     0,
     857,   858,     0,     0,     0,     0,   862,     0,     0,     0,
     864,     0,     0,   867,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   702,     0,     0,
       0,     0,   884,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   895,   896,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   902,     0,     0,     0,     0,   907,     0,     0,   908,
       0,     0,     0,     0,     0,     0,     0,     0,   914,     0,
       0,     0,     0,     0,   757,     0,   759,     0,     0,   763,
       0,     0,   768,     0,   769,   924,   770,     0,   771,     0,
     927,     0,   928,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   776,     0,     0,     0,     0,     0,     0,     0,
       0,   777,   938,   939,     0,     0,   940,     0,   942,   943,
       0,     0,     4,     0,     0,     0,   946,     0,   947,     5,
       6,     0,     0,   796,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     9,     0,    10,     0,    11,    12,     0,
      13,    14,     0,   952,     0,     0,     0,     0,    15,     0,
      16,    17,    18,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,    21,    22,
      23,    24,    25,    26,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,    29,    30,
       0,    31,     0,     0,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,     0,    42,     0,     0,     0,
      43,    44,    45,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,     0,   855,     0,     0,     0,   859,     0,
       0,    50,     0,   863,     0,     0,     0,     0,     0,    51,
       0,     0,    52,     0,    53,    54,    55,     0,     0,    56,
       0,     0,     0,    57,     0,    58,     0,     0,     0,    59,
      60,    61,     0,     0,     0,     0,    62,     0,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,     0,     0,    75,    76,    77,    78,     0,   903,     0,
       0,     0,     0,     0,     4,     0,     0,     0,     0,     0,
       0,     5,     6,     0,     0,     0,     0,     0,     0,     0,
      79,     0,    80,     7,     8,     9,     0,    10,     0,    11,
      12,     0,    13,    14,     0,     0,     0,     0,     0,     0,
      15,     0,    16,    17,    18,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
      21,    22,    23,    24,    25,    26,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
      29,    30,     0,    31,     0,     0,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,     0,    42,     0,
       0,     0,    43,    44,    45,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,    52,     0,    53,    54,    55,     0,
       0,    56,     0,     0,     0,    57,     0,    58,     0,     0,
       0,    59,    60,    61,     0,   303,     0,    87,    62,     0,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    88,     0,    75,    76,    77,    78,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,   544,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,     0,     0,    94,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,     0,    98,     0,     0,     0,     0,
       0,     0,     0,    99,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,   116,   117,   118,     0,   119,   120,   121,     0,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,   125,     0,     0,     0,   126,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
     128,     0,     0,   129,     0,   130,   131,   132,   133,     0,
     134,   135,     0,     0,     0,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,     0,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   306,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,    94,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,     0,    98,     0,     0,     0,     0,     0,     0,     0,
      99,   100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,     0,     0,     0,   116,   117,
     118,     0,   119,   120,   121,     0,   122,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,     0,   125,     0,     0,     0,   126,     0,     0,     0,
       0,     0,     0,     0,   127,     0,     0,   128,     0,     0,
     129,     0,   130,   131,   132,   133,     0,   134,   135,     0,
       0,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    87,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,    88,   333,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,    94,     0,
       0,    95,   334,   335,   336,     0,     0,     0,     0,     0,
       0,    96,    97,   337,    98,     0,     0,     0,     0,     0,
       0,     0,    99,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,     0,     0,     0,
     116,   117,   118,   338,   119,   120,   121,     0,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,     0,   125,     0,     0,     0,   126,     0,
       0,     0,     0,     0,     0,     0,   127,     0,     0,   128,
       0,     0,   129,     0,   130,   131,   132,   133,     0,   134,
     135,     0,     0,     0,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    87,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,   225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,     0,   226,   227,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,     0,     0,
      94,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,     0,    98,     0,     0,     0,
       0,     0,     0,     0,    99,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,     0,
       0,     0,   116,   117,   118,     0,   119,   120,   121,     0,
     122,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,     0,   125,     0,     0,     0,
     126,     0,     0,     0,     0,     0,     0,     0,   127,     0,
       0,   128,     0,     0,   129,     0,   130,   131,   132,   133,
       0,   134,   135,     0,     0,     0,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
      87,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,   270,   271,     0,     0,     0,     0,
       0,     0,    90,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
       0,     0,    94,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,     0,    98,     0,
       0,     0,     0,     0,     0,     0,    99,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     0,     0,     0,   116,   117,   118,     0,   119,   120,
     121,     0,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,     0,   125,     0,
       0,     0,   126,     0,     0,     0,     0,     0,     0,     0,
     127,     0,     0,   128,     0,     0,   129,     0,   130,   131,
     132,   133,     0,   134,   135,     0,     0,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,    87,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,    94,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,   180,    96,    97,     0,
      98,     0,     0,     0,     0,     0,     0,     0,    99,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,     0,     0,   116,   117,   118,     0,
     119,   120,   121,     0,   122,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,     0,
     125,     0,     0,     0,   126,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,   128,     0,     0,   129,     0,
     130,   131,   132,   133,     0,   134,   135,     0,     0,     0,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,    87,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   332,     0,
       0,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,     0,     0,    94,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,     0,    98,     0,     0,     0,     0,
       0,     0,     0,    99,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,   116,   117,   118,     0,   119,   120,   121,     0,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,   125,     0,     0,     0,   126,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
     128,     0,     0,   129,     0,   130,   131,   132,   133,     0,
     134,   135,     0,     0,     0,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,    87,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,     0,     0,     0,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,     0,
       0,    94,     0,     0,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,     0,    98,     0,     0,
       0,     0,     0,     0,     0,    99,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,     0,     0,   116,   117,   118,     0,   119,   120,   121,
       0,   122,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,     0,   125,     0,     0,
       0,   126,     0,     0,     0,     0,     0,     0,     0,   127,
       0,     0,   128,     0,     0,   129,     0,   130,   131,   132,
     133,     0,   134,   135,     0,     0,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,    87,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,     0,     0,     0,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,    94,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,     0,    98,
       0,     0,     0,     0,     0,     0,     0,    99,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   102,   103,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,     0,     0,   116,   117,   118,     0,   119,
     120,   121,     0,   122,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,     0,   125,
       0,     0,     0,   126,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,   128,     0,     0,   129,     0,   130,
     131,   132,   133,     0,   134,   135,     0,     0,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,    87,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,    94,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
       0,    98,     0,     0,     0,     0,     0,     0,     0,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,   103,     0,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,     0,     0,   116,   117,   118,
       0,   119,   120,   121,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
       0,   125,     0,     0,     0,   126,     0,     0,     0,     0,
       0,     0,     0,   127,     0,     0,   128,     0,     0,   129,
       0,   130,   131,   132,   133,     0,   134,   135,     0,     0,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,     0,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160
};

static const yytype_int16 yycheck[] =
{
       7,   326,    57,   416,    11,   593,    25,    14,    58,   592,
      25,    18,    25,   327,     4,    25,     6,    24,     6,    25,
      27,    28,    25,    13,    83,    13,    69,    34,    35,    20,
      20,    20,    20,    40,   329,   330,    20,   211,    54,    46,
      83,    48,     7,    87,    51,    35,    35,    35,    80,    81,
      91,    58,    25,    60,   211,    25,    63,    87,   873,    66,
      67,    68,    25,    33,    37,    38,    33,    74,    80,    81,
      20,    20,     7,    26,    20,   801,     0,    26,   804,    23,
      50,    42,    89,    50,     0,    20,   211,   103,     4,    35,
       6,     8,     9,    43,   101,    12,    25,    14,    15,    16,
      17,    18,   145,   686,   145,   688,   921,   375,    78,    79,
      91,    78,    79,   701,    49,    88,    35,   161,   706,   151,
     152,   153,    75,    76,    77,    88,    75,    76,    77,   145,
     945,   161,    33,    86,    95,    96,   166,    86,     7,   151,
     152,   153,    35,   869,    98,    27,   414,   415,   139,    50,
      32,    20,   106,     7,   213,   139,     7,     7,   148,   148,
     148,   749,   169,    26,    25,   130,   157,   174,   175,   176,
     213,   124,    25,   157,    30,   124,   145,    78,    79,    46,
      49,    98,    36,   136,    69,    36,    36,   136,    55,   106,
      72,   144,   211,    49,   201,   144,   211,    46,   211,    35,
     525,   211,   211,   210,   213,   211,    55,    46,   211,   163,
     164,   165,    75,    76,    77,   211,    55,   224,   225,   211,
     212,    84,    85,    86,   214,   232,   214,   175,   816,   236,
      42,   814,   546,    43,    44,    45,    46,    75,    76,   246,
     247,   211,   537,   250,     6,    55,    46,   211,    86,    75,
      76,   158,   159,    25,    26,    55,   263,   264,     0,   211,
      86,    33,     4,    14,     6,    37,    38,   274,    25,    26,
     211,   194,   213,     5,    46,     7,    33,   200,    43,    44,
      37,    38,    19,    55,    21,    57,    58,   190,     4,    46,
     193,   194,     4,    44,    66,    67,   303,   200,    55,   306,
      57,    58,    95,    96,   311,    77,    93,    94,   213,    66,
      67,    57,    58,   211,   321,   211,    57,    58,    57,    58,
      77,   405,   406,   407,   408,   409,   410,   411,   412,    20,
     743,    57,    58,   340,   341,   342,     8,     9,   403,   404,
     211,    35,    35,    35,    20,    35,    35,    35,   355,   356,
      35,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    20,    20,    20,    20,    20,    20,
     193,   193,   213,   131,   130,    25,    83,    25,    47,    47,
       7,    30,    70,    30,   148,    13,   153,     7,     7,    35,
       7,     7,   419,   148,   148,   148,     7,     7,   169,    13,
      35,    35,    35,   174,   175,   176,    36,    36,   211,   436,
      36,    36,    36,    36,    35,    73,   187,    35,    25,     7,
      35,    25,    35,    35,    30,   452,    35,    30,    73,    73,
     201,    73,    25,    25,    25,    34,   211,    35,    34,   210,
      35,    49,    43,     7,     7,     7,   103,     7,   523,    35,
     477,   526,    20,   480,   481,   148,     7,    35,    35,     7,
      36,   232,   489,   213,   213,   236,   213,   494,    70,   496,
     213,   213,     7,     7,   501,    36,     7,   504,    36,   250,
     507,    36,    36,    36,    36,     7,    36,    36,     7,    36,
      36,    36,    36,    36,    36,    36,    36,    36,     7,    36,
      36,    30,   529,    36,   531,   211,    36,    35,   211,   211,
      30,   211,   539,   211,   541,    13,   211,   211,     7,    43,
      43,     7,   549,     7,   594,   595,     7,   149,    35,    35,
     875,     7,   168,     7,     7,    73,   168,    36,   565,     7,
     211,    36,    36,   213,   211,    36,     7,   213,   213,   149,
     213,     7,   149,    36,     7,    30,     7,     7,    30,     7,
       7,   588,   589,   590,    13,   592,     7,   594,   595,   340,
     341,   342,   211,   211,    36,   212,    36,     7,    36,   149,
     149,    36,   149,     7,    13,     7,     7,   614,    13,   616,
      36,    36,    36,   620,    36,    30,    36,    36,    36,    36,
      13,   116,    30,    36,    36,   632,    13,   212,    73,    36,
      36,     7,    13,    13,   641,   690,    36,    36,   212,    36,
      36,    36,   212,   212,    36,     7,    36,    36,    13,   413,
     904,   197,   905,   519,   906,    -1,    -1,   664,    -1,    -1,
      -1,    -1,   669,   670,    -1,    -1,    -1,    -1,   419,    -1,
     677,    -1,    -1,    -1,    -1,   182,    -1,    -1,    -1,   686,
      -1,   688,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,   442,    -1,   444,    -1,   446,    -1,   448,    -1,   450,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   464,    -1,    -1,    -1,   724,   725,   726,
     727,    -1,    -1,    -1,    -1,   732,   477,    -1,    -1,   480,
     481,   738,   739,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   494,    -1,    -1,    -1,    -1,    -1,    -1,
     501,    -1,    -1,    -1,    -1,   810,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   785,    -1,
     787,   788,    -1,    -1,    -1,    -1,   793,    -1,    -1,    -1,
     797,    -1,    -1,   800,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   814,    -1,    -1,
      -1,    -1,   819,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   834,   835,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   848,    -1,    -1,    -1,    -1,   853,    -1,    -1,   856,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   865,    -1,
      -1,    -1,    -1,    -1,   615,    -1,   617,    -1,    -1,   620,
      -1,    -1,   623,    -1,   625,   882,   627,    -1,   629,    -1,
     887,    -1,   889,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   643,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   652,   909,   910,    -1,    -1,   913,    -1,   915,   916,
      -1,    -1,     3,    -1,    -1,    -1,   923,    -1,   925,    10,
      11,    -1,    -1,   674,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    -1,    26,    -1,    28,    29,    -1,
      31,    32,    -1,   950,    -1,    -1,    -1,    -1,    39,    -1,
      41,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    89,    90,
      -1,    92,    -1,    -1,    95,    96,    97,    -1,    99,   100,
     101,   102,   103,   104,   105,    -1,   107,    -1,    -1,    -1,
     111,   112,   113,   114,   115,    -1,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,   785,    -1,    -1,    -1,   789,    -1,
      -1,   132,    -1,   794,    -1,    -1,    -1,    -1,    -1,   140,
      -1,    -1,   143,    -1,   145,   146,   147,    -1,    -1,   150,
      -1,    -1,    -1,   154,    -1,   156,    -1,    -1,    -1,   160,
     161,   162,    -1,    -1,    -1,    -1,   167,    -1,   169,   170,
     171,   172,   173,   174,    -1,   176,   177,   178,   179,   180,
     181,    -1,    -1,   184,   185,   186,   187,    -1,   849,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,    -1,   213,    22,    23,    24,    -1,    26,    -1,    28,
      29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    41,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      89,    90,    -1,    92,    -1,    -1,    95,    96,    97,    -1,
      99,   100,   101,   102,   103,   104,   105,    -1,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,    -1,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   140,    -1,    -1,   143,    -1,   145,   146,   147,    -1,
      -1,   150,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,
      -1,   160,   161,   162,    -1,     7,    -1,     9,   167,    -1,
     169,   170,   171,   172,   173,   174,    -1,   176,   177,   178,
     179,   180,   181,    25,    -1,   184,   185,   186,   187,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   155,    -1,   157,    -1,    -1,    -1,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,
     172,    -1,    -1,   175,    -1,   177,   178,   179,   180,    -1,
     182,   183,    -1,    -1,    -1,    -1,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     7,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    71,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    -1,    -1,    -1,   133,   134,
     135,    -1,   137,   138,   139,    -1,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,    -1,   157,    -1,    -1,    -1,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   169,    -1,    -1,   172,    -1,    -1,
     175,    -1,   177,   178,   179,   180,    -1,   182,   183,    -1,
      -1,    -1,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,     9,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    -1,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,   138,   139,    -1,   141,   142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,    -1,   157,    -1,    -1,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,   172,
      -1,    -1,   175,    -1,   177,   178,   179,   180,    -1,   182,
     183,    -1,    -1,    -1,    -1,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,     9,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      71,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,    -1,
      -1,    -1,   133,   134,   135,    -1,   137,   138,   139,    -1,
     141,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   155,    -1,   157,    -1,    -1,    -1,
     161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,
      -1,   172,    -1,    -1,   175,    -1,   177,   178,   179,   180,
      -1,   182,   183,    -1,    -1,    -1,    -1,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
       9,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    -1,    -1,    -1,   133,   134,   135,    -1,   137,   138,
     139,    -1,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,   157,    -1,
      -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,    -1,    -1,   172,    -1,    -1,   175,    -1,   177,   178,
     179,   180,    -1,   182,   183,    -1,    -1,    -1,    -1,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,     9,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,   133,   134,   135,    -1,
     137,   138,   139,    -1,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,
     157,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   169,    -1,    -1,   172,    -1,    -1,   175,    -1,
     177,   178,   179,   180,    -1,   182,   183,    -1,    -1,    -1,
      -1,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   155,    -1,   157,    -1,    -1,    -1,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,
     172,    -1,    -1,   175,    -1,   177,   178,   179,   180,    -1,
     182,   183,    -1,    -1,    -1,    -1,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,     9,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    71,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      -1,    -1,    -1,   133,   134,   135,    -1,   137,   138,   139,
      -1,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   155,    -1,   157,    -1,    -1,
      -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,
      -1,    -1,   172,    -1,    -1,   175,    -1,   177,   178,   179,
     180,    -1,   182,   183,    -1,    -1,    -1,    -1,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,     9,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,    -1,    -1,   133,   134,   135,    -1,   137,
     138,   139,    -1,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,   157,
      -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   169,    -1,    -1,   172,    -1,    -1,   175,    -1,   177,
     178,   179,   180,    -1,   182,   183,    -1,    -1,    -1,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,     9,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,    -1,    -1,   133,   134,   135,
      -1,   137,   138,   139,    -1,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
      -1,   157,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   169,    -1,    -1,   172,    -1,    -1,   175,
      -1,   177,   178,   179,   180,    -1,   182,   183,    -1,    -1,
      -1,    -1,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   324,   325,     0,     3,    10,    11,    22,    23,    24,
      26,    28,    29,    31,    32,    39,    41,    42,    43,    48,
      54,    59,    60,    61,    62,    63,    64,    69,    87,    89,
      90,    92,    95,    96,    97,    99,   100,   101,   102,   103,
     104,   105,   107,   111,   112,   113,   114,   115,   117,   118,
     132,   140,   143,   145,   146,   147,   150,   154,   156,   160,
     161,   162,   167,   169,   170,   171,   172,   173,   174,   176,
     177,   178,   179,   180,   181,   184,   185,   186,   187,   211,
     213,   309,   318,   320,   322,   211,   211,     9,    25,    35,
      51,    52,    53,    68,    71,    74,    84,    85,    87,    95,
      96,   108,   109,   110,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   133,   134,   135,   137,
     138,   139,   141,   142,   155,   157,   161,   169,   172,   175,
     177,   178,   179,   180,   182,   183,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   216,   217,   218,   219,   220,   224,   225,   298,    25,
     211,   233,   234,   235,    27,    32,    72,   239,   240,   241,
      83,   216,   221,   243,   244,   245,    23,    25,    33,    50,
      78,    79,   211,   230,   231,   232,   216,   221,   246,   247,
     248,    25,    37,    38,    88,   249,   250,   251,    43,    44,
      45,    46,    55,   264,   265,   266,   216,   281,   211,   267,
     270,   211,   213,   268,   310,    25,    37,    38,   216,   255,
     256,   257,    25,   258,   259,   260,    25,    88,   261,   262,
     263,   216,   216,    91,    91,   145,    35,    35,   216,   216,
      25,   252,   253,   254,    25,   271,   272,   273,   211,   213,
     269,   216,   145,    69,    69,   145,   213,   221,   216,   211,
      43,    44,   216,   285,    35,   211,   286,   216,   274,   211,
     289,   293,   211,   211,   211,   211,   212,   296,   296,   298,
     158,   159,   301,   216,    43,    44,    98,   106,   163,   164,
     165,   302,   304,     7,   216,   305,     7,   216,   306,   216,
     216,   175,   216,    42,    95,    96,   307,    42,   308,     4,
       6,    13,    20,   148,   214,   315,   317,   321,     6,     4,
       4,   213,    20,    26,    75,    76,    77,    86,   136,   216,
      35,    35,    35,    26,    75,    76,    77,    84,    85,    86,
     222,   223,    20,   139,   157,    35,    35,   216,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    20,    35,    87,   161,
      20,   139,   157,    20,    20,    20,    20,    20,    20,    20,
     193,   190,   193,   194,   200,   194,   200,   193,    20,   148,
     226,     5,     7,     8,     9,    12,    14,    15,    16,    17,
      18,    98,   106,   131,    19,    21,   130,   216,   221,    25,
     216,   221,   216,   221,   216,   221,   213,    80,    81,   151,
     152,   153,   242,    81,   153,   242,    25,   211,   236,   237,
     238,   221,    25,   211,    25,   211,    25,   211,    25,   211,
      25,    25,    26,    33,    37,    38,    46,    55,    57,    58,
      66,    67,    77,   229,    26,    33,    37,    38,    46,    55,
      57,    58,    66,    67,   229,   216,   221,    30,   216,   221,
      47,    47,    54,   103,   145,    20,    43,   216,   216,     7,
     216,   221,   216,   221,    30,    70,   148,   216,   216,   216,
     221,    35,   216,   216,    13,   153,   216,     7,    26,    75,
      76,    77,    86,   124,   136,   144,   288,   290,   291,     7,
     148,   311,   148,     7,    20,    49,     7,     7,   216,     7,
     216,     7,   216,    95,    96,    93,    94,   323,   216,    13,
     316,   312,    35,   288,   211,   318,   319,   322,   322,    35,
      36,    36,    36,    36,    36,    75,    76,    86,    36,   216,
     221,   216,   221,   216,   221,    35,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   220,    35,   211,    35,    35,
      35,   227,   228,    35,   300,   299,   218,   218,   217,   217,
     217,   217,   217,   217,   217,   217,   219,   220,   220,   225,
      30,    30,   216,   221,    73,    73,    73,    73,   216,   221,
      25,    49,   221,    25,   221,    25,   221,    25,   221,    25,
     221,   216,    34,    57,    58,    57,    58,    46,    55,    46,
      55,    35,   221,    34,    57,    58,    57,    58,    46,    55,
      46,    55,    35,   216,   221,   216,   221,   216,   221,   282,
     284,   283,    43,   211,     7,   216,   216,   221,   216,     7,
       7,   216,   221,    70,     7,   216,   103,     7,   216,    75,
      76,    86,   292,    35,    20,   293,   313,   148,   314,   296,
       7,   288,   296,    87,   161,   166,   303,   216,   216,   322,
     216,    35,   216,   297,   216,   294,    35,   318,   216,   213,
     213,   213,   213,   213,    36,    36,    36,    36,    36,    36,
      36,    36,    36,   216,     7,     7,     7,     7,    36,    36,
      36,    36,     7,    36,    36,    36,    36,    36,     7,     7,
      36,    36,    36,     7,   211,    36,   216,   216,   216,    35,
     297,   294,   298,   298,   211,   211,   216,   221,   216,   221,
      30,    30,   216,   221,    33,    50,    78,    79,   221,   221,
     221,   221,    30,    49,   216,   216,   221,   221,   211,   275,
     211,   277,   211,   279,   211,    13,   216,     7,    43,    43,
     149,   216,   216,     7,     7,   213,   221,    73,   211,   216,
       7,    35,   213,   287,    35,   297,   211,   295,   297,   296,
       7,   168,   168,   294,     7,   149,     7,    36,   294,     7,
     213,   213,   213,    36,   216,   216,   216,   216,   216,   216,
     216,   225,    36,    36,     7,     7,   294,   149,    36,   211,
     211,    30,    30,   212,    33,    50,    78,    79,     7,     7,
     276,   278,   280,    13,   216,   221,     7,   216,   216,   221,
      36,    36,   216,   221,   216,     7,    36,   216,   287,     7,
      36,   287,   149,     7,    20,    49,   149,   149,   296,    36,
     297,   294,    13,    36,   216,    36,    36,     7,    36,     7,
      36,    36,    36,    36,    36,   216,   216,    36,   212,   212,
      30,    30,   216,   221,     7,     7,     7,   216,   216,    13,
      13,    36,    36,   116,   216,    13,    73,    36,   287,    36,
     295,     7,   288,    13,   216,    13,    36,   216,   216,    36,
      36,   212,   212,    36,    36,   275,   277,   279,   216,   216,
     216,    36,   216,   216,   295,     7,   216,   216,    36,    36,
      13,   295,   216
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   215,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   217,   217,   217,   218,   218,   219,   219,   219,
     220,   220,   220,   221,   222,   222,   222,   222,   222,   222,
     222,   223,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   226,
     225,   227,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   228,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   229,   229,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   231,   231,   231,   231,
     231,   232,   232,   233,   233,   234,   234,   235,   235,   236,
     236,   237,   237,   238,   238,   239,   239,   239,   240,   240,
     240,   241,   241,   242,   242,   242,   243,   243,   243,   244,
     244,   244,   245,   245,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   248,   248,   249,   249,   249,   249,
     249,   250,   250,   251,   251,   252,   253,   254,   254,   255,
     255,   256,   256,   257,   257,   258,   259,   260,   260,   261,
     261,   261,   262,   262,   263,   263,   264,   264,   264,   264,
     264,   265,   265,   265,   266,   266,   267,   267,   267,   267,
     267,   267,   268,   268,   269,   269,   270,   271,   272,   273,
     273,   274,   275,   276,   275,   277,   278,   277,   279,   280,
     279,   282,   281,   283,   281,   284,   281,   285,   285,   285,
     286,   286,   287,   287,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   290,   289,   291,   289,   292,   289,
     293,   293,   294,   294,   295,   295,   295,   295,   295,   295,
     296,   296,   296,   296,   296,   296,   296,   296,   297,   297,
     298,   298,   298,   299,   298,   300,   298,   301,   301,   302,
     302,   302,   302,   302,   303,   303,   303,   303,   303,   304,
     305,   305,   305,   306,   306,   306,   307,   307,   307,   307,
     308,   308,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   310,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   311,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   312,   309,   313,   309,   314,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   315,   309,   316,   309,
     317,   309,   309,   309,   309,   318,   319,   318,   321,   320,
     323,   322,   322,   322,   322,   322,   325,   324
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     3,     3,     1,     3,     1,     3,     3,
       1,     3,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     0,
       5,     0,     6,     1,     2,     1,     2,     1,     4,     5,
       4,     5,     4,     5,     4,     4,     1,     4,     4,     1,
       1,     4,     4,     4,     4,     6,     6,     6,     8,     6,
       8,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     2,     4,     3,     6,     6,     4,     5,     0,     5,
       4,     4,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     5,     5,     7,     2,     2,     2,
       2,     7,     7,     2,     1,     1,     1,     1,     2,     3,
       4,     5,     4,     3,     5,     4,     4,     3,     4,     5,
       4,     3,     5,     4,     4,     3,     5,     7,     6,     7,
       6,     1,     1,     3,     4,     3,     4,     1,     1,     3,
       4,     3,     4,     1,     1,     2,     4,     4,     2,     4,
       4,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     1,     1,     4,     2,     2,     3,     7,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       2,     2,     3,     7,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     2,     1,     1,     1,
       3,     2,     3,     1,     1,     2,     2,     1,     1,     1,
       1,     6,     5,     1,     1,     2,     2,     1,     1,     2,
       1,     5,     2,     5,     1,     1,     1,     1,     2,     3,
       3,     2,     3,     3,     1,     1,     0,     3,     4,     5,
       5,     6,     1,     1,     1,     1,     1,     6,     6,     1,
       1,     1,     1,     0,     4,     1,     0,     4,     1,     0,
       4,     0,     4,     0,     4,     0,     4,     4,     1,     1,
       3,     7,     1,     3,     1,     2,     1,     2,     1,     2,
       1,     1,     1,     1,     0,     5,     0,     6,     0,     6,
       1,     3,     1,     3,     1,     2,     3,     3,     4,     5,
       1,     2,     3,     3,     4,     5,     1,     3,     1,     3,
       1,     2,     2,     0,     4,     0,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     3,
       2,     2,     3,     2,     2,     3,     1,     2,     1,     2,
       2,     2,     2,     2,     3,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     2,     3,     2,     2,     1,     1,     2,     2,     1,
       2,     3,     1,     4,     1,     1,     1,     0,     3,     1,
       1,     2,     1,     2,     2,     3,     2,     2,     5,     5,
       6,     1,     2,     0,     6,     2,     2,     2,     5,     8,
       2,     2,     2,     0,     5,     0,     6,     0,     6,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       2,     2,     2,     2,     1,     2,     1,     1,     8,     8,
       8,    10,     2,     2,     3,     4,     0,     7,     0,     8,
       0,     8,     2,     1,     0,     1,     0,     4,     0,     3,
       0,     4,     1,     3,     1,     3,     0,     2
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
  case 3: /* expr: expr_math AND expr_math  */
#line 78 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2956 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 82 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2965 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 86 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2973 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 89 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2981 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 92 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2989 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 95 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2997 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 98 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3005 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 101 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3013 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 104 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 3021 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 111 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3029 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 114 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3038 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 127 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3047 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 131 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3056 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 139 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 3065 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 143 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 3074 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 150 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3082 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 155 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3090 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 158 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3098 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 161 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3106 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 164 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3114 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 167 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3122 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 170 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3130 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 173 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3138 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 178 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3146 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 183 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3155 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 187 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3164 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 191 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3173 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 195 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3182 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 199 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3191 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 203 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3200 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 207 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3209 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 211 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3218 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 215 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3227 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 219 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3236 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 223 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3245 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 227 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3254 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 231 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3263 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 235 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3272 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 239 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3281 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 243 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3290 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 247 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3299 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 251 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3308 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 255 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3317 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 259 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3326 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 263 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3335 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 267 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3344 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 271 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3353 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 275 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3362 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 279 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3371 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 283 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3380 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 287 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3389 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 293 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3398 "src-generated/ugbc.tab.c"
    break;

  case 60: /* exponential: Identifier $@1 OP indexes CP  */
#line 297 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-4].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-4].string) )->name;
    }
#line 3410 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 304 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3419 "src-generated/ugbc.tab.c"
    break;

  case 62: /* exponential: Identifier DOLLAR $@2 OP indexes CP  */
#line 308 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-5].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-5].string) )->name;
    }
#line 3431 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 315 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3439 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 318 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3447 "src-generated/ugbc.tab.c"
    break;

  case 65: /* exponential: Integer  */
#line 321 "src/ugbc.y"
              { 
        if ( (yyvsp[0].integer) < 0 ) {
            (yyval.string) = variable_temporary( _environment, VT_SWORD, "(signed integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        } else {
            (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        }
      }
#line 3461 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 330 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3470 "src-generated/ugbc.tab.c"
    break;

  case 67: /* exponential: String  */
#line 334 "src/ugbc.y"
             { 
        outline1("; (expr string: \"%s\")", (yyvsp[0].string) );
        (yyval.string) = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", (yyval.string) );
        variable_store_string( _environment, (yyval.string), (yyvsp[0].string) );
        outline2("; variable stored: %s = %s", (yyval.string), (yyvsp[0].string) );
      }
#line 3482 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 341 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3491 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 345 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3500 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 349 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3509 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 353 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3518 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 357 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3527 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 361 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3536 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 365 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3545 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 369 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3554 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 373 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3562 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 376 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3570 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 379 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3578 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 382 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3586 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 385 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3594 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 388 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3602 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 391 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3610 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 394 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3618 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 397 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3626 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 400 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3634 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 403 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3642 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 406 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3650 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 409 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3658 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 412 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3666 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 415 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3674 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 418 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3682 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 421 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3690 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 424 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3698 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 427 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3706 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 430 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3714 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 433 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3722 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 436 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3730 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 439 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3738 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 442 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3746 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 445 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3754 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 448 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3762 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 451 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3770 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 454 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3778 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 457 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3786 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 460 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3794 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 463 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3802 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 466 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3810 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 469 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3818 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 471 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3827 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 475 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3835 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 478 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3843 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 481 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3852 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 485 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3861 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 489 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3870 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: PEN COLORS  */
#line 493 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3879 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: PEN DEFAULT  */
#line 497 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3888 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: DEFAULT PEN  */
#line 501 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3897 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: PAPER COLORS  */
#line 505 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3906 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: PAPER DEFAULT  */
#line 509 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3915 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: DEFAULT PAPER  */
#line 513 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3924 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: WIDTH  */
#line 517 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3932 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: HEIGHT  */
#line 520 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3940 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: TIMER  */
#line 523 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3948 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PEN DOLLAR OP expr CP  */
#line 526 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 3956 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER DOLLAR OP expr CP  */
#line 529 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3964 "src-generated/ugbc.tab.c"
    break;

  case 126: /* exponential: CMOVE DOLLAR OP expr COMMA expr CP  */
#line 532 "src/ugbc.y"
                                         {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3972 "src-generated/ugbc.tab.c"
    break;

  case 127: /* exponential: CUP DOLLAR  */
#line 535 "src/ugbc.y"
                 {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 3980 "src-generated/ugbc.tab.c"
    break;

  case 128: /* exponential: CDOWN DOLLAR  */
#line 538 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 3988 "src-generated/ugbc.tab.c"
    break;

  case 129: /* exponential: CLEFT DOLLAR  */
#line 541 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 3996 "src-generated/ugbc.tab.c"
    break;

  case 130: /* exponential: CRIGHT DOLLAR  */
#line 544 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 4004 "src-generated/ugbc.tab.c"
    break;

  case 131: /* exponential: AT DOLLAR OP expr COMMA expr CP  */
#line 547 "src/ugbc.y"
                                      {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4012 "src-generated/ugbc.tab.c"
    break;

  case 132: /* exponential: LOCATE DOLLAR OP expr COMMA expr CP  */
#line 550 "src/ugbc.y"
                                          {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4020 "src-generated/ugbc.tab.c"
    break;

  case 133: /* exponential: TAB DOLLAR  */
#line 553 "src/ugbc.y"
                 {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 4028 "src-generated/ugbc.tab.c"
    break;

  case 134: /* exponential: XCURS  */
#line 556 "src/ugbc.y"
            {
        (yyval.string) = text_get_xcurs( _environment )->name;
    }
#line 4036 "src-generated/ugbc.tab.c"
    break;

  case 135: /* exponential: YCURS  */
#line 559 "src/ugbc.y"
            {
        (yyval.string) = text_get_ycurs( _environment )->name;
    }
#line 4044 "src-generated/ugbc.tab.c"
    break;

  case 138: /* bank_definition_simple: AT direct_integer  */
#line 567 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4052 "src-generated/ugbc.tab.c"
    break;

  case 139: /* bank_definition_simple: Identifier AT direct_integer  */
#line 570 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4060 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 573 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4068 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 576 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4076 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 579 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4084 "src-generated/ugbc.tab.c"
    break;

  case 143: /* bank_definition_simple: DATA AT direct_integer  */
#line 582 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4092 "src-generated/ugbc.tab.c"
    break;

  case 144: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 586 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4100 "src-generated/ugbc.tab.c"
    break;

  case 145: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 589 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4108 "src-generated/ugbc.tab.c"
    break;

  case 146: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 592 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4116 "src-generated/ugbc.tab.c"
    break;

  case 147: /* bank_definition_simple: CODE AT direct_integer  */
#line 595 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4124 "src-generated/ugbc.tab.c"
    break;

  case 148: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 599 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4132 "src-generated/ugbc.tab.c"
    break;

  case 149: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 602 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4140 "src-generated/ugbc.tab.c"
    break;

  case 150: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 605 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4148 "src-generated/ugbc.tab.c"
    break;

  case 151: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 608 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4156 "src-generated/ugbc.tab.c"
    break;

  case 152: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 612 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4164 "src-generated/ugbc.tab.c"
    break;

  case 153: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 615 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4172 "src-generated/ugbc.tab.c"
    break;

  case 154: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 618 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4180 "src-generated/ugbc.tab.c"
    break;

  case 155: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 621 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4188 "src-generated/ugbc.tab.c"
    break;

  case 156: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 627 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4196 "src-generated/ugbc.tab.c"
    break;

  case 157: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 630 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4204 "src-generated/ugbc.tab.c"
    break;

  case 158: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 633 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4212 "src-generated/ugbc.tab.c"
    break;

  case 159: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 636 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4220 "src-generated/ugbc.tab.c"
    break;

  case 160: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 639 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4228 "src-generated/ugbc.tab.c"
    break;

  case 163: /* raster_definition_simple: Identifier AT direct_integer  */
#line 648 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 4236 "src-generated/ugbc.tab.c"
    break;

  case 164: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 651 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 4244 "src-generated/ugbc.tab.c"
    break;

  case 165: /* raster_definition_expression: Identifier AT expr  */
#line 656 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4252 "src-generated/ugbc.tab.c"
    break;

  case 166: /* raster_definition_expression: AT expr WITH Identifier  */
#line 659 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4260 "src-generated/ugbc.tab.c"
    break;

  case 169: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 668 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 4268 "src-generated/ugbc.tab.c"
    break;

  case 170: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 671 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 4276 "src-generated/ugbc.tab.c"
    break;

  case 171: /* next_raster_definition_expression: Identifier AT expr  */
#line 676 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 4284 "src-generated/ugbc.tab.c"
    break;

  case 172: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 679 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4292 "src-generated/ugbc.tab.c"
    break;

  case 175: /* color_definition_simple: BORDER direct_integer  */
#line 688 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 4300 "src-generated/ugbc.tab.c"
    break;

  case 176: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 691 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4308 "src-generated/ugbc.tab.c"
    break;

  case 177: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 694 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4316 "src-generated/ugbc.tab.c"
    break;

  case 178: /* color_definition_expression: BORDER expr  */
#line 699 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 4324 "src-generated/ugbc.tab.c"
    break;

  case 179: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 702 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4332 "src-generated/ugbc.tab.c"
    break;

  case 180: /* color_definition_expression: SPRITE expr TO expr  */
#line 705 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4340 "src-generated/ugbc.tab.c"
    break;

  case 186: /* wait_definition_simple: direct_integer CYCLES  */
#line 719 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4348 "src-generated/ugbc.tab.c"
    break;

  case 187: /* wait_definition_simple: direct_integer TICKS  */
#line 722 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4356 "src-generated/ugbc.tab.c"
    break;

  case 188: /* wait_definition_simple: direct_integer milliseconds  */
#line 725 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4364 "src-generated/ugbc.tab.c"
    break;

  case 189: /* wait_definition_expression: expr CYCLES  */
#line 730 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4372 "src-generated/ugbc.tab.c"
    break;

  case 190: /* wait_definition_expression: expr TICKS  */
#line 733 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4380 "src-generated/ugbc.tab.c"
    break;

  case 191: /* wait_definition_expression: expr milliseconds  */
#line 736 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4388 "src-generated/ugbc.tab.c"
    break;

  case 194: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 746 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4396 "src-generated/ugbc.tab.c"
    break;

  case 195: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 749 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4404 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 752 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4412 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 755 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4420 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 758 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4428 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_simple: direct_integer ENABLE  */
#line 761 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4436 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_simple: direct_integer DISABLE  */
#line 764 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4444 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 767 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4452 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 770 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4460 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 773 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4468 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 776 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4476 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 779 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4484 "src-generated/ugbc.tab.c"
    break;

  case 206: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 782 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4492 "src-generated/ugbc.tab.c"
    break;

  case 207: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 785 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4500 "src-generated/ugbc.tab.c"
    break;

  case 208: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 788 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4508 "src-generated/ugbc.tab.c"
    break;

  case 209: /* sprite_definition_expression: expr DATA FROM expr  */
#line 793 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4516 "src-generated/ugbc.tab.c"
    break;

  case 210: /* sprite_definition_expression: expr MULTICOLOR  */
#line 796 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4524 "src-generated/ugbc.tab.c"
    break;

  case 211: /* sprite_definition_expression: expr MONOCOLOR  */
#line 799 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4532 "src-generated/ugbc.tab.c"
    break;

  case 212: /* sprite_definition_expression: expr COLOR expr  */
#line 802 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4540 "src-generated/ugbc.tab.c"
    break;

  case 213: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 805 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4548 "src-generated/ugbc.tab.c"
    break;

  case 214: /* sprite_definition_expression: expr ENABLE  */
#line 808 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4556 "src-generated/ugbc.tab.c"
    break;

  case 215: /* sprite_definition_expression: expr DISABLE  */
#line 811 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4564 "src-generated/ugbc.tab.c"
    break;

  case 216: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 814 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4572 "src-generated/ugbc.tab.c"
    break;

  case 217: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 817 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4580 "src-generated/ugbc.tab.c"
    break;

  case 218: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 820 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4588 "src-generated/ugbc.tab.c"
    break;

  case 219: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 823 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4596 "src-generated/ugbc.tab.c"
    break;

  case 220: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 826 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4604 "src-generated/ugbc.tab.c"
    break;

  case 221: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 829 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4612 "src-generated/ugbc.tab.c"
    break;

  case 222: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 832 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4620 "src-generated/ugbc.tab.c"
    break;

  case 223: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 835 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4628 "src-generated/ugbc.tab.c"
    break;

  case 226: /* bitmap_definition_simple: AT direct_integer  */
#line 844 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4636 "src-generated/ugbc.tab.c"
    break;

  case 227: /* bitmap_definition_simple: ENABLE  */
#line 847 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4644 "src-generated/ugbc.tab.c"
    break;

  case 228: /* bitmap_definition_simple: DISABLE  */
#line 850 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4652 "src-generated/ugbc.tab.c"
    break;

  case 229: /* bitmap_definition_simple: CLEAR  */
#line 853 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4660 "src-generated/ugbc.tab.c"
    break;

  case 230: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 856 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4668 "src-generated/ugbc.tab.c"
    break;

  case 231: /* bitmap_definition_expression: AT expr  */
#line 862 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4676 "src-generated/ugbc.tab.c"
    break;

  case 232: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 865 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4684 "src-generated/ugbc.tab.c"
    break;

  case 235: /* textmap_definition_simple: AT direct_integer  */
#line 875 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4692 "src-generated/ugbc.tab.c"
    break;

  case 236: /* textmap_definition_expression: AT expr  */
#line 880 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4700 "src-generated/ugbc.tab.c"
    break;

  case 239: /* text_definition_simple: ENABLE  */
#line 889 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4708 "src-generated/ugbc.tab.c"
    break;

  case 240: /* text_definition_simple: DISABLE  */
#line 892 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4716 "src-generated/ugbc.tab.c"
    break;

  case 241: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 897 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4724 "src-generated/ugbc.tab.c"
    break;

  case 242: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 900 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4732 "src-generated/ugbc.tab.c"
    break;

  case 245: /* tiles_definition_simple: AT direct_integer  */
#line 909 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4740 "src-generated/ugbc.tab.c"
    break;

  case 246: /* tiles_definition_expression: AT expr  */
#line 914 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4748 "src-generated/ugbc.tab.c"
    break;

  case 249: /* colormap_definition_simple: AT direct_integer  */
#line 923 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4756 "src-generated/ugbc.tab.c"
    break;

  case 250: /* colormap_definition_simple: CLEAR  */
#line 926 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4764 "src-generated/ugbc.tab.c"
    break;

  case 251: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 929 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4772 "src-generated/ugbc.tab.c"
    break;

  case 252: /* colormap_definition_expression: AT expr  */
#line 934 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4780 "src-generated/ugbc.tab.c"
    break;

  case 253: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 937 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4788 "src-generated/ugbc.tab.c"
    break;

  case 256: /* screen_definition_simple: ON  */
#line 947 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4796 "src-generated/ugbc.tab.c"
    break;

  case 257: /* screen_definition_simple: OFF  */
#line 950 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4804 "src-generated/ugbc.tab.c"
    break;

  case 258: /* screen_definition_simple: ROWS direct_integer  */
#line 953 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4812 "src-generated/ugbc.tab.c"
    break;

  case 259: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 956 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4820 "src-generated/ugbc.tab.c"
    break;

  case 260: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 959 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4828 "src-generated/ugbc.tab.c"
    break;

  case 261: /* screen_definition_expression: ROWS expr  */
#line 964 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4836 "src-generated/ugbc.tab.c"
    break;

  case 262: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 967 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4844 "src-generated/ugbc.tab.c"
    break;

  case 263: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 970 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4852 "src-generated/ugbc.tab.c"
    break;

  case 267: /* var_definition_simple: Identifier ON Identifier  */
#line 979 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4860 "src-generated/ugbc.tab.c"
    break;

  case 268: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 982 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4868 "src-generated/ugbc.tab.c"
    break;

  case 269: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 985 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4876 "src-generated/ugbc.tab.c"
    break;

  case 270: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 988 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4886 "src-generated/ugbc.tab.c"
    break;

  case 271: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 993 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4896 "src-generated/ugbc.tab.c"
    break;

  case 272: /* goto_definition: Identifier  */
#line 1000 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4904 "src-generated/ugbc.tab.c"
    break;

  case 273: /* goto_definition: Integer  */
#line 1003 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4912 "src-generated/ugbc.tab.c"
    break;

  case 274: /* gosub_definition: Identifier  */
#line 1009 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4920 "src-generated/ugbc.tab.c"
    break;

  case 275: /* gosub_definition: Integer  */
#line 1012 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4928 "src-generated/ugbc.tab.c"
    break;

  case 277: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 1021 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4936 "src-generated/ugbc.tab.c"
    break;

  case 278: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 1027 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4944 "src-generated/ugbc.tab.c"
    break;

  case 281: /* ink_definition: expr  */
#line 1036 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4952 "src-generated/ugbc.tab.c"
    break;

  case 282: /* on_goto_definition: Identifier  */
#line 1041 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4961 "src-generated/ugbc.tab.c"
    break;

  case 283: /* $@4: %empty  */
#line 1045 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4969 "src-generated/ugbc.tab.c"
    break;

  case 285: /* on_gosub_definition: Identifier  */
#line 1050 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4978 "src-generated/ugbc.tab.c"
    break;

  case 286: /* $@5: %empty  */
#line 1054 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4986 "src-generated/ugbc.tab.c"
    break;

  case 288: /* on_proc_definition: Identifier  */
#line 1059 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 4995 "src-generated/ugbc.tab.c"
    break;

  case 289: /* $@6: %empty  */
#line 1063 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 5003 "src-generated/ugbc.tab.c"
    break;

  case 291: /* $@7: %empty  */
#line 1068 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 5011 "src-generated/ugbc.tab.c"
    break;

  case 293: /* $@8: %empty  */
#line 1071 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 5019 "src-generated/ugbc.tab.c"
    break;

  case 295: /* $@9: %empty  */
#line 1074 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 5027 "src-generated/ugbc.tab.c"
    break;

  case 297: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1079 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 5035 "src-generated/ugbc.tab.c"
    break;

  case 298: /* every_definition: ON  */
#line 1082 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 5043 "src-generated/ugbc.tab.c"
    break;

  case 299: /* every_definition: OFF  */
#line 1085 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 5051 "src-generated/ugbc.tab.c"
    break;

  case 300: /* add_definition: Identifier COMMA expr  */
#line 1090 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 5059 "src-generated/ugbc.tab.c"
    break;

  case 301: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1093 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5067 "src-generated/ugbc.tab.c"
    break;

  case 302: /* dimensions: Integer  */
#line 1099 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5076 "src-generated/ugbc.tab.c"
    break;

  case 303: /* dimensions: Integer COMMA dimensions  */
#line 1103 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5085 "src-generated/ugbc.tab.c"
    break;

  case 304: /* datatype: BYTE  */
#line 1110 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 5093 "src-generated/ugbc.tab.c"
    break;

  case 305: /* datatype: SIGNED BYTE  */
#line 1113 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 5101 "src-generated/ugbc.tab.c"
    break;

  case 306: /* datatype: WORD  */
#line 1116 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 5109 "src-generated/ugbc.tab.c"
    break;

  case 307: /* datatype: SIGNED WORD  */
#line 1119 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 5117 "src-generated/ugbc.tab.c"
    break;

  case 308: /* datatype: DWORD  */
#line 1122 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 5125 "src-generated/ugbc.tab.c"
    break;

  case 309: /* datatype: SIGNED DWORD  */
#line 1125 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 5133 "src-generated/ugbc.tab.c"
    break;

  case 310: /* datatype: ADDRESS  */
#line 1128 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 5141 "src-generated/ugbc.tab.c"
    break;

  case 311: /* datatype: POSITION  */
#line 1131 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 5149 "src-generated/ugbc.tab.c"
    break;

  case 312: /* datatype: COLOR  */
#line 1134 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 5157 "src-generated/ugbc.tab.c"
    break;

  case 313: /* datatype: STRING  */
#line 1137 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 5165 "src-generated/ugbc.tab.c"
    break;

  case 314: /* $@10: %empty  */
#line 1142 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5174 "src-generated/ugbc.tab.c"
    break;

  case 315: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1145 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 5184 "src-generated/ugbc.tab.c"
    break;

  case 316: /* $@11: %empty  */
#line 1150 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5193 "src-generated/ugbc.tab.c"
    break;

  case 317: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1153 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 5203 "src-generated/ugbc.tab.c"
    break;

  case 318: /* $@12: %empty  */
#line 1158 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5212 "src-generated/ugbc.tab.c"
    break;

  case 319: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1161 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 5222 "src-generated/ugbc.tab.c"
    break;

  case 322: /* indexes: expr  */
#line 1174 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5231 "src-generated/ugbc.tab.c"
    break;

  case 323: /* indexes: expr COMMA indexes  */
#line 1178 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5240 "src-generated/ugbc.tab.c"
    break;

  case 324: /* parameters: Identifier  */
#line 1185 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5250 "src-generated/ugbc.tab.c"
    break;

  case 325: /* parameters: Identifier DOLLAR  */
#line 1190 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5260 "src-generated/ugbc.tab.c"
    break;

  case 326: /* parameters: Identifier AS datatype  */
#line 1195 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5270 "src-generated/ugbc.tab.c"
    break;

  case 327: /* parameters: Identifier COMMA parameters  */
#line 1200 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5280 "src-generated/ugbc.tab.c"
    break;

  case 328: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1205 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5290 "src-generated/ugbc.tab.c"
    break;

  case 329: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1210 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5300 "src-generated/ugbc.tab.c"
    break;

  case 330: /* parameters_expr: Identifier  */
#line 1218 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5310 "src-generated/ugbc.tab.c"
    break;

  case 331: /* parameters_expr: Identifier DOLLAR  */
#line 1223 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5320 "src-generated/ugbc.tab.c"
    break;

  case 332: /* parameters_expr: Identifier AS datatype  */
#line 1228 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5330 "src-generated/ugbc.tab.c"
    break;

  case 333: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1233 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5340 "src-generated/ugbc.tab.c"
    break;

  case 334: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1238 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5350 "src-generated/ugbc.tab.c"
    break;

  case 335: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1243 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5360 "src-generated/ugbc.tab.c"
    break;

  case 336: /* parameters_expr: String  */
#line 1248 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5369 "src-generated/ugbc.tab.c"
    break;

  case 337: /* parameters_expr: String COMMA parameters_expr  */
#line 1252 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5378 "src-generated/ugbc.tab.c"
    break;

  case 338: /* values: expr  */
#line 1259 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5387 "src-generated/ugbc.tab.c"
    break;

  case 339: /* values: expr COMMA values  */
#line 1263 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5396 "src-generated/ugbc.tab.c"
    break;

  case 340: /* print_definition: expr  */
#line 1270 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5404 "src-generated/ugbc.tab.c"
    break;

  case 341: /* print_definition: expr COMMA  */
#line 1273 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5413 "src-generated/ugbc.tab.c"
    break;

  case 342: /* print_definition: expr SEMICOLON  */
#line 1277 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5421 "src-generated/ugbc.tab.c"
    break;

  case 343: /* $@13: %empty  */
#line 1280 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5430 "src-generated/ugbc.tab.c"
    break;

  case 345: /* $@14: %empty  */
#line 1284 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5438 "src-generated/ugbc.tab.c"
    break;

  case 347: /* use_definition: ANSI  */
#line 1290 "src/ugbc.y"
         {
        use_ansi( _environment );
    }
#line 5446 "src-generated/ugbc.tab.c"
    break;

  case 348: /* use_definition: SPECIFIC  */
#line 1293 "src/ugbc.y"
             {
        use_specific( _environment );
  }
#line 5454 "src-generated/ugbc.tab.c"
    break;

  case 349: /* writing_mode_definition: REPLACE  */
#line 1299 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5463 "src-generated/ugbc.tab.c"
    break;

  case 350: /* writing_mode_definition: OR  */
#line 1303 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5472 "src-generated/ugbc.tab.c"
    break;

  case 351: /* writing_mode_definition: XOR  */
#line 1307 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5481 "src-generated/ugbc.tab.c"
    break;

  case 352: /* writing_mode_definition: AND  */
#line 1311 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5490 "src-generated/ugbc.tab.c"
    break;

  case 353: /* writing_mode_definition: IGNORE  */
#line 1315 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5499 "src-generated/ugbc.tab.c"
    break;

  case 354: /* writing_part_definition: NORMAL  */
#line 1322 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5508 "src-generated/ugbc.tab.c"
    break;

  case 355: /* writing_part_definition: PAPER  */
#line 1326 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5517 "src-generated/ugbc.tab.c"
    break;

  case 356: /* writing_part_definition: PAPER ONLY  */
#line 1330 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5526 "src-generated/ugbc.tab.c"
    break;

  case 357: /* writing_part_definition: PEN  */
#line 1334 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5535 "src-generated/ugbc.tab.c"
    break;

  case 358: /* writing_part_definition: PEN ONLY  */
#line 1338 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5544 "src-generated/ugbc.tab.c"
    break;

  case 359: /* writing_definition: writing_mode_definition COMMA writing_part_definition  */
#line 1345 "src/ugbc.y"
                                                          {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5552 "src-generated/ugbc.tab.c"
    break;

  case 360: /* locate_definition: COMMA expr  */
#line 1351 "src/ugbc.y"
                {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 5560 "src-generated/ugbc.tab.c"
    break;

  case 361: /* locate_definition: expr COMMA  */
#line 1354 "src/ugbc.y"
                 {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 5568 "src-generated/ugbc.tab.c"
    break;

  case 362: /* locate_definition: expr COMMA expr  */
#line 1357 "src/ugbc.y"
                      {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5576 "src-generated/ugbc.tab.c"
    break;

  case 363: /* cmove_definition: COMMA expr  */
#line 1363 "src/ugbc.y"
                {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 5584 "src-generated/ugbc.tab.c"
    break;

  case 364: /* cmove_definition: expr COMMA  */
#line 1366 "src/ugbc.y"
                 {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 5592 "src-generated/ugbc.tab.c"
    break;

  case 365: /* cmove_definition: expr COMMA expr  */
#line 1369 "src/ugbc.y"
                      {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5600 "src-generated/ugbc.tab.c"
    break;

  case 366: /* hscroll_definition: LEFT  */
#line 1375 "src/ugbc.y"
         {
        text_hscroll_line( _environment, -1 );
    }
#line 5608 "src-generated/ugbc.tab.c"
    break;

  case 367: /* hscroll_definition: SCREEN LEFT  */
#line 1378 "src/ugbc.y"
                  {
        text_hscroll_screen( _environment, -1 );
    }
#line 5616 "src-generated/ugbc.tab.c"
    break;

  case 368: /* hscroll_definition: RIGHT  */
#line 1381 "src/ugbc.y"
            {
        text_hscroll_line( _environment, 1 );
    }
#line 5624 "src-generated/ugbc.tab.c"
    break;

  case 369: /* hscroll_definition: SCREEN RIGHT  */
#line 1384 "src/ugbc.y"
                   {
        text_hscroll_screen( _environment, 1 );
    }
#line 5632 "src-generated/ugbc.tab.c"
    break;

  case 370: /* vscroll_definition: SCREEN UP  */
#line 1390 "src/ugbc.y"
                {
        text_vscroll_screen( _environment, -1 );
    }
#line 5640 "src-generated/ugbc.tab.c"
    break;

  case 371: /* vscroll_definition: SCREEN DOWN  */
#line 1393 "src/ugbc.y"
                  {
        text_vscroll_screen( _environment, 1 );
    }
#line 5648 "src-generated/ugbc.tab.c"
    break;

  case 391: /* statement: MEMORIZE  */
#line 1418 "src/ugbc.y"
             {
      text_memorize( _environment );
  }
#line 5656 "src-generated/ugbc.tab.c"
    break;

  case 392: /* statement: REMEMBER  */
#line 1421 "src/ugbc.y"
             {
      text_remember( _environment );
  }
#line 5664 "src-generated/ugbc.tab.c"
    break;

  case 396: /* statement: CUP  */
#line 1427 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 5672 "src-generated/ugbc.tab.c"
    break;

  case 397: /* statement: CDOWN  */
#line 1430 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 5680 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statement: CLEFT  */
#line 1433 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 5688 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: CRIGHT  */
#line 1436 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 5696 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: CLINE  */
#line 1439 "src/ugbc.y"
          {
      text_cline( _environment, NULL );
  }
#line 5704 "src-generated/ugbc.tab.c"
    break;

  case 401: /* statement: CLINE expr  */
#line 1442 "src/ugbc.y"
               {
      text_cline( _environment, (yyvsp[0].string) );
  }
#line 5712 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: SET TAB expr  */
#line 1445 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 5720 "src-generated/ugbc.tab.c"
    break;

  case 403: /* statement: CENTER expr  */
#line 1448 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5728 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: CENTRE expr  */
#line 1451 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5736 "src-generated/ugbc.tab.c"
    break;

  case 405: /* statement: CLS  */
#line 1454 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 5744 "src-generated/ugbc.tab.c"
    break;

  case 406: /* statement: HOME  */
#line 1457 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 5752 "src-generated/ugbc.tab.c"
    break;

  case 407: /* statement: INC Identifier  */
#line 1460 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 5760 "src-generated/ugbc.tab.c"
    break;

  case 408: /* statement: DEC Identifier  */
#line 1463 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 5768 "src-generated/ugbc.tab.c"
    break;

  case 409: /* statement: RANDOMIZE  */
#line 1466 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 5776 "src-generated/ugbc.tab.c"
    break;

  case 410: /* statement: RANDOMIZE expr  */
#line 1469 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 5784 "src-generated/ugbc.tab.c"
    break;

  case 411: /* statement: IF expr THEN  */
#line 1472 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5792 "src-generated/ugbc.tab.c"
    break;

  case 412: /* statement: ELSE  */
#line 1475 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 5800 "src-generated/ugbc.tab.c"
    break;

  case 413: /* statement: ELSE IF expr THEN  */
#line 1478 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5808 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: ENDIF  */
#line 1481 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5816 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: DO  */
#line 1484 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5824 "src-generated/ugbc.tab.c"
    break;

  case 416: /* statement: LOOP  */
#line 1487 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5832 "src-generated/ugbc.tab.c"
    break;

  case 417: /* $@15: %empty  */
#line 1490 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5840 "src-generated/ugbc.tab.c"
    break;

  case 418: /* statement: WHILE $@15 expr  */
#line 1492 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5848 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: WEND  */
#line 1495 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5856 "src-generated/ugbc.tab.c"
    break;

  case 420: /* statement: REPEAT  */
#line 1498 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5864 "src-generated/ugbc.tab.c"
    break;

  case 421: /* statement: UNTIL expr  */
#line 1501 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5872 "src-generated/ugbc.tab.c"
    break;

  case 422: /* statement: EXIT  */
#line 1504 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5880 "src-generated/ugbc.tab.c"
    break;

  case 423: /* statement: EXIT PROC  */
#line 1507 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5888 "src-generated/ugbc.tab.c"
    break;

  case 424: /* statement: POP PROC  */
#line 1510 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5896 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: EXIT IF expr  */
#line 1513 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5904 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: EXIT Integer  */
#line 1516 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5912 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: EXIT direct_integer  */
#line 1519 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5920 "src-generated/ugbc.tab.c"
    break;

  case 428: /* statement: EXIT IF expr COMMA Integer  */
#line 1522 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5928 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1525 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5936 "src-generated/ugbc.tab.c"
    break;

  case 430: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1528 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5944 "src-generated/ugbc.tab.c"
    break;

  case 431: /* statement: NEXT  */
#line 1531 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5952 "src-generated/ugbc.tab.c"
    break;

  case 432: /* statement: PROCEDURE Identifier  */
#line 1534 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5961 "src-generated/ugbc.tab.c"
    break;

  case 433: /* $@16: %empty  */
#line 1538 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5969 "src-generated/ugbc.tab.c"
    break;

  case 434: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1540 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5977 "src-generated/ugbc.tab.c"
    break;

  case 435: /* statement: SHARED parameters_expr  */
#line 1543 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5985 "src-generated/ugbc.tab.c"
    break;

  case 436: /* statement: GLOBAL parameters_expr  */
#line 1546 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5993 "src-generated/ugbc.tab.c"
    break;

  case 437: /* statement: END PROC  */
#line 1549 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 6001 "src-generated/ugbc.tab.c"
    break;

  case 438: /* statement: END PROC OSP expr CSP  */
#line 1552 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6009 "src-generated/ugbc.tab.c"
    break;

  case 439: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1555 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 6017 "src-generated/ugbc.tab.c"
    break;

  case 440: /* statement: Identifier " "  */
#line 1558 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6026 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: PROC Identifier  */
#line 1562 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6035 "src-generated/ugbc.tab.c"
    break;

  case 442: /* statement: CALL Identifier  */
#line 1566 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6044 "src-generated/ugbc.tab.c"
    break;

  case 443: /* $@17: %empty  */
#line 1570 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6052 "src-generated/ugbc.tab.c"
    break;

  case 444: /* statement: Identifier OSP $@17 values CSP  */
#line 1572 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6060 "src-generated/ugbc.tab.c"
    break;

  case 445: /* $@18: %empty  */
#line 1575 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6068 "src-generated/ugbc.tab.c"
    break;

  case 446: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1577 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6076 "src-generated/ugbc.tab.c"
    break;

  case 447: /* $@19: %empty  */
#line 1580 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6084 "src-generated/ugbc.tab.c"
    break;

  case 448: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1582 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6092 "src-generated/ugbc.tab.c"
    break;

  case 449: /* statement: PEN expr  */
#line 1585 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 6100 "src-generated/ugbc.tab.c"
    break;

  case 450: /* statement: PAPER expr  */
#line 1588 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 6108 "src-generated/ugbc.tab.c"
    break;

  case 451: /* statement: INVERSE ON  */
#line 1591 "src/ugbc.y"
               {
      text_inverse( _environment, 1 );
  }
#line 6116 "src-generated/ugbc.tab.c"
    break;

  case 452: /* statement: INVERSE OFF  */
#line 1594 "src/ugbc.y"
                {
      text_inverse( _environment, 0 );
  }
#line 6124 "src-generated/ugbc.tab.c"
    break;

  case 454: /* statement: Identifier COLON  */
#line 1598 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 6132 "src-generated/ugbc.tab.c"
    break;

  case 455: /* statement: BEG GAMELOOP  */
#line 1601 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 6140 "src-generated/ugbc.tab.c"
    break;

  case 456: /* statement: END GAMELOOP  */
#line 1604 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 6148 "src-generated/ugbc.tab.c"
    break;

  case 457: /* statement: GRAPHIC  */
#line 1607 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 6156 "src-generated/ugbc.tab.c"
    break;

  case 458: /* statement: HALT  */
#line 1610 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 6164 "src-generated/ugbc.tab.c"
    break;

  case 459: /* statement: END  */
#line 1613 "src/ugbc.y"
        {
      end( _environment );
  }
#line 6172 "src-generated/ugbc.tab.c"
    break;

  case 464: /* statement: RETURN  */
#line 1620 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 6180 "src-generated/ugbc.tab.c"
    break;

  case 465: /* statement: RETURN expr  */
#line 1623 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 6188 "src-generated/ugbc.tab.c"
    break;

  case 466: /* statement: POP  */
#line 1626 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 6196 "src-generated/ugbc.tab.c"
    break;

  case 467: /* statement: DONE  */
#line 1629 "src/ugbc.y"
          {
      return 0;
  }
#line 6204 "src-generated/ugbc.tab.c"
    break;

  case 468: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1632 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6212 "src-generated/ugbc.tab.c"
    break;

  case 469: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1635 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6220 "src-generated/ugbc.tab.c"
    break;

  case 470: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1638 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 6228 "src-generated/ugbc.tab.c"
    break;

  case 471: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1641 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6236 "src-generated/ugbc.tab.c"
    break;

  case 474: /* statement: Identifier ASSIGN expr  */
#line 1646 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 6250 "src-generated/ugbc.tab.c"
    break;

  case 475: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1655 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 6264 "src-generated/ugbc.tab.c"
    break;

  case 476: /* $@20: %empty  */
#line 1664 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6273 "src-generated/ugbc.tab.c"
    break;

  case 477: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1668 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 6286 "src-generated/ugbc.tab.c"
    break;

  case 478: /* $@21: %empty  */
#line 1676 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6295 "src-generated/ugbc.tab.c"
    break;

  case 479: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1679 "src/ugbc.y"
                                {
        Variable * x = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * a = variable_retrieve( _environment, (yyvsp[-7].string) );
        if ( x->type != VT_STRING ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[x->type], DATATYPE_AS_STRING[VT_STRING] );
        }
        if ( a->type != VT_ARRAY ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->type], DATATYPE_AS_STRING[VT_ARRAY] );
        }
        if ( a->arrayType != VT_STRING ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->arrayType], DATATYPE_AS_STRING[VT_STRING] );
        }
        variable_move_array_string( _environment, (yyvsp[-7].string), x->name );
  }
#line 6314 "src-generated/ugbc.tab.c"
    break;

  case 480: /* $@22: %empty  */
#line 1693 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6323 "src-generated/ugbc.tab.c"
    break;

  case 481: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1696 "src/ugbc.y"
                                         {
        Variable * x = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * a = variable_retrieve( _environment, (yyvsp[-7].string) );
        if ( x->type != (yyvsp[-5].integer) ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[x->type], DATATYPE_AS_STRING[(yyvsp[-5].integer)] );
        }
        if ( a->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-7].string) );
        }
        if ( a->arrayType != (yyvsp[-5].integer) ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->arrayType], DATATYPE_AS_STRING[(yyvsp[-5].integer)] );
        }
        variable_move_array( _environment, (yyvsp[-7].string), x->name );
  }
#line 6342 "src-generated/ugbc.tab.c"
    break;

  case 482: /* statement: DEBUG expr  */
#line 1710 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 6350 "src-generated/ugbc.tab.c"
    break;

  case 485: /* statements_no_linenumbers: statement  */
#line 1718 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 6356 "src-generated/ugbc.tab.c"
    break;

  case 486: /* $@23: %empty  */
#line 1719 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 6362 "src-generated/ugbc.tab.c"
    break;

  case 488: /* $@24: %empty  */
#line 1723 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 6370 "src-generated/ugbc.tab.c"
    break;

  case 489: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1725 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 6378 "src-generated/ugbc.tab.c"
    break;

  case 490: /* $@25: %empty  */
#line 1730 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 6386 "src-generated/ugbc.tab.c"
    break;

  case 496: /* $@26: %empty  */
#line 1740 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 6392 "src-generated/ugbc.tab.c"
    break;


#line 6396 "src-generated/ugbc.tab.c"

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

#line 1742 "src/ugbc.y"


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
    printf("\t-W           Enable warnings during compilation" );
    exit(EXIT_FAILURE);
}

int main( int _argc, char *_argv[] ) {
    extern FILE *yyin;
    int flags, opt;
    int nsecs, tfnd;
    Environment * _environment = malloc(sizeof(Environment));

    _environment->warningsEnabled = 0;

    while ((opt = getopt(_argc, _argv, "e:c:W")) != -1) {
        switch (opt) {
                case 'c':
                    _environment->configurationFileName = strdup(optarg);
                    break;
                case 'W':
                    _environment->warningsEnabled = 1;
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

    bank_define( _environment, "VARIABLES", BT_VARIABLES, 0x5000, NULL );
    bank_define( _environment, "TEMPORARY", BT_TEMPORARY, 0x5100, NULL );

    if ( _environment->configurationFileName ) {
        _environment->configurationFile = fopen( _environment->configurationFileName, "wt");
        if ( ! _environment->configurationFile ) {
            fprintf(stderr, "Unable to open configuration file: %s\n", _environment->configurationFileName );
            exit(EXIT_FAILURE);
        }
        linker_setup( _environment );
        outhead0(".segment \"CODE\"");
        variable_define( _environment, "stringsAddress", VT_ADDRESS, 0x4200 );
        variable_global( _environment, "stringsAddress" );
        bank_define( _environment, "STRINGS", BT_STRINGS, 0x4200, NULL );
        variable_define( _environment, "textAddress", VT_ADDRESS, 0x0400 );
        variable_global( _environment, "textAddress" );
        variable_define( _environment, "colormapAddress", VT_ADDRESS, 0xD800 );
        variable_global( _environment, "colormapAddress" );
    } else {
        outhead0("org 32768");
        variable_define( _environment, "stringsAddress", VT_ADDRESS, 0xa000 );
        variable_global( _environment, "stringsAddress" );
        variable_define( _environment, "bitmap_enabled", VT_BYTE, 0 );
        variable_global( _environment, "bitmap_enabled" );
        variable_define( _environment, "bitmapAddress", VT_ADDRESS, 0x4000 );
        variable_global( _environment, "bitmapAddress" );
        variable_define( _environment, "colormapAddress", VT_ADDRESS, 0x5800 );
        variable_global( _environment, "colormapAddress" );
    }

    setup_text_variables( _environment );

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

