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
  YYSYMBOL_HAS = 23,                       /* HAS  */
  YYSYMBOL_IS = 24,                        /* IS  */
  YYSYMBOL_OF = 25,                        /* OF  */
  YYSYMBOL_RASTER = 26,                    /* RASTER  */
  YYSYMBOL_DONE = 27,                      /* DONE  */
  YYSYMBOL_AT = 28,                        /* AT  */
  YYSYMBOL_COLOR = 29,                     /* COLOR  */
  YYSYMBOL_BORDER = 30,                    /* BORDER  */
  YYSYMBOL_WAIT = 31,                      /* WAIT  */
  YYSYMBOL_NEXT = 32,                      /* NEXT  */
  YYSYMBOL_WITH = 33,                      /* WITH  */
  YYSYMBOL_BANK = 34,                      /* BANK  */
  YYSYMBOL_SPRITE = 35,                    /* SPRITE  */
  YYSYMBOL_DATA = 36,                      /* DATA  */
  YYSYMBOL_FROM = 37,                      /* FROM  */
  YYSYMBOL_OP = 38,                        /* OP  */
  YYSYMBOL_CP = 39,                        /* CP  */
  YYSYMBOL_ENABLE = 40,                    /* ENABLE  */
  YYSYMBOL_DISABLE = 41,                   /* DISABLE  */
  YYSYMBOL_HALT = 42,                      /* HALT  */
  YYSYMBOL_ECM = 43,                       /* ECM  */
  YYSYMBOL_BITMAP = 44,                    /* BITMAP  */
  YYSYMBOL_SCREEN = 45,                    /* SCREEN  */
  YYSYMBOL_ON = 46,                        /* ON  */
  YYSYMBOL_OFF = 47,                       /* OFF  */
  YYSYMBOL_ROWS = 48,                      /* ROWS  */
  YYSYMBOL_VERTICAL = 49,                  /* VERTICAL  */
  YYSYMBOL_SCROLL = 50,                    /* SCROLL  */
  YYSYMBOL_VAR = 51,                       /* VAR  */
  YYSYMBOL_AS = 52,                        /* AS  */
  YYSYMBOL_TEMPORARY = 53,                 /* TEMPORARY  */
  YYSYMBOL_XPEN = 54,                      /* XPEN  */
  YYSYMBOL_YPEN = 55,                      /* YPEN  */
  YYSYMBOL_PEEK = 56,                      /* PEEK  */
  YYSYMBOL_GOTO = 57,                      /* GOTO  */
  YYSYMBOL_HORIZONTAL = 58,                /* HORIZONTAL  */
  YYSYMBOL_MCM = 59,                       /* MCM  */
  YYSYMBOL_COMPRESS = 60,                  /* COMPRESS  */
  YYSYMBOL_EXPAND = 61,                    /* EXPAND  */
  YYSYMBOL_LOOP = 62,                      /* LOOP  */
  YYSYMBOL_REPEAT = 63,                    /* REPEAT  */
  YYSYMBOL_WHILE = 64,                     /* WHILE  */
  YYSYMBOL_TEXT = 65,                      /* TEXT  */
  YYSYMBOL_TILES = 66,                     /* TILES  */
  YYSYMBOL_COLORMAP = 67,                  /* COLORMAP  */
  YYSYMBOL_SELECT = 68,                    /* SELECT  */
  YYSYMBOL_MONOCOLOR = 69,                 /* MONOCOLOR  */
  YYSYMBOL_MULTICOLOR = 70,                /* MULTICOLOR  */
  YYSYMBOL_COLLISION = 71,                 /* COLLISION  */
  YYSYMBOL_IF = 72,                        /* IF  */
  YYSYMBOL_THEN = 73,                      /* THEN  */
  YYSYMBOL_HIT = 74,                       /* HIT  */
  YYSYMBOL_BACKGROUND = 75,                /* BACKGROUND  */
  YYSYMBOL_TO = 76,                        /* TO  */
  YYSYMBOL_RANDOM = 77,                    /* RANDOM  */
  YYSYMBOL_BYTE = 78,                      /* BYTE  */
  YYSYMBOL_WORD = 79,                      /* WORD  */
  YYSYMBOL_POSITION = 80,                  /* POSITION  */
  YYSYMBOL_CODE = 81,                      /* CODE  */
  YYSYMBOL_VARIABLES = 82,                 /* VARIABLES  */
  YYSYMBOL_MS = 83,                        /* MS  */
  YYSYMBOL_CYCLES = 84,                    /* CYCLES  */
  YYSYMBOL_S = 85,                         /* S  */
  YYSYMBOL_HASH = 86,                      /* HASH  */
  YYSYMBOL_WIDTH = 87,                     /* WIDTH  */
  YYSYMBOL_HEIGHT = 88,                    /* HEIGHT  */
  YYSYMBOL_DWORD = 89,                     /* DWORD  */
  YYSYMBOL_PEN = 90,                       /* PEN  */
  YYSYMBOL_CLEAR = 91,                     /* CLEAR  */
  YYSYMBOL_BEG = 92,                       /* BEG  */
  YYSYMBOL_END = 93,                       /* END  */
  YYSYMBOL_GAMELOOP = 94,                  /* GAMELOOP  */
  YYSYMBOL_ENDIF = 95,                     /* ENDIF  */
  YYSYMBOL_UP = 96,                        /* UP  */
  YYSYMBOL_DOWN = 97,                      /* DOWN  */
  YYSYMBOL_LEFT = 98,                      /* LEFT  */
  YYSYMBOL_RIGHT = 99,                     /* RIGHT  */
  YYSYMBOL_DEBUG = 100,                    /* DEBUG  */
  YYSYMBOL_AND = 101,                      /* AND  */
  YYSYMBOL_RANDOMIZE = 102,                /* RANDOMIZE  */
  YYSYMBOL_GRAPHIC = 103,                  /* GRAPHIC  */
  YYSYMBOL_TEXTMAP = 104,                  /* TEXTMAP  */
  YYSYMBOL_POINT = 105,                    /* POINT  */
  YYSYMBOL_GOSUB = 106,                    /* GOSUB  */
  YYSYMBOL_RETURN = 107,                   /* RETURN  */
  YYSYMBOL_POP = 108,                      /* POP  */
  YYSYMBOL_OR = 109,                       /* OR  */
  YYSYMBOL_ELSE = 110,                     /* ELSE  */
  YYSYMBOL_NOT = 111,                      /* NOT  */
  YYSYMBOL_TRUE = 112,                     /* TRUE  */
  YYSYMBOL_FALSE = 113,                    /* FALSE  */
  YYSYMBOL_DO = 114,                       /* DO  */
  YYSYMBOL_EXIT = 115,                     /* EXIT  */
  YYSYMBOL_WEND = 116,                     /* WEND  */
  YYSYMBOL_UNTIL = 117,                    /* UNTIL  */
  YYSYMBOL_FOR = 118,                      /* FOR  */
  YYSYMBOL_STEP = 119,                     /* STEP  */
  YYSYMBOL_EVERY = 120,                    /* EVERY  */
  YYSYMBOL_MID = 121,                      /* MID  */
  YYSYMBOL_INSTR = 122,                    /* INSTR  */
  YYSYMBOL_UPPER = 123,                    /* UPPER  */
  YYSYMBOL_LOWER = 124,                    /* LOWER  */
  YYSYMBOL_STR = 125,                      /* STR  */
  YYSYMBOL_VAL = 126,                      /* VAL  */
  YYSYMBOL_STRING = 127,                   /* STRING  */
  YYSYMBOL_SPACE = 128,                    /* SPACE  */
  YYSYMBOL_FLIP = 129,                     /* FLIP  */
  YYSYMBOL_CHR = 130,                      /* CHR  */
  YYSYMBOL_ASC = 131,                      /* ASC  */
  YYSYMBOL_LEN = 132,                      /* LEN  */
  YYSYMBOL_POW = 133,                      /* POW  */
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
  YYSYMBOL_BLACK = 202,                    /* BLACK  */
  YYSYMBOL_WHITE = 203,                    /* WHITE  */
  YYSYMBOL_RED = 204,                      /* RED  */
  YYSYMBOL_CYAN = 205,                     /* CYAN  */
  YYSYMBOL_VIOLET = 206,                   /* VIOLET  */
  YYSYMBOL_GREEN = 207,                    /* GREEN  */
  YYSYMBOL_BLUE = 208,                     /* BLUE  */
  YYSYMBOL_YELLOW = 209,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 210,                   /* ORANGE  */
  YYSYMBOL_BROWN = 211,                    /* BROWN  */
  YYSYMBOL_LIGHT = 212,                    /* LIGHT  */
  YYSYMBOL_DARK = 213,                     /* DARK  */
  YYSYMBOL_GREY = 214,                     /* GREY  */
  YYSYMBOL_GRAY = 215,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 216,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 217,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 218,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 219,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 220,                /* TURQUOISE  */
  YYSYMBOL_TAN = 221,                      /* TAN  */
  YYSYMBOL_PINK = 222,                     /* PINK  */
  YYSYMBOL_PEACH = 223,                    /* PEACH  */
  YYSYMBOL_OLIVE = 224,                    /* OLIVE  */
  YYSYMBOL_Identifier = 225,               /* Identifier  */
  YYSYMBOL_String = 226,                   /* String  */
  YYSYMBOL_Integer = 227,                  /* Integer  */
  YYSYMBOL_228_ = 228,                     /* " "  */
  YYSYMBOL_YYACCEPT = 229,                 /* $accept  */
  YYSYMBOL_expr = 230,                     /* expr  */
  YYSYMBOL_expr_math = 231,                /* expr_math  */
  YYSYMBOL_term = 232,                     /* term  */
  YYSYMBOL_modula = 233,                   /* modula  */
  YYSYMBOL_factor = 234,                   /* factor  */
  YYSYMBOL_direct_integer = 235,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 236, /* random_definition_simple  */
  YYSYMBOL_random_definition = 237,        /* random_definition  */
  YYSYMBOL_color_enumeration = 238,        /* color_enumeration  */
  YYSYMBOL_exponential = 239,              /* exponential  */
  YYSYMBOL_240_1 = 240,                    /* $@1  */
  YYSYMBOL_241_2 = 241,                    /* $@2  */
  YYSYMBOL_242_3 = 242,                    /* $@3  */
  YYSYMBOL_position = 243,                 /* position  */
  YYSYMBOL_bank_definition_simple = 244,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 245, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 246,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 247, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 248, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 249,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 250, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 251, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 252,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 253,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 254, /* color_definition_expression  */
  YYSYMBOL_color_definition = 255,         /* color_definition  */
  YYSYMBOL_milliseconds = 256,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 257,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 258, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 259,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 260, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 261, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 262,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 263, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 264, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 265,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 266, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 267, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 268,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 269,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 270, /* text_definition_expression  */
  YYSYMBOL_text_definition = 271,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 272,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 273, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 274,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 275, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 276, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 277,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 278, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 279, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 280,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 281,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 282,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 283,         /* gosub_definition  */
  YYSYMBOL_var_definition = 284,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 285,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 286, /* point_definition_expression  */
  YYSYMBOL_point_definition = 287,         /* point_definition  */
  YYSYMBOL_ink_definition = 288,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 289,       /* on_goto_definition  */
  YYSYMBOL_290_4 = 290,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 291,      /* on_gosub_definition  */
  YYSYMBOL_292_5 = 292,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 293,       /* on_proc_definition  */
  YYSYMBOL_294_6 = 294,                    /* $@6  */
  YYSYMBOL_on_definition = 295,            /* on_definition  */
  YYSYMBOL_296_7 = 296,                    /* $@7  */
  YYSYMBOL_297_8 = 297,                    /* $@8  */
  YYSYMBOL_298_9 = 298,                    /* $@9  */
  YYSYMBOL_every_definition = 299,         /* every_definition  */
  YYSYMBOL_add_definition = 300,           /* add_definition  */
  YYSYMBOL_dimensions = 301,               /* dimensions  */
  YYSYMBOL_datatype = 302,                 /* datatype  */
  YYSYMBOL_dim_definition = 303,           /* dim_definition  */
  YYSYMBOL_304_10 = 304,                   /* $@10  */
  YYSYMBOL_305_11 = 305,                   /* $@11  */
  YYSYMBOL_306_12 = 306,                   /* $@12  */
  YYSYMBOL_dim_definitions = 307,          /* dim_definitions  */
  YYSYMBOL_indexes = 308,                  /* indexes  */
  YYSYMBOL_parameters = 309,               /* parameters  */
  YYSYMBOL_parameters_expr = 310,          /* parameters_expr  */
  YYSYMBOL_values = 311,                   /* values  */
  YYSYMBOL_print_definition = 312,         /* print_definition  */
  YYSYMBOL_313_13 = 313,                   /* $@13  */
  YYSYMBOL_314_14 = 314,                   /* $@14  */
  YYSYMBOL_writing_mode_definition = 315,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 316,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 317,       /* writing_definition  */
  YYSYMBOL_locate_definition = 318,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 319,         /* cmove_definition  */
  YYSYMBOL_hscroll_definition = 320,       /* hscroll_definition  */
  YYSYMBOL_vscroll_definition = 321,       /* vscroll_definition  */
  YYSYMBOL_statement = 322,                /* statement  */
  YYSYMBOL_323_15 = 323,                   /* $@15  */
  YYSYMBOL_324_16 = 324,                   /* $@16  */
  YYSYMBOL_325_17 = 325,                   /* $@17  */
  YYSYMBOL_326_18 = 326,                   /* $@18  */
  YYSYMBOL_327_19 = 327,                   /* $@19  */
  YYSYMBOL_328_20 = 328,                   /* $@20  */
  YYSYMBOL_329_21 = 329,                   /* $@21  */
  YYSYMBOL_330_22 = 330,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 331, /* statements_no_linenumbers  */
  YYSYMBOL_332_23 = 332,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 333, /* statements_with_linenumbers  */
  YYSYMBOL_334_24 = 334,                   /* $@24  */
  YYSYMBOL_statements_complex = 335,       /* statements_complex  */
  YYSYMBOL_336_25 = 336,                   /* $@25  */
  YYSYMBOL_program = 337,                  /* program  */
  YYSYMBOL_338_26 = 338                    /* $@26  */
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
#define YYLAST   3941

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  229
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  110
/* YYNRULES -- Number of rules.  */
#define YYNRULES  518
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1013

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   483


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
     225,   226,   227,   228
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
     607,   611,   615,   618,   622,   626,   630,   634,   638,   643,
     643,   646,   649,   652,   655,   658,   661,   665,   668,   671,
     674,   678,   681,   684,   687,   691,   694,   697,   700,   706,
     709,   712,   715,   718,   723,   724,   727,   730,   735,   738,
     743,   744,   747,   750,   755,   758,   763,   764,   767,   770,
     773,   778,   781,   784,   789,   790,   793,   794,   795,   798,
     801,   804,   809,   812,   815,   821,   822,   825,   828,   831,
     834,   837,   840,   843,   846,   849,   852,   855,   858,   861,
     864,   867,   872,   875,   878,   881,   884,   887,   890,   893,
     896,   899,   902,   905,   908,   911,   914,   919,   920,   923,
     926,   929,   932,   935,   941,   944,   950,   951,   954,   959,
     964,   965,   968,   971,   976,   979,   984,   985,   988,   993,
     998,   999,  1002,  1005,  1008,  1013,  1016,  1022,  1023,  1026,
    1029,  1032,  1035,  1038,  1043,  1046,  1049,  1054,  1055,  1057,
    1058,  1061,  1064,  1067,  1072,  1079,  1082,  1088,  1091,  1097,
    1100,  1106,  1111,  1112,  1115,  1120,  1124,  1124,  1129,  1133,
    1133,  1138,  1142,  1142,  1147,  1147,  1150,  1150,  1153,  1153,
    1158,  1161,  1164,  1169,  1172,  1178,  1182,  1189,  1192,  1195,
    1198,  1201,  1204,  1207,  1210,  1213,  1216,  1221,  1221,  1229,
    1229,  1237,  1237,  1248,  1249,  1253,  1257,  1264,  1269,  1274,
    1279,  1284,  1289,  1297,  1302,  1307,  1312,  1317,  1322,  1327,
    1331,  1338,  1342,  1349,  1352,  1356,  1359,  1359,  1363,  1363,
    1369,  1373,  1377,  1381,  1385,  1392,  1396,  1400,  1404,  1408,
    1415,  1421,  1424,  1427,  1433,  1436,  1439,  1445,  1448,  1451,
    1454,  1460,  1463,  1469,  1470,  1471,  1472,  1473,  1474,  1475,
    1476,  1477,  1478,  1479,  1480,  1481,  1482,  1483,  1484,  1487,
    1488,  1489,  1490,  1491,  1494,  1497,  1498,  1499,  1500,  1503,
    1506,  1509,  1512,  1515,  1518,  1521,  1524,  1527,  1530,  1533,
    1536,  1539,  1542,  1545,  1548,  1551,  1554,  1557,  1560,  1563,
    1563,  1568,  1571,  1574,  1577,  1580,  1583,  1586,  1589,  1592,
    1595,  1598,  1601,  1604,  1607,  1611,  1611,  1616,  1619,  1622,
    1625,  1628,  1631,  1635,  1639,  1643,  1643,  1648,  1648,  1653,
    1653,  1658,  1661,  1664,  1667,  1670,  1671,  1674,  1677,  1680,
    1683,  1686,  1689,  1690,  1691,  1692,  1693,  1696,  1699,  1702,
    1705,  1708,  1711,  1714,  1717,  1718,  1727,  1736,  1736,  1748,
    1748,  1765,  1765,  1782,  1785,  1786,  1790,  1791,  1791,  1795,
    1795,  1802,  1802,  1805,  1806,  1807,  1808,  1812,  1812
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
  "DOLLAR", "DIVISION", "QM", "HAS", "IS", "OF", "RASTER", "DONE", "AT",
  "COLOR", "BORDER", "WAIT", "NEXT", "WITH", "BANK", "SPRITE", "DATA",
  "FROM", "OP", "CP", "ENABLE", "DISABLE", "HALT", "ECM", "BITMAP",
  "SCREEN", "ON", "OFF", "ROWS", "VERTICAL", "SCROLL", "VAR", "AS",
  "TEMPORARY", "XPEN", "YPEN", "PEEK", "GOTO", "HORIZONTAL", "MCM",
  "COMPRESS", "EXPAND", "LOOP", "REPEAT", "WHILE", "TEXT", "TILES",
  "COLORMAP", "SELECT", "MONOCOLOR", "MULTICOLOR", "COLLISION", "IF",
  "THEN", "HIT", "BACKGROUND", "TO", "RANDOM", "BYTE", "WORD", "POSITION",
  "CODE", "VARIABLES", "MS", "CYCLES", "S", "HASH", "WIDTH", "HEIGHT",
  "DWORD", "PEN", "CLEAR", "BEG", "END", "GAMELOOP", "ENDIF", "UP", "DOWN",
  "LEFT", "RIGHT", "DEBUG", "AND", "RANDOMIZE", "GRAPHIC", "TEXTMAP",
  "POINT", "GOSUB", "RETURN", "POP", "OR", "ELSE", "NOT", "TRUE", "FALSE",
  "DO", "EXIT", "WEND", "UNTIL", "FOR", "STEP", "EVERY", "MID", "INSTR",
  "UPPER", "LOWER", "STR", "VAL", "STRING", "SPACE", "FLIP", "CHR", "ASC",
  "LEN", "POW", "MOD", "ADD", "MIN", "MAX", "SGN", "SIGNED", "ABS", "RND",
  "COLORS", "INK", "TIMER", "POWERING", "DIM", "ADDRESS", "PROC",
  "PROCEDURE", "CALL", "OSP", "CSP", "SHARED", "MILLISECOND",
  "MILLISECONDS", "TICKS", "GLOBAL", "PARAM", "PRINT", "DEFAULT", "USE",
  "PAPER", "INVERSE", "REPLACE", "XOR", "IGNORE", "NORMAL", "WRITING",
  "ONLY", "LOCATE", "CLS", "HOME", "CMOVE", "CENTER", "CENTRE", "TAB",
  "SET", "CUP", "CDOWN", "CLEFT", "CRIGHT", "CLINE", "XCURS", "YCURS",
  "MEMORIZE", "REMEMBER", "HSCROLL", "VSCROLL", "TEXTADDRESS", "JOY",
  "BIN", "BIT", "COUNT", "JOYCOUNT", "FIRE", "JUP", "JDOWN", "JLEFT",
  "JRIGHT", "JFIRE", "INKEY", "BLACK", "WHITE", "RED", "CYAN", "VIOLET",
  "GREEN", "BLUE", "YELLOW", "ORANGE", "BROWN", "LIGHT", "DARK", "GREY",
  "GRAY", "MAGENTA", "PURPLE", "LAVENDER", "GOLD", "TURQUOISE", "TAN",
  "PINK", "PEACH", "OLIVE", "Identifier", "String", "Integer", "\" \"",
  "$accept", "expr", "expr_math", "term", "modula", "factor",
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
     475,   476,   477,   478,   479,   480,   481,   482,   483
};
#endif

