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
  YYSYMBOL_KEYSHIFT = 233,                 /* KEYSHIFT  */
  YYSYMBOL_CAPSLOCK = 234,                 /* CAPSLOCK  */
  YYSYMBOL_CAPS = 235,                     /* CAPS  */
  YYSYMBOL_LOCK = 236,                     /* LOCK  */
  YYSYMBOL_ALT = 237,                      /* ALT  */
  YYSYMBOL_INPUT = 238,                    /* INPUT  */
  YYSYMBOL_FREE = 239,                     /* FREE  */
  YYSYMBOL_A = 240,                        /* A  */
  YYSYMBOL_B = 241,                        /* B  */
  YYSYMBOL_C = 242,                        /* C  */
  YYSYMBOL_D = 243,                        /* D  */
  YYSYMBOL_E = 244,                        /* E  */
  YYSYMBOL_F = 245,                        /* F  */
  YYSYMBOL_G = 246,                        /* G  */
  YYSYMBOL_H = 247,                        /* H  */
  YYSYMBOL_I = 248,                        /* I  */
  YYSYMBOL_J = 249,                        /* J  */
  YYSYMBOL_K = 250,                        /* K  */
  YYSYMBOL_L = 251,                        /* L  */
  YYSYMBOL_M = 252,                        /* M  */
  YYSYMBOL_N = 253,                        /* N  */
  YYSYMBOL_O = 254,                        /* O  */
  YYSYMBOL_P = 255,                        /* P  */
  YYSYMBOL_Q = 256,                        /* Q  */
  YYSYMBOL_R = 257,                        /* R  */
  YYSYMBOL_S = 258,                        /* S  */
  YYSYMBOL_T = 259,                        /* T  */
  YYSYMBOL_U = 260,                        /* U  */
  YYSYMBOL_V = 261,                        /* V  */
  YYSYMBOL_X = 262,                        /* X  */
  YYSYMBOL_Y = 263,                        /* Y  */
  YYSYMBOL_W = 264,                        /* W  */
  YYSYMBOL_Z = 265,                        /* Z  */
  YYSYMBOL_F1 = 266,                       /* F1  */
  YYSYMBOL_F2 = 267,                       /* F2  */
  YYSYMBOL_F3 = 268,                       /* F3  */
  YYSYMBOL_F4 = 269,                       /* F4  */
  YYSYMBOL_F5 = 270,                       /* F5  */
  YYSYMBOL_F6 = 271,                       /* F6  */
  YYSYMBOL_F7 = 272,                       /* F7  */
  YYSYMBOL_F8 = 273,                       /* F8  */
  YYSYMBOL_BLACK = 274,                    /* BLACK  */
  YYSYMBOL_WHITE = 275,                    /* WHITE  */
  YYSYMBOL_RED = 276,                      /* RED  */
  YYSYMBOL_CYAN = 277,                     /* CYAN  */
  YYSYMBOL_VIOLET = 278,                   /* VIOLET  */
  YYSYMBOL_GREEN = 279,                    /* GREEN  */
  YYSYMBOL_BLUE = 280,                     /* BLUE  */
  YYSYMBOL_YELLOW = 281,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 282,                   /* ORANGE  */
  YYSYMBOL_BROWN = 283,                    /* BROWN  */
  YYSYMBOL_LIGHT = 284,                    /* LIGHT  */
  YYSYMBOL_DARK = 285,                     /* DARK  */
  YYSYMBOL_GREY = 286,                     /* GREY  */
  YYSYMBOL_GRAY = 287,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 288,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 289,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 290,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 291,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 292,                /* TURQUOISE  */
  YYSYMBOL_TAN = 293,                      /* TAN  */
  YYSYMBOL_PINK = 294,                     /* PINK  */
  YYSYMBOL_PEACH = 295,                    /* PEACH  */
  YYSYMBOL_OLIVE = 296,                    /* OLIVE  */
  YYSYMBOL_Identifier = 297,               /* Identifier  */
  YYSYMBOL_String = 298,                   /* String  */
  YYSYMBOL_Integer = 299,                  /* Integer  */
  YYSYMBOL_300_0_ = 300,                   /* "0"  */
  YYSYMBOL_301_1_ = 301,                   /* "1"  */
  YYSYMBOL_302_2_ = 302,                   /* "2"  */
  YYSYMBOL_303_3_ = 303,                   /* "3"  */
  YYSYMBOL_304_4_ = 304,                   /* "4"  */
  YYSYMBOL_305_5_ = 305,                   /* "5"  */
  YYSYMBOL_306_6_ = 306,                   /* "6"  */
  YYSYMBOL_307_7_ = 307,                   /* "7"  */
  YYSYMBOL_308_8_ = 308,                   /* "8"  */
  YYSYMBOL_309_9_ = 309,                   /* "9"  */
  YYSYMBOL_310_ = 310,                     /* " "  */
  YYSYMBOL_YYACCEPT = 311,                 /* $accept  */
  YYSYMBOL_expr = 312,                     /* expr  */
  YYSYMBOL_expr_math = 313,                /* expr_math  */
  YYSYMBOL_term = 314,                     /* term  */
  YYSYMBOL_modula = 315,                   /* modula  */
  YYSYMBOL_factor = 316,                   /* factor  */
  YYSYMBOL_direct_integer = 317,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 318, /* random_definition_simple  */
  YYSYMBOL_random_definition = 319,        /* random_definition  */
  YYSYMBOL_color_enumeration = 320,        /* color_enumeration  */
  YYSYMBOL_key_scancode_alphadigit = 321,  /* key_scancode_alphadigit  */
  YYSYMBOL_key_scancode_function_digit = 322, /* key_scancode_function_digit  */
  YYSYMBOL_key_scancode_definition = 323,  /* key_scancode_definition  */
  YYSYMBOL_exponential = 324,              /* exponential  */
  YYSYMBOL_325_1 = 325,                    /* $@1  */
  YYSYMBOL_326_2 = 326,                    /* $@2  */
  YYSYMBOL_327_3 = 327,                    /* $@3  */
  YYSYMBOL_position = 328,                 /* position  */
  YYSYMBOL_bank_definition_simple = 329,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 330, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 331,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 332, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 333, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 334,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 335, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 336, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 337,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 338,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 339, /* color_definition_expression  */
  YYSYMBOL_color_definition = 340,         /* color_definition  */
  YYSYMBOL_milliseconds = 341,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 342,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 343, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 344,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 345, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 346, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 347,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 348, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 349, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 350,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 351, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 352, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 353,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 354,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 355, /* text_definition_expression  */
  YYSYMBOL_text_definition = 356,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 357,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 358, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 359,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 360, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 361, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 362,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 363, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 364, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 365,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 366,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 367,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 368,         /* gosub_definition  */
  YYSYMBOL_var_definition = 369,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 370,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 371, /* point_definition_expression  */
  YYSYMBOL_point_definition = 372,         /* point_definition  */
  YYSYMBOL_ink_definition = 373,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 374,       /* on_goto_definition  */
  YYSYMBOL_375_4 = 375,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 376,      /* on_gosub_definition  */
  YYSYMBOL_377_5 = 377,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 378,       /* on_proc_definition  */
  YYSYMBOL_379_6 = 379,                    /* $@6  */
  YYSYMBOL_on_definition = 380,            /* on_definition  */
  YYSYMBOL_381_7 = 381,                    /* $@7  */
  YYSYMBOL_382_8 = 382,                    /* $@8  */
  YYSYMBOL_383_9 = 383,                    /* $@9  */
  YYSYMBOL_every_definition = 384,         /* every_definition  */
  YYSYMBOL_add_definition = 385,           /* add_definition  */
  YYSYMBOL_dimensions = 386,               /* dimensions  */
  YYSYMBOL_datatype = 387,                 /* datatype  */
  YYSYMBOL_dim_definition = 388,           /* dim_definition  */
  YYSYMBOL_389_10 = 389,                   /* $@10  */
  YYSYMBOL_390_11 = 390,                   /* $@11  */
  YYSYMBOL_391_12 = 391,                   /* $@12  */
  YYSYMBOL_dim_definitions = 392,          /* dim_definitions  */
  YYSYMBOL_indexes = 393,                  /* indexes  */
  YYSYMBOL_parameters = 394,               /* parameters  */
  YYSYMBOL_parameters_expr = 395,          /* parameters_expr  */
  YYSYMBOL_values = 396,                   /* values  */
  YYSYMBOL_print_definition = 397,         /* print_definition  */
  YYSYMBOL_398_13 = 398,                   /* $@13  */
  YYSYMBOL_399_14 = 399,                   /* $@14  */
  YYSYMBOL_writing_mode_definition = 400,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 401,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 402,       /* writing_definition  */
  YYSYMBOL_locate_definition = 403,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 404,         /* cmove_definition  */
  YYSYMBOL_hscroll_definition = 405,       /* hscroll_definition  */
  YYSYMBOL_vscroll_definition = 406,       /* vscroll_definition  */
  YYSYMBOL_input_definition2 = 407,        /* input_definition2  */
  YYSYMBOL_408_15 = 408,                   /* $@15  */
  YYSYMBOL_input_definition = 409,         /* input_definition  */
  YYSYMBOL_410_16 = 410,                   /* $@16  */
  YYSYMBOL_statement = 411,                /* statement  */
  YYSYMBOL_412_17 = 412,                   /* $@17  */
  YYSYMBOL_413_18 = 413,                   /* $@18  */
  YYSYMBOL_414_19 = 414,                   /* $@19  */
  YYSYMBOL_415_20 = 415,                   /* $@20  */
  YYSYMBOL_416_21 = 416,                   /* $@21  */
  YYSYMBOL_417_22 = 417,                   /* $@22  */
  YYSYMBOL_418_23 = 418,                   /* $@23  */
  YYSYMBOL_419_24 = 419,                   /* $@24  */
  YYSYMBOL_statements_no_linenumbers = 420, /* statements_no_linenumbers  */
  YYSYMBOL_421_25 = 421,                   /* $@25  */
  YYSYMBOL_statements_with_linenumbers = 422, /* statements_with_linenumbers  */
  YYSYMBOL_423_26 = 423,                   /* $@26  */
  YYSYMBOL_statements_complex = 424,       /* statements_complex  */
  YYSYMBOL_425_27 = 425,                   /* $@27  */
  YYSYMBOL_program = 426,                  /* program  */
  YYSYMBOL_427_28 = 427                    /* $@28  */
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
#define YYLAST   5253

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  311
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  117
/* YYNRULES -- Number of rules.  */
#define YYNRULES  626
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1148

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   565


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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    88,    92,    96,    99,   102,   105,   108,
     111,   114,   120,   121,   124,   131,   132,   136,   137,   141,
     148,   149,   153,   157,   160,   163,   166,   169,   175,   180,
     183,   186,   189,   192,   195,   198,   203,   208,   212,   216,
     220,   224,   228,   232,   236,   240,   244,   248,   252,   256,
     260,   264,   268,   272,   276,   280,   284,   288,   292,   296,
     300,   304,   308,   312,   318,   322,   326,   330,   334,   338,
     342,   346,   350,   354,   358,   362,   366,   370,   374,   378,
     382,   386,   390,   394,   398,   402,   406,   410,   414,   418,
     422,   426,   430,   434,   438,   442,   446,   450,   454,   458,
     465,   469,   473,   477,   481,   485,   489,   493,   499,   503,
     506,   510,   514,   518,   522,   526,   530,   534,   538,   542,
     546,   550,   553,   557,   561,   565,   569,   573,   577,   581,
     585,   589,   593,   597,   601,   605,   609,   613,   619,   619,
     630,   630,   641,   644,   647,   656,   660,   667,   671,   675,
     679,   683,   687,   691,   695,   699,   702,   705,   708,   711,
     714,   717,   720,   723,   726,   729,   732,   735,   738,   741,
     744,   747,   750,   753,   756,   759,   762,   765,   768,   771,
     774,   777,   780,   783,   786,   790,   793,   796,   799,   802,
     802,   808,   811,   814,   818,   822,   826,   830,   834,   838,
     842,   846,   850,   853,   856,   859,   862,   865,   868,   871,
     874,   877,   880,   883,   886,   889,   892,   895,   898,   901,
     904,   907,   910,   913,   916,   919,   923,   927,   930,   934,
     938,   942,   946,   950,   953,   956,   959,   962,   965,   968,
     971,   974,   977,   980,   984,   988,   992,   996,  1000,  1004,
    1008,  1012,  1016,  1020,  1024,  1029,  1029,  1032,  1035,  1038,
    1041,  1044,  1047,  1051,  1054,  1057,  1060,  1064,  1067,  1070,
    1073,  1077,  1080,  1083,  1086,  1092,  1095,  1098,  1101,  1104,
    1109,  1110,  1113,  1116,  1121,  1124,  1129,  1130,  1133,  1136,
    1141,  1144,  1149,  1150,  1153,  1156,  1159,  1164,  1167,  1170,
    1175,  1176,  1179,  1180,  1181,  1184,  1187,  1190,  1193,  1199,
    1202,  1205,  1211,  1212,  1215,  1218,  1221,  1224,  1227,  1230,
    1233,  1236,  1239,  1242,  1245,  1248,  1251,  1254,  1257,  1262,
    1265,  1268,  1271,  1274,  1277,  1280,  1283,  1286,  1289,  1292,
    1295,  1298,  1301,  1304,  1309,  1310,  1313,  1316,  1319,  1322,
    1325,  1331,  1334,  1340,  1341,  1344,  1349,  1354,  1355,  1358,
    1361,  1366,  1369,  1374,  1375,  1378,  1383,  1388,  1389,  1392,
    1395,  1398,  1403,  1406,  1412,  1413,  1416,  1419,  1422,  1425,
    1428,  1433,  1436,  1439,  1444,  1445,  1447,  1448,  1451,  1454,
    1457,  1462,  1469,  1472,  1478,  1481,  1487,  1490,  1496,  1501,
    1502,  1505,  1510,  1514,  1514,  1519,  1523,  1523,  1528,  1532,
    1532,  1537,  1537,  1540,  1540,  1543,  1543,  1548,  1551,  1554,
    1559,  1562,  1568,  1572,  1579,  1582,  1585,  1588,  1591,  1594,
    1597,  1600,  1603,  1606,  1611,  1611,  1619,  1619,  1627,  1627,
    1638,  1639,  1643,  1647,  1654,  1659,  1664,  1669,  1674,  1679,
    1687,  1692,  1697,  1702,  1707,  1712,  1717,  1721,  1728,  1732,
    1739,  1742,  1746,  1749,  1749,  1753,  1753,  1759,  1763,  1767,
    1771,  1775,  1782,  1786,  1790,  1794,  1798,  1805,  1811,  1814,
    1817,  1823,  1826,  1829,  1835,  1838,  1841,  1844,  1850,  1853,
    1859,  1863,  1866,  1866,  1872,  1877,  1881,  1881,  1885,  1890,
    1891,  1892,  1893,  1894,  1895,  1896,  1897,  1898,  1899,  1900,
    1901,  1902,  1903,  1904,  1905,  1908,  1909,  1910,  1911,  1912,
    1913,  1916,  1919,  1920,  1921,  1922,  1925,  1928,  1931,  1934,
    1937,  1940,  1943,  1946,  1949,  1952,  1955,  1958,  1961,  1964,
    1967,  1970,  1973,  1976,  1979,  1982,  1985,  1988,  1988,  1993,
    1996,  1999,  2002,  2005,  2008,  2011,  2014,  2017,  2020,  2023,
    2026,  2029,  2032,  2036,  2036,  2041,  2044,  2047,  2050,  2053,
    2056,  2060,  2064,  2068,  2068,  2073,  2073,  2078,  2078,  2083,
    2086,  2089,  2092,  2095,  2096,  2099,  2102,  2105,  2108,  2111,
    2114,  2115,  2116,  2117,  2118,  2121,  2124,  2127,  2130,  2133,
    2136,  2139,  2142,  2143,  2152,  2161,  2161,  2173,  2173,  2190,
    2190,  2207,  2210,  2211,  2215,  2216,  2216,  2220,  2220,  2227,
    2227,  2230,  2231,  2232,  2233,  2237,  2237
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
  "SLASH", "KEY", "STATE", "KEYSTATE", "KEYSHIFT", "CAPSLOCK", "CAPS",
  "LOCK", "ALT", "INPUT", "FREE", "A", "B", "C", "D", "E", "F", "G", "H",
  "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V",
  "X", "Y", "W", "Z", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8",
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
  "hscroll_definition", "vscroll_definition", "input_definition2", "$@15",
  "input_definition", "$@16", "statement", "$@17", "$@18", "$@19", "$@20",
  "$@21", "$@22", "$@23", "$@24", "statements_no_linenumbers", "$@25",
  "statements_with_linenumbers", "$@26", "statements_complex", "$@27",
  "program", "$@28", YY_NULLPTR
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
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565
};
#endif

