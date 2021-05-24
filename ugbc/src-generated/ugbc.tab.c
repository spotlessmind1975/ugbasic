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
  YYSYMBOL_MOD = 133,                      /* MOD  */
  YYSYMBOL_ADD = 134,                      /* ADD  */
  YYSYMBOL_MIN = 135,                      /* MIN  */
  YYSYMBOL_MAX = 136,                      /* MAX  */
  YYSYMBOL_SGN = 137,                      /* SGN  */
  YYSYMBOL_SIGNED = 138,                   /* SIGNED  */
  YYSYMBOL_ABS = 139,                      /* ABS  */
  YYSYMBOL_RND = 140,                      /* RND  */
  YYSYMBOL_COLORS = 141,                   /* COLORS  */
  YYSYMBOL_INK = 142,                      /* INK  */
  YYSYMBOL_TIMER = 143,                    /* TIMER  */
  YYSYMBOL_POWERING = 144,                 /* POWERING  */
  YYSYMBOL_DIM = 145,                      /* DIM  */
  YYSYMBOL_ADDRESS = 146,                  /* ADDRESS  */
  YYSYMBOL_PROC = 147,                     /* PROC  */
  YYSYMBOL_PROCEDURE = 148,                /* PROCEDURE  */
  YYSYMBOL_CALL = 149,                     /* CALL  */
  YYSYMBOL_OSP = 150,                      /* OSP  */
  YYSYMBOL_CSP = 151,                      /* CSP  */
  YYSYMBOL_SHARED = 152,                   /* SHARED  */
  YYSYMBOL_MILLISECOND = 153,              /* MILLISECOND  */
  YYSYMBOL_MILLISECONDS = 154,             /* MILLISECONDS  */
  YYSYMBOL_TICKS = 155,                    /* TICKS  */
  YYSYMBOL_GLOBAL = 156,                   /* GLOBAL  */
  YYSYMBOL_PARAM = 157,                    /* PARAM  */
  YYSYMBOL_PRINT = 158,                    /* PRINT  */
  YYSYMBOL_DEFAULT = 159,                  /* DEFAULT  */
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
  YYSYMBOL_TEXTADDRESS = 188,              /* TEXTADDRESS  */
  YYSYMBOL_JOY = 189,                      /* JOY  */
  YYSYMBOL_BIN = 190,                      /* BIN  */
  YYSYMBOL_BIT = 191,                      /* BIT  */
  YYSYMBOL_COUNT = 192,                    /* COUNT  */
  YYSYMBOL_JOYCOUNT = 193,                 /* JOYCOUNT  */
  YYSYMBOL_FIRE = 194,                     /* FIRE  */
  YYSYMBOL_JUP = 195,                      /* JUP  */
  YYSYMBOL_JDOWN = 196,                    /* JDOWN  */
  YYSYMBOL_JLEFT = 197,                    /* JLEFT  */
  YYSYMBOL_JRIGHT = 198,                   /* JRIGHT  */
  YYSYMBOL_JFIRE = 199,                    /* JFIRE  */
  YYSYMBOL_INKEY = 200,                    /* INKEY  */
  YYSYMBOL_SCANCODE = 201,                 /* SCANCODE  */
  YYSYMBOL_SCAN = 202,                     /* SCAN  */
  YYSYMBOL_SHIFT = 203,                    /* SHIFT  */
  YYSYMBOL_SCANSHIFT = 204,                /* SCANSHIFT  */
  YYSYMBOL_BOTH = 205,                     /* BOTH  */
  YYSYMBOL_SHIFTS = 206,                   /* SHIFTS  */
  YYSYMBOL_NONE = 207,                     /* NONE  */
  YYSYMBOL_LETTER = 208,                   /* LETTER  */
  YYSYMBOL_ASTERISK = 209,                 /* ASTERISK  */
  YYSYMBOL_COLON = 210,                    /* COLON  */
  YYSYMBOL_COMMA = 211,                    /* COMMA  */
  YYSYMBOL_COMMODORE = 212,                /* COMMODORE  */
  YYSYMBOL_CONTROL = 213,                  /* CONTROL  */
  YYSYMBOL_CRSR = 214,                     /* CRSR  */
  YYSYMBOL_CURSOR = 215,                   /* CURSOR  */
  YYSYMBOL_DELETE = 216,                   /* DELETE  */
  YYSYMBOL_EQUAL = 217,                    /* EQUAL  */
  YYSYMBOL_FUNCTION = 218,                 /* FUNCTION  */
  YYSYMBOL_INSERT = 219,                   /* INSERT  */
  YYSYMBOL_ARROW = 220,                    /* ARROW  */
  YYSYMBOL_MINUS = 221,                    /* MINUS  */
  YYSYMBOL_PERIOD = 222,                   /* PERIOD  */
  YYSYMBOL_PLUS = 223,                     /* PLUS  */
  YYSYMBOL_POUND = 224,                    /* POUND  */
  YYSYMBOL_RUNSTOP = 225,                  /* RUNSTOP  */
  YYSYMBOL_RUN = 226,                      /* RUN  */
  YYSYMBOL_STOP = 227,                     /* STOP  */
  YYSYMBOL_SEMICOLON = 228,                /* SEMICOLON  */
  YYSYMBOL_SLASH = 229,                    /* SLASH  */
  YYSYMBOL_KEY = 230,                      /* KEY  */
  YYSYMBOL_STATE = 231,                    /* STATE  */
  YYSYMBOL_KEYSTATE = 232,                 /* KEYSTATE  */
  YYSYMBOL_A = 233,                        /* A  */
  YYSYMBOL_B = 234,                        /* B  */
  YYSYMBOL_C = 235,                        /* C  */
  YYSYMBOL_D = 236,                        /* D  */
  YYSYMBOL_E = 237,                        /* E  */
  YYSYMBOL_F = 238,                        /* F  */
  YYSYMBOL_G = 239,                        /* G  */
  YYSYMBOL_H = 240,                        /* H  */
  YYSYMBOL_I = 241,                        /* I  */
  YYSYMBOL_J = 242,                        /* J  */
  YYSYMBOL_K = 243,                        /* K  */
  YYSYMBOL_L = 244,                        /* L  */
  YYSYMBOL_M = 245,                        /* M  */
  YYSYMBOL_N = 246,                        /* N  */
  YYSYMBOL_O = 247,                        /* O  */
  YYSYMBOL_P = 248,                        /* P  */
  YYSYMBOL_Q = 249,                        /* Q  */
  YYSYMBOL_R = 250,                        /* R  */
  YYSYMBOL_S = 251,                        /* S  */
  YYSYMBOL_T = 252,                        /* T  */
  YYSYMBOL_U = 253,                        /* U  */
  YYSYMBOL_V = 254,                        /* V  */
  YYSYMBOL_X = 255,                        /* X  */
  YYSYMBOL_Y = 256,                        /* Y  */
  YYSYMBOL_W = 257,                        /* W  */
  YYSYMBOL_Z = 258,                        /* Z  */
  YYSYMBOL_F1 = 259,                       /* F1  */
  YYSYMBOL_F2 = 260,                       /* F2  */
  YYSYMBOL_F3 = 261,                       /* F3  */
  YYSYMBOL_F4 = 262,                       /* F4  */
  YYSYMBOL_F5 = 263,                       /* F5  */
  YYSYMBOL_F6 = 264,                       /* F6  */
  YYSYMBOL_F7 = 265,                       /* F7  */
  YYSYMBOL_F8 = 266,                       /* F8  */
  YYSYMBOL_BLACK = 267,                    /* BLACK  */
  YYSYMBOL_WHITE = 268,                    /* WHITE  */
  YYSYMBOL_RED = 269,                      /* RED  */
  YYSYMBOL_CYAN = 270,                     /* CYAN  */
  YYSYMBOL_VIOLET = 271,                   /* VIOLET  */
  YYSYMBOL_GREEN = 272,                    /* GREEN  */
  YYSYMBOL_BLUE = 273,                     /* BLUE  */
  YYSYMBOL_YELLOW = 274,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 275,                   /* ORANGE  */
  YYSYMBOL_BROWN = 276,                    /* BROWN  */
  YYSYMBOL_LIGHT = 277,                    /* LIGHT  */
  YYSYMBOL_DARK = 278,                     /* DARK  */
  YYSYMBOL_GREY = 279,                     /* GREY  */
  YYSYMBOL_GRAY = 280,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 281,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 282,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 283,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 284,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 285,                /* TURQUOISE  */
  YYSYMBOL_TAN = 286,                      /* TAN  */
  YYSYMBOL_PINK = 287,                     /* PINK  */
  YYSYMBOL_PEACH = 288,                    /* PEACH  */
  YYSYMBOL_OLIVE = 289,                    /* OLIVE  */
  YYSYMBOL_Identifier = 290,               /* Identifier  */
  YYSYMBOL_String = 291,                   /* String  */
  YYSYMBOL_Integer = 292,                  /* Integer  */
  YYSYMBOL_293_0_ = 293,                   /* "0"  */
  YYSYMBOL_294_1_ = 294,                   /* "1"  */
  YYSYMBOL_295_2_ = 295,                   /* "2"  */
  YYSYMBOL_296_3_ = 296,                   /* "3"  */
  YYSYMBOL_297_4_ = 297,                   /* "4"  */
  YYSYMBOL_298_5_ = 298,                   /* "5"  */
  YYSYMBOL_299_6_ = 299,                   /* "6"  */
  YYSYMBOL_300_7_ = 300,                   /* "7"  */
  YYSYMBOL_301_8_ = 301,                   /* "8"  */
  YYSYMBOL_302_9_ = 302,                   /* "9"  */
  YYSYMBOL_303_ = 303,                     /* " "  */
  YYSYMBOL_YYACCEPT = 304,                 /* $accept  */
  YYSYMBOL_expr = 305,                     /* expr  */
  YYSYMBOL_expr_math = 306,                /* expr_math  */
  YYSYMBOL_term = 307,                     /* term  */
  YYSYMBOL_modula = 308,                   /* modula  */
  YYSYMBOL_factor = 309,                   /* factor  */
  YYSYMBOL_direct_integer = 310,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 311, /* random_definition_simple  */
  YYSYMBOL_random_definition = 312,        /* random_definition  */
  YYSYMBOL_color_enumeration = 313,        /* color_enumeration  */
  YYSYMBOL_key_scancode_alphadigit = 314,  /* key_scancode_alphadigit  */
  YYSYMBOL_key_scancode_function_digit = 315, /* key_scancode_function_digit  */
  YYSYMBOL_key_scancode_definition = 316,  /* key_scancode_definition  */
  YYSYMBOL_exponential = 317,              /* exponential  */
  YYSYMBOL_318_1 = 318,                    /* $@1  */
  YYSYMBOL_319_2 = 319,                    /* $@2  */
  YYSYMBOL_320_3 = 320,                    /* $@3  */
  YYSYMBOL_position = 321,                 /* position  */
  YYSYMBOL_bank_definition_simple = 322,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 323, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 324,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 325, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 326, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 327,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 328, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 329, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 330,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 331,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 332, /* color_definition_expression  */
  YYSYMBOL_color_definition = 333,         /* color_definition  */
  YYSYMBOL_milliseconds = 334,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 335,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 336, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 337,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 338, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 339, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 340,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 341, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 342, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 343,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 344, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 345, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 346,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 347,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 348, /* text_definition_expression  */
  YYSYMBOL_text_definition = 349,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 350,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 351, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 352,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 353, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 354, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 355,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 356, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 357, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 358,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 359,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 360,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 361,         /* gosub_definition  */
  YYSYMBOL_var_definition = 362,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 363,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 364, /* point_definition_expression  */
  YYSYMBOL_point_definition = 365,         /* point_definition  */
  YYSYMBOL_ink_definition = 366,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 367,       /* on_goto_definition  */
  YYSYMBOL_368_4 = 368,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 369,      /* on_gosub_definition  */
  YYSYMBOL_370_5 = 370,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 371,       /* on_proc_definition  */
  YYSYMBOL_372_6 = 372,                    /* $@6  */
  YYSYMBOL_on_definition = 373,            /* on_definition  */
  YYSYMBOL_374_7 = 374,                    /* $@7  */
  YYSYMBOL_375_8 = 375,                    /* $@8  */
  YYSYMBOL_376_9 = 376,                    /* $@9  */
  YYSYMBOL_every_definition = 377,         /* every_definition  */
  YYSYMBOL_add_definition = 378,           /* add_definition  */
  YYSYMBOL_dimensions = 379,               /* dimensions  */
  YYSYMBOL_datatype = 380,                 /* datatype  */
  YYSYMBOL_dim_definition = 381,           /* dim_definition  */
  YYSYMBOL_382_10 = 382,                   /* $@10  */
  YYSYMBOL_383_11 = 383,                   /* $@11  */
  YYSYMBOL_384_12 = 384,                   /* $@12  */
  YYSYMBOL_dim_definitions = 385,          /* dim_definitions  */
  YYSYMBOL_indexes = 386,                  /* indexes  */
  YYSYMBOL_parameters = 387,               /* parameters  */
  YYSYMBOL_parameters_expr = 388,          /* parameters_expr  */
  YYSYMBOL_values = 389,                   /* values  */
  YYSYMBOL_print_definition = 390,         /* print_definition  */
  YYSYMBOL_391_13 = 391,                   /* $@13  */
  YYSYMBOL_392_14 = 392,                   /* $@14  */
  YYSYMBOL_writing_mode_definition = 393,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 394,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 395,       /* writing_definition  */
  YYSYMBOL_locate_definition = 396,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 397,         /* cmove_definition  */
  YYSYMBOL_hscroll_definition = 398,       /* hscroll_definition  */
  YYSYMBOL_vscroll_definition = 399,       /* vscroll_definition  */
  YYSYMBOL_statement = 400,                /* statement  */
  YYSYMBOL_401_15 = 401,                   /* $@15  */
  YYSYMBOL_402_16 = 402,                   /* $@16  */
  YYSYMBOL_403_17 = 403,                   /* $@17  */
  YYSYMBOL_404_18 = 404,                   /* $@18  */
  YYSYMBOL_405_19 = 405,                   /* $@19  */
  YYSYMBOL_406_20 = 406,                   /* $@20  */
  YYSYMBOL_407_21 = 407,                   /* $@21  */
  YYSYMBOL_408_22 = 408,                   /* $@22  */
  YYSYMBOL_statements_no_linenumbers = 409, /* statements_no_linenumbers  */
  YYSYMBOL_410_23 = 410,                   /* $@23  */
  YYSYMBOL_statements_with_linenumbers = 411, /* statements_with_linenumbers  */
  YYSYMBOL_412_24 = 412,                   /* $@24  */
  YYSYMBOL_statements_complex = 413,       /* statements_complex  */
  YYSYMBOL_414_25 = 414,                   /* $@25  */
  YYSYMBOL_program = 415,                  /* program  */
  YYSYMBOL_416_26 = 416                    /* $@26  */
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
#define YYLAST   4853

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  304
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  601
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1111

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   558


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int16 yytranslate[] =
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
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,    87,    91,    95,    98,   101,   104,   107,
     110,   113,   119,   120,   123,   130,   131,   135,   136,   140,
     147,   148,   152,   156,   159,   162,   165,   168,   174,   179,
     182,   185,   188,   191,   194,   197,   202,   207,   211,   215,
     219,   223,   227,   231,   235,   239,   243,   247,   251,   255,
     259,   263,   267,   271,   275,   279,   283,   287,   291,   295,
     299,   303,   307,   311,   317,   321,   325,   329,   333,   337,
     341,   345,   349,   353,   357,   361,   365,   369,   373,   377,
     381,   385,   389,   393,   397,   401,   405,   409,   413,   417,
     421,   425,   429,   433,   437,   441,   445,   449,   453,   457,
     464,   468,   472,   476,   480,   484,   488,   492,   498,   502,
     505,   509,   513,   517,   521,   525,   529,   533,   537,   541,
     545,   549,   552,   556,   560,   564,   568,   572,   576,   580,
     584,   588,   592,   596,   600,   604,   608,   612,   618,   618,
     629,   629,   640,   643,   646,   655,   659,   666,   670,   674,
     678,   682,   686,   690,   694,   698,   701,   704,   707,   710,
     713,   716,   719,   722,   725,   728,   731,   734,   737,   740,
     743,   746,   749,   752,   755,   758,   761,   764,   767,   770,
     773,   776,   779,   782,   785,   788,   791,   794,   797,   797,
     803,   806,   809,   813,   817,   821,   825,   829,   833,   837,
     841,   845,   848,   851,   854,   857,   860,   863,   866,   869,
     872,   875,   878,   881,   884,   887,   890,   893,   896,   899,
     902,   905,   908,   911,   914,   918,   922,   925,   929,   933,
     937,   941,   945,   948,   951,   954,   957,   960,   963,   966,
     970,   974,   979,   979,   982,   985,   988,   991,   994,   997,
    1001,  1004,  1007,  1010,  1014,  1017,  1020,  1023,  1027,  1030,
    1033,  1036,  1042,  1045,  1048,  1051,  1054,  1059,  1060,  1063,
    1066,  1071,  1074,  1079,  1080,  1083,  1086,  1091,  1094,  1099,
    1100,  1103,  1106,  1109,  1114,  1117,  1120,  1125,  1126,  1129,
    1130,  1131,  1134,  1137,  1140,  1145,  1148,  1151,  1157,  1158,
    1161,  1164,  1167,  1170,  1173,  1176,  1179,  1182,  1185,  1188,
    1191,  1194,  1197,  1200,  1203,  1208,  1211,  1214,  1217,  1220,
    1223,  1226,  1229,  1232,  1235,  1238,  1241,  1244,  1247,  1250,
    1255,  1256,  1259,  1262,  1265,  1268,  1271,  1277,  1280,  1286,
    1287,  1290,  1295,  1300,  1301,  1304,  1307,  1312,  1315,  1320,
    1321,  1324,  1329,  1334,  1335,  1338,  1341,  1344,  1349,  1352,
    1358,  1359,  1362,  1365,  1368,  1371,  1374,  1379,  1382,  1385,
    1390,  1391,  1393,  1394,  1397,  1400,  1403,  1408,  1415,  1418,
    1424,  1427,  1433,  1436,  1442,  1447,  1448,  1451,  1456,  1460,
    1460,  1465,  1469,  1469,  1474,  1478,  1478,  1483,  1483,  1486,
    1486,  1489,  1489,  1494,  1497,  1500,  1505,  1508,  1514,  1518,
    1525,  1528,  1531,  1534,  1537,  1540,  1543,  1546,  1549,  1552,
    1557,  1557,  1565,  1565,  1573,  1573,  1584,  1585,  1589,  1593,
    1600,  1605,  1610,  1615,  1620,  1625,  1633,  1638,  1643,  1648,
    1653,  1658,  1663,  1667,  1674,  1678,  1685,  1688,  1692,  1695,
    1695,  1699,  1699,  1705,  1709,  1713,  1717,  1721,  1728,  1732,
    1736,  1740,  1744,  1751,  1757,  1760,  1763,  1769,  1772,  1775,
    1781,  1784,  1787,  1790,  1796,  1799,  1805,  1806,  1807,  1808,
    1809,  1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,
    1819,  1820,  1823,  1824,  1825,  1826,  1827,  1830,  1833,  1834,
    1835,  1836,  1839,  1842,  1845,  1848,  1851,  1854,  1857,  1860,
    1863,  1866,  1869,  1872,  1875,  1878,  1881,  1884,  1887,  1890,
    1893,  1896,  1899,  1899,  1904,  1907,  1910,  1913,  1916,  1919,
    1922,  1925,  1928,  1931,  1934,  1937,  1940,  1943,  1947,  1947,
    1952,  1955,  1958,  1961,  1964,  1967,  1971,  1975,  1979,  1979,
    1984,  1984,  1989,  1989,  1994,  1997,  2000,  2003,  2006,  2007,
    2010,  2013,  2016,  2019,  2022,  2025,  2026,  2027,  2028,  2029,
    2032,  2035,  2038,  2041,  2044,  2047,  2050,  2053,  2054,  2063,
    2072,  2072,  2084,  2084,  2101,  2101,  2118,  2121,  2122,  2126,
    2127,  2127,  2131,  2131,  2138,  2138,  2141,  2142,  2143,  2144,
    2148,  2148
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
  "VARIABLES", "MS", "CYCLES", "WIDTH", "HEIGHT", "DWORD", "PEN", "CLEAR",
  "BEG", "END", "GAMELOOP", "ENDIF", "UP", "DOWN", "LEFT", "RIGHT",
  "DEBUG", "AND", "RANDOMIZE", "GRAPHIC", "TEXTMAP", "POINT", "GOSUB",
  "RETURN", "POP", "OR", "ELSE", "NOT", "TRUE", "FALSE", "DO", "EXIT",
  "WEND", "UNTIL", "FOR", "STEP", "EVERY", "MID", "INSTR", "UPPER",
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
  "SCANCODE", "SCAN", "SHIFT", "SCANSHIFT", "BOTH", "SHIFTS", "NONE",
  "LETTER", "ASTERISK", "COLON", "COMMA", "COMMODORE", "CONTROL", "CRSR",
  "CURSOR", "DELETE", "EQUAL", "FUNCTION", "INSERT", "ARROW", "MINUS",
  "PERIOD", "PLUS", "POUND", "RUNSTOP", "RUN", "STOP", "SEMICOLON",
  "SLASH", "KEY", "STATE", "KEYSTATE", "A", "B", "C", "D", "E", "F", "G",
  "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U",
  "V", "X", "Y", "W", "Z", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8",
  "BLACK", "WHITE", "RED", "CYAN", "VIOLET", "GREEN", "BLUE", "YELLOW",
  "ORANGE", "BROWN", "LIGHT", "DARK", "GREY", "GRAY", "MAGENTA", "PURPLE",
  "LAVENDER", "GOLD", "TURQUOISE", "TAN", "PINK", "PEACH", "OLIVE",
  "Identifier", "String", "Integer", "\"0\"", "\"1\"", "\"2\"", "\"3\"",
  "\"4\"", "\"5\"", "\"6\"", "\"7\"", "\"8\"", "\"9\"", "\" \"", "$accept",
  "expr", "expr_math", "term", "modula", "factor", "direct_integer",
  "random_definition_simple", "random_definition", "color_enumeration",
  "key_scancode_alphadigit", "key_scancode_function_digit",
  "key_scancode_definition", "exponential", "$@1", "$@2", "$@3",
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
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558
};
#endif