#define YYPACT_NINF (-868)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-498)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -868,    87,  1050,  -868,  -868,  -151,  -135,  2890,   -19,  -868,
      38,  2465,    72,    -4,  2465,  -868,    29,   178,  2890,  -115,
     -20,  -868,  -868,  -868,  2053,    97,    48,  2890,  2890,    21,
      11,  -868,   131,   177,  2890,  2890,  -868,   190,   207,    36,
    2890,    92,   214,  -868,   -32,  -868,  2890,    24,  2259,   256,
      83,  2890,    88,    89,    91,    93,  -123,  -123,  2890,  2890,
     183,    -8,  1420,  -868,  -868,  1641,  2890,  2890,   141,  -868,
    -868,  -868,  -868,  2890,  -868,  -868,    34,   274,   309,     9,
    -868,   318,   321,   323,  -868,  -868,  -868,   101,   310,  1847,
    -868,  -868,   291,   302,   303,   180,  -868,  -868,    25,  -868,
    -868,   304,   305,  2890,  -868,  -868,   306,   311,   312,   313,
     314,   315,   316,   317,   319,   320,   342,   343,   344,   345,
     346,   347,   349,  -868,  -868,   350,    71,   -34,    26,   328,
     336,   339,   366,   369,   370,   373,  -868,  -868,  -868,    -1,
     353,  3508,  -868,   356,   358,   372,   375,   376,   377,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,   201,  -868,  -868,
      68,     2,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,   202,    15,  -868,  -868,   257,   133,   282,   264,    19,
    -868,  -868,  -868,  2465,   389,  -868,  -868,  -868,  2465,  2465,
    2465,  -868,  -868,  -868,   191,    16,    96,  -868,  -868,  -868,
     -14,   333,    -3,    -2,     3,     8,   393,  -868,  -868,  -868,
     251,   371,  -868,  -868,  -868,  2465,  -868,  -868,   390,  -868,
    -868,  -868,  -868,  -868,  2465,   374,   378,  -868,  -868,  -868,
       6,  -868,    65,  -868,  -868,  -868,  -868,  -868,  2890,  2684,
    -868,  -868,   415,  -868,  -868,  -868,  2465,  -868,  -868,  -868,
    2465,   392,  -868,  -868,  -868,   354,  -868,  -868,  -868,   275,
    2890,  2890,  -868,  -868,  2465,  -868,  -868,  -868,   395,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  2890,  2890,  -868,
    -868,  -868,  -868,   417,  -868,  -868,   278,  -868,  2890,   428,
    -868,  -868,  -868,    51,   429,  -868,   286,   288,   292,    74,
     435,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,   437,  -868,  2890,   438,  -868,  2890,   439,  -868,
    -868,  -868,  2890,  -868,   157,  -868,  -868,  -868,   169,  -868,
    2890,  -868,  -868,  2890,   434,  -868,  -868,   410,    57,  1237,
    -868,  1050,  1050,  -868,   411,   413,   414,   418,   419,   420,
     110,   421,  2890,  2465,  2465,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,   412,  -868,  -868,  2890,  2890,  -868,
    2890,  2890,  2890,  2890,  2890,  2890,  2890,  2890,  2890,  2890,
    2890,  2890,  2890,  2890,  2890,  2890,  2890,  3096,   416,   231,
    -868,  -868,   423,  -868,  -868,   424,   425,  -868,  -868,  -868,
    -868,  -868,  2890,  -868,  2890,  1847,   426,   440,  2890,  2890,
    2890,  2890,  2890,  2890,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,   430,  -868,   431,   284,   289,  3096,  3096,  3096,
    3096,  3096,  3096,  3096,  3096,  3096,  3096,  3096,  3096,  3096,
     -73,  3302,  3714,   433,   441,  2465,  -868,  -868,   391,   394,
     396,   397,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  2465,   447,  -868,  -868,  -868,   427,   333,   448,
     333,   449,   333,   450,   333,   452,   333,  -868,  2890,   444,
    -868,  -868,   213,   217,    46,    95,  -868,  -868,  -868,   445,
     333,   451,  -868,  -868,   236,   238,   115,   145,  -868,  -868,
     446,  -868,  -868,  2465,  -868,  -868,  2465,  2465,  -868,  -868,
    -868,   436,   260,  -868,   479,  2890,  -868,  -868,  -868,  -868,
    2465,  -868,  2890,   480,   482,  -868,  -868,  2465,   432,   483,
    2890,   385,   485,  2890,  -868,  -868,  -868,  -868,  -868,  -868,
     123,  -868,  -868,   455,   474,    88,  -868,   351,  -868,  -123,
     490,    57,  -123,   -40,  -868,  2890,  -868,  2890,  -868,  -868,
    -868,  -868,  -868,  -868,  1050,  -868,  2890,   463,  2890,  2890,
     465,    10,  -868,  1237,  -868,  -868,  2890,   277,   279,   280,
     283,   287,   470,   477,   478,  -868,   486,   488,   489,   491,
     493,  2890,   511,   512,   514,   515,   494,   495,   496,   500,
     517,   501,   502,   503,   504,   505,   522,   538,   507,   508,
     513,    60,   326,   516,  2890,  2890,  2890,   518,    58,    82,
    2890,  3096,   519,   521,   523,   525,   526,   527,   529,  2890,
    2890,  2890,  2890,   282,   282,   293,   293,   293,   293,   293,
     293,   293,   293,   264,    19,    19,   361,  3714,  3714,  -868,
    -868,   329,   331,  -868,  -868,  2890,   333,  2890,   333,   535,
     537,  2465,    81,  -868,   333,  -868,   333,  -868,   333,  -868,
     333,    55,  -868,  2890,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  2890,  -868,   333,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,   333,  -868,  -868,  -868,  -868,  -868,  -868,
     352,   355,   357,   360,   558,  2890,   566,   528,   532,   443,
    2890,  2890,   572,   574,  -868,   -52,   510,   362,  2890,   576,
    -868,  -868,  -868,   550,   363,   551,  -868,  2890,   367,  2890,
    -868,  -123,   584,  -868,   442,   454,  -868,  -868,  -868,  -868,
    -868,  -868,  2890,   586,   453,   590,   560,  2890,  -868,   593,
    -868,  -868,  -868,  -868,  -868,   379,   383,   387,  -868,  -868,
    -868,  -868,  -868,   562,  2890,  2890,  2890,  2890,  -868,  -868,
    -868,  -868,  2890,  -868,  -868,  -868,  -868,  -868,  2890,  2890,
    -868,  -868,  -868,  3714,   563,  -868,   564,   597,   608,  -868,
    2890,  -868,  2890,   609,   594,  -868,  -868,  -868,  -868,  -868,
    -868,  2890,   466,   580,  -868,  -868,  3714,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,   401,   402,  -868,  -868,  -868,
    -868,  -868,  -868,   587,  -868,   588,  -868,   403,   138,  -868,
     621,  -868,   623,   624,  -868,   625,  -868,   626,  -868,   622,
    2465,   627,  2890,  2890,   333,  -868,   598,   599,  2890,   333,
    -868,  -868,  2890,  -868,    85,  2890,   363,   629,   600,   363,
     492,   193,   497,   499,  -868,  -123,  -868,  -868,   601,  2890,
    -868,  2890,   628,   603,  2890,  -868,  -868,  -868,  -868,   604,
     606,   148,   158,   607,   613,   614,   616,  -868,  -868,  2890,
    2890,   617,   618,   619,  -868,  -868,  -868,  -868,  -868,   456,
     457,  -868,   630,  -868,   631,  -868,  2890,   333,   652,   653,
     654,  2890,  -868,  -868,  2890,  -868,  -868,  -868,   649,   655,
     632,   633,   546,  2890,   656,   591,   634,   363,  -868,   635,
    -868,   367,   669,    57,  -868,  -868,  -868,   665,  -868,  -868,
    2890,   666,   641,  -868,  -868,  2890,  -868,  2890,  -868,  -868,
    -868,  -868,  -868,   642,   645,  -868,  -868,  -868,  -868,  -868,
     459,   460,   648,   650,   352,   355,   357,  -868,  -868,  2890,
    2890,  -868,  -868,  2890,   651,  2890,  2890,  -868,  -868,  -868,
    -868,   367,   681,  2890,  -868,  2890,  -868,   657,   658,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,   678,  -868,  -868,  -868,   367,  -868,  -868,  -868,  -868,
    2890,  -868,  -868
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     517,     0,   505,     1,   504,     0,     0,     0,     0,   489,
       0,     0,   453,     0,     0,   480,     0,     0,     0,   289,
       0,   438,   442,   439,     0,     0,     0,     0,     0,     0,
     481,   436,     0,     0,     0,   431,   479,     0,     0,     0,
     486,   488,   434,   437,   444,   441,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   427,   428,     0,     0,     0,     0,   418,
     419,   420,   421,   422,   413,   414,     0,     0,     0,   501,
     509,   506,   513,   515,   518,   429,   430,     0,     0,     0,
      83,    84,     0,     0,     0,     0,   127,   128,     0,   153,
     154,   155,   156,     0,   118,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   120,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   140,   141,   142,     0,
       0,     0,   151,   157,     0,     0,     0,     0,     0,   158,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
       0,     0,    49,    54,    55,    56,    57,    58,    59,    62,
      63,     0,    68,    72,    70,   363,     2,    12,    15,    17,
      81,    20,   411,     0,     0,   190,   191,   394,     0,     0,
       0,   204,   205,   396,     0,     0,     0,   215,   216,   397,
       0,     0,     0,     0,     0,     0,     0,   184,   185,   393,
       0,     0,   247,   248,   398,     0,   250,   251,   252,   256,
     257,   399,   279,   280,     0,     0,     0,   287,   288,   404,
       0,   482,     0,   299,   407,   295,   296,   483,     0,     0,
     262,   263,     0,   266,   267,   401,     0,   270,   271,   402,
       0,   273,   277,   278,   403,     0,   471,   477,   478,   459,
       0,     0,   503,   432,     0,   260,   261,   400,     0,   302,
     303,   405,   297,   298,   484,   487,   446,     0,     0,   445,
     448,   449,   443,     0,   321,   322,     0,   485,     0,     0,
     409,   304,   406,   337,   343,   494,   463,   454,   464,   353,
     359,   457,   458,   410,   472,   473,   474,   373,   371,   370,
     372,   374,     0,   475,     0,     0,   412,     0,     0,   417,
     425,   426,     0,   423,     0,   387,   389,   415,     0,   416,
       0,   511,   476,     0,   499,   465,   462,     0,     0,   505,
     507,   505,   505,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    29,    30,    32,    34,
      35,    31,    36,   107,     0,   121,   122,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,   126,     0,   124,   125,     0,     0,   139,   133,   134,
     135,   136,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    47,    50,    51,    52,    53,
      48,    61,    69,   114,     0,   368,   366,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,   198,     0,     0,
       0,     0,    28,   206,   212,   207,   208,   213,   214,   209,
     210,   211,     0,     0,   196,   197,   395,   161,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   160,     0,     0,
     237,   238,     0,     0,     0,     0,   234,   233,   159,     0,
       0,     0,   222,   223,     0,     0,     0,     0,   219,   218,
       0,   254,   249,     0,   284,   281,     0,     0,   314,   318,
     316,     0,     0,   440,     0,     0,   269,   268,   275,   272,
       0,   433,     0,     0,     0,   259,   258,     0,     0,   447,
       0,     0,     0,     0,   335,   327,   329,   334,   331,   336,
       0,   333,   341,     0,     0,     0,   467,     0,   469,     0,
     354,     0,     0,     0,   381,   382,   384,   385,   424,   388,
     390,   391,   392,   408,   505,   495,     0,     0,     0,     0,
       0,   501,   510,   505,   514,   516,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,     5,     7,     8,     9,    10,
       6,     3,     4,    16,    18,    19,     0,     0,     0,    25,
      21,     0,     0,   188,   186,     0,     0,     0,     0,     0,
       0,     0,     0,   166,     0,   178,     0,   170,     0,   174,
       0,   162,   235,     0,   242,   241,   246,   245,   240,   244,
     239,   243,     0,   220,     0,   227,   226,   231,   230,   225,
     229,   224,   228,     0,   255,   253,   285,   282,   286,   283,
       0,     0,     0,     0,   290,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   435,     0,     0,     0,     0,   323,
     328,   330,   332,     0,     0,     0,   344,     0,     0,     0,
     356,     0,   355,   360,   378,   376,   375,   380,   383,   386,
     512,   496,     0,   361,     0,   345,     0,     0,   508,     0,
      80,    73,    75,    79,    77,     0,     0,     0,    82,    86,
      85,    88,    87,     0,     0,     0,     0,     0,    95,    96,
      97,   106,     0,   100,   101,   102,   103,   104,     0,     0,
     116,   117,   108,     0,     0,   112,     0,     0,     0,   143,
       0,    98,     0,     0,    27,   149,   144,   145,   146,   147,
     148,     0,     0,     0,   369,   367,     0,    23,    26,   189,
     187,   203,   200,   202,   199,     0,     0,   194,   192,   163,
     176,   168,   171,   165,   177,   169,   173,     0,     0,   232,
       0,   217,     0,   305,   315,   308,   319,   311,   317,   291,
       0,     0,     0,     0,     0,   460,     0,     0,     0,     0,
     450,   451,     0,   320,     0,     0,     0,   325,     0,     0,
       0,   347,     0,     0,   357,     0,   379,   377,     0,     0,
     466,     0,     0,     0,     0,    74,    76,    78,   130,     0,
       0,     0,     0,     0,     0,     0,     0,   113,   131,     0,
       0,     0,     0,     0,   115,    65,    24,   195,   193,     0,
       0,   179,   164,   175,   167,   172,     0,     0,     0,     0,
       0,     0,   293,   292,     0,   265,   276,   274,     0,     0,
       0,     0,   452,     0,     0,     0,     0,     0,   338,     0,
     468,     0,   348,     0,   456,   470,   358,     0,   362,   346,
       0,     0,     0,    89,    90,     0,    91,     0,    93,   105,
     111,   110,    22,     0,     0,    99,   152,    67,   181,   183,
       0,     0,     0,     0,     0,     0,     0,   294,   264,     0,
       0,   301,   300,     0,     0,     0,     0,   342,   326,   340,
     350,     0,   349,     0,   498,     0,   137,     0,     0,   138,
     132,   180,   182,   236,   221,   307,   310,   313,   490,   491,
     461,     0,   492,   324,   351,     0,   500,   502,    92,    94,
       0,   352,   493
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -868,    -7,   -97,  -124,   255,  -377,   348,  -868,  -868,  -868,
    -136,  -868,  -868,  -868,   484,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,   498,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -271,  -868,  -266,  -868,  -261,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -784,  -337,  -868,  -868,  -868,  -868,   155,  -624,
    -867,   -54,  -621,   -56,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -327,  -868,  -868,  -868,  -323,  -868,  -868,  -868
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   745,   176,   177,   178,   179,   196,   362,   363,   180,
     181,   424,   628,   629,   489,   207,   208,   209,   185,   186,
     187,   464,   465,   466,   191,   192,   193,   458,   197,   198,
     199,   212,   213,   214,   219,   220,   221,   265,   266,   267,
     243,   244,   245,   247,   248,   249,   252,   253,   254,   227,
     228,   229,   233,   237,   274,   234,   269,   270,   271,   292,
     834,   908,   836,   909,   838,   910,   231,   700,   702,   701,
     287,   290,   858,   542,   294,   543,   544,   723,   295,   746,
     862,   301,   744,   182,   632,   631,   312,   737,   313,   316,
     319,   327,   329,    81,   238,   547,   568,   727,   729,   337,
     567,   338,    82,   573,    83,   339,    84,   564,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     175,   570,   303,   302,   195,   407,   803,   210,   802,   183,
     611,   230,   572,   331,   462,   332,   332,   242,   574,   575,
     255,   256,   333,   333,   201,   468,   470,   262,   263,   334,
     334,   472,   202,   275,   194,   422,   474,   402,   646,   282,
     278,   286,   440,   441,   291,   364,   392,  -497,  -497,   203,
     734,   175,   304,   -64,   194,   315,   390,   215,   318,   320,
     321,   644,   645,   508,   980,   790,   323,   783,   188,   216,
     217,  -339,   926,   189,    85,   929,   250,   204,   205,   324,
     534,   549,   351,   440,   441,   511,   534,     3,   827,   792,
      86,   388,   923,   307,   550,   678,   369,   791,   200,   453,
     454,   308,   299,   300,   679,   258,   860,   828,   863,   389,
     232,   512,   509,   190,  1004,   257,   279,   819,   868,   647,
     218,   585,   735,   873,   924,   246,   551,   736,   391,   535,
     536,   537,   325,   326,   820,   535,   536,   537,  1011,   251,
     538,   427,   428,   978,   680,   429,   538,   430,   431,   432,
     433,   434,   442,   681,   510,   945,   309,   310,   311,   259,
     335,   335,   821,   822,   689,   947,   423,   365,   393,   260,
     455,   456,   457,   690,   902,   850,   443,   893,   539,   453,
     459,   446,   448,   450,   539,   366,   394,   946,   582,   583,
     540,   903,   403,   442,   691,   280,   540,   948,   541,   584,
     931,   720,   721,   692,   541,   235,   184,   236,   501,   355,
     419,   463,   722,   932,   732,   261,   420,   504,   264,   904,
     905,   206,   469,   471,   222,   223,   224,   225,   473,   305,
     306,   513,   514,   475,   435,   268,   226,   336,   336,   516,
     276,   740,   436,   518,   794,   933,   748,   939,   938,   283,
     455,   456,   460,   523,   524,   559,   560,   525,   356,   357,
     358,   272,   425,   273,   426,   561,   562,   359,   360,   361,
     528,   529,   415,   674,   675,   416,   417,   676,   677,   477,
     478,   532,   418,   438,  -365,   439,   277,   479,  -365,  -364,
    -365,   480,   481,  -364,   288,  -364,   685,   686,   687,   688,
     482,   427,   428,   633,   634,   649,   650,   554,   289,   483,
     556,   484,   485,   293,   296,   558,   297,   322,   298,   328,
     486,   487,   330,   563,   340,   341,   565,   342,   343,   352,
     344,   488,   635,   636,   637,   638,   639,   640,   641,   642,
     353,   354,   367,   368,   370,   586,   587,   589,   395,   371,
     372,   373,   374,   375,   376,   377,   396,   378,   379,   397,
     592,   593,   211,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     380,   381,   382,   383,   384,   385,   398,   386,   387,   399,
     400,   404,   281,   401,   408,   617,   409,   618,   619,   477,
     490,   622,   623,   624,   625,   626,   627,   491,   414,   421,
     410,   492,   493,   411,   412,   413,   437,   445,   452,   194,
     494,   476,   515,   503,   506,   520,   522,   521,   507,   495,
     530,   496,   497,   527,   531,   533,   545,   546,   653,  -455,
     498,   499,   552,   548,   553,   555,   557,   566,   569,   576,
     591,   488,   577,   578,   612,   659,   613,   579,   580,   581,
     585,   614,   615,   616,   620,   621,   651,   655,   -66,   630,
     656,   672,   657,   658,   652,   661,   664,   666,   668,   662,
     670,   673,   703,   682,   693,   704,   705,   710,   684,   711,
     715,   717,   718,   724,   725,   730,   694,   731,   733,   696,
     698,   742,   728,   747,   750,   714,   751,   752,   706,   755,
     753,   807,   808,   707,   754,   709,   756,   757,   764,   765,
     712,   766,   767,   716,   772,   758,   719,   759,   760,   778,
     761,   444,   762,   768,   769,   770,   447,   449,   451,   771,
     773,   774,   775,   776,   777,   779,   780,   781,   738,   467,
     739,   784,   782,   806,   809,   785,   810,   789,   795,   741,
     796,   743,   797,   502,   798,   799,   800,   801,   815,   749,
     816,   840,   505,   842,   843,   804,   805,   833,   844,   848,
     835,   849,   837,   855,   763,   839,   852,   853,   856,   859,
     857,   865,   861,   869,   517,   845,   982,   871,   519,   872,
     874,   878,   887,   888,   889,   870,   875,   786,   787,   788,
     876,   866,   526,   793,   877,   890,   792,   440,   894,   895,
     899,   900,   743,   867,   175,   175,   897,   898,   906,   901,
     907,  -306,  -309,  -312,   914,   911,   927,   918,   919,   928,
     937,   940,   941,   943,   930,   944,   949,   886,   811,   934,
     813,   935,   950,   951,   817,   952,   955,   956,   957,   964,
     965,   966,   969,   960,   961,   973,   829,   976,   970,   975,
     896,   971,   972,   977,   979,   830,   981,   864,   983,   985,
     986,   989,   958,   959,   990,   991,   992,   993,  1005,   994,
    1001,  1010,   643,   995,   461,   500,  1008,  1009,   841,   996,
     726,   588,   590,   846,   847,   997,     0,     0,     0,     0,
       0,   854,     0,     0,     0,     0,     0,     0,     0,     0,
     743,     0,   743,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   879,   880,   881,
     882,     0,     0,     0,     0,   883,     0,     0,     0,     0,
       0,   884,   885,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   891,     0,   892,     0,     0,     0,     0,
       0,     0,     0,   654,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     660,   936,     0,     0,     0,     0,   663,     0,   665,     0,
     667,     0,   669,     0,   671,     0,     0,     0,     0,     0,
       0,     0,     0,   912,     0,   915,   916,     0,   683,     0,
       0,   920,     0,     0,     0,   922,     0,     0,   925,     0,
       0,   695,     0,     0,   697,   699,     0,     0,     0,     0,
       0,     0,   743,     0,     0,     0,     0,   942,   708,     0,
       0,     0,     0,     0,     0,   713,     0,     0,     0,     0,
       0,     0,   953,   954,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   962,
       0,     0,     0,     0,   967,     0,     0,   968,     0,     0,
       0,     0,     0,     0,     0,     0,   974,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   984,     0,     0,     0,     0,   987,     0,
     988,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   998,   999,     0,     0,  1000,     0,  1002,  1003,
       0,     0,     0,     0,     0,     0,  1006,     0,  1007,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1012,   812,     0,   814,     0,     0,   818,
       0,     0,   823,     0,   824,     0,   825,     0,   826,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   831,     0,     0,     0,     0,     0,     0,     0,
       0,   832,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     0,     0,     0,     0,     0,     0,
       5,     6,     0,   851,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     0,     0,     0,     8,     9,     0,    10,
       0,    11,    12,     0,    13,    14,     0,     0,     0,     0,
       0,     0,    15,     0,    16,    17,    18,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,    20,     0,     0,
       0,     0,    21,    22,    23,    24,    25,    26,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,     0,    29,    30,     0,    31,     0,     0,    32,    33,
      34,     0,    35,    36,    37,    38,    39,    40,    41,     0,
      42,     0,     0,     0,    43,    44,    45,    46,    47,     0,
      48,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,   913,     0,
       0,     0,   917,    51,     0,     0,    52,   921,    53,    54,
      55,     0,     0,    56,     0,     0,     0,    57,     0,    58,
       0,     0,    59,    60,     0,     0,     0,     0,    61,     0,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,     0,     0,    74,    75,    76,    77,    78,
       4,     0,     0,     0,     0,     0,     0,     5,     6,     0,
       0,     0,     0,     0,     0,   963,     0,     0,     0,     7,
       0,     0,     0,     8,     9,     0,    10,     0,    11,    12,
       0,    13,    14,     0,     0,    79,     0,    80,     0,    15,
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
       0,     0,    74,    75,    76,    77,    78,   314,     0,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,   571,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,    94,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,     0,
      98,     0,     0,     0,     0,     0,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,     0,     0,     0,     0,     0,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,     0,
     121,   122,   123,     0,   124,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,     0,
     127,     0,   128,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,   130,     0,     0,   131,     0,   132,   133,
     134,   135,     0,   136,   137,     0,     0,     0,     0,   138,
     139,   140,   141,     0,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   317,     0,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,    94,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
       0,    98,     0,     0,     0,     0,     0,    99,   100,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     0,     0,     0,   118,   119,   120,
       0,   121,   122,   123,     0,   124,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
       0,   127,     0,   128,     0,     0,     0,     0,     0,     0,
       0,   129,     0,     0,   130,     0,     0,   131,     0,   132,
     133,   134,   135,     0,   136,   137,     0,     0,     0,     0,
     138,   139,   140,   141,     0,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,    87,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,     0,
       0,     0,     0,     0,     0,    88,   345,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,     0,
       0,    94,     0,     0,    95,   346,   347,   348,     0,     0,
       0,     0,     0,     0,    96,    97,   349,    98,     0,     0,
       0,     0,     0,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,   104,
     105,     0,     0,     0,     0,     0,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,   350,   121,   122,   123,
       0,   124,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,     0,   127,     0,   128,
       0,     0,     0,     0,     0,     0,     0,   129,     0,     0,
     130,     0,     0,   131,     0,   132,   133,   134,   135,     0,
     136,   137,     0,     0,     0,     0,   138,   139,   140,   141,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,    87,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,     0,     0,     0,     0,     0,
       0,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,   240,   241,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    93,     0,     0,    94,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,     0,    98,     0,     0,     0,     0,     0,    99,
     100,   101,   102,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,   104,   105,     0,     0,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     0,     0,     0,   118,
     119,   120,     0,   121,   122,   123,     0,   124,   125,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,     0,   127,     0,   128,     0,     0,     0,     0,
       0,     0,     0,   129,     0,     0,   130,     0,     0,   131,
       0,   132,   133,   134,   135,     0,   136,   137,     0,     0,
       0,     0,   138,   139,   140,   141,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    87,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,     0,     0,     0,     0,     0,     0,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,   284,   285,     0,     0,     0,
       0,     0,     0,    90,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,    94,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,     0,    98,
       0,     0,     0,     0,     0,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,   104,   105,     0,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,     0,   121,
     122,   123,     0,   124,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,     0,   127,
       0,   128,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     0,   130,     0,     0,   131,     0,   132,   133,   134,
     135,     0,   136,   137,     0,     0,     0,     0,   138,   139,
     140,   141,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,    87,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,     0,     0,     0,
       0,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,     0,     0,    94,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,   194,    96,    97,     0,    98,     0,     0,     0,     0,
       0,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,   104,   105,     0,
       0,     0,     0,     0,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,     0,     0,
       0,   118,   119,   120,     0,   121,   122,   123,     0,   124,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,   127,     0,   128,     0,     0,
       0,     0,     0,     0,     0,   129,     0,     0,   130,     0,
       0,   131,     0,   132,   133,   134,   135,     0,   136,   137,
       0,     0,     0,     0,   138,   139,   140,   141,     0,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   344,     0,     0,     0,     0,     0,
       0,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,    94,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,     0,    98,     0,     0,     0,     0,     0,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,   105,     0,     0,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,     0,   121,   122,   123,     0,   124,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,     0,   127,     0,   128,     0,     0,     0,
       0,     0,     0,     0,   129,     0,     0,   130,     0,     0,
     131,     0,   132,   133,   134,   135,     0,   136,   137,     0,
       0,     0,     0,   138,   139,   140,   141,     0,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    87,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,     0,     0,     0,     0,     0,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,    94,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,     0,
      98,     0,     0,     0,     0,     0,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,     0,     0,     0,     0,     0,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,     0,
     121,   122,   123,     0,   124,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,     0,
     127,     0,   128,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,   130,     0,     0,   131,     0,   132,   133,
     134,   135,     0,   136,   137,     0,     0,     0,     0,   138,
     139,   140,   141,     0,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,    87,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,     0,     0,
       0,     0,     0,     0,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,     0,     0,
      94,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,    97,     0,    98,     0,     0,     0,
       0,     0,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
       0,     0,     0,     0,     0,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,     0,   121,   122,   123,     0,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,     0,   127,     0,   128,     0,
       0,     0,     0,     0,     0,     0,   129,     0,     0,   130,
       0,     0,   131,     0,   132,   133,   134,   135,     0,   136,
     137,     0,     0,     0,     0,   138,   139,   140,   141,     0,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    87,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,     0,     0,     0,     0,     0,     0,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,    94,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,     0,    98,     0,     0,     0,     0,     0,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   648,   104,   105,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     126,     0,   127,     0,   128,     0,     0,     0,     0,     0,
       0,     0,   129,     0,     0,   130,     0,     0,   131,     0,
     132,   133,   134,   135,     0,   136,   137,     0,     0,     0,
       0,   138,   139,   140,   406,     0,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    87,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
       0,     0,     0,     0,     0,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   405,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
       0,     0,    94,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,     0,    98,     0,
       0,     0,     0,     0,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,     0,   121,   122,
     123,     0,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,   127,     0,
     128,     0,     0,     0,     0,     0,     0,     0,   129,     0,
       0,   130,     0,     0,   131,     0,   132,   133,   134,   135,
       0,   136,   137,     0,     0,     0,     0,   138,   139,   140,
     406,     0,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,    87,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,     0,     0,     0,     0,
       0,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,    94,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,     0,    98,     0,     0,     0,     0,     0,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,     0,     0,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,     0,   121,   122,   123,     0,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,     0,   127,     0,   128,     0,     0,     0,
       0,     0,     0,     0,   129,     0,     0,   130,     0,     0,
     131,     0,   132,   133,   134,   135,     0,   136,   137,     0,
       0,     0,     0,   138,   139,   140,   406,     0,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,     0,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174
};