#define YYPACT_NINF (-1008)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-606)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1008,    95,  1095, -1008, -1008,  -172,  -149,  3716,   -21, -1008,
     146,  2869,   161,   -11,  3147, -1008,    39,   193,  3716,  -116,
    -205, -1008, -1008, -1008,  2313,   173,    58,  3716,  3716,    15,
     126,   -26, -1008,   186,   198,  3716,  3716, -1008,   224,   233,
    -190,  3716,   120,   195, -1008,   -20, -1008,  3716,   -25,  2591,
     245,   -16,  3716,     4,    28,    42,    47,     8,     8,  3716,
    3716,   246,    41,  1464, -1008, -1008,  1757,  3716,  3716,   122,
   -1008, -1008, -1008, -1008,  3716, -1008, -1008,    53,   242,   291,
      11,    10, -1008,   301,   319,   327, -1008, -1008, -1008,    60,
     326,  2035, -1008, -1008,   318,   321,   322,   128, -1008, -1008,
      16, -1008, -1008,    -3,    -1,  3716, -1008, -1008,   323,   324,
     325,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   342,   343, -1008, -1008,   345,    63,   -15,
      23,   366,   367,   385,   386,   387,   388,   389, -1008, -1008,
   -1008,     7,   370,  4550, -1008,   371,   372,   373,   374,   375,
     376, -1008, -1008,   -19,   223, -1008, -1008,  4944,   379, -1008,
   -1008,   185,   235,   405, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008,   145, -1008, -1008,   -30,  -181, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008,   154,    26, -1008, -1008,
     140,    62,   299,   243,   234, -1008, -1008, -1008,  3147,   406,
   -1008, -1008, -1008,  3147,  3147,  3147, -1008, -1008, -1008,   138,
    4944,     0,    32, -1008, -1008, -1008,    -5,   412,    -4,     2,
       3,     5,   409, -1008, -1008, -1008,   404,   418, -1008, -1008,
   -1008,  3147, -1008, -1008,   408, -1008, -1008, -1008, -1008, -1008,
    3147,   392,   393, -1008, -1008, -1008,   -10, -1008,   147, -1008,
   -1008, -1008, -1008, -1008,  3716,  3438, -1008, -1008,   433, -1008,
   -1008, -1008,  3147, -1008, -1008, -1008,  3147,   415, -1008, -1008,
   -1008,   377, -1008, -1008, -1008, -1008,   307,  3716,  3716, -1008,
   -1008,  3147, -1008, -1008, -1008,   401, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008,  3716,  3716, -1008, -1008, -1008, -1008,
     438, -1008, -1008,   303, -1008,  3716,   452, -1008, -1008, -1008,
      31,   455, -1008,   313,   315,   320,    82,   461, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,   464,
   -1008,  3716,   465, -1008,  3716,   466, -1008, -1008, -1008,  3716,
   -1008,   237, -1008, -1008, -1008,   241, -1008,  3716,   261,   469,
   -1008, -1008, -1008, -1008,  3716,   470, -1008, -1008,   437,    34,
    1281, -1008,  1095,  1095, -1008,   439,   441,   443,   444,   446,
     447,   133,   450,  3716,  3147,  3147, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008,   453, -1008, -1008,  3716, -1008,
   -1008,  3716, -1008, -1008, -1008,  3716,  3716,  3716,  3716,  3716,
    3716,  3716,  3716,  3716,  3716,  3716,  3716,  3716,  3716,  3716,
    3716,  3716,  3994,   454,   199, -1008, -1008,   457, -1008, -1008,
     458,   459, -1008, -1008, -1008, -1008, -1008,  3716, -1008,  3716,
    2035,   462,   467,  3716,  3716,  3716,  3716,  3716,  3716, -1008,
   -1008, -1008, -1008, -1008, -1008,   275,   281, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008,   177, -1008, -1008,
   -1008,   182, -1008, -1008, -1008, -1008, -1008,   276, -1008, -1008,
     468, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,  3716, -1008,
   -1008, -1008,   472, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008,   473, -1008,   474,   221,   231,  3994,  3994,  3994,  3994,
    3994,  3994,  3994,  3994,  3994,  3994,  3994,  3994,  3994,   -63,
    4272,  4828,   471,   475,  3147, -1008, -1008,   426,   427,   429,
     431, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008,  3147,   485, -1008, -1008, -1008,   463,   412,   486,   412,
     488,   412,   489,   412,   490,   412, -1008,  3716,   482, -1008,
   -1008,   280,   286,    59,   114, -1008, -1008, -1008,   483,   412,
     487, -1008, -1008,   288,   290,   119,   141, -1008, -1008,   484,
   -1008, -1008,  3147, -1008, -1008,  3147,  3147, -1008, -1008, -1008,
     477,   225, -1008,   520,  3716, -1008, -1008, -1008, -1008,  3147,
   -1008,  3716,   521,   522, -1008, -1008,  3147,   456,   523,  3716,
     428,   525,  3716, -1008, -1008, -1008, -1008, -1008, -1008,   171,
   -1008, -1008,   493,   515,     4, -1008,   390, -1008,     8,   529,
      34,     8,   -35, -1008,  3716, -1008,  3716, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008,   530,   244,  1095, -1008,  3716,   498,
    3716,  3716,   499,    18, -1008,  1281, -1008, -1008,  3716,   247,
     249,   250,   251,   252,   501,   502,   503, -1008,   504,   511,
     512,   513,   514,  3716,   549,   550,   551,   552,   519,   524,
     526,   527,   554,   528,   531,   532,   533,   534,   555,   556,
     535,   536,   537,   205,   269,   538,  3716,  3716,  3716,   540,
      56,    94,  3716,  3994,   541,   542,   543,   544,   545,   546,
   -1008, -1008,   491,   492, -1008, -1008, -1008,  3716,   548,  3716,
     553,  3716,  3716,  3716,  3716,   299,   299,   346,   346,   346,
     346,   346,   346,   346,   346,   243,   234,   234,   380,  4828,
    4828, -1008, -1008,   273,   293, -1008, -1008,  3716,   412,  3716,
     412,   557,   559,  3147,   135, -1008,   412, -1008,   412, -1008,
     412, -1008,   412,   153, -1008,  3716, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008,  3716, -1008,   412, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008,   412, -1008, -1008, -1008, -1008,
   -1008, -1008,   298,   300,   302,   305,   583,  3716,   591,   558,
     562,   449,  3716,  3716,   596,   600, -1008,    -8,   547,   314,
    3716,   605, -1008, -1008, -1008,   573,   316,   574, -1008,  3716,
     341,  3716, -1008,     8,   609, -1008,   451,   460, -1008, -1008,
   -1008, -1008,   344,   613, -1008, -1008,  3716,   614,   476,   616,
     579,  3716, -1008,   619, -1008, -1008, -1008, -1008, -1008,   347,
     348,   349, -1008, -1008, -1008, -1008, -1008,   589,  3716,  3716,
    3716,  3716, -1008, -1008, -1008, -1008,  3716, -1008, -1008, -1008,
   -1008, -1008,  3716,  3716, -1008, -1008, -1008,  4828,   590, -1008,
     593,   632,   633, -1008,  3716, -1008,  3716,   635,   620, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008,   603, -1008,   604,
    3716,   500,   608, -1008, -1008,  4828, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008,   355,   356, -1008, -1008, -1008, -1008,
   -1008, -1008,   626, -1008,   628, -1008,   357,   156, -1008,   647,
   -1008,   658,   659, -1008,   660, -1008,   661, -1008,   656,  3147,
     663,  3716,  3716,   412, -1008,   631,   634,  3716,   412, -1008,
   -1008,  3716, -1008,    99,  3716,   316,   667,   636,   316,   539,
      84,   560,   561, -1008,     8, -1008, -1008, -1008,   382,   639,
    3716, -1008,  3716,   669,   642,  3716, -1008, -1008, -1008, -1008,
     643,   644,   115,   125,   645,   646,   648,   651, -1008, -1008,
    3716,  3716,   652,   662, -1008, -1008,   664, -1008, -1008, -1008,
   -1008, -1008,   378,   402, -1008,   653, -1008,   666, -1008,  3716,
     412,   692,   695,   697,  3716, -1008, -1008,  3716, -1008, -1008,
   -1008,   693,   694,   672,   673,   597,  3716,   704,   640,   681,
     316, -1008,   682, -1008,   341,   703,    34, -1008, -1008, -1008,
     344,   711, -1008, -1008,  3716,   713,   686, -1008, -1008,  3716,
   -1008,  3716, -1008, -1008, -1008, -1008, -1008,   687,   688, -1008,
   -1008, -1008, -1008, -1008,   432,   434,   690,   696,   298,   300,
     302, -1008, -1008,  3716,  3716, -1008, -1008,  3716,   698,  3716,
    3716, -1008, -1008, -1008, -1008,   341,   726, -1008,  3716, -1008,
    3716, -1008,   700,   702, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008,   721, -1008, -1008, -1008,
     341, -1008, -1008, -1008, -1008,  3716, -1008, -1008
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     625,     0,   613,     1,   612,     0,     0,     0,     0,   597,
       0,     0,   561,     0,     0,   588,     0,     0,     0,   386,
       0,   546,   550,   547,     0,     0,     0,     0,     0,     0,
       0,   589,   544,     0,     0,     0,   539,   587,     0,     0,
       0,   594,   596,   542,   545,   552,   549,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   534,   535,     0,     0,     0,     0,
     525,   526,   527,   528,   529,   520,   521,     0,     0,     0,
       0,   609,   617,   614,   621,   623,   626,   537,   538,     0,
       0,     0,   157,   158,     0,     0,     0,     0,   202,   203,
       0,   228,   229,   230,   231,     0,   193,   194,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   195,   204,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   215,   216,
     217,     0,     0,     0,   226,   232,     0,     0,     0,     0,
       0,   234,   235,     0,     0,   239,   249,     0,     0,   241,
     247,     0,     0,     0,   184,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     0,     0,    49,    54,    55,
      56,    57,    58,    59,    62,    63,     0,   142,   146,   144,
     460,     2,    12,    15,    17,   155,    20,   518,     0,     0,
     286,   287,   500,     0,     0,     0,   300,   301,   502,     0,
     308,     0,     0,   312,   313,   503,     0,     0,     0,     0,
       0,     0,     0,   280,   281,   499,     0,     0,   344,   345,
     504,     0,   347,   348,   349,   353,   354,   505,   376,   377,
       0,     0,     0,   384,   385,   510,     0,   590,     0,   396,
     513,   392,   393,   591,     0,     0,   359,   360,     0,   363,
     364,   507,     0,   367,   368,   508,     0,   370,   374,   375,
     509,     0,   579,   536,   585,   586,   567,     0,     0,   611,
     540,     0,   357,   358,   506,     0,   399,   400,   511,   394,
     395,   592,   595,   554,     0,     0,   553,   556,   557,   551,
       0,   418,   419,     0,   593,     0,     0,   515,   401,   512,
     434,   440,   602,   571,   562,   572,   450,   456,   565,   566,
     516,   580,   581,   582,   470,   468,   467,   469,   471,     0,
     583,     0,     0,   519,     0,     0,   524,   532,   533,     0,
     530,     0,   484,   486,   522,     0,   523,     0,   490,     0,
     498,   517,   619,   584,     0,   607,   573,   570,     0,     0,
     613,   615,   613,   613,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    29,    30,    32,
      34,    35,    31,    36,   181,     0,   196,   197,     0,   243,
     250,     0,   245,   252,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   198,   201,     0,   199,   200,
       0,     0,   214,   208,   209,   210,   211,     0,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
     240,   244,   246,   111,   112,     0,     0,   132,   137,   122,
     242,   108,   110,   113,   114,   115,   116,     0,   119,   120,
     123,     0,   128,   129,   130,   131,   133,     0,   135,   136,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,   109,   121,   254,     0,   248,
     251,   253,     0,    60,    47,    50,    51,    52,    53,    48,
      61,   143,   189,     0,   465,   463,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   297,   294,     0,     0,     0,
       0,    28,   302,   309,   303,   304,   310,   311,   305,   306,
     307,     0,     0,   292,   293,   501,   257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,     0,     0,   334,
     335,     0,     0,     0,     0,   331,   330,   255,     0,     0,
       0,   319,   320,     0,     0,     0,     0,   316,   315,     0,
     351,   346,     0,   381,   378,     0,     0,   411,   415,   413,
       0,     0,   548,     0,     0,   366,   365,   372,   369,     0,
     541,     0,     0,     0,   356,   355,     0,     0,   555,     0,
       0,     0,     0,   432,   424,   426,   431,   428,   433,     0,
     430,   438,     0,     0,     0,   575,     0,   577,     0,   451,
       0,     0,     0,   478,   479,   481,   482,   531,   485,   487,
     488,   489,   514,   491,     0,     0,   613,   603,     0,     0,
       0,     0,     0,   609,   618,   613,   622,   624,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,   125,     0,     0,   126,   124,   134,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,     5,     7,     8,
       9,    10,     6,     3,     4,    16,    18,    19,     0,     0,
       0,    25,    21,     0,     0,   284,   282,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,   274,     0,   266,
       0,   270,     0,   258,   332,     0,   339,   338,   343,   342,
     337,   341,   336,   340,     0,   317,     0,   324,   323,   328,
     327,   322,   326,   321,   325,     0,   352,   350,   382,   379,
     383,   380,     0,     0,     0,     0,   387,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   543,     0,     0,     0,
       0,   420,   425,   427,   429,     0,     0,     0,   441,     0,
       0,     0,   453,     0,   452,   457,   475,   473,   472,   477,
     480,   483,     0,   494,   620,   604,     0,   458,     0,   442,
       0,     0,   616,     0,   154,   147,   149,   153,   151,     0,
       0,     0,   156,   160,   159,   162,   161,     0,     0,     0,
       0,     0,   169,   170,   171,   180,     0,   174,   175,   176,
     177,   178,     0,     0,   191,   192,   182,     0,     0,   187,
       0,     0,     0,   218,     0,   172,     0,     0,    27,   224,
     219,   220,   221,   222,   223,   118,   117,     0,   238,     0,
       0,     0,     0,   466,   464,     0,    23,    26,   285,   283,
     299,   296,   298,   295,     0,     0,   290,   288,   259,   272,
     264,   267,   261,   273,   265,   269,     0,     0,   329,     0,
     314,     0,   402,   412,   405,   416,   408,   414,   388,     0,
       0,     0,     0,     0,   568,     0,     0,     0,     0,   558,
     559,     0,   417,     0,     0,     0,   422,     0,     0,     0,
     444,     0,     0,   454,     0,   476,   474,   493,   495,     0,
       0,   574,     0,     0,     0,     0,   148,   150,   152,   205,
       0,     0,     0,     0,     0,     0,     0,     0,   188,   206,
       0,     0,     0,     0,   237,   233,     0,   190,   139,    24,
     291,   289,     0,     0,   275,   260,   271,   263,   268,     0,
       0,     0,     0,     0,     0,   390,   389,     0,   362,   373,
     371,     0,     0,     0,     0,   560,     0,     0,     0,     0,
       0,   435,     0,   576,     0,   445,     0,   564,   578,   455,
       0,     0,   459,   443,     0,     0,     0,   163,   164,     0,
     165,     0,   167,   179,   186,   185,    22,     0,     0,   173,
     227,   141,   277,   279,     0,     0,     0,     0,     0,     0,
       0,   391,   361,     0,     0,   398,   397,     0,     0,     0,
       0,   439,   423,   437,   447,     0,   446,   497,     0,   606,
       0,   212,     0,     0,   213,   207,   276,   278,   333,   318,
     404,   407,   410,   598,   599,   569,     0,   600,   421,   448,
       0,   608,   610,   166,   168,     0,   449,   601
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1008,    -7,  -227,  -180,   189,  -404,    79, -1008, -1008, -1008,
   -1008, -1008, -1008,  -133, -1008, -1008, -1008,   509, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
     563, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008,  -360, -1008,  -354, -1008,  -352, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008,  -898,  -357, -1008, -1008, -1008,
   -1008,    96,  -737, -1007,   -57,  -710,   -56, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008,  -840, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,  -355,
   -1008, -1008, -1008,  -350, -1008, -1008, -1008
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   869,   191,   192,   193,   194,   212,   383,   384,   195,
     515,   516,   517,   196,   533,   750,   751,   598,   223,   224,
     225,   200,   201,   202,   573,   574,   575,   206,   207,   208,
     567,   213,   214,   215,   228,   229,   230,   235,   236,   237,
     282,   283,   284,   259,   260,   261,   263,   264,   265,   268,
     269,   270,   243,   244,   245,   249,   253,   291,   250,   286,
     287,   288,   309,   963,  1041,   965,  1042,   967,  1043,   247,
     822,   824,   823,   304,   307,   987,   651,   311,   652,   653,
     845,   312,   870,   991,   318,   868,   197,   754,   753,   329,
     859,   330,   333,   336,   344,   346,   350,   674,   351,  1070,
      83,   254,   656,   680,   849,   851,   358,   679,   359,    84,
     685,    85,   360,    86,   676,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     190,   319,   682,   320,   211,   684,   209,   226,   723,   198,
     432,   246,   686,   687,   352,   932,   353,   258,   209,   217,
     271,   272,   997,   354,   353,   571,   577,   218,   279,   280,
     355,   354,   579,   581,   292,   583,   385,   388,   355,   391,
     299,   931,   303,   417,   219,   308,   531,   427,   768,   617,
    -605,  -436,   190,   321,   295,   856,   332,  1114,  -605,   335,
     337,   338,   643,   914,   439,   643,  -138,   340,   275,   231,
     536,   537,   220,   221,   538,   415,   539,   540,   541,   542,
     543,   232,   233,   413,   372,   562,   563,  1059,   266,   658,
    1062,  1064,   251,   227,   252,     3,   618,   915,   394,   528,
     341,   916,   659,   414,  1065,   529,  1056,   289,  1139,   290,
     800,   644,   645,   646,   644,   645,   646,   562,   568,   801,
     647,   276,  1079,   647,   298,    87,   857,   296,   769,   999,
     234,   858,  1081,  1146,  1004,   697,   660,   619,  1066,   989,
    1057,   992,   324,   766,   767,   534,   416,   535,    88,   267,
     325,   342,   343,   564,   565,   566,  1080,   386,   648,   376,
     356,   648,  1112,   544,   418,   802,  1082,   620,   356,   649,
     811,   545,   649,   948,   803,   387,   532,   650,   203,   812,
     650,   248,   419,   204,   440,   564,   565,   569,   956,   216,
     949,   552,   813,  1026,  1035,   621,   555,   557,   559,   428,
     389,   814,   392,   262,   326,   327,   328,   957,   377,   378,
     379,  1036,   907,   694,   695,   380,   381,   382,   950,   951,
     274,  -462,   696,   205,   610,  -462,   277,  -462,   549,   550,
    1117,  -461,   551,   613,   390,  -461,   393,  -461,   278,  1037,
    1038,   238,   239,   240,   241,   273,   524,   622,   623,   525,
     526,   842,   843,   242,   281,   625,   527,   549,   550,   627,
     844,   551,   547,   285,   548,  1073,   673,   293,  -492,   294,
     632,   633,   300,   742,   634,   743,   199,   553,   744,   297,
     745,   306,   556,   558,   560,   305,   222,   637,   638,   345,
    1072,   979,   572,   578,   322,   323,   576,   339,   641,   580,
     582,   310,   584,   854,   347,   316,   317,   361,   348,   349,
     611,   757,   758,   759,   760,   761,   762,   763,   764,   614,
     357,   441,   442,   362,   663,   313,   864,   665,   357,   918,
     872,   363,   667,   520,   521,   668,   669,   670,   671,   314,
     672,   626,   796,   797,   315,   628,   365,   677,   798,   799,
     807,   808,   809,   810,   536,   537,   755,   756,   373,   364,
     635,   374,   375,   395,   396,   397,   698,   699,   701,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   704,   410,   411,   705,   412,   420,   421,   706,   707,
     708,   709,   710,   711,   712,   713,   714,   715,   716,   717,
     718,   719,   720,   721,   722,   422,   423,   424,   425,   426,
     429,   433,   434,   435,   436,   437,   438,   771,   772,   518,
     729,   519,   730,   731,   523,   522,   734,   735,   736,   737,
     738,   739,   546,   530,   586,   587,   554,   561,   209,   585,
     624,   636,   588,   612,   615,   616,   589,   590,   586,   599,
     629,   639,   630,   700,   702,   591,   600,   631,   640,   642,
     601,   602,   654,   655,   592,  -563,   593,   594,   661,   603,
     657,   662,   664,   666,   675,   595,   596,   681,   604,   688,
     605,   606,   689,   678,   690,   691,   597,   692,   693,   607,
     608,   697,   733,   703,   724,   740,   725,   726,   727,   728,
     597,   741,   732,   746,   777,   778,   773,   779,   747,   780,
     774,   748,   749,  -140,   752,   783,   786,   784,   788,   790,
     792,   795,   826,   804,   815,   825,   806,   827,   832,   833,
     837,   836,   840,   846,   839,   847,   853,   862,   866,   871,
     850,   863,   879,   880,   881,   882,   874,   775,   875,   876,
     877,   878,   883,   884,   885,   886,   888,   889,   890,   891,
     892,   896,   902,   903,   781,   893,   908,   894,   895,   897,
     938,   935,   898,   899,   900,   901,   904,   905,   906,   909,
     794,   913,   919,   920,   921,   922,   923,   924,   925,   928,
     939,   926,   944,   930,   945,   962,   969,   964,   971,   966,
     974,   852,   968,   977,   855,   816,   972,   978,   818,   820,
     973,   982,   984,   985,   988,   986,   994,   828,   998,   995,
    1003,  1000,   829,  1002,   831,   981,  1005,  1001,   996,   834,
    1009,  1018,   838,   776,  1019,   841,   936,   937,   990,  1020,
    1021,   348,   916,   549,  1024,  1025,  1006,  1007,  1008,  1028,
     782,  1027,  1030,  1031,  1039,  1034,   785,   860,   787,   861,
     789,  1032,   791,  1033,   793,  1040,  -403,  -406,  -409,  1044,
    1047,   865,  1051,   867,  1060,  1052,  1092,  1061,   805,  -496,
    1071,   873,  1074,  1075,  1077,  1078,  1083,  1084,  1094,  1085,
    1063,   817,  1086,  1089,   819,   821,   887,   933,   934,  1098,
    1093,  1095,  1099,  1090,  1100,  1091,  1103,  1104,   830,  1116,
    1115,  1067,  1068,  1105,  1106,   835,  1107,  1109,  1110,   910,
     911,   912,  1111,  1113,  1118,   917,  1120,  1121,  1124,  1125,
    1126,  1128,  1127,  1140,  1145,   765,   609,  1129,  1130,  1136,
     927,  1143,   929,  1144,   867,  1131,   190,   190,  1132,     0,
     848,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     940,     0,   942,     0,  1017,   570,   946,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   958,     0,
       0,     0,     0,     0,     0,     0,   993,   959,     0,     0,
       0,     0,  1029,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     970,     0,     0,     0,     0,   975,   976,     0,     0,     0,
       0,     0,     0,   983,     0,     0,     0,     0,     0,     0,
       0,     0,   867,     0,   867,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   941,     0,   943,
       0,     0,   947,     0,     0,   952,     0,   953,     0,   954,
       0,   955,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1010,  1011,  1012,  1013,   960,     0,     0,     0,  1014,
       0,     0,     0,     0,   961,  1015,  1016,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1022,     0,  1023,
       0,     0,     0,     0,     0,     0,   980,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1069,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1045,     0,  1048,  1049,     0,     0,     0,     0,
    1053,     0,     0,     0,  1055,     0,     0,  1058,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   867,     0,     0,     0,     0,  1076,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1087,  1088,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1096,     0,     0,     0,     0,  1101,     0,     0,
    1102,     0,     0,     0,     0,     0,     0,     0,  1046,  1108,
       0,     0,  1050,     0,     0,     0,     0,  1054,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1119,     0,     0,
       0,     0,  1122,     0,  1123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1133,  1134,     4,     0,
    1135,     0,  1137,  1138,     0,     5,     6,     0,     0,     0,
       0,  1141,     0,  1142,     0,     0,     0,     7,     0,  1097,
       0,     0,     0,     8,     9,     0,    10,     0,    11,    12,
       0,    13,    14,     0,     0,     0,     0,     0,  1147,    15,
       0,    16,    17,    18,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,    21,
      22,    23,    24,    25,    26,     0,     0,     0,     0,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,    30,    31,     0,
      32,     0,     0,    33,    34,    35,     0,    36,    37,    38,
      39,    40,    41,    42,     0,    43,     0,     0,     0,    44,
      45,    46,    47,    48,     0,    49,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,     0,     0,     0,     0,     0,     0,    52,     0,     0,
      53,     0,    54,    55,    56,     0,     0,    57,     0,     0,
       0,    58,     0,    59,     0,     0,    60,    61,     0,     0,
       0,     0,    62,     0,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,     0,     0,    75,
      76,    77,    78,    79,     4,     0,     0,     0,     0,     0,
       0,     5,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     8,
       9,     0,    10,     0,    11,    12,     0,    13,    14,     0,
       0,     0,     0,     0,     0,    15,     0,    16,    17,    18,
       0,     0,     0,    80,    19,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,    21,    22,    23,    24,    25,
      26,     0,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    29,    30,    31,     0,    32,     0,     0,    33,
      34,    35,     0,    36,    37,    38,    39,    40,    41,    42,
       0,    43,    81,     0,    82,    44,    45,    46,    47,    48,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,    53,     0,    54,    55,
      56,     0,     0,    57,     0,     0,     0,    58,     0,    59,
       0,     0,    60,    61,     0,     0,     0,     0,    62,     0,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,     0,     0,    75,    76,    77,    78,    79,
       0,   331,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      92,    93,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,     0,     0,
      96,     0,     0,    97,     0,     0,     0,     0,     0,     0,
       0,    98,    99,     0,   100,     0,     0,     0,     0,     0,
     101,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   106,   107,   683,     0,
       0,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,   120,
     121,   122,     0,   123,   124,   125,     0,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   128,     0,   129,     0,   130,     0,     0,     0,     0,
       0,     0,     0,   131,     0,     0,   132,     0,     0,   133,
       0,   134,   135,   136,   137,     0,   138,   139,     0,     0,
       0,     0,   140,   141,   142,   143,     0,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,     0,
       0,     0,     0,     0,     0,     0,     0,   156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,     0,   158,   159,   160,   161,
       0,   162,   163,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     0,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   334,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,     0,     0,    96,     0,     0,    97,     0,     0,     0,
       0,     0,     0,     0,    98,    99,     0,   100,     0,     0,
       0,     0,     0,   101,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
       0,     0,   120,   121,   122,     0,   123,   124,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,     0,   129,     0,   130,     0,
       0,     0,     0,     0,     0,     0,   131,     0,     0,   132,
       0,     0,   133,     0,   134,   135,   136,   137,     0,   138,
     139,     0,     0,     0,     0,   140,   141,   142,   143,     0,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,     0,     0,     0,     0,     0,     0,     0,     0,
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,     0,   158,
     159,   160,   161,     0,   162,   163,   164,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,    89,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,     0,     0,
       0,     0,     0,     0,     0,    90,   366,     0,     0,     0,
       0,     0,     0,     0,     0,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,     0,
       0,    96,     0,     0,    97,   367,   368,   369,     0,     0,
       0,     0,    98,    99,   370,   100,     0,     0,     0,     0,
       0,   101,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
     120,   121,   122,   371,   123,   124,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,     0,   129,     0,   130,     0,     0,     0,
       0,     0,     0,     0,   131,     0,     0,   132,     0,     0,
     133,     0,   134,   135,   136,   137,     0,   138,   139,     0,
       0,     0,     0,   140,   141,   142,   143,     0,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,     0,     0,     0,     0,     0,     0,     0,   156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,     0,   158,   159,   160,
     161,     0,   162,   163,   164,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,    89,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,     0,     0,     0,     0,
       0,     0,     0,   255,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,     0,   256,   257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      93,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,     0,     0,    96,
       0,     0,    97,     0,     0,     0,     0,     0,     0,     0,
      98,    99,     0,   100,     0,     0,     0,     0,     0,   101,
     102,   103,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,     0,   120,   121,
     122,     0,   123,   124,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,   129,     0,   130,     0,     0,     0,     0,     0,
       0,     0,   131,     0,     0,   132,     0,     0,   133,     0,
     134,   135,   136,   137,     0,   138,   139,     0,     0,     0,
       0,   140,   141,   142,   143,     0,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,     0,     0,
       0,     0,     0,     0,     0,     0,   156,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   157,     0,   158,   159,   160,   161,     0,
     162,   163,   164,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
      89,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,     0,     0,     0,     0,     0,     0,
       0,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,   301,
     302,     0,     0,     0,     0,     0,     0,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,     0,     0,    96,     0,     0,
      97,     0,     0,     0,     0,     0,     0,     0,    98,    99,
       0,   100,     0,     0,     0,     0,     0,   101,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,     0,     0,   120,   121,   122,     0,
     123,   124,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,     0,
     129,     0,   130,     0,     0,     0,     0,     0,     0,     0,
     131,     0,     0,   132,     0,     0,   133,     0,   134,   135,
     136,   137,     0,   138,   139,     0,     0,     0,     0,   140,
     141,   142,   143,     0,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,     0,     0,     0,     0,
       0,     0,     0,     0,   156,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,     0,   158,   159,   160,   161,     0,   162,   163,
     164,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,    89,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,     0,     0,     0,   209,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,     0,     0,    96,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,    98,    99,     0,   100,
       0,     0,     0,     0,     0,   101,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,     0,     0,   120,   121,   122,     0,   123,   124,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,   129,     0,
     130,     0,     0,     0,     0,     0,     0,     0,   131,     0,
       0,   132,     0,     0,   133,     0,   134,   135,   136,   137,
       0,   138,   139,     0,     0,     0,     0,   140,   141,   142,
     143,     0,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,     0,     0,     0,     0,     0,     0,
       0,     0,   156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   210,
       0,   158,   159,   160,   161,     0,   162,   163,   164,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,    89,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
       0,     0,     0,   209,     0,     0,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,     0,     0,    96,     0,     0,    97,     0,     0,     0,
       0,     0,     0,     0,    98,    99,     0,   100,     0,     0,
       0,     0,     0,   101,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
       0,     0,   120,   121,   122,     0,   123,   124,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,     0,   129,     0,   130,     0,
       0,     0,     0,     0,     0,     0,   131,     0,     0,   132,
       0,     0,   133,     0,   134,   135,   136,   137,     0,   138,
     139,     0,     0,     0,     0,   140,   141,   142,   143,     0,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,     0,     0,     0,     0,     0,     0,     0,     0,
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,     0,   158,
     159,   160,   161,     0,   162,   163,   164,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,    93,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,     0,     0,    96,     0,     0,    97,     0,     0,
       0,     0,     0,     0,     0,    98,    99,     0,   100,     0,
       0,     0,     0,     0,   101,   102,   103,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,     0,     0,   120,   121,   122,     0,   123,   124,   125,
       0,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,   129,     0,   130,
       0,     0,     0,     0,     0,     0,     0,   131,     0,     0,
     132,     0,     0,   133,     0,   134,   135,   136,   137,     0,
     138,   139,     0,     0,     0,     0,   140,   141,   142,   143,
       0,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,     0,     0,     0,     0,     0,     0,     0,
       0,   156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,     0,
     158,   159,   160,   161,     0,   162,   163,   164,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,    89,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,     0,
       0,     0,     0,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,    96,     0,     0,    97,     0,     0,     0,     0,
       0,     0,     0,    98,    99,     0,   100,     0,     0,     0,
       0,     0,   101,   102,   103,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,     0,
       0,   120,   121,   122,     0,   123,   124,   125,     0,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,   129,     0,   130,     0,     0,
       0,     0,     0,     0,     0,   131,     0,     0,   132,     0,
       0,   133,     0,   134,   135,   136,   137,     0,   138,   139,
       0,     0,     0,     0,   140,   141,   142,   143,     0,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,     0,     0,     0,     0,     0,     0,     0,     0,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,     0,   158,   159,
     160,   161,     0,   162,   163,   164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,    89,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    93,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,     0,     0,
      96,     0,     0,    97,     0,     0,     0,     0,     0,     0,
       0,    98,    99,     0,   100,     0,     0,     0,     0,     0,
     101,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
       0,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,   120,
     121,   122,     0,   123,   124,   125,     0,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   128,     0,   129,     0,   130,     0,     0,     0,     0,
       0,     0,     0,   131,     0,     0,   132,     0,     0,   133,
       0,   134,   135,   136,   137,     0,   138,   139,     0,     0,
       0,     0,   140,   141,   142,   143,     0,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,     0,
       0,     0,     0,     0,     0,     0,     0,   156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,     0,   158,   159,   160,   161,
       0,   162,   163,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,    89,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,     0,     0,     0,     0,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,    96,     0,
       0,    97,     0,     0,     0,     0,     0,     0,     0,    98,
      99,     0,   100,     0,     0,     0,     0,     0,   101,   102,
     103,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   770,   106,   107,     0,     0,     0,     0,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,     0,     0,   120,   121,   122,
       0,   123,   124,   125,     0,   126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
       0,   129,     0,   130,     0,     0,     0,     0,     0,     0,
       0,   131,     0,     0,   132,     0,     0,   133,     0,   134,
     135,   136,   137,     0,   138,   139,     0,     0,     0,     0,
     140,   141,   142,   431,     0,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,     0,     0,     0,
       0,     0,     0,     0,     0,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,     0,   158,   159,   160,   161,     0,   162,
     163,   164,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,    89,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,     0,     0,    96,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,    98,    99,     0,
     100,     0,     0,     0,     0,     0,   101,   102,   103,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,     0,     0,   120,   121,   122,     0,   123,
     124,   125,     0,   126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,     0,   129,
       0,   130,     0,     0,     0,     0,     0,     0,     0,   131,
       0,     0,   132,     0,     0,   133,     0,   134,   135,   136,
     137,     0,   138,   139,     0,     0,     0,     0,   140,   141,
     142,   431,     0,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,     0,     0,     0,     0,     0,
       0,     0,     0,   156,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,     0,   158,   159,   160,   161,     0,   162,   163,   164,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,    89,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,    93,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,     0,     0,    96,     0,     0,    97,     0,     0,
       0,     0,     0,     0,     0,    98,    99,     0,   100,     0,
       0,     0,     0,     0,   101,   102,   103,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,     0,     0,   120,   121,   122,     0,   123,   124,   125,
       0,   126,     0,     0,   443,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,   129,     0,   130,
       0,     0,     0,     0,     0,     0,     0,   131,     0,     0,
     132,     0,     0,   133,     0,   134,   135,   136,   137,     0,
     138,   139,     0,     0,     0,     0,   140,   141,   142,   431,
       0,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,     0,     0,   444,     0,     0,     0,     0,
     445,   156,   446,     0,     0,     0,     0,     0,     0,     0,
       0,   447,     0,     0,     0,     0,     0,     0,   157,     0,
     158,   159,   160,   161,     0,   162,   163,   164,     0,     0,
       0,     0,   448,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   449,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   450,     0,     0,
       0,   451,     0,   452,   453,   454,   455,   456,   457,     0,
     458,   459,     0,   460,   461,   462,   463,   464,   465,   466,
     467,     0,   468,   469,     0,   470,     0,     0,     0,     0,
       0,     0,     0,     0,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514
};

