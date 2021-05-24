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
  YYSYMBOL_A = 239,                        /* A  */
  YYSYMBOL_B = 240,                        /* B  */
  YYSYMBOL_C = 241,                        /* C  */
  YYSYMBOL_D = 242,                        /* D  */
  YYSYMBOL_E = 243,                        /* E  */
  YYSYMBOL_F = 244,                        /* F  */
  YYSYMBOL_G = 245,                        /* G  */
  YYSYMBOL_H = 246,                        /* H  */
  YYSYMBOL_I = 247,                        /* I  */
  YYSYMBOL_J = 248,                        /* J  */
  YYSYMBOL_K = 249,                        /* K  */
  YYSYMBOL_L = 250,                        /* L  */
  YYSYMBOL_M = 251,                        /* M  */
  YYSYMBOL_N = 252,                        /* N  */
  YYSYMBOL_O = 253,                        /* O  */
  YYSYMBOL_P = 254,                        /* P  */
  YYSYMBOL_Q = 255,                        /* Q  */
  YYSYMBOL_R = 256,                        /* R  */
  YYSYMBOL_S = 257,                        /* S  */
  YYSYMBOL_T = 258,                        /* T  */
  YYSYMBOL_U = 259,                        /* U  */
  YYSYMBOL_V = 260,                        /* V  */
  YYSYMBOL_X = 261,                        /* X  */
  YYSYMBOL_Y = 262,                        /* Y  */
  YYSYMBOL_W = 263,                        /* W  */
  YYSYMBOL_Z = 264,                        /* Z  */
  YYSYMBOL_F1 = 265,                       /* F1  */
  YYSYMBOL_F2 = 266,                       /* F2  */
  YYSYMBOL_F3 = 267,                       /* F3  */
  YYSYMBOL_F4 = 268,                       /* F4  */
  YYSYMBOL_F5 = 269,                       /* F5  */
  YYSYMBOL_F6 = 270,                       /* F6  */
  YYSYMBOL_F7 = 271,                       /* F7  */
  YYSYMBOL_F8 = 272,                       /* F8  */
  YYSYMBOL_BLACK = 273,                    /* BLACK  */
  YYSYMBOL_WHITE = 274,                    /* WHITE  */
  YYSYMBOL_RED = 275,                      /* RED  */
  YYSYMBOL_CYAN = 276,                     /* CYAN  */
  YYSYMBOL_VIOLET = 277,                   /* VIOLET  */
  YYSYMBOL_GREEN = 278,                    /* GREEN  */
  YYSYMBOL_BLUE = 279,                     /* BLUE  */
  YYSYMBOL_YELLOW = 280,                   /* YELLOW  */
  YYSYMBOL_ORANGE = 281,                   /* ORANGE  */
  YYSYMBOL_BROWN = 282,                    /* BROWN  */
  YYSYMBOL_LIGHT = 283,                    /* LIGHT  */
  YYSYMBOL_DARK = 284,                     /* DARK  */
  YYSYMBOL_GREY = 285,                     /* GREY  */
  YYSYMBOL_GRAY = 286,                     /* GRAY  */
  YYSYMBOL_MAGENTA = 287,                  /* MAGENTA  */
  YYSYMBOL_PURPLE = 288,                   /* PURPLE  */
  YYSYMBOL_LAVENDER = 289,                 /* LAVENDER  */
  YYSYMBOL_GOLD = 290,                     /* GOLD  */
  YYSYMBOL_TURQUOISE = 291,                /* TURQUOISE  */
  YYSYMBOL_TAN = 292,                      /* TAN  */
  YYSYMBOL_PINK = 293,                     /* PINK  */
  YYSYMBOL_PEACH = 294,                    /* PEACH  */
  YYSYMBOL_OLIVE = 295,                    /* OLIVE  */
  YYSYMBOL_Identifier = 296,               /* Identifier  */
  YYSYMBOL_String = 297,                   /* String  */
  YYSYMBOL_Integer = 298,                  /* Integer  */
  YYSYMBOL_299_0_ = 299,                   /* "0"  */
  YYSYMBOL_300_1_ = 300,                   /* "1"  */
  YYSYMBOL_301_2_ = 301,                   /* "2"  */
  YYSYMBOL_302_3_ = 302,                   /* "3"  */
  YYSYMBOL_303_4_ = 303,                   /* "4"  */
  YYSYMBOL_304_5_ = 304,                   /* "5"  */
  YYSYMBOL_305_6_ = 305,                   /* "6"  */
  YYSYMBOL_306_7_ = 306,                   /* "7"  */
  YYSYMBOL_307_8_ = 307,                   /* "8"  */
  YYSYMBOL_308_9_ = 308,                   /* "9"  */
  YYSYMBOL_309_ = 309,                     /* " "  */
  YYSYMBOL_YYACCEPT = 310,                 /* $accept  */
  YYSYMBOL_expr = 311,                     /* expr  */
  YYSYMBOL_expr_math = 312,                /* expr_math  */
  YYSYMBOL_term = 313,                     /* term  */
  YYSYMBOL_modula = 314,                   /* modula  */
  YYSYMBOL_factor = 315,                   /* factor  */
  YYSYMBOL_direct_integer = 316,           /* direct_integer  */
  YYSYMBOL_random_definition_simple = 317, /* random_definition_simple  */
  YYSYMBOL_random_definition = 318,        /* random_definition  */
  YYSYMBOL_color_enumeration = 319,        /* color_enumeration  */
  YYSYMBOL_key_scancode_alphadigit = 320,  /* key_scancode_alphadigit  */
  YYSYMBOL_key_scancode_function_digit = 321, /* key_scancode_function_digit  */
  YYSYMBOL_key_scancode_definition = 322,  /* key_scancode_definition  */
  YYSYMBOL_exponential = 323,              /* exponential  */
  YYSYMBOL_324_1 = 324,                    /* $@1  */
  YYSYMBOL_325_2 = 325,                    /* $@2  */
  YYSYMBOL_326_3 = 326,                    /* $@3  */
  YYSYMBOL_position = 327,                 /* position  */
  YYSYMBOL_bank_definition_simple = 328,   /* bank_definition_simple  */
  YYSYMBOL_bank_definition_with_payload = 329, /* bank_definition_with_payload  */
  YYSYMBOL_bank_definition = 330,          /* bank_definition  */
  YYSYMBOL_raster_definition_simple = 331, /* raster_definition_simple  */
  YYSYMBOL_raster_definition_expression = 332, /* raster_definition_expression  */
  YYSYMBOL_raster_definition = 333,        /* raster_definition  */
  YYSYMBOL_next_raster_definition_simple = 334, /* next_raster_definition_simple  */
  YYSYMBOL_next_raster_definition_expression = 335, /* next_raster_definition_expression  */
  YYSYMBOL_next_raster_definition = 336,   /* next_raster_definition  */
  YYSYMBOL_color_definition_simple = 337,  /* color_definition_simple  */
  YYSYMBOL_color_definition_expression = 338, /* color_definition_expression  */
  YYSYMBOL_color_definition = 339,         /* color_definition  */
  YYSYMBOL_milliseconds = 340,             /* milliseconds  */
  YYSYMBOL_wait_definition_simple = 341,   /* wait_definition_simple  */
  YYSYMBOL_wait_definition_expression = 342, /* wait_definition_expression  */
  YYSYMBOL_wait_definition = 343,          /* wait_definition  */
  YYSYMBOL_sprite_definition_simple = 344, /* sprite_definition_simple  */
  YYSYMBOL_sprite_definition_expression = 345, /* sprite_definition_expression  */
  YYSYMBOL_sprite_definition = 346,        /* sprite_definition  */
  YYSYMBOL_bitmap_definition_simple = 347, /* bitmap_definition_simple  */
  YYSYMBOL_bitmap_definition_expression = 348, /* bitmap_definition_expression  */
  YYSYMBOL_bitmap_definition = 349,        /* bitmap_definition  */
  YYSYMBOL_textmap_definition_simple = 350, /* textmap_definition_simple  */
  YYSYMBOL_textmap_definition_expression = 351, /* textmap_definition_expression  */
  YYSYMBOL_textmap_definition = 352,       /* textmap_definition  */
  YYSYMBOL_text_definition_simple = 353,   /* text_definition_simple  */
  YYSYMBOL_text_definition_expression = 354, /* text_definition_expression  */
  YYSYMBOL_text_definition = 355,          /* text_definition  */
  YYSYMBOL_tiles_definition_simple = 356,  /* tiles_definition_simple  */
  YYSYMBOL_tiles_definition_expression = 357, /* tiles_definition_expression  */
  YYSYMBOL_tiles_definition = 358,         /* tiles_definition  */
  YYSYMBOL_colormap_definition_simple = 359, /* colormap_definition_simple  */
  YYSYMBOL_colormap_definition_expression = 360, /* colormap_definition_expression  */
  YYSYMBOL_colormap_definition = 361,      /* colormap_definition  */
  YYSYMBOL_screen_definition_simple = 362, /* screen_definition_simple  */
  YYSYMBOL_screen_definition_expression = 363, /* screen_definition_expression  */
  YYSYMBOL_screen_definition = 364,        /* screen_definition  */
  YYSYMBOL_var_definition_simple = 365,    /* var_definition_simple  */
  YYSYMBOL_goto_definition = 366,          /* goto_definition  */
  YYSYMBOL_gosub_definition = 367,         /* gosub_definition  */
  YYSYMBOL_var_definition = 368,           /* var_definition  */
  YYSYMBOL_point_definition_simple = 369,  /* point_definition_simple  */
  YYSYMBOL_point_definition_expression = 370, /* point_definition_expression  */
  YYSYMBOL_point_definition = 371,         /* point_definition  */
  YYSYMBOL_ink_definition = 372,           /* ink_definition  */
  YYSYMBOL_on_goto_definition = 373,       /* on_goto_definition  */
  YYSYMBOL_374_4 = 374,                    /* $@4  */
  YYSYMBOL_on_gosub_definition = 375,      /* on_gosub_definition  */
  YYSYMBOL_376_5 = 376,                    /* $@5  */
  YYSYMBOL_on_proc_definition = 377,       /* on_proc_definition  */
  YYSYMBOL_378_6 = 378,                    /* $@6  */
  YYSYMBOL_on_definition = 379,            /* on_definition  */
  YYSYMBOL_380_7 = 380,                    /* $@7  */
  YYSYMBOL_381_8 = 381,                    /* $@8  */
  YYSYMBOL_382_9 = 382,                    /* $@9  */
  YYSYMBOL_every_definition = 383,         /* every_definition  */
  YYSYMBOL_add_definition = 384,           /* add_definition  */
  YYSYMBOL_dimensions = 385,               /* dimensions  */
  YYSYMBOL_datatype = 386,                 /* datatype  */
  YYSYMBOL_dim_definition = 387,           /* dim_definition  */
  YYSYMBOL_388_10 = 388,                   /* $@10  */
  YYSYMBOL_389_11 = 389,                   /* $@11  */
  YYSYMBOL_390_12 = 390,                   /* $@12  */
  YYSYMBOL_dim_definitions = 391,          /* dim_definitions  */
  YYSYMBOL_indexes = 392,                  /* indexes  */
  YYSYMBOL_parameters = 393,               /* parameters  */
  YYSYMBOL_parameters_expr = 394,          /* parameters_expr  */
  YYSYMBOL_values = 395,                   /* values  */
  YYSYMBOL_print_definition = 396,         /* print_definition  */
  YYSYMBOL_397_13 = 397,                   /* $@13  */
  YYSYMBOL_398_14 = 398,                   /* $@14  */
  YYSYMBOL_writing_mode_definition = 399,  /* writing_mode_definition  */
  YYSYMBOL_writing_part_definition = 400,  /* writing_part_definition  */
  YYSYMBOL_writing_definition = 401,       /* writing_definition  */
  YYSYMBOL_locate_definition = 402,        /* locate_definition  */
  YYSYMBOL_cmove_definition = 403,         /* cmove_definition  */
  YYSYMBOL_hscroll_definition = 404,       /* hscroll_definition  */
  YYSYMBOL_vscroll_definition = 405,       /* vscroll_definition  */
  YYSYMBOL_input_definition2 = 406,        /* input_definition2  */
  YYSYMBOL_407_15 = 407,                   /* $@15  */
  YYSYMBOL_input_definition = 408,         /* input_definition  */
  YYSYMBOL_409_16 = 409,                   /* $@16  */
  YYSYMBOL_statement = 410,                /* statement  */
  YYSYMBOL_411_17 = 411,                   /* $@17  */
  YYSYMBOL_412_18 = 412,                   /* $@18  */
  YYSYMBOL_413_19 = 413,                   /* $@19  */
  YYSYMBOL_414_20 = 414,                   /* $@20  */
  YYSYMBOL_415_21 = 415,                   /* $@21  */
  YYSYMBOL_416_22 = 416,                   /* $@22  */
  YYSYMBOL_417_23 = 417,                   /* $@23  */
  YYSYMBOL_418_24 = 418,                   /* $@24  */
  YYSYMBOL_statements_no_linenumbers = 419, /* statements_no_linenumbers  */
  YYSYMBOL_420_25 = 420,                   /* $@25  */
  YYSYMBOL_statements_with_linenumbers = 421, /* statements_with_linenumbers  */
  YYSYMBOL_422_26 = 422,                   /* $@26  */
  YYSYMBOL_statements_complex = 423,       /* statements_complex  */
  YYSYMBOL_424_27 = 424,                   /* $@27  */
  YYSYMBOL_program = 425,                  /* program  */
  YYSYMBOL_426_28 = 426                    /* $@28  */
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
#define YYLAST   5260

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  310
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  117
/* YYNRULES -- Number of rules.  */
#define YYNRULES  625
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1147

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   564


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
     305,   306,   307,   308,   309
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
     774,   777,   780,   783,   786,   789,   792,   795,   798,   798,
     804,   807,   810,   814,   818,   822,   826,   830,   834,   838,
     842,   846,   849,   852,   855,   858,   861,   864,   867,   870,
     873,   876,   879,   882,   885,   888,   891,   894,   897,   900,
     903,   906,   909,   912,   915,   919,   923,   926,   930,   934,
     938,   942,   946,   949,   952,   955,   958,   961,   964,   967,
     970,   973,   976,   980,   984,   988,   992,   996,  1000,  1004,
    1008,  1012,  1016,  1020,  1025,  1025,  1028,  1031,  1034,  1037,
    1040,  1043,  1047,  1050,  1053,  1056,  1060,  1063,  1066,  1069,
    1073,  1076,  1079,  1082,  1088,  1091,  1094,  1097,  1100,  1105,
    1106,  1109,  1112,  1117,  1120,  1125,  1126,  1129,  1132,  1137,
    1140,  1145,  1146,  1149,  1152,  1155,  1160,  1163,  1166,  1171,
    1172,  1175,  1176,  1177,  1180,  1183,  1186,  1189,  1195,  1198,
    1201,  1207,  1208,  1211,  1214,  1217,  1220,  1223,  1226,  1229,
    1232,  1235,  1238,  1241,  1244,  1247,  1250,  1253,  1258,  1261,
    1264,  1267,  1270,  1273,  1276,  1279,  1282,  1285,  1288,  1291,
    1294,  1297,  1300,  1305,  1306,  1309,  1312,  1315,  1318,  1321,
    1327,  1330,  1336,  1337,  1340,  1345,  1350,  1351,  1354,  1357,
    1362,  1365,  1370,  1371,  1374,  1379,  1384,  1385,  1388,  1391,
    1394,  1399,  1402,  1408,  1409,  1412,  1415,  1418,  1421,  1424,
    1429,  1432,  1435,  1440,  1441,  1443,  1444,  1447,  1450,  1453,
    1458,  1465,  1468,  1474,  1477,  1483,  1486,  1492,  1497,  1498,
    1501,  1506,  1510,  1510,  1515,  1519,  1519,  1524,  1528,  1528,
    1533,  1533,  1536,  1536,  1539,  1539,  1544,  1547,  1550,  1555,
    1558,  1564,  1568,  1575,  1578,  1581,  1584,  1587,  1590,  1593,
    1596,  1599,  1602,  1607,  1607,  1615,  1615,  1623,  1623,  1634,
    1635,  1639,  1643,  1650,  1655,  1660,  1665,  1670,  1675,  1683,
    1688,  1693,  1698,  1703,  1708,  1713,  1717,  1724,  1728,  1735,
    1738,  1742,  1745,  1745,  1749,  1749,  1755,  1759,  1763,  1767,
    1771,  1778,  1782,  1786,  1790,  1794,  1801,  1807,  1810,  1813,
    1819,  1822,  1825,  1831,  1834,  1837,  1840,  1846,  1849,  1855,
    1859,  1862,  1862,  1868,  1873,  1877,  1877,  1881,  1886,  1887,
    1888,  1889,  1890,  1891,  1892,  1893,  1894,  1895,  1896,  1897,
    1898,  1899,  1900,  1901,  1904,  1905,  1906,  1907,  1908,  1909,
    1912,  1915,  1916,  1917,  1918,  1921,  1924,  1927,  1930,  1933,
    1936,  1939,  1942,  1945,  1948,  1951,  1954,  1957,  1960,  1963,
    1966,  1969,  1972,  1975,  1978,  1981,  1984,  1984,  1989,  1992,
    1995,  1998,  2001,  2004,  2007,  2010,  2013,  2016,  2019,  2022,
    2025,  2028,  2032,  2032,  2037,  2040,  2043,  2046,  2049,  2052,
    2056,  2060,  2064,  2064,  2069,  2069,  2074,  2074,  2079,  2082,
    2085,  2088,  2091,  2092,  2095,  2098,  2101,  2104,  2107,  2110,
    2111,  2112,  2113,  2114,  2117,  2120,  2123,  2126,  2129,  2132,
    2135,  2138,  2139,  2148,  2157,  2157,  2169,  2169,  2186,  2186,
    2203,  2206,  2207,  2211,  2212,  2212,  2216,  2216,  2223,  2223,
    2226,  2227,  2228,  2229,  2233,  2233
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
  "LOCK", "ALT", "INPUT", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
  "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "X", "Y",
  "W", "Z", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "BLACK",
  "WHITE", "RED", "CYAN", "VIOLET", "GREEN", "BLUE", "YELLOW", "ORANGE",
  "BROWN", "LIGHT", "DARK", "GREY", "GRAY", "MAGENTA", "PURPLE",
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
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564
};
#endif

