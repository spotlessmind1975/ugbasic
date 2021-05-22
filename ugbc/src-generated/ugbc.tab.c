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
  YYSYMBOL_USE = 158,                      /* USE  */
  YYSYMBOL_PAPER = 159,                    /* PAPER  */
  YYSYMBOL_INVERSE = 160,                  /* INVERSE  */
  YYSYMBOL_REPLACE = 161,                  /* REPLACE  */
  YYSYMBOL_XOR = 162,                      /* XOR  */
  YYSYMBOL_IGNORE = 163,                   /* IGNORE  */
  YYSYMBOL_NORMAL = 164,                   /* NORMAL  */
  YYSYMBOL_WRITING = 165,                  /* WRITING  */
  YYSYMBOL_ONLY = 166,                     /* ONLY  */
  YYSYMBOL_LOCATE = 167,                   /* LOCATE  */
  YYSYMBOL_CLS = 168,                      /* CLS  */
  YYSYMBOL_HOME = 169,                     /* HOME  */
  YYSYMBOL_CMOVE = 170,                    /* CMOVE  */
  YYSYMBOL_CENTER = 171,                   /* CENTER  */
  YYSYMBOL_CENTRE = 172,                   /* CENTRE  */
  YYSYMBOL_TAB = 173,                      /* TAB  */
  YYSYMBOL_SET = 174,                      /* SET  */
  YYSYMBOL_CUP = 175,                      /* CUP  */
  YYSYMBOL_CDOWN = 176,                    /* CDOWN  */
  YYSYMBOL_CLEFT = 177,                    /* CLEFT  */
  YYSYMBOL_CRIGHT = 178,                   /* CRIGHT  */
  YYSYMBOL_CLINE = 179,                    /* CLINE  */
  YYSYMBOL_XCURS = 180,                    /* XCURS  */
  YYSYMBOL_YCURS = 181,                    /* YCURS  */
  YYSYMBOL_MEMORIZE = 182,                 /* MEMORIZE  */
  YYSYMBOL_REMEMBER = 183,                 /* REMEMBER  */
  YYSYMBOL_HSCROLL = 184,                  /* HSCROLL  */
  YYSYMBOL_VSCROLL = 185,                  /* VSCROLL  */
  YYSYMBOL_TEXTADDRESS = 186,              /* TEXTADDRESS  */
  YYSYMBOL_JOY = 187,                      /* JOY  */
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
  YYSYMBOL_writing_mode_definition = 301,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 302,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 303,       /* writing_definition  */
  YYSYMBOL_locate_definition = 304,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 305,         /* cmove_definition  */
  YYSYMBOL_hscroll_definition = 306,       /* hscroll_definition  */
  YYSYMBOL_vscroll_definition = 307,       /* vscroll_definition  */
  YYSYMBOL_statement = 308,                /* statement  */
  YYSYMBOL_309_15 = 309,                   /* $@15  */
  YYSYMBOL_310_16 = 310,                   /* $@16  */
  YYSYMBOL_311_17 = 311,                   /* $@17  */
  YYSYMBOL_312_18 = 312,                   /* $@18  */
  YYSYMBOL_313_19 = 313,                   /* $@19  */
  YYSYMBOL_314_20 = 314,                   /* $@20  */
  YYSYMBOL_315_21 = 315,                   /* $@21  */
  YYSYMBOL_316_22 = 316,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 317, /* statements_no_linenumbers  */
  YYSYMBOL_318_23 = 318,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 319, /* statements_with_linenumbers  */
  YYSYMBOL_320_24 = 320,                   /* $@24  */
  YYSYMBOL_statements_complex = 321,       /* statements_complex  */
  YYSYMBOL_322_25 = 322,                   /* $@25  */
  YYSYMBOL_program = 323,                  /* program  */
  YYSYMBOL_324_26 = 324                    /* $@26  */
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
#define YYLAST   3221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  215
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  110
/* YYNRULES -- Number of rules.  */
#define YYNRULES  497
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  957

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
     544,   547,   550,   553,   556,   559,   562,   565,   570,   570,
     573,   576,   579,   582,   585,   588,   592,   595,   598,   601,
     605,   608,   611,   614,   618,   621,   624,   627,   633,   636,
     639,   642,   645,   650,   651,   654,   657,   662,   665,   670,
     671,   674,   677,   682,   685,   690,   691,   694,   697,   700,
     705,   708,   711,   716,   717,   720,   721,   722,   725,   728,
     731,   736,   739,   742,   748,   749,   752,   755,   758,   761,
     764,   767,   770,   773,   776,   779,   782,   785,   788,   791,
     794,   799,   802,   805,   808,   811,   814,   817,   820,   823,
     826,   829,   832,   835,   838,   841,   846,   847,   850,   853,
     856,   859,   862,   868,   871,   877,   878,   881,   886,   891,
     892,   895,   898,   903,   906,   911,   912,   915,   920,   925,
     926,   929,   932,   935,   940,   943,   949,   950,   953,   956,
     959,   962,   965,   970,   973,   976,   981,   982,   984,   985,
     988,   991,   994,   999,  1006,  1009,  1015,  1018,  1024,  1027,
    1033,  1038,  1039,  1042,  1047,  1051,  1051,  1056,  1060,  1060,
    1065,  1069,  1069,  1074,  1074,  1077,  1077,  1080,  1080,  1085,
    1088,  1091,  1096,  1099,  1105,  1109,  1116,  1119,  1122,  1125,
    1128,  1131,  1134,  1137,  1140,  1143,  1148,  1148,  1156,  1156,
    1164,  1164,  1175,  1176,  1180,  1184,  1191,  1196,  1201,  1206,
    1211,  1216,  1224,  1229,  1234,  1239,  1244,  1249,  1254,  1258,
    1265,  1269,  1276,  1279,  1283,  1286,  1286,  1290,  1290,  1296,
    1300,  1304,  1308,  1312,  1319,  1323,  1327,  1331,  1335,  1342,
    1348,  1351,  1354,  1360,  1363,  1366,  1372,  1375,  1378,  1381,
    1387,  1390,  1396,  1397,  1398,  1399,  1400,  1401,  1402,  1403,
    1404,  1405,  1406,  1407,  1408,  1409,  1410,  1411,  1414,  1415,
    1416,  1417,  1418,  1421,  1424,  1425,  1426,  1427,  1430,  1433,
    1436,  1439,  1442,  1445,  1448,  1451,  1454,  1457,  1460,  1463,
    1466,  1469,  1472,  1475,  1478,  1481,  1484,  1487,  1490,  1490,
    1495,  1498,  1501,  1504,  1507,  1510,  1513,  1516,  1519,  1522,
    1525,  1528,  1531,  1534,  1538,  1538,  1543,  1546,  1549,  1552,
    1555,  1558,  1562,  1566,  1570,  1570,  1575,  1575,  1580,  1580,
    1585,  1588,  1591,  1594,  1597,  1598,  1601,  1604,  1607,  1610,
    1613,  1616,  1617,  1618,  1619,  1620,  1623,  1626,  1629,  1632,
    1635,  1638,  1641,  1644,  1645,  1654,  1663,  1663,  1675,  1675,
    1692,  1692,  1709,  1712,  1713,  1717,  1718,  1718,  1722,  1722,
    1729,  1729,  1732,  1733,  1734,  1735,  1739,  1739
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
  "PARAM", "PRINT", "DEFAULT", "USE", "PAPER", "INVERSE", "REPLACE", "XOR",
  "IGNORE", "NORMAL", "WRITING", "ONLY", "LOCATE", "CLS", "HOME", "CMOVE",
  "CENTER", "CENTRE", "TAB", "SET", "CUP", "CDOWN", "CLEFT", "CRIGHT",
  "CLINE", "XCURS", "YCURS", "MEMORIZE", "REMEMBER", "HSCROLL", "VSCROLL",
  "TEXTADDRESS", "JOY", "BLACK", "WHITE", "RED", "CYAN", "VIOLET", "GREEN",
  "BLUE", "YELLOW", "ORANGE", "BROWN", "LIGHT", "DARK", "GREY", "GRAY",
  "MAGENTA", "PURPLE", "LAVENDER", "GOLD", "TURQUOISE", "TAN", "PINK",
  "PEACH", "OLIVE", "Identifier", "String", "Integer", "\" \"", "$accept",
  "expr", "expr_math", "term", "modula", "factor", "direct_integer",
  "random_definition_simple", "random_definition", "color_enumeration",
  "exponential", "$@1", "$@2", "$@3", "position", "bank_definition_simple",
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
  "textmap_definition", "text_definition_simple",
  "text_definition_expression", "text_definition",
  "tiles_definition_simple", "tiles_definition_expression",
  "tiles_definition", "colormap_definition_simple",
  "colormap_definition_expression", "colormap_definition",
  "screen_definition_simple", "screen_definition_expression",
  "screen_definition", "var_definition_simple", "goto_definition",
  "gosub_definition", "var_definition", "point_definition_simple",
  "point_definition_expression", "point_definition", "ink_definition",
  "on_goto_definition", "$@4", "on_gosub_definition", "$@5",
  "on_proc_definition", "$@6", "on_definition", "$@7", "$@8", "$@9",
  "every_definition", "add_definition", "dimensions", "datatype",
  "dim_definition", "$@10", "$@11", "$@12", "dim_definitions", "indexes",
  "parameters", "parameters_expr", "values", "print_definition", "$@13",
  "$@14", "writing_mode_definition", "writing_part_definition",
  "writing_definition", "locate_definition", "cmove_definition",
  "hscroll_definition", "vscroll_definition", "statement", "$@15", "$@16",
  "$@17", "$@18", "$@19", "$@20", "$@21", "$@22",
  "statements_no_linenumbers", "$@23", "statements_with_linenumbers",
  "$@24", "statements_complex", "$@25", "program", "$@26", YY_NULLPTR
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