static const yytype_int16 yycheck[] =
{
       7,    58,   359,    59,    11,   360,    26,    14,   412,    30,
     143,    18,   362,   363,     4,   752,     6,    24,    26,    30,
      27,    28,   862,    13,     6,    30,    30,    38,    35,    36,
      20,    13,    30,    30,    41,    30,    20,    40,    20,    40,
      47,   751,    49,    20,    55,    52,    20,    40,   111,    59,
      40,    20,    59,    60,    74,    90,    63,  1064,    40,    66,
      67,    68,    31,     7,    83,    31,    40,    74,    94,    30,
       8,     9,    83,    84,    12,    90,    14,    15,    16,    17,
      18,    42,    43,    20,    91,    85,    86,   985,    30,     7,
     988,     7,   297,    14,   299,     0,   106,    41,   105,   280,
      47,     7,    20,    40,    20,   286,     7,   297,  1115,   299,
      51,    80,    81,    82,    80,    81,    82,    85,    86,    60,
      89,   147,     7,    89,    45,   297,   161,   147,   191,   866,
      91,   166,     7,  1140,   871,    41,    54,   147,    54,   849,
      41,   851,   101,   547,   548,     5,   161,     7,   297,    91,
     109,    98,    99,   153,   154,   155,    41,   141,   127,    31,
     150,   127,  1060,   101,   141,    51,    41,    20,   150,   138,
      51,   109,   138,    38,    60,   159,   150,   146,    32,    60,
     146,   297,   159,    37,   203,   153,   154,   155,    35,    28,
      55,   198,    51,   930,    38,    48,   203,   204,   205,   192,
     203,    60,   203,    30,   163,   164,   165,    54,    80,    81,
      82,    55,     7,    80,    81,    87,    88,    89,    83,    84,
      94,     0,    89,    77,   231,     4,    40,     6,    23,    24,
    1070,     0,    27,   240,   237,     4,   237,     6,    40,    83,
      84,    48,    49,    50,    51,   230,   276,   254,   255,   279,
     280,    80,    81,    60,    30,   262,   286,    23,    24,   266,
      89,    27,    19,    30,    21,  1002,     5,   147,     7,    74,
     277,   278,   297,    96,   281,    98,   297,   198,    96,   299,
      98,   297,   203,   204,   205,    40,   297,   294,   295,    47,
    1000,   299,   297,   297,    48,    49,   217,   175,   305,   297,
     297,   297,   297,   660,    13,   297,   298,     6,   297,   298,
     231,   538,   539,   540,   541,   542,   543,   544,   545,   240,
     310,    98,    99,     4,   331,   297,   676,   334,   310,   733,
     685,     4,   339,    98,    99,    98,    99,    96,    97,   297,
     347,   262,    62,    63,   297,   266,    20,   354,    62,    63,
      62,    63,    62,    63,     8,     9,   536,   537,    40,   299,
     281,    40,    40,    40,    40,    40,   373,   374,   375,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,   388,    40,    40,   391,    40,    20,    20,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,    20,    20,    20,    20,    20,
      40,    40,    40,    40,    40,    40,    40,   550,   551,    40,
     427,   236,   429,   430,   279,    20,   433,   434,   435,   436,
     437,   438,   133,   279,    30,    31,    30,   299,    26,    30,
       7,    40,    38,    35,    52,    52,    42,    43,    30,    31,
      35,    13,    75,   374,   375,    51,    38,   150,   155,     7,
      42,    43,     7,   150,    60,   150,    62,    63,     7,    51,
     150,     7,     7,     7,     5,    71,    72,    40,    60,    40,
      62,    63,    41,    13,    41,    41,    82,    41,    41,    71,
      72,    41,    25,    40,    40,   220,   297,    40,    40,    40,
      82,   220,    40,   227,    78,    78,    35,    78,    40,    78,
      35,   518,    40,    40,    40,    30,    30,    54,    30,    30,
      30,    39,   297,    40,    40,    48,    39,     7,     7,     7,
       7,    75,     7,    40,   106,    20,     7,     7,    40,    40,
     150,   297,    41,    41,    41,    41,   299,   554,   299,   299,
     299,   299,    41,    41,    41,    41,     7,     7,     7,     7,
      41,     7,     7,     7,   571,    41,   297,    41,    41,    41,
     297,   191,    41,    41,    41,    41,    41,    41,    41,    41,
     587,    41,    41,    41,    41,    41,    41,    41,    97,    41,
     297,    99,    35,    40,    35,   297,    13,   297,     7,   297,
     151,   658,   297,     7,   661,   612,    48,     7,   615,   616,
      48,   297,     7,    40,    40,   299,     7,   624,     5,   168,
      41,     7,   629,     7,   631,    78,     7,   151,   168,   636,
      41,    41,   639,   554,    41,   642,   769,   770,   297,     7,
       7,   297,     7,    23,    41,    41,   299,   299,   299,    41,
     571,   151,   297,   297,     7,   298,   577,   664,   579,   666,
     581,    35,   583,    35,   585,     7,     7,     7,     7,    13,
       7,   678,    41,   680,     7,    41,   298,    41,   599,   297,
      41,   688,    13,    41,    41,    41,    41,    41,    35,    41,
     151,   612,    41,    41,   615,   616,   703,   753,   754,     7,
     298,    35,     7,    41,     7,    41,    13,    13,   629,  1066,
       7,   151,   151,    41,    41,   636,   119,    13,    78,   726,
     727,   728,    41,    41,    13,   732,    13,    41,    41,    41,
     298,    41,   298,     7,    13,   546,   227,    41,  1098,    41,
     747,    41,   749,    41,   751,  1099,   753,   754,  1100,    -1,
     654,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     777,    -1,   779,    -1,   907,   212,   783,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   795,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   853,   804,    -1,    -1,
      -1,    -1,   935,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     827,    -1,    -1,    -1,    -1,   832,   833,    -1,    -1,    -1,
      -1,    -1,    -1,   840,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   849,    -1,   851,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   778,    -1,   780,
      -1,    -1,   783,    -1,    -1,   786,    -1,   788,    -1,   790,
      -1,   792,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   888,   889,   890,   891,   806,    -1,    -1,    -1,   896,
      -1,    -1,    -1,    -1,   815,   902,   903,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   914,    -1,   916,
      -1,    -1,    -1,    -1,    -1,    -1,   837,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   994,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   969,    -1,   971,   972,    -1,    -1,    -1,    -1,
     977,    -1,    -1,    -1,   981,    -1,    -1,   984,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1000,    -1,    -1,    -1,    -1,  1005,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1020,  1021,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1039,    -1,    -1,    -1,    -1,  1044,    -1,    -1,
    1047,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   969,  1056,
      -1,    -1,   973,    -1,    -1,    -1,    -1,   978,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1074,    -1,    -1,
      -1,    -1,  1079,    -1,  1081,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1103,  1104,     3,    -1,
    1107,    -1,  1109,  1110,    -1,    10,    11,    -1,    -1,    -1,
      -1,  1118,    -1,  1120,    -1,    -1,    -1,    22,    -1,  1040,
      -1,    -1,    -1,    28,    29,    -1,    31,    -1,    33,    34,
      -1,    36,    37,    -1,    -1,    -1,    -1,    -1,  1145,    44,
      -1,    46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    -1,
      95,    -1,    -1,    98,    99,   100,    -1,   102,   103,   104,
     105,   106,   107,   108,    -1,   110,    -1,    -1,    -1,   114,
     115,   116,   117,   118,    -1,   120,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,
     145,    -1,   147,   148,   149,    -1,    -1,   152,    -1,    -1,
      -1,   156,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,
      -1,    -1,   167,    -1,   169,   170,   171,   172,   173,   174,
      -1,   176,   177,   178,   179,   180,   181,    -1,    -1,   184,
     185,   186,   187,   188,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    31,    -1,    33,    34,    -1,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    46,    47,    48,
      -1,    -1,    -1,   238,    53,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    -1,    95,    -1,    -1,    98,
      99,   100,    -1,   102,   103,   104,   105,   106,   107,   108,
      -1,   110,   297,    -1,   299,   114,   115,   116,   117,   118,
      -1,   120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,    -1,   145,    -1,   147,   148,
     149,    -1,    -1,   152,    -1,    -1,    -1,   156,    -1,   158,
      -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,    -1,
     169,   170,   171,   172,   173,   174,    -1,   176,   177,   178,
     179,   180,   181,    -1,    -1,   184,   185,   186,   187,   188,
      -1,     7,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   297,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,   137,    -1,   139,   140,   141,    -1,   143,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,   159,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   169,    -1,    -1,   172,    -1,    -1,   175,
      -1,   177,   178,   179,   180,    -1,   182,   183,    -1,    -1,
      -1,    -1,   188,   189,   190,   191,    -1,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,    -1,   232,   233,   234,   235,
      -1,   237,   238,   239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,    -1,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,     7,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,   172,
      -1,    -1,   175,    -1,   177,   178,   179,   180,    -1,   182,
     183,    -1,    -1,    -1,    -1,   188,   189,   190,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,   232,
     233,   234,   235,    -1,   237,   238,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,     9,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    76,    -1,    -1,    79,    80,    81,    82,    -1,    -1,
      -1,    -1,    87,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    -1,    -1,
     135,   136,   137,   138,   139,   140,   141,    -1,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,    -1,   159,    -1,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   169,    -1,    -1,   172,    -1,    -1,
     175,    -1,   177,   178,   179,   180,    -1,   182,   183,    -1,
      -1,    -1,    -1,   188,   189,   190,   191,    -1,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   230,    -1,   232,   233,   234,
     235,    -1,   237,   238,   239,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,     9,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    76,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,
      97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
     137,    -1,   139,   140,   141,    -1,   143,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,   159,    -1,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   169,    -1,    -1,   172,    -1,    -1,   175,    -1,
     177,   178,   179,   180,    -1,   182,   183,    -1,    -1,    -1,
      -1,   188,   189,   190,   191,    -1,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,    -1,   232,   233,   234,   235,    -1,
     237,   238,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
       9,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    -1,    -1,   135,   136,   137,    -1,
     139,   140,   141,    -1,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
     159,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,    -1,    -1,   172,    -1,    -1,   175,    -1,   177,   178,
     179,   180,    -1,   182,   183,    -1,    -1,    -1,    -1,   188,
     189,   190,   191,    -1,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   230,    -1,   232,   233,   234,   235,    -1,   237,   238,
     239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,     9,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,    -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     201,   202,   203,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,
      -1,   232,   233,   234,   235,    -1,   237,   238,   239,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,     9,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,    -1,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    -1,    -1,
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
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,   172,
      -1,    -1,   175,    -1,   177,   178,   179,   180,    -1,   182,
     183,    -1,    -1,    -1,    -1,   188,   189,   190,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,   232,
     233,   234,   235,    -1,   237,   238,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,    -1,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     202,   203,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,
     232,   233,   234,   235,    -1,   237,   238,   239,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,     9,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,    -1,    -1,
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
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,   232,   233,
     234,   235,    -1,   237,   238,   239,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,     9,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      76,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,   137,    -1,   139,   140,   141,    -1,   143,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,   159,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   169,    -1,    -1,   172,    -1,    -1,   175,
      -1,   177,   178,   179,   180,    -1,   182,   183,    -1,    -1,
      -1,    -1,   188,   189,   190,   191,    -1,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,    -1,   232,   233,   234,   235,
      -1,   237,   238,   239,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,     9,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,   135,   136,   137,
      -1,   139,   140,   141,    -1,   143,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
      -1,   159,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   169,    -1,    -1,   172,    -1,    -1,   175,    -1,   177,
     178,   179,   180,    -1,   182,   183,    -1,    -1,    -1,    -1,
     188,   189,   190,   191,    -1,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,    -1,   232,   233,   234,   235,    -1,   237,
     238,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,     9,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    76,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    -1,    -1,   135,   136,   137,    -1,   139,
     140,   141,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,   159,
      -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,
      -1,    -1,   172,    -1,    -1,   175,    -1,   177,   178,   179,
     180,    -1,   182,   183,    -1,    -1,    -1,    -1,   188,   189,
     190,   191,    -1,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     230,    -1,   232,   233,   234,   235,    -1,   237,   238,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,     9,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
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
      -1,   143,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,   159,    -1,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,
     172,    -1,    -1,   175,    -1,   177,   178,   179,   180,    -1,
     182,   183,    -1,    -1,    -1,    -1,   188,   189,   190,   191,
      -1,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      96,   213,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,
     232,   233,   234,   235,    -1,   237,   238,   239,    -1,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   171,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,
      -1,   207,    -1,   209,   210,   211,   212,   213,   214,    -1,
     216,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,    -1,   228,   229,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   426,   427,     0,     3,    10,    11,    22,    28,    29,
      31,    33,    34,    36,    37,    44,    46,    47,    48,    53,
      59,    64,    65,    66,    67,    68,    69,    74,    90,    91,
      92,    93,    95,    98,    99,   100,   102,   103,   104,   105,
     106,   107,   108,   110,   114,   115,   116,   117,   118,   120,
     121,   134,   142,   145,   147,   148,   149,   152,   156,   158,
     161,   162,   167,   169,   170,   171,   172,   173,   174,   176,
     177,   178,   179,   180,   181,   184,   185,   186,   187,   188,
     238,   297,   299,   411,   420,   422,   424,   297,   297,     9,
      30,    40,    56,    57,    58,    73,    76,    79,    87,    88,
      90,    96,    97,    98,    99,   111,   112,   113,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     135,   136,   137,   139,   140,   141,   143,   144,   157,   159,
     161,   169,   172,   175,   177,   178,   179,   180,   182,   183,
     188,   189,   190,   191,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   213,   230,   232,   233,
     234,   235,   237,   238,   239,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     312,   313,   314,   315,   316,   320,   324,   397,    30,   297,
     332,   333,   334,    32,    37,    77,   338,   339,   340,    26,
     230,   312,   317,   342,   343,   344,    28,    30,    38,    55,
      83,    84,   297,   329,   330,   331,   312,   317,   345,   346,
     347,    30,    42,    43,    91,   348,   349,   350,    48,    49,
      50,    51,    60,   363,   364,   365,   312,   380,   297,   366,
     369,   297,   299,   367,   412,    30,    42,    43,   312,   354,
     355,   356,    30,   357,   358,   359,    30,    91,   360,   361,
     362,   312,   312,   230,    94,    94,   147,    40,    40,   312,
     312,    30,   351,   352,   353,    30,   370,   371,   372,   297,
     299,   368,   312,   147,    74,    74,   147,   299,   317,   312,
     297,    48,    49,   312,   384,    40,   297,   385,   312,   373,
     297,   388,   392,   297,   297,   297,   297,   298,   395,   395,
     397,   312,    48,    49,   101,   109,   163,   164,   165,   400,
     402,     7,   312,   403,     7,   312,   404,   312,   312,   175,
     312,    47,    98,    99,   405,    47,   406,    13,   297,   298,
     407,   409,     4,     6,    13,    20,   150,   310,   417,   419,
     423,     6,     4,     4,   299,    20,    31,    80,    81,    82,
      89,   138,   312,    40,    40,    40,    31,    80,    81,    82,
      87,    88,    89,   318,   319,    20,   141,   159,    40,   203,
     237,    40,   203,   237,   312,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    20,    40,    90,   161,    20,   141,   159,
      20,    20,    20,    20,    20,    20,    20,    40,   192,    40,
      40,   191,   324,    40,    40,    40,    40,    40,    40,    83,
     203,    98,    99,    30,    91,    96,    98,   107,   128,   171,
     203,   207,   209,   210,   211,   212,   213,   214,   216,   217,
     219,   220,   221,   222,   223,   224,   225,   226,   228,   229,
     231,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   321,   322,   323,    40,   236,
      98,    99,    20,   279,   276,   279,   280,   286,   280,   286,
     279,    20,   150,   325,     5,     7,     8,     9,    12,    14,
      15,    16,    17,    18,   101,   109,   133,    19,    21,    23,
      24,    27,   312,   317,    30,   312,   317,   312,   317,   312,
     317,   299,    85,    86,   153,   154,   155,   341,    86,   155,
     341,    30,   297,   335,   336,   337,   317,    30,   297,    30,
     297,    30,   297,    30,   297,    30,    30,    31,    38,    42,
      43,    51,    60,    62,    63,    71,    72,    82,   328,    31,
      38,    42,    43,    51,    60,    62,    63,    71,    72,   328,
     312,   317,    35,   312,   317,    52,    52,    59,   106,   147,
      20,    48,   312,   312,     7,   312,   317,   312,   317,    35,
      75,   150,   312,   312,   312,   317,    40,   312,   312,    13,
     155,   312,     7,    31,    80,    81,    82,    89,   127,   138,
     146,   387,   389,   390,     7,   150,   413,   150,     7,    20,
      54,     7,     7,   312,     7,   312,     7,   312,    98,    99,
      96,    97,   312,     5,   408,     5,   425,   312,    13,   418,
     414,    40,   387,   297,   420,   421,   424,   424,    40,    41,
      41,    41,    41,    41,    80,    81,    89,    41,   312,   312,
     317,   312,   317,    40,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   316,    40,   297,    40,    40,    40,   312,
     312,   312,    40,    25,   312,   312,   312,   312,   312,   312,
     220,   220,    96,    98,    96,    98,   227,    40,   312,    40,
     326,   327,    40,   399,   398,   314,   314,   313,   313,   313,
     313,   313,   313,   313,   313,   315,   316,   316,   111,   191,
     111,   324,   324,    35,    35,   312,   317,    78,    78,    78,
      78,   312,   317,    30,    54,   317,    30,   317,    30,   317,
      30,   317,    30,   317,   312,    39,    62,    63,    62,    63,
      51,    60,    51,    60,    40,   317,    39,    62,    63,    62,
      63,    51,    60,    51,    60,    40,   312,   317,   312,   317,
     312,   317,   381,   383,   382,    48,   297,     7,   312,   312,
     317,   312,     7,     7,   312,   317,    75,     7,   312,   106,
       7,   312,    80,    81,    89,   391,    40,    20,   392,   415,
     150,   416,   395,     7,   387,   395,    90,   161,   166,   401,
     312,   312,     7,   297,   424,   312,    40,   312,   396,   312,
     393,    40,   420,   312,   299,   299,   299,   299,   299,    41,
      41,    41,    41,    41,    41,    41,    41,   312,     7,     7,
       7,     7,    41,    41,    41,    41,     7,    41,    41,    41,
      41,    41,     7,     7,    41,    41,    41,     7,   297,    41,
     312,   312,   312,    41,     7,    41,     7,   312,   316,    41,
      41,    41,    41,    41,    41,    97,    99,   312,    41,   312,
      40,   396,   393,   397,   397,   191,   324,   324,   297,   297,
     312,   317,   312,   317,    35,    35,   312,   317,    38,    55,
      83,    84,   317,   317,   317,   317,    35,    54,   312,   312,
     317,   317,   297,   374,   297,   376,   297,   378,   297,    13,
     312,     7,    48,    48,   151,   312,   312,     7,     7,   299,
     317,    78,   297,   312,     7,    40,   299,   386,    40,   396,
     297,   394,   396,   395,     7,   168,   168,   407,     5,   393,
       7,   151,     7,    41,   393,     7,   299,   299,   299,    41,
     312,   312,   312,   312,   312,   312,   312,   324,    41,    41,
       7,     7,   312,   312,    41,    41,   393,   151,    41,   324,
     297,   297,    35,    35,   298,    38,    55,    83,    84,     7,
       7,   375,   377,   379,    13,   312,   317,     7,   312,   312,
     317,    41,    41,   312,   317,   312,     7,    41,   312,   386,
       7,    41,   386,   151,     7,    20,    54,   151,   151,   395,
     410,    41,   396,   393,    13,    41,   312,    41,    41,     7,
      41,     7,    41,    41,    41,    41,    41,   312,   312,    41,
      41,    41,   298,   298,    35,    35,   312,   317,     7,     7,
       7,   312,   312,    13,    13,    41,    41,   119,   312,    13,
      78,    41,   386,    41,   394,     7,   387,   407,    13,   312,
      13,    41,   312,   312,    41,    41,   298,   298,    41,    41,
     374,   376,   378,   312,   312,   312,    41,   312,   312,   394,
       7,   312,   312,    41,    41,    13,   394,   312
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   311,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   313,   313,   313,   314,   314,   315,   315,   315,
     316,   316,   316,   316,   316,   316,   316,   316,   317,   318,
     318,   318,   318,   318,   318,   318,   319,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     322,   322,   322,   322,   322,   322,   322,   322,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   325,   324,
     326,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   327,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   328,   328,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   330,   330,   330,   330,   330,
     331,   331,   332,   332,   333,   333,   334,   334,   335,   335,
     336,   336,   337,   337,   338,   338,   338,   339,   339,   339,
     340,   340,   341,   341,   341,   342,   342,   342,   342,   343,
     343,   343,   344,   344,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   347,   347,   348,   348,   348,   348,
     348,   349,   349,   350,   350,   351,   352,   353,   353,   354,
     354,   355,   355,   356,   356,   357,   358,   359,   359,   360,
     360,   360,   361,   361,   362,   362,   363,   363,   363,   363,
     363,   364,   364,   364,   365,   365,   366,   366,   366,   366,
     366,   366,   367,   367,   368,   368,   369,   370,   371,   372,
     372,   373,   374,   375,   374,   376,   377,   376,   378,   379,
     378,   381,   380,   382,   380,   383,   380,   384,   384,   384,
     385,   385,   386,   386,   387,   387,   387,   387,   387,   387,
     387,   387,   387,   387,   389,   388,   390,   388,   391,   388,
     392,   392,   393,   393,   394,   394,   394,   394,   394,   394,
     395,   395,   395,   395,   395,   395,   395,   395,   396,   396,
     397,   397,   397,   398,   397,   399,   397,   400,   400,   400,
     400,   400,   401,   401,   401,   401,   401,   402,   403,   403,
     403,   404,   404,   404,   405,   405,   405,   405,   406,   406,
     407,   407,   408,   407,   409,   409,   410,   409,   409,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   412,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   413,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   414,   411,   415,   411,   416,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   417,   411,   418,   411,   419,
     411,   411,   411,   411,   420,   421,   420,   423,   422,   425,
     424,   424,   424,   424,   424,   427,   426
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
       4,     2,     4,     3,     1,     6,     6,     4,     5,     0,
       5,     4,     4,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     5,     5,     7,     2,     2,
       2,     2,     7,     7,     2,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     2,     1,     6,     1,     1,
       1,     1,     1,     5,     1,     1,     2,     5,     4,     1,
       2,     1,     2,     2,     2,     2,     2,     1,     2,     1,
       2,     2,     2,     2,     2,     1,     1,     2,     3,     4,
       5,     4,     3,     5,     4,     4,     3,     4,     5,     4,
       3,     5,     4,     4,     3,     5,     7,     6,     7,     6,
       1,     1,     3,     4,     3,     4,     1,     1,     3,     4,
       3,     4,     1,     1,     2,     4,     4,     2,     4,     4,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     2,
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
       1,     1,     1,     1,     2,     1,     2,     3,     2,     2,
       3,     2,     2,     3,     1,     2,     1,     2,     2,     2,
       1,     2,     0,     4,     3,     4,     0,     6,     1,     2,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     2,     2,     2,     2,     2,
       1,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       2,     3,     2,     2,     1,     1,     2,     2,     2,     1,
       2,     3,     1,     4,     1,     1,     1,     0,     3,     1,
       1,     2,     1,     2,     2,     3,     2,     2,     5,     5,
       6,     1,     2,     0,     6,     2,     2,     2,     5,     8,
       2,     2,     2,     0,     5,     0,     6,     0,     6,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       2,     2,     2,     2,     1,     2,     1,     1,     8,     8,
       8,    10,     2,     3,     4,     0,     7,     0,     8,     0,
       8,     2,     1,     0,     1,     0,     4,     0,     3,     0,
       4,     1,     3,     1,     3,     0,     2
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
#line 88 "src/ugbc.y"
                              {        
        (yyval.string) = variable_and( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s AND %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3593 "src-generated/ugbc.tab.c"
    break;

  case 4: /* expr: expr_math OR expr_math  */
#line 92 "src/ugbc.y"
                             {
        (yyval.string) = variable_or( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s OR %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3602 "src-generated/ugbc.tab.c"
    break;

  case 5: /* expr: expr_math OP_EQUAL expr_math  */
#line 96 "src/ugbc.y"
                                   {
        (yyval.string) = variable_compare( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3610 "src-generated/ugbc.tab.c"
    break;

  case 6: /* expr: expr_math OP_DISEQUAL expr_math  */
#line 99 "src/ugbc.y"
                                      {
        (yyval.string) = variable_compare_not( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3618 "src-generated/ugbc.tab.c"
    break;

  case 7: /* expr: expr_math OP_LT expr_math  */
#line 102 "src/ugbc.y"
                                {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3626 "src-generated/ugbc.tab.c"
    break;

  case 8: /* expr: expr_math OP_LTE expr_math  */
#line 105 "src/ugbc.y"
                                 {
        (yyval.string) = variable_less_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 1 )->name;
    }
#line 3634 "src-generated/ugbc.tab.c"
    break;

  case 9: /* expr: expr_math OP_GT expr_math  */
#line 108 "src/ugbc.y"
                                {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3642 "src-generated/ugbc.tab.c"
    break;

  case 10: /* expr: expr_math OP_GTE expr_math  */
#line 111 "src/ugbc.y"
                                 {
        (yyval.string) = variable_greater_than( _environment, (yyvsp[-2].string), (yyvsp[0].string), 0 )->name;
    }
#line 3650 "src-generated/ugbc.tab.c"
    break;

  case 11: /* expr: NOT expr  */
#line 114 "src/ugbc.y"
               {
        (yyval.string) = variable_not( _environment, (yyvsp[0].string) )->name;
    }
#line 3658 "src-generated/ugbc.tab.c"
    break;

  case 13: /* expr_math: expr_math OP_PLUS term  */
#line 121 "src/ugbc.y"
                             {
        (yyval.string) = variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
    }
#line 3666 "src-generated/ugbc.tab.c"
    break;

  case 14: /* expr_math: expr_math OP_MINUS term  */
#line 124 "src/ugbc.y"
                              {
        (yyval.string) = variable_sub( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s - %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3675 "src-generated/ugbc.tab.c"
    break;

  case 18: /* modula: modula OP_MULTIPLICATION factor  */
#line 137 "src/ugbc.y"
                                      {
        (yyval.string) = variable_mul( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s * %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3684 "src-generated/ugbc.tab.c"
    break;

  case 19: /* modula: modula OP_DIVISION factor  */
#line 141 "src/ugbc.y"
                                {
        (yyval.string) = variable_div( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s / %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 3693 "src-generated/ugbc.tab.c"
    break;

  case 21: /* factor: factor OP_POW exponential  */
#line 149 "src/ugbc.y"
                                  {
        (yyval.string) = powering( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-2].string), (yyvsp[0].string) );
      }
#line 3702 "src-generated/ugbc.tab.c"
    break;

  case 22: /* factor: POWERING OP factor OP_COMMA exponential CP  */
#line 153 "src/ugbc.y"
                                                   {
        (yyval.string) = powering( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
        outline3("; %s = %s ^ %s", (yyval.string), (yyvsp[-3].string), (yyvsp[-1].string) );
      }
#line 3711 "src-generated/ugbc.tab.c"
    break;

  case 23: /* factor: factor HAS BIT exponential  */
#line 157 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[0].string) )->name;
      }
#line 3719 "src-generated/ugbc.tab.c"
    break;

  case 24: /* factor: factor HAS NOT BIT exponential  */
#line 160 "src/ugbc.y"
                                       {
        (yyval.string) = variable_not( _environment, variable_bit( _environment, (yyvsp[-4].string), (yyvsp[0].string) )->name )->name;
      }
#line 3727 "src-generated/ugbc.tab.c"
    break;

  case 25: /* factor: factor IS exponential  */
#line 163 "src/ugbc.y"
                              {
        (yyval.string) = variable_bit( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
      }
#line 3735 "src-generated/ugbc.tab.c"
    break;

  case 26: /* factor: factor IS NOT exponential  */
#line 166 "src/ugbc.y"
                                  {
        (yyval.string) = variable_not( _environment, variable_bit( _environment, (yyvsp[-3].string), (yyvsp[0].string) )->name )->name;
      }
#line 3743 "src-generated/ugbc.tab.c"
    break;

  case 27: /* factor: BIT exponential OF factor  */
#line 169 "src/ugbc.y"
                                  {
        (yyval.string) = variable_bit( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name;
      }
#line 3751 "src-generated/ugbc.tab.c"
    break;

  case 28: /* direct_integer: OP_HASH Integer  */
#line 175 "src/ugbc.y"
                    {
        (yyval.integer) = (yyvsp[0].integer);
    }
#line 3759 "src-generated/ugbc.tab.c"
    break;

  case 29: /* random_definition_simple: BYTE  */
#line 180 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_BYTE )->name;
    }
#line 3767 "src-generated/ugbc.tab.c"
    break;

  case 30: /* random_definition_simple: WORD  */
#line 183 "src/ugbc.y"
           {
        (yyval.string) = random_value( _environment, VT_WORD )->name;
    }
#line 3775 "src-generated/ugbc.tab.c"
    break;

  case 31: /* random_definition_simple: DWORD  */
#line 186 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_DWORD )->name;
    }
#line 3783 "src-generated/ugbc.tab.c"
    break;

  case 32: /* random_definition_simple: POSITION  */
#line 189 "src/ugbc.y"
               {
        (yyval.string) = random_value( _environment, VT_POSITION )->name;
    }
#line 3791 "src-generated/ugbc.tab.c"
    break;

  case 33: /* random_definition_simple: COLOR  */
#line 192 "src/ugbc.y"
            {
        (yyval.string) = random_value( _environment, VT_COLOR )->name;
    }
#line 3799 "src-generated/ugbc.tab.c"
    break;

  case 34: /* random_definition_simple: WIDTH  */
#line 195 "src/ugbc.y"
            {
        (yyval.string) = random_width( _environment )->name;
    }
#line 3807 "src-generated/ugbc.tab.c"
    break;

  case 35: /* random_definition_simple: HEIGHT  */
#line 198 "src/ugbc.y"
             {
        (yyval.string) = random_height( _environment )->name;
    }
#line 3815 "src-generated/ugbc.tab.c"
    break;

  case 36: /* random_definition: random_definition_simple  */
#line 203 "src/ugbc.y"
                               {
          (yyval.string) = (yyvsp[0].string);
      }
#line 3823 "src-generated/ugbc.tab.c"
    break;

  case 37: /* color_enumeration: BLACK  */
#line 208 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLACK );
      }
#line 3832 "src-generated/ugbc.tab.c"
    break;

  case 38: /* color_enumeration: WHITE  */
#line 212 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color WHITE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_WHITE );
      }
#line 3841 "src-generated/ugbc.tab.c"
    break;

  case 39: /* color_enumeration: RED  */
#line 216 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLACK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_RED );
      }
#line 3850 "src-generated/ugbc.tab.c"
    break;

  case 40: /* color_enumeration: CYAN  */
#line 220 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color CYAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_CYAN );
      }
#line 3859 "src-generated/ugbc.tab.c"
    break;

  case 41: /* color_enumeration: VIOLET  */
#line 224 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color VIOLET)" )->name;
          variable_store( _environment, (yyval.string), COLOR_VIOLET );
      }
#line 3868 "src-generated/ugbc.tab.c"
    break;

  case 42: /* color_enumeration: GREEN  */
#line 228 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREEN );
      }
#line 3877 "src-generated/ugbc.tab.c"
    break;

  case 43: /* color_enumeration: BLUE  */
#line 232 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BLUE );
      }
#line 3886 "src-generated/ugbc.tab.c"
    break;

  case 44: /* color_enumeration: YELLOW  */
#line 236 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW );
      }
#line 3895 "src-generated/ugbc.tab.c"
    break;

  case 45: /* color_enumeration: ORANGE  */
#line 240 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color ORANGE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_ORANGE );
      }
#line 3904 "src-generated/ugbc.tab.c"
    break;

  case 46: /* color_enumeration: BROWN  */
#line 244 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color BROWN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_BROWN );
      }
#line 3913 "src-generated/ugbc.tab.c"
    break;

  case 47: /* color_enumeration: LIGHT RED  */
#line 248 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT RED)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_RED );
      }
#line 3922 "src-generated/ugbc.tab.c"
    break;

  case 48: /* color_enumeration: DARK GREY  */
#line 252 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_GREY );
      }
#line 3931 "src-generated/ugbc.tab.c"
    break;

  case 49: /* color_enumeration: GREY  */
#line 256 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GREY );
      }
#line 3940 "src-generated/ugbc.tab.c"
    break;

  case 50: /* color_enumeration: LIGHT GREEN  */
#line 260 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREEN );
      }