static const yytype_int16 yycheck[] =
{
       7,   338,    58,    57,    11,   141,   630,    14,   629,    28,
     387,    18,   339,     4,    28,     6,     6,    24,   341,   342,
      27,    28,    13,    13,    28,    28,    28,    34,    35,    20,
      20,    28,    36,    40,    86,    20,    28,    38,   111,    46,
      72,    48,    23,    24,    51,    20,    20,    38,    38,    53,
      90,    58,    59,    38,    86,    62,    90,    28,    65,    66,
      67,   438,   439,    57,   931,     7,    73,     7,    30,    40,
      41,    20,   856,    35,   225,   859,    28,    81,    82,    45,
      29,     7,    89,    23,    24,    20,    29,     0,    33,     7,
     225,    20,     7,   101,    20,    49,   103,    39,    26,    83,
      84,   109,   225,   226,    58,    94,   727,    52,   729,    38,
     225,    46,   106,    75,   981,    94,   148,    36,   742,   192,
      91,    39,   162,   747,    39,    28,    52,   167,   162,    78,
      79,    80,    98,    99,    53,    78,    79,    80,  1005,    91,
      89,     8,     9,   927,    49,    12,    89,    14,    15,    16,
      17,    18,   133,    58,   148,     7,   164,   165,   166,   148,
     151,   151,    81,    82,    49,     7,   151,   142,   142,    38,
     154,   155,   156,    58,    36,   227,   183,   801,   127,    83,
      84,   188,   189,   190,   127,   160,   160,    39,    78,    79,
     139,    53,   193,   133,    49,   227,   139,    39,   147,    89,
       7,    78,    79,    58,   147,   225,   225,   227,   215,    29,
     208,   225,    89,    20,   551,    38,   214,   224,    28,    81,
      82,   225,   225,   225,    46,    47,    48,    49,   225,    46,
      47,   238,   239,   225,   101,    28,    58,   228,   228,   246,
     148,   564,   109,   250,   621,    52,   573,   871,   869,   225,
     154,   155,   156,   260,   261,    98,    99,   264,    78,    79,
      80,   225,     5,   227,     7,    96,    97,    87,    88,    89,
     277,   278,   204,    60,    61,   207,   208,    60,    61,    28,
      29,   288,   214,    19,     0,    21,    72,    36,     4,     0,
       6,    40,    41,     4,    38,     6,    60,    61,    60,    61,
      49,     8,     9,   427,   428,   441,   442,   314,   225,    58,
     317,    60,    61,   225,   225,   322,   225,   176,   225,    45,
      69,    70,    13,   330,     6,     4,   333,     4,   227,    38,
      20,    80,   429,   430,   431,   432,   433,   434,   435,   436,
      38,    38,    38,    38,    38,   352,   353,   354,    20,    38,
      38,    38,    38,    38,    38,    38,    20,    38,    38,    20,
     367,   368,    14,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
      38,    38,    38,    38,    38,    38,    20,    38,    38,    20,
      20,    38,    44,    20,    38,   402,    38,   404,   405,    28,
      29,   408,   409,   410,   411,   412,   413,    36,   207,   207,
      38,    40,    41,    38,    38,    38,   134,    28,   227,    86,
      49,    28,     7,    33,    50,    33,   151,    73,    50,    58,
      13,    60,    61,    38,   156,     7,     7,   151,   445,   151,
      69,    70,     7,   151,     7,     7,     7,    13,    38,    38,
      38,    80,    39,    39,    38,   462,   225,    39,    39,    39,
      39,    38,    38,    38,    38,    25,    33,    76,    38,    38,
      76,   478,    76,    76,    33,    28,    28,    28,    28,    52,
      28,    37,    46,    38,    38,   225,     7,     7,    37,     7,
       7,   106,     7,    38,    20,   549,   503,     7,   552,   506,
     507,    38,   151,    38,   227,    73,   227,   227,   515,    39,
     227,   647,   648,   520,   227,   522,    39,    39,     7,     7,
     527,     7,     7,   530,     7,    39,   533,    39,    39,     7,
      39,   183,    39,    39,    39,    39,   188,   189,   190,    39,
      39,    39,    39,    39,    39,     7,    39,    39,   555,   201,
     557,   225,    39,   192,   225,    39,   225,    39,    39,   566,
      39,   568,    39,   215,    39,    39,    39,    38,    33,   576,
      33,    13,   224,     7,    46,   631,   632,   225,    46,     7,
     225,     7,   225,     7,   591,   225,    76,   225,    38,    38,
     227,     7,   225,     7,   246,   152,   933,     7,   250,    39,
       7,    39,    39,    39,     7,   152,   227,   614,   615,   616,
     227,   169,   264,   620,   227,     7,     7,    23,   152,    39,
      33,    33,   629,   169,   631,   632,   225,   225,     7,   226,
       7,     7,     7,     7,     7,    13,     7,    39,    39,    39,
      39,    13,    39,    39,   152,    39,    39,   783,   655,   152,
     657,   152,    39,    39,   661,    39,    39,    39,    39,     7,
       7,     7,    13,    33,    33,   119,   673,    76,    13,    13,
     806,    39,    39,    39,    39,   682,     7,   731,    13,    13,
      39,    39,   226,   226,    39,   226,   226,    39,     7,    39,
      39,    13,   437,   964,   196,   211,    39,    39,   705,   965,
     545,   353,   354,   710,   711,   966,    -1,    -1,    -1,    -1,
      -1,   718,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     727,    -1,   729,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   764,   765,   766,
     767,    -1,    -1,    -1,    -1,   772,    -1,    -1,    -1,    -1,
      -1,   778,   779,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   790,    -1,   792,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   445,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     462,   865,    -1,    -1,    -1,    -1,   468,    -1,   470,    -1,
     472,    -1,   474,    -1,   476,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   840,    -1,   842,   843,    -1,   490,    -1,
      -1,   848,    -1,    -1,    -1,   852,    -1,    -1,   855,    -1,
      -1,   503,    -1,    -1,   506,   507,    -1,    -1,    -1,    -1,
      -1,    -1,   869,    -1,    -1,    -1,    -1,   874,   520,    -1,
      -1,    -1,    -1,    -1,    -1,   527,    -1,    -1,    -1,    -1,
      -1,    -1,   889,   890,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   906,
      -1,    -1,    -1,    -1,   911,    -1,    -1,   914,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   923,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   940,    -1,    -1,    -1,    -1,   945,    -1,
     947,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   969,   970,    -1,    -1,   973,    -1,   975,   976,
      -1,    -1,    -1,    -1,    -1,    -1,   983,    -1,   985,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1010,   656,    -1,   658,    -1,    -1,   661,
      -1,    -1,   664,    -1,   666,    -1,   668,    -1,   670,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   684,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   693,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    11,    -1,   715,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,    29,
      -1,    31,    32,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    44,    45,    46,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    92,    93,    -1,    95,    -1,    -1,    98,    99,
     100,    -1,   102,   103,   104,   105,   106,   107,   108,    -1,
     110,    -1,    -1,    -1,   114,   115,   116,   117,   118,    -1,
     120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,   840,    -1,
      -1,    -1,   844,   143,    -1,    -1,   146,   849,   148,   149,
     150,    -1,    -1,   153,    -1,    -1,    -1,   157,    -1,   159,
      -1,    -1,   162,   163,    -1,    -1,    -1,    -1,   168,    -1,
     170,   171,   172,   173,   174,   175,    -1,   177,   178,   179,
     180,   181,   182,    -1,    -1,   185,   186,   187,   188,   189,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,   907,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    29,    -1,    31,    32,
      -1,    34,    35,    -1,    -1,   225,    -1,   227,    -1,    42,
      -1,    44,    45,    46,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    92,
      93,    -1,    95,    -1,    -1,    98,    99,   100,    -1,   102,
     103,   104,   105,   106,   107,   108,    -1,   110,    -1,    -1,
      -1,   114,   115,   116,   117,   118,    -1,   120,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,    -1,    -1,   146,    -1,   148,   149,   150,    -1,    -1,
     153,    -1,    -1,    -1,   157,    -1,   159,    -1,    -1,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,   170,   171,   172,
     173,   174,   175,    -1,   177,   178,   179,   180,   181,   182,
      -1,    -1,   185,   186,   187,   188,   189,     7,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,   136,   137,   138,    -1,
     140,   141,   142,    -1,   144,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,
     160,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     170,    -1,    -1,   173,    -1,    -1,   176,    -1,   178,   179,
     180,   181,    -1,   183,   184,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    -1,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,     7,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,    -1,   136,   137,   138,
      -1,   140,   141,   142,    -1,   144,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
      -1,   160,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   170,    -1,    -1,   173,    -1,    -1,   176,    -1,   178,
     179,   180,   181,    -1,   183,   184,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,     9,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,   136,   137,   138,   139,   140,   141,   142,
      -1,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,
     173,    -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,
     183,   184,    -1,    -1,    -1,    -1,   189,   190,   191,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,     9,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,
      97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,    -1,   136,
     137,   138,    -1,   140,   141,   142,    -1,   144,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,    -1,   160,    -1,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   170,    -1,    -1,   173,    -1,    -1,   176,
      -1,   178,   179,   180,   181,    -1,   183,   184,    -1,    -1,
      -1,    -1,   189,   190,   191,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,     9,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,   136,   137,   138,    -1,   140,
     141,   142,    -1,   144,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,   160,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,
      -1,    -1,   173,    -1,    -1,   176,    -1,   178,   179,   180,
     181,    -1,   183,   184,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,     9,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
      -1,   136,   137,   138,    -1,   140,   141,   142,    -1,   144,
     145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,   173,    -1,
      -1,   176,    -1,   178,   179,   180,   181,    -1,   183,   184,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
      -1,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
     136,   137,   138,    -1,   140,   141,   142,    -1,   144,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,    -1,   160,    -1,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,    -1,    -1,   173,    -1,    -1,
     176,    -1,   178,   179,   180,   181,    -1,   183,   184,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,     9,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,   136,   137,   138,    -1,
     140,   141,   142,    -1,   144,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,
     160,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     170,    -1,    -1,   173,    -1,    -1,   176,    -1,   178,   179,
     180,   181,    -1,   183,   184,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    -1,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,     9,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,    -1,   136,   137,   138,    -1,   140,   141,   142,    -1,
     144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,   173,
      -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,   183,
     184,    -1,    -1,    -1,    -1,   189,   190,   191,   192,    -1,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,     9,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,   136,   137,
     138,    -1,   140,   141,   142,    -1,   144,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,    -1,   160,    -1,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   170,    -1,    -1,   173,    -1,    -1,   176,    -1,
     178,   179,   180,   181,    -1,   183,   184,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    -1,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,     9,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    90,    -1,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,   136,   137,   138,    -1,   140,   141,
     142,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,
      -1,   173,    -1,    -1,   176,    -1,   178,   179,   180,   181,
      -1,   183,   184,    -1,    -1,    -1,    -1,   189,   190,   191,
     192,    -1,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,     9,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,    -1,
     136,   137,   138,    -1,   140,   141,   142,    -1,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,    -1,   160,    -1,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,    -1,    -1,   173,    -1,    -1,
     176,    -1,   178,   179,   180,   181,    -1,   183,   184,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   337,   338,     0,     3,    10,    11,    22,    26,    27,
      29,    31,    32,    34,    35,    42,    44,    45,    46,    51,
      57,    62,    63,    64,    65,    66,    67,    72,    90,    92,
      93,    95,    98,    99,   100,   102,   103,   104,   105,   106,
     107,   108,   110,   114,   115,   116,   117,   118,   120,   121,
     135,   143,   146,   148,   149,   150,   153,   157,   159,   162,
     163,   168,   170,   171,   172,   173,   174,   175,   177,   178,
     179,   180,   181,   182,   185,   186,   187,   188,   189,   225,
     227,   322,   331,   333,   335,   225,   225,     9,    28,    38,
      54,    55,    56,    71,    74,    77,    87,    88,    90,    96,
      97,    98,    99,   111,   112,   113,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   136,   137,
     138,   140,   141,   142,   144,   145,   158,   160,   162,   170,
     173,   176,   178,   179,   180,   181,   183,   184,   189,   190,
     191,   192,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   230,   231,   232,   233,   234,
     238,   239,   312,    28,   225,   247,   248,   249,    30,    35,
      75,   253,   254,   255,    86,   230,   235,   257,   258,   259,
      26,    28,    36,    53,    81,    82,   225,   244,   245,   246,
     230,   235,   260,   261,   262,    28,    40,    41,    91,   263,
     264,   265,    46,    47,    48,    49,    58,   278,   279,   280,
     230,   295,   225,   281,   284,   225,   227,   282,   323,    28,
      40,    41,   230,   269,   270,   271,    28,   272,   273,   274,
      28,    91,   275,   276,   277,   230,   230,    94,    94,   148,
      38,    38,   230,   230,    28,   266,   267,   268,    28,   285,
     286,   287,   225,   227,   283,   230,   148,    72,    72,   148,
     227,   235,   230,   225,    46,    47,   230,   299,    38,   225,
     300,   230,   288,   225,   303,   307,   225,   225,   225,   225,
     226,   310,   310,   312,   230,    46,    47,   101,   109,   164,
     165,   166,   315,   317,     7,   230,   318,     7,   230,   319,
     230,   230,   176,   230,    45,    98,    99,   320,    45,   321,
      13,     4,     6,    13,    20,   151,   228,   328,   330,   334,
       6,     4,     4,   227,    20,    29,    78,    79,    80,    89,
     139,   230,    38,    38,    38,    29,    78,    79,    80,    87,
      88,    89,   236,   237,    20,   142,   160,    38,    38,   230,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    20,    38,
      90,   162,    20,   142,   160,    20,    20,    20,    20,    20,
      20,    20,    38,   193,    38,    38,   192,   239,    38,    38,
      38,    38,    38,    38,   207,   204,   207,   208,   214,   208,
     214,   207,    20,   151,   240,     5,     7,     8,     9,    12,
      14,    15,    16,    17,    18,   101,   109,   134,    19,    21,
      23,    24,   133,   230,   235,    28,   230,   235,   230,   235,
     230,   235,   227,    83,    84,   154,   155,   156,   256,    84,
     156,   256,    28,   225,   250,   251,   252,   235,    28,   225,
      28,   225,    28,   225,    28,   225,    28,    28,    29,    36,
      40,    41,    49,    58,    60,    61,    69,    70,    80,   243,
      29,    36,    40,    41,    49,    58,    60,    61,    69,    70,
     243,   230,   235,    33,   230,   235,    50,    50,    57,   106,
     148,    20,    46,   230,   230,     7,   230,   235,   230,   235,
      33,    73,   151,   230,   230,   230,   235,    38,   230,   230,
      13,   156,   230,     7,    29,    78,    79,    80,    89,   127,
     139,   147,   302,   304,   305,     7,   151,   324,   151,     7,
      20,    52,     7,     7,   230,     7,   230,     7,   230,    98,
      99,    96,    97,   230,   336,   230,    13,   329,   325,    38,
     302,   225,   331,   332,   335,   335,    38,    39,    39,    39,
      39,    39,    78,    79,    89,    39,   230,   230,   235,   230,
     235,    38,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   234,    38,   225,    38,    38,    38,   230,   230,   230,
      38,    25,   230,   230,   230,   230,   230,   230,   241,   242,
      38,   314,   313,   232,   232,   231,   231,   231,   231,   231,
     231,   231,   231,   233,   234,   234,   111,   192,   111,   239,
     239,    33,    33,   230,   235,    76,    76,    76,    76,   230,
     235,    28,    52,   235,    28,   235,    28,   235,    28,   235,
      28,   235,   230,    37,    60,    61,    60,    61,    49,    58,
      49,    58,    38,   235,    37,    60,    61,    60,    61,    49,
      58,    49,    58,    38,   230,   235,   230,   235,   230,   235,
     296,   298,   297,    46,   225,     7,   230,   230,   235,   230,
       7,     7,   230,   235,    73,     7,   230,   106,     7,   230,
      78,    79,    89,   306,    38,    20,   307,   326,   151,   327,
     310,     7,   302,   310,    90,   162,   167,   316,   230,   230,
     335,   230,    38,   230,   311,   230,   308,    38,   331,   230,
     227,   227,   227,   227,   227,    39,    39,    39,    39,    39,
      39,    39,    39,   230,     7,     7,     7,     7,    39,    39,
      39,    39,     7,    39,    39,    39,    39,    39,     7,     7,
      39,    39,    39,     7,   225,    39,   230,   230,   230,    39,
       7,    39,     7,   230,   234,    39,    39,    39,    39,    39,
      39,    38,   311,   308,   312,   312,   192,   239,   239,   225,
     225,   230,   235,   230,   235,    33,    33,   230,   235,    36,
      53,    81,    82,   235,   235,   235,   235,    33,    52,   230,
     230,   235,   235,   225,   289,   225,   291,   225,   293,   225,
      13,   230,     7,    46,    46,   152,   230,   230,     7,     7,
     227,   235,    76,   225,   230,     7,    38,   227,   301,    38,
     311,   225,   309,   311,   310,     7,   169,   169,   308,     7,
     152,     7,    39,   308,     7,   227,   227,   227,    39,   230,
     230,   230,   230,   230,   230,   230,   239,    39,    39,     7,
       7,   230,   230,   308,   152,    39,   239,   225,   225,    33,
      33,   226,    36,    53,    81,    82,     7,     7,   290,   292,
     294,    13,   230,   235,     7,   230,   230,   235,    39,    39,
     230,   235,   230,     7,    39,   230,   301,     7,    39,   301,
     152,     7,    20,    52,   152,   152,   310,    39,   311,   308,
      13,    39,   230,    39,    39,     7,    39,     7,    39,    39,
      39,    39,    39,   230,   230,    39,    39,    39,   226,   226,
      33,    33,   230,   235,     7,     7,     7,   230,   230,    13,
      13,    39,    39,   119,   230,    13,    76,    39,   301,    39,
     309,     7,   302,    13,   230,    13,    39,   230,   230,    39,
      39,   226,   226,    39,    39,   289,   291,   293,   230,   230,
     230,    39,   230,   230,   309,     7,   230,   230,    39,    39,
      13,   309,   230
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   229,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   231,   231,   231,   232,   232,   233,   233,   233,
     234,   234,   234,   234,   234,   234,   234,   234,   235,   236,
     236,   236,   236,   236,   236,   236,   237,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   240,   239,   241,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   242,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   243,
     243,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   245,
     245,   245,   245,   245,   246,   246,   247,   247,   248,   248,
     249,   249,   250,   250,   251,   251,   252,   252,   253,   253,
     253,   254,   254,   254,   255,   255,   256,   256,   256,   257,
     257,   257,   258,   258,   258,   259,   259,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   262,   262,   263,
     263,   263,   263,   263,   264,   264,   265,   265,   266,   267,
     268,   268,   269,   269,   270,   270,   271,   271,   272,   273,
     274,   274,   275,   275,   275,   276,   276,   277,   277,   278,
     278,   278,   278,   278,   279,   279,   279,   280,   280,   281,
     281,   281,   281,   281,   281,   282,   282,   283,   283,   284,
     285,   286,   287,   287,   288,   289,   290,   289,   291,   292,
     291,   293,   294,   293,   296,   295,   297,   295,   298,   295,
     299,   299,   299,   300,   300,   301,   301,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   304,   303,   305,
     303,   306,   303,   307,   307,   308,   308,   309,   309,   309,
     309,   309,   309,   310,   310,   310,   310,   310,   310,   310,
     310,   311,   311,   312,   312,   312,   313,   312,   314,   312,
     315,   315,   315,   315,   315,   316,   316,   316,   316,   316,
     317,   318,   318,   318,   319,   319,   319,   320,   320,   320,
     320,   321,   321,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   323,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   324,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   325,   322,   326,   322,   327,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   328,   322,   329,
     322,   330,   322,   322,   322,   322,   331,   332,   331,   334,
     333,   336,   335,   335,   335,   335,   335,   338,   337
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
       1,     2,     3,     4,     5,     4,     3,     5,     4,     4,
       3,     4,     5,     4,     3,     5,     4,     4,     3,     5,
       7,     6,     7,     6,     1,     1,     3,     4,     3,     4,
       1,     1,     3,     4,     3,     4,     1,     1,     2,     4,
       4,     2,     4,     4,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     1,     1,     4,     2,     2,
       3,     7,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     2,     2,     3,     7,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       1,     1,     1,     3,     2,     3,     1,     1,     2,     2,
       1,     1,     1,     1,     6,     5,     1,     1,     2,     2,
       1,     1,     2,     1,     5,     2,     5,     1,     1,     1,
       1,     2,     3,     3,     2,     3,     3,     1,     1,     0,
       3,     4,     5,     5,     6,     1,     1,     1,     1,     1,
       6,     6,     1,     1,     1,     1,     0,     4,     1,     0,
       4,     1,     0,     4,     0,     4,     0,     4,     0,     4,
       4,     1,     1,     3,     7,     1,     3,     1,     2,     1,
       2,     1,     2,     1,     1,     1,     1,     0,     5,     0,
       6,     0,     6,     1,     3,     1,     3,     1,     2,     3,
       3,     4,     5,     1,     2,     3,     3,     4,     5,     1,
       3,     1,     3,     1,     2,     2,     0,     4,     0,     4,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       3,     2,     2,     3,     2,     2,     3,     1,     2,     1,
       2,     2,     2,     2,     2,     3,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     3,     2,
       2,     2,     2,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     2,     3,     2,     2,     1,     1,     2,
       2,     1,     2,     3,     1,     4,     1,     1,     1,     0,
       3,     1,     1,     2,     1,     2,     2,     3,     2,     2,
       5,     5,     6,     1,     2,     0,     6,     2,     2,     2,
       5,     8,     2,     2,     2,     0,     5,     0,     6,     0,
       6,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     2,     2,     2,     2,     1,     2,     1,     1,
       8,     8,     8,    10,     2,     3,     4,     0,     7,     0,
       8,     0,     8,     2,     1,     0,     1,     0,     4,     0,
       3,     0,     4,     1,     3,     1,     3,     0,     2
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
#line 3139 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 85 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3148 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 89 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3156 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 92 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3164 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 95 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3172 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 98 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 3180 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 101 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3188 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 104 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3196 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 107 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 3204 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 114 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3212 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 117 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3221 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 130 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3230 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 134 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3239 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 142 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 3248 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 146 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 3257 "src-generated/ugbc.tab.c"
    break;

  case 23: /* factor: factor HAS BIT exponential  */
#line 150 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[0].string) )->name;
      }