#define YYPACT_NINF (-974)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-581)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -974,    69,  1059,  -974,  -974,  -209,  -200,  3345,   -17,  -974,
      36,  2790,    79,    -8,  2790,  -974,    41,   180,  3345,  -148,
     -45,  -974,  -974,  -974,  2248,   116,    24,  3345,  3345,    73,
     -27,  -974,   112,   155,  3345,  3345,  -974,   191,   208,   -21,
    3345,    99,   189,  -974,   -12,  -974,  3345,   -24,  2519,   234,
      16,  3345,    18,    33,    42,    48,  -118,  -118,  3345,  3345,
     166,    44,  1420,  -974,  -974,  1706,  3345,  3345,   108,  -974,
    -974,  -974,  -974,  3345,  -974,  -974,    65,   241,   283,    30,
    -974,   304,   310,   330,  -974,  -974,  -974,    52,   325,  1977,
    -974,  -974,   306,   307,   308,   110,  -974,  -974,     3,  -974,
    -974,    -3,    -2,  3345,  -974,  -974,   309,   314,   315,   316,
     317,   319,   320,   321,   322,   323,   324,   326,   328,   329,
     349,   350,   351,  -974,  -974,   352,    54,   -42,    20,   338,
     373,   374,   375,   377,   378,   379,  -974,  -974,  -974,   -22,
     356,  4158,  -974,   360,   361,   363,   382,   383,   384,  -974,
    -974,   -48,  -974,  4551,   385,  -974,  -974,  -974,  -974,  -974,
    -974,  -974,   144,  -974,  -974,   -30,  -194,  -974,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -974,   145,    25,  -974,  -974,
     292,   109,   282,   281,   271,  -974,  -974,  -974,  2790,   396,
    -974,  -974,  -974,  2790,  2790,  2790,  -974,  -974,  -974,   137,
      23,    72,  -974,  -974,  -974,    -6,   404,    -5,    -1,     1,
       2,   401,  -974,  -974,  -974,   376,   390,  -974,  -974,  -974,
    2790,  -974,  -974,   399,  -974,  -974,  -974,  -974,  -974,  2790,
     388,   392,  -974,  -974,  -974,     4,  -974,    57,  -974,  -974,
    -974,  -974,  -974,  3345,  3074,  -974,  -974,   428,  -974,  -974,
    -974,  2790,  -974,  -974,  -974,  2790,   402,  -974,  -974,  -974,
     370,  -974,  -974,  -974,   296,  3345,  3345,  -974,  -974,  2790,
    -974,  -974,  -974,   409,  -974,  -974,  -974,  -974,  -974,  -974,
    -974,  -974,  3345,  3345,  -974,  -974,  -974,  -974,   438,  -974,
    -974,   299,  -974,  3345,   448,  -974,  -974,  -974,    58,   449,
    -974,   313,   327,   331,    80,   450,  -974,  -974,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -974,  -974,   452,  -974,  3345,
     453,  -974,  3345,   457,  -974,  -974,  -974,  3345,  -974,   218,
    -974,  -974,  -974,   225,  -974,  3345,  -974,  -974,  3345,   454,
    -974,  -974,   425,    22,  1238,  -974,  1059,  1059,  -974,   426,
     427,   429,   430,   432,   433,    12,   434,  3345,  2790,  2790,
    -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,   436,
    -974,  -974,  3345,  -974,  3345,  -974,  -974,  3345,  3345,  3345,
    3345,  3345,  3345,  3345,  3345,  3345,  3345,  3345,  3345,  3345,
    3345,  3345,  3345,  3345,  3616,   439,   179,  -974,  -974,   440,
    -974,  -974,   442,   443,  -974,  -974,  -974,  -974,  -974,  3345,
    -974,  3345,  1977,   444,   460,  3345,  3345,  3345,  3345,  3345,
    3345,  -974,  -974,  -974,  -974,   258,   266,  -974,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -974,   205,  -974,  -974,  -974,
     209,  -974,  -974,  -974,  -974,  -974,   260,  -974,  -974,   451,
    -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -974,  -974,  3345,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -974,   455,  -974,   456,   261,
     264,  3616,  3616,  3616,  3616,  3616,  3616,  3616,  3616,  3616,
    3616,  3616,  3616,  3616,   -62,  3887,  4429,   458,   459,  2790,
    -974,  -974,   410,   411,   414,   419,  -974,  -974,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -974,  2790,   468,  -974,  -974,
    -974,   445,   404,   470,   404,   471,   404,   472,   404,   473,
     404,  -974,  3345,   465,  -974,  -974,   262,   267,    35,   114,
    -974,  -974,  -974,   466,   404,   469,  -974,  -974,   274,   278,
     173,   181,  -974,  -974,   467,  -974,  -974,  2790,  -974,  -974,
    2790,  2790,  -974,  -974,  -974,   461,   215,  -974,   503,  3345,
    -974,  -974,  -974,  -974,  2790,  -974,  3345,   504,   505,  -974,
    -974,  2790,   441,   506,  3345,   408,   508,  3345,  -974,  -974,
    -974,  -974,  -974,  -974,   113,  -974,  -974,   477,   498,    18,
    -974,   369,  -974,  -118,   513,    22,  -118,   -18,  -974,  3345,
    -974,  3345,  -974,  -974,  -974,  -974,  -974,  -974,  1059,  -974,
    3345,   481,  3345,  3345,   483,     6,  -974,  1238,  -974,  -974,
    3345,   232,   233,   235,   236,   237,   485,   489,   490,  -974,
     491,   492,   493,   494,   495,  3345,   530,   531,   533,   534,
     501,   502,   507,   509,   537,   510,   511,   512,   515,   516,
     538,   539,   517,   518,   519,   196,   257,   520,  3345,  3345,
    3345,   521,    50,    81,  3345,  3616,   522,   523,   524,   525,
     526,   527,  -974,  -974,   474,   475,  -974,  -974,  -974,  3345,
     528,   514,  3345,  3345,  3345,  3345,   282,   282,   318,   318,
     318,   318,   318,   318,   318,   318,   281,   271,   271,   358,
    4429,  4429,  -974,  -974,   280,   285,  -974,  -974,  3345,   404,
    3345,   404,   541,   542,  2790,   128,  -974,   404,  -974,   404,
    -974,   404,  -974,   404,    45,  -974,  3345,  -974,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  3345,  -974,   404,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -974,   404,  -974,  -974,  -974,
    -974,  -974,  -974,   289,   295,   297,   298,   559,  3345,   566,
     543,   545,   431,  3345,  3345,   579,   582,  -974,   -11,   536,
     300,  3345,   587,  -974,  -974,  -974,   555,   332,   556,  -974,
    3345,   311,  3345,  -974,  -118,   591,  -974,   437,   447,  -974,
    -974,  -974,  -974,  -974,  -974,  3345,   593,   476,   599,   567,
    3345,  -974,   602,  -974,  -974,  -974,  -974,  -974,   333,   334,
     336,  -974,  -974,  -974,  -974,  -974,   570,  3345,  3345,  3345,
    3345,  -974,  -974,  -974,  -974,  3345,  -974,  -974,  -974,  -974,
    -974,  3345,  3345,  -974,  -974,  -974,  4429,   571,  -974,   575,
     610,   611,  -974,  3345,  -974,  3345,   612,   597,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -974,   580,  -974,  3345,   478,
     581,  -974,  -974,  4429,  -974,  -974,  -974,  -974,  -974,  -974,
    -974,  -974,   341,   343,  -974,  -974,  -974,  -974,  -974,  -974,
     588,  -974,   600,  -974,   346,   151,  -974,   632,  -974,   634,
     639,  -974,   640,  -974,   641,  -974,   636,  2790,   643,  3345,
    3345,   404,  -974,   613,   614,  3345,   404,  -974,  -974,  3345,
    -974,    90,  3345,   332,   644,   615,   332,   529,   162,   532,
     535,  -974,  -118,  -974,  -974,   616,  3345,  -974,  3345,   646,
     619,  3345,  -974,  -974,  -974,  -974,   620,   621,   143,   164,
     622,   623,   624,   625,  -974,  -974,  3345,  3345,   626,   628,
    -974,   629,  -974,  -974,  -974,  -974,  -974,   386,   387,  -974,
     617,  -974,   647,  -974,  3345,   404,   669,   672,   674,  3345,
    -974,  -974,  3345,  -974,  -974,  -974,   671,   677,   653,   655,
     568,  3345,   685,   607,   658,   332,  -974,   659,  -974,   311,
     694,    22,  -974,  -974,  -974,   689,  -974,  -974,  3345,   690,
     663,  -974,  -974,  3345,  -974,  3345,  -974,  -974,  -974,  -974,
    -974,   664,   665,  -974,  -974,  -974,  -974,  -974,   416,   417,
     668,   670,   289,   295,   297,  -974,  -974,  3345,  3345,  -974,
    -974,  3345,   673,  3345,  3345,  -974,  -974,  -974,  -974,   311,
     703,  3345,  -974,  3345,  -974,   675,   678,  -974,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,   700,
    -974,  -974,  -974,   311,  -974,  -974,  -974,  -974,  3345,  -974,
    -974
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     600,     0,   588,     1,   587,     0,     0,     0,     0,   572,
       0,     0,   536,     0,     0,   563,     0,     0,     0,   372,
       0,   521,   525,   522,     0,     0,     0,     0,     0,     0,
     564,   519,     0,     0,     0,   514,   562,     0,     0,     0,
     569,   571,   517,   520,   527,   524,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   510,   511,     0,     0,     0,     0,   501,
     502,   503,   504,   505,   496,   497,     0,     0,     0,   584,
     592,   589,   596,   598,   601,   512,   513,     0,     0,     0,
     157,   158,     0,     0,     0,     0,   201,   202,     0,   227,
     228,   229,   230,     0,   192,   193,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   194,   203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   214,   215,   216,     0,
       0,     0,   225,   231,     0,     0,     0,     0,     0,   232,
     233,     0,   237,     0,     0,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     0,     0,    49,    54,    55,
      56,    57,    58,    59,    62,    63,     0,   142,   146,   144,
     446,     2,    12,    15,    17,   155,    20,   494,     0,     0,
     273,   274,   477,     0,     0,     0,   287,   288,   479,     0,
       0,     0,   298,   299,   480,     0,     0,     0,     0,     0,
       0,     0,   267,   268,   476,     0,     0,   330,   331,   481,
       0,   333,   334,   335,   339,   340,   482,   362,   363,     0,
       0,     0,   370,   371,   487,     0,   565,     0,   382,   490,
     378,   379,   566,     0,     0,   345,   346,     0,   349,   350,
     484,     0,   353,   354,   485,     0,   356,   360,   361,   486,
       0,   554,   560,   561,   542,     0,     0,   586,   515,     0,
     343,   344,   483,     0,   385,   386,   488,   380,   381,   567,
     570,   529,     0,     0,   528,   531,   532,   526,     0,   404,
     405,     0,   568,     0,     0,   492,   387,   489,   420,   426,
     577,   546,   537,   547,   436,   442,   540,   541,   493,   555,
     556,   557,   456,   454,   453,   455,   457,     0,   558,     0,
       0,   495,     0,     0,   500,   508,   509,     0,   506,     0,
     470,   472,   498,     0,   499,     0,   594,   559,     0,   582,
     548,   545,     0,     0,   588,   590,   588,   588,   145,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    29,    30,    32,    34,    35,    31,    36,   181,     0,
     195,   196,     0,   239,     0,   240,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   197,   200,     0,
     198,   199,     0,     0,   213,   207,   208,   209,   210,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,   238,   111,   112,     0,     0,   132,   137,   122,
     108,   110,   113,   114,   115,   116,     0,   119,   120,   123,
       0,   128,   129,   130,   131,   133,     0,   135,   136,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,   109,   121,   241,     0,    60,    47,
      50,    51,    52,    53,    48,    61,   143,   188,     0,   451,
     449,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     284,   281,     0,     0,     0,     0,    28,   289,   295,   290,
     291,   296,   297,   292,   293,   294,     0,     0,   279,   280,
     478,   244,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   243,     0,     0,   320,   321,     0,     0,     0,     0,
     317,   316,   242,     0,     0,     0,   305,   306,     0,     0,
       0,     0,   302,   301,     0,   337,   332,     0,   367,   364,
       0,     0,   397,   401,   399,     0,     0,   523,     0,     0,
     352,   351,   358,   355,     0,   516,     0,     0,     0,   342,
     341,     0,     0,   530,     0,     0,     0,     0,   418,   410,
     412,   417,   414,   419,     0,   416,   424,     0,     0,     0,
     550,     0,   552,     0,   437,     0,     0,     0,   464,   465,
     467,   468,   507,   471,   473,   474,   475,   491,   588,   578,
       0,     0,     0,     0,     0,   584,   593,   588,   597,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,   125,     0,     0,   126,   124,   134,     0,
       0,     0,     0,     0,     0,     0,    13,    14,     5,     7,
       8,     9,    10,     6,     3,     4,    16,    18,    19,     0,
       0,     0,    25,    21,     0,     0,   271,   269,     0,     0,
       0,     0,     0,     0,     0,     0,   249,     0,   261,     0,
     253,     0,   257,     0,   245,   318,     0,   325,   324,   329,
     328,   323,   327,   322,   326,     0,   303,     0,   310,   309,
     314,   313,   308,   312,   307,   311,     0,   338,   336,   368,
     365,   369,   366,     0,     0,     0,     0,   373,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   518,     0,     0,
       0,     0,   406,   411,   413,   415,     0,     0,     0,   427,
       0,     0,     0,   439,     0,   438,   443,   461,   459,   458,
     463,   466,   469,   595,   579,     0,   444,     0,   428,     0,
       0,   591,     0,   154,   147,   149,   153,   151,     0,     0,
       0,   156,   160,   159,   162,   161,     0,     0,     0,     0,
       0,   169,   170,   171,   180,     0,   174,   175,   176,   177,
     178,     0,     0,   190,   191,   182,     0,     0,   186,     0,
       0,     0,   217,     0,   172,     0,     0,    27,   223,   218,
     219,   220,   221,   222,   118,   117,     0,   236,     0,     0,
       0,   452,   450,     0,    23,    26,   272,   270,   286,   283,
     285,   282,     0,     0,   277,   275,   246,   259,   251,   254,
     248,   260,   252,   256,     0,     0,   315,     0,   300,     0,
     388,   398,   391,   402,   394,   400,   374,     0,     0,     0,
       0,     0,   543,     0,     0,     0,     0,   533,   534,     0,
     403,     0,     0,     0,   408,     0,     0,     0,   430,     0,
       0,   440,     0,   462,   460,     0,     0,   549,     0,     0,
       0,     0,   148,   150,   152,   204,     0,     0,     0,     0,
       0,     0,     0,     0,   187,   205,     0,     0,     0,     0,
     235,     0,   189,   139,    24,   278,   276,     0,     0,   262,
     247,   258,   250,   255,     0,     0,     0,     0,     0,     0,
     376,   375,     0,   348,   359,   357,     0,     0,     0,     0,
     535,     0,     0,     0,     0,     0,   421,     0,   551,     0,
     431,     0,   539,   553,   441,     0,   445,   429,     0,     0,
       0,   163,   164,     0,   165,     0,   167,   179,   185,   184,
      22,     0,     0,   173,   226,   141,   264,   266,     0,     0,
       0,     0,     0,     0,     0,   377,   347,     0,     0,   384,
     383,     0,     0,     0,     0,   425,   409,   423,   433,     0,
     432,     0,   581,     0,   211,     0,     0,   212,   206,   263,
     265,   319,   304,   390,   393,   396,   573,   574,   544,     0,
     575,   407,   434,     0,   583,   585,   166,   168,     0,   435,
     576
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -974,    -7,  -263,  -169,   199,  -386,    84,  -974,  -974,  -974,
    -974,  -974,  -974,  -138,  -974,  -974,  -974,   540,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,
     544,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,
    -974,  -974,  -974,  -341,  -974,  -340,  -974,  -338,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -892,  -342,  -974,  -974,  -974,
    -974,    93,  -681,  -973,   -55,  -706,   -52,  -974,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,  -974,
    -974,  -974,  -974,  -974,  -974,  -339,  -974,  -974,  -974,  -337,
    -974,  -974,  -974
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   838,   181,   182,   183,   184,   201,   367,   368,   185,
     494,   495,   496,   186,   508,   721,   722,   573,   212,   213,
     214,   190,   191,   192,   548,   549,   550,   196,   197,   198,
     542,   202,   203,   204,   217,   218,   219,   224,   225,   226,
     270,   271,   272,   248,   249,   250,   252,   253,   254,   257,
     258,   259,   232,   233,   234,   238,   242,   279,   239,   274,
     275,   276,   297,   931,  1006,   933,  1007,   935,  1008,   236,
     793,   795,   794,   292,   295,   955,   626,   299,   627,   628,
     816,   300,   839,   959,   306,   837,   187,   725,   724,   317,
     830,   318,   321,   324,   332,   334,    81,   243,   631,   652,
     820,   822,   342,   651,   343,    82,   657,    83,   344,    84,
     648,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     180,   654,   307,   414,   200,   656,   308,   215,   695,   658,
     659,   235,   337,   188,   199,   199,   899,   247,   409,   338,
     260,   261,   206,   369,   546,   552,   339,   267,   268,   554,
     207,   556,   558,   280,   336,   421,   337,   372,   374,   287,
     399,   291,   900,   338,   296,   506,  -580,   208,   397,   739,
     339,   180,   309,   618,   255,   320,  1078,   883,   323,   325,
     326,  1024,   283,   592,  1027,  -138,   328,   263,   193,     3,
    -580,   220,   827,   194,   395,   209,   210,   595,  -422,   503,
     924,    85,   356,   221,   222,   504,   771,   633,   885,   618,
      86,   884,   666,   667,   396,   772,   376,  1021,   216,   925,
     634,   668,   619,   620,   621,   596,  1102,   205,   537,   538,
     593,   622,   329,   195,   957,   256,   960,   511,   512,   398,
     264,   513,   669,   514,   515,   516,   517,   518,   286,   740,
    1109,  1022,   223,  1076,   635,   284,   737,   738,   619,   620,
     621,   360,   237,   828,   370,   312,   251,   622,   829,   623,
    1043,   594,   265,   313,   965,   422,   340,   537,   543,   970,
     624,   400,   371,   330,   331,   773,   916,   262,   625,  1029,
     410,  1045,   304,   305,   774,   507,   539,   540,   541,   401,
     340,   527,  1030,   917,  1044,   623,   530,   532,   534,  1000,
     361,   362,   363,   813,   814,   266,   624,   364,   365,   366,
     373,   375,   815,   876,   625,  1046,  1001,   314,   315,   316,
     519,   918,   919,   585,   310,   311,  1031,   991,   520,   524,
     525,   269,   588,   526,   782,   539,   540,   544,   227,   228,
     229,   230,   784,   783,  1002,  1003,   597,   598,   273,   499,
     231,   785,   500,   501,   600,   240,   281,   241,   602,   502,
     728,   729,   730,   731,   732,   733,   734,   735,   607,   608,
    1036,  -448,   609,   282,  -447,  -448,   288,  -448,  -447,   277,
    -447,   278,   528,   189,   293,   612,   613,   531,   533,   535,
     285,   947,   211,   327,   547,   553,   616,  1037,   333,   555,
     551,   557,   559,   825,   524,   525,   335,   509,   526,   510,
     522,   714,   523,   715,   586,   716,   294,   717,   298,   341,
     345,   833,   638,   589,   346,   640,   643,   644,   841,   887,
     642,   645,   646,   301,   767,   768,   511,   512,   647,   769,
     770,   649,   302,   341,   347,   601,   778,   779,   303,   603,
     780,   781,   726,   727,   348,   349,   357,   358,   359,   377,
     670,   671,   673,   610,   378,   379,   380,   381,   402,   382,
     383,   384,   385,   386,   387,   676,   388,   677,   389,   390,
     678,   679,   680,   681,   682,   683,   684,   685,   686,   687,
     688,   689,   690,   691,   692,   693,   694,   742,   743,   391,
     392,   393,   394,   403,   404,   405,   411,   406,   407,   408,
     415,   416,   701,   417,   702,   703,   561,   562,   706,   707,
     708,   709,   710,   711,   563,   521,   498,   505,   564,   565,
     561,   574,   418,   419,   420,   497,   529,   566,   575,   536,
     199,   560,   576,   577,   587,   599,   567,   604,   568,   569,
     590,   578,   672,   674,   591,   605,   606,   570,   571,   611,
     579,   614,   580,   581,   615,   617,   629,   636,   572,   637,
     639,   582,   583,   630,   641,   653,   660,   650,   661,   697,
     662,   663,   572,   664,   665,   669,   675,  -538,   712,   696,
     698,   632,   699,   700,   704,   705,   713,   718,   748,   749,
     720,   719,   750,   744,   745,  -140,   723,   751,   754,   755,
     757,   759,   761,   763,   766,   797,   775,   786,   777,   796,
     798,   803,   804,   808,   810,   811,   807,   817,   818,   821,
     824,   835,   746,   840,   843,   844,   848,   845,   846,   847,
     849,   850,   851,   852,   853,   854,   855,   857,   858,   752,
     859,   860,   861,   862,   865,   871,   872,   877,   863,   903,
     864,   866,   867,   868,   898,   765,   869,   870,   873,   874,
     875,   878,   882,   888,   889,   890,   891,   892,   893,   897,
     906,   894,   937,   939,   895,   907,   912,   913,   823,   930,
     787,   826,   942,   789,   791,   932,   945,   934,   936,   946,
     950,   940,   799,   941,   952,   953,   956,   800,   962,   802,
     966,   958,   904,   905,   805,   963,   968,   809,   969,   971,
     812,   975,   984,   747,   949,   964,   985,   986,   987,   885,
     524,   990,   993,   997,   954,   972,   973,   967,   974,   992,
     753,   995,   831,   996,   832,   998,   756,   999,   758,  1004,
     760,  1005,   762,   834,   764,   836,  -389,  -392,  -395,  1009,
    1012,  1025,  1058,   842,  1016,  1017,  1026,  1035,   776,  1038,
    1039,  1041,  1042,  1047,  1048,  1049,  1050,  1053,   856,  1054,
    1055,   788,   901,   902,   790,   792,  1062,  1056,  1057,  1063,
    1028,  1064,  1059,  1032,  1067,  1074,  1033,  1071,   801,  1080,
    1068,   879,   880,   881,  1069,   806,  1070,   886,  1073,  1075,
    1077,  1079,  1081,  1083,  1084,  1087,  1088,  1089,  1090,  1091,
    1103,  1092,   896,  1108,  1099,   836,  1106,   180,   180,  1107,
     736,  1093,   819,  1094,     0,     0,  1095,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   983,     0,
       0,   908,     0,   910,     0,   545,     0,   914,     0,     0,
       0,     0,     0,     0,     0,     0,   584,     0,     0,   926,
       0,     0,     0,     0,     0,   994,     0,     0,   927,   961,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   938,     0,     0,     0,     0,   943,   944,     0,     0,
       0,     0,     0,     0,   951,     0,     0,     0,     0,     0,
       0,     0,     0,   836,     0,   836,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   909,     0,   911,     0,     0,   915,     0,
       0,   920,     0,   921,     0,   922,     0,   923,     0,     0,
     976,   977,   978,   979,     0,     0,     0,     0,   980,     0,
       0,   928,     0,     0,   981,   982,     0,     0,     0,     0,
     929,     0,     0,     0,     0,     0,   988,     0,   989,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   948,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1034,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1010,     0,  1013,  1014,     0,     0,     0,     0,  1018,     0,
       0,     0,  1020,     0,     0,  1023,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   836,
       0,     0,     0,     0,  1040,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1051,
    1052,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1060,     0,     0,
       0,     0,  1065,     0,     0,  1066,     0,     0,     0,     0,
       0,     0,     0,     0,  1072,     0,     0,     0,     0,     0,
       0,  1011,     0,     0,     0,  1015,     0,     0,     0,     0,
    1019,  1082,     0,     0,     0,     0,  1085,     0,  1086,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1096,  1097,     4,     0,  1098,     0,  1100,  1101,     0,     5,
       6,     0,     0,     0,  1104,     0,  1105,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     0,     8,     9,  1061,
      10,     0,    11,    12,     0,    13,    14,     0,     0,     0,
       0,  1110,     0,    15,     0,    16,    17,    18,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,    20,     0,
       0,     0,     0,    21,    22,    23,    24,    25,    26,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
       0,    29,    30,     0,    31,     0,     0,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,     0,    42,
       0,     0,     0,    43,    44,    45,    46,    47,     0,    48,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,    52,     0,    53,    54,    55,     0,
       0,    56,     0,     0,     0,    57,     0,    58,     0,     0,
      59,    60,     0,     0,     0,     0,    61,     0,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,     4,     0,    74,    75,    76,    77,    78,     5,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     0,     0,     0,     0,     0,     8,     9,     0,    10,
       0,    11,    12,     0,    13,    14,     0,     0,     0,     0,
       0,     0,    15,     0,    16,    17,    18,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,    20,     0,     0,
       0,     0,    21,    22,    23,    24,    25,    26,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
      29,    30,     0,    31,     0,     0,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    79,
       0,    80,    43,    44,    45,    46,    47,     0,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,    52,     0,    53,    54,    55,     0,     0,
      56,     0,     0,     0,    57,     0,    58,     0,     0,    59,
      60,     0,     0,     0,     0,    61,     0,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
       0,     0,    74,    75,    76,    77,    78,   319,     0,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,    94,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,    96,    97,     0,
      98,     0,     0,     0,     0,     0,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,   655,     0,
       0,   103,   104,   105,     0,     0,     0,     0,     0,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,     0,   118,   119,   120,     0,   121,
     122,   123,     0,   124,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,     0,   127,
       0,   128,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     0,   130,     0,     0,   131,     0,   132,   133,   134,
     135,     0,   136,   137,     0,     0,     0,     0,   138,   139,
     140,   141,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,   152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,     0,   154,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   322,     0,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
       0,     0,    94,     0,     0,    95,     0,     0,     0,     0,
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
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,     0,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    87,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,     0,
       0,     0,     0,     0,     0,     0,     0,    88,   350,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,    94,     0,     0,    95,   351,   352,   353,
       0,     0,     0,     0,    96,    97,   354,    98,     0,     0,
       0,     0,     0,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,   104,
     105,     0,     0,     0,     0,     0,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,     0,   118,   119,   120,   355,   121,   122,   123,     0,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,     0,   127,     0,   128,     0,
       0,     0,     0,     0,     0,     0,   129,     0,     0,   130,
       0,     0,   131,     0,   132,   133,   134,   135,     0,   136,
     137,     0,     0,     0,     0,   138,   139,   140,   141,     0,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
       0,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   153,     0,   154,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    87,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
       0,     0,     0,     0,     0,     0,     0,     0,   244,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
     245,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,    94,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,    96,    97,     0,    98,     0,
       0,     0,     0,     0,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,     0,   118,   119,   120,     0,   121,   122,   123,
       0,   124,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,     0,   127,     0,   128,
       0,     0,     0,     0,     0,     0,     0,   129,     0,     0,
     130,     0,     0,   131,     0,   132,   133,   134,   135,     0,
     136,   137,     0,     0,     0,     0,   138,   139,   140,   141,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,   152,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,     0,
     154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    87,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,     0,     0,     0,     0,     0,     0,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,   289,   290,     0,
       0,     0,     0,     0,     0,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,    94,     0,     0,    95,     0,
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
     150,   151,     0,   152,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   153,
       0,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,    87,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,     0,     0,     0,     0,   199,     0,     0,     0,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,    94,     0,     0,    95,
       0,     0,     0,     0,     0,     0,     0,    96,    97,     0,
      98,     0,     0,     0,     0,     0,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,   104,   105,     0,     0,     0,     0,     0,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,     0,   118,   119,   120,     0,   121,
     122,   123,     0,   124,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,     0,   127,
       0,   128,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     0,   130,     0,     0,   131,     0,   132,   133,   134,
     135,     0,   136,   137,     0,     0,     0,     0,   138,   139,
     140,   141,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,     0,   152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,     0,   154,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
       0,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   349,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,     0,     0,
      94,     0,     0,    95,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,     0,   154,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    87,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,     0,     0,     0,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,     0,
       0,    94,     0,     0,    95,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,     0,   154,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,    87,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
       0,     0,    94,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,    96,    97,     0,    98,     0,     0,     0,
       0,     0,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
       0,     0,     0,     0,     0,     0,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
       0,   118,   119,   120,     0,   121,   122,   123,     0,   124,
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,   127,     0,   128,     0,     0,
       0,     0,     0,     0,     0,   129,     0,     0,   130,     0,
       0,   131,     0,   132,   133,   134,   135,     0,   136,   137,
       0,     0,     0,     0,   138,   139,   140,   141,     0,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,     0,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,     0,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,    87,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,     0,
       0,     0,     0,     0,     0,     0,     0,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,    94,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,    96,    97,     0,    98,     0,     0,
       0,     0,     0,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   741,   104,
     105,     0,     0,     0,     0,     0,     0,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,     0,   118,   119,   120,     0,   121,   122,   123,     0,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,     0,   127,     0,   128,     0,
       0,     0,     0,     0,     0,     0,   129,     0,     0,   130,
       0,     0,   131,     0,   132,   133,   134,   135,     0,   136,
     137,     0,     0,     0,     0,   138,   139,   140,   413,     0,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
       0,   152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   153,     0,   154,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,    87,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
       0,     0,     0,     0,     0,     0,     0,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   412,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,    94,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,    96,    97,     0,    98,     0,
       0,     0,     0,     0,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,     0,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     0,     0,   118,   119,   120,     0,   121,   122,   123,
       0,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,     0,   127,     0,   128,
       0,     0,     0,     0,     0,     0,     0,   129,     0,     0,
     130,     0,     0,   131,     0,   132,   133,   134,   135,     0,
     136,   137,     0,     0,     0,     0,   138,   139,   140,   413,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,     0,   152,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,     0,
     154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    87,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,     0,     0,     0,     0,     0,     0,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,    94,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,    96,    97,     0,    98,
       0,     0,     0,     0,     0,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,     0,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,     0,     0,   118,   119,   120,     0,   121,   122,
     123,     0,   124,     0,     0,     0,     0,     0,     0,     0,
       0,   423,     0,     0,     0,     0,   126,     0,   127,     0,
     128,     0,     0,     0,     0,     0,     0,     0,   129,     0,
       0,   130,     0,     0,   131,     0,   132,   133,   134,   135,
       0,   136,   137,     0,     0,     0,     0,   138,   139,   140,
     413,     0,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,     0,   152,     0,     0,     0,     0,     0,     0,
       0,     0,   424,     0,     0,     0,     0,   425,     0,   426,
       0,     0,     0,     0,     0,     0,     0,     0,   427,   153,
       0,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   428,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,     0,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   429,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   430,     0,
     431,   432,   433,   434,   435,   436,     0,   437,   438,     0,
     439,   440,   441,   442,   443,   444,   445,   446,     0,   447,
     448,     0,   449,     0,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493
};

