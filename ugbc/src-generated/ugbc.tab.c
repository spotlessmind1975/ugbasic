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
  YYSYMBOL_BLACK = 201,                    /* BLACK  */
  YYSYMBOL_WHITE = 202,                    /* WHITE  */
  YYSYMBOL_RED = 203,                      /* RED  */
  YYSYMBOL_CYAN = 204,                     /* CYAN  */
  YYSYMBOL_VIOLET = 205,                   /* VIOLET  */
  YYSYMBOL_GREEN = 206,                    /* GREEN  */
  YYSYMBOL_BLUE = 207,                     /* BLUE  */
  YYSYMBOL_YELLOW = 208,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 209,                   /* ORANGE  */
  YYSYMBOL_BROWN = 210,                    /* BROWN  */
  YYSYMBOL_LIGHT = 211,                    /* LIGHT  */
  YYSYMBOL_DARK = 212,                     /* DARK  */
  YYSYMBOL_GREY = 213,                     /* GREY  */
  YYSYMBOL_GRAY = 214,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 215,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 216,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 217,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 218,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 219,                /* TURQUOISE  */
  YYSYMBOL_TAN = 220,                      /* TAN  */
  YYSYMBOL_PINK = 221,                     /* PINK  */
  YYSYMBOL_PEACH = 222,                    /* PEACH  */
  YYSYMBOL_OLIVE = 223,                    /* OLIVE  */
  YYSYMBOL_Identifier = 224,               /* Identifier  */
  YYSYMBOL_String = 225,                   /* String  */
  YYSYMBOL_Integer = 226,                  /* Integer  */
  YYSYMBOL_227_ = 227,                     /* " "  */
  YYSYMBOL_YYACCEPT = 228,                 /* $accept  */
  YYSYMBOL_expr = 229,                     /* expr  */
  YYSYMBOL_expr_math = 230,                /* expr_math  */
  YYSYMBOL_term = 231,                     /* term  */
  YYSYMBOL_modula = 232,                   /* modula  */
  YYSYMBOL_factor = 233,                   /* factor  */
  YYSYMBOL_direct_integer = 234,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 235, /* random_definition_simple  */
  YYSYMBOL_random_definition = 236,        /* random_definition  */
  YYSYMBOL_color_enumeration = 237,        /* color_enumeration  */
  YYSYMBOL_exponential = 238,              /* exponential  */
  YYSYMBOL_239_1 = 239,                    /* $@1  */
  YYSYMBOL_240_2 = 240,                    /* $@2  */
  YYSYMBOL_241_3 = 241,                    /* $@3  */
  YYSYMBOL_position = 242,                 /* position  */
  YYSYMBOL_bank_definition_simple = 243,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 244, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 245,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 246, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 247, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 248,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 249, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 250, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 251,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 252,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 253, /* color_definition_expression  */
  YYSYMBOL_color_definition = 254,         /* color_definition  */
  YYSYMBOL_milliseconds = 255,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 256,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 257, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 258,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 259, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 260, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 261,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 262, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 263, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 264,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 265, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 266, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 267,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 268,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 269, /* text_definition_expression  */
  YYSYMBOL_text_definition = 270,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 271,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 272, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 273,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 274, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 275, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 276,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 277, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 278, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 279,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 280,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 281,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 282,         /* gosub_definition  */
  YYSYMBOL_var_definition = 283,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 284,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 285, /* point_definition_expression  */
  YYSYMBOL_point_definition = 286,         /* point_definition  */
  YYSYMBOL_ink_definition = 287,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 288,       /* on_goto_definition  */
  YYSYMBOL_289_4 = 289,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 290,      /* on_gosub_definition  */
  YYSYMBOL_291_5 = 291,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 292,       /* on_proc_definition  */
  YYSYMBOL_293_6 = 293,                    /* $@6  */
  YYSYMBOL_on_definition = 294,            /* on_definition  */
  YYSYMBOL_295_7 = 295,                    /* $@7  */
  YYSYMBOL_296_8 = 296,                    /* $@8  */
  YYSYMBOL_297_9 = 297,                    /* $@9  */
  YYSYMBOL_every_definition = 298,         /* every_definition  */
  YYSYMBOL_add_definition = 299,           /* add_definition  */
  YYSYMBOL_dimensions = 300,               /* dimensions  */
  YYSYMBOL_datatype = 301,                 /* datatype  */
  YYSYMBOL_dim_definition = 302,           /* dim_definition  */
  YYSYMBOL_303_10 = 303,                   /* $@10  */
  YYSYMBOL_304_11 = 304,                   /* $@11  */
  YYSYMBOL_305_12 = 305,                   /* $@12  */
  YYSYMBOL_dim_definitions = 306,          /* dim_definitions  */
  YYSYMBOL_indexes = 307,                  /* indexes  */
  YYSYMBOL_parameters = 308,               /* parameters  */
  YYSYMBOL_parameters_expr = 309,          /* parameters_expr  */
  YYSYMBOL_values = 310,                   /* values  */
  YYSYMBOL_print_definition = 311,         /* print_definition  */
  YYSYMBOL_312_13 = 312,                   /* $@13  */
  YYSYMBOL_313_14 = 313,                   /* $@14  */
  YYSYMBOL_writing_mode_definition = 314,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 315,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 316,       /* writing_definition  */
  YYSYMBOL_locate_definition = 317,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 318,         /* cmove_definition  */
  YYSYMBOL_hscroll_definition = 319,       /* hscroll_definition  */
  YYSYMBOL_vscroll_definition = 320,       /* vscroll_definition  */
  YYSYMBOL_statement = 321,                /* statement  */
  YYSYMBOL_322_15 = 322,                   /* $@15  */
  YYSYMBOL_323_16 = 323,                   /* $@16  */
  YYSYMBOL_324_17 = 324,                   /* $@17  */
  YYSYMBOL_325_18 = 325,                   /* $@18  */
  YYSYMBOL_326_19 = 326,                   /* $@19  */
  YYSYMBOL_327_20 = 327,                   /* $@20  */
  YYSYMBOL_328_21 = 328,                   /* $@21  */
  YYSYMBOL_329_22 = 329,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 330, /* statements_no_linenumbers  */
  YYSYMBOL_331_23 = 331,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 332, /* statements_with_linenumbers  */
  YYSYMBOL_333_24 = 333,                   /* $@24  */
  YYSYMBOL_statements_complex = 334,       /* statements_complex  */
  YYSYMBOL_335_25 = 335,                   /* $@25  */
  YYSYMBOL_program = 336,                  /* program  */
  YYSYMBOL_337_26 = 337                    /* $@26  */
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
#define YYLAST   3923

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  228
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  110
/* YYNRULES -- Number of rules.  */
#define YYNRULES  518
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1014

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   482


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
     225,   226,   227
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,    80,    84,    88,    91,    94,    97,   100,
     103,   106,   112,   113,   116,   123,   124,   128,   129,   133,
     140,   141,   145,   149,   152,   155,   158,   161,   167,   172,
     175,   178,   181,   184,   187,   190,   195,   200,   204,   208,
     212,   216,   220,   224,   228,   232,   236,   240,   244,   248,
     252,   256,   260,   264,   268,   272,   276,   280,   284,   288,
     292,   296,   300,   304,   310,   310,   321,   321,   332,   335,
     338,   347,   351,   358,   362,   366,   370,   374,   378,   382,
     386,   390,   393,   396,   399,   402,   405,   408,   411,   414,
     417,   420,   423,   426,   429,   432,   435,   438,   441,   444,
     447,   450,   453,   456,   459,   462,   465,   468,   471,   474,
     477,   480,   483,   486,   489,   492,   492,   498,   501,   504,
     508,   512,   516,   520,   524,   528,   532,   536,   540,   543,
     546,   549,   552,   555,   558,   561,   564,   567,   570,   573,
     576,   579,   582,   585,   588,   591,   594,   597,   600,   603,
     606,   609,   613,   617,   620,   624,   628,   632,   636,   642,
     642,   645,   648,   651,   654,   657,   660,   664,   667,   670,
     673,   677,   680,   683,   686,   690,   693,   696,   699,   705,
     708,   711,   714,   717,   722,   723,   726,   729,   734,   737,
     742,   743,   746,   749,   754,   757,   762,   763,   766,   769,
     772,   777,   780,   783,   788,   789,   792,   793,   794,   797,
     800,   803,   808,   811,   814,   820,   821,   824,   827,   830,
     833,   836,   839,   842,   845,   848,   851,   854,   857,   860,
     863,   866,   871,   874,   877,   880,   883,   886,   889,   892,
     895,   898,   901,   904,   907,   910,   913,   918,   919,   922,
     925,   928,   931,   934,   940,   943,   949,   950,   953,   958,
     963,   964,   967,   970,   975,   978,   983,   984,   987,   992,
     997,   998,  1001,  1004,  1007,  1012,  1015,  1021,  1022,  1025,
    1028,  1031,  1034,  1037,  1042,  1045,  1048,  1053,  1054,  1056,
    1057,  1060,  1063,  1066,  1071,  1078,  1081,  1087,  1090,  1096,
    1099,  1105,  1110,  1111,  1114,  1119,  1123,  1123,  1128,  1132,
    1132,  1137,  1141,  1141,  1146,  1146,  1149,  1149,  1152,  1152,
    1157,  1160,  1163,  1168,  1171,  1177,  1181,  1188,  1191,  1194,
    1197,  1200,  1203,  1206,  1209,  1212,  1215,  1220,  1220,  1228,
    1228,  1236,  1236,  1247,  1248,  1252,  1256,  1263,  1268,  1273,
    1278,  1283,  1288,  1296,  1301,  1306,  1311,  1316,  1321,  1326,
    1330,  1337,  1341,  1348,  1351,  1355,  1358,  1358,  1362,  1362,
    1368,  1372,  1376,  1380,  1384,  1391,  1395,  1399,  1403,  1407,
    1414,  1420,  1423,  1426,  1432,  1435,  1438,  1444,  1447,  1450,
    1453,  1459,  1462,  1468,  1469,  1470,  1471,  1472,  1473,  1474,
    1475,  1476,  1477,  1478,  1479,  1480,  1481,  1482,  1483,  1486,
    1487,  1488,  1489,  1490,  1493,  1496,  1497,  1498,  1499,  1502,
    1505,  1508,  1511,  1514,  1517,  1520,  1523,  1526,  1529,  1532,
    1535,  1538,  1541,  1544,  1547,  1550,  1553,  1556,  1559,  1562,
    1562,  1567,  1570,  1573,  1576,  1579,  1582,  1585,  1588,  1591,
    1594,  1597,  1600,  1603,  1606,  1610,  1610,  1615,  1618,  1621,
    1624,  1627,  1630,  1634,  1638,  1642,  1642,  1647,  1647,  1652,
    1652,  1657,  1660,  1663,  1666,  1669,  1670,  1673,  1676,  1679,
    1682,  1685,  1688,  1689,  1690,  1691,  1692,  1695,  1698,  1701,
    1704,  1707,  1710,  1713,  1716,  1717,  1726,  1735,  1735,  1747,
    1747,  1764,  1764,  1781,  1784,  1785,  1789,  1790,  1790,  1794,
    1794,  1801,  1801,  1804,  1805,  1806,  1807,  1811,  1811
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
  "JRIGHT", "JFIRE", "BLACK", "WHITE", "RED", "CYAN", "VIOLET", "GREEN",
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
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482
};
#endif

