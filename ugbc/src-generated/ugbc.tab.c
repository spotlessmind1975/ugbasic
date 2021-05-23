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
  YYSYMBOL_SCANCODE = 202,                 /* SCANCODE  */
  YYSYMBOL_BLACK = 203,                    /* BLACK  */
  YYSYMBOL_WHITE = 204,                    /* WHITE  */
  YYSYMBOL_RED = 205,                      /* RED  */
  YYSYMBOL_CYAN = 206,                     /* CYAN  */
  YYSYMBOL_VIOLET = 207,                   /* VIOLET  */
  YYSYMBOL_GREEN = 208,                    /* GREEN  */
  YYSYMBOL_BLUE = 209,                     /* BLUE  */
  YYSYMBOL_YELLOW = 210,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 211,                   /* ORANGE  */
  YYSYMBOL_BROWN = 212,                    /* BROWN  */
  YYSYMBOL_LIGHT = 213,                    /* LIGHT  */
  YYSYMBOL_DARK = 214,                     /* DARK  */
  YYSYMBOL_GREY = 215,                     /* GREY  */
  YYSYMBOL_GRAY = 216,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 217,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 218,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 219,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 220,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 221,                /* TURQUOISE  */
  YYSYMBOL_TAN = 222,                      /* TAN  */
  YYSYMBOL_PINK = 223,                     /* PINK  */
  YYSYMBOL_PEACH = 224,                    /* PEACH  */
  YYSYMBOL_OLIVE = 225,                    /* OLIVE  */
  YYSYMBOL_Identifier = 226,               /* Identifier  */
  YYSYMBOL_String = 227,                   /* String  */
  YYSYMBOL_Integer = 228,                  /* Integer  */
  YYSYMBOL_229_ = 229,                     /* " "  */
  YYSYMBOL_YYACCEPT = 230,                 /* $accept  */
  YYSYMBOL_expr = 231,                     /* expr  */
  YYSYMBOL_expr_math = 232,                /* expr_math  */
  YYSYMBOL_term = 233,                     /* term  */
  YYSYMBOL_modula = 234,                   /* modula  */
  YYSYMBOL_factor = 235,                   /* factor  */
  YYSYMBOL_direct_integer = 236,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 237, /* random_definition_simple  */
  YYSYMBOL_random_definition = 238,        /* random_definition  */
  YYSYMBOL_color_enumeration = 239,        /* color_enumeration  */
  YYSYMBOL_exponential = 240,              /* exponential  */
  YYSYMBOL_241_1 = 241,                    /* $@1  */
  YYSYMBOL_242_2 = 242,                    /* $@2  */
  YYSYMBOL_243_3 = 243,                    /* $@3  */
  YYSYMBOL_position = 244,                 /* position  */
  YYSYMBOL_bank_definition_simple = 245,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 246, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 247,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 248, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 249, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 250,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 251, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 252, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 253,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 254,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 255, /* color_definition_expression  */
  YYSYMBOL_color_definition = 256,         /* color_definition  */
  YYSYMBOL_milliseconds = 257,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 258,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 259, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 260,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 261, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 262, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 263,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 264, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 265, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 266,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 267, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 268, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 269,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 270,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 271, /* text_definition_expression  */
  YYSYMBOL_text_definition = 272,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 273,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 274, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 275,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 276, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 277, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 278,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 279, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 280, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 281,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 282,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 283,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 284,         /* gosub_definition  */
  YYSYMBOL_var_definition = 285,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 286,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 287, /* point_definition_expression  */
  YYSYMBOL_point_definition = 288,         /* point_definition  */
  YYSYMBOL_ink_definition = 289,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 290,       /* on_goto_definition  */
  YYSYMBOL_291_4 = 291,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 292,      /* on_gosub_definition  */
  YYSYMBOL_293_5 = 293,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 294,       /* on_proc_definition  */
  YYSYMBOL_295_6 = 295,                    /* $@6  */
  YYSYMBOL_on_definition = 296,            /* on_definition  */
  YYSYMBOL_297_7 = 297,                    /* $@7  */
  YYSYMBOL_298_8 = 298,                    /* $@8  */
  YYSYMBOL_299_9 = 299,                    /* $@9  */
  YYSYMBOL_every_definition = 300,         /* every_definition  */
  YYSYMBOL_add_definition = 301,           /* add_definition  */
  YYSYMBOL_dimensions = 302,               /* dimensions  */
  YYSYMBOL_datatype = 303,                 /* datatype  */
  YYSYMBOL_dim_definition = 304,           /* dim_definition  */
  YYSYMBOL_305_10 = 305,                   /* $@10  */
  YYSYMBOL_306_11 = 306,                   /* $@11  */
  YYSYMBOL_307_12 = 307,                   /* $@12  */
  YYSYMBOL_dim_definitions = 308,          /* dim_definitions  */
  YYSYMBOL_indexes = 309,                  /* indexes  */
  YYSYMBOL_parameters = 310,               /* parameters  */
  YYSYMBOL_parameters_expr = 311,          /* parameters_expr  */
  YYSYMBOL_values = 312,                   /* values  */
  YYSYMBOL_print_definition = 313,         /* print_definition  */
  YYSYMBOL_314_13 = 314,                   /* $@13  */
  YYSYMBOL_315_14 = 315,                   /* $@14  */
  YYSYMBOL_writing_mode_definition = 316,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 317,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 318,       /* writing_definition  */
  YYSYMBOL_locate_definition = 319,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 320,         /* cmove_definition  */
  YYSYMBOL_hscroll_definition = 321,       /* hscroll_definition  */
  YYSYMBOL_vscroll_definition = 322,       /* vscroll_definition  */
  YYSYMBOL_statement = 323,                /* statement  */
  YYSYMBOL_324_15 = 324,                   /* $@15  */
  YYSYMBOL_325_16 = 325,                   /* $@16  */
  YYSYMBOL_326_17 = 326,                   /* $@17  */
  YYSYMBOL_327_18 = 327,                   /* $@18  */
  YYSYMBOL_328_19 = 328,                   /* $@19  */
  YYSYMBOL_329_20 = 329,                   /* $@20  */
  YYSYMBOL_330_21 = 330,                   /* $@21  */
  YYSYMBOL_331_22 = 331,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 332, /* statements_no_linenumbers  */
  YYSYMBOL_333_23 = 333,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 334, /* statements_with_linenumbers  */
  YYSYMBOL_335_24 = 335,                   /* $@24  */
  YYSYMBOL_statements_complex = 336,       /* statements_complex  */
  YYSYMBOL_337_25 = 337,                   /* $@25  */
  YYSYMBOL_program = 338,                  /* program  */
  YYSYMBOL_339_26 = 339                    /* $@26  */
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
#define YYLAST   3954

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  230
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  110
/* YYNRULES -- Number of rules.  */
#define YYNRULES  519
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1014

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   484


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
     225,   226,   227,   228,   229
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
     646,   646,   649,   652,   655,   658,   661,   664,   668,   671,
     674,   677,   681,   684,   687,   690,   694,   697,   700,   703,
     709,   712,   715,   718,   721,   726,   727,   730,   733,   738,
     741,   746,   747,   750,   753,   758,   761,   766,   767,   770,
     773,   776,   781,   784,   787,   792,   793,   796,   797,   798,
     801,   804,   807,   812,   815,   818,   824,   825,   828,   831,
     834,   837,   840,   843,   846,   849,   852,   855,   858,   861,
     864,   867,   870,   875,   878,   881,   884,   887,   890,   893,
     896,   899,   902,   905,   908,   911,   914,   917,   922,   923,
     926,   929,   932,   935,   938,   944,   947,   953,   954,   957,
     962,   967,   968,   971,   974,   979,   982,   987,   988,   991,
     996,  1001,  1002,  1005,  1008,  1011,  1016,  1019,  1025,  1026,
    1029,  1032,  1035,  1038,  1041,  1046,  1049,  1052,  1057,  1058,
    1060,  1061,  1064,  1067,  1070,  1075,  1082,  1085,  1091,  1094,
    1100,  1103,  1109,  1114,  1115,  1118,  1123,  1127,  1127,  1132,
    1136,  1136,  1141,  1145,  1145,  1150,  1150,  1153,  1153,  1156,
    1156,  1161,  1164,  1167,  1172,  1175,  1181,  1185,  1192,  1195,
    1198,  1201,  1204,  1207,  1210,  1213,  1216,  1219,  1224,  1224,
    1232,  1232,  1240,  1240,  1251,  1252,  1256,  1260,  1267,  1272,
    1277,  1282,  1287,  1292,  1300,  1305,  1310,  1315,  1320,  1325,
    1330,  1334,  1341,  1345,  1352,  1355,  1359,  1362,  1362,  1366,
    1366,  1372,  1376,  1380,  1384,  1388,  1395,  1399,  1403,  1407,
    1411,  1418,  1424,  1427,  1430,  1436,  1439,  1442,  1448,  1451,
    1454,  1457,  1463,  1466,  1472,  1473,  1474,  1475,  1476,  1477,
    1478,  1479,  1480,  1481,  1482,  1483,  1484,  1485,  1486,  1487,
    1490,  1491,  1492,  1493,  1494,  1497,  1500,  1501,  1502,  1503,
    1506,  1509,  1512,  1515,  1518,  1521,  1524,  1527,  1530,  1533,
    1536,  1539,  1542,  1545,  1548,  1551,  1554,  1557,  1560,  1563,
    1566,  1566,  1571,  1574,  1577,  1580,  1583,  1586,  1589,  1592,
    1595,  1598,  1601,  1604,  1607,  1610,  1614,  1614,  1619,  1622,
    1625,  1628,  1631,  1634,  1638,  1642,  1646,  1646,  1651,  1651,
    1656,  1656,  1661,  1664,  1667,  1670,  1673,  1674,  1677,  1680,
    1683,  1686,  1689,  1692,  1693,  1694,  1695,  1696,  1699,  1702,
    1705,  1708,  1711,  1714,  1717,  1720,  1721,  1730,  1739,  1739,
    1751,  1751,  1768,  1768,  1785,  1788,  1789,  1793,  1794,  1794,
    1798,  1798,  1805,  1805,  1808,  1809,  1810,  1811,  1815,  1815
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
  "JRIGHT", "JFIRE", "INKEY", "SCANCODE", "BLACK", "WHITE", "RED", "CYAN",
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
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484
};
#endif