#line 3265 "src-generated/ugbc.tab.c"
    break;

  case 24: /* factor: factor HAS NOT BIT exponential  */
#line 153 "src/ugbc.y"
                                       {
        (yyval.string) = variable_not( _environment, variable_bit( _environment, (yyvsp[-4].string), (yyvsp[0].string) )->name )->name;
      }
#line 3273 "src-generated/ugbc.tab.c"
    break;

  case 25: /* factor: factor IS exponential  */
#line 156 "src/ugbc.y"
                              {
        (yyval.string) = variable_bit( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
      }
#line 3281 "src-generated/ugbc.tab.c"
    break;

  case 26: /* factor: factor IS NOT exponential  */
#line 159 "src/ugbc.y"
                                  {
        (yyval.string) = variable_not( _environment, variable_bit( _environment, (yyvsp[-3].string), (yyvsp[0].string) )->name )->name;
      }
#line 3289 "src-generated/ugbc.tab.c"
    break;

  case 27: /* factor: BIT exponential OF factor  */
#line 162 "src/ugbc.y"
                                  {
        (yyval.string) = variable_bit( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
      }
#line 3297 "src-generated/ugbc.tab.c"
    break;

  case 28: /* direct_integer: HASH Integer  */
#line 168 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3305 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: BYTE  */
#line 173 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3313 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: WORD  */
#line 176 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3321 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition_simple: DWORD  */
#line 179 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3329 "src-generated/ugbc.tab.c"
    break;

  case 32: /* random_definition_simple: POSITION  */
#line 182 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3337 "src-generated/ugbc.tab.c"
    break;

  case 33: /* random_definition_simple: COLOR  */
#line 185 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3345 "src-generated/ugbc.tab.c"
    break;

  case 34: /* random_definition_simple: WIDTH  */
#line 188 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3353 "src-generated/ugbc.tab.c"
    break;

  case 35: /* random_definition_simple: HEIGHT  */
#line 191 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3361 "src-generated/ugbc.tab.c"
    break;

  case 36: /* random_definition: random_definition_simple  */
#line 196 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3369 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: BLACK  */
#line 201 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3378 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: WHITE  */
#line 205 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3387 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: RED  */
#line 209 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3396 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: CYAN  */
#line 213 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3405 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: VIOLET  */
#line 217 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3414 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: GREEN  */
#line 221 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3423 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: BLUE  */
#line 225 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3432 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: YELLOW  */
#line 229 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3441 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: ORANGE  */
#line 233 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3450 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: BROWN  */
#line 237 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3459 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT RED  */
#line 241 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3468 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK GREY  */
#line 245 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3477 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: GREY  */
#line 249 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3486 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: LIGHT GREEN  */
#line 253 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3495 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LIGHT BLUE  */
#line 257 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3504 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: LIGHT GREY  */
#line 261 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3513 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: DARK BLUE  */
#line 265 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3522 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: MAGENTA  */
#line 269 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3531 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: PURPLE  */
#line 273 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3540 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: LAVENDER  */
#line 277 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3549 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: GOLD  */
#line 281 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3558 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: TURQUOISE  */
#line 285 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3567 "src-generated/ugbc.tab.c"
    break;

  case 59: /* color_enumeration: TAN  */
#line 289 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3576 "src-generated/ugbc.tab.c"
    break;

  case 60: /* color_enumeration: YELLOW GREEN  */
#line 293 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3585 "src-generated/ugbc.tab.c"
    break;

  case 61: /* color_enumeration: OLIVE GREEN  */
#line 297 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3594 "src-generated/ugbc.tab.c"
    break;

  case 62: /* color_enumeration: PINK  */
#line 301 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3603 "src-generated/ugbc.tab.c"
    break;

  case 63: /* color_enumeration: PEACH  */
#line 305 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3612 "src-generated/ugbc.tab.c"
    break;

  case 64: /* $@1: %empty  */
#line 311 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3621 "src-generated/ugbc.tab.c"
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
#line 3633 "src-generated/ugbc.tab.c"
    break;

  case 66: /* $@2: %empty  */
#line 322 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3642 "src-generated/ugbc.tab.c"
    break;

  case 67: /* exponential: Identifier DOLLAR $@2 OP indexes CP  */
#line 326 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-5].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-5].string) )->name;
    }
#line 3654 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: Identifier  */
#line 333 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3662 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: Identifier DOLLAR  */
#line 336 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3670 "src-generated/ugbc.tab.c"
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
#line 3684 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: MINUS Integer  */
#line 348 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3693 "src-generated/ugbc.tab.c"
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
#line 3705 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP BYTE CP Integer  */
#line 359 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3714 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP SIGNED BYTE CP Integer  */
#line 363 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3723 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP WORD CP Integer  */
#line 367 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3732 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: OP SIGNED WORD CP Integer  */
#line 371 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3741 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: OP DWORD CP Integer  */
#line 375 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3750 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: OP SIGNED DWORD CP Integer  */
#line 379 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3759 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: OP POSITION CP Integer  */
#line 383 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3768 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: OP COLOR CP Integer  */
#line 387 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3777 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: color_enumeration  */
#line 391 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3785 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: PEEK OP expr CP  */
#line 394 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3793 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: XPEN  */
#line 397 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3801 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: YPEN  */
#line 400 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3809 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: COLLISION OP direct_integer CP  */
#line 403 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3817 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: COLLISION OP expr CP  */
#line 406 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3825 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: HIT OP direct_integer CP  */
#line 409 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3833 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: HIT OP expr CP  */
#line 412 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3841 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: LEFT OP expr COMMA expr CP  */
#line 415 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3849 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 418 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3857 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: MID OP expr COMMA expr CP  */
#line 421 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3865 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 424 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3873 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: INSTR OP expr COMMA expr CP  */
#line 427 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3881 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 430 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3889 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: UPPER OP expr CP  */
#line 433 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3897 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: LOWER OP expr CP  */
#line 436 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3905 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: STR OP expr CP  */
#line 439 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3913 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: BIN OP expr CP  */
#line 442 "src/ugbc.y"
                     {
        (yyval.string) = variable_bin( _environment, (yyvsp[-1].string), NULL )->name;
    }
#line 3921 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: BIN OP expr COMMA expr CP  */
#line 445 "src/ugbc.y"
                                {
        (yyval.string) = variable_bin( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3929 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: SPACE OP expr CP  */
#line 448 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3937 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: FLIP OP expr CP  */
#line 451 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3945 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: CHR OP expr CP  */
#line 454 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3953 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: ASC OP expr CP  */
#line 457 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3961 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: LEN OP expr CP  */
#line 460 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3969 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: STRING OP expr COMMA expr CP  */
#line 463 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3977 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: VAL OP expr CP  */
#line 466 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3985 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: RANDOM random_definition  */
#line 469 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3993 "src-generated/ugbc.tab.c"
    break;

  case 108: /* exponential: RND OP expr CP  */
#line 472 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 4001 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: OP expr CP  */
#line 475 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 4009 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: MAX OP expr COMMA expr CP  */
#line 478 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4017 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: MIN OP expr COMMA expr CP  */
#line 481 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4025 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: PARAM OP Identifier CP  */
#line 484 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 4033 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 487 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 4041 "src-generated/ugbc.tab.c"
    break;

  case 114: /* $@3: %empty  */
#line 490 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 4049 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: Identifier OSP $@3 values CSP  */
#line 492 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 4058 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: SGN OP expr CP  */
#line 496 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 4066 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: ABS OP expr CP  */
#line 499 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 4074 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: TRUE  */
#line 502 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 4083 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: FALSE  */
#line 506 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 4092 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: COLORS  */
#line 510 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 4101 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: PEN COLORS  */
#line 514 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 4110 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: PEN DEFAULT  */
#line 518 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 4119 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: DEFAULT PEN  */
#line 522 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 4128 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PAPER COLORS  */
#line 526 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 4137 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER DEFAULT  */
#line 530 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 4146 "src-generated/ugbc.tab.c"
    break;

  case 126: /* exponential: DEFAULT PAPER  */
#line 534 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 4155 "src-generated/ugbc.tab.c"
    break;

  case 127: /* exponential: WIDTH  */
#line 538 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 4163 "src-generated/ugbc.tab.c"
    break;

  case 128: /* exponential: HEIGHT  */
#line 541 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 4171 "src-generated/ugbc.tab.c"
    break;

  case 129: /* exponential: TIMER  */
#line 544 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 4179 "src-generated/ugbc.tab.c"
    break;

  case 130: /* exponential: PEN DOLLAR OP expr CP  */
#line 547 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 4187 "src-generated/ugbc.tab.c"
    break;

  case 131: /* exponential: PAPER DOLLAR OP expr CP  */
#line 550 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 4195 "src-generated/ugbc.tab.c"
    break;

  case 132: /* exponential: CMOVE DOLLAR OP expr COMMA expr CP  */
#line 553 "src/ugbc.y"
                                         {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4203 "src-generated/ugbc.tab.c"
    break;

  case 133: /* exponential: CUP DOLLAR  */
#line 556 "src/ugbc.y"
                 {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 4211 "src-generated/ugbc.tab.c"
    break;

  case 134: /* exponential: CDOWN DOLLAR  */
#line 559 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 4219 "src-generated/ugbc.tab.c"
    break;

  case 135: /* exponential: CLEFT DOLLAR  */
#line 562 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 4227 "src-generated/ugbc.tab.c"
    break;

  case 136: /* exponential: CRIGHT DOLLAR  */
#line 565 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 4235 "src-generated/ugbc.tab.c"
    break;

  case 137: /* exponential: AT DOLLAR OP expr COMMA expr CP  */
#line 568 "src/ugbc.y"
                                      {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4243 "src-generated/ugbc.tab.c"
    break;

  case 138: /* exponential: LOCATE DOLLAR OP expr COMMA expr CP  */
#line 571 "src/ugbc.y"
                                          {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4251 "src-generated/ugbc.tab.c"
    break;

  case 139: /* exponential: TAB DOLLAR  */
#line 574 "src/ugbc.y"
                 {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 4259 "src-generated/ugbc.tab.c"
    break;

  case 140: /* exponential: XCURS  */
#line 577 "src/ugbc.y"
            {
        (yyval.string) = text_get_xcurs( _environment )->name;
    }
#line 4267 "src-generated/ugbc.tab.c"
    break;

  case 141: /* exponential: YCURS  */
#line 580 "src/ugbc.y"
            {
        (yyval.string) = text_get_ycurs( _environment )->name;
    }
#line 4275 "src-generated/ugbc.tab.c"
    break;

  case 142: /* exponential: TEXTADDRESS  */
#line 583 "src/ugbc.y"
                  {
        (yyval.string) = strdup( "TEXTADDRESS" );
    }
#line 4283 "src-generated/ugbc.tab.c"
    break;

  case 143: /* exponential: JOY OP expr CP  */
#line 586 "src/ugbc.y"
                     {
        (yyval.string) = joy( _environment, (yyvsp[-1].string) )->name;
    }
#line 4291 "src-generated/ugbc.tab.c"
    break;

  case 144: /* exponential: JUP OP expr CP  */
#line 589 "src/ugbc.y"
                     {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_UP )->name;
    }
#line 4299 "src-generated/ugbc.tab.c"
    break;

  case 145: /* exponential: JDOWN OP expr CP  */
#line 592 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_DOWN )->name;
    }
#line 4307 "src-generated/ugbc.tab.c"
    break;

  case 146: /* exponential: JLEFT OP expr CP  */
#line 595 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_LEFT )->name;
    }
#line 4315 "src-generated/ugbc.tab.c"
    break;

  case 147: /* exponential: JRIGHT OP expr CP  */
#line 598 "src/ugbc.y"
                        {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_RIGHT )->name;
    }
#line 4323 "src-generated/ugbc.tab.c"
    break;

  case 148: /* exponential: JFIRE OP expr CP  */
#line 601 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_FIRE )->name;
    }
#line 4331 "src-generated/ugbc.tab.c"
    break;

  case 149: /* exponential: FIRE OP expr CP  */
#line 604 "src/ugbc.y"
                      {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_FIRE )->name;
    }
#line 4339 "src-generated/ugbc.tab.c"
    break;

  case 150: /* exponential: JOY COUNT  */
#line 607 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, (yyval.string), JOY_COUNT );
    }
#line 4348 "src-generated/ugbc.tab.c"
    break;

  case 151: /* exponential: JOYCOUNT  */
#line 611 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, (yyval.string), JOY_COUNT );
    }