#define YYPACT_NINF (-876)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-498)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -876,    73,  1089,  -876,  -876,  -148,  -113,  2877,   -16,  -876,
      62,  2454,   106,    -4,  2454,  -876,    43,   214,  2877,   -72,
    -137,  -876,  -876,  -876,  2044,   127,    18,  2877,  2877,    82,
     -38,  -876,   129,   160,  2877,  2877,  -876,   177,   181,  -136,
    2877,    76,   141,  -876,   -32,  -876,  2877,     2,  2249,   202,
      40,  2877,    61,    69,    77,    81,  -100,  -100,  2877,  2877,
     155,     4,  1414,  -876,  -876,  1634,  2877,  2877,    99,  -876,
    -876,  -876,  -876,  2877,  -876,  -876,    22,   237,   300,     9,
    -876,   309,   317,   324,  -876,  -876,  -876,   104,   313,  1839,
    -876,  -876,   305,   310,   311,    70,  -876,  -876,    14,  -876,
    -876,   312,   314,  2877,  -876,  -876,   315,   316,   318,   319,
     320,   323,   349,   350,   351,   352,   353,   354,   355,   357,
     360,   361,   368,  -876,  -876,   369,   166,   -27,    23,   322,
     327,   335,   388,   389,   390,   391,  -876,  -876,  -876,    -1,
     374,  3492,  -876,   375,   376,   377,   378,   379,   381,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,   215,  -876,  -876,    83,
      58,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
     217,    15,  -876,  -876,   276,    86,   286,   273,    51,  -876,
    -876,  -876,  2454,   394,  -876,  -876,  -876,  2454,  2454,  2454,
    -876,  -876,  -876,   198,    63,    79,  -876,  -876,  -876,   -14,
     339,    -3,    -2,     3,     8,   398,  -876,  -876,  -876,   218,
     271,  -876,  -876,  -876,  2454,  -876,  -876,   395,  -876,  -876,
    -876,  -876,  -876,  2454,   380,   382,  -876,  -876,  -876,   -15,
    -876,    92,  -876,  -876,  -876,  -876,  -876,  2877,  2672,  -876,
    -876,   420,  -876,  -876,  -876,  2454,  -876,  -876,  -876,  2454,
     396,  -876,  -876,  -876,   358,  -876,  -876,  -876,   282,  2877,
    2877,  -876,  -876,  2454,  -876,  -876,  -876,   397,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  2877,  2877,  -876,  -876,
    -876,  -876,   421,  -876,  -876,   280,  -876,  2877,   431,  -876,
    -876,  -876,    50,   432,  -876,   289,   290,   292,    65,   435,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,   437,  -876,  2877,   438,  -876,  2877,   439,  -876,  -876,
    -876,  2877,  -876,   152,  -876,  -876,  -876,   220,  -876,  2877,
    -876,  -876,  2877,   434,  -876,  -876,   411,    64,  1276,  -876,
    1089,  1089,  -876,   412,   413,   414,   416,   417,   418,   150,
     419,  2454,  2454,  2454,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,   422,  -876,  -876,  2877,  2877,  -876,  2877,
    2877,  2877,  2877,  2877,  2877,  2877,  2877,  2877,  2877,  2877,
    2877,  2877,  2877,  2877,  2877,  2877,  3082,   423,   227,  -876,
    -876,   424,  -876,  -876,   425,   426,  -876,  -876,  -876,  -876,
    -876,  2877,  -876,  2877,  1839,   427,   441,  2877,  2877,  2877,
    2877,  2877,  2877,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,   429,  -876,   430,   291,   304,  3082,  3082,  3082,  3082,
    3082,  3082,  3082,  3082,  3082,  3082,  3082,  3082,  3082,   -73,
    3287,  3697,   436,   440,  2454,  -876,  -876,   383,   399,   400,
     401,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  2454,   443,  -876,  -876,  -876,   428,   339,   444,   339,
     446,   339,   450,   339,   451,   339,  -876,  2877,   445,  -876,
    -876,   258,   263,   130,   157,  -876,  -876,  -876,   447,   339,
     449,  -876,  -876,   266,   274,   208,   219,  -876,  -876,   452,
    -876,  -876,  2454,  -876,  -876,  2454,  2454,  -876,  -876,  -876,
     442,   257,  -876,   476,  2877,  -876,  -876,  -876,  -876,  2454,
    -876,  2877,   477,   480,  -876,  -876,  2454,   433,   482,  2877,
     385,   485,  2877,  -876,  -876,  -876,  -876,  -876,  -876,   195,
    -876,  -876,   456,   481,    61,  -876,   346,  -876,  -100,   493,
      64,  -100,   -40,  -876,  2877,  -876,  2877,  -876,  -876,  -876,
    -876,  -876,  -876,  1089,  -876,  2877,   464,  2877,  2877,   465,
      10,  -876,  1276,  -876,  -876,  2877,   278,   279,   285,   287,
     294,   469,   478,   479,  -876,   484,   487,   488,   489,   490,
     491,  2877,   508,   509,   514,   517,   492,   494,   495,   496,
     525,   497,   498,   499,   500,   501,   534,   535,   504,   505,
     506,    57,   326,   507,  2877,  2877,  2877,   512,   133,   134,
    2877,  3082,   513,   515,   516,   518,   520,   522,   510,  2877,
    2877,  2877,  2877,   286,   286,   328,   328,   328,   328,   328,
     328,   328,   328,   273,    51,    51,   364,  3697,  3697,  -876,
    -876,   329,   338,  -876,  -876,  2877,   339,  2877,   339,   530,
     531,  2454,    33,  -876,   339,  -876,   339,  -876,   339,  -876,
     339,    93,  -876,  2877,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  2877,  -876,   339,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,   339,  -876,  -876,  -876,  -876,  -876,  -876,
     341,   342,   343,   345,   557,  2877,   564,   526,   527,   448,
    2877,  2877,   567,   568,  -876,   -41,   511,   356,  2877,   569,
    -876,  -876,  -876,   539,   359,   543,  -876,  2877,   365,  2877,
    -876,  -100,   575,  -876,   454,   457,  -876,  -876,  -876,  -876,
    -876,  -876,  2877,   576,   453,   581,   551,  2877,  -876,   587,
    -876,  -876,  -876,  -876,  -876,   370,   371,   373,  -876,  -876,
    -876,  -876,  -876,  -876,   556,  2877,  2877,  2877,  2877,  -876,
    -876,  -876,  -876,  2877,  -876,  -876,  -876,  -876,  -876,  2877,
    2877,  -876,  -876,  -876,  3697,   562,  -876,   563,   596,   599,
    -876,  2877,  -876,  2877,   603,   588,  -876,  -876,  -876,  -876,
    -876,  -876,  2877,   460,   577,  -876,  -876,  3697,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,   393,   405,  -876,  -876,
    -876,  -876,  -876,  -876,   582,  -876,   586,  -876,   403,   118,
    -876,   607,  -876,   613,   614,  -876,   623,  -876,   624,  -876,
     619,  2454,   626,  2877,  2877,   339,  -876,   595,   597,  2877,
     339,  -876,  -876,  2877,  -876,   186,  2877,   359,   628,   598,
     359,   486,   144,   503,   519,  -876,  -100,  -876,  -876,   600,
    2877,  -876,  2877,   627,   602,  2877,  -876,  -876,  -876,  -876,
     604,   605,   205,   216,   606,   608,   612,   617,  -876,  -876,
    2877,  2877,   618,   620,   621,  -876,  -876,  -876,  -876,  -876,
     455,   458,  -876,   609,  -876,   625,  -876,  2877,   339,   645,
     654,   655,  2877,  -876,  -876,  2877,  -876,  -876,  -876,   650,
     651,   629,   631,   546,  2877,   659,   601,   634,   359,  -876,
     635,  -876,   365,   671,    64,  -876,  -876,  -876,   666,  -876,
    -876,  2877,   668,   643,  -876,  -876,  2877,  -876,  2877,  -876,
    -876,  -876,  -876,  -876,   646,   647,  -876,  -876,  -876,  -876,
    -876,   459,   462,   649,   652,   341,   342,   343,  -876,  -876,
    2877,  2877,  -876,  -876,  2877,   653,  2877,  2877,  -876,  -876,
    -876,  -876,   365,   682,  2877,  -876,  2877,  -876,   656,   657,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,   677,  -876,  -876,  -876,   365,  -876,  -876,  -876,
    -876,  2877,  -876,  -876
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
      84,    85,     0,     0,     0,     0,   128,   129,     0,   154,
     155,   156,   157,     0,   119,   120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,   143,     0,
       0,     0,   152,   158,     0,     0,     0,     0,     0,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
       0,    49,    54,    55,    56,    57,    58,    59,    62,    63,
       0,    68,    72,    70,   363,     2,    12,    15,    17,    81,
      20,   411,     0,     0,   190,   191,   394,     0,     0,     0,
     204,   205,   396,     0,     0,     0,   215,   216,   397,     0,
       0,     0,     0,     0,     0,     0,   184,   185,   393,     0,
       0,   247,   248,   398,     0,   250,   251,   252,   256,   257,
     399,   279,   280,     0,     0,     0,   287,   288,   404,     0,
     482,     0,   299,   407,   295,   296,   483,     0,     0,   262,
     263,     0,   266,   267,   401,     0,   270,   271,   402,     0,
     273,   277,   278,   403,     0,   471,   477,   478,   459,     0,
       0,   503,   432,     0,   260,   261,   400,     0,   302,   303,
     405,   297,   298,   484,   487,   446,     0,     0,   445,   448,
     449,   443,     0,   321,   322,     0,   485,     0,     0,   409,
     304,   406,   337,   343,   494,   463,   454,   464,   353,   359,
     457,   458,   410,   472,   473,   474,   373,   371,   370,   372,
     374,     0,   475,     0,     0,   412,     0,     0,   417,   425,
     426,     0,   423,     0,   387,   389,   415,     0,   416,     0,
     511,   476,     0,   499,   465,   462,     0,     0,   505,   507,
     505,   505,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    29,    30,    32,    34,    35,
      31,    36,   108,     0,   122,   123,     0,     0,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
     127,     0,   125,   126,     0,     0,   140,   134,   135,   136,
     137,     0,   151,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,    47,    50,    51,    52,    53,    48,
      61,    69,   115,     0,   368,   366,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,   198,     0,     0,     0,
       0,    28,   206,   212,   207,   208,   213,   214,   209,   210,
     211,     0,     0,   196,   197,   395,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   160,     0,     0,   237,
     238,     0,     0,     0,     0,   234,   233,   159,     0,     0,
       0,   222,   223,     0,     0,     0,     0,   219,   218,     0,
     254,   249,     0,   284,   281,     0,     0,   314,   318,   316,
       0,     0,   440,     0,     0,   269,   268,   275,   272,     0,
     433,     0,     0,     0,   259,   258,     0,     0,   447,     0,
       0,     0,     0,   335,   327,   329,   334,   331,   336,     0,
     333,   341,     0,     0,     0,   467,     0,   469,     0,   354,
       0,     0,     0,   381,   382,   384,   385,   424,   388,   390,
     391,   392,   408,   505,   495,     0,     0,     0,     0,     0,
     501,   510,   505,   514,   516,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,     0,     0,     0,
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
      80,    73,    75,    79,    77,     0,     0,     0,    83,    82,
      87,    86,    89,    88,     0,     0,     0,     0,     0,    96,
      97,    98,   107,     0,   101,   102,   103,   104,   105,     0,
       0,   117,   118,   109,     0,     0,   113,     0,     0,     0,
     144,     0,    99,     0,     0,    27,   150,   145,   146,   147,
     148,   149,     0,     0,     0,   369,   367,     0,    23,    26,
     189,   187,   203,   200,   202,   199,     0,     0,   194,   192,
     163,   176,   168,   171,   165,   177,   169,   173,     0,     0,
     232,     0,   217,     0,   305,   315,   308,   319,   311,   317,
     291,     0,     0,     0,     0,     0,   460,     0,     0,     0,
       0,   450,   451,     0,   320,     0,     0,     0,   325,     0,
       0,     0,   347,     0,     0,   357,     0,   379,   377,     0,
       0,   466,     0,     0,     0,     0,    74,    76,    78,   131,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   132,
       0,     0,     0,     0,     0,   116,    65,    24,   195,   193,
       0,     0,   179,   164,   175,   167,   172,     0,     0,     0,
       0,     0,     0,   293,   292,     0,   265,   276,   274,     0,
       0,     0,     0,   452,     0,     0,     0,     0,     0,   338,
       0,   468,     0,   348,     0,   456,   470,   358,     0,   362,
     346,     0,     0,     0,    90,    91,     0,    92,     0,    94,
     106,   112,   111,    22,     0,     0,   100,   153,    67,   181,
     183,     0,     0,     0,     0,     0,     0,     0,   294,   264,
       0,     0,   301,   300,     0,     0,     0,     0,   342,   326,
     340,   350,     0,   349,     0,   498,     0,   138,     0,     0,
     139,   133,   180,   182,   236,   221,   307,   310,   313,   490,
     491,   461,     0,   492,   324,   351,     0,   500,   502,    93,
      95,     0,   352,   493
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -876,    -7,   -49,   -88,   261,  -376,   404,  -876,  -876,  -876,
    -138,  -876,  -876,  -876,   483,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,   521,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -271,  -876,  -267,  -876,  -266,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -792,  -336,  -876,  -876,  -876,  -876,   156,  -624,
    -875,   -55,  -621,   -53,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -329,  -876,  -876,  -876,  -322,  -876,  -876,  -876
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   745,   175,   176,   177,   178,   195,   361,   362,   179,
     180,   423,   628,   629,   488,   206,   207,   208,   184,   185,
     186,   463,   464,   465,   190,   191,   192,   457,   196,   197,
     198,   211,   212,   213,   218,   219,   220,   264,   265,   266,
     242,   243,   244,   246,   247,   248,   251,   252,   253,   226,
     227,   228,   232,   236,   273,   233,   268,   269,   270,   291,
     835,   909,   837,   910,   839,   911,   230,   700,   702,   701,
     286,   289,   859,   541,   293,   542,   543,   723,   294,   746,
     863,   300,   744,   181,   632,   631,   311,   737,   312,   315,
     318,   326,   328,    81,   237,   546,   567,   727,   729,   336,
     566,   337,    82,   572,    83,   338,    84,   563,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     174,   569,   301,   406,   194,   302,   804,   209,   803,   571,
     611,   229,   182,   330,   461,   331,   331,   241,   573,   574,
     254,   255,   332,   332,   200,   467,   469,   261,   262,   333,
     333,   471,   201,   274,   363,   421,   473,   401,   646,   281,
     277,   285,   507,   391,   290,   193,   249,  -497,  -497,   202,
     734,   174,   303,   -64,   193,   314,   257,   981,   317,   319,
     320,   644,   645,   389,   784,   927,   322,   323,   930,   820,
    -339,   214,   548,     3,   439,   440,    85,   203,   204,   533,
     439,   440,   350,   215,   216,   549,   821,   234,   271,   235,
     272,   508,   187,   533,   426,   427,   368,   188,   428,   354,
     429,   430,   431,   432,   433,   306,   861,  1005,   864,   250,
     258,    86,   510,   307,   822,   823,   278,   550,   869,   647,
     324,   325,   735,   874,   298,   299,   828,   736,   534,   535,
     536,  1012,   199,   509,   217,   390,   979,   189,   511,   537,
     791,   793,   534,   535,   536,   829,   452,   453,   355,   356,
     357,   932,   231,   537,   903,   245,   364,   358,   359,   360,
     334,   334,   452,   458,   933,   392,   422,   259,   308,   309,
     310,   904,   792,   584,   365,   442,   256,   538,   894,   678,
     445,   447,   449,   393,   441,   851,   387,   434,   679,   539,
     441,   538,   402,   924,   279,   435,   934,   540,   260,   905,
     906,   304,   305,   539,   388,   263,   680,   500,   183,   267,
     462,   540,   946,   276,   732,   681,   503,   454,   455,   456,
     205,   468,   470,   948,   275,   925,   282,   472,   581,   582,
     512,   513,   474,   454,   455,   459,   335,   335,   515,   583,
     287,   740,   517,   748,   947,   795,   476,   477,   940,   939,
     558,   559,   522,   523,   478,   949,   524,   689,   479,   480,
     221,   222,   223,   224,   288,   418,   690,   481,   691,   527,
     528,   419,   225,   720,   721,   321,   482,   692,   483,   484,
     531,   424,   327,   425,   722,   292,   414,   485,   486,   415,
     416,  -365,   437,   295,   438,  -365,   417,  -365,   487,   476,
     489,   296,   649,   650,  -364,   297,   553,   490,  -364,   555,
    -364,   491,   492,   329,   557,   339,   560,   561,   674,   675,
     493,   340,   562,   676,   677,   564,   685,   686,   341,   494,
     342,   495,   496,   343,   687,   688,   426,   427,   633,   634,
     497,   498,   394,   351,   585,   587,   589,   395,   352,   353,
     366,   487,   367,   369,   370,   396,   371,   372,   373,   592,
     593,   374,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   635,
     636,   637,   638,   639,   640,   641,   642,   375,   376,   377,
     378,   379,   380,   381,   617,   382,   618,   619,   383,   384,
     622,   623,   624,   625,   626,   627,   385,   386,   397,   398,
     399,   400,   403,   407,   408,   409,   410,   411,   210,   412,
     436,   413,   444,   420,   451,   193,   475,   514,   502,   519,
     505,   520,   506,   521,   529,   526,   530,   653,   532,   544,
     545,  -455,   551,   547,   552,   554,   556,   565,   280,   568,
     575,   613,   576,   577,   659,   578,   579,   580,   584,   655,
     591,   612,   614,   615,   616,   620,   621,   -66,   630,   651,
     672,   661,   664,   652,   666,   656,   657,   658,   668,   670,
     662,   704,   673,   705,   710,   682,   684,   711,   703,   715,
     693,   717,   718,   730,   724,   694,   733,   728,   696,   698,
     731,   725,   742,   747,   750,   751,   714,   706,   755,   808,
     809,   752,   707,   753,   709,   765,   766,   756,   757,   712,
     754,   767,   716,   758,   768,   719,   759,   760,   761,   762,
     763,   769,   773,   770,   771,   772,   774,   775,   776,   777,
     778,   779,   780,   781,   782,   783,   786,   738,   802,   739,
     785,   790,   796,   810,   797,   798,   807,   799,   741,   800,
     743,   801,   811,   816,   817,   834,   836,   838,   749,   840,
     841,   843,   844,   845,   849,   850,   856,   857,   805,   806,
     854,   860,   866,   870,   764,   858,   443,   853,   872,   862,
     873,   446,   448,   450,   875,   879,   876,   877,   983,   878,
     846,   888,   889,   890,   466,   871,   891,   787,   788,   789,
     793,   439,   895,   794,   907,   900,   896,   898,   501,   901,
     908,  -306,   743,   867,   174,   174,   868,   504,   902,   899,
    -309,  -312,   912,   915,   919,   928,   920,   929,   931,   938,
     941,   942,   961,   944,   945,   950,   887,   951,   812,   516,
     814,   952,   965,   518,   818,   935,   953,   956,   962,   957,
     958,   966,   967,   970,   971,   974,   830,   525,   972,   897,
     973,   936,   976,   978,   980,   831,   865,   977,   982,   984,
     959,   986,   987,   960,   992,   990,   991,   993,   994,  1006,
    1011,   995,  1002,   499,   996,  1009,  1010,   643,   842,   997,
     726,   998,     0,   847,   848,     0,     0,     0,     0,     0,
       0,   855,     0,     0,     0,     0,   460,     0,     0,     0,
     743,     0,   743,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   586,   588,   590,   880,   881,
     882,   883,     0,     0,     0,     0,   884,     0,     0,     0,
       0,     0,   885,   886,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   892,     0,   893,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   937,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   913,     0,   916,   917,     0,     0,
       0,     0,   921,     0,     0,     0,   923,     0,   654,   926,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   743,     0,   660,     0,     0,   943,     0,
       0,   663,     0,   665,     0,   667,     0,   669,     0,   671,
       0,     0,     0,   954,   955,     0,     0,     0,     0,     0,
       0,     0,     0,   683,     0,     0,     0,     0,     0,     0,
     963,     0,     0,     0,     0,   968,   695,     0,   969,   697,
     699,     0,     0,     0,     0,     0,     0,   975,     0,     0,
       0,     0,     0,   708,     0,     0,     0,     0,     0,     0,
     713,     0,     0,     0,   985,     0,     0,     0,     0,   988,
       0,   989,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   999,  1000,     0,     0,  1001,     0,  1003,
    1004,     0,     0,     0,     0,     0,     0,  1007,     0,  1008,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1013,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     813,     0,   815,     0,     0,   819,     0,     0,   824,     0,
     825,     0,   826,     0,   827,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   832,     0,
       0,     0,     4,     0,     0,     0,     0,   833,     0,     5,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     8,     9,     0,    10,   852,
      11,    12,     0,    13,    14,     0,     0,     0,     0,     0,
       0,    15,     0,    16,    17,    18,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,    20,     0,     0,     0,
       0,    21,    22,    23,    24,    25,    26,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
       0,    29,    30,     0,    31,     0,     0,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,     0,    42,
       0,     0,     0,    43,    44,    45,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,    52,     0,    53,    54,    55,
       0,     0,    56,     0,     0,   914,    57,     0,    58,   918,
       0,    59,    60,     0,   922,     0,     0,    61,     0,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,     0,     0,    74,    75,    76,    77,    78,     4,
       0,     0,     0,     0,     0,     0,     5,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     0,     8,     9,     0,    10,     0,    11,    12,     0,
      13,    14,   964,    79,     0,    80,     0,     0,    15,     0,
      16,    17,    18,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,    21,    22,
      23,    24,    25,    26,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,    29,    30,
       0,    31,     0,     0,    32,    33,    34,     0,    35,    36,
      37,    38,    39,    40,    41,     0,    42,     0,     0,     0,
      43,    44,    45,    46,    47,     0,    48,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,     0,    51,
       0,   313,    52,    87,    53,    54,    55,     0,     0,    56,
       0,     0,     0,    57,     0,    58,     0,     0,    59,    60,
       0,     0,    88,     0,    61,     0,    62,    63,    64,    65,
      66,    67,    89,    68,    69,    70,    71,    72,    73,     0,
       0,    74,    75,    76,    77,    78,     0,     0,    90,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,    94,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
     570,    96,    97,     0,    98,     0,     0,     0,     0,     0,
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
     154,   155,   156,   157,   158,   159,   160,   161,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   316,     0,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
     154,   155,   156,   157,   158,   159,   160,   161,    87,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,     0,     0,     0,     0,    88,   344,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,    94,     0,     0,    95,   345,   346,   347,
       0,     0,     0,     0,     0,     0,    96,    97,   348,    98,
       0,     0,     0,     0,     0,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,   104,   105,     0,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   349,   121,
     122,   123,     0,   124,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,     0,   127,
       0,   128,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     0,   130,     0,     0,   131,     0,   132,   133,   134,
     135,     0,   136,   137,     0,     0,     0,     0,   138,   139,
     140,   141,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    87,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,     0,     0,     0,
       0,     0,   238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,   239,   240,     0,     0,     0,     0,
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
     154,   155,   156,   157,   158,   159,   160,   161,    87,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,     0,     0,     0,     0,     0,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,   283,   284,     0,     0,     0,
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
     159,   160,   161,    87,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,     0,     0,     0,
       0,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,     0,    94,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
     193,    96,    97,     0,    98,     0,     0,     0,     0,     0,
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
     154,   155,   156,   157,   158,   159,   160,   161,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   343,     0,     0,     0,     0,     0,     0,     0,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,    94,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,     0,    98,     0,     0,     0,     0,     0,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   105,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     126,     0,   127,     0,   128,     0,     0,     0,     0,     0,
       0,     0,   129,     0,     0,   130,     0,     0,   131,     0,
     132,   133,   134,   135,     0,   136,   137,     0,     0,     0,
       0,   138,   139,   140,   141,     0,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    87,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,     0,
       0,    94,     0,     0,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,     0,    98,     0,     0,
       0,     0,     0,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,   104,
     105,     0,     0,     0,     0,     0,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,     0,   121,   122,   123,
       0,   124,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,     0,   127,     0,   128,
       0,     0,     0,     0,     0,     0,     0,   129,     0,     0,
     130,     0,     0,   131,     0,   132,   133,   134,   135,     0,
     136,   137,     0,     0,     0,     0,   138,   139,   140,   141,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    87,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,     0,     0,     0,     0,     0,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,    94,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,     0,    98,     0,     0,     0,     0,     0,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     126,     0,   127,     0,   128,     0,     0,     0,     0,     0,
       0,     0,   129,     0,     0,   130,     0,     0,   131,     0,
     132,   133,   134,   135,     0,   136,   137,     0,     0,     0,
       0,   138,   139,   140,   141,     0,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    87,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,     0,
       0,    94,     0,     0,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,     0,    98,     0,     0,
       0,     0,     0,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   648,   104,
     105,     0,     0,     0,     0,     0,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,     0,   121,   122,   123,
       0,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,     0,   127,     0,   128,
       0,     0,     0,     0,     0,     0,     0,   129,     0,     0,
     130,     0,     0,   131,     0,   132,   133,   134,   135,     0,
     136,   137,     0,     0,     0,     0,   138,   139,   140,   405,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    87,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,     0,     0,     0,     0,     0,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     404,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,    94,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,     0,    98,     0,     0,     0,     0,     0,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     126,     0,   127,     0,   128,     0,     0,     0,     0,     0,
       0,     0,   129,     0,     0,   130,     0,     0,   131,     0,
     132,   133,   134,   135,     0,   136,   137,     0,     0,     0,
       0,   138,   139,   140,   405,     0,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    87,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,     0,
       0,    94,     0,     0,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,     0,    98,     0,     0,
       0,     0,     0,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
     105,     0,     0,     0,     0,     0,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,     0,     0,   118,   119,   120,     0,   121,   122,   123,
       0,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,     0,   127,     0,   128,
       0,     0,     0,     0,     0,     0,     0,   129,     0,     0,
     130,     0,     0,   131,     0,   132,   133,   134,   135,     0,
     136,   137,     0,     0,     0,     0,   138,   139,   140,   405,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173
};