#define YYPACT_NINF (-860)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-499)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -860,    53,  1017,  -860,  -860,  -100,   -64,  2898,   -18,  -860,
      46,  2471,    64,    -4,  2471,  -860,    67,   238,  2898,   -60,
     -21,  -860,  -860,  -860,  2057,   159,    44,  2898,  2898,   101,
     -24,  -860,   161,   192,  2898,  2898,  -860,   197,   214,    71,
    2898,   100,   193,  -860,   -32,  -860,  2898,    47,  2264,   221,
      52,  2898,    76,    79,    91,    97,  -152,  -152,  2898,  2898,
      66,    62,  1421,  -860,  -860,  1643,  2898,  2898,   115,  -860,
    -860,  -860,  -860,  2898,  -860,  -860,    12,   248,   313,    10,
    -860,   343,   346,   347,  -860,  -860,  -860,   125,   332,  1850,
    -860,  -860,   316,   317,   318,   124,  -860,  -860,    15,  -860,
    -860,   319,   320,  2898,  -860,  -860,   321,   322,   325,   344,
     345,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   359,   362,  -860,  -860,   363,   126,   -23,    25,   361,
     364,   365,   388,   389,   390,   391,  -860,  -860,  -860,    -1,
     374,  3519,  -860,   375,   376,   377,   378,   379,   380,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,   211,  -860,
    -860,   110,  -124,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,   212,    18,  -860,  -860,   272,    85,   287,   269,
      19,  -860,  -860,  -860,  2471,   394,  -860,  -860,  -860,  2471,
    2471,  2471,  -860,  -860,  -860,   195,    61,    65,  -860,  -860,
    -860,   -16,   338,    -3,    -2,     3,     8,   397,  -860,  -860,
    -860,   234,   240,  -860,  -860,  -860,  2471,  -860,  -860,   393,
    -860,  -860,  -860,  -860,  -860,  2471,   381,   382,  -860,  -860,
    -860,    11,  -860,   134,  -860,  -860,  -860,  -860,  -860,  2898,
    2691,  -860,  -860,   420,  -860,  -860,  -860,  2471,  -860,  -860,
    -860,  2471,   395,  -860,  -860,  -860,   360,  -860,  -860,  -860,
     279,  2898,  2898,  -860,  -860,  2471,  -860,  -860,  -860,   396,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  2898,  2898,
    -860,  -860,  -860,  -860,   416,  -860,  -860,   281,  -860,  2898,
     428,  -860,  -860,  -860,    51,   429,  -860,   289,   290,   291,
      98,   431,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,   436,  -860,  2898,   437,  -860,  2898,   438,
    -860,  -860,  -860,  2898,  -860,   154,  -860,  -860,  -860,   216,
    -860,  2898,  -860,  -860,  2898,   433,  -860,  -860,   409,    54,
    1238,  -860,  1017,  1017,  -860,   410,   411,   412,   413,   414,
     415,   172,   418,  2898,  2471,  2471,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,   417,  -860,  -860,  2898,  2898,
    -860,  2898,  2898,  2898,  2898,  2898,  2898,  2898,  2898,  2898,
    2898,  2898,  2898,  2898,  2898,  2898,  2898,  2898,  3105,   421,
     223,  -860,  -860,   422,  -860,  -860,   423,   424,  -860,  -860,
    -860,  -860,  -860,  2898,  -860,  2898,  1850,   425,   439,  2898,
    2898,  2898,  2898,  2898,  2898,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,   427,  -860,   430,   231,   260,  3105,  3105,
    3105,  3105,  3105,  3105,  3105,  3105,  3105,  3105,  3105,  3105,
    3105,   -50,  3312,  3726,   434,   440,  2471,  -860,  -860,   398,
     399,   400,   401,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  2471,   441,  -860,  -860,  -860,   406,   338,
     442,   338,   443,   338,   450,   338,   451,   338,  -860,  2898,
     444,  -860,  -860,   261,   276,    30,    40,  -860,  -860,  -860,
     445,   338,   447,  -860,  -860,   278,   280,   142,   187,  -860,
    -860,   448,  -860,  -860,  2471,  -860,  -860,  2471,  2471,  -860,
    -860,  -860,   446,   254,  -860,   459,  2898,  -860,  -860,  -860,
    -860,  2471,  -860,  2898,   475,   478,  -860,  -860,  2471,   432,
     480,  2898,   383,   481,  2898,  -860,  -860,  -860,  -860,  -860,
    -860,   178,  -860,  -860,   452,   471,    76,  -860,   342,  -860,
    -152,   487,    54,  -152,   -40,  -860,  2898,  -860,  2898,  -860,
    -860,  -860,  -860,  -860,  -860,  1017,  -860,  2898,   457,  2898,
    2898,   464,     9,  -860,  1238,  -860,  -860,  2898,   275,   282,
     283,   292,   294,   465,   467,   468,  -860,   469,   476,   479,
     486,   490,  2898,   510,   512,   516,   519,   491,   492,   493,
     494,   527,   496,   497,   498,   499,   500,   533,   534,   503,
     504,   505,    39,   324,   506,  2898,  2898,  2898,   507,   112,
     129,  2898,  3105,   508,   509,   513,   514,   515,   517,   520,
    2898,  2898,  2898,  2898,   287,   287,   334,   334,   334,   334,
     334,   334,   334,   334,   269,    19,    19,   367,  3726,  3726,
    -860,  -860,   329,   331,  -860,  -860,  2898,   338,  2898,   338,
     528,   530,  2471,    33,  -860,   338,  -860,   338,  -860,   338,
    -860,   338,   137,  -860,  2898,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  2898,  -860,   338,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,   338,  -860,  -860,  -860,  -860,  -860,
    -860,   339,   340,   341,   358,   551,  2898,   561,   523,   525,
     426,  2898,  2898,   565,   566,  -860,   -52,   511,   366,  2898,
     567,  -860,  -860,  -860,   537,   369,   541,  -860,  2898,   368,
    2898,  -860,  -152,   573,  -860,   419,   435,  -860,  -860,  -860,
    -860,  -860,  -860,  2898,   574,   449,   575,   544,  2898,  -860,
     579,  -860,  -860,  -860,  -860,  -860,   370,   371,   372,  -860,
    -860,  -860,  -860,  -860,   550,  2898,  2898,  2898,  2898,  -860,
    -860,  -860,  -860,  2898,  -860,  -860,  -860,  -860,  -860,  2898,
    2898,  -860,  -860,  -860,  3726,   552,  -860,   554,   583,   588,
    -860,  2898,  -860,  2898,   595,   580,  -860,  -860,  -860,  -860,
    -860,  -860,  2898,   453,   568,  -860,  -860,  3726,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,   385,   386,  -860,  -860,
    -860,  -860,  -860,  -860,   582,  -860,   584,  -860,   392,    56,
    -860,   599,  -860,   606,   609,  -860,   611,  -860,   613,  -860,
     608,  2471,   615,  2898,  2898,   338,  -860,   585,   589,  2898,
     338,  -860,  -860,  2898,  -860,   149,  2898,   369,   620,   590,
     369,   482,   121,   483,   485,  -860,  -152,  -860,  -860,   591,
    2898,  -860,  2898,   618,   593,  2898,  -860,  -860,  -860,  -860,
     594,   597,   158,   167,   600,   601,   602,   603,  -860,  -860,
    2898,  2898,   604,   605,   607,  -860,  -860,  -860,  -860,  -860,
     454,   455,  -860,   612,  -860,   614,  -860,  2898,   338,   631,
     643,   645,  2898,  -860,  -860,  2898,  -860,  -860,  -860,   640,
     641,   617,   619,   538,  2898,   646,   586,   621,   369,  -860,
     622,  -860,   368,   656,    54,  -860,  -860,  -860,   651,  -860,
    -860,  2898,   652,   627,  -860,  -860,  2898,  -860,  2898,  -860,
    -860,  -860,  -860,  -860,   630,   633,  -860,  -860,  -860,  -860,
    -860,   456,   458,   638,   648,   339,   340,   341,  -860,  -860,
    2898,  2898,  -860,  -860,  2898,   649,  2898,  2898,  -860,  -860,
    -860,  -860,   368,   663,  2898,  -860,  2898,  -860,   650,   653,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,   666,  -860,  -860,  -860,   368,  -860,  -860,  -860,
    -860,  2898,  -860,  -860
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     518,     0,   506,     1,   505,     0,     0,     0,     0,   490,
       0,     0,   454,     0,     0,   481,     0,     0,     0,   290,
       0,   439,   443,   440,     0,     0,     0,     0,     0,     0,
     482,   437,     0,     0,     0,   432,   480,     0,     0,     0,
     487,   489,   435,   438,   445,   442,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   428,   429,     0,     0,     0,     0,   419,
     420,   421,   422,   423,   414,   415,     0,     0,     0,   502,
     510,   507,   514,   516,   519,   430,   431,     0,     0,     0,
      83,    84,     0,     0,     0,     0,   127,   128,     0,   153,
     154,   155,   156,     0,   118,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   120,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   140,   141,   142,     0,
       0,     0,   151,   157,     0,     0,     0,     0,     0,   158,
     159,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     0,     0,    49,    54,    55,    56,    57,    58,    59,
      62,    63,     0,    68,    72,    70,   364,     2,    12,    15,
      17,    81,    20,   412,     0,     0,   191,   192,   395,     0,
       0,     0,   205,   206,   397,     0,     0,     0,   216,   217,
     398,     0,     0,     0,     0,     0,     0,     0,   185,   186,
     394,     0,     0,   248,   249,   399,     0,   251,   252,   253,
     257,   258,   400,   280,   281,     0,     0,     0,   288,   289,
     405,     0,   483,     0,   300,   408,   296,   297,   484,     0,
       0,   263,   264,     0,   267,   268,   402,     0,   271,   272,
     403,     0,   274,   278,   279,   404,     0,   472,   478,   479,
     460,     0,     0,   504,   433,     0,   261,   262,   401,     0,
     303,   304,   406,   298,   299,   485,   488,   447,     0,     0,
     446,   449,   450,   444,     0,   322,   323,     0,   486,     0,
       0,   410,   305,   407,   338,   344,   495,   464,   455,   465,
     354,   360,   458,   459,   411,   473,   474,   475,   374,   372,
     371,   373,   375,     0,   476,     0,     0,   413,     0,     0,
     418,   426,   427,     0,   424,     0,   388,   390,   416,     0,
     417,     0,   512,   477,     0,   500,   466,   463,     0,     0,
     506,   508,   506,   506,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    29,    30,    32,
      34,    35,    31,    36,   107,     0,   121,   122,     0,     0,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,   126,     0,   124,   125,     0,     0,   139,   133,
     134,   135,   136,     0,   150,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    60,    47,    50,    51,    52,
      53,    48,    61,    69,   114,     0,   369,   367,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   199,     0,
       0,     0,     0,    28,   207,   213,   208,   209,   214,   215,
     210,   211,   212,     0,     0,   197,   198,   396,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   161,     0,
       0,   238,   239,     0,     0,     0,     0,   235,   234,   160,
       0,     0,     0,   223,   224,     0,     0,     0,     0,   220,
     219,     0,   255,   250,     0,   285,   282,     0,     0,   315,
     319,   317,     0,     0,   441,     0,     0,   270,   269,   276,
     273,     0,   434,     0,     0,     0,   260,   259,     0,     0,
     448,     0,     0,     0,     0,   336,   328,   330,   335,   332,
     337,     0,   334,   342,     0,     0,     0,   468,     0,   470,
       0,   355,     0,     0,     0,   382,   383,   385,   386,   425,
     389,   391,   392,   393,   409,   506,   496,     0,     0,     0,
       0,     0,   502,   511,   506,   515,   517,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    14,     5,     7,     8,     9,
      10,     6,     3,     4,    16,    18,    19,     0,     0,     0,
      25,    21,     0,     0,   189,   187,     0,     0,     0,     0,
       0,     0,     0,     0,   167,     0,   179,     0,   171,     0,
     175,     0,   163,   236,     0,   243,   242,   247,   246,   241,
     245,   240,   244,     0,   221,     0,   228,   227,   232,   231,
     226,   230,   225,   229,     0,   256,   254,   286,   283,   287,
     284,     0,     0,     0,     0,   291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   436,     0,     0,     0,     0,
     324,   329,   331,   333,     0,     0,     0,   345,     0,     0,
       0,   357,     0,   356,   361,   379,   377,   376,   381,   384,
     387,   513,   497,     0,   362,     0,   346,     0,     0,   509,
       0,    80,    73,    75,    79,    77,     0,     0,     0,    82,
      86,    85,    88,    87,     0,     0,     0,     0,     0,    95,
      96,    97,   106,     0,   100,   101,   102,   103,   104,     0,
       0,   116,   117,   108,     0,     0,   112,     0,     0,     0,
     143,     0,    98,     0,     0,    27,   149,   144,   145,   146,
     147,   148,     0,     0,     0,   370,   368,     0,    23,    26,
     190,   188,   204,   201,   203,   200,     0,     0,   195,   193,
     164,   177,   169,   172,   166,   178,   170,   174,     0,     0,
     233,     0,   218,     0,   306,   316,   309,   320,   312,   318,
     292,     0,     0,     0,     0,     0,   461,     0,     0,     0,
       0,   451,   452,     0,   321,     0,     0,     0,   326,     0,
       0,     0,   348,     0,     0,   358,     0,   380,   378,     0,
       0,   467,     0,     0,     0,     0,    74,    76,    78,   130,
       0,     0,     0,     0,     0,     0,     0,     0,   113,   131,
       0,     0,     0,     0,     0,   115,    65,    24,   196,   194,
       0,     0,   180,   165,   176,   168,   173,     0,     0,     0,
       0,     0,     0,   294,   293,     0,   266,   277,   275,     0,
       0,     0,     0,   453,     0,     0,     0,     0,     0,   339,
       0,   469,     0,   349,     0,   457,   471,   359,     0,   363,
     347,     0,     0,     0,    89,    90,     0,    91,     0,    93,
     105,   111,   110,    22,     0,     0,    99,   152,    67,   182,
     184,     0,     0,     0,     0,     0,     0,     0,   295,   265,
       0,     0,   302,   301,     0,     0,     0,     0,   343,   327,
     341,   351,     0,   350,     0,   499,     0,   137,     0,     0,
     138,   132,   181,   183,   237,   222,   308,   311,   314,   491,
     492,   462,     0,   493,   325,   352,     0,   501,   503,    92,
      94,     0,   353,   494
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -860,    -7,  -102,   -84,   242,  -375,   484,  -860,  -860,  -860,
    -136,  -860,  -860,  -860,   472,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,   501,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -275,  -860,  -273,  -860,  -276,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -773,  -338,  -860,  -860,  -860,  -860,   148,  -623,
    -859,   -54,  -624,   -56,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,  -860,
    -860,  -860,  -331,  -860,  -860,  -860,  -324,  -860,  -860,  -860
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   746,   177,   178,   179,   180,   197,   363,   364,   181,
     182,   425,   629,   630,   490,   208,   209,   210,   186,   187,
     188,   465,   466,   467,   192,   193,   194,   459,   198,   199,
     200,   213,   214,   215,   220,   221,   222,   266,   267,   268,
     244,   245,   246,   248,   249,   250,   253,   254,   255,   228,
     229,   230,   234,   238,   275,   235,   270,   271,   272,   293,
     835,   909,   837,   910,   839,   911,   232,   701,   703,   702,
     288,   291,   859,   543,   295,   544,   545,   724,   296,   747,
     863,   302,   745,   183,   633,   632,   313,   738,   314,   317,
     320,   328,   330,    81,   239,   548,   569,   728,   730,   338,
     568,   339,    82,   574,    83,   340,    84,   565,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     176,   571,   304,   303,   196,   408,   803,   211,   804,   573,
     184,   231,   463,   612,   332,   333,   333,   243,   575,   576,
     256,   257,   334,   334,   202,   469,   471,   263,   264,   335,
     335,   473,   203,   276,   195,   365,   475,   403,   423,   283,
     279,   287,   441,   442,   292,   393,   784,  -498,  -498,   204,
     735,   176,   305,     3,   195,   316,   -64,   325,   319,   321,
     322,   647,   441,   442,   645,   646,   324,   391,   509,   820,
     259,  -340,   251,   981,   300,   301,   189,   205,   206,   679,
     535,   190,   352,   535,   927,   420,   821,   930,   680,   681,
     201,   421,   903,   428,   429,   216,   370,   430,   682,   431,
     432,   433,   434,   435,   861,   550,   864,   217,   218,   904,
     326,   327,   306,   307,   822,   823,   280,   510,   551,   791,
     869,   191,   736,  1005,   260,   874,    85,   737,   932,   536,
     537,   538,   536,   537,   538,   252,   793,   905,   906,   392,
     539,   933,   648,   539,   454,   455,   389,  1012,   454,   460,
     552,   792,   443,   356,   512,   979,   924,   366,   219,   511,
     336,   336,    86,   308,   390,   946,   233,   394,   586,   424,
     828,   309,   443,   934,   948,   367,   851,   444,   540,   894,
     513,   540,   447,   449,   451,   395,   436,   247,   925,   829,
     541,   690,   404,   541,   437,   258,   281,   947,   542,   261,
     691,   542,   357,   358,   359,   236,   949,   237,   185,   502,
     464,   360,   361,   362,   733,   456,   457,   458,   505,   456,
     457,   461,   207,   470,   472,   265,   310,   311,   312,   474,
     262,  -366,   514,   515,   476,  -366,   692,  -366,   337,   337,
     517,   741,   269,   749,   519,   693,   939,   795,   277,   940,
     583,   584,   560,   561,   524,   525,   721,   722,   526,   289,
    -365,   585,   478,   479,  -365,   278,  -365,   723,   478,   491,
     480,   529,   530,   284,   481,   482,   492,   426,   290,   427,
     493,   494,   533,   483,   223,   224,   225,   226,   439,   495,
     440,   323,   484,   329,   485,   486,   227,   273,   496,   274,
     497,   498,   294,   487,   488,   297,   650,   651,   555,   499,
     500,   557,   562,   563,   489,   416,   559,   298,   417,   418,
     489,   675,   676,   299,   564,   419,   331,   566,   636,   637,
     638,   639,   640,   641,   642,   643,   677,   678,   686,   687,
     688,   689,   428,   429,   634,   635,   587,   588,   590,   341,
     342,   343,   345,   344,   353,   354,   355,   368,   369,   371,
     372,   593,   594,   373,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   396,   374,   375,   397,   398,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   618,   386,   619,   620,
     387,   388,   623,   624,   625,   626,   627,   628,   399,   400,
     401,   402,   405,   409,   410,   411,   412,   413,   414,   415,
     422,   438,   446,   453,   195,   477,   504,   516,   521,   531,
     523,   507,   508,   522,   528,   534,   546,   532,   553,   654,
     547,  -456,   549,   554,   556,   558,   567,   570,   577,   614,
     578,   579,   580,   581,   582,   592,   660,   586,   663,   613,
     615,   616,   617,   621,   622,   -66,   706,   652,   631,   662,
     665,   667,   673,   653,   656,   657,   658,   659,   669,   671,
     705,   674,   711,   683,   685,   712,   694,   716,   719,   718,
     725,   726,   704,   729,   732,   743,   731,   695,   212,   734,
     697,   699,   748,   751,   756,   715,   757,   758,   759,   707,
     752,   753,   808,   809,   708,   760,   710,   765,   761,   766,
     754,   713,   755,   767,   717,   762,   768,   720,   282,   763,
     769,   770,   771,   772,   773,   774,   775,   776,   777,   778,
     779,   780,   781,   782,   783,   786,   790,   796,   797,   739,
     785,   740,   798,   799,   800,   810,   801,   811,   802,   807,
     742,   816,   744,   817,   841,   834,   836,   838,   843,   844,
     750,   845,   849,   850,   856,   857,   805,   806,   846,   860,
     866,   870,   872,   873,   840,   764,   875,   853,   867,   879,
     890,   888,   854,   889,   862,   891,   983,   858,   876,   877,
     878,   871,   793,   441,   868,   895,   907,   896,   787,   788,
     789,   898,   899,   908,   794,   900,  -307,   901,  -310,   902,
    -313,   912,   915,   744,   919,   176,   176,   928,   920,   929,
     938,   941,   942,   944,   931,   935,   945,   936,   965,   950,
     951,   952,   953,   956,   957,   961,   958,   962,   887,   812,
     966,   814,   967,   970,   971,   818,   972,   974,   973,   976,
     978,   980,   977,   982,   984,   986,   987,   830,   445,   990,
    1006,   897,   991,   448,   450,   452,   831,   994,   865,  1011,
     644,   959,   960,   992,   501,   993,   468,   995,  1002,  1009,
     996,   998,  1010,   997,   727,     0,     0,     0,   462,   842,
     503,     0,     0,     0,   847,   848,     0,     0,     0,   506,
       0,     0,   855,     0,     0,     0,     0,     0,     0,     0,
       0,   744,     0,   744,     0,     0,     0,     0,     0,     0,
       0,   518,     0,     0,     0,   520,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   527,
       0,     0,     0,     0,     0,     0,     0,     0,   880,   881,
     882,   883,     0,     0,     0,     0,   884,     0,     0,     0,
       0,     0,   885,   886,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   892,     0,   893,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   937,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   913,     0,   916,   917,   589,   591,
       0,     0,   921,     0,     0,     0,   923,     0,     0,   926,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   744,     0,     0,     0,     0,   943,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   954,   955,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     963,     0,     0,     0,     0,   968,     0,     0,   969,     0,
       0,     0,     0,     0,     0,     0,     0,   975,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     655,     0,     0,     0,   985,     0,     0,     0,     0,   988,
       0,   989,     0,     0,     0,     0,     0,   661,     0,     0,
       0,     0,     0,   664,     0,   666,     0,   668,     0,   670,
       0,   672,     0,   999,  1000,     0,     0,  1001,     0,  1003,
    1004,     0,     0,     0,     0,   684,     0,  1007,     0,  1008,
       0,     0,     0,     0,     0,     0,     0,     0,   696,     0,
       0,   698,   700,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1013,   709,     0,     0,     0,     0,
       0,     0,   714,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     0,     0,     0,     0,     0,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     0,     8,     9,     0,    10,     0,    11,    12,
       0,    13,    14,     0,     0,     0,     0,     0,     0,    15,
       0,    16,    17,    18,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,    21,
      22,    23,    24,    25,    26,     0,     0,     0,     0,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,     0,    29,
      30,     0,    31,     0,     0,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,     0,    42,     0,     0,
       0,    43,    44,    45,    46,    47,     0,    48,    49,     0,
       0,   813,     0,   815,     0,     0,   819,     0,     0,   824,
       0,   825,    50,   826,     0,   827,     0,     0,     0,     0,
      51,     0,     0,    52,     0,    53,    54,    55,     0,   832,
      56,     0,     0,     0,    57,     0,    58,     0,   833,    59,
      60,     0,     0,     0,     0,    61,     0,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
     852,     0,    74,    75,    76,    77,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     0,    79,     0,    80,     0,     0,     5,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     0,     0,     0,     8,     9,     0,    10,     0,    11,
      12,     0,    13,    14,     0,     0,     0,     0,     0,     0,
      15,     0,    16,    17,    18,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
      21,    22,    23,    24,    25,    26,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   914,     0,     0,    28,   918,
      29,    30,     0,    31,   922,     0,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,     0,    42,     0,
       0,     0,    43,    44,    45,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,    52,     0,    53,    54,    55,     0,
       0,    56,   964,     0,     0,    57,     0,    58,     0,     0,
      59,    60,     0,     0,     0,     0,    61,     0,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,     0,     0,    74,    75,    76,    77,    78,   315,     0,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,   572,     0,     0,     0,     0,     0,
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
     157,   158,   159,   160,   161,   162,   163,     0,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     318,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
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
     155,   156,   157,   158,   159,   160,   161,   162,   163,    87,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,     0,     0,     0,     0,     0,    88,   346,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,    94,     0,     0,    95,   347,   348,
     349,     0,     0,     0,     0,     0,     0,    96,    97,   350,
      98,     0,     0,     0,     0,     0,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,     0,     0,     0,     0,     0,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   351,
     121,   122,   123,     0,   124,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,     0,
     127,     0,   128,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,   130,     0,     0,   131,     0,   132,   133,
     134,   135,     0,   136,   137,     0,     0,     0,     0,   138,
     139,   140,   141,     0,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,    87,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,     0,
       0,     0,     0,     0,     0,   240,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,   241,   242,     0,
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
     161,   162,   163,    87,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,     0,     0,     0,
       0,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
     285,   286,     0,     0,     0,     0,     0,     0,    90,    91,
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
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
      87,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,     0,     0,     0,     0,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,    94,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,   195,    96,    97,
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
     157,   158,   159,   160,   161,   162,   163,     0,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   345,     0,     0,     0,     0,     0,     0,     0,    88,
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
     157,   158,   159,   160,   161,   162,   163,    87,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,     0,     0,     0,     0,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
       0,     0,    94,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,     0,    98,     0,
       0,     0,     0,     0,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,     0,     0,   118,   119,   120,     0,   121,   122,
     123,     0,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,   127,     0,
     128,     0,     0,     0,     0,     0,     0,     0,   129,     0,
       0,   130,     0,     0,   131,     0,   132,   133,   134,   135,
       0,   136,   137,     0,     0,     0,     0,   138,   139,   140,
     141,     0,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,    87,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,     0,     0,     0,
       0,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,     0,     0,    94,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,     0,    98,     0,     0,     0,     0,
       0,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,     0,
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
     163,    87,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,     0,     0,     0,     0,     0,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,    94,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,     0,    98,     0,     0,     0,     0,     0,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   649,   104,   105,     0,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,     0,   121,   122,   123,     0,   124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     126,     0,   127,     0,   128,     0,     0,     0,     0,     0,
       0,     0,   129,     0,     0,   130,     0,     0,   131,     0,
     132,   133,   134,   135,     0,   136,   137,     0,     0,     0,
       0,   138,   139,   140,   407,     0,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    87,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,     0,     0,     0,     0,     0,     0,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   406,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,    94,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,     0,    98,
       0,     0,     0,     0,     0,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,     0,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,     0,   121,
     122,   123,     0,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,     0,   127,
       0,   128,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     0,   130,     0,     0,   131,     0,   132,   133,   134,
     135,     0,   136,   137,     0,     0,     0,     0,   138,   139,
     140,   407,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,    87,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,     0,
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
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,     0,   127,     0,   128,     0,
       0,     0,     0,     0,     0,     0,   129,     0,     0,   130,
       0,     0,   131,     0,   132,   133,   134,   135,     0,   136,
     137,     0,     0,     0,     0,   138,   139,   140,   407,     0,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,     0,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175
};