static const yytype_int16 yycheck[] =
{
       7,   343,    57,   141,    11,   344,    58,    14,   394,   346,
     347,    18,     6,    30,    26,    26,   722,    24,    40,    13,
      27,    28,    30,    20,    30,    30,    20,    34,    35,    30,
      38,    30,    30,    40,     4,    83,     6,    40,    40,    46,
      20,    48,   723,    13,    51,    20,    40,    55,    90,   111,
      20,    58,    59,    31,    30,    62,  1029,     7,    65,    66,
      67,   953,    74,    59,   956,    40,    73,    94,    32,     0,
      40,    30,    90,    37,    20,    83,    84,    20,    20,   273,
      35,   290,    89,    42,    43,   279,    51,     7,     7,    31,
     290,    41,    80,    81,    40,    60,   103,     7,    14,    54,
      20,    89,    80,    81,    82,    48,  1079,    28,    85,    86,
     106,    89,    47,    77,   820,    91,   822,     8,     9,   161,
     147,    12,    41,    14,    15,    16,    17,    18,    44,   191,
    1103,    41,    91,  1025,    54,   147,   522,   523,    80,    81,
      82,    31,   290,   161,   141,   101,    30,    89,   166,   127,
       7,   147,    40,   109,   835,   203,   150,    85,    86,   840,
     138,   141,   159,    98,    99,    51,    38,    94,   146,     7,
     192,     7,   290,   291,    60,   150,   153,   154,   155,   159,
     150,   188,    20,    55,    41,   127,   193,   194,   195,    38,
      80,    81,    82,    80,    81,    40,   138,    87,    88,    89,
     203,   203,    89,     7,   146,    41,    55,   163,   164,   165,
     101,    83,    84,   220,    48,    49,    54,   898,   109,    23,
      24,    30,   229,    27,    51,   153,   154,   155,    48,    49,
      50,    51,    51,    60,    83,    84,   243,   244,    30,   269,
      60,    60,   272,   273,   251,   290,   147,   292,   255,   279,
     513,   514,   515,   516,   517,   518,   519,   520,   265,   266,
     966,     0,   269,    74,     0,     4,   290,     6,     4,   290,
       6,   292,   188,   290,    40,   282,   283,   193,   194,   195,
     292,   292,   290,   175,   290,   290,   293,   968,    47,   290,
     206,   290,   290,   635,    23,    24,    13,     5,    27,     7,
      19,    96,    21,    98,   220,    96,   290,    98,   290,   303,
       6,   648,   319,   229,     4,   322,    98,    99,   657,   705,
     327,    96,    97,   290,    62,    63,     8,     9,   335,    62,
      63,   338,   290,   303,     4,   251,    62,    63,   290,   255,
      62,    63,   511,   512,   292,    20,    40,    40,    40,    40,
     357,   358,   359,   269,    40,    40,    40,    40,    20,    40,
      40,    40,    40,    40,    40,   372,    40,   374,    40,    40,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   525,   526,    40,
      40,    40,    40,    20,    20,    20,    40,    20,    20,    20,
      40,    40,   409,    40,   411,   412,    30,    31,   415,   416,
     417,   418,   419,   420,    38,   133,   272,   272,    42,    43,
      30,    31,    40,    40,    40,    40,    30,    51,    38,   292,
      26,    30,    42,    43,    35,     7,    60,    35,    62,    63,
      52,    51,   358,   359,    52,    75,   150,    71,    72,    40,
      60,    13,    62,    63,   155,     7,     7,     7,    82,     7,
       7,    71,    72,   150,     7,    40,    40,    13,    41,   290,
      41,    41,    82,    41,    41,    41,    40,   150,   220,    40,
      40,   150,    40,    40,    40,    25,   220,   227,    78,    78,
     497,    40,    78,    35,    35,    40,    40,    78,    30,    54,
      30,    30,    30,    30,    39,   290,    40,    40,    39,    48,
       7,     7,     7,     7,   106,     7,    75,    40,    20,   150,
       7,    40,   529,    40,   292,   292,    41,   292,   292,   292,
      41,    41,    41,    41,    41,    41,    41,     7,     7,   546,
       7,     7,    41,    41,     7,     7,     7,   290,    41,   191,
      41,    41,    41,    41,    40,   562,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
     290,    97,    13,     7,    99,   290,    35,    35,   633,   290,
     587,   636,   151,   590,   591,   290,     7,   290,   290,     7,
     290,    48,   599,    48,     7,    40,    40,   604,     7,   606,
       7,   290,   740,   741,   611,   168,     7,   614,    41,     7,
     617,    41,    41,   529,    78,   168,    41,     7,     7,     7,
      23,    41,    41,    35,   292,   292,   292,   151,   292,   151,
     546,   290,   639,   290,   641,    35,   552,   291,   554,     7,
     556,     7,   558,   650,   560,   652,     7,     7,     7,    13,
       7,     7,    35,   660,    41,    41,    41,    41,   574,    13,
      41,    41,    41,    41,    41,    41,    41,    41,   675,    41,
      41,   587,   724,   725,   590,   591,     7,   291,   291,     7,
     151,     7,    35,   151,    13,    78,   151,   119,   604,  1031,
      13,   698,   699,   700,    41,   611,    41,   704,    13,    41,
      41,     7,    13,    13,    41,    41,    41,   291,   291,    41,
       7,    41,   719,    13,    41,   722,    41,   724,   725,    41,
     521,  1062,   629,  1063,    -1,    -1,  1064,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   876,    -1,
      -1,   748,    -1,   750,    -1,   201,    -1,   754,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,   766,
      -1,    -1,    -1,    -1,    -1,   903,    -1,    -1,   775,   824,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   798,    -1,    -1,    -1,    -1,   803,   804,    -1,    -1,
      -1,    -1,    -1,    -1,   811,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   820,    -1,   822,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   749,    -1,   751,    -1,    -1,   754,    -1,
      -1,   757,    -1,   759,    -1,   761,    -1,   763,    -1,    -1,
     857,   858,   859,   860,    -1,    -1,    -1,    -1,   865,    -1,
      -1,   777,    -1,    -1,   871,   872,    -1,    -1,    -1,    -1,
     786,    -1,    -1,    -1,    -1,    -1,   883,    -1,   885,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   808,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   962,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     937,    -1,   939,   940,    -1,    -1,    -1,    -1,   945,    -1,
      -1,    -1,   949,    -1,    -1,   952,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   966,
      -1,    -1,    -1,    -1,   971,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   986,
     987,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1004,    -1,    -1,
      -1,    -1,  1009,    -1,    -1,  1012,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1021,    -1,    -1,    -1,    -1,    -1,
      -1,   937,    -1,    -1,    -1,   941,    -1,    -1,    -1,    -1,
     946,  1038,    -1,    -1,    -1,    -1,  1043,    -1,  1045,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1067,  1068,     3,    -1,  1071,    -1,  1073,  1074,    -1,    10,
      11,    -1,    -1,    -1,  1081,    -1,  1083,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,  1005,
      31,    -1,    33,    34,    -1,    36,    37,    -1,    -1,    -1,
      -1,  1108,    -1,    44,    -1,    46,    47,    48,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    92,    93,    -1,    95,    -1,    -1,    98,    99,   100,
      -1,   102,   103,   104,   105,   106,   107,   108,    -1,   110,
      -1,    -1,    -1,   114,   115,   116,   117,   118,    -1,   120,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,    -1,    -1,   145,    -1,   147,   148,   149,    -1,
      -1,   152,    -1,    -1,    -1,   156,    -1,   158,    -1,    -1,
     161,   162,    -1,    -1,    -1,    -1,   167,    -1,   169,   170,
     171,   172,   173,   174,    -1,   176,   177,   178,   179,   180,
     181,     3,    -1,   184,   185,   186,   187,   188,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    31,
      -1,    33,    34,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      92,    93,    -1,    95,    -1,    -1,    98,    99,   100,    -1,
     102,   103,   104,   105,   106,   107,   108,    -1,   110,   290,
      -1,   292,   114,   115,   116,   117,   118,    -1,   120,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,    -1,    -1,   145,    -1,   147,   148,   149,    -1,    -1,
     152,    -1,    -1,    -1,   156,    -1,   158,    -1,    -1,   161,
     162,    -1,    -1,    -1,    -1,   167,    -1,   169,   170,   171,
     172,   173,   174,    -1,   176,   177,   178,   179,   180,   181,
      -1,    -1,   184,   185,   186,   187,   188,     7,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   290,    -1,
      -1,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,   135,   136,   137,    -1,   139,
     140,   141,    -1,   143,   144,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,   159,
      -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,
      -1,    -1,   172,    -1,    -1,   175,    -1,   177,   178,   179,
     180,    -1,   182,   183,    -1,    -1,    -1,    -1,   188,   189,
     190,   191,    -1,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,    -1,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     230,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
      -1,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,     7,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,   135,   136,   137,    -1,   139,   140,   141,    -1,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,   172,    -1,
      -1,   175,    -1,   177,   178,   179,   180,    -1,   182,   183,
      -1,    -1,    -1,    -1,   188,   189,   190,   191,    -1,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,   232,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,     9,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    76,    -1,    -1,    79,    80,    81,    82,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,   135,   136,   137,   138,   139,   140,   141,    -1,
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,   172,
      -1,    -1,   175,    -1,   177,   178,   179,   180,    -1,   182,
     183,    -1,    -1,    -1,    -1,   188,   189,   190,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,   232,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,     9,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    90,    -1,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,   137,    -1,   139,   140,   141,
      -1,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,   159,    -1,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,
     172,    -1,    -1,   175,    -1,   177,   178,   179,   180,    -1,
     182,   183,    -1,    -1,    -1,    -1,   188,   189,   190,   191,
      -1,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,
     232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,     9,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,   137,    -1,   139,   140,
     141,    -1,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,   159,    -1,
     161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,
      -1,   172,    -1,    -1,   175,    -1,   177,   178,   179,   180,
      -1,   182,   183,    -1,    -1,    -1,    -1,   188,   189,   190,
     191,    -1,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,
      -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,     9,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,   135,   136,   137,    -1,   139,
     140,   141,    -1,   143,   144,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,   159,
      -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,
      -1,    -1,   172,    -1,    -1,   175,    -1,   177,   178,   179,
     180,    -1,   182,   183,    -1,    -1,    -1,    -1,   188,   189,
     190,   191,    -1,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,    -1,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     230,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
      -1,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,   137,    -1,   139,   140,   141,    -1,   143,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,   159,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   169,    -1,    -1,   172,    -1,    -1,   175,
      -1,   177,   178,   179,   180,    -1,   182,   183,    -1,    -1,
      -1,    -1,   188,   189,   190,   191,    -1,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,    -1,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,    -1,   232,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,     9,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,   137,    -1,   139,   140,   141,    -1,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,    -1,   159,    -1,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   169,    -1,    -1,   172,    -1,    -1,
     175,    -1,   177,   178,   179,   180,    -1,   182,   183,    -1,
      -1,    -1,    -1,   188,   189,   190,   191,    -1,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,    -1,   204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   230,    -1,   232,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,     9,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    88,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,   135,   136,   137,    -1,   139,   140,   141,    -1,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,   172,    -1,
      -1,   175,    -1,   177,   178,   179,   180,    -1,   182,   183,
      -1,    -1,    -1,    -1,   188,   189,   190,   191,    -1,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,   232,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,     9,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,    -1,   135,   136,   137,    -1,   139,   140,   141,    -1,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,   172,
      -1,    -1,   175,    -1,   177,   178,   179,   180,    -1,   182,
     183,    -1,    -1,    -1,    -1,   188,   189,   190,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
      -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,   232,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,     9,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    90,    -1,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,    -1,    -1,   135,   136,   137,    -1,   139,   140,   141,
      -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,   159,    -1,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,
     172,    -1,    -1,   175,    -1,   177,   178,   179,   180,    -1,
     182,   183,    -1,    -1,    -1,    -1,   188,   189,   190,   191,
      -1,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,
     232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,     9,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    90,
      -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,   137,    -1,   139,   140,
     141,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,   157,    -1,   159,    -1,
     161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,
      -1,   172,    -1,    -1,   175,    -1,   177,   178,   179,   180,
      -1,   182,   183,    -1,    -1,    -1,    -1,   188,   189,   190,
     191,    -1,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    96,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,   230,
      -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,    -1,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,
     209,   210,   211,   212,   213,   214,    -1,   216,   217,    -1,
     219,   220,   221,   222,   223,   224,   225,   226,    -1,   228,
     229,    -1,   231,    -1,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   415,   416,     0,     3,    10,    11,    22,    28,    29,
      31,    33,    34,    36,    37,    44,    46,    47,    48,    53,
      59,    64,    65,    66,    67,    68,    69,    74,    90,    92,
      93,    95,    98,    99,   100,   102,   103,   104,   105,   106,
     107,   108,   110,   114,   115,   116,   117,   118,   120,   121,
     134,   142,   145,   147,   148,   149,   152,   156,   158,   161,
     162,   167,   169,   170,   171,   172,   173,   174,   176,   177,
     178,   179,   180,   181,   184,   185,   186,   187,   188,   290,
     292,   400,   409,   411,   413,   290,   290,     9,    30,    40,
      56,    57,    58,    73,    76,    79,    87,    88,    90,    96,
      97,    98,    99,   111,   112,   113,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   135,   136,
     137,   139,   140,   141,   143,   144,   157,   159,   161,   169,
     172,   175,   177,   178,   179,   180,   182,   183,   188,   189,
     190,   191,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   204,   230,   232,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     305,   306,   307,   308,   309,   313,   317,   390,    30,   290,
     325,   326,   327,    32,    37,    77,   331,   332,   333,    26,
     305,   310,   335,   336,   337,    28,    30,    38,    55,    83,
      84,   290,   322,   323,   324,   305,   310,   338,   339,   340,
      30,    42,    43,    91,   341,   342,   343,    48,    49,    50,
      51,    60,   356,   357,   358,   305,   373,   290,   359,   362,
     290,   292,   360,   401,    30,    42,    43,   305,   347,   348,
     349,    30,   350,   351,   352,    30,    91,   353,   354,   355,
     305,   305,    94,    94,   147,    40,    40,   305,   305,    30,
     344,   345,   346,    30,   363,   364,   365,   290,   292,   361,
     305,   147,    74,    74,   147,   292,   310,   305,   290,    48,
      49,   305,   377,    40,   290,   378,   305,   366,   290,   381,
     385,   290,   290,   290,   290,   291,   388,   388,   390,   305,
      48,    49,   101,   109,   163,   164,   165,   393,   395,     7,
     305,   396,     7,   305,   397,   305,   305,   175,   305,    47,
      98,    99,   398,    47,   399,    13,     4,     6,    13,    20,
     150,   303,   406,   408,   412,     6,     4,     4,   292,    20,
      31,    80,    81,    82,    89,   138,   305,    40,    40,    40,
      31,    80,    81,    82,    87,    88,    89,   311,   312,    20,
     141,   159,    40,   203,    40,   203,   305,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    20,    40,    90,   161,    20,
     141,   159,    20,    20,    20,    20,    20,    20,    20,    40,
     192,    40,    40,   191,   317,    40,    40,    40,    40,    40,
      40,    83,   203,    30,    91,    96,    98,   107,   128,   171,
     207,   209,   210,   211,   212,   213,   214,   216,   217,   219,
     220,   221,   222,   223,   224,   225,   226,   228,   229,   231,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   314,   315,   316,    40,   272,   269,
     272,   273,   279,   273,   279,   272,    20,   150,   318,     5,
       7,     8,     9,    12,    14,    15,    16,    17,    18,   101,
     109,   133,    19,    21,    23,    24,    27,   305,   310,    30,
     305,   310,   305,   310,   305,   310,   292,    85,    86,   153,
     154,   155,   334,    86,   155,   334,    30,   290,   328,   329,
     330,   310,    30,   290,    30,   290,    30,   290,    30,   290,
      30,    30,    31,    38,    42,    43,    51,    60,    62,    63,
      71,    72,    82,   321,    31,    38,    42,    43,    51,    60,
      62,    63,    71,    72,   321,   305,   310,    35,   305,   310,
      52,    52,    59,   106,   147,    20,    48,   305,   305,     7,
     305,   310,   305,   310,    35,    75,   150,   305,   305,   305,
     310,    40,   305,   305,    13,   155,   305,     7,    31,    80,
      81,    82,    89,   127,   138,   146,   380,   382,   383,     7,
     150,   402,   150,     7,    20,    54,     7,     7,   305,     7,
     305,     7,   305,    98,    99,    96,    97,   305,   414,   305,
      13,   407,   403,    40,   380,   290,   409,   410,   413,   413,
      40,    41,    41,    41,    41,    41,    80,    81,    89,    41,
     305,   305,   310,   305,   310,    40,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   309,    40,   290,    40,    40,
      40,   305,   305,   305,    40,    25,   305,   305,   305,   305,
     305,   305,   220,   220,    96,    98,    96,    98,   227,    40,
     305,   319,   320,    40,   392,   391,   307,   307,   306,   306,
     306,   306,   306,   306,   306,   306,   308,   309,   309,   111,
     191,   111,   317,   317,    35,    35,   305,   310,    78,    78,
      78,    78,   305,   310,    30,    54,   310,    30,   310,    30,
     310,    30,   310,    30,   310,   305,    39,    62,    63,    62,
      63,    51,    60,    51,    60,    40,   310,    39,    62,    63,
      62,    63,    51,    60,    51,    60,    40,   305,   310,   305,
     310,   305,   310,   374,   376,   375,    48,   290,     7,   305,
     305,   310,   305,     7,     7,   305,   310,    75,     7,   305,
     106,     7,   305,    80,    81,    89,   384,    40,    20,   385,
     404,   150,   405,   388,     7,   380,   388,    90,   161,   166,
     394,   305,   305,   413,   305,    40,   305,   389,   305,   386,
      40,   409,   305,   292,   292,   292,   292,   292,    41,    41,
      41,    41,    41,    41,    41,    41,   305,     7,     7,     7,
       7,    41,    41,    41,    41,     7,    41,    41,    41,    41,
      41,     7,     7,    41,    41,    41,     7,   290,    41,   305,
     305,   305,    41,     7,    41,     7,   305,   309,    41,    41,
      41,    41,    41,    41,    97,    99,   305,    41,    40,   389,
     386,   390,   390,   191,   317,   317,   290,   290,   305,   310,
     305,   310,    35,    35,   305,   310,    38,    55,    83,    84,
     310,   310,   310,   310,    35,    54,   305,   305,   310,   310,
     290,   367,   290,   369,   290,   371,   290,    13,   305,     7,
      48,    48,   151,   305,   305,     7,     7,   292,   310,    78,
     290,   305,     7,    40,   292,   379,    40,   389,   290,   387,
     389,   388,     7,   168,   168,   386,     7,   151,     7,    41,
     386,     7,   292,   292,   292,    41,   305,   305,   305,   305,
     305,   305,   305,   317,    41,    41,     7,     7,   305,   305,
      41,   386,   151,    41,   317,   290,   290,    35,    35,   291,
      38,    55,    83,    84,     7,     7,   368,   370,   372,    13,
     305,   310,     7,   305,   305,   310,    41,    41,   305,   310,
     305,     7,    41,   305,   379,     7,    41,   379,   151,     7,
      20,    54,   151,   151,   388,    41,   389,   386,    13,    41,
     305,    41,    41,     7,    41,     7,    41,    41,    41,    41,
      41,   305,   305,    41,    41,    41,   291,   291,    35,    35,
     305,   310,     7,     7,     7,   305,   305,    13,    13,    41,
      41,   119,   305,    13,    78,    41,   379,    41,   387,     7,
     380,    13,   305,    13,    41,   305,   305,    41,    41,   291,
     291,    41,    41,   367,   369,   371,   305,   305,   305,    41,
     305,   305,   387,     7,   305,   305,    41,    41,    13,   387,
     305
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   304,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   306,   306,   306,   307,   307,   308,   308,   308,
     309,   309,   309,   309,   309,   309,   309,   309,   310,   311,
     311,   311,   311,   311,   311,   311,   312,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     315,   315,   315,   315,   315,   315,   315,   315,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   318,   317,
     319,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   320,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   321,   321,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   323,   323,   323,   323,   323,   324,   324,   325,
     325,   326,   326,   327,   327,   328,   328,   329,   329,   330,
     330,   331,   331,   331,   332,   332,   332,   333,   333,   334,
     334,   334,   335,   335,   335,   336,   336,   336,   337,   337,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     340,   340,   341,   341,   341,   341,   341,   342,   342,   343,
     343,   344,   345,   346,   346,   347,   347,   348,   348,   349,
     349,   350,   351,   352,   352,   353,   353,   353,   354,   354,
     355,   355,   356,   356,   356,   356,   356,   357,   357,   357,
     358,   358,   359,   359,   359,   359,   359,   359,   360,   360,
     361,   361,   362,   363,   364,   365,   365,   366,   367,   368,
     367,   369,   370,   369,   371,   372,   371,   374,   373,   375,
     373,   376,   373,   377,   377,   377,   378,   378,   379,   379,
     380,   380,   380,   380,   380,   380,   380,   380,   380,   380,
     382,   381,   383,   381,   384,   381,   385,   385,   386,   386,
     387,   387,   387,   387,   387,   387,   388,   388,   388,   388,
     388,   388,   388,   388,   389,   389,   390,   390,   390,   391,
     390,   392,   390,   393,   393,   393,   393,   393,   394,   394,
     394,   394,   394,   395,   396,   396,   396,   397,   397,   397,
     398,   398,   398,   398,   399,   399,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   401,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   400,   402,   400,
     400,   400,   400,   400,   400,   400,   400,   400,   403,   400,
     404,   400,   405,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   400,   400,   400,
     406,   400,   407,   400,   408,   400,   400,   400,   400,   409,
     410,   409,   412,   411,   414,   413,   413,   413,   413,   413,
     416,   415
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
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     0,     5,
       0,     6,     1,     2,     1,     2,     1,     4,     5,     4,
       5,     4,     5,     4,     4,     1,     4,     1,     1,     4,
       4,     4,     4,     6,     6,     6,     8,     6,     8,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     6,
       4,     2,     4,     3,     6,     6,     4,     5,     0,     5,
       4,     4,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     5,     5,     7,     2,     2,     2,
       2,     7,     7,     2,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     2,     1,     6,     1,     1,     1,
       1,     1,     1,     1,     2,     5,     4,     1,     2,     2,
       2,     2,     1,     1,     2,     3,     4,     5,     4,     3,
       5,     4,     4,     3,     4,     5,     4,     3,     5,     4,
       4,     3,     5,     7,     6,     7,     6,     1,     1,     3,
       4,     3,     4,     1,     1,     3,     4,     3,     4,     1,
       1,     2,     4,     4,     2,     4,     4,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     1,     1,
       4,     2,     2,     3,     7,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     2,     2,     3,     7,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     2,     1,     1,     1,     3,     2,     3,     1,
       1,     2,     2,     1,     1,     1,     1,     6,     5,     1,
       1,     2,     2,     1,     1,     2,     1,     5,     2,     5,
       1,     1,     1,     1,     2,     3,     3,     2,     3,     3,
       1,     1,     0,     3,     4,     5,     5,     6,     1,     1,
       1,     1,     1,     6,     6,     1,     1,     1,     1,     0,
       4,     1,     0,     4,     1,     0,     4,     0,     4,     0,
       4,     0,     4,     4,     1,     1,     3,     7,     1,     3,
       1,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       0,     5,     0,     6,     0,     6,     1,     3,     1,     3,
       1,     2,     3,     3,     4,     5,     1,     2,     3,     3,
       4,     5,     1,     3,     1,     3,     1,     2,     2,     0,
       4,     0,     4,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     3,     2,     2,     3,     2,     2,     3,
       1,     2,     1,     2,     2,     2,     2,     2,     3,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     2,     2,     2,     2,     1,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     2,     3,     2,     2,
       1,     1,     2,     2,     1,     2,     3,     1,     4,     1,
       1,     1,     0,     3,     1,     1,     2,     1,     2,     2,
       3,     2,     2,     5,     5,     6,     1,     2,     0,     6,
       2,     2,     2,     5,     8,     2,     2,     2,     0,     5,
       0,     6,     0,     6,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     2,     2,     2,     2,     1,
       2,     1,     1,     8,     8,     8,    10,     2,     3,     4,
       0,     7,     0,     8,     0,     8,     2,     1,     0,     1,
       0,     4,     0,     3,     0,     4,     1,     3,     1,     3,
       0,     2
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
#line 87 "src/ugbc.y"
                              {
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3483 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 91 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3492 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math OP_EQUAL expr_math  */
#line 95 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3500 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math OP_DISEQUAL expr_math  */
#line 98 "src/ugbc.y"
                                      {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3508 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math OP_LT expr_math  */
#line 101 "src/ugbc.y"
                                {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3516 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math OP_LTE expr_math  */
#line 104 "src/ugbc.y"
                                 {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 3524 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math OP_GT expr_math  */
#line 107 "src/ugbc.y"
                                {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3532 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math OP_GTE expr_math  */
#line 110 "src/ugbc.y"
                                 {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3540 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 113 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 3548 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math OP_PLUS term  */
#line 120 "src/ugbc.y"
                             {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3556 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math OP_MINUS term  */
#line 123 "src/ugbc.y"
                              {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3565 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula OP_MULTIPLICATION factor  */
#line 136 "src/ugbc.y"
                                      {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3574 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula OP_DIVISION factor  */
#line 140 "src/ugbc.y"
                                {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3583 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor OP_POW exponential  */
#line 148 "src/ugbc.y"
                                  {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 3592 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor OP_COMMA exponential CP  */
#line 152 "src/ugbc.y"
                                                   {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 3601 "src-generated/ugbc.tab.c"
    break;

  case 23: /* factor: factor HAS BIT exponential  */
#line 156 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[0].string) )->name;
      }
#line 3609 "src-generated/ugbc.tab.c"
    break;

  case 24: /* factor: factor HAS NOT BIT exponential  */
#line 159 "src/ugbc.y"
                                       {
        (yyval.string) = variable_not( _environment, variable_bit( _environment, (yyvsp[-4].string), (yyvsp[0].string) )->name )->name;
      }
#line 3617 "src-generated/ugbc.tab.c"
    break;

  case 25: /* factor: factor IS exponential  */
#line 162 "src/ugbc.y"
                              {
        (yyval.string) = variable_bit( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
      }
#line 3625 "src-generated/ugbc.tab.c"
    break;

  case 26: /* factor: factor IS NOT exponential  */
#line 165 "src/ugbc.y"
                                  {
        (yyval.string) = variable_not( _environment, variable_bit( _environment, (yyvsp[-3].string), (yyvsp[0].string) )->name )->name;
      }
#line 3633 "src-generated/ugbc.tab.c"
    break;

  case 27: /* factor: BIT exponential OF factor  */
#line 168 "src/ugbc.y"
                                  {
        (yyval.string) = variable_bit( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
      }
#line 3641 "src-generated/ugbc.tab.c"
    break;

  case 28: /* direct_integer: OP_HASH Integer  */
#line 174 "src/ugbc.y"
                    {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3649 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: BYTE  */
#line 179 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3657 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: WORD  */
#line 182 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3665 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition_simple: DWORD  */
#line 185 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3673 "src-generated/ugbc.tab.c"
    break;

  case 32: /* random_definition_simple: POSITION  */
#line 188 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3681 "src-generated/ugbc.tab.c"
    break;

  case 33: /* random_definition_simple: COLOR  */
#line 191 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3689 "src-generated/ugbc.tab.c"
    break;

  case 34: /* random_definition_simple: WIDTH  */
#line 194 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3697 "src-generated/ugbc.tab.c"
    break;

  case 35: /* random_definition_simple: HEIGHT  */
#line 197 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3705 "src-generated/ugbc.tab.c"
    break;

  case 36: /* random_definition: random_definition_simple  */
#line 202 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3713 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: BLACK  */
#line 207 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3722 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: WHITE  */
#line 211 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3731 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: RED  */
#line 215 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3740 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: CYAN  */
#line 219 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3749 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: VIOLET  */
#line 223 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3758 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: GREEN  */
#line 227 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3767 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: BLUE  */
#line 231 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3776 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: YELLOW  */
#line 235 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3785 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: ORANGE  */
#line 239 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3794 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: BROWN  */
#line 243 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3803 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT RED  */
#line 247 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3812 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK GREY  */
#line 251 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3821 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: GREY  */
#line 255 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3830 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: LIGHT GREEN  */
#line 259 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3839 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LIGHT BLUE  */
#line 263 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3848 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: LIGHT GREY  */
#line 267 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3857 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: DARK BLUE  */
#line 271 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3866 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: MAGENTA  */
#line 275 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3875 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: PURPLE  */
#line 279 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3884 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: LAVENDER  */
#line 283 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 3893 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: GOLD  */
#line 287 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 3902 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: TURQUOISE  */
#line 291 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 3911 "src-generated/ugbc.tab.c"
    break;

  case 59: /* color_enumeration: TAN  */
#line 295 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 3920 "src-generated/ugbc.tab.c"
    break;

  case 60: /* color_enumeration: YELLOW GREEN  */
#line 299 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 3929 "src-generated/ugbc.tab.c"
    break;

  case 61: /* color_enumeration: OLIVE GREEN  */
#line 303 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 3938 "src-generated/ugbc.tab.c"
    break;

  case 62: /* color_enumeration: PINK  */
#line 307 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 3947 "src-generated/ugbc.tab.c"
    break;

  case 63: /* color_enumeration: PEACH  */
#line 311 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 3956 "src-generated/ugbc.tab.c"
    break;

  case 64: /* key_scancode_alphadigit: "0"  */
#line 317 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 0)")->name;
        variable_store( _environment, (yyval.string), KEY_0 );
    }
#line 3965 "src-generated/ugbc.tab.c"
    break;

  case 65: /* key_scancode_alphadigit: "1"  */
#line 321 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 1)")->name;
        variable_store( _environment, (yyval.string), KEY_1 );
    }
#line 3974 "src-generated/ugbc.tab.c"
    break;

  case 66: /* key_scancode_alphadigit: "2"  */
#line 325 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 2)")->name;
        variable_store( _environment, (yyval.string), KEY_2 );
    }
#line 3983 "src-generated/ugbc.tab.c"
    break;

  case 67: /* key_scancode_alphadigit: "3"  */
#line 329 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 3)")->name;
        variable_store( _environment, (yyval.string), KEY_3 );
    }
#line 3992 "src-generated/ugbc.tab.c"
    break;

  case 68: /* key_scancode_alphadigit: "4"  */
#line 333 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 4)")->name;
        variable_store( _environment, (yyval.string), KEY_4 );
    }
#line 4001 "src-generated/ugbc.tab.c"
    break;

  case 69: /* key_scancode_alphadigit: "5"  */
#line 337 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 5)")->name;
        variable_store( _environment, (yyval.string), KEY_5 );
    }
#line 4010 "src-generated/ugbc.tab.c"
    break;

  case 70: /* key_scancode_alphadigit: "6"  */
#line 341 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 6)")->name;
        variable_store( _environment, (yyval.string), KEY_6 );
    }
#line 4019 "src-generated/ugbc.tab.c"
    break;

  case 71: /* key_scancode_alphadigit: "7"  */
#line 345 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 7)")->name;
        variable_store( _environment, (yyval.string), KEY_7 );
    }
#line 4028 "src-generated/ugbc.tab.c"
    break;

  case 72: /* key_scancode_alphadigit: "8"  */
#line 349 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 8)")->name;
        variable_store( _environment, (yyval.string), KEY_8 );
    }
#line 4037 "src-generated/ugbc.tab.c"
    break;

  case 73: /* key_scancode_alphadigit: "9"  */
#line 353 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 9)")->name;
        variable_store( _environment, (yyval.string), KEY_9 );
    }
#line 4046 "src-generated/ugbc.tab.c"
    break;

  case 74: /* key_scancode_alphadigit: A  */
#line 357 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER A)")->name;
        variable_store( _environment, (yyval.string), KEY_A );
    }
#line 4055 "src-generated/ugbc.tab.c"
    break;

  case 75: /* key_scancode_alphadigit: B  */
#line 361 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER B)")->name;
        variable_store( _environment, (yyval.string), KEY_B );
    }
#line 4064 "src-generated/ugbc.tab.c"
    break;

  case 76: /* key_scancode_alphadigit: C  */
#line 365 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER C)")->name;
        variable_store( _environment, (yyval.string), KEY_C );
    }
#line 4073 "src-generated/ugbc.tab.c"
    break;

  case 77: /* key_scancode_alphadigit: D  */
#line 369 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER D)")->name;
        variable_store( _environment, (yyval.string), KEY_D );
    }
#line 4082 "src-generated/ugbc.tab.c"
    break;

  case 78: /* key_scancode_alphadigit: E  */
#line 373 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER E)")->name;
        variable_store( _environment, (yyval.string), KEY_E );
    }