static const yytype_int16 yycheck[] =
{
       7,   337,    57,   141,    11,    58,   630,    14,   629,   338,
     386,    18,    28,     4,    28,     6,     6,    24,   340,   341,
      27,    28,    13,    13,    28,    28,    28,    34,    35,    20,
      20,    28,    36,    40,    20,    20,    28,    38,   111,    46,
      72,    48,    57,    20,    51,    86,    28,    38,    38,    53,
      90,    58,    59,    38,    86,    62,    94,   932,    65,    66,
      67,   437,   438,    90,     7,   857,    73,    45,   860,    36,
      20,    28,     7,     0,    23,    24,   224,    81,    82,    29,
      23,    24,    89,    40,    41,    20,    53,   224,   224,   226,
     226,   106,    30,    29,     8,     9,   103,    35,    12,    29,
      14,    15,    16,    17,    18,   101,   727,   982,   729,    91,
     148,   224,    20,   109,    81,    82,   148,    52,   742,   192,
      98,    99,   162,   747,   224,   225,    33,   167,    78,    79,
      80,  1006,    26,   148,    91,   162,   928,    75,    46,    89,
       7,     7,    78,    79,    80,    52,    83,    84,    78,    79,
      80,     7,   224,    89,    36,    28,   142,    87,    88,    89,
     151,   151,    83,    84,    20,   142,   151,    38,   164,   165,
     166,    53,    39,    39,   160,   182,    94,   127,   802,    49,
     187,   188,   189,   160,   133,   226,    20,   101,    58,   139,
     133,   127,   193,     7,   226,   109,    52,   147,    38,    81,
      82,    46,    47,   139,    38,    28,    49,   214,   224,    28,
     224,   147,     7,    72,   550,    58,   223,   154,   155,   156,
     224,   224,   224,     7,   148,    39,   224,   224,    78,    79,
     237,   238,   224,   154,   155,   156,   227,   227,   245,    89,
      38,   563,   249,   572,    39,   621,    28,    29,   872,   870,
      98,    99,   259,   260,    36,    39,   263,    49,    40,    41,
      46,    47,    48,    49,   224,   207,    58,    49,    49,   276,
     277,   213,    58,    78,    79,   176,    58,    58,    60,    61,
     287,     5,    45,     7,    89,   224,   203,    69,    70,   206,
     207,     0,    19,   224,    21,     4,   213,     6,    80,    28,
      29,   224,   440,   441,     0,   224,   313,    36,     4,   316,
       6,    40,    41,    13,   321,     6,    96,    97,    60,    61,
      49,     4,   329,    60,    61,   332,    60,    61,     4,    58,
     226,    60,    61,    20,    60,    61,     8,     9,   426,   427,
      69,    70,    20,    38,   351,   352,   353,    20,    38,    38,
      38,    80,    38,    38,    38,    20,    38,    38,    38,   366,
     367,    38,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   428,
     429,   430,   431,   432,   433,   434,   435,    38,    38,    38,
      38,    38,    38,    38,   401,    38,   403,   404,    38,    38,
     407,   408,   409,   410,   411,   412,    38,    38,    20,    20,
      20,    20,    38,    38,    38,    38,    38,    38,    14,    38,
     134,   206,    28,   206,   226,    86,    28,     7,    33,    33,
      50,    73,    50,   151,    13,    38,   156,   444,     7,     7,
     151,   151,     7,   151,     7,     7,     7,    13,    44,    38,
      38,   224,    39,    39,   461,    39,    39,    39,    39,    76,
      38,    38,    38,    38,    38,    38,    25,    38,    38,    33,
     477,    28,    28,    33,    28,    76,    76,    76,    28,    28,
      52,   224,    37,     7,     7,    38,    37,     7,    46,     7,
      38,   106,     7,   548,    38,   502,   551,   151,   505,   506,
       7,    20,    38,    38,   226,   226,    73,   514,    39,   647,
     648,   226,   519,   226,   521,     7,     7,    39,    39,   526,
     226,     7,   529,    39,     7,   532,    39,    39,    39,    39,
      39,    39,     7,    39,    39,    39,    39,    39,    39,    39,
      39,     7,     7,    39,    39,    39,    39,   554,    38,   556,
     224,    39,    39,   224,    39,    39,   192,    39,   565,    39,
     567,    39,   224,    33,    33,   224,   224,   224,   575,   224,
      13,     7,    46,    46,     7,     7,     7,    38,   631,   632,
     224,    38,     7,     7,   591,   226,   182,    76,     7,   224,
      39,   187,   188,   189,     7,    39,   226,   226,   934,   226,
     152,    39,    39,     7,   200,   152,     7,   614,   615,   616,
       7,    23,   152,   620,     7,    33,    39,   224,   214,    33,
       7,     7,   629,   169,   631,   632,   169,   223,   225,   224,
       7,     7,    13,     7,    39,     7,    39,    39,   152,    39,
      13,    39,    33,    39,    39,    39,   784,    39,   655,   245,
     657,    39,     7,   249,   661,   152,    39,    39,    33,    39,
      39,     7,     7,    13,    13,   119,   673,   263,    39,   807,
      39,   152,    13,    39,    39,   682,   731,    76,     7,    13,
     225,    13,    39,   225,   225,    39,    39,   225,    39,     7,
      13,    39,    39,   210,   965,    39,    39,   436,   705,   966,
     544,   967,    -1,   710,   711,    -1,    -1,    -1,    -1,    -1,
      -1,   718,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
     727,    -1,   729,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   351,   352,   353,   765,   766,
     767,   768,    -1,    -1,    -1,    -1,   773,    -1,    -1,    -1,
      -1,    -1,   779,   780,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   791,    -1,   793,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   866,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   841,    -1,   843,   844,    -1,    -1,
      -1,    -1,   849,    -1,    -1,    -1,   853,    -1,   444,   856,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   870,    -1,   461,    -1,    -1,   875,    -1,
      -1,   467,    -1,   469,    -1,   471,    -1,   473,    -1,   475,
      -1,    -1,    -1,   890,   891,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   489,    -1,    -1,    -1,    -1,    -1,    -1,
     907,    -1,    -1,    -1,    -1,   912,   502,    -1,   915,   505,
     506,    -1,    -1,    -1,    -1,    -1,    -1,   924,    -1,    -1,
      -1,    -1,    -1,   519,    -1,    -1,    -1,    -1,    -1,    -1,
     526,    -1,    -1,    -1,   941,    -1,    -1,    -1,    -1,   946,
      -1,   948,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   970,   971,    -1,    -1,   974,    -1,   976,
     977,    -1,    -1,    -1,    -1,    -1,    -1,   984,    -1,   986,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1011,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     656,    -1,   658,    -1,    -1,   661,    -1,    -1,   664,    -1,
     666,    -1,   668,    -1,   670,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   684,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    -1,   693,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    26,    27,    -1,    29,   715,
      31,    32,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    92,    93,    -1,    95,    -1,    -1,    98,    99,   100,
      -1,   102,   103,   104,   105,   106,   107,   108,    -1,   110,
      -1,    -1,    -1,   114,   115,   116,   117,   118,    -1,   120,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,    -1,    -1,   146,    -1,   148,   149,   150,
      -1,    -1,   153,    -1,    -1,   841,   157,    -1,   159,   845,
      -1,   162,   163,    -1,   850,    -1,    -1,   168,    -1,   170,
     171,   172,   173,   174,   175,    -1,   177,   178,   179,   180,
     181,   182,    -1,    -1,   185,   186,   187,   188,   189,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    26,    27,    -1,    29,    -1,    31,    32,    -1,
      34,    35,   908,   224,    -1,   226,    -1,    -1,    42,    -1,
      44,    45,    46,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    92,    93,
      -1,    95,    -1,    -1,    98,    99,   100,    -1,   102,   103,
     104,   105,   106,   107,   108,    -1,   110,    -1,    -1,    -1,
     114,   115,   116,   117,   118,    -1,   120,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,     7,   146,     9,   148,   149,   150,    -1,    -1,   153,
      -1,    -1,    -1,   157,    -1,   159,    -1,    -1,   162,   163,
      -1,    -1,    28,    -1,   168,    -1,   170,   171,   172,   173,
     174,   175,    38,   177,   178,   179,   180,   181,   182,    -1,
      -1,   185,   186,   187,   188,   189,    -1,    -1,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,
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
     206,   207,   208,   209,   210,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,     7,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     206,   207,   208,   209,   210,   211,   212,   213,     9,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    74,    -1,    -1,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
     141,   142,    -1,   144,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,   160,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,
      -1,    -1,   173,    -1,    -1,   176,    -1,   178,   179,   180,
     181,    -1,   183,   184,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,     9,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    40,    41,    -1,    -1,    -1,    -1,
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
     206,   207,   208,   209,   210,   211,   212,   213,     9,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
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
     211,   212,   213,     9,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,
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
     206,   207,   208,   209,   210,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     138,    -1,   140,   141,   142,    -1,   144,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,    -1,   160,    -1,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   170,    -1,    -1,   173,    -1,    -1,   176,    -1,
     178,   179,   180,   181,    -1,   183,   184,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    -1,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     9,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,   136,   137,   138,    -1,   140,   141,   142,
      -1,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,
     173,    -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,
     183,   184,    -1,    -1,    -1,    -1,   189,   190,   191,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,     9,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,   136,   137,
     138,    -1,   140,   141,   142,    -1,   144,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,    -1,   160,    -1,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   170,    -1,    -1,   173,    -1,    -1,   176,    -1,
     178,   179,   180,   181,    -1,   183,   184,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    -1,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     9,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,   136,   137,   138,    -1,   140,   141,   142,
      -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,
     173,    -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,
     183,   184,    -1,    -1,    -1,    -1,   189,   190,   191,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,     9,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,   136,   137,
     138,    -1,   140,   141,   142,    -1,   144,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,    -1,   160,    -1,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   170,    -1,    -1,   173,    -1,    -1,   176,    -1,
     178,   179,   180,   181,    -1,   183,   184,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,    -1,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     9,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,    -1,   136,   137,   138,    -1,   140,   141,   142,
      -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,
     173,    -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,
     183,   184,    -1,    -1,    -1,    -1,   189,   190,   191,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   336,   337,     0,     3,    10,    11,    22,    26,    27,
      29,    31,    32,    34,    35,    42,    44,    45,    46,    51,
      57,    62,    63,    64,    65,    66,    67,    72,    90,    92,
      93,    95,    98,    99,   100,   102,   103,   104,   105,   106,
     107,   108,   110,   114,   115,   116,   117,   118,   120,   121,
     135,   143,   146,   148,   149,   150,   153,   157,   159,   162,
     163,   168,   170,   171,   172,   173,   174,   175,   177,   178,
     179,   180,   181,   182,   185,   186,   187,   188,   189,   224,
     226,   321,   330,   332,   334,   224,   224,     9,    28,    38,
      54,    55,    56,    71,    74,    77,    87,    88,    90,    96,
      97,    98,    99,   111,   112,   113,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   136,   137,
     138,   140,   141,   142,   144,   145,   158,   160,   162,   170,
     173,   176,   178,   179,   180,   181,   183,   184,   189,   190,
     191,   192,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   229,   230,   231,   232,   233,   237,
     238,   311,    28,   224,   246,   247,   248,    30,    35,    75,
     252,   253,   254,    86,   229,   234,   256,   257,   258,    26,
      28,    36,    53,    81,    82,   224,   243,   244,   245,   229,
     234,   259,   260,   261,    28,    40,    41,    91,   262,   263,
     264,    46,    47,    48,    49,    58,   277,   278,   279,   229,
     294,   224,   280,   283,   224,   226,   281,   322,    28,    40,
      41,   229,   268,   269,   270,    28,   271,   272,   273,    28,
      91,   274,   275,   276,   229,   229,    94,    94,   148,    38,
      38,   229,   229,    28,   265,   266,   267,    28,   284,   285,
     286,   224,   226,   282,   229,   148,    72,    72,   148,   226,
     234,   229,   224,    46,    47,   229,   298,    38,   224,   299,
     229,   287,   224,   302,   306,   224,   224,   224,   224,   225,
     309,   309,   311,   229,    46,    47,   101,   109,   164,   165,
     166,   314,   316,     7,   229,   317,     7,   229,   318,   229,
     229,   176,   229,    45,    98,    99,   319,    45,   320,    13,
       4,     6,    13,    20,   151,   227,   327,   329,   333,     6,
       4,     4,   226,    20,    29,    78,    79,    80,    89,   139,
     229,    38,    38,    38,    29,    78,    79,    80,    87,    88,
      89,   235,   236,    20,   142,   160,    38,    38,   229,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    20,    38,    90,
     162,    20,   142,   160,    20,    20,    20,    20,    20,    20,
      20,    38,   193,    38,    38,   192,   238,    38,    38,    38,
      38,    38,    38,   206,   203,   206,   207,   213,   207,   213,
     206,    20,   151,   239,     5,     7,     8,     9,    12,    14,
      15,    16,    17,    18,   101,   109,   134,    19,    21,    23,
      24,   133,   229,   234,    28,   229,   234,   229,   234,   229,
     234,   226,    83,    84,   154,   155,   156,   255,    84,   156,
     255,    28,   224,   249,   250,   251,   234,    28,   224,    28,
     224,    28,   224,    28,   224,    28,    28,    29,    36,    40,
      41,    49,    58,    60,    61,    69,    70,    80,   242,    29,
      36,    40,    41,    49,    58,    60,    61,    69,    70,   242,
     229,   234,    33,   229,   234,    50,    50,    57,   106,   148,
      20,    46,   229,   229,     7,   229,   234,   229,   234,    33,
      73,   151,   229,   229,   229,   234,    38,   229,   229,    13,
     156,   229,     7,    29,    78,    79,    80,    89,   127,   139,
     147,   301,   303,   304,     7,   151,   323,   151,     7,    20,
      52,     7,     7,   229,     7,   229,     7,   229,    98,    99,
      96,    97,   229,   335,   229,    13,   328,   324,    38,   301,
     224,   330,   331,   334,   334,    38,    39,    39,    39,    39,
      39,    78,    79,    89,    39,   229,   234,   229,   234,   229,
     234,    38,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   233,    38,   224,    38,    38,    38,   229,   229,   229,
      38,    25,   229,   229,   229,   229,   229,   229,   240,   241,
      38,   313,   312,   231,   231,   230,   230,   230,   230,   230,
     230,   230,   230,   232,   233,   233,   111,   192,   111,   238,
     238,    33,    33,   229,   234,    76,    76,    76,    76,   229,
     234,    28,    52,   234,    28,   234,    28,   234,    28,   234,
      28,   234,   229,    37,    60,    61,    60,    61,    49,    58,
      49,    58,    38,   234,    37,    60,    61,    60,    61,    49,
      58,    49,    58,    38,   229,   234,   229,   234,   229,   234,
     295,   297,   296,    46,   224,     7,   229,   229,   234,   229,
       7,     7,   229,   234,    73,     7,   229,   106,     7,   229,
      78,    79,    89,   305,    38,    20,   306,   325,   151,   326,
     309,     7,   301,   309,    90,   162,   167,   315,   229,   229,
     334,   229,    38,   229,   310,   229,   307,    38,   330,   229,
     226,   226,   226,   226,   226,    39,    39,    39,    39,    39,
      39,    39,    39,    39,   229,     7,     7,     7,     7,    39,
      39,    39,    39,     7,    39,    39,    39,    39,    39,     7,
       7,    39,    39,    39,     7,   224,    39,   229,   229,   229,
      39,     7,    39,     7,   229,   233,    39,    39,    39,    39,
      39,    39,    38,   310,   307,   311,   311,   192,   238,   238,
     224,   224,   229,   234,   229,   234,    33,    33,   229,   234,
      36,    53,    81,    82,   234,   234,   234,   234,    33,    52,
     229,   229,   234,   234,   224,   288,   224,   290,   224,   292,
     224,    13,   229,     7,    46,    46,   152,   229,   229,     7,
       7,   226,   234,    76,   224,   229,     7,    38,   226,   300,
      38,   310,   224,   308,   310,   309,     7,   169,   169,   307,
       7,   152,     7,    39,   307,     7,   226,   226,   226,    39,
     229,   229,   229,   229,   229,   229,   229,   238,    39,    39,
       7,     7,   229,   229,   307,   152,    39,   238,   224,   224,
      33,    33,   225,    36,    53,    81,    82,     7,     7,   289,
     291,   293,    13,   229,   234,     7,   229,   229,   234,    39,
      39,   229,   234,   229,     7,    39,   229,   300,     7,    39,
     300,   152,     7,    20,    52,   152,   152,   309,    39,   310,
     307,    13,    39,   229,    39,    39,     7,    39,     7,    39,
      39,    39,    39,    39,   229,   229,    39,    39,    39,   225,
     225,    33,    33,   229,   234,     7,     7,     7,   229,   229,
      13,    13,    39,    39,   119,   229,    13,    76,    39,   300,
      39,   308,     7,   301,    13,   229,    13,    39,   229,   229,
      39,    39,   225,   225,    39,    39,   288,   290,   292,   229,
     229,   229,    39,   229,   229,   308,     7,   229,   229,    39,
      39,    13,   308,   229
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   228,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   230,   230,   230,   231,   231,   232,   232,   232,
     233,   233,   233,   233,   233,   233,   233,   233,   234,   235,
     235,   235,   235,   235,   235,   235,   236,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   239,   238,   240,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   241,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   242,
     242,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   244,
     244,   244,   244,   244,   245,   245,   246,   246,   247,   247,
     248,   248,   249,   249,   250,   250,   251,   251,   252,   252,
     252,   253,   253,   253,   254,   254,   255,   255,   255,   256,
     256,   256,   257,   257,   257,   258,   258,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   261,   261,   262,
     262,   262,   262,   262,   263,   263,   264,   264,   265,   266,
     267,   267,   268,   268,   269,   269,   270,   270,   271,   272,
     273,   273,   274,   274,   274,   275,   275,   276,   276,   277,
     277,   277,   277,   277,   278,   278,   278,   279,   279,   280,
     280,   280,   280,   280,   280,   281,   281,   282,   282,   283,
     284,   285,   286,   286,   287,   288,   289,   288,   290,   291,
     290,   292,   293,   292,   295,   294,   296,   294,   297,   294,
     298,   298,   298,   299,   299,   300,   300,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   303,   302,   304,
     302,   305,   302,   306,   306,   307,   307,   308,   308,   308,
     308,   308,   308,   309,   309,   309,   309,   309,   309,   309,
     309,   310,   310,   311,   311,   311,   312,   311,   313,   311,
     314,   314,   314,   314,   314,   315,   315,   315,   315,   315,
     316,   317,   317,   317,   318,   318,   318,   319,   319,   319,
     319,   320,   320,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   322,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   323,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   324,   321,   325,   321,   326,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   327,   321,   328,
     321,   329,   321,   321,   321,   321,   330,   331,   330,   333,
     332,   335,   334,   334,   334,   334,   334,   337,   336
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
       4,     1,     4,     4,     1,     1,     4,     4,     4,     4,
       6,     6,     6,     8,     6,     8,     4,     4,     4,     4,
       6,     4,     4,     4,     4,     4,     6,     4,     2,     4,
       3,     6,     6,     4,     5,     0,     5,     4,     4,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     5,     5,     7,     2,     2,     2,     2,     7,     7,
       2,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     2,     1,     6,     1,     1,     1,     1,     1,     1,
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
#line 80 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3133 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 84 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3142 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 88 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3150 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 91 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3158 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 94 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3166 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 97 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 3174 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 100 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3182 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 103 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3190 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 106 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 3198 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 113 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3206 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 116 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3215 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 129 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3224 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 133 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3233 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 141 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 3242 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 145 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 3251 "src-generated/ugbc.tab.c"
    break;

  case 23: /* factor: factor HAS BIT exponential  */
#line 149 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[0].string) )->name;
      }