static const yytype_int16 yycheck[] =
{
       7,   339,    58,    57,    11,   141,   630,    14,   631,   340,
      28,    18,    28,   388,     4,     6,     6,    24,   342,   343,
      27,    28,    13,    13,    28,    28,    28,    34,    35,    20,
      20,    28,    36,    40,    86,    20,    28,    38,    20,    46,
      72,    48,    23,    24,    51,    20,     7,    38,    38,    53,
      90,    58,    59,     0,    86,    62,    38,    45,    65,    66,
      67,   111,    23,    24,   439,   440,    73,    90,    57,    36,
      94,    20,    28,   932,   226,   227,    30,    81,    82,    49,
      29,    35,    89,    29,   857,   209,    53,   860,    58,    49,
      26,   215,    36,     8,     9,    28,   103,    12,    58,    14,
      15,    16,    17,    18,   728,     7,   730,    40,    41,    53,
      98,    99,    46,    47,    81,    82,   148,   106,    20,     7,
     743,    75,   162,   982,   148,   748,   226,   167,     7,    78,
      79,    80,    78,    79,    80,    91,     7,    81,    82,   162,
      89,    20,   192,    89,    83,    84,    20,  1006,    83,    84,
      52,    39,   133,    29,    20,   928,     7,   142,    91,   148,
     151,   151,   226,   101,    38,     7,   226,   142,    39,   151,
      33,   109,   133,    52,     7,   160,   228,   184,   127,   802,
      46,   127,   189,   190,   191,   160,   101,    28,    39,    52,
     139,    49,   193,   139,   109,    94,   228,    39,   147,    38,
      58,   147,    78,    79,    80,   226,    39,   228,   226,   216,
     226,    87,    88,    89,   552,   154,   155,   156,   225,   154,
     155,   156,   226,   226,   226,    28,   164,   165,   166,   226,
      38,     0,   239,   240,   226,     4,    49,     6,   229,   229,
     247,   565,    28,   574,   251,    58,   870,   622,   148,   872,
      78,    79,    98,    99,   261,   262,    78,    79,   265,    38,
       0,    89,    28,    29,     4,    72,     6,    89,    28,    29,
      36,   278,   279,   226,    40,    41,    36,     5,   226,     7,
      40,    41,   289,    49,    46,    47,    48,    49,    19,    49,
      21,   176,    58,    45,    60,    61,    58,   226,    58,   228,
      60,    61,   226,    69,    70,   226,   442,   443,   315,    69,
      70,   318,    96,    97,    80,   205,   323,   226,   208,   209,
      80,    60,    61,   226,   331,   215,    13,   334,   430,   431,
     432,   433,   434,   435,   436,   437,    60,    61,    60,    61,
      60,    61,     8,     9,   428,   429,   353,   354,   355,     6,
       4,     4,    20,   228,    38,    38,    38,    38,    38,    38,
      38,   368,   369,    38,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,    20,    38,    38,    20,    20,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,   403,    38,   405,   406,
      38,    38,   409,   410,   411,   412,   413,   414,    20,    20,
      20,    20,    38,    38,    38,    38,    38,    38,    38,   208,
     208,   134,    28,   228,    86,    28,    33,     7,    33,    13,
     151,    50,    50,    73,    38,     7,     7,   156,     7,   446,
     151,   151,   151,     7,     7,     7,    13,    38,    38,   226,
      39,    39,    39,    39,    39,    38,   463,    39,    52,    38,
      38,    38,    38,    38,    25,    38,     7,    33,    38,    28,
      28,    28,   479,    33,    76,    76,    76,    76,    28,    28,
     226,    37,     7,    38,    37,     7,    38,     7,     7,   106,
      38,    20,    46,   151,     7,    38,   550,   504,    14,   553,
     507,   508,    38,   228,    39,    73,    39,    39,    39,   516,
     228,   228,   648,   649,   521,    39,   523,     7,    39,     7,
     228,   528,   228,     7,   531,    39,     7,   534,    44,    39,
      39,    39,    39,    39,     7,    39,    39,    39,    39,    39,
       7,     7,    39,    39,    39,    39,    39,    39,    39,   556,
     226,   558,    39,    39,    39,   226,    39,   226,    38,   192,
     567,    33,   569,    33,    13,   226,   226,   226,     7,    46,
     577,    46,     7,     7,     7,    38,   632,   633,   152,    38,
       7,     7,     7,    39,   226,   592,     7,    76,   169,    39,
       7,    39,   226,    39,   226,     7,   934,   228,   228,   228,
     228,   152,     7,    23,   169,   152,     7,    39,   615,   616,
     617,   226,   226,     7,   621,    33,     7,    33,     7,   227,
       7,    13,     7,   630,    39,   632,   633,     7,    39,    39,
      39,    13,    39,    39,   152,   152,    39,   152,     7,    39,
      39,    39,    39,    39,    39,    33,    39,    33,   784,   656,
       7,   658,     7,    13,    13,   662,    39,   119,    39,    13,
      39,    39,    76,     7,    13,    13,    39,   674,   184,    39,
       7,   807,    39,   189,   190,   191,   683,    39,   732,    13,
     438,   227,   227,   227,   212,   227,   202,    39,    39,    39,
     965,   967,    39,   966,   546,    -1,    -1,    -1,   197,   706,
     216,    -1,    -1,    -1,   711,   712,    -1,    -1,    -1,   225,
      -1,    -1,   719,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   728,    -1,   730,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   765,   766,
     767,   768,    -1,    -1,    -1,    -1,   773,    -1,    -1,    -1,
      -1,    -1,   779,   780,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   791,    -1,   793,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   866,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   841,    -1,   843,   844,   354,   355,
      -1,    -1,   849,    -1,    -1,    -1,   853,    -1,    -1,   856,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   870,    -1,    -1,    -1,    -1,   875,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   890,   891,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     907,    -1,    -1,    -1,    -1,   912,    -1,    -1,   915,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   924,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     446,    -1,    -1,    -1,   941,    -1,    -1,    -1,    -1,   946,
      -1,   948,    -1,    -1,    -1,    -1,    -1,   463,    -1,    -1,
      -1,    -1,    -1,   469,    -1,   471,    -1,   473,    -1,   475,
      -1,   477,    -1,   970,   971,    -1,    -1,   974,    -1,   976,
     977,    -1,    -1,    -1,    -1,   491,    -1,   984,    -1,   986,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   504,    -1,
      -1,   507,   508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1011,   521,    -1,    -1,    -1,    -1,
      -1,    -1,   528,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    26,    27,    -1,    29,    -1,    31,    32,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    44,    45,    46,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    92,
      93,    -1,    95,    -1,    -1,    98,    99,   100,    -1,   102,
     103,   104,   105,   106,   107,   108,    -1,   110,    -1,    -1,
      -1,   114,   115,   116,   117,   118,    -1,   120,   121,    -1,
      -1,   657,    -1,   659,    -1,    -1,   662,    -1,    -1,   665,
      -1,   667,   135,   669,    -1,   671,    -1,    -1,    -1,    -1,
     143,    -1,    -1,   146,    -1,   148,   149,   150,    -1,   685,
     153,    -1,    -1,    -1,   157,    -1,   159,    -1,   694,   162,
     163,    -1,    -1,    -1,    -1,   168,    -1,   170,   171,   172,
     173,   174,   175,    -1,   177,   178,   179,   180,   181,   182,
     716,    -1,   185,   186,   187,   188,   189,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,   226,    -1,   228,    -1,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    26,    27,    -1,    29,    -1,    31,
      32,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   841,    -1,    -1,    90,   845,
      92,    93,    -1,    95,   850,    -1,    98,    99,   100,    -1,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,    -1,
      -1,    -1,   114,   115,   116,   117,   118,    -1,   120,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   143,    -1,    -1,   146,    -1,   148,   149,   150,    -1,
      -1,   153,   908,    -1,    -1,   157,    -1,   159,    -1,    -1,
     162,   163,    -1,    -1,    -1,    -1,   168,    -1,   170,   171,
     172,   173,   174,   175,    -1,   177,   178,   179,   180,   181,
     182,    -1,    -1,   185,   186,   187,   188,   189,     7,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
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
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
       7,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     207,   208,   209,   210,   211,   212,   213,   214,   215,     9,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,    -1,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,
      90,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,   141,   142,    -1,   144,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,
     160,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     170,    -1,    -1,   173,    -1,    -1,   176,    -1,   178,   179,
     180,   181,    -1,   183,   184,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    -1,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,     9,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    -1,
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
     213,   214,   215,     9,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
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
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
       9,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,
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
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
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
     209,   210,   211,   212,   213,   214,   215,     9,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    90,    -1,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,    -1,   136,   137,   138,    -1,   140,   141,
     142,    -1,   144,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,
      -1,   173,    -1,    -1,   176,    -1,   178,   179,   180,   181,
      -1,   183,   184,    -1,    -1,    -1,    -1,   189,   190,   191,
     192,    -1,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,     9,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,    -1,
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
     215,     9,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,    -1,    -1,    -1,    -1,    -1,    -1,
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
     208,   209,   210,   211,   212,   213,   214,   215,     9,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,    -1,   136,   137,   138,    -1,   140,
     141,   142,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,   160,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,
      -1,    -1,   173,    -1,    -1,   176,    -1,   178,   179,   180,
     181,    -1,   183,   184,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,     9,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,    -1,    -1,
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
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,    -1,   160,    -1,   162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,   173,
      -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,   183,
     184,    -1,    -1,    -1,    -1,   189,   190,   191,   192,    -1,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   338,   339,     0,     3,    10,    11,    22,    26,    27,
      29,    31,    32,    34,    35,    42,    44,    45,    46,    51,
      57,    62,    63,    64,    65,    66,    67,    72,    90,    92,
      93,    95,    98,    99,   100,   102,   103,   104,   105,   106,
     107,   108,   110,   114,   115,   116,   117,   118,   120,   121,
     135,   143,   146,   148,   149,   150,   153,   157,   159,   162,
     163,   168,   170,   171,   172,   173,   174,   175,   177,   178,
     179,   180,   181,   182,   185,   186,   187,   188,   189,   226,
     228,   323,   332,   334,   336,   226,   226,     9,    28,    38,
      54,    55,    56,    71,    74,    77,    87,    88,    90,    96,
      97,    98,    99,   111,   112,   113,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   136,   137,
     138,   140,   141,   142,   144,   145,   158,   160,   162,   170,
     173,   176,   178,   179,   180,   181,   183,   184,   189,   190,
     191,   192,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   231,   232,   233,   234,
     235,   239,   240,   313,    28,   226,   248,   249,   250,    30,
      35,    75,   254,   255,   256,    86,   231,   236,   258,   259,
     260,    26,    28,    36,    53,    81,    82,   226,   245,   246,
     247,   231,   236,   261,   262,   263,    28,    40,    41,    91,
     264,   265,   266,    46,    47,    48,    49,    58,   279,   280,
     281,   231,   296,   226,   282,   285,   226,   228,   283,   324,
      28,    40,    41,   231,   270,   271,   272,    28,   273,   274,
     275,    28,    91,   276,   277,   278,   231,   231,    94,    94,
     148,    38,    38,   231,   231,    28,   267,   268,   269,    28,
     286,   287,   288,   226,   228,   284,   231,   148,    72,    72,
     148,   228,   236,   231,   226,    46,    47,   231,   300,    38,
     226,   301,   231,   289,   226,   304,   308,   226,   226,   226,
     226,   227,   311,   311,   313,   231,    46,    47,   101,   109,
     164,   165,   166,   316,   318,     7,   231,   319,     7,   231,
     320,   231,   231,   176,   231,    45,    98,    99,   321,    45,
     322,    13,     4,     6,    13,    20,   151,   229,   329,   331,
     335,     6,     4,     4,   228,    20,    29,    78,    79,    80,
      89,   139,   231,    38,    38,    38,    29,    78,    79,    80,
      87,    88,    89,   237,   238,    20,   142,   160,    38,    38,
     231,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    20,
      38,    90,   162,    20,   142,   160,    20,    20,    20,    20,
      20,    20,    20,    38,   193,    38,    38,   192,   240,    38,
      38,    38,    38,    38,    38,   208,   205,   208,   209,   215,
     209,   215,   208,    20,   151,   241,     5,     7,     8,     9,
      12,    14,    15,    16,    17,    18,   101,   109,   134,    19,
      21,    23,    24,   133,   231,   236,    28,   231,   236,   231,
     236,   231,   236,   228,    83,    84,   154,   155,   156,   257,
      84,   156,   257,    28,   226,   251,   252,   253,   236,    28,
     226,    28,   226,    28,   226,    28,   226,    28,    28,    29,
      36,    40,    41,    49,    58,    60,    61,    69,    70,    80,
     244,    29,    36,    40,    41,    49,    58,    60,    61,    69,
      70,   244,   231,   236,    33,   231,   236,    50,    50,    57,
     106,   148,    20,    46,   231,   231,     7,   231,   236,   231,
     236,    33,    73,   151,   231,   231,   231,   236,    38,   231,
     231,    13,   156,   231,     7,    29,    78,    79,    80,    89,
     127,   139,   147,   303,   305,   306,     7,   151,   325,   151,
       7,    20,    52,     7,     7,   231,     7,   231,     7,   231,
      98,    99,    96,    97,   231,   337,   231,    13,   330,   326,
      38,   303,   226,   332,   333,   336,   336,    38,    39,    39,
      39,    39,    39,    78,    79,    89,    39,   231,   231,   236,
     231,   236,    38,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   235,    38,   226,    38,    38,    38,   231,   231,
     231,    38,    25,   231,   231,   231,   231,   231,   231,   242,
     243,    38,   315,   314,   233,   233,   232,   232,   232,   232,
     232,   232,   232,   232,   234,   235,   235,   111,   192,   111,
     240,   240,    33,    33,   231,   236,    76,    76,    76,    76,
     231,   236,    28,    52,   236,    28,   236,    28,   236,    28,
     236,    28,   236,   231,    37,    60,    61,    60,    61,    49,
      58,    49,    58,    38,   236,    37,    60,    61,    60,    61,
      49,    58,    49,    58,    38,   231,   236,   231,   236,   231,
     236,   297,   299,   298,    46,   226,     7,   231,   231,   236,
     231,     7,     7,   231,   236,    73,     7,   231,   106,     7,
     231,    78,    79,    89,   307,    38,    20,   308,   327,   151,
     328,   311,     7,   303,   311,    90,   162,   167,   317,   231,
     231,   336,   231,    38,   231,   312,   231,   309,    38,   332,
     231,   228,   228,   228,   228,   228,    39,    39,    39,    39,
      39,    39,    39,    39,   231,     7,     7,     7,     7,    39,
      39,    39,    39,     7,    39,    39,    39,    39,    39,     7,
       7,    39,    39,    39,     7,   226,    39,   231,   231,   231,
      39,     7,    39,     7,   231,   235,    39,    39,    39,    39,
      39,    39,    38,   312,   309,   313,   313,   192,   240,   240,
     226,   226,   231,   236,   231,   236,    33,    33,   231,   236,
      36,    53,    81,    82,   236,   236,   236,   236,    33,    52,
     231,   231,   236,   236,   226,   290,   226,   292,   226,   294,
     226,    13,   231,     7,    46,    46,   152,   231,   231,     7,
       7,   228,   236,    76,   226,   231,     7,    38,   228,   302,
      38,   312,   226,   310,   312,   311,     7,   169,   169,   309,
       7,   152,     7,    39,   309,     7,   228,   228,   228,    39,
     231,   231,   231,   231,   231,   231,   231,   240,    39,    39,
       7,     7,   231,   231,   309,   152,    39,   240,   226,   226,
      33,    33,   227,    36,    53,    81,    82,     7,     7,   291,
     293,   295,    13,   231,   236,     7,   231,   231,   236,    39,
      39,   231,   236,   231,     7,    39,   231,   302,     7,    39,
     302,   152,     7,    20,    52,   152,   152,   311,    39,   312,
     309,    13,    39,   231,    39,    39,     7,    39,     7,    39,
      39,    39,    39,    39,   231,   231,    39,    39,    39,   227,
     227,    33,    33,   231,   236,     7,     7,     7,   231,   231,
      13,    13,    39,    39,   119,   231,    13,    76,    39,   302,
      39,   310,     7,   303,    13,   231,    13,    39,   231,   231,
      39,    39,   227,   227,    39,    39,   290,   292,   294,   231,
     231,   231,    39,   231,   231,   310,     7,   231,   231,    39,
      39,    13,   310,   231
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   230,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   232,   232,   232,   233,   233,   234,   234,   234,
     235,   235,   235,   235,   235,   235,   235,   235,   236,   237,
     237,   237,   237,   237,   237,   237,   238,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   241,   240,   242,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   243,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     244,   244,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     246,   246,   246,   246,   246,   247,   247,   248,   248,   249,
     249,   250,   250,   251,   251,   252,   252,   253,   253,   254,
     254,   254,   255,   255,   255,   256,   256,   257,   257,   257,
     258,   258,   258,   259,   259,   259,   260,   260,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   263,   263,
     264,   264,   264,   264,   264,   265,   265,   266,   266,   267,
     268,   269,   269,   270,   270,   271,   271,   272,   272,   273,
     274,   275,   275,   276,   276,   276,   277,   277,   278,   278,
     279,   279,   279,   279,   279,   280,   280,   280,   281,   281,
     282,   282,   282,   282,   282,   282,   283,   283,   284,   284,
     285,   286,   287,   288,   288,   289,   290,   291,   290,   292,
     293,   292,   294,   295,   294,   297,   296,   298,   296,   299,
     296,   300,   300,   300,   301,   301,   302,   302,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   305,   304,
     306,   304,   307,   304,   308,   308,   309,   309,   310,   310,
     310,   310,   310,   310,   311,   311,   311,   311,   311,   311,
     311,   311,   312,   312,   313,   313,   313,   314,   313,   315,
     313,   316,   316,   316,   316,   316,   317,   317,   317,   317,
     317,   318,   319,   319,   319,   320,   320,   320,   321,   321,
     321,   321,   322,   322,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     324,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   325,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   326,   323,   327,   323,
     328,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   329,   323,
     330,   323,   331,   323,   323,   323,   323,   332,   333,   332,
     335,   334,   337,   336,   336,   336,   336,   336,   339,   338
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
       2,     1,     1,     1,     1,     6,     5,     1,     1,     2,
       2,     1,     1,     2,     1,     5,     2,     5,     1,     1,
       1,     1,     2,     3,     3,     2,     3,     3,     1,     1,
       0,     3,     4,     5,     5,     6,     1,     1,     1,     1,
       1,     6,     6,     1,     1,     1,     1,     0,     4,     1,
       0,     4,     1,     0,     4,     0,     4,     0,     4,     0,
       4,     4,     1,     1,     3,     7,     1,     3,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     0,     5,
       0,     6,     0,     6,     1,     3,     1,     3,     1,     2,
       3,     3,     4,     5,     1,     2,     3,     3,     4,     5,
       1,     3,     1,     3,     1,     2,     2,     0,     4,     0,
       4,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     3,     2,     2,     3,     2,     2,     3,     1,     2,
       1,     2,     2,     2,     2,     2,     3,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       2,     2,     2,     2,     1,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     2,     3,     2,     2,     1,     1,
       2,     2,     1,     2,     3,     1,     4,     1,     1,     1,
       0,     3,     1,     1,     2,     1,     2,     2,     3,     2,
       2,     5,     5,     6,     1,     2,     0,     6,     2,     2,
       2,     5,     8,     2,     2,     2,     0,     5,     0,     6,
       0,     6,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     2,     2,     2,     2,     1,     2,     1,
       1,     8,     8,     8,    10,     2,     3,     4,     0,     7,
       0,     8,     0,     8,     2,     1,     0,     1,     0,     4,
       0,     3,     0,     4,     1,     3,     1,     3,     0,     2
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
#line 3142 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 85 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3151 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math EQUAL expr_math  */
#line 89 "src/ugbc.y"
                                {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3159 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math DISEQUAL expr_math  */
#line 92 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3167 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math LT expr_math  */
#line 95 "src/ugbc.y"
                             {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3175 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math LTE expr_math  */
#line 98 "src/ugbc.y"
                              {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 3183 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math GT expr_math  */
#line 101 "src/ugbc.y"
                             {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3191 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math GTE expr_math  */
#line 104 "src/ugbc.y"
                              {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3199 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 107 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 3207 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math PLUS term  */
#line 114 "src/ugbc.y"
                          {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3215 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math MINUS term  */
#line 117 "src/ugbc.y"
                           {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3224 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula MULTIPLICATION factor  */
#line 130 "src/ugbc.y"
                                   {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3233 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula DIVISION factor  */
#line 134 "src/ugbc.y"
                             {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3242 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor POW exponential  */
#line 142 "src/ugbc.y"
                               {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 3251 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor COMMA exponential CP  */
#line 146 "src/ugbc.y"
                                                {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 3260 "src-generated/ugbc.tab.c"
    break;

  case 23: /* factor: factor HAS BIT exponential  */
#line 150 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[0].string) )->name;
      }
#line 3268 "src-generated/ugbc.tab.c"
    break;

  case 24: /* factor: factor HAS NOT BIT exponential  */
#line 153 "src/ugbc.y"
                                       {
        (yyval.string) = variable_not( _environment, variable_bit( _environment, (yyvsp[-4].string), (yyvsp[0].string) )->name )->name;
      }
#line 3276 "src-generated/ugbc.tab.c"
    break;

  case 25: /* factor: factor IS exponential  */
#line 156 "src/ugbc.y"
                              {
        (yyval.string) = variable_bit( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
      }
#line 3284 "src-generated/ugbc.tab.c"
    break;

  case 26: /* factor: factor IS NOT exponential  */
#line 159 "src/ugbc.y"
                                  {
        (yyval.string) = variable_not( _environment, variable_bit( _environment, (yyvsp[-3].string), (yyvsp[0].string) )->name )->name;
      }
#line 3292 "src-generated/ugbc.tab.c"
    break;

  case 27: /* factor: BIT exponential OF factor  */
#line 162 "src/ugbc.y"
                                  {
        (yyval.string) = variable_bit( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
      }
#line 3300 "src-generated/ugbc.tab.c"
    break;

  case 28: /* direct_integer: HASH Integer  */
#line 168 "src/ugbc.y"
                 {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3308 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: BYTE  */
#line 173 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3316 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: WORD  */
#line 176 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3324 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition_simple: DWORD  */
#line 179 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3332 "src-generated/ugbc.tab.c"
    break;

  case 32: /* random_definition_simple: POSITION  */
#line 182 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3340 "src-generated/ugbc.tab.c"
    break;

  case 33: /* random_definition_simple: COLOR  */
#line 185 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3348 "src-generated/ugbc.tab.c"
    break;

  case 34: /* random_definition_simple: WIDTH  */
#line 188 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3356 "src-generated/ugbc.tab.c"
    break;

  case 35: /* random_definition_simple: HEIGHT  */
#line 191 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3364 "src-generated/ugbc.tab.c"
    break;

  case 36: /* random_definition: random_definition_simple  */
#line 196 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3372 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: BLACK  */
#line 201 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3381 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: WHITE  */
#line 205 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3390 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: RED  */
#line 209 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3399 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: CYAN  */
#line 213 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3408 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: VIOLET  */
#line 217 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3417 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: GREEN  */
#line 221 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3426 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: BLUE  */
#line 225 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3435 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: YELLOW  */
#line 229 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3444 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: ORANGE  */
#line 233 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3453 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: BROWN  */
#line 237 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3462 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT RED  */
#line 241 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3471 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK GREY  */
#line 245 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3480 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: GREY  */
#line 249 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3489 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: LIGHT GREEN  */
#line 253 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3498 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LIGHT BLUE  */
#line 257 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3507 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: LIGHT GREY  */
#line 261 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3516 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: DARK BLUE  */
#line 265 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3525 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: MAGENTA  */
#line 269 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3534 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: PURPLE  */
#line 273 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3543 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: LAVENDER  */
#line 277 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3552 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: GOLD  */
#line 281 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3561 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: TURQUOISE  */
#line 285 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3570 "src-generated/ugbc.tab.c"
    break;

  case 59: /* color_enumeration: TAN  */
#line 289 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3579 "src-generated/ugbc.tab.c"
    break;

  case 60: /* color_enumeration: YELLOW GREEN  */
#line 293 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3588 "src-generated/ugbc.tab.c"
    break;

  case 61: /* color_enumeration: OLIVE GREEN  */
#line 297 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3597 "src-generated/ugbc.tab.c"
    break;

  case 62: /* color_enumeration: PINK  */
#line 301 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3606 "src-generated/ugbc.tab.c"
    break;

  case 63: /* color_enumeration: PEACH  */
#line 305 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3615 "src-generated/ugbc.tab.c"
    break;

  case 64: /* $@1: %empty  */
#line 311 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 3624 "src-generated/ugbc.tab.c"
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
#line 3636 "src-generated/ugbc.tab.c"
    break;

  case 66: /* $@2: %empty  */
#line 322 "src/ugbc.y"
                        {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 3645 "src-generated/ugbc.tab.c"
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
#line 3657 "src-generated/ugbc.tab.c"
    break;

  case 68: /* exponential: Identifier  */
#line 333 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 3665 "src-generated/ugbc.tab.c"
    break;

  case 69: /* exponential: Identifier DOLLAR  */
#line 336 "src/ugbc.y"
                        { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 3673 "src-generated/ugbc.tab.c"
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
#line 3687 "src-generated/ugbc.tab.c"
    break;

  case 71: /* exponential: MINUS Integer  */
#line 348 "src/ugbc.y"
                    { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 3696 "src-generated/ugbc.tab.c"
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
#line 3708 "src-generated/ugbc.tab.c"
    break;

  case 73: /* exponential: OP BYTE CP Integer  */
#line 359 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3717 "src-generated/ugbc.tab.c"
    break;

  case 74: /* exponential: OP SIGNED BYTE CP Integer  */
#line 363 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3726 "src-generated/ugbc.tab.c"
    break;

  case 75: /* exponential: OP WORD CP Integer  */
#line 367 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3735 "src-generated/ugbc.tab.c"
    break;

  case 76: /* exponential: OP SIGNED WORD CP Integer  */
#line 371 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3744 "src-generated/ugbc.tab.c"
    break;

  case 77: /* exponential: OP DWORD CP Integer  */
#line 375 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3753 "src-generated/ugbc.tab.c"
    break;

  case 78: /* exponential: OP SIGNED DWORD CP Integer  */
#line 379 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3762 "src-generated/ugbc.tab.c"
    break;

  case 79: /* exponential: OP POSITION CP Integer  */
#line 383 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3771 "src-generated/ugbc.tab.c"
    break;

  case 80: /* exponential: OP COLOR CP Integer  */
#line 387 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 3780 "src-generated/ugbc.tab.c"
    break;

  case 81: /* exponential: color_enumeration  */
#line 391 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 3788 "src-generated/ugbc.tab.c"
    break;

  case 82: /* exponential: PEEK OP expr CP  */
#line 394 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 3796 "src-generated/ugbc.tab.c"
    break;

  case 83: /* exponential: XPEN  */
#line 397 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 3804 "src-generated/ugbc.tab.c"
    break;

  case 84: /* exponential: YPEN  */
#line 400 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 3812 "src-generated/ugbc.tab.c"
    break;

  case 85: /* exponential: COLLISION OP direct_integer CP  */
#line 403 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3820 "src-generated/ugbc.tab.c"
    break;

  case 86: /* exponential: COLLISION OP expr CP  */
#line 406 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3828 "src-generated/ugbc.tab.c"
    break;

  case 87: /* exponential: HIT OP direct_integer CP  */
#line 409 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 3836 "src-generated/ugbc.tab.c"
    break;

  case 88: /* exponential: HIT OP expr CP  */
#line 412 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 3844 "src-generated/ugbc.tab.c"
    break;

  case 89: /* exponential: LEFT OP expr COMMA expr CP  */
#line 415 "src/ugbc.y"
                                 {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3852 "src-generated/ugbc.tab.c"
    break;

  case 90: /* exponential: RIGHT OP expr COMMA expr CP  */
#line 418 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3860 "src-generated/ugbc.tab.c"
    break;

  case 91: /* exponential: MID OP expr COMMA expr CP  */
#line 421 "src/ugbc.y"
                                {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3868 "src-generated/ugbc.tab.c"
    break;

  case 92: /* exponential: MID OP expr COMMA expr COMMA expr CP  */
#line 424 "src/ugbc.y"
                                           {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3876 "src-generated/ugbc.tab.c"
    break;

  case 93: /* exponential: INSTR OP expr COMMA expr CP  */
#line 427 "src/ugbc.y"
                                  {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 3884 "src-generated/ugbc.tab.c"
    break;

  case 94: /* exponential: INSTR OP expr COMMA expr COMMA expr CP  */
#line 430 "src/ugbc.y"
                                             {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3892 "src-generated/ugbc.tab.c"
    break;

  case 95: /* exponential: UPPER OP expr CP  */
#line 433 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 3900 "src-generated/ugbc.tab.c"
    break;

  case 96: /* exponential: LOWER OP expr CP  */
#line 436 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 3908 "src-generated/ugbc.tab.c"
    break;

  case 97: /* exponential: STR OP expr CP  */
#line 439 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 3916 "src-generated/ugbc.tab.c"
    break;

  case 98: /* exponential: BIN OP expr CP  */
#line 442 "src/ugbc.y"
                     {
        (yyval.string) = variable_bin( _environment, (yyvsp[-1].string), NULL )->name;
    }
#line 3924 "src-generated/ugbc.tab.c"
    break;

  case 99: /* exponential: BIN OP expr COMMA expr CP  */
#line 445 "src/ugbc.y"
                                {
        (yyval.string) = variable_bin( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3932 "src-generated/ugbc.tab.c"
    break;

  case 100: /* exponential: SPACE OP expr CP  */
#line 448 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 3940 "src-generated/ugbc.tab.c"
    break;

  case 101: /* exponential: FLIP OP expr CP  */
#line 451 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 3948 "src-generated/ugbc.tab.c"
    break;

  case 102: /* exponential: CHR OP expr CP  */
#line 454 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 3956 "src-generated/ugbc.tab.c"
    break;

  case 103: /* exponential: ASC OP expr CP  */
#line 457 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 3964 "src-generated/ugbc.tab.c"
    break;

  case 104: /* exponential: LEN OP expr CP  */
#line 460 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 3972 "src-generated/ugbc.tab.c"
    break;

  case 105: /* exponential: STRING OP expr COMMA expr CP  */
#line 463 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 3980 "src-generated/ugbc.tab.c"
    break;

  case 106: /* exponential: VAL OP expr CP  */
#line 466 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 3988 "src-generated/ugbc.tab.c"
    break;

  case 107: /* exponential: RANDOM random_definition  */
#line 469 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 3996 "src-generated/ugbc.tab.c"
    break;

  case 108: /* exponential: RND OP expr CP  */
#line 472 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 4004 "src-generated/ugbc.tab.c"
    break;

  case 109: /* exponential: OP expr CP  */
#line 475 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 4012 "src-generated/ugbc.tab.c"
    break;

  case 110: /* exponential: MAX OP expr COMMA expr CP  */
#line 478 "src/ugbc.y"
                                {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4020 "src-generated/ugbc.tab.c"
    break;

  case 111: /* exponential: MIN OP expr COMMA expr CP  */
#line 481 "src/ugbc.y"
                                {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4028 "src-generated/ugbc.tab.c"
    break;

  case 112: /* exponential: PARAM OP Identifier CP  */
#line 484 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 4036 "src-generated/ugbc.tab.c"
    break;

  case 113: /* exponential: PARAM DOLLAR OP Identifier CP  */
#line 487 "src/ugbc.y"
                                    {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 4044 "src-generated/ugbc.tab.c"
    break;

  case 114: /* $@3: %empty  */
#line 490 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 4052 "src-generated/ugbc.tab.c"
    break;

  case 115: /* exponential: Identifier OSP $@3 values CSP  */
#line 492 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 4061 "src-generated/ugbc.tab.c"
    break;

  case 116: /* exponential: SGN OP expr CP  */
#line 496 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 4069 "src-generated/ugbc.tab.c"
    break;

  case 117: /* exponential: ABS OP expr CP  */
#line 499 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 4077 "src-generated/ugbc.tab.c"
    break;

  case 118: /* exponential: TRUE  */
#line 502 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 4086 "src-generated/ugbc.tab.c"
    break;

  case 119: /* exponential: FALSE  */
#line 506 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 4095 "src-generated/ugbc.tab.c"
    break;

  case 120: /* exponential: COLORS  */
#line 510 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 4104 "src-generated/ugbc.tab.c"
    break;

  case 121: /* exponential: PEN COLORS  */
#line 514 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 4113 "src-generated/ugbc.tab.c"
    break;

  case 122: /* exponential: PEN DEFAULT  */
#line 518 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 4122 "src-generated/ugbc.tab.c"
    break;

  case 123: /* exponential: DEFAULT PEN  */
#line 522 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 4131 "src-generated/ugbc.tab.c"
    break;

  case 124: /* exponential: PAPER COLORS  */
#line 526 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 4140 "src-generated/ugbc.tab.c"
    break;

  case 125: /* exponential: PAPER DEFAULT  */
#line 530 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 4149 "src-generated/ugbc.tab.c"
    break;

  case 126: /* exponential: DEFAULT PAPER  */
#line 534 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 4158 "src-generated/ugbc.tab.c"
    break;

  case 127: /* exponential: WIDTH  */
#line 538 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 4166 "src-generated/ugbc.tab.c"
    break;

  case 128: /* exponential: HEIGHT  */
#line 541 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 4174 "src-generated/ugbc.tab.c"
    break;

  case 129: /* exponential: TIMER  */
#line 544 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 4182 "src-generated/ugbc.tab.c"
    break;

  case 130: /* exponential: PEN DOLLAR OP expr CP  */
#line 547 "src/ugbc.y"
                            {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 4190 "src-generated/ugbc.tab.c"
    break;

  case 131: /* exponential: PAPER DOLLAR OP expr CP  */
#line 550 "src/ugbc.y"
                              {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 4198 "src-generated/ugbc.tab.c"
    break;

  case 132: /* exponential: CMOVE DOLLAR OP expr COMMA expr CP  */
#line 553 "src/ugbc.y"
                                         {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4206 "src-generated/ugbc.tab.c"
    break;

  case 133: /* exponential: CUP DOLLAR  */
#line 556 "src/ugbc.y"
                 {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 4214 "src-generated/ugbc.tab.c"
    break;

  case 134: /* exponential: CDOWN DOLLAR  */
#line 559 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 4222 "src-generated/ugbc.tab.c"
    break;

  case 135: /* exponential: CLEFT DOLLAR  */
#line 562 "src/ugbc.y"
                   {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 4230 "src-generated/ugbc.tab.c"
    break;

  case 136: /* exponential: CRIGHT DOLLAR  */
#line 565 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 4238 "src-generated/ugbc.tab.c"
    break;

  case 137: /* exponential: AT DOLLAR OP expr COMMA expr CP  */
#line 568 "src/ugbc.y"
                                      {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4246 "src-generated/ugbc.tab.c"
    break;

  case 138: /* exponential: LOCATE DOLLAR OP expr COMMA expr CP  */
#line 571 "src/ugbc.y"
                                          {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4254 "src-generated/ugbc.tab.c"
    break;

  case 139: /* exponential: TAB DOLLAR  */
#line 574 "src/ugbc.y"
                 {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 4262 "src-generated/ugbc.tab.c"
    break;

  case 140: /* exponential: XCURS  */
#line 577 "src/ugbc.y"
            {
        (yyval.string) = text_get_xcurs( _environment )->name;
    }
#line 4270 "src-generated/ugbc.tab.c"
    break;

  case 141: /* exponential: YCURS  */
#line 580 "src/ugbc.y"
            {
        (yyval.string) = text_get_ycurs( _environment )->name;
    }
#line 4278 "src-generated/ugbc.tab.c"
    break;

  case 142: /* exponential: TEXTADDRESS  */
#line 583 "src/ugbc.y"
                  {
        (yyval.string) = strdup( "TEXTADDRESS" );
    }
#line 4286 "src-generated/ugbc.tab.c"
    break;

  case 143: /* exponential: JOY OP expr CP  */
#line 586 "src/ugbc.y"
                     {
        (yyval.string) = joy( _environment, (yyvsp[-1].string) )->name;
    }
#line 4294 "src-generated/ugbc.tab.c"
    break;

  case 144: /* exponential: JUP OP expr CP  */
#line 589 "src/ugbc.y"
                     {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_UP )->name;
    }
#line 4302 "src-generated/ugbc.tab.c"
    break;

  case 145: /* exponential: JDOWN OP expr CP  */
#line 592 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_DOWN )->name;
    }
#line 4310 "src-generated/ugbc.tab.c"
    break;

  case 146: /* exponential: JLEFT OP expr CP  */
#line 595 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_LEFT )->name;
    }
#line 4318 "src-generated/ugbc.tab.c"
    break;

  case 147: /* exponential: JRIGHT OP expr CP  */
#line 598 "src/ugbc.y"
                        {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_RIGHT )->name;
    }
#line 4326 "src-generated/ugbc.tab.c"
    break;

  case 148: /* exponential: JFIRE OP expr CP  */
#line 601 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_FIRE )->name;
    }
#line 4334 "src-generated/ugbc.tab.c"
    break;

  case 149: /* exponential: FIRE OP expr CP  */
#line 604 "src/ugbc.y"
                      {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_FIRE )->name;
    }
#line 4342 "src-generated/ugbc.tab.c"
    break;

  case 150: /* exponential: JOY COUNT  */
#line 607 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, (yyval.string), JOY_COUNT );
    }
#line 4351 "src-generated/ugbc.tab.c"
    break;

  case 151: /* exponential: JOYCOUNT  */
#line 611 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, (yyval.string), JOY_COUNT );
    }
#line 4360 "src-generated/ugbc.tab.c"
    break;

  case 152: /* exponential: BIT OP expr COMMA expr CP  */
#line 615 "src/ugbc.y"
                                {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4368 "src-generated/ugbc.tab.c"
    break;

  case 153: /* exponential: UP  */
#line 618 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(UP)" )->name;
        variable_store( _environment, (yyval.string), JOY_UP );
    }
#line 4377 "src-generated/ugbc.tab.c"
    break;

  case 154: /* exponential: DOWN  */
#line 622 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(DOWN)" )->name;
        variable_store( _environment, (yyval.string), JOY_DOWN );
    }
#line 4386 "src-generated/ugbc.tab.c"
    break;

  case 155: /* exponential: LEFT  */
#line 626 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(LEFT)" )->name;
        variable_store( _environment, (yyval.string), JOY_LEFT );
    }
#line 4395 "src-generated/ugbc.tab.c"
    break;

  case 156: /* exponential: RIGHT  */
#line 630 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(RIGHT)" )->name;
        variable_store( _environment, (yyval.string), JOY_RIGHT );
    }
#line 4404 "src-generated/ugbc.tab.c"
    break;

  case 157: /* exponential: FIRE  */
#line 634 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(FIRE)" )->name;
        variable_store( _environment, (yyval.string), JOY_FIRE );
    }
#line 4413 "src-generated/ugbc.tab.c"
    break;

  case 158: /* exponential: INKEY  */
#line 638 "src/ugbc.y"
            {
        (yyval.string) = inkey( _environment )->name;
    }
#line 4421 "src-generated/ugbc.tab.c"
    break;

  case 159: /* exponential: SCANCODE  */
#line 641 "src/ugbc.y"
               {
        (yyval.string) = scancode( _environment )->name;
    }
#line 4429 "src-generated/ugbc.tab.c"
    break;

  case 162: /* bank_definition_simple: AT direct_integer  */
#line 649 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4437 "src-generated/ugbc.tab.c"
    break;

  case 163: /* bank_definition_simple: Identifier AT direct_integer  */
#line 652 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4445 "src-generated/ugbc.tab.c"
    break;

  case 164: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 655 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4453 "src-generated/ugbc.tab.c"
    break;

  case 165: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 658 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 4461 "src-generated/ugbc.tab.c"
    break;

  case 166: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 661 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4469 "src-generated/ugbc.tab.c"
    break;

  case 167: /* bank_definition_simple: DATA AT direct_integer  */
#line 664 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 4477 "src-generated/ugbc.tab.c"
    break;

  case 168: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 668 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4485 "src-generated/ugbc.tab.c"
    break;

  case 169: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 671 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 4493 "src-generated/ugbc.tab.c"
    break;

  case 170: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 674 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4501 "src-generated/ugbc.tab.c"
    break;

  case 171: /* bank_definition_simple: CODE AT direct_integer  */
#line 677 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 4509 "src-generated/ugbc.tab.c"
    break;

  case 172: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 681 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4517 "src-generated/ugbc.tab.c"
    break;

  case 173: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 684 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 4525 "src-generated/ugbc.tab.c"
    break;

  case 174: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 687 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4533 "src-generated/ugbc.tab.c"
    break;

  case 175: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 690 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 4541 "src-generated/ugbc.tab.c"
    break;

  case 176: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 694 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4549 "src-generated/ugbc.tab.c"
    break;

  case 177: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 697 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 4557 "src-generated/ugbc.tab.c"
    break;

  case 178: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 700 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4565 "src-generated/ugbc.tab.c"
    break;

  case 179: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 703 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 4573 "src-generated/ugbc.tab.c"
    break;

  case 180: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 709 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4581 "src-generated/ugbc.tab.c"
    break;

  case 181: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 712 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4589 "src-generated/ugbc.tab.c"
    break;

  case 182: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 715 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4597 "src-generated/ugbc.tab.c"
    break;

  case 183: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 718 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 4605 "src-generated/ugbc.tab.c"
    break;

  case 184: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 721 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 4613 "src-generated/ugbc.tab.c"
    break;

  case 187: /* raster_definition_simple: Identifier AT direct_integer  */
#line 730 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 4621 "src-generated/ugbc.tab.c"
    break;

  case 188: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 733 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 4629 "src-generated/ugbc.tab.c"
    break;

  case 189: /* raster_definition_expression: Identifier AT expr  */
#line 738 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4637 "src-generated/ugbc.tab.c"
    break;

  case 190: /* raster_definition_expression: AT expr WITH Identifier  */
#line 741 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4645 "src-generated/ugbc.tab.c"
    break;

  case 193: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 750 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 4653 "src-generated/ugbc.tab.c"
    break;

  case 194: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 753 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 4661 "src-generated/ugbc.tab.c"
    break;

  case 195: /* next_raster_definition_expression: Identifier AT expr  */
#line 758 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 4669 "src-generated/ugbc.tab.c"
    break;

  case 196: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 761 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 4677 "src-generated/ugbc.tab.c"
    break;

  case 199: /* color_definition_simple: BORDER direct_integer  */
#line 770 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 4685 "src-generated/ugbc.tab.c"
    break;

  case 200: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 773 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4693 "src-generated/ugbc.tab.c"
    break;

  case 201: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 776 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4701 "src-generated/ugbc.tab.c"
    break;

  case 202: /* color_definition_expression: BORDER expr  */
#line 781 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 4709 "src-generated/ugbc.tab.c"
    break;

  case 203: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 784 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4717 "src-generated/ugbc.tab.c"
    break;

  case 204: /* color_definition_expression: SPRITE expr TO expr  */
#line 787 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4725 "src-generated/ugbc.tab.c"
    break;

  case 210: /* wait_definition_simple: direct_integer CYCLES  */
#line 801 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 4733 "src-generated/ugbc.tab.c"
    break;

  case 211: /* wait_definition_simple: direct_integer TICKS  */
#line 804 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 4741 "src-generated/ugbc.tab.c"
    break;

  case 212: /* wait_definition_simple: direct_integer milliseconds  */
#line 807 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 4749 "src-generated/ugbc.tab.c"
    break;

  case 213: /* wait_definition_expression: expr CYCLES  */
#line 812 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 4757 "src-generated/ugbc.tab.c"
    break;

  case 214: /* wait_definition_expression: expr TICKS  */
#line 815 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 4765 "src-generated/ugbc.tab.c"
    break;

  case 215: /* wait_definition_expression: expr milliseconds  */
#line 818 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 4773 "src-generated/ugbc.tab.c"
    break;

  case 218: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 828 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 4781 "src-generated/ugbc.tab.c"
    break;

  case 219: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 831 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 4789 "src-generated/ugbc.tab.c"
    break;

  case 220: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 834 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 4797 "src-generated/ugbc.tab.c"
    break;

  case 221: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 837 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 4805 "src-generated/ugbc.tab.c"
    break;

  case 222: /* sprite_definition_simple: direct_integer position OP direct_integer COMMA direct_integer CP  */
#line 840 "src/ugbc.y"
                                                                      {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 4813 "src-generated/ugbc.tab.c"
    break;

  case 223: /* sprite_definition_simple: direct_integer ENABLE  */
#line 843 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 4821 "src-generated/ugbc.tab.c"
    break;

  case 224: /* sprite_definition_simple: direct_integer DISABLE  */
#line 846 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 4829 "src-generated/ugbc.tab.c"
    break;

  case 225: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 849 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4837 "src-generated/ugbc.tab.c"
    break;

  case 226: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 852 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4845 "src-generated/ugbc.tab.c"
    break;

  case 227: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 855 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4853 "src-generated/ugbc.tab.c"
    break;

  case 228: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 858 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 4861 "src-generated/ugbc.tab.c"
    break;

  case 229: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 861 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4869 "src-generated/ugbc.tab.c"
    break;

  case 230: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 864 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4877 "src-generated/ugbc.tab.c"
    break;

  case 231: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 867 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4885 "src-generated/ugbc.tab.c"
    break;

  case 232: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 870 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 4893 "src-generated/ugbc.tab.c"
    break;

  case 233: /* sprite_definition_expression: expr DATA FROM expr  */
#line 875 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 4901 "src-generated/ugbc.tab.c"
    break;

  case 234: /* sprite_definition_expression: expr MULTICOLOR  */
#line 878 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4909 "src-generated/ugbc.tab.c"
    break;

  case 235: /* sprite_definition_expression: expr MONOCOLOR  */
#line 881 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 4917 "src-generated/ugbc.tab.c"
    break;

  case 236: /* sprite_definition_expression: expr COLOR expr  */
#line 884 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 4925 "src-generated/ugbc.tab.c"
    break;

  case 237: /* sprite_definition_expression: expr position OP expr COMMA expr CP  */
#line 887 "src/ugbc.y"
                                        {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 4933 "src-generated/ugbc.tab.c"
    break;

  case 238: /* sprite_definition_expression: expr ENABLE  */
#line 890 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 4941 "src-generated/ugbc.tab.c"
    break;

  case 239: /* sprite_definition_expression: expr DISABLE  */
#line 893 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 4949 "src-generated/ugbc.tab.c"
    break;

  case 240: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 896 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4957 "src-generated/ugbc.tab.c"
    break;

  case 241: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 899 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4965 "src-generated/ugbc.tab.c"
    break;

  case 242: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 902 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4973 "src-generated/ugbc.tab.c"
    break;

  case 243: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 905 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 4981 "src-generated/ugbc.tab.c"
    break;

  case 244: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 908 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4989 "src-generated/ugbc.tab.c"
    break;

  case 245: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 911 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 4997 "src-generated/ugbc.tab.c"
    break;

  case 246: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 914 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 5005 "src-generated/ugbc.tab.c"
    break;

  case 247: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 917 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 5013 "src-generated/ugbc.tab.c"
    break;

  case 250: /* bitmap_definition_simple: AT direct_integer  */
#line 926 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 5021 "src-generated/ugbc.tab.c"
    break;

  case 251: /* bitmap_definition_simple: ENABLE  */
#line 929 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 5029 "src-generated/ugbc.tab.c"
    break;

  case 252: /* bitmap_definition_simple: DISABLE  */
#line 932 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 5037 "src-generated/ugbc.tab.c"
    break;

  case 253: /* bitmap_definition_simple: CLEAR  */
#line 935 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 5045 "src-generated/ugbc.tab.c"
    break;

  case 254: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 938 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 5053 "src-generated/ugbc.tab.c"
    break;

  case 255: /* bitmap_definition_expression: AT expr  */
#line 944 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 5061 "src-generated/ugbc.tab.c"
    break;

  case 256: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 947 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 5069 "src-generated/ugbc.tab.c"
    break;

  case 259: /* textmap_definition_simple: AT direct_integer  */
#line 957 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 5077 "src-generated/ugbc.tab.c"
    break;

  case 260: /* textmap_definition_expression: AT expr  */
#line 962 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 5085 "src-generated/ugbc.tab.c"
    break;

  case 263: /* text_definition_simple: ENABLE  */
#line 971 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 5093 "src-generated/ugbc.tab.c"
    break;

  case 264: /* text_definition_simple: DISABLE  */
#line 974 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 5101 "src-generated/ugbc.tab.c"
    break;

  case 265: /* text_definition_expression: AT expr COMMA expr COMMA expr  */
#line 979 "src/ugbc.y"
                                   {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 5109 "src-generated/ugbc.tab.c"
    break;

  case 266: /* text_definition_expression: expr COMMA expr COMMA expr  */
#line 982 "src/ugbc.y"
                                {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 5117 "src-generated/ugbc.tab.c"
    break;

  case 269: /* tiles_definition_simple: AT direct_integer  */
#line 991 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 5125 "src-generated/ugbc.tab.c"
    break;

  case 270: /* tiles_definition_expression: AT expr  */
#line 996 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 5133 "src-generated/ugbc.tab.c"
    break;

  case 273: /* colormap_definition_simple: AT direct_integer  */
#line 1005 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 5141 "src-generated/ugbc.tab.c"
    break;

  case 274: /* colormap_definition_simple: CLEAR  */
#line 1008 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 5149 "src-generated/ugbc.tab.c"
    break;

  case 275: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 1011 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 5157 "src-generated/ugbc.tab.c"
    break;

  case 276: /* colormap_definition_expression: AT expr  */
#line 1016 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 5165 "src-generated/ugbc.tab.c"
    break;

  case 277: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 1019 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 5173 "src-generated/ugbc.tab.c"
    break;

  case 280: /* screen_definition_simple: ON  */
#line 1029 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 5181 "src-generated/ugbc.tab.c"
    break;

  case 281: /* screen_definition_simple: OFF  */
#line 1032 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 5189 "src-generated/ugbc.tab.c"
    break;

  case 282: /* screen_definition_simple: ROWS direct_integer  */
#line 1035 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 5197 "src-generated/ugbc.tab.c"
    break;

  case 283: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 1038 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 5205 "src-generated/ugbc.tab.c"
    break;

  case 284: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 1041 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 5213 "src-generated/ugbc.tab.c"
    break;

  case 285: /* screen_definition_expression: ROWS expr  */
#line 1046 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 5221 "src-generated/ugbc.tab.c"
    break;

  case 286: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 1049 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 5229 "src-generated/ugbc.tab.c"
    break;

  case 287: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 1052 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 5237 "src-generated/ugbc.tab.c"
    break;

  case 291: /* var_definition_simple: Identifier ON Identifier  */
#line 1061 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 5245 "src-generated/ugbc.tab.c"
    break;

  case 292: /* var_definition_simple: Identifier DOLLAR ON Identifier  */
#line 1064 "src/ugbc.y"
                                    {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 5253 "src-generated/ugbc.tab.c"
    break;

  case 293: /* var_definition_simple: Identifier ON Identifier ASSIGN direct_integer  */
#line 1067 "src/ugbc.y"
                                                   {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 5261 "src-generated/ugbc.tab.c"
    break;

  case 294: /* var_definition_simple: Identifier ON Identifier ASSIGN expr  */
#line 1070 "src/ugbc.y"
                                         {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 5271 "src-generated/ugbc.tab.c"
    break;

  case 295: /* var_definition_simple: Identifier DOLLAR ON Identifier ASSIGN expr  */
#line 1075 "src/ugbc.y"
                                                {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 5281 "src-generated/ugbc.tab.c"
    break;

  case 296: /* goto_definition: Identifier  */
#line 1082 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 5289 "src-generated/ugbc.tab.c"
    break;

  case 297: /* goto_definition: Integer  */
#line 1085 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 5297 "src-generated/ugbc.tab.c"
    break;

  case 298: /* gosub_definition: Identifier  */
#line 1091 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 5305 "src-generated/ugbc.tab.c"
    break;

  case 299: /* gosub_definition: Integer  */
#line 1094 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 5313 "src-generated/ugbc.tab.c"
    break;

  case 301: /* point_definition_simple: AT OP direct_integer COMMA direct_integer CP  */
#line 1103 "src/ugbc.y"
                                                   {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 5321 "src-generated/ugbc.tab.c"
    break;

  case 302: /* point_definition_expression: AT OP expr COMMA expr CP  */
#line 1109 "src/ugbc.y"
                               {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 5329 "src-generated/ugbc.tab.c"
    break;

  case 305: /* ink_definition: expr  */
#line 1118 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 5337 "src-generated/ugbc.tab.c"
    break;

  case 306: /* on_goto_definition: Identifier  */
#line 1123 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 5346 "src-generated/ugbc.tab.c"
    break;

  case 307: /* $@4: %empty  */
#line 1127 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 5354 "src-generated/ugbc.tab.c"
    break;

  case 309: /* on_gosub_definition: Identifier  */
#line 1132 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 5363 "src-generated/ugbc.tab.c"
    break;

  case 310: /* $@5: %empty  */
#line 1136 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 5371 "src-generated/ugbc.tab.c"
    break;

  case 312: /* on_proc_definition: Identifier  */
#line 1141 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 5380 "src-generated/ugbc.tab.c"
    break;

  case 313: /* $@6: %empty  */
#line 1145 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 5388 "src-generated/ugbc.tab.c"
    break;

  case 315: /* $@7: %empty  */
#line 1150 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 5396 "src-generated/ugbc.tab.c"
    break;

  case 317: /* $@8: %empty  */
#line 1153 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 5404 "src-generated/ugbc.tab.c"
    break;

  case 319: /* $@9: %empty  */
#line 1156 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 5412 "src-generated/ugbc.tab.c"
    break;

  case 321: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1161 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 5420 "src-generated/ugbc.tab.c"
    break;

  case 322: /* every_definition: ON  */
#line 1164 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 5428 "src-generated/ugbc.tab.c"
    break;

  case 323: /* every_definition: OFF  */
#line 1167 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 5436 "src-generated/ugbc.tab.c"
    break;

  case 324: /* add_definition: Identifier COMMA expr  */
#line 1172 "src/ugbc.y"
                          {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 5444 "src-generated/ugbc.tab.c"
    break;

  case 325: /* add_definition: Identifier COMMA expr COMMA expr TO expr  */
#line 1175 "src/ugbc.y"
                                               {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5452 "src-generated/ugbc.tab.c"
    break;

  case 326: /* dimensions: Integer  */
#line 1181 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5461 "src-generated/ugbc.tab.c"
    break;

  case 327: /* dimensions: Integer COMMA dimensions  */
#line 1185 "src/ugbc.y"
                               {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 5470 "src-generated/ugbc.tab.c"
    break;

  case 328: /* datatype: BYTE  */
#line 1192 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 5478 "src-generated/ugbc.tab.c"
    break;

  case 329: /* datatype: SIGNED BYTE  */
#line 1195 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 5486 "src-generated/ugbc.tab.c"
    break;

  case 330: /* datatype: WORD  */
#line 1198 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 5494 "src-generated/ugbc.tab.c"
    break;

  case 331: /* datatype: SIGNED WORD  */
#line 1201 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 5502 "src-generated/ugbc.tab.c"
    break;

  case 332: /* datatype: DWORD  */
#line 1204 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 5510 "src-generated/ugbc.tab.c"
    break;

  case 333: /* datatype: SIGNED DWORD  */
#line 1207 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 5518 "src-generated/ugbc.tab.c"
    break;

  case 334: /* datatype: ADDRESS  */
#line 1210 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 5526 "src-generated/ugbc.tab.c"
    break;

  case 335: /* datatype: POSITION  */
#line 1213 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 5534 "src-generated/ugbc.tab.c"
    break;

  case 336: /* datatype: COLOR  */
#line 1216 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 5542 "src-generated/ugbc.tab.c"
    break;

  case 337: /* datatype: STRING  */
#line 1219 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 5550 "src-generated/ugbc.tab.c"
    break;

  case 338: /* $@10: %empty  */
#line 1224 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5559 "src-generated/ugbc.tab.c"
    break;

  case 339: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1227 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 5569 "src-generated/ugbc.tab.c"
    break;

  case 340: /* $@11: %empty  */
#line 1232 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5578 "src-generated/ugbc.tab.c"
    break;

  case 341: /* dim_definition: Identifier $@11 DOLLAR OP dimensions CP  */
#line 1235 "src/ugbc.y"
                                {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 5588 "src-generated/ugbc.tab.c"
    break;

  case 342: /* $@12: %empty  */
#line 1240 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 5597 "src-generated/ugbc.tab.c"
    break;

  case 343: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1243 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 5607 "src-generated/ugbc.tab.c"
    break;

  case 346: /* indexes: expr  */
#line 1256 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5616 "src-generated/ugbc.tab.c"
    break;

  case 347: /* indexes: expr COMMA indexes  */
#line 1260 "src/ugbc.y"
                         {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 5625 "src-generated/ugbc.tab.c"
    break;

  case 348: /* parameters: Identifier  */
#line 1267 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5635 "src-generated/ugbc.tab.c"
    break;

  case 349: /* parameters: Identifier DOLLAR  */
#line 1272 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5645 "src-generated/ugbc.tab.c"
    break;

  case 350: /* parameters: Identifier AS datatype  */
#line 1277 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5655 "src-generated/ugbc.tab.c"
    break;

  case 351: /* parameters: Identifier COMMA parameters  */
#line 1282 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5665 "src-generated/ugbc.tab.c"
    break;

  case 352: /* parameters: Identifier DOLLAR COMMA parameters  */
#line 1287 "src/ugbc.y"
                                         {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5675 "src-generated/ugbc.tab.c"
    break;

  case 353: /* parameters: Identifier AS datatype COMMA parameters  */
#line 1292 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5685 "src-generated/ugbc.tab.c"
    break;

  case 354: /* parameters_expr: Identifier  */
#line 1300 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5695 "src-generated/ugbc.tab.c"
    break;

  case 355: /* parameters_expr: Identifier DOLLAR  */
#line 1305 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5705 "src-generated/ugbc.tab.c"
    break;

  case 356: /* parameters_expr: Identifier AS datatype  */
#line 1310 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5715 "src-generated/ugbc.tab.c"
    break;

  case 357: /* parameters_expr: Identifier COMMA parameters_expr  */
#line 1315 "src/ugbc.y"
                                       {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5725 "src-generated/ugbc.tab.c"
    break;

  case 358: /* parameters_expr: Identifier DOLLAR COMMA parameters_expr  */
#line 1320 "src/ugbc.y"
                                              {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5735 "src-generated/ugbc.tab.c"
    break;

  case 359: /* parameters_expr: Identifier AS datatype COMMA parameters_expr  */
#line 1325 "src/ugbc.y"
                                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5745 "src-generated/ugbc.tab.c"
    break;

  case 360: /* parameters_expr: String  */
#line 1330 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5754 "src-generated/ugbc.tab.c"
    break;

  case 361: /* parameters_expr: String COMMA parameters_expr  */
#line 1334 "src/ugbc.y"
                                   {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5763 "src-generated/ugbc.tab.c"
    break;

  case 362: /* values: expr  */
#line 1341 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5772 "src-generated/ugbc.tab.c"
    break;

  case 363: /* values: expr COMMA values  */
#line 1345 "src/ugbc.y"
                        {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 5781 "src-generated/ugbc.tab.c"
    break;

  case 364: /* print_definition: expr  */
#line 1352 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 5789 "src-generated/ugbc.tab.c"
    break;

  case 365: /* print_definition: expr COMMA  */
#line 1355 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5798 "src-generated/ugbc.tab.c"
    break;

  case 366: /* print_definition: expr SEMICOLON  */
#line 1359 "src/ugbc.y"
                   {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5806 "src-generated/ugbc.tab.c"
    break;

  case 367: /* $@13: %empty  */
#line 1362 "src/ugbc.y"
               {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 5815 "src-generated/ugbc.tab.c"
    break;

  case 369: /* $@14: %empty  */
#line 1366 "src/ugbc.y"
                    {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 5823 "src-generated/ugbc.tab.c"
    break;

  case 371: /* writing_mode_definition: REPLACE  */
#line 1372 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 5832 "src-generated/ugbc.tab.c"
    break;

  case 372: /* writing_mode_definition: OR  */
#line 1376 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 5841 "src-generated/ugbc.tab.c"
    break;

  case 373: /* writing_mode_definition: XOR  */
#line 1380 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 5850 "src-generated/ugbc.tab.c"
    break;

  case 374: /* writing_mode_definition: AND  */
#line 1384 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 5859 "src-generated/ugbc.tab.c"
    break;

  case 375: /* writing_mode_definition: IGNORE  */
#line 1388 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 5868 "src-generated/ugbc.tab.c"
    break;

  case 376: /* writing_part_definition: NORMAL  */
#line 1395 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 5877 "src-generated/ugbc.tab.c"
    break;

  case 377: /* writing_part_definition: PAPER  */
#line 1399 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5886 "src-generated/ugbc.tab.c"
    break;

  case 378: /* writing_part_definition: PAPER ONLY  */
#line 1403 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 5895 "src-generated/ugbc.tab.c"
    break;

  case 379: /* writing_part_definition: PEN  */
#line 1407 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5904 "src-generated/ugbc.tab.c"
    break;

  case 380: /* writing_part_definition: PEN ONLY  */
#line 1411 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 5913 "src-generated/ugbc.tab.c"
    break;

  case 381: /* writing_definition: writing_mode_definition COMMA writing_part_definition  */
#line 1418 "src/ugbc.y"
                                                          {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5921 "src-generated/ugbc.tab.c"
    break;

  case 382: /* locate_definition: COMMA expr  */
#line 1424 "src/ugbc.y"
                {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 5929 "src-generated/ugbc.tab.c"
    break;

  case 383: /* locate_definition: expr COMMA  */
#line 1427 "src/ugbc.y"
                 {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 5937 "src-generated/ugbc.tab.c"
    break;

  case 384: /* locate_definition: expr COMMA expr  */
#line 1430 "src/ugbc.y"
                      {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5945 "src-generated/ugbc.tab.c"
    break;

  case 385: /* cmove_definition: COMMA expr  */
#line 1436 "src/ugbc.y"
                {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 5953 "src-generated/ugbc.tab.c"
    break;

  case 386: /* cmove_definition: expr COMMA  */
#line 1439 "src/ugbc.y"
                 {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 5961 "src-generated/ugbc.tab.c"
    break;

  case 387: /* cmove_definition: expr COMMA expr  */
#line 1442 "src/ugbc.y"
                      {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5969 "src-generated/ugbc.tab.c"
    break;

  case 388: /* hscroll_definition: LEFT  */
#line 1448 "src/ugbc.y"
         {
        text_hscroll_line( _environment, -1 );
    }
#line 5977 "src-generated/ugbc.tab.c"
    break;

  case 389: /* hscroll_definition: SCREEN LEFT  */
#line 1451 "src/ugbc.y"
                  {
        text_hscroll_screen( _environment, -1 );
    }
#line 5985 "src-generated/ugbc.tab.c"
    break;

  case 390: /* hscroll_definition: RIGHT  */
#line 1454 "src/ugbc.y"
            {
        text_hscroll_line( _environment, 1 );
    }
#line 5993 "src-generated/ugbc.tab.c"
    break;

  case 391: /* hscroll_definition: SCREEN RIGHT  */
#line 1457 "src/ugbc.y"
                   {
        text_hscroll_screen( _environment, 1 );
    }
#line 6001 "src-generated/ugbc.tab.c"
    break;

  case 392: /* vscroll_definition: SCREEN UP  */
#line 1463 "src/ugbc.y"
                {
        text_vscroll_screen( _environment, -1 );
    }
#line 6009 "src-generated/ugbc.tab.c"
    break;

  case 393: /* vscroll_definition: SCREEN DOWN  */
#line 1466 "src/ugbc.y"
                  {
        text_vscroll_screen( _environment, 1 );
    }
#line 6017 "src-generated/ugbc.tab.c"
    break;

  case 409: /* statement: TEXTADDRESS ASSIGN expr  */
#line 1487 "src/ugbc.y"
                            {
      variable_move( _environment, (yyvsp[0].string), "ADDRESS" );
  }
#line 6025 "src-generated/ugbc.tab.c"
    break;

  case 414: /* statement: MEMORIZE  */
#line 1494 "src/ugbc.y"
             {
      text_memorize( _environment );
  }
#line 6033 "src-generated/ugbc.tab.c"
    break;

  case 415: /* statement: REMEMBER  */
#line 1497 "src/ugbc.y"
             {
      text_remember( _environment );
  }
#line 6041 "src-generated/ugbc.tab.c"
    break;

  case 419: /* statement: CUP  */
#line 1503 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 6049 "src-generated/ugbc.tab.c"
    break;

  case 420: /* statement: CDOWN  */
#line 1506 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 6057 "src-generated/ugbc.tab.c"
    break;

  case 421: /* statement: CLEFT  */
#line 1509 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 6065 "src-generated/ugbc.tab.c"
    break;

  case 422: /* statement: CRIGHT  */
#line 1512 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 6073 "src-generated/ugbc.tab.c"
    break;

  case 423: /* statement: CLINE  */
#line 1515 "src/ugbc.y"
          {
      text_cline( _environment, NULL );
  }
#line 6081 "src-generated/ugbc.tab.c"
    break;

  case 424: /* statement: CLINE expr  */
#line 1518 "src/ugbc.y"
               {
      text_cline( _environment, (yyvsp[0].string) );
  }
#line 6089 "src-generated/ugbc.tab.c"
    break;

  case 425: /* statement: SET TAB expr  */
#line 1521 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 6097 "src-generated/ugbc.tab.c"
    break;

  case 426: /* statement: CENTER expr  */
#line 1524 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 6105 "src-generated/ugbc.tab.c"
    break;

  case 427: /* statement: CENTRE expr  */
#line 1527 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 6113 "src-generated/ugbc.tab.c"
    break;

  case 428: /* statement: CLS  */
#line 1530 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 6121 "src-generated/ugbc.tab.c"
    break;

  case 429: /* statement: HOME  */
#line 1533 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 6129 "src-generated/ugbc.tab.c"
    break;

  case 430: /* statement: INC Identifier  */
#line 1536 "src/ugbc.y"
                   {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 6137 "src-generated/ugbc.tab.c"
    break;

  case 431: /* statement: DEC Identifier  */
#line 1539 "src/ugbc.y"
                   {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 6145 "src-generated/ugbc.tab.c"
    break;

  case 432: /* statement: RANDOMIZE  */
#line 1542 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 6153 "src-generated/ugbc.tab.c"
    break;

  case 433: /* statement: RANDOMIZE expr  */
#line 1545 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 6161 "src-generated/ugbc.tab.c"
    break;

  case 434: /* statement: IF expr THEN  */
#line 1548 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 6169 "src-generated/ugbc.tab.c"
    break;

  case 435: /* statement: ELSE  */
#line 1551 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 6177 "src-generated/ugbc.tab.c"
    break;

  case 436: /* statement: ELSE IF expr THEN  */
#line 1554 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 6185 "src-generated/ugbc.tab.c"
    break;

  case 437: /* statement: ENDIF  */
#line 1557 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 6193 "src-generated/ugbc.tab.c"
    break;

  case 438: /* statement: DO  */
#line 1560 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 6201 "src-generated/ugbc.tab.c"
    break;

  case 439: /* statement: LOOP  */
#line 1563 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 6209 "src-generated/ugbc.tab.c"
    break;

  case 440: /* $@15: %empty  */
#line 1566 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 6217 "src-generated/ugbc.tab.c"
    break;

  case 441: /* statement: WHILE $@15 expr  */
#line 1568 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 6225 "src-generated/ugbc.tab.c"
    break;

  case 442: /* statement: WEND  */
#line 1571 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 6233 "src-generated/ugbc.tab.c"
    break;

  case 443: /* statement: REPEAT  */
#line 1574 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 6241 "src-generated/ugbc.tab.c"
    break;

  case 444: /* statement: UNTIL expr  */
#line 1577 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 6249 "src-generated/ugbc.tab.c"
    break;

  case 445: /* statement: EXIT  */
#line 1580 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 6257 "src-generated/ugbc.tab.c"
    break;

  case 446: /* statement: EXIT PROC  */
#line 1583 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 6265 "src-generated/ugbc.tab.c"
    break;

  case 447: /* statement: POP PROC  */
#line 1586 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 6273 "src-generated/ugbc.tab.c"
    break;

  case 448: /* statement: EXIT IF expr  */
#line 1589 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 6281 "src-generated/ugbc.tab.c"
    break;

  case 449: /* statement: EXIT Integer  */
#line 1592 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 6289 "src-generated/ugbc.tab.c"
    break;

  case 450: /* statement: EXIT direct_integer  */
#line 1595 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 6297 "src-generated/ugbc.tab.c"
    break;

  case 451: /* statement: EXIT IF expr COMMA Integer  */
#line 1598 "src/ugbc.y"
                               {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 6305 "src-generated/ugbc.tab.c"
    break;

  case 452: /* statement: EXIT IF expr COMMA direct_integer  */
#line 1601 "src/ugbc.y"
                                      {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 6313 "src-generated/ugbc.tab.c"
    break;

  case 453: /* statement: FOR Identifier ASSIGN expr TO expr  */
#line 1604 "src/ugbc.y"
                                       {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 6321 "src-generated/ugbc.tab.c"
    break;

  case 454: /* statement: NEXT  */
#line 1607 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 6329 "src-generated/ugbc.tab.c"
    break;

  case 455: /* statement: PROCEDURE Identifier  */
#line 1610 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 6338 "src-generated/ugbc.tab.c"
    break;

  case 456: /* $@16: %empty  */
#line 1614 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6346 "src-generated/ugbc.tab.c"
    break;

  case 457: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1616 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6354 "src-generated/ugbc.tab.c"
    break;

  case 458: /* statement: SHARED parameters_expr  */
#line 1619 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 6362 "src-generated/ugbc.tab.c"
    break;

  case 459: /* statement: GLOBAL parameters_expr  */
#line 1622 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 6370 "src-generated/ugbc.tab.c"
    break;

  case 460: /* statement: END PROC  */
#line 1625 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 6378 "src-generated/ugbc.tab.c"
    break;

  case 461: /* statement: END PROC OSP expr CSP  */
#line 1628 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6386 "src-generated/ugbc.tab.c"
    break;

  case 462: /* statement: FOR Identifier ASSIGN expr TO expr STEP expr  */
#line 1631 "src/ugbc.y"
                                                 {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 6394 "src-generated/ugbc.tab.c"
    break;

  case 463: /* statement: Identifier " "  */
#line 1634 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 6403 "src-generated/ugbc.tab.c"
    break;

  case 464: /* statement: PROC Identifier  */
#line 1638 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6412 "src-generated/ugbc.tab.c"
    break;

  case 465: /* statement: CALL Identifier  */
#line 1642 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 6421 "src-generated/ugbc.tab.c"
    break;

  case 466: /* $@17: %empty  */
#line 1646 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6429 "src-generated/ugbc.tab.c"
    break;

  case 467: /* statement: Identifier OSP $@17 values CSP  */
#line 1648 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6437 "src-generated/ugbc.tab.c"
    break;

  case 468: /* $@18: %empty  */
#line 1651 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6445 "src-generated/ugbc.tab.c"
    break;

  case 469: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1653 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6453 "src-generated/ugbc.tab.c"
    break;

  case 470: /* $@19: %empty  */
#line 1656 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 6461 "src-generated/ugbc.tab.c"
    break;

  case 471: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1658 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 6469 "src-generated/ugbc.tab.c"
    break;

  case 472: /* statement: PEN expr  */
#line 1661 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 6477 "src-generated/ugbc.tab.c"
    break;

  case 473: /* statement: PAPER expr  */
#line 1664 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 6485 "src-generated/ugbc.tab.c"
    break;

  case 474: /* statement: INVERSE ON  */
#line 1667 "src/ugbc.y"
               {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 6493 "src-generated/ugbc.tab.c"
    break;

  case 475: /* statement: INVERSE OFF  */
#line 1670 "src/ugbc.y"
                {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 6501 "src-generated/ugbc.tab.c"
    break;

  case 477: /* statement: Identifier COLON  */
#line 1674 "src/ugbc.y"
                     {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 6509 "src-generated/ugbc.tab.c"
    break;

  case 478: /* statement: BEG GAMELOOP  */
#line 1677 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 6517 "src-generated/ugbc.tab.c"
    break;

  case 479: /* statement: END GAMELOOP  */
#line 1680 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 6525 "src-generated/ugbc.tab.c"
    break;

  case 480: /* statement: GRAPHIC  */
#line 1683 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 6533 "src-generated/ugbc.tab.c"
    break;

  case 481: /* statement: HALT  */
#line 1686 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 6541 "src-generated/ugbc.tab.c"
    break;

  case 482: /* statement: END  */
#line 1689 "src/ugbc.y"
        {
      end( _environment );
  }
#line 6549 "src-generated/ugbc.tab.c"
    break;

  case 487: /* statement: RETURN  */
#line 1696 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 6557 "src-generated/ugbc.tab.c"
    break;

  case 488: /* statement: RETURN expr  */
#line 1699 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 6565 "src-generated/ugbc.tab.c"
    break;

  case 489: /* statement: POP  */
#line 1702 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 6573 "src-generated/ugbc.tab.c"
    break;

  case 490: /* statement: DONE  */
#line 1705 "src/ugbc.y"
          {
      return 0;
  }
#line 6581 "src-generated/ugbc.tab.c"
    break;

  case 491: /* statement: LEFT OP expr COMMA expr CP ASSIGN expr  */
#line 1708 "src/ugbc.y"
                                           {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6589 "src-generated/ugbc.tab.c"
    break;

  case 492: /* statement: RIGHT OP expr COMMA expr CP ASSIGN expr  */
#line 1711 "src/ugbc.y"
                                            {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6597 "src-generated/ugbc.tab.c"
    break;

  case 493: /* statement: MID OP expr COMMA expr CP ASSIGN expr  */
#line 1714 "src/ugbc.y"
                                          {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 6605 "src-generated/ugbc.tab.c"
    break;

  case 494: /* statement: MID OP expr COMMA expr COMMA expr CP ASSIGN expr  */
#line 1717 "src/ugbc.y"
                                                     {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6613 "src-generated/ugbc.tab.c"
    break;

  case 496: /* statement: Identifier ASSIGN expr  */
#line 1721 "src/ugbc.y"
                           {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 6627 "src-generated/ugbc.tab.c"
    break;

  case 497: /* statement: Identifier DOLLAR ASSIGN expr  */
#line 1730 "src/ugbc.y"
                                  {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 6641 "src-generated/ugbc.tab.c"
    break;

  case 498: /* $@20: %empty  */
#line 1739 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6650 "src-generated/ugbc.tab.c"
    break;

  case 499: /* statement: Identifier $@20 OP indexes CP ASSIGN expr  */
#line 1743 "src/ugbc.y"
                                {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 6663 "src-generated/ugbc.tab.c"
    break;

  case 500: /* $@21: %empty  */
#line 1751 "src/ugbc.y"
                      {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6672 "src-generated/ugbc.tab.c"
    break;

  case 501: /* statement: Identifier DOLLAR $@21 OP indexes CP ASSIGN expr  */
#line 1754 "src/ugbc.y"
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
#line 6691 "src-generated/ugbc.tab.c"
    break;

  case 502: /* $@22: %empty  */
#line 1768 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 6700 "src-generated/ugbc.tab.c"
    break;

  case 503: /* statement: Identifier $@22 datatype OP indexes CP ASSIGN expr  */
#line 1771 "src/ugbc.y"
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
#line 6719 "src-generated/ugbc.tab.c"
    break;

  case 504: /* statement: DEBUG expr  */
#line 1785 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 6727 "src-generated/ugbc.tab.c"
    break;

  case 507: /* statements_no_linenumbers: statement  */
#line 1793 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 6733 "src-generated/ugbc.tab.c"
    break;

  case 508: /* $@23: %empty  */
#line 1794 "src/ugbc.y"
                      { ((Environment *)_environment)->yylineno = yylineno; }
#line 6739 "src-generated/ugbc.tab.c"
    break;

  case 510: /* $@24: %empty  */
#line 1798 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 6747 "src-generated/ugbc.tab.c"
    break;

  case 511: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 1800 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 6755 "src-generated/ugbc.tab.c"
    break;

  case 512: /* $@25: %empty  */
#line 1805 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 6763 "src-generated/ugbc.tab.c"
    break;

  case 518: /* $@26: %empty  */
#line 1815 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 6769 "src-generated/ugbc.tab.c"
    break;


#line 6773 "src-generated/ugbc.tab.c"

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

#line 1817 "src/ugbc.y"


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