#line 4091 "src-generated/ugbc.tab.c"
    break;

  case 79: /* key_scancode_alphadigit: F  */
#line 377 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER F)")->name;
        variable_store( _environment, (yyval.string), KEY_F );
    }
#line 4100 "src-generated/ugbc.tab.c"
    break;

  case 80: /* key_scancode_alphadigit: G  */
#line 381 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER G)")->name;
        variable_store( _environment, (yyval.string), KEY_G );
    }
#line 4109 "src-generated/ugbc.tab.c"
    break;

  case 81: /* key_scancode_alphadigit: H  */
#line 385 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER H)")->name;
        variable_store( _environment, (yyval.string), KEY_H );
    }
#line 4118 "src-generated/ugbc.tab.c"
    break;

  case 82: /* key_scancode_alphadigit: I  */
#line 389 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER I)")->name;
        variable_store( _environment, (yyval.string), KEY_I );
    }
#line 4127 "src-generated/ugbc.tab.c"
    break;

  case 83: /* key_scancode_alphadigit: J  */
#line 393 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER J)")->name;
        variable_store( _environment, (yyval.string), KEY_J );
    }
#line 4136 "src-generated/ugbc.tab.c"
    break;

  case 84: /* key_scancode_alphadigit: K  */
#line 397 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER K)")->name;
        variable_store( _environment, (yyval.string), KEY_K );
    }