#line 3259 "src-generated/ugbc.tab.c"
    break;

  case 24: /* factor: factor HAS NOT BIT exponential  */
#line 152 "src/ugbc.y"
                                       {
        (yyval.string) = variable_not( _environment, variable_bit( _environment, (yyvsp[-4].string), (yyvsp[0].string) )->name )->name;
      }
#line 3267 "src-generated/ugbc.tab.c"
    break;

  case 25: /* factor: factor IS exponential  */
#line 155 "src/ugbc.y"
                              {
        (yyval.string) = variable_bit( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
      }
#line 3275 "src-generated/ugbc.tab.c"
    break;

  case 26: /* factor: factor IS NOT exponential  */
#line 158 "src/ugbc.y"
                                  {
        (yyval.string) = variable_not( _environment, variable_bit( _environment, (yyvsp[-3].string), (yyvsp[0].string) )->name )->name;
      }
#line 3283 "src-generated/ugbc.tab.c"
    break;

  case 27: /* factor: BIT exponential OF factor  */
#line 161 "src/ugbc.y"
                                  {
        (yyval.string) = variable_bit( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
      }
#line 3291 "src-generated/ugbc.tab.c"
    break;

  case 28: /* direct_integer: HASH Integer  */
#line 167 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3299 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: BYTE  */
#line 172 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3307 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: WORD  */
#line 175 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3315 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition_simple: DWORD  */
#line 178 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3323 "src-generated/ugbc.tab.c"
    break;

  case 32: /* random_definition_simple: POSITION  */
#line 181 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3331 "src-generated/ugbc.tab.c"
    break;

  case 33: /* random_definition_simple: COLOR  */
#line 184 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3339 "src-generated/ugbc.tab.c"
    break;

  case 34: /* random_definition_simple: WIDTH  */
#line 187 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3347 "src-generated/ugbc.tab.c"
    break;

  case 35: /* random_definition_simple: HEIGHT  */
#line 190 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3355 "src-generated/ugbc.tab.c"
    break;

  case 36: /* random_definition: random_definition_simple  */
#line 195 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3363 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: BLACK  */
#line 200 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3372 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: WHITE  */
#line 204 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3381 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: RED  */
#line 208 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3390 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: CYAN  */
#line 212 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3399 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: VIOLET  */
#line 216 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3408 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: GREEN  */
#line 220 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3417 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: BLUE  */
#line 224 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3426 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: YELLOW  */
#line 228 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3435 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: ORANGE  */
#line 232 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3444 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: BROWN  */
#line 236 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3453 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT RED  */
#line 240 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3462 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK GREY  */
#line 244 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3471 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: GREY  */
#line 248 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3480 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: LIGHT GREEN  */
#line 252 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3489 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LIGHT BLUE  */
#line 256 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3498 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: LIGHT GREY  */
#line 260 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3507 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: DARK BLUE  */
#line 264 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3516 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: MAGENTA  */
#line 268 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3525 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: PURPLE  */
#line 272 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3534 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: LAVENDER  */
#line 276 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3543 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: GOLD  */
#line 280 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3552 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: TURQUOISE  */
#line 284 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3561 "src-generated/ugbc.tab.c"
    break;

  case 59: /* color_enumeration: TAN  */
#line 288 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3570 "src-generated/ugbc.tab.c"
    break;

  case 60: /* color_enumeration: YELLOW GREEN  */
#line 292 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3579 "src-generated/ugbc.tab.c"
    break;

  case 61: /* color_enumeration: OLIVE GREEN  */
#line 296 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3588 "src-generated/ugbc.tab.c"
    break;

  case 62: /* color_enumeration: PINK  */
#line 300 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3597 "src-generated/ugbc.tab.c"
    break;

  case 63: /* color_enumeration: PEACH  */
#line 304 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3606 "src-generated/ugbc.tab.c"
    break;

  case 64: /* $@1: %empty  */
#line 310 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3615 "src-generated/ugbc.tab.c"
    break;

  case 65: /* exponential: Identifier $@1 OP indexes CP  */
#line 314 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-4].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-4].string) )->name;
    }
#line 3627 "src-generated/ugbc.tab.c"
    break;

  case 66: /* $@2: %empty  */
#line 321 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3636 "src-generated/ugbc.tab.c"
    break;

  case 67: /* exponential: Identifier DOLLAR $@2 OP indexes CP  */
#line 325 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-5].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-5].string) )->name;
    }