#line 4357 "src-generated/ugbc.tab.c"
    break;

  case 152: /* exponential: BIT OP expr COMMA expr CP  */
#line 615 "src/ugbc.y"
                                {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4365 "src-generated/ugbc.tab.c"
    break;

  case 153: /* exponential: UP  */
#line 618 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(UP)" )->name;
        variable_store( _environment, (yyval.string), JOY_UP );
    }
#line 4374 "src-generated/ugbc.tab.c"
    break;

  case 154: /* exponential: DOWN  */
#line 622 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(DOWN)" )->name;
        variable_store( _environment, (yyval.string), JOY_DOWN );
    }
#line 4383 "src-generated/ugbc.tab.c"
    break;

  case 155: /* exponential: LEFT  */
#line 626 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(LEFT)" )->name;
        variable_store( _environment, (yyval.string), JOY_LEFT );
    }
#line 4392 "src-generated/ugbc.tab.c"
    break;

  case 156: /* exponential: RIGHT  */
#line 630 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(RIGHT)" )->name;
        variable_store( _environment, (yyval.string), JOY_RIGHT );
    }
#line 4401 "src-generated/ugbc.tab.c"
    break;

  case 157: /* exponential: FIRE  */
#line 634 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(FIRE)" )->name;
        variable_store( _environment, (yyval.string), JOY_FIRE );
    }