#line 4145 "src-generated/ugbc.tab.c"
    break;

  case 85: /* key_scancode_alphadigit: L  */
#line 401 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER L)")->name;
        variable_store( _environment, (yyval.string), KEY_L );
    }
#line 4154 "src-generated/ugbc.tab.c"
    break;

  case 86: /* key_scancode_alphadigit: M  */
#line 405 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER M)")->name;
        variable_store( _environment, (yyval.string), KEY_M );
    }
#line 4163 "src-generated/ugbc.tab.c"
    break;

  case 87: /* key_scancode_alphadigit: N  */
#line 409 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER N)")->name;
        variable_store( _environment, (yyval.string), KEY_N );
    }
#line 4172 "src-generated/ugbc.tab.c"
    break;

  case 88: /* key_scancode_alphadigit: O  */
#line 413 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER O)")->name;
        variable_store( _environment, (yyval.string), KEY_O );
    }
#line 4181 "src-generated/ugbc.tab.c"
    break;

  case 89: /* key_scancode_alphadigit: P  */
#line 417 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER P)")->name;
        variable_store( _environment, (yyval.string), KEY_P );
    }
#line 4190 "src-generated/ugbc.tab.c"
    break;

  case 90: /* key_scancode_alphadigit: Q  */
#line 421 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER Q)")->name;
        variable_store( _environment, (yyval.string), KEY_Q );
    }
#line 4199 "src-generated/ugbc.tab.c"
    break;

  case 91: /* key_scancode_alphadigit: R  */
#line 425 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER R)")->name;
        variable_store( _environment, (yyval.string), KEY_R );
    }
#line 4208 "src-generated/ugbc.tab.c"
    break;

  case 92: /* key_scancode_alphadigit: S  */
#line 429 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER S)")->name;
        variable_store( _environment, (yyval.string), KEY_S );
    }
#line 4217 "src-generated/ugbc.tab.c"
    break;

  case 93: /* key_scancode_alphadigit: T  */
#line 433 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER T)")->name;
        variable_store( _environment, (yyval.string), KEY_T );
    }
#line 4226 "src-generated/ugbc.tab.c"
    break;

  case 94: /* key_scancode_alphadigit: U  */
#line 437 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER U)")->name;
        variable_store( _environment, (yyval.string), KEY_U );
    }
#line 4235 "src-generated/ugbc.tab.c"
    break;

  case 95: /* key_scancode_alphadigit: V  */
#line 441 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER V)")->name;
        variable_store( _environment, (yyval.string), KEY_V );
    }
#line 4244 "src-generated/ugbc.tab.c"
    break;

  case 96: /* key_scancode_alphadigit: X  */
#line 445 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER X)")->name;
        variable_store( _environment, (yyval.string), KEY_X );
    }
#line 4253 "src-generated/ugbc.tab.c"
    break;

  case 97: /* key_scancode_alphadigit: Y  */
#line 449 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER Y)")->name;
        variable_store( _environment, (yyval.string), KEY_Y );
    }
#line 4262 "src-generated/ugbc.tab.c"
    break;

  case 98: /* key_scancode_alphadigit: W  */
#line 453 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER W)")->name;
        variable_store( _environment, (yyval.string), KEY_W );
    }
#line 4271 "src-generated/ugbc.tab.c"
    break;

  case 99: /* key_scancode_alphadigit: Z  */
#line 457 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER Z)")->name;
        variable_store( _environment, (yyval.string), KEY_Z );
    }
#line 4280 "src-generated/ugbc.tab.c"
    break;

  case 100: /* key_scancode_function_digit: F1  */
#line 464 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F1)")->name;
        variable_store( _environment, (yyval.string), KEY_F1 );
    }
#line 4289 "src-generated/ugbc.tab.c"
    break;

  case 101: /* key_scancode_function_digit: F2  */
#line 468 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F2)")->name;
        variable_store( _environment, (yyval.string), KEY_F2 );
    }
#line 4298 "src-generated/ugbc.tab.c"
    break;

  case 102: /* key_scancode_function_digit: F3  */
#line 472 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F3)")->name;
        variable_store( _environment, (yyval.string), KEY_F3 );
    }
#line 4307 "src-generated/ugbc.tab.c"
    break;

  case 103: /* key_scancode_function_digit: F4  */
#line 476 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F4)")->name;
        variable_store( _environment, (yyval.string), KEY_F4 );
    }
#line 4316 "src-generated/ugbc.tab.c"
    break;

  case 104: /* key_scancode_function_digit: F5  */
#line 480 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F5)")->name;
        variable_store( _environment, (yyval.string), KEY_F5 );
    }
#line 4325 "src-generated/ugbc.tab.c"
    break;

  case 105: /* key_scancode_function_digit: F6  */
#line 484 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F6)")->name;
        variable_store( _environment, (yyval.string), KEY_F6 );
    }
#line 4334 "src-generated/ugbc.tab.c"
    break;

  case 106: /* key_scancode_function_digit: F7  */
#line 488 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F7)")->name;
        variable_store( _environment, (yyval.string), KEY_F7 );
    }
#line 4343 "src-generated/ugbc.tab.c"
    break;

  case 107: /* key_scancode_function_digit: F8  */
#line 492 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F8)")->name;
        variable_store( _environment, (yyval.string), KEY_F8 );
    }
#line 4352 "src-generated/ugbc.tab.c"
    break;

  case 108: /* key_scancode_definition: NONE  */
#line 498 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode NONE)")->name;
        variable_store( _environment, (yyval.string), KEY_NONE );
    }
#line 4361 "src-generated/ugbc.tab.c"
    break;

  case 109: /* key_scancode_definition: key_scancode_alphadigit  */
#line 502 "src/ugbc.y"
                              {
        (yyval.string) = (yyvsp[0].string);
    }
#line 4369 "src-generated/ugbc.tab.c"
    break;

  case 110: /* key_scancode_definition: ASTERISK  */
#line 505 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode ASTERISK)")->name;
        variable_store( _environment, (yyval.string), KEY_ASTERISK );
    }
#line 4378 "src-generated/ugbc.tab.c"
    break;

  case 111: /* key_scancode_definition: AT  */
#line 509 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode AT)")->name;
        variable_store( _environment, (yyval.string), KEY_AT );
    }
#line 4387 "src-generated/ugbc.tab.c"
    break;

  case 112: /* key_scancode_definition: CLEAR  */
#line 513 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode CLEAR)")->name;
        variable_store( _environment, (yyval.string), KEY_CLEAR );
    }
#line 4396 "src-generated/ugbc.tab.c"
    break;

  case 113: /* key_scancode_definition: COLON  */
#line 517 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode COLON)")->name;
        variable_store( _environment, (yyval.string), KEY_COLON );
    }
#line 4405 "src-generated/ugbc.tab.c"
    break;

  case 114: /* key_scancode_definition: COMMA  */
#line 521 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode COMMA)")->name;
        variable_store( _environment, (yyval.string), KEY_COMMA );
    }
#line 4414 "src-generated/ugbc.tab.c"
    break;

  case 115: /* key_scancode_definition: COMMODORE  */
#line 525 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode COMMODORE)")->name;
        variable_store( _environment, (yyval.string), KEY_COMMODORE );
    }
#line 4423 "src-generated/ugbc.tab.c"
    break;

  case 116: /* key_scancode_definition: CONTROL  */
#line 529 "src/ugbc.y"
              {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode CONTROL)")->name;
        variable_store( _environment, (yyval.string), KEY_CONTROL );
    }
#line 4432 "src-generated/ugbc.tab.c"
    break;

  case 117: /* key_scancode_definition: CRSR LEFT RIGHT  */
#line 533 "src/ugbc.y"
                      {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode CRSR LEFT RIGHT)")->name;
        variable_store( _environment, (yyval.string), KEY_CRSR_LEFT_RIGHT );
    }
#line 4441 "src-generated/ugbc.tab.c"
    break;

  case 118: /* key_scancode_definition: CRSR UP DOWN  */
#line 537 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode CRSR UP DOWN)")->name;
        variable_store( _environment, (yyval.string), KEY_CRSR_UP_DOWN );
    }
#line 4450 "src-generated/ugbc.tab.c"
    break;

  case 119: /* key_scancode_definition: DELETE  */
#line 541 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DELETE)")->name;
        variable_store( _environment, (yyval.string), KEY_DELETE );
    }
#line 4459 "src-generated/ugbc.tab.c"
    break;

  case 120: /* key_scancode_definition: EQUAL  */
#line 545 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode EQUAL)")->name;
        variable_store( _environment, (yyval.string), KEY_EQUAL );
    }
#line 4468 "src-generated/ugbc.tab.c"
    break;

  case 121: /* key_scancode_definition: key_scancode_function_digit  */
#line 549 "src/ugbc.y"
                                  {
        (yyval.string) = (yyvsp[0].string);
    }
#line 4476 "src-generated/ugbc.tab.c"
    break;

  case 122: /* key_scancode_definition: HOME  */
#line 552 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode HOME)")->name;
        variable_store( _environment, (yyval.string), KEY_HOME );
    }
#line 4485 "src-generated/ugbc.tab.c"
    break;

  case 123: /* key_scancode_definition: INSERT  */
#line 556 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode INSERT)")->name;
        variable_store( _environment, (yyval.string), KEY_INSERT );
    }
#line 4494 "src-generated/ugbc.tab.c"
    break;

  case 124: /* key_scancode_definition: ARROW LEFT  */
#line 560 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode ARROW LEFT)")->name;
        variable_store( _environment, (yyval.string), KEY_LEFT_ARROW );
    }
#line 4503 "src-generated/ugbc.tab.c"
    break;

  case 125: /* key_scancode_definition: LEFT ARROW  */
#line 564 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode ARROW LEFT)")->name;
        variable_store( _environment, (yyval.string), KEY_LEFT_ARROW );
    }
#line 4512 "src-generated/ugbc.tab.c"
    break;

  case 126: /* key_scancode_definition: ARROW UP  */
#line 568 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode ARROW UP)")->name;
        variable_store( _environment, (yyval.string), KEY_UP_ARROW );
    }
#line 4521 "src-generated/ugbc.tab.c"
    break;

  case 127: /* key_scancode_definition: UP ARROW  */
#line 572 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode ARROW UP)")->name;
        variable_store( _environment, (yyval.string), KEY_UP_ARROW );
    }
#line 4530 "src-generated/ugbc.tab.c"
    break;

  case 128: /* key_scancode_definition: MINUS  */
#line 576 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode MINUS)")->name;
        variable_store( _environment, (yyval.string), KEY_MINUS );
    }