#line 3648 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: Identifier  */
#line 332 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3656 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: Identifier DOLLAR  */
#line 335 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3664 "src-generated/ugbc.tab.c"
    break;

  case 70: /* exponential: Integer  */
#line 338 "src/ugbc.y"
              { 
        if ( (yyvsp[0].integer) < 0 ) {
            (yyval.string) = variable_temporary( _environment, VT_SWORD, "(signed integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        } else {
            (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        }
      }
#line 3678 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: MINUS Integer  */
#line 347 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3687 "src-generated/ugbc.tab.c"
    break;

  case 72: /* exponential: String  */
#line 351 "src/ugbc.y"
             { 
        outline1("; (expr string: \"%s\")", (yyvsp[0].string) );
        (yyval.string) = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", (yyval.string) );
        variable_store_string( _environment, (yyval.string), (yyvsp[0].string) );
        outline2("; variable stored: %s = %s", (yyval.string), (yyvsp[0].string) );
      }
#line 3699 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP BYTE CP Integer  */
#line 358 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3708 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP SIGNED BYTE CP Integer  */
#line 362 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3717 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP WORD CP Integer  */
#line 366 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3726 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: OP SIGNED WORD CP Integer  */
#line 370 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3735 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: OP DWORD CP Integer  */
#line 374 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3744 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: OP SIGNED DWORD CP Integer  */
#line 378 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3753 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: OP POSITION CP Integer  */
#line 382 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3762 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: OP COLOR CP Integer  */
#line 386 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3771 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: color_enumeration  */
#line 390 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3779 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: PEEK OP direct_integer CP  */
#line 393 "src/ugbc.y"
                                {
        (yyval.string) = peek( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3787 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: PEEK OP expr CP  */
#line 396 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3795 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: XPEN  */
#line 399 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3803 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: YPEN  */
#line 402 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3811 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: COLLISION OP direct_integer CP  */
#line 405 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3819 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: COLLISION OP expr CP  */
#line 408 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3827 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: HIT OP direct_integer CP  */
#line 411 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3835 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: HIT OP expr CP  */
#line 414 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3843 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: LEFT OP expr COMMA expr CP  */
#line 417 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3851 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 420 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3859 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: MID OP expr COMMA expr CP  */
#line 423 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3867 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 426 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3875 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: INSTR OP expr COMMA expr CP  */
#line 429 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3883 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 432 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3891 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: UPPER OP expr CP  */
#line 435 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3899 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: LOWER OP expr CP  */
#line 438 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3907 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: STR OP expr CP  */
#line 441 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3915 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: BIN OP expr CP  */
#line 444 "src/ugbc.y"
                     {
        (yyval.string) = variable_bin( _environment, (yyvsp[-1].string), NULL )->name;
    }
#line 3923 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: BIN OP expr COMMA expr CP  */
#line 447 "src/ugbc.y"
                                {
        (yyval.string) = variable_bin( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3931 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: SPACE OP expr CP  */
#line 450 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3939 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: FLIP OP expr CP  */
#line 453 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3947 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: CHR OP expr CP  */
#line 456 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3955 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: ASC OP expr CP  */
#line 459 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3963 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: LEN OP expr CP  */
#line 462 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3971 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: STRING OP expr COMMA expr CP  */
#line 465 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3979 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: VAL OP expr CP  */
#line 468 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3987 "src-generated/ugbc.tab.c"
    break;

  case 108: /* exponential: RANDOM random_definition  */
#line 471 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3995 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: RND OP expr CP  */
#line 474 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 4003 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: OP expr CP  */
#line 477 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 4011 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: MAX OP expr COMMA expr CP  */
#line 480 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4019 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: MIN OP expr COMMA expr CP  */
#line 483 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4027 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: PARAM OP Identifier CP  */
#line 486 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 4035 "src-generated/ugbc.tab.c"
    break;

  case 114: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 489 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 4043 "src-generated/ugbc.tab.c"
    break;

  case 115: /* $@3: %empty  */
#line 492 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 4051 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: Identifier OSP $@3 values CSP  */
#line 494 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 4060 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: SGN OP expr CP  */
#line 498 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 4068 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: ABS OP expr CP  */
#line 501 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 4076 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: TRUE  */
#line 504 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 4085 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: FALSE  */
#line 508 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 4094 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: COLORS  */
#line 512 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 4103 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: PEN COLORS  */
#line 516 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 4112 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: PEN DEFAULT  */
#line 520 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 4121 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: DEFAULT PEN  */
#line 524 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 4130 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER COLORS  */
#line 528 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 4139 "src-generated/ugbc.tab.c"
    break;

  case 126: /* exponential: PAPER DEFAULT  */
#line 532 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 4148 "src-generated/ugbc.tab.c"
    break;

  case 127: /* exponential: DEFAULT PAPER  */
#line 536 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 4157 "src-generated/ugbc.tab.c"
    break;

  case 128: /* exponential: WIDTH  */
#line 540 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 4165 "src-generated/ugbc.tab.c"
    break;

  case 129: /* exponential: HEIGHT  */
#line 543 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 4173 "src-generated/ugbc.tab.c"
    break;

  case 130: /* exponential: TIMER  */
#line 546 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 4181 "src-generated/ugbc.tab.c"
    break;

  case 131: /* exponential: PEN DOLLAR OP expr CP  */
#line 549 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 4189 "src-generated/ugbc.tab.c"
    break;

  case 132: /* exponential: PAPER DOLLAR OP expr CP  */
#line 552 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 4197 "src-generated/ugbc.tab.c"
    break;

  case 133: /* exponential: CMOVE DOLLAR OP expr COMMA expr CP  */
#line 555 "src/ugbc.y"
                                         {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4205 "src-generated/ugbc.tab.c"
    break;

  case 134: /* exponential: CUP DOLLAR  */
#line 558 "src/ugbc.y"
                 {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 4213 "src-generated/ugbc.tab.c"
    break;

  case 135: /* exponential: CDOWN DOLLAR  */
#line 561 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 4221 "src-generated/ugbc.tab.c"
    break;

  case 136: /* exponential: CLEFT DOLLAR  */
#line 564 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 4229 "src-generated/ugbc.tab.c"
    break;

  case 137: /* exponential: CRIGHT DOLLAR  */
#line 567 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 4237 "src-generated/ugbc.tab.c"
    break;

  case 138: /* exponential: AT DOLLAR OP expr COMMA expr CP  */
#line 570 "src/ugbc.y"
                                      {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4245 "src-generated/ugbc.tab.c"
    break;

  case 139: /* exponential: LOCATE DOLLAR OP expr COMMA expr CP  */
#line 573 "src/ugbc.y"
                                          {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4253 "src-generated/ugbc.tab.c"
    break;

  case 140: /* exponential: TAB DOLLAR  */
#line 576 "src/ugbc.y"
                 {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 4261 "src-generated/ugbc.tab.c"
    break;

  case 141: /* exponential: XCURS  */
#line 579 "src/ugbc.y"
            {
        (yyval.string) = text_get_xcurs( _environment )->name;
    }
#line 4269 "src-generated/ugbc.tab.c"
    break;

  case 142: /* exponential: YCURS  */
#line 582 "src/ugbc.y"
            {
        (yyval.string) = text_get_ycurs( _environment )->name;
    }
#line 4277 "src-generated/ugbc.tab.c"
    break;

  case 143: /* exponential: TEXTADDRESS  */
#line 585 "src/ugbc.y"
                  {
        (yyval.string) = strdup( "TEXTADDRESS" );
    }
#line 4285 "src-generated/ugbc.tab.c"
    break;

  case 144: /* exponential: JOY OP expr CP  */
#line 588 "src/ugbc.y"
                     {
        (yyval.string) = joy( _environment, (yyvsp[-1].string) )->name;
    }
#line 4293 "src-generated/ugbc.tab.c"
    break;

  case 145: /* exponential: JUP OP expr CP  */
#line 591 "src/ugbc.y"
                     {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_UP )->name;
    }
#line 4301 "src-generated/ugbc.tab.c"
    break;

  case 146: /* exponential: JDOWN OP expr CP  */
#line 594 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_DOWN )->name;
    }
#line 4309 "src-generated/ugbc.tab.c"
    break;

  case 147: /* exponential: JLEFT OP expr CP  */
#line 597 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_LEFT )->name;
    }
#line 4317 "src-generated/ugbc.tab.c"
    break;

  case 148: /* exponential: JRIGHT OP expr CP  */
#line 600 "src/ugbc.y"
                        {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_RIGHT )->name;
    }
#line 4325 "src-generated/ugbc.tab.c"
    break;

  case 149: /* exponential: JFIRE OP expr CP  */
#line 603 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_FIRE )->name;
    }
#line 4333 "src-generated/ugbc.tab.c"
    break;

  case 150: /* exponential: FIRE OP expr CP  */
#line 606 "src/ugbc.y"
                      {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_FIRE )->name;
    }
#line 4341 "src-generated/ugbc.tab.c"
    break;

  case 151: /* exponential: JOY COUNT  */
#line 609 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, (yyval.string), JOY_COUNT );
    }
#line 4350 "src-generated/ugbc.tab.c"
    break;

  case 152: /* exponential: JOYCOUNT  */
#line 613 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, (yyval.string), JOY_COUNT );
    }
#line 4359 "src-generated/ugbc.tab.c"
    break;

  case 153: /* exponential: BIT OP expr COMMA expr CP  */
#line 617 "src/ugbc.y"
                                {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4367 "src-generated/ugbc.tab.c"
    break;

  case 154: /* exponential: UP  */
#line 620 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(UP)" )->name;
        variable_store( _environment, (yyval.string), JOY_UP );
    }
#line 4376 "src-generated/ugbc.tab.c"
    break;

  case 155: /* exponential: DOWN  */
#line 624 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(DOWN)" )->name;
        variable_store( _environment, (yyval.string), JOY_DOWN );
    }
#line 4385 "src-generated/ugbc.tab.c"
    break;

  case 156: /* exponential: LEFT  */
#line 628 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(LEFT)" )->name;
        variable_store( _environment, (yyval.string), JOY_LEFT );
    }
#line 4394 "src-generated/ugbc.tab.c"
    break;

  case 157: /* exponential: RIGHT  */
#line 632 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(RIGHT)" )->name;
        variable_store( _environment, (yyval.string), JOY_RIGHT );
    }