#define YYPACT_NINF (-1015)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-605)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1015,    75,  1094, -1015, -1015,  -218,  -207,  3711,    -5, -1015,
      44,  2867,    85,     3,  3144, -1015,    40,   180,  3711,  -193,
     -47, -1015, -1015, -1015,  2313,   148,    55,  3711,  3711,   -39,
     125,    18, -1015,   185,   210,  3711,  3711, -1015,   227,   254,
     -35,  3711,   149,   201, -1015,    -8, -1015,  3711,    -2,  2590,
     252,     4,  3711,    12,    33,    42,    49,  -134,  -134,  3711,
    3711,   219,   -46,  1467, -1015, -1015,  1759,  3711,  3711,   127,
   -1015, -1015, -1015, -1015,  3711, -1015, -1015,    52,   302,   301,
      14,    10, -1015,   345,   352,   353, -1015, -1015, -1015,    60,
     340,  2036, -1015, -1015,   323,   324,   328,   128, -1015, -1015,
      17, -1015, -1015,   -16,    -4,  3711, -1015, -1015,   329,   330,
     331,   333,   334,   335,   336,   337,   338,   341,   342,   344,
     346,   364,   373,   374,   375, -1015, -1015,   378,   135,   -21,
      23,   359,   365,   400,   404,   411,   412,   415, -1015, -1015,
   -1015,    11,   383,  4542, -1015,   396,   397,   398,   399,   402,
     407, -1015, -1015,   -36,   190, -1015, -1015,  4952,   408, -1015,
   -1015,   204,   208,   423, -1015, -1015, -1015, -1015, -1015, -1015,
   -1015,   166, -1015, -1015,   -37,   -78, -1015, -1015, -1015, -1015,
   -1015, -1015, -1015, -1015, -1015,   171,    24, -1015, -1015,   255,
      93,   317,   245,   232, -1015, -1015, -1015,  3144,   421, -1015,
   -1015, -1015,  3144,  3144,  3144, -1015, -1015, -1015,   157,  4952,
      -6,    59, -1015, -1015, -1015,    -3,   430,     2,     5,     8,
       9,   427, -1015, -1015, -1015,   290,   403, -1015, -1015, -1015,
    3144, -1015, -1015,   424, -1015, -1015, -1015, -1015, -1015,  3144,
     406,   409, -1015, -1015, -1015,   -11, -1015,    84, -1015, -1015,
   -1015, -1015, -1015,  3711,  3434, -1015, -1015,   453, -1015, -1015,
   -1015,  3144, -1015, -1015, -1015,  3144,   429, -1015, -1015, -1015,
     387, -1015, -1015, -1015, -1015,   318,  3711,  3711, -1015, -1015,
    3144, -1015, -1015, -1015,   431, -1015, -1015, -1015, -1015, -1015,
   -1015, -1015, -1015,  3711,  3711, -1015, -1015, -1015, -1015,   454,
   -1015, -1015,   314, -1015,  3711,   463, -1015, -1015, -1015,    34,
     465, -1015,   326,   327,   332,   146,   466, -1015, -1015, -1015,
   -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015,   471, -1015,
    3711,   472, -1015,  3711,   473, -1015, -1015, -1015,  3711, -1015,
     214, -1015, -1015, -1015,   220, -1015,  3711,   267,   476, -1015,
   -1015, -1015, -1015,  3711,   470, -1015, -1015,   444,    46,  1281,
   -1015,  1094,  1094, -1015,   446,   447,   448,   449,   450,   451,
      88,   452,  3711,  3144,  3144, -1015, -1015, -1015, -1015, -1015,
   -1015, -1015, -1015, -1015,   455, -1015, -1015,  3711, -1015, -1015,
    3711, -1015, -1015, -1015,  3711,  3711,  3711,  3711,  3711,  3711,
    3711,  3711,  3711,  3711,  3711,  3711,  3711,  3711,  3711,  3711,
    3711,  3988,   456,   191, -1015, -1015,   457, -1015, -1015,   458,
     459, -1015, -1015, -1015, -1015, -1015,  3711, -1015,  3711,  2036,
     460,   469,  3711,  3711,  3711,  3711,  3711,  3711, -1015, -1015,
   -1015, -1015, -1015, -1015,   281,   282, -1015, -1015, -1015, -1015,
   -1015, -1015, -1015, -1015, -1015, -1015,   181, -1015, -1015, -1015,
     182, -1015, -1015, -1015, -1015, -1015,   276, -1015, -1015,   464,
   -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015,
   -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015,
   -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015,
   -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015,
   -1015, -1015, -1015, -1015, -1015, -1015, -1015,  3711, -1015, -1015,
   -1015,   467, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015,
     468, -1015,   474,   179,   218,  3988,  3988,  3988,  3988,  3988,
    3988,  3988,  3988,  3988,  3988,  3988,  3988,  3988,   -54,  4265,
    4819,   477,   478,  3144, -1015, -1015,   428,   433,   437,   438,
   -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015,
    3144,   475, -1015, -1015, -1015,   479,   430,   487,   430,   488,
     430,   489,   430,   490,   430, -1015,  3711,   482, -1015, -1015,
     262,   272,    37,   160, -1015, -1015, -1015,   483,   430,   485,
   -1015, -1015,   274,   280,   192,   193, -1015, -1015,   486, -1015,
   -1015,  3144, -1015, -1015,  3144,  3144, -1015, -1015, -1015,   461,
     226, -1015,   518,  3711, -1015, -1015, -1015, -1015,  3144, -1015,
    3711,   520,   521, -1015, -1015,  3144,   462,   522,  3711,   425,
     523,  3711, -1015, -1015, -1015, -1015, -1015, -1015,   156, -1015,
   -1015,   492,   514,    12, -1015,   385, -1015,  -134,   529,    46,
    -134,   -28, -1015,  3711, -1015,  3711, -1015, -1015, -1015, -1015,
   -1015, -1015, -1015,   531,   243,  1094, -1015,  3711,   500,  3711,
    3711,   501,     6, -1015,  1281, -1015, -1015,  3711,   244,   246,
     247,   249,   250,   502,   508,   509, -1015,   510,   511,   512,
     513,   515,  3711,   548,   550,   551,   552,   519,   524,   525,
     526,   554,   527,   528,   530,   532,   533,   555,   557,   534,
     535,   536,    67,   284,   537,  3711,  3711,  3711,   540,    65,
      89,  3711,  3988,   541,   542,   543,   544,   545,   546, -1015,
   -1015,   491,   493, -1015, -1015, -1015,  3711,   549,  3711,   553,
    3711,  3711,  3711,  3711,   317,   317,   339,   339,   339,   339,
     339,   339,   339,   339,   245,   232,   232,   379,  4819,  4819,
   -1015, -1015,   293,   295, -1015, -1015,  3711,   430,  3711,   430,
     559,   560,  3144,   143, -1015,   430, -1015,   430, -1015,   430,
   -1015,   430,    38, -1015,  3711, -1015, -1015, -1015, -1015, -1015,
   -1015, -1015, -1015,  3711, -1015,   430, -1015, -1015, -1015, -1015,
   -1015, -1015, -1015, -1015,   430, -1015, -1015, -1015, -1015, -1015,
   -1015,   300,   303,   305,   306,   584,  3711,   565,   558,   561,
     494,  3711,  3711,   591,   598, -1015,   -13,   539,   315,  3711,
     603, -1015, -1015, -1015,   572,   316,   573, -1015,  3711,   319,
    3711, -1015,  -134,   611, -1015,   480,   484, -1015, -1015, -1015,
   -1015,   343,   614, -1015, -1015,  3711,   613,   495,   615,   583,
    3711, -1015,   618, -1015, -1015, -1015, -1015, -1015,   349,   355,
     356, -1015, -1015, -1015, -1015, -1015,   585,  3711,  3711,  3711,
    3711, -1015, -1015, -1015, -1015,  3711, -1015, -1015, -1015, -1015,
   -1015,  3711,  3711, -1015, -1015, -1015,  4819,   586, -1015,   588,
     623,   626, -1015,  3711, -1015,  3711,   630,   617, -1015, -1015,
   -1015, -1015, -1015, -1015, -1015, -1015,   597, -1015,   600,  3711,
     499,   601, -1015, -1015,  4819, -1015, -1015, -1015, -1015, -1015,
   -1015, -1015, -1015,   347,   348, -1015, -1015, -1015, -1015, -1015,
   -1015,   616, -1015,   625, -1015,   367,   151, -1015,   655, -1015,
     658,   659, -1015,   660, -1015,   661, -1015,   656,  3144,   664,
    3711,  3711,   430, -1015,   632,   633,  3711,   430, -1015, -1015,
    3711, -1015,   145,  3711,   316,   668,   635,   316,   538,   150,
     547,   562, -1015,  -134, -1015, -1015, -1015,   382,   638,  3711,
   -1015,  3711,   669,   640,  3711, -1015, -1015, -1015, -1015,   642,
     643,   147,   164,   644,   645,   646,   647, -1015, -1015,  3711,
    3711,   650,   651, -1015, -1015,   662, -1015, -1015, -1015, -1015,
   -1015,   405,   413, -1015,   665, -1015,   666, -1015,  3711,   430,
     692,   697,   698,  3711, -1015, -1015,  3711, -1015, -1015, -1015,
     693,   695,   670,   671,   596,  3711,   703,   639,   680,   316,
   -1015,   681, -1015,   319,   716,    46, -1015, -1015, -1015,   343,
     712, -1015, -1015,  3711,   713,   686, -1015, -1015,  3711, -1015,
    3711, -1015, -1015, -1015, -1015, -1015,   687,   688, -1015, -1015,
   -1015, -1015, -1015,   434,   435,   689,   694,   300,   303,   305,
   -1015, -1015,  3711,  3711, -1015, -1015,  3711,   696,  3711,  3711,
   -1015, -1015, -1015, -1015,   319,   726, -1015,  3711, -1015,  3711,
   -1015,   699,   701, -1015, -1015, -1015, -1015, -1015, -1015, -1015,
   -1015, -1015, -1015, -1015, -1015,   721, -1015, -1015, -1015,   319,
   -1015, -1015, -1015, -1015,  3711, -1015, -1015
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     624,     0,   612,     1,   611,     0,     0,     0,     0,   596,
       0,     0,   560,     0,     0,   587,     0,     0,     0,   385,
       0,   545,   549,   546,     0,     0,     0,     0,     0,     0,
       0,   588,   543,     0,     0,     0,   538,   586,     0,     0,
       0,   593,   595,   541,   544,   551,   548,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   533,   534,     0,     0,     0,     0,
     524,   525,   526,   527,   528,   519,   520,     0,     0,     0,
       0,   608,   616,   613,   620,   622,   625,   536,   537,     0,
       0,     0,   157,   158,     0,     0,     0,     0,   201,   202,
       0,   227,   228,   229,   230,     0,   192,   193,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   194,   203,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   214,   215,
     216,     0,     0,     0,   225,   231,     0,     0,     0,     0,
       0,   233,   234,     0,     0,   238,   248,     0,     0,   240,
     246,     0,     0,     0,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,     0,     0,    49,    54,    55,    56,
      57,    58,    59,    62,    63,     0,   142,   146,   144,   459,
       2,    12,    15,    17,   155,    20,   517,     0,     0,   285,
     286,   499,     0,     0,     0,   299,   300,   501,     0,   307,
       0,     0,   311,   312,   502,     0,     0,     0,     0,     0,
       0,     0,   279,   280,   498,     0,     0,   343,   344,   503,
       0,   346,   347,   348,   352,   353,   504,   375,   376,     0,
       0,     0,   383,   384,   509,     0,   589,     0,   395,   512,
     391,   392,   590,     0,     0,   358,   359,     0,   362,   363,
     506,     0,   366,   367,   507,     0,   369,   373,   374,   508,
       0,   578,   535,   584,   585,   566,     0,     0,   610,   539,
       0,   356,   357,   505,     0,   398,   399,   510,   393,   394,
     591,   594,   553,     0,     0,   552,   555,   556,   550,     0,
     417,   418,     0,   592,     0,     0,   514,   400,   511,   433,
     439,   601,   570,   561,   571,   449,   455,   564,   565,   515,
     579,   580,   581,   469,   467,   466,   468,   470,     0,   582,
       0,     0,   518,     0,     0,   523,   531,   532,     0,   529,
       0,   483,   485,   521,     0,   522,     0,   489,     0,   497,
     516,   618,   583,     0,   606,   572,   569,     0,     0,   612,
     614,   612,   612,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    29,    30,    32,    34,
      35,    31,    36,   181,     0,   195,   196,     0,   242,   249,
       0,   244,   251,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   197,   200,     0,   198,   199,     0,
       0,   213,   207,   208,   209,   210,     0,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   239,
     243,   245,   111,   112,     0,     0,   132,   137,   122,   241,
     108,   110,   113,   114,   115,   116,     0,   119,   120,   123,
       0,   128,   129,   130,   131,   133,     0,   135,   136,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,   109,   121,   253,     0,   247,   250,
     252,     0,    60,    47,    50,    51,    52,    53,    48,    61,
     143,   188,     0,   464,   462,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   296,   293,     0,     0,     0,     0,
      28,   301,   308,   302,   303,   309,   310,   304,   305,   306,
       0,     0,   291,   292,   500,   256,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,     0,   333,   334,
       0,     0,     0,     0,   330,   329,   254,     0,     0,     0,
     318,   319,     0,     0,     0,     0,   315,   314,     0,   350,
     345,     0,   380,   377,     0,     0,   410,   414,   412,     0,
       0,   547,     0,     0,   365,   364,   371,   368,     0,   540,
       0,     0,     0,   355,   354,     0,     0,   554,     0,     0,
       0,     0,   431,   423,   425,   430,   427,   432,     0,   429,
     437,     0,     0,     0,   574,     0,   576,     0,   450,     0,
       0,     0,   477,   478,   480,   481,   530,   484,   486,   487,
     488,   513,   490,     0,     0,   612,   602,     0,     0,     0,
       0,     0,   608,   617,   612,   621,   623,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     125,     0,     0,   126,   124,   134,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    14,     5,     7,     8,     9,
      10,     6,     3,     4,    16,    18,    19,     0,     0,     0,
      25,    21,     0,     0,   283,   281,     0,     0,     0,     0,
       0,     0,     0,     0,   261,     0,   273,     0,   265,     0,
     269,     0,   257,   331,     0,   338,   337,   342,   341,   336,
     340,   335,   339,     0,   316,     0,   323,   322,   327,   326,
     321,   325,   320,   324,     0,   351,   349,   381,   378,   382,
     379,     0,     0,     0,     0,   386,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   542,     0,     0,     0,     0,
     419,   424,   426,   428,     0,     0,     0,   440,     0,     0,
       0,   452,     0,   451,   456,   474,   472,   471,   476,   479,
     482,     0,   493,   619,   603,     0,   457,     0,   441,     0,
       0,   615,     0,   154,   147,   149,   153,   151,     0,     0,
       0,   156,   160,   159,   162,   161,     0,     0,     0,     0,
       0,   169,   170,   171,   180,     0,   174,   175,   176,   177,
     178,     0,     0,   190,   191,   182,     0,     0,   186,     0,
       0,     0,   217,     0,   172,     0,     0,    27,   223,   218,
     219,   220,   221,   222,   118,   117,     0,   237,     0,     0,
       0,     0,   465,   463,     0,    23,    26,   284,   282,   298,
     295,   297,   294,     0,     0,   289,   287,   258,   271,   263,
     266,   260,   272,   264,   268,     0,     0,   328,     0,   313,
       0,   401,   411,   404,   415,   407,   413,   387,     0,     0,
       0,     0,     0,   567,     0,     0,     0,     0,   557,   558,
       0,   416,     0,     0,     0,   421,     0,     0,     0,   443,
       0,     0,   453,     0,   475,   473,   492,   494,     0,     0,
     573,     0,     0,     0,     0,   148,   150,   152,   204,     0,
       0,     0,     0,     0,     0,     0,     0,   187,   205,     0,
       0,     0,     0,   236,   232,     0,   189,   139,    24,   290,
     288,     0,     0,   274,   259,   270,   262,   267,     0,     0,
       0,     0,     0,     0,   389,   388,     0,   361,   372,   370,
       0,     0,     0,     0,   559,     0,     0,     0,     0,     0,
     434,     0,   575,     0,   444,     0,   563,   577,   454,     0,
       0,   458,   442,     0,     0,     0,   163,   164,     0,   165,
       0,   167,   179,   185,   184,    22,     0,     0,   173,   226,
     141,   276,   278,     0,     0,     0,     0,     0,     0,     0,
     390,   360,     0,     0,   397,   396,     0,     0,     0,     0,
     438,   422,   436,   446,     0,   445,   496,     0,   605,     0,
     211,     0,     0,   212,   206,   275,   277,   332,   317,   403,
     406,   409,   597,   598,   568,     0,   599,   420,   447,     0,
     607,   609,   166,   168,     0,   448,   600
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1015,    -7,  -132,  -181,   199,  -405,    79, -1015, -1015, -1015,
   -1015, -1015, -1015,  -133, -1015, -1015, -1015,   556, -1015, -1015,
   -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015,
     563, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015,
   -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015,
   -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015,
   -1015, -1015, -1015,  -361, -1015,  -360, -1015,  -352, -1015, -1015,
   -1015, -1015, -1015, -1015, -1015,  -916,  -356, -1015, -1015, -1015,
   -1015,    95,  -736, -1014,   -57,  -728,   -56, -1015, -1015, -1015,
   -1015, -1015, -1015, -1015, -1015, -1015,  -830, -1015, -1015, -1015,
   -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015, -1015,  -354,
   -1015, -1015, -1015,  -353, -1015, -1015, -1015
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   868,   190,   191,   192,   193,   211,   382,   383,   194,
     514,   515,   516,   195,   532,   749,   750,   597,   222,   223,
     224,   199,   200,   201,   572,   573,   574,   205,   206,   207,
     566,   212,   213,   214,   227,   228,   229,   234,   235,   236,
     281,   282,   283,   258,   259,   260,   262,   263,   264,   267,
     268,   269,   242,   243,   244,   248,   252,   290,   249,   285,
     286,   287,   308,   962,  1040,   964,  1041,   966,  1042,   246,
     821,   823,   822,   303,   306,   986,   650,   310,   651,   652,
     844,   311,   869,   990,   317,   867,   196,   753,   752,   328,
     858,   329,   332,   335,   343,   345,   349,   673,   350,  1069,
      83,   253,   655,   679,   848,   850,   357,   678,   358,    84,
     684,    85,   359,    86,   675,     1,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     189,   318,   681,   319,   210,   683,   722,   225,   685,   686,
     431,   245,   352,   208,   351,   931,   352,   257,   208,   353,
     270,   271,   930,   353,   387,   197,   354,   570,   278,   279,
     354,   996,   576,   216,   291,   578,   390,   384,   580,   582,
     298,   217,   302,   416,   530,   307,  -604,   438,   616,  1113,
    -604,   426,   189,   320,  -435,   323,   331,   767,   218,   334,
     336,   337,   855,   324,  -138,   642,   294,   339,  1058,   414,
     230,  1061,   913,   955,   906,     3,   202,   642,    87,   561,
     562,   203,   231,   232,   371,   265,   219,   220,   799,    88,
     548,   549,   956,   226,   550,   617,   915,   800,   393,   340,
    1138,   535,   536,   247,   619,   537,   914,   538,   539,   540,
     541,   542,   274,   215,   643,   644,   645,   325,   326,   327,
     988,   204,   991,   646,   297,  1145,   643,   644,   645,   998,
     696,   233,   620,   856,  1003,   646,   618,   768,   857,   295,
     415,   765,   766,  1111,   561,   567,   266,   563,   564,   565,
     341,   342,  1055,   657,  1078,   412,   355,  1063,   385,   375,
     355,   647,   315,   316,   417,   275,   658,   439,   693,   694,
    1064,  1080,   648,   647,   531,   413,   386,   695,   261,  -461,
     649,   947,   418,  -461,   648,  -461,  1056,   388,  1079,  1034,
     551,   272,   649,  1025,   543,   554,   556,   558,   948,   391,
     659,   527,   544,   427,  1065,  1081,  1035,   528,   376,   377,
     378,   801,   563,   564,   568,   379,   380,   381,  -460,   273,
     802,   389,  -460,   609,  -460,   276,   949,   950,   237,   238,
     239,   240,   612,   392,  1036,  1037,   841,   842,   523,  1116,
     241,   524,   525,   810,   812,   843,   621,   622,   526,   250,
     277,   251,   811,   813,   624,   548,   549,   280,   626,   550,
     533,   288,   534,   289,   546,  1072,   547,   321,   322,   631,
     632,  1071,   672,   633,  -491,   293,   552,   741,   743,   742,
     744,   555,   557,   559,   284,   978,   636,   637,   440,   441,
     296,   198,   304,   571,   299,   575,   292,   640,   577,   221,
     305,   579,   338,   853,   581,   583,   519,   520,   309,   610,
     347,   348,   667,   668,   346,   356,   669,   670,   613,   356,
     585,   586,   863,   662,   795,   796,   664,   917,   587,   312,
     871,   666,   588,   589,   797,   798,   806,   807,   313,   671,
     625,   590,   808,   809,   627,   314,   676,   535,   536,   344,
     591,   360,   592,   593,   754,   755,   361,   362,   363,   634,
     364,   594,   595,   372,   373,   697,   698,   700,   374,   394,
     395,   396,   596,   397,   398,   399,   400,   401,   402,   419,
     703,   403,   404,   704,   405,   420,   406,   705,   706,   707,
     708,   709,   710,   711,   712,   713,   714,   715,   716,   717,
     718,   719,   720,   721,   407,   756,   757,   758,   759,   760,
     761,   762,   763,   408,   409,   410,   770,   771,   411,   728,
     421,   729,   730,   428,   422,   733,   734,   735,   736,   737,
     738,   423,   424,   585,   598,   425,   432,   433,   434,   435,
     518,   599,   436,   521,   522,   600,   601,   437,   517,   529,
     545,   553,   699,   701,   602,   560,   208,   584,   614,   611,
     623,   615,   629,   603,   628,   604,   605,   638,   630,   639,
     641,   635,   653,   660,   606,   607,   654,  -562,   661,   663,
     665,   674,   656,   677,   680,   596,   687,   724,   688,   689,
     690,   691,   692,   696,   732,   702,   723,   725,   726,   727,
     731,   739,   740,   745,   746,   782,   776,   748,  -140,   824,
     747,   777,   772,   773,   751,   778,   779,   785,   787,   789,
     791,   794,   825,   803,   805,   826,   814,   831,   832,   836,
     839,   838,   845,   783,   846,   849,   852,   835,   861,   862,
     865,   870,   873,   878,   874,   875,   774,   876,   877,   879,
     880,   881,   882,   883,   884,   887,   885,   888,   889,   890,
     891,   895,   901,   780,   902,   892,   893,   894,   896,   897,
     934,   898,   970,   899,   900,   903,   904,   905,   908,   793,
     907,   912,   918,   919,   920,   921,   922,   923,   924,   937,
     927,   938,   925,   929,   943,   944,   961,   968,   976,   963,
     851,   965,   967,   854,   815,   977,   971,   817,   819,   972,
     983,   981,   984,   987,   985,   989,   827,   980,   993,   997,
     999,   828,  1001,   830,  1002,  1004,  1008,  1017,   833,  1018,
    1019,   837,   775,  1020,   840,   935,   936,   915,  1023,   347,
     548,  1024,  1027,  1029,  1030,   973,  1000,  1005,   994,   781,
    1026,  1031,   995,  1006,  1007,   784,   859,   786,   860,   788,
    1032,   790,  1038,   792,  1033,  1039,  -402,  -405,  -408,  1043,
     864,  1046,   866,  1050,  1051,  1059,  1060,   804,  -495,  1070,
     872,  1074,  1073,  1076,  1077,  1082,  1083,  1084,  1085,  1062,
     816,  1088,  1089,   818,   820,   886,   932,   933,  1066,  1097,
    1093,  1094,  1091,  1090,  1098,  1099,  1102,   829,  1103,  1115,
    1092,  1104,  1105,  1067,   834,  1106,  1108,  1109,   909,   910,
     911,  1110,  1112,  1114,   916,  1117,  1119,  1120,  1123,  1124,
    1127,  1125,  1126,  1139,  1144,  1128,  1129,  1135,  1130,   926,
    1142,   928,  1143,   866,   764,   189,   189,  1131,   847,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   939,
       0,   941,     0,  1016,   569,   945,     0,     0,     0,     0,
       0,     0,   608,     0,     0,     0,     0,   957,     0,     0,
       0,     0,     0,     0,     0,   992,   958,     0,     0,     0,
       0,  1028,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   969,
       0,     0,     0,     0,   974,   975,     0,     0,     0,     0,
       0,     0,   982,     0,     0,     0,     0,     0,     0,     0,
       0,   866,     0,   866,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   940,     0,   942,     0,
       0,   946,     0,     0,   951,     0,   952,     0,   953,     0,
     954,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1009,  1010,  1011,  1012,   959,     0,     0,     0,  1013,     0,
       0,     0,     0,   960,  1014,  1015,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1021,     0,  1022,     0,
       0,     0,     0,     0,     0,   979,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1068,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1044,     0,  1047,  1048,     0,     0,     0,     0,  1052,
       0,     0,     0,  1054,     0,     0,  1057,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   866,     0,     0,     0,     0,  1075,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1086,  1087,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1095,     0,     0,     0,     0,  1100,     0,     0,  1101,
       0,     0,     0,     0,     0,     0,     0,  1045,  1107,     0,
       0,  1049,     0,     0,     0,     0,  1053,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1118,     0,     0,     0,
       0,  1121,     0,  1122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1132,  1133,     4,     0,  1134,
       0,  1136,  1137,     0,     5,     6,     0,     0,     0,     0,
    1140,     0,  1141,     0,     0,     0,     7,     0,  1096,     0,
       0,     0,     8,     9,     0,    10,     0,    11,    12,     0,
      13,    14,     0,     0,     0,     0,     0,  1146,    15,     0,
      16,    17,    18,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,    21,    22,
      23,    24,    25,    26,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    29,    30,    31,     0,    32,
       0,     0,    33,    34,    35,     0,    36,    37,    38,    39,
      40,    41,    42,     0,    43,     0,     0,     0,    44,    45,
      46,    47,    48,     0,    49,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,    52,     0,     0,    53,
       0,    54,    55,    56,     0,     0,    57,     0,     0,     0,
      58,     0,    59,     0,     0,    60,    61,     0,     0,     0,
       0,    62,     0,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,     0,     0,    75,    76,
      77,    78,    79,     0,     4,     0,     0,     0,     0,     0,
       0,     5,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     8,
       9,     0,    10,     0,    11,    12,     0,    13,    14,     0,
       0,     0,     0,     0,     0,    15,     0,    16,    17,    18,
       0,     0,    80,     0,    19,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,    21,    22,    23,    24,    25,
      26,     0,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    29,    30,    31,     0,    32,     0,     0,    33,
      34,    35,     0,    36,    37,    38,    39,    40,    41,    42,
      81,    43,    82,     0,     0,    44,    45,    46,    47,    48,
       0,    49,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,    53,     0,    54,    55,
      56,     0,     0,    57,     0,     0,     0,    58,     0,    59,
       0,     0,    60,    61,     0,     0,     0,     0,    62,     0,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,     0,     0,    75,    76,    77,    78,    79,
       0,     0,     0,     0,   330,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,    92,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,     0,     0,    96,     0,     0,    97,     0,     0,     0,
       0,     0,     0,     0,    98,    99,     0,   100,     0,     0,
       0,     0,     0,   101,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   682,   105,   106,
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
     159,   160,   161,     0,   162,   163,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,     0,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   333,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
       0,   158,   159,   160,   161,     0,   162,   163,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    89,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,     0,
       0,     0,     0,     0,     0,     0,    90,   365,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,    96,     0,     0,    97,   366,   367,   368,     0,
       0,     0,     0,    98,    99,   369,   100,     0,     0,     0,
       0,     0,   101,   102,   103,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,     0,
       0,   120,   121,   122,   370,   123,   124,   125,     0,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,   129,     0,   130,     0,     0,
       0,     0,     0,     0,     0,   131,     0,     0,   132,     0,
       0,   133,     0,   134,   135,   136,   137,     0,   138,   139,
       0,     0,     0,     0,   140,   141,   142,   143,     0,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,     0,     0,     0,     0,     0,     0,     0,     0,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,     0,   158,   159,
     160,   161,     0,   162,   163,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,    89,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,     0,     0,     0,     0,     0,
       0,     0,     0,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,     0,   255,   256,     0,     0,     0,
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
     162,   163,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,    89,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,   300,   301,
       0,     0,     0,     0,     0,     0,    92,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,     0,     0,    96,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,    98,    99,     0,
     100,     0,     0,     0,     0,     0,   101,   102,   103,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,     0,     0,   120,   121,   122,     0,   123,
     124,   125,     0,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,     0,   129,
       0,   130,     0,     0,     0,     0,     0,     0,     0,   131,
       0,     0,   132,     0,     0,   133,     0,   134,   135,   136,
     137,     0,   138,   139,     0,     0,     0,     0,   140,   141,
     142,   143,     0,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,     0,     0,     0,     0,     0,
       0,     0,     0,   156,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,     0,   158,   159,   160,   161,     0,   162,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,    89,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,     0,
       0,     0,     0,   208,     0,     0,     0,    90,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,   209,     0,   158,
     159,   160,   161,     0,   162,   163,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    89,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,     0,     0,     0,
     208,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    93,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,     0,     0,
      96,     0,     0,    97,     0,     0,     0,     0,     0,     0,
       0,    98,    99,     0,   100,     0,     0,     0,     0,     0,
     101,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   106,   107,     0,     0,
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
       0,   162,   163,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
       0,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   364,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    93,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,     0,     0,
      96,     0,     0,    97,     0,     0,     0,     0,     0,     0,
       0,    98,    99,     0,   100,     0,     0,     0,     0,     0,
     101,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   106,   107,     0,     0,
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
       0,   162,   163,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      89,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,     0,     0,     0,     0,     0,     0,
       0,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,    93,    94,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,    89,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
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
       0,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,   129,     0,   130,
       0,     0,     0,     0,     0,     0,     0,   131,     0,     0,
     132,     0,     0,   133,     0,   134,   135,   136,   137,     0,
     138,   139,     0,     0,     0,     0,   140,   141,   142,   143,
       0,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,     0,     0,     0,     0,     0,     0,     0,
       0,   156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,     0,
     158,   159,   160,   161,     0,   162,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    89,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,     0,     0,
       0,     0,     0,     0,     0,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    93,    94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,     0,
       0,    96,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,    98,    99,     0,   100,     0,     0,     0,     0,
       0,   101,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   769,   106,   107,     0,
       0,     0,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
     120,   121,   122,     0,   123,   124,   125,     0,   126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,     0,   129,     0,   130,     0,     0,     0,
       0,     0,     0,     0,   131,     0,     0,   132,     0,     0,
     133,     0,   134,   135,   136,   137,     0,   138,   139,     0,
       0,     0,     0,   140,   141,   142,   430,     0,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,     0,     0,     0,     0,     0,     0,     0,   156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,     0,   158,   159,   160,
     161,     0,   162,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,    89,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,     0,     0,     0,     0,     0,
       0,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   429,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,    96,     0,
       0,    97,     0,     0,     0,     0,     0,     0,     0,    98,
      99,     0,   100,     0,     0,     0,     0,     0,   101,   102,
     103,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,     0,     0,   120,   121,   122,
       0,   123,   124,   125,     0,   126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
       0,   129,     0,   130,     0,     0,     0,     0,     0,     0,
       0,   131,     0,     0,   132,     0,     0,   133,     0,   134,
     135,   136,   137,     0,   138,   139,     0,     0,     0,     0,
     140,   141,   142,   430,     0,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,     0,     0,     0,
       0,     0,     0,     0,     0,   156,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,     0,   158,   159,   160,   161,     0,   162,
     163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    89,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,     0,     0,    96,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,    98,    99,     0,   100,
       0,     0,     0,     0,     0,   101,   102,   103,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,     0,     0,   120,   121,   122,     0,   123,   124,
     125,     0,   126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,   129,     0,
     130,     0,   442,     0,     0,     0,     0,     0,   131,     0,
       0,   132,     0,     0,   133,     0,   134,   135,   136,   137,
       0,   138,   139,     0,     0,     0,     0,   140,   141,   142,
     430,     0,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,     0,     0,     0,     0,     0,     0,
       0,     0,   156,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   443,     0,     0,     0,     0,   444,   157,
     445,   158,   159,   160,   161,     0,   162,   163,     0,   446,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     447,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,     0,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,     0,
       0,     0,     0,   448,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   449,     0,     0,     0,   450,
       0,   451,   452,   453,   454,   455,   456,     0,   457,   458,
       0,   459,   460,   461,   462,   463,   464,   465,   466,     0,
     467,   468,     0,   469,     0,     0,     0,     0,     0,     0,
       0,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513
};