#define YYPACT_NINF (-831)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-477)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -831,    76,   920,  -831,  -831,  -127,  -114,  2624,   -12,  -831,
      36,  2227,   100,    -1,  2227,  -831,    42,   208,  2624,  -104,
      53,  -831,  -831,  -831,  1843,    87,    29,  2624,  2624,    62,
     -34,  -831,    92,   130,  2624,  2624,  -831,   152,   154,    54,
    2624,    37,   123,  -831,   -35,  -831,  2624,   -11,  2035,   183,
      -5,  2624,    12,    19,    32,    38,    23,    23,  2624,  2624,
     170,    77,  1252,  -831,  -831,  1459,  2624,  2624,    48,  -831,
    -831,  -831,  -831,  2624,  -831,  -831,    41,   184,   255,    10,
    -831,   250,   278,   282,  -831,  -831,  -831,    75,   274,  1651,
    -831,  -831,   262,   267,   275,   199,  -831,  -831,   -10,   280,
     281,  2624,  -831,  -831,   284,   285,   286,   296,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   315,
     335,  -831,  -831,   336,    66,   -25,    15,   297,   352,   353,
     354,   355,   357,   358,  -831,  -831,  -831,   344,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,   189,  -831,  -831,    99,   -94,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,   191,
      26,  -831,  -831,   202,   172,   254,   258,   256,  -831,  -831,
    -831,  2227,   362,  -831,  -831,  -831,  2227,  2227,  2227,  -831,
    -831,  -831,   175,    -9,    51,  -831,  -831,  -831,     0,   313,
       1,     4,     6,    11,   365,  -831,  -831,  -831,   343,   381,
    -831,  -831,  -831,  2227,  -831,  -831,   361,  -831,  -831,  -831,
    -831,  -831,  2227,   345,   346,  -831,  -831,  -831,    -4,  -831,
      45,  -831,  -831,  -831,  -831,  -831,  2624,  2432,  -831,  -831,
     387,  -831,  -831,  -831,  2227,  -831,  -831,  -831,  2227,   367,
    -831,  -831,  -831,   325,  -831,  -831,  -831,   251,  2624,  2624,
    -831,  -831,  2227,  -831,  -831,  -831,   368,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  2624,  2624,  -831,  -831,  -831,
    -831,   389,  -831,  -831,   252,  -831,  2624,   397,  -831,  -831,
    -831,    49,   401,  -831,   263,   264,   268,    67,   408,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
     410,  -831,  2624,   414,  -831,  2624,   415,  -831,  -831,  -831,
    2624,  -831,   176,  -831,  -831,  -831,   187,  -831,  2624,  -831,
    -831,  2624,   416,  -831,  -831,   388,    16,  1097,  -831,   920,
     920,  -831,   393,   395,   396,   398,   399,   404,    70,   405,
    2227,  2227,  2227,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,   402,  -831,  -831,  2624,  2624,  -831,  2624,  2624,
    2624,  2624,  2624,  2624,  2624,  2624,  2624,  2624,  2624,  2624,
    2624,  2624,  2624,  2624,  2624,  2816,   407,   222,  -831,  -831,
     409,  -831,  -831,   417,   418,  -831,  -831,  -831,  -831,  -831,
    2624,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,   419,
    -831,   420,   155,   244,  2816,  2816,  2816,  2816,  2816,  2816,
    2816,  2816,  2816,  2816,  2816,  2816,  2816,  3008,   413,   421,
    2227,  -831,  -831,   372,   376,   377,   383,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  2227,   432,  -831,
    -831,  -831,   411,   313,   434,   313,   436,   313,   437,   313,
     438,   313,  -831,  2624,   430,  -831,  -831,   233,   243,    18,
      35,  -831,  -831,  -831,   431,   313,   433,  -831,  -831,   247,
     249,    93,   121,  -831,  -831,   435,  -831,  -831,  2227,  -831,
    -831,  2227,  2227,  -831,  -831,  -831,   422,   257,  -831,   466,
    2624,  -831,  -831,  -831,  -831,  2227,  -831,  2624,   469,   470,
    -831,  -831,  2227,   412,   471,  2624,   378,   472,  2624,  -831,
    -831,  -831,  -831,  -831,  -831,   171,  -831,  -831,   445,   464,
      12,  -831,   337,  -831,    23,   479,    16,    23,   -44,  -831,
    2624,  -831,  2624,  -831,  -831,  -831,  -831,  -831,  -831,   920,
    -831,  2624,   452,  2624,  2624,   454,     2,  -831,  1097,  -831,
    -831,  2624,   279,   283,   287,   289,   290,   455,   457,   458,
    -831,   461,   463,   473,   474,   475,   476,  2624,   498,   499,
     500,   501,   477,   478,   480,   481,   508,   482,   483,   484,
     486,   488,   519,   521,   494,   496,   502,    33,   326,   503,
    2624,  2624,  2624,   504,   506,  2624,  2624,  2624,  2624,   254,
     254,   300,   300,   300,   300,   300,   300,   300,   300,   258,
     256,   256,  -831,   331,   332,  -831,  -831,  2624,   313,  2624,
     313,   517,   518,  2227,   116,  -831,   313,  -831,   313,  -831,
     313,  -831,   313,    40,  -831,  2624,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  2624,  -831,   313,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,   313,  -831,  -831,  -831,  -831,
    -831,  -831,   339,   340,   341,   342,   542,  2624,   549,   514,
     515,   423,  2624,  2624,   552,   554,  -831,   -45,   490,   356,
    2624,   557,  -831,  -831,  -831,   533,   360,   534,  -831,  2624,
     359,  2624,  -831,    23,   564,  -831,   426,   427,  -831,  -831,
    -831,  -831,  -831,  -831,  2624,   567,   428,   568,   540,  2624,
    -831,   571,  -831,  -831,  -831,  -831,  -831,   369,   374,   382,
    -831,  -831,  -831,  -831,  -831,  -831,   544,  2624,  2624,  2624,
    2624,  -831,  -831,  -831,  -831,  2624,  -831,  -831,  -831,  -831,
    -831,  2624,  2624,  -831,  -831,  -831,  3008,   545,  -831,   553,
     587,   589,  -831,  2624,   448,   562,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,   390,   391,  -831,  -831,  -831,  -831,
    -831,  -831,   569,  -831,   570,  -831,   392,   158,  -831,   596,
    -831,   598,   599,  -831,   600,  -831,   601,  -831,   602,  2227,
     604,  2624,  2624,   313,  -831,   573,   577,  2624,   313,  -831,
    -831,  2624,  -831,    78,  2624,   360,   607,   581,   360,   485,
      89,   487,   491,  -831,    23,  -831,  -831,   582,  2624,  -831,
    2624,   606,   584,  2624,  -831,  -831,  -831,  -831,   585,   586,
      97,   115,   588,   590,   591,   593,  -831,  -831,  2624,  2624,
     594,  -831,  -831,  -831,  -831,   429,   439,  -831,   595,  -831,
     603,  -831,  2624,   313,   616,   624,   625,  2624,  -831,  -831,
    2624,  -831,  -831,  -831,   622,   626,   608,   609,   526,  2624,
     630,   574,   610,   360,  -831,   612,  -831,   359,   642,    16,
    -831,  -831,  -831,   637,  -831,  -831,  2624,   639,   617,  -831,
    -831,  2624,  -831,  2624,  -831,  -831,  -831,  -831,  -831,   618,
     619,  -831,  -831,  -831,   444,   446,   621,   623,   339,   340,
     341,  -831,  -831,  2624,  2624,  -831,  -831,  2624,   627,  2624,
    2624,  -831,  -831,  -831,  -831,   359,   654,  2624,  -831,  2624,
    -831,   628,   631,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,   649,  -831,  -831,  -831,   359,
    -831,  -831,  -831,  -831,  2624,  -831,  -831
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     496,     0,   484,     1,   483,     0,     0,     0,     0,   468,
       0,     0,   432,     0,     0,   459,     0,     0,     0,   268,
       0,   417,   421,   418,     0,     0,     0,     0,     0,     0,
     460,   415,     0,     0,     0,   410,   458,     0,     0,     0,
     465,   467,   413,   416,   423,   420,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   406,   407,     0,     0,     0,     0,   397,
     398,   399,   400,   401,   392,   393,     0,     0,     0,   480,
     488,   485,   492,   494,   497,   408,   409,     0,     0,     0,
      79,    80,     0,     0,     0,     0,   121,   122,     0,     0,
       0,     0,   112,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
      44,    49,    50,    51,    52,    53,    54,    57,    58,     0,
      63,    67,    65,   342,     2,    12,    15,    17,    76,    20,
     390,     0,     0,   169,   170,   373,     0,     0,     0,   183,
     184,   375,     0,     0,     0,   194,   195,   376,     0,     0,
       0,     0,     0,     0,     0,   163,   164,   372,     0,     0,
     226,   227,   377,     0,   229,   230,   231,   235,   236,   378,
     258,   259,     0,     0,     0,   266,   267,   383,     0,   461,
       0,   278,   386,   274,   275,   462,     0,     0,   241,   242,
       0,   245,   246,   380,     0,   249,   250,   381,     0,   252,
     256,   257,   382,     0,   450,   456,   457,   438,     0,     0,
     482,   411,     0,   239,   240,   379,     0,   281,   282,   384,
     276,   277,   463,   466,   425,     0,     0,   424,   427,   428,
     422,     0,   300,   301,     0,   464,     0,     0,   388,   283,
     385,   316,   322,   473,   442,   433,   443,   332,   338,   436,
     437,   389,   451,   452,   453,   352,   350,   349,   351,   353,
       0,   454,     0,     0,   391,     0,     0,   396,   404,   405,
       0,   402,     0,   366,   368,   394,     0,   395,     0,   490,
     455,     0,   478,   444,   441,     0,     0,   484,   486,   484,
     484,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,    24,    25,    27,    29,    30,    26,
      31,   101,     0,   115,   116,     0,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   120,
       0,   118,   119,     0,     0,   133,   127,   128,   129,   130,
       0,    55,    42,    45,    46,    47,    48,    43,    56,    64,
     108,     0,   347,   345,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   180,   177,     0,     0,     0,     0,    23,   185,   191,
     186,   187,   192,   193,   188,   189,   190,     0,     0,   175,
     176,   374,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   139,     0,     0,   216,   217,     0,     0,     0,
       0,   213,   212,   138,     0,     0,     0,   201,   202,     0,
       0,     0,     0,   198,   197,     0,   233,   228,     0,   263,
     260,     0,     0,   293,   297,   295,     0,     0,   419,     0,
       0,   248,   247,   254,   251,     0,   412,     0,     0,     0,
     238,   237,     0,     0,   426,     0,     0,     0,     0,   314,
     306,   308,   313,   310,   315,     0,   312,   320,     0,     0,
       0,   446,     0,   448,     0,   333,     0,     0,     0,   360,
     361,   363,   364,   403,   367,   369,   370,   371,   387,   484,
     474,     0,     0,     0,     0,     0,   480,   489,   484,   493,
     495,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      14,     5,     7,     8,     9,    10,     6,     3,     4,    16,
      18,    19,    21,     0,     0,   167,   165,     0,     0,     0,
       0,     0,     0,     0,     0,   145,     0,   157,     0,   149,
       0,   153,     0,   141,   214,     0,   221,   220,   225,   224,
     219,   223,   218,   222,     0,   199,     0,   206,   205,   210,
     209,   204,   208,   203,   207,     0,   234,   232,   264,   261,
     265,   262,     0,     0,     0,     0,   269,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   414,     0,     0,     0,
       0,   302,   307,   309,   311,     0,     0,     0,   323,     0,
       0,     0,   335,     0,   334,   339,   357,   355,   354,   359,
     362,   365,   491,   475,     0,   340,     0,   324,     0,     0,
     487,     0,    75,    68,    70,    74,    72,     0,     0,     0,
      78,    77,    82,    81,    84,    83,     0,     0,     0,     0,
       0,    91,    92,    93,   100,     0,    94,    95,    96,    97,
      98,     0,     0,   110,   111,   102,     0,     0,   106,     0,
       0,     0,   137,     0,     0,     0,   348,   346,   168,   166,
     182,   179,   181,   178,     0,     0,   173,   171,   142,   155,
     147,   150,   144,   156,   148,   152,     0,     0,   211,     0,
     196,     0,   284,   294,   287,   298,   290,   296,   270,     0,
       0,     0,     0,     0,   439,     0,     0,     0,     0,   429,
     430,     0,   299,     0,     0,     0,   304,     0,     0,     0,
     326,     0,     0,   336,     0,   358,   356,     0,     0,   445,
       0,     0,     0,     0,    69,    71,    73,   124,     0,     0,
       0,     0,     0,     0,     0,     0,   107,   125,     0,     0,
       0,   109,    60,   174,   172,     0,     0,   158,   143,   154,
     146,   151,     0,     0,     0,     0,     0,     0,   272,   271,
       0,   244,   255,   253,     0,     0,     0,     0,   431,     0,
       0,     0,     0,     0,   317,     0,   447,     0,   327,     0,
     435,   449,   337,     0,   341,   325,     0,     0,     0,    85,
      86,     0,    87,     0,    89,    99,   105,   104,    22,     0,
       0,    62,   160,   162,     0,     0,     0,     0,     0,     0,
       0,   273,   243,     0,     0,   280,   279,     0,     0,     0,
       0,   321,   305,   319,   329,     0,   328,     0,   477,     0,
     131,     0,     0,   132,   126,   159,   161,   215,   200,   286,
     289,   292,   469,   470,   440,     0,   471,   303,   330,     0,
     479,   481,    88,    90,     0,   331,   472
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -831,    -7,   -83,   -92,   260,  -218,    84,  -831,  -831,  -831,
    -414,  -831,  -831,  -831,   489,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,   492,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -240,  -831,  -239,  -831,  -241,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -752,  -325,  -831,  -831,  -831,  -831,   151,  -591,
    -830,   -55,  -586,   -52,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,  -831,
    -831,  -831,  -315,  -831,  -831,  -831,  -311,  -831,  -831,  -831
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   707,   164,   165,   166,   167,   184,   350,   351,   168,
     169,   401,   594,   595,   464,   195,   196,   197,   173,   174,
     175,   439,   440,   441,   179,   180,   181,   433,   185,   186,
     187,   200,   201,   202,   207,   208,   209,   253,   254,   255,
     231,   232,   233,   235,   236,   237,   240,   241,   242,   215,
     216,   217,   221,   225,   262,   222,   257,   258,   259,   280,
     783,   854,   785,   855,   787,   856,   219,   662,   664,   663,
     275,   278,   807,   517,   282,   518,   519,   685,   283,   708,
     811,   289,   706,   170,   598,   597,   300,   699,   301,   304,
     307,   315,   317,    81,   226,   522,   543,   689,   691,   325,
     542,   326,    82,   548,    83,   327,    84,   539,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     163,   545,   290,   612,   183,   755,   291,   198,   320,   754,
     352,   218,   547,   171,   319,   321,   320,   230,   549,   550,
     243,   244,   322,   321,   189,   437,   443,   250,   251,   445,
     322,   447,   190,   263,   266,   380,   449,  -476,   182,   270,
     746,   274,   509,   696,   279,  -476,   399,   924,   182,   191,
     483,   163,   292,   872,   238,   303,   875,   246,   306,   308,
     309,   -59,   378,   176,   640,   486,   311,   203,   177,  -318,
     776,   428,   429,   641,   524,   509,     3,   192,   193,   204,
     205,   642,   339,   312,    85,   869,   376,   525,   487,   777,
     643,   510,   511,   512,   357,   948,   877,    86,   199,   484,
     396,   377,   513,   809,   891,   812,   397,   220,   178,   878,
     267,   247,   234,   817,   870,   697,   526,   239,   822,   955,
     698,   922,   893,   188,   510,   511,   512,   248,   269,   353,
     206,   428,   434,   892,   379,   513,   313,   314,   879,   651,
     514,   485,   430,   431,   432,   557,   558,   354,   652,   768,
     323,   894,   515,   245,   381,  -344,   559,   587,   323,  -344,
     516,  -344,   840,   417,   418,   249,   769,   653,   799,   421,
     423,   425,   382,   514,   400,   295,   654,   252,   268,   256,
     404,   405,   264,   296,   406,   515,   407,   408,   409,   410,
     411,   848,   265,   516,   770,   771,   476,   610,   611,   172,
     271,   694,   430,   431,   435,   479,   277,   402,   849,   403,
     194,   438,   444,   293,   294,   446,   324,   448,   276,   488,
     489,   310,   450,   281,   324,   343,   316,   491,   702,   885,
     284,   493,   884,   710,   287,   288,   850,   851,   297,   298,
     299,   498,   499,   285,  -343,   500,   682,   683,  -343,   286,
    -343,   210,   211,   212,   213,   419,   328,   684,   503,   504,
     422,   424,   426,   214,   223,   260,   224,   261,   318,   507,
     412,   534,   535,   442,   344,   345,   346,   415,   413,   416,
     536,   537,   329,   347,   348,   349,   330,   477,   331,   392,
     636,   637,   393,   394,   332,   529,   480,   340,   531,   395,
     638,   639,   341,   533,   647,   648,   649,   650,   404,   405,
     342,   538,   599,   600,   540,   355,   356,   383,   492,   358,
     359,   360,   494,   601,   602,   603,   604,   605,   606,   607,
     608,   361,   835,   561,   563,   565,   501,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   568,   569,
     373,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   452,   453,
     374,   375,   384,   385,   386,   387,   454,   388,   389,   390,
     455,   456,   391,   593,   398,   414,   417,   420,   427,   457,
     451,   478,   481,   482,   490,   496,   182,   495,   458,   497,
     459,   460,   505,   502,   508,   506,   452,   465,   520,   461,
     462,   521,  -434,   615,   466,   527,   523,   528,   467,   468,
     463,   530,   532,   544,   562,   564,   566,   469,   551,   541,
     621,   552,   553,   589,   554,   555,   470,   567,   471,   472,
     556,   560,   588,   613,   590,   617,   634,   473,   474,   618,
     619,   614,   591,   592,   -61,   596,   620,   623,   463,   626,
     624,   628,   630,   632,   635,   665,   644,   646,   666,   692,
     655,   656,   695,   667,   658,   660,   672,   673,   677,   680,
     686,   679,   676,   668,   687,   690,   693,   704,   669,   709,
     671,   717,   712,   718,   719,   674,   713,   720,   678,   721,
     714,   681,   715,   716,   616,   727,   728,   729,   730,   722,
     723,   724,   725,   731,   732,   735,   733,   734,   736,   737,
     738,   622,   739,   700,   740,   701,   741,   625,   742,   627,
     743,   629,   744,   631,   703,   633,   705,   747,   745,   748,
     752,   753,   758,   759,   711,   756,   757,   764,   765,   645,
     782,   784,   786,   788,   926,   789,   791,   792,   793,   797,
     726,   798,   657,   801,   804,   659,   661,   802,   805,   808,
     810,   814,   794,   806,   818,   820,   821,   819,   823,   670,
     827,   836,   824,   749,   750,   751,   675,   825,   705,   837,
     163,   163,   815,   816,   838,   826,   839,   841,   842,   845,
     846,   843,   844,   852,   847,   853,  -285,  -288,  -291,   864,
     760,   860,   762,   865,   873,   857,   766,   874,   883,   886,
     887,   889,   890,   908,   895,   904,   896,   897,   778,   898,
     901,   909,   910,   905,   876,   913,   880,   779,   813,   914,
     881,   902,   917,   919,   915,   916,   921,   920,   923,   925,
     927,   903,   929,   930,   933,   934,   935,   937,   936,   938,
     790,   949,   954,   945,   952,   795,   796,   953,   939,   941,
     940,   688,     0,   803,   609,     0,   436,     0,     0,     0,
       0,     0,   705,     0,   705,     0,     0,     0,   475,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   761,     0,   763,     0,     0,   767,     0,     0,
     772,     0,   773,     0,   774,     0,   775,     0,     0,     0,
     828,   829,   830,   831,     0,     0,     0,     0,   832,     0,
     780,     0,     0,     0,   833,   834,     0,     0,     0,   781,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   882,
       0,   800,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   858,     0,   861,   862,     0,     0,     0,     0,
     866,     0,     0,     0,   868,     0,     0,   871,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   705,     0,     0,     0,     0,   888,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   899,   900,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   906,     0,     0,     0,     0,
     911,     0,     0,   912,     0,     0,     0,     0,     0,     0,
       0,     0,   918,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   859,     0,     0,     0,   863,     0,   928,
       0,     0,   867,     0,   931,     0,   932,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   942,   943,     0,     0,
     944,     0,   946,   947,     0,     0,     0,     0,     0,     0,
     950,     0,   951,     4,     0,     0,     0,     0,     0,     0,
       5,     6,     0,     0,     0,     0,     0,   907,     0,     0,
       0,     0,     7,     8,     9,     0,    10,   956,    11,    12,
       0,    13,    14,     0,     0,     0,     0,     0,     0,    15,
       0,    16,    17,    18,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,    21,
      22,    23,    24,    25,    26,     0,     0,     0,     0,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,     0,    29,
      30,     0,    31,     0,     0,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,     0,    42,     0,     0,
       0,    43,    44,    45,    46,    47,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,    52,     0,    53,    54,    55,     0,     0,
      56,     0,     0,     0,    57,     0,    58,     0,     0,    59,
      60,     0,     0,     0,     0,    61,     0,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
       4,     0,    74,    75,    76,    77,    78,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,    10,     0,    11,    12,     0,    13,    14,
       0,    79,     0,    80,     0,     0,    15,     0,    16,    17,
      18,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,    21,    22,    23,    24,
      25,    26,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,     0,    29,    30,     0,    31,
       0,     0,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,     0,     0,     0,    43,    44,
      45,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,    51,     0,     0,
      52,     0,    53,    54,    55,     0,     0,    56,     0,     0,
       0,    57,     0,    58,     0,     0,    59,    60,     0,   302,
       0,    87,    61,     0,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    88,     0,    74,
      75,    76,    77,    78,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,     0,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,    94,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,     0,    98,
       0,     0,     0,     0,     0,     0,     0,    99,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,     0,     0,   116,   117,   118,     0,   119,
     120,   121,     0,   122,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,     0,   125,
       0,   126,     0,     0,     0,     0,     0,     0,     0,   127,
       0,     0,   128,     0,     0,   129,     0,   130,   131,   132,
     133,     0,   134,   135,     0,     0,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,     0,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   305,     0,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,   124,     0,   125,     0,   126,     0,
       0,     0,     0,     0,     0,     0,   127,     0,     0,   128,
       0,     0,   129,     0,   130,   131,   132,   133,     0,   134,
     135,     0,     0,     0,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
      87,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,     0,     0,     0,    88,   333,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
       0,     0,    94,     0,     0,    95,   334,   335,   336,     0,
       0,     0,     0,     0,     0,    96,    97,   337,    98,     0,
       0,     0,     0,     0,     0,     0,    99,   100,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     0,     0,     0,   116,   117,   118,   338,   119,   120,
     121,     0,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,     0,   125,     0,
     126,     0,     0,     0,     0,     0,     0,     0,   127,     0,
       0,   128,     0,     0,   129,     0,   130,   131,   132,   133,
       0,   134,   135,     0,     0,     0,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    87,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     0,     0,     0,   227,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
     228,   229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,    94,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,     0,
      98,     0,     0,     0,     0,     0,     0,     0,    99,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,     0,     0,   116,   117,   118,     0,
     119,   120,   121,     0,   122,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,     0,
     125,     0,   126,     0,     0,     0,     0,     0,     0,     0,
     127,     0,     0,   128,     0,     0,   129,     0,   130,   131,
     132,   133,     0,   134,   135,     0,     0,     0,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    87,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,     0,     0,     0,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,   272,   273,
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
     124,     0,   125,     0,   126,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,   128,     0,     0,   129,     0,
     130,   131,   132,   133,     0,   134,   135,     0,     0,     0,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,    87,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,     0,
       0,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,    94,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
     182,    96,    97,     0,    98,     0,     0,     0,     0,     0,
       0,     0,    99,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,     0,     0,     0,
     116,   117,   118,     0,   119,   120,   121,     0,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,     0,   125,     0,   126,     0,     0,     0,
       0,     0,     0,     0,   127,     0,     0,   128,     0,     0,
     129,     0,   130,   131,   132,   133,     0,   134,   135,     0,
       0,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   332,     0,     0,     0,     0,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,    94,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,     0,    98,
       0,     0,     0,     0,     0,     0,     0,    99,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,     0,     0,   116,   117,   118,     0,   119,
     120,   121,     0,   122,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,     0,   125,
       0,   126,     0,     0,     0,     0,     0,     0,     0,   127,
       0,     0,   128,     0,     0,   129,     0,   130,   131,   132,
     133,     0,   134,   135,     0,     0,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    87,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,     0,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,    94,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
       0,    98,     0,     0,     0,     0,     0,     0,     0,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,     0,     0,   116,   117,   118,
       0,   119,   120,   121,     0,   122,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
       0,   125,     0,   126,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,   128,     0,     0,   129,     0,   130,
     131,   132,   133,     0,   134,   135,     0,     0,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    87,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,     0,     0,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,     0,     0,    94,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,     0,    98,     0,     0,     0,     0,     0,     0,
       0,    99,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   103,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     0,     0,     0,   116,
     117,   118,     0,   119,   120,   121,     0,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,     0,   125,     0,   126,     0,     0,     0,     0,
       0,     0,     0,   127,     0,     0,   128,     0,     0,   129,
       0,   130,   131,   132,   133,     0,   134,   135,     0,     0,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    87,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
       0,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,     0,     0,    94,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,     0,    98,     0,     0,     0,     0,
       0,     0,     0,    99,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   103,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,   116,   117,   118,     0,   119,   120,   121,     0,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,   125,     0,   126,     0,     0,
       0,     0,     0,     0,     0,   127,     0,     0,   128,     0,
       0,   129,     0,   130,   131,   132,   133,     0,   134,   135,
       0,     0,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162
};