#line 4403 "src-generated/ugbc.tab.c"
    break;

  case 158: /* exponential: FIRE  */
#line 636 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(FIRE)" )->name;
        variable_store( _environment, (yyval.string), JOY_FIRE );
    }
#line 4412 "src-generated/ugbc.tab.c"
    break;

  case 161: /* bank_definition_simple: AT direct_integer  */
#line 645 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4420 "src-generated/ugbc.tab.c"
    break;

  case 162: /* bank_definition_simple: Identifier AT direct_integer  */
#line 648 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4428 "src-generated/ugbc.tab.c"
    break;

  case 163: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 651 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4436 "src-generated/ugbc.tab.c"
    break;

  case 164: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 654 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4444 "src-generated/ugbc.tab.c"
    break;

  case 165: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 657 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4452 "src-generated/ugbc.tab.c"
    break;

  case 166: /* bank_definition_simple: DATA AT direct_integer  */
#line 660 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4460 "src-generated/ugbc.tab.c"
    break;

  case 167: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 664 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4468 "src-generated/ugbc.tab.c"
    break;

  case 168: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 667 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4476 "src-generated/ugbc.tab.c"
    break;

  case 169: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 670 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4484 "src-generated/ugbc.tab.c"
    break;

  case 170: /* bank_definition_simple: CODE AT direct_integer  */
#line 673 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4492 "src-generated/ugbc.tab.c"
    break;

  case 171: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 677 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4500 "src-generated/ugbc.tab.c"
    break;

  case 172: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 680 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4508 "src-generated/ugbc.tab.c"
    break;

  case 173: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 683 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4516 "src-generated/ugbc.tab.c"
    break;

  case 174: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 686 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4524 "src-generated/ugbc.tab.c"
    break;

  case 175: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 690 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4532 "src-generated/ugbc.tab.c"
    break;

  case 176: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 693 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4540 "src-generated/ugbc.tab.c"
    break;

  case 177: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 696 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4548 "src-generated/ugbc.tab.c"
    break;

  case 178: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 699 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4556 "src-generated/ugbc.tab.c"
    break;

  case 179: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 705 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4564 "src-generated/ugbc.tab.c"
    break;

  case 180: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 708 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4572 "src-generated/ugbc.tab.c"
    break;

  case 181: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 711 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4580 "src-generated/ugbc.tab.c"
    break;

  case 182: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 714 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4588 "src-generated/ugbc.tab.c"
    break;

  case 183: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 717 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4596 "src-generated/ugbc.tab.c"
    break;

  case 186: /* raster_definition_simple: Identifier AT direct_integer  */
#line 726 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 4604 "src-generated/ugbc.tab.c"
    break;

  case 187: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 729 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 4612 "src-generated/ugbc.tab.c"
    break;

  case 188: /* raster_definition_expression: Identifier AT expr  */
#line 734 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4620 "src-generated/ugbc.tab.c"
    break;

  case 189: /* raster_definition_expression: AT expr WITH Identifier  */
#line 737 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4628 "src-generated/ugbc.tab.c"
    break;

  case 192: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 746 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 4636 "src-generated/ugbc.tab.c"
    break;

  case 193: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 749 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 4644 "src-generated/ugbc.tab.c"
    break;

  case 194: /* next_raster_definition_expression: Identifier AT expr  */
#line 754 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 4652 "src-generated/ugbc.tab.c"
    break;

  case 195: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 757 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4660 "src-generated/ugbc.tab.c"
    break;

  case 198: /* color_definition_simple: BORDER direct_integer  */
#line 766 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 4668 "src-generated/ugbc.tab.c"
    break;

  case 199: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 769 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4676 "src-generated/ugbc.tab.c"
    break;

  case 200: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 772 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4684 "src-generated/ugbc.tab.c"
    break;

  case 201: /* color_definition_expression: BORDER expr  */
#line 777 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 4692 "src-generated/ugbc.tab.c"
    break;

  case 202: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 780 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4700 "src-generated/ugbc.tab.c"
    break;

  case 203: /* color_definition_expression: SPRITE expr TO expr  */
#line 783 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4708 "src-generated/ugbc.tab.c"
    break;

  case 209: /* wait_definition_simple: direct_integer CYCLES  */
#line 797 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4716 "src-generated/ugbc.tab.c"
    break;

  case 210: /* wait_definition_simple: direct_integer TICKS  */
#line 800 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4724 "src-generated/ugbc.tab.c"
    break;

  case 211: /* wait_definition_simple: direct_integer milliseconds  */
#line 803 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4732 "src-generated/ugbc.tab.c"
    break;

  case 212: /* wait_definition_expression: expr CYCLES  */
#line 808 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4740 "src-generated/ugbc.tab.c"
    break;

  case 213: /* wait_definition_expression: expr TICKS  */
#line 811 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4748 "src-generated/ugbc.tab.c"
    break;

  case 214: /* wait_definition_expression: expr milliseconds  */
#line 814 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4756 "src-generated/ugbc.tab.c"
    break;

  case 217: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 824 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4764 "src-generated/ugbc.tab.c"
    break;

  case 218: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 827 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4772 "src-generated/ugbc.tab.c"
    break;

  case 219: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 830 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4780 "src-generated/ugbc.tab.c"
    break;

  case 220: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 833 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4788 "src-generated/ugbc.tab.c"
    break;

  case 221: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 836 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4796 "src-generated/ugbc.tab.c"
    break;

  case 222: /* sprite_definition_simple: direct_integer ENABLE  */
#line 839 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4804 "src-generated/ugbc.tab.c"
    break;

  case 223: /* sprite_definition_simple: direct_integer DISABLE  */
#line 842 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4812 "src-generated/ugbc.tab.c"
    break;

  case 224: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 845 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4820 "src-generated/ugbc.tab.c"
    break;

  case 225: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 848 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4828 "src-generated/ugbc.tab.c"
    break;

  case 226: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 851 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4836 "src-generated/ugbc.tab.c"
    break;

  case 227: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 854 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4844 "src-generated/ugbc.tab.c"
    break;

  case 228: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 857 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4852 "src-generated/ugbc.tab.c"
    break;

  case 229: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 860 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4860 "src-generated/ugbc.tab.c"
    break;

  case 230: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 863 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4868 "src-generated/ugbc.tab.c"
    break;

  case 231: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 866 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4876 "src-generated/ugbc.tab.c"
    break;

  case 232: /* sprite_definition_expression: expr DATA FROM expr  */
#line 871 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4884 "src-generated/ugbc.tab.c"
    break;

  case 233: /* sprite_definition_expression: expr MULTICOLOR  */
#line 874 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4892 "src-generated/ugbc.tab.c"
    break;

  case 234: /* sprite_definition_expression: expr MONOCOLOR  */
#line 877 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4900 "src-generated/ugbc.tab.c"
    break;

  case 235: /* sprite_definition_expression: expr COLOR expr  */
#line 880 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4908 "src-generated/ugbc.tab.c"
    break;

  case 236: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 883 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4916 "src-generated/ugbc.tab.c"
    break;

  case 237: /* sprite_definition_expression: expr ENABLE  */
#line 886 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4924 "src-generated/ugbc.tab.c"
    break;

  case 238: /* sprite_definition_expression: expr DISABLE  */