#line 3949 "src-generated/ugbc.tab.c"
    break;

  case 51: /* color_enumeration: LIGHT BLUE  */
#line 264 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_BLUE );
      }
#line 3958 "src-generated/ugbc.tab.c"
    break;

  case 52: /* color_enumeration: LIGHT GREY  */
#line 268 "src/ugbc.y"
                   {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LIGHT GREY)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LIGHT_GREY );
      }
#line 3967 "src-generated/ugbc.tab.c"
    break;

  case 53: /* color_enumeration: DARK BLUE  */
#line 272 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color DARK BLUE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_DARK_BLUE );
      }
#line 3976 "src-generated/ugbc.tab.c"
    break;

  case 54: /* color_enumeration: MAGENTA  */
#line 276 "src/ugbc.y"
                {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color MAGENTA)" )->name;
          variable_store( _environment, (yyval.string), COLOR_MAGENTA );
      }
#line 3985 "src-generated/ugbc.tab.c"
    break;

  case 55: /* color_enumeration: PURPLE  */
#line 280 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PURPLE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PURPLE );
      }
#line 3994 "src-generated/ugbc.tab.c"
    break;

  case 56: /* color_enumeration: LAVENDER  */
#line 284 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color LAVENDER)" )->name;
          variable_store( _environment, (yyval.string), COLOR_LAVENDER );
      }