#line 4410 "src-generated/ugbc.tab.c"
    break;

  case 158: /* exponential: INKEY  */
#line 638 "src/ugbc.y"
            {
        (yyval.string) = inkey( _environment )->name;
    }
#line 4418 "src-generated/ugbc.tab.c"
    break;

  case 161: /* bank_definition_simple: AT direct_integer  */
#line 646 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4426 "src-generated/ugbc.tab.c"
    break;

  case 162: /* bank_definition_simple: Identifier AT direct_integer  */
#line 649 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4434 "src-generated/ugbc.tab.c"
    break;

  case 163: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 652 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4442 "src-generated/ugbc.tab.c"
    break;

  case 164: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 655 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4450 "src-generated/ugbc.tab.c"
    break;

  case 165: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 658 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4458 "src-generated/ugbc.tab.c"
    break;

  case 166: /* bank_definition_simple: DATA AT direct_integer  */
#line 661 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4466 "src-generated/ugbc.tab.c"
    break;

  case 167: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 665 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4474 "src-generated/ugbc.tab.c"
    break;

  case 168: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 668 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4482 "src-generated/ugbc.tab.c"
    break;

  case 169: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 671 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4490 "src-generated/ugbc.tab.c"
    break;

  case 170: /* bank_definition_simple: CODE AT direct_integer  */
#line 674 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4498 "src-generated/ugbc.tab.c"
    break;

  case 171: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 678 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4506 "src-generated/ugbc.tab.c"
    break;

  case 172: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 681 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4514 "src-generated/ugbc.tab.c"
    break;

  case 173: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 684 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4522 "src-generated/ugbc.tab.c"
    break;

  case 174: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 687 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4530 "src-generated/ugbc.tab.c"
    break;

  case 175: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 691 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4538 "src-generated/ugbc.tab.c"
    break;

  case 176: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 694 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4546 "src-generated/ugbc.tab.c"
    break;

  case 177: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 697 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4554 "src-generated/ugbc.tab.c"
    break;

  case 178: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 700 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4562 "src-generated/ugbc.tab.c"
    break;

  case 179: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 706 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4570 "src-generated/ugbc.tab.c"
    break;

  case 180: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 709 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4578 "src-generated/ugbc.tab.c"
    break;

  case 181: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 712 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4586 "src-generated/ugbc.tab.c"
    break;

  case 182: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 715 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4594 "src-generated/ugbc.tab.c"
    break;

  case 183: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 718 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4602 "src-generated/ugbc.tab.c"
    break;

  case 186: /* raster_definition_simple: Identifier AT direct_integer  */
#line 727 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 4610 "src-generated/ugbc.tab.c"
    break;

  case 187: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 730 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 4618 "src-generated/ugbc.tab.c"
    break;

  case 188: /* raster_definition_expression: Identifier AT expr  */
#line 735 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4626 "src-generated/ugbc.tab.c"
    break;

  case 189: /* raster_definition_expression: AT expr WITH Identifier  */
#line 738 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4634 "src-generated/ugbc.tab.c"
    break;

  case 192: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 747 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 4642 "src-generated/ugbc.tab.c"
    break;

  case 193: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 750 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 4650 "src-generated/ugbc.tab.c"
    break;

  case 194: /* next_raster_definition_expression: Identifier AT expr  */
#line 755 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 4658 "src-generated/ugbc.tab.c"
    break;

  case 195: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 758 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4666 "src-generated/ugbc.tab.c"
    break;

  case 198: /* color_definition_simple: BORDER direct_integer  */
#line 767 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 4674 "src-generated/ugbc.tab.c"
    break;

  case 199: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 770 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4682 "src-generated/ugbc.tab.c"
    break;

  case 200: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 773 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4690 "src-generated/ugbc.tab.c"
    break;

  case 201: /* color_definition_expression: BORDER expr  */