#line 889 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4932 "src-generated/ugbc.tab.c"
    break;

  case 239: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 892 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4940 "src-generated/ugbc.tab.c"
    break;

  case 240: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 895 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4948 "src-generated/ugbc.tab.c"
    break;

  case 241: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 898 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4956 "src-generated/ugbc.tab.c"
    break;

  case 242: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 901 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4964 "src-generated/ugbc.tab.c"
    break;

  case 243: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 904 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4972 "src-generated/ugbc.tab.c"
    break;

  case 244: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 907 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4980 "src-generated/ugbc.tab.c"
    break;

  case 245: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 910 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4988 "src-generated/ugbc.tab.c"
    break;

  case 246: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 913 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4996 "src-generated/ugbc.tab.c"
    break;

  case 249: /* bitmap_definition_simple: AT direct_integer  */
#line 922 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 5004 "src-generated/ugbc.tab.c"
    break;

  case 250: /* bitmap_definition_simple: ENABLE  */
#line 925 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 5012 "src-generated/ugbc.tab.c"
    break;

  case 251: /* bitmap_definition_simple: DISABLE  */
#line 928 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 5020 "src-generated/ugbc.tab.c"
    break;

  case 252: /* bitmap_definition_simple: CLEAR  */
#line 931 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 5028 "src-generated/ugbc.tab.c"
    break;

  case 253: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 934 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 5036 "src-generated/ugbc.tab.c"
    break;

  case 254: /* bitmap_definition_expression: AT expr  */
#line 940 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 5044 "src-generated/ugbc.tab.c"
    break;

  case 255: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 943 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 5052 "src-generated/ugbc.tab.c"
    break;

  case 258: /* textmap_definition_simple: AT direct_integer  */
#line 953 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 5060 "src-generated/ugbc.tab.c"
    break;

  case 259: /* textmap_definition_expression: AT expr  */
#line 958 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 5068 "src-generated/ugbc.tab.c"
    break;

  case 262: /* text_definition_simple: ENABLE  */
#line 967 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 5076 "src-generated/ugbc.tab.c"
    break;

  case 263: /* text_definition_simple: DISABLE  */
#line 970 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 5084 "src-generated/ugbc.tab.c"
    break;

  case 264: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 975 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 5092 "src-generated/ugbc.tab.c"
    break;

  case 265: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 978 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 5100 "src-generated/ugbc.tab.c"
    break;

  case 268: /* tiles_definition_simple: AT direct_integer  */
#line 987 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 5108 "src-generated/ugbc.tab.c"
    break;

  case 269: /* tiles_definition_expression: AT expr  */
#line 992 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 5116 "src-generated/ugbc.tab.c"
    break;

  case 272: /* colormap_definition_simple: AT direct_integer  */
#line 1001 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 5124 "src-generated/ugbc.tab.c"
    break;

  case 273: /* colormap_definition_simple: CLEAR  */
#line 1004 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 5132 "src-generated/ugbc.tab.c"
    break;

  case 274: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 1007 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 5140 "src-generated/ugbc.tab.c"
    break;

  case 275: /* colormap_definition_expression: AT expr  */
#line 1012 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 5148 "src-generated/ugbc.tab.c"
    break;

  case 276: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 1015 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 5156 "src-generated/ugbc.tab.c"
    break;

  case 279: /* screen_definition_simple: ON  */
#line 1025 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 5164 "src-generated/ugbc.tab.c"
    break;

  case 280: /* screen_definition_simple: OFF  */
#line 1028 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 5172 "src-generated/ugbc.tab.c"
    break;

  case 281: /* screen_definition_simple: ROWS direct_integer  */
#line 1031 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 5180 "src-generated/ugbc.tab.c"
    break;

  case 282: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 1034 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 5188 "src-generated/ugbc.tab.c"
    break;

  case 283: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 1037 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 5196 "src-generated/ugbc.tab.c"
    break;

  case 284: /* screen_definition_expression: ROWS expr  */
#line 1042 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 5204 "src-generated/ugbc.tab.c"
    break;

  case 285: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 1045 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 5212 "src-generated/ugbc.tab.c"
    break;

  case 286: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 1048 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 5220 "src-generated/ugbc.tab.c"
    break;

  case 290: /* var_definition_simple: Identifier ON Identifier  */
#line 1057 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 5228 "src-generated/ugbc.tab.c"
    break;

  case 291: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 1060 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 5236 "src-generated/ugbc.tab.c"
    break;

  case 292: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 1063 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 5244 "src-generated/ugbc.tab.c"
    break;

  case 293: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 1066 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 5254 "src-generated/ugbc.tab.c"
    break;

  case 294: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 1071 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 5264 "src-generated/ugbc.tab.c"
    break;

  case 295: /* goto_definition: Identifier  */
#line 1078 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 5272 "src-generated/ugbc.tab.c"
    break;

  case 296: /* goto_definition: Integer  */
#line 1081 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 5280 "src-generated/ugbc.tab.c"
    break;

  case 297: /* gosub_definition: Identifier  */
#line 1087 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 5288 "src-generated/ugbc.tab.c"
    break;

  case 298: /* gosub_definition: Integer  */
#line 1090 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 5296 "src-generated/ugbc.tab.c"
    break;

  case 300: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 1099 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 5304 "src-generated/ugbc.tab.c"
    break;

  case 301: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 1105 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 5312 "src-generated/ugbc.tab.c"
    break;

  case 304: /* ink_definition: expr  */
#line 1114 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 5320 "src-generated/ugbc.tab.c"
    break;

  case 305: /* on_goto_definition: Identifier  */
#line 1119 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 5329 "src-generated/ugbc.tab.c"
    break;

  case 306: /* $@4: %empty  */
#line 1123 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 5337 "src-generated/ugbc.tab.c"
    break;

  case 308: /* on_gosub_definition: Identifier  */
#line 1128 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 5346 "src-generated/ugbc.tab.c"
    break;

  case 309: /* $@5: %empty  */
#line 1132 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 5354 "src-generated/ugbc.tab.c"
    break;

  case 311: /* on_proc_definition: Identifier  */
#line 1137 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 5363 "src-generated/ugbc.tab.c"
    break;

  case 312: /* $@6: %empty  */
#line 1141 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 5371 "src-generated/ugbc.tab.c"
    break;

  case 314: /* $@7: %empty  */
#line 1146 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 5379 "src-generated/ugbc.tab.c"
    break;

  case 316: /* $@8: %empty  */
#line 1149 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 5387 "src-generated/ugbc.tab.c"
    break;

  case 318: /* $@9: %empty  */
#line 1152 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 5395 "src-generated/ugbc.tab.c"
    break;

  case 320: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1157 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 5403 "src-generated/ugbc.tab.c"
    break;

  case 321: /* every_definition: ON  */
#line 1160 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 5411 "src-generated/ugbc.tab.c"
    break;

  case 322: /* every_definition: OFF  */
#line 1163 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 5419 "src-generated/ugbc.tab.c"
    break;

  case 323: /* add_definition: Identifier COMMA expr  */
#line 1168 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 5427 "src-generated/ugbc.tab.c"
    break;

  case 324: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1171 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5435 "src-generated/ugbc.tab.c"
    break;

  case 325: /* dimensions: Integer  */
#line 1177 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5444 "src-generated/ugbc.tab.c"
    break;

  case 326: /* dimensions: Integer COMMA dimensions  */
#line 1181 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5453 "src-generated/ugbc.tab.c"
    break;

  case 327: /* datatype: BYTE  */
#line 1188 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 5461 "src-generated/ugbc.tab.c"
    break;

  case 328: /* datatype: SIGNED BYTE  */
#line 1191 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 5469 "src-generated/ugbc.tab.c"
    break;

  case 329: /* datatype: WORD  */
#line 1194 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 5477 "src-generated/ugbc.tab.c"
    break;

  case 330: /* datatype: SIGNED WORD  */
#line 1197 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 5485 "src-generated/ugbc.tab.c"
    break;

  case 331: /* datatype: DWORD  */
#line 1200 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 5493 "src-generated/ugbc.tab.c"
    break;

  case 332: /* datatype: SIGNED DWORD  */
#line 1203 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 5501 "src-generated/ugbc.tab.c"
    break;

  case 333: /* datatype: ADDRESS  */
#line 1206 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 5509 "src-generated/ugbc.tab.c"
    break;

  case 334: /* datatype: POSITION  */
#line 1209 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 5517 "src-generated/ugbc.tab.c"
    break;

  case 335: /* datatype: COLOR  */
#line 1212 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 5525 "src-generated/ugbc.tab.c"
    break;

  case 336: /* datatype: STRING  */
#line 1215 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 5533 "src-generated/ugbc.tab.c"
    break;

  case 337: /* $@10: %empty  */
#line 1220 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5542 "src-generated/ugbc.tab.c"
    break;

  case 338: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1223 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 5552 "src-generated/ugbc.tab.c"
    break;

  case 339: /* $@11: %empty  */
#line 1228 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5561 "src-generated/ugbc.tab.c"
    break;

  case 340: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1231 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 5571 "src-generated/ugbc.tab.c"
    break;

  case 341: /* $@12: %empty  */
#line 1236 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5580 "src-generated/ugbc.tab.c"
    break;

  case 342: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1239 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 5590 "src-generated/ugbc.tab.c"
    break;

  case 345: /* indexes: expr  */
#line 1252 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5599 "src-generated/ugbc.tab.c"
    break;

  case 346: /* indexes: expr COMMA indexes  */
#line 1256 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5608 "src-generated/ugbc.tab.c"
    break;

  case 347: /* parameters: Identifier  */
#line 1263 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5618 "src-generated/ugbc.tab.c"
    break;

  case 348: /* parameters: Identifier DOLLAR  */
#line 1268 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5628 "src-generated/ugbc.tab.c"
    break;

  case 349: /* parameters: Identifier AS datatype  */
#line 1273 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5638 "src-generated/ugbc.tab.c"
    break;

  case 350: /* parameters: Identifier COMMA parameters  */
#line 1278 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5648 "src-generated/ugbc.tab.c"
    break;

  case 351: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1283 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5658 "src-generated/ugbc.tab.c"
    break;

  case 352: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1288 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5668 "src-generated/ugbc.tab.c"
    break;

  case 353: /* parameters_expr: Identifier  */
#line 1296 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5678 "src-generated/ugbc.tab.c"
    break;

  case 354: /* parameters_expr: Identifier DOLLAR  */
#line 1301 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5688 "src-generated/ugbc.tab.c"
    break;

  case 355: /* parameters_expr: Identifier AS datatype  */
#line 1306 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5698 "src-generated/ugbc.tab.c"
    break;

  case 356: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1311 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5708 "src-generated/ugbc.tab.c"
    break;

  case 357: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1316 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5718 "src-generated/ugbc.tab.c"
    break;

  case 358: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1321 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5728 "src-generated/ugbc.tab.c"
    break;

  case 359: /* parameters_expr: String  */
#line 1326 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5737 "src-generated/ugbc.tab.c"
    break;

  case 360: /* parameters_expr: String COMMA parameters_expr  */
#line 1330 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5746 "src-generated/ugbc.tab.c"
    break;

  case 361: /* values: expr  */
#line 1337 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5755 "src-generated/ugbc.tab.c"
    break;

  case 362: /* values: expr COMMA values  */
#line 1341 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5764 "src-generated/ugbc.tab.c"
    break;

  case 363: /* print_definition: expr  */
#line 1348 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5772 "src-generated/ugbc.tab.c"
    break;

  case 364: /* print_definition: expr COMMA  */
#line 1351 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5781 "src-generated/ugbc.tab.c"
    break;

  case 365: /* print_definition: expr SEMICOLON  */
#line 1355 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5789 "src-generated/ugbc.tab.c"
    break;

  case 366: /* $@13: %empty  */
#line 1358 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5798 "src-generated/ugbc.tab.c"
    break;

  case 368: /* $@14: %empty  */
#line 1362 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5806 "src-generated/ugbc.tab.c"
    break;

  case 370: /* writing_mode_definition: REPLACE  */
#line 1368 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5815 "src-generated/ugbc.tab.c"
    break;

  case 371: /* writing_mode_definition: OR  */
#line 1372 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5824 "src-generated/ugbc.tab.c"
    break;

  case 372: /* writing_mode_definition: XOR  */
#line 1376 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5833 "src-generated/ugbc.tab.c"
    break;

  case 373: /* writing_mode_definition: AND  */
#line 1380 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5842 "src-generated/ugbc.tab.c"
    break;

  case 374: /* writing_mode_definition: IGNORE  */
#line 1384 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5851 "src-generated/ugbc.tab.c"
    break;

  case 375: /* writing_part_definition: NORMAL  */
#line 1391 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5860 "src-generated/ugbc.tab.c"
    break;

  case 376: /* writing_part_definition: PAPER  */
#line 1395 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5869 "src-generated/ugbc.tab.c"
    break;

  case 377: /* writing_part_definition: PAPER ONLY  */
#line 1399 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5878 "src-generated/ugbc.tab.c"
    break;

  case 378: /* writing_part_definition: PEN  */
#line 1403 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5887 "src-generated/ugbc.tab.c"
    break;

  case 379: /* writing_part_definition: PEN ONLY  */
#line 1407 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5896 "src-generated/ugbc.tab.c"
    break;

  case 380: /* writing_definition: writing_mode_definition COMMA writing_part_definition  */
