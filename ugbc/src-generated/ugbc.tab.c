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
  YYSYMBOL_OP_SEMICOLON = 5,               /* OP_SEMICOLON  */
  YYSYMBOL_OP_COLON = 6,                   /* OP_COLON  */
  YYSYMBOL_OP_COMMA = 7,                   /* OP_COMMA  */
  YYSYMBOL_OP_PLUS = 8,                    /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 9,                   /* OP_MINUS  */
  YYSYMBOL_OP_INC = 10,                    /* OP_INC  */
  YYSYMBOL_OP_DEC = 11,                    /* OP_DEC  */
  YYSYMBOL_OP_EQUAL = 12,                  /* OP_EQUAL  */
  YYSYMBOL_OP_ASSIGN = 13,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_LT = 14,                     /* OP_LT  */
  YYSYMBOL_OP_LTE = 15,                    /* OP_LTE  */
  YYSYMBOL_OP_GT = 16,                     /* OP_GT  */
  YYSYMBOL_OP_GTE = 17,                    /* OP_GTE  */
  YYSYMBOL_OP_DISEQUAL = 18,               /* OP_DISEQUAL  */
  YYSYMBOL_OP_MULTIPLICATION = 19,         /* OP_MULTIPLICATION  */
  YYSYMBOL_OP_DOLLAR = 20,                 /* OP_DOLLAR  */
  YYSYMBOL_OP_DIVISION = 21,               /* OP_DIVISION  */
  YYSYMBOL_QM = 22,                        /* QM  */
  YYSYMBOL_HAS = 23,                       /* HAS  */
  YYSYMBOL_IS = 24,                        /* IS  */
  YYSYMBOL_OF = 25,                        /* OF  */
  YYSYMBOL_OP_HASH = 26,                   /* OP_HASH  */
  YYSYMBOL_OP_POW = 27,                    /* OP_POW  */
  YYSYMBOL_RASTER = 28,                    /* RASTER  */
  YYSYMBOL_DONE = 29,                      /* DONE  */
  YYSYMBOL_AT = 30,                        /* AT  */
  YYSYMBOL_COLOR = 31,                     /* COLOR  */
  YYSYMBOL_BORDER = 32,                    /* BORDER  */
  YYSYMBOL_WAIT = 33,                      /* WAIT  */
  YYSYMBOL_NEXT = 34,                      /* NEXT  */
  YYSYMBOL_WITH = 35,                      /* WITH  */
  YYSYMBOL_BANK = 36,                      /* BANK  */
  YYSYMBOL_SPRITE = 37,                    /* SPRITE  */
  YYSYMBOL_DATA = 38,                      /* DATA  */
  YYSYMBOL_FROM = 39,                      /* FROM  */
  YYSYMBOL_OP = 40,                        /* OP  */
  YYSYMBOL_CP = 41,                        /* CP  */
  YYSYMBOL_ENABLE = 42,                    /* ENABLE  */
  YYSYMBOL_DISABLE = 43,                   /* DISABLE  */
  YYSYMBOL_HALT = 44,                      /* HALT  */
  YYSYMBOL_ECM = 45,                       /* ECM  */
  YYSYMBOL_BITMAP = 46,                    /* BITMAP  */
  YYSYMBOL_SCREEN = 47,                    /* SCREEN  */
  YYSYMBOL_ON = 48,                        /* ON  */
  YYSYMBOL_OFF = 49,                       /* OFF  */
  YYSYMBOL_ROWS = 50,                      /* ROWS  */
  YYSYMBOL_VERTICAL = 51,                  /* VERTICAL  */
  YYSYMBOL_SCROLL = 52,                    /* SCROLL  */
  YYSYMBOL_VAR = 53,                       /* VAR  */
  YYSYMBOL_AS = 54,                        /* AS  */
  YYSYMBOL_TEMPORARY = 55,                 /* TEMPORARY  */
  YYSYMBOL_XPEN = 56,                      /* XPEN  */
  YYSYMBOL_YPEN = 57,                      /* YPEN  */
  YYSYMBOL_PEEK = 58,                      /* PEEK  */
  YYSYMBOL_GOTO = 59,                      /* GOTO  */
  YYSYMBOL_HORIZONTAL = 60,                /* HORIZONTAL  */
  YYSYMBOL_MCM = 61,                       /* MCM  */
  YYSYMBOL_COMPRESS = 62,                  /* COMPRESS  */
  YYSYMBOL_EXPAND = 63,                    /* EXPAND  */
  YYSYMBOL_LOOP = 64,                      /* LOOP  */
  YYSYMBOL_REPEAT = 65,                    /* REPEAT  */
  YYSYMBOL_WHILE = 66,                     /* WHILE  */
  YYSYMBOL_TEXT = 67,                      /* TEXT  */
  YYSYMBOL_TILES = 68,                     /* TILES  */
  YYSYMBOL_COLORMAP = 69,                  /* COLORMAP  */
  YYSYMBOL_SELECT = 70,                    /* SELECT  */
  YYSYMBOL_MONOCOLOR = 71,                 /* MONOCOLOR  */
  YYSYMBOL_MULTICOLOR = 72,                /* MULTICOLOR  */
  YYSYMBOL_COLLISION = 73,                 /* COLLISION  */
  YYSYMBOL_IF = 74,                        /* IF  */
  YYSYMBOL_THEN = 75,                      /* THEN  */
  YYSYMBOL_HIT = 76,                       /* HIT  */
  YYSYMBOL_BACKGROUND = 77,                /* BACKGROUND  */
  YYSYMBOL_TO = 78,                        /* TO  */
  YYSYMBOL_RANDOM = 79,                    /* RANDOM  */
  YYSYMBOL_BYTE = 80,                      /* BYTE  */
  YYSYMBOL_WORD = 81,                      /* WORD  */
  YYSYMBOL_POSITION = 82,                  /* POSITION  */
  YYSYMBOL_CODE = 83,                      /* CODE  */
  YYSYMBOL_VARIABLES = 84,                 /* VARIABLES  */
  YYSYMBOL_MS = 85,                        /* MS  */
  YYSYMBOL_CYCLES = 86,                    /* CYCLES  */
  YYSYMBOL_S = 87,                         /* S  */
  YYSYMBOL_WIDTH = 88,                     /* WIDTH  */
  YYSYMBOL_HEIGHT = 89,                    /* HEIGHT  */
  YYSYMBOL_DWORD = 90,                     /* DWORD  */
  YYSYMBOL_PEN = 91,                       /* PEN  */
  YYSYMBOL_CLEAR = 92,                     /* CLEAR  */
  YYSYMBOL_BEG = 93,                       /* BEG  */
  YYSYMBOL_END = 94,                       /* END  */
  YYSYMBOL_GAMELOOP = 95,                  /* GAMELOOP  */
  YYSYMBOL_ENDIF = 96,                     /* ENDIF  */
  YYSYMBOL_UP = 97,                        /* UP  */
  YYSYMBOL_DOWN = 98,                      /* DOWN  */
  YYSYMBOL_LEFT = 99,                      /* LEFT  */
  YYSYMBOL_RIGHT = 100,                    /* RIGHT  */
  YYSYMBOL_DEBUG = 101,                    /* DEBUG  */
  YYSYMBOL_AND = 102,                      /* AND  */
  YYSYMBOL_RANDOMIZE = 103,                /* RANDOMIZE  */
  YYSYMBOL_GRAPHIC = 104,                  /* GRAPHIC  */
  YYSYMBOL_TEXTMAP = 105,                  /* TEXTMAP  */
  YYSYMBOL_POINT = 106,                    /* POINT  */
  YYSYMBOL_GOSUB = 107,                    /* GOSUB  */
  YYSYMBOL_RETURN = 108,                   /* RETURN  */
  YYSYMBOL_POP = 109,                      /* POP  */
  YYSYMBOL_OR = 110,                       /* OR  */
  YYSYMBOL_ELSE = 111,                     /* ELSE  */
  YYSYMBOL_NOT = 112,                      /* NOT  */
  YYSYMBOL_TRUE = 113,                     /* TRUE  */
  YYSYMBOL_FALSE = 114,                    /* FALSE  */
  YYSYMBOL_DO = 115,                       /* DO  */
  YYSYMBOL_EXIT = 116,                     /* EXIT  */
  YYSYMBOL_WEND = 117,                     /* WEND  */
  YYSYMBOL_UNTIL = 118,                    /* UNTIL  */
  YYSYMBOL_FOR = 119,                      /* FOR  */
  YYSYMBOL_STEP = 120,                     /* STEP  */
  YYSYMBOL_EVERY = 121,                    /* EVERY  */
  YYSYMBOL_MID = 122,                      /* MID  */
  YYSYMBOL_INSTR = 123,                    /* INSTR  */
  YYSYMBOL_UPPER = 124,                    /* UPPER  */
  YYSYMBOL_LOWER = 125,                    /* LOWER  */
  YYSYMBOL_STR = 126,                      /* STR  */
  YYSYMBOL_VAL = 127,                      /* VAL  */
  YYSYMBOL_STRING = 128,                   /* STRING  */
  YYSYMBOL_SPACE = 129,                    /* SPACE  */
  YYSYMBOL_FLIP = 130,                     /* FLIP  */
  YYSYMBOL_CHR = 131,                      /* CHR  */
  YYSYMBOL_ASC = 132,                      /* ASC  */
  YYSYMBOL_LEN = 133,                      /* LEN  */
  YYSYMBOL_MOD = 134,                      /* MOD  */
  YYSYMBOL_ADD = 135,                      /* ADD  */
  YYSYMBOL_MIN = 136,                      /* MIN  */
  YYSYMBOL_MAX = 137,                      /* MAX  */
  YYSYMBOL_SGN = 138,                      /* SGN  */
  YYSYMBOL_SIGNED = 139,                   /* SIGNED  */
  YYSYMBOL_ABS = 140,                      /* ABS  */
  YYSYMBOL_RND = 141,                      /* RND  */
  YYSYMBOL_COLORS = 142,                   /* COLORS  */
  YYSYMBOL_INK = 143,                      /* INK  */
  YYSYMBOL_TIMER = 144,                    /* TIMER  */
  YYSYMBOL_POWERING = 145,                 /* POWERING  */
  YYSYMBOL_DIM = 146,                      /* DIM  */
  YYSYMBOL_ADDRESS = 147,                  /* ADDRESS  */
  YYSYMBOL_PROC = 148,                     /* PROC  */
  YYSYMBOL_PROCEDURE = 149,                /* PROCEDURE  */
  YYSYMBOL_CALL = 150,                     /* CALL  */
  YYSYMBOL_OSP = 151,                      /* OSP  */
  YYSYMBOL_CSP = 152,                      /* CSP  */
  YYSYMBOL_SHARED = 153,                   /* SHARED  */
  YYSYMBOL_MILLISECOND = 154,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 155,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 156,                    /* TICKS  */
  YYSYMBOL_GLOBAL = 157,                   /* GLOBAL  */
  YYSYMBOL_PARAM = 158,                    /* PARAM  */
  YYSYMBOL_PRINT = 159,                    /* PRINT  */
  YYSYMBOL_DEFAULT = 160,                  /* DEFAULT  */
  YYSYMBOL_USE = 161,                      /* USE  */
  YYSYMBOL_PAPER = 162,                    /* PAPER  */
  YYSYMBOL_INVERSE = 163,                  /* INVERSE  */
  YYSYMBOL_REPLACE = 164,                  /* REPLACE  */
  YYSYMBOL_XOR = 165,                      /* XOR  */
  YYSYMBOL_IGNORE = 166,                   /* IGNORE  */
  YYSYMBOL_NORMAL = 167,                   /* NORMAL  */
  YYSYMBOL_WRITING = 168,                  /* WRITING  */
  YYSYMBOL_ONLY = 169,                     /* ONLY  */
  YYSYMBOL_LOCATE = 170,                   /* LOCATE  */
  YYSYMBOL_CLS = 171,                      /* CLS  */
  YYSYMBOL_HOME = 172,                     /* HOME  */
  YYSYMBOL_CMOVE = 173,                    /* CMOVE  */
  YYSYMBOL_CENTER = 174,                   /* CENTER  */
  YYSYMBOL_CENTRE = 175,                   /* CENTRE  */
  YYSYMBOL_TAB = 176,                      /* TAB  */
  YYSYMBOL_SET = 177,                      /* SET  */
  YYSYMBOL_CUP = 178,                      /* CUP  */
  YYSYMBOL_CDOWN = 179,                    /* CDOWN  */
  YYSYMBOL_CLEFT = 180,                    /* CLEFT  */
  YYSYMBOL_CRIGHT = 181,                   /* CRIGHT  */
  YYSYMBOL_CLINE = 182,                    /* CLINE  */
  YYSYMBOL_XCURS = 183,                    /* XCURS  */
  YYSYMBOL_YCURS = 184,                    /* YCURS  */
  YYSYMBOL_MEMORIZE = 185,                 /* MEMORIZE  */
  YYSYMBOL_REMEMBER = 186,                 /* REMEMBER  */
  YYSYMBOL_HSCROLL = 187,                  /* HSCROLL  */
  YYSYMBOL_VSCROLL = 188,                  /* VSCROLL  */
  YYSYMBOL_TEXTADDRESS = 189,              /* TEXTADDRESS  */
  YYSYMBOL_JOY = 190,                      /* JOY  */
  YYSYMBOL_BIN = 191,                      /* BIN  */
  YYSYMBOL_BIT = 192,                      /* BIT  */
  YYSYMBOL_COUNT = 193,                    /* COUNT  */
  YYSYMBOL_JOYCOUNT = 194,                 /* JOYCOUNT  */
  YYSYMBOL_FIRE = 195,                     /* FIRE  */
  YYSYMBOL_JUP = 196,                      /* JUP  */
  YYSYMBOL_JDOWN = 197,                    /* JDOWN  */
  YYSYMBOL_JLEFT = 198,                    /* JLEFT  */
  YYSYMBOL_JRIGHT = 199,                   /* JRIGHT  */
  YYSYMBOL_JFIRE = 200,                    /* JFIRE  */
  YYSYMBOL_INKEY = 201,                    /* INKEY  */
  YYSYMBOL_SCANCODE = 202,                 /* SCANCODE  */
  YYSYMBOL_SCAN = 203,                     /* SCAN  */
  YYSYMBOL_SHIFT = 204,                    /* SHIFT  */
  YYSYMBOL_SCANSHIFT = 205,                /* SCANSHIFT  */
  YYSYMBOL_BOTH = 206,                     /* BOTH  */
  YYSYMBOL_SHIFTS = 207,                   /* SHIFTS  */
  YYSYMBOL_BLACK = 208,                    /* BLACK  */
  YYSYMBOL_WHITE = 209,                    /* WHITE  */
  YYSYMBOL_RED = 210,                      /* RED  */
  YYSYMBOL_CYAN = 211,                     /* CYAN  */
  YYSYMBOL_VIOLET = 212,                   /* VIOLET  */
  YYSYMBOL_GREEN = 213,                    /* GREEN  */
  YYSYMBOL_BLUE = 214,                     /* BLUE  */
  YYSYMBOL_YELLOW = 215,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 216,                   /* ORANGE  */
  YYSYMBOL_BROWN = 217,                    /* BROWN  */
  YYSYMBOL_LIGHT = 218,                    /* LIGHT  */
  YYSYMBOL_DARK = 219,                     /* DARK  */
  YYSYMBOL_GREY = 220,                     /* GREY  */
  YYSYMBOL_GRAY = 221,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 222,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 223,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 224,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 225,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 226,                /* TURQUOISE  */
  YYSYMBOL_TAN = 227,                      /* TAN  */
  YYSYMBOL_PINK = 228,                     /* PINK  */
  YYSYMBOL_PEACH = 229,                    /* PEACH  */
  YYSYMBOL_OLIVE = 230,                    /* OLIVE  */
  YYSYMBOL_Identifier = 231,               /* Identifier  */
  YYSYMBOL_String = 232,                   /* String  */
  YYSYMBOL_Integer = 233,                  /* Integer  */
  YYSYMBOL_234_ = 234,                     /* " "  */
  YYSYMBOL_YYACCEPT = 235,                 /* $accept  */
  YYSYMBOL_expr = 236,                     /* expr  */
  YYSYMBOL_expr_math = 237,                /* expr_math  */
  YYSYMBOL_term = 238,                     /* term  */
  YYSYMBOL_modula = 239,                   /* modula  */
  YYSYMBOL_factor = 240,                   /* factor  */
  YYSYMBOL_direct_integer = 241,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 242, /* random_definition_simple  */
  YYSYMBOL_random_definition = 243,        /* random_definition  */
  YYSYMBOL_color_enumeration = 244,        /* color_enumeration  */
  YYSYMBOL_exponential = 245,              /* exponential  */
  YYSYMBOL_246_1 = 246,                    /* $@1  */
  YYSYMBOL_247_2 = 247,                    /* $@2  */
  YYSYMBOL_248_3 = 248,                    /* $@3  */
  YYSYMBOL_position = 249,                 /* position  */
  YYSYMBOL_bank_definition_simple = 250,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 251, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 252,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 253, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 254, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 255,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 256, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 257, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 258,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 259,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 260, /* color_definition_expression  */
  YYSYMBOL_color_definition = 261,         /* color_definition  */
  YYSYMBOL_milliseconds = 262,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 263,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 264, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 265,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 266, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 267, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 268,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 269, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 270, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 271,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 272, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 273, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 274,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 275,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 276, /* text_definition_expression  */
  YYSYMBOL_text_definition = 277,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 278,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 279, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 280,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 281, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 282, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 283,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 284, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 285, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 286,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 287,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 288,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 289,         /* gosub_definition  */
  YYSYMBOL_var_definition = 290,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 291,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 292, /* point_definition_expression  */
  YYSYMBOL_point_definition = 293,         /* point_definition  */
  YYSYMBOL_ink_definition = 294,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 295,       /* on_goto_definition  */
  YYSYMBOL_296_4 = 296,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 297,      /* on_gosub_definition  */
  YYSYMBOL_298_5 = 298,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 299,       /* on_proc_definition  */
  YYSYMBOL_300_6 = 300,                    /* $@6  */
  YYSYMBOL_on_definition = 301,            /* on_definition  */
  YYSYMBOL_302_7 = 302,                    /* $@7  */
  YYSYMBOL_303_8 = 303,                    /* $@8  */
  YYSYMBOL_304_9 = 304,                    /* $@9  */
  YYSYMBOL_every_definition = 305,         /* every_definition  */
  YYSYMBOL_add_definition = 306,           /* add_definition  */
  YYSYMBOL_dimensions = 307,               /* dimensions  */
  YYSYMBOL_datatype = 308,                 /* datatype  */
  YYSYMBOL_dim_definition = 309,           /* dim_definition  */
  YYSYMBOL_310_10 = 310,                   /* $@10  */
  YYSYMBOL_311_11 = 311,                   /* $@11  */
  YYSYMBOL_312_12 = 312,                   /* $@12  */
  YYSYMBOL_dim_definitions = 313,          /* dim_definitions  */
  YYSYMBOL_indexes = 314,                  /* indexes  */
  YYSYMBOL_parameters = 315,               /* parameters  */
  YYSYMBOL_parameters_expr = 316,          /* parameters_expr  */
  YYSYMBOL_values = 317,                   /* values  */
  YYSYMBOL_print_definition = 318,         /* print_definition  */
  YYSYMBOL_319_13 = 319,                   /* $@13  */
  YYSYMBOL_320_14 = 320,                   /* $@14  */
  YYSYMBOL_writing_mode_definition = 321,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 322,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 323,       /* writing_definition  */
  YYSYMBOL_locate_definition = 324,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 325,         /* cmove_definition  */
  YYSYMBOL_hscroll_definition = 326,       /* hscroll_definition  */
  YYSYMBOL_vscroll_definition = 327,       /* vscroll_definition  */
  YYSYMBOL_statement = 328,                /* statement  */
  YYSYMBOL_329_15 = 329,                   /* $@15  */
  YYSYMBOL_330_16 = 330,                   /* $@16  */
  YYSYMBOL_331_17 = 331,                   /* $@17  */
  YYSYMBOL_332_18 = 332,                   /* $@18  */
  YYSYMBOL_333_19 = 333,                   /* $@19  */
  YYSYMBOL_334_20 = 334,                   /* $@20  */
  YYSYMBOL_335_21 = 335,                   /* $@21  */
  YYSYMBOL_336_22 = 336,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 337, /* statements_no_linenumbers  */
  YYSYMBOL_338_23 = 338,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 339, /* statements_with_linenumbers  */
  YYSYMBOL_340_24 = 340,                   /* $@24  */
  YYSYMBOL_statements_complex = 341,       /* statements_complex  */
  YYSYMBOL_342_25 = 342,                   /* $@25  */
  YYSYMBOL_program = 343,                  /* program  */
  YYSYMBOL_344_26 = 344                    /* $@26  */
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
#define YYLAST   3936

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  235
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  110
/* YYNRULES -- Number of rules.  */
#define YYNRULES  524
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1020

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   489


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
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    80,    80,    81,    85,    89,    92,    95,    98,   101,
     104,   107,   113,   114,   117,   124,   125,   129,   130,   134,
     141,   142,   146,   150,   153,   156,   159,   162,   168,   173,
     176,   179,   182,   185,   188,   191,   196,   201,   205,   209,
     213,   217,   221,   225,   229,   233,   237,   241,   245,   249,
     253,   257,   261,   265,   269,   273,   277,   281,   285,   289,
     293,   297,   301,   305,   311,   311,   322,   322,   333,   336,
     339,   348,   352,   359,   363,   367,   371,   375,   379,   383,
     387,   391,   394,   397,   400,   403,   406,   409,   412,   415,
     418,   421,   424,   427,   430,   433,   436,   439,   442,   445,
     448,   451,   454,   457,   460,   463,   466,   469,   472,   475,
     478,   481,   484,   487,   490,   490,   496,   499,   502,   506,
     510,   514,   518,   522,   526,   530,   534,   538,   541,   544,
     547,   550,   553,   556,   559,   562,   565,   568,   571,   574,
     577,   580,   583,   586,   589,   592,   595,   598,   601,   604,
     607,   611,   615,   618,   622,   626,   630,   634,   638,   641,
     644,   647,   650,   653,   657,   663,   663,   666,   669,   672,
     675,   678,   681,   685,   688,   691,   694,   698,   701,   704,
     707,   711,   714,   717,   720,   726,   729,   732,   735,   738,
     743,   744,   747,   750,   755,   758,   763,   764,   767,   770,
     775,   778,   783,   784,   787,   790,   793,   798,   801,   804,
     809,   810,   813,   814,   815,   818,   821,   824,   829,   832,
     835,   841,   842,   845,   848,   851,   854,   857,   860,   863,
     866,   869,   872,   875,   878,   881,   884,   887,   892,   895,
     898,   901,   904,   907,   910,   913,   916,   919,   922,   925,
     928,   931,   934,   939,   940,   943,   946,   949,   952,   955,
     961,   964,   970,   971,   974,   979,   984,   985,   988,   991,
     996,   999,  1004,  1005,  1008,  1013,  1018,  1019,  1022,  1025,
    1028,  1033,  1036,  1042,  1043,  1046,  1049,  1052,  1055,  1058,
    1063,  1066,  1069,  1074,  1075,  1077,  1078,  1081,  1084,  1087,
    1092,  1099,  1102,  1108,  1111,  1117,  1120,  1126,  1131,  1132,
    1135,  1140,  1144,  1144,  1149,  1153,  1153,  1158,  1162,  1162,
    1167,  1167,  1170,  1170,  1173,  1173,  1178,  1181,  1184,  1189,
    1192,  1198,  1202,  1209,  1212,  1215,  1218,  1221,  1224,  1227,
    1230,  1233,  1236,  1241,  1241,  1249,  1249,  1257,  1257,  1268,
    1269,  1273,  1277,  1284,  1289,  1294,  1299,  1304,  1309,  1317,
    1322,  1327,  1332,  1337,  1342,  1347,  1351,  1358,  1362,  1369,
    1372,  1376,  1379,  1379,  1383,  1383,  1389,  1393,  1397,  1401,
    1405,  1412,  1416,  1420,  1424,  1428,  1435,  1441,  1444,  1447,
    1453,  1456,  1459,  1465,  1468,  1471,  1474,  1480,  1483,  1489,
    1490,  1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,
    1500,  1501,  1502,  1503,  1504,  1507,  1508,  1509,  1510,  1511,
    1514,  1517,  1518,  1519,  1520,  1523,  1526,  1529,  1532,  1535,
    1538,  1541,  1544,  1547,  1550,  1553,  1556,  1559,  1562,  1565,
    1568,  1571,  1574,  1577,  1580,  1583,  1583,  1588,  1591,  1594,
    1597,  1600,  1603,  1606,  1609,  1612,  1615,  1618,  1621,  1624,
    1627,  1631,  1631,  1636,  1639,  1642,  1645,  1648,  1651,  1655,
    1659,  1663,  1663,  1668,  1668,  1673,  1673,  1678,  1681,  1684,
    1687,  1690,  1691,  1694,  1697,  1700,  1703,  1706,  1709,  1710,
    1711,  1712,  1713,  1716,  1719,  1722,  1725,  1728,  1731,  1734,
    1737,  1738,  1747,  1756,  1756,  1768,  1768,  1785,  1785,  1802,
    1805,  1806,  1810,  1811,  1811,  1815,  1815,  1822,  1822,  1825,
    1826,  1827,  1828,  1832,  1832
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
  "OP_SEMICOLON", "OP_COLON", "OP_COMMA", "OP_PLUS", "OP_MINUS", "OP_INC",
  "OP_DEC", "OP_EQUAL", "OP_ASSIGN", "OP_LT", "OP_LTE", "OP_GT", "OP_GTE",
  "OP_DISEQUAL", "OP_MULTIPLICATION", "OP_DOLLAR", "OP_DIVISION", "QM",
  "HAS", "IS", "OF", "OP_HASH", "OP_POW", "RASTER", "DONE", "AT", "COLOR",
  "BORDER", "WAIT", "NEXT", "WITH", "BANK", "SPRITE", "DATA", "FROM", "OP",
  "CP", "ENABLE", "DISABLE", "HALT", "ECM", "BITMAP", "SCREEN", "ON",
  "OFF", "ROWS", "VERTICAL", "SCROLL", "VAR", "AS", "TEMPORARY", "XPEN",
  "YPEN", "PEEK", "GOTO", "HORIZONTAL", "MCM", "COMPRESS", "EXPAND",
  "LOOP", "REPEAT", "WHILE", "TEXT", "TILES", "COLORMAP", "SELECT",
  "MONOCOLOR", "MULTICOLOR", "COLLISION", "IF", "THEN", "HIT",
  "BACKGROUND", "TO", "RANDOM", "BYTE", "WORD", "POSITION", "CODE",
  "VARIABLES", "MS", "CYCLES", "S", "WIDTH", "HEIGHT", "DWORD", "PEN",
  "CLEAR", "BEG", "END", "GAMELOOP", "ENDIF", "UP", "DOWN", "LEFT",
  "RIGHT", "DEBUG", "AND", "RANDOMIZE", "GRAPHIC", "TEXTMAP", "POINT",
  "GOSUB", "RETURN", "POP", "OR", "ELSE", "NOT", "TRUE", "FALSE", "DO",
  "EXIT", "WEND", "UNTIL", "FOR", "STEP", "EVERY", "MID", "INSTR", "UPPER",
  "LOWER", "STR", "VAL", "STRING", "SPACE", "FLIP", "CHR", "ASC", "LEN",
  "MOD", "ADD", "MIN", "MAX", "SGN", "SIGNED", "ABS", "RND", "COLORS",
  "INK", "TIMER", "POWERING", "DIM", "ADDRESS", "PROC", "PROCEDURE",
  "CALL", "OSP", "CSP", "SHARED", "MILLISECOND", "MILLISECONDS", "TICKS",
  "GLOBAL", "PARAM", "PRINT", "DEFAULT", "USE", "PAPER", "INVERSE",
  "REPLACE", "XOR", "IGNORE", "NORMAL", "WRITING", "ONLY", "LOCATE", "CLS",
  "HOME", "CMOVE", "CENTER", "CENTRE", "TAB", "SET", "CUP", "CDOWN",
  "CLEFT", "CRIGHT", "CLINE", "XCURS", "YCURS", "MEMORIZE", "REMEMBER",
  "HSCROLL", "VSCROLL", "TEXTADDRESS", "JOY", "BIN", "BIT", "COUNT",
  "JOYCOUNT", "FIRE", "JUP", "JDOWN", "JLEFT", "JRIGHT", "JFIRE", "INKEY",
  "SCANCODE", "SCAN", "SHIFT", "SCANSHIFT", "BOTH", "SHIFTS", "BLACK",
  "WHITE", "RED", "CYAN", "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE",
  "BROWN", "LIGHT", "DARK", "GREY", "GRAY", "MAGENTA", "PURPLE",
  "LAVENDER", "GOLD", "TURQUOISE", "TAN", "PINK", "PEACH", "OLIVE",
  "Identifier", "String", "Integer", "\" \"", "$accept", "expr",
  "expr_math", "term", "modula", "factor", "direct_integer",
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
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489
};
#endif