#line 4003 "src-generated/ugbc.tab.c"
    break;

  case 57: /* color_enumeration: GOLD  */
#line 288 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color GOLD)" )->name;
          variable_store( _environment, (yyval.string), COLOR_GOLD );
      }
#line 4012 "src-generated/ugbc.tab.c"
    break;

  case 58: /* color_enumeration: TURQUOISE  */
#line 292 "src/ugbc.y"
                  {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TURQUOISE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TURQUOISE );
      }
#line 4021 "src-generated/ugbc.tab.c"
    break;

  case 59: /* color_enumeration: TAN  */
#line 296 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color TAN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_TAN );
      }
#line 4030 "src-generated/ugbc.tab.c"
    break;

  case 60: /* color_enumeration: YELLOW GREEN  */
#line 300 "src/ugbc.y"
                     {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color YELLOW GREEN)" )->name;
          variable_store( _environment, (yyval.string), COLOR_YELLOW_GREEN );
      }
#line 4039 "src-generated/ugbc.tab.c"
    break;

  case 61: /* color_enumeration: OLIVE GREEN  */
#line 304 "src/ugbc.y"
                    {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color OLIVE)" )->name;
          variable_store( _environment, (yyval.string), COLOR_OLIVE_GREEN );
      }
#line 4048 "src-generated/ugbc.tab.c"
    break;

  case 62: /* color_enumeration: PINK  */
#line 308 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PINK)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PINK );
      }
#line 4057 "src-generated/ugbc.tab.c"
    break;

  case 63: /* color_enumeration: PEACH  */
#line 312 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_COLOR, "(color PEACH)" )->name;
          variable_store( _environment, (yyval.string), COLOR_PEACH );
      }
#line 4066 "src-generated/ugbc.tab.c"
    break;

  case 64: /* key_scancode_alphadigit: "0"  */
#line 318 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 0)")->name;
        variable_store( _environment, (yyval.string), KEY_0 );
    }
#line 4075 "src-generated/ugbc.tab.c"
    break;

  case 65: /* key_scancode_alphadigit: "1"  */
#line 322 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 1)")->name;
        variable_store( _environment, (yyval.string), KEY_1 );
    }
#line 4084 "src-generated/ugbc.tab.c"
    break;

  case 66: /* key_scancode_alphadigit: "2"  */
#line 326 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 2)")->name;
        variable_store( _environment, (yyval.string), KEY_2 );
    }
#line 4093 "src-generated/ugbc.tab.c"
    break;

  case 67: /* key_scancode_alphadigit: "3"  */
#line 330 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 3)")->name;
        variable_store( _environment, (yyval.string), KEY_3 );
    }
#line 4102 "src-generated/ugbc.tab.c"
    break;

  case 68: /* key_scancode_alphadigit: "4"  */
#line 334 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 4)")->name;
        variable_store( _environment, (yyval.string), KEY_4 );
    }
#line 4111 "src-generated/ugbc.tab.c"
    break;

  case 69: /* key_scancode_alphadigit: "5"  */
#line 338 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 5)")->name;
        variable_store( _environment, (yyval.string), KEY_5 );
    }
#line 4120 "src-generated/ugbc.tab.c"
    break;

  case 70: /* key_scancode_alphadigit: "6"  */
#line 342 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 6)")->name;
        variable_store( _environment, (yyval.string), KEY_6 );
    }
#line 4129 "src-generated/ugbc.tab.c"
    break;

  case 71: /* key_scancode_alphadigit: "7"  */
#line 346 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 7)")->name;
        variable_store( _environment, (yyval.string), KEY_7 );
    }
#line 4138 "src-generated/ugbc.tab.c"
    break;

  case 72: /* key_scancode_alphadigit: "8"  */
#line 350 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 8)")->name;
        variable_store( _environment, (yyval.string), KEY_8 );
    }
#line 4147 "src-generated/ugbc.tab.c"
    break;

  case 73: /* key_scancode_alphadigit: "9"  */
#line 354 "src/ugbc.y"
          {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DIGIT 9)")->name;
        variable_store( _environment, (yyval.string), KEY_9 );
    }
#line 4156 "src-generated/ugbc.tab.c"
    break;

  case 74: /* key_scancode_alphadigit: A  */
#line 358 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER A)")->name;
        variable_store( _environment, (yyval.string), KEY_A );
    }
#line 4165 "src-generated/ugbc.tab.c"
    break;

  case 75: /* key_scancode_alphadigit: B  */
#line 362 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER B)")->name;
        variable_store( _environment, (yyval.string), KEY_B );
    }
#line 4174 "src-generated/ugbc.tab.c"
    break;

  case 76: /* key_scancode_alphadigit: C  */
#line 366 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER C)")->name;
        variable_store( _environment, (yyval.string), KEY_C );
    }
#line 4183 "src-generated/ugbc.tab.c"
    break;

  case 77: /* key_scancode_alphadigit: D  */
#line 370 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER D)")->name;
        variable_store( _environment, (yyval.string), KEY_D );
    }
#line 4192 "src-generated/ugbc.tab.c"
    break;

  case 78: /* key_scancode_alphadigit: E  */
#line 374 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER E)")->name;
        variable_store( _environment, (yyval.string), KEY_E );
    }
#line 4201 "src-generated/ugbc.tab.c"
    break;

  case 79: /* key_scancode_alphadigit: F  */
#line 378 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER F)")->name;
        variable_store( _environment, (yyval.string), KEY_F );
    }
#line 4210 "src-generated/ugbc.tab.c"
    break;

  case 80: /* key_scancode_alphadigit: G  */
#line 382 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER G)")->name;
        variable_store( _environment, (yyval.string), KEY_G );
    }
#line 4219 "src-generated/ugbc.tab.c"
    break;

  case 81: /* key_scancode_alphadigit: H  */
#line 386 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER H)")->name;
        variable_store( _environment, (yyval.string), KEY_H );
    }
#line 4228 "src-generated/ugbc.tab.c"
    break;

  case 82: /* key_scancode_alphadigit: I  */
#line 390 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER I)")->name;
        variable_store( _environment, (yyval.string), KEY_I );
    }
#line 4237 "src-generated/ugbc.tab.c"
    break;

  case 83: /* key_scancode_alphadigit: J  */
#line 394 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER J)")->name;
        variable_store( _environment, (yyval.string), KEY_J );
    }
#line 4246 "src-generated/ugbc.tab.c"
    break;

  case 84: /* key_scancode_alphadigit: K  */
#line 398 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER K)")->name;
        variable_store( _environment, (yyval.string), KEY_K );
    }
#line 4255 "src-generated/ugbc.tab.c"
    break;

  case 85: /* key_scancode_alphadigit: L  */
#line 402 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER L)")->name;
        variable_store( _environment, (yyval.string), KEY_L );
    }
#line 4264 "src-generated/ugbc.tab.c"
    break;

  case 86: /* key_scancode_alphadigit: M  */
#line 406 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER M)")->name;
        variable_store( _environment, (yyval.string), KEY_M );
    }
#line 4273 "src-generated/ugbc.tab.c"
    break;

  case 87: /* key_scancode_alphadigit: N  */
#line 410 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER N)")->name;
        variable_store( _environment, (yyval.string), KEY_N );
    }
#line 4282 "src-generated/ugbc.tab.c"
    break;

  case 88: /* key_scancode_alphadigit: O  */
#line 414 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER O)")->name;
        variable_store( _environment, (yyval.string), KEY_O );
    }
#line 4291 "src-generated/ugbc.tab.c"
    break;

  case 89: /* key_scancode_alphadigit: P  */
#line 418 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER P)")->name;
        variable_store( _environment, (yyval.string), KEY_P );
    }
#line 4300 "src-generated/ugbc.tab.c"
    break;

  case 90: /* key_scancode_alphadigit: Q  */
#line 422 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER Q)")->name;
        variable_store( _environment, (yyval.string), KEY_Q );
    }
#line 4309 "src-generated/ugbc.tab.c"
    break;

  case 91: /* key_scancode_alphadigit: R  */
#line 426 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER R)")->name;
        variable_store( _environment, (yyval.string), KEY_R );
    }
#line 4318 "src-generated/ugbc.tab.c"
    break;

  case 92: /* key_scancode_alphadigit: S  */
#line 430 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER S)")->name;
        variable_store( _environment, (yyval.string), KEY_S );
    }
#line 4327 "src-generated/ugbc.tab.c"
    break;

  case 93: /* key_scancode_alphadigit: T  */
#line 434 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER T)")->name;
        variable_store( _environment, (yyval.string), KEY_T );
    }
#line 4336 "src-generated/ugbc.tab.c"
    break;

  case 94: /* key_scancode_alphadigit: U  */
#line 438 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER U)")->name;
        variable_store( _environment, (yyval.string), KEY_U );
    }
#line 4345 "src-generated/ugbc.tab.c"
    break;

  case 95: /* key_scancode_alphadigit: V  */
#line 442 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER V)")->name;
        variable_store( _environment, (yyval.string), KEY_V );
    }
#line 4354 "src-generated/ugbc.tab.c"
    break;

  case 96: /* key_scancode_alphadigit: X  */
#line 446 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER X)")->name;
        variable_store( _environment, (yyval.string), KEY_X );
    }
#line 4363 "src-generated/ugbc.tab.c"
    break;

  case 97: /* key_scancode_alphadigit: Y  */
#line 450 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER Y)")->name;
        variable_store( _environment, (yyval.string), KEY_Y );
    }
#line 4372 "src-generated/ugbc.tab.c"
    break;

  case 98: /* key_scancode_alphadigit: W  */
#line 454 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER W)")->name;
        variable_store( _environment, (yyval.string), KEY_W );
    }
#line 4381 "src-generated/ugbc.tab.c"
    break;

  case 99: /* key_scancode_alphadigit: Z  */
#line 458 "src/ugbc.y"
        {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode LETTER Z)")->name;
        variable_store( _environment, (yyval.string), KEY_Z );
    }
#line 4390 "src-generated/ugbc.tab.c"
    break;

  case 100: /* key_scancode_function_digit: F1  */
#line 465 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F1)")->name;
        variable_store( _environment, (yyval.string), KEY_F1 );
    }
#line 4399 "src-generated/ugbc.tab.c"
    break;

  case 101: /* key_scancode_function_digit: F2  */
#line 469 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F2)")->name;
        variable_store( _environment, (yyval.string), KEY_F2 );
    }
#line 4408 "src-generated/ugbc.tab.c"
    break;

  case 102: /* key_scancode_function_digit: F3  */
#line 473 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F3)")->name;
        variable_store( _environment, (yyval.string), KEY_F3 );
    }
#line 4417 "src-generated/ugbc.tab.c"
    break;

  case 103: /* key_scancode_function_digit: F4  */
#line 477 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F4)")->name;
        variable_store( _environment, (yyval.string), KEY_F4 );
    }
#line 4426 "src-generated/ugbc.tab.c"
    break;

  case 104: /* key_scancode_function_digit: F5  */
#line 481 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F5)")->name;
        variable_store( _environment, (yyval.string), KEY_F5 );
    }
#line 4435 "src-generated/ugbc.tab.c"
    break;

  case 105: /* key_scancode_function_digit: F6  */
#line 485 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F6)")->name;
        variable_store( _environment, (yyval.string), KEY_F6 );
    }
#line 4444 "src-generated/ugbc.tab.c"
    break;

  case 106: /* key_scancode_function_digit: F7  */
#line 489 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F7)")->name;
        variable_store( _environment, (yyval.string), KEY_F7 );
    }
#line 4453 "src-generated/ugbc.tab.c"
    break;

  case 107: /* key_scancode_function_digit: F8  */
#line 493 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode F8)")->name;
        variable_store( _environment, (yyval.string), KEY_F8 );
    }
#line 4462 "src-generated/ugbc.tab.c"
    break;

  case 108: /* key_scancode_definition: NONE  */
#line 499 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode NONE)")->name;
        variable_store( _environment, (yyval.string), KEY_NONE );
    }
#line 4471 "src-generated/ugbc.tab.c"
    break;

  case 109: /* key_scancode_definition: key_scancode_alphadigit  */
#line 503 "src/ugbc.y"
                              {
        (yyval.string) = (yyvsp[0].string);
    }
#line 4479 "src-generated/ugbc.tab.c"
    break;

  case 110: /* key_scancode_definition: ASTERISK  */
#line 506 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode ASTERISK)")->name;
        variable_store( _environment, (yyval.string), KEY_ASTERISK );
    }
#line 4488 "src-generated/ugbc.tab.c"
    break;

  case 111: /* key_scancode_definition: AT  */
#line 510 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode AT)")->name;
        variable_store( _environment, (yyval.string), KEY_AT );
    }
#line 4497 "src-generated/ugbc.tab.c"
    break;

  case 112: /* key_scancode_definition: CLEAR  */
#line 514 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode CLEAR)")->name;
        variable_store( _environment, (yyval.string), KEY_CLEAR );
    }
#line 4506 "src-generated/ugbc.tab.c"
    break;

  case 113: /* key_scancode_definition: COLON  */
#line 518 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode COLON)")->name;
        variable_store( _environment, (yyval.string), KEY_COLON );
    }
#line 4515 "src-generated/ugbc.tab.c"
    break;

  case 114: /* key_scancode_definition: COMMA  */
#line 522 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode COMMA)")->name;
        variable_store( _environment, (yyval.string), KEY_COMMA );
    }
#line 4524 "src-generated/ugbc.tab.c"
    break;

  case 115: /* key_scancode_definition: COMMODORE  */
#line 526 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode COMMODORE)")->name;
        variable_store( _environment, (yyval.string), KEY_COMMODORE );
    }
#line 4533 "src-generated/ugbc.tab.c"
    break;

  case 116: /* key_scancode_definition: CONTROL  */
#line 530 "src/ugbc.y"
              {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode CONTROL)")->name;
        variable_store( _environment, (yyval.string), KEY_CONTROL );
    }
#line 4542 "src-generated/ugbc.tab.c"
    break;

  case 117: /* key_scancode_definition: CRSR LEFT RIGHT  */
#line 534 "src/ugbc.y"
                      {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode CRSR LEFT RIGHT)")->name;
        variable_store( _environment, (yyval.string), KEY_CRSR_LEFT_RIGHT );
    }
#line 4551 "src-generated/ugbc.tab.c"
    break;

  case 118: /* key_scancode_definition: CRSR UP DOWN  */
#line 538 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode CRSR UP DOWN)")->name;
        variable_store( _environment, (yyval.string), KEY_CRSR_UP_DOWN );
    }
#line 4560 "src-generated/ugbc.tab.c"
    break;

  case 119: /* key_scancode_definition: DELETE  */
#line 542 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode DELETE)")->name;
        variable_store( _environment, (yyval.string), KEY_DELETE );
    }
#line 4569 "src-generated/ugbc.tab.c"
    break;

  case 120: /* key_scancode_definition: EQUAL  */
#line 546 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode EQUAL)")->name;
        variable_store( _environment, (yyval.string), KEY_EQUAL );
    }
#line 4578 "src-generated/ugbc.tab.c"
    break;

  case 121: /* key_scancode_definition: key_scancode_function_digit  */
#line 550 "src/ugbc.y"
                                  {
        (yyval.string) = (yyvsp[0].string);
    }
#line 4586 "src-generated/ugbc.tab.c"
    break;

  case 122: /* key_scancode_definition: HOME  */
#line 553 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode HOME)")->name;
        variable_store( _environment, (yyval.string), KEY_HOME );
    }
#line 4595 "src-generated/ugbc.tab.c"
    break;

  case 123: /* key_scancode_definition: INSERT  */
#line 557 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode INSERT)")->name;
        variable_store( _environment, (yyval.string), KEY_INSERT );
    }
#line 4604 "src-generated/ugbc.tab.c"
    break;

  case 124: /* key_scancode_definition: ARROW LEFT  */
#line 561 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode ARROW LEFT)")->name;
        variable_store( _environment, (yyval.string), KEY_LEFT_ARROW );
    }
#line 4613 "src-generated/ugbc.tab.c"
    break;

  case 125: /* key_scancode_definition: LEFT ARROW  */
#line 565 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode ARROW LEFT)")->name;
        variable_store( _environment, (yyval.string), KEY_LEFT_ARROW );
    }
#line 4622 "src-generated/ugbc.tab.c"
    break;

  case 126: /* key_scancode_definition: ARROW UP  */
#line 569 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode ARROW UP)")->name;
        variable_store( _environment, (yyval.string), KEY_UP_ARROW );
    }
#line 4631 "src-generated/ugbc.tab.c"
    break;

  case 127: /* key_scancode_definition: UP ARROW  */
#line 573 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode ARROW UP)")->name;
        variable_store( _environment, (yyval.string), KEY_UP_ARROW );
    }
#line 4640 "src-generated/ugbc.tab.c"
    break;

  case 128: /* key_scancode_definition: MINUS  */
#line 577 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode MINUS)")->name;
        variable_store( _environment, (yyval.string), KEY_MINUS );
    }
#line 4649 "src-generated/ugbc.tab.c"
    break;

  case 129: /* key_scancode_definition: PERIOD  */
#line 581 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode PERIOD)")->name;
        variable_store( _environment, (yyval.string), KEY_PERIOD );
    }
#line 4658 "src-generated/ugbc.tab.c"
    break;

  case 130: /* key_scancode_definition: PLUS  */
#line 585 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode PLUS)")->name;
        variable_store( _environment, (yyval.string), KEY_PLUS );
    }
#line 4667 "src-generated/ugbc.tab.c"
    break;

  case 131: /* key_scancode_definition: POUND  */
#line 589 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode POUND)")->name;
        variable_store( _environment, (yyval.string), KEY_POUND );
    }
#line 4676 "src-generated/ugbc.tab.c"
    break;

  case 132: /* key_scancode_definition: RETURN  */
#line 593 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode RETURN)")->name;
        variable_store( _environment, (yyval.string), KEY_RETURN );
    }
#line 4685 "src-generated/ugbc.tab.c"
    break;

  case 133: /* key_scancode_definition: RUNSTOP  */
#line 597 "src/ugbc.y"
              {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode RUNSTOP)")->name;
        variable_store( _environment, (yyval.string), KEY_RUNSTOP );        
    }
#line 4694 "src-generated/ugbc.tab.c"
    break;

  case 134: /* key_scancode_definition: RUN STOP  */
#line 601 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode RUNSTOP)")->name;
        variable_store( _environment, (yyval.string), KEY_RUNSTOP );        
    }
#line 4703 "src-generated/ugbc.tab.c"
    break;

  case 135: /* key_scancode_definition: SEMICOLON  */
#line 605 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode SEMICOLON)")->name;
        variable_store( _environment, (yyval.string), KEY_SEMICOLON );
    }
#line 4712 "src-generated/ugbc.tab.c"
    break;

  case 136: /* key_scancode_definition: SLASH  */
#line 609 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode SLASH)")->name;
        variable_store( _environment, (yyval.string), KEY_SLASH );        
    }
#line 4721 "src-generated/ugbc.tab.c"
    break;

  case 137: /* key_scancode_definition: SPACE  */
#line 613 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(scancode SPACE)")->name;
        variable_store( _environment, (yyval.string), KEY_SPACE );        
    }
#line 4730 "src-generated/ugbc.tab.c"
    break;

  case 138: /* $@1: %empty  */
#line 619 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 4739 "src-generated/ugbc.tab.c"
    break;

  case 139: /* exponential: Identifier $@1 OP indexes CP  */
#line 623 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-4].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-4].string) )->name;
    }
#line 4751 "src-generated/ugbc.tab.c"
    break;

  case 140: /* $@2: %empty  */
#line 630 "src/ugbc.y"
                           {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
     }
#line 4760 "src-generated/ugbc.tab.c"
    break;

  case 141: /* exponential: Identifier OP_DOLLAR $@2 OP indexes CP  */
#line 634 "src/ugbc.y"
                    {
        Variable * array = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-5].string) );
        }
        (yyval.string) = variable_move_from_array( _environment, (yyvsp[-5].string) )->name;
    }
#line 4772 "src-generated/ugbc.tab.c"
    break;

  case 142: /* exponential: Identifier  */
#line 641 "src/ugbc.y"
                 {
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[0].string), VT_WORD, 0 )->name;
      }
#line 4780 "src-generated/ugbc.tab.c"
    break;

  case 143: /* exponential: Identifier OP_DOLLAR  */
#line 644 "src/ugbc.y"
                           { 
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_DSTRING, 0 )->name;
      }
#line 4788 "src-generated/ugbc.tab.c"
    break;

  case 144: /* exponential: Integer  */