#line 1414 "src/ugbc.y"
                                                          {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5904 "src-generated/ugbc.tab.c"
    break;

  case 381: /* locate_definition: COMMA expr  */
#line 1420 "src/ugbc.y"
                {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 5912 "src-generated/ugbc.tab.c"
    break;

  case 382: /* locate_definition: expr COMMA  */
#line 1423 "src/ugbc.y"
                 {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 5920 "src-generated/ugbc.tab.c"
    break;

  case 383: /* locate_definition: expr COMMA expr  */
#line 1426 "src/ugbc.y"
                      {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5928 "src-generated/ugbc.tab.c"
    break;

  case 384: /* cmove_definition: COMMA expr  */
#line 1432 "src/ugbc.y"
                {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 5936 "src-generated/ugbc.tab.c"
    break;

  case 385: /* cmove_definition: expr COMMA  */
#line 1435 "src/ugbc.y"
                 {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 5944 "src-generated/ugbc.tab.c"
    break;

  case 386: /* cmove_definition: expr COMMA expr  */
#line 1438 "src/ugbc.y"
                      {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5952 "src-generated/ugbc.tab.c"
    break;

  case 387: /* hscroll_definition: LEFT  */
#line 1444 "src/ugbc.y"
         {
        text_hscroll_line( _environment, -1 );
    }
#line 5960 "src-generated/ugbc.tab.c"
    break;

  case 388: /* hscroll_definition: SCREEN LEFT  */
#line 1447 "src/ugbc.y"
                  {
        text_hscroll_screen( _environment, -1 );
    }
#line 5968 "src-generated/ugbc.tab.c"
    break;

  case 389: /* hscroll_definition: RIGHT  */
#line 1450 "src/ugbc.y"
            {
        text_hscroll_line( _environment, 1 );
    }
#line 5976 "src-generated/ugbc.tab.c"
    break;

  case 390: /* hscroll_definition: SCREEN RIGHT  */
#line 1453 "src/ugbc.y"
                   {
        text_hscroll_screen( _environment, 1 );
    }
#line 5984 "src-generated/ugbc.tab.c"
    break;

  case 391: /* vscroll_definition: SCREEN UP  */
#line 1459 "src/ugbc.y"
                {
        text_vscroll_screen( _environment, -1 );
    }
#line 5992 "src-generated/ugbc.tab.c"
    break;

  case 392: /* vscroll_definition: SCREEN DOWN  */
#line 1462 "src/ugbc.y"
                  {
        text_vscroll_screen( _environment, 1 );
    }
#line 6000 "src-generated/ugbc.tab.c"
    break;

  case 408: /* statement: TEXTADDRESS ASSIGN expr  */
#line 1483 "src/ugbc.y"
                            {
      variable_move( _environment, (yyvsp[0].string), "ADDRESS" );
  }
#line 6008 "src-generated/ugbc.tab.c"
    break;

  case 413: /* statement: MEMORIZE  */
#line 1490 "src/ugbc.y"
             {
      text_memorize( _environment );
  }
#line 6016 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: REMEMBER  */
#line 1493 "src/ugbc.y"
             {
      text_remember( _environment );
  }
#line 6024 "src-generated/ugbc.tab.c"
    break;

  case 418: /* statement: CUP  */
#line 1499 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 6032 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: CDOWN  */
#line 1502 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 6040 "src-generated/ugbc.tab.c"
    break;

  case 420: /* statement: CLEFT  */
#line 1505 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 6048 "src-generated/ugbc.tab.c"
    break;

  case 421: /* statement: CRIGHT  */
#line 1508 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 6056 "src-generated/ugbc.tab.c"
    break;

  case 422: /* statement: CLINE  */
#line 1511 "src/ugbc.y"
          {
      text_cline( _environment, NULL );
  }
#line 6064 "src-generated/ugbc.tab.c"
    break;

  case 423: /* statement: CLINE expr  */
#line 1514 "src/ugbc.y"
               {
      text_cline( _environment, (yyvsp[0].string) );
  }
#line 6072 "src-generated/ugbc.tab.c"
    break;

  case 424: /* statement: SET TAB expr  */
#line 1517 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 6080 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: CENTER expr  */
#line 1520 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 6088 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: CENTRE expr  */
#line 1523 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 6096 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: CLS  */
#line 1526 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 6104 "src-generated/ugbc.tab.c"
    break;

  case 428: /* statement: HOME  */
#line 1529 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 6112 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: INC Identifier  */
#line 1532 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 6120 "src-generated/ugbc.tab.c"
    break;

  case 430: /* statement: DEC Identifier  */
#line 1535 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 6128 "src-generated/ugbc.tab.c"
    break;

  case 431: /* statement: RANDOMIZE  */
#line 1538 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 6136 "src-generated/ugbc.tab.c"
    break;

  case 432: /* statement: RANDOMIZE expr  */
#line 1541 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 6144 "src-generated/ugbc.tab.c"
    break;

  case 433: /* statement: IF expr THEN  */
#line 1544 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 6152 "src-generated/ugbc.tab.c"
    break;

  case 434: /* statement: ELSE  */
#line 1547 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 6160 "src-generated/ugbc.tab.c"
    break;

  case 435: /* statement: ELSE IF expr THEN  */
#line 1550 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 6168 "src-generated/ugbc.tab.c"
    break;

  case 436: /* statement: ENDIF  */
#line 1553 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 6176 "src-generated/ugbc.tab.c"
    break;

  case 437: /* statement: DO  */
#line 1556 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 6184 "src-generated/ugbc.tab.c"
    break;

  case 438: /* statement: LOOP  */
#line 1559 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 6192 "src-generated/ugbc.tab.c"
    break;

  case 439: /* $@15: %empty  */
#line 1562 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 6200 "src-generated/ugbc.tab.c"
    break;

  case 440: /* statement: WHILE $@15 expr  */
#line 1564 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 6208 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: WEND  */
#line 1567 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 6216 "src-generated/ugbc.tab.c"
    break;

  case 442: /* statement: REPEAT  */
#line 1570 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 6224 "src-generated/ugbc.tab.c"
    break;

  case 443: /* statement: UNTIL expr  */
#line 1573 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 6232 "src-generated/ugbc.tab.c"
    break;

  case 444: /* statement: EXIT  */
#line 1576 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 6240 "src-generated/ugbc.tab.c"
    break;

  case 445: /* statement: EXIT PROC  */
#line 1579 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 6248 "src-generated/ugbc.tab.c"
    break;

  case 446: /* statement: POP PROC  */
#line 1582 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 6256 "src-generated/ugbc.tab.c"
    break;

  case 447: /* statement: EXIT IF expr  */
#line 1585 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 6264 "src-generated/ugbc.tab.c"
    break;

  case 448: /* statement: EXIT Integer  */
#line 1588 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 6272 "src-generated/ugbc.tab.c"
    break;

  case 449: /* statement: EXIT direct_integer  */
#line 1591 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 6280 "src-generated/ugbc.tab.c"
    break;

  case 450: /* statement: EXIT IF expr COMMA Integer  */
#line 1594 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 6288 "src-generated/ugbc.tab.c"
    break;

  case 451: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1597 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 6296 "src-generated/ugbc.tab.c"
    break;

  case 452: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1600 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 6304 "src-generated/ugbc.tab.c"
    break;

  case 453: /* statement: NEXT  */
#line 1603 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 6312 "src-generated/ugbc.tab.c"
    break;

  case 454: /* statement: PROCEDURE Identifier  */
#line 1606 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 6321 "src-generated/ugbc.tab.c"
    break;

  case 455: /* $@16: %empty  */
#line 1610 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6329 "src-generated/ugbc.tab.c"
    break;

  case 456: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1612 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6337 "src-generated/ugbc.tab.c"
    break;

  case 457: /* statement: SHARED parameters_expr  */
#line 1615 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 6345 "src-generated/ugbc.tab.c"
    break;

  case 458: /* statement: GLOBAL parameters_expr  */
#line 1618 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 6353 "src-generated/ugbc.tab.c"
    break;

  case 459: /* statement: END PROC  */
#line 1621 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 6361 "src-generated/ugbc.tab.c"
    break;

  case 460: /* statement: END PROC OSP expr CSP  */
#line 1624 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6369 "src-generated/ugbc.tab.c"
    break;

  case 461: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1627 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 6377 "src-generated/ugbc.tab.c"
    break;

  case 462: /* statement: Identifier " "  */
#line 1630 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6386 "src-generated/ugbc.tab.c"
    break;

  case 463: /* statement: PROC Identifier  */
#line 1634 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6395 "src-generated/ugbc.tab.c"
    break;

  case 464: /* statement: CALL Identifier  */
#line 1638 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6404 "src-generated/ugbc.tab.c"
    break;

  case 465: /* $@17: %empty  */
#line 1642 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6412 "src-generated/ugbc.tab.c"
    break;

  case 466: /* statement: Identifier OSP $@17 values CSP  */
#line 1644 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6420 "src-generated/ugbc.tab.c"
    break;

  case 467: /* $@18: %empty  */
#line 1647 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6428 "src-generated/ugbc.tab.c"
    break;

  case 468: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1649 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6436 "src-generated/ugbc.tab.c"
    break;

  case 469: /* $@19: %empty  */
#line 1652 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6444 "src-generated/ugbc.tab.c"
    break;

  case 470: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1654 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6452 "src-generated/ugbc.tab.c"
    break;

  case 471: /* statement: PEN expr  */
#line 1657 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 6460 "src-generated/ugbc.tab.c"
    break;

  case 472: /* statement: PAPER expr  */
#line 1660 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 6468 "src-generated/ugbc.tab.c"
    break;

  case 473: /* statement: INVERSE ON  */
#line 1663 "src/ugbc.y"
               {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 6476 "src-generated/ugbc.tab.c"
    break;

  case 474: /* statement: INVERSE OFF  */
#line 1666 "src/ugbc.y"
                {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 6484 "src-generated/ugbc.tab.c"
    break;

  case 476: /* statement: Identifier COLON  */
#line 1670 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 6492 "src-generated/ugbc.tab.c"
    break;

  case 477: /* statement: BEG GAMELOOP  */
#line 1673 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 6500 "src-generated/ugbc.tab.c"
    break;

  case 478: /* statement: END GAMELOOP  */
#line 1676 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 6508 "src-generated/ugbc.tab.c"
    break;

  case 479: /* statement: GRAPHIC  */
#line 1679 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 6516 "src-generated/ugbc.tab.c"
    break;

  case 480: /* statement: HALT  */
#line 1682 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 6524 "src-generated/ugbc.tab.c"
    break;

  case 481: /* statement: END  */
#line 1685 "src/ugbc.y"
        {
      end( _environment );
  }
#line 6532 "src-generated/ugbc.tab.c"
    break;

  case 486: /* statement: RETURN  */
#line 1692 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 6540 "src-generated/ugbc.tab.c"
    break;

  case 487: /* statement: RETURN expr  */
#line 1695 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 6548 "src-generated/ugbc.tab.c"
    break;

  case 488: /* statement: POP  */
#line 1698 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 6556 "src-generated/ugbc.tab.c"
    break;

  case 489: /* statement: DONE  */
#line 1701 "src/ugbc.y"
          {
      return 0;
  }
#line 6564 "src-generated/ugbc.tab.c"
    break;

  case 490: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1704 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6572 "src-generated/ugbc.tab.c"
    break;

  case 491: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1707 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6580 "src-generated/ugbc.tab.c"
    break;

  case 492: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1710 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 6588 "src-generated/ugbc.tab.c"
    break;

  case 493: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1713 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6596 "src-generated/ugbc.tab.c"
    break;

  case 495: /* statement: Identifier ASSIGN expr  */
#line 1717 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 6610 "src-generated/ugbc.tab.c"
    break;

  case 496: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1726 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 6624 "src-generated/ugbc.tab.c"
    break;

  case 497: /* $@20: %empty  */
#line 1735 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6633 "src-generated/ugbc.tab.c"
    break;

  case 498: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1739 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 6646 "src-generated/ugbc.tab.c"
    break;

  case 499: /* $@21: %empty  */
#line 1747 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6655 "src-generated/ugbc.tab.c"
    break;

  case 500: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1750 "src/ugbc.y"
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
#line 6674 "src-generated/ugbc.tab.c"
    break;

  case 501: /* $@22: %empty  */
#line 1764 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6683 "src-generated/ugbc.tab.c"
    break;

  case 502: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1767 "src/ugbc.y"
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
#line 6702 "src-generated/ugbc.tab.c"
    break;

  case 503: /* statement: DEBUG expr  */
#line 1781 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 6710 "src-generated/ugbc.tab.c"
    break;

  case 506: /* statements_no_linenumbers: statement  */
#line 1789 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 6716 "src-generated/ugbc.tab.c"
    break;

  case 507: /* $@23: %empty  */
#line 1790 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 6722 "src-generated/ugbc.tab.c"
    break;

  case 509: /* $@24: %empty  */
#line 1794 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 6730 "src-generated/ugbc.tab.c"
    break;

  case 510: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1796 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 6738 "src-generated/ugbc.tab.c"
    break;

  case 511: /* $@25: %empty  */
#line 1801 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 6746 "src-generated/ugbc.tab.c"
    break;

  case 517: /* $@26: %empty  */
#line 1811 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 6752 "src-generated/ugbc.tab.c"
    break;


#line 6756 "src-generated/ugbc.tab.c"

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

#line 1813 "src/ugbc.y"


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