#line 778 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 4698 "src-generated/ugbc.tab.c"
    break;

  case 202: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 781 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4706 "src-generated/ugbc.tab.c"
    break;

  case 203: /* color_definition_expression: SPRITE expr TO expr  */
#line 784 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4714 "src-generated/ugbc.tab.c"
    break;

  case 209: /* wait_definition_simple: direct_integer CYCLES  */
#line 798 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4722 "src-generated/ugbc.tab.c"
    break;

  case 210: /* wait_definition_simple: direct_integer TICKS  */
#line 801 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4730 "src-generated/ugbc.tab.c"
    break;

  case 211: /* wait_definition_simple: direct_integer milliseconds  */
#line 804 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4738 "src-generated/ugbc.tab.c"
    break;

  case 212: /* wait_definition_expression: expr CYCLES  */
#line 809 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4746 "src-generated/ugbc.tab.c"
    break;

  case 213: /* wait_definition_expression: expr TICKS  */
#line 812 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4754 "src-generated/ugbc.tab.c"
    break;

  case 214: /* wait_definition_expression: expr milliseconds  */
#line 815 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4762 "src-generated/ugbc.tab.c"
    break;

  case 217: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 825 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4770 "src-generated/ugbc.tab.c"
    break;

  case 218: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 828 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4778 "src-generated/ugbc.tab.c"
    break;

  case 219: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 831 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4786 "src-generated/ugbc.tab.c"
    break;

  case 220: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 834 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4794 "src-generated/ugbc.tab.c"
    break;

  case 221: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 837 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4802 "src-generated/ugbc.tab.c"
    break;

  case 222: /* sprite_definition_simple: direct_integer ENABLE  */
#line 840 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4810 "src-generated/ugbc.tab.c"
    break;

  case 223: /* sprite_definition_simple: direct_integer DISABLE  */
#line 843 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4818 "src-generated/ugbc.tab.c"
    break;

  case 224: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 846 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4826 "src-generated/ugbc.tab.c"
    break;

  case 225: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 849 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4834 "src-generated/ugbc.tab.c"
    break;

  case 226: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 852 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4842 "src-generated/ugbc.tab.c"
    break;

  case 227: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 855 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4850 "src-generated/ugbc.tab.c"
    break;

  case 228: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 858 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4858 "src-generated/ugbc.tab.c"
    break;

  case 229: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 861 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4866 "src-generated/ugbc.tab.c"
    break;

  case 230: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 864 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4874 "src-generated/ugbc.tab.c"
    break;

  case 231: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 867 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4882 "src-generated/ugbc.tab.c"
    break;

  case 232: /* sprite_definition_expression: expr DATA FROM expr  */
#line 872 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4890 "src-generated/ugbc.tab.c"
    break;

  case 233: /* sprite_definition_expression: expr MULTICOLOR  */
#line 875 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4898 "src-generated/ugbc.tab.c"
    break;

  case 234: /* sprite_definition_expression: expr MONOCOLOR  */
#line 878 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4906 "src-generated/ugbc.tab.c"
    break;

  case 235: /* sprite_definition_expression: expr COLOR expr  */
#line 881 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4914 "src-generated/ugbc.tab.c"
    break;

  case 236: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 884 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4922 "src-generated/ugbc.tab.c"
    break;

  case 237: /* sprite_definition_expression: expr ENABLE  */
#line 887 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4930 "src-generated/ugbc.tab.c"
    break;

  case 238: /* sprite_definition_expression: expr DISABLE  */
#line 890 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4938 "src-generated/ugbc.tab.c"
    break;

  case 239: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 893 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4946 "src-generated/ugbc.tab.c"
    break;

  case 240: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 896 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4954 "src-generated/ugbc.tab.c"
    break;

  case 241: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 899 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4962 "src-generated/ugbc.tab.c"
    break;

  case 242: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 902 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4970 "src-generated/ugbc.tab.c"
    break;

  case 243: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 905 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4978 "src-generated/ugbc.tab.c"
    break;

  case 244: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 908 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4986 "src-generated/ugbc.tab.c"
    break;

  case 245: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 911 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4994 "src-generated/ugbc.tab.c"
    break;

  case 246: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 914 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 5002 "src-generated/ugbc.tab.c"
    break;

  case 249: /* bitmap_definition_simple: AT direct_integer  */
#line 923 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 5010 "src-generated/ugbc.tab.c"
    break;

  case 250: /* bitmap_definition_simple: ENABLE  */
#line 926 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 5018 "src-generated/ugbc.tab.c"
    break;

  case 251: /* bitmap_definition_simple: DISABLE  */
#line 929 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 5026 "src-generated/ugbc.tab.c"
    break;

  case 252: /* bitmap_definition_simple: CLEAR  */
#line 932 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 5034 "src-generated/ugbc.tab.c"
    break;

  case 253: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 935 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 5042 "src-generated/ugbc.tab.c"
    break;

  case 254: /* bitmap_definition_expression: AT expr  */
#line 941 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 5050 "src-generated/ugbc.tab.c"
    break;

  case 255: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 944 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 5058 "src-generated/ugbc.tab.c"
    break;

  case 258: /* textmap_definition_simple: AT direct_integer  */
#line 954 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 5066 "src-generated/ugbc.tab.c"
    break;

  case 259: /* textmap_definition_expression: AT expr  */
#line 959 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 5074 "src-generated/ugbc.tab.c"
    break;

  case 262: /* text_definition_simple: ENABLE  */
#line 968 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 5082 "src-generated/ugbc.tab.c"
    break;

  case 263: /* text_definition_simple: DISABLE  */
#line 971 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 5090 "src-generated/ugbc.tab.c"
    break;

  case 264: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 976 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 5098 "src-generated/ugbc.tab.c"
    break;

  case 265: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 979 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 5106 "src-generated/ugbc.tab.c"
    break;

  case 268: /* tiles_definition_simple: AT direct_integer  */
#line 988 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 5114 "src-generated/ugbc.tab.c"
    break;

  case 269: /* tiles_definition_expression: AT expr  */
#line 993 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 5122 "src-generated/ugbc.tab.c"
    break;

  case 272: /* colormap_definition_simple: AT direct_integer  */
#line 1002 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 5130 "src-generated/ugbc.tab.c"
    break;

  case 273: /* colormap_definition_simple: CLEAR  */
#line 1005 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 5138 "src-generated/ugbc.tab.c"
    break;

  case 274: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 1008 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 5146 "src-generated/ugbc.tab.c"
    break;

  case 275: /* colormap_definition_expression: AT expr  */
#line 1013 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 5154 "src-generated/ugbc.tab.c"
    break;

  case 276: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 1016 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 5162 "src-generated/ugbc.tab.c"
    break;

  case 279: /* screen_definition_simple: ON  */
#line 1026 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 5170 "src-generated/ugbc.tab.c"
    break;

  case 280: /* screen_definition_simple: OFF  */
#line 1029 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 5178 "src-generated/ugbc.tab.c"
    break;

  case 281: /* screen_definition_simple: ROWS direct_integer  */
#line 1032 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 5186 "src-generated/ugbc.tab.c"
    break;

  case 282: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 1035 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 5194 "src-generated/ugbc.tab.c"
    break;

  case 283: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 1038 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 5202 "src-generated/ugbc.tab.c"
    break;

  case 284: /* screen_definition_expression: ROWS expr  */
#line 1043 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 5210 "src-generated/ugbc.tab.c"
    break;

  case 285: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 1046 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 5218 "src-generated/ugbc.tab.c"
    break;

  case 286: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 1049 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 5226 "src-generated/ugbc.tab.c"
    break;

  case 290: /* var_definition_simple: Identifier ON Identifier  */
#line 1058 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 5234 "src-generated/ugbc.tab.c"
    break;

  case 291: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 1061 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 5242 "src-generated/ugbc.tab.c"
    break;

  case 292: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 1064 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 5250 "src-generated/ugbc.tab.c"
    break;

  case 293: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 1067 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 5260 "src-generated/ugbc.tab.c"
    break;

  case 294: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 1072 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 5270 "src-generated/ugbc.tab.c"
    break;

  case 295: /* goto_definition: Identifier  */
#line 1079 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 5278 "src-generated/ugbc.tab.c"
    break;

  case 296: /* goto_definition: Integer  */
#line 1082 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 5286 "src-generated/ugbc.tab.c"
    break;

  case 297: /* gosub_definition: Identifier  */
#line 1088 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 5294 "src-generated/ugbc.tab.c"
    break;

  case 298: /* gosub_definition: Integer  */
#line 1091 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 5302 "src-generated/ugbc.tab.c"
    break;

  case 300: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 1100 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 5310 "src-generated/ugbc.tab.c"
    break;

  case 301: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 1106 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 5318 "src-generated/ugbc.tab.c"
    break;

  case 304: /* ink_definition: expr  */
#line 1115 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 5326 "src-generated/ugbc.tab.c"
    break;

  case 305: /* on_goto_definition: Identifier  */
#line 1120 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 5335 "src-generated/ugbc.tab.c"
    break;

  case 306: /* $@4: %empty  */
#line 1124 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 5343 "src-generated/ugbc.tab.c"
    break;

  case 308: /* on_gosub_definition: Identifier  */
#line 1129 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 5352 "src-generated/ugbc.tab.c"
    break;

  case 309: /* $@5: %empty  */
#line 1133 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 5360 "src-generated/ugbc.tab.c"
    break;

  case 311: /* on_proc_definition: Identifier  */
#line 1138 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 5369 "src-generated/ugbc.tab.c"
    break;

  case 312: /* $@6: %empty  */
#line 1142 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 5377 "src-generated/ugbc.tab.c"
    break;

  case 314: /* $@7: %empty  */
#line 1147 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 5385 "src-generated/ugbc.tab.c"
    break;

  case 316: /* $@8: %empty  */
#line 1150 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 5393 "src-generated/ugbc.tab.c"
    break;

  case 318: /* $@9: %empty  */
#line 1153 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 5401 "src-generated/ugbc.tab.c"
    break;

  case 320: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1158 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 5409 "src-generated/ugbc.tab.c"
    break;

  case 321: /* every_definition: ON  */
#line 1161 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 5417 "src-generated/ugbc.tab.c"
    break;

  case 322: /* every_definition: OFF  */
#line 1164 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 5425 "src-generated/ugbc.tab.c"
    break;

  case 323: /* add_definition: Identifier COMMA expr  */
#line 1169 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 5433 "src-generated/ugbc.tab.c"
    break;

  case 324: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1172 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5441 "src-generated/ugbc.tab.c"
    break;

  case 325: /* dimensions: Integer  */
#line 1178 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5450 "src-generated/ugbc.tab.c"
    break;

  case 326: /* dimensions: Integer COMMA dimensions  */
#line 1182 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5459 "src-generated/ugbc.tab.c"
    break;

  case 327: /* datatype: BYTE  */
#line 1189 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 5467 "src-generated/ugbc.tab.c"
    break;

  case 328: /* datatype: SIGNED BYTE  */
#line 1192 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 5475 "src-generated/ugbc.tab.c"
    break;

  case 329: /* datatype: WORD  */
#line 1195 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 5483 "src-generated/ugbc.tab.c"
    break;

  case 330: /* datatype: SIGNED WORD  */
#line 1198 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 5491 "src-generated/ugbc.tab.c"
    break;

  case 331: /* datatype: DWORD  */
#line 1201 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 5499 "src-generated/ugbc.tab.c"
    break;

  case 332: /* datatype: SIGNED DWORD  */
#line 1204 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 5507 "src-generated/ugbc.tab.c"
    break;

  case 333: /* datatype: ADDRESS  */
#line 1207 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 5515 "src-generated/ugbc.tab.c"
    break;

  case 334: /* datatype: POSITION  */
#line 1210 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 5523 "src-generated/ugbc.tab.c"
    break;

  case 335: /* datatype: COLOR  */
#line 1213 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 5531 "src-generated/ugbc.tab.c"
    break;

  case 336: /* datatype: STRING  */
#line 1216 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 5539 "src-generated/ugbc.tab.c"
    break;

  case 337: /* $@10: %empty  */
#line 1221 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5548 "src-generated/ugbc.tab.c"
    break;

  case 338: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1224 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 5558 "src-generated/ugbc.tab.c"
    break;

  case 339: /* $@11: %empty  */
#line 1229 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5567 "src-generated/ugbc.tab.c"
    break;

  case 340: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1232 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 5577 "src-generated/ugbc.tab.c"
    break;

  case 341: /* $@12: %empty  */
#line 1237 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5586 "src-generated/ugbc.tab.c"
    break;

  case 342: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1240 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 5596 "src-generated/ugbc.tab.c"
    break;

  case 345: /* indexes: expr  */
#line 1253 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5605 "src-generated/ugbc.tab.c"
    break;

  case 346: /* indexes: expr COMMA indexes  */
#line 1257 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5614 "src-generated/ugbc.tab.c"
    break;

  case 347: /* parameters: Identifier  */
#line 1264 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5624 "src-generated/ugbc.tab.c"
    break;

  case 348: /* parameters: Identifier DOLLAR  */
#line 1269 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5634 "src-generated/ugbc.tab.c"
    break;

  case 349: /* parameters: Identifier AS datatype  */
#line 1274 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5644 "src-generated/ugbc.tab.c"
    break;

  case 350: /* parameters: Identifier COMMA parameters  */
#line 1279 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5654 "src-generated/ugbc.tab.c"
    break;

  case 351: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1284 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5664 "src-generated/ugbc.tab.c"
    break;

  case 352: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1289 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5674 "src-generated/ugbc.tab.c"
    break;

  case 353: /* parameters_expr: Identifier  */
#line 1297 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5684 "src-generated/ugbc.tab.c"
    break;

  case 354: /* parameters_expr: Identifier DOLLAR  */
#line 1302 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5694 "src-generated/ugbc.tab.c"
    break;

  case 355: /* parameters_expr: Identifier AS datatype  */
#line 1307 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5704 "src-generated/ugbc.tab.c"
    break;

  case 356: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1312 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5714 "src-generated/ugbc.tab.c"
    break;

  case 357: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1317 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5724 "src-generated/ugbc.tab.c"
    break;

  case 358: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1322 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5734 "src-generated/ugbc.tab.c"
    break;

  case 359: /* parameters_expr: String  */
#line 1327 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5743 "src-generated/ugbc.tab.c"
    break;

  case 360: /* parameters_expr: String COMMA parameters_expr  */
#line 1331 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5752 "src-generated/ugbc.tab.c"
    break;

  case 361: /* values: expr  */
#line 1338 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5761 "src-generated/ugbc.tab.c"
    break;

  case 362: /* values: expr COMMA values  */
#line 1342 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5770 "src-generated/ugbc.tab.c"
    break;

  case 363: /* print_definition: expr  */
#line 1349 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5778 "src-generated/ugbc.tab.c"
    break;

  case 364: /* print_definition: expr COMMA  */
#line 1352 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5787 "src-generated/ugbc.tab.c"
    break;

  case 365: /* print_definition: expr SEMICOLON  */