#line 4539 "src-generated/ugbc.tab.c"
    break;

  case 129: /* key_scancode_definition: PERIOD  */
#line 580 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode PERIOD)")->name;
        variable_store( _environment, (yyval.string), KEY_PERIOD );
    }
#line 4548 "src-generated/ugbc.tab.c"
    break;

  case 130: /* key_scancode_definition: PLUS  */
#line 584 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode PLUS)")->name;
        variable_store( _environment, (yyval.string), KEY_PLUS );
    }
#line 4557 "src-generated/ugbc.tab.c"
    break;

  case 131: /* key_scancode_definition: POUND  */
#line 588 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode POUND)")->name;
        variable_store( _environment, (yyval.string), KEY_POUND );
    }
#line 4566 "src-generated/ugbc.tab.c"
    break;

  case 132: /* key_scancode_definition: RETURN  */
#line 592 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode RETURN)")->name;
        variable_store( _environment, (yyval.string), KEY_RETURN );
    }
#line 4575 "src-generated/ugbc.tab.c"
    break;

  case 133: /* key_scancode_definition: RUNSTOP  */
#line 596 "src/ugbc.y"
              {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode RUNSTOP)")->name;
        variable_store( _environment, (yyval.string), KEY_RUNSTOP );        
    }
#line 4584 "src-generated/ugbc.tab.c"
    break;

  case 134: /* key_scancode_definition: RUN STOP  */
#line 600 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode RUNSTOP)")->name;
        variable_store( _environment, (yyval.string), KEY_RUNSTOP );        
    }
#line 4593 "src-generated/ugbc.tab.c"
    break;

  case 135: /* key_scancode_definition: SEMICOLON  */
#line 604 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode SEMICOLON)")->name;
        variable_store( _environment, (yyval.string), KEY_SEMICOLON );
    }
#line 4602 "src-generated/ugbc.tab.c"
    break;

  case 136: /* key_scancode_definition: SLASH  */
#line 608 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode SLASH)")->name;
        variable_store( _environment, (yyval.string), KEY_SLASH );        
    }
#line 4611 "src-generated/ugbc.tab.c"
    break;

  case 137: /* key_scancode_definition: SPACE  */
#line 612 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode SPACE)")->name;
        variable_store( _environment, (yyval.string), KEY_SPACE );        
    }
#line 4620 "src-generated/ugbc.tab.c"
    break;

  case 138: /* $@1: %empty  */
#line 618 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 4629 "src-generated/ugbc.tab.c"
    break;

  case 139: /* exponential: Identifier $@1 OP indexes CP  */
#line 622 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-4].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-4].string) )->name;
    }
#line 4641 "src-generated/ugbc.tab.c"
    break;

  case 140: /* $@2: %empty  */
#line 629 "src/ugbc.y"
                           {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 4650 "src-generated/ugbc.tab.c"
    break;

  case 141: /* exponential: Identifier OP_DOLLAR $@2 OP indexes CP  */
#line 633 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-5].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-5].string) )->name;
    }
#line 4662 "src-generated/ugbc.tab.c"
    break;

  case 142: /* exponential: Identifier  */
#line 640 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 4670 "src-generated/ugbc.tab.c"
    break;

  case 143: /* exponential: Identifier OP_DOLLAR  */
#line 643 "src/ugbc.y"
                           { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
      }
#line 4678 "src-generated/ugbc.tab.c"
    break;

  case 144: /* exponential: Integer  */