static const yytype_int16 yycheck[] =
{
       7,   326,    57,   417,    11,   596,    58,    14,     6,   595,
      20,    18,   327,    25,     4,    13,     6,    24,   329,   330,
      27,    28,    20,    13,    25,    25,    25,    34,    35,    25,
      20,    25,    33,    40,    69,    20,    25,    35,    83,    46,
       7,    48,    26,    87,    51,    35,    20,   877,    83,    50,
      54,    58,    59,   805,    25,    62,   808,    91,    65,    66,
      67,    35,    87,    27,    46,    20,    73,    25,    32,    20,
      30,    80,    81,    55,     7,    26,     0,    78,    79,    37,
      38,    46,    89,    42,   211,     7,    20,    20,    43,    49,
      55,    75,    76,    77,   101,   925,     7,   211,    14,   103,
     194,    35,    86,   689,     7,   691,   200,   211,    72,    20,
     145,   145,    25,   704,    36,   159,    49,    88,   709,   949,
     164,   873,     7,    23,    75,    76,    77,    35,    44,   139,
      88,    80,    81,    36,   159,    86,    95,    96,    49,    46,
     124,   145,   151,   152,   153,    75,    76,   157,    55,    33,
     148,    36,   136,    91,   139,     0,    86,   375,   148,     4,
     144,     6,   753,   130,   171,    35,    50,    46,   213,   176,
     177,   178,   157,   124,   148,    98,    55,    25,   213,    25,
       8,     9,   145,   106,    12,   136,    14,    15,    16,    17,
      18,    33,    69,   144,    78,    79,   203,   415,   416,   211,
     211,   526,   151,   152,   153,   212,   211,     5,    50,     7,
     211,   211,   211,    43,    44,   211,   214,   211,    35,   226,
     227,   173,   211,   211,   214,    26,    42,   234,   539,   820,
     211,   238,   818,   548,   211,   212,    78,    79,   161,   162,
     163,   248,   249,   211,     0,   252,    75,    76,     4,   211,
       6,    43,    44,    45,    46,   171,     6,    86,   265,   266,
     176,   177,   178,    55,   211,   211,   213,   213,    13,   276,
      98,    95,    96,   189,    75,    76,    77,    19,   106,    21,
      93,    94,     4,    84,    85,    86,     4,   203,   213,   190,
      57,    58,   193,   194,    20,   302,   212,    35,   305,   200,
      57,    58,    35,   310,    57,    58,    57,    58,     8,     9,
      35,   318,   404,   405,   321,    35,    35,    20,   234,    35,
      35,    35,   238,   406,   407,   408,   409,   410,   411,   412,
     413,    35,   746,   340,   341,   342,   252,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,   355,   356,
      35,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,    25,    26,
      35,    35,    20,    20,    20,    20,    33,    20,    20,    35,
      37,    38,   193,   390,   193,   131,   130,    25,   213,    46,
      25,    30,    47,    47,     7,    70,    83,    30,    55,   148,
      57,    58,    13,    35,     7,   153,    25,    26,     7,    66,
      67,   148,   148,   420,    33,     7,   148,     7,    37,    38,
      77,     7,     7,    35,   340,   341,   342,    46,    35,    13,
     437,    36,    36,   211,    36,    36,    55,    35,    57,    58,
      36,    36,    35,    30,    35,    73,   453,    66,    67,    73,
      73,    30,    35,    35,    35,    35,    73,    25,    77,    25,
      49,    25,    25,    25,    34,    43,    35,    34,   211,   524,
      35,   478,   527,     7,   481,   482,     7,     7,     7,     7,
      35,   103,    70,   490,    20,   148,     7,    35,   495,    35,
     497,    36,   213,    36,    36,   502,   213,    36,   505,    36,
     213,   508,   213,   213,   420,     7,     7,     7,     7,    36,
      36,    36,    36,    36,    36,     7,    36,    36,    36,    36,
      36,   437,    36,   530,    36,   532,     7,   443,     7,   445,
      36,   447,    36,   449,   541,   451,   543,   211,    36,    36,
      36,    35,   211,   211,   551,   597,   598,    30,    30,   465,
     211,   211,   211,   211,   879,    13,     7,    43,    43,     7,
     567,     7,   478,    73,     7,   481,   482,   211,    35,    35,
     211,     7,   149,   213,     7,     7,    36,   149,     7,   495,
      36,    36,   213,   590,   591,   592,   502,   213,   595,    36,
     597,   598,   166,   166,     7,   213,     7,   149,    36,    30,
      30,   211,   211,     7,   212,     7,     7,     7,     7,    36,
     617,     7,   619,    36,     7,    13,   623,    36,    36,    13,
      36,    36,    36,     7,    36,    30,    36,    36,   635,    36,
      36,     7,     7,    30,   149,    13,   149,   644,   693,    13,
     149,   212,   116,    13,    36,    36,    36,    73,    36,     7,
      13,   212,    13,    36,    36,    36,   212,    36,   212,    36,
     667,     7,    13,    36,    36,   672,   673,    36,   908,   910,
     909,   520,    -1,   680,   414,    -1,   184,    -1,    -1,    -1,
      -1,    -1,   689,    -1,   691,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   618,    -1,   620,    -1,    -1,   623,    -1,    -1,
     626,    -1,   628,    -1,   630,    -1,   632,    -1,    -1,    -1,
     727,   728,   729,   730,    -1,    -1,    -1,    -1,   735,    -1,
     646,    -1,    -1,    -1,   741,   742,    -1,    -1,    -1,   655,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   814,
      -1,   677,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   789,    -1,   791,   792,    -1,    -1,    -1,    -1,
     797,    -1,    -1,    -1,   801,    -1,    -1,   804,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   818,    -1,    -1,    -1,    -1,   823,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   838,   839,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   852,    -1,    -1,    -1,    -1,
     857,    -1,    -1,   860,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   869,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   789,    -1,    -1,    -1,   793,    -1,   886,
      -1,    -1,   798,    -1,   891,    -1,   893,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   913,   914,    -1,    -1,
     917,    -1,   919,   920,    -1,    -1,    -1,    -1,    -1,    -1,
     927,    -1,   929,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,   853,    -1,    -1,
      -1,    -1,    22,    23,    24,    -1,    26,   954,    28,    29,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    41,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    89,
      90,    -1,    92,    -1,    -1,    95,    96,    97,    -1,    99,
     100,   101,   102,   103,   104,   105,    -1,   107,    -1,    -1,
      -1,   111,   112,   113,   114,   115,    -1,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     140,    -1,    -1,   143,    -1,   145,   146,   147,    -1,    -1,
     150,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,    -1,   167,   168,   169,
     170,   171,   172,    -1,   174,   175,   176,   177,   178,   179,
       3,    -1,   182,   183,   184,   185,   186,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    -1,    26,    -1,    28,    29,    -1,    31,    32,
      -1,   211,    -1,   213,    -1,    -1,    39,    -1,    41,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    89,    90,    -1,    92,
      -1,    -1,    95,    96,    97,    -1,    99,   100,   101,   102,
     103,   104,   105,    -1,   107,    -1,    -1,    -1,   111,   112,
     113,   114,   115,    -1,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,
     143,    -1,   145,   146,   147,    -1,    -1,   150,    -1,    -1,
      -1,   154,    -1,   156,    -1,    -1,   159,   160,    -1,     7,
      -1,     9,   165,    -1,   167,   168,   169,   170,   171,   172,
      -1,   174,   175,   176,   177,   178,   179,    25,    -1,   182,
     183,   184,   185,   186,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    -1,    -1,   211,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,    -1,    -1,   133,   134,   135,    -1,   137,
     138,   139,    -1,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,   157,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,
      -1,    -1,   170,    -1,    -1,   173,    -1,   175,   176,   177,
     178,    -1,   180,   181,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,    -1,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     7,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,   155,    -1,   157,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,    -1,   170,
      -1,    -1,   173,    -1,   175,   176,   177,   178,    -1,   180,
     181,    -1,    -1,    -1,    -1,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
       9,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    71,    -1,    -1,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,   138,
     139,    -1,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,   157,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,
      -1,   170,    -1,    -1,   173,    -1,   175,   176,   177,   178,
      -1,   180,   181,    -1,    -1,    -1,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,     9,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,    -1,   133,   134,   135,    -1,
     137,   138,   139,    -1,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,
     157,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,    -1,    -1,   170,    -1,    -1,   173,    -1,   175,   176,
     177,   178,    -1,   180,   181,    -1,    -1,    -1,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     9,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
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
     155,    -1,   157,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,    -1,    -1,   170,    -1,    -1,   173,    -1,
     175,   176,   177,   178,    -1,   180,   181,    -1,    -1,    -1,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,     9,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,    -1,    -1,
     133,   134,   135,    -1,   137,   138,   139,    -1,   141,   142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,    -1,   157,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,    -1,    -1,   170,    -1,    -1,
     173,    -1,   175,   176,   177,   178,    -1,   180,   181,    -1,
      -1,    -1,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,    -1,    -1,   133,   134,   135,    -1,   137,
     138,   139,    -1,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,   157,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,
      -1,    -1,   170,    -1,    -1,   173,    -1,   175,   176,   177,
     178,    -1,   180,   181,    -1,    -1,    -1,    -1,   186,   187,
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
      -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,    -1,    -1,   133,   134,   135,
      -1,   137,   138,   139,    -1,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
      -1,   157,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,    -1,    -1,   170,    -1,    -1,   173,    -1,   175,
     176,   177,   178,    -1,   180,   181,    -1,    -1,    -1,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,     9,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    -1,    -1,    -1,   133,
     134,   135,    -1,   137,   138,   139,    -1,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   155,    -1,   157,    -1,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   167,    -1,    -1,   170,    -1,    -1,   173,
      -1,   175,   176,   177,   178,    -1,   180,   181,    -1,    -1,
      -1,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,     9,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,   133,   134,   135,    -1,   137,   138,   139,    -1,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   155,    -1,   157,    -1,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   167,    -1,    -1,   170,    -1,
      -1,   173,    -1,   175,   176,   177,   178,    -1,   180,   181,
      -1,    -1,    -1,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   323,   324,     0,     3,    10,    11,    22,    23,    24,
      26,    28,    29,    31,    32,    39,    41,    42,    43,    48,
      54,    59,    60,    61,    62,    63,    64,    69,    87,    89,
      90,    92,    95,    96,    97,    99,   100,   101,   102,   103,
     104,   105,   107,   111,   112,   113,   114,   115,   117,   118,
     132,   140,   143,   145,   146,   147,   150,   154,   156,   159,
     160,   165,   167,   168,   169,   170,   171,   172,   174,   175,
     176,   177,   178,   179,   182,   183,   184,   185,   186,   211,
     213,   308,   317,   319,   321,   211,   211,     9,    25,    35,
      51,    52,    53,    68,    71,    74,    84,    85,    87,    95,
      96,   108,   109,   110,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   133,   134,   135,   137,
     138,   139,   141,   142,   155,   157,   159,   167,   170,   173,
     175,   176,   177,   178,   180,   181,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   216,   217,   218,   219,   220,   224,   225,
     298,    25,   211,   233,   234,   235,    27,    32,    72,   239,
     240,   241,    83,   216,   221,   243,   244,   245,    23,    25,
      33,    50,    78,    79,   211,   230,   231,   232,   216,   221,
     246,   247,   248,    25,    37,    38,    88,   249,   250,   251,
      43,    44,    45,    46,    55,   264,   265,   266,   216,   281,
     211,   267,   270,   211,   213,   268,   309,    25,    37,    38,
     216,   255,   256,   257,    25,   258,   259,   260,    25,    88,
     261,   262,   263,   216,   216,    91,    91,   145,    35,    35,
     216,   216,    25,   252,   253,   254,    25,   271,   272,   273,
     211,   213,   269,   216,   145,    69,    69,   145,   213,   221,
     216,   211,    43,    44,   216,   285,    35,   211,   286,   216,
     274,   211,   289,   293,   211,   211,   211,   211,   212,   296,
     296,   298,   216,    43,    44,    98,   106,   161,   162,   163,
     301,   303,     7,   216,   304,     7,   216,   305,   216,   216,
     173,   216,    42,    95,    96,   306,    42,   307,    13,     4,
       6,    13,    20,   148,   214,   314,   316,   320,     6,     4,
       4,   213,    20,    26,    75,    76,    77,    86,   136,   216,
      35,    35,    35,    26,    75,    76,    77,    84,    85,    86,
     222,   223,    20,   139,   157,    35,    35,   216,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    20,    35,    87,   159,
      20,   139,   157,    20,    20,    20,    20,    20,    20,    20,
      35,   193,   190,   193,   194,   200,   194,   200,   193,    20,
     148,   226,     5,     7,     8,     9,    12,    14,    15,    16,
      17,    18,    98,   106,   131,    19,    21,   130,   216,   221,
      25,   216,   221,   216,   221,   216,   221,   213,    80,    81,
     151,   152,   153,   242,    81,   153,   242,    25,   211,   236,
     237,   238,   221,    25,   211,    25,   211,    25,   211,    25,
     211,    25,    25,    26,    33,    37,    38,    46,    55,    57,
      58,    66,    67,    77,   229,    26,    33,    37,    38,    46,
      55,    57,    58,    66,    67,   229,   216,   221,    30,   216,
     221,    47,    47,    54,   103,   145,    20,    43,   216,   216,
       7,   216,   221,   216,   221,    30,    70,   148,   216,   216,
     216,   221,    35,   216,   216,    13,   153,   216,     7,    26,
      75,    76,    77,    86,   124,   136,   144,   288,   290,   291,
       7,   148,   310,   148,     7,    20,    49,     7,     7,   216,
       7,   216,     7,   216,    95,    96,    93,    94,   216,   322,
     216,    13,   315,   311,    35,   288,   211,   317,   318,   321,
     321,    35,    36,    36,    36,    36,    36,    75,    76,    86,
      36,   216,   221,   216,   221,   216,   221,    35,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   220,    35,   211,
      35,    35,    35,   216,   227,   228,    35,   300,   299,   218,
     218,   217,   217,   217,   217,   217,   217,   217,   217,   219,
     220,   220,   225,    30,    30,   216,   221,    73,    73,    73,
      73,   216,   221,    25,    49,   221,    25,   221,    25,   221,
      25,   221,    25,   221,   216,    34,    57,    58,    57,    58,
      46,    55,    46,    55,    35,   221,    34,    57,    58,    57,
      58,    46,    55,    46,    55,    35,   216,   221,   216,   221,
     216,   221,   282,   284,   283,    43,   211,     7,   216,   216,
     221,   216,     7,     7,   216,   221,    70,     7,   216,   103,
       7,   216,    75,    76,    86,   292,    35,    20,   293,   312,
     148,   313,   296,     7,   288,   296,    87,   159,   164,   302,
     216,   216,   321,   216,    35,   216,   297,   216,   294,    35,
     317,   216,   213,   213,   213,   213,   213,    36,    36,    36,
      36,    36,    36,    36,    36,    36,   216,     7,     7,     7,
       7,    36,    36,    36,    36,     7,    36,    36,    36,    36,
      36,     7,     7,    36,    36,    36,     7,   211,    36,   216,
     216,   216,    36,    35,   297,   294,   298,   298,   211,   211,
     216,   221,   216,   221,    30,    30,   216,   221,    33,    50,
      78,    79,   221,   221,   221,   221,    30,    49,   216,   216,
     221,   221,   211,   275,   211,   277,   211,   279,   211,    13,
     216,     7,    43,    43,   149,   216,   216,     7,     7,   213,
     221,    73,   211,   216,     7,    35,   213,   287,    35,   297,
     211,   295,   297,   296,     7,   166,   166,   294,     7,   149,
       7,    36,   294,     7,   213,   213,   213,    36,   216,   216,
     216,   216,   216,   216,   216,   225,    36,    36,     7,     7,
     294,   149,    36,   211,   211,    30,    30,   212,    33,    50,
      78,    79,     7,     7,   276,   278,   280,    13,   216,   221,
       7,   216,   216,   221,    36,    36,   216,   221,   216,     7,
      36,   216,   287,     7,    36,   287,   149,     7,    20,    49,
     149,   149,   296,    36,   297,   294,    13,    36,   216,    36,
      36,     7,    36,     7,    36,    36,    36,    36,    36,   216,
     216,    36,   212,   212,    30,    30,   216,   221,     7,     7,
       7,   216,   216,    13,    13,    36,    36,   116,   216,    13,
      73,    36,   287,    36,   295,     7,   288,    13,   216,    13,
      36,   216,   216,    36,    36,   212,   212,    36,    36,   275,
     277,   279,   216,   216,   216,    36,   216,   216,   295,     7,
     216,   216,    36,    36,    13,   295,   216
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
     225,   225,   225,   225,   225,   225,   225,   225,   229,   229,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   231,   231,
     231,   231,   231,   232,   232,   233,   233,   234,   234,   235,
     235,   236,   236,   237,   237,   238,   238,   239,   239,   239,
     240,   240,   240,   241,   241,   242,   242,   242,   243,   243,
     243,   244,   244,   244,   245,   245,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   248,   248,   249,   249,
     249,   249,   249,   250,   250,   251,   251,   252,   253,   254,
     254,   255,   255,   256,   256,   257,   257,   258,   259,   260,
     260,   261,   261,   261,   262,   262,   263,   263,   264,   264,
     264,   264,   264,   265,   265,   265,   266,   266,   267,   267,
     267,   267,   267,   267,   268,   268,   269,   269,   270,   271,
     272,   273,   273,   274,   275,   276,   275,   277,   278,   277,
     279,   280,   279,   282,   281,   283,   281,   284,   281,   285,
     285,   285,   286,   286,   287,   287,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   290,   289,   291,   289,
     292,   289,   293,   293,   294,   294,   295,   295,   295,   295,
     295,   295,   296,   296,   296,   296,   296,   296,   296,   296,
     297,   297,   298,   298,   298,   299,   298,   300,   298,   301,
     301,   301,   301,   301,   302,   302,   302,   302,   302,   303,
     304,   304,   304,   305,   305,   305,   306,   306,   306,   306,
     307,   307,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   309,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   310,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   311,   308,   312,   308,   313,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   314,   308,   315,   308,
     316,   308,   308,   308,   308,   317,   318,   317,   320,   319,
     322,   321,   321,   321,   321,   321,   324,   323
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
       2,     7,     7,     2,     1,     1,     1,     4,     1,     1,
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
       1,     1,     1,     6,     5,     1,     1,     2,     2,     1,
       1,     2,     1,     5,     2,     5,     1,     1,     1,     1,
       2,     3,     3,     2,     3,     3,     1,     1,     0,     3,
       4,     5,     5,     6,     1,     1,     1,     1,     1,     6,
       6,     1,     1,     1,     1,     0,     4,     1,     0,     4,
       1,     0,     4,     0,     4,     0,     4,     0,     4,     4,
       1,     1,     3,     7,     1,     3,     1,     2,     1,     2,
       1,     2,     1,     1,     1,     1,     0,     5,     0,     6,
       0,     6,     1,     3,     1,     3,     1,     2,     3,     3,
       4,     5,     1,     2,     3,     3,     4,     5,     1,     3,
       1,     3,     1,     2,     2,     0,     4,     0,     4,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     3,
       2,     2,     3,     2,     2,     3,     1,     2,     1,     2,
       2,     2,     2,     2,     3,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     2,     2,
       2,     2,     1,     1,     2,     2,     2,     1,     1,     1,
       1,     1,     2,     3,     2,     2,     1,     1,     2,     2,
       1,     2,     3,     1,     4,     1,     1,     1,     0,     3,
       1,     1,     2,     1,     2,     2,     3,     2,     2,     5,
       5,     6,     1,     2,     0,     6,     2,     2,     2,     5,
       8,     2,     2,     2,     0,     5,     0,     6,     0,     6,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     2,     2,     2,     2,     1,     2,     1,     1,     8,
       8,     8,    10,     2,     3,     4,     0,     7,     0,     8,
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
#line 2951 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 82 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 2960 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 86 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2968 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 89 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 2976 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 92 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 2984 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 95 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 2992 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 98 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3000 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 101 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3008 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 104 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 3016 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 111 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3024 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 114 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3033 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 127 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3042 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 131 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3051 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 139 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 3060 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 143 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 3069 "src-generated/ugbc.tab.c"
    break;

  case 23: /* direct_integer: HASH Integer  */
#line 150 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3077 "src-generated/ugbc.tab.c"
    break;

  case 24: /* random_definition_simple: BYTE  */
#line 155 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3085 "src-generated/ugbc.tab.c"
    break;

  case 25: /* random_definition_simple: WORD  */
#line 158 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3093 "src-generated/ugbc.tab.c"
    break;

  case 26: /* random_definition_simple: DWORD  */
#line 161 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3101 "src-generated/ugbc.tab.c"
    break;

  case 27: /* random_definition_simple: POSITION  */
#line 164 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3109 "src-generated/ugbc.tab.c"
    break;

  case 28: /* random_definition_simple: COLOR  */
#line 167 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3117 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: WIDTH  */
#line 170 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3125 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: HEIGHT  */
#line 173 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3133 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition: random_definition_simple  */
#line 178 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3141 "src-generated/ugbc.tab.c"
    break;

  case 32: /* color_enumeration: BLACK  */
#line 183 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3150 "src-generated/ugbc.tab.c"
    break;

  case 33: /* color_enumeration: WHITE  */
#line 187 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3159 "src-generated/ugbc.tab.c"
    break;

  case 34: /* color_enumeration: RED  */
#line 191 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3168 "src-generated/ugbc.tab.c"
    break;

  case 35: /* color_enumeration: CYAN  */
#line 195 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3177 "src-generated/ugbc.tab.c"
    break;

  case 36: /* color_enumeration: VIOLET  */
#line 199 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3186 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: GREEN  */
#line 203 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3195 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: BLUE  */
#line 207 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3204 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: YELLOW  */
#line 211 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3213 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: ORANGE  */
#line 215 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3222 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: BROWN  */
#line 219 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3231 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: LIGHT RED  */
#line 223 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3240 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: DARK GREY  */
#line 227 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3249 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: GREY  */
#line 231 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3258 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: LIGHT GREEN  */
#line 235 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3267 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: LIGHT BLUE  */
#line 239 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3276 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT GREY  */
#line 243 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3285 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK BLUE  */
#line 247 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3294 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: MAGENTA  */
#line 251 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3303 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: PURPLE  */
#line 255 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3312 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LAVENDER  */
#line 259 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3321 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: GOLD  */
#line 263 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3330 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: TURQUOISE  */
#line 267 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3339 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: TAN  */
#line 271 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3348 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: YELLOW GREEN  */
#line 275 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3357 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: OLIVE GREEN  */
#line 279 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3366 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: PINK  */
#line 283 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3375 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: PEACH  */
#line 287 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3384 "src-generated/ugbc.tab.c"
    break;

  case 59: /* $@1: %empty  */
#line 293 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3393 "src-generated/ugbc.tab.c"
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
#line 3405 "src-generated/ugbc.tab.c"
    break;

  case 61: /* $@2: %empty  */
#line 304 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3414 "src-generated/ugbc.tab.c"
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
#line 3426 "src-generated/ugbc.tab.c"
    break;

  case 63: /* exponential: Identifier  */
#line 315 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3434 "src-generated/ugbc.tab.c"
    break;

  case 64: /* exponential: Identifier DOLLAR  */
#line 318 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3442 "src-generated/ugbc.tab.c"
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
#line 3456 "src-generated/ugbc.tab.c"
    break;

  case 66: /* exponential: MINUS Integer  */
#line 330 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3465 "src-generated/ugbc.tab.c"
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
#line 3477 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: OP BYTE CP Integer  */
#line 341 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3486 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: OP SIGNED BYTE CP Integer  */
#line 345 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3495 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: OP WORD CP Integer  */
#line 349 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3504 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP SIGNED WORD CP Integer  */
#line 353 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3513 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: OP DWORD CP Integer  */
#line 357 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3522 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP SIGNED DWORD CP Integer  */
#line 361 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3531 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP POSITION CP Integer  */
#line 365 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3540 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP COLOR CP Integer  */
#line 369 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3549 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: color_enumeration  */
#line 373 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3557 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: PEEK OP direct_integer CP  */
#line 376 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3565 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: PEEK OP expr CP  */
#line 379 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3573 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: XPEN  */
#line 382 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3581 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: YPEN  */
#line 385 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3589 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: COLLISION OP direct_integer CP  */
#line 388 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3597 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: COLLISION OP expr CP  */
#line 391 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3605 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: HIT OP direct_integer CP  */
#line 394 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3613 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: HIT OP expr CP  */
#line 397 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3621 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: LEFT OP expr COMMA expr CP  */
#line 400 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3629 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 403 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3637 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: MID OP expr COMMA expr CP  */
#line 406 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3645 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 409 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3653 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: INSTR OP expr COMMA expr CP  */
#line 412 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3661 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 415 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3669 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: UPPER OP expr CP  */
#line 418 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3677 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: LOWER OP expr CP  */
#line 421 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3685 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: STR OP expr CP  */
#line 424 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3693 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: SPACE OP expr CP  */
#line 427 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3701 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: FLIP OP expr CP  */
#line 430 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3709 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: CHR OP expr CP  */
#line 433 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3717 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: ASC OP expr CP  */
#line 436 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3725 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: LEN OP expr CP  */
#line 439 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3733 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: STRING OP expr COMMA expr CP  */
#line 442 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3741 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: VAL OP expr CP  */
#line 445 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3749 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: RANDOM random_definition  */
#line 448 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3757 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: RND OP expr CP  */
#line 451 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 3765 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: OP expr CP  */
#line 454 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 3773 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: MAX OP expr COMMA expr CP  */
#line 457 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3781 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: MIN OP expr COMMA expr CP  */
#line 460 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3789 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: PARAM OP Identifier CP  */
#line 463 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3797 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 466 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 3805 "src-generated/ugbc.tab.c"
    break;

  case 108: /* $@3: %empty  */
#line 469 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 3813 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: Identifier OSP $@3 values CSP  */
#line 471 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 3822 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: SGN OP expr CP  */
#line 475 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 3830 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: ABS OP expr CP  */
#line 478 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 3838 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: TRUE  */
#line 481 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3847 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: FALSE  */
#line 485 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 3856 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: COLORS  */
#line 489 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 3865 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: PEN COLORS  */
#line 493 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3874 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: PEN DEFAULT  */
#line 497 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3883 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: DEFAULT PEN  */
#line 501 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 3892 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: PAPER COLORS  */
#line 505 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 3901 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: PAPER DEFAULT  */
#line 509 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3910 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: DEFAULT PAPER  */
#line 513 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 3919 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: WIDTH  */
#line 517 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 3927 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: HEIGHT  */
#line 520 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 3935 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: TIMER  */
#line 523 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 3943 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PEN DOLLAR OP expr CP  */
#line 526 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 3951 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER DOLLAR OP expr CP  */
#line 529 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3959 "src-generated/ugbc.tab.c"
    break;

  case 126: /* exponential: CMOVE DOLLAR OP expr COMMA expr CP  */
#line 532 "src/ugbc.y"
                                         {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3967 "src-generated/ugbc.tab.c"
    break;

  case 127: /* exponential: CUP DOLLAR  */
#line 535 "src/ugbc.y"
                 {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 3975 "src-generated/ugbc.tab.c"
    break;

  case 128: /* exponential: CDOWN DOLLAR  */
#line 538 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 3983 "src-generated/ugbc.tab.c"
    break;

  case 129: /* exponential: CLEFT DOLLAR  */
#line 541 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 3991 "src-generated/ugbc.tab.c"
    break;

  case 130: /* exponential: CRIGHT DOLLAR  */
#line 544 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 3999 "src-generated/ugbc.tab.c"
    break;

  case 131: /* exponential: AT DOLLAR OP expr COMMA expr CP  */
#line 547 "src/ugbc.y"
                                      {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4007 "src-generated/ugbc.tab.c"
    break;

  case 132: /* exponential: LOCATE DOLLAR OP expr COMMA expr CP  */
#line 550 "src/ugbc.y"
                                          {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4015 "src-generated/ugbc.tab.c"
    break;

  case 133: /* exponential: TAB DOLLAR  */
#line 553 "src/ugbc.y"
                 {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 4023 "src-generated/ugbc.tab.c"
    break;

  case 134: /* exponential: XCURS  */
#line 556 "src/ugbc.y"
            {
        (yyval.string) = text_get_xcurs( _environment )->name;
    }
#line 4031 "src-generated/ugbc.tab.c"
    break;

  case 135: /* exponential: YCURS  */
#line 559 "src/ugbc.y"
            {
        (yyval.string) = text_get_ycurs( _environment )->name;
    }
#line 4039 "src-generated/ugbc.tab.c"
    break;

  case 136: /* exponential: TEXTADDRESS  */
#line 562 "src/ugbc.y"
                  {
        (yyval.string) = strdup( "TEXTADDRESS" );
    }
#line 4047 "src-generated/ugbc.tab.c"
    break;

  case 137: /* exponential: JOY OP expr CP  */
#line 565 "src/ugbc.y"
                     {
        (yyval.string) = joy( _environment, (yyvsp[-1].string) )->name;
    }
#line 4055 "src-generated/ugbc.tab.c"
    break;

  case 140: /* bank_definition_simple: AT direct_integer  */
#line 573 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4063 "src-generated/ugbc.tab.c"
    break;

  case 141: /* bank_definition_simple: Identifier AT direct_integer  */
#line 576 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4071 "src-generated/ugbc.tab.c"
    break;

  case 142: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 579 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4079 "src-generated/ugbc.tab.c"
    break;

  case 143: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 582 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4087 "src-generated/ugbc.tab.c"
    break;

  case 144: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 585 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4095 "src-generated/ugbc.tab.c"
    break;

  case 145: /* bank_definition_simple: DATA AT direct_integer  */
#line 588 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4103 "src-generated/ugbc.tab.c"
    break;

  case 146: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 592 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4111 "src-generated/ugbc.tab.c"
    break;

  case 147: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 595 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4119 "src-generated/ugbc.tab.c"
    break;

  case 148: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 598 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4127 "src-generated/ugbc.tab.c"
    break;

  case 149: /* bank_definition_simple: CODE AT direct_integer  */
#line 601 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4135 "src-generated/ugbc.tab.c"
    break;

  case 150: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 605 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4143 "src-generated/ugbc.tab.c"
    break;

  case 151: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 608 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4151 "src-generated/ugbc.tab.c"
    break;

  case 152: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 611 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4159 "src-generated/ugbc.tab.c"
    break;

  case 153: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 614 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4167 "src-generated/ugbc.tab.c"
    break;

  case 154: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 618 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4175 "src-generated/ugbc.tab.c"
    break;

  case 155: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 621 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4183 "src-generated/ugbc.tab.c"
    break;

  case 156: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 624 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4191 "src-generated/ugbc.tab.c"
    break;

  case 157: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 627 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4199 "src-generated/ugbc.tab.c"
    break;

  case 158: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 633 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4207 "src-generated/ugbc.tab.c"
    break;

  case 159: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 636 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4215 "src-generated/ugbc.tab.c"
    break;

  case 160: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 639 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4223 "src-generated/ugbc.tab.c"
    break;

  case 161: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 642 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4231 "src-generated/ugbc.tab.c"
    break;

  case 162: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 645 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4239 "src-generated/ugbc.tab.c"
    break;

  case 165: /* raster_definition_simple: Identifier AT direct_integer  */
#line 654 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 4247 "src-generated/ugbc.tab.c"
    break;

  case 166: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 657 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 4255 "src-generated/ugbc.tab.c"
    break;

  case 167: /* raster_definition_expression: Identifier AT expr  */
#line 662 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4263 "src-generated/ugbc.tab.c"
    break;

  case 168: /* raster_definition_expression: AT expr WITH Identifier  */
#line 665 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4271 "src-generated/ugbc.tab.c"
    break;

  case 171: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 674 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 4279 "src-generated/ugbc.tab.c"
    break;

  case 172: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 677 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 4287 "src-generated/ugbc.tab.c"
    break;

  case 173: /* next_raster_definition_expression: Identifier AT expr  */
#line 682 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 4295 "src-generated/ugbc.tab.c"
    break;

  case 174: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 685 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4303 "src-generated/ugbc.tab.c"
    break;

  case 177: /* color_definition_simple: BORDER direct_integer  */
#line 694 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 4311 "src-generated/ugbc.tab.c"
    break;

  case 178: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 697 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4319 "src-generated/ugbc.tab.c"
    break;

  case 179: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 700 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4327 "src-generated/ugbc.tab.c"
    break;

  case 180: /* color_definition_expression: BORDER expr  */
#line 705 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 4335 "src-generated/ugbc.tab.c"
    break;

  case 181: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 708 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4343 "src-generated/ugbc.tab.c"
    break;

  case 182: /* color_definition_expression: SPRITE expr TO expr  */
#line 711 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4351 "src-generated/ugbc.tab.c"
    break;

  case 188: /* wait_definition_simple: direct_integer CYCLES  */
#line 725 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4359 "src-generated/ugbc.tab.c"
    break;

  case 189: /* wait_definition_simple: direct_integer TICKS  */
#line 728 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4367 "src-generated/ugbc.tab.c"
    break;

  case 190: /* wait_definition_simple: direct_integer milliseconds  */
#line 731 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4375 "src-generated/ugbc.tab.c"
    break;

  case 191: /* wait_definition_expression: expr CYCLES  */
#line 736 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4383 "src-generated/ugbc.tab.c"
    break;

  case 192: /* wait_definition_expression: expr TICKS  */
#line 739 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4391 "src-generated/ugbc.tab.c"
    break;

  case 193: /* wait_definition_expression: expr milliseconds  */
#line 742 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4399 "src-generated/ugbc.tab.c"
    break;

  case 196: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 752 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4407 "src-generated/ugbc.tab.c"
    break;

  case 197: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 755 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4415 "src-generated/ugbc.tab.c"
    break;

  case 198: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 758 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4423 "src-generated/ugbc.tab.c"
    break;

  case 199: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 761 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4431 "src-generated/ugbc.tab.c"
    break;

  case 200: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 764 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4439 "src-generated/ugbc.tab.c"
    break;

  case 201: /* sprite_definition_simple: direct_integer ENABLE  */
#line 767 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4447 "src-generated/ugbc.tab.c"
    break;

  case 202: /* sprite_definition_simple: direct_integer DISABLE  */
#line 770 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4455 "src-generated/ugbc.tab.c"
    break;

  case 203: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 773 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4463 "src-generated/ugbc.tab.c"
    break;

  case 204: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 776 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4471 "src-generated/ugbc.tab.c"
    break;

  case 205: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 779 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4479 "src-generated/ugbc.tab.c"
    break;

  case 206: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 782 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4487 "src-generated/ugbc.tab.c"
    break;

  case 207: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 785 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4495 "src-generated/ugbc.tab.c"
    break;

  case 208: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 788 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4503 "src-generated/ugbc.tab.c"
    break;

  case 209: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 791 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4511 "src-generated/ugbc.tab.c"
    break;

  case 210: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 794 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4519 "src-generated/ugbc.tab.c"
    break;

  case 211: /* sprite_definition_expression: expr DATA FROM expr  */
#line 799 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4527 "src-generated/ugbc.tab.c"
    break;

  case 212: /* sprite_definition_expression: expr MULTICOLOR  */
#line 802 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4535 "src-generated/ugbc.tab.c"
    break;

  case 213: /* sprite_definition_expression: expr MONOCOLOR  */
#line 805 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4543 "src-generated/ugbc.tab.c"
    break;

  case 214: /* sprite_definition_expression: expr COLOR expr  */
#line 808 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4551 "src-generated/ugbc.tab.c"
    break;

  case 215: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 811 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4559 "src-generated/ugbc.tab.c"
    break;

  case 216: /* sprite_definition_expression: expr ENABLE  */
#line 814 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4567 "src-generated/ugbc.tab.c"
    break;

  case 217: /* sprite_definition_expression: expr DISABLE  */
#line 817 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4575 "src-generated/ugbc.tab.c"
    break;

  case 218: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 820 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4583 "src-generated/ugbc.tab.c"
    break;

  case 219: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 823 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4591 "src-generated/ugbc.tab.c"
    break;

  case 220: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 826 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4599 "src-generated/ugbc.tab.c"
    break;

  case 221: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 829 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4607 "src-generated/ugbc.tab.c"
    break;

  case 222: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 832 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4615 "src-generated/ugbc.tab.c"
    break;

  case 223: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 835 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4623 "src-generated/ugbc.tab.c"
    break;

  case 224: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 838 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4631 "src-generated/ugbc.tab.c"
    break;

  case 225: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 841 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4639 "src-generated/ugbc.tab.c"
    break;

  case 228: /* bitmap_definition_simple: AT direct_integer  */
#line 850 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4647 "src-generated/ugbc.tab.c"
    break;

  case 229: /* bitmap_definition_simple: ENABLE  */
#line 853 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 4655 "src-generated/ugbc.tab.c"
    break;

  case 230: /* bitmap_definition_simple: DISABLE  */
#line 856 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 4663 "src-generated/ugbc.tab.c"
    break;

  case 231: /* bitmap_definition_simple: CLEAR  */
#line 859 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 4671 "src-generated/ugbc.tab.c"
    break;

  case 232: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 862 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 4679 "src-generated/ugbc.tab.c"
    break;

  case 233: /* bitmap_definition_expression: AT expr  */
#line 868 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4687 "src-generated/ugbc.tab.c"
    break;

  case 234: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 871 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 4695 "src-generated/ugbc.tab.c"
    break;

  case 237: /* textmap_definition_simple: AT direct_integer  */
#line 881 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 4703 "src-generated/ugbc.tab.c"
    break;

  case 238: /* textmap_definition_expression: AT expr  */
#line 886 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4711 "src-generated/ugbc.tab.c"
    break;

  case 241: /* text_definition_simple: ENABLE  */
#line 895 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 4719 "src-generated/ugbc.tab.c"
    break;

  case 242: /* text_definition_simple: DISABLE  */
#line 898 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 4727 "src-generated/ugbc.tab.c"
    break;

  case 243: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 903 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4735 "src-generated/ugbc.tab.c"
    break;

  case 244: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 906 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 4743 "src-generated/ugbc.tab.c"
    break;

  case 247: /* tiles_definition_simple: AT direct_integer  */
#line 915 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 4751 "src-generated/ugbc.tab.c"
    break;

  case 248: /* tiles_definition_expression: AT expr  */
#line 920 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 4759 "src-generated/ugbc.tab.c"
    break;

  case 251: /* colormap_definition_simple: AT direct_integer  */
#line 929 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 4767 "src-generated/ugbc.tab.c"
    break;

  case 252: /* colormap_definition_simple: CLEAR  */
#line 932 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 4775 "src-generated/ugbc.tab.c"
    break;

  case 253: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 935 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4783 "src-generated/ugbc.tab.c"
    break;

  case 254: /* colormap_definition_expression: AT expr  */
#line 940 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 4791 "src-generated/ugbc.tab.c"
    break;

  case 255: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 943 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4799 "src-generated/ugbc.tab.c"
    break;

  case 258: /* screen_definition_simple: ON  */
#line 953 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 4807 "src-generated/ugbc.tab.c"
    break;

  case 259: /* screen_definition_simple: OFF  */
#line 956 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 4815 "src-generated/ugbc.tab.c"
    break;

  case 260: /* screen_definition_simple: ROWS direct_integer  */
#line 959 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 4823 "src-generated/ugbc.tab.c"
    break;

  case 261: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 962 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4831 "src-generated/ugbc.tab.c"
    break;

  case 262: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 965 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 4839 "src-generated/ugbc.tab.c"
    break;

  case 263: /* screen_definition_expression: ROWS expr  */
#line 970 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 4847 "src-generated/ugbc.tab.c"
    break;

  case 264: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 973 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4855 "src-generated/ugbc.tab.c"
    break;

  case 265: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 976 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 4863 "src-generated/ugbc.tab.c"
    break;

  case 269: /* var_definition_simple: Identifier ON Identifier  */
#line 985 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 4871 "src-generated/ugbc.tab.c"
    break;

  case 270: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 988 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 4879 "src-generated/ugbc.tab.c"
    break;

  case 271: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 991 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 4887 "src-generated/ugbc.tab.c"
    break;

  case 272: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 994 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 4897 "src-generated/ugbc.tab.c"
    break;

  case 273: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 999 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 4907 "src-generated/ugbc.tab.c"
    break;

  case 274: /* goto_definition: Identifier  */
#line 1006 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 4915 "src-generated/ugbc.tab.c"
    break;

  case 275: /* goto_definition: Integer  */
#line 1009 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 4923 "src-generated/ugbc.tab.c"
    break;

  case 276: /* gosub_definition: Identifier  */
#line 1015 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 4931 "src-generated/ugbc.tab.c"
    break;

  case 277: /* gosub_definition: Integer  */
#line 1018 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 4939 "src-generated/ugbc.tab.c"
    break;

  case 279: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 1027 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 4947 "src-generated/ugbc.tab.c"
    break;

  case 280: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 1033 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 4955 "src-generated/ugbc.tab.c"
    break;

  case 283: /* ink_definition: expr  */
#line 1042 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 4963 "src-generated/ugbc.tab.c"
    break;

  case 284: /* on_goto_definition: Identifier  */
#line 1047 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 4972 "src-generated/ugbc.tab.c"
    break;

  case 285: /* $@4: %empty  */
#line 1051 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 4980 "src-generated/ugbc.tab.c"
    break;

  case 287: /* on_gosub_definition: Identifier  */
#line 1056 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 4989 "src-generated/ugbc.tab.c"
    break;

  case 288: /* $@5: %empty  */
#line 1060 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 4997 "src-generated/ugbc.tab.c"
    break;

  case 290: /* on_proc_definition: Identifier  */
#line 1065 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 5006 "src-generated/ugbc.tab.c"
    break;

  case 291: /* $@6: %empty  */
#line 1069 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 5014 "src-generated/ugbc.tab.c"
    break;

  case 293: /* $@7: %empty  */
#line 1074 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 5022 "src-generated/ugbc.tab.c"
    break;

  case 295: /* $@8: %empty  */
#line 1077 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 5030 "src-generated/ugbc.tab.c"
    break;

  case 297: /* $@9: %empty  */
#line 1080 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 5038 "src-generated/ugbc.tab.c"
    break;

  case 299: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1085 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 5046 "src-generated/ugbc.tab.c"
    break;

  case 300: /* every_definition: ON  */
#line 1088 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 5054 "src-generated/ugbc.tab.c"
    break;

  case 301: /* every_definition: OFF  */
#line 1091 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 5062 "src-generated/ugbc.tab.c"
    break;

  case 302: /* add_definition: Identifier COMMA expr  */
#line 1096 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 5070 "src-generated/ugbc.tab.c"
    break;

  case 303: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1099 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5078 "src-generated/ugbc.tab.c"
    break;

  case 304: /* dimensions: Integer  */
#line 1105 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5087 "src-generated/ugbc.tab.c"
    break;

  case 305: /* dimensions: Integer COMMA dimensions  */
#line 1109 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5096 "src-generated/ugbc.tab.c"
    break;

  case 306: /* datatype: BYTE  */
#line 1116 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 5104 "src-generated/ugbc.tab.c"
    break;

  case 307: /* datatype: SIGNED BYTE  */
#line 1119 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 5112 "src-generated/ugbc.tab.c"
    break;

  case 308: /* datatype: WORD  */
#line 1122 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 5120 "src-generated/ugbc.tab.c"
    break;

  case 309: /* datatype: SIGNED WORD  */
#line 1125 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 5128 "src-generated/ugbc.tab.c"
    break;

  case 310: /* datatype: DWORD  */
#line 1128 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 5136 "src-generated/ugbc.tab.c"
    break;

  case 311: /* datatype: SIGNED DWORD  */
#line 1131 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 5144 "src-generated/ugbc.tab.c"
    break;

  case 312: /* datatype: ADDRESS  */
#line 1134 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 5152 "src-generated/ugbc.tab.c"
    break;

  case 313: /* datatype: POSITION  */
#line 1137 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 5160 "src-generated/ugbc.tab.c"
    break;

  case 314: /* datatype: COLOR  */
#line 1140 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 5168 "src-generated/ugbc.tab.c"
    break;

  case 315: /* datatype: STRING  */
#line 1143 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 5176 "src-generated/ugbc.tab.c"
    break;

  case 316: /* $@10: %empty  */
#line 1148 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5185 "src-generated/ugbc.tab.c"
    break;

  case 317: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1151 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 5195 "src-generated/ugbc.tab.c"
    break;

  case 318: /* $@11: %empty  */
#line 1156 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5204 "src-generated/ugbc.tab.c"
    break;

  case 319: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1159 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 5214 "src-generated/ugbc.tab.c"
    break;

  case 320: /* $@12: %empty  */
#line 1164 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5223 "src-generated/ugbc.tab.c"
    break;

  case 321: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1167 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 5233 "src-generated/ugbc.tab.c"
    break;

  case 324: /* indexes: expr  */
#line 1180 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5242 "src-generated/ugbc.tab.c"
    break;

  case 325: /* indexes: expr COMMA indexes  */
#line 1184 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5251 "src-generated/ugbc.tab.c"
    break;

  case 326: /* parameters: Identifier  */
#line 1191 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5261 "src-generated/ugbc.tab.c"
    break;

  case 327: /* parameters: Identifier DOLLAR  */
#line 1196 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5271 "src-generated/ugbc.tab.c"
    break;

  case 328: /* parameters: Identifier AS datatype  */
#line 1201 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5281 "src-generated/ugbc.tab.c"
    break;

  case 329: /* parameters: Identifier COMMA parameters  */
#line 1206 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5291 "src-generated/ugbc.tab.c"
    break;

  case 330: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1211 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5301 "src-generated/ugbc.tab.c"
    break;

  case 331: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1216 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5311 "src-generated/ugbc.tab.c"
    break;

  case 332: /* parameters_expr: Identifier  */
#line 1224 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5321 "src-generated/ugbc.tab.c"
    break;

  case 333: /* parameters_expr: Identifier DOLLAR  */
#line 1229 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5331 "src-generated/ugbc.tab.c"
    break;

  case 334: /* parameters_expr: Identifier AS datatype  */
#line 1234 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5341 "src-generated/ugbc.tab.c"
    break;

  case 335: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1239 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5351 "src-generated/ugbc.tab.c"
    break;

  case 336: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1244 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5361 "src-generated/ugbc.tab.c"
    break;

  case 337: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1249 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5371 "src-generated/ugbc.tab.c"
    break;

  case 338: /* parameters_expr: String  */
#line 1254 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5380 "src-generated/ugbc.tab.c"
    break;

  case 339: /* parameters_expr: String COMMA parameters_expr  */
#line 1258 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5389 "src-generated/ugbc.tab.c"
    break;

  case 340: /* values: expr  */
#line 1265 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5398 "src-generated/ugbc.tab.c"
    break;

  case 341: /* values: expr COMMA values  */
#line 1269 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5407 "src-generated/ugbc.tab.c"
    break;

  case 342: /* print_definition: expr  */
#line 1276 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5415 "src-generated/ugbc.tab.c"
    break;

  case 343: /* print_definition: expr COMMA  */
#line 1279 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5424 "src-generated/ugbc.tab.c"
    break;

  case 344: /* print_definition: expr SEMICOLON  */
#line 1283 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5432 "src-generated/ugbc.tab.c"
    break;

  case 345: /* $@13: %empty  */
#line 1286 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5441 "src-generated/ugbc.tab.c"
    break;

  case 347: /* $@14: %empty  */
#line 1290 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5449 "src-generated/ugbc.tab.c"
    break;

  case 349: /* writing_mode_definition: REPLACE  */
#line 1296 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5458 "src-generated/ugbc.tab.c"
    break;

  case 350: /* writing_mode_definition: OR  */
#line 1300 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5467 "src-generated/ugbc.tab.c"
    break;

  case 351: /* writing_mode_definition: XOR  */
#line 1304 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5476 "src-generated/ugbc.tab.c"
    break;

  case 352: /* writing_mode_definition: AND  */
#line 1308 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5485 "src-generated/ugbc.tab.c"
    break;

  case 353: /* writing_mode_definition: IGNORE  */
#line 1312 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5494 "src-generated/ugbc.tab.c"
    break;

  case 354: /* writing_part_definition: NORMAL  */
#line 1319 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5503 "src-generated/ugbc.tab.c"
    break;

  case 355: /* writing_part_definition: PAPER  */
#line 1323 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5512 "src-generated/ugbc.tab.c"
    break;

  case 356: /* writing_part_definition: PAPER ONLY  */
#line 1327 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5521 "src-generated/ugbc.tab.c"
    break;

  case 357: /* writing_part_definition: PEN  */
#line 1331 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5530 "src-generated/ugbc.tab.c"
    break;

  case 358: /* writing_part_definition: PEN ONLY  */
#line 1335 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5539 "src-generated/ugbc.tab.c"
    break;

  case 359: /* writing_definition: writing_mode_definition COMMA writing_part_definition  */
#line 1342 "src/ugbc.y"
                                                          {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5547 "src-generated/ugbc.tab.c"
    break;

  case 360: /* locate_definition: COMMA expr  */
#line 1348 "src/ugbc.y"
                {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 5555 "src-generated/ugbc.tab.c"
    break;

  case 361: /* locate_definition: expr COMMA  */
#line 1351 "src/ugbc.y"
                 {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 5563 "src-generated/ugbc.tab.c"
    break;

  case 362: /* locate_definition: expr COMMA expr  */
#line 1354 "src/ugbc.y"
                      {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5571 "src-generated/ugbc.tab.c"
    break;

  case 363: /* cmove_definition: COMMA expr  */
#line 1360 "src/ugbc.y"
                {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 5579 "src-generated/ugbc.tab.c"
    break;

  case 364: /* cmove_definition: expr COMMA  */
#line 1363 "src/ugbc.y"
                 {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 5587 "src-generated/ugbc.tab.c"
    break;

  case 365: /* cmove_definition: expr COMMA expr  */
#line 1366 "src/ugbc.y"
                      {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5595 "src-generated/ugbc.tab.c"
    break;

  case 366: /* hscroll_definition: LEFT  */
#line 1372 "src/ugbc.y"
         {
        text_hscroll_line( _environment, -1 );
    }
#line 5603 "src-generated/ugbc.tab.c"
    break;

  case 367: /* hscroll_definition: SCREEN LEFT  */
#line 1375 "src/ugbc.y"
                  {
        text_hscroll_screen( _environment, -1 );
    }
#line 5611 "src-generated/ugbc.tab.c"
    break;

  case 368: /* hscroll_definition: RIGHT  */
#line 1378 "src/ugbc.y"
            {
        text_hscroll_line( _environment, 1 );
    }
#line 5619 "src-generated/ugbc.tab.c"
    break;

  case 369: /* hscroll_definition: SCREEN RIGHT  */
#line 1381 "src/ugbc.y"
                   {
        text_hscroll_screen( _environment, 1 );
    }
#line 5627 "src-generated/ugbc.tab.c"
    break;

  case 370: /* vscroll_definition: SCREEN UP  */
#line 1387 "src/ugbc.y"
                {
        text_vscroll_screen( _environment, -1 );
    }
#line 5635 "src-generated/ugbc.tab.c"
    break;

  case 371: /* vscroll_definition: SCREEN DOWN  */
#line 1390 "src/ugbc.y"
                  {
        text_vscroll_screen( _environment, 1 );
    }
#line 5643 "src-generated/ugbc.tab.c"
    break;

  case 387: /* statement: TEXTADDRESS ASSIGN expr  */
#line 1411 "src/ugbc.y"
                            {
      variable_move( _environment, (yyvsp[0].string), "ADDRESS" );
  }
#line 5651 "src-generated/ugbc.tab.c"
    break;

  case 392: /* statement: MEMORIZE  */
#line 1418 "src/ugbc.y"
             {
      text_memorize( _environment );
  }
#line 5659 "src-generated/ugbc.tab.c"
    break;

  case 393: /* statement: REMEMBER  */
#line 1421 "src/ugbc.y"
             {
      text_remember( _environment );
  }
#line 5667 "src-generated/ugbc.tab.c"
    break;

  case 397: /* statement: CUP  */
#line 1427 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 5675 "src-generated/ugbc.tab.c"
    break;

  case 398: /* statement: CDOWN  */
#line 1430 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 5683 "src-generated/ugbc.tab.c"
    break;

  case 399: /* statement: CLEFT  */
#line 1433 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 5691 "src-generated/ugbc.tab.c"
    break;

  case 400: /* statement: CRIGHT  */
#line 1436 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 5699 "src-generated/ugbc.tab.c"
    break;

  case 401: /* statement: CLINE  */
#line 1439 "src/ugbc.y"
          {
      text_cline( _environment, NULL );
  }
#line 5707 "src-generated/ugbc.tab.c"
    break;

  case 402: /* statement: CLINE expr  */
#line 1442 "src/ugbc.y"
               {
      text_cline( _environment, (yyvsp[0].string) );
  }
#line 5715 "src-generated/ugbc.tab.c"
    break;

  case 403: /* statement: SET TAB expr  */
#line 1445 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 5723 "src-generated/ugbc.tab.c"
    break;

  case 404: /* statement: CENTER expr  */
#line 1448 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5731 "src-generated/ugbc.tab.c"
    break;

  case 405: /* statement: CENTRE expr  */
#line 1451 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 5739 "src-generated/ugbc.tab.c"
    break;

  case 406: /* statement: CLS  */
#line 1454 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 5747 "src-generated/ugbc.tab.c"
    break;

  case 407: /* statement: HOME  */
#line 1457 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 5755 "src-generated/ugbc.tab.c"
    break;

  case 408: /* statement: INC Identifier  */
#line 1460 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 5763 "src-generated/ugbc.tab.c"
    break;

  case 409: /* statement: DEC Identifier  */
#line 1463 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 5771 "src-generated/ugbc.tab.c"
    break;

  case 410: /* statement: RANDOMIZE  */
#line 1466 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 5779 "src-generated/ugbc.tab.c"
    break;

  case 411: /* statement: RANDOMIZE expr  */
#line 1469 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 5787 "src-generated/ugbc.tab.c"
    break;

  case 412: /* statement: IF expr THEN  */
#line 1472 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5795 "src-generated/ugbc.tab.c"
    break;

  case 413: /* statement: ELSE  */
#line 1475 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 5803 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: ELSE IF expr THEN  */
#line 1478 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 5811 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: ENDIF  */
#line 1481 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 5819 "src-generated/ugbc.tab.c"
    break;

  case 416: /* statement: DO  */
#line 1484 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 5827 "src-generated/ugbc.tab.c"
    break;

  case 417: /* statement: LOOP  */
#line 1487 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 5835 "src-generated/ugbc.tab.c"
    break;

  case 418: /* $@15: %empty  */
#line 1490 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 5843 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: WHILE $@15 expr  */
#line 1492 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 5851 "src-generated/ugbc.tab.c"
    break;

  case 420: /* statement: WEND  */
#line 1495 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 5859 "src-generated/ugbc.tab.c"
    break;

  case 421: /* statement: REPEAT  */
#line 1498 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 5867 "src-generated/ugbc.tab.c"
    break;

  case 422: /* statement: UNTIL expr  */
#line 1501 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 5875 "src-generated/ugbc.tab.c"
    break;

  case 423: /* statement: EXIT  */
#line 1504 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 5883 "src-generated/ugbc.tab.c"
    break;

  case 424: /* statement: EXIT PROC  */
#line 1507 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 5891 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: POP PROC  */
#line 1510 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 5899 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: EXIT IF expr  */
#line 1513 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 5907 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: EXIT Integer  */
#line 1516 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5915 "src-generated/ugbc.tab.c"
    break;

  case 428: /* statement: EXIT direct_integer  */
#line 1519 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 5923 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: EXIT IF expr COMMA Integer  */
#line 1522 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5931 "src-generated/ugbc.tab.c"
    break;

  case 430: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1525 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 5939 "src-generated/ugbc.tab.c"
    break;

  case 431: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1528 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 5947 "src-generated/ugbc.tab.c"
    break;

  case 432: /* statement: NEXT  */
#line 1531 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 5955 "src-generated/ugbc.tab.c"
    break;

  case 433: /* statement: PROCEDURE Identifier  */
#line 1534 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 5964 "src-generated/ugbc.tab.c"
    break;

  case 434: /* $@16: %empty  */
#line 1538 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5972 "src-generated/ugbc.tab.c"
    break;

  case 435: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1540 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 5980 "src-generated/ugbc.tab.c"
    break;

  case 436: /* statement: SHARED parameters_expr  */
#line 1543 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 5988 "src-generated/ugbc.tab.c"
    break;

  case 437: /* statement: GLOBAL parameters_expr  */
#line 1546 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 5996 "src-generated/ugbc.tab.c"
    break;

  case 438: /* statement: END PROC  */
#line 1549 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 6004 "src-generated/ugbc.tab.c"
    break;

  case 439: /* statement: END PROC OSP expr CSP  */
#line 1552 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6012 "src-generated/ugbc.tab.c"
    break;

  case 440: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1555 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 6020 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: Identifier " "  */
#line 1558 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6029 "src-generated/ugbc.tab.c"
    break;

  case 442: /* statement: PROC Identifier  */
#line 1562 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6038 "src-generated/ugbc.tab.c"
    break;

  case 443: /* statement: CALL Identifier  */
#line 1566 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6047 "src-generated/ugbc.tab.c"
    break;

  case 444: /* $@17: %empty  */
#line 1570 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6055 "src-generated/ugbc.tab.c"
    break;

  case 445: /* statement: Identifier OSP $@17 values CSP  */
#line 1572 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6063 "src-generated/ugbc.tab.c"
    break;

  case 446: /* $@18: %empty  */
#line 1575 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6071 "src-generated/ugbc.tab.c"
    break;

  case 447: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1577 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6079 "src-generated/ugbc.tab.c"
    break;

  case 448: /* $@19: %empty  */
#line 1580 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6087 "src-generated/ugbc.tab.c"
    break;

  case 449: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1582 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6095 "src-generated/ugbc.tab.c"
    break;

  case 450: /* statement: PEN expr  */
#line 1585 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 6103 "src-generated/ugbc.tab.c"
    break;

  case 451: /* statement: PAPER expr  */
#line 1588 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 6111 "src-generated/ugbc.tab.c"
    break;

  case 452: /* statement: INVERSE ON  */
#line 1591 "src/ugbc.y"
               {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 6119 "src-generated/ugbc.tab.c"
    break;

  case 453: /* statement: INVERSE OFF  */
#line 1594 "src/ugbc.y"
                {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 6127 "src-generated/ugbc.tab.c"
    break;

  case 455: /* statement: Identifier COLON  */
#line 1598 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 6135 "src-generated/ugbc.tab.c"
    break;

  case 456: /* statement: BEG GAMELOOP  */
#line 1601 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 6143 "src-generated/ugbc.tab.c"
    break;

  case 457: /* statement: END GAMELOOP  */
#line 1604 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 6151 "src-generated/ugbc.tab.c"
    break;

  case 458: /* statement: GRAPHIC  */
#line 1607 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 6159 "src-generated/ugbc.tab.c"
    break;

  case 459: /* statement: HALT  */
#line 1610 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 6167 "src-generated/ugbc.tab.c"
    break;

  case 460: /* statement: END  */
#line 1613 "src/ugbc.y"
        {
      end( _environment );
  }
#line 6175 "src-generated/ugbc.tab.c"
    break;

  case 465: /* statement: RETURN  */
#line 1620 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 6183 "src-generated/ugbc.tab.c"
    break;

  case 466: /* statement: RETURN expr  */
#line 1623 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 6191 "src-generated/ugbc.tab.c"
    break;

  case 467: /* statement: POP  */
#line 1626 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 6199 "src-generated/ugbc.tab.c"
    break;

  case 468: /* statement: DONE  */
#line 1629 "src/ugbc.y"
          {
      return 0;
  }
#line 6207 "src-generated/ugbc.tab.c"
    break;

  case 469: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1632 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6215 "src-generated/ugbc.tab.c"
    break;

  case 470: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1635 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6223 "src-generated/ugbc.tab.c"
    break;

  case 471: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1638 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 6231 "src-generated/ugbc.tab.c"
    break;

  case 472: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1641 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6239 "src-generated/ugbc.tab.c"
    break;

  case 474: /* statement: Identifier ASSIGN expr  */
#line 1645 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 6253 "src-generated/ugbc.tab.c"
    break;

  case 475: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1654 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 6267 "src-generated/ugbc.tab.c"
    break;

  case 476: /* $@20: %empty  */
#line 1663 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6276 "src-generated/ugbc.tab.c"
    break;

  case 477: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1667 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 6289 "src-generated/ugbc.tab.c"
    break;

  case 478: /* $@21: %empty  */
#line 1675 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6298 "src-generated/ugbc.tab.c"
    break;

  case 479: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1678 "src/ugbc.y"
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
#line 6317 "src-generated/ugbc.tab.c"
    break;

  case 480: /* $@22: %empty  */
#line 1692 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6326 "src-generated/ugbc.tab.c"
    break;

  case 481: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1695 "src/ugbc.y"
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
#line 6345 "src-generated/ugbc.tab.c"
    break;

  case 482: /* statement: DEBUG expr  */
#line 1709 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 6353 "src-generated/ugbc.tab.c"
    break;

  case 485: /* statements_no_linenumbers: statement  */
#line 1717 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 6359 "src-generated/ugbc.tab.c"
    break;

  case 486: /* $@23: %empty  */
#line 1718 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 6365 "src-generated/ugbc.tab.c"
    break;

  case 488: /* $@24: %empty  */
#line 1722 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 6373 "src-generated/ugbc.tab.c"
    break;

  case 489: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1724 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 6381 "src-generated/ugbc.tab.c"
    break;

  case 490: /* $@25: %empty  */
#line 1729 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 6389 "src-generated/ugbc.tab.c"
    break;

  case 496: /* $@26: %empty  */
#line 1739 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 6395 "src-generated/ugbc.tab.c"
    break;


#line 6399 "src-generated/ugbc.tab.c"

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

#line 1741 "src/ugbc.y"


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
    memset( _environment, 0, sizeof(Environment));

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
        variable_import( _environment, "TEXTADDRESS", VT_ADDRESS );
        variable_global( _environment, "TEXTADDRESS" );    
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