static const yytype_int16 yycheck[] =
{
       7,    58,   358,    59,    11,   359,   411,    14,   361,   362,
     143,    18,     6,    26,     4,   751,     6,    24,    26,    13,
      27,    28,   750,    13,    40,    30,    20,    30,    35,    36,
      20,   861,    30,    30,    41,    30,    40,    20,    30,    30,
      47,    38,    49,    20,    20,    52,    40,    83,    59,  1063,
      40,    40,    59,    60,    20,   101,    63,   111,    55,    66,
      67,    68,    90,   109,    40,    31,    74,    74,   984,    90,
      30,   987,     7,    35,     7,     0,    32,    31,   296,    85,
      86,    37,    42,    43,    91,    30,    83,    84,    51,   296,
      23,    24,    54,    14,    27,   106,     7,    60,   105,    47,
    1114,     8,     9,   296,    20,    12,    41,    14,    15,    16,
      17,    18,    94,    28,    80,    81,    82,   163,   164,   165,
     848,    77,   850,    89,    45,  1139,    80,    81,    82,   865,
      41,    91,    48,   161,   870,    89,   147,   191,   166,   147,
     161,   546,   547,  1059,    85,    86,    91,   153,   154,   155,
      98,    99,     7,     7,     7,    20,   150,     7,   141,    31,
     150,   127,   296,   297,   141,   147,    20,   203,    80,    81,
      20,     7,   138,   127,   150,    40,   159,    89,    30,     0,
     146,    38,   159,     4,   138,     6,    41,   203,    41,    38,
     197,   230,   146,   929,   101,   202,   203,   204,    55,   203,
      54,   279,   109,   192,    54,    41,    55,   285,    80,    81,
      82,    51,   153,   154,   155,    87,    88,    89,     0,    94,
      60,   237,     4,   230,     6,    40,    83,    84,    48,    49,
      50,    51,   239,   237,    83,    84,    80,    81,   275,  1069,
      60,   278,   279,    51,    51,    89,   253,   254,   285,   296,
      40,   298,    60,    60,   261,    23,    24,    30,   265,    27,
       5,   296,     7,   298,    19,  1001,    21,    48,    49,   276,
     277,   999,     5,   280,     7,    74,   197,    96,    96,    98,
      98,   202,   203,   204,    30,   298,   293,   294,    98,    99,
     298,   296,    40,   296,   296,   216,   147,   304,   296,   296,
     296,   296,   175,   659,   296,   296,    98,    99,   296,   230,
     296,   297,    98,    99,    13,   309,    96,    97,   239,   309,
      30,    31,   675,   330,    62,    63,   333,   732,    38,   296,
     684,   338,    42,    43,    62,    63,    62,    63,   296,   346,
     261,    51,    62,    63,   265,   296,   353,     8,     9,    47,
      60,     6,    62,    63,   535,   536,     4,     4,   298,   280,
      20,    71,    72,    40,    40,   372,   373,   374,    40,    40,
      40,    40,    82,    40,    40,    40,    40,    40,    40,    20,
     387,    40,    40,   390,    40,    20,    40,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,    40,   537,   538,   539,   540,   541,
     542,   543,   544,    40,    40,    40,   549,   550,    40,   426,
      20,   428,   429,    40,    20,   432,   433,   434,   435,   436,
     437,    20,    20,    30,    31,    20,    40,    40,    40,    40,
     236,    38,    40,    20,   278,    42,    43,    40,    40,   278,
     133,    30,   373,   374,    51,   298,    26,    30,    52,    35,
       7,    52,    75,    60,    35,    62,    63,    13,   150,   155,
       7,    40,     7,     7,    71,    72,   150,   150,     7,     7,
       7,     5,   150,    13,    40,    82,    40,   296,    41,    41,
      41,    41,    41,    41,    25,    40,    40,    40,    40,    40,
      40,   220,   220,   227,    40,    30,    78,    40,    40,    48,
     517,    78,    35,    35,    40,    78,    78,    30,    30,    30,
      30,    39,   296,    40,    39,     7,    40,     7,     7,     7,
       7,   106,    40,    54,    20,   150,     7,    75,     7,   296,
      40,    40,   298,    41,   298,   298,   553,   298,   298,    41,
      41,    41,    41,    41,    41,     7,    41,     7,     7,     7,
      41,     7,     7,   570,     7,    41,    41,    41,    41,    41,
     191,    41,     7,    41,    41,    41,    41,    41,    41,   586,
     296,    41,    41,    41,    41,    41,    41,    41,    97,   296,
      41,   296,    99,    40,    35,    35,   296,    13,     7,   296,
     657,   296,   296,   660,   611,     7,    48,   614,   615,    48,
       7,   296,    40,    40,   298,   296,   623,    78,     7,     5,
       7,   628,     7,   630,    41,     7,    41,    41,   635,    41,
       7,   638,   553,     7,   641,   768,   769,     7,    41,   296,
      23,    41,    41,   296,   296,   151,   151,   298,   168,   570,
     151,    35,   168,   298,   298,   576,   663,   578,   665,   580,
      35,   582,     7,   584,   297,     7,     7,     7,     7,    13,
     677,     7,   679,    41,    41,     7,    41,   598,   296,    41,
     687,    41,    13,    41,    41,    41,    41,    41,    41,   151,
     611,    41,    41,   614,   615,   702,   752,   753,   151,     7,
      35,    35,   297,    41,     7,     7,    13,   628,    13,  1065,
     297,    41,    41,   151,   635,   119,    13,    78,   725,   726,
     727,    41,    41,     7,   731,    13,    13,    41,    41,    41,
      41,   297,   297,     7,    13,    41,  1097,    41,  1098,   746,
      41,   748,    41,   750,   545,   752,   753,  1099,   653,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   776,
      -1,   778,    -1,   906,   211,   782,    -1,    -1,    -1,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,   794,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   852,   803,    -1,    -1,    -1,
      -1,   934,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   826,
      -1,    -1,    -1,    -1,   831,   832,    -1,    -1,    -1,    -1,
      -1,    -1,   839,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   848,    -1,   850,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   777,    -1,   779,    -1,
      -1,   782,    -1,    -1,   785,    -1,   787,    -1,   789,    -1,
     791,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     887,   888,   889,   890,   805,    -1,    -1,    -1,   895,    -1,
      -1,    -1,    -1,   814,   901,   902,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   913,    -1,   915,    -1,
      -1,    -1,    -1,    -1,    -1,   836,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   993,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   968,    -1,   970,   971,    -1,    -1,    -1,    -1,   976,
      -1,    -1,    -1,   980,    -1,    -1,   983,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   999,    -1,    -1,    -1,    -1,  1004,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1019,  1020,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1038,    -1,    -1,    -1,    -1,  1043,    -1,    -1,  1046,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   968,  1055,    -1,
      -1,   972,    -1,    -1,    -1,    -1,   977,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1073,    -1,    -1,    -1,
      -1,  1078,    -1,  1080,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1102,  1103,     3,    -1,  1106,
      -1,  1108,  1109,    -1,    10,    11,    -1,    -1,    -1,    -1,
    1117,    -1,  1119,    -1,    -1,    -1,    22,    -1,  1039,    -1,
      -1,    -1,    28,    29,    -1,    31,    -1,    33,    34,    -1,
      36,    37,    -1,    -1,    -1,    -1,    -1,  1144,    44,    -1,
      46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    -1,    95,
      -1,    -1,    98,    99,   100,    -1,   102,   103,   104,   105,
     106,   107,   108,    -1,   110,    -1,    -1,    -1,   114,   115,
     116,   117,   118,    -1,   120,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,   145,
      -1,   147,   148,   149,    -1,    -1,   152,    -1,    -1,    -1,
     156,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,
      -1,   167,    -1,   169,   170,   171,   172,   173,   174,    -1,
     176,   177,   178,   179,   180,   181,    -1,    -1,   184,   185,
     186,   187,   188,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    31,    -1,    33,    34,    -1,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    46,    47,    48,
      -1,    -1,   238,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    93,    -1,    95,    -1,    -1,    98,
      99,   100,    -1,   102,   103,   104,   105,   106,   107,   108,
     296,   110,   298,    -1,    -1,   114,   115,   116,   117,   118,
      -1,   120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,    -1,   145,    -1,   147,   148,
     149,    -1,    -1,   152,    -1,    -1,    -1,   156,    -1,   158,
      -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,    -1,
     169,   170,   171,   172,   173,   174,    -1,   176,   177,   178,
     179,   180,   181,    -1,    -1,   184,   185,   186,   187,   188,
      -1,    -1,    -1,    -1,     7,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   296,   111,   112,
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
     233,   234,   235,    -1,   237,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,    -1,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,     7,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
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
      -1,   232,   233,   234,   235,    -1,   237,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,     9,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    76,    -1,    -1,    79,    80,    81,    82,    -1,
      -1,    -1,    -1,    87,    88,    89,    90,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,   172,    -1,
      -1,   175,    -1,   177,   178,   179,   180,    -1,   182,   183,
      -1,    -1,    -1,    -1,   188,   189,   190,   191,    -1,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,   232,   233,
     234,   235,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,     9,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,    -1,    -1,    -1,    -1,    -1,
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
     237,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,     9,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
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
     200,   201,   202,   203,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     230,    -1,   232,   233,   234,   235,    -1,   237,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,     9,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,    -1,
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
     233,   234,   235,    -1,   237,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,     9,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
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
     196,   197,   198,   199,   200,   201,   202,   203,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,    -1,   232,   233,   234,   235,
      -1,   237,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
      -1,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,     9,    -1,    -1,    -1,    -1,    -1,    -1,
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
     196,   197,   198,   199,   200,   201,   202,   203,   204,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,    -1,   232,   233,   234,   235,
      -1,   237,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
       9,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,     9,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
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
      -1,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,   159,    -1,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,
     172,    -1,    -1,   175,    -1,   177,   178,   179,   180,    -1,
     182,   183,    -1,    -1,    -1,    -1,   188,   189,   190,   191,
      -1,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,
     232,   233,   234,   235,    -1,   237,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,     9,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,    -1,    -1,    -1,
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
     135,   136,   137,    -1,   139,   140,   141,    -1,   143,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,    -1,   159,    -1,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   169,    -1,    -1,   172,    -1,    -1,
     175,    -1,   177,   178,   179,   180,    -1,   182,   183,    -1,
      -1,    -1,    -1,   188,   189,   190,   191,    -1,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   230,    -1,   232,   233,   234,
     235,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,     9,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    76,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    97,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   112,   113,    -1,    -1,    -1,    -1,
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
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,     9,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
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
      -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,   159,    -1,
     161,    -1,    30,    -1,    -1,    -1,    -1,    -1,   169,    -1,
      -1,   172,    -1,    -1,   175,    -1,   177,   178,   179,   180,
      -1,   182,   183,    -1,    -1,    -1,    -1,   188,   189,   190,
     191,    -1,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    96,   230,
      98,   232,   233,   234,   235,    -1,   237,   238,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,    -1,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    -1,    -1,
      -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,   207,
      -1,   209,   210,   211,   212,   213,   214,    -1,   216,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,    -1,
     228,   229,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   425,   426,     0,     3,    10,    11,    22,    28,    29,
      31,    33,    34,    36,    37,    44,    46,    47,    48,    53,
      59,    64,    65,    66,    67,    68,    69,    74,    90,    91,
      92,    93,    95,    98,    99,   100,   102,   103,   104,   105,
     106,   107,   108,   110,   114,   115,   116,   117,   118,   120,
     121,   134,   142,   145,   147,   148,   149,   152,   156,   158,
     161,   162,   167,   169,   170,   171,   172,   173,   174,   176,
     177,   178,   179,   180,   181,   184,   185,   186,   187,   188,
     238,   296,   298,   410,   419,   421,   423,   296,   296,     9,
      30,    40,    56,    57,    58,    73,    76,    79,    87,    88,
      90,    96,    97,    98,    99,   111,   112,   113,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     135,   136,   137,   139,   140,   141,   143,   144,   157,   159,
     161,   169,   172,   175,   177,   178,   179,   180,   182,   183,
     188,   189,   190,   191,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   213,   230,   232,   233,
     234,   235,   237,   238,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   311,
     312,   313,   314,   315,   319,   323,   396,    30,   296,   331,
     332,   333,    32,    37,    77,   337,   338,   339,    26,   230,
     311,   316,   341,   342,   343,    28,    30,    38,    55,    83,
      84,   296,   328,   329,   330,   311,   316,   344,   345,   346,
      30,    42,    43,    91,   347,   348,   349,    48,    49,    50,
      51,    60,   362,   363,   364,   311,   379,   296,   365,   368,
     296,   298,   366,   411,    30,    42,    43,   311,   353,   354,
     355,    30,   356,   357,   358,    30,    91,   359,   360,   361,
     311,   311,   230,    94,    94,   147,    40,    40,   311,   311,
      30,   350,   351,   352,    30,   369,   370,   371,   296,   298,
     367,   311,   147,    74,    74,   147,   298,   316,   311,   296,
      48,    49,   311,   383,    40,   296,   384,   311,   372,   296,
     387,   391,   296,   296,   296,   296,   297,   394,   394,   396,
     311,    48,    49,   101,   109,   163,   164,   165,   399,   401,
       7,   311,   402,     7,   311,   403,   311,   311,   175,   311,
      47,    98,    99,   404,    47,   405,    13,   296,   297,   406,
     408,     4,     6,    13,    20,   150,   309,   416,   418,   422,
       6,     4,     4,   298,    20,    31,    80,    81,    82,    89,
     138,   311,    40,    40,    40,    31,    80,    81,    82,    87,
      88,    89,   317,   318,    20,   141,   159,    40,   203,   237,
      40,   203,   237,   311,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    20,    40,    90,   161,    20,   141,   159,    20,
      20,    20,    20,    20,    20,    20,    40,   192,    40,    40,
     191,   323,    40,    40,    40,    40,    40,    40,    83,   203,
      98,    99,    30,    91,    96,    98,   107,   128,   171,   203,
     207,   209,   210,   211,   212,   213,   214,   216,   217,   219,
     220,   221,   222,   223,   224,   225,   226,   228,   229,   231,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   320,   321,   322,    40,   236,    98,
      99,    20,   278,   275,   278,   279,   285,   279,   285,   278,
      20,   150,   324,     5,     7,     8,     9,    12,    14,    15,
      16,    17,    18,   101,   109,   133,    19,    21,    23,    24,
      27,   311,   316,    30,   311,   316,   311,   316,   311,   316,
     298,    85,    86,   153,   154,   155,   340,    86,   155,   340,
      30,   296,   334,   335,   336,   316,    30,   296,    30,   296,
      30,   296,    30,   296,    30,    30,    31,    38,    42,    43,
      51,    60,    62,    63,    71,    72,    82,   327,    31,    38,
      42,    43,    51,    60,    62,    63,    71,    72,   327,   311,
     316,    35,   311,   316,    52,    52,    59,   106,   147,    20,
      48,   311,   311,     7,   311,   316,   311,   316,    35,    75,
     150,   311,   311,   311,   316,    40,   311,   311,    13,   155,
     311,     7,    31,    80,    81,    82,    89,   127,   138,   146,
     386,   388,   389,     7,   150,   412,   150,     7,    20,    54,
       7,     7,   311,     7,   311,     7,   311,    98,    99,    96,
      97,   311,     5,   407,     5,   424,   311,    13,   417,   413,
      40,   386,   296,   419,   420,   423,   423,    40,    41,    41,
      41,    41,    41,    80,    81,    89,    41,   311,   311,   316,
     311,   316,    40,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   315,    40,   296,    40,    40,    40,   311,   311,
     311,    40,    25,   311,   311,   311,   311,   311,   311,   220,
     220,    96,    98,    96,    98,   227,    40,   311,    40,   325,
     326,    40,   398,   397,   313,   313,   312,   312,   312,   312,
     312,   312,   312,   312,   314,   315,   315,   111,   191,   111,
     323,   323,    35,    35,   311,   316,    78,    78,    78,    78,
     311,   316,    30,    54,   316,    30,   316,    30,   316,    30,
     316,    30,   316,   311,    39,    62,    63,    62,    63,    51,
      60,    51,    60,    40,   316,    39,    62,    63,    62,    63,
      51,    60,    51,    60,    40,   311,   316,   311,   316,   311,
     316,   380,   382,   381,    48,   296,     7,   311,   311,   316,
     311,     7,     7,   311,   316,    75,     7,   311,   106,     7,
     311,    80,    81,    89,   390,    40,    20,   391,   414,   150,
     415,   394,     7,   386,   394,    90,   161,   166,   400,   311,
     311,     7,   296,   423,   311,    40,   311,   395,   311,   392,
      40,   419,   311,   298,   298,   298,   298,   298,    41,    41,
      41,    41,    41,    41,    41,    41,   311,     7,     7,     7,
       7,    41,    41,    41,    41,     7,    41,    41,    41,    41,
      41,     7,     7,    41,    41,    41,     7,   296,    41,   311,
     311,   311,    41,     7,    41,     7,   311,   315,    41,    41,
      41,    41,    41,    41,    97,    99,   311,    41,   311,    40,
     395,   392,   396,   396,   191,   323,   323,   296,   296,   311,
     316,   311,   316,    35,    35,   311,   316,    38,    55,    83,
      84,   316,   316,   316,   316,    35,    54,   311,   311,   316,
     316,   296,   373,   296,   375,   296,   377,   296,    13,   311,
       7,    48,    48,   151,   311,   311,     7,     7,   298,   316,
      78,   296,   311,     7,    40,   298,   385,    40,   395,   296,
     393,   395,   394,     7,   168,   168,   406,     5,   392,     7,
     151,     7,    41,   392,     7,   298,   298,   298,    41,   311,
     311,   311,   311,   311,   311,   311,   323,    41,    41,     7,
       7,   311,   311,    41,    41,   392,   151,    41,   323,   296,
     296,    35,    35,   297,    38,    55,    83,    84,     7,     7,
     374,   376,   378,    13,   311,   316,     7,   311,   311,   316,
      41,    41,   311,   316,   311,     7,    41,   311,   385,     7,
      41,   385,   151,     7,    20,    54,   151,   151,   394,   409,
      41,   395,   392,    13,    41,   311,    41,    41,     7,    41,
       7,    41,    41,    41,    41,    41,   311,   311,    41,    41,
      41,   297,   297,    35,    35,   311,   316,     7,     7,     7,
     311,   311,    13,    13,    41,    41,   119,   311,    13,    78,
      41,   385,    41,   393,     7,   386,   406,    13,   311,    13,
      41,   311,   311,    41,    41,   297,   297,    41,    41,   373,
     375,   377,   311,   311,   311,    41,   311,   311,   393,     7,
     311,   311,    41,    41,    13,   393,   311
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   310,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   312,   312,   312,   313,   313,   314,   314,   314,
     315,   315,   315,   315,   315,   315,   315,   315,   316,   317,
     317,   317,   317,   317,   317,   317,   318,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     321,   321,   321,   321,   321,   321,   321,   321,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   324,   323,
     325,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   326,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   327,   327,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   329,   329,   329,   329,   329,   330,
     330,   331,   331,   332,   332,   333,   333,   334,   334,   335,
     335,   336,   336,   337,   337,   337,   338,   338,   338,   339,
     339,   340,   340,   340,   341,   341,   341,   341,   342,   342,
     342,   343,   343,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   346,   346,   347,   347,   347,   347,   347,
     348,   348,   349,   349,   350,   351,   352,   352,   353,   353,
     354,   354,   355,   355,   356,   357,   358,   358,   359,   359,
     359,   360,   360,   361,   361,   362,   362,   362,   362,   362,
     363,   363,   363,   364,   364,   365,   365,   365,   365,   365,
     365,   366,   366,   367,   367,   368,   369,   370,   371,   371,
     372,   373,   374,   373,   375,   376,   375,   377,   378,   377,
     380,   379,   381,   379,   382,   379,   383,   383,   383,   384,
     384,   385,   385,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   388,   387,   389,   387,   390,   387,   391,
     391,   392,   392,   393,   393,   393,   393,   393,   393,   394,
     394,   394,   394,   394,   394,   394,   394,   395,   395,   396,
     396,   396,   397,   396,   398,   396,   399,   399,   399,   399,
     399,   400,   400,   400,   400,   400,   401,   402,   402,   402,
     403,   403,   403,   404,   404,   404,   404,   405,   405,   406,
     406,   407,   406,   408,   408,   409,   408,   408,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   411,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   412,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   413,   410,   414,   410,   415,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   410,   416,   410,   417,   410,   418,   410,
     410,   410,   410,   419,   420,   419,   422,   421,   424,   423,
     423,   423,   423,   423,   426,   425
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
       1,     1,     5,     1,     1,     2,     5,     4,     1,     2,
       1,     2,     2,     2,     2,     2,     1,     2,     1,     2,
       2,     2,     2,     2,     1,     1,     2,     3,     4,     5,
       4,     3,     5,     4,     4,     3,     4,     5,     4,     3,
       5,     4,     4,     3,     5,     7,     6,     7,     6,     1,
       1,     3,     4,     3,     4,     1,     1,     3,     4,     3,
       4,     1,     1,     2,     4,     4,     2,     4,     4,     1,
       1,     1,     1,     1,     2,     2,     2,     1,     2,     2,
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
       2,     2,     3,     1,     2,     1,     2,     2,     2,     1,
       2,     0,     4,     3,     4,     0,     6,     1,     2,     2,
       3,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     2,     2,     2,     2,     2,     1,
       1,     2,     2,     2,     1,     1,     1,     1,     1,     2,
       3,     2,     2,     1,     1,     2,     2,     2,     1,     2,
       3,     1,     4,     1,     1,     1,     0,     3,     1,     1,
       2,     1,     2,     2,     3,     2,     2,     5,     5,     6,
       1,     2,     0,     6,     2,     2,     2,     5,     8,     2,
       2,     2,     0,     5,     0,     6,     0,     6,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     2,
       2,     2,     2,     1,     2,     1,     1,     8,     8,     8,
      10,     2,     3,     4,     0,     7,     0,     8,     0,     8,
       2,     1,     0,     1,     0,     4,     0,     3,     0,     4,
       1,     3,     1,     3,     0,     2
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
        (yyval.string) = variable_retrieve_or_define( _environment, (yyvsp[-1].string), VT_STRING, 0 )->name;
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

  case 184: /* exponential: MAX OP expr OP_COMMA expr CP  */
#line 786 "src/ugbc.y"
                                   {
        (yyval.string) = maximum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5135 "src-generated/ugbc.tab.c"
    break;

  case 185: /* exponential: MIN OP expr OP_COMMA expr CP  */
#line 789 "src/ugbc.y"
                                   {
        (yyval.string) = minimum( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5143 "src-generated/ugbc.tab.c"
    break;

  case 186: /* exponential: PARAM OP Identifier CP  */
#line 792 "src/ugbc.y"
                             {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 5151 "src-generated/ugbc.tab.c"
    break;

  case 187: /* exponential: PARAM OP_DOLLAR OP Identifier CP  */
#line 795 "src/ugbc.y"
                                       {
        (yyval.string) = param_procedure( _environment, (yyvsp[-1].string) )->name;
    }
#line 5159 "src-generated/ugbc.tab.c"
    break;

  case 188: /* $@3: %empty  */
#line 798 "src/ugbc.y"
                     {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 5167 "src-generated/ugbc.tab.c"
    break;

  case 189: /* exponential: Identifier OSP $@3 values CSP  */
#line 800 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
      (yyval.string) = param_procedure( _environment, (yyvsp[-4].string) )->name;
    }
#line 5176 "src-generated/ugbc.tab.c"
    break;

  case 190: /* exponential: SGN OP expr CP  */
#line 804 "src/ugbc.y"
                     {
        (yyval.string) = sign( _environment, (yyvsp[-1].string) )->name;
    }
#line 5184 "src-generated/ugbc.tab.c"
    break;

  case 191: /* exponential: ABS OP expr CP  */
#line 807 "src/ugbc.y"
                     {
        (yyval.string) = absolute( _environment, (yyvsp[-1].string) )->name;
    }
#line 5192 "src-generated/ugbc.tab.c"
    break;

  case 192: /* exponential: TRUE  */
#line 810 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(true)" )->name;
        variable_store( _environment, (yyval.string), 255 );
    }
#line 5201 "src-generated/ugbc.tab.c"
    break;

  case 193: /* exponential: FALSE  */
#line 814 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(false)" )->name;
        variable_store( _environment, (yyval.string), 0 );
    }
#line 5210 "src-generated/ugbc.tab.c"
    break;

  case 194: /* exponential: COLORS  */
#line 818 "src/ugbc.y"
             {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), 16 );
    }
#line 5219 "src-generated/ugbc.tab.c"
    break;

  case 195: /* exponential: PEN COLORS  */
#line 822 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 5228 "src-generated/ugbc.tab.c"
    break;

  case 196: /* exponential: PEN DEFAULT  */
#line 826 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 5237 "src-generated/ugbc.tab.c"
    break;

  case 197: /* exponential: DEFAULT PEN  */
#line 830 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_WHITE );
    }