#line 1356 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5795 "src-generated/ugbc.tab.c"
    break;

  case 366: /* $@13: %empty  */
#line 1359 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5804 "src-generated/ugbc.tab.c"
    break;

  case 368: /* $@14: %empty  */
#line 1363 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5812 "src-generated/ugbc.tab.c"
    break;

  case 370: /* writing_mode_definition: REPLACE  */
#line 1369 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5821 "src-generated/ugbc.tab.c"
    break;

  case 371: /* writing_mode_definition: OR  */
#line 1373 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5830 "src-generated/ugbc.tab.c"
    break;

  case 372: /* writing_mode_definition: XOR  */
#line 1377 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5839 "src-generated/ugbc.tab.c"
    break;

  case 373: /* writing_mode_definition: AND  */
#line 1381 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5848 "src-generated/ugbc.tab.c"
    break;

  case 374: /* writing_mode_definition: IGNORE  */
#line 1385 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5857 "src-generated/ugbc.tab.c"
    break;

  case 375: /* writing_part_definition: NORMAL  */
#line 1392 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5866 "src-generated/ugbc.tab.c"
    break;

  case 376: /* writing_part_definition: PAPER  */
#line 1396 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5875 "src-generated/ugbc.tab.c"
    break;

  case 377: /* writing_part_definition: PAPER ONLY  */
#line 1400 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5884 "src-generated/ugbc.tab.c"
    break;

  case 378: /* writing_part_definition: PEN  */
#line 1404 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5893 "src-generated/ugbc.tab.c"
    break;

  case 379: /* writing_part_definition: PEN ONLY  */
#line 1408 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5902 "src-generated/ugbc.tab.c"
    break;

  case 380: /* writing_definition: writing_mode_definition COMMA writing_part_definition  */
#line 1415 "src/ugbc.y"
                                                          {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5910 "src-generated/ugbc.tab.c"
    break;

  case 381: /* locate_definition: COMMA expr  */
#line 1421 "src/ugbc.y"
                {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 5918 "src-generated/ugbc.tab.c"
    break;

  case 382: /* locate_definition: expr COMMA  */
#line 1424 "src/ugbc.y"
                 {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 5926 "src-generated/ugbc.tab.c"
    break;

  case 383: /* locate_definition: expr COMMA expr  */
#line 1427 "src/ugbc.y"
                      {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5934 "src-generated/ugbc.tab.c"
    break;

  case 384: /* cmove_definition: COMMA expr  */
#line 1433 "src/ugbc.y"
                {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 5942 "src-generated/ugbc.tab.c"
    break;

  case 385: /* cmove_definition: expr COMMA  */
#line 1436 "src/ugbc.y"
                 {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 5950 "src-generated/ugbc.tab.c"
    break;

  case 386: /* cmove_definition: expr COMMA expr  */
#line 1439 "src/ugbc.y"
                      {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5958 "src-generated/ugbc.tab.c"
    break;

  case 387: /* hscroll_definition: LEFT  */
#line 1445 "src/ugbc.y"
         {
        text_hscroll_line( _environment, -1 );
    }
#line 5966 "src-generated/ugbc.tab.c"
    break;

  case 388: /* hscroll_definition: SCREEN LEFT  */
#line 1448 "src/ugbc.y"
                  {
        text_hscroll_screen( _environment, -1 );
    }
#line 5974 "src-generated/ugbc.tab.c"
    break;

  case 389: /* hscroll_definition: RIGHT  */
#line 1451 "src/ugbc.y"
            {
        text_hscroll_line( _environment, 1 );
    }
#line 5982 "src-generated/ugbc.tab.c"
    break;

  case 390: /* hscroll_definition: SCREEN RIGHT  */
#line 1454 "src/ugbc.y"
                   {
        text_hscroll_screen( _environment, 1 );
    }
#line 5990 "src-generated/ugbc.tab.c"
    break;

  case 391: /* vscroll_definition: SCREEN UP  */
#line 1460 "src/ugbc.y"
                {
        text_vscroll_screen( _environment, -1 );
    }
#line 5998 "src-generated/ugbc.tab.c"
    break;

  case 392: /* vscroll_definition: SCREEN DOWN  */
#line 1463 "src/ugbc.y"
                  {
        text_vscroll_screen( _environment, 1 );
    }
#line 6006 "src-generated/ugbc.tab.c"
    break;

  case 408: /* statement: TEXTADDRESS ASSIGN expr  */
#line 1484 "src/ugbc.y"
                            {
      variable_move( _environment, (yyvsp[0].string), "ADDRESS" );
  }
#line 6014 "src-generated/ugbc.tab.c"
    break;

  case 413: /* statement: MEMORIZE  */
#line 1491 "src/ugbc.y"
             {
      text_memorize( _environment );
  }
#line 6022 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: REMEMBER  */
#line 1494 "src/ugbc.y"
             {
      text_remember( _environment );
  }
#line 6030 "src-generated/ugbc.tab.c"
    break;

  case 418: /* statement: CUP  */
#line 1500 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 6038 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: CDOWN  */
#line 1503 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 6046 "src-generated/ugbc.tab.c"
    break;

  case 420: /* statement: CLEFT  */
#line 1506 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 6054 "src-generated/ugbc.tab.c"
    break;

  case 421: /* statement: CRIGHT  */
#line 1509 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 6062 "src-generated/ugbc.tab.c"
    break;

  case 422: /* statement: CLINE  */
#line 1512 "src/ugbc.y"
          {
      text_cline( _environment, NULL );
  }
#line 6070 "src-generated/ugbc.tab.c"
    break;

  case 423: /* statement: CLINE expr  */
#line 1515 "src/ugbc.y"
               {
      text_cline( _environment, (yyvsp[0].string) );
  }
#line 6078 "src-generated/ugbc.tab.c"
    break;

  case 424: /* statement: SET TAB expr  */
#line 1518 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 6086 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: CENTER expr  */
#line 1521 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 6094 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: CENTRE expr  */
#line 1524 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 6102 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: CLS  */
#line 1527 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 6110 "src-generated/ugbc.tab.c"
    break;

  case 428: /* statement: HOME  */
#line 1530 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 6118 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: INC Identifier  */
#line 1533 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 6126 "src-generated/ugbc.tab.c"
    break;

  case 430: /* statement: DEC Identifier  */
#line 1536 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 6134 "src-generated/ugbc.tab.c"
    break;

  case 431: /* statement: RANDOMIZE  */
#line 1539 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 6142 "src-generated/ugbc.tab.c"
    break;

  case 432: /* statement: RANDOMIZE expr  */
#line 1542 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 6150 "src-generated/ugbc.tab.c"
    break;

  case 433: /* statement: IF expr THEN  */
#line 1545 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 6158 "src-generated/ugbc.tab.c"
    break;

  case 434: /* statement: ELSE  */
#line 1548 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 6166 "src-generated/ugbc.tab.c"
    break;

  case 435: /* statement: ELSE IF expr THEN  */
#line 1551 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 6174 "src-generated/ugbc.tab.c"
    break;

  case 436: /* statement: ENDIF  */
#line 1554 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 6182 "src-generated/ugbc.tab.c"
    break;

  case 437: /* statement: DO  */
#line 1557 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 6190 "src-generated/ugbc.tab.c"
    break;

  case 438: /* statement: LOOP  */
#line 1560 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 6198 "src-generated/ugbc.tab.c"
    break;

  case 439: /* $@15: %empty  */
#line 1563 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 6206 "src-generated/ugbc.tab.c"
    break;

  case 440: /* statement: WHILE $@15 expr  */
#line 1565 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 6214 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: WEND  */
#line 1568 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 6222 "src-generated/ugbc.tab.c"
    break;

  case 442: /* statement: REPEAT  */
#line 1571 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 6230 "src-generated/ugbc.tab.c"
    break;

  case 443: /* statement: UNTIL expr  */
#line 1574 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 6238 "src-generated/ugbc.tab.c"
    break;

  case 444: /* statement: EXIT  */
#line 1577 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 6246 "src-generated/ugbc.tab.c"
    break;

  case 445: /* statement: EXIT PROC  */
#line 1580 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 6254 "src-generated/ugbc.tab.c"
    break;

  case 446: /* statement: POP PROC  */
#line 1583 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 6262 "src-generated/ugbc.tab.c"
    break;

  case 447: /* statement: EXIT IF expr  */
#line 1586 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 6270 "src-generated/ugbc.tab.c"
    break;

  case 448: /* statement: EXIT Integer  */
#line 1589 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 6278 "src-generated/ugbc.tab.c"
    break;

  case 449: /* statement: EXIT direct_integer  */
#line 1592 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 6286 "src-generated/ugbc.tab.c"
    break;

  case 450: /* statement: EXIT IF expr COMMA Integer  */
#line 1595 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 6294 "src-generated/ugbc.tab.c"
    break;

  case 451: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1598 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 6302 "src-generated/ugbc.tab.c"
    break;

  case 452: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1601 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 6310 "src-generated/ugbc.tab.c"
    break;

  case 453: /* statement: NEXT  */
#line 1604 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 6318 "src-generated/ugbc.tab.c"
    break;

  case 454: /* statement: PROCEDURE Identifier  */
#line 1607 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 6327 "src-generated/ugbc.tab.c"
    break;

  case 455: /* $@16: %empty  */
#line 1611 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6335 "src-generated/ugbc.tab.c"
    break;

  case 456: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1613 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6343 "src-generated/ugbc.tab.c"
    break;

  case 457: /* statement: SHARED parameters_expr  */
#line 1616 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 6351 "src-generated/ugbc.tab.c"
    break;

  case 458: /* statement: GLOBAL parameters_expr  */
#line 1619 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 6359 "src-generated/ugbc.tab.c"
    break;

  case 459: /* statement: END PROC  */
#line 1622 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 6367 "src-generated/ugbc.tab.c"
    break;

  case 460: /* statement: END PROC OSP expr CSP  */
#line 1625 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6375 "src-generated/ugbc.tab.c"
    break;

  case 461: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1628 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 6383 "src-generated/ugbc.tab.c"
    break;

  case 462: /* statement: Identifier " "  */
#line 1631 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6392 "src-generated/ugbc.tab.c"
    break;

  case 463: /* statement: PROC Identifier  */
#line 1635 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6401 "src-generated/ugbc.tab.c"
    break;

  case 464: /* statement: CALL Identifier  */
#line 1639 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6410 "src-generated/ugbc.tab.c"
    break;

  case 465: /* $@17: %empty  */
#line 1643 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6418 "src-generated/ugbc.tab.c"
    break;

  case 466: /* statement: Identifier OSP $@17 values CSP  */
#line 1645 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6426 "src-generated/ugbc.tab.c"
    break;

  case 467: /* $@18: %empty  */
#line 1648 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6434 "src-generated/ugbc.tab.c"
    break;

  case 468: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1650 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6442 "src-generated/ugbc.tab.c"
    break;

  case 469: /* $@19: %empty  */
#line 1653 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6450 "src-generated/ugbc.tab.c"
    break;

  case 470: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1655 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6458 "src-generated/ugbc.tab.c"
    break;

  case 471: /* statement: PEN expr  */
#line 1658 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 6466 "src-generated/ugbc.tab.c"
    break;

  case 472: /* statement: PAPER expr  */
#line 1661 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 6474 "src-generated/ugbc.tab.c"
    break;

  case 473: /* statement: INVERSE ON  */
#line 1664 "src/ugbc.y"
               {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 6482 "src-generated/ugbc.tab.c"
    break;

  case 474: /* statement: INVERSE OFF  */
#line 1667 "src/ugbc.y"
                {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 6490 "src-generated/ugbc.tab.c"
    break;

  case 476: /* statement: Identifier COLON  */
#line 1671 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 6498 "src-generated/ugbc.tab.c"
    break;

  case 477: /* statement: BEG GAMELOOP  */
#line 1674 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 6506 "src-generated/ugbc.tab.c"
    break;

  case 478: /* statement: END GAMELOOP  */
#line 1677 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 6514 "src-generated/ugbc.tab.c"
    break;

  case 479: /* statement: GRAPHIC  */
#line 1680 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 6522 "src-generated/ugbc.tab.c"
    break;

  case 480: /* statement: HALT  */
#line 1683 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 6530 "src-generated/ugbc.tab.c"
    break;

  case 481: /* statement: END  */
#line 1686 "src/ugbc.y"
        {
      end( _environment );
  }
#line 6538 "src-generated/ugbc.tab.c"
    break;

  case 486: /* statement: RETURN  */
#line 1693 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 6546 "src-generated/ugbc.tab.c"
    break;

  case 487: /* statement: RETURN expr  */
#line 1696 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 6554 "src-generated/ugbc.tab.c"
    break;

  case 488: /* statement: POP  */
#line 1699 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 6562 "src-generated/ugbc.tab.c"
    break;

  case 489: /* statement: DONE  */
#line 1702 "src/ugbc.y"
          {
      return 0;
  }
#line 6570 "src-generated/ugbc.tab.c"
    break;

  case 490: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1705 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6578 "src-generated/ugbc.tab.c"
    break;

  case 491: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1708 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6586 "src-generated/ugbc.tab.c"
    break;

  case 492: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1711 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 6594 "src-generated/ugbc.tab.c"
    break;

  case 493: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1714 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6602 "src-generated/ugbc.tab.c"
    break;

  case 495: /* statement: Identifier ASSIGN expr  */
#line 1718 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 6616 "src-generated/ugbc.tab.c"
    break;

  case 496: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1727 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 6630 "src-generated/ugbc.tab.c"
    break;

  case 497: /* $@20: %empty  */
#line 1736 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6639 "src-generated/ugbc.tab.c"
    break;

  case 498: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1740 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 6652 "src-generated/ugbc.tab.c"
    break;

  case 499: /* $@21: %empty  */
#line 1748 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6661 "src-generated/ugbc.tab.c"
    break;

  case 500: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1751 "src/ugbc.y"
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
#line 6680 "src-generated/ugbc.tab.c"
    break;

  case 501: /* $@22: %empty  */
#line 1765 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6689 "src-generated/ugbc.tab.c"
    break;

  case 502: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1768 "src/ugbc.y"
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
#line 6708 "src-generated/ugbc.tab.c"
    break;

  case 503: /* statement: DEBUG expr  */
#line 1782 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 6716 "src-generated/ugbc.tab.c"
    break;

  case 506: /* statements_no_linenumbers: statement  */
#line 1790 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 6722 "src-generated/ugbc.tab.c"
    break;

  case 507: /* $@23: %empty  */
#line 1791 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 6728 "src-generated/ugbc.tab.c"
    break;

  case 509: /* $@24: %empty  */
#line 1795 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 6736 "src-generated/ugbc.tab.c"
    break;

  case 510: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1797 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 6744 "src-generated/ugbc.tab.c"
    break;

  case 511: /* $@25: %empty  */
#line 1802 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 6752 "src-generated/ugbc.tab.c"
    break;

  case 517: /* $@26: %empty  */
#line 1812 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 6758 "src-generated/ugbc.tab.c"
    break;


#line 6762 "src-generated/ugbc.tab.c"

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

#line 1814 "src/ugbc.y"


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