#line 647 "src/ugbc.y"
              { 
        if ( (yyvsp[0].integer) < 0 ) {
            (yyval.string) = variable_temporary( _environment, VT_SWORD, "(signed integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        } else {
            (yyval.string) = variable_temporary( _environment, VT_WORD, "(integer value)" )->name;
            variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
        }
      }
#line 4802 "src-generated/ugbc.tab.c"
    break;

  case 145: /* exponential: OP_MINUS Integer  */
#line 656 "src/ugbc.y"
                       { 
        (yyval.string) = variable_temporary( _environment, VT_SWORD, "(negative integer value)" )->name;
        variable_store( _environment, (yyval.string), -(yyvsp[0].integer) );
      }
#line 4811 "src-generated/ugbc.tab.c"
    break;

  case 146: /* exponential: String  */
#line 660 "src/ugbc.y"
             { 
        outline1("; (expr string: \"%s\")", (yyvsp[0].string) );
        (yyval.string) = variable_temporary( _environment, VT_STRING, "(string value)" )->name;
        outline1("; %s", (yyval.string) );
        variable_store_string( _environment, (yyval.string), (yyvsp[0].string) );
        outline2("; variable stored: %s = %s", (yyval.string), (yyvsp[0].string) );
      }
#line 4823 "src-generated/ugbc.tab.c"
    break;

  case 147: /* exponential: OP BYTE CP Integer  */
#line 667 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4832 "src-generated/ugbc.tab.c"
    break;

  case 148: /* exponential: OP SIGNED BYTE CP Integer  */
#line 671 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_SBYTE, "(signed BYTE value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4841 "src-generated/ugbc.tab.c"
    break;

  case 149: /* exponential: OP WORD CP Integer  */
#line 675 "src/ugbc.y"
                         { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4850 "src-generated/ugbc.tab.c"
    break;

  case 150: /* exponential: OP SIGNED WORD CP Integer  */
#line 679 "src/ugbc.y"
                                { 
        (yyval.string) = variable_temporary( _environment, VT_WORD, "(signed WORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4859 "src-generated/ugbc.tab.c"
    break;

  case 151: /* exponential: OP DWORD CP Integer  */
#line 683 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4868 "src-generated/ugbc.tab.c"
    break;

  case 152: /* exponential: OP SIGNED DWORD CP Integer  */
#line 687 "src/ugbc.y"
                                 { 
        (yyval.string) = variable_temporary( _environment, VT_DWORD, "(DWORD value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4877 "src-generated/ugbc.tab.c"
    break;

  case 153: /* exponential: OP POSITION CP Integer  */
#line 691 "src/ugbc.y"
                             { 
        (yyval.string) = variable_temporary( _environment, VT_POSITION, "(POSITION value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4886 "src-generated/ugbc.tab.c"
    break;

  case 154: /* exponential: OP COLOR CP Integer  */
#line 695 "src/ugbc.y"
                          { 
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLOR value)" )->name;
        variable_store( _environment, (yyval.string), (yyvsp[0].integer) );
      }
#line 4895 "src-generated/ugbc.tab.c"
    break;

  case 155: /* exponential: color_enumeration  */
#line 699 "src/ugbc.y"
                        { 
        (yyval.string) = (yyvsp[0].string);
      }
#line 4903 "src-generated/ugbc.tab.c"
    break;

  case 156: /* exponential: PEEK OP expr CP  */
#line 702 "src/ugbc.y"
                      {
        (yyval.string) = peek_var( _environment, (yyvsp[-1].string) )->name;
      }
#line 4911 "src-generated/ugbc.tab.c"
    break;

  case 157: /* exponential: XPEN  */
#line 705 "src/ugbc.y"
           {
        (yyval.string) = xpen( _environment )->name;
      }
#line 4919 "src-generated/ugbc.tab.c"
    break;

  case 158: /* exponential: YPEN  */
#line 708 "src/ugbc.y"
           {
        (yyval.string) = ypen( _environment )->name;
      }
#line 4927 "src-generated/ugbc.tab.c"
    break;

  case 159: /* exponential: COLLISION OP direct_integer CP  */
#line 711 "src/ugbc.y"
                                     {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 4935 "src-generated/ugbc.tab.c"
    break;

  case 160: /* exponential: COLLISION OP expr CP  */
#line 714 "src/ugbc.y"
                           {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 4943 "src-generated/ugbc.tab.c"
    break;

  case 161: /* exponential: HIT OP direct_integer CP  */
#line 717 "src/ugbc.y"
                               {
        (yyval.string) = collision_to( _environment, (yyvsp[-1].integer) )->name;
      }
#line 4951 "src-generated/ugbc.tab.c"
    break;

  case 162: /* exponential: HIT OP expr CP  */
#line 720 "src/ugbc.y"
                     {
        (yyval.string) = collision_to_vars( _environment, (yyvsp[-1].string) )->name;
      }
#line 4959 "src-generated/ugbc.tab.c"
    break;

  case 163: /* exponential: LEFT OP expr OP_COMMA expr CP  */
#line 723 "src/ugbc.y"
                                    {
        (yyval.string) = variable_string_left( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4967 "src-generated/ugbc.tab.c"
    break;

  case 164: /* exponential: RIGHT OP expr OP_COMMA expr CP  */
#line 726 "src/ugbc.y"
                                     {
        (yyval.string) = variable_string_right( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4975 "src-generated/ugbc.tab.c"
    break;

  case 165: /* exponential: MID OP expr OP_COMMA expr CP  */
#line 729 "src/ugbc.y"
                                   {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 4983 "src-generated/ugbc.tab.c"
    break;

  case 166: /* exponential: MID OP expr OP_COMMA expr OP_COMMA expr CP  */
#line 732 "src/ugbc.y"
                                                 {
        (yyval.string) = variable_string_mid( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 4991 "src-generated/ugbc.tab.c"
    break;

  case 167: /* exponential: INSTR OP expr OP_COMMA expr CP  */
#line 735 "src/ugbc.y"
                                     {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-3].string), (yyvsp[-1].string), NULL )->name;
    }
#line 4999 "src-generated/ugbc.tab.c"
    break;

  case 168: /* exponential: INSTR OP expr OP_COMMA expr OP_COMMA expr CP  */
#line 738 "src/ugbc.y"
                                                   {
        (yyval.string) = variable_string_instr( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5007 "src-generated/ugbc.tab.c"
    break;

  case 169: /* exponential: UPPER OP expr CP  */
#line 741 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_upper( _environment, (yyvsp[-1].string) )->name;
    }
#line 5015 "src-generated/ugbc.tab.c"
    break;

  case 170: /* exponential: LOWER OP expr CP  */
#line 744 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_lower( _environment, (yyvsp[-1].string) )->name;
    }
#line 5023 "src-generated/ugbc.tab.c"
    break;

  case 171: /* exponential: STR OP expr CP  */
#line 747 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_str( _environment, (yyvsp[-1].string) )->name;
    }
#line 5031 "src-generated/ugbc.tab.c"
    break;

  case 172: /* exponential: BIN OP expr CP  */
#line 750 "src/ugbc.y"
                     {
        (yyval.string) = variable_bin( _environment, (yyvsp[-1].string), NULL )->name;
    }
#line 5039 "src-generated/ugbc.tab.c"
    break;

  case 173: /* exponential: BIN OP expr OP_COMMA expr CP  */
#line 753 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bin( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5047 "src-generated/ugbc.tab.c"
    break;

  case 174: /* exponential: SPACE OP expr CP  */
#line 756 "src/ugbc.y"
                       {
        (yyval.string) = variable_string_space( _environment, (yyvsp[-1].string) )->name;
    }
#line 5055 "src-generated/ugbc.tab.c"
    break;

  case 175: /* exponential: FLIP OP expr CP  */
#line 759 "src/ugbc.y"
                      {
        (yyval.string) = variable_string_flip( _environment, (yyvsp[-1].string) )->name;
    }
#line 5063 "src-generated/ugbc.tab.c"
    break;

  case 176: /* exponential: CHR OP expr CP  */
#line 762 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_chr( _environment, (yyvsp[-1].string) )->name;
    }
#line 5071 "src-generated/ugbc.tab.c"
    break;

  case 177: /* exponential: ASC OP expr CP  */
#line 765 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_asc( _environment, (yyvsp[-1].string) )->name;
    }
#line 5079 "src-generated/ugbc.tab.c"
    break;

  case 178: /* exponential: LEN OP expr CP  */
#line 768 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_len( _environment, (yyvsp[-1].string) )->name;
    }
#line 5087 "src-generated/ugbc.tab.c"
    break;

  case 179: /* exponential: STRING OP expr OP_COMMA expr CP  */
#line 771 "src/ugbc.y"
                                      {
        (yyval.string) = variable_string_string( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5095 "src-generated/ugbc.tab.c"
    break;

  case 180: /* exponential: VAL OP expr CP  */
#line 774 "src/ugbc.y"
                     {
        (yyval.string) = variable_string_val( _environment, (yyvsp[-1].string) )->name;
    }
#line 5103 "src-generated/ugbc.tab.c"
    break;

  case 181: /* exponential: RANDOM random_definition  */
#line 777 "src/ugbc.y"
                               {
        (yyval.string) = (yyvsp[0].string);
    }
#line 5111 "src-generated/ugbc.tab.c"
    break;

  case 182: /* exponential: RND OP expr CP  */
#line 780 "src/ugbc.y"
                     {
        (yyval.string) = rnd( _environment, (yyvsp[-1].string) )->name;
    }
#line 5119 "src-generated/ugbc.tab.c"
    break;

  case 183: /* exponential: OP expr CP  */
#line 783 "src/ugbc.y"
                 {
        (yyval.string) = (yyvsp[-1].string);
    }
#line 5127 "src-generated/ugbc.tab.c"
    break;

  case 184: /* exponential: FREE  */
#line 786 "src/ugbc.y"
           {
        cpu_dsgc( _environment );
        (yyval.string) = variable_retrieve( _environment, "FREE_STRING" )->name;
    }
#line 5136 "src-generated/ugbc.tab.c"
    break;

  case 185: /* exponential: MAX OP expr OP_COMMA expr CP  */
#line 790 "src/ugbc.y"
                                   {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5144 "src-generated/ugbc.tab.c"
    break;

  case 186: /* exponential: MIN OP expr OP_COMMA expr CP  */
#line 793 "src/ugbc.y"
                                   {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5152 "src-generated/ugbc.tab.c"
    break;

  case 187: /* exponential: PARAM OP Identifier CP  */
#line 796 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 5160 "src-generated/ugbc.tab.c"
    break;

  case 188: /* exponential: PARAM OP_DOLLAR OP Identifier CP  */
#line 799 "src/ugbc.y"
                                       {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 5168 "src-generated/ugbc.tab.c"
    break;

  case 189: /* $@3: %empty  */
#line 802 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5176 "src-generated/ugbc.tab.c"
    break;

  case 190: /* exponential: Identifier OSP $@3 values CSP  */
#line 804 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 5185 "src-generated/ugbc.tab.c"
    break;

  case 191: /* exponential: SGN OP expr CP  */
#line 808 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 5193 "src-generated/ugbc.tab.c"
    break;

  case 192: /* exponential: ABS OP expr CP  */
#line 811 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 5201 "src-generated/ugbc.tab.c"
    break;

  case 193: /* exponential: TRUE  */
#line 814 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 5210 "src-generated/ugbc.tab.c"
    break;

  case 194: /* exponential: FALSE  */
#line 818 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 0 );
    }
#line 5219 "src-generated/ugbc.tab.c"
    break;

  case 195: /* exponential: COLORS  */
#line 822 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 5228 "src-generated/ugbc.tab.c"
    break;

  case 196: /* exponential: PEN COLORS  */
#line 826 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 5237 "src-generated/ugbc.tab.c"
    break;

  case 197: /* exponential: PEN DEFAULT  */
#line 830 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 5246 "src-generated/ugbc.tab.c"
    break;

  case 198: /* exponential: DEFAULT PEN  */
#line 834 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 5255 "src-generated/ugbc.tab.c"
    break;

  case 199: /* exponential: PAPER COLORS  */
#line 838 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 5264 "src-generated/ugbc.tab.c"
    break;

  case 200: /* exponential: PAPER DEFAULT  */
#line 842 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 5273 "src-generated/ugbc.tab.c"
    break;

  case 201: /* exponential: DEFAULT PAPER  */
#line 846 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 5282 "src-generated/ugbc.tab.c"
    break;

  case 202: /* exponential: WIDTH  */
#line 850 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 5290 "src-generated/ugbc.tab.c"
    break;

  case 203: /* exponential: HEIGHT  */
#line 853 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 5298 "src-generated/ugbc.tab.c"
    break;

  case 204: /* exponential: TIMER  */
#line 856 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 5306 "src-generated/ugbc.tab.c"
    break;

  case 205: /* exponential: PEN OP_DOLLAR OP expr CP  */
#line 859 "src/ugbc.y"
                               {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 5314 "src-generated/ugbc.tab.c"
    break;

  case 206: /* exponential: PAPER OP_DOLLAR OP expr CP  */
#line 862 "src/ugbc.y"
                                 {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 5322 "src-generated/ugbc.tab.c"
    break;

  case 207: /* exponential: CMOVE OP_DOLLAR OP expr OP_COMMA expr CP  */
#line 865 "src/ugbc.y"
                                               {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5330 "src-generated/ugbc.tab.c"
    break;

  case 208: /* exponential: CUP OP_DOLLAR  */
#line 868 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 5338 "src-generated/ugbc.tab.c"
    break;

  case 209: /* exponential: CDOWN OP_DOLLAR  */
#line 871 "src/ugbc.y"
                      {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 5346 "src-generated/ugbc.tab.c"
    break;

  case 210: /* exponential: CLEFT OP_DOLLAR  */
#line 874 "src/ugbc.y"
                      {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 5354 "src-generated/ugbc.tab.c"
    break;

  case 211: /* exponential: CRIGHT OP_DOLLAR  */
#line 877 "src/ugbc.y"
                       {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 5362 "src-generated/ugbc.tab.c"
    break;

  case 212: /* exponential: AT OP_DOLLAR OP expr OP_COMMA expr CP  */
#line 880 "src/ugbc.y"
                                            {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5370 "src-generated/ugbc.tab.c"
    break;

  case 213: /* exponential: LOCATE OP_DOLLAR OP expr OP_COMMA expr CP  */
#line 883 "src/ugbc.y"
                                                {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5378 "src-generated/ugbc.tab.c"
    break;

  case 214: /* exponential: TAB OP_DOLLAR  */
#line 886 "src/ugbc.y"
                    {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 5386 "src-generated/ugbc.tab.c"
    break;

  case 215: /* exponential: XCURS  */
#line 889 "src/ugbc.y"
            {
        (yyval.string) = text_get_xcurs( _environment )->name;
    }
#line 5394 "src-generated/ugbc.tab.c"
    break;

  case 216: /* exponential: YCURS  */
#line 892 "src/ugbc.y"
            {
        (yyval.string) = text_get_ycurs( _environment )->name;
    }
#line 5402 "src-generated/ugbc.tab.c"
    break;

  case 217: /* exponential: TEXTADDRESS  */
#line 895 "src/ugbc.y"
                  {
        (yyval.string) = strdup( "TEXTADDRESS" );
    }
#line 5410 "src-generated/ugbc.tab.c"
    break;

  case 218: /* exponential: JOY OP expr CP  */
#line 898 "src/ugbc.y"
                     {
        (yyval.string) = joy( _environment, (yyvsp[-1].string) )->name;
    }
#line 5418 "src-generated/ugbc.tab.c"
    break;

  case 219: /* exponential: JUP OP expr CP  */
#line 901 "src/ugbc.y"
                     {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_UP )->name;
    }
#line 5426 "src-generated/ugbc.tab.c"
    break;

  case 220: /* exponential: JDOWN OP expr CP  */
#line 904 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_DOWN )->name;
    }
#line 5434 "src-generated/ugbc.tab.c"
    break;

  case 221: /* exponential: JLEFT OP expr CP  */
#line 907 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_LEFT )->name;
    }
#line 5442 "src-generated/ugbc.tab.c"
    break;

  case 222: /* exponential: JRIGHT OP expr CP  */
#line 910 "src/ugbc.y"
                        {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_RIGHT )->name;
    }
#line 5450 "src-generated/ugbc.tab.c"
    break;

  case 223: /* exponential: JFIRE OP expr CP  */
#line 913 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_FIRE )->name;
    }
#line 5458 "src-generated/ugbc.tab.c"
    break;

  case 224: /* exponential: FIRE OP expr CP  */
#line 916 "src/ugbc.y"
                      {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_FIRE )->name;
    }
#line 5466 "src-generated/ugbc.tab.c"
    break;

  case 225: /* exponential: JOY COUNT  */
#line 919 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, (yyval.string), JOY_COUNT );
    }
#line 5475 "src-generated/ugbc.tab.c"
    break;

  case 226: /* exponential: JOYCOUNT  */
#line 923 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, (yyval.string), JOY_COUNT );
    }
#line 5484 "src-generated/ugbc.tab.c"
    break;

  case 227: /* exponential: BIT OP expr OP_COMMA expr CP  */
#line 927 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5492 "src-generated/ugbc.tab.c"
    break;

  case 228: /* exponential: UP  */
#line 930 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(UP)" )->name;
        variable_store( _environment, (yyval.string), JOY_UP );
    }
#line 5501 "src-generated/ugbc.tab.c"
    break;

  case 229: /* exponential: DOWN  */
#line 934 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(DOWN)" )->name;
        variable_store( _environment, (yyval.string), JOY_DOWN );
    }
#line 5510 "src-generated/ugbc.tab.c"
    break;

  case 230: /* exponential: LEFT  */
#line 938 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(LEFT)" )->name;
        variable_store( _environment, (yyval.string), JOY_LEFT );
    }
#line 5519 "src-generated/ugbc.tab.c"
    break;

  case 231: /* exponential: RIGHT  */
#line 942 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(RIGHT)" )->name;
        variable_store( _environment, (yyval.string), JOY_RIGHT );
    }
#line 5528 "src-generated/ugbc.tab.c"
    break;

  case 232: /* exponential: FIRE  */
#line 946 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(FIRE)" )->name;
        variable_store( _environment, (yyval.string), JOY_FIRE );
    }
#line 5537 "src-generated/ugbc.tab.c"
    break;

  case 233: /* exponential: INPUT OP_DOLLAR OP expr CP  */
#line 950 "src/ugbc.y"
                                 {
        (yyval.string) = input_string( _environment, (yyvsp[-1].string) )->name;
    }
#line 5545 "src-generated/ugbc.tab.c"
    break;

  case 234: /* exponential: INKEY  */
#line 953 "src/ugbc.y"
            {
        (yyval.string) = inkey( _environment )->name;
    }
#line 5553 "src-generated/ugbc.tab.c"
    break;

  case 235: /* exponential: SCANCODE  */
#line 956 "src/ugbc.y"
               {
        (yyval.string) = scancode( _environment )->name;
    }
#line 5561 "src-generated/ugbc.tab.c"
    break;

  case 236: /* exponential: SCAN CODE  */
#line 959 "src/ugbc.y"
                {
        (yyval.string) = scancode( _environment )->name;
    }
#line 5569 "src-generated/ugbc.tab.c"
    break;

  case 237: /* exponential: KEY STATE OP expr CP  */
#line 962 "src/ugbc.y"
                           {
        (yyval.string) = key_state( _environment, (yyvsp[-1].string) )->name;
    }
#line 5577 "src-generated/ugbc.tab.c"
    break;

  case 238: /* exponential: KEYSTATE OP expr CP  */
#line 965 "src/ugbc.y"
                          {
        (yyval.string) = key_state( _environment, (yyvsp[-1].string) )->name;
    }
#line 5585 "src-generated/ugbc.tab.c"
    break;

  case 239: /* exponential: SCANSHIFT  */
#line 968 "src/ugbc.y"
                {
        (yyval.string) = scanshift( _environment )->name;
    }
#line 5593 "src-generated/ugbc.tab.c"
    break;

  case 240: /* exponential: SCAN SHIFT  */
#line 971 "src/ugbc.y"
                 {
        (yyval.string) = scanshift( _environment )->name;
    }
#line 5601 "src-generated/ugbc.tab.c"
    break;

  case 241: /* exponential: KEYSHIFT  */
#line 974 "src/ugbc.y"
               {
        (yyval.string) = keyshift( _environment )->name;
    }
#line 5609 "src-generated/ugbc.tab.c"
    break;

  case 242: /* exponential: KEY SHIFT  */
#line 977 "src/ugbc.y"
                {
        (yyval.string) = keyshift( _environment )->name;
    }
#line 5617 "src-generated/ugbc.tab.c"
    break;

  case 243: /* exponential: LEFT SHIFT  */
#line 980 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_LEFT );
    }
#line 5626 "src-generated/ugbc.tab.c"
    break;

  case 244: /* exponential: SHIFT LEFT  */
#line 984 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_LEFT );
    }
#line 5635 "src-generated/ugbc.tab.c"
    break;

  case 245: /* exponential: RIGHT SHIFT  */
#line 988 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_RIGHT );
    }
#line 5644 "src-generated/ugbc.tab.c"
    break;

  case 246: /* exponential: SHIFT RIGHT  */
#line 992 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_RIGHT );
    }
#line 5653 "src-generated/ugbc.tab.c"
    break;

  case 247: /* exponential: CAPSLOCK  */
#line 996 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT CAPSLOCK)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_CAPSLOCK );
    }
#line 5662 "src-generated/ugbc.tab.c"
    break;

  case 248: /* exponential: CAPS LOCK  */
#line 1000 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT CAPSLOCK)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_CAPSLOCK );
    }
#line 5671 "src-generated/ugbc.tab.c"
    break;

  case 249: /* exponential: CONTROL  */
#line 1004 "src/ugbc.y"
              {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT CONTROL)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_CONTROL );
    }
#line 5680 "src-generated/ugbc.tab.c"
    break;

  case 250: /* exponential: LEFT ALT  */
#line 1008 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT ALT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_LEFT_ALT );
    }