#line 5246 "src-generated/ugbc.tab.c"
    break;

  case 198: /* exponential: PAPER COLORS  */
#line 834 "src/ugbc.y"
                   {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_COUNT );
    }
#line 5255 "src-generated/ugbc.tab.c"
    break;

  case 199: /* exponential: PAPER DEFAULT  */
#line 838 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 5264 "src-generated/ugbc.tab.c"
    break;

  case 200: /* exponential: DEFAULT PAPER  */
#line 842 "src/ugbc.y"
                    {
        (yyval.string) = variable_temporary( _environment, VT_COLOR, "(COLORS)" )->name;
        variable_store( _environment, (yyval.string), COLOR_BLACK );
    }
#line 5273 "src-generated/ugbc.tab.c"
    break;

  case 201: /* exponential: WIDTH  */
#line 846 "src/ugbc.y"
            {
        (yyval.string) = screen_get_width( _environment )->name;
    }
#line 5281 "src-generated/ugbc.tab.c"
    break;

  case 202: /* exponential: HEIGHT  */
#line 849 "src/ugbc.y"
             {
        (yyval.string) = screen_get_height( _environment )->name;
    }
#line 5289 "src-generated/ugbc.tab.c"
    break;

  case 203: /* exponential: TIMER  */
#line 852 "src/ugbc.y"
            {
        (yyval.string) = get_timer( _environment )->name;
    }
#line 5297 "src-generated/ugbc.tab.c"
    break;

  case 204: /* exponential: PEN OP_DOLLAR OP expr CP  */
#line 855 "src/ugbc.y"
                               {
        (yyval.string) = text_get_pen( _environment, (yyvsp[-1].string) )->name;
    }
#line 5305 "src-generated/ugbc.tab.c"
    break;

  case 205: /* exponential: PAPER OP_DOLLAR OP expr CP  */