#define YYPACT_NINF (-892)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-504)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -892,    53,  1002,  -892,  -892,  -156,  -143,  2855,   -17,  -892,
      52,  2418,    77,    10,  2418,  -892,    60,   204,  2855,   -98,
     -43,  -892,  -892,  -892,  1994,   126,    51,  2855,  2855,    74,
     -32,  -892,   108,   120,  2855,  2855,  -892,   161,   187,    58,
    2855,    89,   103,  -892,   -20,  -892,  2855,    36,  2206,   254,
      75,  2855,    90,    97,   105,   106,  -140,  -140,  2855,  2855,
     124,   -15,  1343,  -892,  -892,  1570,  2855,  2855,   133,  -892,
    -892,  -892,  -892,  2855,  -892,  -892,    14,   291,   326,     6,
    -892,   334,   337,   338,  -892,  -892,  -892,   112,   323,  1782,
    -892,  -892,   304,   306,   307,   190,  -892,  -892,    22,  -892,
    -892,    -4,    -2,  2855,  -892,  -892,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   327,   345,
     346,   347,   348,  -892,  -892,   349,    78,   -27,    23,   344,
     370,   371,   372,   373,   374,   375,  -892,  -892,  -892,   -18,
     357,  3491,  -892,   358,   359,   361,   364,   365,   376,  -892,
    -892,   -49,  -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,
     199,  -892,  -892,     2,  -134,  -892,  -892,  -892,  -892,  -892,
    -892,  -892,  -892,  -892,   200,    29,  -892,  -892,   285,   122,
     283,   274,   258,  -892,  -892,  -892,  2418,   388,  -892,  -892,
    -892,  2418,  2418,  2418,  -892,  -892,  -892,   186,    41,   107,
    -892,  -892,  -892,   -12,   394,    -6,    -5,    -1,     5,   391,
    -892,  -892,  -892,   245,   384,  -892,  -892,  -892,  2418,  -892,
    -892,   389,  -892,  -892,  -892,  -892,  -892,  2418,   377,   378,
    -892,  -892,  -892,    -3,  -892,    59,  -892,  -892,  -892,  -892,
    -892,  2855,  2643,  -892,  -892,   416,  -892,  -892,  -892,  2418,
    -892,  -892,  -892,  2418,   390,  -892,  -892,  -892,   353,  -892,
    -892,  -892,   280,  2855,  2855,  -892,  -892,  2418,  -892,  -892,
    -892,   392,  -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,
    2855,  2855,  -892,  -892,  -892,  -892,   420,  -892,  -892,   278,
    -892,  2855,   429,  -892,  -892,  -892,    42,   430,  -892,   287,
     288,   289,    65,   434,  -892,  -892,  -892,  -892,  -892,  -892,
    -892,  -892,  -892,  -892,  -892,   435,  -892,  2855,   436,  -892,
    2855,   441,  -892,  -892,  -892,  2855,  -892,   110,  -892,  -892,
    -892,   214,  -892,  2855,  -892,  -892,  2855,   437,  -892,  -892,
     409,    19,  1183,  -892,  1002,  1002,  -892,   411,   412,   413,
     417,   418,   419,   118,   422,  2855,  2418,  2418,  -892,  -892,
    -892,  -892,  -892,  -892,  -892,  -892,  -892,   421,  -892,  -892,
    2855,  -892,  2855,  -892,  -892,  2855,  2855,  2855,  2855,  2855,
    2855,  2855,  2855,  2855,  2855,  2855,  2855,  2855,  2855,  2855,
    2855,  2855,  3067,   424,   221,  -892,  -892,   425,  -892,  -892,
     427,   428,  -892,  -892,  -892,  -892,  -892,  2855,  -892,  2855,
    1782,   431,   432,  2855,  2855,  2855,  2855,  2855,  2855,  -892,
    -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,   433,
    -892,   439,   227,   239,  3067,  3067,  3067,  3067,  3067,  3067,
    3067,  3067,  3067,  3067,  3067,  3067,  3067,   -67,  3279,  3703,
     440,   442,  2418,  -892,  -892,   396,   398,   402,   403,  -892,
    -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,  2418,
     452,  -892,  -892,  -892,   415,   394,   453,   394,   454,   394,
     455,   394,   456,   394,  -892,  2855,   448,  -892,  -892,   252,
     257,   111,   143,  -892,  -892,  -892,   449,   394,   451,  -892,
    -892,   262,   268,   208,   226,  -892,  -892,   457,  -892,  -892,
    2418,  -892,  -892,  2418,  2418,  -892,  -892,  -892,   443,   241,
    -892,   463,  2855,  -892,  -892,  -892,  -892,  2418,  -892,  2855,
     481,   485,  -892,  -892,  2418,   423,   486,  2855,   387,   488,
    2855,  -892,  -892,  -892,  -892,  -892,  -892,   148,  -892,  -892,
     459,   476,    90,  -892,   351,  -892,  -140,   493,    19,  -140,
     -21,  -892,  2855,  -892,  2855,  -892,  -892,  -892,  -892,  -892,
    -892,  1002,  -892,  2855,   465,  2855,  2855,   468,    17,  -892,
    1183,  -892,  -892,  2855,   276,   277,   279,   281,   284,   470,
     472,   475,  -892,   477,   478,   480,   482,   483,  2855,   518,
     519,   524,   525,   494,   495,   496,   498,   527,   499,   500,
     501,   505,   506,   541,   542,   509,   510,   511,   242,   328,
     512,  2855,  2855,  2855,   513,    69,    70,  2855,  3067,   517,
     520,   521,   522,   523,   526,   529,  2855,  2855,  2855,  2855,
     283,   283,   324,   324,   324,   324,   324,   324,   324,   324,
     274,   258,   258,   368,  3703,  3703,  -892,  -892,   340,   341,
    -892,  -892,  2855,   394,  2855,   394,   530,   538,  2418,   121,
    -892,   394,  -892,   394,  -892,   394,  -892,   394,   109,  -892,
    2855,  -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,  2855,
    -892,   394,  -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,
     394,  -892,  -892,  -892,  -892,  -892,  -892,   343,   350,   356,
     362,   562,  2855,   570,   532,   534,   426,  2855,  2855,   576,
     577,  -892,   -10,   514,   363,  2855,   581,  -892,  -892,  -892,
     549,   366,   550,  -892,  2855,   367,  2855,  -892,  -140,   588,
    -892,   438,   444,  -892,  -892,  -892,  -892,  -892,  -892,  2855,
     589,   445,   595,   563,  2855,  -892,   596,  -892,  -892,  -892,
    -892,  -892,   379,   385,   393,  -892,  -892,  -892,  -892,  -892,
     565,  2855,  2855,  2855,  2855,  -892,  -892,  -892,  -892,  2855,
    -892,  -892,  -892,  -892,  -892,  2855,  2855,  -892,  -892,  -892,
    3703,   567,  -892,   568,   603,   604,  -892,  2855,  -892,  2855,
     610,   598,  -892,  -892,  -892,  -892,  -892,  -892,  2855,   471,
     583,  -892,  -892,  3703,  -892,  -892,  -892,  -892,  -892,  -892,
    -892,  -892,   397,   399,  -892,  -892,  -892,  -892,  -892,  -892,
     587,  -892,   590,  -892,   395,   123,  -892,   626,  -892,   627,
     628,  -892,   629,  -892,   630,  -892,   625,  2418,   632,  2855,
    2855,   394,  -892,   599,   600,  2855,   394,  -892,  -892,  2855,
    -892,    71,  2855,   366,   635,   602,   366,   492,   147,   497,
     502,  -892,  -140,  -892,  -892,   605,  2855,  -892,  2855,   634,
     607,  2855,  -892,  -892,  -892,  -892,   609,   611,    76,   146,
     612,   615,   617,   618,  -892,  -892,  2855,  2855,   619,   621,
     622,  -892,  -892,  -892,  -892,  -892,   446,   447,  -892,   616,
    -892,   631,  -892,  2855,   394,   638,   658,   660,  2855,  -892,
    -892,  2855,  -892,  -892,  -892,   655,   656,   633,   636,   551,
    2855,   657,   594,   639,   366,  -892,   640,  -892,   367,   668,
      19,  -892,  -892,  -892,   663,  -892,  -892,  2855,   671,   644,
    -892,  -892,  2855,  -892,  2855,  -892,  -892,  -892,  -892,  -892,
     645,   647,  -892,  -892,  -892,  -892,  -892,   458,   460,   648,
     650,   343,   350,   356,  -892,  -892,  2855,  2855,  -892,  -892,
    2855,   652,  2855,  2855,  -892,  -892,  -892,  -892,   367,   687,
    2855,  -892,  2855,  -892,   654,   659,  -892,  -892,  -892,  -892,
    -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,   683,  -892,
    -892,  -892,   367,  -892,  -892,  -892,  -892,  2855,  -892,  -892
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     523,     0,   511,     1,   510,     0,     0,     0,     0,   495,
       0,     0,   459,     0,     0,   486,     0,     0,     0,   295,
       0,   444,   448,   445,     0,     0,     0,     0,     0,     0,
     487,   442,     0,     0,     0,   437,   485,     0,     0,     0,
     492,   494,   440,   443,   450,   447,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   433,   434,     0,     0,     0,     0,   424,
     425,   426,   427,   428,   419,   420,     0,     0,     0,   507,
     515,   512,   519,   521,   524,   435,   436,     0,     0,     0,
      83,    84,     0,     0,     0,     0,   127,   128,     0,   153,
     154,   155,   156,     0,   118,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   120,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   140,   141,   142,     0,
       0,     0,   151,   157,     0,     0,     0,     0,     0,   158,
     159,     0,   161,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     0,     0,    49,    54,    55,    56,    57,
      58,    59,    62,    63,     0,    68,    72,    70,   369,     2,
      12,    15,    17,    81,    20,   417,     0,     0,   196,   197,
     400,     0,     0,     0,   210,   211,   402,     0,     0,     0,
     221,   222,   403,     0,     0,     0,     0,     0,     0,     0,
     190,   191,   399,     0,     0,   253,   254,   404,     0,   256,
     257,   258,   262,   263,   405,   285,   286,     0,     0,     0,
     293,   294,   410,     0,   488,     0,   305,   413,   301,   302,
     489,     0,     0,   268,   269,     0,   272,   273,   407,     0,
     276,   277,   408,     0,   279,   283,   284,   409,     0,   477,
     483,   484,   465,     0,     0,   509,   438,     0,   266,   267,
     406,     0,   308,   309,   411,   303,   304,   490,   493,   452,
       0,     0,   451,   454,   455,   449,     0,   327,   328,     0,
     491,     0,     0,   415,   310,   412,   343,   349,   500,   469,
     460,   470,   359,   365,   463,   464,   416,   478,   479,   480,
     379,   377,   376,   378,   380,     0,   481,     0,     0,   418,
       0,     0,   423,   431,   432,     0,   429,     0,   393,   395,
     421,     0,   422,     0,   517,   482,     0,   505,   471,   468,
       0,     0,   511,   513,   511,   511,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,    29,
      30,    32,    34,    35,    31,    36,   107,     0,   121,   122,
       0,   163,     0,   164,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   123,   126,     0,   124,   125,
       0,     0,   139,   133,   134,   135,   136,     0,   150,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   160,
     162,    60,    47,    50,    51,    52,    53,    48,    61,    69,
     114,     0,   374,   372,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   207,   204,     0,     0,     0,     0,    28,
     212,   218,   213,   214,   219,   220,   215,   216,   217,     0,
       0,   202,   203,   401,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   166,     0,     0,   243,   244,     0,
       0,     0,     0,   240,   239,   165,     0,     0,     0,   228,
     229,     0,     0,     0,     0,   225,   224,     0,   260,   255,
       0,   290,   287,     0,     0,   320,   324,   322,     0,     0,
     446,     0,     0,   275,   274,   281,   278,     0,   439,     0,
       0,     0,   265,   264,     0,     0,   453,     0,     0,     0,
       0,   341,   333,   335,   340,   337,   342,     0,   339,   347,
       0,     0,     0,   473,     0,   475,     0,   360,     0,     0,
       0,   387,   388,   390,   391,   430,   394,   396,   397,   398,
     414,   511,   501,     0,     0,     0,     0,     0,   507,   516,
     511,   520,   522,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    14,     5,     7,     8,     9,    10,     6,     3,     4,
      16,    18,    19,     0,     0,     0,    25,    21,     0,     0,
     194,   192,     0,     0,     0,     0,     0,     0,     0,     0,
     172,     0,   184,     0,   176,     0,   180,     0,   168,   241,
       0,   248,   247,   252,   251,   246,   250,   245,   249,     0,
     226,     0,   233,   232,   237,   236,   231,   235,   230,   234,
       0,   261,   259,   291,   288,   292,   289,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   441,     0,     0,     0,     0,   329,   334,   336,   338,
       0,     0,     0,   350,     0,     0,     0,   362,     0,   361,
     366,   384,   382,   381,   386,   389,   392,   518,   502,     0,
     367,     0,   351,     0,     0,   514,     0,    80,    73,    75,
      79,    77,     0,     0,     0,    82,    86,    85,    88,    87,
       0,     0,     0,     0,     0,    95,    96,    97,   106,     0,
     100,   101,   102,   103,   104,     0,     0,   116,   117,   108,
       0,     0,   112,     0,     0,     0,   143,     0,    98,     0,
       0,    27,   149,   144,   145,   146,   147,   148,     0,     0,
       0,   375,   373,     0,    23,    26,   195,   193,   209,   206,
     208,   205,     0,     0,   200,   198,   169,   182,   174,   177,
     171,   183,   175,   179,     0,     0,   238,     0,   223,     0,
     311,   321,   314,   325,   317,   323,   297,     0,     0,     0,
       0,     0,   466,     0,     0,     0,     0,   456,   457,     0,
     326,     0,     0,     0,   331,     0,     0,     0,   353,     0,
       0,   363,     0,   385,   383,     0,     0,   472,     0,     0,
       0,     0,    74,    76,    78,   130,     0,     0,     0,     0,
       0,     0,     0,     0,   113,   131,     0,     0,     0,     0,
       0,   115,    65,    24,   201,   199,     0,     0,   185,   170,
     181,   173,   178,     0,     0,     0,     0,     0,     0,   299,
     298,     0,   271,   282,   280,     0,     0,     0,     0,   458,
       0,     0,     0,     0,     0,   344,     0,   474,     0,   354,
       0,   462,   476,   364,     0,   368,   352,     0,     0,     0,
      89,    90,     0,    91,     0,    93,   105,   111,   110,    22,
       0,     0,    99,   152,    67,   187,   189,     0,     0,     0,
       0,     0,     0,     0,   300,   270,     0,     0,   307,   306,
       0,     0,     0,     0,   348,   332,   346,   356,     0,   355,
       0,   504,     0,   137,     0,     0,   138,   132,   186,   188,
     242,   227,   313,   316,   319,   496,   497,   467,     0,   498,
     330,   357,     0,   506,   508,    92,    94,     0,   358,   499
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -892,    -7,  -139,  -100,   253,  -378,   352,  -892,  -892,  -892,
    -126,  -892,  -892,  -892,   484,  -892,  -892,  -892,  -892,  -892,
    -892,  -892,  -892,  -892,  -892,  -892,  -892,   503,  -892,  -892,
    -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,
    -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,
    -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,
    -272,  -892,  -271,  -892,  -270,  -892,  -892,  -892,  -892,  -892,
    -892,  -892,  -792,  -340,  -892,  -892,  -892,  -892,   152,  -634,
    -891,   -55,  -628,   -53,  -892,  -892,  -892,  -892,  -892,  -892,
    -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,  -892,
    -892,  -892,  -333,  -892,  -892,  -892,  -313,  -892,  -892,  -892
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   752,   179,   180,   181,   182,   199,   365,   366,   183,
     184,   431,   635,   636,   496,   210,   211,   212,   188,   189,
     190,   471,   472,   473,   194,   195,   196,   465,   200,   201,
     202,   215,   216,   217,   222,   223,   224,   268,   269,   270,
     246,   247,   248,   250,   251,   252,   255,   256,   257,   230,
     231,   232,   236,   240,   277,   237,   272,   273,   274,   295,
     841,   915,   843,   916,   845,   917,   234,   707,   709,   708,
     290,   293,   865,   549,   297,   550,   551,   730,   298,   753,
     869,   304,   751,   185,   639,   638,   315,   744,   316,   319,
     322,   330,   332,    81,   241,   554,   575,   734,   736,   340,
     574,   341,    82,   580,    83,   342,    84,   571,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     178,   577,   305,   810,   198,   306,   197,   213,   809,   579,
     334,   233,   335,   186,   618,   412,   197,   245,   469,   336,
     258,   259,   407,   335,   475,   477,   337,   265,   266,   479,
     336,   581,   582,   278,   419,   481,   370,   337,   372,   285,
     204,   289,   367,   397,   294,   653,  -503,   987,   205,   429,
     541,   178,   307,     3,   281,   318,   515,  -503,   321,   323,
     324,   327,  -345,   261,   395,   206,   326,   651,   652,   -64,
     741,   933,   556,   541,   936,    85,   797,   799,   930,   518,
     426,   253,   354,   952,   191,   557,   427,   310,    86,   192,
     218,   302,   303,   207,   208,   311,   374,  1011,   393,   542,
     543,   544,   219,   220,   516,   203,   867,   519,   870,   545,
     798,   592,   931,   328,   329,   875,   262,   953,   394,   558,
     880,  1018,   542,   543,   544,   654,   460,   461,   282,   193,
     434,   435,   545,   235,   436,   396,   437,   438,   439,   440,
     441,   742,   985,   254,   834,   517,   743,   546,   263,   312,
     313,   314,   221,   954,   938,   420,   249,   338,   547,   826,
     264,   909,   685,   835,   368,   398,   548,   939,   338,   260,
     546,   686,   308,   309,   900,   408,   827,   280,   910,   450,
     430,   547,   369,   399,   453,   455,   457,   955,   238,   548,
     239,   267,   460,   466,   687,   462,   463,   464,   589,   590,
     371,   940,   373,   688,   828,   829,   911,   912,   591,   566,
     567,   508,   422,   283,   187,   423,   424,   271,   739,   470,
     511,   358,   425,   857,   442,   476,   478,  -371,   727,   728,
     480,  -371,   443,  -371,   520,   521,   482,   279,   729,  -370,
     339,   209,   523,  -370,   946,  -370,   525,   755,   945,   790,
     801,   339,   225,   226,   227,   228,   530,   531,   747,   696,
     532,   462,   463,   467,   229,   447,   448,   286,   697,   449,
     359,   360,   361,   535,   536,   484,   485,   698,   362,   363,
     364,   447,   448,   486,   539,   449,   699,   487,   488,   275,
     432,   276,   433,   445,   291,   446,   489,   642,   643,   644,
     645,   646,   647,   648,   649,   490,   292,   491,   492,   325,
     561,   568,   569,   563,   681,   682,   493,   494,   565,   683,
     684,   296,   656,   657,   692,   693,   570,   495,   299,   572,
     694,   695,   434,   435,   640,   641,   300,   301,   331,   333,
     343,   344,   345,   347,   355,   346,   356,   357,   593,   594,
     596,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   599,   400,   600,   214,   387,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   388,   389,   390,   391,   392,
     401,   402,   403,   404,   405,   406,   284,   409,   413,   414,
     624,   415,   625,   626,   416,   417,   629,   630,   631,   632,
     633,   634,   421,   428,   484,   497,   418,   444,   452,   459,
     197,   483,   498,   522,   510,   527,   499,   500,   528,   513,
     514,   529,   534,   537,   538,   501,   540,   552,   553,  -461,
     555,   559,   560,   562,   502,   660,   503,   504,   564,   576,
     573,   583,   620,   584,   585,   505,   506,   628,   586,   587,
     588,   598,   666,   592,   619,   621,   495,   622,   623,   669,
     712,   627,   711,   -66,   662,   658,   663,   659,   679,   637,
     664,   665,   668,   671,   673,   675,   677,   680,   717,   689,
     691,   710,   718,   722,   724,   725,   732,   700,   721,   731,
     738,   737,   735,   701,   740,   749,   703,   705,   754,   757,
     758,   762,   759,   763,   760,   713,   764,   761,   765,   766,
     714,   767,   716,   768,   769,   771,   772,   719,   814,   815,
     723,   773,   774,   726,   779,   775,   776,   777,   451,   778,
     780,   781,   782,   454,   456,   458,   783,   784,   785,   786,
     787,   788,   789,   792,   796,   745,   474,   746,   802,   791,
     813,   803,   804,   805,   806,   822,   748,   807,   750,   808,
     509,   816,   817,   823,   840,   847,   756,   849,   852,   512,
     850,   842,   851,   855,   856,   811,   812,   844,   862,   863,
     866,   770,   859,   846,   860,   872,   876,   877,   868,   864,
     989,   524,   878,   881,   879,   526,   885,   873,   894,   895,
     896,   897,   882,   874,   793,   794,   795,   799,   883,   533,
     800,   447,   906,   901,   902,   907,   884,   908,   904,   750,
     905,   178,   178,   913,   914,  -312,  -315,  -318,   918,   921,
     925,   926,   934,   935,   937,   971,   944,   947,   948,   941,
     950,   967,   951,   956,   942,   818,   957,   820,   958,   959,
     962,   824,   963,   964,   893,   972,   968,   973,   976,   977,
     982,   980,   983,   836,   978,   988,   990,   979,   965,   966,
     984,   986,   837,   871,   992,   993,   996,   903,   997,  1000,
     998,  1001,   999,  1008,  1012,  1015,  1017,   650,   507,  1002,
    1016,  1003,   468,  1004,   733,   848,     0,     0,   595,   597,
     853,   854,     0,     0,     0,     0,     0,     0,   861,     0,
       0,     0,     0,     0,     0,     0,     0,   750,     0,   750,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   886,   887,   888,   889,     0,     0,
       0,     0,   890,     0,     0,     0,     0,     0,   891,   892,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     898,     0,   899,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   661,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   943,     0,     0,
       0,   667,     0,     0,     0,     0,     0,   670,     0,   672,
       0,   674,     0,   676,     0,   678,     0,     0,     0,     0,
     919,     0,   922,   923,     0,     0,     0,     0,   927,   690,
       0,     0,   929,     0,     0,   932,     0,     0,     0,     0,
       0,     0,   702,     0,     0,   704,   706,     0,     0,   750,
       0,     0,     0,     0,   949,     0,     0,     0,     0,   715,
       0,     0,     0,     0,     0,     0,   720,     0,     0,   960,
     961,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   969,     0,     0,     0,
       0,   974,     0,     0,   975,     0,     0,     0,     0,     0,
       0,     0,     0,   981,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     991,     0,     0,     0,     0,   994,     0,   995,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1005,
    1006,     0,     0,  1007,     0,  1009,  1010,     0,     0,     0,
       0,     0,     0,  1013,     0,  1014,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     0,     0,     0,     0,
    1019,     0,     5,     6,     0,   819,     0,   821,     0,     0,
     825,     0,     0,   830,     7,   831,     0,   832,     0,   833,
       8,     9,     0,    10,     0,    11,    12,     0,    13,    14,
       0,     0,     0,   838,     0,     0,    15,     0,    16,    17,
      18,     0,   839,     0,     0,    19,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,    21,    22,    23,    24,
      25,    26,     0,     0,   858,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,     0,    29,    30,     0,    31,     0,
       0,    32,    33,    34,     0,    35,    36,    37,    38,    39,
      40,    41,     0,    42,     0,     0,     0,    43,    44,    45,
      46,    47,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,    52,     0,
      53,    54,    55,     0,     0,    56,     0,     0,     0,    57,
       0,    58,     0,     0,    59,    60,     0,     0,     0,     0,
      61,     0,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,    72,    73,     0,     4,    74,    75,    76,
      77,    78,     0,     5,     6,     0,     0,     0,     0,   920,
       0,     0,     0,   924,     0,     7,     0,     0,   928,     0,
       0,     8,     9,     0,    10,     0,    11,    12,     0,    13,
      14,     0,     0,     0,     0,     0,     0,    15,     0,    16,
      17,    18,     0,    79,     0,    80,    19,     0,     0,     0,
       0,     0,    20,     0,     0,     0,     0,    21,    22,    23,
      24,    25,    26,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,   970,     0,     0,     0,
       0,     0,     0,     0,    28,     0,    29,    30,     0,    31,
       0,     0,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,     0,    42,     0,     0,     0,    43,    44,
      45,    46,    47,     0,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,    51,     0,     0,    52,
       0,    53,    54,    55,     0,     0,    56,     0,     0,     0,
      57,     0,    58,     0,     0,    59,    60,     0,     0,     0,
     317,    61,    87,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,    72,    73,     0,     0,    74,    75,
      76,    77,    78,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   578,     0,    93,     0,     0,    94,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,     0,    98,     0,     0,     0,     0,     0,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,     0,     0,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,     0,   118,
     119,   120,     0,   121,   122,   123,     0,   124,   125,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,     0,   127,     0,   128,     0,     0,     0,     0,
       0,     0,     0,   129,     0,     0,   130,     0,     0,   131,
       0,   132,   133,   134,   135,     0,   136,   137,     0,     0,
       0,     0,   138,   139,   140,   141,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,   152,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   320,     0,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,    94,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
       0,    98,     0,     0,     0,     0,     0,    99,   100,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,     0,   118,   119,   120,     0,
     121,   122,   123,     0,   124,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,     0,
     127,     0,   128,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,   130,     0,     0,   131,     0,   132,   133,
     134,   135,     0,   136,   137,     0,     0,     0,     0,   138,
     139,   140,   141,     0,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,     0,   152,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    87,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,     0,     0,     0,     0,     0,
       0,     0,    88,   348,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,    94,     0,
       0,    95,   349,   350,   351,     0,     0,     0,     0,     0,
      96,    97,   352,    98,     0,     0,     0,     0,     0,    99,
     100,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,   104,   105,     0,     0,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     0,     0,   118,   119,
     120,   353,   121,   122,   123,     0,   124,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     126,     0,   127,     0,   128,     0,     0,     0,     0,     0,
       0,     0,   129,     0,     0,   130,     0,     0,   131,     0,
     132,   133,   134,   135,     0,   136,   137,     0,     0,     0,
       0,   138,   139,   140,   141,     0,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,     0,   152,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    87,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,     0,     0,     0,
       0,     0,     0,     0,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,     0,   243,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,     0,     0,
      94,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,     0,    98,     0,     0,     0,     0,
       0,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   104,   105,     0,
       0,     0,     0,     0,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,     0,     0,
     118,   119,   120,     0,   121,   122,   123,     0,   124,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,     0,   127,     0,   128,     0,     0,     0,
       0,     0,     0,     0,   129,     0,     0,   130,     0,     0,
     131,     0,   132,   133,   134,   135,     0,   136,   137,     0,
       0,     0,     0,   138,   139,   140,   141,     0,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,     0,   152,
       0,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    87,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,     0,     0,
       0,     0,     0,     0,     0,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,   287,   288,     0,     0,     0,     0,
       0,     0,    90,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
       0,     0,    94,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,     0,    98,     0,     0,
       0,     0,     0,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,   104,
     105,     0,     0,     0,     0,     0,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,     0,   118,   119,   120,     0,   121,   122,   123,     0,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,     0,   127,     0,   128,     0,
       0,     0,     0,     0,     0,     0,   129,     0,     0,   130,
       0,     0,   131,     0,   132,   133,   134,   135,     0,   136,
     137,     0,     0,     0,     0,   138,   139,   140,   141,     0,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
       0,   152,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    87,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
       0,     0,     0,     0,   197,     0,     0,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,    94,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,     0,    98,
       0,     0,     0,     0,     0,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,   104,   105,     0,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,     0,     0,   118,   119,   120,     0,   121,   122,
     123,     0,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,   127,     0,
     128,     0,     0,     0,     0,     0,     0,     0,   129,     0,
       0,   130,     0,     0,   131,     0,   132,   133,   134,   135,
       0,   136,   137,     0,     0,     0,     0,   138,   139,   140,
     141,     0,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     0,   152,     0,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,     0,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   347,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,     0,     0,    94,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,     0,    98,     0,     0,     0,     0,     0,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,     0,     0,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,     0,   118,
     119,   120,     0,   121,   122,   123,     0,   124,   125,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,     0,   127,     0,   128,     0,     0,     0,     0,
       0,     0,     0,   129,     0,     0,   130,     0,     0,   131,
       0,   132,   133,   134,   135,     0,   136,   137,     0,     0,
       0,     0,   138,   139,   140,   141,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,   152,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,    87,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,     0,     0,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,     0,
       0,    94,     0,     0,    95,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,     0,    98,     0,     0,     0,
       0,     0,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
       0,     0,     0,     0,     0,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
       0,   118,   119,   120,     0,   121,   122,   123,     0,   124,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,   127,     0,   128,     0,     0,
       0,     0,     0,     0,     0,   129,     0,     0,   130,     0,
       0,   131,     0,   132,   133,   134,   135,     0,   136,   137,
       0,     0,     0,     0,   138,   139,   140,   141,     0,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
     152,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    87,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
       0,     0,     0,     0,     0,     0,     0,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,    94,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,     0,    98,     0,
       0,     0,     0,     0,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,     0,   118,   119,   120,     0,   121,   122,   123,
       0,   124,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,     0,   127,     0,   128,
       0,     0,     0,     0,     0,     0,     0,   129,     0,     0,
     130,     0,     0,   131,     0,   132,   133,   134,   135,     0,
     136,   137,     0,     0,     0,     0,   138,   139,   140,   141,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,   152,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    87,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     0,     0,     0,     0,     0,     0,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,    94,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,     0,
      98,     0,     0,     0,     0,     0,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   655,   104,   105,     0,     0,     0,     0,     0,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,     0,   118,   119,   120,     0,   121,
     122,   123,     0,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,     0,   127,
       0,   128,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     0,   130,     0,     0,   131,     0,   132,   133,   134,
     135,     0,   136,   137,     0,     0,     0,     0,   138,   139,
     140,   411,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,   152,     0,     0,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      87,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   410,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,     0,     0,    94,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,     0,    98,     0,     0,     0,     0,     0,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,   118,   119,   120,
       0,   121,   122,   123,     0,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
       0,   127,     0,   128,     0,     0,     0,     0,     0,     0,
       0,   129,     0,     0,   130,     0,     0,   131,     0,   132,
     133,   134,   135,     0,   136,   137,     0,     0,     0,     0,
     138,   139,   140,   411,     0,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,     0,   152,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,    87,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,     0,     0,     0,     0,
       0,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,     0,     0,    94,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,     0,    98,     0,     0,     0,     0,     0,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,     0,     0,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,     0,   118,
     119,   120,     0,   121,   122,   123,     0,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,     0,   127,     0,   128,     0,     0,     0,     0,
       0,     0,     0,   129,     0,     0,   130,     0,     0,   131,
       0,   132,   133,   134,   135,     0,   136,   137,     0,     0,
       0,     0,   138,   139,   140,   411,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,     0,   152,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177
};