#line 5689 "src-generated/ugbc.tab.c"
    break;

  case 251: /* exponential: ALT LEFT  */
#line 1012 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT ALT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_LEFT_ALT );
    }
#line 5698 "src-generated/ugbc.tab.c"
    break;

  case 252: /* exponential: RIGHT ALT  */
#line 1016 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT ALT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_RIGHT_ALT );
    }
#line 5707 "src-generated/ugbc.tab.c"
    break;

  case 253: /* exponential: ALT RIGHT  */
#line 1020 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT ALT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_RIGHT_ALT );
    }
#line 5716 "src-generated/ugbc.tab.c"
    break;

  case 254: /* exponential: KEY key_scancode_definition  */
#line 1024 "src/ugbc.y"
                                  {
        (yyval.string) = (yyvsp[0].string);
    }
#line 5724 "src-generated/ugbc.tab.c"
    break;

  case 257: /* bank_definition_simple: AT direct_integer  */
#line 1032 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 5732 "src-generated/ugbc.tab.c"
    break;

  case 258: /* bank_definition_simple: Identifier AT direct_integer  */
#line 1035 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 5740 "src-generated/ugbc.tab.c"
    break;

  case 259: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 1038 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 5748 "src-generated/ugbc.tab.c"
    break;

  case 260: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 1041 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 5756 "src-generated/ugbc.tab.c"
    break;

  case 261: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 1044 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 5764 "src-generated/ugbc.tab.c"
    break;

  case 262: /* bank_definition_simple: DATA AT direct_integer  */
#line 1047 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 5772 "src-generated/ugbc.tab.c"
    break;

  case 263: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 1051 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 5780 "src-generated/ugbc.tab.c"
    break;

  case 264: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 1054 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 5788 "src-generated/ugbc.tab.c"
    break;

  case 265: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 1057 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 5796 "src-generated/ugbc.tab.c"
    break;

  case 266: /* bank_definition_simple: CODE AT direct_integer  */
#line 1060 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 5804 "src-generated/ugbc.tab.c"
    break;

  case 267: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 1064 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 5812 "src-generated/ugbc.tab.c"
    break;

  case 268: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 1067 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 5820 "src-generated/ugbc.tab.c"
    break;

  case 269: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 1070 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 5828 "src-generated/ugbc.tab.c"
    break;

  case 270: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 1073 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 5836 "src-generated/ugbc.tab.c"
    break;

  case 271: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 1077 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 5844 "src-generated/ugbc.tab.c"
    break;

  case 272: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 1080 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 5852 "src-generated/ugbc.tab.c"
    break;

  case 273: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 1083 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 5860 "src-generated/ugbc.tab.c"
    break;

  case 274: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 1086 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 5868 "src-generated/ugbc.tab.c"
    break;

  case 275: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 1092 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 5876 "src-generated/ugbc.tab.c"
    break;

  case 276: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 1095 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 5884 "src-generated/ugbc.tab.c"
    break;

  case 277: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 1098 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 5892 "src-generated/ugbc.tab.c"
    break;

  case 278: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 1101 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 5900 "src-generated/ugbc.tab.c"
    break;

  case 279: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 1104 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 5908 "src-generated/ugbc.tab.c"
    break;

  case 282: /* raster_definition_simple: Identifier AT direct_integer  */
#line 1113 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 5916 "src-generated/ugbc.tab.c"
    break;

  case 283: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 1116 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 5924 "src-generated/ugbc.tab.c"
    break;

  case 284: /* raster_definition_expression: Identifier AT expr  */
#line 1121 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5932 "src-generated/ugbc.tab.c"
    break;

  case 285: /* raster_definition_expression: AT expr WITH Identifier  */
#line 1124 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5940 "src-generated/ugbc.tab.c"
    break;

  case 288: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 1133 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 5948 "src-generated/ugbc.tab.c"
    break;

  case 289: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 1136 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 5956 "src-generated/ugbc.tab.c"
    break;

  case 290: /* next_raster_definition_expression: Identifier AT expr  */
#line 1141 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 5964 "src-generated/ugbc.tab.c"
    break;

  case 291: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 1144 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5972 "src-generated/ugbc.tab.c"
    break;

  case 294: /* color_definition_simple: BORDER direct_integer  */
#line 1153 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 5980 "src-generated/ugbc.tab.c"
    break;

  case 295: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 1156 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 5988 "src-generated/ugbc.tab.c"
    break;

  case 296: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 1159 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 5996 "src-generated/ugbc.tab.c"
    break;

  case 297: /* color_definition_expression: BORDER expr  */
#line 1164 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 6004 "src-generated/ugbc.tab.c"
    break;

  case 298: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 1167 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 6012 "src-generated/ugbc.tab.c"
    break;

  case 299: /* color_definition_expression: SPRITE expr TO expr  */
#line 1170 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 6020 "src-generated/ugbc.tab.c"
    break;

  case 305: /* wait_definition_simple: direct_integer CYCLES  */
#line 1184 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 6028 "src-generated/ugbc.tab.c"
    break;

  case 306: /* wait_definition_simple: direct_integer TICKS  */
#line 1187 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 6036 "src-generated/ugbc.tab.c"
    break;

  case 307: /* wait_definition_simple: direct_integer milliseconds  */
#line 1190 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 6044 "src-generated/ugbc.tab.c"
    break;

  case 308: /* wait_definition_simple: KEY  */
#line 1193 "src/ugbc.y"
          {
      wait_key( _environment );
    }
#line 6052 "src-generated/ugbc.tab.c"
    break;

  case 309: /* wait_definition_expression: expr CYCLES  */
#line 1199 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 6060 "src-generated/ugbc.tab.c"
    break;

  case 310: /* wait_definition_expression: expr TICKS  */
#line 1202 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 6068 "src-generated/ugbc.tab.c"
    break;

  case 311: /* wait_definition_expression: expr milliseconds  */
#line 1205 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 6076 "src-generated/ugbc.tab.c"
    break;

  case 314: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 1215 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 6084 "src-generated/ugbc.tab.c"
    break;

  case 315: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 1218 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 6092 "src-generated/ugbc.tab.c"
    break;

  case 316: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 1221 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 6100 "src-generated/ugbc.tab.c"
    break;

  case 317: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 1224 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 6108 "src-generated/ugbc.tab.c"
    break;

  case 318: /* sprite_definition_simple: direct_integer position OP direct_integer OP_COMMA direct_integer CP  */