#line 858 "src/ugbc.y"
                                 {
        (yyval.string) = text_get_paper( _environment, (yyvsp[-1].string) )->name;
    }
#line 5313 "src-generated/ugbc.tab.c"
    break;

  case 206: /* exponential: CMOVE OP_DOLLAR OP expr OP_COMMA expr CP  */
#line 861 "src/ugbc.y"
                                               {
        (yyval.string) = text_get_cmove( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5321 "src-generated/ugbc.tab.c"
    break;

  case 207: /* exponential: CUP OP_DOLLAR  */
#line 864 "src/ugbc.y"
                    {
        (yyval.string) = text_get_cmove_direct( _environment, 0, -1 )->name;
    }
#line 5329 "src-generated/ugbc.tab.c"
    break;

  case 208: /* exponential: CDOWN OP_DOLLAR  */
#line 867 "src/ugbc.y"
                      {
        (yyval.string) = text_get_cmove_direct( _environment, 0, 1 )->name;
    }
#line 5337 "src-generated/ugbc.tab.c"
    break;

  case 209: /* exponential: CLEFT OP_DOLLAR  */
#line 870 "src/ugbc.y"
                      {
        (yyval.string) = text_get_cmove_direct( _environment, -1, 0 )->name;
    }
#line 5345 "src-generated/ugbc.tab.c"
    break;

  case 210: /* exponential: CRIGHT OP_DOLLAR  */
#line 873 "src/ugbc.y"
                       {
        (yyval.string) = text_get_cmove_direct( _environment, 1, 0 )->name;
    }
#line 5353 "src-generated/ugbc.tab.c"
    break;

  case 211: /* exponential: AT OP_DOLLAR OP expr OP_COMMA expr CP  */
#line 876 "src/ugbc.y"
                                            {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5361 "src-generated/ugbc.tab.c"
    break;

  case 212: /* exponential: LOCATE OP_DOLLAR OP expr OP_COMMA expr CP  */
#line 879 "src/ugbc.y"
                                                {
        (yyval.string) = text_get_at( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5369 "src-generated/ugbc.tab.c"
    break;

  case 213: /* exponential: TAB OP_DOLLAR  */
#line 882 "src/ugbc.y"
                    {
        (yyval.string) = text_get_tab( _environment )->name;
    }
#line 5377 "src-generated/ugbc.tab.c"
    break;

  case 214: /* exponential: XCURS  */
#line 885 "src/ugbc.y"
            {
        (yyval.string) = text_get_xcurs( _environment )->name;
    }
#line 5385 "src-generated/ugbc.tab.c"
    break;

  case 215: /* exponential: YCURS  */
#line 888 "src/ugbc.y"
            {
        (yyval.string) = text_get_ycurs( _environment )->name;
    }
#line 5393 "src-generated/ugbc.tab.c"
    break;

  case 216: /* exponential: TEXTADDRESS  */
#line 891 "src/ugbc.y"
                  {
        (yyval.string) = strdup( "TEXTADDRESS" );
    }
#line 5401 "src-generated/ugbc.tab.c"
    break;

  case 217: /* exponential: JOY OP expr CP  */
#line 894 "src/ugbc.y"
                     {
        (yyval.string) = joy( _environment, (yyvsp[-1].string) )->name;
    }
#line 5409 "src-generated/ugbc.tab.c"
    break;

  case 218: /* exponential: JUP OP expr CP  */
#line 897 "src/ugbc.y"
                     {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_UP )->name;
    }
#line 5417 "src-generated/ugbc.tab.c"
    break;

  case 219: /* exponential: JDOWN OP expr CP  */
#line 900 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_DOWN )->name;
    }
#line 5425 "src-generated/ugbc.tab.c"
    break;

  case 220: /* exponential: JLEFT OP expr CP  */
#line 903 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_LEFT )->name;
    }
#line 5433 "src-generated/ugbc.tab.c"
    break;

  case 221: /* exponential: JRIGHT OP expr CP  */
#line 906 "src/ugbc.y"
                        {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_RIGHT )->name;
    }
#line 5441 "src-generated/ugbc.tab.c"
    break;

  case 222: /* exponential: JFIRE OP expr CP  */
#line 909 "src/ugbc.y"
                       {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_FIRE )->name;
    }
#line 5449 "src-generated/ugbc.tab.c"
    break;

  case 223: /* exponential: FIRE OP expr CP  */
#line 912 "src/ugbc.y"
                      {
        (yyval.string) = joy_direction( _environment, (yyvsp[-1].string), JOY_FIRE )->name;
    }
#line 5457 "src-generated/ugbc.tab.c"
    break;

  case 224: /* exponential: JOY COUNT  */
#line 915 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, (yyval.string), JOY_COUNT );
    }
#line 5466 "src-generated/ugbc.tab.c"
    break;

  case 225: /* exponential: JOYCOUNT  */
#line 919 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(JOYCOUNT)" )->name;
        variable_store( _environment, (yyval.string), JOY_COUNT );
    }
#line 5475 "src-generated/ugbc.tab.c"
    break;

  case 226: /* exponential: BIT OP expr OP_COMMA expr CP  */
#line 923 "src/ugbc.y"
                                   {
        (yyval.string) = variable_bit( _environment, (yyvsp[-3].string), (yyvsp[-1].string) )->name;
    }
#line 5483 "src-generated/ugbc.tab.c"
    break;

  case 227: /* exponential: UP  */
#line 926 "src/ugbc.y"
         {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(UP)" )->name;
        variable_store( _environment, (yyval.string), JOY_UP );
    }
#line 5492 "src-generated/ugbc.tab.c"
    break;

  case 228: /* exponential: DOWN  */
#line 930 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(DOWN)" )->name;
        variable_store( _environment, (yyval.string), JOY_DOWN );
    }
#line 5501 "src-generated/ugbc.tab.c"
    break;

  case 229: /* exponential: LEFT  */
#line 934 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(LEFT)" )->name;
        variable_store( _environment, (yyval.string), JOY_LEFT );
    }
#line 5510 "src-generated/ugbc.tab.c"
    break;

  case 230: /* exponential: RIGHT  */
#line 938 "src/ugbc.y"
            {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(RIGHT)" )->name;
        variable_store( _environment, (yyval.string), JOY_RIGHT );
    }
#line 5519 "src-generated/ugbc.tab.c"
    break;

  case 231: /* exponential: FIRE  */
#line 942 "src/ugbc.y"
           {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(FIRE)" )->name;
        variable_store( _environment, (yyval.string), JOY_FIRE );
    }
#line 5528 "src-generated/ugbc.tab.c"
    break;

  case 232: /* exponential: INPUT OP_DOLLAR OP expr CP  */
#line 946 "src/ugbc.y"
                                 {
        (yyval.string) = input_string( _environment, (yyvsp[-1].string) )->name;
    }
#line 5536 "src-generated/ugbc.tab.c"
    break;

  case 233: /* exponential: INKEY  */
#line 949 "src/ugbc.y"
            {
        (yyval.string) = inkey( _environment )->name;
    }
#line 5544 "src-generated/ugbc.tab.c"
    break;

  case 234: /* exponential: SCANCODE  */
#line 952 "src/ugbc.y"
               {
        (yyval.string) = scancode( _environment )->name;
    }
#line 5552 "src-generated/ugbc.tab.c"
    break;

  case 235: /* exponential: SCAN CODE  */
#line 955 "src/ugbc.y"
                {
        (yyval.string) = scancode( _environment )->name;
    }
#line 5560 "src-generated/ugbc.tab.c"
    break;

  case 236: /* exponential: KEY STATE OP expr CP  */
#line 958 "src/ugbc.y"
                           {
        (yyval.string) = key_state( _environment, (yyvsp[-1].string) )->name;
    }
#line 5568 "src-generated/ugbc.tab.c"
    break;

  case 237: /* exponential: KEYSTATE OP expr CP  */
#line 961 "src/ugbc.y"
                          {
        (yyval.string) = key_state( _environment, (yyvsp[-1].string) )->name;
    }
#line 5576 "src-generated/ugbc.tab.c"
    break;

  case 238: /* exponential: SCANSHIFT  */
#line 964 "src/ugbc.y"
                {
        (yyval.string) = scanshift( _environment )->name;
    }
#line 5584 "src-generated/ugbc.tab.c"
    break;

  case 239: /* exponential: SCAN SHIFT  */
#line 967 "src/ugbc.y"
                 {
        (yyval.string) = scanshift( _environment )->name;
    }
#line 5592 "src-generated/ugbc.tab.c"
    break;

  case 240: /* exponential: KEYSHIFT  */
#line 970 "src/ugbc.y"
               {
        (yyval.string) = keyshift( _environment )->name;
    }
#line 5600 "src-generated/ugbc.tab.c"
    break;

  case 241: /* exponential: KEY SHIFT  */
#line 973 "src/ugbc.y"
                {
        (yyval.string) = keyshift( _environment )->name;
    }
#line 5608 "src-generated/ugbc.tab.c"
    break;

  case 242: /* exponential: LEFT SHIFT  */
#line 976 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_LEFT );
    }
#line 5617 "src-generated/ugbc.tab.c"
    break;

  case 243: /* exponential: SHIFT LEFT  */
#line 980 "src/ugbc.y"
                 {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_LEFT );
    }
#line 5626 "src-generated/ugbc.tab.c"
    break;

  case 244: /* exponential: RIGHT SHIFT  */
#line 984 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_RIGHT );
    }
#line 5635 "src-generated/ugbc.tab.c"
    break;

  case 245: /* exponential: SHIFT RIGHT  */
#line 988 "src/ugbc.y"
                  {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_RIGHT );
    }
#line 5644 "src-generated/ugbc.tab.c"
    break;

  case 246: /* exponential: CAPSLOCK  */
#line 992 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT CAPSLOCK)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_CAPSLOCK );
    }
#line 5653 "src-generated/ugbc.tab.c"
    break;

  case 247: /* exponential: CAPS LOCK  */
#line 996 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT CAPSLOCK)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_CAPSLOCK );
    }
#line 5662 "src-generated/ugbc.tab.c"
    break;

  case 248: /* exponential: CONTROL  */
#line 1000 "src/ugbc.y"
              {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT CONTROL)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_CONTROL );
    }
#line 5671 "src-generated/ugbc.tab.c"
    break;

  case 249: /* exponential: LEFT ALT  */
#line 1004 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT ALT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_LEFT_ALT );
    }
#line 5680 "src-generated/ugbc.tab.c"
    break;

  case 250: /* exponential: ALT LEFT  */
#line 1008 "src/ugbc.y"
               {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT LEFT ALT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_LEFT_ALT );
    }
#line 5689 "src-generated/ugbc.tab.c"
    break;

  case 251: /* exponential: RIGHT ALT  */
#line 1012 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT ALT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_RIGHT_ALT );
    }
#line 5698 "src-generated/ugbc.tab.c"
    break;

  case 252: /* exponential: ALT RIGHT  */
#line 1016 "src/ugbc.y"
                {
        (yyval.string) = variable_temporary( _environment, VT_BYTE, "(SHIFT RIGHT ALT)" )->name;
        variable_store( _environment, (yyval.string), SHIFT_RIGHT_ALT );
    }
#line 5707 "src-generated/ugbc.tab.c"
    break;

  case 253: /* exponential: KEY key_scancode_definition  */
#line 1020 "src/ugbc.y"
                                  {
        (yyval.string) = (yyvsp[0].string);
    }
#line 5715 "src-generated/ugbc.tab.c"
    break;

  case 256: /* bank_definition_simple: AT direct_integer  */
#line 1028 "src/ugbc.y"
                    {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 5723 "src-generated/ugbc.tab.c"
    break;

  case 257: /* bank_definition_simple: Identifier AT direct_integer  */
#line 1031 "src/ugbc.y"
                                 {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 5731 "src-generated/ugbc.tab.c"
    break;

  case 258: /* bank_definition_simple: AT direct_integer AS DATA  */
#line 1034 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 5739 "src-generated/ugbc.tab.c"
    break;

  case 259: /* bank_definition_simple: Identifier AT direct_integer AS DATA  */
#line 1037 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), NULL );
  }
#line 5747 "src-generated/ugbc.tab.c"
    break;

  case 260: /* bank_definition_simple: DATA Identifier AT direct_integer  */
#line 1040 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 5755 "src-generated/ugbc.tab.c"
    break;

  case 261: /* bank_definition_simple: DATA AT direct_integer  */
#line 1043 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_DATA, (yyvsp[0].integer), NULL );
  }
#line 5763 "src-generated/ugbc.tab.c"
    break;

  case 262: /* bank_definition_simple: Identifier AT direct_integer AS CODE  */
#line 1047 "src/ugbc.y"
                                         {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 5771 "src-generated/ugbc.tab.c"
    break;

  case 263: /* bank_definition_simple: AT direct_integer AS CODE  */
#line 1050 "src/ugbc.y"
                              {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[-2].integer), NULL );
  }
#line 5779 "src-generated/ugbc.tab.c"
    break;

  case 264: /* bank_definition_simple: CODE Identifier AT direct_integer  */
#line 1053 "src/ugbc.y"
                                      {
      bank_define( _environment, (yyvsp[-2].string), BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 5787 "src-generated/ugbc.tab.c"
    break;

  case 265: /* bank_definition_simple: CODE AT direct_integer  */
#line 1056 "src/ugbc.y"
                           {
      bank_define( _environment, NULL, BT_CODE, (yyvsp[0].integer), NULL );
  }
#line 5795 "src-generated/ugbc.tab.c"
    break;

  case 266: /* bank_definition_simple: AT direct_integer AS VARIABLES  */
#line 1060 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 5803 "src-generated/ugbc.tab.c"
    break;

  case 267: /* bank_definition_simple: Identifier AT direct_integer AS VARIABLES  */
#line 1063 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_VARIABLES, (yyvsp[-2].integer), NULL );
  }
#line 5811 "src-generated/ugbc.tab.c"
    break;

  case 268: /* bank_definition_simple: VARIABLES Identifier AT direct_integer  */
#line 1066 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 5819 "src-generated/ugbc.tab.c"
    break;

  case 269: /* bank_definition_simple: VARIABLES AT direct_integer  */
#line 1069 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_VARIABLES, (yyvsp[0].integer), NULL );
  }
#line 5827 "src-generated/ugbc.tab.c"
    break;

  case 270: /* bank_definition_simple: Identifier AT direct_integer AS TEMPORARY  */
#line 1073 "src/ugbc.y"
                                              {
      bank_define( _environment, (yyvsp[-4].string), BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 5835 "src-generated/ugbc.tab.c"
    break;

  case 271: /* bank_definition_simple: AT direct_integer AS TEMPORARY  */
#line 1076 "src/ugbc.y"
                                   {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[-2].integer), NULL );
  }
#line 5843 "src-generated/ugbc.tab.c"
    break;

  case 272: /* bank_definition_simple: TEMPORARY Identifier AT direct_integer  */
#line 1079 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-2].string), BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 5851 "src-generated/ugbc.tab.c"
    break;

  case 273: /* bank_definition_simple: TEMPORARY AT direct_integer  */
#line 1082 "src/ugbc.y"
                                {
      bank_define( _environment, NULL, BT_TEMPORARY, (yyvsp[0].integer), NULL );
  }
#line 5859 "src-generated/ugbc.tab.c"
    break;

  case 274: /* bank_definition_with_payload: Identifier AT direct_integer WITH String  */