#line 646 "src/ugbc.y"
              { 
        if ( (yyvsp[0].integer) < 0 ) {
            (yyval.string) = variable_temporary( _environment, VT_SWORD, "(signed integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        } else {
            (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        }
      }
#line 4692 "src-generated/ugbc.tab.c"
    break;

  case 145: /* exponential: OP_MINUS Integer  */
#line 655 "src/ugbc.y"
                       { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 4701 "src-generated/ugbc.tab.c"
    break;

  case 146: /* exponential: String  */
#line 659 "src/ugbc.y"
             { 
        outline1("; (expr string: \"%s\")", (yyvsp[0].string) );
        (yyval.string) = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", (yyval.string) );
        variable_store_string( _environment, (yyval.string), (yyvsp[0].string) );
        outline2("; variable stored: %s = %s", (yyval.string), (yyvsp[0].string) );
      }
#line 4713 "src-generated/ugbc.tab.c"
    break;

  case 147: /* exponential: OP BYTE CP Integer  */
#line 666 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4722 "src-generated/ugbc.tab.c"
    break;

  case 148: /* exponential: OP SIGNED BYTE CP Integer  */
#line 670 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4731 "src-generated/ugbc.tab.c"
    break;

  case 149: /* exponential: OP WORD CP Integer  */
#line 674 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4740 "src-generated/ugbc.tab.c"
    break;

  case 150: /* exponential: OP SIGNED WORD CP Integer  */
#line 678 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4749 "src-generated/ugbc.tab.c"
    break;

  case 151: /* exponential: OP DWORD CP Integer  */
#line 682 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4758 "src-generated/ugbc.tab.c"
    break;

  case 152: /* exponential: OP SIGNED DWORD CP Integer  */
#line 686 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4767 "src-generated/ugbc.tab.c"
    break;

  case 153: /* exponential: OP POSITION CP Integer  */
#line 690 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4776 "src-generated/ugbc.tab.c"
    break;

  case 154: /* exponential: OP COLOR CP Integer  */
#line 694 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4785 "src-generated/ugbc.tab.c"
    break;

  case 155: /* exponential: color_enumeration  */
#line 698 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 4793 "src-generated/ugbc.tab.c"
    break;

  case 156: /* exponential: PEEK OP expr CP  */
#line 701 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 4801 "src-generated/ugbc.tab.c"
    break;

  case 157: /* exponential: XPEN  */
#line 704 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 4809 "src-generated/ugbc.tab.c"
    break;

  case 158: /* exponential: YPEN  */
#line 707 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 4817 "src-generated/ugbc.tab.c"
    break;

  case 159: /* exponential: COLLISION OP direct_integer CP  */
#line 710 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 4825 "src-generated/ugbc.tab.c"
    break;

  case 160: /* exponential: COLLISION OP expr CP  */
#line 713 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 4833 "src-generated/ugbc.tab.c"
    break;

  case 161: /* exponential: HIT OP direct_integer CP  */
#line 716 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 4841 "src-generated/ugbc.tab.c"
    break;

  case 162: /* exponential: HIT OP expr CP  */
#line 719 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 4849 "src-generated/ugbc.tab.c"
    break;

  case 163: /* exponential: LEFT OP expr OP_COMMA expr CP  */
#line 722 "src/ugbc.y"
                                    {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4857 "src-generated/ugbc.tab.c"
    break;

  case 164: /* exponential: RIGHT OP expr OP_COMMA expr CP  */
#line 725 "src/ugbc.y"
                                     {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4865 "src-generated/ugbc.tab.c"
    break;

  case 165: /* exponential: MID OP expr OP_COMMA expr CP  */
#line 728 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 4873 "src-generated/ugbc.tab.c"
    break;

  case 166: /* exponential: MID OP expr OP_COMMA expr OP_COMMA expr CP  */
#line 731 "src/ugbc.y"
                                                 {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4881 "src-generated/ugbc.tab.c"
    break;

  case 167: /* exponential: INSTR OP expr OP_COMMA expr CP  */
#line 734 "src/ugbc.y"
                                     {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 4889 "src-generated/ugbc.tab.c"
    break;

  case 168: /* exponential: INSTR OP expr OP_COMMA expr OP_COMMA expr CP  */
#line 737 "src/ugbc.y"
                                                   {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4897 "src-generated/ugbc.tab.c"
    break;

  case 169: /* exponential: UPPER OP expr CP  */
#line 740 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 4905 "src-generated/ugbc.tab.c"
    break;

  case 170: /* exponential: LOWER OP expr CP  */
#line 743 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 4913 "src-generated/ugbc.tab.c"
    break;

  case 171: /* exponential: STR OP expr CP  */
#line 746 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 4921 "src-generated/ugbc.tab.c"
    break;

  case 172: /* exponential: BIN OP expr CP  */
#line 749 "src/ugbc.y"
                     {
        (yyval.string) = variable_bin( _environment, (yyvsp[-1].string), NULL )->name;
    }
#line 4929 "src-generated/ugbc.tab.c"
    break;

  case 173: /* exponential: BIN OP expr OP_COMMA expr CP  */
#line 752 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bin( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4937 "src-generated/ugbc.tab.c"
    break;

  case 174: /* exponential: SPACE OP expr CP  */
#line 755 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 4945 "src-generated/ugbc.tab.c"
    break;

  case 175: /* exponential: FLIP OP expr CP  */
#line 758 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 4953 "src-generated/ugbc.tab.c"
    break;

  case 176: /* exponential: CHR OP expr CP  */
#line 761 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 4961 "src-generated/ugbc.tab.c"
    break;

  case 177: /* exponential: ASC OP expr CP  */
#line 764 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 4969 "src-generated/ugbc.tab.c"
    break;

  case 178: /* exponential: LEN OP expr CP  */
#line 767 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 4977 "src-generated/ugbc.tab.c"
    break;

  case 179: /* exponential: STRING OP expr OP_COMMA expr CP  */
#line 770 "src/ugbc.y"
                                      {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4985 "src-generated/ugbc.tab.c"
    break;

  case 180: /* exponential: VAL OP expr CP  */
#line 773 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 4993 "src-generated/ugbc.tab.c"
    break;

  case 181: /* exponential: RANDOM random_definition  */
#line 776 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 5001 "src-generated/ugbc.tab.c"
    break;

  case 182: /* exponential: RND OP expr CP  */
#line 779 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 5009 "src-generated/ugbc.tab.c"
    break;

  case 183: /* exponential: OP expr CP  */
#line 782 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 5017 "src-generated/ugbc.tab.c"
    break;

  case 184: /* exponential: MAX OP expr OP_COMMA expr CP  */
#line 785 "src/ugbc.y"
                                   {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5025 "src-generated/ugbc.tab.c"
    break;

  case 185: /* exponential: MIN OP expr OP_COMMA expr CP  */
#line 788 "src/ugbc.y"
                                   {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5033 "src-generated/ugbc.tab.c"
    break;

  case 186: /* exponential: PARAM OP Identifier CP  */
#line 791 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 5041 "src-generated/ugbc.tab.c"
    break;

  case 187: /* exponential: PARAM OP_DOLLAR OP Identifier CP  */
#line 794 "src/ugbc.y"
                                       {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 5049 "src-generated/ugbc.tab.c"
    break;

  case 188: /* $@3: %empty  */
#line 797 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5057 "src-generated/ugbc.tab.c"
    break;

  case 189: /* exponential: Identifier OSP $@3 values CSP  */
#line 799 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 5066 "src-generated/ugbc.tab.c"
    break;

  case 190: /* exponential: SGN OP expr CP  */
#line 803 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 5074 "src-generated/ugbc.tab.c"
    break;

  case 191: /* exponential: ABS OP expr CP  */
#line 806 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 5082 "src-generated/ugbc.tab.c"
    break;

  case 192: /* exponential: TRUE  */
#line 809 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 5091 "src-generated/ugbc.tab.c"
    break;

  case 193: /* exponential: FALSE  */
#line 813 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 0 );
    }
#line 5100 "src-generated/ugbc.tab.c"
    break;

  case 194: /* exponential: COLORS  */
#line 817 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 5109 "src-generated/ugbc.tab.c"
    break;

  case 195: /* exponential: PEN COLORS  */
#line 821 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 5118 "src-generated/ugbc.tab.c"
    break;

  case 196: /* exponential: PEN DEFAULT  */
#line 825 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 5127 "src-generated/ugbc.tab.c"
    break;

  case 197: /* exponential: DEFAULT PEN  */
#line 829 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 5136 "src-generated/ugbc.tab.c"
    break;

  case 198: /* exponential: PAPER COLORS  */
#line 833 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 5145 "src-generated/ugbc.tab.c"
    break;

  case 199: /* exponential: PAPER DEFAULT  */
#line 837 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 5154 "src-generated/ugbc.tab.c"
    break;

  case 200: /* exponential: DEFAULT PAPER  */
#line 841 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 5163 "src-generated/ugbc.tab.c"
    break;

  case 201: /* exponential: WIDTH  */
#line 845 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 5171 "src-generated/ugbc.tab.c"
    break;

  case 202: /* exponential: HEIGHT  */
#line 848 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 5179 "src-generated/ugbc.tab.c"
    break;

  case 203: /* exponential: TIMER  */
#line 851 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 5187 "src-generated/ugbc.tab.c"
    break;

  case 204: /* exponential: PEN OP_DOLLAR OP expr CP  */
#line 854 "src/ugbc.y"
                               {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 5195 "src-generated/ugbc.tab.c"
    break;

  case 205: /* exponential: PAPER OP_DOLLAR OP expr CP  */
#line 857 "src/ugbc.y"
                                 {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 5203 "src-generated/ugbc.tab.c"
    break;

  case 206: /* exponential: CMOVE OP_DOLLAR OP expr OP_COMMA expr CP  */
#line 860 "src/ugbc.y"
                                               {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5211 "src-generated/ugbc.tab.c"
    break;

  case 207: /* exponential: CUP OP_DOLLAR  */
#line 863 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 5219 "src-generated/ugbc.tab.c"
    break;

  case 208: /* exponential: CDOWN OP_DOLLAR  */
#line 866 "src/ugbc.y"
                      {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 5227 "src-generated/ugbc.tab.c"
    break;

  case 209: /* exponential: CLEFT OP_DOLLAR  */
#line 869 "src/ugbc.y"
                      {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 5235 "src-generated/ugbc.tab.c"
    break;

  case 210: /* exponential: CRIGHT OP_DOLLAR  */
#line 872 "src/ugbc.y"
                       {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 5243 "src-generated/ugbc.tab.c"
    break;

  case 211: /* exponential: AT OP_DOLLAR OP expr OP_COMMA expr CP  */
#line 875 "src/ugbc.y"
                                            {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5251 "src-generated/ugbc.tab.c"
    break;

  case 212: /* exponential: LOCATE OP_DOLLAR OP expr OP_COMMA expr CP  */
#line 878 "src/ugbc.y"
                                                {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5259 "src-generated/ugbc.tab.c"
    break;

  case 213: /* exponential: TAB OP_DOLLAR  */
#line 881 "src/ugbc.y"
                    {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 5267 "src-generated/ugbc.tab.c"
    break;

  case 214: /* exponential: XCURS  */
#line 884 "src/ugbc.y"
            {
        (yyval.string) = text_get_xcurs( _environment )->name;
    }
#line 5275 "src-generated/ugbc.tab.c"
    break;

  case 215: /* exponential: YCURS  */
#line 887 "src/ugbc.y"
            {
        (yyval.string) = text_get_ycurs( _environment )->name;
    }
#line 5283 "src-generated/ugbc.tab.c"
    break;

  case 216: /* exponential: TEXTADDRESS  */
#line 890 "src/ugbc.y"
                  {
        (yyval.string) = strdup( "TEXTADDRESS" );
    }
#line 5291 "src-generated/ugbc.tab.c"
    break;

  case 217: /* exponential: JOY OP expr CP  */
#line 893 "src/ugbc.y"
                     {
        (yyval.string) = joy( _environment, (yyvsp[-1].string) )->name;
    }
#line 5299 "src-generated/ugbc.tab.c"
    break;

  case 218: /* exponential: JUP OP expr CP  */
#line 896 "src/ugbc.y"
                     {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_UP )->name;
    }
#line 5307 "src-generated/ugbc.tab.c"
    break;

  case 219: /* exponential: JDOWN OP expr CP  */
#line 899 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_DOWN )->name;
    }
#line 5315 "src-generated/ugbc.tab.c"
    break;

  case 220: /* exponential: JLEFT OP expr CP  */
#line 902 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_LEFT )->name;
    }
#line 5323 "src-generated/ugbc.tab.c"
    break;

  case 221: /* exponential: JRIGHT OP expr CP  */
#line 905 "src/ugbc.y"
                        {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_RIGHT )->name;
    }
#line 5331 "src-generated/ugbc.tab.c"
    break;

  case 222: /* exponential: JFIRE OP expr CP  */
#line 908 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_FIRE )->name;
    }
#line 5339 "src-generated/ugbc.tab.c"
    break;

  case 223: /* exponential: FIRE OP expr CP  */
#line 911 "src/ugbc.y"
                      {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_FIRE )->name;
    }
#line 5347 "src-generated/ugbc.tab.c"
    break;

  case 224: /* exponential: JOY COUNT  */
#line 914 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, (yyval.string), JOY_COUNT );
    }
#line 5356 "src-generated/ugbc.tab.c"
    break;

  case 225: /* exponential: JOYCOUNT  */
#line 918 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, (yyval.string), JOY_COUNT );
    }
#line 5365 "src-generated/ugbc.tab.c"
    break;

  case 226: /* exponential: BIT OP expr OP_COMMA expr CP  */
#line 922 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5373 "src-generated/ugbc.tab.c"
    break;

  case 227: /* exponential: UP  */
#line 925 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(UP)" )->name;
        variable_store( _environment, (yyval.string), JOY_UP );
    }
#line 5382 "src-generated/ugbc.tab.c"
    break;

  case 228: /* exponential: DOWN  */
#line 929 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(DOWN)" )->name;
        variable_store( _environment, (yyval.string), JOY_DOWN );
    }
#line 5391 "src-generated/ugbc.tab.c"
    break;

  case 229: /* exponential: LEFT  */
#line 933 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(LEFT)" )->name;
        variable_store( _environment, (yyval.string), JOY_LEFT );
    }
#line 5400 "src-generated/ugbc.tab.c"
    break;

  case 230: /* exponential: RIGHT  */
#line 937 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(RIGHT)" )->name;
        variable_store( _environment, (yyval.string), JOY_RIGHT );
    }
#line 5409 "src-generated/ugbc.tab.c"
    break;

  case 231: /* exponential: FIRE  */
#line 941 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(FIRE)" )->name;
        variable_store( _environment, (yyval.string), JOY_FIRE );
    }
#line 5418 "src-generated/ugbc.tab.c"
    break;

  case 232: /* exponential: INKEY  */
#line 945 "src/ugbc.y"
            {
        (yyval.string) = inkey( _environment )->name;
    }
#line 5426 "src-generated/ugbc.tab.c"
    break;

  case 233: /* exponential: SCANCODE  */
#line 948 "src/ugbc.y"
               {
        (yyval.string) = scancode( _environment )->name;
    }
#line 5434 "src-generated/ugbc.tab.c"
    break;

  case 234: /* exponential: SCAN CODE  */
#line 951 "src/ugbc.y"
                {
        (yyval.string) = scancode( _environment )->name;
    }
#line 5442 "src-generated/ugbc.tab.c"
    break;

  case 235: /* exponential: KEY STATE OP expr CP  */
#line 954 "src/ugbc.y"
                           {
        (yyval.string) = key_state( _environment, (yyvsp[-1].string) )->name;
    }
#line 5450 "src-generated/ugbc.tab.c"
    break;

  case 236: /* exponential: KEYSTATE OP expr CP  */
#line 957 "src/ugbc.y"
                          {
        (yyval.string) = key_state( _environment, (yyvsp[-1].string) )->name;
    }
#line 5458 "src-generated/ugbc.tab.c"
    break;

  case 237: /* exponential: SCANSHIFT  */
#line 960 "src/ugbc.y"
                {
        (yyval.string) = scanshift( _environment )->name;
    }
#line 5466 "src-generated/ugbc.tab.c"
    break;

  case 238: /* exponential: SCAN SHIFT  */
#line 963 "src/ugbc.y"
                 {
        (yyval.string) = scanshift( _environment )->name;
    }
#line 5474 "src-generated/ugbc.tab.c"
    break;

  case 239: /* exponential: LEFT SHIFT  */
#line 966 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_LEFT );
    }
#line 5483 "src-generated/ugbc.tab.c"
    break;

  case 240: /* exponential: RIGHT SHIFT  */
#line 970 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_RIGHT );
    }
#line 5492 "src-generated/ugbc.tab.c"
    break;

  case 241: /* exponential: KEY key_scancode_definition  */
#line 974 "src/ugbc.y"
                                  {
        (yyval.string) = (yyvsp[0].string);
    }
#line 5500 "src-generated/ugbc.tab.c"
    break;

  case 244: /* bank_definition_simple: AT direct_integer  */
#line 982 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 5508 "src-generated/ugbc.tab.c"
    break;

  case 245: /* bank_definition_simple: Identifier AT direct_integer  */
#line 985 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 5516 "src-generated/ugbc.tab.c"
    break;

  case 246: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 988 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 5524 "src-generated/ugbc.tab.c"
    break;

  case 247: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 991 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 5532 "src-generated/ugbc.tab.c"
    break;

  case 248: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 994 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 5540 "src-generated/ugbc.tab.c"
    break;

  case 249: /* bank_definition_simple: DATA AT direct_integer  */
#line 997 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 5548 "src-generated/ugbc.tab.c"
    break;

  case 250: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 1001 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 5556 "src-generated/ugbc.tab.c"
    break;

  case 251: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 1004 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 5564 "src-generated/ugbc.tab.c"
    break;

  case 252: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 1007 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 5572 "src-generated/ugbc.tab.c"
    break;

  case 253: /* bank_definition_simple: CODE AT direct_integer  */
#line 1010 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 5580 "src-generated/ugbc.tab.c"
    break;

  case 254: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 1014 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 5588 "src-generated/ugbc.tab.c"
    break;

  case 255: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 1017 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 5596 "src-generated/ugbc.tab.c"
    break;

  case 256: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 1020 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 5604 "src-generated/ugbc.tab.c"
    break;

  case 257: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 1023 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 5612 "src-generated/ugbc.tab.c"
    break;

  case 258: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 1027 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 5620 "src-generated/ugbc.tab.c"
    break;

  case 259: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 1030 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 5628 "src-generated/ugbc.tab.c"
    break;

  case 260: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 1033 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 5636 "src-generated/ugbc.tab.c"
    break;

  case 261: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 1036 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 5644 "src-generated/ugbc.tab.c"
    break;

  case 262: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 1042 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 5652 "src-generated/ugbc.tab.c"
    break;

  case 263: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 1045 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 5660 "src-generated/ugbc.tab.c"
    break;

  case 264: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 1048 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 5668 "src-generated/ugbc.tab.c"
    break;

  case 265: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 1051 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 5676 "src-generated/ugbc.tab.c"
    break;

  case 266: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 1054 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 5684 "src-generated/ugbc.tab.c"
    break;

  case 269: /* raster_definition_simple: Identifier AT direct_integer  */
#line 1063 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 5692 "src-generated/ugbc.tab.c"
    break;

  case 270: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 1066 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 5700 "src-generated/ugbc.tab.c"
    break;

  case 271: /* raster_definition_expression: Identifier AT expr  */
#line 1071 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5708 "src-generated/ugbc.tab.c"
    break;

  case 272: /* raster_definition_expression: AT expr WITH Identifier  */
#line 1074 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5716 "src-generated/ugbc.tab.c"
    break;

  case 275: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 1083 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 5724 "src-generated/ugbc.tab.c"
    break;

  case 276: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 1086 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 5732 "src-generated/ugbc.tab.c"
    break;

  case 277: /* next_raster_definition_expression: Identifier AT expr  */
#line 1091 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 5740 "src-generated/ugbc.tab.c"
    break;

  case 278: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 1094 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5748 "src-generated/ugbc.tab.c"
    break;

  case 281: /* color_definition_simple: BORDER direct_integer  */
#line 1103 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 5756 "src-generated/ugbc.tab.c"
    break;

  case 282: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 1106 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 5764 "src-generated/ugbc.tab.c"
    break;

  case 283: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 1109 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 5772 "src-generated/ugbc.tab.c"
    break;

  case 284: /* color_definition_expression: BORDER expr  */
#line 1114 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 5780 "src-generated/ugbc.tab.c"
    break;

  case 285: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 1117 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 5788 "src-generated/ugbc.tab.c"
    break;

  case 286: /* color_definition_expression: SPRITE expr TO expr  */
#line 1120 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 5796 "src-generated/ugbc.tab.c"
    break;

  case 292: /* wait_definition_simple: direct_integer CYCLES  */
#line 1134 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 5804 "src-generated/ugbc.tab.c"
    break;

  case 293: /* wait_definition_simple: direct_integer TICKS  */
#line 1137 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 5812 "src-generated/ugbc.tab.c"
    break;

  case 294: /* wait_definition_simple: direct_integer milliseconds  */
#line 1140 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 5820 "src-generated/ugbc.tab.c"
    break;

  case 295: /* wait_definition_expression: expr CYCLES  */
#line 1145 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 5828 "src-generated/ugbc.tab.c"
    break;

  case 296: /* wait_definition_expression: expr TICKS  */
#line 1148 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 5836 "src-generated/ugbc.tab.c"
    break;

  case 297: /* wait_definition_expression: expr milliseconds  */
#line 1151 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 5844 "src-generated/ugbc.tab.c"
    break;

  case 300: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 1161 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 5852 "src-generated/ugbc.tab.c"
    break;

  case 301: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 1164 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 5860 "src-generated/ugbc.tab.c"
    break;

  case 302: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 1167 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 5868 "src-generated/ugbc.tab.c"
    break;

  case 303: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 1170 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 5876 "src-generated/ugbc.tab.c"
    break;

  case 304: /* sprite_definition_simple: direct_integer position OP direct_integer OP_COMMA direct_integer CP  */
#line 1173 "src/ugbc.y"
                                                                         {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 5884 "src-generated/ugbc.tab.c"
    break;

  case 305: /* sprite_definition_simple: direct_integer ENABLE  */
#line 1176 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 5892 "src-generated/ugbc.tab.c"
    break;

  case 306: /* sprite_definition_simple: direct_integer DISABLE  */
#line 1179 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 5900 "src-generated/ugbc.tab.c"
    break;

  case 307: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 1182 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 5908 "src-generated/ugbc.tab.c"
    break;

  case 308: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 1185 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 5916 "src-generated/ugbc.tab.c"
    break;

  case 309: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 1188 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 5924 "src-generated/ugbc.tab.c"
    break;

  case 310: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 1191 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 5932 "src-generated/ugbc.tab.c"
    break;

  case 311: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 1194 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 5940 "src-generated/ugbc.tab.c"
    break;

  case 312: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 1197 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 5948 "src-generated/ugbc.tab.c"
    break;

  case 313: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 1200 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 5956 "src-generated/ugbc.tab.c"
    break;

  case 314: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 1203 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 5964 "src-generated/ugbc.tab.c"
    break;

  case 315: /* sprite_definition_expression: expr DATA FROM expr  */
#line 1208 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 5972 "src-generated/ugbc.tab.c"
    break;

  case 316: /* sprite_definition_expression: expr MULTICOLOR  */
#line 1211 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 5980 "src-generated/ugbc.tab.c"
    break;

  case 317: /* sprite_definition_expression: expr MONOCOLOR  */
#line 1214 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 5988 "src-generated/ugbc.tab.c"
    break;

  case 318: /* sprite_definition_expression: expr COLOR expr  */
#line 1217 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 5996 "src-generated/ugbc.tab.c"
    break;

  case 319: /* sprite_definition_expression: expr position OP expr OP_COMMA expr CP  */
#line 1220 "src/ugbc.y"
                                           {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 6004 "src-generated/ugbc.tab.c"
    break;

  case 320: /* sprite_definition_expression: expr ENABLE  */
#line 1223 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 6012 "src-generated/ugbc.tab.c"
    break;

  case 321: /* sprite_definition_expression: expr DISABLE  */
#line 1226 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 6020 "src-generated/ugbc.tab.c"
    break;

  case 322: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 1229 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 6028 "src-generated/ugbc.tab.c"
    break;

  case 323: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 1232 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 6036 "src-generated/ugbc.tab.c"
    break;

  case 324: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 1235 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 6044 "src-generated/ugbc.tab.c"
    break;

  case 325: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 1238 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 6052 "src-generated/ugbc.tab.c"
    break;

  case 326: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 1241 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 6060 "src-generated/ugbc.tab.c"
    break;

  case 327: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 1244 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 6068 "src-generated/ugbc.tab.c"
    break;

  case 328: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 1247 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 6076 "src-generated/ugbc.tab.c"
    break;

  case 329: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 1250 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 6084 "src-generated/ugbc.tab.c"
    break;

  case 332: /* bitmap_definition_simple: AT direct_integer  */
#line 1259 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 6092 "src-generated/ugbc.tab.c"
    break;

  case 333: /* bitmap_definition_simple: ENABLE  */
#line 1262 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 6100 "src-generated/ugbc.tab.c"
    break;

  case 334: /* bitmap_definition_simple: DISABLE  */
#line 1265 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 6108 "src-generated/ugbc.tab.c"
    break;

  case 335: /* bitmap_definition_simple: CLEAR  */
#line 1268 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 6116 "src-generated/ugbc.tab.c"
    break;

  case 336: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 1271 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 6124 "src-generated/ugbc.tab.c"
    break;

  case 337: /* bitmap_definition_expression: AT expr  */
#line 1277 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 6132 "src-generated/ugbc.tab.c"
    break;

  case 338: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 1280 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 6140 "src-generated/ugbc.tab.c"
    break;

  case 341: /* textmap_definition_simple: AT direct_integer  */
#line 1290 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 6148 "src-generated/ugbc.tab.c"
    break;

  case 342: /* textmap_definition_expression: AT expr  */
#line 1295 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 6156 "src-generated/ugbc.tab.c"
    break;

  case 345: /* text_definition_simple: ENABLE  */
#line 1304 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 6164 "src-generated/ugbc.tab.c"
    break;

  case 346: /* text_definition_simple: DISABLE  */
#line 1307 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 6172 "src-generated/ugbc.tab.c"
    break;

  case 347: /* text_definition_expression: AT expr OP_COMMA expr OP_COMMA expr  */
#line 1312 "src/ugbc.y"
                                         {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 6180 "src-generated/ugbc.tab.c"
    break;

  case 348: /* text_definition_expression: expr OP_COMMA expr OP_COMMA expr  */
#line 1315 "src/ugbc.y"
                                      {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 6188 "src-generated/ugbc.tab.c"
    break;

  case 351: /* tiles_definition_simple: AT direct_integer  */
#line 1324 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 6196 "src-generated/ugbc.tab.c"
    break;

  case 352: /* tiles_definition_expression: AT expr  */
#line 1329 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 6204 "src-generated/ugbc.tab.c"
    break;

  case 355: /* colormap_definition_simple: AT direct_integer  */
#line 1338 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 6212 "src-generated/ugbc.tab.c"
    break;

  case 356: /* colormap_definition_simple: CLEAR  */
#line 1341 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 6220 "src-generated/ugbc.tab.c"
    break;

  case 357: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 1344 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 6228 "src-generated/ugbc.tab.c"
    break;

  case 358: /* colormap_definition_expression: AT expr  */
#line 1349 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 6236 "src-generated/ugbc.tab.c"
    break;

  case 359: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 1352 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 6244 "src-generated/ugbc.tab.c"
    break;

  case 362: /* screen_definition_simple: ON  */
#line 1362 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 6252 "src-generated/ugbc.tab.c"
    break;

  case 363: /* screen_definition_simple: OFF  */
#line 1365 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 6260 "src-generated/ugbc.tab.c"
    break;

  case 364: /* screen_definition_simple: ROWS direct_integer  */
#line 1368 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 6268 "src-generated/ugbc.tab.c"
    break;

  case 365: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 1371 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 6276 "src-generated/ugbc.tab.c"
    break;

  case 366: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 1374 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 6284 "src-generated/ugbc.tab.c"
    break;

  case 367: /* screen_definition_expression: ROWS expr  */
#line 1379 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 6292 "src-generated/ugbc.tab.c"
    break;

  case 368: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 1382 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 6300 "src-generated/ugbc.tab.c"
    break;

  case 369: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 1385 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 6308 "src-generated/ugbc.tab.c"
    break;

  case 373: /* var_definition_simple: Identifier ON Identifier  */
#line 1394 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 6316 "src-generated/ugbc.tab.c"
    break;

  case 374: /* var_definition_simple: Identifier OP_DOLLAR ON Identifier  */
#line 1397 "src/ugbc.y"
                                       {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 6324 "src-generated/ugbc.tab.c"
    break;

  case 375: /* var_definition_simple: Identifier ON Identifier OP_ASSIGN direct_integer  */
#line 1400 "src/ugbc.y"
                                                      {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 6332 "src-generated/ugbc.tab.c"
    break;

  case 376: /* var_definition_simple: Identifier ON Identifier OP_ASSIGN expr  */
#line 1403 "src/ugbc.y"
                                            {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 6342 "src-generated/ugbc.tab.c"
    break;

  case 377: /* var_definition_simple: Identifier OP_DOLLAR ON Identifier OP_ASSIGN expr  */
#line 1408 "src/ugbc.y"
                                                      {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 6352 "src-generated/ugbc.tab.c"
    break;

  case 378: /* goto_definition: Identifier  */
#line 1415 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 6360 "src-generated/ugbc.tab.c"
    break;

  case 379: /* goto_definition: Integer  */
#line 1418 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 6368 "src-generated/ugbc.tab.c"
    break;

  case 380: /* gosub_definition: Identifier  */
#line 1424 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 6376 "src-generated/ugbc.tab.c"
    break;

  case 381: /* gosub_definition: Integer  */
#line 1427 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 6384 "src-generated/ugbc.tab.c"
    break;

  case 383: /* point_definition_simple: AT OP direct_integer OP_COMMA direct_integer CP  */
#line 1436 "src/ugbc.y"
                                                      {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 6392 "src-generated/ugbc.tab.c"
    break;

  case 384: /* point_definition_expression: AT OP expr OP_COMMA expr CP  */
#line 1442 "src/ugbc.y"
                                  {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 6400 "src-generated/ugbc.tab.c"
    break;

  case 387: /* ink_definition: expr  */
#line 1451 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 6408 "src-generated/ugbc.tab.c"
    break;

  case 388: /* on_goto_definition: Identifier  */
#line 1456 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 6417 "src-generated/ugbc.tab.c"
    break;

  case 389: /* $@4: %empty  */
#line 1460 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 6425 "src-generated/ugbc.tab.c"
    break;

  case 391: /* on_gosub_definition: Identifier  */
#line 1465 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 6434 "src-generated/ugbc.tab.c"
    break;

  case 392: /* $@5: %empty  */
#line 1469 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 6442 "src-generated/ugbc.tab.c"
    break;

  case 394: /* on_proc_definition: Identifier  */
#line 1474 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 6451 "src-generated/ugbc.tab.c"
    break;

  case 395: /* $@6: %empty  */
#line 1478 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 6459 "src-generated/ugbc.tab.c"
    break;

  case 397: /* $@7: %empty  */
#line 1483 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 6467 "src-generated/ugbc.tab.c"
    break;

  case 399: /* $@8: %empty  */
#line 1486 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 6475 "src-generated/ugbc.tab.c"
    break;

  case 401: /* $@9: %empty  */
#line 1489 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 6483 "src-generated/ugbc.tab.c"
    break;

  case 403: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1494 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 6491 "src-generated/ugbc.tab.c"
    break;

  case 404: /* every_definition: ON  */
#line 1497 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 6499 "src-generated/ugbc.tab.c"
    break;

  case 405: /* every_definition: OFF  */
#line 1500 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 6507 "src-generated/ugbc.tab.c"
    break;

  case 406: /* add_definition: Identifier OP_COMMA expr  */
#line 1505 "src/ugbc.y"
                             {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 6515 "src-generated/ugbc.tab.c"
    break;

  case 407: /* add_definition: Identifier OP_COMMA expr OP_COMMA expr TO expr  */
#line 1508 "src/ugbc.y"
                                                     {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 6523 "src-generated/ugbc.tab.c"
    break;

  case 408: /* dimensions: Integer  */
#line 1514 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 6532 "src-generated/ugbc.tab.c"
    break;

  case 409: /* dimensions: Integer OP_COMMA dimensions  */
#line 1518 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 6541 "src-generated/ugbc.tab.c"
    break;

  case 410: /* datatype: BYTE  */
#line 1525 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 6549 "src-generated/ugbc.tab.c"
    break;

  case 411: /* datatype: SIGNED BYTE  */
#line 1528 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 6557 "src-generated/ugbc.tab.c"
    break;

  case 412: /* datatype: WORD  */
#line 1531 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 6565 "src-generated/ugbc.tab.c"
    break;

  case 413: /* datatype: SIGNED WORD  */
#line 1534 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 6573 "src-generated/ugbc.tab.c"
    break;

  case 414: /* datatype: DWORD  */
#line 1537 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 6581 "src-generated/ugbc.tab.c"
    break;

  case 415: /* datatype: SIGNED DWORD  */
#line 1540 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 6589 "src-generated/ugbc.tab.c"
    break;

  case 416: /* datatype: ADDRESS  */
#line 1543 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 6597 "src-generated/ugbc.tab.c"
    break;

  case 417: /* datatype: POSITION  */
#line 1546 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 6605 "src-generated/ugbc.tab.c"
    break;

  case 418: /* datatype: COLOR  */
#line 1549 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 6613 "src-generated/ugbc.tab.c"
    break;

  case 419: /* datatype: STRING  */
#line 1552 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 6621 "src-generated/ugbc.tab.c"
    break;

  case 420: /* $@10: %empty  */
#line 1557 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 6630 "src-generated/ugbc.tab.c"
    break;

  case 421: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1560 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 6640 "src-generated/ugbc.tab.c"
    break;

  case 422: /* $@11: %empty  */
#line 1565 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 6649 "src-generated/ugbc.tab.c"
    break;

  case 423: /* dim_definition: Identifier $@11 OP_DOLLAR OP dimensions CP  */
#line 1568 "src/ugbc.y"
                                   {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 6659 "src-generated/ugbc.tab.c"
    break;

  case 424: /* $@12: %empty  */
#line 1573 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 6668 "src-generated/ugbc.tab.c"
    break;

  case 425: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1576 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 6678 "src-generated/ugbc.tab.c"
    break;

  case 428: /* indexes: expr  */
#line 1589 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 6687 "src-generated/ugbc.tab.c"
    break;

  case 429: /* indexes: expr OP_COMMA indexes  */
#line 1593 "src/ugbc.y"
                            {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 6696 "src-generated/ugbc.tab.c"
    break;

  case 430: /* parameters: Identifier  */
#line 1600 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6706 "src-generated/ugbc.tab.c"
    break;

  case 431: /* parameters: Identifier OP_DOLLAR  */
#line 1605 "src/ugbc.y"
                           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6716 "src-generated/ugbc.tab.c"
    break;

  case 432: /* parameters: Identifier AS datatype  */
#line 1610 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6726 "src-generated/ugbc.tab.c"
    break;

  case 433: /* parameters: Identifier OP_COMMA parameters  */
#line 1615 "src/ugbc.y"
                                     {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6736 "src-generated/ugbc.tab.c"
    break;

  case 434: /* parameters: Identifier OP_DOLLAR OP_COMMA parameters  */
#line 1620 "src/ugbc.y"
                                               {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6746 "src-generated/ugbc.tab.c"
    break;

  case 435: /* parameters: Identifier AS datatype OP_COMMA parameters  */
#line 1625 "src/ugbc.y"
                                                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6756 "src-generated/ugbc.tab.c"
    break;

  case 436: /* parameters_expr: Identifier  */
#line 1633 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6766 "src-generated/ugbc.tab.c"
    break;

  case 437: /* parameters_expr: Identifier OP_DOLLAR  */
#line 1638 "src/ugbc.y"
                           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6776 "src-generated/ugbc.tab.c"
    break;

  case 438: /* parameters_expr: Identifier AS datatype  */
#line 1643 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6786 "src-generated/ugbc.tab.c"
    break;

  case 439: /* parameters_expr: Identifier OP_COMMA parameters_expr  */
#line 1648 "src/ugbc.y"
                                          {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6796 "src-generated/ugbc.tab.c"
    break;

  case 440: /* parameters_expr: Identifier OP_DOLLAR OP_COMMA parameters_expr  */
#line 1653 "src/ugbc.y"
                                                    {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6806 "src-generated/ugbc.tab.c"
    break;

  case 441: /* parameters_expr: Identifier AS datatype OP_COMMA parameters_expr  */
#line 1658 "src/ugbc.y"
                                                      {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6816 "src-generated/ugbc.tab.c"
    break;

  case 442: /* parameters_expr: String  */
#line 1663 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6825 "src-generated/ugbc.tab.c"
    break;

  case 443: /* parameters_expr: String OP_COMMA parameters_expr  */
#line 1667 "src/ugbc.y"
                                      {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6834 "src-generated/ugbc.tab.c"
    break;

  case 444: /* values: expr  */
#line 1674 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6843 "src-generated/ugbc.tab.c"
    break;

  case 445: /* values: expr OP_COMMA values  */
#line 1678 "src/ugbc.y"
                           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6852 "src-generated/ugbc.tab.c"
    break;

  case 446: /* print_definition: expr  */
#line 1685 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 6860 "src-generated/ugbc.tab.c"
    break;

  case 447: /* print_definition: expr OP_COMMA  */
#line 1688 "src/ugbc.y"
                  {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 6869 "src-generated/ugbc.tab.c"
    break;

  case 448: /* print_definition: expr OP_SEMICOLON  */
#line 1692 "src/ugbc.y"
                      {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 6877 "src-generated/ugbc.tab.c"
    break;

  case 449: /* $@13: %empty  */
#line 1695 "src/ugbc.y"
                  {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 6886 "src-generated/ugbc.tab.c"
    break;

  case 451: /* $@14: %empty  */
#line 1699 "src/ugbc.y"
                       {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 6894 "src-generated/ugbc.tab.c"
    break;

  case 453: /* writing_mode_definition: REPLACE  */
#line 1705 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 6903 "src-generated/ugbc.tab.c"
    break;

  case 454: /* writing_mode_definition: OR  */
#line 1709 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 6912 "src-generated/ugbc.tab.c"
    break;

  case 455: /* writing_mode_definition: XOR  */
#line 1713 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 6921 "src-generated/ugbc.tab.c"
    break;

  case 456: /* writing_mode_definition: AND  */
#line 1717 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 6930 "src-generated/ugbc.tab.c"
    break;

  case 457: /* writing_mode_definition: IGNORE  */
#line 1721 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 6939 "src-generated/ugbc.tab.c"
    break;

  case 458: /* writing_part_definition: NORMAL  */
#line 1728 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 6948 "src-generated/ugbc.tab.c"
    break;

  case 459: /* writing_part_definition: PAPER  */
#line 1732 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 6957 "src-generated/ugbc.tab.c"
    break;

  case 460: /* writing_part_definition: PAPER ONLY  */
#line 1736 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 6966 "src-generated/ugbc.tab.c"
    break;

  case 461: /* writing_part_definition: PEN  */
#line 1740 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 6975 "src-generated/ugbc.tab.c"
    break;

  case 462: /* writing_part_definition: PEN ONLY  */
#line 1744 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 6984 "src-generated/ugbc.tab.c"
    break;

  case 463: /* writing_definition: writing_mode_definition OP_COMMA writing_part_definition  */
#line 1751 "src/ugbc.y"
                                                             {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 6992 "src-generated/ugbc.tab.c"
    break;

  case 464: /* locate_definition: OP_COMMA expr  */
#line 1757 "src/ugbc.y"
                   {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 7000 "src-generated/ugbc.tab.c"
    break;

  case 465: /* locate_definition: expr OP_COMMA  */
#line 1760 "src/ugbc.y"
                    {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 7008 "src-generated/ugbc.tab.c"
    break;

  case 466: /* locate_definition: expr OP_COMMA expr  */
#line 1763 "src/ugbc.y"
                         {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 7016 "src-generated/ugbc.tab.c"
    break;

  case 467: /* cmove_definition: OP_COMMA expr  */
#line 1769 "src/ugbc.y"
                   {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 7024 "src-generated/ugbc.tab.c"
    break;

  case 468: /* cmove_definition: expr OP_COMMA  */
#line 1772 "src/ugbc.y"
                    {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 7032 "src-generated/ugbc.tab.c"
    break;

  case 469: /* cmove_definition: expr OP_COMMA expr  */
#line 1775 "src/ugbc.y"
                         {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 7040 "src-generated/ugbc.tab.c"
    break;

  case 470: /* hscroll_definition: LEFT  */
#line 1781 "src/ugbc.y"
         {
        text_hscroll_line( _environment, -1 );
    }
#line 7048 "src-generated/ugbc.tab.c"
    break;

  case 471: /* hscroll_definition: SCREEN LEFT  */
#line 1784 "src/ugbc.y"
                  {
        text_hscroll_screen( _environment, -1 );
    }
#line 7056 "src-generated/ugbc.tab.c"
    break;

  case 472: /* hscroll_definition: RIGHT  */
#line 1787 "src/ugbc.y"
            {
        text_hscroll_line( _environment, 1 );
    }
#line 7064 "src-generated/ugbc.tab.c"
    break;

  case 473: /* hscroll_definition: SCREEN RIGHT  */
#line 1790 "src/ugbc.y"
                   {
        text_hscroll_screen( _environment, 1 );
    }
#line 7072 "src-generated/ugbc.tab.c"
    break;

  case 474: /* vscroll_definition: SCREEN UP  */
#line 1796 "src/ugbc.y"
                {
        text_vscroll_screen( _environment, -1 );
    }
#line 7080 "src-generated/ugbc.tab.c"
    break;

  case 475: /* vscroll_definition: SCREEN DOWN  */
#line 1799 "src/ugbc.y"
                  {
        text_vscroll_screen( _environment, 1 );
    }
#line 7088 "src-generated/ugbc.tab.c"
    break;

  case 491: /* statement: TEXTADDRESS OP_ASSIGN expr  */
#line 1820 "src/ugbc.y"
                               {
      variable_move( _environment, (yyvsp[0].string), "ADDRESS" );
  }
#line 7096 "src-generated/ugbc.tab.c"
    break;

  case 496: /* statement: MEMORIZE  */
#line 1827 "src/ugbc.y"
             {
      text_memorize( _environment );
  }
#line 7104 "src-generated/ugbc.tab.c"
    break;

  case 497: /* statement: REMEMBER  */
#line 1830 "src/ugbc.y"
             {
      text_remember( _environment );
  }
#line 7112 "src-generated/ugbc.tab.c"
    break;

  case 501: /* statement: CUP  */
#line 1836 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 7120 "src-generated/ugbc.tab.c"
    break;

  case 502: /* statement: CDOWN  */
#line 1839 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 7128 "src-generated/ugbc.tab.c"
    break;

  case 503: /* statement: CLEFT  */
#line 1842 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 7136 "src-generated/ugbc.tab.c"
    break;

  case 504: /* statement: CRIGHT  */
#line 1845 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 7144 "src-generated/ugbc.tab.c"
    break;

  case 505: /* statement: CLINE  */
#line 1848 "src/ugbc.y"
          {
      text_cline( _environment, NULL );
  }
#line 7152 "src-generated/ugbc.tab.c"
    break;

  case 506: /* statement: CLINE expr  */
#line 1851 "src/ugbc.y"
               {
      text_cline( _environment, (yyvsp[0].string) );
  }
#line 7160 "src-generated/ugbc.tab.c"
    break;

  case 507: /* statement: SET TAB expr  */
#line 1854 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 7168 "src-generated/ugbc.tab.c"
    break;

  case 508: /* statement: CENTER expr  */
#line 1857 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 7176 "src-generated/ugbc.tab.c"
    break;

  case 509: /* statement: CENTRE expr  */
#line 1860 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 7184 "src-generated/ugbc.tab.c"
    break;

  case 510: /* statement: CLS  */
#line 1863 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 7192 "src-generated/ugbc.tab.c"
    break;

  case 511: /* statement: HOME  */
#line 1866 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 7200 "src-generated/ugbc.tab.c"
    break;

  case 512: /* statement: OP_INC Identifier  */
#line 1869 "src/ugbc.y"
                      {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 7208 "src-generated/ugbc.tab.c"
    break;

  case 513: /* statement: OP_DEC Identifier  */
#line 1872 "src/ugbc.y"
                      {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 7216 "src-generated/ugbc.tab.c"
    break;

  case 514: /* statement: RANDOMIZE  */
#line 1875 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 7224 "src-generated/ugbc.tab.c"
    break;

  case 515: /* statement: RANDOMIZE expr  */
#line 1878 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 7232 "src-generated/ugbc.tab.c"
    break;

  case 516: /* statement: IF expr THEN  */
#line 1881 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 7240 "src-generated/ugbc.tab.c"
    break;

  case 517: /* statement: ELSE  */
#line 1884 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 7248 "src-generated/ugbc.tab.c"
    break;

  case 518: /* statement: ELSE IF expr THEN  */
#line 1887 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 7256 "src-generated/ugbc.tab.c"
    break;

  case 519: /* statement: ENDIF  */
#line 1890 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 7264 "src-generated/ugbc.tab.c"
    break;

  case 520: /* statement: DO  */
#line 1893 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 7272 "src-generated/ugbc.tab.c"
    break;

  case 521: /* statement: LOOP  */
#line 1896 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 7280 "src-generated/ugbc.tab.c"
    break;

  case 522: /* $@15: %empty  */
#line 1899 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 7288 "src-generated/ugbc.tab.c"
    break;

  case 523: /* statement: WHILE $@15 expr  */
#line 1901 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 7296 "src-generated/ugbc.tab.c"
    break;

  case 524: /* statement: WEND  */
#line 1904 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 7304 "src-generated/ugbc.tab.c"
    break;

  case 525: /* statement: REPEAT  */
#line 1907 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 7312 "src-generated/ugbc.tab.c"
    break;

  case 526: /* statement: UNTIL expr  */
#line 1910 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 7320 "src-generated/ugbc.tab.c"
    break;

  case 527: /* statement: EXIT  */
#line 1913 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 7328 "src-generated/ugbc.tab.c"
    break;

  case 528: /* statement: EXIT PROC  */
#line 1916 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 7336 "src-generated/ugbc.tab.c"
    break;

  case 529: /* statement: POP PROC  */
#line 1919 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 7344 "src-generated/ugbc.tab.c"
    break;

  case 530: /* statement: EXIT IF expr  */
#line 1922 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 7352 "src-generated/ugbc.tab.c"
    break;

  case 531: /* statement: EXIT Integer  */
#line 1925 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 7360 "src-generated/ugbc.tab.c"
    break;

  case 532: /* statement: EXIT direct_integer  */
#line 1928 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 7368 "src-generated/ugbc.tab.c"
    break;

  case 533: /* statement: EXIT IF expr OP_COMMA Integer  */
#line 1931 "src/ugbc.y"
                                  {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 7376 "src-generated/ugbc.tab.c"
    break;

  case 534: /* statement: EXIT IF expr OP_COMMA direct_integer  */
#line 1934 "src/ugbc.y"
                                         {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 7384 "src-generated/ugbc.tab.c"
    break;

  case 535: /* statement: FOR Identifier OP_ASSIGN expr TO expr  */
#line 1937 "src/ugbc.y"
                                          {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 7392 "src-generated/ugbc.tab.c"
    break;

  case 536: /* statement: NEXT  */
#line 1940 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 7400 "src-generated/ugbc.tab.c"
    break;

  case 537: /* statement: PROCEDURE Identifier  */
#line 1943 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 7409 "src-generated/ugbc.tab.c"
    break;

  case 538: /* $@16: %empty  */
#line 1947 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 7417 "src-generated/ugbc.tab.c"
    break;

  case 539: /* statement: PROCEDURE Identifier $@16 OSP parameters CSP  */
#line 1949 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 7425 "src-generated/ugbc.tab.c"
    break;

  case 540: /* statement: SHARED parameters_expr  */
#line 1952 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 7433 "src-generated/ugbc.tab.c"
    break;

  case 541: /* statement: GLOBAL parameters_expr  */
#line 1955 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 7441 "src-generated/ugbc.tab.c"
    break;

  case 542: /* statement: END PROC  */
#line 1958 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 7449 "src-generated/ugbc.tab.c"
    break;

  case 543: /* statement: END PROC OSP expr CSP  */
#line 1961 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 7457 "src-generated/ugbc.tab.c"
    break;

  case 544: /* statement: FOR Identifier OP_ASSIGN expr TO expr STEP expr  */
#line 1964 "src/ugbc.y"
                                                    {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 7465 "src-generated/ugbc.tab.c"
    break;

  case 545: /* statement: Identifier " "  */
#line 1967 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 7474 "src-generated/ugbc.tab.c"
    break;

  case 546: /* statement: PROC Identifier  */
#line 1971 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 7483 "src-generated/ugbc.tab.c"
    break;

  case 547: /* statement: CALL Identifier  */
#line 1975 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 7492 "src-generated/ugbc.tab.c"
    break;

  case 548: /* $@17: %empty  */
#line 1979 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 7500 "src-generated/ugbc.tab.c"
    break;

  case 549: /* statement: Identifier OSP $@17 values CSP  */
#line 1981 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 7508 "src-generated/ugbc.tab.c"
    break;

  case 550: /* $@18: %empty  */
#line 1984 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 7516 "src-generated/ugbc.tab.c"
    break;

  case 551: /* statement: PROC Identifier OSP $@18 values CSP  */
#line 1986 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 7524 "src-generated/ugbc.tab.c"
    break;

  case 552: /* $@19: %empty  */
#line 1989 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 7532 "src-generated/ugbc.tab.c"
    break;

  case 553: /* statement: CALL Identifier OSP $@19 values CSP  */
#line 1991 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 7540 "src-generated/ugbc.tab.c"
    break;

  case 554: /* statement: PEN expr  */
#line 1994 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 7548 "src-generated/ugbc.tab.c"
    break;

  case 555: /* statement: PAPER expr  */
#line 1997 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 7556 "src-generated/ugbc.tab.c"
    break;

  case 556: /* statement: INVERSE ON  */
#line 2000 "src/ugbc.y"
               {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 7564 "src-generated/ugbc.tab.c"
    break;

  case 557: /* statement: INVERSE OFF  */
#line 2003 "src/ugbc.y"
                {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 7572 "src-generated/ugbc.tab.c"
    break;

  case 559: /* statement: Identifier OP_COLON  */
#line 2007 "src/ugbc.y"
                        {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 7580 "src-generated/ugbc.tab.c"
    break;

  case 560: /* statement: BEG GAMELOOP  */
#line 2010 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 7588 "src-generated/ugbc.tab.c"
    break;

  case 561: /* statement: END GAMELOOP  */
#line 2013 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 7596 "src-generated/ugbc.tab.c"
    break;

  case 562: /* statement: GRAPHIC  */
#line 2016 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 7604 "src-generated/ugbc.tab.c"
    break;

  case 563: /* statement: HALT  */
#line 2019 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 7612 "src-generated/ugbc.tab.c"
    break;

  case 564: /* statement: END  */
#line 2022 "src/ugbc.y"
        {
      end( _environment );
  }
#line 7620 "src-generated/ugbc.tab.c"
    break;

  case 569: /* statement: RETURN  */
#line 2029 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 7628 "src-generated/ugbc.tab.c"
    break;

  case 570: /* statement: RETURN expr  */
#line 2032 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 7636 "src-generated/ugbc.tab.c"
    break;

  case 571: /* statement: POP  */
#line 2035 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 7644 "src-generated/ugbc.tab.c"
    break;

  case 572: /* statement: DONE  */
#line 2038 "src/ugbc.y"
          {
      return 0;
  }
#line 7652 "src-generated/ugbc.tab.c"
    break;

  case 573: /* statement: LEFT OP expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 2041 "src/ugbc.y"
                                                 {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 7660 "src-generated/ugbc.tab.c"
    break;

  case 574: /* statement: RIGHT OP expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 2044 "src/ugbc.y"
                                                  {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 7668 "src-generated/ugbc.tab.c"
    break;

  case 575: /* statement: MID OP expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 2047 "src/ugbc.y"
                                                {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 7676 "src-generated/ugbc.tab.c"
    break;

  case 576: /* statement: MID OP expr OP_COMMA expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 2050 "src/ugbc.y"
                                                              {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 7684 "src-generated/ugbc.tab.c"
    break;

  case 578: /* statement: Identifier OP_ASSIGN expr  */
#line 2054 "src/ugbc.y"
                              {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 7698 "src-generated/ugbc.tab.c"
    break;

  case 579: /* statement: Identifier OP_DOLLAR OP_ASSIGN expr  */
#line 2063 "src/ugbc.y"
                                        {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 7712 "src-generated/ugbc.tab.c"
    break;

  case 580: /* $@20: %empty  */
#line 2072 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 7721 "src-generated/ugbc.tab.c"
    break;

  case 581: /* statement: Identifier $@20 OP indexes CP OP_ASSIGN expr  */
#line 2076 "src/ugbc.y"
                                   {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 7734 "src-generated/ugbc.tab.c"
    break;

  case 582: /* $@21: %empty  */
#line 2084 "src/ugbc.y"
                         {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 7743 "src-generated/ugbc.tab.c"
    break;

  case 583: /* statement: Identifier OP_DOLLAR $@21 OP indexes CP OP_ASSIGN expr  */
#line 2087 "src/ugbc.y"
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
#line 7762 "src-generated/ugbc.tab.c"
    break;

  case 584: /* $@22: %empty  */
#line 2101 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 7771 "src-generated/ugbc.tab.c"
    break;

  case 585: /* statement: Identifier $@22 datatype OP indexes CP OP_ASSIGN expr  */
#line 2104 "src/ugbc.y"
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
#line 7790 "src-generated/ugbc.tab.c"
    break;

  case 586: /* statement: DEBUG expr  */
#line 2118 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 7798 "src-generated/ugbc.tab.c"
    break;

  case 589: /* statements_no_linenumbers: statement  */
#line 2126 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 7804 "src-generated/ugbc.tab.c"
    break;

  case 590: /* $@23: %empty  */
#line 2127 "src/ugbc.y"
                         { ((Environment *)_environment)->yylineno = yylineno; }
#line 7810 "src-generated/ugbc.tab.c"
    break;

  case 592: /* $@24: %empty  */
#line 2131 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 7818 "src-generated/ugbc.tab.c"
    break;

  case 593: /* statements_with_linenumbers: Integer $@24 statements_no_linenumbers  */
#line 2133 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 7826 "src-generated/ugbc.tab.c"
    break;

  case 594: /* $@25: %empty  */
#line 2138 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 7834 "src-generated/ugbc.tab.c"
    break;

  case 600: /* $@26: %empty  */
#line 2148 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 7840 "src-generated/ugbc.tab.c"
    break;


#line 7844 "src-generated/ugbc.tab.c"

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

#line 2150 "src/ugbc.y"


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