#line 1227 "src/ugbc.y"
                                                                         {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 6116 "src-generated/ugbc.tab.c"
    break;

  case 319: /* sprite_definition_simple: direct_integer ENABLE  */
#line 1230 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 6124 "src-generated/ugbc.tab.c"
    break;

  case 320: /* sprite_definition_simple: direct_integer DISABLE  */
#line 1233 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 6132 "src-generated/ugbc.tab.c"
    break;

  case 321: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 1236 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 6140 "src-generated/ugbc.tab.c"
    break;

  case 322: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 1239 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 6148 "src-generated/ugbc.tab.c"
    break;

  case 323: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 1242 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 6156 "src-generated/ugbc.tab.c"
    break;

  case 324: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 1245 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 6164 "src-generated/ugbc.tab.c"
    break;

  case 325: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 1248 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 6172 "src-generated/ugbc.tab.c"
    break;

  case 326: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 1251 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 6180 "src-generated/ugbc.tab.c"
    break;

  case 327: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 1254 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 6188 "src-generated/ugbc.tab.c"
    break;

  case 328: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 1257 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 6196 "src-generated/ugbc.tab.c"
    break;

  case 329: /* sprite_definition_expression: expr DATA FROM expr  */
#line 1262 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6204 "src-generated/ugbc.tab.c"
    break;

  case 330: /* sprite_definition_expression: expr MULTICOLOR  */
#line 1265 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 6212 "src-generated/ugbc.tab.c"
    break;

  case 331: /* sprite_definition_expression: expr MONOCOLOR  */
#line 1268 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 6220 "src-generated/ugbc.tab.c"
    break;

  case 332: /* sprite_definition_expression: expr COLOR expr  */
#line 1271 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 6228 "src-generated/ugbc.tab.c"
    break;

  case 333: /* sprite_definition_expression: expr position OP expr OP_COMMA expr CP  */
#line 1274 "src/ugbc.y"
                                           {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 6236 "src-generated/ugbc.tab.c"
    break;

  case 334: /* sprite_definition_expression: expr ENABLE  */
#line 1277 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 6244 "src-generated/ugbc.tab.c"
    break;

  case 335: /* sprite_definition_expression: expr DISABLE  */
#line 1280 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 6252 "src-generated/ugbc.tab.c"
    break;

  case 336: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 1283 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 6260 "src-generated/ugbc.tab.c"
    break;

  case 337: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 1286 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 6268 "src-generated/ugbc.tab.c"
    break;

  case 338: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 1289 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 6276 "src-generated/ugbc.tab.c"
    break;

  case 339: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 1292 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 6284 "src-generated/ugbc.tab.c"
    break;

  case 340: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 1295 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 6292 "src-generated/ugbc.tab.c"
    break;

  case 341: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 1298 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 6300 "src-generated/ugbc.tab.c"
    break;

  case 342: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 1301 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 6308 "src-generated/ugbc.tab.c"
    break;

  case 343: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 1304 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 6316 "src-generated/ugbc.tab.c"
    break;

  case 346: /* bitmap_definition_simple: AT direct_integer  */
#line 1313 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 6324 "src-generated/ugbc.tab.c"
    break;

  case 347: /* bitmap_definition_simple: ENABLE  */
#line 1316 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 6332 "src-generated/ugbc.tab.c"
    break;

  case 348: /* bitmap_definition_simple: DISABLE  */
#line 1319 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 6340 "src-generated/ugbc.tab.c"
    break;

  case 349: /* bitmap_definition_simple: CLEAR  */
#line 1322 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 6348 "src-generated/ugbc.tab.c"
    break;

  case 350: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 1325 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 6356 "src-generated/ugbc.tab.c"
    break;

  case 351: /* bitmap_definition_expression: AT expr  */
#line 1331 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 6364 "src-generated/ugbc.tab.c"
    break;

  case 352: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 1334 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 6372 "src-generated/ugbc.tab.c"
    break;

  case 355: /* textmap_definition_simple: AT direct_integer  */
#line 1344 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 6380 "src-generated/ugbc.tab.c"
    break;

  case 356: /* textmap_definition_expression: AT expr  */
#line 1349 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 6388 "src-generated/ugbc.tab.c"
    break;

  case 359: /* text_definition_simple: ENABLE  */
#line 1358 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 6396 "src-generated/ugbc.tab.c"
    break;

  case 360: /* text_definition_simple: DISABLE  */
#line 1361 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 6404 "src-generated/ugbc.tab.c"
    break;

  case 361: /* text_definition_expression: AT expr OP_COMMA expr OP_COMMA expr  */
#line 1366 "src/ugbc.y"
                                         {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 6412 "src-generated/ugbc.tab.c"
    break;

  case 362: /* text_definition_expression: expr OP_COMMA expr OP_COMMA expr  */
#line 1369 "src/ugbc.y"
                                      {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 6420 "src-generated/ugbc.tab.c"
    break;

  case 365: /* tiles_definition_simple: AT direct_integer  */
#line 1378 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 6428 "src-generated/ugbc.tab.c"
    break;

  case 366: /* tiles_definition_expression: AT expr  */
#line 1383 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 6436 "src-generated/ugbc.tab.c"
    break;

  case 369: /* colormap_definition_simple: AT direct_integer  */
#line 1392 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 6444 "src-generated/ugbc.tab.c"
    break;

  case 370: /* colormap_definition_simple: CLEAR  */
#line 1395 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 6452 "src-generated/ugbc.tab.c"
    break;

  case 371: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 1398 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 6460 "src-generated/ugbc.tab.c"
    break;

  case 372: /* colormap_definition_expression: AT expr  */
#line 1403 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 6468 "src-generated/ugbc.tab.c"
    break;

  case 373: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 1406 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 6476 "src-generated/ugbc.tab.c"
    break;

  case 376: /* screen_definition_simple: ON  */
#line 1416 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 6484 "src-generated/ugbc.tab.c"
    break;

  case 377: /* screen_definition_simple: OFF  */
#line 1419 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 6492 "src-generated/ugbc.tab.c"
    break;

  case 378: /* screen_definition_simple: ROWS direct_integer  */
#line 1422 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 6500 "src-generated/ugbc.tab.c"
    break;

  case 379: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 1425 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 6508 "src-generated/ugbc.tab.c"
    break;

  case 380: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 1428 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 6516 "src-generated/ugbc.tab.c"
    break;

  case 381: /* screen_definition_expression: ROWS expr  */
#line 1433 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 6524 "src-generated/ugbc.tab.c"
    break;

  case 382: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 1436 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 6532 "src-generated/ugbc.tab.c"
    break;

  case 383: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 1439 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 6540 "src-generated/ugbc.tab.c"
    break;

  case 387: /* var_definition_simple: Identifier ON Identifier  */
#line 1448 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 6548 "src-generated/ugbc.tab.c"
    break;

  case 388: /* var_definition_simple: Identifier OP_DOLLAR ON Identifier  */
#line 1451 "src/ugbc.y"
                                       {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_DSTRING, 0 );
  }
#line 6556 "src-generated/ugbc.tab.c"
    break;

  case 389: /* var_definition_simple: Identifier ON Identifier OP_ASSIGN direct_integer  */
#line 1454 "src/ugbc.y"
                                                      {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 6564 "src-generated/ugbc.tab.c"
    break;

  case 390: /* var_definition_simple: Identifier ON Identifier OP_ASSIGN expr  */
#line 1457 "src/ugbc.y"
                                            {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 6574 "src-generated/ugbc.tab.c"
    break;

  case 391: /* var_definition_simple: Identifier OP_DOLLAR ON Identifier OP_ASSIGN expr  */
#line 1462 "src/ugbc.y"
                                                      {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_DSTRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 6584 "src-generated/ugbc.tab.c"
    break;

  case 392: /* goto_definition: Identifier  */
#line 1469 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 6592 "src-generated/ugbc.tab.c"
    break;

  case 393: /* goto_definition: Integer  */
#line 1472 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 6600 "src-generated/ugbc.tab.c"
    break;

  case 394: /* gosub_definition: Identifier  */
#line 1478 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 6608 "src-generated/ugbc.tab.c"
    break;

  case 395: /* gosub_definition: Integer  */
#line 1481 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 6616 "src-generated/ugbc.tab.c"
    break;

  case 397: /* point_definition_simple: AT OP direct_integer OP_COMMA direct_integer CP  */
#line 1490 "src/ugbc.y"
                                                      {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 6624 "src-generated/ugbc.tab.c"
    break;

  case 398: /* point_definition_expression: AT OP expr OP_COMMA expr CP  */
#line 1496 "src/ugbc.y"
                                  {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 6632 "src-generated/ugbc.tab.c"
    break;

  case 401: /* ink_definition: expr  */
#line 1505 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 6640 "src-generated/ugbc.tab.c"
    break;

  case 402: /* on_goto_definition: Identifier  */
#line 1510 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 6649 "src-generated/ugbc.tab.c"
    break;

  case 403: /* $@4: %empty  */
#line 1514 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 6657 "src-generated/ugbc.tab.c"
    break;

  case 405: /* on_gosub_definition: Identifier  */
#line 1519 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 6666 "src-generated/ugbc.tab.c"
    break;

  case 406: /* $@5: %empty  */
#line 1523 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 6674 "src-generated/ugbc.tab.c"
    break;

  case 408: /* on_proc_definition: Identifier  */
#line 1528 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 6683 "src-generated/ugbc.tab.c"
    break;

  case 409: /* $@6: %empty  */
#line 1532 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 6691 "src-generated/ugbc.tab.c"
    break;

  case 411: /* $@7: %empty  */
#line 1537 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 6699 "src-generated/ugbc.tab.c"
    break;

  case 413: /* $@8: %empty  */
#line 1540 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 6707 "src-generated/ugbc.tab.c"
    break;

  case 415: /* $@9: %empty  */
#line 1543 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 6715 "src-generated/ugbc.tab.c"
    break;

  case 417: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1548 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 6723 "src-generated/ugbc.tab.c"
    break;

  case 418: /* every_definition: ON  */
#line 1551 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 6731 "src-generated/ugbc.tab.c"
    break;

  case 419: /* every_definition: OFF  */
#line 1554 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 6739 "src-generated/ugbc.tab.c"
    break;

  case 420: /* add_definition: Identifier OP_COMMA expr  */
#line 1559 "src/ugbc.y"
                             {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 6747 "src-generated/ugbc.tab.c"
    break;

  case 421: /* add_definition: Identifier OP_COMMA expr OP_COMMA expr TO expr  */
#line 1562 "src/ugbc.y"
                                                     {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 6755 "src-generated/ugbc.tab.c"
    break;

  case 422: /* dimensions: Integer  */
#line 1568 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 6764 "src-generated/ugbc.tab.c"
    break;

  case 423: /* dimensions: Integer OP_COMMA dimensions  */
#line 1572 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 6773 "src-generated/ugbc.tab.c"
    break;

  case 424: /* datatype: BYTE  */
#line 1579 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 6781 "src-generated/ugbc.tab.c"
    break;

  case 425: /* datatype: SIGNED BYTE  */
#line 1582 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 6789 "src-generated/ugbc.tab.c"
    break;

  case 426: /* datatype: WORD  */
#line 1585 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 6797 "src-generated/ugbc.tab.c"
    break;

  case 427: /* datatype: SIGNED WORD  */
#line 1588 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 6805 "src-generated/ugbc.tab.c"
    break;

  case 428: /* datatype: DWORD  */
#line 1591 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 6813 "src-generated/ugbc.tab.c"
    break;

  case 429: /* datatype: SIGNED DWORD  */
#line 1594 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 6821 "src-generated/ugbc.tab.c"
    break;

  case 430: /* datatype: ADDRESS  */
#line 1597 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 6829 "src-generated/ugbc.tab.c"
    break;

  case 431: /* datatype: POSITION  */
#line 1600 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 6837 "src-generated/ugbc.tab.c"
    break;

  case 432: /* datatype: COLOR  */
#line 1603 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 6845 "src-generated/ugbc.tab.c"
    break;

  case 433: /* datatype: STRING  */
#line 1606 "src/ugbc.y"
             {
        (yyval.integer) = VT_DSTRING;
    }
#line 6853 "src-generated/ugbc.tab.c"
    break;

  case 434: /* $@10: %empty  */
#line 1611 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 6862 "src-generated/ugbc.tab.c"
    break;

  case 435: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1614 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 6872 "src-generated/ugbc.tab.c"
    break;

  case 436: /* $@11: %empty  */
#line 1619 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 6881 "src-generated/ugbc.tab.c"
    break;

  case 437: /* dim_definition: Identifier $@11 OP_DOLLAR OP dimensions CP  */
#line 1622 "src/ugbc.y"
                                   {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_DSTRING );
        variable_reset( _environment );
    }
#line 6891 "src-generated/ugbc.tab.c"
    break;

  case 438: /* $@12: %empty  */
#line 1627 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 6900 "src-generated/ugbc.tab.c"
    break;

  case 439: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1630 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 6910 "src-generated/ugbc.tab.c"
    break;

  case 442: /* indexes: expr  */
#line 1643 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 6919 "src-generated/ugbc.tab.c"
    break;

  case 443: /* indexes: expr OP_COMMA indexes  */
#line 1647 "src/ugbc.y"
                            {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 6928 "src-generated/ugbc.tab.c"
    break;

  case 444: /* parameters: Identifier  */
#line 1654 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6938 "src-generated/ugbc.tab.c"
    break;

  case 445: /* parameters: Identifier OP_DOLLAR  */
#line 1659 "src/ugbc.y"
                           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_DSTRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6948 "src-generated/ugbc.tab.c"
    break;

  case 446: /* parameters: Identifier AS datatype  */
#line 1664 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6958 "src-generated/ugbc.tab.c"
    break;

  case 447: /* parameters: Identifier OP_COMMA parameters  */
#line 1669 "src/ugbc.y"
                                     {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6968 "src-generated/ugbc.tab.c"
    break;

  case 448: /* parameters: Identifier OP_DOLLAR OP_COMMA parameters  */
#line 1674 "src/ugbc.y"
                                               {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_DSTRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6978 "src-generated/ugbc.tab.c"
    break;

  case 449: /* parameters: Identifier AS datatype OP_COMMA parameters  */
#line 1679 "src/ugbc.y"
                                                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6988 "src-generated/ugbc.tab.c"
    break;

  case 450: /* parameters_expr: Identifier  */
#line 1687 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6998 "src-generated/ugbc.tab.c"
    break;

  case 451: /* parameters_expr: Identifier OP_DOLLAR  */
#line 1692 "src/ugbc.y"
                           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_DSTRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7008 "src-generated/ugbc.tab.c"
    break;

  case 452: /* parameters_expr: Identifier AS datatype  */
#line 1697 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7018 "src-generated/ugbc.tab.c"
    break;

  case 453: /* parameters_expr: Identifier OP_COMMA parameters_expr  */
#line 1702 "src/ugbc.y"
                                          {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7028 "src-generated/ugbc.tab.c"
    break;

  case 454: /* parameters_expr: Identifier OP_DOLLAR OP_COMMA parameters_expr  */
#line 1707 "src/ugbc.y"
                                                    {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_DSTRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7038 "src-generated/ugbc.tab.c"
    break;

  case 455: /* parameters_expr: Identifier AS datatype OP_COMMA parameters_expr  */
#line 1712 "src/ugbc.y"
                                                      {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7048 "src-generated/ugbc.tab.c"
    break;

  case 456: /* parameters_expr: String  */
#line 1717 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7057 "src-generated/ugbc.tab.c"
    break;

  case 457: /* parameters_expr: String OP_COMMA parameters_expr  */
#line 1721 "src/ugbc.y"
                                      {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7066 "src-generated/ugbc.tab.c"
    break;

  case 458: /* values: expr  */
#line 1728 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7075 "src-generated/ugbc.tab.c"
    break;

  case 459: /* values: expr OP_COMMA values  */
#line 1732 "src/ugbc.y"
                           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7084 "src-generated/ugbc.tab.c"
    break;

  case 460: /* print_definition: expr  */
#line 1739 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 7092 "src-generated/ugbc.tab.c"
    break;

  case 461: /* print_definition: expr OP_COMMA  */
#line 1742 "src/ugbc.y"
                  {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 7101 "src-generated/ugbc.tab.c"
    break;

  case 462: /* print_definition: expr OP_SEMICOLON  */
#line 1746 "src/ugbc.y"
                      {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 7109 "src-generated/ugbc.tab.c"
    break;

  case 463: /* $@13: %empty  */
#line 1749 "src/ugbc.y"
                  {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 7118 "src-generated/ugbc.tab.c"
    break;

  case 465: /* $@14: %empty  */
#line 1753 "src/ugbc.y"
                       {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 7126 "src-generated/ugbc.tab.c"
    break;

  case 467: /* writing_mode_definition: REPLACE  */
#line 1759 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 7135 "src-generated/ugbc.tab.c"
    break;

  case 468: /* writing_mode_definition: OR  */
#line 1763 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 7144 "src-generated/ugbc.tab.c"
    break;

  case 469: /* writing_mode_definition: XOR  */
#line 1767 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 7153 "src-generated/ugbc.tab.c"
    break;

  case 470: /* writing_mode_definition: AND  */
#line 1771 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 7162 "src-generated/ugbc.tab.c"
    break;

  case 471: /* writing_mode_definition: IGNORE  */
#line 1775 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 7171 "src-generated/ugbc.tab.c"
    break;

  case 472: /* writing_part_definition: NORMAL  */
#line 1782 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 7180 "src-generated/ugbc.tab.c"
    break;

  case 473: /* writing_part_definition: PAPER  */
#line 1786 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 7189 "src-generated/ugbc.tab.c"
    break;

  case 474: /* writing_part_definition: PAPER ONLY  */
#line 1790 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 7198 "src-generated/ugbc.tab.c"
    break;

  case 475: /* writing_part_definition: PEN  */
#line 1794 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 7207 "src-generated/ugbc.tab.c"
    break;

  case 476: /* writing_part_definition: PEN ONLY  */
#line 1798 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 7216 "src-generated/ugbc.tab.c"
    break;

  case 477: /* writing_definition: writing_mode_definition OP_COMMA writing_part_definition  */
#line 1805 "src/ugbc.y"
                                                             {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 7224 "src-generated/ugbc.tab.c"
    break;

  case 478: /* locate_definition: OP_COMMA expr  */
#line 1811 "src/ugbc.y"
                   {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 7232 "src-generated/ugbc.tab.c"
    break;

  case 479: /* locate_definition: expr OP_COMMA  */
#line 1814 "src/ugbc.y"
                    {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 7240 "src-generated/ugbc.tab.c"
    break;

  case 480: /* locate_definition: expr OP_COMMA expr  */
#line 1817 "src/ugbc.y"
                         {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 7248 "src-generated/ugbc.tab.c"
    break;

  case 481: /* cmove_definition: OP_COMMA expr  */
#line 1823 "src/ugbc.y"
                   {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 7256 "src-generated/ugbc.tab.c"
    break;

  case 482: /* cmove_definition: expr OP_COMMA  */
#line 1826 "src/ugbc.y"
                    {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 7264 "src-generated/ugbc.tab.c"
    break;

  case 483: /* cmove_definition: expr OP_COMMA expr  */
#line 1829 "src/ugbc.y"
                         {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 7272 "src-generated/ugbc.tab.c"
    break;

  case 484: /* hscroll_definition: LEFT  */
#line 1835 "src/ugbc.y"
         {
        text_hscroll_line( _environment, -1 );
    }
#line 7280 "src-generated/ugbc.tab.c"
    break;

  case 485: /* hscroll_definition: SCREEN LEFT  */
#line 1838 "src/ugbc.y"
                  {
        text_hscroll_screen( _environment, -1 );
    }
#line 7288 "src-generated/ugbc.tab.c"
    break;

  case 486: /* hscroll_definition: RIGHT  */
#line 1841 "src/ugbc.y"
            {
        text_hscroll_line( _environment, 1 );
    }
#line 7296 "src-generated/ugbc.tab.c"
    break;

  case 487: /* hscroll_definition: SCREEN RIGHT  */
#line 1844 "src/ugbc.y"
                   {
        text_hscroll_screen( _environment, 1 );
    }
#line 7304 "src-generated/ugbc.tab.c"
    break;

  case 488: /* vscroll_definition: SCREEN UP  */
#line 1850 "src/ugbc.y"
                {
        text_vscroll_screen( _environment, -1 );
    }
#line 7312 "src-generated/ugbc.tab.c"
    break;

  case 489: /* vscroll_definition: SCREEN DOWN  */
#line 1853 "src/ugbc.y"
                  {
        text_vscroll_screen( _environment, 1 );
    }
#line 7320 "src-generated/ugbc.tab.c"
    break;

  case 490: /* input_definition2: Identifier  */
#line 1859 "src/ugbc.y"
                 {
        input( _environment, (yyvsp[0].string) );
        print_newline( _environment );
      }
#line 7329 "src-generated/ugbc.tab.c"
    break;

  case 491: /* input_definition2: Identifier OP_SEMICOLON  */
#line 1863 "src/ugbc.y"
                              {
        input( _environment, (yyvsp[-1].string) );
      }
#line 7337 "src-generated/ugbc.tab.c"
    break;

  case 492: /* $@15: %empty  */
#line 1866 "src/ugbc.y"
                 {
        input( _environment, (yyvsp[0].string) );
      }
#line 7345 "src-generated/ugbc.tab.c"
    break;

  case 494: /* input_definition: String OP_SEMICOLON Identifier  */
#line 1872 "src/ugbc.y"
                                     {
        print( _environment, (yyvsp[-2].string), 0 );
        input( _environment, (yyvsp[0].string) );
        print_newline( _environment );
    }
#line 7355 "src-generated/ugbc.tab.c"
    break;

  case 495: /* input_definition: String OP_SEMICOLON Identifier OP_SEMICOLON  */
#line 1877 "src/ugbc.y"
                                                  {
        print( _environment, (yyvsp[-3].string), 0 );
        input( _environment, (yyvsp[-1].string) );
    }
#line 7364 "src-generated/ugbc.tab.c"
    break;

  case 496: /* $@16: %empty  */
#line 1881 "src/ugbc.y"
                                                  {
        print( _environment, (yyvsp[-3].string), 0 );
        input( _environment, (yyvsp[-1].string) );
    }
#line 7373 "src-generated/ugbc.tab.c"
    break;

  case 514: /* statement: TEXTADDRESS OP_ASSIGN expr  */
#line 1905 "src/ugbc.y"
                               {
      variable_move( _environment, (yyvsp[0].string), "ADDRESS" );
  }
#line 7381 "src-generated/ugbc.tab.c"
    break;

  case 520: /* statement: MEMORIZE  */
#line 1913 "src/ugbc.y"
             {
      text_memorize( _environment );
  }
#line 7389 "src-generated/ugbc.tab.c"
    break;

  case 521: /* statement: REMEMBER  */
#line 1916 "src/ugbc.y"
             {
      text_remember( _environment );
  }
#line 7397 "src-generated/ugbc.tab.c"
    break;

  case 525: /* statement: CUP  */
#line 1922 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 7405 "src-generated/ugbc.tab.c"
    break;

  case 526: /* statement: CDOWN  */
#line 1925 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 7413 "src-generated/ugbc.tab.c"
    break;

  case 527: /* statement: CLEFT  */
#line 1928 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 7421 "src-generated/ugbc.tab.c"
    break;

  case 528: /* statement: CRIGHT  */
#line 1931 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 7429 "src-generated/ugbc.tab.c"
    break;

  case 529: /* statement: CLINE  */
#line 1934 "src/ugbc.y"
          {
      text_cline( _environment, NULL );
  }
#line 7437 "src-generated/ugbc.tab.c"
    break;

  case 530: /* statement: CLINE expr  */
#line 1937 "src/ugbc.y"
               {
      text_cline( _environment, (yyvsp[0].string) );
  }
#line 7445 "src-generated/ugbc.tab.c"
    break;

  case 531: /* statement: SET TAB expr  */
#line 1940 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 7453 "src-generated/ugbc.tab.c"
    break;

  case 532: /* statement: CENTER expr  */
#line 1943 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 7461 "src-generated/ugbc.tab.c"
    break;

  case 533: /* statement: CENTRE expr  */
#line 1946 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 7469 "src-generated/ugbc.tab.c"
    break;

  case 534: /* statement: CLS  */
#line 1949 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 7477 "src-generated/ugbc.tab.c"
    break;

  case 535: /* statement: HOME  */
#line 1952 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 7485 "src-generated/ugbc.tab.c"
    break;

  case 536: /* statement: CLEAR KEY  */
#line 1955 "src/ugbc.y"
              {
      clear_key( _environment );
  }
#line 7493 "src-generated/ugbc.tab.c"
    break;

  case 537: /* statement: OP_INC Identifier  */
#line 1958 "src/ugbc.y"
                      {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 7501 "src-generated/ugbc.tab.c"
    break;

  case 538: /* statement: OP_DEC Identifier  */
#line 1961 "src/ugbc.y"
                      {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 7509 "src-generated/ugbc.tab.c"
    break;

  case 539: /* statement: RANDOMIZE  */
#line 1964 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 7517 "src-generated/ugbc.tab.c"
    break;

  case 540: /* statement: RANDOMIZE expr  */
#line 1967 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 7525 "src-generated/ugbc.tab.c"
    break;

  case 541: /* statement: IF expr THEN  */
#line 1970 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 7533 "src-generated/ugbc.tab.c"
    break;

  case 542: /* statement: ELSE  */
#line 1973 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 7541 "src-generated/ugbc.tab.c"
    break;

  case 543: /* statement: ELSE IF expr THEN  */
#line 1976 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 7549 "src-generated/ugbc.tab.c"
    break;

  case 544: /* statement: ENDIF  */
#line 1979 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 7557 "src-generated/ugbc.tab.c"
    break;

  case 545: /* statement: DO  */
#line 1982 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 7565 "src-generated/ugbc.tab.c"
    break;

  case 546: /* statement: LOOP  */
#line 1985 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 7573 "src-generated/ugbc.tab.c"
    break;

  case 547: /* $@17: %empty  */
#line 1988 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 7581 "src-generated/ugbc.tab.c"
    break;

  case 548: /* statement: WHILE $@17 expr  */
#line 1990 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 7589 "src-generated/ugbc.tab.c"
    break;

  case 549: /* statement: WEND  */
#line 1993 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 7597 "src-generated/ugbc.tab.c"
    break;

  case 550: /* statement: REPEAT  */
#line 1996 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 7605 "src-generated/ugbc.tab.c"
    break;

  case 551: /* statement: UNTIL expr  */
#line 1999 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 7613 "src-generated/ugbc.tab.c"
    break;

  case 552: /* statement: EXIT  */
#line 2002 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 7621 "src-generated/ugbc.tab.c"
    break;

  case 553: /* statement: EXIT PROC  */
#line 2005 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 7629 "src-generated/ugbc.tab.c"
    break;

  case 554: /* statement: POP PROC  */
#line 2008 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 7637 "src-generated/ugbc.tab.c"
    break;

  case 555: /* statement: EXIT IF expr  */
#line 2011 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 7645 "src-generated/ugbc.tab.c"
    break;

  case 556: /* statement: EXIT Integer  */
#line 2014 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 7653 "src-generated/ugbc.tab.c"
    break;

  case 557: /* statement: EXIT direct_integer  */
#line 2017 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 7661 "src-generated/ugbc.tab.c"
    break;

  case 558: /* statement: EXIT IF expr OP_COMMA Integer  */
#line 2020 "src/ugbc.y"
                                  {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 7669 "src-generated/ugbc.tab.c"
    break;

  case 559: /* statement: EXIT IF expr OP_COMMA direct_integer  */
#line 2023 "src/ugbc.y"
                                         {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 7677 "src-generated/ugbc.tab.c"
    break;

  case 560: /* statement: FOR Identifier OP_ASSIGN expr TO expr  */
#line 2026 "src/ugbc.y"
                                          {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 7685 "src-generated/ugbc.tab.c"
    break;

  case 561: /* statement: NEXT  */
#line 2029 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 7693 "src-generated/ugbc.tab.c"
    break;

  case 562: /* statement: PROCEDURE Identifier  */
#line 2032 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 7702 "src-generated/ugbc.tab.c"
    break;

  case 563: /* $@18: %empty  */
#line 2036 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 7710 "src-generated/ugbc.tab.c"
    break;

  case 564: /* statement: PROCEDURE Identifier $@18 OSP parameters CSP  */
#line 2038 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 7718 "src-generated/ugbc.tab.c"
    break;

  case 565: /* statement: SHARED parameters_expr  */
#line 2041 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 7726 "src-generated/ugbc.tab.c"
    break;

  case 566: /* statement: GLOBAL parameters_expr  */
#line 2044 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 7734 "src-generated/ugbc.tab.c"
    break;

  case 567: /* statement: END PROC  */
#line 2047 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 7742 "src-generated/ugbc.tab.c"
    break;

  case 568: /* statement: END PROC OSP expr CSP  */
#line 2050 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 7750 "src-generated/ugbc.tab.c"
    break;

  case 569: /* statement: FOR Identifier OP_ASSIGN expr TO expr STEP expr  */
#line 2053 "src/ugbc.y"
                                                    {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 7758 "src-generated/ugbc.tab.c"
    break;

  case 570: /* statement: Identifier " "  */
#line 2056 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 7767 "src-generated/ugbc.tab.c"
    break;

  case 571: /* statement: PROC Identifier  */
#line 2060 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 7776 "src-generated/ugbc.tab.c"
    break;

  case 572: /* statement: CALL Identifier  */
#line 2064 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 7785 "src-generated/ugbc.tab.c"
    break;

  case 573: /* $@19: %empty  */
#line 2068 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 7793 "src-generated/ugbc.tab.c"
    break;

  case 574: /* statement: Identifier OSP $@19 values CSP  */
#line 2070 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 7801 "src-generated/ugbc.tab.c"
    break;

  case 575: /* $@20: %empty  */
#line 2073 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 7809 "src-generated/ugbc.tab.c"
    break;

  case 576: /* statement: PROC Identifier OSP $@20 values CSP  */
#line 2075 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 7817 "src-generated/ugbc.tab.c"
    break;

  case 577: /* $@21: %empty  */
#line 2078 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 7825 "src-generated/ugbc.tab.c"
    break;

  case 578: /* statement: CALL Identifier OSP $@21 values CSP  */
#line 2080 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 7833 "src-generated/ugbc.tab.c"
    break;

  case 579: /* statement: PEN expr  */
#line 2083 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 7841 "src-generated/ugbc.tab.c"
    break;

  case 580: /* statement: PAPER expr  */
#line 2086 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 7849 "src-generated/ugbc.tab.c"
    break;

  case 581: /* statement: INVERSE ON  */
#line 2089 "src/ugbc.y"
               {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 7857 "src-generated/ugbc.tab.c"
    break;

  case 582: /* statement: INVERSE OFF  */
#line 2092 "src/ugbc.y"
                {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 7865 "src-generated/ugbc.tab.c"
    break;

  case 584: /* statement: Identifier OP_COLON  */
#line 2096 "src/ugbc.y"
                        {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 7873 "src-generated/ugbc.tab.c"
    break;

  case 585: /* statement: BEG GAMELOOP  */
#line 2099 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 7881 "src-generated/ugbc.tab.c"
    break;

  case 586: /* statement: END GAMELOOP  */
#line 2102 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 7889 "src-generated/ugbc.tab.c"
    break;

  case 587: /* statement: GRAPHIC  */
#line 2105 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 7897 "src-generated/ugbc.tab.c"
    break;

  case 588: /* statement: HALT  */
#line 2108 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 7905 "src-generated/ugbc.tab.c"
    break;

  case 589: /* statement: END  */
#line 2111 "src/ugbc.y"
        {
      end( _environment );
  }
#line 7913 "src-generated/ugbc.tab.c"
    break;

  case 594: /* statement: RETURN  */
#line 2118 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 7921 "src-generated/ugbc.tab.c"
    break;

  case 595: /* statement: RETURN expr  */
#line 2121 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 7929 "src-generated/ugbc.tab.c"
    break;

  case 596: /* statement: POP  */
#line 2124 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 7937 "src-generated/ugbc.tab.c"
    break;

  case 597: /* statement: DONE  */
#line 2127 "src/ugbc.y"
          {
      return 0;
  }
#line 7945 "src-generated/ugbc.tab.c"
    break;

  case 598: /* statement: LEFT OP expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 2130 "src/ugbc.y"
                                                 {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 7953 "src-generated/ugbc.tab.c"
    break;

  case 599: /* statement: RIGHT OP expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 2133 "src/ugbc.y"
                                                  {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 7961 "src-generated/ugbc.tab.c"
    break;

  case 600: /* statement: MID OP expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 2136 "src/ugbc.y"
                                                {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 7969 "src-generated/ugbc.tab.c"
    break;

  case 601: /* statement: MID OP expr OP_COMMA expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 2139 "src/ugbc.y"
                                                              {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 7977 "src-generated/ugbc.tab.c"
    break;

  case 603: /* statement: Identifier OP_ASSIGN expr  */
#line 2143 "src/ugbc.y"
                              {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 7991 "src-generated/ugbc.tab.c"
    break;

  case 604: /* statement: Identifier OP_DOLLAR OP_ASSIGN expr  */
#line 2152 "src/ugbc.y"
                                        {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_DSTRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 8005 "src-generated/ugbc.tab.c"
    break;

  case 605: /* $@22: %empty  */
#line 2161 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 8014 "src-generated/ugbc.tab.c"
    break;

  case 606: /* statement: Identifier $@22 OP indexes CP OP_ASSIGN expr  */
#line 2165 "src/ugbc.y"
                                   {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 8027 "src-generated/ugbc.tab.c"
    break;

  case 607: /* $@23: %empty  */
#line 2173 "src/ugbc.y"
                         {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 8036 "src-generated/ugbc.tab.c"
    break;

  case 608: /* statement: Identifier OP_DOLLAR $@23 OP indexes CP OP_ASSIGN expr  */
#line 2176 "src/ugbc.y"
                                   {
        Variable * x = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * a = variable_retrieve( _environment, (yyvsp[-7].string) );
        if ( x->type != VT_STRING && x->type != VT_DSTRING ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[x->type], DATATYPE_AS_STRING[VT_DSTRING] );
        }
        if ( a->type != VT_ARRAY ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->type], DATATYPE_AS_STRING[VT_ARRAY] );
        }
        if ( a->arrayType != VT_DSTRING ) {
            CRITICAL_DATATYPE_MISMATCH(DATATYPE_AS_STRING[a->arrayType], DATATYPE_AS_STRING[VT_DSTRING] );
        }
        variable_move_array_string( _environment, (yyvsp[-7].string), x->name );
  }
#line 8055 "src-generated/ugbc.tab.c"
    break;

  case 609: /* $@24: %empty  */
#line 2190 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 8064 "src-generated/ugbc.tab.c"
    break;

  case 610: /* statement: Identifier $@24 datatype OP indexes CP OP_ASSIGN expr  */
#line 2193 "src/ugbc.y"
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
#line 8083 "src-generated/ugbc.tab.c"
    break;

  case 611: /* statement: DEBUG expr  */
#line 2207 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 8091 "src-generated/ugbc.tab.c"
    break;

  case 614: /* statements_no_linenumbers: statement  */
#line 2215 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 8097 "src-generated/ugbc.tab.c"
    break;

  case 615: /* $@25: %empty  */
#line 2216 "src/ugbc.y"
                         { ((Environment *)_environment)->yylineno = yylineno; }
#line 8103 "src-generated/ugbc.tab.c"
    break;

  case 617: /* $@26: %empty  */
#line 2220 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 8111 "src-generated/ugbc.tab.c"
    break;

  case 618: /* statements_with_linenumbers: Integer $@26 statements_no_linenumbers  */
#line 2222 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 8119 "src-generated/ugbc.tab.c"
    break;

  case 619: /* $@27: %empty  */
#line 2227 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 8127 "src-generated/ugbc.tab.c"
    break;

  case 625: /* $@28: %empty  */
#line 2237 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 8133 "src-generated/ugbc.tab.c"
    break;


#line 8137 "src-generated/ugbc.tab.c"

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

#line 2239 "src/ugbc.y"


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
    variable_import( _environment, "FREE_STRING", VT_WORD );
    variable_global( _environment, "FREE_STRING" );    

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