#line 1088 "src/ugbc.y"
                                           {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 5867 "src-generated/ugbc.tab.c"
    break;

  case 275: /* bank_definition_with_payload: Identifier AT direct_integer AS DATA WITH String  */
#line 1091 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_DATA, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 5875 "src-generated/ugbc.tab.c"
    break;

  case 276: /* bank_definition_with_payload: DATA Identifier AT direct_integer WITH String  */
#line 1094 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_DATA, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 5883 "src-generated/ugbc.tab.c"
    break;

  case 277: /* bank_definition_with_payload: Identifier AT direct_integer AS CODE WITH String  */
#line 1097 "src/ugbc.y"
                                                     {
      bank_define( _environment, (yyvsp[-6].string), BT_CODE, (yyvsp[-4].integer), (yyvsp[0].string) );
  }
#line 5891 "src-generated/ugbc.tab.c"
    break;

  case 278: /* bank_definition_with_payload: CODE Identifier AT direct_integer WITH String  */
#line 1100 "src/ugbc.y"
                                                  {
      bank_define( _environment, (yyvsp[-4].string), BT_CODE, (yyvsp[-2].integer), (yyvsp[0].string) );
  }
#line 5899 "src-generated/ugbc.tab.c"
    break;

  case 281: /* raster_definition_simple: Identifier AT direct_integer  */
#line 1109 "src/ugbc.y"
                                 {
      raster_at( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );
    }
#line 5907 "src-generated/ugbc.tab.c"
    break;

  case 282: /* raster_definition_simple: AT direct_integer WITH Identifier  */
#line 1112 "src/ugbc.y"
                                      {
      raster_at( _environment, (yyvsp[0].string), (yyvsp[-2].integer) );
    }
#line 5915 "src-generated/ugbc.tab.c"
    break;

  case 283: /* raster_definition_expression: Identifier AT expr  */
#line 1117 "src/ugbc.y"
                       {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5923 "src-generated/ugbc.tab.c"
    break;

  case 284: /* raster_definition_expression: AT expr WITH Identifier  */
#line 1120 "src/ugbc.y"
                            {
      raster_at_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5931 "src-generated/ugbc.tab.c"
    break;

  case 287: /* next_raster_definition_simple: Identifier AT direct_integer  */
#line 1129 "src/ugbc.y"
                                 {
      next_raster_at_with( _environment, (yyvsp[0].integer), (yyvsp[-2].string) );
    }
#line 5939 "src-generated/ugbc.tab.c"
    break;

  case 288: /* next_raster_definition_simple: AT direct_integer WITH Identifier  */
#line 1132 "src/ugbc.y"
                                      {
      next_raster_at_with( _environment, (yyvsp[-2].integer), (yyvsp[0].string) );
    }
#line 5947 "src-generated/ugbc.tab.c"
    break;

  case 289: /* next_raster_definition_expression: Identifier AT expr  */
#line 1137 "src/ugbc.y"
                       {
      next_raster_at_with_var( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
    }
#line 5955 "src-generated/ugbc.tab.c"
    break;

  case 290: /* next_raster_definition_expression: AT expr WITH Identifier  */
#line 1140 "src/ugbc.y"
                            {
      next_raster_at_with_var( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 5963 "src-generated/ugbc.tab.c"
    break;

  case 293: /* color_definition_simple: BORDER direct_integer  */
#line 1149 "src/ugbc.y"
                          {
      color_border( _environment, (yyvsp[0].integer) );
  }
#line 5971 "src-generated/ugbc.tab.c"
    break;

  case 294: /* color_definition_simple: BACKGROUND direct_integer TO direct_integer  */
#line 1152 "src/ugbc.y"
                                                {
      color_background( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 5979 "src-generated/ugbc.tab.c"
    break;

  case 295: /* color_definition_simple: SPRITE direct_integer TO direct_integer  */
#line 1155 "src/ugbc.y"
                                            {
      color_sprite( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 5987 "src-generated/ugbc.tab.c"
    break;

  case 296: /* color_definition_expression: BORDER expr  */
#line 1160 "src/ugbc.y"
                {
      color_border_var( _environment, (yyvsp[0].string) );
  }
#line 5995 "src-generated/ugbc.tab.c"
    break;

  case 297: /* color_definition_expression: BACKGROUND expr TO expr  */
#line 1163 "src/ugbc.y"
                            {
      color_background_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 6003 "src-generated/ugbc.tab.c"
    break;

  case 298: /* color_definition_expression: SPRITE expr TO expr  */
#line 1166 "src/ugbc.y"
                        {
      color_sprite_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 6011 "src-generated/ugbc.tab.c"
    break;

  case 304: /* wait_definition_simple: direct_integer CYCLES  */
#line 1180 "src/ugbc.y"
                            {
      wait_cycles( _environment, (yyvsp[-1].integer) );
    }
#line 6019 "src-generated/ugbc.tab.c"
    break;

  case 305: /* wait_definition_simple: direct_integer TICKS  */
#line 1183 "src/ugbc.y"
                           {
      wait_ticks( _environment, (yyvsp[-1].integer) );
    }
#line 6027 "src-generated/ugbc.tab.c"
    break;

  case 306: /* wait_definition_simple: direct_integer milliseconds  */
#line 1186 "src/ugbc.y"
                                  {
      wait_milliseconds( _environment, (yyvsp[-1].integer) );
    }
#line 6035 "src-generated/ugbc.tab.c"
    break;

  case 307: /* wait_definition_simple: KEY  */
#line 1189 "src/ugbc.y"
          {
      wait_key( _environment );
    }
#line 6043 "src-generated/ugbc.tab.c"
    break;

  case 308: /* wait_definition_expression: expr CYCLES  */
#line 1195 "src/ugbc.y"
                  {
      wait_cycles_var( _environment, (yyvsp[-1].string) );
    }
#line 6051 "src-generated/ugbc.tab.c"
    break;

  case 309: /* wait_definition_expression: expr TICKS  */
#line 1198 "src/ugbc.y"
                 {
      wait_ticks_var( _environment, (yyvsp[-1].string) );
    }
#line 6059 "src-generated/ugbc.tab.c"
    break;

  case 310: /* wait_definition_expression: expr milliseconds  */
#line 1201 "src/ugbc.y"
                        {
      wait_milliseconds_var( _environment, (yyvsp[-1].string) );
    }
#line 6067 "src-generated/ugbc.tab.c"
    break;

  case 313: /* sprite_definition_simple: direct_integer DATA FROM direct_integer  */
#line 1211 "src/ugbc.y"
                                            {
      sprite_data_from( _environment, (yyvsp[-3].integer), (yyvsp[0].integer) );
  }
#line 6075 "src-generated/ugbc.tab.c"
    break;

  case 314: /* sprite_definition_simple: direct_integer MULTICOLOR  */
#line 1214 "src/ugbc.y"
                              {
      sprite_multicolor( _environment, (yyvsp[-1].integer) );
  }
#line 6083 "src-generated/ugbc.tab.c"
    break;

  case 315: /* sprite_definition_simple: direct_integer MONOCOLOR  */
#line 1217 "src/ugbc.y"
                             {
      sprite_monocolor( _environment, (yyvsp[-1].integer) );
  }
#line 6091 "src-generated/ugbc.tab.c"
    break;

  case 316: /* sprite_definition_simple: direct_integer COLOR direct_integer  */
#line 1220 "src/ugbc.y"
                                        {
      sprite_color( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 6099 "src-generated/ugbc.tab.c"
    break;

  case 317: /* sprite_definition_simple: direct_integer position OP direct_integer OP_COMMA direct_integer CP  */
#line 1223 "src/ugbc.y"
                                                                         {
      sprite_position( _environment, (yyvsp[-6].integer), (yyvsp[-3].integer), (yyvsp[-1].integer) );
  }
#line 6107 "src-generated/ugbc.tab.c"
    break;

  case 318: /* sprite_definition_simple: direct_integer ENABLE  */
#line 1226 "src/ugbc.y"
                          {
      sprite_enable( _environment, (yyvsp[-1].integer) );
  }
#line 6115 "src-generated/ugbc.tab.c"
    break;

  case 319: /* sprite_definition_simple: direct_integer DISABLE  */
#line 1229 "src/ugbc.y"
                           {
      sprite_disable( _environment, (yyvsp[-1].integer) );
  }
#line 6123 "src-generated/ugbc.tab.c"
    break;

  case 320: /* sprite_definition_simple: direct_integer EXPAND VERTICAL  */
#line 1232 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 6131 "src-generated/ugbc.tab.c"
    break;

  case 321: /* sprite_definition_simple: direct_integer COMPRESS VERTICAL  */
#line 1235 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 6139 "src-generated/ugbc.tab.c"
    break;

  case 322: /* sprite_definition_simple: direct_integer VERTICAL EXPAND  */
#line 1238 "src/ugbc.y"
                                   {
      sprite_expand_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 6147 "src-generated/ugbc.tab.c"
    break;

  case 323: /* sprite_definition_simple: direct_integer VERTICAL COMPRESS  */
#line 1241 "src/ugbc.y"
                                     {
      sprite_compress_vertical( _environment, (yyvsp[-2].integer) );
  }
#line 6155 "src-generated/ugbc.tab.c"
    break;

  case 324: /* sprite_definition_simple: direct_integer EXPAND HORIZONTAL  */
#line 1244 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 6163 "src-generated/ugbc.tab.c"
    break;

  case 325: /* sprite_definition_simple: direct_integer COMPRESS HORIZONTAL  */
#line 1247 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 6171 "src-generated/ugbc.tab.c"
    break;

  case 326: /* sprite_definition_simple: direct_integer HORIZONTAL EXPAND  */
#line 1250 "src/ugbc.y"
                                     {
      sprite_expand_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 6179 "src-generated/ugbc.tab.c"
    break;

  case 327: /* sprite_definition_simple: direct_integer HORIZONTAL COMPRESS  */
#line 1253 "src/ugbc.y"
                                       {
      sprite_compress_horizontal( _environment, (yyvsp[-2].integer) );
  }
#line 6187 "src-generated/ugbc.tab.c"
    break;

  case 328: /* sprite_definition_expression: expr DATA FROM expr  */
#line 1258 "src/ugbc.y"
                        {
      sprite_data_from_vars( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 6195 "src-generated/ugbc.tab.c"
    break;

  case 329: /* sprite_definition_expression: expr MULTICOLOR  */
#line 1261 "src/ugbc.y"
                    {
      sprite_multicolor_var( _environment, (yyvsp[-1].string) );
  }
#line 6203 "src-generated/ugbc.tab.c"
    break;

  case 330: /* sprite_definition_expression: expr MONOCOLOR  */
#line 1264 "src/ugbc.y"
                   {
      sprite_monocolor_var( _environment, (yyvsp[-1].string) );
  }
#line 6211 "src-generated/ugbc.tab.c"
    break;

  case 331: /* sprite_definition_expression: expr COLOR expr  */
#line 1267 "src/ugbc.y"
                    {
      sprite_color_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 6219 "src-generated/ugbc.tab.c"
    break;

  case 332: /* sprite_definition_expression: expr position OP expr OP_COMMA expr CP  */
#line 1270 "src/ugbc.y"
                                           {
      sprite_position_vars( _environment, (yyvsp[-6].string), (yyvsp[-3].string), (yyvsp[-1].string) );
  }
#line 6227 "src-generated/ugbc.tab.c"
    break;

  case 333: /* sprite_definition_expression: expr ENABLE  */
#line 1273 "src/ugbc.y"
                {
      sprite_enable_var( _environment, (yyvsp[-1].string) );
  }
#line 6235 "src-generated/ugbc.tab.c"
    break;

  case 334: /* sprite_definition_expression: expr DISABLE  */
#line 1276 "src/ugbc.y"
                 {
      sprite_disable_var( _environment, (yyvsp[-1].string) );
  }
#line 6243 "src-generated/ugbc.tab.c"
    break;

  case 335: /* sprite_definition_expression: expr EXPAND VERTICAL  */
#line 1279 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 6251 "src-generated/ugbc.tab.c"
    break;

  case 336: /* sprite_definition_expression: expr COMPRESS VERTICAL  */
#line 1282 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 6259 "src-generated/ugbc.tab.c"
    break;

  case 337: /* sprite_definition_expression: expr VERTICAL EXPAND  */
#line 1285 "src/ugbc.y"
                         {
      sprite_expand_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 6267 "src-generated/ugbc.tab.c"
    break;

  case 338: /* sprite_definition_expression: expr VERTICAL COMPRESS  */
#line 1288 "src/ugbc.y"
                           {
      sprite_compress_vertical_var( _environment, (yyvsp[-2].string) );
  }
#line 6275 "src-generated/ugbc.tab.c"
    break;

  case 339: /* sprite_definition_expression: expr EXPAND HORIZONTAL  */
#line 1291 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 6283 "src-generated/ugbc.tab.c"
    break;

  case 340: /* sprite_definition_expression: expr COMPRESS HORIZONTAL  */
#line 1294 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 6291 "src-generated/ugbc.tab.c"
    break;

  case 341: /* sprite_definition_expression: expr HORIZONTAL EXPAND  */
#line 1297 "src/ugbc.y"
                           {
      sprite_expand_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 6299 "src-generated/ugbc.tab.c"
    break;

  case 342: /* sprite_definition_expression: expr HORIZONTAL COMPRESS  */
#line 1300 "src/ugbc.y"
                             {
      sprite_compress_horizontal_var( _environment, (yyvsp[-2].string) );
  }
#line 6307 "src-generated/ugbc.tab.c"
    break;

  case 345: /* bitmap_definition_simple: AT direct_integer  */
#line 1309 "src/ugbc.y"
                      {
      bitmap_at( _environment, (yyvsp[0].integer) );
  }
#line 6315 "src-generated/ugbc.tab.c"
    break;

  case 346: /* bitmap_definition_simple: ENABLE  */
#line 1312 "src/ugbc.y"
           {
      bitmap_enable( _environment );
  }
#line 6323 "src-generated/ugbc.tab.c"
    break;

  case 347: /* bitmap_definition_simple: DISABLE  */
#line 1315 "src/ugbc.y"
            {
      bitmap_disable( _environment );
  }
#line 6331 "src-generated/ugbc.tab.c"
    break;

  case 348: /* bitmap_definition_simple: CLEAR  */
#line 1318 "src/ugbc.y"
          {
      bitmap_clear( _environment );
  }
#line 6339 "src-generated/ugbc.tab.c"
    break;

  case 349: /* bitmap_definition_simple: CLEAR WITH direct_integer  */
#line 1321 "src/ugbc.y"
                              {
      bitmap_clear_with( _environment, (yyvsp[0].integer) );
  }
#line 6347 "src-generated/ugbc.tab.c"
    break;

  case 350: /* bitmap_definition_expression: AT expr  */
#line 1327 "src/ugbc.y"
            {
      bitmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 6355 "src-generated/ugbc.tab.c"
    break;

  case 351: /* bitmap_definition_expression: CLEAR WITH expr  */
#line 1330 "src/ugbc.y"
                    {
      bitmap_clear_with_vars( _environment, (yyvsp[0].string) );
  }
#line 6363 "src-generated/ugbc.tab.c"
    break;

  case 354: /* textmap_definition_simple: AT direct_integer  */
#line 1340 "src/ugbc.y"
                      {
      textmap_at( _environment, (yyvsp[0].integer) );
  }
#line 6371 "src-generated/ugbc.tab.c"
    break;

  case 355: /* textmap_definition_expression: AT expr  */
#line 1345 "src/ugbc.y"
            {
      textmap_at_var( _environment, (yyvsp[0].string) );
  }
#line 6379 "src-generated/ugbc.tab.c"
    break;

  case 358: /* text_definition_simple: ENABLE  */
#line 1354 "src/ugbc.y"
           {
      text_enable( _environment );
  }
#line 6387 "src-generated/ugbc.tab.c"
    break;

  case 359: /* text_definition_simple: DISABLE  */
#line 1357 "src/ugbc.y"
            {
      text_disable( _environment );
  }
#line 6395 "src-generated/ugbc.tab.c"
    break;

  case 360: /* text_definition_expression: AT expr OP_COMMA expr OP_COMMA expr  */
#line 1362 "src/ugbc.y"
                                         {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 6403 "src-generated/ugbc.tab.c"
    break;

  case 361: /* text_definition_expression: expr OP_COMMA expr OP_COMMA expr  */
#line 1365 "src/ugbc.y"
                                      {
       text_at( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
   }
#line 6411 "src-generated/ugbc.tab.c"
    break;

  case 364: /* tiles_definition_simple: AT direct_integer  */
#line 1374 "src/ugbc.y"
                      {
      tiles_at( _environment, (yyvsp[0].integer) );
  }
#line 6419 "src-generated/ugbc.tab.c"
    break;

  case 365: /* tiles_definition_expression: AT expr  */
#line 1379 "src/ugbc.y"
            {
      tiles_at_var( _environment, (yyvsp[0].string) );
  }
#line 6427 "src-generated/ugbc.tab.c"
    break;

  case 368: /* colormap_definition_simple: AT direct_integer  */
#line 1388 "src/ugbc.y"
                      {
      colormap_at( _environment, (yyvsp[0].integer) );
  }
#line 6435 "src-generated/ugbc.tab.c"
    break;

  case 369: /* colormap_definition_simple: CLEAR  */
#line 1391 "src/ugbc.y"
          {
      colormap_clear( _environment );
  }
#line 6443 "src-generated/ugbc.tab.c"
    break;

  case 370: /* colormap_definition_simple: CLEAR WITH direct_integer ON direct_integer  */
#line 1394 "src/ugbc.y"
                                                {
      colormap_clear_with( _environment, (yyvsp[-2].integer), (yyvsp[0].integer) );
  }
#line 6451 "src-generated/ugbc.tab.c"
    break;

  case 371: /* colormap_definition_expression: AT expr  */
#line 1399 "src/ugbc.y"
            {
      colormap_at_var( _environment, (yyvsp[0].string) );
  }
#line 6459 "src-generated/ugbc.tab.c"
    break;

  case 372: /* colormap_definition_expression: CLEAR WITH expr ON expr  */
#line 1402 "src/ugbc.y"
                            {
      colormap_clear_with_vars( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
  }
#line 6467 "src-generated/ugbc.tab.c"
    break;

  case 375: /* screen_definition_simple: ON  */
#line 1412 "src/ugbc.y"
       {   
      screen_on( _environment );
  }
#line 6475 "src-generated/ugbc.tab.c"
    break;

  case 376: /* screen_definition_simple: OFF  */
#line 1415 "src/ugbc.y"
        {
      screen_off( _environment );
  }
#line 6483 "src-generated/ugbc.tab.c"
    break;

  case 377: /* screen_definition_simple: ROWS direct_integer  */
#line 1418 "src/ugbc.y"
                        {
      screen_rows( _environment, (yyvsp[0].integer) );
  }
#line 6491 "src-generated/ugbc.tab.c"
    break;

  case 378: /* screen_definition_simple: VERTICAL SCROLL direct_integer  */
#line 1421 "src/ugbc.y"
                                   {
      screen_vertical_scroll( _environment, (yyvsp[0].integer) );
  }
#line 6499 "src-generated/ugbc.tab.c"
    break;

  case 379: /* screen_definition_simple: HORIZONTAL SCROLL direct_integer  */
#line 1424 "src/ugbc.y"
                                     {
      screen_horizontal_scroll( _environment, (yyvsp[0].integer) );
  }
#line 6507 "src-generated/ugbc.tab.c"
    break;

  case 380: /* screen_definition_expression: ROWS expr  */
#line 1429 "src/ugbc.y"
              {
      screen_rows_var( _environment, (yyvsp[0].string) );
  }
#line 6515 "src-generated/ugbc.tab.c"
    break;

  case 381: /* screen_definition_expression: VERTICAL SCROLL expr  */
#line 1432 "src/ugbc.y"
                         {
      screen_vertical_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 6523 "src-generated/ugbc.tab.c"
    break;

  case 382: /* screen_definition_expression: HORIZONTAL SCROLL expr  */
#line 1435 "src/ugbc.y"
                           {
      screen_horizontal_scroll_var( _environment, (yyvsp[0].string) );
  }
#line 6531 "src-generated/ugbc.tab.c"
    break;

  case 386: /* var_definition_simple: Identifier ON Identifier  */
#line 1444 "src/ugbc.y"
                             {
      variable_retrieve_or_define( _environment, (yyvsp[-2].string), VT_BYTE, 0 );
  }
#line 6539 "src-generated/ugbc.tab.c"
    break;

  case 387: /* var_definition_simple: Identifier OP_DOLLAR ON Identifier  */
#line 1447 "src/ugbc.y"
                                       {
      variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 );
  }
#line 6547 "src-generated/ugbc.tab.c"
    break;

  case 388: /* var_definition_simple: Identifier ON Identifier OP_ASSIGN direct_integer  */
#line 1450 "src/ugbc.y"
                                                      {
      variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_BYTE, (yyvsp[0].integer) );
  }
#line 6555 "src-generated/ugbc.tab.c"
    break;

  case 389: /* var_definition_simple: Identifier ON Identifier OP_ASSIGN expr  */
#line 1453 "src/ugbc.y"
                                            {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-4].string), v->type, v->value );
      variable_move_naked( _environment, v->name, d->name );
  }
#line 6565 "src-generated/ugbc.tab.c"
    break;

  case 390: /* var_definition_simple: Identifier OP_DOLLAR ON Identifier OP_ASSIGN expr  */
#line 1458 "src/ugbc.y"
                                                      {
      Variable * v = variable_retrieve( _environment, (yyvsp[0].string) );
      Variable * d = variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_STRING, 0 );
      variable_move( _environment, v->name, d->name );
  }
#line 6575 "src-generated/ugbc.tab.c"
    break;

  case 391: /* goto_definition: Identifier  */
#line 1465 "src/ugbc.y"
               {
      goto_label( _environment, (yyvsp[0].string) );
  }
#line 6583 "src-generated/ugbc.tab.c"
    break;

  case 392: /* goto_definition: Integer  */
#line 1468 "src/ugbc.y"
            {
      goto_number( _environment, (yyvsp[0].integer) );
  }
#line 6591 "src-generated/ugbc.tab.c"
    break;

  case 393: /* gosub_definition: Identifier  */
#line 1474 "src/ugbc.y"
               {
      gosub_label( _environment, (yyvsp[0].string) );
  }
#line 6599 "src-generated/ugbc.tab.c"
    break;

  case 394: /* gosub_definition: Integer  */
#line 1477 "src/ugbc.y"
            {
      gosub_number( _environment, (yyvsp[0].integer) );
  }
#line 6607 "src-generated/ugbc.tab.c"
    break;

  case 396: /* point_definition_simple: AT OP direct_integer OP_COMMA direct_integer CP  */
#line 1486 "src/ugbc.y"
                                                      {
        point_at( _environment, (yyvsp[-3].integer), (yyvsp[-1].integer) );
    }
#line 6615 "src-generated/ugbc.tab.c"
    break;

  case 397: /* point_definition_expression: AT OP expr OP_COMMA expr CP  */
#line 1492 "src/ugbc.y"
                                  {
        point_at_vars( _environment, (yyvsp[-3].string), (yyvsp[-1].string) );
    }
#line 6623 "src-generated/ugbc.tab.c"
    break;

  case 400: /* ink_definition: expr  */
#line 1501 "src/ugbc.y"
         {
        ink( _environment, (yyvsp[0].string) );
    }
#line 6631 "src-generated/ugbc.tab.c"
    break;

  case 401: /* on_goto_definition: Identifier  */
#line 1506 "src/ugbc.y"
                 {
          on_goto_index( _environment, (yyvsp[0].string) );
          on_goto_end( _environment );
      }
#line 6640 "src-generated/ugbc.tab.c"
    break;

  case 402: /* $@4: %empty  */
#line 1510 "src/ugbc.y"
                 {
        on_goto_index( _environment, (yyvsp[0].string) );
    }
#line 6648 "src-generated/ugbc.tab.c"
    break;

  case 404: /* on_gosub_definition: Identifier  */
#line 1515 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
          on_gosub_end( _environment );
      }
#line 6657 "src-generated/ugbc.tab.c"
    break;

  case 405: /* $@5: %empty  */
#line 1519 "src/ugbc.y"
                 {
          on_gosub_index( _environment, (yyvsp[0].string) );
    }
#line 6665 "src-generated/ugbc.tab.c"
    break;

  case 407: /* on_proc_definition: Identifier  */
#line 1524 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
          on_proc_end( _environment );
      }
#line 6674 "src-generated/ugbc.tab.c"
    break;

  case 408: /* $@6: %empty  */
#line 1528 "src/ugbc.y"
                 {
          on_proc_index( _environment, (yyvsp[0].string) );
    }
#line 6682 "src-generated/ugbc.tab.c"
    break;

  case 410: /* $@7: %empty  */
#line 1533 "src/ugbc.y"
                {
          on_goto( _environment, (yyvsp[-1].string) );
      }
#line 6690 "src-generated/ugbc.tab.c"
    break;

  case 412: /* $@8: %empty  */
#line 1536 "src/ugbc.y"
                {
          on_proc( _environment, (yyvsp[-1].string) );
      }
#line 6698 "src-generated/ugbc.tab.c"
    break;

  case 414: /* $@9: %empty  */
#line 1539 "src/ugbc.y"
                 {
        on_gosub( _environment, (yyvsp[-1].string) );  
    }
#line 6706 "src-generated/ugbc.tab.c"
    break;

  case 416: /* every_definition: expr TICKS GOSUB Identifier  */
#line 1544 "src/ugbc.y"
                                  {
          every_ticks_gosub( _environment, (yyvsp[-3].string), (yyvsp[0].string) );
    }
#line 6714 "src-generated/ugbc.tab.c"
    break;

  case 417: /* every_definition: ON  */
#line 1547 "src/ugbc.y"
         {
          every_on( _environment );
    }
#line 6722 "src-generated/ugbc.tab.c"
    break;

  case 418: /* every_definition: OFF  */
#line 1550 "src/ugbc.y"
          {
          every_off( _environment );
    }
#line 6730 "src-generated/ugbc.tab.c"
    break;

  case 419: /* add_definition: Identifier OP_COMMA expr  */
#line 1555 "src/ugbc.y"
                             {
        variable_move_naked( _environment, variable_add( _environment, (yyvsp[-2].string), (yyvsp[0].string) )->name, (yyvsp[-2].string) );
    }
#line 6738 "src-generated/ugbc.tab.c"
    break;

  case 420: /* add_definition: Identifier OP_COMMA expr OP_COMMA expr TO expr  */
#line 1558 "src/ugbc.y"
                                                     {
        add_complex( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 6746 "src-generated/ugbc.tab.c"
    break;

  case 421: /* dimensions: Integer  */
#line 1564 "src/ugbc.y"
              {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 6755 "src-generated/ugbc.tab.c"
    break;

  case 422: /* dimensions: Integer OP_COMMA dimensions  */
#line 1568 "src/ugbc.y"
                                  {
          ((struct _Environment *)_environment)->arrayDimensionsEach[((struct _Environment *)_environment)->arrayDimensions] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->arrayDimensions;
    }
#line 6764 "src-generated/ugbc.tab.c"
    break;

  case 423: /* datatype: BYTE  */
#line 1575 "src/ugbc.y"
         {
        (yyval.integer) = VT_BYTE;
    }
#line 6772 "src-generated/ugbc.tab.c"
    break;

  case 424: /* datatype: SIGNED BYTE  */
#line 1578 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SBYTE;
    }
#line 6780 "src-generated/ugbc.tab.c"
    break;

  case 425: /* datatype: WORD  */
#line 1581 "src/ugbc.y"
           {
        (yyval.integer) = VT_WORD;
    }
#line 6788 "src-generated/ugbc.tab.c"
    break;

  case 426: /* datatype: SIGNED WORD  */
#line 1584 "src/ugbc.y"
                  {
        (yyval.integer) = VT_SWORD;
    }
#line 6796 "src-generated/ugbc.tab.c"
    break;

  case 427: /* datatype: DWORD  */
#line 1587 "src/ugbc.y"
            {
        (yyval.integer) = VT_DWORD;
    }
#line 6804 "src-generated/ugbc.tab.c"
    break;

  case 428: /* datatype: SIGNED DWORD  */
#line 1590 "src/ugbc.y"
                   {
        (yyval.integer) = VT_SDWORD;
    }
#line 6812 "src-generated/ugbc.tab.c"
    break;

  case 429: /* datatype: ADDRESS  */
#line 1593 "src/ugbc.y"
              {
        (yyval.integer) = VT_ADDRESS;
    }
#line 6820 "src-generated/ugbc.tab.c"
    break;

  case 430: /* datatype: POSITION  */
#line 1596 "src/ugbc.y"
               {
        (yyval.integer) = VT_POSITION;
    }
#line 6828 "src-generated/ugbc.tab.c"
    break;

  case 431: /* datatype: COLOR  */
#line 1599 "src/ugbc.y"
            {
        (yyval.integer) = VT_COLOR;
    }
#line 6836 "src-generated/ugbc.tab.c"
    break;

  case 432: /* datatype: STRING  */
#line 1602 "src/ugbc.y"
             {
        (yyval.integer) = VT_STRING;
    }
#line 6844 "src-generated/ugbc.tab.c"
    break;

  case 433: /* $@10: %empty  */
#line 1607 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 6853 "src-generated/ugbc.tab.c"
    break;

  case 434: /* dim_definition: Identifier $@10 OP dimensions CP  */
#line 1610 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-4].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-4].string), VT_WORD );
        variable_reset( _environment );
    }
#line 6863 "src-generated/ugbc.tab.c"
    break;

  case 435: /* $@11: %empty  */
#line 1615 "src/ugbc.y"
                 {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 6872 "src-generated/ugbc.tab.c"
    break;

  case 436: /* dim_definition: Identifier $@11 OP_DOLLAR OP dimensions CP  */
#line 1618 "src/ugbc.y"
                                   {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), VT_STRING );
        variable_reset( _environment );
    }
#line 6882 "src-generated/ugbc.tab.c"
    break;

  case 437: /* $@12: %empty  */
#line 1623 "src/ugbc.y"
                          {
          memset( ((struct _Environment *)_environment)->arrayDimensionsEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
          ((struct _Environment *)_environment)->arrayDimensions = 0;
      }
#line 6891 "src-generated/ugbc.tab.c"
    break;

  case 438: /* dim_definition: Identifier datatype $@12 OP dimensions CP  */
#line 1626 "src/ugbc.y"
                         {
        variable_retrieve_or_define( _environment, (yyvsp[-5].string), VT_ARRAY, 0 );
        variable_array_type( _environment, (yyvsp[-5].string), (yyvsp[-4].integer) );
        variable_reset( _environment );
    }
#line 6901 "src-generated/ugbc.tab.c"
    break;

  case 441: /* indexes: expr  */
#line 1639 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 6910 "src-generated/ugbc.tab.c"
    break;

  case 442: /* indexes: expr OP_COMMA indexes  */
#line 1643 "src/ugbc.y"
                            {
          ((struct _Environment *)_environment)->arrayIndexesEach[((struct _Environment *)_environment)->arrayIndexes] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->arrayIndexes;
    }
#line 6919 "src-generated/ugbc.tab.c"
    break;

  case 443: /* parameters: Identifier  */
#line 1650 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6929 "src-generated/ugbc.tab.c"
    break;

  case 444: /* parameters: Identifier OP_DOLLAR  */
#line 1655 "src/ugbc.y"
                           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6939 "src-generated/ugbc.tab.c"
    break;

  case 445: /* parameters: Identifier AS datatype  */
#line 1660 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6949 "src-generated/ugbc.tab.c"
    break;

  case 446: /* parameters: Identifier OP_COMMA parameters  */
#line 1665 "src/ugbc.y"
                                     {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6959 "src-generated/ugbc.tab.c"
    break;

  case 447: /* parameters: Identifier OP_DOLLAR OP_COMMA parameters  */
#line 1670 "src/ugbc.y"
                                               {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6969 "src-generated/ugbc.tab.c"
    break;

  case 448: /* parameters: Identifier AS datatype OP_COMMA parameters  */
#line 1675 "src/ugbc.y"
                                                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6979 "src-generated/ugbc.tab.c"
    break;

  case 449: /* parameters_expr: Identifier  */
#line 1683 "src/ugbc.y"
                 {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6989 "src-generated/ugbc.tab.c"
    break;

  case 450: /* parameters_expr: Identifier OP_DOLLAR  */
#line 1688 "src/ugbc.y"
                           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-1].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 6999 "src-generated/ugbc.tab.c"
    break;

  case 451: /* parameters_expr: Identifier AS datatype  */
#line 1693 "src/ugbc.y"
                             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[0].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7009 "src-generated/ugbc.tab.c"
    break;

  case 452: /* parameters_expr: Identifier OP_COMMA parameters_expr  */
#line 1698 "src/ugbc.y"
                                          {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_WORD;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7019 "src-generated/ugbc.tab.c"
    break;

  case 453: /* parameters_expr: Identifier OP_DOLLAR OP_COMMA parameters_expr  */
#line 1703 "src/ugbc.y"
                                                    {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-3].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = VT_STRING;
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7029 "src-generated/ugbc.tab.c"
    break;

  case 454: /* parameters_expr: Identifier AS datatype OP_COMMA parameters_expr  */
#line 1708 "src/ugbc.y"
                                                      {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-4].string) );
          ((struct _Environment *)_environment)->parametersTypeEach[((struct _Environment *)_environment)->parameters] = (yyvsp[-2].integer);
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7039 "src-generated/ugbc.tab.c"
    break;

  case 455: /* parameters_expr: String  */
#line 1713 "src/ugbc.y"
             {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7048 "src-generated/ugbc.tab.c"
    break;

  case 456: /* parameters_expr: String OP_COMMA parameters_expr  */
#line 1717 "src/ugbc.y"
                                      {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7057 "src-generated/ugbc.tab.c"
    break;

  case 457: /* values: expr  */
#line 1724 "src/ugbc.y"
           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[0].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7066 "src-generated/ugbc.tab.c"
    break;

  case 458: /* values: expr OP_COMMA values  */
#line 1728 "src/ugbc.y"
                           {
          ((struct _Environment *)_environment)->parametersEach[((struct _Environment *)_environment)->parameters] = strdup( (yyvsp[-2].string) );
          ++((struct _Environment *)_environment)->parameters;
    }
#line 7075 "src-generated/ugbc.tab.c"
    break;

  case 459: /* print_definition: expr  */
#line 1735 "src/ugbc.y"
         {
        print( _environment, (yyvsp[0].string), 1 );
    }
#line 7083 "src-generated/ugbc.tab.c"
    break;

  case 460: /* print_definition: expr OP_COMMA  */
#line 1738 "src/ugbc.y"
                  {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 7092 "src-generated/ugbc.tab.c"
    break;

  case 461: /* print_definition: expr OP_SEMICOLON  */
#line 1742 "src/ugbc.y"
                      {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 7100 "src-generated/ugbc.tab.c"
    break;

  case 462: /* $@13: %empty  */
#line 1745 "src/ugbc.y"
                  {
        print( _environment, (yyvsp[-1].string), 0 );
        print_tab( _environment, 0 );
  }
#line 7109 "src-generated/ugbc.tab.c"
    break;

  case 464: /* $@14: %empty  */
#line 1749 "src/ugbc.y"
                       {
        print( _environment, (yyvsp[-1].string), 0 );
  }
#line 7117 "src-generated/ugbc.tab.c"
    break;

  case 466: /* writing_mode_definition: REPLACE  */
#line 1755 "src/ugbc.y"
              {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing REPLACE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_REPLACE );
    }
#line 7126 "src-generated/ugbc.tab.c"
    break;

  case 467: /* writing_mode_definition: OR  */
#line 1759 "src/ugbc.y"
         {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing OR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_OR );
    }
#line 7135 "src-generated/ugbc.tab.c"
    break;

  case 468: /* writing_mode_definition: XOR  */
#line 1763 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing XOR)" )->name;
          variable_store( _environment, (yyval.string), WRITING_XOR );
    }
#line 7144 "src-generated/ugbc.tab.c"
    break;

  case 469: /* writing_mode_definition: AND  */
#line 1767 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing AND)" )->name;
          variable_store( _environment, (yyval.string), WRITING_AND );
    }
#line 7153 "src-generated/ugbc.tab.c"
    break;

  case 470: /* writing_mode_definition: IGNORE  */
#line 1771 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing IGNORE)" )->name;
          variable_store( _environment, (yyval.string), WRITING_IGNORE );
    }
#line 7162 "src-generated/ugbc.tab.c"
    break;

  case 471: /* writing_part_definition: NORMAL  */
#line 1778 "src/ugbc.y"
             {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing NORMAL)" )->name;
          variable_store( _environment, (yyval.string), WRITING_NORMAL );
    }
#line 7171 "src-generated/ugbc.tab.c"
    break;

  case 472: /* writing_part_definition: PAPER  */
#line 1782 "src/ugbc.y"
            {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 7180 "src-generated/ugbc.tab.c"
    break;

  case 473: /* writing_part_definition: PAPER ONLY  */
#line 1786 "src/ugbc.y"
                 {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PAPER)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PAPER );
    }
#line 7189 "src-generated/ugbc.tab.c"
    break;

  case 474: /* writing_part_definition: PEN  */
#line 1790 "src/ugbc.y"
          {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 7198 "src-generated/ugbc.tab.c"
    break;

  case 475: /* writing_part_definition: PEN ONLY  */
#line 1794 "src/ugbc.y"
               {
          (yyval.string) = variable_temporary( _environment, VT_BYTE, "(writing PEN)" )->name;
          variable_store( _environment, (yyval.string), WRITING_PEN );
    }
#line 7207 "src-generated/ugbc.tab.c"
    break;

  case 476: /* writing_definition: writing_mode_definition OP_COMMA writing_part_definition  */
#line 1801 "src/ugbc.y"
                                                             {
        text_writing( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 7215 "src-generated/ugbc.tab.c"
    break;

  case 477: /* locate_definition: OP_COMMA expr  */
#line 1807 "src/ugbc.y"
                   {
        text_locate( _environment, NULL, (yyvsp[0].string) );
    }
#line 7223 "src-generated/ugbc.tab.c"
    break;

  case 478: /* locate_definition: expr OP_COMMA  */
#line 1810 "src/ugbc.y"
                    {
        text_locate( _environment, (yyvsp[-1].string), NULL );
    }
#line 7231 "src-generated/ugbc.tab.c"
    break;

  case 479: /* locate_definition: expr OP_COMMA expr  */
#line 1813 "src/ugbc.y"
                         {
        text_locate( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 7239 "src-generated/ugbc.tab.c"
    break;

  case 480: /* cmove_definition: OP_COMMA expr  */
#line 1819 "src/ugbc.y"
                   {
        text_cmove( _environment, NULL, (yyvsp[0].string) );
    }
#line 7247 "src-generated/ugbc.tab.c"
    break;

  case 481: /* cmove_definition: expr OP_COMMA  */
#line 1822 "src/ugbc.y"
                    {
        text_cmove( _environment, (yyvsp[-1].string), NULL );
    }
#line 7255 "src-generated/ugbc.tab.c"
    break;

  case 482: /* cmove_definition: expr OP_COMMA expr  */
#line 1825 "src/ugbc.y"
                         {
        text_cmove( _environment, (yyvsp[-2].string), (yyvsp[0].string) );
    }
#line 7263 "src-generated/ugbc.tab.c"
    break;

  case 483: /* hscroll_definition: LEFT  */
#line 1831 "src/ugbc.y"
         {
        text_hscroll_line( _environment, -1 );
    }
#line 7271 "src-generated/ugbc.tab.c"
    break;

  case 484: /* hscroll_definition: SCREEN LEFT  */
#line 1834 "src/ugbc.y"
                  {
        text_hscroll_screen( _environment, -1 );
    }
#line 7279 "src-generated/ugbc.tab.c"
    break;

  case 485: /* hscroll_definition: RIGHT  */
#line 1837 "src/ugbc.y"
            {
        text_hscroll_line( _environment, 1 );
    }
#line 7287 "src-generated/ugbc.tab.c"
    break;

  case 486: /* hscroll_definition: SCREEN RIGHT  */
#line 1840 "src/ugbc.y"
                   {
        text_hscroll_screen( _environment, 1 );
    }
#line 7295 "src-generated/ugbc.tab.c"
    break;

  case 487: /* vscroll_definition: SCREEN UP  */
#line 1846 "src/ugbc.y"
                {
        text_vscroll_screen( _environment, -1 );
    }
#line 7303 "src-generated/ugbc.tab.c"
    break;

  case 488: /* vscroll_definition: SCREEN DOWN  */
#line 1849 "src/ugbc.y"
                  {
        text_vscroll_screen( _environment, 1 );
    }
#line 7311 "src-generated/ugbc.tab.c"
    break;

  case 489: /* input_definition2: Identifier  */
#line 1855 "src/ugbc.y"
                 {
        input( _environment, (yyvsp[0].string) );
        print_newline( _environment );
      }
#line 7320 "src-generated/ugbc.tab.c"
    break;

  case 490: /* input_definition2: Identifier OP_SEMICOLON  */
#line 1859 "src/ugbc.y"
                              {
        input( _environment, (yyvsp[-1].string) );
      }
#line 7328 "src-generated/ugbc.tab.c"
    break;

  case 491: /* $@15: %empty  */
#line 1862 "src/ugbc.y"
                 {
        input( _environment, (yyvsp[0].string) );
      }
#line 7336 "src-generated/ugbc.tab.c"
    break;

  case 493: /* input_definition: String OP_SEMICOLON Identifier  */
#line 1868 "src/ugbc.y"
                                     {
        print( _environment, (yyvsp[-2].string), 0 );
        input( _environment, (yyvsp[0].string) );
        print_newline( _environment );
    }
#line 7346 "src-generated/ugbc.tab.c"
    break;

  case 494: /* input_definition: String OP_SEMICOLON Identifier OP_SEMICOLON  */
#line 1873 "src/ugbc.y"
                                                  {
        print( _environment, (yyvsp[-3].string), 0 );
        input( _environment, (yyvsp[-1].string) );
    }
#line 7355 "src-generated/ugbc.tab.c"
    break;

  case 495: /* $@16: %empty  */
#line 1877 "src/ugbc.y"
                                                  {
        print( _environment, (yyvsp[-3].string), 0 );
        input( _environment, (yyvsp[-1].string) );
    }
#line 7364 "src-generated/ugbc.tab.c"
    break;

  case 513: /* statement: TEXTADDRESS OP_ASSIGN expr  */
#line 1901 "src/ugbc.y"
                               {
      variable_move( _environment, (yyvsp[0].string), "ADDRESS" );
  }
#line 7372 "src-generated/ugbc.tab.c"
    break;

  case 519: /* statement: MEMORIZE  */
#line 1909 "src/ugbc.y"
             {
      text_memorize( _environment );
  }
#line 7380 "src-generated/ugbc.tab.c"
    break;

  case 520: /* statement: REMEMBER  */
#line 1912 "src/ugbc.y"
             {
      text_remember( _environment );
  }
#line 7388 "src-generated/ugbc.tab.c"
    break;

  case 524: /* statement: CUP  */
#line 1918 "src/ugbc.y"
        {
      text_cmove_direct( _environment, 0, -1 );
  }
#line 7396 "src-generated/ugbc.tab.c"
    break;

  case 525: /* statement: CDOWN  */
#line 1921 "src/ugbc.y"
          {
      text_cmove_direct( _environment, 0, 1 );
  }
#line 7404 "src-generated/ugbc.tab.c"
    break;

  case 526: /* statement: CLEFT  */
#line 1924 "src/ugbc.y"
          {
      text_cmove_direct( _environment, -1, 0 );
  }
#line 7412 "src-generated/ugbc.tab.c"
    break;

  case 527: /* statement: CRIGHT  */
#line 1927 "src/ugbc.y"
           {
      text_cmove_direct( _environment, 1, 0 );
  }
#line 7420 "src-generated/ugbc.tab.c"
    break;

  case 528: /* statement: CLINE  */
#line 1930 "src/ugbc.y"
          {
      text_cline( _environment, NULL );
  }
#line 7428 "src-generated/ugbc.tab.c"
    break;

  case 529: /* statement: CLINE expr  */
#line 1933 "src/ugbc.y"
               {
      text_cline( _environment, (yyvsp[0].string) );
  }
#line 7436 "src-generated/ugbc.tab.c"
    break;

  case 530: /* statement: SET TAB expr  */
#line 1936 "src/ugbc.y"
                 {
      text_set_tab( _environment, (yyvsp[0].string) );
  }
#line 7444 "src-generated/ugbc.tab.c"
    break;

  case 531: /* statement: CENTER expr  */
#line 1939 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 7452 "src-generated/ugbc.tab.c"
    break;

  case 532: /* statement: CENTRE expr  */
#line 1942 "src/ugbc.y"
                {
      text_center( _environment, (yyvsp[0].string) );
  }
#line 7460 "src-generated/ugbc.tab.c"
    break;

  case 533: /* statement: CLS  */
#line 1945 "src/ugbc.y"
        {
      text_cls( _environment );
  }
#line 7468 "src-generated/ugbc.tab.c"
    break;

  case 534: /* statement: HOME  */
#line 1948 "src/ugbc.y"
         {
      text_home( _environment );
  }
#line 7476 "src-generated/ugbc.tab.c"
    break;

  case 535: /* statement: CLEAR KEY  */
#line 1951 "src/ugbc.y"
              {
      clear_key( _environment );
  }
#line 7484 "src-generated/ugbc.tab.c"
    break;

  case 536: /* statement: OP_INC Identifier  */
#line 1954 "src/ugbc.y"
                      {
      variable_increment( _environment, (yyvsp[0].string) );
  }
#line 7492 "src-generated/ugbc.tab.c"
    break;

  case 537: /* statement: OP_DEC Identifier  */
#line 1957 "src/ugbc.y"
                      {
      variable_decrement( _environment, (yyvsp[0].string) );
  }
#line 7500 "src-generated/ugbc.tab.c"
    break;

  case 538: /* statement: RANDOMIZE  */
#line 1960 "src/ugbc.y"
              {
      randomize( _environment, NULL );
  }
#line 7508 "src-generated/ugbc.tab.c"
    break;

  case 539: /* statement: RANDOMIZE expr  */
#line 1963 "src/ugbc.y"
                   {
      randomize( _environment, (yyvsp[0].string) );
  }
#line 7516 "src-generated/ugbc.tab.c"
    break;

  case 540: /* statement: IF expr THEN  */
#line 1966 "src/ugbc.y"
                 {
      if_then( _environment, (yyvsp[-1].string) );  
  }
#line 7524 "src-generated/ugbc.tab.c"
    break;

  case 541: /* statement: ELSE  */
#line 1969 "src/ugbc.y"
         {
      else_if_then( _environment, NULL );  
  }
#line 7532 "src-generated/ugbc.tab.c"
    break;

  case 542: /* statement: ELSE IF expr THEN  */
#line 1972 "src/ugbc.y"
                      {
      else_if_then( _environment, (yyvsp[-1].string) );  
  }
#line 7540 "src-generated/ugbc.tab.c"
    break;

  case 543: /* statement: ENDIF  */
#line 1975 "src/ugbc.y"
          {
      end_if_then( _environment );  
  }
#line 7548 "src-generated/ugbc.tab.c"
    break;

  case 544: /* statement: DO  */
#line 1978 "src/ugbc.y"
       {
      begin_loop( _environment );  
  }
#line 7556 "src-generated/ugbc.tab.c"
    break;

  case 545: /* statement: LOOP  */
#line 1981 "src/ugbc.y"
         {
      end_loop( _environment );  
  }
#line 7564 "src-generated/ugbc.tab.c"
    break;

  case 546: /* $@17: %empty  */
#line 1984 "src/ugbc.y"
          { 
      begin_while( _environment );  
  }
#line 7572 "src-generated/ugbc.tab.c"
    break;

  case 547: /* statement: WHILE $@17 expr  */
#line 1986 "src/ugbc.y"
         {
      begin_while_condition( _environment, (yyvsp[0].string) );  
  }
#line 7580 "src-generated/ugbc.tab.c"
    break;

  case 548: /* statement: WEND  */
#line 1989 "src/ugbc.y"
         {
      end_while( _environment );  
  }
#line 7588 "src-generated/ugbc.tab.c"
    break;

  case 549: /* statement: REPEAT  */
#line 1992 "src/ugbc.y"
           {
      begin_repeat( _environment );  
  }
#line 7596 "src-generated/ugbc.tab.c"
    break;

  case 550: /* statement: UNTIL expr  */
#line 1995 "src/ugbc.y"
               {
      end_repeat( _environment, (yyvsp[0].string) );  
  }
#line 7604 "src-generated/ugbc.tab.c"
    break;

  case 551: /* statement: EXIT  */
#line 1998 "src/ugbc.y"
         {
      exit_loop( _environment, 0 );  
  }
#line 7612 "src-generated/ugbc.tab.c"
    break;

  case 552: /* statement: EXIT PROC  */
#line 2001 "src/ugbc.y"
              {
      exit_procedure( _environment );
  }
#line 7620 "src-generated/ugbc.tab.c"
    break;

  case 553: /* statement: POP PROC  */
#line 2004 "src/ugbc.y"
             {
      exit_procedure( _environment );
  }
#line 7628 "src-generated/ugbc.tab.c"
    break;

  case 554: /* statement: EXIT IF expr  */
#line 2007 "src/ugbc.y"
                 {
      exit_loop_if( _environment, (yyvsp[0].string), 0 );  
  }
#line 7636 "src-generated/ugbc.tab.c"
    break;

  case 555: /* statement: EXIT Integer  */
#line 2010 "src/ugbc.y"
                 {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 7644 "src-generated/ugbc.tab.c"
    break;

  case 556: /* statement: EXIT direct_integer  */
#line 2013 "src/ugbc.y"
                        {
      exit_loop( _environment, (yyvsp[0].integer) );  
  }
#line 7652 "src-generated/ugbc.tab.c"
    break;

  case 557: /* statement: EXIT IF expr OP_COMMA Integer  */
#line 2016 "src/ugbc.y"
                                  {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 7660 "src-generated/ugbc.tab.c"
    break;

  case 558: /* statement: EXIT IF expr OP_COMMA direct_integer  */
#line 2019 "src/ugbc.y"
                                         {
      exit_loop_if( _environment, (yyvsp[-2].string), (yyvsp[0].integer) );  
  }
#line 7668 "src-generated/ugbc.tab.c"
    break;

  case 559: /* statement: FOR Identifier OP_ASSIGN expr TO expr  */
#line 2022 "src/ugbc.y"
                                          {
      begin_for( _environment, (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 7676 "src-generated/ugbc.tab.c"
    break;

  case 560: /* statement: NEXT  */
#line 2025 "src/ugbc.y"
         {
      end_for( _environment );
  }
#line 7684 "src-generated/ugbc.tab.c"
    break;

  case 561: /* statement: PROCEDURE Identifier  */
#line 2028 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
      begin_procedure( _environment, (yyvsp[0].string) );
  }
#line 7693 "src-generated/ugbc.tab.c"
    break;

  case 562: /* $@18: %empty  */
#line 2032 "src/ugbc.y"
                         {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 7701 "src-generated/ugbc.tab.c"
    break;

  case 563: /* statement: PROCEDURE Identifier $@18 OSP parameters CSP  */
#line 2034 "src/ugbc.y"
                         {
      begin_procedure( _environment, (yyvsp[-4].string) );
  }
#line 7709 "src-generated/ugbc.tab.c"
    break;

  case 564: /* statement: SHARED parameters_expr  */
#line 2037 "src/ugbc.y"
                           {
      shared( _environment );
  }
#line 7717 "src-generated/ugbc.tab.c"
    break;

  case 565: /* statement: GLOBAL parameters_expr  */
#line 2040 "src/ugbc.y"
                           {
      global( _environment );
  }
#line 7725 "src-generated/ugbc.tab.c"
    break;

  case 566: /* statement: END PROC  */
#line 2043 "src/ugbc.y"
             {
      end_procedure( _environment, NULL );
  }
#line 7733 "src-generated/ugbc.tab.c"
    break;

  case 567: /* statement: END PROC OSP expr CSP  */
#line 2046 "src/ugbc.y"
                          {
      end_procedure( _environment, (yyvsp[-1].string) );
  }
#line 7741 "src-generated/ugbc.tab.c"
    break;

  case 568: /* statement: FOR Identifier OP_ASSIGN expr TO expr STEP expr  */
#line 2049 "src/ugbc.y"
                                                    {
      begin_for_step( _environment, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string), (yyvsp[0].string) );  
  }
#line 7749 "src-generated/ugbc.tab.c"
    break;

  case 569: /* statement: Identifier " "  */
#line 2052 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[-1].string) );
  }
#line 7758 "src-generated/ugbc.tab.c"
    break;

  case 570: /* statement: PROC Identifier  */
#line 2056 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 7767 "src-generated/ugbc.tab.c"
    break;

  case 571: /* statement: CALL Identifier  */
#line 2060 "src/ugbc.y"
                    {
      ((struct _Environment *)_environment)->parameters = 0;
      call_procedure( _environment, (yyvsp[0].string) );
  }
#line 7776 "src-generated/ugbc.tab.c"
    break;

  case 572: /* $@19: %empty  */
#line 2064 "src/ugbc.y"
                   {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 7784 "src-generated/ugbc.tab.c"
    break;

  case 573: /* statement: Identifier OSP $@19 values CSP  */
#line 2066 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 7792 "src-generated/ugbc.tab.c"
    break;

  case 574: /* $@20: %empty  */
#line 2069 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 7800 "src-generated/ugbc.tab.c"
    break;

  case 575: /* statement: PROC Identifier OSP $@20 values CSP  */
#line 2071 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 7808 "src-generated/ugbc.tab.c"
    break;

  case 576: /* $@21: %empty  */
#line 2074 "src/ugbc.y"
                        {
      ((struct _Environment *)_environment)->parameters = 0;
    }
#line 7816 "src-generated/ugbc.tab.c"
    break;

  case 577: /* statement: CALL Identifier OSP $@21 values CSP  */
#line 2076 "src/ugbc.y"
                 {
      call_procedure( _environment, (yyvsp[-4].string) );
  }
#line 7824 "src-generated/ugbc.tab.c"
    break;

  case 578: /* statement: PEN expr  */
#line 2079 "src/ugbc.y"
             {
      text_pen( _environment, (yyvsp[0].string) );
  }
#line 7832 "src-generated/ugbc.tab.c"
    break;

  case 579: /* statement: PAPER expr  */
#line 2082 "src/ugbc.y"
               {
      text_paper( _environment, (yyvsp[0].string) );
  }
#line 7840 "src-generated/ugbc.tab.c"
    break;

  case 580: /* statement: INVERSE ON  */
#line 2085 "src/ugbc.y"
               {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 7848 "src-generated/ugbc.tab.c"
    break;

  case 581: /* statement: INVERSE OFF  */
#line 2088 "src/ugbc.y"
                {
      CRITICAL_NOT_SUPPORTED("INVERSE");
  }
#line 7856 "src-generated/ugbc.tab.c"
    break;

  case 583: /* statement: Identifier OP_COLON  */
#line 2092 "src/ugbc.y"
                        {
      outhead1("%s:", (yyvsp[-1].string));
  }
#line 7864 "src-generated/ugbc.tab.c"
    break;

  case 584: /* statement: BEG GAMELOOP  */
#line 2095 "src/ugbc.y"
                 {
      begin_gameloop( _environment );
  }
#line 7872 "src-generated/ugbc.tab.c"
    break;

  case 585: /* statement: END GAMELOOP  */
#line 2098 "src/ugbc.y"
                 {
      end_gameloop( _environment );
  }
#line 7880 "src-generated/ugbc.tab.c"
    break;

  case 586: /* statement: GRAPHIC  */
#line 2101 "src/ugbc.y"
            {
      graphic( _environment );
  }
#line 7888 "src-generated/ugbc.tab.c"
    break;

  case 587: /* statement: HALT  */
#line 2104 "src/ugbc.y"
         {
      halt( _environment );
  }
#line 7896 "src-generated/ugbc.tab.c"
    break;

  case 588: /* statement: END  */
#line 2107 "src/ugbc.y"
        {
      end( _environment );
  }
#line 7904 "src-generated/ugbc.tab.c"
    break;

  case 593: /* statement: RETURN  */
#line 2114 "src/ugbc.y"
           {
      return_label( _environment );
  }
#line 7912 "src-generated/ugbc.tab.c"
    break;

  case 594: /* statement: RETURN expr  */
#line 2117 "src/ugbc.y"
                {
      return_procedure( _environment, (yyvsp[0].string) );
  }
#line 7920 "src-generated/ugbc.tab.c"
    break;

  case 595: /* statement: POP  */
#line 2120 "src/ugbc.y"
        {
      pop( _environment );
  }
#line 7928 "src-generated/ugbc.tab.c"
    break;

  case 596: /* statement: DONE  */
#line 2123 "src/ugbc.y"
          {
      return 0;
  }
#line 7936 "src-generated/ugbc.tab.c"
    break;

  case 597: /* statement: LEFT OP expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 2126 "src/ugbc.y"
                                                 {
        variable_string_left_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 7944 "src-generated/ugbc.tab.c"
    break;

  case 598: /* statement: RIGHT OP expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 2129 "src/ugbc.y"
                                                  {
        variable_string_right_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 7952 "src-generated/ugbc.tab.c"
    break;

  case 599: /* statement: MID OP expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 2132 "src/ugbc.y"
                                                {
        variable_string_mid_assign( _environment, (yyvsp[-5].string), (yyvsp[-3].string), NULL, (yyvsp[0].string) );
  }
#line 7960 "src-generated/ugbc.tab.c"
    break;

  case 600: /* statement: MID OP expr OP_COMMA expr OP_COMMA expr CP OP_ASSIGN expr  */
#line 2135 "src/ugbc.y"
                                                              {
        variable_string_mid_assign( _environment, (yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[0].string) );
  }
#line 7968 "src-generated/ugbc.tab.c"
    break;

  case 602: /* statement: Identifier OP_ASSIGN expr  */
#line 2139 "src/ugbc.y"
                              {
        outline2("; %s = %s", (yyvsp[-2].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-2].string), expr->type, 0 )->name;
        outline1("; defined %s ", (yyvsp[-2].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-2].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-2].string) );
  }
#line 7982 "src-generated/ugbc.tab.c"
    break;

  case 603: /* statement: Identifier OP_DOLLAR OP_ASSIGN expr  */
#line 2148 "src/ugbc.y"
                                        {
        outline2("; %s = %s", (yyvsp[-3].string), (yyvsp[0].string) );
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        outline1("; retrieved %s ", (yyvsp[0].string) );
        variable_retrieve_or_define( _environment, (yyvsp[-3].string), VT_STRING, 0 )->name;
        outline1("; defined %s ", (yyvsp[-3].string) );
        variable_move( _environment, (yyvsp[0].string), (yyvsp[-3].string) );
        outline2("; moved %s -> %s ", (yyvsp[0].string), (yyvsp[-3].string) );
  }
#line 7996 "src-generated/ugbc.tab.c"
    break;

  case 604: /* $@22: %empty  */
#line 2157 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 8005 "src-generated/ugbc.tab.c"
    break;

  case 605: /* statement: Identifier $@22 OP indexes CP OP_ASSIGN expr  */
#line 2161 "src/ugbc.y"
                                   {
        Variable * expr = variable_retrieve( _environment, (yyvsp[0].string) );
        Variable * array = variable_retrieve( _environment, (yyvsp[-6].string) );
        if ( array->type != VT_ARRAY ) {
            CRITICAL_NOT_ARRAY( (yyvsp[-6].string) );
        }
        variable_move_array( _environment, (yyvsp[-6].string), expr->name );
  }
#line 8018 "src-generated/ugbc.tab.c"
    break;

  case 606: /* $@23: %empty  */
#line 2169 "src/ugbc.y"
                         {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 8027 "src-generated/ugbc.tab.c"
    break;

  case 607: /* statement: Identifier OP_DOLLAR $@23 OP indexes CP OP_ASSIGN expr  */
#line 2172 "src/ugbc.y"
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
#line 8046 "src-generated/ugbc.tab.c"
    break;

  case 608: /* $@24: %empty  */
#line 2186 "src/ugbc.y"
               {
        memset( ((struct _Environment *)_environment)->arrayIndexesEach, 0, sizeof( int ) * MAX_ARRAY_DIMENSIONS );
        ((struct _Environment *)_environment)->arrayIndexes = 0;
    }
#line 8055 "src-generated/ugbc.tab.c"
    break;

  case 609: /* statement: Identifier $@24 datatype OP indexes CP OP_ASSIGN expr  */
#line 2189 "src/ugbc.y"
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
#line 8074 "src-generated/ugbc.tab.c"
    break;

  case 610: /* statement: DEBUG expr  */
#line 2203 "src/ugbc.y"
               {
      debug_var( _environment, (yyvsp[0].string) );
  }
#line 8082 "src-generated/ugbc.tab.c"
    break;

  case 613: /* statements_no_linenumbers: statement  */
#line 2211 "src/ugbc.y"
                { ((Environment *)_environment)->yylineno = yylineno; }
#line 8088 "src-generated/ugbc.tab.c"
    break;

  case 614: /* $@25: %empty  */
#line 2212 "src/ugbc.y"
                         { ((Environment *)_environment)->yylineno = yylineno; }
#line 8094 "src-generated/ugbc.tab.c"
    break;

  case 616: /* $@26: %empty  */
#line 2216 "src/ugbc.y"
              {
        outhead1("_linenumber%d:", (yyvsp[0].integer));
    }
#line 8102 "src-generated/ugbc.tab.c"
    break;

  case 617: /* statements_with_linenumbers: Integer $@26 statements_no_linenumbers  */
#line 2218 "src/ugbc.y"
                                { 
        ((Environment *)_environment)->yylineno = yylineno;
    }
#line 8110 "src-generated/ugbc.tab.c"
    break;

  case 618: /* $@27: %empty  */
#line 2223 "src/ugbc.y"
                       {
        call_procedure( _environment, (yyvsp[-1].string) );
    }
#line 8118 "src-generated/ugbc.tab.c"
    break;

  case 624: /* $@28: %empty  */
#line 2233 "src/ugbc.y"
  { ((Environment *)_environment)->yylineno = yylineno; }
#line 8124 "src-generated/ugbc.tab.c"
    break;


#line 8128 "src-generated/ugbc.tab.c"

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

#line 2235 "src/ugbc.y"


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