static const yytype_int16 yycheck[] =
{
       7,   341,    57,   637,    11,    58,    26,    14,   636,   342,
       4,    18,     6,    30,   392,   141,    26,    24,    30,    13,
      27,    28,    40,     6,    30,    30,    20,    34,    35,    30,
      13,   344,   345,    40,    83,    30,    40,    20,    40,    46,
      30,    48,    20,    20,    51,   112,    40,   938,    38,    20,
      31,    58,    59,     0,    74,    62,    59,    40,    65,    66,
      67,    47,    20,    95,    91,    55,    73,   445,   446,    40,
      91,   863,     7,    31,   866,   231,     7,     7,     7,    20,
     214,    30,    89,     7,    32,    20,   220,   102,   231,    37,
      30,   231,   232,    83,    84,   110,   103,   988,    20,    80,
      81,    82,    42,    43,   107,    28,   734,    48,   736,    90,
      41,    41,    41,    99,   100,   749,   148,    41,    40,    54,
     754,  1012,    80,    81,    82,   192,    85,    86,   148,    77,
       8,     9,    90,   231,    12,   162,    14,    15,    16,    17,
      18,   162,   934,    92,    35,   148,   167,   128,    40,   164,
     165,   166,    92,     7,     7,   204,    30,   151,   139,    38,
      40,    38,    51,    54,   142,   142,   147,    20,   151,    95,
     128,    60,    48,    49,   808,   193,    55,    74,    55,   186,
     151,   139,   160,   160,   191,   192,   193,    41,   231,   147,
     233,    30,    85,    86,    51,   154,   155,   156,    80,    81,
     204,    54,   204,    60,    83,    84,    83,    84,    90,    99,
     100,   218,   210,   233,   231,   213,   214,    30,   558,   231,
     227,    31,   220,   233,   102,   231,   231,     0,    80,    81,
     231,     4,   110,     6,   241,   242,   231,   148,    90,     0,
     234,   231,   249,     4,   878,     6,   253,   580,   876,     7,
     628,   234,    48,    49,    50,    51,   263,   264,   571,    51,
     267,   154,   155,   156,    60,    23,    24,   231,    60,    27,
      80,    81,    82,   280,   281,    30,    31,    51,    88,    89,
      90,    23,    24,    38,   291,    27,    60,    42,    43,   231,
       5,   233,     7,    19,    40,    21,    51,   436,   437,   438,
     439,   440,   441,   442,   443,    60,   231,    62,    63,   176,
     317,    97,    98,   320,    62,    63,    71,    72,   325,    62,
      63,   231,   448,   449,    62,    63,   333,    82,   231,   336,
      62,    63,     8,     9,   434,   435,   231,   231,    47,    13,
       6,     4,     4,    20,    40,   233,    40,    40,   355,   356,
     357,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,   370,    20,   372,    14,    40,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,    40,    40,    40,    40,    40,
      20,    20,    20,    20,    20,    20,    44,    40,    40,    40,
     407,    40,   409,   410,    40,    40,   413,   414,   415,   416,
     417,   418,   213,   213,    30,    31,    40,   134,    30,   233,
      26,    30,    38,     7,    35,    35,    42,    43,    75,    52,
      52,   151,    40,    13,   156,    51,     7,     7,   151,   151,
     151,     7,     7,     7,    60,   452,    62,    63,     7,    40,
      13,    40,   231,    41,    41,    71,    72,    25,    41,    41,
      41,    40,   469,    41,    40,    40,    82,    40,    40,    54,
       7,    40,   231,    40,    78,    35,    78,    35,   485,    40,
      78,    78,    30,    30,    30,    30,    30,    39,     7,    40,
      39,    48,     7,     7,   107,     7,    20,    40,    75,    40,
       7,   556,   151,   510,   559,    40,   513,   514,    40,   233,
     233,    41,   233,    41,   233,   522,    41,   233,    41,    41,
     527,    41,   529,    41,    41,     7,     7,   534,   654,   655,
     537,     7,     7,   540,     7,    41,    41,    41,   186,    41,
      41,    41,    41,   191,   192,   193,    41,    41,     7,     7,
      41,    41,    41,    41,    41,   562,   204,   564,    41,   231,
     192,    41,    41,    41,    41,    35,   573,    41,   575,    40,
     218,   231,   231,    35,   231,    13,   583,     7,   152,   227,
      48,   231,    48,     7,     7,   638,   639,   231,     7,    40,
      40,   598,    78,   231,   231,     7,     7,   152,   231,   233,
     940,   249,     7,     7,    41,   253,    41,   169,    41,    41,
       7,     7,   233,   169,   621,   622,   623,     7,   233,   267,
     627,    23,    35,   152,    41,    35,   233,   232,   231,   636,
     231,   638,   639,     7,     7,     7,     7,     7,    13,     7,
      41,    41,     7,    41,   152,     7,    41,    13,    41,   152,
      41,    35,    41,    41,   152,   662,    41,   664,    41,    41,
      41,   668,    41,    41,   790,     7,    35,     7,    13,    13,
      13,   120,    78,   680,    41,     7,    13,    41,   232,   232,
      41,    41,   689,   738,    13,    41,    41,   813,    41,    41,
     232,    41,   232,    41,     7,    41,    13,   444,   214,   971,
      41,   972,   199,   973,   552,   712,    -1,    -1,   356,   357,
     717,   718,    -1,    -1,    -1,    -1,    -1,    -1,   725,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   734,    -1,   736,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   771,   772,   773,   774,    -1,    -1,
      -1,    -1,   779,    -1,    -1,    -1,    -1,    -1,   785,   786,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     797,    -1,   799,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   452,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   872,    -1,    -1,
      -1,   469,    -1,    -1,    -1,    -1,    -1,   475,    -1,   477,
      -1,   479,    -1,   481,    -1,   483,    -1,    -1,    -1,    -1,
     847,    -1,   849,   850,    -1,    -1,    -1,    -1,   855,   497,
      -1,    -1,   859,    -1,    -1,   862,    -1,    -1,    -1,    -1,
      -1,    -1,   510,    -1,    -1,   513,   514,    -1,    -1,   876,
      -1,    -1,    -1,    -1,   881,    -1,    -1,    -1,    -1,   527,
      -1,    -1,    -1,    -1,    -1,    -1,   534,    -1,    -1,   896,
     897,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   913,    -1,    -1,    -1,
      -1,   918,    -1,    -1,   921,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   930,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     947,    -1,    -1,    -1,    -1,   952,    -1,   954,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   976,
     977,    -1,    -1,   980,    -1,   982,   983,    -1,    -1,    -1,
      -1,    -1,    -1,   990,    -1,   992,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
    1017,    -1,    10,    11,    -1,   663,    -1,   665,    -1,    -1,
     668,    -1,    -1,   671,    22,   673,    -1,   675,    -1,   677,
      28,    29,    -1,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    -1,    -1,   691,    -1,    -1,    44,    -1,    46,    47,
      48,    -1,   700,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    64,    65,    66,    67,
      68,    69,    -1,    -1,   722,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    -1,    96,    -1,
      -1,    99,   100,   101,    -1,   103,   104,   105,   106,   107,
     108,   109,    -1,   111,    -1,    -1,    -1,   115,   116,   117,
     118,   119,    -1,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,   146,    -1,
     148,   149,   150,    -1,    -1,   153,    -1,    -1,    -1,   157,
      -1,   159,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,
     168,    -1,   170,   171,   172,   173,   174,   175,    -1,   177,
     178,   179,   180,   181,   182,    -1,     3,   185,   186,   187,
     188,   189,    -1,    10,    11,    -1,    -1,    -1,    -1,   847,
      -1,    -1,    -1,   851,    -1,    22,    -1,    -1,   856,    -1,
      -1,    28,    29,    -1,    31,    -1,    33,    34,    -1,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    46,
      47,    48,    -1,   231,    -1,   233,    53,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   914,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    93,    94,    -1,    96,
      -1,    -1,    99,   100,   101,    -1,   103,   104,   105,   106,
     107,   108,   109,    -1,   111,    -1,    -1,    -1,   115,   116,
     117,   118,   119,    -1,   121,   122,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,   146,
      -1,   148,   149,   150,    -1,    -1,   153,    -1,    -1,    -1,
     157,    -1,   159,    -1,    -1,   162,   163,    -1,    -1,    -1,
       7,   168,     9,   170,   171,   172,   173,   174,   175,    -1,
     177,   178,   179,   180,   181,   182,    -1,    -1,   185,   186,
     187,   188,   189,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   231,    -1,    73,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,   136,
     137,   138,    -1,   140,   141,   142,    -1,   144,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   170,    -1,    -1,   173,    -1,    -1,   176,
      -1,   178,   179,   180,   181,    -1,   183,   184,    -1,    -1,
      -1,    -1,   189,   190,   191,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,    -1,   205,    -1,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,     7,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,
     100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,    -1,    -1,   136,   137,   138,    -1,
     140,   141,   142,    -1,   144,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,
     160,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     170,    -1,    -1,   173,    -1,    -1,   176,    -1,   178,   179,
     180,   181,    -1,   183,   184,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    -1,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,    -1,   205,    -1,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,     9,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    76,    -1,
      -1,    79,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,    -1,    -1,   136,   137,
     138,   139,   140,   141,   142,    -1,   144,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,    -1,   160,    -1,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   170,    -1,    -1,   173,    -1,    -1,   176,    -1,
     178,   179,   180,   181,    -1,   183,   184,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    -1,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    -1,   205,    -1,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,     9,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,    -1,    -1,
     136,   137,   138,    -1,   140,   141,   142,    -1,   144,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,    -1,   160,    -1,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,    -1,    -1,   173,    -1,    -1,
     176,    -1,   178,   179,   180,   181,    -1,   183,   184,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,    -1,   205,
      -1,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,     9,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    -1,    91,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
     114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      -1,    -1,   136,   137,   138,    -1,   140,   141,   142,    -1,
     144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,   173,
      -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,   183,
     184,    -1,    -1,    -1,    -1,   189,   190,   191,   192,    -1,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
      -1,   205,    -1,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,     9,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,    -1,    -1,   136,   137,   138,    -1,   140,   141,
     142,    -1,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,
      -1,   173,    -1,    -1,   176,    -1,   178,   179,   180,   181,
      -1,   183,   184,    -1,    -1,    -1,    -1,   189,   190,   191,
     192,    -1,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,    -1,   205,    -1,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,   136,
     137,   138,    -1,   140,   141,   142,    -1,   144,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   170,    -1,    -1,   173,    -1,    -1,   176,
      -1,   178,   179,   180,   181,    -1,   183,   184,    -1,    -1,
      -1,    -1,   189,   190,   191,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,    -1,   205,    -1,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,     9,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,    -1,
      -1,   136,   137,   138,    -1,   140,   141,   142,    -1,   144,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,   173,    -1,
      -1,   176,    -1,   178,   179,   180,   181,    -1,   183,   184,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,    -1,
     205,    -1,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,     9,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    -1,    -1,   136,   137,   138,    -1,   140,   141,   142,
      -1,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,
     173,    -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,
     183,   184,    -1,    -1,    -1,    -1,   189,   190,   191,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,    -1,   205,    -1,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,     9,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    -1,    -1,   136,   137,   138,    -1,   140,
     141,   142,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,   160,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,
      -1,    -1,   173,    -1,    -1,   176,    -1,   178,   179,   180,
     181,    -1,   183,   184,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,    -1,   205,    -1,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
       9,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    -1,    91,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    -1,    -1,   136,   137,   138,
      -1,   140,   141,   142,    -1,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
      -1,   160,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   170,    -1,    -1,   173,    -1,    -1,   176,    -1,   178,
     179,   180,   181,    -1,   183,   184,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,    -1,   205,    -1,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,     9,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    -1,    -1,   136,
     137,   138,    -1,   140,   141,   142,    -1,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   170,    -1,    -1,   173,    -1,    -1,   176,
      -1,   178,   179,   180,   181,    -1,   183,   184,    -1,    -1,
      -1,    -1,   189,   190,   191,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,    -1,   205,    -1,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   343,   344,     0,     3,    10,    11,    22,    28,    29,
      31,    33,    34,    36,    37,    44,    46,    47,    48,    53,
      59,    64,    65,    66,    67,    68,    69,    74,    91,    93,
      94,    96,    99,   100,   101,   103,   104,   105,   106,   107,
     108,   109,   111,   115,   116,   117,   118,   119,   121,   122,
     135,   143,   146,   148,   149,   150,   153,   157,   159,   162,
     163,   168,   170,   171,   172,   173,   174,   175,   177,   178,
     179,   180,   181,   182,   185,   186,   187,   188,   189,   231,
     233,   328,   337,   339,   341,   231,   231,     9,    30,    40,
      56,    57,    58,    73,    76,    79,    88,    89,    91,    97,
      98,    99,   100,   112,   113,   114,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   136,   137,
     138,   140,   141,   142,   144,   145,   158,   160,   162,   170,
     173,   176,   178,   179,   180,   181,   183,   184,   189,   190,
     191,   192,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   205,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   236,   237,
     238,   239,   240,   244,   245,   318,    30,   231,   253,   254,
     255,    32,    37,    77,   259,   260,   261,    26,   236,   241,
     263,   264,   265,    28,    30,    38,    55,    83,    84,   231,
     250,   251,   252,   236,   241,   266,   267,   268,    30,    42,
      43,    92,   269,   270,   271,    48,    49,    50,    51,    60,
     284,   285,   286,   236,   301,   231,   287,   290,   231,   233,
     288,   329,    30,    42,    43,   236,   275,   276,   277,    30,
     278,   279,   280,    30,    92,   281,   282,   283,   236,   236,
      95,    95,   148,    40,    40,   236,   236,    30,   272,   273,
     274,    30,   291,   292,   293,   231,   233,   289,   236,   148,
      74,    74,   148,   233,   241,   236,   231,    48,    49,   236,
     305,    40,   231,   306,   236,   294,   231,   309,   313,   231,
     231,   231,   231,   232,   316,   316,   318,   236,    48,    49,
     102,   110,   164,   165,   166,   321,   323,     7,   236,   324,
       7,   236,   325,   236,   236,   176,   236,    47,    99,   100,
     326,    47,   327,    13,     4,     6,    13,    20,   151,   234,
     334,   336,   340,     6,     4,     4,   233,    20,    31,    80,
      81,    82,    90,   139,   236,    40,    40,    40,    31,    80,
      81,    82,    88,    89,    90,   242,   243,    20,   142,   160,
      40,   204,    40,   204,   236,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    20,    40,    91,   162,    20,   142,   160,
      20,    20,    20,    20,    20,    20,    20,    40,   193,    40,
      40,   192,   245,    40,    40,    40,    40,    40,    40,    83,
     204,   213,   210,   213,   214,   220,   214,   220,   213,    20,
     151,   246,     5,     7,     8,     9,    12,    14,    15,    16,
      17,    18,   102,   110,   134,    19,    21,    23,    24,    27,
     236,   241,    30,   236,   241,   236,   241,   236,   241,   233,
      85,    86,   154,   155,   156,   262,    86,   156,   262,    30,
     231,   256,   257,   258,   241,    30,   231,    30,   231,    30,
     231,    30,   231,    30,    30,    31,    38,    42,    43,    51,
      60,    62,    63,    71,    72,    82,   249,    31,    38,    42,
      43,    51,    60,    62,    63,    71,    72,   249,   236,   241,
      35,   236,   241,    52,    52,    59,   107,   148,    20,    48,
     236,   236,     7,   236,   241,   236,   241,    35,    75,   151,
     236,   236,   236,   241,    40,   236,   236,    13,   156,   236,
       7,    31,    80,    81,    82,    90,   128,   139,   147,   308,
     310,   311,     7,   151,   330,   151,     7,    20,    54,     7,
       7,   236,     7,   236,     7,   236,    99,   100,    97,    98,
     236,   342,   236,    13,   335,   331,    40,   308,   231,   337,
     338,   341,   341,    40,    41,    41,    41,    41,    41,    80,
      81,    90,    41,   236,   236,   241,   236,   241,    40,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   240,    40,
     231,    40,    40,    40,   236,   236,   236,    40,    25,   236,
     236,   236,   236,   236,   236,   247,   248,    40,   320,   319,
     238,   238,   237,   237,   237,   237,   237,   237,   237,   237,
     239,   240,   240,   112,   192,   112,   245,   245,    35,    35,
     236,   241,    78,    78,    78,    78,   236,   241,    30,    54,
     241,    30,   241,    30,   241,    30,   241,    30,   241,   236,
      39,    62,    63,    62,    63,    51,    60,    51,    60,    40,
     241,    39,    62,    63,    62,    63,    51,    60,    51,    60,
      40,   236,   241,   236,   241,   236,   241,   302,   304,   303,
      48,   231,     7,   236,   236,   241,   236,     7,     7,   236,
     241,    75,     7,   236,   107,     7,   236,    80,    81,    90,
     312,    40,    20,   313,   332,   151,   333,   316,     7,   308,
     316,    91,   162,   167,   322,   236,   236,   341,   236,    40,
     236,   317,   236,   314,    40,   337,   236,   233,   233,   233,
     233,   233,    41,    41,    41,    41,    41,    41,    41,    41,
     236,     7,     7,     7,     7,    41,    41,    41,    41,     7,
      41,    41,    41,    41,    41,     7,     7,    41,    41,    41,
       7,   231,    41,   236,   236,   236,    41,     7,    41,     7,
     236,   240,    41,    41,    41,    41,    41,    41,    40,   317,
     314,   318,   318,   192,   245,   245,   231,   231,   236,   241,
     236,   241,    35,    35,   236,   241,    38,    55,    83,    84,
     241,   241,   241,   241,    35,    54,   236,   236,   241,   241,
     231,   295,   231,   297,   231,   299,   231,    13,   236,     7,
      48,    48,   152,   236,   236,     7,     7,   233,   241,    78,
     231,   236,     7,    40,   233,   307,    40,   317,   231,   315,
     317,   316,     7,   169,   169,   314,     7,   152,     7,    41,
     314,     7,   233,   233,   233,    41,   236,   236,   236,   236,
     236,   236,   236,   245,    41,    41,     7,     7,   236,   236,
     314,   152,    41,   245,   231,   231,    35,    35,   232,    38,
      55,    83,    84,     7,     7,   296,   298,   300,    13,   236,
     241,     7,   236,   236,   241,    41,    41,   236,   241,   236,
       7,    41,   236,   307,     7,    41,   307,   152,     7,    20,
      54,   152,   152,   316,    41,   317,   314,    13,    41,   236,
      41,    41,     7,    41,     7,    41,    41,    41,    41,    41,
     236,   236,    41,    41,    41,   232,   232,    35,    35,   236,
     241,     7,     7,     7,   236,   236,    13,    13,    41,    41,
     120,   236,    13,    78,    41,   307,    41,   315,     7,   308,
      13,   236,    13,    41,   236,   236,    41,    41,   232,   232,
      41,    41,   295,   297,   299,   236,   236,   236,    41,   236,
     236,   315,     7,   236,   236,    41,    41,    13,   315,   236
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   235,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   237,   237,   237,   238,   238,   239,   239,   239,
     240,   240,   240,   240,   240,   240,   240,   240,   241,   242,
     242,   242,   242,   242,   242,   242,   243,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   246,   245,   247,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   248,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   249,   249,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   251,   251,   251,   251,   251,
     252,   252,   253,   253,   254,   254,   255,   255,   256,   256,
     257,   257,   258,   258,   259,   259,   259,   260,   260,   260,
     261,   261,   262,   262,   262,   263,   263,   263,   264,   264,
     264,   265,   265,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   268,   268,   269,   269,   269,   269,   269,
     270,   270,   271,   271,   272,   273,   274,   274,   275,   275,
     276,   276,   277,   277,   278,   279,   280,   280,   281,   281,
     281,   282,   282,   283,   283,   284,   284,   284,   284,   284,
     285,   285,   285,   286,   286,   287,   287,   287,   287,   287,
     287,   288,   288,   289,   289,   290,   291,   292,   293,   293,
     294,   295,   296,   295,   297,   298,   297,   299,   300,   299,
     302,   301,   303,   301,   304,   301,   305,   305,   305,   306,
     306,   307,   307,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   310,   309,   311,   309,   312,   309,   313,
     313,   314,   314,   315,   315,   315,   315,   315,   315,   316,
     316,   316,   316,   316,   316,   316,   316,   317,   317,   318,
     318,   318,   319,   318,   320,   318,   321,   321,   321,   321,
     321,   322,   322,   322,   322,   322,   323,   324,   324,   324,
     325,   325,   325,   326,   326,   326,   326,   327,   327,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   329,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   330,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   331,   328,   332,   328,   333,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   334,   328,   335,   328,   336,   328,   328,
     328,   328,   337,   338,   337,   340,   339,   342,   341,   341,
     341,   341,   341,   344,   343
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     3,     3,     1,     3,     1,     3,     3,
       1,     3,     6,     4,     5,     3,     4,     4,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     0,     5,     0,     6,     1,     2,
       1,     2,     1,     4,     5,     4,     5,     4,     5,     4,
       4,     1,     4,     1,     1,     4,     4,     4,     4,     6,
       6,     6,     8,     6,     8,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     6,     4,     2,     4,     3,
       6,     6,     4,     5,     0,     5,     4,     4,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       5,     5,     7,     2,     2,     2,     2,     7,     7,     2,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       2,     1,     6,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     2,     2,     1,     1,     2,     3,     4,
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
       6,     5,     1,     1,     2,     2,     1,     1,     2,     1,
       5,     2,     5,     1,     1,     1,     1,     2,     3,     3,
       2,     3,     3,     1,     1,     0,     3,     4,     5,     5,
       6,     1,     1,     1,     1,     1,     6,     6,     1,     1,
       1,     1,     0,     4,     1,     0,     4,     1,     0,     4,
       0,     4,     0,     4,     0,     4,     4,     1,     1,     3,
       7,     1,     3,     1,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     0,     5,     0,     6,     0,     6,     1,
       3,     1,     3,     1,     2,     3,     3,     4,     5,     1,
       2,     3,     3,     4,     5,     1,     3,     1,     3,     1,
       2,     2,     0,     4,     0,     4,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     3,     2,     2,     3,
       2,     2,     3,     1,     2,     1,     2,     2,     2,     2,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     2,     2,     2,     2,     1,
       1,     2,     2,     2,     1,     1,     1,     1,     1,     2,
       3,     2,     2,     1,     1,     2,     2,     1,     2,     3,
       1,     4,     1,     1,     1,     0,     3,     1,     1,     2,
       1,     2,     2,     3,     2,     2,     5,     5,     6,     1,
       2,     0,     6,     2,     2,     2,     5,     8,     2,     2,
       2,     0,     5,     0,     6,     0,     6,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     2,     2,
       2,     2,     1,     2,     1,     1,     8,     8,     8,    10,
       2,     3,     4,     0,     7,     0,     8,     0,     8,     2,
       1,     0,     1,     0,     4,     0,     3,     0,     4,     1,
       3,     1,     3,     0,     2
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
#line 81 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3148 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 85 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3157 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math OP_EQUAL expr_math  */
#line 89 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3165 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math OP_DISEQUAL expr_math  */
#line 92 "src/ugbc.y"
                                      {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3173 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math OP_LT expr_math  */
#line 95 "src/ugbc.y"
                                {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3181 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math OP_LTE expr_math  */
#line 98 "src/ugbc.y"
                                 {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 3189 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math OP_GT expr_math  */
#line 101 "src/ugbc.y"
                                {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3197 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math OP_GTE expr_math  */
#line 104 "src/ugbc.y"
                                 {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3205 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 107 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 3213 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math OP_PLUS term  */
#line 114 "src/ugbc.y"
                             {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3221 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math OP_MINUS term  */
#line 117 "src/ugbc.y"
                              {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3230 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula OP_MULTIPLICATION factor  */
#line 130 "src/ugbc.y"
                                      {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3239 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula OP_DIVISION factor  */
#line 134 "src/ugbc.y"
                                {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3248 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor OP_POW exponential  */
#line 142 "src/ugbc.y"
                                  {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 3257 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor OP_COMMA exponential CP  */
#line 146 "src/ugbc.y"
                                                   {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 3266 "src-generated/ugbc.tab.c"
    break;

  case 23: /* factor: factor HAS BIT exponential  */
#line 150 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[0].string) )->name;
      }
#line 3274 "src-generated/ugbc.tab.c"
    break;

  case 24: /* factor: factor HAS NOT BIT exponential  */
#line 153 "src/ugbc.y"
                                       {
        (yyval.string) = variable_not( _environment, variable_bit( _environment, (yyvsp[-4].string), (yyvsp[0].string) )->name )->name;
      }
#line 3282 "src-generated/ugbc.tab.c"
    break;

  case 25: /* factor: factor IS exponential  */
#line 156 "src/ugbc.y"
                              {
        (yyval.string) = variable_bit( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
      }
#line 3290 "src-generated/ugbc.tab.c"
    break;

  case 26: /* factor: factor IS NOT exponential  */
#line 159 "src/ugbc.y"
                                  {
        (yyval.string) = variable_not( _environment, variable_bit( _environment, (yyvsp[-3].string), (yyvsp[0].string) )->name )->name;
      }
#line 3298 "src-generated/ugbc.tab.c"
    break;

  case 27: /* factor: BIT exponential OF factor  */
#line 162 "src/ugbc.y"
                                  {
        (yyval.string) = variable_bit( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
      }
#line 3306 "src-generated/ugbc.tab.c"
    break;

  case 28: /* direct_integer: OP_HASH Integer  */
#line 168 "src/ugbc.y"
                    {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3314 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: BYTE  */
#line 173 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3322 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: WORD  */
#line 176 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3330 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition_simple: DWORD  */
#line 179 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3338 "src-generated/ugbc.tab.c"
    break;

  case 32: /* random_definition_simple: POSITION  */
#line 182 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3346 "src-generated/ugbc.tab.c"
    break;

  case 33: /* random_definition_simple: COLOR  */
#line 185 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3354 "src-generated/ugbc.tab.c"
    break;

  case 34: /* random_definition_simple: WIDTH  */
#line 188 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3362 "src-generated/ugbc.tab.c"
    break;

  case 35: /* random_definition_simple: HEIGHT  */
#line 191 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3370 "src-generated/ugbc.tab.c"
    break;

  case 36: /* random_definition: random_definition_simple  */
#line 196 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3378 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: BLACK  */
#line 201 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3387 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: WHITE  */
#line 205 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3396 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: RED  */
#line 209 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3405 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: CYAN  */
#line 213 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3414 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: VIOLET  */
#line 217 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3423 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: GREEN  */
#line 221 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3432 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: BLUE  */
#line 225 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3441 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: YELLOW  */
#line 229 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3450 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: ORANGE  */
#line 233 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3459 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: BROWN  */
#line 237 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3468 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT RED  */
#line 241 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3477 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK GREY  */
#line 245 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3486 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: GREY  */
#line 249 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3495 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: LIGHT GREEN  */
#line 253 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3504 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LIGHT BLUE  */
#line 257 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3513 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: LIGHT GREY  */
#line 261 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3522 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: DARK BLUE  */
#line 265 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3531 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: MAGENTA  */
#line 269 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3540 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: PURPLE  */
#line 273 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3549 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: LAVENDER  */
#line 277 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3558 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: GOLD  */
#line 281 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3567 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: TURQUOISE  */
#line 285 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3576 "src-generated/ugbc.tab.c"
    break;

  case 59: /* color_enumeration: TAN  */
#line 289 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3585 "src-generated/ugbc.tab.c"
    break;

  case 60: /* color_enumeration: YELLOW GREEN  */
#line 293 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3594 "src-generated/ugbc.tab.c"
    break;

  case 61: /* color_enumeration: OLIVE GREEN  */
#line 297 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3603 "src-generated/ugbc.tab.c"
    break;

  case 62: /* color_enumeration: PINK  */
#line 301 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3612 "src-generated/ugbc.tab.c"
    break;

  case 63: /* color_enumeration: PEACH  */
#line 305 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3621 "src-generated/ugbc.tab.c"
    break;

  case 64: /* $@1: %empty  */
#line 311 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3630 "src-generated/ugbc.tab.c"
    break;

  case 65: /* exponential: Identifier $@1 OP indexes CP  */
#line 315 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-4].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-4].string) )->name;
    }
#line 3642 "src-generated/ugbc.tab.c"
    break;

  case 66: /* $@2: %empty  */
#line 322 "src/ugbc.y"
                           {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3651 "src-generated/ugbc.tab.c"
    break;

  case 67: /* exponential: Identifier OP_DOLLAR $@2 OP indexes CP  */
#line 326 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-5].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-5].string) )->name;
    }
#line 3663 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: Identifier  */
#line 333 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3671 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: Identifier OP_DOLLAR  */
#line 336 "src/ugbc.y"
                           { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3679 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: Integer  */
#line 339 "src/ugbc.y"
              { 
        if ( (yyvsp[0].integer) < 0 ) {
            (yyval.string) = variable_temporary( _environment, VT_SWORD, "(signed integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        } else {
            (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        }
      }
#line 3693 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: OP_MINUS Integer  */
#line 348 "src/ugbc.y"
                       { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3702 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: String  */
#line 352 "src/ugbc.y"
             { 
        outline1("; (expr string: \"%s\")", (yyvsp[0].string) );
        (yyval.string) = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", (yyval.string) );
        variable_store_string( _environment, (yyval.string), (yyvsp[0].string) );
        outline2("; variable stored: %s = %s", (yyval.string), (yyvsp[0].string) );
      }
#line 3714 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP BYTE CP Integer  */
#line 359 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3723 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP SIGNED BYTE CP Integer  */
#line 363 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3732 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP WORD CP Integer  */
#line 367 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3741 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: OP SIGNED WORD CP Integer  */
#line 371 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3750 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: OP DWORD CP Integer  */
#line 375 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3759 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: OP SIGNED DWORD CP Integer  */
#line 379 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3768 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: OP POSITION CP Integer  */
#line 383 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3777 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: OP COLOR CP Integer  */
#line 387 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3786 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: color_enumeration  */
#line 391 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3794 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: PEEK OP expr CP  */
#line 394 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3802 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: XPEN  */
#line 397 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3810 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: YPEN  */
#line 400 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3818 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: COLLISION OP direct_integer CP  */
#line 403 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3826 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: COLLISION OP expr CP  */
#line 406 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3834 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: HIT OP direct_integer CP  */
#line 409 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3842 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: HIT OP expr CP  */
#line 412 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3850 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: LEFT OP expr OP_COMMA expr CP  */
#line 415 "src/ugbc.y"
                                    {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3858 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: RIGHT OP expr OP_COMMA expr CP  */
#line 418 "src/ugbc.y"
                                     {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3866 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: MID OP expr OP_COMMA expr CP  */
#line 421 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3874 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: MID OP expr OP_COMMA expr OP_COMMA expr CP  */
#line 424 "src/ugbc.y"
                                                 {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3882 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: INSTR OP expr OP_COMMA expr CP  */
#line 427 "src/ugbc.y"
                                     {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3890 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: INSTR OP expr OP_COMMA expr OP_COMMA expr CP  */
#line 430 "src/ugbc.y"
                                                   {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3898 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: UPPER OP expr CP  */
#line 433 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3906 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: LOWER OP expr CP  */
#line 436 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3914 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: STR OP expr CP  */
#line 439 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3922 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: BIN OP expr CP  */
#line 442 "src/ugbc.y"
                     {
        (yyval.string) = variable_bin( _environment, (yyvsp[-1].string), NULL )->name;
    }
#line 3930 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: BIN OP expr OP_COMMA expr CP  */
#line 445 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bin( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3938 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: SPACE OP expr CP  */
#line 448 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3946 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: FLIP OP expr CP  */
#line 451 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3954 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: CHR OP expr CP  */
#line 454 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3962 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: ASC OP expr CP  */
#line 457 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3970 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: LEN OP expr CP  */
#line 460 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3978 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: STRING OP expr OP_COMMA expr CP  */
#line 463 "src/ugbc.y"
                                      {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3986 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: VAL OP expr CP  */
#line 466 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3994 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: RANDOM random_definition  */
#line 469 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 4002 "src-generated/ugbc.tab.c"
    break;

  case 108: /* exponential: RND OP expr CP  */
#line 472 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 4010 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: OP expr CP  */
#line 475 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 4018 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: MAX OP expr OP_COMMA expr CP  */
#line 478 "src/ugbc.y"
                                   {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4026 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: MIN OP expr OP_COMMA expr CP  */
#line 481 "src/ugbc.y"
                                   {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4034 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: PARAM OP Identifier CP  */
#line 484 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 4042 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: PARAM OP_DOLLAR OP Identifier CP  */
#line 487 "src/ugbc.y"
                                       {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 4050 "src-generated/ugbc.tab.c"
    break;

  case 114: /* $@3: %empty  */
#line 490 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 4058 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: Identifier OSP $@3 values CSP  */
#line 492 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 4067 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: SGN OP expr CP  */
#line 496 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 4075 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: ABS OP expr CP  */
#line 499 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 4083 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: TRUE  */
#line 502 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 4092 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: FALSE  */
#line 506 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 4101 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: COLORS  */
#line 510 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 4110 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: PEN COLORS  */
#line 514 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 4119 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: PEN DEFAULT  */
#line 518 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 4128 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: DEFAULT PEN  */
#line 522 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 4137 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PAPER COLORS  */
#line 526 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 4146 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER DEFAULT  */
#line 530 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 4155 "src-generated/ugbc.tab.c"
    break;

  case 126: /* exponential: DEFAULT PAPER  */
#line 534 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 4164 "src-generated/ugbc.tab.c"
    break;

  case 127: /* exponential: WIDTH  */
#line 538 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 4172 "src-generated/ugbc.tab.c"
    break;

  case 128: /* exponential: HEIGHT  */
#line 541 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 4180 "src-generated/ugbc.tab.c"
    break;

  case 129: /* exponential: TIMER  */
#line 544 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 4188 "src-generated/ugbc.tab.c"
    break;

  case 130: /* exponential: PEN OP_DOLLAR OP expr CP  */
#line 547 "src/ugbc.y"
                               {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 4196 "src-generated/ugbc.tab.c"
    break;

  case 131: /* exponential: PAPER OP_DOLLAR OP expr CP  */
#line 550 "src/ugbc.y"
                                 {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 4204 "src-generated/ugbc.tab.c"
    break;

  case 132: /* exponential: CMOVE OP_DOLLAR OP expr OP_COMMA expr CP  */
#line 553 "src/ugbc.y"
                                               {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4212 "src-generated/ugbc.tab.c"
    break;

  case 133: /* exponential: CUP OP_DOLLAR  */
#line 556 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 4220 "src-generated/ugbc.tab.c"
    break;

  case 134: /* exponential: CDOWN OP_DOLLAR  */
#line 559 "src/ugbc.y"
                      {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 4228 "src-generated/ugbc.tab.c"
    break;

  case 135: /* exponential: CLEFT OP_DOLLAR  */
#line 562 "src/ugbc.y"
                      {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 4236 "src-generated/ugbc.tab.c"
    break;

  case 136: /* exponential: CRIGHT OP_DOLLAR  */
#line 565 "src/ugbc.y"
                       {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 4244 "src-generated/ugbc.tab.c"
    break;

  case 137: /* exponential: AT OP_DOLLAR OP expr OP_COMMA expr CP  */
#line 568 "src/ugbc.y"
                                            {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4252 "src-generated/ugbc.tab.c"
    break;

  case 138: /* exponential: LOCATE OP_DOLLAR OP expr OP_COMMA expr CP  */
#line 571 "src/ugbc.y"
                                                {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4260 "src-generated/ugbc.tab.c"
    break;

  case 139: /* exponential: TAB OP_DOLLAR  */
#line 574 "src/ugbc.y"
                    {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 4268 "src-generated/ugbc.tab.c"
    break;

  case 140: /* exponential: XCURS  */
#line 577 "src/ugbc.y"
            {
        (yyval.string) = text_get_xcurs( _environment )->name;
    }
#line 4276 "src-generated/ugbc.tab.c"
    break;

  case 141: /* exponential: YCURS  */
#line 580 "src/ugbc.y"
            {
        (yyval.string) = text_get_ycurs( _environment )->name;
    }
#line 4284 "src-generated/ugbc.tab.c"
    break;

  case 142: /* exponential: TEXTADDRESS  */
#line 583 "src/ugbc.y"
                  {
        (yyval.string) = strdup( "TEXTADDRESS" );
    }
#line 4292 "src-generated/ugbc.tab.c"
    break;

  case 143: /* exponential: JOY OP expr CP  */
#line 586 "src/ugbc.y"
                     {
        (yyval.string) = joy( _environment, (yyvsp[-1].string) )->name;
    }
#line 4300 "src-generated/ugbc.tab.c"
    break;

  case 144: /* exponential: JUP OP expr CP  */
#line 589 "src/ugbc.y"
                     {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_UP )->name;
    }
#line 4308 "src-generated/ugbc.tab.c"
    break;

  case 145: /* exponential: JDOWN OP expr CP  */
#line 592 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_DOWN )->name;
    }
#line 4316 "src-generated/ugbc.tab.c"
    break;

  case 146: /* exponential: JLEFT OP expr CP  */
#line 595 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_LEFT )->name;
    }
#line 4324 "src-generated/ugbc.tab.c"
    break;

  case 147: /* exponential: JRIGHT OP expr CP  */
#line 598 "src/ugbc.y"
                        {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_RIGHT )->name;
    }
#line 4332 "src-generated/ugbc.tab.c"
    break;

  case 148: /* exponential: JFIRE OP expr CP  */
#line 601 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_FIRE )->name;
    }
#line 4340 "src-generated/ugbc.tab.c"
    break;

  case 149: /* exponential: FIRE OP expr CP  */
#line 604 "src/ugbc.y"
                      {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_FIRE )->name;
    }
#line 4348 "src-generated/ugbc.tab.c"
    break;

  case 150: /* exponential: JOY COUNT  */
#line 607 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, (yyval.string), JOY_COUNT );
    }
#line 4357 "src-generated/ugbc.tab.c"
    break;

  case 151: /* exponential: JOYCOUNT  */
#line 611 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, (yyval.string), JOY_COUNT );
    }
#line 4366 "src-generated/ugbc.tab.c"
    break;

  case 152: /* exponential: BIT OP expr OP_COMMA expr CP  */
#line 615 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4374 "src-generated/ugbc.tab.c"
    break;

  case 153: /* exponential: UP  */
#line 618 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(UP)" )->name;
        variable_store( _environment, (yyval.string), JOY_UP );
    }
#line 4383 "src-generated/ugbc.tab.c"
    break;

  case 154: /* exponential: DOWN  */
#line 622 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(DOWN)" )->name;
        variable_store( _environment, (yyval.string), JOY_DOWN );
    }
#line 4392 "src-generated/ugbc.tab.c"
    break;

  case 155: /* exponential: LEFT  */
#line 626 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(LEFT)" )->name;
        variable_store( _environment, (yyval.string), JOY_LEFT );
    }
#line 4401 "src-generated/ugbc.tab.c"
    break;

  case 156: /* exponential: RIGHT  */
#line 630 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(RIGHT)" )->name;
        variable_store( _environment, (yyval.string), JOY_RIGHT );
    }
#line 4410 "src-generated/ugbc.tab.c"
    break;

  case 157: /* exponential: FIRE  */
#line 634 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(FIRE)" )->name;
        variable_store( _environment, (yyval.string), JOY_FIRE );
    }
#line 4419 "src-generated/ugbc.tab.c"
    break;

  case 158: /* exponential: INKEY  */
#line 638 "src/ugbc.y"
            {
        (yyval.string) = inkey( _environment )->name;
    }
#line 4427 "src-generated/ugbc.tab.c"
    break;

  case 159: /* exponential: SCANCODE  */
#line 641 "src/ugbc.y"
               {
        (yyval.string) = scancode( _environment )->name;
    }
#line 4435 "src-generated/ugbc.tab.c"
    break;

  case 160: /* exponential: SCAN CODE  */
#line 644 "src/ugbc.y"
                {
        (yyval.string) = scancode( _environment )->name;
    }
#line 4443 "src-generated/ugbc.tab.c"
    break;

  case 161: /* exponential: SCANSHIFT  */
#line 647 "src/ugbc.y"
                {
        (yyval.string) = scanshift( _environment )->name;
    }
#line 4451 "src-generated/ugbc.tab.c"
    break;

  case 162: /* exponential: SCAN SHIFT  */
#line 650 "src/ugbc.y"
                 {
        (yyval.string) = scanshift( _environment )->name;
    }
#line 4459 "src-generated/ugbc.tab.c"
    break;

  case 163: /* exponential: LEFT SHIFT  */
#line 653 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_LEFT );
    }
#line 4468 "src-generated/ugbc.tab.c"
    break;

  case 164: /* exponential: RIGHT SHIFT  */
#line 657 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_RIGHT );
    }
#line 4477 "src-generated/ugbc.tab.c"
    break;

  case 167: /* bank_definition_simple: AT direct_integer  */
#line 666 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4485 "src-generated/ugbc.tab.c"
    break;

  case 168: /* bank_definition_simple: Identifier AT direct_integer  */
#line 669 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4493 "src-generated/ugbc.tab.c"
    break;

  case 169: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 672 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4501 "src-generated/ugbc.tab.c"
    break;

  case 170: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 675 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4509 "src-generated/ugbc.tab.c"
    break;

  case 171: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 678 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4517 "src-generated/ugbc.tab.c"
    break;

  case 172: /* bank_definition_simple: DATA AT direct_integer  */
#line 681 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4525 "src-generated/ugbc.tab.c"
    break;

  case 173: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 685 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4533 "src-generated/ugbc.tab.c"
    break;

  case 174: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 688 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4541 "src-generated/ugbc.tab.c"
    break;

  case 175: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 691 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4549 "src-generated/ugbc.tab.c"
    break;

  case 176: /* bank_definition_simple: CODE AT direct_integer  */
#line 694 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4557 "src-generated/ugbc.tab.c"
    break;

  case 177: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 698 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4565 "src-generated/ugbc.tab.c"
    break;

  case 178: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 701 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4573 "src-generated/ugbc.tab.c"
    break;

  case 179: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 704 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4581 "src-generated/ugbc.tab.c"
    break;

  case 180: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 707 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4589 "src-generated/ugbc.tab.c"
    break;

  case 181: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 711 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4597 "src-generated/ugbc.tab.c"
    break;

  case 182: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 714 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4605 "src-generated/ugbc.tab.c"
    break;

  case 183: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 717 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4613 "src-generated/ugbc.tab.c"
    break;

  case 184: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 720 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4621 "src-generated/ugbc.tab.c"
    break;

  case 185: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 726 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4629 "src-generated/ugbc.tab.c"
    break;

  case 186: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 729 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4637 "src-generated/ugbc.tab.c"
    break;

  case 187: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 732 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4645 "src-generated/ugbc.tab.c"
    break;

  case 188: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 735 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4653 "src-generated/ugbc.tab.c"
    break;

  case 189: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 738 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4661 "src-generated/ugbc.tab.c"
    break;

  case 192: /* raster_definition_simple: Identifier AT direct_integer  */
#line 747 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 4669 "src-generated/ugbc.tab.c"
    break;

  case 193: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 750 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 4677 "src-generated/ugbc.tab.c"
    break;

  case 194: /* raster_definition_expression: Identifier AT expr  */
#line 755 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4685 "src-generated/ugbc.tab.c"
    break;

  case 195: /* raster_definition_expression: AT expr WITH Identifier  */
#line 758 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4693 "src-generated/ugbc.tab.c"
    break;

  case 198: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 767 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 4701 "src-generated/ugbc.tab.c"
    break;

  case 199: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 770 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 4709 "src-generated/ugbc.tab.c"
    break;

  case 200: /* next_raster_definition_expression: Identifier AT expr  */
#line 775 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 4717 "src-generated/ugbc.tab.c"
    break;

  case 201: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 778 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4725 "src-generated/ugbc.tab.c"
    break;

  case 204: /* color_definition_simple: BORDER direct_integer  */
#line 787 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 4733 "src-generated/ugbc.tab.c"
    break;

  case 205: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 790 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4741 "src-generated/ugbc.tab.c"
    break;

  case 206: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 793 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4749 "src-generated/ugbc.tab.c"
    break;

  case 207: /* color_definition_expression: BORDER expr  */
#line 798 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 4757 "src-generated/ugbc.tab.c"
    break;

  case 208: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 801 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4765 "src-generated/ugbc.tab.c"
    break;

  case 209: /* color_definition_expression: SPRITE expr TO expr  */
#line 804 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4773 "src-generated/ugbc.tab.c"
    break;

  case 215: /* wait_definition_simple: direct_integer CYCLES  */
#line 818 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4781 "src-generated/ugbc.tab.c"
    break;

  case 216: /* wait_definition_simple: direct_integer TICKS  */
#line 821 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4789 "src-generated/ugbc.tab.c"
    break;

  case 217: /* wait_definition_simple: direct_integer milliseconds  */
#line 824 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4797 "src-generated/ugbc.tab.c"
    break;

  case 218: /* wait_definition_expression: expr CYCLES  */
#line 829 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4805 "src-generated/ugbc.tab.c"
    break;

  case 219: /* wait_definition_expression: expr TICKS  */
#line 832 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4813 "src-generated/ugbc.tab.c"
    break;

  case 220: /* wait_definition_expression: expr milliseconds  */
#line 835 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4821 "src-generated/ugbc.tab.c"
    break;

  case 223: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 845 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4829 "src-generated/ugbc.tab.c"
    break;

  case 224: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 848 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4837 "src-generated/ugbc.tab.c"
    break;

  case 225: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 851 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4845 "src-generated/ugbc.tab.c"
    break;

  case 226: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 854 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4853 "src-generated/ugbc.tab.c"
    break;

  case 227: /* sprite_definition_simple: direct_integer position OP direct_integer OP_COMMA direct_integer CP  */
#line 857 "src/ugbc.y"
                                                                         {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4861 "src-generated/ugbc.tab.c"
    break;

  case 228: /* sprite_definition_simple: direct_integer ENABLE  */
#line 860 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4869 "src-generated/ugbc.tab.c"
    break;

  case 229: /* sprite_definition_simple: direct_integer DISABLE  */
#line 863 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4877 "src-generated/ugbc.tab.c"
    break;

  case 230: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 866 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4885 "src-generated/ugbc.tab.c"
    break;

  case 231: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 869 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4893 "src-generated/ugbc.tab.c"
    break;

  case 232: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 872 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4901 "src-generated/ugbc.tab.c"
    break;

  case 233: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 875 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4909 "src-generated/ugbc.tab.c"
    break;

  case 234: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 878 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4917 "src-generated/ugbc.tab.c"
    break;

  case 235: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 881 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4925 "src-generated/ugbc.tab.c"
    break;

  case 236: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 884 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4933 "src-generated/ugbc.tab.c"
    break;

  case 237: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 887 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4941 "src-generated/ugbc.tab.c"
    break;

  case 238: /* sprite_definition_expression: expr DATA FROM expr  */
#line 892 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4949 "src-generated/ugbc.tab.c"
    break;

  case 239: /* sprite_definition_expression: expr MULTICOLOR  */
#line 895 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4957 "src-generated/ugbc.tab.c"
    break;

  case 240: /* sprite_definition_expression: expr MONOCOLOR  */
#line 898 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4965 "src-generated/ugbc.tab.c"
    break;

  case 241: /* sprite_definition_expression: expr COLOR expr  */
#line 901 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4973 "src-generated/ugbc.tab.c"
    break;

  case 242: /* sprite_definition_expression: expr position OP expr OP_COMMA expr CP  */
#line 904 "src/ugbc.y"
                                           {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4981 "src-generated/ugbc.tab.c"
    break;

  case 243: /* sprite_definition_expression: expr ENABLE  */
#line 907 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4989 "src-generated/ugbc.tab.c"
    break;

  case 244: /* sprite_definition_expression: expr DISABLE  */
#line 910 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4997 "src-generated/ugbc.tab.c"
    break;

  case 245: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 913 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 5005 "src-generated/ugbc.tab.c"
    break;

  case 246: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 916 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 5013 "src-generated/ugbc.tab.c"
    break;

  case 247: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 919 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 5021 "src-generated/ugbc.tab.c"
    break;

  case 248: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 922 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 5029 "src-generated/ugbc.tab.c"
    break;

  case 249: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 925 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 5037 "src-generated/ugbc.tab.c"
    break;

  case 250: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 928 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 5045 "src-generated/ugbc.tab.c"
    break;

  case 251: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 931 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 5053 "src-generated/ugbc.tab.c"
    break;

  case 252: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 934 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 5061 "src-generated/ugbc.tab.c"
    break;

  case 255: /* bitmap_definition_simple: AT direct_integer  */
#line 943 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 5069 "src-generated/ugbc.tab.c"
    break;

  case 256: /* bitmap_definition_simple: ENABLE  */
#line 946 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 5077 "src-generated/ugbc.tab.c"
    break;

  case 257: /* bitmap_definition_simple: DISABLE  */
#line 949 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 5085 "src-generated/ugbc.tab.c"
    break;

  case 258: /* bitmap_definition_simple: CLEAR  */
#line 952 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 5093 "src-generated/ugbc.tab.c"
    break;

  case 259: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 955 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 5101 "src-generated/ugbc.tab.c"
    break;

  case 260: /* bitmap_definition_expression: AT expr  */
#line 961 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 5109 "src-generated/ugbc.tab.c"
    break;

  case 261: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 964 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 5117 "src-generated/ugbc.tab.c"
    break;

  case 264: /* textmap_definition_simple: AT direct_integer  */
#line 974 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 5125 "src-generated/ugbc.tab.c"
    break;

  case 265: /* textmap_definition_expression: AT expr  */
#line 979 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 5133 "src-generated/ugbc.tab.c"
    break;

  case 268: /* text_definition_simple: ENABLE  */
#line 988 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 5141 "src-generated/ugbc.tab.c"
    break;

  case 269: /* text_definition_simple: DISABLE  */
#line 991 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 5149 "src-generated/ugbc.tab.c"
    break;

  case 270: /* text_definition_expression: AT expr OP_COMMA expr OP_COMMA expr  */
#line 996 "src/ugbc.y"
                                         {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 5157 "src-generated/ugbc.tab.c"
    break;

  case 271: /* text_definition_expression: expr OP_COMMA expr OP_COMMA expr  */
#line 999 "src/ugbc.y"
                                      {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 5165 "src-generated/ugbc.tab.c"
    break;

  case 274: /* tiles_definition_simple: AT direct_integer  */
#line 1008 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 5173 "src-generated/ugbc.tab.c"
    break;

  case 275: /* tiles_definition_expression: AT expr  */
#line 1013 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 5181 "src-generated/ugbc.tab.c"
    break;

  case 278: /* colormap_definition_simple: AT direct_integer  */
#line 1022 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 5189 "src-generated/ugbc.tab.c"
    break;

  case 279: /* colormap_definition_simple: CLEAR  */
#line 1025 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 5197 "src-generated/ugbc.tab.c"
    break;

  case 280: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 1028 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 5205 "src-generated/ugbc.tab.c"
    break;

  case 281: /* colormap_definition_expression: AT expr  */
#line 1033 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 5213 "src-generated/ugbc.tab.c"
    break;

  case 282: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 1036 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 5221 "src-generated/ugbc.tab.c"
    break;

  case 285: /* screen_definition_simple: ON  */
#line 1046 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 5229 "src-generated/ugbc.tab.c"
    break;

  case 286: /* screen_definition_simple: OFF  */
#line 1049 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 5237 "src-generated/ugbc.tab.c"
    break;

  case 287: /* screen_definition_simple: ROWS direct_integer  */
#line 1052 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 5245 "src-generated/ugbc.tab.c"
    break;

  case 288: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 1055 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 5253 "src-generated/ugbc.tab.c"
    break;

  case 289: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 1058 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 5261 "src-generated/ugbc.tab.c"
    break;

  case 290: /* screen_definition_expression: ROWS expr  */
#line 1063 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 5269 "src-generated/ugbc.tab.c"
    break;

  case 291: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 1066 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 5277 "src-generated/ugbc.tab.c"
    break;

  case 292: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 1069 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 5285 "src-generated/ugbc.tab.c"
    break;

  case 296: /* var_definition_simple: Identifier ON Identifier  */
#line 1078 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 5293 "src-generated/ugbc.tab.c"
    break;

  case 297: /* var_definition_simple: Identifier OP_DOLLAR ON Identifier  */
#line 1081 "src/ugbc.y"
                                       {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 5301 "src-generated/ugbc.tab.c"
    break;

  case 298: /* var_definition_simple: Identifier ON Identifier OP_ASSIGN direct_integer  */
#line 1084 "src/ugbc.y"
                                                      {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 5309 "src-generated/ugbc.tab.c"
    break;

  case 299: /* var_definition_simple: Identifier ON Identifier OP_ASSIGN expr  */
#line 1087 "src/ugbc.y"
                                            {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 5319 "src-generated/ugbc.tab.c"
    break;

  case 300: /* var_definition_simple: Identifier OP_DOLLAR ON Identifier OP_ASSIGN expr  */
#line 1092 "src/ugbc.y"
                                                      {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 5329 "src-generated/ugbc.tab.c"
    break;

  case 301: /* goto_definition: Identifier  */
#line 1099 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 5337 "src-generated/ugbc.tab.c"
    break;

  case 302: /* goto_definition: Integer  */
#line 1102 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 5345 "src-generated/ugbc.tab.c"
    break;

  case 303: /* gosub_definition: Identifier  */
#line 1108 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 5353 "src-generated/ugbc.tab.c"
    break;

  case 304: /* gosub_definition: Integer  */
#line 1111 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 5361 "src-generated/ugbc.tab.c"
    break;

  case 306: /* point_definition_simple: AT OP direct_integer OP_COMMA direct_integer CP  */
#line 1120 "src/ugbc.y"
                                                      {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 5369 "src-generated/ugbc.tab.c"
    break;

  case 307: /* point_definition_expression: AT OP expr OP_COMMA expr CP  */
#line 1126 "src/ugbc.y"
                                  {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 5377 "src-generated/ugbc.tab.c"
    break;

  case 310: /* ink_definition: expr  */
#line 1135 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 5385 "src-generated/ugbc.tab.c"
    break;

  case 311: /* on_goto_definition: Identifier  */
#line 1140 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 5394 "src-generated/ugbc.tab.c"
    break;

  case 312: /* $@4: %empty  */
#line 1144 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 5402 "src-generated/ugbc.tab.c"
    break;

  case 314: /* on_gosub_definition: Identifier  */
#line 1149 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 5411 "src-generated/ugbc.tab.c"
    break;

  case 315: /* $@5: %empty  */
#line 1153 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 5419 "src-generated/ugbc.tab.c"
    break;

  case 317: /* on_proc_definition: Identifier  */
#line 1158 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 5428 "src-generated/ugbc.tab.c"
    break;

  case 318: /* $@6: %empty  */
#line 1162 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 5436 "src-generated/ugbc.tab.c"
    break;

  case 320: /* $@7: %empty  */
#line 1167 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 5444 "src-generated/ugbc.tab.c"
    break;

  case 322: /* $@8: %empty  */
#line 1170 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 5452 "src-generated/ugbc.tab.c"
    break;

  case 324: /* $@9: %empty  */
#line 1173 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 5460 "src-generated/ugbc.tab.c"
    break;

  case 326: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1178 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 5468 "src-generated/ugbc.tab.c"
    break;

  case 327: /* every_definition: ON  */
#line 1181 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 5476 "src-generated/ugbc.tab.c"
    break;

  case 328: /* every_definition: OFF  */
#line 1184 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 5484 "src-generated/ugbc.tab.c"
    break;

  case 329: /* add_definition: Identifier OP_COMMA expr  */
#line 1189 "src/ugbc.y"
                             {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 5492 "src-generated/ugbc.tab.c"
    break;

  case 330: /* add_definition: Identifier OP_COMMA expr OP_COMMA expr TO expr  */
#line 1192 "src/ugbc.y"
                                                     {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5500 "src-generated/ugbc.tab.c"
    break;

  case 331: /* dimensions: Integer  */
#line 1198 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5509 "src-generated/ugbc.tab.c"
    break;

  case 332: /* dimensions: Integer OP_COMMA dimensions  */
#line 1202 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5518 "src-generated/ugbc.tab.c"
    break;

  case 333: /* datatype: BYTE  */
#line 1209 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 5526 "src-generated/ugbc.tab.c"
    break;

  case 334: /* datatype: SIGNED BYTE  */
#line 1212 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 5534 "src-generated/ugbc.tab.c"
    break;

  case 335: /* datatype: WORD  */
#line 1215 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 5542 "src-generated/ugbc.tab.c"
    break;

  case 336: /* datatype: SIGNED WORD  */
#line 1218 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 5550 "src-generated/ugbc.tab.c"
    break;

  case 337: /* datatype: DWORD  */
#line 1221 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 5558 "src-generated/ugbc.tab.c"
    break;

  case 338: /* datatype: SIGNED DWORD  */
#line 1224 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 5566 "src-generated/ugbc.tab.c"
    break;

  case 339: /* datatype: ADDRESS  */
#line 1227 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 5574 "src-generated/ugbc.tab.c"
    break;

  case 340: /* datatype: POSITION  */
#line 1230 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 5582 "src-generated/ugbc.tab.c"
    break;

  case 341: /* datatype: COLOR  */
#line 1233 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 5590 "src-generated/ugbc.tab.c"
    break;

  case 342: /* datatype: STRING  */
#line 1236 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 5598 "src-generated/ugbc.tab.c"
    break;

  case 343: /* $@10: %empty  */
#line 1241 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5607 "src-generated/ugbc.tab.c"
    break;

  case 344: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1244 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 5617 "src-generated/ugbc.tab.c"
    break;

  case 345: /* $@11: %empty  */
#line 1249 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5626 "src-generated/ugbc.tab.c"
    break;

  case 346: /* dim_definition: Identifier $@11 OP_DOLLAR OP dimensions CP  */
#line 1252 "src/ugbc.y"
                                   {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 5636 "src-generated/ugbc.tab.c"
    break;

  case 347: /* $@12: %empty  */
#line 1257 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5645 "src-generated/ugbc.tab.c"
    break;

  case 348: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1260 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 5655 "src-generated/ugbc.tab.c"
    break;

  case 351: /* indexes: expr  */
#line 1273 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5664 "src-generated/ugbc.tab.c"
    break;

  case 352: /* indexes: expr OP_COMMA indexes  */
#line 1277 "src/ugbc.y"
                            {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5673 "src-generated/ugbc.tab.c"
    break;

  case 353: /* parameters: Identifier  */
#line 1284 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5683 "src-generated/ugbc.tab.c"
    break;

  case 354: /* parameters: Identifier OP_DOLLAR  */
#line 1289 "src/ugbc.y"
                           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5693 "src-generated/ugbc.tab.c"
    break;

  case 355: /* parameters: Identifier AS datatype  */
#line 1294 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5703 "src-generated/ugbc.tab.c"
    break;

  case 356: /* parameters: Identifier OP_COMMA parameters  */
#line 1299 "src/ugbc.y"
                                     {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5713 "src-generated/ugbc.tab.c"
    break;

  case 357: /* parameters: Identifier OP_DOLLAR OP_COMMA parameters  */
#line 1304 "src/ugbc.y"
                                               {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5723 "src-generated/ugbc.tab.c"
    break;

  case 358: /* parameters: Identifier AS datatype OP_COMMA parameters  */
#line 1309 "src/ugbc.y"
                                                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5733 "src-generated/ugbc.tab.c"
    break;

  case 359: /* parameters_expr: Identifier  */
#line 1317 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5743 "src-generated/ugbc.tab.c"
    break;

  case 360: /* parameters_expr: Identifier OP_DOLLAR  */
#line 1322 "src/ugbc.y"
                           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5753 "src-generated/ugbc.tab.c"
    break;

  case 361: /* parameters_expr: Identifier AS datatype  */
#line 1327 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5763 "src-generated/ugbc.tab.c"
    break;

  case 362: /* parameters_expr: Identifier OP_COMMA parameters_expr  */
#line 1332 "src/ugbc.y"
                                          {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5773 "src-generated/ugbc.tab.c"
    break;

  case 363: /* parameters_expr: Identifier OP_DOLLAR OP_COMMA parameters_expr  */
#line 1337 "src/ugbc.y"
                                                    {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5783 "src-generated/ugbc.tab.c"
    break;

  case 364: /* parameters_expr: Identifier AS datatype OP_COMMA parameters_expr  */
#line 1342 "src/ugbc.y"
                                                      {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5793 "src-generated/ugbc.tab.c"
    break;

  case 365: /* parameters_expr: String  */
#line 1347 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5802 "src-generated/ugbc.tab.c"
    break;

  case 366: /* parameters_expr: String OP_COMMA parameters_expr  */
#line 1351 "src/ugbc.y"
                                      {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5811 "src-generated/ugbc.tab.c"
    break;

  case 367: /* values: expr  */
#line 1358 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5820 "src-generated/ugbc.tab.c"
    break;

  case 368: /* values: expr OP_COMMA values  */
#line 1362 "src/ugbc.y"
                           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5829 "src-generated/ugbc.tab.c"
    break;

  case 369: /* print_definition: expr  */
#line 1369 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5837 "src-generated/ugbc.tab.c"
    break;

  case 370: /* print_definition: expr OP_COMMA  */
#line 1372 "src/ugbc.y"
                  {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5846 "src-generated/ugbc.tab.c"
    break;

  case 371: /* print_definition: expr OP_SEMICOLON  */
#line 1376 "src/ugbc.y"
                      {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5854 "src-generated/ugbc.tab.c"
    break;

  case 372: /* $@13: %empty  */
#line 1379 "src/ugbc.y"
                  {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5863 "src-generated/ugbc.tab.c"
    break;

  case 374: /* $@14: %empty  */
#line 1383 "src/ugbc.y"
                       {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5871 "src-generated/ugbc.tab.c"
    break;

  case 376: /* writing_mode_definition: REPLACE  */
#line 1389 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5880 "src-generated/ugbc.tab.c"
    break;

  case 377: /* writing_mode_definition: OR  */
#line 1393 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5889 "src-generated/ugbc.tab.c"
    break;

  case 378: /* writing_mode_definition: XOR  */
#line 1397 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5898 "src-generated/ugbc.tab.c"
    break;

  case 379: /* writing_mode_definition: AND  */
#line 1401 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5907 "src-generated/ugbc.tab.c"
    break;

  case 380: /* writing_mode_definition: IGNORE  */
#line 1405 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5916 "src-generated/ugbc.tab.c"
    break;

  case 381: /* writing_part_definition: NORMAL  */
#line 1412 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5925 "src-generated/ugbc.tab.c"
    break;

  case 382: /* writing_part_definition: PAPER  */
#line 1416 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5934 "src-generated/ugbc.tab.c"
    break;

  case 383: /* writing_part_definition: PAPER ONLY  */
#line 1420 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5943 "src-generated/ugbc.tab.c"
    break;

  case 384: /* writing_part_definition: PEN  */
#line 1424 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5952 "src-generated/ugbc.tab.c"
    break;

  case 385: /* writing_part_definition: PEN ONLY  */
#line 1428 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5961 "src-generated/ugbc.tab.c"
    break;

  case 386: /* writing_definition: writing_mode_definition OP_COMMA writing_part_definition  */
#line 1435 "src/ugbc.y"
                                                             {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5969 "src-generated/ugbc.tab.c"
    break;

  case 387: /* locate_definition: OP_COMMA expr  */
#line 1441 "src/ugbc.y"
                   {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 5977 "src-generated/ugbc.tab.c"
    break;

  case 388: /* locate_definition: expr OP_COMMA  */
#line 1444 "src/ugbc.y"
                    {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 5985 "src-generated/ugbc.tab.c"
    break;

  case 389: /* locate_definition: expr OP_COMMA expr  */
#line 1447 "src/ugbc.y"
                         {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5993 "src-generated/ugbc.tab.c"
    break;

  case 390: /* cmove_definition: OP_COMMA expr  */
#line 1453 "src/ugbc.y"
                   {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 6001 "src-generated/ugbc.tab.c"
    break;

  case 391: /* cmove_definition: expr OP_COMMA  */
#line 1456 "src/ugbc.y"
                    {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 6009 "src-generated/ugbc.tab.c"
    break;

  case 392: /* cmove_definition: expr OP_COMMA expr  */
#line 1459 "src/ugbc.y"
                         {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 6017 "src-generated/ugbc.tab.c"
    break;

  case 393: /* hscroll_definition: LEFT  */
#line 1465 "src/ugbc.y"
         {
        text_hscroll_line( _environment, -1 );
    }
#line 6025 "src-generated/ugbc.tab.c"
    break;

  case 394: /* hscroll_definition: SCREEN LEFT  */
#line 1468 "src/ugbc.y"
                  {
        text_hscroll_screen( _environment, -1 );
    }
#line 6033 "src-generated/ugbc.tab.c"
    break;

  case 395: /* hscroll_definition: RIGHT  */
#line 1471 "src/ugbc.y"
            {
        text_hscroll_line( _environment, 1 );
    }
#line 6041 "src-generated/ugbc.tab.c"
    break;

  case 396: /* hscroll_definition: SCREEN RIGHT  */
#line 1474 "src/ugbc.y"
                   {
        text_hscroll_screen( _environment, 1 );
    }
#line 6049 "src-generated/ugbc.tab.c"
    break;

  case 397: /* vscroll_definition: SCREEN UP  */
#line 1480 "src/ugbc.y"
                {
        text_vscroll_screen( _environment, -1 );
    }
#line 6057 "src-generated/ugbc.tab.c"
    break;

  case 398: /* vscroll_definition: SCREEN DOWN  */
#line 1483 "src/ugbc.y"
                  {
        text_vscroll_screen( _environment, 1 );
    }
#line 6065 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: TEXTADDRESS OP_ASSIGN expr  */
#line 1504 "src/ugbc.y"
                               {
      variable_move( _environment, (yyvsp[0].string), "ADDRESS" );
  }
#line 6073 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: MEMORIZE  */
#line 1511 "src/ugbc.y"
             {
      text_memorize( _environment );
  }
#line 6081 "src-generated/ugbc.tab.c"
    break;

  case 420: /* statement: REMEMBER  */
#line 1514 "src/ugbc.y"
             {
      text_remember( _environment );
  }
#line 6089 "src-generated/ugbc.tab.c"
    break;

  case 424: /* statement: CUP  */
#line 1520 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 6097 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: CDOWN  */
#line 1523 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 6105 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: CLEFT  */
#line 1526 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 6113 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: CRIGHT  */
#line 1529 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 6121 "src-generated/ugbc.tab.c"
    break;

  case 428: /* statement: CLINE  */
#line 1532 "src/ugbc.y"
          {
      text_cline( _environment, NULL );
  }
#line 6129 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: CLINE expr  */
#line 1535 "src/ugbc.y"
               {
      text_cline( _environment, (yyvsp[0].string) );
  }
#line 6137 "src-generated/ugbc.tab.c"
    break;

  case 430: /* statement: SET TAB expr  */
#line 1538 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 6145 "src-generated/ugbc.tab.c"
    break;

  case 431: /* statement: CENTER expr  */
#line 1541 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 6153 "src-generated/ugbc.tab.c"
    break;

  case 432: /* statement: CENTRE expr  */
#line 1544 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 6161 "src-generated/ugbc.tab.c"
    break;

  case 433: /* statement: CLS  */
#line 1547 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 6169 "src-generated/ugbc.tab.c"
    break;

  case 434: /* statement: HOME  */
#line 1550 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 6177 "src-generated/ugbc.tab.c"
    break;

  case 435: /* statement: OP_INC Identifier  */
#line 1553 "src/ugbc.y"
                      {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 6185 "src-generated/ugbc.tab.c"
    break;

  case 436: /* statement: OP_DEC Identifier  */
#line 1556 "src/ugbc.y"
                      {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 6193 "src-generated/ugbc.tab.c"
    break;

  case 437: /* statement: RANDOMIZE  */
#line 1559 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 6201 "src-generated/ugbc.tab.c"
    break;

  case 438: /* statement: RANDOMIZE expr  */
#line 1562 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 6209 "src-generated/ugbc.tab.c"
    break;

  case 439: /* statement: IF expr THEN  */
#line 1565 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 6217 "src-generated/ugbc.tab.c"
    break;

  case 440: /* statement: ELSE  */
#line 1568 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 6225 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: ELSE IF expr THEN  */
#line 1571 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 6233 "src-generated/ugbc.tab.c"
    break;

  case 442: /* statement: ENDIF  */
#line 1574 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 6241 "src-generated/ugbc.tab.c"
    break;

  case 443: /* statement: DO  */
#line 1577 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 6249 "src-generated/ugbc.tab.c"
    break;

  case 444: /* statement: LOOP  */
#line 1580 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 6257 "src-generated/ugbc.tab.c"
    break;

  case 445: /* $@15: %empty  */
#line 1583 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 6265 "src-generated/ugbc.tab.c"
    break;

  case 446: /* statement: WHILE $@15 expr  */
#line 1585 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 6273 "src-generated/ugbc.tab.c"
    break;

  case 447: /* statement: WEND  */
#line 1588 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 6281 "src-generated/ugbc.tab.c"
    break;

  case 448: /* statement: REPEAT  */
#line 1591 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 6289 "src-generated/ugbc.tab.c"
    break;

  case 449: /* statement: UNTIL expr  */
#line 1594 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 6297 "src-generated/ugbc.tab.c"
    break;

  case 450: /* statement: EXIT  */
#line 1597 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 6305 "src-generated/ugbc.tab.c"
    break;

  case 451: /* statement: EXIT PROC  */
#line 1600 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 6313 "src-generated/ugbc.tab.c"
    break;

  case 452: /* statement: POP PROC  */
#line 1603 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 6321 "src-generated/ugbc.tab.c"
    break;

  case 453: /* statement: EXIT IF expr  */
#line 1606 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 6329 "src-generated/ugbc.tab.c"
    break;

  case 454: /* statement: EXIT Integer  */
#line 1609 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 6337 "src-generated/ugbc.tab.c"
    break;

  case 455: /* statement: EXIT direct_integer  */
#line 1612 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 6345 "src-generated/ugbc.tab.c"
    break;

  case 456: /* statement: EXIT IF expr OP_COMMA Integer  */
#line 1615 "src/ugbc.y"
                                  {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 6353 "src-generated/ugbc.tab.c"
    break;

  case 457: /* statement: EXIT IF expr OP_COMMA direct_integer  */
#line 1618 "src/ugbc.y"
                                         {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 6361 "src-generated/ugbc.tab.c"
    break;

  case 458: /* statement: FOR Identifier OP_ASSIGN expr TO expr  */
#line 1621 "src/ugbc.y"
                                          {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 6369 "src-generated/ugbc.tab.c"
    break;

  case 459: /* statement: NEXT  */
#line 1624 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 6377 "src-generated/ugbc.tab.c"
    break;

  case 460: /* statement: PROCEDURE Identifier  */
#line 1627 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 6386 "src-generated/ugbc.tab.c"
    break;

  case 461: /* $@16: %empty  */
#line 1631 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6394 "src-generated/ugbc.tab.c"
    break;

  case 462: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1633 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6402 "src-generated/ugbc.tab.c"
    break;

  case 463: /* statement: SHARED parameters_expr  */
#line 1636 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 6410 "src-generated/ugbc.tab.c"
    break;

  case 464: /* statement: GLOBAL parameters_expr  */
#line 1639 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 6418 "src-generated/ugbc.tab.c"
    break;

  case 465: /* statement: END PROC  */
#line 1642 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 6426 "src-generated/ugbc.tab.c"
    break;

  case 466: /* statement: END PROC OSP expr CSP  */
#line 1645 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6434 "src-generated/ugbc.tab.c"
    break;

  case 467: /* statement: FOR Identifier OP_ASSIGN expr TO expr STEP expr  */
#line 1648 "src/ugbc.y"
                                                    {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 6442 "src-generated/ugbc.tab.c"
    break;

  case 468: /* statement: Identifier " "  */
#line 1651 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6451 "src-generated/ugbc.tab.c"
    break;

  case 469: /* statement: PROC Identifier  */
#line 1655 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6460 "src-generated/ugbc.tab.c"
    break;

  case 470: /* statement: CALL Identifier  */
#line 1659 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6469 "src-generated/ugbc.tab.c"
    break;

  case 471: /* $@17: %empty  */
#line 1663 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6477 "src-generated/ugbc.tab.c"
    break;

  case 472: /* statement: Identifier OSP $@17 values CSP  */
#line 1665 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6485 "src-generated/ugbc.tab.c"
    break;

  case 473: /* $@18: %empty  */
#line 1668 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6493 "src-generated/ugbc.tab.c"
    break;

  case 474: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1670 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6501 "src-generated/ugbc.tab.c"
    break;

  case 475: /* $@19: %empty  */
#line 1673 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6509 "src-generated/ugbc.tab.c"
    break;

  case 476: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1675 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6517 "src-generated/ugbc.tab.c"
    break;

  case 477: /* statement: PEN expr  */
#line 1678 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 6525 "src-generated/ugbc.tab.c"
    break;

  case 478: /* statement: PAPER expr  */
#line 1681 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 6533 "src-generated/ugbc.tab.c"
    break;

  case 479: /* statement: INVERSE ON  */
#line 1684 "src/ugbc.y"
               {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 6541 "src-generated/ugbc.tab.c"
    break;

  case 480: /* statement: INVERSE OFF  */
#line 1687 "src/ugbc.y"
                {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 6549 "src-generated/ugbc.tab.c"
    break;

  case 482: /* statement: Identifier OP_COLON  */
#line 1691 "src/ugbc.y"
                        {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 6557 "src-generated/ugbc.tab.c"
    break;

  case 483: /* statement: BEG GAMELOOP  */
#line 1694 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 6565 "src-generated/ugbc.tab.c"
    break;

  case 484: /* statement: END GAMELOOP  */
#line 1697 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 6573 "src-generated/ugbc.tab.c"
    break;

  case 485: /* statement: GRAPHIC  */
#line 1700 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 6581 "src-generated/ugbc.tab.c"
    break;

  case 486: /* statement: HALT  */
#line 1703 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 6589 "src-generated/ugbc.tab.c"
    break;

  case 487: /* statement: END  */
#line 1706 "src/ugbc.y"
        {
      end( _environment );
  }
#line 6597 "src-generated/ugbc.tab.c"
    break;

  case 492: /* statement: RETURN  */
#line 1713 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 6605 "src-generated/ugbc.tab.c"
    break;

  case 493: /* statement: RETURN expr  */
#line 1716 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 6613 "src-generated/ugbc.tab.c"
    break;

  case 494: /* statement: POP  */
#line 1719 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 6621 "src-generated/ugbc.tab.c"
    break;

  case 495: /* statement: DONE  */
#line 1722 "src/ugbc.y"
          {
      return 0;
  }
#line 6629 "src-generated/ugbc.tab.c"
    break;

  case 496: /* statement: LEFT OP expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 1725 "src/ugbc.y"
                                                 {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6637 "src-generated/ugbc.tab.c"
    break;

  case 497: /* statement: RIGHT OP expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 1728 "src/ugbc.y"
                                                  {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6645 "src-generated/ugbc.tab.c"
    break;

  case 498: /* statement: MID OP expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 1731 "src/ugbc.y"
                                                {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 6653 "src-generated/ugbc.tab.c"
    break;

  case 499: /* statement: MID OP expr OP_COMMA expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 1734 "src/ugbc.y"
                                                              {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6661 "src-generated/ugbc.tab.c"
    break;

  case 501: /* statement: Identifier OP_ASSIGN expr  */
#line 1738 "src/ugbc.y"
                              {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 6675 "src-generated/ugbc.tab.c"
    break;

  case 502: /* statement: Identifier OP_DOLLAR OP_ASSIGN expr  */
#line 1747 "src/ugbc.y"
                                        {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 6689 "src-generated/ugbc.tab.c"
    break;

  case 503: /* $@20: %empty  */
#line 1756 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6698 "src-generated/ugbc.tab.c"
    break;

  case 504: /* statement: Identifier $@20 OP indexes CP OP_ASSIGN expr  */
#line 1760 "src/ugbc.y"
                                   {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 6711 "src-generated/ugbc.tab.c"
    break;

  case 505: /* $@21: %empty  */
#line 1768 "src/ugbc.y"
                         {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6720 "src-generated/ugbc.tab.c"
    break;

  case 506: /* statement: Identifier OP_DOLLAR $@21 OP indexes CP OP_ASSIGN expr  */
#line 1771 "src/ugbc.y"
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
#line 6739 "src-generated/ugbc.tab.c"
    break;

  case 507: /* $@22: %empty  */
#line 1785 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6748 "src-generated/ugbc.tab.c"
    break;

  case 508: /* statement: Identifier $@22 datatype OP indexes CP OP_ASSIGN expr  */
#line 1788 "src/ugbc.y"
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
#line 6767 "src-generated/ugbc.tab.c"
    break;

  case 509: /* statement: DEBUG expr  */
#line 1802 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 6775 "src-generated/ugbc.tab.c"
    break;

  case 512: /* statements_no_linenumbers: statement  */
#line 1810 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 6781 "src-generated/ugbc.tab.c"
    break;

  case 513: /* $@23: %empty  */
#line 1811 "src/ugbc.y"
                         { ((Environment *)_environment)->yylineno = yylineno; }
#line 6787 "src-generated/ugbc.tab.c"
    break;

  case 515: /* $@24: %empty  */
#line 1815 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 6795 "src-generated/ugbc.tab.c"
    break;

  case 516: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1817 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 6803 "src-generated/ugbc.tab.c"
    break;

  case 517: /* $@25: %empty  */
#line 1822 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 6811 "src-generated/ugbc.tab.c"
    break;

  case 523: /* $@26: %empty  */
#line 1832 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 6817 "src-generated/ugbc.tab.c"
    break;


#line 6821 "src-generated/ugbc.tab.c"

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

#line 1834 "src/ugbc.y"


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
        deploy( varsDeployed, "./ugbc/src/hw/c64/vars.asm");
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

